/*
 * File: imu_data.c
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

/* Block parameters (default storage) */
P_imu_T imu_P = {
  /* Mask Parameter: RepeatingSequence_rep_seq_y
   * Referenced by: '<S2>/Look-Up Table1'
   */
  { 45.0, 135.0, 45.0 },

  /* Expression: 0.1
   * Referenced by: '<Root>/I2C Read'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<Root>/Pulse Generator'
   */
  100.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<Root>/Pulse Generator'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Expression: period
   * Referenced by: '<S2>/Constant'
   */
  0.5,

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S2>/Look-Up Table1'
   */
  { 0.0, 0.25, 0.5 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
