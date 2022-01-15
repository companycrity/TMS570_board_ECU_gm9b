/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_AnaHwTrq.c
 *     Workspace:  C:/_Synergy_Projects/Working/ses_dev_ea3/AnaHwTrq/autosar
 *     SW-C Type:  Sa_AnaHwTrq
 *  Generated at:  Fri Mar  3 15:55:17 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_AnaHwTrq>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2015,2017 Nexteer 
* Nexteer Confidential
*
* Module File Name: Sa_AnaHwTrq.c
* Module Description: Implements the "Analog Hand Wheel Torque" subfunction of ES-04E
* Project           : CBD   
* Author            : Shriram Patki
*****************************************************************************
* Version Control:
* Date Created:      Sat Feb 28 14:17:52 2015
* %version:          EA3#3 %
* %derived_by:       nz2554 %
* %date_modified:    Sat Feb 28 14:17:52 2015 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  ----------
* 03/02/15   1       SP       Initial version (FDD 4E rev 1.0)												 13047
* 08/11/15   2       BDO      Updated to FDD 04E rev 4.0 (parent CR 2417)  									 13519
* 03/03/17   3       SR       Updated to FDD 04E rev 005                                                     14375
*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  NvM_DestPtr
    DataPtr Type to be used by WriteBlock, ReadBlock and RestoreBlockDefaults operations. 	This type is used for all NVRAM blocks


 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.

 *********************************************************************************************************************/

#include "Rte_Sa_AnaHwTrq.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "CalConstants.h"
#include "GlobalMacro.h"

/* MISRA-C:2004 Rule 8.7: This deviation is required for Module Level Variable */
/* MISRA-C:2004 Rule 19.1: This deviation is required for AUTOSAR memory map requirements.  Rule suppressed by line at each occurrence. */
/* PRQA S 3332 EOF
   MISRA-C:2004 Rule 19.11 : Macro #if used for Fault Injection Points*/

#define D_HWTRQLOLMT_HWNM_F32					(-10.0F)
#define D_HWTRQHILMT_HWNM_F32					10.0F
#define D_DFLTRTRQTRIM_VOLT_F32				    2.5F
#define D_TRQSCALEWNDW_ULS_F32       			0.20F
#define D_TWO_ULS_F32							2.0F

/* Module Internals */
#define ANAHWTRQ_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AUTOMATIC) AnaHwTrq1RollgCntr_Cnt_M_u08;
STATIC VAR(uint8, AUTOMATIC) AnaHwTrq2RollgCntr_Cnt_M_u08;
STATIC VAR(SigQlfr_State_enum, AUTOMATIC) AnaHwTrq1Qlfr_Cnt_M_u08;
STATIC VAR(SigQlfr_State_enum, AUTOMATIC) AnaHwTrq2Qlfr_Cnt_M_u08;
STATIC VAR(uint8,  AUTOMATIC) AnaTrq1ErrAcc_Cnt_M_u08;
STATIC VAR(uint8,  AUTOMATIC) AnaTrq2ErrAcc_Cnt_M_u08;
#define ANAHWTRQ_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define ANAHWTRQ_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32,  AUTOMATIC) AnaHwTq1_Volt_M_f32;	/* PRQA S 3218 */
STATIC VAR(float32,  AUTOMATIC) AnaHwTq2_Volt_M_f32;	/* PRQA S 3218 */
#define ANAHWTRQ_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define ANAHWTRQ_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(DiagSettings_Str,  AUTOMATIC)  AnaHwTrqErr_Cnt_M_str;
#define ANAHWTRQ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* Local Function Prototypes */
STATIC FUNC(boolean, SA_HWTRQ_CODE) IsTrqScaleInRng_lgc(VAR(float32, AUTOMATIC) TrqScale_VoltpDeg_T_f32);


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
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * FltInjectionLocType: Enumeration of integer in interval [0...255] with enumerators
 *   FLTINJ_ASSIST (1u)
 *   FLTINJ_RETURN (2u)
 *   FLTINJ_DAMPING (3u)
 *   FLTINJ_ASSTSUMNLMT (4u)
 *   FLTINJ_AVGFRICLRN (7u)
 *   FLTINJ_VECU_BATTERYVOLTAGE (8u)
 *   FLTINJ_HYSTCOMP (12u)
 *   FLTINJ_INERTIACOMP (14u)
 *   FLTINJ_SUPPPWRLMT_CUSTPL (25u)
 *   FLTINJ_EOTDAMPING_ETDMPFW (27u)
 *   FLTINJ_STABILITYCOMP (29u)
 *   FLTINJ_TRQBASEDINRTCOMP (30u)
 *   FLTINJ_SRLCOMVEHSPD_SGNLCOND (33u)
 *   FLTINJ_ASSTFIREWALL (34u)
 *   FLTINJ_ASSTEOTGAIN_LMTCOD (38u)
 *   FLTINJ_ANAHWTRQT1 (39u)
 *   FLTINJ_ANAHWTRQT2 (40u)
 *   FLTINJ_DIGHWTRQSENT_T1FAULT (41u)
 *   FLTINJ_DIGHWTRQSENT_T2FAULT (42u)
 *   FLTINJ_TRQOSC_PREFINALCOMMAND (43u)
 *   FLTINJ_IMCARBCROLLGCNTR (44u)
 *   FLTINJ_IMCARBRCRC (45u)
 *   FLTINJ_IMCARBRDATA (46u)
 *   FLTINJ_GCCDIAG_HWTRQ (46u)
 *   FLTINJ_IMCARBRPATIDN (47u)
 *   FLTINJ_CMMTRCURR1 (48u)
 *   FLTINJ_CMMTRCURR2 (49u)
 *   FLTINJ_NHET1CFGANDUSE1 (50u)
 *   FLTINJ_NHET1CFGANDUSE2 (51u)
 *   FLTINJ_EPWM_UP1 (52u)
 *   FLTINJ_EPWM_UP2 (53u)
 *   FLTINJ_EPWM_UP3 (54u)
 *   FLTINJ_IMCARBROPENCAN (65u)
 *   FLTINJ_IMCARBROPENCANSCI (66u)
 *   FLTINJ_IMCARBROPENSCI (67u)
 *   FLTINJ_TARSTMOMDVACT (68u)
 *   FLTINJ_TRQOVLSTA_LKAFAULT (91u)
 *   FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND (100u)
 *   FLTINJ_TRQARBLIM_LKACMD (101u)
 *   FLTINJ_GCCDIAG_VEHSPD (146u)
 *   FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150u)
 *   FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151u)
 *   FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152u)
 *   FLTINJ_OUTPUTRAMPMULT_LMTCOD (153u)
 *   FLTINJ_ASSTEOTLIMIT_LMTCOD (154u)
 *   FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND (155u)
 *   FLTINJ_ANAHWTORQUE (156u)
 *   FLTINJ_MTRVEL (160u)
 *   FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD (200u)
 *   FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR (201u)
 *   FLTINJ_GCCDIAG_MTRTRQ (246u)
 *   FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND (255u)
 * ManufModeType: Enumeration of integer in interval [0...2] with enumerators
 *   ProductionMode (0u)
 *   ManufacturingMode (1u)
 *   EngineeringMode (2u)
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1u)
 *   NTC_Num_FlashECCCorr (2u)
 *   NTC_Num_FlashECCMemFlt (3u)
 *   NTC_Num_FlashCRCMemFault (4u)
 *   NTC_Num_NvMBlkDftActA (6u)
 *   NTC_Num_NvMBlkDftActB (7u)
 *   NTC_Num_NvMBlkDftActC (8u)
 *   NTC_Num_CurrentSensorCalOutOfRange (9u)
 *   NTC_Num_EEPROMDiag (10u)
 *   NTC_Num_EEPROMDiagMtrStr (11u)
 *   NTC_Num_PriSnsrTrqStorFlt (12u)
 *   NTC_Num_EEPROMDiagPosTrimStr (13u)
 *   NTC_Num_SecSnsrTrqStorFlt (14u)
 *   NTC_Num_EEPROMDiagPolarityStr (15u)
 *   NTC_Num_RAMDiag_GeneralFlt (16u)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17u)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18u)
 *   NTC_Num_RAMDiag_ECCMemFlt (19u)
 *   NTC_Num_RAMDiag_CRCMemFlt (20u)
 *   NTC_Num_PLLSlipNrcvrl (22u)
 *   NTC_Num_RAMDiag_VIMRamFlt (23u)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24u)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25u)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26u)
 *   NTC_Num_RAMDiag_DCANRamFault (27u)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28u)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29u)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30u)
 *   NTC_Num_CPU_RegVer (32u)
 *   NTC_Num_CPU_CoreInitFlt (33u)
 *   NTC_Num_CPU_CoreRunTimeFlt (34u)
 *   NTC_Num_CPU_ClockMon (35u)
 *   NTC_Num_CPU_eFuseFlt (36u)
 *   NTC_Num_CPU_MPUViolation (37u)
 *   NTC_Num_CPU_FactPrcsErr (40u)
 *   NTC_Num_PropExeDiag_InitDiag (41u)
 *   NTC_Num_PrgFlwDeadlnFlt (42u)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43u)
 *   NTC_Num_PropExeDiag_COPTimeout (44u)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48u)
 *   NTC_Num_PropExeDiag_DataAbort (49u)
 *   NTC_Num_PerDiag_ADC1Flt (50u)
 *   NTC_Num_PerDiag_ADC2Flt (51u)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52u)
 *   NTC_Num_PerDiag_IllegalAccess (53u)
 *   NTC_Num_PerDiag_DMAFlt (54u)
 *   NTC_Num_PeripheralStartupFlt (55u)
 *   NTC_Num_PerDiag_CPUWarning (63u)
 *   NTC_Num_TmpMonFunc (64u)
 *   NTC_Num_TmpMonRunTimeFlt (65u)
 *   NTC_Num_PowerRelayInitFlt (66u)
 *   NTC_Num_PrechargeFailure (67u)
 *   NTC_Num_PowerRelayRunFlt (68u)
 *   NTC_Num_Thermistor (69u)
 *   NTC_Num_RefSupplyVltg (70u)
 *   NTC_Num_TrcvrInterfaceFlt (71u)
 *   NTC_Num_CPUSupplyOvervoltage (72u)
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73u)
 *   NTC_Num_IvtrPwrDiscnctFailr (74u)
 *   NTC_Num_PowerRelayInit2Flt (75u)
 *   NTC_Num_GateDrvFltInProcess (76u)
 *   NTC_Num_GateDrvFlt (77u)
 *   NTC_Num_OnStateSingleFET (78u)
 *   NTC_Num_OnStateMultiFET (79u)
 *   NTC_Num_PhaseVoltageVerf (80u)
 *   NTC_Num_PhaseDscnt (81u)
 *   NTC_Num_DigPhaseVoltageVerf (82u)
 *   NTC_Num_PhaseDscntFailedDisable (83u)
 *   NTC_Num_CurrentMeas1 (84u)
 *   NTC_Num_CurrentMeas2 (85u)
 *   NTC_Num_CurrentMeasCrossChk (86u)
 *   NTC_Num_PDSupplyOverVoltage (87u)
 *   NTC_Num_ChargePumpUnderVoltage (88u)
 *   NTC_Num_Ivtr2PwrDiscnctFailr (90u)
 *   NTC_Num_SysVltgCorrlnFlt (91u)
 *   NTC_Num_Inv2GateDrvFltInProcess (92u)
 *   NTC_Num_Inv2GateDrvFlt (93u)
 *   NTC_Num_Inv2OnStateSingleFET (94u)
 *   NTC_Num_EcuIdnFlt (95u)
 *   NTC_Num_HwTrqSensor (96u)
 *   NTC_Num_AnaVsDigHwTrq (97u)
 *   NTC_Num_TrqSensorRecoveryFlt (98u)
 *   NTC_Num_TrqSensorScaleInvalid (100u)
 *   NTC_Num_T1vsT2 (101u)
 *   NTC_Num_T1OutofRange (102u)
 *   NTC_Num_T2OutofRange (103u)
 *   NTC_Num_DigT1vsT2 (104u)
 *   NTC_Num_DigT1OutofRange (105u)
 *   NTC_Num_DigT2OutofRange (106u)
 *   NTC_Num_RedT1vsT2 (107u)
 *   NTC_Num_HWACrossChecks (108u)
 *   NTC_Num_HWASnsrCommFault (109u)
 *   NTC_Num_HWASensorRel (110u)
 *   NTC_Num_HWASensorAbs (111u)
 *   NTC_Num_PriMSB_SinCosCorr (112u)
 *   NTC_Num_SecMSB_SinCosCorr (113u)
 *   NTC_Num_PriVsSec_SinCosCorr (114u)
 *   NTC_Num_DigMSBFlt (115u)
 *   NTC_Num_MtrVelFlt (116u)
 *   NTC_Num_HWAtoMtrAngleCorr (117u)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118u)
 *   NTC_Num_IMCLossOfCom (125u)
 *   NTC_Num_ImcArbrFault (127u)
 *   NTC_Num_TurnCntr_PosLoss (128u)
 *   NTC_Num_TurnCntr_MicroProcFlt (129u)
 *   NTC_Num_TurnCntr_SensorPosFlt (130u)
 *   NTC_Num_TurnCntr_SpiComFlt (131u)
 *   NTC_Num_TurnCntr_HighQuiescCur (132u)
 *   NTC_Num_TurnCntr_MainResets (133u)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134u)
 *   NTC_Num_TurnCntr_SpiDataFlt (135u)
 *   NTC_Num_KinematicIntDiag (144u)
 *   NTC_Num_HighFriction (145u)
 *   NTC_Num_DutyCycleExceeded (148u)
 *   NTC_Num_AbsTempThermLimit (149u)
 *   NTC_Num_EcuCrossChk (150u)
 *   NTC_Num_ImcSigArbHighOffsetCorrection (151u)
 *   NTC_Num_EcuConfigMismatch (152u)
 *   NTC_Num_LatchActive (160u)
 *   NTC_Num_LimpHomeIgnitionCounter (161u)
 *   NTC_Num_AgCompDiagc (167u)
 *   NTC_Num_OpTrqVsHwTrq (168u)
 *   NTC_Num_CurrentReas (169u)
 *   NTC_Num_LoaRpdShutdn (170u)
 *   NTC_Num_LoaCtrldShutdn (171u)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172u)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173u)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174u)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175u)
 *   NTC_Num_OpVoltage (176u)
 *   NTC_Num_ExVoltageLow (177u)
 *   NTC_Num_ReducedAsstLowVoltage (178u)
 *   NTC_Num_ExVoltageHigh (180u)
 *   NTC_Num_OpVoltageOvrMax (181u)
 *   NTC_Num_BattTransOverVolt (182u)
 *   NTC_Num_IgnConfDiag (184u)
 *   NTC_Num_TurnCntr_LowBattery (185u)
 *   NTC_Num_EEPROMCloseFailed (191u)
 *   NTC_Num_SigPath1CrossChk (192u)
 *   NTC_Num_SigPath2CrossChk (193u)
 *   NTC_Num_SigPath3CrossChk (194u)
 *   NTC_Num_SigPath4CrossChk (195u)
 *   NTC_Num_SigPath5CrossChk (196u)
 *   NTC_Num_DampingFWReached (197u)
 *   NTC_Num_AssistFWReached (198u)
 *   NTC_Num_ReturnFWReached (199u)
 *   NTC_Num_DampingFWFltMode (200u)
 *   NTC_Num_AssistFWFltMode (201u)
 *   NTC_Num_VBICFltMode (202u)
 *   NTC_Num_StaMdsSysC (203u)
 *   NTC_NUM_SysFailureForRotVel (204u)
 *   NTC_NUM_SysFailForRedntRotVel (205u)
 *   NTC_Num_SysFailureForTrqSnsr (206u)
 *   NTC_Num_SysFailureForRedTrqSnsr (207u)
 *   NTC_NUM_SysFailureForCtrlVolt (209u)
 *   NTC_Num_GlblSgnlOvrwrtDet (223u)
 *   NTC_Num_VLF_00 (224u)
 *   NTC_Num_VLF_01 (225u)
 *   NTC_Num_VLF_02 (226u)
 *   NTC_Num_VLF_03 (227u)
 *   NTC_Num_VLF_04 (228u)
 *   NTC_Num_VLF_05 (229u)
 *   NTC_Num_VLF_06 (230u)
 *   NTC_Num_VLF_07 (231u)
 *   NTC_Num_VLF_08 (232u)
 *   NTC_Num_VLF_09 (233u)
 *   NTC_Num_VLF_10 (234u)
 *   NTC_Num_VLF_11 (235u)
 *   NTC_Num_VLF_12 (236u)
 *   NTC_Num_VLF_13 (237u)
 *   NTC_Num_VLF_14 (238u)
 *   NTC_Num_VLF_15 (239u)
 *   NTC_Num_VLF_16 (240u)
 *   NTC_Num_VLF_17 (241u)
 *   NTC_Num_VLF_18 (242u)
 *   NTC_Num_VLF_19 (243u)
 *   NTC_Num_VLF_20 (244u)
 *   NTC_Num_VLF_21 (245u)
 *   NTC_Num_VLF_22 (246u)
 *   NTC_Num_VLF_23 (247u)
 *   NTC_Num_VLF_24 (248u)
 *   NTC_Num_VLF_25 (249u)
 *   NTC_Num_VLF_26 (250u)
 *   NTC_Num_VLF_27 (251u)
 *   NTC_Num_VLF_28 (252u)
 *   NTC_Num_VLF_29 (253u)
 *   NTC_Num_VLF_30 (254u)
 *   NTC_Num_VLF_31 (255u)
 *   NTC_Num_BusOffCh1 (256u)
 *   NTC_Num_BusOffCh1NodeMute (257u)
 *   NTC_Num_Node1AAbsent (258u)
 *   NTC_Num_Node1AFaulty (259u)
 *   NTC_Num_Node1BAbsent (260u)
 *   NTC_Num_Node1BFaulty (261u)
 *   NTC_Num_Node1CAbsent (262u)
 *   NTC_Num_Node1CFaulty (263u)
 *   NTC_Num_Node1DAbsent (264u)
 *   NTC_Num_Node1DFaulty (265u)
 *   NTC_Num_Node1EAbsent (266u)
 *   NTC_Num_Node1EFaulty (267u)
 *   NTC_Num_Node1FAbsent (268u)
 *   NTC_Num_Node1FFaulty (269u)
 *   NTC_Num_Node1GAbsent (270u)
 *   NTC_Num_Node1GFaulty (271u)
 *   NTC_Num_BusOffCh2 (272u)
 *   NTC_Num_Node2AAbsent (273u)
 *   NTC_Num_Node2AFaulty (274u)
 *   NTC_Num_Node2BAbsent (275u)
 *   NTC_Num_Node2BFaulty (276u)
 *   NTC_Num_Node2CAbsent (277u)
 *   NTC_Num_Node2CFaulty (278u)
 *   NTC_Num_Node2DAbsent (279u)
 *   NTC_Num_Node2DFaulty (280u)
 *   NTC_Num_Node2EAbsent (281u)
 *   NTC_Num_Node2EFaulty (282u)
 *   NTC_Num_Node2FAbsent (283u)
 *   NTC_Num_Node2FFaulty (284u)
 *   NTC_Num_Node2GAbsent (285u)
 *   NTC_Num_Node2GFaulty (286u)
 *   NTC_Num_InvalidMsg_M (288u)
 *   NTC_Num_MissingMsg_M (289u)
 *   NTC_Num_CRCFltMsg_M (290u)
 *   NTC_Num_PgrsCntFltMsg_M (291u)
 *   NTC_Num_DataRngFltMsg_M (292u)
 *   NTC_Num_DataRateFltMsg_M (293u)
 *   NTC_Num_DataOtherFltMsg_M (294u)
 *   NTC_Num_DataOther2FltMsg_M (295u)
 *   NTC_Num_InvalidMsg_N (296u)
 *   NTC_Num_MissingMsg_N (297u)
 *   NTC_Num_CRCFltMsg_N (298u)
 *   NTC_Num_PgrsCntFltMsg_N (299u)
 *   NTC_Num_DataRngFltMsg_N (300u)
 *   NTC_Num_DataRateFltMsg_N (301u)
 *   NTC_Num_DataOtherFltMsg_N (302u)
 *   NTC_Num_DataOtherFlt2Msg_N (303u)
 *   NTC_Num_InvalidMsg_O (304u)
 *   NTC_Num_MissingMsg_O (305u)
 *   NTC_Num_CRCFltMsg_O (306u)
 *   NTC_Num_PgrsCntFltMsg_O (307u)
 *   NTC_Num_DataRngFltMsg_O (308u)
 *   NTC_Num_DataRateFltMsg_O (309u)
 *   NTC_Num_DataOtherFltMsg_O (310u)
 *   NTC_Num_InvalidMsg_P (312u)
 *   NTC_Num_MissingMsg_P (313u)
 *   NTC_Num_CRCFltMsg_P (314u)
 *   NTC_Num_PgrsCntFltMsg_P (315u)
 *   NTC_Num_DataRngFltMsg_P (316u)
 *   NTC_Num_DataRateFltMsg_P (317u)
 *   NTC_Num_DataOtherFltMsg_P (318u)
 *   NTC_Num_InvalidMsg_Q (320u)
 *   NTC_Num_MissingMsg_Q (321u)
 *   NTC_Num_CRCFltMsg_Q (322u)
 *   NTC_Num_PgrsCntFltMsg_Q (323u)
 *   NTC_Num_DataRngFltMsg_Q (324u)
 *   NTC_Num_DataRateFltMsg_Q (325u)
 *   NTC_Num_DataOtherFltMsg_Q (326u)
 *   NTC_Num_DataOtherFlt2Msg_Q (327u)
 *   NTC_Num_InvalidMsg_R (328u)
 *   NTC_Num_MissingMsg_R (329u)
 *   NTC_Num_CRCFltMsg_R (330u)
 *   NTC_Num_PgrsCntFltMsg_R (331u)
 *   NTC_Num_DataRngFltMsg_R (332u)
 *   NTC_Num_DataRateFltMsg_R (333u)
 *   NTC_Num_DataOtherFltMsg_R (334u)
 *   NTC_Num_DataOtherFlt2Msg_R (335u)
 *   NTC_Num_InvalidMsg_S (336u)
 *   NTC_Num_MissingMsg_S (337u)
 *   NTC_Num_CRCFltMsg_S (338u)
 *   NTC_Num_PgrsCntFltMsg_S (339u)
 *   NTC_Num_DataRngFltMsg_S (340u)
 *   NTC_Num_DataRateFltMsg_S (341u)
 *   NTC_Num_DataOtherFltMsg_S (342u)
 *   NTC_Num_InvalidMsg_T (344u)
 *   NTC_Num_MissingMsg_T (345u)
 *   NTC_Num_CRCFltMsg_T (346u)
 *   NTC_Num_PgrsCntFltMsg_T (347u)
 *   NTC_Num_DataRngFltMsg_T (348u)
 *   NTC_Num_DataRateFltMsg_T (349u)
 *   NTC_Num_DataOtherFltMsg_T (350u)
 *   NTC_Num_InvalidMsg_U (352u)
 *   NTC_Num_MissingMsg_U (353u)
 *   NTC_Num_CRCFltMsg_U (354u)
 *   NTC_Num_PgrsCntFltMsg_U (355u)
 *   NTC_Num_DataRngFltMsg_U (356u)
 *   NTC_Num_DataRateFltMsg_U (357u)
 *   NTC_Num_DataOtherFltMsg_U (358u)
 *   NTC_Num_InvalidMsg_V (360u)
 *   NTC_Num_MissingMsg_V (361u)
 *   NTC_Num_CRCFltMsg_V (362u)
 *   NTC_Num_PgrsCntFltMsg_V (363u)
 *   NTC_Num_DataRngFltMsg_V (364u)
 *   NTC_Num_DataRateFltMsg_V (365u)
 *   NTC_Num_DataOtherFltMsg_V (366u)
 *   NTC_Num_InvalidMsg_W (368u)
 *   NTC_Num_MissingMsg_W (369u)
 *   NTC_Num_CRCFltMsg_W (370u)
 *   NTC_Num_PgrsCntFltMsg_W (371u)
 *   NTC_Num_DataRngFltMsg_W (372u)
 *   NTC_Num_DataRateFltMsg_W (373u)
 *   NTC_Num_DataOtherFltMsg_W (374u)
 *   NTC_Num_InvalidMsg_X (376u)
 *   NTC_Num_MissingMsg_X (377u)
 *   NTC_Num_CRCFltMsg_X (378u)
 *   NTC_Num_PgrsCntFltMsg_X (379u)
 *   NTC_Num_DataRngFltMsg_X (380u)
 *   NTC_Num_DataRateFltMsg_X (381u)
 *   NTC_Num_DataOtherFltMsg_X (382u)
 *   NTC_Num_InvalidMsg_Y (384u)
 *   NTC_Num_MissingMsg_Y (385u)
 *   NTC_Num_CRCFltMsg_Y (386u)
 *   NTC_Num_PgrsCntFltMsg_Y (387u)
 *   NTC_Num_DataRngFltMsg_Y (388u)
 *   NTC_Num_DataRateFltMsg_Y (389u)
 *   NTC_Num_DataOtherFltMsg_Y (390u)
 *   NTC_Num_InvalidMsg_Z (392u)
 *   NTC_Num_MissingMsg_Z (393u)
 *   NTC_Num_CRCFltMsg_Z (394u)
 *   NTC_Num_PgrsCntFltMsg_Z (395u)
 *   NTC_Num_DataRngFltMsg_Z (396u)
 *   NTC_Num_DataRateFltMsg_Z (397u)
 *   NTC_Num_DataOtherFltMsg_Z (398u)
 *   NTC_Num_DSTXORActive (399u)
 *   NTC_Num_InvalidMsg_AA (400u)
 *   NTC_Num_MissingMsg_AA (401u)
 *   NTC_Num_CRCFltMsg_AA (402u)
 *   NTC_Num_PgrsCntFltMsg_AA (403u)
 *   NTC_Num_DataRngFltMsg_AA (404u)
 *   NTC_Num_DataRateFltMsg_AA (405u)
 *   NTC_Num_DataOtherFltMsg_AA (406u)
 *   NTC_Num_InvalidMsg_AB (408u)
 *   NTC_Num_MissingMsg_AB (409u)
 *   NTC_Num_CRCFltMsg_AB (410u)
 *   NTC_Num_PgrsCntFltMsg_AB (411u)
 *   NTC_Num_DataRngFltMsg_AB (412u)
 *   NTC_Num_DataRateFltMsg_AB (413u)
 *   NTC_Num_DataOtherFltMsg_AB (414u)
 *   NTC_Num_InvalidMsg_AC (416u)
 *   NTC_Num_MissingMsg_AC (417u)
 *   NTC_Num_CRCFltMsg_AC (418u)
 *   NTC_Num_PgrsCntFltMsg_AC (419u)
 *   NTC_Num_DataRngFltMsg_AC (420u)
 *   NTC_Num_DataRateFltMsg_AC (421u)
 *   NTC_Num_DataOtherFltMsg_AC (422u)
 *   NTC_Num_InvalidMsg_AD (424u)
 *   NTC_Num_MissingMsg_AD (425u)
 *   NTC_Num_CRCFltMsg_AD (426u)
 *   NTC_Num_PgrsCntFltMsg_AD (427u)
 *   NTC_Num_DataRngFltMsg_AD (428u)
 *   NTC_Num_DataRateFltMsg_AD (429u)
 *   NTC_Num_DataOtherFltMsg_AD (430u)
 *   NTC_Num_InvalidMsg_AE (432u)
 *   NTC_Num_MissingMsg_AE (433u)
 *   NTC_Num_CRCFltMsg_AE (434u)
 *   NTC_Num_PgrsCntFltMsg_AE (435u)
 *   NTC_Num_DataRngFltMsg_AE (436u)
 *   NTC_Num_DataRateFltMsg_AE (437u)
 *   NTC_Num_DataOtherFltMsg_AE (438u)
 *   NTC_Num_InvalidMsg_AF (440u)
 *   NTC_Num_MissingMsg_AF (441u)
 *   NTC_Num_CRCFltMsg_AF (442u)
 *   NTC_Num_PgrsCntFltMsg_AF (443u)
 *   NTC_Num_DataRngFltMsg_AF (444u)
 *   NTC_Num_DataRateFltMsg_AF (445u)
 *   NTC_Num_DataOtherFltMsg_AF (446u)
 *   NTC_Num_InvalidMsg_AG (448u)
 *   NTC_Num_MissingMsg_AG (449u)
 *   NTC_Num_CRCFltMsg_AG (450u)
 *   NTC_Num_PgrsCntFltMsg_AG (451u)
 *   NTC_Num_DataRngFltMsg_AG (452u)
 *   NTC_Num_DataRateFltMsg_AG (453u)
 *   NTC_Num_DataOtherFltMsg_AG (454u)
 *   NTC_Num_InvalidMsg_AH (456u)
 *   NTC_Num_MissingMsg_AH (457u)
 *   NTC_Num_CRCFltMsg_AH (458u)
 *   NTC_Num_PgrsCntFltMsg_AH (459u)
 *   NTC_Num_DataRngFltMsg_AH (460u)
 *   NTC_Num_DataRateFltMsg_AH (461u)
 *   NTC_Num_DataOtherFltMsg_AH (462u)
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464u)
 *   NTC_Num_FlexrayCommunicationError (465u)
 *   NTC_Num_InvalidMsg_AI (466u)
 *   NTC_Num_MissingMsg_AI (467u)
 *   NTC_Num_InvalidMsg_AJ (472u)
 *   NTC_Num_MissingMsg_AJ (473u)
 *   NTC_Num_InvalidMsg_AK (480u)
 *   NTC_Num_MissingMsg_AK (481u)
 *   NTC_Num_MissingMsg_AM (482u)
 *   NTC_Num_InvalidMsg_AM (483u)
 *   NTC_Num_CRCFltMsg_AM (484u)
 *   NTC_Num_PgrsCntFltMsg_AM (485u)
 *   NTC_Num_DataRngFltMsg_AM (486u)
 *   NTC_Num_InvalidMsg_AL (488u)
 *   NTC_Num_MissingMsg_AL (489u)
 *   NTC_Num_DataRngFltMsg_AL (492u)
 *   NTC_Num_DataOtherFltMsg_AL (494u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_TunSetNotPrgmd (499u)
 *   NTC_Num_PHAPosnSnsrVsPwrpkDataWrong (500u)
 *   NTC_Num_EEPROMtoFeeCpyError (500u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_PHAScratchPadTrf (503u)
 *   NTC_Num_HWASensorNotTrimmed (504u)
 *   NTC_Num_HWASensorTrimNoAttempt (505u)
 *   NTC_Num_TrqSensorScaleNotSet (506u)
 *   NTC_Num_TrqSensorNotTrimmed (507u)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508u)
 *   NTC_Num_DigTrqSensorScaleNotSet (509u)
 *   NTC_Num_DigTrqSensorNotTrimmed (510u)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511u)
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0u)
 *   NVM_REQ_NOT_OK (1u)
 *   NVM_REQ_PENDING (2u)
 *   NVM_REQ_INTEGRITY_FAILED (3u)
 *   NVM_REQ_BLOCK_SKIPPED (4u)
 *   NVM_REQ_NV_INVALIDATED (5u)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
 * SigQlfr_State_enum: Enumeration of integer in interval [0...2] with enumerators
 *   SIGQLFR_NORES (0u)
 *   SIGQLFR_PASS (1u)
 *   SIGQLFR_FAIL (2u)
 *
 * Array Types:
 * ============
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * AnaHwTrqScale_Datatype: Record with elements
 *   HwTrqScale_VoltsPerDeg_f32 of type Float
 *   HwTrqScalePerf_Cnt_lgc of type Boolean
 * AnaHwTrqTrim_Datatype: Record with elements
 *   T1Trim_Volts_f32 of type Float
 *   T2Trim_Volts_f32 of type Float
 *   HwTrqTrimPerf_Cnt_lgc of type Boolean
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
 * Float: D_ZERO_ULS_F32 = 0
 * SInt8: D_ZERO_CNT_S8 = 0
 * SigQlfr_State_enum: D_SIGQLFRNORES_CNT_ENUM = 0u
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   AnaHwTrqScale_Datatype *Rte_Pim_AnaHwTrqScaleData(void)
 *   AnaHwTrqTrim_Datatype *Rte_Pim_AnaHwTrqT1T2TrimData(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_ANAHWTRQ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_Init
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
 *   void Rte_IWrite_AnaHwTrq_Init_HwTq1Qlfr_State_enum(SigQlfr_State_enum data)
 *   SigQlfr_State_enum *Rte_IWriteRef_AnaHwTrq_Init_HwTq1Qlfr_State_enum(void)
 *   void Rte_IWrite_AnaHwTrq_Init_HwTq1RollgCntr_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_AnaHwTrq_Init_HwTq1RollgCntr_Cnt_u08(void)
 *   void Rte_IWrite_AnaHwTrq_Init_HwTq2Qlfr_State_enum(SigQlfr_State_enum data)
 *   SigQlfr_State_enum *Rte_IWriteRef_AnaHwTrq_Init_HwTq2Qlfr_State_enum(void)
 *   void Rte_IWrite_AnaHwTrq_Init_HwTq2RollgCntr_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_AnaHwTrq_Init_HwTq2RollgCntr_Cnt_u08(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AnaHwTrq_Init
 *********************************************************************************************************************/
	/* Initialization */
	AnaHwTrqErr_Cnt_M_str.Threshold = 0xFFu;
	AnaHwTrqErr_Cnt_M_str.PStep = (uint16)k_AnaTrqErrorPstep_Cnt_u08;
	AnaHwTrqErr_Cnt_M_str.NStep = (uint16)k_AnaTrqErrorNstep_Cnt_u08;
	
	AnaHwTrq1Qlfr_Cnt_M_u08 = SIGQLFR_PASS;
	AnaHwTrq1RollgCntr_Cnt_M_u08 = D_ZERO_CNT_U8;
	AnaHwTrq2Qlfr_Cnt_M_u08 = SIGQLFR_PASS;
	AnaHwTrq2RollgCntr_Cnt_M_u08 = D_ZERO_CNT_U8;
	AnaTrq1ErrAcc_Cnt_M_u08 = D_ZERO_CNT_U8;
	AnaTrq2ErrAcc_Cnt_M_u08 = D_ZERO_CNT_U8;
	
	(void)Rte_IWrite_AnaHwTrq_Init_HwTq1Qlfr_State_enum(AnaHwTrq1Qlfr_Cnt_M_u08);
	(void)Rte_IWrite_AnaHwTrq_Init_HwTq1RollgCntr_Cnt_u08(AnaHwTrq1RollgCntr_Cnt_M_u08);
	(void)Rte_IWrite_AnaHwTrq_Init_HwTq2Qlfr_State_enum(AnaHwTrq2Qlfr_Cnt_M_u08);
	(void)Rte_IWrite_AnaHwTrq_Init_HwTq2RollgCntr_Cnt_u08(AnaHwTrq2RollgCntr_Cnt_M_u08);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_Per1
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
 *   SInt8 Rte_IRead_AnaHwTrq_Per1_HwTq1Polarity_Cnt_s08(void)
 *   Float Rte_IRead_AnaHwTrq_Per1_T1ADC_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AnaHwTrq_Per1_HwTq1Qlfr_State_enum(SigQlfr_State_enum data)
 *   SigQlfr_State_enum *Rte_IWriteRef_AnaHwTrq_Per1_HwTq1Qlfr_State_enum(void)
 *   void Rte_IWrite_AnaHwTrq_Per1_HwTq1RollgCntr_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_AnaHwTrq_Per1_HwTq1RollgCntr_Cnt_u08(void)
 *   void Rte_IWrite_AnaHwTrq_Per1_HwTq1Val_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_AnaHwTrq_Per1_HwTq1Val_HwNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AnaHwTrq_Per1
 *********************************************************************************************************************/
	/* Hw Torque 1 Calculation */
	VAR(float32, AUTOMATIC) Torque1_Volt_T_f32;
	VAR(float32, AUTOMATIC) AnaHwTq1_HwNm_T_f32;
	VAR(float32, AUTOMATIC) AnaHwTorque1_HwNm_T_f32;
	VAR(sint8,   AUTOMATIC) HwTrq1Polarity_Cnt_T_s08;
	VAR(float32, AUTOMATIC) HwTrq1Polarity_Cnt_T_f32;
	
	Torque1_Volt_T_f32 = Rte_IRead_AnaHwTrq_Per1_T1ADC_Volt_f32();
	HwTrq1Polarity_Cnt_T_s08 = Rte_IRead_AnaHwTrq_Per1_HwTq1Polarity_Cnt_s08();
	
	HwTrq1Polarity_Cnt_T_f32 = (float32)HwTrq1Polarity_Cnt_T_s08;

	if ((Torque1_Volt_T_f32 < k_T1LowRange_Volts_f32) || (Torque1_Volt_T_f32 > k_T1HghRange_Volts_f32))		/* Test Not OK */
	{
		AnaTrq1ErrAcc_Cnt_M_u08 = (uint8)DiagPStep_m((uint16)(AnaTrq1ErrAcc_Cnt_M_u08), AnaHwTrqErr_Cnt_M_str);
		if ( DiagFailed_m((uint16)AnaTrq1ErrAcc_Cnt_M_u08, AnaHwTrqErr_Cnt_M_str) == TRUE )
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T1OutofRange, 0x01U, NTC_STATUS_FAILED);
			AnaHwTrq1Qlfr_Cnt_M_u08 = SIGQLFR_FAIL;
		}
	}
	else																									/* Test OK */
	{
		AnaHwTq1_Volt_M_f32 = Torque1_Volt_T_f32;
		
		/* Update rolling counter */
		AnaHwTrq1RollgCntr_Cnt_M_u08 = AnaHwTrq1RollgCntr_Cnt_M_u08 + 0x01u; /* Intentionally allow overflow to allow the variable to go from 0xFF to 0x00 */
		
		/* Check accumulator for Pass threshold */
		AnaTrq1ErrAcc_Cnt_M_u08 = (uint8)DiagNStep_m((uint16)(AnaTrq1ErrAcc_Cnt_M_u08), AnaHwTrqErr_Cnt_M_str);
		if(AnaTrq1ErrAcc_Cnt_M_u08 == 0x0u)
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T1OutofRange, 0x00U, NTC_STATUS_PASSED);
			AnaHwTrq1Qlfr_Cnt_M_u08 = SIGQLFR_PASS;
		}
	}

	/* Apply Trim and Convert Volts to HwNm  */
	AnaHwTq1_HwNm_T_f32 = 
	((((AnaHwTq1_Volt_M_f32 - Rte_Pim_AnaHwTrqT1T2TrimData()->T1Trim_Volts_f32) * k_TbarStiff_NmpDeg_f32) / Rte_Pim_AnaHwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32) * D_TWO_ULS_F32) * HwTrq1Polarity_Cnt_T_f32;
	
	AnaHwTorque1_HwNm_T_f32 = Limit_m(AnaHwTq1_HwNm_T_f32, D_HWTRQLOLMT_HWNM_F32, D_HWTRQHILMT_HWNM_F32);

    #if(STD_ON == BC_ANAHWTRQ_T1FLTINJ)
        Rte_Call_FaultInjection_SCom_FltInjection(&AnaHwTorque1_HwNm_T_f32,FLTINJ_ANAHWTRQT1);
	#endif
	
	(void) Rte_IWrite_AnaHwTrq_Per1_HwTq1Qlfr_State_enum(AnaHwTrq1Qlfr_Cnt_M_u08);
	(void) Rte_IWrite_AnaHwTrq_Per1_HwTq1RollgCntr_Cnt_u08(AnaHwTrq1RollgCntr_Cnt_M_u08);
	(void) Rte_IWrite_AnaHwTrq_Per1_HwTq1Val_HwNm_f32(AnaHwTorque1_HwNm_T_f32);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_Per2
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
 *   SInt8 Rte_IRead_AnaHwTrq_Per2_HwTq2Polarity_Cnt_s08(void)
 *   Float Rte_IRead_AnaHwTrq_Per2_T2ADC_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_AnaHwTrq_Per2_HwTq2Qlfr_State_enum(SigQlfr_State_enum data)
 *   SigQlfr_State_enum *Rte_IWriteRef_AnaHwTrq_Per2_HwTq2Qlfr_State_enum(void)
 *   void Rte_IWrite_AnaHwTrq_Per2_HwTq2RollgCntr_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_AnaHwTrq_Per2_HwTq2RollgCntr_Cnt_u08(void)
 *   void Rte_IWrite_AnaHwTrq_Per2_HwTq2Val_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_AnaHwTrq_Per2_HwTq2Val_HwNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AnaHwTrq_Per2
 *********************************************************************************************************************/
	/* Hw Torque 2 Calculation */
	VAR(float32, AUTOMATIC) Torque2_Volt_T_f32;
	VAR(float32, AUTOMATIC) AnaHwTq2_HwNm_T_f32;
	VAR(float32, AUTOMATIC) AnaHwTorque2_HwNm_T_f32;
	VAR(sint8,   AUTOMATIC) HwTrq2Polarity_Cnt_T_s08;
	VAR(float32, AUTOMATIC) HwTrq2Polarity_Cnt_T_f32;
	
	Torque2_Volt_T_f32 = Rte_IRead_AnaHwTrq_Per2_T2ADC_Volt_f32();
	HwTrq2Polarity_Cnt_T_s08 = Rte_IRead_AnaHwTrq_Per2_HwTq2Polarity_Cnt_s08();
	
	HwTrq2Polarity_Cnt_T_f32 = (float32)HwTrq2Polarity_Cnt_T_s08;

	if ((Torque2_Volt_T_f32 < k_T2LowRange_Volts_f32) || (Torque2_Volt_T_f32 > k_T2HghRange_Volts_f32))		/* Test Not OK */
	{
		AnaTrq2ErrAcc_Cnt_M_u08 = (uint8)DiagPStep_m((uint16)(AnaTrq2ErrAcc_Cnt_M_u08), AnaHwTrqErr_Cnt_M_str);
		if ( DiagFailed_m((uint16)AnaTrq2ErrAcc_Cnt_M_u08, AnaHwTrqErr_Cnt_M_str) == TRUE )
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T2OutofRange, 0x01U, NTC_STATUS_FAILED);
			AnaHwTrq2Qlfr_Cnt_M_u08 = SIGQLFR_FAIL;
		}
	}
	else																									/* Test OK */
	{
		AnaHwTq2_Volt_M_f32 = Torque2_Volt_T_f32;
		
		/* Update rolling counter */
		AnaHwTrq2RollgCntr_Cnt_M_u08 = AnaHwTrq2RollgCntr_Cnt_M_u08 + 0x01u;	/* Intentionally allow overflow to allow the variable to go from 0xFF to 0x00 */
		
		/* Check accumulator for Pass threshold */
		AnaTrq2ErrAcc_Cnt_M_u08 = (uint8)DiagNStep_m((uint16)(AnaTrq2ErrAcc_Cnt_M_u08), AnaHwTrqErr_Cnt_M_str);
		if(AnaTrq2ErrAcc_Cnt_M_u08 == 0x0u)
		{
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_T2OutofRange, 0x00U, NTC_STATUS_PASSED);
			AnaHwTrq2Qlfr_Cnt_M_u08 = SIGQLFR_PASS;
		}
	}

	/* Apply Trim and Convert Volts to HwNm  */
	AnaHwTq2_HwNm_T_f32 = 
	((((AnaHwTq2_Volt_M_f32 - Rte_Pim_AnaHwTrqT1T2TrimData()->T2Trim_Volts_f32) * k_TbarStiff_NmpDeg_f32) / Rte_Pim_AnaHwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32) * D_TWO_ULS_F32) * HwTrq2Polarity_Cnt_T_f32;
	
	AnaHwTorque2_HwNm_T_f32 = Limit_m(AnaHwTq2_HwNm_T_f32, D_HWTRQLOLMT_HWNM_F32, D_HWTRQHILMT_HWNM_F32);
    
    #if(STD_ON == BC_ANAHWTRQ_T2FLTINJ)
        Rte_Call_FaultInjection_SCom_FltInjection(&AnaHwTorque2_HwNm_T_f32,FLTINJ_ANAHWTRQT2);
	#endif
	
	(void) Rte_IWrite_AnaHwTrq_Per2_HwTq2Qlfr_State_enum(AnaHwTrq2Qlfr_Cnt_M_u08);
	(void) Rte_IWrite_AnaHwTrq_Per2_HwTq2RollgCntr_Cnt_u08(AnaHwTrq2RollgCntr_Cnt_M_u08);
	(void) Rte_IWrite_AnaHwTrq_Per2_HwTq2Val_HwNm_f32(AnaHwTorque2_HwNm_T_f32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   ManufModeType Rte_IRead_AnaHwTrq_Per3_MECCounter_Cnt_enum(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_Per3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AnaHwTrq_Per3
 *********************************************************************************************************************/
	/* Analog T1T2 Offset Not Performed Diagnostic */

	VAR(ManufModeType, AUTOMATIC) MECCounter_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) AnaHwTrq_EOLT1T2TrimPerf_Cnt_T_lgc;
	
	MECCounter_Cnt_T_enum = Rte_IRead_AnaHwTrq_Per3_MECCounter_Cnt_enum();
	AnaHwTrq_EOLT1T2TrimPerf_Cnt_T_lgc = Rte_Pim_AnaHwTrqT1T2TrimData()->HwTrqTrimPerf_Cnt_lgc;
	
	if(((MECCounter_Cnt_T_enum == ProductionMode) || (MECCounter_Cnt_T_enum == EngineeringMode)) && (AnaHwTrq_EOLT1T2TrimPerf_Cnt_T_lgc == FALSE))
	{
		/* Set NTC 1FB */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TrqSensorNotTrimmed, 0x01u, NTC_STATUS_FAILED);
	}
	else
	{
		/* Clear NTC 1FB */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TrqSensorNotTrimmed, 0x00u, NTC_STATUS_PASSED);
	}
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_Per4
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   ManufModeType Rte_IRead_AnaHwTrq_Per4_MECCounter_Cnt_enum(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_Per4(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AnaHwTrq_Per4
 *********************************************************************************************************************/
	/* Analog Torque Sensor Scale Not Performed Diagnostic */

	VAR(ManufModeType, AUTOMATIC) MECCounter_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) AnaHwTrq_EOLHwTrqScale_Cnt_T_lgc;

	AnaHwTrq_EOLHwTrqScale_Cnt_T_lgc = Rte_Pim_AnaHwTrqScaleData()->HwTrqScalePerf_Cnt_lgc;

	MECCounter_Cnt_T_enum = Rte_IRead_AnaHwTrq_Per4_MECCounter_Cnt_enum();
	
	if(((MECCounter_Cnt_T_enum == ProductionMode) || (MECCounter_Cnt_T_enum == EngineeringMode)) && (AnaHwTrq_EOLHwTrqScale_Cnt_T_lgc == FALSE))
	{
		/* Set NTC 1FA */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TrqSensorScaleNotSet, 0x01u, NTC_STATUS_FAILED);
	}
	else
	{
		/* Clear NTC 1FA */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TrqSensorScaleNotSet, 0x00u, NTC_STATUS_PASSED);
	}
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrAnaHwTrqScaleTrim> of PortPrototype <AnaHwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AnaHwTrqScale_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_AnaHwTrqScale_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim (returns application error)
 *********************************************************************************************************************/
	/* Clear Analog Torque Sensor Scale Trim */
	VAR(Std_ReturnType, AUTOMATIC) RetCode;

	Rte_Pim_AnaHwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32 = k_AnaHwTrqSclNom_VoltspDeg_f32;
	Rte_Pim_AnaHwTrqScaleData()->HwTrqScalePerf_Cnt_lgc = FALSE;

	(void) Rte_Call_AnaHwTrqScale_WriteBlock(NULL_PTR);
	RetCode = RTE_E_OK;

	/* Torque Scale Trim Performed Diagnostic functions will be called every 100mS */
	
	return(RetCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_SCom_ClrT1T2OffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrT1T2OffsetTrim> of PortPrototype <AnaHwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AnaHwTrqTrim_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_AnaHwTrqTrim_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType AnaHwTrq_SCom_ClrT1T2OffsetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_ClrT1T2OffsetTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AnaHwTrq_SCom_ClrT1T2OffsetTrim (returns application error)
 *********************************************************************************************************************/
	/* Clear Analog T1 T2 Offset Trim */
	VAR(Std_ReturnType, AUTOMATIC) RetCode;

	Rte_Pim_AnaHwTrqT1T2TrimData()->T1Trim_Volts_f32 = D_DFLTRTRQTRIM_VOLT_F32;
	Rte_Pim_AnaHwTrqT1T2TrimData()->T2Trim_Volts_f32 = D_DFLTRTRQTRIM_VOLT_F32;

	Rte_Pim_AnaHwTrqT1T2TrimData()->HwTrqTrimPerf_Cnt_lgc = FALSE;

	(void) Rte_Call_AnaHwTrqTrim_WriteBlock(NULL_PTR);
	
	/* Torque Offset Trim Performed Diagnostic functions will be called every 100mS */
	
	RetCode = RTE_E_OK;

	return(RetCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_SCom_ReadAnaHwTrqScaleTrim
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadAnaHwTrqScaleTrim> of PortPrototype <AnaHwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AnaHwTrq_SCom_ReadAnaHwTrqScaleTrim(AnaHwTrqScale_Datatype *HwTrqScaleDataPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_ReadAnaHwTrqScaleTrim(P2VAR(AnaHwTrqScale_Datatype, AUTOMATIC, RTE_SA_ANAHWTRQ_APPL_VAR) HwTrqScaleDataPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AnaHwTrq_SCom_ReadAnaHwTrqScaleTrim
 *********************************************************************************************************************/
	/* Read Analog Torque Sensor Scale Trim */
	*HwTrqScaleDataPtr = *Rte_Pim_AnaHwTrqScaleData();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_SCom_ReadT1T2OffsetTrim
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadT1T2OffsetTrim> of PortPrototype <AnaHwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void AnaHwTrq_SCom_ReadT1T2OffsetTrim(AnaHwTrqTrim_Datatype *HwTrqTrimDataPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_ReadT1T2OffsetTrim(P2VAR(AnaHwTrqTrim_Datatype, AUTOMATIC, RTE_SA_ANAHWTRQ_APPL_VAR) HwTrqTrimDataPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AnaHwTrq_SCom_ReadT1T2OffsetTrim
 *********************************************************************************************************************/
	/* Read Analog T1 T2 Offset Trim */
	*HwTrqTrimDataPtr = *Rte_Pim_AnaHwTrqT1T2TrimData();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_SCom_SetAnaHwTrqScaleTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetAnaHwTrqScaleTrim> of PortPrototype <AnaHwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AnaHwTrqScale_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_AnaHwTrqScale_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType AnaHwTrq_SCom_SetAnaHwTrqScaleTrim(Float ScaleValue)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_SetAnaHwTrqScaleTrim(Float ScaleValue)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AnaHwTrq_SCom_SetAnaHwTrqScaleTrim (returns application error)
 *********************************************************************************************************************/
	/* Set Analog Torque Sensor Scale Trim */
	VAR(Std_ReturnType, AUTOMATIC) RetCode;
	VAR(boolean, AUTOMATIC) TrqScaleInRng_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) NewTrqScale_VoltpDeg_f32;

	NewTrqScale_VoltpDeg_f32 = ScaleValue;

	TrqScaleInRng_Cnt_T_lgc = IsTrqScaleInRng_lgc(NewTrqScale_VoltpDeg_f32);

	if (TRUE == TrqScaleInRng_Cnt_T_lgc)
	{
		Rte_Pim_AnaHwTrqScaleData()->HwTrqScale_VoltsPerDeg_f32 = NewTrqScale_VoltpDeg_f32;
		Rte_Pim_AnaHwTrqScaleData()->HwTrqScalePerf_Cnt_lgc = TRUE;

		(void) Rte_Call_AnaHwTrqScale_WriteBlock(NULL_PTR);
		RetCode = RTE_E_OK;
	}
	else
	{
		RetCode = RTE_E_AnaHwTrq_SCom_DataOutOfRange;
		Rte_Pim_AnaHwTrqScaleData()->HwTrqScalePerf_Cnt_lgc = FALSE;
		(void) Rte_Call_AnaHwTrqScale_WriteBlock(NULL_PTR);
	}

	/* Torque Scale Trim Performed Diagnostic functions will be called every 100mS */
		
	return(RetCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_SCom_SetT1T2OffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetT1T2OffsetTrim> of PortPrototype <AnaHwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_T1ADC_Volt_f32(Float *data)
 *   Std_ReturnType Rte_Read_T2ADC_Volt_f32(Float *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTq1Val_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_HwTq2Val_HwNm_f32(Float data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AnaHwTrqTrim_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_AnaHwTrqTrim_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType AnaHwTrq_SCom_SetT1T2OffsetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_SetT1T2OffsetTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AnaHwTrq_SCom_SetT1T2OffsetTrim (returns application error)
 *********************************************************************************************************************/
	/* Set Analog T1 T2 Offset Trim */
	VAR(Std_ReturnType, AUTOMATIC) RetCode;
	VAR(float32, AUTOMATIC) Torque1_Volt_T_f32;
	VAR(float32, AUTOMATIC) Torque2_Volt_T_f32;
	VAR(float32, AUTOMATIC) HwTrqTrim_Volt_T_f32;

	(void) Rte_Read_T1ADC_Volt_f32(&Torque1_Volt_T_f32);
	(void) Rte_Read_T2ADC_Volt_f32(&Torque2_Volt_T_f32);

	HwTrqTrim_Volt_T_f32 = Torque1_Volt_T_f32 - Torque2_Volt_T_f32;

	if ((Abs_f32_m(HwTrqTrim_Volt_T_f32)) <= k_MaxHwTrqTrim_Volts_f32)
	{
		Rte_Pim_AnaHwTrqT1T2TrimData()->T1Trim_Volts_f32 = Torque1_Volt_T_f32;
		Rte_Pim_AnaHwTrqT1T2TrimData()->T2Trim_Volts_f32 = Torque2_Volt_T_f32;

		Rte_Pim_AnaHwTrqT1T2TrimData()->HwTrqTrimPerf_Cnt_lgc = TRUE;

		(void) Rte_Call_AnaHwTrqTrim_WriteBlock(NULL_PTR);
		RetCode = RTE_E_OK;
	}
	else
	{
		RetCode = RTE_E_AnaHwTrq_SCom_DataOutOfRange;
		Rte_Pim_AnaHwTrqT1T2TrimData()->HwTrqTrimPerf_Cnt_lgc = FALSE;
		(void) Rte_Call_AnaHwTrqTrim_WriteBlock(NULL_PTR);
	}

	/* Torque Offset Trim Performed Diagnostic functions will be called every 100mS */
	
	return(RetCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_SCom_WriteT1T2OffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteT1T2OffsetTrim> of PortPrototype <AnaHwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_HwTq1Val_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_HwTq2Val_HwNm_f32(Float data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_AnaHwTrqTrim_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_AnaHwTrqTrim_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType AnaHwTrq_SCom_WriteT1T2OffsetTrim(const AnaHwTrqTrim_Datatype *HwTrqTrimDataPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_ANAHWTRQ_APPL_CODE) AnaHwTrq_SCom_WriteT1T2OffsetTrim(P2CONST(AnaHwTrqTrim_Datatype, AUTOMATIC, RTE_SA_ANAHWTRQ_APPL_DATA) HwTrqTrimDataPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AnaHwTrq_SCom_WriteT1T2OffsetTrim (returns application error)
 *********************************************************************************************************************/
	/* Write Analog T1 T2 Offset Trim */
	VAR(Std_ReturnType, AUTOMATIC) RetCode;

	Rte_Pim_AnaHwTrqT1T2TrimData()->T1Trim_Volts_f32 = (float32)HwTrqTrimDataPtr->T1Trim_Volts_f32;
	Rte_Pim_AnaHwTrqT1T2TrimData()->T2Trim_Volts_f32 = (float32)HwTrqTrimDataPtr->T2Trim_Volts_f32;
	
	Rte_Pim_AnaHwTrqT1T2TrimData()->HwTrqTrimPerf_Cnt_lgc = (boolean)HwTrqTrimDataPtr->HwTrqTrimPerf_Cnt_lgc;

	(void) Rte_Call_AnaHwTrqTrim_WriteBlock(NULL_PTR);
	RetCode = RTE_E_OK;

	/* Torque Offset Trim Performed Diagnostic functions will be called every 100mS */
		
	return(RetCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_ANAHWTRQ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
/******************************************************************************
  * Name:        IsTrqScaleInRng_lgc
  * Description: Range Validity Check for Torque Scale EOL value
  * Inputs:      TrqScale_VltspDeg_f32
  * Outputs:     TrqSclInRng_Cnt_T_lgc
  ****************************************************************************/
STATIC FUNC(boolean, SA_ANAHWTRQ_CODE) IsTrqScaleInRng_lgc(VAR(float32, AUTOMATIC)TrqScale_VoltpDeg_T_f32)
{
	VAR(boolean, AUTOMATIC) TrqSclInRng_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) Limit_VoltpDeg_T_f32;

	Limit_VoltpDeg_T_f32 = k_AnaHwTrqSclNom_VoltspDeg_f32 * D_TRQSCALEWNDW_ULS_F32;

	if( (TrqScale_VoltpDeg_T_f32 >= (k_AnaHwTrqSclNom_VoltspDeg_f32 - Limit_VoltpDeg_T_f32)) &&
		(TrqScale_VoltpDeg_T_f32 <= (k_AnaHwTrqSclNom_VoltspDeg_f32 + Limit_VoltpDeg_T_f32)))
	{
		TrqSclInRng_Cnt_T_lgc = TRUE;
	}
	else
	{
		TrqSclInRng_Cnt_T_lgc = FALSE;
	}

	return(TrqSclInRng_Cnt_T_lgc);
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
