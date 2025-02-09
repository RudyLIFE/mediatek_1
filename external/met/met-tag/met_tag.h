/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2012. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */


#ifndef MET_TAG
#define MET_TAG

#ifdef __cplusplus
extern "C" {
#endif


#define MAX_EVENT_CLASS	31
#define MAX_TAGNAME_LEN	128
#define MET_CLASS_ALL	0x80000000

//IOCTL commands of MET tagging
typedef struct _mtag_cmd_t
{
	unsigned int class_id;
	unsigned int value;
	unsigned int slen;
	char tname[MAX_TAGNAME_LEN];
	void *data;
	unsigned int size;
} mtag_cmd_t;

#define TYPE_START		1
#define TYPE_END		2
#define TYPE_ONESHOT	3
#define TYPE_ENABLE		4
#define TYPE_DISABLE	5
#define TYPE_REC_SET	6
#define TYPE_DUMP		7
#define TYPE_DUMP_SIZE	8
#define TYPE_DUMP_SAVE	9

/* Use 'm' as magic number */
#define MTAG_IOC_MAGIC  'm'
/* Please use a different 8-bit number in your code */
#define MTAG_CMD_START		_IOW(MTAG_IOC_MAGIC, TYPE_START, mtag_cmd_t)
#define MTAG_CMD_END		_IOW(MTAG_IOC_MAGIC, TYPE_END, mtag_cmd_t)
#define MTAG_CMD_ONESHOT	_IOW(MTAG_IOC_MAGIC, TYPE_ONESHOT, mtag_cmd_t)
#define MTAG_CMD_ENABLE		_IOW(MTAG_IOC_MAGIC, TYPE_ENABLE, int)
#define MTAG_CMD_DISABLE	_IOW(MTAG_IOC_MAGIC, TYPE_DISABLE, int)
#define MTAG_CMD_REC_SET	_IOW(MTAG_IOC_MAGIC, TYPE_REC_SET, int)
#define MTAG_CMD_DUMP		_IOW(MTAG_IOC_MAGIC, TYPE_DUMP, mtag_cmd_t)
#define MTAG_CMD_DUMP_SIZE	_IOWR(MTAG_IOC_MAGIC, TYPE_DUMP_SIZE, int)
#define MTAG_CMD_DUMP_SAVE	_IOW(MTAG_IOC_MAGIC, TYPE_DUMP_SAVE, mtag_cmd_t)

//include file
#ifndef MET_USER_EVENT_SUPPORT
#define met_tag_init()	(0)

#define met_tag_uninit()	(0)

#define met_tag_start(id, name) (0)

#define met_tag_end(id, name) (0)

#define met_tag_oneshot(id, name, value) (0)

#define met_tag_dump(id, name, data, length) (0)

#define met_tag_disable(id) (0)

#define met_tag_enable(id) (0)

#define met_set_dump_buffer(size) (0)

#define met_save_dump_buffer(pathname) (0)

#define met_save_log(pathname) (0)

#define met_record_on() (0)

#define met_record_off() (0)

#else
int met_tag_init(void);

int met_tag_uninit(void);

int met_tag_start(unsigned int class_id, const char *name);

int met_tag_end(unsigned int class_id, const char *name);

int met_tag_oneshot(unsigned int class_id, const char *name, unsigned int value);

int met_tag_dump(unsigned int class_id, const char *name, void *data, unsigned int length);

int met_tag_disable(unsigned int class_id);

int met_tag_enable(unsigned int class_id);

int met_set_dump_buffer(int size);

int met_save_dump_buffer(const char *pathname);

int met_record_on(void);

int met_record_off(void);
#endif //MET_USER_EVENT_SUPPORT

#ifdef __cplusplus
}
#endif


#endif //MET_EVENT
