
#ifndef COMM_TYPES_H
#define COMM_TYPES_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "rte_type.h"
#include "il_inc.h"

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/* network bus types */
#define COMM_BUS_TYPE_CAN       0u
#define COMM_BUS_TYPE_FR        1u
#define COMM_BUS_TYPE_INTERNAL  2u
#define COMM_BUS_TYPE_LIN       3u

typedef uint8 ComM_BusType;

/* Initialization status of the ComM */
typedef enum {
  COMM_UNINIT = 0,
  COMM_INIT
} ComM_InitStatusType;

/* communication mode type with sub modes */
typedef enum {
  COMM_NO_COM = 0,
  COMM_SI_COM,
  COMM_READY_TO_SLEEP,
  COMM_NETWORK_REQUESTED
}ComM_SubModeType;

/* DCM request type */
typedef enum {
  COMM_DCM_REQ_INACTIVE,
  COMM_DCM_REQ_ACTIVE
}ComM_DcmReqStateType;

/* user byte type */
typedef struct{
  CanChannelHandle channel;
  vuint8           vnHdnl;
}ComM_UserToChannelAndVnTblType;

#endif
/* STOPSINGLE_OF_MULTIPLE */
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
