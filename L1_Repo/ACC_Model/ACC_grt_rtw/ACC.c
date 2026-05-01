/*
 * ACC.c
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
#include "rtwtypes.h"
#include "ACC_private.h"
#include "ACC_types.h"
#include <string.h>

/* Named constants for Chart: '<Root>/ACC' */
#define ACC_IN_ACC_Active              ((uint8_T)1U)
#define ACC_IN_ACC_Active_Follow       ((uint8_T)2U)
#define ACC_IN_ACC_Fault               ((uint8_T)3U)
#define ACC_IN_ACC_Off                 ((uint8_T)4U)
#define ACC_IN_ACC_Override            ((uint8_T)5U)
#define ACC_IN_ACC_Stanby              ((uint8_T)6U)
#define ACC_IN_ACC_Stop_Hold           ((uint8_T)7U)
#define ACC_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Block signals (default storage) */
B_ACC_T ACC_B;

/* Block states (default storage) */
DW_ACC_T ACC_DW;

/* External inputs (root inport signals with default storage) */
ExtU_ACC_T ACC_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ACC_T ACC_Y;

/* Real-time model */
static RT_MODEL_ACC_T ACC_M_;
RT_MODEL_ACC_T *const ACC_M = &ACC_M_;

/* Forward declaration for local functions */
static void ACC_ACC_Active_Follow(void);
static void ACC_ACC_Stanby(void);

/* System initialize for function-call system: '<S1>/Acc_req' */
void ACC_Acc_req_Init(B_Acc_req_ACC_T *localB, P_Acc_req_ACC_T *localP)
{
  /* SystemInitialize for MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
   *  Outport: '<S4>/Acceleration_request'
   */
  localB->MultiportSwitch = localP->Acceleration_request_Y0;
}

/* Output and update for function-call system: '<S1>/Acc_req' */
void ACC_Acc_req(real_T rtu_ACC_Status, B_Acc_req_ACC_T *localB, P_Acc_req_ACC_T
                 *localP)
{
  /* MultiPortSwitch: '<S4>/Multiport Switch' */
  switch ((int32_T)rtu_ACC_Status) {
   case 0:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Constant: '<S4>/Constant2'
     */
    localB->MultiportSwitch = localP->Constant2_Value;
    break;

   case 1:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Constant: '<S4>/Constant4'
     */
    localB->MultiportSwitch = localP->Constant4_Value;
    break;

   case 2:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    localB->MultiportSwitch = localP->Constant1_Value;
    break;

   case 3:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Constant: '<S4>/Constant7'
     */
    localB->MultiportSwitch = localP->Constant7_Value;
    break;

   case 4:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Constant: '<S4>/Constant6'
     */
    localB->MultiportSwitch = localP->Constant6_Value;
    break;

   case 5:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Constant: '<S4>/Constant5'
     */
    localB->MultiportSwitch = localP->Constant5_Value;
    break;

   case 6:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Constant: '<S4>/Constant3'
     */
    localB->MultiportSwitch = localP->Constant3_Value;
    break;

   default:
    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Constant: '<S4>/Constant2'
     */
    localB->MultiportSwitch = localP->Constant2_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch' */
}

/* Function for Chart: '<Root>/ACC' */
static void ACC_ACC_Active_Follow(void)
{
  /* Inport: '<Root>/Target_Detected' incorporates:
   *  Inport: '<Root>/AEB_Intervention_Active'
   *  Inport: '<Root>/Acc_pedal_Pos'
   *  Inport: '<Root>/Brake_Pedal'
   *  Inport: '<Root>/Dist_Rel'
   *  Inport: '<Root>/Fusion_Confidence'
   *  Inport: '<Root>/Lane_Width'
   *  Inport: '<Root>/Target_Lateral_Offset'
   *  Inport: '<Root>/V_Lead'
   *  Inport: '<Root>/V_ego'
   *  Outport: '<Root>/Button_Status'
   */
  if ((!ACC_U.Target_Detected) || (ACC_U.Target_Lateral_Offset >
       ACC_U.Lane_Width)) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Active;
    ACC_DW.ACC_Status = 3.0;
  } else if ((ACC_U.V_ego < 1) && (ACC_U.V_Lead == 0) && (ACC_U.Dist_Rel < 3.5))
  {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Stop_Hold;
    ACC_DW.ACC_Status = 5.0;
  } else if (ACC_U.Acc_pedal_Pos > 15) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Override;
    ACC_DW.ACC_Status = 6.0;
  } else if ((ACC_U.Brake_Pedal == Dt_Enum_Pedal_E_PRESSED) ||
             (ACC_Y.Button_Status == CANCEL)) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Stanby;
    ACC_DW.ACC_Status = 1.0;
  } else if (((ACC_U.Fusion_Confidence > 0) && (ACC_U.Fusion_Confidence < 40)) ||
             ACC_U.AEB_Intervention_Active) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Fault;
    ACC_DW.ACC_Status = 2.0;
  } else {
    ACC_B.ACC_Status = ACC_DW.ACC_Status;

    /* Outputs for Function Call SubSystem: '<S1>/Acc_req' */
    ACC_Acc_req(ACC_B.ACC_Status, &ACC_B.Acc_req, &ACC_P.Acc_req);

    /* End of Outputs for SubSystem: '<S1>/Acc_req' */

    /* Outport: '<Root>/Acceleration_Request' */
    ACC_Y.Acceleration_Request = ACC_B.Acc_req.MultiportSwitch;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dis_active;

    /* Outport: '<Root>/HMI_ACC_ICON' */
    ACC_Y.HMI_ACC_ICON = Green;

    /* Outport: '<Root>/HMI_SetSpeed' */
    ACC_Y.HMI_SetSpeed = ACC_B.V_set;

    /* SystemInitialize for Outport: '<Root>/HMI_Distance' */
    ACC_Y.HMI_Distance = 1U;

    /* Outport: '<Root>/Audible_Warning' */
    ACC_Y.Audible_Warning = None;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Distctrl;
  }

  /* End of Inport: '<Root>/Target_Detected' */
}

/* Function for Chart: '<Root>/ACC' */
static void ACC_ACC_Stanby(void)
{
  /* Outport: '<Root>/Button_Status' incorporates:
   *  Inport: '<Root>/ACC_Master_Switch'
   *  Inport: '<Root>/Brake_Pedal'
   *  Inport: '<Root>/CAN_Bus_Error'
   *  Inport: '<Root>/Ignition_Status'
   *  Inport: '<Root>/Sensor_Alignment_Lost'
   *  Inport: '<Root>/Target_Detected'
   *  Inport: '<Root>/V_ego'
   *  Outport: '<Root>/Acceleration_Request'
   *  Outport: '<Root>/Audible_Warning'
   *  Outport: '<Root>/HMI_ACC_ICON'
   *  Outport: '<Root>/HMI_SetSpeed'
   *  Outport: '<Root>/Internal_Control_Mode'
   *  Outport: '<Root>/Torque_Request_Status'
   */
  if (((ACC_Y.Button_Status == SET) || (ACC_Y.Button_Status == RESUME)) &&
      (ACC_U.V_ego >= 30) && (ACC_U.Brake_Pedal == Dt_Enum_Pedal_E_RELEASED) &&
      (!ACC_U.Target_Detected)) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Active;
    ACC_DW.ACC_Status = 3.0;
  } else if (((ACC_Y.Button_Status == SET) || (ACC_Y.Button_Status == RESUME)) &&
             (ACC_U.V_ego >= 30) && (ACC_U.Brake_Pedal ==
              Dt_Enum_Pedal_E_RELEASED) && ACC_U.Target_Detected) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Active_Follow;
    ACC_DW.ACC_Status = 4.0;
  } else if ((ACC_U.Ignition_Status == Dt_Enum_Ignition_Status_E_OFF) ||
             (ACC_U.ACC_Master_Switch == Dt_Enum_ACC_Master_Switch_E_OFF)) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Off;
    ACC_DW.ACC_Status = 0.0;
  } else if (ACC_U.CAN_Bus_Error || ACC_U.Sensor_Alignment_Lost) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Fault;
    ACC_DW.ACC_Status = 2.0;
  } else {
    ACC_B.ACC_Status = ACC_DW.ACC_Status;

    /* Outputs for Function Call SubSystem: '<S1>/Acc_req' */
    ACC_Acc_req(ACC_B.ACC_Status, &ACC_B.Acc_req, &ACC_P.Acc_req);

    /* End of Outputs for SubSystem: '<S1>/Acc_req' */
    ACC_Y.Acceleration_Request = ACC_B.Acc_req.MultiportSwitch;
    ACC_Y.Torque_Request_Status = Standby;
    ACC_Y.HMI_ACC_ICON = White;
    ACC_Y.HMI_SetSpeed = ACC_B.V_set;
    ACC_Y.Audible_Warning = None;
    ACC_Y.Internal_Control_Mode = Monitoring;
  }

  /* End of Outport: '<Root>/Button_Status' */
}

/* Model step function */
void ACC_step(void)
{
  /* Chart: '<Root>/Button_Status_State' incorporates:
   *  Inport: '<Root>/Button_Status_Raw'
   */
  if (ACC_U.Button_Status_Raw == 1.0) {
    /* Outport: '<Root>/Button_Status' */
    ACC_Y.Button_Status = SET;
  }

  if (ACC_U.Button_Status_Raw == 2.0) {
    /* Outport: '<Root>/Button_Status' */
    ACC_Y.Button_Status = CANCEL;
  }

  if (ACC_U.Button_Status_Raw == 3.0) {
    /* Outport: '<Root>/Button_Status' */
    ACC_Y.Button_Status = RESUME;
  }

  if ((ACC_U.Button_Status_Raw != 1.0) && (ACC_U.Button_Status_Raw != 2.0) &&
      (ACC_U.Button_Status_Raw != 3.0)) {
    /* Outport: '<Root>/Button_Status' */
    ACC_Y.Button_Status = NONE;
  }

  /* End of Chart: '<Root>/Button_Status_State' */

  /* Chart: '<Root>/V_set_Cal' incorporates:
   *  Inport: '<Root>/V_ego'
   *  Outport: '<Root>/Button_Status'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  if (ACC_Y.Button_Status == SET) {
    ACC_B.V_set = ACC_U.V_ego;
  }

  if (ACC_Y.Button_Status == RESUME) {
    ACC_B.V_set = ACC_DW.UnitDelay_DSTATE;
  }

  /* End of Chart: '<Root>/V_set_Cal' */

  /* Chart: '<Root>/ACC' incorporates:
   *  Inport: '<Root>/ACC_Master_Switch'
   *  Inport: '<Root>/Acc_pedal_Pos'
   *  Inport: '<Root>/Brake_Pedal'
   *  Inport: '<Root>/Dist_Rel'
   *  Inport: '<Root>/Driver_Door_open'
   *  Inport: '<Root>/Electronic_Parking_Brake_Failure'
   *  Inport: '<Root>/Engine_Torque_Unavailable'
   *  Inport: '<Root>/Ignition_Status'
   *  Inport: '<Root>/Measured_Distance'
   *  Inport: '<Root>/POST_Status'
   *  Inport: '<Root>/Pedal_Sensor_Signal_Plausibility_Error'
   *  Inport: '<Root>/Radar_Signal_Blocked'
   *  Inport: '<Root>/Safety_Time_Gap'
   *  Inport: '<Root>/Seatbelt_Unlocked'
   *  Inport: '<Root>/Target_Detected'
   *  Inport: '<Root>/V_Lead'
   *  Outport: '<Root>/Button_Status'
   */
  if (ACC_DW.is_active_c3_ACC == 0) {
    ACC_DW.is_active_c3_ACC = 1U;
    ACC_DW.is_ACC_States = ACC_IN_ACC_Off;
    ACC_DW.ACC_Status = 0.0;
  } else {
    switch (ACC_DW.is_ACC_States) {
     case ACC_IN_ACC_Active:
      if (ACC_U.Acc_pedal_Pos > 15) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Override;
        ACC_DW.ACC_Status = 6.0;
      } else if (ACC_U.Target_Detected && (ACC_U.Measured_Distance <
                  ACC_U.Safety_Time_Gap)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Active_Follow;
        ACC_DW.ACC_Status = 4.0;
      } else if (ACC_Y.Button_Status == CANCEL) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Stanby;
        ACC_DW.ACC_Status = 1.0;
      } else if (ACC_U.Radar_Signal_Blocked || ACC_U.Engine_Torque_Unavailable)
      {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Fault;
        ACC_DW.ACC_Status = 2.0;
      } else {
        ACC_B.ACC_Status = ACC_DW.ACC_Status;

        /* Outputs for Function Call SubSystem: '<S1>/Acc_req' */
        ACC_Acc_req(ACC_B.ACC_Status, &ACC_B.Acc_req, &ACC_P.Acc_req);

        /* End of Outputs for SubSystem: '<S1>/Acc_req' */

        /* Outport: '<Root>/Acceleration_Request' */
        ACC_Y.Acceleration_Request = ACC_B.Acc_req.MultiportSwitch;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Longi;

        /* Outport: '<Root>/HMI_ACC_ICON' */
        ACC_Y.HMI_ACC_ICON = Green;

        /* Outport: '<Root>/HMI_SetSpeed' */
        ACC_Y.HMI_SetSpeed = ACC_B.V_set;

        /* Outport: '<Root>/Audible_Warning' */
        ACC_Y.Audible_Warning = Single_Beep;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Speedctrl;
      }
      break;

     case ACC_IN_ACC_Active_Follow:
      ACC_ACC_Active_Follow();
      break;

     case ACC_IN_ACC_Fault:
      if ((ACC_U.Ignition_Status == Dt_Enum_Ignition_Status_E_OFF) ||
          (ACC_U.ACC_Master_Switch == Dt_Enum_ACC_Master_Switch_E_OFF)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Off;
        ACC_DW.ACC_Status = 0.0;
      } else {
        ACC_B.ACC_Status = ACC_DW.ACC_Status;

        /* Outputs for Function Call SubSystem: '<S1>/Acc_req' */
        ACC_Acc_req(ACC_B.ACC_Status, &ACC_B.Acc_req, &ACC_P.Acc_req);

        /* End of Outputs for SubSystem: '<S1>/Acc_req' */

        /* Outport: '<Root>/Acceleration_Request' */
        ACC_Y.Acceleration_Request = ACC_B.Acc_req.MultiportSwitch;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Fault;

        /* Outport: '<Root>/HMI_ACC_ICON' */
        ACC_Y.HMI_ACC_ICON = Red;

        /* Outport: '<Root>/Audible_Warning' */
        ACC_Y.Audible_Warning = Loud_Chime;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Error;
      }
      break;

     case ACC_IN_ACC_Off:
      if ((ACC_U.Ignition_Status == Dt_Enum_Ignition_Status_E_RUN) &&
          (ACC_U.ACC_Master_Switch == Dt_Enum_ACC_Master_Switch_E_ON) &&
          (ACC_U.POST_Status == Dt_Enum_POST_Status_E_SUCCESS)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Stanby;
        ACC_DW.ACC_Status = 1.0;
      } else if ((ACC_U.Ignition_Status == Dt_Enum_Ignition_Status_E_RUN) &&
                 (ACC_U.ACC_Master_Switch == Dt_Enum_ACC_Master_Switch_E_ON) &&
                 (ACC_U.POST_Status == Dt_Enum_POST_Status_E_FAILED)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Fault;
        ACC_DW.ACC_Status = 2.0;
      } else {
        ACC_B.ACC_Status = ACC_DW.ACC_Status;

        /* Outputs for Function Call SubSystem: '<S1>/Acc_req' */
        ACC_Acc_req(ACC_B.ACC_Status, &ACC_B.Acc_req, &ACC_P.Acc_req);

        /* End of Outputs for SubSystem: '<S1>/Acc_req' */

        /* Outport: '<Root>/Acceleration_Request' */
        ACC_Y.Acceleration_Request = ACC_B.Acc_req.MultiportSwitch;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Disabled;

        /* Outport: '<Root>/HMI_ACC_ICON' */
        ACC_Y.HMI_ACC_ICON = Off;

        /* Outport: '<Root>/HMI_SetSpeed' */
        ACC_Y.HMI_SetSpeed = 0U;

        /* Outport: '<Root>/Audible_Warning' */
        ACC_Y.Audible_Warning = None;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Standstill;
      }
      break;

     case ACC_IN_ACC_Override:
      if ((ACC_U.Acc_pedal_Pos < 5) && ACC_U.Target_Detected) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Active_Follow;
        ACC_DW.ACC_Status = 4.0;
      } else if ((ACC_U.Acc_pedal_Pos < 5) && (!ACC_U.Target_Detected)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Active;
        ACC_DW.ACC_Status = 3.0;
      } else if (((ACC_U.Brake_Pedal == Dt_Enum_Pedal_E_PRESSED) ||
                  (ACC_Y.Button_Status == CANCEL)) && ((ACC_U.Brake_Pedal ==
                   Dt_Enum_Pedal_E_PRESSED) || (ACC_Y.Button_Status == CANCEL)))
      {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Stanby;
        ACC_DW.ACC_Status = 1.0;
      } else if (ACC_U.Pedal_Sensor_Signal_Plausibilit) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Fault;
        ACC_DW.ACC_Status = 2.0;
      } else {
        ACC_B.ACC_Status = ACC_DW.ACC_Status;

        /* Outputs for Function Call SubSystem: '<S1>/Acc_req' */
        ACC_Acc_req(ACC_B.ACC_Status, &ACC_B.Acc_req, &ACC_P.Acc_req);

        /* End of Outputs for SubSystem: '<S1>/Acc_req' */

        /* Outport: '<Root>/Acceleration_Request' */
        ACC_Y.Acceleration_Request = ACC_B.Acc_req.MultiportSwitch;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Override;

        /* Outport: '<Root>/HMI_ACC_ICON' */
        ACC_Y.HMI_ACC_ICON = Blink_Green;

        /* Outport: '<Root>/Audible_Warning' */
        ACC_Y.Audible_Warning = Chime;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Passive;
      }
      break;

     case ACC_IN_ACC_Stanby:
      ACC_ACC_Stanby();
      break;

     default:
      /* case IN_ACC_Stop_Hold: */
      if ((ACC_U.V_Lead > 5) && (ACC_U.Dist_Rel > 3.5)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Active_Follow;
        ACC_DW.ACC_Status = 4.0;
      } else if (ACC_U.Driver_Door_open || ACC_U.Seatbelt_Unlocked ||
                 (ACC_U.Brake_Pedal == Dt_Enum_Pedal_E_PRESSED)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Stanby;
        ACC_DW.ACC_Status = 1.0;
      } else if (ACC_U.Electronic_Parking_Brake_Failur) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Fault;
        ACC_DW.ACC_Status = 2.0;
      } else {
        ACC_B.ACC_Status = ACC_DW.ACC_Status;

        /* Outputs for Function Call SubSystem: '<S1>/Acc_req' */
        ACC_Acc_req(ACC_B.ACC_Status, &ACC_B.Acc_req, &ACC_P.Acc_req);

        /* End of Outputs for SubSystem: '<S1>/Acc_req' */

        /* Outport: '<Root>/Acceleration_Request' */
        ACC_Y.Acceleration_Request = ACC_B.Acc_req.MultiportSwitch;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Hold_Req;

        /* Outport: '<Root>/HMI_ACC_ICON' */
        ACC_Y.HMI_ACC_ICON = Green;

        /* Outport: '<Root>/Audible_Warning' */
        ACC_Y.Audible_Warning = None;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Standstill;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/ACC' */

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  ACC_DW.UnitDelay_DSTATE = ACC_B.V_set;

  /* Matfile logging */
  rt_UpdateTXYLogVars(ACC_M->rtwLogInfo, (&ACC_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(ACC_M)!=-1) &&
        !((rtmGetTFinal(ACC_M)-ACC_M->Timing.taskTime0) >
          ACC_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ACC_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ACC_M->Timing.clockTick0)) {
    ++ACC_M->Timing.clockTickH0;
  }

  ACC_M->Timing.taskTime0 = ACC_M->Timing.clockTick0 * ACC_M->Timing.stepSize0 +
    ACC_M->Timing.clockTickH0 * ACC_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void ACC_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ACC_M, 0,
                sizeof(RT_MODEL_ACC_T));
  rtmSetTFinal(ACC_M, 10.0);
  ACC_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    ACC_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ACC_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ACC_M->rtwLogInfo, (NULL));
    rtliSetLogT(ACC_M->rtwLogInfo, "tout");
    rtliSetLogX(ACC_M->rtwLogInfo, "");
    rtliSetLogXFinal(ACC_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ACC_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ACC_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(ACC_M->rtwLogInfo, 0);
    rtliSetLogDecimation(ACC_M->rtwLogInfo, 1);
    rtliSetLogY(ACC_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ACC_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ACC_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &ACC_B), 0,
                sizeof(B_ACC_T));

  /* states (dwork) */
  (void) memset((void *)&ACC_DW, 0,
                sizeof(DW_ACC_T));

  /* external inputs */
  (void)memset(&ACC_U, 0, sizeof(ExtU_ACC_T));

  /* external outputs */
  (void)memset(&ACC_Y, 0, sizeof(ExtY_ACC_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(ACC_M->rtwLogInfo, 0.0, rtmGetTFinal(ACC_M),
    ACC_M->Timing.stepSize0, (&rtmGetErrorStatus(ACC_M)));

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  ACC_DW.UnitDelay_DSTATE = ACC_P.UnitDelay_InitialCondition;

  /* SystemInitialize for Outport: '<Root>/Button_Status' incorporates:
   *  Chart: '<Root>/Button_Status_State'
   */
  ACC_Y.Button_Status = NONE;

  /* SystemInitialize for Chart: '<Root>/V_set_Cal' */
  ACC_B.V_set = 0U;

  /* SystemInitialize for Outport: '<Root>/Acceleration_Request' */
  ACC_Y.Acceleration_Request = 0.0;

  /* SystemInitialize for Outport: '<Root>/Audible_Warning' */
  ACC_Y.Audible_Warning = None;

  /* SystemInitialize for Outport: '<Root>/HMI_ACC_ICON' */
  ACC_Y.HMI_ACC_ICON = Off;

  /* SystemInitialize for Outport: '<Root>/HMI_SetSpeed' */
  ACC_Y.HMI_SetSpeed = 0U;

  /* SystemInitialize for Outport: '<Root>/Torque_Request_Status' */
  ACC_Y.Torque_Request_Status = Disabled;

  /* SystemInitialize for Outport: '<Root>/Internal_Control_Mode' */
  ACC_Y.Internal_Control_Mode = Standstill;

  /* SystemInitialize for Outport: '<Root>/HMI_Distance' */
  ACC_Y.HMI_Distance = 0U;
  ACC_DW.ACC_Status = 0.0;
  ACC_DW.is_active_c3_ACC = 0U;
  ACC_DW.is_ACC_States = ACC_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<Root>/ACC' incorporates:
   *  SubSystem: '<S1>/Acc_req'
   */
  ACC_Acc_req_Init(&ACC_B.Acc_req, &ACC_P.Acc_req);
}

/* Model terminate function */
void ACC_terminate(void)
{
  /* (no terminate code required) */
}
