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
 *          File:  Components/Rte_Ap_SnsrOffsLrng.h
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
#ifndef _RTE_AP_SNSROFFSLRNG_H
# define _RTE_AP_SNSROFFSLRNG_H

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
#  define Rte_InitValue_HwAgOffs_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_HwTqOffs_HwNm_f32 (0.0F)
#  define Rte_InitValue_TorqueCmdCRF_MtrNm_f32 (0.0F)
#  define Rte_InitValue_VehYawRateOffs_DegpS_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleYawRate_DegpS_f32 (0.0F)
#  define Rte_InitValue_VehicleYawRateValid_Cnt_lgc (FALSE)
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



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_Init_9, RTE_VAR_NOINIT) Rte_Task_Init_9;

extern VAR(Rte_tsTask_2ms_9, RTE_VAR_NOINIT) Rte_Task_2ms_9;

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

#  define Rte_IWrite_SnsrOffsLrng_Init1_HwAgOffs_HwDeg_f32(data) \
  ( \
    Rte_Task_Init_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Init1.Rte_HwAgOffs_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_SnsrOffsLrng_Init1_HwAgOffs_HwDeg_f32() \
  (&Rte_Task_Init_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Init1.Rte_HwAgOffs_HwDeg_f32.value)

#  define Rte_IWrite_SnsrOffsLrng_Init1_HwTqOffs_HwNm_f32(data) \
  ( \
    Rte_Task_Init_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Init1.Rte_HwTqOffs_HwNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_SnsrOffsLrng_Init1_HwTqOffs_HwNm_f32() \
  (&Rte_Task_Init_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Init1.Rte_HwTqOffs_HwNm_f32.value)

#  define Rte_IWrite_SnsrOffsLrng_Init1_VehYawRateOffs_DegpS_f32(data) \
  ( \
    Rte_Task_Init_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Init1.Rte_VehYawRateOffs_DegpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_SnsrOffsLrng_Init1_VehYawRateOffs_DegpS_f32() \
  (&Rte_Task_Init_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Init1.Rte_VehYawRateOffs_DegpS_f32.value)

#  define Rte_IRead_SnsrOffsLrng_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_AbsHwPos_HandwheelAuthority_Uls_f32.value)

#  define Rte_IRead_SnsrOffsLrng_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per1.Rte_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IRead_SnsrOffsLrng_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per1.Rte_HandwheelVelocity_HwRadpS_f32.value)

#  define Rte_IRead_SnsrOffsLrng_Per1_HwTorque_HwNm_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per1.Rte_HwTorque_HwNm_f32.value)

#  define Rte_IRead_SnsrOffsLrng_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_Ap_SignlCondn_VehicleSpeedValid_Cnt_lgc.value)

#  define Rte_IRead_SnsrOffsLrng_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2ms_9.Rte_TB.Rte_I_Ap_SignlCondn_VehicleSpeed_Kph_f32.value)

#  define Rte_IRead_SnsrOffsLrng_Per2_HandwheelAuthority_Uls_f32() \
  (Rte_Task_10ms_9.Rte_TB.Rte_I_AbsHwPos_HandwheelAuthority_Uls_f32.value)

#  define Rte_IRead_SnsrOffsLrng_Per2_HandwheelPosition_HwDeg_f32() \
  (Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IRead_SnsrOffsLrng_Per2_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_HandwheelVelocity_HwRadpS_f32.value)

#  define Rte_IRead_SnsrOffsLrng_Per2_HwTorque_HwNm_f32() \
  (Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_HwTorque_HwNm_f32.value)

#  define Rte_IRead_SnsrOffsLrng_Per2_TorqueCmdCRF_MtrNm_f32() \
  (Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_TorqueCmdCRF_MtrNm_f32.value)

#  define Rte_IRead_SnsrOffsLrng_Per2_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_VehicleSpeedValid_Cnt_lgc.value)

#  define Rte_IRead_SnsrOffsLrng_Per2_VehicleSpeed_Kph_f32() \
  (Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IRead_SnsrOffsLrng_Per2_VehicleYawRateValid_Cnt_lgc() \
  (Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_VehicleYawRateValid_Cnt_lgc.value)

#  define Rte_IRead_SnsrOffsLrng_Per2_VehicleYawRate_DegpS_f32() \
  (Rte_Task_10ms_9.Rte_RB.Rte_Ap_SnsrOffsLrng_SnsrOffsLrng_Per2.Rte_VehicleYawRate_DegpS_f32.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus);
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SnsrLrndOffsBlk_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)81, arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, Boolean RamBlockStatus);
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SnsrLrndOffsBlk_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)81, arg1), ((Std_ReturnType)RTE_E_OK))
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


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(SnsrLrndOffs_Str, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_Ap_SnsrOffsLrng_SnsrLrndOffs;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_SnsrLrndOffs() \
  (&Rte_Ap_SnsrOffsLrng_SnsrLrndOffs)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SNSROFFSLRNG_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_Init1(void);

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_Per1(void);

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_Per2(void);

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_ReadHwAgOffs(P2VAR(Float, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) HwAgOffs_HwDeg_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) HwAgLrngStRst_Cnt_lgc);

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_ReadHwTqOffs(P2VAR(Float, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) HwTqOffs_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) HwTqLrngStRst_Cnt_lgc);

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_ReadYawRateOffs(P2VAR(Float, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) VehYawRateOffs_DegpS_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) VehYawRateLrngStRst_Cnt_lgc);

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_RstHwTq(void);

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_RstYawAndAg(void);

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_SetHwAgOffs(Float HwAgOffs_HwDeg_f32, Boolean HwAgLrngStRst_Cnt_lgc);

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_SetHwTqOffs(Float HwTqOffs_HwNm_f32, Boolean HwTqLrngStRst_Cnt_lgc);

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_SetYawRateOffs(Float VehYawRateOffs_DegpS_f32, Boolean VehYawRateLrngStRst_Cnt_lgc);

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_Trans1(void);

# define RTE_STOP_SEC_AP_SNSROFFSLRNG_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_SnsrOffsLrng.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SNSROFFSLRNG_H */
