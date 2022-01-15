/*****************************************************************************
* Copyright 2015 Nexteer 
* Nexteer Confidential
*
* Module File Name  : Sa_DigMSBArbn.c
* Module Description: Non-AUTOSAR Module created for checking Signal Availability for Motor Position 1 and 2 and
* 					  passes which ever is available (preferably Motor Position 1)
*
* Product           : CBD
* Author            : Srujan Maram
*****************************************************************************
* Version Control:
* %version:          EA3#2 %
* %derived_by:       nz2999 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     ----------
 * 05/29/15   1        Srujan     Digital MtrPos Sensor Arbitration initial implementation						EA3#1648
 * 12/15/16   2        KByrski    Update as per FDD v3, using of average signals values instead of previous one EA3#13029
 *
 */
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Rte_Type.h" /* for SigQlfr_State_enum definition */
#include "GlobalMacro.h"
#include "fixmath.h"
#include "CalConstants.h"
#include "Sa_DigMSBArbn.h"
#include "DigMSBArbn_Cfg.h"

/* MISRA-C:2004 Rule 19.1: This deviation is required for AUTOSAR memory map requirements.  Rule suppressed by line at each occurrence. */
/* MISRA-C:2004 Rule 8.7: This deviation is required to keep the memory map intact.  Rule suppressed by line at each occurrence. */

#define D_MAXSTALL_CNT_U08						((uint8)255U)
#define D_BITMAPZERO_CNT_U16					((uint16)0x0001U)
#define D_BITMAPONE_CNT_U16						((uint16)0x0002U)
#define D_ONE_CNT_U08							((uint8)1U)
#define D_MINMTRPOSMECH_CNT_U0P16				(FPM_InitFixedPoint_m(0.0, u0p16_T))
#define D_MAXMTRPOSMECH_CNT_U0P16				(FPM_InitFixedPoint_m(0.9999847412, u0p16_T))

#define DIGMSBARBN_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, SA_DIGMSBARBN_VAR_NOINIT)  DigMSBAR_PrevMtrPos1RollgCntr_Cnt_M_u08;/* PRQA S 3218 */
STATIC VAR(uint8, SA_DIGMSBARBN_VAR_NOINIT)  DigMSBAR_PrevMtrPos2RollgCntr_Cnt_M_u08;/* PRQA S 3218 */
STATIC VAR(uint8, SA_DIGMSBARBN_VAR_NOINIT)  DigMSBAR_PrevMtrPos1Stall_Cnt_M_u08;/* PRQA S 3218 */
STATIC VAR(uint8, SA_DIGMSBARBN_VAR_NOINIT)  DigMSBAR_PrevMtrPos2Stall_Cnt_M_u08;/* PRQA S 3218 */
#define DIGMSBARBN_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
 
STATIC INLINE FUNC(boolean, SA_DIGMSBARBN_CODE) SigAvlCheck( VAR(SigQlfr_State_enum, AUTOMATIC) MtrPosxQlfr_State_T_enum,
                    VAR(uint8, AUTOMATIC) MtrPosxRollgCntr_Cnt_T_u08,
                    VAR(uint8, AUTOMATIC) MtrPosxMaxStall_Cnt_T_u08,
                    P2VAR(uint8, AUTOMATIC, AUTOMATIC) PrevMtrPosxRollgCntr_Cnt_T_u08,
                    P2VAR(uint8, AUTOMATIC, AUTOMATIC) PrevMtrPosxStall_Cnt_T_u08,
                    VAR(uint16, AUTOMATIC) MtrPosCorrlnSts_Cnt_T_u16
                    );


/**********************************************************************************************************************
 *
 * Function Name: 	DigMSBArbn_Per1
 *
 * Description:     Checks Signal Availability for Motor Position 1 and 2.
 * 					Passes which ever is available (preferably Motor Position 1)
 *
 * Inputs:          MtrPos1Mecl_RevM_u0p16
 *                  MtrPos1Qlfr_State_enum
 *                  MtrPos1RollgCntr_Cnt_u08
 *                  MtrPos2Mecl_RevM_u0p16
 *                  MtrPos2Qlfr_State_enum
 *                  MtrPos2RollgCntr_Cnt_u08
 *                  MtrPosCorrlnSts_Cnt_u16
 *
 * Outputs:         MtrPosMecl_RevM_u0p16
 *
 * Usage Notes:     Called from the motor control ISR
 *                  All inputs/outputs are read/written using macros defined in DigMSBArbn_Cfg.h
 *
 *********************************************************************************************************************/

FUNC(void, SA_DIGMSBARBN_CODE) DigMSBArbn_Per1(void)
 {
	VAR(boolean, AUTOMATIC) MtrPos1SigAv_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) MtrPos2SigAv_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC)  MtrPos1RollgCntr_Cnt_T_u08;
	VAR(uint8, AUTOMATIC)  MtrPos2RollgCntr_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) MtrPos1Mech_RevM_T_u0p16;
	VAR(uint16, AUTOMATIC) MtrPos2Mech_RevM_T_u0p16;
	VAR(uint16, AUTOMATIC) MtrPosMech_RevM_T_u0p16;
	VAR(uint16, AUTOMATIC) MtrPosCorrlnSts_Cnt_T_u16;
	VAR(SigQlfr_State_enum, AUTOMATIC) MtrPos1Qlfr_State_T_enum;
    VAR(SigQlfr_State_enum, AUTOMATIC) MtrPos2Qlfr_State_T_enum;

    /**********Read Inputs**************/
    DigMSBArbn_Read_MtrPos1Mecl_RevM_u0p16(&MtrPos1Mech_RevM_T_u0p16);
    DigMSBArbn_Read_MtrPos1Qlfr_State_enum(&MtrPos1Qlfr_State_T_enum);
    DigMSBArbn_Read_MtrPos1RollgCntr_Cnt_u08(&MtrPos1RollgCntr_Cnt_T_u08);
    DigMSBArbn_Read_MtrPos2Mecl_RevM_u0p16(&MtrPos2Mech_RevM_T_u0p16);
    DigMSBArbn_Read_MtrPos2Qlfr_State_enum(&MtrPos2Qlfr_State_T_enum);
    DigMSBArbn_Read_MtrPos2RollgCntr_Cnt_u08(&MtrPos2RollgCntr_Cnt_T_u08);
    DigMSBArbn_Read_MtrPosCorrlnSts_Cnt_u16(&MtrPosCorrlnSts_Cnt_T_u16);


	/***********Motor Position 1 signal Availability Check *****************/
	MtrPos1SigAv_Cnt_T_lgc = SigAvlCheck(MtrPos1Qlfr_State_T_enum,
										 MtrPos1RollgCntr_Cnt_T_u08,
										 k_DigMSBAR_MtrPos1MaxStall_Cnt_u08,
										 &DigMSBAR_PrevMtrPos1RollgCntr_Cnt_M_u08,
										 &DigMSBAR_PrevMtrPos1Stall_Cnt_M_u08,
										 (MtrPosCorrlnSts_Cnt_T_u16 & D_BITMAPZERO_CNT_U16));

	/***********Motor Position 2 signal Availability Check *****************/
	MtrPos2SigAv_Cnt_T_lgc = SigAvlCheck(MtrPos2Qlfr_State_T_enum,
			  	  	  	  	  	  	     MtrPos2RollgCntr_Cnt_T_u08,
			  	  	  	  	  	  	     k_DigMSBAR_MtrPos2MaxStall_Cnt_u08,
										 &DigMSBAR_PrevMtrPos2RollgCntr_Cnt_M_u08,
										 &DigMSBAR_PrevMtrPos2Stall_Cnt_M_u08,
										 (MtrPosCorrlnSts_Cnt_T_u16 & D_BITMAPONE_CNT_U16));

	
	if (MtrPos1SigAv_Cnt_T_lgc == TRUE)
	{
		MtrPosMech_RevM_T_u0p16 = MtrPos1Mech_RevM_T_u0p16;
	}
	else if (MtrPos2SigAv_Cnt_T_lgc == TRUE)
	{
		MtrPosMech_RevM_T_u0p16 = MtrPos2Mech_RevM_T_u0p16;
	}
	else
	{
		MtrPosMech_RevM_T_u0p16 = (uint16) ((((uint32) MtrPos1Mech_RevM_T_u0p16) + ((uint32) MtrPos2Mech_RevM_T_u0p16)) / 2U);
	}

	MtrPosMech_RevM_T_u0p16 = Limit_m(MtrPosMech_RevM_T_u0p16, D_MINMTRPOSMECH_CNT_U0P16, D_MAXMTRPOSMECH_CNT_U0P16);

	/**********Write Outputs**************/
	DigMSBArbn_Write_MtrPosMecl_RevM_u0p16(MtrPosMech_RevM_T_u0p16);
	
 }

/*****************************************************************************
  * Function Name:      SigAvlCheck
  *
  * Description: 		Checks Signal Availability for Motor Position 1 and 2
  *
  * Inputs:      		MtrPosxQlfr_State_T_enum           - Motor Position State Qualifier
  *              		MtrPosxRollgCntr_Cnt_T_u08         - Motor Position Rolling Counter
  *              		MtrPosxMaxStall_Cnt_T_u08          - calibration for counting Motor Position Stall
  *              		*PreMtrPosxRollgCntr_Cnt_T_u08     - Motor Position Rolling Counter Previous Value
  *              		*MtrPosxStall_Cnt_T_u08            - Motor Position Stall Counter previous value
  *				 		MtrPosCorrlnSts_Cnt_T_u16		   - Motor Position Correlation Status value
  *
  * Outputs:     		return value          - boolean indicating signal availability
  *              		*PreMtrPosxRollgCntr_Cnt_T_u08     - updated value of Motor Position Rolling Counter previous value
  *              		*MtrPosxStall_Cnt_T_u08            - updated value of Motor Position Stall Counter previous value
  *
*****************************************************************************/
STATIC INLINE FUNC(boolean, SA_DIGMSBARBN_CODE) SigAvlCheck( VAR(SigQlfr_State_enum, AUTOMATIC) MtrPosxQlfr_State_T_enum,
                     VAR(uint8, AUTOMATIC) MtrPosxRollgCntr_Cnt_T_u08,
                     VAR(uint8, AUTOMATIC) MtrPosxMaxStall_Cnt_T_u08,
                     P2VAR(uint8, AUTOMATIC, AUTOMATIC) PrevMtrPosxRollgCntr_Cnt_T_u08,
                     P2VAR(uint8, AUTOMATIC, AUTOMATIC) PrevMtrPosxStall_Cnt_T_u08,
                     VAR(uint16, AUTOMATIC) MtrPosCorrlnSts_Cnt_T_u16
                     )
 {
     VAR(boolean, AUTOMATIC) SignalAvailable_Cnt_T_lgc;
     VAR(uint8, AUTOMATIC) MtrPosxStall_Cnt_T_u08;

     /* Check if the current RC is equal to previous RC value*/
     /* Signal is not available under two conditions
        1) There is Stall in the rolling counter value( Calibration determine the max stall value)
        2) Signal Qualifier indicates failed state in Motor Position
      */

     if (*PrevMtrPosxRollgCntr_Cnt_T_u08 ==  MtrPosxRollgCntr_Cnt_T_u08)
     {
       if (*PrevMtrPosxStall_Cnt_T_u08 != D_MAXSTALL_CNT_U08)
       {
    	   MtrPosxStall_Cnt_T_u08 = (uint8)(*PrevMtrPosxStall_Cnt_T_u08 + D_ONE_CNT_U08);
       }
       else
       {
    	   MtrPosxStall_Cnt_T_u08 = D_MAXSTALL_CNT_U08;
       }
     }
     else
     {
        *PrevMtrPosxRollgCntr_Cnt_T_u08 = MtrPosxRollgCntr_Cnt_T_u08;
        MtrPosxStall_Cnt_T_u08 = 0U;
     }
	 
	 *PrevMtrPosxStall_Cnt_T_u08 = MtrPosxStall_Cnt_T_u08;

     if (MtrPosxStall_Cnt_T_u08 >= MtrPosxMaxStall_Cnt_T_u08)
     {
    	 SignalAvailable_Cnt_T_lgc = FALSE;
     }
     else
     {
    	 if ((MtrPosxQlfr_State_T_enum < SIGQLFR_FAIL) && (MtrPosCorrlnSts_Cnt_T_u16 > 0U))
    	 {
    		 SignalAvailable_Cnt_T_lgc = TRUE;
    	 }
    	 else
    	 {
    		 SignalAvailable_Cnt_T_lgc = FALSE;
       	 }
     }

     return SignalAvailable_Cnt_T_lgc;
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
