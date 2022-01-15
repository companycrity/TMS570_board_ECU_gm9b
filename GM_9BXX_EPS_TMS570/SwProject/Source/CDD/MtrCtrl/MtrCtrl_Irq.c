/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : MtrCtrl_Irq.c
* Module Description: Motor Control Interrupt Request Service
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#6 %
 * %derived_by:       fz9hxm %
 * %date_modified:    Wed Feb 12 11:38:58 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 12/01/15  5        GMN       EA3#4064: Update SF-99 and 83.3Hz noise reduction                             4962
 *                              EA3#4365: Change MtrVel3_Per1 order                                           4389
 * 04/05/17  6        CP        EA3#15127: Remove cogging / ripple cancelation calls from motor control ISR task loop
 */


/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"
#include "MtrCtrl_Irq.h"
#include "Os.h"
#include "adc_regs.h"
#include "dma_regs.h"
#include "vim_regs.h"
#include "CDD_Const.h"
#include "PwmCdd.h"
#include "ePWM.h"
#include "CDD_Func.h"
#include "T1_AppInterface.h"
#include "Ap_MtrCtrl.h"
#include "Sa_CmMtrCurr3Phs.h"
#include "Sa_MtrVel.h"
#include "PwmCdd.h"
#include "Nhet.h"
#include "IoHwAbstractionUsr.h"
#include "Dma.h"
#include "Sa_MotMeclPosn1.h"
#include "Sa_MotMeclPosn2.h"
#include "Ap_MotPosnCmp.h"
#include "Sa_DigMSBArbn.h"

/* TODO: Determine if this INTERRUPT pragma is required when using the  */
/*        interrupt keyword.                                            */
#pragma INTERRUPT(Isr_MtrCtrl, IRQ);
STATIC VAR(uint16, AUTOMATIC) Loop125usCounter_Cnt_M_u16;

/*****************************************************************************
* Local Functions
*****************************************************************************/
FUNC(void, MTRCTRL_CODE) MtrCtrlTaskList(void);


/*****************************************************************************
  * Name:        EnableIrq
  * Description: 
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
MTRCTRL_COMPILER_ISR void Isr_MtrCtrl(void)
{
	T1_TraceStartNoSusp(T1_Isr_MtrCtrl_ID);

	MtrCtrlTaskList();
	
	IoHwAb_CaptureADC();
	
	/* BTC Interrupt Flag Clear */
	DMACTRLREG->BTCFLAG = (1u << 3);

	/* ADC2 Event (Group 0) EOC Interrupt Flag Clear */
	adcREG2->GxSR[1u] = 1u;


	T1_TraceStopNoSusp(T1_Isr_MtrCtrl_ID);
}

FUNC(void, MTRCTRL_CODE) MtrCtrlTaskList(void)
{
	/* MotMeclPosn1_Per1 and MotMeclPosn2_Per1 must be called before Motor Velocity and Current Measurement */
	MotMeclPosn1_Per1();
	MotMeclPosn2_Per1();

	DigMSBArbn_Per1();
	MotPosnCmp_Per1();
	
	Loop125usCounter_Cnt_M_u16 = (Loop125usCounter_Cnt_M_u16 ^ 1U);
	if( Loop125usCounter_Cnt_M_u16 == 1U )
	{
		CurrDQPer1();
		/* CoggingTrqCanc is removed from Sw9. SF99 will be updated to remove cogging/ripple 
		cancellation and revise the regulator bandwidth setting */
		/*TrqCogCancRefPer1();*/
		
		PICurrCntrl_Per1();
		MicroDiag_Per1();
		CDDInterface_Per5();
	}

	PwmCdd_Per1();
	ePWM_Per1();
	Nhet1CfgAndUse_Per3();
	MtrVel3_Per1();
}

