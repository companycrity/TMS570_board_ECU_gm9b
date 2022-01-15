/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CDD_Data.h
* Module Description: Header file for data communicated between Nexteer
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#8 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Wed Dec  4 11:32:36 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 12/01/15  6        GMN       EA3#4064: Update SF-99 and 83.3Hz noise reduction                             4962
 * 07/06/16  8        GMN       EA3#9207: Update MtrCtrl inputs connected to LOA
 */

#ifndef CDD_DATA_H
#define CDD_DATA_H

#include "Std_Types.h"
#include "CDD_Const.h"
#include "Dem.h"
#include "Dem_Lcfg.h"
#include "Rte_Type.h"
#include "Ap_DemIf.h"

/* MotMeclPosn1 */
extern VAR(sint8, CDD_VAR) CDD_MotMeclPosn1Polarity_Cnt_G_s08[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint8, CDD_VAR) CDD_MotMeclPosn1RollgCntr_Cnt_G_u08[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR) CDD_MotMeclPosn1RevM_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR) CDD_MotMeclPosn1RawErrReg_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR) CDD_MotMeclPosn1UnderVltgFaultAccum_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR) CDD_MotMeclPosn1ParityFaultAccum_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR) CDD_MotMeclPosn1MeasdTi_uS_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(SigQlfr_State_enum, CDD_VAR) CDD_MotMeclPosn1MotPosnQlfrCnt_G_u08[D_APPCDDBFRSIZE_CNT_U16];

/* MotMeclPosn2 */
extern VAR(sint8, CDD_VAR) CDD_MotMeclPosn2Polarity_Cnt_G_s08[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint8, CDD_VAR) CDD_MotMeclPosn2RollgCntr_Cnt_G_u08[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR) CDD_MotMeclPosn2RevM_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR) CDD_MotMeclPosn2RawErrReg_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR) CDD_MotMeclPosn2UnderVltgFaultAccum_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16, CDD_VAR) CDD_MotMeclPosn2ParityFaultAccum_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(SigQlfr_State_enum, CDD_VAR) CDD_MotMeclPosn2MotPosnQlfrCnt_G_u08[D_APPCDDBFRSIZE_CNT_U16];

/* MotPosnCmp */
extern VAR(uint16, CDD_VAR) CDD_MotPosnElec_Rev_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(sint32, CDD_VAR) CDD_MotPosnCumvAlgnd_Rev_G_s15p16[D_APPCDDBFRSIZE_CNT_U16];

/* MotAgCorrln */
extern VAR(uint16, CDD_VAR) CDD_MotAgCorrlnMtrPosCorrlnSts_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];

/* DigMSBArbn */
extern VAR(uint16, CDD_VAR) CDD_MtrPosMecl_RevM_G_u0p16[D_APPCDDBFRSIZE_CNT_U16];

/* MtrCtrl */
extern VAR(uint16, CDD_VAR) CDD_PhaseAdvFinal_Cnt_G_u16;
extern VAR(uint16, CDD_VAR) CDD_BufferedPhaseAdvFinal_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR) CDD_ModIdxFinal_Uls_G_u16p16;
extern VAR(uint32, CDD_VAR) CDD_BufferedModIdxFinal_Uls_G_u16p16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_MtrDaxVoltage_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_MtrQaxVoltage_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_MtrCurrQaxFinalRef_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];

extern VAR(boolean, AP_SRLCOMOUTPUT_VAR) DTCTriggeredFlag_Cnt_M_lgc[D_NUMOFDEMEVENTS_CNT_U08 + 1U];
extern VAR(boolean, APPDESC_VAR_NOINIT) ECUResetPerformed_Cnt_G_lgc;
extern VAR(uint8, AUTOMATIC) RespMsgBuffer[D_CANRESPLMT_CNT_U8];
extern VAR(uint16,  CDD_VAR) CDD_CommOffset_Cnt_G_u16;
extern VAR(uint8, CDD_VAR) CDD_DemIdSnapshot_Cnt_G_u08;
extern VAR(boolean, CDD_VAR) CDD_DisableCEBusNormComm_Cnt_lgc;
extern VAR(boolean, CDD_VAR) CDD_BallNutTempEstDisableSvc_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR) CDD_DisableHSBusNormComm_Cnt_lgc;
extern VAR(boolean, CDD_VAR) CDD_PullCompDisableSvc_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR) CDD_PwrAsstModeSvc_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR) CDD_SftEndStpDisableSvc_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR) CDD_GenPosTrajEnableFlag_Cnt_G_lgc;

/* CmMtrCurr3Phs */
extern VAR(float32, CDD_VAR) CDD_MtrCurrA_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_MtrCurrB_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_MtrCurrC_Volts_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_CorrMtrCurrA_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_CorrMtrCurrB_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_CorrMtrCurrC_Amps_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_MtrCurrQax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_MtrCurrDax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_CorrMtrCurrPosition_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];

extern VAR(float32, CDD_VAR) CDD_MtrCurrATempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_MtrCurrBTempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_MtrCurrCTempOffset_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,CDD_VAR) CDD_MtrCurrOffComOffset_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];

extern VAR(float32, CDD_VAR) CDD_MtrCurrQax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_MtrCurrDax_Amp_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_VAR) CDD_SysCBattSwitched1_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_VAR) CDD_SysCBattSwitched2_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_VAR) CDD_SysCT1Adc_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,  CDD_VAR) CDD_SysCT2Adc_Cnt_G_u16[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_MRFMtrVel_MtrRadpS_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_CorrMtrCurrPosition_Rev_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(float32, CDD_VAR) CDD_Vecu_Volt_G_f32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint16,CDD_VAR)	CDD_ModIdxSrlComSvcDft_Cnt_G_u16;
extern VAR(sint8,CDD_VAR)	CDD_MtrElecPol_Cnt_G_s8;
extern VAR(Rte_ModeType_StaMd_Mode, CDD_VAR) CDD_SysState_Cnt_G_Enum;

/* MtrCtrl */
extern VAR(boolean,CDD_VAR) CDD_IvtrLoaMtgtnEn_Cnt_G_lgc;
extern VAR(boolean,CDD_VAR) CDD_MotCurrLoaMtgtnEn_Cnt_G_lgc;

extern VAR(uint32, CDD_VAR) CDD_PWMDutyCycleASum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR) CDD_PWMDutyCycleBSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR) CDD_PWMDutyCycleCSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(uint32, CDD_VAR) CDD_PWMPeriodSum_Cnt_G_u32[D_APPCDDBFRSIZE_CNT_U16];

/* Data Native to Application Loop */
extern VAR(boolean, CDD_VAR) CDD_PwmDisable_Cnt_G_lgc[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(sint8,   CDD_DATA_VAR) CDD_MtrPosPolarity_Cnt_G_s08[D_APPCDDBFRSIZE_CNT_U16];
extern VAR(sint8,   CDD_DATA_VAR) CDD_AssistAssemblyPolarity_Cnt_G_s08[D_APPCDDBFRSIZE_CNT_U16];

/* Data Consistancy Buffer Access Variables */
extern VAR(uint16, CDD_VAR) CDD_AppDataFwdPthAccessBfr_Cnt_G_u16;
extern VAR(uint16, CDD_VAR) CDD_AppDataFbkPthAccessBfr_Cnt_G_u16;
extern VAR(uint16, CDD_VAR) CDD_CDDDataAccessBfr_Cnt_G_u16;

/* EOL Global Data */
extern VAR(uint16, CDD_VAR) CDD_EOLCustWIRSelect_Cnt_G_u16;
extern VAR(uint16, CDD_VAR) CDD_EOLNxtrWIRSelect_Cnt_G_u16;
extern VAR(uint16, CDD_VAR) CDD_ADC1OffsetComp_Cnt_G_u8p8;
extern VAR(uint16, CDD_VAR) CDD_ADC2OffsetComp_Cnt_G_u8p8;
extern VAR(uint32, CDD_VAR) CDD_EOLSrlComSvcDft_Cnt_G_b32;

extern VAR(boolean, CDD_VAR) CDD_WIRDisableSvc_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR) CDD_DftAsstTbl_Cnt_G_lgc;
extern VAR(float32, CDD_VAR) CDD_DwnldAsstGain_Uls_G_f32;

/* ePWM Globals */
extern VAR(uint16, CDD_VAR_NOINT) CDD_DCPhsComp_Cnt_G_u16[3];
extern VAR(uint16, CDD_VAR_NOINT) CDD_PWMPeriod_Cnt_G_u16;
extern VAR(uint16, CDD_VAR_NOINT) CDD_ePWM4CMPB_Cnt_G_u16;

#endif
