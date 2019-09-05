/*
 * File: imu.c
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

#include "imu.h"
#include "imu_private.h"
#include "imu_dt.h"

/* Block signals (default storage) */
B_imu_T imu_B;

/* Block states (default storage) */
DW_imu_T imu_DW;

/* Real-time model */
RT_MODEL_imu_T imu_M_;
RT_MODEL_imu_T *const imu_M = &imu_M_;

/* Forward declaration for local functions */
static void imu_SystemCore_release_l(const codertarget_arduinobase_i_laz_T *obj);
static void imu_SystemCore_delete_l(const codertarget_arduinobase_i_laz_T *obj);
static void matlabCodegenHandle_matlabCod_l(codertarget_arduinobase_i_laz_T *obj);
static void matlabCodegenHandle_matlabCo_la(codertarget_arduinobase_block_T *obj);
static void imu_SystemCore_release(const codertarget_arduinobase_in_la_T *obj);
static void imu_SystemCore_delete(const codertarget_arduinobase_in_la_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_in_la_T *obj);
static codertarget_arduinobase_i_laz_T *arduinoI2CWrite_arduinoI2CWrite
  (codertarget_arduinobase_i_laz_T *obj);
static codertarget_arduinobase_in_la_T *i_arduinoI2CRead_arduinoI2CRead
  (codertarget_arduinobase_in_la_T *obj);
static void rate_monotonic_scheduler(void);
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1UL;
    frac = (u0 - bp0[maxIndex - 1UL]) / (bp0[maxIndex] - bp0[maxIndex - 1UL]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1UL] - table[iLeft]) * frac + table[iLeft];
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void imu_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(imu_M, 2));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (imu_M->Timing.TaskCounters.TID[2])++;
  if ((imu_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    imu_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (rtIsNaN(u0) || rtIsInf(u0) || (rtIsNaN(u1) || rtIsInf(u1))) {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = fabs(u0 / u1);
      if (fabs(u1_0 - floor(u1_0 + 0.5)) <= DBL_EPSILON * u1_0) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void imu_SystemCore_release_l(const codertarget_arduinobase_i_laz_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    MW_I2C_Close(obj->MW_I2C_HANDLE);
  }
}

static void imu_SystemCore_delete_l(const codertarget_arduinobase_i_laz_T *obj)
{
  imu_SystemCore_release_l(obj);
}

static void matlabCodegenHandle_matlabCod_l(codertarget_arduinobase_i_laz_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    imu_SystemCore_delete_l(obj);
  }
}

static void matlabCodegenHandle_matlabCo_la(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void imu_SystemCore_release(const codertarget_arduinobase_in_la_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    MW_I2C_Close(obj->MW_I2C_HANDLE);
  }
}

static void imu_SystemCore_delete(const codertarget_arduinobase_in_la_T *obj)
{
  imu_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_in_la_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    imu_SystemCore_delete(obj);
  }
}

static codertarget_arduinobase_i_laz_T *arduinoI2CWrite_arduinoI2CWrite
  (codertarget_arduinobase_i_laz_T *obj)
{
  codertarget_arduinobase_i_laz_T *b_obj;
  obj->isInitialized = 0L;
  b_obj = obj;
  obj->Hw.AvailablePwmPinNames.f1 = '2';
  obj->Hw.AvailablePwmPinNames.f2 = '3';
  obj->Hw.AvailablePwmPinNames.f3 = '4';
  obj->Hw.AvailablePwmPinNames.f4 = '5';
  obj->Hw.AvailablePwmPinNames.f5 = '6';
  obj->Hw.AvailablePwmPinNames.f6 = '7';
  obj->Hw.AvailablePwmPinNames.f7 = '8';
  obj->Hw.AvailablePwmPinNames.f8 = '9';
  obj->Hw.AvailablePwmPinNames.f9[0] = '1';
  obj->Hw.AvailablePwmPinNames.f9[1] = '0';
  obj->Hw.AvailablePwmPinNames.f10[0] = '1';
  obj->Hw.AvailablePwmPinNames.f10[1] = '1';
  obj->Hw.AvailablePwmPinNames.f11[0] = '1';
  obj->Hw.AvailablePwmPinNames.f11[1] = '2';
  obj->Hw.AvailablePwmPinNames.f12[0] = '1';
  obj->Hw.AvailablePwmPinNames.f12[1] = '3';
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static codertarget_arduinobase_in_la_T *i_arduinoI2CRead_arduinoI2CRead
  (codertarget_arduinobase_in_la_T *obj)
{
  codertarget_arduinobase_in_la_T *b_obj;
  obj->isInitialized = 0L;
  b_obj = obj;
  obj->Hw.AvailablePwmPinNames.f1 = '2';
  obj->Hw.AvailablePwmPinNames.f2 = '3';
  obj->Hw.AvailablePwmPinNames.f3 = '4';
  obj->Hw.AvailablePwmPinNames.f4 = '5';
  obj->Hw.AvailablePwmPinNames.f5 = '6';
  obj->Hw.AvailablePwmPinNames.f6 = '7';
  obj->Hw.AvailablePwmPinNames.f7 = '8';
  obj->Hw.AvailablePwmPinNames.f8 = '9';
  obj->Hw.AvailablePwmPinNames.f9[0] = '1';
  obj->Hw.AvailablePwmPinNames.f9[1] = '0';
  obj->Hw.AvailablePwmPinNames.f10[0] = '1';
  obj->Hw.AvailablePwmPinNames.f10[1] = '1';
  obj->Hw.AvailablePwmPinNames.f11[0] = '1';
  obj->Hw.AvailablePwmPinNames.f11[1] = '2';
  obj->Hw.AvailablePwmPinNames.f12[0] = '1';
  obj->Hw.AvailablePwmPinNames.f12[1] = '3';
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/* Model step function for TID0 */
void imu_step0(void)                   /* Sample time: [0.0s, 0.0s] */
{
  uint8_T SwappedDataBytes[8];
  uint8_T b_SwappedDataBytes[9];
  uint8_T xtmp;
  real_T rtb_PulseGenerator;
  int16_T i;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<Root>/I2C Write' incorporates:
   *  Constant: '<Root>/Constant'
   */
  memcpy((void *)&SwappedDataBytes[0], (void *)&imu_P.Constant_Value, (uint16_T)
         ((size_t)8 * sizeof(uint8_T)));
  xtmp = SwappedDataBytes[0];
  SwappedDataBytes[0] = SwappedDataBytes[7];
  SwappedDataBytes[7] = xtmp;
  xtmp = SwappedDataBytes[1];
  SwappedDataBytes[1] = SwappedDataBytes[6];
  SwappedDataBytes[6] = xtmp;
  xtmp = SwappedDataBytes[2];
  SwappedDataBytes[2] = SwappedDataBytes[5];
  SwappedDataBytes[5] = xtmp;
  xtmp = SwappedDataBytes[3];
  SwappedDataBytes[3] = SwappedDataBytes[4];
  SwappedDataBytes[4] = xtmp;
  memcpy((void *)&rtb_PulseGenerator, (void *)&SwappedDataBytes[0], (uint16_T)
         ((size_t)1 * sizeof(real_T)));
  memcpy((void *)&SwappedDataBytes[0], (void *)&rtb_PulseGenerator, (uint16_T)
         ((size_t)8 * sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 107U;
  for (i = 0; i < 8; i++) {
    b_SwappedDataBytes[i + 1] = SwappedDataBytes[i];
  }

  MW_I2C_MasterWrite(imu_DW.obj_n.MW_I2C_HANDLE, 104UL, b_SwappedDataBytes, 9UL,
                     false, false);

  /* End of MATLABSystem: '<Root>/I2C Write' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (imu_DW.clockTickCounter < imu_P.PulseGenerator_Duty) &&
    (imu_DW.clockTickCounter >= 0L) ? imu_P.PulseGenerator_Amp : 0.0;
  if (imu_DW.clockTickCounter >= imu_P.PulseGenerator_Period - 1.0) {
    imu_DW.clockTickCounter = 0L;
  } else {
    imu_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      xtmp = (uint8_T)rtb_PulseGenerator;
    } else {
      xtmp = 0U;
    }
  } else {
    xtmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* MATLABSystem: '<S1>/Digital Output' */
  writeDigitalPin(13, xtmp);

  /* SignalConversion: '<S2>/Output' incorporates:
   *  Clock: '<S2>/Clock'
   *  Constant: '<S2>/Constant'
   *  Lookup_n-D: '<S2>/Look-Up Table1'
   *  Math: '<S2>/Math Function'
   *  S-Function (sfun_tstart): '<S2>/startTime'
   *  Sum: '<S2>/Sum'
   */
  imu_B.Output = look1_binlxpw(rt_remd_snf(imu_M->Timing.t[0] - (0.0),
    imu_P.Constant_Value_g), imu_P.LookUpTable1_bp01Data,
    imu_P.RepeatingSequence_rep_seq_y, 2UL);

  /* MATLABSystem: '<Root>/Standard Servo Write' */
  if (imu_B.Output < 0.0) {
    xtmp = 0U;
  } else if (imu_B.Output > 180.0) {
    xtmp = 180U;
  } else {
    rtb_PulseGenerator = rt_roundd_snf(imu_B.Output);
    if (rtb_PulseGenerator < 256.0) {
      if (rtb_PulseGenerator >= 0.0) {
        xtmp = (uint8_T)rtb_PulseGenerator;
      } else {
        xtmp = 0U;
      }
    } else {
      xtmp = MAX_uint8_T;
    }
  }

  MW_servoWrite(0, xtmp);

  /* End of MATLABSystem: '<Root>/Standard Servo Write' */

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(1, (real_T)imu_M->Timing.t[0]);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(imu_M)!=-1) &&
        !((rtmGetTFinal(imu_M)-imu_M->Timing.t[0]) > imu_M->Timing.t[0] *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(imu_M, "Simulation finished");
    }

    if (rtmGetStopRequested(imu_M)) {
      rtmSetErrorStatus(imu_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  imu_M->Timing.t[0] =
    (++imu_M->Timing.clockTick0) * imu_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  imu_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void imu_step2(void)                   /* Sample time: [0.1s, 0.0s] */
{
  int16_T b_output;
  uint8_T status;
  uint8_T output_raw[2];
  uint8_T b_x[2];

  /* MATLABSystem: '<Root>/I2C Read' */
  if (imu_DW.obj.SampleTime != imu_P.I2CRead_SampleTime) {
    imu_DW.obj.SampleTime = imu_P.I2CRead_SampleTime;
  }

  status = 59U;
  status = MW_I2C_MasterWrite(imu_DW.obj.MW_I2C_HANDLE, 104UL, &status, 1UL,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(imu_DW.obj.MW_I2C_HANDLE, 104UL, output_raw, 2UL, false,
                      true);
    memcpy((void *)&b_output, (void *)&output_raw[0], (uint16_T)((size_t)1 *
            sizeof(int16_T)));
    memcpy((void *)&output_raw[0], (void *)&b_output, (uint16_T)((size_t)2 *
            sizeof(uint8_T)));
    b_x[0] = output_raw[1];
    b_x[1] = output_raw[0];
    memcpy((void *)&imu_B.I2CRead, (void *)&b_x[0], (uint16_T)((size_t)1 *
            sizeof(int16_T)));
  } else {
    imu_B.I2CRead = 0;
  }

  /* End of MATLABSystem: '<Root>/I2C Read' */
  rtExtModeUpload(2, (real_T)((imu_M->Timing.clockTick2) * 0.1));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  imu_M->Timing.clockTick2++;
}

/* Model initialize function */
void imu_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)imu_M, 0,
                sizeof(RT_MODEL_imu_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&imu_M->solverInfo, &imu_M->Timing.simTimeStep);
    rtsiSetTPtr(&imu_M->solverInfo, &rtmGetTPtr(imu_M));
    rtsiSetStepSizePtr(&imu_M->solverInfo, &imu_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&imu_M->solverInfo, (&rtmGetErrorStatus(imu_M)));
    rtsiSetRTModelPtr(&imu_M->solverInfo, imu_M);
  }

  rtsiSetSimTimeStep(&imu_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&imu_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(imu_M, &imu_M->Timing.tArray[0]);
  rtmSetTFinal(imu_M, 30.0);
  imu_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  imu_M->Sizes.checksums[0] = (2826718340U);
  imu_M->Sizes.checksums[1] = (3919948710U);
  imu_M->Sizes.checksums[2] = (3000767184U);
  imu_M->Sizes.checksums[3] = (396567706U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    imu_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(imu_M->extModeInfo,
      &imu_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(imu_M->extModeInfo, imu_M->Sizes.checksums);
    rteiSetTPtr(imu_M->extModeInfo, rtmGetTPtr(imu_M));
  }

  /* block I/O */
  (void) memset(((void *) &imu_B), 0,
                sizeof(B_imu_T));

  /* states (dwork) */
  (void) memset((void *)&imu_DW, 0,
                sizeof(DW_imu_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    imu_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_i_laz_T *obj;
    uint32_T i2cname;
    codertarget_arduinobase_in_la_T *obj_0;
    codertarget_arduinobase_int_l_T *obj_1;

    /* Start for MATLABSystem: '<Root>/I2C Write' */
    imu_DW.obj_n.matlabCodegenIsDeleted = true;
    arduinoI2CWrite_arduinoI2CWrite(&imu_DW.obj_n);
    obj = &imu_DW.obj_n;
    imu_DW.obj_n.isSetupComplete = false;
    imu_DW.obj_n.isInitialized = 1L;
    i2cname = 0;
    obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
    imu_DW.obj_n.BusSpeed = 100000UL;
    MW_I2C_SetBusSpeed(imu_DW.obj_n.MW_I2C_HANDLE, imu_DW.obj_n.BusSpeed);
    imu_DW.obj_n.isSetupComplete = true;

    /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
    imu_DW.clockTickCounter = 0L;

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    imu_DW.obj_b.matlabCodegenIsDeleted = true;
    imu_DW.obj_b.isInitialized = 0L;
    imu_DW.obj_b.matlabCodegenIsDeleted = false;
    imu_DW.obj_b.isSetupComplete = false;
    imu_DW.obj_b.isInitialized = 1L;
    digitalIOSetup(13, true);
    imu_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/I2C Read' */
    imu_DW.obj.matlabCodegenIsDeleted = true;
    i_arduinoI2CRead_arduinoI2CRead(&imu_DW.obj);
    imu_DW.obj.SampleTime = imu_P.I2CRead_SampleTime;
    obj_0 = &imu_DW.obj;
    imu_DW.obj.isSetupComplete = false;
    imu_DW.obj.isInitialized = 1L;
    i2cname = 0;
    obj_0->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
    imu_DW.obj.BusSpeed = 100000UL;
    MW_I2C_SetBusSpeed(imu_DW.obj.MW_I2C_HANDLE, imu_DW.obj.BusSpeed);
    imu_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Standard Servo Write' */
    obj_1 = &imu_DW.obj_j;
    imu_DW.obj_j.isInitialized = 0L;
    obj_1->Hw.AvailablePwmPinNames.f1 = '2';
    obj_1->Hw.AvailablePwmPinNames.f2 = '3';
    obj_1->Hw.AvailablePwmPinNames.f3 = '4';
    obj_1->Hw.AvailablePwmPinNames.f4 = '5';
    obj_1->Hw.AvailablePwmPinNames.f5 = '6';
    obj_1->Hw.AvailablePwmPinNames.f6 = '7';
    obj_1->Hw.AvailablePwmPinNames.f7 = '8';
    obj_1->Hw.AvailablePwmPinNames.f8 = '9';
    obj_1->Hw.AvailablePwmPinNames.f9[0] = '1';
    obj_1->Hw.AvailablePwmPinNames.f9[1] = '0';
    obj_1->Hw.AvailablePwmPinNames.f10[0] = '1';
    obj_1->Hw.AvailablePwmPinNames.f10[1] = '1';
    obj_1->Hw.AvailablePwmPinNames.f11[0] = '1';
    obj_1->Hw.AvailablePwmPinNames.f11[1] = '2';
    obj_1->Hw.AvailablePwmPinNames.f12[0] = '1';
    obj_1->Hw.AvailablePwmPinNames.f12[1] = '3';
    imu_DW.obj_j.isInitialized = 1L;
    MW_servoAttach(0, 2);
  }
}

/* Model terminate function */
void imu_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/I2C Write' */
  matlabCodegenHandle_matlabCod_l(&imu_DW.obj_n);

  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  matlabCodegenHandle_matlabCo_la(&imu_DW.obj_b);

  /* Terminate for MATLABSystem: '<Root>/I2C Read' */
  matlabCodegenHandle_matlabCodeg(&imu_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
