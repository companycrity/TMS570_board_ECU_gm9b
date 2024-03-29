/* -----------------------------------------------------------------------------
  Filename:    xcp_cfg.h
  Description: Toolversion: 08.31.00.01.01.01.23.01.00.00
                
                Serial Number: CBD1010123
                Customer Info: Nexteer
                               Package: GMLAN 3.0 Multi Channel 
                               Micro: TI TMS570 LS2125
                               Compiler: Texas Instruments 4.9.0
                
                
                Generator Fwk   : GENy 
                Generator Module: Xcp
                
                Configuration   : C:\Synergy\GM_C1XX_EPS_TMS570-zz4r1x\GM_C1XX_EPS_TMS570\Tools\AsrProject\GENy\RT_2.0_Mod.gny
                
                ECU: 
                        TargetSystem: Hw_Tms470/570Cpu (Dcan)
                        Compiler:     TexasInstruments
                        Derivates:    TMS570PSFC66
                
                Channel "Channel0":
                        Databasefile: C:\Synergy\GM_C1XX_EPS_TMS570-zz4r1x\GM_C1XX_EPS_TMS570\Tools\AsrProject\GENy\GlobalA_HS.dbc
                        Bussystem:    CAN
                        Manufacturer: General Motors
                        Node:         EPS_HS
                Channel "Channel1":
                        Databasefile: C:\Synergy\GM_C1XX_EPS_TMS570-zz4r1x\GM_C1XX_EPS_TMS570\Tools\AsrProject\GENy\GlobalA_CE.dbc
                        Bussystem:    CAN
                        Manufacturer: General Motors
                        Node:         EPS_CE

  Generated by , 2013-11-04  10:19:01
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

#if !defined(__XCP_CFG_H__)
#define __XCP_CFG_H__

/*  */
#include "v_inc.h"
/*  */
/* General settings */
#define XCP_ENABLE_PARAMETER_CHECK
#define XCP_ENABLE_CALIBRATION
#define XCP_DISABLE_SEND_EVENT
#define XCP_DISABLE_TESTMODE
#define XCP_DISABLE_BOOTLOADER_DOWNLOAD
#define XCP_ENABLE_WRITE_PROTECTION
#define XCP_ENABLE_READ_PROTECTION
#define XCP_DISABLE_CONTROL
#define XCP_DISABLE_GET_XCP_DATA_POINTER
#define XCP_DISABLE_OPENCMDIF
/*  */
/* EEPROM access */
#define XCP_DISABLE_READ_EEPROM
#define XCP_DISABLE_WRITE_EEPROM
/*  */
/* Service request message */
#define XCP_DISABLE_SERV_TEXT
#define XCP_DISABLE_SERV_TEXT_PUTCHAR
#define XCP_DISABLE_SERV_TEXT_PRINTF
/*  */
/* Standard commands */
#define kXcpStationIdLength                  1
#define XCP_ENABLE_COMM_MODE_INFO
#define XCP_DISABLE_SEED_KEY
#define XCP_DISABLE_MODIFY_BITS
#define XCP_ENABLE_SHORT_DOWNLOAD
#define XCP_ENABLE_USER_COMMAND
#define XCP_DISABLE_VECTOR_MAPNAMES
#define XCP_DISABLE_TL_COMMAND
/*  */
/* Block transfer */
#define XCP_ENABLE_BLOCK_UPLOAD
#define XCP_ENABLE_BLOCK_DOWNLOAD
#define kXcpBlockDownloadMinSt               0
/*  */
/* Checksum */
#define XCP_DISABLE_CHECKSUM
/*  */
/* Synchronous Data Acquisition (DAQ) */
#define XCP_ENABLE_DAQ
#define kXcpDaqMemSize                       512
#define XCP_DISABLE_STIM
#define XCP_DISABLE_UNALIGNED_MEM_ACCESS
#define XCP_ENABLE_SEND_QUEUE
#define XCP_ENABLE_DAQ_PRESCALER
#define XCP_ENABLE_DAQ_OVERRUN_INDICATION
#define XCP_ENABLE_WRITE_DAQ_MULTIPLE
#define XCP_DISABLE_DAQ_HDR_ODT_DAQ
#define XCP_DISABLE_DAQ_RESUME
#define XCP_ENABLE_DAQ_PROCESSOR_INFO
#define XCP_ENABLE_DAQ_RESOLUTION_INFO
/*  */
/* Events */
#define XCP_ENABLE_DAQ_EVENT_INFO
#define kXcpMaxEvent                         1
/*  */
/* DAQ Timestamp */
#define XCP_ENABLE_DAQ_TIMESTAMP
#define XCP_DISABLE_DAQ_TIMESTAMP_FIXED
#define kXcpDaqTimestampSize                 DAQ_TIMESTAMP_WORD
#define kXcpDaqTimestampUnit                 DAQ_TIMESTAMP_UNIT_1US
#define kXcpDaqTimestampTicksPerUnit         1
/*  */
/* Page switching */
#define XCP_ENABLE_CALIBRATION_PAGE
#define kXcpMaxSegment                       1
#define XCP_ENABLE_PAGE_INFO
#define kXcpMaxPages                         2
#define XCP_ENABLE_PAGE_COPY
#define XCP_DISABLE_PAGE_FREEZE
/*  */
/* Programming */
#define XCP_ENABLE_PROGRAM
#define kXcpProgramMinStPgm                  0
#define XCP_DISABLE_PROGRAMMING_WRITE_PROTECTION
#define XCP_ENABLE_CALIBRATION_MEM_ACCESS_BY_APPL
#undef kXcpMaxSegment
/* Define new segment and pages -- work around for Vector limitation */
#define kXcpMaxSegment	2u
/*  */
#define CP_XCPDLL_VERSION                    0x0213u
#define CP_XCPDLL_RELEASE_VERSION            0x03u
/* Transport Layer */
/*  */
#define kXcpNumberOfCanChannels              2
#define XCP_DISABLE_MULTI_CHANNEL
#define XCP_DISABLE_MULTI_CONNECTION_PROTECTION
#define XCP_TRANSPORT_LAYER_TYPE_CAN
#define XCP_TRANSPORT_LAYER_VERSION          0x0100u
#define kXcpMaxCTO                           8
#define kXcpMaxDTO                           8
#define XCP_DISABLE_VARIABLE_DLC
#define kXcpSendQueueMinSize                 1
/*  */
#define CP_XCPONCANDLL_VERSION               0x0106u
#define CP_XCPONCANDLL_RELEASE_VERSION       0x03u

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 133574485
      #error "The magic number of the generated file <C:\CMSynergy_Projects\Chrysler_C1xx\Chrysler_LWR_EPS_TMS570\SwProject\Source\_GenData\xcp_cfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 133574485
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __XCP_CFG_H__ */
