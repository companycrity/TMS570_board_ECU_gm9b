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
 *          File:  Components/Rte_Ap_SrlComInput.h
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
#ifndef _RTE_AP_SRLCOMINPUT_H
# define _RTE_AP_SRLCOMINPUT_H

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
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_APAMfgEnable_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_APANonRecoverableFaults_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_APARecoverableFaults_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_APARequest_Cnt_lgc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_SrlComInput_DesiredTunPers_Cnt_u16;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_ESCCmd_HwNm_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_ESCFault_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_ESCMfgEnable_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_ESCRequest_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_EngRunAtvForCTCInhibit_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_HapticRequest_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_LKACmd_HwNm_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_LKAFault_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_LKAInhibit_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_LKAMfgEnable_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_LKARequest_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_MaxSecureVehicleSpeed_Kph_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_MinSecureVehicleSpeed_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_PowertrainCrankActive_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SPMForCTCInhibit_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SWARTrgtAngRequest_HwDeg_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_ShiftLeverIsInReverse_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComABSActive_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComAmbTemp_DegC_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComESCActive_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComEngOn_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComEngTemp_DegC_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComEngineSpeed_Rpm_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComLWhlSpd_Hz_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComLatAccel_MpSecSq_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComLatAccelValid_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComRWhlSpd_Hz_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComSPMOn_Cnt_lgc;
extern VAR(SysPwrMd, RTE_VAR_INIT) Rte_SrlComInput_SrlComSysPwrMd_Cnt_enum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComTCSActive_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComTSMitDefeat_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComTransmissionTrq_TransNm_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComVehLonAccelValid_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComVehSpd_Kph_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComVehicleLonAccel_MpSecSq_f32;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComYawRate_DegpS_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComYawRateValid_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_StrtStopFaultActive_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_VehicleSpeedValid_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComOutput_BusOffCE_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComOutput_BusOffHS_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsDefVehSpd_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DiagMgr_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_RxMsgsSrlComSvcDft_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_WIRMfgEnabled_Cnt_lgc;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_APAMfgEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_APANonRecoverableFaults_Cnt_lgc (FALSE)
#  define Rte_InitValue_APARecoverableFaults_Cnt_lgc (FALSE)
#  define Rte_InitValue_APARequest_Cnt_lgc (FALSE)
#  define Rte_InitValue_BusOffCE_Cnt_lgc (FALSE)
#  define Rte_InitValue_BusOffHS_Cnt_lgc (FALSE)
#  define Rte_InitValue_DesiredTunPers_Cnt_u16 (0U)
#  define Rte_InitValue_DiagStsDefVehSpd_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc (FALSE)
#  define Rte_InitValue_ESCCmd_HwNm_f32 (0.0F)
#  define Rte_InitValue_ESCFault_Cnt_lgc (FALSE)
#  define Rte_InitValue_ESCMfgEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_ESCRequest_Cnt_lgc (FALSE)
#  define Rte_InitValue_EngRunAtvForCTCInhibit_Cnt_lgc (FALSE)
#  define Rte_InitValue_HapticRequest_Cnt_lgc (FALSE)
#  define Rte_InitValue_LKACmd_HwNm_f32 (0.0F)
#  define Rte_InitValue_LKAFault_Cnt_lgc (FALSE)
#  define Rte_InitValue_LKAInhibit_Cnt_lgc (FALSE)
#  define Rte_InitValue_LKAMfgEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_LKARequest_Cnt_lgc (FALSE)
#  define Rte_InitValue_MaxSecureVehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_MinSecureVehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_PowertrainCrankActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_PrevSrlComEngOn_Cnt_lgc (FALSE)
#  define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_SPMForCTCInhibit_Cnt_lgc (FALSE)
#  define Rte_InitValue_SWARTrgtAngRequest_HwDeg_f32 (0.0F)
#  define Rte_InitValue_ShiftLeverIsInReverse_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComABSActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComAmbTemp_DegC_f32 (0.0F)
#  define Rte_InitValue_SrlComESCActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComEngOn_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComEngTemp_DegC_f32 (0.0F)
#  define Rte_InitValue_SrlComEngineSpeed_Rpm_f32 (0.0F)
#  define Rte_InitValue_SrlComLWhlSpd_Hz_f32 (0.0F)
#  define Rte_InitValue_SrlComLWhlSpdVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComLatAccel_MpSecSq_f32 (0.0F)
#  define Rte_InitValue_SrlComLatAccelValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComRWhlSpd_Hz_f32 (0.0F)
#  define Rte_InitValue_SrlComRWhlSpdVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComSPMOn_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComSysPwrMd_Cnt_enum (0U)
#  define Rte_InitValue_SrlComTCSActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComTSMitDefeat_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComTransmissionTrq_TransNm_f32 (0.0F)
#  define Rte_InitValue_SrlComVehLonAccelValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComVehSpd_Kph_f32 (0.0F)
#  define Rte_InitValue_SrlComVehicleLonAccel_MpSecSq_f32 (0.0F)
#  define Rte_InitValue_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32 (0.0F)
#  define Rte_InitValue_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32 (0.0F)
#  define Rte_InitValue_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32 (0.0F)
#  define Rte_InitValue_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32 (0.0F)
#  define Rte_InitValue_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComYawRate_DegpS_f32 (0.0F)
#  define Rte_InitValue_SrlComYawRateValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_StrtStopFaultActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
#  define Rte_InitValue_WIREnabled_Cnt_lgc (FALSE)
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



# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BusOffCE_Cnt_lgc Rte_Read_Ap_SrlComInput_BusOffCE_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_BusOffCE_Cnt_lgc(data) (*(data) = Rte_SrlComOutput_BusOffCE_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_BusOffHS_Cnt_lgc Rte_Read_Ap_SrlComInput_BusOffHS_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_BusOffHS_Cnt_lgc(data) (*(data) = Rte_SrlComOutput_BusOffHS_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DiagStsDefVehSpd_Cnt_lgc Rte_Read_Ap_SrlComInput_DiagStsDefVehSpd_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_DiagStsDefVehSpd_Cnt_lgc(data) (*(data) = Rte_DiagMgr_DiagStsDefVehSpd_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc Rte_Read_Ap_SrlComInput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(data) (*(data) = Rte_DiagMgr_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_PrevSrlComEngOn_Cnt_lgc Rte_Read_Ap_SrlComInput_PrevSrlComEngOn_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_PrevSrlComEngOn_Cnt_lgc(data) (*(data) = Rte_SrlComInput_SrlComEngOn_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc Rte_Read_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_RxMsgsSrlComSvcDft_Cnt_lgc(data) (*(data) = Rte_CDDInterface_RxMsgsSrlComSvcDft_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_WIREnabled_Cnt_lgc Rte_Read_Ap_SrlComInput_WIREnabled_Cnt_lgc
#  define Rte_Read_Ap_SrlComInput_WIREnabled_Cnt_lgc(data) (*(data) = Rte_CDDInterface_WIRMfgEnabled_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_APAMfgEnable_Cnt_lgc Rte_Write_Ap_SrlComInput_APAMfgEnable_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_APAMfgEnable_Cnt_lgc(data) (Rte_SrlComInput_APAMfgEnable_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_APANonRecoverableFaults_Cnt_lgc Rte_Write_Ap_SrlComInput_APANonRecoverableFaults_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_APANonRecoverableFaults_Cnt_lgc(data) (Rte_SrlComInput_APANonRecoverableFaults_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_APARecoverableFaults_Cnt_lgc Rte_Write_Ap_SrlComInput_APARecoverableFaults_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_APARecoverableFaults_Cnt_lgc(data) (Rte_SrlComInput_APARecoverableFaults_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_APARequest_Cnt_lgc Rte_Write_Ap_SrlComInput_APARequest_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_APARequest_Cnt_lgc(data) (Rte_SrlComInput_APARequest_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_DesiredTunPers_Cnt_u16 Rte_Write_Ap_SrlComInput_DesiredTunPers_Cnt_u16
#  define Rte_Write_Ap_SrlComInput_DesiredTunPers_Cnt_u16(data) (Rte_SrlComInput_DesiredTunPers_Cnt_u16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ESCCmd_HwNm_f32 Rte_Write_Ap_SrlComInput_ESCCmd_HwNm_f32
#  define Rte_Write_Ap_SrlComInput_ESCCmd_HwNm_f32(data) (Rte_SrlComInput_ESCCmd_HwNm_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ESCFault_Cnt_lgc Rte_Write_Ap_SrlComInput_ESCFault_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_ESCFault_Cnt_lgc(data) (Rte_SrlComInput_ESCFault_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ESCMfgEnable_Cnt_lgc Rte_Write_Ap_SrlComInput_ESCMfgEnable_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_ESCMfgEnable_Cnt_lgc(data) (Rte_SrlComInput_ESCMfgEnable_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ESCRequest_Cnt_lgc Rte_Write_Ap_SrlComInput_ESCRequest_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_ESCRequest_Cnt_lgc(data) (Rte_SrlComInput_ESCRequest_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_EngRunAtvForCTCInhibit_Cnt_lgc Rte_Write_Ap_SrlComInput_EngRunAtvForCTCInhibit_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_EngRunAtvForCTCInhibit_Cnt_lgc(data) (Rte_SrlComInput_EngRunAtvForCTCInhibit_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HapticRequest_Cnt_lgc Rte_Write_Ap_SrlComInput_HapticRequest_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_HapticRequest_Cnt_lgc(data) (Rte_SrlComInput_HapticRequest_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_LKACmd_HwNm_f32 Rte_Write_Ap_SrlComInput_LKACmd_HwNm_f32
#  define Rte_Write_Ap_SrlComInput_LKACmd_HwNm_f32(data) (Rte_SrlComInput_LKACmd_HwNm_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_LKAFault_Cnt_lgc Rte_Write_Ap_SrlComInput_LKAFault_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_LKAFault_Cnt_lgc(data) (Rte_SrlComInput_LKAFault_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_LKAInhibit_Cnt_lgc Rte_Write_Ap_SrlComInput_LKAInhibit_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_LKAInhibit_Cnt_lgc(data) (Rte_SrlComInput_LKAInhibit_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_LKAMfgEnable_Cnt_lgc Rte_Write_Ap_SrlComInput_LKAMfgEnable_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_LKAMfgEnable_Cnt_lgc(data) (Rte_SrlComInput_LKAMfgEnable_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_LKARequest_Cnt_lgc Rte_Write_Ap_SrlComInput_LKARequest_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_LKARequest_Cnt_lgc(data) (Rte_SrlComInput_LKARequest_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MaxSecureVehicleSpeed_Kph_f32 Rte_Write_Ap_SrlComInput_MaxSecureVehicleSpeed_Kph_f32
#  define Rte_Write_Ap_SrlComInput_MaxSecureVehicleSpeed_Kph_f32(data) (Rte_SrlComInput_MaxSecureVehicleSpeed_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MinSecureVehicleSpeed_Kph_f32 Rte_Write_Ap_SrlComInput_MinSecureVehicleSpeed_Kph_f32
#  define Rte_Write_Ap_SrlComInput_MinSecureVehicleSpeed_Kph_f32(data) (Rte_SrlComInput_MinSecureVehicleSpeed_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PowertrainCrankActive_Cnt_lgc Rte_Write_Ap_SrlComInput_PowertrainCrankActive_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_PowertrainCrankActive_Cnt_lgc(data) (Rte_SrlComInput_PowertrainCrankActive_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SPMForCTCInhibit_Cnt_lgc Rte_Write_Ap_SrlComInput_SPMForCTCInhibit_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SPMForCTCInhibit_Cnt_lgc(data) (Rte_SrlComInput_SPMForCTCInhibit_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SWARTrgtAngRequest_HwDeg_f32 Rte_Write_Ap_SrlComInput_SWARTrgtAngRequest_HwDeg_f32
#  define Rte_Write_Ap_SrlComInput_SWARTrgtAngRequest_HwDeg_f32(data) (Rte_SrlComInput_SWARTrgtAngRequest_HwDeg_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_ShiftLeverIsInReverse_Cnt_lgc Rte_Write_Ap_SrlComInput_ShiftLeverIsInReverse_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_ShiftLeverIsInReverse_Cnt_lgc(data) (Rte_SrlComInput_ShiftLeverIsInReverse_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComABSActive_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComABSActive_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComABSActive_Cnt_lgc(data) (Rte_SrlComInput_SrlComABSActive_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComAmbTemp_DegC_f32 Rte_Write_Ap_SrlComInput_SrlComAmbTemp_DegC_f32
#  define Rte_Write_Ap_SrlComInput_SrlComAmbTemp_DegC_f32(data) (Rte_SrlComInput_SrlComAmbTemp_DegC_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComESCActive_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComESCActive_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComESCActive_Cnt_lgc(data) (Rte_SrlComInput_SrlComESCActive_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComEngOn_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComEngOn_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComEngOn_Cnt_lgc(data) (Rte_SrlComInput_SrlComEngOn_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComEngTemp_DegC_f32 Rte_Write_Ap_SrlComInput_SrlComEngTemp_DegC_f32
#  define Rte_Write_Ap_SrlComInput_SrlComEngTemp_DegC_f32(data) (Rte_SrlComInput_SrlComEngTemp_DegC_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComEngineSpeed_Rpm_f32 Rte_Write_Ap_SrlComInput_SrlComEngineSpeed_Rpm_f32
#  define Rte_Write_Ap_SrlComInput_SrlComEngineSpeed_Rpm_f32(data) (Rte_SrlComInput_SrlComEngineSpeed_Rpm_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComLWhlSpd_Hz_f32 Rte_Write_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32
#  define Rte_Write_Ap_SrlComInput_SrlComLWhlSpd_Hz_f32(data) (Rte_SrlComInput_SrlComLWhlSpd_Hz_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComLWhlSpdVld_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc(data) (Rte_SrlComInput_SrlComLWhlSpdVld_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComLatAccel_MpSecSq_f32 Rte_Write_Ap_SrlComInput_SrlComLatAccel_MpSecSq_f32
#  define Rte_Write_Ap_SrlComInput_SrlComLatAccel_MpSecSq_f32(data) (Rte_SrlComInput_SrlComLatAccel_MpSecSq_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComLatAccelValid_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComLatAccelValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComLatAccelValid_Cnt_lgc(data) (Rte_SrlComInput_SrlComLatAccelValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComRWhlSpd_Hz_f32 Rte_Write_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32
#  define Rte_Write_Ap_SrlComInput_SrlComRWhlSpd_Hz_f32(data) (Rte_SrlComInput_SrlComRWhlSpd_Hz_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComRWhlSpdVld_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc(data) (Rte_SrlComInput_SrlComRWhlSpdVld_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComSPMOn_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComSPMOn_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComSPMOn_Cnt_lgc(data) (Rte_SrlComInput_SrlComSPMOn_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComSysPwrMd_Cnt_enum Rte_Write_Ap_SrlComInput_SrlComSysPwrMd_Cnt_enum
#  define Rte_Write_Ap_SrlComInput_SrlComSysPwrMd_Cnt_enum(data) (Rte_SrlComInput_SrlComSysPwrMd_Cnt_enum = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComTCSActive_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComTCSActive_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComTCSActive_Cnt_lgc(data) (Rte_SrlComInput_SrlComTCSActive_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComTSMitDefeat_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComTSMitDefeat_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComTSMitDefeat_Cnt_lgc(data) (Rte_SrlComInput_SrlComTSMitDefeat_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComTransmissionTrq_TransNm_f32 Rte_Write_Ap_SrlComInput_SrlComTransmissionTrq_TransNm_f32
#  define Rte_Write_Ap_SrlComInput_SrlComTransmissionTrq_TransNm_f32(data) (Rte_SrlComInput_SrlComTransmissionTrq_TransNm_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehLonAccelValid_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComVehLonAccelValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComVehLonAccelValid_Cnt_lgc(data) (Rte_SrlComInput_SrlComVehLonAccelValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehSpd_Kph_f32 Rte_Write_Ap_SrlComInput_SrlComVehSpd_Kph_f32
#  define Rte_Write_Ap_SrlComInput_SrlComVehSpd_Kph_f32(data) (Rte_SrlComInput_SrlComVehSpd_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComVehicleLonAccel_MpSecSq_f32 Rte_Write_Ap_SrlComInput_SrlComVehicleLonAccel_MpSecSq_f32
#  define Rte_Write_Ap_SrlComInput_SrlComVehicleLonAccel_MpSecSq_f32(data) (Rte_SrlComInput_SrlComVehicleLonAccel_MpSecSq_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32 Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32
#  define Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32(data) (Rte_SrlComInput_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc(data) (Rte_SrlComInput_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32 Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32
#  define Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32(data) (Rte_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc(data) (Rte_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32 Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32
#  define Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32(data) (Rte_SrlComInput_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc(data) (Rte_SrlComInput_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32 Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32
#  define Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32(data) (Rte_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc(data) (Rte_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComYawRate_DegpS_f32 Rte_Write_Ap_SrlComInput_SrlComYawRate_DegpS_f32
#  define Rte_Write_Ap_SrlComInput_SrlComYawRate_DegpS_f32(data) (Rte_SrlComInput_SrlComYawRate_DegpS_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SrlComYawRateValid_Cnt_lgc Rte_Write_Ap_SrlComInput_SrlComYawRateValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_SrlComYawRateValid_Cnt_lgc(data) (Rte_SrlComInput_SrlComYawRateValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_StrtStopFaultActive_Cnt_lgc Rte_Write_Ap_SrlComInput_StrtStopFaultActive_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_StrtStopFaultActive_Cnt_lgc(data) (Rte_SrlComInput_StrtStopFaultActive_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_VehicleSpeedValid_Cnt_lgc Rte_Write_Ap_SrlComInput_VehicleSpeedValid_Cnt_lgc
#  define Rte_Write_Ap_SrlComInput_VehicleSpeedValid_Cnt_lgc(data) (Rte_SrlComInput_VehicleSpeedValid_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_Ap_StaMd9_SystemState9_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCActive(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCActive_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCActive NxtrDiagMgr9_GetNTCActive
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) Status_Ptr_T_u08);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCStatus NxtrDiagMgr9_GetNTCStatus
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr9_SetNTCStatus
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


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per2(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per3(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_GetSrlComWIRFltStatus(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) SrlComWIRFltStatus);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetBus1Timers(void);

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetBus2Timers(void);

# define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
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
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_SrlComInput.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SRLCOMINPUT_H */
