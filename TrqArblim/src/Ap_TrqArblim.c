/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_TrqArblim.c
 *     Workspace:  C:/SynergyWorkArea/Working/TrqArblim/autosar
 *     SW-C Type:  Ap_TrqArblim
 *  Generated at:  Mon Nov 14 10:12:50 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_TrqArblim>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2016 Nexteer
* Nexteer Confidential
*
* Module File Name: Ap_TrqArblim.c
* Module Description: Implementation of CF10
* Project           : CBD
* Author            : Selva Sengottaiyan
*****************************************************************************
* Version Control:
 * Date Created:      Fri Aug 15 14:23:51 2014
 * %version:          EA3#12 %
 * %derived_by:       czmgrw %
 * %date_modified:    Wed Aug 15 15:15:18 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 01/20/14  1        Selva     Initial version                                                              10960
 * 04/14/14  2        Selva     A6345 fixes + fixes for UTP                                                  11747
 * 05/02/14  3        Jared     Changed units on PosServoCmd from HwNm to MtrNm as per A6682                 11857
 * 07/16/14  4        SB        Implemented CF-10 GM Torque Arbitrator v002 								 12180
 * 08/15/14  5        SB		A7189 - Global output not range limited										 12331
 * 10/15/14	 6		  SB		Implemented CF-10 GM Torque Arbitrator v003									 12541
 * 02/03/16  7        JK        Implemented CF-10 GM Torque Arbitrator v004                               EA3#5903
 * 02/05/16  8        JK        Implemented CF-10 GM Torque Arbitrator v005                               EA3#5968
 * 02/11/16  9        JK        Implemented CF-10 GM Torque Arbitrator v007                               EA3#6073
 * 06/22/16 10        NS        Implemented CF-10 GM Torque Arbitrator v008							      EA3#8966
 * 								(Changes made as per FDD v004 ,v005,v006 are excluded)
 * 08/31/16  11       JK        Implemented CF-10 GM Torque Arbitrator v010                              EA3#10509
 * 11/14/16  12       JK        Implemented CF-10 GM Torque Arbitrator v011                              EA3#12348
 * 11/17/16  13       JK        Corrected common vehspd cal name                                         EA3#12667
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_TrqArblim.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_TrqArblim_Cfg.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "filters.h"
#include "Interpolation.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include <float.h>

/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */

/* PRQA S 4395 EOF
* MISRA-C: 2004 Rule 10.4: This deviation is required for library macros.The rule is suppressed for the entire file */

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

/* MISRA-C:2004 Rule 11.4 : Deviation required for Bilinear interpolation table values .The rule is suppressed at each occurrence. */

#define D_DSRTRQLMT_HWNM_F32       6.0F
#define D_OPTRQOVLMT_MTRNM_F32     8.8F
#define D_FINALSLEWLMT_NMPSEC_F32  3.0F
#define D_LKAOUTPOVRLLIM_MTRNM_F32 0.0F

#define TRQARBLIM_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(float32, AUTOMATIC) TrqArblim_LKADesired_HwNm_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) TrqArblim_FinalSlew_NmpSec_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) TrqArblim_APASmoothing_Uls_D_f32;/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) TrqArblim_PreLKATrqReq_HwNm_M_f32;/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) TrqArblim_APADisableRate_Uls_M_f32;/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) TrqArblim_PosSrvoCmd_MtrNm_M_f32;/* PRQA S 3218 */
#define TRQARBLIM_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define TRQARBLIM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AUTOMATIC) TrqArblim_HwTorqueSV_HwNm_M_Str;
STATIC VAR(ESC_State_enum, AUTOMATIC) TrqArblim_ESC_State_Cnt_M_enum;/* PRQA S 3218 */
#define TRQARBLIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

STATIC INLINE FUNC(float32, TRQARBLIM_APPL_CODE) CalcSlewRate( VAR(float32, AUTOMATIC) MaxSecVehSpd_Kph_T_f32);

STATIC INLINE FUNC(void, TRQARBLIM_APPL_CODE) DtrmnDDFactor( VAR(float32, AUTOMATIC) Scalefactor_Uls_T_f32,
																P2VAR(float32, AUTOMATIC, AUTOMATIC) AssistDDFactor_Uls_T_f32,
																P2VAR(float32, AUTOMATIC, AUTOMATIC) ReturnDDFactor_Uls_T_f32,
																P2VAR(float32, AUTOMATIC, AUTOMATIC) DampingDDFactor_Uls_T_f32);
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
 *
 * Enumeration Types:
 * ==================
 * ESC_State_enum: Enumeration of integer in interval [0...4] with enumerators
 *   ESC_Inactive (0u)
 *   ESC_Active (1u)
 *   ESC_TemporarilyLimited (2u)
 *   ESC_PermanentlyFailed (3u)
 *   ESC_ManufacturingDisable (4u)
 * FltInjectionLocType: Enumeration of integer in interval [0...255] with enumerators
 *   FLTINJ_ASSIST (1u)
 *   FLTINJ_RETURN (2u)
 *   FLTINJ_DAMPING (3u)
 *   FLTINJ_ASSTSUMNLMT (4u)
 *   FLTINJ_AVGFRICLRN (7u)
 *   FLTINJ_VECU_BATTERYVOLTAGE (8u)
 *   FLTINJ_HYSTCOMP (12u)
 *   FLTINJ_INERTIACOMP (14u)
 *   FLTINJ_SUPPPWRLMT_CUSTPL (25u)
 *   FLTINJ_EOTDAMPING_ETDMPFW (27u)
 *   FLTINJ_STABILITYCOMP (29u)
 *   FLTINJ_TRQBASEDINRTCOMP (30u)
 *   FLTINJ_SRLCOMVEHSPD_SGNLCOND (33u)
 *   FLTINJ_ASSTFIREWALL (34u)
 *   FLTINJ_ASSTEOTGAIN_LMTCOD (38u)
 *   FLTINJ_DIGHWTRQSENT_T1FAULT (41u)
 *   FLTINJ_DIGHWTRQSENT_T2FAULT (42u)
 *   FLTINJ_TRQOSC_PREFINALCOMMAND (43u)
 *   FLTINJ_GCCDIAG_HWTRQ (46u)
 *   FLTINJ_TRQOVLSTA_LKAFAULT (91u)
 *   FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND (100u)
 *   FLTINJ_TRQARBLIM_LKACMD (101u)
 *   FLTINJ_GCCDIAG_VEHSPD (146u)
 *   FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150u)
 *   FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151u)
 *   FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152u)
 *   FLTINJ_OUTPUTRAMPMULT_LMTCOD (153u)
 *   FLTINJ_ASSTEOTLIMIT_LMTCOD (154u)
 *   FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND (155u)
 *   FLTINJ_ANAHWTORQUE (156u)
 *   FLTINJ_MTRVEL (160u)
 *   FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD (200u)
 *   FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR (201u)
 *   FLTINJ_GCCDIAG_MTRTRQ (246u)
 *   FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND (255u)
 * LKA_State_enum: Enumeration of integer in interval [0...4] with enumerators
 *   LKA_Inactive (0u)
 *   LKA_Active (1u)
 *   LKA_TemporarilyLimited (2u)
 *   LKA_PermanentlyFailed (3u)
 *   LKA_ManufacturingDisable (4u)
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
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_TRQARBLIM_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqArblim_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQARBLIM_APPL_CODE) TrqArblim_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqArblim_Init
 *********************************************************************************************************************/

	LPF_Init_f32_m(D_ZERO_ULS_F32, k_APASmoothHwTrqLPFKn_Hz_f32, D_2MS_SEC_F32, &TrqArblim_HwTorqueSV_HwNm_M_Str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqArblim_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF, WARMINIT, DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_TrqArblim_Per1_ESCCmd_HwNm_f32(void)
 *   ESC_State_enum Rte_IRead_TrqArblim_Per1_ESCState_State_enum(void)
 *   Float Rte_IRead_TrqArblim_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_TrqArblim_Per1_LKACmd_HwNm_f32(void)
 *   LKA_State_enum Rte_IRead_TrqArblim_Per1_LKAState_State_enum(void)
 *   Float Rte_IRead_TrqArblim_Per1_MaxSecureVehicleSpeed_Kph_f32(void)
 *   Boolean Rte_IRead_TrqArblim_Per1_PosServEnable_Cnt_lgc(void)
 *   Float Rte_IRead_TrqArblim_Per1_PosSrvoCmd_MtrNm_f32(void)
 *   Float Rte_IRead_TrqArblim_Per1_TrqOscCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_TrqArblim_Per1_TrqOscEnable_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TrqArblim_Per1_AssistDDFactor_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_TrqArblim_Per1_AssistDDFactor_Uls_f32(void)
 *   void Rte_IWrite_TrqArblim_Per1_DampingDDFactor_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_TrqArblim_Per1_DampingDDFactor_Uls_f32(void)
 *   void Rte_IWrite_TrqArblim_Per1_ESCIsLimited_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TrqArblim_Per1_ESCIsLimited_Cnt_lgc(void)
 *   void Rte_IWrite_TrqArblim_Per1_ESCTorqueDelivered_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_TrqArblim_Per1_ESCTorqueDelivered_HwNm_f32(void)
 *   void Rte_IWrite_TrqArblim_Per1_IqTrqOv_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_TrqArblim_Per1_IqTrqOv_HwNm_f32(void)
 *   void Rte_IWrite_TrqArblim_Per1_LKATorqueDelivered_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_TrqArblim_Per1_LKATorqueDelivered_HwNm_f32(void)
 *   void Rte_IWrite_TrqArblim_Per1_OpTrqOv_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_TrqArblim_Per1_OpTrqOv_MtrNm_f32(void)
 *   void Rte_IWrite_TrqArblim_Per1_PullCmpCustLrngDi_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TrqArblim_Per1_PullCmpCustLrngDi_Cnt_lgc(void)
 *   void Rte_IWrite_TrqArblim_Per1_ReturnDDFactor_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_TrqArblim_Per1_ReturnDDFactor_Uls_f32(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQARBLIM_APPL_CODE) TrqArblim_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqArblim_Per1
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) LKACmd_HwNm_T_f32;
	VAR(LKA_State_enum, AUTOMATIC) LKA_State_T_enum;
	VAR(float32, AUTOMATIC) ESCCmd_HwNm_T_f32;
	VAR(ESC_State_enum, AUTOMATIC) ESC_State_T_enum;
	VAR(float32, AUTOMATIC) MaxSecVehSpd_Kph_T_f32;
	VAR(float32, AUTOMATIC) LKADesired_HwNm_T_f32;
	VAR(float32, AUTOMATIC) FinalSlew_NmpSec_T_f32;
	VAR(float32, AUTOMATIC) LKATrqReq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) LKATrqDel_HwNm_T_f32;
	VAR(float32, AUTOMATIC) ESCTrqReq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) ESCTrqDel_HwNm_T_f32;
	VAR(boolean, AUTOMATIC) ESCIsLimited_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) TrqOscEnable_Cnt_lgc;
    VAR(boolean, AUTOMATIC) PullCmpCustLrngDi_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PosServEnable_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) PosSrvoCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) TrqOscCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) HwTrqFilt_HwNm_T_f32;
	VAR(float32, AUTOMATIC) APAlowDisableRate_pSec_T_f32;
	VAR(float32, AUTOMATIC) APADisableRate_Uls_T_f32;
	VAR(float32, AUTOMATIC) APASmoothing_Uls_T_f32;
	VAR(float32, AUTOMATIC) Scalefactor_Uls_T_f32;
	VAR(float32, AUTOMATIC) APAOverlayCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) IqTrqOv_HwNm_T_f32;
	VAR(float32, AUTOMATIC) OpTrqOv_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) AssistDDFactor_Uls_T_f32;
	VAR(float32, AUTOMATIC) ReturnDDFactor_Uls_T_f32;
	VAR(float32, AUTOMATIC) DampingDDFactor_Uls_T_f32;
	VAR(uint16, AUTOMATIC) HwTrqFilt_HwNm_T_u4p12;
	VAR(uint16, AUTOMATIC) APAlowDisableRate_pSec_T_u7p9;
	VAR(uint16, AUTOMATIC) APASmoothing_Uls_T_u2p14;
	VAR(uint16, AUTOMATIC) APADisableRate_Uls_T_u2p14;
	VAR(uint16, AUTOMATIC) MaxSecVehSpd_Kph_T_u9p7;
	VAR(uint16, AUTOMATIC) LKATrqReq_HwNm_T_u8p8;
	VAR(uint16, AUTOMATIC) LKAOutpTrqReq_MtrNm_T_u8p8;
	VAR(float32, AUTOMATIC) LKAOutpTrqReq_MtrNm_T_f32;
	VAR(sint32, AUTOMATIC) LKATrqReqSign_Uls_s32;

	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_TrqArblim_Per1_CP0_CheckpointReached();

	/* Read inputs */
	LKACmd_HwNm_T_f32 = Rte_IRead_TrqArblim_Per1_LKACmd_HwNm_f32();
	LKA_State_T_enum = Rte_IRead_TrqArblim_Per1_LKAState_State_enum();
	ESCCmd_HwNm_T_f32 = Rte_IRead_TrqArblim_Per1_ESCCmd_HwNm_f32();
	ESC_State_T_enum = Rte_IRead_TrqArblim_Per1_ESCState_State_enum();

	MaxSecVehSpd_Kph_T_f32 = Rte_IRead_TrqArblim_Per1_MaxSecureVehicleSpeed_Kph_f32();
	PosServEnable_Cnt_T_lgc = Rte_IRead_TrqArblim_Per1_PosServEnable_Cnt_lgc();
	PosSrvoCmd_MtrNm_T_f32 = Rte_IRead_TrqArblim_Per1_PosSrvoCmd_MtrNm_f32();
	HwTorque_HwNm_T_f32 = Rte_IRead_TrqArblim_Per1_HwTorque_HwNm_f32();
	TrqOscCmd_MtrNm_T_f32 = Rte_IRead_TrqArblim_Per1_TrqOscCmd_MtrNm_f32();
    TrqOscEnable_Cnt_lgc = Rte_IRead_TrqArblim_Per1_TrqOscEnable_Cnt_lgc();

	/* POS Servo Smoothed Ramp */

	HwTrqFilt_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &TrqArblim_HwTorqueSV_HwNm_M_Str);

	HwTrqFilt_HwNm_T_u4p12 = FPM_FloatToFixed_m((Abs_f32_m(HwTrqFilt_HwNm_T_f32)), u4p12_T);

	APAlowDisableRate_pSec_T_u7p9 = IntplVarXY_u16_u16Xu16Y_Cnt( t_APADisableRateX_HwNm_u4p12,
																	t_APADisableRateY_pSec_u7p9,
																	TableSize_m(t_APADisableRateX_HwNm_u4p12),
																	HwTrqFilt_HwNm_T_u4p12);

	APAlowDisableRate_pSec_T_f32 = (FPM_FixedToFloat_m(APAlowDisableRate_pSec_T_u7p9,u7p9_T)) * -D_ONE_ULS_F32;

	/** APA state ***/
	if (APAlowDisableRate_pSec_T_f32 >= -0.2F)
	{
		APAlowDisableRate_pSec_T_f32 = -0.2F;
	}

	if (PosServEnable_Cnt_T_lgc == TRUE)
	{
		APADisableRate_Uls_T_f32 = Limit_m(D_ONE_ULS_F32, ((D_2MS_SEC_F32 * APAlowDisableRate_pSec_T_f32) + TrqArblim_APADisableRate_Uls_M_f32), ((D_2MS_SEC_F32 * k_APAEnableRate_pSec_f32)+ TrqArblim_APADisableRate_Uls_M_f32));
		TrqArblim_PosSrvoCmd_MtrNm_M_f32 = PosSrvoCmd_MtrNm_T_f32;
	}
	else
	{
		APADisableRate_Uls_T_f32 = Limit_m(D_ZERO_ULS_F32, ((D_2MS_SEC_F32 * APAlowDisableRate_pSec_T_f32) + TrqArblim_APADisableRate_Uls_M_f32), ((D_2MS_SEC_F32 * k_APAEnableRate_pSec_f32)+ TrqArblim_APADisableRate_Uls_M_f32));
	}

	TrqArblim_APADisableRate_Uls_M_f32 = APADisableRate_Uls_T_f32;

	APADisableRate_Uls_T_u2p14 = FPM_FloatToFixed_m(APADisableRate_Uls_T_f32,u2p14_T);
	APASmoothing_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt( t_APASmoothX_Uls_u2p14,
																	t_APASmoothY_Uls_u2p14,
																	TableSize_m(t_APASmoothX_Uls_u2p14),
																	APADisableRate_Uls_T_u2p14);

	APASmoothing_Uls_T_f32 = FPM_FixedToFloat_m(APASmoothing_Uls_T_u2p14, u2p14_T);

	APASmoothing_Uls_T_f32 = APASmoothing_Uls_T_f32 * APADisableRate_Uls_T_f32;
	TrqArblim_APASmoothing_Uls_D_f32 = APASmoothing_Uls_T_f32;

	Scalefactor_Uls_T_f32 = D_ONE_ULS_F32 - APASmoothing_Uls_T_f32;

	APAOverlayCmd_MtrNm_T_f32 = TrqArblim_PosSrvoCmd_MtrNm_M_f32 * APASmoothing_Uls_T_f32;

	if (TrqOscEnable_Cnt_lgc == TRUE)
	{
	   OpTrqOv_MtrNm_T_f32 = TrqOscCmd_MtrNm_T_f32 + APAOverlayCmd_MtrNm_T_f32;
	}
	else
	{
		OpTrqOv_MtrNm_T_f32 =  APAOverlayCmd_MtrNm_T_f32;
	}

	/* To determine DD factors for Assist,Return and Damping */
	DtrmnDDFactor(Scalefactor_Uls_T_f32,&AssistDDFactor_Uls_T_f32,&ReturnDDFactor_Uls_T_f32,&DampingDDFactor_Uls_T_f32);

	#if (STD_ON == BC_TRQARBLIM_FAULTINJECTIONPOINT)
		(void)Rte_Call_FaultInjection_SCom_FltInjection(&LKACmd_HwNm_T_f32,FLTINJ_TRQARBLIM_LKACMD);
	#endif

	/* The state does not equal "Active" OR if position control is active, then the desired value shall be 0,
		  else, the desired value shall be the request, limited to 3 Nm */

	if ((LKA_State_T_enum != LKA_Active) ||
		((TrqOscEnable_Cnt_lgc == TRUE) ||
		(PosServEnable_Cnt_T_lgc == TRUE)))
	{
		LKADesired_HwNm_T_f32 = D_ZERO_ULS_F32;
	}
	else
	{
		LKADesired_HwNm_T_f32 = Limit_m(LKACmd_HwNm_T_f32, -k_GmTqArbn_LKA_OutputLim_HwNm_f32, k_GmTqArbn_LKA_OutputLim_HwNm_f32);
		LKADesired_HwNm_T_f32 = Limit_m(LKADesired_HwNm_T_f32, -D_DSRTRQLMT_HWNM_F32, D_DSRTRQLMT_HWNM_F32);
	}

	TrqArblim_LKADesired_HwNm_D_f32 = LKADesired_HwNm_T_f32;

	if (LKA_State_T_enum == LKA_Active)
	{
		PullCmpCustLrngDi_Cnt_T_lgc = TRUE;
	}
	else
	{
		PullCmpCustLrngDi_Cnt_T_lgc = FALSE;
	}

	/*
		  Ramp to the desired value according to either the VDTOM (Velocity Dependant Torque Overlay Metric):
		  dT/dt <= ( -7 / 120 [Nm / kph-s] ) * ( VehSpd [kph] ) + 13.5 [Nm / s]
		  or a calibrated lookup table of vehicle speed dependent slew rate.
	*/

	/* Ramp_to_Value - Calculating Slew rate */
	FinalSlew_NmpSec_T_f32 = CalcSlewRate(MaxSecVehSpd_Kph_T_f32);

	TrqArblim_FinalSlew_NmpSec_D_f32 = FinalSlew_NmpSec_T_f32;

	LKATrqReq_HwNm_T_f32 = Limit_m(LKADesired_HwNm_T_f32, ((D_2MS_SEC_F32 * -FinalSlew_NmpSec_T_f32) + TrqArblim_PreLKATrqReq_HwNm_M_f32), ((D_2MS_SEC_F32 * FinalSlew_NmpSec_T_f32)+ TrqArblim_PreLKATrqReq_HwNm_M_f32));
	TrqArblim_PreLKATrqReq_HwNm_M_f32 = LKATrqReq_HwNm_T_f32;

	/* LKA Output Torque */
	MaxSecVehSpd_Kph_T_u9p7 = FPM_FloatToFixed_m(MaxSecVehSpd_Kph_T_f32,u9p7_T);
	LKATrqReq_HwNm_T_u8p8 = FPM_FloatToFixed_m(Abs_f32_m(LKATrqReq_HwNm_T_f32),u8p8_T);
	LKATrqReqSign_Uls_s32 = Sign_f32_m(LKATrqReq_HwNm_T_f32);

	/* PRQA S 310  L1 */
	LKAOutpTrqReq_MtrNm_T_u8p8 = BilinearXMYM_u16_u16XMu16YM_Cnt(MaxSecVehSpd_Kph_T_u9p7,
															LKATrqReq_HwNm_T_u8p8,
															t_CmnVehSpd_Kph_u9p7,
															TableSize_m(t_CmnVehSpd_Kph_u9p7),
															(P2CONST(uint16, AUTOMATIC, AP_TRQARBLIM_CONST))t2_GmTqArbn_LKAOutpOvrlX_HwNm_u8p8,
															(P2CONST(uint16, AUTOMATIC, AP_TRQARBLIM_CONST))t2_GmTqArbn_LKAOutpOvrlY_MtrNm_u8p8,
															TableSize_m(t2_GmTqArbn_LKAOutpOvrlX_HwNm_u8p8[0]));
	/* PRQA L:L1 */

	LKAOutpTrqReq_MtrNm_T_f32 = FPM_FixedToFloat_m(LKAOutpTrqReq_MtrNm_T_u8p8,u8p8_T);
	LKAOutpTrqReq_MtrNm_T_f32 = Limit_m(LKAOutpTrqReq_MtrNm_T_f32,D_LKAOUTPOVRLLIM_MTRNM_F32,k_GmTqArbn_LKAOutpOvrlUpprLim_MtrNm_f32);
	LKAOutpTrqReq_MtrNm_T_f32 = LKAOutpTrqReq_MtrNm_T_f32 * (float32)LKATrqReqSign_Uls_s32;
	OpTrqOv_MtrNm_T_f32 = OpTrqOv_MtrNm_T_f32 + LKAOutpTrqReq_MtrNm_T_f32;

	/* ESC logic */
	TrqArblim_ESC_State_Cnt_M_enum = ESC_State_T_enum;
	if((ESC_State_T_enum != ESC_Active)&&(ESC_State_T_enum != ESC_TemporarilyLimited))
	{
		ESCCmd_HwNm_T_f32 = D_ZERO_ULS_F32;
	}

	ESCTrqReq_HwNm_T_f32 = Limit_m(ESCCmd_HwNm_T_f32, (-k_ESCMax_HwNm_f32), k_ESCMax_HwNm_f32);

	if(Abs_f32_m(ESCCmd_HwNm_T_f32) > k_ESCMax_HwNm_f32)
	{
		ESCIsLimited_Cnt_T_lgc = TRUE;
	}
	else
	{
		ESCIsLimited_Cnt_T_lgc = FALSE;
	}

	/* CAN Conditioning */
	if((TrqArblim_ESC_State_Cnt_M_enum == ESC_Active)||(TrqArblim_ESC_State_Cnt_M_enum == ESC_TemporarilyLimited))
	{
		LKATrqDel_HwNm_T_f32 = D_ZERO_ULS_F32;
		ESCTrqDel_HwNm_T_f32 = ESCTrqReq_HwNm_T_f32;
	}
	else
	{
		LKATrqDel_HwNm_T_f32 = LKATrqReq_HwNm_T_f32;
		ESCTrqDel_HwNm_T_f32 = D_ZERO_ULS_F32;
	}

	IqTrqOv_HwNm_T_f32 = (LKATrqDel_HwNm_T_f32 * k_GmTqArbn_LKAScagGain_Uls_f32) + ESCTrqDel_HwNm_T_f32;
	IqTrqOv_HwNm_T_f32 = Limit_m(IqTrqOv_HwNm_T_f32, -D_DSRTRQLMT_HWNM_F32, D_DSRTRQLMT_HWNM_F32);
	
	AssistDDFactor_Uls_T_f32 = Limit_m(AssistDDFactor_Uls_T_f32, D_ZERO_ULS_F32, D_ONE_ULS_F32);
	DampingDDFactor_Uls_T_f32 = Limit_m(DampingDDFactor_Uls_T_f32, D_ZERO_ULS_F32, D_ONE_ULS_F32);
	ReturnDDFactor_Uls_T_f32 = Limit_m(ReturnDDFactor_Uls_T_f32, D_ZERO_ULS_F32, D_ONE_ULS_F32);
	OpTrqOv_MtrNm_T_f32 = Limit_m(OpTrqOv_MtrNm_T_f32,-D_OPTRQOVLMT_MTRNM_F32, D_OPTRQOVLMT_MTRNM_F32);

	/* Write outputs */
	(void) Rte_IWrite_TrqArblim_Per1_IqTrqOv_HwNm_f32 (IqTrqOv_HwNm_T_f32);
	(void) Rte_IWrite_TrqArblim_Per1_LKATorqueDelivered_HwNm_f32(LKATrqDel_HwNm_T_f32);
	(void) Rte_IWrite_TrqArblim_Per1_ESCTorqueDelivered_HwNm_f32(ESCTrqDel_HwNm_T_f32);
	(void) Rte_IWrite_TrqArblim_Per1_ESCIsLimited_Cnt_lgc(ESCIsLimited_Cnt_T_lgc);
	(void) Rte_IWrite_TrqArblim_Per1_AssistDDFactor_Uls_f32(AssistDDFactor_Uls_T_f32);
	(void) Rte_IWrite_TrqArblim_Per1_DampingDDFactor_Uls_f32(DampingDDFactor_Uls_T_f32);
	(void) Rte_IWrite_TrqArblim_Per1_OpTrqOv_MtrNm_f32(OpTrqOv_MtrNm_T_f32);
	(void) Rte_IWrite_TrqArblim_Per1_ReturnDDFactor_Uls_f32(ReturnDDFactor_Uls_T_f32);
	(void)Rte_IWrite_TrqArblim_Per1_PullCmpCustLrngDi_Cnt_lgc(PullCmpCustLrngDi_Cnt_T_lgc);

	/* Configurable End of Runnable Checkpoint */
	Rte_Call_TrqArblim_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_TRQARBLIM_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
  * Name:        CalcSlewRate
  * Description: Created for calculating final slew rate
  * Inputs:      MaxSecVehSpd_Kph_T_f32   - Max Secure Vehicle Speed
  * Outputs:     FinalSlew_NmpSec_T_f32   - Final Slew rate
  *
*****************************************************************************/
STATIC INLINE FUNC(float32, TRQARBLIM_APPL_CODE) CalcSlewRate( VAR(float32, AUTOMATIC) MaxSecVehSpd_Kph_T_f32)
{
	VAR(float32, AUTOMATIC) FinalSlew_NmpSec_T_f32;

	if (k_LKAUseSlewCal_lgc == FALSE)
	{
		/* VDTOM */
		FinalSlew_NmpSec_T_f32 = ((-0.05833F * MaxSecVehSpd_Kph_T_f32) + 13.5F);
	}
	else
	{
		/* Calculate calibrate slew */
		FinalSlew_NmpSec_T_f32 =  FPM_FixedToFloat_m((IntplVarXY_u16_u16Xu16Y_Cnt(t_LKASlewX_Kph_u8p8,
																t_LKASlewY_NmpSec_u4p12,
																TableSize_m(t_LKASlewX_Kph_u8p8),
																FPM_FloatToFixed_m(MaxSecVehSpd_Kph_T_f32,u8p8_T))), u4p12_T);
	}

	if (FinalSlew_NmpSec_T_f32 < D_FINALSLEWLMT_NMPSEC_F32)
	{
		FinalSlew_NmpSec_T_f32 = D_FINALSLEWLMT_NMPSEC_F32;
	}

	return FinalSlew_NmpSec_T_f32;
}

/********************************************************************************
  * Name:        DtrmnDDFactor
  * Description: Created for determining DD factor for Assist,Return and Damping
  * Inputs:      Scalefactor_Uls_T_f32   - Scale factor
  *              APAScale_Cnt_T_lgc      - Corresponding APA use scale
  * Outputs:     None
  *
*********************************************************************************/
STATIC INLINE FUNC(void, TRQARBLIM_APPL_CODE) DtrmnDDFactor( VAR(float32, AUTOMATIC) Scalefactor_Uls_T_f32,
																P2VAR(float32, AUTOMATIC, AUTOMATIC) AssistDDFactor_Uls_T_f32,
																P2VAR(float32, AUTOMATIC, AUTOMATIC) ReturnDDFactor_Uls_T_f32,
																P2VAR(float32, AUTOMATIC, AUTOMATIC) DampingDDFactor_Uls_T_f32)
{

	if (k_APAUseAsstScale_lgc == TRUE)
	{
		*AssistDDFactor_Uls_T_f32 =  Scalefactor_Uls_T_f32;
	}
	else
	{
		*AssistDDFactor_Uls_T_f32 = D_ONE_ULS_F32;
	}

	if (k_APAUseRetScale_lgc == TRUE)
	{
		*ReturnDDFactor_Uls_T_f32 =  Scalefactor_Uls_T_f32;
	}
	else
	{
		*ReturnDDFactor_Uls_T_f32 = D_ONE_ULS_F32;
	}

	if (k_APAUseADmpScale_lgc == TRUE)
	{
		*DampingDDFactor_Uls_T_f32 =  Scalefactor_Uls_T_f32;
	}
	else
	{
		*DampingDDFactor_Uls_T_f32 = D_ONE_ULS_F32;
	}

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
