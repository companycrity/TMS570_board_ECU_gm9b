/*****************************************************************************
* Copyright 2009 Nexteer Automotive, Inc., All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Metrics_Cfg.h
* Module Description: Prototypes for Metrics Functions and Macros
* Product           : EPS EA3
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri May  4 15:33:54 2012
* %version:          1 %
* %derived_by:       CZ8L9T %
* %date_modified:    Fri Oct  4 14:20:56 2013 %
*---------------------------------------------------------------------------*/
#ifndef METRICS_CFG_H
#define METRICS_CFG_H

#include "Os.h" /* Required for choice of exclusive area protection */

/************ Metric Module Exclusive Area Protection *****************/
/* Task Start */
#define METRICS_ENTER_EXCLUSIVEAREA0	((void)0) /* area not configured because the resulting cpu usage was too high to collect metrics */
#define METRICS_EXIT_EXCLUSIVEAREA0		((void)0)
/* Task End */
#define METRICS_ENTER_EXCLUSIVEAREA1	((void)0)
#define METRICS_EXIT_EXCLUSIVEAREA1		((void)0)
/* MainFunction Metrics Calculations */
#define METRICS_ENTER_EXCLUSIVEAREA2	SuspendAllInterrupts()
#define METRICS_EXIT_EXCLUSIVEAREA2		ResumeAllInterrupts()
/* Runnable Start */
#define METRICS_ENTER_EXCLUSIVEAREA3	SuspendAllInterrupts()
#define METRICS_EXIT_EXCLUSIVEAREA3		ResumeAllInterrupts()
/* Runnable End */
#define METRICS_ENTER_EXCLUSIVEAREA4	SuspendAllInterrupts()
#define METRICS_EXIT_EXCLUSIVEAREA4		ResumeAllInterrupts()

/******************* Metric Module Feature Enable *********************/
#define BC_METRICS_DET			STD_ON
#define BC_METRICS_STACKUSE 	STD_ON
#define BC_METRICS_CPUUSEDIO	STD_OFF
#define BC_METRICS_CPUUSETMR	STD_ON
#define BC_METRICS_RUNBLCPUUSE	STD_OFF
#define BC_METRICS_PREEMPTCOUNT STD_OFF
#define BC_METRICS_BYPASSMPU	STD_ON

/**************** Metric Module Measurement Constants *****************/
#define D_OSCONTEXTSWITCH_US_U32  	0U		/* Os context switching constant to be used to compensate runtime measurements */
#define D_HWSTARTUP_US_U16          55000U; /* Constant measured in CTP.  This is the time from Wakeup High to uP Reset High */
#define D_OSCILATORFREQ_MHZ_U16		20		/* Used to configure the rti during the initial startup phase to measure init timing */

/************************** Task IDs **************************/
#define D_MTRCTRLID_CNT_U08                 osdNumberOfAllTasks
#define D_COMIRQ1_CNT_U08                   (D_MTRCTRLID_CNT_U08 + 1)
#define D_COMIRQ2_CNT_U08                 (D_COMIRQ1_CNT_U08 + 1)
#define D_COMIRQ3_CNT_U08                 (D_COMIRQ2_CNT_U08 + 1)
#define D_SPIIRQ1_CNT_U08                 (D_COMIRQ3_CNT_U08 + 1)
#define D_SPIIRQ2_CNT_U08                 (D_SPIIRQ1_CNT_U08 + 1)
#define D_SPIIRQ3_CNT_U08                 (D_SPIIRQ2_CNT_U08 + 1)
#define D_SPIIRQ4_CNT_U08                 (D_SPIIRQ3_CNT_U08 + 1)
#define D_SPIIRQ5_CNT_U08                 (D_SPIIRQ4_CNT_U08 + 1)
#define D_SPIIRQ6_CNT_U08                 (D_SPIIRQ5_CNT_U08 + 1)
#define D_SPIIRQ7_CNT_U08                 (D_SPIIRQ6_CNT_U08 + 1)
#define D_SPIIRQ8_CNT_U08                 (D_SPIIRQ7_CNT_U08 + 1)
#define D_SPIIRQ9_CNT_U08                 (D_SPIIRQ8_CNT_U08 + 1)
#define D_SPIIRQ10_CNT_U08                (D_SPIIRQ9_CNT_U08 + 1)
#define D_SPIIRQ11_CNT_U08                (D_SPIIRQ10_CNT_U08 + 1)
#define D_CROSSCHKID_CNT_U08              (D_SPIIRQ11_CNT_U08 + 1)
#define D_SPINXT1_CNT_U08					(D_CROSSCHKID_CNT_U08 + 1)
#define D_SPINXT2_CNT_U08					(D_SPINXT1_CNT_U08 + 1)
#define D_I2CNXT_CNT_U08					(D_SPINXT2_CNT_U08 + 1)
#define D_METRICS_CNT_U08					(D_I2CNXT_CNT_U08 + 1)
#define D_RTSID_CNT_U08                     (D_METRICS_CNT_U08 + 1)
#define D_SUPERTASK_2MS_CNT_U08				(D_RTSID_CNT_U08 + 1)
#define D_SUPERTASK_4MS_CNT_U08				(D_SUPERTASK_2MS_CNT_U08 + 1)
#define d_NumberofTasks_Cnt_u16		    (D_SUPERTASK_4MS_CNT_U08 + 1)

#define D_TASKLIST_2MS_CNT_U08		{ Task_2ms_10, Task_2ms_8, Task_2ms_9, }
#define D_TASKLIST_4MS_CNT_U08		{ Task_4ms_10, Task_4ms_9 }

/* Number of Monitored Runnables */
#define d_NumberofRunnables_Cnt_u16		    0U

/************************** Trace Config IDs **************************/
#define D_MAXTRACEEVT_CNT_U16	      1U /* Define the Maximum number of init trace points allowed to be captured */
#define D_NUMTRACEPOINTS_CNT_U16		      1U

#endif /* METRICS_CFG_H */
