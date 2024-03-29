/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_MtrDrvDiag.c
 *     Workspace:  C:/SynergyWorkArea/Working/SVDiag_DualInv/autosar
 *     SW-C Type:  Sa_MtrDrvDiag
 *  Generated at:  Tue Sep 22 11:10:40 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_MtrDrvDiag>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/****************************************************************************
 * Copyright 2015 Nexteer
 * Nexteer Confidential
 *
 * Module File Name	: Sa_MtrDrvDiag.c
 * Module Description: Sine Voltage Generation Diagnostics Dual Inverter
 * Project           : CBD
 * Author            : Krishna Kanth Anne
 *
 * Module File Name	: Sa_MtrDrvDiag.c
 *
 ****************************************************************************
 *  Version Control:
 * Date Created:      Mon Jun 20 11:22:09 2011
 * %version:          3 %
 * %derived_by:       czmgrw %
 * %date_modified:    Thu Oct  3 16:11:39 2013 %
 *---------------------------------------------------------------------------------------------------------------------	------------
 * Date      Rev      Author         Change Description                                                        			  SCR #
 * -------   -------  --------  --------------------------------------------------------------------------------------	------------
 * 08/06/15  01         KK    	 Updated for 9BXX (Based on ES49, updated for Dual Inverter Operation)		  			 EA3#2317
 * 08/12/15  02         KK    	 Rte_Call_IoHwAbPortConfig_SetFetFlt2ToOutput has been split up for 2 set of FETs 	     EA3#2365
 * 09/22/15  03         JK       Anomaly fix - modified the inverter inputs to inactive from active                      EA3#3243
 */

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

 *********************************************************************************************************************/

#include "Rte_Sa_MtrDrvDiag.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "fixmath.h"
#include "GlobalMacro.h"
#include "CalConstants.h"
#include "Os.h"

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance.  Rule suppressed by line at each occurrence.*/

/* MISRA-C:2004 Rule 8.7: This deviation is required to keep the memory map intact.  Rule suppressed by line at each occurrence. */

#define D_PHASEALOWER_CNT_U16				0U
#define D_PHASEBLOWER_CNT_U16				1U
#define D_PHASECLOWER_CNT_U16				2U
#define D_PHASEAUPPER_CNT_U16				3U
#define D_PHASEBUPPER_CNT_U16				4U
#define D_PHASECUPPER_CNT_U16				5U
#define D_PHASEDLOWER_CNT_U16				0U
#define D_PHASEELOWER_CNT_U16				1U
#define D_PHASEFLOWER_CNT_U16				2U
#define D_PHASEDUPPER_CNT_U16				3U
#define D_PHASEEUPPER_CNT_U16				4U
#define D_PHASEFUPPER_CNT_U16				5U
#define D_VREGUV_CNT_U16					6U
#define D_BTSTRPAUV_CNT_U16					7U
#define D_BTSTRPBUV_CNT_U16					8U
#define D_BTSTRPCUV_CNT_U16					9U
#define D_NUMOFGDSTATUSBITS_CNT_U16			10U
#define D_STATUSALOWER_CNT_B16				0x0001U
#define D_STATUSBLOWER_CNT_B16				0x0002U
#define D_STATUSCLOWER_CNT_B16				0x0004U
#define D_STATUSDLOWER_CNT_B16				0x0001U
#define D_STATUSELOWER_CNT_B16				0x0002U
#define D_STATUSFLOWER_CNT_B16				0x0004U
#define D_STATUSAUPPER_CNT_B16				0x0008U
#define D_STATUSBUPPER_CNT_B16				0x0010U
#define D_STATUSCUPPER_CNT_B16				0x0020U
#define D_STATUSDUPPER_CNT_B16				0x0008U
#define D_STATUSEUPPER_CNT_B16				0x0010U
#define D_STATUSFUPPER_CNT_B16				0x0020U
#define D_STATUSVREGUV_CNT_B16				0x0040U
#define D_STATUSBTSTRPAUV_CNT_B16			0x0080U
#define D_STATUSBTSTRPBUV_CNT_B16			0x0100U
#define D_STATUSBTSTRPCUV_CNT_B16			0x0200U
#define D_STATUSVDDUV_CNT_B16				0x0400U
#define D_STATUSOVERTEMP_CNT_B16			0x8000U
#define D_FFDATACLKTIME_US_U16P0			4U
#define D_GDRESETTIME_US_U16P0				2U
#define D_MTRDRVINITDELAY_MS_U08        	10U
#define D_GATEDRVCOMMLOSSACCTHRS_CNT_U16   	100U


#define MTRDRVDIAG_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_MtrDrv1InitStartTime_mS_M_u32p0;	/* PRQA S 3218 */
STATIC VAR(uint32, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_MtrDrv2InitStartTime_mS_M_u32p0;	/* PRQA S 3218 */
#define MTRDRVDIAG_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define MTRDRVDIAG_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_GateDrive1FltAcc_Cnt_M_u16;			/* PRQA S 3218 */
STATIC VAR(uint16, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_GateDrive2FltAcc_Cnt_M_u16;			/* PRQA S 3218 */
STATIC VAR(uint16, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_GenGateDrive1FltAcc_Cnt_M_u16;		/* PRQA S 3218 */
STATIC VAR(uint16, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_GenGateDrive2FltAcc_Cnt_M_u16;		/* PRQA S 3218 */
STATIC VAR(uint16, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_OnStateFlt1Acc_Cnt_M_u16;			/* PRQA S 3218 */
STATIC VAR(uint16, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_OnStateFlt2Acc_Cnt_M_u16;			/* PRQA S 3218 */
STATIC VAR(uint16, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_GateDrv1FltSts_Cnt_M_u16;			/* PRQA S 3218 */
STATIC VAR(uint16, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_GateDrv2FltSts_Cnt_M_u16;			/* PRQA S 3218 */
#define MTRDRVDIAG_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define MTRDRVDIAG_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_MtrDrv1InitComp_Cnt_M_lgc;			/* PRQA S 3218 */
STATIC VAR(boolean, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_MtrDrv2InitComp_Cnt_M_lgc;			/* PRQA S 3218 */
STATIC VAR(boolean, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_Reset1WaitLoop_Cnt_M_lgc;			/* PRQA S 3218 */
STATIC VAR(boolean, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_Reset2WaitLoop_Cnt_M_lgc;			/* PRQA S 3218 */
STATIC VAR(boolean, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_MtrDrv1InitActive_Cnt_M_lgc;		/* PRQA S 3218 */
STATIC VAR(boolean, SA_MTRDRVDIAG_VAR_NOINIT) SVDiag_MtrDrv2InitActive_Cnt_M_lgc;		/* PRQA S 3218 */
#define MTRDRVDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


STATIC INLINE FUNC(boolean, SA_MTRDRVDIAG_CODE) MotorDriver1Init(void);

STATIC INLINE FUNC(boolean, SA_MTRDRVDIAG_CODE) MotorDriver2Init(void);

STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) ProcGateDrive1Flt(	CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) GateDrive1FltAccPtr_Cnt_T_u16,
																VAR(boolean, AUTOMATIC) F1F2Set_Cnt_T_lgc);

STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) ProcGateDrive2Flt(	CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) GateDrive2FltAccPtr_Cnt_T_u16,
																VAR(boolean, AUTOMATIC) F2F2Set_Cnt_T_lgc);
																
													
STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) ProcBridge1Flt ( CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) OnStateFltAccPtr_Cnt_T_u16,
															  CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) GenGateDriveFltAccPtr_Cnt_T_u16 );

STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) ProcBridge2Flt ( CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) OnStateFltAccPtr_Cnt_T_u16,
															  CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) GenGateDriveFltAccPtr_Cnt_T_u16 );

STATIC INLINE FUNC(uint16, SA_MTRDRVDIAG_CODE) ReadMtrDrv1FltData( CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) StatusPtr_Cnt_T_b16 );

STATIC INLINE FUNC(uint16, SA_MTRDRVDIAG_CODE) ReadMtrDrv2FltData( CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) StatusPtr_Cnt_T_b16 );

STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) ResetGateDriveABC(void);

STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) ResetGateDriveDEF(void);

STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) GateDrvWaitTime(	VAR(uint16, AUTOMATIC) TimeToWait_uS_T_u16p0);


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
 * UInt32: D_ZERO_CNT_U32 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_MTRDRVDIAG_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrDrvDiag_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <DISABLE, OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_MtrDrvDiag_Per1_Inverter1Inactive_Cnt_lgc(void)
 *   Boolean Rte_IRead_MtrDrvDiag_Per1_Inverter2Inactive_Cnt_lgc(void)
 *   Boolean Rte_IRead_MtrDrvDiag_Per1_MtrDrvr1InitStart_Cnt_lgc(void)
 *   Boolean Rte_IRead_MtrDrvDiag_Per1_MtrDrvr2InitStart_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrDrvDiag_Per1_GateDrive1ResetActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_MtrDrvDiag_Per1_GateDrive1ResetActive_Cnt_lgc(void)
 *   void Rte_IWrite_MtrDrvDiag_Per1_GateDrive2ResetActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_MtrDrvDiag_Per1_GateDrive2ResetActive_Cnt_lgc(void)
 *   void Rte_IWrite_MtrDrvDiag_Per1_MtrDrvr1InitComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_MtrDrvDiag_Per1_MtrDrvr1InitComplete_Cnt_lgc(void)
 *   void Rte_IWrite_MtrDrvDiag_Per1_MtrDrvr2InitComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_MtrDrvDiag_Per1_MtrDrvr2InitComplete_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_Fet1Flt1Data_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetFlt1Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Fet1Flt2Clk_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetFlt2Clk_E_NOT_OK
 *   Std_ReturnType Rte_Call_Fet1Flt2Clk_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetFlt2Clk_E_NOT_OK
 *   Std_ReturnType Rte_Call_Fet2Flt1Data_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetFlt1Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_Fet2Flt2Clk_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetFlt2Clk_E_NOT_OK
 *   Std_ReturnType Rte_Call_Fet2Flt2Clk_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetFlt2Clk_E_NOT_OK
 *   Std_ReturnType Rte_Call_FetDrvResetABC_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetDrvReset_E_NOT_OK
 *   Std_ReturnType Rte_Call_FetDrvResetDEF_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetDrvReset_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAbPortConfig_SetFet1Flt2ToOutput(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAbPortConfig_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAbPortConfig_SetFet2Flt2ToOutput(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAbPortConfig_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRDRVDIAG_APPL_CODE) MtrDrvDiag_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrDrvDiag_Per1
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Name			: MtrDrvDiag_Per1
* Description	: NA
* Inputs		: NONE
* Outputs		: NONE
* Usage Notes	: NA
***********************************************************************************************************************/

	
	
	VAR(boolean, AUTOMATIC) 	MtrDrvr1InitStart_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) 	MtrDrvr2InitStart_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	 	MtrDrv1InitComp_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	 	MtrDrv2InitComp_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) 	F1F1Set_Cnt_T_lgc;						/* This corresponds to Fet1 Fault1 (Fault1 is w.r.t Data) */
	VAR(boolean, AUTOMATIC) 	F1F2Set_Cnt_T_lgc;						/* This corresponds to Fet1 Fault2 (Fault2 is w.r.t Clock) */
	VAR(boolean, AUTOMATIC) 	F2F1Set_Cnt_T_lgc;						/* This corresponds to Fet2 Fault1 (Fault1 is w.r.t Data) */
	VAR(boolean, AUTOMATIC) 	F2F2Set_Cnt_T_lgc;						/* This corresponds to Fet2 Fault2 (Fault2 is w.r.t Clock) */
	VAR(boolean, AUTOMATIC) 	GateDrive1ResetActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) 	GateDrive2ResetActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)		Inverter1Inactive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)		Inverter2Inactive_Cnt_T_lgc;

	VAR(uint16, AUTOMATIC) 		GateDrive1FltAcc_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) 		GateDrive2FltAcc_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) 		GenGateDrive1FltAcc_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) 		GenGateDrive2FltAcc_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) 		OnStateFlt1Acc_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) 		OnStateFlt2Acc_Cnt_T_u16;
	


	MtrDrvr1InitStart_Cnt_T_lgc 	= Rte_IRead_MtrDrvDiag_Per1_MtrDrvr1InitStart_Cnt_lgc();
	MtrDrvr2InitStart_Cnt_T_lgc 	= Rte_IRead_MtrDrvDiag_Per1_MtrDrvr2InitStart_Cnt_lgc();
	MtrDrv1InitComp_Cnt_T_lgc 		= SVDiag_MtrDrv1InitComp_Cnt_M_lgc;
	MtrDrv2InitComp_Cnt_T_lgc 		= SVDiag_MtrDrv2InitComp_Cnt_M_lgc;
	GateDrive1FltAcc_Cnt_T_u16 		= SVDiag_GateDrive1FltAcc_Cnt_M_u16;
	GateDrive2FltAcc_Cnt_T_u16 		= SVDiag_GateDrive2FltAcc_Cnt_M_u16;
	GenGateDrive1FltAcc_Cnt_T_u16 	= SVDiag_GenGateDrive1FltAcc_Cnt_M_u16;
	GenGateDrive2FltAcc_Cnt_T_u16 	= SVDiag_GenGateDrive2FltAcc_Cnt_M_u16;
	OnStateFlt1Acc_Cnt_T_u16 		= SVDiag_OnStateFlt1Acc_Cnt_M_u16;
	OnStateFlt2Acc_Cnt_T_u16 		= SVDiag_OnStateFlt2Acc_Cnt_M_u16;
	Inverter1Inactive_Cnt_T_lgc 	= Rte_IRead_MtrDrvDiag_Per1_Inverter1Inactive_Cnt_lgc();
	Inverter2Inactive_Cnt_T_lgc 	= Rte_IRead_MtrDrvDiag_Per1_Inverter2Inactive_Cnt_lgc();
	
	
	
	/****  Start of Gate drive 1 Diagnostics Processing  ****/
	GateDrive1ResetActive_Cnt_T_lgc = FALSE;
	
	if (TRUE == MtrDrv1InitComp_Cnt_T_lgc)
	{
		if  (FALSE == Inverter1Inactive_Cnt_T_lgc) 
		{

				if (TRUE == SVDiag_Reset1WaitLoop_Cnt_M_lgc)
				{
					ResetGateDriveABC();
					SVDiag_Reset1WaitLoop_Cnt_M_lgc = FALSE;
				}
				else
				{
				
					(void)Rte_Call_Fet1Flt1Data_OP_GET(&F1F1Set_Cnt_T_lgc);
					(void)Rte_Call_Fet1Flt2Clk_OP_GET(&F1F2Set_Cnt_T_lgc);
				
					if ((FALSE == F1F1Set_Cnt_T_lgc) && (FALSE == F1F2Set_Cnt_T_lgc))
					{
						/* No Fault operation */
						
						GateDrive1FltAcc_Cnt_T_u16 = DiagNStep_m(GateDrive1FltAcc_Cnt_T_u16, k_GateDriveDiag_Cnt_str);
						OnStateFlt1Acc_Cnt_T_u16   = DiagNStep_m(OnStateFlt1Acc_Cnt_T_u16, k_OnStateDiag_Cnt_str);
					
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_GateDrvFlt, 0x00U, NTC_STATUS_PASSED);
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_OnStateSingleFET, 0x00U, NTC_STATUS_PASSED);
					}
					else
					{
						/* Process Continuous Gate Drive 1 Fault Condition */
						
						GateDrive1ResetActive_Cnt_T_lgc = TRUE;
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_GateDrvFltInProcess, 0x01U, NTC_STATUS_FAILED);
				
						if (TRUE == F1F1Set_Cnt_T_lgc)
						{
							/* Gate Drive 1 Fault Processing */
							ProcGateDrive1Flt(&GateDrive1FltAcc_Cnt_T_u16, F1F2Set_Cnt_T_lgc);
						}
						else
						{
							/* Bridge Fault Processing for gate drive 1*/
							ProcBridge1Flt(&OnStateFlt1Acc_Cnt_T_u16, &GenGateDrive1FltAcc_Cnt_T_u16);
							
						}

						if (TRUE != SVDiag_Reset1WaitLoop_Cnt_M_lgc)
						{
							ResetGateDriveABC();
						}
					}

				}
		}
	}

	else
	{
		if (TRUE == MtrDrvr1InitStart_Cnt_T_lgc)
		{
			MtrDrv1InitComp_Cnt_T_lgc = MotorDriver1Init();
		}
	}
	/****  End of Gate drive 1 Diagnostics Processing  ****/
	
	
	
	/****  Start of Gate drive 2 Diagnostics Processing  ****/
	GateDrive2ResetActive_Cnt_T_lgc = FALSE;
	
	if (TRUE == MtrDrv2InitComp_Cnt_T_lgc)
	{
		if  (FALSE == Inverter2Inactive_Cnt_T_lgc) 
		{

				if (TRUE == SVDiag_Reset2WaitLoop_Cnt_M_lgc)
				{
					ResetGateDriveDEF();
					SVDiag_Reset2WaitLoop_Cnt_M_lgc = FALSE;
				}
				else
				{
				
					(void)Rte_Call_Fet2Flt1Data_OP_GET(&F2F1Set_Cnt_T_lgc);
					(void)Rte_Call_Fet2Flt2Clk_OP_GET(&F2F2Set_Cnt_T_lgc);
				
					if ((FALSE == F2F1Set_Cnt_T_lgc) && (FALSE == F2F2Set_Cnt_T_lgc))
					{
						/* No Fault operation */
						
						GateDrive2FltAcc_Cnt_T_u16 = DiagNStep_m(GateDrive2FltAcc_Cnt_T_u16, k_GateDriveDiag_Cnt_str);
						OnStateFlt2Acc_Cnt_T_u16   = DiagNStep_m(OnStateFlt2Acc_Cnt_T_u16, k_OnStateDiag_Cnt_str);
					
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Inv2GateDrvFlt, 0x00U, NTC_STATUS_PASSED);
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Inv2OnStateSingleFET, 0x00U, NTC_STATUS_PASSED);
					}
					else
					{
						/* Process Continuous Gate Drive 2 Fault Condition */
						
						GateDrive2ResetActive_Cnt_T_lgc = TRUE;
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Inv2GateDrvFltInProcess, 0x01U, NTC_STATUS_FAILED);
				
						if (TRUE == F2F1Set_Cnt_T_lgc)
						{
							/* Gate Drive 2 Fault Processing */
							ProcGateDrive2Flt(&GateDrive2FltAcc_Cnt_T_u16, F2F2Set_Cnt_T_lgc);
						}
						else
						{
							/* Bridge Fault Processing for gate drive 2*/
							ProcBridge2Flt(&OnStateFlt2Acc_Cnt_T_u16, &GenGateDrive2FltAcc_Cnt_T_u16);
							
						}

						if (TRUE != SVDiag_Reset2WaitLoop_Cnt_M_lgc)
						{
							ResetGateDriveDEF();
						}
					}

				}
		}
	}

	else
	{
		if (TRUE == MtrDrvr2InitStart_Cnt_T_lgc)
		{
			MtrDrv2InitComp_Cnt_T_lgc = MotorDriver2Init();
		}
	}
	/****  End of Gate drive 2 Diagnostics Processing  ****/
	
	
	Rte_IWrite_MtrDrvDiag_Per1_MtrDrvr1InitComplete_Cnt_lgc(MtrDrv1InitComp_Cnt_T_lgc);
	Rte_IWrite_MtrDrvDiag_Per1_MtrDrvr2InitComplete_Cnt_lgc(MtrDrv2InitComp_Cnt_T_lgc);
	Rte_IWrite_MtrDrvDiag_Per1_GateDrive1ResetActive_Cnt_lgc(GateDrive1ResetActive_Cnt_T_lgc);
	Rte_IWrite_MtrDrvDiag_Per1_GateDrive2ResetActive_Cnt_lgc(GateDrive2ResetActive_Cnt_T_lgc);
	
	SVDiag_MtrDrv1InitComp_Cnt_M_lgc 		= MtrDrv1InitComp_Cnt_T_lgc;
	SVDiag_MtrDrv2InitComp_Cnt_M_lgc 		= MtrDrv2InitComp_Cnt_T_lgc;
	SVDiag_GateDrive1FltAcc_Cnt_M_u16 		= GateDrive1FltAcc_Cnt_T_u16;
	SVDiag_GateDrive2FltAcc_Cnt_M_u16 		= GateDrive2FltAcc_Cnt_T_u16;
	SVDiag_GenGateDrive1FltAcc_Cnt_M_u16 	= GenGateDrive1FltAcc_Cnt_T_u16;
	SVDiag_GenGateDrive2FltAcc_Cnt_M_u16 	= GenGateDrive2FltAcc_Cnt_T_u16;
	SVDiag_OnStateFlt1Acc_Cnt_M_u16 		= OnStateFlt1Acc_Cnt_T_u16;
	SVDiag_OnStateFlt2Acc_Cnt_M_u16 		= OnStateFlt2Acc_Cnt_T_u16;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrDrvDiag_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_MtrDrvDiag_Per2_Inverter1Inactive_Cnt_lgc(void)
 *   Boolean Rte_IRead_MtrDrvDiag_Per2_Inverter2Inactive_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_FetDrvResetABC_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetDrvReset_E_NOT_OK
 *   Std_ReturnType Rte_Call_FetDrvResetDEF_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetDrvReset_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRDRVDIAG_APPL_CODE) MtrDrvDiag_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrDrvDiag_Per2
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Name			: MtrDrvDiag_Per2
* Description	: NA
* Inputs		: NONE
* Outputs		: NONE
* Usage Notes	: NA
***********************************************************************************************************************/

	VAR(boolean, AUTOMATIC)						Inverter1Inactive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)						Inverter2Inactive_Cnt_T_lgc;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC)		SysState_Cnt_T_Enum;

	Inverter1Inactive_Cnt_T_lgc 	= Rte_IRead_MtrDrvDiag_Per2_Inverter1Inactive_Cnt_lgc();
	Inverter2Inactive_Cnt_T_lgc 	= Rte_IRead_MtrDrvDiag_Per2_Inverter2Inactive_Cnt_lgc();

	SysState_Cnt_T_Enum = Rte_Mode_SystemState_Mode();

	if (RTE_MODE_StaMd_Mode_DISABLE == SysState_Cnt_T_Enum)
	{
		(void)Rte_Call_FetDrvResetABC_OP_SET(STD_LOW);
		(void)Rte_Call_FetDrvResetDEF_OP_SET(STD_LOW);
	}

	if (TRUE == Inverter1Inactive_Cnt_T_lgc)
	{
		(void)Rte_Call_FetDrvResetABC_OP_SET(STD_LOW);
	}


	if (TRUE == Inverter2Inactive_Cnt_T_lgc)
	{
		(void)Rte_Call_FetDrvResetDEF_OP_SET(STD_LOW);
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrDrvDiag_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <WARMINIT> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrDrvDiag_Trns1_MtrDrvr1InitComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_MtrDrvDiag_Trns1_MtrDrvr1InitComplete_Cnt_lgc(void)
 *   void Rte_IWrite_MtrDrvDiag_Trns1_MtrDrvr2InitComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_MtrDrvDiag_Trns1_MtrDrvr2InitComplete_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_FetDrvResetABC_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetDrvReset_E_NOT_OK
 *   Std_ReturnType Rte_Call_FetDrvResetDEF_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetDrvReset_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRDRVDIAG_APPL_CODE) MtrDrvDiag_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrDrvDiag_Trns1
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Name			: MtrDrvDiag_Trns1
* Description	: NA
* Inputs		: NONE
* Outputs		: NONE
* Usage Notes	: NA
**********************************************************************************************************************/

	(void)Rte_Call_FetDrvResetABC_OP_SET(STD_HIGH);
	(void)Rte_Call_FetDrvResetDEF_OP_SET(STD_HIGH);

	SVDiag_GateDrive1FltAcc_Cnt_M_u16 		= 0U;
	SVDiag_GateDrive2FltAcc_Cnt_M_u16 		= 0U;
	SVDiag_GenGateDrive1FltAcc_Cnt_M_u16 	= 0U;
	SVDiag_GenGateDrive2FltAcc_Cnt_M_u16 	= 0U;
	SVDiag_OnStateFlt1Acc_Cnt_M_u16 		= 0U;
	SVDiag_OnStateFlt2Acc_Cnt_M_u16 		= 0U;
	SVDiag_MtrDrv1InitComp_Cnt_M_lgc 		= FALSE;
	SVDiag_MtrDrv2InitComp_Cnt_M_lgc 		= FALSE;


	Rte_IWrite_MtrDrvDiag_Trns1_MtrDrvr1InitComplete_Cnt_lgc(FALSE);
	Rte_IWrite_MtrDrvDiag_Trns1_MtrDrvr2InitComplete_Cnt_lgc(FALSE);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_MTRDRVDIAG_APPL_CODE
#include "MemMap.h"	/* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/****************************************************************************************************************************
* Name			: ProcGateDrive1Flt
* Description	: NA
* Inputs		: GateDrive1FltAccPtr_Cnt_T_u16, F1F2Set_Cnt_T_lgc
* Outputs		: NONE
* Usage Notes	: NA
****************************************************************************************************************************/
STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) ProcGateDrive1Flt(	CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) GateDrive1FltAccPtr_Cnt_T_u16,
																VAR(boolean, AUTOMATIC) F1F2Set_Cnt_T_lgc)
{


	*GateDrive1FltAccPtr_Cnt_T_u16 = DiagPStep_m(*GateDrive1FltAccPtr_Cnt_T_u16, k_GateDriveDiag_Cnt_str);

	if( TRUE== DiagFailed_m(*GateDrive1FltAccPtr_Cnt_T_u16, k_GateDriveDiag_Cnt_str) )
	{

		if (FALSE == F1F2Set_Cnt_T_lgc)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_GateDrvFlt, 0x01U, NTC_STATUS_FAILED);
			SVDiag_GateDrv1FltSts_Cnt_M_u16 |= D_STATUSOVERTEMP_CNT_B16;
		}
		else
		{
		 	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_GateDrvFlt, 0x04U, NTC_STATUS_FAILED);
		 	(void)ReadMtrDrv1FltData(&SVDiag_GateDrv1FltSts_Cnt_M_u16);
		}
	}
}


/****************************************************************************************************************************
* Name			: ProcGateDrive2Flt
* Description	: NA
* Inputs		: GateDrive2FltAccPtr_Cnt_T_u16, F2F2Set_Cnt_T_lgc
* Outputs		: NONE
* Usage Notes	: NA
****************************************************************************************************************************/
STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) ProcGateDrive2Flt(	CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) GateDrive2FltAccPtr_Cnt_T_u16,
																VAR(boolean, AUTOMATIC) F2F2Set_Cnt_T_lgc)
{


	*GateDrive2FltAccPtr_Cnt_T_u16 = DiagPStep_m(*GateDrive2FltAccPtr_Cnt_T_u16, k_GateDriveDiag_Cnt_str);

	if( TRUE== DiagFailed_m(*GateDrive2FltAccPtr_Cnt_T_u16, k_GateDriveDiag_Cnt_str) )
	{

		if (FALSE == F2F2Set_Cnt_T_lgc)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Inv2GateDrvFlt, 0x01U, NTC_STATUS_FAILED);
			SVDiag_GateDrv2FltSts_Cnt_M_u16 |= D_STATUSOVERTEMP_CNT_B16;
		}
		else
		{
		 	(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Inv2GateDrvFlt, 0x04U, NTC_STATUS_FAILED);
		 	(void)ReadMtrDrv2FltData(&SVDiag_GateDrv2FltSts_Cnt_M_u16);
		}
	}
}




/****************************************************************************************************************************
* Name			: ProcBridge1Flt
* Description	: NA
* Inputs		: OnStateFltAccPtr_Cnt_T_u16, GenGateDriveFltAccPtr_Cnt_T_u16
* Outputs		: NONE
* Usage Notes	: NA
****************************************************************************************************************************/
STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) ProcBridge1Flt ( CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) OnStateFltAccPtr_Cnt_T_u16,
															CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) GenGateDriveFltAccPtr_Cnt_T_u16 )
{
	VAR(boolean, AUTOMATIC)  OnStateFltActive_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC)   FaultedPhases_Cnt_T_u16;
	VAR(uint8, AUTOMATIC)    SingleFETFltNTCParam_Cnt_T_u08;

	*OnStateFltAccPtr_Cnt_T_u16 = DiagPStep_m(*OnStateFltAccPtr_Cnt_T_u16, k_OnStateDiag_Cnt_str);

	if (TRUE == DiagFailed_m(*OnStateFltAccPtr_Cnt_T_u16, k_OnStateDiag_Cnt_str))
	{
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_OnStateSingleFET, &OnStateFltActive_Cnt_T_lgc);

					FaultedPhases_Cnt_T_u16 = ReadMtrDrv1FltData(&SVDiag_GateDrv1FltSts_Cnt_M_u16);

			if (FaultedPhases_Cnt_T_u16 == 1U)  /* Single FET fault if TRUE*/
			{
				SVDiag_Reset1WaitLoop_Cnt_M_lgc = TRUE;

				/* Determine the NTC parameter for On-State single FET fault */
				SingleFETFltNTCParam_Cnt_T_u08  =  (uint8)(((uint8)((SVDiag_GateDrv1FltSts_Cnt_M_u16) & 0x0001U)) << 1U );   /* Vds exceeded on A phase high-side FET */
				SingleFETFltNTCParam_Cnt_T_u08 |=  (uint8)(((uint8)((SVDiag_GateDrv1FltSts_Cnt_M_u16) & 0x0002U)) << 2U );   /* Vds exceeded on B phase high-side FET */
				SingleFETFltNTCParam_Cnt_T_u08 |=  (uint8)(((uint8)((SVDiag_GateDrv1FltSts_Cnt_M_u16) & 0x0004U)) << 3U );   /* Vds exceeded on C phase high-side FET */

				SingleFETFltNTCParam_Cnt_T_u08 |=  (((uint8)((SVDiag_GateDrv1FltSts_Cnt_M_u16) & 0x0008U)) >> 3U );          /* Vds exceeded on A phase low-side FET */
				SingleFETFltNTCParam_Cnt_T_u08 |=  (((uint8)((SVDiag_GateDrv1FltSts_Cnt_M_u16) & 0x0010U)) >> 2U );          /* Vds exceeded on B phase low-side FET */
				SingleFETFltNTCParam_Cnt_T_u08 |=  (((uint8)((SVDiag_GateDrv1FltSts_Cnt_M_u16) & 0x0020U)) >> 1U );          /* Vds exceeded on C phase low-side FET */

				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_OnStateSingleFET, SingleFETFltNTCParam_Cnt_T_u08, NTC_STATUS_FAILED);
				*OnStateFltAccPtr_Cnt_T_u16 = 0U;
			}
			else  /* Gate Drive communication loss if TRUE*/
			{
				*OnStateFltAccPtr_Cnt_T_u16 = 0U;
				*GenGateDriveFltAccPtr_Cnt_T_u16 = *GenGateDriveFltAccPtr_Cnt_T_u16 + 1U;
				if(*GenGateDriveFltAccPtr_Cnt_T_u16 >= D_GATEDRVCOMMLOSSACCTHRS_CNT_U16)
				{
					*GenGateDriveFltAccPtr_Cnt_T_u16 = D_GATEDRVCOMMLOSSACCTHRS_CNT_U16;
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_GateDrvFlt, 0x02U, NTC_STATUS_FAILED);
			    }
			}
		}
	}


/****************************************************************************************************************************
* Name			: ProcBridge2Flt
* Description	: NA
* Inputs		: OnStateFltAccPtr_Cnt_T_u16, GenGateDriveFltAccPtr_Cnt_T_u16
* Outputs		: NONE
* Usage Notes	: NA
****************************************************************************************************************************/
STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) ProcBridge2Flt ( CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) OnStateFltAccPtr_Cnt_T_u16,
															CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) GenGateDriveFltAccPtr_Cnt_T_u16 )
{
	VAR(boolean, AUTOMATIC)  OnStateFltActive_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC)   FaultedPhases_Cnt_T_u16;
	VAR(uint8, AUTOMATIC)    SingleFETFltNTCParam_Cnt_T_u08;

	*OnStateFltAccPtr_Cnt_T_u16 = DiagPStep_m(*OnStateFltAccPtr_Cnt_T_u16, k_OnStateDiag_Cnt_str);

	if (TRUE == DiagFailed_m(*OnStateFltAccPtr_Cnt_T_u16, k_OnStateDiag_Cnt_str))
	{
		(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_Inv2OnStateSingleFET, &OnStateFltActive_Cnt_T_lgc);
		
		FaultedPhases_Cnt_T_u16 = ReadMtrDrv2FltData(&SVDiag_GateDrv2FltSts_Cnt_M_u16);

			if (FaultedPhases_Cnt_T_u16 == 1U)  /* Single FET fault if TRUE*/
			{
				SVDiag_Reset2WaitLoop_Cnt_M_lgc = TRUE;

				/* Determine the NTC parameter for On-State single FET fault */
				SingleFETFltNTCParam_Cnt_T_u08  =  (uint8)(((uint8)((SVDiag_GateDrv2FltSts_Cnt_M_u16) & 0x0001U)) << 1U );   /* Vds exceeded on D phase high-side FET */
				SingleFETFltNTCParam_Cnt_T_u08 |=  (uint8)(((uint8)((SVDiag_GateDrv2FltSts_Cnt_M_u16) & 0x0002U)) << 2U );   /* Vds exceeded on E phase high-side FET */
				SingleFETFltNTCParam_Cnt_T_u08 |=  (uint8)(((uint8)((SVDiag_GateDrv2FltSts_Cnt_M_u16) & 0x0004U)) << 3U );   /* Vds exceeded on F phase high-side FET */

				SingleFETFltNTCParam_Cnt_T_u08 |=  (((uint8)((SVDiag_GateDrv2FltSts_Cnt_M_u16) & 0x0008U)) >> 3U );          /* Vds exceeded on D phase low-side FET */
				SingleFETFltNTCParam_Cnt_T_u08 |=  (((uint8)((SVDiag_GateDrv2FltSts_Cnt_M_u16) & 0x0010U)) >> 2U );          /* Vds exceeded on E phase low-side FET */
				SingleFETFltNTCParam_Cnt_T_u08 |=  (((uint8)((SVDiag_GateDrv2FltSts_Cnt_M_u16) & 0x0020U)) >> 1U );          /* Vds exceeded on F phase low-side FET */

				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Inv2OnStateSingleFET, SingleFETFltNTCParam_Cnt_T_u08, NTC_STATUS_FAILED);
				*OnStateFltAccPtr_Cnt_T_u16 = 0U;
			}
			else  /* Gate Drive communication loss if TRUE*/
			{
				*OnStateFltAccPtr_Cnt_T_u16 = 0U;
				*GenGateDriveFltAccPtr_Cnt_T_u16 = *GenGateDriveFltAccPtr_Cnt_T_u16 + 1U;
				if(*GenGateDriveFltAccPtr_Cnt_T_u16 >= D_GATEDRVCOMMLOSSACCTHRS_CNT_U16)
				{
					*GenGateDriveFltAccPtr_Cnt_T_u16 = D_GATEDRVCOMMLOSSACCTHRS_CNT_U16;
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_Inv2GateDrvFlt, 0x02U, NTC_STATUS_FAILED);
			    }
			}
		}
	}





/****************************************************************************************************************************
* Name			: ReadMtrDrv1FltData
* Description	: Motor Drive 1 fault data
* Inputs		: StatusPtr_Cnt_T_b16
* Outputs		: NONE
* Usage Notes	: NA
****************************************************************************************************************************/
STATIC INLINE FUNC(uint16, SA_MTRDRVDIAG_CODE) ReadMtrDrv1FltData(	CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) StatusPtr_Cnt_T_b16)
{

	VAR(uint16, AUTOMATIC) FaultedPhases_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) DataHigh_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) ClockBit_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) Status_Cnt_T_b16;

	(void)Rte_Call_IoHwAbPortConfig_SetFet1Flt2ToOutput(TRUE);

	FaultedPhases_Cnt_T_u16 = 0U;
	Status_Cnt_T_b16 = 0U;


	for (ClockBit_Cnt_T_u16 = 0U; ClockBit_Cnt_T_u16 < D_NUMOFGDSTATUSBITS_CNT_U16; ClockBit_Cnt_T_u16++)
	{
		(void)Rte_Call_Fet1Flt2Clk_OP_SET(STD_LOW);
		GateDrvWaitTime(D_FFDATACLKTIME_US_U16P0);

		(void)Rte_Call_Fet1Flt1Data_OP_GET(&DataHigh_Cnt_T_lgc);

		if (TRUE == DataHigh_Cnt_T_lgc)
		{
			switch(ClockBit_Cnt_T_u16)
			{
				case D_PHASEALOWER_CNT_U16:
					FaultedPhases_Cnt_T_u16++;
					Status_Cnt_T_b16 |= D_STATUSALOWER_CNT_B16;
					break;
				case D_PHASEBLOWER_CNT_U16:
					FaultedPhases_Cnt_T_u16++;
					Status_Cnt_T_b16 |= D_STATUSBLOWER_CNT_B16;
					break;
				case D_PHASECLOWER_CNT_U16:
					FaultedPhases_Cnt_T_u16++;
					Status_Cnt_T_b16 |= D_STATUSCLOWER_CNT_B16;
					break;
				case D_PHASEAUPPER_CNT_U16:
					FaultedPhases_Cnt_T_u16++;
					Status_Cnt_T_b16 |= D_STATUSAUPPER_CNT_B16;
					break;
				case D_PHASEBUPPER_CNT_U16:
					FaultedPhases_Cnt_T_u16++;
					Status_Cnt_T_b16 |= D_STATUSBUPPER_CNT_B16;
					break;
				case D_PHASECUPPER_CNT_U16:
					FaultedPhases_Cnt_T_u16++;
					Status_Cnt_T_b16 |= D_STATUSCUPPER_CNT_B16;
					break;
				case D_VREGUV_CNT_U16:
					Status_Cnt_T_b16 |= D_STATUSVREGUV_CNT_B16;
					break;
				case D_BTSTRPAUV_CNT_U16:
					Status_Cnt_T_b16 |= D_STATUSBTSTRPAUV_CNT_B16;
					break;
				case D_BTSTRPBUV_CNT_U16:
					Status_Cnt_T_b16 |= D_STATUSBTSTRPBUV_CNT_B16;
					break;
				case D_BTSTRPCUV_CNT_U16:
				default: /* D_BTSTRPCUV_CNT_U16 */
					Status_Cnt_T_b16 |= D_STATUSBTSTRPCUV_CNT_B16;
					break;
			}
		}

		(void)Rte_Call_Fet1Flt2Clk_OP_SET(STD_HIGH);
		GateDrvWaitTime(D_FFDATACLKTIME_US_U16P0);
	}

	if (0U == Status_Cnt_T_b16)
	{
		Status_Cnt_T_b16 = D_STATUSVDDUV_CNT_B16;
	}

	(void)Rte_Call_IoHwAbPortConfig_SetFet1Flt2ToOutput(FALSE);

	*StatusPtr_Cnt_T_b16 			= Status_Cnt_T_b16;

	return(FaultedPhases_Cnt_T_u16);
}


/****************************************************************************************************************************
* Name			: ReadMtrDrv2FltData
* Description	: Motor Drive 2 fault data
* Inputs		: StatusPtr_Cnt_T_b16
* Outputs		: NONE
* Usage Notes	: NA
****************************************************************************************************************************/
STATIC INLINE FUNC(uint16, SA_MTRDRVDIAG_CODE) ReadMtrDrv2FltData(	CONSTP2VAR(uint16, AUTOMATIC, SA_MTRDRVDIAG_CONST) StatusPtr_Cnt_T_b16)
{

	VAR(uint16, AUTOMATIC) FaultedPhases_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) DataHigh_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) ClockBit_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) Status_Cnt_T_b16;

	(void)Rte_Call_IoHwAbPortConfig_SetFet2Flt2ToOutput(TRUE);

	FaultedPhases_Cnt_T_u16 = 0U;
	Status_Cnt_T_b16 = 0U;

	for (ClockBit_Cnt_T_u16 = 0U; ClockBit_Cnt_T_u16 < D_NUMOFGDSTATUSBITS_CNT_U16; ClockBit_Cnt_T_u16++)
	{
		(void)Rte_Call_Fet2Flt2Clk_OP_SET(STD_LOW);
		GateDrvWaitTime(D_FFDATACLKTIME_US_U16P0);
		
		(void)Rte_Call_Fet2Flt1Data_OP_GET(&DataHigh_Cnt_T_lgc);
		
		if (TRUE == DataHigh_Cnt_T_lgc)
		{
			switch(ClockBit_Cnt_T_u16)
			{
				case D_PHASEDLOWER_CNT_U16:
					FaultedPhases_Cnt_T_u16++;
					Status_Cnt_T_b16 |= D_STATUSDLOWER_CNT_B16;
					break;
				case D_PHASEELOWER_CNT_U16:
					FaultedPhases_Cnt_T_u16++;
					Status_Cnt_T_b16 |= D_STATUSELOWER_CNT_B16;
					break;
				case D_PHASEFLOWER_CNT_U16:
					FaultedPhases_Cnt_T_u16++;
					Status_Cnt_T_b16 |= D_STATUSFLOWER_CNT_B16;
					break;
				case D_PHASEDUPPER_CNT_U16:
					FaultedPhases_Cnt_T_u16++;
					Status_Cnt_T_b16 |= D_STATUSDUPPER_CNT_B16;
					break;
				case D_PHASEEUPPER_CNT_U16:
					FaultedPhases_Cnt_T_u16++;
					Status_Cnt_T_b16 |= D_STATUSEUPPER_CNT_B16;
					break;
				case D_PHASEFUPPER_CNT_U16:
					FaultedPhases_Cnt_T_u16++;
					Status_Cnt_T_b16 |= D_STATUSFUPPER_CNT_B16;
					break;
				case D_VREGUV_CNT_U16:
					Status_Cnt_T_b16 |= D_STATUSVREGUV_CNT_B16;
					break;
				case D_BTSTRPAUV_CNT_U16:
					Status_Cnt_T_b16 |= D_STATUSBTSTRPAUV_CNT_B16;
					break;
				case D_BTSTRPBUV_CNT_U16:
					Status_Cnt_T_b16 |= D_STATUSBTSTRPBUV_CNT_B16;
					break;
				default: /* D_BTSTRPCUV_CNT_U16 */
					Status_Cnt_T_b16 |= D_STATUSBTSTRPCUV_CNT_B16;
					break;
			}
		}
		
		(void)Rte_Call_Fet2Flt2Clk_OP_SET(STD_HIGH);
		GateDrvWaitTime(D_FFDATACLKTIME_US_U16P0);
	}

	if (0U == Status_Cnt_T_b16)
	{
		Status_Cnt_T_b16 = D_STATUSVDDUV_CNT_B16;
	}

	(void)Rte_Call_IoHwAbPortConfig_SetFet2Flt2ToOutput(FALSE);

	*StatusPtr_Cnt_T_b16 			= Status_Cnt_T_b16;

	return(FaultedPhases_Cnt_T_u16);
}

 /* MISRA Comment: Msg(4:3112) This statement has no side-effect - it can be removed.
MISRA-C:2004 Rule 14.2 as osek.h is just a stub so no return values or conditions specified*/

/****************************************************************************************************************************
* Name			: ResetGateDriveABC
* Description	: Reset for gate drive 1
* Inputs		: NONE
* Outputs		: NONE
* Usage Notes	: NA
****************************************************************************************************************************/
STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) ResetGateDriveABC(void)
{
	SuspendAllInterrupts(); /* PRQA S 3112 EOF */ /* see MISRA comment above */

	(void)Rte_Call_FetDrvResetABC_OP_SET(STD_LOW);
	GateDrvWaitTime(D_GDRESETTIME_US_U16P0);
	(void)Rte_Call_FetDrvResetABC_OP_SET(STD_HIGH);

	ResumeAllInterrupts();/* PRQA S 3112 EOF */ /* see MISRA comment above */
}


/****************************************************************************************************************************
* Name			: ResetGateDriveDEF
* Description	: Reset for gate drive 2
* Inputs		: NONE
* Outputs		: NONE
* Usage Notes	: NA
****************************************************************************************************************************/
STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) ResetGateDriveDEF(void)
{
	SuspendAllInterrupts(); /* PRQA S 3112 EOF */ /* see MISRA comment above */

	(void)Rte_Call_FetDrvResetDEF_OP_SET(STD_LOW);
	GateDrvWaitTime(D_GDRESETTIME_US_U16P0);
	(void)Rte_Call_FetDrvResetDEF_OP_SET(STD_HIGH);

	ResumeAllInterrupts();/* PRQA S 3112 EOF */ /* see MISRA comment above */
}

/****************************************************************************************************************************
* Name			: GateDrvWaitTime
* Description	: Delay time
* Inputs		: NONE
* Outputs		: NONE
* Usage Notes	: NA
****************************************************************************************************************************/
STATIC INLINE FUNC(void, SA_MTRDRVDIAG_CODE) GateDrvWaitTime(	VAR(uint16, AUTOMATIC) TimeToWait_uS_T_u16p0)
{
	VAR(uint32, AUTOMATIC) WaitStartTime_uS_T_u32p0;
	VAR(uint16, AUTOMATIC) WaitElapsedTime_uS_T_u16p0;

	(void)Rte_Call_SystemTime_GetSystemTime_uS_u32(&WaitStartTime_uS_T_u32p0);
	do
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(WaitStartTime_uS_T_u32p0, &WaitElapsedTime_uS_T_u16p0);
	}
	while(WaitElapsedTime_uS_T_u16p0 < TimeToWait_uS_T_u16p0);
}


/****  Motor driver 1 Initialization  ****/
/****************************************************************************************************************************
* Name			: MotorDriver1Init
* Description	: NA
* Inputs		: NONE
* Outputs		: NONE
* Usage Notes	: NA
****************************************************************************************************************************/
STATIC INLINE FUNC(boolean, SA_MTRDRVDIAG_CODE) MotorDriver1Init(void)
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;
	VAR(boolean, AUTOMATIC) MtrDrv1InitComp_Cnt_T_lgc;

	if (FALSE == SVDiag_MtrDrv1InitActive_Cnt_M_lgc)
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SVDiag_MtrDrv1InitStartTime_mS_M_u32p0);
		SVDiag_MtrDrv1InitActive_Cnt_M_lgc = TRUE;
	}

	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(SVDiag_MtrDrv1InitStartTime_mS_M_u32p0, &ElapsedTime_mS_T_u16p0);
	if (ElapsedTime_mS_T_u16p0  > D_MTRDRVINITDELAY_MS_U08)
	{
		ResetGateDriveABC();
		MtrDrv1InitComp_Cnt_T_lgc = TRUE;
		SVDiag_MtrDrv1InitActive_Cnt_M_lgc = FALSE;
	}
	else
	{
		MtrDrv1InitComp_Cnt_T_lgc = FALSE;
	}

	return(MtrDrv1InitComp_Cnt_T_lgc);
}


/****  Motor driver 2 Initialization  ****/
/****************************************************************************************************************************
* Name			: MotorDriver2Init
* Description	: NA
* Inputs		: NONE
* Outputs		: NONE
* Usage Notes	: NA
****************************************************************************************************************************/
STATIC INLINE FUNC(boolean, SA_MTRDRVDIAG_CODE) MotorDriver2Init(void)
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;
	VAR(boolean, AUTOMATIC) MtrDrv2InitComp_Cnt_T_lgc;
	
	if (FALSE == SVDiag_MtrDrv2InitActive_Cnt_M_lgc)
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SVDiag_MtrDrv2InitStartTime_mS_M_u32p0);
		SVDiag_MtrDrv2InitActive_Cnt_M_lgc = TRUE;
	}
	
	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(SVDiag_MtrDrv2InitStartTime_mS_M_u32p0, &ElapsedTime_mS_T_u16p0);
	if (ElapsedTime_mS_T_u16p0  > D_MTRDRVINITDELAY_MS_U08)
	{
		ResetGateDriveDEF();
		MtrDrv2InitComp_Cnt_T_lgc = TRUE;
		SVDiag_MtrDrv2InitActive_Cnt_M_lgc = FALSE;
	}
	else
	{
		MtrDrv2InitComp_Cnt_T_lgc = FALSE;
	}
	
	return(MtrDrv2InitComp_Cnt_T_lgc);
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
