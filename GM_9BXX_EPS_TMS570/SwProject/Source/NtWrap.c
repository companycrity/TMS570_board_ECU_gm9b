/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  NtWrap.c
 *     Workspace:  C:/_synergy/9BXX_CZ8L9T/GM_9BXX_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  NtWrap
 *  Generated at:  Fri Apr  1 09:37:59 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <NtWrap>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Jul  8 13:53:28 2013
 * %version:          EA3#7 %
 * %date_modified:    Mon Sep 30 12:42:52 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 06/03/15  2        GMN       Add trusted init function for StaMd
 * 09/30/15  5        GMN       Added trusted function to AnaHwTrq and HwTrqArbn
 * 02/24/16  6        GMN       EA3#2817: Update ES-60A / ES-61A MotMeclPosn 1/2
 * 04/01/16  7        GMN       EA3#5967: Update CF-09 TrqOvlSta                                              EA3#7182
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Constants:
 ==========
  D_RACKTOVEHCNTRUNLEARNED_CNT_U16
    This constant has been added until anomaly 3744 can be corrected. Once the anomaly is corrected, this can be removed from StdDef. This should only be used by BMW as of 12Sep12.


 Runnable Entities:
 ==================
  NtWrap_Per1
    Dummy function to map this component onto an application for generation.

 *********************************************************************************************************************/

#include "Rte_NtWrap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define NTWRAP_C /* Expose SWC specific definitions in header */
#include "NtWrap.h"

#include "Cd_NvMProxy.h"
#include "PwmCdd.h"
#include "WdgM.h"
#include "WdgM_PBcfg.h"
#include "Wdg.h"
#include "Wdg_TMS570LS3x_Lcfg.h"
#include "Os.h"
#include "trustfct.h"
#include "Det.h"
#include "Adc.h"
#include "Dma.h"
#include "Ap_StaMd.h"

/* RTE Rte_Ap_StaMd.h prototypes */
extern FUNC(void, RTE_AP_STAMD_APPL_CODE) StaMd_Init1(void);

extern void ApXcpWriteCommon(void);

typedef union {
	Std_ReturnType Std_Return;
} RetBuf_Type;

/* This design provides a separate return buffer for each non-trusted function interface. This provides the ability to call non-trusted
 * functions from different preemtion levels without concern for return buffer consistency. However, it does not all re-entrant calling
 * for the same function, since both invocations will be accessing the same buffer.
 * The Os assigned non-trusted function index/id is used to index into the NtWrap_RetBuf[], therefore to have the minimum required size
 * for the return buffer, the functions with non-void return values shoulD be grouped together and starting at id 0.  Note that this
 * configuration grouping may not always be possible depending on the Os config, thus the array may contain some unused indexes.
*/
#define D_NUMRETURNBUFF_CNT_U08 50u

#define NTWRAP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(RetBuf_Type, AUTOMATIC) NtWrap_RetBuf[D_NUMRETURNBUFF_CNT_U08];
#define NTWRAP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/*
 * Context wrap for GeneratePosTraj_SCom_SetInputParam function call.
 */
typedef struct {
	Float arg1_f32;
	Float arg2_f32;
	Float arg3_f32;
} GeneratePosTraj_SetInputParam_Type;

/*
 * Context wrap for EOLNomMtrParam_Set function call.
 */
typedef struct {
	Float arg1_f32;
	Float arg2_f32;
} EOLNomMtrParam_Set_Type;

/*
 * Context wrap for AssistLmtFunc_Scom_ManualTrqCmd function call.
 */
typedef struct {
	Boolean arg1_lgc;
	Float arg2_f32;
} AssistLmtFunc_ManualTrqCmd_Type;

/*
 * Context wrap for TrqCanc_SetCogTrqCal_Type function call.
 */
typedef struct {
	const CoggingCancTrq* arg1_ptr;
	UInt16 arg2_u16;
} TrqCanc_SetCogTrqCal_Type;

/*
 * Context wrap for MtrPos3SinCos_Scom_WriteEOLMtrCals function call.
 */
typedef struct {
	const MtrPos3SinCos_EOLwithCRC* arg1_ptr;
	UInt8 *arg2_ptr;
} MtrPos3SinCos_WriteEOLMtrCals_Type;

/*
 * Context wrap for MotPosnCmp_Scom_MotPosnCmpBackEmfWr function call.
 */
typedef struct {
	const MotPosnBackEmfData* arg1_ptr;
	UInt8 *arg2_ptr;
} MotPosnCmp_MotPosnCmpBackEmfWr_Type;

/*
 * Context wrap for HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim function call.
 */
typedef struct {
	const EOLChOffsetTrim_Datatype *arg1_ptr;
	UInt8 arg2_u08;
} HwTrqArbn_WriteHwTrqArbOffsetTrim_Type;

/*
 * Context wrap for MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl and MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl
 * function calls.
 */
typedef struct {
	const DT_MotMeclPosnCoeffTbl_f32 *coeffTbl_ptr;
	UInt16 crc_u16;
	UInt16 seed_u16;
	UInt8 *resp_ptr;
} MotMeclPosn_WriteMotMeclPosnCoeffTbl_Type;

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
 * Enumeration Types:
 * ==================
 * MtrCurrOffProcessFlag: Enumeration of integer in interval [0...4] with enumerators
 *   CURROFF_INIT (0U)
 *   CURROFF_PROCESSING (1U)
 *   CURROFF_PASS (2U)
 *   CURROFF_FAIL (3U)
 *
 * Array Types:
 * ============
 * CoggingCancTrq: Array with 512 element(s) of type UInt16
 * DT_MotMeclPosnCoeffTbl_f32: Array with 26 element(s) of type Float
 * MotPosnBackEmfData: Array with 2 element(s) of type UInt16
 * MtrPos3SinCos_EOLwithCRC: Array with 6 element(s) of type UInt16
 *
 * Record Types:
 * =============
 * AnaHwTrqScale_Datatype: Record with elements
 *   HwTrqScale_VoltsPerDeg_f32 of type Float
 *   HwTrqScalePerf_Cnt_lgc of type Boolean
 * AnaHwTrqTrim_Datatype: Record with elements
 *   T1Trim_Volts_f32 of type Float
 *   T2Trim_Volts_f32 of type Float
 *   HwTrqTrimPerf_Cnt_lgc of type Boolean
 * EOLChOffsetTrim_Datatype: Record with elements
 *   HwTqArb_EOLChOffsetTrim_HwNm_f32 of type Float
 *   HwTqArb_EOLChOffsetTrimPerf_Cnt_lgc of type Boolean
 * PhaseCurrCal3Phs_DataType: Record with elements
 *   EOLMtrCurrVcalCmd_VoltCnt_f32 of type Float
 *   EOLMtrCurrBOffsetLo_Volt_f32 of type Float
 *   EOLPhscurrBGain_AmppVolt_f32 of type Float
 *   EOLPhscurrCGain_AmppVolt_f32 of type Float
 *   EOLMtrCurrCOffsetLo_Volt_f32 of type Float
 *   EOLMtrCurrBOffsetDiff_Volt_f32 of type Float
 *   EOLMtrCurrCOffsetDiff_Volt_f32 of type Float
 *   EOLMtrCurrAOffsetLo_Volt_f32 of type Float
 *   EOLPhscurrAGain_AmppVolt_f32 of type Float
 *   EOLMtrCurrAOffsetDiff_Volt_f32 of type Float
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
 * Float: D_100MS_SEC_F32 = 0.1F
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082F
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_2PI_ULS_F32 = 6.2831853071796F
 * Float: D_CCWEOTINIT_HWDEG_F32 = -360.0F
 * Float: D_CWEOTINIT_HWDEG_F32 = 360.0F
 * Float: D_MSECPERSEC_ULS_F32 = 1000.0F
 * Float: D_MTRRAMPRATEFALL_MTRNMPS_F32 = -4400.0F
 * Float: D_MTRRAMPRATERISE_MTRNMPS_F32 = 4400.0F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199F
 * Float: D_PI_ULS_F32 = 3.1415926535898F
 * Float: D_RADPERREV_ULS_F32 = 6.28318530718F
 * Float: D_TRQOSCFREQINIT_F32 = 50.0F
 * Float: D_TRQOSCFREQINIT_HZ_F32 = 50.0F
 * Float: D_TRQOVLFREQINIT_HZ_F32 = 3.0F
 * Float: D_VECUMIN_VOLTS_F32 = 5.0F
 * Float: D_VEHWHLBASEINIT_MM_F32 = 3000.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_NEGONE_CNT_S16 = -1
 * SInt16: D_ONE_CNT_S16 = 1
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt32: D_ONE_CNT_S32 = 1
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_CMPVEHLATAINIT_CNT_U16 = 1022U
 * UInt16: D_FIFTEEN_CNT_U16 = 15U
 * UInt16: D_ONE_CNT_U16 = 1U
 * UInt16: D_RACKTOVEHCNTRUNLEARNED_CNT_U16 = 4095U
 * UInt16: D_SEVEN_CNT_U16 = 7U
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ONE_CNT_U32 = 1U
 * UInt32: D_ZERO_CNT_U32 = 0U
 * UInt8: D_FOUR_CNT_U08 = 4U
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3U
 * UInt8: D_ONE_CNT_U8 = 1U
 * UInt8: D_QUADRANT1_CNT_U8 = 1U
 * UInt8: D_QUADRANT2_CNT_U8 = 2U
 * UInt8: D_QUADRANT3_CNT_U8 = 3U
 * UInt8: D_QUADRANT4_CNT_U8 = 4U
 * UInt8: D_THREE_CNT_U08 = 3U
 * UInt8: D_TWO_CNT_U08 = 2U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_NTWRAP_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrAnaHwTrqScaleTrim> of PortPrototype <AnaHwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
	return(NtWrap_RetBuf[NtWrapS_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_SCom_ClrT1T2OffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrT1T2OffsetTrim> of PortPrototype <AnaHwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AnaHwTrq_SCom_ClrT1T2OffsetTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_AnaHwTrq_SCom_ClrT1T2OffsetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_ClrT1T2OffsetTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AnaHwTrq_SCom_ClrT1T2OffsetTrim (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_AnaHwTrq_SCom_ClrT1T2OffsetTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
	return(NtWrap_RetBuf[NtWrapS_AnaHwTrq_SCom_ClrT1T2OffsetTrim].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_SCom_SetAnaHwTrqScaleTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetAnaHwTrqScaleTrim> of PortPrototype <AnaHwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim(Float ScaleValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim(Float ScaleValue)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim(Float ScaleValue)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim, (NonTrustedFunctionParameterRefType)&ScaleValue);
	return(NtWrap_RetBuf[NtWrapS_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_SCom_SetT1T2OffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetT1T2OffsetTrim> of PortPrototype <AnaHwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AnaHwTrq_SCom_SetT1T2OffsetTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_AnaHwTrq_SCom_SetT1T2OffsetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_SetT1T2OffsetTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AnaHwTrq_SCom_SetT1T2OffsetTrim (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_AnaHwTrq_SCom_SetT1T2OffsetTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
	return(NtWrap_RetBuf[NtWrapS_AnaHwTrq_SCom_SetT1T2OffsetTrim].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AnaHwTrq_SCom_WriteT1T2OffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteT1T2OffsetTrim> of PortPrototype <AnaHwTrq_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AnaHwTrq_SCom_WriteT1T2OffsetTrim(const AnaHwTrqTrim_Datatype *HwTrqTrimDataPtr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_AnaHwTrq_SCom_WriteT1T2OffsetTrim(const AnaHwTrqTrim_Datatype *HwTrqTrimDataPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AnaHwTrq_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AnaHwTrq_SCom_WriteT1T2OffsetTrim(P2CONST(AnaHwTrqTrim_Datatype, AUTOMATIC, RTE_NTWRAP_APPL_DATA) HwTrqTrimDataPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AnaHwTrq_SCom_WriteT1T2OffsetTrim (returns application error)
 *********************************************************************************************************************/
	(void)CallNonTrustedFunction(NtWrapS_AnaHwTrq_SCom_WriteT1T2OffsetTrim, (NonTrustedFunctionParameterRefType)HwTrqTrimDataPtr);
	return(NtWrap_RetBuf[NtWrapS_AnaHwTrq_SCom_WriteT1T2OffsetTrim].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: AssistLmtFunc_Scom_ManualTrqCmd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualTrqCmd> of PortPrototype <AssistLmtFunc_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_AssistLmtFunc_Scom_RTE_E_MtrTrqLmt_SCom_VSTH, RTE_E_AssistLmtFunc_Scom_RTE_E_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_AssistLmtFunc_Scom_RTE_E_MtrTrqLmt_SCom_VSTH
 *   RTE_E_AssistLmtFunc_Scom_RTE_E_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_AssistLmtFunc_Scom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_AssistLmtFunc_Scom_ManualTrqCmd (returns application error)
 *********************************************************************************************************************/
	AssistLmtFunc_ManualTrqCmd_Type myargs;

	myargs.arg1_lgc = EnableManualCtrl;
	myargs.arg2_f32 = MtrTrqCmd_MtrNm_f32;

	CallNonTrustedFunction(NtWrapS_AssistLmtFunc_Scom_ManualTrqCmd, (NonTrustedFunctionParameterRefType)&myargs);
	return(NtWrap_RetBuf[NtWrapS_AssistLmtFunc_Scom_ManualTrqCmd].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr3Phs_SCom_CalGain
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalGain> of PortPrototype <CmMtrCurr3Phs_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_CmMtrCurr3Phs_SCom_CalGain(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CmMtrCurr3Phs_SCom_ConditionNotCorrect, RTE_E_CmMtrCurr3Phs_SCom_CurrentOutOfRange, RTE_E_CmMtrCurr3Phs_SCom_VehSpdOutofRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_CmMtrCurr3Phs_SCom_CalGain(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CmMtrCurr3Phs_SCom_ConditionNotCorrect
 *   RTE_E_CmMtrCurr3Phs_SCom_CurrentOutOfRange
 *   RTE_E_CmMtrCurr3Phs_SCom_VehSpdOutofRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr3Phs_SCom_CalGain(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_CmMtrCurr3Phs_SCom_CalGain (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_CmMtrCurr3Phs_SCom_CalGain, (NonTrustedFunctionParameterRefType)NULL_PTR);
	return(NtWrap_RetBuf[NtWrapS_CmMtrCurr3Phs_SCom_CalGain].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr3Phs_SCom_CalGainPhs3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalGainPhs3> of PortPrototype <CmMtrCurr3Phs_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_CmMtrCurr3Phs_SCom_CalGainPhs3(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CmMtrCurr3Phs_SCom_ConditionNotCorrect, RTE_E_CmMtrCurr3Phs_SCom_CurrentOutOfRange, RTE_E_CmMtrCurr3Phs_SCom_VehSpdOutofRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_CmMtrCurr3Phs_SCom_CalGainPhs3(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CmMtrCurr3Phs_SCom_ConditionNotCorrect
 *   RTE_E_CmMtrCurr3Phs_SCom_CurrentOutOfRange
 *   RTE_E_CmMtrCurr3Phs_SCom_VehSpdOutofRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr3Phs_SCom_CalGainPhs3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_CmMtrCurr3Phs_SCom_CalGainPhs3 (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_CmMtrCurr3Phs_SCom_CalGainPhs3, (NonTrustedFunctionParameterRefType)NULL_PTR);
	return(NtWrap_RetBuf[NtWrapS_CmMtrCurr3Phs_SCom_CalGainPhs3].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr3Phs_SCom_CalOffset3Phs
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalOffset3Phs> of PortPrototype <CmMtrCurr3Phs_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_CmMtrCurr3Phs_SCom_CalOffset3Phs(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CmMtrCurr3Phs_SCom_ConditionNotCorrect, RTE_E_CmMtrCurr3Phs_SCom_CurrentOutOfRange, RTE_E_CmMtrCurr3Phs_SCom_VehSpdOutofRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_CmMtrCurr3Phs_SCom_CalOffset3Phs(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CmMtrCurr3Phs_SCom_ConditionNotCorrect
 *   RTE_E_CmMtrCurr3Phs_SCom_CurrentOutOfRange
 *   RTE_E_CmMtrCurr3Phs_SCom_VehSpdOutofRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr3Phs_SCom_CalOffset3Phs(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_CmMtrCurr3Phs_SCom_CalOffset3Phs (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_CmMtrCurr3Phs_SCom_CalOffset3Phs, (NonTrustedFunctionParameterRefType)NULL_PTR);
	return(NtWrap_RetBuf[NtWrapS_CmMtrCurr3Phs_SCom_CalOffset3Phs].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetMtrCurrCals3Phs> of PortPrototype <CmMtrCurr3Phs_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs(const PhaseCurrCal3Phs_DataType *ShCurrCal3PhsPtr)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs(const PhaseCurrCal3Phs_DataType *ShCurrCal3PhsPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs(P2CONST(PhaseCurrCal3Phs_DataType, AUTOMATIC, RTE_NTWRAP_APPL_DATA) ShCurrCal3PhsPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs, (NonTrustedFunctionParameterRefType)ShCurrCal3PhsPtr);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigColPs_SCom_CustClrTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CustClearTrim> of PortPrototype <DigColPs_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_DigColPs_SCom_CustClearTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_DigColPs_SCom_CustClrTrim(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_DigColPs_SCom_CustClrTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_DigColPs_SCom_CustClrTrim
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_DigColPs_SCom_CustClearTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigColPs_SCom_CustSetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CustSetTrim> of PortPrototype <DigColPs_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_DigColPs_SCom_CustSetTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigColPs_SCom_ConditionsNotCorrect
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_DigColPs_SCom_CustSetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DigColPs_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_DigColPs_SCom_CustSetTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_DigColPs_SCom_CustSetTrim (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_DigColPs_SCom_CustSetTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
	return(NtWrap_RetBuf[NtWrapS_DigColPs_SCom_CustSetTrim].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigColPs_SCom_NxtClearTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NxtClrTrim> of PortPrototype <DigColPs_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_DigColPs_SCom_NxtClrTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_DigColPs_SCom_NxtClrTrim(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_DigColPs_SCom_NxtClrTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_DigColPs_SCom_NxtClrTrim
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_DigColPs_SCom_NxtClearTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DigColPs_SCom_NxtSetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <NxtSetTrim> of PortPrototype <DigColPs_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_DigColPs_SCom_NxtSetTrim(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DigColPs_SCom_ConditionsNotCorrect
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_DigColPs_SCom_NxtSetTrim(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DigColPs_SCom_ConditionsNotCorrect
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_DigColPs_SCom_NxtSetTrim(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_DigColPs_SCom_NxtSetTrim (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_DigColPs_SCom_NxtSetTrim, (NonTrustedFunctionParameterRefType)NULL_PTR);
	return(NtWrap_RetBuf[NtWrapS_DigColPs_SCom_NxtSetTrim].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GeneratePosTraj_SCom_SetInputParam
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetInputParam> of PortPrototype <GeneratePosTraj_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_GeneratePosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_GeneratePosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_GeneratePosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_GeneratePosTraj_SCom_SetInputParam
 *********************************************************************************************************************/
	GeneratePosTraj_SetInputParam_Type myargs;

	myargs.arg1_f32 = PosServHwAngle_HwDeg_f32;
	myargs.arg2_f32 = TargetVelocity_HwDegpSec_f32;
	myargs.arg3_f32 = TargetAcceleration_HwDegpSecSqr_f32;

	CallNonTrustedFunction(NtWrapS_GenPosTraj_SCom_SetInputParam, (NonTrustedFunctionParameterRefType)&myargs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ClrHwTrqArbOffsetTrim> of PortPrototype <HwTrqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim(UInt8 HwTqTrmchNr_Cnt_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_HwTrqArbn_SCom_DataOutOfRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim(UInt8 HwTqTrmchNr_Cnt_u08)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrqArbn_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim(UInt8 HwTqTrmchNr_Cnt_u08)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim, (NonTrustedFunctionParameterRefType)&HwTqTrmchNr_Cnt_u08);
	return(NtWrap_RetBuf[NtWrapS_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrqArbn_SCom_SetHwTrqArbOffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetHwTrqArbOffsetTrim> of PortPrototype <HwTrqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim(UInt8 HwTqTrmchNr_Cnt_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_HwTrqArbn_SCom_DataOutOfRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim(UInt8 HwTqTrmchNr_Cnt_u08)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrqArbn_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim(UInt8 HwTqTrmchNr_Cnt_u08)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim (returns application error)
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim, (NonTrustedFunctionParameterRefType)&HwTqTrmchNr_Cnt_u08);
	return(NtWrap_RetBuf[NtWrapS_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteHwTrqArbOffsetTrim> of PortPrototype <HwTrqArbn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(const EOLChOffsetTrim_Datatype *EOLChOffsetTrimDataPtr, UInt8 HwTqTrmchNr_Cnt_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_HwTrqArbn_SCom_DataOutOfRange
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType NtWrapC_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(const EOLChOffsetTrim_Datatype *EOLChOffsetTrimDataPtr, UInt8 HwTqTrmchNr_Cnt_u08)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_HwTrqArbn_SCom_DataOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_NTWRAP_APPL_CODE) NtWrapC_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(P2CONST(EOLChOffsetTrim_Datatype, AUTOMATIC, RTE_NTWRAP_APPL_DATA) EOLChOffsetTrimDataPtr, UInt8 HwTqTrmchNr_Cnt_u08)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim (returns application error)
 *********************************************************************************************************************/
	HwTrqArbn_WriteHwTrqArbOffsetTrim_Type myargs;

	myargs.arg1_ptr = EOLChOffsetTrimDataPtr;
	myargs.arg2_u08 = HwTqTrmchNr_Cnt_u08;

	CallNonTrustedFunction(NtWrapS_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim, (NonTrustedFunctionParameterRefType)&myargs);
	return(NtWrap_RetBuf[NtWrapS_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim].Std_Return);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteMotMeclPosn1CoeffTbl> of PortPrototype <MotMeclPosn1_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_C_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(const Float *MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, UInt8 *MotMeclPosn1CoeffTblResp)
#else
 *   Std_ReturnType Rte_Call_C_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(const DT_MotMeclPosnCoeffTbl_f32 *MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, UInt8 *MotMeclPosn1CoeffTblResp)
#endif
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(const Float *MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, UInt8 *MotMeclPosn1CoeffTblResp)
#else
 *   void NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(const DT_MotMeclPosnCoeffTbl_f32 *MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, UInt8 *MotMeclPosn1CoeffTblResp)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(P2CONST(Float, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotMeclPosn1CoeffTblResp)
#else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(P2CONST(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotMeclPosn1CoeffTbl, UInt16 MotMeclPosn1CoeffTblCRC, UInt16 MotMeclPosn1CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotMeclPosn1CoeffTblResp)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl
 *********************************************************************************************************************/
	MotMeclPosn_WriteMotMeclPosnCoeffTbl_Type myargs;

	myargs.coeffTbl_ptr = MotMeclPosn1CoeffTbl;
	myargs.crc_u16 = MotMeclPosn1CoeffTblCRC;
	myargs.seed_u16 = MotMeclPosn1CoeffTblCRCSeed;
	myargs.resp_ptr = &NtWrap_RetBuf[NtWrapS_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl].Std_Return;

	CallNonTrustedFunction(NtWrapS_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl, (NonTrustedFunctionParameterRefType)&myargs);
	*MotMeclPosn1CoeffTblResp = NtWrap_RetBuf[NtWrapS_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl].Std_Return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteMotMeclPosn2CoeffTbl> of PortPrototype <MotMeclPosn2_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_C_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(const Float *MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, UInt8 *MotMeclPosn2CoeffTblResp)
#else
 *   Std_ReturnType Rte_Call_C_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(const DT_MotMeclPosnCoeffTbl_f32 *MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, UInt8 *MotMeclPosn2CoeffTblResp)
#endif
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(const Float *MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, UInt8 *MotMeclPosn2CoeffTblResp)
#else
 *   void NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(const DT_MotMeclPosnCoeffTbl_f32 *MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, UInt8 *MotMeclPosn2CoeffTblResp)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(P2CONST(Float, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotMeclPosn2CoeffTblResp)
#else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(P2CONST(DT_MotMeclPosnCoeffTbl_f32, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotMeclPosn2CoeffTbl, UInt16 MotMeclPosn2CoeffTblCRC, UInt16 MotMeclPosn2CoeffTblCRCSeed, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotMeclPosn2CoeffTblResp)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl
 *********************************************************************************************************************/
	MotMeclPosn_WriteMotMeclPosnCoeffTbl_Type myargs;

	myargs.coeffTbl_ptr = MotMeclPosn2CoeffTbl;
	myargs.crc_u16 = MotMeclPosn2CoeffTblCRC;
	myargs.seed_u16 = MotMeclPosn2CoeffTblCRCSeed;
	myargs.resp_ptr = &NtWrap_RetBuf[NtWrapS_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl].Std_Return;

	CallNonTrustedFunction(NtWrapS_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl, (NonTrustedFunctionParameterRefType)&myargs);
	*MotMeclPosn2CoeffTblResp = NtWrap_RetBuf[NtWrapS_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl].Std_Return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotPosnCmp_Scom_MotPosnCmpBackEmfWr
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <MotPosnCmpBackEmfWr> of PortPrototype <MotPosnCmp_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_C_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(const UInt16 *MotPosnBackEmfWrData, UInt8 *MotPosnCmpBackEmfWrResp)
#else
 *   Std_ReturnType Rte_Call_C_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(const MotPosnBackEmfData *MotPosnBackEmfWrData, UInt8 *MotPosnCmpBackEmfWrResp)
#endif
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void NtWrapC_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(const UInt16 *MotPosnBackEmfWrData, UInt8 *MotPosnCmpBackEmfWrResp)
#else
 *   void NtWrapC_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(const MotPosnBackEmfData *MotPosnBackEmfWrData, UInt8 *MotPosnCmpBackEmfWrResp)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotPosnBackEmfWrData, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotPosnCmpBackEmfWrResp)
#else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(P2CONST(MotPosnBackEmfData, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MotPosnBackEmfWrData, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MotPosnCmpBackEmfWrResp)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_MotPosnCmp_Scom_MotPosnCmpBackEmfWr
 *********************************************************************************************************************/
	MotPosnCmp_MotPosnCmpBackEmfWr_Type myargs;

	myargs.arg1_ptr = MotPosnBackEmfWrData;
	myargs.arg2_ptr = &NtWrap_RetBuf[NtWrapS_MotPosnCmp_Scom_MotPosnCmpBackEmfWr].Std_Return;

	(void)CallNonTrustedFunction(NtWrapS_MotPosnCmp_Scom_MotPosnCmpBackEmfWr, (NonTrustedFunctionParameterRefType)&myargs);
	*MotPosnCmpBackEmfWrResp = NtWrap_RetBuf[NtWrapS_MotPosnCmp_Scom_MotPosnCmpBackEmfWr].Std_Return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrPos3SinCos_Scom_WriteEOLMtrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteEOLMtrCals> of PortPrototype <MtrPos3SinCos_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_C_MtrPos3SinCos_Scom_WriteEOLMtrCals(const UInt16 *MtrEOLDataPtr, UInt8 *MtrPos3SinCosWrResp)
#else
 *   Std_ReturnType Rte_Call_C_MtrPos3SinCos_Scom_WriteEOLMtrCals(const MtrPos3SinCos_EOLwithCRC *MtrEOLDataPtr, UInt8 *MtrPos3SinCosWrResp)
#endif
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void NtWrapC_MtrPos3SinCos_Scom_WriteEOLMtrCals(const UInt16 *MtrEOLDataPtr, UInt8 *MtrPos3SinCosWrResp)
#else
 *   void NtWrapC_MtrPos3SinCos_Scom_WriteEOLMtrCals(const MtrPos3SinCos_EOLwithCRC *MtrEOLDataPtr, UInt8 *MtrPos3SinCosWrResp)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrPos3SinCos_Scom_WriteEOLMtrCals(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrEOLDataPtr, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MtrPos3SinCosWrResp)
#else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_MtrPos3SinCos_Scom_WriteEOLMtrCals(P2CONST(MtrPos3SinCos_EOLwithCRC, AUTOMATIC, RTE_NTWRAP_APPL_DATA) MtrEOLDataPtr, P2VAR(UInt8, AUTOMATIC, RTE_NTWRAP_APPL_VAR) MtrPos3SinCosWrResp)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_MtrPos3SinCos_Scom_WriteEOLMtrCals
 *********************************************************************************************************************/
	MtrPos3SinCos_WriteEOLMtrCals_Type myargs;

	myargs.arg1_ptr = MtrEOLDataPtr;
	myargs.arg2_ptr = &NtWrap_RetBuf[NtWrapS_MtrPos3SinCos_Scom_WriteEOLMtrCals].Std_Return;

	(void)CallNonTrustedFunction(NtWrapS_MtrPos3SinCos_Scom_WriteEOLMtrCals, (NonTrustedFunctionParameterRefType)&myargs);
	*MtrPos3SinCosWrResp = NtWrap_RetBuf[NtWrapS_MtrPos3SinCos_Scom_WriteEOLMtrCals].Std_Return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NtWrap_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrap_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrap_Per1
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Polarity_SCom_SetPolarity
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetPolarity> of PortPrototype <Polarity_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Polarity_SCom_SetPolarity(UInt32 PolarityCfg_PolarityCfgSaved_Cnt_T_u32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_Polarity_SCom_SetPolarity
 *********************************************************************************************************************/
	(void)CallNonTrustedFunction(NtWrapS_Polarity_SCom_SetPolarity, (NonTrustedFunctionParameterRefType)&PolarityCfg_PolarityCfgSaved_Cnt_T_u32);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SCom_EOLNomMtrParam_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <SCom_EOLNomMtrParam>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomRmtr_Ohm_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_SCom_EOLNomMtrParam_Set
 *********************************************************************************************************************/
	EOLNomMtrParam_Set_Type myargs;

	myargs.arg1_f32 =  NomKe_VpRadpS_f32;
	myargs.arg2_f32 =  NomRmtr_Ohm_f32;

	(void)CallNonTrustedFunction(NtWrapS_SCom_EOLNomMtrParam_Set, (NonTrustedFunctionParameterRefType)&myargs);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TSMit_SCom_GainReset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GainReset> of PortPrototype <TSMit_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_TSMit_SCom_GainReset(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_TSMit_SCom_GainReset(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TSMit_SCom_GainReset(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_TSMit_SCom_GainReset
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_TSMit_SCom_GainReset, (NonTrustedFunctionParameterRefType)NULL_PTR);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqCanc_Scom_SetCogTrqCal
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetCogTrqCal> of PortPrototype <TrqCanc_Scom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   Std_ReturnType Rte_Call_C_TrqCanc_Scom_SetCogTrqCal(const UInt16 *CogTrqCalPtr, UInt16 ID)
#else
 *   Std_ReturnType Rte_Call_C_TrqCanc_Scom_SetCogTrqCal(const CoggingCancTrq *CogTrqCalPtr, UInt16 ID)
#endif
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   void NtWrapC_TrqCanc_Scom_SetCogTrqCal(const UInt16 *CogTrqCalPtr, UInt16 ID)
#else
 *   void NtWrapC_TrqCanc_Scom_SetCogTrqCal(const CoggingCancTrq *CogTrqCalPtr, UInt16 ID)
#endif
 *
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(UInt16, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID)
#else
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCanc_Scom_SetCogTrqCal(P2CONST(CoggingCancTrq, AUTOMATIC, RTE_NTWRAP_APPL_DATA) CogTrqCalPtr, UInt16 ID)
#endif
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_TrqCanc_Scom_SetCogTrqCal
 *********************************************************************************************************************/
	TrqCanc_SetCogTrqCal_Type myargs;

	myargs.arg1_ptr = CogTrqCalPtr;
	myargs.arg2_u16 = ID;

	(void)CallNonTrustedFunction(NtWrapS_TrqCanc_Scom_SetCogTrqCal, (TrustedFunctionParameterRefType)&myargs);
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_TrqCmdScl_SCom_Set(Float Par_f32)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_TrqCmdScl_SCom_Set(Float Par_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqCmdScl_SCom_Set(Float Par_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_TrqCmdScl_SCom_Set
 *********************************************************************************************************************/
	(void)CallNonTrustedFunction(NtWrapS_TrqCmdScl_SCom_Set, (TrustedFunctionParameterRefType)&Par_f32);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: TrqOvlSta_SCom_SetGmLoaIgnCntr
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetGmLoaIgnCntr> of PortPrototype <TrqOvlSta_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_TrqOvlSta_SCom_SetGmLoaIgnCntr(UInt16 GmLoaIgnCntr_Cnt_u16)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_TrqOvlSta_SCom_SetGmLoaIgnCntr(UInt16 GmLoaIgnCntr_Cnt_u16)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_TrqOvlSta_SCom_SetGmLoaIgnCntr(UInt16 GmLoaIgnCntr_Cnt_u16)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_TrqOvlSta_SCom_SetGmLoaIgnCntr
 *********************************************************************************************************************/
	(void)CallNonTrustedFunction(NtWrapS_TrqOvlSta_SCom_SetGmLoaIgnCntr, (TrustedFunctionParameterRefType)&GmLoaIgnCntr_Cnt_u16);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehDyn_SCom_ForceCenter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ForceCenter> of PortPrototype <VehDyn_SCom>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_C_VehDyn_SCom_ForceCenter(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NtWrapC_VehDyn_SCom_ForceCenter(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_VehDyn_SCom_ForceCenter(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NtWrapC_VehDyn_SCom_ForceCenter
 *********************************************************************************************************************/
	CallNonTrustedFunction(NtWrapS_VehDyn_SCom_ForceCenter, (NonTrustedFunctionParameterRefType)NULL_PTR);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_NTWRAP_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/********************************************************************************************************
 * Client side (Non-Rte) Wrappers (NONTRUSTED API)
 *******************************************************************************************************/
 
FUNC(void, RTE_NTWRAP_APPL_CODE) NtWrapC_Adc_Init()
{
	CallTrustedFunction(NtWrapS_Adc_Init, (TrustedFunctionParameterRefType)NULL_PTR);
}

 
/********************************************************************************************************
 * Server side Wrappers (NONTRUSTED API)
 *******************************************************************************************************/
/*TODO: Provide a pointer validation check prior to use to ensure freedom of interference that would result from using an invalid pointer
 * provided by a seperate application */

/* AnaHwTrq non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_AnaHwTrq_SCom_ClrAnaHwTrqScaleTrim();
}

/* AnaHwTrq non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_AnaHwTrq_SCom_ClrT1T2OffsetTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_AnaHwTrq_SCom_ClrT1T2OffsetTrim();
}

/* AnaHwTrq non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_AnaHwTrq_SCom_SetAnaHwTrqScaleTrim((*(Float *) par));
}

/* AnaHwTrq non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_AnaHwTrq_SCom_SetT1T2OffsetTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_AnaHwTrq_SCom_SetT1T2OffsetTrim();
}

/* AnaHwTrq non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_AnaHwTrq_SCom_WriteT1T2OffsetTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_AnaHwTrq_SCom_WriteT1T2OffsetTrim((const AnaHwTrqTrim_Datatype *)par);
}

/* HwTrqArbn non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_HwTrqArbn_SCom_ClrHwTrqArbOffsetTrim((*(UInt8 *)par));
}

/* HwTrqArbn non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_HwTrqArbn_SCom_SetHwTrqArbOffsetTrim((*(UInt8 *)par));
}

/* HwTrqArbn non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	HwTrqArbn_WriteHwTrqArbOffsetTrim_Type *myargs = (HwTrqArbn_WriteHwTrqArbOffsetTrim_Type *)par;

	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return =
		Rte_Call_C_HwTrqArbn_SCom_WriteHwTrqArbOffsetTrim(myargs->arg1_ptr, myargs->arg2_u08);
}

/* CmMtrCurr3Phs non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_CmMtrCurr3Phs_SCom_CalGain(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_CmMtrCurr3Phs_SCom_CalGain();
}

/* CmMtrCurr3Phs non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_CmMtrCurr3Phs_SCom_CalGainPhs3(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_CmMtrCurr3Phs_SCom_CalGainPhs3();
}

/* CmMtrCurr3Phs non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_CmMtrCurr3Phs_SCom_CalOffset3Phs(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_CmMtrCurr3Phs_SCom_CalOffset3Phs();
}

/* CmMtrCurr3Phs non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_CmMtrCurr3Phs_SCom_SetMtrCurrCals3Phs((const PhaseCurrCal3Phs_DataType*)par);
}

/* MtrPos3SinCo non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_MtrPos3SinCos_Scom_WriteEOLMtrCals(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	MtrPos3SinCos_WriteEOLMtrCals_Type *myargs = (MtrPos3SinCos_WriteEOLMtrCals_Type *)par;

	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	(void)Rte_Call_C_MtrPos3SinCos_Scom_WriteEOLMtrCals(myargs->arg1_ptr, myargs->arg2_ptr);
}

/* MotMeclPosn1 non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	MotMeclPosn_WriteMotMeclPosnCoeffTbl_Type *myargs = (MotMeclPosn_WriteMotMeclPosnCoeffTbl_Type *)par;

	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	Rte_Call_C_MotMeclPosn1_Scom_WriteMotMeclPosn1CoeffTbl(myargs->coeffTbl_ptr, myargs->crc_u16, myargs->seed_u16, myargs->resp_ptr);
	NtWrap_RetBuf[index].Std_Return = *(myargs->resp_ptr);
}

/* MotMeclPosn2 non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	MotMeclPosn_WriteMotMeclPosnCoeffTbl_Type *myargs = (MotMeclPosn_WriteMotMeclPosnCoeffTbl_Type *)par;

	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	Rte_Call_C_MotMeclPosn2_Scom_WriteMotMeclPosn2CoeffTbl(myargs->coeffTbl_ptr, myargs->crc_u16, myargs->seed_u16, myargs->resp_ptr);
	NtWrap_RetBuf[index].Std_Return = *(myargs->resp_ptr);
}

/* MotPosnCmp non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	MotPosnCmp_MotPosnCmpBackEmfWr_Type *myargs = (MotPosnCmp_MotPosnCmpBackEmfWr_Type *)par;

	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	(void)Rte_Call_C_MotPosnCmp_Scom_MotPosnCmpBackEmfWr(myargs->arg1_ptr, myargs->arg2_ptr);
}

void NONTRUSTED_NtWrapS_XcpWriteAp8(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	ApXcpWriteCommon();
}

void NONTRUSTED_NtWrapS_XcpWriteAp9(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	ApXcpWriteCommon();
}

void NONTRUSTED_NtWrapS_XcpWriteAp10(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	ApXcpWriteCommon();
}

/* AssistLmtFunc non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_AssistLmtFunc_Scom_ManualTrqCmd(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par) /* PRQA S 1505, 3673 */
{
	AssistLmtFunc_ManualTrqCmd_Type *myargs = (AssistLmtFunc_ManualTrqCmd_Type *) par;

	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[NtWrapS_AssistLmtFunc_Scom_ManualTrqCmd].Std_Return =
		Rte_Call_C_AssistLmtFunc_Scom_ManualTrqCmd(myargs->arg1_lgc, myargs->arg2_f32);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_SCom_EOLNomMtrParam_Set(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)  /* PRQA S 1505, 3673 */
{
	EOLNomMtrParam_Set_Type *myargs = (EOLNomMtrParam_Set_Type *)par;

	Rte_Call_C_SCom_EOLNomMtrParam_Set(myargs->arg1_f32, myargs->arg2_f32);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_TrqCmdScl_SCom_Set(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)   /* PRQA S 1505, 3673 */
{
	Rte_Call_C_TrqCmdScl_SCom_Set(*(Float*)par);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_TrqOvlSta_SCom_SetGmLoaIgnCntr(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)   /* PRQA S 1505, 3673 */
{
	Rte_Call_C_TrqOvlSta_SCom_SetGmLoaIgnCntr(*(UInt16 *)par);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_Polarity_SCom_SetPolarity(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_Polarity_SCom_SetPolarity(*(UInt32*)par);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_TrqCanc_Scom_SetCogTrqCal(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	TrqCanc_SetCogTrqCal_Type *myargs = (TrqCanc_SetCogTrqCal_Type *)par;

	Rte_Call_C_TrqCanc_Scom_SetCogTrqCal(myargs->arg1_ptr, myargs->arg2_u16 );
}

/* GenPosTraj non-Trusted SComm Server wrapper function */
void NONTRUSTED_NtWrapS_GenPosTraj_SCom_SetInputParam(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	GeneratePosTraj_SetInputParam_Type *myargs = (GeneratePosTraj_SetInputParam_Type *)par;

	Rte_Call_C_GeneratePosTraj_SCom_SetInputParam(myargs->arg1_f32, myargs->arg2_f32, myargs->arg3_f32);
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_DigColPs_SCom_CustSetTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08)  {
		NtWrap_ReportDet( D_NTWRAPINVLDINDXDET_CNT_U08 );
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_DigColPs_SCom_CustSetTrim();
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_DigColPs_SCom_CustClearTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_DigColPs_SCom_CustClearTrim();
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_DigColPs_SCom_NxtSetTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	#if(STD_ON == NTWRAP_DEV_ERROR_DETECT)
	if(index >= D_NUMRETURNBUFF_CNT_U08) {
		NtWrap_ReportDet(D_NTWRAPINVLDINDXDET_CNT_U08);
	}
	#endif

	NtWrap_RetBuf[index].Std_Return = Rte_Call_C_DigColPs_SCom_NxtSetTrim();
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_DigColPs_SCom_NxtClearTrim(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_DigColPs_SCom_NxtClrTrim();
}

/* Non-Trusted SComm Server wrapper Functions */
void NONTRUSTED_NtWrapS_TSMit_SCom_GainReset(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_TSMit_SCom_GainReset();
}

void NONTRUSTED_NtWrapS_VehDyn_SCom_ForceCenter(NonTrustedFunctionIndexType index, NonTrustedFunctionParameterRefType par)
{
	Rte_Call_C_VehDyn_SCom_ForceCenter();
}

/********************************************************************************************************
 * Server side Wrappers (TRUSTED API)
 *******************************************************************************************************/
/*TODO: Provide a pointer validation check prior to use to ensure freedom of interference that would result from using an invalid pointer
 * provided by a seperate application */

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_Adc_Init(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	Adc_Init(&AdcConfigSet);
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_Adc2_Init1(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	Adc2_Init1();
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_NvMProxy_Init(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	NvMProxy_Init();
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_StaMd_Init1(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	StaMd_Init1();
}

/* Trusted wrapper Function */
void TRUSTED_NtWrapS_PwmCdd_Init(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)  /* PRQA S 1505, 3673 */
{
	PwmCdd_Init();
}

/* Trusted SComm Server Function */
void TRUSTED_NtWrapS_Wdg_TMS570LS3x_Init(TrustedFunctionIndexType index, TrustedFunctionParameterRefType par)
{
	/* Limitied implementation, TODO: improve in the future to make more generic and accept a passed config parameter */
	/* The Wdg Init function requires privileged access to initalize the RTI register for enabling its internal timebase */
	Wdg_TMS570LS3x_Init(&wdg_tms570ls3x_config);
}

/* Trusted SComm Server wrapper Functions */
void TRUSTED_NtWrapS_WdgM_Init(TrustedFunctionIndexType index, TrustedFunctionParameterRefType par)
{
	/* Limitied implementation, TODO: improve in the future to make more generic and accept a passed config parameter */
	/* The WdgM init funciton appears to need access to all application memory for initlaization of the supervised entity variables */
	WdgM_Init(&WdgMConfig_Mode0);
}

void TRUSTED_TWrapS_XcpWriteAp0(TrustedFunctionIndexType index, TrustedFunctionParameterRefType FunctionParams)
{
	ApXcpWriteCommon();
}

void TRUSTED_NtWrapS_ProcessF0FF(TrustedFunctionIndexType index, TrustedFunctionParameterRefType FunctionParams)
{
	ProcessF0FF(((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_ProcessF0FF_args.os_arg_t_SrvcData_Cnt_T_u08, ((TrustedFunctionParameterType*)FunctionParams)->NtWrapS_ProcessF0FF_args.os_arg_RequestDataIdx_Cnt_T_u16);
}

void TRUSTED_TWrapS_Dma_InvalidateSlowADCGroup(TrustedFunctionIndexType index, TrustedFunctionParameterRefType FunctionParams)
{
	Dma_InvalidateSlowADCGroup();
}

void TRUSTED_NtWrapS_StaMd_Init0(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
	StaMd_Init0();
}


/********************************************************************************************************
 *  Non C/S (TRUSTED API)
 *******************************************************************************************************/
void Call_Adc2_Init1(void)
{
	(void) CallTrustedFunction(NtWrapS_Adc2_Init1, (TrustedFunctionParameterRefType)0);
}

void Call_NvMProxy_Init(void)
{
	(void) CallTrustedFunction(NtWrapS_NvMProxy_Init, (TrustedFunctionParameterRefType)0);
}

void Call_StaMd_Init1(void)
{
	(void) CallTrustedFunction(NtWrapS_StaMd_Init1, (TrustedFunctionParameterRefType)0);
}

void Call_PwmCdd_Init(void)
{
	(void) CallTrustedFunction(NtWrapS_PwmCdd_Init, (TrustedFunctionParameterRefType)0);
}

void Call_StaMd_Init0(void)
{
	(void) CallTrustedFunction(NtWrapS_StaMd_Init0, (TrustedFunctionParameterRefType)0);
}

Std_ReturnType NtWrapC_Wdg_TMS570LS3x_Init(P2CONST(Wdg_TMS570LS3x_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr)
{
	(void)CallTrustedFunction(NtWrapS_Wdg_TMS570LS3x_Init, (TrustedFunctionParameterRefType)ConfigPtr);

	/* returning fixed return type as a quick implementation.  Return actual value in future implementation */
	return(E_OK);
}

void NtWrapC_WdgM_Init(P2CONST (WdgM_ConfigType, AUTOMATIC, WDGM_APPL_CONST) WdgMConfigPtr)
{
	(void)CallTrustedFunction(NtWrapS_WdgM_Init, (TrustedFunctionParameterRefType)WdgMConfigPtr);
}

void Call_ProcessF0FF(P2VAR(uint8, AUTOMATIC, AUTOMATIC) t_SrvcData_Cnt_T_u08, VAR(uint16, AUTOMATIC) RequestDataIdx_Cnt_T_u16)
{
	VAR(TrustedFunctionParameterType, AUTOMATIC) myargs;

	myargs.NtWrapS_ProcessF0FF_args.os_arg_RequestDataIdx_Cnt_T_u16 = RequestDataIdx_Cnt_T_u16;
	myargs.NtWrapS_ProcessF0FF_args.os_arg_t_SrvcData_Cnt_T_u08 = t_SrvcData_Cnt_T_u08;

	(void)CallTrustedFunction(NtWrapS_ProcessF0FF, &myargs);
}

void TWrapC_Dma_InvalidateSlowADCGroup(void)
{
	(void)CallTrustedFunction((TrustedFunctionIndexType)TWrapS_Dma_InvalidateSlowADCGroup, (TrustedFunctionParameterRefType)0);
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
