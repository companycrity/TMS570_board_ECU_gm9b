/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : NtWrap.h
* Module Description: Non-trusted function call wrapper definitions to allow
*						calling of SCom server functions not located in the
*						application with the Diag service handler.
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          EA3#9 %
 * %date_modified:    Mon Sep 30 09:01:45 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 06/03/15	 2		  GMN		Add trusted init function for StaMd
 * 09/30/15  5        GMN       Added trusted function to AnaHwTrq and HwTrqArbn
 * 11/18/15  6        GMN       EA3#3861: Extern TWrapC_Dma_InvalidateSlowADCGroup                            4386
 * 02/24/16  7        GMN       EA3#2817: Update ES-60A / ES-61A MotMeclPosn 1/2
 */

#ifndef NTWRAP_H
#define NTWRAP_H

#include "Std_Types.h"
#include "Rte_Type.h"
#include "WdgM.h"
#include "Wdg_TMS570LS3x.h"
#include "EPS_DiagSrvcs_ISO.Interface.h"

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Adc_Init();
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_DigColPs_SCom_NxtClrTrim(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_DigColPs_SCom_NxtSetTrim(void);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_DigColPs_SCom_CustClrTrim(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_DigColPs_SCom_CustSetTrim(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_DigHwTrqSENT_SCom_SetTrqTrim(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_DigHwTrqSENT_SCom_ClrTrqTrim(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Polarity_SCom_SetPolarity(UInt32 Polarity_Cnt_T_b08);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCmdScl_SCom_Set(Float Par_f32);
FUNC(Std_ReturnType, NTWRAP_CODE) NtWrapC_CmMtrCurr_SCom_CalGain(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_CalOffset(void);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr_SCom_SetMtrCurrCals(P2CONST(PhaseCurrCal_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCalPtr);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr3Phs_SCom_CalGain(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr3Phs_SCom_CalGainPhs3(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr3Phs_SCom_CalOffset3Phs(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_ClrT1T2OffsetTrim(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim(Float ScaleValue);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_SetT1T2OffsetTrim(void);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_WriteT1T2OffsetTrim(P2CONST(AnaHwTrqTrim_Datatype, AUTOMATIC, RTE_NTWRAP_APPL_DATA) HwTrqTrimDataPtr);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim(UInt8 HwTqTrmchNr_Cnt_u08);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim(UInt8 HwTqTrmchNr_Cnt_u08);
FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(P2CONST(EOLChOffsetTrim_Datatype, AUTOMATIC, RTE_NTWRAP_APPL_DATA) EOLChOffsetTrimDataPtr, UInt8 HwTqTrmchNr_Cnt_u08);
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_VehDyn_SCom_ForceCenter(void);

/* CmMtrCurr3Phs */
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs(P2CONST(PhaseCurrCal3Phs_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCal3PhsPtr);

/* MtrPos3SinCos */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrPos3SinCos_Scom_WriteEOLMtrCals(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrEOLDataPtr, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MtrPos3SinCosWrResp);
#else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrPos3SinCos_Scom_WriteEOLMtrCals(P2CONST(MtrPos3SinCos_EOLwithCRC, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrEOLDataPtr, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MtrPos3SinCosWrResp);
#endif

/* MotMeclPosn1 */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(P2CONST(Float, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotMeclPosn1CoeffTblResp);
#else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(P2CONST(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotMeclPosn1CoeffTblResp);
#endif

/* MotMeclPosn2 */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(P2CONST(Float, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotMeclPosn2CoeffTblResp);
#else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(P2CONST(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotMeclPosn2CoeffTblResp);
#endif

/* MotPosnCmp */
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotPosnBackEmfWrData, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotPosnCmpBackEmfWrResp);
#else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(P2CONST(MotPosnBackEmfData, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotPosnBackEmfWrData, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotPosnCmpBackEmfWrResp);
#endif

/* TrqOvlStat */
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqOvlSta_SCom_SetGmLoaIgnCntr(UInt16 GmLoaIgnCntr_Cnt_u16);

FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp8(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par);
FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp9(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par);
FUNC(void, NTWRAP_CODE) NONTRUSTED_NtWrapS_XcpWriteAp10(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par);

FUNC(void, NTWRAP_CODE) TRUSTED_TWrapS_XcpWriteAp0(TrustedFunctionIndexType index, TrustedFunctionParameterRefType FunctionParams);

/* Non-Rte external function Trusted function entry points */
void Call_Adc2_Init1(void);
void Call_NvMProxy_Init(void);
void Call_Rte_Start(void);
void Call_StaMd_Init1(void);
void Call_PwmCdd_Init(void);
void Call_StaMd_Init0(void);
Std_ReturnType NtWrapC_Wdg_TMS570LS3x_Init(P2CONST(Wdg_TMS570LS3x_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr);
void NtWrapC_WdgM_Init(P2CONST (WdgM_ConfigType, AUTOMATIC, WDGM_APPL_CONST) WdgMConfigPtr);
void Call_ProcessF0FF(P2VAR(uint8, AUTOMATIC, AUTOMATIC) t_SrvcData_Cnt_T_u08, VAR(uint16, AUTOMATIC) RequestDataIdx_Cnt_T_u16);
void TWrapC_Dma_InvalidateSlowADCGroup(void);

/*** Private Part (NtWrap Internal) *************************************/
#ifdef NTWRAP_C

#define		NTWRAP_DEV_ERROR_DETECT					STD_ON /* TODO: move NTWRAP_DEV_ERROR_DETECT to a cfg file */

#define 	NtWrap_ReportDet( errorId )				Det_ReportError( 0u /*ModuleId*/, 0u /*InstanceId*/, 0u /*ApiId*/, errorId )
#define		D_NTWRAPINVLDINDXDET_CNT_U08			0x00U

#endif


#endif
