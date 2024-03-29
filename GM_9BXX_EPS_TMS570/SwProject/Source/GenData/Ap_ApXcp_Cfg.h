
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_ApXcp_Cfg.h
* Module Description: Configuration file of Xcp module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 06.11.2013 09:56:02
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          4 %
 * %date_modified:    Mon Oct 28 11:43:26 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 01/07/13   1       LWW       Initial template creation
 * 10/28/13   4       KJS       Changed configuration to support new TOTF configuration layout for segments
 *								0, 1, 2, 3, 4, and 16. 
 */

#ifndef AP_XCP_CFG_H
#define AP_XCP_CFG_H

#include "Std_Types.h"                   /* Standard type definitions      */

/*** Private Part (used by Ap_ApXcp.c only) *************************************/
#ifdef APXCP_C

#define D_NUMOFOSAPPS_CNT_U8					4U
	
#define D_NUMOFVLDMEMRGNS_CNT_U08				2U

#define BC_XCP_EXTEEPACCESS	STD_OFF


/* Tune on the Fly Enabled */
#include "CalConstants.h"

#define BC_XCP_TUNEONFLY			STD_ON
#define BC_XCP_TOTFRAMSIZE_CNT_U32	4096UL

/* Segment 0: Enabled */
#define BC_XCP_SEG0ENABLE			STD_ON
#define BC_XCP_MAXPERCOPY_CNT_U8	1U
#define BC_XCP_PERSINDEXLOOKUP		STD_OFF
/* Configuration Check */
#if(BC_XCP_MAXPERCOPY_CNT_U8 > D_NUMOFPERS_CNT_U16)
	#error "Incorrect configuration: MAXPERCOPY larger than number of available personalities."
#endif

/* Segment 1: Enabled */
#define BC_XCP_SEG1ENABLE			STD_ON
#define BC_XCP_MAXSETCOPY_CNT_U8	1U
#define BC_XCP_SETINDEXLOOKUP		STD_OFF
/* Configuration Check */
#if(BC_XCP_MAXSETCOPY_CNT_U8 > D_NUMOFTUNSETS_CNT_U16)
	#error "Incorrect configuration: MAXSETCOPY larger than number of available sets."
#endif

/* Segment 2: Disabled */

/* Segment 3: Disabled */

/* Segment 4: Disabled */

/* Segment 16: Disabled */

/* End Tune on the Fly Options */

#endif

#endif /* AP_APXCP_CFG_H */

/*** End of file **************************************************************/
