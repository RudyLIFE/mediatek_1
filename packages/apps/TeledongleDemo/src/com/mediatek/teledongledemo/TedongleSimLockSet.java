package com.mediatek.teledongledemo;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.res.Resources;
import android.os.Bundle;
import android.os.Handler;
import android.os.AsyncResult;
import android.os.Message;
import android.preference.CheckBoxPreference;
import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.preference.PreferenceScreen;
import android.widget.Toast;

import com.mediatek.basic.TedongleEditPinPreference;
import android.util.Log;
import android.tedongle.TedongleManager;

public class TedongleSimLockSet extends PreferenceActivity
    implements TedongleEditPinPreference.OnPinEnteredListener {

	private static final int OFF_MODE = 0;
	// State when enabling/disabling ICC lock
	private static final int ICC_LOCK_MODE = 1;
	// State when entering the old pin
	private static final int ICC_OLD_MODE = 2;
	// State when entering the new pin - first time
	private static final int ICC_NEW_MODE = 3;
	// State when entering the new pin - second time
	private static final int ICC_REENTER_MODE = 4;
	
	// Keys in xml file
	private static final String PIN_DIALOG = "sim_pin";
	private static final String PIN_TOGGLE = "sim_toggle";
	// Keys in icicle
	private static final String DIALOG_STATE = "dialogState";
	private static final String DIALOG_PIN = "dialogPin";
	private static final String DIALOG_ERROR = "dialogError";
	private static final String ENABLE_TO_STATE = "enableState";
	
	// Save and restore inputted PIN code when configuration changed
	// (ex. portrait<-->landscape) during change PIN code
	private static final String OLD_PINCODE = "oldPinCode";
	private static final String NEW_PINCODE = "newPinCode";
	
	private static final int MIN_PIN_LENGTH = 4;
	private static final int MAX_PIN_LENGTH = 8;
	// Which dialog to show next when popped up
	private int mDialogState = OFF_MODE;
	
	private String mPin;
	private String mOldPin;
	private String mNewPin;
	private String mError;
	// Are we trying to enable or disable ICC lock?
	private boolean mToState;
	
    private TedongleManager mTedongleManager;
	
	private TedongleEditPinPreference mPinDialog;
	private CheckBoxPreference mPinToggle;
	
	private Resources mRes;
	
	private String LOG_TAG = "3GD-APK-SimLockSet";
			
	// For async handler to identify request type
	private static final int MSG_ENABLE_ICC_PIN_COMPLETE = 100;
	private static final int MSG_CHANGE_ICC_PIN_COMPLETE = 101;
	private static final int MSG_SIM_STATE_CHANGED = 102;
	
    /**
     * Broadcast Action: The sim card state has changed.
     * The intent will have the following extra values:</p>
     * <ul>
     *   <li><em>phoneName</em> - A string version of the phone name.</li>
     *   <li><em>ss</em> - The sim state.  One of
     *   <code>"ABSENT"</code> <code>"LOCKED"</code>
     *   <code>"READY"</code> <code>"ISMI"</code> <code>"LOADED"</code> </li>
     *   <li><em>reason</em> - The reason while ss is LOCKED, otherwise is null
     *   <code>"PIN"</code> locked on PIN1
     *   <code>"PUK"</code> locked on PUK1
     *   <code>"NETWORK"</code> locked on Network Personalization </li>
     * </ul>
     *
     * <p class="note">
     * Requires the READ_PHONE_STATE permission.
     * 
     * <p class="note">This is a protected intent that can only be sent
     * by the system.
     */
    public static final String ACTION_SIM_STATE_CHANGED
            = "tedongle.intent.action.SIM_STATE_CHANGED";
	// For replies from IccCard interface
	private Handler mHandler = new Handler() {
	    public void handleMessage(Message msg) {
	        AsyncResult ar = (AsyncResult) msg.obj;
	        switch (msg.what) {
	            case MSG_ENABLE_ICC_PIN_COMPLETE:
	                //iccLockChanged(ar.exception == null);
	            	if (msg.arg1 == 1) {
	            		iccLockChanged(true);
	            	} else {
	            		iccLockChanged(false);
	            	}
	                break;
	            case MSG_CHANGE_ICC_PIN_COMPLETE:
	                //iccPinChanged(ar.exception == null);
	            	if (msg.arg1 == 1) {
	            		iccLockChanged(true);
	            	} else {
	            		iccLockChanged(false);
	            	}
	                break;
	            case MSG_SIM_STATE_CHANGED:
	                updatePreferences();
	                break;
	        }
			
	        return;
	    }
	};
	
	private final BroadcastReceiver mSimStateReceiver = new BroadcastReceiver() {
	    public void onReceive(Context context, Intent intent) {
	        final String action = intent.getAction();
	        if (ACTION_SIM_STATE_CHANGED.equals(action)) {
	            mHandler.sendMessage(mHandler.obtainMessage(MSG_SIM_STATE_CHANGED));
	        }
	    }
	};
	
	// For top-level settings screen to query
	boolean isIccLockEnabled() {
	    return mTedongleManager.getIccLockEnabled();
	}
	
	String getSummary(Context context) {
	    Resources res = context.getResources();
	    String summary = isIccLockEnabled()
	            ? res.getString(R.string.sim_lock_on)
	            : res.getString(R.string.sim_lock_off);
	    return summary;
	}
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
	    super.onCreate(savedInstanceState);
	
	    addPreferencesFromResource(R.xml.sim_lock_settings);
	
	    mPinDialog = (TedongleEditPinPreference) findPreference(PIN_DIALOG);
	    mPinToggle = (CheckBoxPreference) findPreference(PIN_TOGGLE);
	    if (savedInstanceState != null && savedInstanceState.containsKey(DIALOG_STATE)) {
	        mDialogState = savedInstanceState.getInt(DIALOG_STATE);
	        mPin = savedInstanceState.getString(DIALOG_PIN);
	        mError = savedInstanceState.getString(DIALOG_ERROR);
	        mToState = savedInstanceState.getBoolean(ENABLE_TO_STATE);
	
	        // Restore inputted PIN code
	        switch (mDialogState) {
	            case ICC_NEW_MODE:
	                mOldPin = savedInstanceState.getString(OLD_PINCODE);
	                break;
	
	            case ICC_REENTER_MODE:
	                mOldPin = savedInstanceState.getString(OLD_PINCODE);
	                mNewPin = savedInstanceState.getString(NEW_PINCODE);
	                break;
	
	            case ICC_LOCK_MODE:
	            case ICC_OLD_MODE:
	            default:
	                break;
	        }
	    }
	
	    mPinDialog.setOnPinEnteredListener(this);
	
	    // Don't need any changes to be remembered
	    getPreferenceScreen().setPersistent(false);
	    
		mTedongleManager = TedongleManager.getDefault();
		
	    mRes = getResources();
	    updatePreferences();
	    Log.d(LOG_TAG, "oncreate end...");
	}
	
	private void updatePreferences() {
	    Log.d(LOG_TAG, "updatePreferences boolean :" + mTedongleManager.getIccLockEnabled());		
	    mPinToggle.setChecked(mTedongleManager.getIccLockEnabled());
	}
	
	@Override
	protected void onResume() {
	    super.onResume();
	
	    // ACTION_SIM_STATE_CHANGED is sticky, so we'll receive current state after this call,
	    // which will call updatePreferences().
	    final IntentFilter filter = new IntentFilter(ACTION_SIM_STATE_CHANGED);
	    registerReceiver(mSimStateReceiver, filter);
	    Log.d(LOG_TAG, "onResume mDialogState:" + mDialogState);
	    
	    if (mDialogState != OFF_MODE) {
	        showPinDialog();
	    } else {
	        // Prep for standard click on "Change PIN"
	        resetDialogState();
	    }
	}
	
	@Override
	protected void onPause() {
	    super.onPause();
	    unregisterReceiver(mSimStateReceiver);
	}
	
	@Override
	protected void onSaveInstanceState(Bundle out) {
	    // Need to store this state for slider open/close
	    // There is one case where the dialog is popped up by the preference
	    // framework. In that case, let the preference framework store the
	    // dialog state. In other cases, where this activity manually launches
	    // the dialog, store the state of the dialog.
	    if (mPinDialog.isDialogOpen()) {
	        out.putInt(DIALOG_STATE, mDialogState);
	        out.putString(DIALOG_PIN, mPinDialog.getEditText().getText().toString());
	        out.putString(DIALOG_ERROR, mError);
	        out.putBoolean(ENABLE_TO_STATE, mToState);
	
	        // Save inputted PIN code
	        switch (mDialogState) {
	            case ICC_NEW_MODE:
	                out.putString(OLD_PINCODE, mOldPin);
	                break;
	
	            case ICC_REENTER_MODE:
	                out.putString(OLD_PINCODE, mOldPin);
	                out.putString(NEW_PINCODE, mNewPin);
	                break;
	
	            case ICC_LOCK_MODE:
	            case ICC_OLD_MODE:
	            default:
	                break;
	        }
	    } else {
	        super.onSaveInstanceState(out);
	    }
	}
	
	private void showPinDialog() {
	    if (mDialogState == OFF_MODE) {
	        return;
	    }
	    setDialogValues();
	
	    mPinDialog.showPinDialog();
	}
	
	private void setDialogValues() {
	    mPinDialog.setText(mPin);
	    String message = "";
	    switch (mDialogState) {
	        case ICC_LOCK_MODE:
	            message = mRes.getString(R.string.sim_enter_pin);
	            mPinDialog.setDialogTitle(mToState
	                    ? mRes.getString(R.string.sim_enable_sim_lock)
	                    : mRes.getString(R.string.sim_disable_sim_lock));
	            break;
	        case ICC_OLD_MODE:
	            message = mRes.getString(R.string.sim_enter_old);
	            mPinDialog.setDialogTitle(mRes.getString(R.string.sim_change_pin));
	            break;
	        case ICC_NEW_MODE:
	            message = mRes.getString(R.string.sim_enter_new);
	            mPinDialog.setDialogTitle(mRes.getString(R.string.sim_change_pin));
	            break;
	        case ICC_REENTER_MODE:
	            message = mRes.getString(R.string.sim_reenter_new);
	            mPinDialog.setDialogTitle(mRes.getString(R.string.sim_change_pin));
	            break;
	    }
	    if (mError != null) {
	        message = mError + "\n" + message;
	        mError = null;
	    }
	    mPinDialog.setDialogMessage(message);
	}
	
	public void onPinEntered(TedongleEditPinPreference preference, boolean positiveResult) {
	    if (!positiveResult) {
	        resetDialogState();
	        return;
	    }
	
	    mPin = preference.getText();
	    if (!reasonablePin(mPin)) {
	        // inject error message and display dialog again
	        mError = mRes.getString(R.string.sim_bad_pin);
	        showPinDialog();
	        return;
	    }
	    switch (mDialogState) {
	        case ICC_LOCK_MODE:
	            tryChangeIccLockState();
	            break;
	        case ICC_OLD_MODE:
	            mOldPin = mPin;
	            mDialogState = ICC_NEW_MODE;
	            mError = null;
	            mPin = null;
	            showPinDialog();
	            break;
	        case ICC_NEW_MODE:
	            mNewPin = mPin;
	            mDialogState = ICC_REENTER_MODE;
	            mPin = null;
	            showPinDialog();
	            break;
	        case ICC_REENTER_MODE:
	            if (!mPin.equals(mNewPin)) {
	                mError = mRes.getString(R.string.sim_pins_dont_match);
	                mDialogState = ICC_NEW_MODE;
	                mPin = null;
	                showPinDialog();
	            } else {
	                mError = null;
	                tryChangePin();
	            }
	            break;
	    }
	}
	
	public boolean onPreferenceTreeClick(PreferenceScreen preferenceScreen, Preference preference) {
	    if (preference == mPinToggle) {
	        // Get the new, preferred state
	        mToState = mPinToggle.isChecked();
	        // Flip it back and pop up pin dialog
	        mPinToggle.setChecked(!mToState);
	        mDialogState = ICC_LOCK_MODE;
	        showPinDialog();
	    } else if (preference == mPinDialog) {
	        mDialogState = ICC_OLD_MODE;
	        return false;
	    }
	    return true;
	}
	
	private void tryChangeIccLockState() {
	    // Try to change icc lock. If it succeeds, toggle the lock state and
	    // reset dialog state. Else inject error message and show dialog again.
	    Message callback = Message.obtain(mHandler, MSG_ENABLE_ICC_PIN_COMPLETE);
	    Log.d(LOG_TAG, "tryChangeIccLockState" + " mToState:" + mToState + " mPin:" 
	    				+ mPin + " message:" + callback);
	    mTedongleManager.setIccLockEnabled(mToState, mPin, callback);
	    // Disable the setting till the response is received.
	    mPinToggle.setEnabled(false);
	}
	
	private void iccLockChanged(boolean success) {
		Log.d(LOG_TAG, "iccLockChanged success:" + success);
	    if (success) {
	        mPinToggle.setChecked(mToState);
	    } else {
	        Toast.makeText(this, mRes.getString(R.string.sim_lock_failed), Toast.LENGTH_SHORT)
	                .show();
	    }
	    mPinToggle.setEnabled(true);
	    resetDialogState();
	}
	
	private void iccPinChanged(boolean success) {
		Log.d(LOG_TAG, "iccPinChanged success:" + success);
	    if (!success) {
	        Toast.makeText(this, mRes.getString(R.string.sim_change_failed),
	                Toast.LENGTH_SHORT)
	                .show();
	    } else {
	        Toast.makeText(this, mRes.getString(R.string.sim_change_succeeded),
	                Toast.LENGTH_SHORT)
	                .show();
	
	    }
	    resetDialogState();
	}
	
	private void tryChangePin() {
		Log.d(LOG_TAG, "tryChangePin"+" mOldPin:"+mOldPin+" mNewPin:"+mNewPin);
	    Message callback = Message.obtain(mHandler, MSG_CHANGE_ICC_PIN_COMPLETE);
	    mTedongleManager.changeIccLockPassword(mOldPin,
	            mNewPin, callback);
	}
	
	private boolean reasonablePin(String pin) {
	    if (pin == null || pin.length() < MIN_PIN_LENGTH || pin.length() > MAX_PIN_LENGTH) {
	        return false;
	    } else {
	        return true;
	    }
	}
	
	private void resetDialogState() {
	    mError = null;
	    mDialogState = ICC_OLD_MODE; // Default for when Change PIN is clicked
	    mPin = "";
	    setDialogValues();
	    mDialogState = OFF_MODE;
	    Log.d(LOG_TAG, "resetDialogState");
	}
}
