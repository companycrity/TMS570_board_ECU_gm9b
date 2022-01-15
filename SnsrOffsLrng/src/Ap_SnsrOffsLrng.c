/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SnsrOffsLrng.c
 *     Workspace:  C:/Users/nzt9hv/Documents/Synergy/ccm_wa/ses_dev_ea3/SnsrOffsLrng/autosar
 *     SW-C Type:  Ap_SnsrOffsLrng
 *  Generated at:  Mon Feb 22 15:23:29 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SnsrOffsLrng>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/****************************************************************************
* Copyright 2015,2016 Nexteer
* Nexteer Confidential
*
* Module File Name: Ap_SnsrOffsLrng.c
* Module Description: Sensor Offset learning
* Project           : CBD
* Author            : Selva Sengottaiyan
*****************************************************************************
 *  Version Control:
 * Date Created:
 * %version:           6 %
 * %date_modified:     nz4qtt %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author        Change Description                                                         SCR #
 * -------   -------  --------  --------------------------------------------------------------------------  ----------
 * 11/08/15   1       Selva      SF51 v1 Initial Creation                                                    EA3#3717
 * 02/11/16   2       Selva      updated SF51 v2 and v3 of FDD                                               EA3#5292
 * 04/28/16   3       KK         Updates to SF51A found in unit testing                                      EA3#8057
 * 08/17/16   4       SR         Updated for including FDD Requirement Links from v3.1.1                     EA3#8651
 * 08/19/16   5       SR         Implemented updates in SF051A Design based on anomaly EA4#10380             EA3#10386
 * 12/12/16   6       SR         Updated according to FDD version 3.3.0 to fix anomaly EA3#10925             EA3#12979
 *---------------------------------------------------------------------------------------------------------------------
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
    DataPtr Type to be used by WriteBlock, ReadBlock and RestoreBlockDefaults operations.     This type is used for all NVRAM blocks


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_SnsrOffsLrng.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include <math.h>
#include "GlobalMacro.h"
#include "fixmath.h"
#include "filters.h"
#include "CalConstants.h"
#include "float.h"

#define D_2PI_RADPREV_F32             6.283185307F 
#define D_COVMATINIT_ULS_F32          2000.0F
#define D_DEG2RAD_RADPDEG_F32         0.01745329252F 
#define D_FLTEPSILON_ULS_F32          FLT_EPSILON 
#define D_HWAGHILIM_HWDEG_F32         1440.0F 
#define D_HWAUTHYTHD_ULS_F32          0.99F 
#define D_HWTQLRNGSTSLRND_CNT_U08           4U
#define D_HWTQLRNGSTSNEGOFFS_CNT_U08        2U
#define D_HWTQLRNGSTSNOTLRND_CNT_U08        0U
#define D_HWTQLRNGSTSPOSOFFS_CNT_U08        1U
#define D_HWTQLRNGSTSZEROOFFS_CNT_U08         3U
#define D_HWTQLRNGTMRHILIM_SEC_F32            1023.0F 
#define D_IVS10MS_ULSPS_F32                   100.0F 
#define D_LRNGFILTTICON_ULS_F32               1.099403F 
#define D_MILLISECTOSEC_SPMS_F32              0.001F 
#define D_SPDCNVN_MPSECPKPH_F32               0.2778F 
#define D_TISTEP10MS_MIN_F32                  1.6667e-04F 
#define D_TISTEP10MS_SEC_F32                  0.01F 
#define D_TQINPDETNLOGGAIN_ULS_F32            10.0F 
#define D_TQINPDETNLOGINPHILIM_ULS_F32        1000.0F 
#define D_TQINPDETNLOGINPLOLIM_ULS_F32        2.32831e-10F 
#define D_YAWELPSDTIHILIM_MIN_F32             1440.0F 
#define D_YAWRATENOISE_VEHDEGPS_F32           0.2F 
#define D_TIMINTOSEC_SEC_F32                  60.0F 

#define D_MATRIXSIZE_CNT_U08                  3U
#define D_STAGEONEBUFSIZE_CNT_U08             72U
/* MISRA-C:2004 Rule  8.7 : This deviation is required for Module Level Variable. Rule suppressed by line at each occurrence. */

/* MISRA-C:2004 Rule 10.4 : This deviation is required because of Nexteer macro library.  Rule suppressed by line at each occurrence. */
/* MISRA-C:2004 Rule 16.10: Deviation needed because return values cannot be used at this level. */
/* MISRA-C:2004 Rule 17.4 : This deviation is required for AUTOSAR memory map requirements. Rule suppressed by line at each occurrence. */
/* MISRA-C:2004 Rule 19.1 : This deviation is required for AUTOSAR memory map requirements. Rule suppressed by line at each occurrence. */
/* MISRA-C:2004 Rule 12.4 : No side effect - right hand is read only.Rule suppressed by line at each occurrence. */

#define SNSROFFSLRNG_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_HwAgLrngEna_Cnt_D_lgc; /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_HwAgLrngLrngCdnVld_Cnt_D_lgc; /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_HwAgLrngRst_Cnt_D_lgc; /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_HwAgLrngSysTqVldt_Cnt_D_lgc; /* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_HwAgLrngTiVldt_Cnt_D_lgc;/* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_HwTqLrngEstimnVld_Cnt_D_lgc;/* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_HwTqLrngLrngEna_Cnt_D_lgc;/* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_HwTqLrngMeasEna_Cnt_D_lgc;/* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_HwTqLrngTrqInptPrsntVld_Cnt_D_lgc;/* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_HwTqLrngTrqInptPrsnt_Cnt_D_lgc;/* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_YawLrngEna_Cnt_D_lgc;/* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_YawLrngLrngCdnVld_Cnt_D_lgc;/* PRQA S 3218 */
STATIC volatile VAR(boolean, AP_SNSROFFSLRNG_VAR)  SOaC_TrqInptPrsntRaw_Cnt_D_lgc;/* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) SOaC_SetRamBlkSts_Cnt_M_lgc;/* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) SOaC_VehYawRateOffsFrsh_Cnt_M_lgc;/* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) SOaC_HwTqLrngTqInpPrsnt_Cnt_M_lgc;/* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) SOaC_HwTqLrngTqInpDetnEnaPrev_Cnt_M_lgc;/* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) SOaC_VehYawRateLrngStRst_Cnt_M_lgc;/* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) SOaC_HwAgLrngStRst_Cnt_M_lgc;/* PRQA S 3218 */
STATIC VAR(boolean, AUTOMATIC) SOaC_HwTqLrngStRst_Cnt_M_lgc;/* PRQA S 3218 */
#define SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define SNSROFFSLRNG_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_HwAgFild_HwDeg_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_HwAgLrngSysTqLoThd_HwNm_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_HwAgLrngSysTqUpThd_HwNm_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_HwTqLrngHwAgMeas_HwDeg_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_HwTqLrngHwTqMeas_HwNm_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_HwTqLrngHwTqOffsRaw_HwNm_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_HwTqLrngSampleCntTot_Cnt_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_HwTqLrngSampleImb_Uls_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_HwVelFild_HwRadpS_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_SysTqFild_HwNm_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_TqInpDetnHwTqFild_HwNm_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_TqInpDetnStg1Outp_dB_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_YawA_VehDegpSSq_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_YawLrngBiasEstimnRaw_VehDegpS_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_YawRateFildCorrd_VehDegpS_D_f32;/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_SNSROFFSLRNG_VAR) SOaC_YawRateFild_VehDegpS_D_f32;/* PRQA S 3218 */
STATIC  VAR(float32, AUTOMATIC) SOaC_TqInpDetnHwTqPreProc_dB_M_f32;/* PRQA S 3218 */
STATIC  VAR(float32, AUTOMATIC) SOaC_TqInpDetnStg2CenFiltSt2_Uls_M_f32;/* PRQA S 3218 */
STATIC  VAR(float32, AUTOMATIC) SOaC_TqInpDetnStg2CenFiltSt1_Uls_M_f32;/* PRQA S 3218 */
STATIC  VAR(float32, AUTOMATIC) SOaC_TqInpDetnStg2UpFiltSt2_Uls_M_f32;/* PRQA S 3218 */
STATIC  VAR(float32, AUTOMATIC) SOaC_TqInpDetnStg2UpFiltSt1_Uls_M_f32;/* PRQA S 3218 */
STATIC  VAR(float32, AUTOMATIC) SOaC_TqInpDetnStg2DwnFiltSt2_Uls_M_f32;/* PRQA S 3218 */
STATIC  VAR(float32, AUTOMATIC) SOaC_TqInpDetnStg2DwnFiltSt1_Uls_M_f32;/* PRQA S 3218 */
STATIC  VAR(float32, AUTOMATIC) SOaC_TqInpDetnStg1FiltSt2_Uls_M_f32;/* PRQA S 3218 */
STATIC  VAR(float32, AUTOMATIC) SOaC_TqInpDetnStg1FiltSt1_Uls_M_f32;/* PRQA S 3218 */
STATIC  VAR(float32, AUTOMATIC) SOaC_TqInpDetnStg1Buf_HwNm_M_f32[D_STAGEONEBUFSIZE_CNT_U08];/* PRQA S 3218 */

STATIC  VAR(float32, AUTOMATIC) SOaC_TqInpDetnEnaTi_Sec_M_f32;/* PRQA S 3218 */
STATIC  VAR(float32, AUTOMATIC) SOaC_TqInpDetnSinGenrAg_Rad_M_f32;/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) SOaC_HwAgLrngDrvgDst_Metr_M_f32;/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) SOaC_YawLrngElpdLrngTi_Sec_M_f32;/* PRQA S 3218 */
STATIC VAR(float32, AUTOMATIC) SOaC_YawRatePrev_VehDegpS_M_f32;/* PRQA S 3218 */
STATIC VAR(uint32, AUTOMATIC) SOaC_HwTqLrngMeasTmrRef_mS_M_u32;/* PRQA S 3218 */
STATIC VAR(uint32, AUTOMATIC) SOaC_HwTqLrngEnaTmrRef_mS_M_u32;/* PRQA S 3218 */

#define SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */


#define SNSROFFSLRNG_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_HwAgLrngSysTqFil2_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_TqInpDetnHwTqFil_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_HwTqLrngHwTqMeasFil1_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_HwTqLrngHwAgMeasFil1_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_HwTqLrngHwAgMeasFil2_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_YawCdngFil1_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_YawACdngFil_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_YawCdngFil2_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_HwVelCdngFil_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_HwAgCdngFil_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_YawLrngFil1_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_HwAgLrngFil1_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_YawLrngFil2_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_HwAgLrngSysTqFil1_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_HwAgLrngFil2_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_HwTqLrngHwTqMeasFil2_Uls_M_str;
STATIC VAR(LPF32KSV_Str, AUTOMATIC) SOaC_SysTqCdngFil_Uls_M_str;
#define SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */


#define SNSROFFSLRNG_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AUTOMATIC) SOaC_TqInpDetnStg1Idx_Cnt_M_u08;/* PRQA S 3218 */
STATIC VAR(uint8, AUTOMATIC) SOac_HwTqLrngSts_Cnt_M_u08;
#define SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */


#define SNSROFFSLRNG_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AUTOMATIC) SOaC_TqInpDetnPreProcEnaLoop_Cnt_M_u16; /* PRQA S 3218 */
#define SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE) LearnHwAg(VAR(boolean, AUTOMATIC)  HwAgLrngLrngCdnVld_Cnt_T_lgc, VAR(boolean, AUTOMATIC)  EnablePOC_Cnt_T_lgc, VAR(float32, AUTOMATIC) SysTqFild_HwNm_T_f32,VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32 );

STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)SOaCHierarchyManager(P2VAR(boolean, AUTOMATIC, AUTOMATIC) EnableYOC_Cnt_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC) EnablePOC_Cnt_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC) HwAgLrngRst_Cnt_T_lgc);

STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)Perform_TqInpDetn(void);

STATIC INLINE FUNC(boolean, AP_SNSROFFSLRNG_CODE)EnableLearning(void);

STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)EnablePreProcessing(VAR(float32, AUTOMATIC) HwTqPreproc_dB_T_f32, VAR(uint16, AUTOMATIC)SampleCntrLim_Cnt_T_u16, P2VAR(boolean, AUTOMATIC, AUTOMATIC) TqInpPrsntVld_Cnt_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC) TqInpPrsnt_Cnt_T_lgc);

STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE) CalculateKVector(CONST(float32, AUTOMATIC) TqMdlXAry_HwRadpS_T_f32[D_MATRIXSIZE_CNT_U08], P2VAR(float32, AUTOMATIC, AUTOMATIC) KVect_Uls_T_f32);

STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)UpdateCovarianceMatrix(P2CONST(float32, AUTOMATIC,AUTOMATIC) TqMdlAryKVect_Uls_T_f32, VAR(uint16, AUTOMATIC) TblSize_Cnt_T_u16);

STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)UpdateHwTqOffs(VAR(boolean, AUTOMATIC) HwTqEstimnVld_Cnt_T_lgc, VAR(float32, AUTOMATIC) HwTqDriftEstimnOnCentr_HwNm_T_f32);

STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)UpdateSampleCnt( VAR(float32, AUTOMATIC) HwAgMeasrmnt_HwDeg_T_f32);
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
 * UInt32: Integer in interval [0...4294967295] (standard type)
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
 * DT_Array3_f32: Array with 3 element(s) of type Float
 * DT_Array3x3_f32: Array with 3 element(s) of type DT_Array3_f32
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
 *
 * Record Types:
 * =============
 * SnsrLrndOffs_Str: Record with elements
 *   HwAgLrndTi of type Float
 *   YawRateElpdTi of type Float
 *   HwTqLrngCovariMtrx of type DT_Array3x3_f32
 *   HwTqLrngEstimnVect of type DT_Array3_f32
 *   YawRateOffs of type SInt16
 *   HwAgOffs of type SInt16
 *   HwTqOffs of type SInt16
 *   HwAgLrngYawOffsRef of type SInt16
 *   HwAgLrngHwAgFilSt of type SInt16
 *   HwAgLrngSysTqFilSt of type SInt16
 *   HwTqLrngHwAgRef of type SInt16
 *   HwTqLrngSampleCntNeg of type UInt16
 *   HwTqLrngSampleCntPos of type UInt16
 *   HwTqLrngSts of type UInt8
 *   YawRateOffsVld of type Boolean
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
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt8: D_NEGONE_CNT_S8 = -1
 * UInt16: D_ONE_CNT_U16 = 1u
 * UInt16: D_ZERO_CNT_U16 = 0u
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
 *   SnsrLrndOffs_Str *Rte_Pim_SnsrLrndOffs(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_SNSROFFSLRNG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsLrng_Init1
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
 *   void Rte_IWrite_SnsrOffsLrng_Init1_HwAgOffs_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_SnsrOffsLrng_Init1_HwAgOffs_HwDeg_f32(void)
 *   void Rte_IWrite_SnsrOffsLrng_Init1_HwTqOffs_HwNm_f32(Float data)
 *   Float *Rte_IWriteRef_SnsrOffsLrng_Init1_HwTqOffs_HwNm_f32(void)
 *   void Rte_IWrite_SnsrOffsLrng_Init1_VehYawRateOffs_DegpS_f32(Float data)
 *   Float *Rte_IWriteRef_SnsrOffsLrng_Init1_VehYawRateOffs_DegpS_f32(void)
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SnsrLrndOffsBlk_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_Init1(void) /* REQ: SF051A #46 I */ /* REQ: SF051A #210 I */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsLrng_Init1
 *********************************************************************************************************************/
VAR(float32, AUTOMATIC) YawLrngLrngFiltFreq_Hz_T_f32; 
VAR(float32, AUTOMATIC) HwAgLrngFiltFreq_Hz_T_f32;
VAR(float32, AUTOMATIC) HwTqLrngFiltFreq_Hz_T_f32;
VAR(float32, AUTOMATIC) HwAgOffs_HwDeg_T_f32;
VAR(float32, AUTOMATIC) HwTqOffs_HwNm_T_f32;
VAR(float32, AUTOMATIC) VehYawRateOffs_DegpS_T_f32;

VAR(NvM_RequestResultType,AUTOMATIC) NVMStatusReqRes_Cnt_T_enum;
 
/**************************Filter Initialisation***************/ 

 /*********** Signal Conditioning filters*****************/ 
LPF_KUpdate_f32_m(k_SOaC_YawRateCdngFiltFreq_Hz_f32, D_TISTEP10MS_SEC_F32, &SOaC_YawCdngFil1_Uls_M_str);
LPF_KUpdate_f32_m(k_SOaC_YawRateCdngFiltFreq_Hz_f32, D_TISTEP10MS_SEC_F32, &SOaC_YawCdngFil2_Uls_M_str);
LPF_KUpdate_f32_m(k_SOaC_YawACdngFiltFreq_Hz_f32, D_TISTEP10MS_SEC_F32, &SOaC_YawACdngFil_Uls_M_str);
LPF_KUpdate_f32_m(k_SOaC_TqAndAgFiltFreq_Hz_f32, D_TISTEP10MS_SEC_F32, &SOaC_HwAgCdngFil_Uls_M_str);
LPF_KUpdate_f32_m(k_SOaC_HwVelFiltFreq_Hz_f32, D_TISTEP10MS_SEC_F32, &SOaC_HwVelCdngFil_Uls_M_str);
LPF_KUpdate_f32_m(k_SOaC_TqAndAgFiltFreq_Hz_f32, D_TISTEP10MS_SEC_F32, &SOaC_SysTqCdngFil_Uls_M_str);


/***********Offset learning filters****************/
YawLrngLrngFiltFreq_Hz_T_f32 =    D_LRNGFILTTICON_ULS_F32 / k_SOaC_YawLrngLrngTi_Sec_f32;

LPF_KUpdate_f32_m(YawLrngLrngFiltFreq_Hz_T_f32, D_TISTEP10MS_SEC_F32, &SOaC_YawLrngFil1_Uls_M_str);
LPF_KUpdate_f32_m(YawLrngLrngFiltFreq_Hz_T_f32, D_TISTEP10MS_SEC_F32, &SOaC_YawLrngFil2_Uls_M_str);


HwAgLrngFiltFreq_Hz_T_f32 = D_LRNGFILTTICON_ULS_F32/ k_SOaC_HwAgLrngLrngTi_Sec_f32;
LPF_KUpdate_f32_m(HwAgLrngFiltFreq_Hz_T_f32, D_TISTEP10MS_SEC_F32, &SOaC_HwAgLrngFil1_Uls_M_str);
LPF_KUpdate_f32_m(HwAgLrngFiltFreq_Hz_T_f32, D_TISTEP10MS_SEC_F32, &SOaC_HwAgLrngFil2_Uls_M_str);

LPF_KUpdate_f32_m(HwAgLrngFiltFreq_Hz_T_f32, D_TISTEP10MS_SEC_F32, &SOaC_HwAgLrngSysTqFil1_Uls_M_str);
LPF_KUpdate_f32_m(HwAgLrngFiltFreq_Hz_T_f32, D_TISTEP10MS_SEC_F32, &SOaC_HwAgLrngSysTqFil2_Uls_M_str);

/******Torque Input Detection Filters******************/

HwTqLrngFiltFreq_Hz_T_f32 =D_LRNGFILTTICON_ULS_F32 / k_SOaC_HwTqLrngMeasTi_Sec_f32;
LPF_KUpdate_f32_m(k_SOaC_TqInpDetnHwTqFiltFreq_Hz_f32, D_2MS_SEC_F32, &SOaC_TqInpDetnHwTqFil_Uls_M_str);
LPF_KUpdate_f32_m(HwTqLrngFiltFreq_Hz_T_f32, D_2MS_SEC_F32, &SOaC_HwTqLrngHwTqMeasFil1_Uls_M_str);
LPF_KUpdate_f32_m(HwTqLrngFiltFreq_Hz_T_f32, D_2MS_SEC_F32, &SOaC_HwTqLrngHwTqMeasFil2_Uls_M_str);
LPF_KUpdate_f32_m(HwTqLrngFiltFreq_Hz_T_f32, D_2MS_SEC_F32, &SOaC_HwTqLrngHwAgMeasFil1_Uls_M_str);
LPF_KUpdate_f32_m(HwTqLrngFiltFreq_Hz_T_f32, D_2MS_SEC_F32, &SOaC_HwTqLrngHwAgMeasFil2_Uls_M_str);


/****************NVM Management******************/
(void)Rte_Call_SnsrLrndOffsBlk_GetErrorStatus(&NVMStatusReqRes_Cnt_T_enum);

/* REQ: SF051A #26  I */
/* REQ: SF051A #245 I */
/* REQ: SF051A #45  I */
/* REQ: SF051A #244 I */
if(FALSE == k_SOaC_FctEna_Cnt_lgc) /*Not Enabled*/
{
    HwAgOffs_HwDeg_T_f32 = D_ZERO_ULS_F32;          /* REQ: SF051A #245 I */
    HwTqOffs_HwNm_T_f32 =D_ZERO_ULS_F32;            /* REQ: SF051A #45  I */
    VehYawRateOffs_DegpS_T_f32 = D_ZERO_ULS_F32;    /* REQ: SF051A #244 I */

    SOaC_SetRamBlkSts_Cnt_M_lgc = FALSE;
}
else if(NVMStatusReqRes_Cnt_T_enum !=  NVM_REQ_OK)  /*Data Invalid*/
{
    /* REQ: SF051A #209 I */
    HwAgOffs_HwDeg_T_f32 = D_ZERO_ULS_F32;
    HwTqOffs_HwNm_T_f32 =D_ZERO_ULS_F32;
    VehYawRateOffs_DegpS_T_f32 = D_ZERO_ULS_F32;
    /* ENDREQ: SF051A #209 */
    
    /* REQ: SF051A #81 I */
    Rte_Pim_SnsrLrndOffs()->YawRateOffs= D_ZERO_CNT_S16;
    Rte_Pim_SnsrLrndOffs()->HwAgOffs= D_ZERO_CNT_S16;
    Rte_Pim_SnsrLrndOffs()->HwTqOffs= D_ZERO_CNT_S16;
    Rte_Pim_SnsrLrndOffs()->HwAgLrndTi= D_ZERO_ULS_F32;
    Rte_Pim_SnsrLrndOffs()->HwAgLrngYawOffsRef= D_ZERO_CNT_S16;
    Rte_Pim_SnsrLrndOffs()->YawRateElpdTi= D_YAWELPSDTIHILIM_MIN_F32;
    Rte_Pim_SnsrLrndOffs()->HwAgLrngHwAgFilSt= D_ZERO_CNT_S16;
    Rte_Pim_SnsrLrndOffs()->HwAgLrngSysTqFilSt= D_ZERO_CNT_S16;
    Rte_Pim_SnsrLrndOffs()->HwTqLrngHwAgRef=FPM_FloatToFixed_m(D_HWAGHILIM_HWDEG_F32,s11p4_T); 
    (Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect)[0]= D_ZERO_ULS_F32;
    (Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect)[1]= D_ZERO_ULS_F32;
    (Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect)[2]= D_ZERO_ULS_F32;
    (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[0][0]= D_COVMATINIT_ULS_F32;
    (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[0][1]= D_ZERO_ULS_F32;
    (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[0][2]= D_ZERO_ULS_F32;
    (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[1][0]= D_ZERO_ULS_F32;
    (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[1][1]= D_COVMATINIT_ULS_F32;
    (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[1][2]= D_ZERO_ULS_F32;
    (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[2][0]= D_ZERO_ULS_F32;
    (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[2][1]= D_ZERO_ULS_F32;
    (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[2][2]= D_COVMATINIT_ULS_F32;
    Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntNeg= D_ZERO_CNT_U16;
    Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntPos= D_ZERO_CNT_U16;
    Rte_Pim_SnsrLrndOffs()->HwTqLrngSts= D_ZERO_CNT_U8;
    Rte_Pim_SnsrLrndOffs()->YawRateOffsVld= FALSE; /* REQ: SF051A #113 I */
    /* ENDREQ: SF051A #81 */
    SOaC_SetRamBlkSts_Cnt_M_lgc = TRUE;
}
/* REQ: SF051A #46 I */
else    /*Data Valid*/
{
    /************Check the naming rules for elements in structure************/
    VehYawRateOffs_DegpS_T_f32 = Limit_m(FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->YawRateOffs,s6p9_T), -k_SOaC_YawRateOffsLim_VehDegpS_f32, k_SOaC_YawRateOffsLim_VehDegpS_f32);  /* REQ: SF051A #199 I */
    SOaC_YawLrngFil1_Uls_M_str.SV_Uls_f32 = VehYawRateOffs_DegpS_T_f32;
    SOaC_YawLrngFil2_Uls_M_str.SV_Uls_f32 = VehYawRateOffs_DegpS_T_f32;

    HwAgOffs_HwDeg_T_f32 = Limit_m(FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->HwAgOffs,s5p10_T),-k_SOaC_HwAgOffsLim_HwDeg_f32 , k_SOaC_HwAgOffsLim_HwDeg_f32);  /* REQ: SF051A #200 I */

    SOaC_HwAgLrngFil1_Uls_M_str.SV_Uls_f32 = FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->HwAgLrngHwAgFilSt,s11p4_T);
    SOaC_HwAgLrngFil2_Uls_M_str.SV_Uls_f32 = SOaC_HwAgLrngFil1_Uls_M_str.SV_Uls_f32;

    SOaC_HwAgLrngSysTqFil1_Uls_M_str.SV_Uls_f32 = FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->HwAgLrngSysTqFilSt,s10p5_T);

    SOaC_HwAgLrngSysTqFil2_Uls_M_str.SV_Uls_f32 = SOaC_HwAgLrngSysTqFil1_Uls_M_str.SV_Uls_f32;

    HwTqOffs_HwNm_T_f32 = Limit_m(FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->HwTqOffs,s3p12_T), -k_SOaC_HwTqOffsLim_HwNm_f32, k_SOaC_HwTqOffsLim_HwNm_f32); /* REQ: SF051A #197 I */
    SOaC_HwTqLrngHwTqMeasFil1_Uls_M_str.SV_Uls_f32 =  HwTqOffs_HwNm_T_f32;
    SOaC_HwTqLrngHwTqMeasFil2_Uls_M_str.SV_Uls_f32 =  HwTqOffs_HwNm_T_f32;
    SOaC_SetRamBlkSts_Cnt_M_lgc = TRUE;
}
/* ENDREQ: SF051A #26 */

    (void)Rte_IWrite_SnsrOffsLrng_Init1_HwAgOffs_HwDeg_f32(HwAgOffs_HwDeg_T_f32); /* REQ: SF051A #80 I */
    (void)Rte_IWrite_SnsrOffsLrng_Init1_HwTqOffs_HwNm_f32(HwTqOffs_HwNm_T_f32); /* REQ: SF051A #16 I */
    (void)Rte_IWrite_SnsrOffsLrng_Init1_VehYawRateOffs_DegpS_f32(VehYawRateOffs_DegpS_T_f32); /* REQ: SF051A #79 I */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsLrng_Per1
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
 *   Float Rte_IRead_SnsrOffsLrng_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_SnsrOffsLrng_Per1_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_SnsrOffsLrng_Per1_HandwheelVelocity_HwRadpS_f32(void)
 *   Float Rte_IRead_SnsrOffsLrng_Per1_HwTorque_HwNm_f32(void)
 *   Boolean Rte_IRead_SnsrOffsLrng_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_SnsrOffsLrng_Per1_VehicleSpeed_Kph_f32(void)
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_Per1(void)   /* REQ: SF051A #207 I */  /* REQ: SF051A #150 I */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsLrng_Per1
 *********************************************************************************************************************/

    VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
    VAR(boolean, AUTOMATIC) HwTqLrngEna_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) NewMeasReady_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) HwTqEstimnVld_Cnt_T_lgc;

    VAR(float32, AUTOMATIC) HwTqDriftEstimnOnCentr_HwNm_T_f32;
    VAR(float32, AUTOMATIC) HwAgMeasrmnt_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) TqMdlXSclr_HwRadpS_T_f32;
    VAR(float32, AUTOMATIC) KVect_Uls_T_f32[D_MATRIXSIZE_CNT_U08];

    CONST(float32, AUTOMATIC) T_IDYMTRX_ULS_F32[D_MATRIXSIZE_CNT_U08][D_MATRIXSIZE_CNT_U08] = 
                                                           {{D_ONE_ULS_F32 ,D_ZERO_ULS_F32,D_ZERO_ULS_F32},
                                                            {D_ZERO_ULS_F32,D_ONE_ULS_F32 ,D_ZERO_ULS_F32},
                                                            {D_ZERO_ULS_F32,D_ZERO_ULS_F32,D_ONE_ULS_F32 }};

    VAR(float32, AUTOMATIC) TqMdlAryKVect_Uls_T_f32[D_MATRIXSIZE_CNT_U08][D_MATRIXSIZE_CNT_U08];
    VAR(uint8, AUTOMATIC)   HwTqLrngSts_Cnt_T_u08;
    VAR(float32, AUTOMATIC) SampleImb_Uls_T_f32;
    VAR(float32, AUTOMATIC) HwAgMeasrmnt_HwRad_T_f32;
    VAR(float32, AUTOMATIC) TqMdlXAry_HwRadpS_T_f32[D_MATRIXSIZE_CNT_U08];
    VAR(float32, AUTOMATIC) SampleCntTot_Cnt_T_f32;
    VAR(float32, AUTOMATIC) HwTqMeasrmnt_HwNm_T_f32;
    VAR(uint16, AUTOMATIC)  IterCnt1_Cnt_T_u16,IterCnt2_Cnt_T_u16;
    VAR(uint32, AUTOMATIC)  Elapsedtime_mS_T_u32;
    
    HandwheelPosition_HwDeg_T_f32    = Rte_IRead_SnsrOffsLrng_Per1_HandwheelPosition_HwDeg_f32();   /* REQ: SF051A #170 I */
    HwTorque_HwNm_T_f32              = Rte_IRead_SnsrOffsLrng_Per1_HwTorque_HwNm_f32();             /* REQ: SF051A #168 I */ /* REQ: SF051A #12 I */
    
    
     
    HwTqLrngEna_Cnt_T_lgc= EnableLearning();
    SOaC_HwTqLrngMeasEna_Cnt_D_lgc =  HwTqLrngEna_Cnt_T_lgc;
    /* REQ: SF051A #162 I */
    if(HwTqLrngEna_Cnt_T_lgc == TRUE)
    {
        /***************************Measurements_Grabber*************************/
        /* REQ: SF051A #163 I */
        (void)LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32, &SOaC_HwTqLrngHwTqMeasFil1_Uls_M_str);/* REQ: SF051A #160 I */
        (void)LPF_OpUpdate_f32_m(HandwheelPosition_HwDeg_T_f32, &SOaC_HwTqLrngHwAgMeasFil1_Uls_M_str); /* REQ: SF051A #158 I */

        HwTqMeasrmnt_HwNm_T_f32  = LPF_OpUpdate_f32_m(SOaC_HwTqLrngHwTqMeasFil1_Uls_M_str.SV_Uls_f32,
                                                      &SOaC_HwTqLrngHwTqMeasFil2_Uls_M_str);/* REQ: SF051A #160 I */ /* REQ: SF051A #161 I */
        HwAgMeasrmnt_HwDeg_T_f32 = LPF_OpUpdate_f32_m(SOaC_HwTqLrngHwAgMeasFil1_Uls_M_str.SV_Uls_f32,
                                                      &SOaC_HwTqLrngHwAgMeasFil2_Uls_M_str);/* REQ: SF051A #158 I */ /* REQ: SF051A #159 I */
        (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(SOaC_HwTqLrngMeasTmrRef_mS_M_u32,&Elapsedtime_mS_T_u32); /* REQ: SF051A #157 I */

        /* REQ: SF051A #154 I */
        if( (k_SOaC_HwTqLrngMeasTi_Sec_f32 *k_SOaC_HwTqLrngMeasTiSca_Uls_f32)>=(D_MILLISECTOSEC_SPMS_F32*(float32)Elapsedtime_mS_T_u32) )
        {
            NewMeasReady_Cnt_T_lgc = FALSE;
            HwTqMeasrmnt_HwNm_T_f32 = D_ZERO_ULS_F32;
            HwAgMeasrmnt_HwDeg_T_f32 = D_ZERO_ULS_F32;
            HwTqLrngSts_Cnt_T_u08 = Rte_Pim_SnsrLrndOffs()->HwTqLrngSts;
        }
        else
        {
            /* REQ: SF051A #154 I */
            NewMeasReady_Cnt_T_lgc = TRUE;  /* REQ: SF051A #155 I */
            Rte_Pim_SnsrLrndOffs()->HwTqLrngHwAgRef = FPM_FloatToFixed_m(HwAgMeasrmnt_HwDeg_T_f32,s11p4_T); /* PRQA S 4395 */   /* REQ: SF051A #153 I */
            (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SOaC_HwTqLrngMeasTmrRef_mS_M_u32);
            /* ENDREQ: SF051A #154 */
            /* ENDREQ: SF051A #163 */
            
            /* REQ: SF051A #182 I */
            /***************************Learning****************************/
            /* REQ: SF051A #167 I */
            /* REQ: SF051A #152 I */
            /*************Counter*************/
            UpdateSampleCnt(HwAgMeasrmnt_HwDeg_T_f32);  /* REQ: SF051A #184 I */
            SampleCntTot_Cnt_T_f32 =((float32)Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntPos + (float32)Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntNeg); /* REQ: SF051A #177 I */
            SOaC_HwTqLrngSampleCntTot_Cnt_D_f32 =  SampleCntTot_Cnt_T_f32;
            
            /***********HwPos vs HwTrq Model****************/
            /* REQ: SF051A #183 I */
            TqMdlXAry_HwRadpS_T_f32[0U]= D_ONE_ULS_F32;
            HwAgMeasrmnt_HwRad_T_f32=HwAgMeasrmnt_HwDeg_T_f32*D_DEG2RAD_RADPDEG_F32;
            TqMdlXAry_HwRadpS_T_f32[1U]= sinf(HwAgMeasrmnt_HwRad_T_f32);
            TqMdlXAry_HwRadpS_T_f32[2U]= cosf(HwAgMeasrmnt_HwRad_T_f32);
            /*******************Recursive Least Square Regression*****************/
            /* REQ: SF051A #176 I */
            /***************Calculate K Vector****************************/
            CalculateKVector(TqMdlXAry_HwRadpS_T_f32, KVect_Uls_T_f32);
            /**************Matrix Multiply dimensions (3*1) * (1*3)*******/ 
            for(IterCnt1_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt1_Cnt_T_u16<TableSize_m(KVect_Uls_T_f32);IterCnt1_Cnt_T_u16++)
            {
                for(IterCnt2_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt2_Cnt_T_u16<TableSize_m(TqMdlXAry_HwRadpS_T_f32);IterCnt2_Cnt_T_u16++)
                {
                    TqMdlAryKVect_Uls_T_f32[IterCnt1_Cnt_T_u16][IterCnt2_Cnt_T_u16]= T_IDYMTRX_ULS_F32[IterCnt1_Cnt_T_u16][IterCnt2_Cnt_T_u16] -(KVect_Uls_T_f32[IterCnt1_Cnt_T_u16] * TqMdlXAry_HwRadpS_T_f32[IterCnt2_Cnt_T_u16]); 
                }
            }

            UpdateCovarianceMatrix(TqMdlAryKVect_Uls_T_f32[0U],  (TableSize_m(KVect_Uls_T_f32)));
            /***********Update BETA_k************/
            TqMdlXSclr_HwRadpS_T_f32 =D_ZERO_ULS_F32;
            for(IterCnt1_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt1_Cnt_T_u16< (TableSize_m(TqMdlXAry_HwRadpS_T_f32)); IterCnt1_Cnt_T_u16++)
            {
                TqMdlXSclr_HwRadpS_T_f32 += Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect[IterCnt1_Cnt_T_u16] *  TqMdlXAry_HwRadpS_T_f32[IterCnt1_Cnt_T_u16];
            }
            for(IterCnt1_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt1_Cnt_T_u16< (TableSize_m(KVect_Uls_T_f32)); IterCnt1_Cnt_T_u16++)
            {
                /*REQ: SF051A #174 I */ /*REQ: SF051A #173 I */ /* REQ: SF051A #151 I */
                Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect[IterCnt1_Cnt_T_u16] += ((HwTqMeasrmnt_HwNm_T_f32 - TqMdlXSclr_HwRadpS_T_f32)*KVect_Uls_T_f32[IterCnt1_Cnt_T_u16]);
            }
            /* ENDREQ: SF051A #176 */
            /* ENDREQ: SF051A #183 */
            
            /****************CalculateOnCenterTorqueDrift********************/
            HwTqDriftEstimnOnCentr_HwNm_T_f32 =  Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect[0U] +Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect[2U];
            SOaC_HwTqLrngHwTqOffsRaw_HwNm_D_f32 =  HwTqDriftEstimnOnCentr_HwNm_T_f32;
            
            /*********ForgettingFactor***********************/
            /* REQ: SF051A #243 I */
            if((uint16)SampleCntTot_Cnt_T_f32 > k_SOaC_HwTqLrngSampleCntForLrngRst_Cnt_u16)
            {
                /*NVM*/
                Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntNeg      = D_ZERO_CNT_U16;
                Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntPos      = D_ZERO_CNT_U16;
                Rte_Pim_SnsrLrndOffs()->HwTqLrngHwAgRef           = FPM_FloatToFixed_m(D_HWAGHILIM_HWDEG_F32,s11p4_T);
                (Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect)[0]   = D_ZERO_ULS_F32;
                (Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect)[1]   = D_ZERO_ULS_F32;
                (Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect)[2]   = D_ZERO_ULS_F32;
                (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[0][0]= D_COVMATINIT_ULS_F32;
                (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[0][1]= D_ZERO_ULS_F32;
                (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[0][2]= D_ZERO_ULS_F32;
                (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[1][0]= D_ZERO_ULS_F32;
                (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[1][1]= D_COVMATINIT_ULS_F32;
                (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[1][2]= D_ZERO_ULS_F32;
                (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[2][0]= D_ZERO_ULS_F32;
                (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[2][1]= D_ZERO_ULS_F32;
                (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[2][2]= D_COVMATINIT_ULS_F32;
                
                /*State Variables*/
                (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SOaC_HwTqLrngEnaTmrRef_mS_M_u32);
                (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SOaC_HwTqLrngMeasTmrRef_mS_M_u32);
                SOaC_HwTqLrngTqInpDetnEnaPrev_Cnt_M_lgc = FALSE;
                SOaC_HwTqLrngTqInpPrsnt_Cnt_M_lgc       = TRUE;
                
                /*LPFs*/
                SOaC_HwTqLrngHwAgMeasFil1_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
                SOaC_HwTqLrngHwAgMeasFil2_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
                SOaC_HwTqLrngHwTqMeasFil1_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
                SOaC_HwTqLrngHwTqMeasFil2_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
                SOaC_TqInpDetnHwTqFil_Uls_M_str.SV_Uls_f32     = D_ZERO_ULS_F32;
            } 
            /* ENDREQ: SF051A #243 */
            
            /*********ValidityCheck***********************/
            if((Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntPos >D_ZERO_CNT_U16) && (Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntNeg>D_ZERO_CNT_U16))/* SampleCntTot_Cnt_T_f32>D_ZERO_ULS_F32 is implied if expr is true*/
            {
                SampleImb_Uls_T_f32 = Abs_f32_m((float32)Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntPos - (float32)Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntNeg) / SampleCntTot_Cnt_T_f32;
                SOaC_HwTqLrngSampleImb_Uls_D_f32 = SampleImb_Uls_T_f32;
                if((SampleCntTot_Cnt_T_f32>=(float32)k_SOaC_HwTqLrngSampleThd2_Cnt_u16) &&(SampleImb_Uls_T_f32<=k_SOaC_HwTqLrngSampleImbThd2_Uls_f32)) /* REQ: SF051A #191 I */ /* REQ: SF051A #187 I */
                {
                    HwTqLrngSts_Cnt_T_u08  = D_HWTQLRNGSTSLRND_CNT_U08;
                    HwTqEstimnVld_Cnt_T_lgc  = TRUE;
                }
                else if((SampleCntTot_Cnt_T_f32>=(float32)k_SOaC_HwTqLrngSampleThd1_Cnt_u16) &&(SampleImb_Uls_T_f32<=k_SOaC_HwTqLrngSampleImbThd1_Uls_f32))
                {
                    HwTqEstimnVld_Cnt_T_lgc  = FALSE; /* REQ: SF051A #188 I */
                    if((HwTqDriftEstimnOnCentr_HwNm_T_f32 >k_SOaC_HwTqLrngHwTqZeroOffsThd_HwNm_f32)) /* REQ: SF051A #186 I */
                    {
                        HwTqLrngSts_Cnt_T_u08 =D_HWTQLRNGSTSPOSOFFS_CNT_U08;
                    }
                    else if(HwTqDriftEstimnOnCentr_HwNm_T_f32 < -k_SOaC_HwTqLrngHwTqZeroOffsThd_HwNm_f32) /* REQ: SF051A #195 I */
                    {
                        HwTqLrngSts_Cnt_T_u08 =D_HWTQLRNGSTSNEGOFFS_CNT_U08;
                    }
                    else /* REQ: SF051A #194 I */
                    {
                        HwTqLrngSts_Cnt_T_u08 =D_HWTQLRNGSTSZEROOFFS_CNT_U08; /* REQ: SF051A #188 I */
                    }
                }
                else
                {
                    HwTqEstimnVld_Cnt_T_lgc  = FALSE;
                    HwTqLrngSts_Cnt_T_u08  = D_HWTQLRNGSTSNOTLRND_CNT_U08;
                }
            }
            else
            {
                HwTqLrngSts_Cnt_T_u08  = D_HWTQLRNGSTSNOTLRND_CNT_U08;
                HwTqEstimnVld_Cnt_T_lgc  = FALSE;
            }
            Rte_Pim_SnsrLrndOffs()->HwTqLrngSts =HwTqLrngSts_Cnt_T_u08; /* REQ: SF051A #189 I */
            SOaC_HwTqLrngEstimnVld_Cnt_D_lgc = HwTqEstimnVld_Cnt_T_lgc;
            UpdateHwTqOffs(HwTqEstimnVld_Cnt_T_lgc, HwTqDriftEstimnOnCentr_HwNm_T_f32);
            /* ENDREQ: SF051A #182 */
        }   /* ENDREQ: SF051A #167 */ /* ENDREQ: SF051A #152 */
        SOaC_HwTqLrngHwTqMeas_HwNm_D_f32 = HwTqMeasrmnt_HwNm_T_f32;
        SOaC_HwTqLrngHwAgMeas_HwDeg_D_f32 = HwAgMeasrmnt_HwDeg_T_f32;
        SOaC_HwTqLrngLrngEna_Cnt_D_lgc = NewMeasReady_Cnt_T_lgc;
    }
    else
    {
        HwTqLrngSts_Cnt_T_u08 = Rte_Pim_SnsrLrndOffs()->HwTqLrngSts;
        SOaC_HwTqLrngLrngEna_Cnt_D_lgc = FALSE;
        (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SOaC_HwTqLrngMeasTmrRef_mS_M_u32); /* REQ: SF051A #156 I */
    }/*ENDREQ: SF051A #162 */
    SOac_HwTqLrngSts_Cnt_M_u08 = HwTqLrngSts_Cnt_T_u08;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsLrng_Per2
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
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_SnsrOffsLrng_Per2_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_SnsrOffsLrng_Per2_HandwheelPosition_HwDeg_f32(void)
 *   Float Rte_IRead_SnsrOffsLrng_Per2_HandwheelVelocity_HwRadpS_f32(void)
 *   Float Rte_IRead_SnsrOffsLrng_Per2_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_SnsrOffsLrng_Per2_TorqueCmdCRF_MtrNm_f32(void)
 *   Boolean Rte_IRead_SnsrOffsLrng_Per2_VehicleSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_SnsrOffsLrng_Per2_VehicleSpeed_Kph_f32(void)
 *   Boolean Rte_IRead_SnsrOffsLrng_Per2_VehicleYawRateValid_Cnt_lgc(void)
 *   Float Rte_IRead_SnsrOffsLrng_Per2_VehicleYawRate_DegpS_f32(void)
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

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_Per2(void) /* REQ: SF051A #206 I */ /* REQ: SF051A #208 I */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsLrng_Per2
 *********************************************************************************************************************/

    VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32;
    VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
    VAR(float32, AUTOMATIC) YawLrngBiasEstimnRaw_VehDegpS_T_f32;
    VAR(float32, AUTOMATIC) YawLrngElpdLrngTi_Sec_T_f32;
    VAR(float32, AUTOMATIC) ElpsdTi_Sec_T_f32;
    VAR(float32, AUTOMATIC) SysTqFild_HwNm_T_f32;
    VAR(float32, AUTOMATIC) HwAgFild_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HandwheelVelocityFild_HwRadpS_T_f32;
    VAR(float32, AUTOMATIC) SysTq_HwNm_T_f32;
    VAR(float32, AUTOMATIC) YawA_VehDegpSSq_T_f32;
    VAR(float32, AUTOMATIC) YawRatePrev_VehDegpS_T_f32;
    VAR(float32, AUTOMATIC) YawRateCorrd_DegpS_T_f32;
    VAR(float32, AUTOMATIC) YawRateFild_DegpS_T_f32;
    VAR(float32, AUTOMATIC) TorqueCmdCRF_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
    VAR(float32, AUTOMATIC) VehicleYawRate_DegpS_T_f32;


    VAR(boolean, AUTOMATIC) HwAgLrngLrngCdnVld_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) YawLrngLrngCdnVld_Cnt_T_lgc;

    VAR(boolean, AUTOMATIC) HwAgLrngRst_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) EnablePOC_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) EnableYOC_Cnt_T_lgc;


    /************Read inputs*****************/

    HandwheelPosition_HwDeg_T_f32   = Rte_IRead_SnsrOffsLrng_Per2_HandwheelPosition_HwDeg_f32(); /* REQ: SF051A #71 I */
    HandwheelVelocity_HwRadpS_T_f32   = Rte_IRead_SnsrOffsLrng_Per2_HandwheelVelocity_HwRadpS_f32(); /* REQ: SF051A #76 I */
    HwTorque_HwNm_T_f32 = Rte_IRead_SnsrOffsLrng_Per2_HwTorque_HwNm_f32(); /* REQ: SF051A #12 I */
    TorqueCmdCRF_MtrNm_T_f32=Rte_IRead_SnsrOffsLrng_Per2_TorqueCmdCRF_MtrNm_f32(); /* REQ: SF051A #78 I */
    VehicleSpeed_Kph_T_f32 = Rte_IRead_SnsrOffsLrng_Per2_VehicleSpeed_Kph_f32(); /* REQ: SF051A #73 I */
    VehicleYawRate_DegpS_T_f32= Rte_IRead_SnsrOffsLrng_Per2_VehicleYawRate_DegpS_f32(); /* REQ: SF051A #74 I */

    if(k_SOaC_FctEna_Cnt_lgc == TRUE) /* REQ: SF051A #26 I */
    {
        SOaCHierarchyManager(&EnableYOC_Cnt_T_lgc, &EnablePOC_Cnt_T_lgc, &HwAgLrngRst_Cnt_T_lgc);

        /*****************Condition Signals***************/
        /* REQ: SF051A #28 I */
        (void)LPF_OpUpdate_f32_m(VehicleYawRate_DegpS_T_f32, &SOaC_YawCdngFil1_Uls_M_str);
        YawRateFild_DegpS_T_f32 = LPF_OpUpdate_f32_m(SOaC_YawCdngFil1_Uls_M_str.SV_Uls_f32, &SOaC_YawCdngFil2_Uls_M_str);/* ENDREQ: SF051A #28 */
        SOaC_YawRateFild_VehDegpS_D_f32 =  YawRateFild_DegpS_T_f32;

        YawRateCorrd_DegpS_T_f32 =  YawRateFild_DegpS_T_f32 - FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->YawRateOffs,s6p9_T); /* REQ: SF051A #29 I */
        SOaC_YawRateFildCorrd_VehDegpS_D_f32 =  YawRateCorrd_DegpS_T_f32;

        YawRatePrev_VehDegpS_T_f32 =LPF_OpUpdate_f32_m(YawRateFild_DegpS_T_f32, &SOaC_YawACdngFil_Uls_M_str);
        YawA_VehDegpSSq_T_f32 = (YawRatePrev_VehDegpS_T_f32-SOaC_YawRatePrev_VehDegpS_M_f32) * D_IVS10MS_ULSPS_F32; /* REQ: SF051A #89 I */
        SOaC_YawA_VehDegpSSq_D_f32 =  YawA_VehDegpSSq_T_f32;
        SOaC_YawRatePrev_VehDegpS_M_f32 =  YawRatePrev_VehDegpS_T_f32;

        SysTq_HwNm_T_f32 =(HwTorque_HwNm_T_f32 -FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->HwTqOffs,s3p12_T))  + (TorqueCmdCRF_MtrNm_T_f32 * k_Cmn_SysTrqRatio_HwNmpMtrNm_f32); /* REQ: SF051A #87 I */ /* REQ: SF051A #88 I */
        SysTqFild_HwNm_T_f32 =LPF_OpUpdate_f32_m(SysTq_HwNm_T_f32, &SOaC_SysTqCdngFil_Uls_M_str); /* REQ: SF051A #28 I */
        SOaC_SysTqFild_HwNm_D_f32 =  SysTqFild_HwNm_T_f32;

        HwAgFild_HwDeg_T_f32 =LPF_OpUpdate_f32_m(HandwheelPosition_HwDeg_T_f32, &SOaC_HwAgCdngFil_Uls_M_str); /* REQ: SF051A #28 I */
        SOaC_HwAgFild_HwDeg_D_f32 =  HwAgFild_HwDeg_T_f32;

        HandwheelVelocityFild_HwRadpS_T_f32 =LPF_OpUpdate_f32_m(HandwheelVelocity_HwRadpS_T_f32, &SOaC_HwVelCdngFil_Uls_M_str); /* REQ: SF051A #28 I */
        SOaC_HwVelFild_HwRadpS_D_f32 =  HandwheelVelocityFild_HwRadpS_T_f32;

        /*********YOC**********/
        /* REQ: SF051A #31 I */ /* REQ: SF051A #98 I */

        ElpsdTi_Sec_T_f32 = (Rte_Pim_SnsrLrndOffs()->YawRateElpdTi) * D_TIMINTOSEC_SEC_F32;
        ElpsdTi_Sec_T_f32 =  ElpsdTi_Sec_T_f32 + D_TISTEP10MS_SEC_F32;
        if(ElpsdTi_Sec_T_f32 > (k_SOaC_YawOffsFrshTiThd_Min_f32 * D_TIMINTOSEC_SEC_F32)) /* REQ: SF051A #111 I */ /* REQ: SF051A #242 I */
        {
            SOaC_VehYawRateOffsFrsh_Cnt_M_lgc = FALSE;
            Rte_Pim_SnsrLrndOffs()->YawRateElpdTi = k_SOaC_YawOffsFrshTiThd_Min_f32;
        }
        else
        {
            SOaC_VehYawRateOffsFrsh_Cnt_M_lgc = TRUE; /* REQ: SF051A #112 I */
            Rte_Pim_SnsrLrndOffs()->YawRateElpdTi =   ElpsdTi_Sec_T_f32 /  D_TIMINTOSEC_SEC_F32 ;
            
        }

        /*Conditions*/
        /* REQ: SF051A #97 I */
        /* REQ: SF051A #96 I */
        if((VehicleSpeed_Kph_T_f32 <= D_FLTEPSILON_ULS_F32) && (Abs_f32_m(HandwheelPosition_HwDeg_T_f32)<=k_SOaC_YawLrngHwAgThd_HwDeg_f32) && (Abs_f32_m(YawRateFild_DegpS_T_f32) <=(D_YAWRATENOISE_VEHDEGPS_F32+k_SOaC_YawRateOffsLim_VehDegpS_f32))&& (Abs_f32_m(YawA_VehDegpSSq_T_f32) <=(k_SOaC_YawLrngYawAThd_VehDegpSSq_f32))) /* PRQA S 3415 */ /* REQ: SF051A #99 I */ /* REQ: SF051A #100 I */ /* REQ: SF051A #101 I */ /* REQ: SF051A #102 I */
        {
             YawLrngLrngCdnVld_Cnt_T_lgc = TRUE;
        }
        else
        {
             YawLrngLrngCdnVld_Cnt_T_lgc = FALSE;
        }
        SOaC_YawLrngLrngCdnVld_Cnt_D_lgc = YawLrngLrngCdnVld_Cnt_T_lgc;
        /* ENDREQ: SF051A #96 */
        /* ENDREQ: SF051A #97 */
        if((YawLrngLrngCdnVld_Cnt_T_lgc == TRUE) &&(EnableYOC_Cnt_T_lgc == TRUE)) /* REQ: SF051A #95 I */
        {
          /* REQ: SF051A #94 I */
          YawLrngElpdLrngTi_Sec_T_f32 = SOaC_YawLrngElpdLrngTi_Sec_M_f32 + D_TISTEP10MS_SEC_F32; /* REQ: SF051A #90 I */
          SOaC_YawLrngElpdLrngTi_Sec_M_f32 = Min_m(YawLrngElpdLrngTi_Sec_T_f32, k_SOaC_YawLrngLrngTi_Sec_f32 ); /* REQ: SF051A #91 I */ /* REQ: SF051A #240 I */
          
          /* REQ: SF051A #91 I */
          (void)LPF_OpUpdate_f32_m(YawRateFild_DegpS_T_f32, &SOaC_YawLrngFil1_Uls_M_str);
          YawLrngBiasEstimnRaw_VehDegpS_T_f32 = LPF_OpUpdate_f32_m(SOaC_YawLrngFil1_Uls_M_str.SV_Uls_f32, &SOaC_YawLrngFil2_Uls_M_str);
          SOaC_YawLrngBiasEstimnRaw_VehDegpS_D_f32 =  YawLrngBiasEstimnRaw_VehDegpS_T_f32; /* ENDREQ: SF051A #91 */
          
          if ((Rte_Pim_SnsrLrndOffs()->YawRateOffsVld == TRUE) || (YawLrngElpdLrngTi_Sec_T_f32 > k_SOaC_YawLrngLrngTi_Sec_f32)) /* REQ: SF051A #107 I */ /* REQ: SF051A #93 I */
          {
              YawLrngBiasEstimnRaw_VehDegpS_T_f32 = Limit_m(YawLrngBiasEstimnRaw_VehDegpS_T_f32, -k_SOaC_YawRateOffsLim_VehDegpS_f32, k_SOaC_YawRateOffsLim_VehDegpS_f32); /* REQ: SF051A #106 I */
              /* REQ: SF051A #91 I */
              /* REQ: SF051A #240 I */
              Rte_Pim_SnsrLrndOffs()->YawRateOffs = FPM_FloatToFixed_m(YawLrngBiasEstimnRaw_VehDegpS_T_f32,s6p9_T); /* PRQA S 4395 */
              Rte_Pim_SnsrLrndOffs()->YawRateOffsVld = TRUE; /* REQ: SF051A #104 I */ /* REQ: SF051A #105 I */
              Rte_Pim_SnsrLrndOffs()->YawRateElpdTi = D_ZERO_ULS_F32;
              /* ENDREQ: SF051A #240 */
              /* ENDREQ: SF051A #91 */
          }
          /* ENDREQ: SF051A #94 */
        } /* ENDREQ: SF051A #31 */ /* ENDREQ: SF051A #98 */

        /***************POC*************/
        /* REQ: SF051A #60 I */
        if(HwAgLrngRst_Cnt_T_lgc== TRUE)
        {
          SOaC_HwAgLrngFil1_Uls_M_str.SV_Uls_f32 = FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->HwAgOffs,s5p10_T);
          SOaC_HwAgLrngFil2_Uls_M_str.SV_Uls_f32 = SOaC_HwAgLrngFil1_Uls_M_str.SV_Uls_f32;
          Rte_Pim_SnsrLrndOffs()->HwAgLrndTi = D_ZERO_ULS_F32;
          Rte_Pim_SnsrLrndOffs()->HwAgLrngYawOffsRef=Rte_Pim_SnsrLrndOffs()->YawRateOffs;
        }
         /*Learning Conditions*/
         /* REQ: SF051A #126 I */
         /* REQ: SF051A #125 I */
        if((VehicleSpeed_Kph_T_f32 >= k_SOaC_HwAgLrngVehSpdThd_Kph_f32) && (Abs_f32_m(HandwheelVelocityFild_HwRadpS_T_f32) <=k_SOaC_HwAgLrngHwVelThd_HwRadpS_f32) && (Abs_f32_m(YawRateCorrd_DegpS_T_f32) <=(k_SOaC_HwAgLrngYawRateThd_VehDegpS_f32))&& (Abs_f32_m(SysTqFild_HwNm_T_f32) <=(k_SOaC_HwAgLrngSysTqThd_HwNm_f32))) /* PRQA S 3415 */ /* REQ: SF051A #133 I */ /* REQ: SF051A #129 I */ /* REQ: SF051A #131 I */ /* REQ: SF051A #130 I */
        {
           SOaC_HwAgLrngDrvgDst_Metr_M_f32 =  Limit_m(((VehicleSpeed_Kph_T_f32* D_SPDCNVN_MPSECPKPH_F32* D_TISTEP10MS_SEC_F32)  +  SOaC_HwAgLrngDrvgDst_Metr_M_f32),D_ZERO_ULS_F32, k_SOaC_HwAgLrngDrvgDstThd_Metr_f32);

        }
        else
        {

           SOaC_HwAgLrngDrvgDst_Metr_M_f32 = D_ZERO_ULS_F32;
        }
        if(SOaC_HwAgLrngDrvgDst_Metr_M_f32 >= k_SOaC_HwAgLrngDrvgDstThd_Metr_f32)
        {
           HwAgLrngLrngCdnVld_Cnt_T_lgc = TRUE;
        }
        else
        {
           HwAgLrngLrngCdnVld_Cnt_T_lgc = FALSE;
        }
        /* ENDREQ: SF051A #125 */
        /* ENDREQ: SF051A #126 */
        SOaC_HwAgLrngLrngCdnVld_Cnt_D_lgc = HwAgLrngLrngCdnVld_Cnt_T_lgc;
        LearnHwAg(HwAgLrngLrngCdnVld_Cnt_T_lgc, EnablePOC_Cnt_T_lgc, SysTqFild_HwNm_T_f32,HwAgFild_HwDeg_T_f32); /* REQ: SF051A #127 I */
        /* ENDREQ: SF051A #28 */
   }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsLrng_ReadHwAgOffs
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadHwAgOffs> of PortPrototype <SnsrOffsLrng>
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
 *   void SnsrOffsLrng_ReadHwAgOffs(Float *HwAgOffs_HwDeg_f32, Boolean *HwAgLrngStRst_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_ReadHwAgOffs(P2VAR(Float, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) HwAgOffs_HwDeg_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) HwAgLrngStRst_Cnt_lgc) /* REQ: SF051A #214 I */ /* REQ: SF051A #231 I */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsLrng_ReadHwAgOffs
 *********************************************************************************************************************/
  *HwAgOffs_HwDeg_f32 = FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->HwAgOffs,s5p10_T);
  *HwAgLrngStRst_Cnt_lgc = SOaC_HwAgLrngStRst_Cnt_M_lgc;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsLrng_ReadHwTqOffs
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadHwTqOffs> of PortPrototype <SnsrOffsLrng>
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
 *   void SnsrOffsLrng_ReadHwTqOffs(Float *HwTqOffs_HwNm_f32, Boolean *HwTqLrngStRst_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_ReadHwTqOffs(P2VAR(Float, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) HwTqOffs_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) HwTqLrngStRst_Cnt_lgc) /* REQ: SF051A #212 I */ /* REQ: SF051A #233 I */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsLrng_ReadHwTqOffs 
 *********************************************************************************************************************/
 *HwTqOffs_HwNm_f32= FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->HwTqOffs, s3p12_T);
 *HwTqLrngStRst_Cnt_lgc =SOaC_HwTqLrngStRst_Cnt_M_lgc;    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsLrng_ReadYawRateOffs
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadYawRateOffs> of PortPrototype <SnsrOffsLrng>
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
 *   void SnsrOffsLrng_ReadYawRateOffs(Float *VehYawRateOffs_DegpS_f32, Boolean *VehYawRateLrngStRst_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_ReadYawRateOffs(P2VAR(Float, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) VehYawRateOffs_DegpS_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_SNSROFFSLRNG_APPL_VAR) VehYawRateLrngStRst_Cnt_lgc) /* REQ: SF051A #217 I */ /* REQ: SF051A #229 I */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsLrng_ReadYawRateOffs
 *********************************************************************************************************************/
 *VehYawRateOffs_DegpS_f32= FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->YawRateOffs, s6p9_T);
 *VehYawRateLrngStRst_Cnt_lgc = SOaC_VehYawRateLrngStRst_Cnt_M_lgc;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsLrng_RstHwTq
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RstHwTq> of PortPrototype <SnsrOffsLrng>
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SnsrOffsLrng_RstHwTq(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_RstHwTq(void) /* REQ: SF051A #216 I */ /* REQ: SF051A #235 I */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsLrng_RstHwTq
 *********************************************************************************************************************/
  Rte_Pim_SnsrLrndOffs()->HwTqOffs = D_ZERO_CNT_S16;
  Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntNeg = D_ZERO_CNT_U16;
  Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntPos=D_ZERO_CNT_U16;
  Rte_Pim_SnsrLrndOffs()->HwTqLrngSts=D_ZERO_CNT_U8;
  Rte_Pim_SnsrLrndOffs()->HwTqLrngHwAgRef =FPM_FloatToFixed_m(D_HWAGHILIM_HWDEG_F32,s11p4_T);
 (Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect)[0]= D_ZERO_ULS_F32;
 (Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect)[1]= D_ZERO_ULS_F32;
 (Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect)[2]= D_ZERO_ULS_F32;
 (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[0][0]= D_COVMATINIT_ULS_F32;
 (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[0][1]= D_ZERO_ULS_F32;
 (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[0][2]= D_ZERO_ULS_F32;
 (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[1][0]= D_ZERO_ULS_F32;
 (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[1][1]= D_COVMATINIT_ULS_F32;
 (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[1][2]= D_ZERO_ULS_F32;
 (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[2][0]= D_ZERO_ULS_F32;
 (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[2][1]= D_ZERO_ULS_F32;
 (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[2][2]= D_COVMATINIT_ULS_F32;

  
  SOaC_HwTqLrngHwAgMeasFil1_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
  SOaC_HwTqLrngHwAgMeasFil2_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
  SOaC_HwTqLrngHwTqMeasFil1_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
  SOaC_HwTqLrngHwTqMeasFil2_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
  SOaC_TqInpDetnHwTqFil_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
  
  (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SOaC_HwTqLrngEnaTmrRef_mS_M_u32);
  (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SOaC_HwTqLrngMeasTmrRef_mS_M_u32);
  SOaC_HwTqLrngTqInpDetnEnaPrev_Cnt_M_lgc = FALSE;
  SOaC_HwTqLrngTqInpPrsnt_Cnt_M_lgc = TRUE;
  SOaC_SetRamBlkSts_Cnt_M_lgc = TRUE;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsLrng_RstYawAndAg
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RstYawAndAg> of PortPrototype <SnsrOffsLrng>
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
 *   void SnsrOffsLrng_RstYawAndAg(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_RstYawAndAg(void) /* REQ: SF051A #211 I */ /* REQ: SF051A #234 I */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsLrng_RstYawAndAg
 *********************************************************************************************************************/
    Rte_Pim_SnsrLrndOffs()->YawRateOffs         = D_ZERO_CNT_S16;
    Rte_Pim_SnsrLrndOffs()->YawRateOffsVld      = FALSE;
    Rte_Pim_SnsrLrndOffs()->YawRateElpdTi       = D_YAWELPSDTIHILIM_MIN_F32;
    Rte_Pim_SnsrLrndOffs()->HwAgOffs            = D_ZERO_CNT_S16;
    Rte_Pim_SnsrLrndOffs()->HwAgLrndTi          = D_ZERO_ULS_F32;
    Rte_Pim_SnsrLrndOffs()->HwAgLrngHwAgFilSt   = D_ZERO_CNT_S16;
    Rte_Pim_SnsrLrndOffs()->HwAgLrngSysTqFilSt  = D_ZERO_CNT_S16;
    Rte_Pim_SnsrLrndOffs()->HwAgLrngYawOffsRef  = D_ZERO_CNT_S16;
    
    SOaC_YawLrngFil1_Uls_M_str.SV_Uls_f32       = D_ZERO_ULS_F32;
    SOaC_YawLrngFil2_Uls_M_str.SV_Uls_f32       = D_ZERO_ULS_F32;
    SOaC_YawLrngElpdLrngTi_Sec_M_f32            = D_ZERO_ULS_F32;
    
    SOaC_HwAgLrngFil1_Uls_M_str.SV_Uls_f32      = D_ZERO_ULS_F32;
    SOaC_HwAgLrngFil2_Uls_M_str.SV_Uls_f32      = D_ZERO_ULS_F32;
    SOaC_HwAgLrngSysTqFil1_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
    SOaC_HwAgLrngSysTqFil2_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
    SOaC_SetRamBlkSts_Cnt_M_lgc                 = TRUE;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsLrng_SetHwAgOffs
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHwAgOffs> of PortPrototype <SnsrOffsLrng>
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
 *   void SnsrOffsLrng_SetHwAgOffs(Float HwAgOffs_HwDeg_f32, Boolean HwAgLrngStRst_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_SetHwAgOffs(Float HwAgOffs_HwDeg_f32, Boolean HwAgLrngStRst_Cnt_lgc) /* REQ: SF051A #215 I */ /* REQ: SF051A #236 I */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsLrng_SetHwAgOffs
 *********************************************************************************************************************/
 HwAgOffs_HwDeg_f32 = Limit_m(HwAgOffs_HwDeg_f32,-k_SOaC_HwAgOffsLim_HwDeg_f32, k_SOaC_HwAgOffsLim_HwDeg_f32); /* REQ: SF051A #230 I */
 Rte_Pim_SnsrLrndOffs()->HwAgOffs =FPM_FloatToFixed_m(HwAgOffs_HwDeg_f32,s5p10_T); /* PRQA S 4395 */
 
 if(HwAgLrngStRst_Cnt_lgc == TRUE)
 { 
     SOaC_HwAgLrngFil1_Uls_M_str.SV_Uls_f32      = HwAgOffs_HwDeg_f32;
     SOaC_HwAgLrngFil2_Uls_M_str.SV_Uls_f32      = HwAgOffs_HwDeg_f32;
     SOaC_HwAgLrngSysTqFil1_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
     SOaC_HwAgLrngSysTqFil2_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
     Rte_Pim_SnsrLrndOffs()->HwAgLrndTi          = D_ZERO_ULS_F32;
     Rte_Pim_SnsrLrndOffs()->HwAgLrngHwAgFilSt   = D_ZERO_CNT_S16;
     Rte_Pim_SnsrLrndOffs()->HwAgLrngSysTqFilSt  = D_ZERO_CNT_S16;
     Rte_Pim_SnsrLrndOffs()->HwAgLrngYawOffsRef  = Rte_Pim_SnsrLrndOffs()->YawRateOffs;
 }
 SOaC_HwAgLrngStRst_Cnt_M_lgc = HwAgLrngStRst_Cnt_lgc; 
 SOaC_SetRamBlkSts_Cnt_M_lgc  = TRUE;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsLrng_SetHwTqOffs
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHwTqOffs> of PortPrototype <SnsrOffsLrng>
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SnsrOffsLrng_SetHwTqOffs(Float HwTqOffs_HwNm_f32, Boolean HwTqLrngStRst_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_SetHwTqOffs(Float HwTqOffs_HwNm_f32, Boolean HwTqLrngStRst_Cnt_lgc) /* REQ: SF051A #213 I */ /* REQ: SF051A #238 I */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsLrng_SetHwTqOffs
 *********************************************************************************************************************/
  HwTqOffs_HwNm_f32 = Limit_m(HwTqOffs_HwNm_f32, -k_SOaC_HwTqOffsLim_HwNm_f32, k_SOaC_HwTqOffsLim_HwNm_f32); /* REQ: SF051A #232 I */
  Rte_Pim_SnsrLrndOffs()->HwTqOffs = FPM_FloatToFixed_m(HwTqOffs_HwNm_f32,s3p12_T); /* PRQA S 4395 */
  if(HwTqLrngStRst_Cnt_lgc == TRUE)
  {
      
       Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntNeg      = D_ZERO_CNT_U16;
       Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntPos      = D_ZERO_CNT_U16;
       Rte_Pim_SnsrLrndOffs()->HwTqLrngSts               = D_ZERO_CNT_U8;
       Rte_Pim_SnsrLrndOffs()->HwTqLrngHwAgRef           = FPM_FloatToFixed_m(D_HWAGHILIM_HWDEG_F32,s11p4_T);
      (Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect)[0]    = D_ZERO_ULS_F32;
      (Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect)[1]    = D_ZERO_ULS_F32;
      (Rte_Pim_SnsrLrndOffs()->HwTqLrngEstimnVect)[2]    = D_ZERO_ULS_F32;
      (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[0][0] = D_COVMATINIT_ULS_F32;
      (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[0][1] = D_ZERO_ULS_F32;
      (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[0][2] = D_ZERO_ULS_F32;
      (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[1][0] = D_ZERO_ULS_F32;
      (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[1][1] = D_COVMATINIT_ULS_F32;
      (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[1][2] = D_ZERO_ULS_F32;
      (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[2][0] = D_ZERO_ULS_F32;
      (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[2][1] = D_ZERO_ULS_F32;
      (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx)[2][2] = D_COVMATINIT_ULS_F32;

      SOaC_HwTqLrngHwAgMeasFil1_Uls_M_str.SV_Uls_f32     = D_ZERO_ULS_F32;
      SOaC_HwTqLrngHwAgMeasFil2_Uls_M_str.SV_Uls_f32     = D_ZERO_ULS_F32;
      SOaC_HwTqLrngHwTqMeasFil1_Uls_M_str.SV_Uls_f32     = D_ZERO_ULS_F32;
      SOaC_HwTqLrngHwTqMeasFil2_Uls_M_str.SV_Uls_f32     = D_ZERO_ULS_F32;
      SOaC_TqInpDetnHwTqFil_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
      
      (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SOaC_HwTqLrngEnaTmrRef_mS_M_u32);
      (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SOaC_HwTqLrngMeasTmrRef_mS_M_u32);
      SOaC_HwTqLrngTqInpDetnEnaPrev_Cnt_M_lgc = FALSE;
      SOaC_HwTqLrngTqInpPrsnt_Cnt_M_lgc = TRUE;
  }
  SOaC_HwTqLrngStRst_Cnt_M_lgc = HwTqLrngStRst_Cnt_lgc;
  SOaC_SetRamBlkSts_Cnt_M_lgc  = TRUE;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsLrng_SetYawRateOffs
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetYawRateOffs> of PortPrototype <SnsrOffsLrng>
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
 *   void SnsrOffsLrng_SetYawRateOffs(Float VehYawRateOffs_DegpS_f32, Boolean VehYawRateLrngStRst_Cnt_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_SetYawRateOffs(Float VehYawRateOffs_DegpS_f32, Boolean VehYawRateLrngStRst_Cnt_lgc) /* REQ: SF051A #58  I */ /* REQ: SF051A #237 I */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsLrng_SetYawRateOffs
 *********************************************************************************************************************/

 VehYawRateOffs_DegpS_f32 =Limit_m(VehYawRateOffs_DegpS_f32, -k_SOaC_YawRateOffsLim_VehDegpS_f32, k_SOaC_YawRateOffsLim_VehDegpS_f32); /* REQ: SF051A #218 I */
 Rte_Pim_SnsrLrndOffs()->YawRateOffs = FPM_FloatToFixed_m(VehYawRateOffs_DegpS_f32, s6p9_T); /* PRQA S 4395 */
 if(VehYawRateLrngStRst_Cnt_lgc == TRUE)
 {
     SOaC_YawLrngFil1_Uls_M_str.SV_Uls_f32 = VehYawRateOffs_DegpS_f32;
     SOaC_YawLrngFil2_Uls_M_str.SV_Uls_f32 = VehYawRateOffs_DegpS_f32;
     SOaC_YawLrngElpdLrngTi_Sec_M_f32      = D_ZERO_ULS_F32;
     Rte_Pim_SnsrLrndOffs()->YawRateElpdTi = D_ZERO_ULS_F32;     
 }
 SOaC_VehYawRateLrngStRst_Cnt_M_lgc = VehYawRateLrngStRst_Cnt_lgc;
 SOaC_SetRamBlkSts_Cnt_M_lgc = TRUE;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrOffsLrng_Trans1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SnsrLrndOffsBlk_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SNSROFFSLRNG_APPL_CODE) SnsrOffsLrng_Trans1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrOffsLrng_Trans1
 *********************************************************************************************************************/
 if (SOaC_SetRamBlkSts_Cnt_M_lgc == TRUE)
 {
     (void)Rte_Call_SnsrLrndOffsBlk_SetRamBlockStatus(TRUE);
 }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SNSROFFSLRNG_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
  * Name:        LearnHwAg
  * Description: 
  * Inputs:     HwAgLrngLrngCdnVld_Cnt_T_lgc
  *             EnablePOC_Cnt_T_lgc
  *              SysTqFild_HwNm_T_f32
  * Outputs:    None 
  *              
*****************************************************************************/

STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE) LearnHwAg(VAR(boolean, AUTOMATIC)  HwAgLrngLrngCdnVld_Cnt_T_lgc, VAR(boolean, AUTOMATIC)  EnablePOC_Cnt_T_lgc, VAR(float32, AUTOMATIC) SysTqFild_HwNm_T_f32, VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32 )
{
    /* REQ: SF051A #127 I */
      VAR(float32, AUTOMATIC) ElpsdTi_mS_T_f32;
      VAR(float32, AUTOMATIC) SysTqAvrg_HwNm_T_f32;
      VAR(float32, AUTOMATIC) HwPosBiasEstRaw_HwDeg_T_f32;

      VAR(float32, AUTOMATIC) HwAgLrngSysTqUpThd_HwNm_T_f32;
      VAR(float32, AUTOMATIC) HwAgLrngSysTqLoThd_HwNm_T_f32;
      VAR(uint8  , AUTOMATIC) HwTqLrngSts_Cnt_T_u08;
      VAR(boolean, AUTOMATIC) HwAgLrngTiVldt_Cnt_T_lgc;
      VAR(boolean, AUTOMATIC) HwAgLrngSysTqVldt_Cnt_T_lgc;


       HwTqLrngSts_Cnt_T_u08 = SOac_HwTqLrngSts_Cnt_M_u08; /* REQ: SF051A #128 I */

       /***********Learn**************/
       if((HwAgLrngLrngCdnVld_Cnt_T_lgc == TRUE) &&(EnablePOC_Cnt_T_lgc == TRUE)) /* REQ: SF051A #124 I */
       {
        /**********LPF*************/
        /* REQ: SF051A #123 I */
         (void)LPF_OpUpdate_f32_m(HandwheelPosition_HwDeg_T_f32,&SOaC_HwAgLrngFil1_Uls_M_str); /* REQ: SF051A #132 I */
         HwPosBiasEstRaw_HwDeg_T_f32 = LPF_OpUpdate_f32_m(SOaC_HwAgLrngFil1_Uls_M_str.SV_Uls_f32,&SOaC_HwAgLrngFil2_Uls_M_str);
         Rte_Pim_SnsrLrndOffs()->HwAgLrngHwAgFilSt =  FPM_FloatToFixed_m(HwPosBiasEstRaw_HwDeg_T_f32,s11p4_T); /* PRQA S 4395 */ /* REQ: SF051A #119 I */
         
         (void)LPF_OpUpdate_f32_m(SysTqFild_HwNm_T_f32,&SOaC_HwAgLrngSysTqFil1_Uls_M_str); /* REQ: SF051A #116 I */
         SysTqAvrg_HwNm_T_f32 = LPF_OpUpdate_f32_m(SOaC_HwAgLrngSysTqFil1_Uls_M_str.SV_Uls_f32,&SOaC_HwAgLrngSysTqFil2_Uls_M_str); /* REQ: SF051A #116 I */
         Rte_Pim_SnsrLrndOffs()->HwAgLrngSysTqFilSt =  FPM_FloatToFixed_m(SysTqAvrg_HwNm_T_f32,s10p5_T); /* PRQA S 4395 */ /* REQ: SF051A #119 I */
        
         ElpsdTi_mS_T_f32 = Rte_Pim_SnsrLrndOffs()->HwAgLrndTi +  D_TISTEP10MS_SEC_F32;
         /* ENDREQ: SF051A #123 */
         /********BiasEstimation_ValidityCheck**************/
         /*******Time_Check************/
         /* REQ: SF051A #118 I */
         /* REQ: SF051A #119 I */
         /* REQ: SF051A #120 I */
         if(ElpsdTi_mS_T_f32>=k_SOaC_HwAgLrngLrngTi_Sec_f32) /* REQ: SF051A #117 I */ /* REQ: SF051A #122 I */
         {
             Rte_Pim_SnsrLrndOffs()->HwAgLrndTi = k_SOaC_HwAgLrngLrngTi_Sec_f32;
             HwAgLrngTiVldt_Cnt_T_lgc = TRUE;
         }
         else
         {
             Rte_Pim_SnsrLrndOffs()->HwAgLrndTi = ElpsdTi_mS_T_f32;
             HwAgLrngTiVldt_Cnt_T_lgc = FALSE;
         }
         SOaC_HwAgLrngTiVldt_Cnt_D_lgc = HwAgLrngTiVldt_Cnt_T_lgc;
         /* ENDREQ: SF051A #118 */
         /* ENDREQ: SF051A #119 */
         /* ENDREQ: SF051A #120 */
         
        /********HwTqAvrg_Check*****************/
        /* REQ: SF051A #115 I */

          switch(HwTqLrngSts_Cnt_T_u08)
          {

             case D_HWTQLRNGSTSPOSOFFS_CNT_U08:
                /* REQ: SF051A #145 I */
                HwAgLrngSysTqUpThd_HwNm_T_f32    = k_SOaC_HwAgLrngSysTqThdWide_HwNm_f32;
                HwAgLrngSysTqLoThd_HwNm_T_f32    = D_ZERO_ULS_F32;
                break;
             case D_HWTQLRNGSTSNEGOFFS_CNT_U08:
                /* REQ: SF051A #144 I */
                HwAgLrngSysTqUpThd_HwNm_T_f32    = D_ZERO_ULS_F32;
                HwAgLrngSysTqLoThd_HwNm_T_f32    = -k_SOaC_HwAgLrngSysTqThdWide_HwNm_f32;
                break;
             case D_HWTQLRNGSTSZEROOFFS_CNT_U08:
                /* REQ: SF051A #143 I */
                HwAgLrngSysTqUpThd_HwNm_T_f32    = k_SOaC_HwAgLrngSysTqThdMed_HwNm_f32;
                HwAgLrngSysTqLoThd_HwNm_T_f32    = -k_SOaC_HwAgLrngSysTqThdMed_HwNm_f32;
                break;
             case D_HWTQLRNGSTSLRND_CNT_U08:
                /* REQ: SF051A #142 I */
                HwAgLrngSysTqUpThd_HwNm_T_f32    = k_SOaC_HwAgLrngSysTqThdTrustd_HwNm_f32;
                HwAgLrngSysTqLoThd_HwNm_T_f32    = -k_SOaC_HwAgLrngSysTqThdTrustd_HwNm_f32;
                break;
             default:
             /*case D_HWTQLRNGSTSNOTLRND_CNT_U08:*/
                /* REQ: SF051A #146 I */
                HwAgLrngSysTqUpThd_HwNm_T_f32    = k_SOaC_HwAgLrngSysTqThdWide_HwNm_f32;
                HwAgLrngSysTqLoThd_HwNm_T_f32    = -k_SOaC_HwAgLrngSysTqThdWide_HwNm_f32;
                break;
          }
          SOaC_HwAgLrngSysTqUpThd_HwNm_D_f32 = HwAgLrngSysTqUpThd_HwNm_T_f32;
          SOaC_HwAgLrngSysTqLoThd_HwNm_D_f32 = HwAgLrngSysTqLoThd_HwNm_T_f32;
          if((SysTqAvrg_HwNm_T_f32 <= HwAgLrngSysTqUpThd_HwNm_T_f32 ) &&(SysTqAvrg_HwNm_T_f32>= HwAgLrngSysTqLoThd_HwNm_T_f32 ))
          {
              HwAgLrngSysTqVldt_Cnt_T_lgc = TRUE;
          }
          else
          {
              HwAgLrngSysTqVldt_Cnt_T_lgc = FALSE;
          }
          SOaC_HwAgLrngSysTqVldt_Cnt_D_lgc = HwAgLrngSysTqVldt_Cnt_T_lgc;
          /* ENDREQ: SF051A #115 */
          
          
          
          if(HwAgLrngTiVldt_Cnt_T_lgc == TRUE)
          {
              if(HwAgLrngSysTqVldt_Cnt_T_lgc == TRUE)
              {
                /****** Limit and Keep Learned Value*************/
                /* REQ: SF051A #141 I */ /* REQ: SF051A #120 I */ /* REQ: SF051A #119 I */
                Rte_Pim_SnsrLrndOffs()->HwAgOffs = FPM_FloatToFixed_m(Limit_m(HwPosBiasEstRaw_HwDeg_T_f32, -k_SOaC_HwAgOffsLim_HwDeg_f32,k_SOaC_HwAgOffsLim_HwDeg_f32),s5p10_T); /* PRQA S 4395 */ /* REQ: SF051A #140 I */
                Rte_Pim_SnsrLrndOffs()->HwAgLrndTi = D_ZERO_ULS_F32; /* REQ: SF051A #138 I */  
              }
              else
              {
                  /* REQ: SF051A #139 I */
                  SOaC_HwAgLrngFil1_Uls_M_str.SV_Uls_f32      = FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->HwAgOffs, s5p10_T);
                  SOaC_HwAgLrngFil2_Uls_M_str.SV_Uls_f32      = SOaC_HwAgLrngFil1_Uls_M_str.SV_Uls_f32;
                  Rte_Pim_SnsrLrndOffs()->HwAgLrngHwAgFilSt   = FPM_FloatToFixed_m(SOaC_HwAgLrngFil1_Uls_M_str.SV_Uls_f32, s11p4_T); /* PRQA S 4395 */
                  SOaC_HwAgLrngSysTqFil1_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
                  SOaC_HwAgLrngSysTqFil2_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;
                  Rte_Pim_SnsrLrndOffs()->HwAgLrngSysTqFilSt  = D_ZERO_CNT_S16;
                  Rte_Pim_SnsrLrndOffs()->HwAgLrndTi          = D_ZERO_ULS_F32;
                  Rte_Pim_SnsrLrndOffs()->HwAgLrngYawOffsRef  = Rte_Pim_SnsrLrndOffs()->YawRateOffs;
                  /* ENDREQ: SF051A #139 */
              }             
          }
     }
     /* ENDREQ: SF051A #127 */
}

/*****************************************************************************
  * Name:        SOaCHierarchyManager
  * Description: 
  * Inputs:     None  
  * Outputs:    EnableYOC_Cnt_T_lgc
  *                EnablePOC_Cnt_T_lgc
  *             HwAgLrngRst_Cnt_T_lgc 
  *              
*****************************************************************************/
STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)SOaCHierarchyManager(P2VAR(boolean, AUTOMATIC, AUTOMATIC) EnableYOC_Cnt_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC) EnablePOC_Cnt_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC) HwAgLrngRst_Cnt_T_lgc)
{    /* REQ: SF051A #86 I */
     VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32;

     VAR(boolean, AUTOMATIC) CmnSigVld_Cnt_T_lgc;
     VAR(boolean, AUTOMATIC) VehicleYawRateValid_Cnt_T_lgc;
     VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc;

     HandwheelAuthority_Uls_T_f32  = Rte_IRead_SnsrOffsLrng_Per2_HandwheelAuthority_Uls_f32(); /* REQ: SF051A #75 I */
     VehicleSpeedValid_Cnt_T_lgc   = Rte_IRead_SnsrOffsLrng_Per2_VehicleSpeedValid_Cnt_lgc();  /* REQ: SF051A #72 I */
     VehicleYawRateValid_Cnt_T_lgc = Rte_IRead_SnsrOffsLrng_Per2_VehicleYawRateValid_Cnt_lgc(); /* REQ: SF051A #77 I */


     if((HandwheelAuthority_Uls_T_f32 >=  D_HWAUTHYTHD_ULS_F32) && (VehicleSpeedValid_Cnt_T_lgc== TRUE))
     {
         CmnSigVld_Cnt_T_lgc = TRUE;
     }
     else
     {
         CmnSigVld_Cnt_T_lgc = FALSE;
     }

     /*YOCEnabler*/
     if((CmnSigVld_Cnt_T_lgc == TRUE) &&(VehicleYawRateValid_Cnt_T_lgc==TRUE) && (k_SOaC_YawLrngEna_Cnt_lgc== TRUE)) /* REQ: SF051A #32 I */
     {
          *EnableYOC_Cnt_T_lgc = TRUE;

     }
     else
     {
          *EnableYOC_Cnt_T_lgc = FALSE;
     }
     SOaC_YawLrngEna_Cnt_D_lgc = *EnableYOC_Cnt_T_lgc;

     /*POCEnabler*/
     /* REQ: SF051A #136 I */ /* REQ: SF051A #135 I */
     if((CmnSigVld_Cnt_T_lgc == TRUE) &&(VehicleYawRateValid_Cnt_T_lgc==TRUE) && (k_SOaC_HwAgLrngEna_Cnt_lgc== TRUE) && (SOaC_VehYawRateOffsFrsh_Cnt_M_lgc== TRUE)&&(Rte_Pim_SnsrLrndOffs()->YawRateOffsVld == TRUE))
     {
         *EnablePOC_Cnt_T_lgc = TRUE;
     }
     else
     {
         *EnablePOC_Cnt_T_lgc = FALSE;
     }
     SOaC_HwAgLrngEna_Cnt_D_lgc = *EnablePOC_Cnt_T_lgc;
     /****Reset Logic***/
     /* REQ: SF051A #134 I */
     if(Abs_f32_m(FPM_FixedToFloat_m((sint16)(Rte_Pim_SnsrLrndOffs()->YawRateOffs - Rte_Pim_SnsrLrndOffs()->HwAgLrngYawOffsRef),s6p9_T)) >= k_SOaC_HwAgLrngYawOffsDbnd_VehDegpS_f32) 
     {
         *HwAgLrngRst_Cnt_T_lgc = TRUE;
     }
     else
     {
         *HwAgLrngRst_Cnt_T_lgc = FALSE;
     } /* ENDREQ: SF051A #134 */
     SOaC_HwAgLrngRst_Cnt_D_lgc = *HwAgLrngRst_Cnt_T_lgc;
}

/*****************************************************************************
  * Name:        Perform_TqInpDetn
  * Description: 
  * Inputs:     None
  *    
  *              
  * Outputs:     None
  *              
*****************************************************************************/
STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)Perform_TqInpDetn(void)
{
    VAR(uint16, AUTOMATIC) IterCnt_Cnt_T_u16;
     
    if(SOaC_HwTqLrngTqInpDetnEnaPrev_Cnt_M_lgc == FALSE)
    {
        SOaC_TqInpDetnPreProcEnaLoop_Cnt_M_u16 = D_ZERO_CNT_U16;
        SOaC_HwTqLrngTqInpPrsnt_Cnt_M_lgc      = TRUE;
        SOaC_TqInpDetnStg1Idx_Cnt_M_u08        = D_ZERO_CNT_U8;
        for(IterCnt_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt_Cnt_T_u16<TableSize_m(SOaC_TqInpDetnStg1Buf_HwNm_M_f32); IterCnt_Cnt_T_u16++)
        {
            SOaC_TqInpDetnStg1Buf_HwNm_M_f32[IterCnt_Cnt_T_u16] = D_ZERO_ULS_F32;
        }
        SOaC_TqInpDetnEnaTi_Sec_M_f32              = D_ZERO_ULS_F32;
        SOaC_TqInpDetnSinGenrAg_Rad_M_f32          = D_ZERO_ULS_F32;
        SOaC_TqInpDetnStg1FiltSt2_Uls_M_f32        = D_ZERO_ULS_F32;
        SOaC_TqInpDetnStg1FiltSt1_Uls_M_f32        = D_ZERO_ULS_F32;
        SOaC_TqInpDetnStg2DwnFiltSt2_Uls_M_f32     = D_ZERO_ULS_F32;
        SOaC_TqInpDetnStg2DwnFiltSt1_Uls_M_f32     = D_ZERO_ULS_F32;
        SOaC_TqInpDetnStg2CenFiltSt2_Uls_M_f32     = D_ZERO_ULS_F32;
        SOaC_TqInpDetnStg2CenFiltSt1_Uls_M_f32     = D_ZERO_ULS_F32;
        SOaC_TqInpDetnStg2UpFiltSt2_Uls_M_f32      = D_ZERO_ULS_F32;
        SOaC_TqInpDetnStg2UpFiltSt1_Uls_M_f32      = D_ZERO_ULS_F32;
        SOaC_TqInpDetnHwTqPreProc_dB_M_f32         = D_ZERO_ULS_F32;
        SOaC_TqInpDetnHwTqFil_Uls_M_str.SV_Uls_f32 = D_ZERO_ULS_F32;

    }
}

/*****************************************************************************
  * Name:        EnableLearning
  * Description: 
  * Inputs:     None
  *    
  *              
  * Outputs:     HwTqLrngEna_Cnt_T_lgc
  *              
*****************************************************************************/
STATIC INLINE FUNC(boolean, AP_SNSROFFSLRNG_CODE)EnableLearning(void)
{
    /* REQ: SF051A #165 I */
    VAR(float32, AUTOMATIC) HandwheelAuthority_Uls_T_f32;
    VAR(float32, AUTOMATIC) HandwheelPosition_HwDeg_T_f32;
    VAR(float32, AUTOMATIC) HandwheelVelocity_HwRadpS_T_f32;
    VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
    VAR(float32, AUTOMATIC) VehicleSpeed_Kph_T_f32;
    VAR(boolean, AUTOMATIC) VehicleSpeedValid_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) HwTqLrngEna_Cnt_T_lgc;
    VAR(float32, AUTOMATIC) HwTorqueFild_HwNm_T_f32;
    VAR(boolean, AUTOMATIC) HwAgMoved_Cnt_T_lgc;

    VAR(boolean, AUTOMATIC) TqInpPrsntVld_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) TqInpPrsnt_Cnt_T_lgc;


    VAR(float32, AUTOMATIC) PhaAgStep_Rad_T_f32;
    VAR(float32, AUTOMATIC) HwTqPreproc_dB_T_f32;
    VAR(float32, AUTOMATIC) FreqCenFiltSt0_Uls_T_f32;
    VAR(float32, AUTOMATIC) FreqDwnFiltSt1_Uls_T_f32;
    VAR(float32, AUTOMATIC) FreqDwnFiltSt0_Uls_T_f32;
    VAR(float32, AUTOMATIC) SGoutput_dB_T_f32;
    VAR(float32, AUTOMATIC) MagnSq_Uls_T_f32;
    VAR(float32, AUTOMATIC) FiltSt0_Uls_T_f32;
    VAR(float32, AUTOMATIC) FiltSt1_Uls_T_f32;
    VAR(float32, AUTOMATIC) FreqCenFiltSt1_Uls_T_f32;
    VAR(float32, AUTOMATIC) MagnSqFreqUp_Uls_T_f32;

    VAR(float32, AUTOMATIC) MagnSqFreqCen_Uls_T_f32;

    VAR(float32, AUTOMATIC) MagnSqFreqDwn_Uls_T_f32;


    VAR(float32, AUTOMATIC) TrqOscCmd_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) HwTrq_HwNm_T_f32;
    VAR(float32, AUTOMATIC) X0HwTrq_HwNm_T_f32;


    VAR(uint16, AUTOMATIC) SampleCntrLim_Cnt_T_u16;


    VAR(uint16, AUTOMATIC) TqInpDetnPreProcEnaLoop_Cnt_T_u16;

    VAR(uint32, AUTOMATIC) Elapsedtime_mS_T_u32;
       
    HandwheelAuthority_Uls_T_f32    = Rte_IRead_SnsrOffsLrng_Per1_HandwheelAuthority_Uls_f32();    /* REQ: SF051A #172 I */
    HandwheelPosition_HwDeg_T_f32   = Rte_IRead_SnsrOffsLrng_Per1_HandwheelPosition_HwDeg_f32();   /* REQ: SF051A #170 I */
    HandwheelVelocity_HwRadpS_T_f32 = Rte_IRead_SnsrOffsLrng_Per1_HandwheelVelocity_HwRadpS_f32(); /* REQ: SF051A #169 I */
    HwTorque_HwNm_T_f32             = Rte_IRead_SnsrOffsLrng_Per1_HwTorque_HwNm_f32();             /* REQ: SF051A #168 I */
    VehicleSpeedValid_Cnt_T_lgc     = Rte_IRead_SnsrOffsLrng_Per1_VehicleSpeedValid_Cnt_lgc();     /* REQ: SF051A #172 I */
    VehicleSpeed_Kph_T_f32          = Rte_IRead_SnsrOffsLrng_Per1_VehicleSpeed_Kph_f32();          /* REQ: SF051A #171 I */

    /* REQ: SF051A #26  I */
    /* REQ: SF051A #149 I */
    /* REQ: SF051A #172 I */
    if((k_SOaC_FctEna_Cnt_lgc == TRUE) && (k_SOaC_HwTqLrngEna_Cnt_lgc == TRUE) &&(HandwheelAuthority_Uls_T_f32 >=D_HWAUTHYTHD_ULS_F32) &&(VehicleSpeedValid_Cnt_T_lgc== TRUE))
    {
         /************** EnableLearning****************/
         /*********Filter_HwTq*****************/
         HwTorqueFild_HwNm_T_f32 = LPF_OpUpdate_f32_m(HwTorque_HwNm_T_f32,&SOaC_TqInpDetnHwTqFil_Uls_M_str);
         SOaC_TqInpDetnHwTqFild_HwNm_D_f32  =  HwTorqueFild_HwNm_T_f32;

         /****************CheckLastMeasHwPos**************/
         /* REQ: SF051A #153  I */
         if(Abs_f32_m(HandwheelPosition_HwDeg_T_f32 - FPM_FixedToFloat_m(Rte_Pim_SnsrLrndOffs()->HwTqLrngHwAgRef,s11p4_T)) >= k_SOaC_HwTqLrngHwAgDbnd_HwDeg_f32)
         {
            HwAgMoved_Cnt_T_lgc = TRUE;
            Rte_Pim_SnsrLrndOffs()->HwTqLrngHwAgRef = FPM_FloatToFixed_m(D_HWAGHILIM_HWDEG_F32,s11p4_T);
         }
         else
         {
            HwAgMoved_Cnt_T_lgc = FALSE;
         }
         /**********CheckLastMeasHwPos**************/
         /* REQ: SF051A #164  I */
         if((Abs_f32_m(HwTorque_HwNm_T_f32)             <= k_SOaC_HwTqLrngHwTqThd_HwNm_f32    ) &&   /* PRQA S 3415 */
            (Abs_f32_m(HandwheelVelocity_HwRadpS_T_f32) <= k_SOaC_HwTqLrngHwVelThd_HwRadpS_f32) && /* PRQA S 3415 */
            (Abs_f32_m(HandwheelPosition_HwDeg_T_f32)   <= k_SOaC_HwTqLrngHwAgThd_HwDeg_f32   ) && /* PRQA S 3415 */
            (VehicleSpeed_Kph_T_f32                     <= k_SOaC_HwTqLrngVehSpdThd_Kph_f32   ) &&
            (HwAgMoved_Cnt_T_lgc                        == TRUE)) /* ENDREQ: SF051A #153 */
         {
            /**********Perform_TqInpDetn*************/
            /* REQ: SF051A #166  I */
            Perform_TqInpDetn();

            /************ElapsedTime*********/
            SOaC_TqInpDetnEnaTi_Sec_M_f32 = Min_m(SOaC_TqInpDetnEnaTi_Sec_M_f32 +  D_2MS_SEC_F32, D_HWTQLRNGTMRHILIM_SEC_F32);

            /*************************Enable Preprocessing**************/

            /***Preprocessing**/

            SampleCntrLim_Cnt_T_u16 = k_SOaC_TqInpDetnStg2WinSize_Cnt_u16 + (uint16)k_SOaC_TqInpDetnStg1WinSize_Cnt_u08;

            /********************SampleCounter************/
            SOaC_TqInpDetnPreProcEnaLoop_Cnt_M_u16 = SOaC_TqInpDetnPreProcEnaLoop_Cnt_M_u16+1U;
            TqInpDetnPreProcEnaLoop_Cnt_T_u16 = Min_m(SOaC_TqInpDetnPreProcEnaLoop_Cnt_M_u16, SampleCntrLim_Cnt_T_u16);

            /***********************Stage 1*********************/
            /************Sliding_Goertzel_ver001**************/

            /**********SinGen*******************/
            PhaAgStep_Rad_T_f32 = k_SOaC_TqInpDetnSinGenrFrq_Hz_f32 * D_2PI_RADPREV_F32* D_2MS_SEC_F32;
            SOaC_TqInpDetnSinGenrAg_Rad_M_f32 = PhaAgStep_Rad_T_f32 +  SOaC_TqInpDetnSinGenrAg_Rad_M_f32;
            if(SOaC_TqInpDetnSinGenrAg_Rad_M_f32 >=  D_2PI_RADPREV_F32)
            {
                SOaC_TqInpDetnSinGenrAg_Rad_M_f32 = SOaC_TqInpDetnSinGenrAg_Rad_M_f32 -  D_2PI_RADPREV_F32;
            }
            TrqOscCmd_MtrNm_T_f32 =  k_SOaC_TqInpDetnSinGenrAmp_HwNm_f32 * sinf(SOaC_TqInpDetnSinGenrAg_Rad_M_f32);
            HwTrq_HwNm_T_f32 = HwTorqueFild_HwNm_T_f32 +  TrqOscCmd_MtrNm_T_f32;
            
            
            /****************SlidingGoertzel*******************/

            X0HwTrq_HwNm_T_f32 =HwTrq_HwNm_T_f32 - SOaC_TqInpDetnStg1Buf_HwNm_M_f32[SOaC_TqInpDetnStg1Idx_Cnt_M_u08];
            SOaC_TqInpDetnStg1Buf_HwNm_M_f32[SOaC_TqInpDetnStg1Idx_Cnt_M_u08] =  HwTrq_HwNm_T_f32;
            if( (SOaC_TqInpDetnStg1Idx_Cnt_M_u08 + 1U ) >=  k_SOaC_TqInpDetnStg1WinSize_Cnt_u08)
            {
                SOaC_TqInpDetnStg1Idx_Cnt_M_u08 = D_ZERO_CNT_U8;
            }
            else
            {
                SOaC_TqInpDetnStg1Idx_Cnt_M_u08 = SOaC_TqInpDetnStg1Idx_Cnt_M_u08 + 1U;
            }
            /*Goertzel_Part1*/
            FiltSt0_Uls_T_f32 = (X0HwTrq_HwNm_T_f32 + (k_SOaC_TqInpDetnStg1FiltGain_Uls_f32*SOaC_TqInpDetnStg1FiltSt1_Uls_M_f32)) - (SOaC_TqInpDetnStg1FiltSt2_Uls_M_f32);
            FiltSt1_Uls_T_f32 = SOaC_TqInpDetnStg1FiltSt1_Uls_M_f32;
            SOaC_TqInpDetnStg1FiltSt2_Uls_M_f32 = SOaC_TqInpDetnStg1FiltSt1_Uls_M_f32;
            SOaC_TqInpDetnStg1FiltSt1_Uls_M_f32 = FiltSt0_Uls_T_f32;

            /*Goertzel_Part2*/
            MagnSq_Uls_T_f32 = ((FiltSt0_Uls_T_f32*FiltSt0_Uls_T_f32) + (FiltSt1_Uls_T_f32*FiltSt1_Uls_T_f32)) -(FiltSt0_Uls_T_f32*FiltSt1_Uls_T_f32*k_SOaC_TqInpDetnStg1FiltGain_Uls_f32);

            SGoutput_dB_T_f32 = (log10f(Limit_m((MagnSq_Uls_T_f32/((float32)k_SOaC_TqInpDetnStg1WinSize_Cnt_u08*(float32)k_SOaC_TqInpDetnStg1WinSize_Cnt_u08)),D_TQINPDETNLOGINPLOLIM_ULS_F32 ,D_TQINPDETNLOGINPHILIM_ULS_F32)))* D_TQINPDETNLOGGAIN_ULS_F32;
            SOaC_TqInpDetnStg1Outp_dB_D_f32 =  SGoutput_dB_T_f32;
            /*****************************General_Goertzel*********************/
            /***Stage 2************/
            if(TqInpDetnPreProcEnaLoop_Cnt_T_u16 >= (uint16)k_SOaC_TqInpDetnStg1WinSize_Cnt_u08)
            {
                /****************************Goertzel_part1_1*******************************/
                FreqDwnFiltSt0_Uls_T_f32 =  (SGoutput_dB_T_f32 + (k_SOaC_TqInpDetnStg2FiltGainDwn_Uls_f32*SOaC_TqInpDetnStg2DwnFiltSt1_Uls_M_f32)) -SOaC_TqInpDetnStg2DwnFiltSt2_Uls_M_f32;
                FreqDwnFiltSt1_Uls_T_f32 =  SOaC_TqInpDetnStg2DwnFiltSt1_Uls_M_f32;

                SOaC_TqInpDetnStg2DwnFiltSt2_Uls_M_f32 = SOaC_TqInpDetnStg2DwnFiltSt1_Uls_M_f32;
                SOaC_TqInpDetnStg2DwnFiltSt1_Uls_M_f32 =  FreqDwnFiltSt0_Uls_T_f32;

                /****************************Goertzel_part1_2*******************************/
                FreqCenFiltSt0_Uls_T_f32 =  (SGoutput_dB_T_f32 + (k_SOaC_TqInpDetnStg2FiltGainCen_Uls_f32*SOaC_TqInpDetnStg2CenFiltSt1_Uls_M_f32)) -SOaC_TqInpDetnStg2CenFiltSt2_Uls_M_f32;
                FreqCenFiltSt1_Uls_T_f32 =  SOaC_TqInpDetnStg2CenFiltSt1_Uls_M_f32;

                SOaC_TqInpDetnStg2CenFiltSt2_Uls_M_f32 = SOaC_TqInpDetnStg2CenFiltSt1_Uls_M_f32;
                SOaC_TqInpDetnStg2CenFiltSt1_Uls_M_f32 =  FreqCenFiltSt0_Uls_T_f32;

                /****************************Goertzel_part1_3*******************************/
                FiltSt0_Uls_T_f32 =  (SGoutput_dB_T_f32 + (k_SOaC_TqInpDetnStg2FiltGainUp_Uls_f32*SOaC_TqInpDetnStg2UpFiltSt1_Uls_M_f32)) -SOaC_TqInpDetnStg2UpFiltSt2_Uls_M_f32;
                FiltSt1_Uls_T_f32 =  SOaC_TqInpDetnStg2UpFiltSt1_Uls_M_f32;

                SOaC_TqInpDetnStg2UpFiltSt2_Uls_M_f32 = SOaC_TqInpDetnStg2UpFiltSt1_Uls_M_f32;
                SOaC_TqInpDetnStg2UpFiltSt1_Uls_M_f32 =  FiltSt0_Uls_T_f32;

            }
            if(TqInpDetnPreProcEnaLoop_Cnt_T_u16 >= SampleCntrLim_Cnt_T_u16)
            {
                MagnSqFreqDwn_Uls_T_f32 = ((FreqDwnFiltSt0_Uls_T_f32*FreqDwnFiltSt0_Uls_T_f32) + (FreqDwnFiltSt1_Uls_T_f32*FreqDwnFiltSt1_Uls_T_f32)) -(FreqDwnFiltSt0_Uls_T_f32*FreqDwnFiltSt1_Uls_T_f32*k_SOaC_TqInpDetnStg2FiltGainDwn_Uls_f32);
                MagnSqFreqCen_Uls_T_f32 = ((FreqCenFiltSt0_Uls_T_f32*FreqCenFiltSt0_Uls_T_f32) + (FreqCenFiltSt1_Uls_T_f32*FreqCenFiltSt1_Uls_T_f32)) -(FreqCenFiltSt0_Uls_T_f32*FreqCenFiltSt1_Uls_T_f32*k_SOaC_TqInpDetnStg2FiltGainCen_Uls_f32);
                MagnSqFreqUp_Uls_T_f32 =  ((FiltSt0_Uls_T_f32*FiltSt0_Uls_T_f32) + (FiltSt1_Uls_T_f32*FiltSt1_Uls_T_f32)) -(FiltSt0_Uls_T_f32*FiltSt1_Uls_T_f32*k_SOaC_TqInpDetnStg2FiltGainUp_Uls_f32);

                HwTqPreproc_dB_T_f32 = (log10f(Limit_m(((MagnSqFreqDwn_Uls_T_f32 + MagnSqFreqCen_Uls_T_f32 + MagnSqFreqUp_Uls_T_f32)/(float32)((float32)k_SOaC_TqInpDetnStg2WinSize_Cnt_u16*(float32)k_SOaC_TqInpDetnStg2WinSize_Cnt_u16)),D_TQINPDETNLOGINPLOLIM_ULS_F32 ,D_TQINPDETNLOGINPHILIM_ULS_F32)))* D_TQINPDETNLOGGAIN_ULS_F32;
                SOaC_TqInpDetnStg2DwnFiltSt2_Uls_M_f32 = D_ZERO_ULS_F32;
                SOaC_TqInpDetnStg2DwnFiltSt1_Uls_M_f32 = D_ZERO_ULS_F32;
                SOaC_TqInpDetnStg2CenFiltSt2_Uls_M_f32 = D_ZERO_ULS_F32;
                SOaC_TqInpDetnStg2CenFiltSt1_Uls_M_f32 = D_ZERO_ULS_F32;
                SOaC_TqInpDetnStg2UpFiltSt2_Uls_M_f32  = D_ZERO_ULS_F32;
                SOaC_TqInpDetnStg2UpFiltSt1_Uls_M_f32  = D_ZERO_ULS_F32;
                SOaC_TqInpDetnHwTqPreProc_dB_M_f32     =  HwTqPreproc_dB_T_f32;
                SOaC_TqInpDetnPreProcEnaLoop_Cnt_M_u16 = (uint16)k_SOaC_TqInpDetnStg1WinSize_Cnt_u08;
                
            }
            else
            {
                HwTqPreproc_dB_T_f32 = SOaC_TqInpDetnHwTqPreProc_dB_M_f32;
                SOaC_TqInpDetnPreProcEnaLoop_Cnt_M_u16 = TqInpDetnPreProcEnaLoop_Cnt_T_u16;
            }

            EnablePreProcessing( HwTqPreproc_dB_T_f32, SampleCntrLim_Cnt_T_u16, &TqInpPrsntVld_Cnt_T_lgc, &TqInpPrsnt_Cnt_T_lgc);
            SOaC_HwTqLrngTqInpDetnEnaPrev_Cnt_M_lgc = TRUE;
         }/* ENDREQ: SF051A #166 */
         else
         {
            /************Default_TqInpDetn***************/
            TqInpPrsntVld_Cnt_T_lgc = FALSE;
            TqInpPrsnt_Cnt_T_lgc = TRUE;
            SOaC_HwTqLrngTqInpDetnEnaPrev_Cnt_M_lgc = FALSE;
         }
         SOaC_HwTqLrngTrqInptPrsntVld_Cnt_D_lgc = TqInpPrsntVld_Cnt_T_lgc;
         SOaC_HwTqLrngTrqInptPrsnt_Cnt_D_lgc = TqInpPrsnt_Cnt_T_lgc;
         if((TqInpPrsntVld_Cnt_T_lgc==TRUE) &&(TqInpPrsnt_Cnt_T_lgc== FALSE))
         {
             (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(SOaC_HwTqLrngEnaTmrRef_mS_M_u32,&Elapsedtime_mS_T_u32);
             if((uint16)Elapsedtime_mS_T_u32 >= k_SOaC_HwTqLrngEnaTiThd_mS_u16p0 )
             {
                 HwTqLrngEna_Cnt_T_lgc = TRUE;
             }
             else
             {
                 HwTqLrngEna_Cnt_T_lgc = FALSE;
             }
         }
         else
         {
             HwTqLrngEna_Cnt_T_lgc = FALSE;
             (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&SOaC_HwTqLrngEnaTmrRef_mS_M_u32);
         }/* ENDREQ: SF051A #164 */
    }
    else
    {
      HwTqLrngEna_Cnt_T_lgc = FALSE;
    }

    return HwTqLrngEna_Cnt_T_lgc;
    /* ENDREQ: SF051A #165*/
}

/*****************************************************************************
  * Name:        EnablePreProcessing
  * Description: 
  * Inputs:      HwTqPreproc_dB_T_f32   
  *              SampleCntrLim_Cnt_T_u16
  *    
  *              
  * Outputs:     *TqInpPrsntVld_Cnt_T_lgc
  *              *TqInpPrsnt_Cnt_T_lgc
*****************************************************************************/
STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)EnablePreProcessing(VAR(float32, AUTOMATIC) HwTqPreproc_dB_T_f32, VAR(uint16, AUTOMATIC)SampleCntrLim_Cnt_T_u16, P2VAR(boolean, AUTOMATIC, AUTOMATIC) TqInpPrsntVld_Cnt_T_lgc, P2VAR(boolean, AUTOMATIC, AUTOMATIC) TqInpPrsnt_Cnt_T_lgc)
{       
    VAR(boolean, AUTOMATIC) TqInpPrsntRaw_Cnt_T_lgc;
    VAR(boolean, AUTOMATIC) HwTqPreprocVld_Cnt_T_lgc;        

    if(HwTqPreproc_dB_T_f32 > k_SOaC_TqInpDetnPwrEstimnThd_dB_f32)
    {

        TqInpPrsntRaw_Cnt_T_lgc = TRUE;
    }
    else
    {
        TqInpPrsntRaw_Cnt_T_lgc = FALSE;
    }
    if( SOaC_TqInpDetnEnaTi_Sec_M_f32>= (D_2MS_SEC_F32*(float32)SampleCntrLim_Cnt_T_u16))
    {
        HwTqPreprocVld_Cnt_T_lgc = TRUE;
    }
    else
    {
        HwTqPreprocVld_Cnt_T_lgc = FALSE;
    }
    SOaC_TrqInptPrsntRaw_Cnt_D_lgc = TqInpPrsntRaw_Cnt_T_lgc;
    if(HwTqPreprocVld_Cnt_T_lgc == TRUE)
    {
        if(TqInpPrsntRaw_Cnt_T_lgc == TRUE)
        {
            *TqInpPrsntVld_Cnt_T_lgc = TRUE;
            *TqInpPrsnt_Cnt_T_lgc = TRUE;
        }
        else
        {
            *TqInpPrsntVld_Cnt_T_lgc = TRUE;
            *TqInpPrsnt_Cnt_T_lgc = FALSE;
        }
        
    }
    else
    {
        *TqInpPrsntVld_Cnt_T_lgc = FALSE;
        *TqInpPrsnt_Cnt_T_lgc = SOaC_HwTqLrngTqInpPrsnt_Cnt_M_lgc;
    }
    SOaC_HwTqLrngTqInpPrsnt_Cnt_M_lgc = *TqInpPrsnt_Cnt_T_lgc;
}

/*****************************************************************************
  * Name:        CalculateKVector
  * Description: 
  * Inputs:      TqMdlAryKVect_Uls_T_f32 -Array of 3 Matrix                   
  *              
  *    
  *              
  * Outputs:     KVect_Uls_T_f32
  *
*****************************************************************************/
STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)CalculateKVector(CONST(float32, AUTOMATIC) TqMdlXAry_HwRadpS_T_f32[D_MATRIXSIZE_CNT_U08], P2VAR(float32, AUTOMATIC, AUTOMATIC) KVect_Uls_T_f32)
{   

    VAR(float32, AUTOMATIC) SumQTemp_HwRadpS_T_f32;
    VAR(float32, AUTOMATIC) SumQTempSclr_HwRadpS_T_f32;
    VAR(float32, AUTOMATIC) QTemp_HwRadpS_T_f32[D_MATRIXSIZE_CNT_U08];
    VAR(uint16, AUTOMATIC)  IterCnt1_Cnt_T_u16,IterCnt2_Cnt_T_u16;
    
    for(IterCnt1_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt1_Cnt_T_u16< (TableSize_m(QTemp_HwRadpS_T_f32)); IterCnt1_Cnt_T_u16++)
    {
        SumQTemp_HwRadpS_T_f32 = D_ZERO_ULS_F32;
        for (IterCnt2_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt2_Cnt_T_u16< TableSize_m(QTemp_HwRadpS_T_f32);IterCnt2_Cnt_T_u16++)
        {
            SumQTemp_HwRadpS_T_f32 += Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx[IterCnt1_Cnt_T_u16][IterCnt2_Cnt_T_u16] * TqMdlXAry_HwRadpS_T_f32[IterCnt2_Cnt_T_u16];
        }
        QTemp_HwRadpS_T_f32[IterCnt1_Cnt_T_u16]= SumQTemp_HwRadpS_T_f32;
    }
    
    SumQTempSclr_HwRadpS_T_f32 =D_ZERO_ULS_F32;
    for(IterCnt1_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt1_Cnt_T_u16< (TableSize_m(QTemp_HwRadpS_T_f32)); IterCnt1_Cnt_T_u16++)
    {
        SumQTempSclr_HwRadpS_T_f32 += TqMdlXAry_HwRadpS_T_f32[IterCnt1_Cnt_T_u16]*QTemp_HwRadpS_T_f32[IterCnt1_Cnt_T_u16];
    }
    SumQTempSclr_HwRadpS_T_f32=SumQTempSclr_HwRadpS_T_f32 + k_SOaC_HwTqLrngTiWghtCoeff_Uls_f32; /* REQ: SF051A #243 I */
    
    for(IterCnt1_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt1_Cnt_T_u16< (TableSize_m(QTemp_HwRadpS_T_f32)); IterCnt1_Cnt_T_u16++)
    {
        KVect_Uls_T_f32[IterCnt1_Cnt_T_u16] = QTemp_HwRadpS_T_f32[IterCnt1_Cnt_T_u16]/SumQTempSclr_HwRadpS_T_f32; /* PRQA S 492 */
    }
}


/*****************************************************************************
  * Name:        UpdateCovarianceMatrix
  * Description: 
  * Inputs:      TqMdlAryKVect_Uls_T_f32 -Array of 3*3 Matrix                   
  *              TblSize_Cnt_T_u16 - One dimension size of Covariance Matrix
  *    
  *              
  * Outputs:     None
  *
*****************************************************************************/
STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)UpdateCovarianceMatrix(P2CONST(float32, AUTOMATIC,AUTOMATIC) TqMdlAryKVect_Uls_T_f32, VAR(uint16, AUTOMATIC) TblSize_Cnt_T_u16)
{
    VAR(uint16, AUTOMATIC)  IterCnt1_Cnt_T_u16,IterCnt2_Cnt_T_u16,IterCnt3_Cnt_T_u16;
    VAR(float32, AUTOMATIC) SumQTemp_HwRadpS_T_f32;
    VAR(float32, AUTOMATIC) HwTqLrngCovariMtrx_T_HwRadpS_T_f32[D_MATRIXSIZE_CNT_U08][D_MATRIXSIZE_CNT_U08];

    for(IterCnt1_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt1_Cnt_T_u16<(TblSize_Cnt_T_u16);IterCnt1_Cnt_T_u16++)
    {
        for(IterCnt2_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt2_Cnt_T_u16<(TblSize_Cnt_T_u16);IterCnt2_Cnt_T_u16++)
        {
            SumQTemp_HwRadpS_T_f32 = D_ZERO_ULS_F32;
            
            for(IterCnt3_Cnt_T_u16=D_ZERO_CNT_U16;IterCnt3_Cnt_T_u16<(TblSize_Cnt_T_u16);IterCnt3_Cnt_T_u16++)
            {
                SumQTemp_HwRadpS_T_f32 +=   (*((TqMdlAryKVect_Uls_T_f32+ (IterCnt1_Cnt_T_u16*TblSize_Cnt_T_u16)) + IterCnt3_Cnt_T_u16) * (Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx[IterCnt3_Cnt_T_u16][IterCnt2_Cnt_T_u16] ) ); /* PRQA S 488 */
            }
             HwTqLrngCovariMtrx_T_HwRadpS_T_f32[IterCnt1_Cnt_T_u16][IterCnt2_Cnt_T_u16] = SumQTemp_HwRadpS_T_f32;
        }
    }
    for(IterCnt1_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt1_Cnt_T_u16<(TblSize_Cnt_T_u16);IterCnt1_Cnt_T_u16++)
    {
        for(IterCnt2_Cnt_T_u16=D_ZERO_CNT_U16; IterCnt2_Cnt_T_u16<(TblSize_Cnt_T_u16);IterCnt2_Cnt_T_u16++)
        {
            Rte_Pim_SnsrLrndOffs()->HwTqLrngCovariMtrx[IterCnt1_Cnt_T_u16][IterCnt2_Cnt_T_u16] =HwTqLrngCovariMtrx_T_HwRadpS_T_f32[IterCnt1_Cnt_T_u16][IterCnt2_Cnt_T_u16]; /*REQ: SF051A #174 I */ /*REQ: SF051A #173 I */
        }
            
    }       
}

/*****************************************************************************
  * Name:        UpdateHwTqOffs
  * Description: 
  * Inputs:      HwTqEstimnVld_Cnt_T_lgc                   
  *              HwTqDriftEstimnOnCentr_HwNm_T_f32
  *    
  *              
  * Outputs:     None
  *
*****************************************************************************/

STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)UpdateHwTqOffs(VAR(boolean, AUTOMATIC) HwTqEstimnVld_Cnt_T_lgc, VAR(float32, AUTOMATIC) HwTqDriftEstimnOnCentr_HwNm_T_f32)
{
    if(HwTqEstimnVld_Cnt_T_lgc == TRUE) /* REQ: SF051A #191 I */
    {
        Rte_Pim_SnsrLrndOffs()->HwTqOffs = FPM_FloatToFixed_m(Limit_m(HwTqDriftEstimnOnCentr_HwNm_T_f32,-k_SOaC_HwTqOffsLim_HwNm_f32,k_SOaC_HwTqOffsLim_HwNm_f32),s3p12_T); /* PRQA S 4395 */ /* REQ: SF051A #190 I */
    }
}
/*****************************************************************************
  * Name:        UpdateSampleCnt
  * Description: 
  * Inputs:      HwAgMeasrmnt_HwDeg_T_f32
  *
  *    
  *              
  * Outputs:     None
  *
*****************************************************************************/

STATIC INLINE FUNC(void, AP_SNSROFFSLRNG_CODE)UpdateSampleCnt( VAR(float32, AUTOMATIC) HwAgMeasrmnt_HwDeg_T_f32)
{
    if(HwAgMeasrmnt_HwDeg_T_f32>=D_ZERO_ULS_F32)
    {
        Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntPos++; /* REQ: SF051A #180 I */
    }
    else
    {
        Rte_Pim_SnsrLrndOffs()->HwTqLrngSampleCntNeg++; /* REQ: SF051A #178 I */
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
