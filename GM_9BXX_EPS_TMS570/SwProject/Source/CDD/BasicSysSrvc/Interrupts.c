/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Interrupts.c
* Module Description: Interrupt Enable/Disable Interface
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Nov 5 16:33:22 2010
* %version:          1 %
* %derived_by:       CZ8L9T %
* %date_modified:    Mon Sep 23 12:07:24 2013 % 
*---------------------------------------------------------------------------
 *   Date      Rev     Author    Change Description                                                            SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 09/24/15  2        GMN       EA3#2376: Integrage fix for NTC 0x02A sets during Crank pulse testing          3362
 */

/*****************************************************************************
* Include files
*****************************************************************************/
#include "Std_Types.h"
#include "CDD_Const.h"
#include "vim_regs.h"
#include "Os.h"
#include "rti_regs.h"

/* TODO: Generate the ISR priority defines based on the Os Config in the ECUC file.
 *			The priorities must be manually entered in the following set of defines
 *			to match the configuration in the Os.
 */
#define RTI_COMP0_INT       4u

#define DCAN1_LEVEL0_INT    16u
#define DCAN2_LEVEL0_INT    35u
#define ISR_MTRCTRL_INT     (D_MTRISRVIMIDX_CNT_u16)
#define ESML_INT    		20u
#define CRC_INT    			19u
#define I2C_INT				8u
#define OVERVOLTTHRESH_INT 	31u

/*****************************************************************************
* Local Functions
*****************************************************************************/
void EnableIrq(uint8);
void DisableIrq(uint8);

FUNC(void, INTERRUPT_CODE) EnableFIQInterrupts(void)
{
	_enable_FIQ();
}
/*****************************************************************************
* Global Interrupt Enable Functions
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) EnableCanInterrupt(void)
{
  EnableIrq(DCAN1_LEVEL0_INT);
  EnableIrq(DCAN2_LEVEL0_INT);
}

FUNC(void, INTERRUPT_CODE) EnableCan1Interrupt(void)
{
	EnableIrq(DCAN1_LEVEL0_INT);
}

FUNC(void, INTERRUPT_CODE) EnableCan2Interrupt(void)
{
	EnableIrq(DCAN2_LEVEL0_INT);
}

FUNC(void, INTERRUPT_CODE) DisableCan1Interrupt(void)
{
	DisableIrq(DCAN1_LEVEL0_INT);
}

FUNC(void, INTERRUPT_CODE) DisableCan2Interrupt(void)
{
	DisableIrq(DCAN2_LEVEL0_INT);
}

FUNC(void, INTERRUPT_CODE) EnableMtrCtlInterrupt(void)
{
  EnableIrq(ISR_MTRCTRL_INT);
}

FUNC(void, INTERRUPT_CODE) EnableSysTickInterrupt(void)
{  
  EnableIrq(RTI_COMP0_INT);  
}

FUNC(void, INTERRUPT_CODE) EnableESMLInterrupt(void)
{
  EnableIrq(ESML_INT);
}

FUNC(void, INTERRUPT_CODE) EnableCRCInterrupt(void)
{
  EnableIrq(CRC_INT);
}

FUNC(void, INTERRUPT_CODE) EnableI2CInterrupt(void)
{
  EnableIrq(I2C_INT);
}

FUNC(void, INTERRUPT_CODE) EnableOverVoltThreshInterrupt(void)
{
	EnableIrq(OVERVOLTTHRESH_INT);
}
/*****************************************************************************
* Global Interrupt Disable Functions
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) DisableMtrCtlInterrupt(void)
{
  DisableIrq(ISR_MTRCTRL_INT);
}

FUNC(void, INTERRUPT_CODE) DisableSysTickInterrupt(void)
{
	DisableIrq(RTI_COMP0_INT);
}

FUNC(void, INTERRUPT_CODE) DisableI2CInterrupt(void)
{
	DisableIrq(I2C_INT);
}
/*****************************************************************************
* Local Functions
*****************************************************************************/

/*****************************************************************************
  * Name:        EnableIrq
  * Description: 
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) EnableIrq(uint8 irqRequest)
{
  if (irqRequest < 32)
  {
    osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKSET0),
      (((osuint32)1) << (irqRequest)));
  }
  else if (irqRequest < 64)
  {
    irqRequest -= 32;
    osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKSET1),
      (((osuint32)1) << (irqRequest)));
  }
  else
  {
    irqRequest -= 64;
    osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKSET2),
      (((osuint32)1) << (irqRequest)));
  }
}


/*****************************************************************************
  * Name:        DisableIrq
  * Description: 
  * Inputs:      None 
  * Outputs:     None
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) DisableIrq(uint8 irqRequest)
{
  if (irqRequest < 32)
  {
    osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKCLR0),
      (((osuint32)1) << (irqRequest)));
  }
  else if (irqRequest < 64)
  {
    irqRequest -= 32;
    osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKCLR1),
      (((osuint32)1) << (irqRequest)));
  }
  else
  {
    irqRequest -= 64;
    osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->REQMASKCLR2),
      (((osuint32)1) << (irqRequest)));
  }
}

/*****************************************************************************
  * Name:        ClearSysTickInterruptFlg
  * Description:
  * Inputs:      None
  * Outputs:     None
*****************************************************************************/
FUNC(void, INTERRUPT_CODE) ClearSysTickInterruptFlg(void)
{
	osWritePeripheral32(OS_MEM_AREA_RTI, (osuint32)&(rtiREG1->INTFLAG), 0xFFFFFFFFU);
	osWritePeripheral32(OS_MEM_AREA_VIM, (osuint32)&(VIM->INTREQ0), 0x00000010U);
}

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
                                    (MDD Rev & Date)
-------   -------  --------  -----------------------------------  ----------
11/11/10   1        JJW      Initial file creation
12/19/10   2        LWW      Changes for EEPROM SPI port change
04/13/11   4        JJW      Added CrossChk ISR enable/disable
04/15/11   5        JJW      Added enable FIQ to motor control enable.
                              Replaced register adress pointer constant 
							  access with vim.h structure definitions
04/25/11   6        JJW      Removed enable FIQ from motor control enable.
05/31/11   7        LWW      Added FIQ enable function
08/16/11   8        YY       Added Turns Counter SPI interrupt enable function
09/21/11   8.1.1    LWW      Removed BMW specific interrupts, added CAN interrupts
01/10/12   8.1.2    LWW      Changes for user defined systemtick
03/12/12   8.1.3    JJW      Changes for TurnsCounter Spi interrupts
******************************************************************************/
