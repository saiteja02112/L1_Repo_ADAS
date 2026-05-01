/*
 * ACC_private.h
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

#ifndef ACC_private_h_
#define ACC_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "ACC.h"
#include "ACC_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void ACC_Acc_req_Init(B_Acc_req_ACC_T *localB, P_Acc_req_ACC_T *localP);
extern void ACC_Acc_req(real_T rtu_ACC_Status, B_Acc_req_ACC_T *localB,
  P_Acc_req_ACC_T *localP);

#endif                                 /* ACC_private_h_ */
