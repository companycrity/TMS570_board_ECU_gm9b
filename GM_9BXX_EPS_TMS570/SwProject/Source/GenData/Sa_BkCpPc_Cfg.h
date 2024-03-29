
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Sa_BkCpPc_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 25.07.2013 15:06:47
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          1 %
 * %date_modified:    Mon Jul 29 08:40:03 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/20/12   1       ssk       Initial template creation
 * 05/29/13   2       BDO       Anomaly 5092 - Add D_PWRDISCCONFIGURATION_CNT_U08 - FDD ES-11B v003 	 	
 */

#ifndef SA_BKCPPC_CFG_H
#define SA_BKCPPC_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/


#define D_PWRDISCCONFIGURATION_CNT_U08	1U


/* Disable all checkpoints that are not enabled */
#define Rte_Call_BkCpPc_Per1_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_BkCpPc_Per1_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
   
#endif /* BKCPPC_CFG_H */

/*** End of file **************************************************************/
