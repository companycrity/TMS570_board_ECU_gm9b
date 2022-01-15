/* Kernbauer Version: 1.14 Konfiguration: Il_Vector_Gm Erzeugungsgangnummer: 607 */

/* STARTSINGLE_OF_MULTIPLE */
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2000-2010 by Vector Informatik GmbH. All rights reserved.
 
                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  Il_Inc.h
      Project:  Il_Vector
       Module:  -
    Generator:  -

  \brief Description:  Vector Interaction Layer include header file
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
-----------------------------------------------------------------------------------------------------------------------
  Heike Honert                  Ht            Vector Informatik GmbH
  Georg Pfluegel                Pl            Vector Informatik GmbH
  Armin Happel                  Hp            Vector Informatik GmbH
  Gunnar Meiss                  Ms            Vector Informatik GmbH
  Ralf Fritz                    Fz            Vector Informatik GmbH
  Patrick Markl                 Ml            Vector Informatik GmbH
  Sebastian Waldvogel           Swa           Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  01.00.00  2001-04-18  Ht                    Creation
  01.01.00  2002-05-15  Pl                    add STARTSINGLE_OF_MULTIPLE and STOPSINGLE_OF_MULTIPLE
  01.02.00  2002-08-16  Ht                    avoid multiple include
  01.03.00  2003-07-18  Hp                    Include NM-Header for certain OEM's only.
  01.04.00  2004-08-18  Ms      ESCAN00009633 Naming Conventions
  01.05.00  2005-05-09  Ms      ESCAN00008746 Geny Compatibility
  01.06.00  2005-11-17  Ms      ESCAN00013712 added AUTOSAR Pdu Interface
  01.07.00  2006-04-10  Ms      ESCAN00016017 Add include for Il_Ni
  01.08.00  2007-03-30  Fz      ESCAN00020135 GM-Only: Include file added
  05.00.00  2008-01-10  Ms      ESCAN00023206 Split Oem Extensions
                        Ms      ESCAN00023270 No changes here
                        Ms      ESCAN00023300 No changes here
                        Ms      ESCAN00023284 No changes here
                        Ms      ESCAN00023821 No changes here
                        Ms      ESCAN00023822 GM-Only: No changes here
  05.01.00  2008-01-25  Ms      ESCAN00023109 PSA-Only: No changes here
  05.02.00  2008-04-21  Ms      ESCAN00026301 No changes here
            2008-07-17  Ms      ESCAN00025002 No changes here
                        Ms      ESCAN00028780 No changes here
                        Ms      ESCAN00025178 No changes here
                        Ms      ESCAN00013854 No changes here
  05.02.01  2008-10-17  Ms      ESCAN00029307 No changes here
                        Ms      ESCAN00030750 No changes here
  05.02.02  2009-08-28  Ml      ESCAN00037350 No changes here
  05.03.00  2009-11-19  Swa     ESCAN00039257 No changes here
                        Swa     ESCAN00039071 No changes here
                        Swa     ESCAN00039274 No changes here
            2010-04-20  Swa     ESCAN00042420 No changes here
  05.04.00  2010-06-14  Swa     ESCAN00043305 No changes here
            2010-06-28  Ms      ESCAN00042424 No changes here
**********************************************************************************************************************/
#if defined ( IL_TYPE_GM )
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2000-2009 by Vector Informatik GmbH. All rights reserved.
 
                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  Il_Inc.h
      Project:  Il_Vector_Gm
       Module:  -
    Generator:  -

  \brief Description:  Vector Interaction Layer Gm include header file
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
-----------------------------------------------------------------------------------------------------------------------
  Gunnar Meiss                  Ms            Vector Informatik GmbH
  Sebastian Waldvogel           Swa           Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  01.00.00  2007-06-14  Ms      ESCAN00023204 Creation
            2007-12-03  Ms      ESCAN00023444 No changes here
            2007-12-05  Ms      ESCAN00023551 No changes here
  01.00.01  2008-04-08  Ms      ESCAN00025874 No changes here
  01.00.02  2008-07-30  Ms      ESCAN00013854 No changes here
            2009-02-18  Ms      ESCAN00033184 Update Il_Vector Core to Package 6.01.03
  01.00.03  2010-05-06  Swa     ESCAN00042787 Update Il_Vector Core to Package 6.02.00
  01.00.04  2010-07-01  Swa     ESCAN00043389 Update Il_Vector Core to Package 6.03.00
  01.00.05  2010-09-02  Ms      ESCAN00044234 No changes here
  01.00.06  2010-09-27  Ms      ESCAN00045554 No changes here
**********************************************************************************************************************/
#endif /* IL_TYPE_GM */

#if !defined ( V_IL_INC_COMPONENT_HEADER )
# define V_IL_INC_COMPONENT_HEADER
/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

#  include "v_cfg.h"            /* Generated file...... */

#  if defined ( VGEN_GENY )
#   include "v_inc.h"           /* Generated file...... */
#  endif

#  include "il_cfg.h"

#  if !defined ( VGEN_GENY )
#  endif

#  if defined ( VGEN_GENY )
#   include "il_par.h"          /* Generated file...... */
#  endif

#  include "il_def.h"           /* Il_Vector definition file. */

#  if( IL_VECTOR_VERSION != 0x0504 )
#   error "Source and Header file are inconsistent!"
#  endif
#  if( IL_VECTOR_RELEASE_VERSION != 0x00 )
#   error "Source and Header file are inconsistent!"
#  endif


#  if defined ( IL_TYPE_GM )
#   include "gmlcal.h"
#   if defined ( VGEN_ENABLE_NM_GMLAN )
#    include "gmnmdef.h"
#   endif
        /* VGEN_ENABLE_NM_GMLAN */
#  endif
       /* IL_TYPE_GM */

/**********************************************************************************************************************
  END OF FILE: il_inc.h
**********************************************************************************************************************/
#endif /* V_IL_INC_COMPONENT_HEADER */
/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
