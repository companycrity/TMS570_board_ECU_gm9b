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
 *          File:  Components/Rte_Sa_AnaMSBCorrln.h
 *     Workspace:  C:/_synergy/9BXX_CZ8L9T/GM_9BXX_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Thu Aug 27 16:36:11 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_ANAMSBCORRLN_H
# define _RTE_SA_ANAMSBCORRLN_H

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

#  define Rte_InitValue_MtrPos1Corrd_Rev_u0p16 (0U)
#  define Rte_InitValue_MtrPos1Qlfr_State_enum (0U)
#  define Rte_InitValue_MtrPos1RollgCntr_Cnt_u08 (0U)
#  define Rte_InitValue_MtrPos2Corrd_Rev_u0p16 (0U)
#  define Rte_InitValue_MtrPos2Qlfr_State_enum (0U)
#  define Rte_InitValue_MtrPos2RollgCntr_Cnt_u08 (0U)
#  define Rte_InitValue_MtrPos3Corrd_Rev_u0p16 (0U)
#  define Rte_InitValue_MtrPos3Qlfr_State_enum (0U)
#  define Rte_InitValue_MtrPos3RollgCntr_Cnt_u08 (0U)
#  define Rte_InitValue_MtrPosCorrInSts_Cnt_u16 (0U)
#  define Rte_InitValue_MtrPosIndptsig_Cnt_u08 (3U)
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

#  define Rte_IRead_AnaMSBCorrln_Per1_MtrPos1Corrd_Rev_u0p16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBCorrln_AnaMSBCorrln_Per1.Rte_MtrPos1Corrd_Rev_u0p16.value)

#  define Rte_IRead_AnaMSBCorrln_Per1_MtrPos1Qlfr_State_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBCorrln_AnaMSBCorrln_Per1.Rte_MtrPos1Qlfr_State_enum.value)

#  define Rte_IRead_AnaMSBCorrln_Per1_MtrPos1RollgCntr_Cnt_u08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBCorrln_AnaMSBCorrln_Per1.Rte_MtrPos1RollgCntr_Cnt_u08.value)

#  define Rte_IRead_AnaMSBCorrln_Per1_MtrPos2Corrd_Rev_u0p16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBCorrln_AnaMSBCorrln_Per1.Rte_MtrPos2Corrd_Rev_u0p16.value)

#  define Rte_IRead_AnaMSBCorrln_Per1_MtrPos2Qlfr_State_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBCorrln_AnaMSBCorrln_Per1.Rte_MtrPos2Qlfr_State_enum.value)

#  define Rte_IRead_AnaMSBCorrln_Per1_MtrPos2RollgCntr_Cnt_u08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBCorrln_AnaMSBCorrln_Per1.Rte_MtrPos2RollgCntr_Cnt_u08.value)

#  define Rte_IRead_AnaMSBCorrln_Per1_MtrPos3Corrd_Rev_u0p16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBCorrln_AnaMSBCorrln_Per1.Rte_MtrPos3Corrd_Rev_u0p16.value)

#  define Rte_IRead_AnaMSBCorrln_Per1_MtrPos3Qlfr_State_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBCorrln_AnaMSBCorrln_Per1.Rte_MtrPos3Qlfr_State_enum.value)

#  define Rte_IRead_AnaMSBCorrln_Per1_MtrPos3RollgCntr_Cnt_u08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBCorrln_AnaMSBCorrln_Per1.Rte_MtrPos3RollgCntr_Cnt_u08.value)

#  define Rte_IWrite_AnaMSBCorrln_Per1_MtrPosCorrInSts_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_AnaMSBCorrln_MtrPosCorrInSts_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_AnaMSBCorrln_Per1_MtrPosCorrInSts_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_AnaMSBCorrln_MtrPosCorrInSts_Cnt_u16.value)

#  define Rte_IWrite_AnaMSBCorrln_Per1_MtrPosIndptsig_Cnt_u08(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBCorrln_AnaMSBCorrln_Per1.Rte_MtrPosIndptsig_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_AnaMSBCorrln_Per1_MtrPosIndptsig_Cnt_u08() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_AnaMSBCorrln_AnaMSBCorrln_Per1.Rte_MtrPosIndptsig_Cnt_u08.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_ANAMSBCORRLN_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_ANAMSBCORRLN_APPL_CODE) AnaMSBCorrln_Per1(void);

# define RTE_STOP_SEC_SA_ANAMSBCORRLN_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1440701359
#    error "The magic number of the generated file <C:/_synergy/9BXX_CZ8L9T/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Sa_AnaMSBCorrln.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1440701359
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_ANAMSBCORRLN_H */
