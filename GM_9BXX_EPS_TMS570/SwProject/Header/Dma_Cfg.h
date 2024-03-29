/*********************************************************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Dma_Cfg.h
* Module Description: DMA Peripheral Configuration Header
* Product           : Gen II Plus - EA3.0
* Author            : Owen Tosh
*********************************************************************************************************************/
/***********************************************************************************************************************
* Version Control:
* Date Created:      Tue Mar 11 12:00:00 2014
* %version:          EA3#2 %
* %derived_by:       CZ8L9T %
* %date_modified:    Wed Apr 30 12:00:00 2014 %
***********************************************************************************************************************/
/***********************************************************************************************************************
* Change History:
* Date      Rev      Author    Change Description                                                                CR#
* --------  -------  --------  --------------------------------------------------------------------------------- -----
* 04/08/14   1       OT        Initial version
* 04/29/14   2       OT        Added DiagMgr configuration                                                       11855
* 09/24/15   3       JK        Anomaly fix EA3#2825 - Made the NHET header file configurable                  EA3#3286
***********************************************************************************************************************/


#ifndef DMA_CFG_H
#define DMA_CFG_H

#define D_DMAFLSTSTENABLED_CNT_ENUM         STD_ON  /* FlsTst Init Groups */
#define D_FASTSPIGROUPENABLED_CNT_ENUM      STD_ON  /* 50us SPI Group */
#define D_FASTADCGROUPENABLED_CNT_ENUM      STD_ON  /* 50us ADC Group */
#define D_FASTPWMGROUPENABLED_CNT_ENUM      STD_ON  /* 50us PWM Group */
#define D_SLOWADCGROUPENABLED_CNT_ENUM      STD_ON  /* 2ms ADC Group */

#define DMA_REPORTERRORSTATUS(event, param, status)		NxtrDiagMgr10_SetNTCStatus(event, param, status)

/* Header file containing the definition of HET_PRD_BUF1_0 should be used */
#define DMA_NHET1PROGHFILE "Nhet1CfgAndUse_Prog.h"

#endif
