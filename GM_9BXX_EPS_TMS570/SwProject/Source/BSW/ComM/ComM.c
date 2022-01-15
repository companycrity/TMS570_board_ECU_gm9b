

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "ComM.h"                                     /* Include Commmunication Manager */
#include "EcuM.h"                                     /* Include Ecu Manager */


/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/


/**********************************************************************************************************************
  COMPATIBILITY / DEFAULTS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  FILE LOCAL DEFINES
**********************************************************************************************************************/

/**********************************************************************************************************************
  FILE LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  ROM DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
static FUNC(Std_ReturnType, COMM_CODE) ComM_GetChannelAndVnInfo(ComM_UserHandleType User, CanChannelHandle *channel, vuint8 *vnHndl);

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/*********************************************************************************************************************
  FUNCTION: ComM_GetChannelAndVnInfo
----------------------------------------------------------------------------------------------------------------------
  API     Type                    Name                    Description
----------------------------------------------------------------------------------------------------------------------
   Input:  ComM_UserHandleType     User                   user handle
   Output: CanChannelHandle        *channel               CAN channel which the user coresponds to
           vuint8                  *vnHndl                VN handle for this user
  Return: Std_ReturnType                                  return value of ComM API
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: upper layer
  Precondition: ComM must be initialized via the function ComM_Init

  Function to query the maximum allowed communication mode of the corresponding user.
*********************************************************************************************************************/
static FUNC(Std_ReturnType, COMM_CODE) ComM_GetChannelAndVnInfo(ComM_UserHandleType User, CanChannelHandle *channel, vuint8 *vnHndl)
{
    Std_ReturnType retValue;
    retValue = E_NOT_OK;

    if(User < COMM_MAX_NUMBER_OF_USERS)
    {
        *channel = ComM_UserToChannelAndVnTbl[User].channel; 
        *vnHndl  = ComM_UserToChannelAndVnTbl[User].vnHdnl;
        retValue = E_OK;
    }

    return retValue;
}

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/

/*********************************************************************************************************************
  FUNCTION: ComM_InitMemory
----------------------------------------------------------------------------------------------------------------------
  API     Type                     Name                    Description
----------------------------------------------------------------------------------------------------------------------
   Input: -
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: Ecu Manager
  Precondition: 

  Initialize the ComM variables which are could be used if the ComM is not initialized.
*********************************************************************************************************************/
FUNC(void, COMM_CODE) ComM_InitMemory(void)
{
}

/*********************************************************************************************************************
  FUNCTION: ComM_Init
----------------------------------------------------------------------------------------------------------------------
  API     Type                     Name                    Description
----------------------------------------------------------------------------------------------------------------------
   Input: -
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: Ecu Manager
  Precondition: -

  Initializes the communication manager and the communication stack.
*********************************************************************************************************************/
FUNC(void, COMM_CODE) ComM_Init(void)
{
}

/*********************************************************************************************************************
  FUNCTION: ComM_DeInit
----------------------------------------------------------------------------------------------------------------------
  API     Type                     Name                    Description
----------------------------------------------------------------------------------------------------------------------
   Input: -
  Output: -
  Return: -
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: Ecu Manager
  Precondition: De-Init shall only be performed if the ComM is in " No Communication" state.

  De-Initialize the communication manager, the communication modules including the network management.
*********************************************************************************************************************/
FUNC(void, COMM_CODE) ComM_DeInit(void)
{
}

/*********************************************************************************************************************
  FUNCTION: ComM_RequestComMode
----------------------------------------------------------------------------------------------------------------------
  API     Type                    Name                    Description
----------------------------------------------------------------------------------------------------------------------
   Input: ComM_UserHandleType     User                    handle of the user how requests a mode
          ComM_ModeType           ComMode                 requested communication mode possible values are:
                                                          COMM_NO_COMMUNICATION
                                                          COMM_SILENT_COMMUNICATION
                                                          COMM_FULL_COMMUNICATION
  Output: -
  Return: Std_ReturnType                                   return value of ComM API
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: upper layer
  Precondition: ComM must be initialized via the function ComM_Init

  Requesting of a communication mode by a user
*********************************************************************************************************************/
FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode(ComM_UserHandleType User, ComM_ModeType ComMode)
{
  Std_ReturnType   retValue;
  Nm_Status        retValueGMLAN;
  CanChannelHandle channel;
  vuint8           vnHndl;
  
  retValue = E_NOT_OK;

  switch(ComMode)
  {
    case COMM_NO_COMMUNICATION: 
      if(ComM_GetChannelAndVnInfo(User,&channel,&vnHndl)==E_OK)
      {
        retValueGMLAN = IlNwmDeactivateVN( channel,  vnHndl );
        switch(retValueGMLAN)
        {
        case NM_OK:
        case NM_INACTIVE:
            retValue = E_OK;
            break;
        default:
            retValue = E_NOT_OK;
            break;
        }
      }
      break;
    case COMM_FULL_COMMUNICATION:
      
      if(ComM_GetChannelAndVnInfo(User,&channel,&vnHndl)==E_OK)
      {
        retValueGMLAN = IlNwmActivateVN( channel,  vnHndl );
        switch(retValueGMLAN)
        {
          case NM_HALTED:
          case NM_INHIBITED:
            retValue = COMM_E_MODE_LIMITATION;
            break;
          case NM_OK:    
            retValue = E_OK;
            break;
          case NM_ERROR:
          case NM_WRONG_ARG:
          case NM_INACTIVE:
            default:
            retValue = E_NOT_OK;
            break;
        }
      }
        break;
    default:
        retValue = E_NOT_OK;
        break;
  }
  return retValue;
}


/*********************************************************************************************************************
  FUNCTION: ComM_GetRequestedComMode
----------------------------------------------------------------------------------------------------------------------
  API     Type                    Name                    Description
----------------------------------------------------------------------------------------------------------------------
   Input: ComM_UserHandleType     User                    user handle
          ComM_ModeType           *ComMode                communication mode
  Output: ComM_ModeType           *ComMode                communication mode
  Return: Std_ReturnType                                  return value of ComM API
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: upper layer
  Precondition: ComM must be initialized via the function ComM_Init

  Function to query the currently highest requested communication mode of the corresponding user.
*********************************************************************************************************************/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode)
{
  Std_ReturnType   retValue;
  CanChannelHandle channel;
  vuint8           vnHndl;
  vuint8           vnState;

  retValue = E_NOT_OK;

  if(ComM_GetChannelAndVnInfo(User,&channel,&vnHndl)==E_OK)
  {
    vnState = IlNwmIsActiveVN(channel, vnHndl);
    if(vnState!=0)
    {
       *ComMode = COMM_FULL_COMMUNICATION;
    }
    else
    {
       *ComMode = COMM_NO_COMMUNICATION;
    }
    retValue = E_OK;
  }

  return retValue;
}

/*********************************************************************************************************************
  FUNCTION: ComM_GetCurrentComMode
----------------------------------------------------------------------------------------------------------------------
  API     Type                    Name                    Description
----------------------------------------------------------------------------------------------------------------------
   Input: ComM_UserHandleType     User                    user handle
          ComM_ModeType           *ComMode                communication mode
  Output: ComM_ModeType           *ComMode                communication mode
  Return: Std_ReturnType                                  return value of ComM API
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: upper layer
  Precondition: ComM must be initialized via the function ComM_Init

  Function to query the current communication mode of the corresponding user.
*********************************************************************************************************************/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode)
{
  Std_ReturnType   retValue;

  retValue = ComM_GetRequestedComMode(User, ComMode);

  return retValue;
}

/*********************************************************************************************************************
  FUNCTION: ComM_GetMaxComMode
----------------------------------------------------------------------------------------------------------------------
  API     Type                    Name                    Description
----------------------------------------------------------------------------------------------------------------------
   Input: ComM_UserHandleType     User                    user handle
          ComM_ModeType           *ComMode                max allowed communication mode
  Output: ComM_ModeType           *ComMode                max allowed communication mode
  Return: Std_ReturnType                                  return value of ComM API
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: upper layer
  Precondition: ComM must be initialized via the function ComM_Init

  Function to query the maximum allowed communication mode of the corresponding user.
*********************************************************************************************************************/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode)
{
  Std_ReturnType   retValue;
  CanChannelHandle channel;
  vuint8           vnHndl;
  nmStatusType     nmState;

  retValue = E_NOT_OK;

  if(ComM_GetChannelAndVnInfo(User,&channel,&vnHndl)==E_OK)
  {
    nmState = IlNwmGetStatus(channel);

    retValue = E_OK;
 
    if(
        (IlNwmStateLowVoltageModeActive(nmState)!=0) ||
        (IlNwmStateBusOffOccured(nmState)!=0)        ||
        (IlNwmStateNoCommunication(nmState)!=0)      ||     
        (IlNwmStateHispeedMode(nmState)!=0)          ||         
        (IlNwmStateNormalCommHalted(nmState)!=0)
      )
    {
       *ComMode = COMM_NO_COMMUNICATION;
    }
    else
    {
       *ComMode = COMM_FULL_COMMUNICATION;
    }
  }

  return retValue;

}

/**********************************************************************************************************************
  CALL BACK IMPLEMENTATION
**********************************************************************************************************************/

/*********************************************************************************************************************
  FUNCTION: ApplNwmWakeup
----------------------------------------------------------------------------------------------------------------------
  API     Type                    Name                    Description
----------------------------------------------------------------------------------------------------------------------
   Input:  CanChannelHandle       channel                  CAN channel for which this function is called for
   Output: None
   Return: None
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: GMLAN network management
  Precondition: ComM must be initialized via the function ComM_Init

   This function is the callback implementation of a GMLAN handler function. The function is called if the GMLAN handler 
   is leaving the COM OFF state to establish bus communcaiton.In this case RUN will be requested from the EcuM to prevent
   the ECU from leaving the RUN state. 
 *********************************************************************************************************************/
void ApplNwmWakeup ( CanChannelHandle channel )
{
    if(EcuM_ComM_HasRequestedRUN((EcuM_ChannelHandleType)channel) == FALSE)
    {
        /* no ComM run mode request is set,
        * request ComM run mode
        */
        if(EcuM_ComM_RequestRUN((EcuM_ChannelHandleType)channel) == E_NOT_OK)
        {
          /*TO DO */
        }
    }
}

/*********************************************************************************************************************
  FUNCTION: ApplNwmSleep
----------------------------------------------------------------------------------------------------------------------
  API     Type                    Name                    Description
----------------------------------------------------------------------------------------------------------------------
   Input:  CanChannelHandle       channel                  CAN channel for which this function is called for
   Output: None
   Return: None
----------------------------------------------------------------------------------------------------------------------
  FUNCTION DESCRIPTION
----------------------------------------------------------------------------------------------------------------------
     Called by: GMLAN network management
  Precondition: ComM must be initialized via the function ComM_Init

   This function is the callback implementation of a GMLAN handler function. The function is called when the handler enters 
   COM OFF on this channel, which means there is no communcation request set any more and the handler has entered the 
   sleep mode. In this case the RUN request has to be released.
 *********************************************************************************************************************/
void ApplNwmSleep ( CanChannelHandle channel )
{
    if(EcuM_ComM_HasRequestedRUN((EcuM_ChannelHandleType)channel) == TRUE)
    {
        /* ComM run mode request is set,
        * relase ComM run mode
        */
        if(EcuM_ComM_ReleaseRUN((EcuM_ChannelHandleType)channel) == E_NOT_OK)
        {
          /*TO DO */
        }
    }
}
