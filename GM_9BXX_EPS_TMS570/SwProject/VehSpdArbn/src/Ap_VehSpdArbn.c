/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_VehSpdArbn.c
 *     Workspace:  C:/_synergy/9BXX_CZ8L9T/GM_9BXX_EPS_TMS570/SwProject/VehSpdArbn/autosar
 *     SW-C Type:  Ap_VehSpdArbn
 *  Generated at:  Fri Nov 20 14:19:24 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_VehSpdArbn>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          1 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Wed Feb 12 14:26:44 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 12/03/15  1        GMN       EA3#4313: Initial version                                                    4572
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_VehSpdArbn.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "GlobalMacro.h"
#include "CalConstants.h"

/* MISRA-C: 2004 Rules 12.10 /14.2: Use of comma operator. Used by the RTE functions */
/* PRQA S 3417, 3426 EOF */

/* Limits to vehicle speed */
#define D_MINVEHSPD_KPH_F32    (0.0F)
#define D_MAXVEHSPD_KPH_F32    (511.0F)

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
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
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
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_VEHSPDARBN_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehSpdArbn_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32(Float *data)
 *   Std_ReturnType Rte_Read_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32(Float *data)
 *   Std_ReturnType Rte_Read_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32(Float *data)
 *   Std_ReturnType Rte_Read_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32(Float *data)
 *   Std_ReturnType Rte_Read_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc(Boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_NonSecureVehSpd_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_NonSecureVehSpdVld_Cnt_lgc(Boolean data)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHSPDARBN_APPL_CODE) VehSpdArbn_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehSpdArbn_Per1
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) SrlComWhlGrndVlctyLftDrvnHS_Kph_T_f32;
	VAR(boolean, AUTOMATIC) SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) SrlComWhlGrndVlctyLftNnDrvnHS_Kph_T_f32;
	VAR(boolean, AUTOMATIC) SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) SrlComWhlGrndVlctyRtDrvnHS_Kph_T_f32;
	VAR(boolean, AUTOMATIC) SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) SrlComWhlGrndVlctyRtNnDrvnHS_Kph_T_f32;
	VAR(boolean, AUTOMATIC) SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) NonSecureVehSpdAverage_Kph_T_f32;
	VAR(boolean, AUTOMATIC) NonSecureVehSpdVld_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) NumberOfValidVlcty_Cnt_T_u08;

	/* Read inputs */
	(void)Rte_Read_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32(&SrlComWhlGrndVlctyLftDrvnHS_Kph_T_f32);
	(void)Rte_Read_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc(&SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_T_lgc);
	(void)Rte_Read_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32(&SrlComWhlGrndVlctyLftNnDrvnHS_Kph_T_f32);
	(void)Rte_Read_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc(&SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_T_lgc);
	(void)Rte_Read_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32(&SrlComWhlGrndVlctyRtDrvnHS_Kph_T_f32);
	(void)Rte_Read_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc(&SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_T_lgc);
	(void)Rte_Read_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32(&SrlComWhlGrndVlctyRtNnDrvnHS_Kph_T_f32);
	(void)Rte_Read_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc(&SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_T_lgc);

	/* Reset number of valid velocities assuming all are bad */
	NumberOfValidVlcty_Cnt_T_u08 = 0U;
	NonSecureVehSpdAverage_Kph_T_f32 = 0.0F;

	if (SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_T_lgc == TRUE)
	{
		NumberOfValidVlcty_Cnt_T_u08 = 1U;
		NonSecureVehSpdAverage_Kph_T_f32 = NonSecureVehSpdAverage_Kph_T_f32 + SrlComWhlGrndVlctyLftDrvnHS_Kph_T_f32;
	}

	if (SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_T_lgc == TRUE)
	{
		NumberOfValidVlcty_Cnt_T_u08 = NumberOfValidVlcty_Cnt_T_u08 + 1U;
		NonSecureVehSpdAverage_Kph_T_f32 = NonSecureVehSpdAverage_Kph_T_f32 + SrlComWhlGrndVlctyLftNnDrvnHS_Kph_T_f32;
	}

	if (SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_T_lgc == TRUE)
	{
		NumberOfValidVlcty_Cnt_T_u08 = NumberOfValidVlcty_Cnt_T_u08 + 1U;
		NonSecureVehSpdAverage_Kph_T_f32 = NonSecureVehSpdAverage_Kph_T_f32 + SrlComWhlGrndVlctyRtDrvnHS_Kph_T_f32;
	}

	if (SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_T_lgc == TRUE)
	{
		NumberOfValidVlcty_Cnt_T_u08 = NumberOfValidVlcty_Cnt_T_u08 + 1U;
		NonSecureVehSpdAverage_Kph_T_f32 = NonSecureVehSpdAverage_Kph_T_f32 + SrlComWhlGrndVlctyRtNnDrvnHS_Kph_T_f32;
	}

	/* Check number of valid velocities received */
	if (NumberOfValidVlcty_Cnt_T_u08 == 0U)
	{
		/* There is no valid velocity */
		NonSecureVehSpdAverage_Kph_T_f32 = k_DefaultVehSpd_Kph_f32;
		NonSecureVehSpdVld_Cnt_T_lgc = FALSE;
	}
	else
	{
		/* There are at least one valid velocity */
		NonSecureVehSpdAverage_Kph_T_f32 = (NonSecureVehSpdAverage_Kph_T_f32 / ((float32)NumberOfValidVlcty_Cnt_T_u08));
		NonSecureVehSpdVld_Cnt_T_lgc = TRUE;
	}

	/* Limit the outputs */
	NonSecureVehSpdAverage_Kph_T_f32 = Limit_m(NonSecureVehSpdAverage_Kph_T_f32, D_MINVEHSPD_KPH_F32, D_MAXVEHSPD_KPH_F32);

	/* Write outputs */
	(void)Rte_Write_NonSecureVehSpd_Kph_f32(NonSecureVehSpdAverage_Kph_T_f32);
	(void)Rte_Write_NonSecureVehSpdVld_Cnt_lgc(NonSecureVehSpdVld_Cnt_T_lgc);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_VEHSPDARBN_APPL_CODE
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
