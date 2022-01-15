/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  Copyright (c) 2007 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
         File:  MemDef.h
      Project:  GMLAN Handler Calibration
       Module:  -
    Generator:  -
  Description:  Template for the definition of memory qualifiers and memory mapping
                of the calibration parameters of the GMLAN Handler.
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Initials     Name                      Company
-----------------------------------------------------------------------------------------------------------------------
  vistri       Frank Triem               Vector Informatik GmbH
  vismas       Markus Schwarz            Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  1.00.00   2007-03-28  vistri                creation
  1.01.00   2007-11-20  vismas                added GMLCAL_MEMROM3
                                              corrected locking mechanism for multiple includes
                                              adapted to current coding template
**********************************************************************************************************************/

#if defined ( V_MEMDEF_HEADER )
#else
#define V_MEMDEF_HEADER

/**********************************************************************************************************************
  Includes
**********************************************************************************************************************/
#include "v_def.h"

/* Default definition of memory qualifiers */
#define GMLCAL_MEMROM0  V_MEMROM0
#define GMLCAL_MEMROM1  V_MEMROM1
#define GMLCAL_MEMROM2  V_MEMROM2
#define GMLCAL_MEMROM3  V_MEMROM3

#endif /* V_MEMDEF_HEADER */

/* Note: This part of the code may not be locked against multiple includes */

/* Check of section utilization */
#if defined ( GMLCAL_START_SEC_CONST ) && defined ( GMLCAL_STOP_SEC_CONST )
  #error "Utilization of start and stop of sections inconsistent!"
#endif

/* Definition of section for calibration parameters. */
#if defined ( GMLCAL_START_SEC_CONST )
  #undef GMLCAL_START_SEC_CONST
  /* Enter your #pragma definitions here:
     e.g. #pragma section .CALIBRATION
  */
#endif

/* Definition of section for default parameters. */
#if defined ( GMLCAL_STOP_SEC_CONST )
  #undef GMLCAL_STOP_SEC_CONST
  /* Enter your #pragma definitions here:
     e.g.  #pragma section .DEFAULT
  */
#endif

/**********************************************************************************************************************
  EOF
**********************************************************************************************************************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
