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
 *          File:  Components/Rte_Ap_DemIf.h
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
#ifndef _RTE_AP_DEMIF_H
# define _RTE_AP_DEMIF_H

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
extern VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_DisableCEBusNormComm_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_DisableHSBusNormComm_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_EngRunAtvForCTCInhibit_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SPMForCTCInhibit_Cnt_lgc;
extern VAR(SysPwrMd, RTE_VAR_INIT) Rte_SrlComInput_SrlComSysPwrMd_Cnt_enum;
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_BattVltg_BrdgVltg_Volt_f32;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BusOffCE_Cnt_lgc (FALSE)
#  define Rte_InitValue_BusOffHS_Cnt_lgc (FALSE)
#  define Rte_InitValue_DisableCEBusNormComm_Cnt_lgc (FALSE)
#  define Rte_InitValue_DisableHSBusNormComm_Cnt_lgc (FALSE)
#  define Rte_InitValue_EngRunAtvForCTCInhibit_Cnt_lgc (FALSE)
#  define Rte_InitValue_SPMForCTCInhibit_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComEngOn_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComSysPwrMd_Cnt_enum (0U)
#  define Rte_InitValue_Vecu_Volt_f32 (5.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_10ms_9, RTE_VAR_NOINIT) Rte_Task_10ms_9;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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

#  define Rte_IRead_DemIf_Per1_SrlComEngOn_Cnt_lgc() \
  (Rte_Task_10ms_9.Rte_RB.Rte_Ap_DemIf_DemIf_Per1.Rte_SrlComEngOn_Cnt_lgc.value)

#  define Rte_IRead_DemIf_Per1_SrlComSysPwrMd_Cnt_enum() \
  (Rte_Task_10ms_9.Rte_RB.Rte_Ap_DemIf_DemIf_Per1.Rte_SrlComSysPwrMd_Cnt_enum.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BusOffCE_Cnt_lgc Rte_Read_Ap_DemIf_BusOffCE_Cnt_lgc
#  define Rte_Read_Ap_DemIf_BusOffCE_Cnt_lgc(data) (*(data) = Rte_SrlComOutput_BusOffCE_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_BusOffHS_Cnt_lgc Rte_Read_Ap_DemIf_BusOffHS_Cnt_lgc
#  define Rte_Read_Ap_DemIf_BusOffHS_Cnt_lgc(data) (*(data) = Rte_SrlComOutput_BusOffHS_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DisableCEBusNormComm_Cnt_lgc Rte_Read_Ap_DemIf_DisableCEBusNormComm_Cnt_lgc
#  define Rte_Read_Ap_DemIf_DisableCEBusNormComm_Cnt_lgc(data) (*(data) = Rte_CDDInterface_DisableCEBusNormComm_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DisableHSBusNormComm_Cnt_lgc Rte_Read_Ap_DemIf_DisableHSBusNormComm_Cnt_lgc
#  define Rte_Read_Ap_DemIf_DisableHSBusNormComm_Cnt_lgc(data) (*(data) = Rte_CDDInterface_DisableHSBusNormComm_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_EngRunAtvForCTCInhibit_Cnt_lgc Rte_Read_Ap_DemIf_EngRunAtvForCTCInhibit_Cnt_lgc
#  define Rte_Read_Ap_DemIf_EngRunAtvForCTCInhibit_Cnt_lgc(data) (*(data) = Rte_SrlComInput_EngRunAtvForCTCInhibit_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SPMForCTCInhibit_Cnt_lgc Rte_Read_Ap_DemIf_SPMForCTCInhibit_Cnt_lgc
#  define Rte_Read_Ap_DemIf_SPMForCTCInhibit_Cnt_lgc(data) (*(data) = Rte_SrlComInput_SPMForCTCInhibit_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComSysPwrMd_Cnt_enum Rte_Read_Ap_DemIf_SrlComSysPwrMd_Cnt_enum
#  define Rte_Read_Ap_DemIf_SrlComSysPwrMd_Cnt_enum(data) (*(data) = Rte_SrlComInput_SrlComSysPwrMd_Cnt_enum, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Vecu_Volt_f32 Rte_Read_Ap_DemIf_Vecu_Volt_f32
#  define Rte_Read_Ap_DemIf_Vecu_Volt_f32(data) (*(data) = Rte_Ap_BattVltg_BrdgVltg_Volt_f32, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCActive_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCActive NxtrDiagMgr9_GetNTCActive
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(arg1, arg2) (DtrmnElapsedTime_mS_u16(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
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


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_DEMIF_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_DemShutdown(void);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Per1(void);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_RestartDem(void);

FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus);

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState);

# define RTE_STOP_SEC_AP_DEMIF_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DemIf_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_DemIf.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_DEMIF_H */
