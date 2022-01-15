/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : SchM_NvMProxy.h
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

#ifndef SCHM_NVMPROXY_H
# define SCHM_NVMPROXY_H

#include "Os.h"

#define SchM_Enter_NvMProxy(ExclusiveAreaNumber)	SuspendAllInterrupts()
#define SchM_Exit_NvMProxy(ExclusiveAreaNumber)		ResumeAllInterrupts()

#endif /* SCHM_NVMPROXY_H */
