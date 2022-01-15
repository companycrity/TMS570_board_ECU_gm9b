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
 *          File:  Components/Rte_Ap_GmPwrpkSrvDataRcvry.h
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
#ifndef _RTE_AP_GMPWRPKSRVDATARCVRY_H
# define _RTE_AP_GMPWRPKSRVDATARCVRY_H

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

#  define Rte_InitValue_GetNVMSensorData_Cnt_lgc (TRUE)
#  define Rte_InitValue_NVMMotorVariant_Cnt_u08 (7U)
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

#  define Rte_IRead_GmPwrpkSrvDataRcvry_Per1_GetNVMSensorData_Cnt_lgc() \
  (Rte_Task_100ms_10.Rte_RB.Rte_Ap_GmPwrpkSrvDataRcvry_GmPwrpkSrvDataRcvry_Per1.Rte_GetNVMSensorData_Cnt_lgc.value)

#  define Rte_IRead_GmPwrpkSrvDataRcvry_Per1_NVMMotorVariant_Cnt_u08() \
  (Rte_Task_100ms_10.Rte_RB.Rte_Ap_GmPwrpkSrvDataRcvry_GmPwrpkSrvDataRcvry_Per1.Rte_NVMMotorVariant_Cnt_u08.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_ReadAnaHwTrqScaleTrim(P2VAR(AnaHwTrqScale_Datatype, AUTOMATIC, RTE_SA_ANAHWTRQ_APPL_VAR) HwTrqScaleDataPtr);
#  define RTE_STOP_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_AnaHwTrq_SCom_ReadAnaHwTrqScaleTrim(arg1) (AnaHwTrq_SCom_ReadAnaHwTrqScaleTrim(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_ReadT1T2OffsetTrim(P2VAR(AnaHwTrqTrim_Datatype, AUTOMATIC, RTE_SA_ANAHWTRQ_APPL_VAR) HwTrqTrimDataPtr);
#  define RTE_STOP_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_AnaHwTrq_SCom_ReadT1T2OffsetTrim(arg1) (AnaHwTrq_SCom_ReadT1T2OffsetTrim(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_SetAnaHwTrqScaleTrim(Float ScaleValue);
#  define RTE_STOP_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim AnaHwTrq_SCom_SetAnaHwTrqScaleTrim
#  define RTE_START_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_WriteT1T2OffsetTrim(P2CONST(AnaHwTrqTrim_Datatype, AUTOMATIC, RTE_SA_ANAHWTRQ_APPL_DATA) HwTrqTrimDataPtr);
#  define RTE_STOP_SEC_SA_ANAHWTRQ_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_AnaHwTrq_SCom_WriteT1T2OffsetTrim AnaHwTrq_SCom_WriteT1T2OffsetTrim
#  define RTE_START_SEC_SA_HWTRQARBN_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_SA_HWTRQARBN_APPL_CODE) HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(P2CONST(EOLChOffsetTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQARBN_APPL_DATA) EOLChOffsetTrimDataPtr, UInt8 HwTqTrmchNr_Cnt_u08);
#  define RTE_STOP_SEC_SA_HWTRQARBN_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus
#  define RTE_START_SEC_SA_DIGCOLPS_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) PhaNvmRead_GetData(P2VAR(Boolean, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) ColCustDataReadCmpl_Cnt_lgc, P2VAR(Boolean, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) SpurCustDataReadCmpl_Cnt_lgc, P2VAR(UInt32, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) ColCustData_Uls_u32, P2VAR(UInt32, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) SpurCustData_Uls_u32);
# else
FUNC(void, RTE_SA_DIGCOLPS_APPL_CODE) PhaNvmRead_GetData(P2VAR(CustReadCmplType, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) ColCustDataReadCmpl_Cnt_lgc, P2VAR(CustReadCmplType, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) SpurCustDataReadCmpl_Cnt_lgc, P2VAR(CustDataType, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) ColCustData_Uls_u32, P2VAR(CustDataType, AUTOMATIC, RTE_SA_DIGCOLPS_APPL_VAR) SpurCustData_Uls_u32);
# endif
#  define RTE_STOP_SEC_SA_DIGCOLPS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_PhaNvmRead_GetData(arg1, arg2, arg3, arg4) (PhaNvmRead_GetData(arg1, arg2, arg3, arg4), ((Std_ReturnType)RTE_E_OK))
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


# define RTE_START_SEC_AP_GMPWRPKSRVDATARCVRY_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_GMPWRPKSRVDATARCVRY_APPL_CODE) GmPwrpkSrvDataRcvry_Per1(void);

FUNC(void, RTE_AP_GMPWRPKSRVDATARCVRY_APPL_CODE) GmPwrpkSrvDataRcvry_Trns1(void);

# define RTE_STOP_SEC_AP_GMPWRPKSRVDATARCVRY_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_AnaHwTrq_SCom_DataOutOfRange (20U)

#  define RTE_E_HwTrqArbn_SCom_DataOutOfRange (20U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_GmPwrpkSrvDataRcvry.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_GMPWRPKSRVDATARCVRY_H */
