/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : SchM_EcuM.h
* Module Description: SchM Include
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Mon Jul 29 08:08:40 2013
 * %version:          1 %
 * %derived_by:       czgng4 %
 * %date_modified:    Mon Jul 29 08:08:40 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 */

#ifndef SCHM_ECUM_H
#define SCHM_ECUM_H

#include "Os.h"

#define ECUM_ACTIVATION_POINT_0   ACT_TIMEOUT_EVENT_10MS

#define SchM_Enter_EcuM(ExclusiveAreaNumber)		SuspendAllInterrupts()
#define SchM_Exit_EcuM(ExclusiveAreaNumber)		ResumeAllInterrupts()

#endif /* SCHM_ECUM_H */
