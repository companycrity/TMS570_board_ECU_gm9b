
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Cd_NvMProxy_Cfg.h
* Module Description: Configuration of the Cd_NvMProxy BSW
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
 * Version Control:
 * Date Created:      Tue Feb  7 11:23:49 2012
 * %version:          1 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Wed Nov 20 08:22:28 2013 % 
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 02/07/12   1        JJW       Initial creation
 * 10/17/12   2        JJW       Generated output file
 * 05/30/13   3        JJW       Removed unsuported config feature, added multi-block support
 * 11/21/13   4        LWW       Added Redundant and CRC checking options
 */

#ifndef NVMPROXY_CFG_H
#define NVMPROXY_CFG_H


/* Include defs for data block types */
#ifndef _RTE_TYPE_H
	#define RTE_MICROSAR_PIM_EXPORT /* Define the Rte constant to allow exporting of PIM types to this CDD */
	#include "Rte_Type.h"
#endif
#include "NvM.h"
#include "Ap_DiagMgr.h"
#include "Ap_StaMd_Cfg.h"

#define D_CRC16SIZE_CNT_U16		2


typedef P2CONST(uint8, AUTOMATIC, AUTOMATIC) NvMP_FailActionDataType;
typedef P2FUNC(void, AUTOMATIC, NvMP_FailActFuncType)(void);

typedef enum {
	NVMPROXY_NONE = 0x00,
	NVMPROXY_CRC16 = 0x01,
	NVMPROXY_REDUNDANT = 0x02,
	NVMPROXY_ZERODATA = 0x03
}NvMProxy_InitHandling;

typedef enum {
	NVMPROXY_NOTAPPLICABLE = 0x00,
	NVMPROXY_NTC_0A = 0x01,
	NVMPROXY_NTC_08_ROMDEF = 0x02,
	NVMPROXY_NTC_08_NOTIFFUNC = 0x03,
	NVMPROXY_NTC_07_ROMDEF = 0x04,
	NVMPROXY_NTC_07_NOTIFFUNC = 0x05,
	NVMPROXY_NTC_06_ROMDEF = 0x06,
	NVMPROXY_NTC_06_NOTIFFUNC = 0x07
}NvMProxy_FailResponse;

typedef struct {
	CONST(NvM_BlockIdType, AUTOMATIC) NvMBlock;
	CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) unsecurePtr;
	CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) securePtr;
	CONST(uint16, AUTOMATIC) secureSize;
	CONST(NvMProxy_InitHandling, AUTOMTIC) initHandling;
	CONST(NvMProxy_FailResponse, AUTOMTIC) failResponse;
	CONST(NvMP_FailActionDataType, AUTOMATIC) failActData;
	CONST(NvMP_FailActFuncType, AUTOMATIC) failActFunc;
} NvMProxyCfg_Type;

#define D_NUMPRXYBLOCKS_CNT_U16    		24u
#define NVMPROXY_REPORTERRORSTATUS		NxtrDiagMgr10_ReportNTCStatus

extern CONST(NvMProxyCfg_Type, AUTOMATIC) NvMProxyCfg[D_NUMPRXYBLOCKS_CNT_U16];

/* Only provide externs if PIM Export is defined (won't compile otherwise) */
#ifdef RTE_MICROSAR_PIM_EXPORT
extern VAR(uint8, AUTOMATIC) NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32[sizeof(Rte_TrqCmdScl_TorqueCmdSF_Uls_f32)];

/*extern VAR(uint8, AUTOMATIC) NvMP_TypeHData_Cnt_u08[];Nexteer Patch for generating NvM for TypeH */
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_TrqCanc_CogTrqCal[sizeof(Rte_Ap_TrqCanc_CogTrqCal)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_CurrParamComp_EOLNomMtrParam[sizeof(Rte_CurrParamComp_EOLNomMtrParam)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_DigColPs_DigColPsEOL[sizeof(Rte_DigColPs_DigColPsEOL)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_TrqCanc_CogTrqRplComp[sizeof(Rte_Ap_TrqCanc_CogTrqRplComp)];
extern VAR(uint32, AUTOMATIC) CloseCheck_Cnt_u32; /* Nexteer Patch to generator to support variables which are not extern'd via a header file */
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_TSMit_TSMitDisableEOL[sizeof(Rte_Ap_TSMit_TSMitDisableEOL)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_TSMit_TSMitGainLrn[sizeof(Rte_Ap_TSMit_TSMitGainLrn)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_VehDyn_MotPosReset[sizeof(Rte_VehDyn_MotPosReset)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_HwTqCorrln_HwTqCor_Ch1CMCLPFSv_HwNm_f32[sizeof(Rte_Sa_HwTqCorrln_HwTqCor_Ch1CMCLPFSv_HwNm_f32)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_HwTqCorrln_HwTqCor_Ch2CMCLPFSv_HwNm_f32[sizeof(Rte_Sa_HwTqCorrln_HwTqCor_Ch2CMCLPFSv_HwNm_f32)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str[sizeof(Rte_Ap_CtrlPolarityBrshlss_Polarity_Cnt_Str)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_AnaHwTrq_AnaHwTrqScaleData[sizeof(Rte_Sa_AnaHwTrq_AnaHwTrqScaleData)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_AnaHwTrq_AnaHwTrqT1T2TrimData[sizeof(Rte_Sa_AnaHwTrq_AnaHwTrqT1T2TrimData)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_CmMtrCurr3Phs_ShCurrCal3Phs[sizeof(Rte_Sa_CmMtrCurr3Phs_ShCurrCal3Phs)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_MotMeclPosn1_MotMeclPosn1CoeffTblData[sizeof(Rte_Sa_MotMeclPosn1_MotMeclPosn1CoeffTblData)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_MotMeclPosn2_MotMeclPosn2CoeffTblData[sizeof(Rte_Sa_MotMeclPosn2_MotMeclPosn2CoeffTblData)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_MtrPos3SinCos_MtrPos3_EOLParams[sizeof(Rte_Sa_MtrPos3SinCos_MtrPos3_EOLParams)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Ap_MotPosnCmp_MotPosnCmpMtrPosBackEmf[sizeof(Rte_Ap_MotPosnCmp_MotPosnCmpMtrPosBackEmf)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_HwTrqArbn_EOLCh1OffsetTrimData[sizeof(Rte_Sa_HwTrqArbn_EOLCh1OffsetTrimData)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_Sa_HwTrqArbn_EOLCh2OffsetTrimData[sizeof(Rte_Sa_HwTrqArbn_EOLCh2OffsetTrimData)];
extern VAR(uint8, AUTOMATIC) NvMP_Rte_TrqOvlSta_GmLoaIgnCntr[sizeof(Rte_TrqOvlSta_GmLoaIgnCntr)];
#endif

#endif
