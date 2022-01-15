/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_ElePwr.c
 *     Workspace:  C:/Synergy_KK/working/ElePwr-nz4qtt/ElePwr/autosar
 *     SW-C Type:  Ap_ElePwr
 *  Generated at:  Mon Mar 23 14:05:55 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nexteer  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_ElePwr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Nov 29 18:34:17 2012
 * %version:          6 %
 * %date_modified:    Mon Nov 29 18:34:17 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 12/10/12	 1		  Selva		Initial Release for this component. SF-008
 * 04/02/14  2        SB		Anomaly 6244 Limit Outputs														11667
 * 05/08/14	 3-4      SB        Changed Vecu Initial value from 0 to 5, Updated per Design Review				11667
 * 03/05/15	 5	      KK        Implementation of FDD v 002														13095
 * 03/23/15	 6	      KK        Implementation of FDD v 003														13155
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

 *********************************************************************************************************************/

#include "Rte_Ap_ElePwr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "GlobalMacro.h"
#include "CalConstants.h"

/* MISRA-C:2004 Rule 8.7: Deviation required for the display variables and filter constants because of memory map */

/* MISRA-C:2004 Rule 19.1: Deviation required for the AUTOSAR Compliance */


#define D_SQRT3OVR2_ULS_F32					0.866025403784F
#define D_ELECPOWERLOLMT_WATT_F32			(-2000.0f)
#define D_ELECPOWERHILMT_WATT_F32			2000.0F
#define D_SUPPLYCURRENTLOLMT_AMP_F32  		(-200.0f)
#define D_SUPPLYCURRENTHILMT_AMP_F32  		200.0F

#define ELEPWR_START_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */
STATIC volatile VAR(float32, AP_BATTLOADEST_VAR_NOINIT)	ElePwr_ModInPower_Watt_D_f32;  	/* PRQA S 3218 */
STATIC volatile VAR(float32, AP_BATTLOADEST_VAR_NOINIT) ElePwr_DropInPower_Watt_D_f32; 	/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) ElePwr_MtrCurrQaxEst_Amp_D_f32;					/* PRQA S 3218 */
STATIC volatile VAR(float32, AUTOMATIC) ElePwr_MtrCurrDaxEst_Amp_D_f32;					/* PRQA S 3218 */
#define ELEPWR_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"/* PRQA S 5087 */

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
 * Float: D_VECUMIN_VOLTS_F32 = 5
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_ELEPWR_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ElePwr_Per1
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
 *   Boolean Rte_IRead_ElePwr_Per1_IvtrLoaMtgtnEn_Cnt_lgc(void)
 *   Boolean Rte_IRead_ElePwr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc(void)
 *   Float Rte_IRead_ElePwr_Per1_MtrCurrDaxRef_Amp_f32(void)
 *   Float Rte_IRead_ElePwr_Per1_MtrCurrDax_Amp_f32(void)
 *   Float Rte_IRead_ElePwr_Per1_MtrCurrQaxFinalRef_Amp_f32(void)
 *   Float Rte_IRead_ElePwr_Per1_MtrCurrQax_Amp_f32(void)
 *   Float Rte_IRead_ElePwr_Per1_MtrVoltDax_Volt_f32(void)
 *   Float Rte_IRead_ElePwr_Per1_MtrVoltQax_Volt_f32(void)
 *   Float Rte_IRead_ElePwr_Per1_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ElePwr_Per1_ElectricPower_Watt_f32(Float data)
 *   Float *Rte_IWriteRef_ElePwr_Per1_ElectricPower_Watt_f32(void)
 *   void Rte_IWrite_ElePwr_Per1_SupplyCurrent_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_ElePwr_Per1_SupplyCurrent_Amp_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ELEPWR_APPL_CODE) ElePwr_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ElePwr_Per1
 *********************************************************************************************************************/
 VAR(float32, AUTOMATIC) Vecu_Volt_T_f32;
 VAR(float32, AUTOMATIC) MtrCurrDax_Amp_T_f32;
 VAR(float32, AUTOMATIC) MtrCurrQax_Amp_T_f32;
 VAR(float32, AUTOMATIC) MtrVoltDax_Volt_T_f32;
 VAR(float32, AUTOMATIC) MtrVoltQax_Volt_T_f32;
 VAR(float32, AUTOMATIC) ModInPower_Watt_T_f32;
 VAR(float32, AUTOMATIC) DropInPower_Watt_T_f32;
 VAR(float32, AUTOMATIC) DropInPower_Amp_T_f32;
 VAR(float32, AUTOMATIC) ElecPower_Watt_T_f32;
 VAR(float32, AUTOMATIC) SupplyCurrent_Amp_T_f32;
 VAR(float32, AUTOMATIC) MtrCurrQaxFinalRef_Amp_T_f32;
 VAR(float32, AUTOMATIC) MtrCurrDaxRef_Amp_T_f32;
 VAR(boolean, AUTOMATIC) MotCurrLoaMtgtnEn_Cnt_T_lgc;
 VAR(boolean, AUTOMATIC) IvtrLoaMtgtnEn_Cnt_T_lgc;
  
	
	/* Capture inputs */
	Vecu_Volt_T_f32 				= Rte_IRead_ElePwr_Per1_Vecu_Volt_f32();
    MtrCurrDax_Amp_T_f32			= Rte_IRead_ElePwr_Per1_MtrCurrDax_Amp_f32();
    MtrCurrQax_Amp_T_f32			= Rte_IRead_ElePwr_Per1_MtrCurrQax_Amp_f32();
    MtrVoltDax_Volt_T_f32			= Rte_IRead_ElePwr_Per1_MtrVoltDax_Volt_f32();
    MtrVoltQax_Volt_T_f32			= Rte_IRead_ElePwr_Per1_MtrVoltQax_Volt_f32();
    MtrCurrQaxFinalRef_Amp_T_f32	= Rte_IRead_ElePwr_Per1_MtrCurrQaxFinalRef_Amp_f32();
    MtrCurrDaxRef_Amp_T_f32			= Rte_IRead_ElePwr_Per1_MtrCurrDaxRef_Amp_f32();
    MotCurrLoaMtgtnEn_Cnt_T_lgc 	= Rte_IRead_ElePwr_Per1_MotCurrLoaMtgtnEn_Cnt_lgc();
    IvtrLoaMtgtnEn_Cnt_T_lgc		= Rte_IRead_ElePwr_Per1_IvtrLoaMtgtnEn_Cnt_lgc();

    /*** Input selection in case of LOA fault due to current sensor failure **/

    if( (D_FALSE_CNT_LGC != MotCurrLoaMtgtnEn_Cnt_T_lgc)||
    	(D_FALSE_CNT_LGC != IvtrLoaMtgtnEn_Cnt_T_lgc) )

    	{
    		MtrCurrQax_Amp_T_f32 = MtrCurrQaxFinalRef_Amp_T_f32;
    		MtrCurrDax_Amp_T_f32 = MtrCurrDaxRef_Amp_T_f32;
    	}


    /*** Update of display variables  **/
    ElePwr_MtrCurrQaxEst_Amp_D_f32 = MtrCurrQax_Amp_T_f32;
    ElePwr_MtrCurrDaxEst_Amp_D_f32 = MtrCurrDax_Amp_T_f32;

	/*** Calculate Modin  Power **/
	/*** modinpwr=sqrt(3)/2 *(vq*iq+vd*id) ***/
	ModInPower_Watt_T_f32 = (MtrCurrDax_Amp_T_f32 * MtrVoltDax_Volt_T_f32) + (MtrCurrQax_Amp_T_f32 * MtrVoltQax_Volt_T_f32);
	ModInPower_Watt_T_f32 = ModInPower_Watt_T_f32 * D_SQRT3OVR2_ULS_F32;
	ElePwr_ModInPower_Watt_D_f32 = ModInPower_Watt_T_f32;
	
	/*** Calculate Modin  Power **/
	/*** dropinper =(modinpwr/vecu)^2 *CntrlInResist ***/
	DropInPower_Amp_T_f32 = ModInPower_Watt_T_f32 / Vecu_Volt_T_f32;
	DropInPower_Watt_T_f32 = DropInPower_Amp_T_f32 * DropInPower_Amp_T_f32 * k_CntlrInResist_Ohm_f32;
	
	ElePwr_DropInPower_Watt_D_f32 =DropInPower_Watt_T_f32;

	/*** Calculate the ElectricPower Module ***/
	ElecPower_Watt_T_f32 = ModInPower_Watt_T_f32 + DropInPower_Watt_T_f32 + k_PstcPowerLoss_Watt_f32;
	ElecPower_Watt_T_f32 = Limit_m(ElecPower_Watt_T_f32, D_ELECPOWERLOLMT_WATT_F32, D_ELECPOWERHILMT_WATT_F32);
	
	/*** Calculate the supply current ***/
	SupplyCurrent_Amp_T_f32 = ElecPower_Watt_T_f32/ Vecu_Volt_T_f32;
	SupplyCurrent_Amp_T_f32 = Limit_m(SupplyCurrent_Amp_T_f32, D_SUPPLYCURRENTLOLMT_AMP_F32, D_SUPPLYCURRENTHILMT_AMP_F32);
	
	/*** Write the output data ***/
	Rte_IWrite_ElePwr_Per1_ElectricPower_Watt_f32(ElecPower_Watt_T_f32);
	Rte_IWrite_ElePwr_Per1_SupplyCurrent_Amp_f32(SupplyCurrent_Amp_T_f32);
	
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_ELEPWR_APPL_CODE
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
