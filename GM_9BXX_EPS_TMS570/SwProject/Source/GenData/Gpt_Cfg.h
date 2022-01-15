/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2009 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_Cfg.h
 *    Component:  DrvGpt_Tms570Tirti01Asr
 *       Module:  DrvGpt
 *    Generator:  Davinci Configurator
 *
 *  Description:  This module implements a driver to provide services for starting and stopping a functional timer
 *                instance (channel) within the hardware timer module. Individual timeout periods (single shot mode) as
 *                well as repeating timeout periods (continuous mode) can be generated. The user can configure, if a
 *                notification shall be invoked, when the requested timeout period has expired. Notifications can be
 *                enabled and disabled at runtime. Both, the relative time elapsed since the last notification occurred
 *                (respectively the channel has been started) and the time remaining until the next notification will
 *                occur, can be queried. The GPT Driver can be used to wakeup the ECU, whenever a predefined timeout
 *                period has expired. A mode switching service is provided to switch the GPT Driver between normal
 *                operation and sleep mode.
 *********************************************************************************************************************/

/**********************************************************************************************************************
  
    Project:    EPS.ecuc
    Generated:  2013-07-16 01:12 pm
    Licensee:   Nexteer Automotive Corporation (2502600702)
 
    This file is generated by DaVinci Configurator Pro - DAVINCICFG.EXE V4.0.67.0.
    Do not modify this file, otherwise the software may behave in unexpected way.
    
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Roland S��                    Rsu           Vector Informatik GmbH
 *  Peter Lang                     Lg             Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2008-11-07  Rsu                   Initial release of Asr3.0 implementation
 *  01.00.01  2009-01-09  Rsu     ESCAN00032263 Removed BETA disclaimer
 *                                ESCAN00032267 Enhanced configuration of hardware resources
 *  01.00.02  2011-02-02  Lg      ESCAN00045220 Adding the symbolic name value feature
 *                                ESCAN00045670 Correcting the compore operation for numbers  
 *  01.00.03  2011-02-02  Lg      ESCAN00052054 Adding the missing parameter into the indentifire  
 *  01.00.04  2012-01-16  Lg      ESCAN00054736 Adding register access feature via OS interface 
 *********************************************************************************************************************/

/* switch between public and private sections ------------------------------*/
#if (!defined GPT_CFG_H)
#define GPT_CFG_H

/*---- Version identification - satisfies ----------------------------------*/
#define GPT_CFG_MAJOR_VERSION    (1)
#define GPT_CFG_MINOR_VERSION    (0)
#define GPT_CFG_PATCH_VERSION    (4)

/* ---- API relevant (public) section of configuration ---------------------*/

/* ---- pre-compile switches for services ----------------------------------*/
#define GPT_DEV_ERROR_DETECT     /*<GPT_DEV_ERROR_DETECT/>*/ (STD_OFF)
/* ------------------------------------------------------------------------ */
/*              Configurations for Development mode                         */
/*                                                                          */
#if (STD_ON == GPT_DEV_ERROR_DETECT)                                     
/* ------------------------------------------------------------------------ */

    /* check if driver has been initialized */
    #define GPT_CFG_CHK_UNINIT          /*<GPT_CFG_CHK_UNINIT/>*/ (STD_ON)
    /* switch parameter check */
    #define GPT_CFG_DO_PARAM_CHK        /*<GPT_CFG_DO_PARAM_CHK/>*/ (STD_ON)
    /* check if a channel is still active */
    #define GPT_CFG_CHK_BUSY            /*<GPT_CFG_CHK_BUSY/>*/ (STD_ON)
    /* check if driver has already been initialized */
    #define GPT_CFG_CHK_ALREADY_INIT    /*<GPT_CFG_CHK_ALREADY_INIT/>*/ (STD_ON)
    /* check if a channel is not yet started */
    #define GPT_CFG_CHK_NOT_STARTED     /*<GPT_CFG_CHK_NOT_STARTED/>*/ (STD_ON)
    /* check if notification function is a null pointer */
    #define GPT_CFG_CHK_NOTIFPTR        /*<GPT_CFG_CHK_NOTIFPTR/>*/ (STD_ON)
    /* switch reporting to Det */
    #define GPT_CFG_DEBUG_REPORTING      /*<GPT_CFG_DEBUG_REPORTING/>*/ (STD_ON)

/* ------------------------------------------------------------------------ */
/*                  Configurations for Production mode                      */
#else
/* ------------------------------------------------------------------------ */
    /* no error detection ...
     */
    #define GPT_CFG_CHK_UNINIT          ( STD_OFF )
    #define GPT_CFG_DO_PARAM_CHK        ( STD_OFF )
    #define GPT_CFG_CHK_BUSY            ( STD_OFF )
    #define GPT_CFG_CHK_ALREADY_INIT    ( STD_OFF )
    #define GPT_CFG_CHK_NOT_STARTED     ( STD_OFF )
    #define GPT_CFG_CHK_NOTIFPTR        ( STD_OFF )
    #define GPT_CFG_DEBUG_REPORTING     ( STD_OFF )

/* ------------------------------------------------------------------------ */
#endif     /* (STD_ON == GPT_DEV_ERROR_DETECT) */

#if (STD_ON == GPT_CFG_DO_PARAM_CHK)

    #define GPT_CFG_CHK_PARAM_CHL       /*<GPT_CFG_CHK_PARAM_CHL/>*/ (STD_OFF)
    #define GPT_CFG_CHK_PARAM_VALUE     /*<GPT_CFG_CHK_PARAM_VALUE/>*/ (STD_ON)
    #define GPT_CFG_CHK_PARAM_CONFIG    /*<GPT_CFG_CHK_PARAM_CONFIG/>*/ (STD_ON)
    #define GPT_CFG_CHK_PARAM_VINFO     /*<GPT_CFG_CHK_PARAM_VINFO/>*/ (STD_ON)
    #define GPT_CFG_CHK_PARAM_MODE      /*<GPT_CFG_CHK_PARAM_MODE/>*/ (STD_ON)
    #define GPT_CFG_CHK_PARAM_WAKEUPCHL /*<GPT_CFG_CHK_PARAM_WAKEUPCHL/>*/ (STD_OFF)

#else

    #define GPT_CFG_CHK_PARAM_CHL       ( STD_OFF )
    #define GPT_CFG_CHK_PARAM_VALUE     ( STD_OFF )
    #define GPT_CFG_CHK_PARAM_CONFIG    ( STD_OFF )
    #define GPT_CFG_CHK_PARAM_VINFO     ( STD_OFF )
    #define GPT_CFG_CHK_PARAM_MODE      ( STD_OFF )
    #define GPT_CFG_CHK_PARAM_WAKEUPCHL ( STD_OFF )

#endif     /* (STD_ON == GPT_CFG_DO_PARAM_CHK) */

#if (STD_ON == GPT_CFG_DEBUG_REPORTING)

    /* Function for errorhook */
    #define Gpt_Errorhook(Gpt_FunctionId, Gpt_ErrorCode) \
    (/*<GPT_ERRORHOOK>*/Det_ReportError/*</GPT_ERRORHOOK>*/((GPT_MODULE_ID), (GPT_INSTANCE_ID), (Gpt_FunctionId), (Gpt_ErrorCode)))

#else

    #define Gpt_Errorhook(Gpt_FunctionId, Gpt_ErrorCode)
#endif  /* (STD_ON == GPT_CFG_DEBUG_REPORTING) */

/* Is the reporting of Debug-Errors enabled above?                          */
#if ((STD_ON == GPT_DEV_ERROR_DETECT) && (STD_ON == GPT_CFG_DO_PARAM_CHK))

    /* Include-File, which contains Errorhook-Function                      */
    /*<GPT_CFG_INCLUDE_DET/>*/ #include "Det.h"

#endif  /* ((STD_ON == GPT_DEV_ERROR_DETECT) && (STD_ON == GPT_CFG_DO_PARAM_CHK)) */

/*              End of configurations for Development mode                  */
/*                                                                          */


/* ===== REGISTER ACCESS FOR SAFETY MODE ================================== */

/* Configuration of Safety Hw Access */

#define GPT_SPECIAL_REGISTER_ACCESS_ENABLED    /*<GPT_SPEC_REG_ACC_ENABLED/>*/ (STD_ON)

#if (STD_ON == GPT_SPECIAL_REGISTER_ACCESS_ENABLED)
    #define GPT_SPECIAL_REGISTER_ACCESS_ONLY_FOR_WRITE          /*<GPT_SPEC_REG_ACC_ONLY_FOR_WRITE/>*/ (STD_ON)
    #define GPT_SPECIAL_REGISTER_ACCESS_ONLY_FOR_PRIVILEGED_MODE_REGISTERS /*<GPT_SPEC_REG_ACC_ONLY_FOR_PRIV_MODE_REG/>*/ (STD_ON)
    #define GPT_SPECIAL_REGISTER_ACCESS_NOT_IN_INIT /*<GPT_SPEC_REG_ACC_NOT_IN_INIT/>*/ (STD_OFF)
#else
    #define GPT_SPECIAL_REGISTER_ACCESS_ONLY_FOR_WRITE                                     (STD_OFF)
    #define GPT_SPECIAL_REGISTER_ACCESS_ONLY_FOR_PRIVILEGED_MODE_REGISTERS                 (STD_OFF)
    #define GPT_SPECIAL_REGISTER_ACCESS_NOT_IN_INIT                                        (STD_OFF)
#endif

/*---- symbolic names ------------------------------------------------------*/
/* symbolic names are specified by the configuration tool */
/*<GPT_CFG_CHANNEL_NAMES>*/
#define SystemTime_uS (0u)
/*</GPT_CFG_CHANNEL_NAMES>*/

/*---- API CFG Defines -----------------------------------------------------*/
/* Include the Gpt_GetVersionInfo */
#define GPT_VERSION_INFO_API   /*<GPT_VERSION_INFO_API/>*/ (STD_OFF)
/* Include the Gpt_DeInit */
#define GPT_DEINIT_API     /*<GPT_DEINIT_API/>*/ (STD_OFF)
/* Include the Gpt_GetTimeElapsed */
#define GPT_TIME_ELAPSED_API   /*<GPT_TIME_ELAPSED_API/>*/ (STD_OFF)
/* Include the Gpt_GetTimeRemaining */
#define GPT_TIME_REMAINING_API  /*<GPT_TIME_REMAINING_API/>*/ (STD_OFF)
/* Include the Gpt_Enable/Disible Notification */
#define GPT_ENABLE_DISABLE_NOTIFICATION_API /*<GPT_ENABLE_DISABLE_NOTIFICATION_API/>*/ (STD_ON)
/* enable wakeup features */
#define GPT_WAKEUP_FUNCTIONALITY_API  /*<GPT_WAKEUP_FUNCTIONALITY_API/>*/ (STD_ON)

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    /* enabled reporting of wake up events to EcuM */
    #define GPT_REPORT_WAKEUP_SOURCE /*<GPT_REPORT_WAKEUP_SOURCE/>*/ (STD_ON)
    /* include for Wakeup handling */
    /*<GPT_CFG_WAKEUP_INCLUDE>*/
    #include "EcuM_Cbk.h"
/*</GPT_CFG_WAKEUP_INCLUDE>*/
#endif

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    /* include user callback definitions for notification  */
    /*<GPT_CFG_INCLUDE_LIST>*/
#include "ApplCallbacks.h"
/*</GPT_CFG_INCLUDE_LIST>*/
#endif

/* notification callback function pointer */
typedef void (*Gpt_NotifyType)(void);
/*type for specifying source clock selection */
typedef uint32 Gpt_ClockSourceType;
/* type describing the hardware channel ID */
typedef uint32 Gpt_HWChannelType;

/* configuration per channel */
typedef struct
{
    VAR (Gpt_NotifyType, GPT_APPL_CODE) Notification_pt;        /* Pointer to notification function */
    uint32                              ChannelPrescale_u32;    /* Prescale for clock source */
    uint32                              WakeupSourceID;         /* Assigned Wakeup Source from EcuM */
    Gpt_ClockSourceType                 ChannelClksrc_t;        /* Channel clock source */
    uint32                              ChannelMode_u32;        /* Channel mode */
    Gpt_HWChannelType                   HWChannel_t;            /* Channel's name */
} Gpt_ChannelConfigType;

/* global configuration of the driver */
typedef struct
{
    P2CONST(Gpt_ChannelConfigType,
            AUTOMATIC,
            GPT_CONST_PBCFG) ChannelConfig_pt;               /* Pointer to Channel list*/
    uint32             ChannelCount_u32;               /* Number of channels configured */
} Gpt_ConfigType;

/* extern declaration of the runtime configuration structure */
#define GPT_START_SEC_PBCFG_ROOT
#include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_3.4  */

/*<GPT_CONFIGURATION_EXTERN>*/
extern const Gpt_ConfigType Gpt_Runtime;
/*</GPT_CONFIGURATION_EXTERN>*/

#define GPT_STOP_SEC_PBCFG_ROOT
#include "MemMap.h"  /* PRQA S 5087 *//* MD_MSR_3.4  */

#endif /* Public part: #if (!defined GPT_CFG_H) */


/*---- Module relavant configurations (private, C file only) ---------------*/
#if ((defined GPT_SOURCE) || (defined GPT_IRQ_SOURCE))  /* PRQA S 0833 *//*  MISRA-C:2004 Rules applicable to message 0833:  This switch is not used to protect against multiple inclusion*/

 /*--------------------- CFG Macros -------------------------------------------*/
 #define GPT_ISR_CAT1    (0u)
 #define GPT_ISR_CAT2    (1u)
 #define GPT_ISR_VOID    (2u)

 #define GPT_CFG_ISR_TYPE    /*<GPT_CFG_ISR_TYPE/>*/ GPT_ISR_CAT2

/*---- CFG Defines ---------------------------------------------------------*/
/*---- CFG Includes --------------------------------------------------------*/
/*<GPT_ISR_INCLUDE_IRQ>*/
#include "SchM_Gpt.h"
#include "Os.h"
/*</GPT_ISR_INCLUDE_IRQ>*/

/*---- include of supporting definitions for configuration -----------------*/
/*---- CFG Macros ----------------------------------------------------------*/
#define Gpt_GlobalSuspend() /*<GPT_GLOBAL_SUSPEND/>*/ SchM_Enter_Gpt(GPT_EXCLUSIVE_AREA_0)
#define Gpt_GlobalRestore() /*<GPT_GLOBAL_RESTORE/>*/ SchM_Exit_Gpt(GPT_EXCLUSIVE_AREA_0)

#define Gpt_GlobalReEnable() /*<GPT_GLOBAL_REENABLE/>*/ 

#endif /* ((defined GPT_SOURCE) || (defined GPT_IRQ_SOURCE)) */

/*---- End of File ---------------------------------------------------------*/