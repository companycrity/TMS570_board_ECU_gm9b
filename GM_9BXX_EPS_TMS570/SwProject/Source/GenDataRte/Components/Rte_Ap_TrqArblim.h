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
 *          File:  Components/Rte_Ap_TrqArblim.h
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
#ifndef _RTE_AP_TRQARBLIM_H
# define _RTE_AP_TRQARBLIM_H

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

#  define Rte_InitValue_AssistDDFactor_Uls_f32 (1.0F)
#  define Rte_InitValue_DampingDDFactor_Uls_f32 (1.0F)
#  define Rte_InitValue_ESCCmd_HwNm_f32 (0.0F)
#  define Rte_InitValue_ESCIsLimited_Cnt_lgc (FALSE)
#  define Rte_InitValue_ESCState_State_enum (0U)
#  define Rte_InitValue_ESCTorqueDelivered_HwNm_f32 (0.0F)
#  define Rte_InitValue_HwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_IqTrqOv_HwNm_f32 (0.0F)
#  define Rte_InitValue_LKACmd_HwNm_f32 (0.0F)
#  define Rte_InitValue_LKAState_State_enum (0U)
#  define Rte_InitValue_LKATorqueDelivered_HwNm_f32 (0.0F)
#  define Rte_InitValue_MaxSecureVehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_OpTrqOv_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PosServEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PosSrvoCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PullCmpCustLrngDi_Cnt_lgc (FALSE)
#  define Rte_InitValue_ReturnDDFactor_Uls_f32 (1.0F)
#  define Rte_InitValue_TrqOscCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_TrqOscEnable_Cnt_lgc (FALSE)
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

#  define Rte_IRead_TrqArblim_Per1_ESCCmd_HwNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ESCCmd_HwNm_f32.value)

#  define Rte_IRead_TrqArblim_Per1_ESCState_State_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ESCState_State_enum.value)

#  define Rte_IRead_TrqArblim_Per1_HwTorque_HwNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_HwTorque_HwNm_f32.value)

#  define Rte_IRead_TrqArblim_Per1_LKACmd_HwNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_LKACmd_HwNm_f32.value)

#  define Rte_IRead_TrqArblim_Per1_LKAState_State_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_LKAState_State_enum.value)

#  define Rte_IRead_TrqArblim_Per1_MaxSecureVehicleSpeed_Kph_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_MaxSecureVehicleSpeed_Kph_f32.value)

#  define Rte_IRead_TrqArblim_Per1_PosServEnable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_PosServEnable_Cnt_lgc.value)

#  define Rte_IRead_TrqArblim_Per1_PosSrvoCmd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_PosSrvoCmd_MtrNm_f32.value)

#  define Rte_IRead_TrqArblim_Per1_TrqOscCmd_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_TrqOscCmd_MtrNm_f32.value)

#  define Rte_IRead_TrqArblim_Per1_TrqOscEnable_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_TrqOscEnable_Cnt_lgc.value)

#  define Rte_IWrite_TrqArblim_Per1_AssistDDFactor_Uls_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_AssistDDFactor_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_TrqArblim_Per1_AssistDDFactor_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_AssistDDFactor_Uls_f32.value)

#  define Rte_IWrite_TrqArblim_Per1_DampingDDFactor_Uls_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_DampingDDFactor_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_TrqArblim_Per1_DampingDDFactor_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_DampingDDFactor_Uls_f32.value)

#  define Rte_IWrite_TrqArblim_Per1_ESCIsLimited_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ESCIsLimited_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_TrqArblim_Per1_ESCIsLimited_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ESCIsLimited_Cnt_lgc.value)

#  define Rte_IWrite_TrqArblim_Per1_ESCTorqueDelivered_HwNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ESCTorqueDelivered_HwNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_TrqArblim_Per1_ESCTorqueDelivered_HwNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ESCTorqueDelivered_HwNm_f32.value)

#  define Rte_IWrite_TrqArblim_Per1_IqTrqOv_HwNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_IqTrqOv_HwNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_TrqArblim_Per1_IqTrqOv_HwNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_IqTrqOv_HwNm_f32.value)

#  define Rte_IWrite_TrqArblim_Per1_LKATorqueDelivered_HwNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_LKATorqueDelivered_HwNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_TrqArblim_Per1_LKATorqueDelivered_HwNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_LKATorqueDelivered_HwNm_f32.value)

#  define Rte_IWrite_TrqArblim_Per1_OpTrqOv_MtrNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_OpTrqOv_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_TrqArblim_Per1_OpTrqOv_MtrNm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_OpTrqOv_MtrNm_f32.value)

#  define Rte_IWrite_TrqArblim_Per1_PullCmpCustLrngDi_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_PullCmpCustLrngDi_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_TrqArblim_Per1_PullCmpCustLrngDi_Cnt_lgc() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_PullCmpCustLrngDi_Cnt_lgc.value)

#  define Rte_IWrite_TrqArblim_Per1_ReturnDDFactor_Uls_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ReturnDDFactor_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_TrqArblim_Per1_ReturnDDFactor_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_TrqArblim_TrqArblim_Per1.Rte_ReturnDDFactor_Uls_f32.value)


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


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_TRQARBLIM_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQARBLIM_APPL_CODE) TrqArblim_Init(void);

FUNC(void, RTE_AP_TRQARBLIM_APPL_CODE) TrqArblim_Per1(void);

# define RTE_STOP_SEC_AP_TRQARBLIM_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_TrqArblim.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_TRQARBLIM_H */
