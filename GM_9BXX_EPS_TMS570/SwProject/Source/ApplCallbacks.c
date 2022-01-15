/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : ApplCallbacks.c
* Module Description: Definition of Application Callback Functions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#3 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Mon Jul 29 08:10:19 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 08/14/15  2        GMN       Correcting format and warning removes
 * 09/23/15  3        GMN       EA3#2375: Update the NvM_WaitReady function to monitor the status of the       3361
 *                                        FEE driver
 */

#include "Std_Types.h"
#include "NvM_Cfg.h"
#include "EcuM.h"
#include "NvM.h"
#include "MemIf_Types.h"
#include "Os.h"
#include "Gpt.h"
#include "WdgM.h"
#include "Wdg.h"
#include "WdgM_PBcfg.h"
#include "Wdg_TMS570LS3x_Lcfg.h"
#include "fixmath.h"
#include "GlobalMacro.h"
#include "Interrupts.h"
#include "RednRpdShtdn.h"
#include "CDD_Data.h"
#include "FlsTst.h"
#include "Ap_DfltConfigData.h"
#include "Cd_FeeIf.h"


/*****************************************************************************
  * Name:        StartupHook
  * Description: Required OSEK Hook function, with no functional requirements
  *               in the context of the project.
  * Called by:   OS (On start-up)
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, APPLCB_CODE) StartupHook(void)
{
}

/*****************************************************************************
  * Name:        ShutdownHook
  * Description: Required OSEK Hook function, to start shutdown process on OS
  *               shutdown event.
  * Called by:   OS (On shutdown)
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, OSHOOK_CODE) ShutdownHook(StatusType s)
{
	EcuM_Shutdown();
}


/*****************************************************************************
  * Name:        SystemTick
  * Description: 
  * Called by:   Gpt Timer Expiration Notification
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, APPLCB_CODE) SystemTick(void)
{
	/*
	 * TODO: Move System Time tick count update here or update the system time to use the full
	 * 64 bit hardware counter to alleviate the need for maintaining an accumulator seperate from
	 * the hardware accumulator.
	 */
	CounterTriggerSystemTimer();
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Appl_WaitNvMReady                                          **
**                                                                            **
** DESCRIPTION   : Performs a synchronous wait until NvM has finished         **
**                 the last job                                               **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** GLOBAL DATA   : Appl_Nv_Mode:       Idle, fast or slow mode                **
**                 Appl_NvBlockNumber: Id of NvM block to wait for            **
**                                                                            **
** PARAMETER     : blockNumber: Id of  NvM block to wait for                  **
**                 fastMode:    TRUE:  Schedule Nv stack in loop (used during **
**                                     startup or Coding)                     **
**                              FALSE: Nv stack is scheduled via cyclic tasks **
**                                     (used during normal operation)         **
**                                                                            **
** RETURN        : --                                                         **
**                                                                            **
** REMARKS       : This function is blocking! Do not call this function       **
**                 within the context of a high priority task!!!              **
**                                                                            **
*******************************************************************************/
void Appl_WaitNvMReady(const uint16 blockNumber, const boolean fastMode)
{
	uint8 FeeStatus;
	NvM_RequestResultType Int_NvMultiBlockStatus;

	do
	{
		if (fastMode == TRUE)
		{
			NvM_MainFunction();
			TWrapC_Fee_MainFunction();
		}

		NvM_GetErrorStatus(blockNumber, &Int_NvMultiBlockStatus);

		FeeStatus = TWrapC_Fee_GetStatus();
	}
	while ((Int_NvMultiBlockStatus == NVM_REQ_PENDING) || (FeeStatus != MEMIF_IDLE));
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Appl_FlsTstCompletedNotif                                  **
**                                                                            **
** DESCRIPTION   : FlsTst configured notification that is invoked upon the    **
**                  the completion of the Runtime config set.  In order to    **
**                  minimize Flash bus contentions between the DMA and micro  **
**                  core during EPS runtime, the Flash test is suspended      **
**                  after the first test interval is completed. This strategy **
**                  provides better micrprocessor throughput resulting from   **
**                  less wait states caused by Flash access contentions.      **
**                                                                            **
** PRECONDITIONS : --                                                         **
**                                                                            **
** RETURN        : void                                                       **
**                                                                            **
*******************************************************************************/
FUNC(void, AUTOMATIC) Appl_FlsTstCompletedNotif(void)
{
	FlsTst_Suspend();
}
