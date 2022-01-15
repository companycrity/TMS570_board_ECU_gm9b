/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_TmplMonrDualIvtr.c
 *     Workspace:  C:/SynergyWorkArea/Working/TmplMonrDualIvtr/autosar
 *     SW-C Type:  Sa_TmplMonrDualIvtr
 *  Generated at:  Fri Sep 25 11:48:45 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_TmplMonrDualIvtr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name  : Sa_TmplMonrDualIvtr.c
* Module Description: The purpose of Temporal Monitor Function (TMF) is to continuously verify that the core of the
* 					  Primary Processor CPU in the system is operating properly and at the correct clock rate
*
* Project           : CBD
* Author            : Jayakrishnan T
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       czmgrw %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  -----------
* 09/25/15   1       JK        Initial implementation of ES19D Temporal Monitor-Dual Inverters				EA3#3236
*                              Branched out from FDD19B_009.4 version
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration


 Runnable Entities:
 ==================
  TmplMonrDualIvtr_Per1
    Periodic function intended to be placed at the beginning of the 2ms task list to create the rising edge of the WdMonitor signal.

 *********************************************************************************************************************/

#include "Rte_Sa_TmplMonrDualIvtr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "GlobalMacro.h"

#define D_TMPLMONRDUALIVTR_NUMSTATES	13U

typedef enum {
	TMPLMONRDUALIVTR_RESET1 = 0U,  /* Step 0 */
	TMPLMONRDUALIVTR_INIT_ALLOFF1, /* Step 1 */
	TMPLMONRDUALIVTR_INIT_TMOFF1,  /* Step 2 */
	TMPLMONRDUALIVTR_INIT_PICINIT1,/* Step 3 */
	TMPLMONRDUALIVTR_INIT_SF3OFF,  /* Step 4 */
	TMPLMONRDUALIVTR_INIT_ALLON3,  /* Step 5 */
	TMPLMONRDUALIVTR_INIT_TMOFF2,  /* Step 6 */
	TMPLMONRDUALIVTR_RESET2,       /* Step 7 */
	TMPLMONRDUALIVTR_INIT_ALLOFF2, /* Step 8 */
	TMPLMONRDUALIVTR_INIT_SF23OFF, /* Step 9 */
	TMPLMONRDUALIVTR_INIT_PICINIT2,/* Step 10 */
	TMPLMONRDUALIVTR_OPERATE,      /* Step 11 */
	TMPLMONRDUALIVTR_PREPCHECK	   /* Step 12 */
} DT_TmplMonrDualIvtrSt;
typedef struct TmplMonrDualIvtrState{
	IoHwAb_BoolType	SysFault3Cmd_lgc;
	IoHwAb_BoolType	WdMonitorCmd_lgc;
	IoHwAb_BoolType	WdResetCmd_lgc;
	IoHwAb_BoolType	FetDrvCntlFdbk_lgc;
	IoHwAb_BoolType	PwrSwitchEnFdbk_lgc;
	uint16			StepTime_mS_u16;
} TmplMonrDualIvtrState_Str;
#define TMPLMONRDUALIVTR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC CONST(TmplMonrDualIvtrState_Str, SA_TMPRLMON_CONST) TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[D_TMPLMONRDUALIVTR_NUMSTATES] =
	/* State          FDD Step    SysFlt3   WdMonitor  Reset   FetDrvCntl PwrSwEn  TrnstTime */
	/* RESET1       - Step 0 */ {{STD_LOW,  STD_LOW,  STD_LOW,  STD_LOW,  STD_LOW,  4U},/* 4ms to ensure execution of one 2ms loop */
	/* INIT_ALLOFF1 - Step 1 */  {STD_LOW,  STD_LOW,  STD_HIGH, STD_LOW,  STD_LOW,  31U},
	/* INIT_TMOFF1  - Step 2 */  {STD_HIGH, STD_LOW,  STD_HIGH, STD_LOW,  STD_LOW,  2U},
	/* INIT_PICINIT1- Step 3 */  {STD_HIGH, STD_HIGH, STD_HIGH, STD_HIGH, STD_HIGH, 40U},
	/* INIT_SF3OFF  - Step 4 */  {STD_LOW,  STD_HIGH, STD_HIGH, STD_LOW,  STD_LOW,  2U},
	/* INIT_ALLON3  - Step 5 */  {STD_HIGH, STD_HIGH, STD_HIGH, STD_HIGH, STD_HIGH, 2U},
	/* INIT_TMOFF2  - Step 6 */  {STD_HIGH, STD_LOW,  STD_HIGH, STD_LOW,  STD_LOW,  24U},
	/* RESET2       - Step 7 */  {STD_LOW,  STD_LOW,  STD_LOW,  STD_LOW,  STD_LOW,  1U},
	/* INIT_ALLOFF2 - Step 8 */  {STD_LOW,  STD_LOW,  STD_HIGH, STD_LOW,  STD_LOW,  31U},
	/* INIT_SF23OFF - Step 9 */  {STD_LOW,  STD_HIGH, STD_HIGH, STD_LOW,  STD_LOW,  24U},
	/* INIT_PICINIT2- Step 10 */ {STD_HIGH, STD_HIGH, STD_HIGH, STD_HIGH, STD_HIGH, 16U},
	/* OPERATE      - Step 11 */ {STD_HIGH, STD_HIGH, STD_HIGH, STD_HIGH, STD_HIGH, 0U}, /* SysFlt3 is high intentionally - we don't want to drive it low */
	/* PREPCHECK	- Step 12 */ {STD_LOW,  STD_LOW,  STD_LOW,  STD_HIGH, STD_LOW,  0U}};
#define TMPLMONRDUALIVTR_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
#define TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(DT_TmplMonrDualIvtrSt, TMPLMONRDUALIVTR) TmplMonrDualIvtr_TmplMonrSt_Cnt_M_enum;
STATIC VAR(NxtrDiagMgrStatus, TMPLMONRDUALIVTR) TmplMonrDualIvtr_InitTestSts_Cnt_M_enum;
#define TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


#define TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, TMPLMONRDUALIVTR) TmplMonrDualIvtr_InitialTime_mS_M_u32;
#define TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8,  TMPLMONRDUALIVTR) TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08;
#define TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, TMPLMONRDUALIVTR) TmplMonrDualIvtr_TMFTestCompl_Cnt_M_lgc;
STATIC VAR(boolean, TMPLMONRDUALIVTR) TmplMonrDualIvtr_TMFPrepChkFlg_Cnt_M_lgc;        /* PRQA S 3218 */
#define TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, TMPLMONRDUALIVTR) TmplMonrDualIvtr_PNAccum_Cnt_M_u16;              /* PRQA S 3218 */
#define TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


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
 * IoHwAb_BoolType: Integer in interval [0...1]
 * UInt16: Integer in interval [0...65535] (standard type)
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
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_TMPLMONRDUALIVTR_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TmplMonrDualIvtr_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_WdMonitor_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_TMPLMONRDUALIVTR_APPL_CODE) TmplMonrDualIvtr_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TmplMonrDualIvtr_Per1
 *********************************************************************************************************************/

 (void)Rte_Call_WdMonitor_OP_SET(TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[TmplMonrDualIvtr_TmplMonrSt_Cnt_M_enum].WdMonitorCmd_lgc);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TmplMonrDualIvtr_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <DISABLE, OPERATE, OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_TmplMonrDualIvtr_Per2_TMFTestStart_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TmplMonrDualIvtr_Per2_TMFTestComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TmplMonrDualIvtr_Per2_TMFTestComplete_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_FetDrvCntl_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetDrvCntl_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_PwrSwitchEn_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_PwrSwitchEn_E_NOT_OK
 *   Std_ReturnType Rte_Call_SysFault3_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SysFault3_E_NOT_OK
 *   Std_ReturnType Rte_Call_WdReset_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdReset_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_TMPLMONRDUALIVTR_APPL_CODE) TmplMonrDualIvtr_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TmplMonrDualIvtr_Per2
 *********************************************************************************************************************/


	VAR(boolean, AUTOMATIC)				        TMFTestStart_Cnt_T_lgc;
	VAR(DT_TmplMonrDualIvtrSt, AUTOMATIC)		TmplMonrSt_Cnt_T_enum;
	VAR(IoHwAb_BoolType, AUTOMATIC)		        FetDrvCntlFdbk_Cnt_T_lgc;
	VAR(IoHwAb_BoolType, AUTOMATIC)		        PwrSwitchEnFdbk_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC)				        ElapsedTime_T_mS_u16;
	VAR(IoHwAb_BoolType, AUTOMATIC)		        SysFault3_Cnt_T_lgc;


	TMFTestStart_Cnt_T_lgc = Rte_IRead_TmplMonrDualIvtr_Per2_TMFTestStart_Cnt_lgc();

	TmplMonrSt_Cnt_T_enum = TmplMonrDualIvtr_TmplMonrSt_Cnt_M_enum; /* Local Copy for consistency */

	(void) Rte_Call_FetDrvCntl_OP_GET(&FetDrvCntlFdbk_Cnt_T_lgc);
	(void) Rte_Call_PwrSwitchEn_OP_GET(&PwrSwitchEnFdbk_Cnt_T_lgc);

	if(TmplMonrDualIvtr_TMFPrepChkFlg_Cnt_M_lgc == FALSE)
	{
		(void) Rte_Call_SystemTime_GetSystemTime_mS_u32(&TmplMonrDualIvtr_InitialTime_mS_M_u32);
		(void) Rte_Call_SysFault3_OP_GET(&SysFault3_Cnt_T_lgc);
		TmplMonrDualIvtr_TMFPrepChkFlg_Cnt_M_lgc = TRUE;
		if(SysFault3_Cnt_T_lgc == FALSE)
		{
			/* DTC " TMF circuitry Init" active */
			TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08 = (uint8)((TMPLMONRDUALIVTR_PREPCHECK + 1U) << 4U);
			TmplMonrDualIvtr_InitTestSts_Cnt_M_enum  = NTC_STATUS_FAILED;
		}
	}
	/* Temporal Monitor Control Circuit Fault */
	else if( (TmplMonrSt_Cnt_T_enum < TMPLMONRDUALIVTR_OPERATE) &&
		(TMFTestStart_Cnt_T_lgc == TRUE) )
	{
		(void) Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(TmplMonrDualIvtr_InitialTime_mS_M_u32, &ElapsedTime_T_mS_u16);

		if( (ElapsedTime_T_mS_u16 >= TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[TmplMonrSt_Cnt_T_enum].StepTime_mS_u16) ||
			( ( (TmplMonrSt_Cnt_T_enum == TMPLMONRDUALIVTR_INIT_PICINIT1) ||
			    (TmplMonrSt_Cnt_T_enum == TMPLMONRDUALIVTR_INIT_PICINIT2) ) &&
			(TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[TmplMonrSt_Cnt_T_enum].FetDrvCntlFdbk_lgc == FetDrvCntlFdbk_Cnt_T_lgc) &&
			  (TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[TmplMonrSt_Cnt_T_enum].PwrSwitchEnFdbk_lgc == PwrSwitchEnFdbk_Cnt_T_lgc)))
			{
				if( (TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[TmplMonrSt_Cnt_T_enum].FetDrvCntlFdbk_lgc != FetDrvCntlFdbk_Cnt_T_lgc) ||
						(TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[TmplMonrSt_Cnt_T_enum].PwrSwitchEnFdbk_lgc != PwrSwitchEnFdbk_Cnt_T_lgc) )
				{
					/* Record DTC Parameter data */
					TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08 = ((TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[TmplMonrSt_Cnt_T_enum].FetDrvCntlFdbk_lgc & ((uint8)~FetDrvCntlFdbk_Cnt_T_lgc)) |
											 ((uint8)((TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[TmplMonrSt_Cnt_T_enum].PwrSwitchEnFdbk_lgc & ((uint8)~PwrSwitchEnFdbk_Cnt_T_lgc)) << 1U)) |
											 ((uint8)((((uint8)~TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[TmplMonrSt_Cnt_T_enum].FetDrvCntlFdbk_lgc) & FetDrvCntlFdbk_Cnt_T_lgc) << 2U)) |
											 ((uint8)((((uint8)~TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[TmplMonrSt_Cnt_T_enum].PwrSwitchEnFdbk_lgc) & PwrSwitchEnFdbk_Cnt_T_lgc) << 3U)) ) |
													 TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08;
					if (TmplMonrDualIvtr_InitTestSts_Cnt_M_enum == NTC_STATUS_PASSED)
					{
						TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08 = TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08 | ((uint8)((uint8)TmplMonrSt_Cnt_T_enum << 4U));
						TmplMonrDualIvtr_InitTestSts_Cnt_M_enum = NTC_STATUS_FAILED;
					}
				}
				TmplMonrSt_Cnt_T_enum++;
				TmplMonrDualIvtr_TmplMonrSt_Cnt_M_enum = TmplMonrSt_Cnt_T_enum;
				(void) Rte_Call_SystemTime_GetSystemTime_mS_u32(&TmplMonrDualIvtr_InitialTime_mS_M_u32);
			}

		if(TMPLMONRDUALIVTR_OPERATE == TmplMonrSt_Cnt_T_enum)
		{
			TmplMonrDualIvtr_TMFTestCompl_Cnt_M_lgc = TRUE;
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TmpMonFunc, TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08, TmplMonrDualIvtr_InitTestSts_Cnt_M_enum);
		}

	}
	else
	{
		(void) Rte_Call_SystemTime_GetSystemTime_mS_u32(&TmplMonrDualIvtr_InitialTime_mS_M_u32);
	}
	Rte_IWrite_TmplMonrDualIvtr_Per2_TMFTestComplete_Cnt_lgc(TmplMonrDualIvtr_TMFTestCompl_Cnt_M_lgc);

	(void) Rte_Call_WdReset_OP_SET(TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[TmplMonrSt_Cnt_T_enum].WdResetCmd_lgc);
	(void) Rte_Call_SysFault3_OP_SET(TmplMonrDualIvtr_TmplMonrStTbl_Cnt_M_Str[TmplMonrSt_Cnt_T_enum].SysFault3Cmd_lgc);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TmplMonrDualIvtr_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <WARMINIT, OFF>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FetDrvCntl_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetDrvCntl_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_PwrSwitchEn_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_PwrSwitchEn_E_NOT_OK
 *   Std_ReturnType Rte_Call_SysFault3_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SysFault3_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_TMPLMONRDUALIVTR_APPL_CODE) TmplMonrDualIvtr_Per3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TmplMonrDualIvtr_Per3
 *********************************************************************************************************************/

	VAR(IoHwAb_BoolType, AUTOMATIC)		SysFault3_Cnt_T_lgc;
	VAR(IoHwAb_BoolType, AUTOMATIC)		FetDrvCntl_Cnt_T_lgc;
	VAR(IoHwAb_BoolType, AUTOMATIC)		PwrSwitchEn_Cnt_T_lgc;
	VAR(NxtrDiagMgrStatus, AUTOMATIC)	NTCStatus_Cnt_T_enum;

	(void) Rte_Call_SysFault3_OP_GET(&SysFault3_Cnt_T_lgc);
	(void) Rte_Call_PwrSwitchEn_OP_GET(&PwrSwitchEn_Cnt_T_lgc);
	(void) Rte_Call_FetDrvCntl_OP_GET(&FetDrvCntl_Cnt_T_lgc);


	/* TMF Run Time Control Circuit Fault */

	if(SysFault3_Cnt_T_lgc == TRUE) 
	{
		if( (PwrSwitchEn_Cnt_T_lgc == TRUE) && (FetDrvCntl_Cnt_T_lgc == TRUE) )
		{
			TmplMonrDualIvtr_PNAccum_Cnt_M_u16 =  DiagNStep_m(TmplMonrDualIvtr_PNAccum_Cnt_M_u16, k_TmplMonrDualIvtrPstepNstep_Cnt_str);
			NTCStatus_Cnt_T_enum = NTC_STATUS_PASSED;
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TmpMonRunTimeFlt, 0U, NTCStatus_Cnt_T_enum);
		}
		else
		{
			/* Record appropriate "Stuck Low" Status Bit(s) */
			TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08 = ((uint8)(~FetDrvCntl_Cnt_T_lgc) & 0x1U) |
			                          ((uint8)(((uint8)~PwrSwitchEn_Cnt_T_lgc) << 1U) & 0x2U) |
			                          TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08;
			TmplMonrDualIvtr_PNAccum_Cnt_M_u16 =  DiagPStep_m(TmplMonrDualIvtr_PNAccum_Cnt_M_u16, k_TmplMonrDualIvtrPstepNstep_Cnt_str);
			if (DiagFailed_m( TmplMonrDualIvtr_PNAccum_Cnt_M_u16, k_TmplMonrDualIvtrPstepNstep_Cnt_str) == TRUE)
			{
				NTCStatus_Cnt_T_enum = NTC_STATUS_FAILED;
				(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TmpMonRunTimeFlt, TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08, NTCStatus_Cnt_T_enum);
			}
		}
	}
	else
	{
		if( (PwrSwitchEn_Cnt_T_lgc == TRUE) || (FetDrvCntl_Cnt_T_lgc == TRUE) )
		{
			/* Record appropriate "Stuck High" Status Bit(s) */
			TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08 = ((uint8)(((uint8)FetDrvCntl_Cnt_T_lgc) << 2U) & 0x4U) |
			                          ((uint8)(((uint8)PwrSwitchEn_Cnt_T_lgc) << 3U)& 0x8U) |
			                          TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08;
			TmplMonrDualIvtr_PNAccum_Cnt_M_u16 =  DiagPStep_m(TmplMonrDualIvtr_PNAccum_Cnt_M_u16, k_TmplMonrDualIvtrPstepNstep_Cnt_str);
			if (DiagFailed_m( TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08, k_TmplMonrDualIvtrPstepNstep_Cnt_str) == TRUE)
			{
				NTCStatus_Cnt_T_enum = NTC_STATUS_FAILED;
				(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TmpMonRunTimeFlt, TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08, NTCStatus_Cnt_T_enum);
			}
		}
		else
		{
			TmplMonrDualIvtr_PNAccum_Cnt_M_u16 =  DiagNStep_m(TmplMonrDualIvtr_PNAccum_Cnt_M_u16, k_TmplMonrDualIvtrPstepNstep_Cnt_str);
			NTCStatus_Cnt_T_enum = NTC_STATUS_PASSED;
			(void) Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_TmpMonRunTimeFlt, 0U, NTCStatus_Cnt_T_enum);
		}
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TmplMonrDualIvtr_Per4
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
 *   Boolean Rte_IRead_TmplMonrDualIvtr_Per4_Ivtr1Inactv_Cnt_lgc(void)
 *   Boolean Rte_IRead_TmplMonrDualIvtr_Per4_Ivtr2Inactv_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_SysFault2A_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SysFault2A_E_NOT_OK
 *   Std_ReturnType Rte_Call_SysFault2B_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SysFault2B_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_TMPLMONRDUALIVTR_APPL_CODE) TmplMonrDualIvtr_Per4(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TmplMonrDualIvtr_Per4
 *********************************************************************************************************************/
	VAR(IoHwAb_BoolType, AUTOMATIC)		SysFault2A_Cnt_T_lgc;
	VAR(IoHwAb_BoolType, AUTOMATIC)		SysFault2B_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)		        Ivtr1Inactv_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)		        Ivtr2Inactv_Cnt_T_lgc;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;

	SysFault2A_Cnt_T_lgc = STD_LOW;
	SysFault2B_Cnt_T_lgc = STD_LOW;

	SystemState_Cnt_T_enum       = Rte_Mode_SystemState_Mode();
	Ivtr1Inactv_Cnt_T_lgc  = Rte_IRead_TmplMonrDualIvtr_Per4_Ivtr1Inactv_Cnt_lgc();
	Ivtr2Inactv_Cnt_T_lgc  = Rte_IRead_TmplMonrDualIvtr_Per4_Ivtr2Inactv_Cnt_lgc();

	if((SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_DISABLE) ||((Ivtr1Inactv_Cnt_T_lgc == TRUE) &&(Ivtr2Inactv_Cnt_T_lgc == TRUE)))
	{
		SysFault2A_Cnt_T_lgc = STD_HIGH;
		SysFault2B_Cnt_T_lgc = STD_HIGH;
	}
	else if(Ivtr1Inactv_Cnt_T_lgc == TRUE)
	{
		SysFault2A_Cnt_T_lgc = STD_HIGH;
	}
	else if(Ivtr2Inactv_Cnt_T_lgc == TRUE)
	{
		SysFault2B_Cnt_T_lgc = STD_HIGH;
	}
	else
	{
		/* Do Nothing */
	}

    /* Disable Gate Drive Enable and Power */
	(void) Rte_Call_SysFault2A_OP_SET(SysFault2A_Cnt_T_lgc);
	(void) Rte_Call_SysFault2B_OP_SET(SysFault2B_Cnt_T_lgc);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TmplMonrDualIvtr_Tans1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <WARMINIT> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_TMPLMONRDUALIVTR_APPL_CODE) TmplMonrDualIvtr_Tans1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TmplMonrDualIvtr_Tans1
 *********************************************************************************************************************/

	if (TmplMonrDualIvtr_TMFTestCompl_Cnt_M_lgc == FALSE)
	{
		TmplMonrDualIvtr_InitTestSts_Cnt_M_enum = NTC_STATUS_PASSED;
		TmplMonrDualIvtr_NTCStatusByte_Cnt_M_u08 = 0U;
		(void) Rte_Call_SystemTime_GetSystemTime_mS_u32(&TmplMonrDualIvtr_InitialTime_mS_M_u32);
		TmplMonrDualIvtr_TmplMonrSt_Cnt_M_enum = TMPLMONRDUALIVTR_RESET1;
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_TMPLMONRDUALIVTR_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/




/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
