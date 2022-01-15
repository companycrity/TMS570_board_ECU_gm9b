/* Kernbauer Version: 1.14 Konfiguration: Il_Vector_Gm Erzeugungsgangnummer: 607 */

/* STARTSINGLE_OF_MULTIPLE */
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2000-2010 by Vector Informatik GmbH. All rights reserved.
 
                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  Il_Def.h
      Project:  Il_Vector
       Module:  -
    Generator:  -

  \brief Description:  Vector Interaction Layer source file
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
-----------------------------------------------------------------------------------------------------------------------
  Heike Honert                  Ht            Vector Informatik GmbH
  Stephan Hoffmann              Hn            Vector CANtech, Inc.
  Armin Happel                  Hp            Vector Informatik GmbH
  Gunnar de Haan                dH            Vector Informatik GmbH
  Bernd Stumpf                  Stu           Vector Informatik GmbH	
  Thomas Ebert                  Et            Vector Informatik GmbH
  Werner Ziegler                Zw            Vector Informatik GmbH
  Thomas Petrus                 Pet           Vector Informatik GmbH
  Ralf Fritz                    Fz            Vector Informatik GmbH
  Gunnar Meiss                  Ms            Vector Informatik GmbH
  Marc Rauscher                 Mra           Vector Informatik GmbH
  Frank Triem                   Tri           Vector Informatik GmbH
  Todd Emaus                    Tde           Vector CANtech, Inc.
  Hartmut Hoerner               Hh            Vector Informatik GmbH
  Patrick Markl                 Ml            Vector Informatik GmbH
  Sebastian Waldvogel           Swa           Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  03.00.00  2000-05-08  Ht                    Creation of Vector IL derived from GMLAN Interaction Layer V2.30
  03.01.00  2000-06-16  Ht                    signal-sendtype "ifActive" added
  03.02.00  2000-06-28  Bd                    InitIfActiveFlags call with channelindex ()
  03.03.00  2000-09-05  Ht                    some comment changed
                                              -IlRxStop: supend before defaultvalues
  03.10.00  2000-10-30  Ht                    -adaption to CAN driver with channel index
                                              -call of InitIfActiveFlags only if cyclic event enabled
  03.11.00  2000-11-22  Ht                    parameter channel add in several macros (Reset...)
            2000-12-19  Hn                    -single channel version didn't compile 
                                              -some macros exist now in a multi- and a single-channel version 
  03.12.00  2001-04-12  Ht                    -configurable start of timeout monitoring 
                                              -support of bugfix version added
                                              -bugfix in IlRxTask if Rx is suspend
                                              -bugfix in code douppling
                                              -C_ENABLE_TIMEOUT_DELAY changed to IL_ENABLE_RX_TIMEOUT_DELAY 
            2001-04-20  Ht                    -const -> MEMORY_ROM 
                                              -adaption of functions to Keil C5x5
  03.20.00  2001-06-01  Ht                    -new features:
                                              -Tx: Timeout, Defaultvalues, Send on Init
                                              -Rx: Start-Defautvalues, DataChanged
                                              -indication if rx is waiting
  03.21.00  2001-06-08  Ht                    -modified Tx timeout behaviour    
  03.22.00  2001-08-27  Ht      ESCAN00001154 RxStopDefaultValue will not be set in all cases
                                ESCAN00001340 support mode signals
                                ESCAN00001345 Initialisation of data buffers (second or higher channel) went wrong
                                ESCAN00001361 Parameter type of _memclr and _memcpy changed to (void *) 
  03.23.00  2001-09-09  Ht      ESCAN00001416 Elimination of comiler warnings - Tricore
                                ESCAN00001417 Support Multiple receive channel driver
  03.24.00  2001-09-12  Ht      ESCAN00001448 Elimination of compiler warnings - state macros
  03.25.00  2001-11-15  Hp      ESCAN00002245 Merge GMLAN-IL with Vector-IL.
                                              Adding GMLAN V3.0 related features.
  03.26.00  2001-11-20  Hp                    -Gm-Only :
                                              -New interface function indicates learned message source address.
                                              -Learned source address only indicated when new.
                                              -Bugfix for VN-array initialisation.
                                              -Support for physical Multi-ECU configuration.
            2002-01-30  Ms      ESCAN00002188 IlRxTask calls IlRxGenTask only if RxEnabled
  03.27.00  2002-02-07  Ht      ESCAN00001760 insert module specific define
                                ESCAN00002395 DataChanged Flags are not reset in IlRxStart()
                                ESCAN00002303 Initialization for Multiplex signals
                                ESCAN00002305 Linker error for function _memcpy
                                ESCAN00002399 Initialization of Rx default values went wrong
                                ESCAN00002400 _memcpy missing if default values are used only on the second channel
  03.28.00  2002-02-25  Hp      ESCAN00002252 New callback function for dynamic source address learning.
                                              Revised timeout supervision for learned Extended-IDs
            2002-03-06  Hp      ESCAN00002428 Split the tasks and call message functions individually.
  03.30.00  2002-04-23  Ht      ESCAN00002199 Export extern declarations from IL.c to IL_def.h
                                ESCAN00002604 If no rx-timeout control is used, the IL cannot be compiled
                                ESCAN00002638 extern declaration of IlRxMsgECUMask changed  
                                ESCAN00002689 one call cycle missing for Start delay time
                                ESCAN00002713 Support the new features with multi channel systems
                                ESCAN00002714 Reset RxTimerFlags in IlRxRelease()
                                ESCAN00002715 Support systems without Tx or Rx messages
                                ESCAN00002716 ID priority of Tx messages could be inverted
            2002-04-29  Hp                    Signal supervision fail indication when new msgs on a VN become active
            2002-05-15  Hp                    Gm-Only : Minor corrections for GMLAN in IlTxTimerTask() and IlDequeueNonActiveTxMessages
                                              Gm-Only : start implementing indexed version
                                              Correct the check for max. number of nodes when learning a new address.
            2002-05-15  Pl                    comMultipleECUCurrent channel-index added
            2002-06-20  dH                    added some missing 
  03.32.00  2002-06-17  Ht      ESCAN00003075 Unexpected Rx-Timeout notification in MultiECU systems
                                ESCAN00002791 PowerOn initialization
                                ESCAN00002956 signal irelated start, stop and init callback functions
                                ESCAN00002976 additional get function for indication flags access
            2002-07-08  Stu                   Bugfix for initialisation of index and mask in IlTxTimerTask
  03.33.00  2002-09-09  Et      ESCAN00003694 support STmicro ST7 (beCAN) / Hiware
            2002-09-27  Ht      ESCAN00003839 Disabled Transmission for a single message
            2002-04-11  Hp/Fz   ESCAN00004086 Side-effects when clearing VN-related bits in VN- and  Msg -arrays for indexed systems 
                                ESCAN00004088 Side-effects for Indexed-systems when deactivating VNs 
                                ESCAN00003653 Incomplete code loop in IlTxTimerTask for multiple identity ECUs
                                ESCAN00004085 Speed optimisation
                        Si      ESCAN00004084 support for systems with Tx-Signals or Rx-Signals only added
                        Hp      ESCAN00004099 Function added that provides the status of an NCA
  03.35.00  2002-11-06  Hp      ESCAN00004124 Gm-Only : Compile error for function IlGetNodeCommActiveState() 
                                              for GMLAN without Extended-IDs
            2002-12-05  Pet     ESCAN00004364 wrong define for 8Bit CPU
  03.35.01  2002-12-18  Pet     ESCAN00004495 rx indirection check not needed when indirection index search is used
  03.36.00  2003-05-04  Fz      ESCAN00004484 Timeoutnotification for VN start changed
                                ESCAN00004424 Code optimization for transmission without Repetition
                                ESCAN00004621 Problem in macro IlClrChannelReceived removed  
                                ESCAN00004665 Gm-Only : Wrong index into structure used
                                ESCAN00004715 Gm-Only : Compiler failure removed
                        Hp      ESCAN00004740 Add a function that clears the Timeout indication for receive signals
                        Ms      ESCAN00004956 PClint comments to avoid unauthorized Warnings
                        Mra     ESCAN00005013 Fixed missing  inside of the IlCanGenericPrecopy function
                        Ms      ESCAN00004413 warning from TI TMS470 Compiler
                                ESCAN00003525 memory qualifier for zero page mapping - HC08
                                ESCAN00004662 Size of "extern" object 'IlIndicationOffset' is unknown
                        Fz      ESCAN00005215 Gm-Only : Some assertions modified
                        Ht      ESCAN00002196 Improve Runtime for default values setting of RxSignals in Multiple ECU's
                                ESCAN00004205 Support  for Dual Rate Messages
                                ESCAN00004559 Optimisation for IlRxStateTask not working on indexed  multi channel systems
                                ESCAN00004652 PSA specific timer handling for Periodic and Event triggered messages is not supported by IL 
                                ESCAN00005214 avoid compiler warning in IlRxStateTask about unused parameter
                                ESCAN00005463 Setting of TxDefaultvalue could fail
                        Fz      ESCAN00005552 Gm-Only : Timeout value reload changed in IlRxRelease for source learning
  03.37.00  2003-05-12  Ht      ESCAN00005627 setting of RxStart and RxStop Default Values could fail
                        Fz      ESCAN00005560 Gm-Only : Incorrect reception handling of application messages in a Multiple-ECU environment
  03.38.00  2003-05-15  Tri     ESCAN00005676 Implementing memory qualifier V_MEMROM0
  03.39.00  2003-07-16  Tri     ESCAN00006095 V_MEMROM0 not used at pointer to constants
                        Ht      ESCAN00005851 Memory access may fail with Physical Multiple ECU 
                                ESCAN00005852 suppressed transmission after cancelation of a message
                        Hp      ESCAN00005993 Change bit-order for IlVnTxSendOnInit[].
                        Ms      ESCAN00006033 Critical Indirections with more than 255 CAN messages
  03.40.00  2003-07-22  HH      ESCAN00005747 use type cast in front of ~ to prevent compiler warnings
                        HH      ESCAN00005823 added dummy statement in IlResetRxTimeoutFlags.
                        HH      ESCAN00003627 added special prototype for _memcpy for Keil compiler C5x5
                        HH      ESCAN00006157 MISRA compliance improved
                        HH      ESCAN00005996 IlUintType replaced by vuintx
                        HH      ESCAN00006275 missing  in IlRxStartVnMsgSupervision
                        HH      ESCAN00006246 compiler warnings M32C
  03.41.00  2003-08-11  Hp      ESCAN00006202 enabled reception on all indexed channels.
                                ESCAN00006334 Gm-Only : Disallow message reception too early
  03.42.00  2003-08-15  Fz      ESCAN00006391 Gm-Only : Argument check wrong
  03.43.00  2003-08-29  Hp      ESCAN00006483 Gm-Only : Return on fail condition of State-handler
                                              when activating VN's. More checks for VN-Nr in indexed systems.
                                ESCAN00006490 Gm-Only : SourceLearning correction in Multi-Channel indexed systems.
  03.44.00  2003-09-08  Hp      ESCAN00006549 Gm-Only : SourceLearning recovery failure in indexed-multi channel sytems
  03.45.00  2003-09-16  Fz      ESCAN00006614 Gm-Only : Source failed notification will not be done 
  03.46.00  2003-09-29  Fz      ESCAN00006700 Gm-Only : Source failed recovery will not be done after source is
                                              learned and VN(s) where deactivated and reactivated
  03.47.00  2003-11-10  Fz/Hp   ESCAN00006830 Gm-Only : Timeout recovery and notification for signals is not done
                                              on multi channel indexed systems.
  03.48.00  2004-01-16  Fz/Tde/Ms
                                ESCAN00006990 Add of TMS320 support
            2003-11-21  Ms      ESCAN00005823 moved dummy statement in IlResetRxTimeoutFlags
  03.49.00  2003-12-11  HH      ESCAN00007143 use V_MEM_* instead of MEMORY_ROM
                        Fz      ESCAN00007274 Gm-Only : Possible message burst after normal com hold released
            2004-02-10  Ms      ESCAN00007506 Set Rx and Tx Default Values at Start or Stop
            2004-03-01  Ms                    adapted Memory Qualifier
            2004-03-02  Ms                    adapted Version Handling
  03.50.00  2004-04-02  HH                    improved MISRA compliance, uses vstdlib instead of own functions
                                ESCAN00006119 since std lib functions are not provided by the IL any more this
                                              not applicable any more
                                ESCAN00007434 added PSA specific behaviour to avoid setting TxSendRequest
                                              in part offline state when CanTransmit is called
                                ESCAN00000815 common module functions _memcpy and _memclr
            2004-05-24  Fz      ESCAN00008453 Gm-Only : IlClrFlagsMSB2LSB and IlClrFlagsLSB2MSB changed
                                ESCAN00008452 Init of array ilVnTxMessageEnable changed
  03.51.00  2004-07-08  Fz      ESCAN00008800 Gm-Only : Missing variable initialization
                                ESCAN00008538 Gm-Only : Send on init not calibrate able
                                ESCAN00008856 Gm-Only : Wrong notification about failed source
  03.52.00  2004-11-17  Fz      ESCAN00009802 Gm-Only : Issue due to change ESCAN00008453 solved
                        Ms      ESCAN00009576 Replace NULL by V_NULL
                                ESCAN00009575 Remove C_COMP_FJVGC
                                ESCAN00009613 Runtime Improvement IlTxStartCycles
                                ESCAN00009616 Conceptional common usage of function pointer tables 
                                             in IlTxConfirmationFctPtr and IlCanRxIndicationFctPtr
                                ESCAN00009633 Naming Conventions
                                ESCAN00007483 Wrong access to indication and confirmation flags of the CAN driver
                                ESCAN00009836 CanGetChannelOfTxObj <-> CanTxMsgHandleToChannel
                                ESCAN00006085 Add Nullpointers and Assertions
                                ESCAN00009889 Remove Useless (IltTxCounter) Cast
                                ESCAN00010057 No changes here
  04.00.00  2005-06-15  Fz      ESCAN00012536 Gm-Only : Dummy functions are not longer generated.
                                              Parts which have used this assumtion changed
                        Ms      ESCAN00010691 Improve MISRA Compliance
                        Ms      ESCAN00010404 Runtime improvement in IlRxStart
                        Ms      ESCAN00010403 IlResetCanIndicationFlags Preprocessor encapsulation
                        Ms      ESCAN00010709 Invalid Confirmation Notification and StartDelay time for Multiplex Messages
                        Ms      ESCAN00010701 Not GM: Activate ApplIlInit extern declaration
                        Ms      ESCAN00010704 Remove IL_NO_COMPATIBILITY
                        Ms      ESCAN00010825 Simplify the macros to modifiy the IL state
                        Ms      ESCAN00010609 IlRxFirstvalueFlagsStartIndex Spelling
                        Ms      ESCAN00010690 Geny Compatibility
                        Ms      ESCAN00008116 Dynamic Rx Timeouts
                        Ms      ESCAN00008651 SetTxDefaultMask
                        Ms      ESCAN00012393 No changes here
                        Ms      ESCAN00008455 No changes here
                        Fz      ESCAN00011748 Gm-Only : IlClrFlagsMSB2LSB and IlClrFlagsLSB2MSB changed
                        Ms      ESCAN00012640 Support of "No Buffer" configurations
  04.01.00  2005-08-02  Ms      ESCAN00012851 Out of Bounds
                        Ms      ESCAN00012946 Geny: Standard Multiplex Interface
                        Ms      ESCAN00013024 Geny: kIlNumberOfRxIndicationBits used, but not defined
                        Ms      ESCAN00013049 Adapt local/parameter memory qualifiers
                        Fz      ESCAN00012988 Gm-Only : Interface of function IlGetRxMessageSourceAddress changed
  04.02.00  2005-12-07  Ms      ESCAN00013387 added FastOnStart for muliplexed messages
                        Ms      ESCAN00013712 added AUTOSAR Pdu Interface
                        Ms      ESCAN00013963 ilTxState in IlSendOnInitMsg
                        Ms      ESCAN00014359 SetTxDefaultWithMask prototype preprocessor encapsulation
                        Ms      ESCAN00014419 Init Default Values (Tms320)
                        Ms      ESCAN00014536 Init Dynamic Timeouts
                        Ms      ESCAN00014539 Invalid Confirmation Notification and StartDelay time for Multiplex Messages
  04.03.00  2005-12-20  Ms      ESCAN00014630 Add Il Rx/Tx Polling for the AUTOSAR PduRouter Interface
  04.04.00  2006-02-23  Ms      ESCAN00014829 No changes here
                        Ms      ESCAN00014880 Implicit cast in state transition macros
                        Ms      ESCAN00015290 No changes here
                        Ms      ESCAN00015456 [SR:033] Add GENy physical multiple ecu support
                        Ms      ESCAN00015457 [SR:034] Add Dynamic Cycle Time at Init
  04.05.00  2006-03-20  Fz      ESCAN00015656 GM-Only: Compiler Error in IlNodeCommActiveFailed
                        Fz      ESCAN00015622 GM-Only: Compiler Error re-definition of NULL
                        Ms      ESCAN00015682 [SR:032] Signal Group API for GENy
                        Ms      ESCAN00015502 No changes here
  04.06.00  2006-04-10  Ms      ESCAN00015892 No changes here
                        Ms      ESCAN00015139 [SR:037] IlSendDirect
                        Ms      ESCAN00016071 No changes here
                        Fz      ESCAN00016041 Compiler error removed for ST7 with Cosmic
  04.07.00  2006-06-14  Ms      ESCAN00015850 IlTxTask call for channels without Il messages
                        Ms      ESCAN00016430 No changes here
  04.08.00  2006-06-27  Ms      ESCAN00013964 GenMsgDelayTime is not taken into account
                        Ms      ESCAN00016729 Transmission Events in IlStartCycle and IlStopCycle
                        Ms      ESCAN00016614 Com_TriggerTransmit AUTOSAR 2.0
                        Ms      ESCAN00016933 GM-Only: No changes here
  04.09.00  2007-04-11  Ms      ESCAN00018540 No changes here
                        Ms      ESCAN00018622 No changes here
                        Ms      ESCAN00019703 GM-Only: No changes here
                        Ms      ESCAN00019849 GM-Only: Unreferenced static functions
                        Ms      ESCAN00020000 IlCanGenericPrecopy Dummy Statement
                        Fz      ESCAN00020134 GM-Only: Unused variables warnings removed
                        Ms      ESCAN00020234 GM-Only: IlNwmInit Preprocessor encapsulation
                        Ms      ESCAN00020235 No changes here
  04.10.00  2007-05-10  Ms      ESCAN00013075 Add IlGetModuleContext/IlSetModuleContext
                        Ms      ESCAN00020730 ilPduRxIndicationFlags prototype declaration
                        Ms      ESCAN00021203 GM-Only: Multiple Channel: timeout flag, function or default value
  05.00.00  2008-01-10  Ms      ESCAN00021361 No changes here
                        Ms      ESCAN00021245 No changes here
                        Ms      ESCAN00021696 No changes here
                        Ms      ESCAN00021708 Rx timeout flag is set, message/signal timeout function is called or default value is set
                        Ms      ESCAN00021271 No changes here
                        Ms      ESCAN00022375 IlStartCycle and IlStopCycle without Tx messages
                        Ms      ESCAN00023206 Split Oem Extensions
                        Ms      ESCAN00023270 No changes here
                        Ms      ESCAN00023300 Remove Signal Group Buffer Reset
                        Ms      ESCAN00023284 Alterable Memory for Tx Default Value
                        Ms      ESCAN00023821 Message Transmission Stops
                        Ms      ESCAN00023822 GM-Only: Message Transmission Stops
  05.01.00  2008-01-25  Ms      ESCAN00023109 PSA-Only: Remove Cyclic Messages Period Reset In An Event Transmission
  05.02.00  2008-04-21  Ms      ESCAN00026301 No changes here
            2008-07-17  Ms      ESCAN00025002 IlStartCycle and IlStopCycle return value without Tx messages
                        Ms      ESCAN00028780 Detect Repetition and Signal Activity
                        Ms      ESCAN00025178 Reset Timeout Flags On Release
                        Ms      ESCAN00013854 Support C_COMP_IAR_M16C for Compiler Version >= 3.00
  05.02.01  2008-10-17  Ms      ESCAN00029307 No changes here
                        Ms      ESCAN00030750 No changes here
  05.02.02  2009-08-28  Ml      ESCAN00037350 No changes here
  05.03.00  2009-11-19  Swa     ESCAN00039257 No changes here
                        Swa     ESCAN00039071 Added dummy statement in IlTxRepetitionsAreActive.
                        Swa     ESCAN00039274 No changes here
            2010-04-20  Swa     ESCAN00042420 No changes here
  05.04.00  2010-06-14  Swa     ESCAN00043305 Compile error in IlTxRepetitionsAreActive 
            2010-06-28  Ms      ESCAN00042424 Reload the Cyclic Timer after a successful Transmission Request
**********************************************************************************************************************/
#if defined ( IL_TYPE_GM )
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2000-2009 by Vector Informatik GmbH. All rights reserved.
 
                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  Il_Def.h
      Project:  Il_Vector_Gm
       Module:  -
    Generator:  -

  \brief Description:  Vector Interaction Layer Gm source file
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
-----------------------------------------------------------------------------------------------------------------------
  Gunnar Meiss                  Ms            Vector Informatik GmbH
  Sebastian Waldvogel           Swa           Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  01.00.00  2007-06-14  Ms      ESCAN00023204 Creation
            2007-12-03  Ms      ESCAN00023444 Rx indication and timeout notification
            2007-12-05  Ms      ESCAN00023551 Rx Nca IlCanGenericPrecopy
  01.00.01  2008-04-08  Ms      ESCAN00025874 Source Address Based Timeout Supervision Restart
  01.00.02  2008-07-30  Ms      ESCAN00013854 Support C_COMP_IAR_M16C for Compiler Version >= 3.00
            2009-02-18  Ms      ESCAN00033184 Update Il_Vector Core to Package 6.01.03
  01.00.03  2010-05-06  Swa     ESCAN00042787 Update Il_Vector Core to Package 6.02.00
  01.00.04  2010-07-01  Swa     ESCAN00043389 Update Il_Vector Core to Package 6.03.00
  01.00.05  2010-09-02  Ms      ESCAN00044234 Virtual Network Messages are not activated or deactivated
  01.00.06  2010-09-27  Ms      ESCAN00045554 Virtual Network Messages are not activated or deactivated
**********************************************************************************************************************/
#endif /* IL_TYPE_GM */

/*lint -function(exit,ApplIlFatalError)*/

#define V_IL_VECTOR_COMPONENT_SOURCE

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "il_inc.h"
#if defined ( IL_TYPE_GM )
#endif /* IL_TYPE_GM */

/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/
#if( IL_VECTOR_VERSION != 0x0504 )
# error "Source and Header file are inconsistent!"
#endif
#if( IL_VECTOR_RELEASE_VERSION != 0x00 )
# error "Source and Header file are inconsistent!"
#endif
#if defined ( IL_TYPE_GM )
# if( IL_VECTOR_GM_VERSION != 0x0100 )
#  error "Source and Header file are inconsistent!"
# endif
# if( IL_VECTOR_GM_RELEASE_VERSION != 0x06 )
#  error "Source and Header file are inconsistent!"
# endif

/* Il_Vector-Implementation Compatibility Check */
# if !defined( IL_VECTOR_VERSION )
#  error "Incompatible Il_Vector-Implementation with this Il_Vector_Gm-Implementation. IL_VECTOR_VERSION has to be defined!"
# endif
# if !defined( IL_VECTOR_RELEASE_VERSION )
#  error "Incompatible Il_Vector-Implementation with this Il_Vector_Gm-Implementation. IL_VECTOR_RELEASE_VERSION has to be defined!"
# endif
# if defined( IL_VECTOR_VERSION ) && defined( IL_VECTOR_RELEASE_VERSION )
#  if ( IL_VECTOR_VERSION < 0x0500 )
#   error "Incompatible Il_Vector-Implementation with this Il_Vector_Gm-Implementation!"
#  else
#   if ( IL_VECTOR_RELEASE_VERSION < 0x00 )
#    error "Incompatible Il_Vector-Implementation with this Il_Vector_Gm-Implementation!"
#   endif
#  endif
# endif
#endif /* IL_TYPE_GM */

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/
#if defined ( IL_TYPE_GM )
# if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
/** \defgroup IlNodeCommActiveFailedReturnValue
    \brief The defines are used as constant return values of IlNodeCommActiveFailed. */
/**\{*/
/** This is the return value of IlNodeCommActiveFailed, if a timeout event has been triggered. */
#  define kIlTimeoutEvent      (vuintx)0
/** This is the return value of IlNodeCommActiveFailed, if NO timeout event has been triggered. */
#  define kIlNoTimeoutEvent    (vuintx)1
/**\}*/
# endif

# if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
/** This is the return value of IlGetSourceAddressIndex, if the source address has not been found in ilExtIdRxLearnedSourceAddresses */
#  define IL_NODE_ADDRESS_UNKNOWN  (vuint8)0xFF

#  if ( kIlNrOfSourceAddresses > 254 )
#   error "Error in il.c: kIlNrOfSourceAddresses must be < 255 due to the definition of IL_NODE_ADDRESS_UNKNOWN!"
#  endif

# endif/* IL_ENABLE_RX_EXT_TIMEOUT */
#endif /* IL_TYPE_GM */

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  ModifyChannelState
**********************************************************************************************************************/
/** \defgroup ModifyChannelState
    \brief    These macros shall be used to modify ilChannelState.
    \param    channel      Handle of the CAN channel.
    \return   none */
/**\{*/
/** Set the rx state machine to running */
#define EnableRx(channel)    (Il_ChannelState((channel)) = (vuint8)(((vuint8)(Il_ChannelState((channel)) & kIlIsNotRxWait)) | kIlIsRxRun))
/** Set the tx state machine to running */
#define EnableTx(channel)    (Il_ChannelState((channel)) = (vuint8)(((vuint8)(Il_ChannelState((channel)) & kIlIsNotTxWait)) | kIlIsTxRun))
/** Set the rx state machine to waiting */
#define WaitRx(channel)      (Il_ChannelState((channel)) = (vuint8)(((vuint8)(Il_ChannelState((channel)) & kIlIsNotRxRun)) | kIlIsRxWait))
/** Set the tx state machine to waiting */
#define WaitTx(channel)      (Il_ChannelState((channel)) = (vuint8)(((vuint8)(Il_ChannelState((channel)) & kIlIsNotTxRun)) | kIlIsTxWait))
/** Set the rx state machine to suspended */
#define SuspendRx(channel)   (Il_ChannelState((channel)) = (vuint8)(((vuint8)(Il_ChannelState((channel)) & kIlIsNotRxRun)) & kIlIsNotRxWait))
/** Set the rx state machine to suspended */
#define SuspendTx(channel)   (Il_ChannelState((channel)) = (vuint8)(((vuint8)(Il_ChannelState((channel)) & kIlIsNotTxRun)) & kIlIsNotTxWait))
/**\}*/

/**********************************************************************************************************************
  DecodeChannelState
**********************************************************************************************************************/
/** \ingroup DecodeChannelState */
/**\{*/
/** Tx is running */
#define TxEnabled(channel)      ((Il_ChannelState((channel)) & kIlIsTxRun) != 0)
/** Rx is waiting */
#define RxWaiting(channel)      ((Il_ChannelState((channel)) & kIlIsRxWait) != 0)
/** Tx is waiting */
#define TxWaiting(channel)      ((Il_ChannelState((channel)) & kIlIsTxWait) != 0)
/** Tx is suspended */
#define TxSuspended(channel)    ((Il_ChannelState((channel)) & (kIlIsTxRun | kIlIsTxWait)) == 0)
/** Tx is not suspended */
#define TxNotSuspended(channel) ((Il_ChannelState((channel)) & (kIlIsTxRun | kIlIsTxWait)) != 0)
/** Rx is not suspended */
#define RxNotSuspended(channel) ((Il_ChannelState((channel)) & (kIlIsRxRun | kIlIsRxWait)) != 0)
/**\}*/

#if defined( C_ENABLE_GENERIC_PRECOPY )
/**********************************************************************************************************************
  ModifyChannelReceive
**********************************************************************************************************************/
/** \defgroup ModifyChannelReceive
    \brief    These macros shall be used to modify ilChannelReceive.
    \param    channel      Handle of the CAN channel.
    \return   IlGetChannelReceived : none\n
              IlGetChannelReceived : ilChannelReceive\n
              IlClrChannelReceived : none */
/**\{*/
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define IlSetChannelReceived(channel)      (ilChannelReceive[(channel)] = 0x01)
#  define IlGetChannelReceived(channel)      (ilChannelReceive[(channel)])
#  define IlClrChannelReceived(channel)      (ilChannelReceive[(channel)] = 0x00)
# else
#  define IlSetChannelReceived(channel)      (ilChannelReceive =  0x01)
#  define IlGetChannelReceived(channel)      (ilChannelReceive)
#  define IlClrChannelReceived(channel)      (ilChannelReceive =  0   )
# endif
/**\}*/
#endif /* C_ENABLE_GENERIC_PRECOPY */

/**********************************************************************************************************************
  ClearStatusFlags
**********************************************************************************************************************/
/** \defgroup ClearStatusFlags
    \brief    These macros shall be used to clear status flags.
    \param    channel      Handle of the CAN channel.
    \return   none */
/**\{*/
#if defined IL_ENABLE_TX_TIMEOUT_FLAG
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetTxTimeoutFlags(channel)        (VStdMemNearClr(&ilTxTimeoutFlags[IlTxTimeoutFlagsStartIndex[(channel)]],(vuint8)(IlTxTimeoutFlagsStartIndex[(channel)+1]-IlTxTimeoutFlagsStartIndex[(channel)])))
# else
#  define ResetTxTimeoutFlags(channel)        (VStdMemNearClr(ilTxTimeoutFlags,(vuint8)kIlNumberOfTxTimeoutFlags))
# endif
#else
# define ResetTxTimeoutFlags(channel)
#endif

#if defined IL_ENABLE_TX_CONFIRMATION_FLAG
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetConfirmationFlags(channel)     (VStdMemNearClr(&ilTxConfirmationFlags[IlTxConfirmationFlagsStartIndex[(channel)]],(vuint8)(IlTxConfirmationFlagsStartIndex[(channel)+1]-IlTxConfirmationFlagsStartIndex[(channel)])))
# else
#  define ResetConfirmationFlags(channel)     (VStdMemNearClr(ilTxConfirmationFlags,(vuint8)kIlNumberOfTxConfirmationFlags))
# endif
#else
# define ResetConfirmationFlags(channel)
#endif

#if defined IL_ENABLE_RX_TIMEOUT_FLAG
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetRxTimeoutFlags(channel)        (VStdMemNearClr(&ilRxTimeoutFlags[IlRxTimeoutFlagsStartIndex[(channel)]],(vuint8)(IlRxTimeoutFlagsStartIndex[(channel)+1]-IlRxTimeoutFlagsStartIndex[(channel)])))
# else
#  define ResetRxTimeoutFlags(channel)        (VStdMemNearClr(ilRxTimeoutFlags,(vuint8)kIlNumberOfRxTimeoutFlags))
# endif
#else
# define ResetRxTimeoutFlags(channel)
#endif


#if defined( IL_ENABLE_RX_TIMEOUT )
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetRxTimerFlags(channel)          (VStdMemNearClr(&ilRxTimerFlags[IlRxTimerFlagsStartIndex[(channel)]],(vuint8)(IlRxTimerFlagsStartIndex[(channel)+1]-IlRxTimerFlagsStartIndex[(channel)])))
# else
#  define ResetRxTimerFlags(channel)          (VStdMemNearClr(ilRxTimerFlags,(vuint8)(kIlNumberOfTimerFlagBytes)))
# endif
#else
# define ResetRxTimerFlags(channel)
#endif


#if defined IL_ENABLE_RX_INDICATION_FLAG
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetIndicationFlags(channel)       (VStdMemNearClr(&ilRxIndicationFlags[IlRxIndicationFlagsStartIndex[(channel)]],(vuint8)(IlRxIndicationFlagsStartIndex[(channel)+1]-IlRxIndicationFlagsStartIndex[(channel)])))
# else
#  define ResetIndicationFlags(channel)       (VStdMemNearClr(ilRxIndicationFlags,(vuint8)kIlNumberOfRxIndicationFlags))
# endif
#else
# define ResetIndicationFlags(channel)
#endif

#if defined IL_ENABLE_RX_FIRSTVALUE_FLAG
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetFirstvalueFlags(channel)       (VStdMemNearClr(&ilRxFirstvalueFlags[IlRxFirstvalueFlagsStartIndex[(channel)]],(vuint8)(IlRxFirstvalueFlagsStartIndex[(channel)+1]-IlRxFirstvalueFlagsStartIndex[(channel)])))
# else
#  define ResetFirstvalueFlags(channel)       (VStdMemNearClr(ilRxFirstvalueFlags,(vuint8)kIlNumberOfRxFirstvalueFlags))
# endif
#else
# define ResetFirstvalueFlags(channel)
#endif

#if defined IL_ENABLE_RX_DATACHANGED_FLAG
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetDataChangedFlags(channel)      (VStdMemNearClr(&ilRxDataChangedFlags[IlRxDataChangedFlagsStartIndex[(channel)]],(vuint8)(IlRxDataChangedFlagsStartIndex[(channel)+1]-IlRxDataChangedFlagsStartIndex[(channel)])))
# else
#  define ResetDataChangedFlags(channel)      (VStdMemNearClr(ilRxDataChangedFlags,(vuint8)kIlNumberOfRxDataChangedFlags))
# endif
#else
# define ResetDataChangedFlags(channel)
#endif
/**\}*/

/**********************************************************************************************************************
  DataAbstraction
**********************************************************************************************************************/
/** \defgroup DataAbstraction
    \brief    These macros shall be used to access tx and message buffers. */
/**\{*/

/**********************************************************************************************************************
  IlGetRxDataPtr
**********************************************************************************************************************/
/** \brief    This method returns the pointer to the buffer of a rx message.
    \param    ilRxHnd  Handle of an IL rx message.
    \return   vuint8*  Pointer to the databuffer.
**********************************************************************************************************************/
#if defined( IL_ENABLE_RX_MODE_SIGNALS ) || defined( IL_ENABLE_SYS_MULTI_ECU_PHYS ) 
# define IlGetRxDataPtr(ilRxHnd)                   (IlRxDataPtr[(ilRxHnd)])
#else
# define IlGetRxDataPtr(ilRxHnd)                   (CanGetRxDataPtr((ilRxHnd)))
#endif

/**********************************************************************************************************************
  IlGetRxDataLen
**********************************************************************************************************************/
/** \brief    This method returns the data length of a rx message.
    \param    ilRxHnd  Handle of an IL rx message.
    \return   vuint8   Length of the rx message in bytes.
**********************************************************************************************************************/
#if defined( IL_ENABLE_RX_MODE_SIGNALS ) || defined( IL_ENABLE_SYS_MULTI_ECU_PHYS ) 
# define IlGetRxDataLen(ilRxHnd)                   (IlRxDataLen[(ilRxHnd)])
#else
# define IlGetRxDataLen(ilRxHnd)                   (CanGetRxDataLen((ilRxHnd)))
#endif

/**********************************************************************************************************************
  IlGetTxDataPtr
**********************************************************************************************************************/
/** \brief    This method returns the pointer to the buffer of a tx message.
    \param    ilTxHnd  Handle of an IL tx message.
    \return   vuint8*  Pointer to the databuffer.
**********************************************************************************************************************/
#if defined( IL_ENABLE_TX_MODE_SIGNALS ) 
# define  IlGetTxDataPtr(ilTxHnd)                  (IlTxDataPtr[(ilTxHnd)])
#else
# define  IlGetTxDataPtr(ilTxHnd)                  (CanGetTxDataPtr(IlGetIlTxIndirection((ilTxHnd))))
#endif

/**********************************************************************************************************************
  IlGetTxDlc
**********************************************************************************************************************/
/** \brief    This method returns the data length code of a tx message.
    \param    ilTxHnd  Handle of an IL tx message.
    \return   vuint8   Dlc of the tx message in bytes.
**********************************************************************************************************************/
#if defined( IL_ENABLE_TX_MODE_SIGNALS ) 
# define  IlGetTxDlc(ilTxHnd)                      (IlTxDLC[(ilTxHnd)])
#else
# define  IlGetTxDlc(ilTxHnd)                      (XT_TX_DLC(CanGetTxDlc(IlGetIlTxIndirection((ilTxHnd)))))
#endif
/**\}*/

/**********************************************************************************************************************
  IlGetIlTxIndirection
**********************************************************************************************************************/
/** \brief    This method returns the Can Driver Handle of a IL tx message.
    \param    ilTxHnd  Handle of an IL tx message.
    \return   CanTransmitHandle  Can Driver tx message handle.
**********************************************************************************************************************/
#if defined( IL_ENABLE_SYS_MULTI_ECU_PHYS )
# define IlGetIlTxIndirection(ilTxHnd)             (IlTxIndirection[V_ACTIVE_IDENTITY_LOG][(ilTxHnd)])
#else
# define IlGetIlTxIndirection(ilTxHnd)             (IlTxIndirection[(ilTxHnd)])
#endif

/**********************************************************************************************************************
  IlGetStartRxTimeoutCounter
**********************************************************************************************************************/
/** \brief    This method returns the number of IlRxTask calls in a channel for the rx timeout time.
    \param    ilRxHnd  Handle of an IL rx message.
    \return   IltRxTimeoutCounter  Number of rx ticks until the rx timeout expires.
**********************************************************************************************************************/
#if defined ( VGEN_GENY ) && defined( IL_ENABLE_RX_DYNAMIC_TIMEOUT )
# define IlGetStartRxTimeoutCounter(ilRxHnd)     (ilRxDynamicTimeoutCounter[(ilRxHnd)])
#else
# if defined( IL_ENABLE_SYS_MULTI_ECU_PHYS )
#  define IlGetStartRxTimeoutCounter(ilRxHnd)    (IlRxTimeoutTbl[V_ACTIVE_IDENTITY_LOG][(ilRxHnd)])
# else
#  define IlGetStartRxTimeoutCounter(ilRxHnd)    (IlRxTimeoutTbl[(ilRxHnd)])
# endif
#endif

/**********************************************************************************************************************
  IlGetInitRxTimeoutCounter
**********************************************************************************************************************/
/** \brief    This method returns the number of IlRxTask calls in a channel for the initial rx timeout time.
    \param    ilRxHnd      Handle of an IL rx message.
    \return   IltRxTimeoutCounter  Number of rx ticks until the initial timeout expires.
**********************************************************************************************************************/
#if defined( IL_ENABLE_SYS_MULTI_ECU_PHYS )
# define IlGetInitRxTimeoutCounter(ilRxHnd)    (IlRxTimeoutTbl[V_ACTIVE_IDENTITY_LOG][(ilRxHnd)])
#else
# define IlGetInitRxTimeoutCounter(ilRxHnd)    (IlRxTimeoutTbl[(ilRxHnd)])
#endif

/**********************************************************************************************************************
  IlGetTxTimeout
**********************************************************************************************************************/
/** \brief    This method returns the number of IlTxTask calls in a channel for the tx timeout time.
    \param    channel      Handle of the CAN channel.
    \return   IltTxTimeoutCounter  Number of tx ticks until the tx timeout expires.
**********************************************************************************************************************/
#if defined ( VGEN_GENY )
# if defined( IL_ENABLE_TX ) && defined( IL_ENABLE_TX_TIMEOUT ) && defined ( IL_ENABLE_TX_VARYING_TIMEOUT )
#  define IlGetTxTimeout(channel)              (IlTxTimeout[channel])
# else
#  define IlGetTxTimeout(channel)              (kIlTxTimeout)
# endif
#endif /* VGEN_GENY */

/**********************************************************************************************************************
  IlGetTxCyclicCycles
**********************************************************************************************************************/
/** \brief    This method returns the number of IlTxTask calls for the cyclic transmission of a tx message.
    \param    ilTxHnd      Handle of an IL tx message.
    \return   IltTxCounter  Number of tx ticks until the next transmission request shall be performed.
**********************************************************************************************************************/
#if defined( IL_ENABLE_TX ) && defined( IL_ENABLE_TX_DYNAMIC_CYCLETIME )
# define  IlGetTxCyclicCycles(ilTxHnd)         (ilTxDynCyclicCycles[(ilTxHnd)])
#else
# define  IlGetTxCyclicCycles(ilTxHnd)         (IlTxCyclicCycles[(ilTxHnd)])
#endif

/**********************************************************************************************************************
  IlAssert
**********************************************************************************************************************/
/** \brief    This macro has to be used, if ApplIlFatalError needs to be called.
    \param    ilCondition      A boolean expression.
    \param    ilErrorCode      The error number to be submitted.
    \return   none
**********************************************************************************************************************/
#if defined( IL_ENABLE_SYS_TESTDEBUG )
# define IlAssert(ilCondition, ilErrorCode)        if ((ilCondition)==0) {(ApplIlFatalError((ilErrorCode)));}
#else
# define IlAssert(ilCondition, ilErrorCode)
#endif

#if defined ( IL_TYPE_GM )
# if defined(IL_ENABLE_RX_EXT_TIMEOUT)

/**********************************************************************************************************************
  IlGetRxNcaMsg
**********************************************************************************************************************/
/** \brief    This method returns the Il NCA Rx message handle of the channel
    \param    channel            Handle of the CAN channel.
    \return   IlReceiveHandle    The Il NCA Rx message handle of the channel
**********************************************************************************************************************/
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#   define IlGetRxNcaMsg(channel)       (IlRxChannel2NcaMsgIndirection[(channel)])
#  else
#   define IlGetRxNcaMsg(channel)       (kIlRxNcaMsg)
#  endif

/**********************************************************************************************************************
  IlGetRxNcaMsgTimeoutCnt
**********************************************************************************************************************/
/** \brief    This method returns the timeout time defined by NodeStatusMsgTimeoutTime in the dbc file.
    \param    channel      Handle of the CAN channel.
    \return   IltRxExtIDTimeoutCounter
**********************************************************************************************************************/
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#   define IlGetRxNcaMsgTimeoutCnt(channel)   (kGMLANNodeStatusTimeoutTimeCalCnt[(channel)])
#  else
#   define IlGetRxNcaMsgTimeoutCnt(channel)   (kGMLANNodeStatusTimeoutTimeCalCnt)
#  endif

/**********************************************************************************************************************
  IlGetRxExtIdHnd
**********************************************************************************************************************/
/** \brief    This method returns the extended id handle of the Il Rx message handle.
    \param    ilRxHnd  Il Rx message handle.
    \return   IlReceiveHandle
**********************************************************************************************************************/
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#   define IlGetRxExtIdHnd(ilRxHnd)            (IlRxHnd2IlRxExtIdHndIndirection[(ilRxHnd)])
#  else
#   define IlGetRxExtIdHnd(ilRxHnd)            (ilRxHnd)
#  endif

# endif/* IL_ENABLE_RX_EXT_TIMEOUT */

/**********************************************************************************************************************
  IlGetCanRxIndirection
**********************************************************************************************************************/
/** \brief    This method returns the Il Rx message handle of a CAN Rx message handle.
    \param    canRxHnd           Handle of the Rx CAN message.
    \return   IlReceiveHandle    The Il Rx message handle of the CAN Rx message Handle
**********************************************************************************************************************/
# if defined( IL_ENABLE_SYS_MULTI_ECU_PHYS )
#  define IlGetCanRxIndirection(canRxHnd)     (IlRxMsgCan2IlIndirection[(canRxHnd)])
# else
#  define IlGetCanRxIndirection(canRxHnd)     ((IlReceiveHandle)(canRxHnd))
# endif

/**********************************************************************************************************************
  IlGetMSB2LSBMask
**********************************************************************************************************************/
/** \brief    This method returns a mask in a MSB2LSB packed byte array for the current index.
    \param    index    Bitindex in the byte array
    \return   vuint8 : The mask value
**********************************************************************************************************************/
# define IlGetMSB2LSBMask(index)              (MSB2LSBBitMask[((index)&0x07)])

/**********************************************************************************************************************
  IlGetPackedRxObjectsStartIndex
**********************************************************************************************************************/
/** \brief    This method returns the first byte of the first Rx message index of the channel in an array,
              which contains LSB2MSB order packed kIlNumberOfRxObjects.
    \param    channel  Handle of the CAN channel.
    \return   vuint8 : The startindex in kIlNumberOfRxObjects ordered arrays.
**********************************************************************************************************************/
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define IlGetPackedRxObjectsStartIndex(channel)     (IlPackedRxObjectStartIndex[(channel)])
# else
#  define IlGetPackedRxObjectsStartIndex(channel)     0
# endif

/**********************************************************************************************************************
  IlGetPackedTxObjectsStartIndex
**********************************************************************************************************************/
/** \brief    This method returns the first byte of the first Tx message index of the channel in an array,
              which contains LSB2MSB order packed kIlNumberOfTxObjects.
    \param    channel  Handle of the CAN channel.
    \return   vuint8 : The startindex in kIlNumberOfTxObjects ordered arrays.
**********************************************************************************************************************/
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define IlGetPackedTxObjectsStartIndex(channel)     (IlPackedTxObjectStartIndex[(channel)])
# else
#  define IlGetPackedTxObjectsStartIndex(channel)     0
# endif

/**********************************************************************************************************************
  ResetRxActiveVnFlags
**********************************************************************************************************************/
/** \brief    This method clears the array ilRxActiveVn channelspecific.
    \param    channel  Handle of the CAN channel.
    \return   none
**********************************************************************************************************************/
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetRxActiveVnFlags(channel)              (IlClrFlagsMSB2LSB(ilRxActiveVn, IlVnStartIndex[(channel)],IlVnStartIndex[(channel)+1]))
# else
#  define ResetRxActiveVnFlags(channel)              (VStdMemClr(ilRxActiveVn, (vuint8)kIlNrOfPackedVirtualNetBytes))
# endif

/**********************************************************************************************************************
  ResetRxMessageActiveFlags
**********************************************************************************************************************/
/** \brief    This method clears the array ilVnRxMessageActive channelspecific.
    \param    channel  Handle of the CAN channel.
    \return   none
**********************************************************************************************************************/
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetRxMessageActiveFlags(channel)         (VStdMemClr(&ilVnRxMessageActive[IlPackedRxObjectStartIndex[(channel)]],(vuint8)(IlPackedRxObjectStartIndex[(channel)+1]-IlPackedRxObjectStartIndex[(channel)])))
# else
#  define ResetRxMessageActiveFlags(channel)         (VStdMemClr(ilVnRxMessageActive, (vuint8)kIlNrOfPackedRxObjectBytes))
# endif

/**********************************************************************************************************************
  ResetRxMessageEnableFlags
**********************************************************************************************************************/
/** \brief    This method clears the array ilVnRxMessageEnable channelspecific.
    \param    channel  Handle of the CAN channel.
    \return   none
**********************************************************************************************************************/
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetRxMessageEnableFlags(channel)         (VStdMemCpyRomToRam(&ilVnRxMessageEnable[IlPackedRxObjectStartIndex[(channel)]],&IlVnRxMessageEnabled[IlPackedRxObjectStartIndex[(channel)]],(IlPackedRxObjectStartIndex[(channel)+1]-IlPackedRxObjectStartIndex[(channel)])))
# else
#  define ResetRxMessageEnableFlags(channel)         (VStdMemCpyRomToRam(ilVnRxMessageEnable, IlVnRxMessageEnabled, kIlNrOfPackedRxObjectBytes))
# endif

/**********************************************************************************************************************
  ResetRxSupervisionActiveFlags
**********************************************************************************************************************/
/** \brief    This method clears the array ilVnRxSupervisionActive channelspecific.
    \param    channel  Handle of the CAN channel.
    \return   none
**********************************************************************************************************************/
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetRxSupervisionActiveFlags(channel)     (VStdMemClr(&ilVnRxSupervisionActive[IlPackedRxObjectStartIndex[(channel)]],(vuint8)(IlPackedRxObjectStartIndex[(channel)+1]-IlPackedRxObjectStartIndex[(channel)])))
# else
#  define ResetRxSupervisionActiveFlags(channel)     (VStdMemClr(ilVnRxSupervisionActive, (vuint8)kIlNrOfPackedRxObjectBytes))
# endif

/**********************************************************************************************************************
  ResetRxSVActiveVnFlags
**********************************************************************************************************************/
/** \brief    This method clears the array ilRxSVActiveVn channelspecific.
    \param    channel  Handle of the CAN channel.
    \return   none
**********************************************************************************************************************/
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetRxSVActiveVnFlags(channel)            (IlClrFlagsMSB2LSB(ilRxSVActiveVn, IlVnStartIndex[(channel)], IlVnStartIndex[(channel)+1] ))
# else
#  define ResetRxSVActiveVnFlags(channel)            (VStdMemClr(ilRxSVActiveVn, (vuint8)kIlNrOfPackedVirtualNetBytes))
# endif

/**********************************************************************************************************************
  ResetExtIdRxMsgIdxOfSourceAddress
**********************************************************************************************************************/
/** \brief    This method clears the array ilExtIdRxMsgIdxOfSourceAddress channelspecific.
    \param    channel  Handle of the CAN channel.
    \return   none
**********************************************************************************************************************/
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetExtIdRxMsgIdxOfSourceAddress(channel)   (VStdMemCpyRomToRam(&ilExtIdRxMsgIdxOfSourceAddress[IlRxExtIDStartIndex[(channel)]], &IlRxExtIDTimeoutType[IlRxExtIDStartIndex[(channel)]], IlRxExtIDStartIndex[(channel)+1]-IlRxExtIDStartIndex[(channel)]))
# else
#  define ResetExtIdRxMsgIdxOfSourceAddress(channel)   (VStdMemCpyRomToRam(ilExtIdRxMsgIdxOfSourceAddress, IlRxExtIDTimeoutType, kIlNumberOfExtIdRxObjects))
# endif

/**********************************************************************************************************************
  ResetTxActiveVnFlags
**********************************************************************************************************************/
/** \brief    This method clears the array ilTxSVActiveVn channelspecific.
    \param    channel  Handle of the CAN channel.
    \return   none
**********************************************************************************************************************/
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetTxActiveVnFlags(channel)              (IlClrFlagsMSB2LSB(ilTxActiveVn, IlVnStartIndex[(channel)],IlVnStartIndex[(channel)+1]))
# else
#  define ResetTxActiveVnFlags(channel)              (VStdMemClr(ilTxActiveVn, (vuint8)kIlNrOfPackedVirtualNetBytes))
# endif

/**********************************************************************************************************************
  ResetTxMessageActiveFlags
**********************************************************************************************************************/
/** \brief    This method clears the array ilVnTxMessageActive channelspecific.
    \param    channel  Handle of the CAN channel.
    \return   none
**********************************************************************************************************************/
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetTxMessageActiveFlags(channel)         (VStdMemClr(&ilVnTxMessageActive[IlPackedTxObjectStartIndex[(channel)]],(vuint8)(IlPackedTxObjectStartIndex[(channel)+1]-IlPackedTxObjectStartIndex[(channel)])))
# else
#  define ResetTxMessageActiveFlags(channel)         (VStdMemClr(ilVnTxMessageActive, (vuint8)kIlNrOfPackedTxObjectBytes))
# endif

/**********************************************************************************************************************
  ResetTxMessageEnableFlags
**********************************************************************************************************************/
/** \brief    This method clears the array ilVnTxMessageEnable channelspecific.
    \param    channel  Handle of the CAN channel.
    \return   none
**********************************************************************************************************************/
# if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
#  define ResetTxMessageEnableFlags(channel)         (VStdMemCpyRomToRam(&ilVnTxMessageEnable[IlPackedTxObjectStartIndex[(channel)]],&IlVnTxMessageEnabled[IlPackedTxObjectStartIndex[(channel)]],(IlPackedTxObjectStartIndex[(channel)+1]-IlPackedTxObjectStartIndex[(channel)])))
# else
#  define ResetTxMessageEnableFlags(channel)         (VStdMemCpyRomToRam(ilVnTxMessageEnable, IlVnTxMessageEnabled, kIlNrOfPackedTxObjectBytes))
# endif

#endif /* IL_TYPE_GM */

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
#if defined ( IL_TYPE_GM )
#endif /* IL_TYPE_GM */


/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
#if defined( IL_ENABLE_RX_MULTIPLE_NODES )
/** This variable contains the ECU-mask for Multiple ECUs. The variable is replaced in GENy by V_ACTIVE_IDENTITY_MSK. */
V_MEMRAM0 static V_MEMRAM1 vuintx V_MEMRAM2 ilECUMask;
#endif

#if defined ( IL_ENABLE_RX )
# if defined( C_ENABLE_GENERIC_PRECOPY )
#  if defined( IL_ENABLE_RX_POLLING ) || defined( IL_ENABLE_RX_EXT_TIMEOUT )
/** This variable indicates data reception of a channel */
#   if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 ilChannelReceive[kIlNumberOfChannels];
#   else
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 ilChannelReceive;
#   endif
#  endif /* IL_ENABLE_RX_POLLING || IL_ENABLE_RX_EXT_TIMEOUT */
# endif /* C_ENABLE_GENERIC_PRECOPY */
#endif /* IL_ENABLE_RX */

#if defined ( IL_ENABLE_TX )
/* variable definition for the send type CYCLIC-EVENT ***********************/
# if defined ( IL_ENABLE_TX_CYCLIC_EVENT ) || \
     defined ( IL_ENABLE_TX_SECURE_EVENT ) || \
     defined ( IL_ENABLE_TX_FAST_ON_START )
/** This variable contains the fast cycle time counter for every message. */
V_MEMRAM0 static V_MEMRAM1 IltTxCounter V_MEMRAM2 ilTxEventCounter[kIlNumberOfTxObjects];
# endif
/** This variable contains the standard cycle time and startdelaytime counter for every message. */
V_MEMRAM0 static V_MEMRAM1 IltTxCounter V_MEMRAM2 ilTxCyclicCounter[kIlNumberOfTxObjects];

# if defined( VGEN_GENY ) && defined( IL_ENABLE_TX_DYNAMIC_CYCLETIME )
/** This variable contains the cycle time for every message, if the dynamic cycle time API is used. */
V_MEMRAM0 static V_MEMRAM1 IltTxCounter V_MEMRAM2 ilTxDynCyclicCycles[kIlNumberOfTxObjects];
# endif
#endif /* IL_ENABLE_TX */

#if defined ( IL_TYPE_GM )
# if defined ( IL_ENABLE_RX )
/** This variable represents the active state of a Rx message. */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 ilVnRxMessageActive[kIlNrOfPackedRxObjectBytes];
/** This variable represents the enabled state of a Rx message. */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 ilVnRxMessageEnable[kIlNrOfPackedRxObjectBytes];

/** This variable represents the timeout supervision state of each Rx message. The sort order is LSB2MSB */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 ilVnRxSupervisionActive[kIlNrOfPackedRxObjectBytes];
/** This variable represents the timeout supervision state of a VN. The sort order is MSB2LSB */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 ilRxSVActiveVn[kIlNrOfPackedVirtualNetBytes];

#  if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
/** This variable contains all the source address index in ilExtIdRxLearnedSourceAddresses of an ExtId Handle.
    It is initialized with kMandatorySourceAddress and kOptionalSourceAddress. */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 ilExtIdRxMsgIdxOfSourceAddress[kIlNumberOfExtIdRxObjects];
/** This variable contains all source address per channel and config node. */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2
  ilExtIdRxLearnedSourceAddresses[kIlNumberOfChannels][kIlNrOfSourceAddresses];
/** This variable contains the ammount of all learned source adressses per channel. */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 ilNrOfLearnedSourceAddresses[kIlNumberOfChannels];
/** This variable counts the number of active messages per source address per channel and config node. */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2
  ilExtIdActiveRxMsgsPerSourceAddress[kIlNumberOfChannels][kIlNrOfSourceAddresses];

/** This variable stores the queued source address, which has to be learned for each channel. */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 ilExtIdRxSrcAddressQueue[kIlNumberOfChannels][kIlMaxRxExtIdQueue];
/** This variable stores the IlReceiveHandle of the message, where the source address has to be learned for each channel. */
V_MEMRAM0 static V_MEMRAM1 IlReceiveHandle V_MEMRAM2 ilExtIdRxObjHandleQueue[kIlNumberOfChannels][kIlMaxRxExtIdQueue];
/** This variable stores the maximum index of the queued source adresses for each channel. */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 ilExtIdRxSrcAddressQueueCount[kIlNumberOfChannels];

/** This variable contains the timeout counters for each source adress per channel */
V_MEMRAM0 static V_MEMRAM1 IltRxExtIDTimeoutCounter V_MEMRAM2
  ilExtIdRxSrcAddrTimer[kIlNumberOfChannels][kIlNrOfConfigNodes];
/** This variable contains the timeout counters for not learned source adresses (254/255) per channel */
V_MEMRAM0 static V_MEMRAM1 IltRxExtIDTimeoutCounter V_MEMRAM2 ilExtIdRxDefaultTimer[kIlNumberOfChannels];
/** This variable represents the timeout supervision state per source adress and channel. */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2
  ilNodeCommActiveTimeoutFlags[kIlNumberOfChannels][kIlNrOfPackedSourceAddressBytes];
#  endif/* IL_ENABLE_RX_EXT_TIMEOUT */
# endif/* IL_ENABLE_RX */

# if defined ( IL_ENABLE_TX )
/** This variable represents the active state of a Tx message. */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 ilVnTxMessageActive[kIlNrOfPackedTxObjectBytes];
/** This variable represents the enabled state of a Tx message. */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 ilVnTxMessageEnable[kIlNrOfPackedTxObjectBytes];

# endif/* IL_ENABLE_TX */

/** This constant is used to get the mask of an index, if the bit encoding is MSB2LSB */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 VnBitMask[8] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };

/** This constant is used to get the mask to clear an index, if the bit encoding is MSB2LSB */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 VnBitClrMask[8] = { 0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE };

/** This constant is used to get the mask of an index, if the bit encoding is LSB2MSB */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 LSB2MSBBitMask[8] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
/** This constant is used to get the top mask of an index, to clear the remaining bits if the bit encoding is MSB2LSB */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 BitClrTopMask_MSB2LSB[8] =
  { 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE };
/** This constant is used to get the end mask of an index, to clear the remaining bits if the bit encoding is MSB2LSB */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 BitClrEndMask_MSB2LSB[8] =
  { 0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00 };
# endif
#endif /* IL_TYPE_GM */

/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
#if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 ilChannelState[kIlNumberOfChannels];
#else
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 ilChannelState;
#endif

#if defined ( IL_ENABLE_RX )


# if defined( IL_ENABLE_RX_TIMEOUT )
V_MEMRAM0 V_MEMRAM1 IltRxTimeoutCounter V_MEMRAM2 ilRxTimeoutCounter[kIlNumberOfRxTimeoutCounters];
#  if defined( VGEN_GENY ) && defined( IL_ENABLE_RX_DYNAMIC_TIMEOUT )
V_MEMRAM0 V_MEMRAM1 IltRxTimeoutCounter V_MEMRAM2 ilRxDynamicTimeoutCounter[kIlNumberOfRxTimeoutCounters];
#  endif

V_MEMRAM0 V_MEMRAM1_NEAR vuint8 V_MEMRAM2_NEAR ilRxTimerFlags[kIlNumberOfTimerFlagBytes];

# endif /* IL_ENABLE_RX_TIMEOUT */

# if defined ( IL_ENABLE_RX_INDICATION_FLAG )
V_MEMRAM0 V_MEMRAM1_NEAR vuint8 V_MEMRAM2_NEAR ilRxIndicationFlags[kIlNumberOfRxIndicationFlags];

# endif

# if defined ( IL_ENABLE_RX_FIRSTVALUE_FLAG )
V_MEMRAM0 V_MEMRAM1_NEAR vuint8 V_MEMRAM2_NEAR ilRxFirstvalueFlags[kIlNumberOfRxFirstvalueFlags];

# endif

# if defined ( IL_ENABLE_RX_TIMEOUT_FLAG )
V_MEMRAM0 V_MEMRAM1_NEAR vuint8 V_MEMRAM2_NEAR ilRxTimeoutFlags[kIlNumberOfRxTimeoutFlags];

# endif

# if defined ( IL_ENABLE_RX_DATACHANGED_FLAG )
V_MEMRAM0 V_MEMRAM1_NEAR vuint8 V_MEMRAM2_NEAR ilRxDataChangedFlags[kIlNumberOfRxDataChangedFlags];
# endif

# if !defined (VGEN_GENY) && defined( IL_ENABLE_RX_MODE_SIGNALS )
# endif

#endif /* IL_ENABLE_RX */

#if defined ( IL_ENABLE_TX )

V_MEMRAM0 V_MEMRAM1_NEAR volatile vuint8 V_MEMRAM2_NEAR ilTxState[kIlNumberOfTxObjects];

V_MEMRAM0 V_MEMRAM1 IltTxUpdateCounter V_MEMRAM2 ilTxUpdateCounter[kIlNumberOfTxObjects];

# if defined ( IL_ENABLE_TX_TIMEOUT )
V_MEMRAM0 V_MEMRAM1 IltTxTimeoutCounter V_MEMRAM2 ilTxTimeoutCounter[kIlNumberOfTxTimeoutCounters];
# endif
# if defined( IL_ENABLE_TX_SECURE_EVENT )
V_MEMRAM0 V_MEMRAM1 IltTxRepetitionCounter V_MEMRAM2 ilTxNSendCounter[kIlNumberOfTxObjects];
# endif


# if defined ( IL_ENABLE_TX_TIMEOUT_FLAG )

V_MEMRAM0 V_MEMRAM1_NEAR vuint8 V_MEMRAM2_NEAR ilTxTimeoutFlags[kIlNumberOfTxTimeoutFlags];
# endif

# if defined ( IL_ENABLE_TX_CONFIRMATION_FLAG )

V_MEMRAM0 V_MEMRAM1_NEAR vuint8 V_MEMRAM2_NEAR ilTxConfirmationFlags[kIlNumberOfTxConfirmationFlags];
# endif
#endif /* IL_ENABLE_TX */


V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kIlMainVersion = (vuint8) (IL_VECTOR_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kIlSubVersion = (vuint8) (IL_VECTOR_VERSION & 0x00ff);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kIlReleaseVersion = (vuint8) (IL_VECTOR_RELEASE_VERSION);

#if defined ( IL_TYPE_GM )
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kIlGmMainVersion = (vuint8) (IL_VECTOR_GM_VERSION >> 8);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kIlGmSubVersion = (vuint8) (IL_VECTOR_GM_VERSION & 0x00ff);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kIlGmReleaseVersion = (vuint8) (IL_VECTOR_GM_RELEASE_VERSION);

# if defined ( IL_ENABLE_RX )
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 ilRxActiveVn[kIlNrOfPackedVirtualNetBytes];
# endif

# if defined ( IL_ENABLE_TX )
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 ilTxActiveVn[kIlNrOfPackedVirtualNetBytes];
# endif
#endif /* IL_TYPE_GM */

/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#if defined( IL_ENABLE_TX )
/**********************************************************************************************************************
  IlSendMessage
**********************************************************************************************************************/
/** \brief    This method performs the transmission request to the CAN Driver.
    \param    ilTxHnd  Handle of the tx message.
    \return   none
    \context  The function is called by IlTxTimerTask or IlSendDirect.
**********************************************************************************************************************/
static void IlSendMessage(IlTransmitHandle ilTxHnd);
#endif

#if defined( IL_ENABLE_RX_STOP_DEFAULTVALUE ) || defined( IL_ENABLE_RX_START_DEFAULTVALUE )
/**********************************************************************************************************************
  SetRxDefaultWithMask
**********************************************************************************************************************/
/** \brief    This method copies default values to the rx message buffer.
    \param    ilRxHnd  Handle of the rx message.
    \param    msk      pointer to a mask array of the rx message. At every position, where the mask bit is set,
                       the default value is set.
    \return   none
    \context  The function is called by IlRxStart or IlRxStop.
**********************************************************************************************************************/
static void SetRxDefaultWithMask(IlReceiveHandle ilRxHnd, V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3 * msk);
#endif

#if defined( IL_ENABLE_TX_STOP_DEFAULTVALUE ) || defined( IL_ENABLE_TX_START_DEFAULTVALUE )
/**********************************************************************************************************************
  SetTxDefaultWithMask
**********************************************************************************************************************/
/** \brief    This method copies default values to the tx message buffer.
    \param    ilTxHnd  Handle of the tx message.
    \param    msk      pointer to a mask array of the tx message. At every position, where the mask bit is set,
                       the default value is set.
    \return   none
    \context  The function is called by IlTxStart or IlTxStop.
**********************************************************************************************************************/
static void SetTxDefaultWithMask(IlTransmitHandle ilTxHnd, IL_MEMROM1 vuint8 IL_MEMROM2 IL_MEMROM3 * msk);
#endif

#if defined ( IL_TYPE_GM )
# if defined( IL_ENABLE_RX_EXT_TIMEOUT )
/**********************************************************************************************************************
  IlRxMessageRecovery
**********************************************************************************************************************/
/** \brief    This method calls the timeout recovery function of the ilRxHnd.
    \param    ilRxExtIdHnd Handle of the extended id object.
    \return   none
    \context  The function is called by IlRxStateTask or IlNodeCommActiveRecovery.
**********************************************************************************************************************/
static void IlRxMessageRecovery(IlReceiveHandle ilRxExtIdHnd);

/**********************************************************************************************************************
  IlNodeCommActiveRecovery
**********************************************************************************************************************/
/** \brief    This method performs IlRxMessageRecovery for every Rx message used by the srcAddress of the channel.
    \param_i  channel      Handle of the CAN channel.
    \param    srcAddress   source address of an ECU for this message.
    \return   none
    \context  The function is called by IlProcessLearnedSourceAddress.
**********************************************************************************************************************/
static void IlNodeCommActiveRecovery(IL_CHANNEL_ILTYPE_FIRST vuint8 srcAddress);

/**********************************************************************************************************************
  IlProcessLearnedSourceAddress
**********************************************************************************************************************/
/** \brief    This method is called to learn a new srcAddress or to perform timeout recovery.
    \param_i  channel      Handle of the CAN channel.
    \param    srcAddress   source address of an ECU for this message.
    \return   vuint8
    \context  The function is called by IlRxStateTask or IlSetRxMessageSourceAddress
**********************************************************************************************************************/
static vuint8 IlProcessLearnedSourceAddress(IL_CHANNEL_ILTYPE_FIRST vuint8 srcAddress);

/**********************************************************************************************************************
  IlNodeCommActiveFailed
**********************************************************************************************************************/
/** \brief    This method performs timeout handling for all Rx messages with the related srcAddress of the channel.
    \param_i  channel      Handle of the CAN channel.
    \param    srcAddress   source address of an ECU for this message.
    \return   kIlTimeoutEvent or kIlNoTimeoutEvent
    \context  The function is called by IlRxStateTask.
**********************************************************************************************************************/
static vuintx IlNodeCommActiveFailed(IL_CHANNEL_ILTYPE_FIRST vuint8 srcAddress);

/**********************************************************************************************************************
  IlGetSourceAddressIndex
**********************************************************************************************************************/
/** \brief    This method returns the index of srcAddress in ilExtIdRxLearnedSourceAddresses and
              IL_NODE_ADDRESS_UNKNOWN if the srcAddress has not been found.
    \param_i  channel      Handle of the CAN channel.
    \param    srcAddress   source address of an ECU for this message.
    \return   none
    \context  The function is called by IlProcessLearnedSourceAddress or IlGetNodeCommActiveState.
**********************************************************************************************************************/
static vuint8 IlGetSourceAddressIndex(IL_CHANNEL_ILTYPE_FIRST vuint8 srcAddress);
# endif/* IL_ENABLE_RX_EXT_TIMEOUT */
#endif /* IL_TYPE_GM */

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/
#if defined( IL_ENABLE_RX_STOP_DEFAULTVALUE ) || defined( IL_ENABLE_RX_START_DEFAULTVALUE )
/**********************************************************************************************************************
  SetRxDefaultWithMask
**********************************************************************************************************************/
static void SetRxDefaultWithMask(IlReceiveHandle ilRxHnd, V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3 * msk)
{
  vuint8 *dst = IlGetRxDataPtr(ilRxHnd);
  vuint8 len = IlGetRxDataLen(ilRxHnd);
  V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3 *src = IlRxDefaultInitValue[ilRxHnd];

  if (dst == V_NULL)
  {
    return;
  }

#  if defined IL_ENABLE_SYS_ARGCHECK

  if (len > 8)
  {
    return;
  }
#  endif

  while (len > 0)
  {
    len--;
    *dst = (*dst & (vuint8) ~ (*msk)) | ((*src) & (*msk));
    dst++;
    src++;
    msk++;
  }
}                               /* End of SetRxDefaultWithMask() */
#endif

#if defined( IL_ENABLE_TX_STOP_DEFAULTVALUE ) || defined( IL_ENABLE_TX_START_DEFAULTVALUE )
/**********************************************************************************************************************
  SetTxDefaultWithMask
**********************************************************************************************************************/
static void SetTxDefaultWithMask(IlTransmitHandle ilTxHnd, IL_MEMROM1 vuint8 IL_MEMROM2 IL_MEMROM3 * msk)
{
  vuint8 *dst = IlGetTxDataPtr(ilTxHnd);
  vuint8 len = IlGetTxDlc(ilTxHnd);
  IL_MEMROM1 vuint8 IL_MEMROM2 IL_MEMROM3 *src = IlTxDefaultInitValue[ilTxHnd];

  if (dst == V_NULL)
  {
    return;
  }
#  if defined IL_ENABLE_SYS_ARGCHECK

  if (len > 8)
  {
    return;
  }
#  endif

  while (len > 0)
  {
    len--;
    *dst = (*dst & (vuint8) ~ (*msk)) | ((*src) & (*msk));
    dst++;
    src++;
    msk++;
  }
}                               /* End of SetTxDefaultWithMask() */
#endif

#if defined ( IL_ENABLE_TX )
/**********************************************************************************************************************
  IlSendMessage
**********************************************************************************************************************/
static void IlSendMessage(IlTransmitHandle ilTxHnd)
{

  CanInterruptDisable();
  ilTxState[ilTxHnd] &= kTxNotSendRequest;

# if defined ( IL_ENABLE_TX_MODE_SIGNALS )
  /* copy mode depended signals to message buffer */
  if (IlTxModeCopyFunctions[ilTxHnd] != V_NULL)
  {
    IlTxModeCopyFunctions[ilTxHnd] ();
  }
# endif

  /* Counter for Update time must be reloaded twice, ------------ */
  /* here and in confirmation fct     --------------------------- */
# if defined ( C_ENABLE_CAN_CANCEL_NOTIFICATION )
  ilTxUpdateCounter[ilTxHnd] = kIlStopUpdateCounterValue;
# else
  ilTxUpdateCounter[ilTxHnd] = IlTxUpdateCycles[ilTxHnd];
# endif
  CanInterruptRestore();

  if (CanTransmit(IlGetIlTxIndirection(ilTxHnd)) != kCanTxOk)
  {
    CanInterruptDisable();
    {
      ilTxState[ilTxHnd] |= (kTxSendRequest);
    }
    ilTxUpdateCounter[ilTxHnd] = 0;
    CanInterruptRestore();
  }
# if defined( IL_ENABLE_TX_SECURE_EVENT )
  else
  {
    CanInterruptDisable();
    /* clear send request flag  ----------------------------------- */
    if ((ilTxNSendCounter[ilTxHnd] != 0) && ((ilTxState[ilTxHnd] & kTxNSendRequest) != 0))
    {
      ilTxNSendCounter[ilTxHnd]--;
    }
    ilTxState[ilTxHnd] &= kTxNotNSendRequest;
    CanInterruptRestore();
  }
# endif

}                               /* End of IlSendMessage() */
#endif /* IL_ENABLE_TX */

#if defined ( IL_TYPE_GM )
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
/**********************************************************************************************************************
  IlClrFlagsMSB2LSB
**********************************************************************************************************************/
/** \brief    This method clears bits of a byte array. The bitcount is ascending from LSB to MSB
    \param    *pDat        pointer to the byte array
    \param    startIdx     first bit index to be cleared
    \param    endIdx       last bit to be cleared (not including)
    \return   none
**********************************************************************************************************************/
static void IlClrFlagsMSB2LSB(vuint8 * pDat, vsint16 startIdx, vsint16 endIdx)
{
  vuint8 startByte;
  vuint8 endByte;
  vuint8 topMask;
  vuint8 endMask;
  if (startIdx < endIdx)
  {
    /* Calculate the last bit to be cleared */
    endIdx = endIdx - 1;

    startByte = (vuint8) (startIdx >> 3);
    endByte = (vuint8) (endIdx >> 3);
    topMask = BitClrTopMask_MSB2LSB[(startIdx & 0x07)];
    endMask = BitClrEndMask_MSB2LSB[(endIdx & 0x07)];

    if (startByte == endByte)
    {
      endMask |= topMask;
    }
    else
    {
      pDat[startByte] &= topMask;
      startByte++;
    }

    while (startByte < endByte)
    {
      pDat[startByte] = 0;
      startByte++;
    }
    pDat[startByte] &= endMask;
  }
}                               /* End of IlSetFlagsMSB2LSB() */
# endif/* ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) */
#endif /* IL_TYPE_GM */

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  IlInitPowerOn
**********************************************************************************************************************/
void IlInitPowerOn(void)
{
#if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  CanChannelHandle channel;
  for (channel = 0; channel < kIlNumberOfChannels; channel++)
#endif
  {
    IlInit(IL_CHANNEL_ILPARA_ONLY);
  }
}                               /* End of IlInitPowerOn() */

/**********************************************************************************************************************
  IlInit
**********************************************************************************************************************/
void IlInit(IL_CHANNEL_ILTYPE_ONLY)
{

#if defined ( IL_ENABLE_RX )
  IlReceiveHandle ilRxHnd;
#endif
#if defined ( IL_ENABLE_TX )
  IlTransmitHandle ilTxHnd;
#endif

  /* Reset internal state of IL    */
  Il_ChannelState(IL_CHANNEL_ILPARA_MACRO) = kIlIsSuspend;


#if defined( IL_ENABLE_RX_MULTIPLE_NODES )
  /* Setup the ECU mask for multiple ECUs */
  ilECUMask = (vuintx) (0x01 << V_ACTIVE_IDENTITY_LOG);
#endif


#if defined ( IL_ENABLE_RX )

  /***********************************************************
   **  Initialize receive data
   ***********************************************************/


   /*--- Loop for every receive object ---------------------------------------*/
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilRxHnd = IlRxMsgStartIndex[channel]; ilRxHnd < IlRxMsgStartIndex[(channel + 1)]; ilRxHnd++)
# else
  for (ilRxHnd = 0; ilRxHnd < kIlNumberOfRxObjects; ilRxHnd++)
# endif
  {
    IlAssert(ilRxHnd < kIlNumberOfRxObjects, ILERR_ILLRXMSGHANDLE);

    if ((IlGetRxDataPtr(ilRxHnd)) != V_NULL)
    {
#  if defined IL_ENABLE_RX_DEFAULTVALUE
      if ((IlRxDefaultInitValue[ilRxHnd]) != V_NULL)
      {
        /*-- Set receive buffer to default values ---------------------------*/
        VStdMemCpyRomToRam(IlGetRxDataPtr(ilRxHnd), IlRxDefaultInitValue[ilRxHnd], IlGetRxDataLen(ilRxHnd));
      }
      else
#  endif /* IL_ENABLE_RX_DEFAULTVALUE */
      {
        /*-- No default value for this buffer. Set to '0' -------------------*/
        VStdMemClr(IlGetRxDataPtr(ilRxHnd), IlGetRxDataLen(ilRxHnd));
      }
    }
  }

   /*--- initialize dynamic Rx timeout objects ---------------------------------------*/
# if defined ( VGEN_GENY ) && defined( IL_ENABLE_RX_TIMEOUT ) && defined( IL_ENABLE_RX_DYNAMIC_TIMEOUT )
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilRxHnd = IlRxTimeoutCntStartIndex[channel]; ilRxHnd < IlRxTimeoutCntStartIndex[(channel + 1)]; ilRxHnd++)
#  else
  for (ilRxHnd = 0; ilRxHnd < kIlNumberOfRxTimeoutCounters; ilRxHnd++)
#  endif
  {
    IlAssert(ilRxHnd < kIlNumberOfRxTimeoutCounters, ILERR_ILLRXTIMEOUTINDEX);
    ilRxDynamicTimeoutCounter[ilRxHnd] = IlGetInitRxTimeoutCounter(ilRxHnd);
  }
# endif /* VGEN_GENY && IL_ENABLE_RX_TIMEOUT && IL_ENABLE_RX_DYNAMIC_TIMEOUT */

   /*---- Reset all flags for receive indication -----------------------------*/
  IlResetRxTimeoutFlags(IL_CHANNEL_ILPARA_ONLY);

  ResetRxTimerFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetIndicationFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetFirstvalueFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetDataChangedFlags(IL_CHANNEL_ILPARA_MACRO);


#endif /* IL_ENABLE_RX */


#if defined ( IL_ENABLE_TX )
  /***********************************************************
   **  Initialize transmit data
   ***********************************************************/


  /*----- do the loop for every Tx object  -------------------------------*/
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilTxHnd = IlTxMsgStartIndex[channel]; ilTxHnd < IlTxMsgStartIndex[(channel + 1)]; ilTxHnd++)
# else
  for (ilTxHnd = 0; ilTxHnd < kIlNumberOfTxObjects; ilTxHnd++)
# endif
  {
    IlAssert(ilTxHnd < kIlNumberOfTxObjects, ILERR_ILLTXMSGHANDLE);

# if defined( IL_ENABLE_SYS_MULTI_ECU_PHYS )
    if ((IlTxIdentityAssignment[ilTxHnd] & V_ACTIVE_IDENTITY_MSK) == (tVIdentityMsk) 0)
    {
      continue;
    }
# endif

    /************************************************************************/
    /**** Section: Clear Send-Type independent data *************************/
    /************************************************************************/
    if ((IlGetTxDataPtr(ilTxHnd)) != V_NULL)
    {
#  if defined IL_ENABLE_TX_DEFAULTVALUE
      if (IlTxDefaultInitValue[ilTxHnd] != V_NULL)
      {
        /*-- Set receive buffer to default values ---------------------------*/
        VStdMemCpyRomToRam(IlGetTxDataPtr(ilTxHnd), IlTxDefaultInitValue[ilTxHnd], IlGetTxDlc(ilTxHnd));
      }
      else
#  endif /* IL_ENABLE_TX_DEFAULTVALUE */
      {
        /*-- No default value for this buffer. Set to '0' -------------------*/
        /*** Clear message-transmit data-buffer *********************************/
        VStdMemClr(IlGetTxDataPtr(ilTxHnd), IlGetTxDlc(ilTxHnd));
      }
    }

    /*- Clear Tx-status variable. Message is inactive, no sendtype defined -*/
    ilTxState[ilTxHnd] = 0;

    /*--- Clear counter for update time ------------------------------------*/
    ilTxUpdateCounter[ilTxHnd] = 0; /*    */


    /************************************************************************/
    /**** Section: Clear data buffer for CYCLIC messages ********************/
    /************************************************************************/

    /* initialise the Dynamic cycle time counters with the initial defined rom values */
# if defined( VGEN_GENY ) && defined( IL_ENABLE_TX_DYNAMIC_CYCLETIME )
    ilTxDynCyclicCycles[ilTxHnd] = IlTxCyclicCycles[ilTxHnd];
# endif

    /*-- Counter for the cycletime -----------------------------------------*/
    ilTxCyclicCounter[ilTxHnd] = 0;


# if defined ( IL_ENABLE_TX_CYCLIC_EVENT ) || \
     defined ( IL_ENABLE_TX_SECURE_EVENT ) || \
     defined ( IL_ENABLE_TX_FAST_ON_START )
    /************************************************************************/
    /**** Section: Clear data buffer for CYCLIC- and SECURE-EVENT messages **/
    /************************************************************************/
    ilTxEventCounter[ilTxHnd] = 0;  /* Clear counter for event timer    */
# endif

  }

  /*---- Reset all flags for transmit path ----------------------------------*/
  ResetTxTimeoutFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetConfirmationFlags(IL_CHANNEL_ILPARA_MACRO);


#endif /* IL_ENABLE_TX */

#if defined ( IL_TYPE_GM )
# if defined ( IL_ENABLE_RX )
  ResetRxMessageActiveFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetRxSupervisionActiveFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetRxActiveVnFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetRxSVActiveVnFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetRxMessageEnableFlags(IL_CHANNEL_ILPARA_MACRO);

#  if defined( IL_ENABLE_RX_EXT_TIMEOUT )
  ilNrOfLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO] = 0;
  VStdMemClr(ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO], kIlNrOfConfigNodes);
  ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO][kOptionalSourceAddressIdx] = kOptionalSourceAddress;
  ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO][kMandatorySourceAddressIdx] = kMandatorySourceAddress;
  VStdMemClr(ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO], kIlNrOfSourceAddresses);
  VStdMemClr(ilExtIdRxSrcAddressQueue[IL_CHANNEL_ILPARA_MACRO], kIlMaxRxExtIdQueue);
  VStdMemClr(ilExtIdRxObjHandleQueue[IL_CHANNEL_ILPARA_MACRO],
             kIlMaxRxExtIdQueue * ((vuint16) sizeof(IlReceiveHandle)));
  ilExtIdRxSrcAddressQueueCount[IL_CHANNEL_ILPARA_MACRO] = 0;
  ResetExtIdRxMsgIdxOfSourceAddress(IL_CHANNEL_ILPARA_MACRO);
#  endif/* IL_ENABLE_RX_EXT_TIMEOUT */
# endif/* IL_ENABLE_RX */

# if defined ( IL_ENABLE_TX )
  ResetTxActiveVnFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetTxMessageActiveFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetTxMessageEnableFlags(IL_CHANNEL_ILPARA_MACRO);
# endif/* IL_ENABLE_TX */

# if defined ( VGEN_ENABLE_NM_GMLAN )
  IlNwmInit(IL_CHANNEL_ILPARA_ONLY);
# endif
#endif /* IL_TYPE_GM */

#if defined(IL_ENABLE_SYS_INIT_FCT)
  ApplIlInit(IL_CHANNEL_ILPARA_ONLY);
#endif
#if defined( IL_ENABLE_SYS_SIGNAL_INIT_FCT )
  IlSignalInit(IL_CHANNEL_ILPARA_ONLY);
#endif
}                               /* End of IlInit() */

/**********************************************************************************************************************
  IlRxStart
**********************************************************************************************************************/
void IlRxStart(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( IL_ENABLE_RX )

# if defined ( IL_ENABLE_RX_START_DEFAULTVALUE )
  IlReceiveHandle ilRxHnd;
# endif
# if defined ( IL_ENABLE_RX_TIMEOUT )
  IlRxTimeoutHandle ilRxToHnd;
# endif

  /*** Receive already enabled. Do nothing! **********************************/
  if (RxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    return;
  }

# if defined ( IL_ENABLE_RX_START_DEFAULTVALUE )
  /*--- Loop for every receive object ---------------------------------------*/
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilRxHnd = IlRxMsgStartIndex[channel]; ilRxHnd < IlRxMsgStartIndex[(channel + 1)]; ilRxHnd++)
#  else
  for (ilRxHnd = 0; ilRxHnd < kIlNumberOfRxObjects; ilRxHnd++)
#  endif
  {
    IlAssert(ilRxHnd < kIlNumberOfRxObjects, ILERR_ILLRXMSGHANDLE);
    /*-- Set receive buffer to default for some signals, if selected -------*/
    if ((IlRxDefaultInitValue[ilRxHnd] != V_NULL) && (IlRxDefaultStartMask[ilRxHnd] != V_NULL))
    {
      SetRxDefaultWithMask(ilRxHnd, IlRxDefaultStartMask[ilRxHnd]);
    }
  }
# endif /* IL_ENABLE_RX_START_DEFAULTVALUE */

# if defined( IL_ENABLE_RX_TIMEOUT )
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilRxToHnd = IlRxTimeoutCntStartIndex[channel]; ilRxToHnd < IlRxTimeoutCntStartIndex[(channel + 1)]; ilRxToHnd++)
#  else
  for (ilRxToHnd = 0; ilRxToHnd < kIlNumberOfRxTimeoutCounters; ilRxToHnd++)
#  endif
  {
    IlAssert(ilRxToHnd < kIlNumberOfRxTimeoutCounters, ILERR_ILLRXTIMEOUTINDEX);

    /*--- Reset timeout counter to its initial state --------------------*/
#  if defined ( IL_ENABLE_RX_TIMEOUT_DELAY )
    /* Timeout observation starts with first receive of a message */
    ilRxTimeoutCounter[ilRxToHnd] = 0;
#  else
    ilRxTimeoutCounter[ilRxToHnd] = IlGetStartRxTimeoutCounter(ilRxToHnd);
#  endif
  }
# endif /* IL_ENABLE_RX_TIMEOUT */

  /*---- Reset indication flags of the CAN driver ---------------------------*/
# if defined( IL_ENABLE_RX ) && defined( IL_ENABLE_RX_POLLING )
  IlResetCanIndicationFlags(IL_CHANNEL_ILPARA_ONLY);
# endif
# if !defined( VGEN_GENY ) && defined( IL_ENABLE_RX_MODE_SIGNALS )
# endif
  /*---- Reset all flags for reception path ---------------------------------*/
  IlResetRxTimeoutFlags(IL_CHANNEL_ILPARA_ONLY);

  ResetRxTimerFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetIndicationFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetFirstvalueFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetDataChangedFlags(IL_CHANNEL_ILPARA_MACRO);

# if defined ( IL_TYPE_GM )
#  if defined ( IL_ENABLE_RX )
  ResetRxActiveVnFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetRxMessageActiveFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetRxSVActiveVnFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetRxSupervisionActiveFlags(IL_CHANNEL_ILPARA_MACRO);
#   if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
  VStdMemClr(ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO], kIlNrOfSourceAddresses);
  ilExtIdRxDefaultTimer[IL_CHANNEL_ILPARA_MACRO] = 0;
#   endif
        /* IL_ENABLE_RX_EXT_TIMEOUT */
#  endif
       /* IL_ENABLE_RX */
# endif/* IL_TYPE_GM */

   /*---- call user defined function on start of reception path of IAL -------*/
# if defined IL_ENABLE_SYS_RX_START_FCT
  ApplIlRxStart(IL_CHANNEL_ILPARA_ONLY);
# endif
# if defined( IL_ENABLE_RX_SIGNAL_START_FCT )
  IlSignalRxStart(IL_CHANNEL_ILPARA_ONLY);
# endif

  EnableRx(IL_CHANNEL_ILPARA_MACRO);

#else /* IL_ENABLE_RX */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
# endif
#endif /* IL_ENABLE_RX */
}                               /* End of IlRxStart() */

/**********************************************************************************************************************
  IlTxStart
**********************************************************************************************************************/
void IlTxStart(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( IL_ENABLE_TX )
  IlTransmitHandle ilTxHnd;

  /*** Transmit already enabled. Do nothing! *********************************/
  if (TxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    return;
  }

  /* load startup times into the counter */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilTxHnd = IlTxMsgStartIndex[channel]; ilTxHnd < IlTxMsgStartIndex[(channel + 1)]; ilTxHnd++)
# else
  for (ilTxHnd = 0; ilTxHnd < kIlNumberOfTxObjects; ilTxHnd++)
# endif
  {
    IlAssert(ilTxHnd < kIlNumberOfTxObjects, ILERR_ILLTXMSGHANDLE);

# if defined IL_ENABLE_TX_START_DEFAULTVALUE
    /*-- Set transmit buffer to default for some signals, if selected -------*/
    if ((IlTxDefaultInitValue[ilTxHnd] != V_NULL) && (IlTxDefaultStartMask[ilTxHnd] != V_NULL)
#  if defined( IL_ENABLE_SYS_MULTI_ECU_PHYS )
        && ((IlTxIdentityAssignment[ilTxHnd] & V_ACTIVE_IDENTITY_MSK) != (tVIdentityMsk) 0)
#  endif
      )
    {
      SetTxDefaultWithMask(ilTxHnd, IlTxDefaultStartMask[ilTxHnd]);
    }
# endif

    /* copy default status from ROM to RAM for later change ---------------- */
    ilTxState[ilTxHnd] = IlTxType[ilTxHnd];

    /*--- Clear counter for update time ------------------------------------*/
    ilTxUpdateCounter[ilTxHnd] = 0; /*    */

# if defined( IL_ENABLE_TX_SECURE_EVENT )
    ilTxNSendCounter[ilTxHnd] = 0;
# endif

# if  defined ( IL_ENABLE_TX_FAST_ON_START )
    if ((IlTxType[ilTxHnd] & kTxFastOnStart) != 0)
    {
      /*--- Set the Time for fast transmission after Start of the CYCLIC messages --------------------*/
      ilTxCyclicCounter[ilTxHnd] = IlTxFastOnStartDuration[ilTxHnd];    /* + 1 already done in the table */

      ilTxEventCounter[ilTxHnd] = IlTxStartCycles[ilTxHnd];     /* set start delay time for event timer *//* + 1 already done in the table */
    }
    else
# endif
    {
      /*--- Set the StartDelayTime of the CYCLIC messages --------------------*/
      ilTxCyclicCounter[ilTxHnd] = IlTxStartCycles[ilTxHnd];    /* + 1 already done in the table */

# if defined ( IL_ENABLE_TX_CYCLIC_EVENT ) || \
    defined ( IL_ENABLE_TX_SECURE_EVENT ) || \
    defined ( IL_ENABLE_TX_FAST_ON_START )
      ilTxEventCounter[ilTxHnd] = 0;        /* Clear counter for event timer    */
# endif
    }
  }

# if defined ( IL_ENABLE_TX_TIMEOUT )
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilTxHnd = IlTxTimeoutCntStartIndex[channel]; ilTxHnd < IlTxTimeoutCntStartIndex[(channel + 1)]; ilTxHnd++)
#  else
  for (ilTxHnd = 0; ilTxHnd < kIlNumberOfTxTimeoutCounters; ilTxHnd++)
#  endif
  {
    /*--- Stop timeout counter --------------------*/
    ilTxTimeoutCounter[ilTxHnd] = 0;
  }
# endif

  /*---- Reset all flags for transmission path ------------------------------*/
  ResetTxTimeoutFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetConfirmationFlags(IL_CHANNEL_ILPARA_MACRO);

  /*---- Reset confirmation flags of the CAN driver ---------------------------*/
  IlResetCanConfirmationFlags(IL_CHANNEL_ILPARA_ONLY);
# if defined(IL_ENABLE_TX_CYCLIC_EVENT)
  InitIfActiveFlags(IL_CHANNEL_ILPARA_ONLY);
# endif

# if defined ( IL_TYPE_GM )
#  if defined ( IL_ENABLE_TX )
  ResetTxActiveVnFlags(IL_CHANNEL_ILPARA_MACRO);
  ResetTxMessageActiveFlags(IL_CHANNEL_ILPARA_MACRO);
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilTxHnd = IlTxMsgStartIndex[channel]; ilTxHnd < IlTxMsgStartIndex[(channel + 1)]; ilTxHnd++)
#   else
  for (ilTxHnd = 0; ilTxHnd < kIlNumberOfTxObjects; ilTxHnd++)
#   endif
  {
    IlAssert(ilTxHnd < kIlNumberOfTxObjects, ILERR_ILLTXMSGHANDLE);
    /* Because the configuration for initialy send messages can be changed, */
    /* the pre-setting must maybe changed.                                  */
    ilTxState[ilTxHnd] &= kTxNotQueueInit;
    {
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
      vuint8 ilBitIndex =
        ((IlGetPackedTxObjectsStartIndex(IL_CHANNEL_ILPARA_MACRO) * 8) +
         (ilTxHnd - IlTxMsgStartIndex[IL_CHANNEL_ILPARA_MACRO]));
      if ((IlVnTxSendOnInit[ilBitIndex >> 3] & LSB2MSBBitMask[ilBitIndex & 0x07]) != 0)
#   else
      if ((IlVnTxSendOnInit[ilTxHnd >> 3] & LSB2MSBBitMask[ilTxHnd & 0x07]) != 0)
#   endif
      {
        ilTxState[ilTxHnd] |= kTxQueueInit;
      }
    }
  }
#  endif
       /* IL_ENABLE_TX */
# endif/* IL_TYPE_GM */

   /*---- call user defined function on start of transmission path of IAL ----*/
# if defined IL_ENABLE_SYS_TX_START_FCT
  ApplIlTxStart(IL_CHANNEL_ILPARA_ONLY);
# endif
# if defined( IL_ENABLE_TX_SIGNAL_START_FCT )
  IlSignalTxStart(IL_CHANNEL_ILPARA_ONLY);
# endif

  EnableTx(IL_CHANNEL_ILPARA_MACRO);

#else /* IL_ENABLE_TX */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
# endif
#endif /* IL_ENABLE_TX */
}                               /* End of IlTxStart() */

/**********************************************************************************************************************
  IlRxStop
**********************************************************************************************************************/
void IlRxStop(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( IL_ENABLE_RX )

# if defined IL_ENABLE_RX_STOP_DEFAULTVALUE
  IlReceiveHandle ilRxHnd;
# endif

  if (RxSuspended(IL_CHANNEL_ILPARA_MACRO)) /* Receive already disabled  */
  {
    return;
  }

  SuspendRx(IL_CHANNEL_ILPARA_MACRO);

# if defined IL_ENABLE_RX_STOP_DEFAULTVALUE
  /*--- Loop for every receive object ---------------------------------------*/
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilRxHnd = IlRxMsgStartIndex[channel]; ilRxHnd < IlRxMsgStartIndex[(channel + 1)]; ilRxHnd++)
#  else
  for (ilRxHnd = 0; ilRxHnd < kIlNumberOfRxObjects; ilRxHnd++)
#  endif
  {
    IlAssert(ilRxHnd < kIlNumberOfRxObjects, ILERR_ILLRXMSGHANDLE);

    /*-- Set receive buffer to default for some signals, if selected -------*/
    if ((IlRxDefaultInitValue[ilRxHnd] != V_NULL) && (IlRxDefaultStopMask[ilRxHnd] != V_NULL))
    {
      SetRxDefaultWithMask(ilRxHnd, IlRxDefaultStopMask[ilRxHnd]);
    }
  }
# endif

# if defined ( IL_TYPE_GM )
#  if defined( IL_ENABLE_SYS_TESTDEBUG )
  {
    vuint8 ilVnHnd;

#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    for (ilVnHnd = IlVnStartIndex[channel]; ilVnHnd < IlVnStartIndex[(channel + 1)]; ilVnHnd++)
#   else
    for (ilVnHnd = 0; ilVnHnd < kIlNumberOfVirtualNets; ilVnHnd++)
#   endif
    {
      IlAssert(((ilRxActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) == 0), ILERR_RXVNACTIVATED);
      IlAssert(((ilRxSVActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) == 0), ILERR_RXVNTIMEOUTACTIVATED);
    }
  }
#  endif
  IlResetRxTimeoutFlags(IL_CHANNEL_ILPARA_ONLY);
# endif/* IL_TYPE_GM */

  /*---- call user defined function on stop of reception path of IAL --------*/
# if defined IL_ENABLE_SYS_RX_STOP_FCT
  ApplIlRxStop(IL_CHANNEL_ILPARA_ONLY);
# endif
# if defined( IL_ENABLE_RX_SIGNAL_STOP_FCT )
  IlSignalRxStop(IL_CHANNEL_ILPARA_ONLY);
# endif

#else /* IL_ENABLE_RX */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
# endif
#endif /* IL_ENABLE_RX */
}                               /* End of IlRxStop() */

/**********************************************************************************************************************
  IlTxStop
**********************************************************************************************************************/
void IlTxStop(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( IL_ENABLE_TX )

# if defined IL_ENABLE_TX_STOP_DEFAULTVALUE
  IlTransmitHandle ilTxHnd;
# endif

  if (TxSuspended(IL_CHANNEL_ILPARA_MACRO))
  {
    return;
  }
  SuspendTx(IL_CHANNEL_ILPARA_MACRO);

# if defined IL_ENABLE_TX_STOP_DEFAULTVALUE
  /*--- Loop for every receive object ---------------------------------------*/
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilTxHnd = IlTxMsgStartIndex[channel]; ilTxHnd < IlTxMsgStartIndex[(channel + 1)]; ilTxHnd++)
#  else
  for (ilTxHnd = 0; ilTxHnd < kIlNumberOfTxObjects; ilTxHnd++)
#  endif
  {
    IlAssert(ilTxHnd < kIlNumberOfTxObjects, ILERR_ILLTXMSGHANDLE);

    /*-- Set receive buffer to default for some signals, if selected -------*/
    if ((IlTxDefaultInitValue[ilTxHnd] != V_NULL) && (IlTxDefaultStopMask[ilTxHnd] != V_NULL)
#  if defined( IL_ENABLE_SYS_MULTI_ECU_PHYS )
        && ((IlTxIdentityAssignment[ilTxHnd] & V_ACTIVE_IDENTITY_MSK) != (tVIdentityMsk) 0)
#  endif
      )
    {
      SetTxDefaultWithMask(ilTxHnd, IlTxDefaultStopMask[ilTxHnd]);
    }
  }
# endif

# if defined ( IL_TYPE_GM )
#  if defined( IL_ENABLE_SYS_TESTDEBUG )
  {
    vuint8 ilVnHnd;

#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    for (ilVnHnd = IlVnStartIndex[channel]; ilVnHnd < IlVnStartIndex[(channel + 1)]; ilVnHnd++)
#   else
    for (ilVnHnd = 0; ilVnHnd < kIlNumberOfVirtualNets; ilVnHnd++)
#   endif
    {
      IlAssert(((ilTxActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) == 0), ILERR_TXVNACTIVATED);
    }
  }
#  endif
# endif/* IL_TYPE_GM */

  /*---- call user defined function on stop of transmission path of IAL -----*/
# if defined IL_ENABLE_SYS_TX_STOP_FCT
  ApplIlTxStop(IL_CHANNEL_ILPARA_ONLY);
# endif
# if defined( IL_ENABLE_TX_SIGNAL_STOP_FCT )
  IlSignalTxStop(IL_CHANNEL_ILPARA_ONLY);
# endif

#else /* IL_ENABLE_TX */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
# endif
#endif /* IL_ENABLE_TX */
}                               /* End of IlTxStop() */

/**********************************************************************************************************************
  IlRxWait
**********************************************************************************************************************/
void IlRxWait(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( IL_ENABLE_RX )
  if (RxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    WaitRx(IL_CHANNEL_ILPARA_MACRO);
  }
#else /* IL_ENABLE_RX */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
# endif
#endif /* IL_ENABLE_RX */
}                               /* End of IlRxWait() */

/**********************************************************************************************************************
  IlTxWait
**********************************************************************************************************************/
void IlTxWait(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( IL_ENABLE_TX )
  if (TxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    WaitTx(IL_CHANNEL_ILPARA_MACRO);
  }
#else /* IL_ENABLE_TX */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
# endif
#endif /* IL_ENABLE_TX */
}                               /* End of IlTxWait() */

/**********************************************************************************************************************
  IlRxRelease
**********************************************************************************************************************/
void IlRxRelease(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( IL_ENABLE_RX )

# if defined( IL_ENABLE_RX_TIMEOUT )
  IlRxTimeoutHandle ilRxToHnd;
# endif

  if (RxWaiting(IL_CHANNEL_ILPARA_MACRO))
  {
# if defined( IL_ENABLE_RX_TIMEOUT )

    /* reset old message indications for Timeout supervision */
    ResetRxTimerFlags(IL_CHANNEL_ILPARA_MACRO);

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    for (ilRxToHnd = IlRxTimeoutCntStartIndex[channel]; ilRxToHnd < IlRxTimeoutCntStartIndex[(channel + 1)];
         ilRxToHnd++)
#  else
    for (ilRxToHnd = 0; ilRxToHnd < kIlNumberOfRxTimeoutCounters; ilRxToHnd++)
#  endif
    {
      IlAssert(ilRxToHnd < kIlNumberOfRxTimeoutCounters, ILERR_ILLRXTIMEOUTINDEX);

      /*--- Reset timeout counter to its initial state --------------------*/
#  if defined ( IL_ENABLE_RX_TIMEOUT_DELAY )
      /* Timeout observation starts with first receive of a message */
      ilRxTimeoutCounter[ilRxToHnd] = 0;
#  else
      ilRxTimeoutCounter[ilRxToHnd] = IlGetStartRxTimeoutCounter(ilRxToHnd);
#  endif
    }
# endif

# if defined ( IL_ENABLE_SYS_RX_RESET_TIMEOUT_FLAGS_ON_ILRXRELEASE )
    IlResetRxTimeoutFlags(IL_CHANNEL_ILPARA_ONLY);
# endif

# if defined ( IL_TYPE_GM )
#  if defined( IL_ENABLE_RX_EXT_TIMEOUT )
    {
      vuintx i;
      for (i = 0; i < (vuintx) ilNrOfLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO]; i++)
      {
        /* Restart the timer */
        if (ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][i] != 0)
        {
          ilExtIdRxSrcAddrTimer[IL_CHANNEL_ILPARA_MACRO][i] = IlGetRxNcaMsgTimeoutCnt(IL_CHANNEL_ILPARA_ONLY);
        }
      }
      ilExtIdRxDefaultTimer[IL_CHANNEL_ILPARA_MACRO] = IlGetRxNcaMsgTimeoutCnt(IL_CHANNEL_ILPARA_ONLY);
    }
#  endif
# endif/* IL_TYPE_GM */

    EnableRx(IL_CHANNEL_ILPARA_MACRO);
  }

#else /* IL_ENABLE_RX */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
# endif
#endif /* IL_ENABLE_RX */
}                               /* End of IlRxRelease() */

/**********************************************************************************************************************
  IlTxRelease
**********************************************************************************************************************/
void IlTxRelease(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( IL_ENABLE_TX )
  if (TxWaiting(IL_CHANNEL_ILPARA_MACRO))
  {
    EnableTx(IL_CHANNEL_ILPARA_MACRO);
  }

#else /* IL_ENABLE_TX */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
# endif
#endif /* IL_ENABLE_TX */
}                               /* End of IlTxRelease() */

/**********************************************************************************************************************
  IlRxTask
**********************************************************************************************************************/
void IlRxTask(IL_CHANNEL_ILTYPE_ONLY)
{
  IlRxStateTask(IL_CHANNEL_ILPARA_ONLY);
  IlRxTimerTask(IL_CHANNEL_ILPARA_ONLY);
}                               /* End of IlRxTask() */

/**********************************************************************************************************************
  IlRxStateTask
**********************************************************************************************************************/
void IlRxStateTask(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( IL_ENABLE_RX )

# if defined( IL_ENABLE_RX_POLLING ) || defined( IL_ENABLE_RX_EXT_TIMEOUT )
  /* This check shall avoid, that Signal Indication "hangs" without precopy */
#  if defined( C_ENABLE_GENERIC_PRECOPY )
  /* Check if any message for this channel has been received */
  if (IlGetChannelReceived(IL_CHANNEL_ILPARA_MACRO) == 0)
  {
    return;
  }
  /* Reset the channel flag */
  IlClrChannelReceived(IL_CHANNEL_ILPARA_MACRO);
#  endif /* C_ENABLE_GENERIC_PRECOPY */

  if (RxNotSuspended(IL_CHANNEL_ILPARA_MACRO))
  {
#  if defined( IL_ENABLE_RX_POLLING )
    CanReceiveHandle canRxHnd;

      /*--- Loop for every receive object ---------------------------------------*/
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    for (canRxHnd = IlCanRxMsgStartIndex[channel]; canRxHnd < IlCanRxMsgStartIndex[(channel + 1)]; canRxHnd++)
#   else
    for (canRxHnd = 0; canRxHnd < (CanReceiveHandle) kIlCanNumberOfRxObjects; canRxHnd++)
#   endif
    {
      /* Efficiency might be improved, but this is the way how the CAN-driver does it */
      if ((IlGetRxIndicationFlags(IlGetRxIndicationOffset(canRxHnd)) & IlGetRxIndicationMask(canRxHnd)) !=
          0)
      {
        /*  clear the Indication flags */
        CanInterruptDisable();
        IlGetRxIndicationFlags(IlGetRxIndicationOffset(canRxHnd)) &=
          (vuint8) ~ IlGetRxIndicationMask(canRxHnd);
        CanInterruptRestore();

        if (IlCanRxIndicationFctPtr[canRxHnd] != V_NULL)
        {
          IlCanRxIndicationFctPtr[canRxHnd] ();
        }
      }
    }
#  endif

#  if defined ( IL_TYPE_GM )
#   if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
    {
      vuint8 index;
      vuint8 srcAddress;
      IlReceiveHandle ilRxHnd;
      IlReceiveHandle ilRxExtIdHnd;

      while (ilExtIdRxSrcAddressQueueCount[IL_CHANNEL_ILPARA_MACRO] != 0)
      {
        CanInterruptDisable();
        ilExtIdRxSrcAddressQueueCount[IL_CHANNEL_ILPARA_MACRO]--;
        srcAddress =
          ilExtIdRxSrcAddressQueue[IL_CHANNEL_ILPARA_MACRO][ilExtIdRxSrcAddressQueueCount[IL_CHANNEL_ILPARA_MACRO]];
        ilRxHnd =
          ilExtIdRxObjHandleQueue[IL_CHANNEL_ILPARA_MACRO][ilExtIdRxSrcAddressQueueCount[IL_CHANNEL_ILPARA_MACRO]];
        CanInterruptRestore();

        /* Yes, it is. Restart timer and learn src address */
        index = IlProcessLearnedSourceAddress(IL_CHANNEL_ILPARA_FIRST srcAddress);

        ilRxExtIdHnd = IlGetRxExtIdHnd(ilRxHnd);

        /* source address for a message has been changed/learned */

        if ((index < kIlNrOfConfigNodes) && (ilRxHnd != IlGetRxNcaMsg(IL_CHANNEL_ILPARA_ONLY))
            && (ilExtIdRxMsgIdxOfSourceAddress[ilRxExtIdHnd] != index))
        {
          vuint8 srcAddressIndex = ilExtIdRxMsgIdxOfSourceAddress[ilRxExtIdHnd];
#    if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
          vuint8 ilBitIndex =
            ((IlGetPackedRxObjectsStartIndex(IL_CHANNEL_ILPARA_MACRO) * 8) +
             (ilRxHnd - IlRxMsgStartIndex[IL_CHANNEL_ILPARA_MACRO]));
#    endif

          /* previously used index */
          if ((ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO][(srcAddressIndex >> 3)] &
               LSB2MSBBitMask[(srcAddressIndex & 0x07)]) != 0)
          {
            /* New learned source address, but old one indicated a supervision failure */
            IlRxMessageRecovery(ilRxExtIdHnd);
          }

          /* Keep the next lines consistent to prevent a supervision */
          /* state change while swapping the node addressing.        */
          CanInterruptDisable();

          ilExtIdRxMsgIdxOfSourceAddress[ilRxExtIdHnd] = index;

          /* Check if supervision is currently active for this message */
#    if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
          if ((ilVnRxSupervisionActive[ilBitIndex >> 3] & LSB2MSBBitMask[ilBitIndex & 0x07]) != 0)
#    else
          if ((ilVnRxSupervisionActive[ilRxHnd >> 3] & LSB2MSBBitMask[ilRxHnd & 0x07]) != 0)
#    endif
          {
            /* First learned message of the node. VN is active -> start timer */
            if (ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][index] == 0)
            {
              ilExtIdRxSrcAddrTimer[IL_CHANNEL_ILPARA_MACRO][index] = IlGetRxNcaMsgTimeoutCnt(IL_CHANNEL_ILPARA_ONLY);
            }
            /* Decrement active messages for this node from previous index */
            if (ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][srcAddressIndex] != 0)
            {
              ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][srcAddressIndex]--;
            }
            /* is now changed to the new index */
            ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][index]++;
          }
          CanInterruptRestore();

          /* Indicate to the application the new learned source address for this message */
          ApplIlRxMsgSrcAddressLearned(IL_CHANNEL_ILPARA_FIRST ilRxHnd, srcAddress);
        }
      }
    }
#   endif
#  endif
       /* IL_TYPE_GM */
  }
# else /* IL_ENABLE_RX_POLLING || IL_ENABLE_RX_EXT_TIMEOUT */
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
#  endif
# endif /* IL_ENABLE_RX_POLLING || IL_ENABLE_RX_EXT_TIMEOUT */

#else /* IL_ENABLE_RX */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
# endif
#endif /* IL_ENABLE_RX */
}                               /* End of IlRxStateTask() */

/**********************************************************************************************************************
  IlRxTimerTask
**********************************************************************************************************************/
void IlRxTimerTask(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( IL_ENABLE_RX )

# if defined( IL_ENABLE_RX_TIMEOUT )
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  IlRxTimeoutHandle ilRxToHnd = IlRxTimeoutCntStartIndex[channel];
#  else
  IlRxTimeoutHandle ilRxToHnd = 0;
#  endif
  vuint8 ilRxPackedIndex;
  vuint8 ilRxPackedMask = 0x01;
# endif

  if (!RxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    return;
  }

# if defined( IL_ENABLE_RX_TIMEOUT )

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilRxPackedIndex = IlRxTimerFlagsStartIndex[channel]; ilRxPackedIndex < IlRxTimerFlagsStartIndex[channel + 1];
       ilRxPackedIndex++)
#  else
  for (ilRxPackedIndex = 0; ilRxPackedIndex < kIlNumberOfTimerFlagBytes; ilRxPackedIndex++)
#  endif
  {
    vuint8 ilBitMask = 0xFF;
    vuint8 ilFlagMask;

    CanInterruptDisable();
    ilFlagMask = ilRxTimerFlags[ilRxPackedIndex];
    ilRxTimerFlags[ilRxPackedIndex] = 0;
    CanInterruptRestore();

    while (ilBitMask != 0x00)
    {
      ilBitMask &= (vuint8) ~ (ilRxPackedMask & 0xFFu);
      if ((ilFlagMask & ilRxPackedMask) != 0)
      {
        ilRxTimeoutCounter[ilRxToHnd] = IlGetStartRxTimeoutCounter(ilRxToHnd);
      }
      else
      {
#  if defined ( IL_TYPE_GM )
        vuint8 ilRxHnd = IlRxTimeout2MsgIndirection[ilRxToHnd];
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
        vuint8 ilBitIndex =
          ((IlGetPackedRxObjectsStartIndex(IL_CHANNEL_ILPARA_MACRO) * 8) +
           (ilRxHnd - IlRxMsgStartIndex[IL_CHANNEL_ILPARA_MACRO]));
        if ((ilVnRxSupervisionActive[ilBitIndex >> 3] & LSB2MSBBitMask[ilBitIndex & 0x07]) != 0)
#   else
        if ((ilVnRxSupervisionActive[ilRxHnd >> 3] & LSB2MSBBitMask[ilRxHnd & 0x07]) != 0)
#   endif
#  endif
       /* IL_TYPE_GM */
        {
#  if defined( IL_ENABLE_RX_DYNAMIC_TIMEOUT )
          if (ilRxTimeoutCounter[ilRxToHnd] != kIlNoRxTimeoutSupervision)
          {
#  endif
            if (ilRxTimeoutCounter[ilRxToHnd] != 0)
            {
              ilRxTimeoutCounter[ilRxToHnd]--;
              if (ilRxTimeoutCounter[ilRxToHnd] == 0)
              {
                (*IlRxTimeoutFctPtr[ilRxToHnd]) ();
              }
            }
#  if defined( IL_ENABLE_RX_DYNAMIC_TIMEOUT )
          }
#  endif
        }
      }
      if (ilRxPackedMask == 0x80)
      {
        ilRxPackedMask = 0x01;
      }
      else
      {
        ilRxPackedMask <<= 1;
      }
      ilRxToHnd++;

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
      if (ilRxToHnd >= IlRxTimeoutCntStartIndex[(channel + 1)])
#  else
      if (ilRxToHnd >= kIlNumberOfRxTimeoutCounters)
#  endif
      {
        ilBitMask = 0x00;
      }
    }
  }
# endif/* IL_ENABLE_RX_TIMEOUT */

# if defined ( IL_TYPE_GM )
#  if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
  /*--- Count down the default timer for unlearned nodes -----------------*/
  if (ilExtIdRxDefaultTimer[IL_CHANNEL_ILPARA_MACRO] != 0)
  {
    ilExtIdRxDefaultTimer[IL_CHANNEL_ILPARA_MACRO]--;

    /* Default timer expired */
    if (ilExtIdRxDefaultTimer[IL_CHANNEL_ILPARA_MACRO] == 0)
    {
      /* Notify all possible active non-learned messages that are optional */
      if (IlNodeCommActiveFailed(IL_CHANNEL_ILPARA_FIRST(vuint8) kOptionalSourceAddress) == kIlTimeoutEvent)    /* Optional messages */
      {
        ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO][(kOptionalSourceAddressIdx >> 3)] |=
          LSB2MSBBitMask[(kOptionalSourceAddressIdx & 0x07)];
      }

      /* Notify all possible active non-learned messages that are mandatory */
      if (IlNodeCommActiveFailed(IL_CHANNEL_ILPARA_FIRST(vuint8) kMandatorySourceAddress) == kIlTimeoutEvent)   /* Mandatory messages */
      {
        ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO][(kMandatorySourceAddressIdx >> 3)] |=
          LSB2MSBBitMask[(kMandatorySourceAddressIdx & 0x07)];
      }
    }
  }                             /* End of Default timer condition */

  {
    vuintx i;
    /*-- Loop through all the source address timers to count down the timer */
    for (i = 0; i < (vuintx) ilNrOfLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO]; i++)
    {
      /* If at least one Virtual Network is active        */
      /* for this node, count down the supervision timer. */
      if (ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][i] != 0)
      {
        /* Message didn't come in. Decrement its timer */
        if (ilExtIdRxSrcAddrTimer[IL_CHANNEL_ILPARA_MACRO][i] != 0)
        {
          ilExtIdRxSrcAddrTimer[IL_CHANNEL_ILPARA_MACRO][i]--;

          /* Timer expired. Do Signal supervision failure indication */
          if (ilExtIdRxSrcAddrTimer[IL_CHANNEL_ILPARA_MACRO][i] == 0)
          {
            if (IlNodeCommActiveFailed
                (IL_CHANNEL_ILPARA_FIRST ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO][i]) ==
                kIlTimeoutEvent)
            {
              ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO][(i >> 3)] |= LSB2MSBBitMask[(((vuint8) i) & 0x07)];
            }
          }
        }
      }
    }
  }
#  endif/* IL_ENABLE_RX_EXT_TIMEOUT */
# endif/* IL_TYPE_GM */

#else /* IL_ENABLE_RX */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
# endif

#endif /* IL_ENABLE_RX */
}                               /* End of IlRxTimerTask() */

/**********************************************************************************************************************
  IlInit
**********************************************************************************************************************/
void IlTxTask(IL_CHANNEL_ILTYPE_ONLY)
{
  IlTxStateTask(IL_CHANNEL_ILPARA_ONLY);
  IlTxTimerTask(IL_CHANNEL_ILPARA_ONLY);
}                               /* End of IlTxTask() */

/**********************************************************************************************************************
  IlTxStateTask
**********************************************************************************************************************/
void IlTxStateTask(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( IL_ENABLE_TX )
  IlTransmitHandle ilTxHnd;
  CanTransmitHandle x;

  /* Check if any message for this channel has been recived */
  if (TxNotSuspended(IL_CHANNEL_ILPARA_MACRO))
  {
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    ilTxHnd = IlTxMsgStartIndex[channel + 1];
    if (IlTxMsgStartIndex[channel] == ilTxHnd)
    {
      return;
    }
# else
    ilTxHnd = kIlNumberOfTxObjects;
# endif
    /*--- Loop for every transmit object ---------------------------------------*/
    do
    {
      /* Initial Decrement */
      ilTxHnd--;

      /* Go from IL handle to CAN handle */
      x = IlGetIlTxIndirection(ilTxHnd);

      if (x != kCanTxHandleNotUsed)
      {
        /* Efficiency might be improved, but this is the way how the CAN-driver does it */
        if ((IlGetTxConfirmationFlags(IlGetTxConfirmationOffset(x)) & IlGetTxConfirmationMask(x)) != 0)
        {
          /*  Clear the Confirmation flags */
          CanInterruptDisable();
          IlGetTxConfirmationFlags(IlGetTxConfirmationOffset(x)) &= (vuint8) ~ IlGetTxConfirmationMask(x);
          /* Counter for Update time must be reloaded twice, here and in confirmation fct */
          ilTxUpdateCounter[ilTxHnd] = IlTxUpdateCycles[ilTxHnd];
          CanInterruptRestore();

# if defined( IL_ENABLE_TX_POLLING )
          if (IlTxConfirmationFctPtr[ilTxHnd] != V_NULL)
          {
            IlTxConfirmationFctPtr[ilTxHnd] ();
          }
# endif
        }
      }
# if defined IL_ENABLE_SYS_TRANSMIT_IN_STATETASK

#  error "in case of multiple ECU ILSendMessage is only allowed to be called for Tx messages of the current ECU"

      /*********************************************************************/
      /*-- Send message if send request is set AND update time expired ----*/
      /*********************************************************************/
      if (((ilTxState[ilTxHnd] & kTxSendRequest) != 0) && (ilTxUpdateCounter[ilTxHnd] == 0))
      {
#  if defined ( IL_ENABLE_TX_TIMEOUT )
        if ((ilTxState[ilTxHnd] & kTxCheckTimeout) != 0)
        {
          /* start Timeout supervision for this message */
          IlAssert(IlTxTimeoutIndirection[ilTxHnd] < kIlNumberOfTxTimeoutCounters, ILERR_ILLTXTIMEOUTINDEX);
          CanInterruptDisable();
          if (ilTxTimeoutCounter[IlTxTimeoutIndirection[ilTxHnd]] == 0)
          {
            ilTxTimeoutCounter[IlTxTimeoutIndirection[ilTxHnd]] = IlGetTxTimeout(IL_CHANNEL_ILPARA_MACRO);
          }
          CanInterruptRestore();
        }
#  endif
        IlSendMessage(ilTxHnd);
      }
# endif
    }
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    while (ilTxHnd != IlTxMsgStartIndex[channel]);
# else
    while (ilTxHnd != 0);
# endif
  }

#else /* IL_ENABLE_TX */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
# endif
#endif /* IL_ENABLE_TX */
}                               /* End of IlTxStateTask() */

/**********************************************************************************************************************
  IlTxTimerTask
**********************************************************************************************************************/
void IlTxTimerTask(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( IL_ENABLE_TX )
  IlTransmitHandle ilTxHnd;

  /*----- do Tx-task only if Tx is started ----------------------------------*/
  if (TxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
# if defined ( IL_ENABLE_TX_TIMEOUT )
    IlCheckTxTimeout(IL_CHANNEL_ILPARA_ONLY);
# endif

# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    ilTxHnd = IlTxMsgStartIndex[channel + 1];
    if (IlTxMsgStartIndex[channel] == ilTxHnd)
    {
      return;
    }
# else
    ilTxHnd = kIlNumberOfTxObjects;
# endif
    /*--- Loop for every transmit object ---------------------------------------*/
    do
    {
      /* Initial Decrement */
      ilTxHnd--;
      IlAssert((ilTxHnd < kIlNumberOfTxObjects), ILERR_ILLTXMSGHANDLE);

# if defined( IL_ENABLE_SYS_MULTI_ECU_PHYS )
      /* Suppress  message that is not assigned for this Multi-ECU. */
      if ((IlTxIdentityAssignment[ilTxHnd] & V_ACTIVE_IDENTITY_MSK) == (tVIdentityMsk) 0)
      {
        continue;
      }
# endif

      /*********************************************************************/
      /**** Global section. ************************************************/
      /*********************************************************************/

      CanInterruptDisable();
      /*-- decrement counter for update time ------------------------------*/
      if ((ilTxUpdateCounter[ilTxHnd] != kIlStopUpdateCounterValue) && (ilTxUpdateCounter[ilTxHnd] > 0))
      {
        ilTxUpdateCounter[ilTxHnd]--;
      }
      CanInterruptRestore();

      {
# if defined ( IL_TYPE_GM )
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
        vuint8 ilBitIndex =
          ((IlGetPackedTxObjectsStartIndex(IL_CHANNEL_ILPARA_MACRO) * 8) +
           (ilTxHnd - IlTxMsgStartIndex[IL_CHANNEL_ILPARA_MACRO]));
        if ((ilVnTxMessageActive[ilBitIndex >> 3] & LSB2MSBBitMask[ilBitIndex & 0x07]) != 0)
#  else
        if ((ilVnTxMessageActive[ilTxHnd >> 3] & LSB2MSBBitMask[ilTxHnd & 0x07]) != 0)
#  endif
# endif/* IL_TYPE_GM */
        {
          /*********************************************************************/
          /**** Section for the CYCLIC messages ********************************/
          /*********************************************************************/

          /*-- Check if Cyclic send is active for this message ----------------*/
          if ((ilTxState[ilTxHnd] & kTxSendCyclic) != 0)
          {
            if (ilTxCyclicCounter[ilTxHnd] != 0)    /* decrement timer counter      */
            {
              ilTxCyclicCounter[ilTxHnd]--; /*   only if not 0              */
            }

            /*-- Tx timer expired -> request to send message -----------------*/
            if (ilTxCyclicCounter[ilTxHnd] == 0)
            {
# if  defined ( IL_ENABLE_TX_FAST_ON_START )
#  if defined ( VGEN_GENY ) && defined( IL_ENABLE_TX_MODE_SIGNALS )
              if ((ilTxState[ilTxHnd] & kTxFastOnStart) != 0)
              {
                if (IlTxFastOnStartMuxDelay[ilTxHnd] != 0)
                {
                  /*---- only multiplexed ilTxHnd ----*/
                  ilTxCyclicCounter[ilTxHnd] = IlTxFastOnStartMuxDelay[ilTxHnd];
                  ilTxEventCounter[ilTxHnd] = IlTxFastOnStartMuxDelay[ilTxHnd];
                }
                else
                {
                  /*-- Reload the cycle counter for the cyclic message ----------*/
                  ilTxCyclicCounter[ilTxHnd] = IlGetTxCyclicCycles(ilTxHnd);
                }
#  endif

                CanInterruptDisable();
                ilTxState[ilTxHnd] &= kTxNotFastOnStart;
                CanInterruptRestore();

#  if defined ( VGEN_GENY ) && defined( IL_ENABLE_TX_MODE_SIGNALS )
              }
              else
#  endif
# endif/* IL_ENABLE_TX_FAST_ON_START */
              {
                 /*-- Reload the cycle counter for the cyclic message ----------*/
                ilTxCyclicCounter[ilTxHnd] = IlGetTxCyclicCycles(ilTxHnd);
              }

# if defined ( IL_ENABLE_TX_CYCLIC_EVENT )  || \
    defined ( IL_ENABLE_TX_FAST_ON_START )
              if ((ilTxState[ilTxHnd] & (kTxSendCyclicEvent | kTxFastOnStart)) == 0)
# endif
              {
# if defined ( IL_ENABLE_TX_SECURE_EVENT )
                if ((ilTxNSendCounter[ilTxHnd]) == 0)
# endif
                {
                  /* only if nothing is send fast */
                    /*-- Set the send request bit in tx-status field --------------*/
                  CanInterruptDisable();
                  ilTxState[ilTxHnd] |= kTxSendRequest;
                  CanInterruptRestore();
                }
              }
            }
          }

# if defined ( IL_ENABLE_TX_CYCLIC_EVENT ) || defined ( IL_ENABLE_TX_SECURE_EVENT ) || \
    defined ( IL_ENABLE_TX_FAST_ON_START )

            /*********************************************************************/
            /**** Section for the CYCLIC- and SECURE-EVENT messages **************/
            /*********************************************************************/

            /*-- Check if Cyclic event send is active for this message ----------*/
#  if defined( IL_ENABLE_TX_SECURE_EVENT )
          if (((ilTxState[ilTxHnd] & (kTxSendCyclicEvent | kTxFastOnStart)) != 0)
              || (ilTxNSendCounter[ilTxHnd] != 0))
#  else
          if ((ilTxState[ilTxHnd] & (kTxSendCyclicEvent | kTxFastOnStart)) != 0)
#  endif
          {
            if (ilTxEventCounter[ilTxHnd] != 0)     /* decrement timer counter */
            {
              ilTxEventCounter[ilTxHnd]--;  /*   only if not 0        */
            }

            /*-- Tx EventTimer expired -> request to send message ------------*/
            if (ilTxEventCounter[ilTxHnd] == 0)
            {
              CanInterruptDisable();
#  if defined( IL_ENABLE_TX_SECURE_EVENT )
              if (ilTxNSendCounter[ilTxHnd] != 0)
              {
                ilTxState[ilTxHnd] |= (kTxSendRequest | kTxNSendRequest);
              }
              else
#  endif
              {
                ilTxState[ilTxHnd] |= kTxSendRequest;
              }
              CanInterruptRestore();

              ilTxEventCounter[ilTxHnd] = IlTxEventCycles[ilTxHnd];
            }
          }
# endif/* IL_ENABLE_TX_CYCLIC_EVENT || IL_ENABLE_TX_SECURE_EVENT || IL_ENABLE_TX_FAST_ON_START */
          /*********************************************************************/
          /*-- Send message if send request is set AND update time expired ----*/
          /*********************************************************************/
          if (((ilTxState[ilTxHnd] & kTxSendRequest) != 0) && (ilTxUpdateCounter[ilTxHnd] == 0))
          {
# if defined ( IL_ENABLE_TX_TIMEOUT )
            if ((ilTxState[ilTxHnd] & kTxCheckTimeout) != 0)
            {
              /* start Timeout supervision for this message */
              IlAssert(IlTxTimeoutIndirection[ilTxHnd] < kIlNumberOfTxTimeoutCounters,
                           ILERR_ILLTXTIMEOUTINDEX);
              CanInterruptDisable();
              if (ilTxTimeoutCounter[IlTxTimeoutIndirection[ilTxHnd]] == 0)
              {
                ilTxTimeoutCounter[IlTxTimeoutIndirection[ilTxHnd]] =
                  IlGetTxTimeout(IL_CHANNEL_ILPARA_MACRO);
              }
              CanInterruptRestore();
            }
# endif
            IlSendMessage(ilTxHnd);
          }
        }
      }
    }
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    while (ilTxHnd != IlTxMsgStartIndex[channel]);
# else
    while (ilTxHnd != 0);
# endif
  }                             /* if TxEnabled */
#else /* IL_ENABLE_TX */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
# endif
#endif /* IL_ENABLE_TX */
}                               /* End of IlTxTimerTask() */

#if defined ( C_ENABLE_CAN_CANCEL_NOTIFICATION )
/**********************************************************************************************************************
  IlCanCancelNotification
**********************************************************************************************************************/
/** \brief    This method is called if a transmit message is deleted (CanCancelTransmit, CanOffline or CanInit)
              and the update counter will be reset.
    \param    txHandle     Handle of the Can Driver tx message.
    \return   none
    \context  The function can be called on task and interupt level.
    \note     The function is called by the Can Driver. Either IlCanCancelNotification is exclusively called or
              the Can Driver sets a confirmation flag or calls a confirmation function.
**********************************************************************************************************************/
void IlCanCancelNotification(CanTransmitHandle txHandle)
{
# if defined ( IL_ENABLE_TX )

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  CanChannelHandle channel = CanGetChannelOfTxObj(txHandle);
#  endif
  IlTransmitHandle ilTxHnd;

   /*----- do the loop for every Tx object  -------------------------------*/
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilTxHnd = IlTxMsgStartIndex[channel]; ilTxHnd < IlTxMsgStartIndex[(channel + 1)]; ilTxHnd++)
#  else
  for (ilTxHnd = 0; ilTxHnd < kIlNumberOfTxObjects; ilTxHnd++)
#  endif
  {
    if (IlGetIlTxIndirection(ilTxHnd) == txHandle)
    {
      /* Reset the Update counter when message */
      /* is cancelled by the DLL.              */
      ilTxUpdateCounter[ilTxHnd] = 0;
    }
    /* loop over all objects in case of Multiplex signals */
  }


# else /* IL_ENABLE_TX */
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  txHandle = txHandle;          /* to avoid compiler warnings */
#  endif
# endif /* IL_ENABLE_TX */
}                               /* End of IlCanCancelNotification() */
#endif /* ( C_ENABLE_CAN_CANCEL_NOTIFICATION ) */

#if defined ( C_ENABLE_GENERIC_PRECOPY )
/**********************************************************************************************************************
  IlCanGenericPrecopy
**********************************************************************************************************************/
/** \brief    This method is called immedialtely after the DLC-CHeck and notifies about the reception of a Can message.
              - Received messages with extended CAN identifiers are queued for source address learning.
              - Additional CAN Driver internal processing (message precopy, data copying,
                message indication flag or function) is suppressed,
                if the message is not active in minium one virtual network.
    \param    rcvObject    Handle of the Can Driver tx message.
    \param    dptr         Pointer to the received data in the CAN Controller receive register
    \param    rxStruct     Pointer to the receive structure.
    \return   kCanCopyData, if the data processing shall be continued, else kCanNoCopyData.
    \context  The method can be called on task and interupt level.
    \note     The method is called by the Can Driver.
**********************************************************************************************************************/
# if defined( C_SINGLE_RECEIVE_BUFFER )
vuint8 IlCanGenericPrecopy(CanReceiveHandle rcvObject)
#  define canRxHnd  (rcvObject)
# endif
# if defined( C_MULTIPLE_RECEIVE_BUFFER )
     vuint8 IlCanGenericPrecopy(CanReceiveHandle rcvObject, pChipDataPtr dptr)
#  define canRxHnd  (rcvObject)
# endif
# if defined(C_SINGLE_RECEIVE_CHANNEL) || defined(C_MULTIPLE_RECEIVE_CHANNEL)
     vuint8 IlCanGenericPrecopy(CanRxInfoStructPtr rxStruct)
#  define canRxHnd  (rxStruct->Handle)
# endif
{

# if defined ( IL_ENABLE_RX )

#  if defined ( C_MULTIPLE_RECEIVE_BUFFER ) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  dptr = dptr;                  /* to avoid compiler warnings */
#  endif

  /* Not an IL message */
  if (canRxHnd >= kIlCanNumberOfRxObjects)
  {
    return kCanCopyData;
  }
  if (RxSuspended(IL_CHANNEL_ILPRECOPY_MACRO))
  {                             /* Receive is disabled  */
    return kCanNoCopyData;
  }
#  if defined( IL_ENABLE_RX_MULTI_ECU_PHYS )
  if ((IlCanRxIdentityAssignment[canRxHnd] & V_ACTIVE_IDENTITY_MSK) == (tVIdentityMsk) 0)
  {
    return kCanNoCopyData;
  }
#  endif

#  if defined( IL_ENABLE_RX_POLLING ) || defined( IL_ENABLE_RX_EXT_TIMEOUT )
  IlSetChannelReceived(IL_CHANNEL_ILPRECOPY_MACRO);
#  endif

#  if defined ( IL_TYPE_GM )
  {
    IlReceiveHandle ilRxHnd = IlGetCanRxIndirection(canRxHnd);
#   if defined( IL_ENABLE_RX_EXT_TIMEOUT )
    {
#    if defined( C_SINGLE_RECEIVE_BUFFER )
      if (CanRxActualIdType == kCanIdTypeExt)
#    endif
#    if defined(C_SINGLE_RECEIVE_CHANNEL) || defined(C_MULTIPLE_RECEIVE_CHANNEL)
        if (CanRxActualIdType(rxStruct) == kCanIdTypeExt)
#    endif
        {
#    if defined( C_SINGLE_RECEIVE_BUFFER )
          /* define a block local variable to store the source address */
          vuint8 srcAddress = CanRxActualIdExtLo;
#    endif
#    if defined(C_SINGLE_RECEIVE_CHANNEL) || defined(C_MULTIPLE_RECEIVE_CHANNEL)
          /* define a block local variable to store the source address */
          vuint8 srcAddress = CanRxActualIdExtLo(rxStruct);
#    endif

          IlAssert((ilExtIdRxSrcAddressQueueCount[IL_CHANNEL_ILPRECOPY_MACRO] < kIlMaxRxExtIdQueue),
                   ILERR_EXTID_SRCADDR_QUEUE_OVERFLOW);

          if (ilExtIdRxSrcAddressQueueCount[IL_CHANNEL_ILPRECOPY_MACRO] < kIlMaxRxExtIdQueue)
          {
            ilExtIdRxSrcAddressQueue[IL_CHANNEL_ILPRECOPY_MACRO][ilExtIdRxSrcAddressQueueCount
                                                                 [IL_CHANNEL_ILPRECOPY_MACRO]] = srcAddress;
            ilExtIdRxObjHandleQueue[IL_CHANNEL_ILPRECOPY_MACRO][ilExtIdRxSrcAddressQueueCount
                                                                [IL_CHANNEL_ILPRECOPY_MACRO]] = ilRxHnd;
            ilExtIdRxSrcAddressQueueCount[IL_CHANNEL_ILPRECOPY_MACRO]++;
          }
        }
    }
#   endif
        /* IL_ENABLE_RX_EXT_TIMEOUT */
    {
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
      vuint8 ilBitIndex =
        ((IlGetPackedRxObjectsStartIndex(IL_CHANNEL_ILPRECOPY_MACRO) * 8) +
         (ilRxHnd - IlRxMsgStartIndex[IL_CHANNEL_ILPRECOPY_MACRO]));
      if (((ilVnRxMessageActive[ilBitIndex >> 3] & LSB2MSBBitMask[ilBitIndex & 0x07]) == 0))
#   else
      if (((ilVnRxMessageActive[ilRxHnd >> 3] & LSB2MSBBitMask[ilRxHnd & 0x07]) == 0))
#   endif
      {
        return kCanNoCopyData;
      }
    }
  }
#  endif
       /* IL_TYPE_GM */

  return kCanCopyData;
# else/* IL_ENABLE_RX */
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
#   if defined( C_SINGLE_RECEIVE_BUFFER )
  rcvObject = rcvObject;
#   endif
#   if defined( C_MULTIPLE_RECEIVE_BUFFER )
  rcvObject = rcvObject;
  dptr = dptr;
#   endif
#   if defined(C_SINGLE_RECEIVE_CHANNEL) || defined(C_MULTIPLE_RECEIVE_CHANNEL)
  rxStruct = rxStruct;
#   endif
#  endif/* V_ENABLE_USE_DUMMY_STATEMENT */
  return kCanCopyData;
# endif/* IL_ENABLE_RX */
}                               /* End of IlCanGenericPrecopy() */
#endif /* !IL_TYPE_AUTOSAR && C_ENABLE_GENERIC_PRECOPY */

/**********************************************************************************************************************
  IlGetStatus
**********************************************************************************************************************/
Il_Status IlGetStatus(IL_CHANNEL_ILTYPE_ONLY)
{
  return (Il_Status) Il_ChannelState(IL_CHANNEL_ILPARA_MACRO);
}                               /* End of IlGetStatus() */

#if defined( IL_ENABLE_TX_SEND_ON_INIT )
/**********************************************************************************************************************
  IlSendOnInitMsg
**********************************************************************************************************************/
void IlSendOnInitMsg(IL_CHANNEL_ILTYPE_ONLY)
{
# if defined ( IL_ENABLE_TX )
  IlTransmitHandle ilTxHnd;

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  IlAssert(channel < kIlNumberOfChannels, ILERR_ILLCHANNEL);

#   if defined IL_ENABLE_SYS_ARGCHECK
  if (channel >= kIlNumberOfChannels)
  {
    return;
  }
#   endif
  CanInterruptDisable();
  for (ilTxHnd = IlTxMsgStartIndex[channel]; ilTxHnd < IlTxMsgStartIndex[(channel + 1)]; ilTxHnd++)
#  else
  CanInterruptDisable();
  for (ilTxHnd = 0; ilTxHnd < kIlNumberOfTxObjects; ilTxHnd++)
#  endif
  {
    /*--- Queue message On-Init only if it is configured to be allowed -----*/
    if ((ilTxState[ilTxHnd] & kTxQueueInit) != 0)
    {
      ilTxState[ilTxHnd] |= kTxSendRequest;
    }
  }
  CanInterruptRestore();

# else/* IL_ENABLE_TX */
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
#  endif
# endif/* IL_ENABLE_TX */
}                               /* End of IlSendOnInitMsg() */
#endif /* IL_ENABLE_TX_SEND_ON_INIT */

#if defined IL_ENABLE_TX_STARTSTOP_CYCLIC
/**********************************************************************************************************************
  IlStartCycle
**********************************************************************************************************************/
Il_Status IlStartCycle(IlTransmitHandle ilTxHnd)
{
# if defined ( IL_ENABLE_TX )
  /*----- Check for valid handle numbers ------------------------------------*/
  IlAssert(ilTxHnd < kIlNumberOfTxObjects, ILERR_ILLTXMSGHANDLE);

#  if defined IL_ENABLE_SYS_ARGCHECK
  if (ilTxHnd >= kIlNumberOfTxObjects)
  {
    return IL_ERROR;
  }
#  endif

  /*----- Check if SendState already active for this timebase ---------------*/
  if ((ilTxState[ilTxHnd] & kTxSendCyclic) != 0)
  {
    return IL_QUEUED;
  }

  CanInterruptDisable();
  /*--- Set the flag of the cyclic messages in the --------------------------*/
  ilTxState[ilTxHnd] |= kTxSendCyclic;

  /*--- Init cycle counter to the StartDelayTime (if actual time is greater) */
  if (ilTxCyclicCounter[ilTxHnd] > IlTxStartCycles[ilTxHnd])    /* + 1 already done in the table */
  {
    ilTxCyclicCounter[ilTxHnd] = IlTxStartCycles[ilTxHnd];      /* + 1 already done in the table */
  }
  CanInterruptRestore();

# else /* IL_ENABLE_TX */
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  ilTxHnd = ilTxHnd;
#  endif
# endif /* IL_ENABLE_TX */
  return IL_OK;
}                               /* End of IlStartCycle(() */

/**********************************************************************************************************************
  IlStopCycle
**********************************************************************************************************************/
Il_Status IlStopCycle(IlTransmitHandle ilTxHnd)
{
# if defined ( IL_ENABLE_TX )
  /*----- Check for valid handle numbers ------------------------------------*/
  IlAssert(ilTxHnd < kIlNumberOfTxObjects, ILERR_ILLTXMSGHANDLE);

#  if defined IL_ENABLE_SYS_ARGCHECK
  if (ilTxHnd >= kIlNumberOfTxObjects)
  {
    return IL_ERROR;
  }
#  endif
  CanInterruptDisable();
  ilTxState[ilTxHnd] &= kTxNotSendCyclic;   /* Stop cyclic send        */
  CanInterruptRestore();

# else /* IL_ENABLE_TX */
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  ilTxHnd = ilTxHnd;
#  endif
# endif /* IL_ENABLE_TX */
  return IL_OK;
}                               /* End of IlStopCycle() */
#endif /* IL_ENABLE_TX_STARTSTOP_CYCLIC */


#if defined(IL_ENABLE_TX_CYCLIC_EVENT)
/**********************************************************************************************************************
  IlStartEvent
**********************************************************************************************************************/
Il_Status IlStartEvent(IlTransmitHandle ilTxHnd)
{
  /*----- Check for valid handle numbers ------------------------------------*/
  IlAssert(ilTxHnd < kIlNumberOfTxObjects, ILERR_ILLTXMSGHANDLE);

# if defined IL_ENABLE_SYS_ARGCHECK
  if (ilTxHnd >= kIlNumberOfTxObjects)
  {
    return IL_ERROR;
  }
# endif

  /*--- Start immediately transmission of cyclic event messages -------------*/
  ilTxEventCounter[ilTxHnd] = 0;

  /*-- Set the status of the message for cyclic-event -----------------------*/
  ilTxState[ilTxHnd] |= kTxSendCyclicEvent;

  return (1);
}                               /* End of IlStartEvent() */

/**********************************************************************************************************************
  IlStopEvent
**********************************************************************************************************************/
Il_Status IlStopEvent(IlTransmitHandle ilTxHnd)
{
  /*----- Check for valid handle numbers ------------------------------------*/
  IlAssert(ilTxHnd < kIlNumberOfTxObjects, ILERR_ILLTXMSGHANDLE);

# if defined IL_ENABLE_SYS_ARGCHECK
  if (ilTxHnd >= kIlNumberOfTxObjects)
  {
    return IL_ERROR;
  }
# endif

  /* Stop cyclic send        */
  ilTxState[ilTxHnd] &= kTxNotSendCyclicEvent;

  return (0);
}                               /* End of IlStopEvent() */
#endif /* IL_TX_CYCLIC_EVENT */

#if defined ( IL_ENABLE_TX )
/**********************************************************************************************************************
  IlSetEvent
**********************************************************************************************************************/
void IlSetEvent(IlTransmitHandle ilTxHnd)
{
  /*----- Check for valid handle numbers ------------------------------------*/
  IlAssert(ilTxHnd < kIlNumberOfTxObjects, ILERR_ILLTXMSGHANDLE);

# if defined IL_ENABLE_SYS_ARGCHECK
  if (ilTxHnd >= kIlNumberOfTxObjects)
  {
    return;
  }
# endif

  ilTxState[ilTxHnd] |= kTxSendRequest;
}                               /* End of IlSetEvent() */
#endif /* IL_ENABLE_TX */

#if defined( IL_ENABLE_TX_SECURE_EVENT )
/**********************************************************************************************************************
  IlSecureEvent
**********************************************************************************************************************/
void IlSecureEvent(IlTransmitHandle ilTxHnd)
{
  /*----- Check for valid handle numbers ------------------------------------*/
  IlAssert(ilTxHnd < kIlNumberOfTxObjects, ILERR_ILLTXMSGHANDLE);

# if defined IL_ENABLE_SYS_ARGCHECK
  if (ilTxHnd >= kIlNumberOfTxObjects)
  {
    return;
  }
# endif

  /*--- load repeat counter ---*/
  ilTxNSendCounter[ilTxHnd] = IlGetTxRepetitionCounter(ilTxHnd);

  /*--- Start immediately transmission of cyclic event messages -------------*/
  ilTxEventCounter[ilTxHnd] = 0;
}                               /* End of IlSecureEvent() */
#endif

#if defined ( IL_ENABLE_RX )
# if defined ( IL_ENABLE_RX_INDICATION_FLAG )
/**********************************************************************************************************************
  IlGetSignalIndicationFlag
**********************************************************************************************************************/
vuint8 IlGetSignalIndicationFlag(IlReceiveFlagHandle ilRxFlagHnd)
{
  vuint8 rc;

  CanInterruptDisable();

  rc = ilRxIndicationFlags[IlIndicationOffset[ilRxFlagHnd]] & IlIndicationMask[ilRxFlagHnd];
  if (rc != 0)
  {
    /* reset indication flag */
    ilRxIndicationFlags[IlIndicationOffset[ilRxFlagHnd]] &= (vuint8) ~ (IlIndicationMask[ilRxFlagHnd]);
  }

  CanInterruptRestore();

  return (rc);
}                               /* End of IlGetSignalIndicationFlag() */
# endif /* ( IL_ENABLE_RX_INDICATION_FLAG ) */
#endif

/**********************************************************************************************************************
  IlResetRxTimeoutFlags
**********************************************************************************************************************/
void IlResetRxTimeoutFlags(IL_CHANNEL_ILTYPE_ONLY)
{
#if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
#endif

#if defined ( IL_ENABLE_RX )
  ResetRxTimeoutFlags(channel);
#endif /* IL_ENABLE_RX */

#if defined ( IL_TYPE_GM )
# if defined( IL_ENABLE_RX_EXT_TIMEOUT )
  VStdMemClr(ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO], kIlNrOfPackedSourceAddressBytes);
# endif
#endif /* IL_TYPE_GM */
}                               /* End of IlResetRxTimeoutFlags() */

#if defined ( IL_ENABLE_TX ) && defined( IL_ENABLE_SEND_DIRECT )
/**********************************************************************************************************************
  IlSendDirect
**********************************************************************************************************************/
void IlSendDirect(IL_CHANNEL_ILTYPE_FIRST IlTransmitHandle ilTxHnd)
{
  IlAssert(ilTxHnd < kIlNumberOfTxObjects, ILERR_ILLTXMSGHANDLE);
# if defined ( IL_ENABLE_SYS_ARGCHECK )
  if (ilTxHnd >= kIlNumberOfTxObjects)
  {
    return;
  }
# endif

  if (TxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    if ((ilTxState[ilTxHnd] & kTxSendRequest) != 0)
    {
# if defined ( IL_ENABLE_TX_TIMEOUT )
      if ((ilTxState[ilTxHnd] & kTxCheckTimeout) != 0)
      {
        /* start Timeout supervision for this message */
        IlAssert(IlTxTimeoutIndirection[ilTxHnd] < kIlNumberOfTxTimeoutCounters, ILERR_ILLTXTIMEOUTINDEX);
        CanInterruptDisable();
        if (ilTxTimeoutCounter[IlTxTimeoutIndirection[ilTxHnd]] == 0)
        {
          ilTxTimeoutCounter[IlTxTimeoutIndirection[ilTxHnd]] = IlGetTxTimeout(IL_CHANNEL_ILPARA_MACRO);
        }
        CanInterruptRestore();
      }
# endif
      IlSendMessage(ilTxHnd);
    }
  }
}                               /* End of IlSendDirect() */
#endif /* ( IL_ENABLE_TX ) && ( IL_ENABLE_SEND_DIRECT ) */


#if defined( VGEN_GENY ) && defined( IL_ENABLE_TX_DYNAMIC_CYCLETIME )
/**********************************************************************************************************************
  IlSetDynTxCycleTimeRaw
**********************************************************************************************************************/
void IlSetDynTxCycleTimeRaw(IlTransmitHandle ilTxHnd, IltTxCounter ilTxTicks)
{
  IlAssert(ilTxHnd < kIlNumberOfTxObjects, ILERR_ILLTXMSGHANDLE);
# if defined ( IL_ENABLE_SYS_ARGCHECK )
  if (ilTxHnd >= kIlNumberOfTxObjects)
  {
    return;
  }
# endif
  ilTxDynCyclicCycles[ilTxHnd] = ilTxTicks;
}                               /* End of IlSetDynTxCycleTimeRaw() */
#endif  /* VGEN_GENY && IL_ENABLE_TX_DYNAMIC_CYCLETIME */

#if defined( VGEN_GENY ) && defined( IL_ENABLE_SYS_TX_REPETITIONS_ARE_ACTIVE_FCT )
/**********************************************************************************************************************
  IlTxRepetitionsAreActive
**********************************************************************************************************************/
Il_Boolean IlTxRepetitionsAreActive(IL_CHANNEL_ILTYPE_ONLY)
{
# if defined( IL_ENABLE_TX_SECURE_EVENT )
  IlTransmitHandle ilTxHnd;
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  ilTxHnd = IlTxMsgStartIndex[channel + 1];
  if (IlTxMsgStartIndex[channel] != ilTxHnd)
#  else
  ilTxHnd = kIlNumberOfTxObjects;
#  endif
  {
    /*--- Loop for every transmit object ---------------------------------------*/
    do
    {
      /* Initial Decrement */
      ilTxHnd--;
      if (ilTxNSendCounter[ilTxHnd] != 0)
      {
        return IL_TRUE;
      }
    }
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    while (ilTxHnd != IlTxMsgStartIndex[channel]);
#  else
    while (ilTxHnd != 0);
#  endif
  }
# else
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
#  endif
# endif /* IL_ENABLE_TX_SECURE_EVENT */
  return IL_FALSE;
}
#endif /* VGEN_GENY && IL_ENABLE_SYS_TX_REPETITIONS_ARE_ACTIVE_FCT */


#if defined ( IL_ENABLE_SYS_GET_CONTEXT ) 
/**********************************************************************************************************************
  IlGetModuleContext
**********************************************************************************************************************/
void IlGetModuleContext(tIlModuleContextStructPtr pContext)
{
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  CanChannelHandle channel;
# endif
# if defined ( IL_ENABLE_TX )
  IlTransmitHandle ilTxHnd;
# endif
# if defined( IL_ENABLE_RX_TIMEOUT ) || defined( IL_ENABLE_TX_TIMEOUT ) || defined ( IL_ENABLE_RX_EXT_TIMEOUT )
  vuintx i;
# endif


  pContext->ilMagicNumber = ((vuint32) ((vuint32) IL_VECTOR_VERSION << 16) | IL_VECTOR_RELEASE_VERSION);

# if defined ( IL_ENABLE_RX_MULTIPLE_NODES )
  pContext->ilECUMask = ilECUMask;
# endif

/* Copy Channel Dependent Context */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  for (channel = 0; channel < kIlNumberOfChannels; channel++)
# endif
  {
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
    pContext->ilChannelState[channel] = ilChannelState[channel];
#  if defined( IL_ENABLE_RX_POLLING ) || defined( IL_ENABLE_RX_EXT_TIMEOUT )
    pContext->ilChannelReceive[channel] = ilChannelReceive[channel];
#  endif
# else
    pContext->ilChannelState = ilChannelState;
#  if defined( IL_ENABLE_RX_POLLING ) || defined( IL_ENABLE_RX_EXT_TIMEOUT )
    pContext->ilChannelReceive = ilChannelReceive;
#  endif
# endif /* C_MULTIPLE_RECEIVE_CHANNEL */

  }

/* Copy Tx Dependent Context */
# if defined ( IL_ENABLE_TX )
  for (ilTxHnd = 0; ilTxHnd < kIlNumberOfTxObjects; ilTxHnd++)
  {
    pContext->ilTxState[ilTxHnd] = ilTxState[ilTxHnd];
    pContext->ilTxCyclicCounter[ilTxHnd] = ilTxCyclicCounter[ilTxHnd];
    pContext->ilTxUpdateCounter[ilTxHnd] = ilTxUpdateCounter[ilTxHnd];

#  if defined( VGEN_GENY ) && defined( IL_ENABLE_TX_DYNAMIC_CYCLETIME )
    pContext->ilTxDynCyclicCycles[ilTxHnd] = ilTxDynCyclicCycles[ilTxHnd];
#  endif
#  if defined( IL_ENABLE_TX_SECURE_EVENT )
    pContext->ilTxNSendCounter[ilTxHnd] = ilTxNSendCounter[ilTxHnd];
#  endif
#  if defined ( IL_ENABLE_TX_CYCLIC_EVENT ) || defined ( IL_ENABLE_TX_SECURE_EVENT ) || defined ( IL_ENABLE_TX_FAST_ON_START )
    pContext->ilTxEventCounter[ilTxHnd] = ilTxEventCounter[ilTxHnd];
#  endif
  }

#  if defined( IL_ENABLE_TX_CYCLIC_EVENT )
  pContext->ilIfActiveFlags = ilIfActiveFlags;
#  endif
#  if defined( IL_ENABLE_TX_TIMEOUT_FLAG )
  VStdMemCpyRamToRam(pContext->ilTxTimeoutFlags, ilTxTimeoutFlags, kIlNumberOfTxTimeoutFlags);
#  endif
#  if defined( IL_ENABLE_TX_CONFIRMATION_FLAG )
  VStdMemCpyRamToRam(pContext->ilTxConfirmationFlags, ilTxConfirmationFlags, kIlNumberOfTxConfirmationFlags);
#  endif
#  if defined( IL_ENABLE_TX_TIMEOUT )
  for (i = 0; i < (vuintx) kIlNumberOfTxTimeoutCounters; i++)
  {
    pContext->ilTxTimeoutCounter[i] = ilTxTimeoutCounter[i];
  }
#  endif
# endif /* IL_ENABLE_TX */

/* Copy Rx Dependent Context */
# if defined ( IL_ENABLE_RX )
#  if defined( IL_ENABLE_RX_TIMEOUT )
  for (i = 0; i < (vuintx) kIlNumberOfRxTimeoutCounters; i++)
  {
    pContext->ilRxTimeoutCounter[i] = ilRxTimeoutCounter[i];
#   if defined ( VGEN_GENY ) && defined( IL_ENABLE_RX_DYNAMIC_TIMEOUT )
    pContext->ilRxDynamicTimeoutCounter[i] = ilRxDynamicTimeoutCounter[i];
#   endif
  }
  VStdMemCpyRamToRam(pContext->ilRxTimerFlags, ilRxTimerFlags, kIlNumberOfTimerFlagBytes);
#  endif
#  if defined( IL_ENABLE_RX_DATACHANGED_FLAG )
  VStdMemCpyRamToRam(pContext->ilRxDataChangedFlags, ilRxDataChangedFlags, kIlNumberOfRxDataChangedFlags);
#  endif
#  if defined( IL_ENABLE_RX_INDICATION_FLAG )
  VStdMemCpyRamToRam(pContext->ilRxIndicationFlags, ilRxIndicationFlags, kIlNumberOfRxIndicationFlags);
#  endif
#  if defined( IL_ENABLE_RX_FIRSTVALUE_FLAG )
  VStdMemCpyRamToRam(pContext->ilRxFirstvalueFlags, ilRxFirstvalueFlags, kIlNumberOfRxFirstvalueFlags);
#  endif
#  if defined ( IL_ENABLE_RX_TIMEOUT_FLAG )
  VStdMemCpyRamToRam(pContext->ilRxTimeoutFlags, ilRxTimeoutFlags, kIlNumberOfRxTimeoutFlags);
#  endif
#  if !defined( VGEN_GENY ) && defined( IL_ENABLE_RX_MODE_SIGNALS )
#  endif
# endif /* IL_ENABLE_RX */

# if defined ( IL_TYPE_GM )
#  if defined ( IL_ENABLE_RX )
  VStdMemCpyRamToRam(pContext->ilVnRxMessageActive, ilVnRxMessageActive, kIlNrOfPackedRxObjectBytes);
  VStdMemCpyRamToRam(pContext->ilVnRxMessageEnable, ilVnRxMessageEnable, kIlNrOfPackedRxObjectBytes);
  VStdMemCpyRamToRam(pContext->ilVnRxSupervisionActive, ilVnRxSupervisionActive, kIlNrOfPackedRxObjectBytes);
  VStdMemCpyRamToRam(pContext->ilRxActiveVn, ilRxActiveVn, kIlNrOfPackedVirtualNetBytes);
  VStdMemCpyRamToRam(pContext->ilRxSVActiveVn, ilRxSVActiveVn, kIlNrOfPackedVirtualNetBytes);
#   if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
  VStdMemCpyRamToRam(pContext->ilExtIdRxMsgIdxOfSourceAddress, ilExtIdRxMsgIdxOfSourceAddress,
                     kIlNumberOfExtIdRxObjects);
  pContext->ilExtIdRxSrcAddressQueueCount[IL_CHANNEL_ILPARA_MACRO] =
    ilExtIdRxSrcAddressQueueCount[IL_CHANNEL_ILPARA_MACRO];
  pContext->ilExtIdRxDefaultTimer[IL_CHANNEL_ILPARA_MACRO] = ilExtIdRxDefaultTimer[IL_CHANNEL_ILPARA_MACRO];
  pContext->ilNrOfLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO] =
    ilNrOfLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO];
  for (i = 0; i < (vuintx) kIlMaxRxExtIdQueue; i++)
  {
    pContext->ilExtIdRxSrcAddressQueue[IL_CHANNEL_ILPARA_MACRO][i] =
      ilExtIdRxSrcAddressQueue[IL_CHANNEL_ILPARA_MACRO][i];
    pContext->ilExtIdRxObjHandleQueue[IL_CHANNEL_ILPARA_MACRO][i] = ilExtIdRxObjHandleQueue[IL_CHANNEL_ILPARA_MACRO][i];
  }
  for (i = 0; i < (vuintx) kIlNrOfConfigNodes; i++)
  {
    pContext->ilExtIdRxSrcAddrTimer[IL_CHANNEL_ILPARA_MACRO][i] = ilExtIdRxSrcAddrTimer[IL_CHANNEL_ILPARA_MACRO][i];
  }
  for (i = 0; i < (vuintx) kIlNrOfSourceAddresses; i++)
  {
    pContext->ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][i] =
      ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][i];
    pContext->ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO][i] =
      ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO][i];
  }
  for (i = 0; i < (vuintx) kIlNrOfPackedSourceAddressBytes; i++)
  {
    pContext->ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO][i] =
      ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO][i];
  }
#   endif
        /* IL_ENABLE_RX_EXT_TIMEOUT */
#  endif
       /* IL_ENABLE_RX */

#  if defined ( IL_ENABLE_TX )
  VStdMemCpyRamToRam(pContext->ilVnTxMessageActive, ilVnTxMessageActive, kIlNrOfPackedTxObjectBytes);
  VStdMemCpyRamToRam(pContext->ilVnTxMessageEnable, ilVnTxMessageEnable, kIlNrOfPackedTxObjectBytes);
  VStdMemCpyRamToRam(pContext->ilTxActiveVn, ilTxActiveVn, kIlNrOfPackedVirtualNetBytes);
#  endif/* IL_ENABLE_TX */
# endif/* IL_TYPE_GM */
}                               /* End of IlGetModuleContext() */
#endif /* IL_ENABLE_SYS_GET_CONTEXT || VGEN_ENABLE_MDWRAP */

#if defined ( IL_ENABLE_SYS_SET_CONTEXT ) 
/**********************************************************************************************************************
  IlSetModuleContext
**********************************************************************************************************************/
vuint8 IlSetModuleContext(tIlModuleContextStructPtr pContext)
{
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  CanChannelHandle channel;
# endif
# if defined ( IL_ENABLE_TX )
  IlTransmitHandle ilTxHnd;
# endif
# if defined( IL_ENABLE_RX_TIMEOUT ) || defined( IL_ENABLE_TX_TIMEOUT ) || defined ( IL_ENABLE_RX_EXT_TIMEOUT )
  vuintx i;
# endif

  if (pContext->ilMagicNumber == (vuint32) (((vuint32) IL_VECTOR_VERSION << 16) | IL_VECTOR_RELEASE_VERSION))
  {
# if defined ( IL_ENABLE_RX_MULTIPLE_NODES )
    ilECUMask = pContext->ilECUMask;
# endif

/* Copy Channel Dependent Context */
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
    for (channel = 0; channel < kIlNumberOfChannels; channel++)
# endif
    {
# if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
      ilChannelState[channel] = pContext->ilChannelState[channel];
#  if defined( IL_ENABLE_RX_POLLING ) || defined( IL_ENABLE_RX_EXT_TIMEOUT )
      ilChannelReceive[channel] = pContext->ilChannelReceive[channel];
#  endif
# else
      ilChannelState = pContext->ilChannelState;
#  if defined( IL_ENABLE_RX_POLLING ) || defined( IL_ENABLE_RX_EXT_TIMEOUT )
      ilChannelReceive = pContext->ilChannelReceive;
#  endif
# endif /* C_MULTIPLE_RECEIVE_CHANNEL */
    }

/* Copy Tx Dependent Context */
# if defined ( IL_ENABLE_TX )
    for (ilTxHnd = 0; ilTxHnd < kIlNumberOfTxObjects; ilTxHnd++)
    {
      ilTxState[ilTxHnd] = pContext->ilTxState[ilTxHnd];
      ilTxCyclicCounter[ilTxHnd] = pContext->ilTxCyclicCounter[ilTxHnd];
      ilTxUpdateCounter[ilTxHnd] = pContext->ilTxUpdateCounter[ilTxHnd];

#  if defined( VGEN_GENY ) && defined( IL_ENABLE_TX_DYNAMIC_CYCLETIME )
      ilTxDynCyclicCycles[ilTxHnd] = pContext->ilTxDynCyclicCycles[ilTxHnd];
#  endif
#  if defined( IL_ENABLE_TX_SECURE_EVENT )
      ilTxNSendCounter[ilTxHnd] = pContext->ilTxNSendCounter[ilTxHnd];
#  endif
#  if defined ( IL_ENABLE_TX_CYCLIC_EVENT ) || defined ( IL_ENABLE_TX_SECURE_EVENT ) || defined ( IL_ENABLE_TX_FAST_ON_START )
      ilTxEventCounter[ilTxHnd] = pContext->ilTxEventCounter[ilTxHnd];
#  endif
    }
#  if defined( IL_ENABLE_TX_CYCLIC_EVENT )
    ilIfActiveFlags = pContext->ilIfActiveFlags;
#  endif
#  if defined( IL_ENABLE_TX_TIMEOUT_FLAG )
    VStdMemCpyRamToNearRam(ilTxTimeoutFlags, pContext->ilTxTimeoutFlags, kIlNumberOfTxTimeoutFlags);
#  endif
#  if defined( IL_ENABLE_TX_CONFIRMATION_FLAG )
    VStdMemCpyRamToNearRam(ilTxConfirmationFlags, pContext->ilTxConfirmationFlags, kIlNumberOfTxConfirmationFlags);
#  endif
#  if defined( IL_ENABLE_TX_TIMEOUT )
    for (i = 0; i < (vuintx) kIlNumberOfTxTimeoutCounters; i++)
    {
      ilTxTimeoutCounter[i] = pContext->ilTxTimeoutCounter[i];
    }
#  endif
# endif /* IL_ENABLE_TX */

/* Copy Rx Dependent Context */
# if defined ( IL_ENABLE_RX )
#  if defined( IL_ENABLE_RX_TIMEOUT )
    for (i = 0; i < (vuintx) kIlNumberOfRxTimeoutCounters; i++)
    {
      ilRxTimeoutCounter[i] = pContext->ilRxTimeoutCounter[i];
#   if defined ( VGEN_GENY ) && defined( IL_ENABLE_RX_DYNAMIC_TIMEOUT )
      ilRxDynamicTimeoutCounter[i] = pContext->ilRxDynamicTimeoutCounter[i];
#   endif
    }
    VStdMemCpyRamToNearRam(ilRxTimerFlags, pContext->ilRxTimerFlags, kIlNumberOfTimerFlagBytes);
#  endif /* IL_ENABLE_RX_TIMEOUT */
#  if defined( IL_ENABLE_RX_DATACHANGED_FLAG )
    VStdMemCpyRamToNearRam(ilRxDataChangedFlags, pContext->ilRxDataChangedFlags, kIlNumberOfRxDataChangedFlags);
#  endif
#  if defined( IL_ENABLE_RX_INDICATION_FLAG )
    VStdMemCpyRamToNearRam(ilRxIndicationFlags, pContext->ilRxIndicationFlags, kIlNumberOfRxIndicationFlags);
#  endif
#  if defined( IL_ENABLE_RX_FIRSTVALUE_FLAG )
    VStdMemCpyRamToNearRam(ilRxFirstvalueFlags, pContext->ilRxFirstvalueFlags, kIlNumberOfRxFirstvalueFlags);
#  endif
#  if defined ( IL_ENABLE_RX_TIMEOUT_FLAG )
    VStdMemCpyRamToNearRam(ilRxTimeoutFlags, pContext->ilRxTimeoutFlags, kIlNumberOfRxTimeoutFlags);
#  endif
#  if !defined( VGEN_GENY ) && defined( IL_ENABLE_RX_MODE_SIGNALS )
#  endif
# endif /* IL_ENABLE_RX */

# if defined ( IL_TYPE_GM )
#  if defined ( IL_ENABLE_RX )
    VStdMemCpyRamToRam(ilVnRxMessageActive, pContext->ilVnRxMessageActive, kIlNrOfPackedRxObjectBytes);
    VStdMemCpyRamToRam(ilVnRxMessageEnable, pContext->ilVnRxMessageEnable, kIlNrOfPackedRxObjectBytes);
    VStdMemCpyRamToRam(ilVnRxSupervisionActive, pContext->ilVnRxSupervisionActive, kIlNrOfPackedRxObjectBytes);
    VStdMemCpyRamToRam(ilRxActiveVn, pContext->ilRxActiveVn, kIlNrOfPackedVirtualNetBytes);
    VStdMemCpyRamToRam(ilRxSVActiveVn, pContext->ilRxSVActiveVn, kIlNrOfPackedVirtualNetBytes);
#   if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
    VStdMemCpyRamToRam(ilExtIdRxMsgIdxOfSourceAddress, pContext->ilExtIdRxMsgIdxOfSourceAddress,
                       kIlNumberOfExtIdRxObjects);
    ilExtIdRxSrcAddressQueueCount[IL_CHANNEL_ILPARA_MACRO] =
      pContext->ilExtIdRxSrcAddressQueueCount[IL_CHANNEL_ILPARA_MACRO];
    ilExtIdRxDefaultTimer[IL_CHANNEL_ILPARA_MACRO] = pContext->ilExtIdRxDefaultTimer[IL_CHANNEL_ILPARA_MACRO];
    ilNrOfLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO] =
      pContext->ilNrOfLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO];
    for (i = 0; i < (vuintx) kIlMaxRxExtIdQueue; i++)
    {
      ilExtIdRxSrcAddressQueue[IL_CHANNEL_ILPARA_MACRO][i] =
        pContext->ilExtIdRxSrcAddressQueue[IL_CHANNEL_ILPARA_MACRO][i];
      ilExtIdRxObjHandleQueue[IL_CHANNEL_ILPARA_MACRO][i] =
        pContext->ilExtIdRxObjHandleQueue[IL_CHANNEL_ILPARA_MACRO][i];
    }
    for (i = 0; i < (vuintx) kIlNrOfConfigNodes; i++)
    {
      ilExtIdRxSrcAddrTimer[IL_CHANNEL_ILPARA_MACRO][i] = pContext->ilExtIdRxSrcAddrTimer[IL_CHANNEL_ILPARA_MACRO][i];
    }
    for (i = 0; i < (vuintx) kIlNrOfSourceAddresses; i++)
    {
      ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][i] =
        pContext->ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][i];
      ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO][i] =
        pContext->ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO][i];
    }
    for (i = 0; i < (vuintx) (kIlNrOfPackedSourceAddressBytes); i++)
    {
      ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO][i] =
        pContext->ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO][i];
    }
#   endif
        /* IL_ENABLE_RX_EXT_TIMEOUT */
#  endif
       /* IL_ENABLE_RX */

#  if defined ( IL_ENABLE_TX )
    VStdMemCpyRamToRam(ilVnTxMessageActive, pContext->ilVnTxMessageActive, kIlNrOfPackedTxObjectBytes);
    VStdMemCpyRamToRam(ilVnTxMessageEnable, pContext->ilVnTxMessageEnable, kIlNrOfPackedTxObjectBytes);
    VStdMemCpyRamToRam(ilTxActiveVn, pContext->ilTxActiveVn, kIlNrOfPackedVirtualNetBytes);
#  endif
       /* IL_ENABLE_TX */
# endif/* IL_TYPE_GM */

    return 1;
  }
  else
  {
    return 0;
  }
}                               /* End of IlSetModuleContext() */
#endif /* IL_ENABLE_SYS_SET_CONTEXT || VGEN_ENABLE_QWRAP */

/**********************************************************************************************************************
  CanCopyFromCan
**********************************************************************************************************************/
#if defined ( VGEN_CANGEN_VERSION ) && defined ( IL_ENABLE_RX_MODE_SIGNALS ) && !defined ( C_ENABLE_MEMCOPY_SUPPORT )
void CanCopyFromCan(void *dst, CanChipDataPtr src, vuint8 len)
{
  if (dst == V_NULL)
  {
    return;
  }

  while (len > 0)
  {
    len--;
    *((vuint8 *) dst) = *(src++);
    dst = ((vuint8 *) dst) + 1;
  }
}                               /* End of CanCopyFromCan() */
#endif

#if defined ( IL_TYPE_GM )

/**********************************************************************************************************************
  IlGetSourceAddressIndex
**********************************************************************************************************************/
# if defined( IL_ENABLE_RX_EXT_TIMEOUT )
static vuint8 IlGetSourceAddressIndex(IL_CHANNEL_ILTYPE_FIRST vuint8 srcAddress)
{
  vuintx i;
  for (i = 0; i < (vuintx) ilNrOfLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO]; i++)
  {
    if (ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO][i] == srcAddress)
    {
      return ((vuint8) i);
    }
  }
  return (IL_NODE_ADDRESS_UNKNOWN);
}                               /* End of IlGetSourceAddressIndex() */
# endif /* IL_ENABLE_RX_EXT_TIMEOUT */

/**********************************************************************************************************************
  IlProcessLearnedSourceAddress
**********************************************************************************************************************/
# if defined( IL_ENABLE_RX_EXT_TIMEOUT )
static vuint8 IlProcessLearnedSourceAddress(IL_CHANNEL_ILTYPE_FIRST vuint8 srcAddress)
{
  vuint8 srcAddressIndex = IlGetSourceAddressIndex(IL_CHANNEL_ILPARA_FIRST srcAddress);
  if (srcAddressIndex == IL_NODE_ADDRESS_UNKNOWN)
  {
    /* ************************* */
    /* Not found: Learn a new ID */
    /* ************************* */

    /* Ensure that the table is not exhausted */
    if (ilNrOfLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO] < kIlNrOfConfigNodes)
    {
      /* This is a new device. Add it to the list */
      /* The order is important: First add the source address, */
      /*                           then increment the Number   */
      ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO][ilNrOfLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO]] =
        srcAddress;
      srcAddressIndex = ilNrOfLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO];

      ilNrOfLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO]++;

      ApplIlSourceAddressLearned(IL_CHANNEL_ILPARA_FIRST srcAddress);
    }
  }
  else
  {
    vuint8 ilVnIndex = (srcAddressIndex >> 3);
    vuint8 ilVnMask = LSB2MSBBitMask[(srcAddressIndex & 0x07)];

    /* Restart node comm active supervision timer */
    ilExtIdRxSrcAddrTimer[IL_CHANNEL_ILPARA_MACRO][srcAddressIndex] = IlGetRxNcaMsgTimeoutCnt(IL_CHANNEL_ILPARA_ONLY);

    /* Source address experienced recently a timeout ?! */
    if ((ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO][ilVnIndex] & ilVnMask) != 0)
    {
      /* Recover from previous supervision failure */
      ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO][ilVnIndex] &= (vuint8) ~ ilVnMask;
      IlNodeCommActiveRecovery(IL_CHANNEL_ILPARA_FIRST srcAddress);
    }
  }
  return srcAddressIndex;
}                               /* End of IlProcessLearnedSourceAddress() */
# endif/* IL_ENABLE_RX_EXT_TIMEOUT */

/**********************************************************************************************************************
  IlRxMessageRecovery
**********************************************************************************************************************/
# if defined( IL_ENABLE_RX_EXT_TIMEOUT )
static void IlRxMessageRecovery(IlReceiveHandle ilRxExtIdHnd)
{
  if (IlRxExtIDFaultRecoveryFunctions[ilRxExtIdHnd] != V_NULL)
  {
    (*IlRxExtIDFaultRecoveryFunctions[ilRxExtIdHnd]) ();
  }
}                               /* End of IlRxMessageRecovery() */
# endif/* IL_ENABLE_RX_EXT_TIMEOUT */

/**********************************************************************************************************************
  IlNodeCommActiveRecovery
**********************************************************************************************************************/
# if defined( IL_ENABLE_RX_EXT_TIMEOUT )
static void IlNodeCommActiveRecovery(IL_CHANNEL_ILTYPE_FIRST vuint8 srcAddress)
{
  IlReceiveHandle ilRxExtIdHnd;

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilRxExtIdHnd = IlRxExtIDStartIndex[channel]; ilRxExtIdHnd < IlRxExtIDStartIndex[(channel + 1)]; ilRxExtIdHnd++)
#  else
  for (ilRxExtIdHnd = 0; ilRxExtIdHnd < kIlNumberOfExtIdRxObjects; ilRxExtIdHnd++)
#  endif
  {
    if ((ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO][ilExtIdRxMsgIdxOfSourceAddress[ilRxExtIdHnd]] ==
         srcAddress))
    {
      /* Message located. Do signal recovery */
      IlRxMessageRecovery(ilRxExtIdHnd);
    }
    /* goto next bit in the mask */
  }
  ApplIlNodeCommActiveRecovery(IL_CHANNEL_ILPARA_FIRST srcAddress);
}                               /* End of IlNodeCommActiveRecovery() */
# endif/* IL_ENABLE_RX_EXT_TIMEOUT */

/**********************************************************************************************************************
  IlNodeCommActiveFailed
**********************************************************************************************************************/
# if defined( IL_ENABLE_RX_EXT_TIMEOUT )
static vuintx IlNodeCommActiveFailed(IL_CHANNEL_ILTYPE_FIRST vuint8 srcAddress)
{
  IlReceiveHandle ilRxHnd = IlGetRxMsgStartIndex(IL_CHANNEL_ILPARA_MACRO);
  vuint8 ilRxPackedMask = 0x01;
  vuint8 ilRxPackedIndex;
  vuintx ilTimeoutState = kIlNoTimeoutEvent;

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilRxPackedIndex = IlGetPackedRxObjectsStartIndex(channel);
       ilRxPackedIndex < IlGetPackedRxObjectsStartIndex(channel + 1); ilRxPackedIndex++)
#  else
  for (ilRxPackedIndex = 0; ilRxPackedIndex < kIlNrOfPackedRxObjectBytes; ilRxPackedIndex++)
#  endif
  {
    vuint8 ilVnMsgMask = ilVnRxSupervisionActive[ilRxPackedIndex];
    vuint8 ilBitIndex;
    for (ilBitIndex = 0; ilBitIndex < 8; ilBitIndex++)
    {
      if ((ilVnMsgMask & ilRxPackedMask) != 0)
      {
        IlReceiveHandle ilRxExtIdHnd = IlGetRxExtIdHnd(ilRxHnd);
        ilVnMsgMask &= (vuint8) ~ ilRxPackedMask;

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
        if ((ilRxExtIdHnd >= IlRxExtIDStartIndex[channel]) && (ilRxExtIdHnd < IlRxExtIDStartIndex[(channel + 1)]))
#  else
        if (ilRxExtIdHnd < kIlNumberOfExtIdRxObjects)
#  endif
        {
          if ((ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO][ilExtIdRxMsgIdxOfSourceAddress[ilRxExtIdHnd]] ==
               srcAddress))
          {
            if (IlRxExtIDTimeoutFunctions[ilRxExtIdHnd] != V_NULL)
            {
              CanInterruptDisable();
              /* Message located. Do signal recovery */
              (*IlRxExtIDTimeoutFunctions[ilRxExtIdHnd]) ();
              CanInterruptRestore();
            }
            ilTimeoutState = kIlTimeoutEvent;
          }
        }
      }
      if (ilRxPackedMask == 0x80)
      {
        ilRxPackedMask = 0x01;
      }
      else
      {
        ilRxPackedMask <<= 1;
      }
      ilRxHnd++;
    }
  }
  if (ilTimeoutState == kIlTimeoutEvent)
  {
    ApplIlNodeCommActiveFailed(IL_CHANNEL_ILPARA_FIRST srcAddress);
  }
  return (ilTimeoutState);
}                               /* End of IlNodeCommActiveFailed() */
# endif/* IL_ENABLE_RX_EXT_TIMEOUT */

/**********************************************************************************************************************
  IlTxActivateVnMsg
**********************************************************************************************************************/
Il_Status IlTxActivateVnMsg(IL_CHANNEL_ILTYPE_FIRST vuint8 ilVnHnd)
{
# if defined ( IL_ENABLE_TX )
  IlTransmitHandle ilTxHnd = IlGetTxMsgStartIndex(IL_CHANNEL_ILPARA_MACRO);
  vuint8 ilTxPackedIndex;
  vuint8 ilTxPackedMask = 0x01;

  IlAssert(ilVnHnd < kIlNumberOfVirtualNets, ILERR_ILLVNNR);
#  if defined ( IL_ENABLE_SYS_ARGCHECK )
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  if ((ilVnHnd < IlVnStartIndex[channel]) || (ilVnHnd >= IlVnStartIndex[channel + 1]))
#   else
  if (ilVnHnd >= kIlNumberOfVirtualNets)
#   endif
  {
    return IL_ERROR;
  }
#  endif

  IlAssert(TxEnabled(IL_CHANNEL_ILPARA_MACRO), ILERR_TXSTOPPED);
  if (!TxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    return IL_ERROR;
  }
  if ((ilTxActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) != 0)
  {
    return IL_VN_ALREADY_ACTIVE;
  }

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilTxPackedIndex = IlGetPackedTxObjectsStartIndex(channel);
       ilTxPackedIndex < IlGetPackedTxObjectsStartIndex(channel + 1); ilTxPackedIndex++)
#  else
  for (ilTxPackedIndex = 0; ilTxPackedIndex < kIlNrOfPackedTxObjectBytes; ilTxPackedIndex++)
#  endif
  {
    vuint8 ilVnMsgMask;
    vuint8 ilBitIndex;

    /* Add the Vn-message to the Vn-active  */
    CanInterruptDisable();
    ilVnMsgMask = (IlVnTxMessageMapping[ilVnHnd][ilTxPackedIndex] & ilVnTxMessageEnable[ilTxPackedIndex]);
    ilVnTxMessageActive[ilTxPackedIndex] |= ilVnMsgMask;
    CanInterruptRestore();

    for (ilBitIndex = 0; ilBitIndex < 8; ilBitIndex++)
    {
      /* Check if the message shall be activated for this VN */
      if ((ilVnMsgMask & ilTxPackedMask) != 0)
      {
        /* Clear this flag */
        ilVnMsgMask &= (vuint8) ~ ilTxPackedMask;
        /*--- Queue message On-Init only if it is configured to be allowed -----*/
        if ((ilTxState[ilTxHnd] & kTxQueueInit) != 0)
        {
          /*--- queue the message (set an event) ------------------------------*/
          ilTxState[ilTxHnd] |= kTxSendRequest;
        }

        /*--- Restart the cycle counter if next cyclic transmission is greater--*/
        /*--- than the StartDelay Time (compared to IS > 0.2 -------------------*/
        if (ilTxCyclicCounter[ilTxHnd] > IlTxStartCycles[ilTxHnd])
        {
          ilTxCyclicCounter[ilTxHnd] = IlTxStartCycles[ilTxHnd];
        }
      }
      if (ilTxPackedMask == 0x80)
      {
        ilTxPackedMask = 0x01;
      }
      else
      {
        ilTxPackedMask <<= 1;
      }
      ilTxHnd++;
    }
  }
  /*--- Set marker that this VN is activated --------------------------------*/
  ilTxActiveVn[(ilVnHnd >> 3)] |= VnBitMask[(ilVnHnd & 0x07)];
# else
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  ilVnHnd = ilVnHnd;
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  channel = channel;
#   endif
#  endif
# endif/* IL_ENABLE_TX */
  return IL_VN_ACTIVATED;
}                               /* End of IlTxActivateVnMsg() */

/**********************************************************************************************************************
  IlTxDeactivateVnMsg
**********************************************************************************************************************/
Il_Status IlTxDeactivateVnMsg(IL_CHANNEL_ILTYPE_FIRST vuint8 ilVnHnd)
{
# if defined ( IL_ENABLE_TX )
  IlTransmitHandle ilTxHnd = IlGetTxMsgStartIndex(IL_CHANNEL_ILPARA_MACRO);
  vuint8 ilTxPackedIndex;
  vuint8 ilTxPackedMask = 0x01;

  IlAssert(ilVnHnd < kIlNumberOfVirtualNets, ILERR_ILLVNNR);
#  if defined ( IL_ENABLE_SYS_ARGCHECK )
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  if ((ilVnHnd < IlVnStartIndex[channel]) || (ilVnHnd >= IlVnStartIndex[channel + 1]))
#   else
  if (ilVnHnd >= kIlNumberOfVirtualNets)
#   endif
  {
    return IL_ERROR;
  }
#  endif
  IlAssert(TxEnabled(IL_CHANNEL_ILPARA_MACRO), ILERR_TXSTOPPED);
  if (!TxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    return IL_ERROR;
  }
  if ((ilTxActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) == 0)
  {
    return IL_ERROR;
  }

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilTxPackedIndex = IlGetPackedTxObjectsStartIndex(channel);
       ilTxPackedIndex < IlGetPackedTxObjectsStartIndex(channel + 1); ilTxPackedIndex++)
#  else
  for (ilTxPackedIndex = 0; ilTxPackedIndex < kIlNrOfPackedTxObjectBytes; ilTxPackedIndex++)
#  endif
  {
    vuint8 ilCurVnHnd, ilVnMsgMask, ilVnMsgActiveMask = 0;
    vuint8 ilBitIndex;

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    for (ilCurVnHnd = IlVnStartIndex[channel]; ilCurVnHnd < IlVnStartIndex[(channel + 1)]; ilCurVnHnd++)
#  else
    for (ilCurVnHnd = 0; ilCurVnHnd < kIlNumberOfVirtualNets; ilCurVnHnd++)
#  endif
    {
      if (ilCurVnHnd != ilVnHnd)
      {
        if ((ilTxActiveVn[(ilCurVnHnd >> 3)] & VnBitMask[(ilCurVnHnd & 0x07)]) != 0)
        {
          ilVnMsgActiveMask |= IlVnTxMessageMapping[ilCurVnHnd][ilTxPackedIndex];
        }
      }
    }

    ilVnMsgActiveMask &= ilVnTxMessageEnable[ilTxPackedIndex];
    /* Failure if a new VN is added. Just removing is allowed */
    IlAssert((((ilVnMsgActiveMask ^ ilVnTxMessageActive[ilTxPackedIndex]) & ilVnMsgActiveMask) == 0), 0);

    ilVnMsgMask = ilVnMsgActiveMask ^ ilVnTxMessageActive[ilTxPackedIndex];
    ilVnTxMessageActive[ilTxPackedIndex] = ilVnMsgActiveMask;

    /* Check if any new VN-message comes up */
    for (ilBitIndex = 0; ilBitIndex < 8; ilBitIndex++)
    {
      /* Check if the message shall be activated for this VN */
      if ((ilVnMsgMask & ilTxPackedMask) != 0)
      {
        /* Clear this flag */
        ilVnMsgMask &= (vuint8) ~ ilTxPackedMask;

        ilTxState[ilTxHnd] &= kTxNotSendRequest;
        /* Send cyclic messages after StartDelayTime -------------------- */
        ilTxCyclicCounter[ilTxHnd] = IlTxStartCycles[ilTxHnd];
      }
      if (ilTxPackedMask == 0x80)
      {
        ilTxPackedMask = 0x01;
      }
      else
      {
        ilTxPackedMask <<= 1;
      }
      ilTxHnd++;
    }
  }
  ilTxActiveVn[(ilVnHnd >> 3)] &= VnBitClrMask[(ilVnHnd & 0x07)];
# else
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  ilVnHnd = ilVnHnd;
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  channel = channel;
#   endif
#  endif
# endif/* IL_ENABLE_TX */
  return IL_VN_DEACTIVATED;
}                               /* End of IlTxDeactivateVnMsg() */

/**********************************************************************************************************************
  IlRxActivateVnMsg
**********************************************************************************************************************/
Il_Status IlRxActivateVnMsg(IL_CHANNEL_ILTYPE_FIRST vuint8 ilVnHnd)
{
# if defined ( IL_ENABLE_RX )
  vuint8 ilRxPackedIndex;

  IlAssert(ilVnHnd < kIlNumberOfVirtualNets, ILERR_ILLVNNR);
#  if defined ( IL_ENABLE_SYS_ARGCHECK )
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  if ((ilVnHnd < IlVnStartIndex[channel]) || (ilVnHnd >= IlVnStartIndex[channel + 1]))
#   else
  if (ilVnHnd >= kIlNumberOfVirtualNets)
#   endif
  {
    return IL_ERROR;
  }
#  endif
  IlAssert(RxEnabled(IL_CHANNEL_ILPARA_MACRO), ILERR_RXSTOPPED);
  if (!RxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    return IL_ERROR;
  }
  if ((ilRxActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) != 0)
  {
    return IL_VN_ALREADY_ACTIVE;
  }

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilRxPackedIndex = IlGetPackedRxObjectsStartIndex(channel);
       ilRxPackedIndex < IlGetPackedRxObjectsStartIndex(channel + 1); ilRxPackedIndex++)
#  else
  for (ilRxPackedIndex = 0; ilRxPackedIndex < kIlNrOfPackedRxObjectBytes; ilRxPackedIndex++)
#  endif
  {
    /* Add the Vn-message to the Vn-active  */
    ilVnRxMessageActive[ilRxPackedIndex] |=
      (IlVnRxMessageMapping[ilVnHnd][ilRxPackedIndex] & ilVnRxMessageEnable[ilRxPackedIndex]);
  }
  /*--- Set marker that this VN is activated --------------------------------*/
  ilRxActiveVn[(ilVnHnd >> 3)] |= VnBitMask[(ilVnHnd & 0x07)];
# else
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  ilVnHnd = ilVnHnd;
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  channel = channel;
#   endif
#  endif
# endif/* IL_ENABLE_RX */
  return IL_VN_ACTIVATED;
}                               /* End of IlRxActivateVnMsg() */

/**********************************************************************************************************************
  IlRxDeactivateVnMsg
**********************************************************************************************************************/
Il_Status IlRxDeactivateVnMsg(IL_CHANNEL_ILTYPE_FIRST vuint8 ilVnHnd)
{
# if defined ( IL_ENABLE_RX )
  IlReceiveHandle ilRxPackedIndex;

  IlAssert(ilVnHnd < kIlNumberOfVirtualNets, ILERR_ILLVNNR);
#  if defined ( IL_ENABLE_SYS_ARGCHECK )
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  if ((ilVnHnd < IlVnStartIndex[channel]) || (ilVnHnd >= IlVnStartIndex[channel + 1]))
#   else
  if (ilVnHnd >= kIlNumberOfVirtualNets)
#   endif
  {
    return IL_ERROR;
  }
#  endif
  IlAssert(RxEnabled(IL_CHANNEL_ILPARA_MACRO), ILERR_RXSTOPPED);
  if (!RxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    return IL_ERROR;
  }
  if ((ilRxActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) == 0)
  {
    return IL_ERROR;
  }

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilRxPackedIndex = IlGetPackedRxObjectsStartIndex(channel);
       ilRxPackedIndex < IlGetPackedRxObjectsStartIndex(channel + 1); ilRxPackedIndex++)
#  else
  for (ilRxPackedIndex = 0; ilRxPackedIndex < kIlNrOfPackedRxObjectBytes; ilRxPackedIndex++)
#  endif
  {
    vuint8 ilCurVnHnd, ilVnMsgActiveMask = 0;

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    for (ilCurVnHnd = IlVnStartIndex[channel]; ilCurVnHnd < IlVnStartIndex[(channel + 1)]; ilCurVnHnd++)
#  else
    for (ilCurVnHnd = 0; ilCurVnHnd < kIlNumberOfVirtualNets; ilCurVnHnd++)
#  endif
    {
      /* Skip the one that shall be deactivated */
      if (ilCurVnHnd != ilVnHnd)
      {
        /* Merge the flags of these 8 messages that are currently active */
        if ((ilRxActiveVn[(ilCurVnHnd >> 3)] & VnBitMask[(ilCurVnHnd & 0x07)]) != 0)
        {
          ilVnMsgActiveMask |= IlVnRxMessageMapping[ilCurVnHnd][ilRxPackedIndex];
        }
      }
    }
    ilVnRxMessageActive[ilRxPackedIndex] = ilVnMsgActiveMask & ilVnRxMessageEnable[ilRxPackedIndex];
  }
  ilRxActiveVn[(ilVnHnd >> 3)] &= VnBitClrMask[(ilVnHnd & 0x07)];
# else
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  ilVnHnd = ilVnHnd;
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  channel = channel;
#   endif
#  endif
# endif/* IL_ENABLE_RX */
  return IL_VN_DEACTIVATED;
}                               /* End of IlRxDeactivateVnMsg) */

/**********************************************************************************************************************
  IlRxStartVnMsgSupervision
**********************************************************************************************************************/
void IlRxStartVnMsgSupervision(IL_CHANNEL_ILTYPE_FIRST vuint8 ilVnHnd)
{
# if defined( IL_ENABLE_RX_TIMEOUT )|| defined( IL_ENABLE_RX_EXT_TIMEOUT )
  IlReceiveHandle ilRxHnd = IlGetRxMsgStartIndex(IL_CHANNEL_ILPARA_MACRO);
  vuint8 ilRxPackedIndex;
  vuint8 ilRxPackedMask = 0x01;

  IlAssert(ilVnHnd < kIlNumberOfVirtualNets, ILERR_ILLVNNR);
#  if defined ( IL_ENABLE_SYS_ARGCHECK )
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  if ((ilVnHnd < IlVnStartIndex[channel]) || (ilVnHnd >= IlVnStartIndex[channel + 1]))
#   else
  if (ilVnHnd >= kIlNumberOfVirtualNets)
#   endif
  {
    return;
  }
#  endif
  IlAssert(RxEnabled(IL_CHANNEL_ILPARA_MACRO), ILERR_TXSTOPPED);
  if (!RxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    return;
  }
  IlAssert(((ilRxActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) != 0), ILERR_RXVNDEACTIVATED);
  if ((ilRxActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) == 0)
  {
    return;
  }
  if ((ilRxSVActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) != 0)
  {
    return;
  }

#  if defined( IL_ENABLE_RX_TIMEOUT ) || defined ( IL_ENABLE_RX_EXT_TIMEOUT )
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilRxPackedIndex = IlGetPackedRxObjectsStartIndex(channel);
       ilRxPackedIndex < IlGetPackedRxObjectsStartIndex(channel + 1); ilRxPackedIndex++)
#   else
  for (ilRxPackedIndex = 0; ilRxPackedIndex < kIlNrOfPackedRxObjectBytes; ilRxPackedIndex++)
#   endif
  {
    /* All enabled Rx messages for this VN */
    vuint8 ilVnMsgMask = IlVnRxMessageMapping[ilVnHnd][ilRxPackedIndex] & ilVnRxMessageEnable[ilRxPackedIndex];
    /* All active timeout supervised and enabled Rx messages for this VN */
    vuint8 ilVnToutMsgMask = ilVnRxSupervisionActive[ilRxPackedIndex] | ilVnMsgMask;
    /* All enabled Rx messages without activated ext id timeout supervision for this VN */
    vuint8 ilVnStdToutMsgMask = ilVnToutMsgMask ^ ilVnRxSupervisionActive[ilRxPackedIndex];
    vuint8 ilBitIndex;

    for (ilBitIndex = 0; ilBitIndex < 8; ilBitIndex++)
    {
      if ((ilVnMsgMask & ilRxPackedMask) != 0)
      {
        ilVnMsgMask &= (vuint8) ~ ilRxPackedMask;

#   if defined( IL_ENABLE_RX_TIMEOUT )
        if ((ilVnStdToutMsgMask & ilRxPackedMask) != 0)
        {
        /*--- Reset timeout counter to its initial state --------------------*/
          IlRxTimeoutHandle ilRxToutHnd = IlRxMsg2TimeoutIndirection[ilRxHnd];
#    if defined ( VGEN_GENY )
          if (ilRxToutHnd != kIlRxTimeoutHandleNotUsed)
#    endif
         /* VGEN_GENY */
          {
            ilRxTimeoutCounter[ilRxToutHnd] = IlGetStartRxTimeoutCounter(ilRxToutHnd);
          }
        }
#   endif
        /* IL_ENABLE_RX_TIMEOUT */

#   if defined( IL_ENABLE_RX_EXT_TIMEOUT )
        if ((ilVnToutMsgMask & ilRxPackedMask) != 0)
        {
          IlReceiveHandle ilRxExtIdHnd = IlGetRxExtIdHnd(ilRxHnd);
#    if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
          if ((ilRxExtIdHnd >= IlRxExtIDStartIndex[channel]) && (ilRxExtIdHnd < IlRxExtIDStartIndex[(channel + 1)]))
#    else
          if (ilRxExtIdHnd < kIlNumberOfExtIdRxObjects)
#    endif
          {
            vuint8 srcAddressIndex = ilExtIdRxMsgIdxOfSourceAddress[ilRxExtIdHnd];
            /* srcAddressIndex is now the index into the source address fields */

            /* If this is the first message that becomes active */
            /* for this node, start the supervision timer.      */
            if ((srcAddressIndex < kIlNrOfConfigNodes))
            {
              if ((ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO][(srcAddressIndex >> 3)] &
                   LSB2MSBBitMask[(srcAddressIndex & 0x07)]) != 0)
              {
                if (IlRxExtIDTimeoutFunctions[ilRxExtIdHnd] != V_NULL)
                {
                  CanInterruptDisable();
                  /* NCA already failed previously */
                  /* Perform signal indication     */
                  (*IlRxExtIDTimeoutFunctions[ilRxExtIdHnd]) ();
                  CanInterruptRestore();
                }
              }
              else
              {
                /* Check if there is an active message for this node. If yes, do not set an new timeout value. */
                if (ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][srcAddressIndex] == 0)
                {
                  /* Restart timer only if timeout not yet occurred for this node */
                  ilExtIdRxSrcAddrTimer[IL_CHANNEL_ILPARA_MACRO][srcAddressIndex] =
                    IlGetRxNcaMsgTimeoutCnt(IL_CHANNEL_ILPARA_ONLY);
                }
              }
              if ((ilVnStdToutMsgMask & ilRxPackedMask) != 0)
              {
                /* Count the number of active messages per node */
                ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][srcAddressIndex]++;
              }
            }
          }
        }
#   endif
        /* IL_ENABLE_RX_EXT_TIMEOUT */
      }
      if (ilRxPackedMask == 0x80)
      {
        ilRxPackedMask = 0x01;
      }
      else
      {
        ilRxPackedMask <<= 1;
      }
      ilRxHnd++;
    }
    ilVnRxSupervisionActive[ilRxPackedIndex] = ilVnToutMsgMask;
  }
#   if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
  ilExtIdRxDefaultTimer[IL_CHANNEL_ILPARA_MACRO] = IlGetRxNcaMsgTimeoutCnt(IL_CHANNEL_ILPARA_ONLY);
#   endif
#  endif/* IL_ENABLE_RX_TIMEOUT || IL_ENABLE_RX_EXT_TIMEOUT */

  /*--- Set marker that this VN is activated --------------------------------*/
  ilRxSVActiveVn[(ilVnHnd >> 3)] |= VnBitMask[(ilVnHnd & 0x07)];
# else/* IL_ENABLE_RX_TIMEOUT || IL_ENABLE_RX_EXT_TIMEOUT */
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  ilVnHnd = ilVnHnd;
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  channel = channel;
#   endif
#  endif
# endif /* IL_ENABLE_RX_TIMEOUT || IL_ENABLE_RX_EXT_TIMEOUT */
}                               /* End of IlRxStartVnMsgSupervision() */

/**********************************************************************************************************************
  IlRxDeactivateVnMsgSupervision
**********************************************************************************************************************/
Il_Status IlRxDeactivateVnMsgSupervision(IL_CHANNEL_ILTYPE_FIRST vuint8 ilVnHnd)
{
# if defined ( IL_ENABLE_RX )
  vuint8 ilRxPackedIndex;
#  if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
  IlReceiveHandle ilRxHnd = IlGetRxMsgStartIndex(IL_CHANNEL_ILPARA_MACRO);
  vuint8 ilRxPackedMask = 0x01;
#  endif/* IL_ENABLE_RX_EXT_TIMEOUT */

  IlAssert(ilVnHnd < kIlNumberOfVirtualNets, ILERR_ILLVNNR);
#  if defined ( IL_ENABLE_SYS_ARGCHECK )
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  if ((ilVnHnd < IlVnStartIndex[channel]) || (ilVnHnd >= IlVnStartIndex[channel + 1]))
#   else
  if (ilVnHnd >= kIlNumberOfVirtualNets)
#   endif
  {
    return IL_ERROR;
  }
#  endif
  IlAssert(RxEnabled(IL_CHANNEL_ILPARA_MACRO), ILERR_RXSTOPPED);
  if (!RxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    return IL_ERROR;
  }
  IlAssert(((ilRxActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) != 0), ILERR_RXVNDEACTIVATED);
  if ((ilRxActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) == 0)
  {
    return IL_ERROR;
  }
  if ((ilRxSVActiveVn[(ilVnHnd >> 3)] & VnBitMask[(ilVnHnd & 0x07)]) == 0)
  {
    return IL_ERROR;
  }

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilRxPackedIndex = IlGetPackedRxObjectsStartIndex(channel);
       ilRxPackedIndex < IlGetPackedRxObjectsStartIndex(channel + 1); ilRxPackedIndex++)
#  else
  for (ilRxPackedIndex = 0; ilRxPackedIndex < kIlNrOfPackedRxObjectBytes; ilRxPackedIndex++)
#  endif
  {
    vuint8 ilCurVnHnd, ilVnMsgActiveMask = 0;

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    for (ilCurVnHnd = IlVnStartIndex[channel]; ilCurVnHnd < IlVnStartIndex[(channel + 1)]; ilCurVnHnd++)
#  else
    for (ilCurVnHnd = 0; ilCurVnHnd < kIlNumberOfVirtualNets; ilCurVnHnd++)
#  endif
    {
      /* Skip the one that shall be deactivated */
      if (ilCurVnHnd != ilVnHnd)
      {
        /* Merge the flags of these 8 messages that are currently active */
        if ((ilRxSVActiveVn[(ilCurVnHnd >> 3)] & VnBitMask[(ilCurVnHnd & 0x07)]) != 0)
        {
          ilVnMsgActiveMask |= IlVnRxMessageMapping[ilCurVnHnd][ilRxPackedIndex];
        }
      }
    }

    ilVnMsgActiveMask &= ilVnRxMessageEnable[ilRxPackedIndex];

    /* Failure if a new VN is added. Just removing is allowed */
    IlAssert((((ilVnMsgActiveMask ^ ilVnRxSupervisionActive[ilRxPackedIndex]) & ilVnMsgActiveMask) == 0), 0);

    {
#  if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
      vuint8 ilBitIndex;
      vuint8 ilVnMsgMask = ilVnMsgActiveMask ^ ilVnRxSupervisionActive[ilRxPackedIndex];
#  endif
      ilVnRxSupervisionActive[ilRxPackedIndex] = ilVnMsgActiveMask;

#  if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
      for (ilBitIndex = 0; ilBitIndex < 8; ilBitIndex++)
      {
        /* Check if the message shall be activated for this VN */
        if ((ilVnMsgMask & ilRxPackedMask) != 0)
        {
          IlReceiveHandle ilRxExtIdHnd = IlGetRxExtIdHnd(ilRxHnd);
          ilVnMsgMask &= (vuint8) ~ ilRxPackedMask;

          /*--- Reset timeout counter to its initial state --------------------*/
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
          if ((ilRxExtIdHnd >= IlRxExtIDStartIndex[channel]) && (ilRxExtIdHnd < IlRxExtIDStartIndex[(channel + 1)]))
#   else
          if (ilRxExtIdHnd < kIlNumberOfExtIdRxObjects)
#   endif
          {
            vuint8 srcAddressIndex = ilExtIdRxMsgIdxOfSourceAddress[ilRxExtIdHnd];
            /* srcAddressIndex is now the index into the source address fields */

            /* ##HP: Re-work comment. May assertion instead of IF */
            /* If this is the first message that becomes active */
            /* for this node, start the supervision timer.      */
            if (ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][srcAddressIndex] != 0)
            {
              /* Count the number of active messages per node */
              ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][srcAddressIndex]--;
            }
          }
        }
        if (ilRxPackedMask == 0x80)
        {
          ilRxPackedMask = 0x01;
        }
        else
        {
          ilRxPackedMask <<= 1;
        }
        ilRxHnd++;
      }
#  endif/* IL_ENABLE_RX_EXT_TIMEOUT */
    }
  }
  ilRxSVActiveVn[(ilVnHnd >> 3)] &= VnBitClrMask[(ilVnHnd & 0x07)];
# else
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  ilVnHnd = ilVnHnd;
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  channel = channel;
#   endif
#  endif
# endif/* IL_ENABLE_RX */
  return IL_VN_DEACTIVATED;
}                               /* End of IlRxDeactivateVnMsgSupervision() */

/**********************************************************************************************************************
  IlQueueVnMsg
**********************************************************************************************************************/
void IlQueueVnMsg(IL_CHANNEL_ILTYPE_FIRST vuint8 ilVnHnd)
{
# if defined ( IL_ENABLE_TX )
  IlTransmitHandle ilTxHnd = IlGetTxMsgStartIndex(IL_CHANNEL_ILPARA_MACRO);
  vuint8 ilTxPackedIndex;
  vuint8 ilTxPackedMask = 0x01;

  IlAssert(ilVnHnd < kIlNumberOfVirtualNets, ILERR_ILLVNNR);

#  if defined ( IL_ENABLE_SYS_ARGCHECK )
  if (ilVnHnd >= kIlNumberOfVirtualNets)
  {
    return;
  }
#  endif

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  for (ilTxPackedIndex = IlGetPackedTxObjectsStartIndex(channel);
       ilTxPackedIndex < IlGetPackedTxObjectsStartIndex(channel + 1); ilTxPackedIndex++)
#  else
  for (ilTxPackedIndex = 0; ilTxPackedIndex < kIlNrOfPackedTxObjectBytes; ilTxPackedIndex++)
#  endif
  {
    /* Add the Vn-message to the Vn-active  */
    vuint8 ilBitIndex;
    /* Change for ESCAN5993: SendOnInit-array must be handled separately */
    vuint8 ilVnMsgMask = IlVnTxMessageMapping[ilVnHnd][ilTxPackedIndex] & ilVnTxMessageActive[ilTxPackedIndex];
    for (ilBitIndex = 0; ilBitIndex < 8; ilBitIndex++)
    {
      if ((ilVnMsgMask & ilTxPackedMask) != 0)
      {
        ilVnMsgMask &= (vuint8) ~ ilTxPackedMask;
        if ((ilTxState[ilTxHnd] & kTxQueueInit) != 0)
        {
          /*--- queue the message (set an event) ------------------------------*/
          ilTxState[ilTxHnd] |= kTxSendRequest;
        }
      }
      if (ilTxPackedMask == 0x80)
      {
        ilTxPackedMask = 0x01;
      }
      else
      {
        ilTxPackedMask <<= 1;
      }
      ilTxHnd++;
    }
  }
# else/* IL_ENABLE_TX */
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  ilVnHnd = ilVnHnd;
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  channel = channel;
#   endif
#  endif
# endif/* IL_ENABLE_TX */
}                               /* End of IlQueueVnMsg() */

/**********************************************************************************************************************
  IlSetTxMessageEnable
**********************************************************************************************************************/
# if defined ( IL_ENABLE_TX )
Il_Status IlSetTxMessageEnable(IlTransmitHandle ilTxHnd, vuint8 type)
{
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  CanChannelHandle channel;
  for (channel = 0; channel < kIlNumberOfChannels; channel++)
  {
    if (ilTxHnd < IlTxMsgStartIndex[(channel + 1)])
    {
      break;
    }
  }
  if (channel >= kIlNumberOfChannels)
  {
    return IL_ERROR;
  }
#  endif
#  if defined ( IL_ENABLE_SYS_ARGCHECK )
  if (ilTxHnd >= kIlNumberOfTxObjects)
  {
    return IL_ERROR;
  }
#  endif

#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  ilTxHnd =
    ((IlGetPackedTxObjectsStartIndex(IL_CHANNEL_ILPARA_MACRO) * 8) +
     (ilTxHnd - IlTxMsgStartIndex[IL_CHANNEL_ILPARA_MACRO]));
#  endif

  if (type == kIlMsgEnabled)
  {
    ilVnTxMessageEnable[(ilTxHnd >> 3)] |= LSB2MSBBitMask[(ilTxHnd & 0x07)];
  }
  else
  {
    ilVnTxMessageEnable[(ilTxHnd >> 3)] &= (vuint8) ~ LSB2MSBBitMask[(ilTxHnd & 0x07)];
  }
  return IL_OK;
}                               /* End of IlSetTxMessageEnable() */
# endif/* IL_ENABLE_TX */

/**********************************************************************************************************************
  IlSetRxMessageEnable
**********************************************************************************************************************/
# if defined ( IL_ENABLE_RX )
Il_Status IlSetRxMessageEnable(IlReceiveHandle ilRxHnd, vuint8 type)
{
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  CanChannelHandle channel;
  for (channel = 0; channel < kIlNumberOfChannels; channel++)
  {
    if (ilRxHnd < IlRxMsgStartIndex[(channel + 1)])
    {
      break;
    }
  }
  if (channel >= kIlNumberOfChannels)
  {
    return IL_ERROR;
  }
#  endif
#  if defined ( IL_ENABLE_SYS_ARGCHECK )
  if (ilRxHnd >= kIlNumberOfRxObjects)
  {
    return IL_ERROR;
  }
#  endif
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  ilRxHnd =
    ((IlGetPackedRxObjectsStartIndex(IL_CHANNEL_ILPARA_MACRO) * 8) +
     (ilRxHnd - IlRxMsgStartIndex[IL_CHANNEL_ILPARA_MACRO]));
#  endif

  if (type == kIlMsgEnabled)
  {
    ilVnRxMessageEnable[(ilRxHnd >> 3)] |= LSB2MSBBitMask[(ilRxHnd & 0x07)];
  }
  else
  {
    ilVnRxMessageEnable[(ilRxHnd >> 3)] &= (vuint8) ~ LSB2MSBBitMask[(ilRxHnd & 0x07)];
  }
  return IL_OK;
}                               /* End of IlSetRxMessageEnable() */
# endif/* IL_ENABLE_RX */

/**********************************************************************************************************************
  IlSetRxMessageSourceAddress
**********************************************************************************************************************/
# if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
Il_Status IlSetRxMessageSourceAddress(IlReceiveHandle ilRxHnd, vuint8 srcAddress)
{
  IlReceiveHandle ilRxExtIdHnd = IlGetRxExtIdHnd(ilRxHnd);
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  CanChannelHandle channel;
  for (channel = 0; channel < kIlNumberOfChannels; channel++)
  {
    if (ilRxExtIdHnd < IlRxExtIDStartIndex[(channel + 1)])
    {
      break;
    }
  }
#  endif

  IlAssert(ilRxHnd < kIlNumberOfRxObjects, ILERR_ILLRXMSGHANDLE);
  IlAssert(ilRxExtIdHnd < kIlNumberOfExtIdRxObjects, ILERR_ILLRXEXTIDMSGHANDLE);

  if (ilRxHnd >= kIlNumberOfRxObjects)
  {
    return IL_ERROR;
  }
  if (ilRxExtIdHnd >= kIlNumberOfExtIdRxObjects)
  {
    return IL_ERROR;
  }
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  if (channel >= kIlNumberOfChannels)
  {
    return IL_ERROR;
  }
#  endif

  ilExtIdRxMsgIdxOfSourceAddress[ilRxExtIdHnd] = IlProcessLearnedSourceAddress(IL_CHANNEL_ILPARA_FIRST srcAddress);
  return IL_OK;
}                               /* End of IlSetRxMessageSourceAddress() */
# endif/* IL_ENABLE_RX_EXT_TIMEOUT */

/**********************************************************************************************************************
  IlGetRxMessageSourceAddress
**********************************************************************************************************************/
# if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
Il_Status IlGetRxMessageSourceAddress(IlReceiveHandle ilRxHnd, vuint8 * pSrcAddress)
{
  IlReceiveHandle ilRxExtIdHnd = IlGetRxExtIdHnd(ilRxHnd);
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  CanChannelHandle channel;
  for (channel = 0; channel < kIlNumberOfChannels; channel++)
  {
    if (ilRxExtIdHnd < IlRxExtIDStartIndex[(channel + 1)])
    {
      break;
    }
  }
#  endif

  IlAssert(ilRxHnd < kIlNumberOfRxObjects, ILERR_ILLRXMSGHANDLE);
  IlAssert(ilRxExtIdHnd < kIlNumberOfExtIdRxObjects, ILERR_ILLRXEXTIDMSGHANDLE);

  if (ilRxHnd >= kIlNumberOfRxObjects)
  {
    return IL_ERROR;
  }
  if (ilRxExtIdHnd >= kIlNumberOfExtIdRxObjects)
  {
    return IL_ERROR;
  }
#  if defined( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  if (channel >= kIlNumberOfChannels)
  {
    return IL_ERROR;
  }
#  endif

  (*pSrcAddress) =
    ilExtIdRxLearnedSourceAddresses[IL_CHANNEL_ILPARA_MACRO][ilExtIdRxMsgIdxOfSourceAddress[ilRxExtIdHnd]];
  return IL_OK;
}                               /* End of IlGetRxMessageSourceAddress() */
# endif/* IL_ENABLE_RX_EXT_TIMEOUT */

/**********************************************************************************************************************
  IlSetOwnNodeAddress
**********************************************************************************************************************/
Il_Status IlSetOwnNodeAddress(IL_CHANNEL_ILTYPE_FIRST vuint8 srcAddress)
{
# if defined ( C_ENABLE_TX_MASK_EXT_ID )
  CanSetTxIdExtLo(IL_CHANNEL_ILPARA_FIRST srcAddress);
  return IL_OK;
# else
#  if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  srcAddress = srcAddress;
#   if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  channel = channel;
#   endif
#  endif
  return IL_ERROR;
# endif
}                               /* End of IlSetOwnNodeAddress() */

/**********************************************************************************************************************
  IlGetNodeCommActiveState
**********************************************************************************************************************/
# if defined ( IL_ENABLE_RX )
vuint8 IlGetNodeCommActiveState(IL_CHANNEL_ILTYPE_FIRST vuint8 srcAddress)
{
#  if defined ( IL_ENABLE_RX_EXT_TIMEOUT )
  vuint8 retVal = kIlNodeUnknown;
  vuint8 srcAddressIndex;

  /* Get the index of this node address */
  srcAddressIndex = IlGetSourceAddressIndex(IL_CHANNEL_ILPARA_FIRST srcAddress);

  /* Node not found in list */
  if (srcAddressIndex == IL_NODE_ADDRESS_UNKNOWN)
  {
    /* Return, that node is unknown */
    retVal = kIlNodeUnknown;
  }
  else
  {
    /* ----------------------------------- */
    /* Node found in list. Check the state */
    /* ----------------------------------- */

    /* First, check if timeout occurred    */
    if ((ilNodeCommActiveTimeoutFlags[IL_CHANNEL_ILPARA_MACRO][(srcAddressIndex >> 3)] &
         LSB2MSBBitMask[(srcAddressIndex & 0x07)]) != 0)
    {
      /* Highest priority: Node supervision failed */
      retVal = kIlNodeFailed;
    }
    else
    {
      /* Second priority: check Active/inactive state. */
      if (ilExtIdActiveRxMsgsPerSourceAddress[IL_CHANNEL_ILPARA_MACRO][srcAddressIndex] != 0)
      {
        /* At least, one message/VN is active for this node  */
        retVal = kIlNodeActive;
      }
      else
      {
        /* No message/VN is active for this node, node is idle.  */
        retVal = kIlNodeIdle;
      }
    }
  }
  return (retVal);
#  else
      /* IL_ENABLE_RX_EXT_TIMEOUT */
#   if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  srcAddress = srcAddress;
#    if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
  channel = channel;
#    endif
#   endif
  return kIlNodeUnknown;
#  endif
       /* IL_ENABLE_RX_EXT_TIMEOUT */
}                               /* End of IlGetNodeCommActiveState() */
# endif/* IL_ENABLE_RX */

/**********************************************************************************************************************
  IlDequeueNonActiveTxMessages
**********************************************************************************************************************/
void IlDequeueNonActiveTxMessages(IL_CHANNEL_ILTYPE_ONLY)
{
# if defined ( IL_ENABLE_TX )
  IlTransmitHandle ilTxHnd;

  CanInterruptDisable();
  if (TxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    for (ilTxHnd = IlTxMsgStartIndex[channel]; ilTxHnd < IlTxMsgStartIndex[(channel + 1)]; ilTxHnd++)
#  else
    for (ilTxHnd = 0; ilTxHnd < kIlNumberOfTxObjects; ilTxHnd++)
#  endif
    {
      /* Prevents de-queueing messages where the VN is  inactive */
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
      vuint8 ilBitIndex =
        ((IlGetPackedTxObjectsStartIndex(IL_CHANNEL_ILPARA_MACRO) * 8) +
         (ilTxHnd - IlTxMsgStartIndex[IL_CHANNEL_ILPARA_MACRO]));
      if ((ilVnTxMessageActive[ilBitIndex >> 3] & LSB2MSBBitMask[ilBitIndex & 0x07]) == 0)
#  else
      if ((ilVnTxMessageActive[ilTxHnd >> 3] & LSB2MSBBitMask[ilTxHnd & 0x07]) == 0)
#  endif
      {
        /* clear send request flag  ----------------------------------- */
        ilTxState[ilTxHnd] &= kTxNotSendRequest;
      }
    }
  }
  CanInterruptRestore();
# else
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;
#  endif
# endif
}                               /* End of IlDequeueNonActiveTxMessages() */

/**********************************************************************************************************************
  IlRequeueTransmitMessages
**********************************************************************************************************************/
void IlRequeueTransmitMessages(IL_CHANNEL_ILTYPE_ONLY)
{
# if defined ( IL_ENABLE_TX )
  IlTransmitHandle ilTxHnd;

  CanInterruptDisable();
  if (TxEnabled(IL_CHANNEL_ILPARA_MACRO))
  {
    /*----- do the loop for every Tx object  -------------------------------*/
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1)
    for (ilTxHnd = IlTxMsgStartIndex[channel]; ilTxHnd < IlTxMsgStartIndex[(channel + 1)]; ilTxHnd++)
#  else
    for (ilTxHnd = 0; ilTxHnd < kIlNumberOfTxObjects; ilTxHnd++)
#  endif
    {
      if (ilTxUpdateCounter[ilTxHnd] == kIlStopUpdateCounterValue)
      {
        ilTxUpdateCounter[ilTxHnd] = 0;
        ilTxState[ilTxHnd] |= kTxSendRequest;
      }
    }
  }
  CanInterruptRestore();
# else/* IL_ENABLE_TX */
#  if defined ( C_MULTIPLE_RECEIVE_CHANNEL ) && (kIlNumberOfChannels > 1) && defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  channel = channel;            /* to avoid compiler warnings */
#  endif
# endif/* IL_ENABLE_TX */
}                               /* End of IlRequeueTransmitMessages() */

# if defined ( IL_ENABLE_TX )
/**********************************************************************************************************************
  IlGetTransmitMessageStatus
**********************************************************************************************************************/
vuint8 IlGetTransmitMessageStatus(IlTransmitHandle ilTxHnd)
{
  vuint8 statusX = 0;

  if (ilTxUpdateCounter[ilTxHnd] == kIlStopUpdateCounterValue)
  {
    statusX |= kIlTxMsgQueued;
  }
  if ((ilTxState[ilTxHnd] & kTxSendRequest) != 0)
  {
    statusX |= kIlTxMsgPending;
  }
  return statusX;
}                               /* End of IlGetTransmitMessageStatus() */
# endif/* IL_ENABLE_TX */
#endif /* IL_TYPE_GM */

/**********************************************************************************************************************
  END OF FILE: Il.c
**********************************************************************************************************************/
/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
