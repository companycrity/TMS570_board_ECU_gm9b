/*****************************************************************************
* Copyright 2010 Nexteer Automotive, All Rights Reserved.
* Nexteer Confidential
*
* Module File Name  : Sa_MotMeclPosn1_Cfg.h
* Module Description: Configuration file of MotMeclPosn
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 30.11.2012 08:09:43
*****************************************************************************/
/* Version Control:
 * Date Created:      Thu Aug 20 18:34:17 2015
 * %version:          1 %
 * %date_modified:    Thu Aug 20 18:34:17 2015 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/20/15   1       BDO      	Initial template creation - FDD ES60A version 1 (ICR EA3#423)                 EA3#1650
*/

#ifndef  MOTMECLPOSN1_CFG_H
#define  MOTMECLPOSN1_CFG_H

#include "CDD_Data.h"       /* Needed for CDD interface mapping */
#include "SpiNxt.h"         /* Needed for SpiNxt interface */
#include "Dma.h"            /* Needed when using DMA for Spi transmission */

/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/

/* Map inputs to MotMeclPosn1_Per1 via CDD interface */
#define MotMeclPosn1_Read_MotMeclPosn1Polarity_Cnt_s08(ptr)     *(ptr) = CDD_MotMeclPosn1Polarity_Cnt_G_s08[CDD_CDDDataAccessBfr_Cnt_G_u16]

/* Map Outputs to application via CDD interface */
#define MotMeclPosn1_Write_MotMeclPosn1MeasdTi_uS_u32(Var);     CDD_MotMeclPosn1MeasdTi_uS_G_u32[CDD_CDDDataAccessBfr_Cnt_G_u16] = (Var)    /* Also Used in 62.5uS  of Motor Velocity */
#define MotMeclPosn1_Write_MotMeclPosn1RevM_u0p16(Var);         CDD_MotMeclPosn1RevM_G_u0p16[CDD_CDDDataAccessBfr_Cnt_G_u16] = (Var)        /* Also Used in 62.5uS  of Motor Velocity */
#define MotMeclPosn1_Write_MotMeclPosn1RollgCntr_Cnt_u08(Var);  CDD_MotMeclPosn1RollgCntr_Cnt_G_u08[CDD_CDDDataAccessBfr_Cnt_G_u16] = (Var)

/* Map Outputs via CDD interface using buffering to MotMeclPosn1_Per2 2ms periodic */
#define MotMeclPosn1_Write_MotMeclPosn1RawErrReg_Cnt_u16(Var)           CDD_MotMeclPosn1RawErrReg_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16] = (Var) /* Use CDD interface and buffering scheme to provide sync */
#define MotMeclPosn1_Write_MotMeclPosn1UnderVltgFaultAccum_Cnt_u16(Var) CDD_MotMeclPosn1UnderVltgFaultAccum_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16] = (Var)
#define MotMeclPosn1_Write_MotMeclPosn1ParityFaultAccum_Cnt_u16(Var)    CDD_MotMeclPosn1ParityFaultAccum_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16] = (Var)

/* Macro definitions for SPI functions using SpiNxt */
/* #define MSB1GetData(ptr)            mibspiGetData (mibspiREG3, TRANS_GRP_0, ptr) */ /* Map SPI3 function name  arg1 -MIBSPI3 name    arg2    group notification      arg3 - Transmit data */
/* Note - if using DMA component map the SPI functions accordingly and remove mapping above. */
#define MSB1GetData(ptr)            (ptr)[0] = DMAData_G_str.FastSPI_Cnt_u16[0]; \
                                    (ptr)[1] = DMAData_G_str.FastSPI_Cnt_u16[1]; \
                                    (ptr)[2] = DMAData_G_str.FastSPI_Cnt_u16[2]

#define MSB1SetData(ptr)            mibspiSetData (mibspiREG3, TRANS_GRP_0, ptr)    /* Map SPI3 function name  arg1 -MIBSPI3 name    arg2    group notification      arg3 - receive data*/

#define MSB1EnableDataTransfer()    mibspiTransfer (mibspiREG3, TRANS_GRP_0)        /* Enable MIBSPI3 transfer group 0 */

#define MSB1GetConfig(ptr)          mibspiGetData (mibspiREG3, TRANS_GRP_1, ptr)    /* Map SPI3 function name  arg1 -MIBSPI3 name    arg2    group notification      arg3 - Transmit data*/
#define MSB1SetConfig(ptr)          mibspiSetData (mibspiREG3, TRANS_GRP_1, ptr)    /* Map SPI3 function name  arg1 -MIBSPI3 name    arg2    group notification      arg3 - receive data*/

#define MSB1EnableConfigTransfer() mibspiTransfer (mibspiREG3, TRANS_GRP_1)        /* Enable MIBSPI3 transfer group 1 */

/*** End of file **************************************************************/

#endif /* MOTMECLPOSN1_CFG_H */
