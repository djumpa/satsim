/*
 * imu_dt.h
 *
 * Code generation for model "imu".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Thu Sep  5 22:36:15 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(codertarget_arduinobase_block_T),
  sizeof(codertarget_arduinobase_in_la_T),
  sizeof(codertarget_arduinobase_i_laz_T),
  sizeof(codertarget_arduinobase_int_l_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "codertarget_arduinobase_block_T",
  "codertarget_arduinobase_in_la_T",
  "codertarget_arduinobase_i_laz_T",
  "codertarget_arduinobase_int_l_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&imu_B.Output), 0, 0, 1 },

  { (char_T *)(&imu_B.I2CRead), 4, 0, 1 }
  ,

  { (char_T *)(&imu_DW.obj), 15, 0, 1 },

  { (char_T *)(&imu_DW.obj_n), 16, 0, 1 },

  { (char_T *)(&imu_DW.obj_j), 17, 0, 1 },

  { (char_T *)(&imu_DW.obj_b), 14, 0, 1 },

  { (char_T *)(&imu_DW.Scope1_PWORK.LoggedData), 11, 0, 2 },

  { (char_T *)(&imu_DW.clockTickCounter), 6, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&imu_P.RepeatingSequence_rep_seq_y[0]), 0, 0, 13 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] imu_dt.h */
