/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_TrqOvlSta.c
 *     Workspace:  C:/SynergyWorkArea/Working/TrqOvlSta/autosar
 *     SW-C Type:  Ap_TrqOvlSta
 *  Generated at:  Tue Mar 22 11:10:18 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_TrqOvlSta>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
 * Copyright 2014 Nexteer
 * Nexteer Confidential
 *
 * Module File Name: Ap_TrqOvlSta.c
 * Module Description: Implementation of CF09
 * Project           : CBD
 * Author            : Selva Sengottaiyan
*****************************************************************************
 * Version Control:
 * Date Created:      Thu Jan 15 14:23:51 2014
 * %version:          9 %
 * %derived_by:       pznywf %
 * %date_modified:    Wed Feb 26 17:51:22 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 01/20/14  1        Selva       Initial version                                                            10959
 * 02/26/14  2        BWL         Remove Type H memory per A6287. Since the FDD has not been updated the     11517
 *                                    change was performed under A6405. 
 * 04/21/14  3        Selva       A6475 fixed. Added absolute value in HwTrqFilt_HwNm_T_f32                  11746
 *								  Corrected the output TrqOscFreq_Hz_f32				
 * 07/16/14  4        SB        Implemented CF-09 GM Torque Overlay State Handler v002						 12181
 * 08/06/14	 5		  SB		Removed Per Instance Memory data											 12248
 * 10/15/14	 6,7	  SB		Implemented CF-09 GM Torque Overlay State Handler v003						 12540
 * 01/20/15  8		  KK		A7535 fixed 																 12777
 * 02/20/15  9        SV		Implemented CF-09 GM Torque Overlay State Handler v004						 EA3#448
 * 03/10/16  10       JK        Implemented CF-09 GM Torque Overlay State Handler v5.0.0                     EA3#4335
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


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_TrqOvlSta.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_TrqOvlSta_Cfg.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "filters.h"
#include "Interpolation.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include <float.h>

/* PRQA S 3218 EOF
* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */

/* MISRA-C:2004 Rule 10.4: This deviation is required because of Nexteer macro library.  Rule suppressed by line at each occurrence. */

#define D_HWAGSERVOCMDMIN_HWDEG_F32 (-1440.0F)
#define D_HWAGSERVOCMDMAX_HWDEG_F32 (1440.0F)
#define D_TRQOSCNFRQMIN_HZ_F32 3.0F
#define D_TRQOSCNFRQMAX_HZ_F32 100.0F
#define D_TRQOSCNMOTAMPMIN_MTRNM_F32 0.0F
#define D_TRQOSCNMOTAMPMAX_MTRNM_F32 0.75F
#define D_LKASTPRMNTFAILD_CNT_U08 3U

#define TRQOVLSTA_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC  VAR(uint8, AUTOMATIC)	TrqOvlSta_LKAPermFault_Cnt_M_u08;
#define TRQOVLSTA_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define TRQOVLSTA_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC	VAR(boolean, AUTOMATIC)	TrqOvlSta_LKAPermFault_Cnt_M_lgc;
STATIC	VAR(boolean, AUTOMATIC)	TrqOvlSta_LKAFault_Cnt_M_lgc;
STATIC	volatile VAR(boolean, AUTOMATIC)	TrqOvlSta_StandstillTime_Cnt_D_lgc;
STATIC	volatile VAR(boolean, AUTOMATIC)	TrqOvlSta_ShiftLevRevTime_Cnt_D_lgc;
STATIC	VAR(boolean, AUTOMATIC)	TrqOvlSta_ReadytoPulse_Cnt_M_lgc;
STATIC	VAR(boolean, AUTOMATIC)	TrqOvlSta_IgnCntrUpd_Cnt_M_lgc;
STATIC	VAR(boolean, AUTOMATIC)	TrqOvlSta_LoaStChk_Cnt_M_lgc;
STATIC	VAR(boolean, AUTOMATIC)	TrqOvlSta_LoaStLimdOrSwBasdMtgtn_Cnt_M_lgc;
#define TRQOVLSTA_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define TRQOVLSTA_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC	VAR(float32, AUTOMATIC)	TrqOvlSta_Haptictime_Sec_M_f32;
STATIC	VAR(float32, AUTOMATIC)	TrqOvlSta_ElapsedShiftLevRevTime_Sec_M_f32;
STATIC	VAR(float32, AUTOMATIC)	TrqOvlSta_ElapsedAPAMaxHwTrqTime_Sec_M_f32;
STATIC	VAR(float32, AUTOMATIC)	TrqOvlSta_ElapsedStandstillTime_Sec_M_f32;
STATIC	VAR(float32, AUTOMATIC)	TrqOvlSta_PosSrvoHwAngle_HwDeg_M_f32;
STATIC	VAR(uint32, AUTOMATIC)	TrqOvlSta_TqOscCycRefTmr_mS_M_u32;
STATIC	VAR(uint32, AUTOMATIC)	TrqOvlSta_LkaIntvTmr_mS_M_u32;
STATIC	VAR(uint32, AUTOMATIC)	TrqOvlSta_HaptcStTranActvToWaitTmr_mS_M_u32;
STATIC	VAR(uint32, AUTOMATIC)	TrqOvlSta_TranHaptcWaitToApaStActvTmr_mS_M_u32;
STATIC	VAR(uint32, AUTOMATIC)	TrqOvlSta_LoaMtgtnHaptcFbStrtOnTmr_mS_M_u32;
#define TRQOVLSTA_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define TRQOVLSTA_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC	VAR(uint16, AUTOMATIC)	TrqOvlSta_GMLoaIgnCntr_Cnt_M_u16;
#define TRQOVLSTA_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define TRQOVLSTA_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC	VAR(LPF32KSV_Str, AUTOMATIC)	TrqOvlSta_HwTorqueSV_HwNm_M_Str;
STATIC	VAR(LPF32KSV_Str, AUTOMATIC)	TrqOvlSta_LKAHwTorqueSV_HwNm_M_Str;
STATIC	VAR(LPF32KSV_Str, AUTOMATIC)	TrqOvlSta_HwTorqueOscnSV_HwNm_M_Str;
STATIC	VAR(APA_State_enum, AUTOMATIC)	TrqOvlSta_APAState_State_M_enum;
STATIC	VAR(APA_State_enum, AUTOMATIC)	TrqOvlSta_PrevAPAState_State_M_enum;
STATIC	VAR(Haptic_State_enum, AUTOMATIC)	TrqOvlSta_HapticState_State_M_enum;	/* REQ: CF09 #146 I : Default state is 'Inactive'. Defined in RTE */
STATIC	VAR(LKA_State_enum, AUTOMATIC)	TrqOvlSta_LKAState_State_M_enum;	/* REQ: CF09 #129 I : Default state is 'Inactive'. Defined in RTE */
STATIC	VAR(ESC_State_enum, AUTOMATIC)	TrqOvlSta_ESCState_State_M_enum;	/* REQ: CF09 #130 I : Default state is 'Inactive'. Defined in RTE */
STATIC	VAR(Haptic_State_enum, AUTOMATIC)	TrqOvlSta_PrevHapticState_State_M_enum;
#define TRQOVLSTA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* Local Functions */
static FUNC(boolean, TRQOVLSTA_APPL_CODE) HaptcEnaDurnElpdChk(boolean HapticRequest_Cnt_T_lgc);
static FUNC(boolean, TRQOVLSTA_APPL_CODE) ShiftLvrRvsTmrElpdChk(boolean ShiftLeverIsInReverse_Cnt_T_lgc);
static FUNC(boolean, TRQOVLSTA_APPL_CODE) VehStandStillTmrElpdChk(float32 MaxSecureVehicleSpeed_Kph_T_f32);
static FUNC(boolean, TRQOVLSTA_APPL_CODE) HwTrqFildChk(float32 HwTorque_HwNm_T_f32);
static FUNC(boolean, TRQOVLSTA_APPL_CODE) ApaIntv(float32 HwTorque_HwNm_T_f32);
static FUNC(boolean, TRQOVLSTA_APPL_CODE) LkaIntv(float32 HwTorque_HwNm_T_f32);
static FUNC(void, TRQOVLSTA_APPL_CODE) LkaPrmntFlt(boolean LKAFault_Cnt_T_lgc);
static FUNC(void, TRQOVLSTA_APPL_CODE) InctIgnCntrOnce(void);
static FUNC(boolean, TRQOVLSTA_APPL_CODE) HaptcStTranActvToWaitFlg(void);
static FUNC(boolean, TRQOVLSTA_APPL_CODE) TranHaptcWaitToApaStActvFlg(void);
static FUNC(boolean, TRQOVLSTA_APPL_CODE) PosServo(boolean PosTrajEnable_Cnt_T_lgc,
													float32 PosTrajHwAngle_HwDeg_T_f32,
													float32 SWARTrgtAng_HwDeg_T_f32);
static FUNC(boolean, TRQOVLSTA_APPL_CODE) TrqOscnFunc(boolean HwTrqOscnFiltWithinIntl_Cnt_T_lgc,
													float32 VehSpd_Kph_T_f32,
													P2VAR(float32, AUTOMATIC, TRQOVLSTA_APPL_CODE) TrqOscAmp_MtrNm_T_f32,
													P2VAR(float32, AUTOMATIC, TRQOVLSTA_APPL_CODE) TrqOscFreq_Hz_T_f32);
static FUNC(void, TRQOVLSTA_APPL_CODE) EscStTran(boolean ESCFault_Cnt_T_lgc,
												boolean ESCRequest_Cnt_T_lgc,
												boolean ESCIsLimited_Cnt_T_lgc,
												LOA_State_enum LOAState_Cnt_T_enum,
												float32 MaxSecureVehicleSpeed_Kph_T_f32);
static FUNC(void, TRQOVLSTA_APPL_CODE) LkaStTran(boolean LKAFault_Cnt_T_lgc,
												boolean LKARequest_Cnt_T_lgc,
												boolean LKAInhibit_Cnt_T_lgc,
												boolean LKAIntervention_Cnt_T_lgc,
												LOA_State_enum LOAState_Cnt_T_enum,
												float32 MinSecureVehicleSpeed_Kph_T_f32,
												float32 MaxSecureVehicleSpeed_Kph_T_f32);

static FUNC(void, TRQOVLSTA_APPL_CODE) HaptcStTran(boolean StandstillTime_Cnt_T_lgc,
													boolean APARequest_Cnt_T_lgc,
													boolean ShiftLevRevTime_Cnt_T_lgc,
													boolean HapticRequest_Cnt_T_lgc,
													boolean HaptcStTranActvToWaitFlg_Cnt_T_lgc,
													boolean TranHaptcWaitToApaStActvFlg_Cnt_T_lgc);
static FUNC(void, TRQOVLSTA_APPL_CODE) MfgDisableStTran(boolean GMOSH_APAMfgEnable_Cnt_T_lgc,
														boolean GMOSH_LKAMfgEnable_Cnt_T_lgc,
														boolean GMOSH_ESCMfgEnable_Cnt_T_lgc);
static FUNC(void, TRQOVLSTA_APPL_CODE) ApaActvStTran(boolean APANonRecoverableFaults_Cnt_T_lgc,
													boolean APARecoverableFaults_Cnt_T_lgc,
													boolean HapticRequest_Cnt_T_lgc,
													boolean APARequest_Cnt_T_lgc,
													boolean APAIntervention_Cnt_T_lgc,
													LOA_State_enum LOAState_Cnt_T_enum,
													float32 MaxSecureVehicleSpeed_Kph_T_f32);

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
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * APA_State_enum: Enumeration of integer in interval [0...4] with enumerators
 *   APA_TempInhibit (0u)
 *   APA_AvailCntrl (1u)
 *   APA_Active (2u)
 *   APA_PermanentlyFailed (3u)
 *   APA_ManufacturingDisable (4u)
 * ESC_State_enum: Enumeration of integer in interval [0...4] with enumerators
 *   ESC_Inactive (0u)
 *   ESC_Active (1u)
 *   ESC_TemporarilyLimited (2u)
 *   ESC_PermanentlyFailed (3u)
 *   ESC_ManufacturingDisable (4u)
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
 *   FLTINJ_DIGHWTRQSENT_T1FAULT (41u)
 *   FLTINJ_DIGHWTRQSENT_T2FAULT (42u)
 *   FLTINJ_TRQOSC_PREFINALCOMMAND (43u)
 *   FLTINJ_GCCDIAG_HWTRQ (46u)
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
 * Haptic_State_enum: Enumeration of integer in interval [0...2] with enumerators
 *   Haptic_Inactive (0u)
 *   Haptic_Active (1u)
 *   Haptic_Waiting (2u)
 * LKA_State_enum: Enumeration of integer in interval [0...4] with enumerators
 *   LKA_Inactive (0u)
 *   LKA_Active (1u)
 *   LKA_TemporarilyLimited (2u)
 *   LKA_PermanentlyFailed (3u)
 *   LKA_ManufacturingDisable (4u)
 * LOA_State_enum: Enumeration of integer in interval [0...5] with enumerators
 *   LOAST_NORM (0u)
 *   LOAST_REDCD (1u)
 *   LOAST_SWBASDMTGTN (2u)
 *   LOAST_FADEOUT (3u)
 *   LOAST_CTRLDSHTDWNREQD (4u)
 *   LOAST_RPDSHTDWNREQD (5u)
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
 *
 * Array Types:
 * ============
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_TRQOVLFREQINIT_HZ_F32 = 3
 * Float: D_ZERO_ULS_F32 = 0
 * LOA_State_enum: D_LOASTATEINIT_CNT_ENUM = 0u
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   UInt16 *Rte_Pim_GmLoaIgnCntr(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_TRQOVLSTA_APPL_CODE
#include "MemMap.h"	/* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqOvlSta_Init
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
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_TrqOvlStaBlk_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_TrqOvlStaBlk_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQOVLSTA_APPL_CODE) TrqOvlSta_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqOvlSta_Init
 *********************************************************************************************************************/
	 VAR(NvM_RequestResultType, AUTOMATIC) NvMBlkStatus_Cnt_T_u08;

	/* Filter initializations */
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_APAHwTrqLPFKn_Hz_f32, (float32)D_2MS_SEC_F32, &TrqOvlSta_HwTorqueSV_HwNm_M_Str);		/* REQ: CF09 #79 I */
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_GMOSH_LKAHwTrqLPFKn_Hz_f32, (float32)D_2MS_SEC_F32, &TrqOvlSta_LKAHwTorqueSV_HwNm_M_Str);	/* REQ: CF09 #215 I */
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_GMOSH_HwTrqOscnLPFKn_Hz_f32,(float32)D_2MS_SEC_F32, &TrqOvlSta_HwTorqueOscnSV_HwNm_M_Str);
	
	/* Initialzing the timers */
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrqOvlSta_HaptcStTranActvToWaitTmr_mS_M_u32);
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrqOvlSta_TranHaptcWaitToApaStActvTmr_mS_M_u32);
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrqOvlSta_LoaMtgtnHaptcFbStrtOnTmr_mS_M_u32);
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrqOvlSta_TqOscCycRefTmr_mS_M_u32);
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrqOvlSta_LkaIntvTmr_mS_M_u32);
	
	/* Check NVM error status */
	(void)Rte_Call_TrqOvlStaBlk_GetErrorStatus(&NvMBlkStatus_Cnt_T_u08);
	if(NVM_REQ_OK != NvMBlkStatus_Cnt_T_u08)
	{
		*Rte_Pim_GmLoaIgnCntr() = 0U;
	}
	
	TrqOvlSta_GMLoaIgnCntr_Cnt_M_u16 = *Rte_Pim_GmLoaIgnCntr();		/* REQ: CF09 #246 I */		/* REQ: CF09 #248 I */
	
	/* REQ: CF09 #249 I */
	 /* Check if ignition counter has reached the threshold, set the appropriate NTC */
	if(TrqOvlSta_GMLoaIgnCntr_Cnt_M_u16 >= k_GMOSH_LoaStIgnCntrThd_Cnt_u16)						/* REQ: CF09 #236 I */
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LimpHomeIgnitionCounter, 0x00U, NTC_STATUS_FAILED);
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_LimpHomeIgnitionCounter, 0x00U, NTC_STATUS_PASSED);
	}
	/* ENDREQ: CF09 #249 */
	
	/* REQ: CF09 #250 I */
	if(TrqOvlSta_GMLoaIgnCntr_Cnt_M_u16 > 0U)
	{
		*Rte_Pim_GmLoaIgnCntr() -= 1U;
		(void)Rte_Call_TrqOvlStaBlk_SetRamBlockStatus(TRUE);
	}
	else
	{
		*Rte_Pim_GmLoaIgnCntr() = 0U;
	}
	/* ENDREQ: CF09 #250 */
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqOvlSta_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF, WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_TrqOvlSta_Per1_APANonRecoverableFaults_Cnt_lgc(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_APARecoverableFaults_Cnt_lgc(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_APARequest_Cnt_lgc(void)
 *   Float Rte_IRead_TrqOvlSta_Per1_CCWPosition_HwDeg_f32(void)
 *   Float Rte_IRead_TrqOvlSta_Per1_CWPosition_HwDeg_f32(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_ESCFault_Cnt_lgc(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_ESCIsLimited_Cnt_lgc(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_ESCRequest_Cnt_lgc(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_GMOSH_APAMfgEnable_Cnt_lgc(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_GMOSH_ESCMfgEnable_Cnt_lgc(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_GMOSH_LKAMfgEnable_Cnt_lgc(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_HapticRequest_Cnt_lgc(void)
 *   Float Rte_IRead_TrqOvlSta_Per1_HwTorque_HwNm_f32(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_LKAFault_Cnt_lgc(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_LKAInhibit_Cnt_lgc(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_LKARequest_Cnt_lgc(void)
 *   LOA_State_enum Rte_IRead_TrqOvlSta_Per1_LOASt_State_enum(void)
 *   Float Rte_IRead_TrqOvlSta_Per1_MaxSecureVehicleSpeed_Kph_f32(void)
 *   Float Rte_IRead_TrqOvlSta_Per1_MinSecureVehicleSpeed_Kph_f32(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_PosTrajEnable_Cnt_lgc(void)
 *   Float Rte_IRead_TrqOvlSta_Per1_PosTrajHwAngle_HwDeg_f32(void)
 *   Float Rte_IRead_TrqOvlSta_Per1_SWARTrgtAngRequest_HwDeg_f32(void)
 *   Boolean Rte_IRead_TrqOvlSta_Per1_ShiftLeverIsInReverse_Cnt_lgc(void)
 *   Float Rte_IRead_TrqOvlSta_Per1_VehSpd_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TrqOvlSta_Per1_APADrvrInterventionDetected_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TrqOvlSta_Per1_APADrvrInterventionDetected_Cnt_lgc(void)
 *   void Rte_IWrite_TrqOvlSta_Per1_APAState_State_enum(APA_State_enum data)
 *   APA_State_enum *Rte_IWriteRef_TrqOvlSta_Per1_APAState_State_enum(void)
 *   void Rte_IWrite_TrqOvlSta_Per1_ESCState_State_enum(ESC_State_enum data)
 *   ESC_State_enum *Rte_IWriteRef_TrqOvlSta_Per1_ESCState_State_enum(void)
 *   void Rte_IWrite_TrqOvlSta_Per1_GMOSHOscillateState_State_enum(Haptic_State_enum data)
 *   Haptic_State_enum *Rte_IWriteRef_TrqOvlSta_Per1_GMOSHOscillateState_State_enum(void)
 *   void Rte_IWrite_TrqOvlSta_Per1_LKAState_State_enum(LKA_State_enum data)
 *   LKA_State_enum *Rte_IWriteRef_TrqOvlSta_Per1_LKAState_State_enum(void)
 *   void Rte_IWrite_TrqOvlSta_Per1_LkaDrvrIntvDetd_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TrqOvlSta_Per1_LkaDrvrIntvDetd_Cnt_lgc(void)
 *   void Rte_IWrite_TrqOvlSta_Per1_PosServEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TrqOvlSta_Per1_PosServEnable_Cnt_lgc(void)
 *   void Rte_IWrite_TrqOvlSta_Per1_PosSrvoHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_TrqOvlSta_Per1_PosSrvoHwAngle_HwDeg_f32(void)
 *   void Rte_IWrite_TrqOvlSta_Per1_TrqOscAmp_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_TrqOvlSta_Per1_TrqOscAmp_MtrNm_f32(void)
 *   void Rte_IWrite_TrqOvlSta_Per1_TrqOscEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TrqOvlSta_Per1_TrqOscEnable_Cnt_lgc(void)
 *   void Rte_IWrite_TrqOvlSta_Per1_TrqOscFreq_Hz_f32(Float data)
 *   Float *Rte_IWriteRef_TrqOvlSta_Per1_TrqOscFreq_Hz_f32(void)
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
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_TrqOvlStaBlk_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQOVLSTA_APPL_CODE) TrqOvlSta_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqOvlSta_Per1
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) MaxSecureVehicleSpeed_Kph_T_f32;
	VAR(float32, AUTOMATIC) MinSecureVehicleSpeed_Kph_T_f32;
	VAR(boolean, AUTOMATIC) APARequest_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) APARecoverableFaults_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) APANonRecoverableFaults_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HapticRequest_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ShiftLeverIsInReverse_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(boolean, AUTOMATIC) LKARequest_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) LKAFault_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) LKAInhibit_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ESCRequest_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ESCFault_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ESCIsLimited_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) PosTrajHwAngle_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) SWARTrgtAng_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) SWARTrgtAngRequest_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC) PosTrajEnable_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) CWPosition_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) CCWPosition_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC) GMOSH_APAMfgEnable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) GMOSH_LKAMfgEnable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) GMOSH_ESCMfgEnable_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	VAR(LOA_State_enum, AUTOMATIC)  LOAState_Cnt_T_enum;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SysState_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) ShiftLevRevTime_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) StandstillTime_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HapticReqDurExceeded_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) APAIntervention_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TrqOscEnable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PosEnable_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) TrqOscFreq_Hz_T_f32;
	VAR(float32, AUTOMATIC) TrqOscAmp_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) PosSrvoHwAngle_HwDeg_T_f32;
	VAR(boolean, AUTOMATIC) LKAIntervention_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HaptcStTranActvToWaitFlg_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TranHaptcWaitToApaStActvFlg_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) HwTrqOscnFiltWithinIntl_Cnt_T_lgc;
	

#if (STD_ON == BC_TRQOVLSTA_FAULTINJECTIONPOINT)
	VAR(float32, AUTOMATIC) LKARequest_Cnt_T_f32;
#endif

	(void)Rte_Call_TrqOvlSta_Per1_CP0_CheckpointReached();
	/*** Read the inputs***/
	
	MaxSecureVehicleSpeed_Kph_T_f32	=	Rte_IRead_TrqOvlSta_Per1_MaxSecureVehicleSpeed_Kph_f32();/* REQ: CF09 #41 I */
	MinSecureVehicleSpeed_Kph_T_f32	=	Rte_IRead_TrqOvlSta_Per1_MinSecureVehicleSpeed_Kph_f32();/* REQ: CF09 #27 I */
	APARequest_Cnt_T_lgc			=	Rte_IRead_TrqOvlSta_Per1_APARequest_Cnt_lgc( );			/* REQ: CF09 #42 I */
	APANonRecoverableFaults_Cnt_T_lgc	= 	Rte_IRead_TrqOvlSta_Per1_APANonRecoverableFaults_Cnt_lgc( );/* REQ: CF09 #47 I */
	APARecoverableFaults_Cnt_T_lgc	=	Rte_IRead_TrqOvlSta_Per1_APARecoverableFaults_Cnt_lgc( );		/* REQ: CF09 #46 I */
	HapticRequest_Cnt_T_lgc			=	Rte_IRead_TrqOvlSta_Per1_HapticRequest_Cnt_lgc( );		/* REQ: CF09 #43 I */
	ShiftLeverIsInReverse_Cnt_T_lgc =	Rte_IRead_TrqOvlSta_Per1_ShiftLeverIsInReverse_Cnt_lgc( );/* REQ: CF09 #44 I */
	HwTorque_HwNm_T_f32				=	Rte_IRead_TrqOvlSta_Per1_HwTorque_HwNm_f32( );			/* REQ: CF09 #45 I */
	LKAFault_Cnt_T_lgc				=	Rte_IRead_TrqOvlSta_Per1_LKAFault_Cnt_lgc( );			/* REQ: CF09 #49 I */
	LKAInhibit_Cnt_T_lgc			=	Rte_IRead_TrqOvlSta_Per1_LKAInhibit_Cnt_lgc( );			/* REQ: CF09 #50 I */
	ESCRequest_Cnt_T_lgc			=	Rte_IRead_TrqOvlSta_Per1_ESCRequest_Cnt_lgc( );			/* REQ: CF09 #51 I */
	ESCFault_Cnt_T_lgc				=	Rte_IRead_TrqOvlSta_Per1_ESCFault_Cnt_lgc( );			/* REQ: CF09 #52 I */
	ESCIsLimited_Cnt_T_lgc			=	Rte_IRead_TrqOvlSta_Per1_ESCIsLimited_Cnt_lgc();		/* REQ: CF09 #53 I */
	PosTrajHwAngle_HwDeg_T_f32		=	Rte_IRead_TrqOvlSta_Per1_PosTrajHwAngle_HwDeg_f32();	/* REQ: CF09 #61 I */
	SWARTrgtAngRequest_HwDeg_T_f32	=	Rte_IRead_TrqOvlSta_Per1_SWARTrgtAngRequest_HwDeg_f32();/* REQ: CF09 #59 I */
	PosTrajEnable_Cnt_T_lgc			=	Rte_IRead_TrqOvlSta_Per1_PosTrajEnable_Cnt_lgc();		/* REQ: CF09 #60 I */
	CWPosition_HwDeg_T_f32			=	Rte_IRead_TrqOvlSta_Per1_CWPosition_HwDeg_f32();		/* REQ: CF09 #57 I */
	CCWPosition_HwDeg_T_f32			=	Rte_IRead_TrqOvlSta_Per1_CCWPosition_HwDeg_f32();		/* REQ: CF09 #58 I */
	GMOSH_APAMfgEnable_Cnt_T_lgc	=	Rte_IRead_TrqOvlSta_Per1_GMOSH_APAMfgEnable_Cnt_lgc();	/* REQ: CF09 #54 I */
	GMOSH_LKAMfgEnable_Cnt_T_lgc	=	Rte_IRead_TrqOvlSta_Per1_GMOSH_LKAMfgEnable_Cnt_lgc();	/* REQ: CF09 #55 I */
	GMOSH_ESCMfgEnable_Cnt_T_lgc	=	Rte_IRead_TrqOvlSta_Per1_GMOSH_ESCMfgEnable_Cnt_lgc();	/* REQ: CF09 #56 I */
	VehSpd_Kph_T_f32				=	Rte_IRead_TrqOvlSta_Per1_VehSpd_Kph_f32();	/* REQ: CF09 #223 I */
	LOAState_Cnt_T_enum				=	Rte_IRead_TrqOvlSta_Per1_LOASt_State_enum();	/* REQ: CF09 #222 I */
	SysState_Cnt_T_enum				=	Rte_Mode_SystemState_Mode();	/* REQ: CF09 #224 I */
	
	#if (STD_ON == BC_TRQOVLSTA_FAULTINJECTIONPOINT)
		(void)Rte_Call_FaultInjection_SCom_FltInjection(&LKARequest_Cnt_T_f32,FLTINJ_TRQOVLSTA_LKAFAULT);
		if (LKARequest_Cnt_T_f32 > D_ZERO_ULS_F32)
			{
				LKARequest_Cnt_T_lgc = TRUE;
			}
		else
			{
				LKARequest_Cnt_T_lgc = FALSE;
			}
	#else
	      LKARequest_Cnt_T_lgc            = 	Rte_IRead_TrqOvlSta_Per1_LKARequest_Cnt_lgc( );	/* REQ: CF09 #48 I */
	#endif
	
	/* HwHaptcEna */
	HapticReqDurExceeded_Cnt_T_lgc = HaptcEnaDurnElpdChk(HapticRequest_Cnt_T_lgc);
	
	/* Shift Lever Reverse */
	ShiftLevRevTime_Cnt_T_lgc = ShiftLvrRvsTmrElpdChk(ShiftLeverIsInReverse_Cnt_T_lgc);
	TrqOvlSta_ShiftLevRevTime_Cnt_D_lgc = ShiftLevRevTime_Cnt_T_lgc;
	
	/* Vehicle Stand Still Timer */
	StandstillTime_Cnt_T_lgc = VehStandStillTmrElpdChk(MaxSecureVehicleSpeed_Kph_T_f32);
	TrqOvlSta_StandstillTime_Cnt_D_lgc = StandstillTime_Cnt_T_lgc;
	
	/* REQ: CF09 #254 I */
	/* HwTqFildWithinIntl */
    HwTrqOscnFiltWithinIntl_Cnt_T_lgc = HwTrqFildChk(HwTorque_HwNm_T_f32);
	/* ENDREQ: CF09 #254   */
	
	/* APA Intervention */
	APAIntervention_Cnt_T_lgc = ApaIntv(HwTorque_HwNm_T_f32);
	
	/* LKA Intervention */
	LKAIntervention_Cnt_T_lgc = LkaIntv(HwTorque_HwNm_T_f32);
	
	/* LKA Permanent Fault */
	LkaPrmntFlt(LKAFault_Cnt_T_lgc);
	
	TrqOvlSta_LKAFault_Cnt_M_lgc = LKAFault_Cnt_T_lgc;
	
	/* REQ: CF09 #251 I */
	/* REQ: CF09 #252 I */
	/* REQ: CF09 #253 I */
	/* LoaStLimdOrSwBasdMtgtn */
	if((LOAState_Cnt_T_enum == LOAST_REDCD) || (LOAState_Cnt_T_enum == LOAST_SWBASDMTGTN))
	{
		TrqOvlSta_LoaStLimdOrSwBasdMtgtn_Cnt_M_lgc = TRUE;
	}
	else
	{
		TrqOvlSta_LoaStLimdOrSwBasdMtgtn_Cnt_M_lgc = FALSE;
	}
	/* ENDREQ: CF09 #251 I*/
	/* ENDREQ: CF09 #252 I*/
	/* ENDREQ: CF09 #253 I*/

	/* Increment Ignition Counter once */
	if(TrqOvlSta_LoaStLimdOrSwBasdMtgtn_Cnt_M_lgc == TRUE)
	{
		InctIgnCntrOnce();
	}

	/* HaptcStTransActvToWaitFlg */
	HaptcStTranActvToWaitFlg_Cnt_T_lgc = HaptcStTranActvToWaitFlg();
	
	/* TransHaptcWaitToAPAStActvFlg */
	TranHaptcWaitToApaStActvFlg_Cnt_T_lgc = TranHaptcWaitToApaStActvFlg();
	
	/* Manufacturing Disabling State for APA,LKA,ESC */
	MfgDisableStTran(GMOSH_APAMfgEnable_Cnt_T_lgc,GMOSH_LKAMfgEnable_Cnt_T_lgc,GMOSH_ESCMfgEnable_Cnt_T_lgc);

	/*** Start of APA State ***/
	switch (TrqOvlSta_APAState_State_M_enum)
	{
		case(APA_TempInhibit):	/* REQ: CF09 #133 I */
			if((APANonRecoverableFaults_Cnt_T_lgc == TRUE)||(LOAState_Cnt_T_enum != LOAST_NORM))	/* REQ: CF09 #160 I */
			{
				TrqOvlSta_APAState_State_M_enum = APA_PermanentlyFailed;
			}
			/* REQ: CF09 #86 I */
			/* REQ: CF09 #134 I */
			else if((MaxSecureVehicleSpeed_Kph_T_f32 <= k_APAMaxVehSpd_Kph_f32) && (APARequest_Cnt_T_lgc == FALSE) && (HapticRequest_Cnt_T_lgc == FALSE) && (APARecoverableFaults_Cnt_T_lgc == FALSE))
			{
				TrqOvlSta_APAState_State_M_enum = APA_AvailCntrl;
			}
			else
			{
				/*Do nothing*/
			}
			break;

		case(APA_AvailCntrl):	/* REQ: CF09 #133 I */
			/* REQ: CF09 #144 I */
			/* REQ: CF09 #201 I */
			if((APANonRecoverableFaults_Cnt_T_lgc == TRUE)||(LOAState_Cnt_T_enum != LOAST_NORM))
			{
				TrqOvlSta_APAState_State_M_enum = APA_PermanentlyFailed;
				TrqOvlSta_HapticState_State_M_enum = Haptic_Inactive;
			}
			/* REQ: CF09 #86 I */
			/* REQ: CF09 #140 I */
			/* REQ: CF09 #154 I */
			else if ((MaxSecureVehicleSpeed_Kph_T_f32 > k_APAMaxVehSpd_Kph_f32) ||(APARecoverableFaults_Cnt_T_lgc == TRUE)||((HapticRequest_Cnt_T_lgc == TRUE)&&(HapticReqDurExceeded_Cnt_T_lgc == TRUE)))
			{
				TrqOvlSta_APAState_State_M_enum = APA_TempInhibit;
				TrqOvlSta_HapticState_State_M_enum = Haptic_Inactive;
			}	
			else
			{
				/* Haptic State Transition */
				/* REQ: CF09 #85 I */
				/* REQ: CF09 #146 I */
				HaptcStTran(StandstillTime_Cnt_T_lgc,APARequest_Cnt_T_lgc,
							ShiftLevRevTime_Cnt_T_lgc,HapticRequest_Cnt_T_lgc,
							HaptcStTranActvToWaitFlg_Cnt_T_lgc,
							TranHaptcWaitToApaStActvFlg_Cnt_T_lgc);
			}
			break;

		case(APA_Active):	/* REQ: CF09 #133 I */
				ApaActvStTran(APANonRecoverableFaults_Cnt_T_lgc,
							APARecoverableFaults_Cnt_T_lgc,
							HapticRequest_Cnt_T_lgc,
							APARequest_Cnt_T_lgc,
							APAIntervention_Cnt_T_lgc,
							LOAState_Cnt_T_enum,
							MaxSecureVehicleSpeed_Kph_T_f32);
			break;

		case(APA_PermanentlyFailed):	/* REQ: CF09 #133 I */
			break;
		/* REQ: CF09 #119 I */
		/* REQ: CF09 #133 I */
		case(APA_ManufacturingDisable):
			break;

		default:
			break;
	}
	/*** End of APA State ***/
	
	TrqOvlSta_PrevHapticState_State_M_enum     = TrqOvlSta_HapticState_State_M_enum;
	TrqOvlSta_PrevAPAState_State_M_enum        = TrqOvlSta_APAState_State_M_enum;

	/*** Start of LKA State ***/
	LkaStTran(LKAFault_Cnt_T_lgc,LKARequest_Cnt_T_lgc,LKAInhibit_Cnt_T_lgc,
			LKAIntervention_Cnt_T_lgc,LOAState_Cnt_T_enum,
			MinSecureVehicleSpeed_Kph_T_f32,
			MaxSecureVehicleSpeed_Kph_T_f32);
	/*** End of LKA State ***/

	/*** Start of ESC State ***/
	EscStTran(ESCFault_Cnt_T_lgc,ESCRequest_Cnt_T_lgc,
				ESCIsLimited_Cnt_T_lgc,LOAState_Cnt_T_enum,
				MaxSecureVehicleSpeed_Kph_T_f32);
	/*** End of ESC State ***/

	/* SWAR Limiter */
	/* REQ: CF09 #131 I */
	SWARTrgtAng_HwDeg_T_f32	= Limit_m(SWARTrgtAngRequest_HwDeg_T_f32, (CCWPosition_HwDeg_T_f32 + k_SWARLimiter_HwDeg_f32), (CWPosition_HwDeg_T_f32 - k_SWARLimiter_HwDeg_f32));		/* REQ: CF09 #84 I */
	/* ENDREQ: CF09 #131 */
	
	/* PosServ */
	/* REQ: CF09 #132 I */
	PosEnable_Cnt_T_lgc = PosServo(PosTrajEnable_Cnt_T_lgc,                     
									PosTrajHwAngle_HwDeg_T_f32,
									SWARTrgtAng_HwDeg_T_f32);
	PosSrvoHwAngle_HwDeg_T_f32 = Limit_m(TrqOvlSta_PosSrvoHwAngle_HwDeg_M_f32,D_HWAGSERVOCMDMIN_HWDEG_F32,D_HWAGSERVOCMDMAX_HWDEG_F32);
	/* ENDREQ: CF09 #132 */

	if(SysState_Cnt_T_enum == RTE_MODE_StaMd_Mode_OPERATE)     /* REQ: CF09 #251 I */
	{
		/* SysStOperate */
		TrqOscEnable_Cnt_T_lgc = TrqOscnFunc(HwTrqOscnFiltWithinIntl_Cnt_T_lgc,VehSpd_Kph_T_f32,&TrqOscAmp_MtrNm_T_f32,&TrqOscFreq_Hz_T_f32);
	}
	else
	{
		/* SysStNotOperate */
		TrqOscEnable_Cnt_T_lgc = FALSE;
		TrqOscAmp_MtrNm_T_f32 = 0.0F;
		TrqOscFreq_Hz_T_f32  = D_TRQOSCNFRQMIN_HZ_F32;
	}

	TrqOscAmp_MtrNm_T_f32 = Limit_m(TrqOscAmp_MtrNm_T_f32,D_TRQOSCNMOTAMPMIN_MTRNM_F32,D_TRQOSCNMOTAMPMAX_MTRNM_F32);
	TrqOscFreq_Hz_T_f32   = Limit_m(TrqOscFreq_Hz_T_f32,D_TRQOSCNFRQMIN_HZ_F32,D_TRQOSCNFRQMAX_HZ_F32);

	/* Write outputs */
	(void)Rte_IWrite_TrqOvlSta_Per1_APAState_State_enum(TrqOvlSta_APAState_State_M_enum );				/* REQ: CF09 #28 I */
	(void)Rte_IWrite_TrqOvlSta_Per1_APADrvrInterventionDetected_Cnt_lgc(APAIntervention_Cnt_T_lgc );	/* REQ: CF09 #63 I */
	(void)Rte_IWrite_TrqOvlSta_Per1_LkaDrvrIntvDetd_Cnt_lgc(LKAIntervention_Cnt_T_lgc);					/* REQ: CF09 #217 I */
	(void)Rte_IWrite_TrqOvlSta_Per1_LKAState_State_enum(TrqOvlSta_LKAState_State_M_enum);				/* REQ: CF09 #62 I */
	(void)Rte_IWrite_TrqOvlSta_Per1_ESCState_State_enum(TrqOvlSta_ESCState_State_M_enum);				/* REQ: CF09 #64 I */
	(void)Rte_IWrite_TrqOvlSta_Per1_TrqOscEnable_Cnt_lgc(TrqOscEnable_Cnt_T_lgc);						/* REQ: CF09 #65 I */
	(void)Rte_IWrite_TrqOvlSta_Per1_TrqOscAmp_MtrNm_f32(TrqOscAmp_MtrNm_T_f32 );						/* REQ: CF09 #66 I */
	(void)Rte_IWrite_TrqOvlSta_Per1_TrqOscFreq_Hz_f32(TrqOscFreq_Hz_T_f32);								/* REQ: CF09 #67 I */
	(void)Rte_IWrite_TrqOvlSta_Per1_GMOSHOscillateState_State_enum(TrqOvlSta_HapticState_State_M_enum );/* REQ: CF09 #68 I */
	(void)Rte_IWrite_TrqOvlSta_Per1_PosServEnable_Cnt_lgc(PosEnable_Cnt_T_lgc );						/* REQ: CF09 #70 I */
	(void)Rte_IWrite_TrqOvlSta_Per1_PosSrvoHwAngle_HwDeg_f32(PosSrvoHwAngle_HwDeg_T_f32 );				/* REQ: CF09 #69 I */

	(void)Rte_Call_TrqOvlSta_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqOvlSta_SCom_GetGmLoaIgnCntr
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetGmLoaIgnCntr> of PortPrototype <TrqOvlSta_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TrqOvlSta_SCom_GetGmLoaIgnCntr(UInt16 *GmLoaIgnCntr_Cnt_u16)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQOVLSTA_APPL_CODE) TrqOvlSta_SCom_GetGmLoaIgnCntr(P2VAR(UInt16, AUTOMATIC, RTE_AP_TRQOVLSTA_APPL_VAR) GmLoaIgnCntr_Cnt_u16)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqOvlSta_SCom_GetGmLoaIgnCntr
 *********************************************************************************************************************/
 
	*GmLoaIgnCntr_Cnt_u16 = *Rte_Pim_GmLoaIgnCntr();	/* REQ: CF09 #247 I */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqOvlSta_SCom_SetGmLoaIgnCntr
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetGmLoaIgnCntr> of PortPrototype <TrqOvlSta_SCom>
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
 *   Std_ReturnType Rte_Call_TrqOvlStaBlk_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TrqOvlSta_SCom_SetGmLoaIgnCntr(UInt16 GmLoaIgnCntr_Cnt_u16)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQOVLSTA_APPL_CODE) TrqOvlSta_SCom_SetGmLoaIgnCntr(UInt16 GmLoaIgnCntr_Cnt_u16)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqOvlSta_SCom_SetGmLoaIgnCntr
 *********************************************************************************************************************/

	*Rte_Pim_GmLoaIgnCntr() = GmLoaIgnCntr_Cnt_u16;		/* REQ: CF09 #247 I */
	(void)Rte_Call_TrqOvlStaBlk_SetRamBlockStatus(TRUE);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_TRQOVLSTA_APPL_CODE
#include "MemMap.h"	/* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*******************************************************************************
* Name          :   HaptcEnaDurnElpdChk
* Description   :   "Timer for HwHaptcEna" block implementation.                 
* Inputs        :   HapticRequest_Cnt_T_lgc
* Outputs       :   HapticReqDurExceeded_Cnt_T_lgc
* Usage Notes   :
*****************************************************************************/
static FUNC(boolean, TRQOVLSTA_APPL_CODE) HaptcEnaDurnElpdChk(boolean HapticRequest_Cnt_T_lgc)
{
	VAR(boolean, AUTOMATIC) HapticReqDurExceeded_Cnt_T_lgc;

	if(HapticRequest_Cnt_T_lgc == TRUE)
	{
		if(TrqOvlSta_Haptictime_Sec_M_f32 >= (k_MaxHapticReqTime_Sec_f32))
		{
			HapticReqDurExceeded_Cnt_T_lgc = TRUE;
		}
		else
		{
			TrqOvlSta_Haptictime_Sec_M_f32 += D_2MS_SEC_F32  ;
			HapticReqDurExceeded_Cnt_T_lgc = FALSE;
		}
	}
	else
	{
		TrqOvlSta_Haptictime_Sec_M_f32 = D_ZERO_ULS_F32;
		HapticReqDurExceeded_Cnt_T_lgc = FALSE;
	}

	return HapticReqDurExceeded_Cnt_T_lgc;
}
/*******************************************************************************
* Name          :   ShiftLvrRvsTmrElpdChk
* Description   :   "Timer for ShiftLvrRvs" block implementation.                 
* Inputs        :   ShiftLeverIsInReverse_Cnt_T_lgc                    
* Outputs       :   ShiftLevRevTime_Cnt_T_lgc
* Usage Notes   :
*****************************************************************************/
static FUNC(boolean, TRQOVLSTA_APPL_CODE) ShiftLvrRvsTmrElpdChk(boolean ShiftLeverIsInReverse_Cnt_T_lgc)
{
	VAR(boolean, AUTOMATIC) ShiftLevRevTime_Cnt_T_lgc;

	if(ShiftLeverIsInReverse_Cnt_T_lgc == TRUE)
	{
		if(TrqOvlSta_ElapsedShiftLevRevTime_Sec_M_f32 > (k_ShiftLevRevTime_Sec_f32))	/* REQ: CF09 #93 I */
		{	
			ShiftLevRevTime_Cnt_T_lgc = TRUE;
		}
		else
		{
			TrqOvlSta_ElapsedShiftLevRevTime_Sec_M_f32 += D_2MS_SEC_F32;
			ShiftLevRevTime_Cnt_T_lgc = FALSE;
		}
	}
	else
	{
		TrqOvlSta_ElapsedShiftLevRevTime_Sec_M_f32 = D_ZERO_ULS_F32;
		ShiftLevRevTime_Cnt_T_lgc = FALSE;
	}

	return ShiftLevRevTime_Cnt_T_lgc;
}
/*******************************************************************************
* Name          :   VehStandStillTmrElpdChk
* Description   :   "Timer for VehStandStill" block implementation.                 
* Inputs        :   MaxSecureVehicleSpeed_Kph_T_f32                    
* Outputs       :   StandstillTime_Cnt_T_lgc
* Usage Notes   :
*****************************************************************************/
static FUNC(boolean, TRQOVLSTA_APPL_CODE) VehStandStillTmrElpdChk(float32 MaxSecureVehicleSpeed_Kph_T_f32)
{
	VAR(boolean, AUTOMATIC) StandstillTime_Cnt_T_lgc;

	if(MaxSecureVehicleSpeed_Kph_T_f32 <= k_StandstillThresh_Kph_f32)	/* REQ: CF09 #77 I */
	{
		if(TrqOvlSta_ElapsedStandstillTime_Sec_M_f32 >= k_StandstillTime_Sec_f32)	/* REQ: CF09 #78 I */
		{
			StandstillTime_Cnt_T_lgc = TRUE;
		}
		else
		{
			TrqOvlSta_ElapsedStandstillTime_Sec_M_f32+=D_2MS_SEC_F32;
			StandstillTime_Cnt_T_lgc = FALSE;
		}
	}
	else
	{
		TrqOvlSta_ElapsedStandstillTime_Sec_M_f32=D_ZERO_ULS_F32;
		StandstillTime_Cnt_T_lgc = FALSE;
	}

	return StandstillTime_Cnt_T_lgc;
}
/*******************************************************************************
* Name          :   HwTrqFildChk
* Description   :   "HwTrqFildIntlChk" block implementation.                 
* Inputs        :   HwTorque_HwNm_T_f32    
* Outputs       :   HwTrqOscnFiltWithinIntl_Cnt_T_lgc
* Usage Notes   :
*****************************************************************************/
static FUNC(boolean, TRQOVLSTA_APPL_CODE) HwTrqFildChk(float32 HwTorque_HwNm_T_f32)
{
	VAR(float32, AUTOMATIC) AbsHwTrqOscnFilt_HwNm_T_f32;
	VAR(boolean, AUTOMATIC) HwTrqOscnFiltWithinIntl_Cnt_T_lgc;

	AbsHwTrqOscnFilt_HwNm_T_f32 = Abs_f32_m(LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &TrqOvlSta_HwTorqueOscnSV_HwNm_M_Str));
	
	if((AbsHwTrqOscnFilt_HwNm_T_f32 >= k_GMOSH_LoaMtgtnHaptcFbTqMin_HwNm_f32) && (AbsHwTrqOscnFilt_HwNm_T_f32 <= k_GMOSH_LoaMtgtnHaptcFbTqMax_HwNm_f32))
	{
		HwTrqOscnFiltWithinIntl_Cnt_T_lgc = TRUE;
	}
	else
	{
		HwTrqOscnFiltWithinIntl_Cnt_T_lgc = FALSE;
	}

	return HwTrqOscnFiltWithinIntl_Cnt_T_lgc;
}
/*******************************************************************************
* Name          :   ApaIntv
* Description   :   "ApaIntv" block implementation.                 
* Inputs        :   HwTorque_HwNm_T_f32                    
* Outputs       :   APAIntervention_Cnt_T_lgc
* Usage Notes   :
*****************************************************************************/
static FUNC(boolean, TRQOVLSTA_APPL_CODE) ApaIntv(float32 HwTorque_HwNm_T_f32)
{
	VAR(float32, AUTOMATIC) AbsHwTrqFilt_HwNm_T_f32;
	VAR(boolean, AUTOMATIC) APAIntervention_Cnt_T_lgc;

	if (TrqOvlSta_HapticState_State_M_enum != Haptic_Inactive)
	{
	    AbsHwTrqFilt_HwNm_T_f32 = D_ZERO_ULS_F32;
	}
	else
	{
		AbsHwTrqFilt_HwNm_T_f32 = Abs_f32_m(LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &TrqOvlSta_HwTorqueSV_HwNm_M_Str));
	}
	
	if(AbsHwTrqFilt_HwNm_T_f32 >= k_APAMaxHwTrq_HwNm_f32)		/* REQ: CF09 #80 I */
	{
		if(TrqOvlSta_ElapsedAPAMaxHwTrqTime_Sec_M_f32 >= k_APAMaxHwTrqTime_Sec_f32)		/* REQ: CF09 #81 I */
		{
			APAIntervention_Cnt_T_lgc = TRUE;
		}
		else
		{
			TrqOvlSta_ElapsedAPAMaxHwTrqTime_Sec_M_f32 += D_2MS_SEC_F32;
			APAIntervention_Cnt_T_lgc = FALSE;
		}
	}
	else
	{
		TrqOvlSta_ElapsedAPAMaxHwTrqTime_Sec_M_f32 = D_ZERO_ULS_F32;
		APAIntervention_Cnt_T_lgc = FALSE;
	}

	return APAIntervention_Cnt_T_lgc;
}
/*******************************************************************************
* Name          :   LkaIntv
* Description   :   "LKAIntv" block implementation.                 
* Inputs        :   HwTorque_HwNm_T_f32                    
* Outputs       :   LKAIntervention_Cnt_T_lgc
* Usage Notes   :
*****************************************************************************/
static FUNC(boolean, TRQOVLSTA_APPL_CODE) LkaIntv(float32 HwTorque_HwNm_T_f32)
{
	VAR(float32, AUTOMATIC) AbsHwTrqFilt_HwNm_T_f32;
	VAR(boolean, AUTOMATIC) LKAIntervention_Cnt_T_lgc;
	VAR(uint32, AUTOMATIC) Elapsedtime_mS_T_u32;

	AbsHwTrqFilt_HwNm_T_f32 = Abs_f32_m(LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &TrqOvlSta_LKAHwTorqueSV_HwNm_M_Str));

	if(AbsHwTrqFilt_HwNm_T_f32 >= k_GMOSH_LKAMaxHwTrq_HwNm_f32)		/* REQ: CF09 #210 I */
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TrqOvlSta_LkaIntvTmr_mS_M_u32,&Elapsedtime_mS_T_u32);
		
		if(Elapsedtime_mS_T_u32 >= k_GMOSH_LKAMaxHwTrqTime_mS_u32)	/* REQ: CF09 #211 I */
		{
			LKAIntervention_Cnt_T_lgc = TRUE;
		}
		else
		{
			LKAIntervention_Cnt_T_lgc = FALSE;
		}
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrqOvlSta_LkaIntvTmr_mS_M_u32);
		LKAIntervention_Cnt_T_lgc = FALSE;
	}

	return LKAIntervention_Cnt_T_lgc;
}
/*******************************************************************************
* Name          :   LkaPrmntFlt
* Description   :   "Inct LkaFltCntr By One" block implementation + immediately
*                   proceeding logic                 
* Inputs        :   LKAFault_Cnt_T_lgc    
* Outputs       :   NA
* Usage Notes   :
*****************************************************************************/
static FUNC(void, TRQOVLSTA_APPL_CODE) LkaPrmntFlt(boolean LKAFault_Cnt_T_lgc)
{
	if ((LKAFault_Cnt_T_lgc == TRUE) && (TrqOvlSta_LKAPermFault_Cnt_M_lgc == FALSE) && (TrqOvlSta_LKAFault_Cnt_M_lgc == FALSE))
	{
		TrqOvlSta_LKAPermFault_Cnt_M_u08 ++;
		/* REQ: CF09 #173 I */
		if (TrqOvlSta_LKAPermFault_Cnt_M_u08 >= D_LKASTPRMNTFAILD_CNT_U08)
		{
			TrqOvlSta_LKAPermFault_Cnt_M_lgc = TRUE;
		}
		/* ENDREQ: CF09 #173 */
	}
}
/*******************************************************************************
* Name          :   InctIgnCntrOnce
* Description   :   "Inct Ign Cntr Once" block implementation.                 
* Inputs        :       
* Outputs       :   
* Usage Notes   :
*****************************************************************************/
static FUNC(void, TRQOVLSTA_APPL_CODE) InctIgnCntrOnce(void)
{
	if(TrqOvlSta_IgnCntrUpd_Cnt_M_lgc == FALSE)
	{
		*Rte_Pim_GmLoaIgnCntr() = TrqOvlSta_GMLoaIgnCntr_Cnt_M_u16 + 1U;
		(void)Rte_Call_TrqOvlStaBlk_SetRamBlockStatus(TRUE);
		TrqOvlSta_IgnCntrUpd_Cnt_M_lgc = TRUE;
	}
}
/*******************************************************************************
* Name          :   HaptcStTranActvToWaitFlg
* Description   :   "HaptcStTranActvToWaitFlg" block implementation.                 
* Inputs        :       
* Outputs       :   HaptcStTranActvToWaitFlg_Cnt_T_lgc
* Usage Notes   :
*****************************************************************************/
static FUNC(boolean, TRQOVLSTA_APPL_CODE) HaptcStTranActvToWaitFlg(void)
{
	VAR(boolean, AUTOMATIC) HaptcStTranActvToWaitFlg_Cnt_T_lgc;
	VAR(uint32, AUTOMATIC) Elapsedtime_mS_T_u32;

	if((TrqOvlSta_PrevHapticState_State_M_enum == Haptic_Active) && (TrqOvlSta_PrevAPAState_State_M_enum == APA_AvailCntrl))
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TrqOvlSta_HaptcStTranActvToWaitTmr_mS_M_u32,&Elapsedtime_mS_T_u32);
		
		if(Elapsedtime_mS_T_u32 >= k_GMOSH_HapticDuration_mS_u32)		/* REQ: CF09 #88 I */
		{
			HaptcStTranActvToWaitFlg_Cnt_T_lgc = TRUE;
		}
		else
		{
			HaptcStTranActvToWaitFlg_Cnt_T_lgc = FALSE;
		}
	}
	else
	{
		HaptcStTranActvToWaitFlg_Cnt_T_lgc = FALSE;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrqOvlSta_HaptcStTranActvToWaitTmr_mS_M_u32);
	}

	return HaptcStTranActvToWaitFlg_Cnt_T_lgc;
}
/*******************************************************************************
* Name          :   TranHaptcWaitToApaStActvFlg
* Description   :   "TranHaptcWaitToApaStActvFlg" block implementation.
* Inputs        :
* Outputs       :   TranHaptcWaitToApaStActvFlg_Cnt_T_lgc
* Usage Notes   :
*****************************************************************************/
static FUNC(boolean, TRQOVLSTA_APPL_CODE) TranHaptcWaitToApaStActvFlg(void)
{
	VAR(boolean, AUTOMATIC) TranHaptcWaitToApaStActvFlg_Cnt_T_lgc;
	VAR(uint32, AUTOMATIC) Elapsedtime_mS_T_u32;

	if((TrqOvlSta_PrevHapticState_State_M_enum == Haptic_Waiting) && (TrqOvlSta_PrevAPAState_State_M_enum == APA_AvailCntrl))
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TrqOvlSta_TranHaptcWaitToApaStActvTmr_mS_M_u32,&Elapsedtime_mS_T_u32);

		if(Elapsedtime_mS_T_u32 >= k_GMOSH_HapticReactTime_mS_u32)	/* REQ: CF09 #89 I */
		{
			TranHaptcWaitToApaStActvFlg_Cnt_T_lgc = TRUE;
		}
		else
		{
			TranHaptcWaitToApaStActvFlg_Cnt_T_lgc = FALSE;
		}
	}
	else
	{
		TranHaptcWaitToApaStActvFlg_Cnt_T_lgc = FALSE;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrqOvlSta_TranHaptcWaitToApaStActvTmr_mS_M_u32);
	}

	return TranHaptcWaitToApaStActvFlg_Cnt_T_lgc;
}
/***************************************************************************************
* Name          :   PosServo
* Description   :   "PosServ" block implementation.                 
* Inputs        :   PosTrajEnable_Cnt_T_lgc,HwAgTraj_HwDeg_T_f32,HwAgTarLimd_HwDeg_T_f32
* Outputs       :   PosEnable_Cnt_T_lgc
* Usage Notes   :
****************************************************************************************/
static FUNC(boolean, TRQOVLSTA_APPL_CODE) PosServo(boolean PosTrajEnable_Cnt_T_lgc,
													float32 PosTrajHwAngle_HwDeg_T_f32,
													float32 SWARTrgtAng_HwDeg_T_f32)
{
	VAR(boolean, AUTOMATIC) PosEnable_Cnt_T_lgc;

	if((TrqOvlSta_APAState_State_M_enum == APA_Active) && (PosTrajEnable_Cnt_T_lgc == TRUE ))
	{
		PosEnable_Cnt_T_lgc = FALSE;
	}
	else if((TrqOvlSta_APAState_State_M_enum != APA_Active) && (PosTrajEnable_Cnt_T_lgc == TRUE ))
	{
		PosEnable_Cnt_T_lgc = TRUE;
		TrqOvlSta_PosSrvoHwAngle_HwDeg_M_f32 = PosTrajHwAngle_HwDeg_T_f32;
	}
	else if((TrqOvlSta_APAState_State_M_enum == APA_Active) && (PosTrajEnable_Cnt_T_lgc == FALSE ))
	{
		PosEnable_Cnt_T_lgc = TRUE;
		TrqOvlSta_PosSrvoHwAngle_HwDeg_M_f32 = SWARTrgtAng_HwDeg_T_f32;
	}
	else
	{
		PosEnable_Cnt_T_lgc = FALSE;
	}
	
	return PosEnable_Cnt_T_lgc;
}
/***********************************************************************************************
* Name          :   TrqOscnFunc
* Description   :   "SysStOperate" and "SysStNotOperate" block implementation.                 
* Inputs        :   HwTrqOscnFiltWithinIntl_Cnt_T_lgc,VehSpd_Kph_T_f32,*TrqOscAmp_MtrNm_T_f32,
*                   *TrqOscFreq_Hz_T_f32    
* Outputs       :   TrqOscEnable_Cnt_T_lgc
* Usage Notes   :
*************************************************************************************************/
static FUNC(boolean, TRQOVLSTA_APPL_CODE) TrqOscnFunc(boolean HwTrqOscnFiltWithinIntl_Cnt_T_lgc,
													float32 VehSpd_Kph_T_f32,
													P2VAR(float32, AUTOMATIC, TRQOVLSTA_APPL_CODE) TrqOscAmp_MtrNm_T_f32,
													P2VAR(float32, AUTOMATIC, TRQOVLSTA_APPL_CODE) TrqOscFreq_Hz_T_f32)
{
	VAR(boolean, AUTOMATIC) TrqOscEnable_Cnt_T_lgc;
	VAR(uint32, AUTOMATIC) Elapsedtime_mS_T_u32;
	VAR(uint16, AUTOMATIC) VehSpd_Kph_T_u10p6;
	VAR(boolean, AUTOMATIC) VehSpdWithinIntl_Cnt_T_lgc = FALSE;

	if(TrqOvlSta_LoaStChk_Cnt_M_lgc == FALSE)		/* REQ: CF09 #251 I */
	{
		/* REQ: CF09 #251 I */
		/* At start-up check*/
		if((TrqOvlSta_GMLoaIgnCntr_Cnt_M_u16 < k_GMOSH_LoaStIgnCntrThd_Cnt_u16) && ( TrqOvlSta_LoaStLimdOrSwBasdMtgtn_Cnt_M_lgc == TRUE))
		{
			/* Enable haptic feedback for a cal amount of time */
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TrqOvlSta_LoaMtgtnHaptcFbStrtOnTmr_mS_M_u32,&Elapsedtime_mS_T_u32);
			if(Elapsedtime_mS_T_u32 >= k_GMOSH_LoaMtgtnHaptcFbStrtOnTi_mS_u32)		/* REQ: CF09 #227 I */
			{
				TrqOvlSta_LoaStChk_Cnt_M_lgc = TRUE;
			}
			TrqOscEnable_Cnt_T_lgc = TRUE;
			*TrqOscAmp_MtrNm_T_f32 = k_GMOSH_LoaMtgtnStrtHaptcAmp_MtrNm_f32;		/* REQ: CF09 #233 I */
			*TrqOscFreq_Hz_T_f32  = k_GMOSH_LoaMtgtnHaptcFrq_Hz_f32;				/* REQ: CF09 #232 I */
		}
		else
		{
			/* Disable haptic feedback */
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrqOvlSta_LoaMtgtnHaptcFbStrtOnTmr_mS_M_u32);
			TrqOvlSta_LoaStChk_Cnt_M_lgc = TRUE;
			TrqOscEnable_Cnt_T_lgc = FALSE;
			*TrqOscFreq_Hz_T_f32  = D_TRQOSCNFRQMIN_HZ_F32;
			*TrqOscAmp_MtrNm_T_f32 = 0.0F;
		}
		/* ENDREQ: CF09 #251 */
	}
	else
	{
		 /* After start-up check */
		 /* APA State available and Haptic State Active */
		if((TrqOvlSta_APAState_State_M_enum == APA_AvailCntrl) && (TrqOvlSta_HapticState_State_M_enum == Haptic_Active))
		{
			TrqOscEnable_Cnt_T_lgc = TRUE;
			*TrqOscAmp_MtrNm_T_f32 = k_HapticAmplitude_MtrNm_f32;	/* ENDREQ: CF09 #82 */
			*TrqOscFreq_Hz_T_f32  = k_HapticFreq_Hz_f32;			/* ENDREQ: CF09 #83 */
		}
		/* APA State Not Available */
		else if(TrqOvlSta_APAState_State_M_enum != APA_AvailCntrl)
		{
			/* REQ: CF09 #255 I */
			/* Vehicle Speed within interval  */
			if((VehSpd_Kph_T_f32 >= k_GMOSH_LoaMtgtnHaptcFbVehSpdMin_Kph_f32)
				&&(VehSpd_Kph_T_f32 <= k_GMOSH_LoaMtgtnHaptcFbVehSpdMax_Kph_f32))
			{
				VehSpdWithinIntl_Cnt_T_lgc = TRUE;
			}
			if((TrqOvlSta_GMLoaIgnCntr_Cnt_M_u16 < k_GMOSH_LoaStIgnCntrThd_Cnt_u16)
				&&(HwTrqOscnFiltWithinIntl_Cnt_T_lgc == TRUE)
				&&(VehSpdWithinIntl_Cnt_T_lgc == TRUE)
				&&(TrqOvlSta_LoaStLimdOrSwBasdMtgtn_Cnt_M_lgc == TRUE))
			{
				(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TrqOvlSta_TqOscCycRefTmr_mS_M_u32,&Elapsedtime_mS_T_u32);

				if(Elapsedtime_mS_T_u32 <= (k_GMOSH_LoaMtgtnHaptcFbOffTi_mS_u32 + k_GMOSH_LoaMtgtnHaptcFbOnTi_mS_u32))		/* REQ: CF09 #225 I */
				{
					(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrqOvlSta_TqOscCycRefTmr_mS_M_u32);
				}
				if(Elapsedtime_mS_T_u32 >= k_GMOSH_LoaMtgtnHaptcFbOnTi_mS_u32)		/* REQ: CF09 #226 I */
				{
					TrqOscEnable_Cnt_T_lgc = FALSE;
				}
				else
				{
					TrqOscEnable_Cnt_T_lgc = TRUE;
				}
			}
			/* ENDREQ: CF09 #255 */
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrqOvlSta_TqOscCycRefTmr_mS_M_u32);
				TrqOscEnable_Cnt_T_lgc = FALSE;
			}

			if(TrqOscEnable_Cnt_T_lgc == TRUE)
			{
				VehSpd_Kph_T_u10p6 = FPM_FloatToFixed_m(VehSpd_Kph_T_f32, u10p6_T);                                              /* PRQA S 4395 */
				*TrqOscAmp_MtrNm_T_f32 = FPM_FixedToFloat_m(IntplVarXY_u16_u16Xu16Y_Cnt(t_GMOSH_LoaMtgtnVehSpdX_Kph_u10p6,
																			t_GMOSH_LoaMtgtnTqOscnAmpY_MtrNm_u2p14,
																			TableSize_m(t_GMOSH_LoaMtgtnVehSpdX_Kph_u10p6),
																			VehSpd_Kph_T_u10p6 ),u2p14_T);
				*TrqOscFreq_Hz_T_f32 = k_GMOSH_LoaMtgtnHaptcFrq_Hz_f32;		/* REQ: CF09 #232 I */
			}
			else
			{
				*TrqOscAmp_MtrNm_T_f32 = 0.0F;
				*TrqOscFreq_Hz_T_f32  = D_TRQOSCNFRQMIN_HZ_F32;
			}
		}
		/* REQ: CF09 #251 I */
		else
		{
			TrqOscEnable_Cnt_T_lgc = FALSE;
			*TrqOscAmp_MtrNm_T_f32 = 0.0F;
			*TrqOscFreq_Hz_T_f32  = D_TRQOSCNFRQMIN_HZ_F32;
		}
		/* ENDREQ: CF09 #251 */
	}

	return TrqOscEnable_Cnt_T_lgc;
}
/***********************************************************************************************
* Name          :   EscStTran
* Description   :   Implementation of all ESC state transitions              
* Inputs        :   ESCFault_Cnt_T_lgc,ESCRequest_Cnt_T_lgc,ESCIsLimited_Cnt_T_lgc,
*                   LOAState_Cnt_T_enum,MaxSecureVehicleSpeed_Kph_T_f32   
* Outputs       :   
* Usage Notes   :
*************************************************************************************************/
static FUNC(void, TRQOVLSTA_APPL_CODE) EscStTran(boolean ESCFault_Cnt_T_lgc,
												boolean ESCRequest_Cnt_T_lgc,
												boolean ESCIsLimited_Cnt_T_lgc,
												LOA_State_enum LOAState_Cnt_T_enum,
												float32 MaxSecureVehicleSpeed_Kph_T_f32)
{
	switch (TrqOvlSta_ESCState_State_M_enum)
	{
		case (ESC_Inactive):
		    if ((ESCFault_Cnt_T_lgc == TRUE)||(LOAState_Cnt_T_enum != LOAST_NORM))		/* REQ: CF09 #155 I */
			{
				TrqOvlSta_ESCState_State_M_enum = ESC_PermanentlyFailed;
			}
		    /* REQ: CF09 #94 I */
		    /* REQ: CF09 #161 I */
		    else if((ESCRequest_Cnt_T_lgc == TRUE) && (MaxSecureVehicleSpeed_Kph_T_f32 <= k_ESCMaxVehSpd_Kph_f32))
		    {
		    	TrqOvlSta_ESCState_State_M_enum = ESC_Active;
		    }
		    else
		    {
		    	/* do nothing*/
		    }
			break;

		case (ESC_Active):
			if((ESCFault_Cnt_T_lgc == TRUE )||(LOAState_Cnt_T_enum != LOAST_NORM))	/* REQ: CF09 #166 I */
			{
				TrqOvlSta_ESCState_State_M_enum = ESC_PermanentlyFailed;
			}
			/* REQ: CF09 #94 I */
			/* REQ: CF09 #163 I */
			else if ((ESCRequest_Cnt_T_lgc == FALSE) || (MaxSecureVehicleSpeed_Kph_T_f32 > k_ESCMaxVehSpd_Kph_f32))
			{
				TrqOvlSta_ESCState_State_M_enum = ESC_Inactive;
			}
			else if (ESCIsLimited_Cnt_T_lgc == TRUE)	/* REQ: CF09 #165 I */
			{
				TrqOvlSta_ESCState_State_M_enum = ESC_TemporarilyLimited;
			}
			else
			{
				/* do nothing */
			}
			break;

		case (ESC_TemporarilyLimited):
			if (ESCRequest_Cnt_T_lgc == FALSE)	/* REQ: CF09 #165 I */
			{
				TrqOvlSta_ESCState_State_M_enum = ESC_Inactive;
			}
			else if((ESCFault_Cnt_T_lgc == TRUE)||(LOAState_Cnt_T_enum != LOAST_NORM))	/* REQ: CF09 #169 I */
			{
				TrqOvlSta_ESCState_State_M_enum = ESC_PermanentlyFailed;
			}
			else if(ESCIsLimited_Cnt_T_lgc == FALSE)	/* REQ: CF09 #171 I */
			{
				TrqOvlSta_ESCState_State_M_enum = ESC_Active;
			}
			else
			{
				/* do nothing */
			}
			break;

		case (ESC_PermanentlyFailed):
			if(((ESCRequest_Cnt_T_lgc == FALSE) && (ESCFault_Cnt_T_lgc == FALSE)) ||(LOAState_Cnt_T_enum != LOAST_NORM))		/* REQ: CF09 #170 I */
			{
				TrqOvlSta_ESCState_State_M_enum = ESC_Inactive;
			}
			else
			{
				/* do nothing */
			}
			break;

		case ( ESC_ManufacturingDisable):	/* REQ: CF09 #130 I */
			break;

		default:
			break;
	} 

}
/***********************************************************************************************
* Name          :   LkaStTran
* Description   :   Implementation of all LKA state transitions              
* Inputs        :   LKAFault_Cnt_T_lgc,LKARequest_Cnt_T_lgc,LKAInhibit_Cnt_T_lgc,
*                   LKAIntervention_Cnt_T_lgc,LOAState_Cnt_T_enum 
*                   MinSecureVehicleSpeed_Kph_T_f32,MaxSecureVehicleSpeed_Kph_T_f32
* Outputs       :   
* Usage Notes   :
*************************************************************************************************/
static FUNC(void, TRQOVLSTA_APPL_CODE) LkaStTran(boolean LKAFault_Cnt_T_lgc,
												boolean LKARequest_Cnt_T_lgc,
												boolean LKAInhibit_Cnt_T_lgc,
												boolean LKAIntervention_Cnt_T_lgc,
												LOA_State_enum LOAState_Cnt_T_enum,
												float32 MinSecureVehicleSpeed_Kph_T_f32,
												float32 MaxSecureVehicleSpeed_Kph_T_f32)
{
	switch (TrqOvlSta_LKAState_State_M_enum)
	{
		case (LKA_Inactive):
			if((TrqOvlSta_LKAPermFault_Cnt_M_lgc == TRUE)||(LOAState_Cnt_T_enum != LOAST_NORM))	/* REQ: CF09 #172 I */
			{
				TrqOvlSta_LKAState_State_M_enum = LKA_PermanentlyFailed;
			}
			else if ((MinSecureVehicleSpeed_Kph_T_f32 < k_LKAMinVehSpd_Kph_f32) || (MaxSecureVehicleSpeed_Kph_T_f32 > k_LKAMaxVehSpd_Kph_f32))
			{
				TrqOvlSta_LKAState_State_M_enum = LKA_Inactive;
			}
			/* REQ: CF09 #175 I */
			else if((LKARequest_Cnt_T_lgc == TRUE) && ((LKAFault_Cnt_T_lgc == TRUE) || (LKAInhibit_Cnt_T_lgc == TRUE) || (TrqOvlSta_ESCState_State_M_enum == ESC_Active) || (TrqOvlSta_ESCState_State_M_enum == ESC_TemporarilyLimited)))
			{
				TrqOvlSta_LKAState_State_M_enum = LKA_TemporarilyLimited;
			}
			else if(LKARequest_Cnt_T_lgc == TRUE)	/* REQ: CF09 #174 I */
			{
				TrqOvlSta_LKAState_State_M_enum = LKA_Active;
			}
			else
			{
				/* do nothing*/
			}
			break;
		
		case (LKA_Active):
			if((TrqOvlSta_LKAPermFault_Cnt_M_lgc == TRUE)||(LOAState_Cnt_T_enum != LOAST_NORM))	/* REQ: CF09 #176 I */
			{
				TrqOvlSta_LKAState_State_M_enum = LKA_PermanentlyFailed;
			}
			/* REQ: CF09 #90 I */
			/* REQ: CF09 #91 I */
			/* REQ: CF09 #176 I */
			else if((MinSecureVehicleSpeed_Kph_T_f32 < k_LKAMinVehSpd_Kph_f32) || (MaxSecureVehicleSpeed_Kph_T_f32 > k_LKAMaxVehSpd_Kph_f32) ||(LKARequest_Cnt_T_lgc == FALSE))
			{
				TrqOvlSta_LKAState_State_M_enum = LKA_Inactive;
			}
			/* REQ: CF09 #176 I */
			else if((LKAInhibit_Cnt_T_lgc == TRUE) || (LKAFault_Cnt_T_lgc == TRUE) || (TrqOvlSta_ESCState_State_M_enum == ESC_Active) || (TrqOvlSta_ESCState_State_M_enum == ESC_TemporarilyLimited)||(LKAIntervention_Cnt_T_lgc == TRUE))
			{
				TrqOvlSta_LKAState_State_M_enum = LKA_TemporarilyLimited;
			}
			else
			{
			 /* do nothing*/
			}
			break;
	   
		case (LKA_TemporarilyLimited):
			if ((TrqOvlSta_LKAPermFault_Cnt_M_lgc == TRUE)||(LOAState_Cnt_T_enum != LOAST_NORM))	/* REQ: CF09 #176 I */
			{
				TrqOvlSta_LKAState_State_M_enum = LKA_PermanentlyFailed;
			}
			else if(LKARequest_Cnt_T_lgc == FALSE)		/* REQ: CF09 #192 I */
			{
			  TrqOvlSta_LKAState_State_M_enum = LKA_Inactive;
			}
			else
			{
			/* do nothing*/
			}
			break;

		case (LKA_ManufacturingDisable):	/* REQ: CF09 #129 I */
			break;

		default:
			break;
	}
}
/**************************************************************************************************
* Name          :   HaptcStTran
* Description   :   Implementation of all Haptic state transitions within APA Available for Control             
* Inputs        :   LKAFault_Cnt_T_lgc,LKARequest_Cnt_T_lgc,LKAInhibit_Cnt_T_lgc,
*                   LKAIntervention_Cnt_T_lgc,LOAState_Cnt_T_enum 
*                   MinSecureVehicleSpeed_Kph_T_f32,MaxSecureVehicleSpeed_Kph_T_f32
* Outputs       :   
* Usage Notes   :
****************************************************************************************************/
static FUNC(void, TRQOVLSTA_APPL_CODE) HaptcStTran(boolean StandstillTime_Cnt_T_lgc,
												boolean APARequest_Cnt_T_lgc,
												boolean ShiftLevRevTime_Cnt_T_lgc,
												boolean HapticRequest_Cnt_T_lgc,
												boolean HaptcStTranActvToWaitFlg_Cnt_T_lgc,
												boolean TranHaptcWaitToApaStActvFlg_Cnt_T_lgc)
{
	if (k_APAIncludeHaptic_Cnt_lgc == FALSE)
	{
		/* Pulse Disabled */
		if ((StandstillTime_Cnt_T_lgc == TRUE)&&(APARequest_Cnt_T_lgc == TRUE)&&(ShiftLevRevTime_Cnt_T_lgc == TRUE))	/* REQ: CF09 #145 I */
		{
			TrqOvlSta_HapticState_State_M_enum = Haptic_Inactive;	/* REQ: CF09 #139 I */
			TrqOvlSta_APAState_State_M_enum = APA_Active;
		}
	}
	else
	{
		switch(TrqOvlSta_HapticState_State_M_enum)
		{
			case(Haptic_Inactive):
				/* "TrqOvlSta_ReadytoPulse_Cnt_M_lgc" to introduced a loop delay*/
				if((HapticRequest_Cnt_T_lgc == FALSE) && (TrqOvlSta_ReadytoPulse_Cnt_M_lgc == FALSE))	/* REQ: CF09 #150 I */
				{
					TrqOvlSta_ReadytoPulse_Cnt_M_lgc = TRUE;		/* REQ: CF09 #139 I */
				}
				else if(TrqOvlSta_ReadytoPulse_Cnt_M_lgc == TRUE)
				{
					/* REQ: CF09 #150 I */
					if((StandstillTime_Cnt_T_lgc == TRUE)&&(APARequest_Cnt_T_lgc == TRUE)&&(HapticRequest_Cnt_T_lgc == TRUE)&&(ShiftLevRevTime_Cnt_T_lgc == TRUE))
					{
						TrqOvlSta_HapticState_State_M_enum = Haptic_Active;
					}
					else if(HapticRequest_Cnt_T_lgc == TRUE)	/* REQ: CF09 #150 I */
					{
						TrqOvlSta_ReadytoPulse_Cnt_M_lgc = FALSE;	/* REQ: CF09 #139 I */
					}
					else
					{
						/** do nothing**/
					}
				}
				else
				{
					TrqOvlSta_HapticState_State_M_enum = Haptic_Inactive;
				}
				break;
			case(Haptic_Active):	/* REQ: CF09 #139 I */
				/* REQ: CF09 #150 I */
				if ((StandstillTime_Cnt_T_lgc == FALSE) ||(APARequest_Cnt_T_lgc == FALSE)||(ShiftLevRevTime_Cnt_T_lgc == FALSE))
				{
					TrqOvlSta_HapticState_State_M_enum = Haptic_Inactive;
				}
				/* REQ: CF09 #88 I */
				/* REQ: CF09 #201 I */
				else if(HaptcStTranActvToWaitFlg_Cnt_T_lgc == TRUE)
				{
					TrqOvlSta_HapticState_State_M_enum = Haptic_Waiting;
				}
				else
				{
					/** do nothing**/
				}
				break;
			case(Haptic_Waiting):	/* REQ: CF09 #139 I */
				/* REQ: CF09 #150 I */
				if ((StandstillTime_Cnt_T_lgc == FALSE)||(APARequest_Cnt_T_lgc == FALSE)||(ShiftLevRevTime_Cnt_T_lgc == FALSE))
				{
					TrqOvlSta_HapticState_State_M_enum = Haptic_Inactive;
				}
				/* REQ: CF09 #145 I */
				/* REQ: CF09 #150 I */
				else if(TranHaptcWaitToApaStActvFlg_Cnt_T_lgc == TRUE)
				{
					TrqOvlSta_APAState_State_M_enum = APA_Active;
					TrqOvlSta_HapticState_State_M_enum = Haptic_Inactive;
				}
				else
				{
					/** do nothing**/
				}
				break;
			default:
				break;
		}
	}
}
/***************************************************************************************
* Name          :   MfgDisableStTran
* Description   :   Manufacturing Disable State for LKA,APA,ESC                
* Inputs        :   GMOSH_APAMfgEnable_Cnt_T_lgc,GMOSH_LKAMfgEnable_Cnt_T_lgc,
*                   GMOSH_ESCMfgEnable_Cnt_T_lgc    
* Outputs       :   NA
* Usage Notes   :
****************************************************************************************/
static FUNC(void, TRQOVLSTA_APPL_CODE) MfgDisableStTran(boolean GMOSH_APAMfgEnable_Cnt_T_lgc,
															boolean GMOSH_LKAMfgEnable_Cnt_T_lgc,
															boolean GMOSH_ESCMfgEnable_Cnt_T_lgc)
{
	if(GMOSH_APAMfgEnable_Cnt_T_lgc == FALSE)
	{
		TrqOvlSta_APAState_State_M_enum = APA_ManufacturingDisable;
	}
	if(GMOSH_LKAMfgEnable_Cnt_T_lgc == FALSE)
	{
		TrqOvlSta_LKAState_State_M_enum = LKA_ManufacturingDisable;
	}
	if(GMOSH_ESCMfgEnable_Cnt_T_lgc == FALSE)
	{
		TrqOvlSta_ESCState_State_M_enum = ESC_ManufacturingDisable;
	}
}
/********************************************************************************************************
* Name          :   ApaActvStTran
* Description   :   Implementation of APA Active transitions              
* Inputs        :   APANonRecoverableFaults_Cnt_T_lgc,APARecoverableFaults_Cnt_T_lgc,HapticRequest_Cnt_T_lgc,
*                   APARequest_Cnt_T_lgc,APAIntervention_Cnt_T_lgc,
*                   LOAState_Cnt_T_enum,MaxSecureVehicleSpeed_Kph_T_f32
* Outputs       :   
* Usage Notes   :
**********************************************************************************************************/
static FUNC(void, TRQOVLSTA_APPL_CODE) ApaActvStTran(boolean APANonRecoverableFaults_Cnt_T_lgc,
												boolean APARecoverableFaults_Cnt_T_lgc,
												boolean HapticRequest_Cnt_T_lgc,
												boolean APARequest_Cnt_T_lgc,
												boolean APAIntervention_Cnt_T_lgc,
												LOA_State_enum LOAState_Cnt_T_enum,
												float32 MaxSecureVehicleSpeed_Kph_T_f32)
{
	if((APANonRecoverableFaults_Cnt_T_lgc == TRUE)||(LOAState_Cnt_T_enum != LOAST_NORM))
	{
		TrqOvlSta_APAState_State_M_enum = APA_PermanentlyFailed;
	}
	else if((MaxSecureVehicleSpeed_Kph_T_f32 > k_APAMaxVehSpd_Kph_f32)||(APARecoverableFaults_Cnt_T_lgc == TRUE)||(HapticRequest_Cnt_T_lgc == TRUE)||(APAIntervention_Cnt_T_lgc == TRUE))/* REQ: CF09 #155 I */
	{
		TrqOvlSta_APAState_State_M_enum = APA_TempInhibit;
	}
	/* APARequest_Cnt_T_lgc if false it will go to AvailCntrl */
	/* REQ: CF09 #86 I */
	else if(APARequest_Cnt_T_lgc == FALSE) 
	{	
		TrqOvlSta_APAState_State_M_enum = APA_AvailCntrl;
	}
	else
	{
		/*Do nothing*/
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
