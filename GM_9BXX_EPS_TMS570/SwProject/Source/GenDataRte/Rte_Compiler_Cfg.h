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
 *          File:  Rte_Compiler_Cfg.h
 *     Workspace:  C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Mar 21 14:08:41 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  RTE Compiler Abstraction header file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_COMPILER_CFG_H
# define _RTE_COMPILER_CFG_H


/**********************************************************************************************************************
 * RTE specific defines
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CODE
 *********************************************************************************************************************/

/* used for code */
# define RTE_CODE

/* used for all global or static variables that are not initialized by the startup code of the compiler */
# define RTE_VAR_NOINIT

/* used for global or static variables that are initialized with zero by the startup code of the compiler or in Rte_InitMemory */
# define RTE_VAR_ZERO_INIT

/* used for global or static variables that are initialized by the startup code of the compiler or in Rte_InitMemory */
# define RTE_VAR_INIT

/* used for global or static constants */
# define RTE_CONST

/* used for references on application data (variables or constants */
# define RTE_APPL_DATA

/* used for references on application variables */
# define RTE_APPL_VAR

/* used for references on application functions */
# define RTE_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * SW-C specific defines
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ABSHWPOS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ABSHWPOS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ABSHWPOS_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ABSHWPOS_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ACTIVEPULL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ACTIVEPULL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ACTIVEPULL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ACTIVEPULL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_APXCP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_APXCP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_APXCP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_APXCP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ASSIST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ASSIST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ASSIST_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ASSIST_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ASSISTFIREWALL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ASSISTFIREWALL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ASSISTFIREWALL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ASSISTFIREWALL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ASTLMT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ASTLMT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ASTLMT_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ASTLMT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_AVGFRICLRN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_AVGFRICLRN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_AVGFRICLRN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_AVGFRICLRN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_BVDIAG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_BVDIAG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_BVDIAG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_BVDIAG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_BATTVLTG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_BATTVLTG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_BATTVLTG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_BATTVLTG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_BATTVLTGCORRLN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_BATTVLTGCORRLN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_BATTVLTGCORRLN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_BATTVLTGCORRLN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CHKPTAP10_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CHKPTAP10_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CHKPTAP10_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CHKPTAP10_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CHKPTAP8_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CHKPTAP8_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CHKPTAP8_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CHKPTAP8_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CHKPTAP9_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CHKPTAP9_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CHKPTAP9_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CHKPTAP9_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_COMPLERR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_COMPLERR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_COMPLERR_APPL_DATA

/* used for references on application functions */
# define RTE_AP_COMPLERR_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CTRLPOLARITYBRSHLSS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CTRLPOLARITYBRSHLSS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CTRLPOLARITYBRSHLSS_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CTRLPOLARITYBRSHLSS_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CURRCMD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CURRCMD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CURRCMD_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CURRCMD_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CURRPARAMCOMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CURRPARAMCOMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CURRPARAMCOMP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CURRPARAMCOMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CUSTPERSRVCS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CUSTPERSRVCS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CUSTPERSRVCS_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CUSTPERSRVCS_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DAMPING_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DAMPING_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DAMPING_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DAMPING_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DAMPINGFIREWALL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DAMPINGFIREWALL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DAMPINGFIREWALL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DAMPINGFIREWALL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DEMIF_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DEMIF_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DEMIF_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DEMIF_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DIAGMGR10_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DIAGMGR10_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DIAGMGR10_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DIAGMGR10_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DIAGMGR8_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DIAGMGR8_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DIAGMGR8_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DIAGMGR8_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DIAGMGR9_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DIAGMGR9_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DIAGMGR9_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DIAGMGR9_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DIGPHSREASDIAG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DIGPHSREASDIAG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DIGPHSREASDIAG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DIGPHSREASDIAG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_EOTACTUATORMNG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_EOTACTUATORMNG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_EOTACTUATORMNG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_EOTACTUATORMNG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ELEPWR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ELEPWR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ELEPWR_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ELEPWR_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ETDMPFW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ETDMPFW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ETDMPFW_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ETDMPFW_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_FLTINJECTION_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_FLTINJECTION_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_FLTINJECTION_APPL_DATA

/* used for references on application functions */
# define RTE_AP_FLTINJECTION_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_FRQDEPDMPNINRTCMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_FRQDEPDMPNINRTCMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_FRQDEPDMPNINRTCMP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_FRQDEPDMPNINRTCMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_GMSTRTSTOP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_GMSTRTSTOP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_GMSTRTSTOP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_GMSTRTSTOP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_GENPOSTRAJ_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_GENPOSTRAJ_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_GENPOSTRAJ_APPL_DATA

/* used for references on application functions */
# define RTE_AP_GENPOSTRAJ_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_GMPWRPKSRVDATARCVRY_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_GMPWRPKSRVDATARCVRY_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_GMPWRPKSRVDATARCVRY_APPL_DATA

/* used for references on application functions */
# define RTE_AP_GMPWRPKSRVDATARCVRY_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_HOWDETECT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_HOWDETECT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_HOWDETECT_APPL_DATA

/* used for references on application functions */
# define RTE_AP_HOWDETECT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_HILOADSTALL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_HILOADSTALL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_HILOADSTALL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_HILOADSTALL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_HIGHFREQASSIST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_HIGHFREQASSIST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_HIGHFREQASSIST_APPL_DATA

/* used for references on application functions */
# define RTE_AP_HIGHFREQASSIST_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_HWPWRUPSEQ_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_HWPWRUPSEQ_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_HWPWRUPSEQ_APPL_DATA

/* used for references on application functions */
# define RTE_AP_HWPWRUPSEQ_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_HYSTCOMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_HYSTCOMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_HYSTCOMP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_HYSTCOMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_LMTCOD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_LMTCOD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_LMTCOD_APPL_DATA

/* used for references on application functions */
# define RTE_AP_LMTCOD_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_LOAMGR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_LOAMGR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_LOAMGR_APPL_DATA

/* used for references on application functions */
# define RTE_AP_LOAMGR_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_LRNEOT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_LRNEOT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_LRNEOT_APPL_DATA

/* used for references on application functions */
# define RTE_AP_LRNEOT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_MOTAGCORRLN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_MOTAGCORRLN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_MOTAGCORRLN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_MOTAGCORRLN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_MOTPOSNCMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_MOTPOSNCMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_MOTPOSNCMP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_MOTPOSNCMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_MTRTEMPEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_MTRTEMPEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_MTRTEMPEST_APPL_DATA

/* used for references on application functions */
# define RTE_AP_MTRTEMPEST_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_PICURRCNTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_PICURRCNTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_PICURRCNTRL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_PICURRCNTRL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_PEAKCURREST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_PEAKCURREST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_PEAKCURREST_APPL_DATA

/* used for references on application functions */
# define RTE_AP_PEAKCURREST_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_POSSERVO_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_POSSERVO_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_POSSERVO_APPL_DATA

/* used for references on application functions */
# define RTE_AP_POSSERVO_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_PWRDSCNTDUINV_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_PWRDSCNTDUINV_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_PWRDSCNTDUINV_APPL_DATA

/* used for references on application functions */
# define RTE_AP_PWRDSCNTDUINV_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_PWRLMTFUNCCR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_PWRLMTFUNCCR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_PWRLMTFUNCCR_APPL_DATA

/* used for references on application functions */
# define RTE_AP_PWRLMTFUNCCR_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_QUADDET_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_QUADDET_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_QUADDET_APPL_DATA

/* used for references on application functions */
# define RTE_AP_QUADDET_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_RETURNFIREWALL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_RETURNFIREWALL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_RETURNFIREWALL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_RETURNFIREWALL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SASPLAUSDIAG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SASPLAUSDIAG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SASPLAUSDIAG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SASPLAUSDIAG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SIGNLCONDN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SIGNLCONDN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SIGNLCONDN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SIGNLCONDN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SNSROFFSCORRN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SNSROFFSCORRN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SNSROFFSCORRN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SNSROFFSCORRN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SNSROFFSLRNG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SNSROFFSLRNG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SNSROFFSLRNG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SNSROFFSLRNG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SRLCOMINPUT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SRLCOMINPUT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SRLCOMINPUT_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SRLCOMINPUT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SRLCOMOUTPUT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SRLCOMOUTPUT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SRLCOMOUTPUT_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SRLCOMOUTPUT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STOPCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STOPCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STOPCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STOPCTRL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STAMD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STAMD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STAMD_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STAMD_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STAMD8_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STAMD8_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STAMD8_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STAMD8_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STAMD9_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STAMD9_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STAMD9_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STAMD9_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STABILITYCOMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STABILITYCOMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STABILITYCOMP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STABILITYCOMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STABILITYCOMP2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STABILITYCOMP2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STABILITYCOMP2_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STABILITYCOMP2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SWEEP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SWEEP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SWEEP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SWEEP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SWEEP2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SWEEP2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SWEEP2_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SWEEP2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TSMIT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TSMIT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TSMIT_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TSMIT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_THRMLDUTYCYCLE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_THRMLDUTYCYCLE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_THRMLDUTYCYCLE_APPL_DATA

/* used for references on application functions */
# define RTE_AP_THRMLDUTYCYCLE_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TQRSDG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TQRSDG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TQRSDG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TQRSDG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TRANLDAMPG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TRANLDAMPG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TRANLDAMPG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TRANLDAMPG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TRQARBLIM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TRQARBLIM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TRQARBLIM_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TRQARBLIM_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TRQCANC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TRQCANC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TRQCANC_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TRQCANC_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TRQCMDSCL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TRQCMDSCL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TRQCMDSCL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TRQCMDSCL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TRQLOA_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TRQLOA_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TRQLOA_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TRQLOA_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TRQOSC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TRQOSC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TRQOSC_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TRQOSC_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TRQOVLSTA_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TRQOVLSTA_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TRQOVLSTA_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TRQOVLSTA_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TUNINGSELAUTH_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TUNINGSELAUTH_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TUNINGSELAUTH_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TUNINGSELAUTH_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_VEHDYN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_VEHDYN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_VEHDYN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_VEHDYN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_VEHPWRMD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_VEHPWRMD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_VEHPWRMD_APPL_DATA

/* used for references on application functions */
# define RTE_AP_VEHPWRMD_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_VEHSPDARBN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_VEHSPDARBN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_VEHSPDARBN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_VEHSPDARBN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_VEHSPDLMT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_VEHSPDLMT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_VEHSPDLMT_APPL_DATA

/* used for references on application functions */
# define RTE_AP_VEHSPDLMT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_WIRINPUTQUAL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_WIRINPUTQUAL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_WIRINPUTQUAL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_WIRINPUTQUAL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_WHLIMBREJ_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_WHLIMBREJ_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_WHLIMBREJ_APPL_DATA

/* used for references on application functions */
# define RTE_AP_WHLIMBREJ_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_EPWM2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_EPWM2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_EPWM2_APPL_DATA

/* used for references on application functions */
# define RTE_AP_EPWM2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CDD_APPL_DATA

/* used for references on application functions */
# define RTE_CDD_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CD_NHET1CFGANDUSE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CD_NHET1CFGANDUSE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CD_NHET1CFGANDUSE_APPL_DATA

/* used for references on application functions */
# define RTE_CD_NHET1CFGANDUSE_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CD_PHASEFDBKMEAS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CD_PHASEFDBKMEAS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CD_PHASEFDBKMEAS_APPL_DATA

/* used for references on application functions */
# define RTE_CD_PHASEFDBKMEAS_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CD_UDIAG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CD_UDIAG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CD_UDIAG_APPL_DATA

/* used for references on application functions */
# define RTE_CD_UDIAG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_COMM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_COMM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_COMM_APPL_DATA

/* used for references on application functions */
# define RTE_COMM_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTRLDVELRTN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTRLDVELRTN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTRLDVELRTN_APPL_DATA

/* used for references on application functions */
# define RTE_CTRLDVELRTN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IOHWABSTRACTION_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_IOHWABSTRACTION_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IOHWABSTRACTION_APPL_DATA

/* used for references on application functions */
# define RTE_IOHWABSTRACTION_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IOHWABSTRACTIONUSR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_IOHWABSTRACTIONUSR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IOHWABSTRACTIONUSR_APPL_DATA

/* used for references on application functions */
# define RTE_IOHWABSTRACTIONUSR_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_NEXTEERLIBS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NEXTEERLIBS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NEXTEERLIBS_APPL_DATA

/* used for references on application functions */
# define RTE_NEXTEERLIBS_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_NTWRAP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NTWRAP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NTWRAP_APPL_DATA

/* used for references on application functions */
# define RTE_NTWRAP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_NVM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NVM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NVM_APPL_DATA

/* used for references on application functions */
# define RTE_NVM_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_NVMPROXY_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NVMPROXY_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NVMPROXY_APPL_DATA

/* used for references on application functions */
# define RTE_NVMPROXY_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_RTEERRATA10_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_RTEERRATA10_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RTEERRATA10_APPL_DATA

/* used for references on application functions */
# define RTE_RTEERRATA10_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_RTEERRATA8_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_RTEERRATA8_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RTEERRATA8_APPL_DATA

/* used for references on application functions */
# define RTE_RTEERRATA8_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_RTEERRATA9_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_RTEERRATA9_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RTEERRATA9_APPL_DATA

/* used for references on application functions */
# define RTE_RTEERRATA9_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_ANAHWTRQ_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_ANAHWTRQ_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_ANAHWTRQ_APPL_DATA

/* used for references on application functions */
# define RTE_SA_ANAHWTRQ_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_CDDINTERFACE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_CDDINTERFACE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_CDDINTERFACE_APPL_DATA

/* used for references on application functions */
# define RTE_SA_CDDINTERFACE_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_CMMTRCURR3PHS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_CMMTRCURR3PHS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_CMMTRCURR3PHS_APPL_DATA

/* used for references on application functions */
# define RTE_SA_CMMTRCURR3PHS_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_CTRLTEMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_CTRLTEMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_CTRLTEMP_APPL_DATA

/* used for references on application functions */
# define RTE_SA_CTRLTEMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_DIGCOLPS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_DIGCOLPS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_DIGCOLPS_APPL_DATA

/* used for references on application functions */
# define RTE_SA_DIGCOLPS_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_HWTQCORRLN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_HWTQCORRLN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_HWTQCORRLN_APPL_DATA

/* used for references on application functions */
# define RTE_SA_HWTQCORRLN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_HWTRQARBN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_HWTRQARBN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_HWTRQARBN_APPL_DATA

/* used for references on application functions */
# define RTE_SA_HWTRQARBN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MOTMECLPOSN1_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MOTMECLPOSN1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MOTMECLPOSN1_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MOTMECLPOSN1_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MOTMECLPOSN2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MOTMECLPOSN2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MOTMECLPOSN2_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MOTMECLPOSN2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRDRVDIAG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRDRVDIAG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRDRVDIAG_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRDRVDIAG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRPOS3SINCOS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRPOS3SINCOS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRPOS3SINCOS_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRPOS3SINCOS_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRVEL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRVEL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRVEL_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRVEL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRVEL2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRVEL2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRVEL2_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRVEL2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRVEL3_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRVEL3_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRVEL3_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRVEL3_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_OVRVOLTMON_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_OVRVOLTMON_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_OVRVOLTMON_APPL_DATA

/* used for references on application functions */
# define RTE_SA_OVRVOLTMON_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_SHTDNMECH_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_SHTDNMECH_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_SHTDNMECH_APPL_DATA

/* used for references on application functions */
# define RTE_SA_SHTDNMECH_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_TMPLMONRDUALIVTR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_TMPLMONRDUALIVTR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_TMPLMONRDUALIVTR_APPL_DATA

/* used for references on application functions */
# define RTE_SA_TMPLMONRDUALIVTR_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_TMPLMONRDUALIVTR2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_TMPLMONRDUALIVTR2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_TMPLMONRDUALIVTR2_APPL_DATA

/* used for references on application functions */
# define RTE_SA_TMPLMONRDUALIVTR2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_WDGM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_WDGM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_WDGM_APPL_DATA

/* used for references on application functions */
# define RTE_WDGM_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Per-Instance Memory specific defines
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP
 *********************************************************************************************************************/

# define RTE_VAR_DEFAULT_RTE_Ap_10_PIM_GROUP

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP
 *********************************************************************************************************************/

# define RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_DIGMSBSIGCORR_APPL)  **********/

/* used for references on application variables */
# define RTE_SA_DIGMSBSIGCORR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_DIGMSBSIGCORR_APPL_DATA

/* used for references on application functions */
# define RTE_SA_DIGMSBSIGCORR_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_AP_BATTERYVOLTAGE_APPL)  *********/

/* used for references on application variables */
# define RTE_AP_BATTERYVOLTAGE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_BATTERYVOLTAGE_APPL_DATA

/* used for references on application functions */
# define RTE_AP_BATTERYVOLTAGE_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_AP_POLARITY_APPL)  ***************/

/* used for references on application variables */
# define RTE_AP_POLARITY_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_POLARITY_APPL_DATA

/* used for references on application functions */
# define RTE_AP_POLARITY_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_AP_CTRLDDISSHTDN_APPL)  **********/

/* used for references on application variables */
# define RTE_AP_CTRLDDISSHTDN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CTRLDDISSHTDN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CTRLDDISSHTDN_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_CMMTRCURR_APPL)  **************/

/* used for references on application variables */
# define RTE_SA_CMMTRCURR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_CMMTRCURR_APPL_DATA

/* used for references on application functions */
# define RTE_SA_CMMTRCURR_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_BKCPPC_APPL)  *****************/

/* used for references on application variables */
# define RTE_SA_BKCPPC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_BKCPPC_APPL_DATA

/* used for references on application functions */
# define RTE_SA_BKCPPC_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CD_NHET1_APPL)  ******************/

/* used for references on application variables */
# define RTE_CD_NHET1_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CD_NHET1_APPL_DATA

/* used for references on application functions */
# define RTE_CD_NHET1_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_ANAMSBSNSRIF_APPL)  ***********/

/* used for references on application variables */
# define RTE_SA_ANAMSBSNSRIF_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_ANAMSBSNSRIF_APPL_DATA

/* used for references on application functions */
# define RTE_SA_ANAMSBSNSRIF_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_DIGMSB_APPL)  *****************/

/* used for references on application variables */
# define RTE_SA_DIGMSB_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_DIGMSB_APPL_DATA

/* used for references on application functions */
# define RTE_SA_DIGMSB_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_DIGHWTRQSENT_APPL)  ***********/

/* used for references on application variables */
# define RTE_SA_DIGHWTRQSENT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_DIGHWTRQSENT_APPL_DATA

/* used for references on application functions */
# define RTE_SA_DIGHWTRQSENT_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_ANAMSBARBN_APPL)  *************/

/* used for references on application variables */
# define RTE_SA_ANAMSBARBN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_ANAMSBARBN_APPL_DATA

/* used for references on application functions */
# define RTE_SA_ANAMSBARBN_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_ANAMSBCORRLN_APPL)  ***********/

/* used for references on application variables */
# define RTE_SA_ANAMSBCORRLN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_ANAMSBCORRLN_APPL_DATA

/* used for references on application functions */
# define RTE_SA_ANAMSBCORRLN_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_AP_HWPWUP_APPL)  *****************/

/* used for references on application variables */
# define RTE_AP_HWPWUP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_HWPWUP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_HWPWUP_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_TMPRLMON_APPL)  ***************/

/* used for references on application variables */
# define RTE_SA_TMPRLMON_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_TMPRLMON_APPL_DATA

/* used for references on application functions */
# define RTE_SA_TMPRLMON_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_TMPRLMON2_APPL)  **************/

/* used for references on application variables */
# define RTE_SA_TMPRLMON2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_TMPRLMON2_APPL_DATA

/* used for references on application functions */
# define RTE_SA_TMPRLMON2_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_HWTRQCORRLN_APPL)  ************/

/* used for references on application variables */
# define RTE_SA_HWTRQCORRLN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_HWTRQCORRLN_APPL_DATA

/* used for references on application functions */
# define RTE_SA_HWTRQCORRLN_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_AP_RETURN_APPL)  *****************/

/* used for references on application variables */
# define RTE_AP_RETURN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_RETURN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_RETURN_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_AP_COMMONCAL_APPL)  **************/

/* used for references on application variables */
# define RTE_AP_COMMONCAL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_COMMONCAL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_COMMONCAL_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_AP_STRTSTOP_APPL)  ***************/

/* used for references on application variables */
# define RTE_AP_STRTSTOP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STRTSTOP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STRTSTOP_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_AP_GCCDIAG_APPL)  ****************/

/* used for references on application variables */
# define RTE_AP_GCCDIAG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_GCCDIAG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_GCCDIAG_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1490107833
#    error "The magic number of the generated file <C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/Source/GenDataRte/Rte_Compiler_Cfg.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1490107833
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_COMPILER_CFG_H */
