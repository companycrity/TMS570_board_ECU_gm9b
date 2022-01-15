/***************************************************************************************************************
| Project Name: GM Gateway Diagnostic Addon
|    File Name: Ggda.c
|
|  Description: GM Gateway Diagnostic Addon.
|  
|---------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|---------------------------------------------------------------------------------------------------------------
| Copyright (c) 2005-2010 Vector Informatik GmbH            All rights reserved.
|
|                         This software is copyright protected and 
|                         proprietary to Vector Informatik GmbH.
|                         Vector Informatik GmbH grants to you only
|                         those rights as set out in the license conditions.
|                         All other rights remain with Vector Informatik GmbH.
|
|---------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|---------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -----------------------------------------------------------------------
| Sa           Mishel Shishmanyan        Vector Informatik GmbH
| Mhe          Matthias Heil             Vector Informatik GmbH
|---------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|---------------------------------------------------------------------------------------------------------------
| Date         Ver       Author  Description
| ----------   -----     ------  ----------------------------------------------------------------------------------
| 2005-11-02   1.00      Sa      Creation.
| 2006-01-31   1.01      Sa      Modified: Changed include order of the header files.
|                        Sa      Modified: Compiler warnings.
| 2006-02-16   2.00      Mhe     Added:    Support for multiple channels
|                        Mhe     Modified: Timers use events
| 2006-07-20   2.01      Mhe     Fixed:    ESCAN00016758: Compilation error when disabling A9
| 2007-01-24   2.02      Sa      Fixed:    ESCAN00018731: GGDA accepts diagnostic requests which are functionally addressed to kGgdaEcuNumber
| 2007-02-16   2.03      Sa      Fixed:    ESCAN00019415: Wrong NRC on service 0x10 with invalid length and no sub-function supported.
|                        Sa      Modified: ESCAN00019300: Compiler errror occurs when disabling any optional services besides 0xA9.
| 2007-03-08   2.04      Sa      Fixed:    ESCAN00019852: Tester present timer resets on each receipt of a mode 0x28 request.
|                        Sa      Modified: ESCAN00019989: Warning(ccom): far pointer (implicitly) casted by near pointer.
|                        Sa      Modified: ESCAN00020097: Changed timer management design.
|                        Sa      Modified: ESCAN00020098: Compiler warning on unreferenced static function GgdaMapTxHandleToContext.
|                        Sa      Fixed:    ESCAN00020099: VN_Timer stop on functional request.
| 2007-06-08   2.05      Mhe     Fixed:    ESCAN00021000: compiler error: GGDA requires "HiSpeed Mode" support even with service 0xA5 02 disabled
| 2008-04-02   2.06      Mhe     Fixed:    ESCAN00024481: Not possible to disable individual subfunctions for diagnostic mode 0xA9
| 2008-11-14   2.06.01   Mhe     Fixed:    ESCAN00031288: Compiler Error: Invalid conversion from "unsigned char volatile __far *" to "unsigned char __near *"
| 2010-06-28   2.06.02   Sa      Fixed:    ESCAN00043057: Service 0x28 will be responded positively even if the operations was not executed successfully
| 2010-12-10   2.06.03   Mhe     Fixed:    ESCAN00047411: Service 0x10 0x04 activates tester present monitoring
***************************************************************************************************************/
/*****************************
 include section 
*****************************/
#include "can_inc.h"
#include "il_inc.h"
#include "tpmc.h"
#include "Desc.h"
#include "ggda.h"

/*---------------------*/
/*    Version checks   */
/*---------------------*/
#if (DIAG_CANDESCGGDAEXT_GM_VERSION != 0x0206)
# error "Inconsistent header and source file version!"
#endif

#if (DIAG_CANDESCGGDAEXT_GM_RELEASE_VERSION != 0x03)
# error "Inconsistent header and source file release version!"
#endif

#if (GGDA_CONFIG_VERSION != 0x0203)
# error "Inconsistent configuration version"
#endif

/*---------------------*/
/*Configuration summary*/
/*---------------------*/
#if (GGDA_CONFIG_SERVICE_10_02_SUPPORT == GGDA_CONFIG_ON) || \
    (GGDA_CONFIG_SERVICE_10_04_SUPPORT == GGDA_CONFIG_ON)
# define GGDA_CONFIG_SERVICE_10_XX_SUPPORT                           GGDA_CONFIG_ON
#else
# define GGDA_CONFIG_SERVICE_10_XX_SUPPORT                           GGDA_CONFIG_OFF
#endif

/*---------------------*/
/*       Constants     */
/*---------------------*/
#if !defined(VN_Diagnostics)
/* The diagnsotic VN is always zero */
# define VN_Diagnostics                                              ((vuint8)0)
#endif

#define kGgdaDiagBufferSize                                          7 /* Only single frames requests and responses */
#define kGgdaRcrRpBufferSize                                         3 /* 7f xx 78 */

/*-------------------------*/
/* Negative response codes */
/*-------------------------*/

typedef enum
{
  kGgdaNrcNone                       = 0x00,
  kGgdaNrcServiceNotSupported        = 0x11,
  kGgdaNrcSubfunctionNotSupported    = 0x12,
  kGgdaNrcInvalidFormat              = 0x12,
  kGgdaNrcConditionsNotCorrect       = 0x22,
  kGgdaNrcRequestOutOfRange          = 0x31,
  kGgdaNrcResponsePending            = 0x78
}GgdaNrcType;

/*-------------------------*/
/* Assertion error codes   */
/*-------------------------*/

enum
{
  kGgdaAssertInvalidContext,
  kGgdaAssertInvalidConfiguration
};

/*-------------------------*/
/*         Events          */
/*-------------------------*/
/* Event management */
#define GGDA_EV_NEW_REQ                                              ((GgdaEventType)(0x0001))
#define GGDA_EV_RESEND_MSG                                           ((GgdaEventType)(0x0002))

#define GGDA_EV_SEND_UNSOL_RES                                       ((GgdaEventType)(0x0010))
#define GGDA_EV_SEND_RCR_RP_RES                                      ((GgdaEventType)(0x0020))
#define GGDA_EV_SEND_FINAL_RES                                       ((GgdaEventType)(0x0040))

#define GGDA_EV_RX_A9_80                                             ((GgdaEventType)(0x0100))
#define GGDA_EV_RX_A9_81                                             ((GgdaEventType)(0x0200))
#define GGDA_EV_RX_A9_82                                             ((GgdaEventType)(0x0400))
#define GGDA_EV_RX_A9_8X                                             ((GgdaEventType)(GGDA_EV_RX_A9_80 | GGDA_EV_RX_A9_81 | GGDA_EV_RX_A9_82))

#define GGDA_EV_ACTIVATE_VN                                          ((GgdaEventType)(0x1000))


/*-------------------------*/
/*         Timers          */
/*-------------------------*/
#define GGDA_TIMER_S1                                                ((GgdaTimerHandle)0)
#define GGDA_TIMER_P2                                                ((GgdaTimerHandle)1)
#define GGDA_TIMER_VN                                                ((GgdaTimerHandle)2)
#define GGDA_TIMER_UUDT_CONF                                         ((GgdaTimerHandle)3)

#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
# define GGDA_NUM_TIMERS                                             4
#else
# define GGDA_NUM_TIMERS                                             3
#endif

/*-------------------------*/
/*         Modes           */
/*-------------------------*/
#define kGgdaProgModeNone                                            ((vbittype)0x00)
#define kGgdaProgModeAcceptedLS                                      ((vbittype)0x01)
#define kGgdaProgModeAcceptedHS                                      ((vbittype)0x02)
#define kGgdaProgModeActive                                          ((vbittype)0x03)


#define kGgdaUsdtTxModeResNone                                       ((vbittype)0x00)
#define kGgdaUsdtTxModeResRcrRp                                      ((vbittype)0x01)
#define kGgdaUsdtTxModeResFinal                                      ((vbittype)0x02)
#define kGgdaUsdtTxModeResUnsol                                      ((vbittype)0x03)


/*-------------------------*/
/*        A9 Modes         */
/*-------------------------*/
/* temp buffer lengths */
#define kGgdaSvcA9BufferLen                                          6/* some CPUs could copy word instead of bytes*/

#define kGgdaRdiMode80                                               ((vbittype)0x01u)
#define kGgdaRdiMode81                                               ((vbittype)0x02u)
#define kGgdaRdiMode82                                               ((vbittype)0x04u)

#if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
#define kGgdaRdiLastMode                                             (kGgdaRdiMode82)
#define kGgdaRdiModeMask                                             ((vbittype)(kGgdaRdiMode80 | kGgdaRdiMode81 | kGgdaRdiMode82))
#else
#define kGgdaRdiLastMode                                             (kGgdaRdiMode81)
#define kGgdaRdiModeMask                                             ((vbittype)(kGgdaRdiMode80 | kGgdaRdiMode81))
#endif

/* Precalculated mask to avoid compiler warnings on clearing negated state */

/*---------------------*/
/* Internal data types */
/*---------------------*/
typedef struct
{
  vbittype  isFuncReq          : 1;
  vbittype  isCommHalted       : 1;
  vbittype  isResActive        : 1;
  vbittype  progMode           : 2; /* 00 - none, 01 - acceptedLowSpeed, 02 - acceptedHiSpeed, 03 - active */

  vbittype  isTxModeActivity   : 2; /* 00 - none, 01 - rcrRp, 02 - final, 03 - unsolicited */
  vbittype  isRxModeActive     : 1;
  vbittype  isUsdtBufferLocked : 1;
  vbittype  isDiagActive       : 1;
}GgdaStateEngineType;

#if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
typedef struct
{
  vbittype  is81ModeActive    :1;/* 0x00 - No, 0x01 - Yes,  */
  vbittype  isLastDtcFound    :1;/* 0x00 - No, 0x01 - Yes,  */
  vbittype  isFirstAnswer     :3;/* 0x00 - None, 0x01 - for 0x80, 0x02 - for 0x81, 0x04 - for 0x82, */
  vbittype  answerMode        :3;/* 0x00 - none, 0x01 - 0x80, 0x02 - 0x81, 0x04 - 0x82 */
  vbittype  is82ModeActive    :1;/* 0x00 - No, 0x01 - Yes,  */
  vbittype  isUudtBufferLocked:1;
}GgdaRdiStateCtrlType;
#else
typedef struct
{
  vbittype  is81ModeActive    :1;/* 0x00 - No, 0x01 - Yes,  */
  vbittype  isLastDtcFound    :1;/* 0x00 - No, 0x01 - Yes,  */
  vbittype  isFirstAnswer     :2;/* 0x00 - None, 0x01 - for 0x80, 0x02 - for 0x81 */
  vbittype  answerMode        :2;/* 0x00 - none, 0x01 - 0x80, 0x02 - 0x81 */
  vbittype  isUudtBufferLocked:1;
}GgdaRdiStateCtrlType;
#endif

 /* Take care if more events needed by a task to enlarge these types!!!*/
typedef vuint16 GgdaEventType;
typedef vuintx  GgdaTimerHandle;
typedef vuintx  GgdaTimerEventType;

/* Communication */
typedef struct
{
  GgdaStateEngineType stateMachine;
  GgdaEventType       eventRegister;
  GgdaNrcType         errorRegister;
  vuint8              numActiveTimers;
  vuint16             timers[GGDA_NUM_TIMERS];
#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
  /* Service A9 state machine */
  GgdaRdiStateCtrlType rdiStateCtrl;
  /* global storage of the searching masks */
  vuint8         rdi81SearchStatusMask;
  /* global current iterator value */
  vuint16        nextIterPos;
  /* global check mask for request */
  vuint8         nextMode;
  /* buffer for the asynchronous application writing */
  /* for mode 0x80 and 0x81 */
  vuint8         uudtPrimBuffer[kGgdaSvcA9BufferLen];
# if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
  vuint8         rdi82SearchStatusMask;
  /* buffer for mode 0x82 */
  vuint8         uudtSecBuffer[kGgdaSvcA9BufferLen];
# endif
#endif

  vuint16 dataLength;
  vuint8  diagBuffer[kGgdaDiagBufferSize];
  vuint8  rcrRpBuffer[kGgdaRcrRpBufferSize];
}GgdaContextType;

typedef struct
{
  vuint16 loadValue;
  vuint16 reloadValue;
}GgdaTimerInitType;
/*---------------------*/
/* Internal variables  */
/*---------------------*/
static GgdaContextType ggdaContexts[kGgdaNumContexts];

/*---------------------*/
/*     Utilities       */
/*---------------------*/
#if defined (V_CONFIG_USE_DUMMY_STATEMENT)
# define GGDA_IGNORE_UNREF_PARAM(paramName)                          (paramName) = (paramName);
#else
# define GGDA_IGNORE_UNREF_PARAM(paramName)                          /* do nothing */
#endif

#define GgdaGetTicksOfMs(msec)                                       ((vuint16)((msec)/(kGgdaTimerMsCycle)))
#define GgdaGetHiByte(word)                                          ((vuint8)((word) >> 8))
#define GgdaGetLoByte(word)                                          ((vuint8)(word))

/* -- CAN driver sanity checks -- */
/* ---------------  C_MULTIPLE_RECEIVE_BUFFER ------------------- */
#if defined (C_MULTIPLE_RECEIVE_BUFFER)
# error "Ggda only supports indexed CAN drivers"
/* -----------------  C_SINGLE_RECEIVE_BUFFER ------------------- */
#elif defined (C_SINGLE_RECEIVE_BUFFER)
# error "Ggda only supports indexed CAN drivers"
/* ---- C_MULTIPLE_RECEIVE_CHANNEL||C_SINGLE_RECEIVE_CHANNEL ---- */
#endif


/*---------------------*/
/* Internal Functions  */
/*---------------------*/
#if defined (VGEN_CONFIG_VSTDLIB) || defined (V_CONFIG_VSTDLIB)
/* There is a mem copy function */
# define GgdaMemCopy(tgtAddr, srcAddr, len)                          (VStdMemCpyRamToRam((tgtAddr), (srcAddr), (len)))
#else
static void GgdaMemCopy(vuint8* tgtAddr, const vuint8* const srcAddr, vuintx len);
#endif
static void GgdaCopyFromCan(vuint8* tgtAddr, CanChipDataPtr srcAddr, vuintx len);

/* Event manager */
static void GgdaSetEvent(GgdaContextIndexType context, GgdaEventType ev);
static void GgdaClearEvent(GgdaContextIndexType context, GgdaEventType ev);

/* Timer manager */
static void GgdaActivateTimer(GgdaContextIndexType context, GgdaTimerHandle timer);
static void GgdaReactivateTimer(GgdaContextIndexType context, GgdaTimerHandle timer);
static void GgdaRefreshTimer(GgdaContextIndexType context, GgdaTimerHandle timer);
static void GgdaDeactivateTimer(GgdaContextIndexType context, GgdaTimerHandle timer);

/* Low Level to Context Mapping */
#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
static GgdaContextIndexType GgdaMapTxHandleToContext(CanTransmitHandle txObject);
#endif
static GgdaContextIndexType GgdaMapCanChannelToContext(CanChannelHandle channel);
static GgdaContextIndexType GgdaMapTxChannelToContext(vuint8 tpTxChannel);
static GgdaContextIndexType GgdaMapRxChannelToContext(vuint8 tpRxChannel);

/* Service processing control */
static void GgdaProcessingDone(GgdaContextIndexType context);
static void GgdaPostProcessing(GgdaContextIndexType context);
static void GgdaOnStopSession(GgdaContextIndexType context);
static vuintx GgdaUsdtTransmit(GgdaContextIndexType context, vbittype txMode, vuint8* dataPtr, vuintx len);

/* UUDT Transmitter */
#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
static void GgdaRdiRxTask(GgdaContextIndexType context, GgdaEventType ev);
static void GgdaRdiTxTask(GgdaContextIndexType context);
#endif

/* Service processors */
#if (GGDA_CONFIG_SERVICE_10_XX_SUPPORT == GGDA_CONFIG_ON)
static void GgdaProcessInitiateDiagnosticOperation(GgdaContextIndexType context);
#endif

static void GgdaProcessReturnToNormalMode(GgdaContextIndexType context);
static void GgdaProcessDisableNormalComm(GgdaContextIndexType context);
static void GgdaProcessReadEcuId(GgdaContextIndexType context);
static void GgdaProcessTesterPresent(GgdaContextIndexType context);
static void GgdaProcessEnterProgrammingMode(GgdaContextIndexType context);

#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
static void GgdaProcessReadDtcInfo(GgdaContextIndexType context);
#endif

/* Debugging support */
#if (GGDA_CONFIG_DEBUG == GGDA_CONFIG_ON)
static void GgdaFatalError(vuint32 line, vuint8 error);
static void GgdaValidateConfiguration(void);

# define GgdaAssert(cond, error)                                     if (!(cond)) { GgdaFatalError(__LINE__, (error)); }
#else
# define GgdaValidateConfiguration()
# define GgdaAssert(x, y)
#endif

/*---------------------------*/
/*     Const variables       */
/*---------------------------*/
/* Timers' load and reload values */
static V_MEMROM0 V_MEMROM1 GgdaTimerInitType V_MEMROM2 ggdaTimerValues[GGDA_NUM_TIMERS] =
{
  {GgdaGetTicksOfMs(kGgdaTimeoutS1),            GgdaGetTicksOfMs(kGgdaTimeoutS1)}
 ,{GgdaGetTicksOfMs(kGgdaTimeoutP2),            GgdaGetTicksOfMs(kGgdaTimeoutP2Ex)}
 ,{GgdaGetTicksOfMs(kGgdaTimeoutVnDiagnostics), GgdaGetTicksOfMs(kGgdaTimeoutVnDiagnostics)}
#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
 ,{GgdaGetTicksOfMs(kGgdaCanConfirmTimeout),    GgdaGetTicksOfMs(kGgdaCanConfirmTimeout)}
#endif
};


/*---------------------------*/
/*     Implementation        */
/*---------------------------*/
#if (GGDA_CONFIG_DEBUG == GGDA_CONFIG_ON)
/*  ********************************************************************************
 * Function name:GgdaValidateConfiguration
 * Description: Validates if pre-compile and link-time parameter match.
 * Returns:  
 * Parameter(s): none
 * Particularitie(s) and limitation(s):none
 ********************************************************************************  */
static void GgdaValidateConfiguration(void)
{
  GgdaContextIndexType contextIter = kGgdaNumContexts;
  GgdaContextIndexType context1002 = kGgdaNumContexts;
  GgdaContextIndexType context1004 = kGgdaNumContexts;
  GgdaContextIndexType contextA502 = kGgdaNumContexts;

  /* Scan configuration for at least one enabled sub-function of service 0x10. */
  while (contextIter != 0)
  {
    contextIter--;

    if ((ggdaCanConfig[contextIter].optionalModes & kGgdaEnableMode1002) != 0)
    {
      context1002 = contextIter;
    }

    if ((ggdaCanConfig[contextIter].optionalModes & kGgdaEnableMode1004) != 0)
    {
      context1004 = contextIter;
    }

    if ((ggdaCanConfig[contextIter].optionalModes & kGgdaEnableModeA502) != 0)
    {
      contextA502 = contextIter;
    }
  }

# if (GGDA_CONFIG_SERVICE_10_XX_SUPPORT == GGDA_CONFIG_ON)
#  if (GGDA_CONFIG_SERVICE_10_02_SUPPORT == GGDA_CONFIG_ON)
  /* Pre-compile configuration shows that service 0x10 02 shall be supported, 
   * but no link-time cofiguration allows it!!! */
  GgdaAssert((context1002 != kGgdaNumContexts), kGgdaAssertInvalidConfiguration);
#  else
  /* Pre-compile configuration shows that service 0x10 02 will not be supported, 
   * but a link-time cofiguration allows it!!! */
  GgdaAssert((context1002 == kGgdaNumContexts), kGgdaAssertInvalidConfiguration);
#  endif
#  if (GGDA_CONFIG_SERVICE_10_04_SUPPORT == GGDA_CONFIG_ON)
  /* Pre-compile configuration shows that service 0x10 04 shall be supported, 
   * but no link-time cofiguration allows it!!! */
  GgdaAssert((context1004 != kGgdaNumContexts), kGgdaAssertInvalidConfiguration);
#  else
  /* Pre-compile configuration shows that service 0x10 04 will not be supported, 
   * but a link-time cofiguration allows it!!! */
  GgdaAssert((context1004 == kGgdaNumContexts), kGgdaAssertInvalidConfiguration);
#  endif
# else
  /* Pre-compile configuration shows that no sub-function of service 0x10 will be supported, 
   * but a link-time cofiguration allows at least one of its sub-functions!!! */
  GgdaAssert((context1002 == kGgdaNumContexts), kGgdaAssertInvalidConfiguration);
  GgdaAssert((context1004 == kGgdaNumContexts), kGgdaAssertInvalidConfiguration);
# endif

# if (GGDA_CONFIG_SERVICE_A5_02_SUPPORT == GGDA_CONFIG_ON)
#  if !defined (NM_ENABLE_HISPEED_MODE)
  /* Pre-compile configuration shows that service 0xA5 02 shall be supported,
   * but hi-speed mode is not supported by the comm layer */
#   error "Hi Speed mode is not supported by comm layer (NM_ENABLE_HISPEED_MODE not defined)"
#  endif
  /* Pre-compile configuration shows that service 0xA5 02 shall be supported, 
   * but no link-time cofiguration allows it!!! */
  GgdaAssert((contextA502 != kGgdaNumContexts), kGgdaAssertInvalidConfiguration);
# else
  /* Pre-compile configuration shows that service 0xA5 02 will be supported, 
   * but a link-time cofiguration allows it!!! */
  GgdaAssert((contextA502 == kGgdaNumContexts), kGgdaAssertInvalidConfiguration);
# endif
}
#endif

#if (GGDA_CONFIG_DEBUG == GGDA_CONFIG_ON)
/*  ********************************************************************************
 * Function name:GgdaFatalError
 * Description: Internal assert
 * Returns:  
 * Parameter(s): line number, error code
 * Particularitie(s) and limitation(s):none
 ********************************************************************************  */
static void GgdaFatalError(vuint32 line, vuint8 error)
{
  GGDA_IGNORE_UNREF_PARAM(line)
  GGDA_IGNORE_UNREF_PARAM(error)
  for (;;)
  {
    /* loop endlessly */
  }
}
#endif
/*  ********************************************************************************
 * Function name:GgdaSetEvent
 * Description: Sets event(s)
 * Returns:  
 * Parameter(s): context index, event(s)
 * Particularitie(s) and limitation(s):none
 ********************************************************************************  */
static void GgdaSetEvent(GgdaContextIndexType context, GgdaEventType ev)
{
  CanInterruptDisable();
  ggdaContexts[context].eventRegister |= ev;
  CanInterruptRestore();
}

/*  ********************************************************************************
 * Function name:GgdaClearEvent
 * Description: Clears event(s)
 * Returns:  
 * Parameter(s): context index, event(s)
 * Particularitie(s) and limitation(s):none
 ********************************************************************************  */
static void GgdaClearEvent(GgdaContextIndexType context, GgdaEventType ev)
{
  CanInterruptDisable();
  /* Clear event */
  ggdaContexts[context].eventRegister &= (GgdaEventType)(~ev);
  CanInterruptRestore();
}

/*  ********************************************************************************
 * Function name:GgdaActivateTimer
 * Description: Starts a timer if it is not started yet
 * Returns:  
 * Parameter(s): context index, timer handle
 * Particularitie(s) and limitation(s):none
 ********************************************************************************  */
static void GgdaActivateTimer(GgdaContextIndexType context, GgdaTimerHandle timer)
{
  CanInterruptDisable();
  if(ggdaContexts[context].timers[timer] == 0)
  {
    ggdaContexts[context].numActiveTimers++;
    ggdaContexts[context].timers[timer] = ggdaTimerValues[timer].loadValue;
  }
  CanInterruptRestore();
}

/*  ********************************************************************************
 * Function name:GgdaReactivateTimer
 * Description: Restarts a timer (independently if it has been already started or not).
 * Returns:  
 * Parameter(s): context index, timer handle
 * Particularitie(s) and limitation(s):none
 ********************************************************************************  */
static void GgdaReactivateTimer(GgdaContextIndexType context, GgdaTimerHandle timer)
{
  CanInterruptDisable();
  if(ggdaContexts[context].timers[timer] == 0)
  {
    ggdaContexts[context].numActiveTimers++;
  }
  ggdaContexts[context].timers[timer] = ggdaTimerValues[timer].reloadValue;
  CanInterruptRestore();
}

/*  ********************************************************************************
 * Function name:GgdaRefreshTimer
 * Description: Restarts a timer if already active
 * Returns:  
 * Parameter(s): context index, timer handle
 * Particularitie(s) and limitation(s):none
 ********************************************************************************  */
static void GgdaRefreshTimer(GgdaContextIndexType context, GgdaTimerHandle timer)
{
  CanInterruptDisable();
  if(ggdaContexts[context].timers[timer] != 0)
  {
    ggdaContexts[context].timers[timer] = ggdaTimerValues[timer].loadValue;
  }
  CanInterruptRestore();
}

/*  ********************************************************************************
 * Function name:GgdaDeactivateTimer
 * Description: Stops a timer
 * Returns:  
 * Parameter(s): context index, timer handle
 * Particularitie(s) and limitation(s):none
 ********************************************************************************  */
static void GgdaDeactivateTimer(GgdaContextIndexType context, GgdaTimerHandle timer)
{
  CanInterruptDisable();
  if((ggdaContexts[context].timers[timer] != 0) &&
     (ggdaContexts[context].numActiveTimers != 0))
  {
    ggdaContexts[context].numActiveTimers--;
  }
  ggdaContexts[context].timers[timer] = 0;
  CanInterruptRestore();
}

#if defined (VGEN_CONFIG_VSTDLIB) || defined (V_CONFIG_VSTDLIB)
/* Used STDLIB utility */
#else
/*******************************************************************************
* NAME:              GgdaMemCopy
*
* CALLED BY:         Internal GGDA function
* PRECONDITIONS:     
*
* DESCRIPTION:       Copies a RAM data block to another RAM data block
*
*******************************************************************************/
static void GgdaMemCopy(vuint8* tgtAddr, const vuint8* const srcAddr, vuintx len)
{
  while(len != (vuintx)0)
  {
    len--;
    tgtAddr[len] = srcAddr[len];
  }
}
#endif

/*******************************************************************************
* NAME:              GgdaCopyFromCan
*
* CALLED BY:         Internal GGDA function
* PRECONDITIONS:     
*
* DESCRIPTION:       Copies CAN message data into RAM buffer
*
*******************************************************************************/
static void GgdaCopyFromCan(vuint8* tgtAddr, CanChipDataPtr srcAddr, vuintx len)
{
  while (len != (vuintx)0)
  {
    len--;
    tgtAddr[len] = srcAddr[len];
  }
}

/*******************************************************************************
* NAME:              GgdaInitPowerOn
*
* CALLED BY:         Application
* PRECONDITIONS:     
*
* DESCRIPTION:       Initializes the module at PowerOn time.
*
*******************************************************************************/
void GgdaInitPowerOn(void)
{
  GgdaContextIndexType context = kGgdaNumContexts;

  /* State machine init */
  while (context != 0)
  {
    context--;

    ggdaContexts[context].stateMachine.isUsdtBufferLocked   = 0;
    ggdaContexts[context].stateMachine.isDiagActive         = 0;
    ggdaContexts[context].stateMachine.isResActive          = 0;
    ggdaContexts[context].stateMachine.isCommHalted         = 0;
    ggdaContexts[context].stateMachine.progMode             = kGgdaProgModeNone;

    ggdaContexts[context].stateMachine.isTxModeActivity     = kGgdaUsdtTxModeResNone;
    ggdaContexts[context].stateMachine.isRxModeActive       = 0;

    /* Timer init */
    ggdaContexts[context].numActiveTimers             = 0;
    ggdaContexts[context].timers[GGDA_TIMER_S1]       = 0;
    ggdaContexts[context].timers[GGDA_TIMER_P2]       = 0;
    ggdaContexts[context].timers[GGDA_TIMER_VN]       = 0;
#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
    ggdaContexts[context].timers[GGDA_TIMER_UUDT_CONF]= 0;
#endif

    ggdaContexts[context].eventRegister = 0;

    /* RCR-RP Buffer init */
    ggdaContexts[context].rcrRpBuffer[0] = 0x7F;
    ggdaContexts[context].rcrRpBuffer[2] = (vuint8)kGgdaNrcResponsePending;

#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
    /* A9 init */
    /* init the state machine here to have defined state at startup */
    ggdaContexts[context].rdiStateCtrl.is81ModeActive     = 0;
    ggdaContexts[context].rdiStateCtrl.isFirstAnswer      = 0;
    ggdaContexts[context].rdiStateCtrl.answerMode         = 0;
    ggdaContexts[context].rdiStateCtrl.isLastDtcFound     = 0;
    ggdaContexts[context].rdiStateCtrl.isUudtBufferLocked = 0;
    /* make it before initializing the state machine */
#if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
    ggdaContexts[context].rdiStateCtrl.is82ModeActive     = 0;
    /* deactivate the 0xA9 82 service */
    GgdaRdiDeactivateOnChangeDtcCount(context);
    /* prepare the response - here will be always 0x82 */
    ggdaContexts[context].uudtSecBuffer[0] = 0x82;
#endif
    /* init the state machine */
    ggdaContexts[context].nextMode = kGgdaRdiMode80;
#endif

    /* Validate configuration settings */
    GgdaValidateConfiguration();

#if defined (TP_CONFIG_DYNAMIC_CHANNELS)
# error "Dynamic TP not supported. Please use a static TP configuration"
#endif
  }
}
/*******************************************************************************
* NAME:              GgdaTimerTask
*
* CALLED BY:         Application
* PRECONDITIONS:     
*
* DESCRIPTION:       Timer's task.
*
*******************************************************************************/
void GgdaTimerTask(void)
{
  GgdaContextIndexType context = kGgdaNumContexts;

  while (context != 0)
  {
    GgdaTimerEventType   tmrTo   = 0;

    context--;
    if(ggdaContexts[context].numActiveTimers != 0)
    {
      GgdaTimerEventType tmrShift = (GgdaTimerEventType)(0x01 << (GGDA_NUM_TIMERS - 1));
      vuintx iter = GGDA_NUM_TIMERS;

      /* enter critical section */
      CanInterruptDisable();
      while(iter != 0)
      {
        iter--;
        if(ggdaContexts[context].timers[iter] != 0)
        {
          ggdaContexts[context].timers[iter]--;
          if(ggdaContexts[context].timers[iter] == 0)
          {
            /* Unregister timer */
            ggdaContexts[context].numActiveTimers--;
            /* Set timeout */
            tmrTo |= tmrShift;
          }
        }
        tmrShift>>=1;
      }
      /* leave critical section */
      CanInterruptRestore();
    }

    /* At least one timeout? */
    if(tmrTo != 0)
    {
      vuintx iter = 0;
      do
      {
        /* check for timeout */
        if((tmrTo & 0x01) != 0)
        {
          switch(iter)
          {
            /*------------------------*/
            case GGDA_TIMER_S1:
            /*------------------------*/
              if(ggdaContexts[context].stateMachine.progMode != kGgdaProgModeActive)
              {
                /* send unsolicited response */
                GgdaSetEvent(context, GGDA_EV_SEND_UNSOL_RES);
              }

              /* Reset states */
              GgdaOnStopSession(context);
              break;
            /*------------------------*/
            case GGDA_TIMER_P2:
            /*------------------------*/
              /* Reload */
              GgdaReactivateTimer(context, GGDA_TIMER_P2);
              GgdaSetEvent(context, GGDA_EV_SEND_RCR_RP_RES);
              break;

            /*------------------------*/
            case GGDA_TIMER_VN:
            /*------------------------*/
              ggdaContexts[context].stateMachine.isDiagActive = 0;
              (void)IlNwmDeactivateVN(ggdaCanConfig[context].canChannel, VN_Diagnostics);
              break;
#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
            /*------------------------*/
            case GGDA_TIMER_UUDT_CONF:
            /*------------------------*/
              CanInterruptDisable();
              /* No confirmation up to now - ignore the transmission */
              CanCancelTransmit(ggdaCanConfig[context].uudtResMsgHandle);
              GgdaUudtConfirmation(ggdaCanConfig[context].uudtResMsgHandle);

              CanInterruptRestore();
              break;
#endif
            default:
              /* Shall not land here - but if so - do nothing.*/
              break;
          }
        }
        iter++;
        /* Get next timer */
        tmrTo >>=1;
      }
      while(tmrTo != 0);
    }
  }
}

#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
/*******************************************************************************
* NAME:              GgdaRdiRxTask
*
* CALLED BY:         GGDA
* PRECONDITIONS:     
*
* DESCRIPTION:       RDI RX task
*
*******************************************************************************/
static void GgdaRdiRxTask(GgdaContextIndexType context, GgdaEventType ev)
{
# if (GGDA_CONFIG_SERVICE_A9_80_SUPPORT == GGDA_CONFIG_ON)
  if((ev & GGDA_EV_RX_A9_80) != 0)
  {
    /* send the DTC number and the FTB */
    vuint16 DTCNr =   ((vuint16) ggdaContexts[context].uudtPrimBuffer[1] << 8)
                     | (vuint16) ggdaContexts[context].uudtPrimBuffer[2];
    ApplGgdaGetDtcStatusByNumber(context, DTCNr, ggdaContexts[context].uudtPrimBuffer[3]);
  }
#endif

  if((ev & GGDA_EV_RX_A9_81) != 0)
  {
    /* Send the response buffer, and the searched mask */
    ApplGgdaGetDtcStatusByMask(context,
                               ggdaContexts[context].nextIterPos,
                               ggdaContexts[context].rdi81SearchStatusMask);
  }

#if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
  if((ev & GGDA_EV_RX_A9_82) != 0)
  {
    /* start the DTC on count change algorithm */
    ApplGgdaEnableOnChangeDtcCount(context, ggdaContexts[context].rdi82SearchStatusMask);
    /* set tha OnDTCCountChange is active so in case of timeout only the application
     *  to be called to cancel the change monitoring algo */
    ggdaContexts[context].rdiStateCtrl.is82ModeActive = 1;
  }
#endif
}
#endif

#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
/*******************************************************************************
* NAME:              GgdaRdiTxTask
*
* CALLED BY:         GGDA
* PRECONDITIONS:     Response is requested
*                    -> ggdaContexts[context].rdiStateCtrl.answerMode != 0 
*
* DESCRIPTION:       RDI TX task
*
*******************************************************************************/
static void GgdaRdiTxTask(GgdaContextIndexType context)
{
  /*--------------------------*/
  /*            Tx            */
  /*--------------------------*/
  /* if the UUDT msg is free */
  if(ggdaContexts[context].rdiStateCtrl.isUudtBufferLocked == 0)
  {
    /* temporary buffer for parallel transmission of UUDTs */
    DescMsg curUudtBuffer;

    CanInterruptDisable();
    ggdaContexts[context].rdiStateCtrl.isUudtBufferLocked = 1;
    CanInterruptRestore();

    /* find the next - in this way the parallel confirmations are solved */
    while ((ggdaContexts[context].rdiStateCtrl.answerMode & ggdaContexts[context].nextMode) == 0)
    {
      /* find the next confirmed mode with wrap around */
      if((vuint8)(ggdaContexts[context].nextMode & kGgdaRdiLastMode) != 0)
      {
        ggdaContexts[context].nextMode = kGgdaRdiMode80;
      }
      else
      {
        ggdaContexts[context].nextMode <<=1;
      }
    }
#if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
    /* assign the response buffer */
    if((ggdaContexts[context].nextMode & kGgdaRdiMode82) != 0)
    {
      /* set the buffer and send just the response */
      curUudtBuffer = &ggdaContexts[context].uudtSecBuffer[0];
    }
    else
#endif
    {
      /* set the buffer and send just the response */
      curUudtBuffer = &ggdaContexts[context].uudtPrimBuffer[0];
    }

    /* clear the coresponding confirmation flag */
    ggdaContexts[context].rdiStateCtrl.answerMode &= (vbittype)~ggdaContexts[context].nextMode;

    /* if that was the first UUDT response for the current 
    *  type of response - free the diagnostic layer */
    if((ggdaContexts[context].rdiStateCtrl.isFirstAnswer & ggdaContexts[context].nextMode) != 0)
    {
      ggdaContexts[context].rdiStateCtrl.isFirstAnswer &= (vbittype)~ggdaContexts[context].nextMode;
#if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
      if((ggdaContexts[context].nextMode & kGgdaRdiMode82) != 0)
      {
        /* 0x82 starts start the S1 timer */
        GgdaActivateTimer(context, GGDA_TIMER_S1);
      }
#endif
      GgdaProcessingDone(context);
    }

    /* shift with wrap around (make it before the CanTransmit so the confirmation each time
     * to have the next awaiting mode)*/
    if((ggdaContexts[context].nextMode & kGgdaRdiLastMode) != 0)
    {
      ggdaContexts[context].nextMode = kGgdaRdiMode80;
    }
    else
    {
      ggdaContexts[context].nextMode <<=1;
    }

    /*---------------------------------*/
    /*        send the response        */
    /*---------------------------------*/
    /* copy the data on the response buffer */
    GgdaMemCopy(CanGetTxDataPtr(ggdaCanConfig[context].uudtResMsgHandle), curUudtBuffer, (vuintx)kGgdaSvcA9BufferLen);
    /* Try transmit */
    GgdaActivateTimer(context, GGDA_TIMER_UUDT_CONF);
# if defined (C_CONFIG_TRANSMIT_QUEUE)
    /* Always ok */
    (void)CanTransmit(GgdaCanConfig[context].uudtResMsgHandle);
# else
    {
      /* MISRA requires temporal variable */
      vuint8 result;
      result = CanTransmit(ggdaCanConfig[context].uudtResMsgHandle);
      if(result != kCanTxOk)
      {
        /* set the retry bit */
        GgdaSetEvent(context, GGDA_EV_RESEND_MSG);
      }
    }
# endif
  }
}
#endif

/*******************************************************************************
* NAME:              GgdaStateTask
*
* CALLED BY:         Application
* PRECONDITIONS:     
*
* DESCRIPTION:       Processing task
*
*******************************************************************************/
void GgdaStateTask(void)
{
  GgdaContextIndexType context = kGgdaNumContexts;

  while (context != 0)
  {
    GgdaEventType ev;
    context--;

    ev = ggdaContexts[context].eventRegister;

    if(ev != 0)
    {
      GgdaClearEvent(context, ev);

#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
      if((ev & GGDA_EV_RX_A9_8X) != 0)
      {
        GgdaRdiRxTask(context, ev);
      }

# if defined (C_CONFIG_TRANSMIT_QUEUE)
      /* Do not retry */
# else
      if((ev & GGDA_EV_RESEND_MSG) != 0)
      {
        vuint8 result;
        result = CanTransmit(ggdaCanConfig[context].uudtResMsgHandle);
        if(result != kCanTxOk)
        {
          GgdaSetEvent(context, GGDA_EV_RESEND_MSG);
        }
      }
# endif
#endif

      if((ev & GGDA_EV_ACTIVATE_VN) != 0)
      {
        /* Check VN */
        if(ggdaContexts[context].stateMachine.isDiagActive == 0)
        {
          ggdaContexts[context].stateMachine.isDiagActive = 1;

          (void)IlNwmActivateVN(ggdaCanConfig[context].canChannel, VN_Diagnostics);
        }
      }

      if((ev & GGDA_EV_NEW_REQ) != 0)
      {
        /* Start P2 */
        GgdaActivateTimer(context, GGDA_TIMER_P2);
        /* Prepare RCR-RP */
        ggdaContexts[context].rcrRpBuffer[1] = ggdaContexts[context].diagBuffer[0];

        if(ggdaContexts[context].dataLength == 0)
        {
          /* Suppress any response just ignore this request */
          ggdaContexts[context].stateMachine.isResActive = 0;
          /* Force only one frame copy */
          ggdaContexts[context].errorRegister = kGgdaNrcServiceNotSupported;
          GgdaProcessingDone(context);
        }
        else
        {
          /* By default always use responses */
          ggdaContexts[context].stateMachine.isResActive = 1;

          if(ggdaContexts[context].dataLength > kGgdaDiagBufferSize)
          {
            /* Force only one frame copy */
            ggdaContexts[context].errorRegister = kGgdaNrcInvalidFormat;
            GgdaProcessingDone(context);
          }
          else
          {
            /* Data length without SID */
            ggdaContexts[context].dataLength--;
            ggdaContexts[context].errorRegister = kGgdaNrcNone;

            switch(ggdaContexts[context].diagBuffer[0])
            {
#if (GGDA_CONFIG_SERVICE_10_XX_SUPPORT == GGDA_CONFIG_ON)
            case 0x10u:/* Initiate Diagnostic Operation */
              GgdaProcessInitiateDiagnosticOperation(context);
              break;
#endif
            case 0x1Au:/* Read ECU ID */
              GgdaProcessReadEcuId(context);
              break;
            case 0x20u:/* Return to normal mode */
              GgdaProcessReturnToNormalMode(context);
              break;
            case 0x28u:/* Disable normal comm */
              GgdaProcessDisableNormalComm(context);
              break;
            case 0x3Eu:/* TesterPresent */
              GgdaProcessTesterPresent(context);
              break;
            case 0xA5u:/* Enter Programming mode */
              GgdaProcessEnterProgrammingMode(context);
              break;
#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
            case 0xA9u:/* Read DTC Info */
              GgdaProcessReadDtcInfo(context);
              break;
#endif
            default:
              /* Ilegal service */
              ggdaContexts[context].errorRegister = kGgdaNrcServiceNotSupported;
              GgdaProcessingDone(context);
            }
          }/* No buffer overrun */
        }/* Non-zero length */
      }

      if((ev & GGDA_EV_SEND_UNSOL_RES) != 0)
      {
        /* Currenlty only SF responses alowed so not TxModeActive needed */
        if(ggdaContexts[context].stateMachine.isRxModeActive == 0)
        {
          /* Pointer to const can cause problems on some platforms, so RAM variable used here */
          static vuint8 unsolicitedReponse = 0x60;
          vuintx result;

          result = GgdaUsdtTransmit(context, kGgdaUsdtTxModeResUnsol, &unsolicitedReponse, 1);
          if(result != (vuintx)0)
          {
            GgdaSetEvent(context, GGDA_EV_SEND_UNSOL_RES);
          }
        }
        else
        {
          GgdaSetEvent(context, GGDA_EV_SEND_UNSOL_RES);
        }
      }

      if((ev & GGDA_EV_SEND_RCR_RP_RES) != 0)
      {
        vuintx result;
        result = GgdaUsdtTransmit(context, kGgdaUsdtTxModeResRcrRp, ggdaContexts[context].rcrRpBuffer, kGgdaRcrRpBufferSize);
        if(result != (vuintx)0)
        {
          GgdaSetEvent(context, GGDA_EV_SEND_RCR_RP_RES);
        }
      }

      if((ev & GGDA_EV_SEND_FINAL_RES) != 0)
      {
        vuintx result;
        result = GgdaUsdtTransmit(context, kGgdaUsdtTxModeResFinal, ggdaContexts[context].diagBuffer, ggdaContexts[context].dataLength);
        if(result != (vuintx)0)
        {
          GgdaSetEvent(context, GGDA_EV_SEND_FINAL_RES);
        }
      }
    }

#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
    /* No event management since cycle mode necessary (equal prio) */
    if((ggdaContexts[context].rdiStateCtrl.answerMode & kGgdaRdiModeMask) != 0)
    {
      GgdaRdiTxTask(context);
    }
#endif
  }
}

/*******************************************************************************
* NAME:              GgdaOnStopSession
*
* CALLED BY:         GGDA
* PRECONDITIONS:     
*
* DESCRIPTION:       Common action when the diagnostic session is stopped.
*
*******************************************************************************/
static void GgdaOnStopSession(GgdaContextIndexType context)
{
  /* Stop and prepare for next usage of Tester present timer (for service 0x20) */
  GgdaDeactivateTimer(context, GGDA_TIMER_S1);
  /* Start the VN timer (for timeout S1) */
  GgdaReactivateTimer(context, GGDA_TIMER_VN);

  /* Init the predefined diagnostic states */
  /* Restore communication */
  ggdaContexts[context].stateMachine.isCommHalted = 0;

  IlNwmReturnToNormalMode(ggdaCanConfig[context].canChannel);

  /* Notify the application */
  ApplGgdaOnReturnToNormalMode(context);
#if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
  /* Deactivate the 0xA9 82 service */
  GgdaRdiDeactivateOnChangeDtcCount(context);
#endif

  /* If return to normal mode from Programming state - make ECU reset */
  if(ggdaContexts[context].stateMachine.progMode == kGgdaProgModeActive)
  {
    /* make it as last in case of application delay (up to 150ms) 
     * Shall be used as a immediate RESET or event if the application 
     * has something to save 
     */
    ApplGgdaForceEcuReset();
  }
  /* Programming mode reset here because the current information is needed
   * by the application to determine if software reset is necessary or not 
   * in the ApplGgdaOnReturnToNormalMode() callback.
   */
  ggdaContexts[context].stateMachine.progMode = kGgdaProgModeNone;
}

/*******************************************************************************
* NAME:              GgdaProcessingDone
*
* CALLED BY:         GGDA
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
static void GgdaProcessingDone(GgdaContextIndexType context)
{
  GgdaDeactivateTimer(context, GGDA_TIMER_P2);
  if(ggdaContexts[context].stateMachine.isResActive != 0)
  {
    if(ggdaContexts[context].errorRegister != kGgdaNrcNone)
    {
      /* Negative response */
      ggdaContexts[context].diagBuffer[1] = ggdaContexts[context].diagBuffer[0];
      ggdaContexts[context].diagBuffer[0] = 0x7F;
      ggdaContexts[context].diagBuffer[2] = (vuint8)ggdaContexts[context].errorRegister;
      ggdaContexts[context].dataLength = 3;

      if ( (ggdaContexts[context].stateMachine.isFuncReq != 0)
        && (ggdaContexts[context].errorRegister == kGgdaNrcServiceNotSupported) )
      {
        /* Simulate response */
        GgdaPostProcessing(context);
      }
      else
      {
        GgdaSetEvent(context, GGDA_EV_SEND_FINAL_RES);
      }
    }
    else
    {
      /* Positive response */
      ggdaContexts[context].diagBuffer[0]+= 0x40;
      ggdaContexts[context].dataLength++;
      GgdaSetEvent(context, GGDA_EV_SEND_FINAL_RES);
    }
  }
  else
  {
    /* Simulate response */
    GgdaPostProcessing(context);
  }
}


/*******************************************************************************
* NAME:              GgdaPostProcessing
*
* CALLED BY:         GGDA
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
static void GgdaPostProcessing(GgdaContextIndexType context)
{
  GgdaReactivateTimer(context, GGDA_TIMER_VN);
  ggdaContexts[context].stateMachine.isUsdtBufferLocked = 0;
}

/*******************************************************************************
DIAG processors
*******************************************************************************/

#if (GGDA_CONFIG_SERVICE_10_XX_SUPPORT == GGDA_CONFIG_ON)
/*******************************************************************************
* NAME:              GgdaProcessInitiateDiagnosticOperation
*
* CALLED BY:         GGDA
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
static void GgdaProcessInitiateDiagnosticOperation(GgdaContextIndexType context)
{
  /* Service supported? */
  if ((ggdaCanConfig[context].optionalModes & kGgdaEnableMode10xx) != 0)
  {
    if(ggdaContexts[context].dataLength == 1)
    {
      vuintx processedRequest = 0;

      switch(ggdaContexts[context].diagBuffer[1])
      {
# if (GGDA_CONFIG_SERVICE_10_02_SUPPORT == GGDA_CONFIG_ON)
        case 0x02u:
          if ((ggdaCanConfig[context].optionalModes & kGgdaEnableMode1002) != 0)
          {
            ApplGgdaOnDisableAllDtc();
            GgdaActivateTimer(context, GGDA_TIMER_S1);
            processedRequest = 1;
          }
          break;
# endif
# if (GGDA_CONFIG_SERVICE_10_04_SUPPORT == GGDA_CONFIG_ON)
        case 0x04u:
          if ((ggdaCanConfig[context].optionalModes & kGgdaEnableMode1004) != 0)
          {
            ApplGgdaOnWakeUpLink();
            /* ESCAN00047411: Do not activate S1 timer */
            processedRequest = 1;
          }
          break;
# endif
        default:break;
      }

      if (processedRequest == 0)
      {
        ggdaContexts[context].errorRegister = kGgdaNrcSubfunctionNotSupported;
      }
    }
    else
    {
      ggdaContexts[context].errorRegister = kGgdaNrcInvalidFormat;
    }
  }
  else
  {
    ggdaContexts[context].errorRegister = kGgdaNrcServiceNotSupported;
  }
  /* No data, -no subfunction!- to be sent */
  ggdaContexts[context].dataLength = 0;
  /* Finish the processing */
  GgdaProcessingDone(context);
}
#endif

/*******************************************************************************
* NAME:              GgdaProcessReturnToNormalMode
*
* CALLED BY:         GGDA
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
static void GgdaProcessReturnToNormalMode(GgdaContextIndexType context)
{
  if(ggdaContexts[context].dataLength == 0)
  {
    /* Check the current programming mode */
    if(ggdaContexts[context].stateMachine.progMode == kGgdaProgModeActive)
    {
      ggdaContexts[context].stateMachine.isResActive = 0;
    }

    GgdaOnStopSession(context);
  }
  else
  {
    ggdaContexts[context].errorRegister = kGgdaNrcInvalidFormat;
  }
  /* No data to be sent */
  /* ggdaDataLength = 0;*/
  /* Finish the processing */
  GgdaProcessingDone(context);
}

/*******************************************************************************
* NAME:              GgdaProcessDisableNormalComm
*
* CALLED BY:         GGDA
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
static void GgdaProcessDisableNormalComm(GgdaContextIndexType context)
{
  if(ggdaContexts[context].dataLength == 0)
  {
    Nm_Status result = IlNwmNormalCommHalted(ggdaCanConfig[context].canChannel);

    if(result != NM_OK)
    {
      ggdaContexts[context].errorRegister = kDescNrcConditionsNotCorrect;
    }
    else
    {
      /* set the flag for communication disabled */
      ggdaContexts[context].stateMachine.isCommHalted = 1;
  
      /* Notify the application */
      ApplGgdaOnDisableNormalComm(context);
      /* activate timer monitoring */
      GgdaActivateTimer(context, GGDA_TIMER_S1);
    }
  }
  else
  {
    ggdaContexts[context].errorRegister = kGgdaNrcInvalidFormat;
  }

  /* No data to be sent */
  /* ggdaDataLength = 0;*/
  /* Finish the processing */
  GgdaProcessingDone(context);
}

/*******************************************************************************
* NAME:              GgdaProcessReadEcuId
*
* CALLED BY:         GGDA
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
static void GgdaProcessReadEcuId(GgdaContextIndexType context)
{
  if(ggdaContexts[context].dataLength == 1)
  {
    if(ggdaContexts[context].diagBuffer[1] == 0xB0)
    {
      /* Store ECU address */
      ggdaContexts[context].diagBuffer[2] = kGgdaEcuNumber;
    }
    else
    {
      ggdaContexts[context].errorRegister = kGgdaNrcRequestOutOfRange;
    }
  }
  else
  {
    ggdaContexts[context].errorRegister = kGgdaNrcInvalidFormat;
  }

  /* 2 data bytes to be sent */
  ggdaContexts[context].dataLength = 2;
  /* Finish the processing */
  GgdaProcessingDone(context);
}

/*******************************************************************************
* NAME:              GgdaProcessTesterPresent
*
* CALLED BY:         GGDA
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
static void GgdaProcessTesterPresent(GgdaContextIndexType context)
{
  if(ggdaContexts[context].dataLength == 0)
  {
    /* Just restart (if running) */
    GgdaRefreshTimer(context, GGDA_TIMER_S1);
  }
  else
  {
    ggdaContexts[context].errorRegister = kGgdaNrcInvalidFormat;
  }
  /* No data to be sent */
  /* ggdaDataLength = 0;*/
  /* Finish the processing */
  GgdaProcessingDone(context);
}

/*******************************************************************************
* NAME:              GgdaProcessEnterProgrammingMode
*
* CALLED BY:         GGDA
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
static void GgdaProcessEnterProgrammingMode(GgdaContextIndexType context)
{
  if (ggdaContexts[context].dataLength == 1)
  {
    /*************************
    Do precondition check
    *************************/
    /* check if the normal communication was disabled and application is ready to enter in programming mode */
    if (ggdaContexts[context].stateMachine.progMode != kGgdaProgModeActive)
    {
      /* check which sub-function was requested */
      switch(ggdaContexts[context].diagBuffer[1])
      {
        /******************************
        RequestProgrammingMode 
        ******************************/
        case 0x01u:
          if (ggdaContexts[context].stateMachine.isCommHalted == 0)
          {
            ggdaContexts[context].errorRegister = kGgdaNrcConditionsNotCorrect;
          }
          else
          {
            vuint8 result;
            result = ApplGgdaMayEnterProgMode(context);
            if (result != kDescOk)
            {
              ggdaContexts[context].errorRegister = kGgdaNrcConditionsNotCorrect;
            }
            else
            {
              /* Update programming state */
              ggdaContexts[context].stateMachine.progMode = kGgdaProgModeAcceptedLS;
            }
          }
          break;
#if (GGDA_CONFIG_SERVICE_A5_02_SUPPORT == GGDA_CONFIG_ON)
        /******************************
        RequestProgrammingModeHighSpeed 
        ******************************/
        case 0x02u:
          if ((ggdaCanConfig[context].optionalModes & kGgdaEnableModeA502) != 0)
          {
            if(ggdaContexts[context].stateMachine.isCommHalted == 0)
            {
              ggdaContexts[context].errorRegister = kGgdaNrcConditionsNotCorrect;
            }
            else
            {
              vuint8 result;
              result = ApplGgdaMayEnterHiSpeedProgMode(context);
              if (result != kDescOk)
              {
                ggdaContexts[context].errorRegister = kGgdaNrcConditionsNotCorrect;
              }
              else
              {
                /* Update programming state */
                ggdaContexts[context].stateMachine.progMode = kGgdaProgModeAcceptedHS;
              }
            }
          }
          else
          {
            ggdaContexts[context].errorRegister = kGgdaNrcSubfunctionNotSupported;
          }
          break;
#endif
        /******************************
        EnableProgrammingMode
        ******************************/
        case 0x03u:
          /* If not accepted yet - reject */
          if((ggdaContexts[context].stateMachine.progMode == kGgdaProgModeAcceptedLS)
#if (GGDA_CONFIG_SERVICE_A5_02_SUPPORT == GGDA_CONFIG_ON)
            ||(ggdaContexts[context].stateMachine.progMode == kGgdaProgModeAcceptedHS)
#endif
            )
          {
            /* Disable positive response on this request */
            ggdaContexts[context].stateMachine.isResActive = 0;

#if (GGDA_CONFIG_SERVICE_A5_02_SUPPORT == GGDA_CONFIG_ON)
            /* The return value is not checked, because there are 2 cases that can 
             * cause error setting this mode and which are excluded here:
             * 1. NormalComm is active - impossible because of the checks in 0xA5 01/02
             * 2. EnterSleepMode - impossible - VN_Diagnostics is active still. 
             */
            if(ggdaContexts[context].stateMachine.progMode == kGgdaProgModeAcceptedHS)
            {
              (void)IlNwmSetHispeedMode(ggdaCanConfig[context].canChannel);
            }
#endif
            /* Set programming mode */
            ggdaContexts[context].stateMachine.progMode = kGgdaProgModeActive;
          }
          else
          {
            ggdaContexts[context].errorRegister = kGgdaNrcConditionsNotCorrect;
          }
          break;
        /******************************
        InvalidSubfunction
        ******************************/
        default:/* Not supported parameter */
          if(ggdaContexts[context].stateMachine.progMode != kGgdaProgModeNone)
          {
            /* If in accepted LS or HS - reset prog mode (active is already checked at the beginning) */
            /* reset programming mode */
            ggdaContexts[context].stateMachine.progMode = kGgdaProgModeNone;
          }
          /* Force negative response */
          ggdaContexts[context].errorRegister = kGgdaNrcSubfunctionNotSupported;
          break;
      }
    }
    else
    {
      ggdaContexts[context].errorRegister = kGgdaNrcConditionsNotCorrect;
    }
  }
  else
  {
    ggdaContexts[context].errorRegister = kGgdaNrcInvalidFormat;
  }

  /* Handle the response */
  ggdaContexts[context].dataLength = 0;
  GgdaProcessingDone(context);
}

#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
/*******************************************************************************
* NAME:              GgdaProcessReadDtcInfo
*
* CALLED BY:         GGDA
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
static void GgdaProcessReadDtcInfo(GgdaContextIndexType context)
{
  if ((ggdaCanConfig[context].optionalModes & kGgdaEnableModeA9xx) != 0)
  {
    if(ggdaContexts[context].dataLength > 1)
    {
      /* Format and condition pre-checks */
      switch(ggdaContexts[context].diagBuffer[1])
      {
# if (GGDA_CONFIG_SERVICE_A9_80_SUPPORT == GGDA_CONFIG_ON)
      case 0x80u:
        if ((ggdaCanConfig[context].optionalModes & kGgdaEnableModeA980) != 0)
        {
          if(ggdaContexts[context].dataLength != 4)
          {
            ggdaContexts[context].errorRegister = kGgdaNrcInvalidFormat;
          }
          else
          {
            if(ggdaContexts[context].rdiStateCtrl.is81ModeActive != 0)
            {
              ggdaContexts[context].errorRegister = kGgdaNrcConditionsNotCorrect;
            }
            else
            {
              /* send no response by default */
              ggdaContexts[context].stateMachine.isResActive = 0;
              /* set request is received */
              GgdaSetEvent(context, GGDA_EV_RX_A9_80);
              /* compose the response */
              ggdaContexts[context].uudtPrimBuffer[0] = 0x80;
              ggdaContexts[context].uudtPrimBuffer[1] = ggdaContexts[context].diagBuffer[2];
              ggdaContexts[context].uudtPrimBuffer[2] = ggdaContexts[context].diagBuffer[3];
              ggdaContexts[context].uudtPrimBuffer[3] = ggdaContexts[context].diagBuffer[4];
              /* set that this was the first request */
              ggdaContexts[context].rdiStateCtrl.isFirstAnswer |= kGgdaRdiMode80;
            }
          }
        }
        else
        {
          ggdaContexts[context].errorRegister = kGgdaNrcSubfunctionNotSupported;
        }
        break;
#endif

      case 0x81u:
        if(ggdaContexts[context].dataLength != 2)
        {
          ggdaContexts[context].errorRegister = kGgdaNrcInvalidFormat;
        }
        else
        {
          if(ggdaContexts[context].rdiStateCtrl.is81ModeActive != 0)
          {
            ggdaContexts[context].errorRegister = kGgdaNrcConditionsNotCorrect;
          }
          else
          {
            /* send no response by default */
            ggdaContexts[context].stateMachine.isResActive = 0;
            /* Set the current mode that is 81 */
            ggdaContexts[context].rdiStateCtrl.is81ModeActive = 1;
            /* set the mask to be asked for */
            ggdaContexts[context].rdi81SearchStatusMask = ggdaContexts[context].diagBuffer[2];
            /* Start scanning from the beginning */
            ggdaContexts[context].nextIterPos = 0;
            /* set request is received */
            GgdaSetEvent(context, GGDA_EV_RX_A9_81);
            /* prepare the response */
            ggdaContexts[context].uudtPrimBuffer[0] = 0x81;
            /* set that this was the first request */
            ggdaContexts[context].rdiStateCtrl.isFirstAnswer |= kGgdaRdiMode81;
            /* store the context for the later response acknowledgement */
            /* reset flag that the so the search could start */
            ggdaContexts[context].rdiStateCtrl.isLastDtcFound = 0;
          }
        }
        break;

#if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
      case 0x82u:
        if ((ggdaCanConfig[context].optionalModes & kGgdaEnableModeA982) != 0)
        {
          if(ggdaContexts[context].dataLength != 2)
          {
            ggdaContexts[context].errorRegister = kGgdaNrcSubfunctionNotSupported;
          }
          else
          {
            /* send no response by default */
            ggdaContexts[context].stateMachine.isResActive = 0;
            /* stop or start scanning */
            if(ggdaContexts[context].diagBuffer[2] != 0)
            {
              /* set the mask to be asked for */
              ggdaContexts[context].rdi82SearchStatusMask = ggdaContexts[context].diagBuffer[2];
              /* set request is received */
              GgdaSetEvent(context, GGDA_EV_RX_A9_82);
            }
            else
            {
              ApplGgdaDisableOnChangeDtcCount(context);
              /* reset request is received */
              GgdaClearEvent(context, GGDA_EV_RX_A9_82);
              /*Send the positive response for stopping the service */
              GgdaRdiOnDtcCountChanged(context, 0);
            }
            /* set that this was the first request */
            ggdaContexts[context].rdiStateCtrl.isFirstAnswer |= kGgdaRdiMode82;
          }
        }
        else
        {
          ggdaContexts[context].errorRegister = kGgdaNrcSubfunctionNotSupported;
        }
        break;
#endif
      default:
        ggdaContexts[context].errorRegister = kGgdaNrcSubfunctionNotSupported;
        break;
      }
    }
    else
    {
      ggdaContexts[context].errorRegister = kGgdaNrcInvalidFormat;
    }
  }
  else
  {
    ggdaContexts[context].errorRegister = kGgdaNrcServiceNotSupported;
  }

  /* Only negative response will be sent */
  if(ggdaContexts[context].errorRegister != kGgdaNrcNone)
  {
    GgdaProcessingDone(context);
  }
}
#endif

#if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
/*******************************************************************************
* NAME:              GgdaRdiDeactivateOnChangeDtcCount
*
* CALLED BY:         Desc Application
* PRECONDITIONS:     
*
* DESCRIPTION:       Deactivates the current running 0x82 algorithm.
*
*******************************************************************************/
void GgdaRdiDeactivateOnChangeDtcCount(GgdaContextIndexType context)
{
  GgdaAssert(context < kGgdaNumContexts, kGgdaAssertInvalidContext)
  /* if active mode 0x82 */
  if(ggdaContexts[context].rdiStateCtrl.is82ModeActive == 1)
  {
    /* applciation must stop further notification about mode 0x82 to the RDI module */
    ApplGgdaDisableOnChangeDtcCount(context);
    /* reset mode 82 active */
    ggdaContexts[context].rdiStateCtrl.is82ModeActive = 0;
  }
}
#endif

#if (GGDA_CONFIG_SERVICE_A9_80_SUPPORT == GGDA_CONFIG_ON)
/*******************************************************************************
* NAME:              GgdaRdiDtcStatusByNumberFound
*
* CALLED BY:         Application
* PRECONDITIONS:     
*
* DESCRIPTION:       Confirmation that the response is written and ready for 
*                    transmission. 
*
*******************************************************************************/
void GgdaRdiDtcStatusByNumberFound(GgdaContextIndexType context, vuint8 statusByte)
{
  GgdaAssert(context < kGgdaNumContexts, kGgdaAssertInvalidContext)
  /* put the found status byte into the response */
  ggdaContexts[context].uudtPrimBuffer[4] = statusByte;
  /* set the confirmation flag */
  ggdaContexts[context].rdiStateCtrl.answerMode |= kGgdaRdiMode80;
}
#endif

#if (GGDA_CONFIG_SERVICE_A9_80_SUPPORT == GGDA_CONFIG_ON)
/*******************************************************************************
* NAME:              GgdaRdiDtcStatusByNumberNotFound
*
* CALLED BY:         Application
* PRECONDITIONS:     
*
* DESCRIPTION:       Confirmation that the no FaultTypeCombination was found
*
*******************************************************************************/
void GgdaRdiDtcStatusByNumberNotFound(GgdaContextIndexType context)
{
  GgdaAssert(context < kGgdaNumContexts, kGgdaAssertInvalidContext)
  /* force diagnostic negative response to be sent */
  ggdaContexts[context].errorRegister = kGgdaNrcRequestOutOfRange;
  /* activate the response ability */
  ggdaContexts[context].stateMachine.isResActive = 1;
  /* Clear the flag because of the non existing UUDT response (just USDT NEG RESPONSE) */
  ggdaContexts[context].rdiStateCtrl.isFirstAnswer &= (kGgdaRdiMode81 | kGgdaRdiMode82);
  /* free the diagnostic layer sending the negative response */
  GgdaProcessingDone(context);
}
#endif

#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
/*******************************************************************************
* NAME:              GgdaRdiDtcStatusByMaskFound
*
* CALLED BY:         Application
* PRECONDITIONS:     
*
* DESCRIPTION:       Confirmation that the response is written and ready for 
*                    transmission. 
*
*******************************************************************************/
void GgdaRdiDtcStatusByMaskFound(GgdaContextIndexType context, const DescRdiDtcRecord * const pDtcReport)
{
  GgdaAssert(context < kGgdaNumContexts, kGgdaAssertInvalidContext)
  /* store the next starting position here */
  ggdaContexts[context].nextIterPos = pDtcReport->nextIterPos;
  /* compose th response */
  ggdaContexts[context].uudtPrimBuffer[1] = GgdaGetHiByte(pDtcReport->dtcNum);
  ggdaContexts[context].uudtPrimBuffer[2] = GgdaGetLoByte(pDtcReport->dtcNum);
  ggdaContexts[context].uudtPrimBuffer[3] = pDtcReport->failureTypeByte;
  ggdaContexts[context].uudtPrimBuffer[4] = pDtcReport->statusByte;

  /* set the confirmation flag */
  ggdaContexts[context].rdiStateCtrl.answerMode |= kGgdaRdiMode81;
}
#endif

#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
/*******************************************************************************
* NAME:              GgdaRdiDtcStatusByMaskNotFound
*
* CALLED BY:         Application
* PRECONDITIONS:     
*
* DESCRIPTION:       Confirmation that no more or at all DTC with the given mask 
*                    were found.
*
*******************************************************************************/
void GgdaRdiDtcStatusByMaskNotFound(GgdaContextIndexType context, vuint8 dtcSam)
{
  GgdaAssert(context < kGgdaNumContexts, kGgdaAssertInvalidContext)
  /* compose EndOfDTCReportMess */
  ggdaContexts[context].uudtPrimBuffer[1] = 0;
  ggdaContexts[context].uudtPrimBuffer[2] = 0;
  ggdaContexts[context].uudtPrimBuffer[3] = 0;
  ggdaContexts[context].uudtPrimBuffer[4] = dtcSam;
  /* set the confirmation flag */
  ggdaContexts[context].rdiStateCtrl.answerMode |= kGgdaRdiMode81;
  /* set flag that the last that no more DTC there are */
  ggdaContexts[context].rdiStateCtrl.isLastDtcFound = 1;
}
#endif

#if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
/*******************************************************************************
* NAME:              GgdaRdiOnDtcCountChanged
*
* CALLED BY:         Application
* PRECONDITIONS:     
*
* DESCRIPTION:       Confirmation that DTC count with the given mask 
*                    was changed .
*
*******************************************************************************/
void GgdaRdiOnDtcCountChanged(GgdaContextIndexType context, vuint16 newCount)
{
  GgdaAssert(context < kGgdaNumContexts, kGgdaAssertInvalidContext)
  /* compose the response */
  ggdaContexts[context].uudtSecBuffer[1] = GgdaGetHiByte(newCount);
  ggdaContexts[context].uudtSecBuffer[2] = GgdaGetLoByte(newCount);
  /* set the confirmation flag */
  ggdaContexts[context].rdiStateCtrl.answerMode |= kGgdaRdiMode82;
}
#endif

/*******************************************************************************
CAN layer API
*******************************************************************************/

/*******************************************************************************
* NAME:              GgdaUsdtTransmit
*
* CALLED BY:         GGDA
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
static vuintx GgdaUsdtTransmit(GgdaContextIndexType context, vbittype txMode, vuint8* dataPtr, vuintx len)
{
  if(ggdaContexts[context].stateMachine.isTxModeActivity == kGgdaUsdtTxModeResNone)
  {
    canuint8 result;
    result = TpTransmit(ggdaTpConfig[context].tpTxChannel, dataPtr, (vuint16)len);
    if( result == kTpSuccess)
    {
      ggdaContexts[context].stateMachine.isTxModeActivity = txMode;
      /* Force transmission */
      TpTxStateTask(ggdaTpConfig[context].tpTxChannel);
      return 0;
    }
  }
  return 1;
}


/*******************************************************************************
* NAME:              GgdaRxErrorIndication
*
* CALLED BY:         CANdrv
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
void GgdaRxErrorIndication(canuint8 channel, canuint8 state)
{
  GgdaContextIndexType context;
  context = GgdaMapRxChannelToContext(channel);
  /* Dummy assignement to avoid compiler warnings */
  GGDA_IGNORE_UNREF_PARAM(state)

  GgdaReactivateTimer(context, GGDA_TIMER_VN);
  ggdaContexts[context].stateMachine.isRxModeActive     = 0;
  ggdaContexts[context].stateMachine.isUsdtBufferLocked = 0;
}


/*******************************************************************************
* NAME:              GgdaTxErrorIndication
*
* CALLED BY:         CANdrv
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
canuint8 GgdaTxErrorIndication(canuint8 channel, canuint8 state)
{
  GgdaConfirmation(channel, state);
  return kTpHoldChannel;
}

/*******************************************************************************
* NAME:              GgdaConfirmation
*
* CALLED BY:         CANdrv
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
void GgdaConfirmation(canuint8 channel, canuint8 state)
{
  GgdaContextIndexType context;
  context = GgdaMapTxChannelToContext(channel);
  /* Dummy assignement to avoid compiler warnings */
  GGDA_IGNORE_UNREF_PARAM(state)

  if(ggdaContexts[context].stateMachine.isTxModeActivity == kGgdaUsdtTxModeResFinal)
  {
    GgdaPostProcessing(context);
  }
  ggdaContexts[context].stateMachine.isTxModeActivity = kGgdaUsdtTxModeResNone;
}

/*******************************************************************************
* NAME:              GgdaPhysPrecopy
*
* CALLED BY:         CANdrv
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
canuint8* GgdaPhysGetBuffer(canuint8 channel, canuint16 dataLength)
{
  GgdaContextIndexType context;
  context = GgdaMapRxChannelToContext(channel);

  /* Check if free */
  if(ggdaContexts[context].stateMachine.isUsdtBufferLocked == 0)
  {
    ggdaContexts[context].stateMachine.isRxModeActive     = 1;
    ggdaContexts[context].stateMachine.isUsdtBufferLocked = 1;
    ggdaContexts[context].stateMachine.isFuncReq          = 0;
    /* Init length */
    ggdaContexts[context].dataLength = dataLength;

    if(dataLength > kGgdaDiagBufferSize)
    {
      /* Force only one frame copy */
      TpRxSetBufferOverrun(channel);
    } /* no else required in that case - a valid reception has to be simulated */

    GgdaDeactivateTimer(context, GGDA_TIMER_VN);
    GgdaSetEvent(context, GGDA_EV_ACTIVATE_VN);
    return ggdaContexts[context].diagBuffer;
  }

  return V_NULL;
}


/*******************************************************************************
* NAME:              GgdaPhysReqInd
*
* CALLED BY:         CANdrv
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
void GgdaPhysReqInd(canuint8 channel, canuint16 dataLen)
{
  GgdaContextIndexType context;
  context = GgdaMapRxChannelToContext(channel);

  GGDA_IGNORE_UNREF_PARAM(dataLen)
  ggdaContexts[context].stateMachine.isRxModeActive = 0;
  /* Reset the context */
  TpRxResetChannel(channel);
  GgdaSetEvent(context, GGDA_EV_NEW_REQ);
}


/*******************************************************************************
* NAME:              GgdaFuncPrecopy
*
* CALLED BY:         CANdrv
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
canuint8 GgdaFuncPrecopy(CanRxInfoStructPtr preParam)
{
  GgdaContextIndexType context;
  context = GgdaMapCanChannelToContext(preParam->Channel);

  /* Check TA */

  if ((preParam->pChipData[0] == 0xFE)
#if (GGDA_CONFIG_GW_SUPPORT == GGDA_CONFIG_ON)
    ||(preParam->pChipData[0] == 0xFD)
#endif
    )
  {
    /* DLC check (minimum for TPCI byte */
    if (CanRxActualDLC(preParam) >= (1 + 1))
    {
      /* Only valid SF allowed */
      if ((preParam->pChipData[1] < 0x07) && (preParam->pChipData[1] != 0))
      {
        /* Check TP func (SId == 3E) */
        if (preParam->pChipData[2] == 0x3E)
        {
          if (preParam->pChipData[1] == 0x01)
          {
            /* If still any service pending - do not restart timer */
            if (ggdaContexts[context].stateMachine.isUsdtBufferLocked == 0)
            {
              /* Use the "reactivate" API to always restart the timer!!! */
              GgdaReactivateTimer(context, GGDA_TIMER_VN);
              GgdaSetEvent(context, GGDA_EV_ACTIVATE_VN);
            }
            GgdaRefreshTimer(context, GGDA_TIMER_S1);
          }
        }
        else
        {
          /* Check if free */
          if (ggdaContexts[context].stateMachine.isUsdtBufferLocked == 0)
          {
            ggdaContexts[context].stateMachine.isUsdtBufferLocked = 1;
            ggdaContexts[context].stateMachine.isFuncReq    = 1;
            /* Init length */
            ggdaContexts[context].dataLength = preParam->pChipData[1];
            /* Copy data */
            GgdaCopyFromCan(ggdaContexts[context].diagBuffer,
                            &(preParam->pChipData[2]),
                            (vuintx)ggdaContexts[context].dataLength);
            GgdaDeactivateTimer(context, GGDA_TIMER_VN);
            GgdaSetEvent(context, GGDA_EV_ACTIVATE_VN | GGDA_EV_NEW_REQ);
          }
        }
      }
    }
  }
  return kCanNoCopyData;
}


/*******************************************************************************
UUDT layer API
*******************************************************************************/
/*******************************************************************************
* NAME:              GgdaUudtConfirmation
*
* CALLED BY:         CANdrv
* PRECONDITIONS:     
*
* DESCRIPTION:       
*
*******************************************************************************/
void GgdaUudtConfirmation(CanTransmitHandle txObject)
{
#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
  GgdaContextIndexType context;
  context = GgdaMapTxHandleToContext(txObject);

    /* Dummy assignment to avoid compiler warnings */
  GGDA_IGNORE_UNREF_PARAM(txObject)

  GgdaClearEvent(context, GGDA_EV_RESEND_MSG);
  GgdaDeactivateTimer(context, GGDA_TIMER_UUDT_CONF);
  /* restart the VN timer to keep the bus online */
  GgdaReactivateTimer(context, GGDA_TIMER_VN);

  /* Release buffer */
  /* perform this only for the 0x81 request - at this point the nextMode will have been shifted already */
#if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
  /* If 0x82 enable, the nextMode will be 82 */
  if((ggdaContexts[context].nextMode & kGgdaRdiMode82) != 0)
#else
  /* If 0x82 enable, nextMode will be 80 - wrapped around */
  if((ggdaContexts[context].nextMode & kGgdaRdiMode80) != 0)
#endif
  {
    /* check if that was the last confirmation - no more macthing DTCs or never found */
    if(ggdaContexts[context].rdiStateCtrl.isLastDtcFound == 0)
    {
      /* request again the application to find a mask */
      GgdaSetEvent(context, GGDA_EV_RX_A9_81);
    }
    else
    {
      /* free the module from this mode 
       * make it in the confirmation so not the next 0x80 or again
       * 0x81 to overwrite the buffer before it will be sent */
      ggdaContexts[context].rdiStateCtrl.is81ModeActive = 0;
    }
  }

  ggdaContexts[context].rdiStateCtrl.isUudtBufferLocked = 0;
#endif
}


#if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)
/*  ********************************************************************************
 * Function name:GgdaMapTxHandleToContext
 * Description: Finds context based on can driver transmit handle
 * Returns: context index
 * Parameter(s): can driver transmit handle
 * Particularitie(s) and limitation(s): Used in TxConfirmation
 ********************************************************************************  */
static GgdaContextIndexType GgdaMapTxHandleToContext(CanTransmitHandle txObject)
{
  GgdaContextIndexType context = 0;

  while ((context < kGgdaNumContexts) && (ggdaCanConfig[context].uudtResMsgHandle != txObject))
  {
    context++;
  }
  GgdaAssert((context < kGgdaNumContexts), kGgdaAssertInvalidContext)

  return context;
}
#endif

/*  ********************************************************************************
 * Function name:GgdaMapCanChannelToContext
 * Description: Finds context based on can channel handle
 * Returns: context index
 * Parameter(s): can channel handle
 * Particularitie(s) and limitation(s): Used in GgdaFuncPrecopy
 ********************************************************************************  */
static GgdaContextIndexType GgdaMapCanChannelToContext(CanChannelHandle channel)
{
  GgdaContextIndexType context = 0;

  while ((context < kGgdaNumContexts) && (ggdaCanConfig[context].canChannel != channel))
  {
    context++;
  }
  GgdaAssert((context < kGgdaNumContexts), kGgdaAssertInvalidContext)

  return context;
}

/*  ********************************************************************************
 * Function name:GgdaMapTxChannelToContext
 * Description: Finds context based on tp TX channel handle
 * Returns: context index
 * Parameter(s): p TX channel handle
 * Particularitie(s) and limitation(s): Used in GgdaConfirmation
 ********************************************************************************  */
static GgdaContextIndexType GgdaMapTxChannelToContext(vuint8 tpTxChannel)
{
  GgdaContextIndexType context = 0;

  while ((context < kGgdaNumContexts) && (ggdaTpConfig[context].tpTxChannel != tpTxChannel))
  {
    context++;
  }
  GgdaAssert((context < kGgdaNumContexts), kGgdaAssertInvalidContext)

  return context;
}

/*  ********************************************************************************
 * Function name:GgdaMapRxChannelToContext
 * Description: Finds context based on tp RX channel handle
 * Returns: context index
 * Parameter(s): tp RX channel handle
 * Particularitie(s) and limitation(s): Used in GgdaPhysGetBuffer, GgdaPhysReqInd,
 *                                      GgdaRxErrorIndication
 ********************************************************************************  */
static GgdaContextIndexType GgdaMapRxChannelToContext(vuint8 tpRxChannel)
{
  GgdaContextIndexType context = 0;

  while ((context < kGgdaNumContexts) && (ggdaTpConfig[context].tpRxChannel != tpRxChannel))
  {
    context++;
  }
  GgdaAssert((context < kGgdaNumContexts), kGgdaAssertInvalidContext)

  return context;
}
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
