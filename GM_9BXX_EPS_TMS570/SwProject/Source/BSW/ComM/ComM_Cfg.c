
/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

#include "ComM.h"

/**********************************************************************************************************************
  ROM DATA
**********************************************************************************************************************/
CONST(ComM_UserToChannelAndVnTblType, COMM_CONST) ComM_UserToChannelAndVnTbl[COMM_MAX_NUMBER_OF_USERS] = 
{
     {(CanChannelHandle)0u, (vuint8)VN_SLHSSharedDiagnostic}
    ,{(CanChannelHandle)0u, (vuint8)VN_AllNodes}
    ,{(CanChannelHandle)0u, (vuint8)VN_SLHS_VNReq}
    ,{(CanChannelHandle)1u, (vuint8)VN_SLHSSharedDiagnostic}
    ,{(CanChannelHandle)1u, (vuint8)VN_AllNodes}
    ,{(CanChannelHandle)1u, (vuint8)VN_SLHS_VNReq}
} ;

