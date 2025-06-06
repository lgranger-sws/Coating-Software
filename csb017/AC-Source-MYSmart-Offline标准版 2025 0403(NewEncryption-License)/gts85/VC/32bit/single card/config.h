#pragma once

#define RES_LIMIT                       14
#define RES_ALARM                       14
#define RES_HOME                        14
#define RES_GPI                         16
#define RES_ARRIVE                      14
#define RES_MPG                         7

#define RES_ENABLE                      14
#define RES_CLEAR                       14
#define RES_GPO                         16

#define RES_DAC                         12
#define RES_STEP                        14
#define RES_PULSE                       14
#define RES_ENCODER                     14
#define RES_LASER                       2

#define RES_AIXS_MAX                    8  

#define AXIS_MAX                        18
#define PROFILE_MAX                     18
#define CONTROL_MAX                     14

#define PRF_MAP_MAX                     2
#define ENC_MAP_MAX                     2

#define STEP_DIR                        0
#define STEP_PULSE                      1
#define STEP_ORTHOGONAL                 2

#define USER_VAR_LENGTH                 16

#define WATCH_EVENT_MAX					8
#define WATCH_LIST_MAX                  8
#define WATCH_LENGTH_MAX                32
#define WATCH_FIFO_SIZE                 0x1E0       // 480 word

#define WATCH_ADDRESS_TYPE_PRF_POS      (0)
#define WATCH_ADDRESS_TYPE_PRF_VEL      (1)
#define WATCH_ADDRESS_TYPE_ENC_POS      (2)
#define WATCH_ADDRESS_TYPE_ENC_VEL      (3)
#define WATCH_ADDRESS_TYPE_AXIS_PRF_POS (4)
#define WATCH_ADDRESS_TYPE_AXIS_PRF_VEL (5)
#define WATCH_ADDRESS_TYPE_AXIS_ENC_POS (6)
#define WATCH_ADDRESS_TYPE_AXIS_ENC_VEL (7)
#define WATCH_ADDRESS_TYPE_DAC          (8)
#define WATCH_ADDRESS_TYPE_LMT_POS      (9)
#define WATCH_ADDRESS_TYPE_LMT_NEG      (10)
#define WATCH_ADDRESS_TYPE_ALARM        (11)
#define WATCH_ADDRESS_TYPE_HOME         (12)
#define WATCH_ADDRESS_TYPE_GPI          (13)
#define WATCH_ADDRESS_TYPE_ENABLE       (14)
#define WATCH_ADDRESS_TYPE_CLEAR        (15)
#define WATCH_ADDRESS_TYPE_GPO          (16)
#define WATCH_ADDRESS_TYPE_CLOCK        (17)
#define WATCH_ADDRESS_TYPE_FLASH_BUFFER (18)
#define WATCH_ADDRESS_TYPE_CRD_VEL      (19)
#define WATCH_ADDRESS_TYPE_ARRIVE       (20)
#define WATCH_ADDRESS_TYPE_POS_LOOP_ERROR (21)
#define WATCH_ADDRESS_TYPE_POS_LOOP_OUTPUT (22)
#define WATCH_ADDRESS_TYPE_POS_LOOP_INTERGRAL (23)
#define WATCH_ADDRESS_TYPE_VEL_LOOP_ERROR (24)
#define WATCH_ADDRESS_TYPE_VEL_LOOP_INTERGRAL (25)
#define WATCH_ADDRESS_TYPE_SPRING_OFFSET (26)
#define WATCH_ADDRESS_TYPE_BEFORE_SPRING (27)
#define WATCH_ADDRESS_TYPE_AFTER_SPRING (28)
#define WATCH_ADDRESS_TYPE_OBSERVER_LOWPASS_OUTPUT (29)
#define WATCH_ADDRESS_TYPE_OBSERVER_OUTPUT_PRE (30)
#define WATCH_ADDRESS_TYPE_OBSERVER_TORQUE_CMD_PRE (31)
#define WATCH_ADDRESS_TYPE_OBSERVER_VEL_FEEDBACK_INTERGRAL (32)
#define WATCH_ADDRESS_TYPE_OBSERVER_VEL_ERR_FEEDBACK_INTERGRAL (33)
#define WATCH_ADDRESS_TYPE_POS_LOOP_REF_POS (34)
#define WATCH_ADDRESS_TYPE_ADC                   (35)               //16.0

#define CRD_BUF_DATA_NULL						0

typedef struct DiConfig
{
    short active;
    short reverse;
    short filterTime;
} TDiConfig;

typedef struct CountConfig
{
    short active;
    short reverse;
    short filterType;

    short captureSource;
    short captureHomeSense;
    short captureIndexSense;
} TCountConfig;

typedef struct DoConfig
{
    short active;
    short axis;
    short axisItem;
    short reverse;
} TDoConfig;

typedef struct StepConfig
{
    short active;
    short axis;
    short mode;
    short parameter;
    short reverse;
} TStepConfig;

typedef struct DacConfig
{
    short active;
    short control;
    short reverse;
    short bias;
    short limit;
} TDacConfig;

typedef struct ControlConfig
{
    short active;
    short axis;
    short encoder1;
    short encoder2;
    long  errorLimit;
    short filterType[3];
    short encoderSmooth;
    short controlSmooth;
} TControlConfig;

typedef struct ProfileConfig
{
    short  active;
    double decSmoothStop;
    double decAbruptStop;
} TProfileConfig;

typedef struct AxisConfig
{
    short active;
    short alarmType;
    short alarmIndex;
    short limitPositiveType;
    short limitPositiveIndex;
    short limitNegativeType;
    short limitNegativeIndex;
    short smoothStopType;
    short smoothStopIndex;
    short abruptStopType;
    short abruptStopIndex;
    long  prfMap;
    long  encMap;
    short prfMapAlpha[PRF_MAP_MAX];
    short prfMapBeta[PRF_MAP_MAX];
    short encMapAlpha[ENC_MAP_MAX];
    short encMapBeta[ENC_MAP_MAX];
} TAxisConfig;

typedef struct McConfig
{
    TProfileConfig profile[PROFILE_MAX];
    TAxisConfig    axis[AXIS_MAX];
    TControlConfig control[CONTROL_MAX];
    TDacConfig     dac[RES_DAC];
    TStepConfig    step[RES_STEP];
    TCountConfig   encoder[RES_ENCODER];
    TCountConfig   pulse[RES_PULSE];
    TDoConfig      enable[RES_ENABLE];
    TDoConfig      clear[RES_CLEAR];
    TDoConfig      gpo[RES_GPO];
    TDiConfig      limitPositive[RES_LIMIT];
    TDiConfig      limitNegative[RES_LIMIT];
    TDiConfig      alarm[RES_ALARM];
    TDiConfig      home[RES_HOME];
    TDiConfig      gpi[RES_GPI + 8];		//扩大来兼容GUS产品 du.ws 20191228
    TDiConfig      arrive[RES_ARRIVE];
	TDiConfig      mpg[RES_MPG];
} TMcConfig;

typedef struct ThreadStatus
{
    short link;
    unsigned long  address;
    short size;
    unsigned long  page;
    short delay;
    short priority;
    short ptr;
    short status;
    short error;
    short result[4];
    short resultType;
    short breakpoint;
    short period;
    short count;
    short function;
} TThreadStatus;

typedef struct Watch
{
    short count;
    short interval;
    unsigned long address[WATCH_LIST_MAX];
    short length[WATCH_LIST_MAX];
    unsigned long threshold;
} TWatch;

typedef struct ControlInfo
{
	double refPos;
	double refPosFilter;
	double refPosFilter2;
	double cntPos;
	double cntPosFilter;

	double error;
	double refVel;
	double refAcc;

	short value;
	short valueFilter;

	short offset;
} TControlInfo;

typedef struct RtcTime
{
    short century;
    short year;
    short month;
    short date;
    short day;
    short hour;
    short minutes;
    short seconds;
}TRtcTime;

GT_API GT_SetDiConfig(short diType,short diIndex,TDiConfig *pDi);
GT_API GT_GetDiConfig(short diType,short diIndex,TDiConfig *pDi);
GT_API GT_SetDoConfig(short doType,short doIndex,TDoConfig *pDo);
GT_API GT_GetDoConfig(short doType,short doIndex,TDoConfig *pDo);
GT_API GT_SetStepConfig(short step,TStepConfig *pStep);
GT_API GT_GetStepConfig(short step,TStepConfig *pStep);
GT_API GT_SetStepReverse(short step,short reverse);
GT_API GT_GetStepReverse(short step,short *pReverse);
GT_API GT_SetDacConfig(short dac,TDacConfig *pDac);
GT_API GT_GetDacConfig(short dac,TDacConfig *pDac);
GT_API GT_SetCountConfig(short countType,short countIndex,TCountConfig *pCount);
GT_API GT_GetCountConfig(short countType,short countIndex,TCountConfig *pCount);
GT_API GT_SetControlConfig(short control,TControlConfig *pControl);
GT_API GT_GetControlConfig(short control,TControlConfig *pControl);
GT_API GT_SetProfileConfig(short profile,TProfileConfig *pProfile);
GT_API GT_GetProfileConfig(short profile,TProfileConfig *pProfile);
GT_API GT_SetAxisConfig(short axis,TAxisConfig *pAxis);
GT_API GT_GetAxisConfig(short axis,TAxisConfig *pAxis);
GT_API GT_GetConfigTable(short type,short *pCount);

GT_API GT_SetMcConfig(TMcConfig *pMc);
GT_API GT_GetMcConfig(TMcConfig *pMc);

GT_API GT_SetMcConfigToFile(TMcConfig *pMc,char *pFile);
GT_API GT_GetMcConfigFromFile(TMcConfig *pMc,char *pFile);

GT_API GT_SaveConfig(char *pFile);

GT_API GT_Serialize(void);
GT_API GT_ResetOrigin(void);

GT_API GT_Retain(void);

GT_API GT_SetMemory(unsigned long address,short count,short *pData);
GT_API GT_GetMemory(unsigned long address,short count,short *pData);

GT_API GT_FlashToSdram(long *pRetry=NULL);
GT_API GT_SdramToFlash(long *pRetry=NULL);
GT_API GT_SdramToFlash2(long *pRetry=NULL);
GT_API GT_TestSdram();

typedef struct
{
	short vender;
	short deviceSizeExp;
	short sectorSizeExp;
	short pageSizeExp;
	short flashType;
	short reserve;
} TFlashBurnInfo;

GT_API GT_FlashReadQuery(short command,short count,short* readbuf);
GT_API GT_FlashAccessDsp(short command,short crtl,long address,short count,short* pData);
GT_API GT_SetFlashAccessDspOrder(short command,short index);
GT_API GT_GetFlashAccessDspOrder(short count,short *comandList);
GT_API GT_FlashWriteEnable(short enable);
GT_API GT_SetFlashBurnInfo(TFlashBurnInfo flashInfo);
GT_API GT_GetFlashBurnInfo(TFlashBurnInfo *pFlashInfo);

GT_API GT_GetPlsPos(short pulse,double *pValue,short count,unsigned long *pClock);
GT_API GT_GetPlsVel(short pulse,double *pValue,short count,unsigned long *pClock);

GT_API GT_ClearPlc(void);
GT_API GT_LoadPlc(short id,short returnType);
GT_API GT_LoadPlcCommand(short id,short count,short *pData);
GT_API GT_StepThread(short thread);
GT_API GT_RunThreadToBreakpoint(short thread,short line);
GT_API GT_GetThread(short thread,TThreadStatus *pThread);

GT_API GT_SetWatch(TWatch *pWatch);
GT_API GT_StartWatch(void);
GT_API GT_StartWatchStatic(void);
GT_API GT_StopWatch(void);
GT_API GT_StopWatchStatic(void);
GT_API GT_LoadWatchFifo(short fifo,short *pBuf);
GT_API GT_GetWatchFifo(short *pFifo);
GT_API GT_GetWatchAddress(short type,short index,unsigned long *pAddress,short count=1);
GT_API GT_GetWatchSts(short *pRun,unsigned long *pCount);
GT_API GT_GetWatchData(unsigned long offset,short *pData,short count=1);

GT_API GT_GetControlInfo(short control,TControlInfo *pControlInfo);

GT_API GT_SetRtcTime(TRtcTime *pRtcTime);
GT_API GT_GetRtcTime(TRtcTime *pRtcTime);

GT_API GT_GetFlashPassword(unsigned short *pPassword);
GT_API GT_CheckFlashPassword(void);

GT_API GT_CheckPassword(char *pPassword);
GT_API GT_ModifyPassword(char *pOldPassword,char *pNewPassword);

GT_API GT_LinkCaptureOffset(short encoder,short source);
GT_API GT_SetCaptureOffset(short encoder,long *pOffset,short count=1,long loop=1);
GT_API GT_GetCaptureOffset(short encoder,long *pOffset,short *pCount,long *pLoop);
GT_API GT_GetCaptureOffsetStatus(short encoder,short *pCount,long *pLoop,long *pCapturePos);

GT_API GT_SetServoTime(long servoTime,long delay,long stepCoef);
GT_API GT_GetServoTime(long *pServoTime,long *pDelay,long *pStepCoef);

GT_API GT_SetFollowRegist(short profile,short segment,short fifo);
GT_API GT_GetFollowRegist(short profile,short *pSegment,short fifo);
GT_API GT_GetFollowRegistCount(short profile,unsigned long *pCount);

GT_API GT_AutoCaptureOn(short encoder);
GT_API GT_AutoCaptureOff(short encoder);

GT_API GT_SetCaptureCount(short encoder,unsigned long count);
GT_API GT_GetCaptureCount(short encoder,unsigned long *pCount,short count=1,unsigned long *pClock=NULL);

GT_API GT_GetEncPosModulo(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetEncPosRegist(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GT_SetFollowVirtualSeg(short profile,short segment,short axis,short fifo);
GT_API GT_GetFollowVirtualSeg(short profile,short *pSegment,short *pAxis,short fifo);

GT_API GT_GetFollowVirtualErr(short profile,double *pVirtualErr);
GT_API GT_ClearFollowVirtualErr(short profile);

GT_API GT_AutoSetWatch(long *pWatchInfo,short interval);
GT_API GT_PrintWatchStaticData(char *pFileName);

GT_API GT_GetInterruptTime(double *pServoRunTime,double *pProfileRunTime);
GT_API GT_GetInterruptTimeMax(double *pServoRunTimeMax,double *pProfileRunTimeMax);

GT_API GT_Reserve(long mask);

//////////////////////////////////////////////////////////////////////////
//New Watch
//////////////////////////////////////////////////////////////////////////
#define WATCH_MODE_STATIC					(0)
#define WATCH_MODE_LOOP						(1)
#define WATCH_MODE_DYNAMIC					(2)

#define WATCH_MODE_STATIC_BACKGROUND		(10)
#define WATCH_MODE_LOOP_BACKGROUND			(11)
#define WATCH_MODE_DYNAMIC_BACKGROUND		(12)

#define WATCH_EVENT_RUN						(1)
#define WATCH_EVENT_START					(10)
#define WATCH_EVENT_STOP					(20)
#define WATCH_EVENT_OFF						(30)

#define WATCH_CONDITION_EQ					(1)
#define WATCH_CONDITION_NE					(2)
#define WATCH_CONDITION_GE					(3)
#define WATCH_CONDITION_LE					(4)

#define WATCH_CONDITION_CHANGE_TO			(11)
#define WATCH_CONDITION_CHANGE				(12)
#define WATCH_CONDITION_UP					(13)
#define WATCH_CONDITION_DOWN				(14)

#define WATCH_CONDITION_REMAIN_AT			(21)
#define WATCH_CONDITION_REMAIN				(22)

#define WATCH_CONDITION_CROSS_POSITIVE		(23)
#define WATCH_CONDITION_CROSS_NEGATIVE		(24)

#define WATCH_VAR_CLOCK						(1200)
#define WATCH_VAR_PRF_LOOP					(1201)
#define WATCH_VAR_PRF_PERIOD				(1205)
#define WATCH_VAR_PRF_TIME					(1206)

#define WATCH_VAR_COMMAND_CODE				(1220)
#define WATCH_VAR_COMMAND_DATA				(1221)
#define WATCH_VAR_COMMAND_COUNT				(1222)
#define WATCH_VAR_COMMAND_READ_FLAG			(1223)

#define WATCH_VAR_PRF_POS					(6000)
#define WATCH_VAR_PRF_VEL					(6001)
#define WATCH_VAR_PRF_ACC					(6002)
#define WATCH_VAR_PRF_POS_RAW               (6003)
#define WATCH_VAR_PRF_VEL_RAW				(6004)
#define WATCH_VAR_PRF_RUN					(6200)

#define WATCH_VAR_TRAP_TOTAL_TIME           (6670)
#define WATCH_VAR_TRAP_REMAIN_TIME          (6671)

#define WATCH_VAR_CRD_PRF_POS				(8000)
#define WATCH_VAR_CRD_PRF_VEL				(8001)
#define WATCH_VAR_CRD_PRF_ACC				(8002)
#define WATCH_VAR_CRD_PRF_VEL_RAW		    (8003)

#define WATCH_VAR_CRD_RUN					(8200)

#define WATCH_VAR_CRD_SEGMENT_NUMBER		(8202)
#define WATCH_VAR_CRD_SEGMENT_NUMBER_USER	(8203)
#define WATCH_VAR_CRD_COMMAND_RECEIVE		(8204)
#define WATCH_VAR_CRD_COMMAND_EXECUTE		(8205)

#define WATCH_VAR_CRD_FOLLOW_SLAVE_POS		(8600)
#define WATCH_VAR_CRD_FOLLOW_SLAVE_VEL		(8601)

#define WATCH_VAR_CRD_FOLLOW_STAGE			(8610)

#define WATCH_VAR_CATCH_UP_STATE                           (12000)
#define WATCH_VAR_CATCH_UP_COMMAND                         (12001)
#define WATCH_VAR_CATCH_UP_MASTER_POS                      (12002)
#define WATCH_VAR_CATCH_UP_MASTER_VEL                      (12003)
#define WATCH_VAR_CATCH_UP_SLAVE_POS                       (12004)
#define WATCH_VAR_CATCH_UP_SLAVE_VEL                       (12005)
#define WATCH_VAR_CATCH_UP_PIECE_POS                       (12006)
#define WATCH_VAR_CATCH_UP_PIECE_ID                        (12007)
#define WATCH_VAR_CATCH_UP_PIECE_COUNT                     (12008)
#define WATCH_VAR_CATCH_UP_PIECE_FIFO_COMMAND_RECEIVE      (12009)
#define WATCH_VAR_CATCH_UP_PIECE_FIFO_COMMAND_SEND         (12010)
#define WATCH_VAR_CATCH_UP_SYNCH_DISTANCE                  (12011)
#define WATCH_VAR_CATCH_UP_SYNCN_TIME                      (12012)
#define WATCH_VAR_CATCH_UP_PIECE_START_POS                 (12013)
#define WATCH_VAR_CATCH_UP_PIECE_SYNCH_POS                 (12014)
#define WATCH_VAR_CATCH_UP_SLAVE_START_POS                 (12015)
#define WATCH_VAR_CATCH_UP_SLAVE_SYNCH_POS                 (12016)

#define WATCH_VAR_POS_COMPARE_COMMAND_RECEIVE	(17422)
#define WATCH_VAR_POS_COMPARE_COMMAND_SEND		(17423)
#define WATCH_VAR_POS_COMPARE_COMMAND_LEFT		(17424)
#define WATCH_VAR_POS_COMPARE_COMMAND_TX		(17425)
#define WATCH_VAR_POS_COMPARE_PULSE_COUNT		(17426)

#define WATCH_VAR_SCAN_PRF_POS				(18000)
#define WATCH_VAR_SCAN_PRF_VEL				(18001)
#define WATCH_VAR_SCAN_PRF_ACC				(18002)

#define WATCH_VAR_SCAN_PRF_POS_X			(18010)
#define WATCH_VAR_SCAN_PRF_POS_Y			(18020)

#define WATCH_VAR_SCAN_RUN					(18200)

#define WATCH_VAR_SCAN_SEGMENT_NUMBER		(18202)


#define WATCH_VAR_LASER_HSIO				(18600)
#define WATCH_VAR_LASER_POWER				(18601)

#define WATCH_VAR_AXIS_PRF_POS				(20000)
#define WATCH_VAR_AXIS_PRF_VEL				(20001)
#define WATCH_VAR_AXIS_PRF_ACC				(20002)
#define WATCH_VAR_AXIS_ENC_POS				(20003)

#define WATCH_VAR_AXIS_PRF_VEL_FILTER		(20011)

#define WATCH_VAR_AXIS_RUN       			(20200)
#define WATCH_VAR_AXIS_ENABLE      			(20201)

#define WATCH_VAR_POSCOMPARE_PREDICTION_ENABLE                  (20370)
#define WATCH_VAR_POSCOMPARE_PREDICTION_WORK                    (20371)
#define WATCH_VAR_POSCOMPARE_PREDICTION_OUTPUT_COUNT_TOTAL      (20372)

#define WATCH_VAR_ENC_POS					(30000)

#define WATCH_VAR_ENC_VEL					(30001)

#define WATCH_VAR_GPI						(31000)
#define WATCH_VAR_LIMIT_POSITIVE			(31010)
#define WATCH_VAR_LIMIT_NEGATIVE			(31020)
#define WATCH_VAR_ALARM   		        	(31030)
#define WATCH_VAR_HOME             			(31040)
#define WATCH_VAR_ARRIVE           			(31050)

#define WATCH_VAR_GPO						(32000)

#define WATCH_VAR_AI						(33000)

#define WATCH_VAR_AO						(34000)

#define WATCH_VAR_AUTO_FOCUS_OUT			(34006)

#define WATCH_VAR_TRIGGER_EXECUTE			(38000)
#define WATCH_VAR_TRIGGER_STATUS			(38001)
#define WATCH_VAR_TRIGGER_POSITION			(38002)
#define WATCH_VAR_TRIGGER_COUNT				(38010)

#define WATCH_VAR_POS_LOOP_ERROR			(40000)

#define WATCH_VAR_CONTROL_REF_VEL			(41000)

#define WATCH_VAR_WATCH_TIME				(52001)

#define WATCH_VAR_INT32						(52020)
#define WATCH_VAR_INT64						(52021)
#define WATCH_VAR_FLOAT						(52022)
#define WATCH_VAR_DOUBLE					(52023)
#define WATCH_VAR_BOOL						(52024)

#define WATCH_VAR_LONG_VAR                  (52030)
#define WATCH_VAR_DOUBLE_VAR                (52031)
#define WATCH_VAR_FLAG_VAR                  (52032)

typedef struct  
{
	unsigned short type;
	unsigned short loop;
	unsigned short watchCount;
	TWatchVar var;
	unsigned short condition;
	double value;
} TWatchEvent;

GT_API GT_ClearWatch(short mode=0);
GT_API GT_AddWatchVar(const TWatchVar *pVar);
GT_API GT_AddWatchEvent(const TWatchEvent *pEvent);
GT_API GT_WatchOn(short interval=0,short mode=WATCH_MODE_STATIC,unsigned short count=0);
GT_API GT_WatchOff(void);
GT_API GT_PrintWatch(const char *pFileName,long start=0,unsigned long printCount=0);
GT_API GT_GetMcVar(const TWatchVar *pVar,double *pValue);

GT_API GT_SetWatchGroup(short group);
GT_API GT_GetWatchGroup(short *pGroup);
GT_API GT_LoadWatchConfig(char *pFile);
GT_API GT_SaveWatchConfig(short group,char *pFile);
GT_API GT_ReadWatch(short varIndex,double *pBuffer,unsigned long bufferSize,unsigned long *pReadCount);

typedef struct  
{
	short enable;						// 采集使能
	short run;							// 采集状态
	unsigned long time;					// 采集次数
	unsigned long head;					// 头指针
	unsigned long threshold;			// 最多容纳采集次数

	short interval;						// 采集间隔
	short mode;							// 采集模式
	unsigned short countBeforeEvent;	// 事件触发之前的采集数量
	unsigned short countAfterEvent;		// 事件触发以后的采集数量
	unsigned short varCount;			// 采集变量数量
	unsigned short eventCount;			// 采集事件数量
} TWatchInfo;

typedef struct  
{
	unsigned long *pAddress;
	unsigned short length;
	short fraction;
	unsigned short format;
	unsigned short hex;
	unsigned short sign;
	unsigned short bit;
} TWatchVarInfo;

typedef struct  
{
	short width;
	short precision;
	char seperator;
	short hex;
} TWatchFormat;

GT_API GT_GetWatchInfo(TWatchInfo *pInfo);
GT_API GT_GetWatchVar(short index,TWatchVar *pVar,TWatchVarInfo *pVarInfo);
GT_API GT_GetWatchEvent(short index,TWatchEvent *pEvent);
GT_API GT_SetWatchFormat(const TWatchFormat *pFormat);
GT_API GT_GetWatchFormat(TWatchFormat *pFormat);


//////////////////////////////////////////////////////////////////////////
//New Added
//////////////////////////////////////////////////////////////////////////

GT_API GT_SetUserPassword(char *pCode,short count);
GT_API GT_GetUserPassword(char *pCode,short count);

//////////////////////////////////////////////////////////////////////////
//Event and Task
//////////////////////////////////////////////////////////////////////////
#define TASK_SET_DO_BIT							(0x1101)
#define TASK_CRD_START							(0x4004)
#define TASK_CRD_STOP							(0x4005)
#define TASK_CRD_OVERRIDE						(0x4006)
#define TASK_CRD_STEP_MODE						(0x4015)
#define TASK_COMPARE_PULSE                      (0x6002)

typedef struct  
{
	short doType;
	short doIndex;
	short doValue;
	short mode;
	long parameter[8];
} TTaskSetDoBit;

typedef struct  
{
	short mask;
	short option;
} TTaskCrdStart;

typedef struct  
{
	short mask;
	short option;
} TTaskCrdStop;

typedef struct  
{
	short crd;
	double synVelOverride;
} TTaskCrdOverride;

typedef struct  
{
	short mask;
	short option;
} TTaskCrdStepMode;

typedef struct  
{
	short level;
	short outputType;
	short time;
	short reserve;
}TTaskComparePulse;

typedef struct  
{
	unsigned long loop;
	TWatchVar var;
	unsigned short condition;
	double value;
} TEvent;

GT_API GT_ClearEvent(void);
GT_API GT_ClearTask(void);
GT_API GT_ClearEventTaskLink(void);
GT_API GT_AddEvent(TEvent *pEvent,short *pEventIndex);
GT_API GT_AddTask(short taskType,void *pTaskData,short *pTaskIndex);
GT_API GT_AddEventTaskLink(short eventIndex,short taskIndex,short *pLinkIndex);
GT_API GT_GetEventCount(short *pCount);
GT_API GT_GetEvent(short eventIndex,TEvent *pEvent);
GT_API GT_GetEventLoop(short eventIndex,unsigned long *pCount);
GT_API GT_GetTaskCount(short *pCount);
GT_API GT_GetTask(short taskIndex,short *pTaskType,void *pTaskData);
GT_API GT_GetEventTaskLinkCount(short *pCount);
GT_API GT_GetEventTaskLink(short linkIndex,short *pEventIndex,short *pTaskIndex);
GT_API GT_EventOn(short eventIndex,short count);
GT_API GT_EventOff(short eventIndex,short count);
GT_API GT_BufEventOn(short crd,short eventIndex,short count,short fifo);
GT_API GT_BufEventOff(short crd,short eventIndex,short count,short fifo);

#define VAR_CALCULATE_NONE					(0)
#define VAR_CALCULATE_OR					(1)
#define VAR_CALCULATE_AND					(3)
#define VAR_CALCULATE_NOT					(5)

#define VAR_CALCULATE_ADD					(11)
#define VAR_CALCULATE_SUB					(12)
#define VAR_CALCULATE_MUL					(13)
#define VAR_CALCULATE_DIV					(14)

typedef struct  
{
	unsigned short operation;
	unsigned short varType;
	unsigned short result;
	unsigned short lhs;
	unsigned short rhs;
} TVarCalculate;

GT_API GT_ClearVar(void);
GT_API GT_SetVarBoolCondition(short varIndex,TWatchCondition *pWatchCondition);
GT_API GT_GetVarBoolCondition(short varIndex,TWatchCondition *pWatchCondition);
GT_API GT_AddVarCalculate(TVarCalculate *pVarCalculate,short *pIndex);
GT_API GT_GetVarCalculateCount(short *pCount);
GT_API GT_GetVarCalculate(short index,TVarCalculate *pVarCalculate);


typedef struct  
{
	unsigned long type;
	unsigned short index;
	unsigned short id;
} TWatchVarEx;

GT_API GT_AddWatchVarEx(const TWatchVarEx *pVar);
GT_API GT_GetDIPSwitchValue(short *pData);

#define MC_FUN_INFO_TYPE_ENCODER_SIZE       (1)                      // 需要查询的功能类型--读取编码器硬件接口位数

#define MC_FUN_INFO_TYPE_DSP_HANDWHEEL      (2)                      // 需要查询的功能类型--读取DSP是否支持手轮

#define MC_FUN_INFO_TYPE_COMMAND_EX         (100)                    // 需要查询的功能类型--是否支持大指令机制

typedef struct
{
	unsigned short resType;         // watch变量的类型
	unsigned short resIndex;        // watch变量的索引
	unsigned short resSubIndex;     // watch变量的子索引
	unsigned short resCount;        // 一次性需要读取watch变量的数量
	double resValue[256];           // 读取到的watch变量的值
} TMcVarResInfo;

GT_API GT_GetMcVarArray(short resInfoCount,TMcVarResInfo *pResInfo);