/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_DemIf.c
 *     Workspace:  C:/_synergy/9BXX_CZ8L9T/GM_9BXX_EPS_TMS570/SwProject/DemIf/autosar
 *     SW-C Type:  Ap_DemIf
 *  Generated at:  Mon Mar 14 11:20:06 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_DemIf>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Jul 19 10:51:26 2011
 * %version:          EA3#9 %
 * %derived_by:       fz9hxm %
 * %date_modified:    Tue Sep 10 12:15:02 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 02/08/16  2        GMN       EA3#4984: Bus Off new strategy to set NTC                                     5973
 * 03/14/16  3        GMN       EA3#6465: Add inhibit calibrations for new CTCs                               6594
 * 04/15/16  5        GMN       Fixed variable type for PwrMd read at GetEcuStatusMask function
 * 09/05/16  6        GMN       Update DTC table for new DTC numbers
 * 09/07/16  7        GMN       Update DTC table to correct k_CtcInhibitMask551207_Cnt_u16
 * 11/23/16  8        CP        Update DTC table to correct k_CtcInhibitMask51EA00_Cnt_u16
 * 03/21/16  9        CP        Update DTC table as per FCR v5B
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
  Volt_f32 of Port Interface Vecu_Volt_f32
    This port prototype is inteded to communicate voltage signals that represent the ecu supplied voltage.  This signal has a lower limit, which is non-zero, to allow users of the signal to use it as a denominator in an expression without requiring a divide by 0 check.


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service

 *********************************************************************************************************************/

#include "Rte_Ap_DemIf.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "GlobalMacro.h"
#include "Dem.h"
#include "DiagMgr_Cfg.h"
#include "CalConstants.h"
#include "Rte_Type.h"
#include "Ap_DfltConfigData.h"
#include "Ap_DemIf.h"

/**********************************************************************************************************************
 *  Definitions
 *********************************************************************************************************************/

/**
 * Delay time after recovering from not stable condition. Please check DemIf_DelayInhibitInit for more details of what
 * a not stable condition is.
 */
#define D_DELAYINHIBITTIME_MS_U16 5000U

/**
 * A delay shall be applied when the ECU is recovering from a under voltage condition. This macro holds the under
 * voltage value.
 */
#define D_DELAYINHIBITUNDER_VOLTS_F32 9.0F

/**
 * This group of macros defines the bitmap used to mask the inhibit configuration for each CTC.
 * Each CTC should have its own mask and will only be enabled (set) if the ECU status agrees with the CTC
 * inhibit mask.
 */
#define D_INHMASKPWRMDRUN_CNT_U16           0x0001U /* PwrMd == Run */
#define D_INHMASKENGINERUNNING_CNT_U16      0x0002U /* EngRunAtv == TRUE */
#define D_INHMASKVBATRANGE6TO16_CNT_U16     0x0004U /* 6V < Vbatt < 16V */
#define D_INHMASKVBATRANGE9TO16_CNT_U16     0x0008U /* 9V < Vbatt < 16V */
#define D_INHMASKDELAY5SECONDS_CNT_U16      0x0010U /* 5 seconds delay after crank req and under voltage recovery */
#define D_INHMASKU007300STATUSBIT1_CNT_U16  0x0020U /* U007300 status bit 1 != TRUE */
#define D_INHMASKCUSTOMERMEC_CNT_U16        0x0040U /* Customer MEC is 0 or 0xFF */
#define D_INHMASKNOBUSOFFHS_CNT_U16         0x0080U /* No BusOff fault on HS CAN channel */
#define D_INHMASKNOBUSOFFCE_CNT_U16         0x0100U /* No BusOff fault on CE CAN channel */
#define D_INHMASKPWRMDRUNORACC_CNT_U16      0x0200U /* PwrMd == Run or PwrMd == ACC */

/**********************************************************************************************************************
 *  Types
 *********************************************************************************************************************/

/**
 * Structure used to create the relationship between the CTC number and its bitmap mask of enable conditions
 * for setting the CTC.
 */
typedef struct CTCInhibitStrType_Structure {
	VAR(uint32, AUTOMATIC) CTCNumber_Cnt_u32; /* CTC number */
	P2CONST(uint16, AUTOMATIC, AUTOMATIC) CTCInhibitMaskPtr_Cnt_u16; /* CTC inhibit mask, see D_INHMASK macros */
} DemIf_CtcInhibitType_Str;

/**
 * This structure holds the global variables related to the inhibit delay.
 */
typedef struct DemIf_DelayInhibitCtrl_Struct {
	VAR(uint32, AUTOMATIC) TimerHandler_mS_u32p0;           /* Timer handler to count the elapsed time */
	VAR(SysPwrMd, AUTOMATIC) PrevSysPwrMdSignal_Cnt_enum;   /* Previous system power mode (change detector) */
	VAR(boolean, AUTOMATIC) IsDelayElapsed_Cnt_lgc;         /* TRUE when the delay has elapsed */
} DemIf_DelayInhibitCtrl_Str;

/**********************************************************************************************************************
 *  Constants
 *********************************************************************************************************************/

#define DEMIF_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/*
 * Configuration table of the inhibit mask for each DTC.
 */
STATIC CONST(DemIf_CtcInhibitType_Str, AP_DEMIF_CONST) T_CTCTestEnables_Cnt_str[D_NUMOFDEMEVENTS_CNT_U08] = {  /* PRQA S 3218 */
		{0x50A954U, &k_CtcInhibitMask50A954_Cnt_u16},   /**< System Thermal Error - Temperature High */
		{0x40514BU, &k_CtcInhibitMask40514B_Cnt_u16},   /**< Steering Wheel Angle Sensor - Calibration Not Learned */
		{0x405158U, &k_CtcInhibitMask405158_Cnt_u16},   /**< Steering Wheel Angle Sensor - Hardware Fault */
		{0x40515AU, &k_CtcInhibitMask40515A_Cnt_u16},   /**< Steering Wheel Angle Sensor - Plausibility */
		{0x543700U, &k_CtcInhibitMask543700_Cnt_u16},   /**< Steering Wheel Torque Input Sensor */
		{0x544A00U, &k_CtcInhibitMask544A00_Cnt_u16},   /**< ECU Hardware Performance */
		{0x544B42U, &k_CtcInhibitMask544B42_Cnt_u16},   /**< ECU Swr Performance - Calibration Data Set Not Programmed */
		{0x551203U, &k_CtcInhibitMask551203_Cnt_u16},   /**< Device Power - Voltage Below Threshold */
		{0x551207U, &k_CtcInhibitMask551207_Cnt_u16},   /**< Device Power - Voltage Above Maximum Threshold */
		{0x551212U, &k_CtcInhibitMask551212_Cnt_u16},   /**< Device Power - Voltage Below Minimum Threshold */
		{0xC07300U, &k_CtcInhibitMaskC07300_Cnt_u16},   /**< Control Module High Speed Communication Bus Off */
		{0xC07700U, &k_CtcInhibitMaskC07700_Cnt_u16},   /**< Control Module Chassis Expansion Communication Bus Off */
		{0xC10000U, &k_CtcInhibitMaskC10000_Cnt_u16},   /**< Lost Communication with Engine Control Module */
		{0xC10100U, &k_CtcInhibitMaskC10100_Cnt_u16},   /**< Lost Communication with Transmission Control Module */
		{0xC12100U, &k_CtcInhibitMaskC12100_Cnt_u16},   /**< Lost Communication with Electronic Brake Control Module */
		{0xC14000U, &k_CtcInhibitMaskC14000_Cnt_u16},   /**< Lost Communication with Body Control Module */
		{0xC15900U, &k_CtcInhibitMaskC15900_Cnt_u16},   /**< Lost Communication with Park Assist Control Module */
		{0xC26A00U, &k_CtcInhibitMaskC26A00_Cnt_u16},   /**< Lost Communication with Front Camera Module  */
		{0xC40171U, &k_CtcInhibitMaskC40171_Cnt_u16},   /**< Invalid Data Received From ECM - Invalid Data */
		{0xC40271U, &k_CtcInhibitMaskC40271_Cnt_u16},   /**< Invalid Data Received From Transmission Control Module */
		{0xC41571U, &k_CtcInhibitMaskC41571_Cnt_u16},   /**< Invalid Data Received From Electronic Brake Control Module */
		{0xC42271U, &k_CtcInhibitMaskC42271_Cnt_u16},   /**< Invalid Data Received From Body Control Module */
		{0xC45A71U, &k_CtcInhibitMaskC45A71_Cnt_u16},   /**< Invalid Data Received From Park Assist Control Module */
		{0xC56B71U, &k_CtcInhibitMaskC56B71_Cnt_u16},   /**< Invalid Data Received From Front Camera Module */
		{0xD83300U, &k_CtcInhibitMaskD83300_Cnt_u16},   /**< Lost Communication with EBCM on CE Bus */
		{0xE50271U, &k_CtcInhibitMaskE50271_Cnt_u16},   /**< Invalid Data Received From EBCM - Invalid Data on CE Bus */
		{0x51D200U, &k_CtcInhibitMask51D200_Cnt_u16},   /**< Electric Steering Motor Circuit */
		{0x51EF00U, &k_CtcInhibitMask51EF00_Cnt_u16},   /**< Electric Steering Motor Position Sensor Circuit */
		{0x54374BU, &k_CtcInhibitMask54374B_Cnt_u16},   /**< Steering Wheel Torque Input Sensor - Calibration Not Learned */
		{0x559700U, &k_CtcInhibitMask559700_Cnt_u16},   /**< Steering Failure Mitigation Level 1 Diagnostics */
};

#define DEMIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *  Global Variables
 *********************************************************************************************************************/

/*********************************************************************************************************************/
#define DEMIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/**
 * This structure holds the global variables related to the inhibit delay.
 */
STATIC VAR(DemIf_DelayInhibitCtrl_Str, AP_DEMIF_VAR) DemIf_DelayInhibitCtrl_Cnt_M_str;

#define DEMIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/*********************************************************************************************************************/
#define DEMIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

VAR(Dem_OptimizedNvMDataType, AP_DEMIF_VAR) Dem_NvData_BufferOpt;

#define DEMIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *  Prototypes
 *********************************************************************************************************************/

STATIC FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_DelayInhibitInit(void);
STATIC FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_DelayInhibitPer(void);
STATIC FUNC(boolean, RTE_AP_DEMIF_APPL_CODE) DemIf_IsDelayInhibitPassed(void);
STATIC FUNC(uint16, RTE_AP_DEMIF_APPL_CODE) DemIf_GetEcuStatusMask(void);

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
 *   NTC_Num_PowerRelayInit2Flt (75U)
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
 *   NTC_Num_Inv2GateDrvFltInProcess (92U)
 *   NTC_Num_Inv2GateDrvFlt (93U)
 *   NTC_Num_Inv2OnStateSingleFET (94U)
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
 * NxtrOpCycle: Enumeration of integer in interval [0...0] with enumerators
 *   NxtrDefaultOpCycle (0U)
 * NxtrOpCycleState: Enumeration of integer in interval [1...2] with enumerators
 *   NXTR_CYCLE_STATE_START (1U)
 *   NXTR_CYCLE_STATE_END (2U)
 * SysPwrMd: Enumeration of integer in interval [0...3] with enumerators
 *   Off (0U)
 *   Accessory (1U)
 *   Run (2U)
 *   CrankRequest (3U)
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
 * Float: D_VECUMIN_VOLTS_F32 = 5.0F
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_DEMIF_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_DemShutdown
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DemShutdown> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DemIf_DemShutdown(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_DemShutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_DemShutdown
 *********************************************************************************************************************/
	VAR(uint8, AUTOMATIC) i;
	VAR(uint8, AUTOMATIC) j;

	Dem_Shutdown();
	/* Copy DEM buffer to NvM Block Buffer */
	for (i  =0U; i < (uint8)DEM_NVDATA_PATTERN_SIZE; i++)
	{
		Dem_NvData_BufferOpt.consistencyPattern[i] = Dem_NvData.consistencyPattern[i];
		Dem_NvData_BufferOpt.terminatingPattern[i] = Dem_NvData.terminatingPattern[i];
	}

	Dem_NvData_BufferOpt.chronoPriMemUsed = Dem_NvData.chronoPriMemUsed;

	for (i = 0U; i < (uint8)DEM_MAX_NUMBER_EVENT_ENTRY; i++)
	{
		if (Dem_NvData.primaryStack[i][0] == 1U)
		{
			/* If snapshot counter shows 1 snapshot stored, update counter to 2 and save the 1st snapshot data to NvM */
			Dem_NvData_BufferOpt.primaryStack[i][0] = 2U;

			for (j = 1U; j <= (uint8)DEM_MAX_SNAPSHOT_RECORD_SIZE; j++)
			{
				Dem_NvData_BufferOpt.primaryStack[i][j] = Dem_NvData.primaryStack[i][j];
			}

		}
		else if (Dem_NvData.primaryStack[i][0] == 2U)
		{
			/* If snapshot counter shows 2 snapshots stored, save the 2nd snapshot data to NvM */
			Dem_NvData_BufferOpt.primaryStack[i][0] = 2U;

			for (j = 1U; j <= (uint8)DEM_MAX_SNAPSHOT_RECORD_SIZE; j++)
			{
				Dem_NvData_BufferOpt.primaryStack[i][j] = Dem_NvData.primaryStack[i][j + (uint8)DEM_MAX_SNAPSHOT_RECORD_SIZE];
			}
		}
		else
		{
			/* If snapshot counter shows 0 snapshots stored, clear out the snapshot data */
			for (j = 0U; j <= (uint8)DEM_MAX_SNAPSHOT_RECORD_SIZE; j++)
			{
				Dem_NvData_BufferOpt.primaryStack[i][j] = 0U;
			}
		}

		Dem_NvData_BufferOpt.chronoPriMem[i] = Dem_NvData.chronoPriMem[i];
		Dem_NvData_BufferOpt.dtcAgingCounter[i] = Dem_NvData.dtcAgingCounter[i];
	}

	for (i=0U; i<=D_NUMOFDEMEVENTS_CNT_U08; i++)
	{
		Dem_NvData_BufferOpt.dtcStatusByte[i] = Dem_NvData.dtcStatusByte[i];
	}

	Dem_NvData_BufferOpt.firstFailedEvent = Dem_NvData.firstFailedEvent;
	Dem_NvData_BufferOpt.firstConfirmedEvent = Dem_NvData.firstConfirmedEvent;
	Dem_NvData_BufferOpt.mostRecentFailedEvent = Dem_NvData.mostRecentFailedEvent;
	Dem_NvData_BufferOpt.mostRecentConfirmedEvent = Dem_NvData.mostRecentConfirmedEvent;


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_DemIf_Per1_SrlComEngOn_Cnt_lgc(void)
 *   SysPwrMd Rte_IRead_DemIf_Per1_SrlComSysPwrMd_Cnt_enum(void)
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

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_Per1
 *********************************************************************************************************************/

	DemIf_DelayInhibitPer();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_RestartDem
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RestartDem> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DemIf_RestartDem(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_RestartDem(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_RestartDem
 *********************************************************************************************************************/

	Dem_Init();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_SetEventStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetEventStatus> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BusOffCE_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_BusOffHS_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_DisableCEBusNormComm_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_DisableHSBusNormComm_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_EngRunAtvForCTCInhibit_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SPMForCTCInhibit_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SrlComSysPwrMd_Cnt_enum(SysPwrMd *data)
 *   Std_ReturnType Rte_Read_Vecu_Volt_f32(Float *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DemIf_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_AP_DEMIF_APPL_CODE) DemIf_SetEventStatus(UInt8 EventId, NxtrDiagMgrStatus EventStatus)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_SetEventStatus (returns application error)
 *********************************************************************************************************************/
	VAR(uint8, AUTOMATIC) Index_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) DtcMask_T_u16 = 0U;
	VAR(uint16, AUTOMATIC) EcuStatusMask_T_u16 = 0U;
	VAR(uint32, AUTOMATIC) DemDTCNum_Cnt_T_u32;
	VAR(boolean, AUTOMATIC) Inhibit_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) HSBusInhibitActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) CEBusInhibitActive_Cnt_T_lgc;

	/* Update HS and CE communication status */
	(void)Rte_Read_DisableHSBusNormComm_Cnt_lgc(&HSBusInhibitActive_Cnt_T_lgc);
	(void)Rte_Read_DisableCEBusNormComm_Cnt_lgc(&CEBusInhibitActive_Cnt_T_lgc);

	/* Inhibit unconditionally when HS or CE communication is inhibited */
	if ((HSBusInhibitActive_Cnt_T_lgc == TRUE) || (CEBusInhibitActive_Cnt_T_lgc == TRUE))
	{
		/* All DTCs are inhibit */
		Inhibit_Cnt_T_lgc = TRUE;
	}
	else
	{
		/* DTCs are enabled */

		/* Update ECU status with the actual values of the inhibit criteria */
		EcuStatusMask_T_u16 = DemIf_GetEcuStatusMask();

		/* Get the DTC number based in the event id */
		(void)Dem_GetDTCOfEvent(EventId, DEM_DTC_KIND_ALL_DTCS, &DemDTCNum_Cnt_T_u32); /* PRQA S 1290 */

		/* Get DTC configured mask. If DTC is not in the table, it will not be inhibit and it will be set in any
		 * condition. */
		for (Index_Cnt_T_u08 = 0U; Index_Cnt_T_u08 < TableSize_m(T_CTCTestEnables_Cnt_str); Index_Cnt_T_u08 += 1U)
		{
			if (T_CTCTestEnables_Cnt_str[Index_Cnt_T_u08].CTCNumber_Cnt_u32 == DemDTCNum_Cnt_T_u32)
			{
				DtcMask_T_u16 = *(T_CTCTestEnables_Cnt_str[Index_Cnt_T_u08].CTCInhibitMaskPtr_Cnt_u16);
				break;
			}
		}

		/* Check if the ECU status matches the inhibit mask configured to the DTC */
		if ((EcuStatusMask_T_u16 & DtcMask_T_u16) != DtcMask_T_u16)
		{
			Inhibit_Cnt_T_lgc = TRUE;
		}
	}

	/* Allow DTC to pass under any conditions - allow to fail only when not inhibited by above test (default case) */
	if ((EventStatus == NTC_STATUS_PASSED) || (Inhibit_Cnt_T_lgc == FALSE))
	{
		(void)Dem_SetEventStatus(EventId, EventStatus);
	}

	return (E_OK);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DemIf_SetOperationCycleState
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetOperationCycleState> of PortPrototype <DemIf>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_SetOperationCycleState(NxtrOpCycle NxtrOperationCycleId, NxtrOpCycleState NxtrCycleState)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DemIf_SetOperationCycleState
 *********************************************************************************************************************/
	
	(void)Dem_SetOperationCycleState(NxtrOperationCycleId, NxtrCycleState);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_DEMIF_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
  * Name:        DemIf_DelayInhibitInit
  * Description: Initialize (reset) the inhibit delay used for some DTCs in order to not set DTCs during ignition
  * 			 transition.
  * Inputs:		 NONE
  * Outputs:     NONE
  ********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_DelayInhibitInit(void)
{
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&DemIf_DelayInhibitCtrl_Cnt_M_str.TimerHandler_mS_u32p0);
	DemIf_DelayInhibitCtrl_Cnt_M_str.IsDelayElapsed_Cnt_lgc = FALSE;
}

/**********************************************************************************************************************
  * Name:        DemIf_DelayInhibitPer
  * Description: Periodic function to control the inhibit delay status.
  * Inputs:		 NONE
  * Outputs:     NONE
  ********************************************************************************************************************/
STATIC FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_DelayInhibitPer(void)
{
	VAR(float32, AUTOMATIC) Vecu_Volt_T_f32;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;
	VAR(SysPwrMd, AUTOMATIC) SysPwrMdSignal_Cnt_T_enum;

	SysPwrMdSignal_Cnt_T_enum = Rte_IRead_DemIf_Per1_SrlComSysPwrMd_Cnt_enum();
	(void)Rte_Read_Vecu_Volt_f32(&Vecu_Volt_T_f32);

	if (((DemIf_DelayInhibitCtrl_Cnt_M_str.PrevSysPwrMdSignal_Cnt_enum != Run) &&
	     (SysPwrMdSignal_Cnt_T_enum == Run)) ||
		(Vecu_Volt_T_f32 < D_DELAYINHIBITUNDER_VOLTS_F32))
	{
		DemIf_DelayInhibitInit();
	}
	else
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(DemIf_DelayInhibitCtrl_Cnt_M_str.TimerHandler_mS_u32p0,
														  &ElapsedTime_mS_T_u16p0);

		if (ElapsedTime_mS_T_u16p0 > D_DELAYINHIBITTIME_MS_U16)
		{
			DemIf_DelayInhibitCtrl_Cnt_M_str.IsDelayElapsed_Cnt_lgc = TRUE;
		}
	}

	DemIf_DelayInhibitCtrl_Cnt_M_str.PrevSysPwrMdSignal_Cnt_enum = SysPwrMdSignal_Cnt_T_enum;
}

/**********************************************************************************************************************
  * Name:        DemIf_IsDelayInhibitPassed
  * Description: Check if the delay passed.
  * Inputs:		 NONE
  * Outputs:     Return TRUE if the delay passed.
  ********************************************************************************************************************/
STATIC FUNC(boolean, RTE_AP_DEMIF_APPL_CODE) DemIf_IsDelayInhibitPassed(void)
{
	return DemIf_DelayInhibitCtrl_Cnt_M_str.IsDelayElapsed_Cnt_lgc;
}

/**********************************************************************************************************************
  * Name:        DemIf_GetEcuStatusMask
  * Description: Get the ECU status for each criterion in a bitmap representation of the input fault signals. Check
  * 			 the bitmap masks macros for more details (D_INHMASKs).
  * Inputs:		 NONE
  * Outputs:     Bitmap value for each criteria for inhibit a DTC.
  ********************************************************************************************************************/
STATIC FUNC(uint16, RTE_AP_DEMIF_APPL_CODE) DemIf_GetEcuStatusMask(void)
{
	VAR(float32, AUTOMATIC) Vecu_Volt_T_f32;
	VAR(uint16, AUTOMATIC) EcuStatus_T_u16 = 0U;
	VAR(boolean, AUTOMATIC) SysPwrMdRun_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) EngRunAtvForCTCInhibit_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HSBusOffNTCActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) BusOffHS_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) BusOffCE_Cnt_T_lgc;
	VAR(SysPwrMd, AUTOMATIC) PwrMd_Cnt_T_enum;

	/* Update if vehicle power mode is RUN */
	(void)Rte_Read_SPMForCTCInhibit_Cnt_lgc(&SysPwrMdRun_Cnt_T_lgc);
	EcuStatus_T_u16 |= (SysPwrMdRun_Cnt_T_lgc == TRUE) ? D_INHMASKPWRMDRUN_CNT_U16 : 0U;

	/* Update if engine is running */
	(void)Rte_Read_EngRunAtvForCTCInhibit_Cnt_lgc(&EngRunAtvForCTCInhibit_Cnt_T_lgc);
	EcuStatus_T_u16 |= (EngRunAtvForCTCInhibit_Cnt_T_lgc == TRUE) ? D_INHMASKENGINERUNNING_CNT_U16 : 0U;

	/* Update the voltage ranges */
	(void)Rte_Read_Vecu_Volt_f32(&Vecu_Volt_T_f32);
	EcuStatus_T_u16 |= ((Vecu_Volt_T_f32 > 6.0F) && (Vecu_Volt_T_f32 < 16.0F)) ? D_INHMASKVBATRANGE6TO16_CNT_U16: 0U;
	EcuStatus_T_u16 |= ((Vecu_Volt_T_f32 > 9.0F) && (Vecu_Volt_T_f32 < 16.0F)) ? D_INHMASKVBATRANGE9TO16_CNT_U16: 0U;

	/* Update the delay inhibit mask */
	EcuStatus_T_u16 |= (DemIf_IsDelayInhibitPassed() == TRUE) ? D_INHMASKDELAY5SECONDS_CNT_U16 : 0U;

	/* Update the U007300 status bit 1 */
	(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_BusOffCh1, &HSBusOffNTCActive_Cnt_T_lgc);
	EcuStatus_T_u16 |= (HSBusOffNTCActive_Cnt_T_lgc == FALSE) ? D_INHMASKU007300STATUSBIT1_CNT_U16 : 0U;

	/* Update customer MEC must be 0 or 0xFF */
	EcuStatus_T_u16 |= ((Nvm_CMEC_Cnt_u8 == 0U) ||
						(Nvm_CMEC_Cnt_u8 == 0xFFU)) ? D_INHMASKCUSTOMERMEC_CNT_U16 : 0U;
	/* Update HS BusOff  condition */
	(void)Rte_Read_BusOffHS_Cnt_lgc(&BusOffHS_Cnt_T_lgc);
	EcuStatus_T_u16 |= (BusOffHS_Cnt_T_lgc == FALSE) ? D_INHMASKNOBUSOFFHS_CNT_U16 : 0U;

	/* Update CE BusOff  condition */
	(void)Rte_Read_BusOffCE_Cnt_lgc(&BusOffCE_Cnt_T_lgc);
	EcuStatus_T_u16 |= (BusOffCE_Cnt_T_lgc == FALSE) ? D_INHMASKNOBUSOFFCE_CNT_U16 : 0U;

	/* Update if vehicle power mode is RUN or ACC */
	(void)Rte_Read_SrlComSysPwrMd_Cnt_enum(&PwrMd_Cnt_T_enum);
	EcuStatus_T_u16 |= ((SysPwrMdRun_Cnt_T_lgc == TRUE) ||
	                    (PwrMd_Cnt_T_enum == Accessory)) ? D_INHMASKPWRMDRUNORACC_CNT_U16 : 0U;

	return EcuStatus_T_u16;
}

/* Copy NvM Buffer data into RAM buffer DEM uses */
FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Init(void)
{
	VAR(uint8, AUTOMATIC) i;
	VAR(uint8, AUTOMATIC) j;

	/* Copy Data out of NvM Into RAM Buffer */
	for (i = 0U; i < (uint8)DEM_NVDATA_PATTERN_SIZE; i++)
	{
		Dem_NvData.consistencyPattern[i] = Dem_NvData_BufferOpt.consistencyPattern[i];
		Dem_NvData.terminatingPattern[i] = Dem_NvData_BufferOpt.terminatingPattern[i];
	}

	Dem_NvData.chronoPriMemUsed = Dem_NvData_BufferOpt.chronoPriMemUsed;

	for (i = 0U; i < (uint8)DEM_MAX_NUMBER_EVENT_ENTRY; i++)
	{
		Dem_NvData.primaryStack[i][0] = Dem_NvData_BufferOpt.primaryStack[i][0];
		for (j = 1U; j <= (uint8)DEM_MAX_SNAPSHOT_RECORD_SIZE; j++)
		{
			Dem_NvData.primaryStack[i][j] = Dem_NvData_BufferOpt.primaryStack[i][j];
			Dem_NvData.primaryStack[i][j + (uint8)DEM_MAX_SNAPSHOT_RECORD_SIZE] = Dem_NvData_BufferOpt.primaryStack[i][j];
		}

		Dem_NvData.chronoPriMem[i] = Dem_NvData_BufferOpt.chronoPriMem[i];
		Dem_NvData.dtcAgingCounter[i] = Dem_NvData_BufferOpt.dtcAgingCounter[i];
	}

	for (i = 0U; i <= (uint8)DEM_NUMBER_OF_EVENTS; i++)
	{
		if (i <= D_NUMOFDEMEVENTS_CNT_U08)
		{
			Dem_NvData.dtcStatusByte[i] = Dem_NvData_BufferOpt.dtcStatusByte[i];
		}
		else
		{
			Dem_NvData.dtcStatusByte[i] = 0x50U; /* 0x50 is default status */
		}

		Dem_NvData.dtcFaultDetectionCounter[i] = 0;
	}

	Dem_NvData.firstFailedEvent = Dem_NvData_BufferOpt.firstFailedEvent;
	Dem_NvData.firstConfirmedEvent = Dem_NvData_BufferOpt.firstConfirmedEvent;
	Dem_NvData.mostRecentFailedEvent = Dem_NvData_BufferOpt.mostRecentFailedEvent;
	Dem_NvData.mostRecentConfirmedEvent = Dem_NvData_BufferOpt.mostRecentConfirmedEvent;

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
