/**********************************************************************************************************************
* Copyright 2016 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_SrlComOutput_Cfg.h
* Module Description: SrlComOutput configuration.
* Product           : Gen II Plus - EA3.0
* Author            : Gustavo Muller Nunes
**********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          1 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Wed Mar  5 13:35:47 2014 %
 */

#ifndef AP_SRLCOMOUTPUT_CFG_H
#define AP_SRLCOMOUTPUT_CFG_H

/*
 * Enable/Disable the signal for warning indication Steering Reduced Assist Level 2.
 * Message Power_Steering_Information_HS 0x148.
 *
 * If enabled, the integration must have:
 * - Indicator named as: Dem_Steering_Reduced_Assist_Level2;
 * - Signal put macro named as: IlPutTxStrAsstRdcdLvl2IO.
 */
#define D_WARNINGINDSTEERINGREDUCEDASSIST2_ENABLED    1

/*
 * List of NTCs to check for Torque. This list is used by the signals DrvStrIntfrDtcdV, LKADrvAppldTrqV and
 * HndsOffStrWhlDtStV to go to invalid.
 *
 * Note: Make sure that all NTCs in the list are defined in DiagMgr_Cfg.c.
 */
#define D_LISTOFTORQUENTC_CNT_U16 \
			{NTC_Num_EEPROMDiag,              /* NTC 0x00A */ \
			 NTC_Num_PriSnsrTrqStorFlt,       /* NTC 0x00C */ \
			 NTC_Num_LoaCtrldShutdn,          /* NTC 0x0AB */ \
			 NTC_Num_TrqSensorScaleNotSet,    /* NTC 0x1FA */ \
			 NTC_Num_TrqSensorNotTrimmed,     /* NTC 0x1FB */ \
			 NTC_Num_TrqSensorNotTrimmed,     /* NTC 0x1FC */ \
			 NTC_Num_SENTHWDiffTqOfstNotTrmd} /* NTC 0x1FF */

#endif
