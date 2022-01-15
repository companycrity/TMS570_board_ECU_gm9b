/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. 
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, Vector Informatik's
 *                liability shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defines for all BSW modules
 *                which where used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component spesific defines filtering added
 *  01.01.02  2008-11-04  Jk                    Component spesific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all oems
 *                                              rename internal variables and filtermethods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#18 %
 * %derived_by:       fz9hxm %
 * %date_modified:    Wed Aug 15 11:14:30 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/15/12  10.1.25  JJW		Allocate all data memory to the Ap_10 application initial user mode application
 * 09/12/12  10.1.26  JJW		Wdg_MemMap.h inclusion added
 * 09/24/12  10.1.30  JJW		New Wdg stack integraton that corrected some MemMap workarounds 
 * 03/18/14  19       BWL       Added new sections for update of DigColPs component.
 * 04/29/14  18.1.15  JWJ       Added HOWDetect component                                                      11664
 * 05/02/14  21		  JWJ       Added IoHwAbstraction 32 bit section.
 * 09/04/14  24       JWJ       Added TSMit component                                                          12315
 * 09/25/14  25       JWJ       Added GenPosTraj Component                                                     12491
 * 10/29/14  26       JWJ       Added GCC diagnosic component                                                  12581
 */
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#undef MEM_VENDOR_ID
#undef MEM_AR_MAJOR_VERSION
#undef MEM_AR_MINOR_VERSION
#undef MEM_AR_PATCH_VERSION
#undef MEM_SW_MAJOR_VERSION
#undef MEM_SW_MINOR_VERSION
#undef MEM_SW_PATCH_VERSION

#define MEM_VENDOR_ID        (30u)
#define MEM_AR_MAJOR_VERSION (1u)                      /* part of Autosare release 3.0.1 */
#define MEM_AR_MINOR_VERSION (1u)
#define MEM_AR_PATCH_VERSION (0u)

#define MEM_SW_MAJOR_VERSION (1u)
#define MEM_SW_MINOR_VERSION (5u)
#define MEM_SW_PATCH_VERSION (4u)

#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */

/* Include these prior to Rte_MemMap, because that file includes Os_MemMap */

#include "Wdg_MemMap.h"
#include "WdgM_MemMap.h"

/* include Rte MemMap because the Rte sections are configuration dependent*/
#include "Rte_MemMap.h"


/**********************************************************************************************************************
 *  TSMit START
 *********************************************************************************************************************/

#if defined TSMIT_START_SEC_VAR_CLEARED_32
	#undef TSMIT_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined TSMIT_STOP_SEC_VAR_CLEARED_32
	#undef TSMIT_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined TSMIT_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TSMIT_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined TSMIT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TSMIT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  TSMit END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SASPlausDiag START
 *********************************************************************************************************************/

#elif defined SASPLAUSDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef SASPLAUSDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined SASPLAUSDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef SASPLAUSDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  SASPlausDiag END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DfltConfigData START
 *********************************************************************************************************************/

#elif defined DFLTCONFIGDATA_START_SEC_VAR_HIDDEN_UNSPECIFIED
	#undef DFLTCONFIGDATA_START_SEC_VAR_HIDDEN_UNSPECIFIED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".hidden")
	#undef MEMMAP_ERROR

#elif defined DFLTCONFIGDATA_STOP_SEC_VAR_HIDDEN_UNSPECIFIED
	#undef DFLTCONFIGDATA_STOP_SEC_VAR_HIDDEN_UNSPECIFIED
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  DfltConfigData END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GenPosTraj START
 *********************************************************************************************************************/

#elif defined GENPOSTRAJ_START_SEC_VAR_CLEARED_32
	#undef GENPOSTRAJ_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined GENPOSTRAJ_STOP_SEC_VAR_CLEARED_32
	#undef GENPOSTRAJ_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined GENPOSTRAJ_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef GENPOSTRAJ_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined GENPOSTRAJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef GENPOSTRAJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined GENPOSTRAJ_START_SEC_VAR_CLEARED_BOOLEAN
	#undef GENPOSTRAJ_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined GENPOSTRAJ_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef GENPOSTRAJ_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  GenPosTraj END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DigHwTrqSENT START
 *********************************************************************************************************************/

#elif defined DIGHWTRQSENT_START_SEC_VAR_CLEARED_32
	#undef DIGHWTRQSENT_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined DIGHWTRQSENT_STOP_SEC_VAR_CLEARED_32
	#undef DIGHWTRQSENT_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined DIGHWTRQSENT_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIGHWTRQSENT_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined DIGHWTRQSENT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIGHWTRQSENT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined DIGHWTRQSENT_START_SEC_VAR_CLEARED_32
	#undef DIGHWTRQSENT_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined DIGHWTRQSENT_STOP_SEC_VAR_CLEARED_32
	#undef DIGHWTRQSENT_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined DIGHWTRQSENT_START_SEC_VAR_SAVED_ZONEH_32
	#undef DIGHWTRQSENT_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:noinit:typeH:DigHwTrqSent")
    #undef MEMMAP_ERROR

#elif defined DIGHWTRQSENT_STOP_SEC_VAR_SAVED_ZONEH_32
	#undef DIGHWTRQSENT_STOP_SEC_VAR_SAVED_ZONEH_32
	#define STOP_SEC_VAR


/**********************************************************************************************************************
 *  DigHwTrqSENT END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StrtStop START
 *********************************************************************************************************************/

#elif defined STRTSTOP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef STRTSTOP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined STRTSTOP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef STRTSTOP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined STRTSTOP_START_SEC_VAR_CLEARED_32
	#undef STRTSTOP_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined STRTSTOP_STOP_SEC_VAR_CLEARED_32
	#undef STRTSTOP_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  StrtStop END
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GmPwrpkSrvDataRcvry START
 *********************************************************************************************************************/

#elif defined GMPWRPKSRVDATARCVRY_START_SEC_VAR_CLEARED_BOOLEAN
	#undef GMPWRPKSRVDATARCVRY_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined GMPWRPKSRVDATARCVRY_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef GMPWRPKSRVDATARCVRY_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined GMPWRPKSRVDATARCVRY_START_SEC_VAR_CLEARED_32
	#undef GMPWRPKSRVDATARCVRY_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined GMPWRPKSRVDATARCVRY_STOP_SEC_VAR_CLEARED_32
	#undef GMPWRPKSRVDATARCVRY_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  GmPwrpkSrvDataRcvry END
 *********************************************************************************************************************/

 
 
/**********************************************************************************************************************
 *  HOWDetect START
 *********************************************************************************************************************/

#elif defined HOWDETECT_START_SEC_VAR_CLEARED_32
	#undef HOWDETECT_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined HOWDETECT_STOP_SEC_VAR_CLEARED_32
	#undef HOWDETECT_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined HOWDETECT_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HOWDETECT_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined HOWDETECT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HOWDETECT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined HOWDETECT_START_SEC_CONST_16
	#undef HOWDETECT_START_SEC_CONST_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined HOWDETECT_STOP_SEC_CONST_16
	#undef HOWDETECT_STOP_SEC_CONST_16
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  HOWDetect END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TrqOsc START
 *********************************************************************************************************************/

#elif defined TRQOSC_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRQOSC_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined TRQOSC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRQOSC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined TRQOSC_START_SEC_VAR_CLEARED_BOOLEAN
	#undef TRQOSC_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined TRQOSC_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef TRQOSC_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined TRQOSC_START_SEC_VAR_CLEARED_32
	#undef TRQOSC_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined TRQOSC_STOP_SEC_VAR_CLEARED_32
	#undef TRQOSC_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR


/**********************************************************************************************************************
 *  TrqOsc END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PosServo START
 *********************************************************************************************************************/

#elif defined POSSERVO_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef POSSERVO_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined POSSERVO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef POSSERVO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined POSSERVO_START_SEC_VAR_CLEARED_BOOLEAN
	#undef POSSERVO_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined POSSERVO_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef POSSERVO_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined POSSERVO_START_SEC_VAR_CLEARED_32
	#undef POSSERVO_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined POSSERVO_STOP_SEC_VAR_CLEARED_32
	#undef POSSERVO_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined POSSERVO_START_SEC_VAR_CLEARED_16
	#undef POSSERVO_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined POSSERVO_STOP_SEC_VAR_CLEARED_16
	#undef POSSERVO_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR


/**********************************************************************************************************************
 *  PosServo END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PwrDscntDuInv START
 *********************************************************************************************************************/
#elif defined PWRDSCNTDUINV_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PWRDSCNTDUINV_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined PWRDSCNTDUINV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PWRDSCNTDUINV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined PWRDSCNTDUINV_START_SEC_VAR_CLEARED_BOOLEAN
	#undef PWRDSCNTDUINV_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined PWRDSCNTDUINV_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef PWRDSCNTDUINV_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined PWRDSCNTDUINV_START_SEC_VAR_CLEARED_32
	#undef PWRDSCNTDUINV_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined PWRDSCNTDUINV_STOP_SEC_VAR_CLEARED_32
	#undef PWRDSCNTDUINV_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  PwrDscntDuInv END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DigMSB START
 *********************************************************************************************************************/


#elif defined DIGMSB_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIGMSB_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined DIGMSB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIGMSB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined DIGMSB_START_SEC_VAR_CLEARED_8
	#undef DIGMSB_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined DIGMSB_STOP_SEC_VAR_CLEARED_8
	#undef DIGMSB_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined DIGMSB_START_SEC_VAR_CLEARED_16
	#undef DIGMSB_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined DIGMSB_STOP_SEC_VAR_CLEARED_16
	#undef DIGMSB_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined DIGMSB_START_SEC_VAR_CLEARED_32
	#undef DIGMSB_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined DIGMSB_STOP_SEC_VAR_CLEARED_32
	#undef DIGMSB_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined DIGMSB_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DIGMSB_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined DIGMSB_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DIGMSB_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined DIGMSB_START_SEC_CONST_8
	#undef DIGMSB_START_SEC_CONST_8
	#define START_SEC_CONST_8BIT

#elif defined DIGMSB_STOP_SEC_CONST_8
	#undef DIGMSB_STOP_SEC_CONST_8
	#define STOP_SEC_CONST

/**********************************************************************************************************************
 *  DigMSB End
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrVel Start
 *********************************************************************************************************************/
#elif defined MTRVEL_START_SEC_VAR_CLEARED_32
	#undef MTRVEL_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined MTRVEL_STOP_SEC_VAR_CLEARED_32
	#undef MTRVEL_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined MTRVEL_START_SEC_VAR_CLEARED_16
	#undef MTRVEL_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined MTRVEL_STOP_SEC_VAR_CLEARED_16
	#undef MTRVEL_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined MTRVEL_START_SEC_VAR_CLEARED_8
	#undef MTRVEL_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined MTRVEL_STOP_SEC_VAR_CLEARED_8
	#undef MTRVEL_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined MTRVEL2_START_SEC_VAR_CLEARED_16
	#undef MTRVEL2_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_8

#elif defined MTRVEL2_STOP_SEC_VAR_CLEARED_16
	#undef MTRVEL2_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined MTRVEL2_START_SEC_VAR_CLEARED_32
	#undef MTRVEL2_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_8

#elif defined MTRVEL2_STOP_SEC_VAR_CLEARED_32
	#undef MTRVEL2_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined MTRVEL3_START_SEC_VAR_CLEARED_8
	#undef MTRVEL3_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined MTRVEL3_STOP_SEC_VAR_CLEARED_8
	#undef MTRVEL3_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined MTRVEL3_START_SEC_VAR_CLEARED_16
	#undef MTRVEL3_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined MTRVEL3_STOP_SEC_VAR_CLEARED_16
	#undef MTRVEL3_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined MTRVEL3_START_SEC_VAR_CLEARED_32
	#undef MTRVEL3_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_16_10

#elif defined MTRVEL3_STOP_SEC_VAR_CLEARED_32
	#undef MTRVEL3_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  MtrVel End
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SpiNxt Start
 *********************************************************************************************************************/

#elif defined SPINXT_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef SPINXT_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_0

#elif defined SPINXT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef SPINXT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined SPINXT_START_SEC_CODE
	#undef SPINXT_START_SEC_CODE
	#define START_SEC_CODE

#elif defined SPINXT_STOP_SEC_CODE
	#undef SPINXT_STOP_SEC_CODE
	#define STOP_SEC_CODE

/**********************************************************************************************************************
 *  SpiNxt Start
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FltInjection START
 *********************************************************************************************************************/

#elif defined FLTINJECTION_START_SEC_VAR_CLEARED_32
	#undef FLTINJECTION_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_9

#elif defined FLTINJECTION_STOP_SEC_VAR_CLEARED_32
	#undef FLTINJECTION_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined FLTINJECTION_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FLTINJECTION_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined FLTINJECTION_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FLTINJECTION_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined DIGHWTRQSENT_START_SEC_VAR_SAVED_ZONEH_32
	#undef DIGHWTRQSENT_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:noinit:typeH:DigHwTrqSent")
    #undef MEMMAP_ERROR

#elif defined DIGHWTRQSENT_STOP_SEC_VAR_SAVED_ZONEH_32
	#undef DIGHWTRQSENT_STOP_SEC_VAR_SAVED_ZONEH_32
	#define STOP_SEC_VAR


/**********************************************************************************************************************
 *  FltInjection END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FlsTst START
 *********************************************************************************************************************/

#elif defined FLSTST_START_SEC_VAR_UNSPECIFIED
#undef FLSTST_START_SEC_VAR_UNSPECIFIED
#define START_SEC_VAR_INIT_UNSPECIFIED_0

#elif defined FLSTST_STOP_SEC_VAR_UNSPECIFIED
#undef FLSTST_STOP_SEC_VAR_UNSPECIFIED
#define STOP_SEC_VAR

#elif defined FLSTST_START_SEC_VAR_16
#undef FLSTST_START_SEC_VAR_16
#define START_SEC_VAR_INIT_16_0

#elif defined FLSTST_STOP_SEC_VAR_16
#undef FLSTST_STOP_SEC_VAR_16
#define STOP_SEC_VAR

#elif defined FLSTST_START_SEC_VAR_CLEARED_8
#undef FLSTST_START_SEC_VAR_CLEARED_8
#define START_SEC_VAR_CLEARED_8_0

#elif defined FLSTST_STOP_SEC_VAR_CLEARED_8
#undef FLSTST_STOP_SEC_VAR_CLEARED_8
#define STOP_SEC_VAR

#elif defined FLSTST_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef FLSTST_START_SEC_VAR_CLEARED_UNSPECIFIED
#define START_SEC_VAR_CLEARED_UNSPECIFIED_0

#elif defined FLSTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef FLSTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#define STOP_SEC_VAR

#elif defined FLSTST_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR
#undef FLSTST_START_SEC_CONST_UNSPECIFIED

#elif defined FLSTST_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR
#undef FLSTST_STOP_SEC_CONST_UNSPECIFIED

#elif defined FLSTST_START_SEC_CODE
#undef MEMMAP_ERROR
#undef FLSTST_START_SEC_CODE

#elif defined FLSTST_STOP_SEC_CODE
#undef MEMMAP_ERROR
#undef FLSTST_STOP_SEC_CODE

/**********************************************************************************************************************
 *  FlsTst END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  IOHWAB10 Start
 *********************************************************************************************************************/
/* Variables */
#elif defined IOHWAB10_START_SEC_VAR_CLEARED_16
    #undef IOHWAB10_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined IOHWAB10_STOP_SEC_VAR_CLEARED_16
	#undef IOHWAB10_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined IOHWAB10_START_SEC_VAR_CLEARED_32
    #undef IOHWAB10_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined IOHWAB10_STOP_SEC_VAR_CLEARED_32
	#undef IOHWAB10_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
/**********************************************************************************************************************
 *  IOHWAB10 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TranlDampg Start
 *********************************************************************************************************************/
/* Variables */
#elif defined TRANLDAMPG_START_SEC_VAR_CLEARED_08
	#undef TRANLDAMPG_START_SEC_VAR_CLEARED_08
	#define START_SEC_VAR_CLEARED_8_10

#elif defined TRANLDAMPG_STOP_SEC_VAR_CLEARED_08
	#undef TRANLDAMPG_STOP_SEC_VAR_CLEARED_08
	#define STOP_SEC_VAR

#elif defined TRANLDAMPG_START_SEC_VAR_CLEARED_16
	#undef TRANLDAMPG_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined TRANLDAMPG_STOP_SEC_VAR_CLEARED_16
	#undef TRANLDAMPG_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined TRANLDAMPG_START_SEC_VAR_CLEARED_32
	#undef TRANLDAMPG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined TRANLDAMPG_STOP_SEC_VAR_CLEARED_32
	#undef TRANLDAMPG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined TRANLDAMPG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef TRANLDAMPG_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined TRANLDAMPG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef TRANLDAMPG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined TRANLDAMPG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRANLDAMPG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined TRANLDAMPG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRANLDAMPG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  TranlDampg END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TrqArbLim Start
 *********************************************************************************************************************/
/* Variables */
#elif defined TRQARBLIM_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRQARBLIM_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined TRQARBLIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRQARBLIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined TRQARBLIM_START_SEC_VAR_CLEARED_32
	#undef TRQARBLIM_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined TRQARBLIM_STOP_SEC_VAR_CLEARED_32
	#undef TRQARBLIM_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  TrqArbLim END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TrqLOA Start
 *********************************************************************************************************************/
/* Variables */
#elif defined TRQLOA_START_SEC_VAR_CLEARED_32
	#undef TRQLOA_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined TRQLOA_STOP_SEC_VAR_CLEARED_32
	#undef TRQLOA_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined TRQLOA_START_SEC_VAR_CLEARED_BOOLEAN
	#undef TRQLOA_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined TRQLOA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef TRQLOA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined TRQLOA_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRQLOA_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined TRQLOA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRQLOA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  TrqLOA END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TrqOvlSta Start
 *********************************************************************************************************************/
/* Variables */
#elif defined TRQOVLSTA_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TRQOVLSTA_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined TRQOVLSTA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TRQOVLSTA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined TRQOVLSTA_START_SEC_VAR_CLEARED_32
    #undef TRQOVLSTA_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined TRQOVLSTA_STOP_SEC_VAR_CLEARED_32
	#undef TRQOVLSTA_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined TRQOVLSTA_START_SEC_VAR_CLEARED_16
    #undef TRQOVLSTA_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined TRQOVLSTA_STOP_SEC_VAR_CLEARED_16
	#undef TRQOVLSTA_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined TRQOVLSTA_START_SEC_VAR_CLEARED_8
    #undef TRQOVLSTA_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined TRQOVLSTA_STOP_SEC_VAR_CLEARED_8
	#undef TRQOVLSTA_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined TRQOVLSTA_START_SEC_VAR_CLEARED_BOOLEAN
    #undef TRQOVLSTA_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined TRQOVLSTA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef TRQOVLSTA_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  TrqOvlSta END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EPS XCP Services Start
 *********************************************************************************************************************/
/* Variables */
#elif defined EPSXCPSRVC_START_SEC_VAR_16
    #undef EPSXCPSRVC_START_SEC_VAR_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined EPSXCPSRVC_STOP_SEC_VAR_16
	#undef EPSXCPSRVC_STOP_SEC_VAR_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  EPS XCP Services End
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AppDesc START
 *********************************************************************************************************************/
/* NvM */
#elif defined APPDESC_START_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:AppDesc")
	#undef MEMMAP_ERROR
    #undef APPDESC_START_SEC_VAR_SAVED_ZONEH_UNSPECIFIED

#elif defined APPDESC_STOP_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #undef APPDESC_STOP_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  AppDesc END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CmMtrCurr START
 *********************************************************************************************************************/
/* Variables */
#elif defined CMMTRCURR_START_SEC_VAR_CLEARED_16
    #undef CMMTRCURR_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined CMMTRCURR_STOP_SEC_VAR_CLEARED_16
    #undef CMMTRCURR_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined CMMTRCURR_START_SEC_VAR_CLEARED_32
    #undef CMMTRCURR_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined CMMTRCURR_STOP_SEC_VAR_CLEARED_32
    #undef CMMTRCURR_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CMMTRCURR_START_SEC_VAR_CLEARED_BOOLEAN
    #undef CMMTRCURR_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_8_10

#elif defined CMMTRCURR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef CMMTRCURR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined CMMTRCURR_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CMMTRCURR_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined CMMTRCURR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CMMTRCURR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  CmMtrCurr END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CmMtrCurr3Phs START
 *********************************************************************************************************************/
/* Variables */
#elif defined CMMTRCURR3PHS_START_SEC_VAR_CLEARED_8
    #undef CMMTRCURR3PHS_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined CMMTRCURR3PHS_STOP_SEC_VAR_CLEARED_8
    #undef CMMTRCURR3PHS_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined CMMTRCURR3PHS_START_SEC_VAR_CLEARED_16
    #undef CMMTRCURR3PHS_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined CMMTRCURR3PHS_STOP_SEC_VAR_CLEARED_16
    #undef CMMTRCURR3PHS_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined CMMTRCURR3PHS_START_SEC_VAR_CLEARED_32
    #undef CMMTRCURR3PHS_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined CMMTRCURR3PHS_STOP_SEC_VAR_CLEARED_32
    #undef CMMTRCURR3PHS_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CMMTRCURR3PHS_START_SEC_VAR_CLEARED_BOOLEAN
    #undef CMMTRCURR3PHS_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_8_10

#elif defined CMMTRCURR3PHS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef CMMTRCURR3PHS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined CMMTRCURR3PHS_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CMMTRCURR3PHS_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined CMMTRCURR3PHS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CMMTRCURR3PHS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  CmMtrCurr3Phs END
 *********************************************************************************************************************/


/**********************************************************************************************************************
*  AstLmt START
*********************************************************************************************************************/

#elif defined ASTLMT_START_SEC_VAR_CLEARED_16
    #undef ASTLMT_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined ASTLMT_STOP_SEC_VAR_CLEARED_16
    #undef ASTLMT_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined ASTLMT_START_SEC_VAR_CLEARED_32
    #undef ASTLMT_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined ASTLMT_STOP_SEC_VAR_CLEARED_32
    #undef ASTLMT_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined ASTLMT_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ASTLMT_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined ASTLMT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ASTLMT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined ASTLMT_START_SEC_VAR_CLEARED_BOOLEAN
    #undef ASTLMT_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined ASTLMT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef ASTLMT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  AstLmt END
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  BkCpPc START
*********************************************************************************************************************/

#elif defined BKCPPC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BKCPPC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined BKCPPC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BKCPPC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined BKCPPC_START_SEC_VAR_CLEARED_32
    #undef BKCPPC_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined BKCPPC_STOP_SEC_VAR_CLEARED_32
    #undef BKCPPC_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined BKCPPC_START_SEC_VAR_CLEARED_16
    #undef BKCPPC_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined BKCPPC_STOP_SEC_VAR_CLEARED_16
    #undef BKCPPC_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  BkCpPc END
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  EPSDIAGSRVC START
*********************************************************************************************************************/

#elif defined EPSDIAGSRVC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined EPSDIAGSRVC_START_SEC_VAR_CLEARED_BOOLEAN
    #undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined EPSDIAGSRVC_START_SEC_VAR_CLEARED_32
    #undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_32
    #undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined EPSDIAGSRVC_START_SEC_VAR_CLEARED_16
    #undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_16
    #undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined EPSXCPSRVC_START_SEC_VAR_CLEARED_16
    #undef EPSXCPSRVC_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined EPSXCPSRVC_STOP_SEC_VAR_CLEARED_16
    #undef EPSXCPSRVC_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined EPSDIAGSRVC_START_SEC_VAR_CLEARED_8
    #undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_8
    #undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined EPSDIAGSRVC_START_SEC_CONST_8
	#undef MEMMAP_ERROR
    #undef EPSDIAGSRVC_START_SEC_CONST_8

#elif defined EPSDIAGSRVC_STOP_SEC_CONST_8
	#undef MEMMAP_ERROR
    #undef EPSDIAGSRVC_STOP_SEC_CONST_8

/**********************************************************************************************************************
 *  EPSDIAGSRVC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  DigColPs START
*********************************************************************************************************************/

#elif defined DIGCOLPS_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIGCOLPS_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined DIGCOLPS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIGCOLPS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined DIGCOLPS_START_SEC_VAR_CLEARED_BOOLEAN
    #undef DIGCOLPS_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined DIGCOLPS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef DIGCOLPS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined DIGCOLPS_START_SEC_VAR_CLEARED_32
    #undef DIGCOLPS_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined DIGCOLPS_STOP_SEC_VAR_CLEARED_32
    #undef DIGCOLPS_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DIGCOLPS_START_SEC_VAR_CLEARED_16
    #undef DIGCOLPS_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined DIGCOLPS_STOP_SEC_VAR_CLEARED_16
    #undef DIGCOLPS_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DIGCOLPS_START_SEC_VAR_CLEARED_8
    #undef DIGCOLPS_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined DIGCOLPS_STOP_SEC_VAR_CLEARED_8
    #undef DIGCOLPS_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined DIGCOLPS_START_SEC_CONST_16
	#undef MEMMAP_ERROR
    #undef DIGCOLPS_START_SEC_CONST_16

#elif defined DIGCOLPS_STOP_SEC_CONST_16
	#undef MEMMAP_ERROR
    #undef DIGCOLPS_STOP_SEC_CONST_16

/**********************************************************************************************************************
 *  DigColPs END
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  DigColPsInt START
*********************************************************************************************************************/

#elif defined DIGCOLPSINT_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIGCOLPSINT_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined DIGCOLPSINT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIGCOLPSINT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined DIGCOLPSINT_START_SEC_VAR_CLEARED_BOOLEAN
    #undef DIGCOLPSINT_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined DIGCOLPSINT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef DIGCOLPSINT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined DIGCOLPSINT_START_SEC_VAR_CLEARED_32
    #undef DIGCOLPSINT_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined DIGCOLPSINT_STOP_SEC_VAR_CLEARED_32
    #undef DIGCOLPSINT_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DIGCOLPSINT_START_SEC_VAR_CLEARED_16
    #undef DIGCOLPSINT_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined DIGCOLPSINT_STOP_SEC_VAR_CLEARED_16
    #undef DIGCOLPSINT_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DIGCOLPSINT_START_SEC_VAR_CLEARED_8
    #undef DIGCOLPSINT_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined DIGCOLPSINT_STOP_SEC_VAR_CLEARED_8
    #undef DIGCOLPSINT_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined DIGCOLPSINT_START_SEC_CONST_8
	#undef MEMMAP_ERROR
    #undef DIGCOLPSINT_START_SEC_CONST_8

#elif defined DIGCOLPSINT_STOP_SEC_CONST_8
	#undef MEMMAP_ERROR
    #undef DIGCOLPSINT_STOP_SEC_CONST_8


/**********************************************************************************************************************
 *  DigColPsInt END
 *********************************************************************************************************************/


/**********************************************************************************************************************
*  I2cNxtr START
*********************************************************************************************************************/

#elif defined I2CNXTR_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef I2CNXTR_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined I2CNXTR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef I2CNXTR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  I2cNxtr END
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  VehDyn START
*********************************************************************************************************************/

#elif defined VEHDYN_START_SEC_VAR_CLEARED_32
    #undef VEHDYN_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined VEHDYN_STOP_SEC_VAR_CLEARED_32
    #undef VEHDYN_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined VEHDYN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef VEHDYN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined VEHDYN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef VEHDYN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined VEHDYN_START_SEC_VAR_CLEARED_BOOLEAN
    #undef VEHDYN_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined VEHDYN_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef VEHDYN_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  VehDyn END
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  AbsHwPos START
*********************************************************************************************************************/

#elif defined ABSHWPOS_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ABSHWPOS_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined ABSHWPOS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ABSHWPOS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined ABSHWPOS_START_SEC_VAR_CLEARED_BOOLEAN
    #undef ABSHWPOS_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined ABSHWPOS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef ABSHWPOS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined ABSHWPOS_START_SEC_VAR_CLEARED_32
    #undef ABSHWPOS_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined ABSHWPOS_STOP_SEC_VAR_CLEARED_32
    #undef ABSHWPOS_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined ABSHWPOS_START_SEC_VAR_CLEARED_16
    #undef ABSHWPOS_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined ABSHWPOS_STOP_SEC_VAR_CLEARED_16
    #undef ABSHWPOS_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined ABSHWPOS_START_SEC_VAR_CLEARED_8
    #undef ABSHWPOS_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined ABSHWPOS_STOP_SEC_VAR_CLEARED_8
    #undef ABSHWPOS_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  AbsHwPos END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DiagMgr START
 *********************************************************************************************************************/
/* NvM */
#elif defined DIAGMGR_START_SEC_VAR_SAVED_ZONEHGS_UNSPECIFIED
    #undef DIAGMGR_START_SEC_VAR_SAVED_ZONEHGS_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED

#elif defined DIAGMGR_STOP_SEC_VAR_SAVED_ZONEHGS_UNSPECIFIED
    #undef DIAGMGR_STOP_SEC_VAR_SAVED_ZONEHGS_UNSPECIFIED
    #define STOP_SEC_VAR

/* Variables */
#elif defined DIAGMGR_START_SEC_VAR_CLEARED_BOOLEAN
    #undef DIAGMGR_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED

#elif defined DIAGMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef DIAGMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

	/*DiagMgr8*/
#elif defined DIAGMGR8_START_SEC_VAR_CLEARED_8
    #undef DIAGMGR8_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_8

#elif defined DIAGMGR8_STOP_SEC_VAR_CLEARED_8
    #undef DIAGMGR8_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined DIAGMGR8_START_SEC_VAR_CLEARED_16
    #undef DIAGMGR8_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_8

#elif defined DIAGMGR8_STOP_SEC_VAR_CLEARED_16
    #undef DIAGMGR8_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DIAGMGR8_START_SEC_VAR_CLEARED_32
    #undef DIAGMGR8_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_8

#elif defined DIAGMGR8_STOP_SEC_VAR_CLEARED_32
    #undef DIAGMGR8_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DIAGMGR8_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR8_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_8

#elif defined DIAGMGR8_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR8_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

	/*DiagMgr9*/
#elif defined DIAGMGR9_START_SEC_VAR_CLEARED_8
    #undef DIAGMGR9_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined DIAGMGR9_STOP_SEC_VAR_CLEARED_8
    #undef DIAGMGR9_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined DIAGMGR9_START_SEC_VAR_CLEARED_16
    #undef DIAGMGR9_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined DIAGMGR9_STOP_SEC_VAR_CLEARED_16
    #undef DIAGMGR9_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DIAGMGR9_START_SEC_VAR_CLEARED_32
    #undef DIAGMGR9_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined DIAGMGR9_STOP_SEC_VAR_CLEARED_32
    #undef DIAGMGR9_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DIAGMGR9_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR9_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined DIAGMGR9_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR9_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

	/*DiagMgr10*/
#elif defined DIAGMGR10_START_SEC_VAR_CLEARED_8
    #undef DIAGMGR10_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined DIAGMGR10_STOP_SEC_VAR_CLEARED_8
    #undef DIAGMGR10_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined DIAGMGR10_START_SEC_VAR_CLEARED_16
    #undef DIAGMGR10_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined DIAGMGR10_STOP_SEC_VAR_CLEARED_16
    #undef DIAGMGR10_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DIAGMGR10_START_SEC_VAR_CLEARED_32
    #undef DIAGMGR10_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined DIAGMGR10_STOP_SEC_VAR_CLEARED_32
    #undef DIAGMGR10_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DIAGMGR10_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR10_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined DIAGMGR10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined DIAGMGR_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
    #undef DIAGMGR_START_SEC_CONST_UNSPECIFIED

#elif defined DIAGMGR_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
	#undef DIAGMGR_STOP_SEC_CONST_UNSPECIFIED

/**********************************************************************************************************************
 *  DiagMgr END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DiagMgrDemIf START
 *********************************************************************************************************************/
#elif defined DIAGMGRDEMIF_START_SEC_VAR_16
	#undef DIAGMGRDEMIF_START_SEC_VAR_16
	#define START_SEC_VAR_CLEARED_16_GLOBALSHARED

#elif defined DIAGMGRDEMIF_STOP_SEC_VAR_16
	#undef DIAGMGRDEMIF_STOP_SEC_VAR_16
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  DiagMgrDemIf END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  uDiag START
 *********************************************************************************************************************/

/* Variables */
#elif defined UDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef UDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10

#elif defined UDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef UDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined UDIAG_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
    #undef UDIAG_START_SEC_CONST_UNSPECIFIED

#elif defined UDIAG_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
    #undef UDIAG_STOP_SEC_CONST_UNSPECIFIED

#elif defined  UDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    #undef UDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10

#elif defined UDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef UDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined UDIAG_START_SEC_VAR_CLEARED_16
    #undef UDIAG_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10

#elif defined UDIAG_STOP_SEC_VAR_CLEARED_16
    #undef UDIAG_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined UDIAG_START_SEC_VAR_CLEARED_32
    #undef UDIAG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10

#elif defined UDIAG_STOP_SEC_VAR_CLEARED_32
    #undef UDIAG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined WDGRESETHANDLER_START_SEC_VAR_POWER_ON_CLEARED_8
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".noclear")
	#undef MEMMAP_ERROR
    #undef WDGRESETHANDLER_START_SEC_VAR_POWER_ON_CLEARED_8

#elif defined WDGRESETHANDLER_STOP_SEC_VAR_POWER_ON_CLEARED_8
    #undef WDGRESETHANDLER_STOP_SEC_VAR_POWER_ON_CLEARED_8
    #define STOP_SEC_VAR

#elif defined UDIAG_START_SEC_VAR_SAVED_UNSPECIFIED
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".noclear")
	#undef MEMMAP_ERROR
    #undef UDIAG_START_SEC_VAR_SAVED_UNSPECIFIED

#elif defined UDIAG_STOP_SEC_VAR_SAVED_UNSPECIFIED
    #undef UDIAG_STOP_SEC_VAR_SAVED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  uDiag END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TMS570_Startup START
 *********************************************************************************************************************/
#elif defined RESETCAUSE_START_SEC_VAR_POWER_ON_CLEARED_8
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".resetcause")
	#undef MEMMAP_ERROR
    #undef RESETCAUSE_START_SEC_VAR_POWER_ON_CLEARED_8

#elif defined RESETCAUSE_STOP_SEC_VAR_POWER_ON_CLEARED_8
    #undef RESETCAUSE_STOP_SEC_VAR_POWER_ON_CLEARED_8
    #define STOP_SEC_VAR

#elif defined STARTUP_START_SEC_VAR_NOINIT_32
    #undef STARTUP_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_10

#elif defined STARTUP_STOP_SEC_VAR_NOINIT_32
    #undef STARTUP_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR

#elif defined STARTUP_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef STARTUP_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10

#elif defined STARTUP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef STARTUP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR


/**********************************************************************************************************************
 *  TMS570_Startup END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ShtdnMech START
 *********************************************************************************************************************/

/* Variables */
#elif defined SHTDNMECH_START_SEC_VAR_CLEARED_8
    #undef SHTDNMECH_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined SHTDNMECH_STOP_SEC_VAR_CLEARED_8
    #undef SHTDNMECH_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined SHTDNMECH_START_SEC_VAR_CLEARED_32
    #undef SHTDNMECH_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined SHTDNMECH_STOP_SEC_VAR_CLEARED_32
    #undef SHTDNMECH_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  ShtdnMech END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SnsrOffsLrng START
 *********************************************************************************************************************/

/* Variables */
#elif defined SNSROFFSLRNG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef SNSROFFSLRNG_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined SNSROFFSLRNG_START_SEC_VAR_CLEARED_8
	#undef SNSROFFSLRNG_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_9

#elif defined SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_8
	#undef SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined SNSROFFSLRNG_START_SEC_VAR_CLEARED_16
	#undef SNSROFFSLRNG_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_9

#elif defined SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_16
	#undef SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined SNSROFFSLRNG_START_SEC_VAR_CLEARED_32
	#undef SNSROFFSLRNG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_9

#elif defined SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_32
	#undef SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined SNSROFFSLRNG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef SNSROFFSLRNG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef SNSROFFSLRNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  SnsrOffsLrng END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PwmCdd START
 *********************************************************************************************************************/

/* Variables */
#elif defined PWMCDD_START_SEC_VAR_CLEARED_16
    #undef PWMCDD_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined PWMCDD_STOP_SEC_VAR_CLEARED_16
    #undef PWMCDD_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  PwmCdd END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  WIRInputQual START
 *********************************************************************************************************************/

/* Variables */
#elif defined WIRINPUTQUAL_START_SEC_VAR_CLEARED_32
    #undef WIRINPUTQUAL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined WIRINPUTQUAL_STOP_SEC_VAR_CLEARED_32
    #undef WIRINPUTQUAL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined WIRINPUTQUAL_START_SEC_VAR_CLEARED_16
    #undef WIRINPUTQUAL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined WIRINPUTQUAL_STOP_SEC_VAR_CLEARED_16
    #undef WIRINPUTQUAL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  WIRInputQual END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  TqRsDg START
 *********************************************************************************************************************/
/* Variables */
#elif defined TQRSDG_START_SEC_VAR_CLEARED_32
    #undef TQRSDG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined TQRSDG_STOP_SEC_VAR_CLEARED_32
    #undef TQRSDG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined TQRSDG_START_SEC_VAR_CLEARED_16
    #undef TQRSDG_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined TQRSDG_STOP_SEC_VAR_CLEARED_16
    #undef TQRSDG_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined TQRSDG_START_SEC_VAR_CLEARED_8
    #undef TQRSDG_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined TQRSDG_STOP_SEC_VAR_CLEARED_8
    #undef TQRSDG_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined TQRSDG_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef TQRSDG_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10

#elif defined TQRSDG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef TQRSDG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  TqRsDg END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  Nhet START
 *********************************************************************************************************************/

#elif defined NHET_START_SEC_CODE
    #undef NHET_START_SEC_CODE
    #define START_SEC_CODE

#elif defined NHET_STOP_SEC_CODE
    #undef NHET_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined NHET_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef NHET_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_0

#elif defined NHET_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef NHET_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined NHET_START_SEC_VAR_CLEARED_BOOLEAN
    #undef NHET_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_0

#elif defined NHET_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef NHET_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  Nhet END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Nhet1CfgAndUse START
 *********************************************************************************************************************/
#elif defined NHET1CFGANDUSE_START_SEC_CONST_8
	#undef NHET1CFGANDUSE_START_SEC_CONST_8
	#define START_SEC_CONST_8BIT

#elif defined NHET1CFGANDUSE_STOP_SEC_CONST_8
	#undef NHET1CFGANDUSE_STOP_SEC_CONST_8
	#define STOP_SEC_CONST

#elif defined NHET1CFGANDUSE_START_SEC_VAR_CLEARED_BOOLEAN
	#undef NHET1CFGANDUSE_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined NHET1CFGANDUSE_START_SEC_VAR_CLEARED_8
	#undef NHET1CFGANDUSE_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_8
	#undef NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined NHET1CFGANDUSE_START_SEC_VAR_CLEARED_32
	#undef NHET1CFGANDUSE_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_32
	#undef NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined NHET1CFGANDUSE_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef NHET1CFGANDUSE_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef NHET1CFGANDUSE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  Nhet1CfgAndUse END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ePWM START
 *********************************************************************************************************************/

#elif defined EPWM_START_SEC_CODE
    #undef EPWM_START_SEC_CODE
    #define START_SEC_CODE

#elif defined EPWM_STOP_SEC_CODE
    #undef EPWM_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined EPWM_START_SEC_VAR_CLEARED_16
    #undef EPWM_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined EPWM_STOP_SEC_VAR_CLEARED_16
    #undef EPWM_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  ePWM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  QuadDet START
 *********************************************************************************************************************/

/* Variables */
#elif defined QUADDET_START_SEC_VAR_INIT_32
    #undef QUADDET_START_SEC_VAR_INIT_32
    #define START_SEC_VAR_INIT_32_10

#elif defined QUADDET_STOP_SEC_VAR_INIT_32
    #undef QUADDET_STOP_SEC_VAR_INIT_32
    #define STOP_SEC_VAR

#elif defined QUADDET_START_SEC_VAR_INIT_8
    #undef QUADDET_START_SEC_VAR_INIT_8
    #define START_SEC_VAR_INIT_8_10

#elif defined QUADDET_STOP_SEC_VAR_INIT_8
    #undef QUADDET_STOP_SEC_VAR_INIT_8
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  QuadDet END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CDD_Data START
 *********************************************************************************************************************/

/* Variables */
#elif defined CDD_START_SEC_VAR_CLEARED_32
    #undef CDD_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined CDD_STOP_SEC_VAR_CLEARED_32
    #undef CDD_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CDD_START_SEC_VAR_CLEARED_16
    #undef CDD_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined CDD_STOP_SEC_VAR_CLEARED_16
    #undef CDD_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined CDD_START_SEC_VAR_CLEARED_8
    #undef CDD_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined CDD_STOP_SEC_VAR_CLEARED_8
    #undef CDD_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined CDD_START_SEC_VAR_CLEARED_BOOLEAN
    #undef CDD_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined CDD_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef CDD_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined CDD_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CDD_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined CDD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CDD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined CDD9_START_SEC_VAR_CLEARED_32
    #undef CDD9_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined CDD9_STOP_SEC_VAR_CLEARED_32
    #undef CDD9_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CDD9_START_SEC_VAR_CLEARED_16
    #undef CDD9_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined CDD9_STOP_SEC_VAR_CLEARED_16
    #undef CDD9_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined CDD9_START_SEC_VAR_CLEARED_BOOLEAN
    #undef CDD9_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined CDD9_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef CDD9_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  CDD_Data END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CtrldDisShtdn START
 *********************************************************************************************************************/

/* Variables */
#elif defined CTRLDDISSHTDN_START_SEC_VAR_CLEARED_32
    #undef CTRLDDISSHTDN_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined CTRLDDISSHTDN_STOP_SEC_VAR_CLEARED_32
    #undef CTRLDDISSHTDN_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CTRLDDISSHTDN_START_SEC_VAR_CLEARED_16
    #undef CTRLDDISSHTDN_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined CTRLDDISSHTDN_STOP_SEC_VAR_CLEARED_16
    #undef CTRLDDISSHTDN_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR


/**********************************************************************************************************************
 *  CtrldDisShtdn END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  OvrVoltMon START
 *********************************************************************************************************************/

/* Variables */
#elif defined OVRVOLTMON_START_SEC_VAR_CLEARED_16
    #undef OVRVOLTMON_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined OVRVOLTMON_STOP_SEC_VAR_CLEARED_16
    #undef OVRVOLTMON_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  OvrVoltMon END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PhaseFdbkMeas START
 *********************************************************************************************************************/
/* Variables */
#elif defined PHASEFDBKMEAS_START_SEC_VAR_CLEARED_32
# undef PHASEFDBKMEAS_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_CLEARED_32_10

#elif defined PHASEFDBKMEAS_STOP_SEC_VAR_CLEARED_32
# undef PHASEFDBKMEAS_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR
/**********************************************************************************************************************
 *  PhaseFdbkMeas END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ThrmlDutyCycle START
 *********************************************************************************************************************/
/* Type H Variables */
#elif defined THRMLDUTYCYCLE_START_SEC_VAR_SAVED_ZONEH_8
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:ThrmlDutyCycle")
    #undef THRMLDUTYCYCLE_START_SEC_VAR_SAVED_ZONEH_8
    #undef MEMMAP_ERROR

#elif defined THRMLDUTYCYCLE_STOP_SEC_VAR_SAVED_ZONEH_8
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_SAVED_ZONEH_8
    #define STOP_SEC_VAR

/* Variables */
#elif defined THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_8
    #undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_8
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_16
    #undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_16
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_32
    #undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_32
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined THRMLDUTYCYCLE_STARTP_SEC_VAR_CLEARED_BOOLEAN
	#undef THRMLDUTYCYCLE_STARTP_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  ThrmlDutyCycle END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CustPerSrvcs START
 *********************************************************************************************************************/
/* Type H Variables */
#elif defined CUSTPERSRVCS_START_SEC_VAR_SAVED_ZONEH_8
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:CustPerSrvcs")
    #undef CUSTPERSRVCS_START_SEC_VAR_SAVED_ZONEH_8
    #undef MEMMAP_ERROR

#elif defined CUSTPERSRVCS_STOP_SEC_VAR_SAVED_ZONEH_8
    #undef CUSTPERSRVCS_STOP_SEC_VAR_SAVED_ZONEH_8
    #define STOP_SEC_VAR

/* Variables */
#elif defined CUSTPERSRVCS_START_SEC_VAR_CLEARED_32
    #undef CUSTPERSRVCS_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined CUSTPERSRVCS_STOP_SEC_VAR_CLEARED_32
    #undef CUSTPERSRVCS_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CUSTPERSRVCS_START_SEC_VAR_CLEARED_BOOLEAN
    #undef CUSTPERSRVCS_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined CUSTPERSRVCS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef CUSTPERSRVCS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  CustPerSrvcs END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CtrldVelRtn START
 *********************************************************************************************************************/
/* Variables */
#elif defined CTRLDVELRTN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CTRLDVELRTN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined CTRLDVELRTN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CTRLDVELRTN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined CTRLDVELRTN_START_SEC_VAR_CLEARED_32
    #undef CTRLDVELRTN_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined CTRLDVELRTN_STOP_SEC_VAR_CLEARED_32
    #undef CTRLDVELRTN_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  CtrldVelRtn END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ReturnFirewall START
 *********************************************************************************************************************/
/* Variables */
#elif defined RETURNFIREWALL_START_SEC_VAR_CLEARED_32
    #undef RETURNFIREWALL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined RETURNFIREWALL_STOP_SEC_VAR_CLEARED_32
    #undef RETURNFIREWALL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined RETURNFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
    #undef RETURNFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined RETURNFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef RETURNFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  ReturnFirewall END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DemIf START
 *********************************************************************************************************************/
/* Variables */
#elif defined DEMIF_START_SEC_VAR_CLEARED_32
    #undef DEMIF_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined DEMIF_STOP_SEC_VAR_CLEARED_32
    #undef DEMIF_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DEMIF_START_SEC_VAR_CLEARED_BOOLEAN
    #undef DEMIF_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined DEMIF_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef DEMIF_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined DEMIF_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DEMIF_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined DEMIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DEMIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined DEMIF_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef DEMIF_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9

#elif defined DEMIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef DEMIF_STOP_SEC_NOINIT_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined DEMIF_START_SEC_CONST_UNSPECIFIED
    #undef DEMIF_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined DEMIF_STOP_SEC_CONST_UNSPECIFIED
    #undef DEMIF_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST

/**********************************************************************************************************************
 *  DemIf END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AvgFricLrn START
 *********************************************************************************************************************/

/* Variables */
#elif defined AVGFRICLRN_START_SEC_VAR_CLEARED_32
    #undef AVGFRICLRN_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined AVGFRICLRN_STOP_SEC_VAR_CLEARED_32
    #undef AVGFRICLRN_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined AVGFRICLRN_START_SEC_VAR_CLEARED_BOOLEAN
    #undef AVGFRICLRN_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined AVGFRICLRN_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef AVGFRICLRN_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined AVGFRICLRN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef AVGFRICLRN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined AVGFRICLRN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef AVGFRICLRN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  AvgFricLrn END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SignlCondn START
 *********************************************************************************************************************/
/* Variables */
#elif defined SIGNLCONDN_START_SEC_VAR_CLEARED_32
    #undef SIGNLCONDN_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined SIGNLCONDN_STOP_SEC_VAR_CLEARED_32
    #undef SIGNLCONDN_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined SIGNLCONDN_START_SEC_VAR_CLEARED_BOOLEAN
    #undef SIGNLCONDN_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined SIGNLCONDN_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef SIGNLCONDN_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined SIGNLCONDN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef SIGNLCONDN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined SIGNLCONDN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef SIGNLCONDN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined SIGNLCONDN_START_SEC_VAR_NOINIT_32
    #undef SIGNLCONDN_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_10

#elif defined SIGNLCONDN_STOP_SEC_VAR_NOINIT_32
    #undef SIGNLCONDN_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  SignlCondn END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CtrlTemp START
 *********************************************************************************************************************/
/* Variables */
#elif defined CTRLTEMP_START_SEC_VAR_CLEARED_32
    #undef CTRLTEMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined CTRLTEMP_STOP_SEC_VAR_CLEARED_32
    #undef CTRLTEMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CTRLTEMP_START_SEC_VAR_CLEARED_16
    #undef CTRLTEMP_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined CTRLTEMP_STOP_SEC_VAR_CLEARED_16
    #undef CTRLTEMP_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined CTRLTEMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CTRLTEMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined CTRLTEMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CTRLTEMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  CtrlTemp END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BVDiag START
 *********************************************************************************************************************/
/* Variables */
#elif defined BVDIAG_START_SEC_VAR_CLEARED_32
    #undef BVDIAG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined BVDIAG_STOP_SEC_VAR_CLEARED_32
    #undef BVDIAG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  BVDiag END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BatteryVoltage START
 *********************************************************************************************************************/
/* Variables */
#elif defined BATTERYVOLTAGE_START_SEC_VAR_CLEARED_32
    #undef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_32
    #undef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined BATTERYVOLTAGE_START_SEC_VAR_CLEARED_16
    #undef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_16
    #undef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined BATTERYVOLTAGE_START_SEC_VAR_CLEARED_BOOLEAN
    #undef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  BatteryVoltage END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BattVltgCorreln START
 *********************************************************************************************************************/
/* Constants */
#elif defined BATTVLTGCORRLN_START_SEC_CONST_UNSPECIFIED
	#undef BATTVLTGCORRLN_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED

#elif defined BATTVLTGCORRLN_STOP_SEC_CONST_UNSPECIFIED
	#undef BATTVLTGCORRLN_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST

/* Variables */
#elif defined BATTVLTGCORRLN_START_SEC_VAR_CLEARED_8
	#undef BATTVLTGCORRLN_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_9

#elif defined BATTVLTGCORRLN_STOP_SEC_VAR_CLEARED_8
	#undef BATTVLTGCORRLN_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined BATTVLTGCORRLN_START_SEC_VAR_CLEARED_16
	#undef BATTVLTGCORRLN_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_9

#elif defined BATTVLTGCORRLN_STOP_SEC_VAR_CLEARED_16
	#undef BATTVLTGCORRLN_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  BattVltgCorreln END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrTempEst START
 *********************************************************************************************************************/
/* Variables */
#elif defined MTRTEMPEST_START_SEC_VAR_CLEARED_32
# undef MTRTEMPEST_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_CLEARED_32_9

#elif defined MTRTEMPEST_STOP_SEC_VAR_CLEARED_32
# undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR

#elif defined MTRTEMPEST_START_SEC_VAR_CLEARED_16
# undef MTRTEMPEST_START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_CLEARED_16_9

#elif defined MTRTEMPEST_STOP_SEC_VAR_CLEARED_16
# undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_16
# define STOP_SEC_VAR

#elif defined MTRTEMPEST_START_SEC_VAR_CLEARED_BOOLEAN
# undef MTRTEMPEST_START_SEC_VAR_CLEARED_BOOLEAN
# define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined MTRTEMPEST_STOP_SEC_VAR_CLEARED_BOOLEAN
# undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_BOOLEAN
# define STOP_SEC_VAR

#elif defined MTRTEMPEST_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef MTRTEMPEST_START_SEC_VAR_CLEARED_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined MTRTEMPEST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# define STOP_SEC_VAR

/**********************************************************************************************************************
 *  MtrTempEst END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ATAN2 START
 *********************************************************************************************************************/
/* Variables */
#elif defined ATAN2_START_SEC_VAR_INIT_32
    #undef ATAN2_START_SEC_VAR_INIT_32
    #define START_SEC_VAR_INIT_32_10

#elif defined ATAN2_STOP_SEC_VAR_INIT_32
    #undef ATAN2_STOP_SEC_VAR_INIT_32
    #define STOP_SEC_VAR
/**********************************************************************************************************************
 *  ATAN2 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TuningSelAuth START
 *********************************************************************************************************************/
/* Variables */
#elif defined TUNINGSELAUTH_START_SEC_VAR_CLEARED_16
    #undef TUNINGSELAUTH_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_16
    #undef TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined TUNINGSELAUTH_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TUNINGSELAUTH_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  TuningSelAuth END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  VehSpdLmt START
 *********************************************************************************************************************/
/* Variables */
#elif defined VEHSPDLMT_START_SEC_VAR_CLEARED_16
    #undef VEHSPDLMT_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined VEHSPDLMT_STOP_SEC_VAR_CLEARED_16
    #undef VEHSPDLMT_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  VehSpdLmt END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LrnEOT START
 *********************************************************************************************************************/
/* Variables */
#elif defined LRNEOT_START_SEC_VAR_CLEARED_32
    #undef LRNEOT_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined LRNEOT_STOP_SEC_VAR_CLEARED_32
    #undef LRNEOT_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined LRNEOT_START_SEC_VAR_CLEARED_BOOLEAN
    #undef LRNEOT_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined LRNEOT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef LRNEOT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  LrnEOT END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MotMeclPosn1 START
 *********************************************************************************************************************/
/* Constants */
#elif defined MOTMECLPOSN1_START_SEC_CONST_8
	#undef MOTMECLPOSN1_START_SEC_CONST_8
	#define START_SEC_CONST_8_10

#elif defined MOTMECLPOSN1_STOP_SEC_CONST_8
    #undef MOTMECLPOSN1_STOP_SEC_CONST_8
    #define STOP_SEC_CONST

/* Variables */
#elif defined MOTMECLPOSN1_START_SEC_VAR_CLEARED_8
	#undef MOTMECLPOSN1_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined MOTMECLPOSN1_STOP_SEC_VAR_CLEARED_8
	#undef MOTMECLPOSN1_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined MOTMECLPOSN1_START_SEC_VAR_CLEARED_16
	#undef MOTMECLPOSN1_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined MOTMECLPOSN1_STOP_SEC_VAR_CLEARED_16
	#undef MOTMECLPOSN1_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined MOTMECLPOSN1_START_SEC_VAR_CLEARED_BOOLEAN
	#undef MOTMECLPOSN1_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined MOTMECLPOSN1_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef MOTMECLPOSN1_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined MOTMECLPOSN1_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MOTMECLPOSN1_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined MOTMECLPOSN1_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MOTMECLPOSN1_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  MotMeclPosn1 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MotMeclPosn2 START
 *********************************************************************************************************************/
/* Constants */
#elif defined MOTMECLPOSN2_START_SEC_CONST_8
	#undef MOTMECLPOSN2_START_SEC_CONST_8
	#define START_SEC_CONST_8_10

#elif defined MOTMECLPOSN2_STOP_SEC_CONST_8
    #undef MOTMECLPOSN2_STOP_SEC_CONST_8
    #define STOP_SEC_CONST

/* Variables */
#elif defined MOTMECLPOSN2_START_SEC_VAR_CLEARED_8
	#undef MOTMECLPOSN2_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined MOTMECLPOSN2_STOP_SEC_VAR_CLEARED_8
	#undef MOTMECLPOSN2_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined MOTMECLPOSN2_START_SEC_VAR_CLEARED_16
	#undef MOTMECLPOSN2_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined MOTMECLPOSN2_STOP_SEC_VAR_CLEARED_16
	#undef MOTMECLPOSN2_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined MOTMECLPOSN2_START_SEC_VAR_CLEARED_BOOLEAN
	#undef MOTMECLPOSN2_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined MOTMECLPOSN2_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef MOTMECLPOSN2_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined MOTMECLPOSN2_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MOTMECLPOSN2_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined MOTMECLPOSN2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MOTMECLPOSN2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  MotMeclPosn1 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrPos3SinCos START
 *********************************************************************************************************************/
/* Variables */
#elif defined MTRPOS3SINCOS_START_SEC_VAR_CLEARED_8
	#undef MTRPOS3SINCOS_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined MTRPOS3SINCOS_STOP_SEC_VAR_CLEARED_8
	#undef MTRPOS3SINCOS_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined MTRPOS3SINCOS_START_SEC_VAR_CLEARED_16
	#undef MTRPOS3SINCOS_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined MTRPOS3SINCOS_STOP_SEC_VAR_CLEARED_16
	#undef MTRPOS3SINCOS_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined MTRPOS3SINCOS_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRPOS3SINCOS_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined MTRPOS3SINCOS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRPOS3SINCOS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  MtrPos3SinCos END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MotPosnComp START
 *********************************************************************************************************************/
/* Variables */
#elif defined MOTPOSNCMP_START_SEC_VAR_CLEARED_8
	#undef MOTPOSNCMP_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined MOTPOSNCMP_STOP_SEC_VAR_CLEARED_8
	#undef MOTPOSNCMP_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined MOTPOSNCMP_START_SEC_VAR_CLEARED_16
	#undef MOTPOSNCMP_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined MOTPOSNCMP_STOP_SEC_VAR_CLEARED_16
	#undef MOTPOSNCMP_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined MOTPOSNCMP_START_SEC_VAR_CLEARED_32
	#undef MOTPOSNCMP_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_16_10

#elif defined MOTPOSNCMP_STOP_SEC_VAR_CLEARED_32
	#undef MOTPOSNCMP_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined MOTPOSNCMP_START_SEC_VAR_CLEARED_BOOLEAN
	#undef MOTPOSNCMP_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined MOTPOSNCMP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef MOTPOSNCMP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined MOTPOSNCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MOTPOSNCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined MOTPOSNCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MOTPOSNCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  MotPosnComp END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MotAgCorrln START
 *********************************************************************************************************************/
/* Variables */
#elif defined MOTAGCORRLN_START_SEC_VAR_CLEARED_8
	#undef MOTAGCORRLN_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined MOTAGCORRLN_STOP_SEC_VAR_CLEARED_8
	#undef MOTAGCORRLN_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined MOTAGCORRLN_START_SEC_VAR_CLEARED_16
	#undef MOTAGCORRLN_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined MOTAGCORRLN_STOP_SEC_VAR_CLEARED_16
	#undef MOTAGCORRLN_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined MOTAGCORRLN_START_SEC_VAR_CLEARED_32
	#undef MOTAGCORRLN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_16_10

#elif defined MOTAGCORRLN_STOP_SEC_VAR_CLEARED_32
	#undef MOTAGCORRLN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined MOTAGCORRLN_START_SEC_VAR_CLEARED_BOOLEAN
	#undef MOTAGCORRLN_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined MOTAGCORRLN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef MOTAGCORRLN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined MOTAGCORRLN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MOTAGCORRLN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined MOTAGCORRLN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MOTAGCORRLN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined MOTAGCORRLN_START_SEC_CONST_UNSPECIFIED
	#undef MOTAGCORRLN_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED

#elif defined MOTAGCORRLN_STOP_SEC_CONST_UNSPECIFIED
	#undef MOTAGCORRLN_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST

/**********************************************************************************************************************
 *  MotAgCorrln END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DigMSBArbn START
 *********************************************************************************************************************/
/* Variables */
#elif defined DIGMSBARBN_START_SEC_VAR_CLEARED_8
	#undef DIGMSBARBN_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined DIGMSBARBN_STOP_SEC_VAR_CLEARED_8
	#undef DIGMSBARBN_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR


#elif defined DIGMSBARBN_START_SEC_VAR_CLEARED_32
	#undef DIGMSBARBN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_16_10

#elif defined DIGMSBARBN_STOP_SEC_VAR_CLEARED_32
	#undef DIGMSBARBN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined DIGMSBARBN_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DIGMSBARBN_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined DIGMSBARBN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DIGMSBARBN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined DIGMSBARBN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIGMSBARBN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined DIGMSBARBN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DIGMSBARBN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  DigMSBArbn END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EtDmpFw START
 *********************************************************************************************************************/
/* Variables */
#elif defined ETDMPFW_START_SEC_VAR_CLEARED_32
    #undef ETDMPFW_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined ETDMPFW_STOP_SEC_VAR_CLEARED_32
    #undef ETDMPFW_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined ETDMPFW_START_SEC_VAR_CLEARED_08
    #undef ETDMPFW_START_SEC_VAR_CLEARED_08
    #define START_SEC_VAR_CLEARED_8_10

#elif defined ETDMPFW_STOP_SEC_VAR_CLEARED_08
    #undef ETDMPFW_STOP_SEC_VAR_CLEARED_08
    #define STOP_SEC_VAR

#elif defined ETDMPFW_START_SEC_VAR_CLEARED_BOOLEAN
    #undef ETDMPFW_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined ETDMPFW_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef ETDMPFW_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  EtDmpFw END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EOTActuatorMng START
 *********************************************************************************************************************/
/* Variables */
#elif defined EOTACTUATORMNG_START_SEC_VAR_CLEARED_32
    #undef EOTACTUATORMNG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_32
    #undef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined EOTACTUATORMNG_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef EOTACTUATORMNG_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined EOTACTUATORMNG_START_SEC_VAR_CLEARED_BOOLEAN
    #undef EOTACTUATORMNG_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  EOTActuatorMng END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SrlComOutput START
 *********************************************************************************************************************/
/* Type H Variables */
#elif defined SRLCOMOUTPUT_START_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #define VAR_SEC_OPEN
    #pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:SrlComOutput")
    #undef SRLCOMOUTPUT_START_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #undef MEMMAP_ERROR

#elif defined SRLCOMOUTPUT_STOP_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #undef SRLCOMOUTPUT_STOP_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #define STOP_SEC_VAR

/* Variables */
#elif defined SRLCOMOUTPUT_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined SRLCOMOUTPUT_START_SEC_VAR_CLEARED_32
    #undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_32
    #undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined SRLCOMOUTPUT_START_SEC_VAR_CLEARED_8
    #undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_8
    #undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined SRLCOMOUTPUT_START_SEC_CONST_16
    #undef SRLCOMOUTPUT_START_SEC_CONST_16
    #define START_SEC_CONST_16BIT

#elif defined SRLCOMOUTPUT_STOP_SEC_CONST_16
    #undef SRLCOMOUTPUT_STOP_SEC_CONST_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  SrlComOutput END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SrlComInput START
 *********************************************************************************************************************/
/* Type H Variables */
#elif defined SRLCOMINPUT_START_SEC_VAR_SAVED_ZONEH_16
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:SrlComInput")
    #undef SRLCOMINPUT_START_SEC_VAR_SAVED_ZONEH_16
    #undef MEMMAP_ERROR

#elif defined SRLCOMINPUT_STOP_SEC_VAR_SAVED_ZONEH_16
    #undef SRLCOMINPUT_STOP_SEC_VAR_SAVED_ZONEH_16
    #define STOP_SEC_VAR

/* Variables */
#elif defined SRLCOMINPUT_START_SEC_VAR_CLEARED_32
    #undef SRLCOMINPUT_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined SRLCOMINPUT_STOP_SEC_VAR_CLEARED_32
    #undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined SRLCOMINPUT_START_SEC_VAR_CLEARED_16
    #undef SRLCOMINPUT_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined SRLCOMINPUT_STOP_SEC_VAR_CLEARED_16
    #undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined SRLCOMINPUT_START_SEC_VAR_CLEARED_8
    #undef SRLCOMINPUT_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined SRLCOMINPUT_STOP_SEC_VAR_CLEARED_8
    #undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined SRLCOMINPUT_START_SEC_VAR_CLEARED_BOOLEAN
    #undef SRLCOMINPUT_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined SRLCOMINPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  SrlComInput END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StOpCtrl START
 *********************************************************************************************************************/
/* Variables */
#elif defined STOPCTRL_START_SEC_VAR_INIT_08
    #undef STOPCTRL_START_SEC_VAR_INIT_08
    #define START_SEC_VAR_INIT_8_10

#elif defined STOPCTRL_STOP_SEC_VAR_INIT_08
    #undef STOPCTRL_STOP_SEC_VAR_INIT_08
    #define STOP_SEC_VAR

#elif defined STOPCTRL_START_SEC_VAR_CLEARED_32
    #undef STOPCTRL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined STOPCTRL_STOP_SEC_VAR_CLEARED_32
    #undef STOPCTRL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined STOPCTRL_START_SEC_VAR_NOINIT_32
    #undef STOPCTRL_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined STOPCTRL_STOP_SEC_VAR_NOINIT_32
    #undef STOPCTRL_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR

#elif defined STOPCTRL_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef STOPCTRL_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined STOPCTRL_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef STOPCTRL_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  StOpCtrl END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Sweep START
 *********************************************************************************************************************/

#elif defined SWEEP_START_SEC_VAR_CLEARED_32
	#undef SWEEP_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED

#elif defined SWEEP_STOP_SEC_VAR_CLEARED_32
	#undef SWEEP_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined SWEEP_START_SEC_VAR_CLEARED_16
	#undef SWEEP_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED

#elif defined SWEEP_STOP_SEC_VAR_CLEARED_16
	#undef SWEEP_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined SWEEP_START_SEC_VAR_CLEARED_BOOLEAN
	#undef SWEEP_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED

#elif defined SWEEP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef SWEEP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  Sweep END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  StabilityComp START
 *********************************************************************************************************************/
/* Variables */
#elif defined STABILITYCOMP_START_SEC_VAR_CLEARED_32
    #undef STABILITYCOMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined STABILITYCOMP_STOP_SEC_VAR_CLEARED_32
    #undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined STABILITYCOMP_START_SEC_VAR_CLEARED_16
    #undef STABILITYCOMP_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined STABILITYCOMP_STOP_SEC_VAR_CLEARED_16
    #undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined STABILITYCOMP_START_SEC_VAR_CLEARED_BOOLEAN
    #undef STABILITYCOMP_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined STABILITYCOMP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined STABILITYCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STABILITYCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined STABILITYCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  StabilityComp END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  StabilityComp2 START
 *********************************************************************************************************************/
/* Variables */
#elif defined STABILITYCOMP2_START_SEC_VAR_CLEARED_32
    #undef STABILITYCOMP2_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_8

#elif defined STABILITYCOMP2_STOP_SEC_VAR_CLEARED_32
    #undef STABILITYCOMP2_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined STABILITYCOMP2_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STABILITYCOMP2_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_8

#elif defined STABILITYCOMP2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STABILITYCOMP2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  StabilityComp2 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  TmplMonrDualIvtr START
 *********************************************************************************************************************/
/* Constants */
#elif defined TMPLMONRDUALIVTR_START_SEC_CONST_UNSPECIFIED
    #undef TMPLMONRDUALIVTR_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined TMPLMONRDUALIVTR_STOP_SEC_CONST_UNSPECIFIED
    #undef TMPLMONRDUALIVTR_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST

/* Variables */
#elif defined TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_8
    #undef TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_8
    #undef TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_32
    #undef TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_32
    #undef TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_16
	#undef TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_NOINIT_16_10

#elif defined TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_16
	#undef TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined  TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined  TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_BOOLEAN
    #undef TMPLMONRDUALIVTR_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef TMPLMONRDUALIVTR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  TmplMonrDualIvtr END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HystComp START
 *********************************************************************************************************************/ 
/* Variables */
#elif defined HYSTCOMP_START_SEC_VAR_CLEARED_16
    #undef HYSTCOMP_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined HYSTCOMP_STOP_SEC_VAR_CLEARED_16
    #undef HYSTCOMP_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined HYSTCOMP_START_SEC_VAR_CLEARED_32
    #undef HYSTCOMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined HYSTCOMP_STOP_SEC_VAR_CLEARED_32
    #undef HYSTCOMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined HYSTCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef HYSTCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined HYSTCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef HYSTCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  HystComp END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  HiLoadStall START
 *********************************************************************************************************************/ 
/* Variables */
#elif defined HILOADSTALL_START_SEC_VAR_CLEARED_32
    #undef HILOADSTALL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined HILOADSTALL_STOP_SEC_VAR_CLEARED_32
    #undef HILOADSTALL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined HILOADSTALL_START_SEC_VAR_CLEARED_16
    #undef HILOADSTALL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined HILOADSTALL_STOP_SEC_VAR_CLEARED_16
    #undef HILOADSTALL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  HiLoadStall END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  CDDInterface START
 *********************************************************************************************************************/ 
/* Variables */
  /*CDDDATA9 START*/
#elif defined CDDDATA9_START_SEC_VAR_CLEARED_32
    #undef CDDDATA9_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined CDDDATA9_STOP_SEC_VAR_CLEARED_32
    #undef CDDDATA9_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CDDDATA9_START_SEC_VAR_CLEARED_16
    #undef CDDDATA9_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined CDDDATA9_STOP_SEC_VAR_CLEARED_16
    #undef CDDDATA9_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined CDDDATA9_START_SEC_VAR_CLEARED_BOOLEAN
    #undef CDDDATA9_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined CDDDATA9_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef CDDDATA9_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

  /*CDDDATA10 START*/
#elif defined CDDDATA10_START_SEC_VAR_CLEARED_32
    #undef CDDDATA10_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined CDDDATA10_STOP_SEC_VAR_CLEARED_32
    #undef CDDDATA10_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CDDDATA10_START_SEC_VAR_CLEARED_16
    #undef CDDDATA10_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined CDDDATA10_STOP_SEC_VAR_CLEARED_16
    #undef CDDDATA10_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined CDDDATA10_START_SEC_VAR_CLEARED_8
    #undef CDDDATA10_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined CDDDATA10_STOP_SEC_VAR_CLEARED_8
    #undef CDDDATA10_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined CDDDATA10_START_SEC_VAR_CLEARED_BOOLEAN
    #undef CDDDATA10_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined CDDDATA10_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef CDDDATA10_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/* CDDInterface Internal Variables Start */
#elif defined CDDINTERFACE_START_SEC_VAR_CLEARED_32
    #undef CDDINTERFACE_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined CDDINTERFACE_STOP_SEC_VAR_CLEARED_32
    #undef CDDINTERFACE_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CDDINTERFACE_START_SEC_VAR_CLEARED_8
    #undef CDDINTERFACE_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined CDDINTERFACE_STOP_SEC_VAR_CLEARED_8
    #undef CDDINTERFACE_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  CDDInterface END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DigPhsReasDiag START
 *********************************************************************************************************************/
/* Variables */
#elif defined DIGPHSREASDIAG_START_SEC_VAR_CLEARED_32
    #undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10

#elif defined DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_32
    #undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DIGPHSREASDIAG_START_SEC_VAR_CLEARED_16
    #undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10

#elif defined DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_16
    #undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DIGPHSREASDIAG_START_SEC_VAR_CLEARED_8
    #undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_NOINIT_8_10

#elif defined DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_8
    #undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined DIGPHSREASDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    #undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10

#elif defined DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  DigPhsReasDiag END
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  DMA START
**********************************************************************************************************************/

#elif defined DMA_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DMA_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_0

#elif defined DMA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DMA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined DMA_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DMA_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_0

#elif defined DMA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DMA_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined DMA_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DMA_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_0

#elif defined DMA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DMA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/**********************************************************************************************************************
*  DMA END
**********************************************************************************************************************/

/**********************************************************************************************************************
*  ElePwr START
**********************************************************************************************************************/
#elif defined ELEPWR_START_SEC_VAR_CLEARED_32
	#undef ELEPWR_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined ELEPWR_STOP_SEC_VAR_CLEARED_32
	#undef ELEPWR_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
/**********************************************************************************************************************
*  ElePwr END
**********************************************************************************************************************/

/**********************************************************************************************************************
 *  NtWrap START
 *********************************************************************************************************************/

#elif defined NTWRAP_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NTWRAP_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED

#elif defined NTWRAP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NTWRAP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  NtWrap END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  HighFreqAssist START
 *********************************************************************************************************************/
/* Variables */
#elif defined HIGHFREQASSIST_START_SEC_VAR_CLEARED_32
# undef HIGHFREQASSIST_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_CLEARED_32_10

#elif defined HIGHFREQASSIST_STOP_SEC_VAR_CLEARED_32
# undef HIGHFREQASSIST_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR

#elif defined HYSTADD_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HYSTADD_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined HYSTADD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HYSTADD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  HighFreqAssist END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  PICurrContrl START
 *********************************************************************************************************************/
/* Variables */
#elif defined PICURRCNTRL_START_SEC_VAR_CLEARED_32
    #undef PICURRCNTRL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined PICURRCNTRL_STOP_SEC_VAR_CLEARED_32
    #undef PICURRCNTRL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined PICURRCNTRL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef PICURRCNTRL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined PICURRCNTRL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef PICURRCNTRL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  PICurrContrl END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LmtCod START
 *********************************************************************************************************************/
/* Variables */
#elif defined LMTCOD_START_SEC_VAR_CLEARED_32
    #undef LMTCOD_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined LMTCOD_STOP_SEC_VAR_CLEARED_32
    #undef LMTCOD_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  LmtCod END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LoaMgr START
 *********************************************************************************************************************/
/* Variables */
#elif defined LOAMGR_START_SEC_VAR_CLEARED_08
	#undef LOAMGR_START_SEC_VAR_CLEARED_08
	#define START_SEC_VAR_CLEARED_8_10

#elif defined LOAMGR_STOP_SEC_VAR_CLEARED_08
	#undef LOAMGR_STOP_SEC_VAR_CLEARED_08
	#define STOP_SEC_VAR

#elif defined LOAMGR_START_SEC_VAR_CLEARED_32
	#undef LOAMGR_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined LOAMGR_STOP_SEC_VAR_CLEARED_32
	#undef LOAMGR_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined LOAMGR_START_SEC_VAR_CLEARED_BOOLEAN
	#undef LOAMGR_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined LOAMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef LOAMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined LOAMGR_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef LOAMGR_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined LOAMGR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef LOAMGR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  LoaMgr END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  PeakCurrEst START
 *********************************************************************************************************************/
/* Variables */
#elif defined PEAKCURREST_START_SEC_VAR_CLEARED_32
    #undef PEAKCURREST_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined PEAKCURREST_STOP_SEC_VAR_CLEARED_32
    #undef PEAKCURREST_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  PeakCurrEst END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CurrCmd START
 *********************************************************************************************************************/
/* Variables */
#elif defined CURRCMD_START_SEC_VAR_CLEARED_32
    #undef CURRCMD_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined CURRCMD_STOP_SEC_VAR_CLEARED_32
    #undef CURRCMD_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CURRCMD_START_SEC_VAR_CLEARED_16
    #undef CURRCMD_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined CURRCMD_STOP_SEC_VAR_CLEARED_16
    #undef CURRCMD_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined CURRCMD_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CURRCMD_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined CURRCMD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CURRCMD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
/**********************************************************************************************************************
 *  CurrCmd END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CurrParamComp START
 *********************************************************************************************************************/
/* Variables */
#elif defined CURRPARAMCOMP_START_SEC_VAR_CLEARED_32
    #undef CURRPARAMCOMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined CURRPARAMCOMP_STOP_SEC_VAR_CLEARED_32
    #undef CURRPARAMCOMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  CurrParamComp END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  NvmProxy START
 *********************************************************************************************************************/
/* Code */
#elif defined NVMPROXY_START_SEC_CODE
    #undef NVMPROXY_START_SEC_CODE
    #define START_SEC_CODE

#elif defined NVMPROXY_STOP_SEC_CODE
    #undef NVMPROXY_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined NVMPROXY_START_SEC_CONST_UNSPECIFIED
    #undef NVMPROXY_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined NVMPROXY_STOP_SEC_CONST_UNSPECIFIED
    #undef NVMPROXY_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST

/* Variables */
#elif defined NVMPROXY_START_SEC_VAR_CLEARED_16
    #undef NVMPROXY_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_GLOBALSHARED

#elif defined NVMPROXY_STOP_SEC_VAR_CLEARED_16
    #undef NVMPROXY_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
	
#elif defined NVMPROXY_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef NVMPROXY_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED

#elif defined NVMPROXY_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef NVMPROXY_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined NVMPROXY_START_SEC_VAR_NOINIT_8
    #undef NVMPROXY_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_NOINIT_8_9

#elif defined NVMPROXY_STOP_SEC_VAR_NOINIT_8
    #undef NVMPROXY_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  NvmProxy END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  PwrLmtFuncCr START
 *********************************************************************************************************************/
/* VAR sections */

#elif defined PWRLMTFUNCCR_START_SEC_VAR_CLEARED_32
	# undef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_32
	# define START_SEC_VAR_CLEARED_32_10

#elif defined PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_32
	# undef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_32
	# define STOP_SEC_VAR

#elif defined PWRLMTFUNCCR_START_SEC_VAR_CLEARED_BOOLEAN
    #undef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_8_10

#elif defined PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined PWRLMTFUNCCR_START_SEC_VAR_CLEARED_UNSPECIFIED
	# undef PWRLMTFUNCCR_START_SEC_VAR_CLEARED_UNSPECIFIED
	# define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	# undef PWRLMTFUNCCR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	# define STOP_SEC_VAR

/**********************************************************************************************************************
 *  PwrLmtFuncCr END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  AssistFirewall START
 *********************************************************************************************************************/
/* Variables */
#elif defined ASSISTFIREWALL_START_SEC_VAR_CLEARED_16
    #undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_16
    #undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined ASSISTFIREWALL_START_SEC_VAR_CLEARED_32
    #undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_32
    #undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined ASSISTFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined ASSISTFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
	#undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  AssistFirewall END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  Assist START
 *********************************************************************************************************************/
/* Variables */
#elif defined ASSIST_START_SEC_VAR_CLEARED_16
    #undef ASSIST_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined ASSIST_STOP_SEC_VAR_CLEARED_16
    #undef ASSIST_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  Assist END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FrqDepDmpnInrtCmp START
 *********************************************************************************************************************/
/* Variables */
#elif defined FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_32
	#undef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_32
	#undef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  FrqDepDmpnInrtCmp END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  HwPwUpSeq START
 *********************************************************************************************************************/
/* Variables */
#elif defined HWPWRUPSEQ_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HWPWRUPSEQ_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined HWPWRUPSEQ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HWPWRUPSEQ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined HWPWRUPSEQ_START_SEC_VAR_CLEARED_BOOLEAN
	#undef HWPWRUPSEQ_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined HWPWRUPSEQ_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef HWPWRUPSEQ_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  HwPwUp END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  HwTrqArbn START
 *********************************************************************************************************************/
/* Variables */
#elif defined HWTRQARBN_START_SEC_VAR_CLEARED_8
	#undef HWTRQARBN_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined HWTRQARBN_STOP_SEC_VAR_CLEARED_8
	#undef HWTRQARBN_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined HWTRQARBN_START_SEC_VAR_CLEARED_32
	#undef HWTRQARBN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined HWTRQARBN_STOP_SEC_VAR_CLEARED_32
	#undef HWTRQARBN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined HWTRQARBN_START_SEC_VAR_CLEARED_BOOLEAN
	#undef HWTRQARBN_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined HWTRQARBN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef HWTRQARBN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  HwTrqArbn END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HwTqCorrln START
 *********************************************************************************************************************/
/* Variables */
#elif defined HWTQCORRLN_START_SEC_VAR_CLEARED_8
	#undef HWTQCORRLN_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined HWTQCORRLN_STOP_SEC_VAR_CLEARED_8
	#undef HWTQCORRLN_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined HWTQCORRLN_START_SEC_VAR_CLEARED_16
	#undef HWTQCORRLN_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined HWTQCORRLN_STOP_SEC_VAR_CLEARED_16
	#undef HWTQCORRLN_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined HWTQCORRLN_START_SEC_VAR_CLEARED_32
	#undef HWTQCORRLN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined HWTQCORRLN_STOP_SEC_VAR_CLEARED_32
	#undef HWTQCORRLN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined HWTQCORRLN_START_SEC_VAR_CLEARED_BOOLEAN
	#undef HWTQCORRLN_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined HWTQCORRLN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef HWTQCORRLN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined HWTQCORRLN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HWTQCORRLN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined HWTQCORRLN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef HWTQCORRLN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  HwTrqCorrln END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrDrvDiag START
 *********************************************************************************************************************/
/* Variables */
#elif defined MTRDRVDIAG_START_SEC_VAR_CLEARED_32
	#undef MTRDRVDIAG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined MTRDRVDIAG_STOP_SEC_VAR_CLEARED_32
	#undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined MTRDRVDIAG_START_SEC_VAR_CLEARED_16
	#undef MTRDRVDIAG_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined MTRDRVDIAG_STOP_SEC_VAR_CLEARED_16
	#undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined MTRDRVDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef MTRDRVDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined MTRDRVDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined MTRDRVDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRDRVDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined MTRDRVDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  MtrDrvDiag END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Damping START
 *********************************************************************************************************************/
/* Variables */
#elif defined DAMPING_START_SEC_VAR_CLEARED_32
	#undef DAMPING_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined DAMPING_STOP_SEC_VAR_CLEARED_32
	#undef DAMPING_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined DAMPING_START_SEC_VAR_CLEARED_16
	#undef DAMPING_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined DAMPING_STOP_SEC_VAR_CLEARED_16
	#undef DAMPING_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined DAMPING_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DAMPING_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined DAMPING_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DAMPING_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  Damping END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  TrqCanc START
 *********************************************************************************************************************/
/* Variables */
#elif defined TRQCANC_START_SEC_VAR_CLEARED_16
    #undef TRQCANC_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined TRQCANC_STOP_SEC_VAR_CLEARED_16
    #undef TRQCANC_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined TRQCANC_START_SEC_VAR_CLEARED_32
    #undef TRQCANC_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined TRQCANC_STOP_SEC_VAR_CLEARED_32
    #undef TRQCANC_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined TRQCANC_START_SEC_CONST_16
	#undef TRQCANC_START_SEC_CONST_16
	#define START_SEC_CONST_16BIT

#elif defined TRQCANC_STOP_SEC_CONST_16
	#undef TRQCANC_STOP_SEC_CONST_16
	#define STOP_SEC_CONST

/**********************************************************************************************************************
 *  TrqCanc END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DampingFirewall START
 *********************************************************************************************************************/
/* Variables */
#elif defined DAMPINGFIREWALL_START_SEC_VAR_CLEARED_32
    #undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_32
    #undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DAMPINGFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined DAMPINGFIREWALL_START_SEC_VAR_CLEARED_16
    #undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_16
    #undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DAMPINGFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  DampingFirewall END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  VehPwrMd START
 *********************************************************************************************************************/
/* Variables */
#elif defined VEHPWRMD_START_SEC_CONST_UNSPECIFIED
    #undef VEHPWRMD_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined VEHPWRMMD_STOP_SEC_CONST_UNSPECIFIED
    #undef VEHPWRMMD_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST

#elif defined VEHPWRMD_START_SEC_VAR_CLEARED_BOOLEAN
    #undef VEHPWRMD_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined VEHPWRMD_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef VEHPWRMD_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined VEHPWRMD_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef VEHPWRMD_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined VEHPWRMD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef VEHPWRMD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined VEHPWRMD_START_SEC_VAR_CLEARED_16
    #undef VEHPWRMD_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined VEHPWRMD_STOP_SEC_VAR_CLEARED_16
    #undef VEHPWRMD_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined VEHPWRMD_START_SEC_VAR_CLEARED_32
    #undef VEHPWRMD_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined VEHPWRMD_STOP_SEC_VAR_CLEARED_32
    #undef VEHPWRMD_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  VehPwrMd END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AnaHwTrq START
 *********************************************************************************************************************/
/* Variables */
#elif defined ANAHWTRQ_START_SEC_VAR_CLEARED_8
    #undef ANAHWTRQ_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined ANAHWTRQ_STOP_SEC_VAR_CLEARED_8
    #undef ANAHWTRQ_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined ANAHWTRQ_START_SEC_VAR_CLEARED_32
    #undef ANAHWTRQ_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined ANAHWTRQ_STOP_SEC_VAR_CLEARED_32
    #undef ANAHWTRQ_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined ANAHWTRQ_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ANAHWTRQ_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined ANAHWTRQ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ANAHWTRQ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  AnaHwTrq END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AnaMSBCorrln START
 *********************************************************************************************************************/
/* Variables */
#elif defined ANAMSBCORRLN_START_SEC_VAR_CLEARED_8
    #undef ANAMSBCORRLN_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined ANAMSBCORRLN_STOP_SEC_VAR_CLEARED_8
    #undef ANAMSBCORRLN_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined ANAMSBCORRLN_START_SEC_VAR_CLEARED_16
    #undef ANAMSBCORRLN_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined ANAMSBCORRLN_STOP_SEC_VAR_CLEARED_16
    #undef ANAMSBCORRLN_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined ANAMSBCORRLN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ANAMSBCORRLN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined ANAMSBCORRLN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ANAMSBCORRLN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  AnaMSBCorrln END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AnaMSBSnsrIf START
 *********************************************************************************************************************/
/* Variables */
#elif defined ANAMSBSNSRIF_START_SEC_VAR_CLEARED_8
	#undef ANAMSBSNSRIF_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined ANAMSBSNSRIF_STOP_SEC_VAR_CLEARED_8
	#undef ANAMSBSNSRIF_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined ANAMSBSNSRIF_START_SEC_VAR_CLEARED_16
	#undef ANAMSBSNSRIF_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined ANAMSBSNSRIF_STOP_SEC_VAR_CLEARED_16
	#undef ANAMSBSNSRIF_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined ANAMSBSNSRIF_START_SEC_VAR_CLEARED_32
	#undef ANAMSBSNSRIF_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined ANAMSBSNSRIF_STOP_SEC_VAR_CLEARED_32
	#undef ANAMSBSNSRIF_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined ANAMSBSNSRIF_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef ANAMSBSNSRIF_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined ANAMSBSNSRIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef ANAMSBSNSRIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/* CONST sections */
#elif defined ANAMSBSNSRIF_START_SEC_CONST_UNSPECIFIED
	#undef ANAMSBSNSRIF_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR

#elif defined ANAMSBSNSRIF_STOP_SEC_CONST_UNSPECIFIED
	#undef ANAMSBSNSRIF_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
/**********************************************************************************************************************
 *  AnaMSBSnsrIf END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AnaMSBArbn START
 *********************************************************************************************************************/
/* Type H Variables */
#elif defined ANAMSBARBN_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:noinit:typeH:AnaMSBArbn")
    #undef ANAMSBARBN_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR

#elif defined ANAMSBARBN_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef ANAMSBARBN_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR

/* Variables */
#elif defined ANAMSBARBN_START_SEC_VAR_CLEARED_8
	#undef ANAMSBARBN_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined ANAMSBARBN_STOP_SEC_VAR_CLEARED_8
	#undef ANAMSBARBN_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined ANAMSBARBN_START_SEC_VAR_CLEARED_16
	#undef ANAMSBARBN_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined ANAMSBARBN_STOP_SEC_VAR_CLEARED_16
	#undef ANAMSBARBN_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined ANAMSBARBN_START_SEC_VAR_CLEARED_32
	#undef ANAMSBARBN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined ANAMSBARBN_STOP_SEC_VAR_CLEARED_32
	#undef ANAMSBARBN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined ANAMSBARBN_START_SEC_VAR_CLEARED_BOOLEAN
	#undef ANAMSBARBN_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined ANAMSBARBN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef ANAMSBARBN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

/* CONST sections */
#elif defined ANAMSBARBN_START_SEC_VAR_CONST_UNSPECIFIED
	#undef ANAMSBARBN_START_SEC_VAR_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR

#elif defined ANAMSBARBN_STOP_SEC_VAR_CONST_UNSPECIFIED
	#undef ANAMSBARBN_STOP_SEC_VAR_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
/**********************************************************************************************************************
 *  AnaMSBArbn END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StaMd START
 *********************************************************************************************************************/
/* CONST sections */
#elif defined STAMD_START_SEC_CONST_UNSPECIFIED
	#undef STAMD_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR

#elif defined STAMD_STOP_SEC_CONST_UNSPECIFIED
	#undef STAMD_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR

#elif defined STAMD_START_SEC_VAR_SAVED_ZONEHGS_8
	#undef STAMD_START_SEC_VAR_SAVED_ZONEHGS_8
	#define START_SEC_VAR_CLEARED_8_GLOBALSHARED

#elif defined STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_8
    #undef STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_8
    #define STOP_SEC_VAR

#elif defined STAMD_START_SEC_VAR_SAVED_ZONEHGS_32
	#undef STAMD_START_SEC_VAR_SAVED_ZONEHGS_32
	#define START_SEC_VAR_CLEARED_32_GLOBALSHARED

#elif defined STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_32
    #undef STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_32
    #define STOP_SEC_VAR

#elif defined STAMD10_START_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD10_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_10

#elif defined STAMD10_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD10_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined STAMD10_START_SEC_VAR_CLEARED_32
	#undef STAMD10_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined STAMD10_STOP_SEC_VAR_CLEARED_32
	#undef STAMD10_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined STAMD10_START_SEC_VAR_CLEARED_16
	#undef STAMD10_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_10

#elif defined STAMD10_STOP_SEC_VAR_CLEARED_16
	#undef STAMD10_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined STAMD10_START_SEC_VAR_CLEARED_8
	#undef STAMD10_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined STAMD10_STOP_SEC_VAR_CLEARED_8
	#undef STAMD10_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined STAMD10_START_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD10_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined STAMD10_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD10_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined STAMD9_START_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD9_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_9

#elif defined STAMD9_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD9_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined STAMD9_START_SEC_VAR_CLEARED_32
	#undef STAMD9_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_9

#elif defined STAMD9_STOP_SEC_VAR_CLEARED_32
	#undef STAMD9_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined STAMD9_START_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD9_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined STAMD9_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef STAMD9_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined STAMD8_START_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD8_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_8

#elif defined STAMD8_STOP_SEC_VAR_INIT_UNSPECIFIED
	#undef STAMD8_STOP_SEC_VAR_INIT_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined STAMD8_START_SEC_VAR_CLEARED_32
	#undef STAMD8_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_8

#elif defined STAMD8_STOP_SEC_VAR_CLEARED_32
	#undef STAMD8_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined STAMD8_START_SEC_VAR_CLEARED_16
	#undef STAMD8_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_8

#elif defined STAMD8_STOP_SEC_VAR_CLEARED_16
	#undef STAMD8_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR
/**********************************************************************************************************************
 *  StaMd END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  AP_XCP START
 *********************************************************************************************************************/
/* Variables */
#elif defined APXCP_START_SEC_VAR_CLEARED_8
    #undef APXCP_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined APXCP_STOP_SEC_VAR_CLEARED_8
    #undef APXCP_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef APXCP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined APXCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef APXCP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_CLEARED_BOOLEAN
    #undef APXCP_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined APXCP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef APXCP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_NOINIT_8
    #undef APXCP_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_NOINIT_8_9

#elif defined APXCP_STOP_SEC_VAR_NOINIT_8
    #undef APXCP_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_NOINIT_32
    #undef APXCP_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_9

#elif defined APXCP_STOP_SEC_VAR_NOINIT_32
    #undef APXCP_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_INIT_UNSPECIFIED
	#undef APXCP_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_9

#elif defined APXCP_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef APXCP_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  AP_XCP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ActivePull START
 *********************************************************************************************************************/
/* Type H Variables */
#elif defined ACTIVEPULL_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:ActivePull")
    #undef ACTIVEPULL_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR

#elif defined ACTIVEPULL_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef ACTIVEPULL_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR

/* Variables */
#elif defined ACTIVEPULL_START_SEC_VAR_CLEARED_32
	#undef ACTIVEPULL_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_9

#elif defined ACTIVEPULL_STOP_SEC_VAR_CLEARED_32
	#undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined ACTIVEPULL_START_SEC_VAR_CLEARED_16
	#undef ACTIVEPULL_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_9

#elif defined ACTIVEPULL_STOP_SEC_VAR_CLEARED_16
	#undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined ACTIVEPULL_START_SEC_VAR_CLEARED_BOOLEAN
	#undef ACTIVEPULL_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined ACTIVEPULL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined ACTIVEPULL_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef ACTIVEPULL_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined ACTIVEPULL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  ActivePull END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  WhlImbRej START
 *********************************************************************************************************************/
/* Type H Variables */
#elif defined WHLIMBREJ_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:noinit:typeH:WhlImbRej")
    #undef WHLIMBREJ_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR

#elif defined WHLIMBREJ_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef WHLIMBREJ_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR

/* Variables */
#elif defined WHLIMBREJ_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef WHLIMBREJ_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined WHLIMBREJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef WHLIMBREJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined WHLIMBREJ_START_SEC_VAR_CLEARED_BOOLEAN
    #undef WHLIMBREJ_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined WHLIMBREJ_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef WHLIMBREJ_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined WHLIMBREJ_START_SEC_VAR_CLEARED_32
    #undef WHLIMBREJ_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined WHLIMBREJ_STOP_SEC_VAR_CLEARED_32
    #undef WHLIMBREJ_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined WHLIMBREJ_START_SEC_VAR_CLEARED_16
    #undef WHLIMBREJ_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined WHLIMBREJ_STOP_SEC_VAR_CLEARED_16
    #undef WHLIMBREJ_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  WhlImbRej END
 *********************************************************************************************************************/

#endif




/**********************************************************************************************************************
 *  Adc START
 *********************************************************************************************************************/

/*******  CODE sections *******/

#ifdef ADC_START_SEC_CODE
    #undef ADC_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_CODE
    #undef ADC_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#ifdef ADC2_START_SEC_CODE
    #undef ADC2_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef ADC2_STOP_SEC_CODE
    #undef ADC2_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  *******/

#ifdef ADC_START_SEC_CONST_32
    #undef ADC_START_SEC_CONST_32
    #define START_SEC_CONST_32BIT
#endif

#ifdef ADC_STOP_SEC_CONST_32
    #undef ADC_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

#ifdef ADC2_START_SEC_CONST_32
    #undef ADC2_START_SEC_CONST_32
    #define START_SEC_CONST_32BIT
#endif

#ifdef ADC2_STOP_SEC_CONST_32
    #undef ADC2_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  Adc END
 *********************************************************************************************************************/
/** DEM ***************************************************************************/
/*---------------------START-MODULE-SPECIFIC-START-SECTIONS-----------------------*/
                                                              /* code section */
#if defined (DEM_START_SEC_CODE)
    #undef DEM_START_SEC_CODE
    #define START_SEC_CODE
#endif
                                                              /* vars initialized by startup code */
#if defined (DEM_START_SEC_VAR_8BIT)
    #undef DEM_START_SEC_VAR_8BIT
    #define START_SEC_VAR_INIT_8_9
#endif
#if defined (DEM_START_SEC_VAR_32BIT)
    #undef DEM_START_SEC_VAR_32BIT
    #define START_SEC_VAR_INIT_32_9
#endif
                                                              /* never initialized vars with high number of accesses */
#if defined (DEM_START_SEC_VAR_FAST_8BIT)
    #undef DEM_START_SEC_VAR_FAST_8BIT
    #define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_FAST_16BIT)
    #undef DEM_START_SEC_VAR_FAST_16BIT
    #define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined (DEM_START_SEC_VAR_FAST_32BIT)
    #undef DEM_START_SEC_VAR_FAST_32BIT
    #define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
                                                              /* never initialized vars */
#if defined (DEM_START_SEC_VAR_NOINIT_8BIT)
    #undef DEM_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_9
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_16BIT)
    #undef DEM_START_SEC_VAR_NOINIT_16BIT
    #define START_SEC_VAR_NOINIT_16_9
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED)
    #undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
                                                              /* vars saved in non volatile memory */
#if defined (DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
    #undef DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
    #define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
                                                              /* global or static constants */
#if defined (DEM_START_SEC_CONST_8BIT)
    #undef DEM_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#if defined (DEM_START_SEC_CONST_32BIT)
    #undef DEM_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#if defined (DEM_START_SEC_CONST_UNSPECIFIED)
    #undef DEM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
                                                              /* global or static constants (linktime) */
#if defined (DEM_START_SEC_CONST_LCFG)
    #undef DEM_START_SEC_CONST_LCFG
    #define START_SEC_CONST_UNSPECIFIED
#endif
                                                              /* global or static constants (postbuild) */
#if defined (DEM_START_SEC_PBCONST_ROOT)
    #undef DEM_START_SEC_PBCONST_ROOT
    #define START_SEC_CONST_PBCFG
#endif
#if defined (DEM_START_SEC_PBCONST)
    #undef DEM_START_SEC_PBCONST
    #define START_SEC_CONST_PBCFG
#endif
/*---------------------STOP-MODULE-SPECIFIC-START-SECTIONS------------------------*/

/*---------------------START-MODULE-SPECIFIC-STOP-SECTIONS------------------------*/

#if defined (DEM_STOP_SEC_CODE)
    #undef DEM_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#if defined (DEM_STOP_SEC_VAR_8BIT)
    #undef DEM_STOP_SEC_VAR_8BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_32BIT)
    #undef DEM_STOP_SEC_VAR_32BIT
    #define STOP_SEC_VAR
#endif


#if defined (DEM_STOP_SEC_VAR_FAST_8BIT)
    #undef DEM_STOP_SEC_VAR_FAST_8BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_FAST_16BIT)
    #undef DEM_STOP_SEC_VAR_FAST_16BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_FAST_32BIT)
    #undef DEM_STOP_SEC_VAR_FAST_32BIT
    #define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_NOINIT_8BIT)
    #undef DEM_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_16BIT)
    #undef DEM_STOP_SEC_VAR_NOINIT_16BIT
    #define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
    #undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
    #undef DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_CONST_8BIT)
    #undef DEM_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_32BIT)
    #undef DEM_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_UNSPECIFIED)
    #undef DEM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_CONST_LCFG)
    #undef DEM_STOP_SEC_CONST_LCFG
    #define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_PBCONST_ROOT)
    #undef DEM_STOP_SEC_PBCONST_ROOT
    #define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_PBCONST)
    #undef DEM_STOP_SEC_PBCONST
    #define STOP_SEC_CONST
#endif
/*---------------------STOP-MODULE-SPECIFIC-STOP-SECTIONS------------------------*/
/** End of DEM *******************************************************************/

#ifdef DIO_START_SEC_CODE
  #undef DIO_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef DIO_STOP_SEC_CODE
  #undef DIO_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef DIO_START_SEC_CONST_UNSPECIFIED
  #undef DIO_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_32BIT
#endif

#ifdef DIO_STOP_SEC_CONST_UNSPECIFIED
  #undef DIO_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CODE
 #undef GPT_START_SEC_CODE
 #define START_SEC_CODE
#endif

#ifdef GPT_STOP_SEC_CODE
 #undef GPT_STOP_SEC_CODE
 #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CODE_ISR
 #undef GPT_START_SEC_CODE_ISR
 #define START_SEC_CODE_ISR
#endif

#ifdef GPT_STOP_SEC_CODE_ISR
 #undef GPT_STOP_SEC_CODE_ISR
 #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_PBCFG_ROOT
 #undef GPT_START_SEC_PBCFG_ROOT
 #define START_SEC_CONST_PBCFG
#endif

#ifdef GPT_STOP_SEC_PBCFG_ROOT
 #undef GPT_STOP_SEC_PBCFG_ROOT
 #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_PBCFG
 #undef GPT_START_SEC_PBCFG
 #define START_SEC_CONST_PBCFG
#endif

#ifdef GPT_STOP_SEC_PBCFG
 #undef GPT_STOP_SEC_PBCFG
 #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_32BIT
 #undef GPT_START_SEC_CONST_32BIT
 #define START_SEC_CONST_32BIT
#endif

#ifdef GPT_STOP_SEC_CONST_32BIT
 #undef GPT_STOP_SEC_CONST_32BIT
 #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_VAR_32BIT
 #undef GPT_START_SEC_VAR_32BIT
 #define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef GPT_STOP_SEC_VAR_32BIT
 #undef GPT_STOP_SEC_VAR_32BIT
 #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
 #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
 #define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
 #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
 #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  MCU START
 **********************************************************************************************************************/

/****************************************  CODE sections **************************************************************/
#ifdef MCU_START_SEC_CODE
    #undef MCU_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef MCU_STOP_SEC_CODE
    #undef MCU_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  *********************************************************************************************/

#ifdef MCU_START_SEC_PBCFG
    #undef MCU_START_SEC_PBCFG
    #define START_SEC_CONST_PBCFG
#endif
#ifdef MCU_STOP_SEC_PBCFG
    #undef MCU_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_PBCFG_ROOT
  #undef MCU_START_SEC_PBCFG_ROOT
  #define START_SEC_CONST_PBCFG
#endif
#ifdef MCU_STOP_SEC_PBCFG_ROOT
  #undef MCU_STOP_SEC_PBCFG_ROOT
  #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef MCU_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef MCU_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef MCU_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef MCU_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  MCU END
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  PORT START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef PORT_START_SEC_CODE
    #undef PORT_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_CODE
    #undef PORT_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#ifdef PORT_START_SEC_PBCODE
    #undef PORT_START_SEC_PBCODE
    #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_PBCODE
    #undef PORT_STOP_SEC_PBCODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef PORT_START_SEC_PBCFG
    #undef PORT_START_SEC_PBCFG
    #define START_SEC_CONST_PBCFG
#endif

#ifdef PORT_STOP_SEC_PBCFG
    #undef PORT_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif

#ifdef PORT_START_SEC_PBCFG_ROOT
    #undef PORT_START_SEC_PBCFG_ROOT
    #define START_SEC_CONST_PBCFG
#endif

#ifdef PORT_STOP_SEC_PBCFG_ROOT
    #undef PORT_STOP_SEC_PBCFG_ROOT
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef PORT_START_SEC_VAR_UNSPECIFIED
    #undef PORT_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif

#ifdef PORT_STOP_SEC_VAR_UNSPECIFIED
    #undef PORT_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  PORT END 
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  WDG START
 *********************************************************************************************************************/

/* Code section - START */
#if defined WDG_START_SEC_CODE                      /* Code */
    #undef WDG_START_SEC_CODE
    #define START_SEC_CODE
#elif defined WDG_STOP_SEC_CODE
    #undef WDG_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif


#if defined WDG_START_SEC_CONST_8BIT         /* Global or static constants */
    #undef WDG_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#elif defined WDG_STOP_SEC_CONST_8BIT
    #undef WDG_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST

#elif defined WDG_START_SEC_CONST_16BIT
    #undef WDG_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#elif defined WDG_STOP_SEC_CONST_16BIT
    #undef WDG_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST

#elif defined WDG_START_SEC_CONST_32BIT
    #undef WDG_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#elif defined WDG_STOP_SEC_CONST_32BIT
    #undef WDG_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST

#elif defined WDG_START_SEC_CONST_UNSPECIFIED
    #undef WDG_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined WDG_STOP_SEC_CONST_UNSPECIFIED
    #undef WDG_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  WDG END
 *********************************************************************************************************************/








/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef IOHWAB_START_SEC_CODE
    #undef IOHWAB_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef IOHWAB_STOP_SEC_CODE
    #undef IOHWAB_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef IOHWAB_START_SEC_CONST_32BIT
    #undef IOHWAB_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#ifdef IOHWAB_STOP_SEC_CONST_32BIT
    #undef IOHWAB_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef IOHWAB_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef IOHWAB_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10
#endif
#ifdef IOHWAB_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef IOHWAB_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb END
 *********************************************************************************************************************/


#ifdef MEMIF_START_SEC_CONST_8BIT 
    #undef MEMIF_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef MEMIF_STOP_SEC_CONST_8BIT 
    #undef MEMIF_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


#ifdef MEMIF_START_SEC_CONST_32BIT
    #undef MEMIF_START_SEC_CONST_32BIT
	#include "Cd_FeeIf.h"
    #define START_SEC_CONST_32BIT
	#define Fee_Read			TWrapC_Fee_Read
	#define Fee_Write 			TWrapC_Fee_Write
	#define Fee_EraseImmediateBlock 	TWrapC_Fee_EraseImmediateBlock
	#define Fee_InvalidateBlock 		TWrapC_Fee_InvalidateBlock
	#define Fee_Cancel 			TWrapC_Fee_Cancel
	#define Fee_GetStatus 		 (MemIf_ApiGetJobResultType)TWrapC_Fee_GetStatus
	#define Fee_GetJobResult 		 (MemIf_ApiGetJobResultType)TWrapC_Fee_GetJobResult
#endif

#ifdef MEMIF_STOP_SEC_CONST_32BIT
#undef MEMIF_STOP_SEC_CONST_32BIT
#define STOP_SEC_CONST
	#undef Fee_Read
	#undef Fee_Write
	#undef Fee_EraseImmediateBlock
	#undef Fee_InvalidateBlock
	#undef Fee_Cancel
	#undef Fee_GetStatus
	#undef Fee_GetJobResult
#endif



#ifdef MEMIF_START_SEC_CODE
    #undef MEMIF_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef MEMIF_STOP_SEC_CODE
    #undef MEMIF_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 *  If_AsrIfWd START
 *********************************************************************************************************************/

/* Code section - START */
#if defined WDGIF_START_SEC_CODE                      /* Code */
    #undef WDGIF_START_SEC_CODE
    #define START_SEC_CODE
#elif defined WDGIF_STOP_SEC_CODE
    #undef WDGIF_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/* Variables - START */
#if defined WDGIF_START_SEC_VAR_INIT_8BIT           /* Init variables */
    #undef WDGIF_START_SEC_VAR_INIT_8BIT
    #define START_SEC_VAR_INIT_8_0
#elif defined WDGIF_STOP_SEC_VAR_INIT_8BIT
    #undef WDGIF_STOP_SEC_VAR_INIT_8BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_INIT_16BIT
    #undef WDGIF_START_SEC_VAR_INIT_16BIT
    #define START_SEC_VAR_INIT_16_0
#elif defined WDGIF_STOP_SEC_VAR_INIT_16BIT
    #undef WDGIF_STOP_SEC_VAR_INIT_16BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_INIT_32BIT
    #undef WDGIF_START_SEC_VAR_INIT_32BIT
    #define START_SEC_VAR_INIT_32_0
#elif defined WDGIF_STOP_SEC_VAR_INIT_32BIT
    #undef WDGIF_STOP_SEC_VAR_INIT_32BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_INIT_UNSPECIFIED
    #undef WDGIF_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_0
#elif defined WDGIF_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef WDGIF_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_NOINIT_8BIT           /* No init variables */
    #undef WDGIF_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_0
#elif defined WDGIF_STOP_SEC_VAR_NOINIT_8BIT
    #undef WDGIF_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_NOINIT_16BIT
    #undef WDGIF_START_SEC_VAR_NOINIT_16BIT
    #define START_SEC_VAR_NOINIT_16_0
#elif defined WDGIF_STOP_SEC_VAR_NOINIT_16BIT
    #undef WDGIF_STOP_SEC_VAR_NOINIT_16BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_NOINIT_32BIT
    #undef WDGIF_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_NOINIT_32_0
#elif defined WDGIF_STOP_SEC_VAR_NOINIT_32BIT
    #undef WDGIF_STOP_SEC_VAR_NOINIT_32BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef WDGIF_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_0
#elif defined WDGIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef WDGIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_ZERO_INIT_8BIT           /* Zero init variables */
    #undef WDGIF_START_SEC_VAR_ZERO_INIT_8BIT
    #define START_SEC_VAR_CLEARED_8_0
#elif defined WDGIF_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef WDGIF_STOP_SEC_VAR_ZERO_INIT_8BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_ZERO_INIT_16BIT
    #undef WDGIF_START_SEC_VAR_ZERO_INIT_16BIT
    #define START_SEC_VAR_CLEARED_16_0
#elif defined WDGIF_STOP_SEC_VAR_ZERO_INIT_16BIT
    #undef WDGIF_STOP_SEC_VAR_ZERO_INIT_16BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_ZERO_INIT_32BIT
    #undef WDGIF_START_SEC_VAR_ZERO_INIT_32BIT
    #define START_SEC_VAR_CLEARED_32_0
#elif defined WDGIF_STOP_SEC_VAR_ZERO_INIT_32BIT
    #undef WDGIF_STOP_SEC_VAR_ZERO_INIT_32BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDGIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_0
#elif defined WDGIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDGIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_CONST_8BIT         /* Global or static constants */
    #undef WDGIF_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#elif defined WDGIF_STOP_SEC_CONST_8BIT
    #undef WDGIF_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST

#elif defined WDGIF_START_SEC_CONST_16BIT
    #undef WDGIF_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#elif defined WDGIF_STOP_SEC_CONST_16BIT
    #undef WDGIF_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST

#elif defined WDGIF_START_SEC_CONST_32BIT
    #undef WDGIF_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#elif defined WDGIF_STOP_SEC_CONST_32BIT
    #undef WDGIF_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST

#elif defined WDGIF_START_SEC_CONST_UNSPECIFIED
    #undef WDGIF_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined WDGIF_STOP_SEC_CONST_UNSPECIFIED
    #undef WDGIF_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  If_AsrIfWd END
 *********************************************************************************************************************/







/**********************************************************************************************************************
 *  FEE START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FEE_START_SEC_CODE
    #undef FEE_START_SEC_CODE
    #define START_SEC_CODE
 	#define START_SEC_VAR_INIT_UNSPECIFIED_0
#endif
#ifdef FEE_STOP_SEC_CODE
    #undef FEE_STOP_SEC_CODE
    #define STOP_SEC_CODE
	#define STOP_SEC_VAR
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FEE_START_SEC_CONST_UNSPECIFIED
    #undef FEE_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_STOP_SEC_CONST_UNSPECIFIED
    #undef FEE_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  ********************************************************************************************/

/* VAR INIT sections */

#ifdef FEE_START_SEC_VAR_INIT_UNSPECIFIED
    #undef FEE_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_0
#endif
#ifdef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FEE END
 *********************************************************************************************************************/










/**********************************************************************************************************************
 *  NvM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef NVM_START_SEC_CODE
    #undef NVM_START_SEC_CODE
    #define START_SEC_CODE                /* mapped to default code section */
#endif
#ifdef NVM_STOP_SEC_CODE
    #undef NVM_STOP_SEC_CODE
    #define STOP_SEC_CODE                /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef NVM_START_SEC_CONST_8BIT
    #undef NVM_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef NVM_STOP_SEC_CONST_8BIT
    #undef NVM_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_16BIT
    #undef NVM_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#endif
#ifdef NVM_STOP_SEC_CONST_16BIT
    #undef NVM_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_UNSPECIFIED
    #undef NVM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_CONST_UNSPECIFIED
    #undef NVM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
    #undef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
    #undef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef NVM_START_SEC_VAR_NOINIT_8BIT
    #undef NVM_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef NVM_STOP_SEC_VAR_NOINIT_8BIT
    #undef NVM_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR
#endif

#ifdef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef NVM_START_SEC_VAR_UNSPECIFIED
    #undef NVM_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef NVM_STOP_SEC_VAR_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* VAR FAST NOINIT sections */

#ifdef NVM_START_SEC_VAR_FAST_8BIT
    #undef NVM_START_SEC_VAR_FAST_8BIT
    #define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef NVM_STOP_SEC_VAR_FAST_8BIT
    #undef NVM_STOP_SEC_VAR_FAST_8BIT
    #define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  NvM END
 *********************************************************************************************************************/












#ifdef CRC_START_SEC_CODE
    #undef CRC_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef CRC_START_SEC_CONST_8BIT
    #undef CRC_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef CRC_START_SEC_CONST_16BIT
    #undef CRC_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#endif
#ifdef CRC_START_SEC_CONST_32BIT
    #undef CRC_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif

#ifdef CRC_STOP_SEC_CODE
    #undef CRC_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif
#ifdef CRC_STOP_SEC_CONST_8BIT
    #undef CRC_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef CRC_STOP_SEC_CONST_16BIT
    #undef CRC_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST
#endif

#ifdef CRC_STOP_SEC_CONST_32BIT
    #undef CRC_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif



#ifdef DET_START_SEC_CODE
# undef DET_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef DET_STOP_SEC_CODE
# undef DET_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

#ifdef DET_START_SEC_VAR_UNSPECIFIED
# undef DET_START_SEC_VAR_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef DET_STOP_SEC_VAR_UNSPECIFIED
# undef DET_STOP_SEC_VAR_UNSPECIFIED
# define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ECUM_START_SEC_CODE
# undef ECUM_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ECUM_STOP_SEC_CODE
# undef ECUM_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef ECUM_START_SEC_CODE_SET_BOOT_TARGET
# undef ECUM_START_SEC_CODE_SET_BOOT_TARGET
# define START_SEC_CODE                            /* mapped to default fast code section */
#endif
#ifdef ECUM_STOP_SEC_CODE_SET_BOOT_TARGET
# undef ECUM_STOP_SEC_CODE_SET_BOOT_TARGET
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef ECUM_START_SEC_CODE_GET_BOOT_TARGET
# undef ECUM_START_SEC_CODE_GET_BOOT_TARGET
# define START_SEC_CODE                            /* mapped to default ISR code section */
#endif
#ifdef ECUM_STOP_SEC_CODE_GET_BOOT_TARGET
# undef ECUM_STOP_SEC_CODE_GET_BOOT_TARGET
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef ECUM_START_SEC_CONST_8BIT
# undef ECUM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef ECUM_STOP_SEC_CONST_8BIT
# undef ECUM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef ECUM_START_SEC_CONST_UNSPECIFIED
# undef ECUM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ECUM_STOP_SEC_CONST_UNSPECIFIED
# undef ECUM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */

/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef ECUM_START_SEC_CONST_PBCFG_ROOT
# undef ECUM_START_SEC_CONST_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ECUM_STOP_SEC_CONST_PBCFG_ROOT
# undef ECUM_STOP_SEC_CONST_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef ECUM_START_SEC_CONST_PBCFG
# undef ECUM_START_SEC_CONST_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ECUM_STOP_SEC_CONST_PBCFG
# undef ECUM_STOP_SEC_CONST_PBCFG
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef ECUM_START_SEC_VAR_INIT_UNSPECIFIED
# undef ECUM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef ECUM_START_SEC_VAR_NOINIT_8BIT
# undef ECUM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_8BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_16BIT
# undef ECUM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16_9
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_16BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

/* VAR FAST INIT sections */

/* VAR FAST NOINIT sections */

/* VAR FAST ZERO INIT sections */

/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM END
 *********************************************************************************************************************/







/**********************************************************************************************************************
 *  SYSSERVICE_ASRWDM START 
 *********************************************************************************************************************/

/* Code section - START */
#if defined WDGM_START_SEC_CODE                      /* Code */
    #undef WDGM_START_SEC_CODE
    #define START_SEC_CODE
#elif defined WDGM_STOP_SEC_CODE
    #undef WDGM_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif


#if defined WDGM_START_SEC_CONST_8BIT         /* Global or static constants */
    #undef WDGM_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#elif defined WDGM_STOP_SEC_CONST_8BIT
    #undef WDGM_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST

#elif defined WDGM_START_SEC_CONST_16BIT
    #undef WDGM_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#elif defined WDGM_STOP_SEC_CONST_16BIT
    #undef WDGM_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST

#elif defined WDGM_START_SEC_CONST_32BIT
    #undef WDGM_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#elif defined WDGM_STOP_SEC_CONST_32BIT
    #undef WDGM_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST

#elif defined WDGM_START_SEC_CONST_UNSPECIFIED
    #undef WDGM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined WDGM_STOP_SEC_CONST_UNSPECIFIED
    #undef WDGM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  SYSSERVICE_ASRWDM END
 *********************************************************************************************************************/






/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01ExtVx START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef HET_START_SEC_CODE
    #undef HET_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef HET_STOP_SEC_CODE
    #undef HET_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */
#ifdef HET_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef HET_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif

#ifdef HET_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef HET_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01ExtVx END
 *********************************************************************************************************************/


/* Package Merger: Stop Section MemMapModuleList */ 

/*------------------------------GLOBAL-SECTIONS-----------------------------*/
/* Check code sections */
#if ( (defined CODE_SEC_OPEN)                            && \
     ((defined START_SEC_CODE                          ) || \
      (defined START_SEC_CODE_FAST                     ) || \
      (defined START_SEC_CODE_ISR                      )    \
      ))
    #error "MemMap.h: Close the former code segment before opening a new one."
#endif

/* Check const sections */
#if ( (defined CONST_SEC_OPEN)                           && \
     ((defined START_SEC_CONST_8BIT                    ) || \
      (defined START_SEC_CONST_16BIT                   ) || \
      (defined START_SEC_CONST_32BIT                   ) || \
      (defined START_SEC_CONST_UNSPECIFIED             ) || \
      (defined START_SEC_CONST_FAST_8BIT               ) || \
      (defined START_SEC_CONST_FAST_16BIT              ) || \
      (defined START_SEC_CONST_FAST_32BIT              ) || \
      (defined START_SEC_CONST_FAST_UNSPECIFIED        ) || \
      (defined START_SEC_CONST_PBCFG                   )    \
      ))
    #error "MemMap.h: Close the former const segment before opening a new one."
#endif

/* Check data sections */
#if ( (defined VAR_SEC_OPEN)                             && \
     ((defined START_SEC_VAR_INIT_8BIT                 ) || \
      (defined START_SEC_VAR_INIT_16BIT                ) || \
      (defined START_SEC_VAR_INIT_32BIT                ) || \
      (defined START_SEC_VAR_INIT_UNSPECIFIED          ) || \
      (defined START_SEC_VAR_NOINIT_8BIT               ) || \
      (defined START_SEC_VAR_NOINIT_16BIT              ) || \
      (defined START_SEC_VAR_NOINIT_32BIT              ) || \
      (defined START_SEC_VAR_NOINIT_UNSPECIFIED        ) || \
      (defined START_SEC_VAR_ZERO_INIT_8BIT            ) || \
      (defined START_SEC_VAR_ZERO_INIT_16BIT           ) || \
      (defined START_SEC_VAR_ZERO_INIT_32BIT           ) || \
      (defined START_SEC_VAR_ZERO_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_INIT_8BIT            ) || \
      (defined START_SEC_VAR_FAST_INIT_16BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_32BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_NOINIT_8BIT          ) || \
      (defined START_SEC_VAR_FAST_NOINIT_16BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_32BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT       ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)    \
      ))
    #error "MemMap.h: Close the former variable segment before opening a new one."
#endif



/*------------------------------GLOBAL-START-SECTIONS------------------------------*/

/* Code section */
#ifdef START_SEC_CODE                          
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE                          
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CODE_FAST                     
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_FAST                     
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CODE_ISR                      
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_ISR                      
    #undef MEMMAP_ERROR
#endif




/* Const section */
#ifdef START_SEC_CONST_8BIT                    
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_8BIT                    
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_16BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_16BIT                   
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_32BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_32BIT                   
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_UNSPECIFIED             
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_UNSPECIFIED             
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_8BIT               
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_8BIT               
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_16BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_16BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_32BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_32BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_UNSPECIFIED        
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_UNSPECIFIED        
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_PBCFG                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_PBCFG                   
    #undef MEMMAP_ERROR
#endif




/* Var section */
#ifdef START_SEC_VAR_FAST_INIT_8BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_INIT_8BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_16BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_INIT_16BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_32BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_INIT_32BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_8BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_FAST_NOINIT_8BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_16BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_FAST_NOINIT_16BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_32BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_FAST_NOINIT_32BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_8BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_ZERO_INIT_8BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_16BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_ZERO_INIT_16BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_32BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_ZERO_INIT_32BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
#endif

/************************************** Global Shared Variable Sections (AUTOSAR 4.0) *******************************/

#ifdef START_SEC_VAR_INIT_8_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_8_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_16_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_32_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_32_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_8_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_16_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_32_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_32_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_8_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_8_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_16_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_32_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_32_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif


/************************************** Application #0 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:init")

    #undef START_SEC_VAR_INIT_8_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:init")

    #undef START_SEC_VAR_INIT_16_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:init")

    #undef START_SEC_VAR_INIT_32_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_0
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
 #ifdef START_SEC_VAR_CLEARED_8_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_CLEARED_8_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_CLEARED_16_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_CLEARED_32_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_NOINIT_8_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_NOINIT_16_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_NOINIT_32_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_0
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_0
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_0:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_0
    #undef MEMMAP_ERROR
#endif

/************************************** Application #8 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_8_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_16_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_32_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
 #ifdef START_SEC_VAR_CLEARED_8_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_8_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_16_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_32_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_8_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_16_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_32_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif

/************************************** Application #8 Constant Sections ***************************************/
/* Const section */
#ifdef START_SEC_CONST_8_8
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_8_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_16_8
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_16_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_32_8
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_32_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_UNSPECIFIED_8
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_FAST_UNSPECIFIED_8
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_FAST_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_PBCFG_8
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_PBCFG_8
    #undef MEMMAP_ERROR
#endif

/************************************** Application #9 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_8_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_16_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_32_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_9
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
 #ifdef START_SEC_VAR_CLEARED_8_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_8_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_16_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_32_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_8_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_16_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_32_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_9
    #undef MEMMAP_ERROR
#endif

/************************************** Application #10 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_16_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_32_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
 #ifdef START_SEC_VAR_CLEARED_8_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_16_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_32_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_16_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_32_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

/************************************** Application #10 Constant Sections ***************************************/
/* Const section */
#ifdef START_SEC_CONST_8_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_16_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_16_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_32_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_32_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_UNSPECIFIED_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_FAST_UNSPECIFIED_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_FAST_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_PBCFG_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_PBCFG_10
    #undef MEMMAP_ERROR
#endif


/*------------------------------GENERAL-STOP-SECTIONS-------------------------------*/

/*default segment for Code*/
#ifdef STOP_SEC_CODE
    #undef CODE_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
#pragma SET_CODE_SECTION()

    #undef STOP_SEC_CODE
    #undef MEMMAP_ERROR
#endif

/*default segment for Constants*/
#ifdef STOP_SEC_CONST_UNSPECIFIED
    #undef CONST_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
#pragma SET_DATA_SECTION()
    #undef STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR
#endif

/*default segment for Constants*/
#ifdef STOP_SEC_CONST
    #undef CONST_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
#pragma SET_DATA_SECTION()

    #undef STOP_SEC_CONST
    #undef MEMMAP_ERROR
#endif

/*default segment for Datas*/
#ifdef STOP_SEC_VAR
    #undef VAR_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
#pragma SET_DATA_SECTION()

    #undef STOP_SEC_VAR
    #undef MEMMAP_ERROR
#endif


#ifdef MEMMAP_ERROR
    #error "MemMap.h, wrong pragma command"
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
