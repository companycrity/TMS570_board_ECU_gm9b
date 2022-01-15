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
 *          File:  Components/Rte_Ap_BattVltgCorrln.h
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
#ifndef _RTE_AP_BATTVLTGCORRLN_H
# define _RTE_AP_BATTVLTGCORRLN_H

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

#  define Rte_InitValue_BattSwdVltgCorrlnSts_Cnt_u08 (7U)
#  define Rte_InitValue_BattVltg_Volt_f32 (0.0F)
#  define Rte_InitValue_BattVltgCorrlnIdptSig_Cnt_u08 (3U)
#  define Rte_InitValue_BattVltgSwd1_Volt_f32 (0.0F)
#  define Rte_InitValue_BattVltgSwd2_Volt_f32 (0.0F)
#  define Rte_InitValue_DftBrdgVltgActv_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagcStsIvtr1Inactv_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagcStsIvtr2Inactv_Cnt_lgc (FALSE)
#  define Rte_InitValue_SwdVltgLimd_Cnt_lgc (FALSE)
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

extern VAR(Rte_tsTask_2ms_9, RTE_VAR_NOINIT) Rte_Task_2ms_9;

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

#  define Rte_IRead_BattVltgCorrln_Per1_BattVltgSwd1_Volt_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_BattVltgSwd1_Volt_f32.value)

#  define Rte_IRead_BattVltgCorrln_Per1_BattVltgSwd2_Volt_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_BattVltgSwd2_Volt_f32.value)

#  define Rte_IRead_BattVltgCorrln_Per1_BattVltg_Volt_f32() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_BattVltg_Volt_f32.value)

#  define Rte_IRead_BattVltgCorrln_Per1_DiagcStsIvtr1Inactv_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_DiagcStsIvtr1Inactv_Cnt_lgc.value)

#  define Rte_IRead_BattVltgCorrln_Per1_DiagcStsIvtr2Inactv_Cnt_lgc() \
  (Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_DiagcStsIvtr2Inactv_Cnt_lgc.value)

#  define Rte_IWrite_BattVltgCorrln_Per1_BattSwdVltgCorrlnSts_Cnt_u08(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_BattSwdVltgCorrlnSts_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_BattVltgCorrln_Per1_BattSwdVltgCorrlnSts_Cnt_u08() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_BattSwdVltgCorrlnSts_Cnt_u08.value)

#  define Rte_IWrite_BattVltgCorrln_Per1_BattVltgCorrlnIdptSig_Cnt_u08(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_BattVltgCorrlnIdptSig_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_BattVltgCorrln_Per1_BattVltgCorrlnIdptSig_Cnt_u08() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_BattVltgCorrlnIdptSig_Cnt_u08.value)

#  define Rte_IWrite_BattVltgCorrln_Per1_DftBrdgVltgActv_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_DftBrdgVltgActv_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_BattVltgCorrln_Per1_DftBrdgVltgActv_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_DftBrdgVltgActv_Cnt_lgc.value)

#  define Rte_IWrite_BattVltgCorrln_Per1_SwdVltgLimd_Cnt_lgc(data) \
  ( \
    Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_SwdVltgLimd_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_BattVltgCorrln_Per1_SwdVltgLimd_Cnt_lgc() \
  (&Rte_Task_2ms_9.Rte_RB.Rte_Ap_BattVltgCorrln_BattVltgCorrln_Per1.Rte_SwdVltgLimd_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SysSt_Mode() Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr9_SetNTCStatus


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_BATTVLTGCORRLN_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BATTVLTGCORRLN_APPL_CODE) BattVltgCorrln_Per1(void);

# define RTE_STOP_SEC_AP_BATTVLTGCORRLN_APPL_CODE
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
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_BattVltgCorrln.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_BATTVLTGCORRLN_H */
