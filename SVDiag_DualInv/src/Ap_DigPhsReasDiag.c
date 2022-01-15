/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_DigPhsReasDiag.c
 *     Workspace:  C:/SynergyWorkArea/Working/SVDiag_DualInv/autosar
 *     SW-C Type:  Ap_DigPhsReasDiag
 *  Generated at:  Fri Oct 16 16:09:17 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_DigPhsReasDiag>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/******************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name  : Ap_DigPhsReasDiag.c
* Module Description: Sine Voltage Generation Diagnostics Dual Inverter
* Project           : CBD
* Author            : Krishna Kanth Anne
*
* Module File Name  : Ap_DigPhsReasDiag.c
*
****************************************************************************
 * Version Control:
 * Date Created:      Wed Jan 26 12:00:00 2012
 * %version:          3 %
 * %derived_by:       czmgrw %
 * %date_modified:    Thu Oct  3 16:11:34 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date        Rev    Author    Change Description                                                             SCR #
 * --------  -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/06/15    01       KK      Updated for 9BXX (Based on ES49, updated for Dual Inverter Operation)         EA3#2317
 * 09/22/15    02       JK      Anomaly fix - modified the inverter inputs to inactive from active            EA3#3243
 *                              And also fixed QAC warnings
 * 10/16/15    03       JK      Anomaly fix EA3#3569,EA3#3988 - ExpectedOnTime inputs for D,E,F is            EA3#3948
 *                              actually same as A,B,C and also removed code not matching with FDD
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_DigPhsReasDiag.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/* Include Statements */
#include "CalConstants.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "filters.h"


/* PRQA S 4390 EOF
  MISRA-C: 2004 Rule 10.3: This deviation is required for library macros.  The rule is suppressed for the entire file
*/

/* PRQA S 4393 EOF
  MISRA-C: 2004 Rule 10.3: This deviation is required for library macros.  The rule is suppressed for the entire file
*/

/* PRQA S 4394 EOF
  MISRA-C: 2004 Rule 10.3: This deviation is required for library macros.  The rule is suppressed for the entire file
*/

/* PRQA S 4533 EOF
  MISRA-C: 2004 Rule 12.7: This deviation is required for library macros.  The rule is suppressed for the entire file
*/

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance.  Rule suppressed by line at each occurrence.*/

/* MISRA-C:2004 Rule 8.7: This deviation is required to keep the memory map intact.  Rule suppressed by line at each occurrence. */

/* Local Constants */

#define D_RESETDIGDIAGACTIVE_CNT_U08        0x00U
#define D_ERRORLIMIT_CNT_S32                262136L     /* 2^18 - 8 == 262136 */
#define D_PHASEA_CNT_U16                    0U
#define D_PHASEB_CNT_U16                    1U
#define D_PHASEC_CNT_U16                    2U
#define D_PHASED_CNT_U16                    0U
#define D_PHASEE_CNT_U16                    1U
#define D_PHASEF_CNT_U16                    2U

/* Static Variables */
#define DIGPHSREASDIAG_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint32, AP_DIGPHSREASDIAG_VAR) SVDiag_Filter1SV_Cnt_M_s18p13[D_PHASEC_CNT_U16 + 1U];     /* PRQA S 3218 */
STATIC VAR(sint32, AP_DIGPHSREASDIAG_VAR) SVDiag_Filter2SV_Cnt_M_s18p13[D_PHASEF_CNT_U16 + 1U];     /* PRQA S 3218 */
#define DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define DIGPHSREASDIAG_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_DIGPHSREASDIAG_VAR) SVDiag_HighResPhsReasDisable_M_u08;                        /* PRQA S 3218 */
#define DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */



STATIC INLINE FUNC(void, RTE_AP_DIGPHSREASDIAG_APPL_CODE) DigPhsReasDiagSetBits(VAR(uint8, AUTOMATIC) ParamBits1_Cnt_T_u08,
                                                                                VAR(uint8, AUTOMATIC) ParamBits2_Cnt_T_u08);



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
 * UInt32: Integer in interval [0...4294967295] (standard type)
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
 * UInt32: D_ZERO_CNT_U32 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_DIGPHSREASDIAG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigPhsReasDiag_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <DISABLE, WARMINIT, OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_ExpectedOnTimeA_Cnt_u32(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_ExpectedOnTimeB_Cnt_u32(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_ExpectedOnTimeC_Cnt_u32(void)
 *   Boolean Rte_IRead_DigPhsReasDiag_Per1_GateDrive1ResetActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_DigPhsReasDiag_Per1_GateDrive2ResetActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_DigPhsReasDiag_Per1_Inverter1Inactive_Cnt_lgc(void)
 *   Boolean Rte_IRead_DigPhsReasDiag_Per1_Inverter2Inactive_Cnt_lgc(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeA_Cnt_u32(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeB_Cnt_u32(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeC_Cnt_u32(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeD_Cnt_u32(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeE_Cnt_u32(void)
 *   UInt32 Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeF_Cnt_u32(void)
 *   Boolean Rte_IRead_DigPhsReasDiag_Per1_PDActivateTest_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
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

FUNC(void, RTE_AP_DIGPHSREASDIAG_APPL_CODE) DigPhsReasDiag_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DigPhsReasDiag_Per1
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Name          : DigPhsReasDiag_Per1
* Description   : NA
* Inputs        : NONE
* Outputs       : NONE
* Usage Notes   : NA
***********************************************************************************************************************/


	VAR(uint32, AUTOMATIC)      MeasuredOnTimeABC_Cnt_T_u32[D_PHASEC_CNT_U16 + 1U];
	VAR(uint32, AUTOMATIC)      MeasuredOnTimeDEF_Cnt_T_u32[D_PHASEF_CNT_U16 + 1U];

	VAR(uint32, AUTOMATIC)      ExpectedOnTimeABC_Cnt_T_u32[D_PHASEC_CNT_U16 + 1U];


	VAR(uint16, AUTOMATIC)      i;
	VAR(uint8, AUTOMATIC)       ParamBits1_Cnt_T_u08;
	VAR(uint8, AUTOMATIC)       ParamBits2_Cnt_T_u08;


	VAR(sint32, AUTOMATIC)      HighResError1_Cnt_T_s32[D_PHASEC_CNT_U16 + 1U];
	VAR(sint32, AUTOMATIC)      HighResError2_Cnt_T_s32[D_PHASEF_CNT_U16 + 1U];
	VAR(sint32, AUTOMATIC)      Error1_Cnt_T_s18pm3[D_PHASEC_CNT_U16 + 1U];
	VAR(sint32, AUTOMATIC)      Error2_Cnt_T_s18pm3[D_PHASEF_CNT_U16 + 1U];
	VAR(sint32, AUTOMATIC)      Error1FiltOut_Cnt_T_s32[D_PHASEC_CNT_U16 + 1U];
	VAR(sint32, AUTOMATIC)      Error2FiltOut_Cnt_T_s32[D_PHASEF_CNT_U16 + 1U];
	VAR(sint16, AUTOMATIC)      Error1FiltOut_Cnt_T_s18pm3[D_PHASEC_CNT_U16 + 1U];
	VAR(sint16, AUTOMATIC)      Error2FiltOut_Cnt_T_s18pm3[D_PHASEF_CNT_U16 + 1U];

	VAR(boolean, AUTOMATIC)     PDActivateTest_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)     GateDrive1ResetActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)     GateDrive2ResetActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)     Inverter1Inactive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)     Inverter2Inactive_Cnt_T_lgc;


	MeasuredOnTimeABC_Cnt_T_u32[D_PHASEA_CNT_U16] = Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeA_Cnt_u32();
	MeasuredOnTimeABC_Cnt_T_u32[D_PHASEB_CNT_U16] = Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeB_Cnt_u32();
	MeasuredOnTimeABC_Cnt_T_u32[D_PHASEC_CNT_U16] = Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeC_Cnt_u32();

	MeasuredOnTimeDEF_Cnt_T_u32[D_PHASED_CNT_U16] = Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeD_Cnt_u32();
	MeasuredOnTimeDEF_Cnt_T_u32[D_PHASEE_CNT_U16] = Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeE_Cnt_u32();
	MeasuredOnTimeDEF_Cnt_T_u32[D_PHASEF_CNT_U16] = Rte_IRead_DigPhsReasDiag_Per1_MeasuredOnTimeF_Cnt_u32();

	/* LRPR Expected On time is same as HRPR*/
	/* ExpectedOnTime for D E F phases are same as that for  A B C */
	ExpectedOnTimeABC_Cnt_T_u32[D_PHASEA_CNT_U16] = Rte_IRead_DigPhsReasDiag_Per1_ExpectedOnTimeA_Cnt_u32();
	ExpectedOnTimeABC_Cnt_T_u32[D_PHASEB_CNT_U16] = Rte_IRead_DigPhsReasDiag_Per1_ExpectedOnTimeB_Cnt_u32();
	ExpectedOnTimeABC_Cnt_T_u32[D_PHASEC_CNT_U16] = Rte_IRead_DigPhsReasDiag_Per1_ExpectedOnTimeC_Cnt_u32();

	/* Data collection for this subfunction is performed here (refer 6.1.2.2 in FDD)
	 * The values collected are MotorvelocityMRF, ElectricMachanicalpolarity */

	PDActivateTest_Cnt_T_lgc            = Rte_IRead_DigPhsReasDiag_Per1_PDActivateTest_Cnt_lgc();
	GateDrive1ResetActive_Cnt_T_lgc     = Rte_IRead_DigPhsReasDiag_Per1_GateDrive1ResetActive_Cnt_lgc();
	GateDrive2ResetActive_Cnt_T_lgc     = Rte_IRead_DigPhsReasDiag_Per1_GateDrive2ResetActive_Cnt_lgc();
	Inverter1Inactive_Cnt_T_lgc         = Rte_IRead_DigPhsReasDiag_Per1_Inverter1Inactive_Cnt_lgc();
	Inverter2Inactive_Cnt_T_lgc         = Rte_IRead_DigPhsReasDiag_Per1_Inverter2Inactive_Cnt_lgc();


	/*Resetting Diagnostic bits*/
	ParamBits1_Cnt_T_u08 = D_RESETDIGDIAGACTIVE_CNT_U08;
	ParamBits2_Cnt_T_u08 = D_RESETDIGDIAGACTIVE_CNT_U08;


	/* 200ms delay counter */
	SVDiag_HighResPhsReasDisable_M_u08++;
	if(SVDiag_HighResPhsReasDisable_M_u08 > 100U)
	{
		SVDiag_HighResPhsReasDisable_M_u08 = 100U;
	}

	/* Error Signal Determination and Filtering for phases A, B and C */

	for(i = D_PHASEA_CNT_U16; i <= D_PHASEC_CNT_U16; i++)
	{
		{
			if((SVDiag_HighResPhsReasDisable_M_u08 < 50U) || ((TRUE == PDActivateTest_Cnt_T_lgc) && (SVDiag_HighResPhsReasDisable_M_u08 < 100U)) || (GateDrive1ResetActive_Cnt_T_lgc == TRUE) || (Inverter1Inactive_Cnt_T_lgc  == TRUE))
			{
				HighResError1_Cnt_T_s32[i] = 0;
			}

			else
			{
				HighResError1_Cnt_T_s32[i] = ((sint32)ExpectedOnTimeABC_Cnt_T_u32[i]) - ((sint32)MeasuredOnTimeABC_Cnt_T_u32[i]) - k_PhsReasErrorTerm_Cnt_s16;
				HighResError1_Cnt_T_s32[i] = Limit_m(HighResError1_Cnt_T_s32[i],-D_ERRORLIMIT_CNT_S32,D_ERRORLIMIT_CNT_S32);
			}


			Error1_Cnt_T_s18pm3[i] = FPM_Fix_m(HighResError1_Cnt_T_s32[i],s31p0_T,s18pm3_T);

			SVDiag_Filter1SV_Cnt_M_s18p13[i] = LPF_SvUpdate_s16InFixKTrunc_m (Error1_Cnt_T_s18pm3[i],
			                                                                  SVDiag_Filter1SV_Cnt_M_s18p13[i],
			                                                                  k_ErrorFiltKn_Cnt_u16);

			Error1FiltOut_Cnt_T_s18pm3[i] = LPF_OpUpdate_s16InFixKTrunc_m(SVDiag_Filter1SV_Cnt_M_s18p13[i]);

			Error1FiltOut_Cnt_T_s32[i] = FPM_Fix_m(Error1FiltOut_Cnt_T_s18pm3[i],s18pm3_T,s31p0_T);

			if(Error1FiltOut_Cnt_T_s32[i] > ((sint32)k_ErrorThresh_Cnt_u32))          /* Phase i: Measured Less than Expected */
			{
				ParamBits1_Cnt_T_u08 |= (uint8) (1U << (i*2U));
			}
			else if((-Error1FiltOut_Cnt_T_s32[i]) > ((sint32)k_ErrorThresh_Cnt_u32))  /* Phase i: Measured Greater than Expected */
			{
				ParamBits1_Cnt_T_u08 |= (uint8) (1U << ((i*2U) + 1U));
			}
			else { }
		}
	}


	/* Error Signal Determination and Filtering for phases D, E and F */

	for(i = D_PHASED_CNT_U16; i <= D_PHASEF_CNT_U16; i++)
		{
			{
				if((SVDiag_HighResPhsReasDisable_M_u08 < 50U) || ( (TRUE == PDActivateTest_Cnt_T_lgc) && (SVDiag_HighResPhsReasDisable_M_u08 < 100U) ) || (GateDrive2ResetActive_Cnt_T_lgc == TRUE) || (Inverter2Inactive_Cnt_T_lgc  == TRUE))
				{
					HighResError2_Cnt_T_s32[i] = 0;
				}

				else
				{
					HighResError2_Cnt_T_s32[i] = ((sint32)ExpectedOnTimeABC_Cnt_T_u32[i]) - ((sint32)MeasuredOnTimeDEF_Cnt_T_u32[i]) - k_PhsReasErrorTerm_Cnt_s16;
					HighResError2_Cnt_T_s32[i] = Limit_m(HighResError2_Cnt_T_s32[i], -D_ERRORLIMIT_CNT_S32, D_ERRORLIMIT_CNT_S32);
				}


				Error2_Cnt_T_s18pm3[i] = FPM_Fix_m(HighResError2_Cnt_T_s32[i], s31p0_T, s18pm3_T);

				SVDiag_Filter2SV_Cnt_M_s18p13[i] = LPF_SvUpdate_s16InFixKTrunc_m (Error2_Cnt_T_s18pm3[i],
				                                                                  SVDiag_Filter2SV_Cnt_M_s18p13[i],
				                                                                  k_ErrorFiltKn_Cnt_u16);

				Error2FiltOut_Cnt_T_s18pm3[i] = LPF_OpUpdate_s16InFixKTrunc_m(SVDiag_Filter2SV_Cnt_M_s18p13[i]);

				Error2FiltOut_Cnt_T_s32[i] = FPM_Fix_m(Error2FiltOut_Cnt_T_s18pm3[i], s18pm3_T, s31p0_T);

				if(Error2FiltOut_Cnt_T_s32[i] > ((sint32)k_ErrorThresh_Cnt_u32))          /* Phase i: Measured Less than Expected */
				{
					ParamBits2_Cnt_T_u08 |= (uint8) (1U << (i*2U));
				}
				else if((-Error2FiltOut_Cnt_T_s32[i]) > ((sint32)k_ErrorThresh_Cnt_u32))  /* Phase i: Measured Greater than Expected */
				{
					ParamBits2_Cnt_T_u08 |= (uint8) (1U << ((i*2U) + 1U));
				}
				else { }
			}
		}

	DigPhsReasDiagSetBits(ParamBits1_Cnt_T_u08,ParamBits2_Cnt_T_u08);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigPhsReasDiag_Trans1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OPERATE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DIGPHSREASDIAG_APPL_CODE) DigPhsReasDiag_Trans1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DigPhsReasDiag_Trans1
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Name          : DigPhsReasDiag_Trans1
* Description   : NA
* Inputs        : NONE
* Outputs       : NONE
* Usage Notes   : NA
***********************************************************************************************************************/

    /* Reset the delay counter */
    SVDiag_HighResPhsReasDisable_M_u08 = 0U;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_DIGPHSREASDIAG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
* Name          : DigPhsReasDiagSetBits
* Description   : DigPhsReasDiagSetBits is split out from DigPhsReasDiag_Per1 to reduce QAC reported path count.
* Inputs        : ParamBits1_Cnt_T_u08, ParamBits2_Cnt_T_u08
* Outputs       : NONE
* Usage Notes   : NA
***********************************************************************************************************************/
STATIC INLINE FUNC(void, RTE_AP_DIGPHSREASDIAG_APPL_CODE) DigPhsReasDiagSetBits(VAR(uint8, AUTOMATIC) ParamBits1_Cnt_T_u08,
                                                                                VAR(uint8, AUTOMATIC) ParamBits2_Cnt_T_u08 )

{

	/* Run Rte_Call_NxtrDiagMgr_SetNTCStatus with Diagnostic 1 bits */
	if(ParamBits1_Cnt_T_u08 == D_RESETDIGDIAGACTIVE_CNT_U08)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DigPhaseVoltageVerf,0x00U,NTC_STATUS_PASSED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DigPhaseVoltageVerf,ParamBits1_Cnt_T_u08,NTC_STATUS_FAILED);
	}

	/* Run Rte_Call_NxtrDiagMgr_SetNTCStatus with Diagnostic 2 bits */
	if(ParamBits2_Cnt_T_u08 == D_RESETDIGDIAGACTIVE_CNT_U08)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PhaseVoltageVerf,0x00U,NTC_STATUS_PASSED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PhaseVoltageVerf,ParamBits2_Cnt_T_u08,NTC_STATUS_FAILED);
	}
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
