/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_GenPosTraj.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/GenPosTraj-nzt9hv/GenPosTraj/autosar
 *     SW-C Type:  Ap_GenPosTraj
 *  Generated at:  Sun Sep 23 12:59:15 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_GenPosTraj>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /* Version Control:
 * Date Created:      Tue Dec 20 13:16:01 2011
 * %version:          6 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Mon Sep 16 10:19:36 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 12/20/11   1       VK        Initial Version implementing SF#21 v001											4374
 * 2/21/12	  2       VK		Changes to the math while calculating angle command when in CONSTANT_VEL_STATE  4374
 * 9/20/2012	  3		  SSK		Checkpoints added																6226 
 * 9/25/2012	  4		  SSK		Deleted #define RTE																6226 
 * 9/25/2012	  5		  SSK		Forget to add the member log													6226 
 * 9/16/2013	 6        SSK       Updated for V2 SF#21.Divide by zero is fixed. Name for Static variable's 	
 *										updated.					                                                10102
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_GenPosTraj.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_GenPosTraj_Cfg.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include <math.h>


#define D_MINTRGTACCEL_HWDEGPSECSQR_F32		0.125F
#define D_HWANGLECMD_HWDEG_F32      1440.11F

typedef enum Command_State {
               WAITING_STATE = 0,
               ACCELERATION_STATE = 1,
               CONSTANT_VEL_STATE = 2, 
               DECELERATION_STATE = 3,
			   HOLD_STATE = 4
             } CMDSTATE_Enum; 

#define GENPOSTRAJ_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC) GenPosTraj_TargetAngle_HwDeg_M_f32;
STATIC VAR(float32, AUTOMATIC) GenPosTraj_TargetVelocity_HwDegpSec_M_f32;
STATIC VAR(float32, AUTOMATIC) GenPosTraj_TargetAcceleration_HwDegpSecSqr_M_f32;
STATIC VAR(float32, AUTOMATIC) GenPosTraj_TargetAngleInitial_HwDeg_M_f32;
STATIC VAR(float32, AUTOMATIC) GenPosTraj_TargetVelocityInitial_HwDegpSec_M_f32;
STATIC VAR(float32, AUTOMATIC) GenPosTraj_TargetAccelerationInitial_HwDegpSecSqr_M_f32;
STATIC VAR(float32, AUTOMATIC) GenPosTraj_HwPosInitial_HwDeg_M_f32;
STATIC VAR(float32, AUTOMATIC) GenPosTraj_HwAngleOffsetIn_HwDeg_M_f32;
STATIC VAR(float32, AUTOMATIC) GenPosTraj_StateTime_Sec_M_f32;
#define GENPOSTRAJ_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define GENPOSTRAJ_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(CMDSTATE_Enum, AUTOMATIC) GenPosTraj_CmdState_Cnt_M_Enum;
#define GENPOSTRAJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


#define GENPOSTRAJ_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AUTOMATIC) GenPosTraj_CalculateFlag_Cnt_M_lgc;
#define GENPOSTRAJ_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

STATIC INLINE FUNC(void, AP_GENPOSTRAJ_APPL_CODE) InitializeVariables(P2VAR(float32,AUTOMATIC,AUTOMATIC) pHwPosOffset_HwDeg_T_f32,
															   		  P2VAR(float32,AUTOMATIC,AUTOMATIC) pSignDeltaTrgtAngle_Cnt_T_f32,
															   		  P2VAR(float32,AUTOMATIC,AUTOMATIC) pDeltaAccel_Sec_T_f32,
															   		  P2VAR(float32,AUTOMATIC,AUTOMATIC) pDeltaVelocity_Sec_T_f32,
															   	 	  P2VAR(float32,AUTOMATIC,AUTOMATIC) pMaxAccel_HwDegpSecSqr_T_f32,
															   		  P2VAR(float32,AUTOMATIC,AUTOMATIC) pMaxVelocity_HwDegpSec_T_f32);

STATIC INLINE FUNC(float32, AP_GENPOSTRAJ_APPL_CODE) GenerateSignal(CONST(float32, AUTOMATIC) HwPosOffset_HwDeg_T_f32,
															 		CONST(float32, AUTOMATIC) SignDeltaTrgtAngle_Cnt_T_f32,
														     		CONST(float32, AUTOMATIC) DeltaAccel_Sec_T_f32,
														     		CONST(float32, AUTOMATIC) DeltaVelocity_Sec_T_f32,
															 		CONST(float32, AUTOMATIC) MaxAccel_HwDegpSecSqr_T_f32,
															 		CONST(float32, AUTOMATIC) MaxVelocity_HwDegpSec_T_f32,
														     		VAR(float32, AUTOMATIC) HwPosition_HwDeg_T_f32,
														     		VAR(boolean, AUTOMATIC) CalculateFlag_Cnt_T_lgc);

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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_GENPOSTRAJ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GenPosTraj_Per1
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
 *   Float Rte_IRead_GenPosTraj_Per1_HwPosition_HwDeg_f32(void)
 *   Boolean Rte_IRead_GenPosTraj_Per1_PosTrajEnable_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_GenPosTraj_Per1_PosTrajHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_GenPosTraj_Per1_PosTrajHwAngle_HwDeg_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_GENPOSTRAJ_APPL_CODE) GenPosTraj_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GenPosTraj_Per1
 *********************************************************************************************************************/



VAR(float32, AUTOMATIC) HwPosition_HwDeg_T_f32;
VAR(float32, AUTOMATIC) HwAngleCmd_HwDeg_T_f32;
VAR(float32, AUTOMATIC) HwPosOffset_HwDeg_T_f32;
VAR(float32, AUTOMATIC) SignDeltaTrgtAngle_Cnt_T_f32;
VAR(float32, AUTOMATIC) DeltaAccel_Sec_T_f32;
VAR(float32, AUTOMATIC) DeltaVelocity_Sec_T_f32;
VAR(float32, AUTOMATIC) MaxAccel_HwDegpSecSqr_T_f32;
VAR(float32, AUTOMATIC) MaxVelocity_HwDegpSec_T_f32;
VAR(boolean, AUTOMATIC) CalculateFlag_Cnt_T_lgc;

/* Configurable Start of Runnable Checkpoint */
Rte_Call_GenPosTraj_Per1_CP0_CheckpointReached();

/* Read input signals */
HwPosition_HwDeg_T_f32 = Rte_IRead_GenPosTraj_Per1_HwPosition_HwDeg_f32();
CalculateFlag_Cnt_T_lgc = Rte_IRead_GenPosTraj_Per1_PosTrajEnable_Cnt_lgc();

/* Capture inputs on the raising edge */
if((GenPosTraj_CalculateFlag_Cnt_M_lgc == FALSE ) && (CalculateFlag_Cnt_T_lgc==TRUE))
{
	GenPosTraj_HwPosInitial_HwDeg_M_f32 = HwPosition_HwDeg_T_f32;
	GenPosTraj_TargetAngleInitial_HwDeg_M_f32 = GenPosTraj_TargetAngle_HwDeg_M_f32;
	GenPosTraj_TargetVelocityInitial_HwDegpSec_M_f32 = GenPosTraj_TargetVelocity_HwDegpSec_M_f32;
	GenPosTraj_TargetAccelerationInitial_HwDegpSecSqr_M_f32 =	GenPosTraj_TargetAcceleration_HwDegpSecSqr_M_f32;
}

/* Handle local functions */
InitializeVariables(&HwPosOffset_HwDeg_T_f32, &SignDeltaTrgtAngle_Cnt_T_f32, &DeltaAccel_Sec_T_f32, &DeltaVelocity_Sec_T_f32,
					&MaxAccel_HwDegpSecSqr_T_f32, &MaxVelocity_HwDegpSec_T_f32);

HwAngleCmd_HwDeg_T_f32 = GenerateSignal(HwPosOffset_HwDeg_T_f32, SignDeltaTrgtAngle_Cnt_T_f32, DeltaAccel_Sec_T_f32, DeltaVelocity_Sec_T_f32,
										MaxAccel_HwDegpSecSqr_T_f32, MaxVelocity_HwDegpSec_T_f32, HwPosition_HwDeg_T_f32, CalculateFlag_Cnt_T_lgc);

/* Update Module Level Variables */
GenPosTraj_CalculateFlag_Cnt_M_lgc = CalculateFlag_Cnt_T_lgc;

/* Update Module Outputs */
Rte_IWrite_GenPosTraj_Per1_PosTrajHwAngle_HwDeg_f32(HwAngleCmd_HwDeg_T_f32);

/* Configurable End of Runnable Checkpoint */
Rte_Call_GenPosTraj_Per1_CP1_CheckpointReached();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GenPosTraj_SCom_SetInputParam
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetInputParam> of PortPrototype <GenPosTraj_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GenPosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_GENPOSTRAJ_APPL_CODE) GenPosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GenPosTraj_SCom_SetInputParam
 *********************************************************************************************************************/
GenPosTraj_TargetAngle_HwDeg_M_f32 = PosServHwAngle_HwDeg_f32;
GenPosTraj_TargetVelocity_HwDegpSec_M_f32 = TargetVelocity_HwDegpSec_f32;
GenPosTraj_TargetAcceleration_HwDegpSecSqr_M_f32 = TargetAcceleration_HwDegpSecSqr_f32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_GENPOSTRAJ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define RTE_START_SEC_AP_GENPOSTRAJ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */
/* Local Functions */

/* InitializeVariables */
STATIC INLINE FUNC(void, AP_GENPOSTRAJ_APPL_CODE) InitializeVariables(P2VAR(float32,AUTOMATIC,AUTOMATIC) pHwPosOffset_HwDeg_T_f32,
																		   P2VAR(float32,AUTOMATIC,AUTOMATIC) pSignDeltaTrgtAngle_Cnt_T_f32,
																	       P2VAR(float32,AUTOMATIC,AUTOMATIC) pDeltaAccel_Sec_T_f32,
																	       P2VAR(float32,AUTOMATIC,AUTOMATIC) pDeltaVelocity_Sec_T_f32,
																	       P2VAR(float32,AUTOMATIC,AUTOMATIC) pMaxAccel_HwDegpSecSqr_T_f32,
																	       P2VAR(float32,AUTOMATIC,AUTOMATIC) pMaxVelocity_HwDegpSec_T_f32)
{
	VAR(float32, AUTOMATIC) HwPosFinal_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) MaxVelocityDesired_HwDegpSec_T_f32;
	VAR(float32, AUTOMATIC) MaxAccel_HwDegpSecSqr_T_f32;
	VAR(float32, AUTOMATIC) AbsDeltaTrgtAngle_HwDeg_T_f32;
	VAR(float32, AUTOMATIC) DesiredTrgtAccel_HwDeg_T_f32;

	/* Limit the captured inputs on rising edge */
	HwPosFinal_HwDeg_T_f32 = Limit_m(GenPosTraj_TargetAngleInitial_HwDeg_M_f32, -k_PosTrajMaxAngle_HwDeg_f32, k_PosTrajMaxAngle_HwDeg_f32);
	MaxVelocityDesired_HwDegpSec_T_f32 = Limit_m(GenPosTraj_TargetVelocityInitial_HwDegpSec_M_f32, D_ONE_ULS_F32, k_PosTrajMaxVelocity_HwDegpSec_f32);
	MaxAccel_HwDegpSecSqr_T_f32 = Limit_m(GenPosTraj_TargetAccelerationInitial_HwDegpSecSqr_M_f32, D_MINTRGTACCEL_HWDEGPSECSQR_F32, k_PosTrajMaxAccel_HwDegpSecSqr_f32);
	AbsDeltaTrgtAngle_HwDeg_T_f32 = Abs_f32_m(HwPosFinal_HwDeg_T_f32 - GenPosTraj_HwPosInitial_HwDeg_M_f32);
	(*pSignDeltaTrgtAngle_Cnt_T_f32) = (float32)(Sign_f32_m(HwPosFinal_HwDeg_T_f32 - GenPosTraj_HwPosInitial_HwDeg_M_f32));

	DesiredTrgtAccel_HwDeg_T_f32 = ((MaxVelocityDesired_HwDegpSec_T_f32 * MaxVelocityDesired_HwDegpSec_T_f32)/ MaxAccel_HwDegpSecSqr_T_f32)/ 2.0F;

	if ((AbsDeltaTrgtAngle_HwDeg_T_f32/ 2.0F) < DesiredTrgtAccel_HwDeg_T_f32)
	{
		(*pDeltaAccel_Sec_T_f32) = sqrtf(AbsDeltaTrgtAngle_HwDeg_T_f32/ MaxAccel_HwDegpSecSqr_T_f32);
		(*pDeltaVelocity_Sec_T_f32) = D_ZERO_ULS_F32;
		(*pMaxVelocity_HwDegpSec_T_f32) = (*pDeltaAccel_Sec_T_f32) * MaxAccel_HwDegpSecSqr_T_f32;
	
	}
	else
	{
		(*pDeltaAccel_Sec_T_f32) = MaxVelocityDesired_HwDegpSec_T_f32/ MaxAccel_HwDegpSecSqr_T_f32;
		(*pDeltaVelocity_Sec_T_f32) = (AbsDeltaTrgtAngle_HwDeg_T_f32 - ((MaxVelocityDesired_HwDegpSec_T_f32 * MaxVelocityDesired_HwDegpSec_T_f32)/ MaxAccel_HwDegpSecSqr_T_f32))/ MaxVelocityDesired_HwDegpSec_T_f32;
		(*pMaxVelocity_HwDegpSec_T_f32) = MaxVelocityDesired_HwDegpSec_T_f32;
	}

	(*pHwPosOffset_HwDeg_T_f32) = GenPosTraj_HwPosInitial_HwDeg_M_f32;
	(*pMaxAccel_HwDegpSecSqr_T_f32) = MaxAccel_HwDegpSecSqr_T_f32;

}
/* End of InitializeVariables */

/* GenerateSignal */
STATIC INLINE FUNC(float32, AP_GENPOSTRAJ_APPL_CODE) GenerateSignal(CONST(float32, AUTOMATIC) HwPosOffset_HwDeg_T_f32,
																	     CONST(float32, AUTOMATIC) SignDeltaTrgtAngle_Cnt_T_f32,
																	     CONST(float32, AUTOMATIC) DeltaAccel_Sec_T_f32,
																	     CONST(float32, AUTOMATIC) DeltaVelocity_Sec_T_f32,
																	     CONST(float32, AUTOMATIC) MaxAccel_HwDegpSecSqr_T_f32,
																	     CONST(float32, AUTOMATIC) MaxVelocity_HwDegpSec_T_f32,
																	     VAR(float32, AUTOMATIC) HwPosition_HwDeg_T_f32,
																	     VAR(boolean, AUTOMATIC) CalculateFlag_Cnt_T_lgc)
{

VAR(CMDSTATE_Enum, AUTOMATIC) CmdState_Cnt_T_Enum;
VAR(boolean, AUTOMATIC) bDone_Cnt_T_lgc;
VAR(float32, AUTOMATIC) StateTime_Sec_T_f32;
VAR(float32, AUTOMATIC) HwAngleOffset_HwDeg_T_f32;
VAR(float32, AUTOMATIC) HwAngleCmd_HwDeg_T_f32;

/* Check if calculate flag is enabled then use the previous commanded state */
if (CalculateFlag_Cnt_T_lgc == TRUE)
{
	CmdState_Cnt_T_Enum = GenPosTraj_CmdState_Cnt_M_Enum;
}
else
{
	CmdState_Cnt_T_Enum = WAITING_STATE;
}
switch(CmdState_Cnt_T_Enum)
	{
	case WAITING_STATE: /* State 0 */

		if (CalculateFlag_Cnt_T_lgc == TRUE)
		{
			CmdState_Cnt_T_Enum = ACCELERATION_STATE;
		}
		else
		{
			CmdState_Cnt_T_Enum = WAITING_STATE;
		}

		StateTime_Sec_T_f32 = D_ZERO_ULS_F32;
		HwAngleCmd_HwDeg_T_f32 = HwPosition_HwDeg_T_f32;
		HwAngleOffset_HwDeg_T_f32 = HwPosOffset_HwDeg_T_f32;
		break;

	case ACCELERATION_STATE: /* State 1 */

		HwAngleCmd_HwDeg_T_f32 = GenPosTraj_HwAngleOffsetIn_HwDeg_M_f32 + (SignDeltaTrgtAngle_Cnt_T_f32 * (MaxAccel_HwDegpSecSqr_T_f32/ 2.0F) * (GenPosTraj_StateTime_Sec_M_f32 * GenPosTraj_StateTime_Sec_M_f32));
		if (GenPosTraj_StateTime_Sec_M_f32 >= DeltaAccel_Sec_T_f32)
		{	
			bDone_Cnt_T_lgc = TRUE;
		}
		else
		{
			bDone_Cnt_T_lgc = FALSE;
		}

		if (bDone_Cnt_T_lgc == TRUE)
		{
			HwAngleOffset_HwDeg_T_f32 = HwAngleCmd_HwDeg_T_f32;
			CmdState_Cnt_T_Enum = CONSTANT_VEL_STATE;
			StateTime_Sec_T_f32 = D_ZERO_ULS_F32;
		}
		else
		{
			HwAngleOffset_HwDeg_T_f32 = GenPosTraj_HwAngleOffsetIn_HwDeg_M_f32;
			CmdState_Cnt_T_Enum = ACCELERATION_STATE;
			StateTime_Sec_T_f32 = GenPosTraj_StateTime_Sec_M_f32 + D_2MS_SEC_F32;
		}
		break;

	case CONSTANT_VEL_STATE: /* State 2 */

		HwAngleCmd_HwDeg_T_f32 = GenPosTraj_HwAngleOffsetIn_HwDeg_M_f32 + (SignDeltaTrgtAngle_Cnt_T_f32 * MaxVelocity_HwDegpSec_T_f32 * GenPosTraj_StateTime_Sec_M_f32);
		if (GenPosTraj_StateTime_Sec_M_f32 >= DeltaVelocity_Sec_T_f32)
		{	
			bDone_Cnt_T_lgc = TRUE;
		}
		else
		{
			bDone_Cnt_T_lgc = FALSE;
		}

		if (bDone_Cnt_T_lgc == TRUE)
		{
			HwAngleOffset_HwDeg_T_f32 = HwAngleCmd_HwDeg_T_f32;
			CmdState_Cnt_T_Enum = DECELERATION_STATE;
			StateTime_Sec_T_f32 = D_ZERO_ULS_F32;
		}
		else
		{
			HwAngleOffset_HwDeg_T_f32 = GenPosTraj_HwAngleOffsetIn_HwDeg_M_f32;
			CmdState_Cnt_T_Enum = CONSTANT_VEL_STATE;
			StateTime_Sec_T_f32 = GenPosTraj_StateTime_Sec_M_f32 + D_2MS_SEC_F32;
		}
		break;

	case DECELERATION_STATE: /* State 3 */

		HwAngleCmd_HwDeg_T_f32 = GenPosTraj_HwAngleOffsetIn_HwDeg_M_f32 + (SignDeltaTrgtAngle_Cnt_T_f32 * ((MaxVelocity_HwDegpSec_T_f32 * GenPosTraj_StateTime_Sec_M_f32) - ((MaxAccel_HwDegpSecSqr_T_f32/ 2.0F) * (GenPosTraj_StateTime_Sec_M_f32 * GenPosTraj_StateTime_Sec_M_f32))));
		if (GenPosTraj_StateTime_Sec_M_f32 >= DeltaAccel_Sec_T_f32)
		{	
			bDone_Cnt_T_lgc = TRUE;
		}
		else
		{
			bDone_Cnt_T_lgc = FALSE;
		}

		if (bDone_Cnt_T_lgc == TRUE)
		{
			HwAngleOffset_HwDeg_T_f32 = HwAngleCmd_HwDeg_T_f32;
			CmdState_Cnt_T_Enum = HOLD_STATE;
			StateTime_Sec_T_f32 = D_ZERO_ULS_F32;
		}
		else
		{
			HwAngleOffset_HwDeg_T_f32 = GenPosTraj_HwAngleOffsetIn_HwDeg_M_f32;
			CmdState_Cnt_T_Enum = DECELERATION_STATE;
			StateTime_Sec_T_f32 = GenPosTraj_StateTime_Sec_M_f32 + D_2MS_SEC_F32;
		}
		break;

	case HOLD_STATE: /* State 4 */

		HwAngleCmd_HwDeg_T_f32 = GenPosTraj_HwAngleOffsetIn_HwDeg_M_f32;
		HwAngleOffset_HwDeg_T_f32 = GenPosTraj_HwAngleOffsetIn_HwDeg_M_f32;
		CmdState_Cnt_T_Enum = HOLD_STATE;
		StateTime_Sec_T_f32 = D_ZERO_ULS_F32;
		break;

	default:
	/* Do Nothing */
	break;
	
	} /* End of switch */

/* Copy temporary to module for the next run */
GenPosTraj_CmdState_Cnt_M_Enum = CmdState_Cnt_T_Enum;
GenPosTraj_HwAngleOffsetIn_HwDeg_M_f32 = HwAngleOffset_HwDeg_T_f32;
GenPosTraj_StateTime_Sec_M_f32 = StateTime_Sec_T_f32;

HwAngleCmd_HwDeg_T_f32 = Limit_m(HwAngleCmd_HwDeg_T_f32, -D_HWANGLECMD_HWDEG_F32, D_HWANGLECMD_HWDEG_F32);
return(HwAngleCmd_HwDeg_T_f32);

}

#define RTE_STOP_SEC_AP_GENPOSTRAJ_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
