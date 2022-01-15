/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : SchM_WdgIf.h
* Module Description: SchM Include
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/* Version Control:
 * Date Created:      Mon Jul 29 08:08:40 2013
 * %version:          1 %
 * %derived_by:       CZ8L9T %
 * %date_modified:    Mon Jul 29 08:08:40 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 */

#ifndef SCHM_WDGIF_H
#define SCHM_WDGIF_H

#include "Os.h"

#define SchM_Enter_WdgIf(ExclusiveAreaNumber)		SuspendAllInterrupts()
#define SchM_Exit_WdgIf(ExclusiveAreaNumber)		ResumeAllInterrupts()

#endif /* __SCHM__ */

#endif /* SCHM_WDGIF_H */
