/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_BattVltg.c
 *     Workspace:  C:/SynergyWorkArea/Working/BattVltg/autosar
 *     SW-C Type:  Ap_BattVltg
 *  Generated at:  Wed May 18 18:25:47 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_BattVltg>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name	: BattVltg.c
* Module Description: Battery or Switched Voltage Measurement and Arbitration
* Project           : CBD
* Author            : Krishna Kanth Anne
*
* Module File Name	: Ap_BattVltg.c
*
****************************************************************************
 * Version Control:
 * %version:          1 %
 * %derived_by:       nz4qtt %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/17/15   1        KK     		Initial Implementation of BattVltg - ES08C   						       13257
 * 04/21/16	  2        JK           Anomaly fix EA3#7270- Min value of Bridge Vltg updated                  EA3#7739
 * 18/05/16   3        JK           Updated to FDD v3.0.0                                                   EA3#8465
 * 23/05/16   4        JK           Fix task to correct the order of switch case statements for             EA3#8465
 * 									correlation status
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.

  Volt_f32 of Port Interface Vecu_Volt_f32
    This port prototype is inteded to communicate voltage signals that represent the ecu supplied voltage.  This signal has a lower limit, which is non-zero, to allow users of the signal to use it as a denominator in an expression without requiring a divide by 0 check.

 *********************************************************************************************************************/

#include "Rte_Ap_BattVltg.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "GlobalMacro.h"
#include "CalConstants.h"

/* Deviations from MISRA-C Standards */
/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */


#define	D_BRDGFLTVLTG_VOLT_F32 18.0F
#define D_BRDGVLTGMIN_VOLT_F32 6.0F
#define D_CORRLNSTSSWD2FLT_U08  3U
#define D_CORRLNSTSSWD1FLT_U08  5U
#define D_CORRLNSTSBATTVLTGFLT_U08  6U
#define D_CORRLNSTSNOFLT_U08  7U


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
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
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
 * Float: D_VECUMIN_VOLTS_F32 = 5
 * Float: D_ZERO_ULS_F32 = 0
 * UInt8: D_BATTVLTGCORRLNSTSINIT_CNT_U08 = 7u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_BATTVLTG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BattVltg_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BattVltg_Init1_BrdgVltg_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_BattVltg_Init1_BrdgVltg_Volt_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BATTVLTG_APPL_CODE) BattVltg_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BattVltg_Init1
 *********************************************************************************************************************/
	 Rte_IWrite_BattVltg_Init1_BrdgVltg_Volt_f32(D_BRDGVLTGMIN_VOLT_F32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BattVltg_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt8 Rte_IRead_BattVltg_Per1_BattSwdVltgCorrlnSts_Cnt_u08(void)
 *   Float Rte_IRead_BattVltg_Per1_BattVltgSwd1_Volt_f32(void)
 *   Float Rte_IRead_BattVltg_Per1_BattVltgSwd2_Volt_f32(void)
 *   Float Rte_IRead_BattVltg_Per1_BattVltg_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BattVltg_Per1_BrdgVltg_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_BattVltg_Per1_BrdgVltg_Volt_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BATTVLTG_APPL_CODE) BattVltg_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BattVltg_Per1
 *********************************************************************************************************************/

	VAR(uint8, AUTOMATIC) BattSwdVltgCorrlnSts_Cnt_T_u08;
	VAR(float32, AUTOMATIC) BattVltgSwd1_Volt_T_f32;
	VAR(float32, AUTOMATIC)	BattVltgSwd2_Volt_T_f32;
	VAR(float32, AUTOMATIC)	BattVltg_Volt_T_f32;
	VAR(float32, AUTOMATIC) BrdgVltg_Volt_T_f32;
	VAR(float32, AUTOMATIC) BattVltgSwd_Volt_T_f32;

	/* Store Module Inputs to Local Copies */
	BattSwdVltgCorrlnSts_Cnt_T_u08 = Rte_IRead_BattVltg_Per1_BattSwdVltgCorrlnSts_Cnt_u08();
	BattVltgSwd1_Volt_T_f32	= Rte_IRead_BattVltg_Per1_BattVltgSwd1_Volt_f32();
	BattVltgSwd2_Volt_T_f32	= Rte_IRead_BattVltg_Per1_BattVltgSwd2_Volt_f32();
	BattVltg_Volt_T_f32 = Rte_IRead_BattVltg_Per1_BattVltg_Volt_f32();

	BattVltgSwd_Volt_T_f32 = Max_m(BattVltgSwd1_Volt_T_f32, BattVltgSwd2_Volt_T_f32);

	switch (BattSwdVltgCorrlnSts_Cnt_T_u08)
	{
		/* BattSwdVltgCorrlnSts = No Fault */
		case(D_CORRLNSTSNOFLT_U08):
			if(BattVltg_Volt_T_f32 >= k_BattVltgSwdMax_Volt_f32)
			{
				BrdgVltg_Volt_T_f32 = BattVltg_Volt_T_f32;
			}
			else
			{
				BrdgVltg_Volt_T_f32 = BattVltgSwd_Volt_T_f32;
			}
		break;

		/* BattSwdVltgCorrlnSts = BattVltgSwd2Fault */
		case(D_CORRLNSTSSWD2FLT_U08):
			if(BattVltg_Volt_T_f32 >= k_BattVltgSwdMax_Volt_f32)
			{
				BrdgVltg_Volt_T_f32 = BattVltg_Volt_T_f32;
			}
			else
			{
				BrdgVltg_Volt_T_f32 = BattVltgSwd1_Volt_T_f32;
			}
		break;

		/* BattSwdVltgCorrlnSts = BattVltgSwd1Fault */
		case(D_CORRLNSTSSWD1FLT_U08):
			if(BattVltg_Volt_T_f32 >= k_BattVltgSwdMax_Volt_f32)
			{
				BrdgVltg_Volt_T_f32 = BattVltg_Volt_T_f32;
			}
			else
			{
				BrdgVltg_Volt_T_f32 = BattVltgSwd2_Volt_T_f32;
			}
		break;

		/* BattSwdVltgCorrlnSts = BattVltgFault */
		case(D_CORRLNSTSBATTVLTGFLT_U08):
				BrdgVltg_Volt_T_f32 = BattVltgSwd_Volt_T_f32;
		break;

		/* BattSwdVltgCorrlnSts = No Correlation */
		/* Default Case */
		default:
				BrdgVltg_Volt_T_f32 = D_BRDGFLTVLTG_VOLT_F32;
		break;
	}

	BrdgVltg_Volt_T_f32 = Limit_m(BrdgVltg_Volt_T_f32, k_BattVltgCorrlnSysMinVltg_Volt_f32, k_BrdgVltgMax_Volt_f32);

	/* Write local copies to module outputs */
	Rte_IWrite_BattVltg_Per1_BrdgVltg_Volt_f32(BrdgVltg_Volt_T_f32);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_BATTVLTG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


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
