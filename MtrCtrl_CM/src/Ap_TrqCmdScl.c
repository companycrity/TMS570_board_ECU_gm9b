/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_TrqCmdScl.c
 *     Workspace:  C:/_Synergy_Projects/Working/ses_dev_ea3/MtrCtrl_CM/autosar
 *     SW-C Type:  Ap_TrqCmdScl
 *  Generated at:  Tue Dec 20 11:26:06 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_TrqCmdScl>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
/*****************************************************************************
* Copyright 2017,2012 Nexteer 
* Nexteer Confidential
*
* Module File Name  : Ap_QuadDet.c
* Module Description: Determine the motor quadrant using instantaneous torque sign and calculated motor direction
* Project           : CBD
* Author            : Selva Sengottaiyan
*****************************************************************************
* Version Control:
* %version:          EA3#7 %
* %derived_by:       nz2554 %
*----------------------------------------------------------------------------------------------------------------------
*   Date       Rev      Author                    Change Description                                            SCR #
* ---------  -------  ----------  -----------------------------------------------------------------------    ----------
* 11/02/11    1        VK         Initial template for the component & changes as per SF-99 Version 002       4705
*                                 Motor Control (Torque Command EOL Scale sub function)
* 12/02/11    1.1      VK         Compiler error fixes                                                        4705
* 09/26/12    3        Selva      Checkpoints corrected                                                       6252
* 10/26/12    4        Selva      Integration in MtrCtrl_VM (Refer FDD 06B Ver 4)
*                                 QAC suppression & MISRA deviation comments, Alignment fixes
* 11/20/12    5        Selva      Integration with MtrlCtrl_CM
* 02/06/13    6        Selva      Added void to return function, QAC
* 01/03/17    7        SR         Regenerated file and corrected for:                                         EA3#13142
*                                 QAC suppression & MISRA deviation comments, Alignment fixes
******************************************************************************/

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
    DataPtr Type to be used by WriteBlock, ReadBlock and RestoreBlockDefaults operations. This type is used for all NVRAM blocks

 *********************************************************************************************************************/

#include "Rte_Ap_TrqCmdScl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /*--------------
  * File Includes
  */
 #include "CalConstants.h"
 #include "GlobalMacro.h"
 #include "Ap_TrqCmdScl_Cfg.h"

 /*-------------------------
  * MISRA Deviation Comments
  */

  /* MISRA-C:2004 Rule 19.1 : #include statements in a file should only be preceded by other preprocessor directives or comments.*
   * Rationale: #include statements needed for AutoSAR compliance. */

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
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
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
 * NvM_DestPtr: Array with 65535 element(s) of type UInt8
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
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_2PI_ULS_F32 = 6.2831853071796
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_PI_ULS_F32 = 3.1415926535898
 * Float: D_VECUMIN_VOLTS_F32 = 5
 * Float: D_ZERO_ULS_F32 = 0
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt8: D_QUADRANT1_CNT_U8 = 1u
 * UInt8: D_QUADRANT2_CNT_U8 = 2u
 * UInt8: D_QUADRANT3_CNT_U8 = 3u
 * UInt8: D_QUADRANT4_CNT_U8 = 4u
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
 *   Float *Rte_Pim_TorqueCmdSF_Uls_f32(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_TRQCMDSCL_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqCmdScl_Per1
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
 *   Float Rte_IRead_TrqCmdScl_Per1_MRFMtrTrqCmd_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_TrqCmdScl_Per1_MRFMtrTrqCmdScl_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_TrqCmdScl_Per1_MRFMtrTrqCmdScl_MtrNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqCmdScl_Per1
 *********************************************************************************************************************/

    VAR(float32, AUTOMATIC) MRFMtrTrqCmd_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) MRFMtrTrqCmdScl_MtrNm_T_f32;
    VAR(float32, AUTOMATIC) TorqueCmdSF_Uls_T_f32;

    /* Configurable Start of Runnable Checkpoint */
    Rte_Call_TrqCmdScl_Per1_CP0_CheckpointReached();

    /* Torque Command EOL Function */
    MRFMtrTrqCmd_MtrNm_T_f32 = Rte_IRead_TrqCmdScl_Per1_MRFMtrTrqCmd_MtrNm_f32();

    TorqueCmdSF_Uls_T_f32 = *Rte_Pim_TorqueCmdSF_Uls_f32();

    TorqueCmdSF_Uls_T_f32 = Limit_m(TorqueCmdSF_Uls_T_f32, k_MinTrqCmdScl_Uls_f32, k_MaxTrqCmdScl_Uls_f32);

    MRFMtrTrqCmdScl_MtrNm_T_f32 = MRFMtrTrqCmd_MtrNm_T_f32 * TorqueCmdSF_Uls_T_f32;

    Rte_IWrite_TrqCmdScl_Per1_MRFMtrTrqCmdScl_MtrNm_f32(MRFMtrTrqCmdScl_MtrNm_T_f32);

    /* Configurable End of Runnable Checkpoint */
    Rte_Call_TrqCmdScl_Per1_CP1_CheckpointReached();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqCmdScl_SCom_Get
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <TrqCmdScl_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TrqCmdScl_SCom_Get(Float *Par_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Get(P2VAR(Float, AUTOMATIC, RTE_AP_TRQCMDSCL_APPL_VAR) Par_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqCmdScl_SCom_Get
 *********************************************************************************************************************/

    *Par_f32 = *Rte_Pim_TorqueCmdSF_Uls_f32();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqCmdScl_SCom_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <TrqCmdScl_SCom>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_TrqCmdScl_WriteBlock(const UInt8 *DstPtr)
#else
 *   Std_ReturnType Rte_Call_TrqCmdScl_WriteBlock(const NvM_DestPtr *DstPtr)
#endif
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void TrqCmdScl_SCom_Set(Float Par_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_TRQCMDSCL_APPL_CODE) TrqCmdScl_SCom_Set(Float Par_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: TrqCmdScl_SCom_Set
 *********************************************************************************************************************/

    *Rte_Pim_TorqueCmdSF_Uls_f32() = Par_f32;
    (void)Rte_Call_TrqCmdScl_WriteBlock(NULL_PTR);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_TRQCMDSCL_APPL_CODE
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
