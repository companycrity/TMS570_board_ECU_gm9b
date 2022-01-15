/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_CDDInterface.c
 *     Workspace:  C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/CDDInterface/autosar
 *     SW-C Type:  Sa_CDDInterface
 *  Generated at:  Mon Jan 16 15:40:25 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Sa_CDDInterface>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Aug 15 20:53:00 2011
 * %version:          EA3#9 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Thu Dec  5 11:35:32 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 12/01/15  5        GMN       EA3#4064: Update SF-99 and 83.3Hz noise reduction                             4962
 * 02/15/16  6        GMN       EA3#43112: Added motor variant output                                         4383
 * 02/24/16  7        GMN       EA3#2817: Update ES-60A / ES-61A MotMeclPosn 1/2
 * 03/30/16  8        GMN       EA3#2923: Added output to enable/disable features (CPID05)                    6951
 * 07/06/16  9        GMN       EA3#9207: Added LOA signals reads
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.

  Volt_f32 of Port Interface Vecu_Volt_f32
    This port prototype is inteded to communicate voltage signals that represent the ecu supplied voltage.  This signal has a lower limit, which is non-zero, to allow users of the signal to use it as a denominator in an expression without requiring a divide by 0 check.


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Sa_CDDInterface.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "fixmath.h"
#include "GlobalMacro.h"
#include "CDD_Data.h"
#include "Interrupts.h"
#include "Nhet.h"
#include "CalConstants.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
#include "Ap_DfltConfigData.h"
#include "Nhet_PhaseFdbkMeas_Prog.h"
#include "CDD_Func.h"
#include "appdesc.h"


/* TODO: Consider moving all a/d scaling to a single file (IO HwAbs?) */
#define D_ADCVOLTSPERCNT_ULS_F32        (5.0F/4095.0F)
#define D_WHLIMBSEL_CNT_U16             0xA5A2U
#define D_ECUCONFIGWIRMSK_CNT_U8        0x02U
#define D_ECUCONFIGACTPULLMSK_CNT_U8    0x01U
#define D_PXACCUMMAX_CNT_U32            536870911UL
#define D_PHSADVSCALE_ULS_F32           (6144.0F/65536.0F)
#define D_HALFREV_CNT_U16               32768U
#define D_FULLREV_CNT_S32               65536L
#define D_ONEREV_DEG_F32                360.0F


#define D_PHASEA_CNT_U16  0U
#define D_PHASEB_CNT_U16  1U
#define D_PHASEC_CNT_U16  2U

#define CDDINTERFACE_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
#define CDDINTERFACE_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define CDDINTERFACE_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint8, CDDINTERFACE_VAR_NOINIT) PrevMtrElecMechPolarity_Cnt_M_s08;
#define CDDINTERFACE_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define D_SVCDFTENGON_CNT_B32           1U
#define D_SVCDFTFREQDEPDMP_CNT_B32      2U
#define D_SVCDFTKININTDIAG_CNT_B32      4U
#define D_SVCDFTTHERMALDC_CNT_B32       8U
#define D_SVCDFTEOTIMPACT_CNT_B32       16U
#define D_SVCDFTEOTTHERMAL_CNT_B32      32U
#define D_SVCDFTMTRVELNRMLRN_CNT_B32    64U
#define D_SVCDFTMTRPARMNRMLRN_CNT_B32   128U
#define D_SVCDFTTRQRMP_CNT_B32          256U
#define D_SVCDFTMODIDX_CNT_B32          512U
#define D_SVCDFTPULLCOMP_CNT_B32        1024U
#define D_SVCDFTWHLIMBREJ_CNT_B32       2048U
#define D_SVCDFTPARKAST_CNT_B32         4096U
#define D_SVCDFTDRIVINGDYN_CNT_B32      8192U
#define D_SVCDFTHYSTCOMP_CNT_B32        16384U
#define D_SVCDFTHYSTADD_CNT_B32         32768U
#define D_SVCDFTRETURN_CNT_B32          65536U
#define D_SVCDFTDAMPING_CNT_B32         131072U
#define D_SVCDFTLIMIT_CNT_B32           262144U
#define D_SVCDFTPULLCOMPLRN_CNT_B32     524288U
#define D_SVCDFTFRICLRN_CNT_B32         1048576U
/* #define D_SVCDFTRXMSGS_CNT_B32            134217728U */
/* #define D_SVCDFTMULTIGNMASK_CNT_B32       1342177280U */


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
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ManufModeType: Enumeration of integer in interval [0...2] with enumerators
 *   ProductionMode (0U)
 *   ManufacturingMode (1U)
 *   EngineeringMode (2U)
 * SigQlfr_State_enum: Enumeration of integer in interval [0...2] with enumerators
 *   SIGQLFR_NORES (0U)
 *   SIGQLFR_PASS (1U)
 *   SIGQLFR_FAIL (2U)
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
 * Float: D_VECUMIN_VOLTS_F32 = 5.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt8: D_ZERO_CNT_S8 = 0
 * SigQlfr_State_enum: D_SIGQLFRNORES_CNT_ENUM = 0U
 * UInt16: D_SEVEN_CNT_U16 = 7U
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ZERO_CNT_U32 = 0U
 * UInt8: D_SEVEN_CNT_U08 = 7U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_CDDINTERFACE_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotorVariant_Cnt_u16(UInt16 data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface_Init1_IgnCnt_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Init1_IgnCnt_Cnt_u16(void)
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

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface_Init1
 *********************************************************************************************************************/

	Rte_IWrite_CDDInterface_Init1_IgnCnt_Cnt_u16(Nvm_IgnCntr_Cnt_u16);
	(void)Rte_Write_MotorVariant_Cnt_u16((uint16)Nvm_MotorVariant_Cnt_u8);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Init2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   SInt8 Rte_IRead_CDDInterface_Init2_MtrElecMechPolarity_Cnt_s08(void)
 *   SInt8 Rte_IRead_CDDInterface_Init2_MtrPosPolarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface_Init2_MEC_Cnt_enum(ManufModeType data)
 *   ManufModeType *Rte_IWriteRef_CDDInterface_Init2_MEC_Cnt_enum(void)
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
 *   Std_ReturnType Rte_Call_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Init2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface_Init2
 *********************************************************************************************************************/
	VAR(sint8, AUTOMATIC) MtrElecMechPolarity_Cnt_T_s08;

	MtrElecMechPolarity_Cnt_T_s08 = Rte_IRead_CDDInterface_Init2_MtrElecMechPolarity_Cnt_s08();

	CDD_AppDataFwdPthAccessBfr_Cnt_G_u16 = 0U;
	CDD_AppDataFbkPthAccessBfr_Cnt_G_u16 = 0U;
	CDD_CDDDataAccessBfr_Cnt_G_u16 = 0U;

	(void)Rte_Call_CDDPorts_ApplyMtrElecMechPol(MtrElecMechPolarity_Cnt_T_s08);
	PrevMtrElecMechPolarity_Cnt_M_s08 = MtrElecMechPolarity_Cnt_T_s08;

	Rte_IWrite_CDDInterface_Init2_MEC_Cnt_enum(NxtrMEC_Uls_G_enum);
	CDD_Vecu_Volt_G_f32[0]=31.0F;
	CDD_Vecu_Volt_G_f32[1]=31.0F;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Init3
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

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Init3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface_Init3
 *********************************************************************************************************************/

	EnableMtrCtlInterrupt();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface_Per1_ADCMtrCurrA_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurrA_Volt_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ADCMtrCurrB_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurrB_Volt_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ADCMtrCurrC_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_ADCMtrCurrC_Volt_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_CorrMtrCurrA_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_CorrMtrCurrA_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_CorrMtrCurrB_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_CorrMtrCurrB_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_CorrMtrCurrC_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_CorrMtrCurrC_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_CorrMtrCurrPosition_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_CorrMtrCurrPosition_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_CorrectedElecMtrPosFloat_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_CorrectedElecMtrPosFloat_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_DigMSBArbnMtrPosMecl_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_DigMSBArbnMtrPosMecl_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_CDDInterface_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(void)
 *   void Rte_IWrite_CDDInterface_Per1_ModIdxFinal_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_ModIdxFinal_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotMeclPosn1MeasdTi_USec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn1MeasdTi_USec_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotMeclPosn1ParityFaultAccum_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn1ParityFaultAccum_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotMeclPosn1RawErrReg_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn1RawErrReg_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotMeclPosn1RevM_Rev_u0p16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn1RevM_Rev_u0p16(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotMeclPosn1RollgCntr_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn1RollgCntr_Cnt_u08(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotMeclPosn2MeasdTi_USec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn2MeasdTi_USec_u32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotMeclPosn2ParityFaultAccum_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn2ParityFaultAccum_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotMeclPosn2RawErrReg_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn2RawErrReg_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotMeclPosn2RevM_Rev_u0p16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn2RevM_Rev_u0p16(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotMeclPosn2RollgCntr_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn2RollgCntr_Cnt_u08(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotPosnCmpMotPosnCumvAlgnd_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MotPosnCmpMotPosnCumvAlgnd_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MotPosnCmpMotPosnElec_Rev_u0p16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_MotPosnCmpMotPosnElec_Rev_u0p16(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCtrlMtrDaxVoltage_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCtrlMtrDaxVoltage_Volt_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCtrlMtrQaxVoltage_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCtrlMtrQaxVoltage_Volt_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrDax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrDax_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrQaxFinalRef_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrQaxFinalRef_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_MtrCurrQax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per1_MtrCurrQax_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface_Per1_SysCBattSwitched1_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_SysCBattSwitched1_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface_Per1_SysCBattSwitched2_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_SysCBattSwitched2_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface_Per1_SysCT1ADC_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_SysCT1ADC_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface_Per1_SysCT2ADC_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface_Per1_SysCT2ADC_Cnt_u16(void)
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
 *   Std_ReturnType Rte_Call_Get_PhaseFdbk_PhaseFdbk(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface_Per1
 *********************************************************************************************************************/
	volatile VAR(uint16, AUTOMATIC) ReadBuffer_Cnt_T_u16;
	volatile VAR(uint16, AUTOMATIC) WriteBuffer_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) PhaseAdvFinal_Cnt_T_u16;
	VAR(uint32, AUTOMATIC) ExpectedOnTimeA_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) ExpectedOnTimeB_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) ExpectedOnTimeC_Cnt_T_u32;
	VAR(sint16, AUTOMATIC) PhaseAdvFinal_Cnt_T_s16;
	VAR(uint16,  AUTOMATIC) SysCBattSwitched1_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) SysCBattSwitched2_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) SysCT1Adc_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) SysCT2Adc_Cnt_T_u16;

	ReadBuffer_Cnt_T_u16 = CDD_CDDDataAccessBfr_Cnt_G_u16;
	WriteBuffer_Cnt_T_u16 = (ReadBuffer_Cnt_T_u16 & 1U) ^ 1U;
	(void)CDDPorts_ClearPhsReasSum(WriteBuffer_Cnt_T_u16);
	CDD_CDDDataAccessBfr_Cnt_G_u16 = WriteBuffer_Cnt_T_u16;

	/* These NHET2 memory reads are performed immediately after the buffer swap for greatest possible synchronization */
	(void)Rte_Call_Get_PhaseFdbk_PhaseFdbk();

	/* CmMtrCurr3Phs */
	Rte_IWrite_CDDInterface_Per1_ADCMtrCurrA_Volt_f32(CDD_MtrCurrA_Volts_G_f32[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_ADCMtrCurrB_Volt_f32(CDD_MtrCurrB_Volts_G_f32[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_ADCMtrCurrC_Volt_f32(CDD_MtrCurrC_Volts_G_f32[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_CorrMtrCurrA_Amp_f32(CDD_CorrMtrCurrA_Amps_G_f32[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_CorrMtrCurrB_Amp_f32(CDD_CorrMtrCurrB_Amps_G_f32[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_CorrMtrCurrC_Amp_f32(CDD_CorrMtrCurrC_Amps_G_f32[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MtrCurrQax_Amp_f32(CDD_MtrCurrQax_Amp_G_f32[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MtrCurrDax_Amp_f32(CDD_MtrCurrDax_Amp_G_f32[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_CorrMtrCurrPosition_Rev_f32(CDD_CorrMtrCurrPosition_Rev_G_f32[ReadBuffer_Cnt_T_u16]);

	/* MotMeclPosn1 */
	Rte_IWrite_CDDInterface_Per1_MotMeclPosn1MeasdTi_USec_u32(CDD_MotMeclPosn1MeasdTi_uS_G_u32[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MotMeclPosn1RevM_Rev_u0p16(CDD_MotMeclPosn1RevM_G_u0p16[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MotMeclPosn1RollgCntr_Cnt_u08(CDD_MotMeclPosn1RollgCntr_Cnt_G_u08[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MotMeclPosn1RawErrReg_Cnt_u16(CDD_MotMeclPosn1RawErrReg_Cnt_G_u16[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16(CDD_MotMeclPosn1UnderVltgFaultAccum_Cnt_G_u16[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MotMeclPosn1ParityFaultAccum_Cnt_u16(CDD_MotMeclPosn1ParityFaultAccum_Cnt_G_u16[ReadBuffer_Cnt_T_u16]);

	/* MotMeclPosn2 */
	Rte_IWrite_CDDInterface_Per1_MotMeclPosn2MeasdTi_USec_u32(CDD_MotMeclPosn1MeasdTi_uS_G_u32[ReadBuffer_Cnt_T_u16]); /* Using timer from MotMeclPosn1 */
	Rte_IWrite_CDDInterface_Per1_MotMeclPosn2RevM_Rev_u0p16(CDD_MotMeclPosn2RevM_G_u0p16[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MotMeclPosn2RollgCntr_Cnt_u08(CDD_MotMeclPosn2RollgCntr_Cnt_G_u08[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MotMeclPosn2RawErrReg_Cnt_u16(CDD_MotMeclPosn2RawErrReg_Cnt_G_u16[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16(CDD_MotMeclPosn2UnderVltgFaultAccum_Cnt_G_u16[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MotMeclPosn2ParityFaultAccum_Cnt_u16(CDD_MotMeclPosn2ParityFaultAccum_Cnt_G_u16[ReadBuffer_Cnt_T_u16]);

	/* MotPosnCmp */
	Rte_IWrite_CDDInterface_Per1_MotPosnCmpMotPosnElec_Rev_u0p16(CDD_MotPosnElec_Rev_G_u0p16[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MotPosnCmpMotPosnCumvAlgnd_Rev_f32(FPM_FixedToFloat_m((CDD_MotPosnCumvAlgnd_Rev_G_s15p16[ReadBuffer_Cnt_T_u16]), s15p16_T));

	/* DigMSBArbn */
	Rte_IWrite_CDDInterface_Per1_DigMSBArbnMtrPosMecl_Rev_f32(FPM_FixedToFloat_m(CDD_MtrPosMecl_RevM_G_u0p16[ReadBuffer_Cnt_T_u16], u0p16_T));

	/* MtrCtrl */
	PhaseAdvFinal_Cnt_T_u16 = CDD_BufferedPhaseAdvFinal_Cnt_G_u16[ReadBuffer_Cnt_T_u16];

	if( PhaseAdvFinal_Cnt_T_u16 >= D_HALFREV_CNT_U16 )
	{
		PhaseAdvFinal_Cnt_T_s16 = (sint16)(((float32)(((sint32)PhaseAdvFinal_Cnt_T_u16) - D_FULLREV_CNT_S32)) * D_PHSADVSCALE_ULS_F32);
	}
	else
	{
		PhaseAdvFinal_Cnt_T_s16 = (sint16)(((float32)PhaseAdvFinal_Cnt_T_u16) * D_PHSADVSCALE_ULS_F32);
	}

	Rte_IWrite_CDDInterface_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(PhaseAdvFinal_Cnt_T_s16);
	Rte_IWrite_CDDInterface_Per1_ModIdxFinal_Uls_f32(FPM_FixedToFloat_m((CDD_BufferedModIdxFinal_Uls_G_u16p16[ReadBuffer_Cnt_T_u16]), u16p16_T));
	Rte_IWrite_CDDInterface_Per1_MtrCurrQaxFinalRef_Amp_f32(CDD_MtrCurrQaxFinalRef_Amp_G_f32[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MtrCtrlMtrDaxVoltage_Volt_f32(CDD_MtrDaxVoltage_Volt_G_f32[ReadBuffer_Cnt_T_u16]);
	Rte_IWrite_CDDInterface_Per1_MtrCtrlMtrQaxVoltage_Volt_f32(CDD_MtrQaxVoltage_Volt_G_f32[ReadBuffer_Cnt_T_u16]);

	ExpectedOnTimeA_Cnt_T_u32 = CDD_PWMDutyCycleASum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];
	ExpectedOnTimeB_Cnt_T_u32 = CDD_PWMDutyCycleBSum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];
	ExpectedOnTimeC_Cnt_T_u32 = CDD_PWMDutyCycleCSum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];

	/* IoHwAbstractionUse signals */
	SysCBattSwitched1_Cnt_T_u16 = CDD_SysCBattSwitched1_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	SysCBattSwitched2_Cnt_T_u16 = CDD_SysCBattSwitched2_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	SysCT1Adc_Cnt_T_u16 = CDD_SysCT1Adc_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	SysCT2Adc_Cnt_T_u16 = CDD_SysCT2Adc_Cnt_G_u16[ReadBuffer_Cnt_T_u16];

	Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeA_Cnt_u32(ExpectedOnTimeA_Cnt_T_u32);
	Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeB_Cnt_u32(ExpectedOnTimeB_Cnt_T_u32);
	Rte_IWrite_CDDInterface_Per1_ExpectedOnTimeC_Cnt_u32(ExpectedOnTimeC_Cnt_T_u32);

	Rte_IWrite_CDDInterface_Per1_SysCBattSwitched1_Cnt_u16(SysCBattSwitched1_Cnt_T_u16);
	Rte_IWrite_CDDInterface_Per1_SysCBattSwitched2_Cnt_u16(SysCBattSwitched2_Cnt_T_u16);
	Rte_IWrite_CDDInterface_Per1_SysCT1ADC_Cnt_u16(SysCT1Adc_Cnt_T_u16);
	Rte_IWrite_CDDInterface_Per1_SysCT2ADC_Cnt_u16(SysCT2Adc_Cnt_T_u16);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Per2
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
 *   SInt8 Rte_IRead_CDDInterface_Per2_AssistAssemblyPolarity_Cnt_s08(void)
 *   UInt16 Rte_IRead_CDDInterface_Per2_CommOffset_Cnt_u16(void)
 *   Boolean Rte_IRead_CDDInterface_Per2_IvtrLoaMtgtnEn_Cnt_lgc(void)
 *   Float Rte_IRead_CDDInterface_Per2_MRFMtrVel_MtrRadpS_f32(void)
 *   UInt16 Rte_IRead_CDDInterface_Per2_MotAgCorrlnMtrPosCorrlnSts_Cnt_u16(void)
 *   Boolean Rte_IRead_CDDInterface_Per2_MotCurrLoaMtgtnEn_Cnt_lgc(void)
 *   SigQlfr_State_enum Rte_IRead_CDDInterface_Per2_MotMeclPosn1MotPosnQlfr_State_enum(void)
 *   SInt8 Rte_IRead_CDDInterface_Per2_MotMeclPosn1Polarity_Cnt_s08(void)
 *   SigQlfr_State_enum Rte_IRead_CDDInterface_Per2_MotMeclPosn2MotPosnQlfr_State_enum(void)
 *   SInt8 Rte_IRead_CDDInterface_Per2_MotMeclPosn2Polarity_Cnt_s08(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrATempOffset_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrBTempOffset_Volt_f32(void)
 *   Float Rte_IRead_CDDInterface_Per2_MtrCurrCTempOffset_Volt_f32(void)
 *   SInt8 Rte_IRead_CDDInterface_Per2_MtrPosPolarity_Cnt_s08(void)
 *   SInt16 Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_Cnt_s16(void)
 *   Float Rte_IRead_CDDInterface_Per2_Vecu_Volt_f32(void)
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

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface_Per2
 *********************************************************************************************************************/
	volatile VAR(uint16, AUTOMATIC) WriteBuffer_Cnt_T_u16;
	VAR(float32, AUTOMATIC)	MRFMtrVel_MtrRadpS_T_f32;
	VAR(sint8, AUTOMATIC) MtrPosPolarity_Cnt_T_s08;
	VAR(sint8, AUTOMATIC) AssistAssemblyPolarity_Cnt_T_s08;
	VAR(sint16, AUTOMATIC) MtrTrqCmdSign_Cnt_T_s16;
	VAR(float32, AUTOMATIC) Vecu_Volt_T_f32;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SysState_Cnt_T_Enum;

	WriteBuffer_Cnt_T_u16 = (CDD_AppDataFwdPthAccessBfr_Cnt_G_u16 & 1U) ^ 1U;

	/* CmMtrCurr3Phs */
	CDD_MtrCurrATempOffset_Volt_G_f32[WriteBuffer_Cnt_T_u16] = Rte_IRead_CDDInterface_Per2_MtrCurrATempOffset_Volt_f32();
	CDD_MtrCurrBTempOffset_Volt_G_f32[WriteBuffer_Cnt_T_u16] = Rte_IRead_CDDInterface_Per2_MtrCurrBTempOffset_Volt_f32();
	CDD_MtrCurrCTempOffset_Volt_G_f32[WriteBuffer_Cnt_T_u16] = Rte_IRead_CDDInterface_Per2_MtrCurrCTempOffset_Volt_f32();
	CDD_MtrCurrOffComOffset_Cnt_G_u16[WriteBuffer_Cnt_T_u16] = Rte_IRead_CDDInterface_Per2_CommOffset_Cnt_u16();

	/* MotMeclPosn1 */
	CDD_MotMeclPosn1Polarity_Cnt_G_s08[WriteBuffer_Cnt_T_u16] = Rte_IRead_CDDInterface_Per2_MotMeclPosn1Polarity_Cnt_s08();
	CDD_MotMeclPosn1MotPosnQlfrCnt_G_u08[WriteBuffer_Cnt_T_u16] = Rte_IRead_CDDInterface_Per2_MotMeclPosn1MotPosnQlfr_State_enum();

	/* MotMeclPosn2 */
	CDD_MotMeclPosn2Polarity_Cnt_G_s08[WriteBuffer_Cnt_T_u16] = Rte_IRead_CDDInterface_Per2_MotMeclPosn2Polarity_Cnt_s08();
	CDD_MotMeclPosn2MotPosnQlfrCnt_G_u08[WriteBuffer_Cnt_T_u16] = Rte_IRead_CDDInterface_Per2_MotMeclPosn2MotPosnQlfr_State_enum();

	/* MotAgCorrln */
	CDD_MotAgCorrlnMtrPosCorrlnSts_Cnt_G_u16[WriteBuffer_Cnt_T_u16] = Rte_IRead_CDDInterface_Per2_MotAgCorrlnMtrPosCorrlnSts_Cnt_u16();

	/* MtrCtrl */
	CDD_IvtrLoaMtgtnEn_Cnt_G_lgc = Rte_IRead_CDDInterface_Per2_IvtrLoaMtgtnEn_Cnt_lgc();
	CDD_MotCurrLoaMtgtnEn_Cnt_G_lgc = Rte_IRead_CDDInterface_Per2_MotCurrLoaMtgtnEn_Cnt_lgc();

	MRFMtrVel_MtrRadpS_T_f32 = Rte_IRead_CDDInterface_Per2_MRFMtrVel_MtrRadpS_f32();
	MtrPosPolarity_Cnt_T_s08 = Rte_IRead_CDDInterface_Per2_MtrPosPolarity_Cnt_s08();
	AssistAssemblyPolarity_Cnt_T_s08 = Rte_IRead_CDDInterface_Per2_AssistAssemblyPolarity_Cnt_s08();
	MtrTrqCmdSign_Cnt_T_s16 = Rte_IRead_CDDInterface_Per2_MtrTrqCmdSign_Cnt_s16();
	SysState_Cnt_T_Enum=Rte_Mode_SystemState_Mode();
	Vecu_Volt_T_f32=Rte_IRead_CDDInterface_Per2_Vecu_Volt_f32();

	CDD_MRFMtrVel_MtrRadpS_G_f32[WriteBuffer_Cnt_T_u16] = MRFMtrVel_MtrRadpS_T_f32;
	CDD_MtrPosPolarity_Cnt_G_s08[WriteBuffer_Cnt_T_u16] = MtrPosPolarity_Cnt_T_s08;
	CDD_AssistAssemblyPolarity_Cnt_G_s08[WriteBuffer_Cnt_T_u16] = AssistAssemblyPolarity_Cnt_T_s08;
	CDD_SysState_Cnt_G_Enum=SysState_Cnt_T_Enum;
	CDD_Vecu_Volt_G_f32[WriteBuffer_Cnt_T_u16]=Vecu_Volt_T_f32;

	CDD_AppDataFwdPthAccessBfr_Cnt_G_u16 = WriteBuffer_Cnt_T_u16;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface_Per4
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
 *   SInt8 Rte_IRead_CDDInterface_Per4_MtrElecMechPolarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_NVMMotorVariant_Cnt_u08(UInt8 data)
 *   Std_ReturnType Rte_Write_NVMSensorData_Cnt_lgc(Boolean data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface_Per4_BallNutTempEstSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_BallNutTempEstSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_DftAsstTbl_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_DftAsstTbl_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_DisableCEBusNormComm_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_DisableCEBusNormComm_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_DisableHSBusNormComm_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_DisableHSBusNormComm_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_DwnldAsstGain_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface_Per4_DwnldAsstGain_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_FeatureControl_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_FeatureControl_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_FricLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_FricLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_MEC_Cnt_enum(ManufModeType data)
 *   ManufModeType *Rte_IWriteRef_CDDInterface_Per4_MEC_Cnt_enum(void)
 *   void Rte_IWrite_CDDInterface_Per4_MfgDiagInhibit_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_MfgDiagInhibit_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_PosTrajEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_PosTrajEnable_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_PullCompLrnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_PullCompLrnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_SftEndStpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_SftEndStpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_SrlComSvcDft_Cnt_b32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface_Per4_SrlComSvcDft_Cnt_b32(void)
 *   void Rte_IWrite_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(void)
 *   void Rte_IWrite_CDDInterface_Per4_WIRMfgEnabled_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CDDInterface_Per4_WIRMfgEnabled_Cnt_lgc(void)
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
 *   Std_ReturnType Rte_Call_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE_APPL_CODE) CDDInterface_Per4(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface_Per4
 *********************************************************************************************************************/
	VAR(sint8, AUTOMATIC) MtrElecMechPolarity_Cnt_T_s08;
	VAR(boolean, AUTOMATIC) CPID05FeatureEnabled;

	CPID05FeatureEnabled = ApplDescControlCPID_0xAE05_IsFeaturesEnabled();
	MtrElecMechPolarity_Cnt_T_s08 = Rte_IRead_CDDInterface_Per4_MtrElecMechPolarity_Cnt_s08();

	if (MtrElecMechPolarity_Cnt_T_s08 != PrevMtrElecMechPolarity_Cnt_M_s08)
	{
		(void)Rte_Call_CDDPorts_ApplyMtrElecMechPol(MtrElecMechPolarity_Cnt_T_s08);
		PrevMtrElecMechPolarity_Cnt_M_s08 = MtrElecMechPolarity_Cnt_T_s08;
	}

	if ((D_WHLIMBSEL_CNT_U16 == CDD_EOLNxtrWIRSelect_Cnt_G_u16) &&
	    (FALSE == CDD_WIRDisableSvc_Cnt_G_lgc) &&
	    (0U == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTWHLIMBREJ_CNT_B32)) &&
	    ((NxtrMEC_Uls_G_enum != ProductionMode) ||
	     ((NxtrMEC_Uls_G_enum == ProductionMode) && ((Nvm_CMEC_Cnt_u8 == 0U) || (Nvm_CMEC_Cnt_u8 == 0xFFU)))) &&
	    (CPID05FeatureEnabled == TRUE))
	{
		Rte_IWrite_CDDInterface_Per4_WIRMfgEnabled_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_WIRMfgEnabled_Cnt_lgc(FALSE);
	}

	/* MEC funcationality */
 	Rte_IWrite_CDDInterface_Per4_MEC_Cnt_enum(NxtrMEC_Uls_G_enum);

	Rte_IWrite_CDDInterface_Per4_DisableHSBusNormComm_Cnt_lgc(CDD_DisableHSBusNormComm_Cnt_lgc);
	Rte_IWrite_CDDInterface_Per4_DisableCEBusNormComm_Cnt_lgc(CDD_DisableCEBusNormComm_Cnt_lgc);

	/* DiagManager manufacturing defeat funcationality */
	Rte_IWrite_CDDInterface_Per4_MfgDiagInhibit_Cnt_lgc(MfgDiagInhibit_Uls_G_lgc);

	/* DIAGNOSTIC SERVICE INTERFACE - ASSIST GAIN FUNCTION */
	Rte_IWrite_CDDInterface_Per4_DftAsstTbl_Cnt_lgc(CDD_DftAsstTbl_Cnt_G_lgc);
	Rte_IWrite_CDDInterface_Per4_DwnldAsstGain_Uls_f32(CDD_DwnldAsstGain_Uls_G_f32);

	/* DIAGNOSTIC SERVICE INTERFACE - SRLCOMSVC DEFEAT */
	Rte_IWrite_CDDInterface_Per4_SrlComSvcDft_Cnt_b32(CDD_EOLSrlComSvcDft_Cnt_G_b32);

	/* REQUEST TRANSITION TO OPERATE/RUN STATE */
	if ((D_SVCDFTENGON_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTENGON_CNT_B32)) ||
		(CDD_PwrAsstModeSvc_Cnt_G_lgc == TRUE))
	{
		Rte_IWrite_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_EngONSrlComSvcDft_Cnt_lgc(FALSE);
	}


	if (D_SVCDFTFRICLRN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTFRICLRN_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_FricLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_FricLrnSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTKININTDIAG_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTKININTDIAG_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_KinIntDiagSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTTHERMALDC_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTTHERMALDC_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_ThermalDCSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTEOTIMPACT_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTEOTIMPACT_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_EOTImpactSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTEOTTHERMAL_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTEOTTHERMAL_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_EOTThermalSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTMTRVELNRMLRN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTMTRVELNRMLRN_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_MtrVelNrmLrnSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTMTRPARMNRMLRN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTMTRPARMNRMLRN_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTTRQRMP_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTTRQRMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_TrqRmpSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTMODIDX_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTMODIDX_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(TRUE);
		CDD_ModIdxSrlComSvcDft_Cnt_G_u16 = TRUE;
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_ModIdxSrlComSvcDft_Cnt_lgc(FALSE);
		CDD_ModIdxSrlComSvcDft_Cnt_G_u16 = FALSE;
	}

	if ((D_SVCDFTPULLCOMP_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTPULLCOMP_CNT_B32)) ||
		(CDD_PullCompDisableSvc_Cnt_G_lgc == TRUE)
	   )
	{
		Rte_IWrite_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_PullCompSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTPARKAST_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTPARKAST_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_ParkAstSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTDRIVINGDYN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTDRIVINGDYN_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_DrivingDynSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTHYSTCOMP_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTHYSTCOMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_HystCompSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTHYSTADD_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTHYSTADD_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_HysAddSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTRETURN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTRETURN_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_ReturnSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTDAMPING_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTDAMPING_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_DampingSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTLIMIT_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTLIMIT_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_LimitSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTPULLCOMPLRN_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTPULLCOMPLRN_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_PullCompLrnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_PullCompLrnSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (D_SVCDFTFREQDEPDMP_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTFREQDEPDMP_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_FreqDepDmpSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (CDD_BallNutTempEstDisableSvc_Cnt_G_lgc == TRUE)
	{
		Rte_IWrite_CDDInterface_Per4_BallNutTempEstSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_BallNutTempEstSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (CDD_SftEndStpDisableSvc_Cnt_G_lgc == TRUE)
	{
		Rte_IWrite_CDDInterface_Per4_SftEndStpSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_SftEndStpSrlComSvcDft_Cnt_lgc(FALSE);
	}

	/* DEFEAT RECEPTION OF SRLCOMINPUT MESSAGES */
	if (D_SVCDFTRXMSGS_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTRXMSGS_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_RxMsgsSrlComSvcDft_Cnt_lgc(FALSE);
	}

	/* MULTIPLE IGNITION CYCLE DEFEATS - store EOLSrlComSvcDft */
	if (D_SVCDFTMULTIGNMASK_CNT_B32 == (CDD_EOLSrlComSvcDft_Cnt_G_b32 & D_SVCDFTMULTIGNMASK_CNT_B32))
	{
		Rte_IWrite_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_MultIgnSrlComSvcDft_Cnt_lgc(FALSE);
	}

	if (CDD_GenPosTrajEnableFlag_Cnt_G_lgc == TRUE)
	{
		Rte_IWrite_CDDInterface_Per4_PosTrajEnable_Cnt_lgc(TRUE);
	}
	else
	{
		Rte_IWrite_CDDInterface_Per4_PosTrajEnable_Cnt_lgc(FALSE);
	}

	(void)Rte_Write_NVMSensorData_Cnt_lgc(Nvm_GetSensorData_Cnt_lgc);
	(void)Rte_Write_NVMMotorVariant_Cnt_u08(Nvm_MotorVariant_Cnt_u8);
	
	(void)Rte_Write_MotorVariant_Cnt_u16((uint16)Nvm_MotorVariant_Cnt_u8);
	(void)Rte_IWrite_CDDInterface_Per4_FeatureControl_Cnt_lgc(CPID05FeatureEnabled);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_CDDINTERFACE_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(void, CDDInterface_CODE) CDDPorts_ApplyMtrElecMechPol(sint8 MtrElecMechPol_Cnt_s8)
{
	CDD_MtrElecPol_Cnt_G_s8=MtrElecMechPol_Cnt_s8;
	CDD_ApplyPWMMtrElecMechPol(CDD_MtrElecPol_Cnt_G_s8);
}

/*
 * Periodic function for MotorControl ISR 125us
 */
FUNC(void, CDDInterface_CODE) CDDInterface_Per5(void)
{
	CDD_BufferedModIdxFinal_Uls_G_u16p16[CDD_CDDDataAccessBfr_Cnt_G_u16] = CDD_ModIdxFinal_Uls_G_u16p16;
	CDD_BufferedPhaseAdvFinal_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16] = CDD_PhaseAdvFinal_Cnt_G_u16;
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
