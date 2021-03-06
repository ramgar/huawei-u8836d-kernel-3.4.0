/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
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

#ifndef CUST_FM_H
#define CUST_FM_H

typedef enum{
	FM_RDS_TX_DISENABLE = 0,
	FM_RDS_TX_ENABLE
}fm_rds_tx_enable_state;

/*
FM BAND width
0x01: US/Europe band  87.5MHz ~ 108MHz
0x02: Japan band      76MHz   ~ 90MHz
0x03: Japan wideband  76MHZ   ~ 108MHz
*/
// band
#define FM_BAND_UNKNOWN 0
#define FM_BAND_UE      1 // US/Europe band  87.5MHz ~ 108MHz (DEFAULT)
#define FM_BAND_JAPAN   2 // Japan band      76MHz   ~ 90MHz
#define FM_BAND_JAPANW  3 // Japan wideband  76MHZ   ~ 108MHz
#define FM_BAND_DEFAULT FM_BAND_UE
#define FM_FREQ_MIN  875
#define FM_FREQ_MAX  1080
#define FM_FMD_BAND  FM_BAND_UE

#define FM_TX_RDS "mtkRds"

enum fmr_err_em {
    ERR_SUCCESS = 10000, // kernel error begin at here
    ERR_INVALID_BUF,
    ERR_INVALID_PARA,
    ERR_STP,
    ERR_GET_MUTEX,
    ERR_FW_NORES,
    ERR_RDS_CRC,
    ERR_INVALID_FD, //  native error begin at here
	ERR_UNSUPPORT_CHIP,
	ERR_LD_LIB,
	ERR_FIND_CUST_FNUC,
	ERR_UNINIT,
	ERR_NO_MORE_IDX,
	ERR_RDS_NO_DATA,
    ERR_MAX
};

enum fmtx_tone_freq {
    FMTX_1K_TONE = 1, 
    FMTX_2K_TONE = 2,
    FMTX_3K_TONE = 3,
    FMTX_4K_TONE = 4,
    FMTX_5K_TONE = 5,
    FMTX_6K_TONE = 6,
    FMTX_7K_TONE = 7,
    FMTX_8K_TONE = 8,
    FMTX_9K_TONE = 9,
    FMTX_10K_TONE = 10,
    FMTX_11K_TONE = 11,
    FMTX_12K_TONE = 12,
    FMTX_13K_TONE = 13,
    FMTX_14K_TONE = 14,
    FMTX_15K_TONE = 15,
    FMTX_MAX_TONE
};

/*
FM Seek/scan width
0x01: 100KHz
0x02: 200KHz
*/
#define FM_SPACE_WIDTH   0x01

/*
FM factory mode test freq
Unit:100KHz
*/
uint16_t fmtx_freq_list[] = {878, 886, 891, 910, 920, 930, 940, 990, 1050, 1070};
//unsigned char fmtx_ps[8] = {'m', 't', 'k', 'F', 'm', 'R', 'd', 's'};
unsigned char fmtx_ps[8] = {0};

#define FMR_ASSERT(a) { \
			if ((a) == NULL) { \
				LOGE("%s,invalid buf\n", __func__);\
				return -ERR_INVALID_BUF; \
			} \
		}

#endif /* CUST_FM_H */
