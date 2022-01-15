
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Sa_MtrVel_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 30.11.2012 08:09:43
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          EA3#3 %
 * %date_modified:    Fri Aug 30 13:53:58 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 07/13/12   1       JJW       Initial template creation
 */

#ifndef MTRVEL_CFG_H
#define MTRVEL_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/
#include "CDD_Data.h"


#define D_MTRVELOSBUFSZ_CNT_U08    8u   /*Based on the Buffer size*/
   
#define MtrVel_Read_MechMtrPos1_Rev_u0p16(ptr)  (*(ptr) = CDD_MtrPosMecl_RevM_G_u0p16[CDD_CDDDataAccessBfr_Cnt_G_u16])   /* This is native to MtrCtrl Loop */
#define MtrVel_Read_MechMtrPos1TimeStamp_uS_u32(ptr)   (*(ptr) =  CDD_MotMeclPosn1MeasdTi_uS_G_u32[CDD_CDDDataAccessBfr_Cnt_G_u16])    /* This is native to MtrCtrl Loop, but is buffered because it is also used in 2ms loop */

#endif /* MTRVEL_CFG_H */

/*** End of file **************************************************************/
