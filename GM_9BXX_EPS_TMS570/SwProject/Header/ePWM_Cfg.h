/*****************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name  : ePWM_Cfg_Template.h
* Module Description: This is a template for the manual configuration file needed for the ePWM component
* Product           : CBD
* Author            : Selva Sengottaiyan
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* %version:          EA3#2 %
* %derived_by:       CZ8L9T %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     ----------
* 08/20/15    1		 Rijvi		Changed macros needed for ES34E rev.001								            EA3#1300
******************************************************************************/

#ifndef EPWM_CFG_H
#define EPWM_CFG_H

#include "Std_Types.h"
#include "CDD_Data.h"
#include "Dma.h"

#define D_CONFIGHETREGDMA_CNT_U32  1UL  /* 0UL if no DMA and 1UL if using DMA*/

#define ePWM_Read_PWMPeriod_u16(ptr)  (*ptr) = CDD_PWMPeriod_Cnt_G_u16;

#define  ePWM_Read_DCPhsAComp_u16(ptr) (*ptr) = CDD_DCPhsComp_Cnt_G_u16[0];
#define  ePWM_Read_DCPhsBComp_u16(ptr) (*ptr) = CDD_DCPhsComp_Cnt_G_u16[1];
#define  ePWM_Read_DCPhsCComp_u16(ptr) (*ptr) = CDD_DCPhsComp_Cnt_G_u16[2];
#define  ePWM_Read_ePWM4CMPB_Cnt_u16(ptr) (*ptr) = CDD_ePWM4CMPB_Cnt_G_u16;

/*  the following macros need to be defined for where the ePWM CMPA and CMPB counts should be written
	for example, if DMA is used for the data for all four ePWMs, all eight macros should be defined to
	copy the value to the appropriate DMA data structure(s)   */
#define  ePWM_Write_ePWM1CMPA_Cnt_u16(val) DMAData_G_str.PWMCmp_Cnt_u16[0][0] = (val)
#define  ePWM_Write_ePWM1CMPB_Cnt_u16(val) DMAData_G_str.PWMCmp_Cnt_u16[0][1] = (val)
#define  ePWM_Write_ePWM2CMPA_Cnt_u16(val) DMAData_G_str.PWMCmp_Cnt_u16[1][0] = (val)
#define  ePWM_Write_ePWM2CMPB_Cnt_u16(val) DMAData_G_str.PWMCmp_Cnt_u16[1][1] = (val)
#define  ePWM_Write_ePWM3CMPA_Cnt_u16(val) DMAData_G_str.PWMCmp_Cnt_u16[2][0] = (val)
#define  ePWM_Write_ePWM3CMPB_Cnt_u16(val) DMAData_G_str.PWMCmp_Cnt_u16[2][1] = (val)
#define  ePWM_Write_ePWM4CMPA_Cnt_u16(val) DMAData_G_str.PWMCmp_Cnt_u16[3][0] = (val)
#define  ePWM_Write_ePWM4CMPB_Cnt_u16(val) DMAData_G_str.PWMCmp_Cnt_u16[3][1] = (val)

#endif
