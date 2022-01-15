/*****************************************************************************
* Copyright 2015 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
* Module File Name  : CmMtrCurr3Phs_Cfg.h
* Module Description: Configuration header file for ES-01F 
* Project           : CBD
* Author            : Michael Mondeau
*****************************************************************************/
/* Version Control:
 * %version:          1 %
 * %derived_by:       CZ8L9T %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #  
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/17/15 	1 		MLM		Initial implementation of ES-01F  											  EA3#1774
 */


#ifndef CMMTRCURR3PHS_CFG_H
#define CMMTRCURR3PHS_CFG_H

/* Includes */
#include "Dma.h"
#include "Adc2.h"
#include "CDD_Data.h"

//extern float32 CDD_CorrMtrCurrB_Amp_G_f32;
//extern float32 CDD_CorrMtrCurrC_Amp_G_f32;
//extern float32 CDD_CorrMtrCurrA_Amp_G_f32;
//extern float32 CDD_MtrCurrB_Volt_G_f32;
//extern float32 CDD_MtrCurrC_Volt_G_f32;
//extern float32 CDD_MtrCurrA_Volt_G_f32;
//extern float32 CDD_ElecPosDelayComp_Rad_G_f32;
//extern float32 CDD_MtrCurrQax_Amp_G_f32;
//extern float32 CDD_MtrCurrDax_Amp_G_f32;
//extern float32 CDD_CorrMtrPosElec_Rev_G_f32;
//extern uint16 CDD_ADC2OffsetComp_Cnt_G_u8p8;
//extern sint8 CDD_MtrElecPol_Cnt_G_s8;
//extern uint16 MtrPos_CorrectedMtrPos_Rev_G_u0p16;
//extern float32 CDD_MtrCurrBTempOffset_Volt_G_f32;
//extern float32 CDD_MtrCurrCTempOffset_Volt_G_f32;
//extern float32 CDD_MtrCurrATempOffset_Volt_G_f32;
//extern uint16 CDD_DCPhsComp_Cnt_G_u16[];
//extern uint16 Adc2_GetPhsBCurr_Cnt_u16_m;
//extern uint16 Adc2_GetPhsCCurr_Cnt_u16_m;
//extern uint16 Adc2_GetPhsACurr_Cnt_u16_m;
//extern  float32  CDD_Vecu_Volt_G_f32;
//extern  float32 CDD_MRFMtrVel_MtrRadpS_G_f32;

#define D_ADCRESULTMASK_CNT_U16 0x0FFFu

/* Inputs */
#define CmMtrCurr3Phs_Read_MRFMtrVel_MtrRadpS_f32(ptr)      *(ptr) = CDD_MRFMtrVel_MtrRadpS_G_f32[CDD_AppDataFwdPthAccessBfr_Cnt_G_u16]
#define CmMtrCurr3Phs_Read_Vecu_Volt_f32(ptr)               *(ptr) = CDD_Vecu_Volt_G_f32[CDD_AppDataFwdPthAccessBfr_Cnt_G_u16]
#define CmMtrCurr3Phs_Read_PhsACurr_Cnt_u16(ptr)            (*(ptr) = DMAData_G_str.FastADC_Cnt_u16[D_PHASEACHN_CNT_U16] & D_ADCRESULTMASK_CNT_U16)
#define CmMtrCurr3Phs_Read_PhsBCurr_Cnt_u16(ptr)            (*(ptr) = DMAData_G_str.FastADC_Cnt_u16[D_PHASEBCHN_CNT_U16] & D_ADCRESULTMASK_CNT_U16)
#define CmMtrCurr3Phs_Read_PhsCCurr_Cnt_u16(ptr)            (*(ptr) = DMAData_G_str.FastADC_Cnt_u16[D_PHASECCHN_CNT_U16] & D_ADCRESULTMASK_CNT_U16)
#define CmMtrCurr3Phs_Read_DCPhsAComp_Cnt_u16(ptr)          *(ptr) = CDD_DCPhsComp_Cnt_G_u16[0u]
#define CmMtrCurr3Phs_Read_DCPhsBComp_Cnt_u16(ptr)          *(ptr) = CDD_DCPhsComp_Cnt_G_u16[1u]
#define CmMtrCurr3Phs_Read_DCPhsCComp_Cnt_u16(ptr)          *(ptr) = CDD_DCPhsComp_Cnt_G_u16[2u]
#define CmMtrCurr3Phs_Read_MtrCurrATempOffset_Volt_f32(ptr) *(ptr) = CDD_MtrCurrATempOffset_Volt_G_f32[CDD_AppDataFwdPthAccessBfr_Cnt_G_u16]
#define CmMtrCurr3Phs_Read_MtrCurrBTempOffset_Volt_f32(ptr) *(ptr) = CDD_MtrCurrBTempOffset_Volt_G_f32[CDD_AppDataFwdPthAccessBfr_Cnt_G_u16]
#define CmMtrCurr3Phs_Read_MtrCurrCTempOffset_Volt_f32(ptr) *(ptr) = CDD_MtrCurrCTempOffset_Volt_G_f32[CDD_AppDataFwdPthAccessBfr_Cnt_G_u16]

#define CmMtrCurr3Phs_Read_MtrElecPol_Cnt_s08(ptr)          *(ptr) = CDD_MtrElecPol_Cnt_G_s8 /* This is written in 2ms loop, but on event, so no buffer required */
#define CmMtrCurr3Phs_Read_MtrPosElec_Rev_u0p16(ptr)        *(ptr) = CDD_MotPosnElec_Rev_G_u0p16[CDD_CDDDataAccessBfr_Cnt_G_u16] /* This is native to MtrCtrl Loop, but read in 2ms loop */

#define CmMtrCurr3Phs_Read_ADC2OffsetComp_Cnt_u8p8(ptr)     *(ptr) = CDD_ADC2OffsetComp_Cnt_G_u8p8 /* Map the output to the ADC2 calibration compensation */

/* Outputs */
#define CmMtrCurr3Phs_Write_ElecPosDelayComp_Rad_f32(val)    (void)0 /* Unused Output */
#define CmMtrCurr3Phs_Write_MtrCurrQax_Amp_f32(val)          CDD_MtrCurrQax_Amp_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (val)
#define CmMtrCurr3Phs_Write_MtrCurrDax_Amp_f32(val)          CDD_MtrCurrDax_Amp_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (val)
#define CmMtrCurr3Phs_Write_CorrMtrCurrPosition_Rev_f32(val) CDD_CorrMtrCurrPosition_Rev_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (val)

#define CmMtrCurr3Phs_Write_MtrCurrA_Volt_f32(val) CDD_MtrCurrA_Volts_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (val)
#define CmMtrCurr3Phs_Write_MtrCurrB_Volt_f32(val) CDD_MtrCurrB_Volts_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (val)
#define CmMtrCurr3Phs_Write_MtrCurrC_Volt_f32(val) CDD_MtrCurrC_Volts_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (val)

#define CmMtrCurr3Phs_Write_CorrMtrCurrA_Amp_f32(val) CDD_CorrMtrCurrA_Amps_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (val)
#define CmMtrCurr3Phs_Write_CorrMtrCurrB_Amp_f32(val) CDD_CorrMtrCurrB_Amps_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (val)
#define CmMtrCurr3Phs_Write_CorrMtrCurrC_Amp_f32(val) CDD_CorrMtrCurrC_Amps_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (val)

#endif
