
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_HwPwUp_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 31.08.2015 11:48:26
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          EA3#2 %
 * %date_modified:    Mon Jul 29 09:30:54 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/20/12   1       ssk       Initial template creation
 * 11/08/12   2       jjw       added D_PGMSPECMASK_CNT_U16 gen
 * 	 	
 */

#ifndef AP_HWPWUP_CFG_H
#define AP_HWPWUP_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/


#define D_PGMSPECMASK_CNT_U16	1U


/* Disable all checkpoints that are not enabled */
#define Rte_Call_HwPwUp_Per1_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_HwPwUp_Per1_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
   
#endif /* HWPWUP_CFG_H */

/*** End of file **************************************************************/
