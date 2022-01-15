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
 *          File:  Components/Rte_Ap_SnsrOffsCorrn.h
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
#ifndef _RTE_AP_SNSROFFSCORRN_H
# define _RTE_AP_SNSROFFSCORRN_H

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

#  define Rte_InitValue_HwAgCorrd_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HwAgOffs_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HwPosn_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HwTq_HwNm_f32 (0.0F)
#  define Rte_InitValue_HwTqCorrd_HwNm_f32 (0.0F)
#  define Rte_InitValue_HwTqOffs_HwNm_f32 (0.0F)
#  define Rte_InitValue_YawRate_DegpS_f32 (0.0F)
#  define Rte_InitValue_YawRateCorrd_DegpS_f32 (0.0F)
#  define Rte_InitValue_YawRateOffs_DegpS_f32 (0.0F)
# endif


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


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_SnsrOffsCorrn_Per1_HwAgOffs_HwDeg_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1.Rte_HwAgOffs_HwDeg_f32.value)

#  define Rte_IRead_SnsrOffsCorrn_Per1_HwPosn_HwDeg_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_AbsHwPos_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IRead_SnsrOffsCorrn_Per1_HwTqOffs_HwNm_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1.Rte_HwTqOffs_HwNm_f32.value)

#  define Rte_IRead_SnsrOffsCorrn_Per1_HwTq_HwNm_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_HwTrqArbn_HwTqVal_HwNm_f32.value)

#  define Rte_IRead_SnsrOffsCorrn_Per1_YawRateOffs_DegpS_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1.Rte_YawRateOffs_DegpS_f32.value)

#  define Rte_IRead_SnsrOffsCorrn_Per1_YawRate_DegpS_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_SignlCondn_VehicleYawRate_DegpS_f32.value)

#  define Rte_IWrite_SnsrOffsCorrn_Per1_HwAgCorrd_HwDeg_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1.Rte_HwAgCorrd_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_SnsrOffsCorrn_Per1_HwAgCorrd_HwDeg_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1.Rte_HwAgCorrd_HwDeg_f32.value)

#  define Rte_IWrite_SnsrOffsCorrn_Per1_HwTqCorrd_HwNm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_SnsrOffsCorrn_HwTqCorrd_HwNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_SnsrOffsCorrn_Per1_HwTqCorrd_HwNm_f32() \
  (&Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_SnsrOffsCorrn_HwTqCorrd_HwNm_f32.value)

#  define Rte_IWrite_SnsrOffsCorrn_Per1_YawRateCorrd_DegpS_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1.Rte_YawRateCorrd_DegpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_SnsrOffsCorrn_Per1_YawRateCorrd_DegpS_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_SnsrOffsCorrn_SnsrOffsCorrn_Per1.Rte_YawRateCorrd_DegpS_f32.value)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SNSROFFSCORRN_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSCORRN_APPL_CODE) SnsrOffsCorrn_Per1(void);

# define RTE_STOP_SEC_AP_SNSROFFSCORRN_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_SnsrOffsCorrn.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SNSROFFSCORRN_H */
