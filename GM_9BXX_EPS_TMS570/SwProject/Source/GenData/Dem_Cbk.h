/* -----------------------------------------------------------------------------
  Filename:    Dem_Cbk.h
  Description: Toolversion: 12.00.01.01.11.00.60.01.00.00
               
               Serial Number: CBD1110060
               Customer Info: Nexteer GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments tbd
               
               
               Generator Fwk   : GENy 
               Generator Module: Dem
               
               Configuration   : C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\Config\DEM\gmHS_AFS_HS.ecuc.vdsxml
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "CAN00":
                       Databasefile: 
                       Bussystem:    CAN
                       Manufacturer: Vector
                       Node:         CanStateManagerConfiguration

  Generated by , 2013-07-16  15:38:55
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2011 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(DEM_CBK_H)
#define DEM_CBK_H

/* -----------------------------------------------------------------------------
    &&&~ 
 ----------------------------------------------------------------------------- */

#define DEM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* Init monitor function prototypes */
/* Trigger on event status change function prototypes */
/* Trigger on DTC status change function prototypes */
/* Get data value by data identifier function prototypes */
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_4016(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_401B(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_4074(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_40AC(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_40AD(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_40BC(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_40BD(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_41D3(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_41D4(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_41D5(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_41D6(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_41D7(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_41D9(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_43D0(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_446F(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_8002(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_8078(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_C000(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* PRQA S 3651 */ /* AUTOSAR defined API */
extern FUNC(Std_ReturnType, DEM_APPL_CODE) Appl_Dem_CBValByDID_C050(P2VAR(Dem_MaxDataValueType, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer);
/* Get extended data record function prototypes */

#define DEM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"




/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 133575247
      #error "The magic number of the generated file <C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\Dem_Cbk.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 133575247
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* DEM_CBK_H */