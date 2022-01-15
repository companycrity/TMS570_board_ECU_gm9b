/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_MotMeclPosn2.c
 *     Workspace:  C:/Rijvi_Synergy_EA3/Core_Component/Working/MotMeclPosn2/autosar
 *     SW-C Type:  Sa_MotMeclPosn2
 *  Generated at:  Mon Feb 22 17:08:28 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_MotMeclPosn2>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*
 * Copyright 2016 Nexteer Automotive
 * Nexteer Confidential
 *
 * Version Control:
* Date Created:      Mon Aug 3 13:41:03 2015
* %version:          6 %
* %derived_by:       jzk9cc %
* %date_modified:    Mon Feb 22 13:41:03 2016
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  -------------------------------------------------------------------------------  ------
 * 08/19/15  1.0 	 BDO       Initial Version FDD ES60A v01 (ICR EA3#423)                                       EA3#1651
 * 08/26/15  2.0 	 BDO       Correct rolling counter MotMeclPosn2_RollgCntr_Cnt_M_u08 update.                  EA3#1651
 * 09/29/15  3.0 	 BDO       Anomaly 3515 - Correct SEGMENT mask in TblSeg2 and TblSeg3 Scom write functions   EA3#3518
 * 10/02/15  4.0     JK        Anomaly fix 3562 - MotMeclPosn2 missing offset                                    EA3#3585
 * 10/14/15  5.0     JK        Anomaly fix 3568 - Wrong NTC number used for 0x071                                EA3#3851
 * 22/02/16  6.0 	 Rijvi     Implement rev. 5 of the design                                                    EA3#3953 
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

#include "Rte_Sa_MotMeclPosn2.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* MISRA-C:2004 Rule 8.7: This deviation is required to keep the memory map intact. Rule suppressed by line at each occurrence. */

/* MISRA-C:2004 Rule 10.3: This deviation is required because of Nexteer macro library. Rule suppressed by line at each occurrence. */

/* MISRA-C:2004 Rule 10.4: This deviation is required because of Nexteer macro library. Rule suppressed by line at each occurrence. */

/* MISRA-C: 2004 Rule 11.4: This deviation is required because of Crc_CalculateCRC16(). Rule suppressed by line at each occurrence. */

/* MISRA-C:2004 Rule 19.1: This deviation is required for AUTOSAR memory map requirements.  Rule suppressed by line at each occurrence. */

/* MISRA-C:2004 Rule 19.7: This deviation required as function like macro is called from faster loop. Rule suppressed by line at each occurrence. */

/* MISRA-C:2004 Rule 21.1: 2985 - This deviation was added as mask is specified in FDD, although redundant warning could have been ignored. Rule suppressed by line at each occurrence. */


#include "MotMeclPosn2_Cfg.h"
#include "Sa_MotMeclPosn2.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include "SystemTime.h"
#include "Crc.h"		/* Needed for Crc_CalculateCRC16() */
#include "SinCos.h"     /* Needed for SinCos_Uls_f32() */
#include "float.h"		/* Needed for constant FLT_EPSILON */


/*** SPI Register Configuration: SPI data is bundled into 2 groups: ***/
/* PWM Group: */
#define D_PWMGRPWRD0_CNT_U16   				0x200U		/* Read Turns Counter Register 	*/  
#define D_PWMGRPWRD1_CNT_U16  				0U          /* Read Position Register 	 	*/  
#define D_PWMGRPWRD2_CNT_U16  				0x400U   	/* Read Error Register 		 	*/  

/* Asynchronous Config Group */
#define D_ASYNCCONFIGGRPWRD0_CNT_U16 		0x8800U     /* Write to Control Base Registers 	*/  
#define D_ASYNCCONFIGGRPWRD1_CNT_U16  		0x800U      /* Read the Control Register 		*/  
#define D_ASYNCCONFIGGRPWRD2_CNT_U16 		0x400U		/* Read Error Information 		 	*/  

/* PWM Group */
#define D_TURNSCNTRINDEX_CNT_U16   			0U			/* First word transmitted is a request to Read Turns Counter Register 	*/
#define D_POSITIONINDEX_CNT_U16  			1U       	/* Second word transmitted is a request to Read Position Register 		*/
#define D_ERRORREGINDEX_CNT_U16  			2U   		/* Third word transmitted is a request to Read Error Register 			*/

/* Asynchronous Config Group */
#define D_WRITECONFIGREGINDEX_CNT_U16   	0U			/* First word transmitted is a Config Register Write                  	*/
#define D_READCONFIGREGINDEX_CNT_U16  		1U       	/* Second word transmitted is a request to Read the Config Register	 	*/
#define D_READERRORINFOINDEX_CNT_U16  		2U   		/* Third word transmitted is a request to Read Error Information 		*/

/* SPI received data - Rx Buffer contains 3 messages - Rx Buffer Message order depends on order of the Transmit Buffer Messages */
#define D_RAWERRORREGINDEX_CNT_U16			0U			/* Message at array position "0" is used for Error Register Processing 	*/
#define D_RAWTURNSCOUNTERREGINDEX_CNT_U16	1U			/* Message at array position "1" is used for Rev Centre Processing 	  	*/
#define D_RAWPOSITIONREGINDEX_CNT_U16		2U			/* Message at array position "2" is used for Motor Position Processing 	*/

#define D_UNDERVLTGFLTBITMASK_CNT_U16		0x4000U  
#define D_SNSRAGERRMASK_CNT_U08				0x16U  

#define D_MOTMECLPOSNERRTHRES_CNT_U16		50U
#define D_MOTMECLPOSNERRPSTEP_CNT_U16		5U
#define D_MOTMECLPOSNERRNSTEP_CNT_U16		1U

#define D_CORRNTBLSIZE_CNT_U16   			128U 
#define D_CORRNTBLAGSTEPSIZE_MTRRAD_F32		0.04908738521F  
#define D_COEFFTBLELMSIZE_CNT_U08			2U  
#define D_COEFFTBLSIZE_CNT_U08				13U  
#define D_CORRNTBLSIDXOFFS_CNT_U16 			7U  
#define D_CORRNTBLSIZEMASK_CNT_U08  		127U   
#define D_COEFFTBLSIZEINBYTES_CNT_U08  		104U  
#define D_CRCFAIL_CNT_U08  					1U  
#define D_CRCPASS_CNT_U08  					0U  
#define D_MOTAGDELTAPERCORRNPT_CNT_U16 		512U  
#define D_MOTAGIDXMASK_CNT_U16 				65024U  
#define D_SIXTEENBITMAXVAL_CNT_U16          65535U 
#define D_COEFFTBLSIZE_CNT_U16   			26U 

#define D_MOTMECLPOSN2OFFS_REVM_U0P16       (FPM_InitFixedPoint_m(0.5F, u0p16_T)) 

#define ParityCalculation_m(data) (((T_PARITYTABLE_CNT_U8[(data) & 0xFFu] + T_PARITYTABLE_CNT_U8[((data) >> 8u) & 0xFFu]) ^ 1u) & 1u) /* PRQA S 3453 */


#define MOTMECLPOSN2_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AUTOMATIC) MotMeclPosn2_PWMGrpData_Cnt_M_u16[3];						/* PRQA S 3218 */ /* MISRA-C:2004 Rule 8.7: This deviation is required for Module Level Variable */
STATIC VAR(uint16, AUTOMATIC) MotMeclPosn2_AsyncConfigGrpDie2_Cnt_M_u16[3];
STATIC VAR(uint16, AUTOMATIC) MotMeclPosn2_ErrorAcc_Cnt_M_u16;
STATIC VAR(uint16, AUTOMATIC) MotMeclPosn2_ErrParFltCntr_Cnt_M_u16;						/* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC) MotMeclPosn2_ErrParFltCntrPrev_Cnt_M_u16;					/* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC) MotMeclPosn2_ParityFaultAccumPrev_Cnt_M_u16;				/* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC) MotMeclPosn2_UnderVltgFaultAccumPrev_Cnt_M_u16;			/* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC) MotMeclPosn2_MotMeclPosn2Raw_RevM_M_u0p16;				/* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC) MotMeclPosn2_UnderVltgFaultAccum_Cnt_M_u16;				/* PRQA S 3218 */
STATIC VAR(uint16, AUTOMATIC) MotMeclPosn2_ParityFaultAccum_Cnt_M_u16;					/* PRQA S 3218 */
STATIC volatile VAR(uint16, AUTOMATIC) MotMeclPosn2_RawErrorReg_Cnt_D_u16;				/* PRQA S 3218 */
STATIC volatile VAR(uint16, AUTOMATIC) MotMeclPosn2_RawTurnsCounterReg_Cnt_D_u16;		/* PRQA S 3218 */
STATIC volatile VAR(uint16, AUTOMATIC) MotMeclPosn2_RawPositionReg_Cnt_D_u16;			/* PRQA S 3218 */
#define MOTMECLPOSN2_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define MOTMECLPOSN2_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AUTOMATIC) MotMeclPosn2_EnableAsyncConfigGrp_Cnt_M_lgc;
#define MOTMECLPOSN2_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */


#define MOTMECLPOSN2_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint8, AUTOMATIC) MotMeclPosn2_HarCompTbl_RevM_M_sm5p12[128];	
STATIC VAR(uint8, AUTOMATIC) MotMeclPosn2_Err_Cnt_M_u08;								/* PRQA S 3218 */
STATIC VAR(uint8, AUTOMATIC) MotMeclPosn2_RollgCntr_Cnt_M_u08;							/* PRQA S 3218 */
#define MOTMECLPOSN2_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */


#define MOTMECLPOSN2_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(SigQlfr_State_enum,  AUTOMATIC) MotMeclPosn2_MotPosnQlfr_Cnt_M_enum;
STATIC VAR(DiagSettings_Str,   AUTOMATIC) MotMeclPosn2_Err_Cnt_M_str;
#define MOTMECLPOSN2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


STATIC INLINE FUNC(uint16, SA_MOTMECLPOSN2_CODE) ProcessRxMtrPos( VAR(uint16, AUTOMATIC) MotMeclPosn2RxReg_Cnt_T_u16,
															      P2VAR(uint8, AUTOMATIC, AUTOMATIC) MotMeclPosn2UnderVltgFault_Cnt_T_u08,
															      P2VAR(uint8, AUTOMATIC, AUTOMATIC) MotMeclPosn2ParityFault_Cnt_T_u08);

STATIC INLINE FUNC(uint8, SA_MOTMECLPOSN2_CODE) ProcessErrorReg( VAR(uint16, AUTOMATIC) RxMsg_Cnt_T_u16,
														         P2VAR(uint8, AUTOMATIC, AUTOMATIC) RxErrorRegParityFault_Cnt_T_u08 );
																 
STATIC INLINE FUNC(void, SA_MOTMECLPOSN2_CODE) CalcCorrnTbl( void );


#define MOTMECLPOSN2_START_SEC_CONST_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC CONST(uint8, AUTOMATIC) T_PARITYTABLE_CNT_U8[256]  = { 0u,1u,1u,0u,1u,0u,0u,1u,1u,0u,0u,1u,0u,1u,1u,0u,
															  1u,0u,0u,1u,0u,1u,1u,0u,0u,1u,1u,0u,1u,0u,0u,1u,
															  1u,0u,0u,1u,0u,1u,1u,0u,0u,1u,1u,0u,1u,0u,0u,1u,
															  0u,1u,1u,0u,1u,0u,0u,1u,1u,0u,0u,1u,0u,1u,1u,0u,
															  1u,0u,0u,1u,0u,1u,1u,0u,0u,1u,1u,0u,1u,0u,0u,1u,
															  0u,1u,1u,0u,1u,0u,0u,1u,1u,0u,0u,1u,0u,1u,1u,0u,
															  0u,1u,1u,0u,1u,0u,0u,1u,1u,0u,0u,1u,0u,1u,1u,0u,
															  1u,0u,0u,1u,0u,1u,1u,0u,0u,1u,1u,0u,1u,0u,0u,1u,
															  1u,0u,0u,1u,0u,1u,1u,0u,0u,1u,1u,0u,1u,0u,0u,1u,
															  0u,1u,1u,0u,1u,0u,0u,1u,1u,0u,0u,1u,0u,1u,1u,0u,
															  0u,1u,1u,0u,1u,0u,0u,1u,1u,0u,0u,1u,0u,1u,1u,0u,
															  1u,0u,0u,1u,0u,1u,1u,0u,0u,1u,1u,0u,1u,0u,0u,1u,
															  0u,1u,1u,0u,1u,0u,0u,1u,1u,0u,0u,1u,0u,1u,1u,0u,
															  1u,0u,0u,1u,0u,1u,1u,0u,0u,1u,1u,0u,1u,0u,0u,1u,
															  1u,0u,0u,1u,0u,1u,1u,0u,0u,1u,1u,0u,1u,0u,0u,1u,
															  0u,1u,1u,0u,1u,0u,0u,1u,1u,0u,0u,1u,0u,1u,1u,0u };
#define MOTMECLPOSN2_STOP_SEC_CONST_8
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
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
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
 * DT_MotMeclPosnCoeffTbl_f32: Array with 26 element(s) of type Float
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
 * Float: D_2PI_ULS_F32 = 6.2831853071796
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SigQlfr_State_enum: D_SIGQLFRNORES_CNT_ENUM = 0u
 * UInt16: D_ONE_CNT_U16 = 1u
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
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Float *Rte_Pim_MotMeclPosn2CoeffTblData(void)
#else
 *   DT_MotMeclPosnCoeffTbl_f32 *Rte_Pim_MotMeclPosn2CoeffTblData(void)
#endif
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_MOTMECLPOSN2_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotMeclPosn2_Init
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
 *   Std_ReturnType Rte_Call_MotMeclPosn2CoeffTblBlk_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MOTMECLPOSN2_APPL_CODE) MotMeclPosn2_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotMeclPosn2_Init
 *********************************************************************************************************************/
	
	VAR(NvM_RequestResultType,  AUTOMATIC) NvMBlkStatus_Cnt_T_u08;

	
	MotMeclPosn2_Err_Cnt_M_str.Threshold = D_MOTMECLPOSNERRTHRES_CNT_U16;
	MotMeclPosn2_Err_Cnt_M_str.PStep = D_MOTMECLPOSNERRPSTEP_CNT_U16;
	MotMeclPosn2_Err_Cnt_M_str.NStep = D_MOTMECLPOSNERRNSTEP_CNT_U16;
	
	MotMeclPosn2_ErrorAcc_Cnt_M_u16 = MotMeclPosn2_Err_Cnt_M_str.Threshold/2U;

	MotMeclPosn2_MotPosnQlfr_Cnt_M_enum = SIGQLFR_NORES;

	
	
	(void) Rte_Call_MotMeclPosn2CoeffTblBlk_GetErrorStatus( &NvMBlkStatus_Cnt_T_u08 );
	
	if( NvMBlkStatus_Cnt_T_u08 == NVM_REQ_OK )
	{	/* NVM is OK. */

		CalcCorrnTbl(); 
	}
	else
	{	/* NVM is not OK. */
		
		/* No action is required. Default value of "MotMeclPosn2_HarCompTbl_RevM_M_sm5p12" will be used (i.e all zeros). */
	}
	
	
	
	/* PWM Group: */
	MotMeclPosn2_PWMGrpData_Cnt_M_u16[D_TURNSCNTRINDEX_CNT_U16] = D_PWMGRPWRD0_CNT_U16;	/* Read Turns Counter Register */
	MotMeclPosn2_PWMGrpData_Cnt_M_u16[D_POSITIONINDEX_CNT_U16] = D_PWMGRPWRD1_CNT_U16;	/* Read Position Register */
	MotMeclPosn2_PWMGrpData_Cnt_M_u16[D_ERRORREGINDEX_CNT_U16] = D_PWMGRPWRD2_CNT_U16;	/* Read Error Register */

	/* Asynchronous Config Group */
	MotMeclPosn2_AsyncConfigGrpDie2_Cnt_M_u16[D_READCONFIGREGINDEX_CNT_U16] = D_ASYNCCONFIGGRPWRD1_CNT_U16;	/* Read the Control Register */
	MotMeclPosn2_AsyncConfigGrpDie2_Cnt_M_u16[D_READERRORINFOINDEX_CNT_U16] = D_ASYNCCONFIGGRPWRD2_CNT_U16;	/* Read Error Information */

	/* Set Tx Buffer for MSB2 */
	MSB2SetData(MotMeclPosn2_PWMGrpData_Cnt_M_u16); /* The actual function is implemented in SpiNxt component */
	MSB2EnableDataTransfer(); 						/* The actual function is implemented in SpiNxt component */
	

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotMeclPosn2_Per2
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
 *   UInt16 Rte_IRead_MotMeclPosn2_Per2_MotMeclPosn2RawErrReg_Cnt_u16(void)
 *   UInt16 Rte_IRead_MotMeclPosn2_Per2_ParityFaultAccum_Cnt_u16(void)
 *   UInt16 Rte_IRead_MotMeclPosn2_Per2_UnderVltgFaultAccum_Cnt_u16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MotMeclPosn2_Per2_MotPosnQlfr_State_enum(SigQlfr_State_enum data)
 *   SigQlfr_State_enum *Rte_IWriteRef_MotMeclPosn2_Per2_MotPosnQlfr_State_enum(void)
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

FUNC(void, RTE_SA_MOTMECLPOSN2_APPL_CODE) MotMeclPosn2_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotMeclPosn2_Per2
 *********************************************************************************************************************/

	VAR(uint16,  AUTOMATIC) MotMeclPosn2RawErrReg_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) UnderVltgFaultAccum_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) ParityFaultAccum_Cnt_T_u16;
	VAR(uint8,   AUTOMATIC) ErrorReg_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) RxErrorRegParityFault_Cnt_T_u08;
	VAR(uint8,   AUTOMATIC) ProtFltNTC071ParamByte_Cnt_T_u08;


	MotMeclPosn2RawErrReg_Cnt_T_u16 = Rte_IRead_MotMeclPosn2_Per2_MotMeclPosn2RawErrReg_Cnt_u16();
	UnderVltgFaultAccum_Cnt_T_u16 = Rte_IRead_MotMeclPosn2_Per2_UnderVltgFaultAccum_Cnt_u16();
	ParityFaultAccum_Cnt_T_u16 = Rte_IRead_MotMeclPosn2_Per2_ParityFaultAccum_Cnt_u16();

	/* Process Error Reg */
	/* Process MotAg1RawErr */
	ErrorReg_Cnt_T_u08 = ProcessErrorReg(MotMeclPosn2RawErrReg_Cnt_T_u16, &RxErrorRegParityFault_Cnt_T_u08);

	/* FDD calls for data conversion to UINT16, however UINT8 'Fault' is only checked against zero. Output of logic is UINT16 as in FDD */
	if (RxErrorRegParityFault_Cnt_T_u08 != D_ZERO_CNT_U8)
	{
		/* FDD expects FltCntr to rollover back to zero if fault persists */
		MotMeclPosn2_ErrParFltCntr_Cnt_M_u16++;
	}
	else
	{
		MotMeclPosn2_Err_Cnt_M_u08 = ErrorReg_Cnt_T_u08;
	}

	/* MotMeclPosn2 Protocol Fault Operation */
	ProtFltNTC071ParamByte_Cnt_T_u08 = (MotMeclPosn2_Err_Cnt_M_u08 & D_SNSRAGERRMASK_CNT_U08);

	if (MotMeclPosn2_ErrParFltCntr_Cnt_M_u16 != MotMeclPosn2_ErrParFltCntrPrev_Cnt_M_u16)
	{
		ProtFltNTC071ParamByte_Cnt_T_u08 |= (uint8)(D_ONE_CNT_U8 << 7U);
	}

	if (ParityFaultAccum_Cnt_T_u16 != MotMeclPosn2_ParityFaultAccumPrev_Cnt_M_u16)
	{
		ProtFltNTC071ParamByte_Cnt_T_u08 |= (uint8)(D_ONE_CNT_U8 << 6U);
	}

	if (UnderVltgFaultAccum_Cnt_T_u16 != MotMeclPosn2_UnderVltgFaultAccumPrev_Cnt_M_u16)
	{
		ProtFltNTC071ParamByte_Cnt_T_u08 |= (uint8)(D_ONE_CNT_U8 << 5U);
	}

	if (ProtFltNTC071ParamByte_Cnt_T_u08 != D_ZERO_CNT_U8) /* FDD TestOk_lgc check */
	{
		/* FDD: TestOk_lgc FALSE */
		MotMeclPosn2_ErrorAcc_Cnt_M_u16 = DiagPStep_m(MotMeclPosn2_ErrorAcc_Cnt_M_u16, MotMeclPosn2_Err_Cnt_M_str);

		if (DiagFailed_m(MotMeclPosn2_ErrorAcc_Cnt_M_u16, MotMeclPosn2_Err_Cnt_M_str) == TRUE)
		{
			MotMeclPosn2_MotPosnQlfr_Cnt_M_enum = SIGQLFR_FAIL;
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_SecMSB_SinCosCorr, ProtFltNTC071ParamByte_Cnt_T_u08, NTC_STATUS_FAILED);
		}
	}
	else
	{
		/* FDD: TestOk_lgc TRUE */
		MotMeclPosn2_ErrorAcc_Cnt_M_u16 = DiagNStep_m(MotMeclPosn2_ErrorAcc_Cnt_M_u16, MotMeclPosn2_Err_Cnt_M_str);

		if (MotMeclPosn2_ErrorAcc_Cnt_M_u16 == D_ZERO_CNT_U16)
		{
			MotMeclPosn2_MotPosnQlfr_Cnt_M_enum = SIGQLFR_PASS;
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_SecMSB_SinCosCorr, 0U, NTC_STATUS_PASSED);
		}
	}

	MotMeclPosn2_ErrParFltCntrPrev_Cnt_M_u16 = MotMeclPosn2_ErrParFltCntr_Cnt_M_u16;
	MotMeclPosn2_ParityFaultAccumPrev_Cnt_M_u16 = ParityFaultAccum_Cnt_T_u16;
	MotMeclPosn2_UnderVltgFaultAccumPrev_Cnt_M_u16 = UnderVltgFaultAccum_Cnt_T_u16;

	Rte_IWrite_MotMeclPosn2_Per2_MotPosnQlfr_State_enum(MotMeclPosn2_MotPosnQlfr_Cnt_M_enum);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotMeclPosn2_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MOTMECLPOSN2_APPL_CODE) MotMeclPosn2_Per3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotMeclPosn2_Per3
 *********************************************************************************************************************/
	
	VAR(uint8,  AUTOMATIC) MotPosnQlfr_Cnt_T_u08;
	
	MotPosnQlfr_Cnt_T_u08 = ((MotMeclPosn2_MotPosnQlfr_Cnt_M_enum == SIGQLFR_FAIL) ? D_ONE_CNT_U8 : D_ZERO_CNT_U8);

	/* Asynchronous Config Group */
	/* Add control register config and reset IC errors to transmit group */
	MotMeclPosn2_AsyncConfigGrpDie2_Cnt_M_u16[D_WRITECONFIGREGINDEX_CNT_U16] = D_ASYNCCONFIGGRPWRD0_CNT_U16 | MotPosnQlfr_Cnt_T_u08;	/* First word transmitted is a Config Register Write */
	
	MSB2SetConfig(MotMeclPosn2_AsyncConfigGrpDie2_Cnt_M_u16); /* The actual function is implemented in SpiNxt component */
	
	MotMeclPosn2_EnableAsyncConfigGrp_Cnt_M_lgc = TRUE;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotMeclPosn2_Scom_ReadMotMeclPosn2CoeffTbl
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadMotMeclPosn2CoeffTbl> of PortPrototype <MotMeclPosn2_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void MotMeclPosn2_Scom_ReadMotMeclPosn2CoeffTbl(Float *MotMeclPosn2CoeffTbl, UInt16 *MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed)
#else
 *   void MotMeclPosn2_Scom_ReadMotMeclPosn2CoeffTbl(DT_MotMeclPosnCoeffTbl_f32 *MotMeclPosn2CoeffTbl, UInt16 *MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_MOTMECLPOSN2_APPL_CODE) MotMeclPosn2_Scom_ReadMotMeclPosn2CoeffTbl(P2VAR(Float, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTbl, P2VAR(UInt16, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed)
#else
FUNC(void, RTE_SA_MOTMECLPOSN2_APPL_CODE) MotMeclPosn2_Scom_ReadMotMeclPosn2CoeffTbl(P2VAR(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTbl, P2VAR(UInt16, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotMeclPosn2_Scom_ReadMotMeclPosn2CoeffTbl
 *********************************************************************************************************************/

	VAR(uint8, 	AUTOMATIC)  Index_Cnt_T_u08;


	for( Index_Cnt_T_u08 = 0U; Index_Cnt_T_u08 < D_COEFFTBLSIZE_CNT_U16; Index_Cnt_T_u08++ )
	{
		(*MotMeclPosn2CoeffTbl)[Index_Cnt_T_u08] = (*(Rte_Pim_MotMeclPosn2CoeffTblData()))[Index_Cnt_T_u08];
	}
	
	*MotMeclPosn2CoeffTblCRC = Crc_CalculateCRC16( (Crc_DataRefType)Rte_Pim_MotMeclPosn2CoeffTblData(), (uint32)D_COEFFTBLSIZEINBYTES_CNT_U08, MotMeclPosn2CoeffTblCRCSeed );  /* PRQA S 0310 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteMotMeclPosn2CoeffTbl> of PortPrototype <MotMeclPosn2_Scom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_MotMeclPosn2CoeffTblBlk_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_MotMeclPosn2CoeffTblBlk_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(const Float *MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, UInt8 *MotMeclPosn2CoeffTblResp)
#else
 *   void MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(const DT_MotMeclPosnCoeffTbl_f32 *MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, UInt8 *MotMeclPosn2CoeffTblResp)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_SA_MOTMECLPOSN2_APPL_CODE) MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(P2CONST(Float, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_DATA) MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTblResp)
#else
FUNC(void, RTE_SA_MOTMECLPOSN2_APPL_CODE) MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(P2CONST(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_DATA) MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_SA_MOTMECLPOSN2_APPL_VAR) MotMeclPosn2CoeffTblResp)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl
 *********************************************************************************************************************/

	VAR(uint16,  AUTOMATIC)  CalcCRC_Cnt_T_u16;
	VAR(uint8, 	 AUTOMATIC)  Index_Cnt_T_u08;

	
	CalcCRC_Cnt_T_u16 = Crc_CalculateCRC16( (Crc_DataRefType)MotMeclPosn2CoeffTbl, (uint32)D_COEFFTBLSIZEINBYTES_CNT_U08, MotMeclPosn2CoeffTblCRCSeed );  /* PRQA S 0310 */

	if( CalcCRC_Cnt_T_u16 == MotMeclPosn2CoeffTblCRC )
	{
		for( Index_Cnt_T_u08 = 0U; Index_Cnt_T_u08 < D_COEFFTBLSIZE_CNT_U16; Index_Cnt_T_u08++ )
		{
			(*(Rte_Pim_MotMeclPosn2CoeffTblData()))[Index_Cnt_T_u08] = (*MotMeclPosn2CoeffTbl)[Index_Cnt_T_u08];
		}
		
		(void) Rte_Call_MotMeclPosn2CoeffTblBlk_WriteBlock( NULL_PTR );
	
		*MotMeclPosn2CoeffTblResp = D_CRCPASS_CNT_U08;
	}
	else
	{
		*MotMeclPosn2CoeffTblResp = D_CRCFAIL_CNT_U08; 
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_MOTMECLPOSN2_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/******************************************************
Function: MotMeclPosn2_Per1
Trigger:  62.5us - MtrCtrl ISR
Output:   MechMtrPos1UnCorr
		  MechMtrPos1UnCorrTimeStamp
Functionality: Main 62.5us processing
******************************************************/
FUNC(void, SA_MOTMECLPOSN2_CODE) MotMeclPosn2_Per1(void)
{
	VAR(uint16, AUTOMATIC) MSB2RxData_Cnt_T_u16[3];
	VAR(sint8,  AUTOMATIC) MotMeclPosn2Polarity_Cnt_T_s08;

	VAR(uint16,  AUTOMATIC) MotMeclPosn2Raw_RevM_T_u0p16;
	VAR(uint8,  AUTOMATIC) MotMeclPosn2UnderVltgFault_Cnt_T_u08;
	VAR(uint8,  AUTOMATIC) MotMeclPosn2ParityFault_Cnt_T_u08;
	
	VAR(uint16, AUTOMATIC) MotMeclPosn2_RevM_T_u0p16;
	
	/* Name 'MotAg1' corresponds to name 'MotMeclPosn2' */
	VAR(uint16, AUTOMATIC)  MotAg1Corrd_Cnt_T_u0p16;
	VAR(sint8,  AUTOMATIC)  MotAg1CorrnA_MotRev_T_sm5p12;
	VAR(sint32, AUTOMATIC)  MotAg1CorrnA_MotRev_T_s19p12;
	VAR(sint8,  AUTOMATIC)  MotAg1CorrnB_MotRev_T_sm5p12;
	VAR(sint32, AUTOMATIC)  MotAg1CorrnB_MotRev_T_s19p12;
	VAR(uint16, AUTOMATIC)  MotAg1Gain_Uls_T_u12p4;
	VAR(sint32, AUTOMATIC)  MotAg1CorrnTerm_Cnt_T_s15p16;



	/* FDD 61A - has Uls_s08 type but polarity FDD and component has Cnt_s08 */
	MotMeclPosn2_Read_MotMeclPosn2Polarity_Cnt_s08(&MotMeclPosn2Polarity_Cnt_T_s08);
	
	/* MSB2 Rx Data */
	/* Address of Start of Array is passed inside the macro */
	MSB2GetData(MSB2RxData_Cnt_T_u16);  /* The actual function is implemented in SpiNxt component */

	if (MotMeclPosn2_EnableAsyncConfigGrp_Cnt_M_lgc == TRUE)
	{
		MSB2EnableConfigTransfer(); /* The actual function is implemented in SpiNxt component */
		MotMeclPosn2_EnableAsyncConfigGrp_Cnt_M_lgc = FALSE;
	}

	/*Process the SPI received data
		Rx Buffer contains 3 messages
		Rx Buffer Message order depends on the order of Transmit Buffer Messages
		Message at array position  "0" is used for Error Register Processing
		Message at array position  "1" is used for Rev Centre Processing
		Message at array position  "2" is used for Motor Position Processing  	  */

	MotMeclPosn2_RawErrorReg_Cnt_D_u16 = MSB2RxData_Cnt_T_u16[D_RAWERRORREGINDEX_CNT_U16];
	MotMeclPosn2_RawTurnsCounterReg_Cnt_D_u16 = MSB2RxData_Cnt_T_u16[D_RAWTURNSCOUNTERREGINDEX_CNT_U16];
	MotMeclPosn2_RawPositionReg_Cnt_D_u16 = MSB2RxData_Cnt_T_u16[D_RAWPOSITIONREGINDEX_CNT_U16];
	
	/* Process MotMeclPosn2Raw */
	/* Process RxMtrPos */
	MotMeclPosn2Raw_RevM_T_u0p16 = ProcessRxMtrPos(MSB2RxData_Cnt_T_u16[D_RAWPOSITIONREGINDEX_CNT_U16],
			                                     &MotMeclPosn2UnderVltgFault_Cnt_T_u08,
			                                     &MotMeclPosn2ParityFault_Cnt_T_u08);

	/* FDD calls for data conversion to UINT16, however UINT8 'Fault' is only checked against zero. Output of logic is UINT16 as in FDD */
	if (MotMeclPosn2UnderVltgFault_Cnt_T_u08 != D_ZERO_CNT_U8)
	{
		/* FDD expects FltAccum to rollover back to zero if fault persists */
		MotMeclPosn2_UnderVltgFaultAccum_Cnt_M_u16++;
	}

	/* FDD calls for data conversion to UINT16, however UINT8 'Fault' is only checked against zero. Output of logic is UINT16 as in FDD */
	if (MotMeclPosn2ParityFault_Cnt_T_u08 != D_ZERO_CNT_U8)
	{
		/* FDD expects FltAccum to rollover back to zero if fault persists */
		MotMeclPosn2_ParityFaultAccum_Cnt_M_u16++;
	}

	if ( (MotMeclPosn2UnderVltgFault_Cnt_T_u08 + MotMeclPosn2ParityFault_Cnt_T_u08) == D_ZERO_CNT_U8 )
	{
		MotMeclPosn2_MotMeclPosn2Raw_RevM_M_u0p16 = MotMeclPosn2Raw_RevM_T_u0p16;

		/* FDD expects RollCntr to rollover back to zero */
		MotMeclPosn2_RollgCntr_Cnt_M_u08++;
	}

	
	/*** ------------------------------------------------------------------------------------------------------------- ***/
	/***** -------------------------------- START: Process MotMeclPosn2_RevM_u0p16 --------------------------------- *****/
	/*** ------------------------------------------------------------------------------------------------------------- ***/
	/* Masking is redundant, but used to match the design */
	MotAg1CorrnA_MotRev_T_sm5p12 = MotMeclPosn2_HarCompTbl_RevM_M_sm5p12[(MotMeclPosn2_MotMeclPosn2Raw_RevM_M_u0p16 >> 9U) & D_CORRNTBLSIZEMASK_CNT_U08]; /* PRQA S 2985 */
	MotAg1CorrnA_MotRev_T_s19p12 = (sint32) MotAg1CorrnA_MotRev_T_sm5p12;
	MotAg1CorrnB_MotRev_T_sm5p12 = MotMeclPosn2_HarCompTbl_RevM_M_sm5p12[((MotMeclPosn2_MotMeclPosn2Raw_RevM_M_u0p16 + D_MOTAGDELTAPERCORRNPT_CNT_U16) >> 9U) & D_CORRNTBLSIZEMASK_CNT_U08]; /* PRQA S 2985 */
	MotAg1CorrnB_MotRev_T_s19p12 = (sint32) MotAg1CorrnB_MotRev_T_sm5p12;
	MotAg1Gain_Uls_T_u12p4 = (MotMeclPosn2_MotMeclPosn2Raw_RevM_M_u0p16 - (MotMeclPosn2_MotMeclPosn2Raw_RevM_M_u0p16 & D_MOTAGIDXMASK_CNT_U16)) >> 5U;
	
	
	MotAg1CorrnTerm_Cnt_T_s15p16 =  ((MotAg1CorrnB_MotRev_T_s19p12 - MotAg1CorrnA_MotRev_T_s19p12) * (sint32) MotAg1Gain_Uls_T_u12p4) + (sint32)(uint32)((uint32)MotAg1CorrnA_MotRev_T_s19p12 << 4U);
	
	
	/* Roll-over and typecasting from sign to unsigned is intentional here to implement part of the 'Normalize MechMtrPos' block */
	MotAg1Corrd_Cnt_T_u0p16 = MotMeclPosn2_MotMeclPosn2Raw_RevM_M_u0p16 - (uint16)MotAg1CorrnTerm_Cnt_T_s15p16 - D_MOTMECLPOSN2OFFS_REVM_U0P16;  
	
		
	if( MotMeclPosn2Polarity_Cnt_T_s08 < 0 )
	{
		MotMeclPosn2_RevM_T_u0p16 = D_SIXTEENBITMAXVAL_CNT_U16 - MotAg1Corrd_Cnt_T_u0p16;  
	}
	else
	{
		MotMeclPosn2_RevM_T_u0p16 = MotAg1Corrd_Cnt_T_u0p16;
	}
	/*** ------------------------------------------------------------------------------------------------------------- ***/
	/***** --------------------------------   END: Process MotMeclPosn2_RevM_u0p16 --------------------------------- *****/
	/*** ------------------------------------------------------------------------------------------------------------- ***/
	
	
	/* Outputs */
	MotMeclPosn2_Write_MotMeclPosn2RawErrReg_Cnt_u16((MSB2RxData_Cnt_T_u16[D_RAWERRORREGINDEX_CNT_U16]));
	MotMeclPosn2_Write_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16(MotMeclPosn2_UnderVltgFaultAccum_Cnt_M_u16);
	MotMeclPosn2_Write_MotMeclPosn2ParityFaultAccum_Cnt_u16(MotMeclPosn2_ParityFaultAccum_Cnt_M_u16);
	MotMeclPosn2_Write_MotMeclPosn2RevM_u0p16(MotMeclPosn2_RevM_T_u0p16);
	MotMeclPosn2_Write_MotMeclPosn2RollgCntr_Cnt_u08(MotMeclPosn2_RollgCntr_Cnt_M_u08);

}


/******************************************************
Function: 		ProcessErrorReg
Input :   		Rx MotMeclPosn2RawErrReg
Output:   		ErrorReg Flag and ParityFault
Functionality: 	Process the error register data from SPI
******************************************************/
STATIC INLINE FUNC(uint8, SA_MOTMECLPOSN2_CODE) ProcessErrorReg( VAR(uint16, AUTOMATIC) RxMsg_Cnt_T_u16,
														         P2VAR(uint8, AUTOMATIC, AUTOMATIC) RxErrorRegParityFault_Cnt_T_u08 )
{
	VAR(uint8, AUTOMATIC) ErrorReg_Cnt_T_u08;

	*RxErrorRegParityFault_Cnt_T_u08 = ParityCalculation_m(RxMsg_Cnt_T_u16); /* PRQA S 2985 */
	ErrorReg_Cnt_T_u08 = (uint8)((RxMsg_Cnt_T_u16 >> 1u) & 0x1Fu);

	return(ErrorReg_Cnt_T_u08);
}


/******************************************************
Function:		ProcessRxMtrPos
Input :  		Rx Motor Position
Output: 		Motor Position, Parity and under voltage fault
Functionality:  Process the Motor Position from the SPI
******************************************************/
STATIC INLINE FUNC(uint16, SA_MOTMECLPOSN2_CODE) ProcessRxMtrPos( VAR(uint16, AUTOMATIC) MotMeclPosn2RxReg_Cnt_T_u16,
															      P2VAR(uint8, AUTOMATIC, AUTOMATIC) MotMeclPosn2UnderVltgFault_Cnt_T_u08,
															      P2VAR(uint8, AUTOMATIC, AUTOMATIC) MotMeclPosn2ParityFault_Cnt_T_u08)
{
	VAR(uint16, AUTOMATIC) MotMeclPosn2Raw_RevM_T_u0p16;
	VAR(uint16, AUTOMATIC) MotMeclPosn2Raw_RevM_T_u3p13;

	/* Reading the under voltage fault at the appropriate bit position */
	if( (MotMeclPosn2RxReg_Cnt_T_u16 & D_UNDERVLTGFLTBITMASK_CNT_U16) > D_ZERO_CNT_U16 )
	{
		*MotMeclPosn2UnderVltgFault_Cnt_T_u08 = D_ONE_CNT_U8;
	}
	else
	{
		*MotMeclPosn2UnderVltgFault_Cnt_T_u08 = D_ZERO_CNT_U8;
	}

	/* Received Parity Check */
	*MotMeclPosn2ParityFault_Cnt_T_u08 = ParityCalculation_m(MotMeclPosn2RxReg_Cnt_T_u16); /* PRQA S 2985 */

	/* Bit shift by 1 to remove parity */
	MotMeclPosn2Raw_RevM_T_u3p13 = (uint16)((MotMeclPosn2RxReg_Cnt_T_u16 >> 1U) & 0x1FFFu);
	MotMeclPosn2Raw_RevM_T_u0p16 = FPM_Fix_m(MotMeclPosn2Raw_RevM_T_u3p13, u3p13_T, u0p16_T);	/* PRQA S 4393 */ /* PRQA S 4394 */

	return(MotMeclPosn2Raw_RevM_T_u0p16);
}




/**********************************************************************************************************************
* Name:        CalcCorrnTbl
* Description: Calculate the motor angle 1 correction table from the coefficient table.
* Inputs:      None
* Outputs:     None
* Usage Notes: None
**********************************************************************************************************************/
STATIC INLINE FUNC(void, SA_MOTMECLPOSN2_CODE) CalcCorrnTbl( void )
{
	
	VAR(uint8,  	AUTOMATIC)  TblIdx_Cnt_T_u08;
	VAR(uint8,  	AUTOMATIC)  CoeffTblIdx_Cnt_T_u08;
	VAR(float32,  	AUTOMATIC)  SinVal_Uls_T_f32;
	VAR(float32,  	AUTOMATIC)  CosVal_Uls_T_f32;
	VAR(float32,  	AUTOMATIC)  HarmAg_MotRev_T_f32;
	VAR(float32,  	AUTOMATIC)  RecnstrdWaveForm_MotRev_T_f32[D_CORRNTBLSIZE_CNT_U16];  
	VAR(uint8,  	AUTOMATIC)  LoopIdx_Cnt_T_u08;
	VAR(float32,  	AUTOMATIC)  IdxSca_MotRev_T_f32; 
	VAR(boolean,  	AUTOMATIC)  LoopIdxFound_Cnt_T_logl; 
	VAR(float32,  	AUTOMATIC)  Y1_MotRev_T_f32; 
	VAR(float32,  	AUTOMATIC)  Y2_MotRev_T_f32; 
	VAR(float32,  	AUTOMATIC)  CorrnTermFound_MotRev_T_f32; 
	VAR(float32,  	AUTOMATIC)  CorrnTermNotFound_MotRev_T_f32; 
	VAR(float32,  	AUTOMATIC)  RecnstrdWaveFormX_MotRev_T_f32; 
	VAR(float32,  	AUTOMATIC)  RecnstrdWaveFormX1_MotRev_T_f32; 
	VAR(float32,  	AUTOMATIC)  TempX_MotRev_T_f32; 
	VAR(float32,  	AUTOMATIC)  TempY_MotRev_T_f32; 
	VAR(float32,  	AUTOMATIC)  TempA_MotRev_T_f32; 
	
	
	
	
	/************************************************************************************************************/
	/*** --------------------- START:  Build Wave / Reconstructed Waveform Processing ----------------------- ***/
	/************************************************************************************************************/
	for ( TblIdx_Cnt_T_u08 = 0U; TblIdx_Cnt_T_u08 < D_CORRNTBLSIZE_CNT_U16; TblIdx_Cnt_T_u08++ )
	{
		HarmAg_MotRev_T_f32 = (float32)TblIdx_Cnt_T_u08 * D_CORRNTBLAGSTEPSIZE_MTRRAD_F32;
		
		/* Formula: for i = 0 to 127, n = 1 to 12 */
		/* RecnstrdWaveForm[i] = SUM{ CoeffTbl[2*n] * cos(AgStep*i*n) + CoeffTbl[2*n + 1] * Sin(AgStep*i*n) } */
		
		/* First term is calculated outside of the for loop to avoid the initialization of all terms to zero. */
		SinCos_Uls_f32( HarmAg_MotRev_T_f32, &SinVal_Uls_T_f32, &CosVal_Uls_T_f32 );
		RecnstrdWaveForm_MotRev_T_f32[TblIdx_Cnt_T_u08]  =  ( (*(Rte_Pim_MotMeclPosn2CoeffTblData()))[D_COEFFTBLELMSIZE_CNT_U08] * CosVal_Uls_T_f32 )
												                + ( (*(Rte_Pim_MotMeclPosn2CoeffTblData()))[D_COEFFTBLELMSIZE_CNT_U08 + 1U] * SinVal_Uls_T_f32 ) ;
		
		for ( CoeffTblIdx_Cnt_T_u08 = 2U; CoeffTblIdx_Cnt_T_u08 < D_COEFFTBLSIZE_CNT_U08; CoeffTblIdx_Cnt_T_u08++ )
		{
			
			SinCos_Uls_f32( HarmAg_MotRev_T_f32 * (float32)CoeffTblIdx_Cnt_T_u08, &SinVal_Uls_T_f32, &CosVal_Uls_T_f32 );
			RecnstrdWaveForm_MotRev_T_f32[TblIdx_Cnt_T_u08]  =  RecnstrdWaveForm_MotRev_T_f32[TblIdx_Cnt_T_u08] 
												                + (  (*(Rte_Pim_MotMeclPosn2CoeffTblData()))[CoeffTblIdx_Cnt_T_u08 * D_COEFFTBLELMSIZE_CNT_U08] * CosVal_Uls_T_f32 )
												                + ( (*(Rte_Pim_MotMeclPosn2CoeffTblData()))[(CoeffTblIdx_Cnt_T_u08 * D_COEFFTBLELMSIZE_CNT_U08) + 1U] * SinVal_Uls_T_f32 ) ;
		}
	}	
	/************************************************************************************************************/
	/*** ----------------------  END:  Build Wave / Reconstructed Waveform Processing ----------------------- ***/
	/************************************************************************************************************/
	
	
	

	
	/************************************************************************************************************/
	/*** ---------------  START:  Change Correction Coordinate / Waveform Coordinate Change ----------------- ***/
	/************************************************************************************************************/
	for ( TblIdx_Cnt_T_u08 = 0U; TblIdx_Cnt_T_u08 < D_CORRNTBLSIZE_CNT_U16; TblIdx_Cnt_T_u08++ )
	{
		LoopIdx_Cnt_T_u08 = (TblIdx_Cnt_T_u08 < D_CORRNTBLSIDXOFFS_CNT_U16) ? ( 0U ) : ( TblIdx_Cnt_T_u08 - (uint8)D_CORRNTBLSIDXOFFS_CNT_U16 ); 
		
		HarmAg_MotRev_T_f32 = (float32)TblIdx_Cnt_T_u08 * D_CORRNTBLAGSTEPSIZE_MTRRAD_F32;
		
		/* Calculate Index Scale */
		if( (RecnstrdWaveForm_MotRev_T_f32[0U] >= 0.0F) && (RecnstrdWaveForm_MotRev_T_f32[0U] > HarmAg_MotRev_T_f32) )
		{
			IdxSca_MotRev_T_f32 = HarmAg_MotRev_T_f32 + D_2PI_ULS_F32;
		}
		else if( (RecnstrdWaveForm_MotRev_T_f32[0U] + D_2PI_ULS_F32) <= HarmAg_MotRev_T_f32 )
		{
			IdxSca_MotRev_T_f32 = HarmAg_MotRev_T_f32 - D_2PI_ULS_F32;
		}
		else
		{
			IdxSca_MotRev_T_f32 = HarmAg_MotRev_T_f32;
		}
		
		
		/* Determine Non Wrapped Correction Term */
		LoopIdxFound_Cnt_T_logl = FALSE;
		do
		{
			/* Masking is redundant, but used to match the design */
			RecnstrdWaveFormX_MotRev_T_f32   =  RecnstrdWaveForm_MotRev_T_f32[LoopIdx_Cnt_T_u08 & D_CORRNTBLSIZEMASK_CNT_U08];  /* PRQA S 2985 */
			RecnstrdWaveFormX1_MotRev_T_f32  =  RecnstrdWaveForm_MotRev_T_f32[(LoopIdx_Cnt_T_u08 + 1U) & D_CORRNTBLSIZEMASK_CNT_U08];  /* PRQA S 2985 */
			
			Y1_MotRev_T_f32 = ((float32)LoopIdx_Cnt_T_u08 * D_CORRNTBLAGSTEPSIZE_MTRRAD_F32) + RecnstrdWaveFormX_MotRev_T_f32;
			Y2_MotRev_T_f32 = ((float32)LoopIdx_Cnt_T_u08 * D_CORRNTBLAGSTEPSIZE_MTRRAD_F32) + D_CORRNTBLAGSTEPSIZE_MTRRAD_F32 + RecnstrdWaveFormX1_MotRev_T_f32;
			
			if( (Y1_MotRev_T_f32 <= IdxSca_MotRev_T_f32) && (Y2_MotRev_T_f32 >= IdxSca_MotRev_T_f32) )
			{
				LoopIdxFound_Cnt_T_logl = TRUE;
				
				/* Calculate Correction Term */
				if( Abs_f32_m(Y2_MotRev_T_f32 - Y1_MotRev_T_f32) > FLT_EPSILON )   
				{	/* Denominator != 0 */
					CorrnTermFound_MotRev_T_f32 =  (  ((IdxSca_MotRev_T_f32 - Y1_MotRev_T_f32) / (Y2_MotRev_T_f32 - Y1_MotRev_T_f32))
													  * (RecnstrdWaveFormX1_MotRev_T_f32 - RecnstrdWaveFormX_MotRev_T_f32) )
											          + RecnstrdWaveFormX_MotRev_T_f32;
				}
				else
				{	/* Denominator == 0 */
					CorrnTermFound_MotRev_T_f32 = 0.0F;
				}
			}
			
			LoopIdx_Cnt_T_u08++; 
		} while( ((LoopIdx_Cnt_T_u08 + 1U) < (uint8)D_CORRNTBLSIZE_CNT_U16) && (LoopIdxFound_Cnt_T_logl == FALSE) );
		
		
		if( LoopIdxFound_Cnt_T_logl == TRUE )
		{	/* Correction Term Found */
			
			/* Convert to sm5p12 format */
			MotMeclPosn2_HarCompTbl_RevM_M_sm5p12[TblIdx_Cnt_T_u08] = FPM_FloatToFixed_m( CorrnTermFound_MotRev_T_f32, sm5p12_T );  /* PRQA S 4395 */
		}
		else
		{	/* Correction Term Not Found */
			
			TempX_MotRev_T_f32 = RecnstrdWaveForm_MotRev_T_f32[0U];
			TempY_MotRev_T_f32 = RecnstrdWaveForm_MotRev_T_f32[D_CORRNTBLSIZE_CNT_U16 - 1U];
			TempA_MotRev_T_f32 = TempY_MotRev_T_f32 + ( D_CORRNTBLAGSTEPSIZE_MTRRAD_F32 * (float32)(D_CORRNTBLSIZE_CNT_U16 - 1U) );
			
			if( Abs_f32_m(D_2PI_ULS_F32 + (TempX_MotRev_T_f32 - TempA_MotRev_T_f32)) > FLT_EPSILON )  
			{	/* Denominator != 0 */
				CorrnTermNotFound_MotRev_T_f32 = (((TempX_MotRev_T_f32 - TempY_MotRev_T_f32) * (IdxSca_MotRev_T_f32 - TempA_MotRev_T_f32)) /
											       ((D_2PI_ULS_F32 + (TempX_MotRev_T_f32 - TempA_MotRev_T_f32))))
											      + TempY_MotRev_T_f32;
			}
			else
			{	/* Denominator == 0 */
				CorrnTermNotFound_MotRev_T_f32 = 0.0F;
			}
			
			/* Convert to sm5p12 format */
			MotMeclPosn2_HarCompTbl_RevM_M_sm5p12[TblIdx_Cnt_T_u08] = FPM_FloatToFixed_m( CorrnTermNotFound_MotRev_T_f32, sm5p12_T );  /* PRQA S 4395 */
		}
		
	}
	/************************************************************************************************************/
	/*** ----------------   END:  Change Correction Coordinate / Waveform Coordinate Change ----------------- ***/
	/************************************************************************************************************/
	
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
