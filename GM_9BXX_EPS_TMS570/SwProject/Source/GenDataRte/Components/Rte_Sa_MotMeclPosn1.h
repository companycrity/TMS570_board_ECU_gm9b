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
 *          File:  Components/Rte_Sa_MotMeclPosn1.h
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
#ifndef _RTE_SA_MOTMECLPOSN1_H
# define _RTE_SA_MOTMECLPOSN1_H

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

#  define Rte_InitValue_MotMeclPosn1RawErrReg_Cnt_u16 (0U)
#  define Rte_InitValue_MotPosnQlfr_State_enum (0U)
#  define Rte_InitValue_ParityFaultAccum_Cnt_u16 (0U)
#  define Rte_InitValue_UnderVltgFaultAccum_Cnt_u16 (0U)
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

#  define Rte_IRead_MotMeclPosn1_Per2_MotMeclPosn1RawErrReg_Cnt_u16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_MotMeclPosn1_MotMeclPosn1_Per2.Rte_MotMeclPosn1RawErrReg_Cnt_u16.value)

#  define Rte_IRead_MotMeclPosn1_Per2_ParityFaultAccum_Cnt_u16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_MotMeclPosn1_MotMeclPosn1_Per2.Rte_ParityFaultAccum_Cnt_u16.value)

#  define Rte_IRead_MotMeclPosn1_Per2_UnderVltgFaultAccum_Cnt_u16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_MotMeclPosn1_MotMeclPosn1_Per2.Rte_UnderVltgFaultAccum_Cnt_u16.value)

#  define Rte_IWrite_MotMeclPosn1_Per2_MotPosnQlfr_State_enum(data) \
  ( \
    Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_MotMeclPosn1_MotPosnQlfr_State_enum.value = (data) \
  )

#  define Rte_IWriteRef_MotMeclPosn1_Per2_MotPosnQlfr_State_enum() \
  (&Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_MotMeclPosn1_MotPosnQlfr_State_enum.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(UInt8 parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus);
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_MotMeclPosn1CoeffTblBlk_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((UInt8)17, arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_MotMeclPosn1CoeffTblBlk_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)17, arg1))
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

extern VAR(DT_MotMeclPosnCoeffTbl_f32, RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP) Rte_Sa_MotMeclPosn1_MotMeclPosn1CoeffTblData;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_MotMeclPosn1CoeffTblData() (&((*RtePim_MotMeclPosn1CoeffTblData())[0]))
#  else
#   define Rte_Pim_MotMeclPosn1CoeffTblData() RtePim_MotMeclPosn1CoeffTblData()
#  endif
#  define RtePim_MotMeclPosn1CoeffTblData() \
  (&Rte_Sa_MotMeclPosn1_MotMeclPosn1CoeffTblData)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_MOTMECLPOSN1_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Init(void);

FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Per2(void);

FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Per3(void);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Scom_ReadMotMeclPosn1CoeffTbl(P2VAR(Float, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTbl, P2VAR(UInt16, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed);
# else
FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Scom_ReadMotMeclPosn1CoeffTbl(P2VAR(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTbl, P2VAR(UInt16, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(P2CONST(Float, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_DATA) MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTblResp);
# else
FUNC(void, RTE_SA_MOTMECLPOSN1_APPL_CODE) MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(P2CONST(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_DATA) MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_SA_MOTMECLPOSN1_APPL_VAR) MotMeclPosn1CoeffTblResp);
# endif

# define RTE_STOP_SEC_SA_MOTMECLPOSN1_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

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
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Sa_MotMeclPosn1.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_MOTMECLPOSN1_H */
