/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 * 
 * MediaTek Inc. (C) 2010. All rights reserved.
 * 
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

package com.mediatek.engineermode.tests;

import android.app.Activity;
import android.app.Instrumentation;
import android.content.Context;
import android.test.ActivityInstrumentationTestCase2;
import android.widget.EditText;

import com.jayway.android.robotium.solo.Solo;
import com.mediatek.engineermode.R;
import com.mediatek.engineermode.display.Display;

public class DisplayTest extends ActivityInstrumentationTestCase2<Display> {

    private Solo mSolo;
    private Context mContext;
    private Instrumentation mIns;
    private Activity mActivity;

    public DisplayTest() {
        super("com.mediatek.engineermode", Display.class);
    }

    @Override
    protected void setUp() throws Exception {
        super.setUp();
        mIns = getInstrumentation();
        mContext = mIns.getTargetContext();
        mActivity = getActivity();
        mSolo = new Solo(mIns, mActivity);
    }

    @Override
    protected void tearDown() throws Exception {
        super.tearDown();
    }

    private void verifyPreconditions() {
        assertTrue(mIns != null);
        assertTrue(mActivity != null);
        assertTrue(mContext != null);
        assertTrue(mSolo != null);
    }

    public void testCase01_VerifyPreconditions() {
        verifyPreconditions();
    }

    public void testCase02_CheckBtn() {
        // set pwm 70
        mSolo.clearEditText(0);
        mSolo.enterText(0, "70");
        mSolo.clickOnButton(mActivity.getResources().getString(
                R.string.Display_set));
        mSolo.sleep(EmOperate.TIME_SUPER_LONG);
        
        mSolo.clearEditText(0);
        mSolo.enterText(0, "20");
        mSolo.sleep(EmOperate.TIME_LONG);
        
        mSolo.clickOnButton(mActivity.getResources().getString(
                R.string.Display_set));
        mSolo.sleep(EmOperate.TIME_SUPER_LONG);
        
        mSolo.clickOnButton(mActivity.getResources().getString(
                R.string.Display_lcd_off));
        mSolo.sleep(EmOperate.TIME_LONG);
        
        mSolo.clickOnButton(mActivity.getResources().getString(
                R.string.Display_lcd_on));
        mSolo.sleep(EmOperate.TIME_LONG);
  
        if(false) {
            // 6589 issue will block function test, restore it after the issue is fixed.
            mSolo.clickOnButton(mActivity.getResources().getString(
                    R.string.Display_lcm_off));
            mSolo.sleep(EmOperate.TIME_LONG);
            
            mSolo.clickOnButton(mActivity.getResources().getString(
                    R.string.Display_lcm_on));
            mSolo.sleep(EmOperate.TIME_SUPER_LONG);
        }
        mSolo.goBack();
    }

//    public void testCase03_PMU() {
//        
//        /** Return error about view is null */
//        // mSolo.clickOnView(mActivity.findViewById(R.id.pmu_bank_spinner));
//        mSolo.clickOnText(SPINNERNAME_BANK0);
//        mSolo.sleep(EmOperate.TIME_SHORT);
//        mSolo.clickOnText(SPINNERNAME_BANK1);
//
////        mSolo.enterText((EditText) mActivity.findViewById(R.id.pmu_edit_addr),
////                ADDRESS);
//        mSolo.enterText(0, ADDRESS);
//        mSolo.clickOnButton(mActivity.getResources().getString(
//                R.string.pmu_btn_get));
//        mSolo.sleep(EmOperate.TIME_SHORT);
//        mSolo.clickOnButton(mActivity.getResources().getString(
//                R.string.pmu_btn_set));
//    }

}
