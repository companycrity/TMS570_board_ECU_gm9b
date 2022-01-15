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
 *          File:  Components/Rte_Sa_CmMtrCurr3Phs.h
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
#ifndef _RTE_SA_CMMTRCURR3PHS_H
# define _RTE_SA_CMMTRCURR3PHS_H

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

#  define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Boolean, RTE_VAR_INIT) Rte_Sa_CmMtrCurr3Phs_CurrentGainSvc_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc;

#  define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ADCMtrCurrA_Volt_f32 (0.0F)
#  define Rte_InitValue_ADCMtrCurrB_Volt_f32 (0.0F)
#  define Rte_InitValue_ADCMtrCurrC_Volt_f32 (0.0F)
#  define Rte_InitValue_ComOffset_Cnt_u16 (0U)
#  define Rte_InitValue_CorrMtrCurrA_Amp_f32 (0.0F)
#  define Rte_InitValue_CorrMtrCurrB_Amp_f32 (0.0F)
#  define Rte_InitValue_CorrMtrCurrC_Amp_f32 (0.0F)
#  define Rte_InitValue_CurrentGainSvc_Cnt_lgc (FALSE)
#  define Rte_InitValue_FiltCntrlTemp_DegC_f32 (0.0F)
#  define Rte_InitValue_MtrCurrATempOffset_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrCurrBTempOffset_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrCurrCTempOffset_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrCurrIdptSig_Cnt_u08 (2U)
#  define Rte_InitValue_MtrVel_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_Vecu_Volt_f32 (5.0F)
#  define Rte_InitValue_VehSpd_Kph_f32 (0.0F)
#  define Rte_InitValue_VhSpdValid_Cnt_lgc (FALSE)
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

extern VAR(Rte_tsTask_100ms_10, RTE_VAR_NOINIT) Rte_Task_100ms_10;

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

#  define Rte_IRead_CmMtrCurr3Phs_Per1_FiltCntrlTemp_DegC_f32() \
  (Rte_Task_100ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1.Rte_FiltCntrlTemp_DegC_f32.value)

#  define Rte_IWrite_CmMtrCurr3Phs_Per1_MtrCurrATempOffset_Volt_f32(data) \
  ( \
    Rte_Task_100ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1.Rte_MtrCurrATempOffset_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_CmMtrCurr3Phs_Per1_MtrCurrATempOffset_Volt_f32() \
  (&Rte_Task_100ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1.Rte_MtrCurrATempOffset_Volt_f32.value)

#  define Rte_IWrite_CmMtrCurr3Phs_Per1_MtrCurrBTempOffset_Volt_f32(data) \
  ( \
    Rte_Task_100ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1.Rte_MtrCurrBTempOffset_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_CmMtrCurr3Phs_Per1_MtrCurrBTempOffset_Volt_f32() \
  (&Rte_Task_100ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1.Rte_MtrCurrBTempOffset_Volt_f32.value)

#  define Rte_IWrite_CmMtrCurr3Phs_Per1_MtrCurrCTempOffset_Volt_f32(data) \
  ( \
    Rte_Task_100ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1.Rte_MtrCurrCTempOffset_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_CmMtrCurr3Phs_Per1_MtrCurrCTempOffset_Volt_f32() \
  (&Rte_Task_100ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per1.Rte_MtrCurrCTempOffset_Volt_f32.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per2_ADCMtrCurrA_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_ADCMtrCurrA_Volt_f32.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per2_ADCMtrCurrB_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_ADCMtrCurrB_Volt_f32.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per2_ADCMtrCurrC_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_ADCMtrCurrC_Volt_f32.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per2_CorrMtrCurrA_Amp_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_CorrMtrCurrA_Amp_f32.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per2_CorrMtrCurrB_Amp_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_CorrMtrCurrB_Amp_f32.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per2_CorrMtrCurrC_Amp_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_CorrMtrCurrC_Amp_f32.value)

#  define Rte_IWrite_CmMtrCurr3Phs_Per2_MtrCurrIdptSig_Cnt_u08(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_MtrCurrIdptSig_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_CmMtrCurr3Phs_Per2_MtrCurrIdptSig_Cnt_u08() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per2.Rte_MtrCurrIdptSig_Cnt_u08.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per3_ADCMtrCurrA_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_ADCMtrCurrA_Volt_f32.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per3_ADCMtrCurrB_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_ADCMtrCurrB_Volt_f32.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per3_ADCMtrCurrC_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_ADCMtrCurrC_Volt_f32.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per3_MtrVel_MtrRadpS_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_MtrVel_MtrRadpS_f32.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per3_Vecu_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_Vecu_Volt_f32.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per3_VehSpd_Kph_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_VehSpd_Kph_f32.value)

#  define Rte_IRead_CmMtrCurr3Phs_Per3_VhSpdValid_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_VhSpdValid_Cnt_lgc.value)

#  define Rte_IWrite_CmMtrCurr3Phs_Per3_ComOffset_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_ComOffset_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CmMtrCurr3Phs_Per3_ComOffset_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CmMtrCurr3Phs_CmMtrCurr3Phs_Per3.Rte_ComOffset_Cnt_u16.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_MtrVel_MtrRadpS_f32 Rte_Read_Sa_CmMtrCurr3Phs_MtrVel_MtrRadpS_f32
#  define Rte_Read_Sa_CmMtrCurr3Phs_MtrVel_MtrRadpS_f32(data) (*(data) = Rte_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_VehSpd_Kph_f32 Rte_Read_Sa_CmMtrCurr3Phs_VehSpd_Kph_f32
#  define Rte_Read_Sa_CmMtrCurr3Phs_VehSpd_Kph_f32(data) (*(data) = Rte_Ap_SignlCondn_VehicleSpeed_Kph_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_VhSpdValid_Cnt_lgc Rte_Read_Sa_CmMtrCurr3Phs_VhSpdValid_Cnt_lgc
#  define Rte_Read_Sa_CmMtrCurr3Phs_VhSpdValid_Cnt_lgc(data) (*(data) = Rte_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_CurrentGainSvc_Cnt_lgc Rte_Write_Sa_CmMtrCurr3Phs_CurrentGainSvc_Cnt_lgc
#  define Rte_Write_Sa_CmMtrCurr3Phs_CurrentGainSvc_Cnt_lgc(data) (Rte_Sa_CmMtrCurr3Phs_CurrentGainSvc_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVM_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVM_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EOLCurrTempOffset3Phs_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)56, arg1))
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(UInt8 parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus);
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EOLShCurrCal3Phs_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((UInt8)16, arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(UInt8 parg0, Boolean RamBlockStatus);
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EOLShCurrCal3Phs_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((UInt8)16, arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EOLShCurrCal3Phs_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)16, arg1))
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(CurrTempOffset3PhsType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_CmMtrCurr3Phs_CurrTempOffset3Phs;
extern VAR(PhaseCurrCal3Phs_DataType, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_CmMtrCurr3Phs_ShCurrCal3Phs;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_CurrTempOffset3Phs() \
  (&Rte_Sa_CmMtrCurr3Phs_CurrTempOffset3Phs)

#  define Rte_Pim_ShCurrCal3Phs() \
  (&Rte_Sa_CmMtrCurr3Phs_ShCurrCal3Phs)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_CMMTRCURR3PHS_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CMMTRCURR3PHS_APPL_CODE) Cm3PhsMtrCurrTempOffset_Scom_Get(P2VAR(CurrTempOffset3PhsType, AUTOMATIC, RTE_SA_CMMTRCURR3PHS_APPL_VAR) CurrTempOff3PhsCal);

FUNC(void, RTE_SA_CMMTRCURR3PHS_APPL_CODE) Cm3PhsMtrCurrTempOffset_Scom_Set(P2CONST(CurrTempOffset3PhsType, AUTOMATIC, RTE_SA_CMMTRCURR3PHS_APPL_DATA) CurrTempOff3PhsCal);

FUNC(void, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr3Phs_Init(void);

FUNC(void, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr3Phs_Per1(void);

FUNC(void, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr3Phs_Per2(void);

FUNC(void, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr3Phs_Per3(void);

FUNC(Std_ReturnType, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr3Phs_SCom_3PhsCalOffset(void);

FUNC(void, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr3Phs_SCom_Read3PhsMtrCurrCals(P2VAR(PhaseCurrCal3Phs_DataType, AUTOMATIC, RTE_SA_CMMTRCURR3PHS_APPL_VAR) ShCurrCal3PhsPtr);

FUNC(void, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr3Phs_SCom_Set3PhsMtrCurrCals(P2CONST(PhaseCurrCal3Phs_DataType, AUTOMATIC, RTE_SA_CMMTRCURR3PHS_APPL_DATA) ShCurrCal3PhsPtr);

FUNC(Std_ReturnType, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurrPhs3_SCom_Phs3CalGain(void);

FUNC(Std_ReturnType, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr_SCom_CalGain(void);

FUNC(void, RTE_SA_CMMTRCURR3PHS_APPL_CODE) CmMtrCurr_SCom_MtrCurrOffReadStatus(P2VAR(MtrCurrOffProcessFlag, AUTOMATIC, RTE_SA_CMMTRCURR3PHS_APPL_VAR) CurrOffStatus);

# define RTE_STOP_SEC_SA_CMMTRCURR3PHS_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CmMtrCurr3Phs_SCom_ConditionNotCorrect (34U)

#  define RTE_E_CmMtrCurr3Phs_SCom_CurrentOutOfRange (20U)

#  define RTE_E_CmMtrCurr3Phs_SCom_VehSpdOutofRange (21U)

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
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Sa_CmMtrCurr3Phs.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CMMTRCURR3PHS_H */
