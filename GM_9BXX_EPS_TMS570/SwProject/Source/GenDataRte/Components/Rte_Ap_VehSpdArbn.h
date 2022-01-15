/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Components/Rte_Ap_VehSpdArbn.h
 *     Workspace:  C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Mar 21 14:08:38 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_VEHSPDARBN_H
# define _RTE_AP_VEHSPDARBN_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

# ifndef RTE_CORE

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Float, RTE_VAR_INIT) Rte_Ap_VehSpdArbn_NonSecureVehSpd_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ap_VehSpdArbn_NonSecureVehSpdVld_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_NonSecureVehSpd_Kph_f32 (0.0F)
#  define Rte_InitValue_NonSecureVehSpdVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32 (0.0F)
#  define Rte_InitValue_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32 (0.0F)
#  define Rte_InitValue_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32 (0.0F)
#  define Rte_InitValue_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc (FALSE)
#  define Rte_InitValue_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32 (0.0F)
#  define Rte_InitValue_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc (FALSE)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32 Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32
#  define Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32(data) (*(data) = Rte_SrlComInput_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc
#  define Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc(data) (*(data) = Rte_SrlComInput_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32 Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32
#  define Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32(data) (*(data) = Rte_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc
#  define Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc(data) (*(data) = Rte_SrlComInput_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32 Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32
#  define Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32(data) (*(data) = Rte_SrlComInput_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc
#  define Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc(data) (*(data) = Rte_SrlComInput_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32 Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32
#  define Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32(data) (*(data) = Rte_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc
#  define Rte_Read_Ap_VehSpdArbn_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc(data) (*(data) = Rte_SrlComInput_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_NonSecureVehSpd_Kph_f32 Rte_Write_Ap_VehSpdArbn_NonSecureVehSpd_Kph_f32
#  define Rte_Write_Ap_VehSpdArbn_NonSecureVehSpd_Kph_f32(data) (Rte_Ap_VehSpdArbn_NonSecureVehSpd_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_NonSecureVehSpdVld_Cnt_lgc Rte_Write_Ap_VehSpdArbn_NonSecureVehSpdVld_Cnt_lgc
#  define Rte_Write_Ap_VehSpdArbn_NonSecureVehSpdVld_Cnt_lgc(data) (Rte_Ap_VehSpdArbn_NonSecureVehSpdVld_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_VEHSPDARBN_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VEHSPDARBN_APPL_CODE) VehSpdArbn_Per1(void);

# define RTE_STOP_SEC_AP_VEHSPDARBN_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Components/Rte_Ap_VehSpdArbn.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_VEHSPDARBN_H */
