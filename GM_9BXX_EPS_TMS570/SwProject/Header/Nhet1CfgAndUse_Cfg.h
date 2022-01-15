/*****************************************************************************
* Copyright 2015 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Nhet1CfgAndUse_Cfg.h
* Module Description: FDD ES-35B (Nhet1 configuration and use)
* Product           : CBD
* Author            : Yue Zhao
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* %version:          1 %
* %derived_by:       CZ8L9T %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  ----------
* 06/09/15  1        Yue Zhao         Nhet1 Configuration and Use												EA3#1297
*
*---------------------------------------------------------------------------*/

#ifndef NHET1CFGANDUSE_CFG_H
#define NHET1CFGANDUSE_CFG_H


#include "Std_Types.h"
#include "CDD_Data.h"
#include "Dma.h"


#define Nhet1CfgAndUse_Read_PWMPeriod_u16(ptr) (*ptr)= CDD_PWMPeriod_Cnt_G_u16;


/*  the following macro needs to be defined for where the PWM Period counts for the NHET should be written
	for example, if DMA is used to write PWM period to the NHET, the macro should be defined to 
	copy the value to the appropriate DMA data structure   */

#define Nhet1CfgAndUse_Write_PWMPeriod_Cnt_u16(val) DMAData_G_str.PWMPeriod_Cnt_u32 = (uint32)(val)

#endif
