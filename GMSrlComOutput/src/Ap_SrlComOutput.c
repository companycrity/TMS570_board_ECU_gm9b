/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SrlComOutput.c
 *     Workspace:  C:/02_EA3Int/C1xx/Wip_fz9hxm/GMSrlComOutput/autosar
 *     SW-C Type:  Ap_SrlComOutput
 *  Generated at:  Tue May  3 17:33:04 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SrlComOutput>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          6 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Wed Mar  5 13:35:47 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/01/16  1        GMN       Initial GMSrlComOutput Synergy Version
 * 04/28/16  2        CP        EA3#2269: 778 Message does not report CTC 41 76 54
 *                              EA3#7817: Incorrect checksum is calculated for MSG 184
 *                              EA3#2060: 778 Msg does not report serial/Non serial data fault correctly
 * 05/09/16  3        GMN       Added new signal for message 0x148
 * 05/22/16  4        CP        EA3#2060: Updated Init function to clear 778 DTC triggered flags after Ign Cycle
 * 06/09/16  5        GMN       Added function to reset the status flag and CAN output buffer
 * 08/26/16  6        GMN       List of torque NTCs used by some signals now configurable by project
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


 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_SrlComOutput.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Dem.h"
#include "Dem_Lcfg.h"
#include "il_inc.h"
#include "il_par.h"
#include "can_par.h"
#include "fixmath.h"
#include "string.h"
#include "Ap_DemIf.h"
#include "CDD_Data.h"
#include "Dem_Lcfg.h"
#include "DiagMgr_Cfg.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include "T1_AppInterface.h"
#include "Ap_DfltConfigData.h"
#include "Ap_SrlComOutput.h"
#include "Ap_SrlComOutput_Cfg.h"


/* PRQA S 4395 EOF
 * MISRA-C: 2004 Rule 10.4: This deviation is required for a composite expression of 'essentially float' typ */


#define D_TESTFAILED_CNT_U8        0x01U
#define D_FAILEDTHISCYC_CNT_U8     0x02U
#define D_PENDING_CNT_U8           0x04U
#define D_CONFIRMED_CNT_U8         0x08U
#define D_TESTNCSINCECLEAR_CNT_U8  0x10U
#define D_FAILEDSINCECLEAR_CNT_U8  0x20U
#define D_TESTNCTHISCYC_CNT_U8     0x40U
#define D_WARNINGIND_CNT_U8        0x80U
#define D_VALID_CNT_U08            0x00U
#define D_INVALID_CNT_U08          0x01U
#define D_DISABLED_CNT_U08         0U
#define D_ENABLED_CNT_U08          1U
#define D_FAILED_CNT_U08           2U
#define D_LKAACTIVE_CNT_U08        1U
#define D_HANDSON_CNT_U08          1U
#define D_HANDSOFF_CNT_U08         0U

/* LKADrvAppldTrq - LKA Drive Applied Torque */
#define D_LKADRIVERAPPLIEDTORQUESF_NM_F32       (0.01F)     /* Scale Factor */
#define D_LKADRIVERAPPLIEDTORQUEMIN_NM_F32      (-10.24F)   /* Minimum */
#define D_LKADRIVERAPPLIEDTORQUEMAX_NM_F32      (10.23F)    /* Maximum */

/* LKATrqOvrlDltTrqDlv - LKA Torque Overlay Delta Torque Delivered */
#define D_LKATRQDELIVEREDSF_NM_F32          (0.01F)     /* Scale Factor */
#define D_LKATRQDELIVEREDMIN_NM_F32         (-10.24F)   /* Minimum */
#define D_LKATRQDELIVEREDMAX_NM_F32         (10.23F)    /* Maximum */

/* LKAElPwrStTtlTqDlvd - LKA Electrical Power Steering Total Torque Delivered */
#define D_TOTALTORQUESF_NM_F32              (0.01F)     /* Scale Factor */
#define D_TOTALTORQUEMIN_NM_F32             (-10.24F)   /* Minimum */
#define D_TOTALTORQUEMAX_NM_F32             (10.23F)    /* Maximum */

#define D_USEDATA_CNT_U08               1U
#define D_DONTUSEDATA_CNT_U08           0U

#define D_SENSORTYPE4_CNT_u08           3u

#define D_CALSTATUNKNOWN_CNT_U08        0U
#define D_CALSTATCALIBRATED_CNT_U08     2U

#define D_EPSSOURCEID_CNT_U16           0x31U

#define D_STRWHANGSCALE_ULS_F32         0.0625F
#define D_STRWHANGLOLMT_ULS_F32         (-2048.0F)
#define D_STRWHANGHILMT_ULS_F32         2047.9375F

#define D_STRWHANGGRDLOLMT_ULS_F32      (-2048.0F)
#define D_STRWHANGGRDHILMT_ULS_F32      (2047.0F)

#define D_ESCTRQSCALE_ULS_F32           0.01F
#define D_ESCTRQLOLMT_ULS_F32           (-10.24F)
#define D_ESCTRQHILMT_ULS_F32           10.23F

#define D_ESCTOTALTRQSCALE_ULS_F32      0.01F
#define D_ESCTOTALTRQLOLMT_HWNM_F32     (-10.24F)
#define D_ESCTOTALTRQHILMT_HWNM_F32     10.23F


typedef struct
{
	boolean DTCTriggered;
	uint8 DTCSource;
	uint16 DTCNumber;
	uint8 DTCFailType;
	boolean DTCWrnIndRqdSt;
	boolean DTCTstFldPwrUpSt;
	boolean DTCTstNPsdPwrupSt;
	boolean DTCHistStat;
	boolean DTCTstFldCdClrdStat;
	boolean DTCTstNPsdCdClrdSt;
	boolean DTCCurrentStatus;
	boolean DTCCodeSupported;
	uint8 DTCFaulttype;
} RT_DTC_Triggered_778;

typedef struct SignalConfig_tag
{
	float32 Scale_Uls_f32;
	float32 Max_Uls_f32;
	float32 Min_Uls_f32;
} SignalConfig;

typedef enum SignalIndex_tag
{
	SIGNALINDEX_STRWHANG = 0U,
	SIGNALINDEX_STRWHANGGRD,
	SIGNALINDEX_SIZE
} SignalIndex;

#define SRLCOMOUTPUT_START_SEC_CONST_16
#include "MemMap.h" /* PRQA S 5087 */
/* List of NTC for torque. D_LISTOFTORQUENTC_CNT_U16 must be defined in Ap_SrlComOutput_Cfg.h. */
STATIC CONST(uint16, AUTOMATIC) T_LISTOFTORQUENTC_CNT_U16[] = D_LISTOFTORQUENTC_CNT_U16; /* PRQA S 3218 */
#define SRLCOMOUTPUT_STOP_SEC_CONST_16
#include "MemMap.h" /* PRQA S 5087 */

#define SRLCOMOUTPUT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
VAR(boolean, AP_SRLCOMOUTPUT_VAR) DTCTriggeredFlag_Cnt_M_lgc[D_NUMOFDEMEVENTS_CNT_U08 + 1U];
STATIC VAR(boolean, AP_SRLCOMOUTPUT_VAR) DTCFailed_Cnt_M_lgc[D_NUMOFDEMEVENTS_CNT_U08 + 1U]; /* PRQA S 3218 */
STATIC VAR(boolean, AP_SRLCOMOUTPUT_VAR) CurrentDTCSentThisIC_Cnt_M_lgc;
STATIC VAR(RT_DTC_Triggered_778, AUTOMATIC) DTCData; /* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) BusOffPresentChannel0_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) BusOffPresentChannel1_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) BusOffDiagActiveChannel0_Cnt_M_lgc; /* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) BusOffDiagActiveChannel1_Cnt_M_lgc; /* PRQA S 3218 */
#define SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define SRLCOMOUTPUT_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR) CTCEventId_Cnt_M_u8;
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR) CTCEventIdSV_Cnt_M_u8;
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR) GMStatus_Cnt_M_u8[D_NUMOFDEMEVENTS_CNT_U08 + 1U]; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR) LastReportedDTCEventID_Cnt_M_u8; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR) LastReportedGMStatus_Cnt_M_u8; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR) StWhlAngAliveRollCnt_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR) LKATrqOvrlDlvdRC_Cnt_M_u8; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR) DrvStrIntfrDetARC_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR) ElcPwrStrAvalStatARC_Cnt_M_u08; /* PRQA S 3218 */
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR) ESCRollCount_Cnt_M_u08; /* PRQA S 3218 */

/* This variable holds the last warning indicator value. Every time the value change a message 0x148 is triggered. */
STATIC VAR(uint8, AP_SRLCOMOUTPUT_VAR) PrevWarningIndSignal_Cnt_M_u08[DEM_NUMBER_OF_INDICATORS]; /* PRQA S 3218 */

#define SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define SRLCOMOUTPUT_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, AP_SRLCOMOUTPUT_VAR) StartTimerToSetDTCFlag_mS_M_u32p0; /* PRQA S 3218 */
STATIC VAR(uint32, AP_SRLCOMOUTPUT_VAR) DemDTCNum_Cnt_M_u32[D_NUMOFDEMEVENTS_CNT_U08 + 1U]; /* PRQA S 3218 */
STATIC VAR(uint32,  AUTOMATIC) BusOffFltChannel0RecoverTimer_mS_M_u32;
STATIC VAR(uint32,  AUTOMATIC) BusOffFltChannel0DetectionTimer_mS_M_u32;
STATIC VAR(uint32,  AUTOMATIC) BusOffFltChannel1RecoverTimer_mS_M_u32;
STATIC VAR(uint32,  AUTOMATIC) BusOffFltChannel1DetectionTimer_mS_M_u32;
#define SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

STATIC FUNC(vuint8, AP_SRLCOMOUTPUT_CODE) ISOToGMStatus(vuint8 statusMask);
STATIC FUNC(uint8, AP_SRLCOMOUTPUT_CODE) SrlComOutput_WarningIndicatorHandler(Dem_IndicatorIdType Dem_IndicatorId);
STATIC FUNC(boolean, SrlComOutput_CheckForTorqueNTC) SrlComOutput_CheckForTorqueNTC(void);
STATIC FUNC(void, AP_SRLCOMOUTPUT_CODE) SrlComOuput_BusOffHandlerInit(void);
STATIC FUNC(void, AP_SRLCOMOUTPUT_CODE) SrlComOutput_BusOffHandler(SysPwrMd SysPwrMd_Cnt_T_enum,
                                                P2VAR(boolean, AUTOMATIC, AUTOMATIC) BusOffHS_Cnt_T_lgc,
                                                P2VAR(boolean, AUTOMATIC, AUTOMATIC) BusOffCE_Cnt_T_lgc);

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
 * APA_State_enum: Enumeration of integer in interval [0...4] with enumerators
 *   APA_TempInhibit (0U)
 *   APA_AvailCntrl (1U)
 *   APA_Active (2U)
 *   APA_PermanentlyFailed (3U)
 *   APA_ManufacturingDisable (4U)
 * ComM_ModeType: Enumeration of integer in interval [0...2] with enumerators
 *   COMM_NO_COMMUNICATION (0U)
 *   COMM_SILENT_COMMUNICATION (1U)
 *   COMM_FULL_COMMUNICATION (2U)
 * ESC_State_enum: Enumeration of integer in interval [0...4] with enumerators
 *   ESC_Inactive (0U)
 *   ESC_Active (1U)
 *   ESC_TemporarilyLimited (2U)
 *   ESC_PermanentlyFailed (3U)
 *   ESC_ManufacturingDisable (4U)
 * LKA_State_enum: Enumeration of integer in interval [0...4] with enumerators
 *   LKA_Inactive (0U)
 *   LKA_Active (1U)
 *   LKA_TemporarilyLimited (2U)
 *   LKA_PermanentlyFailed (3U)
 *   LKA_ManufacturingDisable (4U)
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
 *   NTC_Num_LimpHomeIgnitionCounter (161U)
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
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 * SysPwrMd: Enumeration of integer in interval [0...3] with enumerators
 *   Off (0U)
 *   Accessory (1U)
 *   Run (2U)
 *   CrankRequest (3U)
 *
 * Array Types:
 * ============
 * DTCStsFlg: Array with 40 element(s) of type Boolean
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
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
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * UInt16: D_ZERO_CNT_U16 = 0U
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Boolean *Rte_Pim_DTCTrigSts(void)
#else
 *   DTCStsFlg *Rte_Pim_DTCTrigSts(void)
#endif
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
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
 *   Std_ReturnType Rte_Call_ComM_UserRequest_0_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_COMM_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_ComM_UserRequest_1_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_COMM_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_ComM_UserRequest_2_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_COMM_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_ComM_UserRequest_3_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_COMM_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_ComM_UserRequest_4_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_COMM_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_ComM_UserRequest_5_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_COMM_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_Init1
 *********************************************************************************************************************/
	VAR(uint8, AUTOMATIC) EvntCnt;
	VAR(uint8, AUTOMATIC) ISOStatus_Cnt_T_u8;
 
	(void)Rte_Call_ComM_UserRequest_0_RequestComMode(COMM_FULL_COMMUNICATION);
	(void)Rte_Call_ComM_UserRequest_1_RequestComMode(COMM_FULL_COMMUNICATION);
	(void)Rte_Call_ComM_UserRequest_2_RequestComMode(COMM_FULL_COMMUNICATION);
	(void)Rte_Call_ComM_UserRequest_3_RequestComMode(COMM_FULL_COMMUNICATION);
	(void)Rte_Call_ComM_UserRequest_4_RequestComMode(COMM_FULL_COMMUNICATION);
	(void)Rte_Call_ComM_UserRequest_5_RequestComMode(COMM_FULL_COMMUNICATION);

	CTCEventId_Cnt_M_u8 = D_NUMOFDEMEVENTS_CNT_U08 + 1U; /*Fix for EA3#2269*/
	CTCEventIdSV_Cnt_M_u8 = 0U;
	CurrentDTCSentThisIC_Cnt_M_lgc = FALSE;
	
	for (EvntCnt = 1U; EvntCnt <= D_NUMOFDEMEVENTS_CNT_U08; EvntCnt++)
	{
		if (TRUE == (*(Rte_Pim_DTCTrigSts()))[EvntCnt])
		{
			(void)Dem_GetEventStatus(EvntCnt, &ISOStatus_Cnt_T_u8);
			if (((ISOStatus_Cnt_T_u8 & D_FAILEDTHISCYC_CNT_U8) != D_FAILEDTHISCYC_CNT_U8) &&
				((ISOStatus_Cnt_T_u8 & D_TESTNCTHISCYC_CNT_U8) != D_TESTNCTHISCYC_CNT_U8))
			{
				DTCTriggeredFlag_Cnt_M_lgc[EvntCnt] = FALSE;
			}
			else
			{
				DTCTriggeredFlag_Cnt_M_lgc[EvntCnt] = TRUE;
			}

		}
		else
		{
			DTCTriggeredFlag_Cnt_M_lgc[EvntCnt] = FALSE;
		}
	}
	SrlComOuput_BusOffHandlerInit();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *     and not in Mode(s) <OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_APADrvrInterventionDetected_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_APAState_State_enum(APA_State_enum *data)
 *   Std_ReturnType Rte_Read_DiagRmpToZeroActive_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_ESCState_State_enum(ESC_State_enum *data)
 *   Std_ReturnType Rte_Read_ESCTorqueDelivered_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_HOWEstimate_Uls_f32(Float *data)
 *   Std_ReturnType Rte_Read_HwTrq_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_LKAState_State_enum(LKA_State_enum *data)
 *   Std_ReturnType Rte_Read_LKATrqDelivered_HwNm_f32(Float *data)
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
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_Per1
 *********************************************************************************************************************/
	VAR(uint8, AUTOMATIC) i;
	VAR(uint8, AUTOMATIC) WarningIndSignal_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) ISOStatus_Cnt_T_u8;
	VAR(uint16, AUTOMATIC) TimeoutElapsedTime_mS_T_u16p0;
	VAR(float32, AUTOMATIC) DriverAppliedTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) LKATorqueDelivered_HwNm_T_f32;
	VAR(sint16, AUTOMATIC) LKATorqueDelivered_Cnt_T_s16;
	VAR(sint16, AUTOMATIC) DriverAppliedTorque_Cnt_T_s16;
	VAR(sint16, AUTOMATIC) TotalTorque_Cnt_T_s16;
	VAR(LKA_State_enum, AUTOMATIC)  LKAState_Cnt_T_u8;
	VAR(uint16, AUTOMATIC)  CheckSum_Cnt_T_u16;
	VAR(float32, AUTOMATIC) TotalTorque_HwNm_T_f32;
	VAR(boolean, AUTOMATIC) TorqueSensorFault_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) HndsOffStrWhlDtStV_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) HndsOffStrWhlDtMd_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) HndsOffStrWhlDtSt_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) VehicleSpeedMissing_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VehicleSpeedInvalid_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) HOWEstimate_Uls_T_f32;
	VAR(ESC_State_enum, AUTOMATIC) ESCState_State_enum;
	VAR(float32, AUTOMATIC) ESCTorqueDelivered_HwNm_f32;
	VAR(sint16, AUTOMATIC) ESCTorqueDelivered_Cnt_s16;
	VAR(float32, AUTOMATIC) ESCTotalTorqueDelivered_HwNm_f32;
	VAR(sint16, AUTOMATIC) ESCTotalTorqueDelivered_Cnt_s16;
	VAR(uint16, AUTOMATIC) ESCChecksum_Cnt_u16;
	VAR(boolean, AUTOMATIC) F1orF2FaultPresent_Cnt_T_lgc;
	
	/* Message 148 implementation */

	/* Check for Power Steering warning indicator */
	WarningIndSignal_Cnt_T_u08 = SrlComOutput_WarningIndicatorHandler(Dem_Warning_Indicator);
	IlPutTxPwrStrIO(WarningIndSignal_Cnt_T_u08);

	/* Check for Steering Reduced Assist warning indicator */
	WarningIndSignal_Cnt_T_u08 = SrlComOutput_WarningIndicatorHandler(Dem_Steering_Reduced_Assist);
	IlPutTxStrngAsstRdcdIO(WarningIndSignal_Cnt_T_u08);

#if (D_WARNINGINDSTEERINGREDUCEDASSIST2_ENABLED == 1)
	/* Check for Steering Reduced Assist Level 2 warning indicator */
	WarningIndSignal_Cnt_T_u08 = SrlComOutput_WarningIndicatorHandler(Dem_Steering_Reduced_Assist_Level2);
	IlPutTxStrAsstRdcdLvl2IO(WarningIndSignal_Cnt_T_u08);
#endif

	/* message 778 implementation */
	if (CTCEventId_Cnt_M_u8 >= (D_NUMOFDEMEVENTS_CNT_U08 + 1U)) /*Fix for EA3#2269*/
	{
		for(i = 1U; i <= D_NUMOFDEMEVENTS_CNT_U08; i++)
		{
			(void)Dem_GetEventFailed(i, &DTCFailed_Cnt_M_lgc[i]);
			(void)Dem_GetDTCOfEvent(i, DEM_DTC_KIND_ALL_DTCS, &DemDTCNum_Cnt_M_u32[i]);
			(void)Dem_GetEventStatus(i, &ISOStatus_Cnt_T_u8);
			GMStatus_Cnt_M_u8[i] = ISOToGMStatus(ISOStatus_Cnt_T_u8);
		}
		CTCEventId_Cnt_M_u8 = 1U;
	}
	else
	{
		if ((((GMStatus_Cnt_M_u8[CTCEventId_Cnt_M_u8]) & D_FAILEDTHISCYC_CNT_U8) ==  D_FAILEDTHISCYC_CNT_U8) &&
			  (DTCTriggeredFlag_Cnt_M_lgc[CTCEventId_Cnt_M_u8] == FALSE))
		{
			DTCData.DTCTriggered = (boolean)(DTCTriggeredFlag_Cnt_M_lgc[CTCEventId_Cnt_M_u8] == FALSE);
			DTCData.DTCSource = D_EPSSOURCEID_CNT_U16;
			DTCData.DTCNumber = (uint16)((DemDTCNum_Cnt_M_u32[CTCEventId_Cnt_M_u8] >> 8U) & 0xFFFFU);
			DTCData.DTCFailType = (uint8)((DemDTCNum_Cnt_M_u32[CTCEventId_Cnt_M_u8]) & 0x00FFU);
			DTCData.DTCWrnIndRqdSt = (boolean)((GMStatus_Cnt_M_u8[CTCEventId_Cnt_M_u8]  & 0x80U) >> 7U);
			DTCData.DTCTstFldPwrUpSt = (boolean)((GMStatus_Cnt_M_u8[CTCEventId_Cnt_M_u8] & 0x40U) >> 6U);
			DTCData.DTCTstNPsdPwrupSt = (boolean)((GMStatus_Cnt_M_u8[CTCEventId_Cnt_M_u8] & 0x20U) >> 5U);
			DTCData.DTCHistStat = (boolean)((GMStatus_Cnt_M_u8[CTCEventId_Cnt_M_u8] & 0x10U) >> 4U);
			DTCData.DTCTstFldCdClrdStat = (boolean)((GMStatus_Cnt_M_u8[CTCEventId_Cnt_M_u8] & 0x08U) >> 3U);
			DTCData.DTCTstNPsdCdClrdSt = (boolean)((GMStatus_Cnt_M_u8[CTCEventId_Cnt_M_u8] & 0x04U) >> 2U);
			DTCData.DTCCurrentStatus = (boolean)((GMStatus_Cnt_M_u8[CTCEventId_Cnt_M_u8] & 0x02U) >> 1U);
			DTCData.DTCCodeSupported = (boolean)((GMStatus_Cnt_M_u8[CTCEventId_Cnt_M_u8] & 0x01U));
			DTCData.DTCFaulttype = 0x00U;

			if (CTCEventIdSV_Cnt_M_u8 != CTCEventId_Cnt_M_u8)
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&(StartTimerToSetDTCFlag_mS_M_u32p0));
				CTCEventIdSV_Cnt_M_u8 = CTCEventId_Cnt_M_u8;
			}
			else
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(StartTimerToSetDTCFlag_mS_M_u32p0, &TimeoutElapsedTime_mS_T_u16p0);
				if (TimeoutElapsedTime_mS_T_u16p0 > 1500U)
				{
				    DTCTriggeredFlag_Cnt_M_lgc[CTCEventId_Cnt_M_u8] = TRUE;
					LastReportedDTCEventID_Cnt_M_u8 = CTCEventId_Cnt_M_u8;
					LastReportedGMStatus_Cnt_M_u8 = GMStatus_Cnt_M_u8[LastReportedDTCEventID_Cnt_M_u8];
					CTCEventId_Cnt_M_u8++;
					CurrentDTCSentThisIC_Cnt_M_lgc = TRUE;
				}
			}
		}
		else if (CurrentDTCSentThisIC_Cnt_M_lgc == TRUE)
		{
			DTCData.DTCTriggered = FALSE;
			DTCData.DTCSource = D_EPSSOURCEID_CNT_U16;
			DTCData.DTCNumber = (uint16)((DemDTCNum_Cnt_M_u32[LastReportedDTCEventID_Cnt_M_u8] >> 8U) & 0xFFFFU);
			DTCData.DTCFailType = (uint8)((DemDTCNum_Cnt_M_u32[LastReportedDTCEventID_Cnt_M_u8]) & 0x00FFU);
			DTCData.DTCWrnIndRqdSt = (boolean)((LastReportedGMStatus_Cnt_M_u8 & 0x80U) >> 7U);
			DTCData.DTCTstFldPwrUpSt = (boolean)((LastReportedGMStatus_Cnt_M_u8 & 0x40U) >> 6U);
			DTCData.DTCTstNPsdPwrupSt = (boolean)((LastReportedGMStatus_Cnt_M_u8 & 0x20U) >> 5U);
			DTCData.DTCHistStat = (boolean)((LastReportedGMStatus_Cnt_M_u8 & 0x10U) >> 4U);
			DTCData.DTCTstFldCdClrdStat = (boolean)((LastReportedGMStatus_Cnt_M_u8 & 0x08U) >> 3U);
			DTCData.DTCTstNPsdCdClrdSt = (boolean)((LastReportedGMStatus_Cnt_M_u8 & 0x04U) >> 2U);
			DTCData.DTCCurrentStatus = (boolean)((LastReportedGMStatus_Cnt_M_u8 & 0x02U) >> 1U);
			DTCData.DTCCodeSupported = (boolean)((LastReportedGMStatus_Cnt_M_u8 & 0x01U));
			DTCData.DTCFaulttype = 0x00U;

			CTCEventId_Cnt_M_u8++;
		}
		else
		{

			DTCData.DTCTriggered = FALSE;
			DTCData.DTCSource = D_EPSSOURCEID_CNT_U16;
			DTCData.DTCNumber = 0x0000U;
			DTCData.DTCFailType = 0x00U;
			DTCData.DTCWrnIndRqdSt = FALSE;
			DTCData.DTCTstFldPwrUpSt = FALSE;
			DTCData.DTCTstNPsdPwrupSt = FALSE;
			DTCData.DTCHistStat = FALSE;
			DTCData.DTCTstFldCdClrdStat = FALSE;
			DTCData.DTCTstNPsdCdClrdSt = FALSE;
			DTCData.DTCCurrentStatus = FALSE;
			DTCData.DTCCodeSupported = FALSE;
			DTCData.DTCFaulttype = 0x00U;

			CTCEventId_Cnt_M_u8++;

			CurrentDTCSentThisIC_Cnt_M_lgc = FALSE;
		}
	}

	/* Steering_Torqe_Overlay_Stat_CE (Msg ID 0x1CA) */
	(void)Rte_Read_ESCState_State_enum(&ESCState_State_enum);
	(void)Rte_Read_ESCTorqueDelivered_HwNm_f32(&ESCTorqueDelivered_HwNm_f32);
	(void)Rte_Read_HwTrq_HwNm_f32(&DriverAppliedTorque_HwNm_T_f32);

	ESCState_State_enum = ESCState_State_enum & 3U;

	ESCTotalTorqueDelivered_HwNm_f32 = ESCTorqueDelivered_HwNm_f32 + DriverAppliedTorque_HwNm_T_f32;
	ESCTotalTorqueDelivered_HwNm_f32 = Limit_m(ESCTotalTorqueDelivered_HwNm_f32, D_ESCTOTALTRQLOLMT_HWNM_F32, D_ESCTOTALTRQHILMT_HWNM_F32);
	ESCTotalTorqueDelivered_HwNm_f32 /= D_ESCTOTALTRQSCALE_ULS_F32;
	ESCTotalTorqueDelivered_Cnt_s16 = (sint16)ESCTotalTorqueDelivered_HwNm_f32;
	ESCTotalTorqueDelivered_Cnt_s16 *= k_SComTrqPosPol_Cnt_s08;

	/* Scale and limit delivered torque before sending it out on the bus.*/
	ESCTorqueDelivered_HwNm_f32 = Limit_m(ESCTorqueDelivered_HwNm_f32, D_ESCTRQLOLMT_ULS_F32, D_ESCTRQHILMT_ULS_F32);
	ESCTorqueDelivered_HwNm_f32 /= D_ESCTRQSCALE_ULS_F32;
	ESCTorqueDelivered_Cnt_s16 = (sint16)ESCTorqueDelivered_HwNm_f32;
	ESCTorqueDelivered_Cnt_s16 *= k_SComTrqPosPol_Cnt_s08;

	IlPutTxElPwrStTtlTqDlrd(ESCTotalTorqueDelivered_Cnt_s16);
	IlPutTxTrqOvrlTrqDStat(ESCState_State_enum);
	IlPutTxTrqOvrlDvrdARC(ESCRollCount_Cnt_M_u08);
	IlPutTxTrqOvrlDltTrqDlrd(ESCTorqueDelivered_Cnt_s16);

	/* Calculate checksum */
	ESCChecksum_Cnt_u16 = 
				(uint16)Steering_Torque_Overlay_Stat_CE._c[0] +
				(uint16)Steering_Torque_Overlay_Stat_CE._c[1] +
				(uint16)Steering_Torque_Overlay_Stat_CE._c[2] +
				(uint16)Steering_Torque_Overlay_Stat_CE._c[3] +
				(uint16)Steering_Torque_Overlay_Stat_CE._c[4] +
				(uint16)Steering_Torque_Overlay_Stat_CE._c[5] +
				(((uint16)Steering_Torque_Overlay_Stat_CE._c[6] & 0x00F8u) >> 3u) +
				(0x1CAU / 8u);

	ESCRollCount_Cnt_M_u08 = (ESCRollCount_Cnt_M_u08 + 1u) & 0x0Fu;

	IlPutTxTrqOvrlDChksm(ESCChecksum_Cnt_u16);

	/* LKA_Steering_Trq_Overlay_Stat_HS (Msg ID 0x184) */
	if (TRUE == k_LKAMfgEnable_Cnt_lgc)
	{
		(void)Rte_Read_LKAState_State_enum(&LKAState_Cnt_T_u8);
		(void)Rte_Read_LKATrqDelivered_HwNm_f32(&LKATorqueDelivered_HwNm_T_f32);
		(void)Rte_Read_HOWEstimate_Uls_f32(&HOWEstimate_Uls_T_f32);
		(void)Rte_Read_DiagRmpToZeroActive_Cnt_lgc(&F1orF2FaultPresent_Cnt_T_lgc);

		(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_MissingMsg_R, &VehicleSpeedMissing_Cnt_T_lgc);
		(void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_InvalidMsg_R, &VehicleSpeedInvalid_Cnt_T_lgc);

		/* Scale and limit Driver Applied Torque for transmission on the bus. */
		/* Note: this re-uses DriverAppliedTorque signal read for ESC */
		DriverAppliedTorque_HwNm_T_f32 = Limit_m(DriverAppliedTorque_HwNm_T_f32, D_LKADRIVERAPPLIEDTORQUEMIN_NM_F32, D_LKADRIVERAPPLIEDTORQUEMAX_NM_F32);
		DriverAppliedTorque_Cnt_T_s16 = (sint16)(DriverAppliedTorque_HwNm_T_f32 / D_LKADRIVERAPPLIEDTORQUESF_NM_F32) * k_SComTrqPosPol_Cnt_s08;

		/* Scale and limit LKA Torque Delivered for transmission on the bus. */
		LKATorqueDelivered_HwNm_T_f32 = Limit_m(LKATorqueDelivered_HwNm_T_f32, D_LKATRQDELIVEREDMIN_NM_F32, D_LKATRQDELIVEREDMAX_NM_F32);
		LKATorqueDelivered_Cnt_T_s16 = (sint16)(LKATorqueDelivered_HwNm_T_f32 / D_LKATRQDELIVEREDSF_NM_F32) * k_SComTrqPosPol_Cnt_s08;

		/* Scale and limit Total Torque for transmission on the bus. */
		TotalTorque_HwNm_T_f32 = DriverAppliedTorque_HwNm_T_f32 + LKATorqueDelivered_HwNm_T_f32;
		TotalTorque_HwNm_T_f32 = Limit_m(TotalTorque_HwNm_T_f32, D_TOTALTORQUEMIN_NM_F32, D_TOTALTORQUEMAX_NM_F32);
		TotalTorque_Cnt_T_s16 = (sint16)(TotalTorque_HwNm_T_f32 / D_TOTALTORQUESF_NM_F32) * k_SComTrqPosPol_Cnt_s08;

		/* Check for Torque NTCs */
		if (SrlComOutput_CheckForTorqueNTC() == TRUE)
		{
			TorqueSensorFault_Cnt_T_lgc = TRUE;
		}
		else
		{
			TorqueSensorFault_Cnt_T_lgc = FALSE;
		}

		if (TRUE == TorqueSensorFault_Cnt_T_lgc)
		{
			IlPutTxLKADrvAppldTrqV(D_INVALID_CNT_U08);
		}
		else
		{
			IlPutTxLKADrvAppldTrqV(D_VALID_CNT_U08);
		}

		if ((TRUE == TorqueSensorFault_Cnt_T_lgc) ||
			(TRUE == VehicleSpeedMissing_Cnt_T_lgc) ||
			(TRUE == VehicleSpeedInvalid_Cnt_T_lgc))
		{
			HndsOffStrWhlDtStV_Cnt_T_u08 = D_INVALID_CNT_U08;
		}
		else
		{
			HndsOffStrWhlDtStV_Cnt_T_u08 = D_VALID_CNT_U08;
		}

		if (D_VALID_CNT_U08 != HndsOffStrWhlDtStV_Cnt_T_u08)
		{
			HndsOffStrWhlDtMd_Cnt_T_u08 = D_FAILED_CNT_U08;
		}
		else if (TRUE == k_LKAMfgEnable_Cnt_lgc)
		{
			HndsOffStrWhlDtMd_Cnt_T_u08 = D_ENABLED_CNT_U08;
		}
		else
		{
			/* This is technically unreachable but was included to be explicit */
			/* We do not transmit this message when LKA is disabled, ergo we will never transmit Hands Off as disabled */
			HndsOffStrWhlDtMd_Cnt_T_u08 = D_DISABLED_CNT_U08;
		}

		if (HOWEstimate_Uls_T_f32 > k_MaxHOWEstimate_Uls_f32)
		{
			HndsOffStrWhlDtSt_Cnt_T_u08 = D_HANDSON_CNT_U08;
		}
		else
		{
			HndsOffStrWhlDtSt_Cnt_T_u08 = D_HANDSOFF_CNT_U08;
		}

		if (F1orF2FaultPresent_Cnt_T_lgc == TRUE)
		{
			LKAState_Cnt_T_u8 = LKA_PermanentlyFailed;
		}

		/* Fill signal buffers with appropriate values. */
		IlPutTxHndsOffStrWhlDtSt(HndsOffStrWhlDtSt_Cnt_T_u08);
		IlPutTxHndsOffStrWhlDtMd(HndsOffStrWhlDtMd_Cnt_T_u08);
		IlPutTxHndsOffStrWhlDtStV(HndsOffStrWhlDtStV_Cnt_T_u08);
		IlPutTxLKATrqOvrlTrqDStat(LKAState_Cnt_T_u8);
		IlPutTxLKAElPwrStTtlTqDlvd((uint16)TotalTorque_Cnt_T_s16);

		IlPutTxLKATrqOvrlDlvdRC(LKATrqOvrlDlvdRC_Cnt_M_u8);
		IlPutTxLKATrqOvrlDltTrqDlvd((uint16)LKATorqueDelivered_Cnt_T_s16);
		IlPutTxLKADrvAppldTrq((uint16)DriverAppliedTorque_Cnt_T_s16);

		/* Update shadow buffers before checksum is calculated - EA3#7541*/
		IlPutTxHndsOffStrWhlDtStGroup();
		IlPutTxLKADrvAppldTrqGroup();

		/* After the buffer has been filled, use it to calculate the checksum. */
		CheckSum_Cnt_T_u16 =
					((uint16)LKA_Steering_Trq_Overlay_Stat_HS._c[0] & 0x3Fu) +
					(uint16)LKA_Steering_Trq_Overlay_Stat_HS._c[1]+
					((uint16)LKA_Steering_Trq_Overlay_Stat_HS._c[2] & 0x7Fu) +
					(uint16)LKA_Steering_Trq_Overlay_Stat_HS._c[3] +
					(((uint16)LKA_Steering_Trq_Overlay_Stat_HS._c[4] & 0x78u) >> 3u) +
					((uint16)LKA_Steering_Trq_Overlay_Stat_HS._c[6] & 0x08u) +
					(uint16)LKADrvAppldTrqGroup.LKADrvAppldTrqGroup.LKADrvAppldTrq_0 +
					(uint16)LKADrvAppldTrqGroup.LKADrvAppldTrqGroup.LKADrvAppldTrq_1 +
					(0x30u);


		IlPutTxLKATrqOvrlStatChksm(CheckSum_Cnt_T_u16);

		/* Increment Rolling counter. */
		LKATrqOvrlDlvdRC_Cnt_M_u8++;
	}
	else
	{
		CanPartOffline(kCanChannel_Channel0, C_SEND_GRP_LKA);
	}

	/* Write the value to the data buffer for signals in 778 message */
	IlPutTxDTCI_DTCTriggered_778(DTCData.DTCTriggered);
	IlPutTxDTCI_DTCSource_778(DTCData.DTCSource);
	IlPutTxDTCI_DTCNumber_778(DTCData.DTCNumber);
	IlPutTxDTCI_DTCFailType_778(DTCData.DTCFailType);
	IlPutTxDTCI_CodeSupported_778(DTCData.DTCCodeSupported);
	IlPutTxDTCI_CurrentStatus_778(DTCData.DTCCurrentStatus);
	IlPutTxDTCI_TstNPsdCdClrdSt_778(DTCData.DTCTstNPsdCdClrdSt);
	IlPutTxDTCI_TstFldCdClrdStat_778(DTCData.DTCTstFldCdClrdStat);
	IlPutTxDTCI_HistStat_778(DTCData.DTCHistStat);
	IlPutTxDTCI_TstNPsdPwrUpSt_778(DTCData.DTCTstNPsdPwrupSt);
	IlPutTxDTCI_TstFldPwrUpSt_778(DTCData.DTCTstFldPwrUpSt);
	IlPutTxDTCI_WrnIndRqdSt_778(DTCData.DTCWrnIndRqdSt);
	IlPutTxDTCI_DTCFaultType_778(DTCData.DTCFaulttype);
	
	IlPutTxDTCInfo_778();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_DiagStsHwPosDis_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_HandwheelVel_HwRadpS_f32(Float *data)
 *   Std_ReturnType Rte_Read_HwVelValid_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SrlComHwPos_HwDeg_f32(Float *data)
 *   Std_ReturnType Rte_Read_SrlComSysPwrMd_Cnt_enum(SysPwrMd *data)
 *   Std_ReturnType Rte_Read_TrimCompEOL_Cnt_lgc(Boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_BusOffCE_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_BusOffHS_Cnt_lgc(Boolean data)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_Per2
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) SrlComHwPos_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) SrlComHwPos_Cnt_T_f32;
	VAR(sint16, AUTOMATIC) SrlComHwPos_Cnt_T_s16;
	VAR(float32, AUTOMATIC) HandwheelVel_HwRadpS_f32;
	VAR(float32, AUTOMATIC) HandwheelVel_HwDegpS_f32;
	VAR(sint16, AUTOMATIC) HandwheelVel_Cnt_s16;
	VAR(boolean, AUTOMATIC) HandwheelVelValid_Cnt_lgc;
	VAR(boolean, AUTOMATIC) StrWhlAngSenCalStat_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) CheckSum_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) TrimCompEOL_Cnt_lgc;
	VAR(uint8, AUTOMATIC) DrvStrIntfrDtcdV_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DrvStrIntfrDetPrtVal_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) ElcPwrStrAvalStatPVal_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) APADrvrInterventionDetected_Cnt_T_lgc;
	VAR(APA_State_enum, AUTOMATIC) APAState_State_T_enum;
	VAR(SysPwrMd, AUTOMATIC) SysPwrMd_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) DiagStsHwPosDis_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) BusOffHS_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) BusOffCE_Cnt_T_lgc;

	(void)Rte_Read_SrlComHwPos_HwDeg_f32(&SrlComHwPos_HwDeg_T_f32);
	(void)Rte_Read_HandwheelVel_HwRadpS_f32(&HandwheelVel_HwRadpS_f32);
	(void)Rte_Read_HwVelValid_Cnt_lgc(&HandwheelVelValid_Cnt_lgc);
	(void)Rte_Read_TrimCompEOL_Cnt_lgc(&TrimCompEOL_Cnt_lgc);
	(void)Rte_Read_DiagStsHwPosDis_Cnt_lgc(&DiagStsHwPosDis_Cnt_T_lgc);
	(void)Rte_Read_SrlComSysPwrMd_Cnt_enum(&SysPwrMd_Cnt_T_enum);

	SrlComHwPos_HwDeg_T_f32 = Limit_m(SrlComHwPos_HwDeg_T_f32, D_STRWHANGLOLMT_ULS_F32, D_STRWHANGHILMT_ULS_F32);
	SrlComHwPos_Cnt_T_f32 = SrlComHwPos_HwDeg_T_f32 / D_STRWHANGSCALE_ULS_F32;
	SrlComHwPos_Cnt_T_s16 = (sint16)SrlComHwPos_Cnt_T_f32;
	SrlComHwPos_Cnt_T_s16 *= k_SComTrqPosPol_Cnt_s08;

	HandwheelVel_HwDegpS_f32 = D_180OVRPI_ULS_F32 * HandwheelVel_HwRadpS_f32;
	HandwheelVel_HwDegpS_f32 = Limit_m(HandwheelVel_HwDegpS_f32, D_STRWHANGGRDLOLMT_ULS_F32, D_STRWHANGGRDHILMT_ULS_F32);
	HandwheelVel_Cnt_s16 = (sint16)HandwheelVel_HwDegpS_f32;
	HandwheelVel_Cnt_s16 *= k_SComTrqPosPol_Cnt_s08;

	/* If angle is valid, set respective validity signals to valid.*/
	if (FALSE == DiagStsHwPosDis_Cnt_T_lgc)
	{
		IlPutTxStrWhAngMsk_0(D_USEDATA_CNT_U08);
		IlPutTxStrWhAngV_0(D_VALID_CNT_U08);

		IlPutTxStrWhAngMsk_1(D_USEDATA_CNT_U08);
		IlPutTxStrWhAngV_1(D_VALID_CNT_U08);
	}
	else /* Angle is invalid, so set respective validity signals to invalid. */
	{
		IlPutTxStrWhAngMsk_0(D_DONTUSEDATA_CNT_U08);
		IlPutTxStrWhAngV_0(D_INVALID_CNT_U08);

		IlPutTxStrWhAngMsk_1(D_DONTUSEDATA_CNT_U08);
		IlPutTxStrWhAngV_1(D_INVALID_CNT_U08);
	}

	/* If handwheel velocity is valid, set respective validity signals to valid.*/
	if (TRUE == HandwheelVelValid_Cnt_lgc)
	{
		IlPutTxStrWhAngGrdMsk_0(D_USEDATA_CNT_U08);
		IlPutTxStrWhAngGrdV_0(D_VALID_CNT_U08);

		IlPutTxStrWhAngGrdMsk_1(D_USEDATA_CNT_U08);
		IlPutTxStrWhAngGrdV_1(D_VALID_CNT_U08);
	}
	else /* Handwheel velocity is invalid, so set respective validity signals to invalid. */
	{
		IlPutTxStrWhAngGrdMsk_0(D_DONTUSEDATA_CNT_U08);
		IlPutTxStrWhAngGrdV_0(D_INVALID_CNT_U08);

		IlPutTxStrWhAngGrdMsk_1(D_DONTUSEDATA_CNT_U08);
		IlPutTxStrWhAngGrdV_1(D_INVALID_CNT_U08);
	}

	if (TRUE == TrimCompEOL_Cnt_lgc)
	{
		StrWhlAngSenCalStat_Cnt_T_u08 = D_CALSTATCALIBRATED_CNT_U08;
	}
	else
	{
		StrWhlAngSenCalStat_Cnt_T_u08 = D_CALSTATUNKNOWN_CNT_U08;
	}
	IlPutTxStrWhlAngSenCalStat_0(StrWhlAngSenCalStat_Cnt_T_u08);
	IlPutTxStrWhlAngSenCalStat_1(StrWhlAngSenCalStat_Cnt_T_u08);

	IlPutTxStWhlAngAliveRollCnt_0(StWhlAngAliveRollCnt_Cnt_M_u08);
	IlPutTxStWhlAngAliveRollCnt_1(StWhlAngAliveRollCnt_Cnt_M_u08);
	StWhlAngAliveRollCnt_Cnt_M_u08++;

	IlPutTxStrWhlAngSenTyp_0(D_SENSORTYPE4_CNT_u08);
	IlPutTxStrWhlAngSenTyp_1(D_SENSORTYPE4_CNT_u08);

	/* Always update the signals on the bus regardless of their validity. */
	IlPutTxStrWhAng_0(SrlComHwPos_Cnt_T_s16); /* PRQA S 4434 */
	IlPutTxStrWhAng_1(SrlComHwPos_Cnt_T_s16); /* PRQA S 4434 */
	IlPutTxStrWhAngGrd_0(HandwheelVel_Cnt_s16); /* PRQA S 4434 */
	IlPutTxStrWhAngGrd_1(HandwheelVel_Cnt_s16); /* PRQA S 4434 */

	/* Update the transmission buffers before the checksum is calculated. */
	IlPutTxStrWhAngGroup_0();
	IlPutTxStrWhAngGrdGroup_0();

	IlPutTxStrWhAngGroup_1();
	IlPutTxStrWhAngGrdGroup_1();

	CheckSum_Cnt_T_u16 = 0u;
	CheckSum_Cnt_T_u16 += PPEI_Steering_Wheel_Angle._c[0];
	CheckSum_Cnt_T_u16 += PPEI_Steering_Wheel_Angle._c[1];
	CheckSum_Cnt_T_u16 += PPEI_Steering_Wheel_Angle._c[2];
	CheckSum_Cnt_T_u16 += PPEI_Steering_Wheel_Angle._c[3];
	CheckSum_Cnt_T_u16 += PPEI_Steering_Wheel_Angle._c[4];
	CheckSum_Cnt_T_u16 += PPEI_Steering_Wheel_Angle._c[5];
	CheckSum_Cnt_T_u16 += ((uint16)PPEI_Steering_Wheel_Angle._c[6] & 0xF8u) >> 3u;
	CheckSum_Cnt_T_u16 += (0x1E5U / 8U);
	IlPutTxStrAngSnsChksm_0(CheckSum_Cnt_T_u16);

	CheckSum_Cnt_T_u16 = 0u;
	CheckSum_Cnt_T_u16 += PPEI_Steering_Wheel_Angle_CE._c[0];
	CheckSum_Cnt_T_u16 += PPEI_Steering_Wheel_Angle_CE._c[1];
	CheckSum_Cnt_T_u16 += PPEI_Steering_Wheel_Angle_CE._c[2];
	CheckSum_Cnt_T_u16 += PPEI_Steering_Wheel_Angle_CE._c[3];
	CheckSum_Cnt_T_u16 += PPEI_Steering_Wheel_Angle_CE._c[4];
	CheckSum_Cnt_T_u16 += PPEI_Steering_Wheel_Angle_CE._c[5];
	CheckSum_Cnt_T_u16 += ((uint16)PPEI_Steering_Wheel_Angle_CE._c[6] & 0xF8u) >> 3u;
	CheckSum_Cnt_T_u16 += (0x1E5U / 8U);
	IlPutTxStrAngSnsChksm_1(CheckSum_Cnt_T_u16);

	/* Electric_Power_Steering_CE (Msg ID 0x335) */
	if (TRUE == k_APAMfgEnable_Cnt_lgc)
	{
		(void)Rte_Read_APADrvrInterventionDetected_Cnt_lgc(&APADrvrInterventionDetected_Cnt_T_lgc);
		(void)Rte_Read_APAState_State_enum(&APAState_State_T_enum);

		/* Check if the message was sent last execution cycle. If so increment the rolling counters.*/
		if (TRUE == Electric_Power_Steering_CE_conf_b)
		{
			DrvStrIntfrDetARC_Cnt_M_u08 = (DrvStrIntfrDetARC_Cnt_M_u08 + 1u) & 0x03u;
			ElcPwrStrAvalStatARC_Cnt_M_u08 = (ElcPwrStrAvalStatARC_Cnt_M_u08 + 1u) & 0x03u;
		}

		/* Check for Torque NTCs */
		if (SrlComOutput_CheckForTorqueNTC() == TRUE)
		{
			DrvStrIntfrDtcdV_Cnt_T_u08 = D_INVALID_CNT_U08;
		}
		else
		{
			DrvStrIntfrDtcdV_Cnt_T_u08 = D_VALID_CNT_U08;
		}

		DrvStrIntfrDetPrtVal_Cnt_T_u08 = (uint8)(APADrvrInterventionDetected_Cnt_T_lgc << 1) + (uint8)DrvStrIntfrDtcdV_Cnt_T_u08;
		DrvStrIntfrDetPrtVal_Cnt_T_u08 += DrvStrIntfrDetARC_Cnt_M_u08;
		DrvStrIntfrDetPrtVal_Cnt_T_u08 = ((uint8)~DrvStrIntfrDetPrtVal_Cnt_T_u08) + 1u;

		ElcPwrStrAvalStatPVal_Cnt_T_u08 = (uint8)APAState_State_T_enum;
		ElcPwrStrAvalStatPVal_Cnt_T_u08 += ElcPwrStrAvalStatARC_Cnt_M_u08;
		ElcPwrStrAvalStatPVal_Cnt_T_u08 = ((uint8)~ElcPwrStrAvalStatPVal_Cnt_T_u08) + 1u;

		IlPutTxElecPwrStrAvalStat(APAState_State_T_enum);
		IlPutTxDrvStrIntfrDtcdV(DrvStrIntfrDtcdV_Cnt_T_u08);
		IlPutTxDrvStrIntfrDtcd(APADrvrInterventionDetected_Cnt_T_lgc);
		IlPutTxDrvStrIntfrDetARC(DrvStrIntfrDetARC_Cnt_M_u08);
		IlPutTxDrvStrIntfrDetPrtVal(DrvStrIntfrDetPrtVal_Cnt_T_u08);
		IlPutTxElcPwrStrAvalStatARC(ElcPwrStrAvalStatARC_Cnt_M_u08);
		IlPutTxElcPwrStrAvalStatPVal(ElcPwrStrAvalStatPVal_Cnt_T_u08);

		IlPutTxDrvStrIntfrDtcdGroup();
	}
	else
	{
		CanPartOffline(kCanChannel_Channel1, C_SEND_GRP_APA);
	}

	T1_AppHandler();
	IlTxTask(kCanChannel_Channel0);
	IlTxTask(kCanChannel_Channel1);

	/* Bus Off handler */
	SrlComOutput_BusOffHandler(SysPwrMd_Cnt_T_enum, &BusOffHS_Cnt_T_lgc, &BusOffCE_Cnt_T_lgc);

	(void)Rte_Write_BusOffHS_Cnt_lgc(BusOffHS_Cnt_T_lgc);
	(void)Rte_Write_BusOffCE_Cnt_lgc(BusOffCE_Cnt_T_lgc);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComOutput_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_DTCTrigSts_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_DTCTrigSts_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMOUTPUT_APPL_CODE) SrlComOutput_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComOutput_Trns1
 *********************************************************************************************************************/
	VAR(uint8, AUTOMATIC) EvntCnt;

	for (EvntCnt = 1U; EvntCnt <= D_NUMOFDEMEVENTS_CNT_U08; EvntCnt++)
	{
		(*(Rte_Pim_DTCTrigSts()))[EvntCnt] = DTCTriggeredFlag_Cnt_M_lgc[EvntCnt];		
	}
	(void)Rte_Call_DTCTrigSts_WriteBlock(NULL_PTR);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SRLCOMOUTPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************
 * Function name: StatusBitTranslation
 * Description: Translates between ISO and GM status bits
 * Returns: GM Status Byte
 * Parameter: ISO Status Byte
 * 
**********************************************************************************/
static FUNC(vuint8, AP_SRLCOMOUTPUT_CODE) ISOToGMStatus(vuint8 statusMask)
{
	VAR(vuint8, AUTOMATIC) BitMod = 0x01U;

	if (0U != (statusMask & D_TESTFAILED_CNT_U8))
	{
		BitMod |= 0x02U;
	}
	if (0U != (statusMask & D_CONFIRMED_CNT_U8))
	{
		BitMod |= 0x10U;
	}
	if (0U != (statusMask & D_WARNINGIND_CNT_U8))
	{
		BitMod |= 0x80U;
	}

	return(BitMod);
}


/**********************************************************************************
 * Function name: SrlComOuput_Reset778ReportedDTCs
 * Description: Reset to FALSE the DTCTriggeredFlag_Cnt_M_lgc variable and 778
 *              control variables. What means that any current DTC will trigger a
 *              778 message again.
 * Returns: NA
 * Parameter: NA
**********************************************************************************/
FUNC(void, AP_SRLCOMOUTPUT_CODE) SrlComOuput_Reset778ReportedDTCs(void)
{
	(void)memset(&DTCTriggeredFlag_Cnt_M_lgc[0], 0, TableSize_m(DTCTriggeredFlag_Cnt_M_lgc));
	CTCEventId_Cnt_M_u8 = D_NUMOFDEMEVENTS_CNT_U08 + 1U;
	CTCEventIdSV_Cnt_M_u8 = 0U;
	CurrentDTCSentThisIC_Cnt_M_lgc = FALSE;
}


/**********************************************************************************
 * Function name: SrlComOuput_BusOffHandlerInit
 * Description: Initialize the BusOff diagnostic strategy
 * Returns: NA
 * Parameter: NA
**********************************************************************************/
STATIC FUNC(void, AP_SRLCOMOUTPUT_CODE) SrlComOuput_BusOffHandlerInit(void)
{
	VAR(uint32, AUTOMATIC) CurrentSysTime_mS_T_u32;

	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&CurrentSysTime_mS_T_u32);
	BusOffFltChannel0RecoverTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
	BusOffFltChannel0DetectionTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
	BusOffFltChannel1RecoverTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
	BusOffFltChannel1DetectionTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
}


/**********************************************************************************
 * Function name: SrlComOutput_BusOffHandler
 * Description: Periodic function to handle the BusOff diagnostic
 * Returns: NA
 * Parameter: SysPwrMd_Cnt_T_enum: Input to ensure busoff NTC is set only in run mode
 *
 *            BusOffHS_Cnt_T_lgc: Output of the BusOff state for the HS channel,
 *            TRUE if BussOff is identified even if the elapsed time to set the
 *            NTC did not.
 *
 *            BusOffCE_Cnt_T_lgc: Output of the BusOff state for the CE channel,
 *            TRUE if BussOff is identified even if the elapsed time to set the
 *            NTC did not.
**********************************************************************************/
STATIC FUNC(void, AP_SRLCOMOUTPUT_CODE) SrlComOutput_BusOffHandler(SysPwrMd SysPwrMd_Cnt_T_enum,
												P2VAR(boolean, AUTOMATIC, AUTOMATIC) BusOffHS_Cnt_T_lgc,
												P2VAR(boolean, AUTOMATIC, AUTOMATIC) BusOffCE_Cnt_T_lgc)
{
	VAR(uint32, AUTOMATIC) CurrentSysTime_mS_T_u32;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;

	/* BusOff fault detection/recovery for Channel 0 */
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&CurrentSysTime_mS_T_u32);

	/* For Channel 0 */
	if (BusOffPresentChannel0_Cnt_M_lgc == TRUE)
	{
		BusOffDiagActiveChannel0_Cnt_M_lgc = TRUE;
		*BusOffHS_Cnt_T_lgc = TRUE;

		/* Reset recovery timers */
		BusOffFltChannel0RecoverTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BusOffFltChannel0DetectionTimer_mS_M_u32, &ElapsedTime_mS_T_u16);

		if ((ElapsedTime_mS_T_u16 >= k_BusOffFaultTimeChannel0_mS_u16) && (SysPwrMd_Cnt_T_enum == Run))
		{
			/* BusOff fault detected */
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BusOffCh1, 0x01U, NTC_STATUS_FAILED);
		}
	}
	else if (BusOffDiagActiveChannel0_Cnt_M_lgc == TRUE)
	{
		*BusOffHS_Cnt_T_lgc = FALSE;
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BusOffFltChannel0RecoverTimer_mS_M_u32, &ElapsedTime_mS_T_u16);

		if (ElapsedTime_mS_T_u16 >= k_BusOffRecoveryTimeChannel0_mS_u16)
		{
			/* BusOff recovered */
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BusOffCh1, 0x01U, NTC_STATUS_PASSED);

			BusOffDiagActiveChannel0_Cnt_M_lgc = FALSE;	/* Clear diag active flag */

			/* Reset fault/recovery timers */
			BusOffFltChannel0RecoverTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
			BusOffFltChannel0DetectionTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
		}
	}
	else
	{
		*BusOffHS_Cnt_T_lgc = FALSE;
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BusOffCh1, 0x01U, NTC_STATUS_PASSED);

		/* Reset fault/recovery timers */
		BusOffFltChannel0RecoverTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
		BusOffFltChannel0DetectionTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
	}

	/* BusOff fault detection/recovery for Channel 1 */
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&CurrentSysTime_mS_T_u32);

	/* For Channel 1 */
	if (BusOffPresentChannel1_Cnt_M_lgc == TRUE)
	{
		BusOffDiagActiveChannel1_Cnt_M_lgc = TRUE;
		*BusOffCE_Cnt_T_lgc = TRUE;

		/* Reset recovery timers */
		BusOffFltChannel1RecoverTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BusOffFltChannel1DetectionTimer_mS_M_u32, &ElapsedTime_mS_T_u16);

		if (ElapsedTime_mS_T_u16 >= k_BusOffFaultTimeChannel1_mS_u16)
		{
			/* BusOff fault detected */
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BusOffCh2, 0x01U, NTC_STATUS_FAILED);
		}
	}
	else if (BusOffDiagActiveChannel1_Cnt_M_lgc == TRUE)
	{
		*BusOffCE_Cnt_T_lgc = FALSE;
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(BusOffFltChannel1RecoverTimer_mS_M_u32, &ElapsedTime_mS_T_u16);

		if (ElapsedTime_mS_T_u16 >= k_BusOffRecoveryTimeChannel1_mS_u16)
		{
			/* BusOff recovered */
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BusOffCh2, 0x01U, NTC_STATUS_PASSED);

			BusOffDiagActiveChannel1_Cnt_M_lgc = FALSE;	/* Clear diag active flag */

			/* Reset fault/recovery timers */
			BusOffFltChannel1RecoverTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
			BusOffFltChannel1DetectionTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
		}
	}
	else
	{
		*BusOffCE_Cnt_T_lgc = FALSE;
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_BusOffCh2, 0x01U, NTC_STATUS_PASSED);

		/* Reset fault/recovery timers */
		BusOffFltChannel1RecoverTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
		BusOffFltChannel1DetectionTimer_mS_M_u32 = CurrentSysTime_mS_T_u32;
	}
}


/**********************************************************************************
 * Function name: Appl_1E5MsgTxAck_HS
 * Description: Callback function for every time the 0x1E5 message is successfully
 *              transmitted in the HS bus.
 * Returns: NA
 * Parameter: txObject: TX object handler
**********************************************************************************/
FUNC(void, AP_SRLCOMOUTPUT_CODE) Appl_1E5MsgTxAck_HS(CanTransmitHandle txObject)
{
	/* Transmit confirmation indicates successful recovery from BusOff */
	BusOffPresentChannel0_Cnt_M_lgc = FALSE;
}


/**********************************************************************************
 * Function name: Appl_1E5MsgTxAck_CE
 * Description: Callback function for every time the 0x1E5 message is successfully
 *              transmitted in the CE bus.
 * Returns: NA
 * Parameter: txObject: TX object handler
**********************************************************************************/
FUNC(void, AP_SRLCOMOUTPUT_CODE) Appl_1E5MsgTxAck_CE(CanTransmitHandle txObject)
{
	/* Transmit confirmation indicates successful recovery from BusOff */
	BusOffPresentChannel1_Cnt_M_lgc = FALSE;
}


/**********************************************************************************
 * Function name: ApplNwmBusoff
 * Description: Callback function for BusOff event
 * Returns: NA
 * Parameter: channel: channel number where the BusOff occurred
**********************************************************************************/
FUNC(void,AP_SRLCOMOUTPUT_CODE) ApplNwmBusoff(CanChannelHandle channel)
{
	if (0U == channel)
	{
		BusOffPresentChannel0_Cnt_M_lgc = TRUE;
	}
	else
	{
		BusOffPresentChannel1_Cnt_M_lgc = TRUE;
	}
}


/**********************************************************************************
 * Function name: ApplNwmBusoffEnd
 * Description: Callback function for BusOffEnd event
 * Returns: NA
 * Parameter: channel: channel number where the BusOffEnd occurred
**********************************************************************************/
FUNC(void,AP_SRLCOMOUTPUT_CODE) ApplNwmBusoffEnd(CanChannelHandle channel)
{
	/* BusOff "wait" has ended - nothing to do here */
}


/**********************************************************************************
 * Function name: SrlComOutput_WarningIndicatorHandler
 * Description: Read the status for the indicator, trigger message 0x148 if the
 *              value changed and return if the lamp must be on or off.
 * Returns: Value to be set to the indicator signal (0 or 1)
 * Parameter: Dem_IndicatorId: Indicator to be read
**********************************************************************************/
STATIC FUNC(uint8, AP_SRLCOMOUTPUT_CODE) SrlComOutput_WarningIndicatorHandler(Dem_IndicatorIdType Dem_IndicatorId)
{
	VAR(uint8, AUTOMATIC) WarningIndStatus_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) WarningIndSignal_Cnt_T_u08 = 0U;

	if (Dem_IndicatorId < (Dem_IndicatorIdType)DEM_NUMBER_OF_INDICATORS)
	{
		/* Update the signal value based on the DEM events */
		(void)Dem_GetIndicatorStatus(Dem_IndicatorId, &WarningIndStatus_Cnt_T_u08);
		WarningIndSignal_Cnt_T_u08 = (WarningIndStatus_Cnt_T_u08 == DEM_INDICATOR_CONTINUOUS)? 1U : 0U;

		/* Trigger message if value changed */
		if (WarningIndSignal_Cnt_T_u08 != PrevWarningIndSignal_Cnt_M_u08[Dem_IndicatorId])
		{
			IlSetEvent(IlTxMsgHndPower_Steering_Information_HS);
		}
		PrevWarningIndSignal_Cnt_M_u08[Dem_IndicatorId] = WarningIndSignal_Cnt_T_u08;
	}

	return WarningIndSignal_Cnt_T_u08;
}


/**********************************************************************************
 * Function name: SrlComOutput_CheckForTorqueNTC
 * Description: Check if any torque NTC is active
 * Returns: TRUE if any torque NTC is active
 * Parameter: None
**********************************************************************************/
STATIC FUNC(boolean, AP_SRLCOMOUTPUT_CODE) SrlComOutput_CheckForTorqueNTC(void)
{
	VAR(boolean, AUTOMATIC) NTCActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) Return_Cnt_T_lgc = FALSE;
	VAR(uint8, AUTOMATIC) Index_Cnt_T_u08;

	for (Index_Cnt_T_u08 = 0U; Index_Cnt_T_u08 < TableSize_m(T_LISTOFTORQUENTC_CNT_U16); Index_Cnt_T_u08++)
	{
		(void)Rte_Call_NxtrDiagMgr_GetNTCActive(T_LISTOFTORQUENTC_CNT_U16[Index_Cnt_T_u08], &NTCActive_Cnt_T_lgc);

		if (NTCActive_Cnt_T_lgc == TRUE)
		{
			Return_Cnt_T_lgc = TRUE;
		}
	}

	return Return_Cnt_T_lgc;
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
