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
 *          File:  Components/Rte_Ap_TrqOvlSta.h
 *     Workspace:  C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Mar 21 14:08:39 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_TRQOVLSTA_H
# define _RTE_AP_TRQOVLSTA_H

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


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_APADrvrInterventionDetected_Cnt_lgc (FALSE)
#  define Rte_InitValue_APANonRecoverableFaults_Cnt_lgc (FALSE)
#  define Rte_InitValue_APARecoverableFaults_Cnt_lgc (FALSE)
#  define Rte_InitValue_APARequest_Cnt_lgc (FALSE)
#  define Rte_InitValue_APAState_State_enum (0U)
#  define Rte_InitValue_CCWPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_CWPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_ESCFault_Cnt_lgc (FALSE)
#  define Rte_InitValue_ESCIsLimited_Cnt_lgc (FALSE)
#  define Rte_InitValue_ESCRequest_Cnt_lgc (FALSE)
#  define Rte_InitValue_ESCState_State_enum (0U)
#  define Rte_InitValue_GMOSHOscillateState_State_enum (1U)
#  define Rte_InitValue_GMOSH_APAMfgEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_GMOSH_ESCMfgEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_GMOSH_LKAMfgEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_HapticRequest_Cnt_lgc (FALSE)
#  define Rte_InitValue_HwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_LKAFault_Cnt_lgc (FALSE)
#  define Rte_InitValue_LKAInhibit_Cnt_lgc (FALSE)
#  define Rte_InitValue_LKARequest_Cnt_lgc (FALSE)
#  define Rte_InitValue_LKAState_State_enum (0U)
#  define Rte_InitValue_LOASt_State_enum (0U)
#  define Rte_InitValue_LkaDrvrIntvDetd_Cnt_lgc (FALSE)
#  define Rte_InitValue_MaxSecureVehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_MinSecureVehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_PosServEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PosSrvoHwAngle_HwDeg_f32 (0.0F)
#  define Rte_InitValue_PosTrajEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PosTrajHwAngle_HwDeg_f32 (0.0F)
#  define Rte_InitValue_SWARTrgtAngRequest_HwDeg_f32 (0.0F)
#  define Rte_InitValue_ShiftLeverIsInReverse_Cnt_lgc (FALSE)
#  define Rte_InitValue_TrqOscAmp_MtrNm_f32 (0.0F)
#  define Rte_InitValue_TrqOscEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_TrqOscFreq_Hz_f32 (0.0F)
#  define Rte_InitValue_VehSpd_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_TrqOvlSta_Per1_APANonRecoverableFaults_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_APANonRecoverableFaults_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_APARecoverableFaults_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_APARecoverableFaults_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_APARequest_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_APARequest_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_CCWPosition_HwDeg_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_CCWPosition_HwDeg_f32.value)

#  define Rte_IRead_TrqOvlSta_Per1_CWPosition_HwDeg_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_CWPosition_HwDeg_f32.value)

#  define Rte_IRead_TrqOvlSta_Per1_ESCFault_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_ESCFault_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_ESCIsLimited_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_ESCIsLimited_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_ESCRequest_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_ESCRequest_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_GMOSH_APAMfgEnable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_GMOSH_APAMfgEnable_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_GMOSH_ESCMfgEnable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_GMOSH_ESCMfgEnable_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_GMOSH_LKAMfgEnable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_GMOSH_LKAMfgEnable_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_HapticRequest_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_HapticRequest_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_HwTorque_HwNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_HwTorque_HwNm_f32.value)

#  define Rte_IRead_TrqOvlSta_Per1_LKAFault_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LKAFault_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_LKAInhibit_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LKAInhibit_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_LKARequest_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LKARequest_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_LOASt_State_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LOASt_State_enum.value)

#  define Rte_IRead_TrqOvlSta_Per1_MaxSecureVehicleSpeed_Kph_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_MaxSecureVehicleSpeed_Kph_f32.value)

#  define Rte_IRead_TrqOvlSta_Per1_MinSecureVehicleSpeed_Kph_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_MinSecureVehicleSpeed_Kph_f32.value)

#  define Rte_IRead_TrqOvlSta_Per1_PosTrajEnable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_PosTrajEnable_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_PosTrajHwAngle_HwDeg_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_PosTrajHwAngle_HwDeg_f32.value)

#  define Rte_IRead_TrqOvlSta_Per1_SWARTrgtAngRequest_HwDeg_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_SWARTrgtAngRequest_HwDeg_f32.value)

#  define Rte_IRead_TrqOvlSta_Per1_ShiftLeverIsInReverse_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_ShiftLeverIsInReverse_Cnt_lgc.value)

#  define Rte_IRead_TrqOvlSta_Per1_VehSpd_Kph_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_VehSpd_Kph_f32.value)

#  define Rte_IWrite_TrqOvlSta_Per1_APADrvrInterventionDetected_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_APADrvrInterventionDetected_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_TrqOvlSta_Per1_APADrvrInterventionDetected_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_APADrvrInterventionDetected_Cnt_lgc.value)

#  define Rte_IWrite_TrqOvlSta_Per1_APAState_State_enum(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_APAState_State_enum.value = (data) \
  )

#  define Rte_IWriteRef_TrqOvlSta_Per1_APAState_State_enum() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_APAState_State_enum.value)

#  define Rte_IWrite_TrqOvlSta_Per1_ESCState_State_enum(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_ESCState_State_enum.value = (data) \
  )

#  define Rte_IWriteRef_TrqOvlSta_Per1_ESCState_State_enum() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_ESCState_State_enum.value)

#  define Rte_IWrite_TrqOvlSta_Per1_GMOSHOscillateState_State_enum(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_GMOSHOscillateState_State_enum.value = (data) \
  )

#  define Rte_IWriteRef_TrqOvlSta_Per1_GMOSHOscillateState_State_enum() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_GMOSHOscillateState_State_enum.value)

#  define Rte_IWrite_TrqOvlSta_Per1_LKAState_State_enum(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LKAState_State_enum.value = (data) \
  )

#  define Rte_IWriteRef_TrqOvlSta_Per1_LKAState_State_enum() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LKAState_State_enum.value)

#  define Rte_IWrite_TrqOvlSta_Per1_LkaDrvrIntvDetd_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LkaDrvrIntvDetd_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_TrqOvlSta_Per1_LkaDrvrIntvDetd_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_LkaDrvrIntvDetd_Cnt_lgc.value)

#  define Rte_IWrite_TrqOvlSta_Per1_PosServEnable_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_PosServEnable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_TrqOvlSta_Per1_PosServEnable_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_PosServEnable_Cnt_lgc.value)

#  define Rte_IWrite_TrqOvlSta_Per1_PosSrvoHwAngle_HwDeg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_PosSrvoHwAngle_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_TrqOvlSta_Per1_PosSrvoHwAngle_HwDeg_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_PosSrvoHwAngle_HwDeg_f32.value)

#  define Rte_IWrite_TrqOvlSta_Per1_TrqOscAmp_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_TrqOscAmp_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_TrqOvlSta_Per1_TrqOscAmp_MtrNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_TrqOscAmp_MtrNm_f32.value)

#  define Rte_IWrite_TrqOvlSta_Per1_TrqOscEnable_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_TrqOscEnable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_TrqOvlSta_Per1_TrqOscEnable_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_TrqOscEnable_Cnt_lgc.value)

#  define Rte_IWrite_TrqOvlSta_Per1_TrqOscFreq_Hz_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_TrqOscFreq_Hz_f32.value = (data) \
  )

#  define Rte_IWriteRef_TrqOvlSta_Per1_TrqOscFreq_Hz_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqOvlSta_TrqOvlSta_Per1.Rte_TrqOscFreq_Hz_f32.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_FLTINJECTION_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_FLTINJECTION_APPL_CODE) FltInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_FLTINJECTION_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
#  define RTE_STOP_SEC_AP_FLTINJECTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_FaultInjection_SCom_FltInjection(arg1, arg2) (FltInjection_SCom_FltInjection(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(arg1, arg2) (DtrmnElapsedTime_mS_u32(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(UInt8 parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus);
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_TrqOvlStaBlk_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((UInt8)23, arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(UInt8 parg0, Boolean RamBlockStatus);
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_TrqOvlStaBlk_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((UInt8)23, arg1), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(UInt16, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_TrqOvlSta_GmLoaIgnCntr;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_GmLoaIgnCntr() \
  (&Rte_TrqOvlSta_GmLoaIgnCntr)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_TRQOVLSTA_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQOVLSTA_APPL_CODE) TrqOvlSta_Init(void);

FUNC(void, RTE_AP_TRQOVLSTA_APPL_CODE) TrqOvlSta_Per1(void);

FUNC(void, RTE_AP_TRQOVLSTA_APPL_CODE) TrqOvlSta_SCom_GetGmLoaIgnCntr(P2VAR(UInt16, AUTOMATIC, RTE_AP_TRQOVLSTA_APPL_VAR) GmLoaIgnCntr_Cnt_u16);

FUNC(void, RTE_AP_TRQOVLSTA_APPL_CODE) TrqOvlSta_SCom_SetGmLoaIgnCntr(UInt16 GmLoaIgnCntr_Cnt_u16);

# define RTE_STOP_SEC_AP_TRQOVLSTA_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_TrqOvlSta.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_TRQOVLSTA_H */
