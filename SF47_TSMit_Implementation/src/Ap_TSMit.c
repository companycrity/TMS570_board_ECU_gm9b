/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_TSMit.c
 *     Workspace:  C:/Workspace/SF47_TSMit_Implementation-CBD_TSMit/SF47/SF47_TSMit_Implementation/autosar
 *     SW-C Type:  Ap_TSMit
 *  Generated at:  Wed Sep  3 10:01:19 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_TSMit>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Copyright 2014 Nexteer
 * Nexteer Confidential
 *
 * Module File Name  : Ap_TSMit.c
 * Module Description: This function provides a motor torque command to mitigate linear rack force disturbances caused
 *                     by unequal driveline torques.
 * Project           : CBD
 * Author            : Jared Julien (kzdyfh)
 **********************************************************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       kzdyfh %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ------------------------------------------------------------------------     ----------
 * 07/22/14  1        JWJ       Initial component creation based upon SF-47 rev 001                          12183
 * 09/03/14  2        JWJ       Added updates from actual release of FDD v001                                12183
 *********************************************************************************************************************/
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

#include "Rte_Ap_TSMit.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_TSMit_Cfg.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include "filters.h"
#include "fixmath.h"
#include "interpolation.h"


/*** File-Scope MISRA Deviations ***/
/* PRQA S 4395 EOF
 * MISRA-C: 2004 Rule 10.4: This deviation is required for a composite expression of 'essentially float' typ */


/*** Definitions ***/
#define D_10MS_SEC_F32	0.01f
#define D_ONESEC_MS_F32	1000.0f

#define D_OUTPUTCMDLIMIT_HWNM_F32	3.0f


/*** Module Internal Variables ***/
#define TSMIT_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AP_TSMIT_VAR) TSMit_PosTrsmTqGainLongTerm_Uls_M_f32;
STATIC VAR(float32, AP_TSMIT_VAR) TSMit_NegTrsmTqGainLongTerm_Uls_M_f32;
STATIC VAR(uint32, AP_TSMIT_VAR) TSMit_GainLearningEnableTimer_mS_M_u32;
STATIC VAR(float32, AP_TSMIT_VAR) TSMit_PrevTSMitCommand_HwNm_M_f32; /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_TSMIT_VAR) TSMit_HwTqFiltered_HwNm_D_f32; /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_TSMIT_VAR) TSMit_YawRateFiltered_DegpS_D_f32; /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_TSMIT_VAR) TSMit_PinionTrqEst_HwNm_D_f32; /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_TSMIT_VAR) TSMit_PosTransTrqGainShortTerm_HwNmpTransNm_D_f32; /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_TSMIT_VAR) TSMit_NegTransTrqGainShortTerm_HwNmpTransNm_D_f32; /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_TSMIT_VAR) TSMit_PosTransTrqGainLongTerm_HwNmpTransNm_D_f32; /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_TSMIT_VAR) TSMit_NegTransTrqGainLongTerm_HwNmpTransNm_D_f32; /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_TSMIT_VAR) TSMit_CmdScaleFactor_Uls_D_f32; /* PRQA S 3218 */
STATIC volatile VAR(float32, AP_TSMIT_VAR) TSMit_CommandRaw_HwNm_D_f32; /* PRQA S 3218 */
#define TSMIT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define TSMIT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AP_TSMIT_VAR) TSMit_HwTrqFilterKSV_Cnt_M_str;
STATIC VAR(LPF32KSV_Str, AP_TSMIT_VAR) TSMit_YawRateFilterKSV_Cnt_M_str;
STATIC VAR(LPF32KSV_Str, AP_TSMIT_VAR) TSMit_STPosTransGainFilterKSV_Cnt_M_str;
STATIC VAR(LPF32KSV_Str, AP_TSMIT_VAR) TSMit_STNegTransGainFilterKSV_Cnt_M_str;
#define TSMIT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


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
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0u)
 *   NVM_REQ_NOT_OK (1u)
 *   NVM_REQ_PENDING (2u)
 *   NVM_REQ_INTEGRITY_FAILED (3u)
 *   NVM_REQ_BLOCK_SKIPPED (4u)
 *   NVM_REQ_NV_INVALIDATED (5u)
 *
 * Array Types:
 * ============
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * TSMit_Disable_Type: Record with elements
 *   GainLearningDisable_Cnt_lgc of type Boolean
 *   FunctionDisable_Cnt_lgc of type Boolean
 * TSMit_Gain_Type: Record with elements
 *   PosTransGainLongTerm_HwNmpTransNm_f32 of type Float
 *   NegTransGainLongTerm_HwNmpTransNm_f32 of type Float
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
 *   TSMit_Disable_Type *Rte_Pim_TSMitDisableEOL(void)
 *   TSMit_Gain_Type *Rte_Pim_TSMitGainLrn(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_TSMIT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSMit_Init1
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
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_TSMitGainLrn_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSMit_Init1
 *********************************************************************************************************************/

	LPF_KUpdate_f32_m(k_TSMitHwTrqLPFiltFc_Hz_f32, D_10MS_SEC_F32, &TSMit_HwTrqFilterKSV_Cnt_M_str);
	LPF_KUpdate_f32_m(k_TSMitYawRateLPFiltFc_Hz_f32, D_10MS_SEC_F32, &TSMit_YawRateFilterKSV_Cnt_M_str);
	LPF_KUpdate_f32_m(k_TSMitGainLearningFreqFc_Hz_f32, D_10MS_SEC_F32, &TSMit_STPosTransGainFilterKSV_Cnt_M_str);
	LPF_KUpdate_f32_m(k_TSMitGainLearningFreqFc_Hz_f32, D_10MS_SEC_F32, &TSMit_STNegTransGainFilterKSV_Cnt_M_str);

	TSMit_PosTrsmTqGainLongTerm_Uls_M_f32 = Limit_m(
			Rte_Pim_TSMitGainLrn()->PosTransGainLongTerm_HwNmpTransNm_f32,
			-k_TSMitPosTransGainLimit_HwNmpTransNm_f32,
			k_TSMitPosTransGainLimit_HwNmpTransNm_f32
	);
	TSMit_NegTrsmTqGainLongTerm_Uls_M_f32 = Limit_m(
			Rte_Pim_TSMitGainLrn()->NegTransGainLongTerm_HwNmpTransNm_f32,
			-k_TSMitNegTransGainLimit_HwNmpTransNm_f32,
			k_TSMitNegTransGainLimit_HwNmpTransNm_f32
	);

	(void)Rte_Call_TSMitGainLrn_SetRamBlockStatus(TRUE);
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TSMit_GainLearningEnableTimer_mS_M_u32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSMit_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_TSMit_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_TSMit_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_TSMit_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Float Rte_IRead_TSMit_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_TSMit_Per1_PreLimitMtrTrqCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_TSMit_Per1_SrlComABSActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_TSMit_Per1_SrlComESCActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_TSMit_Per1_SrlComTCSActive_Cnt_lgc(void)
 *   Float Rte_IRead_TSMit_Per1_SrlComTransmissionTrq_TransNm_f32(void)
 *   Float Rte_IRead_TSMit_Per1_SrlComYawRate_DegpS_f32(void)
 *   Boolean Rte_IRead_TSMit_Per1_TSMitDefeat_Cnt_lgc(void)
 *   Float Rte_IRead_TSMit_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TSMit_Per1_TSMitCommand_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_TSMit_Per1_TSMitCommand_MtrNm_f32(void)
 *   void Rte_IWrite_TSMit_Per1_TSMitLearningEnabled_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TSMit_Per1_TSMitLearningEnabled_Cnt_lgc(void)
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

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSMit_Per1
 *********************************************************************************************************************/

	VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32;
	VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32;
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) PreLimitMtrTrqCmd_MtrNm_T_f32;
	VAR(boolean, AUTOMATIC) SrlComABSActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SrlComESCActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SrlComTCSActive_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) SrlComTransmissionTrq_TransNm_T_f32;
	VAR(float32, AUTOMATIC) SrlComYawRate_DegpS_T_f32;
	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	VAR(boolean, AUTOMATIC) TSMitDefeat_Cnt_T_lgc;

	VAR(boolean, AUTOMATIC) Disable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DisableLearning_Cnt_T_lgc;

	VAR(float32, AUTOMATIC) HwTorqAbs_HwNm_T_f32;
	VAR(float32, AUTOMATIC) YawRateAbs_DegpS_T_f32;
	VAR(float32, AUTOMATIC) HwPosAbs_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HwVelocityAbs_HwRadpS_T_f32;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(boolean, AUTOMATIC) GainLearningEnableOutput_Cnt_T_lgc;

	VAR(float32, AUTOMATIC) PinionTrqEst_HwNm_T_f32;
	VAR(float32, AUTOMATIC) AbsTransTrq_TransNm_T_f32;
	VAR(float32, AUTOMATIC) PosTransGainLimit_HwNmpTransNm_T_f32;
	VAR(float32, AUTOMATIC) NegTransGainLimit_HwNmpTransNm_T_f32;
	VAR(float32, AUTOMATIC) STPosTransGain_HwNmpTransNm_T_f32;
	VAR(float32, AUTOMATIC) STNegTransGain_HwNmpTransNm_T_f32;

	VAR(uint16, AUTOMATIC) VehicleSpeed_Kph_T_u8p8;
	VAR(sint16, AUTOMATIC) HwPosition_HwDeg_T_s10p5;
	VAR(uint16, AUTOMATIC) CmdScaleFactor_Uls_T_u2p14;
	VAR(float32, AUTOMATIC) CmdScaleFactor_Uls_T_f32;

	VAR(float32, AUTOMATIC) CmdTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) TSMitCommand_HwNm_T_f32;
	VAR(float32, AUTOMATIC) TSMitCommand_MtrNm_T_f32;


	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_TSMit_Per1_CP0_CheckpointReached();

	/*** Store inputs to local copies ***/
	HandwheelAuthority_Uls_T_f32 = Rte_IRead_TSMit_Per1_HandwheelAuthority_Uls_f32();
	HandwheelPosition_HwDeg_T_f32 = Rte_IRead_TSMit_Per1_HandwheelPosition_HwDeg_f32();
	HandwheelVelocity_HwRadpS_T_f32 = Rte_IRead_TSMit_Per1_HandwheelVelocity_HwRadpS_f32();
	HwTorque_HwNm_T_f32 = Rte_IRead_TSMit_Per1_HwTorque_HwNm_f32();
	PreLimitMtrTrqCmd_MtrNm_T_f32 = Rte_IRead_TSMit_Per1_PreLimitMtrTrqCmd_MtrNm_f32();
	SrlComABSActive_Cnt_T_lgc = Rte_IRead_TSMit_Per1_SrlComABSActive_Cnt_lgc();
	SrlComTCSActive_Cnt_T_lgc = Rte_IRead_TSMit_Per1_SrlComTCSActive_Cnt_lgc();
	SrlComESCActive_Cnt_T_lgc = Rte_IRead_TSMit_Per1_SrlComESCActive_Cnt_lgc();
	SrlComTransmissionTrq_TransNm_T_f32 = Rte_IRead_TSMit_Per1_SrlComTransmissionTrq_TransNm_f32();
	SrlComYawRate_DegpS_T_f32 = Rte_IRead_TSMit_Per1_SrlComYawRate_DegpS_f32();
	TSMitDefeat_Cnt_T_lgc = Rte_IRead_TSMit_Per1_TSMitDefeat_Cnt_lgc();
	VehicleSpeed_Kph_T_f32 = Rte_IRead_TSMit_Per1_VehicleSpeed_Kph_f32();


	if (((SrlComABSActive_Cnt_T_lgc == TRUE) && (k_TSMitUseABSActiveFlag_Cnt_lgc == TRUE)) ||
		((SrlComTCSActive_Cnt_T_lgc == TRUE) && (k_TSMitUseTCSActiveFlag_Cnt_lgc == TRUE)) ||
		((SrlComESCActive_Cnt_T_lgc == TRUE) && (k_TSMitUseESCActiveFlag_Cnt_lgc == TRUE)) ||
		(Rte_Pim_TSMitDisableEOL()->FunctionDisable_Cnt_lgc == TRUE) ||
		(TSMitDefeat_Cnt_T_lgc == TRUE))
	{
		Disable_Cnt_T_lgc = TRUE;
	}
	else
	{
		Disable_Cnt_T_lgc = FALSE;
	}

	if ((Rte_Pim_TSMitDisableEOL()->GainLearningDisable_Cnt_lgc == TRUE) || (Disable_Cnt_T_lgc == TRUE))
	{
		DisableLearning_Cnt_T_lgc = TRUE;
	}
	else
	{
		DisableLearning_Cnt_T_lgc = FALSE;
	}


	/*** Learning Enable ***/
	HwTorque_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &TSMit_HwTrqFilterKSV_Cnt_M_str);
	TSMit_HwTqFiltered_HwNm_D_f32 = HwTorque_HwNm_T_f32;

	SrlComYawRate_DegpS_T_f32 = LPF_OpUpdate_f32_m(SrlComYawRate_DegpS_T_f32, &TSMit_YawRateFilterKSV_Cnt_M_str);
	TSMit_YawRateFiltered_DegpS_D_f32 = SrlComYawRate_DegpS_T_f32;

	/**** Learning Enable (Inside other "Learning Enable") ****/
	HwTorqAbs_HwNm_T_f32 = Abs_f32_m(HwTorque_HwNm_T_f32);
	YawRateAbs_DegpS_T_f32 = Abs_f32_m(SrlComYawRate_DegpS_T_f32);
	HwPosAbs_HwDeg_T_f32 = Abs_f32_m(HandwheelPosition_HwDeg_T_f32);
	HwVelocityAbs_HwRadpS_T_f32 = Abs_f32_m(HandwheelVelocity_HwRadpS_T_f32);

	GainLearningEnableOutput_Cnt_T_lgc = FALSE;
	if ((HwTorqAbs_HwNm_T_f32 > k_TSMitMinHwTrqEnable_HwNm_f32) &&
		(HwPosAbs_HwDeg_T_f32 < k_TSMitMaxHwPosEnable_HwDeg_f32) &&
		(YawRateAbs_DegpS_T_f32 < k_TSMitMaxYawRateEnable_DegpS_f32) &&
		(HandwheelAuthority_Uls_T_f32 >= k_TSMitMinHwAuthEnable_Uls_f32) &&
		(VehicleSpeed_Kph_T_f32 >= k_TSMitMinVehSpdEnable_Kph_f32) &&
		(VehicleSpeed_Kph_T_f32 < k_TSMitMaxVehSpdEnable_Kph_f32) &&
		(HwVelocityAbs_HwRadpS_T_f32 < k_TSMitMaxHwVelEnable_HwRadpS_f32) &&
		(DisableLearning_Cnt_T_lgc == FALSE) &&
		((SrlComTransmissionTrq_TransNm_T_f32 < k_TSMitMaxNegTransTrqEnable_TransNm_f32) ||
		 (SrlComTransmissionTrq_TransNm_T_f32 > k_TSMitMinPosTransTrqEnable_TransNm_f32)))
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(TSMit_GainLearningEnableTimer_mS_M_u32, &ElapsedTime_mS_T_u16);

		if (ElapsedTime_mS_T_u16 >= (uint16)(k_TSMitTimeOnEnable_Sec_f32 * D_ONESEC_MS_F32))
		{
			GainLearningEnableOutput_Cnt_T_lgc = TRUE;
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TSMit_GainLearningEnableTimer_mS_M_u32);
	}

	/*** Calculate Gains ***/
	PinionTrqEst_HwNm_T_f32 = HwTorque_HwNm_T_f32 + (PreLimitMtrTrqCmd_MtrNm_T_f32 * -k_CmnSysTrqRatio_HwNmpMtrNm_f32);
	TSMit_PinionTrqEst_HwNm_D_f32 = PinionTrqEst_HwNm_T_f32;

	AbsTransTrq_TransNm_T_f32 = Abs_f32_m(SrlComTransmissionTrq_TransNm_T_f32);

	if ((GainLearningEnableOutput_Cnt_T_lgc == TRUE) &&
		(SrlComTransmissionTrq_TransNm_T_f32 > D_ZERO_ULS_F32))
	{
		/**** Positive Transmission Torque Gain ****/
		LPF_OpUpdate_f32_m(PinionTrqEst_HwNm_T_f32 / AbsTransTrq_TransNm_T_f32, &TSMit_STPosTransGainFilterKSV_Cnt_M_str);
		PosTransGainLimit_HwNmpTransNm_T_f32 = k_TSMitPosTransGainLimit_HwNmpTransNm_f32 - Abs_f32_m(TSMit_PosTrsmTqGainLongTerm_Uls_M_f32);
		TSMit_STPosTransGainFilterKSV_Cnt_M_str.SV_Uls_f32 = Limit_m(
				TSMit_STPosTransGainFilterKSV_Cnt_M_str.SV_Uls_f32,
				-PosTransGainLimit_HwNmpTransNm_T_f32,
				PosTransGainLimit_HwNmpTransNm_T_f32
		);
	}
	STPosTransGain_HwNmpTransNm_T_f32 = TSMit_STPosTransGainFilterKSV_Cnt_M_str.SV_Uls_f32;
	TSMit_PosTransTrqGainShortTerm_HwNmpTransNm_D_f32 = STPosTransGain_HwNmpTransNm_T_f32;

	if ((GainLearningEnableOutput_Cnt_T_lgc == TRUE) &&
		(SrlComTransmissionTrq_TransNm_T_f32 < D_ZERO_ULS_F32) &&
		(k_TSMitDisableNegTransTrqSTGainLearning_Cnt_f32 == TRUE))
	{
		/**** Negative Transmission Torque Gain ****/
		LPF_OpUpdate_f32_m(PinionTrqEst_HwNm_T_f32 / AbsTransTrq_TransNm_T_f32, &TSMit_STNegTransGainFilterKSV_Cnt_M_str);
		NegTransGainLimit_HwNmpTransNm_T_f32 = k_TSMitNegTransGainLimit_HwNmpTransNm_f32 - Abs_f32_m(TSMit_NegTrsmTqGainLongTerm_Uls_M_f32);
		TSMit_STNegTransGainFilterKSV_Cnt_M_str.SV_Uls_f32 = Limit_m(
				TSMit_STNegTransGainFilterKSV_Cnt_M_str.SV_Uls_f32,
				-NegTransGainLimit_HwNmpTransNm_T_f32,
				NegTransGainLimit_HwNmpTransNm_T_f32
		);
	}
	STNegTransGain_HwNmpTransNm_T_f32 = TSMit_STNegTransGainFilterKSV_Cnt_M_str.SV_Uls_f32;
	TSMit_NegTransTrqGainShortTerm_HwNmpTransNm_D_f32 = STNegTransGain_HwNmpTransNm_T_f32;


	/*** Generate Command ***/
	VehicleSpeed_Kph_T_u8p8 = FPM_FloatToFixed_m(VehicleSpeed_Kph_T_f32, u8p8_T);
	HwPosition_HwDeg_T_s10p5 = FPM_FloatToFixed_m(HandwheelPosition_HwDeg_T_f32, s10p5_T);
	CmdScaleFactor_Uls_T_u2p14 = BilinearXYM_u16_s16Xu16YM_Cnt(
			VehicleSpeed_Kph_T_u8p8,
			HwPosition_HwDeg_T_s10p5,
			t_TSMitCmdSclVelocityTbl_Kph_u8p8,
			TableSize_m(t_TSMitCmdSclVelocityTbl_Kph_u8p8),
			t_TSMitCmdSclHwPosTbl_HwDeg_s10p5,
			&t2_TSMitCmdSclScaleFactor_Uls_u2p14[0][0],
			TableSize_m(t_TSMitCmdSclHwPosTbl_HwDeg_s10p5)
	);
	CmdScaleFactor_Uls_T_f32 = FPM_FixedToFloat_m(CmdScaleFactor_Uls_T_u2p14, u2p14_T);
	TSMit_CmdScaleFactor_Uls_D_f32 = CmdScaleFactor_Uls_T_f32;

	if (Disable_Cnt_T_lgc == FALSE)
	{
		/*** Cmd Gen ***/
		if (SrlComTransmissionTrq_TransNm_T_f32 > k_TSMitPosTransTrqThresh_TransNm_f32)
		{
			CmdTrq_HwNm_T_f32 = (STPosTransGain_HwNmpTransNm_T_f32 + TSMit_PosTrsmTqGainLongTerm_Uls_M_f32) * Abs_f32_m(SrlComTransmissionTrq_TransNm_T_f32);
		}
		else if (SrlComTransmissionTrq_TransNm_T_f32 < k_TSMitNegTransTrqThresh_TransNm_f32)
		{
			CmdTrq_HwNm_T_f32 = (STNegTransGain_HwNmpTransNm_T_f32 + TSMit_NegTrsmTqGainLongTerm_Uls_M_f32) * Abs_f32_m(SrlComTransmissionTrq_TransNm_T_f32);
		}
		else
		{
			CmdTrq_HwNm_T_f32 = D_ZERO_ULS_F32;
		}
	}
	else
	{
		CmdTrq_HwNm_T_f32 = D_ZERO_ULS_F32;
	}
	TSMit_CommandRaw_HwNm_D_f32 = CmdTrq_HwNm_T_f32;

	TSMitCommand_HwNm_T_f32 = CmdScaleFactor_Uls_T_f32 * CmdTrq_HwNm_T_f32;
	TSMitCommand_HwNm_T_f32 = Limit_m(
			TSMitCommand_HwNm_T_f32,
			-D_OUTPUTCMDLIMIT_HWNM_F32,
			D_OUTPUTCMDLIMIT_HWNM_F32
	);

	TSMitCommand_HwNm_T_f32 = Limit_m(
			TSMitCommand_HwNm_T_f32,
			(-k_TSMitCmdSlewRate_HwNmpS_f32 * D_10MS_SEC_F32) + TSMit_PrevTSMitCommand_HwNm_M_f32,
			(k_TSMitCmdSlewRate_HwNmpS_f32 * D_10MS_SEC_F32) + TSMit_PrevTSMitCommand_HwNm_M_f32
	);
	TSMit_PrevTSMitCommand_HwNm_M_f32 = TSMitCommand_HwNm_T_f32;

	TSMitCommand_MtrNm_T_f32 = TSMitCommand_HwNm_T_f32 / k_CmnSysTrqRatio_HwNmpMtrNm_f32;

	TSMitCommand_MtrNm_T_f32 = Limit_m(
		TSMitCommand_MtrNm_T_f32,
		-D_OUTPUTCMDLIMIT_HWNM_F32 / k_CmnSysTrqRatio_HwNmpMtrNm_f32,
		D_OUTPUTCMDLIMIT_HWNM_F32 / k_CmnSysTrqRatio_HwNmpMtrNm_f32
	);


	/*** Update Gain Ram Value ***/
	Rte_Pim_TSMitGainLrn()->PosTransGainLongTerm_HwNmpTransNm_f32 = TSMit_PosTrsmTqGainLongTerm_Uls_M_f32 + STPosTransGain_HwNmpTransNm_T_f32;
	TSMit_PosTransTrqGainLongTerm_HwNmpTransNm_D_f32 = Rte_Pim_TSMitGainLrn()->PosTransGainLongTerm_HwNmpTransNm_f32;
	Rte_Pim_TSMitGainLrn()->NegTransGainLongTerm_HwNmpTransNm_f32 = TSMit_NegTrsmTqGainLongTerm_Uls_M_f32 + STNegTransGain_HwNmpTransNm_T_f32;
	TSMit_NegTransTrqGainLongTerm_HwNmpTransNm_D_f32 = Rte_Pim_TSMitGainLrn()->NegTransGainLongTerm_HwNmpTransNm_f32;


	/*** Store local copies to outputs ***/
	Rte_IWrite_TSMit_Per1_TSMitLearningEnabled_Cnt_lgc(GainLearningEnableOutput_Cnt_T_lgc);
	Rte_IWrite_TSMit_Per1_TSMitCommand_MtrNm_f32(TSMitCommand_MtrNm_T_f32);


	/* Configurable End of Runnable Checkpoint */
	Rte_Call_TSMit_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSMit_SCom_GainReset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GainReset> of PortPrototype <TSMit_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_TSMitGainLrn_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_TSMitGainLrn_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TSMit_SCom_GainReset(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_GainReset(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSMit_SCom_GainReset
 *********************************************************************************************************************/

	Rte_Pim_TSMitGainLrn()->PosTransGainLongTerm_HwNmpTransNm_f32 = D_ZERO_ULS_F32;
	TSMit_PosTrsmTqGainLongTerm_Uls_M_f32 = D_ZERO_ULS_F32;
	Rte_Pim_TSMitGainLrn()->NegTransGainLongTerm_HwNmpTransNm_f32 = D_ZERO_ULS_F32;
	TSMit_NegTrsmTqGainLongTerm_Uls_M_f32 = D_ZERO_ULS_F32;
	TSMit_STPosTransGainFilterKSV_Cnt_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
	TSMit_STNegTransGainFilterKSV_Cnt_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
	(void)Rte_Call_TSMitGainLrn_WriteBlock(NULL_PTR);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSMit_SCom_GetFcnDefeat
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetFcnDefeat> of PortPrototype <TSMit_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TSMit_SCom_GetFcnDefeat(Boolean *FunctionDefeat_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_GetFcnDefeat(P2VAR(Boolean, AUTOMATIC, RTE_AP_TSMIT_APPL_VAR) FunctionDefeat_Cnt_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSMit_SCom_GetFcnDefeat
 *********************************************************************************************************************/

	*FunctionDefeat_Cnt_lgc = Rte_Pim_TSMitDisableEOL()->FunctionDisable_Cnt_lgc;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSMit_SCom_GetLongTermGains
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetLongTermGains> of PortPrototype <TSMit_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TSMit_SCom_GetLongTermGains(Float *LTPosTransGain_HwNmpTransNm_f32, Float *LTNegTransGain_HwNmpTransNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_GetLongTermGains(P2VAR(Float, AUTOMATIC, RTE_AP_TSMIT_APPL_VAR) LTPosTransGain_HwNmpTransNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_TSMIT_APPL_VAR) LTNegTransGain_HwNmpTransNm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSMit_SCom_GetLongTermGains
 *********************************************************************************************************************/

	*LTPosTransGain_HwNmpTransNm_f32 = Rte_Pim_TSMitGainLrn()->PosTransGainLongTerm_HwNmpTransNm_f32;
	*LTNegTransGain_HwNmpTransNm_f32 = Rte_Pim_TSMitGainLrn()->NegTransGainLongTerm_HwNmpTransNm_f32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSMit_SCom_GetLrnDefeat
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetLrnDefeat> of PortPrototype <TSMit_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TSMit_SCom_GetLrnDefeat(Boolean *LearningDefeat_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_GetLrnDefeat(P2VAR(Boolean, AUTOMATIC, RTE_AP_TSMIT_APPL_VAR) LearningDefeat_Cnt_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSMit_SCom_GetLrnDefeat
 *********************************************************************************************************************/

	*LearningDefeat_Cnt_lgc = Rte_Pim_TSMitDisableEOL()->GainLearningDisable_Cnt_lgc;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSMit_SCom_SetFcnDefeat
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetFcnDefeat> of PortPrototype <TSMit_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_TSMitDisableEOL_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_TSMitDisableEOL_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TSMit_SCom_SetFcnDefeat(Boolean FunctionDefeat_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_SetFcnDefeat(Boolean FunctionDefeat_Cnt_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSMit_SCom_SetFcnDefeat
 *********************************************************************************************************************/

	Rte_Pim_TSMitDisableEOL()->FunctionDisable_Cnt_lgc = FunctionDefeat_Cnt_lgc;
	(void)Rte_Call_TSMitDisableEOL_WriteBlock(NULL_PTR);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSMit_SCom_SetLongTermGains
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetLongTermGains> of PortPrototype <TSMit_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_TSMitGainLrn_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_TSMitGainLrn_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TSMit_SCom_SetLongTermGains(Float LTPosTransGain_HwNmpTransNm_f32, Float LTNegTransGain_HwNmpTransNm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_SetLongTermGains(Float LTPosTransGain_HwNmpTransNm_f32, Float LTNegTransGain_HwNmpTransNm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSMit_SCom_SetLongTermGains
 *********************************************************************************************************************/

	LTPosTransGain_HwNmpTransNm_f32 = Limit_m(
			LTPosTransGain_HwNmpTransNm_f32,
			-k_TSMitPosTransGainLimit_HwNmpTransNm_f32,
			k_TSMitPosTransGainLimit_HwNmpTransNm_f32
	);
	LTNegTransGain_HwNmpTransNm_f32 = Limit_m(
			LTNegTransGain_HwNmpTransNm_f32,
			-k_TSMitNegTransGainLimit_HwNmpTransNm_f32,
			k_TSMitNegTransGainLimit_HwNmpTransNm_f32
	);
	Rte_Pim_TSMitGainLrn()->PosTransGainLongTerm_HwNmpTransNm_f32 = LTPosTransGain_HwNmpTransNm_f32;
	Rte_Pim_TSMitGainLrn()->NegTransGainLongTerm_HwNmpTransNm_f32 = LTNegTransGain_HwNmpTransNm_f32;
	TSMit_PosTrsmTqGainLongTerm_Uls_M_f32 = LTPosTransGain_HwNmpTransNm_f32;
	TSMit_NegTrsmTqGainLongTerm_Uls_M_f32 = LTNegTransGain_HwNmpTransNm_f32;
	(void)Rte_Call_TSMitGainLrn_WriteBlock(NULL_PTR);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSMit_SCom_SetLrnDefeat
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetLrnDefeat> of PortPrototype <TSMit_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_TSMitDisableEOL_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_TSMitDisableEOL_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TSMit_SCom_SetLrnDefeat(Boolean LearningDefeat_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_SetLrnDefeat(Boolean LearningDefeat_Cnt_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TSMit_SCom_SetLrnDefeat
 *********************************************************************************************************************/

	Rte_Pim_TSMitDisableEOL()->GainLearningDisable_Cnt_lgc = LearningDefeat_Cnt_lgc;
	(void)Rte_Call_TSMitDisableEOL_WriteBlock(NULL_PTR);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_TSMIT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
