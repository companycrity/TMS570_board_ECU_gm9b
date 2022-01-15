/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EPS_DiagSrvcs_CommonFunc.h file
* Module Description: Common Manufacturing Program Interface for XCP and ISO services
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
* Notes:
* This file contains configurations that are shared between ISO and XCP services.
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          EA3#29 %
 * %derived_by:       fz9hxm %
 * %date_modified:    Fri Jan 24 16:14:39 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 02/02/16  2        GMN       Moving Software Release Number to header file
 * 02/15/16  3        GMN       EA3#43112: Added motor variant NVM variable                                   4383
 * 02/23/16  4        GMN       Part number update for 03.00.02
 * 02/24/16  5        GMN       Part number update for 03.00.03
 * 03/16/16  6        GMN       Part number update for 03.00.04
 * 03/17/16  7        GMN       Part number update for 04.00.00
 * 04/04/16  8        GMN       Part number update for 04.01.00
 * 04/11/16  9        GMN       Part number update for 04.02.00
 * 04/22/16  10       GMN       Part number update for 04.03.00
 * 04/22/16  11       GMN       Part number update for 04.03.01
 * 04/25/16  12       GMN       Part number update for 05.00.00
 * 05/10/16  14       GMN       Part number update for 05.01.00
 * 05/20/16  15       GMN       Part number update for 05.01.02
 * 05/23/16  16       GMN       Part number update for 06.00.00
 * 06/23/16  17       GMN       Part number update for 06.01.00
 * 08/02/16  18       GMN       Part number update for 06.02.00
 * 08/25/16  19       GMN       Part number update for 06.03.00
 * 09/05/16  20       GMN       Part number update for 06.03.01
 * 09/07/16  21       CP        Part number update for 06.03.02
 * 09/13/16  22       GMN       Part number update for 06.03.03
 * 10/28/16  23       CP        Part number update for 07.00.00
 * 11/23/16  24       CP        Part number update for 07.01.00
 * 12/20/16  25       CP        Part number update for 07.01.01
 * 01/15/17  26       CP        Part number update for 08.00.00
 * 03/21/17  27       CP        Part number update for 09.00.00
 * 04/05/17  28       CP        Part number update for 09.00.01
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>		                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Rte_Type.h"
#include "GlobalMacro.h"
#include "CDD_Data.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>   		      		    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#ifndef RTE_AP_DFLTCONFIGDATA_H
#define RTE_AP_DFLTCONFIGDATA_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>   		  	    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>	                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#if defined(ENABLE_DATEONSWVERSION)
#define D_DATE __DATE__ __TIME__
#else
#define D_DATE
#endif

/* Software release number */
#define D_SWRELNUM_CNT_U08 "9Bxx_09.00.01" D_SUFFIX D_DATE

#define D_SEEDKEYNOTPROGRAMMED_CNT_U08  0x00U
#define D_SEEDKEYPROGRAMMED_CNT_U08     0xAAU

typedef struct {
	union {
		VAR(uint8, AUTOMATIC) Seed[5U];
		VAR(uint8, AUTOMATIC) Key[5U];
	} Data;
	VAR(uint8, AUTOMATIC) ProgramFlag;
} DfltConfigData_SeedKey_Str;

/* RAM references */
extern VAR(UInt16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Polarity_k_SystemPolarity_Cnt_b16;
extern VAR(uint16, AUTOMATIC) SrlComWIRFltStatus_Cnt_u16;
extern VAR(uint16, CDD_VAR_NOINIT) CDD_EOLNxtrWIRSelect_Cnt_G_u16;
extern VAR(EOLNomMtrParamType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_ParamComp_EOLNomMtrParam;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32[4u];
extern VAR(Float, RTE_VAR_INIT) Rte_DigColPs_I2CHwAbsPos_HwDeg_f32;
extern VAR(uint8, EPSDIAGSRVCS_VAR) NxtrMEC_Cnt_G_u8;
extern VAR(Float, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Return_EOLReturnRange;
extern VAR(uint8, CDD_PARTNUMBER) Nvm_VIN_Cnt_u8[17];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_SystemName_Cnt_u8[20];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_CurrentPrevRepairShopCode_Cnt_u8[20];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_ProgDate_Cnt_u8[4];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_SystemVerCodeDDI_Cnt_u8[2];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_CMEC_Cnt_u8;
extern VAR(uint8, CDD_PARTNUMBER) Nvm_ManfTraceability_Cnt_u8[16];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_EndModelPN_Cnt_u8[4];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_EndModelPNAC_Cnt_u8[2];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_DataUnivNumSysID_Cnt_u8[9];
extern VAR(uint8, NVM_APPL_DATA) Nvm_MotorVariant_Cnt_u8;
extern VAR(boolean, NVM_APPL_DATA) Nvm_GetSensorData_Cnt_lgc;

/*
 * The ECU_ID is a 16 byte, secure static memory, unsigned string which stores a controller
 * specific unique number. Check DID 0xF3 for more details.
 */
extern VAR(uint8, NVM_APPL_DATA) Nvm_EcuId_Cnt_u8[16];

/* ECU ID size */
#define D_DFTCFGECUID_CNT_U8 (sizeof(Nvm_EcuId_Cnt_u8)/sizeof(Nvm_EcuId_Cnt_u8[0]))

extern VAR(uint16, NVM_APPL_DATA) Nvm_AppNbid_Cnt_u16;
extern VAR(uint16, NVM_APPL_DATA) Nvm_Bcid_Cnt_u16;

/*
 * Signature Bypass Authorization Ticket (SBAT).
 * Check DID 0xF4 for more details.
 */
extern VAR(uint8, NVM_APPL_DATA) Nvm_Sbat_Cnt_u8[822];

/* SBAT size */
#define D_DFTCFGSBAT_CNT_U16 (sizeof(Nvm_Sbat_Cnt_u8)/sizeof(Nvm_Sbat_Cnt_u8[0]))

extern VAR(DfltConfigData_SeedKey_Str, CDD_PARTNUMBER) Nvm_SPSSeed_Cnt_str;
extern VAR(DfltConfigData_SeedKey_Str, CDD_PARTNUMBER) Nvm_SPSKey_Cnt_str;
extern VAR(DfltConfigData_SeedKey_Str, CDD_PARTNUMBER) Nvm_CPIDSeed_Cnt_str;
extern VAR(DfltConfigData_SeedKey_Str, CDD_PARTNUMBER) Nvm_CPIDKey_Cnt_str;
extern VAR(DfltConfigData_SeedKey_Str, CDD_PARTNUMBER) Nvm_NexteerSeed_Cnt_str;
extern VAR(DfltConfigData_SeedKey_Str, CDD_PARTNUMBER) Nvm_NexteerKey_Cnt_str;

extern VAR(uint8, NVM_APPL_DATA) Nvm_BaseModelPartNumber_Cnt_u8[4];
extern VAR(uint8, NVM_APPL_DATA) Nvm_BaseModelPartNumberAlphaCode_Cnt_u8[2];
extern VAR(uint8, NVM_APPL_DATA) Nvm_CalProgFlag_Cnt_u8;

extern VAR(uint8, CDD_PARTNUMBER) Nvm_NMEC_Cnt_u8;
extern VAR(boolean, NVM_APPL_DATA) Nvm_NMECReachedZero_Cnt_lgc;
extern VAR(uint8, CDD_PARTNUMBER) Nvm_EcuSrlNum_Cnt_u8[4];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_EpsSrlNum_Cnt_u8[4];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_EcuHwPn_Cnt_u8[12];
extern VAR(uint8, CDD_PARTNUMBER) Nvm_NxtrManfScrpd_Cnt_u8[64];
extern VAR(uint16, CDD_PARTNUMBER) Nvm_IgnCntr_Cnt_u16;

extern CONST(uint8, CDD_PARTNUMBER) T_GMLANID_Cnt_u8[12];
extern CONST(uint8, CDD_PARTNUMBER) T_SwModID1andAC_Cnt_u8[6];

extern CONST(uint8, CDD_PARTNUMBER) k_SWRelNum_Cnt_u8[0x20];

extern FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_Init1(void);

#endif /* RTE_AP_DFLTCONFIGDATA_H */
