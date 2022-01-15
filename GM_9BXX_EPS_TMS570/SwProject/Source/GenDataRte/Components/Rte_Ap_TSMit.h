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
 *          File:  Components/Rte_Ap_TSMit.h
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
#ifndef _RTE_AP_TSMIT_H
# define _RTE_AP_TSMIT_H

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

#  define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 (0.0F)
#  define Rte_InitValue_HwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_PreLimitMtrTrqCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_SrlComABSActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComESCActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComTCSActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComTransmissionTrq_TransNm_f32 (0.0F)
#  define Rte_InitValue_SrlComYawRate_DegpS_f32 (0.0F)
#  define Rte_InitValue_TSMitCommand_MtrNm_f32 (0.0F)
#  define Rte_InitValue_TSMitDefeat_Cnt_lgc (FALSE)
#  define Rte_InitValue_TSMitLearningEnabled_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_10ms_10, RTE_VAR_NOINIT) Rte_Task_10ms_10;

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

#  define Rte_IRead_TSMit_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_HandwheelAuthority_Uls_f32.value)

#  define Rte_IRead_TSMit_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IRead_TSMit_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_HandwheelVelocity_HwRadpS_f32.value)

#  define Rte_IRead_TSMit_Per1_HwTorque_HwNm_f32() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_HwTorque_HwNm_f32.value)

#  define Rte_IRead_TSMit_Per1_PreLimitMtrTrqCmd_MtrNm_f32() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_PreLimitMtrTrqCmd_MtrNm_f32.value)

#  define Rte_IRead_TSMit_Per1_SrlComABSActive_Cnt_lgc() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_SrlComABSActive_Cnt_lgc.value)

#  define Rte_IRead_TSMit_Per1_SrlComESCActive_Cnt_lgc() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_SrlComESCActive_Cnt_lgc.value)

#  define Rte_IRead_TSMit_Per1_SrlComTCSActive_Cnt_lgc() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_SrlComTCSActive_Cnt_lgc.value)

#  define Rte_IRead_TSMit_Per1_SrlComTransmissionTrq_TransNm_f32() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_SrlComTransmissionTrq_TransNm_f32.value)

#  define Rte_IRead_TSMit_Per1_SrlComYawRate_DegpS_f32() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_SrlComYawRate_DegpS_f32.value)

#  define Rte_IRead_TSMit_Per1_TSMitDefeat_Cnt_lgc() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_TSMitDefeat_Cnt_lgc.value)

#  define Rte_IRead_TSMit_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_TSMit_Per1_TSMitCommand_MtrNm_f32(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_TSMitCommand_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_TSMit_Per1_TSMitCommand_MtrNm_f32() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_TSMitCommand_MtrNm_f32.value)

#  define Rte_IWrite_TSMit_Per1_TSMitLearningEnabled_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_TSMitLearningEnabled_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_TSMit_Per1_TSMitLearningEnabled_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Ap_TSMit_TSMit_Per1.Rte_TSMitLearningEnabled_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
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
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_TSMitDisableEOL_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)8, arg1))
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(UInt8 parg0, Boolean RamBlockStatus);
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_TSMitGainLrn_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((UInt8)9, arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_TSMitGainLrn_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)9, arg1))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(TSMit_Disable_Type, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Ap_TSMit_TSMitDisableEOL;
extern VAR(TSMit_Gain_Type, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Ap_TSMit_TSMitGainLrn;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_TSMitDisableEOL() \
  (&Rte_Ap_TSMit_TSMitDisableEOL)

#  define Rte_Pim_TSMitGainLrn() \
  (&Rte_Ap_TSMit_TSMitGainLrn)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_TSMIT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_Init1(void);

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_Per1(void);

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_GainReset(void);

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_GetFcnDefeat(P2VAR(Boolean, AUTOMATIC, RTE_AP_TSMIT_APPL_VAR) FunctionDefeat_Cnt_lgc);

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_GetLongTermGains(P2VAR(Float, AUTOMATIC, RTE_AP_TSMIT_APPL_VAR) LTPosTransGain_HwNmpTransNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_TSMIT_APPL_VAR) LTNegTransGain_HwNmpTransNm_f32);

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_GetLrnDefeat(P2VAR(Boolean, AUTOMATIC, RTE_AP_TSMIT_APPL_VAR) LearningDefeat_Cnt_lgc);

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_SetFcnDefeat(Boolean FunctionDefeat_Cnt_lgc);

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_SetLongTermGains(Float LTPosTransGain_HwNmpTransNm_f32, Float LTNegTransGain_HwNmpTransNm_f32);

FUNC(void, RTE_AP_TSMIT_APPL_CODE) TSMit_SCom_SetLrnDefeat(Boolean LearningDefeat_Cnt_lgc);

# define RTE_STOP_SEC_AP_TSMIT_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_TSMit.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_TSMIT_H */
