/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Cd_PhaseFdbkMeas.h
* Module Description: Nhet1 Configuration and Use global header file
* Product           : Gen II Plus - EA3.0
* Author            : Rijvi ahmed
*****************************************************************************/
/* Version Control:
 * Date Created:      Wed Jun 03 10:56:00 2015 %
 * %version:          1 %
 * %derived_by:       jzk9cc %
 * %date_modified:    Wed Jun 03 10:56:00 2015 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 06/25/15  1        Yue Zhao       Nhet1 Configuration and Use, implementation of FDD_36A					EA3#1303
 */



#ifndef CD_PHASEFDBKMEAS_H
#define CD_PHASEFDBKMEAS_H


#include "Nhet_PhaseFdbkMeas_Prog.h"
#include "Std_Types.h"
#include "n2het_regs.h"
#include "std_nhet.h"


/* Global PhaseFdbkMeas Functions for Nhet1 initialization */
FUNC(void, PHASEFDBKMEAS_CODE) Cd_PhaseFdbkMeas_Init1(void);


#endif
