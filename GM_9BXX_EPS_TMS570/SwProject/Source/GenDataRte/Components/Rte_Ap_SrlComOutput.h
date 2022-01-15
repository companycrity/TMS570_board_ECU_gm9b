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
 *          File:  Components/Rte_Ap_SrlComOutput.h
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
#ifndef _RTE_AP_SRLCOMOUTPUT_H
# define _RTE_AP_SRLCOMOUTPUT_H

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

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComOutput_BusOffCE_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComOutput_BusOffHS_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_TrqOvlSta_APADrvrInterventionDetected_Cnt_lgc;
extern VAR(APA_State_enum, RTE_VAR_INIT) Rte_TrqOvlSta_APAState_State_enum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagRmpToZeroActive_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsScomHWANotValid_Cnt_lgc;
extern VAR(ESC_State_enum, RTE_VAR_INIT) Rte_TrqOvlSta_ESCState_State_enum;
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_TrqArblim_ESCTorqueDelivered_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_HOWDetect_HOWEstimate_Uls_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Sa_MtrVel_HwVelValid_Cnt_lgc;
extern VAR(LKA_State_enum, RTE_VAR_INIT) Rte_TrqOvlSta_LKAState_State_enum;
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_TrqArblim_LKATorqueDelivered_HwNm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_AbsHwPos_SrlComHwPos_HwDeg_f32;
extern VAR(SysPwrMd, RTE_VAR_INIT) Rte_SrlComInput_SrlComSysPwrMd_Cnt_enum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DigColPs_TrimComp_Cnt_lgc;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_APADrvrInterventionDetected_Cnt_lgc (FALSE)
#  define Rte_InitValue_APAState_State_enum (0U)
#  define Rte_InitValue_BusOffCE_Cnt_lgc (FALSE)
#  define Rte_InitValue_BusOffHS_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagRmpToZeroActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStsHwPosDis_Cnt_lgc (FALSE)
#  define Rte_InitValue_ESCState_State_enum (0U)
#  define Rte_InitValue_ESCTorqueDelivered_HwNm_f32 (0.0F)
#  define Rte_InitValue_HOWEstimate_Uls_f32 (0.0F)
#  define Rte_InitValue_HandwheelVel_HwRadpS_f32 (0.0F)
#  define Rte_InitValue_HwTrq_HwNm_f32 (0.0F)
#  define Rte_InitValue_HwVelValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_LKAState_State_enum (0U)
#  define Rte_InitValue_LKATrqDelivered_HwNm_f32 (0.0F)
#  define Rte_InitValue_SrlComHwPos_HwDeg_f32 (0.0F)
#  define Rte_InitValue_SrlComSysPwrMd_Cnt_enum (0U)
#  define Rte_InitValue_TrimCompEOL_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_APADrvrInterventionDetected_Cnt_lgc Rte_Read_Ap_SrlComOutput_APADrvrInterventionDetected_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_APADrvrInterventionDetected_Cnt_lgc(data) (*(data) = Rte_TrqOvlSta_APADrvrInterventionDetected_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_APAState_State_enum Rte_Read_Ap_SrlComOutput_APAState_State_enum
#  define Rte_Read_Ap_SrlComOutput_APAState_State_enum(data) (*(data) = Rte_TrqOvlSta_APAState_State_enum, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DiagRmpToZeroActive_Cnt_lgc Rte_Read_Ap_SrlComOutput_DiagRmpToZeroActive_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_DiagRmpToZeroActive_Cnt_lgc(data) (*(data) = Rte_DiagMgr_DiagRmpToZeroActive_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DiagStsHwPosDis_Cnt_lgc Rte_Read_Ap_SrlComOutput_DiagStsHwPosDis_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_DiagStsHwPosDis_Cnt_lgc(data) (*(data) = Rte_DiagMgr_DiagStsScomHWANotValid_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ESCState_State_enum Rte_Read_Ap_SrlComOutput_ESCState_State_enum
#  define Rte_Read_Ap_SrlComOutput_ESCState_State_enum(data) (*(data) = Rte_TrqOvlSta_ESCState_State_enum, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ESCTorqueDelivered_HwNm_f32 Rte_Read_Ap_SrlComOutput_ESCTorqueDelivered_HwNm_f32
#  define Rte_Read_Ap_SrlComOutput_ESCTorqueDelivered_HwNm_f32(data) (*(data) = Rte_Ap_TrqArblim_ESCTorqueDelivered_HwNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HOWEstimate_Uls_f32 Rte_Read_Ap_SrlComOutput_HOWEstimate_Uls_f32
#  define Rte_Read_Ap_SrlComOutput_HOWEstimate_Uls_f32(data) (*(data) = Rte_Ap_HOWDetect_HOWEstimate_Uls_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HandwheelVel_HwRadpS_f32 Rte_Read_Ap_SrlComOutput_HandwheelVel_HwRadpS_f32
#  define Rte_Read_Ap_SrlComOutput_HandwheelVel_HwRadpS_f32(data) (*(data) = Rte_Sa_MtrVel_HandwheelVel_HwRadpS_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HwTrq_HwNm_f32 Rte_Read_Ap_SrlComOutput_HwTrq_HwNm_f32
#  define Rte_Read_Ap_SrlComOutput_HwTrq_HwNm_f32(data) (*(data) = Rte_Sa_HwTrqArbn_HwTqVal_HwNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_HwVelValid_Cnt_lgc Rte_Read_Ap_SrlComOutput_HwVelValid_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_HwVelValid_Cnt_lgc(data) (*(data) = Rte_Sa_MtrVel_HwVelValid_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_LKAState_State_enum Rte_Read_Ap_SrlComOutput_LKAState_State_enum
#  define Rte_Read_Ap_SrlComOutput_LKAState_State_enum(data) (*(data) = Rte_TrqOvlSta_LKAState_State_enum, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_LKATrqDelivered_HwNm_f32 Rte_Read_Ap_SrlComOutput_LKATrqDelivered_HwNm_f32
#  define Rte_Read_Ap_SrlComOutput_LKATrqDelivered_HwNm_f32(data) (*(data) = Rte_Ap_TrqArblim_LKATorqueDelivered_HwNm_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComHwPos_HwDeg_f32 Rte_Read_Ap_SrlComOutput_SrlComHwPos_HwDeg_f32
#  define Rte_Read_Ap_SrlComOutput_SrlComHwPos_HwDeg_f32(data) (*(data) = Rte_AbsHwPos_SrlComHwPos_HwDeg_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComSysPwrMd_Cnt_enum Rte_Read_Ap_SrlComOutput_SrlComSysPwrMd_Cnt_enum
#  define Rte_Read_Ap_SrlComOutput_SrlComSysPwrMd_Cnt_enum(data) (*(data) = Rte_SrlComInput_SrlComSysPwrMd_Cnt_enum, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_TrimCompEOL_Cnt_lgc Rte_Read_Ap_SrlComOutput_TrimCompEOL_Cnt_lgc
#  define Rte_Read_Ap_SrlComOutput_TrimCompEOL_Cnt_lgc(data) (*(data) = Rte_DigColPs_TrimComp_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_BusOffCE_Cnt_lgc Rte_Write_Ap_SrlComOutput_BusOffCE_Cnt_lgc
#  define Rte_Write_Ap_SrlComOutput_BusOffCE_Cnt_lgc(data) (Rte_SrlComOutput_BusOffCE_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_BusOffHS_Cnt_lgc Rte_Write_Ap_SrlComOutput_BusOffHS_Cnt_lgc
#  define Rte_Write_Ap_SrlComOutput_BusOffHS_Cnt_lgc(data) (Rte_SrlComOutput_BusOffHS_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_RequestComMode(ComM_UserHandleType parg0, ComM_ModeType ComMode);
#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_ComM_UserRequest_0_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)0, arg1))
#  define Rte_Call_ComM_UserRequest_1_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)1, arg1))
#  define Rte_Call_ComM_UserRequest_2_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)2, arg1))
#  define Rte_Call_ComM_UserRequest_3_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)3, arg1))
#  define Rte_Call_ComM_UserRequest_4_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)4, arg1))
#  define Rte_Call_ComM_UserRequest_5_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)5, arg1))
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVM_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVM_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_DTCTrigSts_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)79, arg1))
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCActive_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCActive NxtrDiagMgr9_GetNTCActive
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr9_SetNTCStatus
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(arg1, arg2) (DtrmnElapsedTime_mS_u16(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(DTCStsFlg, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_SrlComOutput_DTCTrigSts;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_DTCTrigSts() (&((*RtePim_DTCTrigSts())[0]))
#  else
#   define Rte_Pim_DTCTrigSts() RtePim_DTCTrigSts()
#  endif
#  define RtePim_DTCTrigSts() \
  (&Rte_SrlComOutput_DTCTrigSts)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Init1(void);

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per1(void);

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per2(void);

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Trns1(void);

# define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComM_UserRequest_COMM_E_MODE_LIMITATION (2U)

#  define RTE_E_ComM_UserRequest_E_NOT_OK (1U)

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_SrlComOutput.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMOUTPUT_H */
