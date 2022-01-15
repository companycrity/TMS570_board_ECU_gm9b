/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_WhlImbRej.c
 *     Workspace:  C:/Synergy/WhlImbRej-zz4r1x/WhlImbRej/autosar
 *     SW-C Type:  Ap_WhlImbRej
 *  Generated at:  Tue Nov 13 09:04:47 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_WhlImbRej>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Tue Jul  5 16:03:05 2011
 * %version:          17 %
 * %derived_by:       zz4r1x %
 * %date_modified:    Tue Nov 13 09:00:34 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/05/11  1        LWW       Initial Template
 * 07/06/11  2        LWW       Initial implementation
 * 07/13/11  3        LWW       Algorithm updates, implementation of tuning blending
 * 07/22/11  4        LWW       Updates per FDD
 * 07/25/11  5        LWW       Fixed passing of structure to local functions
 * 07/27/11  6        LWW       Removed phase adjust enable and added frequency diag enable calibrations
 * 08/05/11  7        LWW       Added WIREnabled input processing, fixed float conversion macro
 * 09/26/11	 8		  KJS		Updated diagnostic function calls with 9bit NTC value							4500 
 * 10/14/11	 9		  LWW		Anomaly correction in frequency diagnostic
 * 01/06/12	 10		  LWW		Commented tuning adjustment functions temporarily for component implementation
 * 01/06/12  11       LWW       Added defeat mask defined locally until component implementation is done
 * 02/21/12  12       LWW       Removed input qualification, addition of enables and vehicle speed checks
 * 05/25/12  13       LWW       Updated for anomaly corrections per new FDD Rev
 * 09/24/12  14       NRAR      Updated as per FDD Ver 005(Excluding SafetyCritical functions) and Ver 006.
 * 09/24/12  15       Selva     Checkpoints added and mempmap macros corrected		                            6256
 * 10/24/12  16       BWL       Change trigger rate to meet new standard.										6623
 * 11/13/12  17       BWL       Update NTC to VLF_00 per new StdDef.											6797
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


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_WhlImbRej.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
	#include "GlobalMacro.h"
	#include "fixmath.h"
	#include "CalConstants.h"
	#include "filters.h"
	#include "interpolation.h"
	#include "Filter_Types.h"
	#include <math.h>
	#include <float.h>
    #include "Ap_WhlImbRej_Cfg.h"
	
	#define D_WIRQUALFLT_CNT_B16				0x0001U
	#define D_WIRCORRFLT_CNT_B16				0x0002U
	#define D_WIRCORRFLTREC_CNT_B16				0x0004U
	#define D_WIRMAXMAGFLT_CNT_B16				0x0008U
	#define D_WIRMAXMAGFLTREC_CNT_B16			0x0010U
	#define D_WIRMAXPERSFLT_CNT_B16				0x0020U
	#define D_WIRDCTRENDFLT_CNT_B16				0x0040U
	#define D_WIRDCTRENDFLTREC_CNT_B16			0x0080U
	#define D_WIRFREQDIAGFLT_CNT_B16			0x0100U
	#define D_WIRFREQDIAGFLTREC_CNT_B16			0x0200U
	#define D_PIDIVTWO_ULS_F32					1.57079632679F
	#define D_PITIMESSAMPLETIME_ULS_F32			0.006283185307F
	#define D_MSPERMIN_ULS_F32					60000.0F
	#define D_STOREDMINSPERCOUNT_ULS_F32		0.000133333333333F	
	#define D_RADPERDEGDIVTWO_ULS_F32			0.00872664626F
	#define D_CALMINSPERCOUNT_ULS_F32			10.0F	
	#define D_DURATIONDISABLE_CNT_U16			18500U
	#define D_FILTWHLSPDMAX_RADPSEC_F32			4.0F
	#define D_PHASEADJMAX_ULS_F32				127.0F
	#define D_CNCLTRQMAX_MTRNM_F32				127.0F
	#define D_UGRSVMAX_ULS_F32					256.0F
	#define D_LMSFILTSVMAX_ULS_F32				2048.0F
	#define D_LEADLAGFILTSVMAX_ULS_F32			65536.0F
	#define D_WIRCMDMAX_MTRNM_F32				8.0F
	#define D_ONEHUNDRED_PCT_F32				100.0F
	#define D_ONEHALF_ULS_F32					0.5F


	typedef struct WIRDiagInfo{
		uint32   StartTime_mS_u32p0;
		boolean  Failed_Cnt_lgc;
		boolean  ResetFlt_Cnt_lgc;
		boolean  MaxRecFailed_Cnt_lgc;
		uint8    RecoveryCntr_Cnt_u8;
	}WIRDiagInfo_Str;

	#define WHLIMBREJ_START_SEC_VAR_SAVED_ZONEH_32
	#include "MemMap.h"

	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) PeakRightTyH_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) PeakLeftTyH_Uls_M_f32;
	STATIC VAR(uint32, AP_WHLIMBREJ_VAR_NOINIT) WIRCmpActTyH_Cnt_M_u32[3];
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) WIRMaxCompTyH_Pct_M_f32;

	#define WHLIMBREJ_STOP_SEC_VAR_SAVED_ZONEH_32
	#include "MemMap.h"
	
	#define WHLIMBREJ_START_SEC_VAR_CLEARED_UNSPECIFIED
	#include "MemMap.h"
	
	STATIC VAR(WIRDiagInfo_Str,  AP_WHLIMBREJ_VAR_NOINIT) MaxMagFlt_Cnt_M_Str;
	STATIC VAR(WIRDiagInfo_Str,  AP_WHLIMBREJ_VAR_NOINIT) DCTrendFlt_Cnt_M_Str;
	STATIC VAR(WIRDiagInfo_Str,  AP_WHLIMBREJ_VAR_NOINIT) FreqDiagFlt_Cnt_M_Str;
	STATIC VAR(WIRDiagInfo_Str,  AP_WHLIMBREJ_VAR_NOINIT) CorrFlt_Cnt_M_Str;
	STATIC VAR(WIRDiagInfo_Str,  AP_WHLIMBREJ_VAR_NOINIT) QualFlt_Cnt_M_Str;
	STATIC VAR(WIRDiagInfo_Str,  AP_WHLIMBREJ_VAR_NOINIT) MaxPersFlt_Cnt_M_Str;
	
		/*FloatingPoint LPF SV declaration start */
	STATIC VAR(LPF32KSV_Str, AP_WHLIMBREJ_VAR_NOINIT) WhlFreqRFiltSV_Hz_M_str;
	STATIC VAR(LPF32KSV_Str, AP_WHLIMBREJ_VAR_NOINIT) WhlFreqLFiltSV_Hz_M_str;
	STATIC VAR(LPF32KSV_Str, AP_WHLIMBREJ_VAR_NOINIT) CmdMagFiltSV1_MtrNm_M_Str;
	STATIC VAR(LPF32KSV_Str, AP_WHLIMBREJ_VAR_NOINIT) CmdMagFiltSV2_MtrNm_M_Str;
	STATIC VAR(LPF32KSV_Str, AP_WHLIMBREJ_VAR_NOINIT) BlndCmdMagFiltSV1_MtrNm_M_Str;
	STATIC VAR(LPF32KSV_Str, AP_WHLIMBREJ_VAR_NOINIT) BlndCmdMagFiltSV2_MtrNm_M_Str;
	STATIC VAR(LPF32KSV_Str, AP_WHLIMBREJ_VAR_NOINIT) WhlSpdRFiltSV_RadpSec_M_Str;
	STATIC VAR(LPF32KSV_Str, AP_WHLIMBREJ_VAR_NOINIT) WhlSpdLFiltSV_RadpSec_M_Str;
	STATIC VAR(LPF32KSV_Str, AP_WHLIMBREJ_VAR_NOINIT) FiltFreqDiffSV_MtrNm_M_Str;
	STATIC VAR(LPF32KSV_Str, AP_WHLIMBREJ_VAR_NOINIT) TrendSV_MtrNm_M_Str;
	/*FloatingPoint LPF SV declaration end */ 

	#define WHLIMBREJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#include "MemMap.h"
	
	#define WHLIMBREJ_START_SEC_VAR_CLEARED_BOOLEAN
	#include "MemMap.h"
	STATIC VAR(boolean, AP_WHLIMBREJ_VAR_NOINIT) DistMagEnabled_Cnt_M_lgc;
	#define WHLIMBREJ_STOP_SEC_VAR_CLEARED_BOOLEAN
	#include "MemMap.h"
	
	#define WHLIMBREJ_START_SEC_VAR_CLEARED_32
	#include "MemMap.h"
	
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) xRefDelayR_RadpSec_M_f32[41];
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) xRefDelayL_RadpSec_M_f32[41];
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) xRefSVR_Uls_M_f32[41];
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) xRefSVL_Uls_M_f32[41];
	STATIC VAR(uint32, AP_WHLIMBREJ_VAR_NOINIT) WIREnTime_mS_M_u32p0;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) PrevCalcEnable_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) PrevEnable_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) PrevHwTrq_HwNm_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) UGRRDelay1_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) UGRLDelay1_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) UGRRDelay2_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) UGRLDelay2_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) Stage1SV1_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) Stage1SV2_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) Stage2SV1_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) Stage2SV2_Uls_M_f32;
	STATIC VAR(uint32, AP_WHLIMBREJ_VAR_NOINIT) TrndThrStartTime_mS_M_u32p0;
	STATIC VAR(uint32, AP_WHLIMBREJ_VAR_NOINIT) TrndThr2StartTime_mS_M_u32p0;
	STATIC VAR(uint32, AP_WHLIMBREJ_VAR_NOINIT) WhlSpdCorrFltTime_mS_M_u32p0;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) RtLmtCurrMagR_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) RtLmtCurrMagL_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) EnabledComp_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) FreqEstAvg_Hz_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) FreqDiagUGRDelay1_Uls_M_f32;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) FreqDiagUGRDelay2_Uls_M_f32;
	STATIC VAR(uint32, AP_WHLIMBREJ_VAR_NOINIT) FrqDiagStartTime_mS_M_u32p0;
	STATIC VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) WIRCmdMag_MtrNm_M_f32;
	STATIC volatile VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) LMSOutR_Uls_D_f32;
	STATIC volatile VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) LMSOutL_Uls_D_f32;
	STATIC volatile VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) FiltWhlSpdR_RadpSec_D_f32;
	STATIC volatile VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) FiltWhlSpdL_RadpSec_D_f32;
	STATIC volatile VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) FiltWhlSpdRScld_RadpSec_D_f32;
	STATIC volatile VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) FiltWhlSpdLScld_RadpSec_D_f32;
	STATIC volatile VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) CurrMagR_Uls_D_f32;
	STATIC volatile VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) CurrMagL_Uls_D_f32;
	STATIC volatile VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) CancelTrqOutput_MtrNm_D_f32;
	STATIC volatile VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) WhlSpdCorrPct_Pct_D_f32;
	STATIC volatile VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) ScaleL_Uls_D_f32;
	STATIC volatile VAR(float32, AP_WHLIMBREJ_VAR_NOINIT) ScaleR_Uls_D_f32;



	#define WHLIMBREJ_STOP_SEC_VAR_CLEARED_32
	#include "MemMap.h"

	#define WHLIMBREJ_START_SEC_VAR_CLEARED_16
	#include "MemMap.h"
	
	STATIC VAR(uint16, AP_WHLIMBREJ_VAR_NOINIT) WhlImbFltStatus_Cnt_M_b16;
	STATIC VAR(uint16, AP_WHLIMBREJ_VAR_NOINIT) MaxMagErrorAcc_Cnt_M_u16;

	#define WHLIMBREJ_STOP_SEC_VAR_CLEARED_16
	#include "MemMap.h"

	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlSpdCorrelationCheck(	VAR(float32, AUTOMATIC) WhlSpdLeft_Hz_T_f32, 
																					VAR(float32, AUTOMATIC) WhlSpdRight_Hz_T_f32);
	
	STATIC INLINE FUNC(boolean, RTE_AP_WHLIMBREJ_APPL_CODE) WhlSpdInRange(	VAR(float32, AUTOMATIC) WhlSpd_Hz_T_f32);

	STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) WIRActRejCmd(	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32,
																			VAR(float32, AUTOMATIC) WhlSpdLeft_Hz_T_f32,
																			VAR(float32, AUTOMATIC) WhlSpdRight_Hz_T_f32,
																			VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
																			VAR(boolean, AUTOMATIC) VehSpdValid_Cnt_T_lgc,
																			VAR(boolean, AUTOMATIC) WIRDisable_Cnt_T_lgc,
																			VAR(boolean, AUTOMATIC) WIRMfgEnable_Cnt_T_lgc);
																			
	STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) UGRFilter_f32(	VAR(float32, AUTOMATIC) UGRInput_Uls_T_f32,
																			VAR(float32, AUTOMATIC) WhlFreqEst_Hz_T_f32,
																			VAR(float32, AUTOMATIC) UGRPoleMag_Uls_T_f32,
																			P2VAR(float32, AUTOMATIC, AUTOMATIC) UGRDelay1_Ptr_T_f32,
																			P2VAR(float32, AUTOMATIC, AUTOMATIC) UGRDelay2_Ptr_T_f32);

	STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) CalcMinusA1Term(VAR(float32, AUTOMATIC) PoleMag_Uls_T_f32,
																			VAR(float32, AUTOMATIC) WhlFreqEst_Hz_T_f32);

	STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) ResFilter(	VAR(float32, AUTOMATIC) ResFilterIn_Uls_T_f32,
																		VAR(float32, AUTOMATIC) ResFiltTermMinA1_Uls_T_f32, 
																		VAR(float32, AUTOMATIC) ResFiltTermA2_Uls_T_f32, 
																		P2VAR(float32, AUTOMATIC, AUTOMATIC) UGRDelay1_Ptr_T_f32, 
																		P2VAR(float32, AUTOMATIC, AUTOMATIC) UGRDelay2_Ptr_T_f32);
																																																																								
	STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) DetermineEnabledAmount(	VAR(float32, AUTOMATIC) FreqEstAvg_Hz_T_f32, 
																					VAR(float32, AUTOMATIC) FiltWhlSpdR_RadpSec_T_f32, 
																					VAR(float32, AUTOMATIC) FiltWhlSpdL_RadpSec_T_f32,
																					VAR(boolean, AUTOMATIC) VehSpdValid_Cnt_T_lgc,
																					VAR(boolean, AUTOMATIC) WIRDisable_Cnt_T_lgc,
																					VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
																					VAR(boolean, AUTOMATIC) WIRMfgEnable_Cnt_T_lgc);

	STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) EnableCalc(	VAR(float32, AUTOMATIC) FreqEstAvg_Hz_T_f32, 
																		VAR(float32, AUTOMATIC) FiltWhlSpdR_RadpSec_T_f32, 
																		VAR(float32, AUTOMATIC) FiltWhlSpdL_RadpSec_T_f32,
																		VAR(boolean, AUTOMATIC) VehSpdValid_Cnt_T_lgc,
																		VAR(boolean, AUTOMATIC) WIRDisable_Cnt_T_lgc,
																		VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
																		VAR(boolean, AUTOMATIC) WIRMfgEnable_Cnt_T_lgc);
																		
	STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) CalcDistMag(	VAR(float32, AUTOMATIC) CurrMag_Uls_T_f32,
																			VAR(float32, AUTOMATIC) Peak_Uls_T_f32, 
																			VAR(float32, AUTOMATIC) FreqEstAvg_Hz_T_f32);

	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) ApplyAutoScale(	P2VAR(float32, AUTOMATIC, AUTOMATIC) FiltWhlSpdR_Ptr_T_f32,
																			P2VAR(float32, AUTOMATIC, AUTOMATIC) FiltWhlSpdL_Ptr_T_f32,
																			VAR(float32, AUTOMATIC) EnabledComp_Uls_T_f32);		
																			
	STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) LMSFilt_f32(VAR(float32, AUTOMATIC) Enable_Uls_T_f32, 
																		VAR(float32, AUTOMATIC) PrevEpsilon_Uls_T_f32, 
																		VAR(float32, AUTOMATIC) xRef_Uls_T_f32, 
																		VAR(float32, AUTOMATIC) AdaptiveMu_Uls_T_f32, 
																		VAR(float32, AUTOMATIC) xRefDelay_Uls_T_f32[], 
																		VAR(float32, AUTOMATIC) xRefStateVar_Uls_T_f32[], 
																		VAR(uint16, AUTOMATIC) NTaps_Cnt_T_u16);

	STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) PhaseAdjust_f32(	VAR(float32, AUTOMATIC) PhaseAdjInput_Uls_T_f32, 
																				VAR(float32, AUTOMATIC) FreqEstAvg_Hz_T_f32);
																				
	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) CalcFilterCoeff(	VAR(float32, AUTOMATIC) Phase_Rad_T_f32,
																			VAR(float32, AUTOMATIC) FreqEstAvg_Hz_T_f32, 
																			P2VAR(float32, AUTOMATIC, AUTOMATIC) ZeroCoeff_Ptr_T_f32,
																			P2VAR(float32, AUTOMATIC, AUTOMATIC) PoleCoeff_Ptr_T_f32,
																			P2VAR(float32, AUTOMATIC, AUTOMATIC) GainCoeff_Ptr_T_f32,
																			P2VAR(float32, AUTOMATIC, AUTOMATIC) InvMag_Ptr_T_f32);

	STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) LeadLagFilter(	VAR(float32, AUTOMATIC) FilterInput_Uls_T_f32,
																			VAR(float32, AUTOMATIC) ZeroCoeff_Uls_T_f32,
																			VAR(float32, AUTOMATIC) PoleCoeff_Uls_T_f32,
																			VAR(float32, AUTOMATIC) GainCoeff_Uls_T_f32,
																			VAR(float32, AUTOMATIC) InvMag_Uls_T_f32,
																			P2VAR(float32, AUTOMATIC, AUTOMATIC) LeadLagSV1_Ptr_T_f32,
																			P2VAR(float32, AUTOMATIC, AUTOMATIC) LeadLagSV2_Ptr_T_f32);

	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WIRDiagnostics(	VAR(float32, AUTOMATIC) WhlImbRejCmd_MtrNm_T_f32);

	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) DiagnoseCmdMag(	VAR(float32, AUTOMATIC) InputCommand_MtrNm_T_f32);

	STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) CalcCmdAmplitude(	VAR(float32, AUTOMATIC) InputCommand_MtrNm_T_f32, 
																				P2VAR(LPF32KSV_Str, AUTOMATIC, AUTOMATIC) CmdMagFiltSV1_Ptr_T_Str,
																				P2VAR(LPF32KSV_Str, AUTOMATIC, AUTOMATIC) CmdMagFiltSV2_Ptr_T_Str);
																				
	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) DiagnoseFreq(	VAR(float32, AUTOMATIC) WhlImbRejCmd_MtrNm_T_f32);
																		
	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) DiagnoseDCTrend(	VAR(float32, AUTOMATIC) InputCommand_MtrNm_T_f32);																																																																																																																											

	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) ProcessStatusBits(	void);

	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) UpdateFaultBits(	P2VAR(WIRDiagInfo_Str, AUTOMATIC, AUTOMATIC) DiagInfo_Ptr_T_Str,
																			VAR(uint16, AUTOMATIC) FaultMask_Cnt_T_b16,
																			VAR(uint16, AUTOMATIC) RecoveryFaultMask_Cnt_T_b16,
																			P2VAR(uint16, AUTOMATIC, AUTOMATIC) WhlImbFltStatus_Ptr_T_b16);
																			
	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) LogCompActivity(	VAR(float32, AUTOMATIC) WIRCmdMag_MtrNm_T_f32);

	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) CheckCompPers(	void);

	STATIC FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WIRFltRecovery(	P2VAR(WIRDiagInfo_Str, AUTOMATIC, AUTOMATIC) DiagInfo_Ptr_T_Str,
																	VAR(uint8, AUTOMATIC) MaxFltRecLmt_Cnt_T_u8,
																	VAR(float32, AUTOMATIC) FltRecDly_Min_T_f32);

	STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) ResetWIRAlgorithm(void);

																
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
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1u)
 *   NTC_Num_FlashECCCorr (2u)
 *   NTC_Num_FlashECCMemFlt (3u)
 *   NTC_Num_FlashCRCMemFault (4u)
 *   NTC_Num_EEPROMDiag (10u)
 *   NTC_Num_EEPROMDiagMtrStr (11u)
 *   NTC_Num_PriSnsrTrqStorFlt (12u)
 *   NTC_Num_EEPROMDiagPosTrimStr (13u)
 *   NTC_Num_SecSnsrTrqStorFlt (14u)
 *   NTC_Num_EEPROMDiagPolarityStr (15u)
 *   NTC_Num_RAMDiag_GeneralFlt (16u)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17u)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18u)
 *   NTC_Num_RAMDiag_ECCMemFlt (19u)
 *   NTC_Num_RAMDiag_CRCMemFlt (20u)
 *   NTC_Num_RAMDiag_VIMRamFlt (23u)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24u)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25u)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26u)
 *   NTC_Num_RAMDiag_DCANRamFault (27u)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28u)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29u)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30u)
 *   NTC_Num_CPU_RegVer (32u)
 *   NTC_Num_CPU_CoreInitFlt (33u)
 *   NTC_Num_CPU_CoreRunTimeFlt (34u)
 *   NTC_Num_CPU_ClockMon (35u)
 *   NTC_Num_CPU_eFuseFlt (36u)
 *   NTC_Num_CPU_MPUViolation (37u)
 *   NTC_Num_CPU_FactPrcsErr (40u)
 *   NTC_Num_PropExeDiag_InitDiag (41u)
 *   NTC_Num_PrgFlwDeadlnFlt (42u)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43u)
 *   NTC_Num_PropExeDiag_COPTimeout (44u)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48u)
 *   NTC_Num_PropExeDiag_DataAbort (49u)
 *   NTC_Num_PerDiag_ADC1Flt (50u)
 *   NTC_Num_PerDiag_ADC2Flt (51u)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52u)
 *   NTC_Num_PerDiag_IllegalAccess (53u)
 *   NTC_Num_PerDiag_DMAFlt (54u)
 *   NTC_Num_PerDiag_CPUWarning (63u)
 *   NTC_Num_TmpMonFunc (64u)
 *   NTC_Num_TmpMonRunTimeFlt (65u)
 *   NTC_Num_PowerRelayInitFlt (66u)
 *   NTC_Num_PrechargeFailure (67u)
 *   NTC_Num_PowerRelayRunFlt (68u)
 *   NTC_Num_Thermistor (69u)
 *   NTC_Num_RefSupplyVltg (70u)
 *   NTC_Num_TrcvrInterfaceFlt (71u)
 *   NTC_Num_CPUSupplyOvervoltage (72u)
 *   NTC_Num_GateDrvFlt (77u)
 *   NTC_Num_OnStateSingleFET (78u)
 *   NTC_Num_OnStateMultiFET (79u)
 *   NTC_Num_PhaseVoltageVerf (80u)
 *   NTC_Num_PhaseDscnt (81u)
 *   NTC_Num_DigPhaseVoltageVerf (82u)
 *   NTC_Num_PhaseDscntFailedDisable (83u)
 *   NTC_Num_CurrentMeas1 (84u)
 *   NTC_Num_CurrentMeas2 (85u)
 *   NTC_Num_CurrentMeasCrossChk (86u)
 *   NTC_Num_PDSupplyOverVoltage (87u)
 *   NTC_Num_ChargePumpUnderVoltage (88u)
 *   NTC_Num_HwTrqSensor (96u)
 *   NTC_Num_AnaVsDigHwTrq (97u)
 *   NTC_Num_TrqSensorRecoveryFlt (98u)
 *   NTC_Num_TrqSensorScaleInvalid (100u)
 *   NTC_Num_T1vsT2 (101u)
 *   NTC_Num_T1OutofRange (102u)
 *   NTC_Num_T2OutofRange (103u)
 *   NTC_Num_DigT1vsT2 (104u)
 *   NTC_Num_DigT1OutofRange (105u)
 *   NTC_Num_DigT2OutofRange (106u)
 *   NTC_Num_RedT1vsT2 (107u)
 *   NTC_Num_HWASensorRel (110u)
 *   NTC_Num_HWASensorAbs (111u)
 *   NTC_Num_PriMSB_SinCosCorr (112u)
 *   NTC_Num_SecMSB_SinCosCorr (113u)
 *   NTC_Num_PriVsSec_SinCosCorr (114u)
 *   NTC_Num_DigMSBFlt (115u)
 *   NTC_Num_MtrVelFlt (116u)
 *   NTC_Num_HWAtoMtrAngleCorr (117u)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118u)
 *   NTC_Num_TurnCntr_PosLoss (128u)
 *   NTC_Num_TurnCntr_MicroProcFlt (129u)
 *   NTC_Num_TurnCntr_SensorPosFlt (130u)
 *   NTC_Num_TurnCntr_SpiComFlt (131u)
 *   NTC_Num_TurnCntr_HighQuiescCur (132u)
 *   NTC_Num_TurnCntr_MainResets (133u)
 *   NTC_Num_KinematicIntDiag (144u)
 *   NTC_Num_HighFriction (145u)
 *   NTC_Num_DutyCycleExceeded (148u)
 *   NTC_Num_AbsTempThermLimit (149u)
 *   NTC_Num_LatchActive (160u)
 *   NTC_Num_OpTrqVsHwTrq (168u)
 *   NTC_Num_CurrentReas (169u)
 *   NTC_Num_OpVoltage (176u)
 *   NTC_Num_ExVoltageLow (177u)
 *   NTC_Num_ReducedAsstLowVoltage (178u)
 *   NTC_Num_ExVoltageHigh (180u)
 *   NTC_Num_OpVoltageOvrMax (181u)
 *   NTC_Num_IgnConfDiag (184u)
 *   NTC_Num_TurnCntr_LowBattery (185u)
 *   NTC_Num_EEPROMCloseFailed (191u)
 *   NTC_Num_SigPath1CrossChk (192u)
 *   NTC_Num_SigPath2CrossChk (193u)
 *   NTC_Num_SigPath3CrossChk (194u)
 *   NTC_Num_SigPath4CrossChk (195u)
 *   NTC_Num_SigPath5CrossChk (196u)
 *   NTC_Num_DampingFWReached (197u)
 *   NTC_Num_AssistFWReached (198u)
 *   NTC_Num_ReturnFWReached (199u)
 *   NTC_Num_DampingFWFltMode (200u)
 *   NTC_Num_AssistFWFltMode (201u)
 *   NTC_Num_VBICFltMode (202u)
 *   NTC_Num_StaMdsSysC (203u)
 *   NTC_NUM_SysFailureForRotVel (204u)
 *   NTC_NUM_SysFailForRedntRotVel (205u)
 *   NTC_Num_SysFailureForTrqSnsr (206u)
 *   NTC_Num_SysFailureForRedTrqSnsr (207u)
 *   NTC_NUM_SysFailureForCtrlVolt (209u)
 *   NTC_Num_GlblSgnlOvrwrtDet (223u)
 *   NTC_Num_VLF_00 (224u)
 *   NTC_Num_VLF_01 (225u)
 *   NTC_Num_VLF_02 (226u)
 *   NTC_Num_VLF_03 (227u)
 *   NTC_Num_VLF_04 (228u)
 *   NTC_Num_VLF_05 (229u)
 *   NTC_Num_VLF_06 (230u)
 *   NTC_Num_VLF_07 (231u)
 *   NTC_Num_VLF_08 (232u)
 *   NTC_Num_VLF_09 (233u)
 *   NTC_Num_VLF_10 (234u)
 *   NTC_Num_VLF_11 (235u)
 *   NTC_Num_VLF_12 (236u)
 *   NTC_Num_VLF_13 (237u)
 *   NTC_Num_VLF_14 (238u)
 *   NTC_Num_VLF_15 (239u)
 *   NTC_Num_VLF_16 (240u)
 *   NTC_Num_VLF_17 (241u)
 *   NTC_Num_VLF_18 (242u)
 *   NTC_Num_VLF_19 (243u)
 *   NTC_Num_VLF_20 (244u)
 *   NTC_Num_VLF_21 (245u)
 *   NTC_Num_VLF_22 (246u)
 *   NTC_Num_VLF_23 (247u)
 *   NTC_Num_VLF_24 (248u)
 *   NTC_Num_VLF_25 (249u)
 *   NTC_Num_VLF_26 (250u)
 *   NTC_Num_VLF_27 (251u)
 *   NTC_Num_VLF_28 (252u)
 *   NTC_Num_VLF_29 (253u)
 *   NTC_Num_VLF_30 (254u)
 *   NTC_Num_VLF_31 (255u)
 *   NTC_Num_BusOffCh1 (256u)
 *   NTC_Num_BusOffCh1NodeMute (257u)
 *   NTC_Num_Node1AAbsent (258u)
 *   NTC_Num_Node1AFaulty (259u)
 *   NTC_Num_Node1BAbsent (260u)
 *   NTC_Num_Node1BFaulty (261u)
 *   NTC_Num_Node1CAbsent (262u)
 *   NTC_Num_Node1CFaulty (263u)
 *   NTC_Num_Node1DAbsent (264u)
 *   NTC_Num_Node1DFaulty (265u)
 *   NTC_Num_Node1EAbsent (266u)
 *   NTC_Num_Node1EFaulty (267u)
 *   NTC_Num_Node1FAbsent (268u)
 *   NTC_Num_Node1FFaulty (269u)
 *   NTC_Num_Node1GAbsent (270u)
 *   NTC_Num_Node1GFaulty (271u)
 *   NTC_Num_BusOffCh2 (272u)
 *   NTC_Num_Node2AAbsent (273u)
 *   NTC_Num_Node2AFaulty (274u)
 *   NTC_Num_Node2BAbsent (275u)
 *   NTC_Num_Node2BFaulty (276u)
 *   NTC_Num_Node2CAbsent (277u)
 *   NTC_Num_Node2CFaulty (278u)
 *   NTC_Num_Node2DAbsent (279u)
 *   NTC_Num_Node2DFaulty (280u)
 *   NTC_Num_Node2EAbsent (281u)
 *   NTC_Num_Node2EFaulty (282u)
 *   NTC_Num_Node2FAbsent (283u)
 *   NTC_Num_Node2FFaulty (284u)
 *   NTC_Num_Node2GAbsent (285u)
 *   NTC_Num_Node2GFaulty (286u)
 *   NTC_Num_InvalidMsg_M (288u)
 *   NTC_Num_MissingMsg_M (289u)
 *   NTC_Num_CRCFltMsg_M (290u)
 *   NTC_Num_PgrsCntFltMsg_M (291u)
 *   NTC_Num_DataRngFltMsg_M (292u)
 *   NTC_Num_DataRateFltMsg_M (293u)
 *   NTC_Num_DataOtherFltMsg_M (294u)
 *   NTC_Num_InvalidMsg_N (296u)
 *   NTC_Num_MissingMsg_N (297u)
 *   NTC_Num_CRCFltMsg_N (298u)
 *   NTC_Num_PgrsCntFltMsg_N (299u)
 *   NTC_Num_DataRngFltMsg_N (300u)
 *   NTC_Num_DataRateFltMsg_N (301u)
 *   NTC_Num_DataOtherFltMsg_N (302u)
 *   NTC_Num_InvalidMsg_O (304u)
 *   NTC_Num_MissingMsg_O (305u)
 *   NTC_Num_CRCFltMsg_O (306u)
 *   NTC_Num_PgrsCntFltMsg_O (307u)
 *   NTC_Num_DataRngFltMsg_O (308u)
 *   NTC_Num_DataRateFltMsg_O (309u)
 *   NTC_Num_DataOtherFltMsg_O (310u)
 *   NTC_Num_InvalidMsg_P (312u)
 *   NTC_Num_MissingMsg_P (313u)
 *   NTC_Num_CRCFltMsg_P (314u)
 *   NTC_Num_PgrsCntFltMsg_P (315u)
 *   NTC_Num_DataRngFltMsg_P (316u)
 *   NTC_Num_DataRateFltMsg_P (317u)
 *   NTC_Num_DataOtherFltMsg_P (318u)
 *   NTC_Num_InvalidMsg_Q (320u)
 *   NTC_Num_MissingMsg_Q (321u)
 *   NTC_Num_CRCFltMsg_Q (322u)
 *   NTC_Num_PgrsCntFltMsg_Q (323u)
 *   NTC_Num_DataRngFltMsg_Q (324u)
 *   NTC_Num_DataRateFltMsg_Q (325u)
 *   NTC_Num_DataOtherFltMsg_Q (326u)
 *   NTC_Num_InvalidMsg_R (328u)
 *   NTC_Num_MissingMsg_R (329u)
 *   NTC_Num_CRCFltMsg_R (330u)
 *   NTC_Num_PgrsCntFltMsg_R (331u)
 *   NTC_Num_DataRngFltMsg_R (332u)
 *   NTC_Num_DataRateFltMsg_R (333u)
 *   NTC_Num_DataOtherFltMsg_R (334u)
 *   NTC_Num_InvalidMsg_S (336u)
 *   NTC_Num_MissingMsg_S (337u)
 *   NTC_Num_CRCFltMsg_S (338u)
 *   NTC_Num_PgrsCntFltMsg_S (339u)
 *   NTC_Num_DataRngFltMsg_S (340u)
 *   NTC_Num_DataRateFltMsg_S (341u)
 *   NTC_Num_DataOtherFltMsg_S (342u)
 *   NTC_Num_InvalidMsg_T (344u)
 *   NTC_Num_MissingMsg_T (345u)
 *   NTC_Num_CRCFltMsg_T (346u)
 *   NTC_Num_PgrsCntFltMsg_T (347u)
 *   NTC_Num_DataRngFltMsg_T (348u)
 *   NTC_Num_DataRateFltMsg_T (349u)
 *   NTC_Num_DataOtherFltMsg_T (350u)
 *   NTC_Num_InvalidMsg_U (352u)
 *   NTC_Num_MissingMsg_U (353u)
 *   NTC_Num_CRCFltMsg_U (354u)
 *   NTC_Num_PgrsCntFltMsg_U (355u)
 *   NTC_Num_DataRngFltMsg_U (356u)
 *   NTC_Num_DataRateFltMsg_U (357u)
 *   NTC_Num_DataOtherFltMsg_U (358u)
 *   NTC_Num_InvalidMsg_V (360u)
 *   NTC_Num_MissingMsg_V (361u)
 *   NTC_Num_CRCFltMsg_V (362u)
 *   NTC_Num_PgrsCntFltMsg_V (363u)
 *   NTC_Num_DataRngFltMsg_V (364u)
 *   NTC_Num_DataRateFltMsg_V (365u)
 *   NTC_Num_DataOtherFltMsg_V (366u)
 *   NTC_Num_InvalidMsg_W (368u)
 *   NTC_Num_MissingMsg_W (369u)
 *   NTC_Num_CRCFltMsg_W (370u)
 *   NTC_Num_PgrsCntFltMsg_W (371u)
 *   NTC_Num_DataRngFltMsg_W (372u)
 *   NTC_Num_DataRateFltMsg_W (373u)
 *   NTC_Num_DataOtherFltMsg_W (374u)
 *   NTC_Num_InvalidMsg_X (376u)
 *   NTC_Num_MissingMsg_X (377u)
 *   NTC_Num_CRCFltMsg_X (378u)
 *   NTC_Num_PgrsCntFltMsg_X (379u)
 *   NTC_Num_DataRngFltMsg_X (380u)
 *   NTC_Num_DataRateFltMsg_X (381u)
 *   NTC_Num_DataOtherFltMsg_X (382u)
 *   NTC_Num_InvalidMsg_Y (384u)
 *   NTC_Num_MissingMsg_Y (385u)
 *   NTC_Num_CRCFltMsg_Y (386u)
 *   NTC_Num_PgrsCntFltMsg_Y (387u)
 *   NTC_Num_DataRngFltMsg_Y (388u)
 *   NTC_Num_DataRateFltMsg_Y (389u)
 *   NTC_Num_DataOtherFltMsg_Y (390u)
 *   NTC_Num_InvalidMsg_Z (392u)
 *   NTC_Num_MissingMsg_Z (393u)
 *   NTC_Num_CRCFltMsg_Z (394u)
 *   NTC_Num_PgrsCntFltMsg_Z (395u)
 *   NTC_Num_DataRngFltMsg_Z (396u)
 *   NTC_Num_DataRateFltMsg_Z (397u)
 *   NTC_Num_DataOtherFltMsg_Z (398u)
 *   NTC_Num_InvalidMsg_AA (400u)
 *   NTC_Num_MissingMsg_AA (401u)
 *   NTC_Num_CRCFltMsg_AA (402u)
 *   NTC_Num_PgrsCntFltMsg_AA (403u)
 *   NTC_Num_DataRngFltMsg_AA (404u)
 *   NTC_Num_DataRateFltMsg_AA (405u)
 *   NTC_Num_DataOtherFltMsg_AA (406u)
 *   NTC_Num_InvalidMsg_AB (408u)
 *   NTC_Num_MissingMsg_AB (409u)
 *   NTC_Num_CRCFltMsg_AB (410u)
 *   NTC_Num_PgrsCntFltMsg_AB (411u)
 *   NTC_Num_DataRngFltMsg_AB (412u)
 *   NTC_Num_DataRateFltMsg_AB (413u)
 *   NTC_Num_DataOtherFltMsg_AB (414u)
 *   NTC_Num_InvalidMsg_AC (416u)
 *   NTC_Num_MissingMsg_AC (417u)
 *   NTC_Num_CRCFltMsg_AC (418u)
 *   NTC_Num_PgrsCntFltMsg_AC (419u)
 *   NTC_Num_DataRngFltMsg_AC (420u)
 *   NTC_Num_DataRateFltMsg_AC (421u)
 *   NTC_Num_DataOtherFltMsg_AC (422u)
 *   NTC_Num_InvalidMsg_AD (424u)
 *   NTC_Num_MissingMsg_AD (425u)
 *   NTC_Num_CRCFltMsg_AD (426u)
 *   NTC_Num_PgrsCntFltMsg_AD (427u)
 *   NTC_Num_DataRngFltMsg_AD (428u)
 *   NTC_Num_DataRateFltMsg_AD (429u)
 *   NTC_Num_DataOtherFltMsg_AD (430u)
 *   NTC_Num_InvalidMsg_AE (432u)
 *   NTC_Num_MissingMsg_AE (433u)
 *   NTC_Num_CRCFltMsg_AE (434u)
 *   NTC_Num_PgrsCntFltMsg_AE (435u)
 *   NTC_Num_DataRngFltMsg_AE (436u)
 *   NTC_Num_DataRateFltMsg_AE (437u)
 *   NTC_Num_DataOtherFltMsg_AE (438u)
 *   NTC_Num_InvalidMsg_AF (440u)
 *   NTC_Num_MissingMsg_AF (441u)
 *   NTC_Num_CRCFltMsg_AF (442u)
 *   NTC_Num_PgrsCntFltMsg_AF (443u)
 *   NTC_Num_DataRngFltMsg_AF (444u)
 *   NTC_Num_DataRateFltMsg_AF (445u)
 *   NTC_Num_DataOtherFltMsg_AF (446u)
 *   NTC_Num_InvalidMsg_AG (448u)
 *   NTC_Num_MissingMsg_AG (449u)
 *   NTC_Num_CRCFltMsg_AG (450u)
 *   NTC_Num_PgrsCntFltMsg_AG (451u)
 *   NTC_Num_DataRngFltMsg_AG (452u)
 *   NTC_Num_DataRateFltMsg_AG (453u)
 *   NTC_Num_DataOtherFltMsg_AG (454u)
 *   NTC_Num_InvalidMsg_AH (456u)
 *   NTC_Num_MissingMsg_AH (457u)
 *   NTC_Num_CRCFltMsg_AH (458u)
 *   NTC_Num_PgrsCntFltMsg_AH (459u)
 *   NTC_Num_DataRngFltMsg_AH (460u)
 *   NTC_Num_DataRateFltMsg_AH (461u)
 *   NTC_Num_DataOtherFltMsg_AH (462u)
 *   NTC_Num_FlexrayCommunicationError (465u)
 *   NTC_Num_SysConsistencyVerf (496u)
 *   NTC_Num_ConfigMisMatch (497u)
 *   NTC_Num_CalNotPrgmd (498u)
 *   NTC_Num_EOLVehTunNtPerf (501u)
 *   NTC_Num_MtrSensorNotTrimmed (502u)
 *   NTC_Num_HWASensorNotTrimmed (504u)
 *   NTC_Num_HWASensorTrimNoAttempt (505u)
 *   NTC_Num_TrqSensorScaleNotSet (506u)
 *   NTC_Num_TrqSensorNotTrimmed (507u)
 *   NTC_Num_DigTrqSensorScaleNotSet (509u)
 *   NTC_Num_DigTrqSensorNotTrimmed (510u)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0u)
 *   NTC_STATUS_FAILED (1u)
 *   NTC_STATUS_PREPASSED (2u)
 *   NTC_STATUS_PREFAILED (3u)
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_2PI_ULS_F32 = 6.2831853071796
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_WHLIMBREJ_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WhlImbRej_Init1
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

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WhlImbRej_Init1
 *********************************************************************************************************************/

	ResetWIRAlgorithm();
	UGRRDelay1_Uls_M_f32 = 0.0F;
	UGRLDelay1_Uls_M_f32 = 0.0F;
	UGRRDelay2_Uls_M_f32 = 0.0F;
	UGRLDelay2_Uls_M_f32 = 0.0F;
	CheckCompPers();



	/* Initialisation for Floating point LPF SV, K start here */
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_WhlSpdLPFKn_Hz_f32, D_2MS_SEC_F32, &WhlFreqRFiltSV_Hz_M_str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_WhlSpdLPFKn_Hz_f32, D_2MS_SEC_F32, &WhlFreqLFiltSV_Hz_M_str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_BlndCmdMagLPFKn1_Hz_f32, D_2MS_SEC_F32, &BlndCmdMagFiltSV1_MtrNm_M_Str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_BlndCmdMagLPFKn2_Hz_f32, D_2MS_SEC_F32, &BlndCmdMagFiltSV2_MtrNm_M_Str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_CmdMagLPFKn1_Hz_f32, D_2MS_SEC_F32, &CmdMagFiltSV1_MtrNm_M_Str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_CmdMagLPFKn2_Hz_f32, D_2MS_SEC_F32, &CmdMagFiltSV2_MtrNm_M_Str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_DistMagLPFKn_Hz_f32, D_2MS_SEC_F32, &WhlSpdRFiltSV_RadpSec_M_Str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_DistMagLPFKn_Hz_f32, D_2MS_SEC_F32, &WhlSpdLFiltSV_RadpSec_M_Str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_FreqDiagLPFKn_Hz_f32, D_2MS_SEC_F32, &FiltFreqDiffSV_MtrNm_M_Str);
	LPF_Init_f32_m(D_ZERO_ULS_F32, k_WIRDCTrendLPFKn_Hz_f32, D_2MS_SEC_F32, &TrendSV_MtrNm_M_Str);


	/* Initialisation for Floating point LPF SV, K end here */










/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WhlImbRej_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <DISABLE, OFF, WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_WhlImbRej_Per1_DiagStsWIRDisable_Cnt_lgc(void)
 *   Float Rte_IRead_WhlImbRej_Per1_HwTrq_HwNm_f32(void)
 *   Float Rte_IRead_WhlImbRej_Per1_QualWhlFreqL_Hz_f32(void)
 *   Float Rte_IRead_WhlImbRej_Per1_QualWhlFreqR_Hz_f32(void)
 *   Boolean Rte_IRead_WhlImbRej_Per1_VehSpdValid_Cnt_lgc(void)
 *   Float Rte_IRead_WhlImbRej_Per1_VehSpd_Kph_f32(void)
 *   Boolean Rte_IRead_WhlImbRej_Per1_WIRMfgEnable_Cnt_lgc(void)
 *   Boolean Rte_IRead_WhlImbRej_Per1_WhlFreqQualified_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_WhlImbRej_Per1_WIRCmdAmpBlnd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_WhlImbRej_Per1_WIRCmdAmpBlnd_MtrNm_f32(void)
 *   void Rte_IWrite_WhlImbRej_Per1_WhlImbRejCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_WhlImbRej_Per1_WhlImbRejCmd_MtrNm_f32(void)
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
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WhlImbRej_Per1
 *********************************************************************************************************************/
	VAR(float32, AUTOMATIC) QualWhlFreqL_Hz_T_f32;
	VAR(float32, AUTOMATIC) QualWhlFreqR_Hz_T_f32;
	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32;
	VAR(float32, AUTOMATIC) WhlImbRejCmd_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) WIRCmdAmpBlnd_MtrNm_T_f32;
	VAR(boolean, AUTOMATIC) WIRDisable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) WIRMfgEnable_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) WhlFreqQualified_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;
	VAR(boolean, AUTOMATIC) VehSpdValid_Cnt_T_lgc;
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_WhlImbRej_Per1_CP0_CheckpointReached();

	VehSpdValid_Cnt_T_lgc = Rte_IRead_WhlImbRej_Per1_VehSpdValid_Cnt_lgc();
	HwTrq_HwNm_T_f32 = Rte_IRead_WhlImbRej_Per1_HwTrq_HwNm_f32();
	QualWhlFreqL_Hz_T_f32 = Rte_IRead_WhlImbRej_Per1_QualWhlFreqL_Hz_f32();
	QualWhlFreqR_Hz_T_f32 = Rte_IRead_WhlImbRej_Per1_QualWhlFreqR_Hz_f32();
	VehSpd_Kph_T_f32 = Rte_IRead_WhlImbRej_Per1_VehSpd_Kph_f32();
	WIRDisable_Cnt_T_lgc = Rte_IRead_WhlImbRej_Per1_DiagStsWIRDisable_Cnt_lgc();
	WIRMfgEnable_Cnt_T_lgc = Rte_IRead_WhlImbRej_Per1_WIRMfgEnable_Cnt_lgc();
	WhlFreqQualified_Cnt_T_lgc = Rte_IRead_WhlImbRej_Per1_WhlFreqQualified_Cnt_lgc();
	
	if (FALSE == WhlFreqQualified_Cnt_T_lgc)
	{
		QualFlt_Cnt_M_Str.Failed_Cnt_lgc = TRUE;
	}
	
	WhlSpdCorrelationCheck(	QualWhlFreqL_Hz_T_f32, 
							QualWhlFreqR_Hz_T_f32);
		
	WhlImbRejCmd_MtrNm_T_f32 = WIRActRejCmd(	HwTrq_HwNm_T_f32,
												QualWhlFreqL_Hz_T_f32,
												QualWhlFreqR_Hz_T_f32,
												VehSpd_Kph_T_f32,
												VehSpdValid_Cnt_T_lgc,
												WIRDisable_Cnt_T_lgc,
												WIRMfgEnable_Cnt_T_lgc);
	
	CancelTrqOutput_MtrNm_D_f32 = WhlImbRejCmd_MtrNm_T_f32;

	WIRDiagnostics(	WhlImbRejCmd_MtrNm_T_f32);
	
	WhlImbRejCmd_MtrNm_T_f32 = Limit_m(WhlImbRejCmd_MtrNm_T_f32, -k_WhlImbCmdMax_MtrNm_f32, k_WhlImbCmdMax_MtrNm_f32);
	
	/* Compute Amplitude for blending */
	WIRCmdAmpBlnd_MtrNm_T_f32 =  CalcCmdAmplitude(	WhlImbRejCmd_MtrNm_T_f32, 
													&BlndCmdMagFiltSV1_MtrNm_M_Str,
													&BlndCmdMagFiltSV2_MtrNm_M_Str);

	ProcessStatusBits();

	WhlImbRejCmd_MtrNm_T_f32 = Limit_m(WhlImbRejCmd_MtrNm_T_f32, -D_WIRCMDMAX_MTRNM_F32, D_WIRCMDMAX_MTRNM_F32);
	WIRCmdAmpBlnd_MtrNm_T_f32 = Limit_m(WIRCmdAmpBlnd_MtrNm_T_f32, D_ZERO_ULS_F32, D_WIRCMDMAX_MTRNM_F32);

	Rte_IWrite_WhlImbRej_Per1_WIRCmdAmpBlnd_MtrNm_f32(WIRCmdAmpBlnd_MtrNm_T_f32);
	Rte_IWrite_WhlImbRej_Per1_WhlImbRejCmd_MtrNm_f32(WhlImbRejCmd_MtrNm_T_f32);
    /* Configurable End of Runnable Checkpoint */
    Rte_Call_WhlImbRej_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WhlImbRej_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *     and not in Mode(s) <OFF, DISABLE, WARMINIT>
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

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WhlImbRej_Per2
 *********************************************************************************************************************/
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_WhlImbRej_Per2_CP0_CheckpointReached();
	LogCompActivity(WIRCmdMag_MtrNm_M_f32);
	CheckCompPers();
	
	WIRFltRecovery(	&MaxMagFlt_Cnt_M_Str,
					k_MaxMagFltRecLim_Cnt_u8,
					k_MaxMagFltRecDly_Min_f32);
	
	WIRFltRecovery(	&DCTrendFlt_Cnt_M_Str,
					k_DCTrendFltRecLim_Cnt_u8,
					k_DCTrendFltRecDly_Min_f32);
	
	WIRFltRecovery(	&FreqDiagFlt_Cnt_M_Str,
					k_FreqDiagFltRecLim_Cnt_u8,
					k_FreqDiagFltRecDly_Min_f32);
					
	WIRFltRecovery(	&CorrFlt_Cnt_M_Str,
					k_CorrFltRecLim_Cnt_u8,
					k_CorrFltRecDly_Min_f32);
	  
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_WhlImbRej_Per2_CP1_CheckpointReached();
				
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WhlImbRej_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OPERATE>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_WhlImbRej_Per3_WhlImbRejCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_WhlImbRej_Per3_WhlImbRejCmd_MtrNm_f32(void)
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

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_Per3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WhlImbRej_Per3
 *********************************************************************************************************************/
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_WhlImbRej_Per3_CP0_CheckpointReached();
	ResetWIRAlgorithm();
	UGRRDelay1_Uls_M_f32 = 0.0F;
	UGRLDelay1_Uls_M_f32 = 0.0F;
	UGRRDelay2_Uls_M_f32 = 0.0F;
	UGRLDelay2_Uls_M_f32 = 0.0F;
	
	WhlFreqRFiltSV_Hz_M_str.SV_Uls_f32 = 0.0F;
	WhlFreqLFiltSV_Hz_M_str.SV_Uls_f32 = 0.0F;

	Rte_IWrite_WhlImbRej_Per3_WhlImbRejCmd_MtrNm_f32(0.0F);
	/* Configurable End of Runnable Checkpoint */
    Rte_Call_WhlImbRej_Per3_CP1_CheckpointReached();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WhlImbRej_SCom_GetWIRInfo
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetWIRInfo> of PortPrototype <WhlImbRej_SCom>
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void WhlImbRej_SCom_GetWIRInfo(UInt32 *WIRCmpActRng1Ptr_Cnt_u32, UInt32 *WIRCmpActRng2Ptr_Cnt_u32, UInt32 *WIRCmpActRng3Ptr_Cnt_u32, UInt16 *AlgFltStatusPtr_Cnt_b16, Float *WIRMaxCompPtr_Pct_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlImbRej_SCom_GetWIRInfo(P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng1Ptr_Cnt_u32, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng2Ptr_Cnt_u32, P2VAR(UInt32, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRCmpActRng3Ptr_Cnt_u32, P2VAR(UInt16, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) AlgFltStatusPtr_Cnt_b16, P2VAR(Float, AUTOMATIC, RTE_AP_WHLIMBREJ_APPL_VAR) WIRMaxCompPtr_Pct_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WhlImbRej_SCom_GetWIRInfo
 *********************************************************************************************************************/
	*WIRCmpActRng1Ptr_Cnt_u32 = WIRCmpActTyH_Cnt_M_u32[0];
	*WIRCmpActRng2Ptr_Cnt_u32 = WIRCmpActTyH_Cnt_M_u32[1];
	*WIRCmpActRng3Ptr_Cnt_u32 = WIRCmpActTyH_Cnt_M_u32[2];
	*AlgFltStatusPtr_Cnt_b16 = WhlImbFltStatus_Cnt_M_b16;
	*WIRMaxCompPtr_Pct_f32 = WIRMaxCompTyH_Pct_M_f32;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_WHLIMBREJ_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/******************************************************************************
* Name:        WhlSpdCorrelationCheck
* Description: Wheel Speed Correlation Check
******************************************************************************/
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WhlSpdCorrelationCheck(	VAR(float32, AUTOMATIC) WhlSpdLeft_Hz_T_f32, 
																				VAR(float32, AUTOMATIC) WhlSpdRight_Hz_T_f32)
{
	VAR(float32, AUTOMATIC) Correlation_Pct_T_f32;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;
	VAR(boolean, AUTOMATIC) WhlSpdLeftInRng_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) WhlSpdRightInRng_Cnt_T_lgc;
	
	WhlSpdLeftInRng_Cnt_T_lgc = WhlSpdInRange(WhlSpdLeft_Hz_T_f32);
	WhlSpdRightInRng_Cnt_T_lgc = WhlSpdInRange(WhlSpdRight_Hz_T_f32);

	if ((WhlSpdRight_Hz_T_f32 > FLT_EPSILON) && (WhlSpdRight_Hz_T_f32 >= WhlSpdLeft_Hz_T_f32))
	{
		Correlation_Pct_T_f32 = (WhlSpdLeft_Hz_T_f32 / WhlSpdRight_Hz_T_f32) * D_ONEHUNDRED_PCT_F32;
	}
	else if ((WhlSpdLeft_Hz_T_f32 > FLT_EPSILON) && (WhlSpdRight_Hz_T_f32 > FLT_EPSILON))
	{
		Correlation_Pct_T_f32 = (WhlSpdRight_Hz_T_f32 / WhlSpdLeft_Hz_T_f32) * D_ONEHUNDRED_PCT_F32;
	}
	else
	{
		Correlation_Pct_T_f32 = D_ONEHUNDRED_PCT_F32; 											
	}

	WhlSpdCorrPct_Pct_D_f32 = Correlation_Pct_T_f32;

	if ((Correlation_Pct_T_f32 < k_WhlSpdCorrThresh_Pct_f32) && 
		((TRUE == WhlSpdLeftInRng_Cnt_T_lgc) || 
		(TRUE == WhlSpdRightInRng_Cnt_T_lgc)))
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(WhlSpdCorrFltTime_mS_M_u32p0, &ElapsedTime_mS_T_u16p0);
		
		if (ElapsedTime_mS_T_u16p0 >= k_WhlSpdCorrTime_mS_u16p0)
		{
			CorrFlt_Cnt_M_Str.Failed_Cnt_lgc = TRUE;
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&CorrFlt_Cnt_M_Str.StartTime_mS_u32p0);
		}
	}
	else
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlSpdCorrFltTime_mS_M_u32p0);
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
* Name:        WIRActRejCmd
* Description: Wheel Imbalance Rejection Active Rejection Command
******************************************************************************/
STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) WIRActRejCmd(	VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32,
																		VAR(float32, AUTOMATIC) WhlSpdLeft_Hz_T_f32,
																		VAR(float32, AUTOMATIC) WhlSpdRight_Hz_T_f32,
																		VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
																		VAR(boolean, AUTOMATIC) VehSpdValid_Cnt_T_lgc,
																		VAR(boolean, AUTOMATIC) WIRDisable_Cnt_T_lgc,
																		VAR(boolean, AUTOMATIC) WIRMfgEnable_Cnt_T_lgc)
{
	VAR(float32, AUTOMATIC) FreqEstR_Hz_T_f32;
	VAR(float32, AUTOMATIC) FreqEstL_Hz_T_f32;
	VAR(float32, AUTOMATIC) FreqEstAvg_Hz_T_f32;
	VAR(float32, AUTOMATIC) WhlSpdR_RadpSec_T_f32;
	VAR(float32, AUTOMATIC) WhlSpdL_RadpSec_T_f32;
	VAR(float32, AUTOMATIC) EnabledComp_Uls_T_f32;
	VAR(float32, AUTOMATIC) FiltWhlSpdR_RadpSec_T_f32;
	VAR(float32, AUTOMATIC) FiltWhlSpdL_RadpSec_T_f32;
	VAR(float32, AUTOMATIC) LMSOutR_Uls_T_f32;
	VAR(float32, AUTOMATIC) LMSOutL_Uls_T_f32;
	VAR(float32, AUTOMATIC) CancelTrqOutput_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) PhaseAdjInput_Uls_T_f32;
	VAR(float32, AUTOMATIC) PhaseAdjOutput_Uls_T_f32;
	

	FreqEstR_Hz_T_f32 = LPF_OpUpdate_f32_m(WhlSpdRight_Hz_T_f32, &WhlFreqRFiltSV_Hz_M_str);
	FreqEstL_Hz_T_f32 = LPF_OpUpdate_f32_m(WhlSpdLeft_Hz_T_f32, &WhlFreqLFiltSV_Hz_M_str);


	FreqEstAvg_Hz_T_f32 = (FreqEstR_Hz_T_f32 + FreqEstL_Hz_T_f32) * D_ONEHALF_ULS_F32;
	FreqEstAvg_Hz_M_f32 = FreqEstAvg_Hz_T_f32;

	WhlSpdR_RadpSec_T_f32 = FreqEstR_Hz_T_f32 * D_2PI_ULS_F32;
	WhlSpdL_RadpSec_T_f32 = FreqEstL_Hz_T_f32 * D_2PI_ULS_F32;

	/* Filter Raw Wheel Speed */
	FiltWhlSpdR_RadpSec_T_f32 = UGRFilter_f32(	WhlSpdR_RadpSec_T_f32, 
												FreqEstR_Hz_T_f32,
												k_UGRPoleMag_Uls_f32,
												&UGRRDelay1_Uls_M_f32,
												&UGRRDelay2_Uls_M_f32);
	
	FiltWhlSpdR_RadpSec_T_f32 = Limit_m(FiltWhlSpdR_RadpSec_T_f32, -D_FILTWHLSPDMAX_RADPSEC_F32, D_FILTWHLSPDMAX_RADPSEC_F32);
	
	FiltWhlSpdL_RadpSec_T_f32 = UGRFilter_f32(	WhlSpdL_RadpSec_T_f32, 
												FreqEstL_Hz_T_f32,
												k_UGRPoleMag_Uls_f32,
												&UGRLDelay1_Uls_M_f32,
												&UGRLDelay2_Uls_M_f32);
	
	FiltWhlSpdL_RadpSec_T_f32 = Limit_m(FiltWhlSpdL_RadpSec_T_f32, -D_FILTWHLSPDMAX_RADPSEC_F32, D_FILTWHLSPDMAX_RADPSEC_F32);
												
	/* Calculate Enabled Compensation */
	EnabledComp_Uls_T_f32 = DetermineEnabledAmount(	FreqEstAvg_Hz_T_f32, 
													FiltWhlSpdR_RadpSec_T_f32, 
													FiltWhlSpdL_RadpSec_T_f32,
													VehSpdValid_Cnt_T_lgc,
													WIRDisable_Cnt_T_lgc,
													VehSpd_Kph_T_f32,
													WIRMfgEnable_Cnt_T_lgc);
	
	EnabledComp_Uls_M_f32 = EnabledComp_Uls_T_f32;
	
	FiltWhlSpdR_RadpSec_D_f32 = FiltWhlSpdR_RadpSec_T_f32;
	FiltWhlSpdL_RadpSec_D_f32 = FiltWhlSpdL_RadpSec_T_f32;
	
	ApplyAutoScale(	&FiltWhlSpdR_RadpSec_T_f32,
					&FiltWhlSpdL_RadpSec_T_f32,
					EnabledComp_Uls_T_f32);
	
	FiltWhlSpdRScld_RadpSec_D_f32 = FiltWhlSpdR_RadpSec_T_f32;
	FiltWhlSpdLScld_RadpSec_D_f32 = FiltWhlSpdL_RadpSec_T_f32;
	
	/* Apply Adaptive Filter */ 
	LMSOutR_Uls_T_f32 = LMSFilt_f32(	EnabledComp_Uls_T_f32, PrevHwTrq_HwNm_M_f32, 
										FiltWhlSpdR_RadpSec_T_f32, k_AdaptiveMu_Uls_f32,
										xRefDelayR_RadpSec_M_f32, xRefSVR_Uls_M_f32,
										k_NumberOfTaps_Cnt_u16);				
	
	LMSOutR_Uls_D_f32 = LMSOutR_Uls_T_f32;
																									
	LMSOutL_Uls_T_f32 = LMSFilt_f32(	EnabledComp_Uls_T_f32, PrevHwTrq_HwNm_M_f32, 
										FiltWhlSpdL_RadpSec_T_f32, k_AdaptiveMu_Uls_f32,
										xRefDelayL_RadpSec_M_f32, xRefSVL_Uls_M_f32,
										k_NumberOfTaps_Cnt_u16);
	
	LMSOutL_Uls_D_f32 = LMSOutL_Uls_T_f32;
	
	PhaseAdjInput_Uls_T_f32 = LMSOutR_Uls_T_f32 + LMSOutL_Uls_T_f32;
	PhaseAdjInput_Uls_T_f32 = Limit_m(PhaseAdjInput_Uls_T_f32, -D_PHASEADJMAX_ULS_F32, D_PHASEADJMAX_ULS_F32);  /* TODO: Check This Limit vs Requirement */
			
	PhaseAdjOutput_Uls_T_f32 = PhaseAdjust_f32(PhaseAdjInput_Uls_T_f32, FreqEstAvg_Hz_T_f32);	

	CancelTrqOutput_MtrNm_T_f32 = -PhaseAdjOutput_Uls_T_f32 * k_ScaleCancel_Uls_f32;
	
	CancelTrqOutput_MtrNm_T_f32 = Limit_m(CancelTrqOutput_MtrNm_T_f32, -D_CNCLTRQMAX_MTRNM_F32, D_CNCLTRQMAX_MTRNM_F32);
											
	PrevHwTrq_HwNm_M_f32 = HwTrq_HwNm_T_f32;
	
	return(CancelTrqOutput_MtrNm_T_f32);
}

/******************************************************************************
* Name:        UGRFilter_f32
* Description: Unity Gain Resonator Filter
******************************************************************************/
STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) UGRFilter_f32(	VAR(float32, AUTOMATIC) UGRInput_Uls_T_f32,
																		VAR(float32, AUTOMATIC) WhlFreqEst_Hz_T_f32,
																		VAR(float32, AUTOMATIC) UGRPoleMag_Uls_T_f32,
																		P2VAR(float32, AUTOMATIC, AUTOMATIC) UGRDelay1_Ptr_T_f32,
																		P2VAR(float32, AUTOMATIC, AUTOMATIC) UGRDelay2_Ptr_T_f32)
{
	VAR(float32, AUTOMATIC) ResFiltTermMinA1_Uls_T_f32;
	VAR(float32, AUTOMATIC) ResFiltTermA2_Uls_T_f32;
	VAR(float32, AUTOMATIC) FilterOut_Uls_T_f32;

	ResFiltTermMinA1_Uls_T_f32 = CalcMinusA1Term(UGRPoleMag_Uls_T_f32, WhlFreqEst_Hz_T_f32);
	ResFiltTermA2_Uls_T_f32 = UGRPoleMag_Uls_T_f32 * UGRPoleMag_Uls_T_f32;
	FilterOut_Uls_T_f32 = ResFilter(UGRInput_Uls_T_f32, ResFiltTermMinA1_Uls_T_f32, ResFiltTermA2_Uls_T_f32, UGRDelay1_Ptr_T_f32, UGRDelay2_Ptr_T_f32);
	
	return(FilterOut_Uls_T_f32);
}

/******************************************************************************
* Name:        CalcMinusA1Term
* Description: Caluclate Minus A1 Term
******************************************************************************/
STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) CalcMinusA1Term(VAR(float32, AUTOMATIC) PoleMag_Uls_T_f32,
																		VAR(float32, AUTOMATIC) WhlFreqEst_Hz_T_f32)
{
	VAR(float32, AUTOMATIC) LowLmt_Hz_T_f32;
	VAR(float32, AUTOMATIC) HighLmt_Hz_T_f32;
	VAR(float32, AUTOMATIC) WhlFreq_Rad_T_f32;
	VAR(float32, AUTOMATIC) MinusA1Term_Uls_T_f32;
	
	LowLmt_Hz_T_f32 = FPM_FixedToFloat_m(t_FreqScaleTblX_Hz_u7p9[0], u7p9_T);
	HighLmt_Hz_T_f32 = FPM_FixedToFloat_m(t_FreqScaleTblX_Hz_u7p9[TableSize_m(t_FreqScaleTblX_Hz_u7p9)-1], u7p9_T);
	
	WhlFreqEst_Hz_T_f32 = Limit_m(WhlFreqEst_Hz_T_f32, LowLmt_Hz_T_f32, HighLmt_Hz_T_f32);
	WhlFreq_Rad_T_f32 = WhlFreqEst_Hz_T_f32 * D_2MS_SEC_F32 * D_2PI_ULS_F32;
	MinusA1Term_Uls_T_f32 = 2.0F * cosf(WhlFreq_Rad_T_f32) * PoleMag_Uls_T_f32;
	
	return(MinusA1Term_Uls_T_f32);
}

/******************************************************************************
* Name:        ResFilter
* Description: Resonator Filter
******************************************************************************/
STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) ResFilter(	VAR(float32, AUTOMATIC) ResFilterIn_Uls_T_f32,
																	VAR(float32, AUTOMATIC) ResFiltTermMinA1_Uls_T_f32, 
																	VAR(float32, AUTOMATIC) ResFiltTermA2_Uls_T_f32, 
																	P2VAR(float32, AUTOMATIC, AUTOMATIC) UGRDelay1_Ptr_T_f32, 
																	P2VAR(float32, AUTOMATIC, AUTOMATIC) UGRDelay2_Ptr_T_f32)
{
	VAR(float32, AUTOMATIC) FiltOut_Uls_T_f32;
	VAR(float32, AUTOMATIC) A2Term_Uls_T_f32;
	VAR(float32, AUTOMATIC) A1Term_Uls_T_f32;
	VAR(float32, AUTOMATIC) UGRDelay1_Uls_T_f32;
	
	/*Calculate A2 Term*/
	A2Term_Uls_T_f32 = ((ResFilterIn_Uls_T_f32 * D_ONEHALF_ULS_F32) + *UGRDelay2_Ptr_T_f32) * ResFiltTermA2_Uls_T_f32;
	
	/*Calculate A1 Term*/
	A1Term_Uls_T_f32 = *UGRDelay1_Ptr_T_f32 * ResFiltTermMinA1_Uls_T_f32;
	
	/* Compute output */
	UGRDelay1_Uls_T_f32 = ((ResFilterIn_Uls_T_f32 * D_ONEHALF_ULS_F32) - A2Term_Uls_T_f32) + A1Term_Uls_T_f32;
	FiltOut_Uls_T_f32 = UGRDelay1_Uls_T_f32 - *UGRDelay2_Ptr_T_f32;
	
	UGRDelay1_Uls_T_f32 = Limit_m(UGRDelay1_Uls_T_f32, -D_UGRSVMAX_ULS_F32, D_UGRSVMAX_ULS_F32); /* Limit based on p16 resolution requirement */
	/* Update State Variables for next loop  */
	*UGRDelay2_Ptr_T_f32 = *UGRDelay1_Ptr_T_f32;
	*UGRDelay1_Ptr_T_f32 = UGRDelay1_Uls_T_f32;
	
	return(FiltOut_Uls_T_f32);
}

/******************************************************************************
* Name:        DetermineEnabledAmount
* Description: Determines Enabled Amount
******************************************************************************/
STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) DetermineEnabledAmount(	VAR(float32, AUTOMATIC) FreqEstAvg_Hz_T_f32, 
																				VAR(float32, AUTOMATIC) FiltWhlSpdR_RadpSec_T_f32, 
																				VAR(float32, AUTOMATIC) FiltWhlSpdL_RadpSec_T_f32,
																				VAR(boolean, AUTOMATIC) VehSpdValid_Cnt_T_lgc,
																				VAR(boolean, AUTOMATIC) WIRDisable_Cnt_T_lgc,
																				VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
																				VAR(boolean, AUTOMATIC) WIRMfgEnable_Cnt_T_lgc)
{
	VAR(float32, AUTOMATIC) Enable_Uls_T_f32;
	VAR(float32, AUTOMATIC) RampedEnable_Uls_T_f32;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;

	if ((TRUE == QualFlt_Cnt_M_Str.Failed_Cnt_lgc) ||
		(TRUE == CorrFlt_Cnt_M_Str.Failed_Cnt_lgc) ||
		(TRUE == DCTrendFlt_Cnt_M_Str.Failed_Cnt_lgc) ||
		(TRUE == FreqDiagFlt_Cnt_M_Str.Failed_Cnt_lgc))
	{
		/* Don't call EnableCalc (inputs may be invalid) */
		Enable_Uls_T_f32 = D_ZERO_ULS_F32;
		/* Reset algorithm to prepare for potential recovery */
		ResetWIRAlgorithm();
	}
	else 
    {
    	Enable_Uls_T_f32 = EnableCalc(FreqEstAvg_Hz_T_f32, FiltWhlSpdR_RadpSec_T_f32, FiltWhlSpdL_RadpSec_T_f32, VehSpdValid_Cnt_T_lgc, WIRDisable_Cnt_T_lgc, VehSpd_Kph_T_f32, WIRMfgEnable_Cnt_T_lgc);	
    	
    	if ( (TRUE == MaxMagFlt_Cnt_M_Str.Failed_Cnt_lgc) || 
    	     (TRUE == MaxPersFlt_Cnt_M_Str.Failed_Cnt_lgc)) 
    	{
    		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(WIREnTime_mS_M_u32p0, &ElapsedTime_mS_T_u16p0);
    		if (ElapsedTime_mS_T_u16p0 >= k_WIRRampDownTime_mS_u16p0)
    		{
    			Enable_Uls_T_f32 = D_ZERO_ULS_F32;
    			/* Reset algorithm to prepare for potential recovery */
    			ResetWIRAlgorithm();
    		}
    		else
    		{
    			RampedEnable_Uls_T_f32 = PrevCalcEnable_Uls_M_f32 * ((float32)(k_WIRRampDownTime_mS_u16p0 - ElapsedTime_mS_T_u16p0) / (float32)k_WIRRampDownTime_mS_u16p0);
    			Enable_Uls_T_f32 = Min_m(Enable_Uls_T_f32, RampedEnable_Uls_T_f32);
    		}
    	}
    	else
    	{
    		Rte_Call_SystemTime_GetSystemTime_mS_u32(&WIREnTime_mS_M_u32p0);
    		PrevCalcEnable_Uls_M_f32 = Enable_Uls_T_f32;
    	}
    }

	return(Enable_Uls_T_f32);
}

/******************************************************************************
* Name:        EnableCalc
* Description: Algorithm enable calculation
******************************************************************************/
STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) EnableCalc(	VAR(float32, AUTOMATIC) FreqEstAvg_Hz_T_f32, 
																	VAR(float32, AUTOMATIC) FiltWhlSpdR_RadpSec_T_f32, 
																	VAR(float32, AUTOMATIC) FiltWhlSpdL_RadpSec_T_f32,
																	VAR(boolean, AUTOMATIC) VehSpdValid_Cnt_T_lgc,
																	VAR(boolean, AUTOMATIC) WIRDisable_Cnt_T_lgc,
																	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32,
																	VAR(boolean, AUTOMATIC) WIRMfgEnable_Cnt_T_lgc)
{
	VAR(float32, AUTOMATIC) CurrMagR_Uls_T_f32;
	VAR(float32, AUTOMATIC) CurrMagL_Uls_T_f32;
	VAR(float32, AUTOMATIC) Enable_Uls_T_f32;
	VAR(uint16, AUTOMATIC) FreqEstAvg_Hz_T_u7p9;
	VAR(uint16, AUTOMATIC) Enable_Uls_T_u2p14;
	

	FiltWhlSpdR_RadpSec_T_f32 = Abs_f32_m(FiltWhlSpdR_RadpSec_T_f32);
	FiltWhlSpdL_RadpSec_T_f32 = Abs_f32_m(FiltWhlSpdL_RadpSec_T_f32);
	FiltWhlSpdR_RadpSec_T_f32 = LPF_OpUpdate_f32_m(FiltWhlSpdR_RadpSec_T_f32, &WhlSpdRFiltSV_RadpSec_M_Str);
	FiltWhlSpdL_RadpSec_T_f32 = LPF_OpUpdate_f32_m(FiltWhlSpdL_RadpSec_T_f32, &WhlSpdLFiltSV_RadpSec_M_Str);
	/* Get Current Magnitude */
	CurrMagR_Uls_T_f32 = FiltWhlSpdR_RadpSec_T_f32 * D_PIDIVTWO_ULS_F32;
	CurrMagL_Uls_T_f32 = FiltWhlSpdL_RadpSec_T_f32 * D_PIDIVTWO_ULS_F32;
	CurrMagR_Uls_D_f32 = CurrMagR_Uls_T_f32;
	CurrMagL_Uls_D_f32 = CurrMagL_Uls_T_f32;
	
	/* Calculate the Disturbance Magnitude */
	PeakRightTyH_Uls_M_f32 = CalcDistMag(CurrMagR_Uls_T_f32, PeakRightTyH_Uls_M_f32, FreqEstAvg_Hz_T_f32);
	PeakLeftTyH_Uls_M_f32 = CalcDistMag(CurrMagL_Uls_T_f32, PeakLeftTyH_Uls_M_f32, FreqEstAvg_Hz_T_f32);
	
	/* Check if the Disturbance Magnitude is in enabling range */
	if ((PeakLeftTyH_Uls_M_f32 < k_MagEstDisable_Uls_f32) && 
	    (PeakRightTyH_Uls_M_f32 < k_MagEstDisable_Uls_f32))
	{
		DistMagEnabled_Cnt_M_lgc = FALSE;
		Enable_Uls_T_f32 = D_ZERO_ULS_F32;
	}
	else
	{ 
		if ((PeakLeftTyH_Uls_M_f32 > k_MagEstEnable_Uls_f32) || 
		    (PeakRightTyH_Uls_M_f32 > k_MagEstEnable_Uls_f32) || 
		    (TRUE == DistMagEnabled_Cnt_M_lgc))
		{
			DistMagEnabled_Cnt_M_lgc = TRUE;
			
			FreqEstAvg_Hz_T_u7p9 = FPM_FloatToFixed_m(FreqEstAvg_Hz_T_f32, u7p9_T);
			 
			Enable_Uls_T_u2p14 = IntplVarXY_u16_u16Xu16Y_Cnt(	t_FreqScaleTblX_Hz_u7p9,
	        	                         						t_FreqScaleTblY_Uls_u2p14,
	    	                            						TableSize_m(t_FreqScaleTblX_Hz_u7p9),
	        	                       							FreqEstAvg_Hz_T_u7p9);
	       	
	       	Enable_Uls_T_f32 = FPM_FixedToFloat_m(Enable_Uls_T_u2p14, u2p14_T);
		}
		else
		{
			Enable_Uls_T_f32 = D_ZERO_ULS_F32;
		}
	}

	if ((FALSE == VehSpdValid_Cnt_T_lgc) ||
		(TRUE == WIRDisable_Cnt_T_lgc) || 
		(FALSE == WIRMfgEnable_Cnt_T_lgc) ||
		(VehSpd_Kph_T_f32 < k_WIRVehSpdEnable_Kph_f32))
	{
		Enable_Uls_T_f32 = D_ZERO_ULS_F32;
	}
	
	/* Apply slew limit to control the rate of change */
	Enable_Uls_T_f32 = Limit_m(	Enable_Uls_T_f32, 
								(PrevEnable_Uls_M_f32 - k_EnSlewPerLoop_Uls_f32), 
								(PrevEnable_Uls_M_f32 + k_EnSlewPerLoop_Uls_f32));
	
	PrevEnable_Uls_M_f32 = Enable_Uls_T_f32;
	
	RtLmtCurrMagR_Uls_M_f32 = Limit_m(	CurrMagR_Uls_T_f32, 
										(RtLmtCurrMagR_Uls_M_f32 - k_CurrMagSlewPerLoop_Uls_f32),
										(RtLmtCurrMagR_Uls_M_f32 + k_CurrMagSlewPerLoop_Uls_f32));
										
	RtLmtCurrMagL_Uls_M_f32 = Limit_m(	CurrMagL_Uls_T_f32, 
										(RtLmtCurrMagL_Uls_M_f32 - k_CurrMagSlewPerLoop_Uls_f32),
										(RtLmtCurrMagL_Uls_M_f32 + k_CurrMagSlewPerLoop_Uls_f32));
	
	return(Enable_Uls_T_f32);
}

/******************************************************************************
* Name:        CalcDistMag
* Description: Calculate Disturbance Magnitude
******************************************************************************/
STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) CalcDistMag(	VAR(float32, AUTOMATIC) CurrMag_Uls_T_f32,
																		VAR(float32, AUTOMATIC) Peak_Uls_T_f32, 
																		VAR(float32, AUTOMATIC) FreqEstAvg_Hz_T_f32)
{
	VAR(float32, AUTOMATIC) DeltaScaled_Uls_T_f32;
	
	if ((FreqEstAvg_Hz_T_f32 > (k_MagEstFreq_Hz_f32 - k_MagEstFreqDelta_Hz_f32)) &&
	    (FreqEstAvg_Hz_T_f32 < (k_MagEstFreq_Hz_f32 + k_MagEstFreqDelta_Hz_f32)))
	{
		if (CurrMag_Uls_T_f32 > Peak_Uls_T_f32)
		{
			DeltaScaled_Uls_T_f32 = (CurrMag_Uls_T_f32 - Peak_Uls_T_f32) * k_MagEstDeltaScale_Uls_f32;
			Peak_Uls_T_f32 = Peak_Uls_T_f32 + DeltaScaled_Uls_T_f32;	
		}
		else
		{
			Peak_Uls_T_f32 = Peak_Uls_T_f32 * k_MagEstLeak_Uls_f32;
		}	
	}

	return(Peak_Uls_T_f32);
}

/******************************************************************************
* Name:        ApplyAutoScale
* Description: Apply AutoScale
******************************************************************************/
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) ApplyAutoScale(	P2VAR(float32, AUTOMATIC, AUTOMATIC) FiltWhlSpdR_Ptr_T_f32,
																		P2VAR(float32, AUTOMATIC, AUTOMATIC) FiltWhlSpdL_Ptr_T_f32,
																		VAR(float32, AUTOMATIC) EnabledComp_Uls_T_f32)
{
	VAR(float32, AUTOMATIC) ScaleR_Uls_T_f32;
	VAR(float32, AUTOMATIC) ScaleL_Uls_T_f32;
	
	if ((k_AutoScaleEnable_Cnt_lgc == TRUE) && (EnabledComp_Uls_T_f32 > 0.0F))
	{
		ScaleR_Uls_T_f32 = k_AutoScaleTarget_RadpSec_f32 / Max_m(RtLmtCurrMagR_Uls_M_f32, k_AutoScaleTarget_RadpSec_f32);
		ScaleL_Uls_T_f32 = k_AutoScaleTarget_RadpSec_f32 / Max_m(RtLmtCurrMagL_Uls_M_f32, k_AutoScaleTarget_RadpSec_f32);
	
		*FiltWhlSpdR_Ptr_T_f32 = *FiltWhlSpdR_Ptr_T_f32 * ScaleR_Uls_T_f32;
		*FiltWhlSpdL_Ptr_T_f32 = *FiltWhlSpdL_Ptr_T_f32 * ScaleL_Uls_T_f32;

		ScaleL_Uls_D_f32 = ScaleL_Uls_T_f32;
		ScaleR_Uls_D_f32 = ScaleR_Uls_T_f32;
	}
	else
	{
		ScaleL_Uls_D_f32 = 1.0F;
		ScaleR_Uls_D_f32 = 1.0F;
	}
}	
																		
/******************************************************************************
* Name:        LMSFilt_f32
* Description: LMS Filter
******************************************************************************/
STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) LMSFilt_f32(VAR(float32, AUTOMATIC) Enable_Uls_T_f32, 
																	VAR(float32, AUTOMATIC) PrevEpsilon_Uls_T_f32, 
																	VAR(float32, AUTOMATIC) xRef_Uls_T_f32, 
																	VAR(float32, AUTOMATIC) AdaptiveMu_Uls_T_f32, 
																	VAR(float32, AUTOMATIC) xRefDelay_Uls_T_f32[], 
																	VAR(float32, AUTOMATIC) xRefStateVar_Uls_T_f32[], 
																	VAR(uint16, AUTOMATIC) NTaps_Cnt_T_u16)
{

	VAR(float32, AUTOMATIC) OutputSum_Uls_T_f32;
	VAR(float32, AUTOMATIC) Multiplier_Uls_T_f32;
	VAR(uint16, AUTOMATIC) Index_Cnt_T_u16;
	VAR(float32, AUTOMATIC) TapOutput_Uls_T_f32;
	VAR(float32, AUTOMATIC) Output_Uls_T_f32;
	VAR(float32, AUTOMATIC) SVMultiplier_Uls_T_f32;
	VAR(float32, AUTOMATIC) SVTemp_Uls_T_f32;

	OutputSum_Uls_T_f32 = D_ZERO_ULS_F32;
	
	Multiplier_Uls_T_f32 = PrevEpsilon_Uls_T_f32 * AdaptiveMu_Uls_T_f32 * 2.0F * Enable_Uls_T_f32;

	if(FLT_EPSILON < Enable_Uls_T_f32)
	{
		SVMultiplier_Uls_T_f32 = 1.0F;
	}
	else
	{
		SVMultiplier_Uls_T_f32 = D_ZERO_ULS_F32;
	}

	/* Process Index 1->NTaps */
	for (Index_Cnt_T_u16 = NTaps_Cnt_T_u16; Index_Cnt_T_u16 > 0; Index_Cnt_T_u16--)
	{
		SVTemp_Uls_T_f32 = SVMultiplier_Uls_T_f32 * (xRefStateVar_Uls_T_f32[Index_Cnt_T_u16] + (Multiplier_Uls_T_f32 * xRefDelay_Uls_T_f32[Index_Cnt_T_u16]));
		xRefStateVar_Uls_T_f32[Index_Cnt_T_u16] = Limit_m(SVTemp_Uls_T_f32, -D_LMSFILTSVMAX_ULS_F32, D_LMSFILTSVMAX_ULS_F32);	/* Based on p13 resolution input requirement */
		xRefDelay_Uls_T_f32[Index_Cnt_T_u16] = xRefDelay_Uls_T_f32[Index_Cnt_T_u16-1];
		TapOutput_Uls_T_f32 = xRefDelay_Uls_T_f32[Index_Cnt_T_u16] * xRefStateVar_Uls_T_f32[Index_Cnt_T_u16];
		OutputSum_Uls_T_f32 = OutputSum_Uls_T_f32 + TapOutput_Uls_T_f32; 
	}

	/* Process Index 0 */
	xRefStateVar_Uls_T_f32[0] = SVMultiplier_Uls_T_f32 * (xRefStateVar_Uls_T_f32[0] + (Multiplier_Uls_T_f32 * xRefDelay_Uls_T_f32[0]));
	xRefDelay_Uls_T_f32[0] = xRef_Uls_T_f32;
	TapOutput_Uls_T_f32 = xRefDelay_Uls_T_f32[0] * xRefStateVar_Uls_T_f32[0];
	OutputSum_Uls_T_f32 = OutputSum_Uls_T_f32 + TapOutput_Uls_T_f32; 
	
	Output_Uls_T_f32 = OutputSum_Uls_T_f32 * Enable_Uls_T_f32;
	
	return (Output_Uls_T_f32);
}

/******************************************************************************
* Name:        PhaseAdjust_f32
* Description: Phase Adjust
******************************************************************************/
STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) PhaseAdjust_f32(	VAR(float32, AUTOMATIC) PhaseAdjInput_Uls_T_f32, 
																			VAR(float32, AUTOMATIC) FreqEstAvg_Hz_T_f32)
{
	VAR(uint16, AUTOMATIC) FreqEstAvg_Hz_T_u7p9;
	VAR(sint16, AUTOMATIC) Phase_Deg_T_s8p7;
	VAR(float32, AUTOMATIC) Phase_Deg_T_f32;
	VAR(float32, AUTOMATIC) AbsPhase_Deg_T_f32;
	VAR(float32, AUTOMATIC) Phase_Rad_T_f32;
	VAR(float32, AUTOMATIC) Stage1Out_Uls_T_f32;
	VAR(float32, AUTOMATIC) Stage2Out_Uls_T_f32;
	VAR(float32, AUTOMATIC) PhaseAdjOutput_Uls_T_f32;
	VAR(float32, AUTOMATIC) ZeroCoeff_Uls_T_f32;
	VAR(float32, AUTOMATIC) PoleCoeff_Uls_T_f32;
	VAR(float32, AUTOMATIC) GainCoeff_Uls_T_f32;
	VAR(float32, AUTOMATIC) InvMag_Uls_T_f32;
		
	FreqEstAvg_Hz_T_u7p9 = FPM_FloatToFixed_m(FreqEstAvg_Hz_T_f32, u7p9_T);
	Phase_Deg_T_s8p7 = IntplVarXY_s16_u16Xs16Y_Cnt(	t_PhaseAdjustX_Hz_u7p9,
													t_PhaseAdjustY_Deg_s8p7,
													TableSize_m(t_PhaseAdjustX_Hz_u7p9),
													FreqEstAvg_Hz_T_u7p9);
	Phase_Deg_T_f32 = FPM_FixedToFloat_m(Phase_Deg_T_s8p7, s8p7_T);

	AbsPhase_Deg_T_f32 = Abs_f32_m(Phase_Deg_T_f32);

	if (AbsPhase_Deg_T_f32 > 90.0F)
	{
		Phase_Deg_T_f32 = (float32)-Sign_f32_m(Phase_Deg_T_f32) * (180.0F - AbsPhase_Deg_T_f32);
		PhaseAdjInput_Uls_T_f32 = -PhaseAdjInput_Uls_T_f32;
	}												

	/* Convert to radians and divide by 2 */
	Phase_Rad_T_f32 = Phase_Deg_T_f32 * D_RADPERDEGDIVTWO_ULS_F32;
	
	CalcFilterCoeff(	Phase_Rad_T_f32, 
						FreqEstAvg_Hz_T_f32,
						&ZeroCoeff_Uls_T_f32, 
						&PoleCoeff_Uls_T_f32, 
						&GainCoeff_Uls_T_f32, 
						&InvMag_Uls_T_f32);
	
	Stage1Out_Uls_T_f32 = LeadLagFilter(	PhaseAdjInput_Uls_T_f32,
											ZeroCoeff_Uls_T_f32,
											PoleCoeff_Uls_T_f32,
											GainCoeff_Uls_T_f32,
											InvMag_Uls_T_f32,
											&Stage1SV1_Uls_M_f32,
											&Stage1SV2_Uls_M_f32);
	
	Stage2Out_Uls_T_f32 = LeadLagFilter(	Stage1Out_Uls_T_f32,
											ZeroCoeff_Uls_T_f32,
											PoleCoeff_Uls_T_f32,
											GainCoeff_Uls_T_f32,
											InvMag_Uls_T_f32,
											&Stage2SV1_Uls_M_f32,
											&Stage2SV2_Uls_M_f32);
										
	PhaseAdjOutput_Uls_T_f32 = Stage2Out_Uls_T_f32;

	return(PhaseAdjOutput_Uls_T_f32);
}

/******************************************************************************
* Name:        CalcFilterCoeff
* Description: Calculate Filter Coefficients
******************************************************************************/
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) CalcFilterCoeff(	VAR(float32, AUTOMATIC) Phase_Rad_T_f32,
																		VAR(float32, AUTOMATIC) FreqEstAvg_Hz_T_f32, 
																		P2VAR(float32, AUTOMATIC, AUTOMATIC) ZeroCoeff_Ptr_T_f32,
																		P2VAR(float32, AUTOMATIC, AUTOMATIC) PoleCoeff_Ptr_T_f32,
																		P2VAR(float32, AUTOMATIC, AUTOMATIC) GainCoeff_Ptr_T_f32,
																		P2VAR(float32, AUTOMATIC, AUTOMATIC) InvMag_Ptr_T_f32)
{
	VAR(float32, AUTOMATIC) SinPhase_Uls_T_f32;
	VAR(float32, AUTOMATIC) Alpha_Uls_T_f32;
	VAR(float32, AUTOMATIC) SqrtAlpha_Uls_T_f32;
	VAR(float32, AUTOMATIC) PiFTs_Uls_T_f32;
	VAR(float32, AUTOMATIC) AlphaPiFTs_Uls_T_f32;
	VAR(float32, AUTOMATIC) Term1_Uls_T_f32;
	VAR(float32, AUTOMATIC) Term2_Uls_T_f32;
	VAR(float32, AUTOMATIC) Term3_Uls_T_f32;
	VAR(float32, AUTOMATIC) Term4_Uls_T_f32;
	VAR(float32, AUTOMATIC) AlphaTerm4_Uls_T_f32;
	
	SinPhase_Uls_T_f32 = sinf(Phase_Rad_T_f32);
	
	Alpha_Uls_T_f32 = (1.0F - SinPhase_Uls_T_f32) / (1.0F + SinPhase_Uls_T_f32);
	SqrtAlpha_Uls_T_f32 = sqrtf(Alpha_Uls_T_f32);
	
	PiFTs_Uls_T_f32 = FreqEstAvg_Hz_T_f32 * D_PITIMESSAMPLETIME_ULS_F32;
	
	AlphaPiFTs_Uls_T_f32 = Alpha_Uls_T_f32 * PiFTs_Uls_T_f32;
	
	Term1_Uls_T_f32 = SqrtAlpha_Uls_T_f32 - AlphaPiFTs_Uls_T_f32;
	Term2_Uls_T_f32 = SqrtAlpha_Uls_T_f32 + AlphaPiFTs_Uls_T_f32;
	Term3_Uls_T_f32 = SqrtAlpha_Uls_T_f32 - PiFTs_Uls_T_f32;
	Term4_Uls_T_f32 = SqrtAlpha_Uls_T_f32 + PiFTs_Uls_T_f32;
	
	AlphaTerm4_Uls_T_f32 = Term4_Uls_T_f32 * Alpha_Uls_T_f32;
	
	*ZeroCoeff_Ptr_T_f32 = Term1_Uls_T_f32 / Term2_Uls_T_f32;
	*PoleCoeff_Ptr_T_f32 = Term3_Uls_T_f32 / Term4_Uls_T_f32;
	*GainCoeff_Ptr_T_f32 = Term2_Uls_T_f32 / AlphaTerm4_Uls_T_f32;
	*InvMag_Ptr_T_f32 = SqrtAlpha_Uls_T_f32;	
}

/******************************************************************************
* Name:        LeadLagFilter
* Description: Lead Lag Filter
******************************************************************************/
STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) LeadLagFilter(	VAR(float32, AUTOMATIC) FilterInput_Uls_T_f32,
																		VAR(float32, AUTOMATIC) ZeroCoeff_Uls_T_f32,
																		VAR(float32, AUTOMATIC) PoleCoeff_Uls_T_f32,
																		VAR(float32, AUTOMATIC) GainCoeff_Uls_T_f32,
																		VAR(float32, AUTOMATIC) InvMag_Uls_T_f32,
																		P2VAR(float32, AUTOMATIC, AUTOMATIC) LeadLagSV1_Ptr_T_f32,
																		P2VAR(float32, AUTOMATIC, AUTOMATIC) LeadLagSV2_Ptr_T_f32)
{
	VAR(float32, AUTOMATIC) TempSV1_Uls_T_f32;
	VAR(float32, AUTOMATIC) TempSV2_Uls_T_f32;
	VAR(float32, AUTOMATIC) Output_Uls_T_f32;
	
	TempSV1_Uls_T_f32 = FilterInput_Uls_T_f32 * GainCoeff_Uls_T_f32;
	TempSV1_Uls_T_f32 = Limit_m(TempSV1_Uls_T_f32, -D_LEADLAGFILTSVMAX_ULS_F32, D_LEADLAGFILTSVMAX_ULS_F32);  /* Based on p8 resolution input requirement */
	
	TempSV2_Uls_T_f32 = (TempSV1_Uls_T_f32 - (*LeadLagSV1_Ptr_T_f32 * ZeroCoeff_Uls_T_f32)) + (*LeadLagSV2_Ptr_T_f32 * PoleCoeff_Uls_T_f32);
	TempSV2_Uls_T_f32 = Limit_m(TempSV2_Uls_T_f32, -D_LEADLAGFILTSVMAX_ULS_F32, D_LEADLAGFILTSVMAX_ULS_F32);	/* Based on p8 resolution input requirement */
	
	*LeadLagSV2_Ptr_T_f32 = TempSV2_Uls_T_f32;
	*LeadLagSV1_Ptr_T_f32 = TempSV1_Uls_T_f32;

	Output_Uls_T_f32 = *LeadLagSV2_Ptr_T_f32 * InvMag_Uls_T_f32;
	
	Output_Uls_T_f32 = Limit_m(Output_Uls_T_f32, -D_PHASEADJMAX_ULS_F32, D_PHASEADJMAX_ULS_F32);
	
	return(Output_Uls_T_f32);
}

/******************************************************************************
* Name:        WIRDiagnostics
* Description: WIR Diagnostic Functions
******************************************************************************/
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WIRDiagnostics(	VAR(float32, AUTOMATIC) WhlImbRejCmd_MtrNm_T_f32)
{
	DiagnoseCmdMag(WhlImbRejCmd_MtrNm_T_f32);
	DiagnoseFreq(WhlImbRejCmd_MtrNm_T_f32);
	DiagnoseDCTrend(WhlImbRejCmd_MtrNm_T_f32);
}

/******************************************************************************
* Name:        DiagnoseCmdMag
* Description: Command Magnitude Diagnostic
******************************************************************************/
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) DiagnoseCmdMag(	VAR(float32, AUTOMATIC) InputCommand_MtrNm_T_f32)
{
	VAR(float32, AUTOMATIC) FinalCmdMag_MtrNm_T_f32;
	
	FinalCmdMag_MtrNm_T_f32 = CalcCmdAmplitude(	InputCommand_MtrNm_T_f32, 
												&CmdMagFiltSV1_MtrNm_M_Str,
												&CmdMagFiltSV2_MtrNm_M_Str);
	
	if (FinalCmdMag_MtrNm_T_f32 >= k_WIRMaxMag_MtrNm_f32)
	{
		MaxMagErrorAcc_Cnt_M_u16 = DiagPStep_m(MaxMagErrorAcc_Cnt_M_u16, k_WIRMaxMagDiag_Cnt_Str);
		if(TRUE == DiagFailed_m(MaxMagErrorAcc_Cnt_M_u16, k_WIRMaxMagDiag_Cnt_Str))
		{
			MaxMagFlt_Cnt_M_Str.Failed_Cnt_lgc = TRUE;
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&MaxMagFlt_Cnt_M_Str.StartTime_mS_u32p0);
		}
	}
	else 
	{
		MaxMagErrorAcc_Cnt_M_u16 = DiagNStep_m(MaxMagErrorAcc_Cnt_M_u16, k_WIRMaxMagDiag_Cnt_Str);
	}

	WIRCmdMag_MtrNm_M_f32 = FinalCmdMag_MtrNm_T_f32;
}

/******************************************************************************
* Name: CalcCmdAmplitude
* Description: Calculate Command Amplitude
******************************************************************************/
STATIC INLINE FUNC(float32, RTE_AP_WHLIMBREJ_APPL_CODE) CalcCmdAmplitude(	VAR(float32, AUTOMATIC) InputCommand_MtrNm_T_f32, 
																			P2VAR(LPF32KSV_Str, AUTOMATIC, AUTOMATIC) CmdMagFiltSV1_Ptr_T_Str,
																			P2VAR(LPF32KSV_Str, AUTOMATIC, AUTOMATIC) CmdMagFiltSV2_Ptr_T_Str)
{
	VAR(float32, AUTOMATIC) Filter1Out_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) Filter2Out_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) CmdAmp_MtrNm_T_f32;


	InputCommand_MtrNm_T_f32 = Abs_f32_m(InputCommand_MtrNm_T_f32);
		
	Filter1Out_MtrNm_T_f32 = LPF_OpUpdate_f32_m(InputCommand_MtrNm_T_f32, CmdMagFiltSV1_Ptr_T_Str);


	Filter2Out_MtrNm_T_f32 = LPF_OpUpdate_f32_m(Filter1Out_MtrNm_T_f32, CmdMagFiltSV2_Ptr_T_Str);
	
	CmdAmp_MtrNm_T_f32 = Filter2Out_MtrNm_T_f32 * D_PIDIVTWO_ULS_F32;
	
	return(CmdAmp_MtrNm_T_f32);
}
												
/******************************************************************************
* Name:        DiagnoseFreq
* Description: Diagnose WIR Cmd Frequency Content
******************************************************************************/
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) DiagnoseFreq(	VAR(float32, AUTOMATIC) WhlImbRejCmd_MtrNm_T_f32)
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;
	VAR(float32, AUTOMATIC) FreqDiagFiltOut_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) FreqDiff_MtrNm_T_f32;
	VAR(float32, AUTOMATIC) FiltFreqDiff_MtrNm_T_f32;
	
	FreqDiagFiltOut_MtrNm_T_f32 = UGRFilter_f32(	WhlImbRejCmd_MtrNm_T_f32, 
													FreqEstAvg_Hz_M_f32,
													k_FreqDiagUGRPoleMag_Uls_f32,
													&FreqDiagUGRDelay1_Uls_M_f32,
													&FreqDiagUGRDelay2_Uls_M_f32);
	
	FreqDiagFiltOut_MtrNm_T_f32 = Limit_m(FreqDiagFiltOut_MtrNm_T_f32, -D_CNCLTRQMAX_MTRNM_F32, D_CNCLTRQMAX_MTRNM_F32);
	
	FreqDiff_MtrNm_T_f32 = Abs_f32_m((FreqDiagFiltOut_MtrNm_T_f32 - WhlImbRejCmd_MtrNm_T_f32));


	FiltFreqDiff_MtrNm_T_f32 = LPF_OpUpdate_f32_m(FreqDiff_MtrNm_T_f32, &FiltFreqDiffSV_MtrNm_M_Str);

	
	if ((FiltFreqDiff_MtrNm_T_f32 >= k_FreqDiagThresh_MtrNm_f32) &&
	    (WIRCmdMag_MtrNm_M_f32 >= k_FreqDiagWIRAmpThresh_MtrNm_f32) && 
	    (EnabledComp_Uls_M_f32 > FLT_EPSILON))
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(FrqDiagStartTime_mS_M_u32p0, &ElapsedTime_mS_T_u16p0);
		
		if ((ElapsedTime_mS_T_u16p0 > k_FreqDiagTimeout_mS_u16p0) && (TRUE == k_FreqDiagEnable_Cnt_lgc))
		{
			FreqDiagFlt_Cnt_M_Str.Failed_Cnt_lgc = TRUE;
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&FreqDiagFlt_Cnt_M_Str.StartTime_mS_u32p0);
		}
	}
	else
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&FrqDiagStartTime_mS_M_u32p0);
	}
}
/******************************************************************************
* Name:        DiagnoseDCTrend
* Description: Diagnose WIR DC Trend
******************************************************************************/
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) DiagnoseDCTrend(	VAR(float32, AUTOMATIC) InputCommand_MtrNm_T_f32)
{
	VAR(float32, AUTOMATIC) Trend_MtrNm_T_f32;
	VAR(uint32, AUTOMATIC) ElapsedTime_mS_T_u32p0;
	VAR(uint32, AUTOMATIC) ElapsedTime2_mS_T_u32p0;

	Trend_MtrNm_T_f32 = LPF_OpUpdate_f32_m(InputCommand_MtrNm_T_f32, &TrendSV_MtrNm_M_Str);
	
	if ((Abs_f32_m(Trend_MtrNm_T_f32) >= k_WIRDCTrendTh_MtrNm_f32) )
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TrndThrStartTime_mS_M_u32p0, &ElapsedTime_mS_T_u32p0);
		if ((float32)ElapsedTime_mS_T_u32p0 > (k_WIRDCTrendTime_Sec_f32 * 1000.0F))
		{
			DCTrendFlt_Cnt_M_Str.Failed_Cnt_lgc = TRUE;
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&DCTrendFlt_Cnt_M_Str.StartTime_mS_u32p0);
		}
	}
	else 
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrndThrStartTime_mS_M_u32p0);
	}


	if (Abs_f32_m(Trend_MtrNm_T_f32) >= k_WIRDCTrendTh2_MtrNm_f32)
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(TrndThr2StartTime_mS_M_u32p0, &ElapsedTime2_mS_T_u32p0);
		if ((float32)ElapsedTime2_mS_T_u32p0 > (k_WIRDCTrendTime2_Sec_f32 * 1000.0F))
		{
			DCTrendFlt_Cnt_M_Str.Failed_Cnt_lgc = TRUE;
			Rte_Call_SystemTime_GetSystemTime_mS_u32(&DCTrendFlt_Cnt_M_Str.StartTime_mS_u32p0);
		}
	}
	else
	{
		Rte_Call_SystemTime_GetSystemTime_mS_u32(&TrndThr2StartTime_mS_M_u32p0);
	}

}

/******************************************************************************
* Name:        ProcessStatusBits
* Description: Process WIR Status Bits
******************************************************************************/
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) ProcessStatusBits(	void)
{
	VAR(uint16, AUTOMATIC) WhlImbFltStatus_Cnt_T_b16;
	
	WhlImbFltStatus_Cnt_T_b16 = WhlImbFltStatus_Cnt_M_b16;
	
	/* Update status bits and handle recovery */
	UpdateFaultBits(	&CorrFlt_Cnt_M_Str,
						D_WIRCORRFLT_CNT_B16,
						D_WIRCORRFLTREC_CNT_B16,
						&WhlImbFltStatus_Cnt_T_b16);
	
	UpdateFaultBits(	&QualFlt_Cnt_M_Str,
						D_WIRQUALFLT_CNT_B16,
						0U, /* No Recovery */
						&WhlImbFltStatus_Cnt_T_b16);
						
	UpdateFaultBits(	&MaxMagFlt_Cnt_M_Str,
						D_WIRMAXMAGFLT_CNT_B16,
						D_WIRMAXMAGFLTREC_CNT_B16,
						&WhlImbFltStatus_Cnt_T_b16);
	
	UpdateFaultBits(	&MaxPersFlt_Cnt_M_Str,
						D_WIRMAXPERSFLT_CNT_B16,
						0U, /* No Recovery */
						&WhlImbFltStatus_Cnt_T_b16);
	
	UpdateFaultBits(	&DCTrendFlt_Cnt_M_Str,
						D_WIRDCTRENDFLT_CNT_B16,
						D_WIRDCTRENDFLTREC_CNT_B16,
						&WhlImbFltStatus_Cnt_T_b16);
	
	UpdateFaultBits(	&FreqDiagFlt_Cnt_M_Str,
						D_WIRFREQDIAGFLT_CNT_B16,
						D_WIRFREQDIAGFLTREC_CNT_B16,
						&WhlImbFltStatus_Cnt_T_b16);
	
	if (0U != WhlImbFltStatus_Cnt_T_b16)
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_00, 0x01, NTC_STATUS_FAILED);
	}
	else
	{
		Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_VLF_00, 0x01, NTC_STATUS_PASSED);
	}
	
	WhlImbFltStatus_Cnt_M_b16 = WhlImbFltStatus_Cnt_T_b16;	
}

/******************************************************************************
* Name:        UpdateFaultBits
* Description: Update Fault Bits
******************************************************************************/
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) UpdateFaultBits(	P2VAR(WIRDiagInfo_Str, AUTOMATIC, AUTOMATIC) DiagInfo_Ptr_T_Str,
																		VAR(uint16, AUTOMATIC) FaultMask_Cnt_T_b16,
																		VAR(uint16, AUTOMATIC) RecoveryFaultMask_Cnt_T_b16,
																		P2VAR(uint16, AUTOMATIC, AUTOMATIC) WhlImbFltStatus_Ptr_T_b16)
{
	if (TRUE == (*DiagInfo_Ptr_T_Str).MaxRecFailed_Cnt_lgc)
	{
		*WhlImbFltStatus_Ptr_T_b16 |= RecoveryFaultMask_Cnt_T_b16;
	}
	else if (TRUE == (*DiagInfo_Ptr_T_Str).Failed_Cnt_lgc)
	{
		if (TRUE == (*DiagInfo_Ptr_T_Str).ResetFlt_Cnt_lgc)
		{
			*WhlImbFltStatus_Ptr_T_b16 &= ~FaultMask_Cnt_T_b16;
			(*DiagInfo_Ptr_T_Str).Failed_Cnt_lgc = FALSE;
			(*DiagInfo_Ptr_T_Str).ResetFlt_Cnt_lgc = FALSE;
		}
		else
		{
			*WhlImbFltStatus_Ptr_T_b16 |= FaultMask_Cnt_T_b16;
		}
	}
	else
	{
	}
}

/******************************************************************************
* Name:        LogCompActivity
* Description: Log WIR Compensation Activity
******************************************************************************/
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) LogCompActivity(	VAR(float32, AUTOMATIC) WIRCmdMag_MtrNm_T_f32)
{
	VAR(float32, AUTOMATIC) CurrComp_Pct_T_f32;
	VAR(uint16, AUTOMATIC) IndexOfRange_Cnt_T_u16;
	
	if (WIRCmdMag_MtrNm_T_f32 >= k_WIRMaxMag_MtrNm_f32)
	{
		CurrComp_Pct_T_f32 = D_ONEHUNDRED_PCT_F32;
	}
	else
	{
		CurrComp_Pct_T_f32 = D_ONEHUNDRED_PCT_F32 * (WIRCmdMag_MtrNm_T_f32 / k_WIRMaxMag_MtrNm_f32);	
	}

	if (CurrComp_Pct_T_f32 < 5.0F)
	{
		/* Compensation is small enough that no data stored */
	}
	else
	{ 
		if (CurrComp_Pct_T_f32 < 33.0F)
		{
			/*Range 1*/
			IndexOfRange_Cnt_T_u16 = 0U;
		}
		else if (CurrComp_Pct_T_f32 < 66.0F)
		{
			/*Range 2*/
			IndexOfRange_Cnt_T_u16 = 1U;
		}
		else
		{
			/*Range 3*/
			IndexOfRange_Cnt_T_u16 = 2U;
		}
		
		if(WIRCmpActTyH_Cnt_M_u32[IndexOfRange_Cnt_T_u16] < 0xFFFFFFFFU)
		{
			WIRCmpActTyH_Cnt_M_u32[IndexOfRange_Cnt_T_u16]++;
		}
	}
	
	/* Store Max Compensation Activity */
	if (CurrComp_Pct_T_f32 > WIRMaxCompTyH_Pct_M_f32)
	{
		WIRMaxCompTyH_Pct_M_f32 = CurrComp_Pct_T_f32;
	}
	
}

/******************************************************************************
* Name:        CheckCompPers
* Description: Check Compensation Persistence
******************************************************************************/						
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) CheckCompPers(	void)
{
	
	VAR(float32, AUTOMATIC) TotalDuration_Min_T_f32;
	
	if (k_WIRMaxDur_Cnt_u16 <= D_DURATIONDISABLE_CNT_U16)
	{
		TotalDuration_Min_T_f32 = (((float32)WIRCmpActTyH_Cnt_M_u32[0] * 0.33F) + 
		                           ((float32)WIRCmpActTyH_Cnt_M_u32[1] * 0.66F) + 
		                           (float32)WIRCmpActTyH_Cnt_M_u32[2]) * D_STOREDMINSPERCOUNT_ULS_F32;
		
		if (TotalDuration_Min_T_f32 > ((float32)k_WIRMaxDur_Cnt_u16 * D_CALMINSPERCOUNT_ULS_F32))
		{
			MaxPersFlt_Cnt_M_Str.Failed_Cnt_lgc = TRUE;
		}
	}
}

/******************************************************************************
* Name:        WIRFltRecovery
* Description: Fault Recovery Processing
******************************************************************************/		
STATIC FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) WIRFltRecovery(	P2VAR(WIRDiagInfo_Str, AUTOMATIC, AUTOMATIC) DiagInfo_Ptr_T_Str,
																VAR(uint8, AUTOMATIC) MaxFltRecLmt_Cnt_T_u8,
																VAR(float32, AUTOMATIC) FltRecDly_Min_T_f32)
{
	VAR(uint32, AUTOMATIC) ElapsedTime_mS_T_u32p0;
	
	if ((TRUE == (*DiagInfo_Ptr_T_Str).Failed_Cnt_lgc) && (FALSE == (*DiagInfo_Ptr_T_Str).MaxRecFailed_Cnt_lgc))
	{
		Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32((*DiagInfo_Ptr_T_Str).StartTime_mS_u32p0, &ElapsedTime_mS_T_u32p0);
		
		if((*DiagInfo_Ptr_T_Str).RecoveryCntr_Cnt_u8 >= MaxFltRecLmt_Cnt_T_u8)
		{
			/* Maximum number of recovery attempts exceeded */
			(*DiagInfo_Ptr_T_Str).MaxRecFailed_Cnt_lgc = TRUE;
		}
		else if (ElapsedTime_mS_T_u32p0 >= (uint32)(FltRecDly_Min_T_f32 * D_MSPERMIN_ULS_F32))
		{
			/* Minimum delay time has elapsed, attempt to recover from Max Compensation fault */
			(*DiagInfo_Ptr_T_Str).ResetFlt_Cnt_lgc = TRUE;
			(*DiagInfo_Ptr_T_Str).RecoveryCntr_Cnt_u8 = (*DiagInfo_Ptr_T_Str).RecoveryCntr_Cnt_u8 + 1U;
		}
		else
		{
		}
	}
}

/******************************************************************************
* Name:        ResetWIRAlgorithm
* Description: Reset WIR Algorithm
******************************************************************************/		
STATIC INLINE FUNC(void, RTE_AP_WHLIMBREJ_APPL_CODE) ResetWIRAlgorithm(void)
{
	VAR(uint16, AUTOMATIC) Index_Cnt_T_u16;
	VAR(uint32, AUTOMATIC) CurrentTime_mS_T_u32p0;

	for (Index_Cnt_T_u16 = 0; Index_Cnt_T_u16 < TableSize_m(xRefDelayR_RadpSec_M_f32); Index_Cnt_T_u16++)
	{
		xRefDelayR_RadpSec_M_f32[Index_Cnt_T_u16] = 0.0F;
		xRefDelayL_RadpSec_M_f32[Index_Cnt_T_u16] = 0.0F;
		xRefSVR_Uls_M_f32[Index_Cnt_T_u16] = 0.0F;
		xRefSVL_Uls_M_f32[Index_Cnt_T_u16] = 0.0F;
	}
	
	PrevHwTrq_HwNm_M_f32 = 0.0F;
	Stage1SV1_Uls_M_f32 = 0.0F;
	Stage1SV2_Uls_M_f32 = 0.0F;
	Stage2SV1_Uls_M_f32 = 0.0F;
	Stage2SV2_Uls_M_f32 = 0.0F;

	WhlSpdRFiltSV_RadpSec_M_Str.SV_Uls_f32 = 0.0F;
	WhlSpdLFiltSV_RadpSec_M_Str.SV_Uls_f32 = 0.0F;

	PrevEnable_Uls_M_f32 = 0.0F;
	DistMagEnabled_Cnt_M_lgc = FALSE;
	PrevCalcEnable_Uls_M_f32 = 0.0F;

	CmdMagFiltSV1_MtrNm_M_Str.SV_Uls_f32 = 0.0F;
	CmdMagFiltSV2_MtrNm_M_Str.SV_Uls_f32 = 0.0F;

	RtLmtCurrMagR_Uls_M_f32 = 0.0F;
	RtLmtCurrMagL_Uls_M_f32 = 0.0F;

	TrendSV_MtrNm_M_Str.SV_Uls_f32 = 0.0F;
	Rte_Call_SystemTime_GetSystemTime_mS_u32(&CurrentTime_mS_T_u32p0);
	TrndThrStartTime_mS_M_u32p0 = CurrentTime_mS_T_u32p0;
	WhlSpdCorrFltTime_mS_M_u32p0 = CurrentTime_mS_T_u32p0;
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
