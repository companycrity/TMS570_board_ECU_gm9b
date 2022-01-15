/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : CDD_Func.h
* Module Description: Header file for functions communicated between Nexteer
*                      Complex Device Drivers (CDD)
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#2 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Mon Jul 29 08:16:41 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 12/01/15  2        GMN       EA3#4064: Update SF-99 and 83.3Hz noise reduction                             4962
 * 03/30/16  3        GMN       EA3#2923: CDDInterface update                                                 6951
 */

#ifndef CDD_FUNC_H
#define CDD_FUNC_H

#include "Std_Types.h"

extern FUNC(void, SA_MTRPOS_CODE) MtrPos_Per1(void);
extern FUNC(void, RTE_AP_MICRODIAG_APPL_CODE) MicroDiag_Per1(void);
extern FUNC(void, PWMCDD_CODE) CDD_ApplyPWMMtrElecMechPol(sint8 MtrElecMechPol_Cnt_s8);

/* TODO: Determine if the  CalRamInit really needs to execute as a CDD early in init */
/*        if it is determined that RAM cals are only used after RTE Start, then this */
/*        function can be removed from here and scheduled in Developer               */
extern FUNC(void, XCP_CODE) Xcp_CalRamInit(void);
extern FUNC(void, CDDInterface_CODE) CDDInterface_Per5(void);

#endif
