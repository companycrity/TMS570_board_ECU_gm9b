
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Cd_NvMProxy_PBcfg.h
* Module Description: Configuration of the Cd_NvMProxy BSW
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
 * Version Control:
 * Date Created:      Tue Feb  7 11:23:49 2012
 * %version:          EA3#9 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Wed Nov 20 08:22:29 2013 % 
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/07/12   1        JJW       Initial creation
 * 10/17/12   2        JJW       Generated output file
 * 11/20/12   3        JJW       Removed generation of Block status mirror array.  It is defined in the static SWC
 * 05/30/13   4        JJW       Removed unsuported config feature, added multi-block support
 * 11/21/13   5        LWW       Added Redundant and CRC block checking
 */

#include "Std_Types.h"
#define NVMPROXY_C
#include "Cd_NvMProxy_Cfg.h"
#undef NVMPROXY_C


/* Global data buffers to be used in NvM cfg for Read All destinations */
#define NVMPROXY_START_SEC_VAR_NOINIT_8
#include "MemMap.h"


	
#pragma DATA_ALIGN (NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32[sizeof(Rte_TrqCmdScl_TorqueCmdSF_Uls_f32)];	
	
	
	
	
//#pragma DATA_ALIGN (NvMP_TypeHData_Cnt_u08, 4U); /* NEXTEER PATCH: Added to force 32-bit alignment: A_5202 */
//VAR(uint8, AUTOMATIC) NvMP_TypeHData_Cnt_u08[sizeof(TypeHData_Cnt_u08)];
	
#pragma DATA_ALIGN (NvMP_Rte_Ap_TrqCanc_CogTrqCal, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_TrqCanc_CogTrqCal[sizeof(Rte_Ap_TrqCanc_CogTrqCal)];	
	
#pragma DATA_ALIGN (NvMP_Rte_CurrParamComp_EOLNomMtrParam, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_CurrParamComp_EOLNomMtrParam[sizeof(Rte_CurrParamComp_EOLNomMtrParam)];	
	
#pragma DATA_ALIGN (NvMP_Rte_DigColPs_DigColPsEOL, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_DigColPs_DigColPsEOL[sizeof(Rte_DigColPs_DigColPsEOL)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Ap_TrqCanc_CogTrqRplComp, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_TrqCanc_CogTrqRplComp[sizeof(Rte_Ap_TrqCanc_CogTrqRplComp)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Ap_TSMit_TSMitDisableEOL, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_TSMit_TSMitDisableEOL[sizeof(Rte_Ap_TSMit_TSMitDisableEOL)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Ap_TSMit_TSMitGainLrn, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_TSMit_TSMitGainLrn[sizeof(Rte_Ap_TSMit_TSMitGainLrn)];	
	
#pragma DATA_ALIGN (NvMP_Rte_VehDyn_MotPosReset, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_VehDyn_MotPosReset[sizeof(Rte_VehDyn_MotPosReset)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Sa_HwTqCorrln_HwTqCor_Ch1CMCLPFSv_HwNm_f32, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_HwTqCorrln_HwTqCor_Ch1CMCLPFSv_HwNm_f32[sizeof(Rte_Sa_HwTqCorrln_HwTqCor_Ch1CMCLPFSv_HwNm_f32)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Sa_HwTqCorrln_HwTqCor_Ch2CMCLPFSv_HwNm_f32, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_HwTqCorrln_HwTqCor_Ch2CMCLPFSv_HwNm_f32[sizeof(Rte_Sa_HwTqCorrln_HwTqCor_Ch2CMCLPFSv_HwNm_f32)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str[sizeof(Rte_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Sa_AnaHwTrq_AnaHwTrqScaleData, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_AnaHwTrq_AnaHwTrqScaleData[sizeof(Rte_Sa_AnaHwTrq_AnaHwTrqScaleData)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Sa_AnaHwTrq_AnaHwTrqT1T2TrimData, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_AnaHwTrq_AnaHwTrqT1T2TrimData[sizeof(Rte_Sa_AnaHwTrq_AnaHwTrqT1T2TrimData)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Sa_CmMtrCurr3Phs_ShCurrCal3Phs, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_CmMtrCurr3Phs_ShCurrCal3Phs[sizeof(Rte_Sa_CmMtrCurr3Phs_ShCurrCal3Phs)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Sa_MotMeclPosn1_MotMeclPosn1CoeffTblData, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_MotMeclPosn1_MotMeclPosn1CoeffTblData[sizeof(Rte_Sa_MotMeclPosn1_MotMeclPosn1CoeffTblData)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Sa_MotMeclPosn2_MotMeclPosn2CoeffTblData, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_MotMeclPosn2_MotMeclPosn2CoeffTblData[sizeof(Rte_Sa_MotMeclPosn2_MotMeclPosn2CoeffTblData)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Sa_MtrPos3SinCos_MtrPos3_EOLParams, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_MtrPos3SinCos_MtrPos3_EOLParams[sizeof(Rte_Sa_MtrPos3SinCos_MtrPos3_EOLParams)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Ap_MotPosnCmp_MotPosnCmpMtrPosBackEmf, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_MotPosnCmp_MotPosnCmpMtrPosBackEmf[sizeof(Rte_Ap_MotPosnCmp_MotPosnCmpMtrPosBackEmf)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Sa_HwTrqArbn_EOLCh1OffsetTrimData, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_HwTrqArbn_EOLCh1OffsetTrimData[sizeof(Rte_Sa_HwTrqArbn_EOLCh1OffsetTrimData)];	
	
#pragma DATA_ALIGN (NvMP_Rte_Sa_HwTrqArbn_EOLCh2OffsetTrimData, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_HwTrqArbn_EOLCh2OffsetTrimData[sizeof(Rte_Sa_HwTrqArbn_EOLCh2OffsetTrimData)];	
	
#pragma DATA_ALIGN (NvMP_Rte_TrqOvlSta_GmLoaIgnCntr, 4U);
VAR(uint8, AUTOMATIC) NvMP_Rte_TrqOvlSta_GmLoaIgnCntr[sizeof(Rte_TrqOvlSta_GmLoaIgnCntr)];	

#define NVMPROXY_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

/* Block Test and Copy Configuration */
#define NVMPROXY_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
CONST(NvMProxyCfg_Type, AUTOMATIC) NvMProxyCfg[ D_NUMPRXYBLOCKS_CNT_U16 ] = {
	{0, NULL_PTR,  NULL_PTR, 0, NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR}, /* Multi-block fixed config */
	{Rte_NvmBlock_TrqCmdScl_TorqueCmdSF_Uls_f32, (uint8*)&NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32,  (uint8*)&Rte_TrqCmdScl_TorqueCmdSF_Uls_f32, sizeof(Rte_TrqCmdScl_TorqueCmdSF_Uls_f32), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{NVM_BLOCK_STAMD_CLOSECHECK, (uint8*)&CloseCheck_Cnt_u32,  (uint8*)&CloseCheck_Cnt_u32, sizeof(CloseCheck_Cnt_u32), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{NVM_BLOCK_STAMD_TYPEH, (uint8*)&TypeHData_Cnt_u08,  (uint8*)&TypeHData_Cnt_u08, sizeof(TypeHData_Cnt_u08), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR}, /* Nexteer Hand Edit */
	{Rte_NvmBlock_Ap_TrqCanc_CogTrqCal, (uint8*)&NvMP_Rte_Ap_TrqCanc_CogTrqCal,  (uint8*)&Rte_Ap_TrqCanc_CogTrqCal, sizeof(Rte_Ap_TrqCanc_CogTrqCal), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_CurrParamComp_EOLNomMtrParam, (uint8*)&NvMP_Rte_CurrParamComp_EOLNomMtrParam,  (uint8*)&Rte_CurrParamComp_EOLNomMtrParam, sizeof(Rte_CurrParamComp_EOLNomMtrParam), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_DigColPs_DigColPsEOL, (uint8*)&NvMP_Rte_DigColPs_DigColPsEOL,  (uint8*)&Rte_DigColPs_DigColPsEOL, sizeof(Rte_DigColPs_DigColPsEOL), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Ap_TrqCanc_CogTrqRplComp, (uint8*)&NvMP_Rte_Ap_TrqCanc_CogTrqRplComp,  (uint8*)&Rte_Ap_TrqCanc_CogTrqRplComp, sizeof(Rte_Ap_TrqCanc_CogTrqRplComp), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Ap_TSMit_TSMitDisableEOL, (uint8*)&NvMP_Rte_Ap_TSMit_TSMitDisableEOL,  (uint8*)&Rte_Ap_TSMit_TSMitDisableEOL, sizeof(Rte_Ap_TSMit_TSMitDisableEOL), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Ap_TSMit_TSMitGainLrn, (uint8*)&NvMP_Rte_Ap_TSMit_TSMitGainLrn,  (uint8*)&Rte_Ap_TSMit_TSMitGainLrn, sizeof(Rte_Ap_TSMit_TSMitGainLrn), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_VehDyn_MotPosReset, (uint8*)&NvMP_Rte_VehDyn_MotPosReset,  (uint8*)&Rte_VehDyn_MotPosReset, sizeof(Rte_VehDyn_MotPosReset), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Sa_HwTrqCorrln_Ch1CMCLPFSv_HwNm_f32, (uint8*)&NvMP_Rte_Sa_HwTqCorrln_HwTqCor_Ch1CMCLPFSv_HwNm_f32,  (uint8*)&Rte_Sa_HwTqCorrln_HwTqCor_Ch1CMCLPFSv_HwNm_f32, sizeof(Rte_Sa_HwTqCorrln_HwTqCor_Ch1CMCLPFSv_HwNm_f32), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Sa_HwTrqCorrln_Ch2CMCLPFSv_HwNm_f32, (uint8*)&NvMP_Rte_Sa_HwTqCorrln_HwTqCor_Ch2CMCLPFSv_HwNm_f32,  (uint8*)&Rte_Sa_HwTqCorrln_HwTqCor_Ch2CMCLPFSv_HwNm_f32, sizeof(Rte_Sa_HwTqCorrln_HwTqCor_Ch2CMCLPFSv_HwNm_f32), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str, (uint8*)&NvMP_Rte_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str,  (uint8*)&Rte_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str, sizeof(Rte_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Sa_AnaHwTrq_AnaHwTrqScaleData, (uint8*)&NvMP_Rte_Sa_AnaHwTrq_AnaHwTrqScaleData,  (uint8*)&Rte_Sa_AnaHwTrq_AnaHwTrqScaleData, sizeof(Rte_Sa_AnaHwTrq_AnaHwTrqScaleData), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Sa_AnaHwTrq_AnaHwTrqT1T2TrimData, (uint8*)&NvMP_Rte_Sa_AnaHwTrq_AnaHwTrqT1T2TrimData,  (uint8*)&Rte_Sa_AnaHwTrq_AnaHwTrqT1T2TrimData, sizeof(Rte_Sa_AnaHwTrq_AnaHwTrqT1T2TrimData), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Sa_CmMtrCurr3Phs_ShCurrCal3Phs, (uint8*)&NvMP_Rte_Sa_CmMtrCurr3Phs_ShCurrCal3Phs,  (uint8*)&Rte_Sa_CmMtrCurr3Phs_ShCurrCal3Phs, sizeof(Rte_Sa_CmMtrCurr3Phs_ShCurrCal3Phs), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Sa_MotMeclPosn1_MotMeclPosn1CoeffTblData, (uint8*)&NvMP_Rte_Sa_MotMeclPosn1_MotMeclPosn1CoeffTblData,  (uint8*)&Rte_Sa_MotMeclPosn1_MotMeclPosn1CoeffTblData, sizeof(Rte_Sa_MotMeclPosn1_MotMeclPosn1CoeffTblData), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Sa_MotMeclPosn2_MotMeclPosn2CoeffTblData, (uint8*)&NvMP_Rte_Sa_MotMeclPosn2_MotMeclPosn2CoeffTblData,  (uint8*)&Rte_Sa_MotMeclPosn2_MotMeclPosn2CoeffTblData, sizeof(Rte_Sa_MotMeclPosn2_MotMeclPosn2CoeffTblData), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Sa_MtrPos3SinCos_MtrPos3_EOLParams, (uint8*)&NvMP_Rte_Sa_MtrPos3SinCos_MtrPos3_EOLParams,  (uint8*)&Rte_Sa_MtrPos3SinCos_MtrPos3_EOLParams, sizeof(Rte_Sa_MtrPos3SinCos_MtrPos3_EOLParams), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Ap_MotPosnCmp_MotPosnCmpMtrPosBackEmf, (uint8*)&NvMP_Rte_Ap_MotPosnCmp_MotPosnCmpMtrPosBackEmf,  (uint8*)&Rte_Ap_MotPosnCmp_MotPosnCmpMtrPosBackEmf, sizeof(Rte_Ap_MotPosnCmp_MotPosnCmpMtrPosBackEmf), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Sa_HwTrqArbn_EOLCh1OffsetTrimData, (uint8*)&NvMP_Rte_Sa_HwTrqArbn_EOLCh1OffsetTrimData,  (uint8*)&Rte_Sa_HwTrqArbn_EOLCh1OffsetTrimData, sizeof(Rte_Sa_HwTrqArbn_EOLCh1OffsetTrimData), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_Sa_HwTrqArbn_EOLCh2OffsetTrimData, (uint8*)&NvMP_Rte_Sa_HwTrqArbn_EOLCh2OffsetTrimData,  (uint8*)&Rte_Sa_HwTrqArbn_EOLCh2OffsetTrimData, sizeof(Rte_Sa_HwTrqArbn_EOLCh2OffsetTrimData), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
	{Rte_NvmBlock_TrqOvlSta_GmLoaIgnCntr, (uint8*)&NvMP_Rte_TrqOvlSta_GmLoaIgnCntr,  (uint8*)&Rte_TrqOvlSta_GmLoaIgnCntr, sizeof(Rte_TrqOvlSta_GmLoaIgnCntr), NVMPROXY_NONE, NVMPROXY_NOTAPPLICABLE, NULL_PTR, NULL_PTR},
};
#define NVMPROXY_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


