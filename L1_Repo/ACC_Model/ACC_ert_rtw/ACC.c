/*
 * File: ACC.c
 *
 * Code generated for Simulink model 'ACC'.
 *
 * Model version                  : 1.366
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat Jul 11 12:50:24 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACC.h"
#include "rtwtypes.h"
#include "ACC_private.h"
#include "ACC_types.h"
#include <math.h>

/* Named constants for Chart: '<Root>/ACC' */
#define ACC_Dist_Hyst                  (5.0F)
#define ACC_IN_ACC_Active              ((uint8_T)1U)
#define ACC_IN_ACC_Active_Follow       ((uint8_T)2U)
#define ACC_IN_ACC_Fault               ((uint8_T)3U)
#define ACC_IN_ACC_Off                 ((uint8_T)4U)
#define ACC_IN_ACC_Override            ((uint8_T)5U)
#define ACC_IN_ACC_Standby             ((uint8_T)6U)
#define ACC_IN_ACC_Stop_Hold           ((uint8_T)7U)

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
static real_T ACC_HMI_Distance_Bars(void);
static void ACC_ACC_Active(void);
static void ACC_ACC_Active_Follow(const uint8_T *HMI_Bar);
static void ACC_ACC_Standby(void);

/* Function for Chart: '<Root>/ACC' */
static real_T ACC_HMI_Distance_Bars(void)
{
  real_T HMI_Bars;

  /* Inport: '<Root>/Dist_Rel' */
  if ((ACC_U.Dist_Rel <= 3.5F) && (ACC_U.Dist_Rel > 2.5F)) {
    HMI_Bars = 1.0;
  } else if ((ACC_U.Dist_Rel <= 2.5F) && (ACC_U.Dist_Rel > 1.5F)) {
    HMI_Bars = 2.0;
  } else if ((ACC_U.Dist_Rel <= 1.5F) && (ACC_U.Dist_Rel > 0.75F)) {
    HMI_Bars = 3.0;
  } else if ((ACC_U.Dist_Rel <= 0.75F) && (ACC_U.Dist_Rel > 0.0F)) {
    HMI_Bars = 4.0;
  } else {
    HMI_Bars = 0.0;
  }

  /* End of Inport: '<Root>/Dist_Rel' */
  return HMI_Bars;
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

/* Function for Chart: '<Root>/ACC' */
static void ACC_ACC_Active(void)
{
  /* Outport: '<Root>/ACC_State' */
  ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Active;

  /* Outport: '<Root>/Torque_Request_Status' */
  ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Longi;

  /* Outport: '<Root>/HMI_ACC_ICON' */
  ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Green;

  /* Outport: '<Root>/Audible_Warning' */
  ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Single_Beep;

  /* Outport: '<Root>/Internal_Control_Mode' */
  ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Speedctrl;

  /* Inport: '<Root>/Acc_pedal_Pos' incorporates:
   *  Inport: '<Root>/Engine_Torque_Unavailable'
   *  Inport: '<Root>/Measured_Distance'
   *  Inport: '<Root>/Radar_Signal_Blocked'
   *  Inport: '<Root>/Safety_Time_Gap'
   *  Inport: '<Root>/Target_Detected'
   *  Inport: '<Root>/V_ego'
   *  Outport: '<Root>/Button_Status'
   */
  if (ACC_U.Acc_pedal_Pos > 15) {
    ACC_B.Loc_flag = false;
    ACC_DW.is_ACC_States = ACC_IN_ACC_Override;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Override;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Override;

    /* Outport: '<Root>/HMI_ACC_ICON' */
    ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Blink_Green;

    /* Outport: '<Root>/Audible_Warning' */
    ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Chime;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Passive;
  } else if (ACC_U.Target_Detected && (ACC_U.Measured_Distance < 0.278F *
              (real32_T)ACC_U.V_ego * ACC_U.Safety_Time_Gap)) {
    ACC_B.Loc_flag = false;
    ACC_DW.is_ACC_States = ACC_IN_ACC_Active_Follow;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Active_Follow;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Dis_active;

    /* Outport: '<Root>/HMI_SetSpeed' incorporates:
     *  Outport: '<Root>/V_set'
     */
    ACC_Y.HMI_SetSpeed = ACC_Y.V_set;

    /* Outport: '<Root>/Audible_Warning' */
    ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_None;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Distctrl;
  } else if (ACC_Y.Button_Status == Dt_Enum_Button_Status_E_Cancel) {
    ACC_B.Loc_flag = false;
    ACC_DW.is_ACC_States = ACC_IN_ACC_Standby;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Standby;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Standby;

    /* Outport: '<Root>/HMI_ACC_ICON' */
    ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_White;

    /* Outport: '<Root>/HMI_SetSpeed' incorporates:
     *  Outport: '<Root>/V_set'
     */
    ACC_Y.HMI_SetSpeed = ACC_Y.V_set;

    /* Outport: '<Root>/Audible_Warning' */
    ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_None;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Monitoring;
  } else if (ACC_U.Radar_Signal_Blocked || ACC_U.Engine_Torque_Unavailable) {
    ACC_B.Loc_flag = false;
    ACC_DW.is_ACC_States = ACC_IN_ACC_Fault;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Fault;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Fault;

    /* Outport: '<Root>/HMI_ACC_ICON' */
    ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Red;

    /* Outport: '<Root>/Audible_Warning' */
    ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Loud_Chime;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Error;
  }

  /* End of Inport: '<Root>/Acc_pedal_Pos' */
}

/* Function for Chart: '<Root>/ACC' */
static void ACC_ACC_Active_Follow(const uint8_T *HMI_Bar)
{
  /* Outport: '<Root>/ACC_State' */
  ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Active_Follow;

  /* Outport: '<Root>/Torque_Request_Status' */
  ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Dis_active;

  /* Outport: '<Root>/HMI_ACC_ICON' */
  ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Green;

  /* Outport: '<Root>/Audible_Warning' */
  ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_None;

  /* Outport: '<Root>/Internal_Control_Mode' */
  ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Distctrl;

  /* Inport: '<Root>/Target_Detected' incorporates:
   *  Inport: '<Root>/AEB_Intervention_Active'
   *  Inport: '<Root>/Acc_pedal_Pos'
   *  Inport: '<Root>/Brake_Pedal'
   *  Inport: '<Root>/Dist_Rel'
   *  Inport: '<Root>/Fusion_Confidence'
   *  Inport: '<Root>/Lane_Width'
   *  Inport: '<Root>/Measured_Distance'
   *  Inport: '<Root>/Safety_Time_Gap'
   *  Inport: '<Root>/Target_Lateral_Offset'
   *  Inport: '<Root>/V_Lead'
   *  Inport: '<Root>/V_ego'
   *  Outport: '<Root>/Button_Status'
   */
  if ((!ACC_U.Target_Detected) || (ACC_U.Target_Lateral_Offset >
       ACC_U.Lane_Width) || (ACC_U.Measured_Distance > 0.278F * (real32_T)
       ACC_U.V_ego * ACC_U.Safety_Time_Gap + ACC_Dist_Hyst)) {
    ACC_B.Loc_flag = true;
    ACC_DW.is_ACC_States = ACC_IN_ACC_Active;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Active;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Longi;

    /* Outport: '<Root>/HMI_SetSpeed' incorporates:
     *  Outport: '<Root>/V_set'
     */
    ACC_Y.HMI_SetSpeed = ACC_Y.V_set;

    /* Outport: '<Root>/Audible_Warning' */
    ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Single_Beep;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Speedctrl;
  } else if ((ACC_U.V_ego < 1) && (ACC_U.V_Lead == 0) && (ACC_U.Dist_Rel < 3.5F))
  {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Stop_Hold;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Stop_Hold;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Hold_Req;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Standstill;
  } else if (ACC_U.Acc_pedal_Pos > 15) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Override;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Override;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Override;

    /* Outport: '<Root>/HMI_ACC_ICON' */
    ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Blink_Green;

    /* Outport: '<Root>/Audible_Warning' */
    ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Chime;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Passive;
  } else if ((ACC_U.Brake_Pedal == Dt_Enum_Brk_Pedal_E_Pedal_Pressed) ||
             (ACC_Y.Button_Status == Dt_Enum_Button_Status_E_Cancel)) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Standby;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Standby;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Standby;

    /* Outport: '<Root>/HMI_ACC_ICON' */
    ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_White;

    /* Outport: '<Root>/HMI_SetSpeed' incorporates:
     *  Outport: '<Root>/V_set'
     */
    ACC_Y.HMI_SetSpeed = ACC_Y.V_set;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Monitoring;
  } else if (((ACC_U.Fusion_Confidence > 0) && (ACC_U.Fusion_Confidence < 40)) ||
             ACC_U.AEB_Intervention_Active) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Fault;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Fault;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Fault;

    /* Outport: '<Root>/HMI_ACC_ICON' */
    ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Red;

    /* Outport: '<Root>/Audible_Warning' */
    ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Loud_Chime;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Error;
  } else {
    /* Outport: '<Root>/HMI_Distance' */
    ACC_Y.HMI_Distance = *HMI_Bar;
  }

  /* End of Inport: '<Root>/Target_Detected' */
}

/* Function for Chart: '<Root>/ACC' */
static void ACC_ACC_Standby(void)
{
  boolean_T tmp;

  /* Outport: '<Root>/ACC_State' */
  ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Standby;

  /* Outport: '<Root>/Torque_Request_Status' */
  ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Standby;

  /* Outport: '<Root>/HMI_ACC_ICON' */
  ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_White;

  /* Outport: '<Root>/Audible_Warning' */
  ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_None;

  /* Outport: '<Root>/Internal_Control_Mode' */
  ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Monitoring;

  /* Inport: '<Root>/V_ego' incorporates:
   *  Inport: '<Root>/Brake_Pedal'
   */
  tmp = (((ACC_Y.Button_Status == Dt_Enum_Button_Status_E_Set) ||
          (ACC_Y.Button_Status == Dt_Enum_Button_Status_E_Resume)) &&
         (ACC_U.V_ego >= 30) && (ACC_U.Brake_Pedal ==
          Dt_Enum_Brk_Pedal_E_Pedal_Released));

  /* Inport: '<Root>/Target_Detected' incorporates:
   *  Inport: '<Root>/ACC_Master_Switch'
   *  Inport: '<Root>/CAN_Bus_Error'
   *  Inport: '<Root>/Ignition_Status'
   *  Inport: '<Root>/Sensor_Alignment_Lost'
   */
  if (tmp && (!ACC_U.Target_Detected)) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Active;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Active;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Longi;

    /* Outport: '<Root>/HMI_ACC_ICON' */
    ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Green;

    /* Outport: '<Root>/HMI_SetSpeed' incorporates:
     *  Outport: '<Root>/V_set'
     */
    ACC_Y.HMI_SetSpeed = ACC_Y.V_set;

    /* Outport: '<Root>/Audible_Warning' */
    ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Single_Beep;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Speedctrl;
  } else if (tmp && ACC_U.Target_Detected) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Active_Follow;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Active_Follow;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Dis_active;

    /* Outport: '<Root>/HMI_ACC_ICON' */
    ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Green;

    /* Outport: '<Root>/HMI_SetSpeed' incorporates:
     *  Outport: '<Root>/V_set'
     */
    ACC_Y.HMI_SetSpeed = ACC_Y.V_set;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Distctrl;
  } else if ((ACC_U.Ignition_Status == Dt_Enum_Ignition_Status_E_Ign_Off) ||
             (ACC_U.ACC_Master_Switch == Dt_Enum_ACC_Master_Switch_E_Switch_Off))
  {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Off;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Off;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Disabled;

    /* Outport: '<Root>/HMI_ACC_ICON' */
    ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Off;

    /* Outport: '<Root>/HMI_SetSpeed' */
    ACC_Y.HMI_SetSpeed = 0U;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Standstill;
  } else if (ACC_U.CAN_Bus_Error || ACC_U.Sensor_Alignment_Lost) {
    ACC_DW.is_ACC_States = ACC_IN_ACC_Fault;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Fault;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Fault;

    /* Outport: '<Root>/HMI_ACC_ICON' */
    ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Red;

    /* Outport: '<Root>/Audible_Warning' */
    ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Loud_Chime;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Error;
  }

  /* End of Inport: '<Root>/Target_Detected' */
}

/* Model step function */
void ACC_step(void)
{
  real_T tmp_0;
  uint8_T tmp;
  boolean_T tmp_1;

  /* Chart: '<Root>/Button_Status_State' incorporates:
   *  Inport: '<Root>/Button_Status_Raw'
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  if ((ACC_U.Button_Status_Raw == 1.0) || ACC_DW.UnitDelay1_DSTATE) {
    /* Chart: '<Root>/V_set_Cal' incorporates:
     *  Outport: '<Root>/Button_Status'
     */
    ACC_Y.Button_Status = Dt_Enum_Button_Status_E_Set;
  }

  if (ACC_U.Button_Status_Raw == 2.0) {
    /* Chart: '<Root>/V_set_Cal' incorporates:
     *  Outport: '<Root>/Button_Status'
     */
    ACC_Y.Button_Status = Dt_Enum_Button_Status_E_Cancel;
  }

  if (ACC_U.Button_Status_Raw == 3.0) {
    /* Chart: '<Root>/V_set_Cal' incorporates:
     *  Outport: '<Root>/Button_Status'
     */
    ACC_Y.Button_Status = Dt_Enum_Button_Status_E_Resume;
  }

  if ((ACC_U.Button_Status_Raw != 1.0) && (ACC_U.Button_Status_Raw != 2.0) &&
      (ACC_U.Button_Status_Raw != 3.0) && (ACC_U.Ignition_Status !=
       Dt_Enum_Ignition_Status_E_Ign_Run)) {
    /* Chart: '<Root>/V_set_Cal' incorporates:
     *  Outport: '<Root>/Button_Status'
     */
    ACC_Y.Button_Status = Dt_Enum_Button_Status_E_None;
  }

  /* End of Chart: '<Root>/Button_Status_State' */

  /* Chart: '<Root>/V_set_Cal' incorporates:
   *  Inport: '<Root>/Target_Detected'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  if (ACC_Y.Button_Status == Dt_Enum_Button_Status_E_Set) {
    if (ACC_U.Target_Detected) {
      /* Outport: '<Root>/V_set' incorporates:
       *  Inport: '<Root>/V_Lead'
       */
      ACC_Y.V_set = ACC_U.V_Lead;
    } else {
      /* Outport: '<Root>/V_set' incorporates:
       *  Inport: '<Root>/V_ego'
       */
      ACC_Y.V_set = ACC_U.V_ego;
    }
  }

  if (ACC_Y.Button_Status == Dt_Enum_Button_Status_E_Resume) {
    if (ACC_DW.UnitDelay_DSTATE == 0) {
      /* Outport: '<Root>/V_set' incorporates:
       *  Inport: '<Root>/V_ego'
       */
      ACC_Y.V_set = ACC_U.V_ego;
    } else {
      /* Outport: '<Root>/V_set' */
      ACC_Y.V_set = ACC_DW.UnitDelay_DSTATE;
    }
  }

  if (ACC_Y.Button_Status == Dt_Enum_Button_Status_E_Cancel) {
    /* Outport: '<Root>/V_set' incorporates:
     *  UnitDelay: '<Root>/Unit Delay'
     */
    ACC_Y.V_set = ACC_DW.UnitDelay_DSTATE;
  }

  if (ACC_Y.Button_Status == Dt_Enum_Button_Status_E_None) {
    /* Outport: '<Root>/V_set' */
    ACC_Y.V_set = MAX_uint8_T;
  }

  /* Chart: '<Root>/ACC' incorporates:
   *  Inport: '<Root>/ACC_Master_Switch'
   *  Inport: '<Root>/Acc_pedal_Pos'
   *  Inport: '<Root>/Brake_Pedal'
   *  Inport: '<Root>/Dist_Rel'
   *  Inport: '<Root>/Driver_Door_open'
   *  Inport: '<Root>/Electronic_Parking_Brake_Failure'
   *  Inport: '<Root>/Pedal_Sensor_Signal_Plausibility_Error'
   *  Inport: '<Root>/Seatbelt_Unlocked'
   *  Inport: '<Root>/Target_Detected'
   *  Inport: '<Root>/V_Lead'
   */
  if (ACC_DW.is_active_c3_ACC == 0) {
    ACC_DW.is_active_c3_ACC = 1U;
    ACC_DW.is_ACC_States = ACC_IN_ACC_Off;

    /* Outport: '<Root>/ACC_State' */
    ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Off;

    /* Outport: '<Root>/Torque_Request_Status' */
    ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Disabled;

    /* Outport: '<Root>/HMI_ACC_ICON' */
    ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Off;

    /* Outport: '<Root>/HMI_SetSpeed' */
    ACC_Y.HMI_SetSpeed = 0U;

    /* Outport: '<Root>/Audible_Warning' */
    ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_None;

    /* Outport: '<Root>/Internal_Control_Mode' */
    ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Standstill;
  } else {
    tmp_0 = rt_roundd_snf(ACC_HMI_Distance_Bars());
    if (tmp_0 < 256.0) {
      if (tmp_0 >= 0.0) {
        tmp = (uint8_T)tmp_0;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    switch (ACC_DW.is_ACC_States) {
     case ACC_IN_ACC_Active:
      ACC_ACC_Active();
      break;

     case ACC_IN_ACC_Active_Follow:
      ACC_ACC_Active_Follow(&tmp);
      break;

     case ACC_IN_ACC_Fault:
      /* Outport: '<Root>/ACC_State' */
      ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Fault;

      /* Outport: '<Root>/Torque_Request_Status' */
      ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Fault;

      /* Outport: '<Root>/HMI_ACC_ICON' */
      ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Red;

      /* Outport: '<Root>/Audible_Warning' */
      ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Loud_Chime;

      /* Outport: '<Root>/Internal_Control_Mode' */
      ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Error;
      if ((ACC_U.Ignition_Status == Dt_Enum_Ignition_Status_E_Ign_Off) ||
          (ACC_U.ACC_Master_Switch == Dt_Enum_ACC_Master_Switch_E_Switch_Off)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Off;

        /* Outport: '<Root>/ACC_State' */
        ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Off;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Disabled;

        /* Outport: '<Root>/HMI_ACC_ICON' */
        ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Off;

        /* Outport: '<Root>/HMI_SetSpeed' */
        ACC_Y.HMI_SetSpeed = 0U;

        /* Outport: '<Root>/Audible_Warning' */
        ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_None;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Standstill;
      }
      break;

     case ACC_IN_ACC_Off:
      /* Outport: '<Root>/ACC_State' */
      ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Off;

      /* Outport: '<Root>/Torque_Request_Status' */
      ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Disabled;

      /* Outport: '<Root>/HMI_ACC_ICON' */
      ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Off;

      /* Outport: '<Root>/Audible_Warning' */
      ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_None;

      /* Outport: '<Root>/Internal_Control_Mode' */
      ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Standstill;
      tmp_1 = ((ACC_U.Ignition_Status == Dt_Enum_Ignition_Status_E_Ign_Run) &&
               (ACC_U.ACC_Master_Switch == Dt_Enum_ACC_Master_Switch_E_Switch_On));
      if (tmp_1 && (ACC_U.POST_Status == Dt_Enum_POST_Status_E_Success)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Standby;

        /* Outport: '<Root>/ACC_State' */
        ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Standby;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Standby;

        /* Outport: '<Root>/HMI_ACC_ICON' */
        ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_White;

        /* Outport: '<Root>/HMI_SetSpeed' incorporates:
         *  Outport: '<Root>/V_set'
         */
        ACC_Y.HMI_SetSpeed = ACC_Y.V_set;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Monitoring;
      } else if (tmp_1 && (ACC_U.POST_Status == Dt_Enum_POST_Status_E_Failed)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Fault;

        /* Outport: '<Root>/ACC_State' */
        ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Fault;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Fault;

        /* Outport: '<Root>/HMI_ACC_ICON' */
        ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Red;

        /* Outport: '<Root>/Audible_Warning' */
        ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Loud_Chime;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Error;
      }
      break;

     case ACC_IN_ACC_Override:
      /* Outport: '<Root>/ACC_State' */
      ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Override;

      /* Outport: '<Root>/Torque_Request_Status' */
      ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Override;

      /* Outport: '<Root>/HMI_ACC_ICON' */
      ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Blink_Green;

      /* Outport: '<Root>/Audible_Warning' */
      ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Chime;

      /* Outport: '<Root>/Internal_Control_Mode' */
      ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Passive;
      if (ACC_U.Pedal_Sensor_Signal_Plausibilit) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Fault;

        /* Outport: '<Root>/ACC_State' */
        ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Fault;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Fault;

        /* Outport: '<Root>/HMI_ACC_ICON' */
        ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Red;

        /* Outport: '<Root>/Audible_Warning' */
        ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Loud_Chime;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Error;
      } else if ((ACC_U.Brake_Pedal == Dt_Enum_Brk_Pedal_E_Pedal_Pressed) ||
                 (ACC_Y.Button_Status == Dt_Enum_Button_Status_E_Cancel)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Standby;

        /* Outport: '<Root>/ACC_State' */
        ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Standby;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Standby;

        /* Outport: '<Root>/HMI_ACC_ICON' */
        ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_White;

        /* Outport: '<Root>/HMI_SetSpeed' incorporates:
         *  Outport: '<Root>/V_set'
         */
        ACC_Y.HMI_SetSpeed = ACC_Y.V_set;

        /* Outport: '<Root>/Audible_Warning' */
        ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_None;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Monitoring;
      } else if (ACC_U.Acc_pedal_Pos < 5) {
        if (ACC_U.Target_Detected) {
          ACC_DW.is_ACC_States = ACC_IN_ACC_Active_Follow;

          /* Outport: '<Root>/ACC_State' */
          ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Active_Follow;

          /* Outport: '<Root>/Torque_Request_Status' */
          ACC_Y.Torque_Request_Status =
            Dt_Enum_Torque_Request_Status_E_Dis_active;

          /* Outport: '<Root>/HMI_ACC_ICON' */
          ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Green;

          /* Outport: '<Root>/HMI_SetSpeed' incorporates:
           *  Outport: '<Root>/V_set'
           */
          ACC_Y.HMI_SetSpeed = ACC_Y.V_set;

          /* Outport: '<Root>/Audible_Warning' */
          ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_None;

          /* Outport: '<Root>/Internal_Control_Mode' */
          ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Distctrl;
        } else {
          ACC_DW.is_ACC_States = ACC_IN_ACC_Active;

          /* Outport: '<Root>/ACC_State' */
          ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Active;

          /* Outport: '<Root>/Torque_Request_Status' */
          ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Longi;

          /* Outport: '<Root>/HMI_ACC_ICON' */
          ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Green;

          /* Outport: '<Root>/HMI_SetSpeed' incorporates:
           *  Outport: '<Root>/V_set'
           */
          ACC_Y.HMI_SetSpeed = ACC_Y.V_set;

          /* Outport: '<Root>/Audible_Warning' */
          ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Single_Beep;

          /* Outport: '<Root>/Internal_Control_Mode' */
          ACC_Y.Internal_Control_Mode =
            Dt_Enum_Internal_Control_Mode_E_Speedctrl;
        }
      }
      break;

     case ACC_IN_ACC_Standby:
      ACC_ACC_Standby();
      break;

     default:
      /* Outport: '<Root>/ACC_State' */
      /* case IN_ACC_Stop_Hold: */
      ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Stop_Hold;

      /* Outport: '<Root>/Torque_Request_Status' */
      ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Hold_Req;

      /* Outport: '<Root>/HMI_ACC_ICON' */
      ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Green;

      /* Outport: '<Root>/Audible_Warning' */
      ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_None;

      /* Outport: '<Root>/Internal_Control_Mode' */
      ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Standstill;
      if ((ACC_U.V_Lead > 5) && (ACC_U.Dist_Rel > 3.5F)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Active_Follow;

        /* Outport: '<Root>/ACC_State' */
        ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Active_Follow;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Dis_active;

        /* Outport: '<Root>/HMI_SetSpeed' incorporates:
         *  Outport: '<Root>/V_set'
         */
        ACC_Y.HMI_SetSpeed = ACC_Y.V_set;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Distctrl;
      } else if (ACC_U.Driver_Door_open || ACC_U.Seatbelt_Unlocked ||
                 (ACC_U.Brake_Pedal == Dt_Enum_Brk_Pedal_E_Pedal_Pressed)) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Standby;

        /* Outport: '<Root>/ACC_State' */
        ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Standby;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Standby;

        /* Outport: '<Root>/HMI_ACC_ICON' */
        ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_White;

        /* Outport: '<Root>/HMI_SetSpeed' incorporates:
         *  Outport: '<Root>/V_set'
         */
        ACC_Y.HMI_SetSpeed = ACC_Y.V_set;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Monitoring;
      } else if (ACC_U.Electronic_Parking_Brake_Failur) {
        ACC_DW.is_ACC_States = ACC_IN_ACC_Fault;

        /* Outport: '<Root>/ACC_State' */
        ACC_Y.ACC_State = Dt_Enum_ACC_State_E_ACC_Fault;

        /* Outport: '<Root>/Torque_Request_Status' */
        ACC_Y.Torque_Request_Status = Dt_Enum_Torque_Request_Status_E_Fault;

        /* Outport: '<Root>/HMI_ACC_ICON' */
        ACC_Y.HMI_ACC_ICON = Dt_Enum_HMI_ACC_ICON_E_Red;

        /* Outport: '<Root>/Audible_Warning' */
        ACC_Y.Audible_Warning = Dt_Enum_Audible_Warning_E_Warn_Loud_Chime;

        /* Outport: '<Root>/Internal_Control_Mode' */
        ACC_Y.Internal_Control_Mode = Dt_Enum_Internal_Control_Mode_E_Error;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/ACC' */

  /* Update for UnitDelay: '<Root>/Unit Delay1' */
  ACC_DW.UnitDelay1_DSTATE = ACC_B.Loc_flag;

  /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
   *  Outport: '<Root>/V_set'
   */
  ACC_DW.UnitDelay_DSTATE = ACC_Y.V_set;
}

/* Model initialize function */
void ACC_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void ACC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
