/*
 * File: ert_main.c
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
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
boolean_T isRateRunning[3] = { 0, 0, 0 };

boolean_T need2runFlags[3] = { 0, 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[3];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates
   * that need to run this time step.  The return values are 1 and 0
   * for true and false, respectively.
   */
  imu_SetEventsForThisBaseStep(eventFlags);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  imu_step0();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  isRateRunning[0]--;
  if (eventFlags[2]) {
    if (need2runFlags[2]++) {
      IsrOverrun = 1;
      need2runFlags[2]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[2]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[2]++;

#ifndef _MW_ARDUINO_LOOP_

    sei();

#endif;

    /* Step the model for subrate "2" */
    switch (2)
    {
     case 2 :
      imu_step2();

      /* Get model outputs here */
      break;

     default :
      break;
    }

#ifndef _MW_ARDUINO_LOOP_

    cli();

#endif;

    need2runFlags[2]--;
    isRateRunning[2]--;
  }

  rtExtModeCheckEndTrigger();
}

volatile boolean_T stopRequested = false;
int main(void)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 0.01;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(imu_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  imu_initialize();
  sei ();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(imu_M));
  rtExtModeCheckInit(3);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(imu_M->extModeInfo, 3, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(imu_M, true);
    }
  }

  rtERTExtModeStartMsg();
  cli();
  configureArduinoAVRTimer();
  runModel =
    (rtmGetErrorStatus(imu_M) == (NULL)) && !rtmGetStopRequested(imu_M);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei ();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(imu_M->extModeInfo, 3, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(imu_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(imu_M) == (NULL)) &&
                      !rtmGetStopRequested(imu_M));
    runModel = !(stopRequested);
    runModel = runModel && MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  imu_terminate();
  rtExtModeShutdown(3);
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
