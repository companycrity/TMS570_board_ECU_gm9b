/***********************************************************************************************************************
* Copyright 2013 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : EPS_DiagSrvcs_ISO.Customer.h file
* Module Description: Common Manufacturing services
* Product           : Gen II Plus - EA3.0
* Author            : czgng4
*
* Notes:
* This file contains configurations for ISO services.
*
***********************************************************************************************************************/

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                 DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Jul 01 09:30:12 2013
 * %version:          EA3#5 %
 * %derived_by:       fz9hxm %
 * %date_modified:    Fri Oct 25 13:47:46 2013 %
 * --------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                           SCR #
 * --------  -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 */
/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                   DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include area >>                         DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/
#include "EPS_DiagSrvcs_CommonData.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include area >>                           DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/
#ifndef EPS_DIAGSRVCS_ISO_CUSTOMER_H
#define EPS_DIAGSRVCS_ISO_CUSTOMER_H

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom include area >>                  DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/
#include "EPS_DiagSrvcs_ISO.Interface.h"

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom include area >>                    DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of custom define area >>                   DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/

/* This is the number of Program Specific PIDs in the LUT */
#define	D_DIAGSRCVS_PROGPIDTBLSIZE_CNT_U16	22U

/****************************** BEGIN CMS GENERATION - DO NOT CHANGE/REMOVE THIS COMMENT ******************************/

/* Routine I/O Services */
#if (D_EPSDIAGSRVRIDFCE0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_RID_FCE0 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_RID_FCE0	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVRIDFCE0_CNT_ENUM == D_DIAGSRVC_ENABLED) */


/* PID and I/O Control Services */
#if (D_EPSDIAGSRVPIDFEE0_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE0 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE0	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE0_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE1 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE1	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE1_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE2_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE2 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE2	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE2_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE3 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE3	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE3_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE4 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE4	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE4_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE5 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE5	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE5_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE6_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE6 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE6	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE6_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE7 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE7	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE7_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEE8_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEE8 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEE8	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEE8_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEEA_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEEA (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEEA	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEEA_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEEB_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEEB (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEEB	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEEB_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEEC_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEEC (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEEC	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEEC_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEED_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEED (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEED	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEED_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEEF_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEEF (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEEF	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEEF_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEF1_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEF1 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEF1	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEF1_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEF3_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEF3 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEF3	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEF3_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEF4_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEF4 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEF4	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEF4_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEF5_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEF5 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEF5	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEF5_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEF6_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEF6 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEF6	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEF6_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEF7_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEF7 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEF7	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEF7_CNT_ENUM == D_DIAGSRVC_ENABLED) */

#if (D_EPSDIAGSRVPIDFEF8_CNT_ENUM == D_DIAGSRVC_ENABLED)
	extern FUNC(uint8, EPSDIAGSRVC_CODE) EPSInternal_PID_FEF8 (VAR(uint8, EPSDIAGSRVC_VAR) SubFunc_Cnt_T_u08, VAR(uint8, EPSDIAGSRVC_VAR) DataBuffer_Uls_T_u08[], VAR(CM_MsgLenType, EPSDIAGSRVC_VAR) RequestLen_Cnt_T_u16, P2VAR(CM_MsgLenType, EPSDIAGSRVC_VAR, EPSDIAGSRVC_VAR) RespLength_Cnt_T_u16);
#else
	#define EPSInternal_PID_FEF8	DiagSrvNullFunc
#endif /* (D_EPSDIAGSRVPIDFEF8_CNT_ENUM == D_DIAGSRVC_ENABLED) */

/******************************* END CMS GENERATION - DO NOT CHANGE/REMOVE THIS COMMENT *******************************/

/***********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of custom define area >>                     DO NOT CHANGE THIS COMMENT!
 **********************************************************************************************************************/

#endif /* EPS_DIAGSRVCS_ISO_CUSTOMER_H */
