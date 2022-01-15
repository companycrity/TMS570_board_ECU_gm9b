/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_MotPosnCmp.c
 *     Workspace:  C:/Users/nzt9hv/Documents/Synergy/ccm_wa/ESG_Dev_65/MotPosnCmp/MotPosnCmp/autosar
 *     SW-C Type:  Ap_MotPosnCmp
 *  Generated at:  Fri Aug 28 08:25:11 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_MotPosnCmp>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*
* Copyright 2015 Nexteer Automotive
* Nexteer Confidential
*
* Module File Name  : MotPosnCmp.c
* Module Description: Implementation of MotPosnCmp
* Project           : CBD 
* Author            : Selva Sengottaiyan
* Version Control:
* Date Created:      Mon Aug 24 13:41:03 2015
* %version:          2 %
* %derived_by:       czmgrw %
* %date_modified:     Mon Aug 24 13:41:03 2015
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  -------------------------------------------------------------------------------  ------
 * 08/19/15  1.0 	 Selva       Initial Version FDD ES62A v01 (ICR EA3#2490)                                  EA3#2765
 * 10/15/15  2.0     JK          Anomaly Fix EA3#3691 Cumulative Motor Position Not Calculated Correctly v02   EA3#3772
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  NvM_DestPtr
    DataPtr Type to be used by WriteBlock, ReadBlock and RestoreBlockDefaults operations. 	This type is used for all NVRAM blocks

 *********************************************************************************************************************/

#include "Rte_Ap_MotPosnCmp.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "MotPosnCmp_Cfg.h"
#include "Ap_MotPosnCmp.h"
#include "GlobalMacro.h"
#include "fixmath.h"
#include "Crc.h"		/* Needed for Crc_CalculateCRC16() */
 

 
 /* MISRA-C:2004 Rule 8.7: This deviation is required to keep the memory map intact.  Rule suppressed by line at each occurrence. */
 
 /* MISRA-C:2004 Rule 11.4: This deviation is required because of passing pointer.  Rule suppressed by line at each occurrence. */
 
 /* MISRA-C:2004 Rule 19.1: This deviation is required for AUTOSAR memory map requirements.  Rule suppressed by line at each occurrence. */

#define D_BEMFCRCIDX_CNT_U16  1U 
#define D_BEMFCRCSEED_CNT_U16 4369U 
#define D_BEMFIDX_CNT_U16     0U 
#define D_BEMFSRVCSIZE_CNT_U16 2U 
#define D_DEGPERREV_MOTDEGPERREV_U16P0 360U 
#define D_MOTPOLECNT_CNT_U08 6U  
#define D_BEMFCRCPASS_CNT_U08  0U
#define D_BEMFCRCFAIL_CNT_U08  1U
#define D_MAXMOTAG_DEG_F32     ( 11796479.99F)
#define D_MINMOTAG_DEG_F32    ( -11796480.0F)

#define MOTPOSNCMP_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */ 
 
	STATIC VAR(uint16, AUTOMATIC)  MotPosnCmp_MotPosnMeclPrev_Rev_M_u0p16; /* PRQA S 3218 */

#define MOTPOSNCMP_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */  


#define MOTPOSNCMP_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */ 

	STATIC VAR(boolean, AUTOMATIC)  MotPosnCmp_MotPosnCmpFirstRunCmpl_Cnt_M_lgc; /* PRQA S 3218 */

#define MOTPOSNCMP_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */  
 
 
#define MOTPOSNCMP_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */ 

	STATIC VAR(sint32, AUTOMATIC) MotPosnCmp_MotPosnCumvAlgndMrfRevSVPrev_Rev_M_s15p16;/* PRQA S 3218 */
 
#define MOTPOSNCMP_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */   
 
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
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NvM_RequestResultType: Enumeration of integer in interval [0...5] with enumerators
 *   NVM_REQ_OK (0u)
 *   NVM_REQ_NOT_OK (1u)
 *   NVM_REQ_PENDING (2u)
 *   NVM_REQ_INTEGRITY_FAILED (3u)
 *   NVM_REQ_BLOCK_SKIPPED (4u)
 *   NVM_REQ_NV_INVALIDATED (5u)
 *
 * Array Types:
 * ============
 * MotPosnBackEmfData: Array with 2 element(s) of type UInt16
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
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
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ONE_CNT_U16 = 1u
 * UInt8: D_ONE_CNT_U8 = 1u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   UInt16 *Rte_Pim_MotPosnCmpMtrPosBackEmf(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_MOTPOSNCMP_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */ 

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotPosnCmp_Per2
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
 *   SInt8 Rte_IRead_MotPosnCmp_Per2_AssiMechPolarity_Cnt_s08(void)
 *   Float Rte_IRead_MotPosnCmp_Per2_MotPosnCumvAlgnd_Rev_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MotPosnCmp_Per2_MotPosnCumvAlgndCrf_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_MotPosnCmp_Per2_MotPosnCumvAlgndCrf_Deg_f32(void)
 *   void Rte_IWrite_MotPosnCmp_Per2_MotPosnCumvAlgndMrf_Deg_f32(Float data)
 *   Float *Rte_IWriteRef_MotPosnCmp_Per2_MotPosnCumvAlgndMrf_Deg_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotPosnCmp_Per2
 *********************************************************************************************************************/
     VAR(sint8, AUTOMATIC) 		AssiMechPolarity_Cnt_T_s08;
	 VAR(float32, AUTOMATIC) 	MotAgCumvAlgndMrfRev_Rev_T_f32;
	 VAR(float32, AUTOMATIC) 	MotAgCumvAlgndMrf_Deg_T_f32;
	 VAR(float32, AUTOMATIC) 	MotAgCumvAlgndCrf_Deg_T_f32;
		
	 AssiMechPolarity_Cnt_T_s08= Rte_IRead_MotPosnCmp_Per2_AssiMechPolarity_Cnt_s08(); 
	 MotAgCumvAlgndMrfRev_Rev_T_f32 = Rte_IRead_MotPosnCmp_Per2_MotPosnCumvAlgnd_Rev_f32(); 
	
	 MotAgCumvAlgndMrf_Deg_T_f32 = MotAgCumvAlgndMrfRev_Rev_T_f32* (float32)D_DEGPERREV_MOTDEGPERREV_U16P0;  
	 MotAgCumvAlgndCrf_Deg_T_f32 = MotAgCumvAlgndMrf_Deg_T_f32 * (float32)AssiMechPolarity_Cnt_T_s08;
	 MotAgCumvAlgndMrf_Deg_T_f32= Limit_m(MotAgCumvAlgndMrf_Deg_T_f32, D_MINMOTAG_DEG_F32 , D_MAXMOTAG_DEG_F32);
	 MotAgCumvAlgndCrf_Deg_T_f32= Limit_m(MotAgCumvAlgndCrf_Deg_T_f32, D_MINMOTAG_DEG_F32 , D_MAXMOTAG_DEG_F32); 
	 (void) Rte_IWrite_MotPosnCmp_Per2_MotPosnCumvAlgndCrf_Deg_f32(MotAgCumvAlgndCrf_Deg_T_f32);
	 (void) Rte_IWrite_MotPosnCmp_Per2_MotPosnCumvAlgndMrf_Deg_f32(MotAgCumvAlgndMrf_Deg_T_f32); 
	 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotPosnCmp_Scom_MotPosnCmpBackEmfRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <MotPosnCmpBackEmfRead> of PortPrototype <MotPosnCmp_Scom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void MotPosnCmp_Scom_MotPosnCmpBackEmfRead(UInt16 *MotPosnBackEmfReadData)
#else
 *   void MotPosnCmp_Scom_MotPosnCmpBackEmfRead(MotPosnBackEmfData *MotPosnBackEmfReadData)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Scom_MotPosnCmpBackEmfRead(P2VAR(UInt16, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_VAR) MotPosnBackEmfReadData)
#else
FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Scom_MotPosnCmpBackEmfRead(P2VAR(MotPosnBackEmfData, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_VAR) MotPosnBackEmfReadData)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotPosnCmp_Scom_MotPosnCmpBackEmfRead
 *********************************************************************************************************************/
   VAR(uint16, AUTOMATIC) CalcCRC_Cnt_T_u16;
   CalcCRC_Cnt_T_u16 = Crc_CalculateCRC16( (const uint8 *)Rte_Pim_MotPosnCmpMtrPosBackEmf(), (uint32)D_BEMFSRVCSIZE_CNT_U16, D_BEMFCRCSEED_CNT_U16); /* PRQA S 310 */
   (*MotPosnBackEmfReadData)[D_BEMFIDX_CNT_U16] = *Rte_Pim_MotPosnCmpMtrPosBackEmf();
   (*MotPosnBackEmfReadData)[D_BEMFCRCIDX_CNT_U16] =  CalcCRC_Cnt_T_u16;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotPosnCmp_Scom_MotPosnCmpBackEmfWr
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <MotPosnCmpBackEmfWr> of PortPrototype <MotPosnCmp_Scom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_MotPosnCmpMtrPosBackEmf_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_MotPosnCmpMtrPosBackEmf_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void MotPosnCmp_Scom_MotPosnCmpBackEmfWr(const UInt16 *MotPosnBackEmfWrData, UInt8 *MotPosnCmpBackEmfWrResp)
#else
 *   void MotPosnCmp_Scom_MotPosnCmpBackEmfWr(const MotPosnBackEmfData *MotPosnBackEmfWrData, UInt8 *MotPosnCmpBackEmfWrResp)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Scom_MotPosnCmpBackEmfWr(P2CONST(UInt16, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_DATA) MotPosnBackEmfWrData, P2VAR(UInt8, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_VAR) MotPosnCmpBackEmfWrResp)
#else
FUNC(void, RTE_AP_MOTPOSNCMP_APPL_CODE) MotPosnCmp_Scom_MotPosnCmpBackEmfWr(P2CONST(MotPosnBackEmfData, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_DATA) MotPosnBackEmfWrData, P2VAR(UInt8, AUTOMATIC, RTE_AP_MOTPOSNCMP_APPL_VAR) MotPosnCmpBackEmfWrResp)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotPosnCmp_Scom_MotPosnCmpBackEmfWr
 *********************************************************************************************************************/
 VAR(uint16, AUTOMATIC) CalcCRC_Cnt_T_u16;
 
 CalcCRC_Cnt_T_u16 = Crc_CalculateCRC16( (const uint8 *)MotPosnBackEmfWrData, (uint32)D_BEMFSRVCSIZE_CNT_U16, D_BEMFCRCSEED_CNT_U16); /* PRQA S 310 */
 if(CalcCRC_Cnt_T_u16 == (*MotPosnBackEmfWrData)[D_BEMFCRCIDX_CNT_U16])
	{
     *Rte_Pim_MotPosnCmpMtrPosBackEmf() = (*MotPosnBackEmfWrData)[D_BEMFIDX_CNT_U16];
     (void)Rte_Call_MotPosnCmpMtrPosBackEmf_WriteBlock(NULL_PTR);
	 *MotPosnCmpBackEmfWrResp = D_BEMFCRCPASS_CNT_U08  ;
	}
 else
   {
	  *MotPosnCmpBackEmfWrResp = D_BEMFCRCFAIL_CNT_U08 ;
   }
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_MOTPOSNCMP_APPL_CODE
#include "MemMap.h"  /* PRQA S 5087 */ 


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 
/******************************************************************************
  * Name:        MotPosnCmp_Per1
  * Description: MotPosnCmp periodic processing in the motor control loop
  * Inputs:      see component's DataDict.m file     
  * Outputs:     see component's DataDict.m file 
  * Usage Notes: Called at Motor Control loop rate 
  ****************************************************************************/
FUNC (void, MotPosnCmp_CODE) MotPosnCmp_Per1 (void)
{
	 
	 VAR(sint32, AUTOMATIC) 	DeltaMotCtrlMotAg_RevM_T_s15p16;
	 VAR(uint16, AUTOMATIC) 	MotCtrlMotAgMecl_RevM_T_u0p16;
	 VAR(uint16, AUTOMATIC) 	MotCtrlMotAgElec_RevE_T_u0p16;
	 
	 MotPosnCmp_Read_MtrPosMecl_Rev_u0p16(&MotCtrlMotAgMecl_RevM_T_u0p16);
	 if(MotPosnCmp_MotPosnCmpFirstRunCmpl_Cnt_M_lgc == FALSE)
	 {
		 MotPosnCmp_MotPosnMeclPrev_Rev_M_u0p16 = MotCtrlMotAgMecl_RevM_T_u0p16; 
		 MotPosnCmp_MotPosnCumvAlgndMrfRevSVPrev_Rev_M_s15p16 = (sint32)MotCtrlMotAgMecl_RevM_T_u0p16; 
		 MotPosnCmp_MotPosnCmpFirstRunCmpl_Cnt_M_lgc = TRUE;
	 }
	 else
	 {   /*rollover is intentional*/
		 MotCtrlMotAgElec_RevE_T_u0p16 =  (((uint16)(D_MOTPOLECNT_CNT_U08>>1U) * 
											MotCtrlMotAgMecl_RevM_T_u0p16)  - *Rte_Pim_MotPosnCmpMtrPosBackEmf());
		 DeltaMotCtrlMotAg_RevM_T_s15p16 = (sint32)MotCtrlMotAgMecl_RevM_T_u0p16 - (sint32)MotPosnCmp_MotPosnMeclPrev_Rev_M_u0p16;
		 MotPosnCmp_MotPosnMeclPrev_Rev_M_u0p16 = MotCtrlMotAgMecl_RevM_T_u0p16;
		if (DeltaMotCtrlMotAg_RevM_T_s15p16 > 32768)
		{
			DeltaMotCtrlMotAg_RevM_T_s15p16  =  DeltaMotCtrlMotAg_RevM_T_s15p16 - 65536;
		}
		else if (DeltaMotCtrlMotAg_RevM_T_s15p16 < -32768 )
		{
			DeltaMotCtrlMotAg_RevM_T_s15p16  =  DeltaMotCtrlMotAg_RevM_T_s15p16 + 65536;
		}
		else
		{
			/*** Do nothing***/
		}
		 MotPosnCmp_MotPosnCumvAlgndMrfRevSVPrev_Rev_M_s15p16 += DeltaMotCtrlMotAg_RevM_T_s15p16 ;
		 MotPosnCmp_Write_MotPosnElec_Rev_T_u0p16(MotCtrlMotAgElec_RevE_T_u0p16);
		 /*MotPosnCmp_MotPosnCumvAlgndMrfRevSVPrev_Rev_M_s15p16 uses full range and hence rollover is intentional and no range limiting*/
		 MotPosnCmp_Write_MotPosnCumvAlgnd_Rev_s15p16(MotPosnCmp_MotPosnCumvAlgndMrfRevSVPrev_Rev_M_s15p16);	 
		
	 }
	
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
