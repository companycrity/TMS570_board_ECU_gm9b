#ifndef COMM_H
#define COMM_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "ComM_cfg.h"                /* Include ComM configuration header */

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/* advanced return type of the communication manager */
#define COMM_E_MODE_LIMITATION        2u                  /* mode is limited and can not be requested by the ComM User */

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  INTERNAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/* memory intialization function of ComM */
extern FUNC(void, COMM_CODE) ComM_InitMemory(void);

/* initialization function of the ComM */
extern FUNC(void, COMM_CODE) ComM_Init(void);

/* de-initlization function of the ComM */
extern FUNC(void, COMM_CODE) ComM_DeInit(void);

/* request a communication mode for an User */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode(ComM_UserHandleType User, ComM_ModeType ComMode);

/* Get the requested communication mode of an user */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode);

/* Get the current communication mode of an user */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode);

/* Get the current maximum allowed mode of an user*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode);

#endif /* #ifndef COMM_H */
