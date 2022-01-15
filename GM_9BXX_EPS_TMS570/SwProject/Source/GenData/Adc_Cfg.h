/*****************************************************************************
* Copyright 2012 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Adc_Cfg.h
* Module Description: Adc Driver configuration
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Jul 28 18:03:04 2012
* %version:          EA3#2 %
* %derived_by:       CZ8L9T %
* %date_modified:    Tue Oct  8 10:28:20 2013 %
*---------------------------------------------------------------------------*/


#ifndef ADC_CFG_H
#define ADC_CFG_H


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#include "Adc.h"
#include "SchM_Adc.h"
#include "CDD_Data.h"
/*** For 33E ADc (Current mode) define the following macro ***/
#define D_ADC1CURRENTMODE_ULS_LGC

/* Map user defined group conversion names to appropriate group indexer */
#define AdcFwdPath     		D_GROUP1_CNT_U8
#define AdcFdbkPath     	D_GROUP2_CNT_U8
#define adcGROUP0			D_GROUPEV_CNT_U8

#define D_ADC1NUMEVTCH_CNT_U08	0U				/* Number of channels sampled (e.g. number of bits set in D_ADC1EVTCH_CNT_U32) */
#define D_ADC1EVTCH_CNT_U32		0x0000UL
#define D_ADC1EVTBUFSZ_CNT_U08	52U				/* Number of results allocated in ADC RAM, must be even */

#define D_ADC1NUMG1CH_CNT_U08	0U				/* Number of channels sampled (e.g. number of bits set in D_ADC1G1CH_CNT_U32) */
#define D_ADC1G1CH_CNT_U32		0x0000UL
#define D_ADC1G1BUFSZ_CNT_U08	0U				/* Number of results allocated in ADC RAM, must be even */

#define D_ADC1NUMG2CH_CNT_U08   12U             /* Number of channels sampled (e.g. number of bits set in D_ADC1G2CH_CNT_U32) */
#define D_ADC1G2CH_CNT_U32      0x80E7E3UL      /* Channel configuration - Value founded in FDD SelRegister cell */
#define D_ADC1G2BUFSZ_CNT_U08   12U             /* Number of results allocated in ADC RAM, must be even */

/* AdcFdbkPath result buffer indices */
//#define D_TEMPSNSRCHN_CNT_U16		0u
//#define D_BATTCHN_CNT_U16			1u
//#define D_VREFCHN_CNT_U16			2u
//#define D_BATTSWITCHEDCHN_CNT_U16	3u
#define D_TEMPERATURE_CNT_U16       0U
#define D_VREF3P3_CNT_U16           1U
#define D_BATT_CNT_U16              2U
#define D_ADC1DUMMYREAD_CNT_U16     3U
#define D_VREF5VP2_CNT_U16          4U
#define D_VREF5VP1_CNT_U16          5U
#define D_MTRPOS3SIN_CNT_U16        6U
#define D_MTRPOS3COS_CNT_U16        7U
#define D_BATTSWITCHED1_CNT_U16     8U
#define D_HWTRQT1ADC_CNT_U16        9U
#define D_HWTRQT2ADC_CNT_U16        10U
#define D_BATTSWITCHED2_CNT_U16     11U

#define ADC1_REPORTERRORSTATUS(event, param, status)		NxtrDiagMgr10_ReportNTCStatus(event, param, status)
#define ADC_EVENT_PASSED				NTC_STATUS_PASSED
#define ADC_EVENT_FAILED				NTC_STATUS_FAILED

typedef uint8	Adc_ConfigType;
   
/* Event Group Register Configuration (Currently Not Used) */
#define D_ADC1GEVTSRC_CNT_U32		0UL
#define D_ADC1GEVTDMACR_CNT_U32		0UL

/* Group 1 Register Configuration */
#define D_ADC1G1SRC_CNT_U32			0UL
#define D_ADC1G1DMACR_CNT_U32		0UL

/* Group 2 Register Configuration */
#define D_ADC1G2SRC_CNT_U32			1UL
#define D_ADC1G2DMACR_CNT_U32		0x00000008UL

/* define D_ADC1USEDMA_CNT_LGC to STD_ON if using DMA to transfer ADC data; STD_OFF if not using DMA */
#define D_ADC1USEDMA_CNT_LGC		STD_ON

/* define D_HWTRGADC1Gx_CNT_LGC to STD_ON to use hardware triggering; STD_OFF to use software triggering */
/* only used when D_ADC1USEDMA_CNT_LGC == STD_ON */
#define D_HWTRGADC1GEVT_CNT_LGC     STD_OFF
#define D_HWTRGADC1G1_CNT_LGC       STD_OFF
#define D_HWTRGADC1G2_CNT_LGC       STD_ON

#define  Adc1_Write_ADC1OffsetComp_Cnt_u8p8(val)   CDD_ADC1OffsetComp_Cnt_G_u8p8 = (val)

#endif
