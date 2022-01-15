/*****************************************************************************
* Copyright 2012 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Ap_DemIf.h
* Module Description: DemIf Include
* Product           : Gen II Plus - EA3.0
* Author            : Lucas Wendling
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Jul 28 18:03:04 2012
* %version:          1 %
* %derived_by:       CZ8L9T %
* %date_modified:    Tue Sep 10 12:14:26 2013 %
*---------------------------------------------------------------------------*/


#ifndef AP_DEMIF_H_
#define AP_DEMIF_H_

#include "Dem_Lcfg.h"

#ifndef DIAGMGR_C
	#define DIAGMGR_C
	#ifdef DIAGMGR_CFG_H
		#undef DIAGMGR_CFG_H
	#endif
#endif

#include "DiagMgr_Cfg.h"

#define NVM_E_REQ_FAILED   Dem_NVM_E_REQ_FAILED
#define NVM_E_INTEGRITY_FAILED  Dem_NVM_E_INTEGRITY_FAILED

typedef struct Dem_OptimizedNvMDataTypeTag
{
  uint8 consistencyPattern[DEM_NVDATA_PATTERN_SIZE];
  Dem_DtcChronoRefType chronoPriMemUsed;
  uint8 primaryStack[DEM_MAX_NUMBER_EVENT_ENTRY][DEM_MAX_SNAPSHOT_RECORD_SIZE+1];
  Dem_ChronoPriMemType chronoPriMem[DEM_MAX_NUMBER_EVENT_ENTRY];
  Dem_DtcStatusByteType dtcStatusByte[D_NUMOFDEMEVENTS_CNT_U08+1];
  uint8 dtcAgingCounter[DEM_MAX_NUMBER_EVENT_ENTRY];
  Dem_EventIdType firstFailedEvent;
  Dem_EventIdType firstConfirmedEvent;
  Dem_EventIdType mostRecentFailedEvent;
  Dem_EventIdType mostRecentConfirmedEvent;
  uint8 terminatingPattern[DEM_NVDATA_PATTERN_SIZE];
} Dem_OptimizedNvMDataType;

extern VAR(Dem_OptimizedNvMDataType, AP_DEMIF_VAR) Dem_NvData_BufferOpt;
extern FUNC(void, RTE_AP_DEMIF_APPL_CODE) DemIf_Init(void);

#endif
