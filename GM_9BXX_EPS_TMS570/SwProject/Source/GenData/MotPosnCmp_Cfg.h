/*
 * Copyright 2015 Nexteer Automotive
 * Nexteer Confidential
 *
 * Version Control:
* Date Created:      Mon Aug 24 13:41:03 2015
* %version:          1 %
* %derived_by:       CZ8L9T %
* %date_modified:     Mon Aug 24 13:41:03 2015
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * --------  -------  --------  -------------------------------------------------------------------------------  ------
 * 08/19/15  1.0 	 Selva       Initial Version FDD ES62A v01 (ICR EA3#2490)                                       EA3#2765
 *
 */

#ifndef  MOTPOSNCMP_CFG_H
#define  MOTPOSNCMP_CFG_H

#include "CDD_Data.h"

/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/

/* Map inputs to MotMeclPosn1_Per1 via CDD interface */
#define MotPosnCmp_Read_MtrPosMecl_Rev_u0p16(ptr) (*ptr = CDD_MtrPosMecl_RevM_G_u0p16[CDD_CDDDataAccessBfr_Cnt_G_u16])

/* Map Outputs via CDD interface using buffering to MotPosnCmp_Per2 2ms periodic */
#define MotPosnCmp_Write_MotPosnCumvAlgnd_Rev_s15p16(Val) (CDD_MotPosnCumvAlgnd_Rev_G_s15p16[CDD_CDDDataAccessBfr_Cnt_G_u16] = Val)

/*Use CDD interface and buffering scheme to provide sync*/
#define MotPosnCmp_Write_MotPosnElec_Rev_T_u0p16(Val) (CDD_MotPosnElec_Rev_G_u0p16[CDD_CDDDataAccessBfr_Cnt_G_u16] = Val)

#endif

