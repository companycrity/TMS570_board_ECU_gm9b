/*****************************************************************************
* Copyright 2015 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : gmheader.c
* Module Description: GM Header
* Product           : Gen II Plus - EA3
* Author            : P.Srinivasa
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#4 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Fri Oct 11 13:32:48 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 08/25/15  2        GMN       Part numbers update for version 01.00.01
 * 12/10/15  3        GMN       Part numbers update for version 02.00.00
 * 02/02/16  4        GMN       EA3#2919: New bootloader 02.00.00                                             5902
 * 04/04/16  5        GMN       Changed Cal Part Number to array of uint16 to avoid packing
 */

#define GM_HEADER_DATA

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "gmheader.h"

#pragma DATA_SECTION (PresencePatternApp, "N_PresPattAppSeg")
const uint16 PresencePatternApp = 0xA596U;
#pragma DATA_SECTION (PresencePatternCal, "N_PresPattCalSeg")
const uint16 PresencePatternCal = 0xA596U;
#pragma DATA_SECTION (PresencePatternCal2, "N_PresPattCalSeg2")
const uint16 PresencePatternCal2 = 0xA596U;
#pragma DATA_SECTION (PresencePatternCal3, "N_PresPattCalSeg3")
const uint16 PresencePatternCal3 = 0xA596U;

/* #pragma to locate data to the first segment of the application via linker command file!!! */
#pragma DATA_SECTION(GM_ApplHeader,"N_AppHeaderSeg");/* PRQA S:DS46_3116 3116 */
const tSwmApplHeader GM_ApplHeader =
{
	/* 16-Bit value calculated from integrity algorithm */
	INTEGRITY_WORD,

	/* 2-byte Configuration options */
	CONFIG_OPTIONS,

	/* 2 bytes for the Module ID */
	MODID_APPLICATION,

	/* Followed by 2 byte Data Compatibility Identifier */
	DCID_APPLICATION,

	/* Indicates the Application software-Not Before ID of the current application software version */
	APP_NBID,

	/* DLS: Design Level Suffix - 2 bytes ASCII */
	APP_DLS,

	/* 4 byte SW module Part Number in hex format */
	HEX_PART_NO_APPLICATION,

	/* No of Application region's */
	SWM_DATA_MAX_NOAR_APP,

	/* Application SW Location Info */
	{             /* App SW Info */
		{{0x0002U,0x0000U}, {0x0007U,0xFFF0U}}    /* Application */
	},

	/* Followed by Number-of-Partitions */
	SWM_DATA_MAX_NOAM,

	/* Provide as many additional-modules in NOAM (we use 2 in our example). */
	{                        /* Region Info */                                                                 /* Cal module Info */
		{0x0001U, {0x0001U,0x0000U},  {0x0000U,0x4000U}, 0x0001U, MODID_CALIBRATION2,  DCID_CALIBRATION, {0x0001U,0x0000U},  {0x0000U,0x3FF0U}}, /* Calibration 2 */
		{0x0001U, {0x0001U,0x4000U},  {0x0000U,0xC000U}, 0x0001U, MODID_CALIBRATION3,  DCID_CALIBRATION, {0x0001U,0x4000U},  {0x0000U,0xBFF0U}}, /* Calibration 3 */
		{0x0001U, {0x000AU,0x0000U},  {0x0002U,0x0000U}, 0x0001U, MODID_CALIBRATION,   DCID_CALIBRATION, {0x000AU,0x0000U},  {0x0001U,0xFFF0U}}, /* Calibration 1 */
	}
};

/* #pragma to locate data to the first segment of the calibration via linker command file!!! */
#pragma DATA_SECTION(GM_CalHeader,"N_CalHeaderSeg"); /* PRQA S:DS46_3116 3116 */
const tSwmCalHeader GM_CalHeader=
{
	/* 16-Bit value calculated from integrity algorithm */
	INTEGRITY_WORD,

	/* 2-byte Configuration options */
	CONFIG_OPTIONS,

	/* 2 bytes for the Module ID */
	MODID_CALIBRATION,

	/* Followed by 2 byte Data Compatibility Identifier */
	DCID_CALIBRATION,

	/*DLS: Design Level Suffix - 2 bytes ASCII */
	CAL_DLS,

	/* 4 byte SW module Part Number in hex format */
	HEX_PART_NO_CALIBRATION
};

/* #pragma to locate data to the first segment of the calibration via linker command file!!! */
#pragma DATA_SECTION(GM_Cal2Header,"N_Cal2HeaderSeg"); /* PRQA S:DS46_3116 3116 */
const tSwmCalHeader GM_Cal2Header=
{
	/* 16-Bit value calculated from integrity algorithm */
	INTEGRITY_WORD,

	/* 2-byte Configuration options */
	CONFIG_OPTIONS,

	/* 2 bytes for the Module ID */
	MODID_CALIBRATION2,

	/* Followed by 2 byte Data Compatibility Identifier */
	DCID_CALIBRATION,

	/*DLS: Design Level Suffix - 2 bytes ASCII */
	CAL2_DLS,

	/* 4 byte SW module Part Number in hex format */
	HEX_PART_NO_CALIBRATION2
};

/* #pragma to locate data to the first segment of the calibration via linker command file!!! */
#pragma DATA_SECTION(GM_Cal3Header,"N_Cal3HeaderSeg"); /* PRQA S:DS46_3116 3116 */
const tSwmCalHeader GM_Cal3Header=
{
	/* 16-Bit value calculated from integrity algorithm */
	INTEGRITY_WORD,

	/* 2-byte Configuration options */
	CONFIG_OPTIONS,

	/* 2 bytes for the Module ID */
	MODID_CALIBRATION3,

	/* Followed by 2 byte Data Compatibility Identifier */
	DCID_CALIBRATION,

	/*DLS: Design Level Suffix - 2 bytes ASCII */
	CAL3_DLS,

	/* 4 byte SW module Part Number in hex format */
	HEX_PART_NO_CALIBRATION3
};
