/* -----------------------------------------------------------------------------
  Filename:    nm_cfg.h
  Description: Toolversion: 08.31.00.01.01.01.23.01.00.00
                
                Serial Number: CBD1010123
                Customer Info: Nexteer
                               Package: GMLAN 3.0 Multi Channel 
                               Micro: TI TMS570 LS2125
                               Compiler: Texas Instruments 4.9.0
                
                
                Generator Fwk   : GENy 
                Generator Module: Nm_Gmlan_Gm
                
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

  Generated by , 2013-07-16  15:26:14
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

#if !defined(__NM_CFG_H__)
#define __NM_CFG_H__

#include "can_par.h"
#define NM_GMLAN_GMDLL_VERSION               0x0100u
#define NM_GMLAN_GMDLL_RELEASE_VERSION       0x03u
#define NM_TYPE_GMLAN
#define GMLAN_VERSION 0x300
#define kNmNumberOfChannels                  2
#define kNmNumberOfIdentities                1
/* Module specific attributes */
/* Feature configuration */
#define NM_DISABLE_CANOFF_ON_LOWVOLTAGE_MODE
#define NM_DISABLE_LOWVOLTAGE_MODE
#define NM_DISABLE_INHIBIT_VN_HIGHLOAD
#define NM_DISABLE_HIGHSPEED_MODE
#define NM_ENABLE_CALL_CANINITPON
#define NM_ENABLE_BUSOFF_FCT
#define NM_ENABLE_BUSOFF_END_FCT
#define NM_DISABLE_WAKEUP_FCT
#define NM_DISABLE_SLEEP_FCT
#define NM_DISABLE_WAKEUP_RECEIVED_FCT
#define NM_DISABLE_VN_REMOTE_ACTIVATE_REQUEST_FCT
#define NM_DISABLE_VN_ACTIVATION_FAILED_FCT
#define NM_DISABLE_VNMF_CONFIRMATION_TIMEOUT_FCT
#define NM_DISABLE_HLVW_INDICATION_FCT
#define NM_DISABLE_REINITREQUEST_FCT
#define NM_DISABLE_SLEEPCONFIRMATION_FCT
#define NM_DISABLE_EXTENDED_RETURNCODES
#define NM_DISABLE_ASSERTIONS
/* VN configuration */
#define NM_DISABLE_VN_ACTIVATOR
#define NM_DISABLE_VN_REMOTED
#define NM_ENABLE_VN_LOCAL
#define NM_ENABLE_VN_INITACTIVE
#define NM_DISABLE_LV_SUSCEPT_VN
#define kNmNumberOfVirtualNets               6
#define kNmNumberOfVnBytes                   2
#define kNmNumberOfLVSusceptibleVNs          0
/* VN handles */
#define VN_SLHSSharedDiagnostic              0
#define VN_AllNodes                          1
#define VN_SLHS_VNReq                        2
/* Transceiver */
#define NM_DISABLE_SINGLEWIRE_TRCV
#define NM_ENABLE_HIGHSPEED_NOSLEEP_TRCV
#define NM_DISABLE_HIGHSPEED_SLEEP_TRCV
/* BusTypes */
#define NM_DISABLE_BODYBUS
#define NM_ENABLE_POWERTRAIN
#define NM_DISABLE_INFOTAINMENT
#define NM_DISABLE_DIAGNOSTICS
/* Channel specific attributes are generated into the file 'nm_par.c' */

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 133574485
      #error "The magic number of the generated file <C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\nm_cfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 133574485
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __NM_CFG_H__ */
