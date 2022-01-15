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
 *          File:  Rte.c
 *     Workspace:  C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Mar 21 14:08:41 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 **********************************************************************************************************************
  MISRA rule:   8.8: '%s' has external linkage but is being defined without any previous declaration.
  MISRA rule:  8.10: The object '%1s' is only referenced in the translation unit where it is defined.
  MISRA rule:  10.6: Integer literal constant is of an unsigned type but does not include a U suffix.
  MISRA rule:  13.3: Floating-point expressions shall not be tested for equality or inequality.
  MISRA rule:  14.1: The function '%1s' is defined but is not used within this project.
  MISRA rule:  14.2: This statement has no side-effect - it can be removed.
  MISRA rule:  14.3: Empty statement (';' on its own) - if this is deliberate, it is best to put ';' on a line by itself.
  MISRA rule:  18.4: An object of union type has been defined.
  MISRA rule:  19.1: #include statements in a file should only be preceded by other preprocessor directives or comments.
  MISRA rule:  19.4: Macro defines an unrecognised code-fragment.
  MISRA rule:  19.7: A function could probably be used instead of this function-like macro.
  MISRA rule:  19.8: [U] Macro argument is empty.
  MISRA rule: 12.10: The comma operator has been used outside a for-loop header.
  MISRA rule: 19.13: The # and ## preprocessor directives should not be used.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Rte_Type.h"
#include "Rte_Main.h"

#define RTE_CORE
#include "Rte_Ap_AbsHwPos.h"
#include "Rte_Ap_ActivePull.h"
#include "Rte_Ap_ApXcp.h"
#include "Rte_Ap_Assist.h"
#include "Rte_Ap_AssistFirewall.h"
#include "Rte_Ap_AstLmt.h"
#include "Rte_Ap_AvgFricLrn.h"
#include "Rte_Ap_BVDiag.h"
#include "Rte_Ap_BattVltg.h"
#include "Rte_Ap_BattVltgCorrln.h"
#include "Rte_Ap_ChkPtAp10.h"
#include "Rte_Ap_ChkPtAp8.h"
#include "Rte_Ap_ChkPtAp9.h"
#include "Rte_Ap_ComplErr.h"
#include "Rte_Ap_CtrlPolarityBrshlss.h"
#include "Rte_Ap_CurrCmd.h"
#include "Rte_Ap_CurrParamComp.h"
#include "Rte_Ap_CustPerSrvcs.h"
#include "Rte_Ap_Damping.h"
#include "Rte_Ap_DampingFirewall.h"
#include "Rte_Ap_DemIf.h"
#include "Rte_Ap_DiagMgr10.h"
#include "Rte_Ap_DiagMgr8.h"
#include "Rte_Ap_DiagMgr9.h"
#include "Rte_Ap_DigPhsReasDiag.h"
#include "Rte_Ap_EOTActuatorMng.h"
#include "Rte_Ap_ElePwr.h"
#include "Rte_Ap_EtDmpFw.h"
#include "Rte_Ap_FltInjection.h"
#include "Rte_Ap_FrqDepDmpnInrtCmp.h"
#include "Rte_Ap_GMStrtStop.h"
#include "Rte_Ap_GenPosTraj.h"
#include "Rte_Ap_GmPwrpkSrvDataRcvry.h"
#include "Rte_Ap_HOWDetect.h"
#include "Rte_Ap_HiLoadStall.h"
#include "Rte_Ap_HighFreqAssist.h"
#include "Rte_Ap_HwPwrUpSeq.h"
#include "Rte_Ap_HystComp.h"
#include "Rte_Ap_LmtCod.h"
#include "Rte_Ap_LoaMgr.h"
#include "Rte_Ap_LrnEOT.h"
#include "Rte_Ap_MotAgCorrln.h"
#include "Rte_Ap_MotPosnCmp.h"
#include "Rte_Ap_MtrTempEst.h"
#include "Rte_Ap_PICurrCntrl.h"
#include "Rte_Ap_PeakCurrEst.h"
#include "Rte_Ap_PosServo.h"
#include "Rte_Ap_PwrDscntDuInv.h"
#include "Rte_Ap_PwrLmtFuncCr.h"
#include "Rte_Ap_QuadDet.h"
#include "Rte_Ap_ReturnFirewall.h"
#include "Rte_Ap_SASPlausDiag.h"
#include "Rte_Ap_SignlCondn.h"
#include "Rte_Ap_SnsrOffsCorrn.h"
#include "Rte_Ap_SnsrOffsLrng.h"
#include "Rte_Ap_SrlComInput.h"
#include "Rte_Ap_SrlComOutput.h"
#include "Rte_Ap_StOpCtrl.h"
#include "Rte_Ap_StaMd.h"
#include "Rte_Ap_StaMd8.h"
#include "Rte_Ap_StaMd9.h"
#include "Rte_Ap_StabilityComp.h"
#include "Rte_Ap_StabilityComp2.h"
#include "Rte_Ap_Sweep.h"
#include "Rte_Ap_Sweep2.h"
#include "Rte_Ap_TSMit.h"
#include "Rte_Ap_ThrmlDutyCycle.h"
#include "Rte_Ap_TqRsDg.h"
#include "Rte_Ap_TranlDampg.h"
#include "Rte_Ap_TrqArblim.h"
#include "Rte_Ap_TrqCanc.h"
#include "Rte_Ap_TrqCmdScl.h"
#include "Rte_Ap_TrqLOA.h"
#include "Rte_Ap_TrqOsc.h"
#include "Rte_Ap_TrqOvlSta.h"
#include "Rte_Ap_TuningSelAuth.h"
#include "Rte_Ap_VehDyn.h"
#include "Rte_Ap_VehPwrMd.h"
#include "Rte_Ap_VehSpdArbn.h"
#include "Rte_Ap_VehSpdLmt.h"
#include "Rte_Ap_WIRInputQual.h"
#include "Rte_Ap_WhlImbRej.h"
#include "Rte_Ap_ePWM2.h"
#include "Rte_CDD.h"
#include "Rte_Cd_Nhet1CfgAndUse.h"
#include "Rte_Cd_PhaseFdbkMeas.h"
#include "Rte_Cd_uDiag.h"
#include "Rte_ComM.h"
#include "Rte_CtrldVelRtn.h"
#include "Rte_IoHwAbstraction.h"
#include "Rte_IoHwAbstractionUsr.h"
#include "Rte_NexteerLibs.h"
#include "Rte_NtWrap.h"
#include "Rte_NvM.h"
#include "Rte_NvMProxy.h"
#include "Rte_RteErrata10.h"
#include "Rte_RteErrata8.h"
#include "Rte_RteErrata9.h"
#include "Rte_Sa_AnaHwTrq.h"
#include "Rte_Sa_CDDInterface.h"
#include "Rte_Sa_CmMtrCurr3Phs.h"
#include "Rte_Sa_CtrlTemp.h"
#include "Rte_Sa_DigColPs.h"
#include "Rte_Sa_HwTqCorrln.h"
#include "Rte_Sa_HwTrqArbn.h"
#include "Rte_Sa_MotMeclPosn1.h"
#include "Rte_Sa_MotMeclPosn2.h"
#include "Rte_Sa_MtrDrvDiag.h"
#include "Rte_Sa_MtrPos3SinCos.h"
#include "Rte_Sa_MtrVel.h"
#include "Rte_Sa_MtrVel2.h"
#include "Rte_Sa_MtrVel3.h"
#include "Rte_Sa_OvrVoltMon.h"
#include "Rte_Sa_ShtdnMech.h"
#include "Rte_Sa_TmplMonrDualIvtr.h"
#include "Rte_Sa_TmplMonrDualIvtr2.h"
#include "Rte_WdgM.h"

#include "Os.h"

/* Os.h Compatibility Check */
#ifndef RTE_OS_VERSION
# if defined (OS_AR_MAJOR_VERSION) && defined (OS_AR_MINOR_VERSION)
#  define RTE_OS_VERSION ((OS_AR_MAJOR_VERSION * 10) + OS_AR_MINOR_VERSION)
# endif
#endif
#if !defined (OS_VENDOR_ID)
# define RTE_INCOMPATIBLE_OS
#else
# if (OS_VENDOR_ID != RTE_VENDOR_ID)
#  define RTE_INCOMPATIBLE_OS
# endif
#endif
#if defined (RTE_INCOMPATIBLE_OS)
# error "Incompatible AUTOSAR OS. The MICROSAR RTE requires MICROSAR OS if memory protection is enabled!"
#endif

#include "Rte_Hook.h"

/* AUTOSAR 2.1 compatibility */
#if !defined (STATIC) && defined (_STATIC_)
# define STATIC _STATIC_
#endif

#ifndef V_USE_DUMMY_STATEMENT
# define V_USE_DUMMY_STATEMENT STD_OFF
#endif


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

typedef unsigned int Rte_BitType;


/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/


#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_HandwheelAuthority_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_HandwheelPosition_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_AbsHwPos_HwPosSource_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_RelHwPos_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_SrlComHwPos_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_AbsHwPos_SrlComHwPosStatus_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_ActivePull_PullCmpLongTermIntgtrSt_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_ActivePull_PullCmpShoTermIntgtrSt_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_ActivePull_PullCompCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_AssistFirewall_AsstFirewallActive_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_AssistFirewall_CombinedAssist_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_AstLmt_LimitPercentFiltered_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_AstLmt_PreLimitForStall_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_AstLmt_PreLimitTorque_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_AstLmt_SumLimTrqCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_AstLmt_TrqLimitMin_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_AvgFricLrn_EstFric_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_AvgFricLrn_FricOffset_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_AvgFricLrn_SatEstFric_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_BattVltg_BrdgVltg_Volt_f32 = 5.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_Ap_BattVltgCorrln_BattSwdVltgCorrlnSts_Cnt_u08 = 7U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_Ap_BattVltgCorrln_BattVltgCorrlnIdptSig_Cnt_u08 = 3U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_BattVltgCorrln_DftBrdgVltgActv_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_BattVltgCorrln_SwdVltgLimd_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn1Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn2Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn3Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn4Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn5Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn6Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn7Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwPosn8Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq1Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq2Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq3Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq4Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq5Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq6Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq7Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_HwTq8Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotElecMeclPolarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn1Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn2Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn3Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn4Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn5Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn6Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn7Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn8Polarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_CtrlPolarityBrshlss_MotVelPolarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_DampingFirewall_CombinedDamping_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_ElePwr_ElectricPower_Watt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_ElePwr_SupplyCurrent_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_EtDmpFw_EOTDampingLtd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_GMStrtStop_SSScale_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_GMStrtStop_SSSlew_UlspS_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SS_State_enum, RTE_VAR_INIT) Rte_Ap_GMStrtStop_SSState_State_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_GenPosTraj_PosTrajHwAngle_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_HOWDetect_HOWEstimate_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_Ap_HOWDetect_HOWState_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_HwPwrUpSeq_MtrDrvr0InitStart_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_HwPwrUpSeq_MtrDrvr1InitStart_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_HwPwrUpSeq_OverVltgMonStart_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_HwPwrUpSeq_PwrDiscATestStart_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_HwPwrUpSeq_PwrDiscBTestStart_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_HwPwrUpSeq_TMFTestStart_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_LmtCod_EOTGainLtd_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_LmtCod_EOTLimitLtd_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_LmtCod_OutputRampMultLtd_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_LmtCod_StallLimitLtd_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_LmtCod_ThermalLimitLtd_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_LmtCod_VehSpdLimitLtd_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_LoaMgr_HwTqLoaMtgtnEn_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_LoaMgr_IvtrLoaMtgtnEn_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(LOA_State_enum, RTE_VAR_INIT) Rte_Ap_LoaMgr_LOASt_State_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_LoaMgr_LoaRateLimit_UlspS_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_LoaMgr_LoaScaleFctr_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_LoaMgr_MotAgLoaMtgtnEn_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_LoaMgr_MotCurrLoaMtgtnEn_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_LrnEOT_CCWFound_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_LrnEOT_CCWPosition_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_LrnEOT_CWFound_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_LrnEOT_CWPosition_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_Ap_MotAgCorrln_MtrPosCorrlnSts_Cnt_u16 = 7U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_Ap_MotAgCorrln_MtrPosIdptSig_Cnt_u08 = 3U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_MotPosnCmp_MotPosnCumvAlgndCrf_Deg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_MotPosnCmp_MotPosnCumvAlgndMrf_Deg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_MtrTempEst_AssistMechTempEst_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_MtrTempEst_CuTempEst_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_MtrTempEst_MagTempEst_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_MtrTempEst_SiTempEst_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_PosServo_PosSrvoCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_PosServo_PosSrvoReturnSclFct_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_PosServo_PosSrvoSmoothEnable_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_PwrDscntDuInv_PwrDiscATestComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_PwrDscntDuInv_PwrDiscBTestComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_PwrLmtFuncCr_FltTrqLmt_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_PwrLmtFuncCr_MRFMtrTrqCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_PwrLmtFuncCr_ThresholdExceeded_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_SignlCondn_EstimdLatAcce_MpSecSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_SignlCondn_EstimdLatAcceValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleLatAcceValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleLatAccel_MpSecSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleLonAccel_KphpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleLonAccelValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleYawRate_DegpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleYawRateValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_SnsrOffsCorrn_HwTqCorrd_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_SnsrOffsCorrn_YawRateCorrd_DegpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_SnsrOffsLrng_HwAgOffs_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_SnsrOffsLrng_HwTqOffs_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_SnsrOffsLrng_VehYawRateOffs_DegpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_StabilityComp2_SysAssistCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_Sweep_OutputHwTrq_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_Sweep2_OutputMtrTrq_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TSMit_TSMitCommand_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_TSMit_TSMitLearningEnabled_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_ThrmlDutyCycle_DutyCycleLevel_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_ThrmlDutyCycle_ThermLimitPerc_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_ThrmlDutyCycle_ThermalLimit_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_Ap_TqRsDg_MtrCurrIdptSig_Cnt_u08 = 2U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TranlDampg_CRFMtrTrqCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_TranlDampg_CntrlDampComp_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TranlDampg_MRFMtrTrqCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TranlDampg_SysC_CRFMtrTrqCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TranlDampg_SysC_MRFMtrTrqCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TrqArblim_AssistDDFactor_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TrqArblim_DampingDDFactor_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_TrqArblim_ESCIsLimited_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TrqArblim_ESCTorqueDelivered_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TrqArblim_IqTrqOv_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TrqArblim_LKATorqueDelivered_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TrqArblim_OpTrqOv_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_TrqArblim_PullCmpCustLrngDi_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TrqArblim_ReturnDDFactor_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_TrqLOA_TrqLOAAvail_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TrqLOA_TrqLOACmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TrqOsc_TrqOscCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_TrqOsc_TrqOscDCExceeded_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_Ap_TuningSelAuth_ActiveTunPers_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_Ap_TuningSelAuth_ActiveTunSet_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_VehSpdArbn_NonSecureVehSpd_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_VehSpdArbn_NonSecureVehSpdVld_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_WIRInputQual_QualWhlFreqL_Hz_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_WIRInputQual_QualWhlFreqR_Hz_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_WIRInputQual_WhlFreqQualified_Cnt_lgc = TRUE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_WhlImbRej_WIRCmdAmpBlnd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_WhlImbRej_WhlImbRejCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Assist_BaseAssistCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_ADCMtrCurrA_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_ADCMtrCurrB_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_ADCMtrCurrC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_BallNutTempEstSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_CorrMtrCurrA_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_CorrMtrCurrB_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_CorrMtrCurrC_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_CorrMtrCurrPosition_Rev_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_CorrectedElecMtrPosFloat_Rev_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_DampingSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_DftAsstTbl_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_DigMSBArbnMtrPosMecl_Rev_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_DisableCEBusNormComm_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_DisableHSBusNormComm_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_DrivingDynSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_DwnldAsstGain_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_EOTImpactSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_EOTThermalSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_EngONSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface_ExpectedOnTimeA_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface_ExpectedOnTimeB_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface_ExpectedOnTimeC_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_FeatureControl_Cnt_lgc = TRUE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_FreqDepDmpSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_FricLrnSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_HysAddSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_HystCompSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_IgnCnt_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_KinIntDiagSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt16, RTE_VAR_INIT) Rte_CDDInterface_LRPRPhaseadvanceCaptured_Cnt_s16 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_LimitSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(ManufModeType, RTE_VAR_INIT) Rte_CDDInterface_MEC_Cnt_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_MfgDiagInhibit_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_ModIdxFinal_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_ModIdxSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface_MotMeclPosn1MeasdTi_USec_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_MotMeclPosn1ParityFaultAccum_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_MotMeclPosn1RawErrReg_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_MotMeclPosn1RevM_Rev_u0p16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_CDDInterface_MotMeclPosn1RollgCntr_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface_MotMeclPosn2MeasdTi_USec_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_MotMeclPosn2ParityFaultAccum_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_MotMeclPosn2RawErrReg_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_MotMeclPosn2RevM_Rev_u0p16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_CDDInterface_MotMeclPosn2RollgCntr_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_MotPosnCmpMotPosnCumvAlgnd_Rev_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_MotPosnCmpMotPosnElec_Rev_u0p16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_MotorVariant_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_MtrCtrlMtrDaxVoltage_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_MtrCtrlMtrQaxVoltage_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_MtrCurrDax_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_MtrCurrQax_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CDDInterface_MtrCurrQaxFinalRef_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_MultIgnSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_CDDInterface_NVMMotorVariant_Cnt_u08 = 7U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_NVMSensorData_Cnt_lgc = TRUE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_ParkAstSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_PosTrajEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_PullCompLrnSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_PullCompSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_ReturnSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_RxMsgsSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_SftEndStpSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_CDDInterface_SrlComSvcDft_Cnt_b32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_SysCBattSwitched1_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_SysCBattSwitched2_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_SysCT1ADC_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_SysCT2ADC_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_ThermalDCSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_TrqRmpSrlComSvcDft_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_WIRMfgEnabled_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SigQlfr_State_enum, RTE_VAR_INIT) Rte_Cd_Nhet1CfgAndUse_HwTq3Qlfr_State_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_Cd_Nhet1CfgAndUse_HwTq3RollgCntr_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Cd_Nhet1CfgAndUse_HwTq3Val_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SigQlfr_State_enum, RTE_VAR_INIT) Rte_Cd_Nhet1CfgAndUse_HwTq4Qlfr_State_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_Cd_Nhet1CfgAndUse_HwTq4RollgCntr_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Cd_Nhet1CfgAndUse_HwTq4Val_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeA_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeB_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeC_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeD_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeE_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeF_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ComplErr_ComplErr_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CtrlTemp_FiltMeasTemp_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CtrldVelRtn_ReturnCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CurrCmd_MtrCurrAngle_Rev_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CurrCmd_MtrCurrDaxRef_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CurrCmd_MtrCurrQaxRef_Amp_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CurrCmd_MtrVoltDaxFFStatic_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CurrCmd_MtrVoltQaxFFStatic_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CurrParamComp_EstKe_VpRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CurrParamComp_EstLd_Henry_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CurrParamComp_EstLq_Henry_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CurrParamComp_EstR_Ohm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_CustPerSrvcs_ThermalLimitFlagCntr_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Damping_DampingCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_DiagMgr_DiagNoofActiveInverter_Cnt_u08 = 2U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_DiagMgr_DiagRampRate_XpmS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_DiagMgr_DiagRampValue_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagRmpToZeroActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsCtrldDisRmpPres_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsDefTemp_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsDefVehSpd_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsHWASbSystmFltPres_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsInverter1Inactive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsInverter2Inactive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsRecRmpToZeroFltPres_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsScomHWANotValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsWIRDisable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_DigColPs_I2CHwAbsPos_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DigColPs_I2CHwAbsPosValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_DigColPs_TrimComp_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_EOTActuatorMng_AssistEOTDamping_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_EOTActuatorMng_AssistEOTGain_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_EOTActuatorMng_AssistEOTLimit_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HiLoadStall_AssistStallLimit_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HighFreqAssist_HighFreqAssist_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_HystComp_HysteresisComp_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_Batt_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_BattSwitched1_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_BattSwitched2_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_MtrPos3Con_Volt_u3p13 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_MtrPos3Sin_Volt_u3p13 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_SysCBattSwitched1_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_SysCBattSwitched2_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_SysCT1_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_SysCT2_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_T1ADC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_T2ADC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_TemperatureADC_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_Vref3p3_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_Vref5vp1_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_IoHwAbstractionUsr_Vref5vp2_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_PeakCurrEst_EstPkCurr_AmpSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_PeakCurrEst_FiltEstPkCurr_AmpSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_QuadDet_InstMtrDir_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_QuadDet_MtrQuad_Cnt_u08 = 1U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_ReturnFirewall_LimitedReturn_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SigQlfr_State_enum, RTE_VAR_INIT) Rte_Sa_AnaHwTrq_HwTq1Qlfr_State_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_Sa_AnaHwTrq_HwTq1RollgCntr_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_AnaHwTrq_HwTq1Val_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SigQlfr_State_enum, RTE_VAR_INIT) Rte_Sa_AnaHwTrq_HwTq2Qlfr_State_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_Sa_AnaHwTrq_HwTq2RollgCntr_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_AnaHwTrq_HwTq2Val_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_Sa_CmMtrCurr3Phs_ComOffset_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Sa_CmMtrCurr3Phs_CurrentGainSvc_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_CmMtrCurr3Phs_MtrCurrATempOffset_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_CmMtrCurr3Phs_MtrCurrBTempOffset_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_CmMtrCurr3Phs_MtrCurrCTempOffset_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_Sa_CmMtrCurr3Phs_MtrCurrIdptSig_Cnt_u08 = 2U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_Sa_HwTqCorrln_HwTqCorrlnSts_Cnt_u16 = 15U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_Sa_HwTqCorrln_HwTqIdptSig_Cnt_u08 = 4U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_Sa_HwTqCorrln_HwTqVldSrcSig_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_HwTrqArbn_ArbnAbsHwTqErr_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SigQlfr_State_enum, RTE_VAR_INIT) Rte_Sa_MotMeclPosn1_MotPosnQlfr_State_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SigQlfr_State_enum, RTE_VAR_INIT) Rte_Sa_MotMeclPosn2_MotPosnQlfr_State_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Sa_MtrDrvDiag_GateDrive1ResetActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Sa_MtrDrvDiag_GateDrive2ResetActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Sa_MtrDrvDiag_MtrDrvr1InitComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Sa_MtrDrvDiag_MtrDrvr2InitComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_Sa_MtrPos3SinCos_MtrPos3Mech_Rev_u0p16 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SigQlfr_State_enum, RTE_VAR_INIT) Rte_Sa_MtrPos3SinCos_MtrPos3Qlfr_State_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_Sa_MtrPos3SinCos_MtrPos3RollgCntr_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Sa_MtrVel_HwVelValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_MtrVel_SysCHandwheelVel_HwRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_MtrVel_SysCMotorVelMRF_MtrRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_MtrVel2_SysCDiagHwVel_HwRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Sa_MtrVel2_SysCDiagMtrVelMRF_MtrRadpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Sa_TmplMonrDualIvtr_TMFTestComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_APAMfgEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_APANonRecoverableFaults_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_APARecoverableFaults_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_APARequest_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_DesiredTunPers_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_ESCCmd_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_ESCFault_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_ESCMfgEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_ESCRequest_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_EngRunAtvForCTCInhibit_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HapticRequest_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_LKACmd_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_LKAFault_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_LKAInhibit_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_LKAMfgEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_LKARequest_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_MaxSecureVehicleSpeed_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_MinSecureVehicleSpeed_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_PowertrainCrankActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SPMForCTCInhibit_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SWARTrgtAngRequest_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_ShiftLeverIsInReverse_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComABSActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComAmbTemp_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComESCActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComEngOn_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComEngTemp_DegC_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComEngineSpeed_Rpm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComLWhlSpd_Hz_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComLatAccel_MpSecSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComLatAccelValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComRWhlSpd_Hz_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComSPMOn_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SysPwrMd, RTE_VAR_INIT) Rte_SrlComInput_SrlComSysPwrMd_Cnt_enum = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComTCSActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComTSMitDefeat_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComTransmissionTrq_TransNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComVehLonAccelValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComVehSpd_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComVehicleLonAccel_MpSecSq_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComYawRate_DegpS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComYawRateValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_StrtStopFaultActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_VehicleSpeedValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComOutput_BusOffCE_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_SrlComOutput_BusOffHS_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_StOpCtrl_OutputRampMult_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_StOpCtrl_SysStReqDi_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_StaMd_InitiatePwrDnFastWrite_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_StaMd_InitiatePwrDnNormalWrite_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_StaMd_PwrDnFastWriteComplete_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_StabilityComp_AssistCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_TrqOvlSta_APADrvrInterventionDetected_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(APA_State_enum, RTE_VAR_INIT) Rte_TrqOvlSta_APAState_State_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(ESC_State_enum, RTE_VAR_INIT) Rte_TrqOvlSta_ESCState_State_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Haptic_State_enum, RTE_VAR_INIT) Rte_TrqOvlSta_GMOSHOscillateState_State_enum = 1U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(LKA_State_enum, RTE_VAR_INIT) Rte_TrqOvlSta_LKAState_State_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_TrqOvlSta_LkaDrvrIntvDetd_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_TrqOvlSta_PosServEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_TrqOvlSta_PosSrvoHwAngle_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_TrqOvlSta_TrqOscAmp_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_TrqOvlSta_TrqOscEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_TrqOvlSta_TrqOscFreq_Hz_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VehDyn_SensorlessAuthority_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VehDyn_SensorlessHwPos_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehPwrMd_ATermActive_Cnt_lgc = TRUE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehPwrMd_CTermActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_VehPwrMd_DftVehSpdEna_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VehPwrMd_OperRampRate_XpmS_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VehPwrMd_OperRampValue_Uls_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VehPwrMd_SysOperMotTqCmdSca_Uls_f32 = 1.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_VehSpdLmt_AstVehSpdLimit_MtrNm_f32 = 8.8F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_Xcp_ActiveTunOvrPtrAddr_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(TuningSessionAddrPtrEnum, RTE_VAR_INIT) Rte_Xcp_TuningSessionActPtr_Cnt_u8 = 255U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_AbsHwPos_TurnsCntrValidity_Cnt_u08 = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_ActivePull_PullCmpLongTermIntgtrStOffs_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_ActivePull_PullCmpShoTermIntgtrStOffs_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_AstLmt_EotActvCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_AstLmt_LrnPnCtrEnable_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_AstLmt_LrnPnCtrTCmd_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_DigPhsReasDiag_PDActivateTest_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SteerMod_enum, RTE_VAR_INIT) Rte_Ap_LoaMgr_SteerMod_Cnt_enum = 0U;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_LoaMgr_TloaDi_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_MtrTempEst_ScomAMDefeat_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_MtrTempEst_ScomTempDataRcvd_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_PwrLmtFuncCr_AltFaultActive_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt32, RTE_VAR_INIT) Rte_Ap_ThrmlDutyCycle_IgnTimeOff_Cnt_u32 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_ThrmlDutyCycle_VehTimeValid_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TqRsDg_DervLambdaAlphaDiag_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TqRsDg_DervLambdaBetaDiag_Volt_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_TrqLOA_TrqLoaDi_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Ap_TrqLOA_VehWhlBas_mm_f32 = 3000.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_Ap_TrqLOA_VehWhlBasVld_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Assist_HwTrqHysAdd_HwNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_CDDInterface_AssistAssemblyPolarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt8, RTE_VAR_INIT) Rte_CDDInterface_MtrPosPolarity_Cnt_s08 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(SInt16, RTE_VAR_INIT) Rte_CDDInterface_MtrTrqCmdSign_Cnt_s16 = 0;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_CtrldVelRtn_ReturnOffset_HwDeg_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CurrCmd_DualEcuMotCtrlMtgnEna_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CurrParamComp_DualEcuFltMtgtnEna_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_CurrParamComp_IvtrLoaMtgtnEn_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_Damping_CustomDamp_MtrNm_f32 = 0.0F;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Boolean, RTE_VAR_INIT) Rte_PeakCurrEst_DualEcuMotCtrlMtgnEna_Cnt_lgc = FALSE;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(UInt16, RTE_VAR_INIT) Rte_Xcp_DesiredTunSet_Cnt_u16 = 0U;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"



/**********************************************************************************************************************
 * Constants
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONST(DT_SinTanLkpTbl_f32, RTE_CONST) Rte_T_SINELKPTBL_ULS_F32 = {
  0.0F, 0.00818114F, 0.016361732F, 0.024541229F, 0.032719083F, 0.040894747F, 0.049067674F, 0.057237317F, 0.065403129F, 
  0.073564564F, 0.081721074F, 0.089872115F, 0.09801714F, 0.106155605F, 0.114286965F, 0.122410675F, 0.130526192F, 
  0.138632973F, 0.146730475F, 0.154818155F, 0.162895473F, 0.170961889F, 0.179016861F, 0.187059852F, 0.195090322F, 
  0.203107734F, 0.211111552F, 0.21910124F, 0.227076263F, 0.235036087F, 0.24298018F, 0.250908009F, 0.258819045F, 
  0.266712758F, 0.274588618F, 0.2824461F, 0.290284677F, 0.298103825F, 0.30590302F, 0.31368174F, 0.321439465F, 
  0.329175676F, 0.336889853F, 0.344581482F, 0.352250048F, 0.359895037F, 0.367515937F, 0.375112238F, 0.382683432F, 
  0.390229013F, 0.397748475F, 0.405241314F, 0.41270703F, 0.420145122F, 0.427555093F, 0.434936447F, 0.44228869F, 
  0.44961133F, 0.456903876F, 0.46416584F, 0.471396737F, 0.478596082F, 0.485763394F, 0.492898192F, 0.5F, 0.507068342F, 
  0.514102744F, 0.521102737F, 0.528067851F, 0.53499762F, 0.541891581F, 0.548749271F, 0.555570233F, 0.562354009F, 
  0.569100146F, 0.575808191F, 0.582477697F, 0.589108216F, 0.595699305F, 0.602250522F, 0.608761429F, 0.615231591F, 
  0.621660573F, 0.628047947F, 0.634393284F, 0.64069616F, 0.646956153F, 0.653172843F, 0.659345815F, 0.665474656F, 
  0.671558955F, 0.677598305F, 0.683592302F, 0.689540545F, 0.695442635F, 0.701298178F, 0.707106781F, 0.712868056F, 
  0.718581618F, 0.724247083F, 0.729864073F, 0.735432211F, 0.740951125F, 0.746420446F, 0.751839808F, 0.757208847F, 
  0.762527204F, 0.767794524F, 0.773010453F, 0.778174644F, 0.783286749F, 0.788346428F, 0.79335334F, 0.798307152F, 
  0.803207532F, 0.80805415F, 0.812846685F, 0.817584813F, 0.822268219F, 0.826896589F, 0.831469612F, 0.835986984F, 
  0.840448401F, 0.844853565F, 0.849202182F, 0.853493959F, 0.85772861F, 0.861905852F, 0.866025404F, 0.870086991F, 
  0.874090342F, 0.878035187F, 0.881921264F, 0.885748312F, 0.889516075F, 0.893224301F, 0.896872742F, 0.900461152F, 
  0.903989293F, 0.907456928F, 0.910863825F, 0.914209756F, 0.917494496F, 0.920717827F, 0.923879533F, 0.926979401F, 
  0.930017224F, 0.932992799F, 0.935905927F, 0.938756413F, 0.941544065F, 0.944268698F, 0.94693013F, 0.949528181F, 
  0.952062678F, 0.954533451F, 0.956940336F, 0.95928317F, 0.961561798F, 0.963776066F, 0.965925826F, 0.968010935F, 
  0.970031253F, 0.971986645F, 0.973876979F, 0.97570213F, 0.977461975F, 0.979156396F, 0.98078528F, 0.982348519F, 
  0.983846006F, 0.985277642F, 0.986643332F, 0.987942984F, 0.98917651F, 0.990343829F, 0.991444861F, 0.992479535F, 
  0.993447779F, 0.99434953F, 0.995184727F, 0.995953314F, 0.996655239F, 0.997290457F, 0.997858923F, 0.998360601F, 
  0.998795456F, 0.99916346F, 0.999464588F, 0.999698819F, 0.999866138F, 0.999966534F, 1.0F
};
CONST(DT_SinTanLkpTbl_f32, RTE_CONST) Rte_T_TANLKPTBL_ULS_F32 = {
  0.004090638F, 0.012272462F, 0.02045593F, 0.028642137F, 0.036832181F, 0.045027163F, 0.053228185F, 0.061436353F, 
  0.069652776F, 0.077878569F, 0.086114851F, 0.094362747F, 0.102623388F, 0.110897912F, 0.119187464F, 0.127493199F, 
  0.135816279F, 0.144157876F, 0.152519173F, 0.160901363F, 0.16930565F, 0.177733252F, 0.1861854F, 0.194663336F, 
  0.203168319F, 0.211701624F, 0.22026454F, 0.228858373F, 0.237484449F, 0.24614411F, 0.254838719F, 0.26356966F, 
  0.272338336F, 0.281146175F, 0.289994626F, 0.298885164F, 0.307819289F, 0.316798527F, 0.325824432F, 0.334898586F, 
  0.344022602F, 0.353198123F, 0.362426827F, 0.371710423F, 0.381050656F, 0.390449308F, 0.399908199F, 0.409429188F, 
  0.419014177F, 0.42866511F, 0.438383974F, 0.448172804F, 0.458033683F, 0.467968746F, 0.477980176F, 0.488070214F, 
  0.498241156F, 0.508495358F, 0.518835235F, 0.529263268F, 0.539782003F, 0.550394056F, 0.561102113F, 0.571908936F, 
  0.582817365F, 0.593830322F, 0.604950811F, 0.616181926F, 0.627526852F, 0.638988871F, 0.650571362F, 0.662277811F, 
  0.674111811F, 0.686077068F, 0.698177407F, 0.710416776F, 0.722799253F, 0.735329049F, 0.748010517F, 0.760848156F, 
  0.77384662F, 0.787010724F, 0.80034545F, 0.813855957F, 0.827547589F, 0.841425884F, 0.855496581F, 0.869765633F, 
  0.884239215F, 0.898923737F, 0.913825852F, 0.928952473F, 0.944310785F, 0.959908255F, 0.97575265F, 0.991852054F, 
  1.008214881F, 1.024849894F, 1.041766226F, 1.058973397F, 1.076481336F, 1.094300405F, 1.112441422F, 1.130915688F, 
  1.149735011F, 1.168911743F, 1.188458804F, 1.208389721F, 1.228718659F, 1.249460468F, 1.270630717F, 1.292245742F, 
  1.314322696F, 1.336879599F, 1.359935394F, 1.383510008F, 1.407624417F, 1.432300717F, 1.4575622F, 1.483433437F, 
  1.509940366F, 1.53711039F, 1.564972483F, 1.593557306F, 1.622897326F, 1.65302696F, 1.683982719F, 1.715803371F, 
  1.74853012F, 1.782206799F, 1.816880088F, 1.852599743F, 1.889418859F, 1.927394157F, 1.966586293F, 2.007060212F, 
  2.048885533F, 2.092136977F, 2.136894845F, 2.183245548F, 2.231282201F, 2.281105287F, 2.332823403F, 2.386554093F, 
  2.442424793F, 2.500573891F, 2.561151937F, 2.624323002F, 2.690266237F, 2.759177648F, 2.831272122F, 2.906785762F, 
  2.985978571F, 3.069137557F, 3.156580334F, 3.248659312F, 3.345766601F, 3.448339762F, 3.556868595F, 3.671903171F, 
  3.7940634F, 3.924050484F, 4.062660691F, 4.210802034F, 4.369514589F, 4.539995414F, 4.723629328F, 4.92202723F, 
  5.137074201F, 5.370990435F, 5.626409169F, 5.90647743F, 6.214987771F, 6.556552741F, 6.936839169F, 7.362887641F, 
  7.843555652F, 8.390144119F, 9.01730236F, 9.744367451F, 10.59740238F, 11.61239886F, 12.84050299F, 14.35692958F, 
  16.27700796F, 18.78703932F, 22.20881656F, 27.15017067F, 34.91359651F, 48.88558064F, 81.48324021F, 244.460629F, 
  244.460629F
};
CONST(SysOutpCpbySig_Str, RTE_CONST) Rte_T_HWPOSNCOMPINIT_HWDEG_STR = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
};

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/**********************************************************************************************************************
 * Per-Instance Memory
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#include "MemMap.h"

VAR(Float, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_HwTqCorrln_HwTqCor_Ch1CMCLPFSv_HwNm_f32;
VAR(Float, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_HwTqCorrln_HwTqCor_Ch2CMCLPFSv_HwNm_f32;
VAR(Float, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_TrqCmdScl_TorqueCmdSF_Uls_f32;
VAR(UInt16, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Ap_MotPosnCmp_MotPosnCmpMtrPosBackEmf;
VAR(UInt16, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_TrqOvlSta_GmLoaIgnCntr;
VAR(CoggingCancTrq, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Ap_TrqCanc_CogTrqCal;
VAR(CoggingCancTrqRplComp, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Ap_TrqCanc_CogTrqRplComp;
VAR(DT_MotMeclPosnCoeffTbl_f32, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_MotMeclPosn1_MotMeclPosn1CoeffTblData;
VAR(DT_MotMeclPosnCoeffTbl_f32, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_MotMeclPosn2_MotMeclPosn2CoeffTblData;
VAR(EOLHwPosTrimType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_AbsHwPos_EOLVehCntrOffset;
VAR(Polarity_DataType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str;
VAR(TSMit_Disable_Type, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Ap_TSMit_TSMitDisableEOL;
VAR(TSMit_Gain_Type, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Ap_TSMit_TSMitGainLrn;
VAR(EOLNomMtrParamType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_CurrParamComp_EOLNomMtrParam;
VAR(DigColPsEOLType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_DigColPs_DigColPsEOL;
VAR(AnaHwTrqScale_Datatype, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_AnaHwTrq_AnaHwTrqScaleData;
VAR(AnaHwTrqTrim_Datatype, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_AnaHwTrq_AnaHwTrqT1T2TrimData;
VAR(CurrTempOffset3PhsType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_CmMtrCurr3Phs_CurrTempOffset3Phs;
VAR(PhaseCurrCal3Phs_DataType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_CmMtrCurr3Phs_ShCurrCal3Phs;
VAR(EOLChOffsetTrim_Datatype, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_HwTrqArbn_EOLCh1OffsetTrimData;
VAR(EOLChOffsetTrim_Datatype, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_HwTrqArbn_EOLCh2OffsetTrimData;
VAR(MtrPos3SinCos_Str, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_MtrPos3SinCos_MtrPos3_EOLParams;
VAR(VehDyn_DataType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_VehDyn_MotPosReset;

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#include "MemMap.h"

VAR(Float, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_Ap_ActivePull_PullCmpLTComp_HwNm_f32;
VAR(DTCStsFlg, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_SrlComOutput_DTCTrigSts;
VAR(AvgFricLrnType, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_Ap_AvgFricLrn_AvgFricLrnData;
VAR(EOTLearned_DataType, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_Ap_LrnEOT_LearnedEOT;
VAR(SnsrLrndOffs_Str, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_Ap_SnsrOffsLrng_SnsrLrndOffs;
VAR(ThrmlDutyCycle_FltStVal_Datatype, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_FltStVal;

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#include "MemMap.h"


/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_100ms_10, RTE_VAR_NOINIT) Rte_Task_100ms_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_100ms_9, RTE_VAR_NOINIT) Rte_Task_100ms_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_10ms_10, RTE_VAR_NOINIT) Rte_Task_10ms_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_10ms_9, RTE_VAR_NOINIT) Rte_Task_10ms_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_2ms_8, RTE_VAR_NOINIT) Rte_Task_2ms_8;
#define RTE_STOP_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_2ms_9, RTE_VAR_NOINIT) Rte_Task_2ms_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_4ms_10, RTE_VAR_NOINIT) Rte_Task_4ms_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_Init_10, RTE_VAR_NOINIT) Rte_Task_Init_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_Init_8, RTE_VAR_NOINIT) Rte_Task_Init_8;
#define RTE_STOP_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_Init_9, RTE_VAR_NOINIT) Rte_Task_Init_9;
#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_tsTask_Trans_10, RTE_VAR_NOINIT) Rte_Task_Trans_10;
#define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#include "MemMap.h"


/**********************************************************************************************************************
 * Buffer for inter-runnable variables
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

VAR(UInt32, RTE_VAR_INIT) Rte_Irv_NexteerLibs_Time_mS_u32 = 0U;

#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_CODE
#include "MemMap.h"

STATIC FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16 num);
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_Ap_StaMd9_SystemState9_Mode(Rte_ModeType_StaMd_Mode nextMode);
STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_Ap_StaMd9_SystemState9_Mode(Rte_ModeType_StaMd_Mode previousMode);
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_StaMd_SystemState_Mode(Rte_ModeType_StaMd_Mode nextMode);
STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_StaMd_SystemState_Mode(Rte_ModeType_StaMd_Mode previousMode);

#define RTE_STOP_SEC_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/

typedef struct
{
  Rte_ModeType_StaMd_Mode Rte_ModeQueue[1];
} Rte_ModeInfoType_Ap_StaMd8_SystemState8_Mode;

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(Rte_ModeInfoType_Ap_StaMd8_SystemState8_Mode, RTE_VAR_INIT) Rte_ModeInfo_Ap_StaMd8_SystemState8_Mode = {
  {
    RTE_MODE_StaMd_Mode_WARMINIT
  }
};
#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_INIT) Rte_ModeMachine_Ap_StaMd8_SystemState8_Mode = RTE_TRANSITION_StaMd_Mode;
#define RTE_STOP_SEC_VAR_Ap_8_INIT_UNSPECIFIED
#include "MemMap.h"

typedef struct
{
  Rte_ModeType_StaMd_Mode Rte_ModeQueue[1+1];
} Rte_ModeInfoType_Ap_StaMd9_SystemState9_Mode;

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(Rte_ModeInfoType_Ap_StaMd9_SystemState9_Mode, RTE_VAR_INIT) Rte_ModeInfo_Ap_StaMd9_SystemState9_Mode = {
  {
    RTE_MODE_StaMd_Mode_WARMINIT,
    RTE_MODE_StaMd_Mode_WARMINIT
  }
};
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_INIT) Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode = RTE_TRANSITION_StaMd_Mode;
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

typedef struct
{
  Rte_ModeType_StaMd_Mode Rte_ModeQueue[1+1];
} Rte_ModeInfoType_StaMd_SystemState_Mode;

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(Rte_ModeInfoType_StaMd_SystemState_Mode, RTE_VAR_INIT) Rte_ModeInfo_StaMd_SystemState_Mode = {
  {
    RTE_MODE_StaMd_Mode_WARMINIT,
    RTE_MODE_StaMd_Mode_WARMINIT
  }
};
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"
VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_INIT) Rte_ModeMachine_StaMd_SystemState_Mode = RTE_TRANSITION_StaMd_Mode;
#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


CONST(EventMaskType, RTE_CONST) Rte_ModeExitEventMask_Ap_StaMd8_SystemState8_Mode[4] =
{
  (EventMaskType) 0, /* DISABLE */
  Rte_Ev_Run_Ap_DiagMgr8_DiagMgr8_Trns, /* OFF */
  (EventMaskType) 0, /* OPERATE */
  (EventMaskType) 0  /* WARMINIT */
};

CONST(EventMaskType, RTE_CONST) Rte_ModeEntryEventMask_Ap_StaMd8_SystemState8_Mode[4] =
{
  Rte_Ev_Run_RteErrata8_RteErrata8_Trns, /* DISABLE */
  Rte_Ev_Run_RteErrata8_RteErrata8_Trns, /* OFF */
  Rte_Ev_Run_RteErrata8_RteErrata8_Trns, /* OPERATE */
  Rte_Ev_Run_RteErrata8_RteErrata8_Trns  /* WARMINIT */
};


CONST(EventMaskType, RTE_CONST) Rte_ModeExitEventMask_Ap_StaMd9_SystemState9_Mode[4] =
{
  (EventMaskType) 0, /* DISABLE */
  Rte_Ev_OnExit_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF, /* OFF */
  (EventMaskType) 0, /* OPERATE */
  (EventMaskType) 0  /* WARMINIT */
};

CONST(EventMaskType, RTE_CONST) Rte_ModeEntryEventMask_Ap_StaMd9_SystemState9_Mode[4] =
{
  Rte_Ev_Run_RteErrata9_RteErrata9_Trns, /* DISABLE */
  Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF, /* OFF */
  Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OPERATE, /* OPERATE */
  Rte_Ev_Run_RteErrata9_RteErrata9_Trns  /* WARMINIT */
};


CONST(EventMaskType, RTE_CONST) Rte_ModeExitEventMask_StaMd_SystemState_Mode[4] =
{
  (EventMaskType) 0, /* DISABLE */
  Rte_Ev_Run_DiagMgr_DiagMgr10_Trns, /* OFF */
  Rte_Ev_Run_Ap_ePWM2_ePWM2_Trns2, /* OPERATE */
  (EventMaskType) 0  /* WARMINIT */
};

CONST(EventMaskType, RTE_CONST) Rte_ModeEntryEventMask_StaMd_SystemState_Mode[4] =
{
  Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_DISABLE, /* DISABLE */
  Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OFF, /* OFF */
  Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OPERATE, /* OPERATE */
  Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_WARMINIT  /* WARMINIT */
};


#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/**********************************************************************************************************************
 * Trigger Disable Flags
 *********************************************************************************************************************/

#define Rte_TriggerDisableMaxCount_Task_100ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per2 1
#define Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3 2
#define Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per1 1
#define Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_Ap_DiagMgr9_DiagMgr_Per2 1
#define Rte_TriggerDisableMaxCount_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2 2
#define Rte_TriggerDisableMaxCount_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3 2
#define Rte_TriggerDisableMaxCount_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1 2
#define Rte_TriggerDisableMaxCount_Task_10ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per2 1
#define Rte_TriggerDisableMaxCount_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per3 1
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1 1
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per2 1
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per1 1
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1 2
#define Rte_TriggerDisableMaxCount_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per2 1
#define Rte_TriggerDisableMaxCount_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2 2

typedef struct
{
  Rte_BitType Rte_Trigger_Task_100ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per2 : 1;
  Rte_BitType Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2 : 2;
  Rte_BitType Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per3 : 1;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1 : 1;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per1 : 1;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per2 : 1;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2 : 2;
} Rte_Ap_10_TriggerDisableFlagsType;
typedef struct
{
  Rte_BitType Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3 : 2;
  Rte_BitType Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_DiagMgr9_DiagMgr_Per2 : 1;
  Rte_BitType Rte_Trigger_Task_100ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per1 : 1;
  Rte_BitType Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_10ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per2 : 1;
  Rte_BitType Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1 : 2;
  Rte_BitType Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per2 : 1;
  Rte_BitType Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1 : 2;
} Rte_Ap_9_TriggerDisableFlagsType;

#define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(Rte_Ap_10_TriggerDisableFlagsType, RTE_VAR_INIT) Rte_Ap_10_TriggerDisableFlags = {
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  0,
  0,
  1,
  1,
  1,
  0,
  1,
  0,
  1,
  1
};

#define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#include "MemMap.h"


#define Rte_Ap_10_TriggerDisableFlagsInit() (Rte_MemClr(&Rte_Ap_10_TriggerDisableFlags, sizeof(Rte_Ap_10_TriggerDisableFlagsType)))

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

STATIC VAR(Rte_Ap_9_TriggerDisableFlagsType, RTE_VAR_INIT) Rte_Ap_9_TriggerDisableFlags = {
  1,
  0,
  0,
  1,
  0,
  1,
  0,
  1
};

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


#define Rte_Ap_9_TriggerDisableFlagsInit() (Rte_MemClr(&Rte_Ap_9_TriggerDisableFlags, sizeof(Rte_Ap_9_TriggerDisableFlagsType)))


/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if (OSTICKDURATION < 1000)
# error "The MICROSAR RTE does not support OSTICKDURATION < 1000 ns"
#endif

#define RTE_TICKDURATION (OSTICKDURATION / 1000U)
#define RTE_USEC(val) ((TickType)((uint32)(val) / (uint32)RTE_TICKDURATION))
#define RTE_MSEC(val) ((TickType)RTE_CONST_MSEC_##val)
#define RTE_SEC(val)  ((TickType)RTE_CONST_SEC_##val)

#define RTE_MSEC_BASE 1000UL
#define RTE_SEC_BASE  1000000UL

#if ((0) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_0 (((uint32)(0) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_0 ((uint32)(0) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_0 ((uint32)(0) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif

#if ((10) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_10 (((uint32)(10) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_10 ((uint32)(10) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_10 ((uint32)(10) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif

#if ((100) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_100 (((uint32)(100) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_100 ((uint32)(100) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_100 ((uint32)(100) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif

#if ((2) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_2 (((uint32)(2) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_2 ((uint32)(2) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_2 ((uint32)(2) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif

#if ((4) < (0xFFFFFFFFUL / RTE_MSEC_BASE))
# define RTE_CONST_MSEC_4 (((uint32)(4) * RTE_MSEC_BASE) / (uint32)RTE_TICKDURATION)
#else
# if (RTE_TICKDURATION > RTE_MSEC_BASE)
#  define RTE_CONST_MSEC_4 ((uint32)(4) / ((uint32)RTE_TICKDURATION / RTE_MSEC_BASE))
# else
#  define RTE_CONST_MSEC_4 ((uint32)(4) * (RTE_MSEC_BASE / (uint32)RTE_TICKDURATION))
# endif
#endif


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)


/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h"

#if (RTE_TICKDURATION > (100UL * 1000UL))
# error "The cycle time of runnable(s) <AnaHwTrq_Per4>, <GmPwrpkSrvDataRcvry_Per1>, <MotMeclPosn1_Per3>, <HwTqCorrln_Per3>, <uDiagStaticRegs_Per>, <PeakCurrEst_Per2>, <MotMeclPosn2_Per3>, <DigColPs_Per3>, <DiagMgr10_Per>, <HwTrqArbn_Per2>, <CmMtrCurr3Phs_Per1>, <CurrParamComp_Per2>, <ChkPtAp10_100msStart_Per>, <AnaHwTrq_Per3>, <ChkPtAp10_100msEnd_Per>, <NtWrap_Per1> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (100UL * 1000UL))
# error "The cycle time of runnable(s) <ChkPtAp8_100msEnd_Per>, <DiagMgr8_Per>, <ChkPtAp8_100msStart_Per> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (100UL * 1000UL))
# error "The cycle time of runnable(s) <MtrTempEst_Per1>, <SrlComOutput_Per1>, <ActivePull_Per3>, <CtrlTemp_Per2>, <DiagMgr9_Per>, <SrlComInput_Per3>, <ChkPtAp9_100msStart_Per>, <CustPerSrvcs_Per1>, <ChkPtAp9_100msEnd_Per>, <DiagMgr_Per2>, <ThrmlDutyCycle_Per1> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (10UL * 1000UL))
# error "The cycle time of runnable(s) <OvrVoltMon_Per1>, <ShtdnMech_Per1>, <TuningSelAuth_Per1>, <ChkPtAp10_10msEnd_Per>, <ChkPtAp10_10msStart_Per>, <TSMit_Per1>, <CDDInterface_Per4>, <uDiagECC_Per>, <TmplMonrDualIvtr_Per3>, <uDiagVIM_Per>, <AbsHwPos_Per4>, <ElePwr_Per1>, <PwrLmtFuncCr_Per2> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (10UL * 1000UL))
# error "The cycle time of runnable(s) <DemIf_Per1>, <SrlComOutput_Per2>, <VehSpdArbn_Per1>, <SnsrOffsLrng_Per2>, <LrnEOT_Per1>, <BVDiag_Per1>, <AvgFricLrn_Per1>, <ChkPtAp9_10msStart_Per>, <ChkPtAp9_10msEnd_Per>, <ApXcp_Per1>, <SrlComInput_Per2> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (2UL * 1000UL))
# error "The cycle time of runnable(s) <TmplMonrDualIvtr_Per1> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (2UL * 1000UL))
# error "The cycle time of runnable(s) <HOWDetect_Per1>, <AnaHwTrq_Per2>, <TrqArblim_Per1>, <PwrDscntDuInv_Per1>, <DampingFirewall_Per1>, <TrqCanc_Per1>, <AbsHwPos_Per1>, <DiagMgr_Per1>, <TrqCmdScl_Per1>, <MtrDrvDiag_Per1>, <TmplMonrDualIvtr_Per4>, <PeakCurrEst_Per1>, <Assist_Per1>, <GenPosTraj_Per1>, <CDDInterface_Per2>, <TrqOvlSta_Per1>, <WhlImbRej_Per1>, <MotAgCorrln_Per1>, <PwrLmtFuncCr_Per1>, <BattVltg_Per1>, <uDiagLossOfExec_Per2>, <WIRInputQual_Per1>, <StabilityComp_Per1>, <ChkPtAp10_2msEnd_Per>, <HighFreqAssist_Per1>, <Nhet1CfgAndUse_Per1>, <DigColPs_Per1>, <Cd_PhaseFdbkMeas_Per1>, <CmMtrCurr3Phs_Per3>, <TrqOsc_Per1>, <HwPwrUpSeq_Per1>, <TrqLOA_Per1>, <TqRsDg_Per1>, <HystComp_Per1>, <WhlImbRej_Per3>, <SASPlausDiag_Per1>, <SnsrOffsCorrn_Per1>, <AssistFirewall_Per1>, <MtrVel_Per1>, <CurrParamComp_Per1>, <Sweep2_Per1>, <Nhet1CfgAndUse_Per2>, <SystemTime_Per1>, <SignlCondn_Per1>, <Damping_Per1>, <CtrldVelRtn_Per1>, <StrtStop_Per1>, <AbsHwPos_Per2>, <ComplErr_Per1>, <StOpCtrl_Per1>, <VehDyn_Per1>, <MotPosnCmp_Per2>, <IoHwAb_StartADC>, <MtrVel_Per2>, <LmtCod_Per1>, <FrqDepDmpnInrtCmp_Per1>, <CDDInterface_Per1>, <MotMeclPosn1_Per2>, <AstLmt_Per1>, <QuadDet_Per1>, <AnaHwTrq_Per1>, <TmplMonrDualIvtr_Per2>, <ePWM2_Per1>, <ChkPtAp10_2msStart_Per>, <EtDmpFw_Per1>, <PosServo_Per1>, <MtrDrvDiag_Per2>, <TmplMonrDualIvtr2_Per1>, <CmMtrCurr3Phs_Per2>, <MotMeclPosn2_Per2>, <Sweep_Per1>, <Ap_TranlDampg_Per1>, <HwTrqArbn_Per1>, <HwTqCorrln_Per1>, <IoHwAb_ReadADC>, <CurrCmd_Per1>, <ReturnFirewall_Per1>, <MtrPos3SinCos_Per1>, <StaMd_Per1>, <DigPhsReasDiag_Per1>, <EOTActuatorMng_Per1> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (2UL * 1000UL))
# error "The cycle time of runnable(s) <StabilityComp2_Per1>, <ChkPtAp8_2msStart_Per>, <MtrVel2_Per2>, <ChkPtAp8_2msEnd_Per>, <StaMd8_Per1>, <MtrVel2_Per1> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (2UL * 1000UL))
# error "The cycle time of runnable(s) <VehPwrMd_Per1>, <VehSpdLmt_Per1>, <DAQ_2msTL>, <ChkPtAp9_2msEnd_Per>, <HiLoadStall_Per1>, <StaMd9_Per1>, <BattVltgCorrln_Per1>, <ChkPtAp9_2msStart_Per>, <FltInjection_Per1>, <SrlComInput_Per1>, <ActivePull_Per1>, <CtrlTemp_Per1>, <SnsrOffsLrng_Per1>, <ActivePull_Per2> is smaller than the tick time of the operating system."
#endif

#if (RTE_TICKDURATION > (4UL * 1000UL))
# error "The cycle time of runnable(s) <LoaMgr_Per1>, <ChkPtAp10_4msStart_Per>, <AbsHwPos_Per3>, <HwTqCorrln_Per2>, <WhlImbRej_Per2>, <uDiagLossOfExec_Per3>, <DigColPs_Per2>, <ChkPtAp10_4msEnd_Per> is smaller than the tick time of the operating system."
#endif

STATIC FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16 num)
{
  P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = ptr;
  uint16 i;
  for (i = 0; i < num; i++)
  {
    dst[i] = 0;
  }
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void)
{
  /* activate the tasks */
  Rte_Task_Activate(Task_Init_10);
  (void)ActivateTask(Task_Init_10);
  Rte_Task_Activate(Task_Init_8);
  (void)ActivateTask(Task_Init_8);
  Rte_Task_Activate(Task_Init_9);
  (void)ActivateTask(Task_Init_9);
  Rte_Task_Activate(Task_Trans_10);
  (void)ActivateTask(Task_Trans_10);
  Rte_Task_Activate(Task_Trans_8);
  (void)ActivateTask(Task_Trans_8);
  Rte_Task_Activate(Task_Trans_9);
  (void)ActivateTask(Task_Trans_9);

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE_Task_100ms_10_0_100ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(100));
  (void)SetRelAlarm(Rte_Al_TE_Task_100ms_8_0_100ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(100));
  (void)SetRelAlarm(Rte_Al_TE_Task_100ms_9_0_100ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(100));
  (void)SetRelAlarm(Rte_Al_TE_Task_10ms_10_0_10ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(10));
  (void)SetRelAlarm(Rte_Al_TE_Task_10ms_9_0_10ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(10));
  (void)SetRelAlarm(Rte_Al_TE_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per1, RTE_MSEC(0) + (TickType)1, RTE_MSEC(2));
  (void)SetRelAlarm(Rte_Al_TE_Task_2ms_10_0_2ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(2));
  (void)SetRelAlarm(Rte_Al_TE_Task_2ms_8_0_2ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(2));
  (void)SetRelAlarm(Rte_Al_TE_Task_2ms_9_0_2ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(2));
  (void)SetRelAlarm(Rte_Al_TE_Task_4ms_10_0_4ms, RTE_MSEC(0) + (TickType)1, RTE_MSEC(4));

  /* mode management initialization part 2 */
  Rte_Task_SetEvent(Task_Trans_8, Rte_ModeEntryEventMask_Ap_StaMd8_SystemState8_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);
  (void)SetEvent(Task_Trans_8, Rte_ModeEntryEventMask_Ap_StaMd8_SystemState8_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);

  Rte_Task_SetEvent(Task_Trans_9, Rte_ModeEntryEventMask_Ap_StaMd9_SystemState9_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);
  (void)SetEvent(Task_Trans_9, Rte_ModeEntryEventMask_Ap_StaMd9_SystemState9_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);

  Rte_Task_SetEvent(Task_Trans_10, Rte_ModeEntryEventMask_StaMd_SystemState_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);
  (void)SetEvent(Task_Trans_10, Rte_ModeEntryEventMask_StaMd_SystemState_Mode[RTE_MODE_StaMd_Mode_WARMINIT]);


  return RTE_E_OK;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE_Task_100ms_10_0_100ms);
  (void)CancelAlarm(Rte_Al_TE_Task_100ms_8_0_100ms);
  (void)CancelAlarm(Rte_Al_TE_Task_100ms_9_0_100ms);
  (void)CancelAlarm(Rte_Al_TE_Task_10ms_10_0_10ms);
  (void)CancelAlarm(Rte_Al_TE_Task_10ms_9_0_10ms);
  (void)CancelAlarm(Rte_Al_TE_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per1);
  (void)CancelAlarm(Rte_Al_TE_Task_2ms_10_0_2ms);
  (void)CancelAlarm(Rte_Al_TE_Task_2ms_8_0_2ms);
  (void)CancelAlarm(Rte_Al_TE_Task_2ms_9_0_2ms);
  (void)CancelAlarm(Rte_Al_TE_Task_4ms_10_0_4ms);

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) Rte_InitMemory(void)
{
  /* set default values for internal data */
  Rte_AbsHwPos_HandwheelAuthority_Uls_f32 = 0.0F;
  Rte_AbsHwPos_HandwheelPosition_HwDeg_f32 = 0.0F;
  Rte_AbsHwPos_HwPosSource_Cnt_u16 = 0U;
  Rte_AbsHwPos_RelHwPos_HwDeg_f32 = 0.0F;
  Rte_AbsHwPos_SrlComHwPos_HwDeg_f32 = 0.0F;
  Rte_AbsHwPos_SrlComHwPosStatus_Cnt_u16 = 0U;
  Rte_Ap_ActivePull_PullCmpLongTermIntgtrSt_HwNm_f32 = 0.0F;
  Rte_Ap_ActivePull_PullCmpShoTermIntgtrSt_HwNm_f32 = 0.0F;
  Rte_Ap_ActivePull_PullCompCmd_MtrNm_f32 = 0.0F;
  Rte_Ap_AssistFirewall_AsstFirewallActive_Uls_f32 = 0.0F;
  Rte_Ap_AssistFirewall_CombinedAssist_MtrNm_f32 = 0.0F;
  Rte_Ap_AstLmt_LimitPercentFiltered_Uls_f32 = 0.0F;
  Rte_Ap_AstLmt_PreLimitForStall_MtrNm_f32 = 0.0F;
  Rte_Ap_AstLmt_PreLimitTorque_MtrNm_f32 = 0.0F;
  Rte_Ap_AstLmt_SumLimTrqCmd_MtrNm_f32 = 0.0F;
  Rte_Ap_AstLmt_TrqLimitMin_MtrNm_f32 = 0.0F;
  Rte_Ap_AvgFricLrn_EstFric_HwNm_f32 = 0.0F;
  Rte_Ap_AvgFricLrn_FricOffset_HwNm_f32 = 0.0F;
  Rte_Ap_AvgFricLrn_SatEstFric_HwNm_f32 = 0.0F;
  Rte_Ap_BattVltg_BrdgVltg_Volt_f32 = 5.0F;
  Rte_Ap_BattVltgCorrln_BattSwdVltgCorrlnSts_Cnt_u08 = 7U;
  Rte_Ap_BattVltgCorrln_BattVltgCorrlnIdptSig_Cnt_u08 = 3U;
  Rte_Ap_BattVltgCorrln_DftBrdgVltgActv_Cnt_lgc = FALSE;
  Rte_Ap_BattVltgCorrln_SwdVltgLimd_Cnt_lgc = FALSE;
  Rte_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwPosn1Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwPosn2Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwPosn3Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwPosn4Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwPosn5Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwPosn6Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwPosn7Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwPosn8Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwTq1Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwTq2Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwTq3Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwTq4Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwTq5Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwTq6Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwTq7Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_HwTq8Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_MotElecMeclPolarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn1Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn2Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn3Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn4Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn5Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn6Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn7Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn8Polarity_Cnt_s08 = 0;
  Rte_Ap_CtrlPolarityBrshlss_MotVelPolarity_Cnt_s08 = 0;
  Rte_Ap_DampingFirewall_CombinedDamping_MtrNm_f32 = 0.0F;
  Rte_Ap_ElePwr_ElectricPower_Watt_f32 = 0.0F;
  Rte_Ap_ElePwr_SupplyCurrent_Amp_f32 = 0.0F;
  Rte_Ap_EtDmpFw_EOTDampingLtd_MtrNm_f32 = 0.0F;
  Rte_Ap_GMStrtStop_SSScale_Uls_f32 = 1.0F;
  Rte_Ap_GMStrtStop_SSSlew_UlspS_f32 = 1.0F;
  Rte_Ap_GMStrtStop_SSState_State_enum = 0U;
  Rte_Ap_GenPosTraj_PosTrajHwAngle_HwDeg_f32 = 0.0F;
  Rte_Ap_HOWDetect_HOWEstimate_Uls_f32 = 0.0F;
  Rte_Ap_HOWDetect_HOWState_Cnt_s08 = 0;
  Rte_Ap_HwPwrUpSeq_MtrDrvr0InitStart_Cnt_lgc = FALSE;
  Rte_Ap_HwPwrUpSeq_MtrDrvr1InitStart_Cnt_lgc = FALSE;
  Rte_Ap_HwPwrUpSeq_OverVltgMonStart_Cnt_lgc = FALSE;
  Rte_Ap_HwPwrUpSeq_PwrDiscATestStart_Cnt_lgc = FALSE;
  Rte_Ap_HwPwrUpSeq_PwrDiscBTestStart_Cnt_lgc = FALSE;
  Rte_Ap_HwPwrUpSeq_TMFTestStart_Cnt_lgc = FALSE;
  Rte_Ap_LmtCod_EOTGainLtd_Uls_f32 = 1.0F;
  Rte_Ap_LmtCod_EOTLimitLtd_MtrNm_f32 = 8.8F;
  Rte_Ap_LmtCod_OutputRampMultLtd_Uls_f32 = 0.0F;
  Rte_Ap_LmtCod_StallLimitLtd_MtrNm_f32 = 8.8F;
  Rte_Ap_LmtCod_ThermalLimitLtd_MtrNm_f32 = 8.8F;
  Rte_Ap_LmtCod_VehSpdLimitLtd_MtrNm_f32 = 8.8F;
  Rte_Ap_LoaMgr_HwTqLoaMtgtnEn_Cnt_lgc = FALSE;
  Rte_Ap_LoaMgr_IvtrLoaMtgtnEn_Cnt_lgc = FALSE;
  Rte_Ap_LoaMgr_LOASt_State_enum = 0U;
  Rte_Ap_LoaMgr_LoaRateLimit_UlspS_f32 = 1.0F;
  Rte_Ap_LoaMgr_LoaScaleFctr_Uls_f32 = 1.0F;
  Rte_Ap_LoaMgr_MotAgLoaMtgtnEn_Cnt_lgc = FALSE;
  Rte_Ap_LoaMgr_MotCurrLoaMtgtnEn_Cnt_lgc = FALSE;
  Rte_Ap_LrnEOT_CCWFound_Cnt_lgc = FALSE;
  Rte_Ap_LrnEOT_CCWPosition_HwDeg_f32 = 0.0F;
  Rte_Ap_LrnEOT_CWFound_Cnt_lgc = FALSE;
  Rte_Ap_LrnEOT_CWPosition_HwDeg_f32 = 0.0F;
  Rte_Ap_MotAgCorrln_MtrPosCorrlnSts_Cnt_u16 = 7U;
  Rte_Ap_MotAgCorrln_MtrPosIdptSig_Cnt_u08 = 3U;
  Rte_Ap_MotPosnCmp_MotPosnCumvAlgndCrf_Deg_f32 = 0.0F;
  Rte_Ap_MotPosnCmp_MotPosnCumvAlgndMrf_Deg_f32 = 0.0F;
  Rte_Ap_MtrTempEst_AssistMechTempEst_DegC_f32 = 0.0F;
  Rte_Ap_MtrTempEst_CuTempEst_DegC_f32 = 0.0F;
  Rte_Ap_MtrTempEst_MagTempEst_DegC_f32 = 0.0F;
  Rte_Ap_MtrTempEst_SiTempEst_DegC_f32 = 0.0F;
  Rte_Ap_PosServo_PosSrvoCmd_MtrNm_f32 = 0.0F;
  Rte_Ap_PosServo_PosSrvoReturnSclFct_Uls_f32 = 1.0F;
  Rte_Ap_PosServo_PosSrvoSmoothEnable_Uls_f32 = 0.0F;
  Rte_Ap_PwrDscntDuInv_PwrDiscATestComplete_Cnt_lgc = FALSE;
  Rte_Ap_PwrDscntDuInv_PwrDiscBTestComplete_Cnt_lgc = FALSE;
  Rte_Ap_PwrLmtFuncCr_FltTrqLmt_Uls_f32 = 0.0F;
  Rte_Ap_PwrLmtFuncCr_MRFMtrTrqCmd_MtrNm_f32 = 0.0F;
  Rte_Ap_PwrLmtFuncCr_ThresholdExceeded_Cnt_lgc = FALSE;
  Rte_Ap_SignlCondn_EstimdLatAcce_MpSecSq_f32 = 0.0F;
  Rte_Ap_SignlCondn_EstimdLatAcceValid_Cnt_lgc = FALSE;
  Rte_Ap_SignlCondn_VehicleLatAcceValid_Cnt_lgc = FALSE;
  Rte_Ap_SignlCondn_VehicleLatAccel_MpSecSq_f32 = 0.0F;
  Rte_Ap_SignlCondn_VehicleLonAccel_KphpS_f32 = 0.0F;
  Rte_Ap_SignlCondn_VehicleLonAccelValid_Cnt_lgc = FALSE;
  Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32 = 0.0F;
  Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc = FALSE;
  Rte_Ap_SignlCondn_VehicleYawRate_DegpS_f32 = 0.0F;
  Rte_Ap_SignlCondn_VehicleYawRateValid_Cnt_lgc = FALSE;
  Rte_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32 = 0.0F;
  Rte_Ap_SnsrOffsCorrn_HwTqCorrd_HwNm_f32 = 0.0F;
  Rte_Ap_SnsrOffsCorrn_YawRateCorrd_DegpS_f32 = 0.0F;
  Rte_Ap_SnsrOffsLrng_HwAgOffs_HwDeg_f32 = 0.0F;
  Rte_Ap_SnsrOffsLrng_HwTqOffs_HwNm_f32 = 0.0F;
  Rte_Ap_SnsrOffsLrng_VehYawRateOffs_DegpS_f32 = 0.0F;
  Rte_Ap_StabilityComp2_SysAssistCmd_MtrNm_f32 = 0.0F;
  Rte_Ap_Sweep_OutputHwTrq_HwNm_f32 = 0.0F;
  Rte_Ap_Sweep2_OutputMtrTrq_MtrNm_f32 = 0.0F;
  Rte_Ap_TSMit_TSMitCommand_MtrNm_f32 = 0.0F;
  Rte_Ap_TSMit_TSMitLearningEnabled_Cnt_lgc = FALSE;
  Rte_Ap_ThrmlDutyCycle_DutyCycleLevel_Uls_f32 = 0.0F;
  Rte_Ap_ThrmlDutyCycle_ThermLimitPerc_Uls_f32 = 0.0F;
  Rte_Ap_ThrmlDutyCycle_ThermalLimit_MtrNm_f32 = 8.8F;
  Rte_Ap_TqRsDg_MtrCurrIdptSig_Cnt_u08 = 2U;
  Rte_Ap_TranlDampg_CRFMtrTrqCmd_MtrNm_f32 = 0.0F;
  Rte_Ap_TranlDampg_CntrlDampComp_Cnt_lgc = FALSE;
  Rte_Ap_TranlDampg_MRFMtrTrqCmd_MtrNm_f32 = 0.0F;
  Rte_Ap_TranlDampg_SysC_CRFMtrTrqCmd_MtrNm_f32 = 0.0F;
  Rte_Ap_TranlDampg_SysC_MRFMtrTrqCmd_MtrNm_f32 = 0.0F;
  Rte_Ap_TrqArblim_AssistDDFactor_Uls_f32 = 1.0F;
  Rte_Ap_TrqArblim_DampingDDFactor_Uls_f32 = 1.0F;
  Rte_Ap_TrqArblim_ESCIsLimited_Cnt_lgc = FALSE;
  Rte_Ap_TrqArblim_ESCTorqueDelivered_HwNm_f32 = 0.0F;
  Rte_Ap_TrqArblim_IqTrqOv_HwNm_f32 = 0.0F;
  Rte_Ap_TrqArblim_LKATorqueDelivered_HwNm_f32 = 0.0F;
  Rte_Ap_TrqArblim_OpTrqOv_MtrNm_f32 = 0.0F;
  Rte_Ap_TrqArblim_PullCmpCustLrngDi_Cnt_lgc = FALSE;
  Rte_Ap_TrqArblim_ReturnDDFactor_Uls_f32 = 1.0F;
  Rte_Ap_TrqLOA_TrqLOAAvail_Cnt_lgc = FALSE;
  Rte_Ap_TrqLOA_TrqLOACmd_MtrNm_f32 = 0.0F;
  Rte_Ap_TrqOsc_TrqOscCmd_MtrNm_f32 = 0.0F;
  Rte_Ap_TrqOsc_TrqOscDCExceeded_Cnt_lgc = FALSE;
  Rte_Ap_TuningSelAuth_ActiveTunPers_Cnt_u16 = 0U;
  Rte_Ap_TuningSelAuth_ActiveTunSet_Cnt_u16 = 0U;
  Rte_Ap_VehSpdArbn_NonSecureVehSpd_Kph_f32 = 0.0F;
  Rte_Ap_VehSpdArbn_NonSecureVehSpdVld_Cnt_lgc = FALSE;
  Rte_Ap_WIRInputQual_QualWhlFreqL_Hz_f32 = 0.0F;
  Rte_Ap_WIRInputQual_QualWhlFreqR_Hz_f32 = 0.0F;
  Rte_Ap_WIRInputQual_WhlFreqQualified_Cnt_lgc = TRUE;
  Rte_Ap_WhlImbRej_WIRCmdAmpBlnd_MtrNm_f32 = 0.0F;
  Rte_Ap_WhlImbRej_WhlImbRejCmd_MtrNm_f32 = 0.0F;
  Rte_Assist_BaseAssistCmd_MtrNm_f32 = 0.0F;
  Rte_CDDInterface_ADCMtrCurrA_Volt_f32 = 0.0F;
  Rte_CDDInterface_ADCMtrCurrB_Volt_f32 = 0.0F;
  Rte_CDDInterface_ADCMtrCurrC_Volt_f32 = 0.0F;
  Rte_CDDInterface_BallNutTempEstSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_CorrMtrCurrA_Amp_f32 = 0.0F;
  Rte_CDDInterface_CorrMtrCurrB_Amp_f32 = 0.0F;
  Rte_CDDInterface_CorrMtrCurrC_Amp_f32 = 0.0F;
  Rte_CDDInterface_CorrMtrCurrPosition_Rev_f32 = 0.0F;
  Rte_CDDInterface_CorrectedElecMtrPosFloat_Rev_f32 = 0.0F;
  Rte_CDDInterface_DampingSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_DftAsstTbl_Cnt_lgc = FALSE;
  Rte_CDDInterface_DigMSBArbnMtrPosMecl_Rev_f32 = 0.0F;
  Rte_CDDInterface_DisableCEBusNormComm_Cnt_lgc = FALSE;
  Rte_CDDInterface_DisableHSBusNormComm_Cnt_lgc = FALSE;
  Rte_CDDInterface_DrivingDynSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_DwnldAsstGain_Uls_f32 = 0.0F;
  Rte_CDDInterface_EOTImpactSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_EOTThermalSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_EngONSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_ExpectedOnTimeA_Cnt_u32 = 0U;
  Rte_CDDInterface_ExpectedOnTimeB_Cnt_u32 = 0U;
  Rte_CDDInterface_ExpectedOnTimeC_Cnt_u32 = 0U;
  Rte_CDDInterface_FeatureControl_Cnt_lgc = TRUE;
  Rte_CDDInterface_FreqDepDmpSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_FricLrnSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_HysAddSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_HystCompSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_IgnCnt_Cnt_u16 = 0U;
  Rte_CDDInterface_KinIntDiagSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_LRPRPhaseadvanceCaptured_Cnt_s16 = 0;
  Rte_CDDInterface_LimitSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_MEC_Cnt_enum = 0U;
  Rte_CDDInterface_MfgDiagInhibit_Cnt_lgc = FALSE;
  Rte_CDDInterface_ModIdxFinal_Uls_f32 = 0.0F;
  Rte_CDDInterface_ModIdxSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_MotMeclPosn1MeasdTi_USec_u32 = 0U;
  Rte_CDDInterface_MotMeclPosn1ParityFaultAccum_Cnt_u16 = 0U;
  Rte_CDDInterface_MotMeclPosn1RawErrReg_Cnt_u16 = 0U;
  Rte_CDDInterface_MotMeclPosn1RevM_Rev_u0p16 = 0U;
  Rte_CDDInterface_MotMeclPosn1RollgCntr_Cnt_u08 = 0U;
  Rte_CDDInterface_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16 = 0U;
  Rte_CDDInterface_MotMeclPosn2MeasdTi_USec_u32 = 0U;
  Rte_CDDInterface_MotMeclPosn2ParityFaultAccum_Cnt_u16 = 0U;
  Rte_CDDInterface_MotMeclPosn2RawErrReg_Cnt_u16 = 0U;
  Rte_CDDInterface_MotMeclPosn2RevM_Rev_u0p16 = 0U;
  Rte_CDDInterface_MotMeclPosn2RollgCntr_Cnt_u08 = 0U;
  Rte_CDDInterface_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16 = 0U;
  Rte_CDDInterface_MotPosnCmpMotPosnCumvAlgnd_Rev_f32 = 0.0F;
  Rte_CDDInterface_MotPosnCmpMotPosnElec_Rev_u0p16 = 0U;
  Rte_CDDInterface_MotorVariant_Cnt_u16 = 0U;
  Rte_CDDInterface_MtrCtrlMtrDaxVoltage_Volt_f32 = 0.0F;
  Rte_CDDInterface_MtrCtrlMtrQaxVoltage_Volt_f32 = 0.0F;
  Rte_CDDInterface_MtrCurrDax_Amp_f32 = 0.0F;
  Rte_CDDInterface_MtrCurrQax_Amp_f32 = 0.0F;
  Rte_CDDInterface_MtrCurrQaxFinalRef_Amp_f32 = 0.0F;
  Rte_CDDInterface_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_MultIgnSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_NVMMotorVariant_Cnt_u08 = 7U;
  Rte_CDDInterface_NVMSensorData_Cnt_lgc = TRUE;
  Rte_CDDInterface_ParkAstSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_PosTrajEnable_Cnt_lgc = FALSE;
  Rte_CDDInterface_PullCompLrnSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_PullCompSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_ReturnSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_RxMsgsSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_SftEndStpSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_SrlComSvcDft_Cnt_b32 = 0U;
  Rte_CDDInterface_SysCBattSwitched1_Cnt_u16 = 0U;
  Rte_CDDInterface_SysCBattSwitched2_Cnt_u16 = 0U;
  Rte_CDDInterface_SysCT1ADC_Cnt_u16 = 0U;
  Rte_CDDInterface_SysCT2ADC_Cnt_u16 = 0U;
  Rte_CDDInterface_ThermalDCSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_TrqRmpSrlComSvcDft_Cnt_lgc = FALSE;
  Rte_CDDInterface_WIRMfgEnabled_Cnt_lgc = FALSE;
  Rte_Cd_Nhet1CfgAndUse_HwTq3Qlfr_State_enum = 0U;
  Rte_Cd_Nhet1CfgAndUse_HwTq3RollgCntr_Cnt_u08 = 0U;
  Rte_Cd_Nhet1CfgAndUse_HwTq3Val_HwNm_f32 = 0.0F;
  Rte_Cd_Nhet1CfgAndUse_HwTq4Qlfr_State_enum = 0U;
  Rte_Cd_Nhet1CfgAndUse_HwTq4RollgCntr_Cnt_u08 = 0U;
  Rte_Cd_Nhet1CfgAndUse_HwTq4Val_HwNm_f32 = 0.0F;
  Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeA_Cnt_u32 = 0U;
  Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeB_Cnt_u32 = 0U;
  Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeC_Cnt_u32 = 0U;
  Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeD_Cnt_u32 = 0U;
  Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeE_Cnt_u32 = 0U;
  Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeF_Cnt_u32 = 0U;
  Rte_ComplErr_ComplErr_HwDeg_f32 = 0.0F;
  Rte_CtrlTemp_FiltMeasTemp_DegC_f32 = 0.0F;
  Rte_CtrldVelRtn_ReturnCmd_MtrNm_f32 = 0.0F;
  Rte_CurrCmd_MtrCurrAngle_Rev_f32 = 0.0F;
  Rte_CurrCmd_MtrCurrDaxRef_Amp_f32 = 0.0F;
  Rte_CurrCmd_MtrCurrQaxRef_Amp_f32 = 0.0F;
  Rte_CurrCmd_MtrVoltDaxFFStatic_Volt_f32 = 0.0F;
  Rte_CurrCmd_MtrVoltQaxFFStatic_Volt_f32 = 0.0F;
  Rte_CurrParamComp_EstKe_VpRadpS_f32 = 0.0F;
  Rte_CurrParamComp_EstLd_Henry_f32 = 0.0F;
  Rte_CurrParamComp_EstLq_Henry_f32 = 0.0F;
  Rte_CurrParamComp_EstR_Ohm_f32 = 0.0F;
  Rte_CustPerSrvcs_ThermalLimitFlagCntr_Cnt_u08 = 0U;
  Rte_Damping_DampingCmd_MtrNm_f32 = 0.0F;
  Rte_DiagMgr_DiagNoofActiveInverter_Cnt_u08 = 2U;
  Rte_DiagMgr_DiagRampRate_XpmS_f32 = 0.0F;
  Rte_DiagMgr_DiagRampValue_Uls_f32 = 0.0F;
  Rte_DiagMgr_DiagRmpToZeroActive_Cnt_lgc = FALSE;
  Rte_DiagMgr_DiagStsCtrldDisRmpPres_Cnt_lgc = FALSE;
  Rte_DiagMgr_DiagStsDefTemp_Cnt_lgc = FALSE;
  Rte_DiagMgr_DiagStsDefVehSpd_Cnt_lgc = FALSE;
  Rte_DiagMgr_DiagStsHWASbSystmFltPres_Cnt_lgc = FALSE;
  Rte_DiagMgr_DiagStsInverter1Inactive_Cnt_lgc = FALSE;
  Rte_DiagMgr_DiagStsInverter2Inactive_Cnt_lgc = FALSE;
  Rte_DiagMgr_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc = FALSE;
  Rte_DiagMgr_DiagStsRecRmpToZeroFltPres_Cnt_lgc = FALSE;
  Rte_DiagMgr_DiagStsScomHWANotValid_Cnt_lgc = FALSE;
  Rte_DiagMgr_DiagStsWIRDisable_Cnt_lgc = FALSE;
  Rte_DigColPs_I2CHwAbsPos_HwDeg_f32 = 0.0F;
  Rte_DigColPs_I2CHwAbsPosValid_Cnt_lgc = FALSE;
  Rte_DigColPs_TrimComp_Cnt_lgc = FALSE;
  Rte_EOTActuatorMng_AssistEOTDamping_MtrNm_f32 = 0.0F;
  Rte_EOTActuatorMng_AssistEOTGain_Uls_f32 = 1.0F;
  Rte_EOTActuatorMng_AssistEOTLimit_MtrNm_f32 = 8.8F;
  Rte_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_MtrNm_f32 = 0.0F;
  Rte_HiLoadStall_AssistStallLimit_MtrNm_f32 = 8.8F;
  Rte_HighFreqAssist_HighFreqAssist_MtrNm_f32 = 0.0F;
  Rte_HystComp_HysteresisComp_MtrNm_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_Batt_Volt_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_BattSwitched1_Volt_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_BattSwitched2_Volt_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_MtrPos3Con_Volt_u3p13 = 0U;
  Rte_IoHwAbstractionUsr_MtrPos3Sin_Volt_u3p13 = 0U;
  Rte_IoHwAbstractionUsr_SysCBattSwitched1_Volt_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_SysCBattSwitched2_Volt_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_SysCT1_Volt_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_SysCT2_Volt_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_T1ADC_Volt_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_T2ADC_Volt_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_TemperatureADC_Volt_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_Vref3p3_Volt_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_Vref5vp1_Volt_f32 = 0.0F;
  Rte_IoHwAbstractionUsr_Vref5vp2_Volt_f32 = 0.0F;
  Rte_PeakCurrEst_EstPkCurr_AmpSq_f32 = 0.0F;
  Rte_PeakCurrEst_FiltEstPkCurr_AmpSq_f32 = 0.0F;
  Rte_QuadDet_InstMtrDir_Cnt_s08 = 0;
  Rte_QuadDet_MtrQuad_Cnt_u08 = 1U;
  Rte_ReturnFirewall_LimitedReturn_MtrNm_f32 = 0.0F;
  Rte_Sa_AnaHwTrq_HwTq1Qlfr_State_enum = 0U;
  Rte_Sa_AnaHwTrq_HwTq1RollgCntr_Cnt_u08 = 0U;
  Rte_Sa_AnaHwTrq_HwTq1Val_HwNm_f32 = 0.0F;
  Rte_Sa_AnaHwTrq_HwTq2Qlfr_State_enum = 0U;
  Rte_Sa_AnaHwTrq_HwTq2RollgCntr_Cnt_u08 = 0U;
  Rte_Sa_AnaHwTrq_HwTq2Val_HwNm_f32 = 0.0F;
  Rte_Sa_CmMtrCurr3Phs_ComOffset_Cnt_u16 = 0U;
  Rte_Sa_CmMtrCurr3Phs_CurrentGainSvc_Cnt_lgc = FALSE;
  Rte_Sa_CmMtrCurr3Phs_MtrCurrATempOffset_Volt_f32 = 0.0F;
  Rte_Sa_CmMtrCurr3Phs_MtrCurrBTempOffset_Volt_f32 = 0.0F;
  Rte_Sa_CmMtrCurr3Phs_MtrCurrCTempOffset_Volt_f32 = 0.0F;
  Rte_Sa_CmMtrCurr3Phs_MtrCurrIdptSig_Cnt_u08 = 2U;
  Rte_Sa_HwTqCorrln_HwTqCorrlnSts_Cnt_u16 = 15U;
  Rte_Sa_HwTqCorrln_HwTqIdptSig_Cnt_u08 = 4U;
  Rte_Sa_HwTqCorrln_HwTqVldSrcSig_Cnt_u08 = 0U;
  Rte_Sa_HwTrqArbn_ArbnAbsHwTqErr_HwNm_f32 = 0.0F;
  Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32 = 0.0F;
  Rte_Sa_MotMeclPosn1_MotPosnQlfr_State_enum = 0U;
  Rte_Sa_MotMeclPosn2_MotPosnQlfr_State_enum = 0U;
  Rte_Sa_MtrDrvDiag_GateDrive1ResetActive_Cnt_lgc = FALSE;
  Rte_Sa_MtrDrvDiag_GateDrive2ResetActive_Cnt_lgc = FALSE;
  Rte_Sa_MtrDrvDiag_MtrDrvr1InitComplete_Cnt_lgc = FALSE;
  Rte_Sa_MtrDrvDiag_MtrDrvr2InitComplete_Cnt_lgc = FALSE;
  Rte_Sa_MtrPos3SinCos_MtrPos3Mech_Rev_u0p16 = 0U;
  Rte_Sa_MtrPos3SinCos_MtrPos3Qlfr_State_enum = 0U;
  Rte_Sa_MtrPos3SinCos_MtrPos3RollgCntr_Cnt_u08 = 0U;
  Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32 = 0.0F;
  Rte_Sa_MtrVel_HwVelValid_Cnt_lgc = FALSE;
  Rte_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32 = 0.0F;
  Rte_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32 = 0.0F;
  Rte_Sa_MtrVel_SysCHandwheelVel_HwRadpS_f32 = 0.0F;
  Rte_Sa_MtrVel_SysCMotorVelMRF_MtrRadpS_f32 = 0.0F;
  Rte_Sa_MtrVel2_SysCDiagHwVel_HwRadpS_f32 = 0.0F;
  Rte_Sa_MtrVel2_SysCDiagMtrVelMRF_MtrRadpS_f32 = 0.0F;
  Rte_Sa_TmplMonrDualIvtr_TMFTestComplete_Cnt_lgc = FALSE;
  Rte_SrlComInput_APAMfgEnable_Cnt_lgc = FALSE;
  Rte_SrlComInput_APANonRecoverableFaults_Cnt_lgc = FALSE;
  Rte_SrlComInput_APARecoverableFaults_Cnt_lgc = FALSE;
  Rte_SrlComInput_APARequest_Cnt_lgc = FALSE;
  Rte_SrlComInput_DesiredTunPers_Cnt_u16 = 0U;
  Rte_SrlComInput_ESCCmd_HwNm_f32 = 0.0F;
  Rte_SrlComInput_ESCFault_Cnt_lgc = FALSE;
  Rte_SrlComInput_ESCMfgEnable_Cnt_lgc = FALSE;
  Rte_SrlComInput_ESCRequest_Cnt_lgc = FALSE;
  Rte_SrlComInput_EngRunAtvForCTCInhibit_Cnt_lgc = FALSE;
  Rte_SrlComInput_HapticRequest_Cnt_lgc = FALSE;
  Rte_SrlComInput_LKACmd_HwNm_f32 = 0.0F;
  Rte_SrlComInput_LKAFault_Cnt_lgc = FALSE;
  Rte_SrlComInput_LKAInhibit_Cnt_lgc = FALSE;
  Rte_SrlComInput_LKAMfgEnable_Cnt_lgc = FALSE;
  Rte_SrlComInput_LKARequest_Cnt_lgc = FALSE;
  Rte_SrlComInput_MaxSecureVehicleSpeed_Kph_f32 = 0.0F;
  Rte_SrlComInput_MinSecureVehicleSpeed_Kph_f32 = 0.0F;
  Rte_SrlComInput_PowertrainCrankActive_Cnt_lgc = FALSE;
  Rte_SrlComInput_SPMForCTCInhibit_Cnt_lgc = FALSE;
  Rte_SrlComInput_SWARTrgtAngRequest_HwDeg_f32 = 0.0F;
  Rte_SrlComInput_ShiftLeverIsInReverse_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComABSActive_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComAmbTemp_DegC_f32 = 0.0F;
  Rte_SrlComInput_SrlComESCActive_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComEngOn_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComEngTemp_DegC_f32 = 0.0F;
  Rte_SrlComInput_SrlComEngineSpeed_Rpm_f32 = 0.0F;
  Rte_SrlComInput_SrlComLWhlSpd_Hz_f32 = 0.0F;
  Rte_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComLatAccel_MpSecSq_f32 = 0.0F;
  Rte_SrlComInput_SrlComLatAccelValid_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComRWhlSpd_Hz_f32 = 0.0F;
  Rte_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComSPMOn_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComSysPwrMd_Cnt_enum = 0U;
  Rte_SrlComInput_SrlComTCSActive_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComTSMitDefeat_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComTransmissionTrq_TransNm_f32 = 0.0F;
  Rte_SrlComInput_SrlComVehLonAccelValid_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComVehSpd_Kph_f32 = 0.0F;
  Rte_SrlComInput_SrlComVehicleLonAccel_MpSecSq_f32 = 0.0F;
  Rte_SrlComInput_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32 = 0.0F;
  Rte_SrlComInput_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32 = 0.0F;
  Rte_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32 = 0.0F;
  Rte_SrlComInput_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32 = 0.0F;
  Rte_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc = FALSE;
  Rte_SrlComInput_SrlComYawRate_DegpS_f32 = 0.0F;
  Rte_SrlComInput_SrlComYawRateValid_Cnt_lgc = FALSE;
  Rte_SrlComInput_StrtStopFaultActive_Cnt_lgc = FALSE;
  Rte_SrlComInput_VehicleSpeedValid_Cnt_lgc = FALSE;
  Rte_SrlComOutput_BusOffCE_Cnt_lgc = FALSE;
  Rte_SrlComOutput_BusOffHS_Cnt_lgc = FALSE;
  Rte_StOpCtrl_OutputRampMult_Uls_f32 = 0.0F;
  Rte_StOpCtrl_SysStReqDi_Cnt_lgc = FALSE;
  Rte_StaMd_InitiatePwrDnFastWrite_Cnt_lgc = FALSE;
  Rte_StaMd_InitiatePwrDnNormalWrite_Cnt_lgc = FALSE;
  Rte_StaMd_PwrDnFastWriteComplete_Cnt_lgc = FALSE;
  Rte_StabilityComp_AssistCmd_MtrNm_f32 = 0.0F;
  Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32 = 0.0F;
  Rte_TrqOvlSta_APADrvrInterventionDetected_Cnt_lgc = FALSE;
  Rte_TrqOvlSta_APAState_State_enum = 0U;
  Rte_TrqOvlSta_ESCState_State_enum = 0U;
  Rte_TrqOvlSta_GMOSHOscillateState_State_enum = 1U;
  Rte_TrqOvlSta_LKAState_State_enum = 0U;
  Rte_TrqOvlSta_LkaDrvrIntvDetd_Cnt_lgc = FALSE;
  Rte_TrqOvlSta_PosServEnable_Cnt_lgc = FALSE;
  Rte_TrqOvlSta_PosSrvoHwAngle_HwDeg_f32 = 0.0F;
  Rte_TrqOvlSta_TrqOscAmp_MtrNm_f32 = 0.0F;
  Rte_TrqOvlSta_TrqOscEnable_Cnt_lgc = FALSE;
  Rte_TrqOvlSta_TrqOscFreq_Hz_f32 = 0.0F;
  Rte_VehDyn_SensorlessAuthority_Uls_f32 = 0.0F;
  Rte_VehDyn_SensorlessHwPos_HwDeg_f32 = 0.0F;
  Rte_VehPwrMd_ATermActive_Cnt_lgc = TRUE;
  Rte_VehPwrMd_CTermActive_Cnt_lgc = FALSE;
  Rte_VehPwrMd_DftVehSpdEna_Cnt_lgc = FALSE;
  Rte_VehPwrMd_OperRampRate_XpmS_f32 = 0.0F;
  Rte_VehPwrMd_OperRampValue_Uls_f32 = 0.0F;
  Rte_VehPwrMd_SysOperMotTqCmdSca_Uls_f32 = 1.0F;
  Rte_VehSpdLmt_AstVehSpdLimit_MtrNm_f32 = 8.8F;
  Rte_Xcp_ActiveTunOvrPtrAddr_Cnt_u32 = 0U;
  Rte_Xcp_TuningSessionActPtr_Cnt_u8 = 255U;
  Rte_AbsHwPos_TurnsCntrValidity_Cnt_u08 = 0U;
  Rte_Ap_ActivePull_PullCmpLongTermIntgtrStOffs_HwNm_f32 = 0.0F;
  Rte_Ap_ActivePull_PullCmpShoTermIntgtrStOffs_HwNm_f32 = 0.0F;
  Rte_Ap_AstLmt_EotActvCmd_MtrNm_f32 = 0.0F;
  Rte_Ap_AstLmt_LrnPnCtrEnable_Cnt_lgc = FALSE;
  Rte_Ap_AstLmt_LrnPnCtrTCmd_MtrNm_f32 = 0.0F;
  Rte_Ap_DigPhsReasDiag_PDActivateTest_Cnt_lgc = FALSE;
  Rte_Ap_LoaMgr_SteerMod_Cnt_enum = 0U;
  Rte_Ap_LoaMgr_TloaDi_Cnt_lgc = FALSE;
  Rte_Ap_MtrTempEst_ScomAMDefeat_Cnt_lgc = FALSE;
  Rte_Ap_MtrTempEst_ScomTempDataRcvd_Cnt_lgc = FALSE;
  Rte_Ap_PwrLmtFuncCr_AltFaultActive_Cnt_lgc = FALSE;
  Rte_Ap_ThrmlDutyCycle_IgnTimeOff_Cnt_u32 = 0U;
  Rte_Ap_ThrmlDutyCycle_VehTimeValid_Cnt_lgc = FALSE;
  Rte_Ap_TqRsDg_DervLambdaAlphaDiag_Volt_f32 = 0.0F;
  Rte_Ap_TqRsDg_DervLambdaBetaDiag_Volt_f32 = 0.0F;
  Rte_Ap_TrqLOA_TrqLoaDi_Cnt_lgc = FALSE;
  Rte_Ap_TrqLOA_VehWhlBas_mm_f32 = 3000.0F;
  Rte_Ap_TrqLOA_VehWhlBasVld_Cnt_lgc = FALSE;
  Rte_Assist_HwTrqHysAdd_HwNm_f32 = 0.0F;
  Rte_CDDInterface_AssistAssemblyPolarity_Cnt_s08 = 0;
  Rte_CDDInterface_MtrPosPolarity_Cnt_s08 = 0;
  Rte_CDDInterface_MtrTrqCmdSign_Cnt_s16 = 0;
  Rte_CtrldVelRtn_ReturnOffset_HwDeg_f32 = 0.0F;
  Rte_CurrCmd_DualEcuMotCtrlMtgnEna_Cnt_lgc = FALSE;
  Rte_CurrParamComp_DualEcuFltMtgtnEna_Cnt_lgc = FALSE;
  Rte_CurrParamComp_IvtrLoaMtgtnEn_Cnt_lgc = FALSE;
  Rte_Damping_CustomDamp_MtrNm_f32 = 0.0F;
  Rte_PeakCurrEst_DualEcuMotCtrlMtgnEna_Cnt_lgc = FALSE;
  Rte_Xcp_DesiredTunSet_Cnt_u16 = 0U;

  /* initialize inter-runnable variables */
  Rte_Irv_NexteerLibs_Time_mS_u32 = 0U;

  /* mode management initialization part 1 */
  /* reset Trigger Disable Flags */
  Rte_Ap_10_TriggerDisableFlagsInit();
  Rte_Ap_9_TriggerDisableFlagsInit();


  Rte_ModeMachine_Ap_StaMd8_SystemState8_Mode = RTE_TRANSITION_StaMd_Mode;

  Rte_ModeInfo_Ap_StaMd8_SystemState8_Mode.Rte_ModeQueue[0] = RTE_MODE_StaMd_Mode_WARMINIT;

  Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode = RTE_TRANSITION_StaMd_Mode;

  Rte_ModeInfo_Ap_StaMd9_SystemState9_Mode.Rte_ModeQueue[0] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_ModeInfo_Ap_StaMd9_SystemState9_Mode.Rte_ModeQueue[1] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3++;
  Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1++;
  Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1++;
  Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1++;

  Rte_ModeMachine_StaMd_SystemState_Mode = RTE_TRANSITION_StaMd_Mode;

  Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[0] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[1] = RTE_MODE_StaMd_Mode_WARMINIT;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_100ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per2++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per2++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1++;
  Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2++;

}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Exclusive area access
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Mode switch handling functions
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Ap_StaMd8_SystemState8_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  Std_ReturnType ret = RTE_E_OK;
  Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Start(nextMode);

  Rte_Assert(((nextMode < RTE_TRANSITION_StaMd_Mode) && ( nextMode >= 0)), RTE_E_INTERNAL_ModeArgument);

  SuspendOSInterrupts();
  if (Rte_ModeMachine_Ap_StaMd8_SystemState8_Mode == RTE_TRANSITION_StaMd_Mode)
  {
    ret = RTE_E_LIMIT;
    ResumeOSInterrupts();
  }
  else
  {
    EventMaskType ModeSwitchEventMask;
    Rte_ModeType_StaMd_Mode currentMode = Rte_ModeMachine_Ap_StaMd8_SystemState8_Mode;

    ModeSwitchEventMask = Rte_ModeExitEventMask_Ap_StaMd8_SystemState8_Mode[currentMode] | Rte_ModeEntryEventMask_Ap_StaMd8_SystemState8_Mode[nextMode];

    if (ModeSwitchEventMask != (EventMaskType)0)
    {
      Rte_ModeInfo_Ap_StaMd8_SystemState8_Mode.Rte_ModeQueue[0] = nextMode;

      Rte_ModeMachine_Ap_StaMd8_SystemState8_Mode = RTE_TRANSITION_StaMd_Mode;
      ResumeOSInterrupts();

      Rte_Task_SetEvent(Task_Trans_8, ModeSwitchEventMask);
      (void)SetEvent(Task_Trans_8, ModeSwitchEventMask);
    }
    else
    {
      Rte_ModeMachine_Ap_StaMd8_SystemState8_Mode = nextMode;
      ResumeOSInterrupts();
    }
  }

  Rte_SwitchHook_Ap_StaMd8_SystemState8_Mode_Return(nextMode);
  return ret;
}


/**********************************************************************************************************************
 * Mode switch handling functions
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_Ap_StaMd9_SystemState9_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  if (nextMode == RTE_MODE_StaMd_Mode_DISABLE)
  {
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3 < Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1 < Rte_TriggerDisableMaxCount_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3 < Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_DiagMgr9_DiagMgr_Per2 < Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_Ap_DiagMgr9_DiagMgr_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_DiagMgr9_DiagMgr_Per2++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per1 < Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1 < Rte_TriggerDisableMaxCount_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per2 < Rte_TriggerDisableMaxCount_Task_10ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per2++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per2++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_WARMINIT)
  {
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3 < Rte_TriggerDisableMaxCount_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1 < Rte_TriggerDisableMaxCount_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1++;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1++;
  }
}

STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_Ap_StaMd9_SystemState9_Mode(Rte_ModeType_StaMd_Mode previousMode)
{
  if (previousMode == RTE_MODE_StaMd_Mode_DISABLE)
  {
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_DiagMgr9_DiagMgr_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_DiagMgr9_DiagMgr_Per2--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per2--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per2--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_WARMINIT)
  {
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1--;
    Rte_Assert(Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1--;
  }
}



/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Ap_StaMd9_SystemState9_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  Std_ReturnType ret = RTE_E_OK;
  Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Start(nextMode);

  Rte_Assert(((nextMode < RTE_TRANSITION_StaMd_Mode) && ( nextMode >= 0)), RTE_E_INTERNAL_ModeArgument);

  SuspendOSInterrupts();
  if (Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode == RTE_TRANSITION_StaMd_Mode)
  {
    ret = RTE_E_LIMIT;
    ResumeOSInterrupts();
  }
  else
  {
    EventMaskType ModeSwitchEventMask;
    Rte_ModeType_StaMd_Mode currentMode = Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode;

    ModeSwitchEventMask = Rte_ModeExitEventMask_Ap_StaMd9_SystemState9_Mode[currentMode] | Rte_ModeEntryEventMask_Ap_StaMd9_SystemState9_Mode[nextMode];

    if ((ModeSwitchEventMask == (EventMaskType)0) && (currentMode != nextMode))
    {
      if (nextMode == RTE_MODE_StaMd_Mode_DISABLE)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trans_9;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_OFF)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trans_9;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_WARMINIT)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trans_9;
      }
    }

    if (ModeSwitchEventMask != (EventMaskType)0)
    {
      Rte_ModeInfo_Ap_StaMd9_SystemState9_Mode.Rte_ModeQueue[0] = nextMode;
      Rte_ModeInfo_Ap_StaMd9_SystemState9_Mode.Rte_ModeQueue[1] = currentMode;

      Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode = RTE_TRANSITION_StaMd_Mode;
      if (currentMode != nextMode)
      {
        Rte_IncDisableFlags_Ap_StaMd9_SystemState9_Mode(nextMode);
      }
      ResumeOSInterrupts();

      Rte_Task_SetEvent(Task_Trans_9, ModeSwitchEventMask);
      (void)SetEvent(Task_Trans_9, ModeSwitchEventMask);
    }
    else
    {
      Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode = nextMode;
      ResumeOSInterrupts();
    }
  }

  Rte_SwitchHook_Ap_StaMd9_SystemState9_Mode_Return(nextMode);
  return ret;
}


/**********************************************************************************************************************
 * Mode switch handling functions
 *********************************************************************************************************************/
STATIC FUNC(void, RTE_CODE) Rte_IncDisableFlags_StaMd_SystemState_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  if (nextMode == RTE_MODE_StaMd_Mode_DISABLE)
  {
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2 < Rte_TriggerDisableMaxCount_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1 < Rte_TriggerDisableMaxCount_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2 < Rte_TriggerDisableMaxCount_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2 < Rte_TriggerDisableMaxCount_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1 < Rte_TriggerDisableMaxCount_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3 < Rte_TriggerDisableMaxCount_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2 < Rte_TriggerDisableMaxCount_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_OPERATE)
  {
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per3 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per3++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2++;
  }
  else if (nextMode == RTE_MODE_StaMd_Mode_WARMINIT)
  {
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_100ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per2 < Rte_TriggerDisableMaxCount_Task_100ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_100ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per2++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2 < Rte_TriggerDisableMaxCount_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3 < Rte_TriggerDisableMaxCount_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per2 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per2++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1 < Rte_TriggerDisableMaxCount_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1++;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2 < Rte_TriggerDisableMaxCount_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2++;
  }
}

STATIC FUNC(void, RTE_CODE) Rte_DecDisableFlags_StaMd_SystemState_Mode(Rte_ModeType_StaMd_Mode previousMode)
{
  if (previousMode == RTE_MODE_StaMd_Mode_DISABLE)
  {
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_OFF)
  {
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_OPERATE)
  {
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per3--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2--;
  }
  else if (previousMode == RTE_MODE_StaMd_Mode_WARMINIT)
  {
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_100ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_100ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per2--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per2--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1--;
    Rte_Assert(Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2 > 0, RTE_E_INTERNAL_TriggerDisableCounter);
    Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2--;
  }
}



/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Ap_StaMd_SystemState_Mode(Rte_ModeType_StaMd_Mode nextMode)
{
  Std_ReturnType ret = RTE_E_OK;
  Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Start(nextMode);

  Rte_Assert(((nextMode < RTE_TRANSITION_StaMd_Mode) && ( nextMode >= 0)), RTE_E_INTERNAL_ModeArgument);

  SuspendOSInterrupts();
  if (Rte_ModeMachine_StaMd_SystemState_Mode == RTE_TRANSITION_StaMd_Mode)
  {
    ret = RTE_E_LIMIT;
    ResumeOSInterrupts();
  }
  else
  {
    EventMaskType ModeSwitchEventMask;
    Rte_ModeType_StaMd_Mode currentMode = Rte_ModeMachine_StaMd_SystemState_Mode;

    ModeSwitchEventMask = Rte_ModeExitEventMask_StaMd_SystemState_Mode[currentMode] | Rte_ModeEntryEventMask_StaMd_SystemState_Mode[nextMode];

    if ((ModeSwitchEventMask == (EventMaskType)0) && (currentMode != nextMode))
    {
      if (nextMode == RTE_MODE_StaMd_Mode_DISABLE)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trans_10;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_OFF)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trans_10;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_OPERATE)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trans_10;
      }
      else if (nextMode == RTE_MODE_StaMd_Mode_WARMINIT)
      {
        ModeSwitchEventMask |= Rte_Ev_MS_Task_Trans_10;
      }
    }

    if (ModeSwitchEventMask != (EventMaskType)0)
    {
      Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[0] = nextMode;
      Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[1] = currentMode;

      Rte_ModeMachine_StaMd_SystemState_Mode = RTE_TRANSITION_StaMd_Mode;
      if (currentMode != nextMode)
      {
        Rte_IncDisableFlags_StaMd_SystemState_Mode(nextMode);
      }
      ResumeOSInterrupts();

      Rte_Task_SetEvent(Task_Trans_10, ModeSwitchEventMask);
      (void)SetEvent(Task_Trans_10, ModeSwitchEventMask);
    }
    else
    {
      Rte_ModeMachine_StaMd_SystemState_Mode = nextMode;
      ResumeOSInterrupts();
    }
  }

  Rte_SwitchHook_Ap_StaMd_SystemState_Mode_Return(nextMode);
  return ret;
}


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     Task_100ms_10
 * Priority: 32
 * Schedule: FULL
 * Alarm:    Cycle Time 0.1 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_100ms_10)
{
  Rte_Task_Dispatch(Task_100ms_10);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_100msStart_Per_Start();
  ChkPtAp10_100msStart_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_100msStart_Per_Return();

  /* read implicit data */
  *(&Rte_Task_100ms_10.Rte_TB.Rte_I_CDDInterface_MEC_Cnt_enum.value) = Rte_CDDInterface_MEC_Cnt_enum;

  /* call runnable */
  Rte_Runnable_Sa_AnaHwTrq_AnaHwTrq_Per3_Start();
  AnaHwTrq_Per3();
  Rte_Runnable_Sa_AnaHwTrq_AnaHwTrq_Per3_Return();

  /* call runnable */
  Rte_Runnable_Sa_AnaHwTrq_AnaHwTrq_Per4_Start();
  AnaHwTrq_Per4();
  Rte_Runnable_Sa_AnaHwTrq_AnaHwTrq_Per4_Return();

  /* call runnable */
  Rte_Runnable_Sa_HwTqCorrln_HwTqCorrln_Per3_Start();
  HwTqCorrln_Per3();
  Rte_Runnable_Sa_HwTqCorrln_HwTqCorrln_Per3_Return();

  /* call runnable */
  Rte_Runnable_Sa_HwTrqArbn_HwTrqArbn_Per2_Start();
  HwTrqArbn_Per2();
  Rte_Runnable_Sa_HwTrqArbn_HwTrqArbn_Per2_Return();

  /* call runnable */
  Rte_Runnable_Sa_MotMeclPosn1_MotMeclPosn1_Per3_Start();
  MotMeclPosn1_Per3();
  Rte_Runnable_Sa_MotMeclPosn1_MotMeclPosn1_Per3_Return();

  /* read implicit data */
  *(&Rte_Task_100ms_10.Rte_RB.Rte_Ap_GmPwrpkSrvDataRcvry_GmPwrpkSrvDataRcvry_Per1.Rte_GetNVMSensorData_Cnt_lgc.value) = Rte_CDDInterface_NVMSensorData_Cnt_lgc;
  *(&Rte_Task_100ms_10.Rte_RB.Rte_Ap_GmPwrpkSrvDataRcvry_GmPwrpkSrvDataRcvry_Per1.Rte_NVMMotorVariant_Cnt_u08.value) = Rte_CDDInterface_NVMMotorVariant_Cnt_u08;

  /* call runnable */
  Rte_Runnable_Ap_GmPwrpkSrvDataRcvry_GmPwrpkSrvDataRcvry_Per1_Start();
  GmPwrpkSrvDataRcvry_Per1();
  Rte_Runnable_Ap_GmPwrpkSrvDataRcvry_GmPwrpkSrvDataRcvry_Per1_Return();

  /* call runnable */
  Rte_Runnable_Sa_MotMeclPosn2_MotMeclPosn2_Per3_Start();
  MotMeclPosn2_Per3();
  Rte_Runnable_Sa_MotMeclPosn2_MotMeclPosn2_Per3_Return();

  /* read implicit data */
  *(&Rte_Task_100ms_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Per2.Rte_CuTempEst_DegC_f32.value) = Rte_Ap_MtrTempEst_CuTempEst_DegC_f32;
  *(&Rte_Task_100ms_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Per2.Rte_MagTempEst_DegC_f32.value) = Rte_Ap_MtrTempEst_MagTempEst_DegC_f32;
  *(&Rte_Task_100ms_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Per2.Rte_SiTempEst_DegC_f32.value) = Rte_Ap_MtrTempEst_SiTempEst_DegC_f32;

  /* call runnable */
  Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Start();
  CurrParamComp_Per2();
  Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per2_Return();

  /* read implicit data */
  *(&Rte_Task_100ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1.Rte_FiltCntrlTemp_DegC_f32.value) = Rte_CtrlTemp_FiltMeasTemp_DegC_f32;

  /* call runnable */
  Rte_Runnable_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1_Start();
  CmMtrCurr3Phs_Per1();
  Rte_Runnable_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1_Return();

  /* write implicit data */
  Rte_Sa_CmMtrCurr3Phs_MtrCurrATempOffset_Volt_f32 = *(&Rte_Task_100ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1.Rte_MtrCurrATempOffset_Volt_f32.value);
  Rte_Sa_CmMtrCurr3Phs_MtrCurrBTempOffset_Volt_f32 = *(&Rte_Task_100ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1.Rte_MtrCurrBTempOffset_Volt_f32.value);
  Rte_Sa_CmMtrCurr3Phs_MtrCurrCTempOffset_Volt_f32 = *(&Rte_Task_100ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1.Rte_MtrCurrCTempOffset_Volt_f32.value);

  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_100ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per2 == 0)
  {
    /* call runnable */
    Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Start();
    PeakCurrEst_Per2();
    Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per2_Return();

    /* write implicit data */
    Rte_PeakCurrEst_FiltEstPkCurr_AmpSq_f32 = *(&Rte_Task_100ms_10.Rte_RB.Rte_Ap_PeakCurrEst_PeakCurrEst_Per2.Rte_FiltEstPkCurr_AmpSq_f32.value);
  }

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Start();
  uDiagStaticRegs_Per();
  Rte_Runnable_Cd_uDiag_uDiagStaticRegs_Per_Return();

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Start();
  DiagMgr10_Per();
  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Per_Return();

  /* call runnable */
  Rte_Runnable_NtWrap_NtWrap_Per1_Start();
  NtWrap_Per1();
  Rte_Runnable_NtWrap_NtWrap_Per1_Return();

  /* call runnable */
  Rte_Runnable_Sa_DigColPs_DigColPs_Per3_Start();
  DigColPs_Per3();
  Rte_Runnable_Sa_DigColPs_DigColPs_Per3_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_100msEnd_Per_Start();
  ChkPtAp10_100msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_100msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_100ms_8
 * Priority: 31
 * Schedule: FULL
 * Alarm:    Cycle Time 0.1 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_100ms_8)
{
  Rte_Task_Dispatch(Task_100ms_8);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_100msStart_Per_Start();
  ChkPtAp8_100msStart_Per();
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_100msStart_Per_Return();

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Start();
  DiagMgr8_Per();
  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Per_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_100msEnd_Per_Start();
  ChkPtAp8_100msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_100msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_100ms_9
 * Priority: 30
 * Schedule: FULL
 * Alarm:    Cycle Time 0.1 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_100ms_9)
{
  Rte_Task_Dispatch(Task_100ms_9);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_100msStart_Per_Start();
  ChkPtAp9_100msStart_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_100msStart_Per_Return();

  /* read implicit data */
  *(&Rte_Task_100ms_9.Rte_TB.Rte_I_SrlComInput_SrlComAmbTemp_DegC_f32.value) = Rte_SrlComInput_SrlComAmbTemp_DegC_f32;

  /* call runnable */
  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Start();
  CtrlTemp_Per2();
  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per2_Return();

  /* call runnable */
  Rte_Runnable_Ap_CustPerSrvcs_CustPerSrvcs_Per1_Start();
  CustPerSrvcs_Per1();
  Rte_Runnable_Ap_CustPerSrvcs_CustPerSrvcs_Per1_Return();

  /* write implicit data */
  Rte_CustPerSrvcs_ThermalLimitFlagCntr_Cnt_u08 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_CustPerSrvcs_CustPerSrvcs_Per1.Rte_ThermalLimitFlagCntr_Cnt_u08.value);

  /* read implicit data */
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_CtrlTempFinal_DegC_f32.value) = Rte_CtrlTemp_FiltMeasTemp_DegC_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_EngTemp_DegC_f32.value) = Rte_SrlComInput_SrlComEngTemp_DegC_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_EstPkCurr_AmpSq_f32.value) = Rte_PeakCurrEst_EstPkCurr_AmpSq_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_HwVel_HwRadpS_f32.value) = Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_ScomAMDefeat_Cnt_lgc.value) = Rte_Ap_MtrTempEst_ScomAMDefeat_Cnt_lgc;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_ScomTempDataRcvd_Cnt_lgc.value) = Rte_Ap_MtrTempEst_ScomTempDataRcvd_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Start();
  MtrTempEst_Per1();
  Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Per1_Return();

  /* write implicit data */
  Rte_Ap_MtrTempEst_AssistMechTempEst_DegC_f32 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_AssistMechTempEst_DegC_f32.value);
  Rte_Ap_MtrTempEst_CuTempEst_DegC_f32 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_CuTempEst_DegC_f32.value);
  Rte_Ap_MtrTempEst_MagTempEst_DegC_f32 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_MagTempEst_DegC_f32.value);
  Rte_Ap_MtrTempEst_SiTempEst_DegC_f32 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Per1.Rte_SiTempEst_DegC_f32.value);

  DisableAllInterrupts();
  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per3 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_HwTorque_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
    *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_PullCmpEna_Cnt_lgc.value) = Rte_CDDInterface_FeatureControl_Cnt_lgc;
    *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_PullCmpLongTermIntgtrStOffs_HwNm_f32.value) = Rte_Ap_ActivePull_PullCmpLongTermIntgtrStOffs_HwNm_f32;
    *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

    /* call runnable */
    Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Start();
    ActivePull_Per3();
    Rte_Runnable_Ap_ActivePull_ActivePull_Per3_Return();

    /* write implicit data */
    Rte_Ap_ActivePull_PullCmpLongTermIntgtrSt_HwNm_f32 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per3.Rte_PullCmpLongTermIntgtrSt_HwNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* call runnable */
  Rte_Runnable_Ap_SrlComInput_SrlComInput_Per3_Start();
  SrlComInput_Per3();
  Rte_Runnable_Ap_SrlComInput_SrlComInput_Per3_Return();

  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per1 == 0)
  {
    /* call runnable */
    Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Start();
    SrlComOutput_Per1();
    Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per1_Return();
  }

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Start();
  DiagMgr9_Per();
  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Per_Return();

  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_100ms_9_Rte_Trigger1_Ap_DiagMgr9_DiagMgr_Per2 == 0)
  {
    /* call runnable */
    Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Start();
    DiagMgr_Per2();
    Rte_Runnable_Ap_DiagMgr9_DiagMgr_Per2_Return();
  }

  /* read implicit data */
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_CuTempEst_DegC_f32.value) = Rte_Ap_MtrTempEst_CuTempEst_DegC_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_DefeatDutySvc_Cnt_lgc.value) = Rte_CDDInterface_ThermalDCSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_FiltMeasTemp_DegC_f32.value) = Rte_CtrlTemp_FiltMeasTemp_DegC_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_FilteredPkCurr_AmpSq_f32.value) = Rte_PeakCurrEst_FiltEstPkCurr_AmpSq_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_IgnTimeOff_Cnt_u32.value) = Rte_Ap_ThrmlDutyCycle_IgnTimeOff_Cnt_u32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_MagTempEst_DegC_f32.value) = Rte_Ap_MtrTempEst_MagTempEst_DegC_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_MotorVelCRF_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_MtrPkCurr_AmpSq_f32.value) = Rte_PeakCurrEst_EstPkCurr_AmpSq_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_SiTempEst_DegC_f32.value) = Rte_Ap_MtrTempEst_SiTempEst_DegC_f32;
  *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_VehTimeValid_Cnt_lgc.value) = Rte_Ap_ThrmlDutyCycle_VehTimeValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Start();
  ThrmlDutyCycle_Per1();
  Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1_Return();

  /* write implicit data */
  Rte_Ap_ThrmlDutyCycle_DutyCycleLevel_Uls_f32 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_DutyCycleLevel_Uls_f32.value);
  Rte_Ap_ThrmlDutyCycle_ThermLimitPerc_Uls_f32 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_ThermLimitPerc_Uls_f32.value);
  Rte_Ap_ThrmlDutyCycle_ThermalLimit_MtrNm_f32 = *(&Rte_Task_100ms_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Per1.Rte_ThermalLimit_MtrNm_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_100msEnd_Per_Start();
  ChkPtAp9_100msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_100msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_10ms_10
 * Priority: 42
 * Schedule: FULL
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_10ms_10)
{
  Rte_Task_Dispatch(Task_10ms_10);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_10msStart_Per_Start();
  ChkPtAp10_10msStart_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_10msStart_Per_Return();

  /* read implicit data */
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_ActiveTunOvrPtrAddr_Cnt_u32.value) = Rte_Xcp_ActiveTunOvrPtrAddr_Cnt_u32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_DesiredTunPers_Cnt_u16.value) = Rte_SrlComInput_DesiredTunPers_Cnt_u16;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_DesiredTunSet_Cnt_u16.value) = Rte_CDDInterface_MotorVariant_Cnt_u16;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_TuningSessionActPtr_Cnt_u8.value) = Rte_Xcp_TuningSessionActPtr_Cnt_u8;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Start();
  TuningSelAuth_Per1();
  Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Per1_Return();

  /* write implicit data */
  Rte_Ap_TuningSelAuth_ActiveTunPers_Cnt_u16 = *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_ActiveTunPers_Cnt_u16.value);
  Rte_Ap_TuningSelAuth_ActiveTunSet_Cnt_u16 = *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Per1.Rte_ActiveTunSet_Cnt_u16.value);

  /* read implicit data */
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrElecMechPolarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_MotElecMeclPolarity_Cnt_s08;

  /* call runnable */
  Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Start();
  CDDInterface_Per4();
  Rte_Runnable_Sa_CDDInterface_CDDInterface_Per4_Return();

  /* write implicit data */
  Rte_CDDInterface_BallNutTempEstSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_BallNutTempEstSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_DampingSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DampingSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_DftAsstTbl_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DftAsstTbl_Cnt_lgc.value);
  Rte_CDDInterface_DisableCEBusNormComm_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DisableCEBusNormComm_Cnt_lgc.value);
  Rte_CDDInterface_DisableHSBusNormComm_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DisableHSBusNormComm_Cnt_lgc.value);
  Rte_CDDInterface_DrivingDynSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DrivingDynSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_DwnldAsstGain_Uls_f32 = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DwnldAsstGain_Uls_f32.value);
  Rte_CDDInterface_EOTImpactSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EOTImpactSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_EOTThermalSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EOTThermalSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_EngONSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EngONSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_FeatureControl_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FeatureControl_Cnt_lgc.value);
  Rte_CDDInterface_FreqDepDmpSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_FricLrnSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FricLrnSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_HysAddSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_HysAddSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_HystCompSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_HystCompSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_KinIntDiagSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_KinIntDiagSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_LimitSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_LimitSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_MEC_Cnt_enum = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MEC_Cnt_enum.value);
  Rte_CDDInterface_MfgDiagInhibit_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MfgDiagInhibit_Cnt_lgc.value);
  Rte_CDDInterface_ModIdxSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ModIdxSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_MultIgnSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MultIgnSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_ParkAstSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ParkAstSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_PosTrajEnable_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_PosTrajEnable_Cnt_lgc.value);
  Rte_CDDInterface_PullCompLrnSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_PullCompLrnSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_PullCompSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_PullCompSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_ReturnSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ReturnSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_RxMsgsSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_RxMsgsSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_SftEndStpSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_SftEndStpSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_SrlComSvcDft_Cnt_b32 = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_SrlComSvcDft_Cnt_b32.value);
  Rte_CDDInterface_ThermalDCSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ThermalDCSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_TrqRmpSrlComSvcDft_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_TrqRmpSrlComSvcDft_Cnt_lgc.value);
  Rte_CDDInterface_WIRMfgEnabled_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_WIRMfgEnabled_Cnt_lgc.value);

  /* call runnable */
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Per4_Start();
  AbsHwPos_Per4();
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Per4_Return();

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2.Rte_CntDisMtrTrqCmdMRF_MtrNm_f32.value) = Rte_Ap_TranlDampg_MRFMtrTrqCmd_MtrNm_f32;
    *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2.Rte_Vecu_Volt_f32.value) = Rte_Ap_BattVltg_BrdgVltg_Volt_f32;

    /* call runnable */
    Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Start();
    PwrLmtFuncCr_Per2();
    Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2_Return();

    /* write implicit data */
    Rte_Ap_PwrLmtFuncCr_FltTrqLmt_Uls_f32 = *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2.Rte_FltTrqLmt_Uls_f32.value);
    Rte_Ap_PwrLmtFuncCr_ThresholdExceeded_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per2.Rte_ThresholdExceeded_Cnt_lgc.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_HandwheelAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_HandwheelPosition_HwDeg_f32.value) = Rte_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_HandwheelVelocity_HwRadpS_f32.value) = Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_PreLimitMtrTrqCmd_MtrNm_f32.value) = Rte_Ap_AstLmt_PreLimitTorque_MtrNm_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_SrlComABSActive_Cnt_lgc.value) = Rte_SrlComInput_SrlComABSActive_Cnt_lgc;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_SrlComESCActive_Cnt_lgc.value) = Rte_SrlComInput_SrlComESCActive_Cnt_lgc;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_SrlComTCSActive_Cnt_lgc.value) = Rte_SrlComInput_SrlComTCSActive_Cnt_lgc;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_SrlComTransmissionTrq_TransNm_f32.value) = Rte_SrlComInput_SrlComTransmissionTrq_TransNm_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_SrlComYawRate_DegpS_f32.value) = Rte_Ap_SnsrOffsCorrn_YawRateCorrd_DegpS_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_TSMitDefeat_Cnt_lgc.value) = Rte_SrlComInput_SrlComTSMitDefeat_Cnt_lgc;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_TSMit_TSMit_Per1_Start();
  TSMit_Per1();
  Rte_Runnable_Ap_TSMit_TSMit_Per1_Return();

  /* write implicit data */
  Rte_Ap_TSMit_TSMitCommand_MtrNm_f32 = *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_TSMitCommand_MtrNm_f32.value);
  Rte_Ap_TSMit_TSMitLearningEnabled_Cnt_lgc = *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_TSMitLearningEnabled_Cnt_lgc.value);

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagECC_Per_Start();
  uDiagECC_Per();
  Rte_Runnable_Cd_uDiag_uDiagECC_Per_Return();

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Start();
  uDiagVIM_Per();
  Rte_Runnable_Cd_uDiag_uDiagVIM_Per_Return();

  /* call runnable */
  Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Start();
  ShtdnMech_Per1();
  Rte_Runnable_Sa_ShtdnMech_ShtdnMech_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_ElePwr_ElePwr_Per1.Rte_IvtrLoaMtgtnEn_Cnt_lgc.value) = Rte_Ap_LoaMgr_IvtrLoaMtgtnEn_Cnt_lgc;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_ElePwr_ElePwr_Per1.Rte_MotCurrLoaMtgtnEn_Cnt_lgc.value) = Rte_Ap_LoaMgr_MotCurrLoaMtgtnEn_Cnt_lgc;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_ElePwr_ElePwr_Per1.Rte_MtrCurrDax_Amp_f32.value) = Rte_CDDInterface_MtrCurrDax_Amp_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_ElePwr_ElePwr_Per1.Rte_MtrCurrDaxRef_Amp_f32.value) = Rte_CurrCmd_MtrCurrDaxRef_Amp_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_ElePwr_ElePwr_Per1.Rte_MtrCurrQax_Amp_f32.value) = Rte_CDDInterface_MtrCurrQax_Amp_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_ElePwr_ElePwr_Per1.Rte_MtrCurrQaxFinalRef_Amp_f32.value) = Rte_CDDInterface_MtrCurrQaxFinalRef_Amp_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_ElePwr_ElePwr_Per1.Rte_MtrVoltDax_Volt_f32.value) = Rte_CDDInterface_MtrCtrlMtrDaxVoltage_Volt_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_ElePwr_ElePwr_Per1.Rte_MtrVoltQax_Volt_f32.value) = Rte_CDDInterface_MtrCtrlMtrQaxVoltage_Volt_f32;
  *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_ElePwr_ElePwr_Per1.Rte_Vecu_Volt_f32.value) = Rte_Ap_BattVltg_BrdgVltg_Volt_f32;

  /* call runnable */
  Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Start();
  ElePwr_Per1();
  Rte_Runnable_Ap_ElePwr_ElePwr_Per1_Return();

  /* write implicit data */
  Rte_Ap_ElePwr_ElectricPower_Watt_f32 = *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_ElePwr_ElePwr_Per1.Rte_ElectricPower_Watt_f32.value);
  Rte_Ap_ElePwr_SupplyCurrent_Amp_f32 = *(&Rte_Task_10ms_10.Rte_RB.Rte_Ap_ElePwr_ElePwr_Per1.Rte_SupplyCurrent_Amp_f32.value);

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3 == 0)
  {
    EnableAllInterrupts();
    /* call runnable */
    Rte_Runnable_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3_Start();
    TmplMonrDualIvtr_Per3();
    Rte_Runnable_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per3_Return();
  }
  else
  {
    EnableAllInterrupts();
  }

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_10ms_10_Rte_Trigger1_Sa_OvrVoltMon_OvrVoltMon_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_10ms_10.Rte_RB.Rte_Sa_OvrVoltMon_OvrVoltMon_Per1.Rte_OverVltgMonStart_Cnt_lgc.value) = Rte_Ap_HwPwrUpSeq_OverVltgMonStart_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Start();
    OvrVoltMon_Per1();
    Rte_Runnable_Sa_OvrVoltMon_OvrVoltMon_Per1_Return();
  }
  else
  {
    EnableAllInterrupts();
  }

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_10msEnd_Per_Start();
  ChkPtAp10_10msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_10msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_10ms_9
 * Priority: 40
 * Schedule: FULL
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_10ms_9)
{
  Rte_Task_Dispatch(Task_10ms_9);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_10msStart_Per_Start();
  ChkPtAp9_10msStart_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_10msStart_Per_Return();

  /* call runnable */
  Rte_Runnable_Ap_SrlComInput_SrlComInput_Per2_Start();
  SrlComInput_Per2();
  Rte_Runnable_Ap_SrlComInput_SrlComInput_Per2_Return();

  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_SrlComOutput_SrlComOutput_Per2 == 0)
  {
    /* call runnable */
    Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per2_Start();
    SrlComOutput_Per2();
    Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Per2_Return();
  }

  /* read implicit data */
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_DemIf_DemIf_Per1.Rte_SrlComEngOn_Cnt_lgc.value) = Rte_SrlComInput_SrlComEngOn_Cnt_lgc;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_DemIf_DemIf_Per1.Rte_SrlComSysPwrMd_Cnt_enum.value) = Rte_SrlComInput_SrlComSysPwrMd_Cnt_enum;

  /* call runnable */
  Rte_Runnable_Ap_DemIf_DemIf_Per1_Start();
  DemIf_Per1();
  Rte_Runnable_Ap_DemIf_DemIf_Per1_Return();

  DisableAllInterrupts();
  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_10ms_9_Rte_Trigger1_Ap_AvgFricLrn_AvgFricLrn_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_CRFMtrTrq_MtrNm_f32.value) = Rte_Ap_TranlDampg_CRFMtrTrqCmd_MtrNm_f32;
    *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_DefeatFricLearning_Cnt_lgc.value) = Rte_CDDInterface_FricLrnSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_HwAng_HwDeg_f32.value) = Rte_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32;
    *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_HwPosAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
    *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_HwTrq_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
    *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_HwVel_HwRadpS_f32.value) = Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32;
    *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_LatAcc_MpSecSq_f32.value) = Rte_Ap_SignlCondn_VehicleLatAccel_MpSecSq_f32;
    *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_Temperature_DegC_f32.value) = Rte_Ap_MtrTempEst_AssistMechTempEst_DegC_f32;
    *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_VehSpd_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
    *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value) = Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Start();
    AvgFricLrn_Per1();
    Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Per1_Return();

    /* write implicit data */
    Rte_Ap_AvgFricLrn_EstFric_HwNm_f32 = *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_EstFric_HwNm_f32.value);
    Rte_Ap_AvgFricLrn_FricOffset_HwNm_f32 = *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_FricOffset_HwNm_f32.value);
    Rte_Ap_AvgFricLrn_SatEstFric_HwNm_f32 = *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Per1.Rte_SatEstFric_HwNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_DiagStsHwPosDis_Cnt_lgc.value) = Rte_DiagMgr_DiagStsHWASbSystmFltPres_Cnt_lgc;
  *(&Rte_Task_10ms_9.Rte_TB.Rte_I_AbsHwPos_HandwheelAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_HandwheelPosition_HwDeg_f32.value) = Rte_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_MtrVelCRF_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_PostLimitTorque_MtrNm_f32.value) = Rte_Ap_Sweep2_OutputMtrTrq_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Start();
  LrnEOT_Per1();
  Rte_Runnable_Ap_LrnEOT_LrnEOT_Per1_Return();

  /* write implicit data */
  Rte_Ap_LrnEOT_CCWFound_Cnt_lgc = *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_CCWFound_Cnt_lgc.value);
  Rte_Ap_LrnEOT_CCWPosition_HwDeg_f32 = *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_CCWPosition_HwDeg_f32.value);
  Rte_Ap_LrnEOT_CWFound_Cnt_lgc = *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_CWFound_Cnt_lgc.value);
  Rte_Ap_LrnEOT_CWPosition_HwDeg_f32 = *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Per1.Rte_CWPosition_HwDeg_f32.value);

  /* read implicit data */
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_ActiveTunPers_Cnt_u16.value) = Rte_Ap_TuningSelAuth_ActiveTunPers_Cnt_u16;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_ActiveTunSet_Cnt_u16.value) = Rte_Ap_TuningSelAuth_ActiveTunSet_Cnt_u16;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_DesiredTunPers_Cnt_u16.value) = Rte_SrlComInput_DesiredTunPers_Cnt_u16;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_DesiredTunSet_Cnt_u16.value) = Rte_Xcp_DesiredTunSet_Cnt_u16;

  /* call runnable */
  Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Start();
  ApXcp_Per1();
  Rte_Runnable_Ap_ApXcp_ApXcp_Per1_Return();

  /* write implicit data */
  Rte_Xcp_ActiveTunOvrPtrAddr_Cnt_u32 = *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_ActiveTunOvrPtrAddr_Cnt_u32.value);
  Rte_Xcp_TuningSessionActPtr_Cnt_u8 = *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_ApXcp_ApXcp_Per1.Rte_TuningSessionActPtr_Cnt_u8.value);

  /* read implicit data */
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_BVDiag_BVDiag_Per1.Rte_Batt_Volt_f32.value) = Rte_IoHwAbstractionUsr_Batt_Volt_f32;

  /* call runnable */
  Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Start();
  BVDiag_Per1();
  Rte_Runnable_Ap_BVDiag_BVDiag_Per1_Return();

  /* call runnable */
  Rte_Runnable_Ap_VehSpdArbn_VehSpdArbn_Per1_Start();
  VehSpdArbn_Per1();
  Rte_Runnable_Ap_VehSpdArbn_VehSpdArbn_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_HandwheelPosition_HwDeg_f32.value) = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_HandwheelVelocity_HwRadpS_f32.value) = Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_HwTorque_HwNm_f32.value) = Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_TorqueCmdCRF_MtrNm_f32.value) = Rte_Ap_TranlDampg_CRFMtrTrqCmd_MtrNm_f32;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_VehicleSpeedValid_Cnt_lgc.value) = Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_VehicleYawRate_DegpS_f32.value) = Rte_Ap_SignlCondn_VehicleYawRate_DegpS_f32;
  *(&Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_VehicleYawRateValid_Cnt_lgc.value) = Rte_Ap_SignlCondn_VehicleYawRateValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2_Start();
  SnsrOffsLrng_Per2();
  Rte_Runnable_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_10msEnd_Per_Start();
  ChkPtAp9_10msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_10msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_2msB_10
 * Priority: 81
 * Schedule: FULL
 * Alarm:    Cycle Time 0.002 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_2msB_10)
{
  Rte_Task_Dispatch(Task_2msB_10);

  /* call runnable */
  Rte_Runnable_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per1_Start();
  TmplMonrDualIvtr_Per1();
  Rte_Runnable_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per1_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_2ms_10
 * Priority: 62
 * Schedule: FULL
 * Alarm:    Cycle Time 0.002 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_2ms_10)
{
  Rte_Task_Dispatch(Task_2ms_10);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_2msStart_Per_Start();
  ChkPtAp10_2msStart_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_2msStart_Per_Return();

  /* call runnable */
  Rte_Runnable_NexteerLibs_SystemTime_Per1_Start();
  SystemTime_Per1();
  Rte_Runnable_NexteerLibs_SystemTime_Per1_Return();

  /* call runnable */
  Rte_Runnable_IoHwAbstractionUsr_IoHwAb_StartADC_Start();
  IoHwAb_StartADC();
  Rte_Runnable_IoHwAbstractionUsr_IoHwAb_StartADC_Return();

  /* call runnable */
  Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Start();
  CDDInterface_Per1();
  Rte_Runnable_Sa_CDDInterface_CDDInterface_Per1_Return();

  /* write implicit data */
  Rte_CDDInterface_ADCMtrCurrA_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurrA_Volt_f32.value);
  Rte_CDDInterface_ADCMtrCurrB_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurrB_Volt_f32.value);
  Rte_CDDInterface_ADCMtrCurrC_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurrC_Volt_f32.value);
  Rte_CDDInterface_CorrMtrCurrA_Amp_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrA_Amp_f32.value);
  Rte_CDDInterface_CorrMtrCurrB_Amp_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrB_Amp_f32.value);
  Rte_CDDInterface_CorrMtrCurrC_Amp_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrC_Amp_f32.value);
  Rte_CDDInterface_CorrMtrCurrPosition_Rev_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrPosition_Rev_f32.value);
  Rte_CDDInterface_CorrectedElecMtrPosFloat_Rev_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrectedElecMtrPosFloat_Rev_f32.value);
  Rte_CDDInterface_DigMSBArbnMtrPosMecl_Rev_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_DigMSBArbnMtrPosMecl_Rev_f32.value);
  Rte_CDDInterface_ExpectedOnTimeA_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeA_Cnt_u32.value);
  Rte_CDDInterface_ExpectedOnTimeB_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeB_Cnt_u32.value);
  Rte_CDDInterface_ExpectedOnTimeC_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeC_Cnt_u32.value);
  Rte_CDDInterface_LRPRPhaseadvanceCaptured_Cnt_s16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_LRPRPhaseadvanceCaptured_Cnt_s16.value);
  Rte_CDDInterface_ModIdxFinal_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ModIdxFinal_Uls_f32.value);
  Rte_CDDInterface_MotMeclPosn1MeasdTi_USec_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1MeasdTi_USec_u32.value);
  Rte_CDDInterface_MotMeclPosn1ParityFaultAccum_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1ParityFaultAccum_Cnt_u16.value);
  Rte_CDDInterface_MotMeclPosn1RawErrReg_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1RawErrReg_Cnt_u16.value);
  Rte_CDDInterface_MotMeclPosn1RevM_Rev_u0p16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1RevM_Rev_u0p16.value);
  Rte_CDDInterface_MotMeclPosn1RollgCntr_Cnt_u08 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1RollgCntr_Cnt_u08.value);
  Rte_CDDInterface_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16.value);
  Rte_CDDInterface_MotMeclPosn2MeasdTi_USec_u32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_CDDInterface_MotMeclPosn2MeasdTi_USec_u32.value);
  Rte_CDDInterface_MotMeclPosn2ParityFaultAccum_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn2ParityFaultAccum_Cnt_u16.value);
  Rte_CDDInterface_MotMeclPosn2RawErrReg_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn2RawErrReg_Cnt_u16.value);
  Rte_CDDInterface_MotMeclPosn2RevM_Rev_u0p16 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_CDDInterface_MotMeclPosn2RevM_Rev_u0p16.value);
  Rte_CDDInterface_MotMeclPosn2RollgCntr_Cnt_u08 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn2RollgCntr_Cnt_u08.value);
  Rte_CDDInterface_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16.value);
  Rte_CDDInterface_MotPosnCmpMotPosnCumvAlgnd_Rev_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotPosnCmpMotPosnCumvAlgnd_Rev_f32.value);
  Rte_CDDInterface_MotPosnCmpMotPosnElec_Rev_u0p16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotPosnCmpMotPosnElec_Rev_u0p16.value);
  Rte_CDDInterface_MtrCtrlMtrDaxVoltage_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCtrlMtrDaxVoltage_Volt_f32.value);
  Rte_CDDInterface_MtrCtrlMtrQaxVoltage_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCtrlMtrQaxVoltage_Volt_f32.value);
  Rte_CDDInterface_MtrCurrDax_Amp_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrDax_Amp_f32.value);
  Rte_CDDInterface_MtrCurrQax_Amp_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrQax_Amp_f32.value);
  Rte_CDDInterface_MtrCurrQaxFinalRef_Amp_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrQaxFinalRef_Amp_f32.value);
  Rte_CDDInterface_SysCBattSwitched1_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCBattSwitched1_Cnt_u16.value);
  Rte_CDDInterface_SysCBattSwitched2_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCBattSwitched2_Cnt_u16.value);
  Rte_CDDInterface_SysCT1ADC_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCT1ADC_Cnt_u16.value);
  Rte_CDDInterface_SysCT2ADC_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCT2ADC_Cnt_u16.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_AsstAssemblyPolarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08;

  /* call runnable */
  Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Start();
  MtrVel_Per1();
  Rte_Runnable_Sa_MtrVel_MtrVel_Per1_Return();

  /* write implicit data */
  Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_HandwheelVel_HwRadpS_f32.value);
  Rte_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_MotorVelCRF_MtrRadpS_f32.value);
  Rte_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_MotorVelMRF_MtrRadpS_f32.value);
  Rte_Sa_MtrVel_SysCHandwheelVel_HwRadpS_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_SysCHandwheelVel_HwRadpS_f32.value);
  Rte_Sa_MtrVel_SysCMotorVelMRF_MtrRadpS_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per1.Rte_SysCMotorVelMRF_MtrRadpS_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per2.Rte_SysCDiagHwVel_HwRadpS_f32.value) = Rte_Sa_MtrVel2_SysCDiagHwVel_HwRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per2.Rte_SysCDiagMtrVelMRF_MtrRadpS_f32.value) = Rte_Sa_MtrVel2_SysCDiagMtrVelMRF_MtrRadpS_f32;

  /* call runnable */
  Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Start();
  MtrVel_Per2();
  Rte_Runnable_Sa_MtrVel_MtrVel_Per2_Return();

  /* write implicit data */
  Rte_Sa_MtrVel_HwVelValid_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrVel_MtrVel_Per2.Rte_HwVelValid_Cnt_lgc.value);

  /* call runnable */
  Rte_Runnable_Sa_DigColPs_DigColPs_Per1_Start();
  DigColPs_Per1();
  Rte_Runnable_Sa_DigColPs_DigColPs_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WIRInputQual_WIRInputQual_Per1.Rte_SrlComLWhlSpd_Hz_f32.value) = Rte_SrlComInput_SrlComLWhlSpd_Hz_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WIRInputQual_WIRInputQual_Per1.Rte_SrlComLWhlSpdVld_Cnt_lgc.value) = Rte_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WIRInputQual_WIRInputQual_Per1.Rte_SrlComRWhlSpd_Hz_f32.value) = Rte_SrlComInput_SrlComRWhlSpd_Hz_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WIRInputQual_WIRInputQual_Per1.Rte_SrlComRWhlSpdVld_Cnt_lgc.value) = Rte_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Start();
  WIRInputQual_Per1();
  Rte_Runnable_Ap_WIRInputQual_WIRInputQual_Per1_Return();

  /* write implicit data */
  Rte_Ap_WIRInputQual_QualWhlFreqL_Hz_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WIRInputQual_WIRInputQual_Per1.Rte_QualWhlFreqL_Hz_f32.value);
  Rte_Ap_WIRInputQual_QualWhlFreqR_Hz_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WIRInputQual_WIRInputQual_Per1.Rte_QualWhlFreqR_Hz_f32.value);
  Rte_Ap_WIRInputQual_WhlFreqQualified_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WIRInputQual_WIRInputQual_Per1.Rte_WhlFreqQualified_Cnt_lgc.value);

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_DiagStsWIRDisable_Cnt_lgc.value) = Rte_DiagMgr_DiagStsWIRDisable_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_HwTrq_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_QualWhlFreqL_Hz_f32.value) = Rte_Ap_WIRInputQual_QualWhlFreqL_Hz_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_QualWhlFreqR_Hz_f32.value) = Rte_Ap_WIRInputQual_QualWhlFreqR_Hz_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_VehSpd_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_VehSpdValid_Cnt_lgc.value) = Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_WIRMfgEnable_Cnt_lgc.value) = Rte_CDDInterface_WIRMfgEnabled_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_WhlFreqQualified_Cnt_lgc.value) = Rte_Ap_WIRInputQual_WhlFreqQualified_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Start();
    WhlImbRej_Per1();
    Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per1_Return();

    /* write implicit data */
    Rte_Ap_WhlImbRej_WIRCmdAmpBlnd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_WIRCmdAmpBlnd_MtrNm_f32.value);
    Rte_Ap_WhlImbRej_WhlImbRejCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per1.Rte_WhlImbRejCmd_MtrNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per3 == 0)
  {
    /* call runnable */
    Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Start();
    WhlImbRej_Per3();
    Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per3_Return();

    /* write implicit data */
    Rte_Ap_WhlImbRej_WhlImbRejCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_WhlImbRej_WhlImbRej_Per3.Rte_WhlImbRejCmd_MtrNm_f32.value);
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehLatAccel_MpSecSq_f32.value) = Rte_SrlComInput_SrlComLatAccel_MpSecSq_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehLatAccelValid_Cnt_lgc.value) = Rte_SrlComInput_SrlComLatAccelValid_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehLonAccel_MpSecSq_f32.value) = Rte_SrlComInput_SrlComVehicleLonAccel_MpSecSq_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehLonAccelValid_Cnt_lgc.value) = Rte_SrlComInput_SrlComVehLonAccelValid_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehSpeed_Kph_f32.value) = Rte_Ap_VehSpdArbn_NonSecureVehSpd_Kph_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehSpeedValid_Cnt_lgc.value) = Rte_Ap_VehSpdArbn_NonSecureVehSpdVld_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehYawRate_DegpS_f32.value) = Rte_SrlComInput_SrlComYawRate_DegpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_SrlComVehYawRateValid_Cnt_lgc.value) = Rte_SrlComInput_SrlComYawRateValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Start();
  SignlCondn_Per1();
  Rte_Runnable_Ap_SignlCondn_SignlCondn_Per1_Return();

  /* write implicit data */
  Rte_Ap_SignlCondn_EstimdLatAcce_MpSecSq_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_EstimdLatAcce_MpSecSq_f32.value);
  Rte_Ap_SignlCondn_EstimdLatAcceValid_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_EstimdLatAcceValid_Cnt_lgc.value);
  Rte_Ap_SignlCondn_VehicleLatAcceValid_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_VehicleLatAcceValid_Cnt_lgc.value);
  Rte_Ap_SignlCondn_VehicleLatAccel_MpSecSq_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_VehicleLatAccel_MpSecSq_f32.value);
  Rte_Ap_SignlCondn_VehicleLonAccel_KphpS_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_VehicleLonAccel_KphpS_f32.value);
  Rte_Ap_SignlCondn_VehicleLonAccelValid_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_VehicleLonAccelValid_Cnt_lgc.value);
  Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_SignlCondn_VehicleSpeed_Kph_f32.value);
  Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc.value);
  Rte_Ap_SignlCondn_VehicleYawRate_DegpS_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_SignlCondn_VehicleYawRate_DegpS_f32.value);
  Rte_Ap_SignlCondn_VehicleYawRateValid_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SignlCondn_SignlCondn_Per1.Rte_VehicleYawRateValid_Cnt_lgc.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_SysCBattSwitched1ADC_Cnt_u16.value) = Rte_CDDInterface_SysCBattSwitched1_Cnt_u16;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_SysCBattSwitched2ADC_Cnt_u16.value) = Rte_CDDInterface_SysCBattSwitched2_Cnt_u16;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_SysCT1ADC_Cnt_u16.value) = Rte_CDDInterface_SysCT1ADC_Cnt_u16;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_SysCT2ADC_Cnt_u16.value) = Rte_CDDInterface_SysCT2ADC_Cnt_u16;

  /* call runnable */
  Rte_Runnable_IoHwAbstractionUsr_IoHwAb_ReadADC_Start();
  IoHwAb_ReadADC();
  Rte_Runnable_IoHwAbstractionUsr_IoHwAb_ReadADC_Return();

  /* write implicit data */
  Rte_IoHwAbstractionUsr_Batt_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_Batt_Volt_f32.value);
  Rte_IoHwAbstractionUsr_BattSwitched1_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_BattSwitched1_Volt_f32.value);
  Rte_IoHwAbstractionUsr_BattSwitched2_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_BattSwitched2_Volt_f32.value);
  Rte_IoHwAbstractionUsr_MtrPos3Con_Volt_u3p13 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_MtrPos3Con_Volt_u3p13.value);
  Rte_IoHwAbstractionUsr_MtrPos3Sin_Volt_u3p13 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_MtrPos3Sin_Volt_u3p13.value);
  Rte_IoHwAbstractionUsr_SysCBattSwitched1_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_SysCBattSwitched1_Volt_f32.value);
  Rte_IoHwAbstractionUsr_SysCBattSwitched2_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_SysCBattSwitched2_Volt_f32.value);
  Rte_IoHwAbstractionUsr_SysCT1_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_SysCT1_Volt_f32.value);
  Rte_IoHwAbstractionUsr_SysCT2_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_SysCT2_Volt_f32.value);
  Rte_IoHwAbstractionUsr_T1ADC_Volt_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_IoHwAbstractionUsr_T1ADC_Volt_f32.value);
  Rte_IoHwAbstractionUsr_T2ADC_Volt_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_IoHwAbstractionUsr_T2ADC_Volt_f32.value);
  Rte_IoHwAbstractionUsr_TemperatureADC_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_TemperatureADC_Volt_f32.value);
  Rte_IoHwAbstractionUsr_Vref3p3_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_Vref3p3_Volt_f32.value);
  Rte_IoHwAbstractionUsr_Vref5vp1_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_Vref5vp1_Volt_f32.value);
  Rte_IoHwAbstractionUsr_Vref5vp2_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_ReadADC.Rte_Vref5vp2_Volt_f32.value);

  /* call runnable */
  Rte_Runnable_Cd_Nhet1CfgAndUse_Nhet1CfgAndUse_Per1_Start();
  Nhet1CfgAndUse_Per1();
  Rte_Runnable_Cd_Nhet1CfgAndUse_Nhet1CfgAndUse_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaHwTrq_AnaHwTrq_Per1.Rte_HwTq1Polarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_HwTq1Polarity_Cnt_s08;

  /* call runnable */
  Rte_Runnable_Sa_AnaHwTrq_AnaHwTrq_Per1_Start();
  AnaHwTrq_Per1();
  Rte_Runnable_Sa_AnaHwTrq_AnaHwTrq_Per1_Return();

  /* write implicit data */
  Rte_Sa_AnaHwTrq_HwTq1Qlfr_State_enum = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_AnaHwTrq_HwTq1Qlfr_State_enum.value);
  Rte_Sa_AnaHwTrq_HwTq1RollgCntr_Cnt_u08 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_AnaHwTrq_HwTq1RollgCntr_Cnt_u08.value);
  Rte_Sa_AnaHwTrq_HwTq1Val_HwNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_AnaHwTrq_HwTq1Val_HwNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaHwTrq_AnaHwTrq_Per2.Rte_HwTq2Polarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_HwTq2Polarity_Cnt_s08;

  /* call runnable */
  Rte_Runnable_Sa_AnaHwTrq_AnaHwTrq_Per2_Start();
  AnaHwTrq_Per2();
  Rte_Runnable_Sa_AnaHwTrq_AnaHwTrq_Per2_Return();

  /* write implicit data */
  Rte_Sa_AnaHwTrq_HwTq2Qlfr_State_enum = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_AnaHwTrq_HwTq2Qlfr_State_enum.value);
  Rte_Sa_AnaHwTrq_HwTq2RollgCntr_Cnt_u08 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_AnaHwTrq_HwTq2RollgCntr_Cnt_u08.value);
  Rte_Sa_AnaHwTrq_HwTq2Val_HwNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_AnaHwTrq_HwTq2Val_HwNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Cd_Nhet1CfgAndUse_Nhet1CfgAndUse_Per2.Rte_HwTq3Polarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_HwTq3Polarity_Cnt_s08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Cd_Nhet1CfgAndUse_Nhet1CfgAndUse_Per2.Rte_HwTq4Polarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_HwTq4Polarity_Cnt_s08;

  /* call runnable */
  Rte_Runnable_Cd_Nhet1CfgAndUse_Nhet1CfgAndUse_Per2_Start();
  Nhet1CfgAndUse_Per2();
  Rte_Runnable_Cd_Nhet1CfgAndUse_Nhet1CfgAndUse_Per2_Return();

  /* write implicit data */
  Rte_Cd_Nhet1CfgAndUse_HwTq3Qlfr_State_enum = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Cd_Nhet1CfgAndUse_HwTq3Qlfr_State_enum.value);
  Rte_Cd_Nhet1CfgAndUse_HwTq3RollgCntr_Cnt_u08 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Cd_Nhet1CfgAndUse_HwTq3RollgCntr_Cnt_u08.value);
  Rte_Cd_Nhet1CfgAndUse_HwTq3Val_HwNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Cd_Nhet1CfgAndUse_HwTq3Val_HwNm_f32.value);
  Rte_Cd_Nhet1CfgAndUse_HwTq4Qlfr_State_enum = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Cd_Nhet1CfgAndUse_HwTq4Qlfr_State_enum.value);
  Rte_Cd_Nhet1CfgAndUse_HwTq4RollgCntr_Cnt_u08 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Cd_Nhet1CfgAndUse_HwTq4RollgCntr_Cnt_u08.value);
  Rte_Cd_Nhet1CfgAndUse_HwTq4Val_HwNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Cd_Nhet1CfgAndUse_HwTq4Val_HwNm_f32.value);

  /* call runnable */
  Rte_Runnable_Sa_HwTqCorrln_HwTqCorrln_Per1_Start();
  HwTqCorrln_Per1();
  Rte_Runnable_Sa_HwTqCorrln_HwTqCorrln_Per1_Return();

  /* write implicit data */
  Rte_Sa_HwTqCorrln_HwTqCorrlnSts_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_HwTqCorrln_HwTqCorrlnSts_Cnt_u16.value);

  /* call runnable */
  Rte_Runnable_Sa_HwTrqArbn_HwTrqArbn_Per1_Start();
  HwTrqArbn_Per1();
  Rte_Runnable_Sa_HwTrqArbn_HwTrqArbn_Per1_Return();

  /* write implicit data */
  Rte_Sa_HwTrqArbn_ArbnAbsHwTqErr_HwNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_HwTrqArbn_HwTrqArbn_Per1.Rte_ArbnAbsHwTqErr_HwNm_f32.value);
  Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_HwTrqArbn_HwTqVal_HwNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_AlignedCumMechMtrPosCRF_Deg_f32.value) = Rte_Ap_MotPosnCmp_MotPosnCumvAlgndCrf_Deg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_ComplError_HwDeg_f32.value) = Rte_ComplErr_ComplErr_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_CumMechMtrPosCRF_Deg_f32.value) = Rte_Ap_MotPosnCmp_MotPosnCumvAlgndCrf_Deg_f32;

  /* call runnable */
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Per1_Start();
  AbsHwPos_Per1();
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Per1_Return();

  /* write implicit data */
  Rte_AbsHwPos_RelHwPos_HwDeg_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per1.Rte_RelHwPos_HwDeg_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_DiagStatusHwPosReducedPerf_Cnt_lgc.value) = Rte_DiagMgr_DiagStsHWASbSystmFltPres_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_I2CHwAbsPos_HwDeg_f32.value) = Rte_DigColPs_I2CHwAbsPos_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_I2CHwAbsPosValid_Cnt_lgc.value) = Rte_DigColPs_I2CHwAbsPosValid_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_ManufMode_Cnt_enum.value) = Rte_CDDInterface_MEC_Cnt_enum;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_TurnsCntrValidity_Cnt_u08.value) = Rte_AbsHwPos_TurnsCntrValidity_Cnt_u08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_VdAuthority_Uls_f32.value) = Rte_VehDyn_SensorlessAuthority_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_VdHwPos_HwDeg_f32.value) = Rte_VehDyn_SensorlessHwPos_HwDeg_f32;

  /* call runnable */
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Per2_Start();
  AbsHwPos_Per2();
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Per2_Return();

  /* write implicit data */
  Rte_AbsHwPos_HandwheelAuthority_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_HandwheelAuthority_Uls_f32.value);
  Rte_AbsHwPos_HandwheelPosition_HwDeg_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_AbsHwPos_HandwheelPosition_HwDeg_f32.value);
  Rte_AbsHwPos_HwPosSource_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_HwPosSource_Cnt_u16.value);
  Rte_AbsHwPos_SrlComHwPos_HwDeg_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_SrlComHwPos_HwDeg_f32.value);
  Rte_AbsHwPos_SrlComHwPosStatus_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Per2.Rte_SrlComHwPosStatus_Cnt_u16.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1.Rte_HwAgOffs_HwDeg_f32.value) = Rte_Ap_SnsrOffsLrng_HwAgOffs_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1.Rte_HwTqOffs_HwNm_f32.value) = Rte_Ap_SnsrOffsLrng_HwTqOffs_HwNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1.Rte_YawRateOffs_DegpS_f32.value) = Rte_Ap_SnsrOffsLrng_VehYawRateOffs_DegpS_f32;

  /* call runnable */
  Rte_Runnable_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1_Start();
  SnsrOffsCorrn_Per1();
  Rte_Runnable_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1_Return();

  /* write implicit data */
  Rte_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1.Rte_HwAgCorrd_HwDeg_f32.value);
  Rte_Ap_SnsrOffsCorrn_HwTqCorrd_HwNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_SnsrOffsCorrn_HwTqCorrd_HwNm_f32.value);
  Rte_Ap_SnsrOffsCorrn_YawRateCorrd_DegpS_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1.Rte_YawRateCorrd_DegpS_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_Sweep_Sweep_Per1_Start();
  Sweep_Per1();
  Rte_Runnable_Ap_Sweep_Sweep_Per1_Return();

  /* write implicit data */
  Rte_Ap_Sweep_OutputHwTrq_HwNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_Sweep_OutputHwTrq_HwNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_Assist_Assist_Per1.Rte_AssistDDFactor_Uls_f32.value) = Rte_Ap_TrqArblim_AssistDDFactor_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_Assist_Assist_Per1.Rte_DftAsstTbl_Cnt_lgc.value) = Rte_CDDInterface_DftAsstTbl_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_Assist_Assist_Per1.Rte_DutyCycleLevel_Uls_f32.value) = Rte_Ap_ThrmlDutyCycle_DutyCycleLevel_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_Assist_Assist_Per1.Rte_DwnldAsstGain_Uls_f32.value) = Rte_CDDInterface_DwnldAsstGain_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_Assist_Assist_Per1.Rte_HwTrqHysAdd_HwNm_f32.value) = Rte_Assist_HwTrqHysAdd_HwNm_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_TrqArblim_IqTrqOv_HwNm_f32.value) = Rte_Ap_TrqArblim_IqTrqOv_HwNm_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_WhlImbRej_WIRCmdAmpBlnd_MtrNm_f32.value) = Rte_Ap_WhlImbRej_WIRCmdAmpBlnd_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_Assist_Assist_Per1_Start();
  Assist_Per1();
  Rte_Runnable_Ap_Assist_Assist_Per1_Return();

  /* write implicit data */
  Rte_Assist_BaseAssistCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Assist_BaseAssistCmd_MtrNm_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Start();
  HighFreqAssist_Per1();
  Rte_Runnable_Ap_HighFreqAssist_HighFreqAssist_Per1_Return();

  /* write implicit data */
  Rte_HighFreqAssist_HighFreqAssist_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HighFreqAssist_HighFreqAssist_Per1.Rte_HighFreqAssist_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HystComp_HystComp_Per1.Rte_AssistMechTempEst_DegC_f32.value) = Rte_Ap_MtrTempEst_AssistMechTempEst_DegC_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HystComp_HystComp_Per1.Rte_DefeatHystService_Cnt_lgc.value) = Rte_CDDInterface_HystCompSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HystComp_HystComp_Per1.Rte_FricOffset_HwNm_f32.value) = Rte_Ap_AvgFricLrn_FricOffset_HwNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_HystComp_HystComp_Per1_Start();
  HystComp_Per1();
  Rte_Runnable_Ap_HystComp_HystComp_Per1_Return();

  /* write implicit data */
  Rte_HystComp_HysteresisComp_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HystComp_HystComp_Per1.Rte_HysteresisComp_MtrNm_f32.value);

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_AssistFirewall_AssistFirewall_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_BaseAssistCmd_MtrNm_f32.value) = Rte_Assist_BaseAssistCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_Defeat_AsstTbl_Service_Cnt_lgc.value) = Rte_CDDInterface_DftAsstTbl_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_HighFreqAssist_MtrNm_f32.value) = Rte_HighFreqAssist_HighFreqAssist_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_HysteresisComp_MtrNm_f32.value) = Rte_HystComp_HysteresisComp_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_MEC_Counter_Cnt_enum.value) = Rte_CDDInterface_MEC_Cnt_enum;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

    /* call runnable */
    Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Start();
    AssistFirewall_Per1();
    Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Per1_Return();

    /* write implicit data */
    Rte_Ap_AssistFirewall_AsstFirewallActive_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_AsstFirewallActive_Uls_f32.value);
    Rte_Ap_AssistFirewall_CombinedAssist_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AssistFirewall_AssistFirewall_Per1.Rte_CombinedAssist_MtrNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StabilityComp_StabilityComp_Per1.Rte_AssistDDFactor_Uls_f32.value) = Rte_Ap_TrqArblim_AssistDDFactor_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StabilityComp_StabilityComp_Per1.Rte_AsstFWActive_Uls_f32.value) = Rte_Ap_AssistFirewall_AsstFirewallActive_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StabilityComp_StabilityComp_Per1.Rte_CombinedAssist_MtrNm_f32.value) = Rte_Ap_AssistFirewall_CombinedAssist_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_Sweep_OutputHwTrq_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StabilityComp_StabilityComp_Per1.Rte_SysAssistCmd_MtrNm_MtrNm_f32.value) = Rte_Ap_StabilityComp2_SysAssistCmd_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_SignlCondn_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Start();
  StabilityComp_Per1();
  Rte_Runnable_Ap_StabilityComp_StabilityComp_Per1_Return();

  /* write implicit data */
  Rte_StabilityComp_AssistCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_StabilityComp_AssistCmd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_CDDInterface_ReturnSrlComSvcDft_Cnt_lgc.value) = Rte_CDDInterface_ReturnSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_CtrldVelRtn_CtrldVelRtn_Per1.Rte_DiagStsHwPosDis_Cnt_lgc.value) = Rte_DiagMgr_DiagStsHWASbSystmFltPres_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_CtrldVelRtn_CtrldVelRtn_Per1.Rte_HandwheelAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32.value) = Rte_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_CtrldVelRtn_CtrldVelRtn_Per1.Rte_HandwheelVelocity_HwRadpS_f32.value) = Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_CtrldVelRtn_CtrldVelRtn_Per1.Rte_MRFMtrTrqCmdScl_MtrNm_f32.value) = Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_CtrldVelRtn_CtrldVelRtn_Per1.Rte_PAReturnSclFct_Uls_f32.value) = Rte_Ap_PosServo_PosSrvoReturnSclFct_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_CtrldVelRtn_CtrldVelRtn_Per1.Rte_ReturnDDFactor_Uls_f32.value) = Rte_Ap_TrqArblim_ReturnDDFactor_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_CtrldVelRtn_CtrldVelRtn_Per1.Rte_ReturnOffset_HwDeg_f32.value) = Rte_CtrldVelRtn_ReturnOffset_HwDeg_f32;

  /* call runnable */
  Rte_Runnable_CtrldVelRtn_CtrldVelRtn_Per1_Start();
  CtrldVelRtn_Per1();
  Rte_Runnable_CtrldVelRtn_CtrldVelRtn_Per1_Return();

  /* write implicit data */
  Rte_CtrldVelRtn_ReturnCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_CtrldVelRtn_ReturnCmd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ReturnFirewall_ReturnFirewall_Per1.Rte_MEC_Counter_Cnt_enum.value) = Rte_CDDInterface_MEC_Cnt_enum;

  /* call runnable */
  Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Start();
  ReturnFirewall_Per1();
  Rte_Runnable_Ap_ReturnFirewall_ReturnFirewall_Per1_Return();

  /* write implicit data */
  Rte_ReturnFirewall_LimitedReturn_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ReturnFirewall_ReturnFirewall_Per1.Rte_LimitedReturn_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_Damping_Damping_Per1.Rte_AssistMechTempEst_DegC_f32.value) = Rte_Ap_MtrTempEst_AssistMechTempEst_DegC_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_Damping_Damping_Per1.Rte_CustomDamp_MtrNm_f32.value) = Rte_Damping_CustomDamp_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_Damping_Damping_Per1.Rte_DampingDDFactor_Uls_f32.value) = Rte_Ap_TrqArblim_DampingDDFactor_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_Damping_Damping_Per1.Rte_DefeatDampingSvc_Cnt_lgc.value) = Rte_CDDInterface_DampingSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_Damping_Damping_Per1.Rte_MotorVelCRF_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32;

  /* call runnable */
  Rte_Runnable_Ap_Damping_Damping_Per1_Start();
  Damping_Per1();
  Rte_Runnable_Ap_Damping_Damping_Per1_Return();

  /* write implicit data */
  Rte_Damping_DampingCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_Damping_Damping_Per1.Rte_DampingCmd_MtrNm_f32.value);

  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1 == 0)
  {
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_BaseAssistCmd_MtrNm_f32.value) = Rte_Assist_BaseAssistCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_BrakePulsationEna_Cnt_lgc.value) = Rte_CDDInterface_FeatureControl_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_CRFMotorVel_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value) = Rte_CDDInterface_FreqDepDmpSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_VehicleLonAccel_KphpS_f32.value) = Rte_Ap_SignlCondn_VehicleLonAccel_KphpS_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_WIRCmdAmpBlnd_MtrNm_f32.value) = Rte_Ap_WhlImbRej_WIRCmdAmpBlnd_MtrNm_f32;

    /* call runnable */
    Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Start();
    FrqDepDmpnInrtCmp_Per1();
    Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1_Return();

    /* write implicit data */
    Rte_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Per1.Rte_FrqDepDmpnInrtCmp_MtrNm_f32.value);
  }

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DampingFirewall_DampingFirewall_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_AsstFirewallActive_Uls_f32.value) = Rte_Ap_AssistFirewall_AsstFirewallActive_Uls_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_BaseAssistCmd_MtrNm_f32.value) = Rte_Assist_BaseAssistCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_DampingCmd_MtrNm_f32.value) = Rte_Damping_DampingCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_Defeat_Damping_Svc_Cnt_lgc.value) = Rte_CDDInterface_DampingSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value) = Rte_CDDInterface_FreqDepDmpSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_InertiaComp_MtrNm_f32.value) = Rte_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_MEC_Counter_Cnt_enum.value) = Rte_CDDInterface_MEC_Cnt_enum;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_MtrVelCRF_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_VehicleLonAccel_KphpS_f32.value) = Rte_Ap_SignlCondn_VehicleLonAccel_KphpS_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_WIRCmdAmpBlnd_MtrNm_f32.value) = Rte_Ap_WhlImbRej_WIRCmdAmpBlnd_MtrNm_f32;

    /* call runnable */
    Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Start();
    DampingFirewall_Per1();
    Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Per1_Return();

    /* write implicit data */
    Rte_Ap_DampingFirewall_CombinedDamping_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DampingFirewall_DampingFirewall_Per1.Rte_CombinedDamping_MtrNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_GMStrtStop_StrtStop_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_GMStrtStop_StrtStop_Per1.Rte_APAState_State_enum.value) = Rte_TrqOvlSta_APAState_State_enum;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_GMStrtStop_StrtStop_Per1.Rte_EngSpd_Rpm_f32.value) = Rte_SrlComInput_SrlComEngineSpeed_Rpm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_GMStrtStop_StrtStop_Per1.Rte_HandwheelVelocity_HwRadpS_f32.value) = Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_GMStrtStop_StrtStop_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_GMStrtStop_StrtStop_Per1.Rte_SS12VFault_Cnt_lgc.value) = Rte_SrlComInput_StrtStopFaultActive_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_GMStrtStop_StrtStop_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

    /* call runnable */
    Rte_Runnable_Ap_GMStrtStop_StrtStop_Per1_Start();
    StrtStop_Per1();
    Rte_Runnable_Ap_GMStrtStop_StrtStop_Per1_Return();

    /* write implicit data */
    Rte_Ap_GMStrtStop_SSScale_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_GMStrtStop_StrtStop_Per1.Rte_SSScale_Uls_f32.value);
    Rte_Ap_GMStrtStop_SSSlew_UlspS_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_GMStrtStop_StrtStop_Per1.Rte_SSSlew_UlspS_f32.value);
    Rte_Ap_GMStrtStop_SSState_State_enum = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_GMStrtStop_StrtStop_Per1.Rte_SSState_State_enum.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_DiagRampRate_XpmS_f32.value) = Rte_DiagMgr_DiagRampRate_XpmS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_DiagRampValue_Uls_f32.value) = Rte_DiagMgr_DiagRampValue_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_DiagStsDiagRmpActive_Cnt_lgc.value) = Rte_DiagMgr_DiagRmpToZeroActive_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_LoaRateLimit_UlspS_f32.value) = Rte_Ap_LoaMgr_LoaRateLimit_UlspS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_LoaScaleFctr_Uls_f32.value) = Rte_Ap_LoaMgr_LoaScaleFctr_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_OperRampRate_XpmS_f32.value) = Rte_VehPwrMd_OperRampRate_XpmS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_OperRampValue_Uls_f32.value) = Rte_VehPwrMd_OperRampValue_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_RampSrlComSvcDft_Cnt_lgc.value) = Rte_CDDInterface_TrqRmpSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_StrtStopRateLimit_UlspS_f32.value) = Rte_Ap_GMStrtStop_SSSlew_UlspS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_StrtStopScaleFctr_Uls_f32.value) = Rte_Ap_GMStrtStop_SSScale_Uls_f32;

  /* call runnable */
  Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Start();
  StOpCtrl_Per1();
  Rte_Runnable_Ap_StOpCtrl_StOpCtrl_Per1_Return();

  /* write implicit data */
  Rte_StOpCtrl_OutputRampMult_Uls_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_StOpCtrl_OutputRampMult_Uls_f32.value);
  Rte_StOpCtrl_SysStReqDi_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StOpCtrl_StOpCtrl_Per1.Rte_SysStReqDi_Cnt_lgc.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_AssistEOTGain_Uls_f32.value) = Rte_EOTActuatorMng_AssistEOTGain_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_AssistEOTLimit_MtrNm_f32.value) = Rte_EOTActuatorMng_AssistEOTLimit_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_AssistStallLimit_MtrNm_f32.value) = Rte_HiLoadStall_AssistStallLimit_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_AstVehSpdLimit_MtrNm_f32.value) = Rte_VehSpdLmt_AstVehSpdLimit_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_LmtCod_LmtCod_Per1.Rte_ThermalLimit_MtrNm_f32.value) = Rte_Ap_ThrmlDutyCycle_ThermalLimit_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_SignlCondn_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Start();
  LmtCod_Per1();
  Rte_Runnable_Ap_LmtCod_LmtCod_Per1_Return();

  /* write implicit data */
  Rte_Ap_LmtCod_EOTGainLtd_Uls_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_LmtCod_EOTGainLtd_Uls_f32.value);
  Rte_Ap_LmtCod_EOTLimitLtd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_LmtCod_EOTLimitLtd_MtrNm_f32.value);
  Rte_Ap_LmtCod_OutputRampMultLtd_Uls_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_LmtCod_OutputRampMultLtd_Uls_f32.value);
  Rte_Ap_LmtCod_StallLimitLtd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_LmtCod_StallLimitLtd_MtrNm_f32.value);
  Rte_Ap_LmtCod_ThermalLimitLtd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_LmtCod_ThermalLimitLtd_MtrNm_f32.value);
  Rte_Ap_LmtCod_VehSpdLimitLtd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_LmtCod_VehSpdLimitLtd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_AbsHwPos_HandwheelAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32.value) = Rte_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_MotAgLoaMtgtnEn_Cnt_lgc.value) = Rte_Ap_LoaMgr_MotAgLoaMtgtnEn_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_TrqLoaDi_Cnt_lgc.value) = Rte_Ap_TrqLOA_TrqLoaDi_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_VehWhlBas_mm_f32.value) = Rte_Ap_TrqLOA_VehWhlBas_mm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_VehWhlBasVld_Cnt_lgc.value) = Rte_Ap_TrqLOA_VehWhlBasVld_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_VehicleLatAccel_MpSecSq_f32.value) = Rte_Ap_SignlCondn_VehicleLatAccel_MpSecSq_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_VehicleLatAccelValid_Cnt_lgc.value) = Rte_Ap_SignlCondn_VehicleLatAcceValid_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value) = Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_TrqLOA_TrqLOA_Per1_Start();
  TrqLOA_Per1();
  Rte_Runnable_Ap_TrqLOA_TrqLOA_Per1_Return();

  /* write implicit data */
  Rte_Ap_TrqLOA_TrqLOAAvail_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqLOA_TrqLOA_Per1.Rte_TrqLOAAvail_Cnt_lgc.value);
  Rte_Ap_TrqLOA_TrqLOACmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_TrqLOA_TrqLOACmd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_CcwEOT_HwDeg_f32.value) = Rte_Ap_LrnEOT_CCWPosition_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_CcwFound_Cnt_lgc.value) = Rte_Ap_LrnEOT_CCWFound_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_CwEOT_HwDeg_f32.value) = Rte_Ap_LrnEOT_CWPosition_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_CwFound_Cnt_lgc.value) = Rte_Ap_LrnEOT_CWFound_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_CDDInterface_EOTImpactSrlComSvcDft_Cnt_lgc.value) = Rte_CDDInterface_EOTImpactSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_PreLimitTorque_MtrNm_f32.value) = Rte_Ap_AstLmt_PreLimitTorque_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Start();
  EOTActuatorMng_Per1();
  Rte_Runnable_Ap_EOTActuatorMng_EOTActuatorMng_Per1_Return();

  /* write implicit data */
  Rte_EOTActuatorMng_AssistEOTDamping_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_EOTActuatorMng_AssistEOTDamping_MtrNm_f32.value);
  Rte_EOTActuatorMng_AssistEOTGain_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_AssistEOTGain_Uls_f32.value);
  Rte_EOTActuatorMng_AssistEOTLimit_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EOTActuatorMng_EOTActuatorMng_Per1.Rte_AssistEOTLimit_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_EtDmpFw_EtDmpFw_Per1.Rte_MEC_Counter_Cnt_enum.value) = Rte_CDDInterface_MEC_Cnt_enum;

  /* call runnable */
  Rte_Runnable_Ap_EtDmpFw_EtDmpFw_Per1_Start();
  EtDmpFw_Per1();
  Rte_Runnable_Ap_EtDmpFw_EtDmpFw_Per1_Return();

  /* write implicit data */
  Rte_Ap_EtDmpFw_EOTDampingLtd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_EtDmpFw_EOTDampingLtd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_AssistCmd_MtrNm_f32.value) = Rte_StabilityComp_AssistCmd_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_CombinedDamping_MtrNm_f32.value) = Rte_Ap_DampingFirewall_CombinedDamping_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_DefeatLimitService_Cnt_lgc.value) = Rte_CDDInterface_LimitSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_EotActvCmd_MtrNm_f32.value) = Rte_Ap_AstLmt_EotActvCmd_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_HwTqLoaMtgtnEn_Cnt_lgc.value) = Rte_Ap_LoaMgr_HwTqLoaMtgtnEn_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_LimitedReturn_MtrNm_f32.value) = Rte_ReturnFirewall_LimitedReturn_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_LrnPnCtrEnable_Cnt_lgc.value) = Rte_Ap_AstLmt_LrnPnCtrEnable_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_LrnPnCtrTCmd_MtrNm_f32.value) = Rte_Ap_AstLmt_LrnPnCtrTCmd_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_OpTrqOvr_MtrNm_f32.value) = Rte_Ap_TrqArblim_OpTrqOv_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_PowerLimitPerc_Uls_f32.value) = Rte_Ap_PwrLmtFuncCr_FltTrqLmt_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_PullCompCmd_MtrNm_f32.value) = Rte_Ap_ActivePull_PullCompCmd_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_TSMitCommand_MtrNm_f32.value) = Rte_Ap_TSMit_TSMitCommand_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_ThermalLimitPerc_Uls_f32.value) = Rte_Ap_ThrmlDutyCycle_ThermLimitPerc_Uls_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_WheelImbalanceCmd_MtrNm_f32.value) = Rte_Ap_WhlImbRej_WhlImbRejCmd_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Start();
  AstLmt_Per1();
  Rte_Runnable_Ap_AstLmt_AstLmt_Per1_Return();

  /* write implicit data */
  Rte_Ap_AstLmt_LimitPercentFiltered_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_LimitPercentFiltered_Uls_f32.value);
  Rte_Ap_AstLmt_PreLimitForStall_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_PreLimitForStall_MtrNm_f32.value);
  Rte_Ap_AstLmt_PreLimitTorque_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_PreLimitTorque_MtrNm_f32.value);
  Rte_Ap_AstLmt_SumLimTrqCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_AstLmt_SumLimTrqCmd_MtrNm_f32.value);
  Rte_Ap_AstLmt_TrqLimitMin_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_AstLmt_AstLmt_Per1.Rte_TrqLimitMin_MtrNm_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_Sweep2_Sweep2_Per1_Start();
  Sweep2_Per1();
  Rte_Runnable_Ap_Sweep2_Sweep2_Per1_Return();

  /* write implicit data */
  Rte_Ap_Sweep2_OutputMtrTrq_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_Sweep2_OutputMtrTrq_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TranlDampg_Ap_TranlDampg_Per1.Rte_AssistAssyPolarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TranlDampg_Ap_TranlDampg_Per1.Rte_DiagStsF2Active_Cnt_lgc.value) = Rte_DiagMgr_DiagStsCtrldDisRmpPres_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TranlDampg_Ap_TranlDampg_Per1.Rte_LoaSt_State_enum.value) = Rte_Ap_LoaMgr_LOASt_State_enum;

  /* call runnable */
  Rte_Runnable_Ap_TranlDampg_Ap_TranlDampg_Per1_Start();
  Ap_TranlDampg_Per1();
  Rte_Runnable_Ap_TranlDampg_Ap_TranlDampg_Per1_Return();

  /* write implicit data */
  Rte_Ap_TranlDampg_CRFMtrTrqCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TranlDampg_Ap_TranlDampg_Per1.Rte_CRFMtrTrqCmd_MtrNm_f32.value);
  Rte_Ap_TranlDampg_CntrlDampComp_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TranlDampg_Ap_TranlDampg_Per1.Rte_CntrlDampComp_Cnt_lgc.value);
  Rte_Ap_TranlDampg_MRFMtrTrqCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TranlDampg_Ap_TranlDampg_Per1.Rte_MRFMtrTrqCmd_MtrNm_f32.value);
  Rte_Ap_TranlDampg_SysC_CRFMtrTrqCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TranlDampg_Ap_TranlDampg_Per1.Rte_SysC_CRFMtrTrqCmd_MtrNm_f32.value);
  Rte_Ap_TranlDampg_SysC_MRFMtrTrqCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TranlDampg_Ap_TranlDampg_Per1.Rte_SysC_MRFMtrTrqCmd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_BattVltg_BattVltg_Per1.Rte_BattSwdVltgCorrlnSts_Cnt_u08.value) = Rte_Ap_BattVltgCorrln_BattSwdVltgCorrlnSts_Cnt_u08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_BattVltg_BattVltg_Per1.Rte_BattVltg_Volt_f32.value) = Rte_IoHwAbstractionUsr_Batt_Volt_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_BattVltg_BattVltg_Per1.Rte_BattVltgSwd1_Volt_f32.value) = Rte_IoHwAbstractionUsr_BattSwitched1_Volt_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_BattVltg_BattVltg_Per1.Rte_BattVltgSwd2_Volt_f32.value) = Rte_IoHwAbstractionUsr_BattSwitched2_Volt_f32;

  /* call runnable */
  Rte_Runnable_Ap_BattVltg_BattVltg_Per1_Start();
  BattVltg_Per1();
  Rte_Runnable_Ap_BattVltg_BattVltg_Per1_Return();

  /* write implicit data */
  Rte_Ap_BattVltg_BrdgVltg_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_BattVltg_BattVltg_Per1.Rte_BrdgVltg_Volt_f32.value);

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1.Rte_AltFaultActive_Cnt_lgc.value) = Rte_Ap_PwrLmtFuncCr_AltFaultActive_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1.Rte_CntDisMtrTrqCmdMRF_MtrNm_f32.value) = Rte_Ap_TranlDampg_MRFMtrTrqCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1.Rte_EstKe_VpRadpS_f32.value) = Rte_CurrParamComp_EstKe_VpRadpS_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1.Rte_IvtrLoaMtgtnEn_Cnt_lgc.value) = Rte_Ap_LoaMgr_IvtrLoaMtgtnEn_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1.Rte_MotorVelMRF_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1.Rte_PosServEnable_Cnt_lgc.value) = Rte_TrqOvlSta_PosServEnable_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1.Rte_Vecu_Volt_f32.value) = Rte_Ap_BattVltg_BrdgVltg_Volt_f32;

    /* call runnable */
    Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Start();
    PwrLmtFuncCr_Per1();
    Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1_Return();

    /* write implicit data */
    Rte_Ap_PwrLmtFuncCr_MRFMtrTrqCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Per1.Rte_MRFMtrTrqCmd_MtrNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqCmdScl_TrqCmdScl_Per1.Rte_MRFMtrTrqCmd_MtrNm_f32.value) = Rte_Ap_PwrLmtFuncCr_MRFMtrTrqCmd_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Start();
  TrqCmdScl_Per1();
  Rte_Runnable_Ap_TrqCmdScl_TrqCmdScl_Per1_Return();

  /* write implicit data */
  Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqCmdScl_TrqCmdScl_Per1.Rte_MRFMtrTrqCmdScl_MtrNm_f32.value);

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_ADCMtrCurrA_Volt_f32.value) = Rte_CDDInterface_ADCMtrCurrA_Volt_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_ADCMtrCurrB_Volt_f32.value) = Rte_CDDInterface_ADCMtrCurrB_Volt_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_ADCMtrCurrC_Volt_f32.value) = Rte_CDDInterface_ADCMtrCurrC_Volt_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_CorrMtrCurrA_Amp_f32.value) = Rte_CDDInterface_CorrMtrCurrA_Amp_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_CorrMtrCurrB_Amp_f32.value) = Rte_CDDInterface_CorrMtrCurrB_Amp_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_CorrMtrCurrC_Amp_f32.value) = Rte_CDDInterface_CorrMtrCurrC_Amp_f32;

    /* call runnable */
    Rte_Runnable_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2_Start();
    CmMtrCurr3Phs_Per2();
    Rte_Runnable_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2_Return();

    /* write implicit data */
    Rte_Sa_CmMtrCurr3Phs_MtrCurrIdptSig_Cnt_u08 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_MtrCurrIdptSig_Cnt_u08.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_ADCMtrCurrA_Volt_f32.value) = Rte_CDDInterface_ADCMtrCurrA_Volt_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_ADCMtrCurrB_Volt_f32.value) = Rte_CDDInterface_ADCMtrCurrB_Volt_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_ADCMtrCurrC_Volt_f32.value) = Rte_CDDInterface_ADCMtrCurrC_Volt_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_MtrVel_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_Vecu_Volt_f32.value) = Rte_Ap_BattVltg_BrdgVltg_Volt_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_VehSpd_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_VhSpdValid_Cnt_lgc.value) = Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3_Start();
    CmMtrCurr3Phs_Per3();
    Rte_Runnable_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3_Return();

    /* write implicit data */
    Rte_Sa_CmMtrCurr3Phs_ComOffset_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_ComOffset_Cnt_u16.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotPosnCmp_MotPosnCmp_Per2.Rte_AssiMechPolarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotPosnCmp_MotPosnCmp_Per2.Rte_MotPosnCumvAlgnd_Rev_f32.value) = Rte_CDDInterface_MotPosnCmpMotPosnCumvAlgnd_Rev_f32;

  /* call runnable */
  Rte_Runnable_Ap_MotPosnCmp_MotPosnCmp_Per2_Start();
  MotPosnCmp_Per2();
  Rte_Runnable_Ap_MotPosnCmp_MotPosnCmp_Per2_Return();

  /* write implicit data */
  Rte_Ap_MotPosnCmp_MotPosnCumvAlgndCrf_Deg_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotPosnCmp_MotPosnCmp_Per2.Rte_MotPosnCumvAlgndCrf_Deg_f32.value);
  Rte_Ap_MotPosnCmp_MotPosnCumvAlgndMrf_Deg_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_MotPosnCmp_MotPosnCumvAlgndMrf_Deg_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32.value) = Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Start();
  QuadDet_Per1();
  Rte_Runnable_Ap_QuadDet_QuadDet_Per1_Return();

  /* write implicit data */
  Rte_QuadDet_InstMtrDir_Cnt_s08 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_QuadDet_QuadDet_Per1.Rte_InstMtrDir_Cnt_s08.value);
  Rte_QuadDet_MtrQuad_Cnt_u08 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_QuadDet_MtrQuad_Cnt_u08.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrCmd_CurrCmd_Per1.Rte_CurrentGainSvc_Cnt_lgc.value) = Rte_Sa_CmMtrCurr3Phs_CurrentGainSvc_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrCmd_CurrCmd_Per1.Rte_DualEcuMotCtrlMtgnEna_Cnt_lgc.value) = Rte_CurrCmd_DualEcuMotCtrlMtgnEna_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrCmd_CurrCmd_Per1.Rte_EstKe_VpRadpS_f32.value) = Rte_CurrParamComp_EstKe_VpRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrCmd_CurrCmd_Per1.Rte_EstLd_Henry_f32.value) = Rte_CurrParamComp_EstLd_Henry_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrCmd_CurrCmd_Per1.Rte_EstLq_Henry_f32.value) = Rte_CurrParamComp_EstLq_Henry_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrCmd_CurrCmd_Per1.Rte_EstR_Ohm_f32.value) = Rte_CurrParamComp_EstR_Ohm_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_LoaMgr_IvtrLoaMtgtnEn_Cnt_lgc.value) = Rte_Ap_LoaMgr_IvtrLoaMtgtnEn_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_LoaMgr_MotCurrLoaMtgtnEn_Cnt_lgc.value) = Rte_Ap_LoaMgr_MotCurrLoaMtgtnEn_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_BattVltg_BrdgVltg_Volt_f32.value) = Rte_Ap_BattVltg_BrdgVltg_Volt_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrCmd_CurrCmd_Per1.Rte_VehSpd_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Start();
  CurrCmd_Per1();
  Rte_Runnable_Ap_CurrCmd_CurrCmd_Per1_Return();

  /* write implicit data */
  Rte_CurrCmd_MtrCurrAngle_Rev_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrCmd_CurrCmd_Per1.Rte_MtrCurrAngle_Rev_f32.value);
  Rte_CurrCmd_MtrCurrDaxRef_Amp_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrCmd_CurrCmd_Per1.Rte_MtrCurrDaxRef_Amp_f32.value);
  Rte_CurrCmd_MtrCurrQaxRef_Amp_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrCmd_CurrCmd_Per1.Rte_MtrCurrQaxRef_Amp_f32.value);
  Rte_CurrCmd_MtrVoltDaxFFStatic_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrCmd_CurrCmd_Per1.Rte_MtrVoltDaxFFStatic_Volt_f32.value);
  Rte_CurrCmd_MtrVoltQaxFFStatic_Volt_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrCmd_CurrCmd_Per1.Rte_MtrVoltQaxFFStatic_Volt_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_AssistAssemblyPolarity_Cnt_s08.value) = Rte_CDDInterface_AssistAssemblyPolarity_Cnt_s08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_CommOffset_Cnt_u16.value) = Rte_Sa_CmMtrCurr3Phs_ComOffset_Cnt_u16;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MotAgCorrlnMtrPosCorrlnSts_Cnt_u16.value) = Rte_Ap_MotAgCorrln_MtrPosCorrlnSts_Cnt_u16;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MotMeclPosn1MotPosnQlfr_State_enum.value) = Rte_Sa_MotMeclPosn1_MotPosnQlfr_State_enum;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MotMeclPosn1Polarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn1Polarity_Cnt_s08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MotMeclPosn2MotPosnQlfr_State_enum.value) = Rte_Sa_MotMeclPosn2_MotPosnQlfr_State_enum;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MotMeclPosn2Polarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn2Polarity_Cnt_s08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurrATempOffset_Volt_f32.value) = Rte_Sa_CmMtrCurr3Phs_MtrCurrATempOffset_Volt_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurrBTempOffset_Volt_f32.value) = Rte_Sa_CmMtrCurr3Phs_MtrCurrBTempOffset_Volt_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurrCTempOffset_Volt_f32.value) = Rte_Sa_CmMtrCurr3Phs_MtrCurrCTempOffset_Volt_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrPosPolarity_Cnt_s08.value) = Rte_CDDInterface_MtrPosPolarity_Cnt_s08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrTrqCmdSign_Cnt_s16.value) = Rte_CDDInterface_MtrTrqCmdSign_Cnt_s16;

  /* call runnable */
  Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Start();
  CDDInterface_Per2();
  Rte_Runnable_Sa_CDDInterface_CDDInterface_Per2_Return();

  /* call runnable */
  Rte_Runnable_Sa_TmplMonrDualIvtr2_TmplMonrDualIvtr2_Per1_Start();
  TmplMonrDualIvtr2_Per1();
  Rte_Runnable_Sa_TmplMonrDualIvtr2_TmplMonrDualIvtr2_Per1_Return();

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2.Rte_TMFTestStart_Cnt_lgc.value) = Rte_Ap_HwPwrUpSeq_TMFTestStart_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2_Start();
    TmplMonrDualIvtr_Per2();
    Rte_Runnable_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2_Return();

    /* write implicit data */
    Rte_Sa_TmplMonrDualIvtr_TMFTestComplete_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per2.Rte_TMFTestComplete_Cnt_lgc.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MotMeclPosn1_MotMeclPosn1_Per2.Rte_MotMeclPosn1RawErrReg_Cnt_u16.value) = Rte_CDDInterface_MotMeclPosn1RawErrReg_Cnt_u16;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MotMeclPosn1_MotMeclPosn1_Per2.Rte_ParityFaultAccum_Cnt_u16.value) = Rte_CDDInterface_MotMeclPosn1ParityFaultAccum_Cnt_u16;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MotMeclPosn1_MotMeclPosn1_Per2.Rte_UnderVltgFaultAccum_Cnt_u16.value) = Rte_CDDInterface_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16;

  /* call runnable */
  Rte_Runnable_Sa_MotMeclPosn1_MotMeclPosn1_Per2_Start();
  MotMeclPosn1_Per2();
  Rte_Runnable_Sa_MotMeclPosn1_MotMeclPosn1_Per2_Return();

  /* write implicit data */
  Rte_Sa_MotMeclPosn1_MotPosnQlfr_State_enum = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_MotMeclPosn1_MotPosnQlfr_State_enum.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MotMeclPosn2_MotMeclPosn2_Per2.Rte_MotMeclPosn2RawErrReg_Cnt_u16.value) = Rte_CDDInterface_MotMeclPosn2RawErrReg_Cnt_u16;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MotMeclPosn2_MotMeclPosn2_Per2.Rte_ParityFaultAccum_Cnt_u16.value) = Rte_CDDInterface_MotMeclPosn2ParityFaultAccum_Cnt_u16;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MotMeclPosn2_MotMeclPosn2_Per2.Rte_UnderVltgFaultAccum_Cnt_u16.value) = Rte_CDDInterface_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16;

  /* call runnable */
  Rte_Runnable_Sa_MotMeclPosn2_MotMeclPosn2_Per2_Start();
  MotMeclPosn2_Per2();
  Rte_Runnable_Sa_MotMeclPosn2_MotMeclPosn2_Per2_Return();

  /* write implicit data */
  Rte_Sa_MotMeclPosn2_MotPosnQlfr_State_enum = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_MotMeclPosn2_MotPosnQlfr_State_enum.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos3SinCos_MtrPos3SinCos_Per1.Rte_MtrMechPos3Polarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_MotMeclPosn3Polarity_Cnt_s08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos3SinCos_MtrPos3SinCos_Per1.Rte_MtrPos3Cos_Volt_u3p13.value) = Rte_IoHwAbstractionUsr_MtrPos3Con_Volt_u3p13;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrPos3SinCos_MtrPos3SinCos_Per1.Rte_MtrPos3Sin_Volt_u3p13.value) = Rte_IoHwAbstractionUsr_MtrPos3Sin_Volt_u3p13;

  /* call runnable */
  Rte_Runnable_Sa_MtrPos3SinCos_MtrPos3SinCos_Per1_Start();
  MtrPos3SinCos_Per1();
  Rte_Runnable_Sa_MtrPos3SinCos_MtrPos3SinCos_Per1_Return();

  /* write implicit data */
  Rte_Sa_MtrPos3SinCos_MtrPos3Mech_Rev_u0p16 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_MtrPos3SinCos_MtrPos3Mech_Rev_u0p16.value);
  Rte_Sa_MtrPos3SinCos_MtrPos3Qlfr_State_enum = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_MtrPos3SinCos_MtrPos3Qlfr_State_enum.value);
  Rte_Sa_MtrPos3SinCos_MtrPos3RollgCntr_Cnt_u08 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_MtrPos3SinCos_MtrPos3RollgCntr_Cnt_u08.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotAgCorrln_MotAgCorrln_Per1.Rte_MotMeclPosn1_Rev_u0p16.value) = Rte_CDDInterface_MotMeclPosn1RevM_Rev_u0p16;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotAgCorrln_MotAgCorrln_Per1.Rte_MotMeclPosn1RollgCntr_Cnt_u08.value) = Rte_CDDInterface_MotMeclPosn1RollgCntr_Cnt_u08;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotAgCorrln_MotAgCorrln_Per1.Rte_MotMeclPosn2_Rev_u0p16.value) = Rte_CDDInterface_MotMeclPosn2RevM_Rev_u0p16;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotAgCorrln_MotAgCorrln_Per1.Rte_MotMeclPosn2RollgCntr_Cnt_u08.value) = Rte_CDDInterface_MotMeclPosn2RollgCntr_Cnt_u08;

  /* call runnable */
  Rte_Runnable_Ap_MotAgCorrln_MotAgCorrln_Per1_Start();
  MotAgCorrln_Per1();
  Rte_Runnable_Ap_MotAgCorrln_MotAgCorrln_Per1_Return();

  /* write implicit data */
  Rte_Ap_MotAgCorrln_MtrPosCorrlnSts_Cnt_u16 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotAgCorrln_MotAgCorrln_Per1.Rte_MtrPosCorrlnSts_Cnt_u16.value);
  Rte_Ap_MotAgCorrln_MtrPosIdptSig_Cnt_u08 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_MotAgCorrln_MotAgCorrln_Per1.Rte_MtrPosIdptSig_Cnt_u08.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1.Rte_MtrDrvr0InitComplete_Cnt_lgc.value) = Rte_Sa_MtrDrvDiag_MtrDrvr1InitComplete_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1.Rte_MtrDrvr1InitComplete_Cnt_lgc.value) = Rte_Sa_MtrDrvDiag_MtrDrvr2InitComplete_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1.Rte_PwrDiscATestComplete_Cnt_lgc.value) = Rte_Ap_PwrDscntDuInv_PwrDiscATestComplete_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1.Rte_PwrDiscBTestComplete_Cnt_lgc.value) = Rte_Ap_PwrDscntDuInv_PwrDiscBTestComplete_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1.Rte_TMFTestComplete_Cnt_lgc.value) = Rte_Sa_TmplMonrDualIvtr_TMFTestComplete_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1_Start();
  HwPwrUpSeq_Per1();
  Rte_Runnable_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1_Return();

  /* write implicit data */
  Rte_Ap_HwPwrUpSeq_MtrDrvr0InitStart_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1.Rte_MtrDrvr0InitStart_Cnt_lgc.value);
  Rte_Ap_HwPwrUpSeq_MtrDrvr1InitStart_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1.Rte_MtrDrvr1InitStart_Cnt_lgc.value);
  Rte_Ap_HwPwrUpSeq_OverVltgMonStart_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1.Rte_OverVltgMonStart_Cnt_lgc.value);
  Rte_Ap_HwPwrUpSeq_PwrDiscATestStart_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1.Rte_PwrDiscATestStart_Cnt_lgc.value);
  Rte_Ap_HwPwrUpSeq_PwrDiscBTestStart_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1.Rte_PwrDiscBTestStart_Cnt_lgc.value);
  Rte_Ap_HwPwrUpSeq_TMFTestStart_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HwPwrUpSeq_HwPwrUpSeq_Per1.Rte_TMFTestStart_Cnt_lgc.value);

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_Inverter1Inactive_Cnt_lgc.value) = Rte_DiagMgr_DiagStsInverter1Inactive_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_Inverter2Inactive_Cnt_lgc.value) = Rte_DiagMgr_DiagStsInverter2Inactive_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_MtrDrvr1InitStart_Cnt_lgc.value) = Rte_Ap_HwPwrUpSeq_MtrDrvr0InitStart_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_MtrDrvr2InitStart_Cnt_lgc.value) = Rte_Ap_HwPwrUpSeq_MtrDrvr1InitStart_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Start();
    MtrDrvDiag_Per1();
    Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per1_Return();

    /* write implicit data */
    Rte_Sa_MtrDrvDiag_GateDrive1ResetActive_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_GateDrive1ResetActive_Cnt_lgc.value);
    Rte_Sa_MtrDrvDiag_GateDrive2ResetActive_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_GateDrive2ResetActive_Cnt_lgc.value);
    Rte_Sa_MtrDrvDiag_MtrDrvr1InitComplete_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_MtrDrvr1InitComplete_Cnt_lgc.value);
    Rte_Sa_MtrDrvDiag_MtrDrvr2InitComplete_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per1.Rte_MtrDrvr2InitComplete_Cnt_lgc.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Sa_MtrDrvDiag_MtrDrvDiag_Per2 == 0)
  {
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per2.Rte_Inverter1Inactive_Cnt_lgc.value) = Rte_DiagMgr_DiagStsInverter1Inactive_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Per2.Rte_Inverter2Inactive_Cnt_lgc.value) = Rte_DiagMgr_DiagStsInverter2Inactive_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Start();
    MtrDrvDiag_Per2();
    Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Per2_Return();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Per1.Rte_DualEcuFltMtgtnEna_Cnt_lgc.value) = Rte_CurrParamComp_DualEcuFltMtgtnEna_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Per1.Rte_IvtrLoaMtgtnEn_Cnt_lgc.value) = Rte_CurrParamComp_IvtrLoaMtgtnEn_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Per1.Rte_MtrCurrDaxRef_Amp_f32.value) = Rte_CurrCmd_MtrCurrDaxRef_Amp_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Per1.Rte_MtrCurrQaxRef_Amp_f32.value) = Rte_CurrCmd_MtrCurrQaxRef_Amp_f32;

  /* call runnable */
  Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Start();
  CurrParamComp_Per1();
  Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Per1_Return();

  /* write implicit data */
  Rte_CurrParamComp_EstKe_VpRadpS_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Per1.Rte_EstKe_VpRadpS_f32.value);
  Rte_CurrParamComp_EstLd_Henry_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Per1.Rte_EstLd_Henry_f32.value);
  Rte_CurrParamComp_EstLq_Henry_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Per1.Rte_EstLq_Henry_f32.value);
  Rte_CurrParamComp_EstR_Ohm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Per1.Rte_EstR_Ohm_f32.value);

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Start();
  uDiagLossOfExec_Per2();
  Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per2_Return();

  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_PeakCurrEst_PeakCurrEst_Per1 == 0)
  {
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PeakCurrEst_PeakCurrEst_Per1.Rte_DualEcuMotCtrlMtgnEna_Cnt_lgc.value) = Rte_PeakCurrEst_DualEcuMotCtrlMtgnEna_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PeakCurrEst_PeakCurrEst_Per1.Rte_IvtrLoaMtgtnEn_Cnt_lgc.value) = Rte_Ap_LoaMgr_IvtrLoaMtgtnEn_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PeakCurrEst_PeakCurrEst_Per1.Rte_MotCurrLoaMtgtnEn_Cnt_lgc.value) = Rte_Ap_LoaMgr_MotCurrLoaMtgtnEn_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PeakCurrEst_PeakCurrEst_Per1.Rte_MtrCurrDax_Amp_f32.value) = Rte_CDDInterface_MtrCurrDax_Amp_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PeakCurrEst_PeakCurrEst_Per1.Rte_MtrCurrDaxRef_Amp_f32.value) = Rte_CurrCmd_MtrCurrDaxRef_Amp_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PeakCurrEst_PeakCurrEst_Per1.Rte_MtrCurrQax_Amp_f32.value) = Rte_CDDInterface_MtrCurrQax_Amp_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PeakCurrEst_PeakCurrEst_Per1.Rte_MtrCurrQaxRef_Amp_f32.value) = Rte_CurrCmd_MtrCurrQaxRef_Amp_f32;

    /* call runnable */
    Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Start();
    PeakCurrEst_Per1();
    Rte_Runnable_Ap_PeakCurrEst_PeakCurrEst_Per1_Return();

    /* write implicit data */
    Rte_PeakCurrEst_EstPkCurr_AmpSq_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PeakCurrEst_PeakCurrEst_Per1.Rte_EstPkCurr_AmpSq_f32.value);
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqCanc_TrqCanc_Per1.Rte_EstKe_VpRadpS_f32.value) = Rte_CurrParamComp_EstKe_VpRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqCanc_TrqCanc_Per1.Rte_EstLd_Henry_f32.value) = Rte_CurrParamComp_EstLd_Henry_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqCanc_TrqCanc_Per1.Rte_EstLq_Henry_f32.value) = Rte_CurrParamComp_EstLq_Henry_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqCanc_TrqCanc_Per1.Rte_MRFMtrVel_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqCanc_TrqCanc_Per1.Rte_MtrCurrDaxRef_Amp_f32.value) = Rte_CurrCmd_MtrCurrDaxRef_Amp_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqCanc_TrqCanc_Per1.Rte_MtrCurrQaxRef_Amp_f32.value) = Rte_CurrCmd_MtrCurrQaxRef_Amp_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqCanc_TrqCanc_Per1.Rte_MtrTrqCmdMRFScl_MtrNm_f32.value) = Rte_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Start();
  TrqCanc_Per1();
  Rte_Runnable_Ap_TrqCanc_TrqCanc_Per1_Return();

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_TrqOvlSta_TrqOvlSta_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_APANonRecoverableFaults_Cnt_lgc.value) = Rte_SrlComInput_APANonRecoverableFaults_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_APARecoverableFaults_Cnt_lgc.value) = Rte_SrlComInput_APARecoverableFaults_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_APARequest_Cnt_lgc.value) = Rte_SrlComInput_APARequest_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_CCWPosition_HwDeg_f32.value) = Rte_Ap_LrnEOT_CCWPosition_HwDeg_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_CWPosition_HwDeg_f32.value) = Rte_Ap_LrnEOT_CWPosition_HwDeg_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_ESCFault_Cnt_lgc.value) = Rte_SrlComInput_ESCFault_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_ESCIsLimited_Cnt_lgc.value) = Rte_Ap_TrqArblim_ESCIsLimited_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_ESCRequest_Cnt_lgc.value) = Rte_SrlComInput_ESCRequest_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_GMOSH_APAMfgEnable_Cnt_lgc.value) = Rte_SrlComInput_APAMfgEnable_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_GMOSH_ESCMfgEnable_Cnt_lgc.value) = Rte_SrlComInput_ESCMfgEnable_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_GMOSH_LKAMfgEnable_Cnt_lgc.value) = Rte_SrlComInput_LKAMfgEnable_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_HapticRequest_Cnt_lgc.value) = Rte_SrlComInput_HapticRequest_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LKAFault_Cnt_lgc.value) = Rte_SrlComInput_LKAFault_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LKAInhibit_Cnt_lgc.value) = Rte_SrlComInput_LKAInhibit_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LKARequest_Cnt_lgc.value) = Rte_SrlComInput_LKARequest_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LOASt_State_enum.value) = Rte_Ap_LoaMgr_LOASt_State_enum;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_MaxSecureVehicleSpeed_Kph_f32.value) = Rte_SrlComInput_MaxSecureVehicleSpeed_Kph_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_MinSecureVehicleSpeed_Kph_f32.value) = Rte_SrlComInput_MinSecureVehicleSpeed_Kph_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_PosTrajEnable_Cnt_lgc.value) = Rte_CDDInterface_PosTrajEnable_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_PosTrajHwAngle_HwDeg_f32.value) = Rte_Ap_GenPosTraj_PosTrajHwAngle_HwDeg_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_SWARTrgtAngRequest_HwDeg_f32.value) = Rte_SrlComInput_SWARTrgtAngRequest_HwDeg_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_ShiftLeverIsInReverse_Cnt_lgc.value) = Rte_SrlComInput_ShiftLeverIsInReverse_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_VehSpd_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

    /* call runnable */
    Rte_Runnable_Ap_TrqOvlSta_TrqOvlSta_Per1_Start();
    TrqOvlSta_Per1();
    Rte_Runnable_Ap_TrqOvlSta_TrqOvlSta_Per1_Return();

    /* write implicit data */
    Rte_TrqOvlSta_APADrvrInterventionDetected_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_APADrvrInterventionDetected_Cnt_lgc.value);
    Rte_TrqOvlSta_APAState_State_enum = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_APAState_State_enum.value);
    Rte_TrqOvlSta_ESCState_State_enum = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_ESCState_State_enum.value);
    Rte_TrqOvlSta_GMOSHOscillateState_State_enum = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_GMOSHOscillateState_State_enum.value);
    Rte_TrqOvlSta_LKAState_State_enum = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LKAState_State_enum.value);
    Rte_TrqOvlSta_LkaDrvrIntvDetd_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LkaDrvrIntvDetd_Cnt_lgc.value);
    Rte_TrqOvlSta_PosServEnable_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_PosServEnable_Cnt_lgc.value);
    Rte_TrqOvlSta_PosSrvoHwAngle_HwDeg_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_PosSrvoHwAngle_HwDeg_f32.value);
    Rte_TrqOvlSta_TrqOscAmp_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_TrqOscAmp_MtrNm_f32.value);
    Rte_TrqOvlSta_TrqOscEnable_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_TrqOscEnable_Cnt_lgc.value);
    Rte_TrqOvlSta_TrqOscFreq_Hz_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_TrqOscFreq_Hz_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscAmp_MtrNm_f32.value) = Rte_TrqOvlSta_TrqOscAmp_MtrNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscEnable_Cnt_lgc.value) = Rte_TrqOvlSta_TrqOscEnable_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscFreq_Hz_f32.value) = Rte_TrqOvlSta_TrqOscFreq_Hz_f32;

  /* call runnable */
  Rte_Runnable_Ap_TrqOsc_TrqOsc_Per1_Start();
  TrqOsc_Per1();
  Rte_Runnable_Ap_TrqOsc_TrqOsc_Per1_Return();

  /* write implicit data */
  Rte_Ap_TrqOsc_TrqOscCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscCmd_MtrNm_f32.value);
  Rte_Ap_TrqOsc_TrqOscDCExceeded_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOsc_TrqOsc_Per1.Rte_TrqOscDCExceeded_Cnt_lgc.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_HandwheelPosition_HwDeg_f32.value) = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_MotorVelCRF_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoEnable_Cnt_lgc.value) = Rte_TrqOvlSta_PosServEnable_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoHwAngle_HwDeg_f32.value) = Rte_TrqOvlSta_PosSrvoHwAngle_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_PosServo_PosServo_Per1_Start();
  PosServo_Per1();
  Rte_Runnable_Ap_PosServo_PosServo_Per1_Return();

  /* write implicit data */
  Rte_Ap_PosServo_PosSrvoCmd_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoCmd_MtrNm_f32.value);
  Rte_Ap_PosServo_PosSrvoReturnSclFct_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoReturnSclFct_Uls_f32.value);
  Rte_Ap_PosServo_PosSrvoSmoothEnable_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PosServo_PosServo_Per1.Rte_PosSrvoSmoothEnable_Uls_f32.value);

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TrqArblim_TrqArblim_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ESCCmd_HwNm_f32.value) = Rte_SrlComInput_ESCCmd_HwNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ESCState_State_enum.value) = Rte_TrqOvlSta_ESCState_State_enum;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_LKACmd_HwNm_f32.value) = Rte_SrlComInput_LKACmd_HwNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_LKAState_State_enum.value) = Rte_TrqOvlSta_LKAState_State_enum;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_MaxSecureVehicleSpeed_Kph_f32.value) = Rte_SrlComInput_MaxSecureVehicleSpeed_Kph_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_PosServEnable_Cnt_lgc.value) = Rte_TrqOvlSta_PosServEnable_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_PosSrvoCmd_MtrNm_f32.value) = Rte_Ap_PosServo_PosSrvoCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_TrqOscCmd_MtrNm_f32.value) = Rte_Ap_TrqOsc_TrqOscCmd_MtrNm_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_TrqOscEnable_Cnt_lgc.value) = Rte_TrqOvlSta_TrqOscEnable_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Ap_TrqArblim_TrqArblim_Per1_Start();
    TrqArblim_Per1();
    Rte_Runnable_Ap_TrqArblim_TrqArblim_Per1_Return();

    /* write implicit data */
    Rte_Ap_TrqArblim_AssistDDFactor_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_AssistDDFactor_Uls_f32.value);
    Rte_Ap_TrqArblim_DampingDDFactor_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_DampingDDFactor_Uls_f32.value);
    Rte_Ap_TrqArblim_ESCIsLimited_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ESCIsLimited_Cnt_lgc.value);
    Rte_Ap_TrqArblim_ESCTorqueDelivered_HwNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ESCTorqueDelivered_HwNm_f32.value);
    Rte_Ap_TrqArblim_IqTrqOv_HwNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_IqTrqOv_HwNm_f32.value);
    Rte_Ap_TrqArblim_LKATorqueDelivered_HwNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_LKATorqueDelivered_HwNm_f32.value);
    Rte_Ap_TrqArblim_OpTrqOv_MtrNm_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_OpTrqOv_MtrNm_f32.value);
    Rte_Ap_TrqArblim_PullCmpCustLrngDi_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_PullCmpCustLrngDi_Cnt_lgc.value);
    Rte_Ap_TrqArblim_ReturnDDFactor_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ReturnDDFactor_Uls_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1.Rte_VBattADC_Volt_f32.value) = Rte_IoHwAbstractionUsr_Batt_Volt_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1.Rte_VSwitch1ADC_Volt_f32.value) = Rte_IoHwAbstractionUsr_BattSwitched2_Volt_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1.Rte_VSwitch2ADC_Volt_f32.value) = Rte_IoHwAbstractionUsr_BattSwitched1_Volt_f32;

    /* call runnable */
    Rte_Runnable_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1_Start();
    PwrDscntDuInv_Per1();
    Rte_Runnable_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1_Return();

    /* write implicit data */
    Rte_Ap_PwrDscntDuInv_PwrDiscATestComplete_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1.Rte_PwrDiscATestComplete_Cnt_lgc.value);
    Rte_Ap_PwrDscntDuInv_PwrDiscBTestComplete_Cnt_lgc = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_PwrDscntDuInv_PwrDscntDuInv_Per1.Rte_PwrDiscBTestComplete_Cnt_lgc.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HOWDetect_HOWDetect_Per1.Rte_HwTrq_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HOWDetect_HOWDetect_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HOWDetect_HOWDetect_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value) = Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_HOWDetect_HOWDetect_Per1_Start();
  HOWDetect_Per1();
  Rte_Runnable_Ap_HOWDetect_HOWDetect_Per1_Return();

  /* write implicit data */
  Rte_Ap_HOWDetect_HOWEstimate_Uls_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HOWDetect_HOWDetect_Per1.Rte_HOWEstimate_Uls_f32.value);
  Rte_Ap_HOWDetect_HOWState_Cnt_s08 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_HOWDetect_HOWDetect_Per1.Rte_HOWState_Cnt_s08.value);

  /* call runnable */
  Rte_Runnable_Cd_PhaseFdbkMeas_Cd_PhaseFdbkMeas_Per1_Start();
  Cd_PhaseFdbkMeas_Per1();
  Rte_Runnable_Cd_PhaseFdbkMeas_Cd_PhaseFdbkMeas_Per1_Return();

  /* write implicit data */
  Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeA_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Cd_PhaseFdbkMeas_Cd_PhaseFdbkMeas_Per1.Rte_MeasuredOnTimeA_Cnt_u32.value);
  Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeB_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Cd_PhaseFdbkMeas_Cd_PhaseFdbkMeas_Per1.Rte_MeasuredOnTimeB_Cnt_u32.value);
  Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeC_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Cd_PhaseFdbkMeas_Cd_PhaseFdbkMeas_Per1.Rte_MeasuredOnTimeC_Cnt_u32.value);
  Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeD_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Cd_PhaseFdbkMeas_Cd_PhaseFdbkMeas_Per1.Rte_MeasuredOnTimeD_Cnt_u32.value);
  Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeE_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Cd_PhaseFdbkMeas_Cd_PhaseFdbkMeas_Per1.Rte_MeasuredOnTimeE_Cnt_u32.value);
  Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeF_Cnt_u32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Cd_PhaseFdbkMeas_Cd_PhaseFdbkMeas_Per1.Rte_MeasuredOnTimeF_Cnt_u32.value);

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_ExpectedOnTimeA_Cnt_u32.value) = Rte_CDDInterface_ExpectedOnTimeA_Cnt_u32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_ExpectedOnTimeB_Cnt_u32.value) = Rte_CDDInterface_ExpectedOnTimeB_Cnt_u32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_ExpectedOnTimeC_Cnt_u32.value) = Rte_CDDInterface_ExpectedOnTimeC_Cnt_u32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_GateDrive1ResetActive_Cnt_lgc.value) = Rte_Sa_MtrDrvDiag_GateDrive1ResetActive_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_GateDrive2ResetActive_Cnt_lgc.value) = Rte_Sa_MtrDrvDiag_GateDrive2ResetActive_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_Inverter1Inactive_Cnt_lgc.value) = Rte_DiagMgr_DiagStsInverter1Inactive_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_Inverter2Inactive_Cnt_lgc.value) = Rte_DiagMgr_DiagStsInverter2Inactive_Cnt_lgc;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_MeasuredOnTimeA_Cnt_u32.value) = Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeA_Cnt_u32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_MeasuredOnTimeB_Cnt_u32.value) = Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeB_Cnt_u32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_MeasuredOnTimeC_Cnt_u32.value) = Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeC_Cnt_u32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_MeasuredOnTimeD_Cnt_u32.value) = Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeD_Cnt_u32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_MeasuredOnTimeE_Cnt_u32.value) = Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeE_Cnt_u32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_MeasuredOnTimeF_Cnt_u32.value) = Rte_Cd_PhaseFdbkMeas_MeasuredOnTimeF_Cnt_u32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1.Rte_PDActivateTest_Cnt_lgc.value) = Rte_Ap_DigPhsReasDiag_PDActivateTest_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Start();
    DigPhsReasDiag_Per1();
    Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Per1_Return();
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ePWM2_ePWM2_Per1.Rte_CtrldDmpStsCmp_Cnt_lgc.value) = Rte_Ap_TranlDampg_CntrlDampComp_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ePWM2_ePWM2_Per1.Rte_DiagStsCtrldDisRmpPres_Cnt_lgc.value) = Rte_DiagMgr_DiagStsCtrldDisRmpPres_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ePWM2_ePWM2_Per1.Rte_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc.value) = Rte_DiagMgr_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ePWM2_ePWM2_Per1.Rte_RampDwnStatusComplete_Cnt_lgc.value) = Rte_StOpCtrl_SysStReqDi_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_ePWM2_ePWM2_Per1_Start();
  ePWM2_Per1();
  Rte_Runnable_Ap_ePWM2_ePWM2_Per1_Return();

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_2ms_10_Rte_Trigger1_Ap_TqRsDg_TqRsDg_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TqRsDg_TqRsDg_Per1.Rte_DervLambdaAlphaDiag_Volt_f32.value) = Rte_Ap_TqRsDg_DervLambdaAlphaDiag_Volt_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TqRsDg_TqRsDg_Per1.Rte_DervLambdaBetaDiag_Volt_f32.value) = Rte_Ap_TqRsDg_DervLambdaBetaDiag_Volt_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TqRsDg_TqRsDg_Per1.Rte_OutputRampMult_Uls_f32.value) = Rte_Ap_LmtCod_OutputRampMultLtd_Uls_f32;
    *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TqRsDg_TqRsDg_Per1.Rte_TrqLimitMin_MtrNm_f32.value) = Rte_Ap_AstLmt_TrqLimitMin_MtrNm_f32;

    /* call runnable */
    Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Start();
    TqRsDg_Per1();
    Rte_Runnable_Ap_TqRsDg_TqRsDg_Per1_Return();

    /* write implicit data */
    Rte_Ap_TqRsDg_MtrCurrIdptSig_Cnt_u08 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TqRsDg_TqRsDg_Per1.Rte_MtrCurrIdptSig_Cnt_u08.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_TranlDampg_CRFMtrTrqCmd_MtrNm_f32.value) = Rte_Ap_TranlDampg_CRFMtrTrqCmd_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_ComplErr_ComplErr_Per1_Start();
  ComplErr_Per1();
  Rte_Runnable_Ap_ComplErr_ComplErr_Per1_Return();

  /* write implicit data */
  Rte_ComplErr_ComplErr_HwDeg_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ComplErr_ComplErr_Per1.Rte_ComplErr_HwDeg_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_VehDyn_VehDyn_Per1.Rte_CcwEOT_HwDeg_f32.value) = Rte_Ap_LrnEOT_CCWPosition_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_VehDyn_VehDyn_Per1.Rte_CwEOT_HwDeg_f32.value) = Rte_Ap_LrnEOT_CWPosition_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_VehDyn_VehDyn_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_VehDyn_VehDyn_Per1.Rte_MotorVelCRF_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_VehDyn_VehDyn_Per1.Rte_RelHwPos_HwDeg_f32.value) = Rte_AbsHwPos_RelHwPos_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_VehDyn_VehDyn_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_VehDyn_VehDyn_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value) = Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_VehDyn_VehDyn_Per1_Start();
  VehDyn_Per1();
  Rte_Runnable_Ap_VehDyn_VehDyn_Per1_Return();

  /* write implicit data */
  Rte_VehDyn_SensorlessAuthority_Uls_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_VehDyn_SensorlessAuthority_Uls_f32.value);
  Rte_VehDyn_SensorlessHwPos_HwDeg_f32 = *(&Rte_Task_2ms_10.Rte_TB.Rte_I_VehDyn_SensorlessHwPos_HwDeg_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SASPlausDiag_SASPlausDiag_Per1.Rte_I2CHwAbsPos_HwDeg_f32.value) = Rte_DigColPs_I2CHwAbsPos_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SASPlausDiag_SASPlausDiag_Per1.Rte_I2CHwAbsPosValid_Cnt_lgc.value) = Rte_DigColPs_I2CHwAbsPosValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_SASPlausDiag_SASPlausDiag_Per1_Start();
  SASPlausDiag_Per1();
  Rte_Runnable_Ap_SASPlausDiag_SASPlausDiag_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_GenPosTraj_GenPosTraj_Per1.Rte_HwPosition_HwDeg_f32.value) = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_GenPosTraj_GenPosTraj_Per1.Rte_PosTrajEnable_Cnt_lgc.value) = Rte_CDDInterface_PosTrajEnable_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_GenPosTraj_GenPosTraj_Per1_Start();
  GenPosTraj_Per1();
  Rte_Runnable_Ap_GenPosTraj_GenPosTraj_Per1_Return();

  /* write implicit data */
  Rte_Ap_GenPosTraj_PosTrajHwAngle_HwDeg_f32 = *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_GenPosTraj_GenPosTraj_Per1.Rte_PosTrajHwAngle_HwDeg_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Start();
  DiagMgr_Per1();
  Rte_Runnable_Ap_DiagMgr10_DiagMgr_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per4.Rte_Ivtr1Inactv_Cnt_lgc.value) = Rte_DiagMgr_DiagStsInverter1Inactive_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per4.Rte_Ivtr2Inactv_Cnt_lgc.value) = Rte_DiagMgr_DiagStsInverter2Inactive_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per4_Start();
  TmplMonrDualIvtr_Per4();
  Rte_Runnable_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Per4_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StaMd_StaMd_Per1.Rte_ATerm_Cnt_lgc.value) = Rte_VehPwrMd_ATermActive_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StaMd_StaMd_Per1.Rte_CTerm_Cnt_lgc.value) = Rte_VehPwrMd_CTermActive_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StaMd_StaMd_Per1.Rte_ControlledDampStatusComplete_Cnt_lgc.value) = Rte_Ap_TranlDampg_CntrlDampComp_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StaMd_StaMd_Per1.Rte_FTerm_Cnt_lgc.value) = Rte_DiagMgr_DiagRmpToZeroActive_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StaMd_StaMd_Per1.Rte_RampStatusComplete_Cnt_lgc.value) = Rte_StOpCtrl_SysStReqDi_Cnt_lgc;
  *(&Rte_Task_2ms_10.Rte_RB.Rte_Ap_StaMd_StaMd_Per1.Rte_TMFTestComplete_Cnt_lgc.value) = Rte_Sa_TmplMonrDualIvtr_TMFTestComplete_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_StaMd_StaMd_Per1_Start();
  StaMd_Per1();
  Rte_Runnable_Ap_StaMd_StaMd_Per1_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_2msEnd_Per_Start();
  ChkPtAp10_2msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_2msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_2ms_8
 * Priority: 61
 * Schedule: FULL
 * Alarm:    Cycle Time 0.002 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_2ms_8)
{
  Rte_Task_Dispatch(Task_2ms_8);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_2msStart_Per_Start();
  ChkPtAp8_2msStart_Per();
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_2msStart_Per_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StaMd8_StaMd8_Per1.Rte_ATerm_Cnt_lgc.value) = Rte_VehPwrMd_ATermActive_Cnt_lgc;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StaMd8_StaMd8_Per1.Rte_CTerm_Cnt_lgc.value) = Rte_VehPwrMd_CTermActive_Cnt_lgc;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StaMd8_StaMd8_Per1.Rte_ControlledDampStatusComplete_Cnt_lgc.value) = Rte_Ap_TranlDampg_CntrlDampComp_Cnt_lgc;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StaMd8_StaMd8_Per1.Rte_FTerm_Cnt_lgc.value) = Rte_DiagMgr_DiagRmpToZeroActive_Cnt_lgc;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StaMd8_StaMd8_Per1.Rte_RampStatusComplete_Cnt_lgc.value) = Rte_StOpCtrl_SysStReqDi_Cnt_lgc;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StaMd8_StaMd8_Per1.Rte_TMFTestComplete_Cnt_lgc.value) = Rte_Sa_TmplMonrDualIvtr_TMFTestComplete_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Start();
  StaMd8_Per1();
  Rte_Runnable_Ap_StaMd8_StaMd8_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StabilityComp2_StabilityComp2_Per1.Rte_AssistDDFactor_Uls_f32.value) = Rte_Ap_TrqArblim_AssistDDFactor_Uls_f32;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StabilityComp2_StabilityComp2_Per1.Rte_AsstFWActive_Uls_f32.value) = Rte_Ap_AssistFirewall_AsstFirewallActive_Uls_f32;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StabilityComp2_StabilityComp2_Per1.Rte_CombinedAssist_MtrNm_f32.value) = Rte_Ap_AssistFirewall_CombinedAssist_MtrNm_f32;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StabilityComp2_StabilityComp2_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StabilityComp2_StabilityComp2_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Start();
  StabilityComp2_Per1();
  Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Per1_Return();

  /* write implicit data */
  Rte_Ap_StabilityComp2_SysAssistCmd_MtrNm_f32 = *(&Rte_Task_2ms_8.Rte_RB.Rte_Ap_StabilityComp2_StabilityComp2_Per1.Rte_SysAssistCmd_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per1.Rte_AsstAssemblyPolarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_AssiMechPolarity_Cnt_s08;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per1.Rte_CumMechMtrPosMRF_Deg_f32.value) = Rte_Ap_MotPosnCmp_MotPosnCumvAlgndMrf_Deg_f32;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per1.Rte_MechMtrPos1Timestamp_USec_u32.value) = Rte_CDDInterface_MotMeclPosn1MeasdTi_USec_u32;

  /* call runnable */
  Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Start();
  MtrVel2_Per1();
  Rte_Runnable_Sa_MtrVel2_MtrVel2_Per1_Return();

  /* write implicit data */
  Rte_Sa_MtrVel2_SysCDiagHwVel_HwRadpS_f32 = *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per1.Rte_SysCDiagHwVel_HwRadpS_f32.value);
  Rte_Sa_MtrVel2_SysCDiagMtrVelMRF_MtrRadpS_f32 = *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per1.Rte_SysCDiagMtrVelMRF_MtrRadpS_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per2.Rte_HandwheelVel_HwRadpS_f32.value) = Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32;
  *(&Rte_Task_2ms_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Per2.Rte_MotorVelMRF_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32;

  /* call runnable */
  Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Start();
  MtrVel2_Per2();
  Rte_Runnable_Sa_MtrVel2_MtrVel2_Per2_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_2msEnd_Per_Start();
  ChkPtAp8_2msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp8_ChkPtAp8_2msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_2ms_9
 * Priority: 60
 * Schedule: FULL
 * Alarm:    Cycle Time 0.002 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_2ms_9)
{
  Rte_Task_Dispatch(Task_2ms_9);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_2msStart_Per_Start();
  ChkPtAp9_2msStart_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_2msStart_Per_Return();

  DisableAllInterrupts();
  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_BattVltgCorrln_BattVltgCorrln_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_BattVltg_Volt_f32.value) = Rte_IoHwAbstractionUsr_Batt_Volt_f32;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_BattVltgSwd1_Volt_f32.value) = Rte_IoHwAbstractionUsr_BattSwitched1_Volt_f32;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_BattVltgSwd2_Volt_f32.value) = Rte_IoHwAbstractionUsr_BattSwitched2_Volt_f32;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_DiagcStsIvtr1Inactv_Cnt_lgc.value) = Rte_DiagMgr_DiagStsInverter1Inactive_Cnt_lgc;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_DiagcStsIvtr2Inactv_Cnt_lgc.value) = Rte_DiagMgr_DiagStsInverter2Inactive_Cnt_lgc;

    /* call runnable */
    Rte_Runnable_Ap_BattVltgCorrln_BattVltgCorrln_Per1_Start();
    BattVltgCorrln_Per1();
    Rte_Runnable_Ap_BattVltgCorrln_BattVltgCorrln_Per1_Return();

    /* write implicit data */
    Rte_Ap_BattVltgCorrln_BattSwdVltgCorrlnSts_Cnt_u08 = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_BattSwdVltgCorrlnSts_Cnt_u08.value);
    Rte_Ap_BattVltgCorrln_BattVltgCorrlnIdptSig_Cnt_u08 = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_BattVltgCorrlnIdptSig_Cnt_u08.value);
    Rte_Ap_BattVltgCorrln_DftBrdgVltgActv_Cnt_lgc = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_DftBrdgVltgActv_Cnt_lgc.value);
    Rte_Ap_BattVltgCorrln_SwdVltgLimd_Cnt_lgc = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_SwdVltgLimd_Cnt_lgc.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  DisableAllInterrupts();
  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per1 == 0)
  {
    EnableAllInterrupts();
    /* read implicit data */
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_DisableLearning_Cnt_lgc.value) = Rte_CDDInterface_PullCompLrnSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_DisableOutput_Cnt_lgc.value) = Rte_CDDInterface_PullCompSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_EstLatAcc_MpSecSq_f32.value) = Rte_Ap_SignlCondn_EstimdLatAcce_MpSecSq_f32;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_HandwheelAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_HandwheelPosition_HwDeg_f32.value) = Rte_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_HandwheelVelocity_HwRadpS_f32.value) = Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpCustLrngDi_Cnt_lgc.value) = Rte_Ap_TrqArblim_PullCmpCustLrngDi_Cnt_lgc;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpEna_Cnt_lgc.value) = Rte_CDDInterface_FeatureControl_Cnt_lgc;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpShoTermIntgtrStOffs_HwNm_f32.value) = Rte_Ap_ActivePull_PullCmpShoTermIntgtrStOffs_HwNm_f32;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value) = Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_VehicleYawRate_DegpS_f32.value) = Rte_Ap_SnsrOffsCorrn_YawRateCorrd_DegpS_f32;

    /* call runnable */
    Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Start();
    ActivePull_Per1();
    Rte_Runnable_Ap_ActivePull_ActivePull_Per1_Return();

    /* write implicit data */
    Rte_Ap_ActivePull_PullCmpShoTermIntgtrSt_HwNm_f32 = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per1.Rte_PullCmpShoTermIntgtrSt_HwNm_f32.value);
  }
  else
  {
    EnableAllInterrupts();
  }

  if (Rte_Ap_9_TriggerDisableFlags.Rte_Trigger_Task_2ms_9_Rte_Trigger1_Ap_ActivePull_ActivePull_Per2 == 0)
  {
    /* read implicit data */
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_DisableOutput_Cnt_lgc.value) = Rte_CDDInterface_PullCompSrlComSvcDft_Cnt_lgc;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCmpEna_Cnt_lgc.value) = Rte_CDDInterface_FeatureControl_Cnt_lgc;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCmpLongTermIntgtrStOffs_HwNm_f32.value) = Rte_Ap_ActivePull_PullCmpLongTermIntgtrStOffs_HwNm_f32;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCmpShoTermIntgtrStOffs_HwNm_f32.value) = Rte_Ap_ActivePull_PullCmpShoTermIntgtrStOffs_HwNm_f32;
    *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

    /* call runnable */
    Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Start();
    ActivePull_Per2();
    Rte_Runnable_Ap_ActivePull_ActivePull_Per2_Return();

    /* write implicit data */
    Rte_Ap_ActivePull_PullCompCmd_MtrNm_f32 = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_ActivePull_ActivePull_Per2.Rte_PullCompCmd_MtrNm_f32.value);
  }

  /* read implicit data */
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehSpdLmt_VehSpdLmt_Per1.Rte_CCWPosition_HwDeg_f32.value) = Rte_Ap_LrnEOT_CCWPosition_HwDeg_f32;
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehSpdLmt_VehSpdLmt_Per1.Rte_CWPosition_HwDeg_f32.value) = Rte_Ap_LrnEOT_CWPosition_HwDeg_f32;
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehSpdLmt_VehSpdLmt_Per1.Rte_HwPos_HwDeg_f32.value) = Rte_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32;
  *(&Rte_Task_2ms_9.Rte_TB.Rte_I_AbsHwPos_HandwheelAuthority_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
  *(&Rte_Task_2ms_9.Rte_TB.Rte_I_Ap_SignlCondn_VehicleSpeed_Kph_f32.value) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;

  /* call runnable */
  Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Start();
  VehSpdLmt_Per1();
  Rte_Runnable_Ap_VehSpdLmt_VehSpdLmt_Per1_Return();

  /* write implicit data */
  Rte_VehSpdLmt_AstVehSpdLimit_MtrNm_f32 = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehSpdLmt_VehSpdLmt_Per1.Rte_AstVehSpdLimit_MtrNm_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CtrlTemp_CtrlTemp_Per1.Rte_DiagStsTempRdPrf_Cnt_lgc.value) = Rte_DiagMgr_DiagStsDefTemp_Cnt_lgc;
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CtrlTemp_CtrlTemp_Per1.Rte_TemperatureADC_Volt_f32.value) = Rte_IoHwAbstractionUsr_TemperatureADC_Volt_f32;

  /* call runnable */
  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Start();
  CtrlTemp_Per1();
  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Per1_Return();

  /* write implicit data */
  Rte_CtrlTemp_FiltMeasTemp_DegC_f32 = *(&Rte_Task_2ms_9.Rte_RB.Rte_Sa_CtrlTemp_CtrlTemp_Per1.Rte_FiltMeasTemp_DegC_f32.value);

  /* read implicit data */
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_HiLoadStall_HiLoadStall_Per1.Rte_DftStallLimit_Cnt_lgc.value) = Rte_CDDInterface_EOTThermalSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2ms_9.Rte_TB.Rte_I_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32.value) = Rte_Sa_MtrVel_MotorVelCRF_MtrRadpS_f32;
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_HiLoadStall_HiLoadStall_Per1.Rte_PreLimitForStall_MtrNm_f32.value) = Rte_Ap_AstLmt_PreLimitForStall_MtrNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Start();
  HiLoadStall_Per1();
  Rte_Runnable_Ap_HiLoadStall_HiLoadStall_Per1_Return();

  /* write implicit data */
  Rte_HiLoadStall_AssistStallLimit_MtrNm_f32 = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_HiLoadStall_HiLoadStall_Per1.Rte_AssistStallLimit_MtrNm_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Start();
  StaMd9_Per1();
  Rte_Runnable_Ap_StaMd9_StaMd9_Per1_Return();

  /* call runnable */
  Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Start();
  SrlComInput_Per1();
  Rte_Runnable_Ap_SrlComInput_SrlComInput_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_EngONSrlComSvcDft_Cnt_lgc.value) = Rte_CDDInterface_EngONSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_HwTrq_HwNm_f32.value) = Rte_Ap_Sweep_OutputHwTrq_HwNm_f32;
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_SrlComEngOn_Cnt_lgc.value) = Rte_SrlComInput_SrlComEngOn_Cnt_lgc;
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_SrlComSPMOn_Cnt_lgc.value) = Rte_SrlComInput_SrlComSPMOn_Cnt_lgc;
  *(&Rte_Task_2ms_9.Rte_TB.Rte_I_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc.value) = Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Start();
  VehPwrMd_Per1();
  Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Per1_Return();

  /* write implicit data */
  Rte_VehPwrMd_ATermActive_Cnt_lgc = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_ATermActive_Cnt_lgc.value);
  Rte_VehPwrMd_CTermActive_Cnt_lgc = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_CTermActive_Cnt_lgc.value);
  Rte_VehPwrMd_DftVehSpdEna_Cnt_lgc = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_DftVehSpdEna_Cnt_lgc.value);
  Rte_VehPwrMd_OperRampRate_XpmS_f32 = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_OperRampRate_XpmS_f32.value);
  Rte_VehPwrMd_OperRampValue_Uls_f32 = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_OperRampValue_Uls_f32.value);
  Rte_VehPwrMd_SysOperMotTqCmdSca_Uls_f32 = *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Per1.Rte_SysOperMotTqCmdSca_Uls_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_FltInjection_FltInjection_Per1_Start();
  FltInjection_Per1();
  Rte_Runnable_Ap_FltInjection_FltInjection_Per1_Return();

  /* read implicit data */
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per1.Rte_HandwheelPosition_HwDeg_f32.value) = Rte_AbsHwPos_HandwheelPosition_HwDeg_f32;
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per1.Rte_HandwheelVelocity_HwRadpS_f32.value) = Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32;
  *(&Rte_Task_2ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per1.Rte_HwTorque_HwNm_f32.value) = Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32;

  /* call runnable */
  Rte_Runnable_Ap_SnsrOffsLrng_SnsrOffsLrng_Per1_Start();
  SnsrOffsLrng_Per1();
  Rte_Runnable_Ap_SnsrOffsLrng_SnsrOffsLrng_Per1_Return();

  /* call runnable */
  Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Start();
  DAQ_2msTL();
  Rte_Runnable_Ap_ApXcp_DAQ_2msTL_Return();

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_2msEnd_Per_Start();
  ChkPtAp9_2msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp9_ChkPtAp9_2msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_4ms_10
 * Priority: 52
 * Schedule: FULL
 * Alarm:    Cycle Time 0.004 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_4ms_10)
{
  Rte_Task_Dispatch(Task_4ms_10);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_4msStart_Per_Start();
  ChkPtAp10_4msStart_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_4msStart_Per_Return();

  /* read implicit data */
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Sa_DigColPs_DigColPs_Per2.Rte_MecState_Cnt_enum.value) = Rte_CDDInterface_MEC_Cnt_enum;

  /* call runnable */
  Rte_Runnable_Sa_DigColPs_DigColPs_Per2_Start();
  DigColPs_Per2();
  Rte_Runnable_Sa_DigColPs_DigColPs_Per2_Return();

  /* write implicit data */
  Rte_DigColPs_I2CHwAbsPos_HwDeg_f32 = *(&Rte_Task_4ms_10.Rte_TB.Rte_I_DigColPs_I2CHwAbsPos_HwDeg_f32.value);
  Rte_DigColPs_I2CHwAbsPosValid_Cnt_lgc = *(&Rte_Task_4ms_10.Rte_TB.Rte_I_DigColPs_I2CHwAbsPosValid_Cnt_lgc.value);
  Rte_DigColPs_TrimComp_Cnt_lgc = *(&Rte_Task_4ms_10.Rte_RB.Rte_Sa_DigColPs_DigColPs_Per2.Rte_TrimComp_Cnt_lgc.value);

  /* read implicit data */
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Sa_HwTqCorrln_HwTqCorrln_Per2.Rte_ArbnAbsTqErr_HwNm_f32.value) = Rte_Sa_HwTrqArbn_ArbnAbsHwTqErr_HwNm_f32;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Sa_HwTqCorrln_HwTqCorrln_Per2.Rte_HwTq1Val_HwNm_f32.value) = Rte_Sa_AnaHwTrq_HwTq1Val_HwNm_f32;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Sa_HwTqCorrln_HwTqCorrln_Per2.Rte_HwTq2Val_HwNm_f32.value) = Rte_Sa_AnaHwTrq_HwTq2Val_HwNm_f32;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Sa_HwTqCorrln_HwTqCorrln_Per2.Rte_HwTq3Val_HwNm_f32.value) = Rte_Cd_Nhet1CfgAndUse_HwTq3Val_HwNm_f32;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Sa_HwTqCorrln_HwTqCorrln_Per2.Rte_HwTq4Val_HwNm_f32.value) = Rte_Cd_Nhet1CfgAndUse_HwTq4Val_HwNm_f32;

  /* call runnable */
  Rte_Runnable_Sa_HwTqCorrln_HwTqCorrln_Per2_Start();
  HwTqCorrln_Per2();
  Rte_Runnable_Sa_HwTqCorrln_HwTqCorrln_Per2_Return();

  /* write implicit data */
  Rte_Sa_HwTqCorrln_HwTqIdptSig_Cnt_u08 = *(&Rte_Task_4ms_10.Rte_RB.Rte_Sa_HwTqCorrln_HwTqCorrln_Per2.Rte_HwTqIdptSig_Cnt_u08.value);
  Rte_Sa_HwTqCorrln_HwTqVldSrcSig_Cnt_u08 = *(&Rte_Task_4ms_10.Rte_RB.Rte_Sa_HwTqCorrln_HwTqCorrln_Per2.Rte_HwTqVldSrcSig_Cnt_u08.value);

  /* call runnable */
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Per3_Start();
  AbsHwPos_Per3();
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Per3_Return();

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Start();
  uDiagLossOfExec_Per3();
  Rte_Runnable_Cd_uDiag_uDiagLossOfExec_Per3_Return();

  DisableAllInterrupts();
  if (Rte_Ap_10_TriggerDisableFlags.Rte_Trigger_Task_4ms_10_Rte_Trigger1_Ap_WhlImbRej_WhlImbRej_Per2 == 0)
  {
    EnableAllInterrupts();
    /* call runnable */
    Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Start();
    WhlImbRej_Per2();
    Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Per2_Return();
  }
  else
  {
    EnableAllInterrupts();
  }

  /* read implicit data */
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_DiagcStsIvtr1Inactv_Cnt_lgc.value) = Rte_DiagMgr_DiagStsInverter1Inactive_Cnt_lgc;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_DiagcStsIvtr2Inactv_Cnt_lgc.value) = Rte_DiagMgr_DiagStsInverter2Inactive_Cnt_lgc;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_HwTqIdptSig_Cnt_u08.value) = Rte_Sa_HwTqCorrln_HwTqIdptSig_Cnt_u08;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_LoaScaDi_Cnt_lgc.value) = Rte_CDDInterface_MfgDiagInhibit_Cnt_lgc;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_MotCurrIdptSig_Cnt_u08.value) = Rte_Sa_CmMtrCurr3Phs_MtrCurrIdptSig_Cnt_u08;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_MtrPosIdptSig_Cnt_u08.value) = Rte_Ap_MotAgCorrln_MtrPosIdptSig_Cnt_u08;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_SteerMod_Cnt_enum.value) = Rte_Ap_LoaMgr_SteerMod_Cnt_enum;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_TloaAvail_Cnt_lgc.value) = Rte_Ap_TrqLOA_TrqLOAAvail_Cnt_lgc;
  *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_TloaDi_Cnt_lgc.value) = Rte_Ap_LoaMgr_TloaDi_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_LoaMgr_LoaMgr_Per1_Start();
  LoaMgr_Per1();
  Rte_Runnable_Ap_LoaMgr_LoaMgr_Per1_Return();

  /* write implicit data */
  Rte_Ap_LoaMgr_HwTqLoaMtgtnEn_Cnt_lgc = *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_HwTqLoaMtgtnEn_Cnt_lgc.value);
  Rte_Ap_LoaMgr_IvtrLoaMtgtnEn_Cnt_lgc = *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_IvtrLoaMtgtnEn_Cnt_lgc.value);
  Rte_Ap_LoaMgr_LOASt_State_enum = *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_LOASt_State_enum.value);
  Rte_Ap_LoaMgr_LoaRateLimit_UlspS_f32 = *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_LoaRateLimit_UlspS_f32.value);
  Rte_Ap_LoaMgr_LoaScaleFctr_Uls_f32 = *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_LoaScaleFctr_Uls_f32.value);
  Rte_Ap_LoaMgr_MotAgLoaMtgtnEn_Cnt_lgc = *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_MotAgLoaMtgtnEn_Cnt_lgc.value);
  Rte_Ap_LoaMgr_MotCurrLoaMtgtnEn_Cnt_lgc = *(&Rte_Task_4ms_10.Rte_RB.Rte_Ap_LoaMgr_LoaMgr_Per1.Rte_MotCurrLoaMtgtnEn_Cnt_lgc.value);

  /* call runnable */
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_4msEnd_Per_Start();
  ChkPtAp10_4msEnd_Per();
  Rte_Runnable_Ap_ChkPtAp10_ChkPtAp10_4msEnd_Per_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_Init_10
 * Priority: 72
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Init_10)
{
  Rte_Task_Dispatch(Task_Init_10);

  /* call runnable */
  Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Start();
  CDDInterface_Init1();
  Rte_Runnable_Sa_CDDInterface_CDDInterface_Init1_Return();

  /* write implicit data */
  Rte_CDDInterface_IgnCnt_Cnt_u16 = *(&Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Init1.Rte_IgnCnt_Cnt_u16.value);

  /* read implicit data */
  *(&Rte_Task_Init_10.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Init1.Rte_DesiredTunPers_Cnt_u16.value) = Rte_SrlComInput_DesiredTunPers_Cnt_u16;
  *(&Rte_Task_Init_10.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Init1.Rte_DesiredTunSet_Cnt_u16.value) = Rte_CDDInterface_MotorVariant_Cnt_u16;

  /* call runnable */
  Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Start();
  TuningSelAuth_Init1();
  Rte_Runnable_Ap_TuningSelAuth_TuningSelAuth_Init1_Return();

  /* write implicit data */
  Rte_Ap_TuningSelAuth_ActiveTunPers_Cnt_u16 = *(&Rte_Task_Init_10.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Init1.Rte_ActiveTunPers_Cnt_u16.value);
  Rte_Ap_TuningSelAuth_ActiveTunSet_Cnt_u16 = *(&Rte_Task_Init_10.Rte_RB.Rte_Ap_TuningSelAuth_TuningSelAuth_Init1.Rte_ActiveTunSet_Cnt_u16.value);

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Start();
  DiagMgr10_Init();
  Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_StaMd_StaMd_Init1_Start();
  StaMd_Init1();
  Rte_Runnable_Ap_StaMd_StaMd_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_CtrlPolarityBrshlss_Polarity_Init1_Start();
  Polarity_Init1();
  Rte_Runnable_Ap_CtrlPolarityBrshlss_Polarity_Init1_Return();

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Start();
  uDiagResetHandler_Init();
  Rte_Runnable_Cd_uDiag_uDiagResetHandler_Init_Return();

  /* call runnable */
  Rte_Runnable_Cd_uDiag_uDiagPeriphStartup_Init_Start();
  uDiagPeriphStartup_Init();
  Rte_Runnable_Cd_uDiag_uDiagPeriphStartup_Init_Return();

  /* call runnable */
  Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Start();
  IoHwAb_Init();
  Rte_Runnable_IoHwAbstractionUsr_IoHwAb_Init_Return();

  /* write implicit data */
  Rte_IoHwAbstractionUsr_Batt_Volt_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_Init.Rte_Batt_Volt_f32.value);
  Rte_IoHwAbstractionUsr_BattSwitched1_Volt_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_Init.Rte_BattSwitched1_Volt_f32.value);
  Rte_IoHwAbstractionUsr_BattSwitched2_Volt_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_Init.Rte_BattSwitched2_Volt_f32.value);
  Rte_IoHwAbstractionUsr_MtrPos3Con_Volt_u3p13 = *(&Rte_Task_Init_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_Init.Rte_MtrPos3Con_Volt_u3p13.value);
  Rte_IoHwAbstractionUsr_MtrPos3Sin_Volt_u3p13 = *(&Rte_Task_Init_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_Init.Rte_MtrPos3Sin_Volt_u3p13.value);
  Rte_IoHwAbstractionUsr_T1ADC_Volt_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_Init.Rte_T1ADC_Volt_f32.value);
  Rte_IoHwAbstractionUsr_T2ADC_Volt_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_Init.Rte_T2ADC_Volt_f32.value);
  Rte_IoHwAbstractionUsr_TemperatureADC_Volt_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_Init.Rte_TemperatureADC_Volt_f32.value);
  Rte_IoHwAbstractionUsr_Vref3p3_Volt_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_Init.Rte_Vref3p3_Volt_f32.value);
  Rte_IoHwAbstractionUsr_Vref5vp1_Volt_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_Init.Rte_Vref5vp1_Volt_f32.value);
  Rte_IoHwAbstractionUsr_Vref5vp2_Volt_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_IoHwAbstractionUsr_IoHwAb_Init.Rte_Vref5vp2_Volt_f32.value);

  /* call runnable */
  Rte_Runnable_Sa_MotMeclPosn1_MotMeclPosn1_Init_Start();
  MotMeclPosn1_Init();
  Rte_Runnable_Sa_MotMeclPosn1_MotMeclPosn1_Init_Return();

  /* call runnable */
  Rte_Runnable_Sa_MotMeclPosn2_MotMeclPosn2_Init_Start();
  MotMeclPosn2_Init();
  Rte_Runnable_Sa_MotMeclPosn2_MotMeclPosn2_Init_Return();

  /* call runnable */
  Rte_Runnable_Sa_MtrPos3SinCos_MtrPos3SinCos_Init_Start();
  MtrPos3SinCos_Init();
  Rte_Runnable_Sa_MtrPos3SinCos_MtrPos3SinCos_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_MotAgCorrln_MotAgCorrln_Init_Start();
  MotAgCorrln_Init();
  Rte_Runnable_Ap_MotAgCorrln_MotAgCorrln_Init_Return();

  /* call runnable */
  Rte_Runnable_Sa_MtrVel_MtrVel_Init_Start();
  MtrVel_Init();
  Rte_Runnable_Sa_MtrVel_MtrVel_Init_Return();

  /* call runnable */
  Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Start();
  MtrVel3_Init();
  Rte_Runnable_Sa_MtrVel3_MtrVel3_Init_Return();

  /* call runnable */
  Rte_Runnable_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Init_Start();
  CmMtrCurr3Phs_Init();
  Rte_Runnable_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_TranlDampg_Ap_TranlDampg_Init_Start();
  Ap_TranlDampg_Init();
  Rte_Runnable_Ap_TranlDampg_Ap_TranlDampg_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Start();
  CurrCmd_Init();
  Rte_Runnable_Ap_CurrCmd_CurrCmd_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Start();
  CurrParamComp_Init();
  Rte_Runnable_Ap_CurrParamComp_CurrParamComp_Init_Return();

  /* write implicit data */
  Rte_CurrParamComp_EstKe_VpRadpS_f32 = *(&Rte_Task_Init_10.Rte_TB.Rte_I_CurrParamComp_EstKe_VpRadpS_f32.value);
  Rte_CurrParamComp_EstLd_Henry_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Init.Rte_EstLd_Henry_f32.value);
  Rte_CurrParamComp_EstLq_Henry_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Init.Rte_EstLq_Henry_f32.value);
  Rte_CurrParamComp_EstR_Ohm_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_Ap_CurrParamComp_CurrParamComp_Init.Rte_EstR_Ohm_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Start();
  TrqCanc_Init();
  Rte_Runnable_Ap_TrqCanc_TrqCanc_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Init_Start();
  PICurrCntrl_Init();
  Rte_Runnable_Ap_PICurrCntrl_PICurrCntrl_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_HystComp_HystComp_Init1_Start();
  HystComp_Init1();
  Rte_Runnable_Ap_HystComp_HystComp_Init1_Return();

  /* call runnable */
  Rte_Runnable_Sa_AnaHwTrq_AnaHwTrq_Init_Start();
  AnaHwTrq_Init();
  Rte_Runnable_Sa_AnaHwTrq_AnaHwTrq_Init_Return();

  /* write implicit data */
  Rte_Sa_AnaHwTrq_HwTq1Qlfr_State_enum = *(&Rte_Task_Init_10.Rte_RB.Rte_Sa_AnaHwTrq_AnaHwTrq_Init.Rte_HwTq1Qlfr_State_enum.value);
  Rte_Sa_AnaHwTrq_HwTq1RollgCntr_Cnt_u08 = *(&Rte_Task_Init_10.Rte_RB.Rte_Sa_AnaHwTrq_AnaHwTrq_Init.Rte_HwTq1RollgCntr_Cnt_u08.value);
  Rte_Sa_AnaHwTrq_HwTq2Qlfr_State_enum = *(&Rte_Task_Init_10.Rte_RB.Rte_Sa_AnaHwTrq_AnaHwTrq_Init.Rte_HwTq2Qlfr_State_enum.value);
  Rte_Sa_AnaHwTrq_HwTq2RollgCntr_Cnt_u08 = *(&Rte_Task_Init_10.Rte_RB.Rte_Sa_AnaHwTrq_AnaHwTrq_Init.Rte_HwTq2RollgCntr_Cnt_u08.value);

  /* call runnable */
  Rte_Runnable_Sa_HwTqCorrln_HwTqCorrln_Init1_Start();
  HwTqCorrln_Init1();
  Rte_Runnable_Sa_HwTqCorrln_HwTqCorrln_Init1_Return();

  /* call runnable */
  Rte_Runnable_Sa_HwTrqArbn_HwTrqArbn_Init_Start();
  HwTrqArbn_Init();
  Rte_Runnable_Sa_HwTrqArbn_HwTrqArbn_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_TrqLOA_TrqLOA_Init1_Start();
  TrqLOA_Init1();
  Rte_Runnable_Ap_TrqLOA_TrqLOA_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Start();
  FrqDepDmpnInrtCmp_Init();
  Rte_Runnable_Ap_FrqDepDmpnInrtCmp_FrqDepDmpnInrtCmp_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_Damping_Damping_Init1_Start();
  Damping_Init1();
  Rte_Runnable_Ap_Damping_Damping_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Start();
  PwrLmtFuncCr_Init1();
  Rte_Runnable_Ap_PwrLmtFuncCr_PwrLmtFuncCr_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Start();
  TqRsDg_Init1();
  Rte_Runnable_Ap_TqRsDg_TqRsDg_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Start();
  StabilityComp_Init1();
  Rte_Runnable_Ap_StabilityComp_StabilityComp_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_GMStrtStop_StrtStop_Init1_Start();
  StrtStop_Init1();
  Rte_Runnable_Ap_GMStrtStop_StrtStop_Init1_Return();

  /* call runnable */
  Rte_Runnable_CtrldVelRtn_CtrldVelRtn_Init1_Start();
  CtrldVelRtn_Init1();
  Rte_Runnable_CtrldVelRtn_CtrldVelRtn_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_SignlCondn_SignlCondn_Init1_Start();
  SignlCondn_Init1();
  Rte_Runnable_Ap_SignlCondn_SignlCondn_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_PosServo_PosServo_Init1_Start();
  PosServo_Init1();
  Rte_Runnable_Ap_PosServo_PosServo_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_AstLmt_AstLmt_Init_Start();
  AstLmt_Init();
  Rte_Runnable_Ap_AstLmt_AstLmt_Init_Return();

  /* read implicit data */
  *(&Rte_Task_Init_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Init1.Rte_ManufMode_Cnt_enum.value) = Rte_CDDInterface_MEC_Cnt_enum;

  /* call runnable */
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Init1_Start();
  AbsHwPos_Init1();
  Rte_Runnable_Ap_AbsHwPos_AbsHwPos_Init1_Return();

  /* write implicit data */
  Rte_AbsHwPos_HwPosSource_Cnt_u16 = *(&Rte_Task_Init_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Init1.Rte_HwPosSource_Cnt_u16.value);
  Rte_AbsHwPos_SrlComHwPosStatus_Cnt_u16 = *(&Rte_Task_Init_10.Rte_RB.Rte_Ap_AbsHwPos_AbsHwPos_Init1.Rte_SrlComHwPosStatus_Cnt_u16.value);

  /* call runnable */
  Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Start();
  WhlImbRej_Init1();
  Rte_Runnable_Ap_WhlImbRej_WhlImbRej_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Start();
  DampingFirewall_Init1();
  Rte_Runnable_Ap_DampingFirewall_DampingFirewall_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_HOWDetect_HOWDetect_Init1_Start();
  HOWDetect_Init1();
  Rte_Runnable_Ap_HOWDetect_HOWDetect_Init1_Return();

  /* call runnable */
  Rte_Runnable_Sa_DigColPs_DigColPs_Init1_Start();
  DigColPs_Init1();
  Rte_Runnable_Sa_DigColPs_DigColPs_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_TSMit_TSMit_Init1_Start();
  TSMit_Init1();
  Rte_Runnable_Ap_TSMit_TSMit_Init1_Return();

  /* read implicit data */
  *(&Rte_Task_Init_10.Rte_RB.Rte_Ap_VehDyn_VehDyn_Init1.Rte_RelHwPos_HwDeg_f32.value) = Rte_AbsHwPos_RelHwPos_HwDeg_f32;

  /* call runnable */
  Rte_Runnable_Ap_VehDyn_VehDyn_Init1_Start();
  VehDyn_Init1();
  Rte_Runnable_Ap_VehDyn_VehDyn_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_TrqOsc_TrqOsc_Init_Start();
  TrqOsc_Init();
  Rte_Runnable_Ap_TrqOsc_TrqOsc_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Start();
  AssistFirewall_Init1();
  Rte_Runnable_Ap_AssistFirewall_AssistFirewall_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_Sweep_Sweep_Init_Start();
  Sweep_Init();
  Rte_Runnable_Ap_Sweep_Sweep_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_TrqArblim_TrqArblim_Init_Start();
  TrqArblim_Init();
  Rte_Runnable_Ap_TrqArblim_TrqArblim_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_TrqOvlSta_TrqOvlSta_Init_Start();
  TrqOvlSta_Init();
  Rte_Runnable_Ap_TrqOvlSta_TrqOvlSta_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_LoaMgr_LoaMgr_Init1_Start();
  LoaMgr_Init1();
  Rte_Runnable_Ap_LoaMgr_LoaMgr_Init1_Return();

  /* read implicit data */
  *(&Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Init2.Rte_MtrElecMechPolarity_Cnt_s08.value) = Rte_Ap_CtrlPolarityBrshlss_MotElecMeclPolarity_Cnt_s08;
  *(&Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Init2.Rte_MtrPosPolarity_Cnt_s08.value) = Rte_CDDInterface_MtrPosPolarity_Cnt_s08;

  /* call runnable */
  Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Start();
  CDDInterface_Init2();
  Rte_Runnable_Sa_CDDInterface_CDDInterface_Init2_Return();

  /* write implicit data */
  Rte_CDDInterface_MEC_Cnt_enum = *(&Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Init2.Rte_MEC_Cnt_enum.value);

  /* call runnable */
  Rte_Runnable_Sa_CDDInterface_CDDInterface_Init3_Start();
  CDDInterface_Init3();
  Rte_Runnable_Sa_CDDInterface_CDDInterface_Init3_Return();

  /* call runnable */
  Rte_Runnable_Cd_PhaseFdbkMeas_Cd_PhaseFdbkMeas_Init2_Start();
  Cd_PhaseFdbkMeas_Init2();
  Rte_Runnable_Cd_PhaseFdbkMeas_Cd_PhaseFdbkMeas_Init2_Return();

  /* call runnable */
  Rte_Runnable_Ap_BattVltg_BattVltg_Init1_Start();
  BattVltg_Init1();
  Rte_Runnable_Ap_BattVltg_BattVltg_Init1_Return();

  /* write implicit data */
  Rte_Ap_BattVltg_BrdgVltg_Volt_f32 = *(&Rte_Task_Init_10.Rte_RB.Rte_Ap_BattVltg_BattVltg_Init1.Rte_BrdgVltg_Volt_f32.value);

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_Init_8
 * Priority: 71
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Init_8)
{
  Rte_Task_Dispatch(Task_Init_8);

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Start();
  DiagMgr8_Init();
  Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Init_Return();

  /* read implicit data */
  *(&Rte_Task_Init_8.Rte_RB.Rte_Sa_MtrVel2_MtrVel2_Init.Rte_CumMechMtrPosMRF_Deg_f32.value) = Rte_Ap_MotPosnCmp_MotPosnCumvAlgndMrf_Deg_f32;

  /* call runnable */
  Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Start();
  MtrVel2_Init();
  Rte_Runnable_Sa_MtrVel2_MtrVel2_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Start();
  StabilityComp2_Init1();
  Rte_Runnable_Ap_StabilityComp2_StabilityComp2_Init1_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_Init_9
 * Priority: 70
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Init_9)
{
  Rte_Task_Dispatch(Task_Init_9);

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Start();
  DiagMgr9_Init();
  Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Start();
  DiagMgr_Init1();
  Rte_Runnable_Ap_DiagMgr9_DiagMgr_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Start();
  SrlComInput_Init();
  Rte_Runnable_Ap_SrlComInput_SrlComInput_Init_Return();

  /* call runnable */
  Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Start();
  SrlComOutput_Init1();
  Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Init1_Return();

  /* read implicit data */
  *(&Rte_Task_Init_9.Rte_RB.Rte_Sa_CtrlTemp_CtrlTemp_Init1.Rte_TemperatureADC_Volt_f32.value) = Rte_IoHwAbstractionUsr_TemperatureADC_Volt_f32;

  /* call runnable */
  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Start();
  CtrlTemp_Init1();
  Rte_Runnable_Sa_CtrlTemp_CtrlTemp_Init1_Return();

  /* write implicit data */
  Rte_CtrlTemp_FiltMeasTemp_DegC_f32 = *(&Rte_Task_Init_9.Rte_TB.Rte_I_CtrlTemp_FiltMeasTemp_DegC_f32.value);

  /* read implicit data */
  *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_AmbTemp_DegC_f32.value) = Rte_SrlComInput_SrlComAmbTemp_DegC_f32;
  *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_EngTemp_DegC_f32.value) = Rte_SrlComInput_SrlComEngTemp_DegC_f32;
  *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_ScomTempDataRcvd_Cnt_lgc.value) = Rte_Ap_MtrTempEst_ScomTempDataRcvd_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Start();
  MtrTempEst_Init1();
  Rte_Runnable_Ap_MtrTempEst_MtrTempEst_Init1_Return();

  /* write implicit data */
  Rte_Ap_MtrTempEst_AssistMechTempEst_DegC_f32 = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_AssistMechTempEst_DegC_f32.value);
  Rte_Ap_MtrTempEst_CuTempEst_DegC_f32 = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_CuTempEst_DegC_f32.value);
  Rte_Ap_MtrTempEst_MagTempEst_DegC_f32 = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_MagTempEst_DegC_f32.value);
  Rte_Ap_MtrTempEst_SiTempEst_DegC_f32 = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_MtrTempEst_MtrTempEst_Init1.Rte_SiTempEst_DegC_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Start();
  VehPwrMd_Init1();
  Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Init1_Return();

  /* write implicit data */
  Rte_VehPwrMd_OperRampRate_XpmS_f32 = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Init1.Rte_OperRampRate_XpmS_f32.value);
  Rte_VehPwrMd_OperRampValue_Uls_f32 = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_VehPwrMd_VehPwrMd_Init1.Rte_OperRampValue_Uls_f32.value);

  /* read implicit data */
  *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1.Rte_DefeatDutySvc_Cnt_lgc.value) = Rte_CDDInterface_ThermalDCSrlComSvcDft_Cnt_lgc;
  *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1.Rte_IgnTimeOff_Cnt_u32.value) = Rte_Ap_ThrmlDutyCycle_IgnTimeOff_Cnt_u32;
  *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1.Rte_VehTimeValid_Cnt_lgc.value) = Rte_Ap_ThrmlDutyCycle_VehTimeValid_Cnt_lgc;

  /* call runnable */
  Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Start();
  ThrmlDutyCycle_Init1();
  Rte_Runnable_Ap_ThrmlDutyCycle_ThrmlDutyCycle_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Start();
  AvgFricLrn_Init1();
  Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Init1_Return();

  /* write implicit data */
  Rte_Ap_AvgFricLrn_FricOffset_HwNm_f32 = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_AvgFricLrn_AvgFricLrn_Init1.Rte_FricOffset_HwNm_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Start();
  ActivePull_Init1();
  Rte_Runnable_Ap_ActivePull_ActivePull_Init1_Return();

  /* call runnable */
  Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Start();
  LrnEOT_Init1();
  Rte_Runnable_Ap_LrnEOT_LrnEOT_Init1_Return();

  /* write implicit data */
  Rte_Ap_LrnEOT_CCWFound_Cnt_lgc = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Init1.Rte_CCWFound_Cnt_lgc.value);
  Rte_Ap_LrnEOT_CCWPosition_HwDeg_f32 = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Init1.Rte_CCWPosition_HwDeg_f32.value);
  Rte_Ap_LrnEOT_CWFound_Cnt_lgc = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Init1.Rte_CWFound_Cnt_lgc.value);
  Rte_Ap_LrnEOT_CWPosition_HwDeg_f32 = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_LrnEOT_LrnEOT_Init1.Rte_CWPosition_HwDeg_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_SnsrOffsLrng_SnsrOffsLrng_Init1_Start();
  SnsrOffsLrng_Init1();
  Rte_Runnable_Ap_SnsrOffsLrng_SnsrOffsLrng_Init1_Return();

  /* write implicit data */
  Rte_Ap_SnsrOffsLrng_HwAgOffs_HwDeg_f32 = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Init1.Rte_HwAgOffs_HwDeg_f32.value);
  Rte_Ap_SnsrOffsLrng_HwTqOffs_HwNm_f32 = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Init1.Rte_HwTqOffs_HwNm_f32.value);
  Rte_Ap_SnsrOffsLrng_VehYawRateOffs_DegpS_f32 = *(&Rte_Task_Init_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Init1.Rte_VehYawRateOffs_DegpS_f32.value);

  /* call runnable */
  Rte_Runnable_Ap_CustPerSrvcs_CustPerSrvcs_Init1_Start();
  CustPerSrvcs_Init1();
  Rte_Runnable_Ap_CustPerSrvcs_CustPerSrvcs_Init1_Return();

  (void)TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Task_Trans_10
 * Priority: 12
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Trans_10)
{
  EventMaskType ev;

  Rte_Task_Dispatch(Task_Trans_10);

  for(;;)
  {
    Rte_Task_WaitEvent(Task_Trans_10, Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OFF | Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OPERATE | Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_WARMINIT | Rte_Ev_Run_Ap_ePWM2_ePWM2_Trns2 | Rte_Ev_Run_DiagMgr_DiagMgr10_Trns | Rte_Ev_MS_Task_Trans_10);
    (void)WaitEvent(Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OFF | Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OPERATE | Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_WARMINIT | Rte_Ev_Run_Ap_ePWM2_ePWM2_Trns2 | Rte_Ev_Run_DiagMgr_DiagMgr10_Trns | Rte_Ev_MS_Task_Trans_10);
    Rte_Task_WaitEventRet(Task_Trans_10, Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OFF | Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OPERATE | Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_WARMINIT | Rte_Ev_Run_Ap_ePWM2_ePWM2_Trns2 | Rte_Ev_Run_DiagMgr_DiagMgr10_Trns | Rte_Ev_MS_Task_Trans_10);
    (void)GetEvent(Task_Trans_10, &ev);
    (void)ClearEvent(ev & (Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_DISABLE | Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OFF | Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OPERATE | Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_WARMINIT | Rte_Ev_Run_Ap_ePWM2_ePWM2_Trns2 | Rte_Ev_Run_DiagMgr_DiagMgr10_Trns | Rte_Ev_MS_Task_Trans_10));

    if ((ev & Rte_Ev_Run_DiagMgr_DiagMgr10_Trns) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Start();
      DiagMgr10_Trns();
      Rte_Runnable_Ap_DiagMgr10_DiagMgr10_Trns_Return();
    }

    if ((ev & Rte_Ev_Run_Ap_ePWM2_ePWM2_Trns2) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Start();
      ePWM2_Trns2();
      Rte_Runnable_Ap_ePWM2_ePWM2_Trns2_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_WARMINIT) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Tans1_Start();
      TmplMonrDualIvtr_Tans1();
      Rte_Runnable_Sa_TmplMonrDualIvtr_TmplMonrDualIvtr_Tans1_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OFF) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_StaMd_StaMd_Trns1_Start();
      StaMd_Trns1();
      Rte_Runnable_Ap_StaMd_StaMd_Trns1_Return();
    }

    if (((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_DISABLE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_WARMINIT) != (EventMaskType)0))
    {
      /* call runnable */
      Rte_Runnable_Ap_GmPwrpkSrvDataRcvry_GmPwrpkSrvDataRcvry_Trns1_Start();
      GmPwrpkSrvDataRcvry_Trns1();
      Rte_Runnable_Ap_GmPwrpkSrvDataRcvry_GmPwrpkSrvDataRcvry_Trns1_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OFF) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_Task_Trans_10.Rte_RB.Rte_Ap_VehDyn_VehDyn_Trns1.Rte_HandwheelPosition_HwDeg_f32.value) = Rte_Ap_SnsrOffsCorrn_HwAgCorrd_HwDeg_f32;
      *(&Rte_Task_Trans_10.Rte_RB.Rte_Ap_VehDyn_VehDyn_Trns1.Rte_HwAuth_Uls_f32.value) = Rte_AbsHwPos_HandwheelAuthority_Uls_f32;
      *(&Rte_Task_Trans_10.Rte_RB.Rte_Ap_VehDyn_VehDyn_Trns1.Rte_MechMtrPos1_Rev_f32.value) = Rte_CDDInterface_DigMSBArbnMtrPosMecl_Rev_f32;

      /* call runnable */
      Rte_Runnable_Ap_VehDyn_VehDyn_Trns1_Start();
      VehDyn_Trns1();
      Rte_Runnable_Ap_VehDyn_VehDyn_Trns1_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OPERATE) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Start();
      ePWM2_Trns1();
      Rte_Runnable_Ap_ePWM2_ePWM2_Trns1_Return();
    }

    if (((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_DISABLE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OFF) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OPERATE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_WARMINIT) != (EventMaskType)0))
    {
      /* call runnable */
      Rte_Runnable_RteErrata10_RteErrata10_Trns_Start();
      RteErrata10_Trns();
      Rte_Runnable_RteErrata10_RteErrata10_Trns_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_WARMINIT) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Start();
      MtrDrvDiag_Trns1();
      Rte_Runnable_Sa_MtrDrvDiag_MtrDrvDiag_Trns1_Return();

      /* write implicit data */
      Rte_Sa_MtrDrvDiag_MtrDrvr1InitComplete_Cnt_lgc = *(&Rte_Task_Trans_10.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Trns1.Rte_MtrDrvr1InitComplete_Cnt_lgc.value);
      Rte_Sa_MtrDrvDiag_MtrDrvr2InitComplete_Cnt_lgc = *(&Rte_Task_Trans_10.Rte_RB.Rte_Sa_MtrDrvDiag_MtrDrvDiag_Trns1.Rte_MtrDrvr2InitComplete_Cnt_lgc.value);
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OPERATE) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Start();
      DigPhsReasDiag_Trans1();
      Rte_Runnable_Ap_DigPhsReasDiag_DigPhsReasDiag_Trans1_Return();
    }

    if (((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OPERATE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_DISABLE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_WARMINIT) != (EventMaskType)0) || ((ev & Rte_Ev_Run_Ap_ePWM2_ePWM2_Trns2) != (EventMaskType)0) || ((ev & Rte_Ev_Run_DiagMgr_DiagMgr10_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trans_10_StaMd_SystemState_Mode_OFF) != (EventMaskType)0) || ((ev & Rte_Ev_MS_Task_Trans_10) != (EventMaskType)0))
    {
      Rte_ModeType_StaMd_Mode previousMode;
      Rte_ModeType_StaMd_Mode nextMode;

      Rte_Assert((Rte_ModeMachine_StaMd_SystemState_Mode == RTE_TRANSITION_StaMd_Mode), RTE_E_INTERNAL_TransitionState);

      DisableAllInterrupts();
      previousMode = Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[1];
      nextMode = Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[0];

      if (previousMode != nextMode)
      {
        Rte_DecDisableFlags_StaMd_SystemState_Mode(previousMode);
      }

      Rte_ModeMachine_StaMd_SystemState_Mode = Rte_ModeInfo_StaMd_SystemState_Mode.Rte_ModeQueue[0];

      EnableAllInterrupts();


    }
  }
}

/**********************************************************************************************************************
 * Task:     Task_Trans_8
 * Priority: 11
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Trans_8)
{
  EventMaskType ev;

  Rte_Task_Dispatch(Task_Trans_8);

  for(;;)
  {
    Rte_Task_WaitEvent(Task_Trans_8, Rte_Ev_Run_Ap_DiagMgr8_DiagMgr8_Trns | Rte_Ev_Run_RteErrata8_RteErrata8_Trns);
    (void)WaitEvent(Rte_Ev_Run_Ap_DiagMgr8_DiagMgr8_Trns | Rte_Ev_Run_RteErrata8_RteErrata8_Trns);
    Rte_Task_WaitEventRet(Task_Trans_8, Rte_Ev_Run_Ap_DiagMgr8_DiagMgr8_Trns | Rte_Ev_Run_RteErrata8_RteErrata8_Trns);
    (void)GetEvent(Task_Trans_8, &ev);
    (void)ClearEvent(ev & (Rte_Ev_Run_Ap_DiagMgr8_DiagMgr8_Trns | Rte_Ev_Run_RteErrata8_RteErrata8_Trns));

    if ((ev & Rte_Ev_Run_Ap_DiagMgr8_DiagMgr8_Trns) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Start();
      DiagMgr8_Trns();
      Rte_Runnable_Ap_DiagMgr8_DiagMgr8_Trns_Return();
    }

    if ((ev & Rte_Ev_Run_RteErrata8_RteErrata8_Trns) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_RteErrata8_RteErrata8_Trns_Start();
      RteErrata8_Trns();
      Rte_Runnable_RteErrata8_RteErrata8_Trns_Return();
    }

    if (((ev & Rte_Ev_Run_Ap_DiagMgr8_DiagMgr8_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_Run_RteErrata8_RteErrata8_Trns) != (EventMaskType)0))
    {

      Rte_Assert((Rte_ModeMachine_Ap_StaMd8_SystemState8_Mode == RTE_TRANSITION_StaMd_Mode), RTE_E_INTERNAL_TransitionState);

      DisableAllInterrupts();

      Rte_ModeMachine_Ap_StaMd8_SystemState8_Mode = Rte_ModeInfo_Ap_StaMd8_SystemState8_Mode.Rte_ModeQueue[0];

      EnableAllInterrupts();


    }
  }
}

/**********************************************************************************************************************
 * Task:     Task_Trans_9
 * Priority: 10
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Trans_9)
{
  EventMaskType ev;

  Rte_Task_Dispatch(Task_Trans_9);

  for(;;)
  {
    Rte_Task_WaitEvent(Task_Trans_9, Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF | Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OPERATE | Rte_Ev_OnExit_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF | Rte_Ev_Run_RteErrata9_RteErrata9_Trns | Rte_Ev_MS_Task_Trans_9);
    (void)WaitEvent(Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF | Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OPERATE | Rte_Ev_OnExit_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF | Rte_Ev_Run_RteErrata9_RteErrata9_Trns | Rte_Ev_MS_Task_Trans_9);
    Rte_Task_WaitEventRet(Task_Trans_9, Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF | Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OPERATE | Rte_Ev_OnExit_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF | Rte_Ev_Run_RteErrata9_RteErrata9_Trns | Rte_Ev_MS_Task_Trans_9);
    (void)GetEvent(Task_Trans_9, &ev);
    (void)ClearEvent(ev & (Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF | Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OPERATE | Rte_Ev_OnExit_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF | Rte_Ev_Run_RteErrata9_RteErrata9_Trns | Rte_Ev_MS_Task_Trans_9));

    if ((ev & Rte_Ev_OnExit_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Start();
      DiagMgr9_Trns();
      Rte_Runnable_Ap_DiagMgr9_DiagMgr9_Trns_Return();

      /* call runnable */
      Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Start();
      DiagMgr_Trns1();
      Rte_Runnable_Ap_DiagMgr9_DiagMgr_Trns1_Return();

      /* call runnable */
      Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Trns2_Start();
      VehPwrMd_Trns2();
      Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Trns2_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OPERATE) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Start();
      ActivePull_Trns1();
      Rte_Runnable_Ap_ActivePull_ActivePull_Trns1_Return();
    }

    if ((ev & Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF) != (EventMaskType)0)
    {
      /* call runnable */
      Rte_Runnable_Ap_ActivePull_ActivePull_Trns2_Start();
      ActivePull_Trns2();
      Rte_Runnable_Ap_ActivePull_ActivePull_Trns2_Return();

      /* call runnable */
      Rte_Runnable_Ap_SnsrOffsLrng_SnsrOffsLrng_Trans1_Start();
      SnsrOffsLrng_Trans1();
      Rte_Runnable_Ap_SnsrOffsLrng_SnsrOffsLrng_Trans1_Return();

      /* call runnable */
      Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Start();
      AvgFricLrn_Trns1();
      Rte_Runnable_Ap_AvgFricLrn_AvgFricLrn_Trns1_Return();

      /* call runnable */
      Rte_Runnable_Ap_CustPerSrvcs_CustPerSrvcs_Trns1_Start();
      CustPerSrvcs_Trns1();
      Rte_Runnable_Ap_CustPerSrvcs_CustPerSrvcs_Trns1_Return();

      /* call runnable */
      Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Trns1_Start();
      SrlComOutput_Trns1();
      Rte_Runnable_Ap_SrlComOutput_SrlComOutput_Trns1_Return();

      /* call runnable */
      Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Trns1_Start();
      VehPwrMd_Trns1();
      Rte_Runnable_Ap_VehPwrMd_VehPwrMd_Trns1_Return();
    }

    if (((ev & Rte_Ev_Run_RteErrata9_RteErrata9_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OPERATE) != (EventMaskType)0))
    {
      /* call runnable */
      Rte_Runnable_RteErrata9_RteErrata9_Trns_Start();
      RteErrata9_Trns();
      Rte_Runnable_RteErrata9_RteErrata9_Trns_Return();
    }

    if (((ev & Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OPERATE) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF) != (EventMaskType)0) || ((ev & Rte_Ev_OnExit_Task_Trans_9_Ap_StaMd9_SystemState9_Mode_OFF) != (EventMaskType)0) || ((ev & Rte_Ev_Run_RteErrata9_RteErrata9_Trns) != (EventMaskType)0) || ((ev & Rte_Ev_MS_Task_Trans_9) != (EventMaskType)0))
    {
      Rte_ModeType_StaMd_Mode previousMode;
      Rte_ModeType_StaMd_Mode nextMode;

      Rte_Assert((Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode == RTE_TRANSITION_StaMd_Mode), RTE_E_INTERNAL_TransitionState);

      DisableAllInterrupts();
      previousMode = Rte_ModeInfo_Ap_StaMd9_SystemState9_Mode.Rte_ModeQueue[1];
      nextMode = Rte_ModeInfo_Ap_StaMd9_SystemState9_Mode.Rte_ModeQueue[0];

      if (previousMode != nextMode)
      {
        Rte_DecDisableFlags_Ap_StaMd9_SystemState9_Mode(previousMode);
      }

      Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode = Rte_ModeInfo_Ap_StaMd9_SystemState9_Mode.Rte_ModeQueue[0];

      EnableAllInterrupts();


    }
  }
}

/**********************************************************************************************************************
 * Task:     Task_TrnsB_9
 * Priority: 13
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_TrnsB_9)
{
  Rte_Task_Dispatch(Task_TrnsB_9);

  /* call runnable */
  Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Start();
  StaMd9_Trns_DemShutdown();
  Rte_Runnable_Ap_StaMd9_StaMd9_Trns_DemShutdown_Return();

  (void)TerminateTask();
}

#define RTE_STOP_SEC_CODE
#include "MemMap.h"

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
# ifdef RTE_MAGIC_NUMBER
#  if RTE_MAGIC_NUMBER != 1490107833
#   error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Rte.c> is different. Please check time and date of the generated RTE files!"
#  endif
# else
#  define RTE_MAGIC_NUMBER 1490107833
# endif  /* RTE_MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */
