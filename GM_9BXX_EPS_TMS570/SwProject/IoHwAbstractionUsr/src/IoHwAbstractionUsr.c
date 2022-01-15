/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  IoHwAbstractionUsr.c
 *     Workspace:  C:/_synergy/9BXX_CZ8L9T/GM_9BXX_EPS_TMS570/SwProject/IoHwAbstractionUsr/autosar
 *     SW-C Type:  IoHwAbstractionUsr
 *  Generated at:  Wed Nov 18 09:51:55 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <IoHwAbstractionUsr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 18 18:34:17 2011
 * %version:          EA3#5 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Tue Oct  8 10:24:48 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 10/15/15  4        GMN       EA3#3871: Use k_ADCVbattSwitchScaling_Uls_f32  to scale switch volts         3902
 *                              EA3#3802: Fix init function write calls                                      3901
 * 11/18/15  5        GMN       EA3#3861: Added a wait to the ReadAdc function so it could be re ordered
 *                                        near the StartAdc function                                         4386
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.

 *********************************************************************************************************************/

#include "Rte_IoHwAbstractionUsr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Adc.h"
#include "Adc2.h"
#include "CalConstants.h"
#include "CDD_Data.h"
#include "GlobalMacro.h"
#include "Dma.h"
#include "NtWrap.h"
#include "IoHwAbstractionUsr.h"

#define D_ADCRESULTMASK_CNT_U16         0x0FFFU
#define D_ADCVOLTSPERCNT_ULS_F32        (5.0F /4095.0F)
#define D_BATTSWHWSCALING_ULS_F32       3.36966824645F
#define D_BATTHWSCALING_ULS_F32         6.74712643678F

/*
 * Macro to read slow ADC values.
 * The _adc value must be one of the macros defined at Adc_Cfg.h.
 */
#define IoHwAb_ReadAdc(_adc) (DMAData_G_str.SlowADC_Cnt_u16[_adc] & D_ADCRESULTMASK_CNT_U16) /* PRQA S 3453 */

#define IOHWAB10_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AUTOMATIC) IoHwAb_ADCVrefErrorAcc_Cnt_M_u16;    /* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC) IoHwAb_SlowADCValidAcc_Cnt_M_u16;    /* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC) MtrPos3Sin_Volt_M_u3p13;
STATIC VAR(uint16, AUTOMATIC) MtrPos3Cos_Volt_M_u3p13;
#define IOHWAB10_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define IOHWAB10_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC) Batt_Volt_M_f32;
STATIC VAR(float32, AUTOMATIC) BattSwitched1_Volt_M_f32;
STATIC VAR(float32, AUTOMATIC) BattSwitched2_Volt_M_f32;
STATIC VAR(float32, AUTOMATIC) SysCBattSwitched1_Volt_M_f32;           /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) SysCBattSwitched2_Volt_M_f32;           /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) Temperature_Volt_M_f32;
STATIC VAR(float32, AUTOMATIC) Vref3p3_Volt_M_f32;
STATIC VAR(float32, AUTOMATIC) Vref5vp1_Volt_M_f32;
STATIC VAR(float32, AUTOMATIC) Vref5vp2_Volt_M_f32;
STATIC VAR(float32, AUTOMATIC) T1ADC_Volt_M_f32;
STATIC VAR(float32, AUTOMATIC) T2ADC_Volt_M_f32;
STATIC VAR(float32, AUTOMATIC) SysCT1ADC_Volt_M_f32;                   /* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) SysCT2ADC_Volt_M_f32;                   /* PRQA S 3218 */
STATIC volatile VAR(uint32, AUTOMATIC) ReadAdcWaitedTime_uS_D_u32;     /* PRQA S 3218 */
STATIC volatile VAR(uint32, AUTOMATIC) ReadAdcMaxWaitedTime_uS_D_u32;  /* PRQA S 3218 */
#define IOHWAB10_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

/* Prototypes */
STATIC FUNC(boolean, DMA_CODE) IoHwAb_SlowADCGroupValidity(void);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_NvMBlkDftActA (6U)
 *   NTC_Num_NvMBlkDftActB (7U)
 *   NTC_Num_NvMBlkDftActC (8U)
 *   NTC_Num_CurrentSensorCalOutOfRange (9U)
 *   NTC_Num_EEPROMDiag (10U)
 *   NTC_Num_EEPROMDiagMtrStr (11U)
 *   NTC_Num_PriSnsrTrqStorFlt (12U)
 *   NTC_Num_EEPROMDiagPosTrimStr (13U)
 *   NTC_Num_SecSnsrTrqStorFlt (14U)
 *   NTC_Num_EEPROMDiagPolarityStr (15U)
 *   NTC_Num_RAMDiag_GeneralFlt (16U)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17U)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
 *   NTC_Num_RAMDiag_ECCMemFlt (19U)
 *   NTC_Num_RAMDiag_CRCMemFlt (20U)
 *   NTC_Num_RAMDiag_VIMRamFlt (23U)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24U)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25U)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26U)
 *   NTC_Num_RAMDiag_DCANRamFault (27U)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28U)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29U)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30U)
 *   NTC_Num_CPU_RegVer (32U)
 *   NTC_Num_CPU_CoreInitFlt (33U)
 *   NTC_Num_CPU_CoreRunTimeFlt (34U)
 *   NTC_Num_CPU_ClockMon (35U)
 *   NTC_Num_CPU_eFuseFlt (36U)
 *   NTC_Num_CPU_MPUViolation (37U)
 *   NTC_Num_CPU_FactPrcsErr (40U)
 *   NTC_Num_PropExeDiag_InitDiag (41U)
 *   NTC_Num_PrgFlwDeadlnFlt (42U)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43U)
 *   NTC_Num_PropExeDiag_COPTimeout (44U)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48U)
 *   NTC_Num_PropExeDiag_DataAbort (49U)
 *   NTC_Num_PerDiag_ADC1Flt (50U)
 *   NTC_Num_PerDiag_ADC2Flt (51U)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52U)
 *   NTC_Num_PerDiag_IllegalAccess (53U)
 *   NTC_Num_PerDiag_DMAFlt (54U)
 *   NTC_Num_PeripheralStartupFlt (55U)
 *   NTC_Num_PerDiag_CPUWarning (63U)
 *   NTC_Num_TmpMonFunc (64U)
 *   NTC_Num_TmpMonRunTimeFlt (65U)
 *   NTC_Num_PowerRelayInitFlt (66U)
 *   NTC_Num_PrechargeFailure (67U)
 *   NTC_Num_PowerRelayRunFlt (68U)
 *   NTC_Num_Thermistor (69U)
 *   NTC_Num_RefSupplyVltg (70U)
 *   NTC_Num_TrcvrInterfaceFlt (71U)
 *   NTC_Num_CPUSupplyOvervoltage (72U)
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73U)
 *   NTC_Num_IvtrPwrDiscnctFailr (74U)
 *   NTC_Num_GateDrvFltInProcess (76U)
 *   NTC_Num_GateDrvFlt (77U)
 *   NTC_Num_OnStateSingleFET (78U)
 *   NTC_Num_OnStateMultiFET (79U)
 *   NTC_Num_PhaseVoltageVerf (80U)
 *   NTC_Num_PhaseDscnt (81U)
 *   NTC_Num_DigPhaseVoltageVerf (82U)
 *   NTC_Num_PhaseDscntFailedDisable (83U)
 *   NTC_Num_CurrentMeas1 (84U)
 *   NTC_Num_CurrentMeas2 (85U)
 *   NTC_Num_CurrentMeasCrossChk (86U)
 *   NTC_Num_PDSupplyOverVoltage (87U)
 *   NTC_Num_ChargePumpUnderVoltage (88U)
 *   NTC_Num_HwTrqSensor (96U)
 *   NTC_Num_AnaVsDigHwTrq (97U)
 *   NTC_Num_TrqSensorRecoveryFlt (98U)
 *   NTC_Num_TrqSensorScaleInvalid (100U)
 *   NTC_Num_T1vsT2 (101U)
 *   NTC_Num_T1OutofRange (102U)
 *   NTC_Num_T2OutofRange (103U)
 *   NTC_Num_DigT1vsT2 (104U)
 *   NTC_Num_DigT1OutofRange (105U)
 *   NTC_Num_DigT2OutofRange (106U)
 *   NTC_Num_RedT1vsT2 (107U)
 *   NTC_Num_HWACrossChecks (108U)
 *   NTC_Num_HWASnsrCommFault (109U)
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_LoaRpdShutdn (170U)
 *   NTC_Num_LoaCtrldShutdn (171U)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172U)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173U)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174U)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
 *   NTC_Num_BattTransOverVolt (182U)
 *   NTC_Num_IgnConfDiag (184U)
 *   NTC_Num_TurnCntr_LowBattery (185U)
 *   NTC_Num_EEPROMCloseFailed (191U)
 *   NTC_Num_SigPath1CrossChk (192U)
 *   NTC_Num_SigPath2CrossChk (193U)
 *   NTC_Num_SigPath3CrossChk (194U)
 *   NTC_Num_SigPath4CrossChk (195U)
 *   NTC_Num_SigPath5CrossChk (196U)
 *   NTC_Num_DampingFWReached (197U)
 *   NTC_Num_AssistFWReached (198U)
 *   NTC_Num_ReturnFWReached (199U)
 *   NTC_Num_DampingFWFltMode (200U)
 *   NTC_Num_AssistFWFltMode (201U)
 *   NTC_Num_VBICFltMode (202U)
 *   NTC_Num_StaMdsSysC (203U)
 *   NTC_NUM_SysFailureForRotVel (204U)
 *   NTC_NUM_SysFailForRedntRotVel (205U)
 *   NTC_Num_SysFailureForTrqSnsr (206U)
 *   NTC_Num_SysFailureForRedTrqSnsr (207U)
 *   NTC_NUM_SysFailureForCtrlVolt (209U)
 *   NTC_Num_GlblSgnlOvrwrtDet (223U)
 *   NTC_Num_VLF_00 (224U)
 *   NTC_Num_VLF_01 (225U)
 *   NTC_Num_VLF_02 (226U)
 *   NTC_Num_VLF_03 (227U)
 *   NTC_Num_VLF_04 (228U)
 *   NTC_Num_VLF_05 (229U)
 *   NTC_Num_VLF_06 (230U)
 *   NTC_Num_VLF_07 (231U)
 *   NTC_Num_VLF_08 (232U)
 *   NTC_Num_VLF_09 (233U)
 *   NTC_Num_VLF_10 (234U)
 *   NTC_Num_VLF_11 (235U)
 *   NTC_Num_VLF_12 (236U)
 *   NTC_Num_VLF_13 (237U)
 *   NTC_Num_VLF_14 (238U)
 *   NTC_Num_VLF_15 (239U)
 *   NTC_Num_VLF_16 (240U)
 *   NTC_Num_VLF_17 (241U)
 *   NTC_Num_VLF_18 (242U)
 *   NTC_Num_VLF_19 (243U)
 *   NTC_Num_VLF_20 (244U)
 *   NTC_Num_VLF_21 (245U)
 *   NTC_Num_VLF_22 (246U)
 *   NTC_Num_VLF_23 (247U)
 *   NTC_Num_VLF_24 (248U)
 *   NTC_Num_VLF_25 (249U)
 *   NTC_Num_VLF_26 (250U)
 *   NTC_Num_VLF_27 (251U)
 *   NTC_Num_VLF_28 (252U)
 *   NTC_Num_VLF_29 (253U)
 *   NTC_Num_VLF_30 (254U)
 *   NTC_Num_VLF_31 (255U)
 *   NTC_Num_BusOffCh1 (256U)
 *   NTC_Num_BusOffCh1NodeMute (257U)
 *   NTC_Num_Node1AAbsent (258U)
 *   NTC_Num_Node1AFaulty (259U)
 *   NTC_Num_Node1BAbsent (260U)
 *   NTC_Num_Node1BFaulty (261U)
 *   NTC_Num_Node1CAbsent (262U)
 *   NTC_Num_Node1CFaulty (263U)
 *   NTC_Num_Node1DAbsent (264U)
 *   NTC_Num_Node1DFaulty (265U)
 *   NTC_Num_Node1EAbsent (266U)
 *   NTC_Num_Node1EFaulty (267U)
 *   NTC_Num_Node1FAbsent (268U)
 *   NTC_Num_Node1FFaulty (269U)
 *   NTC_Num_Node1GAbsent (270U)
 *   NTC_Num_Node1GFaulty (271U)
 *   NTC_Num_BusOffCh2 (272U)
 *   NTC_Num_Node2AAbsent (273U)
 *   NTC_Num_Node2AFaulty (274U)
 *   NTC_Num_Node2BAbsent (275U)
 *   NTC_Num_Node2BFaulty (276U)
 *   NTC_Num_Node2CAbsent (277U)
 *   NTC_Num_Node2CFaulty (278U)
 *   NTC_Num_Node2DAbsent (279U)
 *   NTC_Num_Node2DFaulty (280U)
 *   NTC_Num_Node2EAbsent (281U)
 *   NTC_Num_Node2EFaulty (282U)
 *   NTC_Num_Node2FAbsent (283U)
 *   NTC_Num_Node2FFaulty (284U)
 *   NTC_Num_Node2GAbsent (285U)
 *   NTC_Num_Node2GFaulty (286U)
 *   NTC_Num_InvalidMsg_M (288U)
 *   NTC_Num_MissingMsg_M (289U)
 *   NTC_Num_CRCFltMsg_M (290U)
 *   NTC_Num_PgrsCntFltMsg_M (291U)
 *   NTC_Num_DataRngFltMsg_M (292U)
 *   NTC_Num_DataRateFltMsg_M (293U)
 *   NTC_Num_DataOtherFltMsg_M (294U)
 *   NTC_Num_DataOther2FltMsg_M (295U)
 *   NTC_Num_InvalidMsg_N (296U)
 *   NTC_Num_MissingMsg_N (297U)
 *   NTC_Num_CRCFltMsg_N (298U)
 *   NTC_Num_PgrsCntFltMsg_N (299U)
 *   NTC_Num_DataRngFltMsg_N (300U)
 *   NTC_Num_DataRateFltMsg_N (301U)
 *   NTC_Num_DataOtherFltMsg_N (302U)
 *   NTC_Num_DataOtherFlt2Msg_N (303U)
 *   NTC_Num_InvalidMsg_O (304U)
 *   NTC_Num_MissingMsg_O (305U)
 *   NTC_Num_CRCFltMsg_O (306U)
 *   NTC_Num_PgrsCntFltMsg_O (307U)
 *   NTC_Num_DataRngFltMsg_O (308U)
 *   NTC_Num_DataRateFltMsg_O (309U)
 *   NTC_Num_DataOtherFltMsg_O (310U)
 *   NTC_Num_InvalidMsg_P (312U)
 *   NTC_Num_MissingMsg_P (313U)
 *   NTC_Num_CRCFltMsg_P (314U)
 *   NTC_Num_PgrsCntFltMsg_P (315U)
 *   NTC_Num_DataRngFltMsg_P (316U)
 *   NTC_Num_DataRateFltMsg_P (317U)
 *   NTC_Num_DataOtherFltMsg_P (318U)
 *   NTC_Num_InvalidMsg_Q (320U)
 *   NTC_Num_MissingMsg_Q (321U)
 *   NTC_Num_CRCFltMsg_Q (322U)
 *   NTC_Num_PgrsCntFltMsg_Q (323U)
 *   NTC_Num_DataRngFltMsg_Q (324U)
 *   NTC_Num_DataRateFltMsg_Q (325U)
 *   NTC_Num_DataOtherFltMsg_Q (326U)
 *   NTC_Num_InvalidMsg_R (328U)
 *   NTC_Num_MissingMsg_R (329U)
 *   NTC_Num_CRCFltMsg_R (330U)
 *   NTC_Num_PgrsCntFltMsg_R (331U)
 *   NTC_Num_DataRngFltMsg_R (332U)
 *   NTC_Num_DataRateFltMsg_R (333U)
 *   NTC_Num_DataOtherFltMsg_R (334U)
 *   NTC_Num_DataOtherFlt2Msg_R (335U)
 *   NTC_Num_InvalidMsg_S (336U)
 *   NTC_Num_MissingMsg_S (337U)
 *   NTC_Num_CRCFltMsg_S (338U)
 *   NTC_Num_PgrsCntFltMsg_S (339U)
 *   NTC_Num_DataRngFltMsg_S (340U)
 *   NTC_Num_DataRateFltMsg_S (341U)
 *   NTC_Num_DataOtherFltMsg_S (342U)
 *   NTC_Num_InvalidMsg_T (344U)
 *   NTC_Num_MissingMsg_T (345U)
 *   NTC_Num_CRCFltMsg_T (346U)
 *   NTC_Num_PgrsCntFltMsg_T (347U)
 *   NTC_Num_DataRngFltMsg_T (348U)
 *   NTC_Num_DataRateFltMsg_T (349U)
 *   NTC_Num_DataOtherFltMsg_T (350U)
 *   NTC_Num_InvalidMsg_U (352U)
 *   NTC_Num_MissingMsg_U (353U)
 *   NTC_Num_CRCFltMsg_U (354U)
 *   NTC_Num_PgrsCntFltMsg_U (355U)
 *   NTC_Num_DataRngFltMsg_U (356U)
 *   NTC_Num_DataRateFltMsg_U (357U)
 *   NTC_Num_DataOtherFltMsg_U (358U)
 *   NTC_Num_InvalidMsg_V (360U)
 *   NTC_Num_MissingMsg_V (361U)
 *   NTC_Num_CRCFltMsg_V (362U)
 *   NTC_Num_PgrsCntFltMsg_V (363U)
 *   NTC_Num_DataRngFltMsg_V (364U)
 *   NTC_Num_DataRateFltMsg_V (365U)
 *   NTC_Num_DataOtherFltMsg_V (366U)
 *   NTC_Num_InvalidMsg_W (368U)
 *   NTC_Num_MissingMsg_W (369U)
 *   NTC_Num_CRCFltMsg_W (370U)
 *   NTC_Num_PgrsCntFltMsg_W (371U)
 *   NTC_Num_DataRngFltMsg_W (372U)
 *   NTC_Num_DataRateFltMsg_W (373U)
 *   NTC_Num_DataOtherFltMsg_W (374U)
 *   NTC_Num_InvalidMsg_X (376U)
 *   NTC_Num_MissingMsg_X (377U)
 *   NTC_Num_CRCFltMsg_X (378U)
 *   NTC_Num_PgrsCntFltMsg_X (379U)
 *   NTC_Num_DataRngFltMsg_X (380U)
 *   NTC_Num_DataRateFltMsg_X (381U)
 *   NTC_Num_DataOtherFltMsg_X (382U)
 *   NTC_Num_InvalidMsg_Y (384U)
 *   NTC_Num_MissingMsg_Y (385U)
 *   NTC_Num_CRCFltMsg_Y (386U)
 *   NTC_Num_PgrsCntFltMsg_Y (387U)
 *   NTC_Num_DataRngFltMsg_Y (388U)
 *   NTC_Num_DataRateFltMsg_Y (389U)
 *   NTC_Num_DataOtherFltMsg_Y (390U)
 *   NTC_Num_InvalidMsg_Z (392U)
 *   NTC_Num_MissingMsg_Z (393U)
 *   NTC_Num_CRCFltMsg_Z (394U)
 *   NTC_Num_PgrsCntFltMsg_Z (395U)
 *   NTC_Num_DataRngFltMsg_Z (396U)
 *   NTC_Num_DataRateFltMsg_Z (397U)
 *   NTC_Num_DataOtherFltMsg_Z (398U)
 *   NTC_Num_DSTXORActive (399U)
 *   NTC_Num_InvalidMsg_AA (400U)
 *   NTC_Num_MissingMsg_AA (401U)
 *   NTC_Num_CRCFltMsg_AA (402U)
 *   NTC_Num_PgrsCntFltMsg_AA (403U)
 *   NTC_Num_DataRngFltMsg_AA (404U)
 *   NTC_Num_DataRateFltMsg_AA (405U)
 *   NTC_Num_DataOtherFltMsg_AA (406U)
 *   NTC_Num_InvalidMsg_AB (408U)
 *   NTC_Num_MissingMsg_AB (409U)
 *   NTC_Num_CRCFltMsg_AB (410U)
 *   NTC_Num_PgrsCntFltMsg_AB (411U)
 *   NTC_Num_DataRngFltMsg_AB (412U)
 *   NTC_Num_DataRateFltMsg_AB (413U)
 *   NTC_Num_DataOtherFltMsg_AB (414U)
 *   NTC_Num_InvalidMsg_AC (416U)
 *   NTC_Num_MissingMsg_AC (417U)
 *   NTC_Num_CRCFltMsg_AC (418U)
 *   NTC_Num_PgrsCntFltMsg_AC (419U)
 *   NTC_Num_DataRngFltMsg_AC (420U)
 *   NTC_Num_DataRateFltMsg_AC (421U)
 *   NTC_Num_DataOtherFltMsg_AC (422U)
 *   NTC_Num_InvalidMsg_AD (424U)
 *   NTC_Num_MissingMsg_AD (425U)
 *   NTC_Num_CRCFltMsg_AD (426U)
 *   NTC_Num_PgrsCntFltMsg_AD (427U)
 *   NTC_Num_DataRngFltMsg_AD (428U)
 *   NTC_Num_DataRateFltMsg_AD (429U)
 *   NTC_Num_DataOtherFltMsg_AD (430U)
 *   NTC_Num_InvalidMsg_AE (432U)
 *   NTC_Num_MissingMsg_AE (433U)
 *   NTC_Num_CRCFltMsg_AE (434U)
 *   NTC_Num_PgrsCntFltMsg_AE (435U)
 *   NTC_Num_DataRngFltMsg_AE (436U)
 *   NTC_Num_DataRateFltMsg_AE (437U)
 *   NTC_Num_DataOtherFltMsg_AE (438U)
 *   NTC_Num_InvalidMsg_AF (440U)
 *   NTC_Num_MissingMsg_AF (441U)
 *   NTC_Num_CRCFltMsg_AF (442U)
 *   NTC_Num_PgrsCntFltMsg_AF (443U)
 *   NTC_Num_DataRngFltMsg_AF (444U)
 *   NTC_Num_DataRateFltMsg_AF (445U)
 *   NTC_Num_DataOtherFltMsg_AF (446U)
 *   NTC_Num_InvalidMsg_AG (448U)
 *   NTC_Num_MissingMsg_AG (449U)
 *   NTC_Num_CRCFltMsg_AG (450U)
 *   NTC_Num_PgrsCntFltMsg_AG (451U)
 *   NTC_Num_DataRngFltMsg_AG (452U)
 *   NTC_Num_DataRateFltMsg_AG (453U)
 *   NTC_Num_DataOtherFltMsg_AG (454U)
 *   NTC_Num_InvalidMsg_AH (456U)
 *   NTC_Num_MissingMsg_AH (457U)
 *   NTC_Num_CRCFltMsg_AH (458U)
 *   NTC_Num_PgrsCntFltMsg_AH (459U)
 *   NTC_Num_DataRngFltMsg_AH (460U)
 *   NTC_Num_DataRateFltMsg_AH (461U)
 *   NTC_Num_DataOtherFltMsg_AH (462U)
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464U)
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_InvalidMsg_AI (466U)
 *   NTC_Num_MissingMsg_AI (467U)
 *   NTC_Num_InvalidMsg_AJ (472U)
 *   NTC_Num_MissingMsg_AJ (473U)
 *   NTC_Num_InvalidMsg_AK (480U)
 *   NTC_Num_MissingMsg_AK (481U)
 *   NTC_Num_MissingMsg_AL (489U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_TunSetNotPrgmd (499U)
 *   NTC_Num_EEPROMtoFeeCpyError (500U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Boolean: D_TRUE_CNT_LGC = TRUE
 * Float: D_ZERO_ULS_F32 = 0.0F
 * UInt16: D_ZERO_CNT_U16 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_IOHWABSTRACTIONUSR_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_Init
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_IoHwAb_Init_BattSwitched1_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_BattSwitched1_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_BattSwitched2_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_BattSwitched2_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_Batt_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_Batt_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_MtrPos3Con_Volt_u3p13(UInt16 data)
 *   UInt16 *Rte_IWriteRef_IoHwAb_Init_MtrPos3Con_Volt_u3p13(void)
 *   void Rte_IWrite_IoHwAb_Init_MtrPos3Sin_Volt_u3p13(UInt16 data)
 *   UInt16 *Rte_IWriteRef_IoHwAb_Init_MtrPos3Sin_Volt_u3p13(void)
 *   void Rte_IWrite_IoHwAb_Init_T1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_T1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_T2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_T2ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_TemperatureADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_TemperatureADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_Vref3p3_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_Vref3p3_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_Vref5vp1_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_Vref5vp1_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_Init_Vref5vp2_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_Init_Vref5vp2_Volt_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) IoHwAb_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_Init
 *********************************************************************************************************************/
	VAR(uint16, AUTOMATIC) BattADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) BattSwitched1ADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) BattSwitched2ADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) TemperatureADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) Vref3p3_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) Vref5vp1_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) Vref5vp2_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) T1ADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) T2ADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) MtrPos3Sin_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) MtrPos3Con_Cnt_T_u16;

	/* Read ADC values */
	BattADC_Cnt_T_u16 = IoHwAb_ReadAdc(D_BATT_CNT_U16);
	BattSwitched1ADC_Cnt_T_u16 = IoHwAb_ReadAdc(D_BATTSWITCHED1_CNT_U16);
	BattSwitched2ADC_Cnt_T_u16 = IoHwAb_ReadAdc(D_BATTSWITCHED2_CNT_U16);
	TemperatureADC_Cnt_T_u16 = IoHwAb_ReadAdc(D_TEMPERATURE_CNT_U16);
	Vref3p3_Cnt_T_u16 = IoHwAb_ReadAdc(D_VREF3P3_CNT_U16);
	Vref5vp1_Cnt_T_u16 = IoHwAb_ReadAdc(D_VREF5VP1_CNT_U16);
	Vref5vp2_Cnt_T_u16 = IoHwAb_ReadAdc(D_VREF5VP2_CNT_U16);
	T1ADC_Cnt_T_u16 = IoHwAb_ReadAdc(D_HWTRQT1ADC_CNT_U16);
	T2ADC_Cnt_T_u16 = IoHwAb_ReadAdc(D_HWTRQT2ADC_CNT_U16);
	MtrPos3Sin_Cnt_T_u16 = IoHwAb_ReadAdc(D_MTRPOS3SIN_CNT_U16);
	MtrPos3Con_Cnt_T_u16 = IoHwAb_ReadAdc(D_MTRPOS3COS_CNT_U16);

	/* Convert the variable units */
	Batt_Volt_M_f32 = ((float32)BattADC_Cnt_T_u16) * D_ADCVOLTSPERCNT_ULS_F32 * D_BATTHWSCALING_ULS_F32;
	BattSwitched1_Volt_M_f32 = ((float32)BattSwitched1ADC_Cnt_T_u16) * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVbattSwitchScaling_Uls_f32;
	BattSwitched2_Volt_M_f32 = ((float32)BattSwitched2ADC_Cnt_T_u16) * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVbattSwitchScaling_Uls_f32;
	Temperature_Volt_M_f32 = ((float32)TemperatureADC_Cnt_T_u16) * D_ADCVOLTSPERCNT_ULS_F32;
	Vref3p3_Volt_M_f32 = (float32)Vref3p3_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVref3p3Scaling_Uls_f32;
	Vref5vp1_Volt_M_f32 = (float32)Vref5vp1_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVref5vp1Scaling_Uls_f32;
	Vref5vp2_Volt_M_f32 = (float32)Vref5vp2_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVref5vp2Scaling_Uls_f32;
	T1ADC_Volt_M_f32 = (float32)T1ADC_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32;
	T2ADC_Volt_M_f32 = (float32)T2ADC_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32;
	MtrPos3Sin_Volt_M_u3p13 = FPM_FloatToFixed_m((float32)MtrPos3Sin_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32, u3p13_T); /* PRQA S 4395 */
	MtrPos3Cos_Volt_M_u3p13 = FPM_FloatToFixed_m((float32)MtrPos3Con_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32, u3p13_T); /* PRQA S 4395 */

	/* RTE Write */
	Rte_IWrite_IoHwAb_Init_Batt_Volt_f32(Batt_Volt_M_f32);
	Rte_IWrite_IoHwAb_Init_BattSwitched1_Volt_f32(BattSwitched1_Volt_M_f32);
	Rte_IWrite_IoHwAb_Init_BattSwitched2_Volt_f32(BattSwitched2_Volt_M_f32);
	Rte_IWrite_IoHwAb_Init_TemperatureADC_Volt_f32(Temperature_Volt_M_f32);
	Rte_IWrite_IoHwAb_Init_Vref3p3_Volt_f32(Vref3p3_Volt_M_f32);
	Rte_IWrite_IoHwAb_Init_Vref5vp1_Volt_f32(Vref5vp1_Volt_M_f32);
	Rte_IWrite_IoHwAb_Init_Vref5vp2_Volt_f32(Vref5vp2_Volt_M_f32);
	Rte_IWrite_IoHwAb_Init_T1ADC_Volt_f32(T1ADC_Volt_M_f32);
	Rte_IWrite_IoHwAb_Init_T2ADC_Volt_f32(T2ADC_Volt_M_f32);
	Rte_IWrite_IoHwAb_Init_MtrPos3Sin_Volt_u3p13(MtrPos3Sin_Volt_M_u3p13);
	Rte_IWrite_IoHwAb_Init_MtrPos3Con_Volt_u3p13(MtrPos3Cos_Volt_M_u3p13);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_ReadADC
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt16 Rte_IRead_IoHwAb_ReadADC_SysCBattSwitched1ADC_Cnt_u16(void)
 *   UInt16 Rte_IRead_IoHwAb_ReadADC_SysCBattSwitched2ADC_Cnt_u16(void)
 *   UInt16 Rte_IRead_IoHwAb_ReadADC_SysCT1ADC_Cnt_u16(void)
 *   UInt16 Rte_IRead_IoHwAb_ReadADC_SysCT2ADC_Cnt_u16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_IoHwAb_ReadADC_BattSwitched1_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_BattSwitched1_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_BattSwitched2_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_BattSwitched2_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_Batt_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_Batt_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_MtrPos3Con_Volt_u3p13(UInt16 data)
 *   UInt16 *Rte_IWriteRef_IoHwAb_ReadADC_MtrPos3Con_Volt_u3p13(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_MtrPos3Sin_Volt_u3p13(UInt16 data)
 *   UInt16 *Rte_IWriteRef_IoHwAb_ReadADC_MtrPos3Sin_Volt_u3p13(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_SysCBattSwitched1_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_SysCBattSwitched1_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_SysCBattSwitched2_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_SysCBattSwitched2_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_SysCT1_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_SysCT1_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_SysCT2_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_SysCT2_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_T1ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_T1ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_T2ADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_T2ADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_TemperatureADC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_TemperatureADC_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_Vref3p3_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_Vref3p3_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_Vref5vp1_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_Vref5vp1_Volt_f32(void)
 *   void Rte_IWrite_IoHwAb_ReadADC_Vref5vp2_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_IoHwAb_ReadADC_Vref5vp2_Volt_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_uS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) IoHwAb_ReadADC(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_ReadADC
 *********************************************************************************************************************/
	VAR(uint16, AUTOMATIC) BattADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) BattSwitched1ADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) BattSwitched2ADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) SysCBattSwitched1ADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) SysCBattSwitched2ADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) TemperatureADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) Vref3p3_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) Vref5vp1_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) Vref5vp2_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) T1ADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) T2ADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) SysCT1ADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) SysCT2ADC_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) MtrPos3Sin_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) MtrPos3Con_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) DataValid_Cnt_T_lgc;

	/* Check if this data has been updated. */
	DataValid_Cnt_T_lgc = IoHwAb_SlowADCGroupValidity();

	/* Disable ADC Conversion */
	CDD_ePWM4CMPB_Cnt_G_u16 = 65535u;

	/* Read ADC values */
	BattADC_Cnt_T_u16 = IoHwAb_ReadAdc(D_BATT_CNT_U16);
	BattSwitched1ADC_Cnt_T_u16 = IoHwAb_ReadAdc(D_BATTSWITCHED1_CNT_U16);
	BattSwitched2ADC_Cnt_T_u16 = IoHwAb_ReadAdc(D_BATTSWITCHED2_CNT_U16);
	TemperatureADC_Cnt_T_u16 = IoHwAb_ReadAdc(D_TEMPERATURE_CNT_U16);
	Vref3p3_Cnt_T_u16 = IoHwAb_ReadAdc(D_VREF3P3_CNT_U16);
	Vref5vp1_Cnt_T_u16 = IoHwAb_ReadAdc(D_VREF5VP1_CNT_U16);
	Vref5vp2_Cnt_T_u16 = IoHwAb_ReadAdc(D_VREF5VP2_CNT_U16);
	T1ADC_Cnt_T_u16 = IoHwAb_ReadAdc(D_HWTRQT1ADC_CNT_U16);
	T2ADC_Cnt_T_u16 = IoHwAb_ReadAdc(D_HWTRQT2ADC_CNT_U16);
	MtrPos3Sin_Cnt_T_u16 = IoHwAb_ReadAdc(D_MTRPOS3SIN_CNT_U16);
	MtrPos3Con_Cnt_T_u16 = IoHwAb_ReadAdc(D_MTRPOS3COS_CNT_U16);

	/* Read RTE inputs */
	SysCBattSwitched1ADC_Cnt_T_u16 = Rte_IRead_IoHwAb_ReadADC_SysCBattSwitched1ADC_Cnt_u16() & D_ADCRESULTMASK_CNT_U16;
	SysCBattSwitched2ADC_Cnt_T_u16 = Rte_IRead_IoHwAb_ReadADC_SysCBattSwitched2ADC_Cnt_u16() & D_ADCRESULTMASK_CNT_U16;
	SysCT1ADC_Cnt_T_u16 = Rte_IRead_IoHwAb_ReadADC_SysCT1ADC_Cnt_u16() & D_ADCRESULTMASK_CNT_U16;
	SysCT2ADC_Cnt_T_u16 = Rte_IRead_IoHwAb_ReadADC_SysCT2ADC_Cnt_u16() & D_ADCRESULTMASK_CNT_U16;

	/* Set the buffer to invalid values, to be updated before the next read. */
	TWrapC_Dma_InvalidateSlowADCGroup();

	/* If the data is valid, convert it for the RTE and check Vref for a fault. Otherwise keep old data. */
	if(TRUE == DataValid_Cnt_T_lgc)
	{
		Batt_Volt_M_f32 = ((float32)BattADC_Cnt_T_u16) * D_ADCVOLTSPERCNT_ULS_F32 * D_BATTHWSCALING_ULS_F32;
		BattSwitched1_Volt_M_f32 = ((float32)BattSwitched1ADC_Cnt_T_u16) * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVbattSwitchScaling_Uls_f32;
		BattSwitched2_Volt_M_f32 = ((float32)BattSwitched2ADC_Cnt_T_u16) * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVbattSwitchScaling_Uls_f32;
		SysCBattSwitched1_Volt_M_f32 = ((float32)SysCBattSwitched1ADC_Cnt_T_u16) * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVbattSwitchScaling_Uls_f32;
		SysCBattSwitched2_Volt_M_f32 = ((float32)SysCBattSwitched2ADC_Cnt_T_u16) * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVbattSwitchScaling_Uls_f32;
		Temperature_Volt_M_f32 = ((float32)TemperatureADC_Cnt_T_u16) * D_ADCVOLTSPERCNT_ULS_F32;
		Vref3p3_Volt_M_f32 = (float32)Vref3p3_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVref3p3Scaling_Uls_f32;
		Vref5vp1_Volt_M_f32 = (float32)Vref5vp1_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVref5vp1Scaling_Uls_f32;
		Vref5vp2_Volt_M_f32 = (float32)Vref5vp2_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32 * k_ADCVref5vp2Scaling_Uls_f32;
		T1ADC_Volt_M_f32 = (float32)T1ADC_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32;
		T2ADC_Volt_M_f32 = (float32)T2ADC_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32;
		SysCT1ADC_Volt_M_f32 = (float32)SysCT1ADC_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32;
		SysCT2ADC_Volt_M_f32 = (float32)SysCT2ADC_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32;
		MtrPos3Sin_Volt_M_u3p13 = FPM_FloatToFixed_m((float32)MtrPos3Sin_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32, u3p13_T); /* PRQA S 4395 */
		MtrPos3Cos_Volt_M_u3p13 = FPM_FloatToFixed_m((float32)MtrPos3Con_Cnt_T_u16 * D_ADCVOLTSPERCNT_ULS_F32, u3p13_T); /* PRQA S 4395 */

		if(Vref3p3_Volt_M_f32 > k_VrefMax_Volts_f32)
		{
			IoHwAb_ADCVrefErrorAcc_Cnt_M_u16 = DiagPStep_m(IoHwAb_ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str);
			if (DiagFailed_m( IoHwAb_ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str) == D_TRUE_CNT_LGC)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_RefSupplyVltg, D_NTCPARMBIT0_CNT_U8, NTC_STATUS_FAILED);
			}
		}
		else if(Vref3p3_Volt_M_f32 < k_VrefMin_Volts_f32)
		{
			IoHwAb_ADCVrefErrorAcc_Cnt_M_u16 = DiagPStep_m(IoHwAb_ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str);
			if (DiagFailed_m( IoHwAb_ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str) == D_TRUE_CNT_LGC)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_RefSupplyVltg, D_NTCPARMBIT1_CNT_U8, NTC_STATUS_FAILED);
			}
		}
		else
		{
			IoHwAb_ADCVrefErrorAcc_Cnt_M_u16 = DiagNStep_m(IoHwAb_ADCVrefErrorAcc_Cnt_M_u16, k_VrefOORDiag_Cnt_str);
			if (IoHwAb_ADCVrefErrorAcc_Cnt_M_u16 == D_ZERO_CNT_U16)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_RefSupplyVltg, D_NTCPARMBIT0_CNT_U8, NTC_STATUS_PASSED);
			}
		}
	}

	Rte_IWrite_IoHwAb_ReadADC_Batt_Volt_f32(Batt_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_BattSwitched1_Volt_f32(BattSwitched1_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_BattSwitched2_Volt_f32(BattSwitched2_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_SysCBattSwitched1_Volt_f32(SysCBattSwitched1_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_SysCBattSwitched2_Volt_f32(SysCBattSwitched2_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_TemperatureADC_Volt_f32(Temperature_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_Vref3p3_Volt_f32(Vref3p3_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_Vref5vp1_Volt_f32(Vref5vp1_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_Vref5vp2_Volt_f32(Vref5vp2_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_T1ADC_Volt_f32(T1ADC_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_T2ADC_Volt_f32(T2ADC_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_SysCT1_Volt_f32(SysCT1ADC_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_SysCT2_Volt_f32(SysCT2ADC_Volt_M_f32);
	Rte_IWrite_IoHwAb_ReadADC_MtrPos3Sin_Volt_u3p13(MtrPos3Sin_Volt_M_u3p13);
	Rte_IWrite_IoHwAb_ReadADC_MtrPos3Con_Volt_u3p13(MtrPos3Cos_Volt_M_u3p13);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: IoHwAb_StartADC
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) IoHwAb_StartADC(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: IoHwAb_StartADC
 *********************************************************************************************************************/
	/* Enable ADC Conversion */
	CDD_ePWM4CMPB_Cnt_G_u16 = 100U;

	/* Clear ADC1 G2 Conversion Complete Flag */
	adcREG1->GxSR[2U] = 1U; /* PRQA S 0303 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_IOHWABSTRACTIONUSR_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*****************************************************************************
 * Name:        IoHwAb_CaptureADC
 * Description: Capture the ADC values from ADC2 used by the 2ms loop
 *****************************************************************************/
FUNC(void, RTE_IOHWABSTRACTIONUSR_APPL_CODE) IoHwAb_CaptureADC(void)
{
	CDD_SysCBattSwitched1_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16] = DMAData_G_str.FastADC_Cnt_u16[D_SYSCBATTSWITCHED1_CNT_U16];
	CDD_SysCBattSwitched2_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16] = DMAData_G_str.FastADC_Cnt_u16[D_SYSCBATTSWITCHED2_CNT_U16];
	CDD_SysCT1Adc_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16] = DMAData_G_str.FastADC_Cnt_u16[D_SYSCT1ADC_CNT_U16];
	CDD_SysCT2Adc_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16] = DMAData_G_str.FastADC_Cnt_u16[D_SYSCT2ADC_CNT_U16];
}

/*****************************************************************************
 * Name:        IoHwAb_SlowADCGroupValidity
 * Description: Patch validity check utilizing a P/N-step around the NTC
 *****************************************************************************/
STATIC FUNC(boolean, DMA_CODE) IoHwAb_SlowADCGroupValidity(void)
{
	VAR(uint16, AUTOMATIC) i;
	VAR(uint32, AUTOMATIC) InitTime_uS_T_u32;
	VAR(uint32, AUTOMATIC) ElapsedTime_uS_T_u32;
	VAR(uint32, AUTOMATIC) WaitedTime_uS_T_u32;
	VAR(boolean, AUTOMATIC) RetValue_Cnt_T_lgc;

	RetValue_Cnt_T_lgc = TRUE;
	WaitedTime_uS_T_u32 = 0U;
	(void)Rte_Call_SystemTime_GetSystemTime_uS_u32(&InitTime_uS_T_u32); /* PRQA S 3417, 3426 */

	for (i = 0U; i < D_NUMSLOWADCCHANNELS_CNT_U16; i++)
	{
		/* Wait for the ADC conversion */
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u32(InitTime_uS_T_u32, &ElapsedTime_uS_T_u32); /* PRQA S 3417, 3426 */
		while ((DMAData_G_str.SlowADC_Cnt_u16[i] == 0xFFFFU) && (ElapsedTime_uS_T_u32 < k_ReadAdcWaitTimeout_uS_u32))
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u32(InitTime_uS_T_u32, &ElapsedTime_uS_T_u32); /* PRQA S 3417, 3426 */
			WaitedTime_uS_T_u32 = ElapsedTime_uS_T_u32;
		}

		/* Update the display variables */
		ReadAdcWaitedTime_uS_D_u32 = WaitedTime_uS_T_u32;
		if (WaitedTime_uS_T_u32 > ReadAdcMaxWaitedTime_uS_D_u32)
		{
			ReadAdcMaxWaitedTime_uS_D_u32 = WaitedTime_uS_T_u32;
		}

		/* Check if the ADC conversion happened or a timeout occurred */
		if (DMAData_G_str.SlowADC_Cnt_u16[i] == 0xFFFFU)
		{
			RetValue_Cnt_T_lgc = FALSE;
			IoHwAb_SlowADCValidAcc_Cnt_M_u16 = DiagPStep_m(IoHwAb_SlowADCValidAcc_Cnt_M_u16, k_SlowADCValidDiag_Cnt_str);

			if (DiagFailed_m(IoHwAb_SlowADCValidAcc_Cnt_M_u16, k_SlowADCValidDiag_Cnt_str) == D_TRUE_CNT_LGC)
			{
				(void)DMA_REPORTERRORSTATUS(NTC_Num_PerDiag_DMAFlt, 0x20u, NTC_STATUS_FAILED);
			}
		}
		else
		{
			IoHwAb_SlowADCValidAcc_Cnt_M_u16 = DiagNStep_m(IoHwAb_SlowADCValidAcc_Cnt_M_u16, k_SlowADCValidDiag_Cnt_str);
		}
	}

	return RetValue_Cnt_T_lgc;
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
