/*****************************************************************************
* Copyright 2015 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : gmheader.h
* Module Description: GM Header
* Product           : Gen II Plus - EA3
* Author            : P.Srinivasa
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Mon Jun 21 10:55:38 2004
* %version:          EA3#16 %
* %derived_by:       fz9hxm %
* %date_modified:    Wed Feb 12 14:32:54 2014 %
*----------------------------------------------------------------------------
* CHANGE HISTORY:
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  ----------
* 04/24/15     1       GMN       Initial 9Bxx Synergy Version
* 12/11/15     2       GMN       Updated DCID_CALIBRATION for 02.00.00
* 02/02/16     3       GMN       EA3#2919: New bootloader 02.00.00                                           5902
* 02/29/16     4       GMN       EA3#2919: GM Part Numbers                                                   6363
* 04/01/16     5       GMN       Change the DCID_APPLICATION back (increased by mistake)
* 04/04/16     6       GMN       Changed Cal Part Number to array of uint16 to avoid packing
* 04/22/16     7       GMN       Changed APP_DLS to "AD" for 04.03.01 build
* 05/20/16     8       GMN       Changed APP_DLS to "AE" for 05.01.02 build
* 06/23/16     9       GMN       Changed APP_DLS to "AF" for 06.01.00 build
* 08/11/16     10      GMN       Changed APP_DLS to "AG" for 06.02.00 build
* 09/01/16     11      GMN       Changed APP_DLS to "AH" for 06.03.00 build
* 09/13/16     12      GMN       Changed APP_DLS to "AF" for 06.03.03 build
* 10/28/16     13      CP        Changed APP_DLS to "AH" and Mod ID for SysCal1, SysCCal2 and PerfCal as 4,2 and 3
* 12/20/16     14      CP        Changed APP_DLS to "AJ"
* 01/15/17     15      CP        Changed part numbers to 39053401.AK
* 04/05/17     16      CP        Changed APP_DLS to BA
*****************************************************************************/

#ifndef GMHEADER_H
#define GMHEADER_H

#include "Std_Types.h"

/* Use this number as the max. PMA you will reserve for CANFlash */
#define SWM_DATA_MAX_NOAR_APP       0x0001u

/* Use this number as the max. additional-modules reserved for CANFlash */
#define SWM_DATA_MAX_NOAM           0x0003u

/* Checksum magic code to instruct CANFLash to calculate the HEX-File checksum */
#define INTEGRITY_WORD              0xFFFFu
#define CONFIG_OPTIONS              0x0000u
#define APP_NBID                    0x0001u

/* Module ID for the application */
#define MODID_APPLICATION           0x0001u
#define MODID_CALIBRATION           0x0004u
#define MODID_CALIBRATION2          0x0002u
#define MODID_CALIBRATION3          0x0003u

/* SWMI Part Numbers */
#define HEX_PART_NO_APPLICATION     0x253E859   /* 39053401 */
#define HEX_PART_NO_CALIBRATION     {0x2222U, 0x2222U}
#define HEX_PART_NO_CALIBRATION2    {0x3333U, 0x3333U}
#define HEX_PART_NO_CALIBRATION3    {0x4444U, 0x4444U}

/* DLS: Design Level Suffix - 2 bytes ASCII */
#define APP_DLS  0x4241u /* BA */
#define CAL_DLS  0x4141u /* AA */
#define CAL2_DLS 0x4141u /* AA */
#define CAL3_DLS 0x4141u /* AA */

/* Data Compatibility ID for the application: Must match DCID in FBL */
#define DCID_APPLICATION            0x8004u

/* Data Compatibility ID for the calibration: Must match DCID in App */
#define DCID_CALIBRATION            0x9012u

typedef struct {
	uint16     IW;                  /* Integrity Word */
	uint16     CONFIG;              /* Configuration Options */
	uint16     MID;                 /* Module ID */
	uint16     DCID;                /* Data Compatibility Identifier */
	uint16     App_NBID;            /* Application Software-Not Before ID */
	uint16     DLS;                 /* Design Level Suffix */
	uint32     PART_NO;             /* Hex Part Number */
	uint16     NOAR;                /* Number Of Address Regions */
	struct {
		uint16 PMA[2];              /* Product Memory Address */
		uint16 NOB[2];              /* Number Of Bytes */
	} PMA_NOB[SWM_DATA_MAX_NOAR_APP];
	uint16     NOAM;                /* Number of Additional Modules */
	struct {
		uint16 NOAR;                /* Number of Address Regions */
		uint16 PMA[2];              /* Product Memory Address */
		uint16 NOB[2];              /* Number Of Bytes */
		uint16 NOCM;                /* Number of Cal modules */
		uint16 CMID;                /* Cal Module ID */
		uint16 CCID;                /* Cal Compatibility Identifier */
		uint16 PMA_Cal[2];          /* Product Memory Address */
		uint16 NOB_Cal[2];          /* Number Of Bytes */
	} PMA_NOAM[SWM_DATA_MAX_NOAM];
} tSwmApplHeader;

typedef struct {
	uint16     IW;                  /* Integrity Word */
	uint16     CONFIG;              /* Configuration Options */
	uint16     MID;                 /* Module ID */
	uint16     DCID;                /* Data Compatibility Identifier */
	uint16     DLS;                 /* Design Level Suffix */
	uint16     SWMI[2];             /* Hex Part Number - Used array of uint16 to avoid packing */
} tSwmCalHeader;

/* Export the header definition */
extern const tSwmApplHeader GM_ApplHeader;
extern const tSwmCalHeader GM_CalHeader;
extern const tSwmCalHeader GM_Cal2Header;
extern const tSwmCalHeader GM_Cal3Header;

#endif
