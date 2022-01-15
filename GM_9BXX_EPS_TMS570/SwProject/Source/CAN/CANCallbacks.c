/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CANCallbacks.c
* Module Description: Definition of CAN Releated Application Callback Functions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          3 %
 * %derived_by:       zz4r1x %
 * %date_modified:    Wed Oct 30 12:23:53 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 02/08/16  2        GMN       EA3#4984: Bus Off new strategy to set NTC                                     5973
 */

#include "Std_Types.h"
#include "can_inc.h"
#include "il_inc.h"
#include "Ap_DiagMgr.h"
#include "CDD_Data.h"
#include "Rte_Ap_SrlComInput.h"
#include "Interrupts.h"

void DCan1_level0_Irqfunc(void)
{
	CanIsr_0();
}
void DCan2_level0_Irqfunc(void)
{
	CanIsr_1();
}
void ApplTrcvrNormalMode(NM_CHANNEL_APPLTYPE_ONLY)
{
}

void ApplNwmVnActivated(NM_CHANNEL_APPLTYPE_ONLY, vuint8 vnHndl)
{
	NxtrDiagMgr9_SetNTCStatus(NTC_Num_BusOffCh1, 0x01, NTC_STATUS_PASSED);
	NxtrDiagMgr9_SetNTCStatus(NTC_Num_BusOffCh2, 0x01, NTC_STATUS_PASSED);
}
void ApplNwmVnDeactivated(NM_CHANNEL_APPLTYPE_ONLY, vuint8 vnHndl)
{
}

void ApplCanAddCanInterruptDisable(CanChannelHandle channel)
{
	if (channel == 0)
	{
		DisableCan1Interrupt();
	}
	else
	{
		DisableCan2Interrupt();
	}
}

void ApplCanAddCanInterruptRestore(CanChannelHandle channel)
{
	if (channel == 0)
	{
		EnableCan1Interrupt();
	}
	else
	{
		EnableCan2Interrupt();
	}
}
