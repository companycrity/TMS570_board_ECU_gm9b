/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_DigColPs.c
 *     Workspace:  C:/SynergyWorkArea/Working/DigColPs/autosar
 *     SW-C Type:  Sa_DigColPs
 *  Generated at:  Fri Nov 11 15:25:58 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_DigColPs>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Nov 29 18:34:17 2011
 * %version:          EA3#13 %
 * %date_modified:    Tue Feb 18 09:54:35 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/11/13  1        Jared     Initial component creation for ES-20D v001                                   8850
 * 11/20/13  2        Jared     Updated to FDD v002 to correct A5906                                         10626
 *                              Added new EOLTrimPerformed output to correct A5721                           10552
 *                              Corrected VernierFaultActive logic to correct A5895                          10794
 * 02/27/14  3        Rijvi     Updated to FDD v003 and fixed Anomaly 6135                                   10979
 * 03/20/14  4        Rijvi     Update to FDD rev.004                                                        11266
 *                              Update to FDD rev.005 (anomaly# 6471)                                        11594
 *                              Fix Anomaly# 6089                                                            11611
 * 03/26/14  5        Rijvi     Updated to FDD rev.006 and fixed Anomaly 6483                                11641
 * 05/13/14  6        Selva     Updated for FDD rev 007 and fixed Anomaly 6680                               11926
 * 06/30/14  7        Jared     Updated to FDD rev 008 (Dual Spur design)                                    12145
 * 07/28/14  8        Selva     Updated for FDD rev 009 and 010  and version 11                              12221
 * 07/20/15	 9		  JK		Anomaly Fix #EA3-1992:Position Trim data loss if read all does not complete  13492
 * 05/09/16  10       JK        Update to FDD rev 015 - Anomaly fix: EA3#1966 ,EA3#2989                   EA3#4101
 * 05/31/16  11       JK        Update to FDD rev 016 - Anomaly fix: EA3#8655                             EA3#8667
 * 08/03/16  12       JK        Update to FDD rev 018 - Anomaly fix: EA3#9596                             EA3#9922
 * 10/19/16  13       JK        Update to FDD rev 020                                          EA3#10275,EA3#12066
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  NvM_DestPtr
    DataPtr Type to be used by WriteBlock, ReadBlock and RestoreBlockDefaults operations. 	This type is used for all NVRAM blocks


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service

 *********************************************************************************************************************/

#include "Rte_Sa_DigColPs.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Sa_DigColPsInt.h"
#include "GlobalMacro.h"
#include "filters.h"
#include "fixmath.h"
#include "CalConstants.h"
#include "interrupts.h"
#include "Os.h"

/* PRQA S 4393 EOF
 * MISRA-C: 2004 Rule 10.3: This deviation is required for library macros.  The rule is suppressed for the entire file */

/* PRQA S 310 EOF
 * MISRA-C: 2004 Rule 11.4: This deviation is required for library macros.  The rule is suppressed for the entire file */

/* PRQA S 2985 EOF
 * MISRA-C: 2004 Rule 21.1: This deviation is required for code consistency.  The rule is suppressed for the entire file */

/* MISRA-C:2004 Rule 8.7: This deviation is required to keep the memory map intact.  Rule suppressed by line at each occurrence. */
/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

/*** Locally Defined Constants ***/
#define D_INVSPURRATIO_ULS_F32          (1.0f / 2.2f)
#define D_SPURRATIO_ULS_F32             2.2f
#define D_INVDUALSPURRATIO_ULS_F32      (1.0f / 2.0f)
#define D_DUALSPURRATIO_ULS_F32         (2.0f)
#define D_ONEREV_DEGREESPREV_F32        360.0f
#define D_VERNIERANGLECENTEROFF_DEG_F32 900.0f
#define D_HWANGLEATCENTER_DEG_F32       180.0f
#define D_ANGLEZEROODDPARITY_CNT_U16    0x1000U
#define D_ANGLEDATA_CNT_U08             1U
#define D_ERRORREG_CNT_U08              3U
#define D_EXTERRORREG_CNT_U08           4U
#define D_MAXHWPOS_HWDEG_F32            900.0f

/* Row offsets in *VernierLUT for lookup and translations to revs */
#define D_VERNIERLEVEL_CNT_U08          0U
#define D_COLUMNREVS_CNT_U08            1U
#define D_SPURREVS_CNT_U08              2U
#define D_VERNIERLEVELNO_CNT_U08        3U
#define D_DUALSPURTBLXSIZE_CNT_U08      22U

#define D_TRIMCOMPLETE_CNT_U16          1U
#define D_TRIMNOTCOMPLETE_CNT_U16       4488U
#define D_I2CHWTRIMTRANSCNT_ULS_U08     6U
#define D_I2HW11TO10TRATIO_ULS_F32     (1.1f)
#define D_SNSRREINITTIME_MS_U32        10U
#define D_SNSRERRORBIT_CNT_U16         0x4000U
#define D_ANGREGIDBIT_CNT_U16          0x8000U
#define D_ANGLEMASK_CNT_U16            0x0FFFU
#define D_COMMORPARITYERR_CNT_U08      0x3EU

/*** Module Internal Variables ***/
#define DIGCOLPS_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32,AP_DIGCOLPS_VAR) DigColPs_I2CHwColAngle_Deg_M_f32;                      /* PRQA S 3218 */
STATIC VAR(float32,AP_DIGCOLPS_VAR) DigColPs_I2CHwSpurAngle_Deg_M_f32;                     /* PRQA S 3218 */
STATIC VAR(float32,AP_DIGCOLPS_VAR) DigColPs_PrevI2CHwColAngle_Deg_M_f32;                  /* PRQA S 3218 */
STATIC VAR(float32,AP_DIGCOLPS_VAR) DigColPs_PrevI2CHwSpurAngle_Deg_M_f32;                 /* PRQA S 3218 */
STATIC VAR(float32,AP_DIGCOLPS_VAR) DigColPs_PrevColPos_Deg_M_f32;                         /* PRQA S 3218 */
STATIC VAR(float32,AP_DIGCOLPS_VAR) DigColPs_ColTrimStatic_Deg_M_f32;                      /* PRQA S 3218 */
STATIC VAR(float32,AP_DIGCOLPS_VAR) DigColPs_SpurTrimStatic_Deg_M_f32;                     /* PRQA S 3218 */
STATIC VAR(float32,AP_DIGCOLPS_VAR) DigColPs_I2CHwColAngleForTrim_Deg_M_f32;               /* PRQA S 3218 */
STATIC VAR(uint32,AP_DIGCOLPS_VAR) DigColPs_SnsrReInitTmr_mS_M_u32;                        /* PRQA S 3218 */
STATIC VAR(float32,AP_DIGCOLPS_VAR) DigColPs_PrevI2CAbsHwPos_HwDeg_M_f32;                  /* PRQA S 3218 */
STATIC volatile VAR(float32,AP_DIGCOLPS_VAR) DigColPs_VernDiagError_Deg_D_f32;             /* PRQA S 3218 */
STATIC volatile VAR(float32,AP_DIGCOLPS_VAR) DigColPs_ColAngle_Deg_D_f32;                  /* PRQA S 3218 */
STATIC volatile VAR(float32,AP_DIGCOLPS_VAR) DigColPs_SpurAngle_Deg_D_f32;                 /* PRQA S 3218 */
STATIC volatile VAR(float32,AP_DIGCOLPS_VAR) DigColPs_VernierLevel_Deg_D_f32;              /* PRQA S 3218 */
STATIC volatile VAR(float32,AP_DIGCOLPS_VAR) DigColPs_I2CHwColAngleTrim_Deg_D_f32;         /* PRQA S 3218 */
STATIC volatile VAR(float32,AP_DIGCOLPS_VAR) DigColPs_I2CHwSpurAngleTrim_Deg_D_f32;        /* PRQA S 3218 */
STATIC volatile VAR(float32,AP_DIGCOLPS_VAR) DigColPs_I2CHWSpurPos_HwDeg_D_f32;            /* PRQA S 3218 */
#define DIGCOLPS_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define DIGCOLPS_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16,AP_DIGCOLPS_VAR) DigColPs_VernCorrDetectAcc_Cnt_M_u16;                   /* PRQA S 3218 */
STATIC VAR(uint16,AP_DIGCOLPS_VAR) DigColPs_SkipStepFltDetectAcc_Cnt_M_u16;                /* PRQA S 3218 */
STATIC VAR(uint16,AP_DIGCOLPS_VAR) DigColPs_I2CHwColAngle_Cnt_M_u16;                       /* PRQA S 3218 */
STATIC VAR(uint16,AP_DIGCOLPS_VAR) DigColPs_I2CHwSpurAngle_Cnt_M_u16;                      /* PRQA S 3218 */
STATIC VAR(uint16,AP_DIGCOLPS_VAR) DigColPs_TrimCompStatic_Cnt_M_u16;                      /* PRQA S 3218 */
STATIC VAR(sint16,AP_DIGCOLPS_VAR) DigColPs_ColRoughTurns_Cnt_M_s16;                       /* PRQA S 3218 */
STATIC VAR(sint16,AP_DIGCOLPS_VAR) DigColPs_SpurRoughTurns_Cnt_M_s16;                      /* PRQA S 3218 */
STATIC VAR(uint16,AP_DIGCOLPS_VAR) DigColPs_SnsrReInitElapsedTime_mS_M_u16;                /* PRQA S 3218 */
#define DIGCOLPS_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define DIGCOLPS_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_DIGCOLPS_VAR) DigColPs_I2CHwDataType_Cnt_M_u08;                        /* PRQA S 3218 */
STATIC VAR(uint8, AP_DIGCOLPS_VAR) DigColPs_I2CHwDataTypeMdfy_Cnt_M_u08;                    /* PRQA S 3218 */
STATIC VAR(uint8, AP_DIGCOLPS_VAR) DigColPs_I2CSensCommFlts_Cnt_M_u08;                      /* PRQA S 3218 */
STATIC VAR(uint8, AP_DIGCOLPS_VAR) DigColPs_ReqI2CSnsrDataType_Cnt_M_u08;                   /* PRQA S 3218 */
STATIC VAR(uint8, AP_DIGCOLPS_VAR) DigColPs_PrevVernierLevelNo_Cnt_M_u08;                   /* PRQA S 3218 */
STATIC VAR(uint8, AP_DIGCOLPS_VAR) DigColPs_I2CHwTrimTransCnts_Uls_M_u08;                   /* PRQA S 3218 */
STATIC VAR(uint8, AP_DIGCOLPS_VAR) DigColPs_SnsrReInitMaxTryCntr_Cnt_M_u08;
STATIC VAR(uint8, AP_DIGCOLPS_VAR) DigColPs_I2CSensCommFltsMdfy_Cnt_M_u08;
#define DIGCOLPS_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define DIGCOLPS_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean,AP_DIGCOLPS_VAR) DigColPs_ColLPFInitDone_Cnt_M_lgc;                   /* PRQA S 3218 */
STATIC VAR(boolean,AP_DIGCOLPS_VAR) DigColPs_SpurLPFInitDone_Cnt_M_lgc;                  /* PRQA S 3218 */
STATIC VAR(boolean,AP_DIGCOLPS_VAR) DigColPs_VernierAngleOORange_Cnt_M_lgc;              /* PRQA S 3218 */
STATIC VAR(boolean,AP_DIGCOLPS_VAR) DigColPs_HwAVernCorrFault_Cnt_M_lgc;                 /* PRQA S 3218 */
STATIC VAR(boolean,AP_DIGCOLPS_VAR) DigColPs_SnsrReInitInProgs_Cnt_M_lgc;
STATIC VAR(boolean,AP_DIGCOLPS_VAR) DigColPs_SnsrSampleOk_Cnt_M_lgc;
STATIC VAR(boolean,AP_DIGCOLPS_VAR) DigColPs_ColSnsrErr_Cnt_M_lgc;
STATIC VAR(boolean,AP_DIGCOLPS_VAR) DigColPs_SpurSnsrErr_Cnt_M_lgc;
STATIC VAR(boolean,AP_DIGCOLPS_VAR) DigColPs_PrevTrimComplete_Cnt_M_lgc;                 /* PRQA S 3218 */
STATIC VAR(boolean,AP_DIGCOLPS_VAR) DigColPs_PrevI2CHwPosValid_Cnt_M_lgc;                /* PRQA S 3218 */
STATIC VAR(boolean, AP_DIGCOLPS_VAR) DigColPs_PrevAngleDataAvailable_Cnt_M_lgc;
STATIC VAR(boolean, AP_DIGCOLPS_VAR) DigColPs_ColSnsrFlt_Cnt_M_lgc;
STATIC VAR(boolean, AP_DIGCOLPS_VAR) DigColPs_SpurSnsrFlt_Cnt_M_lgc;
#define DIGCOLPS_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define DIGCOLPS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_DIGCOLPS_VAR) DigColPs_ColAngleLPFKSV_Cnt_M_str;              /* PRQA S 3218 */
STATIC VAR(LPF32KSV_Str, AP_DIGCOLPS_VAR) DigColPs_SpurAngleLPFKSV_Cnt_M_str;             /* PRQA S 3218 */
#define DIGCOLPS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/*** Locally defined tables ***/
#define DIGCOLPS_START_SEC_CONST_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC CONST(sint16, AP_DIGCOLPS_CONST) T2_DualSpurVernierLUT_Cnt_s16[4][D_DUALSPURTBLXSIZE_CNT_U08] = {                                                 /* PRQA S 3218 */
	{  -396, -360, -324, -288, -252, -216, -180, -144, -108,  -72,  -36,   0,    36,   72,  108,  144, 180, 216, 252, 288,   324,  360},
	{   9,		0,	  1,   2 ,	3,    4,     5,   6,    7,     8,    9,    0,     1,	2,	 3,		4,  5,   6,   7,   8,     9,	0 },
	{   0,		1,	  2,   3,   4,    5,     6,   7,    8,     9,   10,    0,     1,	2,	 3,		4, 	5,   6,   7,   8,     9,    10},
	{   22,     2,    4,    6,   8,   10,   12,   14,   16,   18,    20,   1,     3,    5,   7,     9,  11,  13,  15,  17,    19,   21}
};
#define DIGCOLPS_STOP_SEC_CONST_16
#include "MemMap.h" /* PRQA S 5087 */

/*** Function Prototypes ***/
STATIC FUNC(boolean, SA_DIGCOLPS_CODE) OddParityFault(
	VAR(uint16, AUTOMATIC) Input_Cnt_T_u16)
;
STATIC FUNC(boolean, SA_DIGCOLPS_CODE) DiagnosticThreshold(
	VAR(boolean, AUTOMATIC) FaultPresent_Cnt_T_lgc,
	CONST(DiagSettings_Str, AUTOMATIC) DiagSettings_Cnt_T_str,
	P2VAR(uint16, AUTOMATIC, AUTOMATIC) AccumulatorPtr_Cnt_T_u16
);
STATIC FUNC(void, SA_DIGCOLPS_CODE) VernierLookup(
	CONST(sint16, AUTOMATIC) VernierLUT_Cnt_T_s16[],
	VAR(uint8, AUTOMATIC) LookupTableXSize_Cnt_T_u08,
	VAR(float32, AUTOMATIC) Level_Deg_T_f32,
	P2VAR(uint8, AUTOMATIC, AUTOMATIC) ColRevPtr_Cnt_T_u08,
	P2VAR(uint8, AUTOMATIC, AUTOMATIC) SpurRevPtr_Cnt_T_u08,
	P2VAR(uint8, AUTOATIC, AUTOMATIC) VernierLevelNo_Cnt_T_u08
);
STATIC FUNC(float32, SA_DIGCOLPS_CODE) ComputeRoughTurns(
	VAR(float32, AUTOMATIC) Delta_Deg_T_f32,
	P2VAR(sint16, AUTOMATIC, AUTOMATIC) RoughTurnAccPtr_Cnt_T_s16
);
STATIC FUNC(float32, SA_DIGCOLPS_CODE) ConstrainOneRev(
	VAR(float32, AUTOMATIC) Input_Deg_T_f32
);

STATIC FUNC(void, SA_DIGCOLPS_CODE) I2CCommFltDiag(VAR(uint8, AUTOMATIC) I2CSensCommFlts_Cnt_T_u08);

STATIC FUNC(void, SA_DIGCOLPS_CODE) I2CSnsrDataCheck(VAR(uint16, AUTOMATIC) I2CHwColAngle_Cnt_T_u16,
													VAR(uint16, AUTOMATIC) I2CHwSpurAngle_Cnt_T_u16,
													P2VAR(boolean, AUTOMATIC, AUTOMATIC) ColSensorFault_Cnt_T_lgc,
													P2VAR(boolean, AUTOMATIC, AUTOMATIC) SpurSensorFault_Cnt_T_lgc,
													P2VAR(boolean, AUTOMATIC, AUTOMATIC) ColRegisterFaultCnt_T_lgc,
													P2VAR(boolean, AUTOMATIC, AUTOMATIC) SpurRegisterFaultCnt_T_lgc);

STATIC FUNC(uint8, SA_DIGCOLPS_CODE) I2CSnsrReInitMaxTry(VAR(uint8,AUTOMATIC) I2CSensCommFlts_Cnt_T_u08,
															VAR(boolean,AUTOMATIC) ColSensorFlt_Cnt_T_lgc,
															VAR(boolean,AUTOMATIC) SpurSensorFlt_Cnt_T_lgc);

STATIC FUNC(void, SA_DIGCOLPS_CODE) SnsrFltDiag(VAR(uint16, AUTOMATIC) I2CHwColAngle_Cnt_T_u16,
												VAR(uint16, AUTOMATIC) I2CHwSpurAngle_Cnt_T_u16,
												VAR(uint8, AUTOMATIC) I2CHwDataType_Cnt_T_u08,
												VAR(uint8, AUTOMATIC) I2CSensCommFlts_Cnt_T_u08,
												VAR(boolean, AUTOMATIC) ColSnsrErr_Cnt_T_lgc,
												VAR(boolean, AUTOMATIC) SpurSnsrErr_Cnt_T_lgc);

STATIC FUNC(void, SA_DIGCOLPS_CODE) VernCorrlnFltDiag(VAR(boolean, AUTOMATIC) VernCorrDetect_Cnt_T_lgc,
													VAR(boolean, AUTOMATIC) SkipStepFltDetect_Cnt_T_lgc);

STATIC FUNC(boolean, SA_DIGCOLPS_CODE) ChkVernCorrlnError(VAR(uint8, AUTOMATIC) VernierLevelNo_Cnt_T_u08,
														VAR(float32, AUTOMATIC) VernDiagError_Deg_T_f32,
														VAR(boolean, AUTOMATIC) TrimComplete_Cnt_T_lgc);

STATIC FUNC(boolean, SA_DIGCOLPS_CODE) ChkSkipStepError(VAR(uint8, AUTOMATIC) AbsVernLevelDiff_Cnt_T_u08,
														VAR(boolean, AUTOMATIC) TrimComplete_Cnt_T_lgc);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ManufModeType: Enumeration of integer in interval [0...2] with enumerators
 *   ProductionMode (0u)
 *   ManufacturingMode (1u)
 *   EngineeringMode (2u)
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1u)
 *   NTC_Num_FlashECCCorr (2u)
 *   NTC_Num_FlashECCMemFlt (3u)
 *   NTC_Num_FlashCRCMemFault (4u)
 *   NTC_Num_NvMBlkDftActA (6u)
 *   NTC_Num_NvMBlkDftActB (7u)
 *   NTC_Num_NvMBlkDftActC (8u)
 *   NTC_Num_CurrentSensorCalOutOfRange (9u)
 *   NTC_Num_EEPROMDiag (10u)
 *   NTC_Num_EEPROMDiagMtrStr (11u)
 *   NTC_Num_PriSnsrTrqStorFlt (12u)
 *   NTC_Num_EEPROMDiagPosTrimStr (13u)
 *   NTC_Num_SecSnsrTrqStorFlt (14u)
 *   NTC_Num_EEPROMDiagPolarityStr (15u)
 *   NTC_Num_RAMDiag_GeneralFlt (16u)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17u)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18u)
 *   NTC_Num_RAMDiag_ECCMemFlt (19u)
 *   NTC_Num_RAMDiag_CRCMemFlt (20u)
 *   NTC_Num_RAMDiag_VIMRamFlt (23u)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24u)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25u)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26u)
 *   NTC_Num_RAMDiag_DCANRamFault (27u)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28u)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29u)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30u)
 *   NTC_Num_CPU_RegVer (32u)
 *   NTC_Num_CPU_CoreInitFlt (33u)
 *   NTC_Num_CPU_CoreRunTimeFlt (34u)
 *   NTC_Num_CPU_ClockMon (35u)
 *   NTC_Num_CPU_eFuseFlt (36u)
 *   NTC_Num_CPU_MPUViolation (37u)
 *   NTC_Num_CPU_FactPrcsErr (40u)
 *   NTC_Num_PropExeDiag_InitDiag (41u)
 *   NTC_Num_PrgFlwDeadlnFlt (42u)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43u)
 *   NTC_Num_PropExeDiag_COPTimeout (44u)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48u)
 *   NTC_Num_PropExeDiag_DataAbort (49u)
 *   NTC_Num_PerDiag_ADC1Flt (50u)
 *   NTC_Num_PerDiag_ADC2Flt (51u)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52u)
 *   NTC_Num_PerDiag_IllegalAccess (53u)
 *   NTC_Num_PerDiag_DMAFlt (54u)
 *   NTC_Num_PeripheralStartupFlt (55u)
 *   NTC_Num_PerDiag_CPUWarning (63u)
 *   NTC_Num_TmpMonFunc (64u)
 *   NTC_Num_TmpMonRunTimeFlt (65u)
 *   NTC_Num_PowerRelayInitFlt (66u)
 *   NTC_Num_PrechargeFailure (67u)
 *   NTC_Num_PowerRelayRunFlt (68u)
 *   NTC_Num_Thermistor (69u)
 *   NTC_Num_RefSupplyVltg (70u)
 *   NTC_Num_TrcvrInterfaceFlt (71u)
 *   NTC_Num_CPUSupplyOvervoltage (72u)
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73u)
 *   NTC_Num_IvtrPwrDiscnctFailr (74u)
 *   NTC_Num_PowerRelayInit2Flt (75u)
 *   NTC_Num_GateDrvFltInProcess (76u)
 *   NTC_Num_GateDrvFlt (77u)
 *   NTC_Num_OnStateSingleFET (78u)
 *   NTC_Num_OnStateMultiFET (79u)
 *   NTC_Num_PhaseVoltageVerf (80u)
 *   NTC_Num_PhaseDscnt (81u)
 *   NTC_Num_DigPhaseVoltageVerf (82u)
 *   NTC_Num_PhaseDscntFailedDisable (83u)
 *   NTC_Num_CurrentMeas1 (84u)
 *   NTC_Num_CurrentMeas2 (85u)
 *   NTC_Num_CurrentMeasCrossChk (86u)
 *   NTC_Num_PDSupplyOverVoltage (87u)
 *   NTC_Num_ChargePumpUnderVoltage (88u)
 *   NTC_Num_Ivtr2PwrDiscnctFailr (90u)
 *   NTC_Num_Inv2GateDrvFltInProcess (92u)
 *   NTC_Num_Inv2GateDrvFlt (93u)
 *   NTC_Num_Inv2OnStateSingleFET (94u)
 *   NTC_Num_HwTrqSensor (96u)
 *   NTC_Num_AnaVsDigHwTrq (97u)
 *   NTC_Num_TrqSensorRecoveryFlt (98u)
 *   NTC_Num_TrqSensorScaleInvalid (100u)
 *   NTC_Num_T1vsT2 (101u)
 *   NTC_Num_T1OutofRange (102u)
 *   NTC_Num_T2OutofRange (103u)
 *   NTC_Num_DigT1vsT2 (104u)
 *   NTC_Num_DigT1OutofRange (105u)
 *   NTC_Num_DigT2OutofRange (106u)
 *   NTC_Num_RedT1vsT2 (107u)
 *   NTC_Num_HWACrossChecks (108u)
 *   NTC_Num_HWASnsrCommFault (109u)
 *   NTC_Num_HWASensorRel (110u)
 *   NTC_Num_HWASensorAbs (111u)
 *   NTC_Num_PriMSB_SinCosCorr (112u)
 *   NTC_Num_SecMSB_SinCosCorr (113u)
 *   NTC_Num_PriVsSec_SinCosCorr (114u)
 *   NTC_Num_DigMSBFlt (115u)
 *   NTC_Num_MtrVelFlt (116u)
 *   NTC_Num_HWAtoMtrAngleCorr (117u)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118u)
 *   NTC_Num_TurnCntr_PosLoss (128u)
 *   NTC_Num_TurnCntr_MicroProcFlt (129u)
 *   NTC_Num_TurnCntr_SensorPosFlt (130u)
 *   NTC_Num_TurnCntr_SpiComFlt (131u)
 *   NTC_Num_TurnCntr_HighQuiescCur (132u)
 *   NTC_Num_TurnCntr_MainResets (133u)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134u)
 *   NTC_Num_KinematicIntDiag (144u)
 *   NTC_Num_HighFriction (145u)
 *   NTC_Num_DutyCycleExceeded (148u)
 *   NTC_Num_AbsTempThermLimit (149u)
 *   NTC_Num_LatchActive (160u)
 *   NTC_Num_LimpHomeIgnitionCounter (161u)
 *   NTC_Num_OpTrqVsHwTrq (168u)
 *   NTC_Num_CurrentReas (169u)
 *   NTC_Num_LoaRpdShutdn (170u)
 *   NTC_Num_LoaCtrldShutdn (171u)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172u)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173u)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174u)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175u)
 *   NTC_Num_OpVoltage (176u)
 *   NTC_Num_ExVoltageLow (177u)
 *   NTC_Num_ReducedAsstLowVoltage (178u)
 *   NTC_Num_ExVoltageHigh (180u)
 *   NTC_Num_OpVoltageOvrMax (181u)
 *   NTC_Num_BattTransOverVolt (182u)
 *   NTC_Num_IgnConfDiag (184u)
 *   NTC_Num_TurnCntr_LowBattery (185u)
 *   NTC_Num_EEPROMCloseFailed (191u)
 *   NTC_Num_SigPath1CrossChk (192u)
 *   NTC_Num_SigPath2CrossChk (193u)
 *   NTC_Num_SigPath3CrossChk (194u)
 *   NTC_Num_SigPath4CrossChk (195u)
 *   NTC_Num_SigPath5CrossChk (196u)
 *   NTC_Num_DampingFWReached (197u)
 *   NTC_Num_AssistFWReached (198u)
 *   NTC_Num_ReturnFWReached (199u)
 *   NTC_Num_DampingFWFltMode (200u)
 *   NTC_Num_AssistFWFltMode (201u)
 *   NTC_Num_VBICFltMode (202u)
 *   NTC_Num_StaMdsSysC (203u)
 *   NTC_NUM_SysFailureForRotVel (204u)
 *   NTC_NUM_SysFailForRedntRotVel (205u)
 *   NTC_Num_SysFailureForTrqSnsr (206u)
 *   NTC_Num_SysFailureForRedTrqSnsr (207u)
 *   NTC_NUM_SysFailureForCtrlVolt (209u)
 *   NTC_Num_GlblSgnlOvrwrtDet (223u)
 *   NTC_Num_VLF_00 (224u)
 *   NTC_Num_VLF_01 (225u)
 *   NTC_Num_VLF_02 (226u)
 *   NTC_Num_VLF_03 (227u)
 *   NTC_Num_VLF_04 (228u)
 *   NTC_Num_VLF_05 (229u)
 *   NTC_Num_VLF_06 (230u)
 *   NTC_Num_VLF_07 (231u)
 *   NTC_Num_VLF_08 (232u)
 *   NTC_Num_VLF_09 (233u)
 *   NTC_Num_VLF_10 (234u)
 *   NTC_Num_VLF_11 (235u)
 *   NTC_Num_VLF_12 (236u)
 *   NTC_Num_VLF_13 (237u)
 *   NTC_Num_VLF_14 (238u)
 *   NTC_Num_VLF_15 (239u)
 *   NTC_Num_VLF_16 (240u)
 *   NTC_Num_VLF_17 (241u)
 *   NTC_Num_VLF_18 (242u)
 *   NTC_Num_VLF_19 (243u)
 *   NTC_Num_VLF_20 (244u)
 *   NTC_Num_VLF_21 (245u)
 *   NTC_Num_VLF_22 (246u)
 *   NTC_Num_VLF_23 (247u)
 *   NTC_Num_VLF_24 (248u)
 *   NTC_Num_VLF_25 (249u)
 *   NTC_Num_VLF_26 (250u)
 *   NTC_Num_VLF_27 (251u)
 *   NTC_Num_VLF_28 (252u)
 *   NTC_Num_VLF_29 (253u)
 *   NTC_Num_VLF_30 (254u)
 *   NTC_Num_VLF_31 (255u)
 *   NTC_Num_BusOffCh1 (256u)
 *   NTC_Num_BusOffCh1NodeMute (257u)
 *   NTC_Num_Node1AAbsent (258u)
 *   NTC_Num_Node1AFaulty (259u)
 *   NTC_Num_Node1BAbsent (260u)
 *   NTC_Num_Node1BFaulty (261u)
 *   NTC_Num_Node1CAbsent (262u)
 *   NTC_Num_Node1CFaulty (263u)
 *   NTC_Num_Node1DAbsent (264u)
 *   NTC_Num_Node1DFaulty (265u)
 *   NTC_Num_Node1EAbsent (266u)
 *   NTC_Num_Node1EFaulty (267u)
 *   NTC_Num_Node1FAbsent (268u)
 *   NTC_Num_Node1FFaulty (269u)
 *   NTC_Num_Node1GAbsent (270u)
 *   NTC_Num_Node1GFaulty (271u)
 *   NTC_Num_BusOffCh2 (272u)
 *   NTC_Num_Node2AAbsent (273u)
 *   NTC_Num_Node2AFaulty (274u)
 *   NTC_Num_Node2BAbsent (275u)
 *   NTC_Num_Node2BFaulty (276u)
 *   NTC_Num_Node2CAbsent (277u)
 *   NTC_Num_Node2CFaulty (278u)
 *   NTC_Num_Node2DAbsent (279u)
 *   NTC_Num_Node2DFaulty (280u)
 *   NTC_Num_Node2EAbsent (281u)
 *   NTC_Num_Node2EFaulty (282u)
 *   NTC_Num_Node2FAbsent (283u)
 *   NTC_Num_Node2FFaulty (284u)
 *   NTC_Num_Node2GAbsent (285u)
 *   NTC_Num_Node2GFaulty (286u)
 *   NTC_Num_InvalidMsg_M (288u)
 *   NTC_Num_MissingMsg_M (289u)
 *   NTC_Num_CRCFltMsg_M (290u)
 *   NTC_Num_PgrsCntFltMsg_M (291u)
 *   NTC_Num_DataRngFltMsg_M (292u)
 *   NTC_Num_DataRateFltMsg_M (293u)
 *   NTC_Num_DataOtherFltMsg_M (294u)
 *   NTC_Num_DataOther2FltMsg_M (295u)
 *   NTC_Num_InvalidMsg_N (296u)
 *   NTC_Num_MissingMsg_N (297u)
 *   NTC_Num_CRCFltMsg_N (298u)
 *   NTC_Num_PgrsCntFltMsg_N (299u)
 *   NTC_Num_DataRngFltMsg_N (300u)
 *   NTC_Num_DataRateFltMsg_N (301u)
 *   NTC_Num_DataOtherFltMsg_N (302u)
 *   NTC_Num_DataOtherFlt2Msg_N (303u)
 *   NTC_Num_InvalidMsg_O (304u)
 *   NTC_Num_MissingMsg_O (305u)
 *   NTC_Num_CRCFltMsg_O (306u)
 *   NTC_Num_PgrsCntFltMsg_O (307u)
 *   NTC_Num_DataRngFltMsg_O (308u)
 *   NTC_Num_DataRateFltMsg_O (309u)
 *   NTC_Num_DataOtherFltMsg_O (310u)
 *   NTC_Num_InvalidMsg_P (312u)
 *   NTC_Num_MissingMsg_P (313u)
 *   NTC_Num_CRCFltMsg_P (314u)
 *   NTC_Num_PgrsCntFltMsg_P (315u)
 *   NTC_Num_DataRngFltMsg_P (316u)
 *   NTC_Num_DataRateFltMsg_P (317u)
 *   NTC_Num_DataOtherFltMsg_P (318u)
 *   NTC_Num_InvalidMsg_Q (320u)
 *   NTC_Num_MissingMsg_Q (321u)
 *   NTC_Num_CRCFltMsg_Q (322u)
 *   NTC_Num_PgrsCntFltMsg_Q (323u)
 *   NTC_Num_DataRngFltMsg_Q (324u)
 *   NTC_Num_DataRateFltMsg_Q (325u)
 *   NTC_Num_DataOtherFltMsg_Q (326u)
 *   NTC_Num_InvalidMsg_R (328u)
 *   NTC_Num_MissingMsg_R (329u)
 *   NTC_Num_CRCFltMsg_R (330u)
 *   NTC_Num_PgrsCntFltMsg_R (331u)
 *   NTC_Num_DataRngFltMsg_R (332u)
 *   NTC_Num_DataRateFltMsg_R (333u)
 *   NTC_Num_DataOtherFltMsg_R (334u)
 *   NTC_Num_DataOtherFlt2Msg_R (335u)
 *   NTC_Num_InvalidMsg_S (336u)
 *   NTC_Num_MissingMsg_S (337u)
 *   NTC_Num_CRCFltMsg_S (338u)
 *   NTC_Num_PgrsCntFltMsg_S (339u)
 *   NTC_Num_DataRngFltMsg_S (340u)
 *   NTC_Num_DataRateFltMsg_S (341u)
 *   NTC_Num_DataOtherFltMsg_S (342u)
 *   NTC_Num_InvalidMsg_T (344u)
 *   NTC_Num_MissingMsg_T (345u)
 *   NTC_Num_CRCFltMsg_T (346u)
 *   NTC_Num_PgrsCntFltMsg_T (347u)
 *   NTC_Num_DataRngFltMsg_T (348u)
 *   NTC_Num_DataRateFltMsg_T (349u)
 *   NTC_Num_DataOtherFltMsg_T (350u)
 *   NTC_Num_InvalidMsg_U (352u)
 *   NTC_Num_MissingMsg_U (353u)
 *   NTC_Num_CRCFltMsg_U (354u)
 *   NTC_Num_PgrsCntFltMsg_U (355u)
 *   NTC_Num_DataRngFltMsg_U (356u)
 *   NTC_Num_DataRateFltMsg_U (357u)
 *   NTC_Num_DataOtherFltMsg_U (358u)
 *   NTC_Num_InvalidMsg_V (360u)
 *   NTC_Num_MissingMsg_V (361u)
 *   NTC_Num_CRCFltMsg_V (362u)
 *   NTC_Num_PgrsCntFltMsg_V (363u)
 *   NTC_Num_DataRngFltMsg_V (364u)
 *   NTC_Num_DataRateFltMsg_V (365u)
 *   NTC_Num_DataOtherFltMsg_V (366u)
 *   NTC_Num_InvalidMsg_W (368u)
 *   NTC_Num_MissingMsg_W (369u)
 *   NTC_Num_CRCFltMsg_W (370u)
 *   NTC_Num_PgrsCntFltMsg_W (371u)
 *   NTC_Num_DataRngFltMsg_W (372u)
 *   NTC_Num_DataRateFltMsg_W (373u)
 *   NTC_Num_DataOtherFltMsg_W (374u)
 *   NTC_Num_InvalidMsg_X (376u)
 *   NTC_Num_MissingMsg_X (377u)
 *   NTC_Num_CRCFltMsg_X (378u)
 *   NTC_Num_PgrsCntFltMsg_X (379u)
 *   NTC_Num_DataRngFltMsg_X (380u)
 *   NTC_Num_DataRateFltMsg_X (381u)
 *   NTC_Num_DataOtherFltMsg_X (382u)
 *   NTC_Num_InvalidMsg_Y (384u)
 *   NTC_Num_MissingMsg_Y (385u)
 *   NTC_Num_CRCFltMsg_Y (386u)
 *   NTC_Num_PgrsCntFltMsg_Y (387u)
 *   NTC_Num_DataRngFltMsg_Y (388u)
 *   NTC_Num_DataRateFltMsg_Y (389u)
 *   NTC_Num_DataOtherFltMsg_Y (390u)
 *   NTC_Num_InvalidMsg_Z (392u)
 *   NTC_Num_MissingMsg_Z (393u)
 *   NTC_Num_CRCFltMsg_Z (394u)
 *   NTC_Num_PgrsCntFltMsg_Z (395u)
 *   NTC_Num_DataRngFltMsg_Z (396u)
 *   NTC_Num_DataRateFltMsg_Z (397u)
 *   NTC_Num_DataOtherFltMsg_Z (398u)
 *   NTC_Num_DSTXORActive (399u)
 *   NTC_Num_InvalidMsg_AA (400u)
 *   NTC_Num_MissingMsg_AA (401u)
 *   NTC_Num_CRCFltMsg_AA (402u)
 *   NTC_Num_PgrsCntFltMsg_AA (403u)
 *   NTC_Num_DataRngFltMsg_AA (404u)
 *   NTC_Num_DataRateFltMsg_AA (405u)
 *   NTC_Num_DataOtherFltMsg_AA (406u)
 *   NTC_Num_InvalidMsg_AB (408u)
 *   NTC_Num_MissingMsg_AB (409u)
 *   NTC_Num_CRCFltMsg_AB (410u)
 *   NTC_Num_PgrsCntFltMsg_AB (411u)
 *   NTC_Num_DataRngFltMsg_AB (412u)
 *   NTC_Num_DataRateFltMsg_AB (413u)
 *   NTC_Num_DataOtherFltMsg_AB (414u)
 *   NTC_Num_InvalidMsg_AC (416u)
 *   NTC_Num_MissingMsg_AC (417u)
 *   NTC_Num_CRCFltMsg_AC (418u)
 *   NTC_Num_PgrsCntFltMsg_AC (419u)
 *   NTC_Num_DataRngFltMsg_AC (420u)
 *   NTC_Num_DataRateFltMsg_AC (421u)
 *   NTC_Num_DataOtherFltMsg_AC (422u)
 *   NTC_Num_InvalidMsg_AD (424u)
 *   NTC_Num_MissingMsg_AD (425u)
 *   NTC_Num_CRCFltMsg_AD (426u)
 *   NTC_Num_PgrsCntFltMsg_AD (427u)
 *   NTC_Num_DataRngFltMsg_AD (428u)
 *   NTC_Num_DataRateFltMsg_AD (429u)
 *   NTC_Num_DataOtherFltMsg_AD (430u)
 *   NTC_Num_InvalidMsg_AE (432u)
 *   NTC_Num_MissingMsg_AE (433u)
 *   NTC_Num_CRCFltMsg_AE (434u)
 *   NTC_Num_PgrsCntFltMsg_AE (435u)
 *   NTC_Num_DataRngFltMsg_AE (436u)
 *   NTC_Num_DataRateFltMsg_AE (437u)
 *   NTC_Num_DataOtherFltMsg_AE (438u)
 *   NTC_Num_InvalidMsg_AF (440u)
 *   NTC_Num_MissingMsg_AF (441u)
 *   NTC_Num_CRCFltMsg_AF (442u)
 *   NTC_Num_PgrsCntFltMsg_AF (443u)
 *   NTC_Num_DataRngFltMsg_AF (444u)
 *   NTC_Num_DataRateFltMsg_AF (445u)
 *   NTC_Num_DataOtherFltMsg_AF (446u)
 *   NTC_Num_InvalidMsg_AG (448u)
 *   NTC_Num_MissingMsg_AG (449u)
 *   NTC_Num_CRCFltMsg_AG (450u)
 *   NTC_Num_PgrsCntFltMsg_AG (451u)
 *   NTC_Num_DataRngFltMsg_AG (452u)
 *   NTC_Num_DataRateFltMsg_AG (453u)
 *   NTC_Num_DataOtherFltMsg_AG (454u)
 *   NTC_Num_InvalidMsg_AH (456u)
 *   NTC_Num_MissingMsg_AH (457u)
 *   NTC_Num_CRCFltMsg_AH (458u)
 *   NTC_Num_PgrsCntFltMsg_AH (459u)
 *   NTC_Num_DataRngFltMsg_AH (460u)
 *   NTC_Num_DataRateFltMsg_AH (461u)
 *   NTC_Num_DataOtherFltMsg_AH (462u)
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464u)
 *   NTC_Num_FlexrayCommunicationError (465u)
 *   NTC_Num_InvalidMsg_AI (466u)
 *   NTC_Num_MissingMsg_AI (467u)
 *   NTC_Num_InvalidMsg_AJ (472u)
 *   NTC_Num_MissingMsg_AJ (473u)
 *   NTC_Num_InvalidMsg_AK (480u)
 *   NTC_Num_MissingMsg_AK (481u)
 *   NTC_Num_MissingMsg_AL (489u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_TunSetNotPrgmd (499u)
 *   NTC_Num_EEPROMtoFeeCpyError (500u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_HWASensorNotTrimmed (504u)
 *   NTC_Num_HWASensorTrimNoAttempt (505u)
 *   NTC_Num_TrqSensorScaleNotSet (506u)
 *   NTC_Num_TrqSensorNotTrimmed (507u)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508u)
 *   NTC_Num_DigTrqSensorScaleNotSet (509u)
 *   NTC_Num_DigTrqSensorNotTrimmed (510u)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511u)
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0u)
 *   NVM_REQ_NOT_OK (1u)
 *   NVM_REQ_PENDING (2u)
 *   NVM_REQ_INTEGRITY_FAILED (3u)
 *   NVM_REQ_BLOCK_SKIPPED (4u)
 *   NVM_REQ_NV_INVALIDATED (5u)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
 *
 * Array Types:
 * ============
 * CustDataType: Array with 6 element(s) of type UInt32
 * CustReadCmplType: Array with 6 element(s) of type Boolean
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * DigColPsEOLType: Record with elements
 *   ColTrim_Deg_f32 of type Float
 *   R_ColTrim_Cnt_u32 of type UInt32
 *   SpurTrim_Deg_f32 of type Float
 *   R_SpurTrim_Cnt_u32 of type UInt32
 *   TrimComp_Cnt_u16 of type UInt16
 *   R_TrimCom_Cnt_u16 of type UInt16
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   DigColPsEOLType *Rte_Pim_DigColPsEOL(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_DIGCOLPS_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigColPs_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLDigColPosCals_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_EOLDigColPosCals_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DigColPs_Init1
 *********************************************************************************************************************/

	/* Lpf Init */
	LPF_KUpdate_f32_m(k_ColAngSenseLPFFc_Hz_f32, D_2MS_SEC_F32, &DigColPs_ColAngleLPFKSV_Cnt_M_str);
	LPF_KUpdate_f32_m(k_SpurAngSenseLPFFc_Hz_f32, D_2MS_SEC_F32, &DigColPs_SpurAngleLPFKSV_Cnt_M_str);

	DigColPsInt_Init();

	/* Trim Check */
	/* Check NvM data against redundant copies */
	if ((Redundant_Format_1_m(*(uint32*)&Rte_Pim_DigColPsEOL()->ColTrim_Deg_f32) != Rte_Pim_DigColPsEOL()->R_ColTrim_Cnt_u32) ||
		(Redundant_Format_1_m(*(uint32*)&Rte_Pim_DigColPsEOL()->SpurTrim_Deg_f32) != Rte_Pim_DigColPsEOL()->R_SpurTrim_Cnt_u32) ||
		((uint16)Redundant_Format_1_m(Rte_Pim_DigColPsEOL()->TrimComp_Cnt_u16) != Rte_Pim_DigColPsEOL()->R_TrimCom_Cnt_u16))
	{
		/* Clear trims if data did not match redundant copy bit-for-bit */
		Rte_Pim_DigColPsEOL()->ColTrim_Deg_f32 = 0.0f;
		Rte_Pim_DigColPsEOL()->SpurTrim_Deg_f32 = 0.0f;
		Rte_Pim_DigColPsEOL()->TrimComp_Cnt_u16 = D_TRIMNOTCOMPLETE_CNT_U16;
		Rte_Pim_DigColPsEOL()->R_ColTrim_Cnt_u32 = Redundant_Format_1_m((uint32)0U);
		Rte_Pim_DigColPsEOL()->R_SpurTrim_Cnt_u32 = Redundant_Format_1_m((uint32)0U);
		Rte_Pim_DigColPsEOL()->R_TrimCom_Cnt_u16 = (uint16)Redundant_Format_1_m(D_TRIMNOTCOMPLETE_CNT_U16);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorNotTrimmed, 2U, NTC_STATUS_FAILED);
	}
	else if (Rte_Pim_DigColPsEOL()->TrimComp_Cnt_u16 == D_TRIMNOTCOMPLETE_CNT_U16)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorNotTrimmed, 1U, NTC_STATUS_FAILED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorNotTrimmed, 0U, NTC_STATUS_PASSED);
	}

	/* Trim Static Init */
	DigColPs_ColTrimStatic_Deg_M_f32 = 0.0f;
	DigColPs_SpurTrimStatic_Deg_M_f32 = 0.0f;
	DigColPs_TrimCompStatic_Cnt_M_u16 = D_TRIMNOTCOMPLETE_CNT_U16;

	/* Snsr ReInit MaxTry */
	DigColPs_SnsrReInitInProgs_Cnt_M_lgc = FALSE;
	DigColPs_SnsrReInitMaxTryCntr_Cnt_M_u08 = k_ReInitMaxTryCntr_Cnt_u08;
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DigColPs_SnsrReInitTmr_mS_M_u32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigColPs_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DigColPs_Per1
 *********************************************************************************************************************/

	/*** Temporary Variables ***/
	/* Inputs */
	VAR(uint16, AUTOMATIC) I2CHwColAngle_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) I2CHwSpurAngle_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) I2CHwDataType_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) I2CSensCommFlts_Cnt_T_u08;

	/* Angle Mask & Parity Check, Column Sensor Variables */
	VAR(boolean, AUTOMATIC) ColParityFault_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ColRegisterFaultCnt_T_lgc;
	VAR(boolean, AUTOMATIC) SpurRegisterFaultCnt_T_lgc;
	VAR(boolean, AUTOMATIC) SpurParityFault_Cnt_T_lgc;

	VAR(boolean, AUTOMATIC) ColSensorFault_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SpurSensorFault_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ColSnsrErr_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SpurSnsrErr_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SnsrSampleOK_Cnt_T_lgc;

	/* Angle: Limit & Trim Column */
	VAR(float32, AUTOMATIC) ColDelta_Deg_T_f32;
	VAR(float32, AUTOMATIC) SpurDelta_Deg_T_f32;
	VAR(float32, AUTOMATIC) I2CHwColAngle_Deg_T_f32;
	VAR(float32, AUTOMATIC) I2CHwSpurAngle_Deg_T_f32;

	/* Check Re Init Maxtry */
	if(DigColPs_SnsrReInitInProgs_Cnt_M_lgc == TRUE)
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DigColPs_SnsrReInitTmr_mS_M_u32,&DigColPs_SnsrReInitElapsedTime_mS_M_u16);
		if(DigColPs_SnsrReInitElapsedTime_mS_M_u16 >= D_SNSRREINITTIME_MS_U32)
		{
			DigColPs_SnsrReInitInProgs_Cnt_M_lgc = FALSE;
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DigColPs_SnsrReInitTmr_mS_M_u32);
		}
	}

	/* Protocol Check */
	if(DigColPs_SnsrReInitInProgs_Cnt_M_lgc == FALSE)
	{
		DisableI2CInterrupt();
		DigColPs_I2CSensCommFlts_Cnt_M_u08 = DigColPsInt_GetData(&DigColPs_I2CHwColAngle_Cnt_M_u16, &DigColPs_I2CHwSpurAngle_Cnt_M_u16, &DigColPs_I2CHwDataType_Cnt_M_u08);
		EnableI2CInterrupt();

		I2CHwColAngle_Cnt_T_u16 = DigColPs_I2CHwColAngle_Cnt_M_u16;
		I2CHwSpurAngle_Cnt_T_u16 = DigColPs_I2CHwSpurAngle_Cnt_M_u16;
		I2CHwDataType_Cnt_T_u08 = DigColPs_I2CHwDataType_Cnt_M_u08;
		I2CSensCommFlts_Cnt_T_u08 = DigColPs_I2CSensCommFlts_Cnt_M_u08;

		ColSensorFault_Cnt_T_lgc = FALSE;
		SpurSensorFault_Cnt_T_lgc = FALSE;
		ColRegisterFaultCnt_T_lgc = FALSE;
		SpurRegisterFaultCnt_T_lgc = FALSE;

		/* -----[ Angle Mask & Parity Check of Sensor Data ]------------------------------------------------------------- */
		if (I2CHwDataType_Cnt_T_u08 != D_ANGLEDATA_CNT_U08)
		{
			I2CHwColAngle_Cnt_T_u16 = D_ANGLEZEROODDPARITY_CNT_U16;
			I2CHwSpurAngle_Cnt_T_u16 = D_ANGLEZEROODDPARITY_CNT_U16;
		}

		I2CSnsrDataCheck(I2CHwColAngle_Cnt_T_u16,
						I2CHwSpurAngle_Cnt_T_u16,
						&ColSensorFault_Cnt_T_lgc,
						&SpurSensorFault_Cnt_T_lgc,
						&ColRegisterFaultCnt_T_lgc,
						&SpurRegisterFaultCnt_T_lgc);

		/* Check for Odd Parity */
		ColParityFault_Cnt_T_lgc = OddParityFault(I2CHwColAngle_Cnt_T_u16);
		SpurParityFault_Cnt_T_lgc = OddParityFault(I2CHwSpurAngle_Cnt_T_u16);

		ColSnsrErr_Cnt_T_lgc = ColRegisterFaultCnt_T_lgc | ColParityFault_Cnt_T_lgc | ColSensorFault_Cnt_T_lgc;
		SpurSnsrErr_Cnt_T_lgc = SpurRegisterFaultCnt_T_lgc | SpurParityFault_Cnt_T_lgc | SpurSensorFault_Cnt_T_lgc;

		I2CSensCommFlts_Cnt_T_u08 |= ColSnsrErr_Cnt_T_lgc;
		I2CSensCommFlts_Cnt_T_u08 |=  ((uint8)(SpurSnsrErr_Cnt_T_lgc << 6U));

		/* Mask off parity bit */
		I2CHwColAngle_Cnt_T_u16 &= D_ANGLEMASK_CNT_U16;
		I2CHwSpurAngle_Cnt_T_u16 &= D_ANGLEMASK_CNT_U16;

		/* Max Try Logic */
		I2CHwDataType_Cnt_T_u08 = I2CSnsrReInitMaxTry(I2CSensCommFlts_Cnt_T_u08,ColSensorFault_Cnt_T_lgc,SpurSensorFault_Cnt_T_lgc);

		/* I2C Communication Fault Diagnostic - NTC 0x06D */
		I2CCommFltDiag(I2CSensCommFlts_Cnt_T_u08);

		/* Sample Ok Logic & Max Re try Step Up */
		if((I2CSensCommFlts_Cnt_T_u08 == 0U) &&
		   (DigColPs_SnsrReInitInProgs_Cnt_M_lgc == FALSE) &&
		   (I2CHwDataType_Cnt_T_u08 == D_ANGLEDATA_CNT_U08))
		{
			SnsrSampleOK_Cnt_T_lgc = TRUE;
			if(DigColPs_SnsrReInitMaxTryCntr_Cnt_M_u08 < k_ReInitMaxTryCntr_Cnt_u08)
			{
				/* Max Try Increment */
				DigColPs_SnsrReInitMaxTryCntr_Cnt_M_u08++;
			}
		}
		else
		{
			SnsrSampleOK_Cnt_T_lgc = FALSE;
		}

		if(SnsrSampleOK_Cnt_T_lgc == TRUE)
		{
			/* -----[ Angle: Scale, Limit, LPF ]----------------------------------------------------------------------------- */
			/* Scale 12 bit counts to 0-360 degrees */
			I2CHwColAngle_Deg_T_f32 = FPM_FixedToFloat_m(I2CHwColAngle_Cnt_T_u16, u4p12_T) * D_ONEREV_DEGREESPREV_F32;
			I2CHwSpurAngle_Deg_T_f32 = FPM_FixedToFloat_m(I2CHwSpurAngle_Cnt_T_u16, u4p12_T) * D_ONEREV_DEGREESPREV_F32;

			/* Compute Rough Turns */
			ColDelta_Deg_T_f32 = I2CHwColAngle_Deg_T_f32 - DigColPs_PrevI2CHwColAngle_Deg_M_f32;
			SpurDelta_Deg_T_f32 = I2CHwSpurAngle_Deg_T_f32 - DigColPs_PrevI2CHwSpurAngle_Deg_M_f32;
			DigColPs_PrevI2CHwColAngle_Deg_M_f32 = I2CHwColAngle_Deg_T_f32;
			DigColPs_PrevI2CHwSpurAngle_Deg_M_f32 = I2CHwSpurAngle_Deg_T_f32;
			I2CHwColAngle_Deg_T_f32 += ComputeRoughTurns(ColDelta_Deg_T_f32, &DigColPs_ColRoughTurns_Cnt_M_s16);
			I2CHwSpurAngle_Deg_T_f32 += ComputeRoughTurns(SpurDelta_Deg_T_f32, &DigColPs_SpurRoughTurns_Cnt_M_s16);

			/* Update Display Variables */
			DigColPs_ColAngle_Deg_D_f32 = I2CHwColAngle_Deg_T_f32;
			DigColPs_SpurAngle_Deg_D_f32 = I2CHwSpurAngle_Deg_T_f32;

			if (DigColPs_ColLPFInitDone_Cnt_M_lgc == FALSE)
			{
				DigColPs_ColAngleLPFKSV_Cnt_M_str.SV_Uls_f32 = I2CHwColAngle_Deg_T_f32;
				DigColPs_ColLPFInitDone_Cnt_M_lgc = TRUE;
			}

			if (DigColPs_SpurLPFInitDone_Cnt_M_lgc == FALSE)
			{
				DigColPs_SpurAngleLPFKSV_Cnt_M_str.SV_Uls_f32 = I2CHwSpurAngle_Deg_T_f32;
				DigColPs_SpurLPFInitDone_Cnt_M_lgc = TRUE;
			}

			/* Low-Pass Filter */
			I2CHwColAngle_Deg_T_f32 = LPF_OpUpdate_f32_m(I2CHwColAngle_Deg_T_f32, &DigColPs_ColAngleLPFKSV_Cnt_M_str);
			I2CHwSpurAngle_Deg_T_f32 = LPF_OpUpdate_f32_m(I2CHwSpurAngle_Deg_T_f32, &DigColPs_SpurAngleLPFKSV_Cnt_M_str);
			I2CHwColAngle_Deg_T_f32 = ConstrainOneRev(I2CHwColAngle_Deg_T_f32);
			I2CHwSpurAngle_Deg_T_f32 = ConstrainOneRev(I2CHwSpurAngle_Deg_T_f32);

			DigColPs_I2CHwColAngle_Deg_M_f32 = I2CHwColAngle_Deg_T_f32;
			DigColPs_I2CHwSpurAngle_Deg_M_f32 = I2CHwSpurAngle_Deg_T_f32;
		}

		/* Copy Temporary outputs to module level variables for sharing with 4ms periodic */
		DigColPs_I2CHwDataTypeMdfy_Cnt_M_u08 = I2CHwDataType_Cnt_T_u08;
		DigColPs_I2CSensCommFltsMdfy_Cnt_M_u08 = I2CSensCommFlts_Cnt_T_u08;
		DigColPs_ColSnsrErr_Cnt_M_lgc = ColSnsrErr_Cnt_T_lgc;
		DigColPs_SpurSnsrErr_Cnt_M_lgc = SpurSnsrErr_Cnt_T_lgc;
		DigColPs_SnsrSampleOk_Cnt_M_lgc = SnsrSampleOK_Cnt_T_lgc;

		/* Request start next I2C transfer */
		DigColPsInt_StartRequest(DigColPs_ReqI2CSnsrDataType_Cnt_M_u08);
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigColPs_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   ManufModeType Rte_IRead_DigColPs_Per2_MecState_Cnt_enum(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_DigColPs_Per2_I2CHwAbsPosValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_DigColPs_Per2_I2CHwAbsPosValid_Cnt_lgc(void)
 *   void Rte_IWrite_DigColPs_Per2_I2CHwAbsPos_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_DigColPs_Per2_I2CHwAbsPos_HwDeg_f32(void)
 *   void Rte_IWrite_DigColPs_Per2_TrimComp_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_DigColPs_Per2_TrimComp_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DigColPs_Per2
 *********************************************************************************************************************/

	/*** Temporary Variables ***/
	/* Inputs */
	VAR(boolean, AUTOMATIC) ColSnsrErr_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SpurSnsrErr_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SnsrSampleOk_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) I2CHwColAngle_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) I2CHwSpurAngle_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) I2CHwDataType_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) I2CSensCommFlts_Cnt_T_u08;
	VAR(float32, AUTOMATIC) I2CHwColAngle_Deg_T_f32;
	VAR(float32, AUTOMATIC) I2CHwSpurAngle_Deg_T_f32;

	/* Apply Trim */
	VAR(float32, AUTOMATIC) I2CHwColAngleTrim_Deg_T_f32;
	VAR(float32, AUTOMATIC) I2CHwSpurAngleTrim_Deg_T_f32;

	/* Vernier Level & Revolution Calc */
	VAR(float32, AUTOMATIC) VernierLevel_Deg_T_f32;
	VAR(uint8, AUTOMATIC) ColRev_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) SpurRev_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) VernierLevelNo_Cnt_T_u08;

	/* Calc Abs Angles */
	VAR(float32, AUTOMATIC) ColPos_Deg_T_f32;
	VAR(float32, AUTOMATIC) SpurPos_Deg_T_f32;

	/* Vernier Diagnostic */
	VAR(boolean, AUTOMATIC) VernCorrDetect_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) AbsVernLevelDiff_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) SkipStepFltDetect_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) AbsColPosDiff_Deg_T_f32;
	VAR(float32, AUTOMATIC) VernDiagError_Deg_T_f32;

	/* Module Outputs */
	VAR(float32, AUTOMATIC) I2CAbsHwPos_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC) TrimComplete_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) I2CHwPosValid_Cnt_T_lgc;

	VAR(ManufModeType, AUTOMATIC) MecState_Cnt_T_enum;

	/* Read RTE Inputs */
	MecState_Cnt_T_enum = Rte_IRead_DigColPs_Per2_MecState_Cnt_enum();

	/* Stop Interrupts during read of inputs from Per1 for consistency */
	(void)GetResource(RES_SCHEDULER);
	ColSnsrErr_Cnt_T_lgc = DigColPs_ColSnsrErr_Cnt_M_lgc;
	SpurSnsrErr_Cnt_T_lgc = DigColPs_SpurSnsrErr_Cnt_M_lgc;
	I2CHwColAngle_Cnt_T_u16 = DigColPs_I2CHwColAngle_Cnt_M_u16;
	I2CHwSpurAngle_Cnt_T_u16 = DigColPs_I2CHwSpurAngle_Cnt_M_u16;
	I2CHwColAngle_Deg_T_f32 = DigColPs_I2CHwColAngle_Deg_M_f32;
	I2CHwSpurAngle_Deg_T_f32 = DigColPs_I2CHwSpurAngle_Deg_M_f32;
	I2CHwDataType_Cnt_T_u08 = DigColPs_I2CHwDataTypeMdfy_Cnt_M_u08;
	I2CSensCommFlts_Cnt_T_u08 = DigColPs_I2CSensCommFltsMdfy_Cnt_M_u08;
	SnsrSampleOk_Cnt_T_lgc = DigColPs_SnsrSampleOk_Cnt_M_lgc;
	(void)ReleaseResource(RES_SCHEDULER);

	if(DigColPs_SnsrReInitInProgs_Cnt_M_lgc == FALSE)
	{
		if(SnsrSampleOk_Cnt_T_lgc == TRUE)
		{
			/* -----[ Apply Trims ]------------------------------------------------------------------------------------------ */
			if (Rte_Pim_DigColPsEOL()->TrimComp_Cnt_u16 == D_TRIMCOMPLETE_CNT_U16)
			{
				I2CHwColAngleTrim_Deg_T_f32 = I2CHwColAngle_Deg_T_f32 - Rte_Pim_DigColPsEOL()->ColTrim_Deg_f32;
				I2CHwSpurAngleTrim_Deg_T_f32 = I2CHwSpurAngle_Deg_T_f32 - Rte_Pim_DigColPsEOL()->SpurTrim_Deg_f32;
				I2CHwColAngleTrim_Deg_T_f32 = ConstrainOneRev(I2CHwColAngleTrim_Deg_T_f32);
				I2CHwSpurAngleTrim_Deg_T_f32 = ConstrainOneRev(I2CHwSpurAngleTrim_Deg_T_f32);
			}
			else
			{
				I2CHwColAngleTrim_Deg_T_f32 = I2CHwColAngle_Deg_T_f32 - DigColPs_ColTrimStatic_Deg_M_f32;
				I2CHwSpurAngleTrim_Deg_T_f32 = I2CHwSpurAngle_Deg_T_f32 - DigColPs_SpurTrimStatic_Deg_M_f32;
				I2CHwColAngleTrim_Deg_T_f32 = ConstrainOneRev(I2CHwColAngleTrim_Deg_T_f32);
				I2CHwSpurAngleTrim_Deg_T_f32 = ConstrainOneRev(I2CHwSpurAngleTrim_Deg_T_f32);
			}

			DigColPs_I2CHwColAngleTrim_Deg_D_f32 =  I2CHwColAngleTrim_Deg_T_f32;
			DigColPs_I2CHwSpurAngleTrim_Deg_D_f32 = I2CHwSpurAngleTrim_Deg_T_f32;

			/* -----[ Vernier Level & Revolution Calc ]---------------------------------------------------------------------- */
			/* Dual Spur Sensor Design */
			VernierLevel_Deg_T_f32 = (I2CHwSpurAngleTrim_Deg_T_f32) - (I2CHwColAngleTrim_Deg_T_f32 * D_I2HW11TO10TRATIO_ULS_F32) ;
			VernierLookup(
				(sint16*)T2_DualSpurVernierLUT_Cnt_s16,
				D_DUALSPURTBLXSIZE_CNT_U08,
				VernierLevel_Deg_T_f32,
				&ColRev_Cnt_T_u08,
				&SpurRev_Cnt_T_u08,
				&VernierLevelNo_Cnt_T_u08
			);
			DigColPs_VernierLevel_Deg_D_f32 = VernierLevel_Deg_T_f32;

			/* -----[ Calc Abs Angles ]-------------------------------------------------------------------------------------- */
			ColPos_Deg_T_f32 = (((float32)ColRev_Cnt_T_u08 * D_ONEREV_DEGREESPREV_F32) + I2CHwColAngleTrim_Deg_T_f32)* D_INVDUALSPURRATIO_ULS_F32;
			SpurPos_Deg_T_f32 = (((float32)SpurRev_Cnt_T_u08 * D_ONEREV_DEGREESPREV_F32) + I2CHwSpurAngleTrim_Deg_T_f32) * D_INVSPURRATIO_ULS_F32;

			DigColPs_I2CHWSpurPos_HwDeg_D_f32 = SpurPos_Deg_T_f32;

			/* -----[ Vernier Diagnostic ]----------------------------------------------------------------------------------- */
			TrimComplete_Cnt_T_lgc = FALSE;

			if ((Rte_Pim_DigColPsEOL()->TrimComp_Cnt_u16 == D_TRIMCOMPLETE_CNT_U16) ||
				(DigColPs_TrimCompStatic_Cnt_M_u16 == D_TRIMCOMPLETE_CNT_U16))
			{
				TrimComplete_Cnt_T_lgc = TRUE;
			}

			/* Check Vernier Correlation Error */
			VernDiagError_Deg_T_f32 = ColPos_Deg_T_f32 - SpurPos_Deg_T_f32;
			DigColPs_VernDiagError_Deg_D_f32 = VernDiagError_Deg_T_f32;
			VernCorrDetect_Cnt_T_lgc = ChkVernCorrlnError(VernierLevelNo_Cnt_T_u08,VernDiagError_Deg_T_f32,TrimComplete_Cnt_T_lgc);

			/* Check Skip Step Error */
			AbsVernLevelDiff_Cnt_T_u08 = (uint8)Abs_s16_m((sint16)VernierLevelNo_Cnt_T_u08 - (sint16)DigColPs_PrevVernierLevelNo_Cnt_M_u08);
			SkipStepFltDetect_Cnt_T_lgc = ChkSkipStepError(AbsVernLevelDiff_Cnt_T_u08,TrimComplete_Cnt_T_lgc);

			/* Vernier Out of Range Error */
			AbsColPosDiff_Deg_T_f32 = Abs_f32_m(ColPos_Deg_T_f32 - DigColPs_PrevColPos_Deg_M_f32);
			if ((AbsColPosDiff_Deg_T_f32 > k_VernOORangeThresh_Deg_f32) &&
				(TrimComplete_Cnt_T_lgc == TRUE) &&
				(DigColPs_PrevAngleDataAvailable_Cnt_M_lgc == TRUE) &&
				(MecState_Cnt_T_enum != ManufacturingMode))
			{
				/* will "latch" for this ignition cycle by never being cleared to false */
				DigColPs_VernierAngleOORange_Cnt_M_lgc = TRUE;
			}

			/* Vernier Correlation Fault Diagnostic - NTC 0x06C */
			VernCorrlnFltDiag(VernCorrDetect_Cnt_T_lgc,SkipStepFltDetect_Cnt_T_lgc);

			/* -----[ Form Abs Position & Position Valid ]------------------------------------------------------------------- */
			I2CHwPosValid_Cnt_T_lgc = FALSE;

			if ((TrimComplete_Cnt_T_lgc == TRUE) && (DigColPs_HwAVernCorrFault_Cnt_M_lgc == FALSE))
			{
				I2CHwPosValid_Cnt_T_lgc = TRUE;
			}

			if (k_SelectFromColumn_Cnt_lgc == TRUE)
			{
				I2CAbsHwPos_HwDeg_T_f32 = ColPos_Deg_T_f32;
			}
			else
			{
				I2CAbsHwPos_HwDeg_T_f32 = SpurPos_Deg_T_f32;
				DigColPs_I2CHwColAngleForTrim_Deg_M_f32 = SpurPos_Deg_T_f32;
			}

			I2CAbsHwPos_HwDeg_T_f32 -= D_VERNIERANGLECENTEROFF_DEG_F32;

			/* Update "previous" values */
			DigColPs_PrevColPos_Deg_M_f32 = ColPos_Deg_T_f32;
			DigColPs_PrevI2CAbsHwPos_HwDeg_M_f32 = I2CAbsHwPos_HwDeg_T_f32;
			DigColPs_PrevVernierLevelNo_Cnt_M_u08 = VernierLevelNo_Cnt_T_u08;
			DigColPs_PrevTrimComplete_Cnt_M_lgc = TrimComplete_Cnt_T_lgc;
		}
		else
		{
			I2CAbsHwPos_HwDeg_T_f32 = DigColPs_PrevI2CAbsHwPos_HwDeg_M_f32;
			I2CHwPosValid_Cnt_T_lgc = FALSE;
			TrimComplete_Cnt_T_lgc = DigColPs_PrevTrimComplete_Cnt_M_lgc;
		}

		DigColPs_PrevI2CHwPosValid_Cnt_M_lgc = I2CHwPosValid_Cnt_T_lgc;

		/* -----[ Get Sensor Fault Parameter Data ]---------------------------------------------------------------------- */
		SnsrFltDiag(I2CHwColAngle_Cnt_T_u16,I2CHwSpurAngle_Cnt_T_u16,I2CHwDataType_Cnt_T_u08,I2CSensCommFlts_Cnt_T_u08,ColSnsrErr_Cnt_T_lgc,SpurSnsrErr_Cnt_T_lgc);
	}
	else
	{
		I2CAbsHwPos_HwDeg_T_f32 = DigColPs_PrevI2CAbsHwPos_HwDeg_M_f32;
		I2CHwPosValid_Cnt_T_lgc = DigColPs_PrevI2CHwPosValid_Cnt_M_lgc;
		TrimComplete_Cnt_T_lgc = DigColPs_PrevTrimComplete_Cnt_M_lgc;
	}

	I2CAbsHwPos_HwDeg_T_f32 = Limit_m(I2CAbsHwPos_HwDeg_T_f32, -D_MAXHWPOS_HWDEG_F32, D_MAXHWPOS_HWDEG_F32);

	/* Write local copies to module outputs */
	Rte_IWrite_DigColPs_Per2_I2CHwAbsPosValid_Cnt_lgc(I2CHwPosValid_Cnt_T_lgc);
	Rte_IWrite_DigColPs_Per2_I2CHwAbsPos_HwDeg_f32(I2CAbsHwPos_HwDeg_T_f32);
	Rte_IWrite_DigColPs_Per2_TrimComp_Cnt_lgc(TrimComplete_Cnt_T_lgc);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigColPs_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_Per3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DigColPs_Per3
 *********************************************************************************************************************/
	if (Rte_Pim_DigColPsEOL()->TrimComp_Cnt_u16 != D_TRIMCOMPLETE_CNT_U16)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorNotTrimmed, 1U, NTC_STATUS_FAILED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorNotTrimmed, 0U, NTC_STATUS_PASSED);
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigColPs_SCom_CustClrTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CustClearTrim> of PortPrototype <DigColPs_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLDigColPosCals_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_EOLDigColPosCals_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DigColPs_SCom_CustClrTrim(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_SCom_CustClrTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DigColPs_SCom_CustClrTrim
 *********************************************************************************************************************/

	Rte_Pim_DigColPsEOL()->ColTrim_Deg_f32 = 0.0f;
	Rte_Pim_DigColPsEOL()->SpurTrim_Deg_f32 = 0.0f;
	Rte_Pim_DigColPsEOL()->TrimComp_Cnt_u16 = D_TRIMNOTCOMPLETE_CNT_U16;
	Rte_Pim_DigColPsEOL()->R_ColTrim_Cnt_u32 = Redundant_Format_1_m((uint32)0U);
	Rte_Pim_DigColPsEOL()->R_SpurTrim_Cnt_u32 = Redundant_Format_1_m((uint32)0U);
	Rte_Pim_DigColPsEOL()->R_TrimCom_Cnt_u16 = (uint16)Redundant_Format_1_m(D_TRIMNOTCOMPLETE_CNT_U16);
	(void)Rte_Call_EOLDigColPosCals_WriteBlock(NULL_PTR);

	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorNotTrimmed, 1U, NTC_STATUS_FAILED);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigColPs_SCom_CustSetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CustSetTrim> of PortPrototype <DigColPs_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_EOLDigColPosCals_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_EOLDigColPosCals_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DigColPs_SCom_CustSetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DigColPs_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_SCom_CustSetTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DigColPs_SCom_CustSetTrim (returns application error)
 *********************************************************************************************************************/

	VAR(boolean, AUTOMATIC) I2CColSensorFault_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) I2CSpurSensorFault_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) I2CHwColAngle_Deg_T_f32;
	VAR(float32, AUTOMATIC) I2CHwSpurAngle_Deg_T_f32;
	VAR(Std_ReturnType, AUTOMATIC) RetCode_Cnt_T_u08;
	VAR(float32, AUTOMATIC) I2CHwColAngleForTrim_Deg_T_f32;
	VAR(float32, AUTOMATIC) I2CHwTrimColOffset_Deg_T_f32;
	VAR(float32, AUTOMATIC) Snsr1Trimoffset_Deg_T_f32;
	VAR(float32, AUTOMATIC) Snsr2Trimoffset_Deg_T_f32;
	
	RetCode_Cnt_T_u08 = RTE_E_DigColPs_SCom_ConditionsNotCorrect;

	/* Disable interrupts for data consistency while reading inputs */
	(void)GetResource(RES_SCHEDULER);
	I2CColSensorFault_Cnt_T_lgc = DigColPs_ColSnsrErr_Cnt_M_lgc;
	I2CSpurSensorFault_Cnt_T_lgc = DigColPs_SpurSnsrErr_Cnt_M_lgc;
	I2CHwColAngleForTrim_Deg_T_f32 = DigColPs_I2CHwColAngleForTrim_Deg_M_f32;
	(void)ReleaseResource(RES_SCHEDULER);

	if ((I2CColSensorFault_Cnt_T_lgc == FALSE) && (I2CSpurSensorFault_Cnt_T_lgc == FALSE)  &&
		(DigColPs_TrimCompStatic_Cnt_M_u16 != D_TRIMCOMPLETE_CNT_U16) &&
		(Rte_Pim_DigColPsEOL()->TrimComp_Cnt_u16 != D_TRIMCOMPLETE_CNT_U16))
	{
		I2CHwTrimColOffset_Deg_T_f32 = I2CHwColAngleForTrim_Deg_T_f32 - D_VERNIERANGLECENTEROFF_DEG_F32;
		Snsr1Trimoffset_Deg_T_f32 = I2CHwTrimColOffset_Deg_T_f32 * D_DUALSPURRATIO_ULS_F32 ;
		Snsr2Trimoffset_Deg_T_f32 = I2CHwTrimColOffset_Deg_T_f32 * D_SPURRATIO_ULS_F32;

		if (I2CHwTrimColOffset_Deg_T_f32 >= 0.0f)
		{
			I2CHwColAngle_Deg_T_f32 = ConstrainOneRev(Snsr1Trimoffset_Deg_T_f32) - D_ONEREV_DEGREESPREV_F32;
			I2CHwSpurAngle_Deg_T_f32 = ConstrainOneRev(Snsr2Trimoffset_Deg_T_f32) - D_ONEREV_DEGREESPREV_F32;
		}
		else
		{
			I2CHwColAngle_Deg_T_f32 = ConstrainOneRev(Snsr1Trimoffset_Deg_T_f32);
			I2CHwSpurAngle_Deg_T_f32 = ConstrainOneRev(Snsr2Trimoffset_Deg_T_f32);
		}

		Rte_Pim_DigColPsEOL()->ColTrim_Deg_f32 = I2CHwColAngle_Deg_T_f32;
		Rte_Pim_DigColPsEOL()->SpurTrim_Deg_f32 = I2CHwSpurAngle_Deg_T_f32;
		Rte_Pim_DigColPsEOL()->TrimComp_Cnt_u16 = D_TRIMCOMPLETE_CNT_U16;
		Rte_Pim_DigColPsEOL()->R_ColTrim_Cnt_u32 = Redundant_Format_1_m(*(uint32*)&I2CHwColAngle_Deg_T_f32);
		Rte_Pim_DigColPsEOL()->R_SpurTrim_Cnt_u32 = Redundant_Format_1_m(*(uint32*)&I2CHwSpurAngle_Deg_T_f32);
		Rte_Pim_DigColPsEOL()->R_TrimCom_Cnt_u16 = Redundant_Format_1_m((uint16)D_TRIMCOMPLETE_CNT_U16);
		(void)Rte_Call_EOLDigColPosCals_WriteBlock(NULL_PTR);
		RetCode_Cnt_T_u08 = RTE_E_OK;

	}

	if ( Rte_Pim_DigColPsEOL()->TrimComp_Cnt_u16 != D_TRIMCOMPLETE_CNT_U16 )
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorNotTrimmed, 1U, NTC_STATUS_FAILED);

	}
	else
	{
		DigColPs_I2CHwTrimTransCnts_Uls_M_u08 = D_I2CHWTRIMTRANSCNT_ULS_U08;
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorNotTrimmed, 0U, NTC_STATUS_PASSED);
	}

	return RetCode_Cnt_T_u08;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigColPs_SCom_NxtClrTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NxtClrTrim> of PortPrototype <DigColPs_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DigColPs_SCom_NxtClrTrim(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_SCom_NxtClrTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DigColPs_SCom_NxtClrTrim
 *********************************************************************************************************************/

	DigColPs_ColTrimStatic_Deg_M_f32 = 0.0f;
	DigColPs_SpurTrimStatic_Deg_M_f32 = 0.0f;
	DigColPs_TrimCompStatic_Cnt_M_u16 = D_TRIMNOTCOMPLETE_CNT_U16;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigColPs_SCom_NxtSetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NxtSetTrim> of PortPrototype <DigColPs_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DigColPs_SCom_NxtSetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DigColPs_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_SCom_NxtSetTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DigColPs_SCom_NxtSetTrim (returns application error)
 *********************************************************************************************************************/

	VAR(boolean, AUTOMATIC) I2CColSensorFault_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) I2CSpurSensorFault_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) I2CHwColAngle_Deg_T_f32;
	VAR(float32, AUTOMATIC) I2CHwSpurAngle_Deg_T_f32;
	VAR(float32, AUTOMATIC) I2CHwColAngleForTrim_Deg_T_f32;
	VAR(float32, AUTOMATIC) I2CHwTrimColOffset_Deg_T_f32;
	VAR(float32, AUTOMATIC) Snsr1Trimoffset_Deg_T_f32;
	VAR(float32, AUTOMATIC) Snsr2Trimoffset_Deg_T_f32;
	VAR(Std_ReturnType, AUTOMATIC) RetCode_Cnt_T_u08 = RTE_E_DigColPs_SCom_ConditionsNotCorrect;

	/* Disable interrupts for data consistency while reading inputs */
	(void)GetResource(RES_SCHEDULER);
	I2CColSensorFault_Cnt_T_lgc = DigColPs_ColSnsrErr_Cnt_M_lgc;
	I2CSpurSensorFault_Cnt_T_lgc = DigColPs_SpurSnsrErr_Cnt_M_lgc;
	I2CHwColAngleForTrim_Deg_T_f32 = DigColPs_I2CHwColAngleForTrim_Deg_M_f32;
	(void)ReleaseResource(RES_SCHEDULER);


	if ((I2CColSensorFault_Cnt_T_lgc == FALSE) && (I2CSpurSensorFault_Cnt_T_lgc == FALSE) &&
		(DigColPs_TrimCompStatic_Cnt_M_u16 != D_TRIMCOMPLETE_CNT_U16) &&
		(Rte_Pim_DigColPsEOL()->TrimComp_Cnt_u16 != D_TRIMCOMPLETE_CNT_U16))
	{
		I2CHwTrimColOffset_Deg_T_f32 = I2CHwColAngleForTrim_Deg_T_f32 - D_VERNIERANGLECENTEROFF_DEG_F32;
		Snsr1Trimoffset_Deg_T_f32 = I2CHwTrimColOffset_Deg_T_f32 * D_DUALSPURRATIO_ULS_F32 ;
		Snsr2Trimoffset_Deg_T_f32 = I2CHwTrimColOffset_Deg_T_f32 * D_SPURRATIO_ULS_F32;

		if (I2CHwTrimColOffset_Deg_T_f32 >= 0.0f)
		{
			I2CHwColAngle_Deg_T_f32 = ConstrainOneRev(Snsr1Trimoffset_Deg_T_f32) - D_ONEREV_DEGREESPREV_F32;
			I2CHwSpurAngle_Deg_T_f32 = ConstrainOneRev(Snsr2Trimoffset_Deg_T_f32) - D_ONEREV_DEGREESPREV_F32;
		}
		else
		{
			I2CHwColAngle_Deg_T_f32 = ConstrainOneRev(Snsr1Trimoffset_Deg_T_f32);
			I2CHwSpurAngle_Deg_T_f32 = ConstrainOneRev(Snsr2Trimoffset_Deg_T_f32);
		}

		DigColPs_ColTrimStatic_Deg_M_f32 = I2CHwColAngle_Deg_T_f32;
		DigColPs_SpurTrimStatic_Deg_M_f32 = I2CHwSpurAngle_Deg_T_f32;
		DigColPs_TrimCompStatic_Cnt_M_u16 = D_TRIMCOMPLETE_CNT_U16;

		RetCode_Cnt_T_u08 = RTE_E_OK;
	}
	else
	{
		/* Do nothing. */
	}

	if (DigColPs_TrimCompStatic_Cnt_M_u16 == D_TRIMCOMPLETE_CNT_U16)
	{
		DigColPs_I2CHwTrimTransCnts_Uls_M_u08 = D_I2CHWTRIMTRANSCNT_ULS_U08;
	}
	else
	{
		/* Do nothing. */
	}

	return RetCode_Cnt_T_u08;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PhaNvmRead_GetData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetData> of PortPrototype <PhaNvmRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void PhaNvmRead_GetData(Boolean *ColCustDataReadCmpl_Cnt_lgc, Boolean *SpurCustDataReadCmpl_Cnt_lgc, UInt32 *ColCustData_Uls_u32, UInt32 *SpurCustData_Uls_u32)
#else
 *   void PhaNvmRead_GetData(CustReadCmplType *ColCustDataReadCmpl_Cnt_lgc, CustReadCmplType *SpurCustDataReadCmpl_Cnt_lgc, CustDataType *ColCustData_Uls_u32, CustDataType *SpurCustData_Uls_u32)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) PhaNvmRead_GetData(P2VAR(Boolean, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) ColCustDataReadCmpl_Cnt_lgc, P2VAR(Boolean, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) SpurCustDataReadCmpl_Cnt_lgc, P2VAR(UInt32, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) ColCustData_Uls_u32, P2VAR(UInt32, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) SpurCustData_Uls_u32)
#else
FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) PhaNvmRead_GetData(P2VAR(CustReadCmplType, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) ColCustDataReadCmpl_Cnt_lgc, P2VAR(CustReadCmplType, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) SpurCustDataReadCmpl_Cnt_lgc, P2VAR(CustDataType, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) ColCustData_Uls_u32, P2VAR(CustDataType, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) SpurCustData_Uls_u32)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PhaNvmRead_GetData
 *********************************************************************************************************************/
	/* Probe Housing Assembly (PHA) NVM Data Read from I2C Sensor */
	DigColPsInt_GetPhaNvmData(ColCustDataReadCmpl_Cnt_lgc,SpurCustDataReadCmpl_Cnt_lgc,ColCustData_Uls_u32,SpurCustData_Uls_u32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_DIGCOLPS_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *         Name:    OddParityFault
 *
 *  Description:    Returns TRUE if there is an odd parity error for the input data.  Parity is calculated over the
 *                  entire 16 bits of input.  Mask off any unwanted (error) bits before passing to this function.
 *
 *  Inputs                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  Input_Cnt_T_u16                     | uint16    | FULL      | FULL
 *
 *  Output                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  Error_Cnt_T_lgc                     | boolean   | FALSE     | TRUE
 *
 **********************************************************************************************************************/
STATIC FUNC(boolean, SA_DIGCOLPS_CODE) OddParityFault(VAR(uint16, AUTOMATIC) Input_Cnt_T_u16)
{
	VAR(uint8, AUTOMATIC) Parity_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) Error_Cnt_T_lgc;

	Parity_Cnt_T_u08 = 0U;

	/* Count the number of 1's in the inputs */
	/* Note: This while loop is limited to a maximum of 16 iterations */
	while (Input_Cnt_T_u16 > 0U)
	{
		if ((Input_Cnt_T_u16 & 1U) != 0U)
		{
			Parity_Cnt_T_u08++;
		}
		Input_Cnt_T_u16 >>= 1U;
	}

	/* For odd parity, the least significant bit should be set */
	if ((Parity_Cnt_T_u08 & 1U) == 0U)
	{
		Error_Cnt_T_lgc = TRUE;
	}
	else
	{
		Error_Cnt_T_lgc = FALSE;
	}

	return Error_Cnt_T_lgc;
}


/***********************************************************************************************************************
 *         Name:    DiagnosticThreshold
 *
 *  Description:    Common diagnostic threshold function for computing if a diagnostic has filed.
 *
 *  Inputs                              | Type             | Min       | Max
 *  ----------------------------------- | ---------------- | --------- | ---------
 *  FaultPresent_Cnt_T_lgc              | boolean          | FALSE     | TRUE
 *  DiagSettings_Cnt_T_str              | DiagSettings_Str | FULL      | FULL
 *  AccumulatorPtr_Cnt_T_u16            | *uint16          | FULL      | FULL
 *
 *  Output                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  DiagFailed_Cnt_T_lgc                | boolean   | FALSE     | TRUE
 *
 **********************************************************************************************************************/
STATIC FUNC(boolean, SA_DIGCOLPS_CODE) DiagnosticThreshold(VAR(boolean, AUTOMATIC) FaultPresent_Cnt_T_lgc, CONST(DiagSettings_Str, AUTOMATIC) DiagSettings_Cnt_T_str, P2VAR(uint16, AUTOMATIC, AUTOMATIC) AccumulatorPtr_Cnt_T_u16)
{
	VAR(boolean, AUTOMATIC) DiagFailed_Cnt_T_lgc;

	DiagFailed_Cnt_T_lgc = FALSE;

	if (FaultPresent_Cnt_T_lgc == TRUE)
	{
		*AccumulatorPtr_Cnt_T_u16 = DiagPStep_m(*AccumulatorPtr_Cnt_T_u16, DiagSettings_Cnt_T_str);

		if (DiagFailed_m(*AccumulatorPtr_Cnt_T_u16, DiagSettings_Cnt_T_str) == TRUE)
		{
			DiagFailed_Cnt_T_lgc = TRUE;
		}
	}
	else
	{
		*AccumulatorPtr_Cnt_T_u16 = DiagNStep_m(*AccumulatorPtr_Cnt_T_u16, DiagSettings_Cnt_T_str);
	}

	return DiagFailed_Cnt_T_lgc;
}


/***********************************************************************************************************************
 *  Function:  VernierLookup
 *
 *  Perform Vernier Lookup function.  The FDD specifically calls out that the lookup shall use the closest match and
 *  therefore the interpolation library functions cannot be used.  This function expects a 3xN array where the first
 *  "row" contains the values to match against and the second and third "rows" contains the corresponding outputs for
 *  ColrRev and SpurRev respectively.
 *
 *
 *  Inputs                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  VernierLUT_Cnt_T_s16                | uint16    | -396**    | 360**
 *  Level_Deg_T_f32                     | float32   | -792      | 360
 *
 *  Output                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  ColRevPtr_Cnt_T_u08                 | uint8*    | 0         | 9
 *  SpurRevPtr_Cnt_T_u08                | uint8*    | 0         | 10
 *  VernierLevelNo_Cnt_T_u08            | uint8*    | 0         | 22
 *
 * ** VernierLUT is a pointer to a FLASH constant defined in this file.  See the FLASH constant definition above for
 *    actual ranges of data.
 *
 **********************************************************************************************************************/
STATIC FUNC(void, SA_DIGCOLPS_CODE) VernierLookup(
	CONST(sint16, AUTOMATIC) VernierLUT_Cnt_T_s16[],
	VAR(uint8, AUTOMATIC) LookupTableXSize_Cnt_T_u08,
	VAR(float32, AUTOMATIC) Level_Deg_T_f32,
	P2VAR(uint8, AUTOMATIC, AUTOMATIC) ColRevPtr_Cnt_T_u08,
	P2VAR(uint8, AUTOMATIC, AUTOMATIC) SpurRevPtr_Cnt_T_u08,
	P2VAR(uint8, AUTOATIC, AUTOMATIC) VernierLevelNo_Cnt_T_u08)
{
	VAR(uint8, AUTOMATIC) Index_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) Search_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) MatchFound_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) Middle_Cnt_T_f32;

	Index_Cnt_T_u08 = 0U;

	if (Level_Deg_T_f32 <= (float32)VernierLUT_Cnt_T_s16[0])
	{
		/* Less than minimum - return the first index */
	}
	else
	{
		/* Somewhere in between - must perform search */
		MatchFound_Cnt_T_lgc = FALSE;
		for (Search_Cnt_T_u08 = 0U;
			 ((Search_Cnt_T_u08 < (LookupTableXSize_Cnt_T_u08 - 1U)) && (MatchFound_Cnt_T_lgc == FALSE));
			 Search_Cnt_T_u08++)
		{
			/* Check if the level is in this range */
			if (Level_Deg_T_f32 < (float32)VernierLUT_Cnt_T_s16[Search_Cnt_T_u08 + 1U])
			{
				MatchFound_Cnt_T_lgc = TRUE;

				Middle_Cnt_T_f32 = (float32)VernierLUT_Cnt_T_s16[Search_Cnt_T_u08 + 1U];
				Middle_Cnt_T_f32 -= (float32)VernierLUT_Cnt_T_s16[Search_Cnt_T_u08];
				Middle_Cnt_T_f32 *= 0.5f;
				Middle_Cnt_T_f32 += (float32)VernierLUT_Cnt_T_s16[Search_Cnt_T_u08];

				/* Choose index based upon linear midpoint between indexes */
				if (Level_Deg_T_f32 < Middle_Cnt_T_f32)
				{
					Index_Cnt_T_u08 = Search_Cnt_T_u08;
				}
				else
				{
					Index_Cnt_T_u08 = Search_Cnt_T_u08 + 1U;
				}
			}
		}

		if (MatchFound_Cnt_T_lgc == FALSE)
		{
			/* Greater than or equal to maximum - return the last index */
			Index_Cnt_T_u08 = LookupTableXSize_Cnt_T_u08 - 1U;
		}
	}

	/* Update all of the output values include the module level variables set by this function */
	*VernierLevelNo_Cnt_T_u08 = (uint8)VernierLUT_Cnt_T_s16[(D_VERNIERLEVELNO_CNT_U08 * LookupTableXSize_Cnt_T_u08) + Index_Cnt_T_u08];
	*ColRevPtr_Cnt_T_u08 = (uint8)VernierLUT_Cnt_T_s16[(D_COLUMNREVS_CNT_U08 * LookupTableXSize_Cnt_T_u08) + Index_Cnt_T_u08];                     /* PRQA S 2986 */
	*SpurRevPtr_Cnt_T_u08 = (uint8)VernierLUT_Cnt_T_s16[(D_SPURREVS_CNT_U08 * LookupTableXSize_Cnt_T_u08) + Index_Cnt_T_u08];
}


/***********************************************************************************************************************
 *  Function:  ComputeRoughTurns
 *
 *  Compute rough turn count to preserve consistency of LPF output when rollover condition occurs.
 *
 *  Inputs                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  Delta_Deg_T_f32                     | float32   | -360      | 360
 *
 *  Output                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  RoughTurnAccPtr_Cnt_T_s16           | sint16*    | -5        | 5
 *  RoughTurnCount_Deg_T_f32            | float32   | -1800     | 1800
 *
 **********************************************************************************************************************/
STATIC FUNC(float32, SA_DIGCOLPS_CODE) ComputeRoughTurns(VAR(float32, AUTOMATIC) Delta_Deg_T_f32, P2VAR(sint16, AUTOMATIC, AUTOMATIC) RoughTurnAccPtr_Cnt_T_s16)
{
	VAR(float32, AUTOMATIC) RoughTurnCount_Deg_T_f32;

	if (Delta_Deg_T_f32 > k_StepDetect_Deg_f32)
	{
		*RoughTurnAccPtr_Cnt_T_s16 -= 1;
	}
	else if (Delta_Deg_T_f32 < -k_StepDetect_Deg_f32)
	{
		*RoughTurnAccPtr_Cnt_T_s16 += 1;
	}
	else
	{
		/* Do Nothing */
	}

	RoughTurnCount_Deg_T_f32 = (float32)(*RoughTurnAccPtr_Cnt_T_s16) * D_ONEREV_DEGREESPREV_F32;

	return RoughTurnCount_Deg_T_f32;
}



/***********************************************************************************************************************
 *  Function:  ConstrainOneRev
 *
 *  Constrain input to range of 0-360 degrees.  Same functionality as "fmodf(input, 360)" except that this function
 *  gracefully handles negative input values.
 *
 *  Inputs                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  Input_Deg_T_f32                     | float32   | -1800     | 1800
 *
 *  Output                              | Type      | Min       | Max
 *  ----------------------------------- | --------- | --------- | ---------
 *  Input_Deg_T_f32                     | float32   | 0         | 360
 *
 **********************************************************************************************************************/
STATIC FUNC(float32, SA_DIGCOLPS_CODE) ConstrainOneRev(VAR(float32, AUTOMATIC) Input_Deg_T_f32)
{
	while (Input_Deg_T_f32 >= D_ONEREV_DEGREESPREV_F32)
	{
		Input_Deg_T_f32 -= D_ONEREV_DEGREESPREV_F32;
	}

	while (Input_Deg_T_f32 < D_ZERO_ULS_F32)
	{
		Input_Deg_T_f32 += D_ONEREV_DEGREESPREV_F32;
	}

	return Input_Deg_T_f32;
}
/**********************************************************************************************************************
 * Function: I2CCommFltDiag
 * Inputs  : uint8 I2CSensCommFlts_Cnt_M_u08
 * Outputs : None
 *********************************************************************************************************************/
STATIC FUNC(void, SA_DIGCOLPS_CODE) I2CCommFltDiag(VAR(uint8, AUTOMATIC) I2CSensCommFlts_Cnt_T_u08)
{
	if(DigColPs_SnsrReInitInProgs_Cnt_M_lgc == FALSE)
	{
		if(I2CSensCommFlts_Cnt_T_u08 != 0U)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASnsrCommFault, I2CSensCommFlts_Cnt_T_u08, NTC_STATUS_FAILED);
		}
		else
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASnsrCommFault, 0U, NTC_STATUS_PASSED);
		}
	}
}
/**********************************************************************************************************************
 * Function: I2CSnsrDataCheck
 * Inputs  : uint16 I2CHwColAngle_Cnt_T_u16,
 * 			 uint16 I2CHwSpurAngle_Cnt_T_u16,
 * 			 boolean &ColSensorFault_Cnt_T_lgc
 * 			 boolean &SpurSensorFault_Cnt_T_lgc
 * 			 boolean &ColRegisterFaultCnt_T_lgc
 * 			 boolean &SpurRegisterFaultCnt_T_lgc
 * Outputs : None
 *********************************************************************************************************************/
STATIC FUNC(void, SA_DIGCOLPS_CODE) I2CSnsrDataCheck(VAR(uint16, AUTOMATIC) I2CHwColAngle_Cnt_T_u16,
													VAR(uint16, AUTOMATIC) I2CHwSpurAngle_Cnt_T_u16,
													P2VAR(boolean, AUTOMATIC, AUTOMATIC) ColSensorFault_Cnt_T_lgc,
													P2VAR(boolean, AUTOMATIC, AUTOMATIC) SpurSensorFault_Cnt_T_lgc,
													P2VAR(boolean, AUTOMATIC, AUTOMATIC) ColRegisterFaultCnt_T_lgc,
													P2VAR(boolean, AUTOMATIC, AUTOMATIC) SpurRegisterFaultCnt_T_lgc)
{
	/* Column Sensor - Error Bit */
	if ((I2CHwColAngle_Cnt_T_u16 & D_SNSRERRORBIT_CNT_U16) != 0U)
	{
		*ColSensorFault_Cnt_T_lgc = TRUE;
	}

	/* Spur Sensor - Error Bit */
	if ((I2CHwSpurAngle_Cnt_T_u16 & D_SNSRERRORBIT_CNT_U16) != 0U)
	{
		*SpurSensorFault_Cnt_T_lgc = TRUE;
	}

	/* Column Sensor Register ID Bit Check */
	if ((I2CHwColAngle_Cnt_T_u16 & D_ANGREGIDBIT_CNT_U16) != 0U)
	{
		*ColRegisterFaultCnt_T_lgc = TRUE;
	}

	/* Spur Sensor Register ID Bit Check */
	if ((I2CHwSpurAngle_Cnt_T_u16 & D_ANGREGIDBIT_CNT_U16) != 0U)
	{
		*SpurRegisterFaultCnt_T_lgc = TRUE;
	}
}
/**********************************************************************************************************************
 * Function: I2CSnsrReInitMaxTry
 * Inputs  : uint8 I2CSensCommFlts_Cnt_M_u08
 * Outputs : uint8 I2CHwDataType_Cnt_T_u08
 *********************************************************************************************************************/
STATIC FUNC(uint8, SA_DIGCOLPS_CODE) I2CSnsrReInitMaxTry(VAR(uint8,AUTOMATIC) I2CSensCommFlts_Cnt_T_u08,
															VAR(boolean,AUTOMATIC) ColSensorFlt_Cnt_T_lgc,
															VAR(boolean,AUTOMATIC) SpurSensorFlt_Cnt_T_lgc)
{
	VAR(uint8, AUTOMATIC) I2CHwDataType_Cnt_T_u08;

	I2CHwDataType_Cnt_T_u08 = DigColPs_I2CHwDataType_Cnt_M_u08;

	if((I2CSensCommFlts_Cnt_T_u08 != 0U)&&
			(ColSensorFlt_Cnt_T_lgc == FALSE)&&
			(SpurSensorFlt_Cnt_T_lgc == FALSE))
	{
		if(DigColPs_SnsrReInitMaxTryCntr_Cnt_M_u08 != 0U)
		{
			(void)DigColPsInt_Reset();
			DigColPs_SnsrReInitInProgs_Cnt_M_lgc = TRUE;
			DigColPs_SnsrReInitMaxTryCntr_Cnt_M_u08--;
			I2CHwDataType_Cnt_T_u08 = D_ANGLEDATA_CNT_U08;
			DigColPs_ColSnsrFlt_Cnt_M_lgc = FALSE;
			DigColPs_SpurSnsrFlt_Cnt_M_lgc = FALSE;
		}
	}

	return I2CHwDataType_Cnt_T_u08;
}
/**********************************************************************************************************************
 * Function: SnsrFltDiag
 * Inputs  : uint16 I2CHwColAngle_Cnt_T_u16
 * 			 uint16 I2CHwSpurAngle_Cnt_T_u16
 * 			 uint8 I2CHwDataType_Cnt_T_u08
 * 			 boolean ColParityErrorEvt_Cnt_T_lgc
 * 			 boolean SpurParityErrorEvt_Cnt_T_lgc
 * Outputs : None
 *********************************************************************************************************************/
STATIC FUNC(void, SA_DIGCOLPS_CODE) SnsrFltDiag(VAR(uint16, AUTOMATIC) I2CHwColAngle_Cnt_T_u16,
												VAR(uint16, AUTOMATIC) I2CHwSpurAngle_Cnt_T_u16,
												VAR(uint8, AUTOMATIC) I2CHwDataType_Cnt_T_u08,
												VAR(uint8, AUTOMATIC) I2CSensCommFlts_Cnt_T_u08,
												VAR(boolean, AUTOMATIC) ColSnsrErr_Cnt_T_lgc,
												VAR(boolean, AUTOMATIC) SpurSnsrErr_Cnt_T_lgc)
{
	VAR(boolean, AUTOMATIC) ErrorDataReady_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ParityOrCommFault_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) Param1_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) Param2_Cnt_T_u08;

	DigColPs_ColSnsrFlt_Cnt_M_lgc |= ColSnsrErr_Cnt_T_lgc;
	DigColPs_SpurSnsrFlt_Cnt_M_lgc |= SpurSnsrErr_Cnt_T_lgc;

	if ((I2CHwDataType_Cnt_T_u08 == D_ERRORREG_CNT_U08) ||(I2CHwDataType_Cnt_T_u08 == D_EXTERRORREG_CNT_U08))
	{
		ErrorDataReady_Cnt_T_lgc = TRUE;
	}
	else
	{
		ErrorDataReady_Cnt_T_lgc = FALSE;
	}

	/* Masking Sensor Error Info */
	I2CSensCommFlts_Cnt_T_u08 = I2CSensCommFlts_Cnt_T_u08 & D_COMMORPARITYERR_CNT_U08;

	if (I2CSensCommFlts_Cnt_T_u08 != 0U)
	{
		ParityOrCommFault_Cnt_T_lgc = TRUE;
	}
	else
	{
		ParityOrCommFault_Cnt_T_lgc = FALSE;
	}

	if (ErrorDataReady_Cnt_T_lgc == TRUE)
	{
		DigColPs_ReqI2CSnsrDataType_Cnt_M_u08 = D_EXTERRORREG_CNT_U08;
	}
	else if((ParityOrCommFault_Cnt_T_lgc == TRUE)||
			(DigColPs_ColSnsrFlt_Cnt_M_lgc == TRUE) ||
			(DigColPs_SpurSnsrFlt_Cnt_M_lgc == TRUE))
	{
		DigColPs_ReqI2CSnsrDataType_Cnt_M_u08 = D_ERRORREG_CNT_U08;
	}
	else
	{
		DigColPs_ReqI2CSnsrDataType_Cnt_M_u08 = D_ANGLEDATA_CNT_U08;
	}

	/* Error Data Ready and NOT (Parity or Comm. Fault) */
	if ((ErrorDataReady_Cnt_T_lgc == TRUE) &&
		(ParityOrCommFault_Cnt_T_lgc == FALSE) &&
		(DigColPs_ColSnsrFlt_Cnt_M_lgc == TRUE))
	{
		Param1_Cnt_T_u08 = (uint8)((I2CHwColAngle_Cnt_T_u16 & 0x0C00U) >> 6U);
		Param1_Cnt_T_u08 |= (uint8)(I2CHwColAngle_Cnt_T_u16 & 0x004FU);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorRel, Param1_Cnt_T_u08, NTC_STATUS_FAILED);
		DigColPs_ColSnsrFlt_Cnt_M_lgc = FALSE;
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorRel, 0U, NTC_STATUS_PASSED);
	}

	/* Error Data Ready and NOT (Parity or Comm. Fault) 1 */
	if ((ErrorDataReady_Cnt_T_lgc == TRUE) &&
		(ParityOrCommFault_Cnt_T_lgc == FALSE) &&
		(DigColPs_SpurSnsrFlt_Cnt_M_lgc == TRUE))
	{
		Param2_Cnt_T_u08 = (uint8)((I2CHwSpurAngle_Cnt_T_u16 & 0x0C00U) >> 6U);
		Param2_Cnt_T_u08 |= (uint8)(I2CHwSpurAngle_Cnt_T_u16 & 0x004FU);
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorAbs, Param2_Cnt_T_u08, NTC_STATUS_FAILED);
		DigColPs_SpurSnsrFlt_Cnt_M_lgc = FALSE;
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWASensorAbs, 0U, NTC_STATUS_PASSED);
	}
}
/**********************************************************************************************************************
 * Function: VernCorrlnFltDiag
 * Inputs  : boolean VernCorrDetect_Cnt_T_lgc
 * 			 boolean SkipStepFltDetect_Cnt_T_lgc
 * Outputs : None
 *********************************************************************************************************************/
STATIC FUNC(void, SA_DIGCOLPS_CODE) VernCorrlnFltDiag(VAR(boolean, AUTOMATIC) VernCorrDetect_Cnt_T_lgc,
													VAR(boolean, AUTOMATIC) SkipStepFltDetect_Cnt_T_lgc)
{
	VAR(uint8, AUTOMATIC) Param_Cnt_T_u08;

	Param_Cnt_T_u08 = 0x00U;

	if (DigColPs_I2CHwTrimTransCnts_Uls_M_u08 > 0U)
	{
		DigColPs_I2CHwTrimTransCnts_Uls_M_u08--;
		Param_Cnt_T_u08 = 0x08U;
	}

	if ((VernCorrDetect_Cnt_T_lgc == TRUE) ||
		(SkipStepFltDetect_Cnt_T_lgc == TRUE) ||
		(DigColPs_VernierAngleOORange_Cnt_M_lgc == TRUE))
	{
			/****MISRA 2004: Rule 21.1 violation: Redundant operation need for UTP purposes***/
		Param_Cnt_T_u08 |= ((uint8)VernCorrDetect_Cnt_T_lgc) & 0x01U;                                                  /* PRQA S 2985 */
		/****MISRA 2004: Rule 21.1 violation: Redundant operation need for UTP purposes***/
		Param_Cnt_T_u08 |= ((uint8)(SkipStepFltDetect_Cnt_T_lgc << 1) & 0x02U);                                        /* PRQA S 2985 */
		/****MISRA 2004: Rule 21.1 violation: Redundant operation need for UTP purposes***/
		Param_Cnt_T_u08 |= ((uint8)(DigColPs_VernierAngleOORange_Cnt_M_lgc << 2) & 0x04U);

		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWACrossChecks, Param_Cnt_T_u08, NTC_STATUS_FAILED);
		DigColPs_HwAVernCorrFault_Cnt_M_lgc = TRUE;
	}
	else
	{
		if ((DigColPs_VernCorrDetectAcc_Cnt_M_u16 == 0U) && (DigColPs_SkipStepFltDetectAcc_Cnt_M_u16 == 0U))
		{
			DigColPs_HwAVernCorrFault_Cnt_M_lgc = FALSE;
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_HWACrossChecks, 0U, NTC_STATUS_PASSED);
			DigColPs_PrevAngleDataAvailable_Cnt_M_lgc = TRUE;
		}
	}
}
/**********************************************************************************************************************
 * Function: ChkVernCorrlnError
 * Inputs  : uint8 VernierLevelNo_Cnt_T_u08
 * 			 float32 VernDiagError_Deg_T_f32
 * 			 boolean TrimComplete_Cnt_T_lgc
 * Outputs : boolean VernCorrDetect_Cnt_T_lgc
 *********************************************************************************************************************/
STATIC FUNC(boolean, SA_DIGCOLPS_CODE) ChkVernCorrlnError(VAR(uint8, AUTOMATIC) VernierLevelNo_Cnt_T_u08,
														VAR(float32, AUTOMATIC) VernDiagError_Deg_T_f32,
														VAR(boolean, AUTOMATIC) TrimComplete_Cnt_T_lgc)
{
	VAR(boolean, AUTOMATIC) VernCorrDetect_Cnt_T_lgc;

	if ((Abs_f32_m(VernDiagError_Deg_T_f32) > k_VernCorrErrorThresh_Deg_f32) && (TrimComplete_Cnt_T_lgc == TRUE))
	{
		VernCorrDetect_Cnt_T_lgc = TRUE;
	}
	else
	{
		VernCorrDetect_Cnt_T_lgc = FALSE;
	}

	VernCorrDetect_Cnt_T_lgc = DiagnosticThreshold(VernCorrDetect_Cnt_T_lgc, k_VernCorrErrorDiag_Cnt_str, &DigColPs_VernCorrDetectAcc_Cnt_M_u16);

	return VernCorrDetect_Cnt_T_lgc;

}
/**********************************************************************************************************************
 * Function: ChkSkipStepError
 * Inputs  : uint8 AbsVernLevelDiff_Cnt_T_u08
 * 			 boolean TrimComplete_Cnt_T_lgc
 * Outputs : boolean SkipStepFltDetect_Cnt_T_lgc
 *********************************************************************************************************************/
STATIC FUNC(boolean, SA_DIGCOLPS_CODE) ChkSkipStepError(VAR(uint8, AUTOMATIC) AbsVernLevelDiff_Cnt_T_u08,
														VAR(boolean, AUTOMATIC) TrimComplete_Cnt_T_lgc)
{
	VAR(boolean, AUTOMATIC) SkipStepFltDetect_Cnt_T_lgc;

	SkipStepFltDetect_Cnt_T_lgc = FALSE;

	if ((AbsVernLevelDiff_Cnt_T_u08 > 1U)&&(TrimComplete_Cnt_T_lgc == TRUE))
	{
		DigColPs_SkipStepFltDetectAcc_Cnt_M_u16 = DiagPStep_m(DigColPs_SkipStepFltDetectAcc_Cnt_M_u16, k_SkipStepErrDiag_Cnt_str);
	}
	else
	{
		DigColPs_SkipStepFltDetectAcc_Cnt_M_u16 = DiagNStep_m(DigColPs_SkipStepFltDetectAcc_Cnt_M_u16, k_SkipStepErrDiag_Cnt_str);
	}

	/* Did not use DiagnosticThreshold function here because of combined accumulator for DiagFailed_m check */
	DigColPs_SkipStepFltDetectAcc_Cnt_M_u16 += DigColPs_VernCorrDetectAcc_Cnt_M_u16;
	DigColPs_SkipStepFltDetectAcc_Cnt_M_u16 = Min_m(DigColPs_SkipStepFltDetectAcc_Cnt_M_u16, k_SkipStepErrDiag_Cnt_str.Threshold);

	if (DiagFailed_m(DigColPs_SkipStepFltDetectAcc_Cnt_M_u16, k_SkipStepErrDiag_Cnt_str) == TRUE)
	{
		SkipStepFltDetect_Cnt_T_lgc = TRUE;
	}

	return SkipStepFltDetect_Cnt_T_lgc;
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/







/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
