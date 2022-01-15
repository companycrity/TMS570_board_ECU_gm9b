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
         File:  gmnm.c
      Project:  Nm_Gmlan_Gm
       Module:  -
    Generator:  -
  Description:  Vector GMLAN Network Management source file
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
  Ht           Heike Honert              Vector Informatik GmbH
  Hp           Armin Happel              Vector Informatik GmbH
  Jrw          Jason Wolbers             Vector CANtech, Inc.
  Law          Laura Anne Winder         Vector CANtech, Inc.
  Mfr          Michael Radwick           Vector CANtech, Inc.
  Mr           
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
  2.00      12.02.1999  Hp      Creation;
                                Starting with V2.0 to distinguish between HGMLAN V1.x
                                and GMLAN > V2.x
  2.01      08.03.1999  Ba      Supporting of Hiware ST7
                        Hp      Supporting C16x/HC12
  2.10      31.03.1999  Hp      Some corrections:
                                Calling ActivatedVN on init and on self-activation,
                                after sending the VNMF
                                Adding VDA support
                                Sending ReinitializeVN
  2.11      13.04.1999  Hp      Config-switches for GMNM-module to scale it according
                                to the usage of VN's and HighSpeedMode (especially for HSCAN)
  2.12      14.04.1999  Hp      Activate Rx-VN immediately on activation by appl.
                                Initially-active-VN's are activated on each received/
                                transmitted HLVW.
  2.13      30.04.1999  Ba      Changes for Hiware ST7:
                                nmSendMess is a ptr to a character array
                                write to the last Tx buffer byte in pretransmit
                                function to start transmit request
                                dummy assignments because of compiler warnings
  2.14      01.06.1999  Hp      Initially-Active VN's activated on sendout/
                                receiving of each wakeup message (100h).
                                No shorten of VNMF-sendout when VN-timer is > 5 sec.
  2.15      05.06.1999  Hp      For C16x/Gnu-C only: move the rcvObject-assignment
                                below the RcvData-declaration.
            01.07.1999  Fr      Creating SingleSource for multiple channel versions
  2.20      20.07.1999  Hp      Some changes:
                                VnTimer is synchronized with transmitted and received
                                VNMF
                                Distinguish between local and remotely activated VN
                                VN initialization is handled internally, callback added.
                                Confirmation check for transmitted VNMF
  2.21      22.07.1999  Ht      nmMessType for Keil and Tasking compiler
                        Hp      Bugfix: Re-enter the ApplNwmVnActivated();
                                Correcting parameter for ApplNwmVnDeactivated()
                                Improvements concerning reentrance
  2.22      26.07.1999  Hp      return value of IlNwmIsActiveVN(vnHndl); corrected.
                                Clearing nmVNMFTxRequest and SendHVMsgRequest only if
                                status NM_COMM_ENABLE is reached NOT from NM_COMM_OFF.
  2.23      26.08.1999  Ht      RecvData changed to  RecvData for C16x-comp.
                                Position of NmErrStr changed
                                test for id=100h corrected
                        Hp      Changing NodeState, when VnActivation/ActivcationPending
                                has been set.
                                Do always confirmation-timeout for VNMF.
  2.30      22.11.1999  Hp      No CanInit() when NormalCommHalted is entered
                                No wakeup transission when VN already (remotely) active.
                                Splitting VNMF into INIT/CONTINUE fields.
                        Th      nmSendInit & nmSendContinue adapted for Hiware ST7
  2.31      30.11.1999  Hp      Error correction: Check VnActive state in NmStateTask()
                                to set NMActive state flag properly (solves incorrect
                                sleepmode transition after BusOff).
  2.32      31.01.2000  Hp      Adding counter for HLVW-retries
                                NM_ENABLE_EXTENDED_RETURNCODES now configurable for each channel
                                in a multi-channel environment
                                No canceling of messages in OFF-, HighSpeed- or
                                CommHalted state.
                                reception of VNMF during NoCommunication allowed,
                                disallow reception of VNMF when transit to NM_COMM_OFF
                                resp. in COMM_OFF.
  2.33      06.02.2000  Hp      Adapting config switch naming convention
                                for automatic configuration of GMLAN with CANgen.
  2.34      11.05.2000  Hp      Portation to NEC V850 with NEC-Compiler
  2.40      14.07.2000  Hp      GMLAN-Source with OLD NAMING convention for manual
                                configuration via CAN_CFG.H
                                Including TxObserve option to check successful
                                transmission of all messages. This has been included
                                for detection of Ground Offset on SingleWire-CAN.
                                Now, ActivateVN accepts activation even though a
                                pending activation is still not successfully proceeded.
                                Wakeup message delay increased to 4.5 sec.
                                The messages, associated to a VN will now immediately
                                enabled for reception, when a VNMF is received. This
                                is done in the NmPrecopy function, which is in
                                interrupt context. This eliminates the  risk to discard
                                received messages on pending VN activation. As a result,
                                the runtime of this interrupt service routine has been
                                extended sometimes.
  2.41      18.09.2000  Hp      Remove access to nmActNrOfTxObj, when only one
                                Tx-object is used.
                                Bit reversal for some micros.
  2.42      21.02.2001  Fz      Support of indexed CAN-Driver added
  2.49      11.12.2000  Hp      Pre-Release for GM-internal verification:
                                Adding LowVoltage mode
                                Some general improvements.
  2.50      20.07.2001  Hp       Release GMLAN V2.50
                                Solve ESCAN00000262 (Delete internal wakeup Tx-request 
                                when receiving HLVW).
                                Solve ESCAN00000286. Conditionally restart the I-VNMF timer
                                transmission timer when receiving HLVW.
                                Solve ESCAN00000311: Start VNMF-confirmation timer when
                                initiating VNMF-Tx-request.
                                Solve ESCAN00000434: Re-entrance of IlRxActivateVN();
                        Ht      C_COMP_KEIL_C16x changed to C_COMP_KEIL_C16X
  2.51      10.08.2001  dH      added C_COMP_HEW_SH7055
  2.52      14.08.2001  Ht      ESCAN00001220: expand support of code doubling
  2.53      18.09.2001  Al      added C_COMP_GNU_ST9
  2.54      17.10.2001  Al      fixed atomic write problem
                                fixed problem with code being stuck in TrcvrHighVoltage mode
                                if BusOff occurs during HVWU Tx
                                fixed 7 second problem, changes also in Ils.c
  3.00      09.11.2001  Al      Added RSMs for GMLAN 3.0, current version is internal
                                pre-release.
  3.00      23.11.2001  Hp      ESCAN00001817: Delayed VNMF after Wakeup solved.
                                Avoiding VN-timer if ONLY Shared-Local-Input-VNs are used.
                                Timeout-observation and retry of Wakeup-frames with BusOff.
                                Smaller refinements in the FctCall/SetFlag order.
                                Separate start-up of signal supervision from the Rx-Activation
                                to improve throughput in the ISR.
  3.00      07.12.2001  Al       - Changed ints to unsigned char.
                              - Changed sleep timer to max(4, nmGenericTimer) for comm_active -> comm_enable
                                Moved VN inhibit state variable into nmState[1].
  3.00      01.02.2002  Al      Added kNmSleepDeniedTime, this is time to stay in comm_enabled
                                after denied ApplNwmSleepConfirmation.
                                Added DLC check to VNMF processing bit field processing
                                Allow for sleep time set to 8 sec if HVWU received in comm_active.
  3.00      04.03.2002  Al      Added check to see if HVWU needs to be sent in C before I condition.
  3.00      04.03.2002  Hp      Restart Signal supervision when a VN s restarted and VN-timer < 1sec.
  3.00      15.03.2002  Al      Added support to detect HVWU upon going to sleep.
                              - Added protection from missing HVWU during re-init.
                              - Do not send I-VNMF for init active VNs.
  3.01      2002-03-22  Hp      - Calibratable values changed to constants for GMLAN V2.6.
            2002-04-05  Hp      - Splitting the overlayed C-VNMF-timer and COMM-Enable timer into two timers
                              - Re-structure the definition order.
            2002-05-10  Hp      - ESCAN00001156: New names of CAN-driver LI1.2
                                ESCAN00002538 Call ResetBusoffStart directly in NmCanError()
                                              Making an indexed version of GMLAN-NM.
            2002-05-16  Hp                    First draft of an indexed version of GMLAN-NM
            2002-06-12  Hp                    Changing the names of the arrays VnBitMask[]/ByteOffs[] 
                                              to NmVnByteMask[]/NmVnByteOffset[]. Is generated for indexed systems.
  3.01.01   2002-07-02  Hp      ESCAN00003144 Incorrect bit definition in nmState structure
                                              with the option C_CPUTYPE_BITORDER_MSB2LSB
  3.02      2002-07-16  Hp                    Move timer default values to GMNMDEF.H. 
                                ESCAN00002871 Timer parameters for indexed-NM now channel specific.
                                              CANgen V3.88 and higher now recommended, especially for indexed systems.
  3.03      2002-11-05  Hp      ESCAN00003429 Processing VNMF for more than two bytes 
                                              if DLC is shorter than expected.
                                ESCAN00003435 Solves delayed Continue-VNMF for Activator+Initially Active VN
                                ESCAN00003715 Add #pragma for external const definition for M16C
                        Si                    some casts added 
                        Fz      ESCAN00004083 Compiler Failure with C_SINGLE_RECEIVE_CHANNEL API removed
  3.04      2002-11-11  Fz      ESCAN00004148 Compiler warning removed
  3.05      2003-01-27  Fz      ESCAN00004402 Insert comment and define for transition into sleep mode
                        Mr      ESCAN00004733 BusOff handling changed to be Strategy V1.5 compliant
                        Hp      ESCAN00004734 DeactivateVN(0) removed from NormalCommHalted/ResetHispeedMode
                                              to meet GMW3110 requirements with Shared-Local-input-VNs (DIAG_VN_TIMER).
                        Hp      ESCAN00004735 Correction of ReturnToNormalMode with HighSpeed and LowVoltage mode.
                        Hp      ESCAN00004736 Corrected Initially-Activated VN with Shared-Local VNs only
                        Hp      ESCAN00004737 Delayed Activation of Shared-Local VNs
                        Fz      ESCAN00004349 Timer check for ApplNwmSleepConfirmation changed  
                        Mr                     Modify NmPreCopy() to remove variable-length VNMF handling.
                        Hp      ESCAN00004728 Inhibit activation of Initially-Active VN for NormalCommHalted 
                                              when transmitting HLVW. Clear activation when entering NormalCommHalted.
  3.06      2003-02-03  Mra                   Fixed missing _0 and _1 in codedoubled projects, 
                                              Bugfix in VNMF assertion test
                        Ds      ESCAN00004534 Reentrancy and near memory support for the ST7beCAN Hiware.
                                              Casts added.
                        Mra                   Removed assertions at the end of NmVnTimerTask() and NmStateTask()
                        Hp      ESCAN00004846 Inhibit C-VNMF after a HLVW, finally between HLVW and I-VNMF.
                        Hp      ESCAN00004847 Activation time for Initially-Active VNs too short
  3.07      2003-03-24  Mra     ESCAN00005012 Fixed missing _0 and _1 in codedoubled multi-ECU projects
                        Fz      ESCAN00005086 Assertion moved in NmPrecopy
  3.08      2003-04-03  Fz      ESCAN00005293 NmPrecopy will access memory outside of receive CAN buffer  
  3.09      2003-04-28  Mfr     ESCAN00005465 Change the WAKEUP_SYNC_DELAY time from average to a minimum time.
                                ESCAN00005442 Increment initialization of nmSendInitVnmfCnt[] by one.
                                ESCAN00005466 Unnecessary delay time for transmission of I-VNMF.
                        Hp      ESCAN00005467 Disable interrupts while enable message reception for Initially-Active VNs
                        Fz      ESCAN00005542 Some defines missing for indexed systems
  3.10      2003-05-15  Tri     ESCAN00005677 Implementing memory qualifier V_MEMROM0
  3.11      2003-05-16  Mra     ESCAN00005697 Missing  in GMLAN_VERSION if-clause fixed
                                ESCAN00005696
  3.12      2003-07-08  Hp      ESCAN00005697 Interface function provided to get current VN-Timer value
                                              Change some internal variables from global to local.
                        Hp      ESCAN00005658 Avoid compiler warning in specific configurations for NmHVPreCopy().
                        Hp      ESCAN00006004 Shared Input VN activation delay timer changed to ensure minimum value.
  3.13      2003-08-13  Tri     ESCAN00006352 Support for V_ENABLE_USE_DUMMY_STATEMENT added
  3.14      2003-09-15  Mr      ESCAN00006569 Bus-Off recovery time delay is not honored
  3.15      2003-11-11  Hp      ESCAN00006904 Improve data integrity for internal counter
  3.16      2004-01-16  Fz      ESCAN00006991 Add of TMS 320
                        Hp      ESCAN00007136 Deactivation of a Shared-Local VN leads to a VNMF transmission request
                        Fz      ESCAN00007315 Initialisation optimization for single and multiple receive systems
  3.17      2004-06-23  Law     ESCAN00007148 Updated memory qualifiers
                        Fz                    BUGFIX changed to RELEASE
                                ESCAN00008733 Add support for multiple NM
                                ESCAN00007353 Conditionally compiled definition in GMNM.C
  3.18      2004-10-15  Fz      ESCAN00006550 Compiler waring because of unused variable removed
                                ESCAN00006548 Compiler waring because of unused variable removed 
                                ESCAN00009900 Handler does not enter sleep mode
  3.19      2005-01-24  Fz      ESCAN00010876 Diagnostic VN will not be activated on second CAN channel
                                              when normal communication halted state is entered
                                ESCAN00009901 Implement new version defines
  3.20      2005-02-22  Fz      ESCAN00011254 Enable IL transmit messages of diagnostic VN in case
                                              of normal communication halted state too.
  3.21      2005-02-24  Fz      ESCAN00010876 Diagnostic VN will not be activated on second CAN channel
                                              when normal communication halted state is entered
  3.22      2005-03-22  Fz      ESCAN00011431 ECU sends IL messages even if the normal communication is halted.
  3.23      2006-01-13  Fz      ESCAN00011926 problem with far and near pointer in precopy solved
                        Fz      ESCAN00012207 Improved MISRA
                        Fz      ESCAN00012960 Description changed for IlNwmIsActiveVN. 
                        Fz      ESCAN00013160 Support to read and write the current context of the NM
                        Fz      ESCAN00014323 Version define changed according to Vector rule
                        Jrw     ESCAN00012834 Handler does not enter sleep mode
                        Jrw     ESCAN00013929 Transmission not possible when VN activation coincides with HLVW
                        Jrw     ESCAN00014709 Compiler warning with certain compiler option removed
                        Jrw     ESCAN00014844 Application messages or VNMFs could be sent without a preceeding HLVW
                        Jrw     ESCAN00014887 COMM_ENABLE timer could expire too early for 8-bit micros
                        Fz      ESCAN00014394 Assertion reports error NMERR_VNTIMER_INCONSISTENT wrongly
  3.24      2006-01-18  Fz      ESCAN00014962 Multiple compiler errors in different configurations.
  3.25      2006-03-14  Fz      ESCAN00015592 Timeout recovery strategy for HLVW does not work like expected
  3.26      2006-05-10  Fz      ESCAN00016213 Allow redefines to kNmNumberOfFailedWakeup
  3.27      2006-06-26  Fz      ESCAN00016353 Compile error nmNrOfFailedWakeup in configurations with initially
                                              active VNs but no activator or remoted VNs
  3.28      2006-09-28  Fz      ESCAN00006412 Comments for nmVnState[] corrected 
                        Fz      ESCAN00017297 cast added for assignment of NmCfg_HighSpeed_Cnt(channel) to 
                                              nmTxConfirmCnt to avoid compiler warning
                        Fz      ESCAN00017292 Multichannel configurations: compile error if assertions are enabled and
                                              internal NM provided assertion function is used.
  3.29      2007-01-25  Fz      ESCAN00018323 Function IlNwmGetActiveListVN does not work like expected
                        Fz      ESCAN00019499 Sleep wake able high speed transceiver put into sleep mode to early 
                        Fz      ESCAN00019706 Support memory mapping in gmlcal.c / gmlcal.h
                        Fz      ESCAN00020070 Compiler error because of not defined define used in code 
                        Fz      ESCAN00020187 Unused variables warnings removed
                        Fz      ESCAN00019875 Assertion may be called when a msg is RX during transition to sleep mode
  3.30      2007-04-18  Fz      ESCAN00020333 No changes (see gmnmdef.h)
  3.30.01   2007-06-04  vismas  ESCAN00020903 Synchronized encapsulation for nmTxConfirmCnt to avoid compiler warnings
                                ESCAN00021023 Added cast to avoid compiler warning
  4.00.00   2007-07-26  vismas  ESCAN00021281 removed compiler warning
                                ESCAN00022355 added check for some API to be not executed in BusOff
                                ESCAN00023021 added handling for rescan of VNs when LowVoltage mode is left
                                ESCAN00023087 added check to prohibit API execution of IlNwmReturnToNormal() in sleep
                                ESCAN00023446 added check for inactive activator VNs in IlNwmDeactivateVN.
                                ------------- adapted for GENy, rework of document structure, rework of comments
                                ------------- adapted to current coding template
                                ESCAN00023509 modified setting of NmVnActivatorPending for diagnostic VN
                                ESCAN00024008 changed parameter check in IlNwmActivateVN and IlNwmDeactivateVN
  4.00.01   2008-02-13  vismas  ESCAN00024303 added code to let I-VNMF be send under certain condition
                                ESCAN00024378 added reset of nmVNMFInitRequest upon Tx timeout
                                ------------- optimization of preprocessor usage
                                ------------- corrected typing mistakes
                                ESCAN00025934 adapted for usage with TMS320
                                ------------- adapted PRQA analysis comments
  4.00.02   2008-08-12  Jrw     ESCAN00029103 IlNwmNormalCommHalted, IlNwmReturnToNormalMode do not work after busoff
  4.00.03   2008-10-17  vismas  ESCAN00029370 changed error handling in IlNwmActivateVN()
                                ESCAN00030073 adapted handling of CanInit()
                                ESCAN00030131 encapsulated unused variable in NmPreTransmit
                                ESCAN00030738 adapted code to satisfy some specific pre-processors
  4.00.04   2009-07-08  vismas  ESCAN00036068 removed wrong preprocessor distinction
  4.00.05   2009-07-09  vismas  ESCAN00036294 removed wrong preprocessor distinction
  4.00.06   2009-10-26  vismas  ESCAN00038021 added code to switch transceiver to normal mode after inconsistent state
  4.00.07   2009-12-22  vismas  ESCAN00039287 no changes in this file
            2010-03-04  vismas  ESCAN00038215 corrected handling for reinit of VN upon multi VNMF reception
            2010-03-04  vismas  ESCAN00041336 no changes in this file
  4.01.00   2010-07-15  vismas  ESCAN00043175 added feature to cancel I-VNMF if another I-VNMF has already been received
            2010-07-15  vismas  ESCAN00043663 adapted code to avoid compiler warning for unused variable
**********************************************************************************************************************/

#define V_NM_GMLAN_GM_SOURCE

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#include "gmnmdef.h"

#if defined ( NM_ENABLE_ASSERTIONS )
/* lint -e661
  2007-11-13, vismas: 
  When assertions are active, PClint reports a variety of possible out-of-bounds.
  This warning is suppressed to focus on the relevant warnings. */
#endif

/**********************************************************************************************************************
  Version check
**********************************************************************************************************************/
/*--- check version of static files ---------------------------------------------------------------------------------*/
#if ( NM_GMLAN_GM_VERSION != 0x0401 )
  #error "Nm_Gmlan_Gm: Header and Source file are inconsistent (version)!"
#endif
#if ( NM_GMLAN_GM_RELEASE_VERSION != 0x00 )
  #error "Nm_Gmlan_Gm: Header and Source file are inconsistent (release version)!"
#endif

/*--- check version of configuration tool / generated files ---------------------------------------------------------*/
#if defined ( VGEN_GENY )
#endif

#if defined ( NM_GMLAN_GMDLL_VERSION )
  #if ( NM_GMLAN_GMDLL_VERSION < 0x0100u )
    #error  "Nm_Gmlan_Gm: This code requires a newer version of GENy DLL Nm_Gmlan_Gm.dll."
  #endif
#else
  #error "Nm_Gmlan_Gm: NM_GMLAN_GMDLL_VERSION is not defined."
#endif

/**********************************************************************************************************************
  ORGANI check
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local configuration
**********************************************************************************************************************/
/* re-mapping of GMLAN names if IVLAN is also used in the same system (IVLAN-GMLAN gateway) */
#if defined ( NM_ENABLE_MULTIPLE_NM ) 
  #if defined ( NM_ENABLE_INDEXED_NM )
    #define NmConfirmation                      GMLAN_NmConfirmation
    #define NmCanWakeUp                         GMLAN_NmCanWakeUp
    #define NmCanError                          GMLAN_NmCanError
    #define NmPreTransmit                       GMLAN_NmPreTransmit
    #define NmInit                              GMLAN_NmInit
    #define NmPrecopy                           GMLAN_NmPrecopy
  #endif
#endif

/**********************************************************************************************************************
  Local data types and structures
**********************************************************************************************************************/
/*
 * Name:    tNmVnTimer
 * Used by: 
 */
#if defined ( NM_ENABLE_INDEXED_NM )
typedef vuint16 tNmVnTimer;
#else
  #if ( NmCfg_VnTimer_Cnt(0) > 255 ) /* ESCAN00030738 */
typedef vuint16 tNmVnTimer;
  #else
typedef vuint8 tNmVnTimer; 
  #endif
#endif

#if defined( NM_ENABLE_VN_ACTIVATOR ) || \
    defined( NM_ENABLE_VN_REMOTED )
/*
 * Name:    tNmWakeupCnt
 * Used by: 
 */
  #if defined ( NM_ENABLE_INDEXED_NM )
typedef vuint16 tNmWakeupCnt;
  #else
    #if ( NmCfg_LastWakeup_Cnt(0) > 255 ) /* ESCAN00030738 */
typedef vuint16 tNmWakeupCnt;
    #else
typedef vuint8 tNmWakeupCnt;
    #endif
  #endif
#endif

/**********************************************************************************************************************
  Local data defines
**********************************************************************************************************************/
/*
 * Description: Bit coded status of VN
 *              These bits are for internal use only and are not returned by the function IlNwmIsActiveVN()
 */
#define kNmVnRemoteInit                         0x01u  /* indicates Rx of an I-VNMF for a VN */
#define kNmVnRestartTimer                       0x20u  /* requests restart of timer */
#define kNmVnRemotedPending                     0x40u  /* VN must be activated due to received VNMF */
#define kNmVNMFVnInitialize                     kNmVnRemoteInit

/*
 * Description: Bit coded status of VN
 *              Parameter for function, that activates InitActive VNs
 */
#define kNmEnableRx                             0x01
#define kNmEnableTx                             0x02

/*
 * Description: kNmTrue and kNmFalse
 */
#define kNmFalse                                0
#define kNmTrue                                 1

/**********************************************************************************************************************
  Local macro defines
**********************************************************************************************************************/
/*
 * Description: Helper macro to access channel-specific variables
 *              Access is optimized to non-array in single-channel systems.
 */
#if defined ( NM_ENABLE_INDEXED_NM )
  #define NMVAR(var)                            ((var)[channel])  /* PRQA S 3453 */ /* MD_NmGmlanGm_3453 */
#else
  #define NMVAR(var)                            (var)             /* PRQA S 3453 */ /* MD_NmGmlanGm_3453 */
#endif

/* access to NM state (nmState) */
#define nmState1                                NMVAR(nmState).c[0]
#define nmState2                                NMVAR(nmState).c[1]
#define nmState3                                NMVAR(nmState).c[2]
#define nmState4                                NMVAR(nmState).c[3]

/* external status flags */
#define nmLowVoltageMode                        NMVAR(nmState).b.b_LVModeActive
#define nmNmActive                              NMVAR(nmState).b.b_NMActive
#define nmBusOff                                NMVAR(nmState).b.b_BusOffOccured
#define nmSleepModePending                      NMVAR(nmState).b.b_SleepModePending
#define nmSleepMode                             NMVAR(nmState).b.b_SleepModeEntered
#define nmNoComm                                NMVAR(nmState).b.b_NoCommunication
#define nmHighSpeedMode                         NMVAR(nmState).b.b_HighSpeedMode
#define nmNormalCommHalted                      NMVAR(nmState).b.b_NormalCommHalted
/* internal status flags */
#define nmVnInhibition                          NMVAR(nmState).b.b_nmVnInhibit
#define nmVnActive                              NMVAR(nmState).b.b_VnActive
#define nmInternalHighSpeedMode                 NMVAR(nmState).b.b_InternalHighSpeedMode
#define nmInternalNmActive                      NMVAR(nmState).b.b_InternalNMActive
#define nmInternalSleepMode                     NMVAR(nmState).b.b_InternalSleepModeEntered
#define nmInternalSleepMode_volatile            (*(volatile nmStateType*)&NMVAR(nmState)).b.b_InternalSleepModeEntered
#define nmInternalVnActive                      NMVAR(nmState).b.b_InternalVnActive
#define nmInitVnRx                              NMVAR(nmState).b.b_ActivateInitRxVN
#define nmInitVnTx                              NMVAR(nmState).b.b_ActivateInitTxVN
#define nmRescanVn                              NMVAR(nmState).b.b_RescanVnState
#define nmHLVWRxFlag                            NMVAR(nmState).b.b_HVMsgReceived
#define nmHLVWTxRequest                         NMVAR(nmState).b.b_HVMsgSendRequest
#define nmHLVWTxTransmitted                     NMVAR(nmState).b.b_HVMsgSent
#define nmHLVWTxActive                          NMVAR(nmState).b.b_HVMsgActive
#define nmHLVWTxConfirmed                       NMVAR(nmState).b.b_HVMsgTxConfirmed
#define nmHLVWTxFailed                          NMVAR(nmState).b.b_HVMsgSendFailed
#define nmVNMFInitRequest                       NMVAR(nmState).b.b_SendVnInitRequest
#define nmVNMFTxConfirmed                       NMVAR(nmState).b.b_VNMF_TxConfirmed
#define nmVNMFTxRequest                         NMVAR(nmState).b.b_SendMessFlag

/*
 * Description: Function macro that converts an internal VN handle to an application-known VN handle (channel-specific)
 */
#if defined ( NM_ENABLE_INDEXED_NM )
  #define NM_CVT_NMVNPARA_TO_APPLVNPARA(vnHndl)     (vuint8)((vuint8)(vnHndl)-NmVnStartIndex[channel]) /* PRQA S 3453 */  /* MD_NmGmlanGm_3453 */
#else
  #define NM_CVT_NMVNPARA_TO_APPLVNPARA(vnHndl)     ((vuint8)(vnHndl)) /* PRQA S 3453 */  /* MD_NmGmlanGm_3453 */
#endif

/*
 * Description: Function macros used for assertion handling
 */
#if defined( NM_ENABLE_ASSERTIONS )
  #define NmAssert(cond, err)                   if((cond)==0) { NM_ASSERT_FCT(err); } /* PRQA S 3412 */  /* MD_NmGmlanGm_3412 */
  #define NmAssertDirect(err)                   NM_ASSERT_FCT(err)
#else
  #define NmAssert(cond, err)                   
  #define NmAssertDirect(err)                   
#endif

/**********************************************************************************************************************
  Global data definitions (ROM)
**********************************************************************************************************************/

/*
 * Name:        kGmlanNm...Version
 * Description: contains the version data of the component
 * Values:      BCD-coded
 */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kGmlanNmMainVersion    = (vuint8)(NM_GMLAN_GM_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kGmlanNmSubVersion     = (vuint8)(NM_GMLAN_GM_VERSION & 0xFF);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kGmlanNmReleaseVersion = (vuint8)(NM_GMLAN_GM_RELEASE_VERSION);

/*
 * Name:        kGmlan...Version
 * Description: contains the version data of the GMLAN handler
 * Values:      BCD-coded
 */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kGmlanMainVersion    =  (vuint8)(GMLAN_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kGmlanSubVersion     =  (vuint8)(GMLAN_VERSION & 0xFF);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kGmlanReleaseVersion =  (vuint8)(0x00);

/*
 * Name:        kDataDict...Version
 * Description: contains the version data of the database
 * Values:      BCD-coded
 */
#if defined( VERSIONNUMBER )
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kDataDictMainVersion  =  (vuint8)(VERSIONNUMBER >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kDataDictSubVersion   =  (vuint8)(VERSIONNUMBER & 0xFF);
#else
  #if defined ( VERSIONYEAR )
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kDataDictMainVersion  =  (vuint8)VERSIONYEAR;
  #endif
  #if defined ( VERSIONWEEK )
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kDataDictSubVersion   =  (vuint8)VERSIONWEEK;
  #endif
#endif


/**********************************************************************************************************************
  Global data definitions (RAM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local data definitions (ROM)
**********************************************************************************************************************/

/**********************************************************************************************************************
  Local data definitions (RAM)
**********************************************************************************************************************/
/*-----------------------------------------------------------------------------
 * NM handling
 *----------------------------------------------------------------------------*/
#if defined( NM_ENABLE_VN_ACTIVATOR ) || \
    defined( NM_ENABLE_VN_REMOTED )
/*
 * Name:        nmWakeupCnt
 * Description: This is a time counter for Rx of HLVW message.
 *              The timer is restarted each time a HLVW message (100h) is received.
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1 tNmWakeupCnt V_MEMRAM2 nmWakeupCnt[kNmNumberOfChannels];
#endif

#if defined( NM_ENABLE_VN_ACTIVATOR ) || \
    defined( NM_ENABLE_VN_REMOTED )
/*
 * Name:        nmNrOfFailedWakeup
 * Description: 
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 nmNrOfFailedWakeup[kNmNumberOfChannels];
#endif

#if defined( NM_ENABLE_VN_ACTIVATOR ) || \
    defined( NM_ENABLE_VN_REMOTED )  || \
    defined( NM_ENABLE_HIGHSPEED_MODE )
/*
 * Name:        nmTxConfirmCnt
 * Description: This is a time counter for VNMF confirmation timeout.
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 nmTxConfirmCnt[kNmNumberOfChannels];
#endif

/*
 * Name:        nmBusOffRecoveryTimeCnt
 * Description: This is a timer for restart of CAN after multiple BusOffs.
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 nmBusOffRecoveryTimeCnt[kNmNumberOfChannels];

/*
 * Name:        nmSendInitVnmfCnt
 * Description: This is a timer for delaying I-VNMF
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2  nmSendInitVnmfCnt[kNmNumberOfChannels];

#if defined( NM_ENABLE_VN_ACTIVATOR ) || \
    defined( NM_ENABLE_VN_REMOTED )
/*
 * Name:        nmSendContVnmfCnt
 * Description: This is a timer for C-VNMF
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 nmSendContVnmfCnt[kNmNumberOfChannels];
#endif

/*
 * Name:        nmAction
 * Description: 
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1 nmActionType V_MEMRAM2 nmAction[kNmNumberOfChannels];

/*
 * Name:        nmGenericTimer
 * Description: This is a general purpose timer used for different states.
 *              It is overlayed to save RAM. 
 *              The timer has different meanings depending on the NM state.
 *              It is used as:
 *              - COMM_ENABLE_TIMER        during NM_COMM_ENABLE
 *              - HighSpeed recovery time  during NM_LEAVE_HIGHSPEED_MODE.
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1 tCommEnableTimer V_MEMRAM2 nmGenericTimer[kNmNumberOfChannels];


/*-----------------------------------------------------------------------------
 * VN handling
 *----------------------------------------------------------------------------*/
/*
 * Name:        nmVnTimer
 * Description: 
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1 tNmVnTimer V_MEMRAM2 nmVnTimer[kNmNumberOfVirtualNets];

/*
 * Name:        nmVnState
 * Description: This variable holds the bit-coded status of the VNs
 * Values:      76543210
 *              |||||||+--- VN Remotely activation requested as Initial (set)/Continued (cleared)
 *              |||||||     Important: Same position as in Byte 0 of VNMF!!!! (it's a copy)
 *              ||||||+---- VN Active
 *              |||||+----- VN Activator. Send out VNMF for this VN.
 *              ||||+------ VN is locally active
 *              |||+------- VN Indicates Receive-enabled
 *              ||+-------- VN Request for timer restart
 *              |+--------- VN must be activated due to received VNMF
 *              +---------- VN activation pending
 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 nmVnState[kNmNumberOfVirtualNets];
#if defined( NM_ENABLE_VN_REMOTED ) /* ESCAN00043663 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 nmVnStateInhibit[kNmNumberOfVirtualNets];
#endif

#if defined( NM_ENABLE_INHIBIT_VN_HIGHLOAD ) && \
    defined( NM_ENABLE_VN_ACTIVATOR )
/*
 * Name:        nmVnQueued
 * Description: 
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 nmVnQueued[kNmNumberOfVnBytes];
#endif

#if defined( NM_ENABLE_VN_INITACTIVE )
/*
 * Name:        nmInitVnCnt
 * Description: This is a time counter for initially active VNs.
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 nmInitVnCnt[kNmNumberOfChannels];
#endif

/**********************************************************************************************************************
  Local data definitions (RAM, near)
**********************************************************************************************************************/
/*--- NEAR MEMORY ---*/

#if defined( NM_ENABLE_VN_ACTIVATOR) || \
    defined( NM_ENABLE_VN_REMOTED )
/*
 * Name:        nmSendInit
 * Description: I-VNMF buffer
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1_NEAR vuint8 V_MEMRAM2_NEAR nmSendInit[kNmNumberOfVnBytes];
#endif

#if defined( NM_ENABLE_VN_ACTIVATOR )
/*
 * Name:        nmSendContinue
 * Description: C-VNMF buffer
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1_NEAR vuint8 V_MEMRAM2_NEAR nmSendContinue[kNmNumberOfVnBytes];
#endif

/*
 * Name:        nmState
 * Description: internal status
 * Values:      
 */
#if defined( NM_ENABLE_INDEXED_NM )
V_MEMRAM0 static V_MEMRAM1_NEAR nmStateType V_MEMRAM2_NEAR nmState[kNmNumberOfChannels]; /* PRQA S 759 */ /* MD_NmGmlanGm_759 */
#else
V_MEMRAM0 static V_MEMRAM1_NEAR nmStateType V_MEMRAM2_NEAR nmState; /* PRQA S 759 */ /* MD_NmGmlanGm_759 */
#endif

/*
 * Name:        nmSendMess
 * Description: Declare buffer for the VNMF
 * Values:      
 */
V_MEMRAM0 V_MEMRAM1_NEAR nmMessType V_MEMRAM2_NEAR nmSendMess; /* PRQA S 759 */ /* MD_NmGmlanGm_759 */

#if defined( NM_ENABLE_VN_ACTIVATOR ) || \
    defined( NM_ENABLE_VN_REMOTED)
/*
 * Name:        nmLastVnmfType
 * Description: 
 * Values:      
 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 nmLastVnmfType[kNmNumberOfChannels];
#endif


/**********************************************************************************************************************
  Local function prototypes
**********************************************************************************************************************/
static void NmActivateCan( NM_CHANNEL_NMTYPE_ONLY );

#if defined( NM_ENABLE_VN_ACTIVATOR ) || \
    defined( NM_ENABLE_VN_REMOTED )
static void NmDoActivationPending( NM_CHANNEL_NMTYPE_ONLY );
#endif

static void NmGotoMode( NM_CHANNEL_NMTYPE_FIRST nmActionType NewNodeState );


#if defined( NM_ENABLE_VN_ACTIVATOR ) || \
    defined( NM_ENABLE_VN_REMOTED )
static void NmSendWakeupMessage(NM_CHANNEL_NMTYPE_ONLY);
#endif

static void NmSetupInitActivation( NM_CHANNEL_NMTYPE_ONLY );
static void NmStartupReset( NM_CHANNEL_NMTYPE_ONLY );
static void NmStateTask( NM_CHANNEL_NMTYPE_ONLY );

#if defined( NM_ENABLE_VN_INITACTIVE )
static void NmVnInitWakeup( NM_CHANNEL_NMTYPE_FIRST vuint8 direction );
#endif

static void NmVnTimerTask( NM_CHANNEL_NMTYPE_ONLY );

#if defined( NM_ENABLE_VN_ACTIVATOR ) && \
    defined( NM_ENABLE_RECOVER_VN_AFTER_BUSOFF )
static void NmVnmfRecoveryFromBusoff(NM_CHANNEL_NMTYPE_ONLY);
#endif

/**********************************************************************************************************************
  Global function definitions
**********************************************************************************************************************/
/**********************************************************************************************************************
  Name:         IlNwmInit
  Parameter:    channel
  Return value: ---
  Description:  This is the initialization function of the NM.
                It resets all variables.
**********************************************************************************************************************/
void IlNwmInit( NM_CHANNEL_NMTYPE_ONLY )
{
  vsint8 vnHndl;
  #if defined( NM_ENABLE_VN_ACTIVATOR) || \
      defined( NM_ENABLE_VN_REMOTED )
  vsint8 vnByte;
  #endif

  /* initialize node management */
  NmInit( NM_CHANNEL_NMPARA_ONLY );

  (void)IlSetOwnNodeAddress( NM_CHANNEL_NMPARA_FIRST NmCfg_SourceId(channel) );

  /* reset all state bits */
  nmState1 = 0x00;
  nmState2 = 0x00;
  nmState3 = 0x00;
  nmState4 = 0x00;

  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )
  nmSendContVnmfCnt[NM_CHANNEL_IDX] = 0;
  #endif
  nmSendInitVnmfCnt[NM_CHANNEL_IDX] = 0;
  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )  || \
      defined ( NM_ENABLE_HIGHSPEED_MODE )
  nmTxConfirmCnt[NM_CHANNEL_IDX] = 0;
  #endif

  /* iterate over all VNs */
  for( vnHndl=(vsint8)NmCfg_VN_StopIndex(channel); vnHndl>=(vsint8)NmCfg_VN_StartIndex(channel); vnHndl-- )
  {
    nmVnTimer[vnHndl] = 0;
    nmVnState[vnHndl] = NmVnNone;
  #if defined( NM_ENABLE_VN_REMOTED ) /* ESCAN00043663 */
    nmVnStateInhibit[vnHndl] = 0;
  #endif
  }

  #if defined( NM_ENABLE_VN_ACTIVATOR) || \
      defined( NM_ENABLE_VN_REMOTED )
  for( vnByte=(vsint8)NmCfg_VnByte_StopIndex(channel); vnByte>=(vsint8)NmCfg_VnByte_StartIndex(channel); vnByte-- )
  {
    nmSendInit[vnByte] = 0;
    #if defined( NM_ENABLE_VN_ACTIVATOR)
    nmSendContinue[vnByte] = 0;
    #endif
    #if defined( NM_ENABLE_INHIBIT_VN_HIGHLOAD) && \
        defined( NM_ENABLE_VN_ACTIVATOR )
    nmVnQueued[vnByte] = 0;
    #endif
  }
  #endif

  nmAction[NM_CHANNEL_IDX] = NO_ACTION;

  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )
  nmWakeupCnt[NM_CHANNEL_IDX]         = 0;
  nmNrOfFailedWakeup[NM_CHANNEL_IDX]  = 0;
  #endif

  /* Code: NmGotoMode(NM_COMM_ENABLED) must be called before InitVNs are activated. 
   *       This is because starting the IL re-inits the message structs */
  NmGotoMode(NM_CHANNEL_NMPARA_FIRST  NM_COMM_ENABLE);
  #if defined( NM_ENABLE_LOWVOLTAGE_MODE )
  NmGotoMode(NM_CHANNEL_NMPARA_FIRST  NM_ENTER_LOW_VOLTAGE_TOLERANT_MODE);
  #endif
  nmGenericTimer[NM_CHANNEL_IDX] = NmCfg_WakeupSleep_Cnt(channel);

  /* start initially active VNs */
  NmSetupInitActivation(NM_CHANNEL_NMPARA_ONLY);
}

/**********************************************************************************************************************
  Name:         IlNwmTask
  Parameter:    channel
  Return value: ---
  Description:  Cyclic function of NM to handle timer and NM functionality.
**********************************************************************************************************************/
void IlNwmTask( NM_CHANNEL_NMTYPE_ONLY )
{
  /* abort task execution if NM is in sleep mode */
  if( nmInternalSleepMode==kNmTrue )
  {
    return;
  }

  /* ESCAN00038021: check inconsistent state and resolve it */
  if ((nmHLVWTxTransmitted == kNmFalse) && (nmHLVWTxActive == kNmTrue) )
  {
    ApplTrcvrNormalMode(NM_CHANNEL_APPLPARA_ONLY);
    nmHLVWTxActive = kNmFalse;
  }

  /* external wakeup request in sleep mode must change the Node state into NM_COMM_ENABLE */
  if( nmSleepMode==kNmTrue )
  {
    NmGotoMode( NM_CHANNEL_NMPARA_FIRST NM_COMM_ENABLE );
  }

  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED  ) || \
      defined( NM_ENABLE_VN_INITACTIVE  )
  if( nmState4!=0 )
  {
    CanInterruptDisable();

    /* ESCAN00020903 */
    #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
        defined( NM_ENABLE_VN_REMOTED )
    /* check confirmation of VNMF */
    if( nmVNMFTxConfirmed != kNmFalse )
    {
      nmVNMFTxConfirmed = kNmFalse;
      nmTxConfirmCnt[NM_CHANNEL_IDX] = 0; /* reset Tx confirmation timeout counter */
    }
    #endif

    /* check confirmation of HLVW  */
    if( nmHLVWTxConfirmed != kNmFalse )
    {
    #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
        defined( NM_ENABLE_VN_REMOTED  )
      nmNrOfFailedWakeup[NM_CHANNEL_IDX] = 0; /* ESCAN00015592: Clear fail counter for next retry */
    #endif
      nmHLVWTxConfirmed = kNmFalse;
      nmGenericTimer[NM_CHANNEL_IDX] = NmCfg_WakeupSleep_Cnt(channel);
    }

    CanInterruptRestore();
  }

  /* check indication of HLVW */
  if( nmHLVWRxFlag == kNmTrue )
  {
    CanInterruptDisable();
    nmHLVWRxFlag = kNmFalse;
    /* Restart COMM_ENABLE_TIMER in COMM_ENABLE mode */
    nmGenericTimer[NM_CHANNEL_IDX] = NmCfg_WakeupSleep_Cnt(channel);
    if( nmNoComm!=kNmFalse )
    {
    #if defined( NM_ENABLE_LOWVOLTAGE_MODE ) && \
        defined( NM_ENABLE_CANOFF_ON_LOWVOLTAGE_MODE )
      if( (nmAction[NM_CHANNEL_IDX]!=NM_BUSOFF) && (nmLowVoltageMode != kNmTrue) )
    #else
      if( (nmAction[NM_CHANNEL_IDX]!=NM_BUSOFF) )
    #endif
      {
        nmNoComm = kNmFalse;
        CanOnline(NM_CHANNEL_CANPARA_ONLY);
      }
    }
    CanInterruptRestore();

    #if defined( NM_ENABLE_WAKEUP_RECEIVED_FCT )
    /* inform application about Rx of HLVW */
    ApplNwm100MsgRecv(NM_CHANNEL_APPLPARA_ONLY);
    #endif

    #if defined( NM_ENABLE_HIGHSPEED_MODE )
    if( (nmNormalCommHalted==kNmFalse) && (nmHighSpeedMode==kNmFalse) )
    #else
    if( (nmNormalCommHalted==kNmFalse) )
    #endif
    {
      /* Note: do not start Init-VN in NormalCommHalted mode */
      NmSetupInitActivation(NM_CHANNEL_NMPARA_ONLY);
    }
  }
  #endif

  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )
  if( nmHLVWTxRequest!=kNmFalse )
  {
    NmSendWakeupMessage(NM_CHANNEL_NMPARA_ONLY);
  }
  #endif

  #if defined( NM_ENABLE_VN_INITACTIVE )
  /*-- Flag indicates the request to a VN initialization. -------------------*/
  if( nmInitVnRx!=kNmFalse )
  {
    /*-- Request activation of initial active VN's -------------------------*/
    NmVnInitWakeup( NM_CHANNEL_NMPARA_FIRST kNmEnableRx );
  }
  if( nmInitVnTx!=kNmFalse )
  {
    /*-- Count down the delay counter for Initial active VN's. -------------*/
    if( nmInitVnCnt[NM_CHANNEL_IDX]!=0 )
    {
      nmInitVnCnt[NM_CHANNEL_IDX]--;
    }
    if (nmInitVnCnt[NM_CHANNEL_IDX]==0)
    {
      /*-- If counter is 0, the Initially-Active VN('s) could be activated. --*/
      NmVnInitWakeup( NM_CHANNEL_NMPARA_FIRST kNmEnableTx );
    }
  }
  #endif

  /*--- StateTask handles the VN-status changes requested from CAN or Appl. -*/
  NmStateTask(NM_CHANNEL_NMPARA_ONLY);

  /*-------------------------------------------------------------------------*/
  CanInterruptDisable();

  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )
  /* handle wakeup dis-allowance time counter */
  if( nmWakeupCnt[NM_CHANNEL_IDX]!=0 )
  {
    nmWakeupCnt[NM_CHANNEL_IDX]--;
  }
  #endif

  /* handle COMM_ENABLE_TIMER */
  #if defined( NM_ENABLE_LOWVOLTAGE_MODE )
  /* Note: COMM_ENABLE_TIMER does not have to be decremented in LowVoltage mode */
  if( nmLowVoltageMode != kNmTrue )
  #endif
  {
    if (nmGenericTimer[NM_CHANNEL_IDX]!=0)
    {
      nmGenericTimer[NM_CHANNEL_IDX]--;
    }
  }

  /* handle time counter for BusOff recovery time */
  if( nmBusOffRecoveryTimeCnt[NM_CHANNEL_IDX]!=0 )
  {
    nmBusOffRecoveryTimeCnt[NM_CHANNEL_IDX]--;
  }
  CanInterruptRestore();


  /*--------------------------------------------------------------------------
   * FSM for NM states
   *--------------------------------------------------------------------------*/
  switch( nmAction[NM_CHANNEL_IDX] )
  {
    /*----------------------------------------------------------------------------*/
    case NM_COMM_ENABLE:
    /*----------------------------------------------------------------------------*/
      if ((nmNmActive==kNmFalse) && (nmVnActive==kNmFalse)    )
      {
        CanInterruptDisable();
        /* Goto sleep mode not exact after 8 seconds. This is done because of CanInit. This     */
        /* function will be called during transition into sleep mode. This function will delete  */
        /* all pending receive request. So it is possible, that an HLVW message will be deleted */
        /* by it.                                                                               */
        if (nmGenericTimer[NM_CHANNEL_IDX] == NmCfg_SleepTransition_Cnt(channel))
        {
          /* if the application confirms sleep goto sleep */
  #if defined ( NM_ENABLE_SLEEPCONFIRMATION_FCT )
          if ( ApplNwmSleepConfirmation(NM_CHANNEL_APPLPARA_ONLY)==NmSleepOk)
  #endif
          {
            nmNoComm = kNmTrue;
            CanOffline(NM_CHANNEL_CANPARA_ONLY);

            /*-- Before entering sleepmode, reset CAN to delete non-successful Tx */
  #if defined ( NM_ENABLE_INDEXED_NM )
            CanResetBusSleep(channel, NmCfg_InitObj_Std(channel));
  #else
            CanResetBusSleep(NmCfg_InitObj_Std(channel));
  #endif
          }
  #if defined ( NM_ENABLE_SLEEPCONFIRMATION_FCT )
          else
          {
            /* restart counter for another 8s */
            nmGenericTimer[NM_CHANNEL_IDX] = NmCfg_SleepDenied_Cnt(channel);
          }
  #endif
        }

        /*--- Shutdown time expired. Goto Sleep state -----------------*/
        if (nmGenericTimer[NM_CHANNEL_IDX]==0)
        {
          NmGotoMode(NM_CHANNEL_NMPARA_FIRST  NM_COMM_OFF);
        }

        CanInterruptRestore();

        if (nmSendInitVnmfCnt[NM_CHANNEL_IDX]!=0 )
        {
          nmSendInitVnmfCnt[NM_CHANNEL_IDX]--;
        }
        /*--- IMPORTANT: Finish here when no VN is active -------------------------*/
        break; /* PRQA S 3333 */  /* MD_NmGmlanGm_3333 */
      }
      else
      {
        NmGotoMode(NM_CHANNEL_NMPARA_FIRST  NM_COMM_ACTIVE);
      }
      /* Code: no break here: continue with case NM_COMM_ACTIVE */
    /*----------------------------------------------------------------------------*/
    case NM_COMM_ACTIVE: /* PRQA S 2003 */ /* MD_NmGmlanGm_2003 */
    /*----------------------------------------------------------------------------*/
  #if defined( NM_ENABLE_LOWVOLTAGE_MODE ) && \
      defined( NM_ENABLE_CANOFF_ON_LOWVOLTAGE_MODE )
      /* In case of being in LowVoltage mode AND transmission request is not
      * allowed there, Active-mode can be skipped.
      * This prevents from incorrect states during LowVoltage mode (especially timeout of VNMF transmission. */
      if( nmLowVoltageMode == kNmTrue )
      {
        break; /* PRQA S 3333 */  /* MD_NmGmlanGm_3333 */
      }
  #endif

      /*-- counting the active VN-timer --------------------------------*/
      NmVnTimerTask(NM_CHANNEL_NMPARA_ONLY);

  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED  )

      if( nmTxConfirmCnt[NM_CHANNEL_IDX]!=0 )
      {
        nmTxConfirmCnt[NM_CHANNEL_IDX]--;
        if( nmTxConfirmCnt[NM_CHANNEL_IDX]==0 )
        {
    #if defined( NM_ENABLE_VNMF_CONFIRMATION_TIMEOUT_FCT )
          ApplNwmVnmfConfirmationTimeout(NM_CHANNEL_APPLPARA_ONLY);
    #endif

          /* ESCAN00024378 */
          nmVNMFInitRequest = kNmFalse;

          CanInterruptDisable();
          /*-- Process VNMF data with activation request  ------------*/
          /*-- to simulate the confirmation --------------------------*/
          NmDoActivationPending(NM_CHANNEL_NMPARA_ONLY);
          CanInterruptRestore();
        }
      }
      /* Changed since V2.30: No further VNMF transmission request when previous transmission is not confirmed */
      else
      {
        if(nmSendContVnmfCnt[NM_CHANNEL_IDX]!=0)
        {
          nmSendContVnmfCnt[NM_CHANNEL_IDX]--;
        }
        if(nmSendInitVnmfCnt[NM_CHANNEL_IDX]!=0 )
        {
          nmSendInitVnmfCnt[NM_CHANNEL_IDX]--;
        }

        /*- Do not send Init-VNMF while waiting for HLVW confirmation -*/
        if (   (nmHLVWTxTransmitted==kNmFalse) 
            && (nmVNMFInitRequest!=kNmFalse) 
            && (nmSendInitVnmfCnt[NM_CHANNEL_IDX]==0) )
        {
          /* This if-clause reflects Section 5.5.3.1.1 of */
          /* GMLAN Strategy Spec. V1.5, Requirement 4     */
          /* Usually already handled in other code parts. */
          /* Just to make sure.                           */
          if (nmWakeupCnt[NM_CHANNEL_IDX]!=0)
          {
            nmVNMFTxRequest = kNmTrue;

            /*-----------------------------------------------------
            *-- Start timer, to check if VNMF transmission request
            *-- can be done within certain time. Otherwise
            *-- a CAN communication problem is encountered!!
            *-- NOTE: That as long as this timer is running
            *--       no further VNMF transmission can be requested!!!
            *-- Solves ESCAN00000311
            *-----------------------------------------------------*/
            nmTxConfirmCnt[NM_CHANNEL_IDX] = (vuint8)NmCfg_VnmfConfirm_Cnt(channel);

            /* ESCAN00024378 */
            /*-- and restart timer between successive VNMF --*/
            nmSendContVnmfCnt[NM_CHANNEL_IDX] = NmCfg_VnmfPeriodicRate_Cnt(channel);
          }
          else
          {
            /* Setup first to ensure that Init-VNMF not transmitted when CanTransmit for wakeup message fails */
            nmSendInitVnmfCnt[NM_CHANNEL_IDX] = (vuint8) NmCfg_VnmfStartSend_Cnt(channel);
            NmSendWakeupMessage(NM_CHANNEL_NMPARA_ONLY);
          }
        }
    #if defined( NM_ENABLE_VN_ACTIVATOR )
        /*- If Activator VN is active and VNMF sendout-time expired, send.*/
        else
        {
          if( (nmVnActive!=kNmFalse) && (nmSendContVnmfCnt[NM_CHANNEL_IDX]==0) )
          {
            /*-- Set the VNMF send-request flag --*/
            nmVNMFTxRequest = kNmTrue;

            /*-----------------------------------------------------
            *-- Start timer, to check if VNMF transmission request
            *-- can be done within certain time. Otherwise
            *-- a CAN communication problem is encountered!!
            *-- NOTE: That as long as this timer is running
            *--       no further VNMF transmission can be requested!!!
            *-- Solves ESCAN00000311
            *-----------------------------------------------------*/
            nmTxConfirmCnt[NM_CHANNEL_IDX] = (vuint8)NmCfg_VnmfConfirm_Cnt(channel);

            /*-- and restart timer between successive VNMF --*/
            nmSendContVnmfCnt[NM_CHANNEL_IDX] = NmCfg_VnmfPeriodicRate_Cnt(channel);
          }
        }
    #endif
      }
  #endif
      /*- Indicates, that VN's no longer active. Change node state -----*/
      if( (nmNmActive==kNmFalse) && (nmVnActive==kNmFalse) )
      {
        NmGotoMode(NM_CHANNEL_NMPARA_FIRST  NM_COMM_ENABLE);
        /* ESCAN00036068 */
        /* Section 5.5.2.1.1. nmGenericTimer:=max(nmGenericTimer, 4 sec) */
        if( nmGenericTimer[NM_CHANNEL_IDX] < NmCfg_DeactSleep_Cnt(channel) )
        {
          nmGenericTimer[NM_CHANNEL_IDX] = NmCfg_DeactSleep_Cnt(channel);
        }
      }
      break;
  #if defined( NM_ENABLE_HIGHSPEED_MODE )
    /*----------------------------------------------------------------------------*/
    case NM_HIGHSPEED_MODE:
    /*----------------------------------------------------------------------------*/
      if( nmInternalHighSpeedMode==kNmFalse )
      {
        ApplTrcvrNormalMode(NM_CHANNEL_APPLPARA_ONLY);
        CanInterruptDisable(); /* ESCAN00030073 */
        CanOffline(NM_CHANNEL_CANPARA_ONLY); /* ESCAN00030073 */
        CanInit( NM_CHANNEL_CANPARA_FIRST NmCfg_InitObj_Std(channel) );
        CanOnline(NM_CHANNEL_CANPARA_ONLY); /* ESCAN00030073 */
        CanInterruptRestore();
        nmAction[NM_CHANNEL_IDX] = NM_LEAVE_HIGHSPEED_MODE;
        nmTxConfirmCnt[NM_CHANNEL_IDX] = (vuint8)NmCfg_HighSpeed_Cnt(channel);
      }
     break;
  #endif
  #if defined( NM_ENABLE_HIGHSPEED_MODE )
    /*----------------------------------------------------------------------------*/
    case NM_LEAVE_HIGHSPEED_MODE:
    /*----------------------------------------------------------------------------*/
      /*-- Decrease state-dependent timer/counter ----------------------*/
      if( nmTxConfirmCnt[NM_CHANNEL_IDX]!=0 )
      {
        nmTxConfirmCnt[NM_CHANNEL_IDX]--;
      }
      if( nmTxConfirmCnt[NM_CHANNEL_IDX]==0 )
      {
        nmHighSpeedMode = kNmFalse;
        nmRescanVn = kNmTrue;

        NmStateTask(NM_CHANNEL_NMPARA_ONLY);

        if( (nmNmActive!=kNmFalse) || (nmVnActive!=kNmFalse) )
        {
          NmGotoMode( NM_CHANNEL_NMPARA_FIRST NM_COMM_ACTIVE );
        }
        else
        {
          NmGotoMode( NM_CHANNEL_NMPARA_FIRST NM_COMM_ENABLE );
        }
      }
      break;
  #endif
    /*----------------------------------------------------------------------------*/
    case NM_BUSOFF:
    /*----------------------------------------------------------------------------*/
      /*-- counting the active VN-timer during BusOff ------------------*/
      NmVnTimerTask(NM_CHANNEL_NMPARA_ONLY);

      if( ((nmNmActive==kNmFalse) && (nmVnActive==kNmFalse)) != 0 )
      {
        if( nmBusOff == kNmTrue )
        {
          nmBusOff = kNmFalse;
          /* ESCAN00036068 */
          /* GMW3104 - 5.5.2.1.2.2 paragraph 1 */
          /* nmGenericTimer:=max(nmGenericTimer, 4 sec) */
          if( nmGenericTimer[NM_CHANNEL_IDX] < NmCfg_DeactSleep_Cnt(channel) )
          {
            nmGenericTimer[NM_CHANNEL_IDX] = NmCfg_DeactSleep_Cnt(channel);
          }
        }
        /* GMW3104 - 5.5.2.1.2.1 paragraph 5 */
        if( nmGenericTimer[NM_CHANNEL_IDX] == 0 )
        {
          nmBusOffRecoveryTimeCnt[NM_CHANNEL_IDX] = 0;
        }
      }
      if( nmBusOffRecoveryTimeCnt[NM_CHANNEL_IDX] == 0 )
      {
  #if defined(NM_ENABLE_HIGHSPEED_MODE)
        if( nmInternalHighSpeedMode != kNmFalse )
        {
          CanInterruptDisable();
    #if defined ( NM_ENABLE_INDEXED_NM )
          CanResetBusOffEnd(channel, NmCfg_InitObj_HighSpeed(channel));
    #else
          CanResetBusOffEnd(NmCfg_InitObj_HighSpeed(channel));
    #endif
          CanInterruptRestore();
          nmHighSpeedMode = kNmTrue;
          nmAction[NM_CHANNEL_IDX] = NM_HIGHSPEED_MODE;
        }
        else
  #endif
        {
          CanInterruptDisable();
  #if defined ( NM_ENABLE_INDEXED_NM )
          CanResetBusOffEnd(channel, NmCfg_InitObj_Std(channel));
  #else
          CanResetBusOffEnd(NmCfg_InitObj_Std(channel));
  #endif
          CanInterruptRestore();

  #if defined( NM_ENABLE_HIGHSPEED_MODE )
          if( nmHighSpeedMode != kNmFalse )
          {
            nmAction[NM_CHANNEL_IDX] = NM_LEAVE_HIGHSPEED_MODE;
            nmTxConfirmCnt[NM_CHANNEL_IDX]  = (vuint8)NmCfg_HighSpeed_Cnt(channel);
            break; /* PRQA S 3333 */  /* MD_NmGmlanGm_3333 */
          }
          else
  #endif
          {
            CanInterruptDisable();
            nmRescanVn = kNmTrue;
            CanInterruptRestore();

            NmStateTask(NM_CHANNEL_NMPARA_ONLY);
            if ((nmNmActive!=kNmFalse) ||
                (nmVnActive!=kNmFalse) )
            {
              NmGotoMode(NM_CHANNEL_NMPARA_FIRST  NM_COMM_ACTIVE);
            }
            else
            {
              NmGotoMode(NM_CHANNEL_NMPARA_FIRST  NM_COMM_ENABLE);
              /* Ensures to be active for the next 8 sec.*/
              /* in case of the system missed the HLVW   */
              /* during this BusOff state.               */
              nmGenericTimer[NM_CHANNEL_IDX] = NmCfg_WakeupSleep_Cnt(channel);
            }
          }
        }
        
        /* enable CAN Tx after BusOff recovery */
  #if defined( NM_ENABLE_LOWVOLTAGE_MODE ) && \
      defined( NM_ENABLE_CANOFF_ON_LOWVOLTAGE_MODE )
        /* Don't enable communication after BusOff when in LowVoltage Mode */
        if( nmLowVoltageMode == kNmFalse )
  #endif
        {
          nmNoComm = kNmFalse;
          CanOnline(NM_CHANNEL_CANPARA_ONLY);
        }

        /* reload time counter for BusOff recovery time. */
        nmBusOffRecoveryTimeCnt[NM_CHANNEL_IDX] = NmCfg_BusOffRecovery_Cnt(channel);

  #if defined( NM_ENABLE_BUSOFF_END_FCT )
        /* inform application about end of BusOff recovery */
        ApplNwmBusoffEnd(NM_CHANNEL_APPLPARA_ONLY);
  #endif

  #if defined( NM_ENABLE_VN_ACTIVATOR) && \
      defined( NM_ENABLE_RECOVER_VN_AFTER_BUSOFF )
        /* ESCAN00014844: Recover the VNs after the BusOff recovery, since it could cause another BusOff */
        if( nmHighSpeedMode == kNmFalse )
        {
          NmVnmfRecoveryFromBusoff(NM_CHANNEL_NMPARA_ONLY);
        }
  #endif
      }
      break;
    /*----------------------------------------------------------------------------*/
    case NO_ACTION:
    case NM_COMM_HALTED:
    case NM_COMM_OFF:
    /*----------------------------------------------------------------------------*/
      /* no special action in these states */
      break;
    /*----------------------------------------------------------------------------*/
    default :
    /*----------------------------------------------------------------------------*/
      NmAssertDirect( NMERR_ILLSTATE );
      break;
  } /* end switch */

  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )
  /*--- Last sending HVMsg not accepted on CAN-bus -------------------------*/
  if( nmHLVWTxTransmitted!=kNmFalse )
  {
    /* Wakeup must be confirmed after period of time. If not, reinit CAN ---*/
    if( nmWakeupCnt[NM_CHANNEL_IDX] < (NmCfg_LastWakeup_Cnt(channel) - NmCfg_WakeupFail_Cnt(channel)) )
    {
      IlRequeueTransmitMessages(NM_CHANNEL_ILPARA_ONLY);
      CanOffline(NM_CHANNEL_CANPARA_ONLY);

      /* CanInit is called to kill any message from the  */
      /* CAN-object that prevents the HLVW-transmission  */
      /* Thus, blocks the wakeup of the sleepy nodes.   */
      CanInit(NM_CHANNEL_CANPARA_FIRST  NmCfg_InitObj_Std(channel));

      ApplTrcvrNormalMode(NM_CHANNEL_APPLPARA_ONLY);    /* Turn transceiver to normal ------*/

    #if defined( NM_ENABLE_HLVW_INDICATION_FCT)
      ApplNwmHLVWStop(NM_CHANNEL_APPLPARA_ONLY);
    #endif

      /*-- Clear old send-indicator --*/
      nmHLVWTxTransmitted = kNmFalse;
      nmHLVWTxActive = kNmFalse; /* ESCAN00038021 */

      /* Increment counter of failed Wakeup retries */
      nmNrOfFailedWakeup[NM_CHANNEL_IDX]++;

      if (nmNrOfFailedWakeup[NM_CHANNEL_IDX] >= kNmNumberOfFailedWakeup )
      {
        nmNrOfFailedWakeup[NM_CHANNEL_IDX] = 0;   /*-- Clear fail counter for next retry */

    #if defined( NM_ENABLE_VN_ACTIVATOR) && \
        defined( NM_ENABLE_RECOVER_VN_AFTER_BUSOFF )
        /* ESCAN00014844: Process the VNMF but continue */
        /* trying to send the HLVW */
        nmNoComm = kNmTrue;
        nmHLVWTxFailed = kNmTrue;

        /*-- Reset Wakeup counter to allow new wakeup-sending ------------*/
        nmWakeupCnt[NM_CHANNEL_IDX] = 0;

        /*-- Process VNMF data with activation request  ------------*/
        /*-- to simulate the confirmation --------------------------*/
        NmDoActivationPending(NM_CHANNEL_NMPARA_ONLY);
    #else
        nmNoComm = kNmFalse;
        CanOnline(NM_CHANNEL_CANPARA_ONLY);
    #endif
      }
      else
      {
        /* HVMSG-sent has failed. After CanInit(), the controller needs to resync. 
           To avoid appl. to fill Tx-Buffer, switch off Controller */
        nmNoComm = kNmTrue;

        /*-- Reset Wakeup counter to allow new wakeup-sending ------------*/
        nmWakeupCnt[NM_CHANNEL_IDX] = 0;

        /*-- newly request to send a wakeup message. ---------------------*/
        /*-- Send this in next loop --------------------------------------*/
        nmHLVWTxRequest = kNmTrue;
      }
    }
  }
  /*-- Process request to HLVW message ----------------------*/
  else
  #endif

  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED  )
  {
    /*-- Process any data, if a message has to be sent -----------------------*/
    if( nmVNMFTxRequest!=kNmFalse )
    {
      nmVNMFTxRequest = kNmFalse;
      nmVNMFTxConfirmed = kNmFalse;
      if ( CanTransmit(NmCfg_TxHndl_VNMF(channel)) != kCanTxOk )
      {
        /* Tx request failed => set Tx request flag again */
        nmVNMFTxRequest = kNmTrue;
      }
    }
  }
  #endif
} /* PRQA S 2006, 4700, 4700 */  /* MD_NmGmlanGm_2006, MD_NmGmlanGm_4700, MD_NmGmlanGm_4700 */

/**********************************************************************************************************************
  Name:         IlNwmGetStatus
  Parameter:    channel
  Return value: current status of NM
  Description:  This function returns the current status of the NM.
**********************************************************************************************************************/
nmStatusType IlNwmGetStatus( NM_CHANNEL_NMTYPE_ONLY )
{
  return( nmState1 );
}

#if defined( NM_ENABLE_HIGHSPEED_MODE )
/**********************************************************************************************************************
  Name:         IlNwmSetHispeedMode
  Parameter:    channel
  Return value: NM_OK           NM was switched to HighSpeed mode
                NM_ERROR        request was not accepted because NM is not in correct state
                                (only available if NM_ENABLE_EXTENDED_RETURNCODES is enabled)
  Description:  This function sets the NM node to HighSpeed mode.
**********************************************************************************************************************/
Nm_Status IlNwmSetHispeedMode( NM_CHANNEL_NMTYPE_ONLY )
{
  #if defined( NM_ENABLE_EXTENDED_RETURNCODES )
  if( (nmNormalCommHalted==kNmFalse) || (nmSleepMode==kNmTrue) )
  {
    /* API not accepted because of incorrect NM state */
    return( NM_ERROR );
  }
  #endif

  /* check NM state */
  if( nmAction[NM_CHANNEL_IDX]==NM_BUSOFF )
  {
    /* set a flag to indicate that HighSpeed mode was requested */
    nmInternalHighSpeedMode = kNmTrue;
  }
  else
  {
    /* enter HighSpeed mode */
    NmGotoMode( NM_CHANNEL_NMPARA_FIRST NM_HIGHSPEED_MODE );
  }

  return( NM_OK );
} /* PRQA S 2006 */ /* MD_NmGmlanGm_2006 */
#endif

#if defined( NM_ENABLE_HIGHSPEED_MODE )
/**********************************************************************************************************************
  Name:         IlNwmResetHispeedMode
  Parameter:    channel
  Return value: ---
  Description:  This function sets the NM node to normal mode.
**********************************************************************************************************************/
void IlNwmResetHispeedMode( NM_CHANNEL_NMTYPE_ONLY )
{
  #if defined( NM_ENABLE_LOWVOLTAGE_MODE )
  if( nmLowVoltageMode == kNmTrue )
  {
    /* do nothing in LowVoltage mode. Quit ASAP. */
    return;
  }
  #endif

  /* set a flag to indicate that HighSpeed mode was released */
  nmInternalHighSpeedMode = kNmFalse;
} /* PRQA S 2006 */  /* MD_NmGmlanGm_2006 */
#endif

/**********************************************************************************************************************
  Name:         IlNwmNormalCommHalted
  Parameter:    channel     CAN channel handle
  Return value: NM_OK       NM was switched to NormalCommHalted mode
                NM_ERROR    request was not accepted because NM is not in correct state
                            (only available if NM_ENABLE_EXTENDED_RETURNCODES is enabled)
  Description:  This function stops normal communication.
                CAN stays in LowSpeed mode, but NM stops. Tx of any message is possible.
**********************************************************************************************************************/
Nm_Status IlNwmNormalCommHalted( NM_CHANNEL_NMTYPE_ONLY )
{
  /* ESCAN00022355, ESCAN00029103 */
  if( nmAction[NM_CHANNEL_IDX] == NM_BUSOFF )
  {
    return( NM_ERROR );
  }

  #if defined( NM_ENABLE_HIGHSPEED_MODE )
    #if defined( NM_ENABLE_EXTENDED_RETURNCODES )
  /* API may not be called in HighSpeed mode or Sleep mode */
  if( (nmHighSpeedMode!=kNmFalse) || 
      (nmSleepMode!=kNmFalse) )
  {
    /* API not accepted because of incorrect NM state => quit ASAP */
    return( NM_ERROR );
  }
    #endif
  #endif

  #if defined( NM_ENABLE_LOWVOLTAGE_MODE )
  /* API may not be processed if NM is in LowVoltage mode */
  if( nmLowVoltageMode == kNmTrue )
  {
    /* API not accepted because of incorrect NM state => quit ASAP */
    return( NM_ERROR );
  }
  #endif

  CanInterruptDisable();
  NmGotoMode( NM_CHANNEL_NMPARA_FIRST NM_COMM_HALTED );
  CanInterruptRestore();

  #if defined( NM_ENABLE_VN_LOCAL ) || \
      defined( NM_ENABLE_VN_ACTIVATOR )
  /* activate VN 0 (diagnosis) */
  (void)IlNwmActivateVN( NM_CHANNEL_NMPARA_FIRST 0 );
  #endif

  /* reset VN timer of VN 0 => leads to activation without delay */
  nmVnTimer[NmCfg_VN_StartIndex(channel)] = 0;

  return( NM_OK );
} /* PRQA S 2006 */ /* MD_NmGmlanGm_2006 */

/**********************************************************************************************************************
  Name:         IlNwmReturnToNormalMode
  Parameter:    channel
  Return value: ---
  Description:  This function sets the NM back to normal communication mode after IlNwmNormalCommHalted was called.
**********************************************************************************************************************/
void IlNwmReturnToNormalMode( NM_CHANNEL_NMTYPE_ONLY )
{
  /* ESCAN00023087 */
  if( nmSleepMode==kNmTrue )
  {
    return;
  }

  /* ESCAN00022355, ESCAN00029103 */
  if( nmAction[NM_CHANNEL_IDX] == NM_BUSOFF )
  {
    return;
  }

  #if defined( NM_ENABLE_HIGHSPEED_MODE )
  if( nmHighSpeedMode != kNmFalse )
  {
    IlNwmResetHispeedMode( NM_CHANNEL_NMPARA_ONLY );
  }
  else
  #endif
  {
  #if defined( NM_ENABLE_LOWVOLTAGE_MODE )
    /* API may not be processed if NM is in LowVoltage mode */
    if( nmLowVoltageMode != kNmFalse )
    {
      /* API not accepted because of incorrect NM state => quit ASAP */
      return;
    }
  #endif

    if( nmNormalCommHalted != kNmFalse )
    {
      IlDequeueNonActiveTxMessages(NM_CHANNEL_ILPARA_ONLY);

      /* execute initialization of COMM_ENABLE */
      NmGotoMode( NM_CHANNEL_NMPARA_FIRST  NM_COMM_ENABLE );
      nmGenericTimer[NM_CHANNEL_IDX] = NmCfg_WakeupSleep_Cnt(channel);
    }

  #if defined( NM_ENABLE_VN_LOCAL ) || \
      defined( NM_ENABLE_VN_ACTIVATOR )
    NmGotoMode( NM_CHANNEL_NMPARA_FIRST  NM_COMM_ACTIVE );
  #endif
  }
}  /* PRQA S 2006 */ /* MD_NmGmlanGm_2006 */

#if defined( NM_ENABLE_LOWVOLTAGE_MODE )
/**********************************************************************************************************************
  Name:         IlNwmEnterLowVoltageMode
  Parameter:    channel
  Return value: ---
  Description:  This function sets the NM node to LowVoltage mode.
  Usage:        This mode is normally commanded by the "LowVoltage Tolerant mode Master".
                The function has to be called when the corresponding signal has been received.
**********************************************************************************************************************/
void IlNwmEnterLowVoltageMode( NM_CHANNEL_NMTYPE_ONLY )
{
  NmAssert( nmInternalSleepMode==kNmFalse, NMERR_APIERR_CALLENTERLVMODE_IN_SLEEP ) /*;*/

  /* check if LowVoltage mode is not active */
  if( nmLowVoltageMode == kNmFalse )
  {
    /* if current state is COMM_OFF, switch to COMM_ENABLE first and then goto LowVoltage mode */
    if( nmSleepMode==kNmTrue )
    {
      NmGotoMode( NM_CHANNEL_NMPARA_FIRST  NM_COMM_ENABLE );
    }
    NmGotoMode( NM_CHANNEL_NMPARA_FIRST  NM_ENTER_LOW_VOLTAGE_TOLERANT_MODE );
  }
  else
  {
    /* do nothing */
  }
}
#endif

#if defined( NM_ENABLE_LOWVOLTAGE_MODE )
/**********************************************************************************************************************
  Name:         IlNwmExitLowVoltageMode
  Parameter:    channel
  Return value: ---
  Description:  This function sets the NM node back from LowVoltage mode.
  Usage:        This mode is normally commanded by the "LowVoltage Tolerant mode Master".
                The function has to be called when the corresponding signal has been received.
**********************************************************************************************************************/
void IlNwmExitLowVoltageMode( NM_CHANNEL_NMTYPE_ONLY )
{
  #if ( kNmNumberOfLVSusceptibleVNs > 0 )
  vsint8 i;
  vuint8 vnHndl;
  #endif

  /* check if LowVoltage mode is active */
  if( nmLowVoltageMode != kNmFalse )
  {
    /* lock CAN interrupts to ensure consistent I-VNMF */
    CanInterruptDisable();

  #if( kNmNumberOfLVSusceptibleVNs > 0 )
    /* iterate over all LowVoltage-susceptible VNs */
    for( i=kNmNumberOfLVSusceptibleVNs-1; i>=0; i-- )
    {
      /* determine VN */
      vnHndl = NmVnLVSusceptTable[i];

      /* check if VN is activator */
      if( (nmVnState[vnHndl] & NmVnActivator) != 0 )
      {
        /* set bit in I-VNMF message and request Tx of I-VNMF */
        nmSendInit[NmVnByteOffset[vnHndl]] |=  NmVnByteMask[vnHndl];
        nmVNMFInitRequest = kNmTrue;

        /* state of VN has changed => rescan it */
        nmRescanVn = kNmTrue;
      }
    }
  #endif

    NmGotoMode( NM_CHANNEL_NMPARA_FIRST NM_EXIT_LOW_VOLTAGE_TOLERANT_MODE );

    CanInterruptRestore();
  }
  else
  {
    /* do nothing */
  }
}
#endif

#if defined( NM_ENABLE_VN_LOCAL ) || \
    defined( NM_ENABLE_VN_ACTIVATOR )
/**********************************************************************************************************************
  Name:         IlNwmActivateVN
  Parameter:    channel         Handle of the Can Driver tx message.
                vnHndl          Pointer to the received data in the CAN Controller receive register
  Return value: NM_ERROR        activation request within HighSpeed mode.
                NM_WRONG_ARG    When argcheck is enabled and vnHndl out of range
                NM_OK           VN activation request accepted
                NM_INACTIVE     Application is not permitted for activation
                NM_INHIBITED    Application has inhibited VN activation
                NM_HALTED       
  Description:  Activation request of a Virtual Network
**********************************************************************************************************************/
Nm_Status IlNwmActivateVN( NM_CHANNEL_NMTYPE_FIRST  vuint8 vnHndl )
{
  /* ESCAN00029370 */
  NmAssert( nmHighSpeedMode==kNmFalse || nmInternalHighSpeedMode==kNmFalse, NMERR_ILLACTIVATOR )/*;*/

  #if defined ( NM_ENABLE_INDEXED_NM )
  /* determine internal VN handle */
  vnHndl = NmVnStartIndex[channel] + vnHndl;
  #endif

  /* ESCAN00024008 */
  NmAssert( vnHndl<=NmCfg_VN_StopIndex(channel), NMERR_ILLVNARGNUMBER )/*;*/

  #if defined( NM_ENABLE_EXTENDED_RETURNCODES )
  if( vnHndl > NmCfg_VN_StopIndex(channel) ) /* ESCAN00024008 */
  {
    return( NM_WRONG_ARG );
  }
  #endif

  /* check if VN is already activated */
  if( (nmVnState[vnHndl] & (NmVnLocal|NmVnActivator))!=0 )
  {
    return( NM_ACTIVE );
  }

  if( (nmAction[NM_CHANNEL_IDX]==NM_COMM_HALTED) && (NmCfg_VN_StartIndex(channel) != vnHndl) )
  {
    return( NM_HALTED );
  }

  #if defined( NM_ENABLE_HIGHSPEED_MODE )
  /* do not permit activation of VNs in HighSpeed mode */
  /* ESCAN00029370 */
  if( (nmHighSpeedMode!=kNmFalse) && (nmInternalHighSpeedMode!=kNmFalse) )
  {
    return( NM_ERROR );
  }
  #endif

  #if defined( NM_ENABLE_VN_LOCAL )
  if( (NmVnTypeTable[vnHndl] & kVnLocal)!=0 )
  {
    NmActivateCan(NM_CHANNEL_NMPARA_ONLY);

    CanInterruptDisable();

    /* Setting these states will activate the VN. Timer is initialized but not started until Local-flag is removed */
    nmVnState[vnHndl] |= (vuint8)((NmVnLocal | kNmVnRestartTimer));

    if( (nmVnState[vnHndl] & NmVnActive)==0 )
    {
      /* This is the delay time to activate Shared-Local Input VN */
      nmVnTimer[vnHndl] = (tNmVnTimer)(NmCfg_InitDelayLocal_Cnt(channel) + 1);  /* +1 solves ESCAN00006004 */

      /* ESCAN00023509 */
      if( (nmAction[NM_CHANNEL_IDX]!=NM_COMM_HALTED) || (NmCfg_VN_StartIndex(channel)!=vnHndl) )
      {
        /* Set the request bit to activate that VN */
        nmVnState[vnHndl] |= NmVnActivatorPending;
      }
    }
    else
    {
      if( nmVnTimer[vnHndl] <= (tNmVnTimer)NmCfg_VnRxTimer_Cnt(channel) )
      {
        /* Turn back on supervision */
        /*-- IL-function: Start Signal SuperVision -----------------------*/
        IlRxStartVnMsgSupervision(NM_CHANNEL_ILPARA_FIRST  vnHndl);
      }
    }
    nmRescanVn = kNmTrue;

    CanInterruptRestore();

    return( NM_OK );
  }
  #endif

  #if defined( NM_ENABLE_VN_ACTIVATOR )
  /*--- VnActivation not allowed in COMM_HALTED. Activation only once -------*/
  if( (NmVnTypeTable[vnHndl] & kVnActivator)!=0 )
  {
    CanInterruptDisable();

    #if defined( NM_ENABLE_INHIBIT_VN_HIGHLOAD )
    if( nmVnInhibition!=kNmFalse )
    {
      if((nmVnQueued[NmVnByteOffset[vnHndl]] & NmVnByteMask[vnHndl])==0)
      {
        nmVnQueued[NmVnByteOffset[vnHndl]] |= NmVnByteMask[vnHndl];
      }

      CanInterruptRestore();
      return( NM_INHIBITED );
    }
    #endif

    if( (nmVnState[vnHndl] & NmVnActivatorPending)==0 )
    {
      NmActivateCan(NM_CHANNEL_NMPARA_ONLY); /* If CAN in sleepmode, wakeup   */

      /* Check if VN is currently inactive or "out of date" (means: VN-timer < 4 sec. ) */
      if (nmVnTimer[vnHndl] < (tNmVnTimer)NmCfg_VnRestartIVnmf_Cnt(channel))
      {
        /* Check for sending HLVW */
        if (nmWakeupCnt[NM_CHANNEL_IDX]==0)
        {
          /* Setup first to ensure that Init-VNMF not transmitted when CanTransmit for wakeup message fails */
          nmSendInitVnmfCnt[NM_CHANNEL_IDX] = (vuint8) (NmCfg_VnmfStartSend_Cnt(channel) + 1);

          /* Send the HLVW frame only when VN is inactive and last WU > 3sec */
          NmSendWakeupMessage(NM_CHANNEL_NMPARA_ONLY);
        }

        /* Start timer for cyclic transmission of VNMF if not yet active. -*/
        if( nmVnActive==kNmFalse )
        {
          /* Timer, to transmit VNMF after sending I-VNMF */
          nmSendContVnmfCnt[NM_CHANNEL_IDX] = NmCfg_VnmfPeriodicRate_Cnt(channel);
        }

        /* This check is necessary because a VN may be shortly activated  */
        /* after reception of VNMF-activating. this VN activated when     */
        if ( (nmVnState[vnHndl] & kNmVnRestartTimer) == 0 )
        {
          /* If VN is currently inactive, indicate the Initialization within VNMF */
          nmVNMFInitRequest = kNmTrue;
          nmSendInit[NmVnByteOffset[vnHndl]] |= NmVnByteMask[vnHndl];
        }
      }
      else
      {
        NmAssert(nmVnTimer[vnHndl] > 0, NMERR_VNTIMER_INCONSISTENT )/*;*/

        /* NM sends currently VNMF, therefore schedule this VN into it ---*/
        /* Potential risk that VN-timer expires before VNMF is scheduled -*/
        if (nmVnTimer[vnHndl] < (tNmVnTimer)(NmCfg_VnTimer_Cnt(channel)-NmCfg_VnmfPeriodicRate_Cnt(channel)))
        {
          nmSendContVnmfCnt[NM_CHANNEL_IDX] = 0;
        }
      }
    }

    /*-- This indicates the activation of a VN, sendout of VNMF ------------*/
    nmVnState[vnHndl] |= (vuint8)(NmVnActivator | NmVnActivatorPending);

    nmSendContinue[NmVnByteOffset[vnHndl]] |= NmVnByteMask[vnHndl];

    nmRescanVn = kNmTrue;

    CanInterruptRestore();

    return( NM_OK );
  }
  #endif

  return( NM_INACTIVE );
}  /* PRQA S 2006, 4700 */ /* MD_NmGmlanGm_2006, MD_NmGmlanGm_4700 */
#endif

#if defined( NM_ENABLE_VN_LOCAL ) || \
    defined( NM_ENABLE_VN_ACTIVATOR )
/**********************************************************************************************************************
  Name:         IlNwmDeactivateVN
  Parameter:    channel
                vnHndl
  Return value: NM_WRONG_ARG            When argcheck is enabled and vnHndl out of range
                NM_OK                   VN deactivation request accepted
                NM_INACTIVE             VN was already inactive
  Description:  Deactivation request of a Virtual Network
**********************************************************************************************************************/
Nm_Status IlNwmDeactivateVN( NM_CHANNEL_NMTYPE_FIRST vuint8 vnHndl )
{
  Nm_Status rval = NM_INACTIVE;

  #if defined ( NM_ENABLE_INDEXED_NM )
  vnHndl = NmVnStartIndex[channel] + vnHndl;
  #endif

  /* ESCAN00024008 */
  NmAssert( vnHndl<=NmCfg_VN_StopIndex(channel), NMERR_ILLVNARGNUMBER )/*;*/

  #if defined( NM_ENABLE_EXTENDED_RETURNCODES )
  if( vnHndl > NmCfg_VN_StopIndex(channel) ) /* ESCAN00024008 */
  {
    return( NM_WRONG_ARG );
  }
  #endif

  /* check if VN is already inactivated */ /* ESCAN00023446 */
  if( (nmVnState[vnHndl] & (NmVnLocal|NmVnActivator))==0 )
  {
    return( NM_INACTIVE );
  }

  CanInterruptDisable();

  #if defined( NM_ENABLE_VN_LOCAL )
  if( (nmVnState[vnHndl] & NmVnLocal)!=0 )
  {
    nmRescanVn = kNmTrue;

    /* ESCAN00021023 */
    nmVnState[vnHndl] &= (vuint8)(~(vuintx)(NmVnLocal|NmVnActivatorPending));

    rval = NM_OK;
  }
  #endif

  #if defined( NM_ENABLE_VN_LOCAL ) && \
      defined( NM_ENABLE_VN_ACTIVATOR )
  else
  #endif

  #if defined( NM_ENABLE_VN_ACTIVATOR )
  {
    if( (NmVnTypeTable[vnHndl] & kVnActivator)!=0 )
    {
    #if defined( NM_ENABLE_INHIBIT_VN_HIGHLOAD )
      if( (nmVnQueued[NmVnByteOffset[vnHndl]] & NmVnByteMask[vnHndl])!=0 )
      {
        nmVnQueued[NmVnByteOffset[vnHndl]] &= (vuint8)(~NmVnByteMask[vnHndl]);
      }
    #endif

      nmRescanVn = kNmTrue;

      nmVnState[vnHndl] &= (vuint8)(~(vuintx)(NmVnActivator));

      if ((nmVnState[vnHndl] & NmVnActivatorPending)==0)
      {
        nmSendContinue[NmVnByteOffset[vnHndl]] &= (vuint8)(~NmVnByteMask[vnHndl]);
      }

      rval = NM_OK;
    }
  }
  #endif

  CanInterruptRestore();

  return( rval );
}  /* PRQA S 2006 */ /* MD_NmGmlanGm_2006 */
#endif

/**********************************************************************************************************************
  Name:         IlNwmGetVnTimer
  Parameter:    channel
                vnHndl
  Return value: current value of the VN timer in [ms]
  Description:  This function returns the current value of the VN timer of the given VN in [ms].
**********************************************************************************************************************/
vuint16 IlNwmGetVnTimer( NM_CHANNEL_NMTYPE_FIRST  vuint8 vnHndl )
{
  #if defined ( NM_ENABLE_INDEXED_NM )
  vnHndl = NmVnStartIndex[channel] + vnHndl;
  #endif

  return( (vuint16)(nmVnTimer[vnHndl] * (vuint16)NmCfg_CycleTime(channel)) );
}

/**********************************************************************************************************************
  Name:         IlNwmIsActiveVN
  Parameter:    channel
                vnHndl
  Return value: 0:              VN is not active
                others:         VN is active or will become active
  Description:  This function returns the current state of a VN.
                Use the following macros to evaluate the return value:
                -IlNwmIsNmVnNone(vnState)
                -IlNwmIsNmVnActive(vnState)
                -IlNwmIsNmVnActivator(vnState)
                -IlNwmIsNmVnLocal(vnState)
                -IlNwmIsNmVnRxActive(vnState)
                -IlNwmIsNmVnActivatorPending(vnState)
**********************************************************************************************************************/
vuint8 IlNwmIsActiveVN( NM_CHANNEL_NMTYPE_FIRST  vuint8 vnHndl )
{
  #if defined ( NM_ENABLE_INDEXED_NM )
  vnHndl = NmVnStartIndex[channel] + vnHndl;
  #endif

  return( (vuint8)(nmVnState[vnHndl] & (NmVnActive|NmVnActivator|NmVnLocal|NmVnRxActive|NmVnActivatorPending)) );
}

/**********************************************************************************************************************
  Name:         IlNwmGetActiveListVN
  Parameter:    *vnList         pointer to application buffer
  Return value: ---
  Description:  This function writes a list of the currently active VNs in a buffer provided by the application.
                The buffer is given by argument *vnList.
                Assignment between byte/bit position and VN number:
                | byte 0                  | byte 1                   | ...
                |  0  1  2  3  4  5  6  7 |  8  9 10 11 12 13 14  15 | ...
**********************************************************************************************************************/
void IlNwmGetActiveListVN( NM_CHANNEL_NMTYPE_FIRST vuint8 *vnList )
{
  vsint8 vnHndl;
  vuint8 vnByte;

  /* iterate over all VNs */
  for( vnHndl=(vsint8)NmCfg_VN_StopIndex(channel); vnHndl>=(vsint8)NmCfg_VN_StartIndex(channel); vnHndl-- )
  {
    /* determine VN-related byte within vnList */
  #if defined ( NM_ENABLE_INDEXED_NM )
    vnByte = (vuint8)(NmVnByteOffset[vnHndl] - NmVnByteOffset[NmVnStartIndex[channel]]); 
  #else
    vnByte = NmVnByteOffset[vnHndl];
  #endif

    /* check if VN is active and update vnList */
    if( (nmVnState[vnHndl] & (NmVnActive|NmVnActivator|NmVnLocal)) != 0 )
    {
      vnList[vnByte] |=  NmVnByteMask[vnHndl];
    }
    else
    {
      vnList[vnByte] &= (vuint8)(~NmVnByteMask[vnHndl]);
    }
  }
}

#if defined( NM_ENABLE_INHIBIT_VN_HIGHLOAD) && \
    defined( NM_ENABLE_VN_ACTIVATOR )
/**********************************************************************************************************************
  Name:         IlNwmInhibitActivationVN
  Parameter:    channel
  Return value: ---
  Description:  This function prevents the start of ACTIVATOR VNs by the own NM node.
                All VN requests are queued instead.
**********************************************************************************************************************/
void IlNwmInhibitActivationVN( NM_CHANNEL_NMTYPE_ONLY )
{
  vsint8 vnHndl;

  /* check if VN activation is currently not inhibited */
  if( nmVnInhibition == kNmFalse )
  {
    /* set a flag to inhibit any VN activation requests */
    nmVnInhibition = kNmTrue;

    /* iterate over all VNs */
    for( vnHndl=(vsint8)NmCfg_VN_StopIndex(channel); vnHndl>=(vsint8)NmCfg_VN_StartIndex(channel); vnHndl-- )
    {
      /* check if activation is pending */
      if( (nmVnState[vnHndl] & NmVnActivatorPending) != 0 )
      {
        /* delete activation request but queue it instead */
        CanInterruptDisable();
        nmVnState[vnHndl] &= (vuint8)(~(vuintx)(NmVnActivatorPending));
        nmVnQueued[NmVnByteOffset[vnHndl]] |= NmVnByteMask[vnHndl];
        CanInterruptRestore();
      }
    }
  }
  else
  {
    /* do nothing, as VN activation is already inhibited */
  }
}
#endif

#if defined( NM_ENABLE_INHIBIT_VN_HIGHLOAD) && \
    defined( NM_ENABLE_VN_ACTIVATOR )
/**********************************************************************************************************************
  Name:         IlNwmAllowActivationVN
  Parameter:    channel
  Return value: ---
  Description:  This function re-allows the start of ACTIVATOR VNs by the own NM node.
                All queued VN requests are processed.
**********************************************************************************************************************/
void IlNwmAllowActivationVN( NM_CHANNEL_NMTYPE_ONLY )
{
  vsint8 vnHndl;

  /* check if VN activation is currently inhibited */
  if( nmVnInhibition != kNmFalse )
  {
    /* remove flag that inhibits any VN activation requests */
    nmVnInhibition = kNmFalse;

    /* iterate over all VNs */
    for( vnHndl=(vsint8)NmCfg_VN_StopIndex(channel); vnHndl>=(vsint8)NmCfg_VN_StartIndex(channel); vnHndl-- )
    {
      /* check if VN is queued */
      if( (nmVnQueued[NmVnByteOffset[vnHndl]] & NmVnByteMask[vnHndl]) != 0 )
      {
        /* start VN and un-queue it */
        (void)IlNwmActivateVN( NM_CHANNEL_NMPARA_FIRST NM_CVT_NMVNPARA_TO_APPLVNPARA(vnHndl) );
        nmVnQueued[NmVnByteOffset[vnHndl]] &= (vuint8)(~NmVnByteMask[vnHndl]);
      }
    }
  }
  else
  {
    /* do nothing, as VN activation is already allowed */
  }
}
#endif

/**********************************************************************************************************************
  Name:         NmInit
  Parameter:    channel
  Return value: ---
  Description:  This function initializes the NM node.
**********************************************************************************************************************/
void NmInit( NM_CHANNEL_NMTYPE_ONLY )
{
  /* set transceiver to normal mode */
  ApplTrcvrNormalMode(NM_CHANNEL_APPLPARA_ONLY);

  #if defined( NM_ENABLE_CALL_CANINITPON )
  /* initialize DrvCan */
    #if defined ( NM_ENABLE_INDEXED_NM )
  /* ensure that CAN is initialized only once (=> save runtime) */
  if( channel==0 )
    #endif
  {
    CanInitPowerOn();
  }
    #if defined( NM_ENABLE_CALL_CANINIT )
      #if defined( NM_ENABLE_CANINIT_PARAM_CHECK )
        #if defined ( NM_ENABLE_USERSPECIFIC_CANINITOBJECTS )
  if( NmCfg_InitObj_Std(channel)!=0 )
        #endif
      #endif
  {
    CanInit( NM_CHANNEL_CANPARA_FIRST NmCfg_InitObj_Std(channel) );
  }
    #endif
  #endif

  /* allow CAN transmission */
  CanOnline(NM_CHANNEL_CANPARA_ONLY);
  nmNoComm = kNmFalse;

  /* reset BusOff counter */
  nmBusOffRecoveryTimeCnt[NM_CHANNEL_IDX] = 0;
}

#if defined ( NM_ENABLE_HLVW_HANDLING )
/**********************************************************************************************************************
  Name:         NmHVPreTransmit
  Parameter:    ctis            pointer to data of CAN Tx object (Note: not used)
  Return value: kCanNoCopyData  global data buffer is not used. Transmission can be started immediately
  Description:  This function informs the NM that the HLVW message is about to be send.
                The CAN object is locked for transmission.
                Therefore, it is a well suited place to switch the transceiver into HLVW mode.
**********************************************************************************************************************/
vuint8 NmHVPreTransmit( CanTxInfoStruct ctis )
{
  #if defined ( NM_ENABLE_INDEXED_NM )
  CanChannelHandle channel = CanTxMsgHandleToChannel[ctis.Handle];
  #else
    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  ctis = ctis; /* PRQA S 3199 */  /* MD_NmGmlanGm_3199 */
    #endif
  #endif

  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )
    #if defined( NM_ENABLE_SINGLEWIRE_TRCV )
      #if defined( NM_ENABLE_INDEXED_NM )
  /* Check if for this channel a single wire transceiver is used. */
  if( NmTrcvType_Field[channel]==NM_SINGLEWIRE_TRCV )
  {
      #else
  {
      #endif
    /* request application to switch single wire transceiver into HV mode */
    ApplTrcvrHighVoltage( NM_CHANNEL_APPLPARA_ONLY );
  }
    #endif

  /* set a flag that HLVW message is about to be transmitted */
  nmHLVWTxActive = kNmTrue;


    #if defined( NM_ENABLE_HLVW_INDICATION_FCT )
  /* inform application that transmission of HLVW message is started */
  ApplNwmHLVWStart( NM_CHANNEL_APPLPARA_ONLY );
    #endif
  #endif

  /* data of HLVW message is not relevant */
  return( kCanNoCopyData );
}
#endif

#if defined ( NM_ENABLE_HLVW_HANDLING )
/**********************************************************************************************************************
  Name:         NmHVConfirmation
  Parameter:    txObject        handle of CAN Tx object (Note: not used)
  Return value: ---
  Description:  This function informs the NM that the HLVW message has been confirmed, 
                i.e. the message was successfully transmitted.
**********************************************************************************************************************/
void NmHVConfirmation( CanTransmitHandle txObject )
{
  #if defined ( NM_ENABLE_INDEXED_NM )
  CanChannelHandle channel = CanTxMsgHandleToChannel[txObject];
  #else
    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  txObject = txObject;  /* PRQA S 3199 */  /* MD_NmGmlanGm_3199 */
    #endif
  #endif

  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )
  /* HLVW message was sent => activate initially-active VNs */
    #if defined( NM_ENABLE_HIGHSPEED_MODE )
  if( (nmNormalCommHalted == 0) && (nmHighSpeedMode == 0) )
    #else
  if( nmNormalCommHalted == 0 )
    #endif
  {
    NmSetupInitActivation(NM_CHANNEL_NMPARA_ONLY);
  }

  /* set a flag that HLVW is confirmed */
  nmHLVWTxConfirmed = kNmTrue;

    #if defined( NM_ENABLE_SINGLEWIRE_TRCV )
      #if defined( NM_ENABLE_INDEXED_NM )
  /* check if a single wire transceiver is used on the current channel => set to NORMAL mode */
  if( NmTrcvType_Field[channel]==NM_SINGLEWIRE_TRCV )
  {
      #else
  {
      #endif
    ApplTrcvrNormalMode( NM_CHANNEL_APPLPARA_ONLY );
  }
    #endif

  /* clear HLVW flags */
  nmHLVWTxActive = kNmFalse;
  nmHLVWTxTransmitted = kNmFalse;

    #if defined( NM_ENABLE_HLVW_INDICATION_FCT )
  /* inform application that transmission of HLVW message is stopped */
  ApplNwmHLVWStop( NM_CHANNEL_APPLPARA_ONLY );
    #endif
  #endif
}
#endif

#if defined ( NM_ENABLE_HLVW_HANDLING )
/**********************************************************************************************************************
  Name:         NmHVPreCopy
  Parameter:    rxStruct        pointer to Rx message
  Return value: kCanNoCopyData
  Description:  This function informs the NM about the reception of a HLVW message.
**********************************************************************************************************************/
vuint8 NmHVPreCopy( CanRxInfoStructPtr rxStruct )  /* PRQA S 3673 */  /* MD_NmGmlanGm_3673 */
{
  #if defined ( NM_ENABLE_INDEXED_NM )
  CanChannelHandle channel = rxStruct->Channel;
  #else
    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  rxStruct = rxStruct;  /* PRQA S 3199 */  /* MD_NmGmlanGm_3199 */
    #endif
  #endif

  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )
  /* restart wakeup counter */
  nmWakeupCnt[NM_CHANNEL_IDX] = NmCfg_LastWakeup_Cnt(channel);

  /* delete HLVW Tx request when HLVW was received (ESCAN00000262) */
  nmHLVWTxRequest = kNmFalse;
  #endif

  /* set a flag the HLVW was received */
  nmHLVWRxFlag = kNmTrue;

  /* some controller cannot wakeup by NmCanWakeUp()... */
  NmActivateCan(NM_CHANNEL_NMPARA_ONLY);

  #if defined ( NM_ENABLE_HLVW_HANDLING )
  /* check if HLVW is about to be send */
  if( nmHLVWTxTransmitted != kNmFalse )
  {
    /* HLVW is currently in the queue => remove it! */
    CanCancelTransmit(NmCfg_TxHndl_HLVW(channel));
    nmHLVWTxTransmitted = kNmFalse;

    if( nmHLVWTxActive!=kNmFalse )
    {
      nmHLVWTxActive=kNmFalse;

      /* Since CanCancelTransmit() prevents confirmation
         the transceiver has to be set back to normal mode here */
      ApplTrcvrNormalMode( NM_CHANNEL_APPLPARA_ONLY );
    }
  }
  #endif

  /* data of HLVW message is not relevant */
  return( kCanNoCopyData );
}
#endif

/**********************************************************************************************************************
  Name:         NmPreTransmit
  Parameter:    ctis            pointer to data buffer of CAN object
  Return value: kCanCopyData    Indicates the copy of data from global data buffer
                kNoCanCopyData  Data has been copied by this function. No action from DLL needed.
  Description:  This function informs the NM that the VNMF message is about to be transmitted.
                The data is directly written into the CAN object.
**********************************************************************************************************************/
vuint8 NmPreTransmit( CanTxInfoStruct ctis )
{
  /* ESCAN00030131 */
  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED)
  CanChipDataPtr txDataPtr = ctis.pChipData;
  vuint8 V_MEMRAM2 txVnmfIdx=1;
  vuint8 idx;
    #if defined ( NM_ENABLE_INDEXED_NM )
  CanChannelHandle channel = CanTxMsgHandleToChannel[ctis.Handle];
    #endif

  /* check type of VNMF to be transmitted (I-VNMF or C-VNMF) */
  if( nmVNMFInitRequest==kNmTrue )
  {
    /* => Init-VN */
    nmLastVnmfType[NM_CHANNEL_IDX] = txDataPtr[0] = 1;         /* First Byte to INIT   */

    nmVNMFInitRequest = kNmFalse;

    idx = NmCfg_VnByte_StartIndex(channel);
    while( idx <= NmCfg_VnByte_StopIndex(channel) )
    {
      /* Copy init-VNMF data field */
      txDataPtr[txVnmfIdx] = nmSendMess.c[idx] = nmSendInit[idx];

      txVnmfIdx++;
      idx++;
    }
  }
    #if defined( NM_ENABLE_VN_ACTIVATOR )
  else
  {
    /* => Continuous-VN */
    nmLastVnmfType[NM_CHANNEL_IDX] = txDataPtr[0] = 0;    /* First Byte to INIT   */

    idx = NmCfg_VnByte_StartIndex(channel);
    while( idx <= NmCfg_VnByte_StopIndex(channel) )
    {
      /* copy continue-VN data field */
      txDataPtr[txVnmfIdx] = nmSendMess.c[idx] = nmSendContinue[idx];
      txVnmfIdx++;
      idx++;
    }
  }
    #endif

  /* fill remaining bytes with 0x00 */
  while( txVnmfIdx < 8 )
  {
    txDataPtr[txVnmfIdx] = 0x00;
    txVnmfIdx++;
  }
  #endif

  return( kCanNoCopyData );
}

/**********************************************************************************************************************
  Name:         NmConfirmation
  Parameter:    Handle of CAN-object (not used)
  Return value: ---
  Description:  Confirmation of successfully transmitted VNMF.
                The Init/Continue flag is cleared in Byte 0/Bit 0 of VNMF.
**********************************************************************************************************************/
void NmConfirmation( CanTransmitHandle txObject )
{
  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )
  vsint8 vnHndl;
  vsint8 vnByte;

    #if defined ( NM_ENABLE_INDEXED_NM )
   V_MEMRAM0 V_MEMRAM1 CanChannelHandle V_MEMRAM2 channel = CanTxMsgHandleToChannel[txObject];
    #else
      #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
   txObject = txObject;  /* PRQA S 3199 */  /* MD_NmGmlanGm_3199 */
      #endif
    #endif

  /* Reject any VNMF if in sleepmode or HighSpeed (Diag) mode */
    #if defined(NM_ENABLE_HIGHSPEED_MODE)
  if( (nmInternalSleepMode==kNmTrue) || 
      (nmNormalCommHalted==kNmTrue) || 
      (nmHighSpeedMode==kNmTrue) )
    #else
  if( (nmInternalSleepMode==kNmTrue) || 
      (nmNormalCommHalted==kNmTrue))
    #endif
  {
    /* NoCommunication is active on diag-state and Sleepmode/Shutdown mode of NM. */
    return;
  }

  nmVNMFTxConfirmed = kNmTrue;

  /* Restart the VnTimer for activated VN's sent in VNMF */
  for( vnHndl=(vsint8)NmCfg_VN_StopIndex(channel); vnHndl>=(vsint8)NmCfg_VN_StartIndex(channel); vnHndl-- )
  {
    /* Check if bit is set in VNMF */
    if((nmSendMess.c[NmVnByteOffset[vnHndl]] & NmVnByteMask[vnHndl])!=0)
    {
      /* Request to restart the VN-Timer */
      nmVnState[vnHndl] |=  kNmVnRestartTimer;

      /* Activate VN-message in VNMF-confirmation to enable reception of msg. */
      if ( (nmVnState[vnHndl] & NmVnRxActive)==0 )
      {
        (void)IlRxActivateVnMsg(NM_CHANNEL_ILPARA_FIRST (vuint8)vnHndl);
        nmVnState[vnHndl] |= NmVnRxActive;
      }

    #if defined( NM_ENABLE_VN_ACTIVATOR )
      nmVnState[vnHndl] &= (vuint8)(~(vuintx)(NmVnActivatorPending));

      /* Clear both reinit-VN bits and already deactivated VN-bits. */
      if ((nmVnState[vnHndl] & NmVnActivator)==0)
      {
        nmSendContinue[NmVnByteOffset[vnHndl]] &= (vuint8)(~NmVnByteMask[vnHndl]);
      }
    #endif
    }
  }

  if( (nmLastVnmfType[NM_CHANNEL_IDX])!=0 )
  {
    for(vnByte=(vsint8)NmCfg_VnByte_StopIndex(channel); vnByte>=(vsint8)NmCfg_VnByte_StartIndex(channel); vnByte-- )
    {
      /* Clear Init-Request bits that has been transmitted */
      nmSendInit[vnByte] &= (vuint8)(~nmSendMess.c[vnByte]);
    }
  }

  nmRescanVn = kNmTrue;
  #else
    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  txObject=txObject;  /* PRQA S 3199 */  /* MD_NmGmlanGm_3199 */
    #endif
  #endif
}  /* PRQA S 2006 */  /* MD_NmGmlanGm_2006 */

/**********************************************************************************************************************
  Name:         NmPrecopy
  Parameter:    Handle of CAN-object is either ptr to data buffer of Handle to receive object.
  Return value: kCanCopyData:       Indicates the copy of data to global data buffer
                kNoCanCopyData:     Finish the action in DLL.
  Description:  Indicates the reception of a VNMF.
                The data are scanned and appropriate flags are set.
**********************************************************************************************************************/
vuint8 NmPrecopy (CanRxInfoStructPtr rxStruct)  /* PRQA S 3673 */  /* MD_NmGmlanGm_3673 */
{
  #if defined( NM_ENABLE_VN_REMOTED )
  CanChipDataPtr nmRecvMess = rxStruct->pChipData;
    #if defined ( NM_ENABLE_INDEXED_NM )
  CanChannelHandle channel = rxStruct->Channel;
    #endif
  vuint8 hilf;
  vuint8 rxVnmfIdx;
  vuint8 nmVnBit;
  vuint8 nmVnByte;
  vuint8 vnHndl;
  vsint8 vnByte;

  /*-- Reject any NMF if  in sleepmode or HighSpeed (Diag) mode ---------------*/
    #if defined(NM_ENABLE_HIGHSPEED_MODE)
  if( (nmInternalSleepMode==kNmTrue) || 
      (nmNormalCommHalted==kNmTrue)    || 
      (nmHighSpeedMode==kNmTrue)         )
    #else
  if( (nmInternalSleepMode==kNmTrue) ||
      (nmNormalCommHalted==kNmTrue)    )
    #endif
  {
    /* NoCommunication is active on BusOff-state and Sleepmode/Shutdown mode of NM. */
    return( kCanNoCopyData );
  }

  /* Check if DLC of VNMF is 8 Bytes */
  if( CanRxActualDLC(rxStruct) < 8 )  /* PRQA S 488 */  /* MD_NmGmlanGm_488 */
  {
    return( kCanNoCopyData );
  }

  rxVnmfIdx = 1;    /* Start with first VN-data byte inside the VNMF */
  nmVnByte = NmCfg_VnByte_StartIndex(channel);
  vnHndl   = NmCfg_VN_StartIndex(channel);

  /* Recalculate current VN-Nr. */
  do
  {
    hilf = (vuint8)(nmRecvMess[rxVnmfIdx] & NmVnRelevantMask[nmVnByte]);
    nmVnBit = 0x80;

    #if defined ( NM_ENABLE_INDEXED_NM )
    NmAssert(nmVnByte < NmVnByteStartIndex[channel+1], NMERR_ILL_VNMF_INDEX)/*;*/
    NmAssert(vnHndl < NmVnStartIndex[channel+1],  NMERR_ILL_VN_NUMBER)/*;*/
    #else
    NmAssert(nmVnByte < (kNmNumberOfVnBytes+1), NMERR_ILL_VNMF_INDEX)/*;*/
    #endif
    NmAssert(rxVnmfIdx < 8, NMERR_ILL_VNMF_INDEX)/*;*/

    while( nmVnBit!=0 )
    {
      if( (hilf & nmVnBit)!=0 )
      {
        /* clear the checked VN -------------*/
        hilf ^= nmVnBit;

        /*--- Enable reception of VN msg immediately on reception of VNMF ---*/
        if( (nmVnState[vnHndl] & NmVnRxActive)==0 )
        {
          /* In case of receiving a message before IL is started */
          if( IlRxActivateVnMsg(NM_CHANNEL_ILPARA_FIRST vnHndl)!=IL_ERROR )
          {
            nmVnState[vnHndl] |= NmVnRxActive;
          }
        }

        /* Indicate a status change for VN's. call NmStateTask() ------------*/
        nmRescanVn = kNmTrue;

        /*-- Set the VnState to Remotely activation pending. -------------------*/
        /*-- copy also the Init/Continue flag for this VN to the state byte  ---*/
        /* ESCAN00038215 */
        if( (nmVnStateInhibit[vnHndl] == 0) || ((nmVnState[vnHndl] & NmVnActive)==NmVnActive)  )
        {
          nmVnState[vnHndl] |= (vuint8)((kNmVnRemotedPending | kNmVnRestartTimer | 
                                        (nmRecvMess[0] & kNmVNMFVnInitialize)));
          nmVnStateInhibit[vnHndl] = 1;
        }

        /* ESCAN00043175 */
        /* Check if the received VNMF has the init bit set */
        if ( (nmRecvMess[0] & kNmVNMFVnInitialize)!=0 )
        {
          /* NmVnActivator is set by IlNwmActivateVN, so if it's set this can't be a reinit case */
          if( (nmVnState[vnHndl] & (NmVnActivator)) == 0 )
          {
            /* nmTxConfirmCnt is non-zero when CanTransmit has been called for the VNMF */
            if( nmTxConfirmCnt[NM_CHANNEL_IDX]!=0 )
            {
              /* Check if the VN bit is set in the VNMF message */
              if( (nmSendInit[NmVnByteOffset[vnHndl]] & NmVnByteMask[vnHndl])!=0 )
              {
                /* Check if the VNMF message has the init bit set and pretransmit has not been called */
                if( nmVNMFInitRequest == kNmTrue )
                { /* PRQA S 715 */  /* MD_NmGmlanGm_715 */
                  /* Remove the bit from the I-VNMF */
                  nmSendInit[NmVnByteOffset[vnHndl]] &= (vuint8)(~NmVnByteMask[vnHndl]);
    
                  nmVNMFInitRequest = kNmFalse;
    
                  /* Check if the I-VNMF still needs to be sent for other VNs */
                  for(vnByte=(vsint8)NmCfg_VnByte_StopIndex(channel); vnByte>=(vsint8)NmCfg_VnByte_StartIndex(channel); vnByte-- )
                  {
                    /* check if there is something to be sent */
                    if( nmSendInit[vnByte] != 0 )
                    {
                      /* set Tx request */
                      nmVNMFInitRequest = kNmTrue;
                      break;
                    }
                  }
    
                  /* Are there no other VNs in the I-VNMF? */ 
                  if( nmVNMFInitRequest == kNmFalse )
                  {
                    nmTxConfirmCnt[NM_CHANNEL_IDX] = 0; /* reset Tx confirmation timeout counter */
                    CanCancelTransmit(NmCfg_TxHndl_VNMF(channel));
                  }
                }
              }
            }
          }
        }
      }
      vnHndl++;
      nmVnBit >>= 1;
    }
    rxVnmfIdx++;
    nmVnByte++;
  }
    #if defined ( NM_ENABLE_INDEXED_NM )
  while(vnHndl < NmVnStartIndex[channel+1]);
    #else
  while(vnHndl < kNmNumberOfVirtualNets);
    #endif

  #else /* ENABLE_VN_REMOTED */
    #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  rxStruct = rxStruct;  /* PRQA S 3199 */  /* MD_NmGmlanGm_3199 */
    #endif
  #endif

  return( kCanNoCopyData );
}  /* PRQA S 2006,4700 */  /* MD_NmGmlanGm_2006, MD_NmGmlanGm_4700 */

/**********************************************************************************************************************
  Name:         NmCanWakeUp
  Parameter:    CAN channel
  Return value: ---
  Description:  This function notifies the NM about a CAN wakeup interrupt, 
                i.e. CAN activities on Rx line of CAN while CAN is asleep.
**********************************************************************************************************************/
void NmCanWakeUp( NM_CHANNEL_CANTYPE_ONLY )
{
  /* wakeup CAN controller */
  NmActivateCan( NM_CHANNEL_NMPARA_ONLY );

  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )
  /* restart wakeup counter */
  nmWakeupCnt[NM_CHANNEL_IDX] = NmCfg_LastWakeup_Cnt(channel);
  #endif

  #if defined( NM_ENABLE_WAKEUP_RECEIVED_FCT )
  /* inform application about wakeup event */
  ApplNwmWakeupMsgRecv( NM_CHANNEL_APPLPARA_ONLY );
  #endif

  /* start initially active VNs */
  NmSetupInitActivation(NM_CHANNEL_NMPARA_ONLY);
}

/**********************************************************************************************************************
  Name:         NmCanError
  Parameter:    CAN channel
  Return value: ---
  Description:  This function notifies a BusOff event.
**********************************************************************************************************************/
void NmCanError( NM_CHANNEL_CANTYPE_ONLY )
{
  /* BusOff handling may not be interrupted by CAN interrupts */
  CanInterruptDisable();

  nmHLVWTxRequest = kNmFalse; /* remove pending HLVW Tx requests */

  /* [SR:028] */
  IlRequeueTransmitMessages(NM_CHANNEL_ILPARA_ONLY);

  /* inhibit message transmission during BusOff */
  CanOffline( NM_CHANNEL_CANPARA_ONLY );
  nmNoComm = kNmTrue;

  /* initialize the CAN controller [SR:026] */
  #if defined( NM_ENABLE_HIGHSPEED_MODE )
  if( nmInternalHighSpeedMode==kNmTrue )
  {
    #if defined ( NM_ENABLE_INDEXED_NM )
    CanResetBusOffStart(NM_CHANNEL_CANPARA_ONLY, NmCfg_InitObj_HighSpeed(channel));
    #else
    CanResetBusOffStart(NmCfg_InitObj_HighSpeed(channel));
    #endif
  }
  else
  #endif
  {
  #if defined ( NM_ENABLE_INDEXED_NM )
    CanResetBusOffStart(NM_CHANNEL_CANPARA_ONLY, NmCfg_InitObj_Std(channel));
  #else
    CanResetBusOffStart(NmCfg_InitObj_Std(channel));
  #endif
  }

  nmAction[NM_CHANNEL_IDX] = NM_BUSOFF;
  nmBusOff = kNmTrue;

  CanInterruptRestore();

  #if defined( NM_ENABLE_BUSOFF_FCT )
  /* inform application about BusOff event [SR:025] */
  ApplNwmBusoff(NM_CHANNEL_APPLPARA_ONLY);
  #endif
}


/**********************************************************************************************************************
  Local function definitions
**********************************************************************************************************************/
/**********************************************************************************************************************
  Name:         NmActivateCan
  Parameter:    channel
  Return value: ---
  Description:  This function activates the DataLinkLayer (DLL) (=>DrvCan) after sleep mode.
**********************************************************************************************************************/
static void NmActivateCan( NM_CHANNEL_NMTYPE_ONLY )
{
  /* process only if NM is not in sleep mode */
  if( nmInternalSleepMode != kNmFalse )
  {
    /* load sleep counter */
    nmGenericTimer[NM_CHANNEL_IDX] = NmCfg_WakeupSleep_Cnt(channel);

    /* inform application to set transceiver to NORMAL */
    ApplTrcvrNormalMode(NM_CHANNEL_APPLPARA_ONLY);

    /* wakeup CAN */
    (void)CanWakeUp(NM_CHANNEL_CANPARA_ONLY);

    nmNoComm = kNmFalse;

    /* enable CAN Tx path */
    CanOnline(NM_CHANNEL_CANPARA_ONLY);

    nmInternalSleepMode = kNmFalse;
  }
  else
  {
    /* do nothing */
  }
}

#if defined( NM_ENABLE_VN_ACTIVATOR ) || \
    defined( NM_ENABLE_VN_REMOTED )
/**********************************************************************************************************************
  Name:         NmDoActivationPending
  Parameter:    channel
  Return value: ---
  Description:  If no confirmation timeout is processed but VNMF could not be transmitted successfully, 
                the pending activation (from application VN-activation) is performed to ensure, 
                that the node goes to sleepmode when VN is requested for deactivation.
  Note:         This function has to be called with locked interrupt.
**********************************************************************************************************************/
static void NmDoActivationPending( NM_CHANNEL_NMTYPE_ONLY )
{
  vsint8 vnHndl;

  /* iterate over all VNs */
  for( vnHndl=(vsint8)NmCfg_VN_StopIndex(channel); vnHndl>=(vsint8)NmCfg_VN_StartIndex(channel); vnHndl-- )
  {
    /* request to restart the VN timer */
    if( (nmVnState[vnHndl] & (NmVnActivatorPending|NmVnLocal)) == NmVnActivatorPending )
    {
      nmVnState[vnHndl] &= (vuint8)(~(vuintx)(NmVnActivatorPending));
      nmVnState[vnHndl] |=  kNmVnRestartTimer;
      nmRescanVn = kNmTrue;
      nmSendInit[NmVnByteOffset[vnHndl]] &= NmVnByteMask[vnHndl];
    }
  }
}
#endif


/**********************************************************************************************************************
  Name:         NmGotoMode / NmGotoModeInternal
  Parameter:    requested new status.
  Return value: ---
  Description:  Switches the NM-status and performs status dependent initializations. 
                Locks interrupt to prevent problems on Read-Modify-Write on flag field of status variables.
**********************************************************************************************************************/
static void NmGotoMode( NM_CHANNEL_NMTYPE_FIRST  nmActionType NewNodeState )
{
  /* shortens runtime when no action needed */
  if (nmAction[NM_CHANNEL_IDX] == NewNodeState)
  {
    return;
  }

  CanInterruptDisable();

  /*-- Clear always the sleepmode request and NormalCommHalted --------------*/
  nmSleepModePending = kNmFalse;
  nmNormalCommHalted = kNmFalse;

  switch( NewNodeState )
  {
    /*----------------------------------------------------------------------------*/
    case NM_COMM_OFF:
    /*----------------------------------------------------------------------------*/
      if( nmNoComm==kNmFalse )
      {
        CanOffline(NM_CHANNEL_CANPARA_ONLY);
        nmNoComm = kNmTrue;
      }
      if( nmSleepMode==kNmFalse )
      {
        /* stop IL */
        IlTxStop(NM_CHANNEL_ILPARA_ONLY);
        IlRxStop(NM_CHANNEL_ILPARA_ONLY);

        /* stop transceiver */
  #if defined ( NM_ENABLE_SINGLEWIRE_TRCV )
    #if defined ( NM_ENABLE_INDEXED_NM )
        /* Check if for this channel the sleep request of the transceiver must be set before */
        /* CanSleep is called or not.                                                        */
        if( NmTrcvType_Field[channel]==NM_SINGLEWIRE_TRCV )
    #endif
        {
          ApplTrcvrSleepMode(NM_CHANNEL_APPLPARA_ONLY);
        }
  #endif

        /* Workaround: Check if the 100h message was already received, */
        nmInternalSleepMode = kNmTrue;
        CanInterruptRestore();
        CanInterruptDisable();
        /* if HLVW message has been received sleep mode will be false and we must exit mode change */
        {
          vuint8 restart=0;

          if( nmInternalSleepMode_volatile==kNmFalse )
          {
            restart = 1;
          }

          /* Check if the sleepmode didn't fail */
          /* Note: This avoids problems with the kCanNotSupported return value */
          if( CanSleep(NM_CHANNEL_CANPARA_ONLY)==kCanFailed )
          {
            restart = 1;
          }

          if( restart!=0 )
          {
            NmActivateCan(NM_CHANNEL_NMPARA_ONLY);
            CanInterruptRestore();

            /* restart interaction layer */
            IlTxStart(NM_CHANNEL_ILPARA_ONLY);
            IlRxStart(NM_CHANNEL_ILPARA_ONLY);
            return;
          }
        }

        /* stop transceiver */
  #if defined ( NM_ENABLE_HIGHSPEED_SLEEP_TRCV )
    #if defined(NM_ENABLE_INDEXED_NM)
        if( NmTrcvType_Field[channel]==NM_HIGHSPEED_SLEEP_TRCV )
    #endif
        {
          ApplTrcvrSleepMode(NM_CHANNEL_APPLPARA_ONLY);
        }
  #endif
        nmSleepMode=kNmTrue;

        nmBusOffRecoveryTimeCnt[NM_CHANNEL_IDX] = 0;
        nmBusOff = kNmFalse;      /* clear marker for BusOff       */

        /* Clear the internal state */
        nmHLVWTxRequest     = kNmFalse;
        nmHLVWTxTransmitted = kNmFalse;
        nmVNMFTxRequest        = kNmFalse;
  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )   || \
      defined( NM_ENABLE_HIGHSPEED_MODE )
        nmTxConfirmCnt[NM_CHANNEL_IDX] = 0;
  #endif
        nmVNMFInitRequest = kNmFalse;
        nmInternalHighSpeedMode  = kNmFalse;

  #if defined( NM_ENABLE_SLEEP_FCT )
        ApplNwmSleep(NM_CHANNEL_APPLPARA_ONLY);                  /* Indicates, that sleepmode-state is reached */
  #endif
      }
      break;
    /*----------------------------------------------------------------------------*/
    case NM_COMM_ENABLE:
    /*----------------------------------------------------------------------------*/
      /* Clear the internal state */
      NmActivateCan(NM_CHANNEL_NMPARA_ONLY);

      /*-- Initialize values only when NOT leaving the sleep mode ---------*/
      if (nmAction[NM_CHANNEL_IDX]!=NM_COMM_OFF)
      {
        nmHLVWTxRequest         = kNmFalse;
        nmHLVWTxTransmitted     = kNmFalse;
        nmVNMFInitRequest       = kNmFalse;
        nmVNMFTxRequest         = kNmFalse;
        nmInternalHighSpeedMode = kNmFalse;
  #if defined( NM_ENABLE_VN_ACTIVATOR )     || \
      defined( NM_ENABLE_VN_REMOTED )      || \
      defined ( NM_ENABLE_HIGHSPEED_MODE )
        nmTxConfirmCnt[NM_CHANNEL_IDX] = 0;
  #endif
        nmSendInitVnmfCnt[NM_CHANNEL_IDX] = 0;
  #if defined( NM_ENABLE_VN_ACTIVATOR )     || \
      defined( NM_ENABLE_VN_REMOTED )
        nmSendContVnmfCnt[NM_CHANNEL_IDX] = 0;
  #endif
        IlResetRxTimeoutFlags(NM_CHANNEL_ILPARA_ONLY);
      }
      nmSleepModePending      = kNmTrue;

      /*-- None critical but time consuming function of IL. --------------*/
      /*-- Therefore, interrupt is released          ----------------------*/
      CanInterruptRestore();

      /*--- If interaction layer is used, start it here -------------------*/
      IlTxStart(NM_CHANNEL_ILPARA_ONLY);   /* Start Tx-Path of IL          */
      IlRxStart(NM_CHANNEL_ILPARA_ONLY);   /* Start Rx-Path of IL          */

      /*-- Lock CAN interrupt to prevent interfering from CAN-IRQ --------*/
      CanInterruptDisable();

      /*-- This is performed if COMM_ACTIVE is requested before NM_COMM_ENABLE */
      if( nmSleepMode==kNmTrue )
      {
        nmSleepMode = kNmFalse;

  #if defined( NM_ENABLE_WAKEUP_FCT )
        ApplNwmWakeup(NM_CHANNEL_APPLPARA_ONLY);                 /* call user function on wakeup  */
  #endif
      }
    /*----------------------------------------------------------------------------*/
    /*     N O T E :  No break after case NM_COMM_ENABLE                          */
    /*----------------------------------------------------------------------------*/
    /*---------------------------------------------------------*/
    case NM_COMM_ACTIVE:  /* PRQA S 2003 */ /* MD_NmGmlanGm_2003 */
    /*---------------------------------------------------------*/
      if( (nmNoComm==kNmTrue)
  #if defined( NM_ENABLE_CANOFF_ON_LOWVOLTAGE_MODE )
          &&  (nmLowVoltageMode==kNmFalse)
  #endif
        )
      {
        nmNoComm = kNmFalse;
        CanOnline(NM_CHANNEL_CANPARA_ONLY);
      }
      break;
    /*----------------------------------------------------------------------------*/
    case NM_COMM_HALTED:
    /*----------------------------------------------------------------------------*/
      nmNormalCommHalted = kNmTrue;
  #if defined(NM_ENABLE_HIGHSPEED_MODE)
    /*----------------------------------------------------------------------------*/
    case NM_HIGHSPEED_MODE:  /* PRQA S 2003 */ /* MD_NmGmlanGm_2003 */
    /*----------------------------------------------------------------------------*/
  #endif
      if( nmSleepMode==kNmTrue )
      {
        /*---- Restore old Interrupt Mask --------------------------------*/
        CanInterruptRestore();
        return;
      }
  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )
      nmSendContVnmfCnt[NM_CHANNEL_IDX] = 0;
  #endif
  #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
      defined( NM_ENABLE_VN_REMOTED )   || \
      defined ( NM_ENABLE_HIGHSPEED_MODE )
      nmTxConfirmCnt[NM_CHANNEL_IDX] = 0;
  #endif
      nmVNMFTxRequest = kNmFalse;         /* Prevent sending next NMF   */
      nmVNMFInitRequest = kNmFalse;

      nmInternalSleepMode=kNmFalse;

      nmHLVWTxTransmitted = kNmFalse;
      nmHLVWTxActive = kNmFalse; /* ESCAN00038021 */
      nmHLVWTxRequest = kNmFalse;         /* and any pending requests   */

  #if defined( NM_ENABLE_HIGHSPEED_MODE )
      if( NewNodeState == NM_HIGHSPEED_MODE )  /* PRQA S 3355,3358 */ /* MD_NmGmlanGm_3355, MD_NmGmlanGm_3358 */
      {
        CanOffline(NM_CHANNEL_CANPARA_ONLY);  /* No transmission, clear queue */
        CanInit(NM_CHANNEL_CANPARA_FIRST  NmCfg_InitObj_HighSpeed(channel));    /* Initialize CAN to HighSpeed    */
    #if defined( NM_ENABLE_SINGLEWIRE_TRCV )
        ApplTrcvrHighSpeed(NM_CHANNEL_APPLPARA_ONLY);
    #endif

        nmInternalHighSpeedMode = kNmTrue;
        nmHighSpeedMode = kNmTrue;
      }
      else
  #endif
      {
        if( NewNodeState == NM_COMM_HALTED ) /* PRQA S 3355,3358 */ /* MD_NmGmlanGm_3355, MD_NmGmlanGm_3358 */
        {
          NmStartupReset(NM_CHANNEL_NMPARA_ONLY);

          CanOffline(NM_CHANNEL_CANPARA_ONLY);       /* No transmission, clear queue */
          if( nmInternalHighSpeedMode == kNmTrue )
          {
            CanInit( NM_CHANNEL_CANPARA_FIRST  NmCfg_InitObj_Std(channel) );
          }
          ApplTrcvrNormalMode( NM_CHANNEL_APPLPARA_ONLY );

          nmInternalHighSpeedMode = kNmFalse;
          nmHighSpeedMode = kNmFalse;
        }
      }
      nmNoComm = kNmFalse;
      CanOnline(NM_CHANNEL_CANPARA_ONLY);
      break;
  #if defined( NM_ENABLE_LOWVOLTAGE_MODE )
    /*----------------------------------------------------------------------------*/
    case NM_ENTER_LOW_VOLTAGE_TOLERANT_MODE:
    /*----------------------------------------------------------------------------*/
      /* Store previous state of NM */
    #if defined( NM_ENABLE_VN_ACTIVATOR ) || \
        defined( NM_ENABLE_VN_REMOTED )   || \
        defined ( NM_ENABLE_HIGHSPEED_MODE )
      nmTxConfirmCnt[NM_CHANNEL_IDX] = 0;
    #endif
      nmVNMFTxRequest   = kNmFalse; /* prevent Tx VNMF */
      nmVNMFInitRequest = kNmFalse;
      nmLowVoltageMode  = kNmTrue;

    #if defined( NM_ENABLE_CANOFF_ON_LOWVOLTAGE_MODE )
      /* do not observe acceptance of HLVW message. */
      nmHLVWTxTransmitted = kNmFalse;

      /* turn off CAN Tx path */
      CanOffline(NM_CHANNEL_CANPARA_ONLY);
      nmNoComm = kNmTrue;
      IlTxWait(NM_CHANNEL_ILPARA_ONLY);
    #endif
      IlRxWait(NM_CHANNEL_ILPARA_ONLY);
      /* Keep current node state */
      NewNodeState = nmAction[NM_CHANNEL_IDX];
      break;
    /*----------------------------------------------------------------------------*/
    case NM_EXIT_LOW_VOLTAGE_TOLERANT_MODE:
    /*----------------------------------------------------------------------------*/
      nmLowVoltageMode = kNmFalse;
      IlRxRelease(NM_CHANNEL_ILPARA_ONLY);
    #if defined( NM_ENABLE_CANOFF_ON_LOWVOLTAGE_MODE )
      IlTxRelease(NM_CHANNEL_ILPARA_ONLY);

      /* ESCAN00023021 */
      nmRescanVn = kNmTrue;

      /* If currently not BUSOFF, re-enable communication */
      if( nmAction[NM_CHANNEL_IDX] != NM_BUSOFF )
      {
        nmNoComm = kNmFalse;
        CanOnline(NM_CHANNEL_CANPARA_ONLY);
      }
    #endif
      NewNodeState = nmAction[NM_CHANNEL_IDX];
      break;
  #endif
    /*----------------------------------------------------------------------------*/
    default:
    /*----------------------------------------------------------------------------*/
      NmAssertDirect(NMERR_ILLSTATECHANGEREQ);
      break;
  }
  nmAction[NM_CHANNEL_IDX] = NewNodeState;

  CanInterruptRestore();
} /* PRQA S 2006,4700,4700 */ /* MD_NmGmlanGm_2006, MD_NmGmlanGm_4700, MD_NmGmlanGm_4700 */

#if defined( NM_ENABLE_VN_ACTIVATOR ) || \
    defined( NM_ENABLE_VN_REMOTED )
/**********************************************************************************************************************
  Name:         NmSendWakeupMessage
  Parameter:    channel
  Return value: ---
  Description:  This function handles the transmit request for the HLVW message.
                The HLVW message may only be send if VN is inactive and if
                there was no HLVW message transmission for a certain time.
**********************************************************************************************************************/
static void NmSendWakeupMessage( NM_CHANNEL_NMTYPE_ONLY )
{
  /* check if HLVW can be transmitted */
  if( nmWakeupCnt[NM_CHANNEL_IDX] != 0 )
  {
    /* Tx of HLVW is not allowed because HLVW was Tx/Rx within the last NmCfg_LastWakeup_Cnt */
    return;
  }

  if( (nmAction[NM_CHANNEL_IDX] == NM_BUSOFF) ||
      (nmTxConfirmCnt[NM_CHANNEL_IDX] != 0)
  #if defined( NM_ENABLE_LOWVOLTAGE_MODE ) && \
      defined( NM_ENABLE_CANOFF_ON_LOWVOLTAGE_MODE )
      || (nmLowVoltageMode == kNmTrue)
  #endif
     )
  {
    /*
     *  Tx of HLVW is not allowed because either
     * - BusOff
     * - NM is in LowVoltage mode
     * . Tx of C-VNMF is ongoing 
     */
    CanInterruptDisable();
    nmHLVWTxTransmitted = kNmFalse;
    nmHLVWTxRequest = kNmTrue;           /* keep request to do the wakeup later */
    CanInterruptRestore();
    return;
  }

  if( nmNoComm!=kNmFalse )
  {
    if((nmAction[NM_CHANNEL_IDX]!=NM_BUSOFF) && (nmAction[NM_CHANNEL_IDX]!=NM_COMM_OFF)
  #if defined( NM_ENABLE_LOWVOLTAGE_MODE ) && \
      defined( NM_ENABLE_CANOFF_ON_LOWVOLTAGE_MODE )
        && (nmLowVoltageMode != kNmTrue)
  #endif
       )
    {
      nmNoComm = kNmFalse;
      CanOnline(NM_CHANNEL_CANPARA_ONLY);
    }
  }

  /*
   * Prevent Tx of C-VNMF for at least 2-times a distance between
   * HLVW and I-VNMF so that C-VNMF cannot interfere with HLVW/I-VNMF sequence (5.5.3.1.1, #11)
   */
  if( nmSendContVnmfCnt[NM_CHANNEL_IDX] < (2*NmCfg_VnmfStartSend_Cnt(channel)) )
  {
    nmSendContVnmfCnt[NM_CHANNEL_IDX] = (2*NmCfg_VnmfStartSend_Cnt(channel));
  }

  CanInterruptDisable();

  /* Tx of HLVW has succeeded. Start counter to suppress Tx HLVW during this time */
  nmWakeupCnt[NM_CHANNEL_IDX] = NmCfg_LastWakeup_Cnt(channel);

  nmHLVWTxTransmitted = kNmTrue;
  nmHLVWTxRequest = kNmFalse;

  CanInterruptRestore();

  #if defined ( NM_ENABLE_HLVW_HANDLING )
  /* transmit HLVW */
  /*
   * ESCAN00012834: Do not check the return value of CanTransmit.
   *                If the DrvCan has rejected the Tx request, the Tx will be re-requested 
   *                after NmCfg_WakeupFail_Cnt(channel) has elapsed. 
   */
  (void)CanTransmit( NmCfg_TxHndl_HLVW(channel) );
  #endif
  nmHLVWTxFailed = kNmFalse;
} /* PRQA S 2006 */ /* MD_NmGmlanGm_2006 */
#endif

/**********************************************************************************************************************
  Name:         NmSetupInitActivation
  Parameter:    channel
  Return value: ---
  Description:  This function sets relevant flags when a wakeup/poweron occurred.
**********************************************************************************************************************/
static void NmSetupInitActivation( NM_CHANNEL_NMTYPE_ONLY )
{
  #if defined( NM_ENABLE_VN_INITACTIVE )
  nmInitVnRx=kNmTrue;
  nmInitVnTx=kNmTrue;
  nmInitVnCnt[NM_CHANNEL_IDX]=(vuint8)(NmCfg_InitDelay_Cnt(channel)+1);
  #endif
  /* ESCAN00000286 */
  if (nmSendInitVnmfCnt[NM_CHANNEL_IDX] == 0)
  {
    nmSendInitVnmfCnt[NM_CHANNEL_IDX] = (vuint8)(NmCfg_VnmfStartSend_Cnt(channel)+1);
  }
}

/**********************************************************************************************************************
  Name:         NmStartupReset
  Parameter:    channel
  Return value: ---
  Description:  Initialize data structures of NM.
                Stops all currently active VNs for both Tx and Rx.
**********************************************************************************************************************/
static void NmStartupReset( NM_CHANNEL_NMTYPE_ONLY )
{
  #if defined( NM_ENABLE_VN_ACTIVATOR) || \
      defined( NM_ENABLE_VN_REMOTED )
  vsint8 vnByte;
  #endif
  vsint8 vnHndl;

  #if defined( NM_ENABLE_VN_ACTIVATOR) || \
      defined( NM_ENABLE_VN_REMOTED )
  for( vnByte=(vsint8)NmCfg_VnByte_StopIndex(channel); vnByte>=(vsint8)NmCfg_VnByte_StartIndex(channel); vnByte-- )
  {
    nmSendInit[vnByte] = 0x00;
    #if defined( NM_ENABLE_VN_ACTIVATOR )
    nmSendContinue[vnByte] = 0x00;
    #endif
  }
  #endif

 /* prevent activation of initially Active VN */
  nmInitVnRx = kNmFalse;
  nmInitVnTx = kNmFalse;

  /* iterate over all VNs */
  for( vnHndl=(vsint8)NmCfg_VN_StopIndex(channel); vnHndl>=(vsint8)NmCfg_VN_StartIndex(channel); vnHndl-- )
  {
    if( nmVnState[vnHndl]!=NmVnNone )
    {
      /* reset VN state */
      nmRescanVn = kNmTrue;
      nmVnState[vnHndl] = NmVnNone;
      nmVnTimer[vnHndl] = 0;

      /* stop signal supervision and transmission */
      (void)IlRxDeactivateVnMsgSupervision( NM_CHANNEL_ILPARA_FIRST (vuint8)vnHndl );
      (void)IlRxDeactivateVnMsg( NM_CHANNEL_ILPARA_FIRST (vuint8)vnHndl );
      (void)IlTxDeactivateVnMsg( NM_CHANNEL_ILPARA_FIRST (vuint8)vnHndl );

      /* inform application that VN is stopped */
      ApplNwmVnDeactivated( NM_CHANNEL_APPLPARA_FIRST NM_CVT_NMVNPARA_TO_APPLVNPARA(vnHndl) );
    }
  }
}

/**********************************************************************************************************************
  Name:         NmStateTask
  Parameter:    channel
  Return value: ---
  Description:  This functions handles the VN requests, starts the IL and restarts the timers.
  Note:         Status manipulation is performed within locked (CAN-)interrupts.
**********************************************************************************************************************/
static void NmStateTask( NM_CHANNEL_NMTYPE_ONLY )
{
  vsint8 vnHndl;
  /* ESCAN00023021 */
  Il_Status txActivationRval = IL_VN_ACTIVATED;

  /* abort if there are no changes in the VN states */
  if( nmRescanVn==kNmFalse )
  {
    return;
  }

  /* clear internal state variables to detect active VNs and VNMF sendout */
  nmInternalVnActive = kNmFalse;
  nmInternalNmActive = kNmFalse;

  CanInterruptDisable();
  nmRescanVn = kNmFalse;
  CanInterruptRestore();

  /* iterate over all VNs */
  for( vnHndl=(vsint8)NmCfg_VN_StopIndex(channel); vnHndl>=(vsint8)NmCfg_VN_StartIndex(channel); vnHndl-- )
  {
  #if defined( NM_ENABLE_VN_REMOTED )
    /*-- Check for restarting the VN-timer or Remotely activation ----------*/
    if( (nmVnState[vnHndl] & kNmVnRemotedPending)!=0 )
    {
    #if defined( NM_ENABLE_VN_REMOTE_ACTIVATE_REQUEST_FCT )
      /*-- With this callback function it is possible to reject -----------*/
      /*-- remote activation request from application. Extended for GMNAO -*/
      /*-- Normally, the application needs not to reject it!    -----------*/
      if( ApplNwmVnRemoteActivateRequest(NM_CHANNEL_APPLPARA_FIRST  NM_CVT_NMVNPARA_TO_APPLVNPARA(vnHndl) )==0 )
      {
        CanInterruptDisable();
        /* ESCAN00021023 */
        nmVnState[vnHndl] &= (vuint8)(~(vuintx)(kNmVnRemotedPending | kNmVnRestartTimer | kNmVnRemoteInit));
        CanInterruptRestore();
        continue;  /* PRQA S 770 */  /* MD_NmGmlanGm_770 */
      }
    #endif

      nmInternalNmActive = kNmTrue;

      /*-- Status check: Own node's VN is inactive but RemoteActivation ---*/
      /*-- request is only "Continue VN". This results in ReinitReq. VN ---*/
      if( (nmVnState[vnHndl] & (NmVnActive|kNmVnRemotedPending|kNmVnRemoteInit))==kNmVnRemotedPending )
      {
        CanInterruptDisable();
        /*-- set the VN-bit in VNMF for Init request. ----*/
        /*-- Will be cleared in Confirmation  ------------*/
        nmSendInit[NmVnByteOffset[vnHndl]] |= NmVnByteMask[vnHndl];
        nmVNMFInitRequest = kNmTrue;
        CanInterruptRestore();

    #if defined ( NM_ENABLE_REINITREQUEST_FCT )
        /*-- Application callback about reinit request ----------------*/
        ApplNwmReinitRequest( NM_CHANNEL_APPLPARA_FIRST  NM_CVT_NMVNPARA_TO_APPLVNPARA(vnHndl), 
                              NM_INTERNAL_REINIT_REQUEST );
    #endif

        /*--- Check for sending HLVW ----------------*/
        if( nmWakeupCnt[NM_CHANNEL_IDX]==0 )
        {
          /* Setup first to ensure that Init-VNMF not transmitted when CanTransmit for wakeup message fails */
          nmSendInitVnmfCnt[NM_CHANNEL_IDX] = (vuint8) (NmCfg_VnmfStartSend_Cnt(channel)+1);

          /* Send the HLVW frame only when VN is inactive and last WU > 4.5 sec */
          NmSendWakeupMessage(NM_CHANNEL_NMPARA_ONLY);
        }
      }

      /*-- Requesting an active VN to be reinitialized --------------------*/
      if(((nmVnState[vnHndl] & NmVnActive)!=0) && ((nmVnState[vnHndl] & kNmVnRemoteInit)!=0))
      {
        /*-- Request queuing of initialized VN --------------------------*/
        IlQueueVnMsg(NM_CHANNEL_ILPARA_FIRST  (vuint8)vnHndl );

    #if defined ( NM_ENABLE_REINITREQUEST_FCT )
        /*-- Application callback about reinit request -------------------*/
        ApplNwmReinitRequest( NM_CHANNEL_APPLPARA_FIRST   NM_CVT_NMVNPARA_TO_APPLVNPARA(vnHndl), 
                              NM_EXTERNAL_REINIT_REQUEST );
    #endif
      }

      CanInterruptDisable();
      /* ESCAN00021023 */
      nmVnState[vnHndl] &= (vuint8)(~(vuintx)(kNmVnRemoteInit|kNmVnRemotedPending));
      CanInterruptRestore();
    }
    /* ESCAN00038215 */
    nmVnStateInhibit[vnHndl] = 0;
  #endif

    /*-- 2nd request: Restart VN-Timer:          ---------------------------*/
    /* from Activator due to sendout of VNMF or  ---------------------------*/
    /* from remotely activation of received VNMF ---------------------------*/
    if( (nmVnState[vnHndl] & kNmVnRestartTimer)!=0 )
    {
      /*-- If timer was restarted after signal supervision is stopped, re enable it again --*/
      if ((nmVnState[vnHndl] & NmVnRxActive)==0)
      {
        /* Solves ESCAN00000434 */
        CanInterruptDisable();
        /*-- Start signal supervision ---------------------------------------*/
        if( IlRxActivateVnMsg(NM_CHANNEL_ILPARA_FIRST  (vuint8)vnHndl)!=IL_ERROR )
        {
          nmVnState[vnHndl] |= NmVnRxActive;
        }
        CanInterruptRestore();
      }

      /*-- If VN-timer is 0, this is the first activation of this VN ------*/
      if( nmVnTimer[vnHndl]==0 )
      {
        /* ESCAN00023021 */
        txActivationRval = IlTxActivateVnMsg( NM_CHANNEL_ILPARA_FIRST  (vuint8)vnHndl );
        if( txActivationRval == IL_VN_ACTIVATED )
        {
          ApplNwmVnActivated( NM_CHANNEL_APPLPARA_FIRST  NM_CVT_NMVNPARA_TO_APPLVNPARA(vnHndl));
        }
      }

      /*-- VN-timer was already below the signal supervision time. Restart it! */
      if( (nmVnTimer[vnHndl] <= (tNmVnTimer)NmCfg_VnRxTimer_Cnt(channel)) && ((nmVnState[vnHndl] & kVnLocal)==0) )
      {
        /*-- IL-function: Start Signal SuperVision -----------------------*/
        IlRxStartVnMsgSupervision(NM_CHANNEL_ILPARA_FIRST  (vuint8)vnHndl);
      }

      CanInterruptDisable();
      if( txActivationRval == IL_VN_ACTIVATED ) /* ESCAN00023021 */
      {
        /*-- Clear the request flag --*/
        nmVnState[vnHndl] &= (vuint8)(~(vuintx)(kNmVnRestartTimer));
        /*-- Set the active flag    --*/
        nmVnState[vnHndl] |=  NmVnActive;
      }
      CanInterruptRestore();

      nmInternalNmActive = kNmTrue;

      /* if NV is local stop supervision as well */
      if ((nmVnState[vnHndl] & kVnLocal)==0)
      {
        if( txActivationRval == IL_VN_ACTIVATED ) /* ESCAN00023021 */
        {
          /*-- Set timer to its initial value --*/
          nmVnTimer[vnHndl]  = (tNmVnTimer)NmCfg_VnTimer_Cnt(channel);
        }
      }
    }

  #if defined( NM_ENABLE_VN_ACTIVATOR )
    if( ((nmVnState[vnHndl] & (NmVnActivator | NmVnActivatorPending))!=0) && ((nmVnState[vnHndl] & NmVnLocal)==0) )
    {
      nmInternalVnActive = kNmTrue;
    }
  #endif

    if( (nmVnState[vnHndl] & (NmVnActive|NmVnLocal)) != 0 )
    {
      nmInternalNmActive = kNmTrue;
    }
  }

  /*-- copy new state to global state variable ------------------------------*/
  nmVnActive = nmInternalVnActive;
  nmNmActive = nmInternalNmActive;
}  /* PRQA S 2006,4700,4700 */  /* MD_NmGmlanGm_2006, MD_NmGmlanGm_4700, MD_NmGmlanGm_4700 */

#if defined( NM_ENABLE_VN_INITACTIVE )
/**********************************************************************************************************************
  Name:         NmVnInitWakeup
  Parameter:    channel
                direction       indicates, whether Tx-Msg of VN is started and/or
                                Rx-Msg enabled for reception / started for supervision.
                                kNmEnableRx - Indicates start signal supervision for Init-VN's
                                kNmEnableTx - Indicates enable send-out of msg of Init-VN
  Return value: ---
  Description:  Activate the VN's on Wakeup/InitPowerOn, defined in Gentool as Init activated.
**********************************************************************************************************************/
static void NmVnInitWakeup( NM_CHANNEL_NMTYPE_FIRST  vuint8 direction )
{
  vsint8 vnHndl;
  #if defined( NM_ENABLE_VN_ACTIVATOR )
  vsint8 vnByte;
  #endif
  
  /* iterate over all VNs */
  for( vnHndl=(vsint8)NmCfg_VN_StopIndex(channel); vnHndl>=(vsint8)NmCfg_VN_StartIndex(channel); vnHndl-- )
  {
    /* check if VN is InitActive */
    if( (NmVnTypeTable[vnHndl] & kVnInitActive)!=0 )
    {
      if( direction == kNmEnableTx )
      {
        if( (nmVnState[vnHndl] & kVnLocal)==kVnLocal )
        {
          /* 
           * If the Local VN is currently active the VN timer must be restarted here
           * since it will not be done in StateTask() 
           */
          /* reset timer */
          nmVnTimer[vnHndl] = (tNmVnTimer)NmCfg_VnTimer_Cnt(channel);
        }
        CanInterruptDisable();
        nmRescanVn = kNmTrue;
        nmVnState[vnHndl] |= kNmVnRestartTimer;
        CanInterruptRestore();
      }
      else
      {
  #if defined( NM_ENABLE_VN_ACTIVATOR)
        if( (NmVnTypeTable[vnHndl] & kVnActivator) != 0)
        /* ESCAN00013929: Only check the VNMF and activator pending status if this VN */
        /* is configured as an activator.  This check complies with GMW-3104v1.5r03   */
        /* sections 5.5.3.1 #4 and 5.5.3.1.1 #3.                                      */
        {
          CanInterruptDisable();
          /* if VN is in VNMF init frame remove it */
          if( (nmSendInit[NmVnByteOffset[vnHndl]] & NmVnByteMask[vnHndl])!=0 )
          {
            /* ESCAN00024303 */
            if( nmVNMFInitRequest != kNmTrue )
            {
              /* Remove the bit from the I-VNMF */
              nmSendInit[NmVnByteOffset[vnHndl]] &= (vuint8)(~NmVnByteMask[vnHndl]);
            }
            else
            {
              /* keep bit */
            }

            /* Prevents that the next C-VNMF comes closer than StartSendCalCnt to the HLVW */
            if (nmSendContVnmfCnt[NM_CHANNEL_IDX] < NmCfg_VnmfStartSend_Cnt(channel)) 
            {
              nmSendContVnmfCnt[NM_CHANNEL_IDX] = NmCfg_VnmfStartSend_Cnt(channel);
            }
            if ( (nmVnState[vnHndl] & NmVnActivator)==0)
            {
              /* Since VN already deactivated, remove also the bit from the C-VNMF */
              nmSendContinue[NmVnByteOffset[vnHndl]] &= (vuint8)(~NmVnByteMask[vnHndl]);
            }
          }
          /*-- Pending activation request can be cleared, because now already done here      */
          if ( (nmVnState[vnHndl] & NmVnActivatorPending) != 0)
          {
            nmVnState[vnHndl] &= (vuint8)(~(vuintx)(NmVnActivatorPending));
          }

          nmRescanVn = kNmTrue;        /* nmVnState[] changed. Rescan it --*/
          CanInterruptRestore();
        }
  #endif
        /*--- Enable reception of VN msg immediately on reception of HLVW ---*/
        if ( (nmVnState[vnHndl] & NmVnRxActive)==0 )
        {
          CanInterruptDisable();    /* Prevents nested calls to IlRxActivateVnMsg from Interrupts */
          /* In case of receiving a message before IL is started */
          if( IlRxActivateVnMsg(NM_CHANNEL_ILPARA_FIRST (vuint8)vnHndl)!=IL_ERROR )
          {
            nmVnState[vnHndl] |= NmVnRxActive;
          }
          CanInterruptRestore();
        }
      }
    }
  }

  CanInterruptDisable();

  /*-- This is called, when IL_INIT_DELAY_TIME has expired ------------------*/
  if( direction == kNmEnableTx )
  {
    nmInitVnTx = kNmFalse; /* clear until next wakeup */
  }

  /*-- This is called, immediately after wakeup/powerup ---------------------*/
  if( direction == kNmEnableRx )
  {
  #if defined( NM_ENABLE_VN_ACTIVATOR)
    /*-- Status must also be cleared if no Init-VN is used -----------------*/
    nmVNMFInitRequest = kNmFalse;

    /* iterate over all VNs */
    for(vnByte=(vsint8)NmCfg_VnByte_StopIndex(channel); vnByte>=(vsint8)NmCfg_VnByte_StartIndex(channel); vnByte-- )
    {
      /* check if there is something to be send */
      if( nmSendInit[vnByte] != 0 )
      {
        /* set Tx request */
        nmVNMFInitRequest = kNmTrue;
      }
    }
  #endif
    nmInitVnRx = kNmFalse;   /* clear until next wakeup */
  }
  CanInterruptRestore();
} /* PRQA S 4700 */  /* MD_NmGmlanGm_4700 */
#endif

/**********************************************************************************************************************
  Name:         NmVnTimerTask
  Parameter:    
  Return value: 
  Description:  This function counts down the VN timer.
                The IL handling is done depending on the timer value.
**********************************************************************************************************************/
static void NmVnTimerTask( NM_CHANNEL_NMTYPE_ONLY )
{
  vsint8 vnHndl;

  #if defined( NM_ENABLE_LOWVOLTAGE_MODE )
  if( nmLowVoltageMode == kNmTrue )
  {
    /* VN timer are not decremented in LowVoltage mode */
    return;
  }
  #endif

  /* clear status flag: will be set within this function if at least one VN is active */
  nmInternalNmActive = kNmFalse;

  /* iterate over all VNs */
  for( vnHndl=(vsint8)NmCfg_VN_StopIndex(channel); vnHndl>=(vsint8)NmCfg_VN_StartIndex(channel); vnHndl-- )
  {
    /* update VN timer */
    if( nmVnTimer[vnHndl] > 0 )
    {
      nmVnTimer[vnHndl]--;
    }

    /*--- LOCAL VN ---*/
    if( (nmVnState[vnHndl] & NmVnLocal)!=0 )
    {
      /* Activation request of a LOCAL VN by the application.
       * Either VN timer runs to 0 (delayed VN activation for Tx and supervision) 
       * or an INIT VN becomes active at the same time! */
      if( (nmVnState[vnHndl] & NmVnActivatorPending)!=0 )
      {
        if( (nmVnTimer[vnHndl]==0) || (nmVnTimer[vnHndl] > (tNmVnTimer)NmCfg_InitDelayLocal_Cnt(channel)) )
        {
          /* activate VN */
          (void)IlTxActivateVnMsg( NM_CHANNEL_ILPARA_FIRST (vuint8)vnHndl );
          /* inform application that VN is started */
          ApplNwmVnActivated( NM_CHANNEL_APPLPARA_FIRST NM_CVT_NMVNPARA_TO_APPLVNPARA(vnHndl) );
          /* inform IL to start signal supervision */
          IlRxStartVnMsgSupervision( NM_CHANNEL_ILPARA_FIRST (vuint8)vnHndl );

          CanInterruptDisable();
          nmVnState[vnHndl] &= (vuint8)(~(vuintx)(NmVnActivatorPending));
          nmRescanVn = kNmTrue;
          CanInterruptRestore();
        }
      }

      /* set a flag that at least one VN is active */
      nmInternalNmActive = kNmTrue;
    }
    else
    {
      if( (nmVnState[vnHndl] & NmVnActive)!=0 )
      {
        /* check for additional actions depending on timer status */

        /* check if VN timer runs below the signal supervision time */
        if( nmVnTimer[vnHndl] == (tNmVnTimer)NmCfg_VnRxTimer_Cnt(channel) )
        {
  #if defined( NM_ENABLE_VN_ACTIVATOR )
          if( (nmVnState[vnHndl] & NmVnActivator)!=0 )
          {
    #if defined( NM_ENABLE_VN_ACTIVATION_FAILED_FCT )
            /*-- FAULT CONDITION: Activation of VN was unsuccessful. ------*/
            /* VN-timer runs below 1 sec. and Signal supervision may  ----*/
            /* stopped. Return code of the function may decide, if VN  ----*/
            /* should be continued or further deactivated. ----------------*/
            if( ApplNwmVnActivationFailed(NM_CHANNEL_APPLPARA_FIRST NM_CVT_NMVNPARA_TO_APPLVNPARA(vnHndl)) != 0 )
            {
              CanInterruptDisable();
              nmVnState[vnHndl] |= kNmVnRestartTimer;
              nmRescanVn = kNmTrue;
              CanInterruptRestore();
              continue;  /* PRQA S 770 */  /* MD_NmGmlanGm_770 */
            }
    #endif
          }
  #endif
          /* inform IL to stop signal supervision */
          (void)IlRxDeactivateVnMsgSupervision( NM_CHANNEL_ILPARA_FIRST (vuint8)vnHndl );
        }

        /* check if VN timer has expired */
        if( nmVnTimer[vnHndl]==0 )
        {
          /* => deactivate VN */
          /* Code: necessary because of modified behavior of IL */
          (void)IlRxDeactivateVnMsgSupervision( NM_CHANNEL_ILPARA_FIRST (vuint8)vnHndl ); 
          (void)IlTxDeactivateVnMsg( NM_CHANNEL_ILPARA_FIRST (vuint8)vnHndl );
          (void)IlRxDeactivateVnMsg( NM_CHANNEL_ILPARA_FIRST (vuint8)vnHndl );
          CanInterruptDisable();
          nmVnState[vnHndl] &= (vuint8)(~(vuintx)(NmVnRxActive));

  #if defined( NM_ENABLE_VN_ACTIVATOR )
          /* check if VN has a pending request */
          if( (nmVnState[vnHndl] & NmVnActivatorPending)!=0 )
          {
            nmSendInit[NmVnByteOffset[vnHndl]] |= NmVnByteMask[vnHndl];
            nmVNMFInitRequest = kNmTrue;
          }
          else
          {
            /* reset VN state */
            nmVnState[vnHndl] = 0;
          }
  #endif
          nmVnState[vnHndl] &= (vuint8)(~(vuintx)(NmVnActive));
          nmRescanVn = kNmTrue;

          NmAssert( (((nmVnState[vnHndl] & NmVnActivatorPending)!=0) || (nmVnState[vnHndl]==0)), 
                    NMERR_VNSTATE_INCONSISTENT )/*;*/
          CanInterruptRestore();

          /* inform application that VN is stopped */
          ApplNwmVnDeactivated( NM_CHANNEL_APPLPARA_FIRST NM_CVT_NMVNPARA_TO_APPLVNPARA(vnHndl));
        }
        else
        {
          nmInternalNmActive = kNmTrue;
        }
      }
    }
  }
  nmNmActive = nmInternalNmActive;
}  /* PRQA S 2006,4700,4700 */  /* MD_NmGmlanGm_2006, MD_NmGmlanGm_4700, MD_NmGmlanGm_4700 */

#if defined( NM_ENABLE_VN_ACTIVATOR ) && \
    defined( NM_ENABLE_RECOVER_VN_AFTER_BUSOFF )
/**********************************************************************************************************************
  Name:         NmVnmfRecoveryFromBusoff (*)
  Parameter:    NM channel
  Return value: ---
  Description:  This function recovers those VNs where the node is activator and the VN timer has gone below 4 sec.
  Note:         Must be called with locked interrupts
**********************************************************************************************************************/
static void NmVnmfRecoveryFromBusoff( NM_CHANNEL_NMTYPE_ONLY )
{
  vsint8 vnHndl;

  /* iterate over all VNs */
  for( vnHndl=(vsint8)NmCfg_VN_StopIndex(channel); vnHndl>=(vsint8)NmCfg_VN_StartIndex(channel); vnHndl-- )
  {
    /* check if current VN is activator and the VN timer is less than 4s */
    /* ESCAN00014844: check if Tx of HLVW failed */
    if ( ((nmVnState[vnHndl] & NmVnActivator)!=0) &&
         ((nmVnTimer[vnHndl] < (tNmVnTimer)NmCfg_VnRxTimer_Cnt(channel)) ||
          (nmHLVWTxFailed == kNmTrue)) )
    {
      /* set the VN bit in I-VNMF */
      nmSendInit[NmVnByteOffset[vnHndl]] |= NmVnByteMask[vnHndl];
      nmVNMFInitRequest = kNmTrue;
    }
  }

  if( nmVNMFInitRequest != kNmFalse )
  {
    if( nmWakeupCnt[NM_CHANNEL_IDX] == 0 )
    {
      /* ensure that I-VNMF is not transmitted when CanTransmit for wakeup message fails */
      nmSendInitVnmfCnt[NM_CHANNEL_IDX] = (vuint8)NmCfg_VnmfStartSend_Cnt(channel);

      /* try to transmit HLVW */
      NmSendWakeupMessage(NM_CHANNEL_NMPARA_ONLY);
    }
  }
}
#endif

/* module specific MISRA deviations:
   MD_NmGmlanGm_488:
     Reason: pointer arithmetic used by DrvCan
     Risk: Mistake by pointer arithmetic
     Prevention: Cover by code review
   MD_NmGmlanGm_715:
     Reason: Nesting depth is used to keep code maintainable
     Risk: Some compilers could have problems with this nesting depth.
     Prevention: Not true for used compiler.
   MD_NmGmlanGm_759:
     Reason: Usage of union type allows more efficient access on flag array
     Risk: Unions are used.
     Prevention: Cover by code review
   MD_NmGmlanGm_770:
     Reason: Continue-statement used to shorten runtime 
     Risk: Continue statement is used.
     Prevention: Cover by code review
   MD_NmGmlanGm_2003:
     Reason: Break-statement not used as this case is part of the predecessor
     Risk: Unexpected behaviour in switch statement
     Prevention: Cover by code review
   MD_NmGmlanGm_2006:
     Reason: Multiple return paths used to keep control flow short
     Risk: Unexpected control flow possible.
     Prevention: Cover by code review
   MD_NmGmlanGm_3199:
     Reason: Dummy assignment for unused parameter
     Risk: Increased memory resources if not optimized by compiler.
     Prevention: Cover by code review
   MD_NmGmlanGm_3333:
     Reason: Break-statement used to shorten runtime
     Risk: Break statement is used.
     Prevention: Cover by code review
   MD_NmGmlanGm_3355:
     Reason: The following code is only to be executed if the case has been entered normally. Due to the missing break statement of the case before, this is not always true.
     Risk: N/A
     Prevention: Cover by code review
   MD_NmGmlanGm_3358:
     Reason: The following code is only to be executed if the case has been entered normally. Due to the missing break statement of the case before, this is not always true.
     Risk: N/A
     Prevention: Cover by code review
   MD_NmGmlanGm_412:
     Reason: Assertion function is configurable => this results in unknown code fragment
     Risk: 
     Prevention: Cover by code review
   MD_NmGmlanGm_3453:
     Reason: Using macros allows more compact source code
     Risk: Macros are used.
     Prevention: Cover by code review
   MD_NmGmlanGm_3673:
     Reason: prototype can't be changed because defined by DrvCan
     Risk: N/A
     Prevention: N/A
   MD_NmGmlanGm_4700:
     Reason: Metric deviation is only for information purpose.
     Risk: N/A
     Prevention: N/A: Only information
*/

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
/* ORGANI: STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
