
/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_ApXcp_Cfg.c
* Module Description: Configuration file of Xcp module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 06.11.2013 09:56:04
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          5 %
 * %date_modified:    Thu Jul 18 10:58:51 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 01/07/13   1       LWW       Initial template creation
 * 06/26/13   3       KJS       Added preprocessor statements to control memcpy statements
 * 07/09/13   4       JJW       Added generation of Rte runnalbes for the configured Rte mapped Xcp Events
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#define APXCP_C /* Enable visibility to Module internal definitions in Ap_ApXcp.h*/
#include "Ap_ApXcp.h"
#include "Lnk_Symbols.h"
#include "NtWrap.h"

/*******************************************************************************
**                      Public Data                                           **
*******************************************************************************/
CONST(uint32, AUTOMATIC) T_AllowedMemRegion_Cnt_u32[D_NUMOFVLDMEMRGNS_CNT_U08][2] =
{ 
	{ 0x08000000UL, 0x0801FFFFUL },
	{ 0x00000000UL, 0x000BFFFFUL },
};


CONST(uint8, AUTOMATIC) T_AppIndex_Cnt_u08[D_NUMOFOSAPPS_CNT_U8] =
{ 10U, 8U, 9U, 0U, };

CONST(uint8, AUTOMATIC) T_FunctionIndex_Cnt_u08[D_NUMOFOSAPPS_CNT_U8] =
{ NtWrapS_XcpWriteAp10, NtWrapS_XcpWriteAp8, NtWrapS_XcpWriteAp9, TWrapS_XcpWriteAp0,};

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DAQ_2msTL
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2
 *
 *********************************************************************************************************************/
FUNC(void, AUTOMATIC) DAQ_2msTL(void)
{
	XcpEvent(XcpEventChannel_2ms_DAQ_2);
}


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CopyCalsToRam
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * SWC internal function executed by ApXcp_Init()
 *
 *********************************************************************************************************************/
FUNC(void, AUTOMATIC) CopyCalsToRam(void)
{
#if( (D_ENABLEMETRICS_CNT_LGC != STD_ON) && (BC_TUNINGSETINRAM == 1U) )
#endif
}
