/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EPS_DiagSrvcs_ISO.Interface.h file
* Module Description: Common Manufacturing Program Interface for XCP and ISO services
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
* Notes:
* This file contains the configurations for the ISO services. It should be
* modified for each program as needed.
*
*****************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          EA3#7 %
 * %derived_by:       fz9hxm %
 * %date_modified:    Fri Oct  4 15:01:08 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 02/23/16  3        GMN       Added new variable and function declarations needed at appdesc.c file
 * 05/23/16  4        GMN       Added handwheel torque variables
 * 03/20/17  7        CP        Added MtrCurrQaxRef and IoHwAbstractionUsr_Batt_Volt
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>		                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "fpmtype.h"
#include "Compiler.h"
#include "Rte_Type.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>   		      		    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#ifndef RTE_GLOBALDATA_H
#define RTE_GLOBALDATA_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>   		  	    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* Used services, such as appdesc */
extern VAR(uint8, RTE_VAR_NOINIT) Rte_CustPerSrvcs_ThermalLimitFlagCntr_Cnt_u08;
extern VAR(uint8, RTE_VAR_NOINIT) Rte_TrqOvlSta_LKAState_State_enum;
extern VAR(uint8, RTE_VAR_NOINIT) Rte_TrqOvlSta_APAState_State_enum;
extern VAR(boolean, RTE_VAR_NOINIT) CDD_DisableHSBusNormComm_Cnt_lgc;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_Ap_LrnEOT_CCWFound_Cnt_lgc;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_Ap_LrnEOT_CWFound_Cnt_lgc;
extern VAR(boolean, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_DiagMgr_DiagStsDefVehSpd_Cnt_lgc;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_DigColPs_TrimComp_Cnt_lgc;
extern VAR(boolean, RTE_VAR_INIT) Rte_Sa_DigHwTrqSENT_SrlComHwTrqValid_Cnt_lgc;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_SrlComInput_SrlComEngOn_Cnt_lgc;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_SrlComInput_VehicleSpeedValid_Cnt_lgc;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_DiagMgr_DiagRmpToZeroActive_Cnt_lgc;
extern VAR(uint16, RTE_VAR_NOINIT) Rte_SrlComInput_DesiredTunPers_Cnt_u16;
extern VAR(uint16, RTE_VAR_NOINIT) Rte_SrlComInput_DriverModeCtrlState_Cnt_u16;
extern VAR(uint16, RTE_VAR_NOINIT) Rte_SrlComInput_TrannyPlatfShftStatus_Cnt_u16;
extern VAR(uint16, RTE_VAR_NOINIT) Rte_Ap_TuningSelAuth_ActiveTunPers_Cnt_u16;
extern VAR(uint16, RTE_VAR_NOINIT) Rte_Ap_TuningSelAuth_ActiveTunPers_Cnt_u16;
extern VAR(float32, RTE_VAR_NOINIT)Rte_SrlComInput_LKACmd_HwNm_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_SrlComInput_SWARTrgtAngRequest_HwDeg_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_Ap_LrnEOT_CWPosition_HwDeg_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_Ap_LrnEOT_CCWPosition_HwDeg_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_CurrCmd_MtrCurrDaxRef_Amp_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_CurrCmd_MtrCurrQaxRef_Amp_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_Ap_BattVltg_BrdgVltg_Volt_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_IoHwAbstractionUsr_Batt_Volt_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_CtrlTemp_FiltMeasTemp_DegC_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_DigColPs_I2CHwAbsPos_HwDeg_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_SrlComInput_SrlComVehSpd_Kph_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_Ap_AstLmt_SumLimTrqCmd_MtrNm_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_PeakCurrEst_EstPkCurr_AmpSq_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_SrlComInput_SrlComEngineSpeed_Rpm_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_SignlCondn_VehicleSpeed_Kph_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_HwTrqArb_HwTrq_HwNm_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_AbsHwPosScom_HwPos_HwDeg_f32;
extern VAR(float32, RTE_VAR_NOINIT) Rte_BatteryVoltage_Vecu_Volt_f32;
extern VAR(float32, RTE_VAR_INIT) Rte_DigHwTrq_DigHwTrq_HwNm_f32;
extern VAR(float32, RTE_VAR_INIT) Rte_Sa_DigHwTrqSENT_SrlComHwTrq_HwNm_f32;
extern VAR(float32, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
extern VAR(SysPwrMd, RTE_VAR_NOINIT) Rte_SrlComInput_SrlComSysPwrMd_Cnt_enum;
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;
extern VAR(float32, RTE_VAR_NOINIT) Rte_AbsHwPosScom_HwPosAuthority_Uls_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Sa_AnaHwTrq_HwTq1Val_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Sa_AnaHwTrq_HwTq2Val_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Cd_Nhet1CfgAndUse_HwTq3Val_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Cd_Nhet1CfgAndUse_HwTq4Val_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32;
extern VAR(SS_State_enum, RTE_VAR_INIT) Rte_Ap_GMStrtStop_SSState_State_enum;

/* Used for Customer Periodic services */
extern VAR(EOTLearned_DataType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ap_LrnEOT_LearnedEOT;

/* Function prototypes */
extern FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetBus1Timers(void);
extern FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetBus2Timers(void);
extern FUNC(void, RTE_AP_CUSTPERSRVCS_APPL_CODE) CustPerSrvcs_SCom_ResetThrmlCntr(void);
extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_Reset(void);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TSMit_SCom_GainReset(void);
extern FUNC(void, RTE_AP_LRNEOT_APPL_CODE) LrnEOT_Scom_ResetEOT(void);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#endif /* RTE_GLOBALDATA_H */
