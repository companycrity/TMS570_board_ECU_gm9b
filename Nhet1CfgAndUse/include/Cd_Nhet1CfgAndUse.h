/*****************************************************************************
* Copyright 2015 Nexteer 
* Nexteer Confidential
*
* Module File Name  : Cd_Nhet1CfgAndUse.h
* Module Description: Nhet1 configuration and use
* Product           : CBD
* Author            : Yue Zhao
*****************************************************************************/
/* Version Control:
 * Date Created:      Tue Jun 09 12:17:00 2015 %
 * %version:          1 %
 * %derived_by:       gzdv8b %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/10/15  1        Yue Zhao       Initial   Version, Nhet1 configuration and use							EA3#1297
 */


#ifndef CD_NHET1CFGANDUSE_H
#define CD_NHET1CFGANDUSE_H

#include "Std_Types.h"
#include "n2het_regs.h"
#include "htu_regs.h"
#include "std_nhet.h"
#include "Nhet1CfgAndUse_Prog.h"


#define D_CBUFLEN_CNT_U16		8U	
/* # of time stamps for rising and falling edges stored in main system RAM*/
typedef struct{

		uint32 HtuDataTrq1_Cnt_u32[D_CBUFLEN_CNT_U16]; /* Main input capture circular buffer (for HTU transfers from HET RAM to main CPU RAM */
		uint32 HtuDataTrq2_Cnt_u32[D_CBUFLEN_CNT_U16]; /* Main input capture circular buffer (for HTU transfers from HET RAM to main CPU RAM*/

}HtuDataTrq_Str;
									
extern volatile VAR(HtuDataTrq_Str, AUTOMATIC)  Nhet1CfgAndUse_HtuDataTrq_Cnt_G_str;
extern VAR(boolean, AUTOMATIC) Nhet1CfgAndUse_Htu1RstFail_Cnt_G_lgc;/* Global variable for peripheral startup diagnostic -- HTU1 failed to exit reset */


/* Global Nhet1CfgAndUse Function for NHET_1 and HTU initialization */
FUNC(void, NHET1CFGANDUSE_CODE) Nhet1CfgAndUse_Init(void);
FUNC(void, NHET1CFGANDUSE_CODE) Nhet1CfgAndUse_Per3(void);
	

#endif
