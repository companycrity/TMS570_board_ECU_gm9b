/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_WIRInputQual.c
 *     Workspace:  C:/SynergyWorkArea/GMK2XXRT2.0/GM_K2XX_EPS_TMS570/SwProject/WIRInputQual/autosar
 *     SW-C Type:  Ap_WIRInputQual
 *  Generated at:  Sun Nov 11 10:32:50 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_WIRInputQual>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Feb 21 08:59:27 2012
 * %version:          1 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Mon Jul 29 10:53:39 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service

 *********************************************************************************************************************/

#include "Rte_Ap_WIRInputQual.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_WIRInputQual_Cfg.h"
	#include "GlobalMacro.h"
	#include "fixmath.h"
	#include "CalConstants.h"
	
	#define D_WHLSPDMIN_HZ_F32		0.0F
	#define D_WHLSPDMAX_HZ_F32		40.0F

	#define WIRINPUTQUAL_START_SEC_VAR_CLEARED_32
	#include "MemMap.h"

	STATIC VAR(float32, AP_WIRINPUTQUAL_VAR_NOINIT) PrevQualWhlSpdLeft_Hz_M_f32;
	STATIC VAR(float32, AP_WIRINPUTQUAL_VAR_NOINIT) PrevQualWhlSpdRight_Hz_M_f32;

	#define WIRINPUTQUAL_STOP_SEC_VAR_CLEARED_32
	#include "MemMap.h"

	#define WIRINPUTQUAL_START_SEC_VAR_CLEARED_16
	#include "MemMap.h"

	STATIC VAR(uint16, AP_WIRINPUTQUAL_VAR_NOINIT) QualLevelLeft_Cnt_M_u16;
	STATIC VAR(uint16, AP_WIRINPUTQUAL_VAR_NOINIT) QualLevelRight_Cnt_M_u16;
	STATIC VAR(uint16, AP_WIRINPUTQUAL_VAR_NOINIT) QualErrAccLeft_Cnt_M_u16;
	STATIC VAR(uint16, AP_WIRINPUTQUAL_VAR_NOINIT) QualErrAccRight_Cnt_M_u16;

	#define WIRINPUTQUAL_STOP_SEC_VAR_CLEARED_16
	#include "MemMap.h"


	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) QualifyWhlSpd(	P2VAR(float32, AUTOMATIC, AUTOMATIC) WhlSpd_Ptr_T_f32,
																		P2VAR(float32, AUTOMATIC, AUTOMATIC) PrevQualWhlSpd_Ptr_T_f32,
																		VAR(boolean, AUTOMATIC) WhlSpdValid_Cnt_T_lgc, 
																		P2VAR(uint16, AUTOMATIC, AUTOMATIC) QualLevel_Ptr_T_u16);

	STATIC INLINE FUNC(boolean, RTE_AP_WHLIMBREJ_APPL_CODE) WhlSpdInRange(	VAR(float32, AUTOMATIC) WhlSpd_Hz_T_f32);

	STATIC INLINE FUNC(boolean, RTE_AP_WHLIMBREJ_APPL_CODE) WhlSpdQualCheck(VAR(uint16, AUTOMATIC) QualLevel_Cnt_T_u16,
																			VAR(boolean, AUTOMATIC) InRange_Cnt_T_lgc,
																			P2VAR(uint16, AUTOMATIC, AUTOMATIC) QualErrAcc_Ptr_T_u16);
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
 * Double: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
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
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Boolean: D_TRUE_CNT_LGC = TRUE
 * Double: D_SFINVMILLI_ULS_F32 = 1000
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082F
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_2PI_ULS_F32 = 6.2831853071796F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199F
 * Float: D_PI_ULS_F32 = 3.1415926535898F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ZERO_CNT_U32 = 0U
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3U
 * UInt8: D_QUADRANT1_CNT_U8 = 1U
 * UInt8: D_QUADRANT2_CNT_U8 = 2U
 * UInt8: D_QUADRANT3_CNT_U8 = 3U
 * UInt8: D_QUADRANT4_CNT_U8 = 4U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_WIRINPUTQUAL_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WIRInputQual_Per1
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
 *   Boolean Rte_IRead_WIRInputQual_Per1_SrlComLWhlSpdVld_Cnt_lgc(void)
 *   Float Rte_IRead_WIRInputQual_Per1_SrlComLWhlSpd_Hz_f32(void)
 *   Boolean Rte_IRead_WIRInputQual_Per1_SrlComRWhlSpdVld_Cnt_lgc(void)
 *   Float Rte_IRead_WIRInputQual_Per1_SrlComRWhlSpd_Hz_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_WIRInputQual_Per1_QualWhlFreqL_Hz_f32(Float data)
 *   Float *Rte_IWriteRef_WIRInputQual_Per1_QualWhlFreqL_Hz_f32(void)
 *   void Rte_IWrite_WIRInputQual_Per1_QualWhlFreqR_Hz_f32(Float data)
 *   Float *Rte_IWriteRef_WIRInputQual_Per1_QualWhlFreqR_Hz_f32(void)
 *   void Rte_IWrite_WIRInputQual_Per1_WhlFreqQualified_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_WIRInputQual_Per1_WhlFreqQualified_Cnt_lgc(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_WIRINPUTQUAL_APPL_CODE) WIRInputQual_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WIRInputQual_Per1
 *********************************************************************************************************************/

	VAR(boolean, AUTOMATIC) WhlSpdLeftInRng_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) WhlSpdRightInRng_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) WhlSpdLeftQualfied_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) WhlSpdRightQualfied_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) WhlSpdLeftValid_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) WhlSpdLeft_Hz_T_f32;
	VAR(boolean, AUTOMATIC) WhlSpdRightValid_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) WhlSpdRight_Hz_T_f32;
	VAR(boolean, AUTOMATIC) WhlFreqQualified_Cnt_T_lgc;
	
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_WIRInputQual_Per1_CP0_CheckpointReached();
	WhlSpdLeftValid_Cnt_T_lgc = Rte_IRead_WIRInputQual_Per1_SrlComLWhlSpdVld_Cnt_lgc();
	WhlSpdLeft_Hz_T_f32 = Rte_IRead_WIRInputQual_Per1_SrlComLWhlSpd_Hz_f32();
	WhlSpdRightValid_Cnt_T_lgc = Rte_IRead_WIRInputQual_Per1_SrlComRWhlSpdVld_Cnt_lgc();
	WhlSpdRight_Hz_T_f32 = Rte_IRead_WIRInputQual_Per1_SrlComRWhlSpd_Hz_f32();

	QualifyWhlSpd(	&WhlSpdLeft_Hz_T_f32,
					&PrevQualWhlSpdLeft_Hz_M_f32,
					WhlSpdLeftValid_Cnt_T_lgc,
					&QualLevelLeft_Cnt_M_u16);
	
	QualifyWhlSpd(	&WhlSpdRight_Hz_T_f32,
					&PrevQualWhlSpdRight_Hz_M_f32,
					WhlSpdRightValid_Cnt_T_lgc,
					&QualLevelRight_Cnt_M_u16);
	
	WhlSpdLeftInRng_Cnt_T_lgc = WhlSpdInRange(WhlSpdLeft_Hz_T_f32);
	WhlSpdRightInRng_Cnt_T_lgc = WhlSpdInRange(WhlSpdRight_Hz_T_f32);
					
	WhlSpdLeftQualfied_Cnt_T_lgc = WhlSpdQualCheck(QualLevelLeft_Cnt_M_u16, WhlSpdLeftInRng_Cnt_T_lgc, &QualErrAccLeft_Cnt_M_u16);
	WhlSpdRightQualfied_Cnt_T_lgc = WhlSpdQualCheck(QualLevelRight_Cnt_M_u16, WhlSpdRightInRng_Cnt_T_lgc, &QualErrAccRight_Cnt_M_u16);
	
	WhlFreqQualified_Cnt_T_lgc = TRUE;
		
	if (FALSE == WhlSpdLeftQualfied_Cnt_T_lgc)																			
	{
		WhlFreqQualified_Cnt_T_lgc = FALSE;
		WhlSpdLeft_Hz_T_f32 = 0.0F;
	}
	if (FALSE == WhlSpdRightQualfied_Cnt_T_lgc)
	{
		WhlFreqQualified_Cnt_T_lgc = FALSE;
		WhlSpdRight_Hz_T_f32 = 0.0F;
	}			
	
	WhlSpdLeft_Hz_T_f32 = Limit_m(WhlSpdLeft_Hz_T_f32, D_WHLSPDMIN_HZ_F32, D_WHLSPDMAX_HZ_F32);
	WhlSpdRight_Hz_T_f32 = Limit_m(WhlSpdRight_Hz_T_f32, D_WHLSPDMIN_HZ_F32, D_WHLSPDMAX_HZ_F32);

	Rte_IWrite_WIRInputQual_Per1_QualWhlFreqL_Hz_f32(WhlSpdLeft_Hz_T_f32);
	Rte_IWrite_WIRInputQual_Per1_QualWhlFreqR_Hz_f32(WhlSpdRight_Hz_T_f32);
	Rte_IWrite_WIRInputQual_Per1_WhlFreqQualified_Cnt_lgc(WhlFreqQualified_Cnt_T_lgc);

	/* Configurable End of Runnable Checkpoint */
	Rte_Call_WIRInputQual_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_WIRINPUTQUAL_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/******************************************************************************
* Name:        QualifyWhlSpd
* Description: Qualify Wheel Speeds
******************************************************************************/
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) QualifyWhlSpd(	P2VAR(float32, AUTOMATIC, AUTOMATIC) WhlSpd_Ptr_T_f32,
																	P2VAR(float32, AUTOMATIC, AUTOMATIC) PrevQualWhlSpd_Ptr_T_f32,
																	VAR(boolean, AUTOMATIC) WhlSpdValid_Cnt_T_lgc, 
																	P2VAR(uint16, AUTOMATIC, AUTOMATIC) QualLevel_Ptr_T_u16)
{
	if(TRUE == WhlSpdValid_Cnt_T_lgc)
	{
		*PrevQualWhlSpd_Ptr_T_f32 = *WhlSpd_Ptr_T_f32;
		*QualLevel_Ptr_T_u16 = Min_m((*QualLevel_Ptr_T_u16 + k_WhlSpdQPStep_Cnt_u16), k_WhlSpdQLimit_Cnt_u16);
	}
	else
	{
		*WhlSpd_Ptr_T_f32 = *PrevQualWhlSpd_Ptr_T_f32;
		
		if(*QualLevel_Ptr_T_u16 > k_WhlSpdQNStep_Cnt_u16)
		{
			*QualLevel_Ptr_T_u16 = *QualLevel_Ptr_T_u16 - k_WhlSpdQNStep_Cnt_u16;
		}
		else
		{
			*QualLevel_Ptr_T_u16 = 0U;
		}
	}
}

/******************************************************************************
* Name:        WhlSpdInRange
* Description: Wheel Speed In Range Check
******************************************************************************/
STATIC INLINE FUNC(boolean, RTE_AP_WHLIMBREJ_APPL_CODE) WhlSpdInRange(	VAR(float32, AUTOMATIC) WhlSpd_Hz_T_f32)
{
	VAR(uint16, AUTOMATIC) WhlSpd_Hz_T_u7p9;
	VAR(boolean, AUTOMATIC) InRange_Cnt_T_lgc;
	
	WhlSpd_Hz_T_u7p9 = FPM_FloatToFixed_m(WhlSpd_Hz_T_f32, u7p9_T);
	
	if(	(WhlSpd_Hz_T_u7p9 >= t_FreqScaleTblX_Hz_u7p9[0]) && 
	    (WhlSpd_Hz_T_u7p9 <= t_FreqScaleTblX_Hz_u7p9[TableSize_m(t_FreqScaleTblX_Hz_u7p9)-1U]))
	{
		InRange_Cnt_T_lgc = TRUE;
	}
	else
	{
		InRange_Cnt_T_lgc = FALSE;
	}
	
	return(InRange_Cnt_T_lgc);
}

/******************************************************************************
* Name:        WhlSpdQualCheck
* Description: Wheel Speed Qualification Check
******************************************************************************/
STATIC INLINE FUNC(boolean, RTE_AP_WHLIMBREJ_APPL_CODE) WhlSpdQualCheck(VAR(uint16, AUTOMATIC) QualLevel_Cnt_T_u16,
																		VAR(boolean, AUTOMATIC) InRange_Cnt_T_lgc,
																		P2VAR(uint16, AUTOMATIC, AUTOMATIC) QualErrAcc_Ptr_T_u16)
{
	VAR(boolean, AUTOMATIC) WhlSpdQualfied_Cnt_T_lgc;
	
	if(TRUE == InRange_Cnt_T_lgc)
	{
		if(0U == QualLevel_Cnt_T_u16)
		{
			*QualErrAcc_Ptr_T_u16 = DiagPStep_m(*QualErrAcc_Ptr_T_u16, k_WhlSpdQualDiag_Cnt_Str);
		}
		else 
		{
			if(QualLevel_Cnt_T_u16 >= k_WhlSpdQLimit_Cnt_u16)
			{
				*QualErrAcc_Ptr_T_u16 = DiagNStep_m(*QualErrAcc_Ptr_T_u16, k_WhlSpdQualDiag_Cnt_Str);
			}
		}
	}
	
	if (DiagFailed_m(*QualErrAcc_Ptr_T_u16, k_WhlSpdQualDiag_Cnt_Str) == TRUE)
	{
		WhlSpdQualfied_Cnt_T_lgc = FALSE;
	}
	else
	{
		WhlSpdQualfied_Cnt_T_lgc = TRUE;
	}
	
	return(WhlSpdQualfied_Cnt_T_lgc);
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
