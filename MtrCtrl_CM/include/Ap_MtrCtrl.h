/*****************************************************************************
* Copyright 2017-15,2012 Nexteer 
* Nexteer Confidential
*
* Module File Name  : Ap_MtrCtrl.h
* Module Description: Header file for Motor control component
* Project           : CBD
* Author            : Selva Sengottaiyan
*****************************************************************************
* Version Control:
* %version:          EA3#6 %
* %derived_by:       nz2554 %
*----------------------------------------------------------------------------------------------------------------------
*   Date       Rev      Author                    Change Description                                           SCR #
* ---------  -------  ----------  -----------------------------------------------------------------------  ------------
* 03/21/12    1        Selva       Updated to version 8 FDD SF99B                                            7711		
* 08/19/15    4        Selva       Updated for V17 of FDD SF99B                                             EA3#2430
* 07/21/16    5        Rijvi       Updated for V19 of FDD SF99B                                             EA3#9293
* 01/04/17    6        SR          Updated for v20 of FDD SF99B                                             EA3#13142
******************************************************************************/

#ifndef MTRCTRL_H
#define MTRCTRL_H

#ifdef MTRCTRL

typedef struct {
    VAR(float32, AUTOMATIC)       PrevInput_Uls_f32;
    VAR(float32, AUTOMATIC)       PrevOutput_Uls_f32;
    VAR(float32, AUTOMATIC)       TermN_Uls_f32;
    VAR(float32, AUTOMATIC)       TermD_Uls_f32;
} LowPassFiltBilinear_Str;

extern VAR(float32, AUTOMATIC) MtrCurrQaxRef_Amp_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCurrDaxRef_Amp_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrDaxIntegralGain_Ohm_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrDaxPropotionalGain_Ohm_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrQaxIntegralGain_Ohm_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrQaxPropotionalGain_Ohm_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrPosComputationDelay_Rad_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrVoltDaxFF_Volt_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrVoltQaxFF_Volt_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrEstKe_VpRadpS_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrCurrQaxCogRpl_Amp_M_f32;
extern VAR(uint16 , AUTOMATIC) FastDataAccessBufIndex_Cnt_M_u16;
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrDampTermDax_Ohm_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrDampTermQax_Ohm_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrImpedDax_Ohm_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrImpedQax_Ohm_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrCurrDaxMaxVal_Amp_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_MtrPosComputationDelayRpl_Rad_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_Vecu_Volt_M_f32[2];
extern VAR(float32, AUTOMATIC) MtrCtrl_VoltSatIndicFf_Uls_M_f32;

#endif

extern FUNC(void, PICurrCntrl_CODE) PICurrCntrl_Per1(void);
extern FUNC(void, IPMTRQCANC_CODE) TrqCogCancRefPer1(void);

#endif
