/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_MotAgCorrln.c
 *     Workspace:  C:/Rijvi_Synergy_EA3/Core_Component/Prep/MotAgCorrln-1/MotAgCorrln/autosar
 *     SW-C Type:  Ap_MotAgCorrln
 *  Generated at:  Fri Aug 28 16:44:12 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_MotAgCorrln>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : Ap_MotAgCorrln.c
* Module Description: Performs cross check of available Motor Angle signals for GM 9Bxx. FDD ES-55B.
* Project           : CBD   
* Author            : Rijvi Ahmed
**********************************************************************************************************************
* Version Control:
* Date Created:      Mon Feb 16 13:00:00 2015
* %version:          2 %
* %derived_by:       nzt9hv %
*---------------------------------------------------------------------------------------------------------------------
* Date       Rev      Author    Change Description                                                               SCR #
* --------   -------  --------  ------------------------------------------------------------------------------  -------
* 08/25/15    1       Rijvi     Initial implementation of FDD ES-55B                                           EA3#2556
* 01/25/16    2       Selva     Implementation of v2.0.0 of FDD ES-55B                                         EA3#5571
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_MotAgCorrln.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "fixmath.h"
#include "GlobalMacro.h"

/* MISRA-C:2004 Rule 8.7: This deviation is required for Module Level Variable. Rule suppressed by line at each occurrence. */

/* MISRA-C:2004 Rule 19.1: This deviation is required for AUTOSAR memory map requirements. Rule suppressed by line at each occurrence. */

/* PRQA S 4393 EOF
 * MISRA-C: 2004 Rule 10.3: This deviation is required for library macros.  The rule is suppressed for the entire file. */

/* MISRA-C: 2004 Rule 21.1: This deviation is required for code consistency.  The rule is suppressed by line at each occurrence. */
 
#define  D_MOTMECLPOSN1CORRLNST_CNT_U08					1U
#define  D_MOTMECLPOSN2CORRLNST_CNT_U08					2U
#define  D_MOTMECLPOSN3CORRLNST_CNT_U08					4U
#define  D_MOTAGCORRLNERRTHD_MOTREVELEC_U0P16           14563U      /* Corresponds to Angle Difference Threshold '0.2222222222' */   
#define  D_MOTPOSN1MAXSTALL_CNT_U08           		    200U
#define  D_MOTPOSN2MAXSTALL_CNT_U08           		    200U
#define  D_MAXIDPTSIG_CNT_U08							3U
#define  D_MINIDPTSIG_CNT_U08							0U
#define  D_MAXCORRLNSTS_CNT_U08                         7U
#define  D_MINCORRLNSTS_CNT_U08							0U
#define  D_MOTPOSN1NOTVALID_CNT_U08                     1U 
#define  D_MOTPOSN2NOTVALID_CNT_U08                     2U
#define  D_MOTPOSN3NOTVALID_CNT_U08                     4U
#define  D_MINNOOFPOLES_ULS_F32                         2.0F  
#define  D_MAXNOOFPOLES_ULS_F32                         12.0F

/* Module Internals */
#define MOTAGCORRLN_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_MOTAGCORRLN_VAR) MotAgCorrln_MotMeclPosn1RollgCntPrev_Cnt_M_u08;	/* PRQA S 3218 */
STATIC VAR(uint8, AP_MOTAGCORRLN_VAR) MotAgCorrln_MotMeclPosn1StallCntPrev_Cnt_M_u08;	/* PRQA S 3218 */
STATIC VAR(uint8, AP_MOTAGCORRLN_VAR) MotAgCorrln_MotMeclPosn2RollgCntPrev_Cnt_M_u08;	/* PRQA S 3218 */
STATIC VAR(uint8, AP_MOTAGCORRLN_VAR) MotAgCorrln_MotMeclPosn2StallCntPrev_Cnt_M_u08;	/* PRQA S 3218 */
STATIC VAR(uint8, AP_MOTAGCORRLN_VAR) MotAgCorrln_MotMeclPosn3RollgCntPrev_Cnt_M_u08;	/* PRQA S 3218 */
STATIC VAR(uint8, AP_MOTAGCORRLN_VAR) MotAgCorrln_MotMeclPosn3StallCntPrev_Cnt_M_u08;	/* PRQA S 3218 */
#define MOTAGCORRLN_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */


#define MOTAGCORRLN_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_MOTAGCORRLN_VAR) MotAgCorrln_MtrPos1Acc_Cnt_M_u16;	/* PRQA S 3218 */
STATIC VAR(uint16, AP_MOTAGCORRLN_VAR) MotAgCorrln_MtrPos2Acc_Cnt_M_u16;	/* PRQA S 3218 */
STATIC VAR(uint16, AP_MOTAGCORRLN_VAR) MotAgCorrln_MtrPos3Acc_Cnt_M_u16;	/* PRQA S 3218 */
STATIC VAR(uint16, AP_MOTAGCORRLN_VAR) MotAgCorrln_MotAgCorrlnErrThd_Cnt_M_u16;/* PRQA S 3218 */
#define MOTAGCORRLN_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */



#define MOTAGCORRLN_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC 	VAR(boolean,  			AUTOMATIC)     MotAgCorrln_MtrPos1Passed_Cnt_M_lgc;/* PRQA S 3218 */
STATIC 	VAR(boolean,  			AUTOMATIC)     MotAgCorrln_MtrPos2Passed_Cnt_M_lgc;/* PRQA S 3218 */
STATIC 	VAR(boolean,  			AUTOMATIC)     MotAgCorrln_MtrPos3Passed_Cnt_M_lgc;/* PRQA S 3218 */
#define MOTAGCORRLN_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define MOTAGCORRLN_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
	STATIC CONST(DiagSettings_Str,    AP_MOTAGCORRLN_VAR)  T_MOTAGCORRLN_MOTPOSN1FLT_CNT_STR = {100U, 5U, 1U}; /* PRQA S 3218 */
	STATIC CONST(DiagSettings_Str,    AP_MOTAGCORRLN_VAR)  T_MOTAGCORRLN_MOTPOSN2FLT_CNT_STR = {100U, 5U, 1U}; /* PRQA S 3218 */
#define MOTAGCORRLN_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
/*** Function Prototypes ***/
STATIC FUNC(boolean, AP_MOTAGCORRLN_CODE) MotMeclPosAVsMotMeclPosB( CONST(u0p16_T, AUTOMATIC) MotMeclPosA_RevM_T_u0p16,
																    CONST(u0p16_T, AUTOMATIC) MotMeclPosB_RevM_T_u0p16
																	);
																	
STATIC FUNC(boolean, AP_MOTAGCORRLN_CODE) SigAvlChk( CONST(uint8, AUTOMATIC) SigRollgCntr_Cnt_T_u08, 
													 CONST(SigQlfr_State_enum, AUTOMATIC) SigQlfr_Cnt_T_enum,
												     P2VAR(uint8, AUTOMATIC, AUTOMATIC) LstRollgCntr_Cnt_T_u08,
												     P2VAR(uint8, AUTOMATIC, AUTOMATIC) StallCntr_Cnt_T_u08,
													 CONST(uint8, AUTOMATIC) MaxStallCntr_Cnt_T_u08);
												 
STATIC FUNC(void, AP_MOTAGCORRLN_CODE) TestOK( CONST(boolean, AUTOMATIC) MotMeclPos1VsPos2TestOk_Cnt_T_lgc, 
											   CONST(boolean, AUTOMATIC) MotMeclPos1VsPos3TestOk_Cnt_T_lgc,
											   CONST(boolean, AUTOMATIC) MotMeclPos2VsPos3TestOk_Cnt_T_lgc,
											   P2VAR(boolean, AUTOMATIC, AUTOMATIC) MotMeclPosn1Ok_Cnt_T_lgc,
										   	   P2VAR(boolean, AUTOMATIC, AUTOMATIC) MotMeclPosn2Ok_Cnt_T_lgc,
											   P2VAR(boolean, AUTOMATIC, AUTOMATIC) MotMeclPosn3Ok_Cnt_T_lgc );
																	

STATIC INLINE FUNC(void, AP_MOTAGCORRLN_CODE) MtrPosDiagc(  VAR(boolean, AUTOMATIC) MtrPosXOk_Cnt_T_lgc,
		                                                        VAR(DiagSettings_Str, AUTOMATIC) MtrPosXFlt_Cnt_T_str,
		                                                        P2VAR(uint16, AUTOMATIC, AUTOMATIC) MtrPosXAcc_Cnt_T_u16,
		                                                        P2VAR(boolean, AUTOMATIC, AUTOMATIC) MtrPosXPassd_Cnt_T_lgc );
																
STATIC INLINE FUNC(void, AP_MOTAGCORRLN_CODE) IdptSigChkAndFltSetting( VAR(uint8, AUTOMATIC) MtrPosCorrlnFltPrmByte_Cnt_T_u08,
																	P2VAR(uint8, AUTOMATIC, AUTOMATIC) MtrPosIndptsig_Cnt_T_u08);

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
 * SigQlfr_State_enum: Enumeration of integer in interval [0...2] with enumerators
 *   SIGQLFR_NORES (0u)
 *   SIGQLFR_PASS (1u)
 *   SIGQLFR_FAIL (2u)
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
 * SigQlfr_State_enum: D_SIGQLFRNORES_CNT_ENUM = 0u
 * UInt16: D_SEVEN_CNT_U16 = 7u
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt8: D_THREE_CNT_U08 = 3u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_MOTAGCORRLN_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCorrln_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_MOTAGCORRLN_APPL_CODE) MotAgCorrln_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCorrln_Init
 *********************************************************************************************************************/
    VAR(float32, AP_MOTAGCORRLN_VAR) NoofPoles_Uls_T_f32;
	
	/* Initialise the Passed logic to True*/
	MotAgCorrln_MtrPos1Passed_Cnt_M_lgc  = TRUE;
	MotAgCorrln_MtrPos2Passed_Cnt_M_lgc  = TRUE;
	MotAgCorrln_MtrPos3Passed_Cnt_M_lgc  = TRUE;
	
	
	NoofPoles_Uls_T_f32 = Limit_m(k_NoofPoles_Uls_f32, D_MINNOOFPOLES_ULS_F32, D_MAXNOOFPOLES_ULS_F32);
	MotAgCorrln_MotAgCorrlnErrThd_Cnt_M_u16 =(uint16)(((uint32)D_MOTAGCORRLNERRTHD_MOTREVELEC_U0P16*(uint32)2U*(((uint32)1U <<16U)/(uint8)NoofPoles_Uls_T_f32))>>16U);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCorrln_Per1
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
 *   SigQlfr_State_enum Rte_IRead_MotAgCorrln_Per1_MotMeclPosn1Qlfr_State_enum(void)
 *   UInt8 Rte_IRead_MotAgCorrln_Per1_MotMeclPosn1RollgCntr_Cnt_u08(void)
 *   UInt16 Rte_IRead_MotAgCorrln_Per1_MotMeclPosn1_Rev_u0p16(void)
 *   SigQlfr_State_enum Rte_IRead_MotAgCorrln_Per1_MotMeclPosn2Qlfr_State_enum(void)
 *   UInt8 Rte_IRead_MotAgCorrln_Per1_MotMeclPosn2RollgCntr_Cnt_u08(void)
 *   UInt16 Rte_IRead_MotAgCorrln_Per1_MotMeclPosn2_Rev_u0p16(void)
 *   SigQlfr_State_enum Rte_IRead_MotAgCorrln_Per1_MotMeclPosn3Qlfr_State_enum(void)
 *   UInt8 Rte_IRead_MotAgCorrln_Per1_MotMeclPosn3RollgCntr_Cnt_u08(void)
 *   UInt16 Rte_IRead_MotAgCorrln_Per1_MotMeclPosn3_Rev_u0p16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MotAgCorrln_Per1_MtrPosCorrlnSts_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_MotAgCorrln_Per1_MtrPosCorrlnSts_Cnt_u16(void)
 *   void Rte_IWrite_MotAgCorrln_Per1_MtrPosIdptSig_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_MotAgCorrln_Per1_MtrPosIdptSig_Cnt_u08(void)
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

FUNC(void, RTE_AP_MOTAGCORRLN_APPL_CODE) MotAgCorrln_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCorrln_Per1
 *********************************************************************************************************************/

	/*** Temporary Variables ***/
		/* Module Inputs */
	VAR(SigQlfr_State_enum, AUTOMATIC)     MotMeclPosn1Qlfr_Cnt_T_enum; 
	VAR(uint8,              AUTOMATIC)     MotMeclPosn1RollgCntr_Cnt_T_u08; 
	VAR(u0p16_T,            AUTOMATIC)     MotMeclPosn1_RevM_T_u0p16; 
	VAR(SigQlfr_State_enum, AUTOMATIC)     MotMeclPosn2Qlfr_Cnt_T_enum; 
	VAR(uint8,              AUTOMATIC)     MotMeclPosn2RollgCntr_Cnt_T_u08; 
	VAR(u0p16_T,            AUTOMATIC)     MotMeclPosn2_RevM_T_u0p16; 
	VAR(SigQlfr_State_enum, AUTOMATIC)     MotMeclPosn3Qlfr_Cnt_T_enum; 
	VAR(uint8,              AUTOMATIC)     MotMeclPosn3RollgCntr_Cnt_T_u08; 
	VAR(u0p16_T,            AUTOMATIC)     MotMeclPosn3_RevM_T_u0p16; 
	
		/* Module internal */
	VAR(boolean,  			AUTOMATIC)     MotMeclPosn1SigAvl_Cnt_T_lgc;
	VAR(boolean,  			AUTOMATIC)     MotMeclPosn2SigAvl_Cnt_T_lgc;
	VAR(boolean,  			AUTOMATIC)     MotMeclPosn3SigAvl_Cnt_T_lgc;
	VAR(boolean, 			AUTOMATIC) 	   MotMeclPos1VsPos2TestOk_Cnt_T_lgc;	
	VAR(boolean, 			AUTOMATIC) 	   MotMeclPos1VsPos3TestOk_Cnt_T_lgc;
	VAR(boolean, 			AUTOMATIC) 	   MotMeclPos2VsPos3TestOk_Cnt_T_lgc;
	VAR(boolean,  			AUTOMATIC)     MotMeclPosn1Ok_Cnt_T_lgc;
	VAR(boolean,  			AUTOMATIC)     MotMeclPosn2Ok_Cnt_T_lgc;
	VAR(boolean,  			AUTOMATIC)     MotMeclPosn3Ok_Cnt_T_lgc;

		
		/* Module Outputs */
	VAR(uint8,              AUTOMATIC)     MtrPosCorrlnFltNTC072ParmByte_Cnt_T_u08 =0U; 
	VAR(uint8,              AUTOMATIC)     MtrPosIdptSig_Cnt_T_u08=0U;
	VAR(uint16,             AUTOMATIC)     MtrPosCorrlnSts_Cnt_T_u16; 
		

	
	/* Read RTE Inputs */
	MotMeclPosn1Qlfr_Cnt_T_enum 		= 	Rte_IRead_MotAgCorrln_Per1_MotMeclPosn1Qlfr_State_enum();
	MotMeclPosn1RollgCntr_Cnt_T_u08		= 	Rte_IRead_MotAgCorrln_Per1_MotMeclPosn1RollgCntr_Cnt_u08();
	MotMeclPosn1_RevM_T_u0p16 			= 	Rte_IRead_MotAgCorrln_Per1_MotMeclPosn1_Rev_u0p16();
	MotMeclPosn2Qlfr_Cnt_T_enum 		= 	Rte_IRead_MotAgCorrln_Per1_MotMeclPosn2Qlfr_State_enum();
	MotMeclPosn2RollgCntr_Cnt_T_u08 	= 	Rte_IRead_MotAgCorrln_Per1_MotMeclPosn2RollgCntr_Cnt_u08();
	MotMeclPosn2_RevM_T_u0p16 			= 	Rte_IRead_MotAgCorrln_Per1_MotMeclPosn2_Rev_u0p16();
	MotMeclPosn3Qlfr_Cnt_T_enum 		= 	Rte_IRead_MotAgCorrln_Per1_MotMeclPosn3Qlfr_State_enum();
	MotMeclPosn3RollgCntr_Cnt_T_u08 	= 	Rte_IRead_MotAgCorrln_Per1_MotMeclPosn3RollgCntr_Cnt_u08();
	MotMeclPosn3_RevM_T_u0p16 			= 	Rte_IRead_MotAgCorrln_Per1_MotMeclPosn3_Rev_u0p16();
	
	
 
	/* Check signal availability for Motor Mechanical Position 1 */
	MotMeclPosn1SigAvl_Cnt_T_lgc = SigAvlChk( MotMeclPosn1RollgCntr_Cnt_T_u08, 
											  MotMeclPosn1Qlfr_Cnt_T_enum,
											  &MotAgCorrln_MotMeclPosn1RollgCntPrev_Cnt_M_u08,
											  &MotAgCorrln_MotMeclPosn1StallCntPrev_Cnt_M_u08,
											  D_MOTPOSN1MAXSTALL_CNT_U08);
	
	/* Check signal availability for Motor Mechanical Position 2 */										  
	MotMeclPosn2SigAvl_Cnt_T_lgc = SigAvlChk( MotMeclPosn2RollgCntr_Cnt_T_u08, 
											  MotMeclPosn2Qlfr_Cnt_T_enum,
											  &MotAgCorrln_MotMeclPosn2RollgCntPrev_Cnt_M_u08,
											  &MotAgCorrln_MotMeclPosn2StallCntPrev_Cnt_M_u08,
											  D_MOTPOSN2MAXSTALL_CNT_U08);
													 
	/* Check signal availability for Motor Mechanical Position 3 */
	MotMeclPosn3SigAvl_Cnt_T_lgc = SigAvlChk( MotMeclPosn3RollgCntr_Cnt_T_u08, 
											  MotMeclPosn3Qlfr_Cnt_T_enum,
											  &MotAgCorrln_MotMeclPosn3RollgCntPrev_Cnt_M_u08,
											  &MotAgCorrln_MotMeclPosn3StallCntPrev_Cnt_M_u08,
											  k_MotAgCorrln_MotPosn3MaxStall_Cnt_u08);
						
						
	/* Motor mechanical position 1 vs position 2 test */
	MotMeclPos1VsPos2TestOk_Cnt_T_lgc = MotMeclPosAVsMotMeclPosB( MotMeclPosn1_RevM_T_u0p16,
																  MotMeclPosn2_RevM_T_u0p16 );
 
	/* Motor mechanical position 1 vs position 3 test */
	MotMeclPos1VsPos3TestOk_Cnt_T_lgc = MotMeclPosAVsMotMeclPosB( MotMeclPosn1_RevM_T_u0p16,
																  MotMeclPosn3_RevM_T_u0p16 );
																  
	/* Motor mechanical position 2 vs position 3 test */
	MotMeclPos2VsPos3TestOk_Cnt_T_lgc = MotMeclPosAVsMotMeclPosB( MotMeclPosn2_RevM_T_u0p16,
																  MotMeclPosn3_RevM_T_u0p16 );
																  
																  
	/*** ------------------------------------- START: TestOK ------------------------------------------ ***/
	MotMeclPosn1Ok_Cnt_T_lgc = FALSE;
	MotMeclPosn2Ok_Cnt_T_lgc = FALSE;
	MotMeclPosn3Ok_Cnt_T_lgc = FALSE;
	TestOK( MotMeclPos1VsPos2TestOk_Cnt_T_lgc, MotMeclPos1VsPos3TestOk_Cnt_T_lgc, MotMeclPos2VsPos3TestOk_Cnt_T_lgc,
			&MotMeclPosn1Ok_Cnt_T_lgc, &MotMeclPosn2Ok_Cnt_T_lgc, &MotMeclPosn3Ok_Cnt_T_lgc ); /* This local function is implemented to reduce the number of static path count */
	/*** -------------------------------------   END: TestOK ------------------------------------------ ***/
																
																
																 
	/*** ------------------------------------- START: Passed ------------------------------------------ ***/
	MtrPosDiagc(MotMeclPosn1Ok_Cnt_T_lgc,T_MOTAGCORRLN_MOTPOSN1FLT_CNT_STR,&MotAgCorrln_MtrPos1Acc_Cnt_M_u16,&MotAgCorrln_MtrPos1Passed_Cnt_M_lgc);
    MtrPosDiagc(MotMeclPosn2Ok_Cnt_T_lgc,T_MOTAGCORRLN_MOTPOSN2FLT_CNT_STR,&MotAgCorrln_MtrPos2Acc_Cnt_M_u16,&MotAgCorrln_MtrPos2Passed_Cnt_M_lgc);
	MtrPosDiagc(MotMeclPosn3Ok_Cnt_T_lgc,k_MotAgCorrln_MotPosn3Flt_Cnt_str,&MotAgCorrln_MtrPos3Acc_Cnt_M_u16,&MotAgCorrln_MtrPos3Passed_Cnt_M_lgc);
	/*** -------------------------------------   END: Passed ------------------------------------------ ***/
	
	
	
	/*** ------------------------------------- START: Build Correlation Status ------------------------------------------ ***/
	MtrPosCorrlnSts_Cnt_T_u16 = 0U;
	if( (MotMeclPosn1SigAvl_Cnt_T_lgc == TRUE) && (MotMeclPosn1Ok_Cnt_T_lgc == TRUE) && (MotAgCorrln_MtrPos1Passed_Cnt_M_lgc == TRUE) )
	{
		MtrPosCorrlnSts_Cnt_T_u16 = MtrPosCorrlnSts_Cnt_T_u16 | (D_MOTMECLPOSN1CORRLNST_CNT_U08); /* PRQA S 2984 */
	}
	if( (MotMeclPosn2SigAvl_Cnt_T_lgc == TRUE) && (MotMeclPosn2Ok_Cnt_T_lgc == TRUE) && (MotAgCorrln_MtrPos2Passed_Cnt_M_lgc == TRUE) )
	{
		MtrPosCorrlnSts_Cnt_T_u16 = MtrPosCorrlnSts_Cnt_T_u16 | (D_MOTMECLPOSN2CORRLNST_CNT_U08);
	}
	if( (MotMeclPosn3SigAvl_Cnt_T_lgc == TRUE) && (MotMeclPosn3Ok_Cnt_T_lgc == TRUE) && (MotAgCorrln_MtrPos3Passed_Cnt_M_lgc == TRUE) )
	{
		MtrPosCorrlnSts_Cnt_T_u16 = MtrPosCorrlnSts_Cnt_T_u16 | (D_MOTMECLPOSN3CORRLNST_CNT_U08);
	}
	/*** -------------------------------------   END: Build Correlation Status ------------------------------------------ ***/
	
	/********** START:IdptSig and Fault Setting ************/
    if(MotAgCorrln_MtrPos1Passed_Cnt_M_lgc == TRUE)
    {
		if(MotMeclPosn1SigAvl_Cnt_T_lgc ==TRUE)
		{
			MtrPosIdptSig_Cnt_T_u08 = 1U;
		}
    }
    else
    {
    	MtrPosCorrlnFltNTC072ParmByte_Cnt_T_u08 = D_MOTPOSN1NOTVALID_CNT_U08;

    }

    if(MotAgCorrln_MtrPos2Passed_Cnt_M_lgc == TRUE)
    {
		if(MotMeclPosn2SigAvl_Cnt_T_lgc ==TRUE)
		{
			MtrPosIdptSig_Cnt_T_u08 += 1U;
		}
    }
    else
    {
    	MtrPosCorrlnFltNTC072ParmByte_Cnt_T_u08 += D_MOTPOSN2NOTVALID_CNT_U08;
    }

    if(MotAgCorrln_MtrPos3Passed_Cnt_M_lgc == TRUE)
    {
		if(MotMeclPosn3SigAvl_Cnt_T_lgc ==TRUE)
		{
			MtrPosIdptSig_Cnt_T_u08 += 1U;
		}
    }
	else
	{
		MtrPosCorrlnFltNTC072ParmByte_Cnt_T_u08 += D_MOTPOSN3NOTVALID_CNT_U08;
	}
	/*************** Idpt Sig Check and Motor Position Correlation Fault NTC 0x72 Setting ****************/
    IdptSigChkAndFltSetting(MtrPosCorrlnFltNTC072ParmByte_Cnt_T_u08,&MtrPosIdptSig_Cnt_T_u08);
	
	MtrPosCorrlnSts_Cnt_T_u16=Limit_m(MtrPosCorrlnSts_Cnt_T_u16, D_MINCORRLNSTS_CNT_U08, D_MAXCORRLNSTS_CNT_U08);
	MtrPosIdptSig_Cnt_T_u08=Limit_m(MtrPosIdptSig_Cnt_T_u08,D_MINIDPTSIG_CNT_U08,D_MAXIDPTSIG_CNT_U08);
	/********** END:IdptSig and Fault Setting ************/
	
	/* Write RTE Outputs */
	(void) Rte_IWrite_MotAgCorrln_Per1_MtrPosCorrlnSts_Cnt_u16( MtrPosCorrlnSts_Cnt_T_u16 );
    (void) Rte_IWrite_MotAgCorrln_Per1_MtrPosIdptSig_Cnt_u08( MtrPosIdptSig_Cnt_T_u08 );
 
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_MOTAGCORRLN_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
 
/**********************************************************************************************************************
  * Name:        MotMeclPosAVsMotMeclPosB
  * Description: Created for common processing for MotMeclPosnA vs MotMeclPosnB
  * Inputs:      MotMeclPosA_RevM_T_u0p16				- Motor Mechanical Position A
  *              MotMeclPosB_RevM_T_u0p16				- Motor Mechanical Position B
  *              *MotMeclPosAVsPosBNTCState_Cnt_T_enum	- Signal Qualifier indicates the correlation status between Motor position A and B
  *              *MotMeclPosAVsMotPosBErrAcc_Cnt_T_u16	- Motor position A vs Motor position B error accumulator
  *              *MotMeclPosAVsPosBRollgCntr_Cnt_T_u08	- Motor position A vs Motor position B rolling counter
  * Outputs:     TestOk_Cnt_T_lgc      					- Indicates Motor position A vs Motor position B instant correlation status 
  *
**********************************************************************************************************************/
STATIC FUNC(boolean, AP_MOTAGCORRLN_CODE) MotMeclPosAVsMotMeclPosB( CONST(u0p16_T, AUTOMATIC) MotMeclPosA_RevM_T_u0p16,
																    CONST(u0p16_T, AUTOMATIC) MotMeclPosB_RevM_T_u0p16)
{
	/* Temporary variables */
	VAR(boolean, AUTOMATIC) TestOk_Cnt_T_lgc;	
	VAR(uint16,  AUTOMATIC) AbsDiffMotPosAVsMotPosB_RevM_T_u16;
	
	
	AbsDiffMotPosAVsMotPosB_RevM_T_u16 = (uint16)(uint32)Abs_s32_m((sint32)MotMeclPosA_RevM_T_u0p16 - (sint32)MotMeclPosB_RevM_T_u0p16);
			
	if( AbsDiffMotPosAVsMotPosB_RevM_T_u16 > 32767U )
	{
		AbsDiffMotPosAVsMotPosB_RevM_T_u16 = 65535U - AbsDiffMotPosAVsMotPosB_RevM_T_u16;
	}
	
			
	if( AbsDiffMotPosAVsMotPosB_RevM_T_u16 < MotAgCorrln_MotAgCorrlnErrThd_Cnt_M_u16 )
	{
		TestOk_Cnt_T_lgc = TRUE;
		
	}
	else
	{
		TestOk_Cnt_T_lgc = FALSE;	
	}
	return TestOk_Cnt_T_lgc;
}													
		


/**********************************************************************************************************************
* Name:        		SigAvlChk
* Description: 		Check availability of the signal based on 'RollingCounter', 'StallCounter' and 'SignalQualifier'.
* Inputs:      		SigRollgCntr_Cnt_T_u08       - Signal rolling counter
*              		SigQlfr_Cnt_T_enum		     - Signal qualifier	
* 					*LstRollgCntr_Cnt_T_u08	     - Last rolling counter
*    				*StallCntr_Cnt_T_u08		 - Stall counter
* Outputs:          SigAvl_Cnt_T_lgc   			 - Returns 'TRUE' when signal is available and 'FALSE' when not available.
* 
**********************************************************************************************************************/
STATIC FUNC(boolean, AP_MOTAGCORRLN_CODE) SigAvlChk( CONST(uint8, AUTOMATIC) SigRollgCntr_Cnt_T_u08, 
													 CONST(SigQlfr_State_enum, AUTOMATIC) SigQlfr_Cnt_T_enum,
												     P2VAR(uint8, AUTOMATIC, AUTOMATIC) LstRollgCntr_Cnt_T_u08,
												     P2VAR(uint8, AUTOMATIC, AUTOMATIC) StallCntr_Cnt_T_u08,
													 CONST(uint8, AUTOMATIC) MaxStallCntr_Cnt_T_u08)
{

	/* Temporary variable */
	VAR(boolean,  AUTOMATIC)  SigAvl_Cnt_T_lgc;
	
	
	if( SigRollgCntr_Cnt_T_u08 == *LstRollgCntr_Cnt_T_u08 )
	{
		if( *StallCntr_Cnt_T_u08 < 255U )
		{
			*StallCntr_Cnt_T_u08 = *StallCntr_Cnt_T_u08 + 1U;
		}
	}
	else
	{
		*StallCntr_Cnt_T_u08 = 0U;
		
		*LstRollgCntr_Cnt_T_u08 = SigRollgCntr_Cnt_T_u08;
	}
	
	
	
	if( *StallCntr_Cnt_T_u08 >= MaxStallCntr_Cnt_T_u08 )
	{
		SigAvl_Cnt_T_lgc = FALSE;
	}
	else
	{
		if( SigQlfr_Cnt_T_enum != SIGQLFR_FAIL )
		{
			SigAvl_Cnt_T_lgc = TRUE;
		}
		else
		{
			SigAvl_Cnt_T_lgc = FALSE;
		}
	}
	
	
	return SigAvl_Cnt_T_lgc;
												  
}
		
		
		
/**********************************************************************************************************************
* Name:        		TestOK
* Description: 		Check availability of the signals based on the instant correlation status of the signals.
* Inputs:      		MotMeclPos1VsPos2TestOk_Cnt_T_lgc   - Instant correlation status between Motor position 1 and 2
*              		MotMeclPos1VsPos3TestOk_Cnt_T_lgc   - Instant correlation status between Motor position 1 and 3
*              		MotMeclPos2VsPos3TestOk_Cnt_T_lgc   - Instant correlation status between Motor position 2 and 3	
*              		*MotMeclPosn1Ok_Cnt_T_lgc	     	- Motor position 1 signal availability based on instant correlation info.
* 					*MotMeclPosn2Ok_Cnt_T_lgc	     	- Motor position 2 signal availability based on instant correlation info.
*    				*MotMeclPosn3Ok_Cnt_T_lgc		 	- Motor position 3 signal availability based on instant correlation info.
* Outputs:          None   			 					- Returns none.
* 
**********************************************************************************************************************/	
STATIC FUNC(void, AP_MOTAGCORRLN_CODE) TestOK( CONST(boolean, AUTOMATIC) MotMeclPos1VsPos2TestOk_Cnt_T_lgc, 
											   CONST(boolean, AUTOMATIC) MotMeclPos1VsPos3TestOk_Cnt_T_lgc,
											   CONST(boolean, AUTOMATIC) MotMeclPos2VsPos3TestOk_Cnt_T_lgc,
											   P2VAR(boolean, AUTOMATIC, AUTOMATIC) MotMeclPosn1Ok_Cnt_T_lgc,
										   	   P2VAR(boolean, AUTOMATIC, AUTOMATIC) MotMeclPosn2Ok_Cnt_T_lgc,
											   P2VAR(boolean, AUTOMATIC, AUTOMATIC) MotMeclPosn3Ok_Cnt_T_lgc )
{
		
	*MotMeclPosn1Ok_Cnt_T_lgc = FALSE;
	*MotMeclPosn2Ok_Cnt_T_lgc = FALSE;
	*MotMeclPosn3Ok_Cnt_T_lgc = FALSE;
	if( MotMeclPos1VsPos2TestOk_Cnt_T_lgc == TRUE )
	{
		*MotMeclPosn1Ok_Cnt_T_lgc = TRUE;
		*MotMeclPosn2Ok_Cnt_T_lgc = TRUE;
	}
	if( MotMeclPos1VsPos3TestOk_Cnt_T_lgc == TRUE )
	{
		*MotMeclPosn1Ok_Cnt_T_lgc = TRUE;
		*MotMeclPosn3Ok_Cnt_T_lgc = TRUE;
	}
	if( MotMeclPos2VsPos3TestOk_Cnt_T_lgc == TRUE )
	{
		*MotMeclPosn2Ok_Cnt_T_lgc = TRUE;
		*MotMeclPosn3Ok_Cnt_T_lgc = TRUE;
	}
	
}


/*****************************************************************************
  * Name:        MtrPosDiagc
  * Description: Created for Motor Position 1 and 2 Diagnostics
  * Inputs:      MtrPosXOk_Cnt_T_lgc,MtrPosXFlt_Cnt_T_str,*MtrPosXAcc_Cnt_T_u16
  * 			 *MtrPosXPassd_Cnt_T_lgc
  * Outputs:     None
  *
*****************************************************************************/
STATIC INLINE FUNC(void, AP_MOTAGCORRLN_CODE) MtrPosDiagc(  VAR(boolean, AUTOMATIC) MtrPosXOk_Cnt_T_lgc,
		                                                        VAR(DiagSettings_Str, AUTOMATIC) MtrPosXFlt_Cnt_T_str,
		                                                        P2VAR(uint16, AUTOMATIC, AUTOMATIC) MtrPosXAcc_Cnt_T_u16,
		                                                        P2VAR(boolean, AUTOMATIC, AUTOMATIC) MtrPosXPassd_Cnt_T_lgc )
{
   if (MtrPosXOk_Cnt_T_lgc == FALSE)
   {
	   *MtrPosXAcc_Cnt_T_u16 = DiagPStep_m(*MtrPosXAcc_Cnt_T_u16, MtrPosXFlt_Cnt_T_str);
	   if( DiagFailed_m(*MtrPosXAcc_Cnt_T_u16, MtrPosXFlt_Cnt_T_str) == TRUE )
		{
		   *MtrPosXPassd_Cnt_T_lgc = FALSE;
		}
   }
   else
   {
	   *MtrPosXAcc_Cnt_T_u16 = DiagNStep_m(*MtrPosXAcc_Cnt_T_u16, MtrPosXFlt_Cnt_T_str);
	   if(*MtrPosXAcc_Cnt_T_u16 == D_ZERO_CNT_U16)
	   {
		   *MtrPosXPassd_Cnt_T_lgc = TRUE;
	   }
   }

}

/************************************************************************************
  * Name:        IdptSigChkAndFltSetting
  * Description: Created for setting Motor Position NTC fault setting and IdptSig Chk
  * Inputs:      MtrPosCorrlnFltPrmByte_Cnt_T_u08
  * Outputs:     None
  *
**************************************************************************************/
STATIC INLINE FUNC(void, AP_MOTAGCORRLN_CODE) IdptSigChkAndFltSetting( VAR(uint8, AUTOMATIC) MtrPosCorrlnFltPrmByte_Cnt_T_u08,P2VAR(uint8, AUTOMATIC, AUTOMATIC) MtrPosIndptsig_Cnt_T_u08)
{
	if(*MtrPosIndptsig_Cnt_T_u08 <= 1U )
	{
		*MtrPosIndptsig_Cnt_T_u08 = D_ZERO_CNT_U8;
	}

    if(MtrPosCorrlnFltPrmByte_Cnt_T_u08 > D_ZERO_CNT_U8)
    {
    	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PriVsSec_SinCosCorr, MtrPosCorrlnFltPrmByte_Cnt_T_u08, NTC_STATUS_FAILED);
    }
    else
    {
    	 (void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_PriVsSec_SinCosCorr, D_ZERO_CNT_U8, NTC_STATUS_PASSED);
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
