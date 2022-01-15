/*****************************************************************************
/*****************************************************************************
* Copyright 2015, 2016 Nexteer Automotive
* Nexteer Confidential
*
* Module File Name  : MtrCtrl_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Mar 23 13:00:00 2013
* %version:          EA3#7 %
* %derived_by:       fz9hxm %
* %date_modified:    Wed Jun  5 11:31:23 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 03/11/15   2       Selva      Initial template creation                                                    CR12888
 * 07/21/16	  4       Rijvi      Updated for V19 of FDD SF99                                                  EA3#9293
 */


#ifndef MTRCTRL_CFG_H
#define MTRCTRL_CFG_H


#include "CDD_Data.h"


#define MtrCntrl_Read_MtrCurrQax_Amp_f32(ptr)               *(ptr) = CDD_MtrCurrQax_Amp_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] /* This is native to MtrCtrl Loop, but is buffered because it is also used in 2ms loop */
#define MtrCntrl_Read_MtrCurrDax_Amp_f32(ptr)               *(ptr) = CDD_MtrCurrDax_Amp_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] /* This is native to MtrCtrl Loop, but is buffered because it is also used in 2ms loop */
#define MtrCntrl_Read_ModIdxSrlComSvcDft_Cnt_lgc(ptr)       *(ptr) = CDD_ModIdxSrlComSvcDft_Cnt_G_u16 /* This is written in 2ms loop, but on event, so no buffer required */
#define MtrCntrl_Read_SysState_Cnt_Enum(ptr)                *(ptr) = CDD_SysState_Cnt_G_Enum /* This is written in 2ms loop, but only changes with system state change, so no buffer required */
#define MtrCntrl_Read_MtrCurrOffComOffset_Cnt_u16(ptr)      *(ptr) = CDD_MtrCurrOffComOffset_Cnt_G_u16[CDD_AppDataFwdPthAccessBfr_Cnt_G_u16] /* This data is written in 2ms loop */
#define MtrCntrl_Read_MtrElecPol_Cnt_s8(ptr)                *(ptr) = CDD_MtrElecPol_Cnt_G_s8 /* This is written in 2ms loop, but on event, so no buffer required */
#define MtrCntrl_Read_MtrPosElec_Rev_u0p16(ptr)             *(ptr) = CDD_MotPosnElec_Rev_G_u0p16[CDD_CDDDataAccessBfr_Cnt_G_u16] /* This is native to MtrCtrl Loop, but read in 2ms loop */
#define MtrCntrl_Read_IvtrLoaMtgtnEn_Cnt_lgc(ptr)           *(ptr) = CDD_IvtrLoaMtgtnEn_Cnt_G_lgc /* from LOA manager through CDD interface */
#define MtrCntrl_Read_MotCurrLoaMtgtnEn_Cnt_lgc(ptr)        *(ptr) = CDD_MotCurrLoaMtgtnEn_Cnt_G_lgc /* from LOA manager through CDD interface */
#define MtrCntrl_Read_DualEcuMotCtrlMtgnEna_Cnt_lgc(ptr)    *(ptr) =	0x00U;/*Unused*/		/********* from LOA manager through CDD interface**********/ 
#define MtrCntrl_Write_MtrCurrQaxFinalRef_Amp_f32(val)      CDD_MtrCurrQaxFinalRef_Amp_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (val) /* This is read in 2ms loop */
#define MtrCntrl_Write_MtrDaxVoltage_Volt_f32(val)          CDD_MtrDaxVoltage_Volt_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (val)
#define MtrCntrl_Write_MtrQaxVoltage_Volt_f32(val)          CDD_MtrQaxVoltage_Volt_G_f32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (val)
#define MtrCntrl_Write_ModIdx_Uls_u16p16(val)               CDD_ModIdxFinal_Uls_G_u16p16 = (val) /* This is read in 2ms loop */
#define MtrCntrl_Write_PhaseAdvanceFinal_Rev_u0p16(val)     CDD_PhaseAdvFinal_Cnt_G_u16 = (val)  /* This is read in 2ms loop */

#define MtrCntrl_Write_CommOffset_Cnt_u16(val)              CDD_CommOffset_Cnt_G_u16 = (val) /* This is read only in MtrCtrl Loop */

#endif
