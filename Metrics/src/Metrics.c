/*****************************************************************************
* Copyright 2009 Delphi Technologies, Inc., All Rights Reserved.
* Delphi Confidential
*
* Module File Name  : Metrics.c
* Module Description: Data for Metrics
* Product           : Gen II Plus
* Author            : Jeremy Warmbeir
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Mar 15 14:16:03 2011
* %version:          15 % 
* %derived_by:       zz4r1x %
* %date_modified:    Fri Oct  4 10:58:29 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 03/15/11   1        JJW        Initial metrics
 * 03/16/11   2        JJW        Added CDD_TimerState_Cnt_u32[]
 * 05/13/11   3        JJW        Added Trace Buffer support
 * 05/07/12   6        JJW        Reworked with SafeOs hook limitations in mind
 *                                so RteHooks are used start and return hooks.
 *                                Also the design is changed to not require
 *                                exclusive control of a Free Running Counter
 *                                resource because an FRC resaource is not 
 *                                available in all designs.
 * 05/16/12   7        JJW        Added computation of individual task CPU use and
 *                                runnable CPU use
 * 03/15/13  11       BWL         Keep module variables and types internal, add preemption counting.       7610
 * 05/16/13  14       BWL         Add task chain timing.                                                   8305
 * 10/07/13  15       BWL         Only move to privileged mode if not in the motor control ISR.
*---------------------------------------------------------------------------*/
#define METRICS_MODULE_INCLUDE
#include "Metrics.h"
#include "Det.h"
#include "GlobalMacro.h"
#include "SystemTime.h"
#include "sys_pmu.h"
#include "string.h"
#include "Rte_Type.h"
#include "Metrics_Enable.h"
#include "filters.h"

#if( BC_METRICS_BYPASSMPU )
#include "oseksctx.h"
#endif

#if( BC_METRICS_CPUUSEDIO == STD_ON )
# include "Port.h"
# include "Dio.h"
#endif

#if( D_ENABLEMETRICS_CNT_LGC == STD_ON )

#define D_TASKCOUNTER_CNT_U32	pmuCOUNTER0
#define D_TRACECOUNTER_CNT_U32	pmuCOUNTER1
#define D_BUSYLOOPS_CNT_U32		0x0U
#define D_CPUUSEUPDATEINTERVAL_MS_U32 	((uint32)10000)
#define D_STACKUSEUPDATEINTERVAL_MS_U32 ((uint32)10000)
#define D_ACTIVETASKSTACKSIZE_CNT_U08   10u
#define D_NOACTIVETASK_CNT_U08          d_NumberofTasks_Cnt_u16
#define D_NOACTIVERUNNABLE_CNT_U08      d_NumberofRunnables_Cnt_u16
#define D_DEFAULTFILTERCONST_CNT_U08	(.0001f);
#define D_TASKTRACENUM_CNT_U16			(512)

#define SATURATED_ADD_U08(a, b) (((a) > 0xFF - (b)) ? 0xFFu : ((a) + (b)))

#if ( (d_NumberofRunnables_Cnt_u16 == 0) && (BC_METRICS_RUNBLCPUUSE == STD_ON))
#error "Metrics build constants conflict."
#endif

typedef struct TaskMetric_tag
{
	uint32  ActiveTimeMax_Cnt_u32; /* Max calculated task active time (End time - Start time ) */
	uint32  RunTimeMax_Cnt_u32;	 /* Max calculated task run time (Elapsed time - Preempt time) */
	LPF32KSV_Str  RunTimeFilt_Cnt_Str;
	uint32  PreemptTime_Cnt_u32;
	uint8 	PremptedTaskId_Cnt_u08;   /* Id of the Task that was premepted by this entity */
	uint8 	PremptedRunnableId_Cnt_u08;   /* Id of the Runnable that was premepted by this entity */
	uint32  StartTime_Cnt_u32; /*Value of PMU at start of execution. Determines how long preemeted task has executed.*/
	uint32  CpuUse_Cnt_u32; /* Accumulated Cpu use time to be processed by the CpuUse calculation operation */
	float32 CpuUse_Pct_f32; /* Normalized CPU use over a defined interval */
#if( BC_METRICS_STACKUSE == STD_ON )
	uint16  StackUse_Byte_u16;
	uint16  StackSize_Byte_u16;
#endif
}TaskMetric_Type;


typedef struct RunnableMetric_tag
{
	uint32  ActiveTimeMax_Cnt_u32;	/* Max calculated runnable active time (End time - Start time )  */
	uint32  RunTimeMax_Cnt_u32;	/* Max calculated runnable run time (Elapsed time - Preempt time) */
	uint32  PreemptTime_Cnt_u32;  /* Accumulated task preemption time for the runnable */
	uint32  StartTime_Cnt_u32;    /* Task execution start time */
	uint8   PreemptCount_Cnt_u08; /* Number of non-motor-control ISR preemptions this execution cycle. */
	uint8   MaxTimePreemptCount_Cnt_u08; /* The number of non-motor-control ISR preemptions that occurred during the longest runtime. */
	uint8   MtrCtrlPreemptCount_Cnt_u08; /* Number of motor control ISR preemptions this execution cycle. */
	uint8   MaxTimeMtrCtrlPreemptCount_Cnt_u08; /* The number of motor control ISR preemptions that occurred during the longest runtime. */
#if( BC_METRICS_RUNBLCPUUSE == STD_ON )
	uint32  CpuUse_Cnt_u32; /* Accumulated Cpu use time to be processed by the CpuUse calculation operation */
	float32 CpuUse_Pct_f32; /* Normalized CPU use over a defined interval */
#endif
}RunnableMetric_Type;

/* Pseudo Module Internal Variables. (Global Variables Used By Inline Functions) */

/* Trace Buffer Id is a 32 bit entry to match the time stamp, in order to make eviewing the log with CANape possible via a dataset measurement */
/*  If memory becomes an issue, then the Id cna be stored in a seperate array to reduce it to a uint16*/
typedef struct MetricTrace
{
	uint32  TracePtId_Cnt_u32; /* ID of the trace point */
	uint32  Time_Cnt_u32;      /* Time stamp for trace point */
} MetricTrace_Str;

/* Local Function Prototypes */
static FUNC(void, METRICS_CODE) Metrics_CalcCpuUse( void );

#if( BC_METRICS_STACKUSE == STD_ON )
static FUNC(void, METRICS_CODE) Metrics_CalcStackUse( void );
#endif

#if( BC_METRICS_DET == STD_ON )
static FUNC(void, METRICS_CODE) ValidateTaskId( uint16 Id );
static FUNC(void, METRICS_CODE) ValidateRunnableId( uint16 Id );
static FUNC(void, METRICS_CODE) ValidateTraceId( uint16 Id );
#endif


#define METRICS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"


/* Trace point data structures. */
STATIC VAR(uint16, AUTOMATIC)           Metrics_TraceIdx_Cnt_M_u16;
STATIC VAR(uint32, AUTOMATIC)           Metrics_TraceOffset_uS_M_u32;
STATIC volatile VAR(MetricTrace_Str, AUTOMATIC)  Metrics_Trace_Cnt_M_Str[D_MAXTRACEEVT_CNT_U16];

/* A round robin list of task execution sequence. Useful for debugging.
 * Can be used to give a history of how a failure was achieved. */
STATIC volatile VAR(uint8, AUTOMATIC)			Metrics_TaskTrace_Cnt_M_u08[D_TASKTRACENUM_CNT_U16];
STATIC VAR(uint16, AUTOMATIC)			Metrics_TaskTraceIndex_Cnt_M_u16;

#if( METRICS_RUNNABLERUNTIMEMASK == STD_ON )
	STATIC volatile VAR(uint32, AUTOMATIC) Metrics_RunnableMask_Cnt_M_u32[(d_NumberofRunnables_Cnt_u16 / 32U) + 1U ];
#endif

/* A stack that tracks all active tasks. Use a stack instead of */

/* Track which task and runnable are active. */
STATIC volatile VAR(uint8, AUTOMATIC) Metrics_ActiveTask_Cnt_M_u08;
STATIC volatile VAR(uint8, AUTOMATIC) Metrics_ActiveRunnable_Cnt_M_u08;

/* Track runtime and activation time for each task and runnable.*/
STATIC	VAR(TaskMetric_Type, AUTOMATIC) Metrics_TaskTimes_Str[d_NumberofTasks_Cnt_u16];
STATIC VAR(uint8, AUTOMATIC) Metrics_SuperTask_Cnt_M_u08[d_NumberofTasks_Cnt_u16];

#if defined(D_TASKLIST_1MS_CNT_U08)
STATIC const VAR(uint8, AUTOMATIC) TaskList1ms_Cnt_M_u08[] = D_TASKLIST_1MS_CNT_U08;
#endif
#if defined(D_TASKLIST_2MS_CNT_U08)
STATIC const VAR(uint8, AUTOMATIC) TaskList2ms_Cnt_M_u08[] = D_TASKLIST_2MS_CNT_U08;
#endif
#if defined(D_TASKLIST_4MS_CNT_U08)
STATIC const VAR(uint8, AUTOMATIC) TaskList4ms_Cnt_M_u08[] = D_TASKLIST_4MS_CNT_U08;
#endif

#if ( d_NumberofRunnables_Cnt_u16 > 0 )
STATIC	VAR(RunnableMetric_Type, AUTOMATIC) Metrics_RunnableTimes_Str[d_NumberofRunnables_Cnt_u16];
#endif /* d_NumberofRunnables_Cnt_u16 > 0 */

/* System scope metrics. */
STATIC	volatile VAR(float32, AUTOMATIC) Metrics_CpuUse_Pct_M_f32;
STATIC	volatile VAR(uint32, AUTOMATIC) Metrics_BkgndLoopTimeMax_Cnt_M_u32;

/* Time the metrics has executed since the last main function execution. */
STATIC	VAR(uint32, AUTOMATIC) Metrics_ActiveTime_Cnt_M_u32;

#if( BC_METRICS_PREEMPTCOUNT == STD_ON )
/* Count how many times each task is preempted, and by which tasks.
 * Transient preemption counts preemtions this execution, where max preemption is the per task maximum. */
STATIC VAR(uint8, AUTOMATIC) Metrics_PreemptionStackIndex_Cnt_u08;
STATIC volatile VAR(uint8, AUTOMATIC)	Metrics_TransientPreemption_Cnt_M_u08[D_ACTIVETASKSTACKSIZE_CNT_U08][d_NumberofTasks_Cnt_u16];
STATIC volatile VAR(uint8, AUTOMATIC)	Metrics_MaxPreemption_Cnt_M_u08[d_NumberofTasks_Cnt_u16][d_NumberofTasks_Cnt_u16];
#endif

#define METRICS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"



/****************************************************************************
 * Name:        Metrics_TraceTimerInit()
 * Description: Trace Point timer init
 * Inputs:      None 
 * Outputs:     None
 ****************************************************************************/
FUNC(void, METRICS_CODE) Metrics_TraceTimerStart( void )
{
}

/****************************************************************************
 * Name:        Metrics_Init()
 * Description: Metrics module initilaization
 * Inputs:      None 
 * Outputs:     None
 ****************************************************************************/
FUNC(void, METRICS_CODE) Metrics_Init( void )
{
	VAR(uint8, AUTOMATIC) i;

	/* Initialize the offset to the nominal measured Hardware startup time */
	Metrics_TraceOffset_uS_M_u32 = D_HWSTARTUP_US_U16;

	/* Set active task and runnable to an invalid value. */
	Metrics_ActiveTask_Cnt_M_u08 = D_NOACTIVETASK_CNT_U08;
	Metrics_ActiveRunnable_Cnt_M_u08 = D_NOACTIVERUNNABLE_CNT_U08;

	/* If Metrics_TaskTimes_Str ends up in uncleared memory, it may appear that some tasks are started
	 * when the system starts up. */
	memset((void*)Metrics_TaskTimes_Str, 0u, sizeof(TaskMetric_Type) * d_NumberofTasks_Cnt_u16);

#if( BC_METRICS_STACKUSE == STD_ON )
	/*Calculate the stack size.*/
	for(i=0; i<osdNumberOfAllTasks; i++)
	{
		Metrics_TaskTimes_Str[i].StackSize_Byte_u16 = (uint16)((uint8*)oskTcbStackTop[i] - (uint8*)oskTcbStackBottom[i]);
	}
#endif
	for(i=0; i<d_NumberofTasks_Cnt_u16; i++)
	{
		Metrics_TaskTimes_Str[i].RunTimeFilt_Cnt_Str.K_Uls_f32 = D_DEFAULTFILTERCONST_CNT_U08;
	}
	
#if ( METRICS_RUNNABLERUNTIMEMASK == STD_ON )
	for(i=0; i < (d_NumberofRunnables_Cnt_u16 / 32U) + 1U; i++)
	{
		Metrics_RunnableMask_Cnt_M_u32[i] = 0xFFFFFFFF;
	}
#endif
	/* Initialize CPU use to 100, when it reaches the backgournd for the first calcualtion it will be updated to the measusred value.
	 * in the event that the background task is starved, it the ECU will report 100% until it successfully reaches the calculation.
	 */
	Metrics_CpuUse_Pct_M_f32 = 100.0F;

	/* Translate the sub tasks arrays into a single super task array.
	 * This way configuration is straightforward, and super task lookups can still be done quickly.
	 * Loops are ordered such that if something is in the 4ms supertask and the 2ms supertask,
	 * it is only saved in the 2ms task.*/

#if defined(D_TASKLIST_4MS_CNT_U08)
	for(i = 0; i < TableSize_m(TaskList4ms_Cnt_M_u08); i++)
	{
		Metrics_SuperTask_Cnt_M_u08[TaskList4ms_Cnt_M_u08[i]]= D_SUPERTASK_4MS_CNT_U08;
	}
#endif

#if defined(D_TASKLIST_2MS_CNT_U08)
	for(i = 0; i < TableSize_m(TaskList2ms_Cnt_M_u08); i++)
	{
		Metrics_SuperTask_Cnt_M_u08[TaskList2ms_Cnt_M_u08[i]]= D_SUPERTASK_2MS_CNT_U08;
	}
#endif

#if defined(D_TASKLIST_1MS_CNT_U08)
	for(i = 0; i < TableSize_m(TaskList1ms_Cnt_M_u08); i++)
	{
		Metrics_SuperTask_Cnt_M_u08[TaskList1ms_Cnt_M_u08[i]]= D_SUPERTASK_1MS_CNT_U08;
	}
#endif

	/*Initialize and start the PMU counters.*/
	_pmuInit_();
	_pmuEnableCountersGlobal_();
	_pmuSetUserEnable_(1U);
	_pmuSetCountEvent_(D_TASKCOUNTER_CNT_U32, PMU_CYCLE_COUNT); /* PMU_INST_ARCH_EXECUTED */
	_pmuSetCountEvent_(D_TRACECOUNTER_CNT_U32, PMU_CYCLE_COUNT);
	_pmuResetCounters_();
	/* Cycle Counter: Total time for CPU utilization calculations.*/
	_pmuStartCounters_(D_TASKCOUNTER_CNT_U32 | D_TRACECOUNTER_CNT_U32 | pmuCYCLE_COUNTER);

}


/***************************************************************************
 * Name:        Metrics_Init2()
 * Description: Perform required initialization on Os Startup
 * Inputs:      Null
 * Outputs:     Null
 ****************************************************************************/
#if( BC_METRICS_CPUUSEDIO == STD_ON )
FUNC(void, AUTOMATIC) Metrics_Init2(void)
{
	Port_SetPinDirection(Metrics_Dio, PORT_PIN_OUT);
}
#endif /* ENABLE_CPUUSE_DIO */


/****************************************************************************
 * Name:        Metrics_TracePoint()
 * Description: Trace Point event capture
 * Inputs:      None 
 * Outputs:     None
 ****************************************************************************/
FUNC(void, METRICS_CODE) Metrics_TracePoint( uint16 Id )
{
	VAR(uint32, AUTOMATIC) Time_Cnt_T_u32;

#if( BC_METRICS_DET == STD_ON )
	ValidateTraceId( Id );
#endif

	/* Log Trace point while the buffer is not full */
	if(Metrics_TraceIdx_Cnt_M_u16 < D_MAXTRACEEVT_CNT_U16)
	{
		Time_Cnt_T_u32 = _pmuGetEventCount_(D_TRACECOUNTER_CNT_U32);
		Time_Cnt_T_u32 += Metrics_TraceOffset_uS_M_u32 * 160U;

		Metrics_Trace_Cnt_M_Str[Metrics_TraceIdx_Cnt_M_u16].TracePtId_Cnt_u32 = (uint32)Id;
		Metrics_Trace_Cnt_M_Str[Metrics_TraceIdx_Cnt_M_u16].Time_Cnt_u32 = Time_Cnt_T_u32;
		Metrics_TraceIdx_Cnt_M_u16++;
	}
}

/****************************************************************************
 * Name:        Metrics_RunnableStart()
 * Description: Start runnable function.  Design is based on preemptable entity.
 * Inputs:      None 
 * Outputs:     None
 ****************************************************************************/
void Metrics_RunnableStart(uint16 Id)
{
#if ( d_NumberofRunnables_Cnt_u16 > 0 )

#if( METRICS_RUNNABLERUNTIMEMASK == STD_ON )
	/* Check Runnable Metric enable mask before running metrics for runnable */
	if( 0 != ((1U << (Id%32U)) & Metrics_RunnableMask_Cnt_M_u32[Id / 32U]))
#endif
	{
#if( BC_METRICS_DET == STD_ON )
		ValidateRunnableId( Id );
#endif
		if(D_NOACTIVERUNNABLE_CNT_U08 != Metrics_ActiveRunnable_Cnt_M_u08)
		{
			return;
		}

		METRICS_ENTER_EXCLUSIVEAREA3;

		Metrics_RunnableTimes_Str[Id].PreemptTime_Cnt_u32 = 0; /* Reset runnable's preemption accumulator */
		Metrics_ActiveRunnable_Cnt_M_u08 = Id;

		METRICS_EXIT_EXCLUSIVEAREA3;

		/*The task timer will take into account preemption, so only run time is recorded.*/
		Metrics_RunnableTimes_Str[Id].StartTime_Cnt_u32 = _pmuGetEventCount_(D_TASKCOUNTER_CNT_U32);
	}
#endif /* d_NumberofRunnables_Cnt_u16 > 0 */
}

/****************************************************************************
 * Name:        Metrtics_RunnableEnd()
 * Description: End runnable function. Design is based on preemptable entity.
 * Inputs:      None 
 * Outputs:     None
 ****************************************************************************/
FUNC(void, METRICS_CODE) Metrics_RunnableEnd(uint16 Id)
{
#if ( d_NumberofRunnables_Cnt_u16 > 0 )
	VAR(uint32, AUTOMATIC) 	activeTime_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) 	endTime_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) 	runTime_Cnt_T_u32;

	endTime_Cnt_T_u32 = _pmuGetEventCount_(D_TASKCOUNTER_CNT_U32);
	runTime_Cnt_T_u32 = endTime_Cnt_T_u32 - Metrics_RunnableTimes_Str[Id].StartTime_Cnt_u32;

#if( METRICS_RUNNABLERUNTIMEMASK == STD_ON )
	/* Check Runnable Metric enable mask before running metrics for runnable */
	if( 0 != ((1U << (Id%32U)) & Metrics_RunnableMask_Cnt_M_u32[Id / 32U]))
#endif
	{
#if( BC_METRICS_DET == STD_ON )
		ValidateRunnableId( Id );
#endif
		if(Id != Metrics_ActiveRunnable_Cnt_M_u08 || D_NOACTIVERUNNABLE_CNT_U08 == Metrics_ActiveRunnable_Cnt_M_u08)
		{
			return;
		}
		METRICS_ENTER_EXCLUSIVEAREA4;

		/*Preempted runnable time accounted for by the task, so don't worry about it here.*/
		Metrics_ActiveRunnable_Cnt_M_u08 = D_NOACTIVERUNNABLE_CNT_U08;

		/* If this execution was preempted less, the time is more accurate, so take this time. */
		if(Metrics_RunnableTimes_Str[Id].PreemptCount_Cnt_u08 < Metrics_RunnableTimes_Str[Id].MaxTimePreemptCount_Cnt_u08)
		{
			Metrics_RunnableTimes_Str[Id].RunTimeMax_Cnt_u32 = runTime_Cnt_T_u32;
			Metrics_RunnableTimes_Str[Id].MaxTimePreemptCount_Cnt_u08 = Metrics_RunnableTimes_Str[Id].PreemptCount_Cnt_u08;
			Metrics_RunnableTimes_Str[Id].MaxTimeMtrCtrlPreemptCount_Cnt_u08 = Metrics_RunnableTimes_Str[Id].MtrCtrlPreemptCount_Cnt_u08;
		}
		/* The same number of preemptions means measurements have the same level of precision. */
		else if(Metrics_RunnableTimes_Str[Id].PreemptCount_Cnt_u08 == Metrics_RunnableTimes_Str[Id].MaxTimePreemptCount_Cnt_u08)
		{
			Metrics_RunnableTimes_Str[Id].RunTimeMax_Cnt_u32 = Max_m(runTime_Cnt_T_u32, Metrics_RunnableTimes_Str[Id].RunTimeMax_Cnt_u32);
			Metrics_RunnableTimes_Str[Id].MaxTimeMtrCtrlPreemptCount_Cnt_u08 = Max_m(
				Metrics_RunnableTimes_Str[Id].MtrCtrlPreemptCount_Cnt_u08,
				Metrics_RunnableTimes_Str[Id].MaxTimeMtrCtrlPreemptCount_Cnt_u08);
		}

		/* Active time accuracy is not impacted by preemptions. */
		activeTime_Cnt_T_u32 = Metrics_RunnableTimes_Str[Id].PreemptTime_Cnt_u32 + runTime_Cnt_T_u32;
		Metrics_RunnableTimes_Str[Id].ActiveTimeMax_Cnt_u32 = Max_m(activeTime_Cnt_T_u32, Metrics_RunnableTimes_Str[Id].ActiveTimeMax_Cnt_u32);

#if( BC_METRICS_RUNBLCPUUSE == STD_ON )
		Metrics_RunnableTimes_Str[Id].CpuUse_Cnt_u32 += runTime_Cnt_T_u32;
#endif

		METRICS_EXIT_EXCLUSIVEAREA4;
	}
#endif /* d_NumberofRunnables_Cnt_u16 > 0*/
}


/****************************************************************************
 * Name:        Metrics_MainFunction()
 * Description: Periodic function for computing the metrics
 * Inputs:      None 
 * Outputs:     None
 ****************************************************************************/
FUNC(void, METRICS_CODE) Metrics_MainFunction( void )
{
	VAR(uint32, AUTOMATIC) bkgndLoopTime_Cnt_T_u32;
	#if (D_BUSYLOOPS_CNT_U32 > 0)
	volatile VAR(uint32, AUTOMATIC)	busyLoop_Cnt_T_u32;
	#endif

	#if( BC_METRICS_BYPASSMPU )
		VAR(uint32, AUTOMATIC) CallerIsTrusted_Cnt_T_u32;
		CallerIsTrusted_Cnt_T_u32 = osSwitchToPrivMode();
	#endif

  	Metrics_TaskStart(D_METRICS_CNT_U08);

	/* Exclusive area protection could be placed around the elapsed time calc and system time get for better period
	 * measurement, but is deemed not necessary for the purposes of this calculation.
	 */

	#if (D_BUSYLOOPS_CNT_U32 > 0)
	for(busyLoop_Cnt_T_u32 = 0; busyLoop_Cnt_T_u32 < D_BUSYLOOPS_CNT_U32; busyLoop_Cnt_T_u32++)
	{
		/*Do nothing except increment busyLoop*/
	}
	#endif

	bkgndLoopTime_Cnt_T_u32 = _pmuGetCycleCount_();
	Metrics_BkgndLoopTimeMax_Cnt_M_u32 = Max_m(bkgndLoopTime_Cnt_T_u32, Metrics_BkgndLoopTimeMax_Cnt_M_u32);

	#if( BC_METRICS_STACKUSE == STD_ON )
		Metrics_CalcStackUse();
	#endif

	#if( BC_METRICS_CPUUSETMR == STD_ON )
		Metrics_CalcCpuUse();
	#endif

	#if( BC_METRICS_CPUUSEDIO == STD_ON )
		/* When using the DIO method of utilization monitoring, an external scope is required to monitor the pin signal
		 * The pin is always set low by the background task.  The understood constraint with this approach is that the 
		 * content of the background task will effect the lag to deassert the DIO upon returning to the background and
		 * produce some measurement jitter.  If this is determined unaccaptable, a different scheme will need to 
		 * be implemented.
		 */
		Dio_WriteChannel(Metrics, STD_LOW);
	#endif /* ENABLE_CPUUSE_DIO */

	Metrics_TaskEnd(D_METRICS_CNT_U08);

	#if( BC_METRICS_BYPASSMPU )
			if(0u == CallerIsTrusted_Cnt_T_u32)
			{
				osSwitchToUserMode();
			}
	#endif
}

/***************************************************************************
 * Name:        Metrics_TaskStart()
 * Description: Metrics Post Task Processing
 * Inputs:      Null
 * Outputs:     Null
 ****************************************************************************/
FUNC(void, METRICS_CODE) Metrics_TaskStart( uint16 Id )
{
	VAR(uint32, AUTOMATIC) startTime_Cnt_T_u32;

#if( BC_METRICS_BYPASSMPU )
	VAR(uint32, AUTOMATIC) CallerIsTrusted_Cnt_T_u32;
#endif

#if( BC_METRICS_DET == STD_ON )
	ValidateTaskId( Id );
#endif


	/* If this task does not have a super task.
	 * Zero is an invalid super task ID since at least one sub task must exist,
	 * and the list of super tasks is tacked onto the end of the list of sub tasks.*/
	if(0 == Metrics_SuperTask_Cnt_M_u08[Id])
	{
		startTime_Cnt_T_u32 = _pmuGetEventCount_(D_TASKCOUNTER_CNT_U32);
		/*TaskStart is called on a given task twice before TaskEnd is called.*/
		if(0 != Metrics_TaskTimes_Str[Id].StartTime_Cnt_u32 || Metrics_ActiveTask_Cnt_M_u08 == Id)
		{
			return;
		}

		if(Id != D_MTRCTRLID_CNT_U08)
		{
#if( BC_METRICS_BYPASSMPU )
			CallerIsTrusted_Cnt_T_u32 = osSwitchToPrivMode();
#endif
			METRICS_ENTER_EXCLUSIVEAREA0;
		}

		Metrics_TaskTrace_Cnt_M_u08[Metrics_TaskTraceIndex_Cnt_M_u16] = Id;
		Metrics_TaskTraceIndex_Cnt_M_u16 = (Metrics_TaskTraceIndex_Cnt_M_u16 + 1) % D_TASKTRACENUM_CNT_U16;

#if ( d_NumberofRunnables_Cnt_u16 > 0 )
		if(D_NOACTIVERUNNABLE_CNT_U08 != Metrics_ActiveRunnable_Cnt_M_u08)
		{
			if(Id != D_MTRCTRLID_CNT_U08)
			{
				Metrics_RunnableTimes_Str[Metrics_ActiveRunnable_Cnt_M_u08].PreemptCount_Cnt_u08 =
					SATURATED_ADD_U08(Metrics_RunnableTimes_Str[Metrics_ActiveRunnable_Cnt_M_u08].PreemptCount_Cnt_u08, 1u);
			}
			else
			{
				Metrics_RunnableTimes_Str[Metrics_ActiveRunnable_Cnt_M_u08].MtrCtrlPreemptCount_Cnt_u08 =
					SATURATED_ADD_U08(Metrics_RunnableTimes_Str[Metrics_ActiveRunnable_Cnt_M_u08].MtrCtrlPreemptCount_Cnt_u08, 1u);
			}
		}
#endif /* d_NumberofRunnables_Cnt_u16 > 0  */

		/* Save the amount of time the interrupted task was running before this task started.*/
		Metrics_TaskTimes_Str[Id].StartTime_Cnt_u32 = startTime_Cnt_T_u32;

		/* Store preempted entity Id to communicate total preemption time with the entity on exit from this task */
		Metrics_TaskTimes_Str[Id].PremptedTaskId_Cnt_u08 = Metrics_ActiveTask_Cnt_M_u08;
		Metrics_TaskTimes_Str[Id].PremptedRunnableId_Cnt_u08 = Metrics_ActiveRunnable_Cnt_M_u08;

		/* Reset the task's preempt time accumulator */
		Metrics_TaskTimes_Str[Id].PreemptTime_Cnt_u32 = 0;
		Metrics_ActiveTask_Cnt_M_u08 = Id;
		Metrics_ActiveRunnable_Cnt_M_u08 = D_NOACTIVERUNNABLE_CNT_U08;

#if( BC_METRICS_PREEMPTCOUNT == STD_ON )
		/*If the preemption stack has not overflowed, add this task to the top.*/
		if(Metrics_PreemptionStackIndex_Cnt_u08 < D_ACTIVETASKSTACKSIZE_CNT_U08)
		{
			memset((void*)Metrics_TransientPreemption_Cnt_M_u08[Metrics_PreemptionStackIndex_Cnt_u08], 0U, d_NumberofTasks_Cnt_u16);
			Metrics_PreemptionStackIndex_Cnt_u08++;
		}
#endif

#if( BC_METRICS_CPUUSEDIO == STD_ON )
		/* Set the DIO high when a task is activated, the dio is set low in the background loop */
		Dio_WriteChannel(Metrics, STD_HIGH);
#endif

		Metrics_ActiveTime_Cnt_M_u32 += _pmuGetEventCount_(D_TASKCOUNTER_CNT_U32) - startTime_Cnt_T_u32;

		if(Id != D_MTRCTRLID_CNT_U08)
		{
			METRICS_EXIT_EXCLUSIVEAREA0;
#if( BC_METRICS_BYPASSMPU )
			if(0u == CallerIsTrusted_Cnt_T_u32)
			{
				osSwitchToUserMode();
			}
#endif
		}


		/*Start the task timer.*/
		_pmuSetEventCount_(D_TASKCOUNTER_CNT_U32, 0U);
	}
	else /* This task is a sub task. */
	{
		/* If the super task has not yet been started, start it. */
		if(0 == Metrics_TaskTimes_Str[Metrics_SuperTask_Cnt_M_u08[Id]].StartTime_Cnt_u32)
		{
			Metrics_TaskStart(Metrics_SuperTask_Cnt_M_u08[Id]);
		}
	}
}


/***************************************************************************
 * Name:        Metrics_TaskEnd()
 * Description: Metrics Post Task Processing
 * Inputs:      Null
 * Outputs:     Null
 ****************************************************************************/
FUNC(void, METRICS_CODE) Metrics_TaskEnd( uint16 Id )
{
	VAR(uint32, AUTOMATIC) 	activeTime_Cnt_T_u32 = 0;
	VAR(uint32, AUTOMATIC) 	runTime_Cnt_T_u32;
	VAR(uint32, AUTOMATIC)	startTime_Cnt_T_u32;
	VAR(uint32, AUTOMATIC)  metricsTime_Cnt_T_u32;

#if( BC_METRICS_BYPASSMPU )
	VAR(uint32, AUTOMATIC) CallerIsTrusted_Cnt_T_u32;
#endif

#if ( BC_METRICS_PREEMPTCOUNT == STD_ON )
	VAR(uint32, AUTOMATIC) taskId_Cnt_T_u32;
#endif

#if( BC_METRICS_DET == STD_ON )
	ValidateTaskId( Id );
#endif

	if(0 == Metrics_SuperTask_Cnt_M_u08[Id])
	{
		runTime_Cnt_T_u32 = _pmuGetEventCount_(D_TASKCOUNTER_CNT_U32);
		startTime_Cnt_T_u32 = Metrics_TaskTimes_Str[Id].StartTime_Cnt_u32;

		/* If TaskEnd is called before TaskStart.*/
		/* Zero is an impossible value to be gathered naturally. If a task is interrupted
		 * immediately after it sets the PMU counter to zero, time will pass before the new
		 * task records its start time.*/
		if(0 == startTime_Cnt_T_u32)
		{
			return;
		}
#if( BC_METRICS_DET == STD_ON )
		else if (Id != Metrics_ActiveTask_Cnt_M_u08)
		{
			/* This DET gets triggered when a */
			Det_ReportError( /*uint16 ModuleId*/0, /*uint8 InstanceId*/0, /*uint8 ApiId*/0, /*uint8 ErrorId*/4U );
		}
#endif

		if(Id != D_MTRCTRLID_CNT_U08)
		{
#if( BC_METRICS_BYPASSMPU )
			CallerIsTrusted_Cnt_T_u32 = osSwitchToPrivMode();
#endif
			METRICS_ENTER_EXCLUSIVEAREA1;
		}

		/* Distinguish the start of a task from the end of a task. */
		Metrics_TaskTrace_Cnt_M_u08[Metrics_TaskTraceIndex_Cnt_M_u16] = ~Id;
		Metrics_TaskTraceIndex_Cnt_M_u16 = (Metrics_TaskTraceIndex_Cnt_M_u16 + 1) % D_TASKTRACENUM_CNT_U16;

		/* Restore prior Active Task state and accrue preemption time for the entity */
		Metrics_ActiveTask_Cnt_M_u08 = Metrics_TaskTimes_Str[Id].PremptedTaskId_Cnt_u08;
		Metrics_ActiveRunnable_Cnt_M_u08 = Metrics_TaskTimes_Str[Id].PremptedRunnableId_Cnt_u08;

		activeTime_Cnt_T_u32 = runTime_Cnt_T_u32 + Metrics_TaskTimes_Str[Id].PreemptTime_Cnt_u32;

		/* Preempted task preemption time is equal to the total activation time of this task, which includes preemption time due to higher priority tasks */
		/* A fixed constant is added for the Os Context switch time since it can not be monitored directly in the existing scheme. */
		if(Metrics_ActiveTask_Cnt_M_u08 != D_NOACTIVETASK_CNT_U08)
		{
			Metrics_TaskTimes_Str[Metrics_ActiveTask_Cnt_M_u08].PreemptTime_Cnt_u32 += (activeTime_Cnt_T_u32 + D_OSCONTEXTSWITCH_US_U32);
		}

#if ( d_NumberofRunnables_Cnt_u16 > 0 )
		if(D_NOACTIVERUNNABLE_CNT_U08 != Metrics_TaskTimes_Str[Id].PremptedRunnableId_Cnt_u08)
		{
			Metrics_RunnableTimes_Str[Metrics_TaskTimes_Str[Id].PremptedRunnableId_Cnt_u08].PreemptTime_Cnt_u32 +=
					(activeTime_Cnt_T_u32 + D_OSCONTEXTSWITCH_US_U32);
		}
#endif /* d_NumberofRunnables_Cnt_u16 > 0 */

		/*Mark this task as no longer active.*/
		Metrics_TaskTimes_Str[Id].StartTime_Cnt_u32 = 0;

		Metrics_TaskTimes_Str[Id].RunTimeMax_Cnt_u32 = Max_m(runTime_Cnt_T_u32, Metrics_TaskTimes_Str[Id].RunTimeMax_Cnt_u32);
		Metrics_TaskTimes_Str[Id].ActiveTimeMax_Cnt_u32 = Max_m(activeTime_Cnt_T_u32, Metrics_TaskTimes_Str[Id].ActiveTimeMax_Cnt_u32);
		Metrics_TaskTimes_Str[Id].CpuUse_Cnt_u32 += runTime_Cnt_T_u32;
		(void)LPF_OpUpdate_f32_m(runTime_Cnt_T_u32, &Metrics_TaskTimes_Str[Id].RunTimeFilt_Cnt_Str);

#if( BC_METRICS_PREEMPTCOUNT == STD_ON )
		/*If the preemption stack has not overflowed, count this preemption.*/
		if(Metrics_PreemptionStackIndex_Cnt_u08 < D_ACTIVETASKSTACKSIZE_CNT_U08)
		{
			Metrics_PreemptionStackIndex_Cnt_u08--;

			/* For each task, record this number of preemptions if this execution resulted in a larger number of preemptions than was previously recorded. */
			for(taskId_Cnt_T_u32 = 0U; taskId_Cnt_T_u32 < d_NumberofTasks_Cnt_u16; taskId_Cnt_T_u32++)
			{
				if(Metrics_MaxPreemption_Cnt_M_u08[Id][taskId_Cnt_T_u32] <
					Metrics_TransientPreemption_Cnt_M_u08[Metrics_PreemptionStackIndex_Cnt_u08][taskId_Cnt_T_u32])
				{
					Metrics_MaxPreemption_Cnt_M_u08[Id][taskId_Cnt_T_u32] =
							Metrics_TransientPreemption_Cnt_M_u08[Metrics_PreemptionStackIndex_Cnt_u08][taskId_Cnt_T_u32];
				}
			}

			if(Metrics_PreemptionStackIndex_Cnt_u08 > 0)
			{
				/* For each task, add all premptions to the task that just ended to the task that it preempted.*/
				for(taskId_Cnt_T_u32 = 0U; taskId_Cnt_T_u32 < d_NumberofTasks_Cnt_u16; taskId_Cnt_T_u32++)
				{
					Metrics_TransientPreemption_Cnt_M_u08[Metrics_PreemptionStackIndex_Cnt_u08 - 1][taskId_Cnt_T_u32] =
							SATURATED_ADD_U08(
							Metrics_TransientPreemption_Cnt_M_u08[Metrics_PreemptionStackIndex_Cnt_u08 - 1][taskId_Cnt_T_u32],
							Metrics_TransientPreemption_Cnt_M_u08[Metrics_PreemptionStackIndex_Cnt_u08][taskId_Cnt_T_u32]);
				}

				/* Add one to the preemption count */
				Metrics_TransientPreemption_Cnt_M_u08[Metrics_PreemptionStackIndex_Cnt_u08 - 1][Id] =
						SATURATED_ADD_U08(Metrics_TransientPreemption_Cnt_M_u08[Metrics_PreemptionStackIndex_Cnt_u08 - 1][Id], 1u);
			}
		}
#endif

		metricsTime_Cnt_T_u32 = _pmuGetEventCount_(D_TASKCOUNTER_CNT_U32) - runTime_Cnt_T_u32;
		Metrics_ActiveTime_Cnt_M_u32 += metricsTime_Cnt_T_u32;

		if(Id != D_MTRCTRLID_CNT_U08)
		{
			METRICS_EXIT_EXCLUSIVEAREA1;
#if( BC_METRICS_BYPASSMPU )
			if(0u == CallerIsTrusted_Cnt_T_u32)
			{
				osSwitchToUserMode();
			}
#endif
		}

		/*Restore PMU counter to the values it had before this task became active.*/
		_pmuSetEventCount_(D_TASKCOUNTER_CNT_U32, startTime_Cnt_T_u32);
	}
	else /* This task is a sub task. */
	{
		/*Only end the task if it is the last one in the chain.*/
		switch(Metrics_SuperTask_Cnt_M_u08[Id])
		{
#if defined(D_TASKLIST_1MS_CNT_U08)
		case D_SUPERTASK_1MS_CNT_U08:
			if(Id == TaskList1ms_Cnt_M_u08[TableSize_m(TaskList1ms_Cnt_M_u08) - 1])
			{
				Metrics_TaskEnd(Metrics_SuperTask_Cnt_M_u08[Id]);
			}
			break;
#endif
#if defined(D_TASKLIST_2MS_CNT_U08)
		case D_SUPERTASK_2MS_CNT_U08:
			if(Id == TaskList2ms_Cnt_M_u08[TableSize_m(TaskList2ms_Cnt_M_u08) - 1])
			{
				Metrics_TaskEnd(Metrics_SuperTask_Cnt_M_u08[Id]);
			}
			break;
#endif
#if defined(D_TASKLIST_4MS_CNT_U08)
		case D_SUPERTASK_4MS_CNT_U08:
			if(Id == TaskList4ms_Cnt_M_u08[TableSize_m(TaskList4ms_Cnt_M_u08) - 1])
			{
				Metrics_TaskEnd(Metrics_SuperTask_Cnt_M_u08[Id]);
			}
			break;
#endif
		default:
			break;
		}
	}
}

#if( BC_METRICS_DET == STD_ON )
/****************************************************************************
 * Name:        ValidateTaskId()
 * Description: Perform a DET check on the Id passed to the functions
 *
 * Inputs:      None
 * Outputs:     None
 ****************************************************************************/
static FUNC(void, METRICS_CODE) ValidateTaskId( uint16 Id )
{
	if(Id >= d_NumberofTasks_Cnt_u16){
		Det_ReportError( /*uint16 ModuleId*/0, /*uint8 InstanceId*/0, /*uint8 ApiId*/0, /*uint8 ErrorId*/1U );
	}
}

/****************************************************************************
 * Name:        ValidateRunnableId()
 * Description: Perform a DET check on the Id passed to the functions
 * Inputs:      None
 * Outputs:     None
 ****************************************************************************/
static FUNC(void, METRICS_CODE) ValidateRunnableId( uint16 Id )
{
	if(Id >= d_NumberofRunnables_Cnt_u16){
		Det_ReportError( /*uint16 ModuleId*/0, /*uint8 InstanceId*/0, /*uint8 ApiId*/0, /*uint8 ErrorId*/2U );
	}
}

/****************************************************************************
 * Name:        ValidateTraceId()
 * Description: Perform a DET check on the Id passed to the functions
 * Inputs:      None
 * Outputs:     None
 ****************************************************************************/
static FUNC(void, METRICS_CODE) ValidateTraceId( uint16 Id )
{
	if(Id >= D_NUMTRACEPOINTS_CNT_U16){
		Det_ReportError( /*uint16 ModuleId*/0, /*uint8 InstanceId*/0, /*uint8 ApiId*/0, /*uint8 ErrorId*/3U );
	}
}
#endif /* BC_METRICS_DET */

/***************************************************************************
 * Name:        Metrics_CalcCpuUse()
 * Description: Compute the overall throughput
 * Inputs:      Null
 * Outputs:     Null
 ****************************************************************************/
static FUNC(void, METRICS_CODE) Metrics_CalcCpuUse( void )
{
	uint32 elapsedTime_Cnt_T_u32;
	uint32 taskCpuTime_Cnt_T_u32[d_NumberofTasks_Cnt_u16];
	uint32 CpuTimeSum_Cnt_T_u32 = 0;
	uint16 i;

#if( BC_METRICS_RUNBLCPUUSE == STD_ON )
	uint32 runnableCpuTime_Cnt_T_u32[d_NumberofRunnables_Cnt_u16];
#endif

	elapsedTime_Cnt_T_u32 = _pmuGetCycleCount_();

	/*If the counter has overflowed, discard all the accumulated CPU use time.*/
	if(0 != (_pmuGetOverflow_() & pmuCYCLE_COUNTER)) {
		for(i=0; i<d_NumberofTasks_Cnt_u16; i++)
		{
			Metrics_TaskTimes_Str[i].CpuUse_Cnt_u32 = 0U;
		}
#if( BC_METRICS_RUNBLCPUUSE == STD_ON )
		for(i=0; i<d_NumberofRunnables_Cnt_u16; i++)
		{
			Metrics_RunnableTimes_Str[i].CpuUse_Cnt_u32 = 0U;
		}
#endif
		_pmuResetCycleCounter_();
	}/* Check if the update interval has passed. (160,000 cycles per millisecond)*/
	else if(elapsedTime_Cnt_T_u32 >= D_CPUUSEUPDATEINTERVAL_MS_U32*160000)
	{
		METRICS_ENTER_EXCLUSIVEAREA2;

		/* Calculate the CPU Utilization Interval to use for scaling time to percent */
		/* Determine elapsed time and reset within interrupt disable to prevent calculation errors due to preemption */
		elapsedTime_Cnt_T_u32 = _pmuGetCycleCount_();
		_pmuResetCycleCounter_();

		for(i=0; i<d_NumberofTasks_Cnt_u16; i++)
		{
			taskCpuTime_Cnt_T_u32[i] = Metrics_TaskTimes_Str[i].CpuUse_Cnt_u32;
			Metrics_TaskTimes_Str[i].CpuUse_Cnt_u32 = 0;
		}
		taskCpuTime_Cnt_T_u32[D_METRICS_CNT_U08] += Metrics_ActiveTime_Cnt_M_u32;
		Metrics_ActiveTime_Cnt_M_u32 = 0U;

#if( BC_METRICS_RUNBLCPUUSE == STD_ON )
		/* Capture configured Runnables CPU Use */
		for(i=0; i<d_NumberofRunnables_Cnt_u16; i++)
		{
			runnableCpuTime_Cnt_T_u32[i] = Metrics_RunnableTimes_Str[i].CpuUse_Cnt_u32;
			Metrics_RunnableTimes_Str[i].CpuUse_Cnt_u32 = 0;
		}
#endif

		METRICS_EXIT_EXCLUSIVEAREA2;

		/* Process buffered data, e.g. calculate an aggregate utilization, individual, and or custom grouping */
		for(i=0; i<d_NumberofTasks_Cnt_u16; i++)
		{
			/* Exclude Task Use Time from calculation if masked out by the user mask */
			CpuTimeSum_Cnt_T_u32 += taskCpuTime_Cnt_T_u32[i];

			/* Compute individual task CPU Usage*/
			Metrics_TaskTimes_Str[i].CpuUse_Pct_f32 = ((float32)taskCpuTime_Cnt_T_u32[i]/(float32)elapsedTime_Cnt_T_u32) * 100.0f;
		}

#if( BC_METRICS_RUNBLCPUUSE == STD_ON )
		/* Capture configured Runnables CPU Use */
		/*This loop takes long enough that it causes a watchdog timeout.*/
		for(i=0; i<d_NumberofRunnables_Cnt_u16; i++)
		{
			Metrics_RunnableTimes_Str[i].CpuUse_Pct_f32 = ((float32)runnableCpuTime_Cnt_T_u32[i]/(float32)elapsedTime_Cnt_T_u32) * 100.0f;
		}
#endif

		Metrics_CpuUse_Pct_M_f32 = ((float32)CpuTimeSum_Cnt_T_u32/(float32)elapsedTime_Cnt_T_u32) * 100.0f;
	} /* elapsedTime_Cnt_T_u32 >= D_CPUUSEUPDATEINTERVAL_MS_U32 */
}

#if( BC_METRICS_STACKUSE == STD_ON )
/****************************************************************************
 * Name:        Metrics_CalcStackUse()
 * Description: Determine the stack usage
 * Inputs:      None
 * Outputs:     None
 ****************************************************************************/
static FUNC(void, AUTOMATIC) Metrics_CalcStackUse( void )
{
	uint16 i;

	/* Calculate the Stack usage */
	for( i=0; i < osdNumberOfAllTasks; i++ )
	{
		Metrics_TaskTimes_Str[i].StackUse_Byte_u16 = osGetStackUsage( i );
	}
}
#endif /* BC_METRICS_STACKUSE */

#endif /* defined D_ENABLEMETRICS_CNT_LGC */
