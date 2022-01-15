/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EcuStartup.h
* Module Description: AUTOSAR Startup Sequence
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          1 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Mon Jul 29 08:28:14 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 */

#ifndef ECUSTARTUP_H 
#define ECUSTARTUP_H  

/***************************************************************************************************
* Include files
***************************************************************************************************/

#include "Platform_Types.h"

/**************************************************************************************************
* Defines / Constants
**************************************************************************************************/



/* Prototypes */
extern void EcuStartup_Init1(void);
extern void EcuStartup_Init2(void);

extern void MemChk_StartFlashCRC(void);
extern void AppDesc_Init(void);

#endif /*ECUSTARTUP_H*/
