/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SnsrOffsCorrn.c
 *     Workspace:  C:/SynergyWorkArea/Working/SnsrOffsCorrn/autosar
 *     SW-C Type:  Ap_SnsrOffsCorrn
 *  Generated at:  Tue Dec  1 15:56:17 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SnsrOffsCorrn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name  : Ap_SnsrOffsCorrn.c
* Module Description: SnsrOffsCorrn corrects the Yaw rate, Hand wheel Position and Hand wheel Torque signals using their
* 					  corresponding offset learnt values.Each offset value is learnt by the SF051A Sensor Offset Learning.
* Project           : CBD
* Author            : Jayakrishnan T
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       czmgrw %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  -----------
* 12/1/15   1       JK        Initial implementation of SF-052A SnsrOffsCorrn								EA3#3712
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_SnsrOffsCorrn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "GlobalMacro.h"
#include "CalConstants.h"

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance.  Rule suppressed by line at each occurrence.*/

#define D_HWAGLOLIM_HWDEG_F32   (-1440.0F)
#define D_HWAGHILIM_HWDEG_F32     1440.0F
#define D_HWTQLOLIM_HWNM_F32     (-10.0F)
#define D_HWTQHILIM_HWNM_F32       10.0F
#define D_YAWRATELOLIM_VEHDEGPS_F32 (-120.0F)
#define D_YAWRATEHILIM_VEHDEGPS_F32   120.0F

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
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_SNSROFFSCORRN_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsCorrn_Per1
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
 *   Float Rte_IRead_SnsrOffsCorrn_Per1_HwAgOffs_HwDeg_f32(void)
 *   Float Rte_IRead_SnsrOffsCorrn_Per1_HwPosn_HwDeg_f32(void)
 *   Float Rte_IRead_SnsrOffsCorrn_Per1_HwTqOffs_HwNm_f32(void)
 *   Float Rte_IRead_SnsrOffsCorrn_Per1_HwTq_HwNm_f32(void)
 *   Float Rte_IRead_SnsrOffsCorrn_Per1_YawRateOffs_DegpS_f32(void)
 *   Float Rte_IRead_SnsrOffsCorrn_Per1_YawRate_DegpS_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SnsrOffsCorrn_Per1_HwAgCorrd_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SnsrOffsCorrn_Per1_HwAgCorrd_HwDeg_f32(void)
 *   void Rte_IWrite_SnsrOffsCorrn_Per1_HwTqCorrd_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_SnsrOffsCorrn_Per1_HwTqCorrd_HwNm_f32(void)
 *   void Rte_IWrite_SnsrOffsCorrn_Per1_YawRateCorrd_DegpS_f32(Float data)
 *   Float *Rte_IWriteRef_SnsrOffsCorrn_Per1_YawRateCorrd_DegpS_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSCORRN_APPL_CODE) SnsrOffsCorrn_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsCorrn_Per1
 *********************************************************************************************************************/

	/* Input variables */
	VAR(float32, AUTOMATIC) HwTq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HwPosn_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) YawRate_VehDegpS_T_f32;
	VAR(float32, AUTOMATIC) HwAgOffs_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HwTqOffs_HwNm_T_f32;
	VAR(float32, AUTOMATIC) YawRateOffs_VehDegpS_T_f32;

	/* Output variables */
	VAR(float32, AUTOMATIC) HwAgCorrd_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) HwTqCorrd_HwNm_T_f32;
	VAR(float32, AUTOMATIC) YawRateCorrd_VehDegpS_T_f32;

	/* Read RTE Inputs */
	HwTq_HwNm_T_f32 		=  Rte_IRead_SnsrOffsCorrn_Per1_HwTq_HwNm_f32();                       /* REQ: SF052A #10 I */
	HwPosn_HwDeg_T_f32 		=  Rte_IRead_SnsrOffsCorrn_Per1_HwPosn_HwDeg_f32();                    /* REQ: SF052A #11 I */
	YawRate_VehDegpS_T_f32	=  Rte_IRead_SnsrOffsCorrn_Per1_YawRate_DegpS_f32();       			   /* REQ: SF052A #12 I */
	HwTqOffs_HwNm_T_f32 	=  Rte_IRead_SnsrOffsCorrn_Per1_HwTqOffs_HwNm_f32();                   /* REQ: SF052A #13 I */
	HwAgOffs_HwDeg_T_f32 	=  Rte_IRead_SnsrOffsCorrn_Per1_HwAgOffs_HwDeg_f32();                  /* REQ: SF052A #14 I */
	YawRateOffs_VehDegpS_T_f32 =  Rte_IRead_SnsrOffsCorrn_Per1_YawRateOffs_DegpS_f32();            /* REQ: SF052A #15 I */

	/* REQ: SF052A #59 I */
	if(k_SnsrOffsCorrn_OffsEna_Cnt_lgc == TRUE)
	{
		/* Limiting the offset values */
		HwTqOffs_HwNm_T_f32      =  Limit_m(HwTqOffs_HwNm_T_f32,-k_SnsrOffsCorrn_HwTqLrndOffsLim_HwNm_f32,k_SnsrOffsCorrn_HwTqLrndOffsLim_HwNm_f32);                           /* REQ: SF052A #28 I */
		HwAgOffs_HwDeg_T_f32     =  Limit_m(HwAgOffs_HwDeg_T_f32,-k_SnsrOffsCorrn_HwAgLrndOffsLim_HwDeg_f32,k_SnsrOffsCorrn_HwAgLrndOffsLim_HwDeg_f32);                        /* REQ: SF052A #29 I */
		YawRateOffs_VehDegpS_T_f32  =  Limit_m(YawRateOffs_VehDegpS_T_f32,-k_SnsrOffsCorrn_YawRateLrndOffsLim_VehDegpS_f32,k_SnsrOffsCorrn_YawRateLrndOffsLim_VehDegpS_f32);   /* REQ: SF052A #30 I */

		/* Offset Correction */
		HwTqCorrd_HwNm_T_f32     =  HwTq_HwNm_T_f32 - HwTqOffs_HwNm_T_f32;                        /* REQ: SF052A #31 I */
		HwAgCorrd_HwDeg_T_f32    =  HwPosn_HwDeg_T_f32 - HwAgOffs_HwDeg_T_f32;                    /* REQ: SF052A #32 I */
		YawRateCorrd_VehDegpS_T_f32 =  YawRate_VehDegpS_T_f32 - YawRateOffs_VehDegpS_T_f32;       /* REQ: SF052A #33 I */
	}
	else
	{
		/* Signals are passed through without offset correction */
		HwTqCorrd_HwNm_T_f32     =  HwTq_HwNm_T_f32;
		HwAgCorrd_HwDeg_T_f32    =  HwPosn_HwDeg_T_f32;
		YawRateCorrd_VehDegpS_T_f32 =  YawRate_VehDegpS_T_f32;
	}
	/* ENDREQ: SF052A #59 I */
	
	/* Limiting the offset corrected values */
	HwTqCorrd_HwNm_T_f32     =  Limit_m(HwTqCorrd_HwNm_T_f32,D_HWTQLOLIM_HWNM_F32,D_HWTQHILIM_HWNM_F32);                                 /* REQ: SF052A #35 I */
	HwAgCorrd_HwDeg_T_f32    =  Limit_m(HwAgCorrd_HwDeg_T_f32,D_HWAGLOLIM_HWDEG_F32,D_HWAGHILIM_HWDEG_F32);                              /* REQ: SF052A #36 I */
	YawRateCorrd_VehDegpS_T_f32 =  Limit_m(YawRateCorrd_VehDegpS_T_f32,D_YAWRATELOLIM_VEHDEGPS_F32,D_YAWRATEHILIM_VEHDEGPS_F32);         /* REQ: SF052A #37 I */

	Rte_IWrite_SnsrOffsCorrn_Per1_HwTqCorrd_HwNm_f32(HwTqCorrd_HwNm_T_f32);                      /* REQ: SF052A #17 I */
	Rte_IWrite_SnsrOffsCorrn_Per1_HwAgCorrd_HwDeg_f32(HwAgCorrd_HwDeg_T_f32);                    /* REQ: SF052A #18 I */
	Rte_IWrite_SnsrOffsCorrn_Per1_YawRateCorrd_DegpS_f32(YawRateCorrd_VehDegpS_T_f32);           /* REQ: SF052A #19 I */
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SNSROFFSCORRN_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */


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
