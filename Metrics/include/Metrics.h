/*****************************************************************************
* Copyright 2009 Nexteer Automotive, Inc., All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Metrics.h
* Module Description: Prototypes for Metrics Functions and Macros
* Product           : EPS EA3
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Mar 15 14:16:05 2011
* %version:          11 % 
* %derived_by:       zz4r1x %
* %date_modified:    Tue Mar 19 09:49:55 2013 %
*---------------------------------------------------------------------------*/
#ifndef METRICS_H
#define METRICS_H

#include "Std_Types.h"
#include "Metrics_Cfg.h"
#include "Metrics_Enable.h"

#if( D_ENABLEMETRICS_CNT_LGC == STD_ON )

extern FUNC(void, METRICS_CODE) Metrics_RunnableStart( uint16 Id );
extern FUNC(void, METRICS_CODE) Metrics_RunnableEnd( uint16 Id );
extern FUNC(void, METRICS_CODE) Metrics_TaskStart( uint16 Id );
extern FUNC(void, METRICS_CODE) Metrics_TaskEnd( uint16 Id );

extern FUNC(void, METRICS_CODE) Metrics_Init( void );
extern FUNC(void, METRICS_CODE) Metrics_TraceTimerStart( void );
extern FUNC(void, METRICS_CODE) Metrics_TracePoint( uint16 );
extern FUNC(void, METRICS_CODE) Metrics_MainFunction( void );

#if( BC_METRICS_CPUUSEDIO == STD_ON )
extern FUNC(void, METRICS_CODE) Metrics_Init2( void );
#else
#define Metrics_Init2() ((void)(0))
#endif

/************************************************************************/

#else /* Metrics not enabled. Stub Metrics API */
#define Metrics_RunnableStart( Id ) ((void)(0))
#define Metrics_RunnableEnd( Id ) ((void)(0))
#define Metrics_TaskStart( Id ) ((void)(0))
#define Metrics_TaskEnd( Id ) ((void)(0))

#define Metrics_Init() ((void)(0))
#define Metrics_Init2() ((void)(0))
#define Metrics_TraceTimerStart() ((void)(0))
#define Metrics_TracePoint( Id ) ((void)(0))
#define Metrics_MainFunction() ((void)(0))
#define Metrics_TaskStart( Id ) ((void)(0))
#define Metrics_TaskEnd( Id ) ((void)(0))

#endif /* D_ENABLEMETRICS_CNT_LGC */



#endif /* METRICS_H */

/******************************************************************************
CHANGE HISTORY:

 Date      Rev      Author 			Change Description              SCR #
 				 					 (MDD Rev & Date) 		
--------   -------  --------  -----------------------------------  ----------
03/15/11   1        JJW        Initial metrics
03/17/11   2        JJW        Added ReadUtMnTimerState_m
05/13/11   4        JJW        Added Trace Buffer support
09/21/11   5        JJW        Added SystemTick Trace ID define
                               Added Spi Irq ID defines
05/07/12   6	    JJW        Reworked with SafeOs hook limitations in mind
                               and desing change to not rely on an available
							   FRC resource.
05/16/12   8        JJW        Added computation of individual task CPU use and
								runnable CPU use
******************************************************************************/
