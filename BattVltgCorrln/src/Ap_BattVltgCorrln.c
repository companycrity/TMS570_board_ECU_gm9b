/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_BattVltgCorrln.c
 *     Workspace:  C:/SynergyWorkArea/Working/BattVltgCorrln/autosar
 *     SW-C Type:  Ap_BattVltgCorrln
 *  Generated at:  Wed May 18 18:30:45 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_BattVltgCorrln>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /*
 * Copyright 2015,2016 Nexteer Automotive
 * Nexteer Confidential
 *
 * Version Control:
 * Date Created:      Tue Jun 02 18:34:17 2015
 * %version:          EA3#2 %
 * %date_modified:    Mon Jun 08 17:03:12 2015 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/05/15   1       JK        Initial version                                                                  13401
 * 15/10/15   2       JK        Anomaly fix EA3#3872 - Incorrect BattVltg Correlation Status output           EA3#3909
 * 05/04/16   3       JK        Updated to FDD v2.0.0                                                         EA3#8425
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


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_BattVltgCorrln.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
#include "CalConstants.h"
#include "GlobalMacro.h"

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance.  Rule suppressed by line at each occurrence.*/

/* MISRA-C:2004 Rule 8.7: This deviation is required to keep the memory map intact.  Rule suppressed by line at each occurrence. */

#define D_IDPTSIGCNTMIN_CNT_U08  0U
#define D_IDPTSIGCNTMAX_CNT_U08  3U
#define D_CORRLNSTSMIN_CNT_U08  0U
#define D_CORRLNSTSMAX_CNT_U08  7U

typedef struct {
	VAR(uint8, AUTOMATIC)  BattVltgOk_u08;
	VAR(uint8, AUTOMATIC)  BattVltgSwd1Ok_u08;
	VAR(uint8, AUTOMATIC)  BattVltgSwd2Ok_u08;
}InstCorrlnTest_Str;

#define BATTVLTGCORRLN_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* The FDD implements the correlation tests based on truth tables.
 * In order to reduce the cyclomatic complexity and for optimization,code implements the same based on look up table.
 * For example condition BattVltgvsBattVltgSwd1 = 1 signal is treated as uint8 instead of boolean.
 * Thus the three resulting condition signals are shifted to form an uint8 index for the look up table.
 * In the TestOK TruthTable in FDD we have D1 --> T , T , T
 * So the index in this case would be : Index = 1 + (1 << 1) + (1 << 2) which is equal to 7.
 * D4 --> F , T , F, so Index = 0 + (1 << 1) + (0 << 2) which is equal to 2
 * Similarly all the cases D1,D2,D3 etc will result in an index from 0 to 7
 * Now in FDD D1 refers to action table 1
 * In look up based implementation D1 corresponds to index 7 and our values for row 7 will be the action table 1 which is 1,1,1 .......
 * Similarly we have it for all index */

/* Look up table corresponding to TestOK Truth Table */
STATIC CONST(InstCorrlnTest_Str, AP_BATTVLTGCORRLN_APPL_CODE) T_BATCRLN_INSTCORRLNTESTTABLE_CNT_STR[8] = {                  /* PRQA S 3218 */
		{0u,0u,0u},
		{1u,1u,0u},
		{0u,1u,1u},
		{1u,1u,1u},
		{1u,0u,1u},
		{1u,1u,1u},
		{1u,1u,1u},
		{1u,1u,1u}
	}; 
#define BATTVLTGCORRLN_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define BATTVLTGCORRLN_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_NTC49FltAcc_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_NTC4AFltAcc_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_NTC5AFltAcc_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_NTC5BFltAcc_Cnt_M_u16; /* PRQA S 3218 */
#define BATTVLTGCORRLN_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define BATTVLTGCORRLN_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
/* NTC status variables */
STATIC VAR(uint8, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_NTC49Sts_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_NTC4ASts_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_NTC5ASts_Cnt_M_u08; /* PRQA S 3218 */
STATIC volatile VAR(uint8, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_BattVltgOk_Cnt_D_u08; /* PRQA S 3218 */
STATIC volatile VAR(uint8, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_BattVltgSwd1Ok_Cnt_D_u08; /* PRQA S 3218 */
STATIC volatile VAR(uint8, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_BattVltgSwd2Ok_Cnt_D_u08; /* PRQA S 3218 */
STATIC volatile VAR(uint8, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_BattVltgRngOk_Cnt_D_u08; /* PRQA S 3218 */
STATIC volatile VAR(uint8, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_BattVltgSwd1RngOk_Cnt_D_u08; /* PRQA S 3218 */
STATIC volatile VAR(uint8, AP_BATTVLTGCORRLN_APPL_CODE) BatCrln_BattVltgSwd2RngOk_Cnt_D_u08; /* PRQA S 3218 */
#define BATTVLTGCORRLN_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

/* Local Function Declarations */
STATIC  FUNC(uint8, AP_BATTVLTGCORRLN_APPL_CODE) DtrmnInstCorrln(VAR(float32, AUTOMATIC) BattVltg_Volt_T_f32,
																VAR(float32, AUTOMATIC) BattVltgSwd1_Volt_T_f32,
																VAR(float32, AUTOMATIC) BattVltgSwd2_Volt_T_f32);

STATIC FUNC(uint8, AP_BATTVLTGCORRLN_APPL_CODE) DtrmnIdptSig(VAR(uint8, AUTOMATIC) BattVltgCorrlnOk_Cnt_T_u08,
															VAR(uint8, AUTOMATIC) BattVltgSwd1CorrlnOk_Cnt_T_u08,
															VAR(uint8, AUTOMATIC) BattVltgSwd2CorrlnOk_Cnt_T_u08,
															VAR(boolean, AUTOMATIC) DiagcStsIvtr1Inactv_Cnt_T_lgc,
															VAR(boolean, AUTOMATIC) DiagcStsIvtr2Inactv_Cnt_T_lgc);

STATIC  FUNC(boolean, AP_BATTVLTGCORRLN_APPL_CODE) DtrmnSwdVltgLimd(VAR(uint8, AUTOMATIC) BattVltgSwd1Ok_Cnt_T_u08,
																	VAR(float32, AUTOMATIC) BattVltgSwd1_Volt_T_f32,
																	VAR(uint8, AUTOMATIC) BattVltgSwd2Ok_Cnt_T_u08,
																	VAR(float32, AUTOMATIC) BattVltgSwd2_Volt_T_f32);

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
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
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
 *   NTC_Num_TurnCntr_PosLoss (128u)
 *   NTC_Num_TurnCntr_MicroProcFlt (129u)
 *   NTC_Num_TurnCntr_SensorPosFlt (130u)
 *   NTC_Num_TurnCntr_SpiComFlt (131u)
 *   NTC_Num_TurnCntr_HighQuiescCur (132u)
 *   NTC_Num_TurnCntr_MainResets (133u)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134u)
 *   NTC_Num_KinematicIntDiag (144u)
 *   NTC_Num_HighFriction (145u)
 *   NTC_Num_DutyCycleExceeded (148u)
 *   NTC_Num_AbsTempThermLimit (149u)
 *   NTC_Num_LatchActive (160u)
 *   NTC_Num_LimpHomeIgnitionCounter (161u)
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
 *   NTC_Num_MissingMsg_AL (489u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_TunSetNotPrgmd (499u)
 *   NTC_Num_EEPROMtoFeeCpyError (500u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_HWASensorNotTrimmed (504u)
 *   NTC_Num_HWASensorTrimNoAttempt (505u)
 *   NTC_Num_TrqSensorScaleNotSet (506u)
 *   NTC_Num_TrqSensorNotTrimmed (507u)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508u)
 *   NTC_Num_DigTrqSensorScaleNotSet (509u)
 *   NTC_Num_DigTrqSensorNotTrimmed (510u)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511u)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ZERO_ULS_F32 = 0
 * UInt8: D_BATTVLTGCORRLNSTSINIT_CNT_U08 = 7u
 * UInt8: D_THREE_CNT_U08 = 3u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_BATTVLTGCORRLN_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BattVltgCorrln_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF, DISABLE, WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_BattVltgCorrln_Per1_BattVltgSwd1_Volt_f32(void)
 *   Float Rte_IRead_BattVltgCorrln_Per1_BattVltgSwd2_Volt_f32(void)
 *   Float Rte_IRead_BattVltgCorrln_Per1_BattVltg_Volt_f32(void)
 *   Boolean Rte_IRead_BattVltgCorrln_Per1_DiagcStsIvtr1Inactv_Cnt_lgc(void)
 *   Boolean Rte_IRead_BattVltgCorrln_Per1_DiagcStsIvtr2Inactv_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BattVltgCorrln_Per1_BattSwdVltgCorrlnSts_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_BattVltgCorrln_Per1_BattSwdVltgCorrlnSts_Cnt_u08(void)
 *   void Rte_IWrite_BattVltgCorrln_Per1_BattVltgCorrlnIdptSig_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_BattVltgCorrln_Per1_BattVltgCorrlnIdptSig_Cnt_u08(void)
 *   void Rte_IWrite_BattVltgCorrln_Per1_DftBrdgVltgActv_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BattVltgCorrln_Per1_DftBrdgVltgActv_Cnt_lgc(void)
 *   void Rte_IWrite_BattVltgCorrln_Per1_SwdVltgLimd_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_BattVltgCorrln_Per1_SwdVltgLimd_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SysSt_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
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

FUNC(void, RTE_AP_BATTVLTGCORRLN_APPL_CODE) BattVltgCorrln_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BattVltgCorrln_Per1
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) BattVltgSwd1_Volt_T_f32;
	VAR(float32, AUTOMATIC) BattVltgSwd2_Volt_T_f32;
	VAR(float32, AUTOMATIC) BattVltg_Volt_T_f32;
	VAR(boolean, AUTOMATIC) DiagcStsIvtr1Inactv_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DiagcStsIvtr2Inactv_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) IdptSigCnt_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BattVltgCorrlnSts_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) SwdVltgLimd_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) DftBrdgVltgActv_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) InstCorrlnTestIndex_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BattVltgOk_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BattVltgSwd1Ok_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BattVltgSwd2Ok_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BattVltgRngOk_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BattVltgSwd1RngOk_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BattVltgSwd2RngOk_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BattVltgCorrlnOk_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BattVltgSwd1CorrlnOk_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BattVltgSwd2CorrlnOk_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DftBrdgVltgActvSts_Cnt_T_u08;

	/* Read inputs */
	BattVltg_Volt_T_f32 = Rte_IRead_BattVltgCorrln_Per1_BattVltg_Volt_f32();
	BattVltgSwd1_Volt_T_f32 = Rte_IRead_BattVltgCorrln_Per1_BattVltgSwd1_Volt_f32();
	BattVltgSwd2_Volt_T_f32 = Rte_IRead_BattVltgCorrln_Per1_BattVltgSwd2_Volt_f32();
	DiagcStsIvtr1Inactv_Cnt_T_lgc = Rte_IRead_BattVltgCorrln_Per1_DiagcStsIvtr1Inactv_Cnt_lgc();
	DiagcStsIvtr2Inactv_Cnt_T_lgc = Rte_IRead_BattVltgCorrln_Per1_DiagcStsIvtr2Inactv_Cnt_lgc();

	/************** Range Check ************/
	if(BattVltg_Volt_T_f32 < k_BattVltgCorrlnSysMinVltg_Volt_f32)
	{
		BattVltgRngOk_Cnt_T_u08 = 0U;
	}
	else
	{
		BattVltgRngOk_Cnt_T_u08 = 1U;
	}

	if(BattVltgSwd1_Volt_T_f32 < k_BattVltgCorrlnSysMinVltg_Volt_f32)
	{
		BattVltgSwd1RngOk_Cnt_T_u08 = 0U;
	}
	else
	{
		BattVltgSwd1RngOk_Cnt_T_u08 = 1U;
	}

	if(BattVltgSwd2_Volt_T_f32 < k_BattVltgCorrlnSysMinVltg_Volt_f32)
	{
		BattVltgSwd2RngOk_Cnt_T_u08 = 0U;
	}
	else
	{
		BattVltgSwd2RngOk_Cnt_T_u08 = 1U;
	}

	/* Update the display variables */
	BatCrln_BattVltgRngOk_Cnt_D_u08 = BattVltgRngOk_Cnt_T_u08;
	BatCrln_BattVltgSwd1RngOk_Cnt_D_u08 = BattVltgSwd1RngOk_Cnt_T_u08;
	BatCrln_BattVltgSwd2RngOk_Cnt_D_u08 = BattVltgSwd2RngOk_Cnt_T_u08;

	/************** Get instantaneous correlation ************/
	InstCorrlnTestIndex_Cnt_T_u08 = DtrmnInstCorrln(BattVltg_Volt_T_f32, BattVltgSwd1_Volt_T_f32, BattVltgSwd2_Volt_T_f32);

	BattVltgOk_Cnt_T_u08 = T_BATCRLN_INSTCORRLNTESTTABLE_CNT_STR[InstCorrlnTestIndex_Cnt_T_u08].BattVltgOk_u08;
	BattVltgSwd1Ok_Cnt_T_u08 = T_BATCRLN_INSTCORRLNTESTTABLE_CNT_STR[InstCorrlnTestIndex_Cnt_T_u08].BattVltgSwd1Ok_u08;
	BattVltgSwd2Ok_Cnt_T_u08 = T_BATCRLN_INSTCORRLNTESTTABLE_CNT_STR[InstCorrlnTestIndex_Cnt_T_u08].BattVltgSwd2Ok_u08;

	/* Update the display variables */
	BatCrln_BattVltgOk_Cnt_D_u08 = BattVltgOk_Cnt_T_u08;
	BatCrln_BattVltgSwd1Ok_Cnt_D_u08 = BattVltgSwd1Ok_Cnt_T_u08;
	BatCrln_BattVltgSwd2Ok_Cnt_D_u08 = BattVltgSwd2Ok_Cnt_T_u08;

	/* Checking if switched voltages are saturated */
	SwdVltgLimd_Cnt_T_lgc = DtrmnSwdVltgLimd(BattVltgSwd1Ok_Cnt_T_u08, BattVltgSwd1_Volt_T_f32,BattVltgSwd2Ok_Cnt_T_u08, BattVltgSwd2_Volt_T_f32);

	BattVltgCorrlnOk_Cnt_T_u08 = (BattVltgOk_Cnt_T_u08 & BattVltgRngOk_Cnt_T_u08);
	BattVltgSwd1CorrlnOk_Cnt_T_u08 = (BattVltgSwd1Ok_Cnt_T_u08 & BattVltgSwd1RngOk_Cnt_T_u08);
	BattVltgSwd2CorrlnOk_Cnt_T_u08 = (BattVltgSwd2Ok_Cnt_T_u08 & BattVltgSwd2RngOk_Cnt_T_u08);

	/*************** NTC 0x5B *************/
	if((BattVltgCorrlnOk_Cnt_T_u08 + BattVltgSwd1CorrlnOk_Cnt_T_u08 + BattVltgSwd2CorrlnOk_Cnt_T_u08) < 2U)
	{
		BatCrln_NTC5BFltAcc_Cnt_M_u16 = DiagPStep_m(BatCrln_NTC5BFltAcc_Cnt_M_u16, k_BattVltgCorrlnFlt_Cnt_str);

		if (DiagFailed_m(BatCrln_NTC5BFltAcc_Cnt_M_u16, k_BattVltgCorrlnFlt_Cnt_str) == TRUE)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_SysVltgCorrlnFlt, 0x02U, NTC_STATUS_FAILED);
		}
	}
	else
	{
		BatCrln_NTC5BFltAcc_Cnt_M_u16 = DiagNStep_m(BatCrln_NTC5BFltAcc_Cnt_M_u16, k_BattVltgCorrlnFlt_Cnt_str);

		if (BatCrln_NTC5BFltAcc_Cnt_M_u16 == 0U)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_SysVltgCorrlnFlt, 0x00U, NTC_STATUS_PASSED);
		}
	}

	/************** Determine independent signals ************/
	IdptSigCnt_Cnt_T_u08 = DtrmnIdptSig(BattVltgCorrlnOk_Cnt_T_u08,BattVltgSwd1CorrlnOk_Cnt_T_u08,BattVltgSwd2CorrlnOk_Cnt_T_u08,DiagcStsIvtr1Inactv_Cnt_T_lgc,DiagcStsIvtr2Inactv_Cnt_T_lgc);

	/************** Determine correlation status *************/
	BattVltgCorrlnSts_Cnt_T_u08 = ((BattVltgCorrlnOk_Cnt_T_u08 & BatCrln_NTC49Sts_Cnt_M_u08) +
									(uint8)((BattVltgSwd1CorrlnOk_Cnt_T_u08 & BatCrln_NTC4ASts_Cnt_M_u08) << 1U) +
									(uint8)((BattVltgSwd2CorrlnOk_Cnt_T_u08 & BatCrln_NTC5ASts_Cnt_M_u08) << 2U));

	/* Default Bridge Voltage Active */
	DftBrdgVltgActvSts_Cnt_T_u08 = ((BattVltgCorrlnOk_Cnt_T_u08 & BatCrln_NTC49Sts_Cnt_M_u08) +
									(BattVltgSwd1CorrlnOk_Cnt_T_u08 & BatCrln_NTC4ASts_Cnt_M_u08) +
									(BattVltgSwd2CorrlnOk_Cnt_T_u08 & BatCrln_NTC5ASts_Cnt_M_u08));

	if(DftBrdgVltgActvSts_Cnt_T_u08 <= 1U)
	{
		DftBrdgVltgActv_Cnt_T_lgc = TRUE;
	}
	else
	{
		DftBrdgVltgActv_Cnt_T_lgc = FALSE;
	}

	IdptSigCnt_Cnt_T_u08 = Limit_m(IdptSigCnt_Cnt_T_u08,D_IDPTSIGCNTMIN_CNT_U08,D_IDPTSIGCNTMAX_CNT_U08);
	BattVltgCorrlnSts_Cnt_T_u08 = Limit_m(BattVltgCorrlnSts_Cnt_T_u08,D_CORRLNSTSMIN_CNT_U08,D_CORRLNSTSMAX_CNT_U08);

	/* Write Outputs */
	Rte_IWrite_BattVltgCorrln_Per1_BattSwdVltgCorrlnSts_Cnt_u08(BattVltgCorrlnSts_Cnt_T_u08);
	Rte_IWrite_BattVltgCorrln_Per1_BattVltgCorrlnIdptSig_Cnt_u08(IdptSigCnt_Cnt_T_u08);
	Rte_IWrite_BattVltgCorrln_Per1_SwdVltgLimd_Cnt_lgc(SwdVltgLimd_Cnt_T_lgc);
	Rte_IWrite_BattVltgCorrln_Per1_DftBrdgVltgActv_Cnt_lgc(DftBrdgVltgActv_Cnt_T_lgc);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_BATTVLTGCORRLN_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/******************************************************************************
  * Name:        DtrmnInstCorrln
  * Description: To determine the instantaneous correlation
  * Inputs:      BattVltg_Volt_T_f32
  *              BattVltgSwd1_Volt_T_f32
  *              BattVltgSwd2_Volt_T_f32
  * Outputs:     InstCorrlnTestIndex_Cnt_T_u08 
  * Usage Notes: None  
  ****************************************************************************/

STATIC  FUNC(uint8, AP_BATTVLTGCORRLN_APPL_CODE) DtrmnInstCorrln(VAR(float32, AUTOMATIC) BattVltg_Volt_T_f32,
																	VAR(float32, AUTOMATIC) BattVltgSwd1_Volt_T_f32,
																	VAR(float32, AUTOMATIC) BattVltgSwd2_Volt_T_f32)
 {
	VAR(uint8, AUTOMATIC) Test1Ok_Cnt_T_u08 = 0U;
	VAR(uint8, AUTOMATIC) Test2Ok_Cnt_T_u08 = 0U;
	VAR(uint8, AUTOMATIC) Test3Ok_Cnt_T_u08 = 0U;
	VAR(uint8, AUTOMATIC) InstCorrlnTestIndex_Cnt_T_u08;

	if(BattVltg_Volt_T_f32 <= k_BattVltgSwdMax_Volt_f32 )
	{
		/* Test 1 - Batt Vltg vs BattVltgSwd1 */
		if(Abs_f32_m(BattVltg_Volt_T_f32 - BattVltgSwd1_Volt_T_f32) < k_BattVltgCorrlnAllwdVltgDif_Volt_f32)
		{
			Test1Ok_Cnt_T_u08 = 1u;
		}

		/* Test 3 - Batt Vltg vs BattVltgSwd2 */
		if(Abs_f32_m(BattVltg_Volt_T_f32 - BattVltgSwd2_Volt_T_f32) < k_BattVltgCorrlnAllwdVltgDif_Volt_f32)
		{
			Test3Ok_Cnt_T_u08 = 1u;
		}
	}
	else
	{
		if(Abs_f32_m(BattVltgSwd1_Volt_T_f32 - k_BattVltgSwdMax_Volt_f32) <= k_BattVltgCorrlnAllwdVltgDif_Volt_f32 )
		{
			Test1Ok_Cnt_T_u08 = 1u;
		}
		if(Abs_f32_m(BattVltgSwd2_Volt_T_f32 - k_BattVltgSwdMax_Volt_f32) <= k_BattVltgCorrlnAllwdVltgDif_Volt_f32 )
		{
			Test3Ok_Cnt_T_u08 = 1u;
		}
	}

	/* Test2 - BattVltgSwd1 vs BattVltgSwd2 */
	if((Abs_f32_m(BattVltgSwd1_Volt_T_f32 - BattVltgSwd2_Volt_T_f32) <= k_BattVltgCorrlnAllwdVltgDif_Volt_f32) &&
		(BattVltgSwd1_Volt_T_f32 <= (k_BattVltgSwdMax_Volt_f32 + k_BattVltgCorrlnAllwdVltgDif_Volt_f32))&&
		(BattVltgSwd2_Volt_T_f32 <= (k_BattVltgSwdMax_Volt_f32 + k_BattVltgCorrlnAllwdVltgDif_Volt_f32)))
	{
		Test2Ok_Cnt_T_u08 = 1u;
	}

	/* Instantaneous Correlation Index*/
	InstCorrlnTestIndex_Cnt_T_u08 = Test1Ok_Cnt_T_u08 + (uint8)(Test2Ok_Cnt_T_u08 << 1u) + (uint8)(Test3Ok_Cnt_T_u08 << 2u);

	return(InstCorrlnTestIndex_Cnt_T_u08);
}

/******************************************************************************
  * Name:        DtrmnIdptSig
  * Description: To determine the independent signal count and also performs the
  *              diagnostic functions
  * Inputs:      BattVltgCorrlnOk_Cnt_T_u08
  *              BattVltgSwd1CorrlnOk_Cnt_T_u08
  *              BattVltgSwd2CorrlnOk_Cnt_T_u08
  *              DiagcStsIvtr1Inactv_Cnt_T_lgc
  *              DiagcStsIvtr2Inactv_Cnt_T_lgc
  * Outputs:     IdptSigCnt_Cnt_T_u08 
  * Usage Notes: None  
  ****************************************************************************/
STATIC FUNC(uint8, AP_BATTVLTGCORRLN_APPL_CODE) DtrmnIdptSig(VAR(uint8, AUTOMATIC) BattVltgCorrlnOk_Cnt_T_u08,
															VAR(uint8, AUTOMATIC) BattVltgSwd1CorrlnOk_Cnt_T_u08,
															VAR(uint8, AUTOMATIC) BattVltgSwd2CorrlnOk_Cnt_T_u08,
															VAR(boolean, AUTOMATIC) DiagcStsIvtr1Inactv_Cnt_T_lgc,
															VAR(boolean, AUTOMATIC) DiagcStsIvtr2Inactv_Cnt_T_lgc)
{
	VAR(uint8, AUTOMATIC) IdptSigCnt_Cnt_T_u08;

	/************** NTC 0x49 ******************/
	if(BattVltgCorrlnOk_Cnt_T_u08 == 0U)
	{
		BatCrln_NTC49FltAcc_Cnt_M_u16 = DiagPStep_m(BatCrln_NTC49FltAcc_Cnt_M_u16, k_BattVltgCorrlnFlt_Cnt_str);

		if (DiagFailed_m(BatCrln_NTC49FltAcc_Cnt_M_u16, k_BattVltgCorrlnFlt_Cnt_str) == TRUE)
		{
			/* For Dual inverters parameter bit 1 is set */
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BattVltgMeasdCorrlnFlt, 0x01U, NTC_STATUS_FAILED);
			BatCrln_NTC49Sts_Cnt_M_u08 = 0U;
		}
	}
	else
	{
		BatCrln_NTC49FltAcc_Cnt_M_u16 = DiagNStep_m(BatCrln_NTC49FltAcc_Cnt_M_u16, k_BattVltgCorrlnFlt_Cnt_str);

		if (BatCrln_NTC49FltAcc_Cnt_M_u16 == 0U)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BattVltgMeasdCorrlnFlt, 0x00U, NTC_STATUS_PASSED);
			BatCrln_NTC49Sts_Cnt_M_u08 = 1U;
		}

	}

	/************** NTC 0x4A ******************/
	if(DiagcStsIvtr1Inactv_Cnt_T_lgc == TRUE)
	{
		/* Retain the previous value */
	}
	else
	{
		if(BattVltgSwd1CorrlnOk_Cnt_T_u08 != 1U)
		{
			BatCrln_NTC4AFltAcc_Cnt_M_u16 = DiagPStep_m(BatCrln_NTC4AFltAcc_Cnt_M_u16, k_BattVltgCorrlnFlt_Cnt_str);

			if (DiagFailed_m(BatCrln_NTC4AFltAcc_Cnt_M_u16, k_BattVltgCorrlnFlt_Cnt_str) == TRUE)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_IvtrPwrDiscnctFailr, 0x01U, NTC_STATUS_FAILED);
				/* Instead of GetNTCActive function,using a static variable to store the status of NTC */
				BatCrln_NTC4ASts_Cnt_M_u08 = 0U;
			}
		}
		else
		{
			BatCrln_NTC4AFltAcc_Cnt_M_u16 = DiagNStep_m(BatCrln_NTC4AFltAcc_Cnt_M_u16, k_BattVltgCorrlnFlt_Cnt_str);

			if (BatCrln_NTC4AFltAcc_Cnt_M_u16 == 0U)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_IvtrPwrDiscnctFailr, 0x00U, NTC_STATUS_PASSED);
				BatCrln_NTC4ASts_Cnt_M_u08 = 1U;
			}
		}
	}

	/************** NTC 0x5A ******************/
	if(DiagcStsIvtr2Inactv_Cnt_T_lgc == TRUE)
	{
		/* Retain the previous value */
	}
	else
	{
		if(BattVltgSwd2CorrlnOk_Cnt_T_u08 == 0U)
		{
			BatCrln_NTC5AFltAcc_Cnt_M_u16 = DiagPStep_m(BatCrln_NTC5AFltAcc_Cnt_M_u16, k_BattVltgCorrlnFlt_Cnt_str);

			if (DiagFailed_m(BatCrln_NTC5AFltAcc_Cnt_M_u16, k_BattVltgCorrlnFlt_Cnt_str) == TRUE)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Ivtr2PwrDiscnctFailr, 0x01U, NTC_STATUS_FAILED);
				/* Instead of GetNTCActive function,using a static variable to store the status of NTC */
				BatCrln_NTC5ASts_Cnt_M_u08 = 0U;
			}
		}
		else
		{
			BatCrln_NTC5AFltAcc_Cnt_M_u16 = DiagNStep_m(BatCrln_NTC5AFltAcc_Cnt_M_u16, k_BattVltgCorrlnFlt_Cnt_str);

			if (BatCrln_NTC5AFltAcc_Cnt_M_u16 == 0U)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Ivtr2PwrDiscnctFailr, 0x00U, NTC_STATUS_PASSED);
				BatCrln_NTC5ASts_Cnt_M_u08 = 1U;
			}
		}
	}

	/* Independent Signal Count */
	IdptSigCnt_Cnt_T_u08 = (BatCrln_NTC49Sts_Cnt_M_u08 + BatCrln_NTC4ASts_Cnt_M_u08 + BatCrln_NTC5ASts_Cnt_M_u08);

	if(IdptSigCnt_Cnt_T_u08 <= 1U)
	{
		IdptSigCnt_Cnt_T_u08 = 0U;
	}

	return(IdptSigCnt_Cnt_T_u08);
}

/******************************************************************************
  * Name:        DtrmnSwdVltgLimd
  * Description: To determine if the switched voltages are saturated
  * Inputs:      BattVltgSwd1Ok_Cnt_T_u08
  *              BattVltgSwd1_Volt_T_f32
  *              BattVltgSwd2Ok_Cnt_T_u08
  *              BattVltgSwd2_Volt_T_f32
  * Outputs:     SwdVltgLimd_Cnt_T_lgc 
  * Usage Notes: None  
  ****************************************************************************/
STATIC  FUNC(boolean, AP_BATTVLTGCORRLN_APPL_CODE) DtrmnSwdVltgLimd(VAR(uint8, AUTOMATIC) BattVltgSwd1Ok_Cnt_T_u08,
																	VAR(float32, AUTOMATIC) BattVltgSwd1_Volt_T_f32,
																	VAR(uint8, AUTOMATIC) BattVltgSwd2Ok_Cnt_T_u08,
																	VAR(float32, AUTOMATIC) BattVltgSwd2_Volt_T_f32)
 {
	VAR(boolean, AUTOMATIC) SwdVltgLimd_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SwdVltg1Limd_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SwdVltg2Limd_Cnt_T_lgc;

	SwdVltg1Limd_Cnt_T_lgc = FALSE;
	SwdVltg2Limd_Cnt_T_lgc = FALSE;

	if(BattVltgSwd1Ok_Cnt_T_u08 != 0u)
	{
		if(Abs_f32_m(BattVltgSwd1_Volt_T_f32 - k_BattVltgSwdMax_Volt_f32) <= k_BattVltgCorrlnAllwdVltgDif_Volt_f32 )
		{
			SwdVltg1Limd_Cnt_T_lgc = TRUE;
		}
	}

	if(BattVltgSwd2Ok_Cnt_T_u08 != 0u)
	{
		if(Abs_f32_m(BattVltgSwd2_Volt_T_f32 - k_BattVltgSwdMax_Volt_f32) <= k_BattVltgCorrlnAllwdVltgDif_Volt_f32 )
		{
			SwdVltg2Limd_Cnt_T_lgc = TRUE;
		}
	}

	SwdVltgLimd_Cnt_T_lgc = (SwdVltg1Limd_Cnt_T_lgc | SwdVltg2Limd_Cnt_T_lgc);

	return(SwdVltgLimd_Cnt_T_lgc);
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
