/***************************************************************************************************************
| Project Name: GM Gateway Diagnostic Addon
|    File Name: Ggda.h
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
#if !defined(__GGDA_H__)
# define __GGDA_H__


/*----------------------*/
/*       Version        */
/*----------------------*/
/* ##V_CFG_MANAGEMENT ##CQProject : Diag_CANdescGgdaExt_Gm CQComponent : Implementation */
# define DIAG_CANDESCGGDAEXT_GM_VERSION                              0x0206
# define DIAG_CANDESCGGDAEXT_GM_RELEASE_VERSION                      0x03

/*----------------------*/
/*    Configuration     */
/*----------------------*/

# include "ggda_par.h"

/*----------------------*/
/* Default Configuration*/
/*----------------------*/
# if !defined(GGDA_CONFIG_GW_SUPPORT)
#  define GGDA_CONFIG_GW_SUPPORT                                     GGDA_CONFIG_OFF
# endif

/*----------------------*/
/*          API         */
/*----------------------*/

/* Administrative */
void GgdaInitPowerOn(void);
void GgdaTimerTask(void);
void GgdaStateTask(void);

/* Mode A9 */
# if (GGDA_CONFIG_SERVICE_A9_SUPPORT == GGDA_CONFIG_ON)

/* Level 80 */
#  if (GGDA_CONFIG_SERVICE_A9_80_SUPPORT == GGDA_CONFIG_ON)
/* Confirmations */
void GgdaRdiDtcStatusByNumberFound(GgdaContextIndexType context, vuint8 statusByte);
void GgdaRdiDtcStatusByNumberNotFound(GgdaContextIndexType context);
/* Callback functions */
void ApplGgdaGetDtcStatusByNumber(GgdaContextIndexType context, vuint16 dtcNum, vuint8 failureTypeByte);
#  endif

/* Level 81 */
/* Confirmations */
void GgdaRdiDtcStatusByMaskFound(GgdaContextIndexType context, const DescRdiDtcRecord * const pDtcReport);
void GgdaRdiDtcStatusByMaskNotFound(GgdaContextIndexType context, vuint8 dtcSam);
/* Callback functions */
void ApplGgdaGetDtcStatusByMask(GgdaContextIndexType context, vuint16 iterPos, vuint8 statusMask);

/* Level 82 */
#  if (GGDA_CONFIG_SERVICE_A9_82_SUPPORT == GGDA_CONFIG_ON)
/* Explicit deactivation of the DTC count change algorithm */
void GgdaRdiDeactivateOnChangeDtcCount(GgdaContextIndexType context);
void GgdaRdiOnDtcCountChanged(GgdaContextIndexType context, vuint16 newCount);
/* Callback functions */
void ApplGgdaEnableOnChangeDtcCount(GgdaContextIndexType context, vuint8 statusMask);
void ApplGgdaDisableOnChangeDtcCount(GgdaContextIndexType context);
#  endif
# endif

/* Mode A5 */
vuint8 ApplGgdaMayEnterProgMode(GgdaContextIndexType context);

# if (GGDA_CONFIG_SERVICE_A5_02_SUPPORT == GGDA_CONFIG_ON)
vuint8 ApplGgdaMayEnterHiSpeedProgMode(GgdaContextIndexType context);
# endif

/* Events */
# if (GGDA_CONFIG_SERVICE_10_04_SUPPORT == GGDA_CONFIG_ON)
void ApplGgdaOnWakeUpLink(void);
# endif
# if (GGDA_CONFIG_SERVICE_10_02_SUPPORT == GGDA_CONFIG_ON)
void ApplGgdaOnDisableAllDtc(void);
# endif

void ApplGgdaOnDisableNormalComm(GgdaContextIndexType context);
void ApplGgdaOnReturnToNormalMode(GgdaContextIndexType context);

/* Actions */
void ApplGgdaForceEcuReset(void);
#endif /*__GGDA_H__*/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
