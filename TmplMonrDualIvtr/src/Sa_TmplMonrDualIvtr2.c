/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_TmplMonrDualIvtr2.c
 *     Workspace:  C:/SynergyWorkArea/Working/TmplMonrDualIvtr/autosar
 *     SW-C Type:  Sa_TmplMonrDualIvtr2
 *  Generated at:  Fri Sep 25 11:48:54 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_TmplMonrDualIvtr2>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name  : Sa_TmplMonrDualIvtr2.c
* Module Description: Set the Watchdog Monitor to LOW
* Project           : CBD
* Author            : Jayakrishnan T
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       czmgrw %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  -----------
* 09/25/15   1       JK        Initial implementation of ES19D Temporal Monitor-Dual Inverters				EA3#3236
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Runnable Entities:
 ==================
  TmplMonrDualIvtr2_Per1
    Periodic function intended to be placed at the beginning of the 2ms task list to create the rising edge of the WdMonitor signal.

 *********************************************************************************************************************/

#include "Rte_Sa_TmplMonrDualIvtr2.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * IoHwAb_BoolType: Integer in interval [0...1]
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_TMPLMONRDUALIVTR2_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: TmplMonrDualIvtr2_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_WdMonitor_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_WdMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_TMPLMONRDUALIVTR2_APPL_CODE) TmplMonrDualIvtr2_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TmplMonrDualIvtr2_Per1
 *********************************************************************************************************************/
	
	(void)Rte_Call_WdMonitor_OP_SET(STD_LOW);
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_TMPLMONRDUALIVTR2_APPL_CODE
#include "MemMap.h"   /* PRQA S 5087 */



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
