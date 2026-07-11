/*
 * File: ACC_types.h
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

#ifndef ACC_types_h_
#define ACC_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_ACC_Master_Switch_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_ACC_Master_Switch_E_

typedef uint8_T Dt_Enum_ACC_Master_Switch_E;

/* enum Dt_Enum_ACC_Master_Switch_E */
#define Dt_Enum_ACC_Master_Switch_E_Switch_Off ((Dt_Enum_ACC_Master_Switch_E)0U) /* Default value */
#define Dt_Enum_ACC_Master_Switch_E_Switch_On ((Dt_Enum_ACC_Master_Switch_E)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_Brk_Pedal_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_Brk_Pedal_E_

typedef uint8_T Dt_Enum_Brk_Pedal_E;

/* enum Dt_Enum_Brk_Pedal_E */
#define Dt_Enum_Brk_Pedal_E_Pedal_Released ((Dt_Enum_Brk_Pedal_E)0U) /* Default value */
#define Dt_Enum_Brk_Pedal_E_Pedal_Pressed ((Dt_Enum_Brk_Pedal_E)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_Ignition_Status_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_Ignition_Status_E_

typedef uint8_T Dt_Enum_Ignition_Status_E;

/* enum Dt_Enum_Ignition_Status_E */
#define Dt_Enum_Ignition_Status_E_Ign_Off ((Dt_Enum_Ignition_Status_E)0U) /* Default value */
#define Dt_Enum_Ignition_Status_E_Ign_ACC ((Dt_Enum_Ignition_Status_E)1U)
#define Dt_Enum_Ignition_Status_E_Ign_Run ((Dt_Enum_Ignition_Status_E)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_POST_Status_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_POST_Status_E_

typedef uint8_T Dt_Enum_POST_Status_E;

/* enum Dt_Enum_POST_Status_E */
#define Dt_Enum_POST_Status_E_Failed   ((Dt_Enum_POST_Status_E)0U) /* Default value */
#define Dt_Enum_POST_Status_E_Success  ((Dt_Enum_POST_Status_E)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_Button_Status_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_Button_Status_E_

typedef uint8_T Dt_Enum_Button_Status_E;

/* enum Dt_Enum_Button_Status_E */
#define Dt_Enum_Button_Status_E_None   ((Dt_Enum_Button_Status_E)0U) /* Default value */
#define Dt_Enum_Button_Status_E_Set    ((Dt_Enum_Button_Status_E)1U)
#define Dt_Enum_Button_Status_E_Cancel ((Dt_Enum_Button_Status_E)2U)
#define Dt_Enum_Button_Status_E_Resume ((Dt_Enum_Button_Status_E)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_Audible_Warning_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_Audible_Warning_E_

typedef uint8_T Dt_Enum_Audible_Warning_E;

/* enum Dt_Enum_Audible_Warning_E */
#define Dt_Enum_Audible_Warning_E_Warn_None ((Dt_Enum_Audible_Warning_E)0U) /* Default value */
#define Dt_Enum_Audible_Warning_E_Warn_Single_Beep ((Dt_Enum_Audible_Warning_E)1U)
#define Dt_Enum_Audible_Warning_E_Warn_Chime ((Dt_Enum_Audible_Warning_E)2U)
#define Dt_Enum_Audible_Warning_E_Warn_Loud_Chime ((Dt_Enum_Audible_Warning_E)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_HMI_ACC_ICON_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_HMI_ACC_ICON_E_

typedef uint8_T Dt_Enum_HMI_ACC_ICON_E;

/* enum Dt_Enum_HMI_ACC_ICON_E */
#define Dt_Enum_HMI_ACC_ICON_E_Off     ((Dt_Enum_HMI_ACC_ICON_E)0U) /* Default value */
#define Dt_Enum_HMI_ACC_ICON_E_White   ((Dt_Enum_HMI_ACC_ICON_E)1U)
#define Dt_Enum_HMI_ACC_ICON_E_Green   ((Dt_Enum_HMI_ACC_ICON_E)2U)
#define Dt_Enum_HMI_ACC_ICON_E_Blink_Green ((Dt_Enum_HMI_ACC_ICON_E)3U)
#define Dt_Enum_HMI_ACC_ICON_E_Red     ((Dt_Enum_HMI_ACC_ICON_E)4U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_Torque_Request_Status_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_Torque_Request_Status_E_

typedef uint8_T Dt_Enum_Torque_Request_Status_E;

/* enum Dt_Enum_Torque_Request_Status_E */
#define Dt_Enum_Torque_Request_Status_E_Disabled ((Dt_Enum_Torque_Request_Status_E)0U) /* Default value */
#define Dt_Enum_Torque_Request_Status_E_Standby ((Dt_Enum_Torque_Request_Status_E)1U)
#define Dt_Enum_Torque_Request_Status_E_Longi ((Dt_Enum_Torque_Request_Status_E)2U)
#define Dt_Enum_Torque_Request_Status_E_Dis_active ((Dt_Enum_Torque_Request_Status_E)3U)
#define Dt_Enum_Torque_Request_Status_E_Hold_Req ((Dt_Enum_Torque_Request_Status_E)4U)
#define Dt_Enum_Torque_Request_Status_E_Override ((Dt_Enum_Torque_Request_Status_E)5U)
#define Dt_Enum_Torque_Request_Status_E_Fault ((Dt_Enum_Torque_Request_Status_E)6U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_Internal_Control_Mode_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_Internal_Control_Mode_E_

typedef uint8_T Dt_Enum_Internal_Control_Mode_E;

/* enum Dt_Enum_Internal_Control_Mode_E */
#define Dt_Enum_Internal_Control_Mode_E_Standstill ((Dt_Enum_Internal_Control_Mode_E)0U) /* Default value */
#define Dt_Enum_Internal_Control_Mode_E_Monitoring ((Dt_Enum_Internal_Control_Mode_E)1U)
#define Dt_Enum_Internal_Control_Mode_E_Speedctrl ((Dt_Enum_Internal_Control_Mode_E)2U)
#define Dt_Enum_Internal_Control_Mode_E_Distctrl ((Dt_Enum_Internal_Control_Mode_E)3U)
#define Dt_Enum_Internal_Control_Mode_E_Passive ((Dt_Enum_Internal_Control_Mode_E)4U)
#define Dt_Enum_Internal_Control_Mode_E_Error ((Dt_Enum_Internal_Control_Mode_E)5U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_ACC_State_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_ACC_State_E_

typedef uint8_T Dt_Enum_ACC_State_E;

/* enum Dt_Enum_ACC_State_E */
#define Dt_Enum_ACC_State_E_ACC_Off    ((Dt_Enum_ACC_State_E)0U) /* Default value */
#define Dt_Enum_ACC_State_E_ACC_Standby ((Dt_Enum_ACC_State_E)1U)
#define Dt_Enum_ACC_State_E_ACC_Fault  ((Dt_Enum_ACC_State_E)2U)
#define Dt_Enum_ACC_State_E_ACC_Active ((Dt_Enum_ACC_State_E)3U)
#define Dt_Enum_ACC_State_E_ACC_Active_Follow ((Dt_Enum_ACC_State_E)4U)
#define Dt_Enum_ACC_State_E_ACC_Stop_Hold ((Dt_Enum_ACC_State_E)5U)
#define Dt_Enum_ACC_State_E_ACC_Override ((Dt_Enum_ACC_State_E)6U)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_ACC_T RT_MODEL_ACC_T;

#endif                                 /* ACC_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
