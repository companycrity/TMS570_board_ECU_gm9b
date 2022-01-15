/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_TrqOsc.c
 *     Workspace:  C:/Synergy/Working/Component/CBD_TrqOsc-gz7pm0/CBD_TrqOsc/autosar
 *     SW-C Type:  Ap_TrqOsc
 *  Generated at:  Thu Apr  3 10:16:45 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_TrqOsc>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /* Version Control:
 * Date Created:      Tue Mar 25 14:55:10 2014
 * %version:          1 %
 * %derived_by:       gz7pm0 %
 * %date_modified:    Fri Dec 13 14:08:05 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * --------  -------  --------  ---------------------------------------------------------------------------  ----------
 * 03/26/14  1        LK        Initial Version (SF 43 v001)                                                 11572
*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Ap_TrqOsc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CalConstants.h"
#include "fixmath.h"
#include "filters.h"
#include "Ap_TrqOsc_Cfg.h"
/*Constants*/
#define D_TRQOSCPERMMAXFREQ_HZ_U12P4 (FPM_InitFixedPoint_m(50.0f,u12p4_T)) /* Max Freq*/
#define D_TRQOSCPERMMINFREQ_HZ_U12P4 (FPM_InitFixedPoint_m(10.0f,u12p4_T)) /* Min Freq*/
#define D_TRQOSCMAXAMP_MTRNM_F32 (0.7f) /* Max Amplitude */
#define D_TRQOSCMINAMP_MTRNM_F32 (0.0f) /* Min Amplitude */
#define D_TRQOSCMAXDC_MTRNM_F32 (0.1f)  /* Max DC allowed */
#define D_TRQOSCDCTRENDLPFKN_HZ_F32 (0.32f) /*Low pass filter Kn*/

#define TRQOSC_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AUTOMATIC) TrqOsc_EnablePrev_Cnt_M_lgc;  /*to check for rising edge*/
STATIC VAR(boolean, AUTOMATIC) TrqOsc_DCExceeded_Cnt_M_lgc; /* Output for DCExceeded_lgc */
#define TRQOSC_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define TRQOSC_START_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */
STATIC VAR(float32, AUTOMATIC) TrqOsc_LmtAmplitude_MtrNm_M_f32; /*Limited Amplitude*/
STATIC VAR(float32, AUTOMATIC) TrqOsc_PhaseAngleIncrease_Rad_M_f32; /*Increase in PhaseAngle*/
STATIC VAR(float32, AUTOMATIC) TrqOsc_Angle_Rad_M_f32; /* Final Phase angle to be used in sine wave*/
STATIC VAR(float32, AUTOMATIC) TrqOsc_PrevAngle_Rad_M_f32;
STATIC volatile VAR(float32, AUTOMATIC) TrqOsc_SineCmd_Uls_D_f32; 
STATIC VAR(float32, AUTOMATIC) TrqOsc_PreFinalCmd_MtrNm_M_f32;
#define TRQOSC_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */

#define TRQOSC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(LPF32KSV_Str, AUTOMATIC) TrqOsc_PreFinalCmdKSV_M_str;
#define TRQOSC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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
 * Float: D_2PI_ULS_F32 = 6.2831853071796
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_TRQOSC_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqOsc_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQOSC_APPL_CODE) TrqOsc_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqOsc_Init
 *********************************************************************************************************************/
	/*Initialize Low Pass Filter here*/
	LPF_KUpdate_f32_m(D_TRQOSCDCTRENDLPFKN_HZ_F32,D_2MS_SEC_F32,&TrqOsc_PreFinalCmdKSV_M_str);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqOsc_Per1
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
 *   Float Rte_IRead_TrqOsc_Per1_TrqOscAmp_MtrNm_f32(void)
 *   Boolean Rte_IRead_TrqOsc_Per1_TrqOscEnable_Cnt_lgc(void)
 *   Float Rte_IRead_TrqOsc_Per1_TrqOscFreq_Hz_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TrqOsc_Per1_TrqOscCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_TrqOsc_Per1_TrqOscCmd_MtrNm_f32(void)
 *   void Rte_IWrite_TrqOsc_Per1_TrqOscDCExceeded_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_TrqOsc_Per1_TrqOscDCExceeded_Cnt_lgc(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQOSC_APPL_CODE) TrqOsc_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqOsc_Per1
 *********************************************************************************************************************/
/*Inputs*/
	VAR(boolean, AUTOMATIC) Enable_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) Freq_Hz_T_f32;
	VAR(uint16, AUTOMATIC) Freq_Hz_T_u12p4;
	VAR(float32, AUTOMATIC) Amplitude_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) AmplitudeAbs_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) LmtAmplitude_MtrNm_T_f32;
	VAR(uint16, AUTOMATIC) EffectiveFreq_Hz_T_u12p4;
	VAR(float32, AUTOMATIC) EffectiveFreq_Hz_T_f32;
	VAR(float32, AUTOMATIC) SineCmd_Uls_T_f32;
	VAR(float32, AUTOMATIC) FiltPreFinalCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) AbsFiltPreFinalCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) PhaseAngleIn_Rad_T_f32; /*Phase Angle Input for Angle wrap*/
	VAR(float32, AUTOMATIC) PhaseAngleOut_Rad_T_f32; /*Phase Angle Output after Angle wrap*/
	VAR(float32, AUTOMATIC) AmpLmt_MtrNm_T_f32;
	VAR(uint16, AUTOMATIC) AmpLmt_MtrNm_T_u5p11;	
	VAR(uint16, AUTOMATIC) FreqIndex_Cnt_T_u16;
	VAR(float32, AUTOMATIC) OscTrqCmd_MtrNm_T_f32; /* Output for Final OscTrqCmd */

	
	/*Input Reads*/
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_TrqOsc_Per1_CP0_CheckpointReached();
	Enable_Cnt_T_lgc = Rte_IRead_TrqOsc_Per1_TrqOscEnable_Cnt_lgc();
	Freq_Hz_T_f32= Rte_IRead_TrqOsc_Per1_TrqOscFreq_Hz_f32();
	Amplitude_MtrNm_T_f32 = Rte_IRead_TrqOsc_Per1_TrqOscAmp_MtrNm_f32();
		
	if((Enable_Cnt_T_lgc == TRUE) && (TrqOsc_EnablePrev_Cnt_M_lgc == FALSE))
	{
		
		/****Update Variables****/
		
		Freq_Hz_T_f32 = Abs_f32_m(Freq_Hz_T_f32);
		Freq_Hz_T_u12p4 = FPM_FloatToFixed_m(Freq_Hz_T_f32, u12p4_T);
		
		/* Interpolation based on floor input value (value below) */
		if (Freq_Hz_T_u12p4 <= t_TrqOscFreqIn_Hz_u12p4[0u])
		{
			Freq_Hz_T_u12p4 = t_TrqOscFreqIn_Hz_u12p4[0u];
		}
		else if(Freq_Hz_T_u12p4 >= (t_TrqOscFreqIn_Hz_u12p4[TableSize_m(t_TrqOscFreqIn_Hz_u12p4)-1u]))
		{

			Freq_Hz_T_u12p4 = t_TrqOscFreqIn_Hz_u12p4[TableSize_m(t_TrqOscFreqIn_Hz_u12p4)-1u];
		} 
		else
		{
			FreqIndex_Cnt_T_u16 = 0u;
			while( t_TrqOscFreqIn_Hz_u12p4[FreqIndex_Cnt_T_u16+1u] <= Freq_Hz_T_u12p4)
			{

				FreqIndex_Cnt_T_u16++;
			}
			Freq_Hz_T_u12p4 = t_TrqOscFreqIn_Hz_u12p4[FreqIndex_Cnt_T_u16];
		}
		
	
		EffectiveFreq_Hz_T_u12p4 = Limit_m(Freq_Hz_T_u12p4, D_TRQOSCPERMMINFREQ_HZ_U12P4, D_TRQOSCPERMMAXFREQ_HZ_U12P4);
												
		/* Interpolation based on floor input value (value below) */
		if (EffectiveFreq_Hz_T_u12p4 <= t_TrqOscFreqIn_Hz_u12p4[0u])
		{
			AmpLmt_MtrNm_T_u5p11 = t_TrqOscAmpLimit_MtrNm_u5p11[0];
			
		}
		else if(EffectiveFreq_Hz_T_u12p4 >= t_TrqOscFreqIn_Hz_u12p4[TableSize_m(t_TrqOscFreqIn_Hz_u12p4)-1u])
		{
			AmpLmt_MtrNm_T_u5p11 = t_TrqOscAmpLimit_MtrNm_u5p11[TableSize_m(t_TrqOscAmpLimit_MtrNm_u5p11)-1u];
		} 
		else
		{
			FreqIndex_Cnt_T_u16 = 0u;
			while( t_TrqOscFreqIn_Hz_u12p4[FreqIndex_Cnt_T_u16+1u] <= EffectiveFreq_Hz_T_u12p4)
			{
				/*Perform floor logic for intermediate values*/
				FreqIndex_Cnt_T_u16++;
			}
			AmpLmt_MtrNm_T_u5p11 = t_TrqOscAmpLimit_MtrNm_u5p11[FreqIndex_Cnt_T_u16];
		}													
															
															
		AmpLmt_MtrNm_T_f32 = FPM_FixedToFloat_m(AmpLmt_MtrNm_T_u5p11,u5p11_T);
		
		AmplitudeAbs_MtrNm_T_f32 = Abs_f32_m(Amplitude_MtrNm_T_f32);
		LmtAmplitude_MtrNm_T_f32 = Limit_m(AmplitudeAbs_MtrNm_T_f32,D_ZERO_ULS_F32, AmpLmt_MtrNm_T_f32);
		
		TrqOsc_LmtAmplitude_MtrNm_M_f32 = Limit_m(LmtAmplitude_MtrNm_T_f32, D_TRQOSCMINAMP_MTRNM_F32, D_TRQOSCMAXAMP_MTRNM_F32);

		/*Phase Angle Increase*/
		EffectiveFreq_Hz_T_f32  = FPM_FixedToFloat_m(EffectiveFreq_Hz_T_u12p4, u12p4_T);											  
		EffectiveFreq_Hz_T_f32 = EffectiveFreq_Hz_T_f32 * D_2PI_ULS_F32;
		TrqOsc_PhaseAngleIncrease_Rad_M_f32 = EffectiveFreq_Hz_T_f32 * D_2MS_SEC_F32;
		
	}
	
		TrqOsc_EnablePrev_Cnt_M_lgc = Enable_Cnt_T_lgc; /* Update the previous enable*/
		
		/****Unit Delay****/
		
		PhaseAngleIn_Rad_T_f32 = TrqOsc_PhaseAngleIncrease_Rad_M_f32 + TrqOsc_PrevAngle_Rad_M_f32 ; /*Uses previous value of TrqOsc_Angle_Rad_M_f32 */
		
		/****Angle Wrapper****/
		
		if(PhaseAngleIn_Rad_T_f32 >= D_2PI_ULS_F32)
		{
			/*Pass through to calculate new Phase Angle*/
			PhaseAngleOut_Rad_T_f32 = PhaseAngleIn_Rad_T_f32 - D_2PI_ULS_F32;
		}
		else
		{
			PhaseAngleOut_Rad_T_f32 = PhaseAngleIn_Rad_T_f32;
		}
			
		/****Check Flag and Update TrqOsc_Angle_Rad_M_f32 accordingly****/
		if(Enable_Cnt_T_lgc ==TRUE)
		{
			TrqOsc_Angle_Rad_M_f32 = PhaseAngleOut_Rad_T_f32;
		}
		else
		{
			TrqOsc_Angle_Rad_M_f32 = 0.0f;
		}
		TrqOsc_PrevAngle_Rad_M_f32 = TrqOsc_Angle_Rad_M_f32;
		
		SineCmd_Uls_T_f32 = sinf(TrqOsc_Angle_Rad_M_f32); 
		TrqOsc_SineCmd_Uls_D_f32 = SineCmd_Uls_T_f32;
		TrqOsc_PreFinalCmd_MtrNm_M_f32 = SineCmd_Uls_T_f32 * TrqOsc_LmtAmplitude_MtrNm_M_f32; 
		
		/****DC Check****/
		/*DC Trend - LPF*/
		FiltPreFinalCmd_MtrNm_T_f32 = LPF_OpUpdate_f32_m(TrqOsc_PreFinalCmd_MtrNm_M_f32,&TrqOsc_PreFinalCmdKSV_M_str);
		AbsFiltPreFinalCmd_MtrNm_T_f32 = Abs_f32_m(FiltPreFinalCmd_MtrNm_T_f32);
		
		if( AbsFiltPreFinalCmd_MtrNm_T_f32 >= D_TRQOSCMAXDC_MTRNM_F32)
		{
			TrqOsc_DCExceeded_Cnt_M_lgc = TRUE;
		}
			
		
		if(TrqOsc_DCExceeded_Cnt_M_lgc == TRUE)
		{
			OscTrqCmd_MtrNm_T_f32 = 0.0f;
		}
		else
		{
			OscTrqCmd_MtrNm_T_f32 = TrqOsc_PreFinalCmd_MtrNm_M_f32;
		}
				
		/*Saturation saturation*/
		OscTrqCmd_MtrNm_T_f32 = Limit_m(OscTrqCmd_MtrNm_T_f32,-D_TRQOSCMAXAMP_MTRNM_F32,D_TRQOSCMAXAMP_MTRNM_F32);

		/*Output Writes*/
		Rte_IWrite_TrqOsc_Per1_TrqOscDCExceeded_Cnt_lgc(TrqOsc_DCExceeded_Cnt_M_lgc);
		Rte_IWrite_TrqOsc_Per1_TrqOscCmd_MtrNm_f32(OscTrqCmd_MtrNm_T_f32);
		
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_TrqOsc_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_TRQOSC_APPL_CODE
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
 
