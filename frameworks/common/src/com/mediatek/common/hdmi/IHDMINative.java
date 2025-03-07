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

package com.mediatek.common.hdmi;
//add for HDMINative.java interface
public interface IHDMINative {
    public static final int DISPLAY_TYPE_HDMI = 0;
    public static final int DISPLAY_TYPE_SMB = 1;
    public static final int DISPLAY_TYPE_MHL = 2;
    public static final int FEATURE_SCALE_ADJUST = 0x01;
    public static final int FEATURE_NO_CALL = 0x02;
    
    public  boolean enableHDMI(boolean enabled);
    public  boolean enableHDMIIPO(boolean enabled);
    public  boolean enableVideo(boolean enabled);
    public  boolean enableAudio(boolean enabled);
    public  boolean enableCEC(boolean enbaled);
    public  boolean enableHDCP(boolean enabled);
    public  boolean setVideoConfig(int newValue);
    public  boolean setAudioConfig(int newValue);
    public  boolean setDeepColor(int colorSpace, int deepColor);
    public  boolean setHDCPKey(byte[] key);
    public  boolean setHDMIDRMKey();
    public  boolean setCECAddr(byte laNum, byte[] la, char pa, char svc);
    public  boolean setCECCmd(byte initAddr, byte destAddr, char opCode, byte[] operand, int size, byte enqueueOk);
    public  boolean hdmiPowerEnable(boolean enabled);
    public  boolean hdmiPortraitEnable(boolean enabled);
    public  boolean isHdmiForceAwake();
    public  int[]   getEDID();
    public  char[]  getCECAddr();
    public  int[]   getCECCmd();
    public  boolean notifyOtgState(int otgState);
    public  int     getDisplayType();
    public  boolean needSwDrmProtect();
    public  int     getSupportedFeatures();
}
