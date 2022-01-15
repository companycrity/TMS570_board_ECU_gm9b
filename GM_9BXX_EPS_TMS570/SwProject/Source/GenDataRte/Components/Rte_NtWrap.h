/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Components/Rte_NtWrap.h
 *     Workspace:  C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Mar 21 14:08:38 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_NTWRAP_H
# define _RTE_NTWRAP_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim(void);
#  define RTE_STOP_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim
#  define RTE_START_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_ClrT1T2OffsetTrim(void);
#  define RTE_STOP_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AnaHwTrq_SCom_ClrT1T2OffsetTrim AnaHwTrq_SCom_ClrT1T2OffsetTrim
#  define RTE_START_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_SetAnaHwTrqScaleTrim(Float ScaleValue);
#  define RTE_STOP_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim AnaHwTrq_SCom_SetAnaHwTrqScaleTrim
#  define RTE_START_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_SetT1T2OffsetTrim(void);
#  define RTE_STOP_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AnaHwTrq_SCom_SetT1T2OffsetTrim AnaHwTrq_SCom_SetT1T2OffsetTrim
#  define RTE_START_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_WriteT1T2OffsetTrim(P2CONST(AnaHwTrqTrim_Datatype, AUTOMATIC, RTE_SA_ANAHWTRQ_APPL_DATA) HwTrqTrimDataPtr);
#  define RTE_STOP_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AnaHwTrq_SCom_WriteT1T2OffsetTrim AnaHwTrq_SCom_WriteT1T2OffsetTrim
#  define RTE_START_SEC_AP_ASTLMT_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_ASTLMT_APPL_CODE) AstLmt_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
#  define RTE_STOP_SEC_AP_ASTLMT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_AssistLmtFunc_Scom_ManualTrqCmd AstLmt_Scom_ManualTrqCmd
#  define RTE_START_SEC_SA_CMMTRCURR3PHS_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr_SCom_CalGain(void);
#  define RTE_STOP_SEC_SA_CMMTRCURR3PHS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_CmMtrCurr3Phs_SCom_CalGain CmMtrCurr_SCom_CalGain
#  define RTE_START_SEC_SA_CMMTRCURR3PHS_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurrPhs3_SCom_Phs3CalGain(void);
#  define RTE_STOP_SEC_SA_CMMTRCURR3PHS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_CmMtrCurr3Phs_SCom_CalGainPhs3 CmMtrCurrPhs3_SCom_Phs3CalGain
#  define RTE_START_SEC_SA_CMMTRCURR3PHS_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr3Phs_SCom_3PhsCalOffset(void);
#  define RTE_STOP_SEC_SA_CMMTRCURR3PHS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_CmMtrCurr3Phs_SCom_CalOffset3Phs CmMtrCurr3Phs_SCom_3PhsCalOffset
#  define RTE_START_SEC_SA_CMMTRCURR3PHS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr3Phs_SCom_Set3PhsMtrCurrCals(P2CONST(PhaseCurrCal3Phs_DataType, AUTOMATIC, RTE_SA_CMMTRCURR3PHS_APPL_DATA) ShCurrCal3PhsPtr);
#  define RTE_STOP_SEC_SA_CMMTRCURR3PHS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs(arg1) (CmMtrCurr3Phs_SCom_Set3PhsMtrCurrCals(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_DIGCOLPS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_SCom_CustClrTrim(void);
#  define RTE_STOP_SEC_SA_DIGCOLPS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_DigColPs_SCom_CustClearTrim() (DigColPs_SCom_CustClrTrim(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_DIGCOLPS_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_SCom_CustSetTrim(void);
#  define RTE_STOP_SEC_SA_DIGCOLPS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_DigColPs_SCom_CustSetTrim DigColPs_SCom_CustSetTrim
#  define RTE_START_SEC_SA_DIGCOLPS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_SCom_NxtClrTrim(void);
#  define RTE_STOP_SEC_SA_DIGCOLPS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_DigColPs_SCom_NxtClrTrim() (DigColPs_SCom_NxtClrTrim(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_DIGCOLPS_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_DIGCOLPS_APPL_CODE) DigColPs_SCom_NxtSetTrim(void);
#  define RTE_STOP_SEC_SA_DIGCOLPS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_DigColPs_SCom_NxtSetTrim DigColPs_SCom_NxtSetTrim
#  define RTE_START_SEC_AP_GENPOSTRAJ_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_GENPOSTRAJ_APPL_CODE) GenPosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32);
#  define RTE_STOP_SEC_AP_GENPOSTRAJ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_GeneratePosTraj_SCom_SetInputParam(arg1, arg2, arg3) (GenPosTraj_SCom_SetInputParam(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_HWTRQARBN_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQARBN_APPL_CODE) HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim(UInt8 HwTqTrmchNr_Cnt_u08);
#  define RTE_STOP_SEC_SA_HWTRQARBN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim
#  define RTE_START_SEC_SA_HWTRQARBN_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQARBN_APPL_CODE) HwTrqArbn_SCom_SetHwTrqArbOffsetTrim(UInt8 HwTqTrmchNr_Cnt_u08);
#  define RTE_STOP_SEC_SA_HWTRQARBN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim HwTrqArbn_SCom_SetHwTrqArbOffsetTrim
#  define RTE_START_SEC_SA_HWTRQARBN_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQARBN_APPL_CODE) HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(P2CONST(EOLChOffsetTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQARBN_APPL_DATA) EOLChOffsetTrimDataPtr, UInt8 HwTqTrmchNr_Cnt_u08);
#  define RTE_STOP_SEC_SA_HWTRQARBN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim
#  define RTE_START_SEC_SA_MOTMECLPOSN1_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(P2CONST(Float, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_DATA) MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTblResp);
# else
FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(P2CONST(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_DATA) MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTblResp);
# endif
#  define RTE_STOP_SEC_SA_MOTMECLPOSN1_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(arg1, arg2, arg3, arg4) (MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(arg1, arg2, arg3, arg4), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_MOTMECLPOSN2_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_MOTMECLPOSN2_APPL_CODE) MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(P2CONST(Float, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_DATA) MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTblResp);
# else
FUNC(void, RTE_SA_MOTMECLPOSN2_APPL_CODE) MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(P2CONST(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_DATA) MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTblResp);
# endif
#  define RTE_STOP_SEC_SA_MOTMECLPOSN2_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(arg1, arg2, arg3, arg4) (MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(arg1, arg2, arg3, arg4), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_MOTPOSNCMP_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Scom_MotPosnCmpBackEmfWr(P2CONST(UInt16, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_DATA) MotPosnBackEmfWrData, P2VAR(UInt8, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_VAR) MotPosnCmpBackEmfWrResp);
# else
FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Scom_MotPosnCmpBackEmfWr(P2CONST(MotPosnBackEmfData, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_DATA) MotPosnBackEmfWrData, P2VAR(UInt8, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_VAR) MotPosnCmpBackEmfWrResp);
# endif
#  define RTE_STOP_SEC_AP_MOTPOSNCMP_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(arg1, arg2) (MotPosnCmp_Scom_MotPosnCmpBackEmfWr(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_MTRPOS3SINCOS_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_MTRPOS3SINCOS_APPL_CODE) MtrPos3SinCos_Scom_WriteEOLMtrCals(P2CONST(UInt16, AUTOMATIC, RTE_SA_MTRPOS3SINCOS_APPL_DATA) MtrEOLDataPtr, P2VAR(UInt8, AUTOMATIC, RTE_SA_MTRPOS3SINCOS_APPL_VAR) MtrPos3SinCosWrResp);
# else
FUNC(void, RTE_SA_MTRPOS3SINCOS_APPL_CODE) MtrPos3SinCos_Scom_WriteEOLMtrCals(P2CONST(MtrPos3SinCos_EOLwithCRC, AUTOMATIC, RTE_SA_MTRPOS3SINCOS_APPL_DATA) MtrEOLDataPtr, P2VAR(UInt8, AUTOMATIC, RTE_SA_MTRPOS3SINCOS_APPL_VAR) MtrPos3SinCosWrResp);
# endif
#  define RTE_STOP_SEC_SA_MTRPOS3SINCOS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_MtrPos3SinCos_Scom_WriteEOLMtrCals(arg1, arg2) (MtrPos3SinCos_Scom_WriteEOLMtrCals(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_CTRLPOLARITYBRSHLSS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE) Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32);
#  define RTE_STOP_SEC_AP_CTRLPOLARITYBRSHLSS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_Polarity_SCom_SetPolarity(arg1) (Polarity_SCom_SetPolarity(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_CURRPARAMCOMP_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_CURRPARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);
#  define RTE_STOP_SEC_AP_CURRPARAMCOMP_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_SCom_EOLNomMtrParam_Set(arg1, arg2) (SCom_EOLNomMtrParam_Set(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_TSMIT_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_GainReset(void);
#  define RTE_STOP_SEC_AP_TSMIT_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_TSMit_SCom_GainReset() (TSMit_SCom_GainReset(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_TRQCANC_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
FUNC(void, RTE_AP_TRQCANC_APPL_CODE) TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_AP_TRQCANC_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# endif
#  define RTE_STOP_SEC_AP_TRQCANC_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_TrqCanc_Scom_SetCogTrqCal(arg1, arg2) (TrqCanc_Scom_SetCogTrqCal(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_TRQCMDSCL_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Set(Float Par_f32);
#  define RTE_STOP_SEC_AP_TRQCMDSCL_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_TrqCmdScl_SCom_Set(arg1) (TrqCmdScl_SCom_Set(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_TRQOVLSTA_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_TRQOVLSTA_APPL_CODE) TrqOvlSta_SCom_SetGmLoaIgnCntr(UInt16 GmLoaIgnCntr_Cnt_u16);
#  define RTE_STOP_SEC_AP_TRQOVLSTA_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_TrqOvlSta_SCom_SetGmLoaIgnCntr(arg1) (TrqOvlSta_SCom_SetGmLoaIgnCntr(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_VEHDYN_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_VEHDYN_APPL_CODE) VehDyn_SCom_ForceCenter(void);
#  define RTE_STOP_SEC_AP_VEHDYN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_C_VehDyn_SCom_ForceCenter() (VehDyn_SCom_ForceCenter(), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_NTWRAP_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_ClrT1T2OffsetTrim(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim(Float ScaleValue);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_SetT1T2OffsetTrim(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_WriteT1T2OffsetTrim(P2CONST(AnaHwTrqTrim_Datatype, AUTOMATIC, RTE_NTWRAP_APPL_DATA) HwTrqTrimDataPtr);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr3Phs_SCom_CalGain(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr3Phs_SCom_CalGainPhs3(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr3Phs_SCom_CalOffset3Phs(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs(P2CONST(PhaseCurrCal3Phs_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCal3PhsPtr);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_DigColPs_SCom_CustClrTrim(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_DigColPs_SCom_CustSetTrim(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_DigColPs_SCom_NxtClrTrim(void);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_DigColPs_SCom_NxtSetTrim(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_GeneratePosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim(UInt8 HwTqTrmchNr_Cnt_u08);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim(UInt8 HwTqTrmchNr_Cnt_u08);

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(P2CONST(EOLChOffsetTrim_Datatype, AUTOMATIC, RTE_NTWRAP_APPL_DATA) EOLChOffsetTrimDataPtr, UInt8 HwTqTrmchNr_Cnt_u08);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(P2CONST(Float, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotMeclPosn1CoeffTblResp);
# else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(P2CONST(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotMeclPosn1CoeffTblResp);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(P2CONST(Float, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotMeclPosn2CoeffTblResp);
# else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(P2CONST(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotMeclPosn2CoeffTblResp);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotPosnBackEmfWrData, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotPosnCmpBackEmfWrResp);
# else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(P2CONST(MotPosnBackEmfData, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotPosnBackEmfWrData, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotPosnCmpBackEmfWrResp);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrPos3SinCos_Scom_WriteEOLMtrCals(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrEOLDataPtr, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MtrPos3SinCosWrResp);
# else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrPos3SinCos_Scom_WriteEOLMtrCals(P2CONST(MtrPos3SinCos_EOLwithCRC, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrEOLDataPtr, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MtrPos3SinCosWrResp);
# endif

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrap_Per1(void);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TSMit_SCom_GainReset(void);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID);
# endif

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCmdScl_SCom_Set(Float Par_f32);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqOvlSta_SCom_SetGmLoaIgnCntr(UInt16 GmLoaIgnCntr_Cnt_u16);

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_VehDyn_SCom_ForceCenter(void);

# define RTE_STOP_SEC_NTWRAP_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_AnaHwTrq_SCom_DataOutOfRange (20U)

#  define RTE_E_AssistLmtFunc_Scom_RTE_E_MtrTrqLmt_SCom_VSTH (34U)

#  define RTE_E_AssistLmtFunc_Scom_RTE_E_OK (1U)

#  define RTE_E_CmMtrCurr3Phs_SCom_ConditionNotCorrect (34U)

#  define RTE_E_CmMtrCurr3Phs_SCom_CurrentOutOfRange (20U)

#  define RTE_E_CmMtrCurr3Phs_SCom_VehSpdOutofRange (21U)

#  define RTE_E_DigColPs_SCom_ConditionsNotCorrect (34U)

#  define RTE_E_HwTrqArbn_SCom_DataOutOfRange (20U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_NtWrap.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_NTWRAP_H */
