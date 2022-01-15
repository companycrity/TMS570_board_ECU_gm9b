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
 *          File:  Components/Rte_Sa_CDDInterface.h
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
#ifndef _RTE_SA_CDDINTERFACE_H
# define _RTE_SA_CDDINTERFACE_H

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
extern VAR(UInt16, RTE_VAR_INIT) Rte_CDDInterface_MotorVariant_Cnt_u16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_CDDInterface_NVMMotorVariant_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_CDDInterface_NVMSensorData_Cnt_lgc;

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
#  define Rte_InitValue_AssistAssemblyPolarity_Cnt_s08 (0)
#  define Rte_InitValue_BallNutTempEstSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_CommOffset_Cnt_u16 (0U)
#  define Rte_InitValue_CorrMtrCurrA_Amp_f32 (0.0F)
#  define Rte_InitValue_CorrMtrCurrB_Amp_f32 (0.0F)
#  define Rte_InitValue_CorrMtrCurrC_Amp_f32 (0.0F)
#  define Rte_InitValue_CorrMtrCurrPosition_Rev_f32 (0.0F)
#  define Rte_InitValue_CorrectedElecMtrPosFloat_Rev_f32 (0.0F)
#  define Rte_InitValue_DampingSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_DftAsstTbl_Cnt_lgc (FALSE)
#  define Rte_InitValue_DigMSBArbnMtrPosMecl_Rev_f32 (0.0F)
#  define Rte_InitValue_DisableCEBusNormComm_Cnt_lgc (FALSE)
#  define Rte_InitValue_DisableHSBusNormComm_Cnt_lgc (FALSE)
#  define Rte_InitValue_DrivingDynSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_DwnldAsstGain_Uls_f32 (0.0F)
#  define Rte_InitValue_EOTImpactSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_EOTThermalSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_EngONSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_ExpectedOnTimeA_Cnt_u32 (0U)
#  define Rte_InitValue_ExpectedOnTimeB_Cnt_u32 (0U)
#  define Rte_InitValue_ExpectedOnTimeC_Cnt_u32 (0U)
#  define Rte_InitValue_FeatureControl_Cnt_lgc (TRUE)
#  define Rte_InitValue_FreqDepDmpSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_FricLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_HysAddSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_HystCompSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_IgnCnt_Cnt_u16 (0U)
#  define Rte_InitValue_IvtrLoaMtgtnEn_Cnt_lgc (FALSE)
#  define Rte_InitValue_KinIntDiagSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_LRPRPhaseadvanceCaptured_Cnt_s16 (0)
#  define Rte_InitValue_LimitSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MEC_Cnt_enum (0U)
#  define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_MfgDiagInhibit_Cnt_lgc (FALSE)
#  define Rte_InitValue_ModIdxFinal_Uls_f32 (0.0F)
#  define Rte_InitValue_ModIdxSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MotAgCorrlnMtrPosCorrlnSts_Cnt_u16 (7U)
#  define Rte_InitValue_MotCurrLoaMtgtnEn_Cnt_lgc (FALSE)
#  define Rte_InitValue_MotMeclPosn1MeasdTi_USec_u32 (0U)
#  define Rte_InitValue_MotMeclPosn1MotPosnQlfr_State_enum (0U)
#  define Rte_InitValue_MotMeclPosn1ParityFaultAccum_Cnt_u16 (0U)
#  define Rte_InitValue_MotMeclPosn1Polarity_Cnt_s08 (0)
#  define Rte_InitValue_MotMeclPosn1RawErrReg_Cnt_u16 (0U)
#  define Rte_InitValue_MotMeclPosn1RevM_Rev_u0p16 (0U)
#  define Rte_InitValue_MotMeclPosn1RollgCntr_Cnt_u08 (0U)
#  define Rte_InitValue_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16 (0U)
#  define Rte_InitValue_MotMeclPosn2MeasdTi_USec_u32 (0U)
#  define Rte_InitValue_MotMeclPosn2MotPosnQlfr_State_enum (0U)
#  define Rte_InitValue_MotMeclPosn2ParityFaultAccum_Cnt_u16 (0U)
#  define Rte_InitValue_MotMeclPosn2Polarity_Cnt_s08 (0)
#  define Rte_InitValue_MotMeclPosn2RawErrReg_Cnt_u16 (0U)
#  define Rte_InitValue_MotMeclPosn2RevM_Rev_u0p16 (0U)
#  define Rte_InitValue_MotMeclPosn2RollgCntr_Cnt_u08 (0U)
#  define Rte_InitValue_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16 (0U)
#  define Rte_InitValue_MotPosnCmpMotPosnCumvAlgnd_Rev_f32 (0.0F)
#  define Rte_InitValue_MotPosnCmpMotPosnElec_Rev_u0p16 (0U)
#  define Rte_InitValue_MotorVariant_Cnt_u16 (0U)
#  define Rte_InitValue_MtrCtrlMtrDaxVoltage_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrCtrlMtrQaxVoltage_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrCurrATempOffset_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrCurrBTempOffset_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrCurrCTempOffset_Volt_f32 (0.0F)
#  define Rte_InitValue_MtrCurrDax_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQax_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQaxFinalRef_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrElecMechPolarity_Cnt_s08 (0)
#  define Rte_InitValue_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrPosPolarity_Cnt_s08 (0)
#  define Rte_InitValue_MtrTrqCmdSign_Cnt_s16 (0)
#  define Rte_InitValue_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MultIgnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_NVMMotorVariant_Cnt_u08 (7U)
#  define Rte_InitValue_NVMSensorData_Cnt_lgc (TRUE)
#  define Rte_InitValue_ParkAstSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_PosTrajEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PullCompLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_PullCompSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_ReturnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_RxMsgsSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_SftEndStpSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComSvcDft_Cnt_b32 (0U)
#  define Rte_InitValue_SysCBattSwitched1_Cnt_u16 (0U)
#  define Rte_InitValue_SysCBattSwitched2_Cnt_u16 (0U)
#  define Rte_InitValue_SysCT1ADC_Cnt_u16 (0U)
#  define Rte_InitValue_SysCT2ADC_Cnt_u16 (0U)
#  define Rte_InitValue_ThermalDCSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_TrqRmpSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_Vecu_Volt_f32 (5.0F)
#  define Rte_InitValue_WIRMfgEnabled_Cnt_lgc (FALSE)
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

extern VAR(Rte_tsTask_Init_10, RTE_VAR_NOINIT) Rte_Task_Init_10;

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

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

#  define Rte_IWrite_CDDInterface_Init1_IgnCnt_Cnt_u16(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Init1.Rte_IgnCnt_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Init1_IgnCnt_Cnt_u16() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Init1.Rte_IgnCnt_Cnt_u16.value)

#  define Rte_IRead_CDDInterface_Init2_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Init2.Rte_MtrElecMechPolarity_Cnt_s08.value)

#  define Rte_IRead_CDDInterface_Init2_MtrPosPolarity_Cnt_s08() \
  (Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Init2.Rte_MtrPosPolarity_Cnt_s08.value)

#  define Rte_IWrite_CDDInterface_Init2_MEC_Cnt_enum(data) \
  ( \
    Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Init2.Rte_MEC_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Init2_MEC_Cnt_enum() \
  (&Rte_Task_Init_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Init2.Rte_MEC_Cnt_enum.value)

#  define Rte_IWrite_CDDInterface_Per1_ADCMtrCurrA_Volt_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurrA_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurrA_Volt_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurrA_Volt_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_ADCMtrCurrB_Volt_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurrB_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurrB_Volt_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurrB_Volt_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_ADCMtrCurrC_Volt_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurrC_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurrC_Volt_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ADCMtrCurrC_Volt_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_CorrMtrCurrA_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrA_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_CorrMtrCurrA_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrA_Amp_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_CorrMtrCurrB_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrB_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_CorrMtrCurrB_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrB_Amp_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_CorrMtrCurrC_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrC_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_CorrMtrCurrC_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrC_Amp_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_CorrMtrCurrPosition_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrPosition_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_CorrMtrCurrPosition_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrMtrCurrPosition_Rev_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_CorrectedElecMtrPosFloat_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrectedElecMtrPosFloat_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_CorrectedElecMtrPosFloat_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_CorrectedElecMtrPosFloat_Rev_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_DigMSBArbnMtrPosMecl_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_DigMSBArbnMtrPosMecl_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_DigMSBArbnMtrPosMecl_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_DigMSBArbnMtrPosMecl_Rev_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeA_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeA_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeB_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeB_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeC_Cnt_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ExpectedOnTimeC_Cnt_u32.value)

#  define Rte_IWrite_CDDInterface_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_LRPRPhaseadvanceCaptured_Cnt_s16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_LRPRPhaseadvanceCaptured_Cnt_s16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_LRPRPhaseadvanceCaptured_Cnt_s16.value)

#  define Rte_IWrite_CDDInterface_Per1_ModIdxFinal_Uls_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ModIdxFinal_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_ModIdxFinal_Uls_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_ModIdxFinal_Uls_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MotMeclPosn1MeasdTi_USec_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1MeasdTi_USec_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn1MeasdTi_USec_u32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1MeasdTi_USec_u32.value)

#  define Rte_IWrite_CDDInterface_Per1_MotMeclPosn1ParityFaultAccum_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1ParityFaultAccum_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn1ParityFaultAccum_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1ParityFaultAccum_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface_Per1_MotMeclPosn1RawErrReg_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1RawErrReg_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn1RawErrReg_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1RawErrReg_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface_Per1_MotMeclPosn1RevM_Rev_u0p16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1RevM_Rev_u0p16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn1RevM_Rev_u0p16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1RevM_Rev_u0p16.value)

#  define Rte_IWrite_CDDInterface_Per1_MotMeclPosn1RollgCntr_Cnt_u08(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1RollgCntr_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn1RollgCntr_Cnt_u08() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1RollgCntr_Cnt_u08.value)

#  define Rte_IWrite_CDDInterface_Per1_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface_Per1_MotMeclPosn2MeasdTi_USec_u32(data) \
  ( \
    Rte_Task_2ms_10.Rte_TB.Rte_I_CDDInterface_MotMeclPosn2MeasdTi_USec_u32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn2MeasdTi_USec_u32() \
  (&Rte_Task_2ms_10.Rte_TB.Rte_I_CDDInterface_MotMeclPosn2MeasdTi_USec_u32.value)

#  define Rte_IWrite_CDDInterface_Per1_MotMeclPosn2ParityFaultAccum_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn2ParityFaultAccum_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn2ParityFaultAccum_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn2ParityFaultAccum_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface_Per1_MotMeclPosn2RawErrReg_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn2RawErrReg_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn2RawErrReg_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn2RawErrReg_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface_Per1_MotMeclPosn2RevM_Rev_u0p16(data) \
  ( \
    Rte_Task_2ms_10.Rte_TB.Rte_I_CDDInterface_MotMeclPosn2RevM_Rev_u0p16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn2RevM_Rev_u0p16() \
  (&Rte_Task_2ms_10.Rte_TB.Rte_I_CDDInterface_MotMeclPosn2RevM_Rev_u0p16.value)

#  define Rte_IWrite_CDDInterface_Per1_MotMeclPosn2RollgCntr_Cnt_u08(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn2RollgCntr_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn2RollgCntr_Cnt_u08() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn2RollgCntr_Cnt_u08.value)

#  define Rte_IWrite_CDDInterface_Per1_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface_Per1_MotPosnCmpMotPosnCumvAlgnd_Rev_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotPosnCmpMotPosnCumvAlgnd_Rev_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotPosnCmpMotPosnCumvAlgnd_Rev_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotPosnCmpMotPosnCumvAlgnd_Rev_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MotPosnCmpMotPosnElec_Rev_u0p16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotPosnCmpMotPosnElec_Rev_u0p16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MotPosnCmpMotPosnElec_Rev_u0p16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MotPosnCmpMotPosnElec_Rev_u0p16.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrCtrlMtrDaxVoltage_Volt_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCtrlMtrDaxVoltage_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrCtrlMtrDaxVoltage_Volt_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCtrlMtrDaxVoltage_Volt_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrCtrlMtrQaxVoltage_Volt_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCtrlMtrQaxVoltage_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrCtrlMtrQaxVoltage_Volt_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCtrlMtrQaxVoltage_Volt_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrCurrDax_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrDax_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrCurrDax_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrDax_Amp_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrCurrQaxFinalRef_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrQaxFinalRef_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrCurrQaxFinalRef_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrQaxFinalRef_Amp_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_MtrCurrQax_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrQax_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_MtrCurrQax_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_MtrCurrQax_Amp_f32.value)

#  define Rte_IWrite_CDDInterface_Per1_SysCBattSwitched1_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCBattSwitched1_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_SysCBattSwitched1_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCBattSwitched1_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface_Per1_SysCBattSwitched2_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCBattSwitched2_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_SysCBattSwitched2_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCBattSwitched2_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface_Per1_SysCT1ADC_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCT1ADC_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_SysCT1ADC_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCT1ADC_Cnt_u16.value)

#  define Rte_IWrite_CDDInterface_Per1_SysCT2ADC_Cnt_u16(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCT2ADC_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per1_SysCT2ADC_Cnt_u16() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per1.Rte_SysCT2ADC_Cnt_u16.value)

#  define Rte_IRead_CDDInterface_Per2_AssistAssemblyPolarity_Cnt_s08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_AssistAssemblyPolarity_Cnt_s08.value)

#  define Rte_IRead_CDDInterface_Per2_CommOffset_Cnt_u16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_CommOffset_Cnt_u16.value)

#  define Rte_IRead_CDDInterface_Per2_IvtrLoaMtgtnEn_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_LoaMgr_IvtrLoaMtgtnEn_Cnt_lgc.value)

#  define Rte_IRead_CDDInterface_Per2_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Sa_MtrVel_MotorVelMRF_MtrRadpS_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MotAgCorrlnMtrPosCorrlnSts_Cnt_u16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MotAgCorrlnMtrPosCorrlnSts_Cnt_u16.value)

#  define Rte_IRead_CDDInterface_Per2_MotCurrLoaMtgtnEn_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_LoaMgr_MotCurrLoaMtgtnEn_Cnt_lgc.value)

#  define Rte_IRead_CDDInterface_Per2_MotMeclPosn1MotPosnQlfr_State_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MotMeclPosn1MotPosnQlfr_State_enum.value)

#  define Rte_IRead_CDDInterface_Per2_MotMeclPosn1Polarity_Cnt_s08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MotMeclPosn1Polarity_Cnt_s08.value)

#  define Rte_IRead_CDDInterface_Per2_MotMeclPosn2MotPosnQlfr_State_enum() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MotMeclPosn2MotPosnQlfr_State_enum.value)

#  define Rte_IRead_CDDInterface_Per2_MotMeclPosn2Polarity_Cnt_s08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MotMeclPosn2Polarity_Cnt_s08.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurrATempOffset_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurrATempOffset_Volt_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurrBTempOffset_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurrBTempOffset_Volt_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrCurrCTempOffset_Volt_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrCurrCTempOffset_Volt_f32.value)

#  define Rte_IRead_CDDInterface_Per2_MtrPosPolarity_Cnt_s08() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrPosPolarity_Cnt_s08.value)

#  define Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_Cnt_s16() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per2.Rte_MtrTrqCmdSign_Cnt_s16.value)

#  define Rte_IRead_CDDInterface_Per2_Vecu_Volt_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_Ap_BattVltg_BrdgVltg_Volt_f32.value)

#  define Rte_IRead_CDDInterface_Per4_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrElecMechPolarity_Cnt_s08.value)

#  define Rte_IWrite_CDDInterface_Per4_BallNutTempEstSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_BallNutTempEstSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_BallNutTempEstSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_BallNutTempEstSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DampingSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DampingSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_DftAsstTbl_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DftAsstTbl_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_DftAsstTbl_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DftAsstTbl_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_DisableCEBusNormComm_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DisableCEBusNormComm_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_DisableCEBusNormComm_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DisableCEBusNormComm_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_DisableHSBusNormComm_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DisableHSBusNormComm_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_DisableHSBusNormComm_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DisableHSBusNormComm_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DrivingDynSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DrivingDynSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_DwnldAsstGain_Uls_f32(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DwnldAsstGain_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_DwnldAsstGain_Uls_f32() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_DwnldAsstGain_Uls_f32.value)

#  define Rte_IWrite_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EOTImpactSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EOTImpactSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EOTThermalSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EOTThermalSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EngONSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_EngONSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_FeatureControl_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FeatureControl_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_FeatureControl_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FeatureControl_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FreqDepDmpSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_FricLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FricLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_FricLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_FricLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_HysAddSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_HysAddSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_HystCompSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_HystCompSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_KinIntDiagSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_KinIntDiagSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_LimitSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_LimitSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_MEC_Cnt_enum(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MEC_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_MEC_Cnt_enum() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MEC_Cnt_enum.value)

#  define Rte_IWrite_CDDInterface_Per4_MfgDiagInhibit_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MfgDiagInhibit_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_MfgDiagInhibit_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MfgDiagInhibit_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ModIdxSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ModIdxSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MultIgnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_MultIgnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ParkAstSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ParkAstSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_PosTrajEnable_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_PosTrajEnable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_PosTrajEnable_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_PosTrajEnable_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_PullCompLrnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_PullCompLrnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_PullCompLrnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_PullCompLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_PullCompSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_PullCompSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ReturnSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ReturnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_RxMsgsSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_RxMsgsSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_SftEndStpSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_SftEndStpSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_SftEndStpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_SftEndStpSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_SrlComSvcDft_Cnt_b32(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_SrlComSvcDft_Cnt_b32.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_SrlComSvcDft_Cnt_b32() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_SrlComSvcDft_Cnt_b32.value)

#  define Rte_IWrite_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ThermalDCSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_ThermalDCSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_TrqRmpSrlComSvcDft_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_TrqRmpSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IWrite_CDDInterface_Per4_WIRMfgEnabled_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_WIRMfgEnabled_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CDDInterface_Per4_WIRMfgEnabled_Cnt_lgc() \
  (&Rte_Task_10ms_10.Rte_RB.Rte_Sa_CDDInterface_CDDInterface_Per4.Rte_WIRMfgEnabled_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_MotorVariant_Cnt_u16 Rte_Write_Sa_CDDInterface_MotorVariant_Cnt_u16
#  define Rte_Write_Sa_CDDInterface_MotorVariant_Cnt_u16(data) (Rte_CDDInterface_MotorVariant_Cnt_u16 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_NVMMotorVariant_Cnt_u08 Rte_Write_Sa_CDDInterface_NVMMotorVariant_Cnt_u08
#  define Rte_Write_Sa_CDDInterface_NVMMotorVariant_Cnt_u08(data) (Rte_CDDInterface_NVMMotorVariant_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_NVMSensorData_Cnt_lgc Rte_Write_Sa_CDDInterface_NVMSensorData_Cnt_lgc
#  define Rte_Write_Sa_CDDInterface_NVMSensorData_Cnt_lgc(data) (Rte_CDDInterface_NVMSensorData_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CDD_APPL_CODE) CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8);
#  define RTE_STOP_SEC_CDD_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CDDPorts_ApplyMtrElecMechPol(arg1) (CDDPorts_ApplyMtrElecMechPol(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_CDD_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CDD_APPL_CODE) CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16);
#  define RTE_STOP_SEC_CDD_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CDDPorts_ClearPhsReasSum(arg1) (CDDPorts_ClearPhsReasSum(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_CD_PHASEFDBKMEAS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CD_PHASEFDBKMEAS_APPL_CODE) Get_PhaseFdbk_PhaseFdbk(void);
#  define RTE_STOP_SEC_CD_PHASEFDBKMEAS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_Get_PhaseFdbk_PhaseFdbk() (Get_PhaseFdbk_PhaseFdbk(), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NEXTEERLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NEXTEERLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NEXTEERLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_SA_CDDINTERFACE_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Init1(void);

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Init2(void);

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Init3(void);

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per1(void);

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per2(void);

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per4(void);

# define RTE_STOP_SEC_SA_CDDINTERFACE_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Sa_CDDInterface.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CDDINTERFACE_H */
