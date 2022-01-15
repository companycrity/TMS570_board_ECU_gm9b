/* ORGANI: STARTSINGLE_OF_MULTIPLE */


/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2007-2010 by Vector Informatik GmbH.                                             All rights reserved.
 
                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  gmnmdef.h
      Project:  Nm_Gmlan_Gm
       Module:  -
    Generator:  -
  Description:  Vector GMLAN Network Management header file
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Initials     Name                      Company
-----------------------------------------------------------------------------------------------------------------------
  Al           Casey Alford              Vector CANtech, inc.
  Ba           Bernd Baudermann          Vector Informatik GmbH
  dH           Gunnar de Haan            Vector Informatik GmbH
  Ds           Hussain Darwish           Vector CANtech, Inc.
  Eb           Volker Ebner              Vector Informatik GmbH
  Fr           Guenther Foerstner        Vector Informatik GmbH
  Fz           Ralf Fritz                Vector Informatik GmbH
  Hp           Armin Happel              Vector Informatik GmbH
  Ht           Heike Honert              Vector Informatik GmbH
  Jrw          Jason Wolbers             Vector CANtech, Inc.
  Law          Laura Anne Winder         Vector CANtech, Inc.
  Mfr          Michael Radwick           Vector CANtech, Inc.
  Mra          Marc Rauscher             Vector Informatik GmbH
  Si           Bernd Sigle               Vector Informatik GmbH
  Th           Jochen Theuer             Vector Informatik GmbH
  Tri          Frank Triem               Vector Informatik GmbH
  vismas       Markus Schwarz            Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  2.0       12.02.1999  Hp      Creation;
                                Starting with V2.0 to distinguish between HGMLAN V1.x
                                and GMLAN > V2.x
  2.01      08.03.1999  Ba      Supporting of Hiware ST7
                        Hp      Supporting C16x/HC12
  2.10      31.03.1999  Hp      Extending interface for VDA support.
  2.12      14.04.1999  Hp      No changes (see GMNM.C)
  2.13      30.04.1999  Ba      No changes (see GMNM.C)
  2.14      01.06.1999  Hp      No changes (see GMNM.C)
  2.15      05.06.1999  Hp      No changes (see GMNM.C)
  2.20      20.07.1999  Hp      Remove VDA-support
                                Changing prototype of IlNwmActivateVN, IlNwmDeactivateVN,
                                IlNwmNormalCommHalted, IlNwmSetHispeedMode
                                Adding constants for new return value
                                New prototype for configurable callback function
                                ApplNwmVnRemoteActivateRequest(vnHndl).
                                Remove Reinitialization request of VN's. Adding
                                callback instead.
  2.21      22.07.1999  Hp      No changes (see GMNM.C)
  2.22      26.07.1999  Hp      Exporting parts of the bit-coded nmVnState[] to make
                                them available via IlNwmIsActiveVN(vnHndl);
  2.23      26.08.1999  Hp      No changes (see GMNM.C)
  2.30      22.11.1999  Hp      Function prototype for ApplNwmVnActivationFailed(vnHndl);
  2.31      30.11.1999  Hp      No changes (see GMNM.C)
  2.32      31.01.2000  Hp      No changes (see GMNM.C)
  2.33      06.02.2000  Hp      Adapting config switch naming convention for automatic configuration of GMLAN.
  2.34      11.05.2000  Hp      Portation to NEC V850 with NEC-Compiler
  2.40      14.07.2000  Hp      No changes (see GMNM.C)
  2.41      18.09.2000  Hp      No changes (see GMNM.C)
  2.42      21.02.2001  Fz      No changes (see GMNM.C)
  2.49      11.12.2000  Hp      Pre-Release for GM-internal verification:
                                Adding interface functions for LowVoltage mode.
  2.50      20.07.2001  Hp      ESCAN00000262
                                ESCAN00000286
                                ESCAN00000311
                                ESCAN00000434
                                              Release GMLAN V2.50
  2.51      10.08.2001  dH      No changes (see GMNM.C)
  2.52      14.08.2001  Ht      ESCAN00001220 No changes (see GMNM.C)
  2.53      17.10.2001  Al      No changes (see GMNM.C)
  2.54      19.10.2001  Al      Added the transceiver state defines also see GMNM.C
  2.99      09.11.2001  Al      Added interface functions:
                                IlNwmInhibitActivationVN & lNwmAllowActivationVN
                                Added mandatory callback function: ApplNwmSleepConfirmation
  2.99a     23.11.2001  Hp      ESCAN00001817: Delayed VNMF after Wakeup solved.
                                Avoiding VN-timer if ONLY Shared-Local-Input-VNs are used.
                                Timeout-observation and retry of Wakeup-frames with BusOff.
                                Smaller refinements in the FctCall/SetFlag order.
                                Removing old-style name 
  3.00      01.02.2002  Al      ESCAN00001817 No changes (see GNMN.C)
  3.01      22.03.2002  Hp      ESCAN00001156
                                ESCAN00002538
                                Calibratable values changed to constants for GMLAN V2.6.
                                Other changes: see GMNM.C
  3.01.01   2002-07-02  Hp      ESCAN00003144: Incorrect bit definition in nmState structure
                                with the option C_CPUTYPE_BITORDER_MSB2LSB
  3.02      2002-07-16  Hp      ESCAN00002871 Timer parameters for indexed-NM now channel specific.
                                              Move timer default values to GMNMDEF.H. 
                                              CANgen V3.88 and higher now recommended, especially for indexed systems.
  3.03      2002-09-09  Hp      ESCAN00003429 Processing VNMF for more than two bytes if DLC is shorter than expected.
                        Hp      ESCAN00003435 Solves delayed Continue-VNMF for Activator+Initially Active VN
                        Hp      ESCAN00003715 Add #pragma for external const definition for M16C
                                ESCAN00004083
  3.04      2002-11-14  Fz      ESCAN00004148 No changes
  3.05      2003-01-27  Fz      ESCAN00004402 No changes
                                ESCAN00004733 No changes
                                ESCAN00004734 No changes
                                ESCAN00004735 No changes
                                ESCAN00004736 No changes
                                ESCAN00004737 No changes
                                ESCAN00004349 No changes
                                ESCAN00004728 No changes
  3.06      2003-02-03  Mra     ESCAN00004534 No changes
                                ESCAN00004846 No changes
                                ESCAN00004847 No changes
  3.07      2003-02-24  Mra     ESCAN00005012 No changes
                                ESCAN00005086 No changes
  3.08      2003-04-03  Fz      ESCAN00005293 No changes
  3.09      2003-04-28  Fz      ESCAN00005465 No changes
                                ESCAN00005442 No changes
                                ESCAN00005466 No changes
                                ESCAN00005467 No changes
                                ESCAN00005542 No changes
                                              Code replication issue with IlNwmInhibit/Allow function solved.
  3.10      2003-05-15  Tri     ESCAN00005677 Implementing memory qualifier V_MEMROM0
  3.11      2003-05-16  Mra     ESCAN00005696 Missing  in GMLAN_VERSION if-clause fixed
  3.12      2003-07-04  Hp      ESCAN00005697 Interface function provided to get current VN-Timer value
                                ESCAN00005658
                                ESCAN00006004
  3.13      2003-08-13  Tri     ESCAN00006352 No changes
  3.14      2003-09-15  Hp      ESCAN00006569 No changes
  3.15      2003-11-11  Hp      ESCAN00006904 Improve data integrity for internal counter
  3.16      2004-01-16  Fz      ESCAN00006991 No changes
                                ESCAN00007136
                                ESCAN00007315
  3.17      2004-06-23  LAW     ESCAN00007148 Updated memory qualifiers 
                                ESCAN00008733
                                ESCAN00007353
  3.18      2004-10-15  Fz      ESCAN00009901 Add new naming convention for version defines
                                ESCAN00006550
                                ESCAN00006548
                                ESCAN00009900
  3.19      2005-01-24  Fz      ESCAN00010876 No changes
                                ESCAN00009901
  3.20      2005-02-22  Fz      ESCAN00011254 No changes
  3.21      2005-02-24  Fz      ESCAN00010876 No changes
  3.22      2005-03-22  Fz      ESCAN00011431 No changes
  3.23      2006-01-13  Fz      ESCAN00012960 Macros added to access the return value of IlNwmIsActiveVN.
                                ESCAN00013160 Support to read and write the current context of the NM
                        Fz      ESCAN00014323 Version define changed according to Vector rule 
                        Jrw     ESCAN00012834 No changes (see GMNM.C)
                        Jrw     ESCAN00013929 No changes (see GMNM.C)
                        Jrw     ESCAN00014709 No changes (see GMNM.C)
                        Jrw     ESCAN00014844 Application messages or VNMFs could be sent without a preceeding HLVW
                        Jrw     ESCAN00014887 COMM_ENABLE timer could expire too early for 8-bit micros
                        Fz      ESCAN00014394 No changes (see GMNM.C)
                                ESCAN00011926
                                ESCAN00012207
  3.24      2006-01-18  Fz      ESCAN00014962 No changes (see GMNM.C)
  3.25      2006-03-14  Fz      ESCAN00015592 No changes (see GMNM.C)
  3.26      2006-05-10  Fz      ESCAN00016213 No changes (see GMNM.C)
  3.27      2006-06-26  Fz      ESCAN00016353 No changes (see GMNM.C)
  3.28      2006-09-28  Fz      ESCAN00006412 No changes (see GMNM.C)
                                ESCAN00017297 No changes (see GMNM.C) 
                                ESCAN00017292 Multichannel configurations: compile error if assertions are enabled and
                                              internal NM provided assertion function is used. 
  3.29      2007-01-25  Fz      ESCAN00018323 No changes (see GMNM.C)
                        Fz      ESCAN00019499 Sleep wake able high speed transceiver put into sleep mode to early 
                        Fz      ESCAN00019706 Support memory mapping in gmlcal.c / gmlcal.h
                        Fz      ESCAN00020070 No changes (see GMNM.C) 
                        Fz      ESCAN00020187 Unused variables warnings removed
                        Fz      ESCAN00019875 No changes (see GMNM.C)
  3.30      2007-04-18  Fz      ESCAN00020333 Compiler error in multi channel configurations
  3.30.01   2007-06-04  vismas  ESCAN00020903 no changes in this file
                                ESCAN00021023 no changes in this file
  4.00.00   2007-07-26  vismas  ESCAN00021281 no changes in this file
                                ESCAN00022355 no changes in this file
                                ESCAN00023021 no changes in this file
                                ESCAN00023087 no changes in this file
                                ESCAN00023446 no changes in this file
                                ------------- adapted for GENy, rework of document structure, rework of comments
                                ------------- adapted to current coding template
                                ESCAN00023509 no changes in this file
                                ESCAN00024008 no changes in this file
  4.00.01   2008-02-13  vismas  ESCAN00024303 no changes in this file
                                ESCAN00024378 no changes in this file
                                ------------- corrected typing mistakes
                                ESCAN00025934 adapted for usage with TMS320
  4.00.02   2008-08-12  Jrw     ESCAN00029103 no changes in this file
  4.00.03   2008-10-17  vismas  ESCAN00029370 no changes in this file
                                ESCAN00030073 no changes in this file
                                ESCAN00030131 no changes in this file
                                ESCAN00030738 no changes in this file
  4.00.04   2009-07-08  vismas  ESCAN00036068 no changes in this file
  4.00.05   2009-07-09  vismas  ESCAN00036294 no changes in this file
  4.00.06   2009-10-26  vismas  ESCAN00038021 no changes in this file
  4.00.07   2009-12-22  vismas  ESCAN00039287 changed position of type nmMessType
            2010-03-04  vismas  ESCAN00038215 no changes in this file
            2010-03-04  vismas  ESCAN00041336 adapted function-like macros to be MSIRA compliant
  4.01.00   2010-07-15  vismas  ESCAN00043175 no changes in this file
            2010-07-15  vismas  ESCAN00043663 no changes in this file
**********************************************************************************************************************/

#if defined ( V_NM_GMLAN_GM_HEADER )
#else
#define V_NM_GMLAN_GM_HEADER

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
/* 
These includes are already part of gmlcal.h:
#include "v_cfg.h"
#include "v_def.h"
#include "nm_cfg.h"
*/

#include "gmlcal.h"

/**********************************************************************************************************************
  Version data
**********************************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : Nm_Gmlan_GM CQComponent : Implementation */
#define NM_GMLAN_GM_VERSION                     0x0401
#define NM_GMLAN_GM_RELEASE_VERSION             0x00

/**********************************************************************************************************************
  Global configuration
**********************************************************************************************************************/
/*--- system ---*/
#if ( kNmNumberOfChannels > 1 )
  #define NM_ENABLE_INDEXED_NM
#endif

#if ( kNmNumberOfIdentities > 1 )
  #define NM_ENABLE_MULTIPLE_NODES
#endif

/*--- timing ---*/
#if defined ( kNmDeactSleepTime )
#else
  #define kNmDeactSleepTime                     4000
#endif
#if defined ( kNmHighSpeedTime )
#else
  #define kNmHighSpeedTime                      500
#endif
#if defined ( kNmLastWakeupTime )
#else
  #define kNmLastWakeupTime                     4500
#endif
#if defined ( kNmSleepDeniedTime )
#else
  #define kNmSleepDeniedTime                    8000
#endif
#if defined ( kNmVnRestartIVNMFTime )
#else
  #define kNmVnRestartIVNMFTime                 4000
#endif
#if defined ( kNmVnRxTimerTime )
#else
  #define kNmVnRxTimerTime                      1000
#endif
#if defined ( kNmVnTimerTime )
#else
  #define kNmVnTimerTime                        8000
#endif
#if defined ( kNmWakeupFailTime )
#else
  #define kNmWakeupFailTime                     100
#endif
#if defined ( kNmWakeupSleepTime )
#else
  #define kNmWakeupSleepTime                    8000
#endif

/*--- others ---*/
#if defined ( kNmNumberOfFailedWakeup )
#else
  #define kNmNumberOfFailedWakeup               3
#endif

#if defined ( kNmCanInitObjStd )
#else
  #define kNmCanInitObjStd                      0
#endif

#if defined ( kNmCanInitObjHighSpeed )
#else
  #define kNmCanInitObjHighSpeed                1
#endif

/*--- VNs ---*/
#if defined ( kNmNumberOfVirtualNets )
  #if ( kNmNumberOfVirtualNets == 0 )
    #undef kNmNumberOfVirtualNets
  #endif
#endif
#if defined ( kNmNumberOfVirtualNets )
#else
  #define kNmNumberOfVirtualNets                1
#endif

#if defined ( kNmNumberOfVnBytes )
#else
  #define kNmNumberOfVnBytes                    ((kNmNumberOfVirtualNets+7)/8)
#endif

/*--- features ---*/
#if defined ( NM_ENABLE_BODYBUS ) || \
    defined ( NM_ENABLE_INFOTAINMENT )
/* HLVW is used on Bodybus and Infotainment */
  #define NM_ENABLE_HLVW_HANDLING
  #define NM_ENABLE_VNMF_HANDLING
#endif

#if defined ( NM_ENABLE_INDEXED_NM )
  #define NM_ENABLE_CALL_CANINIT
  #define NM_ENABLE_CANINIT_PARAM_CHECK
#else
  #if defined ( kNmCanInitObjStd )
    #if ( kNmCanInitObjStd != 0 )
      #define NM_ENABLE_CALL_CANINIT
    #endif
  #else
    #define NM_ENABLE_CALL_CANINIT
    #define NM_ENABLE_CANINIT_PARAM_CHECK
  #endif
#endif

/* compatibility define for usage of Diag */
#if defined ( NM_ENABLE_HIGHSPEED_MODE )
  #define NM_ENABLE_HISPEED_MODE
#else
  #define NM_DISABLE_HISPEED_MODE
#endif

/**********************************************************************************************************************
  Global typedefs
**********************************************************************************************************************/
/*
 * Name:    nmStatusType
 * Used by: IlNwmGetStatus() (return value) 
 */
typedef vuint8   nmStatusType;

/*
 * Name:    nmStatusType
 * Used by: IlNwmSetHispeedMode() (return value)
 *          IlNwmNormalCommHalted() (return value)
 *          IlNwmActivateVN() (return value)
 *          IlNwmDeactivateVN() (return value)
 */
typedef vsint8     Nm_Status;

/*
 * Name:    nmStateType
 * Used by: --- (needed for status export of all variables)
 * Notes:   state is stored in byte0. These flags can be accessed by IlNwmGetStatus()
 *          internal flags are stored in bytes 1-3
 *          Bytes 2+3 contain all flags modified in interrupt context.
 *          Clearing the flags on task level must be done with locked interrupt.
 */
typedef union
{
  vuint8      c[4];
  #if defined( C_CPUTYPE_BITORDER_MSB2LSB )
  struct
  {
    vbittype  b_NormalCommHalted        :1;   /* byte 0 bit 7 */
    vbittype  b_HighSpeedMode           :1;   /* byte 0 bit 6 */
    vbittype  b_NoCommunication         :1;   /* byte 0 bit 5 */
    vbittype  b_SleepModeEntered        :1;   /* byte 0 bit 4 */
    vbittype  b_SleepModePending        :1;   /* byte 0 bit 3 */
    vbittype  b_BusOffOccured           :1;   /* byte 0 bit 2 */
    vbittype  b_NMActive                :1;   /* byte 0 bit 1 */
    vbittype  b_LVModeActive            :1;   /* byte 0 bit 0 */

    vbittype  b_InternalNMActive        :1;   /* byte 1 bit 7 */
    vbittype  b_InternalVnActive        :1;   /* byte 1 bit 6 */
    vbittype  b_InternalSleepModeEntered:1;   /* byte 1 bit 5 */
    vbittype  b_InternalHighSpeedMode   :1;   /* byte 1 bit 4 */
    vbittype  b_TxObserveError          :1;   /* byte 1 bit 3 */
    vbittype  b_VnActive                :1;   /* byte 1 bit 2 */
    vbittype  b_nmVnInhibit             :1;   /* byte 1 bit 1 */
    vbittype  b_SendMessFlag            :1;   /* byte 1 bit 0 */

    vbittype  b_HVMsgActive             :1;   /* byte 2 bit 7 */
    vbittype  b_HVMsgSent               :1;   /* byte 2 bit 6 */
    vbittype  b_HVMsgSendRequest        :1;   /* byte 2 bit 5 */
    vbittype  b_HVMsgReceived           :1;   /* byte 2 bit 4 */
    vbittype  b_SendVnInitRequest       :1;   /* byte 2 bit 3 */
    vbittype  b_RescanVnState           :1;   /* byte 2 bit 2 */
    vbittype  b_ActivateInitTxVN        :1;   /* byte 2 bit 1 */
    vbittype  b_ActivateInitRxVN        :1;   /* byte 2 bit 0 */

    vbittype  b_UnusedAndReserved1      :1;   /* byte 3 bit 7 */
    vbittype  b_UnusedAndReserved2      :1;   /* byte 3 bit 6 */
    vbittype  b_UnusedAndReserved3      :1;   /* byte 3 bit 5 */
    vbittype  b_UnusedAndReserved4      :1;   /* byte 3 bit 4 */
    vbittype  b_UnusedAndReserved5      :1;   /* byte 3 bit 3 */
    vbittype  b_HVMsgSendFailed         :1;   /* byte 3 bit 2 */
    vbittype  b_HVMsgTxConfirmed        :1;   /* byte 3 bit 1 */
    vbittype  b_VNMF_TxConfirmed        :1;   /* byte 3 bit 0 */
  } b;
  #else
    #if defined( C_CPUTYPE_BITORDER_LSB2MSB )
  struct
  {
    vbittype  b_LVModeActive            :1;   /* byte 0 bit 0 */
    vbittype  b_NMActive                :1;   /* byte 0 bit 1 */
    vbittype  b_BusOffOccured           :1;   /* byte 0 bit 2 */
    vbittype  b_SleepModePending        :1;   /* byte 0 bit 3 */
    vbittype  b_SleepModeEntered        :1;   /* byte 0 bit 4 */
    vbittype  b_NoCommunication         :1;   /* byte 0 bit 5 */
    vbittype  b_HighSpeedMode           :1;   /* byte 0 bit 6 */
    vbittype  b_NormalCommHalted        :1;   /* byte 0 bit 7 */

    vbittype  b_SendMessFlag            :1;   /* byte 1 bit 0 */
    vbittype  b_nmVnInhibit             :1;   /* byte 1 bit 1 */
    vbittype  b_VnActive                :1;   /* byte 1 bit 2 */
    vbittype  b_TxObserveError          :1;   /* byte 1 bit 3 */
    vbittype  b_InternalHighSpeedMode   :1;   /* byte 1 bit 4 */
    vbittype  b_InternalSleepModeEntered:1;   /* byte 1 bit 5 */
    vbittype  b_InternalVnActive        :1;   /* byte 1 bit 6 */
    vbittype  b_InternalNMActive        :1;   /* byte 1 bit 7 */

    vbittype  b_ActivateInitRxVN        :1;   /* byte 2 bit 0 */
    vbittype  b_ActivateInitTxVN        :1;   /* byte 2 bit 1 */
    vbittype  b_RescanVnState           :1;   /* byte 2 bit 2 */
    vbittype  b_SendVnInitRequest       :1;   /* byte 2 bit 3 */
    vbittype  b_HVMsgReceived           :1;   /* byte 2 bit 4 */
    vbittype  b_HVMsgSendRequest        :1;   /* byte 2 bit 5 */
    vbittype  b_HVMsgSent               :1;   /* byte 2 bit 6 */
    vbittype  b_HVMsgActive             :1;   /* byte 2 bit 7 */

    vbittype  b_VNMF_TxConfirmed        :1;   /* byte 3 bit 0 */
    vbittype  b_HVMsgTxConfirmed        :1;   /* byte 3 bit 1 */
    vbittype  b_HVMsgSendFailed         :1;   /* byte 3 bit 2 */
    vbittype  b_UnusedAndReserved5      :1;   /* byte 3 bit 3 */
    vbittype  b_UnusedAndReserved4      :1;   /* byte 3 bit 4 */
    vbittype  b_UnusedAndReserved3      :1;   /* byte 3 bit 5 */
    vbittype  b_UnusedAndReserved2      :1;   /* byte 3 bit 6 */
    vbittype  b_UnusedAndReserved1      :1;   /* byte 3 bit 7 */
  } b;
    #else
      #error "Missing Bitorder type definition of compiler !!"
    #endif
  #endif
} nmStateType;

/*
 * Name:    nmActionType
 * Used by: --- (needed for status export of all variables)
 */
typedef enum
{
   NO_ACTION = 0,
   NM_COMM_OFF,
   NM_COMM_ENABLE,
   NM_COMM_HALTED,
   NM_COMM_ACTIVE,
   NM_HIGHSPEED_MODE,
   NM_LEAVE_HIGHSPEED_MODE,
   NM_BUSOFF,
   NM_ENTER_LOW_VOLTAGE_TOLERANT_MODE,
   NM_EXIT_LOW_VOLTAGE_TOLERANT_MODE
} nmActionType;

/*
 * Name:    tErrState
 * Used by: NmAssert()
 */
typedef enum eErrState 
{
   NMERR_ILLSTATE,
   NMERR_ILLHIGHSPEED,
   NMERR_ILLHIGHSPEEDPARAM,
   NMERR_ILLWAKEUP,
   NMERR_ILLVNARGNUMBER,
   NMERR_ILLACTIVATOR,
   NMERR_ILLSTATECHANGEREQ,
   NMERR_VNNROUTOFRANGE,
   NMERR_VNACTIVECNT_INCONSISTENT,
   NMERR_TIMER_ACTIVE_ALREADY_ZERO,
   NMERR_ILL_VN_NUMBER,
   NMERR_ILL_VNMF_INDEX,
   NMERR_VNTIMER_INCONSISTENT,
   NMERR_VNTIMER_UNDERFLOW,
   NMERR_VNSTATE_INCONSISTENT,
   NMERR_ILLNR_OF_ACTUAL_TXHWOBJ,
   NMERR_OFFLINE_INCONSISTENT,
   NMERR_APIERR_CALLENTERLVMODE_IN_SLEEP,
   NMERR_LAST
} tErrState;

/*
 * Name:    tCommEnableTimer
 * Used by: ---
 */
typedef vuint16 tCommEnableTimer;

#if defined( NM_ENABLE_INDEXED_NM )
/*
 * Name:    tNmTrcvrType
 * Used by: 
 */
typedef enum eNmTrcvrType
{
  NM_SINGLEWIRE_TRCV           =0,
  NM_HIGHSPEED_NOSLEEP_TRCV    =1,
  NM_HIGHSPEED_SLEEP_TRCV      =2
} tNmTrcvrType;
#endif

/*
 * Name:    nmMessType
 * Used by: ---
 * Note:    nmMessType is a union to set word alignment for specific 16-bit CPU
 */
typedef union
{
  vuint8    c[kNmNumberOfVnBytes];
  vuint16   i[(kNmNumberOfVnBytes+1)/2];
} nmMessType;


/**********************************************************************************************************************
  Global data defines
**********************************************************************************************************************/
/*
 * Name:        
 * Description: Definition of return values
 * Used by:     
 */
#define NM_INHIBITED                            3
#define NM_INACTIVE                             2
#define NM_ACTIVE                               1
#define NM_OK                                   0
#define NM_ERROR                                -1
#define NM_WRONG_ARG                            -2
#define NM_HALTED                               -3

/*
 * Name:        
 * Description: Definition of transceiver states
 * Used by:     
 */
#define NM_TRCVR_NORMAL                         0x00
#define NM_TRCVR_SLEEP                          0x01
#define NM_TRCVR_HIGHSPEED                      0x02
#define NM_TRCVR_HIGHVOLTAGE                    0x03

/*
 * Name:        
 * Description: VN state types
 *              Bit coded status of VN. Returned by function IlNwmIsActiveVN()
 * Used by:     
 */
#define NmVnNone                                (0x00u)  /* VN is inactive                 */
#define NmVnActive                              (0x02u)  /* VN is completely activated     */
#define NmVnActivator                           (0x04u)  /* VN is activator active         */
#define NmVnLocal                               (0x08u)  /* VN is locally active           */
#define NmVnRxActive                            (0x10u)  /* VN has Rx enabled              */
#define NmVnActivatorPending                    (0x80u)  /* VN is requested by application */

/*
 * Name:        
 * Description: VN types
 * Used by:     
 */
#define kVnNone                                 0x00
#define kVnRemoted                              0x02
#define kVnActivator                            0x04
#define kVnLocal                                0x08
#define kVnInitActive                           0x80

/*
 * Name:        
 * Description: Sleep confirmation return values
 * Used by:     
 */
#define NmSleepOk                               0x01
#define NmSleepNo                               0x00

/*
 * Name:        
 * Description: 2nd parameter of callback ApplNwmReinitRequest
 *              Indicates if VN is requested for initialization from received VNMF or
 *              due to a VN-continuation request of an internally inactive VN
 * Used by:     
 */
#define NM_INTERNAL_REINIT_REQUEST              0
#define NM_EXTERNAL_REINIT_REQUEST              1

/**********************************************************************************************************************
  Global macro defines
**********************************************************************************************************************/
/*--- function-like API macros --------------------------------------------------------------------------------------*/
/*
 * Name:        IlNwmState...()
 * Description: macros for status evaluation (applied on return value of IlNwmGetStatus()
 * Used by      application
 */
/* ESCAN00041336 */
#define IlNwmStateLowVoltageModeActive(state)   ((((state) & 0x01) != 0) ? 1 : 0)
#define IlNwmStateNMActive(state)               ((((state) & 0x02) != 0) ? 1 : 0)
#define IlNwmStateBusOffOccured(state)          ((((state) & 0x04) != 0) ? 1 : 0)
#define IlNwmStateSleepModePending(state)       ((((state) & 0x08) != 0) ? 1 : 0)
#define IlNwmStateSleepModeEntered(state)       ((((state) & 0x10) != 0) ? 1 : 0)
#define IlNwmStateNoCommunication(state)        ((((state) & 0x20) != 0) ? 1 : 0)
#define IlNwmStateHispeedMode(state)            ((((state) & 0x40) != 0) ? 1 : 0)
#define IlNwmStateNormalCommHalted(state)       ((((state) & 0x80) != 0) ? 1 : 0)

/*
 * Name:        IlNwmIsNmVn...()
 * Description: macros for status evaluation (applied on return value of IlNwmIsActiveVN()
 * Used by      application
 */
#define IlNwmIsNmVnNone(vnState)                (((vnState) == NmVnNone) ? 1 : 0)
#define IlNwmIsNmVnActive(vnState)              ((((vnState) & NmVnActive)==NmVnActive) ? 1 : 0)
#define IlNwmIsNmVnActivator(vnState)           ((((vnState) & NmVnActivator)==NmVnActivator) ? 1 : 0)
#define IlNwmIsNmVnLocal(vnState)               ((((vnState) & NmVnLocal)==NmVnLocal) ? 1 : 0)
#define IlNwmIsNmVnRxActive(vnState)            ((((vnState) & NmVnRxActive)==NmVnRxActive) ? 1 : 0)
#define IlNwmIsNmVnActivatorPending(vnState)    ((((vnState) & NmVnActivatorPending)==NmVnActivatorPending) ? 1 : 0)

/*--- instance-access macros ----------------------------------------------------------------------------------------*/
/*
 * Name:        NmIdentity
 * Description: This macros addresses the instance of the NM (channel/identity)
 * Used by      any access to instance-specific data, i.e. data that has to be differed for multiple ECUs.
 */
#if defined( NM_ENABLE_INDEXED_NM )
  #if defined ( NM_ENABLE_MULTIPLE_NODES )
    #define NmIdentity(ch, id)                  ((kNmNumberOfChannels*(id))+(ch))
  #else
    #define NmIdentity(ch, id)                  (ch)
  #endif
#else
  #if defined ( NM_ENABLE_MULTIPLE_NODES )
    #define NmIdentity(ch, id)                  (id)
  #else
    #define NmIdentity(ch, id)                  0
  #endif
#endif

/*--- configuration access macros -----------------------------------------------------------------------------------*/
#if defined ( NM_ENABLE_INDEXED_NM )
  #define NmCfg_CycleTime(ch)                   (NmCallCycle_Field[ch])
  #if defined ( NM_ENABLE_HLVW_HANDLING )
  #define NmCfg_TxHndl_HLVW(ch)                 (NmTxHandle_HLVW_Field[ch])
  #endif
  #if defined ( NM_ENABLE_USERSPECIFIC_CANINITOBJECTS )
  #define NmCfg_InitObj_Std(ch)                 (nmCanInitObjStd[ch])
  #else
  #define NmCfg_InitObj_Std(ch)                 (kNmCanInitObjStd)
  #endif
  #if defined ( NM_ENABLE_HIGHSPEED_MODE )
    #if defined ( NM_ENABLE_USERSPECIFIC_CANINITOBJECTS )
  #define NmCfg_InitObj_HighSpeed(ch)           (nmCanInitObjHighSpeed[ch])
    #else
  #define NmCfg_InitObj_HighSpeed(ch)           (kNmCanInitObjHighSpeed)
    #endif
  #endif
  #define NmCfg_HighSpeed_Cnt(ch)               NmHighSpeedCnt_Field[ch]
  #define NmCfg_WakeupFail_Cnt(ch)              NmWakeupFailCnt_Field[ch]
  #define NmCfg_VnTimer_Cnt(ch)                 NmVnTimerCnt_Field[ch]
  #define NmCfg_VnRxTimer_Cnt(ch)               NmVnRxTimerCnt_Field[ch]
  #define NmCfg_WakeupSleep_Cnt(ch)             NmWakeupSleepCnt_Field[ch]
  #define NmCfg_DeactSleep_Cnt(ch)              NmDeactSleepCnt_Field[ch]
  #define NmCfg_SleepDenied_Cnt(ch)             NmSleepDeniedCnt_Field[ch]
  #define NmCfg_LastWakeup_Cnt(ch)              NmLastWakeupCnt_Field[ch]
  #define NmCfg_VnRestartIVnmf_Cnt(ch)          NmVNRestartIVNMFCnt_Field[ch]
  #define NmCfg_VnmfConfirm_Cnt(ch)             NmVNMFConfirmCnt_Field[ch]

  #define NmCfg_BusOffRecovery_Cnt(ch)          nmBusOffRecoverTimeCalCnt[ch]
  #define NmCfg_InitDelay_Cnt(ch)               nmInitDelayTimeCalCnt[ch]
  #define NmCfg_InitDelayLocal_Cnt(ch)          nmInitDelayTimeCalCnt[ch]
  #define NmCfg_SleepTransition_Cnt(ch)         ((tCommEnableTimer)(nmVNMFStartSendCalCnt[ch]+2)) 
  #define NmCfg_VnmfStartSend_Cnt(ch)           nmVNMFStartSendCalCnt[ch]
  #define NmCfg_VnmfPeriodicRate_Cnt(ch)        nmVNMFSendTimeCalCnt[ch]

  #define NmCfg_VN_StartIndex(ch)               (NmVnStartIndex[ch])
  #define NmCfg_VN_StopIndex(ch)                (NmVnStartIndex[ch+1]-1)
  #define NmCfg_VnByte_StartIndex(ch)           (NmVnByteStartIndex[ch])
  #define NmCfg_VnByte_StopIndex(ch)            (NmVnByteStartIndex[ch+1]-1)
#else
  #define NmCfg_CycleTime(ch)                   (kNmCycleTime)
  #if defined ( NM_ENABLE_HLVW_HANDLING )
    #if defined ( NmUserCfg_TxHndl_HV100 )
  #define NmCfg_TxHndl_HLVW(ch)                 (NmUserCfg_TxHndl_HV100)
    #else
  #define NmCfg_TxHndl_HLVW(ch)                 (kNmTxHndl_HLVW)
    #endif
  #endif
  #if defined ( NM_ENABLE_USERSPECIFIC_CANINITOBJECTS )
  #define NmCfg_InitObj_Std(ch)                 (nmCanInitObjStd)
  #else
  #define NmCfg_InitObj_Std(ch)                 (kNmCanInitObjStd)
  #endif
  #if defined ( NM_ENABLE_HIGHSPEED_MODE )
    #if defined ( NM_ENABLE_USERSPECIFIC_CANINITOBJECTS )
  #define NmCfg_InitObj_HighSpeed(ch)           (nmCanInitObjHighSpeed)
    #else
  #define NmCfg_InitObj_HighSpeed(ch)           (kNmCanInitObjHighSpeed)
    #endif
  #endif
  #define NmCfg_HighSpeed_Cnt(ch)               (((kNmHighSpeedTime            +kNmCycleTime)-1)/kNmCycleTime)
  #define NmCfg_WakeupFail_Cnt(ch)              (((kNmWakeupFailTime           +kNmCycleTime)-1)/kNmCycleTime)
  #define NmCfg_VnTimer_Cnt(ch)                 (((kNmVnTimerTime              +kNmCycleTime)-1)/kNmCycleTime)
  #define NmCfg_VnRxTimer_Cnt(ch)               (((kNmVnRxTimerTime            +kNmCycleTime)-1)/kNmCycleTime)
  #define NmCfg_WakeupSleep_Cnt(ch)             (((kNmWakeupSleepTime          +kNmCycleTime)-1)/kNmCycleTime)
  #define NmCfg_DeactSleep_Cnt(ch)              (((kNmDeactSleepTime           +kNmCycleTime)-1)/kNmCycleTime)
  #define NmCfg_SleepDenied_Cnt(ch)             (((kNmSleepDeniedTime          +kNmCycleTime)-1)/kNmCycleTime)
  #define NmCfg_LastWakeup_Cnt(ch)              (((kNmLastWakeupTime           +kNmCycleTime)-1)/kNmCycleTime)
  #define NmCfg_VnRestartIVnmf_Cnt(ch)          (((kNmVnRestartIVNMFTime       +kNmCycleTime)-1)/kNmCycleTime)
  #define NmCfg_VnmfConfirm_Cnt(ch)             (((kNmVNMFConfirmationTimeout  +kNmCycleTime)-1)/kNmCycleTime)

  #define NmCfg_BusOffRecovery_Cnt(ch)          nmBusOffRecoverTimeCalCnt
  #define NmCfg_InitDelay_Cnt(ch)               nmInitDelayTimeCalCnt
  #define NmCfg_InitDelayLocal_Cnt(ch)          nmInitDelayTimeCalCnt
  #define NmCfg_SleepTransition_Cnt(ch)         ((tCommEnableTimer)(nmVNMFStartSendCalCnt+2)) 
  #define NmCfg_VnmfStartSend_Cnt(ch)           nmVNMFStartSendCalCnt
  #define NmCfg_VnmfPeriodicRate_Cnt(ch)        nmVNMFSendTimeCalCnt

  #define NmCfg_VN_StartIndex(ch)               0
  #define NmCfg_VN_StopIndex(ch)                (kNmNumberOfVirtualNets-1)
  #define NmCfg_VnByte_StartIndex(ch)           0
  #define NmCfg_VnByte_StopIndex(ch)            (kNmNumberOfVnBytes-1)
#endif

#if defined ( NM_ENABLE_INDEXED_NM ) || \
    defined ( NM_ENABLE_MULTIPLE_NODES )
  #define NmCfg_SourceId(ch)                    (NmSourceId_Field[NmIdentity(ch, vActiveIdentityLog)])
  #define NmCfg_TxHndl_VNMF(ch)                 (NmTxHandle_VNMF_Field[NmIdentity(ch, vActiveIdentityLog)])
#else
  #define NmCfg_SourceId(ch)                    (kNmSourceId)
  #define NmCfg_TxHndl_VNMF(ch)                 (kNmTxHndl_VNMF)
#endif

/*--- channel access macros -----------------------------------------------------------------------------------------*/
/*--- NM ---*/
#if defined ( NM_ENABLE_INDEXED_NM )
  #define NM_CHANNEL_NMTYPE_ONLY                CanChannelHandle channel
  #define NM_CHANNEL_NMTYPE_FIRST               CanChannelHandle channel,
  #define NM_CHANNEL_NMPARA_ONLY                channel
  #define NM_CHANNEL_NMPARA_FIRST               channel,
  #define NM_CHANNEL_IDX                        channel
#else
  #define NM_CHANNEL_NMTYPE_ONLY                void
  #define NM_CHANNEL_NMTYPE_FIRST               
  #define NM_CHANNEL_NMPARA_ONLY                
  #define NM_CHANNEL_NMPARA_FIRST               
  #define NM_CHANNEL_IDX                        0
#endif

/*--- CAN ---*/
#if defined ( NM_ENABLE_INDEXED_NM )
  #define NM_CHANNEL_CANTYPE_ONLY               CanChannelHandle channel
  #define NM_CHANNEL_CANTYPE_FIRST              CanChannelHandle channel,
  #define NM_CHANNEL_CANPARA_ONLY               channel
  #define NM_CHANNEL_CANPARA_FIRST              channel,
#else
  #define NM_CHANNEL_CANTYPE_ONLY               void
  #define NM_CHANNEL_CANTYPE_FIRST              
  #define NM_CHANNEL_CANPARA_ONLY               
  #define NM_CHANNEL_CANPARA_FIRST              
#endif

/*--- IL---*/
#if defined ( NM_ENABLE_INDEXED_NM )
  #define NM_CHANNEL_ILPARA_ONLY                channel
  #define NM_CHANNEL_ILPARA_FIRST               channel,
#else
  #define NM_CHANNEL_ILPARA_ONLY                
  #define NM_CHANNEL_ILPARA_FIRST               
#endif

/*--- APPL ---*/
#if defined ( NM_ENABLE_INDEXED_NM )
  #define NM_CHANNEL_APPLTYPE_ONLY              CanChannelHandle channel
  #define NM_CHANNEL_APPLTYPE_FIRST             CanChannelHandle channel,
  #define NM_CHANNEL_APPLPARA_ONLY              channel
  #define NM_CHANNEL_APPLPARA_FIRST             channel,
#else
  #define NM_CHANNEL_APPLTYPE_ONLY              void
  #define NM_CHANNEL_APPLTYPE_FIRST             
  #define NM_CHANNEL_APPLPARA_ONLY              
  #define NM_CHANNEL_APPLPARA_FIRST             
#endif

/**********************************************************************************************************************
  Global data prototypes (exported, RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Global data prototypes (exported, ROM)
**********************************************************************************************************************/

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kGmlanNmMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kGmlanNmSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kGmlanNmReleaseVersion;

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kGmlanMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kGmlanSubVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kGmlanReleaseVersion;

#if defined( VERSIONNUMBER )
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kDataDictMainVersion;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kDataDictSubVersion;
#else
  #if defined ( VERSIONYEAR )
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kDataDictMainVersion;
  #endif
  #if defined ( VERSIONWEEK )
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 kDataDictSubVersion;
  #endif
#endif


/**********************************************************************************************************************
  Global data prototypes (imported, RAM)
**********************************************************************************************************************/
V_MEMRAM0 extern V_MEMRAM1_NEAR nmMessType V_MEMRAM2_NEAR nmSendMess;

#if defined ( NM_ENABLE_USERSPECIFIC_CANINITOBJECTS )
  #if defined ( NM_ENABLE_INDEXED_NM )
V_MEMRAM0 extern V_MEMRAM1 vuint8 V_MEMRAM2 nmCanInitObjStd[kNmNumberOfChannels];
  #else
V_MEMRAM0 extern V_MEMRAM1 vuint8 V_MEMRAM2 nmCanInitObjStd;
  #endif
#endif

#if defined ( NM_ENABLE_HIGHSPEED_MODE ) && \
    defined ( NM_ENABLE_USERSPECIFIC_CANINITOBJECTS )
  #if defined ( NM_ENABLE_INDEXED_NM )
V_MEMRAM0 extern V_MEMRAM1 vuint8 V_MEMRAM2 nmCanInitObjHighSpeed[kNmNumberOfChannels];
  #else
V_MEMRAM0 extern V_MEMRAM1 vuint8 V_MEMRAM2 nmCanInitObjHighSpeed;
  #endif
#endif

#if defined ( NM_ENABLE_INDEXED_NM )
#else
  #if defined ( kNmTxHndl_VNMF )
  #else
V_MEMRAM0 extern V_MEMRAM1 CanTransmitHandle V_MEMRAM2 nmTxObj;
  #endif
#endif

/**********************************************************************************************************************
  Global data prototypes (imported, ROM)
**********************************************************************************************************************/

/*--- general -------------------------------------------------------------------------------------------------------*/
#if defined ( NM_ENABLE_INDEXED_NM ) || \
    defined ( NM_ENABLE_MULTIPLE_NODES )
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle V_MEMROM2 NmTxHandle_VNMF_Field[kNmNumberOfChannels*kNmNumberOfIdentities];
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 NmSourceId_Field[kNmNumberOfChannels*kNmNumberOfIdentities];
#endif

#if defined( NM_ENABLE_INDEXED_NM )
V_MEMROM0 extern V_MEMROM1 tNmTrcvrType V_MEMROM2 NmTrcvType_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 CanTransmitHandle V_MEMROM2 NmTxHandle_HLVW_Field[kNmNumberOfChannels];
#endif

/*--- VN handling ---------------------------------------------------------------------------------------------------*/
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 NmVnTypeTable[kNmNumberOfVirtualNets];
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 NmVnByteOffset[kNmNumberOfVirtualNets];
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 NmVnByteMask[kNmNumberOfVirtualNets];
#if defined( NM_ENABLE_INDEXED_NM )
V_MEMROM0 extern V_MEMROM1 vuint8  V_MEMROM2 NmVnStartIndex[kNmNumberOfChannels+1];
#endif
#if (kNmNumberOfLVSusceptibleVNs > 0)
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 NmVnLVSusceptTable[kNmNumberOfLVSusceptibleVNs];
#endif
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 NmVnRelevantMask[kNmNumberOfVnBytes];
#if defined( NM_ENABLE_INDEXED_NM )
V_MEMROM0 extern V_MEMROM1 vuint8  V_MEMROM2 NmVnByteStartIndex[kNmNumberOfChannels+1];
#endif

/*--- timing --------------------------------------------------------------------------------------------------------*/
#if defined( NM_ENABLE_INDEXED_NM )
V_MEMROM0 extern V_MEMROM1 vuint8  V_MEMROM2 NmCallCycle_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2 NmDeactSleepCnt_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2 NmHighSpeedCnt_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2 NmLastWakeupCnt_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2 NmMsgConfirmMinCnt_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2 NmSleepDeniedCnt_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2 NmVNMFConfirmCnt_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2 NmVNRestartIVNMFCnt_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2 NmVnRxTimerCnt_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2 NmVnTimerCnt_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2 NmWakeupFailCnt_Field[kNmNumberOfChannels];
V_MEMROM0 extern V_MEMROM1 vuint16 V_MEMROM2 NmWakeupSleepCnt_Field[kNmNumberOfChannels];
#endif


/**********************************************************************************************************************
  Global function prototypes
**********************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------
  service functions
---------------------------------------------------------------------------------------------------------------------*/
/*--- network management --------------------------------------------------------------------------------------------*/
extern void IlNwmInit( NM_CHANNEL_NMTYPE_ONLY );
extern void IlNwmTask( NM_CHANNEL_NMTYPE_ONLY );

extern nmStatusType IlNwmGetStatus( NM_CHANNEL_NMTYPE_ONLY );

#if defined( NM_ENABLE_HIGHSPEED_MODE )
extern void IlNwmResetHispeedMode( NM_CHANNEL_NMTYPE_ONLY );
extern Nm_Status IlNwmSetHispeedMode( NM_CHANNEL_NMTYPE_ONLY );
#endif

extern Nm_Status IlNwmNormalCommHalted( NM_CHANNEL_NMTYPE_ONLY );
extern void IlNwmReturnToNormalMode( NM_CHANNEL_NMTYPE_ONLY );

#if defined( NM_ENABLE_LOWVOLTAGE_MODE )
extern void IlNwmEnterLowVoltageMode( NM_CHANNEL_NMTYPE_ONLY );
extern void IlNwmExitLowVoltageMode( NM_CHANNEL_NMTYPE_ONLY );
#endif

/*--- VN handling ---------------------------------------------------------------------------------------------------*/
#if defined( NM_ENABLE_VN_LOCAL ) || \
    defined( NM_ENABLE_VN_ACTIVATOR )
extern Nm_Status IlNwmActivateVN( NM_CHANNEL_NMTYPE_FIRST  vuint8 vnHndl );
extern Nm_Status IlNwmDeactivateVN( NM_CHANNEL_NMTYPE_FIRST  vuint8 vnHndl );
#endif
extern void IlNwmGetActiveListVN( NM_CHANNEL_NMTYPE_FIRST  vuint8 *vnList );
extern vuint16 IlNwmGetVnTimer( NM_CHANNEL_NMTYPE_FIRST  vuint8 vnHndl );
extern vuint8 IlNwmIsActiveVN( NM_CHANNEL_NMTYPE_FIRST  vuint8 vnHndl );

#if defined( NM_ENABLE_INHIBIT_VN_HIGHLOAD) && \
    defined( NM_ENABLE_VN_ACTIVATOR )
extern void IlNwmInhibitActivationVN( NM_CHANNEL_NMTYPE_ONLY );
extern void IlNwmAllowActivationVN( NM_CHANNEL_NMTYPE_ONLY );
#endif

/*--- node management -----------------------------------------------------------------------------------------------*/
extern void NmInit( NM_CHANNEL_NMTYPE_ONLY );


/*---------------------------------------------------------------------------------------------------------------------
  callback functions
---------------------------------------------------------------------------------------------------------------------*/
/*--- transceiver handling ------------------------------------------------------------------------------------------*/
#if defined( NM_ENABLE_SINGLEWIRE_TRCV ) && \
    defined( NM_ENABLE_HIGHSPEED_MODE )
extern void ApplTrcvrHighSpeed( NM_CHANNEL_APPLTYPE_ONLY );
#endif
#if defined( NM_ENABLE_SINGLEWIRE_TRCV )
extern void ApplTrcvrHighVoltage( NM_CHANNEL_APPLTYPE_ONLY );
#endif
extern void ApplTrcvrNormalMode( NM_CHANNEL_APPLTYPE_ONLY );
#if defined( NM_ENABLE_SINGLEWIRE_TRCV ) || \
    defined( NM_ENABLE_HIGHSPEED_SLEEP_TRCV )
extern void ApplTrcvrSleepMode( NM_CHANNEL_APPLTYPE_ONLY );
#endif

/*--- VN handling ---------------------------------------------------------------------------------------------------*/
#if defined ( NM_ENABLE_REINITREQUEST_FCT )
extern void ApplNwmReinitRequest( NM_CHANNEL_APPLTYPE_FIRST  vuint8 vnHndl, vuint8 ReinitRequest );
#endif
#if defined( NM_ENABLE_VN_ACTIVATION_FAILED_FCT)
extern vuint8 ApplNwmVnActivationFailed( NM_CHANNEL_APPLTYPE_FIRST  vuint8 vnHndl );
#endif
extern void ApplNwmVnActivated( NM_CHANNEL_APPLTYPE_FIRST  vuint8 vnHndl );
extern void ApplNwmVnDeactivated( NM_CHANNEL_APPLTYPE_FIRST  vuint8 vnHndl );
#if defined( NM_ENABLE_VN_REMOTE_ACTIVATE_REQUEST_FCT )
 extern vuint8 ApplNwmVnRemoteActivateRequest( NM_CHANNEL_APPLTYPE_FIRST  vuint8 vnHndl );
#endif
#if defined( NM_ENABLE_VNMF_CONFIRMATION_TIMEOUT_FCT )
extern void ApplNwmVnmfConfirmationTimeout( NM_CHANNEL_APPLTYPE_ONLY );
#endif

/*--- wakeup/sleep handling -----------------------------------------------------------------------------------------*/
#if defined( NM_ENABLE_HLVW_INDICATION_FCT )
extern void ApplNwmHLVWStart( NM_CHANNEL_APPLTYPE_ONLY );
extern void ApplNwmHLVWStop( NM_CHANNEL_APPLTYPE_ONLY );
#endif
#if defined( NM_ENABLE_SLEEP_FCT )
extern void ApplNwmSleep( NM_CHANNEL_APPLTYPE_ONLY );
#endif
#if defined ( NM_ENABLE_SLEEPCONFIRMATION_FCT )
extern vuint8 ApplNwmSleepConfirmation( NM_CHANNEL_APPLTYPE_ONLY );
#endif
#if defined( NM_ENABLE_WAKEUP_FCT )
extern void ApplNwmWakeup( NM_CHANNEL_APPLTYPE_ONLY );
#endif
#if defined( NM_ENABLE_WAKEUP_RECEIVED_FCT )
extern void ApplNwm100MsgRecv( NM_CHANNEL_APPLTYPE_ONLY );
extern void ApplNwmWakeupMsgRecv( NM_CHANNEL_APPLTYPE_ONLY );
#endif

/*--- BusOff handling -----------------------------------------------------------------------------------------------*/
#if defined( NM_ENABLE_BUSOFF_FCT )
extern void ApplNwmBusoff( NM_CHANNEL_APPLTYPE_ONLY );
#endif
#if defined( NM_ENABLE_BUSOFF_END_FCT )
extern void ApplNwmBusoffEnd( NM_CHANNEL_APPLTYPE_ONLY );
#endif

/*--- debug handling ------------------------------------------------------------------------------------------------*/
#if defined( NM_ENABLE_ASSERTIONS )
/* Code: The name of the assertion function is configurable: see define NM_ASSERT_FCT */
extern void NM_ASSERT_FCT( tErrState errorCode );
#endif

/**********************************************************************************************************************
  Global configuration check
**********************************************************************************************************************/
#if defined ( NM_TYPE_GMLAN )
#else
  #error "Nm_Gmlan_Gm (config): NM_TYPE_GMLAN is not defined."
#endif

#if defined ( NM_ENABLE_CALL_CANINITPON ) && \
    defined ( NM_DISABLE_CALL_CANINITPON )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_CALL_CANINITPON is multiply defined."
#endif
#if defined ( NM_ENABLE_CALL_CANINITPON ) || \
    defined ( NM_DISABLE_CALL_CANINITPON )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_CALL_CANINITPON is not defined."
#endif

#if defined ( NM_ENABLE_INHIBIT_VN_HIGHLOAD ) && \
    defined ( NM_DISABLE_INHIBIT_VN_HIGHLOAD )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_INHIBIT_VN_HIGHLOAD is multiply defined."
#endif
#if defined ( NM_ENABLE_INHIBIT_VN_HIGHLOAD ) || \
    defined ( NM_DISABLE_INHIBIT_VN_HIGHLOAD )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_INHIBIT_VN_HIGHLOAD is not defined."
#endif

#if defined ( NM_ENABLE_HIGHSPEED_MODE ) && \
    defined ( NM_DISABLE_HIGHSPEED_MODE )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_HIGHSPEED_MODE is multiply defined."
#endif
#if defined ( NM_ENABLE_HIGHSPEED_MODE ) || \
    defined ( NM_DISABLE_HIGHSPEED_MODE )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_HIGHSPEED_MODE is not defined."
#endif

#if defined ( NM_ENABLE_LOWVOLTAGE_MODE ) && \
    defined ( NM_DISABLE_LOWVOLTAGE_MODE )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_LOW_VOLTAGE_TOLERANT_MODE is multiply defined."
#endif
#if defined ( NM_ENABLE_LOWVOLTAGE_MODE ) || \
    defined ( NM_DISABLE_LOWVOLTAGE_MODE )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_LOW_VOLTAGE_TOLERANT_MODE is not defined."
#endif

#if defined ( NM_ENABLE_CANOFF_ON_LOWVOLTAGE_MODE ) && \
    defined ( NM_DISABLE_CANOFF_ON_LOWVOLTAGE_MODE )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_CANOFF_ON_LVMODE is multiply defined."
#endif
#if defined ( NM_ENABLE_CANOFF_ON_LOWVOLTAGE_MODE ) || \
    defined ( NM_DISABLE_CANOFF_ON_LOWVOLTAGE_MODE )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_CANOFF_ON_LVMODE is not defined."
#endif

#if defined ( NM_ENABLE_BUSOFF_FCT ) && \
    defined ( NM_DISABLE_BUSOFF_FCT )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_BUSOFF_FCT is multiply defined."
#endif
#if defined ( NM_ENABLE_BUSOFF_FCT ) || \
    defined ( NM_DISABLE_BUSOFF_FCT )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_BUSOFF_FCT is not defined."
#endif

#if defined ( NM_ENABLE_BUSOFF_END_FCT ) && \
    defined ( NM_DISABLE_BUSOFF_END_FCT )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_BUSOFF_END_FCT is multiply defined."
#endif
#if defined ( NM_ENABLE_BUSOFF_END_FCT ) || \
    defined ( NM_DISABLE_BUSOFF_END_FCT )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_BUSOFF_END_FCT is not defined."
#endif

#if defined ( NM_ENABLE_WAKEUP_FCT ) && \
    defined ( NM_DISABLE_WAKEUP_FCT )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_WAKEUP_FCT is multiply defined."
#endif
#if defined ( NM_ENABLE_WAKEUP_FCT ) || \
    defined ( NM_DISABLE_WAKEUP_FCT )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_WAKEUP_FCT is not defined."
#endif

#if defined ( NM_ENABLE_SLEEP_FCT ) && \
    defined ( NM_DISABLE_SLEEP_FCT )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_SLEEP_FCT is multiply defined."
#endif
#if defined ( NM_ENABLE_SLEEP_FCT ) || \
    defined ( NM_DISABLE_SLEEP_FCT )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_SLEEP_FCT is not defined."
#endif

#if defined ( NM_ENABLE_WAKEUP_RECEIVED_FCT ) && \
    defined ( NM_DISABLE_WAKEUP_RECEIVED_FCT )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_WAKEUP_RECEIVED_FCT is multiply defined."
#endif
#if defined ( NM_ENABLE_WAKEUP_RECEIVED_FCT ) || \
    defined ( NM_DISABLE_WAKEUP_RECEIVED_FCT )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_WAKEUP_RECEIVED_FCT is not defined."
#endif

#if defined ( NM_ENABLE_VN_REMOTE_ACTIVATE_REQUEST_FCT ) && \
    defined ( NM_DISABLE_VN_REMOTE_ACTIVATE_REQUEST_FCT )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_VN_REMOTE_ACTIVATE_REQUEST_FCT is multiply defined."
#endif
#if defined ( NM_ENABLE_VN_REMOTE_ACTIVATE_REQUEST_FCT ) || \
    defined ( NM_DISABLE_VN_REMOTE_ACTIVATE_REQUEST_FCT )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_VN_REMOTE_ACTIVATE_REQUEST_FCT is not defined."
#endif

#if defined ( NM_ENABLE_VN_ACTIVATION_FAILED_FCT ) && \
    defined ( NM_DISABLE_VN_ACTIVATION_FAILED_FCT )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_VN_ACTIVATION_FAILED_FCT is multiply defined."
#endif
#if defined ( NM_ENABLE_VN_ACTIVATION_FAILED_FCT ) || \
    defined ( NM_DISABLE_VN_ACTIVATION_FAILED_FCT )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_VN_ACTIVATION_FAILED_FCT is not defined."
#endif

#if defined ( NM_ENABLE_VNMF_CONFIRMATION_TIMEOUT_FCT ) && \
    defined ( NM_DISABLE_VNMF_CONFIRMATION_TIMEOUT_FCT )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_VNMF_CONFIRMATION_TIMEOUT_FCT is multiply defined."
#endif
#if defined ( NM_ENABLE_VNMF_CONFIRMATION_TIMEOUT_FCT ) || \
    defined ( NM_DISABLE_VNMF_CONFIRMATION_TIMEOUT_FCT )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_VNMF_CONFIRMATION_TIMEOUT_FCT is not defined."
#endif

#if defined ( NM_ENABLE_HLVW_INDICATION_FCT ) && \
    defined ( NM_DISABLE_HLVW_INDICATION_FCT )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_HLVW_INDICATION_FCT is multiply defined."
#endif
#if defined ( NM_ENABLE_HLVW_INDICATION_FCT ) || \
    defined ( NM_DISABLE_HLVW_INDICATION_FCT )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_HLVW_INDICATION_FCT is not defined."
#endif

#if defined ( NM_ENABLE_REINITREQUEST_FCT ) && \
    defined ( NM_DISABLE_REINITREQUEST_FCT )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_REINITREQUEST_FCT is multiply defined."
#endif
#if defined ( NM_ENABLE_REINITREQUEST_FCT ) || \
    defined ( NM_DISABLE_REINITREQUEST_FCT )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_REINITREQUEST_FCT is not defined."
#endif

#if defined ( NM_ENABLE_SLEEPCONFIRMATION_FCT ) && \
    defined ( NM_DISABLE_SLEEPCONFIRMATION_FCT )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_SLEEPCONFIRMATION_FCT is multiply defined."
#endif
#if defined ( NM_ENABLE_SLEEPCONFIRMATION_FCT ) || \
    defined ( NM_DISABLE_SLEEPCONFIRMATION_FCT )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_SLEEPCONFIRMATION_FCT is not defined."
#endif

#if defined ( NM_ENABLE_EXTENDED_RETURNCODES ) && \
    defined ( NM_DISABLE_EXTENDED_RETURNCODES )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_EXTENDED_RETURNCODES is multiply defined."
#endif
#if defined ( NM_ENABLE_EXTENDED_RETURNCODES ) || \
    defined ( NM_DISABLE_EXTENDED_RETURNCODES )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_EXTENDED_RETURNCODES is not defined."
#endif

#if defined ( NM_ENABLE_ASSERTIONS ) && \
    defined ( NM_DISABLE_ASSERTIONS )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_ASSERTIONS is multiply defined."
#endif
#if defined ( NM_ENABLE_ASSERTIONS ) || \
    defined ( NM_DISABLE_ASSERTIONS )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_TESTDEBUG is not defined."
#endif

#if defined ( NM_ENABLE_VN_ACTIVATOR ) && \
    defined ( NM_DISABLE_VN_ACTIVATOR )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_VN_ACTIVATOR is multiply defined."
#endif
#if defined ( NM_ENABLE_VN_ACTIVATOR ) || \
    defined ( NM_DISABLE_VN_ACTIVATOR )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_VN_ACTIVATOR is not defined."
#endif

#if defined ( NM_ENABLE_VN_REMOTED ) && \
    defined ( NM_DISABLE_VN_REMOTED )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_VN_REMOTELD is multiply defined."
#endif
#if defined ( NM_ENABLE_VN_REMOTED ) || \
    defined ( NM_DISABLE_VN_REMOTED )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_VN_REMOTED is not defined."
#endif

#if defined ( NM_ENABLE_VN_LOCAL ) && \
    defined ( NM_DISABLE_VN_LOCAL )
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_VN_LOCAL is multiply defined."
#endif
#if defined ( NM_ENABLE_VN_LOCAL ) || \
    defined ( NM_DISABLE_VN_LOCAL )
#else
  #error "Nm_Gmlan_Gm (config): NM_<EN|DIS>ABLE_VN_LOCAL is not defined."
#endif
/*--- integration aspects -------------------------------------------------------------------------------------------*/
#if (defined( NM_ENABLE_VN_ACTIVATOR ) || defined( NM_ENABLE_VN_REMOTED )) && !defined( C_ENABLE_CONFIRMATION_FCT )
  #error "Nm_Gmlan_Gm (config): There has to be a confirmation routine for the current configuration."
#endif
#if (defined( NM_ENABLE_VN_ACTIVATOR ) || defined( NM_ENABLE_VN_REMOTED )) && !defined( C_ENABLE_PRETRANSMIT_FCT )
  #error "Nm_Gmlan_Gm (config): There has to be a pretransmit routine for the current configuration."
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL ) || defined( C_MULTIPLE_RECEIVE_CHANNEL )
#else
  #error "Nm_Gmlan_Gm (config): Interface of DrvCan is not supported."
#endif


#endif /* V_NM_GMLAN_GM_HEADER */

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
/* ORGANI: STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
