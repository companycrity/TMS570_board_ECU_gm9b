/**********************************************************************************************************************
* Copyright 2015 Nexteer 
* Nexteer Confidential
*
* Module File Name:   CalConstants.h
* Module Description: Calibration constant file generated from the integration data dictionary
* Project:            GM 9Bxx
* Author:             Gustavo M Nunes
***********************************************************************************************************************
* Version Control:
* %version:          EA3#50 %
* %derived_by:       fz9hxm %
**********************************************************************************************************************/

#ifndef CALCONSTANTS_H
#define CALCONSTANTS_H

#include "Rte_Type.h"
#include "fixmath.h"
#include "filters.h"
#include "Ap_DiagMgr_Types.h"

#define D_NUMOFTUNSETS_CNT_U16  8U
#define D_NUMOFPERS_CNT_U16     4U

/*********************** Start of Auto Generated Code ************************/

/****************** File Generated on 3/21/2017 1:25:40 PM *******************/
/************************* GM 9BXX Project - Rev 52 **************************/



/************* Tuning Structure Definition for "Y" Calibrations **************/

typedef struct
{
	float32	k_KinmIntDiagMaxRackLimit_HwDeg_f32;
	uint16	t_CmnVehSpd_Kph_u9p7[12];
	float32	k_AsstFWFiltKn_Hz_f32;
	float32	k_AsstFWFWActiveLPF_Hz_f32;
	float32	k_AsstFWInpLimitBaseAsst_MtrNm_f32;
	float32	k_AsstFWInpLimitHFA_MtrNm_f32;
	uint16	k_AsstFWNstep_Cnt_u16;
	uint16	k_AsstFWPstep_Cnt_u16;
	float32	k_RestoreThresh_MtrNm_f32;
	uint16	t_AsstFWDefltAssistX_HwNm_u8p8[20];
	sint16	t_AsstFWDefltAssistY_MtrNm_s4p11[20];
	uint16	t_AsstFWPstepNstepThresh_Cnt_u16[2];
	uint16	t_AsstFWVehSpd_Kph_u9p7[8];
	sint16	t2_AsstFWUprBoundX_HwNm_s4p11[8][11];
	sint16	t2_AsstFWUprBoundY_MtrNm_s4p11[8][11];
	float32	k_AvgFricLPFKn_Hz_f32;
	float32	k_BaselineEOLFric_HwNm_f32;
	float32	k_DataPrepLPFKn_Hz_f32;
	float32	k_EOLFricDiffLimitHigh_HwNm_f32;
	float32	k_EOLFricDiffLimitLow_HwNm_f32;
	float32	k_EOLFricDiffScalingFactor_Uls_f32;
	float32	k_FricOffsetLimitHigh_HwNm_f32;
	float32	k_FricOffsetLimitLow_HwNm_f32;
	float32	k_FricOffsetLPFKn_Hz_f32;
	float32	k_FrictionDiagThreshold_HwNm_f32;
	uint32	k_FrictionDiagTimer_mS_u32;
	float32	k_HwPosAuthMin_Uls_f32;
	float32	k_HwVelConstLimit_HwDegpS_f32;
	float32	k_HwVelMax_HwDegpS_f32;
	float32	k_HwVelMin_HwDegpS_f32;
	float32	k_IgnCycleFricChgLim_HwNm_f32;
	float32	k_LatAccMax_MpSecSqrd_f32;
	float32	k_LatAccMin_MpSecSqrd_f32;
	float32	k_LearningGain_Uls_f32;
	uint32	k_LearningThreshold_Cnt_u32;
	uint16	k_RangeCounterLimit_Cnt_u16;
	float32	k_SatFricChgLim_HwNm_f32;
	float32	k_TempMax_DegC_f32;
	float32	k_TempMin_DegC_f32;
	float32	t_BaselineFric_HwNm_f32[4];
	float32	t_FrHystHwAPts_HwDeg_f32[4];
	float32	t_FricChgWeight_Uls_f32[4];
	uint16	t_InvRatioX_HwDeg_u11p5[10];
	uint16	t_InvRatioY_HwNmpMtrNm_u6p10[10];
	boolean	t_MskVehSpd_Cnt_lgc[4];
	uint16	t2_BaselineRangeCounter_Cnt_u16[8][3];
	float32	t2_BaselineTheta_HwNm_f32[8][4];
	float32	t2_VehSpd_Kph_f32[4][2];
	float32	k_DampFWErrThresh_MtrNm_f32;
	float32	k_DampFWFWActiveLPF_Hz_f32;
	uint16	k_DampFWInCmpNStep_Cnt_u16;
	uint16	k_DampFWInCmpPStep_Cnt_u16;
	float32	k_DampFWInpLimitDamp_MtrNm_f32;
	uint16	k_DampFWNstep_Cnt_u16;
	uint16	k_DampFWPstep_Cnt_u16;
	float32	k_DampFWVBICLPF_Hz_f32;
	float32	k_DmpBoundLPFKn_Hz_f32;
	uint16	t_DampFWAddDampAFWX_MtrRadpS_u11p5[8];
	uint16	t_DampFWAddDampAFWY_MtrNm_u5p11[8];
	uint16	t_DampFWAddDampDFWX_MtrRadpS_u11p5[8];
	uint16	t_DampFWAddDampDFWY_MtrNm_u5p11[8];
	uint16	t_DampFWDampInrtCmpPNThesh_Cnt_u16[2];
	uint16	t_DampFWDefltDampX_MtrRadpS_u11p5[11];
	uint16	t_DampFWDefltDampY_MtrNm_u5p11[11];
	uint16	t_DampFWPNstepThresh_Cnt_u16[2];
	sint16	t_DampFWUprBoundX_MtrRadpS_s11p4[11];
	uint16	t_DampFWVehSpd_Kph_u9p7[8];
	sint16	t2_DampFWUprBoundY_MtrNm_s7p8[8][11];
	float32	k_PosTrajMaxAngle_HwDeg_f32;
	float32	k_Mode1AssistDD_Uls_f32;
	float32	k_Mode1EngTransThresh_Rpm_f32;
	float32	k_Mode1VehSpdTransThresh_Kph_f32;
	float32	k_Mode2AssistDD_Uls_f32;
	float32	k_Mode2VehSpdTransThresh_Kph_f32;
	float32	k_NormalModeEngTransThresh_Rpm_f32;
	float32	k_NormalModeVehSpdTransThresh_Kph_f32;
	float32	k_StopMode1HwTrqTransThresh_HwNm_f32;
	float32	k_StopMode1VehSpdTransThres_Kph_f32;
	float32	k_StopMode2HwTrqTransThresh_HwNm_f32;
	float32	k_StopMode2VehSpdTransThresh_Kph_f32;
	float32	k_StopModeAssistDD_Uls_f32;
	uint32	k_GmPpChk_PwrpkCmpbltyChkRefTiThd_mS_u32;
	uint16	k_EOTThrmPrtLPFKn_Cnt_u16;
	float32	k_EOTThrmSlwLmtStp_MtrNm_f32;
	uint16	t_EOTThrmDpntTbl_MtrNm_u8p8[4];
	uint16	t_EOTThrmIndptTbl_MtrNm_u8p8[4];
	float32	k_AbsMtrVelBkt_MtrRadps_f32;
	float32	k_NoofPoles_Uls_f32;
	float32	k_CLOAFdbackSignalSclFacSlew_UlspS_f32;
	float32	k_CuThermCoeff_OhmpDegC_f32;
	float32	k_deadtimeVScale_Uls_f32;
	float32	k_DualEcuSignalSclFacSlew_UlspS_f32;
	uint16	k_EstPkCurr2msLPFKn_Uls_u16;
	uint16	k_EstPkCurrSlowLoopLPFKn_Uls_u16;
	float32	k_Harmonic12thElec_Uls_f32;
	float32	k_Harmonic6thElec_Uls_f32;
	float32	k_IdBoostGain_Uls_f32;
	float32	k_IdBoostVRThreshScl_Uls_f32;
	uint16	k_IdqRefIminNIter_Cnt_u16;
	float32	k_IdqRefIminTol_Amp_f32;
	uint16	k_IdqRefLocateRefNIter_Cnt_u16;
	uint16	k_IdqRefTrqNIter_Cnt_u16;
	float32	k_IdqRefTrqTol_Rad_f32;
	float32	k_ILOAFdbackSignalSclFacSlew_UlspS_f32;
	float32	k_InstMtrDirHyst_Deg_f32;
	float32	k_KeSatSclAdj_Uls_f32;
	float32	k_MagThrC_VpRadpSpDegC_f32;
	float32	k_MaxKeRngLmt_VpRadpS_f32;
	float32	k_MaxLdRngLmt_Henry_f32;
	float32	k_MaxLqRngLmt_Henry_f32;
	float32	k_MaxRRngLmt_Ohm_f32;
	float32	k_MaxTrqCmdScl_Uls_f32;
	float32	k_MinKeRngLmt_VpRadpS_f32;
	float32	k_MinLdRngLmt_Henry_f32;
	float32	k_MinLqRngLmt_Henry_f32;
	float32	k_MinRRngLmt_Ohm_f32;
	float32	k_MinTrqCmdScl_Uls_f32;
	boolean	k_MtrCtrlCurrLoopSecOrTranFcEnable_Cnt_lgc;
	boolean	k_MtrCtrlFeedbackControlDisable_Cnt_lgc;
	float32	k_MtrCtrlVirualResDax_Ohm_f32;
	float32	k_MtrCtrlVirualResQax_Ohm_f32;
	float32	k_MtrCurrDaxMaxValScl_Per_f32;
	boolean	k_MtrCurrQaxRefModifDsb_Cnt_lgc;
	float32	k_MtrDampingRatioDax_Uls_f32;
	float32	k_MtrDampingRatioQax_Uls_f32;
	float32	k_MtrPosComputationDelay_Sec_f32;
	float32	k_MtrVoltDervFiltCoeffTimeCons_Sec_f32;
	float32	k_NomLd_Henry_f32;
	float32	k_NomLdFltAdj_Henry_f32;
	float32	k_NomLq_Henry_f32;
	float32	k_NomLqFltAdj_Henry_f32;
	float32	k_NomRfet_Ohm_f32;
	float32	k_NomTemp_DegC_f32;
	float32	k_PIGainVspdCutoff_kph_f32;
	float32	k_PiSamplingTs_Sec_f32;
	float32	k_SiThermCoeff_OhmpDegC_f32;
	uint16	t_CurrParamCompDaxRef_Amp_u9p7[6];
	uint16	t_CurrParamCompQaxRef_Amp_u9p7[7];
	uint16	t_KeSatTblX_Amp_u9p7[16];
	uint16	t_KeSatTblY_Uls_u2p14[16];
	uint16	t_MtrCurrDaxRpl_Amp_u9p7[10];
	uint16	t_MtrCurrQaxRpl_Amp_u9p7[12];
	uint16	t_Q13VltgSchedXTbl_MtrRadpS_u12p4[10];
	uint16	t_Q13VltgSchedYTbl_Volt_u5p11[10];
	uint16	t_Q24VltgSchedXTbl_MtrRadpS_u12p4[10];
	uint16	t_Q24VltgSchedYTbl_Volt_u5p11[10];
	float32	t_RefDeltaPoints_Rad_f32[8];
	uint16	t_TrqRplCogRampDown12thY_Uls_u0p16[4];
	uint16	t_TrqRplCogRampDown6thY_Uls_u0p16[4];
	uint16	t_TrqRplCogRampDownVoltSatX_Uls_u0p16[4];
	uint16	t2_CurrParamLdSatSclFac_Uls_u2p14[6][7];
	uint16	t2_CurrParamLqSatSclFac_Uls_u2p14[6][7];
	sint16	t2_MtrTrqRpl12X_MtrNm_s2p13[10][12];
	sint16	t2_MtrTrqRpl12Y_MtrNm_s2p13[10][12];
	sint16	t2_MtrTrqRpl6X_MtrNm_s2p13[10][12];
	sint16	t2_MtrTrqRpl6Y_MtrNm_s2p13[10][12];
	float32	k_AMAmbLPFKn_Hz_f32;
	float32	k_AMAmbMult_DegCpWatt_f32;
	float32	k_AmbPwrMult_WtspAmpSq_f32;
	float32	k_AmbTempScl_Uls_f32;
	float32	k_AMDampScl_NmpRadpS_f32;
	float32	k_AMLLFiltCoefB0_Uls_f32;
	float32	k_AMLLFiltCoefB1_Uls_f32;
	float32	k_AMLLFiltPoleA1_Uls_f32;
	float32	k_AssistMechSlew_DegCpS_f32;
	float32	k_CuAmbLPFKn_Hz_f32;
	float32	k_CuAmbMult_DegCpWatt_f32;
	float32	k_CuLLFiltKA1_Uls_f32;
	float32	k_CuLLFiltKB0_Uls_f32;
	float32	k_CuLLFiltKB1_Uls_f32;
	float32	k_EngTempScl_Uls_f32;
	float32	k_MagAmbLPFKn_Hz_f32;
	float32	k_MagAmbMult_DegCpWatt_f32;
	float32	k_MagLLFiltKA1_Uls_f32;
	float32	k_MagLLFiltKB0_Uls_f32;
	float32	k_MagLLFiltKB1_Uls_f32;
	float32	k_SiAmbLPFKn_Hz_f32;
	float32	k_SiAmbMult_DegCpWatt_f32;
	float32	k_SiLLFiltKA1_Uls_f32;
	float32	k_SiLLFiltKB0_Uls_f32;
	float32	k_SiLLFiltKB1_Uls_f32;
	float32	k_TrimTempAM_DegC_f32;
	float32	k_TrimTempCu_DegC_f32;
	float32	k_TrimTempMag_DegC_f32;
	float32	k_TrimTempSi_DegC_f32;
	Boolean	k_WtAvgTempDFt_Cnt_lgc;
	float32	k_PrkAstDTermKn_Hz_f32;
	float32	k_PrkAstEnableRate_pSec_f32;
	float32	k_PrkAstHwaLPFKn_Hz_f32;
	float32	k_PrkAstHwTrqLPFKn_Hz_f32;
	uint16	k_PrkAstPIDLimit_MtrNm_u9p7;
	uint16	t_HwaRateLimit_HwDegpSec_u12p4[3];
	uint16	t_PosSrvoMaxCmdX_Kph_u9p7[4];
	uint16	t_PosSrvoMaxCmdY_MtrNm_u5p11[4];
	uint16	t_PrkAstDGainY_MtrNmmSpHwDeg_u7p9[3];
	uint16	t_PrkAstDisableRateX_HwNm_u11p5[6];
	uint16	t_PrkAstDisableRateY_pSec_u12p4[6];
	uint16	t_PrkAstDmpTrqX_MtrRadpS_u11p5[13];
	uint16	t_PrkAstIGainY_MtrNmpHwDegS_u2p14[3];
	uint16	t_PrkAstITermAWLmtY_MtrNm_u9p7[3];
	uint16	t_PrkAstPGainX_HwDeg_u12p4[7];
	uint16	t_PrkAstSmoothX_Uls_u6p10[10];
	uint16	t_PrkAstSmoothY_Uls_u6p10[10];
	uint16	t_PrkAstVehSpdBS_Kph_u9p7[3];
	uint16	t2_PrkAstDmpTrqY_MtrNm_u4p12[3][13];
	uint16	t2_PrkAstPGainY_MtrNm_u9p7[3][7];
	float32	k_AsstReducLPFKn_Hz_f32;
	float32	k_FiltAsstReducTh_Uls_f32;
	float32	k_KeStdTemp_VpRadpS_f32;
	float32	k_LowVltAstRecTh_Volt_f32;
	uint16	k_LowVltAstRecTime_mS_u16;
	uint8	k_PwrLmt_NumofInverters_Cnt_u08;
	float32	k_PwrLmtMtrVelLPFKn_Hz_f32;
	float32	k_PwrLmtVecuAdjSlew_VoltspL_f32;
	float32	k_PwrLmtVecuAltFltAdj_Volt_f32;
	float32	k_SpdAdjSlewDec_MtrRadpS_f32;
	boolean	k_SpdAdjSlewEnable_Cnt_lgc;
	float32	k_SpdAdjSlewInc_MtrRadpS_f32;
	uint16	t_DLVTblX_Volt_u5p11[10];
	uint16	t_DLVTblY_MtrRadpS_u11p5[10];
	sint16	t_MtrEnvTblX_MtrRadpS_s11p4[14];
	uint16	t_MtrEnvTblY_MtrNm_u5p11[14];
	uint16	t_StdOpMtrEnvTblX_MtrRadpS_u11p5[6];
	uint16	t_StdOpMtrEnvTblY_MtrNm_u4p12[6];
	float32	k_AmbTempDflt_DegC_f32;
	uint16	k_AmbTempValTimeOut_mS_u16p0;
	float32	k_EngTempDflt_DegC_f32;
	uint16	k_EngTempValTimeOut_mS_u16p0;
	DiagSettings_Str	k_AbsTempDiag_Cnt_str;
	float32	k_AbsTmpTrqSlewLmt_MtrNm_f32;
	boolean	k_CtrlTempSlc_Cnt_lgc;
	float32	k_DefaultIgnOffTime_Sec_f32;
	uint16	k_DutyCycFltTrshld_Uls_u16p0;
	float32	k_EOCCtrlTemp_DegC_f32;
	boolean	k_IgnOffCntrEnb_Cnt_lgc;
	float32	k_IgnOffMsgWaitTime_Sec_f32;
	boolean	k_MtrPrTempSlc_Cnt_lgc;
	boolean	k_MultTempSlc_Cnt_lgc;
	boolean	k_SlowFltTempSlc_Cnt_lgc;
	uint16	k_TrqCmdSlewDown_MtrNm_u9p7;
	uint16	k_TrqCmdSlewUp_MtrNm_u9p7;
	sint16	t_AbsCtrlTmpTblX_DegC_s15p0[4];
	uint16	t_AbsCtrlTmpTblY_MtrNm_u9p7[4];
	sint16	t_AbsCuTmpTblX_DegC_s15p0[4];
	uint16	t_AbsCuTmpTblY_MtrNm_u9p7[4];
	uint16	t_LastTblValNS_MtrNm_u9p7[5];
	uint16	t_LastTblValS_MtrNm_u9p7[5];
	uint16	t_Mult1NSTblY_Uls_u3p13[5];
	uint16	t_Mult1STblY_Uls_u3p13[5];
	uint16	t_Mult2NSTblY_Uls_u3p13[5];
	uint16	t_Mult2STblY_Uls_u3p13[5];
	uint16	t_Mult3NSTblY_Uls_u3p13[5];
	uint16	t_Mult3STblY_Uls_u3p13[5];
	uint16	t_Mult4NSTblY_Uls_u3p13[5];
	uint16	t_Mult4STblY_Uls_u3p13[5];
	uint16	t_Mult5NSTblY_Uls_u3p13[5];
	uint16	t_Mult5STblY_Uls_u3p13[5];
	uint16	t_Mult6NSTblY_Uls_u3p13[5];
	uint16	t_Mult6STblY_Uls_u3p13[5];
	sint16	t_MultTblX_DegC_s15p0[5];
	uint16	t_ThrmLoadLmtTblX_Uls_u16p0[8];
	uint16	t_ThrmLoadLmtTblY_MtrNm_u9p7[8];
	float32	k_APAEnableRate_pSec_f32;
	float32	k_APASmoothHwTrqLPFKn_Hz_f32;
	boolean	k_APAUseADmpScale_lgc;
	boolean	k_APAUseAsstScale_lgc;
	boolean	k_APAUseRetScale_lgc;
	float32	k_ESCMax_HwNm_f32;
	float32	k_GmTqArbn_LKAOutpOvrlUpprLim_MtrNm_f32;
	float32	k_GmTqArbn_LKAScagGain_Uls_f32;
	uint16	t_APADisableRateX_HwNm_u4p12[6];
	uint16	t_APADisableRateY_pSec_u7p9[6];
	uint16	t_APASmoothX_Uls_u2p14[10];
	uint16	t_APASmoothY_Uls_u2p14[10];
	float32	k_APAHwTrqLPFKn_Hz_f32;
	float32	k_APAMaxHwTrq_HwNm_f32;
	float32	k_APAMaxHwTrqTime_Sec_f32;
	float32	k_APAMaxVehSpd_Kph_f32;
	float32	k_ESCMaxVehSpd_Kph_f32;
	uint32	k_GMOSH_HapticDuration_mS_u32;
	uint32	k_GMOSH_HapticReactTime_mS_u32;
	float32	k_GMOSH_HwTrqOscnLPFKn_Hz_f32;
	float32	k_GMOSH_LKAHwTrqLPFKn_Hz_f32;
	float32	k_GMOSH_LKAMaxHwTrq_HwNm_f32;
	uint32	k_GMOSH_LKAMaxHwTrqTime_mS_u32;
	uint32	k_GMOSH_LoaMtgtnHaptcFbOffTi_mS_u32;
	uint32	k_GMOSH_LoaMtgtnHaptcFbOnTi_mS_u32;
	uint32	k_GMOSH_LoaMtgtnHaptcFbStrtOnTi_mS_u32;
	float32	k_GMOSH_LoaMtgtnHaptcFbTqMax_HwNm_f32;
	float32	k_GMOSH_LoaMtgtnHaptcFbTqMin_HwNm_f32;
	float32	k_GMOSH_LoaMtgtnHaptcFbVehSpdMax_Kph_f32;
	float32	k_GMOSH_LoaMtgtnHaptcFbVehSpdMin_Kph_f32;
	float32	k_GMOSH_LoaMtgtnHaptcFrq_Hz_f32;
	float32	k_GMOSH_LoaMtgtnStrtHaptcAmp_MtrNm_f32;
	uint16	k_GMOSH_LoaStIgnCntrThd_Cnt_u16;
	float32	k_HapticAmplitude_MtrNm_f32;
	float32	k_HapticFreq_Hz_f32;
	float32	k_LKAMaxVehSpd_Kph_f32;
	float32	k_LKAMinVehSpd_Kph_f32;
	float32	k_MaxHapticReqTime_Sec_f32;
	float32	k_ShiftLevRevTime_Sec_f32;
	float32	k_StandstillThresh_Kph_f32;
	float32	k_StandstillTime_Sec_f32;
	float32	k_SWARLimiter_HwDeg_f32;
	uint16	t_GMOSH_LoaMtgtnTqOscnAmpY_MtrNm_u2p14[8];
	uint16	t_GMOSH_LoaMtgtnVehSpdX_Kph_u10p6[8];
	uint16	k_PosMaxOfstOne_HwDeg_u12p4;
	uint16	k_PosMaxOfstTwo_HwDeg_u12p4;

} TUNING_Y_Str;

/************* Tuning Structure Definition for "P" Calibrations **************/

typedef struct
{
	float32	k_EnableHwAuthMin_Uls_f32;
	uint16	t_AsstThermSclX_Cnt_u16p0[2];
	uint16	t_AsstThermSclY_Uls_u2p14[2];
	sint16	t2_AsstAsstY0_MtrNm_s4p11[12][20];
	sint16	t2_AsstAsstY1_MtrNm_s4p11[12][20];
	uint16	t2_AsstHwtX0_HwNm_u8p8[12][20];
	uint16	t2_AsstHwtX1_HwNm_u8p8[12][20];
	uint16	t2_AsstWIRBlendY_Uls_u2p14[12][5];
	uint16	t2_AsstWIRBlndX_MtrNm_u5p11[12][5];
	float32	k_HPSOutLimit_MtrNm_f32;
	uint16	t_HPSAsstLimY_MtrNm_u4p12[12];
	uint16	t_HPSscaleC1Y_Uls_u4p12[12];
	uint16	t_HPSscaleC2Y_Uls_u4p12[12];
	uint16	t_HPSscaleC3Y_Uls_u4p12[12];
	uint16	t_HPSscaleC4Y_Uls_u4p12[12];
	uint16	t_HwTrqDmpTblX_HwNm_u8p8[2];
	uint16	t_HwTrqDmpTblY_Uls_u1p15[2];
	sint16	t_TempScaleX_DegC_s8p7[11];
	uint16	t_TempScaleY_Uls_u4p12[11];
	uint16	t2_MtrVelDmpTblX_MtrRadpS_u12p4[12][13];
	uint16	t2_MtrVelDmpTblY_MtrNm_u5p11[12][13];
	uint16	t_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17[10];
	uint16	t_DmpADDCoefX_MtrNm_u4p12[10];
	uint16	t_DmpFiltKpWIRBlndY_Uls_u2p14[5];
	uint16	t_FDD_AttenTblX_MtrRadpS_u12p4[2];
	uint16	t_FDD_AttenTblY_Uls_u8p8[2];
	uint16	t_FDD_BlendTblY_Uls_u8p8[12];
	uint16	t_InrtCmp_ScaleFactorTblY_Uls_u9p7[12];
	uint16	t_InrtCmp_TBarVel_ScaleFactorTblY_Uls_u9p7[12];
	uint16	t_RIAstWIRBlndTblY_Uls_u2p14[5];
	uint16	t_WIRBlndTblX_MtrNm_u8p8[5];
	uint16	t2_FDD_ADDRollingTblYM_MtrNmpRadpS_um1p17[2][10];
	uint16	t2_FDD_FreqTblYM_Hz_u12p4[2][12];
	uint16	k_EOTDeltaTrqThrsh_HwNm_u9p7;
	uint16	k_EOTEnterLPFKn_Cnt_u16;
	uint16	k_EOTExitLPFKn_Cnt_u16;
	uint16	k_EOTImpSpdEn_Kph_u9p7;
	uint16	k_EOTStateHwTrqLPFKn_Cnt_u16;
	uint16	k_PosRampStep_HwDeg_u12p4;
	uint16	k_SpdIptScale_MtrNmpRadpS_u4p12;
	uint16	t_EOTDmpVspd_Kph_u9p7[4];
	uint16	t_EOTEnterGainVspd_Kph_u9p7[4];
	uint16	t_SpdIptTblXTbl_HwDeg_u12p4[2];
	uint16	t_SpdIptTblYTbl_MtrRadpS_u12p4[2];
	uint16	t_TrqTableX_HwNm_u8p8[2];
	uint16	t2_EOTEnterGainX_HwDeg_u12p4[4][4];
	uint16	t2_EOTEnterGainY_Uls_u1p15[4][4];
	uint16	t2_EOTExPosDepDmpTblY_MtrNmpRadps_u0p16[4][2];
	uint16	t2_EOTPosDepDmpTblY_MtrNmpRadpS_u0p16[4][2];
	uint16	t2_EOTPosDepDmpTblX_HwDeg_u12p4[4][2];
	uint16	t2_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17[2][10];
	uint16	t_LPFKnY_Hz_u7p9[12];
	uint16	t2_GainY0_MtrNmpHwNm_u3p13[12][13];
	uint16	t2_GainY1_MtrNmpHwNm_u3p13[12][13];
	uint16	t2_TorqX0_HwNm_u5p11[12][13];
	uint16	t2_TorqX1_HwNm_u5p11[12][13];
	uint16	t2_WIRBlendX_MtrNm_u4p12[12][5];
	uint16	t2_WIRBlendY_Uls_u1p15[12][5];
	float32	k_HysCmpHwTrqLPFKn_Hz_f32;
	float32	k_HysCmpLPAstLPFKn_Hz_f32;
	float32	k_HysFinalOutLPFKn_Hz_f32;
	float32	k_HysOutLIm_HwNm_f32;
	float32	k_HysRevGain_InvHwNm_f32;
	uint16	k_LpFricIpLim_HwNm_u9p7;
	uint16	t_EffLossTblY_Uls_u4p12[12];
	uint16	t_EffOffTblY_HwNm_u9p7[12];
	sint16	t_HysCompCoulFricTempScaleX_DegC_s14p1[8];
	uint16	t_HysCompCoulFricTempScaleY_HwNm_u9p7[8];
	uint16	t_HysCompCoulFricWIRBlendX_MtrNm_u8p8[6];
	uint16	t_HysCompCoulFricWIRBlendY_Uls_u2p14[6];
	uint16	t_HysCompCoulFricY_HwNm_u9p7[2][12];
	uint16	t_HysCompHysSatY_HwNm_u9p7[12];
	uint16	t_HysCompNegHysBlendX_HwNm_u9p7[5];
	uint16	t_HysCompNegHysBlendY_Uls_u2p14[5];
	uint16	t_HysCompNegHysCompX_MtrNm_u8p8[8];
	uint16	t_HysCompNegHysCompY_HwNm_u9p7[8];
	uint16	t_HysRiseTblX_HwNm_u2p14[6];
	uint16	t_HysRiseTblY_Uls_u2p14[6];
	uint16	t2_HysHwTrqBlndTblX_HwNm_u4p12[12][8];
	uint16	t2_HysHwTrqBlndTblY_Uls_u4p12[12][8];
	float32	k_GmTqArbn_LKA_OutputLim_HwNm_f32;
	boolean	k_LKAUseSlewCal_lgc;
	uint16	t_LKASlewX_Kph_u8p8[6];
	uint16	t_LKASlewY_NmpSec_u4p12[6];
	uint16	t2_GmTqArbn_LKAOutpOvrlX_HwNm_u8p8[12][20];
	uint16	t2_GmTqArbn_LKAOutpOvrlY_MtrNm_u8p8[12][20];
	float32	k_WIRVehSpdEnable_Kph_f32;

} TUNING_P_Str;


/************************** 9BXX_CZ8L9T, Wip_fz9hxm **************************/
extern CONST(uint8, CAL_CONST) k_Cal2RelNum_Cnt_u8[12];
extern CONST(uint8, CAL_CONST) k_Cal3RelNum_Cnt_u8[12];
extern CONST(uint8, CAL_CONST) k_CalRelNum_Cnt_u8[12];
extern CONST(float32, CAL_CONST) k_ClearDtcVehSpdLmt_Kph_f32;
extern CONST(uint8, CAL_CONST) k_ComprVehPartiProStr_Cnt_u8[14];
extern CONST(float32, CAL_CONST) k_CPID02VehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_CPID03LockedVehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_CPID03UnlockedVehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_CPID04LockedVehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_CPID04UnlockedVehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_CPID05CWPolarity_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_CPID05EOTTol_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_CPID05LockedVehSpdLmt_Kph_f32;
extern CONST(uint32, CAL_CONST) k_CPID05Timeout_mS_u32;
extern CONST(float32, CAL_CONST) k_CPID05UnlockedVehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_CPIDFDLockedVehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_CPIDFDUnlockedVehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_DID02VehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_DID90VehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_DID97VehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_DID98VehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_DID99VehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_DID9AVehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_DIDB4VehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_DIDCBVehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_DIDDBVehSpdLmt_Kph_f32;
extern CONST(uint8, CAL_CONST) k_DigColPsCustSetTrimLoops_Cnt_u08;
extern CONST(float32, CAL_CONST) k_DisableNormalComm28VehSpdLmt_Kph_f32;
extern CONST(float32, CAL_CONST) k_ECUResetHwTrq_HwNm_f32;
extern CONST(float32, CAL_CONST) k_ECUResetVehSpd_kph_f32;
extern CONST(float32, CAL_CONST) k_GearCfactor_MmpRev_f32;
extern CONST(uint16, CAL_CONST) k_NexteerModeTO_mS_u16p0;
extern CONST(float32, CAL_CONST) k_SrvcHwTrqLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_SrvcVehSpdLimit_Kph_f32;
extern CONST(float32, CAL_CONST) k_SteeringAngleSensorCalHwTrqLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_SteeringAngleSensorCalVehSpdLimit_Kph_f32;

/***************************** AbsHwPos_TcI2cVd ******************************/
extern CONST(float32, CAL_CONST) k_HWAtoMtrADiffLimit_HwDeg_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_HwAtoMtrAError_str;
extern CONST(float32, CAL_CONST) k_HwPosAuthorityStep_Uls_f32;
extern CONST(float32, CAL_CONST) k_HwPosOutputLPFCoeffFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_HwPosOutputLPFError_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_I2CHwAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_MaxVehCntrOffDiff_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_TurnsCntrAuthority_Uls_f32;
extern CONST(boolean, CAL_CONST) k_UseTurnsCntr_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_VehCntrOffValidLimit_HwDeg_f32;

/*********************** AbsHwPos_TcI2cVd, MtrVel_Digi ***********************/
extern CONST(float32, CAL_CONST) k_GearRatio_Uls_f32;

/************************* AbsHwPos_TcI2cVd, VehDyn **************************/
extern CONST(float32, CAL_CONST) k_HiSpdVDAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_LoSpdVDAuthority_Uls_f32;

/******************************** ActivePull *********************************/
extern CONST(float32, CAL_CONST) k_EnableHwPosMax_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_EnableHwTrqMax_HwNm_f32;
extern CONST(float32, CAL_CONST) k_EnableHwVelMax_DegpS_f32;
extern CONST(float32, CAL_CONST) k_EnableLatAccMax_MpSecSq_f32;
extern CONST(uint32, CAL_CONST) k_EnableTime_mS_u32;
extern CONST(float32, CAL_CONST) k_EnableVehSpdMax_Kph_f32;
extern CONST(float32, CAL_CONST) k_EnableVehSpdMin_Kph_f32;
extern CONST(float32, CAL_CONST) k_EnableVehSpdRateMax_KphpS_f32;
extern CONST(float32, CAL_CONST) k_EnableYawRateMax_DegpS_f32;
extern CONST(float32, CAL_CONST) k_FiltDeadband_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwNmToMtrNm_MtrNmpHwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTrqFilt_Hz_f32;
extern CONST(float32, CAL_CONST) k_LTFilt_Hz_f32;
extern CONST(float32, CAL_CONST) k_LTIntInputLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_LTLearnTime_Min_f32;
extern CONST(float32, CAL_CONST) k_LTLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_OutputMaxRate_HwNmpS_f32;
extern CONST(float32, CAL_CONST) k_PullCmp_LTIntgtrStCorrnGain_Uls_f32;
extern CONST(float32, CAL_CONST) k_PullCmp_STIntgtrStCorrnGain_Uls_f32;
extern CONST(float32, CAL_CONST) k_STFilt_Hz_f32;
extern CONST(float32, CAL_CONST) k_STIntInputLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_STLearnTimeDec_Sec_f32;
extern CONST(float32, CAL_CONST) k_STLearnTimeInc_Sec_f32;
extern CONST(float32, CAL_CONST) k_STLimit_HwNm_f32;
extern CONST(uint32, CAL_CONST) k_STOppSignTime_mS_u32;
extern CONST(float32, CAL_CONST) k_STRampTime_Sec_f32;
extern CONST(float32, CAL_CONST) k_STResetHwPos_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_STResetHwTrq_HwNm_f32;
extern CONST(float32, CAL_CONST) k_STResetLatAcc_MpSecSq_f32;
extern CONST(float32, CAL_CONST) k_STResetYawRate_DegpS_f32;
extern CONST(float32, CAL_CONST) k_TotalLimit_HwNm_f32;
extern CONST(float32, CAL_CONST) k_YawRateFilt_Hz_f32;
extern CONST(uint16, CAL_CONST) t_VehSpdScaleTblX_Kph_u9p7[4];
extern CONST(uint16, CAL_CONST) t_VehSpdScaleTblY_Uls_u2p14[4];

/************************************ Adc ************************************/
extern CONST(uint16, CAL_CONST) k_MaxADCConvTime_uS_u16;
extern CONST(uint32, CAL_CONST) k_VbattOVTransIntConfig_Cnt_u32;

/********************************* AnaHwTrq **********************************/
extern CONST(float32, CAL_CONST) k_AnaHwTrqSclNom_VoltspDeg_f32;
extern CONST(uint8, CAL_CONST) k_AnaTrqErrorNstep_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_AnaTrqErrorPstep_Cnt_u08;
extern CONST(float32, CAL_CONST) k_MaxHwTrqTrim_Volts_f32;
extern CONST(float32, CAL_CONST) k_T1HghRange_Volts_f32;
extern CONST(float32, CAL_CONST) k_T1LowRange_Volts_f32;
extern CONST(float32, CAL_CONST) k_T2HghRange_Volts_f32;
extern CONST(float32, CAL_CONST) k_T2LowRange_Volts_f32;
extern CONST(float32, CAL_CONST) k_TbarStiff_NmpDeg_f32;

/****************************** AssistFirewall *******************************/
extern CONST(float32, CAL_CONST) k_AsstFWInpLimitHysComp_MtrNm_f32;

/********************************* AstLmt_CM *********************************/
extern CONST(float32, CAL_CONST) k_SumLim_CmdSftyLimr_MtrNm_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_SumLim_LrnPnCtrDebounce_Cnt_str;

/********************************* BattVltg **********************************/
extern CONST(float32, CAL_CONST) k_BrdgVltgMax_Volt_f32;

/************************* BattVltg, BattVltgCorrln **************************/
extern CONST(float32, CAL_CONST) k_BattVltgCorrlnSysMinVltg_Volt_f32;
extern CONST(float32, CAL_CONST) k_BattVltgSwdMax_Volt_f32;

/****************************** BattVltgCorrln *******************************/
extern CONST(float32, CAL_CONST) k_BattVltgCorrlnAllwdVltgDif_Volt_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_BattVltgCorrlnFlt_Cnt_str;

/********************************** BVDiag ***********************************/
extern CONST(uint16, CAL_CONST) k_LowDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LowDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_LowNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_LowNotDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_OvDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_OvDetect_Volts_u10p6;
extern CONST(uint16, CAL_CONST) k_OvNotDetect_ms_u16p0;
extern CONST(uint16, CAL_CONST) k_OvNotDetect_Volts_u10p6;

/************************* C1xx, IoHwAbstractionUsr **************************/
extern CONST(float32, CAL_CONST) k_ADCVbattSwitchScaling_Uls_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_SlowADCValidDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_VrefMax_Volts_f32;
extern CONST(float32, CAL_CONST) k_VrefMin_Volts_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_VrefOORDiag_Cnt_str;

/******************************* CmMtrCurr3Phs *******************************/
extern CONST(float32, CAL_CONST) k_CurrCorrErrThresh_Amps_f32;
extern CONST(float32, CAL_CONST) k_CurrGainNumerator_Amp_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_CurrMeasCorrLim_Cnt_str;
extern CONST(float32, CAL_CONST) k_CurrMeasCorrlnErrorThresh_Amp_f32;
extern CONST(uint16, CAL_CONST) k_CurrOffGainKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CurrOffNoofAvg_Cnt_u16;
extern CONST(float32, CAL_CONST) k_MaxCurrOffMtrVel_RadpS_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMaxGain_AmppVolt_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMaxOffset_Volt_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMinGain_AmppVolt_f32;
extern CONST(float32, CAL_CONST) k_MtrCurrEOLMinOffset_Volt_f32;
extern CONST(uint16, CAL_CONST) k_MtrCurrOffLoComOff_Cnt_u16;
extern CONST(float32, CAL_CONST) k_MtrPosComputDelay_Sec_f32;

/******************************** CMS_Common *********************************/
extern CONST(sint8, CAL_CONST) k_CMSGotoPosPol_Cnt_s08;
extern CONST(boolean, CAL_CONST) k_CyberSecNexteerCheckEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_F00FHandsOnThres_HwNm_f32;
extern CONST(boolean, CAL_CONST) k_FreezeMECFD1BEnable_Cnt_lgc;
extern CONST(uint16, CAL_CONST) k_NxtrSrvcHandsOnTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_NxtrSrvcPosTrajHoldTime_mS_u16;
extern CONST(float32, CAL_CONST) k_NxtrSrvcPosTrajThres_HwDeg_f32;
extern CONST(boolean, CAL_CONST) k_VehSpdZeroCheckEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_VehSpdZeroThreshold_Kph_f32;

/***************************** CommonCal, TrqLOA *****************************/
extern CONST(float, CAL_CONST) k_Cmn_VehWhlBas_mm_f32;

/********************************* ComplErr **********************************/
extern CONST(uint16, CAL_CONST) t_CompErrMtrPosNonLinComplDepTbl_HwDegpMtrNm_u8p8[6];
extern CONST(uint16, CAL_CONST) t_ComplErrMtrPosNonLinComplIndTbl_MtrNm_u5p11[6];

/******************************** CtrldVelRtn ********************************/
extern CONST(boolean, CAL_CONST) k_Rtn_DampgEnable_Cnt_Lgc;
extern CONST(boolean, CAL_CONST) k_Rtn_DampgScaEnable_Cnt_Lgc;
extern CONST(float32, CAL_CONST) k_Rtn_DesVelLPFKn_Hz_f32;
extern CONST(boolean, CAL_CONST) k_Rtn_DrvTrqEnable_Cnt_Lgc;
extern CONST(float32, CAL_CONST) k_Rtn_HwAuthySlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_Rtn_HwTrqLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_Rtn_Kb_Uls_f32;
extern CONST(float32, CAL_CONST) k_Rtn_OffsRng_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_Rtn_OffsSlew_HwDegpS_f32;
extern CONST(float32, CAL_CONST) k_Rtn_Polarity_Uls_f32;
extern CONST(float32, CAL_CONST) k_Rtn_ScaLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_Rtn_SelHwTrqScaSlewDec_UlspS_f32;
extern CONST(float32, CAL_CONST) k_Rtn_SelHwTrqScaSlewInc_UlspS_f32;
extern CONST(float32, CAL_CONST) k_Rtn_SelHwTrqScaTrqThr_HwNm_f32;
extern CONST(float32, CAL_CONST) k_Rtn_SelHwTrqScaVelThr_HwDegpS_f32;
extern CONST(boolean, CAL_CONST) k_Rtn_TrqGrdtScaEnable_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_Rtn_VelErrScaEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) t_Rtn_DrvTrqMtrxC_Uls_f32[5];
extern CONST(float32, CAL_CONST) t_Rtn_DrvTrqMtrxD_Uls_f32[4];
extern CONST(uint16, CAL_CONST) t_Rtn_HwAuthyScaX_Uls_u2p14[4];
extern CONST(uint16, CAL_CONST) t_Rtn_HwAuthyScaY_Uls_u2p14[4];
extern CONST(uint16, CAL_CONST) t_Rtn_Ki_Uls_u8p8[8];
extern CONST(uint16, CAL_CONST) t_Rtn_Kp_Uls_u4p12[8];
extern CONST(uint16, CAL_CONST) t_Rtn_OutpLimTblY_MtrNm_u4p12[8];
extern CONST(uint16, CAL_CONST) t_Rtn_PosScaX_HwDeg_u12p4[9];
extern CONST(uint16, CAL_CONST) t_Rtn_PosScaY_Uls_u2p14[9];
extern CONST(uint16, CAL_CONST) t_Rtn_ScaFacVehSpdTbl_Kph_u9p7[5];
extern CONST(uint16, CAL_CONST) t_Rtn_VehSpdTbl_Kph_u9p7[8];
extern CONST(sint16, CAL_CONST) t_Rtn_VelErrorScaX_HwDegpS_s10p5[8];
extern CONST(uint16, CAL_CONST) t_Rtn_VelErrorScaZ_HwDeg_u12p4[7];
extern CONST(uint16, CAL_CONST) t_Rtn_VelErrVehSpdScaY_Uls_u2p14[5];
extern CONST(uint16, CAL_CONST) t2_Rtn_DampgTblX_HwDegpS_u10p6[8][9];
extern CONST(uint16, CAL_CONST) t2_Rtn_DampgTblY_HwNm_u6p10[8][9];
extern CONST(uint16, CAL_CONST) t2_Rtn_DesVelScaX_HwNm_u8p8[5][8];
extern CONST(uint16, CAL_CONST) t2_Rtn_DesVelScaY_Uls_u2p14[5][8];
extern CONST(uint16, CAL_CONST) t2_Rtn_DesVelX_HwDeg_u12p4[8][12];
extern CONST(uint16, CAL_CONST) t2_Rtn_DesVelY_HwDegpS_u10p6[8][12];
extern CONST(float32, CAL_CONST) t2_Rtn_DrvTrqMtrxA_Uls_f32[5][5];
extern CONST(float32, CAL_CONST) t2_Rtn_DrvTrqMtrxB_Uls_f32[5][4];
extern CONST(uint16, CAL_CONST) t2_Rtn_HwTrqSca1X_HwNm_u8p8[5][10];
extern CONST(uint16, CAL_CONST) t2_Rtn_HwTrqSca1Y_Uls_u2p14[5][10];
extern CONST(uint16, CAL_CONST) t2_Rtn_HwTrqSca2X_HwNm_u8p8[5][10];
extern CONST(uint16, CAL_CONST) t2_Rtn_HwTrqSca2Y_Uls_u2p14[5][10];
extern CONST(uint16, CAL_CONST) t2_Rtn_IntgtrLimTblY_HwNm_u6p10[5][9];
extern CONST(uint16, CAL_CONST) t2_Rtn_TBarTrqScaX_HwNm_u8p8[5][8];
extern CONST(uint16, CAL_CONST) t2_Rtn_TBarTrqScaY_Uls_u2p14[5][8];
extern CONST(uint16, CAL_CONST) t2_Rtn_TrqGrdtScaX_HwNmpS_u8p8[5][8];
extern CONST(uint16, CAL_CONST) t2_Rtn_TrqGrdtScaY_Uls_u2p14[5][8];
extern CONST(uint16, CAL_CONST) t2_Rtn_VelErrorScaY_Uls_u2p14[7][8];

/************************* CtrldVelRtn, SnsrOffsLrng *************************/
extern CONST(float32, CAL_CONST) k_Cmn_SysTrqRatio_HwNmpMtrNm_f32;

/********************************* CtrlTemp **********************************/
extern CONST(boolean, CAL_CONST) k_CustDiagAmbLowEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_CustDiagAmbLowThresh_DegC_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_TempSensDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_TempSensHighLimit_DegC_f32;
extern CONST(float32, CAL_CONST) k_TempSensLowLimit_DegC_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrDefVal_DegC_f32;
extern CONST(boolean, CAL_CONST) k_TempSnsrFiltDft_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_TempSnsrLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrOffset_Volts_f32;
extern CONST(float32, CAL_CONST) k_TempSnsrScaling_DegpVolt_f32;

/********************************** Damping **********************************/
extern CONST(float32, CAL_CONST) k_HPSbaseC1_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC2_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC3_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_HPSbaseC4_MtrNmpMtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_MtrVelDampLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_QDDHwTrqBckLash_HwNm_f32;
extern CONST(float32, CAL_CONST) k_QddHwTrqDampKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_QDDMtrVelBckLash_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_QddMtrVelDampKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_QddSfLFPKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_Quad13DmpMult_Uls_f32;
extern CONST(float32, CAL_CONST) k_Quad24DmpMult_Uls_f32;

/******************** DampingFirewall, FrqDepDmpnInrtCmp *********************/
extern CONST(float32, CAL_CONST) k_CmnSysKinRatio_MtrDegpHwDeg_f32;
extern CONST(float32, CAL_CONST) k_CmnTbarStiff_NmpDeg_f32;
extern CONST(float32, CAL_CONST) k_DmpDecelGain_Uls_f32;
extern CONST(float32, CAL_CONST) k_DmpDecelGainFSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_DmpGainOffThresh_KphpS_f32;
extern CONST(float32, CAL_CONST) k_DmpGainOnThresh_KphpS_f32;
extern CONST(float32, CAL_CONST) k_InrtCmp_MtrInertia_KgmSq_f32;
extern CONST(float32, CAL_CONST) k_InrtCmp_MtrVel_ScaleFactor_Uls_f32;
extern CONST(float32, CAL_CONST) k_InrtCmp_TBarVelLPFKn_Hz_f32;
extern CONST(uint16, CAL_CONST) t_DmpDecelGainSlewX_MtrRadpS_u11p5[6];
extern CONST(uint16, CAL_CONST) t_DmpDecelGainSlewY_UlspS_u13p3[6];

/*********************************** DemIf ***********************************/
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask40514B_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask405158_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask40515A_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask50A954_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask51D200_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask51EF00_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask543700_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask54374B_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask544A00_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask544B42_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask551203_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask551207_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask551212_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMask559700_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC07300_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC07700_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC10000_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC10100_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC12100_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC14000_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC15900_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC26A00_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC40171_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC40271_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC41571_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC42271_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC45A71_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskC56B71_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskD83300_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_CtcInhibitMaskE50271_Cnt_u16;

/********************************** DiagMgr **********************************/
extern CONST(float32, CAL_CONST) k_FltRmpRate_UlspmS_f32[13];
extern CONST(FltRsp_Str, CAL_CONST) k_FltRspTbl_Cnt_str[512];
extern CONST(uint32* const, CAL_CONST) t_BlkBoxGrp_Ptr_u32[7][3];
extern CONST(NTCLatch_Str, CAL_CONST) t_LatchFaults_Cnt_str[8];
extern CONST(NTCNumber, CAL_CONST) t_SortedNTCs_Cnt_enum[256];

/********************************* DigColPs **********************************/
extern CONST(float32, CAL_CONST) k_ColAngSenseLPFFc_Hz_f32;
extern CONST(uint8, CAL_CONST) k_ColSensorI2CAddress_Cnt_u08;
extern CONST(float32, CAL_CONST) k_I2CHWInitTransactionTime_Sec_f32;
extern CONST(uint8, CAL_CONST) k_ReInitMaxTryCntr_Cnt_u08;
extern CONST(boolean, CAL_CONST) k_SelectFromColumn_Cnt_lgc;
extern CONST(DiagSettings_Str, CAL_CONST) k_SkipStepErrDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_SpurAngSenseLPFFc_Hz_f32;
extern CONST(uint8, CAL_CONST) k_SpurSensorI2CAddress_Cnt_u08;
extern CONST(float32, CAL_CONST) k_StepDetect_Deg_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_VernCorrErrorDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_VernCorrErrorThresh_Deg_f32;
extern CONST(float32, CAL_CONST) k_VernOORangeThresh_Deg_f32;

/******************************** DigMSBArbn *********************************/
extern CONST(uint8, CAL_CONST) k_DigMSBAR_MtrPos1MaxStall_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_DigMSBAR_MtrPos2MaxStall_Cnt_u08;

/********************************** ElePwr ***********************************/
extern CONST(float32, CAL_CONST) k_CntlrInResist_Ohm_f32;
extern CONST(float32, CAL_CONST) k_PstcPowerLoss_Watt_f32;

/****************************** EOTActuatorMng *******************************/
extern CONST(uint16, CAL_CONST) k_EOTDefltPosition_HwDeg_u12p4;
extern CONST(Boolean, CAL_CONST) k_EOTOriginalImpactandSoftEnd_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_EOTPosDepDempFinalSlew_MtrNmpS_T_f32;
extern CONST(uint16, CAL_CONST) k_MaxRackTrvl_HwDeg_u12p4;
extern CONST(Boolean, CAL_CONST) k_SoftStopEOTEnable_Cnt_lgc;

/************************** EOTActuatorMng, EtDmpFw **************************/
extern CONST(uint16, CAL_CONST) k_EOTDynConf_Uls_u8p8;
extern CONST(uint16, CAL_CONST) k_MinRackTrvl_HwDeg_u12p4;

/********************************** ePWM_Up **********************************/
extern CONST(sint16, CAL_CONST) k_ADCTrig1Offset_Cnt_s16;
extern CONST(uint16, CAL_CONST) k_PwmDeadBand_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PwmRelay_Cnt_u16;

/********************************** EtDmpFw **********************************/
extern CONST(float32, CAL_CONST) k_EOTDmpFWInactiveLim_MtrNm_f32;
extern CONST(sint16, CAL_CONST) t_EOTDmpFWActiveBoundX_MtrRadpS_s11p4[5];
extern CONST(uint16, CAL_CONST) t_EOTDmpFWVehSpd_Kph_u9p7[4];
extern CONST(sint16, CAL_CONST) t2_EOTDmpFWActiveBoundY_MtrNm_s7p8[4][5];

/******************************** GenPosTraj *********************************/
extern CONST(float32, CAL_CONST) k_PosTrajMaxAccel_HwDegpSecSqr_f32;
extern CONST(float32, CAL_CONST) k_PosTrajMaxVelocity_HwDegpSec_f32;

/******************************** GMStrtStop *********************************/
extern CONST(boolean, CAL_CONST) k_AlgEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_FltRspRampDnRt_UlspS_f32;
extern CONST(float32, CAL_CONST) k_Mode1AssistSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_Mode2AssistSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_NormalModeAssistSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_StopMode1AssistSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_StopMode1HwVelTransThresh_HwDegpS_f32;
extern CONST(uint16, CAL_CONST) k_StopMode1Timer_Sec_u16;
extern CONST(float32, CAL_CONST) k_StopMode2AssistSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_StopMode2HwVelTransThresh_HwDegpS_f32;
extern CONST(uint16, CAL_CONST) k_StopMode2Timer_Sec_u16;

/********************************* HOWDetect *********************************/
extern CONST(float32, CAL_CONST) k_HOWDecaySF_Uls_f32;
extern CONST(float32, CAL_CONST) k_HOWEstLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HOWMinVehSpd_Kph_f32;
extern CONST(float32, CAL_CONST) k_HOWSlewRate_HwNmpS_f32;
extern CONST(float32, CAL_CONST) k_HOWStateLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HOWTrqFinalLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HOWTrqHPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_HOWTrqInitLPFKn_Hz_f32;
extern CONST(uint16, CAL_CONST) t_HOWHighFreqGainY_Uls_u9p7[3];
extern CONST(uint16, CAL_CONST) t_HOWStateThresholds_Uls_u8p8[7];
extern CONST(uint16, CAL_CONST) t_HOWVehSpd_Kph_u9p7[3];
extern CONST(uint16, CAL_CONST) t2_HOWHFRateX_HwNm_u8p8[3][6];
extern CONST(sint16, CAL_CONST) t2_HOWHFRateY_UlspS_s7p8[3][6];
extern CONST(uint16, CAL_CONST) t2_HOWLFRateX_HwNm_u8p8[3][5];
extern CONST(sint16, CAL_CONST) t2_HOWLFRateY_UlspS_s7p8[3][5];

/******************************** HwTqCorrln *********************************/
extern CONST(float32, CAL_CONST) k_HwTqCor_AnVsDigChCorrlnMaxErr_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_ArbnAbsTqMaxErr_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1CMCLPFActvnThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1CMCLPFFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1CMCLPFOpLim_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1ImdtCorrlnChkFailThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1SSLPFFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1SSOpClrFltThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1SSOpSetFltThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1TraSumOpClrFltThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch1TraSumOpSetFltThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch2CMCLPFActvnThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch2CMCLPFFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch2CMCLPFOpLim_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch2ImdtCorrlnChkFailThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch2SSLPFFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch2SSOpClrFltThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch2SSOpSetFltThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch2TraSumOpClrFltThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_Ch2TraSumOpSetFltThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCor_DigDiagLPFFc_Hz_f32;
extern CONST(uint16, CAL_CONST) t_HwTqCor_AnaDigTraLPFDepAxis_Hz_u7p9[17];
extern CONST(uint16, CAL_CONST) t_HwTqCor_AnaDigTraLPFIndAxis_HwNm_u6p10[17];
extern CONST(uint16, CAL_CONST) t_HwTqCor_ArbnAbsTqErrTraLPFDepAxis_Hz_u7p9[17];
extern CONST(uint16, CAL_CONST) t_HwTqCor_ArbnAbsTqErrTraLPFIndAxis_HwNm_u6p10[17];
extern CONST(uint16, CAL_CONST) t_HwTqCor_Ch1TraLPFDepAxis_Hz_u7p9[17];
extern CONST(uint16, CAL_CONST) t_HwTqCor_Ch1TraLPFIndAxis_HwNm_u6p10[17];
extern CONST(uint16, CAL_CONST) t_HwTqCor_Ch2TraLPFDepAxis_Hz_u7p9[17];
extern CONST(uint16, CAL_CONST) t_HwTqCor_Ch2TraLPFIndAxis_HwNm_u6p10[17];

/********************************* HwTrqArbn *********************************/
extern CONST(float32, CAL_CONST) k_HwTqCh1MaxTrm_HwNm_f32;
extern CONST(float32, CAL_CONST) k_HwTqCh2MaxTrm_HwNm_f32;

/******************** HystComp, SF47_TSMit_Implementation ********************/
extern CONST(float32, CAL_CONST) k_CmnSysTrqRatio_HwNmpMtrNm_f32;

/**************************** IoHwAbstractionUsr *****************************/
extern CONST(float32, CAL_CONST) k_ADCVref3p3Scaling_Uls_f32;
extern CONST(float32, CAL_CONST) k_ADCVref5vp1Scaling_Uls_f32;
extern CONST(float32, CAL_CONST) k_ADCVref5vp2Scaling_Uls_f32;
extern CONST(uint32, CAL_CONST) k_ReadAdcWaitTimeout_uS_u32;

/********************************** LmtCod ***********************************/
extern CONST(float32, CAL_CONST) k_GainDecSlew_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TorqueDecSlew_MtrNmpS_f32;
extern CONST(uint16, CAL_CONST) t_GainIncSlewTblX_Kph_u9p7[2];
extern CONST(uint16, CAL_CONST) t_GainIncSlewTblY_UlspS_u9p7[2];
extern CONST(uint16, CAL_CONST) t_TorqueIncSlewTblX_Kph_u9p7[2];
extern CONST(uint16, CAL_CONST) t_TorqueIncSlewTblY_MtrNmpS_u13p3[2];

/********************************** LoaMgr ***********************************/
extern CONST(float32, CAL_CONST) k_LoaMgr_CurrIvtrMtgtnRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LoaMgr_CurrIvtrMtgtnSca_Uls_f32;
extern CONST(Boolean, CAL_CONST) k_LoaMgr_CurrIvtrMtgtnScaZeroEn_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_LoaMgr_FadeOutStRate_UlspS_f32;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSig0TloaAvailResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSig1NoTloaResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSig1TloaAvailResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSig2TloaDiResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSig2TloaEnaResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSig4Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_HwTqIdptSigFltThd_Cnt_u08;
extern CONST(float32, CAL_CONST) k_LoaMgr_HwTqMtgtnRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LoaMgr_HwTqMtgtnSca_Uls_f32;
extern CONST(uint8, CAL_CONST) k_LoaMgr_IvtrIdptSig1Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_IvtrIdptSig2Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_IvtrIdptSigFltThd_Cnt_u08;
extern CONST(float32, CAL_CONST) k_LoaMgr_IvtrMtgtnRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LoaMgr_IvtrMtgtnSca_Uls_f32;
extern CONST(Boolean, CAL_CONST) k_LoaMgr_IvtrMtgtnScaZeroEn_Cnt_lgc;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotAgIdptSig1NoSmaResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotAgIdptSig2Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotAgIdptSig3Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotAgIdptSigFltThd_Cnt_u08;
extern CONST(float32, CAL_CONST) k_LoaMgr_MotAgMtgtnRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LoaMgr_MotAgMtgtnSca_Uls_f32;
extern CONST(Boolean, CAL_CONST) k_LoaMgr_MotAgMtgtnScaZeroEn_Cnt_lgc;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotAgSmaAvailResp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotCurrIdptSig0Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotCurrIdptSig1Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotCurrIdptSig2Resp_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_LoaMgr_MotCurrIdptSigFltThd_Cnt_u08;
extern CONST(float32, CAL_CONST) k_LoaMgr_MotCurrMtgtnRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LoaMgr_MotCurrMtgtnSca_Uls_f32;
extern CONST(Boolean, CAL_CONST) k_LoaMgr_MotCurrMtgtnScaZeroEn_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_LoaMgr_RedcdStRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_LoaMgr_RedcdStSca_Uls_f32;

/********************************** LrnEOT ***********************************/
extern CONST(float32, CAL_CONST) k_AuthorityStartLrn_Uls_f32;
extern CONST(uint16, CAL_CONST) k_EOTLrnTimer_mS_u16;
extern CONST(float32, CAL_CONST) k_HwTrqEOTLrn_HwNm_f32;
extern CONST(float32, CAL_CONST) k_MaxRackTrvl_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_MinRackTrvl_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_MinResetAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_MtrVelEOTLrn_MtrRadpS_f32;

/******************************** MotAgCorrln ********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_MotAgCorrln_MotPosn3Flt_Cnt_str;
extern CONST(uint8, CAL_CONST) k_MotAgCorrln_MotPosn3MaxStall_Cnt_u08;

/******************************** MtrCtrl_CM *********************************/
extern CONST(boolean, CAL_CONST) k_MtrCurrQaxRefModifRplEn_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_MtrPosComputationDelayRpl_Sec_f32;
extern CONST(float32, CAL_CONST) k_MtrVelFiltFFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_MtrVelFiltPIKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltDaxIntegHiLim_Volt_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltDaxIntegLoLim_Volt_f32;
extern CONST(boolean, CAL_CONST) k_MtrVoltQaxFiltFFEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_MtrVoltQaxFiltFFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltQaxIntegHiLim_Volt_f32;
extern CONST(float32, CAL_CONST) k_MtrVoltQaxIntegLoLim_Volt_f32;
extern CONST(boolean, CAL_CONST) k_MtrVoltVecuFiltEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_MtrVoltVecuFiltKn_Hz_f32;
extern CONST(boolean, CAL_CONST) k_VoltModeDynCompEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_VoltSatDaxPolyCoeff_Uls_f32;
extern CONST(float32, CAL_CONST) k_VoltSatQaxPolyCoeff_Uls_f32;
extern CONST(uint16, CAL_CONST) t_CommOffsetTblX_Uls_u3p13[2];
extern CONST(uint16, CAL_CONST) t_IdBoostTrqCharSclY_Uls_u1p15[11];
extern CONST(uint16, CAL_CONST) t_IdBoostTrqCmdX_MtrNm_u4p12[11];
extern CONST(uint16, CAL_CONST) t_MtrBandwidthDaxY_Hz_u10p6[4];
extern CONST(uint16, CAL_CONST) t_MtrBandwidthQaxY_Hz_u10p6[4];
extern CONST(uint16, CAL_CONST) t_MtrNaturalFreqDaxY_Hz_u9p7[4];
extern CONST(uint16, CAL_CONST) t_MtrNaturalFreqQaxY_Hz_u9p7[4];
extern CONST(uint16, CAL_CONST) t_MtrTrqCmdPIY_MtrNm_u5p11[8];
extern CONST(uint16, CAL_CONST) t_MtrVelCtrlGainX_MtrRadpSec_u12p4[4];
extern CONST(uint16, CAL_CONST) t_MtrVelX_MtrRadpS_T_u16[20];
extern CONST(uint16, CAL_CONST) t2_MtrTrqCancPIMagRP_Uls_u6p10[20][8];
extern CONST(uint16, CAL_CONST) t2_MtrTrqCancPIPhRP_Rev_u0p16[20][8];

/******************************* MtrPos3SinCos *******************************/
extern CONST(uint16, CAL_CONST) k_MtrPos3Offset_RevM_u0p16;
extern CONST(float32, CAL_CONST) k_MtrPos3SinCos_ValMaxError_VoltsSqrd_f32;
extern CONST(float32, CAL_CONST) k_MtrPos3SinCos_ValMinError_VoltsSqrd_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrPos3ValDiag_Cnt_str;

/******************************** MtrTempEst *********************************/
extern CONST(float32, CAL_CONST) k_AMCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_AMDefaultTemp_DegC_f32;
extern CONST(float32, CAL_CONST) k_CuCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_MagCorrLmt_DegC_f32;
extern CONST(float32, CAL_CONST) k_SiCorrLmt_DegC_f32;

/******************************** MtrVel_Digi ********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_HwVelCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_HwVelCorrLim_HwRadpS_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_MtrVelCorrLim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_MtrVelCorrLim_MtrRadpS_f32;
extern CONST(uint16, CAL_CONST) t_MtrVelBlendTblX_MtrRadpS_u12p4[2];

/****************************** Nhet1CfgAndUse *******************************/
extern CONST(uint32, CAL_CONST) k_SENTSyncTrgMin_Cnt_u32;
extern CONST(uint16, CAL_CONST) k_SPI1mOff_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_SPI50UOff_Cnt_u16;
extern CONST(uint8, CAL_CONST) k_TSNstep_Cnt_u08;
extern CONST(uint8, CAL_CONST) k_TSPstep_Cnt_u08;

/******************************** OvrVoltMon *********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_CPUSupplyOV_Cnt_Str;

/******************************* PwrDscntDuInv *******************************/
extern CONST(float32, CAL_CONST) k_MaxSwitchedVolt_Volts_f32;

/****************************** ReturnFirewall *******************************/
extern CONST(sint16, CAL_CONST) t_RtrnFWUprBoundX_HwDeg_s11p4[11];
extern CONST(uint16, CAL_CONST) t_RtrnFWVehSpd_Kph_u9p7[8];
extern CONST(sint16, CAL_CONST) t2_RtrnFWUprBoundY_MtrNm_s4p11[8][11];

/******************************* SASPlausDiag ********************************/
extern CONST(float32, CAL_CONST) k_SASPlausDiagMaxDelta_HwDeg_f32;

/************************* SF47_TSMit_Implementation *************************/
extern CONST(float32, CAL_CONST) k_TSMitCmdSlewRate_HwNmpS_f32;
extern CONST(boolean, CAL_CONST) k_TSMitDisableNegTransTrqSTGainLearning_Cnt_f32;
extern CONST(float32, CAL_CONST) k_TSMitGainLearningFreqFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_TSMitHwTrqLPFiltFc_Hz_f32;
extern CONST(float32, CAL_CONST) k_TSMitMaxHwPosEnable_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_TSMitMaxHwVelEnable_HwRadpS_f32;
extern CONST(float32, CAL_CONST) k_TSMitMaxNegTransTrqEnable_TransNm_f32;
extern CONST(float32, CAL_CONST) k_TSMitMaxVehSpdEnable_Kph_f32;
extern CONST(float32, CAL_CONST) k_TSMitMaxYawRateEnable_DegpS_f32;
extern CONST(float32, CAL_CONST) k_TSMitMinHwAuthEnable_Uls_f32;
extern CONST(float32, CAL_CONST) k_TSMitMinHwTrqEnable_HwNm_f32;
extern CONST(float32, CAL_CONST) k_TSMitMinPosTransTrqEnable_TransNm_f32;
extern CONST(float32, CAL_CONST) k_TSMitMinVehSpdEnable_Kph_f32;
extern CONST(float32, CAL_CONST) k_TSMitNegTransGainLimit_HwNmpTransNm_f32;
extern CONST(float32, CAL_CONST) k_TSMitNegTransTrqThresh_TransNm_f32;
extern CONST(float32, CAL_CONST) k_TSMitPosTransGainLimit_HwNmpTransNm_f32;
extern CONST(float32, CAL_CONST) k_TSMitPosTransTrqThresh_TransNm_f32;
extern CONST(float32, CAL_CONST) k_TSMitTimeOnEnable_Sec_f32;
extern CONST(boolean, CAL_CONST) k_TSMitUseABSActiveFlag_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_TSMitUseESCActiveFlag_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_TSMitUseTCSActiveFlag_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_TSMitYawRateLPFiltFc_Hz_f32;
extern CONST(sint16, CAL_CONST) t_TSMitCmdSclHwPosTbl_HwDeg_s10p5[11];
extern CONST(uint16, CAL_CONST) t_TSMitCmdSclVelocityTbl_Kph_u8p8[5];
extern CONST(uint16, CAL_CONST) t2_TSMitCmdSclScaleFactor_Uls_u2p14[5][11];

/********************************* SgnlCond **********************************/
extern CONST(float32, CAL_CONST) k_SigCon_DefaultLatAccel_MpSecSq_f32;
extern CONST(float32, CAL_CONST) k_SigCon_DefaultLonAccel_KphpS_f32;
extern CONST(float32, CAL_CONST) k_SigCon_DefaultVehSpd_Kph_f32;
extern CONST(float32, CAL_CONST) k_SigCon_DefaultYawRate_DegpS_f32;
extern CONST(float32, CAL_CONST) k_SigCon_LatAccelDiffThresh_MpSecSq_f32;
extern CONST(float32, CAL_CONST) k_SigCon_LatAccelSlewRate_MpSecSq_f32;
extern CONST(float32, CAL_CONST) k_SigCon_LatAccFiltFrq_Hz_f32;
extern CONST(float32, CAL_CONST) k_SigCon_LonAccelDiffThresh_KphpS_f32;
extern CONST(float32, CAL_CONST) k_SigCon_LonAccelSlewRate_KphpSecSq_f32;
extern CONST(float32, CAL_CONST) k_SigCon_VehSpdDiffThresh_Kph_f32;
extern CONST(float32, CAL_CONST) k_SigCon_VehSpdSlewRate_KphpS_f32;
extern CONST(float32, CAL_CONST) k_SigCon_YawRateDiffThresh_DegpS_f32;
extern CONST(float32, CAL_CONST) k_VehYawRateSlew_DegpSecSq_f32;

/******************************* SnsrOffsCorrn *******************************/
extern CONST(float32, CAL_CONST) k_SnsrOffsCorrn_HwAgLrndOffsLim_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_SnsrOffsCorrn_HwTqLrndOffsLim_HwNm_f32;
extern CONST(boolean, CAL_CONST) k_SnsrOffsCorrn_OffsEna_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_SnsrOffsCorrn_YawRateLrndOffsLim_VehDegpS_f32;

/******************************* SnsrOffsLrng ********************************/
extern CONST(boolean, CAL_CONST) k_SOaC_FctEna_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_SOaC_HwAgLrngDrvgDstThd_Metr_f32;
extern CONST(boolean, CAL_CONST) k_SOaC_HwAgLrngEna_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_SOaC_HwAgLrngHwVelThd_HwRadpS_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwAgLrngLrngTi_Sec_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwAgLrngSysTqThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwAgLrngSysTqThdMed_HwNm_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwAgLrngSysTqThdTrustd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwAgLrngSysTqThdWide_HwNm_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwAgLrngVehSpdThd_Kph_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwAgLrngYawOffsDbnd_VehDegpS_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwAgLrngYawRateThd_VehDegpS_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwAgOffsLim_HwDeg_f32;
extern CONST(boolean, CAL_CONST) k_SOaC_HwTqLrngEna_Cnt_lgc;
extern CONST(uint16, CAL_CONST) k_SOaC_HwTqLrngEnaTiThd_mS_u16p0;
extern CONST(float32, CAL_CONST) k_SOaC_HwTqLrngHwAgDbnd_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwTqLrngHwAgThd_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwTqLrngHwTqThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwTqLrngHwTqZeroOffsThd_HwNm_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwTqLrngHwVelThd_HwRadpS_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwTqLrngMeasTi_Sec_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwTqLrngMeasTiSca_Uls_f32;
extern CONST(uint16, CAL_CONST) k_SOaC_HwTqLrngSampleCntForLrngRst_Cnt_u16;
extern CONST(float32, CAL_CONST) k_SOaC_HwTqLrngSampleImbThd1_Uls_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwTqLrngSampleImbThd2_Uls_f32;
extern CONST(uint16, CAL_CONST) k_SOaC_HwTqLrngSampleThd1_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_SOaC_HwTqLrngSampleThd2_Cnt_u16;
extern CONST(float32, CAL_CONST) k_SOaC_HwTqLrngTiWghtCoeff_Uls_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwTqLrngVehSpdThd_Kph_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwTqOffsLim_HwNm_f32;
extern CONST(float32, CAL_CONST) k_SOaC_HwVelFiltFreq_Hz_f32;
extern CONST(float32, CAL_CONST) k_SOaC_TqAndAgFiltFreq_Hz_f32;
extern CONST(float32, CAL_CONST) k_SOaC_TqInpDetnHwTqFiltFreq_Hz_f32;
extern CONST(float32, CAL_CONST) k_SOaC_TqInpDetnPwrEstimnThd_dB_f32;
extern CONST(float32, CAL_CONST) k_SOaC_TqInpDetnSinGenrAmp_HwNm_f32;
extern CONST(float32, CAL_CONST) k_SOaC_TqInpDetnSinGenrFrq_Hz_f32;
extern CONST(float32, CAL_CONST) k_SOaC_TqInpDetnStg1FiltGain_Uls_f32;
extern CONST(uint8, CAL_CONST) k_SOaC_TqInpDetnStg1WinSize_Cnt_u08;
extern CONST(float32, CAL_CONST) k_SOaC_TqInpDetnStg2FiltGainCen_Uls_f32;
extern CONST(float32, CAL_CONST) k_SOaC_TqInpDetnStg2FiltGainDwn_Uls_f32;
extern CONST(float32, CAL_CONST) k_SOaC_TqInpDetnStg2FiltGainUp_Uls_f32;
extern CONST(uint16, CAL_CONST) k_SOaC_TqInpDetnStg2WinSize_Cnt_u16;
extern CONST(float32, CAL_CONST) k_SOaC_YawACdngFiltFreq_Hz_f32;
extern CONST(boolean, CAL_CONST) k_SOaC_YawLrngEna_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_SOaC_YawLrngHwAgThd_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_SOaC_YawLrngLrngTi_Sec_f32;
extern CONST(float32, CAL_CONST) k_SOaC_YawLrngYawAThd_VehDegpSSq_f32;
extern CONST(float32, CAL_CONST) k_SOaC_YawOffsFrshTiThd_Min_f32;
extern CONST(float32, CAL_CONST) k_SOaC_YawRateCdngFiltFreq_Hz_f32;
extern CONST(float32, CAL_CONST) k_SOaC_YawRateOffsLim_VehDegpS_f32;

/******************************** SrlComInput ********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_ABSActvProtARCVldDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_ABSActvProtARCVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_ABSActvProtPValVldDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_ABSActvProtPValVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_ABSActvProtVldDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_ABSFldValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_ABSFldValTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_ActAxleTrqVldDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_ActAxleTrqVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_AmbTempValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_APANonRecFltsMsk_Cnt_b16;
extern CONST(uint8, CAL_CONST) k_APARecFltsMsk_Cnt_b08;
extern CONST(DiagSettings_Str, CAL_CONST) k_EngSpdStatVldDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_EngSpdStatVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_EngTempValDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_ESCChksmVldDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_ESCChksmVldTimeOut_mS_u16p0;
extern CONST(boolean, CAL_CONST) k_ESCMfgEnable_Cnt_lgc;
extern CONST(DiagSettings_Str, CAL_CONST) k_ESCRollCountVldDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_ESCRollCountVldTimeOut_mS_u16p0;
extern CONST(float32, CAL_CONST) k_LatAccDflt_MpSecSqrd_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_LatAccValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_LatAccValTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_LKATqOvrDltCmdPrtVlVldDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_LKATqOvrDltCmdPrtVlVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_LKATqOvrDltCmdRCVldDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_LKATqOvrDltCmdRCVldTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_LKAVehStabEnVldTimeOut_mS_u16p0;
extern CONST(float32, CAL_CONST) k_MaxFreqChg_Hz_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_Ms17DTimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg0C1TimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg0C1TimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg0C9TimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg0C9TimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg0D3TimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg0D3TimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg17DLKATimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_Msg17DTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_Msg180CETimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg180CETimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg180HSLKATimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_Msg180HSTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg180HSTimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg182TimeOut_mS_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg182TimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg1E9LKATimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_Msg1E9TimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg1E9TimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg1F1TimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg1F1TimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg1F5TimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg1F5TimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg214LKATimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_Msg214TimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg214TimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg232TimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg232TimeOutDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg337APAInvalidDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg337APANonRecTimeOut_mS_u16;
extern CONST(uint16, CAL_CONST) k_Msg337APARecTimeOut_mS_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg337APATimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg337TimeOut_mS_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg337TimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg348CELKATimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_Msg348CETimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg348CETimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg348HSLKATimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_Msg348HSTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg348HSTimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg34ACELKATimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_Msg34ACETimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg34ACETimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg34AHSLKATimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_Msg34AHSTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg34AHSTimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg3E9TimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg3E9TimeOutDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg3F1LossTimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg3F1TimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg4C1LossTimeOutDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_Msg4C1TimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_Msg500TimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_Msg500TimeOutDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_ParkAssistParallelValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_ParkAssistParallelValTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_RedntVSEActARCVldDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_RedntVSEActARCVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_RedntVSEActVldDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_RedntVSEActVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_TCSysAValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_TCSysAValTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_TCSysEValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_TCSysEValTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_TrnsShftLvrPosVldDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_TrnsShftLvrPosVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_VehicleDynamicsESCHybCEValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_VehicleDynamicsESCHybCEValTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_VehSpdValDiag_Cnt_Str;
extern CONST(uint16, CAL_CONST) k_VehSpdValTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_VhDynCValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_VhDynCValTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_VSEActValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_VSEActValTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_WhlGrndVlctyLftDrvnCEValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_WhlGrndVlctyLftDrvnCEVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_WhlGrndVlctyLftDrvnHSValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_WhlGrndVlctyLftDrvnHSVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_WhlGrndVlctyLftNnDrvnCEValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_WhlGrndVlctyLftNnDrvnCEVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_WhlGrndVlctyLftNnDrvnHSValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_WhlGrndVlctyLftNnDrvnHSVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_WhlGrndVlctyRtDrvnCEValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_WhlGrndVlctyRtDrvnCEVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_WhlGrndVlctyRtDrvnHSValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_WhlGrndVlctyRtDrvnHSVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_WhlGrndVlctyRtNnDrvnCEValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_WhlGrndVlctyRtNnDrvnCEVldTimeOut_mS_u16p0;
extern CONST(DiagSettings_Str, CAL_CONST) k_WhlGrndVlctyRtNnDrvnHSValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_WhlGrndVlctyRtNnDrvnHSVldTimeOut_mS_u16p0;
extern CONST(uint16, CAL_CONST) k_WhlGrndVlctyStuckTime_mS_u16;
extern CONST(uint16, CAL_CONST) k_WhlPlsPerRev_Cnt_u16p0;
extern CONST(uint16, CAL_CONST) k_WhlRotVldTimeOut_mS_u16p0;
extern CONST(float32, CAL_CONST) k_WhlTstmpRes_SecpCnt_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_WIRFltStatusDiag_Cnt_str;
extern CONST(float32, CAL_CONST) k_YawRateDflt_DegpSec_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_YawRateValDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_YawRateValTimeOut_mS_u16p0;

/************************** SrlComInput, VehSpdArbn **************************/
extern CONST(float32, CAL_CONST) k_DefaultVehSpd_Kph_f32;

/*********************** SrlComOutput, GMSrlComOutput ************************/
extern CONST(uint16, CAL_CONST) k_BusOffFaultTimeChannel0_mS_u16;
extern CONST(uint16, CAL_CONST) k_BusOffFaultTimeChannel1_mS_u16;
extern CONST(uint16, CAL_CONST) k_BusOffRecoveryTimeChannel0_mS_u16;
extern CONST(uint16, CAL_CONST) k_BusOffRecoveryTimeChannel1_mS_u16;
extern CONST(float32, CAL_CONST) k_MaxHOWEstimate_Uls_f32;

/***************** SrlComOutput, GMSrlComOutput, SrlComInput *****************/
extern CONST(boolean, CAL_CONST) k_APAMfgEnable_Cnt_lgc;
extern CONST(boolean, CAL_CONST) k_LKAMfgEnable_Cnt_lgc;
extern CONST(sint8, CAL_CONST) k_SComTrqPosPol_Cnt_s08;

/******************************* StabilityComp *******************************/
extern CONST(boolean, CAL_CONST) k_StCmpCrosChkEnbl_Uls_lgc;
extern CONST(float32, CAL_CONST) k_StCmpHwTrqLPFKn_Hz_f32;
extern CONST(uint16, CAL_CONST) k_StCmpStabCmpNstep_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_StCmpStabCmpPNThresh_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_StCmpStabCmpPstep_Cnt_u16;
extern CONST(float32, CAL_CONST) k_StCmpSysCorrThresh_MtrNm_f32;
extern CONST(uint16, CAL_CONST) t_StCmpADDFBlendX_Uls_u2p14[2];
extern CONST(uint16, CAL_CONST) t_StCmpADDFBlendY_Uls_u2p14[2];
extern CONST(uint16, CAL_CONST) t_StCmpBlend12Trq_HwNm_u8p8[5];
extern CONST(uint16, CAL_CONST) t_StCmpBlend34Trq_HwNm_u8p8[5];
extern CONST(uint16, CAL_CONST) t_StCmpBlendSpdBS_Kph_u9p7[6];
extern CONST(NotchFiltK_Str, CAL_CONST) t_StCmpNFK_Str[4];
extern CONST(uint16, CAL_CONST) t2_StCmpBlend02TblY_Uls_u2p14[6][5];
extern CONST(uint16, CAL_CONST) t2_StCmpBlend04TblY_Uls_u2p14[6][5];
extern CONST(uint16, CAL_CONST) t2_StCmpBlend12TblY_Uls_u2p14[6][5];
extern CONST(uint16, CAL_CONST) t2_StCmpBlend34TblY_Uls_u2p14[6][5];

/*********************************** StaMd ***********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_StaMdsSysCDiag_Cnt_str;

/**************************** SVDiag, MtrCtrl_CM *****************************/
extern CONST(uint16, CAL_CONST) t_CommOffsetTblY_Cnt_u16[2];

/************************** SVDiag, SVDiag_DualInv ***************************/
extern CONST(uint16, CAL_CONST) k_ErrorFiltKn_Cnt_u16;
extern CONST(uint32, CAL_CONST) k_ErrorThresh_Cnt_u32;
extern CONST(DiagSettings_Str, CAL_CONST) k_GateDriveDiag_Cnt_str;
extern CONST(DiagSettings_Str, CAL_CONST) k_OnStateDiag_Cnt_str;
extern CONST(sint16, CAL_CONST) k_PhsReasErrorTerm_Cnt_s16;

/********************************* SVDrvr_CM *********************************/
extern CONST(uint16, CAL_CONST) k_DitherLPFKn_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_PWMBaseFrequency_Hz_u16;

/***************************** TmplMonrDualIvtr ******************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_TmplMonrDualIvtrPstepNstep_Cnt_str;

/******************************* TMS570_uDiag ********************************/
extern CONST(DiagSettings_Str, CAL_CONST) k_FlashECCDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_MtrCtrlMaxCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_MtrCtrlMinCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_OneMsLoopMaxCount_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_OneMsLoopMinCount_Cnt_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_RAMECCDiag_Cnt_str;
extern CONST(uint16, CAL_CONST) k_VIMParErrThrsh_Cnt_u16;

/********************************** TqRsDg ***********************************/
extern CONST(float32, CAL_CONST) k_CurrDiagLambdaMinMax_Volt_f32;
extern CONST(float32, CAL_CONST) k_CurrDiagMtrEnvTblMax_MtrNm_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_CurrDiagPrim_Cnt_Str;
extern CONST(float32, CAL_CONST) k_CurrDiagPrimErrorThresh_Volt_f32;
extern CONST(float32, CAL_CONST) k_CurrDiagPrimLPFKn_Hz_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_CurrDiagSec_Cnt_Str;
extern CONST(float32, CAL_CONST) k_CurrDiagSecErrorThresh_Volt_f32;
extern CONST(float32, CAL_CONST) k_CurrDiagSecLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_CurrDiagSecTrqLmtThresh_Uls_f32;

/******************************** TranlDampg *********************************/
extern CONST(float32, CAL_CONST) k_TrnDmp_BkptTwo_mS_f32;
extern CONST(float32, CAL_CONST) k_TrnDmp_DampCoeff_MtrNmpRadpS_f32;
extern CONST(float32, CAL_CONST) k_TrnDmp_DmpLimit_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_TrnDmp_RampEnd_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrnDmp_TmrBkptOne_mS_f32;
extern CONST(float32, CAL_CONST) k_TrnDmp_VelThr_MtrRadpS_f32;
extern CONST(uint16, CAL_CONST) t_TrnDmp_VehSpdBlndX_Kph_u9p7[4];
extern CONST(uint16, CAL_CONST) t_TrnDmp_VehSpdBlndY_Uls_u9p7[4];

/********************************** TrqLOA ***********************************/
extern CONST(float32, CAL_CONST) k_TrqLOA_AbsAssistThreshold_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_AbsVelThreshold_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_DiffScaleRateLimiterFalling_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_DiffScaleRateLimiterRising_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_FallingRampRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_LatAccConversionFactor_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_LimOutput_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_LPF_Hz_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_MaxScaleFactor_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_MinScaleFactor_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_NomDrvTrq_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_RisingRampRate_UlspS_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_SteerRatio_Uls_f32;
extern CONST(float32, CAL_CONST) k_TrqLOA_UndersteerGrad_RadpG_f32;
extern CONST(boolean, CAL_CONST) k_TrqLOA_UseVehWhlBasCal_Cnt_lgc;
extern CONST(uint16, CAL_CONST) t_TrqLOA_DiffGainX_G_u2p14[4];
extern CONST(uint16, CAL_CONST) t_TrqLOA_HighSpeedTrqBlend_X_Kph_u10p6[5];
extern CONST(uint16, CAL_CONST) t_TrqLOA_HighSpeedTrqBlend_Y_Uls_u1p15[5];
extern CONST(uint16, CAL_CONST) t_TrqLOA_LatAccGain_Y_MtrNmpG_u4p12[8];
extern CONST(uint16, CAL_CONST) t_TrqLOA_TempTrqCmdSatYTbl_MtrNm_u4p12[8];
extern CONST(uint16, CAL_CONST) t_TrqLOA_X_Kph_u10p6[8];
extern CONST(uint16, CAL_CONST) t2_TrqLOA_DiffGainY_Uls_u1p15[8][4];

/********************************** TrqOsc ***********************************/
extern CONST(uint16, CAL_CONST) t_TrqOscAmpLimit_MtrNm_u5p11[5];
extern CONST(uint16, CAL_CONST) t_TrqOscFreqIn_Hz_u12p4[5];

/********************************* TrqOvlSta *********************************/
extern CONST(boolean, CAL_CONST) k_APAIncludeHaptic_Cnt_lgc;

/******************************* TuningSelAuth *******************************/
extern CONST(float32, CAL_CONST) k_TunSelHwTrqLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_TunSelHwTrqThresh_HwNm_f32;
extern CONST(float32, CAL_CONST) k_TunSelVehSpdThresh_Kph_f32;

/********************************** VehDyn ***********************************/
extern CONST(float32, CAL_CONST) k_AutoCntrHiSpdCntrWindow_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_AutoCntrHiSpdFilt1Kn_Hz_f32;
extern CONST(float32, CAL_CONST) k_AutoCntrHiSpdFilt2Kn_Hz_f32;
extern CONST(uint16, CAL_CONST) k_AutoCntrHiSpdTimer1_mS_u16;
extern CONST(float32, CAL_CONST) k_AutoCntrHiSpdTimer1MtrVel_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_AutoCntrHiSpdTimer1PinTrq_HwNm_f32;
extern CONST(float32, CAL_CONST) k_AutoCntrHiSpdTimer1VehSpd_kph_f32;
extern CONST(uint16, CAL_CONST) k_AutoCntrHiSpdTimer2_mS_u16;
extern CONST(uint16, CAL_CONST) k_AutoCntrHiSpdTimer4_mS_u16;
extern CONST(float32, CAL_CONST) k_AutoCntrHiSpdTimer4CntrWindow_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_AutoCntrHiSpdTimer4MtrVel_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_AutoCntrHiSpdTimer4PinTrq_HwNm_f32;
extern CONST(float32, CAL_CONST) k_AutoCntrHiSpdTimer4VehSpd_kph_f32;
extern CONST(float32, CAL_CONST) k_AutoCntrLoSpdCntrWindow_HwDeg_f32;
extern CONST(float32, CAL_CONST) k_AutoCntrLoSpdFilt1Kn_Hz_f32;
extern CONST(float32, CAL_CONST) k_AutoCntrLoSpdFilt2Kn_Hz_f32;
extern CONST(uint16, CAL_CONST) k_AutoCntrLoSpdTimer1_mS_u16;
extern CONST(float32, CAL_CONST) k_AutoCntrLoSpdTimer1MtrVel_MtrRadpS_f32;
extern CONST(float32, CAL_CONST) k_AutoCntrLoSpdTimer1PinTrq_HwNm_f32;
extern CONST(float32, CAL_CONST) k_AutoCntrLoSpdTimer1VehSpd_kph_f32;
extern CONST(uint16, CAL_CONST) k_AutoCntrLoSpdTimer2_mS_u16;
extern CONST(float32, CAL_CONST) k_AutoCntrPinTrqLPFCoeffKn_Hz_f32;
extern CONST(boolean, CAL_CONST) k_SLPEnableBFCheck_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_SLPHwAuthority_Uls_f32;
extern CONST(float32, CAL_CONST) k_SLPMinHwAuthToStoreHwPos_Uls_f32;
extern CONST(float32, CAL_CONST) k_SysKinRatio_MtrDegpHwDeg_f32;
extern CONST(float32, CAL_CONST) k_TravelXCDeadband_Uls_f32;
extern CONST(float32, CAL_CONST) k_TravelXCHwAuthority_Uls_f32;

/********************************* VehPwrMd **********************************/
extern CONST(float32, CAL_CONST) k_GmVPMod_VehSpdAssiOnMin_Kph_f32;
extern CONST(float32, CAL_CONST) k_GmVPMod_VehSpdMinKeepAssist_Kph_f32;
extern CONST(uint16, CAL_CONST) k_IGNDiagTime_mS_u16p0;
extern CONST(float32, CAL_CONST) k_RampDnRt_UlspmS_f32;
extern CONST(float32, CAL_CONST) k_RampUpRtLoSpd_UlspmS_f32;
extern CONST(uint16, CAL_CONST) k_VehPwrMdAvgTq_Cnt_u16;
extern CONST(boolean, CAL_CONST) k_VehPwrMdDiffTorque_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_VehPwrMdDiffTqThreshold_HwNm_f32;
extern CONST(float32, CAL_CONST) k_VehPwrMdLpfCutOff_Hz_f32;
extern CONST(uint32, CAL_CONST) k_VehPwrMdNoTqTimer_mS_u32p0;
extern CONST(float32, CAL_CONST) k_VehPwrMdTqThreshold_Nm_f32;

/********************************* VehSpdLmt *********************************/
extern CONST(uint16, CAL_CONST) t_MaxAsstTblX_Kph_u9p7[5];
extern CONST(uint16, CAL_CONST) t_MaxAsstTblY_MtrNm_u5p11[5];

/********************************* WhlImbRej *********************************/
extern CONST(float32, CAL_CONST) k_AdaptiveMu_Uls_f32;
extern CONST(boolean, CAL_CONST) k_AutoScaleEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_AutoScaleTarget_RadpSec_f32;
extern CONST(float32, CAL_CONST) k_BlndCmdMagLPFKn1_Hz_f32;
extern CONST(float32, CAL_CONST) k_BlndCmdMagLPFKn2_Hz_f32;
extern CONST(float32, CAL_CONST) k_CmdMagLPFKn1_Hz_f32;
extern CONST(float32, CAL_CONST) k_CmdMagLPFKn2_Hz_f32;
extern CONST(float32, CAL_CONST) k_CorrFltRecDly_Min_f32;
extern CONST(uint8, CAL_CONST) k_CorrFltRecLim_Cnt_u8;
extern CONST(float32, CAL_CONST) k_CurrMagSlewPerLoop_Uls_f32;
extern CONST(float32, CAL_CONST) k_DCTrendFltRecDly_Min_f32;
extern CONST(uint8, CAL_CONST) k_DCTrendFltRecLim_Cnt_u8;
extern CONST(float32, CAL_CONST) k_DistMagLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_EnSlewPerLoop_Uls_f32;
extern CONST(boolean, CAL_CONST) k_FreqDiagEnable_Cnt_lgc;
extern CONST(float32, CAL_CONST) k_FreqDiagFltRecDly_Min_f32;
extern CONST(uint8, CAL_CONST) k_FreqDiagFltRecLim_Cnt_u8;
extern CONST(float32, CAL_CONST) k_FreqDiagLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_FreqDiagThresh_MtrNm_f32;
extern CONST(uint16, CAL_CONST) k_FreqDiagTimeout_mS_u16p0;
extern CONST(float32, CAL_CONST) k_FreqDiagUGRPoleMag_Uls_f32;
extern CONST(float32, CAL_CONST) k_FreqDiagWIRAmpThresh_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_MagEstDeltaScale_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagEstDisable_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagEstEnable_Uls_f32;
extern CONST(float32, CAL_CONST) k_MagEstFreq_Hz_f32;
extern CONST(float32, CAL_CONST) k_MagEstFreqDelta_Hz_f32;
extern CONST(float32, CAL_CONST) k_MagEstLeak_Uls_f32;
extern CONST(float32, CAL_CONST) k_MaxMagFltRecDly_Min_f32;
extern CONST(uint8, CAL_CONST) k_MaxMagFltRecLim_Cnt_u8;
extern CONST(uint16, CAL_CONST) k_NumberOfTaps_Cnt_u16;
extern CONST(float32, CAL_CONST) k_ScaleCancel_Uls_f32;
extern CONST(float32, CAL_CONST) k_UGRPoleMag_Uls_f32;
extern CONST(float32, CAL_CONST) k_WhlImbCmdMax_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_WhlSpdCorrThresh_Pct_f32;
extern CONST(uint16, CAL_CONST) k_WhlSpdCorrTime_mS_u16p0;
extern CONST(float32, CAL_CONST) k_WhlSpdLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_WIRDCTrendLPFKn_Hz_f32;
extern CONST(float32, CAL_CONST) k_WIRDCTrendTh_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_WIRDCTrendTh2_MtrNm_f32;
extern CONST(float32, CAL_CONST) k_WIRDCTrendTime_Sec_f32;
extern CONST(float32, CAL_CONST) k_WIRDCTrendTime2_Sec_f32;
extern CONST(uint16, CAL_CONST) k_WIRMaxDur_Cnt_u16;
extern CONST(float32, CAL_CONST) k_WIRMaxMag_MtrNm_f32;
extern CONST(DiagSettings_Str, CAL_CONST) k_WIRMaxMagDiag_Cnt_Str;
extern CONST(uint16, CAL_CONST) k_WIRRampDownTime_mS_u16p0;
extern CONST(uint16, CAL_CONST) t_PhaseAdjustX_Hz_u7p9[3];
extern CONST(sint16, CAL_CONST) t_PhaseAdjustY_Deg_s8p7[3];

/******************************* WIRInputQual ********************************/
extern CONST(uint16, CAL_CONST) k_WhlSpdQLimit_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_WhlSpdQNStep_Cnt_u16;
extern CONST(uint16, CAL_CONST) k_WhlSpdQPStep_Cnt_u16;
extern CONST(DiagSettings_Str, CAL_CONST) k_WhlSpdQualDiag_Cnt_Str;

/************************** WIRInputQual, WhlImbRej **************************/
extern CONST(uint16, CAL_CONST) t_FreqScaleTblX_Hz_u7p9[6];
extern CONST(uint16, CAL_CONST) t_FreqScaleTblY_Uls_u2p14[6];

/***************************** AbsHwPos_TcI2cVd ******************************/
#define k_KinmIntDiagMaxRackLimit_HwDeg_f32	TunSet_Ptr_Str->k_KinmIntDiagMaxRackLimit_HwDeg_f32

/* Assist, Damping, DampingFirewall, FrqDepDmpnInrtCmp, HighFreqAssist, HystComp, TrqArblim ********************************************************************************/
#define t_CmnVehSpd_Kph_u9p7	TunSet_Ptr_Str->t_CmnVehSpd_Kph_u9p7

/****************************** AssistFirewall *******************************/
#define k_AsstFWFiltKn_Hz_f32	TunSet_Ptr_Str->k_AsstFWFiltKn_Hz_f32
#define k_AsstFWFWActiveLPF_Hz_f32	TunSet_Ptr_Str->k_AsstFWFWActiveLPF_Hz_f32
#define k_AsstFWInpLimitBaseAsst_MtrNm_f32	TunSet_Ptr_Str->k_AsstFWInpLimitBaseAsst_MtrNm_f32
#define k_AsstFWInpLimitHFA_MtrNm_f32	TunSet_Ptr_Str->k_AsstFWInpLimitHFA_MtrNm_f32
#define k_AsstFWNstep_Cnt_u16	TunSet_Ptr_Str->k_AsstFWNstep_Cnt_u16
#define k_AsstFWPstep_Cnt_u16	TunSet_Ptr_Str->k_AsstFWPstep_Cnt_u16
#define k_RestoreThresh_MtrNm_f32	TunSet_Ptr_Str->k_RestoreThresh_MtrNm_f32
#define t_AsstFWDefltAssistX_HwNm_u8p8	TunSet_Ptr_Str->t_AsstFWDefltAssistX_HwNm_u8p8
#define t_AsstFWDefltAssistY_MtrNm_s4p11	TunSet_Ptr_Str->t_AsstFWDefltAssistY_MtrNm_s4p11
#define t_AsstFWPstepNstepThresh_Cnt_u16	TunSet_Ptr_Str->t_AsstFWPstepNstepThresh_Cnt_u16
#define t_AsstFWVehSpd_Kph_u9p7	TunSet_Ptr_Str->t_AsstFWVehSpd_Kph_u9p7
#define t2_AsstFWUprBoundX_HwNm_s4p11	TunSet_Ptr_Str->t2_AsstFWUprBoundX_HwNm_s4p11
#define t2_AsstFWUprBoundY_MtrNm_s4p11	TunSet_Ptr_Str->t2_AsstFWUprBoundY_MtrNm_s4p11

/******************************** AvgFricLrn *********************************/
#define k_AvgFricLPFKn_Hz_f32	TunSet_Ptr_Str->k_AvgFricLPFKn_Hz_f32
#define k_BaselineEOLFric_HwNm_f32	TunSet_Ptr_Str->k_BaselineEOLFric_HwNm_f32
#define k_DataPrepLPFKn_Hz_f32	TunSet_Ptr_Str->k_DataPrepLPFKn_Hz_f32
#define k_EOLFricDiffLimitHigh_HwNm_f32	TunSet_Ptr_Str->k_EOLFricDiffLimitHigh_HwNm_f32
#define k_EOLFricDiffLimitLow_HwNm_f32	TunSet_Ptr_Str->k_EOLFricDiffLimitLow_HwNm_f32
#define k_EOLFricDiffScalingFactor_Uls_f32	TunSet_Ptr_Str->k_EOLFricDiffScalingFactor_Uls_f32
#define k_FricOffsetLimitHigh_HwNm_f32	TunSet_Ptr_Str->k_FricOffsetLimitHigh_HwNm_f32
#define k_FricOffsetLimitLow_HwNm_f32	TunSet_Ptr_Str->k_FricOffsetLimitLow_HwNm_f32
#define k_FricOffsetLPFKn_Hz_f32	TunSet_Ptr_Str->k_FricOffsetLPFKn_Hz_f32
#define k_FrictionDiagThreshold_HwNm_f32	TunSet_Ptr_Str->k_FrictionDiagThreshold_HwNm_f32
#define k_FrictionDiagTimer_mS_u32	TunSet_Ptr_Str->k_FrictionDiagTimer_mS_u32
#define k_HwPosAuthMin_Uls_f32	TunSet_Ptr_Str->k_HwPosAuthMin_Uls_f32
#define k_HwVelConstLimit_HwDegpS_f32	TunSet_Ptr_Str->k_HwVelConstLimit_HwDegpS_f32
#define k_HwVelMax_HwDegpS_f32	TunSet_Ptr_Str->k_HwVelMax_HwDegpS_f32
#define k_HwVelMin_HwDegpS_f32	TunSet_Ptr_Str->k_HwVelMin_HwDegpS_f32
#define k_IgnCycleFricChgLim_HwNm_f32	TunSet_Ptr_Str->k_IgnCycleFricChgLim_HwNm_f32
#define k_LatAccMax_MpSecSqrd_f32	TunSet_Ptr_Str->k_LatAccMax_MpSecSqrd_f32
#define k_LatAccMin_MpSecSqrd_f32	TunSet_Ptr_Str->k_LatAccMin_MpSecSqrd_f32
#define k_LearningGain_Uls_f32	TunSet_Ptr_Str->k_LearningGain_Uls_f32
#define k_LearningThreshold_Cnt_u32	TunSet_Ptr_Str->k_LearningThreshold_Cnt_u32
#define k_RangeCounterLimit_Cnt_u16	TunSet_Ptr_Str->k_RangeCounterLimit_Cnt_u16
#define k_SatFricChgLim_HwNm_f32	TunSet_Ptr_Str->k_SatFricChgLim_HwNm_f32
#define k_TempMax_DegC_f32	TunSet_Ptr_Str->k_TempMax_DegC_f32
#define k_TempMin_DegC_f32	TunSet_Ptr_Str->k_TempMin_DegC_f32
#define t_BaselineFric_HwNm_f32	TunSet_Ptr_Str->t_BaselineFric_HwNm_f32
#define t_FrHystHwAPts_HwDeg_f32	TunSet_Ptr_Str->t_FrHystHwAPts_HwDeg_f32
#define t_FricChgWeight_Uls_f32	TunSet_Ptr_Str->t_FricChgWeight_Uls_f32
#define t_InvRatioX_HwDeg_u11p5	TunSet_Ptr_Str->t_InvRatioX_HwDeg_u11p5
#define t_InvRatioY_HwNmpMtrNm_u6p10	TunSet_Ptr_Str->t_InvRatioY_HwNmpMtrNm_u6p10
#define t_MskVehSpd_Cnt_lgc	TunSet_Ptr_Str->t_MskVehSpd_Cnt_lgc
#define t2_BaselineRangeCounter_Cnt_u16	TunSet_Ptr_Str->t2_BaselineRangeCounter_Cnt_u16
#define t2_BaselineTheta_HwNm_f32	TunSet_Ptr_Str->t2_BaselineTheta_HwNm_f32
#define t2_VehSpd_Kph_f32	TunSet_Ptr_Str->t2_VehSpd_Kph_f32

/****************************** DampingFirewall ******************************/
#define k_DampFWErrThresh_MtrNm_f32	TunSet_Ptr_Str->k_DampFWErrThresh_MtrNm_f32
#define k_DampFWFWActiveLPF_Hz_f32	TunSet_Ptr_Str->k_DampFWFWActiveLPF_Hz_f32
#define k_DampFWInCmpNStep_Cnt_u16	TunSet_Ptr_Str->k_DampFWInCmpNStep_Cnt_u16
#define k_DampFWInCmpPStep_Cnt_u16	TunSet_Ptr_Str->k_DampFWInCmpPStep_Cnt_u16
#define k_DampFWInpLimitDamp_MtrNm_f32	TunSet_Ptr_Str->k_DampFWInpLimitDamp_MtrNm_f32
#define k_DampFWNstep_Cnt_u16	TunSet_Ptr_Str->k_DampFWNstep_Cnt_u16
#define k_DampFWPstep_Cnt_u16	TunSet_Ptr_Str->k_DampFWPstep_Cnt_u16
#define k_DampFWVBICLPF_Hz_f32	TunSet_Ptr_Str->k_DampFWVBICLPF_Hz_f32
#define k_DmpBoundLPFKn_Hz_f32	TunSet_Ptr_Str->k_DmpBoundLPFKn_Hz_f32
#define t_DampFWAddDampAFWX_MtrRadpS_u11p5	TunSet_Ptr_Str->t_DampFWAddDampAFWX_MtrRadpS_u11p5
#define t_DampFWAddDampAFWY_MtrNm_u5p11	TunSet_Ptr_Str->t_DampFWAddDampAFWY_MtrNm_u5p11
#define t_DampFWAddDampDFWX_MtrRadpS_u11p5	TunSet_Ptr_Str->t_DampFWAddDampDFWX_MtrRadpS_u11p5
#define t_DampFWAddDampDFWY_MtrNm_u5p11	TunSet_Ptr_Str->t_DampFWAddDampDFWY_MtrNm_u5p11
#define t_DampFWDampInrtCmpPNThesh_Cnt_u16	TunSet_Ptr_Str->t_DampFWDampInrtCmpPNThesh_Cnt_u16
#define t_DampFWDefltDampX_MtrRadpS_u11p5	TunSet_Ptr_Str->t_DampFWDefltDampX_MtrRadpS_u11p5
#define t_DampFWDefltDampY_MtrNm_u5p11	TunSet_Ptr_Str->t_DampFWDefltDampY_MtrNm_u5p11
#define t_DampFWPNstepThresh_Cnt_u16	TunSet_Ptr_Str->t_DampFWPNstepThresh_Cnt_u16
#define t_DampFWUprBoundX_MtrRadpS_s11p4	TunSet_Ptr_Str->t_DampFWUprBoundX_MtrRadpS_s11p4
#define t_DampFWVehSpd_Kph_u9p7	TunSet_Ptr_Str->t_DampFWVehSpd_Kph_u9p7
#define t2_DampFWUprBoundY_MtrNm_s7p8	TunSet_Ptr_Str->t2_DampFWUprBoundY_MtrNm_s7p8

/******************************** GenPosTraj *********************************/
#define k_PosTrajMaxAngle_HwDeg_f32	TunSet_Ptr_Str->k_PosTrajMaxAngle_HwDeg_f32

/******************************** GMStrtStop *********************************/
#define k_Mode1AssistDD_Uls_f32	TunSet_Ptr_Str->k_Mode1AssistDD_Uls_f32
#define k_Mode1EngTransThresh_Rpm_f32	TunSet_Ptr_Str->k_Mode1EngTransThresh_Rpm_f32
#define k_Mode1VehSpdTransThresh_Kph_f32	TunSet_Ptr_Str->k_Mode1VehSpdTransThresh_Kph_f32
#define k_Mode2AssistDD_Uls_f32	TunSet_Ptr_Str->k_Mode2AssistDD_Uls_f32
#define k_Mode2VehSpdTransThresh_Kph_f32	TunSet_Ptr_Str->k_Mode2VehSpdTransThresh_Kph_f32
#define k_NormalModeEngTransThresh_Rpm_f32	TunSet_Ptr_Str->k_NormalModeEngTransThresh_Rpm_f32
#define k_NormalModeVehSpdTransThresh_Kph_f32	TunSet_Ptr_Str->k_NormalModeVehSpdTransThresh_Kph_f32
#define k_StopMode1HwTrqTransThresh_HwNm_f32	TunSet_Ptr_Str->k_StopMode1HwTrqTransThresh_HwNm_f32
#define k_StopMode1VehSpdTransThres_Kph_f32	TunSet_Ptr_Str->k_StopMode1VehSpdTransThres_Kph_f32
#define k_StopMode2HwTrqTransThresh_HwNm_f32	TunSet_Ptr_Str->k_StopMode2HwTrqTransThresh_HwNm_f32
#define k_StopMode2VehSpdTransThresh_Kph_f32	TunSet_Ptr_Str->k_StopMode2VehSpdTransThresh_Kph_f32
#define k_StopModeAssistDD_Uls_f32	TunSet_Ptr_Str->k_StopModeAssistDD_Uls_f32

/**************************** GmPwrpkSrvDataRcvry ****************************/
#define k_GmPpChk_PwrpkCmpbltyChkRefTiThd_mS_u32	TunSet_Ptr_Str->k_GmPpChk_PwrpkCmpbltyChkRefTiThd_mS_u32

/******************************** HiLoadStall ********************************/
#define k_EOTThrmPrtLPFKn_Cnt_u16	TunSet_Ptr_Str->k_EOTThrmPrtLPFKn_Cnt_u16
#define k_EOTThrmSlwLmtStp_MtrNm_f32	TunSet_Ptr_Str->k_EOTThrmSlwLmtStp_MtrNm_f32
#define t_EOTThrmDpntTbl_MtrNm_u8p8	TunSet_Ptr_Str->t_EOTThrmDpntTbl_MtrNm_u8p8
#define t_EOTThrmIndptTbl_MtrNm_u8p8	TunSet_Ptr_Str->t_EOTThrmIndptTbl_MtrNm_u8p8

/************************ HiLoadStall, ThrmDutyCycle *************************/
#define k_AbsMtrVelBkt_MtrRadps_f32	TunSet_Ptr_Str->k_AbsMtrVelBkt_MtrRadps_f32

/************************** MotAgCorrln, MtrCtrl_CM **************************/
#define k_NoofPoles_Uls_f32	TunSet_Ptr_Str->k_NoofPoles_Uls_f32

/******************************** MtrCtrl_CM *********************************/
#define k_CLOAFdbackSignalSclFacSlew_UlspS_f32	TunSet_Ptr_Str->k_CLOAFdbackSignalSclFacSlew_UlspS_f32
#define k_CuThermCoeff_OhmpDegC_f32	TunSet_Ptr_Str->k_CuThermCoeff_OhmpDegC_f32
#define k_deadtimeVScale_Uls_f32	TunSet_Ptr_Str->k_deadtimeVScale_Uls_f32
#define k_DualEcuSignalSclFacSlew_UlspS_f32	TunSet_Ptr_Str->k_DualEcuSignalSclFacSlew_UlspS_f32
#define k_EstPkCurr2msLPFKn_Uls_u16	TunSet_Ptr_Str->k_EstPkCurr2msLPFKn_Uls_u16
#define k_EstPkCurrSlowLoopLPFKn_Uls_u16	TunSet_Ptr_Str->k_EstPkCurrSlowLoopLPFKn_Uls_u16
#define k_Harmonic12thElec_Uls_f32	TunSet_Ptr_Str->k_Harmonic12thElec_Uls_f32
#define k_Harmonic6thElec_Uls_f32	TunSet_Ptr_Str->k_Harmonic6thElec_Uls_f32
#define k_IdBoostGain_Uls_f32	TunSet_Ptr_Str->k_IdBoostGain_Uls_f32
#define k_IdBoostVRThreshScl_Uls_f32	TunSet_Ptr_Str->k_IdBoostVRThreshScl_Uls_f32
#define k_IdqRefIminNIter_Cnt_u16	TunSet_Ptr_Str->k_IdqRefIminNIter_Cnt_u16
#define k_IdqRefIminTol_Amp_f32	TunSet_Ptr_Str->k_IdqRefIminTol_Amp_f32
#define k_IdqRefLocateRefNIter_Cnt_u16	TunSet_Ptr_Str->k_IdqRefLocateRefNIter_Cnt_u16
#define k_IdqRefTrqNIter_Cnt_u16	TunSet_Ptr_Str->k_IdqRefTrqNIter_Cnt_u16
#define k_IdqRefTrqTol_Rad_f32	TunSet_Ptr_Str->k_IdqRefTrqTol_Rad_f32
#define k_ILOAFdbackSignalSclFacSlew_UlspS_f32	TunSet_Ptr_Str->k_ILOAFdbackSignalSclFacSlew_UlspS_f32
#define k_InstMtrDirHyst_Deg_f32	TunSet_Ptr_Str->k_InstMtrDirHyst_Deg_f32
#define k_KeSatSclAdj_Uls_f32	TunSet_Ptr_Str->k_KeSatSclAdj_Uls_f32
#define k_MagThrC_VpRadpSpDegC_f32	TunSet_Ptr_Str->k_MagThrC_VpRadpSpDegC_f32
#define k_MaxKeRngLmt_VpRadpS_f32	TunSet_Ptr_Str->k_MaxKeRngLmt_VpRadpS_f32
#define k_MaxLdRngLmt_Henry_f32	TunSet_Ptr_Str->k_MaxLdRngLmt_Henry_f32
#define k_MaxLqRngLmt_Henry_f32	TunSet_Ptr_Str->k_MaxLqRngLmt_Henry_f32
#define k_MaxRRngLmt_Ohm_f32	TunSet_Ptr_Str->k_MaxRRngLmt_Ohm_f32
#define k_MaxTrqCmdScl_Uls_f32	TunSet_Ptr_Str->k_MaxTrqCmdScl_Uls_f32
#define k_MinKeRngLmt_VpRadpS_f32	TunSet_Ptr_Str->k_MinKeRngLmt_VpRadpS_f32
#define k_MinLdRngLmt_Henry_f32	TunSet_Ptr_Str->k_MinLdRngLmt_Henry_f32
#define k_MinLqRngLmt_Henry_f32	TunSet_Ptr_Str->k_MinLqRngLmt_Henry_f32
#define k_MinRRngLmt_Ohm_f32	TunSet_Ptr_Str->k_MinRRngLmt_Ohm_f32
#define k_MinTrqCmdScl_Uls_f32	TunSet_Ptr_Str->k_MinTrqCmdScl_Uls_f32
#define k_MtrCtrlCurrLoopSecOrTranFcEnable_Cnt_lgc	TunSet_Ptr_Str->k_MtrCtrlCurrLoopSecOrTranFcEnable_Cnt_lgc
#define k_MtrCtrlFeedbackControlDisable_Cnt_lgc	TunSet_Ptr_Str->k_MtrCtrlFeedbackControlDisable_Cnt_lgc
#define k_MtrCtrlVirualResDax_Ohm_f32	TunSet_Ptr_Str->k_MtrCtrlVirualResDax_Ohm_f32
#define k_MtrCtrlVirualResQax_Ohm_f32	TunSet_Ptr_Str->k_MtrCtrlVirualResQax_Ohm_f32
#define k_MtrCurrDaxMaxValScl_Per_f32	TunSet_Ptr_Str->k_MtrCurrDaxMaxValScl_Per_f32
#define k_MtrCurrQaxRefModifDsb_Cnt_lgc	TunSet_Ptr_Str->k_MtrCurrQaxRefModifDsb_Cnt_lgc
#define k_MtrDampingRatioDax_Uls_f32	TunSet_Ptr_Str->k_MtrDampingRatioDax_Uls_f32
#define k_MtrDampingRatioQax_Uls_f32	TunSet_Ptr_Str->k_MtrDampingRatioQax_Uls_f32
#define k_MtrPosComputationDelay_Sec_f32	TunSet_Ptr_Str->k_MtrPosComputationDelay_Sec_f32
#define k_MtrVoltDervFiltCoeffTimeCons_Sec_f32	TunSet_Ptr_Str->k_MtrVoltDervFiltCoeffTimeCons_Sec_f32
#define k_NomLd_Henry_f32	TunSet_Ptr_Str->k_NomLd_Henry_f32
#define k_NomLdFltAdj_Henry_f32	TunSet_Ptr_Str->k_NomLdFltAdj_Henry_f32
#define k_NomLq_Henry_f32	TunSet_Ptr_Str->k_NomLq_Henry_f32
#define k_NomLqFltAdj_Henry_f32	TunSet_Ptr_Str->k_NomLqFltAdj_Henry_f32
#define k_NomRfet_Ohm_f32	TunSet_Ptr_Str->k_NomRfet_Ohm_f32
#define k_NomTemp_DegC_f32	TunSet_Ptr_Str->k_NomTemp_DegC_f32
#define k_PIGainVspdCutoff_kph_f32	TunSet_Ptr_Str->k_PIGainVspdCutoff_kph_f32
#define k_PiSamplingTs_Sec_f32	TunSet_Ptr_Str->k_PiSamplingTs_Sec_f32
#define k_SiThermCoeff_OhmpDegC_f32	TunSet_Ptr_Str->k_SiThermCoeff_OhmpDegC_f32
#define t_CurrParamCompDaxRef_Amp_u9p7	TunSet_Ptr_Str->t_CurrParamCompDaxRef_Amp_u9p7
#define t_CurrParamCompQaxRef_Amp_u9p7	TunSet_Ptr_Str->t_CurrParamCompQaxRef_Amp_u9p7
#define t_KeSatTblX_Amp_u9p7	TunSet_Ptr_Str->t_KeSatTblX_Amp_u9p7
#define t_KeSatTblY_Uls_u2p14	TunSet_Ptr_Str->t_KeSatTblY_Uls_u2p14
#define t_MtrCurrDaxRpl_Amp_u9p7	TunSet_Ptr_Str->t_MtrCurrDaxRpl_Amp_u9p7
#define t_MtrCurrQaxRpl_Amp_u9p7	TunSet_Ptr_Str->t_MtrCurrQaxRpl_Amp_u9p7
#define t_Q13VltgSchedXTbl_MtrRadpS_u12p4	TunSet_Ptr_Str->t_Q13VltgSchedXTbl_MtrRadpS_u12p4
#define t_Q13VltgSchedYTbl_Volt_u5p11	TunSet_Ptr_Str->t_Q13VltgSchedYTbl_Volt_u5p11
#define t_Q24VltgSchedXTbl_MtrRadpS_u12p4	TunSet_Ptr_Str->t_Q24VltgSchedXTbl_MtrRadpS_u12p4
#define t_Q24VltgSchedYTbl_Volt_u5p11	TunSet_Ptr_Str->t_Q24VltgSchedYTbl_Volt_u5p11
#define t_RefDeltaPoints_Rad_f32	TunSet_Ptr_Str->t_RefDeltaPoints_Rad_f32
#define t_TrqRplCogRampDown12thY_Uls_u0p16	TunSet_Ptr_Str->t_TrqRplCogRampDown12thY_Uls_u0p16
#define t_TrqRplCogRampDown6thY_Uls_u0p16	TunSet_Ptr_Str->t_TrqRplCogRampDown6thY_Uls_u0p16
#define t_TrqRplCogRampDownVoltSatX_Uls_u0p16	TunSet_Ptr_Str->t_TrqRplCogRampDownVoltSatX_Uls_u0p16
#define t2_CurrParamLdSatSclFac_Uls_u2p14	TunSet_Ptr_Str->t2_CurrParamLdSatSclFac_Uls_u2p14
#define t2_CurrParamLqSatSclFac_Uls_u2p14	TunSet_Ptr_Str->t2_CurrParamLqSatSclFac_Uls_u2p14
#define t2_MtrTrqRpl12X_MtrNm_s2p13	TunSet_Ptr_Str->t2_MtrTrqRpl12X_MtrNm_s2p13
#define t2_MtrTrqRpl12Y_MtrNm_s2p13	TunSet_Ptr_Str->t2_MtrTrqRpl12Y_MtrNm_s2p13
#define t2_MtrTrqRpl6X_MtrNm_s2p13	TunSet_Ptr_Str->t2_MtrTrqRpl6X_MtrNm_s2p13
#define t2_MtrTrqRpl6Y_MtrNm_s2p13	TunSet_Ptr_Str->t2_MtrTrqRpl6Y_MtrNm_s2p13

/******************************** MtrTempEst *********************************/
#define k_AMAmbLPFKn_Hz_f32	TunSet_Ptr_Str->k_AMAmbLPFKn_Hz_f32
#define k_AMAmbMult_DegCpWatt_f32	TunSet_Ptr_Str->k_AMAmbMult_DegCpWatt_f32
#define k_AmbPwrMult_WtspAmpSq_f32	TunSet_Ptr_Str->k_AmbPwrMult_WtspAmpSq_f32
#define k_AmbTempScl_Uls_f32	TunSet_Ptr_Str->k_AmbTempScl_Uls_f32
#define k_AMDampScl_NmpRadpS_f32	TunSet_Ptr_Str->k_AMDampScl_NmpRadpS_f32
#define k_AMLLFiltCoefB0_Uls_f32	TunSet_Ptr_Str->k_AMLLFiltCoefB0_Uls_f32
#define k_AMLLFiltCoefB1_Uls_f32	TunSet_Ptr_Str->k_AMLLFiltCoefB1_Uls_f32
#define k_AMLLFiltPoleA1_Uls_f32	TunSet_Ptr_Str->k_AMLLFiltPoleA1_Uls_f32
#define k_AssistMechSlew_DegCpS_f32	TunSet_Ptr_Str->k_AssistMechSlew_DegCpS_f32
#define k_CuAmbLPFKn_Hz_f32	TunSet_Ptr_Str->k_CuAmbLPFKn_Hz_f32
#define k_CuAmbMult_DegCpWatt_f32	TunSet_Ptr_Str->k_CuAmbMult_DegCpWatt_f32
#define k_CuLLFiltKA1_Uls_f32	TunSet_Ptr_Str->k_CuLLFiltKA1_Uls_f32
#define k_CuLLFiltKB0_Uls_f32	TunSet_Ptr_Str->k_CuLLFiltKB0_Uls_f32
#define k_CuLLFiltKB1_Uls_f32	TunSet_Ptr_Str->k_CuLLFiltKB1_Uls_f32
#define k_EngTempScl_Uls_f32	TunSet_Ptr_Str->k_EngTempScl_Uls_f32
#define k_MagAmbLPFKn_Hz_f32	TunSet_Ptr_Str->k_MagAmbLPFKn_Hz_f32
#define k_MagAmbMult_DegCpWatt_f32	TunSet_Ptr_Str->k_MagAmbMult_DegCpWatt_f32
#define k_MagLLFiltKA1_Uls_f32	TunSet_Ptr_Str->k_MagLLFiltKA1_Uls_f32
#define k_MagLLFiltKB0_Uls_f32	TunSet_Ptr_Str->k_MagLLFiltKB0_Uls_f32
#define k_MagLLFiltKB1_Uls_f32	TunSet_Ptr_Str->k_MagLLFiltKB1_Uls_f32
#define k_SiAmbLPFKn_Hz_f32	TunSet_Ptr_Str->k_SiAmbLPFKn_Hz_f32
#define k_SiAmbMult_DegCpWatt_f32	TunSet_Ptr_Str->k_SiAmbMult_DegCpWatt_f32
#define k_SiLLFiltKA1_Uls_f32	TunSet_Ptr_Str->k_SiLLFiltKA1_Uls_f32
#define k_SiLLFiltKB0_Uls_f32	TunSet_Ptr_Str->k_SiLLFiltKB0_Uls_f32
#define k_SiLLFiltKB1_Uls_f32	TunSet_Ptr_Str->k_SiLLFiltKB1_Uls_f32
#define k_TrimTempAM_DegC_f32	TunSet_Ptr_Str->k_TrimTempAM_DegC_f32
#define k_TrimTempCu_DegC_f32	TunSet_Ptr_Str->k_TrimTempCu_DegC_f32
#define k_TrimTempMag_DegC_f32	TunSet_Ptr_Str->k_TrimTempMag_DegC_f32
#define k_TrimTempSi_DegC_f32	TunSet_Ptr_Str->k_TrimTempSi_DegC_f32
#define k_WtAvgTempDFt_Cnt_lgc	TunSet_Ptr_Str->k_WtAvgTempDFt_Cnt_lgc

/********************************* PosServo **********************************/
#define k_PrkAstDTermKn_Hz_f32	TunSet_Ptr_Str->k_PrkAstDTermKn_Hz_f32
#define k_PrkAstEnableRate_pSec_f32	TunSet_Ptr_Str->k_PrkAstEnableRate_pSec_f32
#define k_PrkAstHwaLPFKn_Hz_f32	TunSet_Ptr_Str->k_PrkAstHwaLPFKn_Hz_f32
#define k_PrkAstHwTrqLPFKn_Hz_f32	TunSet_Ptr_Str->k_PrkAstHwTrqLPFKn_Hz_f32
#define k_PrkAstPIDLimit_MtrNm_u9p7	TunSet_Ptr_Str->k_PrkAstPIDLimit_MtrNm_u9p7
#define t_HwaRateLimit_HwDegpSec_u12p4	TunSet_Ptr_Str->t_HwaRateLimit_HwDegpSec_u12p4
#define t_PosSrvoMaxCmdX_Kph_u9p7	TunSet_Ptr_Str->t_PosSrvoMaxCmdX_Kph_u9p7
#define t_PosSrvoMaxCmdY_MtrNm_u5p11	TunSet_Ptr_Str->t_PosSrvoMaxCmdY_MtrNm_u5p11
#define t_PrkAstDGainY_MtrNmmSpHwDeg_u7p9	TunSet_Ptr_Str->t_PrkAstDGainY_MtrNmmSpHwDeg_u7p9
#define t_PrkAstDisableRateX_HwNm_u11p5	TunSet_Ptr_Str->t_PrkAstDisableRateX_HwNm_u11p5
#define t_PrkAstDisableRateY_pSec_u12p4	TunSet_Ptr_Str->t_PrkAstDisableRateY_pSec_u12p4
#define t_PrkAstDmpTrqX_MtrRadpS_u11p5	TunSet_Ptr_Str->t_PrkAstDmpTrqX_MtrRadpS_u11p5
#define t_PrkAstIGainY_MtrNmpHwDegS_u2p14	TunSet_Ptr_Str->t_PrkAstIGainY_MtrNmpHwDegS_u2p14
#define t_PrkAstITermAWLmtY_MtrNm_u9p7	TunSet_Ptr_Str->t_PrkAstITermAWLmtY_MtrNm_u9p7
#define t_PrkAstPGainX_HwDeg_u12p4	TunSet_Ptr_Str->t_PrkAstPGainX_HwDeg_u12p4
#define t_PrkAstSmoothX_Uls_u6p10	TunSet_Ptr_Str->t_PrkAstSmoothX_Uls_u6p10
#define t_PrkAstSmoothY_Uls_u6p10	TunSet_Ptr_Str->t_PrkAstSmoothY_Uls_u6p10
#define t_PrkAstVehSpdBS_Kph_u9p7	TunSet_Ptr_Str->t_PrkAstVehSpdBS_Kph_u9p7
#define t2_PrkAstDmpTrqY_MtrNm_u4p12	TunSet_Ptr_Str->t2_PrkAstDmpTrqY_MtrNm_u4p12
#define t2_PrkAstPGainY_MtrNm_u9p7	TunSet_Ptr_Str->t2_PrkAstPGainY_MtrNm_u9p7

/******************************* PwrLmtFuncCr ********************************/
#define k_AsstReducLPFKn_Hz_f32	TunSet_Ptr_Str->k_AsstReducLPFKn_Hz_f32
#define k_FiltAsstReducTh_Uls_f32	TunSet_Ptr_Str->k_FiltAsstReducTh_Uls_f32
#define k_KeStdTemp_VpRadpS_f32	TunSet_Ptr_Str->k_KeStdTemp_VpRadpS_f32
#define k_LowVltAstRecTh_Volt_f32	TunSet_Ptr_Str->k_LowVltAstRecTh_Volt_f32
#define k_LowVltAstRecTime_mS_u16	TunSet_Ptr_Str->k_LowVltAstRecTime_mS_u16
#define k_PwrLmt_NumofInverters_Cnt_u08	TunSet_Ptr_Str->k_PwrLmt_NumofInverters_Cnt_u08
#define k_PwrLmtMtrVelLPFKn_Hz_f32	TunSet_Ptr_Str->k_PwrLmtMtrVelLPFKn_Hz_f32
#define k_PwrLmtVecuAdjSlew_VoltspL_f32	TunSet_Ptr_Str->k_PwrLmtVecuAdjSlew_VoltspL_f32
#define k_PwrLmtVecuAltFltAdj_Volt_f32	TunSet_Ptr_Str->k_PwrLmtVecuAltFltAdj_Volt_f32
#define k_SpdAdjSlewDec_MtrRadpS_f32	TunSet_Ptr_Str->k_SpdAdjSlewDec_MtrRadpS_f32
#define k_SpdAdjSlewEnable_Cnt_lgc	TunSet_Ptr_Str->k_SpdAdjSlewEnable_Cnt_lgc
#define k_SpdAdjSlewInc_MtrRadpS_f32	TunSet_Ptr_Str->k_SpdAdjSlewInc_MtrRadpS_f32
#define t_DLVTblX_Volt_u5p11	TunSet_Ptr_Str->t_DLVTblX_Volt_u5p11
#define t_DLVTblY_MtrRadpS_u11p5	TunSet_Ptr_Str->t_DLVTblY_MtrRadpS_u11p5
#define t_MtrEnvTblX_MtrRadpS_s11p4	TunSet_Ptr_Str->t_MtrEnvTblX_MtrRadpS_s11p4
#define t_MtrEnvTblY_MtrNm_u5p11	TunSet_Ptr_Str->t_MtrEnvTblY_MtrNm_u5p11
#define t_StdOpMtrEnvTblX_MtrRadpS_u11p5	TunSet_Ptr_Str->t_StdOpMtrEnvTblX_MtrRadpS_u11p5
#define t_StdOpMtrEnvTblY_MtrNm_u4p12	TunSet_Ptr_Str->t_StdOpMtrEnvTblY_MtrNm_u4p12

/******************************** SrlComInput ********************************/
#define k_AmbTempDflt_DegC_f32	TunSet_Ptr_Str->k_AmbTempDflt_DegC_f32
#define k_AmbTempValTimeOut_mS_u16p0	TunSet_Ptr_Str->k_AmbTempValTimeOut_mS_u16p0
#define k_EngTempDflt_DegC_f32	TunSet_Ptr_Str->k_EngTempDflt_DegC_f32
#define k_EngTempValTimeOut_mS_u16p0	TunSet_Ptr_Str->k_EngTempValTimeOut_mS_u16p0

/******************************* ThrmDutyCycle *******************************/
#define k_AbsTempDiag_Cnt_str	TunSet_Ptr_Str->k_AbsTempDiag_Cnt_str
#define k_AbsTmpTrqSlewLmt_MtrNm_f32	TunSet_Ptr_Str->k_AbsTmpTrqSlewLmt_MtrNm_f32
#define k_CtrlTempSlc_Cnt_lgc	TunSet_Ptr_Str->k_CtrlTempSlc_Cnt_lgc
#define k_DefaultIgnOffTime_Sec_f32	TunSet_Ptr_Str->k_DefaultIgnOffTime_Sec_f32
#define k_DutyCycFltTrshld_Uls_u16p0	TunSet_Ptr_Str->k_DutyCycFltTrshld_Uls_u16p0
#define k_EOCCtrlTemp_DegC_f32	TunSet_Ptr_Str->k_EOCCtrlTemp_DegC_f32
#define k_IgnOffCntrEnb_Cnt_lgc	TunSet_Ptr_Str->k_IgnOffCntrEnb_Cnt_lgc
#define k_IgnOffMsgWaitTime_Sec_f32	TunSet_Ptr_Str->k_IgnOffMsgWaitTime_Sec_f32
#define k_MtrPrTempSlc_Cnt_lgc	TunSet_Ptr_Str->k_MtrPrTempSlc_Cnt_lgc
#define k_MultTempSlc_Cnt_lgc	TunSet_Ptr_Str->k_MultTempSlc_Cnt_lgc
#define k_SlowFltTempSlc_Cnt_lgc	TunSet_Ptr_Str->k_SlowFltTempSlc_Cnt_lgc
#define k_TrqCmdSlewDown_MtrNm_u9p7	TunSet_Ptr_Str->k_TrqCmdSlewDown_MtrNm_u9p7
#define k_TrqCmdSlewUp_MtrNm_u9p7	TunSet_Ptr_Str->k_TrqCmdSlewUp_MtrNm_u9p7
#define t_AbsCtrlTmpTblX_DegC_s15p0	TunSet_Ptr_Str->t_AbsCtrlTmpTblX_DegC_s15p0
#define t_AbsCtrlTmpTblY_MtrNm_u9p7	TunSet_Ptr_Str->t_AbsCtrlTmpTblY_MtrNm_u9p7
#define t_AbsCuTmpTblX_DegC_s15p0	TunSet_Ptr_Str->t_AbsCuTmpTblX_DegC_s15p0
#define t_AbsCuTmpTblY_MtrNm_u9p7	TunSet_Ptr_Str->t_AbsCuTmpTblY_MtrNm_u9p7
#define t_LastTblValNS_MtrNm_u9p7	TunSet_Ptr_Str->t_LastTblValNS_MtrNm_u9p7
#define t_LastTblValS_MtrNm_u9p7	TunSet_Ptr_Str->t_LastTblValS_MtrNm_u9p7
#define t_Mult1NSTblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult1NSTblY_Uls_u3p13
#define t_Mult1STblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult1STblY_Uls_u3p13
#define t_Mult2NSTblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult2NSTblY_Uls_u3p13
#define t_Mult2STblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult2STblY_Uls_u3p13
#define t_Mult3NSTblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult3NSTblY_Uls_u3p13
#define t_Mult3STblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult3STblY_Uls_u3p13
#define t_Mult4NSTblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult4NSTblY_Uls_u3p13
#define t_Mult4STblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult4STblY_Uls_u3p13
#define t_Mult5NSTblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult5NSTblY_Uls_u3p13
#define t_Mult5STblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult5STblY_Uls_u3p13
#define t_Mult6NSTblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult6NSTblY_Uls_u3p13
#define t_Mult6STblY_Uls_u3p13	TunSet_Ptr_Str->t_Mult6STblY_Uls_u3p13
#define t_MultTblX_DegC_s15p0	TunSet_Ptr_Str->t_MultTblX_DegC_s15p0
#define t_ThrmLoadLmtTblX_Uls_u16p0	TunSet_Ptr_Str->t_ThrmLoadLmtTblX_Uls_u16p0
#define t_ThrmLoadLmtTblY_MtrNm_u9p7	TunSet_Ptr_Str->t_ThrmLoadLmtTblY_MtrNm_u9p7

/********************************* TrqArblim *********************************/
#define k_APAEnableRate_pSec_f32	TunSet_Ptr_Str->k_APAEnableRate_pSec_f32
#define k_APASmoothHwTrqLPFKn_Hz_f32	TunSet_Ptr_Str->k_APASmoothHwTrqLPFKn_Hz_f32
#define k_APAUseADmpScale_lgc	TunSet_Ptr_Str->k_APAUseADmpScale_lgc
#define k_APAUseAsstScale_lgc	TunSet_Ptr_Str->k_APAUseAsstScale_lgc
#define k_APAUseRetScale_lgc	TunSet_Ptr_Str->k_APAUseRetScale_lgc
#define k_ESCMax_HwNm_f32	TunSet_Ptr_Str->k_ESCMax_HwNm_f32
#define k_GmTqArbn_LKAOutpOvrlUpprLim_MtrNm_f32	TunSet_Ptr_Str->k_GmTqArbn_LKAOutpOvrlUpprLim_MtrNm_f32
#define k_GmTqArbn_LKAScagGain_Uls_f32	TunSet_Ptr_Str->k_GmTqArbn_LKAScagGain_Uls_f32
#define t_APADisableRateX_HwNm_u4p12	TunSet_Ptr_Str->t_APADisableRateX_HwNm_u4p12
#define t_APADisableRateY_pSec_u7p9	TunSet_Ptr_Str->t_APADisableRateY_pSec_u7p9
#define t_APASmoothX_Uls_u2p14	TunSet_Ptr_Str->t_APASmoothX_Uls_u2p14
#define t_APASmoothY_Uls_u2p14	TunSet_Ptr_Str->t_APASmoothY_Uls_u2p14

/********************************* TrqOvlSta *********************************/
#define k_APAHwTrqLPFKn_Hz_f32	TunSet_Ptr_Str->k_APAHwTrqLPFKn_Hz_f32
#define k_APAMaxHwTrq_HwNm_f32	TunSet_Ptr_Str->k_APAMaxHwTrq_HwNm_f32
#define k_APAMaxHwTrqTime_Sec_f32	TunSet_Ptr_Str->k_APAMaxHwTrqTime_Sec_f32
#define k_APAMaxVehSpd_Kph_f32	TunSet_Ptr_Str->k_APAMaxVehSpd_Kph_f32
#define k_ESCMaxVehSpd_Kph_f32	TunSet_Ptr_Str->k_ESCMaxVehSpd_Kph_f32
#define k_GMOSH_HapticDuration_mS_u32	TunSet_Ptr_Str->k_GMOSH_HapticDuration_mS_u32
#define k_GMOSH_HapticReactTime_mS_u32	TunSet_Ptr_Str->k_GMOSH_HapticReactTime_mS_u32
#define k_GMOSH_HwTrqOscnLPFKn_Hz_f32	TunSet_Ptr_Str->k_GMOSH_HwTrqOscnLPFKn_Hz_f32
#define k_GMOSH_LKAHwTrqLPFKn_Hz_f32	TunSet_Ptr_Str->k_GMOSH_LKAHwTrqLPFKn_Hz_f32
#define k_GMOSH_LKAMaxHwTrq_HwNm_f32	TunSet_Ptr_Str->k_GMOSH_LKAMaxHwTrq_HwNm_f32
#define k_GMOSH_LKAMaxHwTrqTime_mS_u32	TunSet_Ptr_Str->k_GMOSH_LKAMaxHwTrqTime_mS_u32
#define k_GMOSH_LoaMtgtnHaptcFbOffTi_mS_u32	TunSet_Ptr_Str->k_GMOSH_LoaMtgtnHaptcFbOffTi_mS_u32
#define k_GMOSH_LoaMtgtnHaptcFbOnTi_mS_u32	TunSet_Ptr_Str->k_GMOSH_LoaMtgtnHaptcFbOnTi_mS_u32
#define k_GMOSH_LoaMtgtnHaptcFbStrtOnTi_mS_u32	TunSet_Ptr_Str->k_GMOSH_LoaMtgtnHaptcFbStrtOnTi_mS_u32
#define k_GMOSH_LoaMtgtnHaptcFbTqMax_HwNm_f32	TunSet_Ptr_Str->k_GMOSH_LoaMtgtnHaptcFbTqMax_HwNm_f32
#define k_GMOSH_LoaMtgtnHaptcFbTqMin_HwNm_f32	TunSet_Ptr_Str->k_GMOSH_LoaMtgtnHaptcFbTqMin_HwNm_f32
#define k_GMOSH_LoaMtgtnHaptcFbVehSpdMax_Kph_f32	TunSet_Ptr_Str->k_GMOSH_LoaMtgtnHaptcFbVehSpdMax_Kph_f32
#define k_GMOSH_LoaMtgtnHaptcFbVehSpdMin_Kph_f32	TunSet_Ptr_Str->k_GMOSH_LoaMtgtnHaptcFbVehSpdMin_Kph_f32
#define k_GMOSH_LoaMtgtnHaptcFrq_Hz_f32	TunSet_Ptr_Str->k_GMOSH_LoaMtgtnHaptcFrq_Hz_f32
#define k_GMOSH_LoaMtgtnStrtHaptcAmp_MtrNm_f32	TunSet_Ptr_Str->k_GMOSH_LoaMtgtnStrtHaptcAmp_MtrNm_f32
#define k_GMOSH_LoaStIgnCntrThd_Cnt_u16	TunSet_Ptr_Str->k_GMOSH_LoaStIgnCntrThd_Cnt_u16
#define k_HapticAmplitude_MtrNm_f32	TunSet_Ptr_Str->k_HapticAmplitude_MtrNm_f32
#define k_HapticFreq_Hz_f32	TunSet_Ptr_Str->k_HapticFreq_Hz_f32
#define k_LKAMaxVehSpd_Kph_f32	TunSet_Ptr_Str->k_LKAMaxVehSpd_Kph_f32
#define k_LKAMinVehSpd_Kph_f32	TunSet_Ptr_Str->k_LKAMinVehSpd_Kph_f32
#define k_MaxHapticReqTime_Sec_f32	TunSet_Ptr_Str->k_MaxHapticReqTime_Sec_f32
#define k_ShiftLevRevTime_Sec_f32	TunSet_Ptr_Str->k_ShiftLevRevTime_Sec_f32
#define k_StandstillThresh_Kph_f32	TunSet_Ptr_Str->k_StandstillThresh_Kph_f32
#define k_StandstillTime_Sec_f32	TunSet_Ptr_Str->k_StandstillTime_Sec_f32
#define k_SWARLimiter_HwDeg_f32	TunSet_Ptr_Str->k_SWARLimiter_HwDeg_f32
#define t_GMOSH_LoaMtgtnTqOscnAmpY_MtrNm_u2p14	TunSet_Ptr_Str->t_GMOSH_LoaMtgtnTqOscnAmpY_MtrNm_u2p14
#define t_GMOSH_LoaMtgtnVehSpdX_Kph_u10p6	TunSet_Ptr_Str->t_GMOSH_LoaMtgtnVehSpdX_Kph_u10p6

/********************************* VehSpdLmt *********************************/
#define k_PosMaxOfstOne_HwDeg_u12p4	TunSet_Ptr_Str->k_PosMaxOfstOne_HwDeg_u12p4
#define k_PosMaxOfstTwo_HwDeg_u12p4	TunSet_Ptr_Str->k_PosMaxOfstTwo_HwDeg_u12p4

/******************************** ActivePull *********************************/
#define k_EnableHwAuthMin_Uls_f32	TunPer_Ptr_Str->k_EnableHwAuthMin_Uls_f32

/********************************** Assist ***********************************/
#define t_AsstThermSclX_Cnt_u16p0	TunPer_Ptr_Str->t_AsstThermSclX_Cnt_u16p0
#define t_AsstThermSclY_Uls_u2p14	TunPer_Ptr_Str->t_AsstThermSclY_Uls_u2p14
#define t2_AsstAsstY0_MtrNm_s4p11	TunPer_Ptr_Str->t2_AsstAsstY0_MtrNm_s4p11
#define t2_AsstAsstY1_MtrNm_s4p11	TunPer_Ptr_Str->t2_AsstAsstY1_MtrNm_s4p11
#define t2_AsstHwtX0_HwNm_u8p8	TunPer_Ptr_Str->t2_AsstHwtX0_HwNm_u8p8
#define t2_AsstHwtX1_HwNm_u8p8	TunPer_Ptr_Str->t2_AsstHwtX1_HwNm_u8p8
#define t2_AsstWIRBlendY_Uls_u2p14	TunPer_Ptr_Str->t2_AsstWIRBlendY_Uls_u2p14
#define t2_AsstWIRBlndX_MtrNm_u5p11	TunPer_Ptr_Str->t2_AsstWIRBlndX_MtrNm_u5p11

/********************************** Damping **********************************/
#define k_HPSOutLimit_MtrNm_f32	TunPer_Ptr_Str->k_HPSOutLimit_MtrNm_f32
#define t_HPSAsstLimY_MtrNm_u4p12	TunPer_Ptr_Str->t_HPSAsstLimY_MtrNm_u4p12
#define t_HPSscaleC1Y_Uls_u4p12	TunPer_Ptr_Str->t_HPSscaleC1Y_Uls_u4p12
#define t_HPSscaleC2Y_Uls_u4p12	TunPer_Ptr_Str->t_HPSscaleC2Y_Uls_u4p12
#define t_HPSscaleC3Y_Uls_u4p12	TunPer_Ptr_Str->t_HPSscaleC3Y_Uls_u4p12
#define t_HPSscaleC4Y_Uls_u4p12	TunPer_Ptr_Str->t_HPSscaleC4Y_Uls_u4p12
#define t_HwTrqDmpTblX_HwNm_u8p8	TunPer_Ptr_Str->t_HwTrqDmpTblX_HwNm_u8p8
#define t_HwTrqDmpTblY_Uls_u1p15	TunPer_Ptr_Str->t_HwTrqDmpTblY_Uls_u1p15
#define t_TempScaleX_DegC_s8p7	TunPer_Ptr_Str->t_TempScaleX_DegC_s8p7
#define t_TempScaleY_Uls_u4p12	TunPer_Ptr_Str->t_TempScaleY_Uls_u4p12
#define t2_MtrVelDmpTblX_MtrRadpS_u12p4	TunPer_Ptr_Str->t2_MtrVelDmpTblX_MtrRadpS_u12p4
#define t2_MtrVelDmpTblY_MtrNm_u5p11	TunPer_Ptr_Str->t2_MtrVelDmpTblY_MtrNm_u5p11

/****************************** DampingFirewall ******************************/
#define t_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17	TunPer_Ptr_Str->t_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17

/******************** DampingFirewall, FrqDepDmpnInrtCmp *********************/
#define t_DmpADDCoefX_MtrNm_u4p12	TunPer_Ptr_Str->t_DmpADDCoefX_MtrNm_u4p12
#define t_DmpFiltKpWIRBlndY_Uls_u2p14	TunPer_Ptr_Str->t_DmpFiltKpWIRBlndY_Uls_u2p14
#define t_FDD_AttenTblX_MtrRadpS_u12p4	TunPer_Ptr_Str->t_FDD_AttenTblX_MtrRadpS_u12p4
#define t_FDD_AttenTblY_Uls_u8p8	TunPer_Ptr_Str->t_FDD_AttenTblY_Uls_u8p8
#define t_FDD_BlendTblY_Uls_u8p8	TunPer_Ptr_Str->t_FDD_BlendTblY_Uls_u8p8
#define t_InrtCmp_ScaleFactorTblY_Uls_u9p7	TunPer_Ptr_Str->t_InrtCmp_ScaleFactorTblY_Uls_u9p7
#define t_InrtCmp_TBarVel_ScaleFactorTblY_Uls_u9p7	TunPer_Ptr_Str->t_InrtCmp_TBarVel_ScaleFactorTblY_Uls_u9p7
#define t_RIAstWIRBlndTblY_Uls_u2p14	TunPer_Ptr_Str->t_RIAstWIRBlndTblY_Uls_u2p14
#define t_WIRBlndTblX_MtrNm_u8p8	TunPer_Ptr_Str->t_WIRBlndTblX_MtrNm_u8p8
#define t2_FDD_ADDRollingTblYM_MtrNmpRadpS_um1p17	TunPer_Ptr_Str->t2_FDD_ADDRollingTblYM_MtrNmpRadpS_um1p17
#define t2_FDD_FreqTblYM_Hz_u12p4	TunPer_Ptr_Str->t2_FDD_FreqTblYM_Hz_u12p4

/****************************** EOTActuatorMng *******************************/
#define k_EOTDeltaTrqThrsh_HwNm_u9p7	TunPer_Ptr_Str->k_EOTDeltaTrqThrsh_HwNm_u9p7
#define k_EOTEnterLPFKn_Cnt_u16	TunPer_Ptr_Str->k_EOTEnterLPFKn_Cnt_u16
#define k_EOTExitLPFKn_Cnt_u16	TunPer_Ptr_Str->k_EOTExitLPFKn_Cnt_u16
#define k_EOTImpSpdEn_Kph_u9p7	TunPer_Ptr_Str->k_EOTImpSpdEn_Kph_u9p7
#define k_EOTStateHwTrqLPFKn_Cnt_u16	TunPer_Ptr_Str->k_EOTStateHwTrqLPFKn_Cnt_u16
#define k_PosRampStep_HwDeg_u12p4	TunPer_Ptr_Str->k_PosRampStep_HwDeg_u12p4
#define k_SpdIptScale_MtrNmpRadpS_u4p12	TunPer_Ptr_Str->k_SpdIptScale_MtrNmpRadpS_u4p12
#define t_EOTDmpVspd_Kph_u9p7	TunPer_Ptr_Str->t_EOTDmpVspd_Kph_u9p7
#define t_EOTEnterGainVspd_Kph_u9p7	TunPer_Ptr_Str->t_EOTEnterGainVspd_Kph_u9p7
#define t_SpdIptTblXTbl_HwDeg_u12p4	TunPer_Ptr_Str->t_SpdIptTblXTbl_HwDeg_u12p4
#define t_SpdIptTblYTbl_MtrRadpS_u12p4	TunPer_Ptr_Str->t_SpdIptTblYTbl_MtrRadpS_u12p4
#define t_TrqTableX_HwNm_u8p8	TunPer_Ptr_Str->t_TrqTableX_HwNm_u8p8
#define t2_EOTEnterGainX_HwDeg_u12p4	TunPer_Ptr_Str->t2_EOTEnterGainX_HwDeg_u12p4
#define t2_EOTEnterGainY_Uls_u1p15	TunPer_Ptr_Str->t2_EOTEnterGainY_Uls_u1p15
#define t2_EOTExPosDepDmpTblY_MtrNmpRadps_u0p16	TunPer_Ptr_Str->t2_EOTExPosDepDmpTblY_MtrNmpRadps_u0p16
#define t2_EOTPosDepDmpTblY_MtrNmpRadpS_u0p16	TunPer_Ptr_Str->t2_EOTPosDepDmpTblY_MtrNmpRadpS_u0p16

/************************** EOTActuatorMng, EtDmpFw **************************/
#define t2_EOTPosDepDmpTblX_HwDeg_u12p4	TunPer_Ptr_Str->t2_EOTPosDepDmpTblX_HwDeg_u12p4

/***************************** FrqDepDmpnInrtCmp *****************************/
#define t2_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17	TunPer_Ptr_Str->t2_FDD_ADDStaticTblY_MtrNmpRadpS_um1p17

/****************************** HighFreqAssist *******************************/
#define t_LPFKnY_Hz_u7p9	TunPer_Ptr_Str->t_LPFKnY_Hz_u7p9
#define t2_GainY0_MtrNmpHwNm_u3p13	TunPer_Ptr_Str->t2_GainY0_MtrNmpHwNm_u3p13
#define t2_GainY1_MtrNmpHwNm_u3p13	TunPer_Ptr_Str->t2_GainY1_MtrNmpHwNm_u3p13
#define t2_TorqX0_HwNm_u5p11	TunPer_Ptr_Str->t2_TorqX0_HwNm_u5p11
#define t2_TorqX1_HwNm_u5p11	TunPer_Ptr_Str->t2_TorqX1_HwNm_u5p11
#define t2_WIRBlendX_MtrNm_u4p12	TunPer_Ptr_Str->t2_WIRBlendX_MtrNm_u4p12
#define t2_WIRBlendY_Uls_u1p15	TunPer_Ptr_Str->t2_WIRBlendY_Uls_u1p15

/********************************* HystComp **********************************/
#define k_HysCmpHwTrqLPFKn_Hz_f32	TunPer_Ptr_Str->k_HysCmpHwTrqLPFKn_Hz_f32
#define k_HysCmpLPAstLPFKn_Hz_f32	TunPer_Ptr_Str->k_HysCmpLPAstLPFKn_Hz_f32
#define k_HysFinalOutLPFKn_Hz_f32	TunPer_Ptr_Str->k_HysFinalOutLPFKn_Hz_f32
#define k_HysOutLIm_HwNm_f32	TunPer_Ptr_Str->k_HysOutLIm_HwNm_f32
#define k_HysRevGain_InvHwNm_f32	TunPer_Ptr_Str->k_HysRevGain_InvHwNm_f32
#define k_LpFricIpLim_HwNm_u9p7	TunPer_Ptr_Str->k_LpFricIpLim_HwNm_u9p7
#define t_EffLossTblY_Uls_u4p12	TunPer_Ptr_Str->t_EffLossTblY_Uls_u4p12
#define t_EffOffTblY_HwNm_u9p7	TunPer_Ptr_Str->t_EffOffTblY_HwNm_u9p7
#define t_HysCompCoulFricTempScaleX_DegC_s14p1	TunPer_Ptr_Str->t_HysCompCoulFricTempScaleX_DegC_s14p1
#define t_HysCompCoulFricTempScaleY_HwNm_u9p7	TunPer_Ptr_Str->t_HysCompCoulFricTempScaleY_HwNm_u9p7
#define t_HysCompCoulFricWIRBlendX_MtrNm_u8p8	TunPer_Ptr_Str->t_HysCompCoulFricWIRBlendX_MtrNm_u8p8
#define t_HysCompCoulFricWIRBlendY_Uls_u2p14	TunPer_Ptr_Str->t_HysCompCoulFricWIRBlendY_Uls_u2p14
#define t_HysCompCoulFricY_HwNm_u9p7	TunPer_Ptr_Str->t_HysCompCoulFricY_HwNm_u9p7
#define t_HysCompHysSatY_HwNm_u9p7	TunPer_Ptr_Str->t_HysCompHysSatY_HwNm_u9p7
#define t_HysCompNegHysBlendX_HwNm_u9p7	TunPer_Ptr_Str->t_HysCompNegHysBlendX_HwNm_u9p7
#define t_HysCompNegHysBlendY_Uls_u2p14	TunPer_Ptr_Str->t_HysCompNegHysBlendY_Uls_u2p14
#define t_HysCompNegHysCompX_MtrNm_u8p8	TunPer_Ptr_Str->t_HysCompNegHysCompX_MtrNm_u8p8
#define t_HysCompNegHysCompY_HwNm_u9p7	TunPer_Ptr_Str->t_HysCompNegHysCompY_HwNm_u9p7
#define t_HysRiseTblX_HwNm_u2p14	TunPer_Ptr_Str->t_HysRiseTblX_HwNm_u2p14
#define t_HysRiseTblY_Uls_u2p14	TunPer_Ptr_Str->t_HysRiseTblY_Uls_u2p14
#define t2_HysHwTrqBlndTblX_HwNm_u4p12	TunPer_Ptr_Str->t2_HysHwTrqBlndTblX_HwNm_u4p12
#define t2_HysHwTrqBlndTblY_Uls_u4p12	TunPer_Ptr_Str->t2_HysHwTrqBlndTblY_Uls_u4p12

/********************************* TrqArblim *********************************/
#define k_GmTqArbn_LKA_OutputLim_HwNm_f32	TunPer_Ptr_Str->k_GmTqArbn_LKA_OutputLim_HwNm_f32
#define k_LKAUseSlewCal_lgc	TunPer_Ptr_Str->k_LKAUseSlewCal_lgc
#define t_LKASlewX_Kph_u8p8	TunPer_Ptr_Str->t_LKASlewX_Kph_u8p8
#define t_LKASlewY_NmpSec_u4p12	TunPer_Ptr_Str->t_LKASlewY_NmpSec_u4p12
#define t2_GmTqArbn_LKAOutpOvrlX_HwNm_u8p8	TunPer_Ptr_Str->t2_GmTqArbn_LKAOutpOvrlX_HwNm_u8p8
#define t2_GmTqArbn_LKAOutpOvrlY_MtrNm_u8p8	TunPer_Ptr_Str->t2_GmTqArbn_LKAOutpOvrlY_MtrNm_u8p8

/********************************* WhlImbRej *********************************/
#define k_WIRVehSpdEnable_Kph_f32	TunPer_Ptr_Str->k_WIRVehSpdEnable_Kph_f32
#endif

/*********************** Start of Code Footer ************************/

extern P2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) TunPer_Ptr_Str;
extern P2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) TunSet_Ptr_Str;
extern CONSTP2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16][D_NUMOFPERS_CNT_U16];
extern CONSTP2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16];
















