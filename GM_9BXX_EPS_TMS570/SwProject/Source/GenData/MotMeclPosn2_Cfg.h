
/*****************************************************************************/
/*
 * Copyright 2016 Nexteer Automotive
 * Nexteer Confidential
 *
 * Version Control:
* Date Created:      Mon Aug 3 13:41:03 2015
* %version:          3 %
* %derived_by:       CZ8L9T %
* %date_modified:    Tue Feb 23 13:41:03 2016
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/20/15   1       BDO      	Initial template creation - FDD ES61A version 1 (ICR EA3#423)                 EA3#1651
 * 23/02/16   2 	  Rijvi     Updated per rev. 5 of the design                                              EA3#3953 
*/

#ifndef  MOTMECLPOSN2_CFG_H
#define  MOTMECLPOSN2_CFG_H


#include "CDD_Data.h"       /* Needed for CDD interface mapping */
#include "SpiNxt.h"         /* Needed for SpiNxt interface */
#include "Dma.h"            /* Needed when using DMA for Spi transmission */

/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/

/* Map inputs to MotMeclPosn2_Per1 via CDD interface */
#define MotMeclPosn2_Read_MotMeclPosn2Polarity_Cnt_s08(ptr)                *(ptr) = CDD_MotMeclPosn2Polarity_Cnt_G_s08[CDD_CDDDataAccessBfr_Cnt_G_u16]

/* Map Outputs to application via CDD interface */
#define MotMeclPosn2_Write_MotMeclPosn2RevM_u0p16(Var);                    CDD_MotMeclPosn2RevM_G_u0p16[CDD_CDDDataAccessBfr_Cnt_G_u16] = (Var)        /* Also Used in 62.5uS  of Motor Velocity */
#define MotMeclPosn2_Write_MotMeclPosn2RollgCntr_Cnt_u08(Var);             CDD_MotMeclPosn2RollgCntr_Cnt_G_u08[CDD_CDDDataAccessBfr_Cnt_G_u16] = (Var)

/* Map Outputs via CDD interface using buffering to MotMeclPosn2_Per2 2ms periodic */
#define MotMeclPosn2_Write_MotMeclPosn2RawErrReg_Cnt_u16(Var)              CDD_MotMeclPosn2RawErrReg_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16] = (Var) /* Use CDD interface and buffering scheme to provide sync */
#define MotMeclPosn2_Write_MotMeclPosn2UnderVltgFaultAccum_Cnt_u16(Var)    CDD_MotMeclPosn2UnderVltgFaultAccum_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16] = (Var)
#define MotMeclPosn2_Write_MotMeclPosn2ParityFaultAccum_Cnt_u16(Var)       CDD_MotMeclPosn2ParityFaultAccum_Cnt_G_u16[CDD_CDDDataAccessBfr_Cnt_G_u16] = (Var)


/* macro definitions for SPI functions using SpiNxt */
/* #define	 MSB2GetData(ptr)                mibspiGetData (mibspiREG5, TRANS_GRP_0, ptr) */ /* Map SPI5 function name  arg1 -MIBSPI5 name    arg2    group notification      arg3 - Transmit data*/
/* Note - if using DMA component map the SPI functions accordingly and remove mapping above. */
#define MSB2GetData(ptr)                    (ptr)[0] = DMAData_G_str.SlowSPI_Cnt_u16[0]; \
                                            (ptr)[1] = DMAData_G_str.SlowSPI_Cnt_u16[1]; \
                                            (ptr)[2] = DMAData_G_str.SlowSPI_Cnt_u16[2]

#define MSB2SetData(ptr)                    mibspiSetData (mibspiREG5, TRANS_GRP_0, ptr)    /* Map SPI5 function name  arg1 -MIBSPI5 name    arg2    group notification      arg3 - receive data*/

#define MSB2EnableDataTransfer()            mibspiTransfer (mibspiREG5, TRANS_GRP_0)  /* Enable MIBSPI5 transfer group 0 */

#define MSB2GetConfig(ptr)                  mibspiGetData (mibspiREG5, TRANS_GRP_1, ptr)    /* Map SPI5 function name  arg1 -MIBSPI5 name    arg2    group notification      arg3 - Transmit data*/
#define MSB2SetConfig(ptr)                  mibspiSetData (mibspiREG5, TRANS_GRP_1, ptr)    /* Map SPI5 function name  arg1 -MIBSPI5name    arg2    group notification      arg3 - receive data*/

#define MSB2EnableConfigTransfer()          mibspiTransfer (mibspiREG5, TRANS_GRP_1)  /* Enable MIBSPI5 transfer group 1 */

/*** End of file **************************************************************/

#endif /* MOTMECLPOSN2_CFG_H */
