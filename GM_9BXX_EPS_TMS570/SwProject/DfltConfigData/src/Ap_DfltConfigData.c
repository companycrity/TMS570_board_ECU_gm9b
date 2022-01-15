/*****************************************************************************
* Copyright 2014 Nexteer
* Nexteer Confidential
*
* Module File Name  : Ap_DfltConfigData.c
* Module Description:
* Product           : Gen II Plus - EA3.0
* Author            : Kevin Smith
*
*
*****************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Apr 12 10:20:00 2012
 * %version:          EA3#18 %
 * %derived_by:       fz9hxm %
 * %date_modified:    Wed Feb 12 14:26:44 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 09/25/15  5        GMN       Updated part number for 01.02.00
 * 09/25/15  6        GMN       Updated part number for 01.02.01
 * 09/20/15  7        GMN       Updated part number for 01.03.00
 * 09/20/15  8        GMN       Updated part number for 01.03.01
 * 10/15/15  10       GMN       Updated part number for 01.05.00
 * 12/03/15  11       GMN       Updated part number for 02.00.00
 * 01/29/16  12       GMN       Updated part number for 03.00.00
 * 02/02/16  13       GMN       EA3#2919: New bootloader 02.00.00                                             5902
 * 02/15/16  14       GMN       EA3#43112: Added motor variant NVM variable                                   4383
 * 02/17/16  15       GMN       EA3#5994: New default values for some services                                6167
 * 08/11/16  16       GMN       Update GM LAN ID
 * 01/15/17  17       CP        Added Nvm_GetSensorData_Cnt_lgc
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_DfltConfigData.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
#include "Cd_NvMProxy.h"
#include "CalConstants.h"
#include "Cd_NvMProxy_Cfg.h"
#include "T1_AppInterface.h"
#include "Rte_Type.h"
#include "NvM.h"

/* Select the release suffix based on the build type*/
#if	defined(ENABLE_UTILIZATION_MONITOR)
	#define D_SUFFIX    "_U"
#elif defined(ENABLE_CPUUSE_METRICS)
	#define D_SUFFIX    "_T"
#elif defined(ENABLE_METRICS)
	#define D_SUFFIX    "_O"
#elif defined(T1_ENABLE)
	#define D_SUFFIX    "_T1"
#elif defined(SWEEPBUILD)
	#define D_SUFFIX    "_SWP1"
#elif( BC_FLTINJECTION_ENABLEFAULTINJECTION == STD_ON )
	#define D_SUFFIX    "_FLT"
#else
	#define D_SUFFIX
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*Current Sw Release Number(from CM Synergy)*/

/* Multiple strings separated by a space are combined at compile time.  So the result of the expression is a single string */
#pragma DATA_SECTION(k_SWRelNum_Cnt_u8,"N_NxtrSWPN");
CONST(uint8, CDD_PARTNUMBER) k_SWRelNum_Cnt_u8[0x20] = D_SWRELNUM_CNT_U08;

/* -----[ SER Defined NvM Data ]------------------------------------------------------------------------------------- */
VAR(uint8, CDD_PARTNUMBER) Nvm_VIN_Cnt_u8[17];
VAR(uint8, CDD_PARTNUMBER) Nvm_SystemName_Cnt_u8[20];
VAR(uint8, CDD_PARTNUMBER) Nvm_CurrentPrevRepairShopCode_Cnt_u8[20];
VAR(uint8, CDD_PARTNUMBER) Nvm_ProgDate_Cnt_u8[4];
VAR(uint8, CDD_PARTNUMBER) Nvm_SystemVerCodeDDI_Cnt_u8[2];
VAR(uint8, CDD_PARTNUMBER) Nvm_CMEC_Cnt_u8;
VAR(uint8, CDD_PARTNUMBER) Nvm_ManfTraceability_Cnt_u8[16];
VAR(uint8, CDD_PARTNUMBER) Nvm_EndModelPN_Cnt_u8[4];
VAR(uint8, CDD_PARTNUMBER) Nvm_EndModelPNAC_Cnt_u8[2];
VAR(uint8, CDD_PARTNUMBER) Nvm_DataUnivNumSysID_Cnt_u8[9];
VAR(uint8, NVM_APPL_DATA) Nvm_BaseModelPartNumber_Cnt_u8[4];
VAR(uint8, NVM_APPL_DATA) Nvm_BaseModelPartNumberAlphaCode_Cnt_u8[2];
VAR(uint8, NVM_APPL_DATA) Nvm_CalProgFlag_Cnt_u8;
VAR(uint8, NVM_APPL_DATA) Nvm_EcuId_Cnt_u8[16];
VAR(uint16, NVM_APPL_DATA) Nvm_AppNbid_Cnt_u16;
VAR(uint16, NVM_APPL_DATA) Nvm_Bcid_Cnt_u16;
VAR(uint8, NVM_APPL_DATA) Nvm_Sbat_Cnt_u8[822];

/* Data selected by CMS service and exported to RTE through CDD interface */
VAR(uint8, NVM_APPL_DATA) Nvm_MotorVariant_Cnt_u8;
VAR(boolean, NVM_APPL_DATA) Nvm_GetSensorData_Cnt_lgc;

#define DFLTCONFIGDATA_START_SEC_VAR_HIDDEN_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
VAR(DfltConfigData_SeedKey_Str, CDD_PARTNUMBER) Nvm_SPSSeed_Cnt_str;
VAR(DfltConfigData_SeedKey_Str, CDD_PARTNUMBER) Nvm_SPSKey_Cnt_str;
VAR(DfltConfigData_SeedKey_Str, CDD_PARTNUMBER) Nvm_CPIDSeed_Cnt_str;
VAR(DfltConfigData_SeedKey_Str, CDD_PARTNUMBER) Nvm_CPIDKey_Cnt_str;
VAR(DfltConfigData_SeedKey_Str, CDD_PARTNUMBER) Nvm_NexteerSeed_Cnt_str;
VAR(DfltConfigData_SeedKey_Str, CDD_PARTNUMBER) Nvm_NexteerKey_Cnt_str;
#define DFLTCONFIGDATA_STOP_SEC_VAR_HIDDEN_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* -----[ Initial Data ]--------------------------------------------------------------------------------------------- */
static CONST(uint16, CDD_PARTNUMBER) T_InitEOLNxtrWIRSelect_Cnt_u16 = 0xA5A2U; /* PRQA S 3218 */

static CONST(uint8, CDD_PARTNUMBER) T_InitCalProgFlag_Cnt_u8 = 0xAAU; /* PRQA S 3218 */

static CONST(uint8, CDD_PARTNUMBER) T_InitVIN_Cnt_u8[17] = { /* PRQA S 3218 */
	0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U
};

static CONST(uint8, CDD_PARTNUMBER) T_InitSystemName_Cnt_u8[20] = { /* PRQA S 3218 */
	0x43U, 0x6FU, 0x6CU, 0x75U, 0x6DU, 0x6EU, 0x20U, 0x45U, 0x50U, 0x53U,
	0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U
};

static CONST(uint8, CDD_PARTNUMBER) T_InitCurrentPrevRepairShopCode_Cnt_u8[20] = { /* PRQA S 3218 */
	0x20U, 0x20U, 0x20U, 0x20U, 0x20U, 0x20U, 0x20U, 0x20U, 0x20U, 0x20U,
	0x20U, 0x20U, 0x20U, 0x20U, 0x20U, 0x20U, 0x20U, 0x20U, 0x20U, 0x20U
};

static CONST(uint8, CDD_PARTNUMBER) T_InitProgDate_Cnt_u8[4] = { /* PRQA S 3218 */
	0x00U, 0x00U, 0x00U, 0x00U
};

static CONST(uint8, CDD_PARTNUMBER) T_InitSystemVerCodeDDI_Cnt_u8[2] = { /* PRQA S 3218 */
	0x15U, 0x01U
};

static CONST(uint8, CDD_PARTNUMBER) T_InitCMEC_Cnt_u8 = 0xFEU; /* PRQA S 3218 */

static CONST(uint8, CDD_PARTNUMBER) T_InitSeed_Cnt_u08[5U] = { /* PRQA S 3218 */
	0x01U, 0x02U, 0x03U, 0x04U, 0x05U
};

static CONST(uint8, CDD_PARTNUMBER) T_InitKey_Cnt_u08[5U] = { /* PRQA S 3218 */
	0xFEU, 0xFDU, 0xFCU, 0xFBU, 0xFAU
};

static CONST(float32, CDD_PARTNUMBER) T_InitTorqueCmdSF_Uls_f32 = 1.0F; /* PRQA S 3218 */

static CONST(uint8, CDD_PARTNUMBER) T_InitNMEC_Cnt_u8 = 0xFEU; /* PRQA S 3218 */

static CONST(uint8, CDD_PARTNUMBER) T_InitECUHwPn_Cnt_u8[12] = {
    '2', '8', '6', '4', '8', '8', '3', '1', '-', '0', '0', '7'
};

static CONST(uint8, CDD_PARTNUMBER) T_InitDataUnivNumSysID_Cnt_u8[9] = { /* PRQA S 3218, 4414 2 */
    '0', '5', '3', '3', '3', '3', '0', '5', '5'
};

static CONST(uint8, CDD_PARTNUMBER) T_InitBaseModelPartNumber_Cnt_u8[4] = { /* PRQA S 3218 */
    0x01U, 0x62U, 0x19U, 0x2AU
};

static CONST(uint8, NVM_APPL_DATA) T_InitBaseModelPartNumberAlphaCode_Cnt_u8[2] = { /* PRQA S 3218, 4414 2 */
    'A', 'B'
};

static CONST(uint8, CDD_PARTNUMBER) T_InitEndModelPN_Cnt_u8[4] = { /* PRQA S 3218 */
	0x01U, 0x62U, 0x19U, 0x28U
};

static CONST(uint8, NVM_APPL_DATA) T_InitEndModelPNAC_Cnt_u8[2] = { /* PRQA S 3218, 4414 2 */
	'A', 'G'
};

/*
 * The ECU_ID is a 16 byte, secure static memory, unsigned string which stores a controller
 * specific unique number. Check DID 0xF3 for more details.
 */
static CONST(uint8, NVM_APPL_DATA) T_InitEcuId_Cnt_u8[16] = { /* PRQA S 3218 */
	0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU,
	0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU
};

/* Motor variant */
static CONST(uint8, NVM_APPL_DATA) T_InitMotorVariant_Cnt_u8 = 0U; /* PRQA S 3218 */

/* -----[ Flash Constant Data ]-------------------------------------------------------------------------------------- */
#pragma DATA_SECTION(T_GMLANID_Cnt_u8, "N_GMLANID");
CONST(uint8, CDD_PARTNUMBER) T_GMLANID_Cnt_u8[12] = {
	0x02U, 0x03U, 0x00U, 0x12U, 0x12U, 0x79U,
	0x03U, 0x03U, 0x00U, 0x12U, 0x12U, 0x79U
};

/* -----[ Processing Functions ]------------------------------------------------------------------------------------- */
FUNC(void, CDD_PARTNUMBER_CODE) DfltConfigData_Init1(void)
{
	VAR(NvM_RequestResultType, AUTOMATIC) BlockStatus = 0U;
	VAR(ManufModeType, AUTOMATIC) NxtrMEC_Uls_T_enum;
	VAR(uint16, AUTOMATIC) i;

	/* Nexteer MEC */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_CMS_NXTRMEC, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		Nvm_NMEC_Cnt_u8 = T_InitNMEC_Cnt_u8;
	}
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_CMS_NXTRMECFLAG, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		Nvm_NMECReachedZero_Cnt_lgc = FALSE;
	}

	EPS_DiagSrvcs_Init();

	/* Read MEC */
	NxtrMEC_Uls_T_enum = NxtrMEC_Uls_G_enum;

	/* The following section are block checks that require the MEC to be set in Manufacturing Mode */
	if (NxtrMEC_Uls_T_enum == ManufacturingMode)
	{
		/* Torque Command Scale Factor */
		NvM_GetErrorStatus((NvM_BlockIdType)Rte_NvmBlock_TrqCmdScl_TorqueCmdSF_Uls_f32, &BlockStatus);
		if (BlockStatus != NVM_REQ_OK)
		{
			*(float32*)NvMP_Rte_TrqCmdScl_TorqueCmdSF_Uls_f32 = T_InitTorqueCmdSF_Uls_f32;
		}

		/* VIN */
		NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_VINDATA, &BlockStatus);
		if (BlockStatus != NVM_REQ_OK)
		{
			for (i = 0U; i < TableSize_m(Nvm_VIN_Cnt_u8); i++)
			{
				Nvm_VIN_Cnt_u8[i] = T_InitVIN_Cnt_u8[i];
			}
		}

		/* Repair Shop Code */
		NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_CURRENT_PREV_REPAIRSHOPCODE, &BlockStatus);
		if (BlockStatus != NVM_REQ_OK)
		{
			for (i = 0U; i < TableSize_m(Nvm_CurrentPrevRepairShopCode_Cnt_u8); i++)
			{
				Nvm_CurrentPrevRepairShopCode_Cnt_u8[i] = T_InitCurrentPrevRepairShopCode_Cnt_u8[i];
			}
		}
		
		/* Programming Date */
		NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_PROGDATE, &BlockStatus);
		if (BlockStatus != NVM_REQ_OK)
		{
			for (i = 0U; i < TableSize_m(Nvm_ProgDate_Cnt_u8); i++)
			{
				Nvm_ProgDate_Cnt_u8[i] = T_InitProgDate_Cnt_u8[i];
			}
		}

		/* Customer MEC */
		NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_CUSTMEC, &BlockStatus);
		if (BlockStatus != NVM_REQ_OK)
		{
			Nvm_CMEC_Cnt_u8 = T_InitCMEC_Cnt_u8;
		}
	}
	else
	{
		/* MEC Validity Check */
		NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_CUSTMEC, &BlockStatus);
		if (BlockStatus != NVM_REQ_OK)
		{
			Nvm_CMEC_Cnt_u8 = 0U;
			NvM_SetRamBlockStatus((NvM_BlockIdType)NVM_BLOCK_SER_CUSTMEC, TRUE);
		}
	}

	/* The following sections are for blocks that do not require MEC checks */

	/* Nexteer WIR Select */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_CMS_NXTRWIRSELECT, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		CDD_EOLNxtrWIRSelect_Cnt_G_u16 = T_InitEOLNxtrWIRSelect_Cnt_u16;
	}

	/* Cal Programmed Flag */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_CALPRGFLAG, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		Nvm_CalProgFlag_Cnt_u8 = T_InitCalProgFlag_Cnt_u8;
	}

	/* DUNS Number */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_DATAUNIVNUMSYSID, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(Nvm_DataUnivNumSysID_Cnt_u8); i++)
		{
			Nvm_DataUnivNumSysID_Cnt_u8[i] = T_InitDataUnivNumSysID_Cnt_u8[i];
		}
	}

	/* System Name */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_SYSTEMNAME, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(Nvm_SystemName_Cnt_u8); i++)
		{
			Nvm_SystemName_Cnt_u8[i] = T_InitSystemName_Cnt_u8[i];
		}
	}

	/* System and Version Code DDI */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_SYSVERSCODEDDI, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(Nvm_SystemVerCodeDDI_Cnt_u8); i++)
		{
			Nvm_SystemVerCodeDDI_Cnt_u8[i] = T_InitSystemVerCodeDDI_Cnt_u8[i];
		}
	}

	/* ECU Hardware Part Number */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_CMS_ECUHWPN, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(Nvm_EcuHwPn_Cnt_u8); i++)
		{
			Nvm_EcuHwPn_Cnt_u8[i] = T_InitECUHwPn_Cnt_u8[i];
		}
	}

	/* Base Model Part Number */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_BASEMODELPN, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(Nvm_BaseModelPartNumber_Cnt_u8); i++)
		{
			Nvm_BaseModelPartNumber_Cnt_u8[i] = T_InitBaseModelPartNumber_Cnt_u8[i];
		}
	}


	/* Base Model Part Number Alpha Code*/
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_BASEMODELPNAC, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(Nvm_BaseModelPartNumberAlphaCode_Cnt_u8); i++)
		{
			Nvm_BaseModelPartNumberAlphaCode_Cnt_u8[i] = T_InitBaseModelPartNumberAlphaCode_Cnt_u8[i];
		}
	}

	/* End Model Part Number */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_ENDMODELPN, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(Nvm_EndModelPN_Cnt_u8); i++)
		{
			Nvm_EndModelPN_Cnt_u8[i] = T_InitEndModelPN_Cnt_u8[i];
		}
	}

	/* End Model Part Number Alpha Code*/
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_ENDMODELPNAC, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(Nvm_EndModelPNAC_Cnt_u8); i++)
		{
			Nvm_EndModelPNAC_Cnt_u8[i] = T_InitEndModelPNAC_Cnt_u8[i];
		}
	}

	/* Nexteer Storage Array */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_DIAGMGR_NTCSTRG, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(NTCStrgArray_Cnt_str); i++)
		{
			NTCStrgArray_Cnt_str[i].NTC = 0U;
			NTCStrgArray_Cnt_str[i].Status = 0U;
			NTCStrgArray_Cnt_str[i].AgingCounter = 0xFFU;
		}
	}

	/* Security: SPS Seed */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_SEED_SPS, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(T_InitSeed_Cnt_u08); i++)
		{
			Nvm_SPSSeed_Cnt_str.Data.Seed[i] = T_InitSeed_Cnt_u08[i];
		}
		Nvm_SPSSeed_Cnt_str.ProgramFlag = D_SEEDKEYNOTPROGRAMMED_CNT_U08;
	}

	/* Security: SPS Key */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_KEY_SPS, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(T_InitKey_Cnt_u08); i++)
		{
			Nvm_SPSKey_Cnt_str.Data.Key[i] = T_InitKey_Cnt_u08[i];
		}
		Nvm_SPSKey_Cnt_str.ProgramFlag = D_SEEDKEYNOTPROGRAMMED_CNT_U08;
	}

	/* Security: CPID Seed */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_SEED_CPID, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(T_InitSeed_Cnt_u08); i++)
		{
			Nvm_CPIDSeed_Cnt_str.Data.Seed[i] = T_InitSeed_Cnt_u08[i];
		}
		Nvm_CPIDSeed_Cnt_str.ProgramFlag = D_SEEDKEYNOTPROGRAMMED_CNT_U08;
	}

	/* Security: CPID Key */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_KEY_CPID, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(T_InitKey_Cnt_u08); i++)
		{
			Nvm_CPIDKey_Cnt_str.Data.Key[i] = T_InitKey_Cnt_u08[i];
		}
		Nvm_CPIDKey_Cnt_str.ProgramFlag = D_SEEDKEYNOTPROGRAMMED_CNT_U08;
	}

	/* Security: Nexteer Seed */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_SEED_NEXTEER, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(T_InitSeed_Cnt_u08); i++)
		{
			Nvm_NexteerSeed_Cnt_str.Data.Seed[i] = T_InitSeed_Cnt_u08[i];
		}
		Nvm_NexteerSeed_Cnt_str.ProgramFlag = D_SEEDKEYNOTPROGRAMMED_CNT_U08;
	}

	/* Security: Nexteer Key */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_KEY_NEXTEER, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(T_InitKey_Cnt_u08); i++)
		{
			Nvm_NexteerKey_Cnt_str.Data.Key[i] = T_InitKey_Cnt_u08[i];
		}
		Nvm_NexteerKey_Cnt_str.ProgramFlag = D_SEEDKEYNOTPROGRAMMED_CNT_U08;
	}

	/* ECU ID */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_ECU_ID, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < TableSize_m(T_InitEcuId_Cnt_u8); i++)
		{
			Nvm_EcuId_Cnt_u8[i] = T_InitEcuId_Cnt_u8[i];
		}
	}

	/* SBAT */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_SER_SBAT, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		for (i = 0U; i < D_DFTCFGSBAT_CNT_U16; i++)
		{
			Nvm_Sbat_Cnt_u8[i] = 0xFFU;
		}
	}

	/* Motor variant */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_CMS_MOTORVARIANT, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		Nvm_MotorVariant_Cnt_u8 = T_InitMotorVariant_Cnt_u8;
	}
	
	/* Get sensor data */
	NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_CMS_GETSENSORDATA, &BlockStatus);
	if (BlockStatus != NVM_REQ_OK)
	{
		Nvm_GetSensorData_Cnt_lgc = FALSE;
	}

}
