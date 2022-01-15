/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Lnk_Symbols.h
* Module Description: This file contains the declarations of Link Time Symbols
*                     used in the application.
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          1 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Mon Jul 29 08:26:57 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 */

#ifndef LNK_SYMBOLS_H
#define LNK_SYMBOLS_H

#include "Std_Types.h"

extern CONST(uint32, AUTOMATIC) Lnk_TypeH_Start;
extern CONST(uint32, AUTOMATIC) Lnk_TypeH_Size;

extern CONST(uint32, AUTOMATIC) Lnk_BSS_Start;
extern CONST(uint32, AUTOMATIC) Lnk_BSS_End;

extern CONST(uint32, AUTOMATIC) Lnk_BootRelNum_Addr;

#endif

