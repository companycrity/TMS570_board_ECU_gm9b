/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_VehPwrMd.c
 *     Workspace:  C:/_synergy/9BXX_CZ8L9T/GM_9BXX_EPS_TMS570/SwProject/VehPwrMd/autosar
 *     SW-C Type:  Ap_VehPwrMd
 *  Generated at:  Wed Mar 23 16:10:21 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_VehPwrMd>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#6 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Mon Jul 29 08:44:06 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 11/24/15  3        GMN       EA3#4066: New conditions to C and A Term                                      4381
 * 03/24/16  4        GMN       EA3#6352: Deleted C-Term latch condition                                      EA3#7050
 *                              EA3#5868: Added two outputs Dflt Veh Spd Ena and Sy Op Motor Trq Commd Scale  EA3#
 *                              EA3#5870: Changed calibration for vehicle speed checks                        EA3#
 * 08/30/16  5        GMN       EA3#10213: Added HW Torque as input of KeepAssist table                       EA3#10598
 * 09/13/16  6        GMN       EA3#10213: Changed the KeepAssist table                                       EA3#10914
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

#include "Rte_Ap_VehPwrMd.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "filters.h"
#include "can_inc.h"
#include "Dem.h"
#include "CDD_Data.h"
#include "CalConstants.h"
#include "Ap_VehPwrMd_Cfg.h"

/* MISRA-C: 2004 Rules 8.7 File scope static variable is only accessed in one function. */
/* PRQA S 3218 EOF */
/* MISRA-C: 2004 Rules 12.10 /14.2: Use of comma operator. Used by the RTE functions */
/* PRQA S 3417, 3426 EOF */

/*
 * States when would be considered safe to remove assist based only on torque.
 */
typedef enum {
	HWTRQNOTPRESENT = 0, /* Hand wheel torque not present but still not safe to remove assist */
	HWTRQPRESENT,        /* Hand wheel torque present */
	HWTRQSAFETOOFF       /* Hand wheel torque not present for a certain time, safe to remove assist */
} VehPwMd_HwTorqueStateEnum;

#define VEHPWRMD_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_VEHPWRMD_VAR_NOINIT) VehPwrMd_CTermActive_Cnt_M_lgc;
#define VEHPWRMD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define VEHPWRMD_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(VehPwMd_HwTorqueStateEnum, AP_VEHPWRMD_VAR_NOINIT) VehPwrMd_HwTorqueSt_Cnt_M_enum;
STATIC VAR(LPF32KSV_Str, AP_VEHPWRMD_VAR_NOINIT) VehPwMd_HwTorqueLPF_M_str;
#define VEHPWRMD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define VEHPWRMD_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC volatile VAR(uint16, AP_VEHPWRMD_VAR_NOINIT) VehPwrMd_Assist_Cnt_D_u16;
#define VEHPWRMD_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define VEHPWRMD_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, AP_VEHPWRMD_VAR_NOINIT) VehPwrMd_IGNDiagStartTime_mS_M_u32p0;
STATIC VAR(uint32, AP_VEHPWRMD_VAR_NOINIT) VehPwrMd_HwTorqueTimer_mS_T_u32p0;
STATIC VAR(float32, AP_VEHPWRMD_VAR_NOINIT) VehPwrMd_PrevTqValue_HwNm_M_f32;
STATIC volatile VAR(float32, AP_VEHPWRMD_VAR_NOINIT) VehPwrMd_TqValue_HwNm_D_f32;
STATIC volatile VAR(float32, AP_VEHPWRMD_VAR_NOINIT) VehPwrMd_TqAverage_HwNm_M_f32;
#define VEHPWRMD_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define VEHPWRMD_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
/*
 * System State Request Enable output for the Keep Assist Truth Table.
 *
 * -----------------> 8: Comm Enable (1 = On)
 * | ---------------> 7: System Power Mode Run (1 = Run)
 * | | -------------> 6: Engine Run Active (1 = On)
 * | | | -----------> 5: Vehcile Speed > then calibration value
 * | | | | ---------> 4: Missing Message 0C9
 * | | | | | -------> 3: Vehicle Speed Sensor Valid
 * | | | | | | -----> 2: Missing message 1F1
 * | | | | | | | ---> 1: HS Bus Off
 * | | | | | | | | -> 0: Steering Torque
 * 0 0 0 0 0 0 0 0 0
 *
 * NOTE: Please check the file "CF-17 VehPwrMd Calculator.xlsx" on how to generate this table.
 */
STATIC CONST(uint8, AP_VEHPWRMD_VAR) T_VehPwrMdSystemState_Cnt_u08[512] =
{
	0U, /* 000000000 */
	0U, /* 000000001 */
	0U, /* 000000010 */
	1U, /* 000000011 */
	0U, /* 000000100 */
	0U, /* 000000101 */
	0U, /* 000000110 */
	1U, /* 000000111 */
	0U, /* 000001000 */
	0U, /* 000001001 */
	0U, /* 000001010 */
	1U, /* 000001011 */
	0U, /* 000001100 */
	0U, /* 000001101 */
	0U, /* 000001110 */
	1U, /* 000001111 */
	0U, /* 000010000 */
	1U, /* 000010001 */
	0U, /* 000010010 */
	1U, /* 000010011 */
	0U, /* 000010100 */
	1U, /* 000010101 */
	0U, /* 000010110 */
	1U, /* 000010111 */
	0U, /* 000011000 */
	1U, /* 000011001 */
	0U, /* 000011010 */
	1U, /* 000011011 */
	0U, /* 000011100 */
	1U, /* 000011101 */
	0U, /* 000011110 */
	1U, /* 000011111 */
	0U, /* 000100000 */
	0U, /* 000100001 */
	0U, /* 000100010 */
	1U, /* 000100011 */
	0U, /* 000100100 */
	0U, /* 000100101 */
	0U, /* 000100110 */
	1U, /* 000100111 */
	1U, /* 000101000 */
	1U, /* 000101001 */
	0U, /* 000101010 */
	1U, /* 000101011 */
	1U, /* 000101100 */
	1U, /* 000101101 */
	0U, /* 000101110 */
	1U, /* 000101111 */
	0U, /* 000110000 */
	1U, /* 000110001 */
	0U, /* 000110010 */
	1U, /* 000110011 */
	0U, /* 000110100 */
	1U, /* 000110101 */
	0U, /* 000110110 */
	1U, /* 000110111 */
	1U, /* 000111000 */
	1U, /* 000111001 */
	0U, /* 000111010 */
	1U, /* 000111011 */
	1U, /* 000111100 */
	1U, /* 000111101 */
	0U, /* 000111110 */
	1U, /* 000111111 */
	1U, /* 001000000 */
	1U, /* 001000001 */
	0U, /* 001000010 */
	1U, /* 001000011 */
	1U, /* 001000100 */
	1U, /* 001000101 */
	0U, /* 001000110 */
	1U, /* 001000111 */
	1U, /* 001001000 */
	1U, /* 001001001 */
	0U, /* 001001010 */
	1U, /* 001001011 */
	1U, /* 001001100 */
	1U, /* 001001101 */
	0U, /* 001001110 */
	1U, /* 001001111 */
	0U, /* 001010000 */
	1U, /* 001010001 */
	0U, /* 001010010 */
	1U, /* 001010011 */
	0U, /* 001010100 */
	1U, /* 001010101 */
	0U, /* 001010110 */
	1U, /* 001010111 */
	0U, /* 001011000 */
	1U, /* 001011001 */
	0U, /* 001011010 */
	1U, /* 001011011 */
	0U, /* 001011100 */
	1U, /* 001011101 */
	0U, /* 001011110 */
	1U, /* 001011111 */
	1U, /* 001100000 */
	1U, /* 001100001 */
	0U, /* 001100010 */
	1U, /* 001100011 */
	1U, /* 001100100 */
	1U, /* 001100101 */
	0U, /* 001100110 */
	1U, /* 001100111 */
	1U, /* 001101000 */
	1U, /* 001101001 */
	0U, /* 001101010 */
	1U, /* 001101011 */
	1U, /* 001101100 */
	1U, /* 001101101 */
	0U, /* 001101110 */
	1U, /* 001101111 */
	0U, /* 001110000 */
	1U, /* 001110001 */
	0U, /* 001110010 */
	1U, /* 001110011 */
	0U, /* 001110100 */
	1U, /* 001110101 */
	0U, /* 001110110 */
	1U, /* 001110111 */
	1U, /* 001111000 */
	1U, /* 001111001 */
	0U, /* 001111010 */
	1U, /* 001111011 */
	1U, /* 001111100 */
	1U, /* 001111101 */
	0U, /* 001111110 */
	1U, /* 001111111 */
	1U, /* 010000000 */
	0U, /* 010000001 */
	0U, /* 010000010 */
	1U, /* 010000011 */
	0U, /* 010000100 */
	0U, /* 010000101 */
	0U, /* 010000110 */
	1U, /* 010000111 */
	0U, /* 010001000 */
	0U, /* 010001001 */
	0U, /* 010001010 */
	1U, /* 010001011 */
	0U, /* 010001100 */
	0U, /* 010001101 */
	0U, /* 010001110 */
	1U, /* 010001111 */
	1U, /* 010010000 */
	1U, /* 010010001 */
	0U, /* 010010010 */
	1U, /* 010010011 */
	0U, /* 010010100 */
	1U, /* 010010101 */
	0U, /* 010010110 */
	1U, /* 010010111 */
	0U, /* 010011000 */
	1U, /* 010011001 */
	0U, /* 010011010 */
	1U, /* 010011011 */
	0U, /* 010011100 */
	1U, /* 010011101 */
	0U, /* 010011110 */
	1U, /* 010011111 */
	1U, /* 010100000 */
	0U, /* 010100001 */
	0U, /* 010100010 */
	1U, /* 010100011 */
	0U, /* 010100100 */
	0U, /* 010100101 */
	0U, /* 010100110 */
	1U, /* 010100111 */
	1U, /* 010101000 */
	1U, /* 010101001 */
	0U, /* 010101010 */
	1U, /* 010101011 */
	1U, /* 010101100 */
	1U, /* 010101101 */
	0U, /* 010101110 */
	1U, /* 010101111 */
	1U, /* 010110000 */
	1U, /* 010110001 */
	0U, /* 010110010 */
	1U, /* 010110011 */
	0U, /* 010110100 */
	1U, /* 010110101 */
	0U, /* 010110110 */
	1U, /* 010110111 */
	1U, /* 010111000 */
	1U, /* 010111001 */
	0U, /* 010111010 */
	1U, /* 010111011 */
	1U, /* 010111100 */
	1U, /* 010111101 */
	0U, /* 010111110 */
	1U, /* 010111111 */
	1U, /* 011000000 */
	1U, /* 011000001 */
	0U, /* 011000010 */
	1U, /* 011000011 */
	1U, /* 011000100 */
	1U, /* 011000101 */
	0U, /* 011000110 */
	1U, /* 011000111 */
	1U, /* 011001000 */
	1U, /* 011001001 */
	0U, /* 011001010 */
	1U, /* 011001011 */
	1U, /* 011001100 */
	1U, /* 011001101 */
	0U, /* 011001110 */
	1U, /* 011001111 */
	1U, /* 011010000 */
	1U, /* 011010001 */
	0U, /* 011010010 */
	1U, /* 011010011 */
	0U, /* 011010100 */
	1U, /* 011010101 */
	0U, /* 011010110 */
	1U, /* 011010111 */
	0U, /* 011011000 */
	1U, /* 011011001 */
	0U, /* 011011010 */
	1U, /* 011011011 */
	0U, /* 011011100 */
	1U, /* 011011101 */
	0U, /* 011011110 */
	1U, /* 011011111 */
	1U, /* 011100000 */
	1U, /* 011100001 */
	0U, /* 011100010 */
	1U, /* 011100011 */
	1U, /* 011100100 */
	1U, /* 011100101 */
	0U, /* 011100110 */
	1U, /* 011100111 */
	1U, /* 011101000 */
	1U, /* 011101001 */
	0U, /* 011101010 */
	1U, /* 011101011 */
	1U, /* 011101100 */
	1U, /* 011101101 */
	0U, /* 011101110 */
	1U, /* 011101111 */
	1U, /* 011110000 */
	1U, /* 011110001 */
	0U, /* 011110010 */
	1U, /* 011110011 */
	0U, /* 011110100 */
	1U, /* 011110101 */
	0U, /* 011110110 */
	1U, /* 011110111 */
	1U, /* 011111000 */
	1U, /* 011111001 */
	0U, /* 011111010 */
	1U, /* 011111011 */
	1U, /* 011111100 */
	1U, /* 011111101 */
	0U, /* 011111110 */
	1U, /* 011111111 */
	1U, /* 100000000 */
	1U, /* 100000001 */
	1U, /* 100000010 */
	1U, /* 100000011 */
	1U, /* 100000100 */
	1U, /* 100000101 */
	1U, /* 100000110 */
	1U, /* 100000111 */
	0U, /* 100001000 */
	0U, /* 100001001 */
	1U, /* 100001010 */
	1U, /* 100001011 */
	1U, /* 100001100 */
	1U, /* 100001101 */
	1U, /* 100001110 */
	1U, /* 100001111 */
	1U, /* 100010000 */
	1U, /* 100010001 */
	1U, /* 100010010 */
	1U, /* 100010011 */
	1U, /* 100010100 */
	1U, /* 100010101 */
	1U, /* 100010110 */
	1U, /* 100010111 */
	1U, /* 100011000 */
	1U, /* 100011001 */
	1U, /* 100011010 */
	1U, /* 100011011 */
	1U, /* 100011100 */
	1U, /* 100011101 */
	1U, /* 100011110 */
	1U, /* 100011111 */
	1U, /* 100100000 */
	1U, /* 100100001 */
	1U, /* 100100010 */
	1U, /* 100100011 */
	1U, /* 100100100 */
	1U, /* 100100101 */
	1U, /* 100100110 */
	1U, /* 100100111 */
	1U, /* 100101000 */
	1U, /* 100101001 */
	1U, /* 100101010 */
	1U, /* 100101011 */
	1U, /* 100101100 */
	1U, /* 100101101 */
	1U, /* 100101110 */
	1U, /* 100101111 */
	1U, /* 100110000 */
	1U, /* 100110001 */
	1U, /* 100110010 */
	1U, /* 100110011 */
	1U, /* 100110100 */
	1U, /* 100110101 */
	1U, /* 100110110 */
	1U, /* 100110111 */
	1U, /* 100111000 */
	1U, /* 100111001 */
	1U, /* 100111010 */
	1U, /* 100111011 */
	1U, /* 100111100 */
	1U, /* 100111101 */
	1U, /* 100111110 */
	1U, /* 100111111 */
	1U, /* 101000000 */
	1U, /* 101000001 */
	1U, /* 101000010 */
	1U, /* 101000011 */
	1U, /* 101000100 */
	1U, /* 101000101 */
	1U, /* 101000110 */
	1U, /* 101000111 */
	1U, /* 101001000 */
	1U, /* 101001001 */
	1U, /* 101001010 */
	1U, /* 101001011 */
	1U, /* 101001100 */
	1U, /* 101001101 */
	1U, /* 101001110 */
	1U, /* 101001111 */
	1U, /* 101010000 */
	1U, /* 101010001 */
	1U, /* 101010010 */
	1U, /* 101010011 */
	1U, /* 101010100 */
	1U, /* 101010101 */
	1U, /* 101010110 */
	1U, /* 101010111 */
	1U, /* 101011000 */
	1U, /* 101011001 */
	1U, /* 101011010 */
	1U, /* 101011011 */
	1U, /* 101011100 */
	1U, /* 101011101 */
	1U, /* 101011110 */
	1U, /* 101011111 */
	1U, /* 101100000 */
	1U, /* 101100001 */
	1U, /* 101100010 */
	1U, /* 101100011 */
	1U, /* 101100100 */
	1U, /* 101100101 */
	1U, /* 101100110 */
	1U, /* 101100111 */
	1U, /* 101101000 */
	1U, /* 101101001 */
	1U, /* 101101010 */
	1U, /* 101101011 */
	1U, /* 101101100 */
	1U, /* 101101101 */
	1U, /* 101101110 */
	1U, /* 101101111 */
	1U, /* 101110000 */
	1U, /* 101110001 */
	1U, /* 101110010 */
	1U, /* 101110011 */
	1U, /* 101110100 */
	1U, /* 101110101 */
	1U, /* 101110110 */
	1U, /* 101110111 */
	1U, /* 101111000 */
	1U, /* 101111001 */
	1U, /* 101111010 */
	1U, /* 101111011 */
	1U, /* 101111100 */
	1U, /* 101111101 */
	1U, /* 101111110 */
	1U, /* 101111111 */
	1U, /* 110000000 */
	1U, /* 110000001 */
	1U, /* 110000010 */
	1U, /* 110000011 */
	1U, /* 110000100 */
	1U, /* 110000101 */
	1U, /* 110000110 */
	1U, /* 110000111 */
	0U, /* 110001000 */
	0U, /* 110001001 */
	1U, /* 110001010 */
	1U, /* 110001011 */
	1U, /* 110001100 */
	1U, /* 110001101 */
	1U, /* 110001110 */
	1U, /* 110001111 */
	1U, /* 110010000 */
	1U, /* 110010001 */
	1U, /* 110010010 */
	1U, /* 110010011 */
	1U, /* 110010100 */
	1U, /* 110010101 */
	1U, /* 110010110 */
	1U, /* 110010111 */
	1U, /* 110011000 */
	1U, /* 110011001 */
	1U, /* 110011010 */
	1U, /* 110011011 */
	1U, /* 110011100 */
	1U, /* 110011101 */
	1U, /* 110011110 */
	1U, /* 110011111 */
	1U, /* 110100000 */
	1U, /* 110100001 */
	1U, /* 110100010 */
	1U, /* 110100011 */
	1U, /* 110100100 */
	1U, /* 110100101 */
	1U, /* 110100110 */
	1U, /* 110100111 */
	1U, /* 110101000 */
	1U, /* 110101001 */
	1U, /* 110101010 */
	1U, /* 110101011 */
	1U, /* 110101100 */
	1U, /* 110101101 */
	1U, /* 110101110 */
	1U, /* 110101111 */
	1U, /* 110110000 */
	1U, /* 110110001 */
	1U, /* 110110010 */
	1U, /* 110110011 */
	1U, /* 110110100 */
	1U, /* 110110101 */
	1U, /* 110110110 */
	1U, /* 110110111 */
	1U, /* 110111000 */
	1U, /* 110111001 */
	1U, /* 110111010 */
	1U, /* 110111011 */
	1U, /* 110111100 */
	1U, /* 110111101 */
	1U, /* 110111110 */
	1U, /* 110111111 */
	1U, /* 111000000 */
	1U, /* 111000001 */
	1U, /* 111000010 */
	1U, /* 111000011 */
	1U, /* 111000100 */
	1U, /* 111000101 */
	1U, /* 111000110 */
	1U, /* 111000111 */
	1U, /* 111001000 */
	1U, /* 111001001 */
	1U, /* 111001010 */
	1U, /* 111001011 */
	1U, /* 111001100 */
	1U, /* 111001101 */
	1U, /* 111001110 */
	1U, /* 111001111 */
	1U, /* 111010000 */
	1U, /* 111010001 */
	1U, /* 111010010 */
	1U, /* 111010011 */
	1U, /* 111010100 */
	1U, /* 111010101 */
	1U, /* 111010110 */
	1U, /* 111010111 */
	1U, /* 111011000 */
	1U, /* 111011001 */
	1U, /* 111011010 */
	1U, /* 111011011 */
	1U, /* 111011100 */
	1U, /* 111011101 */
	1U, /* 111011110 */
	1U, /* 111011111 */
	1U, /* 111100000 */
	1U, /* 111100001 */
	1U, /* 111100010 */
	1U, /* 111100011 */
	1U, /* 111100100 */
	1U, /* 111100101 */
	1U, /* 111100110 */
	1U, /* 111100111 */
	1U, /* 111101000 */
	1U, /* 111101001 */
	1U, /* 111101010 */
	1U, /* 111101011 */
	1U, /* 111101100 */
	1U, /* 111101101 */
	1U, /* 111101110 */
	1U, /* 111101111 */
	1U, /* 111110000 */
	1U, /* 111110001 */
	1U, /* 111110010 */
	1U, /* 111110011 */
	1U, /* 111110100 */
	1U, /* 111110101 */
	1U, /* 111110110 */
	1U, /* 111110111 */
	1U, /* 111111000 */
	1U, /* 111111001 */
	1U, /* 111111010 */
	1U, /* 111111011 */
	1U, /* 111111100 */
	1U, /* 111111101 */
	1U, /* 111111110 */
	1U, /* 111111111 */
};

/*
 * Variable Effort output for the Keep Assist Truth Table.
 *
 * -----------------> 8: Comm Enable (1 = On)
 * | ---------------> 7: System Power Mode Run (1 = Run)
 * | | -------------> 6: Engine Run Active (1 = On)
 * | | | -----------> 5: Vehcile Speed > then calibration value
 * | | | | ---------> 4: Missing Message 0C9
 * | | | | | -------> 3: Vehicle Speed Sensor Valid
 * | | | | | | -----> 2: Missing message 1F1
 * | | | | | | | ---> 1: HS Bus Off
 * | | | | | | | | -> 0: Steering Torque
 * 0 0 0 0 0 0 0 0 0
 *
 * NOTE: Please check the file "CF-17 VehPwrMd Calculator.xlsx" on how to generate this table.
 */
STATIC CONST(uint8, AP_VEHPWRMD_VAR_NOINIT) T_VehPwrMdVariableEffort_Cnt_u08[512] =
{
	0U, /* 000000000 */
	0U, /* 000000001 */
	0U, /* 000000010 */
	0U, /* 000000011 */
	0U, /* 000000100 */
	0U, /* 000000101 */
	0U, /* 000000110 */
	0U, /* 000000111 */
	0U, /* 000001000 */
	0U, /* 000001001 */
	0U, /* 000001010 */
	0U, /* 000001011 */
	0U, /* 000001100 */
	0U, /* 000001101 */
	0U, /* 000001110 */
	0U, /* 000001111 */
	0U, /* 000010000 */
	0U, /* 000010001 */
	0U, /* 000010010 */
	0U, /* 000010011 */
	0U, /* 000010100 */
	0U, /* 000010101 */
	0U, /* 000010110 */
	0U, /* 000010111 */
	0U, /* 000011000 */
	1U, /* 000011001 */
	0U, /* 000011010 */
	0U, /* 000011011 */
	0U, /* 000011100 */
	1U, /* 000011101 */
	0U, /* 000011110 */
	0U, /* 000011111 */
	0U, /* 000100000 */
	0U, /* 000100001 */
	0U, /* 000100010 */
	0U, /* 000100011 */
	0U, /* 000100100 */
	0U, /* 000100101 */
	0U, /* 000100110 */
	0U, /* 000100111 */
	1U, /* 000101000 */
	1U, /* 000101001 */
	0U, /* 000101010 */
	0U, /* 000101011 */
	1U, /* 000101100 */
	1U, /* 000101101 */
	0U, /* 000101110 */
	0U, /* 000101111 */
	0U, /* 000110000 */
	0U, /* 000110001 */
	0U, /* 000110010 */
	0U, /* 000110011 */
	0U, /* 000110100 */
	0U, /* 000110101 */
	0U, /* 000110110 */
	0U, /* 000110111 */
	1U, /* 000111000 */
	1U, /* 000111001 */
	0U, /* 000111010 */
	0U, /* 000111011 */
	1U, /* 000111100 */
	1U, /* 000111101 */
	0U, /* 000111110 */
	0U, /* 000111111 */
	0U, /* 001000000 */
	0U, /* 001000001 */
	0U, /* 001000010 */
	0U, /* 001000011 */
	0U, /* 001000100 */
	0U, /* 001000101 */
	0U, /* 001000110 */
	0U, /* 001000111 */
	1U, /* 001001000 */
	1U, /* 001001001 */
	0U, /* 001001010 */
	0U, /* 001001011 */
	1U, /* 001001100 */
	1U, /* 001001101 */
	0U, /* 001001110 */
	0U, /* 001001111 */
	0U, /* 001010000 */
	0U, /* 001010001 */
	0U, /* 001010010 */
	0U, /* 001010011 */
	0U, /* 001010100 */
	0U, /* 001010101 */
	0U, /* 001010110 */
	0U, /* 001010111 */
	0U, /* 001011000 */
	1U, /* 001011001 */
	0U, /* 001011010 */
	0U, /* 001011011 */
	0U, /* 001011100 */
	1U, /* 001011101 */
	0U, /* 001011110 */
	0U, /* 001011111 */
	0U, /* 001100000 */
	0U, /* 001100001 */
	0U, /* 001100010 */
	0U, /* 001100011 */
	0U, /* 001100100 */
	0U, /* 001100101 */
	0U, /* 001100110 */
	0U, /* 001100111 */
	1U, /* 001101000 */
	1U, /* 001101001 */
	0U, /* 001101010 */
	0U, /* 001101011 */
	1U, /* 001101100 */
	1U, /* 001101101 */
	0U, /* 001101110 */
	0U, /* 001101111 */
	0U, /* 001110000 */
	0U, /* 001110001 */
	0U, /* 001110010 */
	0U, /* 001110011 */
	0U, /* 001110100 */
	0U, /* 001110101 */
	0U, /* 001110110 */
	0U, /* 001110111 */
	1U, /* 001111000 */
	1U, /* 001111001 */
	0U, /* 001111010 */
	0U, /* 001111011 */
	1U, /* 001111100 */
	1U, /* 001111101 */
	0U, /* 001111110 */
	0U, /* 001111111 */
	0U, /* 010000000 */
	0U, /* 010000001 */
	0U, /* 010000010 */
	0U, /* 010000011 */
	0U, /* 010000100 */
	0U, /* 010000101 */
	0U, /* 010000110 */
	0U, /* 010000111 */
	0U, /* 010001000 */
	0U, /* 010001001 */
	0U, /* 010001010 */
	0U, /* 010001011 */
	0U, /* 010001100 */
	0U, /* 010001101 */
	0U, /* 010001110 */
	0U, /* 010001111 */
	0U, /* 010010000 */
	0U, /* 010010001 */
	0U, /* 010010010 */
	0U, /* 010010011 */
	0U, /* 010010100 */
	0U, /* 010010101 */
	0U, /* 010010110 */
	0U, /* 010010111 */
	0U, /* 010011000 */
	1U, /* 010011001 */
	0U, /* 010011010 */
	0U, /* 010011011 */
	0U, /* 010011100 */
	1U, /* 010011101 */
	0U, /* 010011110 */
	0U, /* 010011111 */
	0U, /* 010100000 */
	0U, /* 010100001 */
	0U, /* 010100010 */
	0U, /* 010100011 */
	0U, /* 010100100 */
	0U, /* 010100101 */
	0U, /* 010100110 */
	0U, /* 010100111 */
	1U, /* 010101000 */
	1U, /* 010101001 */
	0U, /* 010101010 */
	0U, /* 010101011 */
	1U, /* 010101100 */
	1U, /* 010101101 */
	0U, /* 010101110 */
	0U, /* 010101111 */
	0U, /* 010110000 */
	0U, /* 010110001 */
	0U, /* 010110010 */
	0U, /* 010110011 */
	0U, /* 010110100 */
	0U, /* 010110101 */
	0U, /* 010110110 */
	0U, /* 010110111 */
	1U, /* 010111000 */
	1U, /* 010111001 */
	0U, /* 010111010 */
	0U, /* 010111011 */
	1U, /* 010111100 */
	1U, /* 010111101 */
	0U, /* 010111110 */
	0U, /* 010111111 */
	0U, /* 011000000 */
	0U, /* 011000001 */
	0U, /* 011000010 */
	0U, /* 011000011 */
	0U, /* 011000100 */
	0U, /* 011000101 */
	0U, /* 011000110 */
	0U, /* 011000111 */
	1U, /* 011001000 */
	1U, /* 011001001 */
	0U, /* 011001010 */
	0U, /* 011001011 */
	1U, /* 011001100 */
	1U, /* 011001101 */
	0U, /* 011001110 */
	0U, /* 011001111 */
	0U, /* 011010000 */
	0U, /* 011010001 */
	0U, /* 011010010 */
	0U, /* 011010011 */
	0U, /* 011010100 */
	0U, /* 011010101 */
	0U, /* 011010110 */
	0U, /* 011010111 */
	0U, /* 011011000 */
	1U, /* 011011001 */
	0U, /* 011011010 */
	0U, /* 011011011 */
	0U, /* 011011100 */
	1U, /* 011011101 */
	0U, /* 011011110 */
	0U, /* 011011111 */
	0U, /* 011100000 */
	0U, /* 011100001 */
	0U, /* 011100010 */
	0U, /* 011100011 */
	0U, /* 011100100 */
	0U, /* 011100101 */
	0U, /* 011100110 */
	0U, /* 011100111 */
	1U, /* 011101000 */
	1U, /* 011101001 */
	0U, /* 011101010 */
	0U, /* 011101011 */
	1U, /* 011101100 */
	1U, /* 011101101 */
	0U, /* 011101110 */
	0U, /* 011101111 */
	0U, /* 011110000 */
	0U, /* 011110001 */
	0U, /* 011110010 */
	0U, /* 011110011 */
	0U, /* 011110100 */
	0U, /* 011110101 */
	0U, /* 011110110 */
	0U, /* 011110111 */
	1U, /* 011111000 */
	1U, /* 011111001 */
	0U, /* 011111010 */
	0U, /* 011111011 */
	1U, /* 011111100 */
	1U, /* 011111101 */
	0U, /* 011111110 */
	0U, /* 011111111 */
	0U, /* 100000000 */
	0U, /* 100000001 */
	0U, /* 100000010 */
	0U, /* 100000011 */
	0U, /* 100000100 */
	0U, /* 100000101 */
	0U, /* 100000110 */
	0U, /* 100000111 */
	0U, /* 100001000 */
	0U, /* 100001001 */
	0U, /* 100001010 */
	0U, /* 100001011 */
	1U, /* 100001100 */
	1U, /* 100001101 */
	0U, /* 100001110 */
	0U, /* 100001111 */
	0U, /* 100010000 */
	0U, /* 100010001 */
	0U, /* 100010010 */
	0U, /* 100010011 */
	0U, /* 100010100 */
	0U, /* 100010101 */
	0U, /* 100010110 */
	0U, /* 100010111 */
	1U, /* 100011000 */
	1U, /* 100011001 */
	0U, /* 100011010 */
	0U, /* 100011011 */
	1U, /* 100011100 */
	1U, /* 100011101 */
	0U, /* 100011110 */
	0U, /* 100011111 */
	0U, /* 100100000 */
	0U, /* 100100001 */
	0U, /* 100100010 */
	0U, /* 100100011 */
	0U, /* 100100100 */
	0U, /* 100100101 */
	0U, /* 100100110 */
	0U, /* 100100111 */
	1U, /* 100101000 */
	1U, /* 100101001 */
	0U, /* 100101010 */
	0U, /* 100101011 */
	1U, /* 100101100 */
	1U, /* 100101101 */
	0U, /* 100101110 */
	0U, /* 100101111 */
	0U, /* 100110000 */
	0U, /* 100110001 */
	0U, /* 100110010 */
	0U, /* 100110011 */
	0U, /* 100110100 */
	0U, /* 100110101 */
	0U, /* 100110110 */
	0U, /* 100110111 */
	1U, /* 100111000 */
	1U, /* 100111001 */
	0U, /* 100111010 */
	0U, /* 100111011 */
	1U, /* 100111100 */
	1U, /* 100111101 */
	0U, /* 100111110 */
	0U, /* 100111111 */
	0U, /* 101000000 */
	0U, /* 101000001 */
	0U, /* 101000010 */
	0U, /* 101000011 */
	0U, /* 101000100 */
	0U, /* 101000101 */
	0U, /* 101000110 */
	0U, /* 101000111 */
	1U, /* 101001000 */
	1U, /* 101001001 */
	0U, /* 101001010 */
	0U, /* 101001011 */
	1U, /* 101001100 */
	1U, /* 101001101 */
	0U, /* 101001110 */
	0U, /* 101001111 */
	0U, /* 101010000 */
	0U, /* 101010001 */
	0U, /* 101010010 */
	0U, /* 101010011 */
	0U, /* 101010100 */
	0U, /* 101010101 */
	0U, /* 101010110 */
	0U, /* 101010111 */
	1U, /* 101011000 */
	1U, /* 101011001 */
	0U, /* 101011010 */
	0U, /* 101011011 */
	1U, /* 101011100 */
	1U, /* 101011101 */
	0U, /* 101011110 */
	0U, /* 101011111 */
	0U, /* 101100000 */
	0U, /* 101100001 */
	0U, /* 101100010 */
	0U, /* 101100011 */
	0U, /* 101100100 */
	0U, /* 101100101 */
	0U, /* 101100110 */
	0U, /* 101100111 */
	1U, /* 101101000 */
	1U, /* 101101001 */
	0U, /* 101101010 */
	0U, /* 101101011 */
	1U, /* 101101100 */
	1U, /* 101101101 */
	0U, /* 101101110 */
	0U, /* 101101111 */
	0U, /* 101110000 */
	0U, /* 101110001 */
	0U, /* 101110010 */
	0U, /* 101110011 */
	0U, /* 101110100 */
	0U, /* 101110101 */
	0U, /* 101110110 */
	0U, /* 101110111 */
	1U, /* 101111000 */
	1U, /* 101111001 */
	0U, /* 101111010 */
	0U, /* 101111011 */
	1U, /* 101111100 */
	1U, /* 101111101 */
	0U, /* 101111110 */
	0U, /* 101111111 */
	0U, /* 110000000 */
	0U, /* 110000001 */
	0U, /* 110000010 */
	0U, /* 110000011 */
	0U, /* 110000100 */
	0U, /* 110000101 */
	0U, /* 110000110 */
	0U, /* 110000111 */
	0U, /* 110001000 */
	0U, /* 110001001 */
	0U, /* 110001010 */
	0U, /* 110001011 */
	1U, /* 110001100 */
	1U, /* 110001101 */
	0U, /* 110001110 */
	0U, /* 110001111 */
	0U, /* 110010000 */
	0U, /* 110010001 */
	0U, /* 110010010 */
	0U, /* 110010011 */
	0U, /* 110010100 */
	0U, /* 110010101 */
	0U, /* 110010110 */
	0U, /* 110010111 */
	1U, /* 110011000 */
	1U, /* 110011001 */
	0U, /* 110011010 */
	0U, /* 110011011 */
	1U, /* 110011100 */
	1U, /* 110011101 */
	0U, /* 110011110 */
	0U, /* 110011111 */
	0U, /* 110100000 */
	0U, /* 110100001 */
	0U, /* 110100010 */
	0U, /* 110100011 */
	0U, /* 110100100 */
	0U, /* 110100101 */
	0U, /* 110100110 */
	0U, /* 110100111 */
	1U, /* 110101000 */
	1U, /* 110101001 */
	0U, /* 110101010 */
	0U, /* 110101011 */
	1U, /* 110101100 */
	1U, /* 110101101 */
	0U, /* 110101110 */
	0U, /* 110101111 */
	0U, /* 110110000 */
	0U, /* 110110001 */
	0U, /* 110110010 */
	0U, /* 110110011 */
	0U, /* 110110100 */
	0U, /* 110110101 */
	0U, /* 110110110 */
	0U, /* 110110111 */
	1U, /* 110111000 */
	1U, /* 110111001 */
	0U, /* 110111010 */
	0U, /* 110111011 */
	1U, /* 110111100 */
	1U, /* 110111101 */
	0U, /* 110111110 */
	0U, /* 110111111 */
	0U, /* 111000000 */
	0U, /* 111000001 */
	0U, /* 111000010 */
	0U, /* 111000011 */
	0U, /* 111000100 */
	0U, /* 111000101 */
	0U, /* 111000110 */
	0U, /* 111000111 */
	1U, /* 111001000 */
	1U, /* 111001001 */
	0U, /* 111001010 */
	0U, /* 111001011 */
	1U, /* 111001100 */
	1U, /* 111001101 */
	0U, /* 111001110 */
	0U, /* 111001111 */
	0U, /* 111010000 */
	0U, /* 111010001 */
	0U, /* 111010010 */
	0U, /* 111010011 */
	0U, /* 111010100 */
	0U, /* 111010101 */
	0U, /* 111010110 */
	0U, /* 111010111 */
	1U, /* 111011000 */
	1U, /* 111011001 */
	0U, /* 111011010 */
	0U, /* 111011011 */
	1U, /* 111011100 */
	1U, /* 111011101 */
	0U, /* 111011110 */
	0U, /* 111011111 */
	0U, /* 111100000 */
	0U, /* 111100001 */
	0U, /* 111100010 */
	0U, /* 111100011 */
	0U, /* 111100100 */
	0U, /* 111100101 */
	0U, /* 111100110 */
	0U, /* 111100111 */
	1U, /* 111101000 */
	1U, /* 111101001 */
	0U, /* 111101010 */
	0U, /* 111101011 */
	1U, /* 111101100 */
	1U, /* 111101101 */
	0U, /* 111101110 */
	0U, /* 111101111 */
	0U, /* 111110000 */
	0U, /* 111110001 */
	0U, /* 111110010 */
	0U, /* 111110011 */
	0U, /* 111110100 */
	0U, /* 111110101 */
	0U, /* 111110110 */
	0U, /* 111110111 */
	1U, /* 111111000 */
	1U, /* 111111001 */
	0U, /* 111111010 */
	0U, /* 111111011 */
	1U, /* 111111100 */
	1U, /* 111111101 */
	0U, /* 111111110 */
	0U, /* 111111111 */
};
#define VEHPWRMMD_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* Local prototypes */
STATIC FUNC(void, SA_VEHPWRMD_CODE) IgnFailureDiag(VAR(boolean, AUTOMATIC) SrlComEngOn_Cnt_T_lgc,
                                                   VAR(boolean, AUTOMATIC) SrlComSPMOn_Cnt_T_lgc,
                                                   VAR(boolean, AUTOMATIC) EPSEn_Cnt_T_lgc);

STATIC FUNC(float32, SA_VEHPOWRMD_CODE) VehPwrMd_TrqValue(void);
STATIC FUNC(void, SA_VEHPOWRMD_CODE) VehPwrMd_HwTqHandlerStep(void);
STATIC FUNC(void, SA_VEHPOWRMD_CODE) VehPwrMd_CheckKeepAssist(P2VAR(boolean, AUTOMATIC, RTE_AP_VEHPWRMD_APPL_VAR) Assist_Cnt_lgc,
                                                              P2VAR(boolean, AUTOMATIC, RTE_AP_VEHPWRMD_APPL_VAR) VarEffort_Cnt_lgc);
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
 * IoHwAb_BoolType: Integer in interval [0...1]
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_NvMBlkDftActA (6U)
 *   NTC_Num_NvMBlkDftActB (7U)
 *   NTC_Num_NvMBlkDftActC (8U)
 *   NTC_Num_CurrentSensorCalOutOfRange (9U)
 *   NTC_Num_EEPROMDiag (10U)
 *   NTC_Num_EEPROMDiagMtrStr (11U)
 *   NTC_Num_PriSnsrTrqStorFlt (12U)
 *   NTC_Num_EEPROMDiagPosTrimStr (13U)
 *   NTC_Num_SecSnsrTrqStorFlt (14U)
 *   NTC_Num_EEPROMDiagPolarityStr (15U)
 *   NTC_Num_RAMDiag_GeneralFlt (16U)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17U)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
 *   NTC_Num_RAMDiag_ECCMemFlt (19U)
 *   NTC_Num_RAMDiag_CRCMemFlt (20U)
 *   NTC_Num_RAMDiag_VIMRamFlt (23U)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24U)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25U)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26U)
 *   NTC_Num_RAMDiag_DCANRamFault (27U)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28U)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29U)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30U)
 *   NTC_Num_CPU_RegVer (32U)
 *   NTC_Num_CPU_CoreInitFlt (33U)
 *   NTC_Num_CPU_CoreRunTimeFlt (34U)
 *   NTC_Num_CPU_ClockMon (35U)
 *   NTC_Num_CPU_eFuseFlt (36U)
 *   NTC_Num_CPU_MPUViolation (37U)
 *   NTC_Num_CPU_FactPrcsErr (40U)
 *   NTC_Num_PropExeDiag_InitDiag (41U)
 *   NTC_Num_PrgFlwDeadlnFlt (42U)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43U)
 *   NTC_Num_PropExeDiag_COPTimeout (44U)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48U)
 *   NTC_Num_PropExeDiag_DataAbort (49U)
 *   NTC_Num_PerDiag_ADC1Flt (50U)
 *   NTC_Num_PerDiag_ADC2Flt (51U)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52U)
 *   NTC_Num_PerDiag_IllegalAccess (53U)
 *   NTC_Num_PerDiag_DMAFlt (54U)
 *   NTC_Num_PeripheralStartupFlt (55U)
 *   NTC_Num_PerDiag_CPUWarning (63U)
 *   NTC_Num_TmpMonFunc (64U)
 *   NTC_Num_TmpMonRunTimeFlt (65U)
 *   NTC_Num_PowerRelayInitFlt (66U)
 *   NTC_Num_PrechargeFailure (67U)
 *   NTC_Num_PowerRelayRunFlt (68U)
 *   NTC_Num_Thermistor (69U)
 *   NTC_Num_RefSupplyVltg (70U)
 *   NTC_Num_TrcvrInterfaceFlt (71U)
 *   NTC_Num_CPUSupplyOvervoltage (72U)
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73U)
 *   NTC_Num_IvtrPwrDiscnctFailr (74U)
 *   NTC_Num_PowerRelayInit2Flt (75U)
 *   NTC_Num_GateDrvFltInProcess (76U)
 *   NTC_Num_GateDrvFlt (77U)
 *   NTC_Num_OnStateSingleFET (78U)
 *   NTC_Num_OnStateMultiFET (79U)
 *   NTC_Num_PhaseVoltageVerf (80U)
 *   NTC_Num_PhaseDscnt (81U)
 *   NTC_Num_DigPhaseVoltageVerf (82U)
 *   NTC_Num_PhaseDscntFailedDisable (83U)
 *   NTC_Num_CurrentMeas1 (84U)
 *   NTC_Num_CurrentMeas2 (85U)
 *   NTC_Num_CurrentMeasCrossChk (86U)
 *   NTC_Num_PDSupplyOverVoltage (87U)
 *   NTC_Num_ChargePumpUnderVoltage (88U)
 *   NTC_Num_Inv2GateDrvFltInProcess (92U)
 *   NTC_Num_Inv2GateDrvFlt (93U)
 *   NTC_Num_Inv2OnStateSingleFET (94U)
 *   NTC_Num_HwTrqSensor (96U)
 *   NTC_Num_AnaVsDigHwTrq (97U)
 *   NTC_Num_TrqSensorRecoveryFlt (98U)
 *   NTC_Num_TrqSensorScaleInvalid (100U)
 *   NTC_Num_T1vsT2 (101U)
 *   NTC_Num_T1OutofRange (102U)
 *   NTC_Num_T2OutofRange (103U)
 *   NTC_Num_DigT1vsT2 (104U)
 *   NTC_Num_DigT1OutofRange (105U)
 *   NTC_Num_DigT2OutofRange (106U)
 *   NTC_Num_RedT1vsT2 (107U)
 *   NTC_Num_HWACrossChecks (108U)
 *   NTC_Num_HWASnsrCommFault (109U)
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_LoaRpdShutdn (170U)
 *   NTC_Num_LoaCtrldShutdn (171U)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172U)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173U)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174U)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
 *   NTC_Num_BattTransOverVolt (182U)
 *   NTC_Num_IgnConfDiag (184U)
 *   NTC_Num_TurnCntr_LowBattery (185U)
 *   NTC_Num_EEPROMCloseFailed (191U)
 *   NTC_Num_SigPath1CrossChk (192U)
 *   NTC_Num_SigPath2CrossChk (193U)
 *   NTC_Num_SigPath3CrossChk (194U)
 *   NTC_Num_SigPath4CrossChk (195U)
 *   NTC_Num_SigPath5CrossChk (196U)
 *   NTC_Num_DampingFWReached (197U)
 *   NTC_Num_AssistFWReached (198U)
 *   NTC_Num_ReturnFWReached (199U)
 *   NTC_Num_DampingFWFltMode (200U)
 *   NTC_Num_AssistFWFltMode (201U)
 *   NTC_Num_VBICFltMode (202U)
 *   NTC_Num_StaMdsSysC (203U)
 *   NTC_NUM_SysFailureForRotVel (204U)
 *   NTC_NUM_SysFailForRedntRotVel (205U)
 *   NTC_Num_SysFailureForTrqSnsr (206U)
 *   NTC_Num_SysFailureForRedTrqSnsr (207U)
 *   NTC_NUM_SysFailureForCtrlVolt (209U)
 *   NTC_Num_GlblSgnlOvrwrtDet (223U)
 *   NTC_Num_VLF_00 (224U)
 *   NTC_Num_VLF_01 (225U)
 *   NTC_Num_VLF_02 (226U)
 *   NTC_Num_VLF_03 (227U)
 *   NTC_Num_VLF_04 (228U)
 *   NTC_Num_VLF_05 (229U)
 *   NTC_Num_VLF_06 (230U)
 *   NTC_Num_VLF_07 (231U)
 *   NTC_Num_VLF_08 (232U)
 *   NTC_Num_VLF_09 (233U)
 *   NTC_Num_VLF_10 (234U)
 *   NTC_Num_VLF_11 (235U)
 *   NTC_Num_VLF_12 (236U)
 *   NTC_Num_VLF_13 (237U)
 *   NTC_Num_VLF_14 (238U)
 *   NTC_Num_VLF_15 (239U)
 *   NTC_Num_VLF_16 (240U)
 *   NTC_Num_VLF_17 (241U)
 *   NTC_Num_VLF_18 (242U)
 *   NTC_Num_VLF_19 (243U)
 *   NTC_Num_VLF_20 (244U)
 *   NTC_Num_VLF_21 (245U)
 *   NTC_Num_VLF_22 (246U)
 *   NTC_Num_VLF_23 (247U)
 *   NTC_Num_VLF_24 (248U)
 *   NTC_Num_VLF_25 (249U)
 *   NTC_Num_VLF_26 (250U)
 *   NTC_Num_VLF_27 (251U)
 *   NTC_Num_VLF_28 (252U)
 *   NTC_Num_VLF_29 (253U)
 *   NTC_Num_VLF_30 (254U)
 *   NTC_Num_VLF_31 (255U)
 *   NTC_Num_BusOffCh1 (256U)
 *   NTC_Num_BusOffCh1NodeMute (257U)
 *   NTC_Num_Node1AAbsent (258U)
 *   NTC_Num_Node1AFaulty (259U)
 *   NTC_Num_Node1BAbsent (260U)
 *   NTC_Num_Node1BFaulty (261U)
 *   NTC_Num_Node1CAbsent (262U)
 *   NTC_Num_Node1CFaulty (263U)
 *   NTC_Num_Node1DAbsent (264U)
 *   NTC_Num_Node1DFaulty (265U)
 *   NTC_Num_Node1EAbsent (266U)
 *   NTC_Num_Node1EFaulty (267U)
 *   NTC_Num_Node1FAbsent (268U)
 *   NTC_Num_Node1FFaulty (269U)
 *   NTC_Num_Node1GAbsent (270U)
 *   NTC_Num_Node1GFaulty (271U)
 *   NTC_Num_BusOffCh2 (272U)
 *   NTC_Num_Node2AAbsent (273U)
 *   NTC_Num_Node2AFaulty (274U)
 *   NTC_Num_Node2BAbsent (275U)
 *   NTC_Num_Node2BFaulty (276U)
 *   NTC_Num_Node2CAbsent (277U)
 *   NTC_Num_Node2CFaulty (278U)
 *   NTC_Num_Node2DAbsent (279U)
 *   NTC_Num_Node2DFaulty (280U)
 *   NTC_Num_Node2EAbsent (281U)
 *   NTC_Num_Node2EFaulty (282U)
 *   NTC_Num_Node2FAbsent (283U)
 *   NTC_Num_Node2FFaulty (284U)
 *   NTC_Num_Node2GAbsent (285U)
 *   NTC_Num_Node2GFaulty (286U)
 *   NTC_Num_InvalidMsg_M (288U)
 *   NTC_Num_MissingMsg_M (289U)
 *   NTC_Num_CRCFltMsg_M (290U)
 *   NTC_Num_PgrsCntFltMsg_M (291U)
 *   NTC_Num_DataRngFltMsg_M (292U)
 *   NTC_Num_DataRateFltMsg_M (293U)
 *   NTC_Num_DataOtherFltMsg_M (294U)
 *   NTC_Num_DataOther2FltMsg_M (295U)
 *   NTC_Num_InvalidMsg_N (296U)
 *   NTC_Num_MissingMsg_N (297U)
 *   NTC_Num_CRCFltMsg_N (298U)
 *   NTC_Num_PgrsCntFltMsg_N (299U)
 *   NTC_Num_DataRngFltMsg_N (300U)
 *   NTC_Num_DataRateFltMsg_N (301U)
 *   NTC_Num_DataOtherFltMsg_N (302U)
 *   NTC_Num_DataOtherFlt2Msg_N (303U)
 *   NTC_Num_InvalidMsg_O (304U)
 *   NTC_Num_MissingMsg_O (305U)
 *   NTC_Num_CRCFltMsg_O (306U)
 *   NTC_Num_PgrsCntFltMsg_O (307U)
 *   NTC_Num_DataRngFltMsg_O (308U)
 *   NTC_Num_DataRateFltMsg_O (309U)
 *   NTC_Num_DataOtherFltMsg_O (310U)
 *   NTC_Num_InvalidMsg_P (312U)
 *   NTC_Num_MissingMsg_P (313U)
 *   NTC_Num_CRCFltMsg_P (314U)
 *   NTC_Num_PgrsCntFltMsg_P (315U)
 *   NTC_Num_DataRngFltMsg_P (316U)
 *   NTC_Num_DataRateFltMsg_P (317U)
 *   NTC_Num_DataOtherFltMsg_P (318U)
 *   NTC_Num_InvalidMsg_Q (320U)
 *   NTC_Num_MissingMsg_Q (321U)
 *   NTC_Num_CRCFltMsg_Q (322U)
 *   NTC_Num_PgrsCntFltMsg_Q (323U)
 *   NTC_Num_DataRngFltMsg_Q (324U)
 *   NTC_Num_DataRateFltMsg_Q (325U)
 *   NTC_Num_DataOtherFltMsg_Q (326U)
 *   NTC_Num_InvalidMsg_R (328U)
 *   NTC_Num_MissingMsg_R (329U)
 *   NTC_Num_CRCFltMsg_R (330U)
 *   NTC_Num_PgrsCntFltMsg_R (331U)
 *   NTC_Num_DataRngFltMsg_R (332U)
 *   NTC_Num_DataRateFltMsg_R (333U)
 *   NTC_Num_DataOtherFltMsg_R (334U)
 *   NTC_Num_DataOtherFlt2Msg_R (335U)
 *   NTC_Num_InvalidMsg_S (336U)
 *   NTC_Num_MissingMsg_S (337U)
 *   NTC_Num_CRCFltMsg_S (338U)
 *   NTC_Num_PgrsCntFltMsg_S (339U)
 *   NTC_Num_DataRngFltMsg_S (340U)
 *   NTC_Num_DataRateFltMsg_S (341U)
 *   NTC_Num_DataOtherFltMsg_S (342U)
 *   NTC_Num_InvalidMsg_T (344U)
 *   NTC_Num_MissingMsg_T (345U)
 *   NTC_Num_CRCFltMsg_T (346U)
 *   NTC_Num_PgrsCntFltMsg_T (347U)
 *   NTC_Num_DataRngFltMsg_T (348U)
 *   NTC_Num_DataRateFltMsg_T (349U)
 *   NTC_Num_DataOtherFltMsg_T (350U)
 *   NTC_Num_InvalidMsg_U (352U)
 *   NTC_Num_MissingMsg_U (353U)
 *   NTC_Num_CRCFltMsg_U (354U)
 *   NTC_Num_PgrsCntFltMsg_U (355U)
 *   NTC_Num_DataRngFltMsg_U (356U)
 *   NTC_Num_DataRateFltMsg_U (357U)
 *   NTC_Num_DataOtherFltMsg_U (358U)
 *   NTC_Num_InvalidMsg_V (360U)
 *   NTC_Num_MissingMsg_V (361U)
 *   NTC_Num_CRCFltMsg_V (362U)
 *   NTC_Num_PgrsCntFltMsg_V (363U)
 *   NTC_Num_DataRngFltMsg_V (364U)
 *   NTC_Num_DataRateFltMsg_V (365U)
 *   NTC_Num_DataOtherFltMsg_V (366U)
 *   NTC_Num_InvalidMsg_W (368U)
 *   NTC_Num_MissingMsg_W (369U)
 *   NTC_Num_CRCFltMsg_W (370U)
 *   NTC_Num_PgrsCntFltMsg_W (371U)
 *   NTC_Num_DataRngFltMsg_W (372U)
 *   NTC_Num_DataRateFltMsg_W (373U)
 *   NTC_Num_DataOtherFltMsg_W (374U)
 *   NTC_Num_InvalidMsg_X (376U)
 *   NTC_Num_MissingMsg_X (377U)
 *   NTC_Num_CRCFltMsg_X (378U)
 *   NTC_Num_PgrsCntFltMsg_X (379U)
 *   NTC_Num_DataRngFltMsg_X (380U)
 *   NTC_Num_DataRateFltMsg_X (381U)
 *   NTC_Num_DataOtherFltMsg_X (382U)
 *   NTC_Num_InvalidMsg_Y (384U)
 *   NTC_Num_MissingMsg_Y (385U)
 *   NTC_Num_CRCFltMsg_Y (386U)
 *   NTC_Num_PgrsCntFltMsg_Y (387U)
 *   NTC_Num_DataRngFltMsg_Y (388U)
 *   NTC_Num_DataRateFltMsg_Y (389U)
 *   NTC_Num_DataOtherFltMsg_Y (390U)
 *   NTC_Num_InvalidMsg_Z (392U)
 *   NTC_Num_MissingMsg_Z (393U)
 *   NTC_Num_CRCFltMsg_Z (394U)
 *   NTC_Num_PgrsCntFltMsg_Z (395U)
 *   NTC_Num_DataRngFltMsg_Z (396U)
 *   NTC_Num_DataRateFltMsg_Z (397U)
 *   NTC_Num_DataOtherFltMsg_Z (398U)
 *   NTC_Num_DSTXORActive (399U)
 *   NTC_Num_InvalidMsg_AA (400U)
 *   NTC_Num_MissingMsg_AA (401U)
 *   NTC_Num_CRCFltMsg_AA (402U)
 *   NTC_Num_PgrsCntFltMsg_AA (403U)
 *   NTC_Num_DataRngFltMsg_AA (404U)
 *   NTC_Num_DataRateFltMsg_AA (405U)
 *   NTC_Num_DataOtherFltMsg_AA (406U)
 *   NTC_Num_InvalidMsg_AB (408U)
 *   NTC_Num_MissingMsg_AB (409U)
 *   NTC_Num_CRCFltMsg_AB (410U)
 *   NTC_Num_PgrsCntFltMsg_AB (411U)
 *   NTC_Num_DataRngFltMsg_AB (412U)
 *   NTC_Num_DataRateFltMsg_AB (413U)
 *   NTC_Num_DataOtherFltMsg_AB (414U)
 *   NTC_Num_InvalidMsg_AC (416U)
 *   NTC_Num_MissingMsg_AC (417U)
 *   NTC_Num_CRCFltMsg_AC (418U)
 *   NTC_Num_PgrsCntFltMsg_AC (419U)
 *   NTC_Num_DataRngFltMsg_AC (420U)
 *   NTC_Num_DataRateFltMsg_AC (421U)
 *   NTC_Num_DataOtherFltMsg_AC (422U)
 *   NTC_Num_InvalidMsg_AD (424U)
 *   NTC_Num_MissingMsg_AD (425U)
 *   NTC_Num_CRCFltMsg_AD (426U)
 *   NTC_Num_PgrsCntFltMsg_AD (427U)
 *   NTC_Num_DataRngFltMsg_AD (428U)
 *   NTC_Num_DataRateFltMsg_AD (429U)
 *   NTC_Num_DataOtherFltMsg_AD (430U)
 *   NTC_Num_InvalidMsg_AE (432U)
 *   NTC_Num_MissingMsg_AE (433U)
 *   NTC_Num_CRCFltMsg_AE (434U)
 *   NTC_Num_PgrsCntFltMsg_AE (435U)
 *   NTC_Num_DataRngFltMsg_AE (436U)
 *   NTC_Num_DataRateFltMsg_AE (437U)
 *   NTC_Num_DataOtherFltMsg_AE (438U)
 *   NTC_Num_InvalidMsg_AF (440U)
 *   NTC_Num_MissingMsg_AF (441U)
 *   NTC_Num_CRCFltMsg_AF (442U)
 *   NTC_Num_PgrsCntFltMsg_AF (443U)
 *   NTC_Num_DataRngFltMsg_AF (444U)
 *   NTC_Num_DataRateFltMsg_AF (445U)
 *   NTC_Num_DataOtherFltMsg_AF (446U)
 *   NTC_Num_InvalidMsg_AG (448U)
 *   NTC_Num_MissingMsg_AG (449U)
 *   NTC_Num_CRCFltMsg_AG (450U)
 *   NTC_Num_PgrsCntFltMsg_AG (451U)
 *   NTC_Num_DataRngFltMsg_AG (452U)
 *   NTC_Num_DataRateFltMsg_AG (453U)
 *   NTC_Num_DataOtherFltMsg_AG (454U)
 *   NTC_Num_InvalidMsg_AH (456U)
 *   NTC_Num_MissingMsg_AH (457U)
 *   NTC_Num_CRCFltMsg_AH (458U)
 *   NTC_Num_PgrsCntFltMsg_AH (459U)
 *   NTC_Num_DataRngFltMsg_AH (460U)
 *   NTC_Num_DataRateFltMsg_AH (461U)
 *   NTC_Num_DataOtherFltMsg_AH (462U)
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464U)
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_InvalidMsg_AI (466U)
 *   NTC_Num_MissingMsg_AI (467U)
 *   NTC_Num_InvalidMsg_AJ (472U)
 *   NTC_Num_MissingMsg_AJ (473U)
 *   NTC_Num_InvalidMsg_AK (480U)
 *   NTC_Num_MissingMsg_AK (481U)
 *   NTC_Num_MissingMsg_AL (489U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_TunSetNotPrgmd (499U)
 *   NTC_Num_EEPROMtoFeeCpyError (500U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
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
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_VEHPWRMD_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehPwrMd_Init1
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
 *   void Rte_IWrite_VehPwrMd_Init1_OperRampRate_XpmS_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Init1_OperRampRate_XpmS_f32(void)
 *   void Rte_IWrite_VehPwrMd_Init1_OperRampValue_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Init1_OperRampValue_Uls_f32(void)
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

FUNC(void, RTE_AP_VEHPWRMD_APPL_CODE) VehPwrMd_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehPwrMd_Init1
 *********************************************************************************************************************/
	Rte_IWrite_VehPwrMd_Init1_OperRampRate_XpmS_f32(k_RampDnRt_UlspmS_f32);
	Rte_IWrite_VehPwrMd_Init1_OperRampValue_Uls_f32(D_ZERO_ULS_F32);

	/* Assume that there is a torque at initialization */
	VehPwrMd_HwTorqueSt_Cnt_M_enum = HWTRQPRESENT;
	VehPwrMd_PrevTqValue_HwNm_M_f32 = 0.0F;
	LPF_KUpdate_f32_m(k_VehPwrMdLpfCutOff_Hz_f32, D_2MS_SEC_F32, &VehPwMd_HwTorqueLPF_M_str);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehPwrMd_Per1
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
 *   Boolean Rte_IRead_VehPwrMd_Per1_EngONSrlComSvcDft_Cnt_lgc(void)
 *   Float Rte_IRead_VehPwrMd_Per1_HwTrq_HwNm_f32(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_SrlComEngOn_Cnt_lgc(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_SrlComSPMOn_Cnt_lgc(void)
 *   Boolean Rte_IRead_VehPwrMd_Per1_VehSpdValid_Cnt_lgc(void)
 *   Float Rte_IRead_VehPwrMd_Per1_VehSpd_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_VehPwrMd_Per1_ATermActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_VehPwrMd_Per1_ATermActive_Cnt_lgc(void)
 *   void Rte_IWrite_VehPwrMd_Per1_CTermActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_VehPwrMd_Per1_CTermActive_Cnt_lgc(void)
 *   void Rte_IWrite_VehPwrMd_Per1_DftVehSpdEna_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_VehPwrMd_Per1_DftVehSpdEna_Cnt_lgc(void)
 *   void Rte_IWrite_VehPwrMd_Per1_OperRampRate_XpmS_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Per1_OperRampRate_XpmS_f32(void)
 *   void Rte_IWrite_VehPwrMd_Per1_OperRampValue_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Per1_OperRampValue_Uls_f32(void)
 *   void Rte_IWrite_VehPwrMd_Per1_SysOperMotTqCmdSca_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_VehPwrMd_Per1_SysOperMotTqCmdSca_Uls_f32(void)
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
 *   Std_ReturnType Rte_Call_EpsEn_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EpsEn_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
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

FUNC(void, RTE_AP_VEHPWRMD_APPL_CODE) VehPwrMd_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehPwrMd_Per1
 *********************************************************************************************************************/

	VAR(boolean, AUTOMATIC) CE_Cnt_T_lgc;                 /* Communication Enable */
	VAR(boolean, AUTOMATIC) PM_Cnt_T_lgc;                 /* System Power Mode */
	VAR(boolean, AUTOMATIC) ER_Cnt_T_lgc;                 /* Engine Running */
	VAR(boolean, AUTOMATIC) ERDft_Cnt_T_lgc;              /* Engine Running Defeat */
	VAR(boolean, AUTOMATIC) VS_Cnt_T_lgc;                 /* Vehicle Speed > cal */
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;             /* Vehicle Speed */
	VAR(boolean, AUTOMATIC) VSValid_Cnt_T_lgc;            /* Vehicle Speed Valid */
	VAR(boolean, AUTOMATIC) PM1F1Missing_Cnt_T_lgc;       /* PM 1F1 Missing Message */
	VAR(boolean, AUTOMATIC) ER0C9Missing_Cnt_T_lgc;       /* ER 0C9 Missing Message */
	VAR(boolean, AUTOMATIC) HSBusOff_Cnt_T_lgc;           /* HS Bus Off */
	VAR(float32, AUTOMATIC) OperRampRate_XpmS_T_f32;
	VAR(float32, AUTOMATIC) OperRampValue_Uls_T_f32;
	VAR(boolean, AUTOMATIC) ATermActive_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) Assist_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VarEffort_Cnt_T_lgc = FALSE;
	VAR(boolean, AUTOMATIC) VehPwrModDftVehSpdEna_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) SysOperMotTqCmdSca_Uls_T_f32;
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;

	/* Read inputs */
	(void)Rte_Call_EpsEn_OP_GET(&CE_Cnt_T_lgc);
	PM_Cnt_T_lgc = Rte_IRead_VehPwrMd_Per1_SrlComSPMOn_Cnt_lgc();
	ER_Cnt_T_lgc = Rte_IRead_VehPwrMd_Per1_SrlComEngOn_Cnt_lgc();
	ERDft_Cnt_T_lgc = Rte_IRead_VehPwrMd_Per1_EngONSrlComSvcDft_Cnt_lgc();
	VehSpd_Kph_T_f32 = Rte_IRead_VehPwrMd_Per1_VehSpd_Kph_f32();
	VS_Cnt_T_lgc = (VehSpd_Kph_T_f32 > k_GmVPMod_VehSpdAssiOnMin_Kph_f32)? TRUE: FALSE;
	VSValid_Cnt_T_lgc = Rte_IRead_VehPwrMd_Per1_VehSpdValid_Cnt_lgc();
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_O, &PM1F1Missing_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_N, &ER0C9Missing_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_BusOffCh1, &HSBusOff_Cnt_T_lgc);
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	HwTorque_HwNm_T_f32 = VehPwrMd_TrqValue();

	VehPwrMd_HwTqHandlerStep();

	if (TRUE == ERDft_Cnt_T_lgc)
	{
		if (TRUE == CE_Cnt_T_lgc)
		{
			ATermActive_Cnt_T_lgc = TRUE;
			VehPwrMd_CTermActive_Cnt_M_lgc = TRUE;
			
			OperRampRate_XpmS_T_f32 = k_RampUpRtLoSpd_UlspmS_f32;
			OperRampValue_Uls_T_f32 = D_ONE_ULS_F32;
		}
		else
		{
			ATermActive_Cnt_T_lgc = FALSE;
			VehPwrMd_CTermActive_Cnt_M_lgc = FALSE;
			
			OperRampRate_XpmS_T_f32 = k_RampDnRt_UlspmS_f32;
			OperRampValue_Uls_T_f32 = D_ZERO_ULS_F32;
		}
	}
	else
	{
		/* Determine A Term */
		if ((CE_Cnt_T_lgc == TRUE) ||
		    ((PM_Cnt_T_lgc == TRUE) && (PM1F1Missing_Cnt_T_lgc == FALSE)) ||
		    ((RTE_MODE_StaMd_Mode_OPERATE == SystemState_Cnt_T_enum)))
		{
			ATermActive_Cnt_T_lgc = TRUE;
		}
		else
		{
			ATermActive_Cnt_T_lgc = FALSE;
		}
		
		/* Determine C Term */
		if (VehPwrMd_CTermActive_Cnt_M_lgc == TRUE)
		{
			/* C Term is TRUE - Check conditions to keep assist */

			VehPwrMd_CheckKeepAssist(&Assist_Cnt_T_lgc, &VarEffort_Cnt_T_lgc);
			if (Assist_Cnt_T_lgc == FALSE)
			{
				VehPwrMd_CTermActive_Cnt_M_lgc = FALSE;
			}
		}
		else
		{
			/* C Term is FALSE - No previous assist */

			if ((CE_Cnt_T_lgc == TRUE) &&
			    (PM_Cnt_T_lgc == TRUE) &&
			    (((ER_Cnt_T_lgc == TRUE) && (ER0C9Missing_Cnt_T_lgc == FALSE)) || (VS_Cnt_T_lgc == TRUE)) &&
			    (VSValid_Cnt_T_lgc == TRUE) &&
			    (PM1F1Missing_Cnt_T_lgc == FALSE) &&
			    (HSBusOff_Cnt_T_lgc == FALSE))
			{
				/* Conditions to start assist satisfied */
				VehPwrMd_CTermActive_Cnt_M_lgc = TRUE;
			}
		}

		if ((FALSE == VehPwrMd_CTermActive_Cnt_M_lgc) || (FALSE == ATermActive_Cnt_T_lgc))
		{
			OperRampRate_XpmS_T_f32 = k_RampDnRt_UlspmS_f32;
			OperRampValue_Uls_T_f32 = D_ZERO_ULS_F32;
		}
		else
		{
			OperRampRate_XpmS_T_f32 = k_RampUpRtLoSpd_UlspmS_f32;
			OperRampValue_Uls_T_f32 = D_ONE_ULS_F32;
		}
	}
	
	/* Logic for Vehicle Power Mode Default Vehicle Speed Enable */
	if (((VarEffort_Cnt_T_lgc == FALSE) && (VehPwrMd_CTermActive_Cnt_M_lgc == TRUE)) ||
	    ((CE_Cnt_T_lgc == FALSE) && (HSBusOff_Cnt_T_lgc == TRUE) &&
	     (HwTorque_HwNm_T_f32 > k_VehPwrMdTqThreshold_Nm_f32)))
	{
		VehPwrModDftVehSpdEna_Cnt_T_lgc = TRUE;
	}
	else
	{
		VehPwrModDftVehSpdEna_Cnt_T_lgc = FALSE;
	}

	/* Logic for System Operation Motor Torque Command Scale */
	SysOperMotTqCmdSca_Uls_T_f32 = (VehPwrMd_CTermActive_Cnt_M_lgc == TRUE)? 1.0F : 0.0F;

	/* Outputs writes */
	Rte_IWrite_VehPwrMd_Per1_OperRampRate_XpmS_f32(OperRampRate_XpmS_T_f32);
	Rte_IWrite_VehPwrMd_Per1_OperRampValue_Uls_f32(OperRampValue_Uls_T_f32);

	Rte_IWrite_VehPwrMd_Per1_ATermActive_Cnt_lgc(ATermActive_Cnt_T_lgc);
	Rte_IWrite_VehPwrMd_Per1_CTermActive_Cnt_lgc(VehPwrMd_CTermActive_Cnt_M_lgc);
	Rte_IWrite_VehPwrMd_Per1_DftVehSpdEna_Cnt_lgc(VehPwrModDftVehSpdEna_Cnt_T_lgc);
	Rte_IWrite_VehPwrMd_Per1_SysOperMotTqCmdSca_Uls_f32(SysOperMotTqCmdSca_Uls_T_f32);

	IgnFailureDiag(ER_Cnt_T_lgc, PM_Cnt_T_lgc, CE_Cnt_T_lgc);

	Rte_Call_VehPwrMd_Per1_CP1_CheckpointReached(); /* PRQA S 3112 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehPwrMd_Trns1
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
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHPWRMD_APPL_CODE) VehPwrMd_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehPwrMd_Trns1
 *********************************************************************************************************************/
	(void)CanStop(0U);
	(void)CanStop(1U);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: VehPwrMd_Trns2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <OFF> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
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
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SrlComInput_SCom_ResetBus1Timers(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SrlComInput_SCom_ResetBus2Timers(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHPWRMD_APPL_CODE) VehPwrMd_Trns2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: VehPwrMd_Trns2
 *********************************************************************************************************************/
	(void)Rte_Call_SrlComInput_SCom_ResetBus1Timers();
	(void)Rte_Call_SrlComInput_SCom_ResetBus2Timers();
	(void)CanStart(0U);
	(void)CanStart(1U);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_VEHPWRMD_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
STATIC FUNC(void, SA_VEHPWRMD_CODE) IgnFailureDiag(VAR(boolean, AUTOMATIC) SrlComEngOn_Cnt_T_lgc,
                                                   VAR(boolean, AUTOMATIC) SrlComSPMOn_Cnt_T_lgc,
                                                   VAR(boolean, AUTOMATIC) EPSEn_Cnt_T_lgc)
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;

	if (((TRUE == SrlComEngOn_Cnt_T_lgc) || (TRUE == SrlComSPMOn_Cnt_T_lgc)) && (FALSE == EPSEn_Cnt_T_lgc))
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(VehPwrMd_IGNDiagStartTime_mS_M_u32p0, &ElapsedTime_mS_T_u16p0);
		if (ElapsedTime_mS_T_u16p0 >= k_IGNDiagTime_mS_u16p0)
		{
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_IgnConfDiag, 0x01U, NTC_STATUS_FAILED);
		}
	}
	else
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_IgnConfDiag, 0x01U, NTC_STATUS_PASSED);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&VehPwrMd_IGNDiagStartTime_mS_M_u32p0);
	}
}

/**
 * Read the torque value. If k_VehPwrMdDiffTorque_Cnt_lgc is TRUE, the returned torque will be the different between the
 * actual torque and the average past torque. In this case, the output will tend to zero if the torque remains the
 * same.
 */
STATIC FUNC(float32, SA_VEHPOWRMD_CODE) VehPwrMd_TrqValue(void)
{
	VAR(float32, AUTOMATIC) TorqueValue_HwNm_T_f32;
	VAR(float32, AUTOMATIC) TorqueValueDiff_HwNm_T_f32;

	/* Read the actual torque value */
	TorqueValue_HwNm_T_f32 = Rte_IRead_VehPwrMd_Per1_HwTrq_HwNm_f32();

	if (k_VehPwrMdDiffTorque_Cnt_lgc == TRUE)
	{
		/* Calculate the average */ /* PRQA S 4394 1*/
		VehPwrMd_TqAverage_HwNm_M_f32 = (TorqueValue_HwNm_T_f32 + (((float32)(k_VehPwrMdAvgTq_Cnt_u16 -1U)) * VehPwrMd_PrevTqValue_HwNm_M_f32))
		                                /(float32)k_VehPwrMdAvgTq_Cnt_u16;

		/* Use the delta between the actual torque value and the moving average of the past values to calculate
		 * the amount of torque */
		TorqueValueDiff_HwNm_T_f32 = TorqueValue_HwNm_T_f32 - VehPwrMd_TqAverage_HwNm_M_f32;
		TorqueValueDiff_HwNm_T_f32 = Abs_f32_m(TorqueValueDiff_HwNm_T_f32);

		if (TorqueValueDiff_HwNm_T_f32 < k_VehPwrMdDiffTqThreshold_HwNm_f32)
		{
			/* Filter output */
			TorqueValue_HwNm_T_f32 = LPF_OpUpdate_f32_m(TorqueValueDiff_HwNm_T_f32, &VehPwMd_HwTorqueLPF_M_str);
		}
		else
		{
			LPF_Init_f32_m(TorqueValueDiff_HwNm_T_f32, k_VehPwrMdLpfCutOff_Hz_f32, D_2MS_SEC_F32, &VehPwMd_HwTorqueLPF_M_str);
			TorqueValue_HwNm_T_f32 = TorqueValueDiff_HwNm_T_f32;
		}

		VehPwrMd_PrevTqValue_HwNm_M_f32 = VehPwrMd_TqAverage_HwNm_M_f32;
	}
	else
	{
		/* Use the actual torque value as the amount torque */
		TorqueValue_HwNm_T_f32 = Abs_f32_m(TorqueValue_HwNm_T_f32);
	}

	VehPwrMd_TqValue_HwNm_D_f32 = TorqueValue_HwNm_T_f32;
	return (TorqueValue_HwNm_T_f32);
}


/**
 * This function will determine if it is safe to remove assist based on the hand wheel torque. If torque is below
 * k_VehPwrMdTqThreshold_Nm_f32, count for k_VehPwrMdNoTqTimer_mS_u32p0 before say that is safe to remove assist.
 */
STATIC FUNC(void, SA_VEHPOWRMD_CODE) VehPwrMd_HwTqHandlerStep(void)
{
	VAR(float32, AUTOMATIC) HwTorque_HwNm_T_f32;
	VAR(uint32, AUTOMATIC) ElapsedTime_mS_T_u32p0;

	/* Read torque value */
	HwTorque_HwNm_T_f32 = VehPwrMd_TrqValue();

	if (HwTorque_HwNm_T_f32 >= k_VehPwrMdTqThreshold_Nm_f32)
	{
		VehPwrMd_HwTorqueSt_Cnt_M_enum = HWTRQPRESENT;

		/* Reset HW torque not present timer */
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&VehPwrMd_HwTorqueTimer_mS_T_u32p0);
	}
	else
	{
		/* Read time elapsed in this state */
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(VehPwrMd_HwTorqueTimer_mS_T_u32p0, &ElapsedTime_mS_T_u32p0);

		if (ElapsedTime_mS_T_u32p0 > k_VehPwrMdNoTqTimer_mS_u32p0)
		{
			VehPwrMd_HwTorqueSt_Cnt_M_enum = HWTRQSAFETOOFF;
		}
		else
		{
			VehPwrMd_HwTorqueSt_Cnt_M_enum = HWTRQNOTPRESENT;
		}
	}
}


/**
 * This function will verify if, based on the inputs, the assist should be keep on or if it should be turned off.
 *
 * Inputs
 *
 * CE                FALSE-> OFF                 / TRUE-> ON
 * PM                FALSE-> !Run                / TRUE-> Run
 * ER                FALSE-> !On                 / TRUE-> On
 * VS                FALSE-> < K                 / TRUE-> >= K
 * 0C9Miss           FALSE-> Not Missing         / TRUE-> Missing
 * VSValid           FALSE-> Not Valid           / TRUE-> Valid
 * 1F1Miss           FALSE-> Not Missing         / TRUE-> Missing
 * HSBusOff          FALSE-> No Bus Off          / TRUE-> BusOff
 * Sterring Torque   FALSE-> < K                 / TRUE-> >= K
 *
 * Outputs
 *
 * Assist            FALSE-> No Assist           / TRUE-> Assist
 * VarEff            FALSE-> No variable effort  / TRUE -> Use variable effort
 */
STATIC FUNC(void, SA_VEHPOWRMD_CODE) VehPwrMd_CheckKeepAssist(P2VAR(boolean, AUTOMATIC, RTE_AP_VEHPWRMD_APPL_VAR) Assist_Cnt_lgc,
                                                              P2VAR(boolean, AUTOMATIC, RTE_AP_VEHPWRMD_APPL_VAR) VarEffort_Cnt_lgc)
{
	VAR(uint16, AUTOMATIC) Index_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) CE_Cnt_T_lgc;             /* Comm Enable        FALSE-> OFF            / TRUE-> ON */
	VAR(boolean, AUTOMATIC) PM_Cnt_T_lgc;             /* Power Mode         FALSE-> !Run           / TRUE-> Run */
	VAR(boolean, AUTOMATIC) ER_Cnt_T_lgc;             /* Engine Running     FALSE-> !On            / TRUE-> On */
	VAR(boolean, AUTOMATIC) VS_Cnt_T_lgc;             /* Vehicle Speed      FALSE-> < K            / TRUE-> >= K */
	VAR(boolean, AUTOMATIC) ER0C9Miss_Cnt_T_lgc;      /* ER 0C9 Missing     FALSE-> Not Missing    / TRUE-> Missing */
	VAR(boolean, AUTOMATIC) PM1F1Miss_Cnt_T_lgc;      /* PM 1F1 Missing     FALSE-> Not Missing    / TRUE-> Missing */
	VAR(boolean, AUTOMATIC) VSValid_Cnt_T_lgc;        /* Veh Speed Valid    FALSE-> Not Valid      / TRUE-> Valid */
	VAR(boolean, AUTOMATIC) BusOff_Cnt_T_lgc;         /* Bus Off            FALSE-> No Bus Off     / TRUE-> BusOff */
	VAR(boolean, AUTOMATIC) SterringTorque_Cnt_T_lgc; /* Sterring Torque    FALSE-> < K            / TRUE-> >= K */
	VAR(boolean, AUTOMATIC) Assist_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) VarEffort_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) VehSpd_Kph_T_f32;

	/* Read inputs */
	(void)Rte_Call_EpsEn_OP_GET(&CE_Cnt_T_lgc);
	PM_Cnt_T_lgc = Rte_IRead_VehPwrMd_Per1_SrlComSPMOn_Cnt_lgc();
	ER_Cnt_T_lgc = Rte_IRead_VehPwrMd_Per1_SrlComEngOn_Cnt_lgc();
	VehSpd_Kph_T_f32 = Rte_IRead_VehPwrMd_Per1_VehSpd_Kph_f32();
	VS_Cnt_T_lgc = (VehSpd_Kph_T_f32 >= k_GmVPMod_VehSpdMinKeepAssist_Kph_f32)? TRUE : FALSE;
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_O, &PM1F1Miss_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_MissingMsg_N, &ER0C9Miss_Cnt_T_lgc);
	VSValid_Cnt_T_lgc = Rte_IRead_VehPwrMd_Per1_VehSpdValid_Cnt_lgc();
	(void)Rte_Call_NxtrDiagMgr_GetNTCFailed(NTC_Num_BusOffCh1, &BusOff_Cnt_T_lgc);
	SterringTorque_Cnt_T_lgc = (VehPwrMd_HwTorqueSt_Cnt_M_enum != HWTRQSAFETOOFF)? TRUE : FALSE;

	Index_Cnt_T_u16 = SterringTorque_Cnt_T_lgc;
	Index_Cnt_T_u16 |= ((uint16)BusOff_Cnt_T_lgc << 1);
	Index_Cnt_T_u16 |= ((uint16)PM1F1Miss_Cnt_T_lgc << 2);
	Index_Cnt_T_u16 |= ((uint16)VSValid_Cnt_T_lgc << 3);
	Index_Cnt_T_u16 |= ((uint16)ER0C9Miss_Cnt_T_lgc << 4);
	Index_Cnt_T_u16 |= ((uint16)VS_Cnt_T_lgc << 5);
	Index_Cnt_T_u16 |= ((uint16)ER_Cnt_T_lgc << 6);
	Index_Cnt_T_u16 |= ((uint16)PM_Cnt_T_lgc << 7);
	Index_Cnt_T_u16 |= ((uint16)CE_Cnt_T_lgc << 8);

	Assist_Cnt_T_lgc = T_VehPwrMdSystemState_Cnt_u08[Index_Cnt_T_u16];
	VarEffort_Cnt_T_lgc = T_VehPwrMdVariableEffort_Cnt_u08[Index_Cnt_T_u16];

	*Assist_Cnt_lgc = Assist_Cnt_T_lgc;
	*VarEffort_Cnt_lgc = VarEffort_Cnt_T_lgc;

	/* Update a display variable for debug purposes */
	VehPwrMd_Assist_Cnt_D_u16 = Index_Cnt_T_u16;
	VehPwrMd_Assist_Cnt_D_u16 |= ((uint16)Assist_Cnt_T_lgc << 9);
	VehPwrMd_Assist_Cnt_D_u16 |= ((uint16)VarEffort_Cnt_T_lgc << 10);
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
