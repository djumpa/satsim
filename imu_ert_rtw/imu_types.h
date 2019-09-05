/*
 * File: imu_types.h
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

#ifndef RTW_HEADER_imu_types_h_
#define RTW_HEADER_imu_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Custom Type definition for MATLABSystem: '<Root>/I2C Write' */
#include "MW_SVD.h"
#include <stddef.h>
#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} codertarget_arduinobase_block_T;

#endif                                 /*typedef_codertarget_arduinobase_block_T*/

#ifndef typedef_cell_imu_T
#define typedef_cell_imu_T

typedef struct {
  char_T f1;
  char_T f2;
  char_T f3;
  char_T f4;
  char_T f5;
  char_T f6;
  char_T f7;
  char_T f8;
  char_T f9[2];
  char_T f10[2];
  char_T f11[2];
  char_T f12[2];
} cell_imu_T;

#endif                                 /*typedef_cell_imu_T*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  cell_imu_T AvailablePwmPinNames;
} codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

#ifndef typedef_codertarget_arduinobase_int_l_T
#define typedef_codertarget_arduinobase_int_l_T

typedef struct {
  int32_T isInitialized;
  codertarget_arduinobase_inter_T Hw;
} codertarget_arduinobase_int_l_T;

#endif                                 /*typedef_codertarget_arduinobase_int_l_T*/

#ifndef typedef_codertarget_arduinobase_in_la_T
#define typedef_codertarget_arduinobase_in_la_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_arduinobase_inter_T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
  real_T SampleTime;
} codertarget_arduinobase_in_la_T;

#endif                                 /*typedef_codertarget_arduinobase_in_la_T*/

#ifndef typedef_codertarget_arduinobase_i_laz_T
#define typedef_codertarget_arduinobase_i_laz_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_arduinobase_inter_T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
} codertarget_arduinobase_i_laz_T;

#endif                                 /*typedef_codertarget_arduinobase_i_laz_T*/

/* Parameters (default storage) */
typedef struct P_imu_T_ P_imu_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_imu_T RT_MODEL_imu_T;

#endif                                 /* RTW_HEADER_imu_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
