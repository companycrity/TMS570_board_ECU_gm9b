/* -----------------------------------------------------------------------------
  Filename:    xcp_par.h
  Description: Toolversion: 08.31.00.01.01.01.23.01.00.00
                
                Serial Number: CBD1010123
                Customer Info: Nexteer
                               Package: GMLAN 3.0 Multi Channel 
                               Micro: TI TMS570 LS2125
                               Compiler: Texas Instruments 4.9.0
                
                
                Generator Fwk   : GENy 
                Generator Module: Xcp
                
                Configuration   : C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\Tools\AsrProject\GENy\RT_2.0_Mod.gny
                
                ECU: 
                        TargetSystem: Hw_Tms470/570Cpu (Dcan)
                        Compiler:     TexasInstruments
                        Derivates:    TMS570PSFC66
                
                Channel "Channel0":
                        Databasefile: C:\Synergy\GM_K2XX_EPS_TMS570-zz4r1x\GM_K2XX_EPS_TMS570\Tools\AsrProject\GENy\GlobalA_HS.dbc
                        Bussystem:    CAN
                        Manufacturer: General Motors
                        Node:         EPS_HS
                Channel "Channel1":
                        Databasefile: GlobalA_CE.dbc
                        Bussystem:    CAN
                        Manufacturer: General Motors
                        Node:         EPS_CE

  Generated by , 2013-07-16  15:26:13
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2008 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(__XCP_PAR_H__)
#define __XCP_PAR_H__

#include "v_inc.h"
/*  */
typedef unsigned char XcpCharType;
V_MEMROM0 extern  V_MEMROM1 XcpCharType V_MEMROM2 kXcpStationId[];
/*  */
/* Events */
V_MEMROM0 extern  V_MEMROM1 XcpCharType V_MEMROM2 V_MEMROM3* V_MEMROM1 V_MEMROM2 kXcpEventName[];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kXcpEventNameLength[];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kXcpEventCycle[];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kXcpEventUnit[];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kXcpEventDirection[];
#define XcpEventChannel_2ms_DAQ_2            0u
/*  */
/* Online calibration */
/*  */
/* Flash programming */
/*  */
/* DAQ */
/*  */
/* Checksum */
/*  */
/* Transport Layer */
#define XcpGetTransmitHandle()               CanTxXcp_Slave_Msg
#define XcpGetTransmitDataPtr()              (Xcp_Slave_Msg._c)
#define ApplXcpInterruptDisable()            CanInterruptDisable()
#define ApplXcpInterruptEnable()             CanInterruptRestore()
#define ApplXcpSendFlush()
#define XcpTransmit()                        CanTransmit(XcpGetTransmitHandle())

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 133574485
      #error "The magic number of the generated file <C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\xcp_par.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 133574485
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __XCP_PAR_H__ */