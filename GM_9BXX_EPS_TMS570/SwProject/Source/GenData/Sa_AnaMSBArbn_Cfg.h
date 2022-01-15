/*****************************************************************************
* Copyright 2015 Nexteer Automotive
* Nexteer Confidential
*
* Module File Name  : Sa_AnaMSBArbn_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
*****************************************************************************/
/* Version Control:
 * Date Created:      Tue Mar  3 09:39:04 2015
 * %version:          1 %
 * %date_modified:    Tue Mar  3 09:39:04 2015 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 03/11/15   1       Selva      Initial template creation                                                    CR13083
 */

#ifndef  ANAMSBARBN_CFG_H
#define  ANAMSBARBN_CFG_H


/*******************************************************************************
**                      Define Section                                        **
*******************************************************************************/
/* Map these Write Macro's*/
#define AnaMSBArbn_Write_SampleTime_uS_u32(Val)                           /* MtrVel */
#define AnaMSBArbn_Write_SinTheta1_Volt_s2p13(Val)                        /* MtrVel */
#define AnaMSBArbn_Write_CosTheta1_Volt_s2p13(Val)                        /* MtrVel */
#define AnaMSBArbn_Write_MtrPosCorrd_Rev_u0p16(Val)
#define AnaMSBArbn_Write_MechMtrPos_Rev_u0p16(Val)                        /* MtrVel */

#define AnaMSBArbn_Write_MtrPos1Sin_Volt_u3p13(Val)                      /* Use CDD interface and buffering scheme to provide sync */
#define AnaMSBArbn_Write_MtrPos1Cos_Volt_u3p13(Val)                      /* Use CDD interface and buffering scheme to provide sync */
#define AnaMSBArbn_Write_MtrPos2Sin_Volt_u3p13(Val)                      /* Use CDD interface and buffering scheme to provide sync */
#define AnaMSBArbn_Write_MtrPos2Cos_Volt_u3p13(Val)                      /* Use CDD interface and buffering scheme to provide sync */


/* Variables Read */
/* TODO [GMN] Integrate */
#define AnaMSBArbn_Read_MtrPosCorrlnSts_Cnt_u16(ptr)                    *(ptr) = 1  /* Signal from AnaMSBCorrelation */
#define AnaMSBArbn_Read_MtrPos1Sin_Volt_u3p13(ptr)                      *(ptr) = 1  /* Output from Adc2*/
#define AnaMSBArbn_Read_MtrPos1Cos_Volt_u3p13(ptr)                      *(ptr) = 1  /* Output from Adc2 */
#define AnaMSBArbn_Read_MotMeclPosn1Polarity_Uls_s08(ptr)               *(ptr) = 1
#define AnaMSBArbn_Read_MtrPos2Sin_Volt_u3p13(ptr)                      *(ptr) = 1  /* Output from Adc2*/
#define AnaMSBArbn_Read_MtrPos2Cos_Volt_u3p13(ptr)                      *(ptr) = 1  /* Output from Adc2*/
#define AnaMSBArbn_Read_MotMeclPosn2Polarity_Uls_s08(ptr)               *(ptr) = 1


/*** End of file **************************************************************/

#endif /* ANAMSBARBN_CFG_H */
