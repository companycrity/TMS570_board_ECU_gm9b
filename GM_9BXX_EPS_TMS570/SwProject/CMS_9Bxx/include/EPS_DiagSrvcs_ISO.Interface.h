/***********************************************************************************************************************
* Copyright 2015 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EPS_DiagSrvcs_ISO.Interface.h file
* Module Description: Common Manufacturing services
* Product           : Gen II Plus - EA3.0
* Author            : cz8l9t
*
* Notes:
* This file contains configurations for ISO services.
*
***********************************************************************************************************************/

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                 DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/
/* Version Control:
 * Date Created:      Thu Sep 03 10:28:08 2015
 * %version:          EA3#16 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Thu Sep 03 10:28:08 2015 %
 * --------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * --------  -------  --------  ---------------------------------------------------------------------------  ----------
 *
 */
/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                   DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>                         DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/
#include "EPS_DiagSrvcs_CommonData.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>                           DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/

#ifndef EPS_DIAGSRVCS_ISO_INTERFACE_H
#define EPS_DIAGSRVCS_ISO_INTERFACE_H

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>                  DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/

#include "CalConstants.h"
#include "desc.h"					/* Required for interfacing with the CAN transport layer */
#include "Dem_Cfg.h"
#include "Dem_Types.h"
#include "Lnk_Symbols.h"
#include "Ap_DiagMgr.h"
#include "NtWrap.h"
#include "Interrupts.h"
#include "Ap_ApXcp.h"

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>                    DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>                   DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/

/* --- Common Defines --- */
#define CM_DIAGBUFFLEN_CNT_U16                      kDescPrimBufferLen
#define NEXTEER_SESSION								kDescStateDiagnostic_ModeNexteer_Mode
#define CM_NumHeaderBytes_Cnt_u16					2u
#define CM_NumRIDHeaderBytes_Cnt_u16				3u
#define CM_NumLIDHeaderBytes_Cnt_u16				CDD_DiagSrvcsUnusedVar_Cnt_M_u16
#define CM_MsgBufferType							DescMsg
#define CM_MsgLenType								DescMsgLen
#define CM_Std_ReturnType							Std_ReturnType
#define CM_RESP_OK									RTE_E_OK
#define CM_NULL										NULL
#define CM_SrlComHwPos_HwDeg_f32					Rte_AbsHwPos_HandwheelPosition_HwDeg_f32

/* No Error Response (Positive Codes) */
#define D_EPSNRCNOERROR_CNT_U8						kDescNrcNone

/* offsets for the data buffers for diag request/responses */
#define D_REQMSG_PID_OFFSET_CNT_U16			2U
#define D_REQMSG_RID_OFFSET_CNT_U16			3U
#define D_REQMSG_IOC_OFFSET_CNT_U16			3U
#define D_REQMSG_RESET_OFFSET_CNT_U16				0U
#define D_RESPMSG_OFFSET_CNT_U16					0U

/* Negative Response Codes */
#define D_EPSNRCNOTNEXTEERPROD_CNT_U08    D_EPSNRCSERVICENOTSUPPORTED_CNT_U16
#define D_EPSNRCSERVICEMISSING_CNT_U08    D_EPSNRCSERVICENOTSUPPORTED_CNT_U16

#define CM_GetCurrentDiagnosticMode(mode)     (*mode = DescGetStateDiagnostic_Mode())
#define NVM_BLOCK_NXTRWIRSELECT               NVM_BLOCK_CMS_NXTRWIRSELECT
#define NVM_BLOCK_EPSDEFEATS                  NVM_BLOCK_CMS_EPSDEFEATS
#define Rte_NvmBlock_Polarity_EOLCtrlPolarity Rte_NvmBlock_Polarity_Polarity_Cnt_Str

/* Condition to enable services when cyber security is necessary */
#define CM_CyberSecNexteerLocked_Cnt_lgc (boolean) ((NxtrMEC_Uls_G_enum == ProductionMode) && \
                                                    (DescGetStateSecurity_Access() != kDescStateSecurity_AccessNexteer_Unlock))

/***********************************************************************************************************************
 * --- RTE GLOBAL DATA START ---
 *
 * This section is for variables that are external references to RTE variables. (Formally found in the RTE_GlobalData.h)
 **********************************************************************************************************************/

extern VAR(Float, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsDefVehSpd_Cnt_lgc;
extern VAR(boolean, RTE_SRLCOMINPUT_VAR) Rte_SrlComInput_VehicleSpeedValid_Cnt_lgc;
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_INIT) Rte_ModeMachine_StaMd_SystemState_Mode;
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_TranlDampg_MRFMtrTrqCmd_MtrNm_f32;
extern VAR(float32, AUTOMATIC) Rte_Ap_BattVltg_BrdgVltg_Volt_f32;
extern VAR(float32, AUTOMATIC) Rte_Ap_PwrLmtFuncCr_MRFMtrTrqCmd_MtrNm_f32;
extern VAR(float32, AUTOMATIC) Rte_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32;
extern VAR(float32, AUTOMATIC) Rte_CtrlTemp_FiltMeasTemp_DegC_f32;
extern VAR(float32, AUTOMATIC) Rte_CDDInterface_ModIdxFinal_Uls_f32;
extern VAR(float32, AUTOMATIC) Rte_IoHwAbstractionUsr_TemperatureADC_Volt_f32;
extern VAR(float32, AUTOMATIC) Rte_SrlComInput_SrlComEngineSpeed_Rpm_f32;
extern VAR(float32, AUTOMATIC) Rte_CDDInterface_MtrCurrK1_Amp_f32;
extern VAR(float32, AUTOMATIC) Rte_CDDInterface_MtrCurrK2_Amp_f32;
extern VAR(float32, AUTOMATIC) Rte_CDDInterface_MtrCurrQax_Amp_f32;
extern VAR(float32, AUTOMATIC) Rte_CurrCmd_MtrCurrDaxRef_Amp_f32;
extern VAR(float32, AUTOMATIC) Rte_DigColPs_I2CHwAbsPos_HwDeg_f32;
extern VAR(float32, AUTOMATIC) Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32;
extern VAR(boolean, AUTOMATIC) Rte_CDDInterface_WIRMfgEnabled_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_MotPosnCmp_MotPosnCumvAlgndMrf_Deg_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Sa_AnaHwTrq_HwTq1Val_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Sa_AnaHwTrq_HwTq2Val_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Cd_Nhet1CfgAndUse_HwTq3Val_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Cd_Nhet1CfgAndUse_HwTq4Val_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32;

/***********************************************************************************************************************
 * --- RTE GLOBAL DATA END ---
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * --- SERIAL COMM FUNCTION START ---
 *
 * This section is for functions that are external references to system functions. (Formally found in the SComm_Func.h)
 **********************************************************************************************************************/

/* 0x22 and 0x2E Services */
extern FUNC(void, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE) Polarity_SCom_ReadPolarity(P2VAR(UInt32, AUTOMATIC, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_VAR) PolarityCfg_PolarityCfgSaved_Cnt_T_u32);
extern FUNC(void, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr3Phs_SCom_Read3PhsMtrCurrCals(P2VAR(PhaseCurrCal3Phs_DataType, AUTOMATIC, RTE_SA_CMMTRCURR3PHS_APPL_VAR) ShCurrCal3PhsPtr);
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_ReadStrgArray(void);
extern FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32);
extern FUNC(void, RTE_AP_BATTERYVOLTAGE_APPL_CODE) BatteryVoltage_SCom_ReadTransOvData(P2VAR(UInt16, AUTOMATIC, RTE_AP_BATTERYVOLTAGE_APPL_VAR) OvervoltageCounter_Cnt_u16, P2VAR(Float, AUTOMATIC, RTE_AP_BATTERYVOLTAGE_APPL_VAR) MaxBattVoltage_Volts_f32);
extern FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Get(P2VAR(Float, AUTOMATIC, RTE_AP_TRQCMDSCL_APPL_VAR) Par_f32);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetSelect(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableFricLearning_Cnt_lgc, P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableOffsetOutput_Cnt_lgc, P2VAR(UInt8, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) OpMode_Uls_u08);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetOffsetOutputDefeat(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) DefeatOffsetOutput_Cnt_lgc);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_GetEOLFric(P2VAR(Float, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EOLFric_HwNm_f32);
extern FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_ReadCogTrqCal(P2VAR(CoggingCancTrq, AUTOMATIC, RTE_AP_TRQCANC_APPL_VAR) CogTrqCalPtr, UInt16 ID);
extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);
extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_ReadParam(P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) PullCompCmd_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) STComp_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) LTComp_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) EnableLearn_Cnt_lgc);
extern FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_CURRPARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32);
extern FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_DigHwTrqSENT_SCom_WriteData(Float HwTrqTrim_HwNm_f32);
extern FUNC(void, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_ReadT1T2OffsetTrim(P2VAR(AnaHwTrqTrim_Datatype, AUTOMATIC, RTE_SA_ANAHWTRQ_APPL_VAR) HwTrqTrimDataPtr);
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
extern FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(P2CONST(Float, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_DATA) MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTblResp);
extern FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Scom_ReadMotMeclPosn1CoeffTbl(P2VAR(Float, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTbl, P2VAR(UInt16, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed);
extern FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(P2CONST(Float, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_DATA) MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTblResp);
extern FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn2_Scom_ReadMotMeclPosn2CoeffTbl(P2VAR(Float, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTbl, P2VAR(UInt16, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed);
extern FUNC(void, RTE_SA_MTRPOS3SINCOS_APPL_CODE) MtrPos3SinCos_Scom_ReadEOLMtrCals(P2VAR(UInt16, AUTOMATIC, RTE_SA_MTRPOS3SINCOS_APPL_VAR) MtrEOLDataPtr);
#else
extern FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(P2CONST(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_DATA) MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTblResp);
extern FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Scom_ReadMotMeclPosn1CoeffTbl(P2VAR(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTbl, P2VAR(UInt16, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed);
extern FUNC(void, RTE_SA_MOTMECLPOSN2_APPL_CODE) MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(P2CONST(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_DATA) MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTblResp);
extern FUNC(void, RTE_SA_MOTMECLPOSN2_APPL_CODE) MotMeclPosn2_Scom_ReadMotMeclPosn2CoeffTbl(P2VAR(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTbl, P2VAR(UInt16, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed);
extern FUNC(void, RTE_SA_MTRPOS3SINCOS_APPL_CODE) MtrPos3SinCos_Scom_ReadEOLMtrCals(P2VAR(MtrPos3SinCos_EOLwithCRC, AUTOMATIC, RTE_SA_MTRPOS3SINCOS_APPL_VAR) MtrEOLDataPtr);
#endif
extern FUNC(Std_ReturnType, RTE_SA_HWTRQARBN_APPL_CODE) HwTrqArbn_SCom_ReadHwTrqArbOffsetTrim(P2VAR(EOLChOffsetTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQARBN_APPL_VAR) EOLChOffsetTrimDataPtr, UInt8 HwTqTrmchNr_Cnt_u08);
extern FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Scom_MotPosnCmpBackEmfRead(P2VAR(MotPosnBackEmfData, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_VAR) MotPosnBackEmfReadData);
extern FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_ReadHwAgOffs(P2VAR(Float, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) HwAgOffs_HwDeg_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) HwAgLrngStRst_Cnt_lgc);
extern FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_ReadHwTqOffs(P2VAR(Float, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) HwTqOffs_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) HwTqLrngStRst_Cnt_lgc);
extern FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_ReadYawRateOffs(P2VAR(Float, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) VehYawRateOffs_DegpS_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) VehYawRateLrngStRst_Cnt_lgc);
extern FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_SetHwAgOffs(Float HwAgOffs_HwDeg_f32, Boolean HwAgLrngStRst_Cnt_lgc);
extern FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_SetHwTqOffs(Float HwTqOffs_HwNm_f32, Boolean HwTqLrngStRst_Cnt_lgc);
extern FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_SetYawRateOffs(Float VehYawRateOffs_DegpS_f32, Boolean VehYawRateLrngStRst_Cnt_lgc);
extern FUNC(void, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_ReadAnaHwTrqScaleTrim(P2VAR(AnaHwTrqScale_Datatype, AUTOMATIC, RTE_SA_ANAHWTRQ_APPL_VAR) HwTrqScaleDataPtr);

/* 0x31 Services */
extern FUNC(void, RTE_AP_ACTIVEPULL_APPL_CODE) ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);
extern FUNC(void, RTE_AP_LRNEOT_APPL_CODE) LrnEOT_Scom_ResetEOT(void);
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_ResetNTCStatus(void);
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_ClearBlackBox(void);
extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTC( Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCOriginType DTCOrigin);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_InitLearnedTables(void);
extern FUNC(void, RTE_AP_AVGFRICLRN_APPL_CODE) AvgFricLrn_SCom_ResetToZero(void);
extern FUNC(void, RTE_AP_BATTERYVOLTAGE_APPL_CODE) BatteryVoltage_SCom_ClearTransOvData(void);
extern FUNC(void, RTE_AP_DIAGMGR_APPL_CODE) DiagMgr_SCom_GetNTCInfo(VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Param_Ptr_T_u08, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Status_Ptr_T_u08, P2VAR(uint8, AUTOMATIC, AUTOMATIC) AgingCounter_Ptr_T_u08);
extern FUNC(void, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr_SCom_MtrCurrOffReadStatus(P2VAR(MtrCurrOffProcessFlag, AUTOMATIC, RTE_SA_CMMTRCURR3PHS_APPL_VAR) CurrOffStatus);
extern void Call_ProcessF0FF(P2VAR(uint8, AUTOMATIC, AUTOMATIC) t_SrvcData_Cnt_T_u08, VAR(uint16, AUTOMATIC) RequestDataIdx_Cnt_T_u16);
extern FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_RstHwTq(void);
extern FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_RstYawAndAg(void);

/* 0x2F services */
/* << DEFINE AND EXTERNALLY REFERENCED FUNCTIONS FOR TYPE 0x2F SERVICES HERE >> */

/* 0x11 Reset services */
extern FUNC(void, RTE_AP_STAMD_APPL_CODE) StaMd_SCom_EcuReset( void );

/* F00F */
extern VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
extern FUNC(void, AUTOMATIC) NtWrapC_GeneratePosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32);
extern VAR(float32, AUTOMATIC) Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
extern VAR(Boolean, AUTOMATIC) Rte_SrlComInput_VehicleSpeedValid_Cnt_lgc;

/* Defines for global services */
#define D_ALLDTC_MASK_CNT_U32 			0xFFFFFFU
#define CM_VehicleSpeed_Kph_f32			Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32
#define CM_DiagStsDefVehSpd_Cnt_lgc		Rte_DiagMgr_DiagStsDefVehSpd_Cnt_lgc
#define CM_VehicleSpeedValid_Cnt_lgc	Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc
#define CM_HwTrq_HwNm_f32				Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32
#define CM_k_TrimVehSpdLimit_Kph_f32    k_SrvcVehSpdLimit_Kph_f32
#define CM_k_TrimHwTrqLimit_HwNm_f32    k_SrvcHwTrqLimit_HwNm_f32
#define CM_RTE_MODE_StaMd_Mode_OPERATE	RTE_MODE_StaMd_Mode_OPERATE
/***********************************************************************************************************************
 * --- SERIAL COMM FUNCTION END ---
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * --- Common Manufacturing Services Selection ---
 *
 * This block of defines control which services are to be included for the program at the time of build. Unused or not
 * defined services should be set to D_DIAGSRVC_DISABLED.
 **********************************************************************************************************************/
/****************************** BEGIN CMS GENERATION - DO NOT CHANGE/REMOVE THIS COMMENT ******************************/
#define D_EPSDIAGSRVPID0000_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0001_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0002_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0003_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0004_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0005_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0006_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0007_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0008_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0009_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000A_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP000B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP000C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP000D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP000E_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP000F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0010_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0011_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0012_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0013_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0014_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0015_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0016_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0017_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0018_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0019_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001A_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP001B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP001C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP001D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP001E_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP001F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0020_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0021_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0022_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0023_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0024_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0025_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0026_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0027_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0028_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0029_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP002A_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002E_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP002F_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0030_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0031_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0032_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0033_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0034_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0035_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0036_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0037_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0038_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0039_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP003A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP003B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP003C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP003D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP003E_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP003F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0040_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0041_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0042_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0043_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0044_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0045_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0046_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0047_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0048_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0049_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0050_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0051_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0052_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0053_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP00FF_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0100_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0101_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0102_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0103_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0104_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0105_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0106_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0107_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0108_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP0109_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP010A_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP010B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP010C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVXCP010D_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP010E_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP010F_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRESET1160_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF000_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF001_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF002_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF003_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF004_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF005_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF006_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF007_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF008_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF009_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00A_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF00B_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF00C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF00D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF00E_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF00F_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF010_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF011_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF012_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF013_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF014_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF015_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVRIDF016_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF018_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF0FF_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDFCE0_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD01_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD02_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD03_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD04_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD05_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD06_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD07_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD08_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD09_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD0A_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD0B_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0C_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVIOCFD0D_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0E_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD10_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVIOCFD11_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD12_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD13_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD14_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD15_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD16_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD17_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD18_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD19_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1A_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1B_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1C_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1D_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD1E_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1F_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD20_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD21_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD22_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD23_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD24_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD25_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD26_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD27_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD28_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD29_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD30_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD31_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD32_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFD33_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD41_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA0_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA1_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA2_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA3_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA4_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA5_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA7_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA8_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDA9_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDAC_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAD_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAE_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAF_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB0_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDB1_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDB2_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDB3_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDB4_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB5_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB6_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB7_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDB8_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB9_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDBA_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDBB_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDBC_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDBD_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDBE_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDBF_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDC0_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDC1_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDC2_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDC3_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDC4_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDC5_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDC6_CNT_ENUM	D_DIAGSRVC_DISABLED
#define D_EPSDIAGSRVPIDFDC7_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDC8_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDC9_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDCA_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDCB_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDCC_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDCD_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE0_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE1_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE2_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE3_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE4_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE5_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE6_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE7_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEE8_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEEA_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEEB_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEEC_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEED_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEEF_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEF1_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEF3_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEF4_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEF5_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEF6_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEF7_CNT_ENUM	D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFEF8_CNT_ENUM	D_DIAGSRVC_ENABLED

/* -----[ Begin XCP Variables ]----- */
#define CM_ModeMachine_StaMd_SystemState_Mode    &Rte_ModeMachine_StaMd_SystemState_Mode
#define CM_BatteryVoltage_Vecu_Volts_f32         &Rte_Ap_BattVltg_BrdgVltg_Volt_f32
#define CM_ScaledMtrPos_HwDeg_M_f32              NULL_PTR
#define CM_MtrTrqLmt_MRFMtrTrqCmd_MtrNm_f32      &Rte_Ap_PwrLmtFuncCr_MRFMtrTrqCmd_MtrNm_f32
#define CM_MtrPos_MRFCumMtrPos_Deg_f32           NULL_PTR
#define CM_MtrVel_MRFMtrVel_MtrRadpS_f32         &Rte_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32
#define CM_VehicleSpeed_VehSpd_Kph_f32           &Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32
#define CM_k_TbarStiff_NmpDeg_F32                &k_CmnTbarStiff_NmpDeg_f32
#define CM_CtrlTemp_FiltMeasTemp_DegC_f32        &Rte_CtrlTemp_FiltMeasTemp_DegC_f32
#define CM_QaxCurrFiltSV_Amp_M_s11p20            NULL_PTR
#define CM_VltgCtrl_ModIdx_Uls_f32               &Rte_CDDInterface_ModIdxFinal_Uls_f32
#define CM_TemperatureADC_Volt_f32               &Rte_IoHwAbstractionUsr_TemperatureADC_Volt_f32
#define CM_MtrCurrMeas_Amp_f32                   &Rte_CurrCmd_MtrCurrDaxRef_Amp_f32
#define CM_SrlComEngineSpeed_Rpm_f32             &Rte_SrlComInput_SrlComEngineSpeed_Rpm_f32
#define CM_RawCurrFiltered1_Amp_f32              NULL_PTR
#define CM_RawCurrFiltered2_Amp_f32              NULL_PTR
#define CM_MtrCurrQax_Amp_f32                    &Rte_CDDInterface_MtrCurrQax_Amp_f32
#define CM_MtrCurrDax_Amp_f32                    &Rte_CurrCmd_MtrCurrDaxRef_Amp_f32
#define CM_DigColPs_VernDiagError_Deg_D_F32      NULL_PTR
#define CM_Rte_Cd_Nhet_DigHwTrqT1_HwNm_f32       &Rte_Cd_Nhet1CfgAndUse_HwTq3Val_HwNm_f32
#define CM_Rte_Cd_Nhet_DigHwTrqT2_HwNm_f32       &Rte_Cd_Nhet1CfgAndUse_HwTq4Val_HwNm_f32
#define CM_Rte_Sa_DigColPs_I2CHwAbsPos_HwDeg_f32 &Rte_DigColPs_I2CHwAbsPos_HwDeg_f32
#define CM_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32   &Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32
/* -----[ End XCP Variables ]----- */

#if (D_EPSDIAGSRVRESET1160_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_StaMd_SCom_EcuReset                  StaMd_SCom_EcuReset
#endif

#if (D_EPSDIAGSRVRIDF000_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_F000NMEC_CNT_LGC                      TRUE
	#define D_F000IGNCNTR_CNT_LGC                   TRUE
	#define D_F000LEARNEDEOT_CNT_LGC                TRUE
	#define D_F000ACTIVEPULLCOMP_CNT_LGC            TRUE
	#define D_F000NXTRDTCTBL_CNT_LGC                TRUE
	#define D_F000NXTRDTCBLACKBOX_CNT_LGC           TRUE
	#define D_F000CUSTDTCTBL_CNT_LGC                TRUE
	#define D_F000FRICTIONDETECTPARAM_CNT_LGC       TRUE
	#define D_F000INITLRNDTBLS_CNT_LGC              TRUE
	#define CM_Reset_LrnEOT_Scom_ResetEOT           LrnEOT_Scom_ResetEOT
	#define CM_Reset_ActivePull_SCom_SetLTComp      ActivePull_SCom_SetLTComp
	#define CM_Reset_ClearNTCs_SComm                DiagMgr_SCom_ResetNTCStatus
	#define CM_DiagMgr_SCom_ClearBlackBox           DiagMgr_SCom_ClearBlackBox
	#define CM_Reset_ClearCustDTCs_SComm            Dem_ClearDTC
	#define CM_AvgFricLrn_SCom_ResetToZero          AvgFricLrn_SCom_ResetToZero
	#define CM_AvgFricLrn_SCom_InitLearnedTables    AvgFricLrn_SCom_InitLearnedTables
#endif

#if (D_EPSDIAGSRVRIDF001_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ClearNTCs_SComm                      DiagMgr_SCom_ResetNTCStatus
	#define CM_DiagMgr_SCom_ClearBlackBox           DiagMgr_SCom_ClearBlackBox
	#define CM_ClearCustDTCs_SComm                  Dem_ClearDTC
#endif

#if (D_EPSDIAGSRVRIDF002_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrq_SCom_ClrHwTrqTrim              NtWrapC_AnaHwTrq_SCom_ClrT1T2OffsetTrim
	#define CM_HwTrq_SCom_ClrHwTrqScale             NtWrapC_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim
	#define CM_HwTrq_SCom_SetHwTrqTrim              NtWrapC_AnaHwTrq_SCom_SetT1T2OffsetTrim
#endif

#if (D_EPSDIAGSRVRIDF003_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_F003CLRTRIMNORET_CNT_LGC              TRUE
	#define CM_HwPos_SCom_ClrHwPosTrim              NtWrapC_DigColPs_SCom_NxtClrTrim
	#define CM_HwPos_SCom_SetHwPosTrim              NtWrapC_DigColPs_SCom_NxtSetTrim
	#define D_F003DISABLELRNTRIM_CNT_LGC            TRUE
#endif

#if (D_EPSDIAGSRVRIDF004_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F004 */
#endif

#if (D_EPSDIAGSRVRIDF005_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_DiagMgr_SCom_GetNTCInfo              DiagMgr_SCom_GetNTCInfo
#endif

#if (D_EPSDIAGSRVRIDF006_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F006 */
#endif

#if (D_EPSDIAGSRVRIDF007_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F007 */
#endif

#if (D_EPSDIAGSRVRIDF008_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_CmMtrCurr_SCom_CalGain               NtWrapC_CmMtrCurr3Phs_SCom_CalGain
#endif

#if (D_EPSDIAGSRVRIDF009_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_CmMtrCurr_SCom_MtrCurrOffReadStatus  CmMtrCurr_SCom_MtrCurrOffReadStatus
	#define CM_CmMtrCurr_SCom_CalOffset             NtWrapC_CmMtrCurr3Phs_SCom_CalOffset3Phs
	#define MtrCurrOffProcessFlag                   MtrCurrOffProcessFlag
	#define D_RIDF009SVCDFTBITSSET_CNT_U16          0x301
	#define D_RIDF009SVCDFTBITSCLR_CNT_U16          (~D_RIDF009SVCDFTBITSSET_CNT_U16)
#endif

#if (D_EPSDIAGSRVRIDF00A_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F00A */
#endif

#if (D_EPSDIAGSRVRIDF00B_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F00B */
#endif

#if (D_EPSDIAGSRVRIDF00C_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F00C */
#endif

#if (D_EPSDIAGSRVRIDF00D_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F00D */
#endif

#if (D_EPSDIAGSRVRIDF00E_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: F00E */
#endif

#if (D_EPSDIAGSRVRIDF00F_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_k_SComTrqPosPol_Cnt_s08              k_SComTrqPosPol_Cnt_s08
	#define CM_Rte_AbsHwPos_SrlComHwPos_HwDeg_f32   Rte_AbsHwPos_HandwheelPosition_HwDeg_f32
	#define CM_HandwheelAuthority_Uls_f32           Rte_AbsHwPos_HandwheelAuthority_Uls_f32
	#define CM_VehSpdValid_Cnt_lgc                  Rte_SrlComInput_VehicleSpeedValid_Cnt_lgc
	#define CM_GenPosTraj_SCom_SetInputParam        NtWrapC_GeneratePosTraj_SCom_SetInputParam
#endif

#if (D_EPSDIAGSRVRIDF010_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim NtWrapC_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim
	#define CM_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim NtWrapC_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim
#endif

#if (D_EPSDIAGSRVRIDF011_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim NtWrapC_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim
	#define CM_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim NtWrapC_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim
#endif

#if (D_EPSDIAGSRVRIDF012_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrCurrPhs3_SCom_Phs3CalGain         NtWrapC_CmMtrCurr3Phs_SCom_CalGainPhs3
#endif

#if (D_EPSDIAGSRVRIDF013_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrq_SCom_ClrHwTrqTrim              NtWrapC_AnaHwTrq_SCom_ClrT1T2OffsetTrim
	#define CM_HwTrq_SCom_ClrHwTrqScale             NtWrapC_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim
	#define CM_HwTrq_SCom_SetHwTrqTrim              NtWrapC_AnaHwTrq_SCom_SetT1T2OffsetTrim
#endif

#if (D_EPSDIAGSRVRIDF014_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MotMeclPosn1_SCom_ClrHarCompTb       NtWrapC_MotMeclPosn1_SCom_ClrMotMeclPosnCorrnTbl
#endif

#if (D_EPSDIAGSRVRIDF015_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MotMeclPosn2_SCom_ClrHarCompTb       NtWrapC_MotMeclPosn2_SCom_ClrMotMeclPosnCorrnTbl
#endif

#if (D_EPSDIAGSRVRIDF016_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SnsrOffsLrng_RstYawRateOffsAndHwAgOffs SnsrOffsLrng_RstYawAndAg
#endif

#if (D_EPSDIAGSRVRIDF018_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SnsrOffsLrng_RstHwTqOffs             SnsrOffsLrng_RstHwTq
#endif

#if (D_EPSDIAGSRVRIDF0FF_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_EnableTestMode_Cnt_lgc               EnableTestMode_Cnt_lgc
	#define CM_ProcessF0FF                          Call_ProcessF0FF
	#define CM_WdgM_CheckpointReached               WdgM_CheckpointReached
	#define CM_DisableSysTickInterrupt              DisableSysTickInterrupt
	#define CM_EnableSysTickInterrupt               EnableSysTickInterrupt
	#define CM_GetAlarm                             GetAlarm
	#define CM_CancelAlarm                          CancelAlarm
	#define CM_SetRelAlarm                          SetRelAlarm
#endif

#if (D_EPSDIAGSRVRIDFCE0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to RID: FCE0 */
#endif

#if (D_EPSDIAGSRVPIDFD01_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SwRelNum_Cnt_u08                     k_SWRelNum_Cnt_u8
	#define CM_CalRelNums_Cnt_u08                   k_CalRelNum_Cnt_u8, k_Cal2RelNum_Cnt_u8, k_Cal3RelNum_Cnt_u8
	#define CM_BootRelNum_Cnt_u08                   Lnk_BootRelNum_Addr
	#define D_NUMCALSECTIONS_CNT_U08                3
	#define D_MAXCALREVLENGTH_CNT_U08               12
#endif

#if (D_EPSDIAGSRVPIDFD02_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SrlComSvcDft_Cnt_b32                 CDD_EOLSrlComSvcDft_Cnt_G_b32
#endif

#if (D_EPSDIAGSRVPIDFD03_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD03 */
#endif

#if (D_EPSDIAGSRVPIDFD04_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD04 */
#endif

#if (D_EPSDIAGSRVPIDFD05_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD05 */
#endif

#if (D_EPSDIAGSRVPIDFD06_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD06 */
#endif

#if (D_EPSDIAGSRVPIDFD07_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD07 */
#endif

#if (D_EPSDIAGSRVPIDFD08_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrq_SCom_SetHwTrqScale             NtWrapC_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim
	#define CM_HwTrq_SCom_ReadHwTrqScale            AnaHwTrq_SCom_ReadAnaHwTrqScaleTrim
	/* Macro add manually */
	/* TODO [GMN] Make this macro part of the CMS Configuration tool */
	#define CM_HwTrqScale_Datatype                  AnaHwTrqScale_Datatype
#endif

#if (D_EPSDIAGSRVPIDFD09_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD09 */
#endif

#if (D_EPSDIAGSRVPIDFD0A_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD0A */
#endif

#if (D_EPSDIAGSRVPIDFD0B_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_WIRSel_Cnt_u16                       CDD_EOLNxtrWIRSelect_Cnt_G_u16
#endif

#if (D_EPSDIAGSRVPIDFD0C_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD0C */
#endif

#if (D_EPSDIAGSRVIOCFD0D_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrTrqLmt_SCom_ManualTrqCmd          NtWrapC_AssistLmtFunc_Scom_ManualTrqCmd
#endif

#if (D_EPSDIAGSRVPIDFD0E_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrTrqCmd_MtrNm_f32                  Rte_Ap_TranlDampg_MRFMtrTrqCmd_MtrNm_f32
	#define CM_CumMtrPos_Deg_f32                    Rte_Ap_MotPosnCmp_MotPosnCumvAlgndMrf_Deg_f32
#endif

#if (D_EPSDIAGSRVPIDFD0F_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD0F */
#endif

#if (D_EPSDIAGSRVPIDFD10_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD10 */
#endif

#if (D_EPSDIAGSRVIOCFD11_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_DFTASSTTBL_CNT_LGC                   CDD_DftAsstTbl_Cnt_G_lgc
	#define CM_DWNLDASSTGAIN_ULS_F32                CDD_DwnldAsstGain_Uls_G_f32
#endif

#if (D_EPSDIAGSRVPIDFD12_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD12 */
#endif

#if (D_EPSDIAGSRVPIDFD13_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_DiagMgr_SCom_ReadStrgArray           DiagMgr_SCom_ReadStrgArray
	#define CM_DTCMaxStorage_Cnt_u16                D_MAXDTCSTORAGE_CNT_U16
	#define CM_NTCStrgArray_Type                    NTCStrgArray
	#define CM_DiagMgr_SCom_GetNTCInfo              DiagMgr_SCom_GetNTCInfo
#endif

#if (D_EPSDIAGSRVPIDFD14_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD14 */
#endif

#if (D_EPSDIAGSRVPIDFD15_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD15 */
#endif

#if (D_EPSDIAGSRVPIDFD16_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD16 */
#endif

#if (D_EPSDIAGSRVPIDFD17_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD17 */
#endif

#if (D_EPSDIAGSRVPIDFD18_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD18 */
#endif

#if (D_EPSDIAGSRVPIDFD19_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_NxtrMEC_Cnt_G_u8                     Nvm_NMEC_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFD1A_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_Rte_ModeType_StaMd_Mode              Rte_ModeType_StaMd_Mode
	#define CM_SystemState_Cnt_enum                 Rte_ModeMachine_StaMd_SystemState_Mode
#endif

#if (D_EPSDIAGSRVPIDFD1B_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ManualVehSpd_SCom                    SrlComInput_SCom_ManualVehSpd
	#define D_FD1BFREEZEONMEC_CNT_LGC               TRUE
#endif

#if (D_EPSDIAGSRVPIDFD1C_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD1C */
#endif

#if (D_EPSDIAGSRVPIDFD1D_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD1D */
#endif

#if (D_EPSDIAGSRVPIDFD1E_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MfgDiagInhibit_Cnt_lgc               MfgDiagInhibit_Uls_G_lgc
#endif

#if (D_EPSDIAGSRVPIDFD1F_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD1F */
#endif

#if (D_EPSDIAGSRVPIDFD20_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD20 */
#endif

#if (D_EPSDIAGSRVPIDFD21_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD21 */
#endif

#if (D_EPSDIAGSRVPIDFD22_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD22 */
#endif

#if (D_EPSDIAGSRVPIDFD23_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD23 */
#endif

#if (D_EPSDIAGSRVPIDFD24_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD24 */
#endif

#if (D_EPSDIAGSRVPIDFD25_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_TrqCmdScl_SCom_Set                   NtWrapC_TrqCmdScl_SCom_Set
	#define CM_TrqCmdScl_SCom_Get                   TrqCmdScl_SCom_Get
#endif

#if (D_EPSDIAGSRVPIDFD26_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_AvgFricLrn_SCom_SetSelect            AvgFricLrn_SCom_SetSelect
	#define CM_AvgFricLrn_SCom_GetSelect            AvgFricLrn_SCom_GetSelect
#endif

#if (D_EPSDIAGSRVPIDFD27_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_AvgFricLrn_SCom_SetOffsetOutputDefeat AvgFricLrn_SCom_SetOffsetOutputDefeat
	#define CM_AvgFricLrn_SCom_GetOffsetOutputDefeat AvgFricLrn_SCom_GetOffsetOutputDefeat
#endif

#if (D_EPSDIAGSRVPIDFD28_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD28 */
#endif

#if (D_EPSDIAGSRVPIDFD29_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_AvgFricLrn_SCom_SetEOLFric           AvgFricLrn_SCom_SetEOLFric
	#define CM_AvgFricLrn_SCom_GetEOLFric           AvgFricLrn_SCom_GetEOLFric
#endif

#if (D_EPSDIAGSRVPIDFD30_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD30 */
#endif

#if (D_EPSDIAGSRVPIDFD31_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD31 */
#endif

#if (D_EPSDIAGSRVPIDFD32_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD32 */
#endif

#if (D_EPSDIAGSRVPIDFD33_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_PhaseCurrCal3Phs_DataType            PhaseCurrCal3Phs_DataType
	#define CM_MtrCurr3Phs_SCom_Read3PhsMtrCurrCals CmMtrCurr3Phs_SCom_Read3PhsMtrCurrCals
	#define CM_MtrCurr3Phs_SCom_Set3PhsMtrCurrCals  NtWrapC_CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs
#endif

#if (D_EPSDIAGSRVPIDFD41_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FD41 */
#endif

#if (D_EPSDIAGSRVPIDFDA0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA0 */
#endif

#if (D_EPSDIAGSRVPIDFDA1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ECUSerialNumber                      Nvm_EcuSrlNum_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFDA2_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_EPSSerialNumber                      Nvm_EpsSrlNum_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFDA3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ECUHardwarePN                        Nvm_EcuHwPn_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFDA4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA4 */
#endif

#if (D_EPSDIAGSRVPIDFDA5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA5 */
#endif

#if (D_EPSDIAGSRVPIDFDA7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA7 */
#endif

#if (D_EPSDIAGSRVPIDFDA8_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA8 */
#endif

#if (D_EPSDIAGSRVPIDFDA9_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDA9 */
#endif

#if (D_EPSDIAGSRVPIDFDAC_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MfgScratchPad_Cnt_G_u8               Nvm_NxtrManfScrpd_Cnt_u8
#endif

#if (D_EPSDIAGSRVPIDFDAD_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ActivePull_SCom_ReadParam            ActivePull_SCom_ReadParam
#endif

#if (D_EPSDIAGSRVPIDFDAE_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDAE */
#endif

#if (D_EPSDIAGSRVPIDFDAF_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_ENABLEGENERICPARAMS_CNT_LGC           TRUE
#endif

#if (D_EPSDIAGSRVPIDFDB0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB0 */
#endif

#if (D_EPSDIAGSRVPIDFDB1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB1 */
#endif

#if (D_EPSDIAGSRVPIDFDB2_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB2 */
#endif

#if (D_EPSDIAGSRVPIDFDB3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB3 */
#endif

#if (D_EPSDIAGSRVPIDFDB4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_RANDKESUPPORTONLY_CNT_LGC             TRUE
	#define CM_SCom_EOLNomMtrParam_Set_FDB4         NtWrapC_SCom_EOLNomMtrParam_Set
	#define CM_SCom_EOLNomMtrParam_Get_FDB4         SCom_EOLNomMtrParam_Get
#endif

#if (D_EPSDIAGSRVPIDFDB5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ActivePull_SCom_SetSTComp            ActivePull_SCom_SetSTComp
#endif

#if (D_EPSDIAGSRVPIDFDB6_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_ActivePull_SCom_SetLTComp            ActivePull_SCom_SetLTComp
#endif

#if (D_EPSDIAGSRVPIDFDB7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FDB7 */
#endif

#if (D_EPSDIAGSRVPIDFDB8_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_FDB8_HWDIFFTRQCHANNEL_U8              1
	#define CM_EOLChOffsetTrim_Datatype             EOLChOffsetTrim_Datatype
	#define CM_HwTrqArbn_SCom_ReadHwTrqArbOffsetTrim HwTrqArbn_SCom_ReadHwTrqArbOffsetTrim
	#define CM_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim NtWrapC_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim
#endif

#if (D_EPSDIAGSRVPIDFDB9_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define D_FDB9_HWDIFFTRQCHANNEL_U8              2
	#define CM_EOLChOffsetTrim_Datatype             EOLChOffsetTrim_Datatype
	#define CM_HwTrqArbn_SCom_ReadHwTrqArbOffsetTrim HwTrqArbn_SCom_ReadHwTrqArbOffsetTrim
	#define CM_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim NtWrapC_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim
#endif

#if (D_EPSDIAGSRVPIDFDBA_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_Polarity_SCom_SetPolarity32          NtWrapC_Polarity_SCom_SetPolarity
	#define CM_Polarity_SCom_ReadPolarity32         Polarity_SCom_ReadPolarity
#endif

#if (D_EPSDIAGSRVPIDFDBB_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrq_SCom_ManualSetHwTrqTrim        NtWrapC_AnaHwTrq_SCom_WriteT1T2OffsetTrim
	#define CM_HwTrq_SCom_ReadHwTrqTrim             AnaHwTrq_SCom_ReadT1T2OffsetTrim
	#define CM_HwTrqTrim_Datatype                   AnaHwTrqTrim_Datatype
#endif

#if (D_EPSDIAGSRVPIDFDBC_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrPos_SCom_WriteBEMF                NtWrapC_MotPosnCmp_Scom_MotPosnCmpBackEmfWr
	#define CM_MtrPos_SCom_ReadBEMF                 MotPosnCmp_Scom_MotPosnCmpBackEmfRead
	#define CM_MtrPos_BEMF_Datatype                 MotPosnBackEmfData
#endif

#if (D_EPSDIAGSRVPIDFDBD_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrMeclPos1_SCom_WriteHarCompTbA     NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosnCorrnTblSeg0
	#define CM_MtrMeclPos1_SCom_ReadHarCompTbA      MotMeclPosn1_Scom_ReadMotMeclPosnCorrnTblSeg0
	#define CM_MtrPos_HarCompTbSegDataType          HarCompTblSegment_DataType
#endif

#if (D_EPSDIAGSRVPIDFDBE_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrMeclPos1_SCom_WriteHarCompTbB     NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosnCorrnTblSeg1
	#define CM_MtrMeclPos1_SCom_ReadHarCompTbB      MotMeclPosn1_Scom_ReadMotMeclPosnCorrnTblSeg1
	#define CM_MtrPos_HarCompTbSegDataType          HarCompTblSegment_DataType
#endif

#if (D_EPSDIAGSRVPIDFDBF_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrMeclPos1_SCom_WriteHarCompTbC     NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosnCorrnTblSeg2
	#define CM_MtrMeclPos1_SCom_ReadHarCompTbC      MotMeclPosn1_Scom_ReadMotMeclPosnCorrnTblSeg2
	#define CM_MtrPos_HarCompTbSegDataType          HarCompTblSegment_DataType
#endif

#if (D_EPSDIAGSRVPIDFDC0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrMeclPos1_SCom_WriteHarCompTbD     NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosnCorrnTblSeg3
	#define CM_MtrMeclPos1_SCom_ReadHarCompTbD      MotMeclPosn1_Scom_ReadMotMeclPosnCorrnTblSeg3
	#define CM_MtrPos_HarCompTbSegDataType          HarCompTblSegment_DataType
#endif

#if (D_EPSDIAGSRVPIDFDC1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrMeclPosn1_SCom_WriteCRC           NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosnCorrnTblCRC
	#define CM_MtrMeclPosn1_SCom_ReadCRC            MotMeclPosn1_Scom_ReadMotMeclPosnCorrnTblCRC
#endif

#if (D_EPSDIAGSRVPIDFDC2_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrMeclPos2_SCom_WriteHarCompTbA     NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosnCorrnTblSeg0
	#define CM_MtrMeclPos2_SCom_ReadHarCompTbA      MotMeclPosn2_Scom_ReadMotMeclPosnCorrnTblSeg0
	#define CM_MtrPos_HarCompTbSegDataType          HarCompTblSegment_DataType
#endif

#if (D_EPSDIAGSRVPIDFDC3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrMeclPos2_SCom_WriteHarCompTbB     NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosnCorrnTblSeg1
	#define CM_MtrMeclPos2_SCom_ReadHarCompTbB      MotMeclPosn2_Scom_ReadMotMeclPosnCorrnTblSeg1
	#define CM_MtrPos_HarCompTbSegDataType          HarCompTblSegment_DataType
#endif

#if (D_EPSDIAGSRVPIDFDC4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrMeclPos2_SCom_WriteHarCompTbC     NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosnCorrnTblSeg2
	#define CM_MtrMeclPos2_SCom_ReadHarCompTbC      MotMeclPosn2_Scom_ReadMotMeclPosnCorrnTblSeg2
	#define CM_MtrPos_HarCompTbSegDataType          HarCompTblSegment_DataType
#endif

#if (D_EPSDIAGSRVPIDFDC5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrMeclPos2_SCom_WriteHarCompTbD     NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosnCorrnTblSeg3
	#define CM_MtrMeclPos2_SCom_ReadHarCompTbD      MotMeclPosn2_Scom_ReadMotMeclPosnCorrnTblSeg3
	#define CM_MtrPos_HarCompTbSegDataType          HarCompTblSegment_DataType
#endif

#if (D_EPSDIAGSRVPIDFDC6_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MtrMeclPosn2_SCom_WriteCRC           NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosnCorrnTblCRC
	#define CM_MtrMeclPosn2_SCom_ReadCRC            MotMeclPosn2_Scom_ReadMotMeclPosnCorrnTblCRC
#endif

#if (D_EPSDIAGSRVPIDFDC7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_AnalogMtrPos_SCom_Read               MtrPos3SinCos_Scom_ReadEOLMtrCals
	#define CM_AnalogMtrPos_SCom_Write              NtWrapC_MtrPos3SinCos_Scom_WriteEOLMtrCals
	#define CM_AnalogMtrPos_Datatype                MtrPos3SinCos_EOLwithCRC
#endif

#if (D_EPSDIAGSRVPIDFDC8_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MotPosn1CoeffTbl_SCom_Write          NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl
	#define CM_MotPosn1CoeffTbl_SCom_Read           MotMeclPosn1_Scom_ReadMotMeclPosn1CoeffTbl
	#define CM_MotMeclPosn1CoeffTbl_Datatype        DT_MotMeclPosnCoeffTbl_f32
#endif

#if (D_EPSDIAGSRVPIDFDC9_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_MotPosn2CoeffTbl_SCom_Write          NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl
	#define CM_MotPosn2CoeffTbl_SCom_Read           MotMeclPosn2_Scom_ReadMotMeclPosn2CoeffTbl
	#define CM_MotMeclPosn2CoeffTbl_Datatype        DT_MotMeclPosnCoeffTbl_f32
#endif

#if (D_EPSDIAGSRVPIDFDCA_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SnsrLrngVehYawRateOffs_SCom_Write    SnsrOffsLrng_SetYawRateOffs
	#define CM_SnsrLrngVehYawRateOffs_SCom_Read     SnsrOffsLrng_ReadYawRateOffs
#endif

#if (D_EPSDIAGSRVPIDFDCB_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SnsrLrngHwAgOffs_SCom_Write          SnsrOffsLrng_SetHwAgOffs
	#define CM_SnsrLrngHwAgOffs_SCom_Read           SnsrOffsLrng_ReadHwAgOffs
#endif

#if (D_EPSDIAGSRVPIDFDCC_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_SnsrLrngHwTqOffs_SCom_Write          SnsrOffsLrng_SetHwTqOffs
	#define CM_SnsrLrngHwTqOffs_SCom_Read           SnsrOffsLrng_ReadHwTqOffs
#endif

#if (D_EPSDIAGSRVPIDFDCD_CNT_ENUM == D_DIAGSRVC_ENABLED)
	#define CM_HwTrqVal_HwNm_f32                    Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32
	#define CM_HwTrq1Val_HwNm_f32                   Rte_Sa_AnaHwTrq_HwTq1Val_HwNm_f32
	#define CM_HwTrq2Val_HwNm_f32                   Rte_Sa_AnaHwTrq_HwTq2Val_HwNm_f32
	#define CM_HwTrq3Val_HwNm_f32                   Rte_Cd_Nhet1CfgAndUse_HwTq3Val_HwNm_f32
	#define CM_HwTrq4Val_HwNm_f32                   Rte_Cd_Nhet1CfgAndUse_HwTq4Val_HwNm_f32
#endif

#if (D_EPSDIAGSRVPIDFEE0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE0 */
#endif

#if (D_EPSDIAGSRVPIDFEE1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE1 */
#endif

#if (D_EPSDIAGSRVPIDFEE2_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE2 */
#endif

#if (D_EPSDIAGSRVPIDFEE3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE3 */
#endif

#if (D_EPSDIAGSRVPIDFEE4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE4 */
#endif

#if (D_EPSDIAGSRVPIDFEE5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE5 */
#endif

#if (D_EPSDIAGSRVPIDFEE6_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE6 */
#endif

#if (D_EPSDIAGSRVPIDFEE7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE7 */
#endif

#if (D_EPSDIAGSRVPIDFEE8_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEE8 */
#endif

#if (D_EPSDIAGSRVPIDFEEA_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEEA */
#endif

#if (D_EPSDIAGSRVPIDFEEB_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEEB */
#endif

#if (D_EPSDIAGSRVPIDFEEC_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEEC */
#endif

#if (D_EPSDIAGSRVPIDFEED_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEED */
#endif

#if (D_EPSDIAGSRVPIDFEEF_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEEF */
#endif

#if (D_EPSDIAGSRVPIDFEF1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEF1 */
#endif

#if (D_EPSDIAGSRVPIDFEF3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEF3 */
#endif

#if (D_EPSDIAGSRVPIDFEF4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEF4 */
#endif

#if (D_EPSDIAGSRVPIDFEF5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEF5 */
#endif

#if (D_EPSDIAGSRVPIDFEF6_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEF6 */
#endif

#if (D_EPSDIAGSRVPIDFEF7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEF7 */
#endif

#if (D_EPSDIAGSRVPIDFEF8_CNT_ENUM == D_DIAGSRVC_ENABLED)
	/* Defines specific to PID: FEF8 */
#endif

/******************************* END CMS GENERATION - DO NOT CHANGE/REMOVE THIS COMMENT *******************************/

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>                     DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/

#endif /* EPS_DIAGSRVCS_ISO_INTERFACE_H */
