/*****************************************************************************
* Copyright 2012 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : PwmCdd_Cfg.h
* Module Description: Pwm Complex Driver configuration
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Dec  7 20:09:21 2010
* %version:          EA3#4 %
* %derived_by:       CZ8L9T %
* %date_modified:    Fri Aug 30 09:38:32 2013 %
*---------------------------------------------------------------------------*/


#ifndef PWMCDD_CFG_H
#define PWMCDD_CFG_H

#include "CDD_Data.h"

#define d_PwmFreq_Hz_Cnt_u16            75000000UL
#define d_PWMFreqDither_Hz_u16          2000U

#define CDD_Read_PhaseAdvanceFinal_Rev_u0p16(ptr)       *(ptr) = (CDD_PhaseAdvFinal_Cnt_G_u16) /* This is native to MtrCtrl Loop, but is buffered because it is also used in 2ms loop */
#define PwmCdd_Read_ModIdxFinal_Uls_u16p16(ptr)         *(ptr) = CDD_ModIdxFinal_Uls_G_u16p16
#define CDD_Read_CorrectedMtrPos_Rev_u0p16(ptr)         *(ptr) = CDD_MotPosnElec_Rev_G_u0p16[CDD_CDDDataAccessBfr_Cnt_G_u16] /* This is native to MtrCtrl Loop, but read in 2ms loop */
#define CDD_Read_CommOffset_Cnt_u16(ptr)                *(ptr) = CDD_CommOffset_Cnt_G_u16 /* This is native to MtrCtrl Loop */

#define CDD_Write_DCPhsBComp_Cnt_u16p0(val)     (void)0  /* Disable optional write, not required */
#define CDD_Write_DCPhsCComp_Cnt_u16p0(val)     (void)0  /* Disable optional write, not required */

#endif
