/*****************************************************************************
* Copyright 2015 Nexteer Automotive
* Nexteer Confidential
*
* Module File Name  : DigMSBArbn_Cfg.h
* Module Description: Integration Configuration file of DigMSBArbn module
* Product           : Gen II Plus - EA3.0
* Author            : Srujan Maram
*****************************************************************************/
/* Version Control:
 * Date Created:      Thu May 14 11:13:40 2015
 * %version:          1 %
 * %date_modified:    Fri May 22 02:23:26 2015 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 05/22/15   1       Srujan      Initial template creation													 EA3#1648
 */

#ifndef DIGMSBARBN_CFG_H
#define DIGMSBARBN_CFG_H

/* integrator to add any #includes needed for the macro definitions below */
#include "CDD_Data.h"


/* integrator to complete the macro definitions below as needed for the motor control loop reads and writes */
/* typically these will be reading/writing global variables defined in CDD_Interface */

#define DigMSBArbn_Read_MtrPos1Mecl_RevM_u0p16(ptr)     *ptr= CDD_MotMeclPosn1RevM_G_u0p16[CDD_CDDDataAccessBfr_Cnt_G_u16]
#define DigMSBArbn_Read_MtrPos1Qlfr_State_enum(ptr)     *ptr= CDD_MotMeclPosn1MotPosnQlfrCnt_G_u08[CDD_CDDDataAccessBfr_Cnt_G_u16]
#define DigMSBArbn_Read_MtrPos1RollgCntr_Cnt_u08(ptr)   *ptr= CDD_MotMeclPosn1RollgCntr_Cnt_G_u08[CDD_CDDDataAccessBfr_Cnt_G_u16]
#define DigMSBArbn_Read_MtrPos2Mecl_RevM_u0p16(ptr)     *ptr= CDD_MotMeclPosn2RevM_G_u0p16[CDD_CDDDataAccessBfr_Cnt_G_u16]
#define DigMSBArbn_Read_MtrPos2Qlfr_State_enum(ptr)     *ptr= CDD_MotMeclPosn2MotPosnQlfrCnt_G_u08[CDD_CDDDataAccessBfr_Cnt_G_u16]
#define DigMSBArbn_Read_MtrPos2RollgCntr_Cnt_u08(ptr)   *ptr= CDD_MotMeclPosn2RollgCntr_Cnt_G_u08[CDD_CDDDataAccessBfr_Cnt_G_u16]
#define DigMSBArbn_Read_MtrPosCorrlnSts_Cnt_u16(ptr)    *ptr= CDD_MotAgCorrlnMtrPosCorrlnSts_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16]

#define DigMSBArbn_Write_MtrPosMecl_RevM_u0p16(var)     CDD_MtrPosMecl_RevM_G_u0p16[CDD_CDDDataAccessBfr_Cnt_G_u16] = (var)


/*** End of file **************************************************************/

#endif /* DIGMSBARBN_CFG_H */
