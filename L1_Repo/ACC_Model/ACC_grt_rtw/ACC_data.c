/*
 * ACC_data.c
 *
 * Code generation for model "ACC".
 *
 * Model version              : 1.168
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Sun May  3 21:31:53 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACC.h"

/* Block parameters (default storage) */
P_ACC_T ACC_P = {
  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<Root>/Unit Delay'
   */
  0U,

  /* Start of '<S1>/Acc_req' */
  {
    /* Expression: 0
     * Referenced by: '<S4>/Constant4'
     */
    0.0,

    /* Expression: 3
     * Referenced by: '<S4>/Constant1'
     */
    3.0,

    /* Expression: 2
     * Referenced by: '<S4>/Constant7'
     */
    2.0,

    /* Expression: 1
     * Referenced by: '<S4>/Constant6'
     */
    1.0,

    /* Expression: -2.5
     * Referenced by: '<S4>/Constant5'
     */
    -2.5,

    /* Expression: 0
     * Referenced by: '<S4>/Constant3'
     */
    0.0,

    /* Computed Parameter: Acceleration_request_Y0
     * Referenced by: '<S4>/Acceleration_request'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S4>/Constant2'
     */
    0.0
  }
  /* End of '<S1>/Acc_req' */
};
