/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_MtrPos3SinCos.c
 *     Workspace:  C:/SynergyWorkArea/Working/MtrPos3SinCos/autosar
 *     SW-C Type:  Sa_MtrPos3SinCos
 *  Generated at:  Wed Sep 23 16:26:33 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_MtrPos3SinCos>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*
 * Copyright 2015 Nexteer Automotive
 * Nexteer Confidential
 *
 * Version Control:
 * Date Created:      Wed Jun 03 10:56:00 2015 %
 * %version:          2 %
 * %derived_by:       czmgrw %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/09/15  1        Yue Zhao       Implement Motor position sin&cos measurement, implementation of FDD_58A	EA3#1623
 * 09/23/15  2        JK             Anomaly Fix EA3#3153 - A temporary fix for Rev_u0p16 port                  EA3#3150
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

 *********************************************************************************************************************/

#include "Rte_Sa_MtrPos3SinCos.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "GlobalMacro.h"
#include "CalConstants.h"
#include "fixmath.h"
#include "Crc.h"
#include "atan2.h"



/* MISRA-C:2004 Rule 8.7: This deviation is required to keep the memory map intact.  Rule suppressed by line at each occurrence. */

/* MISRA-C:2004 Rule 10.3: This deviation is required because of Nexteer macro library.  Rule suppressed by line at each occurrence. */

/* MISRA-C:2004 Rule 11.4: This deviation is required because of passing pointer.  Rule suppressed by line at each occurrence. */

/* PRQA S 4533 EOF
 * MISRA-C:2004 Rule 12.7: This deviation is required for macro operation.  The rule is suppressed for the entire file */

/* MISRA-C:2004 Rule 19.1: This deviation is required for AUTOSAR memory map requirements.  Rule suppressed by line at each occurrence. */

#define D_MAXCNT_CNT_U16                        65535U
#define D_SIGCORRLOLMT_ULS_S5P26				(FPM_InitFixedPoint_m(-3.0F, s5p26_T))
#define D_SIGCORRHILMT_ULS_S5P26				(FPM_InitFixedPoint_m(3.0F, s5p26_T))
#define D_2PIREV_REV_U1P15						(FPM_InitFixedPoint_m( 1.0F, u1p15_T))
#define D_SEGLEN_CNT_U16						10U
#define D_SEGSEED_CNT_U16						56797U
#define D_SEGCRCFAIL_CNT_U08					1U
#define D_SEGCRCPASS_CNT_U08					0U


#define MTRPOS3SINCOS_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC  VAR(uint16, SA_MTRPOS3SINCOS_VAR) MtrPos3SinCos_MtrPos3ErrAcc_Cnt_M_u16;
STATIC  VAR(uint16, SA_MTRPOS3SINCOS_VAR) MtrPos3SinCos_LastMtrPos3Mech_Rev_M_u0p16;/* PRQA S 3218 */
#define MTRPOS3SINCOS_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define MTRPOS3SINCOS_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC   VAR(uint8, SA_MTRPOS3SINCOS_VAR) MtrPos3SinCos_MtrPos3RollgCntr_Cnt_M_u08; /* PRQA S 3218 */
#define MTRPOS3SINCOS_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define MTRPOS3SINCOS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(SigQlfr_State_enum, SA_MTRPOS3SINCOS_VAR)  MtrPos3SinCos_MtrPos3Qlfr_State_M_enum;
#define MTRPOS3SINCOS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


STATIC INLINE FUNC(sint16, SA_MTRPOS3SINCOS_CODE) SignalCorrect(VAR(uint16, AUTOMATIC) Signal_Volt_T_u3p13, VAR(uint16, AUTOMATIC) Offset_Volt_T_u3p13, VAR(uint16, AUTOMATIC) AmpRec_Uls_T_u3p13);

STATIC INLINE FUNC(sint16, SA_MTRPOS3SINCOS_CODE) QuadCorrect(VAR(sint16, AUTOMATIC) CorrSin_Uls_T_s2p13, VAR(sint16, AUTOMATIC) CorrCos_Uls_T_s2p13, VAR(sint16, AUTOMATIC) SinDelta_Uls_T_s2p13);

STATIC FUNC(boolean, SA_MTRPOS3SINCOS_CODE) MtrPos3Diagnostics( VAR(uint16, AUTOMATIC) MtrPos3Sin_Volt_T_u3p13, VAR(uint16, AUTOMATIC) MtrPos3Cos_Volt_T_u3p13 );

STATIC FUNC(uint16, SA_MTRPOS3SINCOS_CODE) MtrPos3Atan( VAR(sint16, AUTOMATIC) SinTheta_Volt_T_s2p13,  VAR(sint16, AUTOMATIC) CosTheta_Volt_T_s2p13);

STATIC FUNC(uint16, SA_MTRPOS3SINCOS_CODE) MtrPos3CalcPos( VAR(uint16, AUTOMATIC)  MtrPos3Sin_Volt_T_u3p13, VAR(uint16, AUTOMATIC)  MtrPos3Cos_Volt_T_u3p13, VAR(sint8, AUTOMATIC)  MtrPos3MechPolarity_Uls_T_s08, VAR(uint16, AUTOMATIC)  MtrPos3Offset_RevM_T_u0p16);

STATIC FUNC(uint16, SA_MTRPOS3SINCOS_CODE) CalcMtrPos3Corrd(VAR(uint16, AUTOMATIC) MtrMechPos3_Rev_T_u0p16, VAR(sint8, AUTOMATIC)MtrPos3MechPolarity_Uls_T_s08, VAR(uint16, AUTOMATIC) MtrPos3Offset_RevM_T_u0p16);

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
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
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
 * MtrPos3SinCos_EOLwithCRC: Array with 6 element(s) of type UInt16
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * MtrPos3SinCos_Str: Record with elements
 *   Sin3Offset_Volts_u3p13 of type UInt16
 *   Sin3AmpRec_Uls_u3p13 of type UInt16
 *   Cos3Offset_Volts_u3p13 of type UInt16
 *   Cos3AmpRec_Uls_u3p13 of type UInt16
 *   SinDelta3_Uls_s2p13 of type SInt16
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
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_ZERO_CNT_S8 = 0
 * SigQlfr_State_enum: D_SIGQLFRNORES_CNT_ENUM = 0u
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt8: D_ONE_CNT_U8 = 1u
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
 *   MtrPos3SinCos_Str *Rte_Pim_MtrPos3_EOLParams(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_MTRPOS3SINCOS_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos3SinCos_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MtrEOLData_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRPOS3SINCOS_APPL_CODE) MtrPos3SinCos_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrPos3SinCos_Init
 *********************************************************************************************************************/
  VAR(NvM_RequestResultType, AUTOMATIC) ErrorStatus_Cnt_T_enum;

  MtrPos3SinCos_MtrPos3ErrAcc_Cnt_M_u16= (k_MtrPos3ValDiag_Cnt_str.Threshold) / 2U;

  (void)Rte_Call_MtrEOLData_GetErrorStatus(&ErrorStatus_Cnt_T_enum);
  if(ErrorStatus_Cnt_T_enum != NVM_REQ_OK)
  {
	  Rte_Pim_MtrPos3_EOLParams()->Sin3Offset_Volts_u3p13  =   0U;
	  Rte_Pim_MtrPos3_EOLParams()->Sin3AmpRec_Uls_u3p13    =   0U;
	  Rte_Pim_MtrPos3_EOLParams()->Cos3Offset_Volts_u3p13  =   0U;
	  Rte_Pim_MtrPos3_EOLParams()->Cos3AmpRec_Uls_u3p13    =   0U;
	  Rte_Pim_MtrPos3_EOLParams()->SinDelta3_Uls_s2p13     =   0;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos3SinCos_Per1
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
 *   SInt8 Rte_IRead_MtrPos3SinCos_Per1_MtrMechPos3Polarity_Cnt_s08(void)
 *   UInt16 Rte_IRead_MtrPos3SinCos_Per1_MtrPos3Cos_Volt_u3p13(void)
 *   UInt16 Rte_IRead_MtrPos3SinCos_Per1_MtrPos3Sin_Volt_u3p13(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrPos3SinCos_Per1_MtrPos3Mech_Rev_u0p16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_MtrPos3SinCos_Per1_MtrPos3Mech_Rev_u0p16(void)
 *   void Rte_IWrite_MtrPos3SinCos_Per1_MtrPos3Qlfr_State_enum(SigQlfr_State_enum data)
 *   SigQlfr_State_enum *Rte_IWriteRef_MtrPos3SinCos_Per1_MtrPos3Qlfr_State_enum(void)
 *   void Rte_IWrite_MtrPos3SinCos_Per1_MtrPos3RollgCntr_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_MtrPos3SinCos_Per1_MtrPos3RollgCntr_Cnt_u08(void)
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

FUNC(void, RTE_SA_MTRPOS3SINCOS_APPL_CODE) MtrPos3SinCos_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrPos3SinCos_Per1
 *********************************************************************************************************************/
	VAR(sint8, AUTOMATIC)  MtrPosMech3Polarity_Uls_T_s08;
	VAR(uint16, AUTOMATIC) MtrPos3Cos_Volt_T_u3p13;
	VAR(uint16, AUTOMATIC) MtrPos3Sin_Volt_T_u3p13;
	VAR(uint16, AUTOMATIC) MtrPos3Mech_Rev_T_u0p16;
	VAR(boolean, AUTOMATIC)  MtrPos3TestOk_Cnt_T_lgc;


	MtrPos3Sin_Volt_T_u3p13        = Rte_IRead_MtrPos3SinCos_Per1_MtrPos3Sin_Volt_u3p13();
	MtrPos3Cos_Volt_T_u3p13        = Rte_IRead_MtrPos3SinCos_Per1_MtrPos3Cos_Volt_u3p13();
	MtrPosMech3Polarity_Uls_T_s08  = Rte_IRead_MtrPos3SinCos_Per1_MtrMechPos3Polarity_Cnt_s08();




	MtrPos3TestOk_Cnt_T_lgc = MtrPos3Diagnostics(MtrPos3Sin_Volt_T_u3p13,MtrPos3Cos_Volt_T_u3p13);

	if(MtrPos3TestOk_Cnt_T_lgc == TRUE  )
	{
		MtrPos3Mech_Rev_T_u0p16 = MtrPos3CalcPos(MtrPos3Sin_Volt_T_u3p13,MtrPos3Cos_Volt_T_u3p13,MtrPosMech3Polarity_Uls_T_s08,k_MtrPos3Offset_RevM_u0p16);

	}
	else
	{
		MtrPos3Mech_Rev_T_u0p16 = MtrPos3SinCos_LastMtrPos3Mech_Rev_M_u0p16;

	}

	MtrPos3SinCos_LastMtrPos3Mech_Rev_M_u0p16 = MtrPos3Mech_Rev_T_u0p16;



	Rte_IWrite_MtrPos3SinCos_Per1_MtrPos3Mech_Rev_u0p16(MtrPos3Mech_Rev_T_u0p16);
	Rte_IWrite_MtrPos3SinCos_Per1_MtrPos3Qlfr_State_enum(MtrPos3SinCos_MtrPos3Qlfr_State_M_enum);
	Rte_IWrite_MtrPos3SinCos_Per1_MtrPos3RollgCntr_Cnt_u08(MtrPos3SinCos_MtrPos3RollgCntr_Cnt_M_u08);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos3SinCos_Scom_ReadEOLMtrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadEOLMtrCals> of PortPrototype <MtrPos3SinCos_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void MtrPos3SinCos_Scom_ReadEOLMtrCals(UInt16 *MtrEOLDataPtr)
#else
 *   void MtrPos3SinCos_Scom_ReadEOLMtrCals(MtrPos3SinCos_EOLwithCRC *MtrEOLDataPtr)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_MTRPOS3SINCOS_APPL_CODE) MtrPos3SinCos_Scom_ReadEOLMtrCals(P2VAR(UInt16, AUTOMATIC, RTE_SA_MTRPOS3SINCOS_APPL_VAR) MtrEOLDataPtr)
#else
FUNC(void, RTE_SA_MTRPOS3SINCOS_APPL_CODE) MtrPos3SinCos_Scom_ReadEOLMtrCals(P2VAR(MtrPos3SinCos_EOLwithCRC, AUTOMATIC, RTE_SA_MTRPOS3SINCOS_APPL_VAR) MtrEOLDataPtr)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrPos3SinCos_Scom_ReadEOLMtrCals
 *********************************************************************************************************************/

	 (*MtrEOLDataPtr)[0] = Rte_Pim_MtrPos3_EOLParams()->Sin3Offset_Volts_u3p13;
	 (*MtrEOLDataPtr)[1] = Rte_Pim_MtrPos3_EOLParams()->Sin3AmpRec_Uls_u3p13;
	 (*MtrEOLDataPtr)[2] = Rte_Pim_MtrPos3_EOLParams()->Cos3Offset_Volts_u3p13;
	 (*MtrEOLDataPtr)[3] = Rte_Pim_MtrPos3_EOLParams()->Cos3AmpRec_Uls_u3p13;
	 (*MtrEOLDataPtr)[4] = (uint16)(Rte_Pim_MtrPos3_EOLParams()->SinDelta3_Uls_s2p13);
	 (*MtrEOLDataPtr)[5] = Crc_CalculateCRC16((Crc_DataRefType)(*MtrEOLDataPtr) , D_SEGLEN_CNT_U16, D_SEGSEED_CNT_U16);/* PRQA S 310 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos3SinCos_Scom_WriteEOLMtrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteEOLMtrCals> of PortPrototype <MtrPos3SinCos_Scom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_MtrEOLData_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_MtrEOLData_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void MtrPos3SinCos_Scom_WriteEOLMtrCals(const UInt16 *MtrEOLDataPtr, UInt8 *MtrPos3SinCosWrResp)
#else
 *   void MtrPos3SinCos_Scom_WriteEOLMtrCals(const MtrPos3SinCos_EOLwithCRC *MtrEOLDataPtr, UInt8 *MtrPos3SinCosWrResp)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_MTRPOS3SINCOS_APPL_CODE) MtrPos3SinCos_Scom_WriteEOLMtrCals(P2CONST(UInt16, AUTOMATIC, RTE_SA_MTRPOS3SINCOS_APPL_DATA) MtrEOLDataPtr, P2VAR(UInt8, AUTOMATIC, RTE_SA_MTRPOS3SINCOS_APPL_VAR) MtrPos3SinCosWrResp)
#else
FUNC(void, RTE_SA_MTRPOS3SINCOS_APPL_CODE) MtrPos3SinCos_Scom_WriteEOLMtrCals(P2CONST(MtrPos3SinCos_EOLwithCRC, AUTOMATIC, RTE_SA_MTRPOS3SINCOS_APPL_DATA) MtrEOLDataPtr, P2VAR(UInt8, AUTOMATIC, RTE_SA_MTRPOS3SINCOS_APPL_VAR) MtrPos3SinCosWrResp)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrPos3SinCos_Scom_WriteEOLMtrCals
 *********************************************************************************************************************/


	if( (*MtrEOLDataPtr) [5] == Crc_CalculateCRC16( (Crc_DataRefType)(*MtrEOLDataPtr) , D_SEGLEN_CNT_U16, D_SEGSEED_CNT_U16  )   )/* PRQA S 310 */
	{
		Rte_Pim_MtrPos3_EOLParams()->Sin3Offset_Volts_u3p13  =   (*MtrEOLDataPtr)[0];
		Rte_Pim_MtrPos3_EOLParams()->Sin3AmpRec_Uls_u3p13    =   (*MtrEOLDataPtr)[1];
		Rte_Pim_MtrPos3_EOLParams()->Cos3Offset_Volts_u3p13  =   (*MtrEOLDataPtr)[2];
		Rte_Pim_MtrPos3_EOLParams()->Cos3AmpRec_Uls_u3p13    =   (*MtrEOLDataPtr)[3];
		Rte_Pim_MtrPos3_EOLParams()->SinDelta3_Uls_s2p13     =   (sint16) (*MtrEOLDataPtr)[4];
		*MtrPos3SinCosWrResp = D_SEGCRCPASS_CNT_U08;

		  (void)Rte_Call_MtrEOLData_WriteBlock(NULL_PTR);

	}
	else
	{
		*MtrPos3SinCosWrResp = D_SEGCRCFAIL_CNT_U08;

	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_MTRPOS3SINCOS_APPL_CODE
#include "MemMap.h"/* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
  * Name:        MtrPos3CalcPos
  * Description: Created to calculate Motor Position 3
  * Inputs:      MtrPos3Sin_Volt_T_u3p13			 	- Sine Motor Position
  *              MtrPos3Cos_Volt_T_u3p13   	 			- Cosine Motor Position
  *              MtrPos3MechPolarity_Uls_T_s08          - MtrPos Polarity
  *              MtrPos3Offset_RevM_T_u0p16				- MtrPos Offset Correction factor
  * Outputs:     MtrPos3Mech_Rev_T_u0p16      	     	- Calculated Mech Motor Position
  ******************************************************************************/
STATIC FUNC(uint16, SA_MTRPOS3SINCOS_CODE) MtrPos3CalcPos( VAR(uint16, AUTOMATIC)  MtrPos3Sin_Volt_T_u3p13, VAR(uint16, AUTOMATIC)  MtrPos3Cos_Volt_T_u3p13, VAR(sint8, AUTOMATIC)  MtrPos3MechPolarity_Uls_T_s08, VAR(uint16, AUTOMATIC)  MtrPos3Offset_RevM_T_u0p16)
{


	VAR(sint16, AUTOMATIC) CorrSin_Uls_T_s2p13;
	VAR(sint16, AUTOMATIC) CorrCos_Uls_T_s2p13;
	VAR(sint16, AUTOMATIC) CosTheta_Uls_T_s2p13;
	VAR(uint16, AUTOMATIC) MtrPos3Mech_Rev_T_u0p16;

	CorrSin_Uls_T_s2p13 = SignalCorrect(MtrPos3Sin_Volt_T_u3p13, Rte_Pim_MtrPos3_EOLParams()->Sin3Offset_Volts_u3p13, Rte_Pim_MtrPos3_EOLParams()->Sin3AmpRec_Uls_u3p13);
	CorrCos_Uls_T_s2p13 = SignalCorrect(MtrPos3Cos_Volt_T_u3p13, Rte_Pim_MtrPos3_EOLParams()->Cos3Offset_Volts_u3p13, Rte_Pim_MtrPos3_EOLParams()->Cos3AmpRec_Uls_u3p13);

	CosTheta_Uls_T_s2p13 = QuadCorrect(CorrSin_Uls_T_s2p13, CorrCos_Uls_T_s2p13, Rte_Pim_MtrPos3_EOLParams()->SinDelta3_Uls_s2p13);
	MtrPos3Mech_Rev_T_u0p16 = MtrPos3Atan(CorrSin_Uls_T_s2p13, CosTheta_Uls_T_s2p13 );
	MtrPos3Mech_Rev_T_u0p16 = CalcMtrPos3Corrd(MtrPos3Mech_Rev_T_u0p16, MtrPos3MechPolarity_Uls_T_s08, MtrPos3Offset_RevM_T_u0p16);

	return MtrPos3Mech_Rev_T_u0p16;
}


/*****************************************************************************
  * Name:        CalcMtrPos3Corrd
  * Description: Created for checking Signal correlation for Motor Position 3
  * Inputs:      MtrPos3Mech_Rev_T_u0p16			 -Mech Motor Position
  *              MtrMechPos3Polarity_Uls_T_s08   	 -Motor Position polarity
  *              MtrPos3Offset_RevM_T_u0p16           -MtrPos Offset Correction factor
  * Outputs:     MtrPos3Mech_Rev_T_u0p16      	     -Corrected Mech Motor Position
  ******************************************************************************/

STATIC FUNC(uint16, SA_MTRPOS3SINCOS_CODE) CalcMtrPos3Corrd(VAR(uint16, AUTOMATIC) MtrMechPos3_Rev_T_u0p16, VAR(sint8, AUTOMATIC)MtrPos3MechPolarity_Uls_T_s08, VAR(uint16, AUTOMATIC) MtrPos3Offset_RevM_T_u0p16)
{
	if (MtrPos3MechPolarity_Uls_T_s08 < D_ZERO_CNT_S8)
	{
		MtrMechPos3_Rev_T_u0p16 = D_MAXCNT_CNT_U16 - MtrMechPos3_Rev_T_u0p16;
	}
	MtrMechPos3_Rev_T_u0p16 = MtrMechPos3_Rev_T_u0p16 - MtrPos3Offset_RevM_T_u0p16 ;
	return MtrMechPos3_Rev_T_u0p16;
}


/*****************************************************************************
  * Name:        MtrPos3Atan
  * Description: Created for checking Signal correlation for Motor Position 3
  * Inputs:      SinTheta_Volt_T_s2p13			     - Sine Motor Position Corrected
  *              CosTheta_Volt_T_s2p13     	     - Cosine Motor Position Corrected
  * Outputs:     MechMtrPos_Rev_T_u0p16      	     - Mech Motor Position Calculated
  ******************************************************************************/

STATIC FUNC(uint16, SA_MTRPOS3SINCOS_CODE) MtrPos3Atan( VAR(sint16, AUTOMATIC) SinTheta_Volt_T_s2p13,  VAR(sint16, AUTOMATIC) CosTheta_Volt_T_s2p13)
{
	VAR(sint32, AUTOMATIC)   MtrPosMech_Rev_T_s16p15;
	VAR(uint16, AUTOMATIC)   MechMtrPos_Rev_T_u0p16;
	MtrPosMech_Rev_T_s16p15 = _atan2_asm_(SinTheta_Volt_T_s2p13, CosTheta_Volt_T_s2p13);
	if (MtrPosMech_Rev_T_s16p15 < D_ZERO_CNT_S32)
	{
		MtrPosMech_Rev_T_s16p15 = MtrPosMech_Rev_T_s16p15 + (sint32)D_2PIREV_REV_U1P15;
	}

	MechMtrPos_Rev_T_u0p16 = (uint16)MtrPosMech_Rev_T_s16p15 << D_ONE_CNT_U8;

	return (MechMtrPos_Rev_T_u0p16);
}

 /*****************************************************************************
  * Name:        MtrPos3Diagnostics
  * Description: Created for checking Signal correlation for Motor Position 3
  * Inputs:      MtrPos3Sin_Volt_T_u3p13		- Sine Motor Position
  *              MtrPos3Cos_Volt_T_u3p13        - Cosine Motor Position
  * Outputs:     TestOk_Cnt_T_lgc      	        - Diagnostics results
  ******************************************************************************/

STATIC FUNC(boolean, SA_MTRPOS3SINCOS_CODE) MtrPos3Diagnostics ( VAR(uint16, AUTOMATIC) MtrPos3Sin_Volt_T_u3p13, VAR(uint16, AUTOMATIC) MtrPos3Cos_Volt_T_u3p13 )
													   
{	
    
	VAR(float32, AUTOMATIC) SinCorr_Volt_T_f32;
	VAR(float32, AUTOMATIC) CosCorr_Volt_T_f32;
	VAR(float32, AUTOMATIC) ValidErr_VoltsSqrd_T_f32;
	VAR(boolean, AUTOMATIC) TestOk_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) MtrPos3Sin_Volt_T_f32;
	VAR(float32, AUTOMATIC) MtrPos3Cos_Volt_T_f32;
	VAR(float32, AUTOMATIC) MtrPos3SinOffset_Volt_T_f32;
	VAR(float32, AUTOMATIC) MtrPos3CosOffset_Volt_T_f32;

	MtrPos3Sin_Volt_T_f32 = FPM_FixedToFloat_m(MtrPos3Sin_Volt_T_u3p13,u3p13_T);
	MtrPos3Cos_Volt_T_f32 = FPM_FixedToFloat_m(MtrPos3Cos_Volt_T_u3p13,u3p13_T);
	MtrPos3SinOffset_Volt_T_f32 = FPM_FixedToFloat_m(Rte_Pim_MtrPos3_EOLParams()->Sin3Offset_Volts_u3p13,u3p13_T);
	MtrPos3CosOffset_Volt_T_f32 = FPM_FixedToFloat_m(Rte_Pim_MtrPos3_EOLParams()->Cos3Offset_Volts_u3p13,u3p13_T);

    SinCorr_Volt_T_f32 = MtrPos3Sin_Volt_T_f32 - MtrPos3SinOffset_Volt_T_f32;
	CosCorr_Volt_T_f32 = MtrPos3Cos_Volt_T_f32 - MtrPos3CosOffset_Volt_T_f32;
	
	ValidErr_VoltsSqrd_T_f32 = (SinCorr_Volt_T_f32 * SinCorr_Volt_T_f32) + (CosCorr_Volt_T_f32 * CosCorr_Volt_T_f32);
	
	if( (ValidErr_VoltsSqrd_T_f32 < k_MtrPos3SinCos_ValMinError_VoltsSqrd_f32) ||
	    (ValidErr_VoltsSqrd_T_f32 > k_MtrPos3SinCos_ValMaxError_VoltsSqrd_f32) )
	{
		TestOk_Cnt_T_lgc = FALSE;
		MtrPos3SinCos_MtrPos3ErrAcc_Cnt_M_u16 = DiagPStep_m(MtrPos3SinCos_MtrPos3ErrAcc_Cnt_M_u16, k_MtrPos3ValDiag_Cnt_str);
		if( DiagFailed_m(MtrPos3SinCos_MtrPos3ErrAcc_Cnt_M_u16, k_MtrPos3ValDiag_Cnt_str) == TRUE )
		{
			MtrPos3SinCos_MtrPos3Qlfr_State_M_enum = SIGQLFR_FAIL;
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DigMSBFlt,  0x01U, NTC_STATUS_FAILED);
		}
	}
	else
	{
		TestOk_Cnt_T_lgc = TRUE;
		MtrPos3SinCos_MtrPos3ErrAcc_Cnt_M_u16 = DiagNStep_m(MtrPos3SinCos_MtrPos3ErrAcc_Cnt_M_u16, k_MtrPos3ValDiag_Cnt_str);
		if( MtrPos3SinCos_MtrPos3ErrAcc_Cnt_M_u16 == D_ZERO_CNT_U16 )
		{
			MtrPos3SinCos_MtrPos3Qlfr_State_M_enum = SIGQLFR_PASS;
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_DigMSBFlt, 0x00U, NTC_STATUS_PASSED);

		}
		MtrPos3SinCos_MtrPos3RollgCntr_Cnt_M_u08++; /*intentional overflow when counter rolls over*/
	}
	return (TestOk_Cnt_T_lgc);
}



/*****************************************************************************
  * Name:        QuadCorrect
  * Description: Created for checking Signal correlation for Motor Position 3
  * Inputs:      CorrSin_Uls_T_s2p13			 - Sine Motor Position Corrected 
  *              CorrCos_Uls_T_s2p13     	     - Cosine Motor Position Corrected 
  *				 SinDelta_Uls_T_s2p13            - Change in Sine Motor Position          
  * Outputs:     CorrCos_Uls_T_s2p13      	     - Corrected Cosine Angle for Quadrant 
  ******************************************************************************/

STATIC INLINE FUNC(sint16, SA_MTRPOS3SINCOS_CODE) QuadCorrect(VAR(sint16, AUTOMATIC) CorrSin_Uls_T_s2p13, VAR(sint16, AUTOMATIC) CorrCos_Uls_T_s2p13, VAR(sint16, AUTOMATIC) SinDelta_Uls_T_s2p13)
{
	
	VAR(sint32, AUTOMATIC) CosAdjust_Uls_T_s5p26;
	VAR(sint16, AUTOMATIC) CosAdjust_Uls_T_s2p13;
	
	CosAdjust_Uls_T_s5p26 = (sint32)CorrSin_Uls_T_s2p13 * (sint32)SinDelta_Uls_T_s2p13;
	CosAdjust_Uls_T_s2p13 = (sint16)FPM_Fix_m(CosAdjust_Uls_T_s5p26, s5p26_T, s2p13_T); /* PRQA S 4393 */ /* PRQA S 4394 */
	CorrCos_Uls_T_s2p13 = CorrCos_Uls_T_s2p13 + CosAdjust_Uls_T_s2p13;
	
	return(CorrCos_Uls_T_s2p13);
	
}

/*****************************************************************************
  * Name:        SignalCorrect
  * Description: Created for Signal correlation for Motor Position 3
  * Inputs:      Signal_Volt_T_u3p13			- Motor Position Signal
  *              Offset_Volt_T_u3p13     	    - Offset Correction factor
  *				 AmpRec_Uls_T_u3p13             - Amplitude Reciprocal correction factor
  * Outputs:     Signal_Uls_T_s2p13      	    - Corrected Signal
  ******************************************************************************/

STATIC INLINE FUNC(sint16, SA_MTRPOS3SINCOS_CODE) SignalCorrect(VAR(uint16, AUTOMATIC) Signal_Volt_T_u3p13, VAR(uint16, AUTOMATIC) Offset_Volt_T_u3p13, VAR(uint16, AUTOMATIC) AmpRec_Uls_T_u3p13)
{
	
	VAR(sint16, AUTOMATIC) Signal_Volt_T_s2p13;
	VAR(sint32, AUTOMATIC) Signal_Uls_T_s5p26;
	VAR(sint16, AUTOMATIC) Signal_Uls_T_s2p13;
	
	Signal_Volt_T_s2p13 = (sint16)Signal_Volt_T_u3p13 - (sint16)Offset_Volt_T_u3p13;
	Signal_Uls_T_s5p26 = (sint32)Signal_Volt_T_s2p13 * (sint32)AmpRec_Uls_T_u3p13;
	Signal_Uls_T_s5p26 = Limit_m(Signal_Uls_T_s5p26, D_SIGCORRLOLMT_ULS_S5P26, D_SIGCORRHILMT_ULS_S5P26);
	Signal_Uls_T_s2p13 = (sint16)FPM_Fix_m(Signal_Uls_T_s5p26, s5p26_T, s2p13_T); /* PRQA S 4393 */ /* PRQA S 4394 */
	
	return(Signal_Uls_T_s2p13);
	
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
