/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_HwPwrUpSeq.c
 *     Workspace:  C:/SynergyWorkArea/Working/HwPwrUpSeq/autosar
 *     SW-C Type:  Ap_HwPwrUpSeq
 *  Generated at:  Wed Jun 15 12:47:17 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_HwPwrUpSeq>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/****************************************************************************
* Copyright 2015,2016 Nexteer
* Nexteer Confidential
*
* Module File Name: Ap_HwPwrUpSeq.c
* Module Description: Initial Implementation of FDD 13C V001 (legacy of ES013B)
* Project           : CBD
* Author            : Selva Sengottaiyan
*****************************************************************************
 *  Version Control:
 * Date Created:
 * %version:           1 %
 * %date_modified:     %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/02/15   1       Selva    	     ES-13C Initial Creation												EA3#2970
 * 15/06/15   2       JK             Updated to FDD v002                                                    EA3#8888
 *---------------------------------------------------------------------------------------------------------------------
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_HwPwrUpSeq.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 5087 */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* PRQA S 3218 */
/* MISRA-C:2004 Rule 8.7 [NXTRDEV 8.7.1]: File scope static, is only accessed in one function. */


typedef enum {
	PWRUPPWRDISCSTEPA = 0U,
	PWRUPTMFINIT,
	PWRUPPWRDISCSTEPB,
	PWRUPMTRDRIVERINIT,
	PWRUPWARMINITCOMPLETE,
	PWRUPRUN,
	PWRUPDISABLE
} PowerUpSequenceType;

#define HWPWRUPSEQ_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(PowerUpSequenceType, AP_HWPWRUPSEQ_VAR) HwPwrUpSeq_PowerUpState_Cnt_M_enum;/* PRQA S 3218 */
STATIC 	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) HwPwrUpSeq_StaMdPrev_Cnt_M_enum;/* PRQA S 3218 */
#define HWPWRUPSEQ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


#define HWPWRUPSEQ_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_HWPWRUPSEQ_VAR) HwPwrUpSeq_PwrDiscATestStart_Cnt_M_lgc;/* PRQA S 3218 */
STATIC VAR(boolean, AP_HWPWRUPSEQ_VAR) HwPwrUpSeq_TMFTestStart_Cnt_M_lgc;/* PRQA S 3218 */
STATIC VAR(boolean, AP_HWPWRUPSEQ_VAR) HwPwrUpSeq_PwrDiscBTestStart_Cnt_M_lgc;/* PRQA S 3218 */
STATIC VAR(boolean, AP_HWPWRUPSEQ_VAR) HwPwrUpSeq_MtrDrvr0InitStart_Cnt_M_lgc;/* PRQA S 3218 */
STATIC VAR(boolean, AP_HWPWRUPSEQ_VAR) HwPwrUpSeq_MtrDrvr1InitStart_Cnt_M_lgc;/* PRQA S 3218 */

#define HWPWRUPSEQ_STOP_SEC_VAR_CLEARED_BOOLEAN
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
 *
 * Enumeration Types:
 * ==================
 * StaMd_Users: Enumeration of integer in interval [0...15] with enumerators
 *   STAMD_STOPCTRL (0u)
 *   STAMD_VEHPWRMD (1u)
 *   STAMD_DIAGMGR (2u)
 *   STAMD_PHSDSCNCT (3u)
 *   STAMD_MTRDRVR (4u)
 *   STAMD_TMPRLMON (5u)
 *   STAMD_HWPWUP (6u)
 *   STAMD_MTRPOSDIAG (7u)
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


#define RTE_START_SEC_AP_HWPWRUPSEQ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwPwrUpSeq_Per1
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
 *   Boolean Rte_IRead_HwPwrUpSeq_Per1_MtrDrvr0InitComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_HwPwrUpSeq_Per1_MtrDrvr1InitComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_HwPwrUpSeq_Per1_PwrDiscATestComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_HwPwrUpSeq_Per1_PwrDiscBTestComplete_Cnt_lgc(void)
 *   Boolean Rte_IRead_HwPwrUpSeq_Per1_TMFTestComplete_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HwPwrUpSeq_Per1_MtrDrvr0InitStart_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_HwPwrUpSeq_Per1_MtrDrvr0InitStart_Cnt_lgc(void)
 *   void Rte_IWrite_HwPwrUpSeq_Per1_MtrDrvr1InitStart_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_HwPwrUpSeq_Per1_MtrDrvr1InitStart_Cnt_lgc(void)
 *   void Rte_IWrite_HwPwrUpSeq_Per1_OverVltgMonStart_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_HwPwrUpSeq_Per1_OverVltgMonStart_Cnt_lgc(void)
 *   void Rte_IWrite_HwPwrUpSeq_Per1_PwrDiscATestStart_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_HwPwrUpSeq_Per1_PwrDiscATestStart_Cnt_lgc(void)
 *   void Rte_IWrite_HwPwrUpSeq_Per1_PwrDiscBTestStart_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_HwPwrUpSeq_Per1_PwrDiscBTestStart_Cnt_lgc(void)
 *   void Rte_IWrite_HwPwrUpSeq_Per1_TMFTestStart_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_HwPwrUpSeq_Per1_TMFTestStart_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_MilestoneRqst_WarmInitMilestoneComplete(StaMd_Users user)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_MilestoneRqst_WarmInitMilestoneNotComplete(StaMd_Users user)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HWPWRUPSEQ_APPL_CODE) HwPwrUpSeq_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: HwPwrUpSeq_Per1
 *********************************************************************************************************************/
	VAR(boolean, AUTOMATIC) PwrDiscATestComplete_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TMFTestComplete_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PwrDiscBTestComplete_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MtrDrvr0InitComplete_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MtrDrvr1InitComplete_Cnt_T_lgc;

	if ((Rte_Mode_SystemState_Mode() == RTE_MODE_StaMd_Mode_WARMINIT) &&(HwPwrUpSeq_StaMdPrev_Cnt_M_enum != RTE_MODE_StaMd_Mode_WARMINIT))
	{
		(void) Rte_Call_MilestoneRqst_WarmInitMilestoneNotComplete(STAMD_HWPWUP);
		HwPwrUpSeq_PowerUpState_Cnt_M_enum = PWRUPPWRDISCSTEPA;
		HwPwrUpSeq_MtrDrvr1InitStart_Cnt_M_lgc = FALSE;	
		HwPwrUpSeq_MtrDrvr0InitStart_Cnt_M_lgc = FALSE;
		HwPwrUpSeq_PwrDiscATestStart_Cnt_M_lgc = FALSE;
		HwPwrUpSeq_PwrDiscBTestStart_Cnt_M_lgc = FALSE;
		HwPwrUpSeq_TMFTestStart_Cnt_M_lgc = FALSE;
		
	}
	else if(Rte_Mode_SystemState_Mode() == RTE_MODE_StaMd_Mode_DISABLE)
	{
		HwPwrUpSeq_PowerUpState_Cnt_M_enum = PWRUPDISABLE;
	}
	else
	{
		PwrDiscATestComplete_Cnt_T_lgc = Rte_IRead_HwPwrUpSeq_Per1_PwrDiscATestComplete_Cnt_lgc();
		TMFTestComplete_Cnt_T_lgc = Rte_IRead_HwPwrUpSeq_Per1_TMFTestComplete_Cnt_lgc();
		PwrDiscBTestComplete_Cnt_T_lgc = Rte_IRead_HwPwrUpSeq_Per1_PwrDiscBTestComplete_Cnt_lgc();
		MtrDrvr1InitComplete_Cnt_T_lgc = Rte_IRead_HwPwrUpSeq_Per1_MtrDrvr1InitComplete_Cnt_lgc();
		MtrDrvr0InitComplete_Cnt_T_lgc = Rte_IRead_HwPwrUpSeq_Per1_MtrDrvr0InitComplete_Cnt_lgc();
		
		switch(HwPwrUpSeq_PowerUpState_Cnt_M_enum)
		{
			case PWRUPPWRDISCSTEPA:
				HwPwrUpSeq_PwrDiscATestStart_Cnt_M_lgc = TRUE;

				if((PwrDiscATestComplete_Cnt_T_lgc == TRUE))
				{
					HwPwrUpSeq_PowerUpState_Cnt_M_enum = PWRUPTMFINIT;
				}
				break;
			case PWRUPTMFINIT:
				HwPwrUpSeq_TMFTestStart_Cnt_M_lgc = TRUE;

				if( TMFTestComplete_Cnt_T_lgc == TRUE )
				{
					HwPwrUpSeq_PowerUpState_Cnt_M_enum = PWRUPPWRDISCSTEPB;
				}
				break;
			case PWRUPPWRDISCSTEPB:
				HwPwrUpSeq_PwrDiscBTestStart_Cnt_M_lgc = TRUE;

				if( PwrDiscBTestComplete_Cnt_T_lgc == TRUE )
				{
					HwPwrUpSeq_PowerUpState_Cnt_M_enum = PWRUPMTRDRIVERINIT;
				}
				break;
			case PWRUPMTRDRIVERINIT:
				HwPwrUpSeq_MtrDrvr1InitStart_Cnt_M_lgc = TRUE;
				HwPwrUpSeq_MtrDrvr0InitStart_Cnt_M_lgc = TRUE;

				if(( MtrDrvr1InitComplete_Cnt_T_lgc == TRUE ) && ( MtrDrvr0InitComplete_Cnt_T_lgc == TRUE ))
				{
					HwPwrUpSeq_PowerUpState_Cnt_M_enum = PWRUPWARMINITCOMPLETE;
				}
				break;
			case PWRUPWARMINITCOMPLETE:
				HwPwrUpSeq_PowerUpState_Cnt_M_enum = PWRUPRUN;
				(void) Rte_Call_MilestoneRqst_WarmInitMilestoneComplete(STAMD_HWPWUP);
				break;
			
			case PWRUPRUN:
			case PWRUPDISABLE:
			default:
				/* do nothing */
				break;
		}
	}
	
	HwPwrUpSeq_StaMdPrev_Cnt_M_enum = Rte_Mode_SystemState_Mode();
	
	(void)Rte_IWrite_HwPwrUpSeq_Per1_PwrDiscATestStart_Cnt_lgc(HwPwrUpSeq_PwrDiscATestStart_Cnt_M_lgc);
	(void)Rte_IWrite_HwPwrUpSeq_Per1_TMFTestStart_Cnt_lgc(HwPwrUpSeq_TMFTestStart_Cnt_M_lgc);
	(void)Rte_IWrite_HwPwrUpSeq_Per1_PwrDiscBTestStart_Cnt_lgc(HwPwrUpSeq_PwrDiscBTestStart_Cnt_M_lgc);
	(void)Rte_IWrite_HwPwrUpSeq_Per1_MtrDrvr1InitStart_Cnt_lgc(HwPwrUpSeq_MtrDrvr1InitStart_Cnt_M_lgc);
	(void)Rte_IWrite_HwPwrUpSeq_Per1_MtrDrvr0InitStart_Cnt_lgc(HwPwrUpSeq_MtrDrvr0InitStart_Cnt_M_lgc);
	(void)Rte_IWrite_HwPwrUpSeq_Per1_OverVltgMonStart_Cnt_lgc(HwPwrUpSeq_PwrDiscBTestStart_Cnt_M_lgc);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_HWPWRUPSEQ_APPL_CODE
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
