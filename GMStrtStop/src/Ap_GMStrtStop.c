/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_GMStrtStop.c
 *     Workspace:  C:/Synergy_EA3/working/GMStrtStop/autosar
 *     SW-C Type:  Ap_GMStrtStop
 *  Generated at:  Fri Jun  3 11:21:00 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_GMStrtStop>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /******************************************************************************
 * Copyright 2014 - 2016 Nexteer
 * Nexteer Confidential
 *
 * Module File Name		: Ap_GMStrtStop.c
 * Module Description	: Implementation of CF12A
 * Project           	: CBD
 * Author            	: Jared Julien
 ******************************************************************************
 * Version Control:
 * Date Created:      Thu Apr 24 08:34:17 2014
 * %version:          4 %
 * %derived_by:       nz4qtt %
 *-------------------------------------------------------------------------------------------------------------------
 * Date        Rev    Author     Change Description                                                          SCR #
 * -------   -------  --------   ------------------------------------------------------------------------  ----------
 * 04/24/14    1      Jared      Initial component creation based upon C1xx System Spec
 * 05/16/16    2      Krishna    Update CF-12 component to match with FDD v002.								EA3#8327
 * 06/03/16    3      Krishna    Fix issues found with FDD during peer reviews 								EA3#8612
 * 08/05/16    4      Krishna    Fix for anomaly EA3#9961					 								EA3#10147
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_GMStrtStop.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "SystemTime.h"

/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */

/* MISRA-C:2004 Rule 19.1: Required for AutoSAR compliance so deviation is taken. : PRQA S 5087:  */

/* -----[ Constant Definitions ]------------------------------------------------------------------------------------ */
#define D_SSSLEWLOWRLIM_UlspS_F32	0.1F
#define D_SSSLEWUPPRLIM_UlspS_F32	500.0F
#define D_SSSCALELOWRLIM_Uls_F32	0.0F
#define D_SSSCALEUPPRLIM_Uls_F32	1.0F
#define D_APASTNORM_CNT_U08 		2U

/* -----[ Variable Declarations ]----------------------------------------------------------------------------------- */
#define STRTSTOP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(SS_State_enum, AP_GMSTRTSTOP_VAR) StrtStop_StOpMode_Cnt_M_enum;				/* PRQA S 3218 */
STATIC VAR(SS_State_enum, AP_GMSTRTSTOP_VAR) StrtStop_StOpModePrev_Cnt_M_enum;			/* PRQA S 3218 */
STATIC VAR(SS_State_enum, AP_GMSTRTSTOP_VAR) StrtStop_StOpModePrevPrev_Cnt_M_enum;		/* PRQA S 3218 */
#define STRTSTOP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define STRTSTOP_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, AP_GMSTRTSTOP_VAR) StrtStop_StopModeTimer1_mS_M_u32;					/* PRQA S 3218 */
STATIC VAR(uint32, AP_GMSTRTSTOP_VAR) StrtStop_StopModeTimer2_mS_M_u32;					/* PRQA S 3218 */
STATIC VAR(float32, AP_GMSTRTSTOP_VAR) StrtStop_SSSlewRatePrev_UlspS_M_f32;				/* PRQA S 3218 */
STATIC VAR(float32, AP_GMSTRTSTOP_VAR) StrtStop_SSScale_Uls_M_f32;						/* PRQA S 3218 */
#define STRTSTOP_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

/* -----[ Local Function Declarations ]---------------------------------------------------------------------------- */
STATIC FUNC(float32, AP_GMSTRTSTOP_VAR) SlewRateCalc(void);
STATIC FUNC(void, AP_GMSTRTSTOP_VAR) PreviousStCalc(void);

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
 * Enumeration Types:
 * ==================
 * APA_State_enum: Enumeration of integer in interval [0...4] with enumerators
 *   APA_TempInhibit (0u)
 *   APA_AvailCntrl (1u)
 *   APA_Active (2u)
 *   APA_PermanentlyFailed (3u)
 *   APA_ManufacturingDisable (4u)
 * SS_State_enum: Enumeration of integer in interval [0...5] with enumerators
 *   SS_Normal (0u)
 *   SS_Intermediate1 (1u)
 *   SS_Stop (2u)
 *   SS_Intermediate2 (3u)
 *   SS_Fault (4u)
 *   SS_Disable (5u)
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
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082
 * Float: D_MSECPERSEC_ULS_F32 = 1000
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_GMSTRTSTOP_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StrtStop_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_GMSTRTSTOP_APPL_CODE) StrtStop_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StrtStop_Init1
 *********************************************************************************************************************/

	StrtStop_SSScale_Uls_M_f32	= D_ONE_ULS_F32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StrtStop_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <WARMINIT, DISABLE, OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   APA_State_enum Rte_IRead_StrtStop_Per1_APAState_State_enum(void)
 *   Float Rte_IRead_StrtStop_Per1_EngSpd_Rpm_f32(void)
 *   Float Rte_IRead_StrtStop_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Float Rte_IRead_StrtStop_Per1_HwTorque_HwNm_f32(void)
 *   Boolean Rte_IRead_StrtStop_Per1_SS12VFault_Cnt_lgc(void)
 *   Float Rte_IRead_StrtStop_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_StrtStop_Per1_SSScale_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_StrtStop_Per1_SSScale_Uls_f32(void)
 *   void Rte_IWrite_StrtStop_Per1_SSSlew_UlspS_f32(Float data)
 *   Float *Rte_IWriteRef_StrtStop_Per1_SSSlew_UlspS_f32(void)
 *   void Rte_IWrite_StrtStop_Per1_SSState_State_enum(SS_State_enum data)
 *   SS_State_enum *Rte_IWriteRef_StrtStop_Per1_SSState_State_enum(void)
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_GMSTRTSTOP_APPL_CODE) StrtStop_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StrtStop_Per1
 *********************************************************************************************************************/
	VAR(uint8, AUTOMATIC) APAState_State_T_enum;

	VAR(boolean, AUTOMATIC) SS12VFault_Cnt_T_lgc;

	VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
	VAR(float32, AUTOMATIC) EngSpd_Rpm_T_f32;
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) AbsHwTorque_HwNm_T_f32;
	VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32;
	VAR(float32, AUTOMATIC) AbsHandwheelVelocity_HwDegpS_T_f32;
	VAR(float32, AUTOMATIC) SSSlewRate_UlspS_T_f32;
	
	VAR(uint32, AUTOMATIC) ElapsedTime1_mS_T_u32;
	VAR(uint32, AUTOMATIC) ElapsedTime2_mS_T_u32;
	
	
	/* Read inputs to local copies */
	APAState_State_T_enum				= Rte_IRead_StrtStop_Per1_APAState_State_enum();				/* REQ: CF12A #218 I */
	EngSpd_Rpm_T_f32					= Rte_IRead_StrtStop_Per1_EngSpd_Rpm_f32();						/* REQ: CF12A #037 I */
	HandwheelVelocity_HwRadpS_T_f32		= Rte_IRead_StrtStop_Per1_HandwheelVelocity_HwRadpS_f32();		/* REQ: CF12A #032 I */
	HwTorque_HwNm_T_f32					= Rte_IRead_StrtStop_Per1_HwTorque_HwNm_f32();					/* REQ: CF12A #009 I */
	SS12VFault_Cnt_T_lgc				= Rte_IRead_StrtStop_Per1_SS12VFault_Cnt_lgc();					/* REQ: CF12A #033 I */
	VehicleSpeed_Kph_T_f32				= Rte_IRead_StrtStop_Per1_VehicleSpeed_Kph_f32();				/* REQ: CF12A #036 I */
	
	/* Calculate Absolute values  */
	AbsHwTorque_HwNm_T_f32 				= Abs_f32_m(HwTorque_HwNm_T_f32);
	AbsHandwheelVelocity_HwDegpS_T_f32 	= Abs_f32_m(HandwheelVelocity_HwRadpS_T_f32 * D_180OVRPI_ULS_F32);
	
	/* Start of Current State Determination */
	/* REQ: CF12A #086 I */ /* REQ: CF12A #182 I */
	/* REQ: CF12A #114 I */ 
	if(k_AlgEnable_Cnt_lgc == FALSE)
	{
		StrtStop_StOpMode_Cnt_M_enum 	= SS_Disable;
		StrtStop_SSScale_Uls_M_f32		= D_ONE_ULS_F32;
	}
	/* ENDREQ: CF12A #086 */ /* ENDREQ: CF12A #182 */
	
	/* REQ: CF12A #066 I */ /* REQ: CF12A #166 I */ /* REQ: CF12A #167 I */ /* REQ: CF12A #182 I */
	else 
	{
		/* REQ: CF12A #086 I */ /* REQ: CF12A #062 I */ /* REQ: CF12A #195 I */
		if (SS12VFault_Cnt_T_lgc == TRUE)
		{
			StrtStop_StOpMode_Cnt_M_enum = SS_Fault;
			StrtStop_SSScale_Uls_M_f32	 = D_ONE_ULS_F32;
		}
		/* ENDREQ: CF12A #086 */ /* ENDREQ: CF12A #062 */ /* ENDREQ: CF12A #195 */
		
		/* REQ: CF12A #062 I */ /* REQ: CF12A #195 I */ /* REQ: CF12A #166 I */
		else
		{
			switch (StrtStop_StOpMode_Cnt_M_enum)
			{
				/* REQ: CF12A #086 I */ /* REQ: CF12A #143 I */ /* REQ: CF12A #186 I */ /* REQ: CF12A #146 I */ /* REQ: CF12A #153 I */ /* REQ: CF12A #160 I */
				case SS_Normal :
				{
					/* REQ: CF12A #087 I */ /* REQ: CF12A #143 I */ /* REQ: CF12A #092 I */
					if ((EngSpd_Rpm_T_f32 <= k_Mode1EngTransThresh_Rpm_f32) &&
						(VehicleSpeed_Kph_T_f32 <= k_Mode1VehSpdTransThresh_Kph_f32))
					{
						GetSystemTime_mS_u32(&StrtStop_StopModeTimer1_mS_M_u32);
						StrtStop_StOpMode_Cnt_M_enum 	= SS_Intermediate1;
						StrtStop_SSScale_Uls_M_f32	 	= k_Mode1AssistDD_Uls_f32;
					}
				}
				break;
				/* ENDREQ: CF12A #086 */ /* ENDREQ: CF12A #143 */ /* ENDREQ: CF12A #186 */ /* ENDREQ: CF12A #146 */ /* ENDREQ: CF12A #153 */ /* ENDREQ: CF12A #160 */
				
				/* REQ: CF12A #086 I */ /* REQ: CF12A #143 I */ /* REQ: CF12A #198 I */ /* REQ: CF12A #146 I */ /* REQ: CF12A #149 I */ /* REQ: CF12A #094 I */
				case SS_Intermediate1 :
				{
					DtrmnElapsedTime_mS_u32(StrtStop_StopModeTimer1_mS_M_u32, &ElapsedTime1_mS_T_u32);
					/* REQ: CF12A #146 I */
					if (EngSpd_Rpm_T_f32 > k_NormalModeEngTransThresh_Rpm_f32) 
					{
						StrtStop_StOpMode_Cnt_M_enum	= SS_Normal;
						StrtStop_SSScale_Uls_M_f32	 	= D_ONE_ULS_F32;
					}
					/* REQ: CF12A #095 I */ /* REQ: CF12A #096 I */ /* REQ: CF12A #097 I */ /* REQ: CF12A #098 I */ /* REQ: CF12A #149 I */ /* REQ: CF12A #151 I */
					else if ( (VehicleSpeed_Kph_T_f32 <= k_StopMode1VehSpdTransThres_Kph_f32) &&
							  (AbsHandwheelVelocity_HwDegpS_T_f32 <= k_StopMode1HwVelTransThresh_HwDegpS_f32) &&
							  (AbsHwTorque_HwNm_T_f32 <= k_StopMode1HwTrqTransThresh_HwNm_f32) &&
							  (ElapsedTime1_mS_T_u32 >= ((uint32)k_StopMode1Timer_Sec_u16 * (uint32)D_MSECPERSEC_ULS_F32)) )
					{
						StrtStop_StOpMode_Cnt_M_enum 	= SS_Stop;
						StrtStop_SSScale_Uls_M_f32	 	= k_StopModeAssistDD_Uls_f32;
					}
					else
					{
						/* Remain in SS_Intermediate1 state */
					}
				}
				break;
				/* ENDREQ: CF12A #086 */ /* ENDREQ: CF12A #143 */ /* ENDREQ: CF12A #198 */ /* ENDREQ: CF12A #146 */ /* ENDREQ: CF12A #149 */ /* ENDREQ: CF12A #094 */
			
				/* REQ: CF12A #086 I */ /* REQ: CF12A #149 I */ /* REQ: CF12A #150 I */ /* REQ: CF12A #153 I */ /* REQ: CF12A #155 I */ /* REQ: CF12A #161 I */ /* REQ: CF12A #100 I */
				case SS_Stop :
				{
					/* REQ: CF12A #153 I */
					if (EngSpd_Rpm_T_f32 > k_NormalModeEngTransThresh_Rpm_f32)
					{
						StrtStop_StOpMode_Cnt_M_enum	= SS_Normal;
						StrtStop_SSScale_Uls_M_f32		= D_ONE_ULS_F32;
					}
					/* REQ: CF12A #102 I */ /* REQ: CF12A #155 I */
					else if (VehicleSpeed_Kph_T_f32 > k_Mode2VehSpdTransThresh_Kph_f32)
					{
						GetSystemTime_mS_u32(&StrtStop_StopModeTimer2_mS_M_u32);
						StrtStop_StOpMode_Cnt_M_enum 	= SS_Intermediate2;
						StrtStop_SSScale_Uls_M_f32		= k_Mode2AssistDD_Uls_f32;
					}
					else
					{
						/* Remain in SS_Stop state */
					}
				}
				break;
				/* ENDREQ: CF12A #086 */ /* ENDREQ: CF12A #149 */ /* ENDREQ: CF12A #150 */ /* ENDREQ: CF12A #153 */ /* ENDREQ: CF12A #155 */ /* ENDREQ: CF12A #161 */ /* ENDREQ: CF12A #100 */
				
				/* REQ: CF12A #086 I */ /* REQ: CF12A #155 I */ /* REQ: CF12A #156 I */ /* REQ: CF12A #160 I */ /* REQ: CF12A #161 I */ /* REQ: CF12A #104 I */
				case SS_Intermediate2 :
				{
					DtrmnElapsedTime_mS_u32(StrtStop_StopModeTimer2_mS_M_u32, &ElapsedTime2_mS_T_u32);
					/* REQ: CF12A #110 I */ /* REQ: CF12A #111 I */ /* REQ: CF12A #160 I */
					if ( (VehicleSpeed_Kph_T_f32 >= k_NormalModeVehSpdTransThresh_Kph_f32) || 
						 (EngSpd_Rpm_T_f32 > k_NormalModeEngTransThresh_Rpm_f32) )
					{
						StrtStop_StOpMode_Cnt_M_enum 	= SS_Normal;
						StrtStop_SSScale_Uls_M_f32		= D_ONE_ULS_F32;
					}
					/* REQ: CF12A #105 I */ /* REQ: CF12A #106 I */ /* REQ: CF12A #107 I */ /* REQ: CF12A #108 I */ /* REQ: CF12A #161 I */ /* REQ: CF12A #162 I */
					else if ( (VehicleSpeed_Kph_T_f32 <= k_StopMode2VehSpdTransThresh_Kph_f32) &&
							  (AbsHandwheelVelocity_HwDegpS_T_f32 <= k_StopMode2HwVelTransThresh_HwDegpS_f32) &&
							  (AbsHwTorque_HwNm_T_f32 <= k_StopMode2HwTrqTransThresh_HwNm_f32) &&
							  (ElapsedTime2_mS_T_u32 >= ((uint32)k_StopMode2Timer_Sec_u16 * (uint32)D_MSECPERSEC_ULS_F32)) )
					{
						
						StrtStop_StOpMode_Cnt_M_enum 	= SS_Stop;
						StrtStop_SSScale_Uls_M_f32		= k_StopModeAssistDD_Uls_f32;
					}
					else
					{
						/* Remain in SS_Intermediate2 state */
					}
				}
				break;
				/* ENDREQ: CF12A #086 */ /* ENDREQ: CF12A #155 */ /* ENDREQ: CF12A #156 */ /* ENDREQ: CF12A #160 */ /* ENDREQ: CF12A #161 */ /* ENDREQ: CF12A #104 */
				
				default :
				/* Do nothing */
				break;
			}
		}
		/* ENDREQ: CF12A #062 */ /* ENDREQ: CF12A #195 */ /* ENDREQ: CF12A #166 */
	}
	/* ENDREQ: CF12A #066 */ /* ENDREQ: CF12A #166 */ /* ENDREQ: CF12A #167 */ /* ENDREQ: CF12A #182 */
	/* End of Current State Determination */

	
	/* Start of PreviousSt */
	PreviousStCalc();
	/* End of PreviousSt */
	
	/* Start of SlewRate */
	SSSlewRate_UlspS_T_f32 = SlewRateCalc();
	/* End of SlewRate */
	
	
	/* Start of SlewRateHold */
	/* REQ: CF12A #229 I */ /* REQ: CF12A #230 I */
	if(APAState_State_T_enum == D_APASTNORM_CNT_U08)
	{
		/* REQ: CF12A #230 I */
		StrtStop_SSScale_Uls_M_f32 	= D_ONE_ULS_F32;
		SSSlewRate_UlspS_T_f32 		= StrtStop_SSSlewRatePrev_UlspS_M_f32;
	}
	/* End of SlewRateHold */
	
	/* Updating Previous values for using in next cycle (unit delay) */
	StrtStop_SSSlewRatePrev_UlspS_M_f32 	= SSSlewRate_UlspS_T_f32;
	StrtStop_StOpModePrevPrev_Cnt_M_enum 	= StrtStop_StOpModePrev_Cnt_M_enum;
	StrtStop_StOpModePrev_Cnt_M_enum 		= StrtStop_StOpMode_Cnt_M_enum;
	
	/* Range Limit and Write local copies to RTE outputs */
	Rte_IWrite_StrtStop_Per1_SSScale_Uls_f32(Limit_m(StrtStop_SSScale_Uls_M_f32, D_SSSCALELOWRLIM_Uls_F32, D_SSSCALEUPPRLIM_Uls_F32));	/* REQ: CF12A #011 I */
	Rte_IWrite_StrtStop_Per1_SSSlew_UlspS_f32(Limit_m(SSSlewRate_UlspS_T_f32, D_SSSLEWLOWRLIM_UlspS_F32, D_SSSLEWUPPRLIM_UlspS_F32));	/* REQ: CF12A #040 I */
	Rte_IWrite_StrtStop_Per1_SSState_State_enum(StrtStop_StOpMode_Cnt_M_enum);															/* REQ: CF12A #216 I */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_GMSTRTSTOP_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * Function		: SlewRateCalc.
 * Inputs		: StrtStop_StOpModePrev_Cnt_M_enum, StrtStop_StOpMode_Cnt_M_enum
 * Outputs		: SSSlewRate_UlspS_T_f32.
 * Description	: This function corresponds to SlewRate block in FDD 
 * 				: and is split from Per1 to handle the cyclomatic complexity and path count.
 * Usage Notes	: NA.
 **********************************************************************************************************************/
 STATIC FUNC(float32, AP_GMSTRTSTOP_VAR) SlewRateCalc(void)
 
 {
	
	VAR(float32, AUTOMATIC) SSSlewRate_UlspS_T_f32 = D_ONE_ULS_F32;
	
	/* Start of SlewRate */
	switch (StrtStop_StOpModePrev_Cnt_M_enum)
	{
		/* REQ: CF12A #186 I */
		case SS_Normal :
		{
			if(StrtStop_StOpMode_Cnt_M_enum == SS_Intermediate1)
			{
				/* REQ: CF12A #186 I */ /* REQ: CF12A #145 I */ /* REQ: CF12A #093 I */
				SSSlewRate_UlspS_T_f32 = k_Mode1AssistSlew_UlspS_f32;
			}
			else
			{
				SSSlewRate_UlspS_T_f32 = k_FltRspRampDnRt_UlspS_f32;
			}
		}
		break;
	
		/* REQ: CF12A #148 I */ /* REQ: CF12A #152 I */ /* REQ: CF12A #187 I */
		case SS_Intermediate1 :
		{
			if(StrtStop_StOpMode_Cnt_M_enum == SS_Normal)
			{
				/* REQ: CF12A #148 I */ /* REQ: CF12A #187 I */
				SSSlewRate_UlspS_T_f32 = k_NormalModeAssistSlew_UlspS_f32;
			}
			else if(StrtStop_StOpMode_Cnt_M_enum == SS_Stop)
			{
				/* REQ: CF12A #152 I */  /* REQ: CF12A #188 I */ /* REQ: CF12A #099 I */
				SSSlewRate_UlspS_T_f32 = k_StopMode1AssistSlew_UlspS_f32;
			}
			else
			{
				SSSlewRate_UlspS_T_f32 = k_FltRspRampDnRt_UlspS_f32;
			}
		}
		break;
	
		/* REQ: CF12A #191 I */ /* REQ: CF12A #164 I */ /* REQ: CF12A #157 I */
		case SS_Stop :
		{
			if(StrtStop_StOpMode_Cnt_M_enum == SS_Intermediate2)
			{
				/* REQ: CF12A #191 I */ /* REQ: CF12A #103 I */ /* REQ: CF12A #157 I */
				SSSlewRate_UlspS_T_f32 = k_Mode2AssistSlew_UlspS_f32;
			}
			else if(StrtStop_StOpMode_Cnt_M_enum == SS_Normal)
			{
				/* REQ: CF12A #190 I */ /* REQ: CF12A #164 I */
				SSSlewRate_UlspS_T_f32 = k_NormalModeAssistSlew_UlspS_f32;
			}
			else
			{
				SSSlewRate_UlspS_T_f32 = k_FltRspRampDnRt_UlspS_f32;
			}
		}
		break;
		
		/* REQ: CF12A #163 I */ /* REQ: CF12A #165 I */
		case SS_Intermediate2 :
		{
			if(StrtStop_StOpMode_Cnt_M_enum == SS_Stop)
			{
				/* REQ: CF12A #163 I */ /* REQ: CF12A #194 I */ /* REQ: CF12A #109 I */
				SSSlewRate_UlspS_T_f32 = k_StopMode2AssistSlew_UlspS_f32;
			}
			else if(StrtStop_StOpMode_Cnt_M_enum == SS_Normal)
			{
				/* REQ: CF12A #165 I */ /* REQ: CF12A #193 I */ /* REQ: CF12A #112 I */
				SSSlewRate_UlspS_T_f32 = k_NormalModeAssistSlew_UlspS_f32;
			}
			else
			{
				SSSlewRate_UlspS_T_f32 = k_FltRspRampDnRt_UlspS_f32;
			}
		}
		break;
	
		case SS_Fault :
		{
			/* REQ: CF12A #196 I */ /* REQ: CF12A #113 I */
			SSSlewRate_UlspS_T_f32 = k_FltRspRampDnRt_UlspS_f32;
		}
		break;
		
		default :
		/* Do nothing */
		break;
	}
	/* End of SlewRate */
	
	return(SSSlewRate_UlspS_T_f32);
 
 }
 
 
 /**********************************************************************************************************************
 * Function		: PreviousStCalc.
 * Inputs		: StrtStop_StOpMode_Cnt_M_enum, StrtStop_StOpModePrev_Cnt_M_enum.
 * Outputs		: NA.
 * Description	: This function corresponds to PreviousSt block in FDD and 
 *				: is split from Per1 to handle the cyclomatic complexity and path count.
 * Usage Notes	: NA.
 **********************************************************************************************************************/
 STATIC FUNC(void, AP_GMSTRTSTOP_VAR) PreviousStCalc(void)
 {
	/* Start of PreviousSt */
	if(StrtStop_StOpMode_Cnt_M_enum == StrtStop_StOpModePrev_Cnt_M_enum)
	{
		StrtStop_StOpModePrev_Cnt_M_enum 		= StrtStop_StOpModePrevPrev_Cnt_M_enum;
	}
	/* End of PreviousSt */
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
