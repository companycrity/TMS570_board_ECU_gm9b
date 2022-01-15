/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SrlComInput.c
 *     Workspace:  C:/02_EA3Int/9Bxx/Wip_fz9hxm/GM_9BXX_EPS_TMS570/SwProject/SrlComInput/autosar
 *     SW-C Type:  Ap_SrlComInput
 *  Generated at:  Sun Mar 19 15:59:27 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SrlComInput>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Apr 13 12:17:00 2011
 * %version:          EA3#13 %
 * %derived_by:       fz9hxm %
 * %date_modified:    Wed Mar  5 13:36:15 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/24/15  1        GMN       Initial 9Bxx Synergy Version
 * 09/22/15  4        GMN       Anomaly 2373: NTC 0x121 (Missing 0x0C1 Message) Sets Intermittently            3359
 * 11/20/15  5        GMN       EA3#4313: Implement Non Secure Vehicle Speed                                   4572
 *                              Change Lat Accel unit from g to MpSecSqr
 *                              Add output for YawRateValid
 * 01/29/16  6        GMN       EA3#4065: Changed unit of VehicleLonAccel to from KphpsS to MpSecSq            4384
 * 02/09/16  7        GMN       EA3#4986: New APA strategy                                                     6033
 * 02/15/16  9        GMN       EA3#4990: ARCs and ProtVals NTC strategy changed                               6125
 * 03/18/16  10       GMN       EA3#5780: WhlGrndVlcty output signals changed to be equal to received CAN      6491
 *                                        signals with no stuck control
 * 05/02/16  11       GMN       Increased the number of personalities for message 0x232
 *                              EA3#6571: Fixed invalid message criteria for NTC 1D0
 *                              EA3#7531: Fixed missing messages set during bus off
 * 03/19/17  13       CP        EA3#14185: Added Longitudinal Acceleration valid signal
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Operation Prototypes:
 =====================
  DtrmnElapsedTime_mS_u16 of Port Interface SystemTime
    Nexteer SystemTime Service


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_SrlComInput.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Rte.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "CDD_Data.h"
#include "il_inc.h"
#include "can_cfg.h"
#include "can_par.h"
#include "Ap_DfltConfigData.h"
#include "desc.h"
#include "appdesc.h"
#include "CDD_Data.h"
#include "float.h"
#include "drv_par.h"
#include "NvM.h"


/* MISRA-C: 2004 Rule 10.3: This deviation is required for a composite expression of 'essentially unsigned' typ */
/* PRQA S 4394 EOF */

/* MISRA-C: 2004 Rules 12.10 /14.2: Use of comma operator. Used by the RTE functions */
/* PRQA S 3417, 3426 EOF */

/*
 * Enable/Disable NTCs missing and invalid message for a specific message.
 *
 * TRUE: NTCs are disabled
 * FALSE: NTCs are enabled
 */
#define D_DISABLE3E9MESSAGENTC_CNT_LGC                  TRUE /* Message 0x3E9 */

#define D_CONFIRMEDDTCBIT_CNT_B8                        0x08U

/*
 * Maximum number of personalities.
 * Message 0x232 Driving Mode Control HS, signal StgSysPerfMdRq has a range from 0 to 7 where the value 0 should not
 * be used. This macro should represent the maximum number of personalities configured in the software. Any higher
 * number received is ignored.
 */
#define D_MAXPERFMDRQ_CNT_U16 (D_NUMOFPERS_CNT_U16)

/*
 * Default personality.
 * Default value for personality in order to be written to the RTE in case the message 0x232 is missing.
 * The range is 0 to (D_MAXPERFMDRQ_CNT_U16 - 1).
 */
#define D_DEFAULTPERS_CNT_U16 0U

#define D_WIRFLTVALBIT_CNT_U16                          ((uint16)0x0001U)
#define D_WIRFLTSEQNUMBIT_CNT_U16                       ((uint16)0x0002U)
#define D_WIRFLTRESETBIT_CNT_U16                        ((uint16)0x0004U)
#define D_WIRFLTMAXFREQ_CNT_U16                         ((uint16)0x0008U)
#define D_WIRFLTFREQDELTA_CNT_U16                       ((uint16)0x0010U)

#define D_WIRFLTALLBITSL_CNT_U16                        ((uint16)(D_WIRFLTVALBIT_CNT_U16 | D_WIRFLTSEQNUMBIT_CNT_U16 | D_WIRFLTRESETBIT_CNT_U16 | D_WIRFLTMAXFREQ_CNT_U16 | D_WIRFLTFREQDELTA_CNT_U16))
#define D_WIRFLTALLBITSR_CNT_U16                        ((uint16)(D_WIRFLTALLBITSL_CNT_U16 << 5u))
#define D_WIRFLTVALIDITY_CNT_U16                        ((uint16)(D_WIRFLTVALBIT_CNT_U16 | D_WIRFLTSEQNUMBIT_CNT_U16 | D_WIRFLTRESETBIT_CNT_U16))
#define D_WIRFLTVALIDITYLR_CNT_U16                      ((uint16)((uint16)(D_WIRFLTVALIDITY_CNT_U16 << 5u) | D_WIRFLTVALIDITY_CNT_U16))
#define D_WIRFLTFREQMASK_CNT_U16                        ((uint16)(D_WIRFLTMAXFREQ_CNT_U16 | D_WIRFLTFREQDELTA_CNT_U16))
#define D_WIRFLTFREQMASKLR_CNT_U16                      ((uint16)(D_WIRFLTFREQMASK_CNT_U16 << 5u) | D_WIRFLTFREQMASK_CNT_U16)
#define D_AMBTEMPLOLMT_DEGC_F32                         (-40.0F)
#define D_AMBTEMPHILMT_DEGC_F32                         87.5F
#define D_ENGTEMPLOLMT_DEGC_F32                         (-40.0F)
#define D_ENGTEMPHILMT_DEGC_F32                         215.0F
#define D_LATACCLOLMT_MPSECSQRD_F32                     (-32.0F)
#define D_LATACCHILMT_MPSECSQRD_F32                     31.984375F

#define D_LONACCELSF_MPSECSQRD_F32                      0.03F
#define D_LONACCELMAXVAL_CNT_U16                        511U
#define D_LONACCELSIGNEDOFFSET_CNT_U16                  1024U
#define D_LONACCELCONVFACTOR_KPHSPM_F32                 3.6F

#define D_YAWRATELOLMT_DEGPSEC_F32                      (-128.0F)
#define D_YAWRATEHILMT_DEGPSEC_F32                      127.9375F

#define D_VEHSTBLATACCELSF_MPSECSQRD_F32                0.015625F
#define D_MPSECSQRDTOGRAVITYACCEL_ULS_F32               9.81F
#define D_VEHDYNYAWRATESF_DEGPSEC_F32                   0.0625F
#define D_ENGCLTTEMPOFFSET_DEGC_F32                     40.0F
#define D_OUTAIRTEMPCORRVALSF_DEGC_F32                  0.5F
#define D_OUTAIRTEMPCORRVALOFFSET_DEGC_F32              40.0F
#define D_VEHSPDAVGNDRVNSF_KPH_F32                      0.015625F
#define D_SIGNEDSIGNALOFFSET_CNT_U16                    4096U
#define D_LATACCELYAWRATEMAXVAL_CNT_U16                 2047U
#define D_1MICROSEC_SEC_F32                             0.000001F
#define D_SASRATIONALITYINHIBITTIMEOUT_MS_U16           5000U
#define D_USEDATA_CNT_U08                               1U
#define D_REVERSERANGE_CNT_U08                          2U

#define D_ENGSPDSF_RPM_F32                              0.25F
#define D_ENGSPDMIN_RPM_F32                             0.0F
#define D_ENGSPDMAX_RPM_F32                             16383.75F

#define NTC_Num_MissingMsg_ParkAssistParallel           NTC_Num_FlexrayCommunicationError

#define D_VALID_CNT_U08                                 0U
#define D_INVALID_CNT_U08                               1U
#define D_5KPH_CNT_U16                                  ((uint16)(5.0F / D_WHEELVELSF_KPH_F32))
#define D_WHEELVELSF_KPH_F32                            (0.03125F)
#define D_VEHSTABILITYINACTIVE_CNT_U08                  (0U)
#define D_VEHSTABILITYFAULT_CNT_U08                     (2U)
#define D_SECVEHSPDSF_KPH_F32                           (0.03125F)
#define D_NORMALOPERATION_CNT_U08                       0U
#define D_TEMPINHIBIT_CNT_U08                           2U
#define D_PERMANENTLYFAILED_CNT_U08                     3U
#define D_INVALIDROLLINGCOUNT_CNT_U08                   (0xFFU)

#define D_ACTAXLETRQSF_TRANSNM_F32                      (2.0F)
#define D_ACTAXLETRQOFFSET_TRANSNM_F32                  (22534.0F)

#define D_TRQRQV1SF_HWNM_F32                            (0.01F)
#define D_TRQRQV1MIN_HWNM_F32                           (-10.24F)
#define D_TRQRQV1MAX_HWNM_F32                           (10.23F)

#define D_MINVEHSPD_KPH_F32                             (0.0F)
#define D_MAXVEHSPD_KPH_F32                             (511.0F)

#define D_SYSPWRMDMIN_CNT_U08                           (0U)
#define D_SYSPWRMDMAX_CNT_U08                           (3U)

#define D_SWARTRGTANGSF_DEG_F32                         (0.0625F)
#define D_SWARTRGTANGPOLARITY_ULS_F32                   (-1.0F)
#define D_SWARTRGTANGLOLMT_DEG_F32                      (-2048.0F)
#define D_SWARTRGTANGHILMT_DEG_F32                      (2047.9375F)

#define D_LKAFAULT_NOFAULTS_CNT_B16                     (0x0000U)
#define D_LKAFAULT_INVALIDWHEELVEL_CNT_B16              ((uint16)1U << 0U)
#define D_LKAFAULT_MISSING17D_CNT_B16                   ((uint16)1U << 1U)
#define D_LKAFAULT_MISSING180_CNT_B16                   ((uint16)1U << 2U)
#define D_LKAFAULT_INVALIDPV180_CNT_B16                 ((uint16)1U << 3U)
#define D_LKAFAULT_MISSING1E9_CNT_B16                   ((uint16)1U << 4U)
#define D_LKAFAULT_MISSING214_CNT_B16                   ((uint16)1U << 5U)
#define D_LKAFAULT_VSEROLLCOUNT214_CNT_B16              ((uint16)1U << 6U)
#define D_LKAFAULT_ABSINVALIDPV214_CNT_B16              ((uint16)1U << 7U)
#define D_LKAFAULT_INVALIDRC180_CNT_B16                 ((uint16)1U << 8U)
#define D_LKAFAULT_ABSINVALIDRC214_CNT_B16              ((uint16)1U << 9U)
#define D_LKAFAULT_INVALIDMINWHEELVEL_CNT_B16           ((uint16)1U << 10U)

#define D_LKAINHIBIT_NOFAULTS_CNT_B16                    (0x0000U)
#define D_LKAINHIBIT_INVALID17D_CNT_B16                  ((uint16)1U << 0U)
#define D_LKAINHIBIT_VSEACTIVE_CNT_B16                   ((uint16)1U << 1U)
#define D_LKAINHIBIT_PROTECTED214_CNT_B16                ((uint16)1U << 2U)
#define D_LKAINHIBIT_INVALID1E9_CNT_B16                  ((uint16)1U << 3U)

/* APA Recovery faults types */
#define D_APARECOVERABLEFAULTS_NOFAULTS_CNT_U08          (0x00U)
#define D_APARECOVERABLEFAULTS_INVALID337_CNT_U08        ((uint8)(1U << 0U))
#define D_APARECOVERABLEFAULTS_INVALID1F5_CNT_U08        ((uint8)(1U << 1U))
#define D_APARECOVERABLEFAULTS_MISSING337_CNT_U08        ((uint8)(1U << 2U))
#define D_APARECOVERABLEFAULTS_INVLDMINWHEELVEL_CNT_U08  ((uint8)(1U << 3U))
#define D_APARECOVERABLEFAULTS_INVLDMAXWHEELVEL_CNT_U08  ((uint8)(1U << 4U))

/* APA Non Recovery faults types */
#define D_APANONRECOVERABLEFAULTS_NOFAULTS_CNT_U16      (0x0000u)
#define D_APANONRECOVERABLEFAULTS_MISSING337_CNT_U16    (((uint16) 0x01u) << 0u)
#define D_APANONRECOVERABLEFAULTS_INVALID337_CNT_U16    (((uint16) 0x01u) << 1u)
#define D_APANONRECOVERABLEFAULTS_DIAGSTS_CNT_U16       (((uint16) 0x01u) << 2u) /* DiagStsNonRecRmpToZeroFltPres */
#define D_APANONRECOVERABLEFAULTS_NTC1D1_CNT_U16        (((uint16) 0x01u) << 3u) /* NTC_Num_MissingMsg_ParkAssistParallel */
#define D_APANONRECOVERABLEFAULTS_NTC1D0_CNT_U16        (((uint16) 0x01u) << 4u) /* NTC_Num_InvalidMsg_ParkAssistParallel */
#define D_APANONRECOVERABLEFAULTS_NTC06C_CNT_U16        (((uint16) 0x01u) << 5u) /* NTC_Num_HWACrossChecks */
#define D_APANONRECOVERABLEFAULTS_NTC06D_CNT_U16        (((uint16) 0x01u) << 6u) /* NTC_Num_HWASnsrCommFault */
#define D_APANONRECOVERABLEFAULTS_NTC06E_CNT_U16        (((uint16) 0x01u) << 7u) /* NTC_Num_HWASensorRel */
#define D_APANONRECOVERABLEFAULTS_NTC06F_CNT_U16        (((uint16) 0x01u) << 8u) /* NTC_Num_HWASensorAbs */
#define D_APANONRECOVERABLEFAULTS_NTC1F8_CNT_U16        (((uint16) 0x01u) << 9u) /* NTC_Num_HWASensorNotTrimmed */

#define D_STARTSTOPFAULT_NOFAULTS_CNT_U16                (0x0000U)
#define D_STARTSTOPFAULT_MISSING0C9_CNT_U16              ((uint16)1U << 0U)
#define D_STARTSTOPFAULT_INVALIDVEHSPD_CNT_U16           ((uint16)1U << 1U)
#define D_STARTSTOPFAULT_INVALID0C9_CNT_U16              ((uint16)1U << 2U)

#define D_ESCFAULT_NOFAULTS_CNT_B16                      (0x0000U)
#define D_ESCFAULT_INVALID180CE_CNT_U16                  ((uint16)1U << 0U)
#define D_ESCFAULT_MISSING180CE_CNT_U16                  ((uint16)1U << 1U)

typedef struct
{
	uint16 	VSELatAcc;
	uint16 	VehDynYawRate;
	uint8 	VSELatAccV;
	uint8 	VehDynYawRateV;
} RT_Chassis_General_Status_1;

typedef struct
{
	uint8	WRSSeqNum;
	uint16 	WRSWhlDistPCntr;
	uint8 	WRSWhlDisTpRC;
	uint16 	WRSWhlDistTstm;
	uint8 	WRSWhlDistVal;
	uint8 	WRSWhlRotStatRst;
} WhlRotStat;

typedef struct
{
	WhlRotStat WhlRotStatLft;
	WhlRotStat WhlRotStatRght;
} RT_PPEI_NonDrivn_Whl_Rotationl_Stat;

typedef struct
{
	uint8 	OtsAirTmpCrVal;
	uint8 	OtsAirTmpCrValV;
	uint8 	OtsAirTmpCrValMsk;
} RT_Platform_Eng_Cntrl_Requests;

typedef struct
{
	uint8 	SysPwrMode;
	boolean SysBkupPwrMdEn;
	uint8 	SysBkUpPwrMd;
	uint8 	BkupPwrModeMstrVDA;
} RT_PPEI_Platform_General_Status;

typedef struct
{
	uint16 	StrAngSnsChksm;
	sint16 	StrWhAng;
	uint8 	StWhlAngAliveRollCnt;
	sint16 	StrWhAngGrd;
	uint8 	StrWhAngGrdMsk;
	uint8 	StrWhAngGrdV;
	uint8 	StrWhAngMsk;
	uint8 	StrWhlAngSenCalStat;
	uint8 	StrWhlAngSenTyp;
	uint8 	StrWhAngV;
	uint8 	StrWhlAngMsgUnused1;
	uint8 	StrWhlAngMsgUnused2;
	uint8 	StrWhlAngMsgUnused3;
} RT_PPEI_Steering_Wheel_Angle_CE;

typedef struct
{
	uint16 	VehSpdAvgNDrvn;
	uint8 	VehSpdAvgNDrvnV;
} RT_VehSpdAvgNonDrvnGroup;

typedef struct
{
	RT_VehSpdAvgNonDrvnGroup VehSpdAvgNonDrvnGroup;
} RT_PPEI_Vehicle_Speed_and_Distance;

typedef struct
{
	uint16 	WhlRotStatTmstmpRes;
	uint8 	WhlPlsPerRevNonDrvn;
} RT_Wheel_Pulses_HS;

typedef struct
{
	uint8 	EngCltTmp;
	uint8 	EngCltTmpV;
} RT_Engine_General_Status_4;


#define SRLCOMINPUT_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) LastPlsChngTimeL_mS_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) LastPlsChngTimeR_mS_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) InvStartTimeL_mS_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) InvStartTimeR_mS_M_u32; /* PRQA S 3218 */
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_NOINIT) OldRawWhlFreqL_Hz_M_f32; /* PRQA S 3218 */
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_NOINIT) OldRawWhlFreqR_Hz_M_f32; /* PRQA S 3218 */
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_NOINIT) PulseScale_RevpCnt_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_NOINIT) WhlTstmpRes_SecpCnt_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_NOINIT) VehSpdAvgNDrvn_Kph_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_NOINIT) ManualVehSpd_Kph_M_f32;
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_NOINIT) MaxSecVehSpd_Kph_M_f32; /* PRQA S 3218 */
STATIC VAR(float32, AP_SRLCOMINPUT_VAR_NOINIT) MinSecVehSpd_Kph_M_f32; /* PRQA S 3218 */

/* Invalid message timers */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) AmbTempVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) EngTempVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) LatAccVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) YawRateVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) VehSpdVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) VehicleDynamicsESCHybCEVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) ParkAssistParallelCEVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) AntilockTCbrakeVldStartTime_mS_M_u32p0;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) RedntVSEActARCVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) RedntVSEActVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) ABSActvProtPValVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) ABSActvProtARCVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) ABSActvProtVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) VSEActVldStartTime_mS_M_u32p0;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) TCSysEVldStartTime_mS_M_u32p0;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) ABSFldVldStartTime_mS_M_u32p0;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) VhDynCVldStartTime_mS_M_u32p0;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) LKATqOvrDltCmdPrtVlVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) LKATqOvrDltCmdRCVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) ActAxleTrqVldStartTime_mS_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) TrnsShftLvrPosVldStartTime_mS_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) EngSpdStatlVldStartTime_mS_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) ESCChksmVldStartTime_mS_M_u32; /* PRQA S 3218 */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) ESCRollCountVldStartTime_mS_M_u32; /* PRQA S 3218 */

/* Msg loss timers */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg1E9Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg214Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg232Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg0C9Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg0C1Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg0D3Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg1F1Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg1F5Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg3E9Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg500Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg348CELoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg348HSLoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg180HSLoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg34ACELoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg34AHSLoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg337Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg337LossAPARec_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg337LossAPANonRec_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg182Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg3F1Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg4C1Loss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg17DLoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg180CELoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg180HSLKALoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg348HSLKALoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg348CELKALoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg34AHSLKALoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg34ACELKALoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg1E9LKALoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg214LKALoss_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) Msg17DLKALoss_mS_M_u32;

/* Wheel Ground Velocity Stuck Signal Timers */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtDrvnCEStuck_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftDrvnCEStuck_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtNnDrvnCEStuck_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftNnDrvnCEStuck_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtDrvnHSStuck_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftDrvnHSStuck_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtNnDrvnHSStuck_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftNnDrvnHSStuck_mS_M_u32;

/* Wheel Ground Velocity Validity Timers */
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtDrvnCEVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftDrvnCEVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtNnDrvnCEVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftNnDrvnCEVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtDrvnHSVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftDrvnHSVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtNnDrvnHSVldStartTime_mS_M_u32;
STATIC VAR(uint32, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftNnDrvnHSVldStartTime_mS_M_u32;
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

#define SRLCOMINPUT_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) AmbTempVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) EngTempVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) LatAccVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) YawRateVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) VehSpdVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) VehicleDynamicsESCHybCEVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) ParkAssistParallelCEVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtDrvnHSVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftDrvnHSVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtNnDrvnHSVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftNnDrvnHSVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtDrvnCEVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftDrvnCEVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtNnDrvnCEVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftNnDrvnCEVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) RedntVSEActARCVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) RedntVSEActVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) ABSActvProtPValVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) ABSActvProtARCVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) ABSActvProtVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) VSEActVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) TCSysEVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) ABSFldVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) VhDynCVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) LKATqOvrDltCmdPrtVlVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) LKATqOvrDltCmdRCVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) ActAxleTrqVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) TrnsShftLvrPosVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) EngSpdStatVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) ESCChksmVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) ESCRollCountVldAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg1E9LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg214LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg232LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg0C9LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg0C1LossAccum_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg0D3LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg1F1LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg1F5LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg3E9LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg500LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg348CELossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg348HSLossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg180HSLossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg34ACELossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg34AHSLossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg337LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg337LossAccumAPA_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg337InvalidAccumAPA_Cnt_M_u16;	/* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg182LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg3F1LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg4C1LossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg17DLossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) Msg180CELossAccum_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) OldSeqNumL_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) OldSeqNumR_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) OldWhlDistTstmL_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) OldWhlDistTstmR_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) OldWhlPCntrL_Cnt_M_u16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) OldWhlPCntrR_Cnt_M_u16; /* PRQA S 3218 */

STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtDrvnCE_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftDrvnCE_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtNnDrvnCE_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftNnDrvnCE_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtDrvnHS_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftDrvnHS_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtNnDrvnHS_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftNnDrvnHS_Cnt_M_u16;

STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) PrevLKARollingCounter_Cnt_M_u16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) LKAInhibit_Cnt_M_b16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) LKAFault_Cnt_M_b16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) StartStopFault_Cnt_M_b16;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) ESCFault_Cnt_M_b16;
STATIC volatile VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) LKAFaultLatch_Cnt_D_b16; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) PrevESCRollingCounter_Cnt_M_u16;

STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) APARecoverableFaults_Cnt_M_b08;
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) APANonRecoverableFaults_Cnt_M_b16;
STATIC volatile VAR(uint16, AP_SRLCOMINPUT_VAR_NOINIT) APANonRecFaultsLatch_Cnt_D_b16; /* PRQA S 3218 */
STATIC volatile VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) APARecFaultsLatch_Cnt_D_b08; /* PRQA S 3218 */
STATIC VAR(uint16, AP_SRLCOMINPUT_VAR) WIRFltStatusAcc_Cnt_M_u16; /* PRQA S 3218 */
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */

#define SRLCOMINPUT_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) ABSActvProtARC_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) RedntVSEActARC_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) PrevStrWhlTctlFdbkReqActRC_Cnt_M_u08;
STATIC VAR(uint8, AP_SRLCOMINPUT_VAR_NOINIT) PrevStrWhlAngReqARC_Cnt_M_u08;
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define SRLCOMINPUT_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) ManualVehSpdOvrRide_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) VehSpdAvgNDrvnInValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) RedntVSEAct_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) VSEAct_Cnt_M_lgc;

STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtDrvnCEValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftDrvnCEValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtNnDrvnCEValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftNnDrvnCEValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtDrvnHSValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftDrvnHSValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyRtNnDrvnHSValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyLftNnDrvnHSValid_Cnt_M_lgc;

STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyDrvnCEMissing_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyNnDrvnCEMissing_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyDrvnHSMissing_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) WhlGrndVlctyNnDrvnHSMissing_Cnt_M_lgc;

STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) SrlComInput_Message0D3PresentAndValid_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) SrlComInput_Message1E9PresentAndValid_Cnt_M_lgc;

STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) SrlComInput_EngRunAtv_Cnt_M_lgc;
STATIC VAR(boolean, AP_SRLCOMINPUT_VAR_NOINIT) SrlComInput_PrevRunMode_Cnt_M_lgc; /* PRQA S 3218 */
#define SRLCOMINPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

/* Type H Data */
#define SRLCOMINPUT_START_SEC_VAR_SAVED_ZONEH_16
#include "MemMap.h" /* PRQA S 5087 */
VAR(uint16,  AP_SRLCOMINPUT_VAR_NOINIT) SrlComWIRFltStatus_Cnt_u16;
#define SRLCOMINPUT_STOP_SEC_VAR_SAVED_ZONEH_16
#include "MemMap.h" /* PRQA S 5087 */


STATIC FUNC(float32, AP_SRLCOMINPUT_CODE) CalcWhlFreq(	VAR(uint16, AUTOMATIC) WRSWhlDistPCntr_Cnt_T_u16,
														VAR(uint16, AUTOMATIC) OldWhlPCntr_Cnt_T_u16,
														VAR(uint16, AUTOMATIC) WRSWhlDistTstm_Cnt_T_u16,
														VAR(uint16, AUTOMATIC) OldWhlDistTstm_Cnt_T_u16,
														P2VAR(float32, AUTOMATIC, AUTOMATIC) OldRawWhlFreq_Ptr_T_f32,
														VAR(float32, AUTOMATIC) WhlTstmpRes_SecpCnt_T_f32,
														VAR(float32, AUTOMATIC) PulseScale_RevpCnt_T_f32,
														P2VAR(uint16, AUTOMATIC, AUTOMATIC) WIRFltStatus_Ptr_T_u16);

STATIC FUNC(float32, AP_SRLCOMINPUT_CODE) ProcessWhlStatus(	VAR(WhlRotStat, AUTOMATIC) WhlRotStatus,
															P2VAR(uint16, AUTOMATIC, AUTOMATIC) OldSeqNum_Ptr_T_u16,
															P2VAR(uint16, AUTOMATIC, AUTOMATIC) OldWhlDistTstm_Ptr_T_u16,
															P2VAR(uint16, AUTOMATIC, AUTOMATIC) OldWhlPCntr_Ptr_T_u16,
															P2VAR(float32, AUTOMATIC, AUTOMATIC) OldRawWhlFreq_Ptr_T_f32,
															VAR(float32, AUTOMATIC) WhlTstmpRes_SecpCnt_T_f32,
															VAR(float32, AUTOMATIC) PulseScale_RevpCnt_T_f32,
															P2VAR(uint32, AUTOMATIC, AUTOMATIC) LastPlsChngTime_Ptr_T_u32,
															P2VAR(uint16, AUTOMATIC, AUTOMATIC) WIRFltStatus_Ptr_T_u16,
															P2VAR(uint32, AUTOMATIC, AUTOMATIC) InvStartTime_Ptr_T_u32);

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) DtrmnNTCTimeout(	P2VAR(uint32, AUTOMATIC, AUTOMATIC) MsgLossTimer_mS_T_u32,
															VAR(uint16, AUTOMATIC) RxMsgTimeoutCal_mS_T_u16p0,
															P2VAR(uint16, AUTOMATIC, AUTOMATIC) FaultAccumulator_Cnt_T_u16,
															VAR(DiagSettings_Str, AUTOMATIC) DiagSettings_Cnt_T_str,
															VAR(uint16, AUTOMATIC) NTCNum_Cnt_T_u16,
															VAR(boolean, AUTOMATIC) InhibitNTCFlag_Cnt_T_lgc,
															VAR(uint8, AUTOMATIC) NTCbit_Cnt_T_u8);

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) DtrmnTimerElapsed(VAR(uint32, AUTOMATIC) MsgLossTimer_mS_T_u32,
															VAR(uint16, AUTOMATIC) RxMsgInhibitNTCTOCal_mS_T_u16p0);
STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) NTCCheckClear(P2VAR(uint32, AUTOMATIC, AUTOMATIC) MsgLossTimer_mS_T_u32,
														P2VAR(uint16, AUTOMATIC, AUTOMATIC) FaultAccumulator_Cnt_T_u16,
														CONSTP2CONST(DiagSettings_Str, AUTOMATIC, AUTOMATIC) DiagSettings_Cnt_T_str,
														VAR(uint16, AUTOMATIC) NTCNum_Cnt_T_u16);

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ResetLKABus1Timers(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ResetWhlGrndVlctyBus1Timers(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ResetWhlGrndVlctyBus2Timers(void);
STATIC FUNC(uint8, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFltsGet(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFltsSet(VAR(uint8, AUTOMATIC) Fault_Cnt_T_b08,
		                                                                  VAR(boolean, AUTOMATIC) Status_Cnt_T_lgc);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFlts337Present(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFlts337Missing(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFlts337Invalid(VAR(boolean, AUTOMATIC) Invalid_Cnt_T_lgc);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFlts1F5Invalid(VAR(boolean, AUTOMATIC) Invalid_Cnt_T_lgc);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFltsPer(void);
STATIC FUNC(uint16, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APANonRecFltsGet(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APANonRecFltsSet(VAR(uint16, AUTOMATIC) Fault_Cnt_T_b16,
		                                                                     VAR(boolean, AUTOMATIC) Status_Cnt_T_lgc);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APANonRecFlts337Present(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APANonRecFlts337Missing(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APANonRecFlts337Invalid(boolean Invalid_Cnt_T_lgc);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APANonRecFltsPer(void);
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_DecrementCMEC(void);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NTCNumber: Enumeration of integer in interval [0...511] with enumerators
 *   NTC_Num_FlashWrapperLgcFlt (1U)
 *   NTC_Num_FlashECCCorr (2U)
 *   NTC_Num_FlashECCMemFlt (3U)
 *   NTC_Num_FlashCRCMemFault (4U)
 *   NTC_Num_NvMBlkDftActA (6U)
 *   NTC_Num_NvMBlkDftActB (7U)
 *   NTC_Num_NvMBlkDftActC (8U)
 *   NTC_Num_CurrentSensorCalOutOfRange (9U)
 *   NTC_Num_EEPROMDiag (10U)
 *   NTC_Num_EEPROMDiagMtrStr (11U)
 *   NTC_Num_PriSnsrTrqStorFlt (12U)
 *   NTC_Num_EEPROMDiagPosTrimStr (13U)
 *   NTC_Num_SecSnsrTrqStorFlt (14U)
 *   NTC_Num_EEPROMDiagPolarityStr (15U)
 *   NTC_Num_RAMDiag_GeneralFlt (16U)
 *   NTC_Num_RAMDiag_WrprLgcFlt (17U)
 *   NTC_Num_RAMDiag_ECCCorrIndFlt (18U)
 *   NTC_Num_RAMDiag_ECCMemFlt (19U)
 *   NTC_Num_RAMDiag_CRCMemFlt (20U)
 *   NTC_Num_RAMDiag_VIMRamFlt (23U)
 *   NTC_Num_RAMDiag_NHET1RamFlt (24U)
 *   NTC_Num_RAMDiag_NHET2RamFlt (25U)
 *   NTC_Num_RAMDiag_ADC1RamFlt (26U)
 *   NTC_Num_RAMDiag_DCANRamFault (27U)
 *   NTC_Num_RAMDiag_ADC2RamFlt (28U)
 *   NTC_Num_RAMDiag_HETTU1RamFlt (29U)
 *   NTC_Num_RAMDiag_HETTU2RamFlt (30U)
 *   NTC_Num_CPU_RegVer (32U)
 *   NTC_Num_CPU_CoreInitFlt (33U)
 *   NTC_Num_CPU_CoreRunTimeFlt (34U)
 *   NTC_Num_CPU_ClockMon (35U)
 *   NTC_Num_CPU_eFuseFlt (36U)
 *   NTC_Num_CPU_MPUViolation (37U)
 *   NTC_Num_CPU_FactPrcsErr (40U)
 *   NTC_Num_PropExeDiag_InitDiag (41U)
 *   NTC_Num_PrgFlwDeadlnFlt (42U)
 *   NTC_Num_PropExeDiag_RunTimeDiag (43U)
 *   NTC_Num_PropExeDiag_COPTimeout (44U)
 *   NTC_Num_PropExeDiag_PrefetchAbort (48U)
 *   NTC_Num_PropExeDiag_DataAbort (49U)
 *   NTC_Num_PerDiag_ADC1Flt (50U)
 *   NTC_Num_PerDiag_ADC2Flt (51U)
 *   NTC_Num_PerDiag_ADCCrossChkFlt (52U)
 *   NTC_Num_PerDiag_IllegalAccess (53U)
 *   NTC_Num_PerDiag_DMAFlt (54U)
 *   NTC_Num_PeripheralStartupFlt (55U)
 *   NTC_Num_PerDiag_CPUWarning (63U)
 *   NTC_Num_TmpMonFunc (64U)
 *   NTC_Num_TmpMonRunTimeFlt (65U)
 *   NTC_Num_PowerRelayInitFlt (66U)
 *   NTC_Num_PrechargeFailure (67U)
 *   NTC_Num_PowerRelayRunFlt (68U)
 *   NTC_Num_Thermistor (69U)
 *   NTC_Num_RefSupplyVltg (70U)
 *   NTC_Num_TrcvrInterfaceFlt (71U)
 *   NTC_Num_CPUSupplyOvervoltage (72U)
 *   NTC_Num_BattVltgMeasdCorrlnFlt (73U)
 *   NTC_Num_IvtrPwrDiscnctFailr (74U)
 *   NTC_Num_PowerRelayInit2Flt (75U)
 *   NTC_Num_GateDrvFltInProcess (76U)
 *   NTC_Num_GateDrvFlt (77U)
 *   NTC_Num_OnStateSingleFET (78U)
 *   NTC_Num_OnStateMultiFET (79U)
 *   NTC_Num_PhaseVoltageVerf (80U)
 *   NTC_Num_PhaseDscnt (81U)
 *   NTC_Num_DigPhaseVoltageVerf (82U)
 *   NTC_Num_PhaseDscntFailedDisable (83U)
 *   NTC_Num_CurrentMeas1 (84U)
 *   NTC_Num_CurrentMeas2 (85U)
 *   NTC_Num_CurrentMeasCrossChk (86U)
 *   NTC_Num_PDSupplyOverVoltage (87U)
 *   NTC_Num_ChargePumpUnderVoltage (88U)
 *   NTC_Num_Inv2GateDrvFltInProcess (92U)
 *   NTC_Num_Inv2GateDrvFlt (93U)
 *   NTC_Num_Inv2OnStateSingleFET (94U)
 *   NTC_Num_HwTrqSensor (96U)
 *   NTC_Num_AnaVsDigHwTrq (97U)
 *   NTC_Num_TrqSensorRecoveryFlt (98U)
 *   NTC_Num_TrqSensorScaleInvalid (100U)
 *   NTC_Num_T1vsT2 (101U)
 *   NTC_Num_T1OutofRange (102U)
 *   NTC_Num_T2OutofRange (103U)
 *   NTC_Num_DigT1vsT2 (104U)
 *   NTC_Num_DigT1OutofRange (105U)
 *   NTC_Num_DigT2OutofRange (106U)
 *   NTC_Num_RedT1vsT2 (107U)
 *   NTC_Num_HWACrossChecks (108U)
 *   NTC_Num_HWASnsrCommFault (109U)
 *   NTC_Num_HWASensorRel (110U)
 *   NTC_Num_HWASensorAbs (111U)
 *   NTC_Num_PriMSB_SinCosCorr (112U)
 *   NTC_Num_SecMSB_SinCosCorr (113U)
 *   NTC_Num_PriVsSec_SinCosCorr (114U)
 *   NTC_Num_DigMSBFlt (115U)
 *   NTC_Num_MtrVelFlt (116U)
 *   NTC_Num_HWAtoMtrAngleCorr (117U)
 *   NTC_Num_RedPriVsSec_SinCosCorr (118U)
 *   NTC_Num_TurnCntr_PosLoss (128U)
 *   NTC_Num_TurnCntr_MicroProcFlt (129U)
 *   NTC_Num_TurnCntr_SensorPosFlt (130U)
 *   NTC_Num_TurnCntr_SpiComFlt (131U)
 *   NTC_Num_TurnCntr_HighQuiescCur (132U)
 *   NTC_Num_TurnCntr_MainResets (133U)
 *   NTC_Num_TurnCntr_PosLossNotSpdDep (134U)
 *   NTC_Num_KinematicIntDiag (144U)
 *   NTC_Num_HighFriction (145U)
 *   NTC_Num_DutyCycleExceeded (148U)
 *   NTC_Num_AbsTempThermLimit (149U)
 *   NTC_Num_LatchActive (160U)
 *   NTC_Num_OpTrqVsHwTrq (168U)
 *   NTC_Num_CurrentReas (169U)
 *   NTC_Num_LoaRpdShutdn (170U)
 *   NTC_Num_LoaCtrldShutdn (171U)
 *   NTC_Num_LoaMgr_HwTqIdptSigTooLow (172U)
 *   NTC_Num_LoaMgr_MotAgIdptSigTooLow (173U)
 *   NTC_Num_LoaMgr_MotCurrIdptSigTooLow (174U)
 *   NTC_Num_LoaMgr_IvtrIdptSigTooLow (175U)
 *   NTC_Num_OpVoltage (176U)
 *   NTC_Num_ExVoltageLow (177U)
 *   NTC_Num_ReducedAsstLowVoltage (178U)
 *   NTC_Num_ExVoltageHigh (180U)
 *   NTC_Num_OpVoltageOvrMax (181U)
 *   NTC_Num_BattTransOverVolt (182U)
 *   NTC_Num_IgnConfDiag (184U)
 *   NTC_Num_TurnCntr_LowBattery (185U)
 *   NTC_Num_EEPROMCloseFailed (191U)
 *   NTC_Num_SigPath1CrossChk (192U)
 *   NTC_Num_SigPath2CrossChk (193U)
 *   NTC_Num_SigPath3CrossChk (194U)
 *   NTC_Num_SigPath4CrossChk (195U)
 *   NTC_Num_SigPath5CrossChk (196U)
 *   NTC_Num_DampingFWReached (197U)
 *   NTC_Num_AssistFWReached (198U)
 *   NTC_Num_ReturnFWReached (199U)
 *   NTC_Num_DampingFWFltMode (200U)
 *   NTC_Num_AssistFWFltMode (201U)
 *   NTC_Num_VBICFltMode (202U)
 *   NTC_Num_StaMdsSysC (203U)
 *   NTC_NUM_SysFailureForRotVel (204U)
 *   NTC_NUM_SysFailForRedntRotVel (205U)
 *   NTC_Num_SysFailureForTrqSnsr (206U)
 *   NTC_Num_SysFailureForRedTrqSnsr (207U)
 *   NTC_NUM_SysFailureForCtrlVolt (209U)
 *   NTC_Num_GlblSgnlOvrwrtDet (223U)
 *   NTC_Num_VLF_00 (224U)
 *   NTC_Num_VLF_01 (225U)
 *   NTC_Num_VLF_02 (226U)
 *   NTC_Num_VLF_03 (227U)
 *   NTC_Num_VLF_04 (228U)
 *   NTC_Num_VLF_05 (229U)
 *   NTC_Num_VLF_06 (230U)
 *   NTC_Num_VLF_07 (231U)
 *   NTC_Num_VLF_08 (232U)
 *   NTC_Num_VLF_09 (233U)
 *   NTC_Num_VLF_10 (234U)
 *   NTC_Num_VLF_11 (235U)
 *   NTC_Num_VLF_12 (236U)
 *   NTC_Num_VLF_13 (237U)
 *   NTC_Num_VLF_14 (238U)
 *   NTC_Num_VLF_15 (239U)
 *   NTC_Num_VLF_16 (240U)
 *   NTC_Num_VLF_17 (241U)
 *   NTC_Num_VLF_18 (242U)
 *   NTC_Num_VLF_19 (243U)
 *   NTC_Num_VLF_20 (244U)
 *   NTC_Num_VLF_21 (245U)
 *   NTC_Num_VLF_22 (246U)
 *   NTC_Num_VLF_23 (247U)
 *   NTC_Num_VLF_24 (248U)
 *   NTC_Num_VLF_25 (249U)
 *   NTC_Num_VLF_26 (250U)
 *   NTC_Num_VLF_27 (251U)
 *   NTC_Num_VLF_28 (252U)
 *   NTC_Num_VLF_29 (253U)
 *   NTC_Num_VLF_30 (254U)
 *   NTC_Num_VLF_31 (255U)
 *   NTC_Num_BusOffCh1 (256U)
 *   NTC_Num_BusOffCh1NodeMute (257U)
 *   NTC_Num_Node1AAbsent (258U)
 *   NTC_Num_Node1AFaulty (259U)
 *   NTC_Num_Node1BAbsent (260U)
 *   NTC_Num_Node1BFaulty (261U)
 *   NTC_Num_Node1CAbsent (262U)
 *   NTC_Num_Node1CFaulty (263U)
 *   NTC_Num_Node1DAbsent (264U)
 *   NTC_Num_Node1DFaulty (265U)
 *   NTC_Num_Node1EAbsent (266U)
 *   NTC_Num_Node1EFaulty (267U)
 *   NTC_Num_Node1FAbsent (268U)
 *   NTC_Num_Node1FFaulty (269U)
 *   NTC_Num_Node1GAbsent (270U)
 *   NTC_Num_Node1GFaulty (271U)
 *   NTC_Num_BusOffCh2 (272U)
 *   NTC_Num_Node2AAbsent (273U)
 *   NTC_Num_Node2AFaulty (274U)
 *   NTC_Num_Node2BAbsent (275U)
 *   NTC_Num_Node2BFaulty (276U)
 *   NTC_Num_Node2CAbsent (277U)
 *   NTC_Num_Node2CFaulty (278U)
 *   NTC_Num_Node2DAbsent (279U)
 *   NTC_Num_Node2DFaulty (280U)
 *   NTC_Num_Node2EAbsent (281U)
 *   NTC_Num_Node2EFaulty (282U)
 *   NTC_Num_Node2FAbsent (283U)
 *   NTC_Num_Node2FFaulty (284U)
 *   NTC_Num_Node2GAbsent (285U)
 *   NTC_Num_Node2GFaulty (286U)
 *   NTC_Num_InvalidMsg_M (288U)
 *   NTC_Num_MissingMsg_M (289U)
 *   NTC_Num_CRCFltMsg_M (290U)
 *   NTC_Num_PgrsCntFltMsg_M (291U)
 *   NTC_Num_DataRngFltMsg_M (292U)
 *   NTC_Num_DataRateFltMsg_M (293U)
 *   NTC_Num_DataOtherFltMsg_M (294U)
 *   NTC_Num_DataOther2FltMsg_M (295U)
 *   NTC_Num_InvalidMsg_N (296U)
 *   NTC_Num_MissingMsg_N (297U)
 *   NTC_Num_CRCFltMsg_N (298U)
 *   NTC_Num_PgrsCntFltMsg_N (299U)
 *   NTC_Num_DataRngFltMsg_N (300U)
 *   NTC_Num_DataRateFltMsg_N (301U)
 *   NTC_Num_DataOtherFltMsg_N (302U)
 *   NTC_Num_DataOtherFlt2Msg_N (303U)
 *   NTC_Num_InvalidMsg_O (304U)
 *   NTC_Num_MissingMsg_O (305U)
 *   NTC_Num_CRCFltMsg_O (306U)
 *   NTC_Num_PgrsCntFltMsg_O (307U)
 *   NTC_Num_DataRngFltMsg_O (308U)
 *   NTC_Num_DataRateFltMsg_O (309U)
 *   NTC_Num_DataOtherFltMsg_O (310U)
 *   NTC_Num_InvalidMsg_P (312U)
 *   NTC_Num_MissingMsg_P (313U)
 *   NTC_Num_CRCFltMsg_P (314U)
 *   NTC_Num_PgrsCntFltMsg_P (315U)
 *   NTC_Num_DataRngFltMsg_P (316U)
 *   NTC_Num_DataRateFltMsg_P (317U)
 *   NTC_Num_DataOtherFltMsg_P (318U)
 *   NTC_Num_InvalidMsg_Q (320U)
 *   NTC_Num_MissingMsg_Q (321U)
 *   NTC_Num_CRCFltMsg_Q (322U)
 *   NTC_Num_PgrsCntFltMsg_Q (323U)
 *   NTC_Num_DataRngFltMsg_Q (324U)
 *   NTC_Num_DataRateFltMsg_Q (325U)
 *   NTC_Num_DataOtherFltMsg_Q (326U)
 *   NTC_Num_InvalidMsg_R (328U)
 *   NTC_Num_MissingMsg_R (329U)
 *   NTC_Num_CRCFltMsg_R (330U)
 *   NTC_Num_PgrsCntFltMsg_R (331U)
 *   NTC_Num_DataRngFltMsg_R (332U)
 *   NTC_Num_DataRateFltMsg_R (333U)
 *   NTC_Num_DataOtherFltMsg_R (334U)
 *   NTC_Num_DataOtherFlt2Msg_R (335U)
 *   NTC_Num_InvalidMsg_S (336U)
 *   NTC_Num_MissingMsg_S (337U)
 *   NTC_Num_CRCFltMsg_S (338U)
 *   NTC_Num_PgrsCntFltMsg_S (339U)
 *   NTC_Num_DataRngFltMsg_S (340U)
 *   NTC_Num_DataRateFltMsg_S (341U)
 *   NTC_Num_DataOtherFltMsg_S (342U)
 *   NTC_Num_InvalidMsg_T (344U)
 *   NTC_Num_MissingMsg_T (345U)
 *   NTC_Num_CRCFltMsg_T (346U)
 *   NTC_Num_PgrsCntFltMsg_T (347U)
 *   NTC_Num_DataRngFltMsg_T (348U)
 *   NTC_Num_DataRateFltMsg_T (349U)
 *   NTC_Num_DataOtherFltMsg_T (350U)
 *   NTC_Num_InvalidMsg_U (352U)
 *   NTC_Num_MissingMsg_U (353U)
 *   NTC_Num_CRCFltMsg_U (354U)
 *   NTC_Num_PgrsCntFltMsg_U (355U)
 *   NTC_Num_DataRngFltMsg_U (356U)
 *   NTC_Num_DataRateFltMsg_U (357U)
 *   NTC_Num_DataOtherFltMsg_U (358U)
 *   NTC_Num_InvalidMsg_V (360U)
 *   NTC_Num_MissingMsg_V (361U)
 *   NTC_Num_CRCFltMsg_V (362U)
 *   NTC_Num_PgrsCntFltMsg_V (363U)
 *   NTC_Num_DataRngFltMsg_V (364U)
 *   NTC_Num_DataRateFltMsg_V (365U)
 *   NTC_Num_DataOtherFltMsg_V (366U)
 *   NTC_Num_InvalidMsg_W (368U)
 *   NTC_Num_MissingMsg_W (369U)
 *   NTC_Num_CRCFltMsg_W (370U)
 *   NTC_Num_PgrsCntFltMsg_W (371U)
 *   NTC_Num_DataRngFltMsg_W (372U)
 *   NTC_Num_DataRateFltMsg_W (373U)
 *   NTC_Num_DataOtherFltMsg_W (374U)
 *   NTC_Num_InvalidMsg_X (376U)
 *   NTC_Num_MissingMsg_X (377U)
 *   NTC_Num_CRCFltMsg_X (378U)
 *   NTC_Num_PgrsCntFltMsg_X (379U)
 *   NTC_Num_DataRngFltMsg_X (380U)
 *   NTC_Num_DataRateFltMsg_X (381U)
 *   NTC_Num_DataOtherFltMsg_X (382U)
 *   NTC_Num_InvalidMsg_Y (384U)
 *   NTC_Num_MissingMsg_Y (385U)
 *   NTC_Num_CRCFltMsg_Y (386U)
 *   NTC_Num_PgrsCntFltMsg_Y (387U)
 *   NTC_Num_DataRngFltMsg_Y (388U)
 *   NTC_Num_DataRateFltMsg_Y (389U)
 *   NTC_Num_DataOtherFltMsg_Y (390U)
 *   NTC_Num_InvalidMsg_Z (392U)
 *   NTC_Num_MissingMsg_Z (393U)
 *   NTC_Num_CRCFltMsg_Z (394U)
 *   NTC_Num_PgrsCntFltMsg_Z (395U)
 *   NTC_Num_DataRngFltMsg_Z (396U)
 *   NTC_Num_DataRateFltMsg_Z (397U)
 *   NTC_Num_DataOtherFltMsg_Z (398U)
 *   NTC_Num_DSTXORActive (399U)
 *   NTC_Num_InvalidMsg_AA (400U)
 *   NTC_Num_MissingMsg_AA (401U)
 *   NTC_Num_CRCFltMsg_AA (402U)
 *   NTC_Num_PgrsCntFltMsg_AA (403U)
 *   NTC_Num_DataRngFltMsg_AA (404U)
 *   NTC_Num_DataRateFltMsg_AA (405U)
 *   NTC_Num_DataOtherFltMsg_AA (406U)
 *   NTC_Num_InvalidMsg_AB (408U)
 *   NTC_Num_MissingMsg_AB (409U)
 *   NTC_Num_CRCFltMsg_AB (410U)
 *   NTC_Num_PgrsCntFltMsg_AB (411U)
 *   NTC_Num_DataRngFltMsg_AB (412U)
 *   NTC_Num_DataRateFltMsg_AB (413U)
 *   NTC_Num_DataOtherFltMsg_AB (414U)
 *   NTC_Num_InvalidMsg_AC (416U)
 *   NTC_Num_MissingMsg_AC (417U)
 *   NTC_Num_CRCFltMsg_AC (418U)
 *   NTC_Num_PgrsCntFltMsg_AC (419U)
 *   NTC_Num_DataRngFltMsg_AC (420U)
 *   NTC_Num_DataRateFltMsg_AC (421U)
 *   NTC_Num_DataOtherFltMsg_AC (422U)
 *   NTC_Num_InvalidMsg_AD (424U)
 *   NTC_Num_MissingMsg_AD (425U)
 *   NTC_Num_CRCFltMsg_AD (426U)
 *   NTC_Num_PgrsCntFltMsg_AD (427U)
 *   NTC_Num_DataRngFltMsg_AD (428U)
 *   NTC_Num_DataRateFltMsg_AD (429U)
 *   NTC_Num_DataOtherFltMsg_AD (430U)
 *   NTC_Num_InvalidMsg_AE (432U)
 *   NTC_Num_MissingMsg_AE (433U)
 *   NTC_Num_CRCFltMsg_AE (434U)
 *   NTC_Num_PgrsCntFltMsg_AE (435U)
 *   NTC_Num_DataRngFltMsg_AE (436U)
 *   NTC_Num_DataRateFltMsg_AE (437U)
 *   NTC_Num_DataOtherFltMsg_AE (438U)
 *   NTC_Num_InvalidMsg_AF (440U)
 *   NTC_Num_MissingMsg_AF (441U)
 *   NTC_Num_CRCFltMsg_AF (442U)
 *   NTC_Num_PgrsCntFltMsg_AF (443U)
 *   NTC_Num_DataRngFltMsg_AF (444U)
 *   NTC_Num_DataRateFltMsg_AF (445U)
 *   NTC_Num_DataOtherFltMsg_AF (446U)
 *   NTC_Num_InvalidMsg_AG (448U)
 *   NTC_Num_MissingMsg_AG (449U)
 *   NTC_Num_CRCFltMsg_AG (450U)
 *   NTC_Num_PgrsCntFltMsg_AG (451U)
 *   NTC_Num_DataRngFltMsg_AG (452U)
 *   NTC_Num_DataRateFltMsg_AG (453U)
 *   NTC_Num_DataOtherFltMsg_AG (454U)
 *   NTC_Num_InvalidMsg_AH (456U)
 *   NTC_Num_MissingMsg_AH (457U)
 *   NTC_Num_CRCFltMsg_AH (458U)
 *   NTC_Num_PgrsCntFltMsg_AH (459U)
 *   NTC_Num_DataRngFltMsg_AH (460U)
 *   NTC_Num_DataRateFltMsg_AH (461U)
 *   NTC_Num_DataOtherFltMsg_AH (462U)
 *   NTC_Num_InvalidMsg_ParkAssistParallel (464U)
 *   NTC_Num_FlexrayCommunicationError (465U)
 *   NTC_Num_InvalidMsg_AI (466U)
 *   NTC_Num_MissingMsg_AI (467U)
 *   NTC_Num_InvalidMsg_AJ (472U)
 *   NTC_Num_MissingMsg_AJ (473U)
 *   NTC_Num_InvalidMsg_AK (480U)
 *   NTC_Num_MissingMsg_AK (481U)
 *   NTC_Num_MissingMsg_AL (489U)
 *   NTC_Num_SysConsistencyVerf (496U)
 *   NTC_Num_ConfigMisMatch (497U)
 *   NTC_Num_CalNotPrgmd (498U)
 *   NTC_Num_TunSetNotPrgmd (499U)
 *   NTC_Num_EEPROMtoFeeCpyError (500U)
 *   NTC_Num_EOLVehTunNtPerf (501U)
 *   NTC_Num_MtrSensorNotTrimmed (502U)
 *   NTC_Num_HWASensorNotTrimmed (504U)
 *   NTC_Num_HWASensorTrimNoAttempt (505U)
 *   NTC_Num_TrqSensorScaleNotSet (506U)
 *   NTC_Num_TrqSensorNotTrimmed (507U)
 *   NTC_Num_AnaHWDiffTqOfstNotTrmd (508U)
 *   NTC_Num_DigTrqSensorScaleNotSet (509U)
 *   NTC_Num_DigTrqSensorNotTrimmed (510U)
 *   NTC_Num_SENTHWDiffTqOfstNotTrmd (511U)
 * NxtrDiagMgrStatus: Enumeration of integer in interval [0...255] with enumerators
 *   NTC_STATUS_PASSED (0U)
 *   NTC_STATUS_FAILED (1U)
 *   NTC_STATUS_PREPASSED (2U)
 *   NTC_STATUS_PREFAILED (3U)
 * SysPwrMd: Enumeration of integer in interval [0...3] with enumerators
 *   Off (0U)
 *   Accessory (1U)
 *   Run (2U)
 *   CrankRequest (3U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * UInt16: D_ZERO_CNT_U16 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_SRLCOMINPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SrlComAmbTemp_DegC_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComEngTemp_DegC_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComVehicleLonAccel_MpSecSq_f32(Float data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Init
 *********************************************************************************************************************/

	PulseScale_RevpCnt_M_f32 = D_ONE_ULS_F32/(float32)k_WhlPlsPerRev_Cnt_u16p0;
	WhlTstmpRes_SecpCnt_M_f32 = k_WhlTstmpRes_SecpCnt_f32;


	OldSeqNumL_Cnt_M_u16 = 0x4u; /* Initialize to value outside of normal range */
	OldSeqNumR_Cnt_M_u16 = 0x4u; /* Initialize to value outside of normal range */

	RedntVSEActARC_Cnt_M_u08 = D_INVALIDROLLINGCOUNT_CNT_U08; /* Initialize to value outside of normal range */
	ABSActvProtARC_Cnt_M_u08 = D_INVALIDROLLINGCOUNT_CNT_U08; /* Initialize to value outside of normal range */
	PrevLKARollingCounter_Cnt_M_u16 = D_INVALIDROLLINGCOUNT_CNT_U08; /* Initialize to value outside of normal range */
	PrevESCRollingCounter_Cnt_M_u16 = D_INVALIDROLLINGCOUNT_CNT_U08; /* Initialize to value outside of normal range */
	PrevStrWhlTctlFdbkReqActRC_Cnt_M_u08 = D_INVALIDROLLINGCOUNT_CNT_U08;
	PrevStrWhlAngReqARC_Cnt_M_u08 = D_INVALIDROLLINGCOUNT_CNT_U08;

	(void)Rte_Write_SrlComAmbTemp_DegC_f32(k_AmbTempDflt_DegC_f32);
	(void)Rte_Write_SrlComEngTemp_DegC_f32(k_EngTempDflt_DegC_f32);

	/* Setup default vehicle speeds */
	VehSpdAvgNDrvn_Kph_M_f32 = 0.0f;

	/* Send a positive response for a Nexteer Manufacturing ECU reset service */
	if (ECUResetPerformed_Cnt_G_lgc == TRUE)
	{
		ECUResetPerformed_Cnt_G_lgc = FALSE;
		RespMsgBuffer[0] = 0x51U;
		RespMsgBuffer[1] = 0x60U;
		DescTransmitSingleFrame(RespMsgBuffer,2U);
	}

	SrlComInput_SCom_ResetBus1Timers();
	SrlComInput_SCom_ResetBus2Timers();

	/* If all advanced features are disabled, pre-pass the Secure Vehicle Speed related NTCs */
	if ((FALSE == k_LKAMfgEnable_Cnt_lgc) && (FALSE == k_APAMfgEnable_Cnt_lgc) && (FALSE == k_ESCMfgEnable_Cnt_lgc))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AC, 0x00u, NTC_STATUS_PASSED); /* 0x34C HS Missing */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AC, 0x00u, NTC_STATUS_PASSED); /* 0x34C HS Invalid */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AJ, 0x00u, NTC_STATUS_PASSED); /* 0x348 CE Missing */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AJ, 0x00u, NTC_STATUS_PASSED); /* 0x348 CE Invalid */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AK, 0x00u, NTC_STATUS_PASSED); /* 0x34C CE Missing */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AK, 0x00u, NTC_STATUS_PASSED); /* 0x34C CE Invalid */
	}

	/* If LKA is disabled, ensure all related faults are not reported as pre-passed. */
	if (FALSE == k_LKAMfgEnable_Cnt_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AA, 0x00u, NTC_STATUS_PASSED); /* 0x180 HS Missing */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_X , 0x00u, NTC_STATUS_PASSED); /* 0x214 HS Missing */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AA, 0x00u, NTC_STATUS_PASSED); /* 0x180 HS Invalid */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_X , 0x00u, NTC_STATUS_PASSED); /* 0x214 HS Invalid */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AD , 0x00u, NTC_STATUS_PASSED); /* 0x17D HS Missing */
	}

	/* If APA is disabled, ensure all related faults are not reported as pre-passed. */
	if (FALSE == k_APAMfgEnable_Cnt_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_P, 0x00u, NTC_STATUS_PASSED); /* 0x1F5 HS Missing */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_ParkAssistParallel, 0x00u, NTC_STATUS_PASSED); /* 337 CE Missing */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_P, 0x00u, NTC_STATUS_PASSED); /* 0x1F5 HS Invalid */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_ParkAssistParallel, 0x00u, NTC_STATUS_PASSED); /* 0x337 CE Invalid */
	}

	/* If ESC is disabled, ensure all related faults are not reported as pre-passed. */
	if (FALSE == k_ESCMfgEnable_Cnt_lgc)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_AG, 0x00u, NTC_STATUS_PASSED); /* 0x180 CE Missing */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AG, 0x00u, NTC_STATUS_PASSED); /* 0x180 CE Invalid */
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_WIREnabled_Cnt_lgc(Boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_LKACmd_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_LKAFault_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_LKAInhibit_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_LKARequest_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_MaxSecureVehicleSpeed_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComLWhlSpd_Hz_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComLWhlSpdVld_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComRWhlSpd_Hz_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComRWhlSpdVld_Cnt_lgc(Boolean data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 *Status_Ptr_T_u08)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Per1
 *********************************************************************************************************************/

	/* Poll for new messages */ /* PRQA S 1290 1 */
	(void)CanRxFullCANObjTask(CanRxPPEI_Driven_Whl_Rotational_Stat_HW_CHANNEL, CanRxPPEI_Driven_Whl_Rotational_Stat_HW_OBJ); /* ID: 0x0C1, Periodic Rate: 10ms */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BusOffCE_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_BusOffHS_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_WIREnabled_Cnt_lgc(Boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_APAMfgEnable_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_APANonRecoverableFaults_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_APARecoverableFaults_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_APARequest_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_DesiredTunPers_Cnt_u16(UInt16 data)
 *   Std_ReturnType Rte_Write_ESCCmd_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_ESCFault_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_ESCMfgEnable_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_ESCRequest_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_EngRunAtvForCTCInhibit_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_HapticRequest_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_LKACmd_HwNm_f32(Float data)
 *   Std_ReturnType Rte_Write_LKAFault_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_LKAInhibit_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_LKAMfgEnable_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_LKARequest_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_MaxSecureVehicleSpeed_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_MinSecureVehicleSpeed_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_PowertrainCrankActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SPMForCTCInhibit_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SWARTrgtAngRequest_HwDeg_f32(Float data)
 *   Std_ReturnType Rte_Write_ShiftLeverIsInReverse_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComABSActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComESCActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComEngOn_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComEngineSpeed_Rpm_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComLWhlSpd_Hz_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComLWhlSpdVld_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComLatAccel_MpSecSq_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComLatAccelValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComRWhlSpd_Hz_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComRWhlSpdVld_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComSysPwrMd_Cnt_enum(SysPwrMd data)
 *   Std_ReturnType Rte_Write_SrlComTCSActive_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComTSMitDefeat_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComTransmissionTrq_TransNm_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComYawRate_DegpS_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComYawRateValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_StrtStopFaultActive_Cnt_lgc(Boolean data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCActive(NTCNumber NTC_Cnt_T_enum, Boolean *NTCActive_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Per2
 *********************************************************************************************************************/

	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) WIREnabled_Cnt_T_lgc;
	VAR(uint32, AUTOMATIC) CurrentSysTime_mS_T_u32p0;
	VAR(nmStatusType, AUTOMATIC) NmStateChannel0_Cnt_T_enum;
	VAR(nmStatusType, AUTOMATIC) NmStateChannel1_Cnt_T_enum;
	VAR(uint16, AUTOMATIC) MaxSecVehSpd_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) ValidMaxSecureVehicleSpeed_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) MinSecVehSpd_Cnt_T_u16;
	VAR(boolean, AUTOMATIC) ValidMinSecureVehicleSpeed_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) APARecoverableFaults_Cnt_T_b08;
	VAR(uint16, AUTOMATIC) APANonRecoverableFaults_Cnt_T_b16;
	VAR(boolean, AUTOMATIC) BusOffHSPresent_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) BusOffCEPresent_Cnt_T_lgc;

	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);
	(void)Rte_Read_WIREnabled_Cnt_lgc(&WIREnabled_Cnt_T_lgc);
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&CurrentSysTime_mS_T_u32p0);

	(void)Rte_Read_BusOffHS_Cnt_lgc(&BusOffHSPresent_Cnt_T_lgc);
	(void)Rte_Read_BusOffCE_Cnt_lgc(&BusOffCEPresent_Cnt_T_lgc);

	/* Poll for messages on the HS bus. */ /* PRQA S 1290 6 */
	(void)CanRxFullCANObjTask(CanRxDriving_Mode_Control_HS_HW_CHANNEL, CanRxDriving_Mode_Control_HS_HW_OBJ);                   /* ID: 0x232, HS, Periodic Rate: 50ms */
	(void)CanRxFullCANObjTask(CanRxPPEI_Chassis_General_Status_1_HW_CHANNEL, CanRxPPEI_Chassis_General_Status_1_HW_OBJ);       /* ID: 0x1E9, HS, Periodic Rate: 20ms */
	(void)CanRxFullCANObjTask(CanRxPPEI_Engine_General_Status_1_HW_CHANNEL, CanRxPPEI_Engine_General_Status_1_HW_OBJ);         /* ID: 0x0C9, HS, Periodic Rate: 12ms */
	(void)CanRxFullCANObjTask(CanRxPPEI_Hybrid_General_Status_3_HS_HW_CHANNEL, CanRxPPEI_Hybrid_General_Status_3_HS_HW_OBJ);   /* ID: 0x0D3, HS, Periodic Rate: 12ms */
	(void)CanRxFullCANObjTask(CanRxNonDriven_Wheel_Grnd_Velocity_HS_HW_CHANNEL, CanRxNonDriven_Wheel_Grnd_Velocity_HS_HW_OBJ); /* ID: 0x348, HS, Periodic Rate: 50ms */
	(void)CanRxFullCANObjTask(CanRxDriven_Wheel_Grnd_Velocity_HS_HW_CHANNEL, CanRxDriven_Wheel_Grnd_Velocity_HS_HW_OBJ);       /* ID: 0x34A, HS, Periodic Rate: 50ms */

	/* Poll for messages on the CE bus. */ /* PRQA S 1290 1 */
	(void)CanRxFullCANObjTask(CanRxVehicle_Dynamics_ESC_Hyb_CE_HW_CHANNEL, CanRxVehicle_Dynamics_ESC_Hyb_CE_HW_OBJ);    /* ID: 0x182, CE, Periodic Rate: 100ms */

	/* Call message handlers for wheel ground velocities when APA or LKA are enabled */
	if ((TRUE == k_LKAMfgEnable_Cnt_lgc) || (TRUE == k_APAMfgEnable_Cnt_lgc) || (TRUE == k_ESCMfgEnable_Cnt_lgc))
	{
		/* Poll for messages on the CE bus. */ /* PRQA S 1290 2 */
		(void)CanRxFullCANObjTask(CanRxNonDriven_Wheel_Grnd_Velocity_CE_HW_CHANNEL, CanRxNonDriven_Wheel_Grnd_Velocity_CE_HW_OBJ);   /* ID: 0x34A, CE, Periodic Rate: 50ms */
		(void)CanRxFullCANObjTask(CanRxDriven_Wheel_Grnd_Velocity_CE_HW_CHANNEL, CanRxDriven_Wheel_Grnd_Velocity_CE_HW_OBJ);         /* ID: 0x348, CE, Periodic Rate: 50ms */
	}

	/* Only call message handlers related to LKA if it is enabled. */
	if (TRUE == k_LKAMfgEnable_Cnt_lgc)
	{
		/* Poll for messages on the HS bus. */ /* PRQA S 1290 3 */
		(void)CanRxFullCANObjTask(CanRxBrake_Pedal_Driver_Status_HS_HW_CHANNEL,CanRxBrake_Pedal_Driver_Status_HS_HW_OBJ);           /* ID: 0x214, HS, Periodic Rate: 50ms */
		(void)CanRxFullCANObjTask(CanRxAntilock_Brake_and_TC_Status_HS_HW_CHANNEL, CanRxAntilock_Brake_and_TC_Status_HS_HW_OBJ);    /* ID: 0x17D, HS, Periodic Rate: 100ms */
		(void)CanRxFullCANObjTask(CanRxLKA_Steering_Torque_Cmd_HS_HW_CHANNEL, CanRxLKA_Steering_Torque_Cmd_HS_HW_OBJ);              /* ID: 0x180, HS, Periodic Rate: 100ms */
	}

	/* Only call message handlers related to APA if it is enabled. */
	if (TRUE == k_APAMfgEnable_Cnt_lgc)
	{
		/* Poll for messages */ /* PRQA S 1290 2 */
		(void)CanRxFullCANObjTask(CanRxPPEI_Trans_General_Status_2_HW_CHANNEL, CanRxPPEI_Trans_General_Status_2_HW_OBJ);  /* ID: 0x1F5, HS, Periodic Rate: 25ms */
		(void)CanRxFullCANObjTask(CanRxPark_Assist_Parallel_CE_HW_CHANNEL, CanRxPark_Assist_Parallel_CE_HW_OBJ);          /* ID: 0x337, CE, Periodic Rate: 20ms */
	}

	/* Only call message handlers related to ESC if it is enabled. */
	if (TRUE == k_ESCMfgEnable_Cnt_lgc)
	{
		/* Poll for messages */ /* PRQA S 1290 1 */
		(void)CanRxFullCANObjTask(CanRxSteering_Torque_Command_CE_HW_CHANNEL, CanRxSteering_Torque_Command_CE_HW_OBJ);  /* ID: 0x180, CE, Periodic Rate: 50ms */
		(void)Rte_Write_ESCMfgEnable_Cnt_lgc(TRUE);
	}
	else
	{
		(void)Rte_Write_ESCMfgEnable_Cnt_lgc(FALSE);
	}

	if (D_ESCFAULT_NOFAULTS_CNT_B16 == ESCFault_Cnt_M_b16)
	{
		(void)Rte_Write_ESCFault_Cnt_lgc(FALSE);
	}
	else
	{
		(void)Rte_Write_ESCFault_Cnt_lgc(TRUE);
	}

	NmStateChannel0_Cnt_T_enum = IlNwmGetStatus(0u);
	NmStateChannel1_Cnt_T_enum = IlNwmGetStatus(1u);

	/* If the 0x28 service has turned off communications, or a bus off has occurred.*/
	if ((TRUE == (boolean)IlNwmStateNormalCommHalted(NmStateChannel0_Cnt_T_enum)) || /* PRQA S 1861 */
	    (TRUE == BusOffHSPresent_Cnt_T_lgc))
	{
		SrlComInput_SCom_ResetBus1Timers();
	}

	/* If the 0x28 service has turned off communications, or a bus off has occurred.*/
	if ((TRUE == (boolean)IlNwmStateNormalCommHalted(NmStateChannel1_Cnt_T_enum)) || /* PRQA S 1861 */
	    (TRUE == BusOffCEPresent_Cnt_T_lgc))
	{
		SrlComInput_SCom_ResetBus2Timers();
	}

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		/* ->Determine message loss<- */
		/* ChassisGenStat1MsgLoss */
		if (TRUE == DtrmnNTCTimeout(&Msg1E9Loss_mS_M_u32, k_Msg1E9TimeOut_mS_u16p0,
					&Msg1E9LossAccum_Cnt_M_u16, k_Msg1E9TimeOutDiag_Cnt_str,
					NTC_Num_MissingMsg_W, D_FALSE_CNT_LGC, 0x01u))
		{
			(void)Rte_Write_SrlComLatAccel_MpSecSq_f32(k_LatAccDflt_MpSecSqrd_f32);
			(void)Rte_Write_SrlComLatAccelValid_Cnt_lgc(TRUE);
			(void)Rte_Write_SrlComYawRate_DegpS_f32(k_YawRateDflt_DegpSec_f32);
			(void)Rte_Write_SrlComYawRateValid_Cnt_lgc(FALSE);
			(void)Rte_Write_SrlComABSActive_Cnt_lgc(FALSE);
			(void)Rte_Write_SrlComESCActive_Cnt_lgc(FALSE);
			(void)Rte_Write_SrlComTCSActive_Cnt_lgc(FALSE);
			SrlComInput_Message1E9PresentAndValid_Cnt_M_lgc = FALSE;
		}

		/* Msg232Loss */
		if (TRUE == DtrmnNTCTimeout(&Msg232Loss_mS_M_u32, k_Msg232TimeOut_mS_u16p0,
				&Msg232LossAccum_Cnt_M_u16, k_Msg232TimeOutDiag_Cnt_str,
				NTC_Num_MissingMsg_Q, D_FALSE_CNT_LGC, 0x01u))
		{
			(void)Rte_Write_DesiredTunPers_Cnt_u16(D_DEFAULTPERS_CNT_U16);
		}

		/* EngGenStat1MsgLoss */
		if (DtrmnNTCTimeout(&Msg0C9Loss_mS_M_u32, k_Msg0C9TimeOut_mS_u16p0,
					 &Msg0C9LossAccum_Cnt_M_u16, k_Msg0C9TimeOutDiag_Cnt_str,
					 NTC_Num_MissingMsg_N, D_FALSE_CNT_LGC, 0x01u) == TRUE)
		{
			StartStopFault_Cnt_M_b16 |= D_STARTSTOPFAULT_MISSING0C9_CNT_U16;
			(void)Rte_Write_EngRunAtvForCTCInhibit_Cnt_lgc(TRUE);
		}

		/* DrvnWhlRotStatMsgLoss */
		if (DtrmnNTCTimeout(&Msg0C1Loss_mS_M_u32, k_Msg0C1TimeOut_mS_u16p0,
					&Msg0C1LossAccum_Cnt_M_u16, k_Msg0C1TimeOutDiag_Cnt_str,
					NTC_Num_MissingMsg_M, D_FALSE_CNT_LGC, 0x01u) == TRUE)
		{
			(void)Rte_Write_SrlComLWhlSpd_Hz_f32(0.0F);
			(void)Rte_Write_SrlComLWhlSpdVld_Cnt_lgc(FALSE);
			(void)Rte_Write_SrlComRWhlSpd_Hz_f32(0.0F);
			(void)Rte_Write_SrlComRWhlSpdVld_Cnt_lgc(FALSE);
		}

		/* HybridGeneralStatus3 */
		if (DtrmnNTCTimeout(&Msg0D3Loss_mS_M_u32, k_Msg0D3TimeOut_mS_u16p0,
					&Msg0D3LossAccum_Cnt_M_u16, k_Msg0D3TimeOutDiag_Cnt_str,
					NTC_Num_MissingMsg_T, D_FALSE_CNT_LGC, 0x01u) == TRUE)
		{
			(void)Rte_Write_SrlComTransmissionTrq_TransNm_f32(0.0F);
			SrlComInput_Message0D3PresentAndValid_Cnt_M_lgc = FALSE;
		}

		/* WheelPulsesMsgLoss */
		if (WIREnabled_Cnt_T_lgc == TRUE)
		{
			(void)DtrmnNTCTimeout(&Msg500Loss_mS_M_u32, k_Msg500TimeOut_mS_u16p0,
					&Msg500LossAccum_Cnt_M_u16, k_Msg500TimeOutDiag_Cnt_str,
					NTC_Num_MissingMsg_S, D_FALSE_CNT_LGC, 0x01u);
		}

		/* Msg1F1Loss */
		if (DtrmnNTCTimeout(&Msg1F1Loss_mS_M_u32, k_Msg1F1TimeOut_mS_u16p0,
					&Msg1F1LossAccum_Cnt_M_u16, k_Msg1F1TimeOutDiag_Cnt_str,
					NTC_Num_MissingMsg_O, D_FALSE_CNT_LGC, 0x01u) == TRUE)
		{
			if (SrlComInput_EngRunAtv_Cnt_M_lgc == TRUE)
			{
				(void)Rte_Write_SrlComSysPwrMd_Cnt_enum(Run);
			}
			else
			{
				(void)Rte_Write_SrlComSysPwrMd_Cnt_enum(Off);
			}
			(void)Rte_Write_SPMForCTCInhibit_Cnt_lgc(TRUE);
		}

		/* Msg180CELoss */
		if (DtrmnNTCTimeout(&Msg180CELoss_mS_M_u32, k_Msg180CETimeOut_mS_u16p0,
					&Msg180CELossAccum_Cnt_M_u16, k_Msg180CETimeOutDiag_Cnt_str,
					NTC_Num_MissingMsg_AG, D_FALSE_CNT_LGC, 0x01u) == TRUE)
		{
			ESCFault_Cnt_M_b16 |= D_ESCFAULT_MISSING180CE_CNT_U16;
		}

		if (StartStopFault_Cnt_M_b16 == D_STARTSTOPFAULT_NOFAULTS_CNT_U16)
		{
			(void)Rte_Write_StrtStopFaultActive_Cnt_lgc(FALSE);
		}
		else
		{
			(void)Rte_Write_StrtStopFaultActive_Cnt_lgc(TRUE);
		}

		if ((SrlComInput_Message0D3PresentAndValid_Cnt_M_lgc == TRUE) &&
			(SrlComInput_Message1E9PresentAndValid_Cnt_M_lgc == TRUE))
		{
			/* SrlComTSMitEnable_Cnt_lgc is TRUE when:
			 * 1) x0D3 message is NOT missing,
			 * 2) x0D3 message IS valid,
			 * 3) x1E9 message is NOT missing,
			 * 4) x1E9 message IS valid.
			 */
			(void)Rte_Write_SrlComTSMitDefeat_Cnt_lgc(FALSE);
		}
		else
		{
			(void)Rte_Write_SrlComTSMitDefeat_Cnt_lgc(TRUE);
		}

		/* -----[ LKA, APA or ESC Enabled ]-------------------------------------------------------------------------- */
		if ((TRUE == k_LKAMfgEnable_Cnt_lgc) || (TRUE == k_APAMfgEnable_Cnt_lgc) || (TRUE == k_ESCMfgEnable_Cnt_lgc))
		{
			if (TRUE == DtrmnTimerElapsed(Msg348HSLKALoss_mS_M_u32, k_Msg348HSLKATimeOut_mS_u16p0))
			{
				Msg348HSLKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
				WhlGrndVlctyDrvnHSMissing_Cnt_M_lgc = TRUE;
			}
			if (TRUE == DtrmnTimerElapsed(Msg348CELKALoss_mS_M_u32, k_Msg348CELKATimeOut_mS_u16p0))
			{
				Msg348CELKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
				WhlGrndVlctyNnDrvnHSMissing_Cnt_M_lgc = TRUE;
			}
			if (TRUE == DtrmnTimerElapsed(Msg34AHSLKALoss_mS_M_u32, k_Msg34AHSLKATimeOut_mS_u16p0))
			{
				Msg34AHSLKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
				WhlGrndVlctyNnDrvnCEMissing_Cnt_M_lgc = TRUE;
			}
			if (TRUE == DtrmnTimerElapsed(Msg34ACELKALoss_mS_M_u32, k_Msg34ACELKATimeOut_mS_u16p0))
			{
				Msg34ACELKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
				WhlGrndVlctyDrvnCEMissing_Cnt_M_lgc = TRUE;
			}

			(void)DtrmnNTCTimeout(&Msg348CELoss_mS_M_u32, k_Msg348CETimeOut_mS_u16p0, &Msg348CELossAccum_Cnt_M_u16,
					              k_Msg348CETimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AJ, D_FALSE_CNT_LGC, 0x01u);
			(void)DtrmnNTCTimeout(&Msg34ACELoss_mS_M_u32, k_Msg34ACETimeOut_mS_u16p0, &Msg34ACELossAccum_Cnt_M_u16,
					              k_Msg34ACETimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AK, D_FALSE_CNT_LGC, 0x01u);

			/* Combine the wheel velocity signals from each bus. Both are required to be valid to have a valid velocity for a given wheel.*/
			MaxSecVehSpd_Cnt_T_u16 = 0u;
			MinSecVehSpd_Cnt_T_u16 = 0xFFFFu;
			ValidMaxSecureVehicleSpeed_Cnt_T_lgc = FALSE;
			ValidMinSecureVehicleSpeed_Cnt_T_lgc = FALSE;
			/* Right Non-Driven */
			if ((TRUE == WhlGrndVlctyRtNnDrvnCEValid_Cnt_M_lgc) &&
					(TRUE == WhlGrndVlctyRtNnDrvnHSValid_Cnt_M_lgc) &&
					((FALSE == WhlGrndVlctyNnDrvnCEMissing_Cnt_M_lgc) || (FALSE == WhlGrndVlctyNnDrvnHSMissing_Cnt_M_lgc)))
			{
				MaxSecVehSpd_Cnt_T_u16 = Max_m(MaxSecVehSpd_Cnt_T_u16, WhlGrndVlctyRtNnDrvnHS_Cnt_M_u16);
				MaxSecVehSpd_Cnt_T_u16 = Max_m(MaxSecVehSpd_Cnt_T_u16, WhlGrndVlctyRtNnDrvnCE_Cnt_M_u16);
				ValidMaxSecureVehicleSpeed_Cnt_T_lgc = TRUE;

				MinSecVehSpd_Cnt_T_u16 = Min_m(MinSecVehSpd_Cnt_T_u16, WhlGrndVlctyRtNnDrvnHS_Cnt_M_u16);
				MinSecVehSpd_Cnt_T_u16 = Min_m(MinSecVehSpd_Cnt_T_u16, WhlGrndVlctyRtNnDrvnCE_Cnt_M_u16);
				ValidMinSecureVehicleSpeed_Cnt_T_lgc = TRUE;
			}
			/* Left Non-Driven */
			if ((TRUE == WhlGrndVlctyLftNnDrvnCEValid_Cnt_M_lgc) &&
					(TRUE == WhlGrndVlctyLftNnDrvnHSValid_Cnt_M_lgc) &&
					((FALSE == WhlGrndVlctyNnDrvnCEMissing_Cnt_M_lgc) || (FALSE == WhlGrndVlctyNnDrvnHSMissing_Cnt_M_lgc)))
			{
				MaxSecVehSpd_Cnt_T_u16 = Max_m(MaxSecVehSpd_Cnt_T_u16, WhlGrndVlctyLftNnDrvnHS_Cnt_M_u16);
				MaxSecVehSpd_Cnt_T_u16 = Max_m(MaxSecVehSpd_Cnt_T_u16, WhlGrndVlctyLftNnDrvnCE_Cnt_M_u16);
				ValidMaxSecureVehicleSpeed_Cnt_T_lgc = TRUE;

				MinSecVehSpd_Cnt_T_u16 = Min_m(MinSecVehSpd_Cnt_T_u16, WhlGrndVlctyLftNnDrvnHS_Cnt_M_u16);
				MinSecVehSpd_Cnt_T_u16 = Min_m(MinSecVehSpd_Cnt_T_u16, WhlGrndVlctyLftNnDrvnCE_Cnt_M_u16);
				ValidMinSecureVehicleSpeed_Cnt_T_lgc = TRUE;
			}
			/* Right Driven */
			if ((TRUE == WhlGrndVlctyRtDrvnCEValid_Cnt_M_lgc) &&
					(TRUE == WhlGrndVlctyRtDrvnHSValid_Cnt_M_lgc) &&
					((FALSE == WhlGrndVlctyDrvnCEMissing_Cnt_M_lgc) || (FALSE == WhlGrndVlctyDrvnHSMissing_Cnt_M_lgc)))
			{
				MaxSecVehSpd_Cnt_T_u16 = Max_m(MaxSecVehSpd_Cnt_T_u16, WhlGrndVlctyRtDrvnHS_Cnt_M_u16);
				MaxSecVehSpd_Cnt_T_u16 = Max_m(MaxSecVehSpd_Cnt_T_u16, WhlGrndVlctyRtDrvnCE_Cnt_M_u16);
				ValidMaxSecureVehicleSpeed_Cnt_T_lgc = TRUE;
			}
			/* Left Driven */
			if ((TRUE == WhlGrndVlctyLftDrvnCEValid_Cnt_M_lgc) &&
					(TRUE == WhlGrndVlctyLftDrvnHSValid_Cnt_M_lgc) &&
					((FALSE == WhlGrndVlctyDrvnCEMissing_Cnt_M_lgc) || (FALSE == WhlGrndVlctyDrvnHSMissing_Cnt_M_lgc)))
			{
				MaxSecVehSpd_Cnt_T_u16 = Max_m(MaxSecVehSpd_Cnt_T_u16, WhlGrndVlctyLftDrvnHS_Cnt_M_u16);
				MaxSecVehSpd_Cnt_T_u16 = Max_m(MaxSecVehSpd_Cnt_T_u16, WhlGrndVlctyLftDrvnCE_Cnt_M_u16);
				ValidMaxSecureVehicleSpeed_Cnt_T_lgc = TRUE;
			}

			/* If a secure vehicle speed was derived, use it. Otherwise retain the last valid value, and set LKA_Fault_lgc */
			if (TRUE == ValidMaxSecureVehicleSpeed_Cnt_T_lgc)
			{
				MaxSecVehSpd_Kph_M_f32 = (float32)MaxSecVehSpd_Cnt_T_u16 * D_SECVEHSPDSF_KPH_F32;
				MaxSecVehSpd_Kph_M_f32 = Limit_m(MaxSecVehSpd_Kph_M_f32, D_MINVEHSPD_KPH_F32, D_MAXVEHSPD_KPH_F32);
				LKAFault_Cnt_M_b16 &= ~D_LKAFAULT_INVALIDWHEELVEL_CNT_B16;
				SrlComInput_APARecFltsSet(D_APARECOVERABLEFAULTS_INVLDMAXWHEELVEL_CNT_U08, FALSE);
			}
			else
			{
				LKAFault_Cnt_M_b16 |= D_LKAFAULT_INVALIDWHEELVEL_CNT_B16;
				SrlComInput_APARecFltsSet(D_APARECOVERABLEFAULTS_INVLDMAXWHEELVEL_CNT_U08, TRUE);
			}
			(void)Rte_Write_MaxSecureVehicleSpeed_Kph_f32(MaxSecVehSpd_Kph_M_f32);

			/* If a minimum secure vehicle speed was found, use it. Otherwise set LKA_Fault_lgc. */
			if (TRUE == ValidMinSecureVehicleSpeed_Cnt_T_lgc)
			{
				MinSecVehSpd_Kph_M_f32 = (float32)MinSecVehSpd_Cnt_T_u16 * D_SECVEHSPDSF_KPH_F32;
				MinSecVehSpd_Kph_M_f32 = Limit_m(MinSecVehSpd_Kph_M_f32, D_MINVEHSPD_KPH_F32, D_MAXVEHSPD_KPH_F32);
				LKAFault_Cnt_M_b16 &= ~D_LKAFAULT_INVALIDMINWHEELVEL_CNT_B16;
				SrlComInput_APARecFltsSet(D_APARECOVERABLEFAULTS_INVLDMINWHEELVEL_CNT_U08, FALSE);
			}
			else
			{
				LKAFault_Cnt_M_b16 |= D_LKAFAULT_INVALIDMINWHEELVEL_CNT_B16;
				SrlComInput_APARecFltsSet(D_APARECOVERABLEFAULTS_INVLDMINWHEELVEL_CNT_U08, TRUE);
			}
			(void)Rte_Write_MinSecureVehicleSpeed_Kph_f32(MinSecVehSpd_Kph_M_f32);
		}
		else
		{
			(void)Rte_Write_MaxSecureVehicleSpeed_Kph_f32(0.0F);
			(void)Rte_Write_MinSecureVehicleSpeed_Kph_f32(0.0F);

			ResetWhlGrndVlctyBus2Timers();
		}

		/* -----[ LKA Enabled ]-------------------------------------------------------------------------------------- */
		if (TRUE == k_LKAMfgEnable_Cnt_lgc)
		{
			/* Check if messages have gone missing for long enough to set LKA fault. Don't set any NTCs here. */
			if (TRUE == DtrmnTimerElapsed(Msg1E9LKALoss_mS_M_u32, k_Msg1E9LKATimeOut_mS_u16p0))
			{
				Msg1E9LKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
				LKAFault_Cnt_M_b16 |= D_LKAFAULT_MISSING1E9_CNT_B16;
			}
			if (TRUE == DtrmnTimerElapsed(Msg214LKALoss_mS_M_u32, k_Msg214LKATimeOut_mS_u16p0))
			{
				Msg214LKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
				LKAFault_Cnt_M_b16 |= D_LKAFAULT_MISSING214_CNT_B16;
			}
			if (TRUE == DtrmnTimerElapsed(Msg180HSLKALoss_mS_M_u32, k_Msg180HSLKATimeOut_mS_u16p0))
			{
				Msg180HSLKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
				LKAFault_Cnt_M_b16 |= D_LKAFAULT_MISSING180_CNT_B16;
			}
			if (TRUE == DtrmnTimerElapsed(Msg17DLKALoss_mS_M_u32, k_Msg17DLKATimeOut_mS_u16p0))
			{
				Msg17DLKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
				LKAFault_Cnt_M_b16 |= D_LKAFAULT_MISSING17D_CNT_B16;
			}

			/*Check if any missing message timers have elapsed. */
			(void)DtrmnNTCTimeout(&Msg214Loss_mS_M_u32, k_Msg214TimeOut_mS_u16p0, &Msg214LossAccum_Cnt_M_u16,
					              k_Msg214TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_X, D_FALSE_CNT_LGC, 0x01u);
			(void)DtrmnNTCTimeout(&Msg180HSLoss_mS_M_u32, k_Msg180HSTimeOut_mS_u16p0, &Msg180HSLossAccum_Cnt_M_u16,
					              k_Msg180HSTimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AA, D_FALSE_CNT_LGC, 0x01u);
			(void)DtrmnNTCTimeout(&Msg17DLoss_mS_M_u32, k_Msg17DTimeOut_mS_u16p0, &Msg17DLossAccum_Cnt_M_u16,
								  k_Ms17DTimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AD, D_FALSE_CNT_LGC, 0x01u);

			/* If no bits in the LKA Inhibit bit mask are set, then it remains false. */
			if (D_LKAINHIBIT_NOFAULTS_CNT_B16 != LKAInhibit_Cnt_M_b16)
			{
				(void)Rte_Write_LKAInhibit_Cnt_lgc(TRUE);
			}
			else
			{
				(void)Rte_Write_LKAInhibit_Cnt_lgc (FALSE);
			}

			/* If no bits in the LKA Fault bit mask are set, then it remains false. */
			if (D_LKAFAULT_NOFAULTS_CNT_B16 != LKAFault_Cnt_M_b16)
			{
				(void)Rte_Write_LKAFault_Cnt_lgc(TRUE);
				LKAFaultLatch_Cnt_D_b16 |= LKAFault_Cnt_M_b16;
			}
			else
			{
				(void)Rte_Write_LKAFault_Cnt_lgc(FALSE);
			}

			(void)Rte_Write_LKAMfgEnable_Cnt_lgc(TRUE);
		}
		else /* LKA is disabled. */
		{
			(void)Rte_Write_LKAInhibit_Cnt_lgc(TRUE);
			(void)Rte_Write_LKAFault_Cnt_lgc (TRUE);
			(void)Rte_Write_LKACmd_HwNm_f32(0.0F);
			(void)Rte_Write_LKARequest_Cnt_lgc(FALSE);
			(void)Rte_Write_LKAMfgEnable_Cnt_lgc(FALSE);

			ResetLKABus1Timers();
		}

		/* -----[ APA Enabled ]-------------------------------------------------------------------------------------- */
		if (TRUE == k_APAMfgEnable_Cnt_lgc)
		{
			(void)DtrmnNTCTimeout(&Msg337Loss_mS_M_u32, k_Msg337TimeOut_mS_u16,
								  &Msg337LossAccum_Cnt_M_u16, k_Msg337TimeOutDiag_Cnt_str,
								  NTC_Num_MissingMsg_ParkAssistParallel, D_FALSE_CNT_LGC, 0x01u);

			if (TRUE == DtrmnNTCTimeout(&Msg1F5Loss_mS_M_u32, k_Msg1F5TimeOut_mS_u16p0,
					&Msg1F5LossAccum_Cnt_M_u16, k_Msg1F5TimeOutDiag_Cnt_str,
					NTC_Num_MissingMsg_P, D_FALSE_CNT_LGC, 0x01u))
			{
				/* Default to "not in reverse" when the message goes missing */
				(void)Rte_Write_ShiftLeverIsInReverse_Cnt_lgc(FALSE);
			}

			/* Get APA recoverable faults status */
			SrlComInput_APARecFltsPer();
			APARecoverableFaults_Cnt_T_b08 = SrlComInput_APARecFltsGet();

			if (D_APARECOVERABLEFAULTS_NOFAULTS_CNT_U08 == APARecoverableFaults_Cnt_T_b08)
			{
				(void)Rte_Write_APARecoverableFaults_Cnt_lgc(FALSE);
			}
			else
			{
				(void)Rte_Write_APARecoverableFaults_Cnt_lgc(TRUE);
			}

			/* Get APA non recoverable faults status */
			SrlComInput_APANonRecFltsPer();
			APANonRecoverableFaults_Cnt_T_b16 = SrlComInput_APANonRecFltsGet();

			if (D_APANONRECOVERABLEFAULTS_NOFAULTS_CNT_U16 == APANonRecoverableFaults_Cnt_T_b16)
			{
				(void)Rte_Write_APANonRecoverableFaults_Cnt_lgc(FALSE);
			}
			else
			{
				(void)Rte_Write_APANonRecoverableFaults_Cnt_lgc(TRUE);
			}

			(void)Rte_Write_APAMfgEnable_Cnt_lgc(TRUE);
		}
		else
		{
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Msg337Loss_mS_M_u32);
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Msg337LossAPARec_mS_M_u32);
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Msg337LossAPANonRec_mS_M_u32);
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Msg1F5Loss_mS_M_u32);

			(void)Rte_Write_APARecoverableFaults_Cnt_lgc(TRUE);
			(void)Rte_Write_APANonRecoverableFaults_Cnt_lgc(FALSE);
			(void)Rte_Write_ShiftLeverIsInReverse_Cnt_lgc(FALSE);
			(void)Rte_Write_SWARTrgtAngRequest_HwDeg_f32(0.0f);
			(void)Rte_Write_APARequest_Cnt_lgc(FALSE);
			(void)Rte_Write_APAMfgEnable_Cnt_lgc(FALSE);
		}

		if (TRUE == DtrmnNTCTimeout(&Msg348HSLoss_mS_M_u32, k_Msg348HSTimeOut_mS_u16p0, &Msg348HSLossAccum_Cnt_M_u16,
		                            k_Msg348HSTimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AB, D_FALSE_CNT_LGC, 0x01u))
		{
			/* Message 0x348 HS is missing */
			(void)Rte_Write_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc(FALSE);
			(void)Rte_Write_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc(FALSE);
		}

		if (TRUE == DtrmnNTCTimeout(&Msg34AHSLoss_mS_M_u32, k_Msg34AHSTimeOut_mS_u16p0, &Msg34AHSLossAccum_Cnt_M_u16,
		                            k_Msg34AHSTimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AC, D_FALSE_CNT_LGC, 0x01u))
		{
			/* Message 0x34A HS is missing */
			(void)Rte_Write_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc(FALSE);
			(void)Rte_Write_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc(FALSE);
		}

		(void)DtrmnNTCTimeout(&Msg3E9Loss_mS_M_u32, k_Msg3E9TimeOut_mS_u16p0,
				&Msg3E9LossAccum_Cnt_M_u16, k_Msg3E9TimeOutDiag_Cnt_str,
				NTC_Num_MissingMsg_R, D_DISABLE3E9MESSAGENTC_CNT_LGC, 0x01u);
		(void)DtrmnNTCTimeout(&Msg182Loss_mS_M_u32, k_Msg182TimeOut_mS_u16,
				&Msg182LossAccum_Cnt_M_u16, k_Msg182TimeOutDiag_Cnt_str,
				NTC_Num_MissingMsg_AH, D_FALSE_CNT_LGC, 0x01u);
		if (TRUE == DtrmnNTCTimeout(&Msg4C1Loss_mS_M_u32, k_Msg4C1TimeOut_mS_u16p0,
				&Msg4C1LossAccum_Cnt_M_u16, k_Msg4C1LossTimeOutDiag_Cnt_str,
				NTC_Num_MissingMsg_U, D_FALSE_CNT_LGC, 0x01u))
		{
			(void)Rte_Write_SrlComEngTemp_DegC_f32(k_EngTempDflt_DegC_f32);
		}
		if (TRUE == DtrmnNTCTimeout(&Msg3F1Loss_mS_M_u32, k_Msg3F1TimeOut_mS_u16p0,
				&Msg3F1LossAccum_Cnt_M_u16, k_Msg3F1LossTimeOutDiag_Cnt_str,
				NTC_Num_MissingMsg_V, D_FALSE_CNT_LGC, 0x01u))
		{
			(void)Rte_Write_SrlComAmbTemp_DegC_f32(k_AmbTempDflt_DegC_f32);
		}
	}
	else
	{
		SrlComInput_SCom_ResetBus1Timers();
		SrlComInput_SCom_ResetBus2Timers();
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_DiagStsDefVehSpd_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_PrevSrlComEngOn_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(Boolean *data)
 *   Std_ReturnType Rte_Read_WIREnabled_Cnt_lgc(Boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SPMForCTCInhibit_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComAmbTemp_DegC_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComEngTemp_DegC_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComSPMOn_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComSysPwrMd_Cnt_enum(SysPwrMd data)
 *   Std_ReturnType Rte_Write_SrlComVehLonAccelValid_Cnt_lgc(Boolean data)
 *   Std_ReturnType Rte_Write_SrlComVehSpd_Kph_f32(Float data)
 *   Std_ReturnType Rte_Write_SrlComVehicleLonAccel_MpSecSq_f32(Float data)
 *   Std_ReturnType Rte_Write_VehicleSpeedValid_Cnt_lgc(Boolean data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_Per3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_Per3
 *********************************************************************************************************************/
	VAR(boolean, AUTOMATIC) DiagStsDefVehSpd_Cnt_T_lgc;

	(void)Rte_Read_DiagStsDefVehSpd_Cnt_lgc(&DiagStsDefVehSpd_Cnt_T_lgc);

	/* Poll for messages on the HS bus. */ /* PRQA S 1290 5 */
	(void)CanRxFullCANObjTask(CanRxWheel_Pulses_HS_HW_CHANNEL, CanRxWheel_Pulses_HS_HW_OBJ);									/* ID: 0x500, Periodic Rate: 1000ms */
	(void)CanRxFullCANObjTask(CanRxPPEI_Engine_General_Status_4_HW_CHANNEL, CanRxPPEI_Engine_General_Status_4_HW_OBJ);			/* ID: 0x4C1, Periodic Rate: 500ms  */
	(void)CanRxFullCANObjTask(CanRxPPEI_Platform_Eng_Cntrl_Requests_HW_CHANNEL, CanRxPPEI_Platform_Eng_Cntrl_Requests_HW_OBJ);	/* ID: 0x3F1, Periodic Rate: 250ms  */
	(void)CanRxFullCANObjTask(CanRxPPEI_Vehicle_Speed_and_Distance_HW_CHANNEL, CanRxPPEI_Vehicle_Speed_and_Distance_HW_OBJ);	/* ID: 0x3E9, Periodic Rate: 100ms  */
	(void)CanRxFullCANObjTask(CanRxPPEI_Platform_General_Status_HW_CHANNEL, CanRxPPEI_Platform_General_Status_HW_OBJ);			/* ID: 0x1F1, Periodic Rate: 100ms  */

	if (ManualVehSpdOvrRide_Cnt_M_lgc == TRUE)
	{
		StartStopFault_Cnt_M_b16 &= (uint16)~D_STARTSTOPFAULT_INVALIDVEHSPD_CNT_U16;
		(void)Rte_Write_SrlComVehSpd_Kph_f32(Limit_m(ManualVehSpd_Kph_M_f32, D_MINVEHSPD_KPH_F32, D_MAXVEHSPD_KPH_F32));
		(void)Rte_Write_VehicleSpeedValid_Cnt_lgc(TRUE);
	}
	else if ((DiagStsDefVehSpd_Cnt_T_lgc == TRUE) || (VehSpdAvgNDrvnInValid_Cnt_M_lgc == TRUE))
	{
		StartStopFault_Cnt_M_b16 |= D_STARTSTOPFAULT_INVALIDVEHSPD_CNT_U16;
		(void)Rte_Write_SrlComVehSpd_Kph_f32(k_DefaultVehSpd_Kph_f32);
		(void)Rte_Write_VehicleSpeedValid_Cnt_lgc(FALSE);
	}
	else
	{
		StartStopFault_Cnt_M_b16 &= (uint16)~D_STARTSTOPFAULT_INVALIDVEHSPD_CNT_U16;
		(void)Rte_Write_SrlComVehSpd_Kph_f32(Limit_m(VehSpdAvgNDrvn_Kph_M_f32, D_MINVEHSPD_KPH_F32, D_MAXVEHSPD_KPH_F32));
		(void)Rte_Write_VehicleSpeedValid_Cnt_lgc(TRUE);
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_GetSrlComWIRFltStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSrlComWIRFltStatus> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_GetSrlComWIRFltStatus(UInt16 *SrlComWIRFltStatus)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_GetSrlComWIRFltStatus(P2VAR(UInt16, AUTOMATIC, RTE_AP_SRLCOMINPUT_APPL_VAR) SrlComWIRFltStatus)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_GetSrlComWIRFltStatus
 *********************************************************************************************************************/

	*SrlComWIRFltStatus = SrlComWIRFltStatus_Cnt_u16;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ManualVehSpd
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ManualVehSpd> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ManualVehSpd(Float VehSpd_Kph_f32)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_ManualVehSpd
 *********************************************************************************************************************/

	ManualVehSpd_Kph_M_f32 = VehSpd_Kph_f32;
	ManualVehSpdOvrRide_Cnt_M_lgc = TRUE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ResetBus1Timers
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetBus1Timers> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_ResetBus1Timers(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetBus1Timers(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_ResetBus1Timers
 *********************************************************************************************************************/

	VAR(uint32, AUTOMATIC) CurrentSysTime_mS_T_u32p0;

	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&CurrentSysTime_mS_T_u32p0);

	Msg1E9Loss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg1E9LossAccum_Cnt_M_u16 = 0U;
	Msg232Loss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg232LossAccum_Cnt_M_u16 = 0U;
	Msg0C9Loss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg0C9LossAccum_Cnt_M_u16 = 0U;
	Msg0C1Loss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg0C1LossAccum_Cnt_M_u16 = 0U;
	Msg0D3Loss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg0D3LossAccum_Cnt_M_u16 = 0U;
	Msg1F1Loss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg1F1LossAccum_Cnt_M_u16 = 0U;
	Msg1F5Loss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg1F5LossAccum_Cnt_M_u16 = 0U;
	Msg3E9Loss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg3E9LossAccum_Cnt_M_u16 = 0U;
	Msg500Loss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg500LossAccum_Cnt_M_u16 = 0U;
	Msg3F1Loss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg3F1LossAccum_Cnt_M_u16 = 0U;
	Msg4C1Loss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg4C1LossAccum_Cnt_M_u16 = 0U;

	LatAccVldStartTime_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	YawRateVldStartTime_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	EngTempVldStartTime_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	AmbTempVldStartTime_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	VehSpdVldStartTime_mS_M_u32 = CurrentSysTime_mS_T_u32p0;

	ResetLKABus1Timers();
	ResetWhlGrndVlctyBus1Timers();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComInput_SCom_ResetBus2Timers
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetBus2Timers> of PortPrototype <SrlComInput_SCom>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void SrlComInput_SCom_ResetBus2Timers(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_SCom_ResetBus2Timers(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComInput_SCom_ResetBus2Timers
 *********************************************************************************************************************/
	VAR(uint32, AUTOMATIC) CurrentSysTime_mS_T_u32p0;

	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&CurrentSysTime_mS_T_u32p0);

	Msg337Loss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg337LossAccum_Cnt_M_u16 = 0U;
	Msg337LossAPARec_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg337LossAccumAPA_Cnt_M_u16 = 0U;
	Msg337LossAPANonRec_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg182Loss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg182LossAccum_Cnt_M_u16 = 0U;
	Msg180CELoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg180CELossAccum_Cnt_M_u16 = 0U;
	ESCChksmVldStartTime_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	ESCChksmVldAccum_Cnt_M_u16 = 0U;
	ESCRollCountVldStartTime_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	ESCRollCountVldAccum_Cnt_M_u16 = 0U;

	VehicleDynamicsESCHybCEVldStartTime_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	ParkAssistParallelCEVldStartTime_mS_M_u32 = CurrentSysTime_mS_T_u32p0;

	ResetWhlGrndVlctyBus2Timers();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SRLCOMINPUT_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
STATIC FUNC(float32, AP_SRLCOMINPUT_CODE) ProcessWhlStatus(	VAR(WhlRotStat, AUTOMATIC) WhlRotStatus,
															P2VAR(uint16, AUTOMATIC, AUTOMATIC) OldSeqNum_Ptr_T_u16,
															P2VAR(uint16, AUTOMATIC, AUTOMATIC) OldWhlDistTstm_Ptr_T_u16,
															P2VAR(uint16, AUTOMATIC, AUTOMATIC) OldWhlPCntr_Ptr_T_u16,
															P2VAR(float32, AUTOMATIC, AUTOMATIC) OldRawWhlFreq_Ptr_T_f32,
															VAR(float32, AUTOMATIC) WhlTstmpRes_SecpCnt_T_f32,
															VAR(float32, AUTOMATIC) PulseScale_RevpCnt_T_f32,
															P2VAR(uint32, AUTOMATIC, AUTOMATIC) LastPlsChngTime_Ptr_T_u32,
															P2VAR(uint16, AUTOMATIC, AUTOMATIC) WIRFltStatus_Ptr_T_u16,
															P2VAR(uint32, AUTOMATIC, AUTOMATIC) InvStartTime_Ptr_T_u32)
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;
	VAR(float32, AUTOMATIC) RawWhlFreq_Hz_T_f32;

	RawWhlFreq_Hz_T_f32 = *OldRawWhlFreq_Ptr_T_f32;

	if (0u != WhlRotStatus.WRSWhlDistVal)
	{
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(*InvStartTime_Ptr_T_u32, &ElapsedTime_mS_T_u16p0);

		if (ElapsedTime_mS_T_u16p0 > k_WhlRotVldTimeOut_mS_u16p0)
		{
			*WIRFltStatus_Ptr_T_u16 |= D_WIRFLTVALBIT_CNT_U16;
			RawWhlFreq_Hz_T_f32 = 0.0F;
		}
	}
	else if (*OldSeqNum_Ptr_T_u16 == WhlRotStatus.WRSSeqNum)
	{
		*WIRFltStatus_Ptr_T_u16 |= D_WIRFLTSEQNUMBIT_CNT_U16;
		RawWhlFreq_Hz_T_f32 = 0.0F;
	}
	else if (0u != WhlRotStatus.WRSWhlRotStatRst)
	{
		*WIRFltStatus_Ptr_T_u16 |= D_WIRFLTRESETBIT_CNT_U16;
		RawWhlFreq_Hz_T_f32 = 0.0F;
	}
	else
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(InvStartTime_Ptr_T_u32);

		if (*OldWhlDistTstm_Ptr_T_u16 != WhlRotStatus.WRSWhlDistTstm)
		{
			(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(*LastPlsChngTime_Ptr_T_u32, &ElapsedTime_mS_T_u16p0);

			if (((float32)ElapsedTime_mS_T_u16p0) < (65000.0F * 1000.0F * WhlTstmpRes_SecpCnt_T_f32))
			{
				RawWhlFreq_Hz_T_f32 = CalcWhlFreq(	WhlRotStatus.WRSWhlDistPCntr,
													*OldWhlPCntr_Ptr_T_u16,
													WhlRotStatus.WRSWhlDistTstm,
													*OldWhlDistTstm_Ptr_T_u16,
													OldRawWhlFreq_Ptr_T_f32,
													WhlTstmpRes_SecpCnt_T_f32,
													PulseScale_RevpCnt_T_f32,
													WIRFltStatus_Ptr_T_u16);
			}

			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(LastPlsChngTime_Ptr_T_u32);
		}

		*OldWhlPCntr_Ptr_T_u16 = WhlRotStatus.WRSWhlDistPCntr;
		*OldWhlDistTstm_Ptr_T_u16 = WhlRotStatus.WRSWhlDistTstm;
	}

	*OldSeqNum_Ptr_T_u16 = WhlRotStatus.WRSSeqNum;

	return(RawWhlFreq_Hz_T_f32);
}

STATIC FUNC(float32, AP_SRLCOMINPUT_CODE) CalcWhlFreq(	VAR(uint16, AUTOMATIC) WRSWhlDistPCntr_Cnt_T_u16,
														VAR(uint16, AUTOMATIC) OldWhlPCntr_Cnt_T_u16,
														VAR(uint16, AUTOMATIC) WRSWhlDistTstm_Cnt_T_u16,
														VAR(uint16, AUTOMATIC) OldWhlDistTstm_Cnt_T_u16,
														P2VAR(float32, AUTOMATIC, AUTOMATIC) OldRawWhlFreq_Ptr_T_f32,
														VAR(float32, AUTOMATIC) WhlTstmpRes_SecpCnt_T_f32,
														VAR(float32, AUTOMATIC) PulseScale_RevpCnt_T_f32,
														P2VAR(uint16, AUTOMATIC, AUTOMATIC) WIRFltStatus_Ptr_T_u16)
{
	VAR(sint16, AUTOMATIC) DeltaPCntr_Cnt_T_s16;
	VAR(sint32, AUTOMATIC) DeltaTstm_Cnt_T_s32;
	VAR(float32, AUTOMATIC) RawWhlFreq_Hz_T_f32;
	VAR(float32, AUTOMATIC) DeltaTstm_Sec_T_f32;

	DeltaPCntr_Cnt_T_s16 = (sint16)WRSWhlDistPCntr_Cnt_T_u16 - (sint16)OldWhlPCntr_Cnt_T_u16;
	/* PCntr will always increment, so negative values always correspond to rollover */
	if (DeltaPCntr_Cnt_T_s16 < 0)
	{
		DeltaPCntr_Cnt_T_s16 += 1024;
	}
	/* Tstm will always increment, so negative values always correspond to rollover */
	DeltaTstm_Cnt_T_s32 = (sint32)WRSWhlDistTstm_Cnt_T_u16 - (sint32)OldWhlDistTstm_Cnt_T_u16;
	if (DeltaTstm_Cnt_T_s32 < 0)
	{
		DeltaTstm_Cnt_T_s32 += 65536;
	}

	DeltaTstm_Sec_T_f32 = ((float32)DeltaTstm_Cnt_T_s32 * WhlTstmpRes_SecpCnt_T_f32);
	if (Abs_f32_m(DeltaTstm_Sec_T_f32) >= FLT_EPSILON)
	{
		RawWhlFreq_Hz_T_f32 = ((float32)DeltaPCntr_Cnt_T_s16 * PulseScale_RevpCnt_T_f32) / DeltaTstm_Sec_T_f32;

		if (RawWhlFreq_Hz_T_f32 > 55.48)
		{
			*WIRFltStatus_Ptr_T_u16 |= D_WIRFLTMAXFREQ_CNT_U16;
			RawWhlFreq_Hz_T_f32 = 55.48f;
		}
		else
		{
			*WIRFltStatus_Ptr_T_u16 &= (uint16)~D_WIRFLTMAXFREQ_CNT_U16;
		}
	}
	else
	{
		*WIRFltStatus_Ptr_T_u16 |= D_WIRFLTMAXFREQ_CNT_U16;
		RawWhlFreq_Hz_T_f32 = 55.48f;
	}

	if (Abs_f32_m(RawWhlFreq_Hz_T_f32 - *OldRawWhlFreq_Ptr_T_f32) > k_MaxFreqChg_Hz_f32)
	{
		*WIRFltStatus_Ptr_T_u16 |= D_WIRFLTFREQDELTA_CNT_U16;
		RawWhlFreq_Hz_T_f32 = *OldRawWhlFreq_Ptr_T_f32;
	}
	else
	{
		*WIRFltStatus_Ptr_T_u16 &= ~D_WIRFLTFREQDELTA_CNT_U16;
	}

	*OldRawWhlFreq_Ptr_T_f32 = RawWhlFreq_Hz_T_f32;

	return(RawWhlFreq_Hz_T_f32);
}

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) DtrmnNTCTimeout(	P2VAR(uint32, AUTOMATIC, AUTOMATIC) MsgLossTimer_mS_T_u32,
														VAR(uint16, AUTOMATIC) RxMsgTimeoutCal_mS_T_u16p0,
														P2VAR(uint16, AUTOMATIC, AUTOMATIC) FaultAccumulator_Cnt_T_u16,
														VAR(DiagSettings_Str, AUTOMATIC) DiagSettings_Cnt_T_str,
														VAR(uint16, AUTOMATIC) NTCNum_Cnt_T_u16,
														VAR(boolean, AUTOMATIC) InhibitNTCFlag_Cnt_T_lgc,
														VAR(uint8, AUTOMATIC) NTCbit_Cnt_T_u8)
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;
	VAR(boolean, AUTOMATIC) FaultPresent_Cnt_T_lgc;

	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(*MsgLossTimer_mS_T_u32, &ElapsedTime_mS_T_u16p0);
	if (ElapsedTime_mS_T_u16p0 > RxMsgTimeoutCal_mS_T_u16p0)
	{
		/* If the timer has elapsed, reset it. */
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(MsgLossTimer_mS_T_u32);

		/* Don't count the fault if it is inhibited. */
		if (InhibitNTCFlag_Cnt_T_lgc == FALSE)
		{
			/* Check if the fault accumulator is saturated. If so, set the fault.*/
			*FaultAccumulator_Cnt_T_u16 = DiagPStep_m(*FaultAccumulator_Cnt_T_u16, DiagSettings_Cnt_T_str);
			if (TRUE == DiagFailed_m(*FaultAccumulator_Cnt_T_u16, DiagSettings_Cnt_T_str))
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, NTCbit_Cnt_T_u8, NTC_STATUS_FAILED);
			}
		}
		FaultPresent_Cnt_T_lgc = TRUE;
	}
	else
	{
		FaultPresent_Cnt_T_lgc = FALSE;
	}

	return(FaultPresent_Cnt_T_lgc);
}

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) NTCCheckClear(P2VAR(uint32, AUTOMATIC, AUTOMATIC) MsgLossTimer_mS_T_u32,
														P2VAR(uint16, AUTOMATIC, AUTOMATIC) FaultAccumulator_Cnt_T_u16,
														CONSTP2CONST(DiagSettings_Str, AUTOMATIC, AUTOMATIC) DiagSettings_Cnt_T_str,
														VAR(uint16, AUTOMATIC) NTCNum_Cnt_T_u16)
{
	VAR(boolean, AUTOMATIC) FaultCleared_Cnt_T_lgc;

	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(MsgLossTimer_mS_T_u32);
	*FaultAccumulator_Cnt_T_u16 = DiagNStep_m(*FaultAccumulator_Cnt_T_u16, (*DiagSettings_Cnt_T_str));
	if (0u == *FaultAccumulator_Cnt_T_u16)
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNum_Cnt_T_u16, 0x01u, NTC_STATUS_PASSED);
		FaultCleared_Cnt_T_lgc = TRUE;
	}
	else
	{
		FaultCleared_Cnt_T_lgc = FALSE;
	}

	return(FaultCleared_Cnt_T_lgc);
}

STATIC FUNC(boolean, AP_SRLCOMINPUT_CODE) DtrmnTimerElapsed(VAR(uint32, AUTOMATIC) MsgLossTimer_mS_T_u32,
															VAR(uint16, AUTOMATIC) RxMsgInhibitNTCTOCal_mS_T_u16p0)
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;
	VAR(boolean, AUTOMATIC) NTCInhibit_Cnt_T_lgc;

	(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(MsgLossTimer_mS_T_u32, &ElapsedTime_mS_T_u16p0);
	if (ElapsedTime_mS_T_u16p0 > RxMsgInhibitNTCTOCal_mS_T_u16p0)
	{
		NTCInhibit_Cnt_T_lgc = TRUE;
	}
	else
	{
		NTCInhibit_Cnt_T_lgc = FALSE;
	}

	return(NTCInhibit_Cnt_T_lgc);
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ResetLKABus1Timers(void)
{
	VAR(uint32, AUTOMATIC) CurrentSysTime_mS_T_u32p0;

	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&CurrentSysTime_mS_T_u32p0);

	Msg214Loss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg214LossAccum_Cnt_M_u16 = 0U;
	Msg214LKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg180HSLKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg180HSLoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg180HSLossAccum_Cnt_M_u16 = 0U;
	Msg1E9LKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg17DLoss_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	Msg17DLossAccum_Cnt_M_u16 = 0U;
	Msg17DLKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;

	AntilockTCbrakeVldStartTime_mS_M_u32p0       = CurrentSysTime_mS_T_u32p0;
	RedntVSEActARCVldStartTime_mS_M_u32          = CurrentSysTime_mS_T_u32p0;
	RedntVSEActVldStartTime_mS_M_u32             = CurrentSysTime_mS_T_u32p0;
	ABSActvProtPValVldStartTime_mS_M_u32         = CurrentSysTime_mS_T_u32p0;
	ABSActvProtARCVldStartTime_mS_M_u32          = CurrentSysTime_mS_T_u32p0;
	ABSActvProtVldStartTime_mS_M_u32             = CurrentSysTime_mS_T_u32p0;
	VSEActVldStartTime_mS_M_u32p0                = CurrentSysTime_mS_T_u32p0;
	TCSysEVldStartTime_mS_M_u32p0                = CurrentSysTime_mS_T_u32p0;
	ABSFldVldStartTime_mS_M_u32p0                = CurrentSysTime_mS_T_u32p0;
	VhDynCVldStartTime_mS_M_u32p0                = CurrentSysTime_mS_T_u32p0;
	LKATqOvrDltCmdPrtVlVldStartTime_mS_M_u32     = CurrentSysTime_mS_T_u32p0;
	LKATqOvrDltCmdRCVldStartTime_mS_M_u32        = CurrentSysTime_mS_T_u32p0;
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ResetWhlGrndVlctyBus1Timers(void)
{
	VAR(uint32, AUTOMATIC) CurrentSysTime_mS_T_u32p0;

	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&CurrentSysTime_mS_T_u32p0);

	Msg348HSLoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg348HSLossAccum_Cnt_M_u16 = 0U;
	Msg34AHSLoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg34AHSLossAccum_Cnt_M_u16 = 0U;
	Msg348HSLKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg34AHSLKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;

	WhlGrndVlctyRtDrvnHSStuck_mS_M_u32           = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyLftDrvnHSStuck_mS_M_u32          = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyRtNnDrvnHSStuck_mS_M_u32         = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyLftNnDrvnHSStuck_mS_M_u32        = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyRtDrvnHSVldStartTime_mS_M_u32    = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyLftDrvnHSVldStartTime_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyRtNnDrvnHSVldStartTime_mS_M_u32  = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyLftNnDrvnHSVldStartTime_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
}

STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) ResetWhlGrndVlctyBus2Timers(void)
{
	VAR(uint32, AUTOMATIC) CurrentSysTime_mS_T_u32p0;

	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&CurrentSysTime_mS_T_u32p0);

	Msg34ACELoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg34ACELossAccum_Cnt_M_u16 = 0U;
	Msg348CELoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg348CELossAccum_Cnt_M_u16 = 0U;
	Msg34ACELKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
	Msg348CELKALoss_mS_M_u32 = CurrentSysTime_mS_T_u32p0;

	WhlGrndVlctyRtDrvnCEStuck_mS_M_u32           = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyLftDrvnCEStuck_mS_M_u32          = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyRtNnDrvnCEStuck_mS_M_u32         = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyLftNnDrvnCEStuck_mS_M_u32        = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyRtDrvnCEVldStartTime_mS_M_u32    = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyLftDrvnCEVldStartTime_mS_M_u32   = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyRtNnDrvnCEVldStartTime_mS_M_u32  = CurrentSysTime_mS_T_u32p0;
	WhlGrndVlctyLftNnDrvnCEVldStartTime_mS_M_u32 = CurrentSysTime_mS_T_u32p0;
}

/* **********************************************************************************************************************
 * ******************************** Messages Received by the PSCM *******************************************************
 * ********************************         High-Speed Bus        *******************************************************
 * **********************************************************************************************************************
 */
/* ID: 0x0C1, Periodic Rate: 10ms, Polled in runnable: SrlComInput_Per2*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxNonDrivnWhlRotationlStat_x0C1(CanReceiveHandle rcvObject)
{
	VAR(RT_PPEI_NonDrivn_Whl_Rotationl_Stat, AUTOMATIC) Data_T_str;
	VAR(float32, AUTOMATIC) PulseScale_RevpCnt_T_f32;
	VAR(float32, AUTOMATIC) WhlTstmpRes_SecpCnt_T_f32;
	VAR(float32, AUTOMATIC) RawWhlFreqL_Hz_T_f32;
	VAR(float32, AUTOMATIC) RawWhlFreqR_Hz_T_f32;
	VAR(uint16, AUTOMATIC) WIRFltStatusL_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WIRFltStatusR_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WIRFltStatus_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) WIRFltParam_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) RightValid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) LeftValid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) WIREnabled_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) InvalidFltStatus_Cnt_T_u8;
	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;

	(void)IlGetRxWhlRotatStatLftDrvn();
	(void)IlGetRxWhlRotatStatRtDrvn();

	Data_T_str.WhlRotStatLft.WRSSeqNum = IlGetRxWRSLDSeqNum();
	Data_T_str.WhlRotStatLft.WRSWhlDisTpRC = IlGetRxWRSLDWhlDisTpRC();
	Data_T_str.WhlRotStatLft.WRSWhlDistVal = IlGetRxWRSLDWhlDistVal();
	Data_T_str.WhlRotStatLft.WRSWhlRotStatRst = IlGetRxWRSLDWhlRotStatRst();
	Data_T_str.WhlRotStatLft.WRSWhlDistTstm = IlGetRxWRSLDWhlDistTmstm();
	Data_T_str.WhlRotStatLft.WRSWhlDistPCntr = IlGetRxWRSLDWhlDistPlsCntr();

	Data_T_str.WhlRotStatRght.WRSSeqNum = IlGetRxWRSRDSeqNum();
	Data_T_str.WhlRotStatRght.WRSWhlDisTpRC = IlGetRxWRSRDWhlDisTpRC();
	Data_T_str.WhlRotStatRght.WRSWhlDistVal = IlGetRxWRSRDWhlDistVal();
	Data_T_str.WhlRotStatRght.WRSWhlRotStatRst = IlGetRxWRSRDWhlRotStatRst();
	Data_T_str.WhlRotStatRght.WRSWhlDistTstm = IlGetRxWRSRDWhlDistTmstm();
	Data_T_str.WhlRotStatRght.WRSWhlDistPCntr = IlGetRxWRSRDWhlDistPlsCntr();

	PulseScale_RevpCnt_T_f32 = PulseScale_RevpCnt_M_f32;
	WhlTstmpRes_SecpCnt_T_f32 = WhlTstmpRes_SecpCnt_M_f32;
	(void)Rte_Read_WIREnabled_Cnt_lgc(&WIREnabled_Cnt_T_lgc);
	(void)Rte_Call_NxtrDiagMgr_GetNTCStatus(NTC_Num_InvalidMsg_M, &InvalidFltStatus_Cnt_T_u8);
	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		/* Clear Missing Msg Fault */
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_MissingMsg_M, 0x01u, NTC_STATUS_PASSED);

		if (TRUE != WIREnabled_Cnt_T_lgc)
		{
			(void)Rte_Write_SrlComLWhlSpdVld_Cnt_lgc(TRUE);
			(void)Rte_Write_SrlComRWhlSpdVld_Cnt_lgc(TRUE);
			(void)Rte_Write_SrlComLWhlSpd_Hz_f32(0.0F);
			(void)Rte_Write_SrlComRWhlSpd_Hz_f32(0.0F);

			/* Clear Invalid Signals Fault */
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_M, 0x01u, NTC_STATUS_PASSED);
		}
		else
		{
			/* Initialize this loop status with the bits that are set or cleared in the local functions */
			WIRFltStatusL_Cnt_T_u16 = SrlComWIRFltStatus_Cnt_u16 & D_WIRFLTFREQMASK_CNT_U16;
			WIRFltStatusR_Cnt_T_u16 = (SrlComWIRFltStatus_Cnt_u16 >> 5) & D_WIRFLTFREQMASK_CNT_U16;
			SrlComWIRFltStatus_Cnt_u16 &= (uint16)(~D_WIRFLTFREQMASKLR_CNT_U16);

			RawWhlFreqL_Hz_T_f32 = ProcessWhlStatus(Data_T_str.WhlRotStatLft,
													&OldSeqNumL_Cnt_M_u16,
													&OldWhlDistTstmL_Cnt_M_u16,
													&OldWhlPCntrL_Cnt_M_u16,
													&OldRawWhlFreqL_Hz_M_f32,
													WhlTstmpRes_SecpCnt_T_f32,
													PulseScale_RevpCnt_T_f32,
													&LastPlsChngTimeL_mS_M_u32,
													&WIRFltStatusL_Cnt_T_u16,
													&InvStartTimeL_mS_M_u32);

			RawWhlFreqR_Hz_T_f32 = ProcessWhlStatus(Data_T_str.WhlRotStatRght,
													&OldSeqNumR_Cnt_M_u16,
													&OldWhlDistTstmR_Cnt_M_u16,
													&OldWhlPCntrR_Cnt_M_u16,
													&OldRawWhlFreqR_Hz_M_f32,
													WhlTstmpRes_SecpCnt_T_f32,
													PulseScale_RevpCnt_T_f32,
													&LastPlsChngTimeR_mS_M_u32,
													&WIRFltStatusR_Cnt_T_u16,
													&InvStartTimeR_mS_M_u32);

			WIRFltStatus_Cnt_T_u16 = (WIRFltStatusR_Cnt_T_u16 << 5) | WIRFltStatusL_Cnt_T_u16;

			WIRFltParam_Cnt_T_u08 = (uint8)((WIRFltStatusR_Cnt_T_u16 & D_WIRFLTVALIDITY_CNT_U16) << 3U);
			WIRFltParam_Cnt_T_u08 |= (uint8)(WIRFltStatusL_Cnt_T_u16 & D_WIRFLTVALIDITY_CNT_U16);

			/* Set or Clear Validity Bits */
			if (0U == (WIRFltStatus_Cnt_T_u16 & D_WIRFLTVALIDITYLR_CNT_U16))
			{
				WIRFltStatusAcc_Cnt_M_u16 = DiagNStep_m(WIRFltStatusAcc_Cnt_M_u16, k_WIRFltStatusDiag_Cnt_str);

				if (WIRFltStatusAcc_Cnt_M_u16 == 0U)
				{
					/* No Invalid Bits set, clear fault */
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_M, 0x01u, NTC_STATUS_PASSED);
				}

				/* Clear Status Bits if not in history (confirmed) */
				if (0u == (InvalidFltStatus_Cnt_T_u8 & D_CONFIRMEDDTCBIT_CNT_B8))
				{
					SrlComWIRFltStatus_Cnt_u16 &= (uint16)(~D_WIRFLTVALIDITYLR_CNT_U16);
				}
			}
			else
			{
				if ((Nvm_CMEC_Cnt_u8 == 0U) || (Nvm_CMEC_Cnt_u8 == 0xFFU))
				{
					WIRFltStatusAcc_Cnt_M_u16 = DiagPStep_m(WIRFltStatusAcc_Cnt_M_u16, k_WIRFltStatusDiag_Cnt_str);

					if (DiagFailed_m(WIRFltStatusAcc_Cnt_M_u16, k_WIRFltStatusDiag_Cnt_str) == TRUE)
					{
						(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_M, WIRFltParam_Cnt_T_u08, NTC_STATUS_FAILED);
					}
				}
				SrlComWIRFltStatus_Cnt_u16 |= (WIRFltStatus_Cnt_T_u16 & D_WIRFLTVALIDITYLR_CNT_U16);
			}

			/* Set Frequency Bits that are active */
			SrlComWIRFltStatus_Cnt_u16 |= (WIRFltStatus_Cnt_T_u16 & D_WIRFLTFREQMASKLR_CNT_U16);

			/* Set Validity Output for L and R */
			if (0U == (WIRFltStatus_Cnt_T_u16 & D_WIRFLTALLBITSL_CNT_U16))
			{
				LeftValid_Cnt_T_lgc = TRUE;
			}
			else
			{
				LeftValid_Cnt_T_lgc = FALSE;
			}

			if (0U == (WIRFltStatus_Cnt_T_u16 & D_WIRFLTALLBITSR_CNT_U16))
			{
				RightValid_Cnt_T_lgc = TRUE;
			}
			else
			{
				RightValid_Cnt_T_lgc = FALSE;
			}

			RawWhlFreqL_Hz_T_f32 = Min_m(RawWhlFreqL_Hz_T_f32, 40.0F);
			RawWhlFreqR_Hz_T_f32 = Min_m(RawWhlFreqR_Hz_T_f32, 40.0F);

			(void)Rte_Write_SrlComLWhlSpdVld_Cnt_lgc(LeftValid_Cnt_T_lgc);
			(void)Rte_Write_SrlComRWhlSpdVld_Cnt_lgc(RightValid_Cnt_T_lgc);
			(void)Rte_Write_SrlComLWhlSpd_Hz_f32(RawWhlFreqL_Hz_T_f32);
			(void)Rte_Write_SrlComRWhlSpd_Hz_f32(RawWhlFreqR_Hz_T_f32);
		}
		(void)NTCCheckClear(&Msg0C1Loss_mS_M_u32, &Msg0C1LossAccum_Cnt_M_u16, &k_Msg0C1TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_M);
	}
}

/* ID: 0x0C9, Periodic Rate: 12ms, Polled in runnable: SrlComInput_Per2*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxEngineGeneralStatus1_x0C9(CanReceiveHandle rcvObject)
{
	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) EngineSpeed_Cnt_T_u16;
	VAR(float32, AUTOMATIC) EngineSpeed_Rpm_T_f32;
	VAR(uint8, AUTOMATIC) EngSpdStat_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) PT_CrnkAct_Cnt_T_lgc;

	SrlComInput_EngRunAtv_Cnt_M_lgc = IlGetRxEngRunAtv();
	EngineSpeed_Cnt_T_u16 = IlGetRxEngSpd();
	EngSpdStat_Cnt_T_u08 = IlGetRxEngSpdStat();
	PT_CrnkAct_Cnt_T_lgc = IlGetRxPT_CrnkAct();

	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		if (D_NORMALOPERATION_CNT_U08 == EngSpdStat_Cnt_T_u08)
		{
			StartStopFault_Cnt_M_b16 &= (uint16)~D_STARTSTOPFAULT_INVALID0C9_CNT_U16;

			(void)NTCCheckClear(&EngSpdStatlVldStartTime_mS_M_u32, &EngSpdStatVldAccum_Cnt_M_u16, &k_EngSpdStatVldDiag_Cnt_str, NTC_Num_InvalidMsg_N);
		}
		else
		{
			StartStopFault_Cnt_M_b16 |= D_STARTSTOPFAULT_INVALID0C9_CNT_U16;

			(void)DtrmnNTCTimeout(&EngSpdStatlVldStartTime_mS_M_u32, k_EngSpdStatVldTimeOut_mS_u16p0,
					&EngSpdStatVldAccum_Cnt_M_u16, k_EngSpdStatVldDiag_Cnt_str,
					NTC_Num_InvalidMsg_N,
					FALSE,
					0x01u);
		}
		StartStopFault_Cnt_M_b16 &= (uint16)~D_STARTSTOPFAULT_MISSING0C9_CNT_U16;

		EngineSpeed_Rpm_T_f32 = (((float32)(EngineSpeed_Cnt_T_u16)) * D_ENGSPDSF_RPM_F32);
		EngineSpeed_Rpm_T_f32 = Limit_m(EngineSpeed_Rpm_T_f32, D_ENGSPDMIN_RPM_F32, D_ENGSPDMAX_RPM_F32);
		(void)Rte_Write_SrlComEngineSpeed_Rpm_f32(EngineSpeed_Rpm_T_f32);
		(void)Rte_Write_SrlComEngOn_Cnt_lgc(SrlComInput_EngRunAtv_Cnt_M_lgc);
		(void)Rte_Write_EngRunAtvForCTCInhibit_Cnt_lgc(SrlComInput_EngRunAtv_Cnt_M_lgc);
		(void)Rte_Write_PowertrainCrankActive_Cnt_lgc(PT_CrnkAct_Cnt_T_lgc);

		(void)NTCCheckClear(&Msg0C9Loss_mS_M_u32, &Msg0C9LossAccum_Cnt_M_u16, &k_Msg0C9TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_N);
	}
}

/* ====================================================================================================================
 *  ID            : 0x0D3
 *  Name          : Hybrid General Status 3
 *  Periodic Rate : 12ms
 *  Polled in     : SrlComInput_Per2
 * --------------------------------------------------------------------------------------------------------------------
 */
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxHybridGeneralStatus3_x0D3(CanReceiveHandle rcvObject)
{
	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) ActAxleTrq_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) ActAxleTrqV_Cnt_T_u08;
	VAR(float32, AUTOMATIC) ActAxleTrq_TransNm_T_f32;
	VAR(boolean, AUTOMATIC) FaultSet_Cnt_T_lgc;

	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	IlGetRxActAxleTrqGroup();

	ActAxleTrq_Cnt_T_u16 = IlGetRxActAxleTrq();
	ActAxleTrqV_Cnt_T_u08 = IlGetRxActAxleTrqV();

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		if (D_VALID_CNT_U08 == ActAxleTrqV_Cnt_T_u08)
		{
			/* Write the valid Transmission Torque to the RTE */
			ActAxleTrq_TransNm_T_f32 = ((float32)ActAxleTrq_Cnt_T_u16 * D_ACTAXLETRQSF_TRANSNM_F32) - D_ACTAXLETRQOFFSET_TRANSNM_F32;
			(void)Rte_Write_SrlComTransmissionTrq_TransNm_f32(ActAxleTrq_TransNm_T_f32);
			SrlComInput_Message0D3PresentAndValid_Cnt_M_lgc = TRUE;

			(void)NTCCheckClear(&ActAxleTrqVldStartTime_mS_M_u32, &ActAxleTrqVldAccum_Cnt_M_u16, &k_ActAxleTrqVldDiag_Cnt_str, NTC_Num_InvalidMsg_T);
		}
		else
		{
			FaultSet_Cnt_T_lgc = DtrmnNTCTimeout(&ActAxleTrqVldStartTime_mS_M_u32, k_ActAxleTrqVldTimeOut_mS_u16p0,
						&ActAxleTrqVldAccum_Cnt_M_u16, k_ActAxleTrqVldDiag_Cnt_str,
						NTC_Num_InvalidMsg_T, D_FALSE_CNT_LGC, 0x01u);

			if (TRUE == FaultSet_Cnt_T_lgc)
			{
				/* Set Transmission Torque value to zero when the data is determined to be invalid (post-timeout) */
				(void)Rte_Write_SrlComTransmissionTrq_TransNm_f32(D_ZERO_ULS_F32);
				SrlComInput_Message0D3PresentAndValid_Cnt_M_lgc = FALSE;
			}
		}

		(void)NTCCheckClear(&Msg0D3Loss_mS_M_u32, &Msg0D3LossAccum_Cnt_M_u16, &k_Msg0D3TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_T);
	}
}

/* ID: 0x17D, Periodic Rate: 100ms, Polled in runnable: SrlComInput_Per3 */
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxAntilockBrakeandTCStatusHS_x17D(CanReceiveHandle rcvObject)
{
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;
	VAR(uint16, AUTOMATIC) RxVehStabEn_Cnt_T_u16;

	RxVehStabEn_Cnt_T_u16 = IlGetRxVehStabEnhmntStat_0();

	/* If vehicle stability is inactive, the message is valid and LKA inhibit may be turned off. */
	if (D_VEHSTABILITYINACTIVE_CNT_U08 == RxVehStabEn_Cnt_T_u16)
	{
		LKAInhibit_Cnt_M_b16 &= ~D_LKAINHIBIT_INVALID17D_CNT_B16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&AntilockTCbrakeVldStartTime_mS_M_u32p0);
	}
	/* If vehicle stability is faulted, set LKA inhibit and determine if the NTC should be set */
	else if (D_VEHSTABILITYFAULT_CNT_U08 == RxVehStabEn_Cnt_T_u16)
	{
		LKAInhibit_Cnt_M_b16 |= D_LKAINHIBIT_INVALID17D_CNT_B16;

		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(AntilockTCbrakeVldStartTime_mS_M_u32p0, &ElapsedTime_mS_T_u16p0);
		if (ElapsedTime_mS_T_u16p0 >= k_LKAVehStabEnVldTimeOut_mS_u16p0)
		{
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&AntilockTCbrakeVldStartTime_mS_M_u32p0);
		}
	}
	else /* Any other state is a valid, but set LKA to inhibited. */
	{
		LKAInhibit_Cnt_M_b16 |= D_LKAINHIBIT_INVALID17D_CNT_B16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&AntilockTCbrakeVldStartTime_mS_M_u32p0);
	}

	/* Reset the LKA timer. */
	LKAFault_Cnt_M_b16 &= ~D_LKAFAULT_MISSING17D_CNT_B16;								/* Clear the LKA fault for missing this message. */
	(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Msg17DLKALoss_mS_M_u32);
	(void)NTCCheckClear(&Msg17DLoss_mS_M_u32, &Msg17DLossAccum_Cnt_M_u16, &k_Ms17DTimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AD);
}

/* ID: 0x180, Periodic Rate: 20ms, Polled in runnable: SrlComInput_Per2*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxLKASteeringTorqueCmdHS_x180(CanReceiveHandle rcvObject)
{
	VAR(uint16, AUTOMATIC) RollingCounter_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ProtectReceived_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ProtectCalculated_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) TrqRqAct_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) TrqRqVl_Cnt_T_u16;
	VAR(sint16, AUTOMATIC) TrqRqVl_Cnt_T_s16;
	VAR(float32,AUTOMATIC) TrqRqVl_Cnt_T_f32;
	VAR(boolean,AUTOMATIC) MessageValid_Cnt_T_lgc;

	MessageValid_Cnt_T_lgc = TRUE;

	IlGetRxLKATqOvrDltCmd();

	RollingCounter_Cnt_T_u16 = IlGetRxLKATqOvrDltCmdRC();
	ProtectReceived_Cnt_T_u16 = IlGetRxLKATqOvrDltCmdPrtVl();
	TrqRqAct_Cnt_T_u16 = IlGetRxLKATODC_TrqRqAct();
	TrqRqVl_Cnt_T_u16 = IlGetRxLKATODC_TrqVl();

	/* Calculate the checksum. */
	ProtectCalculated_Cnt_T_u16 = TrqRqAct_Cnt_T_u16 << 11;
	ProtectCalculated_Cnt_T_u16 |= TrqRqVl_Cnt_T_u16;
	ProtectCalculated_Cnt_T_u16 += RollingCounter_Cnt_T_u16;
	ProtectCalculated_Cnt_T_u16 = ~ProtectCalculated_Cnt_T_u16;
	ProtectCalculated_Cnt_T_u16++;
	ProtectCalculated_Cnt_T_u16 &= 0xFFFu;

	/* If the checksum is valid */
	if (ProtectCalculated_Cnt_T_u16 == ProtectReceived_Cnt_T_u16)
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&LKATqOvrDltCmdPrtVlVldStartTime_mS_M_u32);
		LKATqOvrDltCmdPrtVlVldAccum_Cnt_M_u16 = DiagNStep_m(LKATqOvrDltCmdPrtVlVldAccum_Cnt_M_u16, k_LKATqOvrDltCmdPrtVlVldDiag_Cnt_str);
		LKAFault_Cnt_M_b16 &= ~D_LKAFAULT_INVALIDPV180_CNT_B16;
	}
	else /* The protection value is invalid. */
	{
		MessageValid_Cnt_T_lgc = FALSE;

		(void)DtrmnNTCTimeout(&LKATqOvrDltCmdPrtVlVldStartTime_mS_M_u32, k_LKATqOvrDltCmdPrtVlVldTimeOut_mS_u16p0,
						&LKATqOvrDltCmdPrtVlVldAccum_Cnt_M_u16, k_LKATqOvrDltCmdPrtVlVldDiag_Cnt_str,
						NTC_Num_InvalidMsg_AA,
						FALSE,
						0x02u);

		/* Set LKA Fault */
		LKAFault_Cnt_M_b16 |= D_LKAFAULT_INVALIDPV180_CNT_B16;
	}

    /* Rolling Counter is Valid */
	if ((D_INVALIDROLLINGCOUNT_CNT_U08 != PrevLKARollingCounter_Cnt_M_u16) &&
			(RollingCounter_Cnt_T_u16 == ((PrevLKARollingCounter_Cnt_M_u16 + 1u) & 3u)))
	{
		/* Convert requested active signal for RTE. */
		if (TRUE == TrqRqAct_Cnt_T_u16)
		{
			(void)Rte_Write_LKARequest_Cnt_lgc(TRUE);
		}
		else
		{
			(void)Rte_Write_LKARequest_Cnt_lgc(FALSE);
		}

		/* Sign extend torque overlay value. */
		if (TrqRqVl_Cnt_T_u16 > 1023u)
		{
			TrqRqVl_Cnt_T_s16 = (sint16)(TrqRqVl_Cnt_T_u16 | 0xFC00u);
		}
		else
		{
			TrqRqVl_Cnt_T_s16 = (sint16)TrqRqVl_Cnt_T_u16;
		}

		/* Convert from the customer sign convention. */
		TrqRqVl_Cnt_T_s16 *= k_SComTrqPosPol_Cnt_s08;

		/* Scale the signal, and write it to the RTE. */
		TrqRqVl_Cnt_T_f32 = (float32)TrqRqVl_Cnt_T_s16 * D_TRQRQV1SF_HWNM_F32;
		TrqRqVl_Cnt_T_f32 = Limit_m(TrqRqVl_Cnt_T_f32, D_TRQRQV1MIN_HWNM_F32, D_TRQRQV1MAX_HWNM_F32);
		(void)Rte_Write_LKACmd_HwNm_f32(TrqRqVl_Cnt_T_f32);

		/* Try to clear the LKA fault. Clear the rolling coutner and checksum timers. */
		LKATqOvrDltCmdRCVldAccum_Cnt_M_u16 = DiagNStep_m(LKATqOvrDltCmdRCVldAccum_Cnt_M_u16, k_LKATqOvrDltCmdRCVldDiag_Cnt_str);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&LKATqOvrDltCmdRCVldStartTime_mS_M_u32);
		LKAFault_Cnt_M_b16 &= ~D_LKAFAULT_INVALIDRC180_CNT_B16;
	}
	else /* The rolling counter did not increment correctly. */
	{
		MessageValid_Cnt_T_lgc = FALSE;

		(void)DtrmnNTCTimeout(&LKATqOvrDltCmdRCVldStartTime_mS_M_u32, k_LKATqOvrDltCmdRCVldTimeOut_mS_u16p0,
						&LKATqOvrDltCmdRCVldAccum_Cnt_M_u16, k_LKATqOvrDltCmdRCVldDiag_Cnt_str,
						NTC_Num_InvalidMsg_AA,
						FALSE,
						0x01u);

		/* Set LKA Fault */
		LKAFault_Cnt_M_b16 |= D_LKAFAULT_INVALIDRC180_CNT_B16;
	}

	/* If the whole message is valid and all the accumulators are zero, clear the fault. */
	if ((TRUE == MessageValid_Cnt_T_lgc) &&
			(0u == LKATqOvrDltCmdRCVldAccum_Cnt_M_u16) &&
			(0u == LKATqOvrDltCmdPrtVlVldAccum_Cnt_M_u16))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AA, 0x00u, NTC_STATUS_PASSED);
	}

	/* Update the Rolling Counter */
	PrevLKARollingCounter_Cnt_M_u16 = RollingCounter_Cnt_T_u16;

	(void)NTCCheckClear(&Msg180HSLoss_mS_M_u32, &Msg180HSLossAccum_Cnt_M_u16, &k_Msg180HSTimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AA);
	Msg180HSLKALoss_mS_M_u32 = Msg180HSLoss_mS_M_u32;
	LKAFault_Cnt_M_b16 &= ~D_LKAFAULT_MISSING180_CNT_B16;
}

/* ID: 0x1E9, Periodic Rate: 20ms, Polled in runnable: SrlComInput_Per2*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxChassisGeneralStatus1_x1E9(CanReceiveHandle rcvObject)
{
	VAR(RT_Chassis_General_Status_1, AUTOMATIC) Data_T_str;

	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) SrlComYawRate_DegpSec_T_f32;
	VAR(float32, AUTOMATIC) SrlComLatAcc_MpSecSqrd_T_f32;

	VAR(boolean, AUTOMATIC) TCSysE_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) TCSysA_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) ABSFld_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC)   VhDynC_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) ABSysA_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) LKAInhibitFrom1E9_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) InvalidMsgNtcSet_Cnt_T_lgc;

	IlGetRxVSELatAccGroup();
	IlGetRxVehDynYawRateGroup();

	Data_T_str.VSELatAcc = IlGetRxVSELatAcc();
	Data_T_str.VSELatAccV = IlGetRxVSELatAccV();
	Data_T_str.VehDynYawRate = IlGetRxVehDynYawRate();
	Data_T_str.VehDynYawRateV = IlGetRxVehDynYawRateV();
	TCSysA_Cnt_T_lgc = IlGetRxTCSysAtv();
	VSEAct_Cnt_M_lgc = IlGetRxVSEAct_0();
	ABSysA_Cnt_T_lgc = IlGetRxABSAtv_0();

	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		if (D_VALID_CNT_U08 == Data_T_str.VSELatAccV)
		{
			if ((Data_T_str.VSELatAcc) > D_LATACCELYAWRATEMAXVAL_CNT_U16)
			{
				SrlComLatAcc_MpSecSqrd_T_f32 = ((float32)(((sint16)((Data_T_str.VSELatAcc) - (D_SIGNEDSIGNALOFFSET_CNT_U16)))) * D_VEHSTBLATACCELSF_MPSECSQRD_F32);
			}
			else
			{
				SrlComLatAcc_MpSecSqrd_T_f32 = (float32)Data_T_str.VSELatAcc * D_VEHSTBLATACCELSF_MPSECSQRD_F32;
			}
			SrlComLatAcc_MpSecSqrd_T_f32 = Limit_m(SrlComLatAcc_MpSecSqrd_T_f32, D_LATACCLOLMT_MPSECSQRD_F32, D_LATACCHILMT_MPSECSQRD_F32);
			(void)Rte_Write_SrlComLatAccel_MpSecSq_f32(SrlComLatAcc_MpSecSqrd_T_f32);
			(void)Rte_Write_SrlComLatAccelValid_Cnt_lgc(TRUE);

			LatAccVldAccum_Cnt_M_u16 = DiagNStep_m(LatAccVldAccum_Cnt_M_u16, k_LatAccValDiag_Cnt_str);
		}
		else
		{
			(void)Rte_Write_SrlComLatAccelValid_Cnt_lgc(FALSE);
			(void)DtrmnNTCTimeout(&LatAccVldStartTime_mS_M_u32, k_LatAccValTimeOut_mS_u16p0,
					&LatAccVldAccum_Cnt_M_u16, k_LatAccValDiag_Cnt_str,
					NTC_Num_InvalidMsg_W, (boolean)((Nvm_CMEC_Cnt_u8 != 0U) && (Nvm_CMEC_Cnt_u8 != 0xFFU)), 0x01u);
		}

		if (D_VALID_CNT_U08 == Data_T_str.VehDynYawRateV)
		{
			if ((Data_T_str.VehDynYawRate) > D_LATACCELYAWRATEMAXVAL_CNT_U16)
			{
				SrlComYawRate_DegpSec_T_f32 = ((float32)(((sint16)((Data_T_str.VehDynYawRate) - (D_SIGNEDSIGNALOFFSET_CNT_U16)))) * D_VEHDYNYAWRATESF_DEGPSEC_F32);
			}
			else
			{
				SrlComYawRate_DegpSec_T_f32 = (float32)Data_T_str.VehDynYawRate * D_VEHDYNYAWRATESF_DEGPSEC_F32;
			}
			SrlComYawRate_DegpSec_T_f32 = Limit_m(SrlComYawRate_DegpSec_T_f32, D_YAWRATELOLMT_DEGPSEC_F32, D_YAWRATEHILMT_DEGPSEC_F32);
			(void)Rte_Write_SrlComYawRate_DegpS_f32(SrlComYawRate_DegpSec_T_f32);
			(void)Rte_Write_SrlComYawRateValid_Cnt_lgc(TRUE);
			SrlComInput_Message1E9PresentAndValid_Cnt_M_lgc = TRUE;

			(void)NTCCheckClear(&YawRateVldStartTime_mS_M_u32, &YawRateVldAccum_Cnt_M_u16, &k_YawRateValDiag_Cnt_str, NTC_Num_InvalidMsg_Y);
		}
		else if (TRUE == DtrmnNTCTimeout(&YawRateVldStartTime_mS_M_u32, k_YawRateValTimeOut_mS_u16p0,
				                        &YawRateVldAccum_Cnt_M_u16, k_YawRateValDiag_Cnt_str,
				                        NTC_Num_InvalidMsg_Y,
				                        (boolean)((Nvm_CMEC_Cnt_u8 != 0U) && (Nvm_CMEC_Cnt_u8 != 0xFFU)),
				                        0x01u))
		{
			(void)Rte_Write_SrlComYawRate_DegpS_f32(k_YawRateDflt_DegpSec_f32);
			(void)Rte_Write_SrlComYawRateValid_Cnt_lgc(FALSE);
			SrlComInput_Message1E9PresentAndValid_Cnt_M_lgc = FALSE;
		}
		else
		{
			/* Message is invalid, but not for long enough to set the NTC. */
			(void)Rte_Write_SrlComYawRateValid_Cnt_lgc(FALSE);
		}

		/* If LKA is enabled. */
		if (TRUE == k_LKAMfgEnable_Cnt_lgc)
		{
			TCSysE_Cnt_T_lgc = IlGetRxTCSysEnbld();
			ABSFld_Cnt_T_lgc = IlGetRxABSFld();
			VhDynC_Cnt_T_u08 = IlGetRxVhDynCntlSysSt();

			/* Assume that this message will not inhibit LKA until proven otherwise. */
			LKAInhibitFrom1E9_Cnt_T_lgc = FALSE;

			/* Assume that this message is not invalid until proven otherwise. */
			InvalidMsgNtcSet_Cnt_T_lgc = FALSE;

			/* Determine if the redundant and original Vehicle Stability Enhancement system active signal match. */
			if (RedntVSEAct_Cnt_M_lgc != VSEAct_Cnt_M_lgc)
			{
				LKAInhibitFrom1E9_Cnt_T_lgc = TRUE;
				InvalidMsgNtcSet_Cnt_T_lgc = TRUE;

				/* Check if the NTC for the original signal should be set. */
				if (TRUE == DtrmnNTCTimeout(&VSEActVldStartTime_mS_M_u32p0, k_VSEActValTimeOut_mS_u16p0,
						   &VSEActVldAccum_Cnt_M_u16, k_VSEActValDiag_Cnt_str,
						   NTC_Num_InvalidMsg_W, D_FALSE_CNT_LGC, 0x01u))
				{
					LKAInhibit_Cnt_M_b16 |= D_LKAINHIBIT_INVALID1E9_CNT_B16;
				}
			}
			else if (TRUE == VSEAct_Cnt_M_lgc)
			{
				LKAInhibit_Cnt_M_b16 |= D_LKAINHIBIT_INVALID1E9_CNT_B16;
				LKAInhibitFrom1E9_Cnt_T_lgc = TRUE;

				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&VSEActVldStartTime_mS_M_u32p0);
				VSEActVldAccum_Cnt_M_u16 = DiagNStep_m(VSEActVldAccum_Cnt_M_u16, k_VSEActValDiag_Cnt_str);

			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&VSEActVldStartTime_mS_M_u32p0);
				VSEActVldAccum_Cnt_M_u16 = DiagNStep_m(VSEActVldAccum_Cnt_M_u16, k_VSEActValDiag_Cnt_str);
			}

			/* The next section repeats the same idea several times. Each signal is expected to be in a certain state for
			 * LKA to operate. If it is not in that state LKA is inhibited. If it remains out of that state for a period of
			 * time an NTC is set. */

			/* Traction Control System Enabled */
			if (FALSE == TCSysE_Cnt_T_lgc)
			{
				LKAInhibit_Cnt_M_b16 |= D_LKAINHIBIT_INVALID1E9_CNT_B16;
				LKAInhibitFrom1E9_Cnt_T_lgc = TRUE;
				InvalidMsgNtcSet_Cnt_T_lgc = TRUE;

				(void)DtrmnNTCTimeout(&TCSysEVldStartTime_mS_M_u32p0, k_TCSysEValTimeOut_mS_u16p0,
										   &TCSysEVldAccum_Cnt_M_u16, k_TCSysEValDiag_Cnt_str,
										   NTC_Num_InvalidMsg_W, D_FALSE_CNT_LGC, 0x08u);
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&TCSysEVldStartTime_mS_M_u32p0);
				TCSysEVldAccum_Cnt_M_u16 = DiagNStep_m(TCSysEVldAccum_Cnt_M_u16, k_TCSysEValDiag_Cnt_str);
			}

			/* Traction Control System Active */
			if (TRUE == TCSysA_Cnt_T_lgc)
			{
				LKAInhibit_Cnt_M_b16 |= D_LKAINHIBIT_INVALID1E9_CNT_B16;
				LKAInhibitFrom1E9_Cnt_T_lgc = TRUE;
			}

			/* Antilock Brake System Failed */
			if (TRUE == ABSFld_Cnt_T_lgc)
			{
				LKAInhibit_Cnt_M_b16 |= D_LKAINHIBIT_INVALID1E9_CNT_B16;
				LKAInhibitFrom1E9_Cnt_T_lgc = TRUE;
				InvalidMsgNtcSet_Cnt_T_lgc = TRUE;

				(void)DtrmnNTCTimeout(&ABSFldVldStartTime_mS_M_u32p0, k_ABSFldValTimeOut_mS_u16p0,
										   &ABSFldVldAccum_Cnt_M_u16, k_ABSFldValDiag_Cnt_str,
										   NTC_Num_InvalidMsg_W, D_FALSE_CNT_LGC, 0x10u);
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&ABSFldVldStartTime_mS_M_u32p0);
				ABSFldVldAccum_Cnt_M_u16 = DiagNStep_m(ABSFldVldAccum_Cnt_M_u16, k_ABSFldValDiag_Cnt_str);
			}

			/* Vehicle Dynamics Control System Status */
			if ((D_TEMPINHIBIT_CNT_U08 == VhDynC_Cnt_T_u08) ||
				(D_PERMANENTLYFAILED_CNT_U08 == VhDynC_Cnt_T_u08))
			{
				(void)DtrmnNTCTimeout(&VhDynCVldStartTime_mS_M_u32p0, k_VhDynCValTimeOut_mS_u16p0,
										   &VhDynCVldAccum_Cnt_M_u16, k_VhDynCValDiag_Cnt_str,
										   NTC_Num_InvalidMsg_W, D_FALSE_CNT_LGC, 0x02u);
			}
			else
			{
				(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&VhDynCVldStartTime_mS_M_u32p0);
				VhDynCVldAccum_Cnt_M_u16 = DiagNStep_m(VhDynCVldAccum_Cnt_M_u16, k_VhDynCValDiag_Cnt_str);
			}

			if (D_NORMALOPERATION_CNT_U08 != VhDynC_Cnt_T_u08)
			{
				LKAInhibit_Cnt_M_b16 |= D_LKAINHIBIT_INVALID1E9_CNT_B16;
				LKAInhibitFrom1E9_Cnt_T_lgc = TRUE;
				InvalidMsgNtcSet_Cnt_T_lgc = TRUE;
			}

			/* If no signal in this message is going to inhibit LKA, then pass the NTC. */
			if ((FALSE == LKAInhibitFrom1E9_Cnt_T_lgc) &&
			   (0u == VSEActVldAccum_Cnt_M_u16) &&
			   (0u == TCSysEVldAccum_Cnt_M_u16) &&
			   (0u == ABSFldVldAccum_Cnt_M_u16) &&
			   (0u == VhDynCVldAccum_Cnt_M_u16))
			{
				LKAInhibit_Cnt_M_b16 &= ~D_LKAINHIBIT_INVALID1E9_CNT_B16;
			}

			if ((FALSE == InvalidMsgNtcSet_Cnt_T_lgc) &&
			   (0u == VSEActVldAccum_Cnt_M_u16) &&
			   (0u == TCSysEVldAccum_Cnt_M_u16) &&
			   (0u == ABSFldVldAccum_Cnt_M_u16) &&
			   (0u == VhDynCVldAccum_Cnt_M_u16))
			{
				/* Also take non-LKA accumulator into account when passing NTC */
				if (LatAccVldAccum_Cnt_M_u16 == 0U)
				{
					(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_W, 0x00u, NTC_STATUS_PASSED);
				}
			}

			/* Clear a missing message fault for the LKA portion of this message. */
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Msg1E9LKALoss_mS_M_u32);
			LKAFault_Cnt_M_b16 &= ~D_LKAFAULT_MISSING1E9_CNT_B16;
		}
		else
		{
			/* When LKA is diabled, then only criteria for passing NTC 170 is that LatAccVldAccum_Cnt_M_u16 be zero */
			if (LatAccVldAccum_Cnt_M_u16 == 0U)
			{
				(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_W, 0x00u, NTC_STATUS_PASSED);
			}
		}

		(void)NTCCheckClear(&Msg1E9Loss_mS_M_u32, &Msg1E9LossAccum_Cnt_M_u16, &k_Msg1E9TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_W);

		(void)Rte_Write_SrlComABSActive_Cnt_lgc(ABSysA_Cnt_T_lgc);
		(void)Rte_Write_SrlComESCActive_Cnt_lgc(VSEAct_Cnt_M_lgc);
		(void)Rte_Write_SrlComTCSActive_Cnt_lgc(TCSysA_Cnt_T_lgc);
	}
}

/* ID: 0x1F1, Periodic Rate: 100ms, Polled in runnable: SrlComInput_Per3*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxPlatformGeneralStatus_x1F1(CanReceiveHandle rcvObject)
{
	VAR(RT_PPEI_Platform_General_Status, AUTOMATIC) Data_T_str;
	VAR(uint8, AUTOMATIC) PwrMode_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) SPMOn_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) PrevSrlComEngOn_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) SPMForCTCInhibit_Cnt_T_lgc;

	IlGetRxBkupPwrModeMstrGroup();

	Data_T_str.SysPwrMode = IlGetRxSysPwrMd();
	Data_T_str.SysBkupPwrMdEn = IlGetRxSysBkupPwrMdEn();
	Data_T_str.SysBkUpPwrMd = IlGetRxSysBkUpPwrMd();
	Data_T_str.BkupPwrModeMstrVDA = IlGetRxBkupPwrModeMstrVDA();

	(void)Rte_Read_PrevSrlComEngOn_Cnt_lgc(&PrevSrlComEngOn_Cnt_T_lgc);
	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		if (FALSE == Data_T_str.SysBkupPwrMdEn)
		{
			PwrMode_Cnt_T_u08 = Data_T_str.SysPwrMode;
		 	if (Run == Data_T_str.SysPwrMode)
		 	{
				SPMOn_Cnt_T_lgc = TRUE;
				SPMForCTCInhibit_Cnt_T_lgc = TRUE;
				SrlComInput_PrevRunMode_Cnt_M_lgc = TRUE;
			}
			else
			{
				SPMOn_Cnt_T_lgc = FALSE;
				SPMForCTCInhibit_Cnt_T_lgc = FALSE;
			}
		}
		else if (TRUE == Data_T_str.BkupPwrModeMstrVDA)
		{
			PwrMode_Cnt_T_u08 = Data_T_str.SysBkUpPwrMd;
			if (Run == Data_T_str.SysBkUpPwrMd)
		 	{
				SPMOn_Cnt_T_lgc = TRUE;
				SPMForCTCInhibit_Cnt_T_lgc = TRUE;
				SrlComInput_PrevRunMode_Cnt_M_lgc = TRUE;
			}
			else
			{
				SPMOn_Cnt_T_lgc = FALSE;
				SPMForCTCInhibit_Cnt_T_lgc = FALSE;
			}
		}
		else
		{
			if (FALSE == PrevSrlComEngOn_Cnt_T_lgc)
			{
				SPMOn_Cnt_T_lgc = FALSE;
				PwrMode_Cnt_T_u08 = Off;
			}
			else
			{
				SPMOn_Cnt_T_lgc = TRUE;
				PwrMode_Cnt_T_u08 = Run;
				SrlComInput_PrevRunMode_Cnt_M_lgc = TRUE;
			}

			SPMForCTCInhibit_Cnt_T_lgc = FALSE;
		}

		/* Decrement CMEC on falling edge of Run to Off */
		if ((SrlComInput_PrevRunMode_Cnt_M_lgc == TRUE) && (PwrMode_Cnt_T_u08 == Off))
		{
			SrlComInput_DecrementCMEC();
			SrlComInput_PrevRunMode_Cnt_M_lgc = FALSE;
		}

		Data_T_str.SysPwrMode = Limit_m(Data_T_str.SysPwrMode, D_SYSPWRMDMIN_CNT_U08, D_SYSPWRMDMAX_CNT_U08);
		(void)Rte_Write_SrlComSPMOn_Cnt_lgc(SPMOn_Cnt_T_lgc);
		(void)Rte_Write_SrlComSysPwrMd_Cnt_enum(Data_T_str.SysPwrMode);
		(void)Rte_Write_SPMForCTCInhibit_Cnt_lgc(SPMForCTCInhibit_Cnt_T_lgc);

		(void)NTCCheckClear(&Msg1F1Loss_mS_M_u32, &Msg1F1LossAccum_Cnt_M_u16, &k_Msg1F1TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_O);
	}
}

/* ID: 0x1F5, Periodic Rate: 25ms, Polled in runnable: SrlComInput_Per2*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxTransGeneralStatus2_x1F5(CanReceiveHandle rcvObject)
{
	VAR(uint8, AUTOMATIC) TrnsShftLvrPos_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) TrnsShftLvrPosV_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;

	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	/*IlGetRxTransEstGearGroup();*/ /* For unused signals in this messasge. */
	IlGetRxTrnsShftLvrPosGroup();

	TrnsShftLvrPos_Cnt_T_u08 = IlGetRxTrnsShftLvrPos();
	TrnsShftLvrPosV_Cnt_T_u08 = IlGetRxTrnsShftLvrPosV();

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		if (D_REVERSERANGE_CNT_U08 == TrnsShftLvrPos_Cnt_T_u08)
		{
			(void)Rte_Write_ShiftLeverIsInReverse_Cnt_lgc(TRUE);
		}
		else
		{
			(void)Rte_Write_ShiftLeverIsInReverse_Cnt_lgc(FALSE);
		}

		if (D_VALID_CNT_U08 == TrnsShftLvrPosV_Cnt_T_u08)
		{
			SrlComInput_APARecFlts1F5Invalid(FALSE);

			(void)NTCCheckClear(&TrnsShftLvrPosVldStartTime_mS_M_u32, &TrnsShftLvrPosVldAccum_Cnt_M_u16, &k_TrnsShftLvrPosVldDiag_Cnt_str, NTC_Num_InvalidMsg_P);
		}
		else
		{
			SrlComInput_APARecFlts1F5Invalid(TRUE);

			(void)DtrmnNTCTimeout(&TrnsShftLvrPosVldStartTime_mS_M_u32, k_TrnsShftLvrPosVldTimeOut_mS_u16p0,
						   &TrnsShftLvrPosVldAccum_Cnt_M_u16, k_TrnsShftLvrPosVldDiag_Cnt_str,
						   NTC_Num_InvalidMsg_P, D_FALSE_CNT_LGC, 0x01u);
		}

		(void)NTCCheckClear(&Msg1F5Loss_mS_M_u32, &Msg1F5LossAccum_Cnt_M_u16, &k_Msg1F5TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_P);
	}
}

/* ID: 0x214, Periodic Rate: 50ms, Polled in runnable: SrlComInput_Per2 */
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxBrakePedalDriverStatusHS_x214(CanReceiveHandle rcvObject)
{
	VAR(uint16, AUTOMATIC) ABSActvProtPVal_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) ABSActvProtARC_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) ABSActvProt_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) RedntVSEActARC_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) CalculatedABSActvProtPVal_Cnt_T_u16;
	VAR(boolean, AUTOMATIC)	MessageValid_Cnt_T_lgc;

	RedntVSEActARC_Cnt_T_u08 = IlGetRxRedntVSEActARC();		/* Redundant Vehicle Stability Enhancement System Active Alive Rolling Count */
	RedntVSEAct_Cnt_M_lgc = IlGetRxRedntVSEAct();			/* Redundant Vehicle Stability Enhancement System Active */
	ABSActvProtARC_Cnt_T_u08 = IlGetRxABSActvProtARC();		/* Antilock Brake System Active Protected Protection Value */
	ABSActvProtPVal_Cnt_T_u16 = IlGetRxABSActvProtPVal();	/* Antilock Brake System Active Protected Alive Rolling Count */
	ABSActvProt_Cnt_T_lgc = IlGetRxABSActvProt();			/* Antilock Brake System Active Protected */

	/* Assume the two signal groups are invalid until proven otherwise. */
	MessageValid_Cnt_T_lgc = TRUE;

	/* If there is a valid previous rolling counter value and it did not progress correctly, set LKA fault and check the NTC timer. */
	if ((D_INVALIDROLLINGCOUNT_CNT_U08 != RedntVSEActARC_Cnt_M_u08) &&
			(RedntVSEActARC_Cnt_T_u08 != ((RedntVSEActARC_Cnt_M_u08 + 1u) & 0x03u)))
	{
		LKAFault_Cnt_M_b16 |= D_LKAFAULT_VSEROLLCOUNT214_CNT_B16;
		MessageValid_Cnt_T_lgc = FALSE;

		(void)DtrmnNTCTimeout(&RedntVSEActARCVldStartTime_mS_M_u32, k_RedntVSEActARCVldTimeOut_mS_u16p0,
								   &RedntVSEActARCVldAccum_Cnt_M_u16, k_RedntVSEActARCVldDiag_Cnt_str,
								   NTC_Num_InvalidMsg_X, D_FALSE_CNT_LGC, 0x10u);
	}
	else /* The value of RedntVSEAct is not stuck. */
	{
		LKAFault_Cnt_M_b16 &= ~D_LKAFAULT_VSEROLLCOUNT214_CNT_B16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&RedntVSEActARCVldStartTime_mS_M_u32);
		RedntVSEActARCVldAccum_Cnt_M_u16 = DiagNStep_m(RedntVSEActARCVldAccum_Cnt_M_u16, k_RedntVSEActARCVldDiag_Cnt_str);
	}

	if (RedntVSEAct_Cnt_M_lgc != VSEAct_Cnt_M_lgc )
	{
		/* Check if the NTC for the redundant signal should be set. */
		MessageValid_Cnt_T_lgc = FALSE;

		if (TRUE == DtrmnNTCTimeout(&RedntVSEActVldStartTime_mS_M_u32, k_RedntVSEActVldTimeOut_mS_u16p0,
								   &RedntVSEActVldAccum_Cnt_M_u16, k_RedntVSEActVldDiag_Cnt_str,
								   NTC_Num_InvalidMsg_X, D_FALSE_CNT_LGC, 0x08u))
		{
			LKAInhibit_Cnt_M_b16 |= D_LKAINHIBIT_VSEACTIVE_CNT_B16;
		}
	}
	else
	{
		LKAInhibit_Cnt_M_b16 &= ~D_LKAINHIBIT_VSEACTIVE_CNT_B16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&RedntVSEActVldStartTime_mS_M_u32);
		RedntVSEActVldAccum_Cnt_M_u16 = DiagNStep_m(RedntVSEActVldAccum_Cnt_M_u16, k_RedntVSEActVldDiag_Cnt_str);
	}

	RedntVSEActARC_Cnt_M_u08 = RedntVSEActARC_Cnt_T_u08;

	/* Calculate the protection value (AKA checksum) for ABSActvProtPVal. */
	CalculatedABSActvProtPVal_Cnt_T_u16 = (uint16)ABSActvProt_Cnt_T_lgc + (uint16)ABSActvProtARC_Cnt_T_u08;
	CalculatedABSActvProtPVal_Cnt_T_u16 = ~CalculatedABSActvProtPVal_Cnt_T_u16;
	CalculatedABSActvProtPVal_Cnt_T_u16++;
	CalculatedABSActvProtPVal_Cnt_T_u16 &= 0x03u;

	/* If the checksum is invalid, set LKA Fault. */
	if (CalculatedABSActvProtPVal_Cnt_T_u16 != ABSActvProtPVal_Cnt_T_u16)
	{
		LKAFault_Cnt_M_b16 |= D_LKAFAULT_ABSINVALIDPV214_CNT_B16;
		MessageValid_Cnt_T_lgc = FALSE;
		(void)DtrmnNTCTimeout(&ABSActvProtPValVldStartTime_mS_M_u32, k_ABSActvProtPValVldTimeOut_mS_u16p0,
								   &ABSActvProtPValVldAccum_Cnt_M_u16, k_ABSActvProtPValVldDiag_Cnt_str,
								   NTC_Num_InvalidMsg_X, D_FALSE_CNT_LGC, 0x01u);
	}
	else
	{
		LKAFault_Cnt_M_b16 &= ~D_LKAFAULT_ABSINVALIDPV214_CNT_B16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&ABSActvProtPValVldStartTime_mS_M_u32);
		ABSActvProtPValVldAccum_Cnt_M_u16 = DiagNStep_m(ABSActvProtPValVldAccum_Cnt_M_u16, k_ABSActvProtPValVldDiag_Cnt_str);
	}

	/* If the rolling counter is stuck, set LKA Fault. */
	if ((D_INVALIDROLLINGCOUNT_CNT_U08 != ABSActvProtARC_Cnt_T_u08) &&
	    (ABSActvProtARC_Cnt_T_u08 != ((ABSActvProtARC_Cnt_M_u08 + 1u) & 0x03U)))
	{
		LKAFault_Cnt_M_b16 |= D_LKAFAULT_ABSINVALIDRC214_CNT_B16;
		MessageValid_Cnt_T_lgc = FALSE;
		(void)DtrmnNTCTimeout(&ABSActvProtARCVldStartTime_mS_M_u32, k_ABSActvProtARCVldTimeOut_mS_u16p0, &ABSActvProtARCVldAccum_Cnt_M_u16,
		                      k_ABSActvProtARCVldDiag_Cnt_str, NTC_Num_InvalidMsg_X, D_FALSE_CNT_LGC, 0x04U);
	}
	else /* Rolling counter is not stuck. Process the protected state. */
	{
		LKAFault_Cnt_M_b16 &= ~D_LKAFAULT_ABSINVALIDRC214_CNT_B16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&ABSActvProtARCVldStartTime_mS_M_u32);
		ABSActvProtARCVldAccum_Cnt_M_u16 = DiagNStep_m(ABSActvProtARCVldAccum_Cnt_M_u16, k_ABSActvProtARCVldDiag_Cnt_str);
	}

	/* If the ABS system is protected, set LKA inhibit. */
	if (TRUE == ABSActvProt_Cnt_T_lgc)
	{
		LKAInhibit_Cnt_M_b16 |= D_LKAINHIBIT_PROTECTED214_CNT_B16;
		MessageValid_Cnt_T_lgc = FALSE;

		(void)DtrmnNTCTimeout(&ABSActvProtVldStartTime_mS_M_u32, k_ABSActvProtARCVldTimeOut_mS_u16p0,
								   &ABSActvProtVldAccum_Cnt_M_u16, k_ABSActvProtVldDiag_Cnt_str,
								   NTC_Num_InvalidMsg_X, D_FALSE_CNT_LGC, 0x02u);
	}
	else /* The ABS system is not protected */
	{
		LKAInhibit_Cnt_M_b16 &= ~D_LKAINHIBIT_PROTECTED214_CNT_B16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&ABSActvProtVldStartTime_mS_M_u32);
		ABSActvProtVldAccum_Cnt_M_u16 = DiagNStep_m(ABSActvProtVldAccum_Cnt_M_u16, k_ABSActvProtVldDiag_Cnt_str);
	}
	ABSActvProtARC_Cnt_M_u08 = ABSActvProtARC_Cnt_T_u08;

	/* All validity criteria for this message are met, and all accumulators are zero. Set the NTC to passed. */
	if ((TRUE == MessageValid_Cnt_T_lgc) &&
			(0u == RedntVSEActARCVldAccum_Cnt_M_u16) &&
			(0u == RedntVSEActVldAccum_Cnt_M_u16) &&
			(0u == ABSActvProtPValVldAccum_Cnt_M_u16) &&
			(0u == ABSActvProtARCVldAccum_Cnt_M_u16) &&
			(0u == ABSActvProtVldAccum_Cnt_M_u16))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_X, 0x00u, NTC_STATUS_PASSED);
	}

	(void)NTCCheckClear(&Msg214Loss_mS_M_u32, &Msg214LossAccum_Cnt_M_u16, &k_Msg214TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_X);
	Msg214LKALoss_mS_M_u32 = Msg214Loss_mS_M_u32;
	LKAFault_Cnt_M_b16 &= ~D_LKAFAULT_MISSING214_CNT_B16;
}

/* ID: 0x232, Periodic Rate: 50ms, Polled in runnable: SrlComInput_Per2*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxDrivingModeControlHS_x232(CanReceiveHandle rcvObject)
{
	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) StgSysPerfMdRq_Cnt_T_u16;

	StgSysPerfMdRq_Cnt_T_u16 = IlGetRxStgSysPerfMdRq();
	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		if ((StgSysPerfMdRq_Cnt_T_u16 > 0U) && (StgSysPerfMdRq_Cnt_T_u16 <= D_MAXPERFMDRQ_CNT_U16))
		{
			/* The RTE variable that represents the personality starts with zero. That is why it is necessary
			 * to subtract one from the received value */
			(void)Rte_Write_DesiredTunPers_Cnt_u16((StgSysPerfMdRq_Cnt_T_u16-1U));
		}
		else
		{
			/* Keep existing selection. */
		}
		(void)NTCCheckClear(&Msg232Loss_mS_M_u32, &Msg232LossAccum_Cnt_M_u16, &k_Msg232TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_Q);
	}
}

/* ID: 0x348, Periodic Rate: 50ms, Polled in runnable: SrlComInput_Per2 */
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxDrivenWheelGrndVelocityHS_x348(CanReceiveHandle rcvObject)
{
	VAR(uint16, AUTOMATIC) WhlGrndVlctyLftDrvn_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WhlGrndVlctyRtDrvn_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) WhlGrndVlctyLftDrvnV_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) WhlGrndVlctyRtDrvnV_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(boolean, AUTOMATIC) LeftWheelValid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) RightWheelValid_Cnt_T_lgc;

	IlGetRxWhlGrndVlctyLftDrvnGroup_0();
	IlGetRxWhlGrndVlctyRtDrvnGroup_0();

	WhlGrndVlctyLftDrvn_Cnt_T_u16 = IlGetRxWhlGrndVlctyLftDrvn_0();
	WhlGrndVlctyRtDrvn_Cnt_T_u16 = IlGetRxWhlGrndVlctyRtDrvn_0();
	WhlGrndVlctyRtDrvnV_Cnt_T_u08 = IlGetRxWhlGrndVlctyRtDrvnV_0();
	WhlGrndVlctyLftDrvnV_Cnt_T_u08 = IlGetRxWhlGrndVlctyLftDrvnV_0();

	/* Assume both signals are invalid until proven otherwise. */
	LeftWheelValid_Cnt_T_lgc = FALSE;
	RightWheelValid_Cnt_T_lgc = FALSE;

	/*** Handle Right Driven Wheel Ground Velocity ***/
	/* Velocity is invalid, so don't update it. Also reset the stuck velocity timer to prevent overflows. */
	if (D_VALID_CNT_U08 != WhlGrndVlctyRtDrvnV_Cnt_T_u08)
	{
		WhlGrndVlctyRtDrvnHSValid_Cnt_M_lgc = FALSE;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtDrvnHSStuck_mS_M_u32);

		(void)DtrmnNTCTimeout(&WhlGrndVlctyRtDrvnHSVldStartTime_mS_M_u32, k_WhlGrndVlctyRtDrvnHSVldTimeOut_mS_u16p0,
		                      &WhlGrndVlctyRtDrvnHSVldAccum_Cnt_M_u16, k_WhlGrndVlctyRtDrvnHSValDiag_Cnt_str,
		                      NTC_Num_InvalidMsg_AB, D_FALSE_CNT_LGC, 0x02u);
	}
	/* If wheel velocity is stuck, and more than 5kph. */
	else if ((WhlGrndVlctyRtDrvn_Cnt_T_u16 == WhlGrndVlctyRtDrvnHS_Cnt_M_u16) &&
	         (WhlGrndVlctyRtDrvn_Cnt_T_u16 >= D_5KPH_CNT_U16))
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtDrvnHSVldStartTime_mS_M_u32);

		/* If wheel velocity has been stuck long enough, signal goes invalid. */
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(WhlGrndVlctyRtDrvnHSStuck_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_WhlGrndVlctyStuckTime_mS_u16)
		{
			WhlGrndVlctyRtDrvnHSValid_Cnt_M_lgc = FALSE;
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtDrvnHSStuck_mS_M_u32);
		}

		RightWheelValid_Cnt_T_lgc = TRUE;
	}
	else /* Velocity is valid, and not stuck. */
	{
		RightWheelValid_Cnt_T_lgc = TRUE;
		WhlGrndVlctyRtDrvnHSValid_Cnt_M_lgc = TRUE;
		WhlGrndVlctyRtDrvnHS_Cnt_M_u16 = WhlGrndVlctyRtDrvn_Cnt_T_u16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtDrvnHSStuck_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtDrvnHSVldStartTime_mS_M_u32);
		WhlGrndVlctyRtDrvnHSVldAccum_Cnt_M_u16 = DiagNStep_m(WhlGrndVlctyRtDrvnHSVldAccum_Cnt_M_u16, k_WhlGrndVlctyRtDrvnHSValDiag_Cnt_str);
	}

	/*** Handle Left Driven Wheel Ground Velocity ***/
	/* Velocity is invalid, so don't update it. Also reset the stuck velocity timer to prevent overflows. */
	if (D_VALID_CNT_U08 != WhlGrndVlctyLftDrvnV_Cnt_T_u08)
	{
		WhlGrndVlctyLftDrvnHSValid_Cnt_M_lgc = FALSE;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftDrvnHSStuck_mS_M_u32);

		(void)DtrmnNTCTimeout(&WhlGrndVlctyLftDrvnHSVldStartTime_mS_M_u32, k_WhlGrndVlctyLftDrvnHSVldTimeOut_mS_u16p0,
		                      &WhlGrndVlctyLftDrvnHSVldAccum_Cnt_M_u16, k_WhlGrndVlctyLftDrvnHSValDiag_Cnt_str,
		                      NTC_Num_InvalidMsg_AB, D_FALSE_CNT_LGC, 0x01u);
	}
	/* If wheel velocity is stuck, and more than 5kph. */
	else if ((WhlGrndVlctyLftDrvn_Cnt_T_u16 == WhlGrndVlctyLftDrvnHS_Cnt_M_u16) &&
	         (WhlGrndVlctyLftDrvn_Cnt_T_u16 >= D_5KPH_CNT_U16))
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftDrvnHSVldStartTime_mS_M_u32);

		/* If wheel velocity has been stuck long enough, signal goes invalid. */
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(WhlGrndVlctyLftDrvnHSStuck_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_WhlGrndVlctyStuckTime_mS_u16)
		{
			WhlGrndVlctyLftDrvnHSValid_Cnt_M_lgc = FALSE;
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftDrvnHSStuck_mS_M_u32);
		}

		LeftWheelValid_Cnt_T_lgc = TRUE;
	}
	else /* Velocity is valid, and not stuck. */
	{
		LeftWheelValid_Cnt_T_lgc = TRUE;
		WhlGrndVlctyLftDrvnHSValid_Cnt_M_lgc = TRUE;
		WhlGrndVlctyLftDrvnHS_Cnt_M_u16 = WhlGrndVlctyLftDrvn_Cnt_T_u16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftDrvnHSStuck_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftDrvnHSVldStartTime_mS_M_u32);
		WhlGrndVlctyLftDrvnHSVldAccum_Cnt_M_u16 = DiagNStep_m(WhlGrndVlctyLftDrvnHSVldAccum_Cnt_M_u16, k_WhlGrndVlctyLftDrvnHSValDiag_Cnt_str);
	}

	if ((TRUE == LeftWheelValid_Cnt_T_lgc) &&
	    (TRUE == RightWheelValid_Cnt_T_lgc) &&
	    (0U == WhlGrndVlctyRtDrvnHSVldAccum_Cnt_M_u16) &&
	    (0U == WhlGrndVlctyLftDrvnHSVldAccum_Cnt_M_u16))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AB, 0x00u, NTC_STATUS_PASSED);
	}

	(void)NTCCheckClear(&Msg348HSLoss_mS_M_u32, &Msg348HSLossAccum_Cnt_M_u16, &k_Msg348HSTimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AB);
	Msg348HSLKALoss_mS_M_u32 = Msg348HSLoss_mS_M_u32;
	WhlGrndVlctyDrvnHSMissing_Cnt_M_lgc = FALSE;

	/* Update RTE outputs */
	(void)Rte_Write_SrlComWhlGrndVlctyRtDrvnHS_Kph_f32((float32)WhlGrndVlctyRtDrvn_Cnt_T_u16 * D_SECVEHSPDSF_KPH_F32);
	(void)Rte_Write_SrlComWhlGrndVlctyRtDrvnVldHS_Cnt_lgc(((WhlGrndVlctyRtDrvnV_Cnt_T_u08 == D_VALID_CNT_U08)? TRUE : FALSE));
	(void)Rte_Write_SrlComWhlGrndVlctyLftDrvnHS_Kph_f32((float32)WhlGrndVlctyLftDrvn_Cnt_T_u16 * D_SECVEHSPDSF_KPH_F32);
	(void)Rte_Write_SrlComWhlGrndVlctyLftDrvnVldHS_Cnt_lgc(((WhlGrndVlctyLftDrvnV_Cnt_T_u08 == D_VALID_CNT_U08)? TRUE : FALSE));
}

/* ID: 0x34A, Periodic Rate: 50ms, Polled in runnable: SrlComInput_Per2 */
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxNonDrivenWheelGrndVelocityHS_x34A(CanReceiveHandle rcvObject)
{
	VAR(uint16, AUTOMATIC) WhlGrndVlctyLftNnDrvn_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WhlGrndVlctyRtNnDrvn_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) WhlGrndVlctyLftNnDrvnV_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) WhlGrndVlctyRtNnDrvnV_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(boolean, AUTOMATIC) LeftWheelValid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) RightWheelValid_Cnt_T_lgc;

	IlGetRxWhlGrndVlctyLftNnDrvnGroup_0();
	IlGetRxWhlGrndVlctyRtNnDrvnGroup_0();

	WhlGrndVlctyLftNnDrvn_Cnt_T_u16 = IlGetRxWhlGrndVlctyLftNnDrvn_0();
	WhlGrndVlctyRtNnDrvn_Cnt_T_u16 = IlGetRxWhlGrndVlctyRtNnDrvn_0();
	WhlGrndVlctyRtNnDrvnV_Cnt_T_u08 = IlGetRxWhlGrndVlctyRtNnDrvnV_0();
	WhlGrndVlctyLftNnDrvnV_Cnt_T_u08 = IlGetRxWhlGrndVlctyLftNnDrvnV_0();

	/* Assume both signals are invalid until proven otherwise. */
	LeftWheelValid_Cnt_T_lgc = FALSE;
	RightWheelValid_Cnt_T_lgc = FALSE;

	/*** Handle Right Non-Driven Wheel Ground Velocity ***/
	/* Velocity is invalid, so don't update it. Also reset the stuck velocity timer to prevent overflows. */
	if (D_VALID_CNT_U08 != WhlGrndVlctyRtNnDrvnV_Cnt_T_u08)
	{
		WhlGrndVlctyRtNnDrvnHSValid_Cnt_M_lgc = FALSE;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtNnDrvnHSStuck_mS_M_u32);

		(void)DtrmnNTCTimeout(&WhlGrndVlctyRtNnDrvnHSVldStartTime_mS_M_u32, k_WhlGrndVlctyRtNnDrvnHSVldTimeOut_mS_u16p0,
		                      &WhlGrndVlctyRtNnDrvnHSVldAccum_Cnt_M_u16, k_WhlGrndVlctyRtNnDrvnHSValDiag_Cnt_str,
		                      NTC_Num_InvalidMsg_AC, D_FALSE_CNT_LGC, 0x02u);
	}
	/* If wheel velocity is stuck, and more than 5kph. */
	else if ((WhlGrndVlctyRtNnDrvn_Cnt_T_u16 == WhlGrndVlctyRtNnDrvnHS_Cnt_M_u16) &&
	         (WhlGrndVlctyRtNnDrvn_Cnt_T_u16 >= D_5KPH_CNT_U16))
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtNnDrvnHSVldStartTime_mS_M_u32);

		/* If wheel velocity has been stuck long enough, signal goes invalid. */
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(WhlGrndVlctyRtNnDrvnHSStuck_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_WhlGrndVlctyStuckTime_mS_u16)
		{
			WhlGrndVlctyRtNnDrvnHSValid_Cnt_M_lgc = FALSE;
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtNnDrvnHSStuck_mS_M_u32);
		}

		RightWheelValid_Cnt_T_lgc = TRUE;
	}
	else /* Velocity is valid, and not stuck. */
	{
		RightWheelValid_Cnt_T_lgc = TRUE;
		WhlGrndVlctyRtNnDrvnHSValid_Cnt_M_lgc = TRUE;
		WhlGrndVlctyRtNnDrvnHS_Cnt_M_u16 = WhlGrndVlctyRtNnDrvn_Cnt_T_u16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtNnDrvnHSStuck_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtNnDrvnHSVldStartTime_mS_M_u32);
		WhlGrndVlctyRtNnDrvnHSVldAccum_Cnt_M_u16 = DiagNStep_m(WhlGrndVlctyRtNnDrvnHSVldAccum_Cnt_M_u16, k_WhlGrndVlctyRtNnDrvnHSValDiag_Cnt_str);
	}

	/*** Handle Left Non-Driven Wheel Ground Velocity ***/
	/* Velocity is invalid, so don't update it. Also reset the stuck velocity timer to prevent overflows. */
	if (D_VALID_CNT_U08 != WhlGrndVlctyLftNnDrvnV_Cnt_T_u08)
	{
		WhlGrndVlctyLftNnDrvnHSValid_Cnt_M_lgc = FALSE;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftNnDrvnHSStuck_mS_M_u32);

		(void)DtrmnNTCTimeout(&WhlGrndVlctyLftNnDrvnHSVldStartTime_mS_M_u32, k_WhlGrndVlctyLftNnDrvnHSVldTimeOut_mS_u16p0,
		                      &WhlGrndVlctyLftNnDrvnHSVldAccum_Cnt_M_u16, k_WhlGrndVlctyLftNnDrvnHSValDiag_Cnt_str,
		                      NTC_Num_InvalidMsg_AC, D_FALSE_CNT_LGC, 0x01u);
	}
	/* If wheel velocity is stuck, and more than 5kph. */
	else if ((WhlGrndVlctyLftNnDrvn_Cnt_T_u16 == WhlGrndVlctyLftNnDrvnHS_Cnt_M_u16) &&
	         (WhlGrndVlctyLftNnDrvn_Cnt_T_u16 >= D_5KPH_CNT_U16))
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftNnDrvnHSVldStartTime_mS_M_u32);

		/* If wheel velocity has been stuck long enough, signal goes invalid. */
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(WhlGrndVlctyLftNnDrvnHSStuck_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_WhlGrndVlctyStuckTime_mS_u16)
		{
			WhlGrndVlctyLftNnDrvnHSValid_Cnt_M_lgc = FALSE;
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftNnDrvnHSStuck_mS_M_u32);
		}

		LeftWheelValid_Cnt_T_lgc = TRUE;
	}
	else /* Velocity is valid, and not stuck. */
	{
		LeftWheelValid_Cnt_T_lgc = TRUE;
		WhlGrndVlctyLftNnDrvnHSValid_Cnt_M_lgc = TRUE;
		WhlGrndVlctyLftNnDrvnHS_Cnt_M_u16 = WhlGrndVlctyLftNnDrvn_Cnt_T_u16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftNnDrvnHSStuck_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftNnDrvnHSVldStartTime_mS_M_u32);
		WhlGrndVlctyLftNnDrvnHSVldAccum_Cnt_M_u16 = DiagNStep_m(WhlGrndVlctyLftNnDrvnHSVldAccum_Cnt_M_u16, k_WhlGrndVlctyLftNnDrvnHSValDiag_Cnt_str);
	}

	if ((TRUE == LeftWheelValid_Cnt_T_lgc) &&
	    (TRUE == RightWheelValid_Cnt_T_lgc) &&
	    (0U == WhlGrndVlctyRtNnDrvnHSVldAccum_Cnt_M_u16) &&
	    (0U == WhlGrndVlctyLftNnDrvnHSVldAccum_Cnt_M_u16))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AC, 0x00u, NTC_STATUS_PASSED);
	}

	(void)NTCCheckClear(&Msg34AHSLoss_mS_M_u32, &Msg34AHSLossAccum_Cnt_M_u16, &k_Msg34AHSTimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AC);
	Msg34AHSLKALoss_mS_M_u32 = Msg34AHSLoss_mS_M_u32;
	WhlGrndVlctyNnDrvnHSMissing_Cnt_M_lgc = FALSE;

	/* Update RTE outputs */
	(void)Rte_Write_SrlComWhlGrndVlctyRtNnDrvnHS_Kph_f32((float32)WhlGrndVlctyRtNnDrvn_Cnt_T_u16 * D_SECVEHSPDSF_KPH_F32);
	(void)Rte_Write_SrlComWhlGrndVlctyRtNnDrvnVldHS_Cnt_lgc(((WhlGrndVlctyRtNnDrvnV_Cnt_T_u08 == D_VALID_CNT_U08)? TRUE : FALSE));
	(void)Rte_Write_SrlComWhlGrndVlctyLftNnDrvnHS_Kph_f32((float32)WhlGrndVlctyLftNnDrvn_Cnt_T_u16 * D_SECVEHSPDSF_KPH_F32);
	(void)Rte_Write_SrlComWhlGrndVlctyLftNnDrvnVldHS_Cnt_lgc(((WhlGrndVlctyLftNnDrvnV_Cnt_T_u08 == D_VALID_CNT_U08)? TRUE : FALSE));
}

/* ID: 0x3E9, Periodic Rate: 100ms, Polled in runnable: SrlComInput_Per3*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxVehicleSpeedAndDistance_x3E9(CanReceiveHandle rcvObject)
{
	VAR(RT_PPEI_Vehicle_Speed_and_Distance, AUTOMATIC) Data_T_str;
	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;

	IlGetRxVehSpdAvgNDrvnGroup();

	Data_T_str.VehSpdAvgNonDrvnGroup.VehSpdAvgNDrvn = IlGetRxVehSpdAvgNDrvn();
	Data_T_str.VehSpdAvgNonDrvnGroup.VehSpdAvgNDrvnV = IlGetRxVehSpdAvgNDrvnV();

	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		if (D_VALID_CNT_U08 == Data_T_str.VehSpdAvgNonDrvnGroup.VehSpdAvgNDrvnV)
		{
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&VehSpdVldStartTime_mS_M_u32);
			(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_R, 0x01u, NTC_STATUS_PASSED);

			VehSpdAvgNDrvnInValid_Cnt_M_lgc = FALSE;
		}
		else
		{
			VehSpdAvgNDrvnInValid_Cnt_M_lgc = TRUE;

			(void)DtrmnNTCTimeout(&VehSpdVldStartTime_mS_M_u32, k_VehSpdValTimeOut_mS_u16p0,
					&VehSpdVldAccum_Cnt_M_u16, k_VehSpdValDiag_Cnt_Str,
					NTC_Num_InvalidMsg_R, D_FALSE_CNT_LGC, 0x01u);

		}

		VehSpdAvgNDrvn_Kph_M_f32 = ((float32)Data_T_str.VehSpdAvgNonDrvnGroup.VehSpdAvgNDrvn) * D_VEHSPDAVGNDRVNSF_KPH_F32;
		(void)NTCCheckClear(&Msg3E9Loss_mS_M_u32, &Msg3E9LossAccum_Cnt_M_u16, &k_Msg3E9TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_R);
	}
}

/* ID: 0x3F1, Periodic Rate: 250ms, Polled in runnable: SrlComInput_Per3*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxPlatformEngCntrlRequests_x3F1(CanReceiveHandle rcvObject)
{
	VAR(RT_Platform_Eng_Cntrl_Requests, AUTOMATIC) Data_T_str;

	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) SrlComAmbTemp_DegC_T_f32;

	IlGetRxOtsAirTmpCrValGroup();

	Data_T_str.OtsAirTmpCrVal = IlGetRxOtsAirTmpCrVal();
	Data_T_str.OtsAirTmpCrValV = IlGetRxOtsAirTmpCrValV();
	Data_T_str.OtsAirTmpCrValMsk = IlGetRxOtsAirTmpCrValMsk();

	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		/* TODO: Make common signal scaling function */
		if ((D_VALID_CNT_U08 == Data_T_str.OtsAirTmpCrValV) && (D_USEDATA_CNT_U08 == Data_T_str.OtsAirTmpCrValMsk))
		{
			SrlComAmbTemp_DegC_T_f32 = ((float32)Data_T_str.OtsAirTmpCrVal * D_OUTAIRTEMPCORRVALSF_DEGC_F32) - D_OUTAIRTEMPCORRVALOFFSET_DEGC_F32;
			SrlComAmbTemp_DegC_T_f32 = Limit_m(SrlComAmbTemp_DegC_T_f32, D_AMBTEMPLOLMT_DEGC_F32, D_AMBTEMPHILMT_DEGC_F32);
			(void)Rte_Write_SrlComAmbTemp_DegC_f32(SrlComAmbTemp_DegC_T_f32);

			(void)NTCCheckClear(&AmbTempVldStartTime_mS_M_u32, &AmbTempVldAccum_Cnt_M_u16, &k_AmbTempValDiag_Cnt_str, NTC_Num_InvalidMsg_V);
		}
		else
		{
			if (TRUE == DtrmnNTCTimeout(&AmbTempVldStartTime_mS_M_u32, k_AmbTempValTimeOut_mS_u16p0,
					&AmbTempVldAccum_Cnt_M_u16, k_AmbTempValDiag_Cnt_str,
					NTC_Num_InvalidMsg_V, FALSE, 0x01u))
			{
				(void)Rte_Write_SrlComAmbTemp_DegC_f32(k_AmbTempDflt_DegC_f32);
			}
		}

		(void)NTCCheckClear(&Msg3F1Loss_mS_M_u32, &Msg3F1LossAccum_Cnt_M_u16, &k_Msg3F1LossTimeOutDiag_Cnt_str, NTC_Num_MissingMsg_V);
	}
}

/* ID: 0x4C1, Periodic Rate: 500ms, Polled in runnable: SrlComInput_Per3*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxEngineGeneralStatus4_x4C1(CanReceiveHandle rcvObject)
{
	VAR(RT_Engine_General_Status_4, AUTOMATIC) Data_T_str;

	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;
	VAR(float32, AUTOMATIC) SrlComEngTemp_DegC_T_f32;

	IlGetRxEngCltTmpGroup();

	Data_T_str.EngCltTmp = IlGetRxEngCltTmp();
	Data_T_str.EngCltTmpV = IlGetRxEngCltTmpV();

	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		/* TODO: Make common signal scaling function */
		if (D_VALID_CNT_U08 == Data_T_str.EngCltTmpV)
		{
			SrlComEngTemp_DegC_T_f32 = (float32)Data_T_str.EngCltTmp - D_ENGCLTTEMPOFFSET_DEGC_F32;
			SrlComEngTemp_DegC_T_f32 = Limit_m(SrlComEngTemp_DegC_T_f32, D_ENGTEMPLOLMT_DEGC_F32, D_ENGTEMPHILMT_DEGC_F32);
			(void)Rte_Write_SrlComEngTemp_DegC_f32(SrlComEngTemp_DegC_T_f32);

			(void)NTCCheckClear(&EngTempVldStartTime_mS_M_u32, &EngTempVldAccum_Cnt_M_u16, &k_EngTempValDiag_Cnt_str, NTC_Num_InvalidMsg_U);
		}
		else
		{
			if (TRUE == DtrmnNTCTimeout(&EngTempVldStartTime_mS_M_u32, k_EngTempValTimeOut_mS_u16p0,
					&EngTempVldAccum_Cnt_M_u16, k_EngTempValDiag_Cnt_str,
					NTC_Num_InvalidMsg_U, D_FALSE_CNT_LGC, 0x01u))
			{
				(void)Rte_Write_SrlComEngTemp_DegC_f32(k_EngTempDflt_DegC_f32);
			}
		}

		(void)NTCCheckClear(&Msg4C1Loss_mS_M_u32, &Msg4C1LossAccum_Cnt_M_u16, &k_Msg4C1LossTimeOutDiag_Cnt_str, NTC_Num_MissingMsg_U);
	}
}

/* ID: 0x500, Periodic Rate: 1000ms, Polled in runnable: SrlComInput_Per3*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxWheelPulsesHS_x500(CanReceiveHandle rcvObject)
{
	VAR(RT_Wheel_Pulses_HS, AUTOMATIC) Data_T_str;
	VAR(float32, AUTOMATIC) PulseScale_RevpCnt_T_f32;
	VAR(float32, AUTOMATIC) WhlTstmpRes_SecpCnt_T_f32;
	VAR(boolean, AUOTMATIC) WIREnabled_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;

	Data_T_str.WhlRotStatTmstmpRes = IlGetRxWhlRotStatTmstmpRes();
	Data_T_str.WhlPlsPerRevNonDrvn = IlGetRxWhlPlsPerRevNonDrvn_0();

	(void)Rte_Read_WIREnabled_Cnt_lgc(&WIREnabled_Cnt_T_lgc);
	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		if (TRUE == WIREnabled_Cnt_T_lgc)
		{
			/* Process Data */
			if ((0u != Data_T_str.WhlPlsPerRevNonDrvn) && (0u != Data_T_str.WhlRotStatTmstmpRes))
			{
				PulseScale_RevpCnt_T_f32 = D_ONE_ULS_F32/(float32)Data_T_str.WhlPlsPerRevNonDrvn;
				WhlTstmpRes_SecpCnt_T_f32 = (((float32)Data_T_str.WhlRotStatTmstmpRes) * D_2MS_SEC_F32 * D_1MICROSEC_SEC_F32);

				PulseScale_RevpCnt_M_f32 = PulseScale_RevpCnt_T_f32;
				WhlTstmpRes_SecpCnt_M_f32 = WhlTstmpRes_SecpCnt_T_f32;
			}
		}

		(void)NTCCheckClear(&Msg500Loss_mS_M_u32, &Msg500LossAccum_Cnt_M_u16, &k_Msg500TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_S);
	}
}

/* **********************************************************************************************************************
 * ******************************** Messages Received by the PSCM *******************************************************
 * ********************************     Chassis Expansion Bus     *******************************************************
 * **********************************************************************************************************************
 */
/* ID: 0x182, Periodic Rate: 100ms, Polled in runnable: SrlComInput_Per3*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxVehicleDynamicsESCHybCE_x182(CanReceiveHandle rcvObject)
{
	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) VSELongAccLoResV_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) VehDynOvrUndrStrV_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) VSELongAccLoRes_Cnt_T_u16;
	VAR(float32, AUTOMATIC) VSELongAccLoRes_MpSecSqrd_T_f32;

	IlGetRxVSELongAccLoResGroup();
	IlGetRxVehDynOvrUndrStrGroup_1();

	VSELongAccLoResV_Cnt_T_u08 = IlGetRxVSELongAccLoResV();
	VSELongAccLoRes_Cnt_T_u16 = IlGetRxVSELongAccLoRes();
	VehDynOvrUndrStrV_Cnt_T_u08 = IlGetRxVehDynOvrUndrStrV_1();
	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		if ((D_VALID_CNT_U08 == VSELongAccLoResV_Cnt_T_u08) && (D_VALID_CNT_U08 == VehDynOvrUndrStrV_Cnt_T_u08))
		{
			(void)NTCCheckClear(&VehicleDynamicsESCHybCEVldStartTime_mS_M_u32, &VehicleDynamicsESCHybCEVldAccum_Cnt_M_u16,
					&k_VehicleDynamicsESCHybCEValDiag_Cnt_str, NTC_Num_InvalidMsg_AH);
		}
		else
		{
			(void)DtrmnNTCTimeout(&VehicleDynamicsESCHybCEVldStartTime_mS_M_u32, k_VehicleDynamicsESCHybCEValTimeOut_mS_u16p0,
					&VehicleDynamicsESCHybCEVldAccum_Cnt_M_u16, k_VehicleDynamicsESCHybCEValDiag_Cnt_str,
					NTC_Num_InvalidMsg_AH, FALSE, 0x01u);
		}

		/* Specifically look at the Longitudinal Acceleration signal now */
		if (D_VALID_CNT_U08 == VSELongAccLoResV_Cnt_T_u08)
		{
			/* Signed signal, handle negative numbers by subtracting the maximum value */
			if (VSELongAccLoRes_Cnt_T_u16 > D_LONACCELMAXVAL_CNT_U16)
			{
				VSELongAccLoRes_Cnt_T_u16 = VSELongAccLoRes_Cnt_T_u16 - D_LONACCELSIGNEDOFFSET_CNT_U16;
			}
			VSELongAccLoRes_MpSecSqrd_T_f32 = (float32)((sint16)VSELongAccLoRes_Cnt_T_u16) * D_LONACCELSF_MPSECSQRD_F32;
			(void)Rte_Write_SrlComVehicleLonAccel_MpSecSq_f32(VSELongAccLoRes_MpSecSqrd_T_f32);
			(void)Rte_Write_SrlComVehLonAccelValid_Cnt_lgc(TRUE);
		}
		else
		{
			(void)Rte_Write_SrlComVehLonAccelValid_Cnt_lgc(FALSE);
		}

		(void)NTCCheckClear(&Msg182Loss_mS_M_u32, &Msg182LossAccum_Cnt_M_u16, &k_Msg182TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AH);
	}
}

/* ID: 0x337, Periodic Rate: 20ms, Polled in runnable: SrlComInput_Per2*/
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxParkAssistParallelCE_x337(CanReceiveHandle rcvObject)
{
	VAR(boolean, AUTOMATIC) RxMsgSrlComSvcDft_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) SWARReqActV_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) StrWhlTctlFdbkReqActRC_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) StrWhlTctlFdbkReqAct_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) StrWhlTctlFdbkReqActProtVal_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) CalculatedStrWhlTctlFdbkReqActProtVal_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) SWARReqAct_Cnt_T_lgc;
	VAR(sint16, AUTOMATIC) SWARTrgtAng_Cnt_T_s16;
	VAR(float32, AUTOMATIC) SWARTrgtAng_HwDeg_T_f32;
	VAR(uint8, AUTOMATIC) StrWhlAngReqARC_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) StrWhlAngReqPrtVal_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) CalculatedStrWhlAngReqPrtVal_Cnt_T_u32;

	IlGetRxStrWhlAngReq();

	StrWhlTctlFdbkReqActRC_Cnt_T_u08 = IlGetRxStrWhlTctlFdbkReqActRC();
	StrWhlTctlFdbkReqAct_Cnt_T_lgc = IlGetRxStrWhlTctlFdbkReqAct();
	StrWhlTctlFdbkReqActProtVal_Cnt_T_u08 = IlGetRxStrWhlTctlFdbkReqActProtVal();
	SWARReqActV_Cnt_T_u08 = IlGetRxSWAR_ReqActV();
	SWARReqAct_Cnt_T_lgc = IlGetRxSWAR_ReqAct();
	SWARTrgtAng_Cnt_T_s16 = (sint16)IlGetRxSWAR_TrgtAng();
	StrWhlAngReqARC_Cnt_T_u08 = IlGetRxStrWhlAngReqARC();
	StrWhlAngReqPrtVal_Cnt_T_u32 = IlGetRxStrWhlAngReqPrtVal();

	(void)Rte_Read_RxMsgsSrlComSvcDft_Cnt_lgc(&RxMsgSrlComSvcDft_Cnt_T_lgc);

	if (RxMsgSrlComSvcDft_Cnt_T_lgc == FALSE)
	{
		SWARTrgtAng_HwDeg_T_f32 = (float32)SWARTrgtAng_Cnt_T_s16 * D_SWARTRGTANGSF_DEG_F32;
		SWARTrgtAng_HwDeg_T_f32 = Limit_m(SWARTrgtAng_HwDeg_T_f32, D_SWARTRGTANGLOLMT_DEG_F32, D_SWARTRGTANGHILMT_DEG_F32);
		SWARTrgtAng_HwDeg_T_f32 *= D_SWARTRGTANGPOLARITY_ULS_F32;

		(void)Rte_Write_SWARTrgtAngRequest_HwDeg_f32(SWARTrgtAng_HwDeg_T_f32);
		(void)Rte_Write_APARequest_Cnt_lgc(SWARReqAct_Cnt_T_lgc);
		(void)Rte_Write_HapticRequest_Cnt_lgc(StrWhlTctlFdbkReqAct_Cnt_T_lgc);

		CalculatedStrWhlTctlFdbkReqActProtVal_Cnt_T_u08 = ((uint8)~((uint8)StrWhlTctlFdbkReqAct_Cnt_T_lgc + StrWhlTctlFdbkReqActRC_Cnt_T_u08)) + 1u;
		CalculatedStrWhlTctlFdbkReqActProtVal_Cnt_T_u08 &= 0x03u;

		CalculatedStrWhlAngReqPrtVal_Cnt_T_u32 = ((uint32)SWARReqAct_Cnt_T_lgc << 17);
		CalculatedStrWhlAngReqPrtVal_Cnt_T_u32 |= ((uint32)SWARReqActV_Cnt_T_u08 << 16);
		CalculatedStrWhlAngReqPrtVal_Cnt_T_u32 |= ((uint32)SWARTrgtAng_Cnt_T_s16) & 0x0000FFFFU;
		CalculatedStrWhlAngReqPrtVal_Cnt_T_u32 += (uint32)StrWhlAngReqARC_Cnt_T_u08;
		CalculatedStrWhlAngReqPrtVal_Cnt_T_u32 = (~CalculatedStrWhlAngReqPrtVal_Cnt_T_u32) + 1u;
		CalculatedStrWhlAngReqPrtVal_Cnt_T_u32 &= 0x03FFFFu;

		/* Check for faults */
		if ((PrevStrWhlTctlFdbkReqActRC_Cnt_M_u08 == StrWhlTctlFdbkReqActRC_Cnt_T_u08) ||
		    (CalculatedStrWhlTctlFdbkReqActProtVal_Cnt_T_u08 != StrWhlTctlFdbkReqActProtVal_Cnt_T_u08) ||
		    (D_VALID_CNT_U08 != SWARReqActV_Cnt_T_u08) ||
		    (PrevStrWhlAngReqARC_Cnt_M_u08 == StrWhlAngReqARC_Cnt_T_u08) ||
		    (CalculatedStrWhlAngReqPrtVal_Cnt_T_u32 != StrWhlAngReqPrtVal_Cnt_T_u32))
		{
			SrlComInput_APARecFlts337Invalid(TRUE);
			SrlComInput_APANonRecFlts337Invalid(TRUE);

			/* Set invalid message */
			(void)DtrmnNTCTimeout(&ParkAssistParallelCEVldStartTime_mS_M_u32, k_ParkAssistParallelValTimeOut_mS_u16p0,
			                      &ParkAssistParallelCEVldAccum_Cnt_M_u16, k_ParkAssistParallelValDiag_Cnt_str,
			                      NTC_Num_InvalidMsg_ParkAssistParallel, FALSE, 0x01u);
		}
		else
		{
			SrlComInput_APARecFlts337Invalid(FALSE);
			SrlComInput_APANonRecFlts337Invalid(FALSE);

			/* Clean invalid message */
			(void)NTCCheckClear(&ParkAssistParallelCEVldStartTime_mS_M_u32, &ParkAssistParallelCEVldAccum_Cnt_M_u16,
			                    &k_ParkAssistParallelValDiag_Cnt_str, NTC_Num_InvalidMsg_ParkAssistParallel);
		}
		PrevStrWhlTctlFdbkReqActRC_Cnt_M_u08 = StrWhlTctlFdbkReqActRC_Cnt_T_u08;
		PrevStrWhlAngReqARC_Cnt_M_u08 = StrWhlAngReqARC_Cnt_T_u08;

		(void)NTCCheckClear(&Msg337Loss_mS_M_u32, &Msg337LossAccum_Cnt_M_u16, &k_Msg337TimeOutDiag_Cnt_str, NTC_Num_MissingMsg_ParkAssistParallel);
		SrlComInput_APARecFlts337Present();
		SrlComInput_APANonRecFlts337Present();
	}
}

/* ID: 0x348, Periodic Rate: 50ms, Polled in runnable: SrlComInput_Per2 */
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxDrivenWheelGrndVelocityCE_x348(CanReceiveHandle rcvObject)
{
	VAR(uint16, AUTOMATIC) WhlGrndVlctyLftDrvn_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WhlGrndVlctyRtDrvn_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) WhlGrndVlctyLftDrvnV_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) WhlGrndVlctyRtDrvnV_Cnt_T_u08;
	VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16;
	VAR(boolean, AUTOMATIC) LeftWheelValid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) RightWheelValid_Cnt_T_lgc;

	IlGetRxWhlGrndVlctyLftDrvnGroup_1();
	IlGetRxWhlGrndVlctyRtDrvnGroup_1();

	WhlGrndVlctyLftDrvn_Cnt_T_u16 = IlGetRxWhlGrndVlctyLftDrvn_1();
	WhlGrndVlctyRtDrvn_Cnt_T_u16 = IlGetRxWhlGrndVlctyRtDrvn_1();
	WhlGrndVlctyRtDrvnV_Cnt_T_u08 = IlGetRxWhlGrndVlctyRtDrvnV_1();
	WhlGrndVlctyLftDrvnV_Cnt_T_u08 = IlGetRxWhlGrndVlctyLftDrvnV_1();

	/* Assume both signals are invalid until proven otherwise. */
	LeftWheelValid_Cnt_T_lgc = FALSE;
	RightWheelValid_Cnt_T_lgc = FALSE;

	/*** Handle Right Driven Wheel Ground Velocity ***/
	/* Velocity is invalid, so don't update it. Also reset the stuck velocity timer to prevent overflows. */
	if (D_VALID_CNT_U08 != WhlGrndVlctyRtDrvnV_Cnt_T_u08)
	{
		WhlGrndVlctyRtDrvnCEValid_Cnt_M_lgc = FALSE;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtDrvnCEStuck_mS_M_u32);

		(void)DtrmnNTCTimeout(&WhlGrndVlctyRtDrvnCEVldStartTime_mS_M_u32, k_WhlGrndVlctyRtDrvnCEVldTimeOut_mS_u16p0,
							  &WhlGrndVlctyRtDrvnCEVldAccum_Cnt_M_u16, k_WhlGrndVlctyRtDrvnCEValDiag_Cnt_str,
							  NTC_Num_InvalidMsg_AJ, D_FALSE_CNT_LGC, 0x02u);
	}
	/* If wheel velocity is stuck, and more than 5kph. */
	else if ((WhlGrndVlctyRtDrvn_Cnt_T_u16 == WhlGrndVlctyRtDrvnCE_Cnt_M_u16) &&
			(WhlGrndVlctyRtDrvn_Cnt_T_u16 >= D_5KPH_CNT_U16))
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtDrvnCEVldStartTime_mS_M_u32);

		/* If wheel velocity has been stuck long enough, signal goes invalid. */
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(WhlGrndVlctyRtDrvnCEStuck_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_WhlGrndVlctyStuckTime_mS_u16)
		{
			WhlGrndVlctyRtDrvnCEValid_Cnt_M_lgc = FALSE;
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtDrvnCEStuck_mS_M_u32);
		}

		RightWheelValid_Cnt_T_lgc = TRUE;
	}
	else /* Velocity is valid, and not stuck. */
	{
		RightWheelValid_Cnt_T_lgc = TRUE;
		WhlGrndVlctyRtDrvnCEValid_Cnt_M_lgc = TRUE;
		WhlGrndVlctyRtDrvnCE_Cnt_M_u16 = WhlGrndVlctyRtDrvn_Cnt_T_u16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtDrvnCEStuck_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtDrvnCEVldStartTime_mS_M_u32);
		WhlGrndVlctyRtDrvnCEVldAccum_Cnt_M_u16 = DiagNStep_m(WhlGrndVlctyRtDrvnCEVldAccum_Cnt_M_u16, k_WhlGrndVlctyRtDrvnCEValDiag_Cnt_str);
	}

	/*** Handle Left Driven Wheel Ground Velocity ***/
	/* Velocity is invalid, so don't update it. Also reset the stuck velocity timer to prevent overflows. */
	if (D_VALID_CNT_U08 != WhlGrndVlctyLftDrvnV_Cnt_T_u08)
	{
		WhlGrndVlctyLftDrvnCEValid_Cnt_M_lgc = FALSE;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftDrvnCEStuck_mS_M_u32);

		(void)DtrmnNTCTimeout(&WhlGrndVlctyLftDrvnCEVldStartTime_mS_M_u32, k_WhlGrndVlctyLftDrvnCEVldTimeOut_mS_u16p0,
							  &WhlGrndVlctyLftDrvnCEVldAccum_Cnt_M_u16, k_WhlGrndVlctyLftDrvnCEValDiag_Cnt_str,
							  NTC_Num_InvalidMsg_AJ, D_FALSE_CNT_LGC, 0x01u);
	}
	/* If wheel velocity is stuck, and more than 5kph. */
	else if ((WhlGrndVlctyLftDrvn_Cnt_T_u16 == WhlGrndVlctyLftDrvnCE_Cnt_M_u16) &&
			(WhlGrndVlctyLftDrvn_Cnt_T_u16 >= D_5KPH_CNT_U16))
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftDrvnCEVldStartTime_mS_M_u32);

		/* If wheel velocity has been stuck long enough, signal goes invalid. */
		(void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(WhlGrndVlctyLftDrvnCEStuck_mS_M_u32, &ElapsedTime_mS_T_u16);
		if (ElapsedTime_mS_T_u16 > k_WhlGrndVlctyStuckTime_mS_u16)
		{
			WhlGrndVlctyLftDrvnCEValid_Cnt_M_lgc = FALSE;
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftDrvnCEStuck_mS_M_u32);
		}

		LeftWheelValid_Cnt_T_lgc = TRUE;
	}
	else /* Velocity is valid, and not stuck. */
	{
		LeftWheelValid_Cnt_T_lgc = TRUE;
		WhlGrndVlctyLftDrvnCEValid_Cnt_M_lgc = TRUE;
		WhlGrndVlctyLftDrvnCE_Cnt_M_u16 = WhlGrndVlctyLftDrvn_Cnt_T_u16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftDrvnCEStuck_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftDrvnCEVldStartTime_mS_M_u32);
		WhlGrndVlctyLftDrvnCEVldAccum_Cnt_M_u16 = DiagNStep_m(WhlGrndVlctyLftDrvnCEVldAccum_Cnt_M_u16, k_WhlGrndVlctyLftDrvnCEValDiag_Cnt_str);
	}

	if ((TRUE == LeftWheelValid_Cnt_T_lgc) &&
	   (TRUE == RightWheelValid_Cnt_T_lgc) &&
	   (0u == WhlGrndVlctyRtDrvnCEVldAccum_Cnt_M_u16) &&
	   (0u == WhlGrndVlctyLftDrvnCEVldAccum_Cnt_M_u16))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AJ, 0x00u, NTC_STATUS_PASSED);
	}

	(void)NTCCheckClear(&Msg348CELoss_mS_M_u32, &Msg348CELossAccum_Cnt_M_u16, &k_Msg348CETimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AJ);
	Msg348CELKALoss_mS_M_u32 = Msg348CELoss_mS_M_u32;
	WhlGrndVlctyDrvnCEMissing_Cnt_M_lgc = FALSE;
}

/* ID: 0x34A, Periodic Rate: 50ms, Polled in runnable: SrlComInput_Per2 */
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxNonDrivenWheelGrndVelocityCE_x34A(CanReceiveHandle rcvObject)
{
	VAR(uint16, AUTOMATIC) WhlGrndVlctyLftNnDrvn_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WhlGrndVlctyRtNnDrvn_Cnt_T_u16;
	VAR(uint8, AUTOMATIC) WhlGrndVlctyLftNnDrvnV_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) WhlGrndVlctyRtNnDrvnV_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) LeftWheelValid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC) RightWheelValid_Cnt_T_lgc;

	IlGetRxWhlGrndVlctyLftNnDrvnGroup_1();
	IlGetRxWhlGrndVlctyRtNnDrvnGroup_1();

	WhlGrndVlctyLftNnDrvn_Cnt_T_u16 = IlGetRxWhlGrndVlctyLftNnDrvn_1();
	WhlGrndVlctyRtNnDrvn_Cnt_T_u16 = IlGetRxWhlGrndVlctyRtNnDrvn_1();
	WhlGrndVlctyRtNnDrvnV_Cnt_T_u08 = IlGetRxWhlGrndVlctyRtNnDrvnV_1();
	WhlGrndVlctyLftNnDrvnV_Cnt_T_u08 = IlGetRxWhlGrndVlctyLftNnDrvnV_1();

	/* Assume both signals are invalid until proven otherwise. */
	LeftWheelValid_Cnt_T_lgc = FALSE;
	RightWheelValid_Cnt_T_lgc = FALSE;

	/*** Handle Right Non-Driven Wheel Ground Velocity ***/
	/* Velocity is invalid, so don't update it. Also reset the stuck velocity timer to prevent overflows. */
	if (D_VALID_CNT_U08 != WhlGrndVlctyRtNnDrvnV_Cnt_T_u08)
	{
		WhlGrndVlctyRtNnDrvnCEValid_Cnt_M_lgc = FALSE;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtNnDrvnCEStuck_mS_M_u32);

		(void)DtrmnNTCTimeout(&WhlGrndVlctyRtNnDrvnCEVldStartTime_mS_M_u32, k_WhlGrndVlctyRtNnDrvnCEVldTimeOut_mS_u16p0,
							  &WhlGrndVlctyRtNnDrvnCEVldAccum_Cnt_M_u16, k_WhlGrndVlctyRtNnDrvnCEValDiag_Cnt_str,
							  NTC_Num_InvalidMsg_AK, D_FALSE_CNT_LGC, 0x02u);
	}
	/* If wheel velocity is stuck, and more than 5kph. */
	else if ((WhlGrndVlctyRtNnDrvn_Cnt_T_u16 == WhlGrndVlctyRtNnDrvnCE_Cnt_M_u16) &&
			(WhlGrndVlctyRtNnDrvn_Cnt_T_u16 >= D_5KPH_CNT_U16))
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtNnDrvnCEVldStartTime_mS_M_u32);

		/* If wheel velocity has been stuck long enough, signal goes invalid. */
		if (TRUE == DtrmnTimerElapsed(WhlGrndVlctyRtNnDrvnCEStuck_mS_M_u32, k_WhlGrndVlctyStuckTime_mS_u16))
		{
			WhlGrndVlctyRtNnDrvnCEValid_Cnt_M_lgc = FALSE;
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtNnDrvnCEStuck_mS_M_u32);
		}

		RightWheelValid_Cnt_T_lgc = TRUE;
	}
	else /* Velocity is valid, and not stuck. */
	{
		RightWheelValid_Cnt_T_lgc = TRUE;
		WhlGrndVlctyRtNnDrvnCEValid_Cnt_M_lgc = TRUE;
		WhlGrndVlctyRtNnDrvnCE_Cnt_M_u16 = WhlGrndVlctyRtNnDrvn_Cnt_T_u16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtNnDrvnCEStuck_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyRtNnDrvnCEVldStartTime_mS_M_u32);
		WhlGrndVlctyRtNnDrvnCEVldAccum_Cnt_M_u16 = DiagNStep_m(WhlGrndVlctyRtNnDrvnCEVldAccum_Cnt_M_u16, k_WhlGrndVlctyRtNnDrvnCEValDiag_Cnt_str);
	}

	/*** Handle Left Non-Driven Wheel Ground Velocity ***/
	/* Velocity is invalid, so don't update it. Also reset the stuck velocity timer to prevent overflows. */
	if (D_VALID_CNT_U08 != WhlGrndVlctyLftNnDrvnV_Cnt_T_u08)
	{
		WhlGrndVlctyLftNnDrvnCEValid_Cnt_M_lgc = FALSE;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftNnDrvnCEStuck_mS_M_u32);

		(void)DtrmnNTCTimeout(&WhlGrndVlctyLftNnDrvnCEVldStartTime_mS_M_u32, k_WhlGrndVlctyLftNnDrvnCEVldTimeOut_mS_u16p0,
							  &WhlGrndVlctyLftNnDrvnCEVldAccum_Cnt_M_u16, k_WhlGrndVlctyLftNnDrvnCEValDiag_Cnt_str,
							  NTC_Num_InvalidMsg_AK, D_FALSE_CNT_LGC, 0x01u);
	}
	/* If wheel velocity is stuck, and more than 5kph. */
	else if ((WhlGrndVlctyLftNnDrvn_Cnt_T_u16 == WhlGrndVlctyLftNnDrvnCE_Cnt_M_u16) &&
			(WhlGrndVlctyLftNnDrvn_Cnt_T_u16 >= D_5KPH_CNT_U16))
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftNnDrvnCEVldStartTime_mS_M_u32);

		/* If wheel velocity has been stuck long enough, signal goes invalid. */
		if (TRUE == DtrmnTimerElapsed(WhlGrndVlctyLftNnDrvnCEStuck_mS_M_u32, k_WhlGrndVlctyStuckTime_mS_u16))
		{
			WhlGrndVlctyLftNnDrvnCEValid_Cnt_M_lgc = FALSE;
			(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftNnDrvnCEStuck_mS_M_u32);
		}

		LeftWheelValid_Cnt_T_lgc = TRUE;
	}
	else /* Velocity is valid, and not stuck. */
	{
		LeftWheelValid_Cnt_T_lgc = TRUE;
		WhlGrndVlctyLftNnDrvnCEValid_Cnt_M_lgc = TRUE;
		WhlGrndVlctyLftNnDrvnCE_Cnt_M_u16 = WhlGrndVlctyLftNnDrvn_Cnt_T_u16;
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftNnDrvnCEStuck_mS_M_u32);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&WhlGrndVlctyLftNnDrvnCEVldStartTime_mS_M_u32);
		WhlGrndVlctyLftNnDrvnCEVldAccum_Cnt_M_u16 = DiagNStep_m(WhlGrndVlctyLftNnDrvnCEVldAccum_Cnt_M_u16, k_WhlGrndVlctyLftNnDrvnCEValDiag_Cnt_str);
	}

	if ((TRUE == LeftWheelValid_Cnt_T_lgc) &&
	   (TRUE == RightWheelValid_Cnt_T_lgc) &&
	   (0u == WhlGrndVlctyRtNnDrvnCEVldAccum_Cnt_M_u16) &&
	   (0u == WhlGrndVlctyLftNnDrvnCEVldAccum_Cnt_M_u16))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AK, 0x00u, NTC_STATUS_PASSED);
	}

	(void)NTCCheckClear(&Msg34ACELoss_mS_M_u32, &Msg34ACELossAccum_Cnt_M_u16, &k_Msg34ACETimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AK);
	Msg34ACELKALoss_mS_M_u32 = Msg34ACELoss_mS_M_u32;
	WhlGrndVlctyNnDrvnCEMissing_Cnt_M_lgc = FALSE;
}


/* ID: 0x180, Periodic Rate: 20ms, Polled in runnable: SrlComInput_Per2 */
FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_MsgProcess_RxSteeringTorqueCmdCE_x180(CanReceiveHandle rcvObject)
{
	VAR(boolean, AUTOMATIC) ESCRequest_Cnt_T_lgc;
	VAR(uint16, AUTOMATIC) ESCCmd_Cnt_T_u16;
	VAR(sint16, AUTOMATIC) ESCCmd_Cnt_T_s16;
	VAR(float32, AUTOMATIC) ESCCmd_HwNm_T_f32;
	VAR(uint16, AUTOMATIC) RollingCounter_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ChecksumReceived_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) ChecksumCalculated_Cnt_T_u16;
	VAR(boolean,AUTOMATIC) MessageValid_Cnt_T_lgc;

	ESCRequest_Cnt_T_lgc = IlGetRxTqOvrDltTqCmdAct();
	RollingCounter_Cnt_T_u16 = IlGetRxTrqOvrlARC();
	ESCCmd_Cnt_T_u16 = IlGetRxTqOvrDltTqCmdVl();
	ChecksumReceived_Cnt_T_u16 = IlGetRxTrqOvrlCmdChksm();

	MessageValid_Cnt_T_lgc = TRUE;

	ChecksumCalculated_Cnt_T_u16 = Steering_Torque_Command_CE._c[0];
	ChecksumCalculated_Cnt_T_u16 += Steering_Torque_Command_CE._c[1];
	ChecksumCalculated_Cnt_T_u16 += Steering_Torque_Command_CE._c[2];
	ChecksumCalculated_Cnt_T_u16 += Steering_Torque_Command_CE._c[3];
	ChecksumCalculated_Cnt_T_u16 += Steering_Torque_Command_CE._c[4];
	ChecksumCalculated_Cnt_T_u16 += Steering_Torque_Command_CE._c[5];
	ChecksumCalculated_Cnt_T_u16 += (uint16)Steering_Torque_Command_CE._c[6] & 0xF8u;
	ChecksumCalculated_Cnt_T_u16 += 0x180u / 8u;
	ChecksumCalculated_Cnt_T_u16 &= 0x7FFu;

	/* If the checksum is valid */
	if (ChecksumCalculated_Cnt_T_u16 == ChecksumReceived_Cnt_T_u16)
	{
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&ESCChksmVldStartTime_mS_M_u32);
		ESCChksmVldAccum_Cnt_M_u16 = DiagNStep_m(ESCChksmVldAccum_Cnt_M_u16, k_ESCChksmVldDiag_Cnt_str);
	}
	else /* The protection value is invalid. */
	{
		MessageValid_Cnt_T_lgc = FALSE;

		(void)DtrmnNTCTimeout(&ESCChksmVldStartTime_mS_M_u32, k_ESCChksmVldTimeOut_mS_u16p0,
						&ESCChksmVldAccum_Cnt_M_u16, k_ESCChksmVldDiag_Cnt_str,
						NTC_Num_InvalidMsg_AG,
						FALSE,
						0x02u);

		/* Set ESC Fault */
		ESCFault_Cnt_M_b16 |= D_ESCFAULT_INVALID180CE_CNT_U16;
	}

    /* Rolling Counter is Valid */
	if (RollingCounter_Cnt_T_u16 != PrevESCRollingCounter_Cnt_M_u16)
	{
		/* Try to clear the LKA fault. Clear the rolling coutner and checksum timers. */
		ESCRollCountVldAccum_Cnt_M_u16 = DiagNStep_m(ESCRollCountVldAccum_Cnt_M_u16, k_ESCRollCountVldDiag_Cnt_str);
		(void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&ESCRollCountVldStartTime_mS_M_u32);
	}
	else /* The rolling counter did not increment correctly. */
	{
		MessageValid_Cnt_T_lgc = FALSE;

		(void)DtrmnNTCTimeout(&ESCRollCountVldStartTime_mS_M_u32, k_ESCRollCountVldTimeOut_mS_u16p0,
						&ESCRollCountVldAccum_Cnt_M_u16, k_ESCRollCountVldDiag_Cnt_str,
						NTC_Num_InvalidMsg_AG,
						FALSE,
						0x01u);

		/* Set ESC Fault */
		ESCFault_Cnt_M_b16 |= D_ESCFAULT_INVALID180CE_CNT_U16;
	}

	/* Sign extend torque overlay value. */
	if (ESCCmd_Cnt_T_u16 > 1023u)
	{
		ESCCmd_Cnt_T_s16 = (sint16)(ESCCmd_Cnt_T_u16 | 0xFC00u);
	}
	else
	{
		ESCCmd_Cnt_T_s16 = (sint16)ESCCmd_Cnt_T_u16;
	}

	/* Convert from the customer sign convention. */
	ESCCmd_Cnt_T_s16 *= k_SComTrqPosPol_Cnt_s08;

	/* Scale the signal, and write it to the RTE. */
	ESCCmd_HwNm_T_f32 = (float32)ESCCmd_Cnt_T_s16 * D_TRQRQV1SF_HWNM_F32;
	ESCCmd_HwNm_T_f32 = Limit_m(ESCCmd_HwNm_T_f32, D_TRQRQV1MIN_HWNM_F32, D_TRQRQV1MAX_HWNM_F32);

	/* Only write outputs when a valid message was received */
	if (TRUE == MessageValid_Cnt_T_lgc)
	{
		(void)Rte_Write_ESCRequest_Cnt_lgc(ESCRequest_Cnt_T_lgc);
		(void)Rte_Write_ESCCmd_HwNm_f32(ESCCmd_HwNm_T_f32);
	}

	/* If the whole message is valid and all the accumulators are zero, clear the fault. */
	if ((TRUE == MessageValid_Cnt_T_lgc) &&
			(0u == ESCRollCountVldAccum_Cnt_M_u16) &&
			(0u == ESCChksmVldAccum_Cnt_M_u16))
	{
		(void)Rte_Call_NxtrDiagMgr_SetNTCStatus(NTC_Num_InvalidMsg_AG, 0x00u, NTC_STATUS_PASSED);
		ESCFault_Cnt_M_b16 &= (uint16)~D_ESCFAULT_INVALID180CE_CNT_U16;
	}

	/* Update the Rolling Counter */
	PrevESCRollingCounter_Cnt_M_u16 = RollingCounter_Cnt_T_u16;

	(void)NTCCheckClear(&Msg180CELoss_mS_M_u32, &Msg180CELossAccum_Cnt_M_u16, &k_Msg180CETimeOutDiag_Cnt_str, NTC_Num_MissingMsg_AG);
	ESCFault_Cnt_M_b16 &= (uint16)~D_ESCFAULT_MISSING180CE_CNT_U16;
}


/**********************************************************************************
 * Function name: SrlComInput_APARecFltsGet
 * Description: This function returns the status of the APA recoverable faults
 *
 * Returns: A bitmap value representing the faults for APA. Check the macros
 *          D_APARECOVERABLEFAULTS for details on how the bitmap is set
 *
 * Parameter: None
**********************************************************************************/
STATIC FUNC(uint8, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFltsGet(void)
{
    return APARecoverableFaults_Cnt_M_b08;
}


/**********************************************************************************
 * Function name: SrlComInput_APARecFltsSet
 * Description: This function sets a recoverable fault. The faults can be enable
 *              or disable using k_APARecFltsMsk_Cnt_b08.
 *
 * Returns: None
 *
 * Parameter: Fault_Cnt_T_b08  Fault to set, check D_APARECOVERABLEFAULTS macros
 *            Status_Cnt_T_lgc TRUE if it is to set the fault, FALSE if it is to clean it
**********************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFltsSet(VAR(uint8, AUTOMATIC) Fault_Cnt_T_b08,
                                                                          VAR(boolean, AUTOMATIC) Status_Cnt_T_lgc)
{
    if ((Status_Cnt_T_lgc == TRUE) && ((Fault_Cnt_T_b08 & k_APARecFltsMsk_Cnt_b08) == Fault_Cnt_T_b08))
    {
        APARecoverableFaults_Cnt_M_b08 |= Fault_Cnt_T_b08;
        APARecFaultsLatch_Cnt_D_b08 |= Fault_Cnt_T_b08;
    }
    else
    {
        APARecoverableFaults_Cnt_M_b08 &= (uint8)~Fault_Cnt_T_b08;
    }
}


/**********************************************************************************
 * Function name: SrlComInput_APARecFlts337Present
 * Description: This function should be called every time a message 337 is received.
 *
 * Returns: None
 *
 * Parameter: None
**********************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFlts337Present(void)
{
    (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Msg337LossAPARec_mS_M_u32);
    SrlComInput_APARecFltsSet(D_APARECOVERABLEFAULTS_MISSING337_CNT_U08, FALSE);
}


/**********************************************************************************
 * Function name: SrlComInput_APARecFlts337Missing
 * Description: This function identify when the message 337 is missing and set
 *              a recoverable fault. It should be called periodically.
 *
 * Returns: None
 *
 * Parameter: None
**********************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFlts337Missing(void)
{
    VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;

    (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(Msg337LossAPARec_mS_M_u32, &ElapsedTime_mS_T_u16p0);
    if (ElapsedTime_mS_T_u16p0 > k_Msg337APARecTimeOut_mS_u16)
    {
        /* If the timer has elapsed, reset it. */
        (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Msg337LossAPARec_mS_M_u32);
        SrlComInput_APARecFltsSet(D_APARECOVERABLEFAULTS_MISSING337_CNT_U08, TRUE);
    }
}


/**********************************************************************************
 * Function name: SrlComInput_APARecFlts337Invalid
 * Description: This function set the invalid state of the 337 message for
 *              recoverable faults. There is no calibration to set the fault state,
 *              a single invalid message will set the fault to TRUE.
 *
 * Returns: None
 *
 * Parameter: Invalid_Cnt_T_lgc TRUE when the 337 message is invalid, FALSE otherwise
**********************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFlts337Invalid(VAR(boolean, AUTOMATIC) Invalid_Cnt_T_lgc)
{
    SrlComInput_APARecFltsSet(D_APARECOVERABLEFAULTS_INVALID337_CNT_U08, Invalid_Cnt_T_lgc);
}


/**********************************************************************************
 * Function name: SrlComInput_APARecFlts1F5Invalid
 * Description: This function set the invalid state of the 1F5 message for
 *              recoverable faults. There is no calibration to set the fault state,
 *              a single invalid message will set the fault to TRUE.
 *
 * Returns: None
 *
 * Parameter: Invalid_Cnt_T_lgc TRUE when the 1F5 message is invalid, FALSE otherwise
**********************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFlts1F5Invalid(VAR(boolean, AUTOMATIC) Invalid_Cnt_T_lgc)
{
    SrlComInput_APARecFltsSet(D_APARECOVERABLEFAULTS_INVALID1F5_CNT_U08, Invalid_Cnt_T_lgc);
}


/**********************************************************************************
 * Function name: SrlComInput_APARecFltsPer
 * Description: Periodic function to update the status of APA recoverable faults.
 *
 * Returns: None
 *
 * Parameter: None
**********************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APARecFltsPer(void)
{
    SrlComInput_APARecFlts337Missing();
}

/**********************************************************************************
 * Function name: SrlComInput_APANonRecFltsGet
 * Description: This function returns the status of the APA non recoverable faults
 *
 * Returns: A bitmap value representing the faults for APA. Check the macros
 *          D_APANONRECOVERABLEFAULTS for details on how the bitmap is set
 *
 * Parameter: None
**********************************************************************************/
STATIC FUNC(uint16, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APANonRecFltsGet(void)
{
    return APANonRecoverableFaults_Cnt_M_b16;
}


/**********************************************************************************
 * Function name: SrlComInput_APANonRecFltsSet
 * Description: This function sets a non recoverable fault. The faults can be enable
 *              or disable using k_APANonRecFltsMsk_Cnt_b16.
 *
 * Returns: None
 *
 * Parameter: Fault_Cnt_T_b16  Fault to set, check D_APANONRECOVERABLEFAULTS macros
 *            Status_Cnt_T_lgc TRUE if it is to set the fault, FALSE if it is to clean it
**********************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APANonRecFltsSet(VAR(uint16, AUTOMATIC) Fault_Cnt_T_b16,
                                                                             VAR(boolean, AUTOMATIC) Status_Cnt_T_lgc)
{
    if ((Status_Cnt_T_lgc == TRUE) && ((Fault_Cnt_T_b16 & k_APANonRecFltsMsk_Cnt_b16) == Fault_Cnt_T_b16))
    {
        APANonRecoverableFaults_Cnt_M_b16 |= Fault_Cnt_T_b16;
        APANonRecFaultsLatch_Cnt_D_b16 |= Fault_Cnt_T_b16;
    }
    else
    {
        APANonRecoverableFaults_Cnt_M_b16 &= (uint16)~Fault_Cnt_T_b16;
    }
}


/**********************************************************************************
 * Function name: SrlComInput_APANonRecFlts337Present
 * Description: This function should be called every time a message 337 is received.
 *
 * Returns: None
 *
 * Parameter: None
**********************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APANonRecFlts337Present(void)
{
    (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Msg337LossAPANonRec_mS_M_u32);

    Msg337LossAccumAPA_Cnt_M_u16 = DiagNStep_m(Msg337LossAccumAPA_Cnt_M_u16, k_Msg337APATimeOutDiag_Cnt_str);
    if (0u == Msg337LossAccumAPA_Cnt_M_u16)
    {
        SrlComInput_APANonRecFltsSet(D_APANONRECOVERABLEFAULTS_MISSING337_CNT_U16, FALSE);
    }
}


/**********************************************************************************
 * Function name: SrlComInput_APANonRecFlts337Missing
 * Description: This function identify when the message 337 is missing and set
 *              a non recoverable fault. It should be called periodically.
 *
 * Returns: None
 *
 * Parameter: None
**********************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APANonRecFlts337Missing(void)
{
    VAR(uint16, AUTOMATIC) ElapsedTime_mS_T_u16p0;

    (void)Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(Msg337LossAPANonRec_mS_M_u32, &ElapsedTime_mS_T_u16p0);
    if (ElapsedTime_mS_T_u16p0 > k_Msg337APANonRecTimeOut_mS_u16)
    {
        /* If the timer has elapsed, reset it. */
        (void)Rte_Call_SystemTime_GetSystemTime_mS_u32(&Msg337LossAPANonRec_mS_M_u32);

        Msg337LossAccumAPA_Cnt_M_u16 = DiagPStep_m(Msg337LossAccumAPA_Cnt_M_u16, k_Msg337APATimeOutDiag_Cnt_str);
        if (TRUE == DiagFailed_m(Msg337LossAccumAPA_Cnt_M_u16, k_Msg337APATimeOutDiag_Cnt_str))
        {
            SrlComInput_APANonRecFltsSet(D_APANONRECOVERABLEFAULTS_MISSING337_CNT_U16, TRUE);
        }
    }
}


/**********************************************************************************
 * Function name: SrlComInput_APANonRecFlts337Invalid
 * Description: This function handles the P and N step to the APA non
 *              recoverable fault invalid 337 message.
 *
 * Returns: None
 *
 * Parameter: Invalid_Cnt_T_lgc TRUE when the 337 message is invalid, FALSE otherwise
**********************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APANonRecFlts337Invalid(boolean Invalid_Cnt_T_lgc)
{
    if (Invalid_Cnt_T_lgc == TRUE)
    {
        Msg337InvalidAccumAPA_Cnt_M_u16 = DiagPStep_m(Msg337InvalidAccumAPA_Cnt_M_u16, k_Msg337APAInvalidDiag_Cnt_str);
        if (TRUE == DiagFailed_m(Msg337InvalidAccumAPA_Cnt_M_u16, k_Msg337APAInvalidDiag_Cnt_str))
        {
            SrlComInput_APANonRecFltsSet(D_APANONRECOVERABLEFAULTS_INVALID337_CNT_U16, TRUE);
        }
    }
    else
    {
        Msg337InvalidAccumAPA_Cnt_M_u16 = DiagNStep_m(Msg337InvalidAccumAPA_Cnt_M_u16, k_Msg337APAInvalidDiag_Cnt_str);
        if (0u == Msg337InvalidAccumAPA_Cnt_M_u16)
        {
            SrlComInput_APANonRecFltsSet(D_APANONRECOVERABLEFAULTS_INVALID337_CNT_U16, FALSE);
        }
    }
}


/**********************************************************************************
 * Function name: SrlComInput_APANonRecFltsPer
 * Description: Periodic function to update the status of the APA non
 *              recoverable faults.
 *
 * Returns: None
 *
 * Parameter: None
**********************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_APANonRecFltsPer(void)
{
    VAR(boolean, AUTOMATIC) Status_Cnt_T_lgc;

    (void)Rte_Read_DiagStsNonRecRmpToZeroFltPres_Cnt_lgc(&Status_Cnt_T_lgc);
    SrlComInput_APANonRecFltsSet(D_APANONRECOVERABLEFAULTS_DIAGSTS_CNT_U16, Status_Cnt_T_lgc);

    (void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_HWACrossChecks, &Status_Cnt_T_lgc);
    SrlComInput_APANonRecFltsSet(D_APANONRECOVERABLEFAULTS_NTC06C_CNT_U16, Status_Cnt_T_lgc);

    (void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_HWASnsrCommFault, &Status_Cnt_T_lgc);
    SrlComInput_APANonRecFltsSet(D_APANONRECOVERABLEFAULTS_NTC06D_CNT_U16, Status_Cnt_T_lgc);

    (void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_HWASensorRel, &Status_Cnt_T_lgc);
    SrlComInput_APANonRecFltsSet(D_APANONRECOVERABLEFAULTS_NTC06E_CNT_U16, Status_Cnt_T_lgc);

    (void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_HWASensorAbs, &Status_Cnt_T_lgc);
    SrlComInput_APANonRecFltsSet(D_APANONRECOVERABLEFAULTS_NTC06F_CNT_U16, Status_Cnt_T_lgc);

    (void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_InvalidMsg_ParkAssistParallel, &Status_Cnt_T_lgc);
    SrlComInput_APANonRecFltsSet(D_APANONRECOVERABLEFAULTS_NTC1D0_CNT_U16, Status_Cnt_T_lgc);

    (void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_MissingMsg_ParkAssistParallel, &Status_Cnt_T_lgc);
    SrlComInput_APANonRecFltsSet(D_APANONRECOVERABLEFAULTS_NTC1D1_CNT_U16, Status_Cnt_T_lgc);

    (void)Rte_Call_NxtrDiagMgr_GetNTCActive(NTC_Num_HWASensorNotTrimmed, &Status_Cnt_T_lgc);
    SrlComInput_APANonRecFltsSet(D_APANONRECOVERABLEFAULTS_NTC1F8_CNT_U16, Status_Cnt_T_lgc);

    SrlComInput_APANonRecFlts337Missing();
}


/*****************************************************************************
 *  Function Name:     SrlComInput_DecrementCMEC
 *  Description:       Decrements the Customer MEC
 *
 *  Inputs:            None
 *  Outputs:           None
 *****************************************************************************/
STATIC FUNC(void, RTE_AP_SRLCOMINPUT_APPL_CODE) SrlComInput_DecrementCMEC(void)
{
    if ((Nvm_CMEC_Cnt_u8 > 0U) && (Nvm_CMEC_Cnt_u8 != 0xFFU))
    {
        Nvm_CMEC_Cnt_u8 -= 1U;
        (void)NvM_SetRamBlockStatus((NvM_BlockIdType)NVM_BLOCK_SER_CUSTMEC, TRUE);
    }
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
