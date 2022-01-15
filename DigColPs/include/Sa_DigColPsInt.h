/***********************************************************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Sa_DigColPsInt.h
* Module Description: Digital Column Position Sensor I2C Interface
* Product           : Gen II Plus - EA3.0
* Author            : Jared Julien
*
***********************************************************************************************************************/
/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/
/* Version Control:
 * Date Created:      Thur Aug 8 11:20:41 2013 %
 * %version:          EA3#5 %
 * %derived_by:       czmgrw %
 * %date_modified:    Fri Aug 23 15:04:11 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/08/13  1        Jared     New driver for initial use with DigColPs component                              8850
 * 03/20/14  2        Rijvi     Update to FDD rev.004                                                           11266
 *                              Update to FDD rev.005 (anomaly# 6471)                                           11594
 *                              Fix Anomaly# 6089                                                               11611
 * 06/30/14  3        Jared     Updated to FDD rev 008 (Dual Spur design)                                       12145
 * 11/11/16  5        JK        Updated to FDD rev 020                                                      EA3#12066
 */
/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/
#ifndef __DIGCOLPSINT_H__
#define __DIGCOLPSINT_H__
/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/

FUNC(void, SA_DIGCOLPS_CODE) DigColPsInt_Init(void);
FUNC(uint8, SA_DIGCOLPS_CODE) DigColPsInt_GetData(
	P2VAR(uint16, AUTOMATIC, AUTOMATIC) ColSnsrDataPtr_Cnt_T_u16,
	P2VAR(uint16, AUTOMATIC, AUTOMATIC) SpurSnsrDataPtr_Cnt_T_u16,
	P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataTypePtr_Cnt_T_u08
);
FUNC(void, SA_DIGCOLPS_CODE) DigColPsInt_StartRequest(VAR(uint8, AUTOMATIC) Type_Cnt_T_u08);
FUNC(void, SA_DIGCOLPS_CODE) DigColPsInt_InterruptNotification(VAR(uint16, AUTOMATIC) Flags_Cnt_T_b16);
FUNC(void, SA_DIGCOLPS_CODE) DigColPsInt_GetPhaNvmData(P2VAR(CustReadCmplType, AUTOMATIC,AUTOMATIC) ColCustDataReadCmpl_Cnt_T_lgc,
		P2VAR(CustReadCmplType, AUTOMATIC,AUTOMATIC) SpurCustDataReadCmpl_Cnt_T_lgc,
		P2VAR(CustDataType, AUTOMATIC,AUTOMATIC) ColCustData_Uls_T_u32,
		P2VAR(CustDataType, AUTOMATIC,AUTOMATIC) SpurCustData_Uls_T_u32);
FUNC(void, SA_DIGCOLPS_CODE) DigColPsInt_Reset(void);



/* --- Customer Data Bit Definitions --- */
#define D_I2CHWCUSTDATAUNKWN_CNT_U16   0x01FFU
#define D_I2CHWCUSTDATACOL_CNT_U16     0x000FU
#define D_I2CHWCUSTDATASPUR_CNT_U16    0x00F0U
#define D_EXTREADADRREGCNT_CNT_U08 6U


/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/
#endif
