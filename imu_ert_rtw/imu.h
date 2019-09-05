/*
 * File: imu.h
 *
 * Code generated for Simulink model 'imu'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Sep  5 22:36:15 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_imu_h_
#define RTW_HEADER_imu_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef imu_COMMON_INCLUDES_
# define imu_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_ServoWriteRead.h"
#include "MW_I2C.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* imu_COMMON_INCLUDES_ */

#include "imu_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Output;                       /* '<S2>/Output' */
  int16_T I2CRead;                     /* '<Root>/I2C Read' */
} B_imu_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_la_T obj; /* '<Root>/I2C Read' */
  codertarget_arduinobase_i_laz_T obj_n;/* '<Root>/I2C Write' */
  codertarget_arduinobase_int_l_T obj_j;/* '<Root>/Standard Servo Write' */
  codertarget_arduinobase_block_T obj_b;/* '<S1>/Digital Output' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_imu_T;

/* Parameters (default storage) */
struct P_imu_T_ {
  real_T RepeatingSequence_rep_seq_y[3];/* Mask Parameter: RepeatingSequence_rep_seq_y
                                         * Referenced by: '<S2>/Look-Up Table1'
                                         */
  real_T I2CRead_SampleTime;           /* Expression: 0.1
                                        * Referenced by: '<Root>/I2C Read'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T Constant_Value_g;             /* Expression: period
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T LookUpTable1_bp01Data[3];     /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S2>/Look-Up Table1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_imu_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_imu_T imu_P;

/* Block signals (default storage) */
extern B_imu_T imu_B;

/* Block states (default storage) */
extern DW_imu_T imu_DW;

/* External function called from main */
extern void imu_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void imu_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void imu_initialize(void);
extern void imu_step0(void);
extern void imu_step2(void);
extern void imu_terminate(void);

/* Real-time Model object */
extern RT_MODEL_imu_T *const imu_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'imu'
 * '<S1>'   : 'imu/Digital Output'
 * '<S2>'   : 'imu/Repeating Sequence'
 */
#endif                                 /* RTW_HEADER_imu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
