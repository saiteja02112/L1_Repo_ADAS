/*
 * File: ACC.h
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

#ifndef ACC_h_
#define ACC_h_
#ifndef ACC_COMMON_INCLUDES_
#define ACC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* ACC_COMMON_INCLUDES_ */

#include "ACC_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T Loc_flag;                  /* '<Root>/ACC' */
} B_ACC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T UnitDelay_DSTATE;            /* '<Root>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<Root>/Unit Delay1' */
  uint8_T is_active_c3_ACC;            /* '<Root>/ACC' */
  uint8_T is_ACC_States;               /* '<Root>/ACC' */
} DW_ACC_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Button_Status_Raw;            /* '<Root>/Button_Status_Raw' */
  Dt_Enum_ACC_Master_Switch_E ACC_Master_Switch;/* '<Root>/ACC_Master_Switch' */
  boolean_T AEB_Intervention_Active;   /* '<Root>/AEB_Intervention_Active' */
  uint8_T Acc_pedal_Pos;               /* '<Root>/Acc_pedal_Pos' */
  Dt_Enum_Brk_Pedal_E Brake_Pedal;     /* '<Root>/Brake_Pedal' */
  boolean_T CAN_Bus_Error;             /* '<Root>/CAN_Bus_Error' */
  real32_T Dist_Rel;                   /* '<Root>/Dist_Rel' */
  boolean_T Driver_Door_open;          /* '<Root>/Driver_Door_open' */
  boolean_T Electronic_Parking_Brake_Failur;
                                 /* '<Root>/Electronic_Parking_Brake_Failure' */
  boolean_T Engine_Torque_Unavailable; /* '<Root>/Engine_Torque_Unavailable' */
  uint8_T Fusion_Confidence;           /* '<Root>/Fusion_Confidence' */
  Dt_Enum_Ignition_Status_E Ignition_Status;/* '<Root>/Ignition_Status' */
  uint16_T Lane_Width;                 /* '<Root>/Lane_Width' */
  real32_T Measured_Distance;          /* '<Root>/Measured_Distance' */
  Dt_Enum_POST_Status_E POST_Status;   /* '<Root>/POST_Status' */
  boolean_T Pedal_Sensor_Signal_Plausibilit;
                           /* '<Root>/Pedal_Sensor_Signal_Plausibility_Error' */
  boolean_T Radar_Signal_Blocked;      /* '<Root>/Radar_Signal_Blocked' */
  boolean_T Target_Detected;           /* '<Root>/Target_Detected' */
  boolean_T Seatbelt_Unlocked;         /* '<Root>/Seatbelt_Unlocked' */
  boolean_T Sensor_Alignment_Lost;     /* '<Root>/Sensor_Alignment_Lost' */
  uint16_T Target_Lateral_Offset;      /* '<Root>/Target_Lateral_Offset' */
  uint8_T V_Lead;                      /* '<Root>/V_Lead' */
  uint8_T V_ego;                       /* '<Root>/V_ego' */
  real32_T Safety_Time_Gap;            /* '<Root>/Safety_Time_Gap' */
} ExtU_ACC_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  Dt_Enum_Audible_Warning_E Audible_Warning;/* '<Root>/Audible_Warning' */
  Dt_Enum_HMI_ACC_ICON_E HMI_ACC_ICON; /* '<Root>/HMI_ACC_ICON' */
  uint8_T HMI_SetSpeed;                /* '<Root>/HMI_SetSpeed' */
  Dt_Enum_Torque_Request_Status_E Torque_Request_Status;/* '<Root>/Torque_Request_Status' */
  Dt_Enum_Internal_Control_Mode_E Internal_Control_Mode;/* '<Root>/Internal_Control_Mode' */
  uint8_T HMI_Distance;                /* '<Root>/HMI_Distance' */
  Dt_Enum_ACC_State_E ACC_State;       /* '<Root>/ACC_State' */
  Dt_Enum_Button_Status_E Button_Status;/* '<Root>/Button_Status' */
  uint8_T V_set;                       /* '<Root>/V_set' */
} ExtY_ACC_T;

/* Real-time Model Data Structure */
struct tag_RTM_ACC_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_ACC_T ACC_B;

/* Block states (default storage) */
extern DW_ACC_T ACC_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_ACC_T ACC_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ACC_T ACC_Y;

/* Model entry point functions */
extern void ACC_initialize(void);
extern void ACC_step(void);
extern void ACC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ACC_T *const ACC_M;

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
 * '<Root>' : 'ACC'
 * '<S1>'   : 'ACC/ACC'
 * '<S2>'   : 'ACC/Button_Status_State'
 * '<S3>'   : 'ACC/V_set_Cal'
 */
#endif                                 /* ACC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
