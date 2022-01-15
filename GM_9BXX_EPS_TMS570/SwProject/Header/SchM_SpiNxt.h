#ifndef SCHM_SPINXT_H
#define SCHM_SPINXT_H

#include "Os.h"

#define SPINXT_EXCLUSIVE_AREA_0

/* Exclusive area stubs for unit testing hooks */
#define SchM_Enter_SpiNxt(ExclusiveAreaNumber) SuspendAllInterrupts()
#define SchM_Exit_SpiNxt(ExclusiveAreaNumber) ResumeAllInterrupts()

#endif/* double include preventer */

