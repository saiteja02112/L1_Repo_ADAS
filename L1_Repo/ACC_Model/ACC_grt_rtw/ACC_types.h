/*
 * ACC_types.h
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

#ifndef ACC_types_h_
#define ACC_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_ACC_Master_Switch_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_ACC_Master_Switch_E_

typedef uint8_T Dt_Enum_ACC_Master_Switch_E;

/* enum Dt_Enum_ACC_Master_Switch_E */
#define Dt_Enum_ACC_Master_Switch_E_OFF ((Dt_Enum_ACC_Master_Switch_E)0U) /* Default value */
#define Dt_Enum_ACC_Master_Switch_E_ON ((Dt_Enum_ACC_Master_Switch_E)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_Pedal_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_Pedal_E_

typedef uint8_T Dt_Enum_Pedal_E;

/* enum Dt_Enum_Pedal_E */
#define Dt_Enum_Pedal_E_RELEASED       ((Dt_Enum_Pedal_E)0U)     /* Default value */
#define Dt_Enum_Pedal_E_PRESSED        ((Dt_Enum_Pedal_E)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_Ignition_Status_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_Ignition_Status_E_

typedef uint8_T Dt_Enum_Ignition_Status_E;

/* enum Dt_Enum_Ignition_Status_E */
#define Dt_Enum_Ignition_Status_E_OFF  ((Dt_Enum_Ignition_Status_E)0U) /* Default value */
#define Dt_Enum_Ignition_Status_E_RUN  ((Dt_Enum_Ignition_Status_E)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_POST_Status_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_POST_Status_E_

typedef uint8_T Dt_Enum_POST_Status_E;

/* enum Dt_Enum_POST_Status_E */
#define Dt_Enum_POST_Status_E_FAILED   ((Dt_Enum_POST_Status_E)0U) /* Default value */
#define Dt_Enum_POST_Status_E_SUCCESS  ((Dt_Enum_POST_Status_E)1U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_Button_Status_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_Button_Status_E_

typedef int32_T Dt_Enum_Button_Status_E;

/* enum Dt_Enum_Button_Status_E */
#define NONE                           (0)                       /* Default value */
#define SET                            (1)
#define CANCEL                         (2)
#define RESUME                         (3)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_Audible_Warning_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_Audible_Warning_E_

typedef uint8_T Dt_Enum_Audible_Warning_E;

/* enum Dt_Enum_Audible_Warning_E */
#define None                           ((Dt_Enum_Audible_Warning_E)0U) /* Default value */
#define Single_Beep                    ((Dt_Enum_Audible_Warning_E)1U)
#define Chime                          ((Dt_Enum_Audible_Warning_E)2U)
#define Loud_Chime                     ((Dt_Enum_Audible_Warning_E)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_HMI_ACC_ICON_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_HMI_ACC_ICON_E_

typedef uint8_T Dt_Enum_HMI_ACC_ICON_E;

/* enum Dt_Enum_HMI_ACC_ICON_E */
#define Off                            ((Dt_Enum_HMI_ACC_ICON_E)0U) /* Default value */
#define White                          ((Dt_Enum_HMI_ACC_ICON_E)1U)
#define Green                          ((Dt_Enum_HMI_ACC_ICON_E)2U)
#define Blink_Green                    ((Dt_Enum_HMI_ACC_ICON_E)3U)
#define Red                            ((Dt_Enum_HMI_ACC_ICON_E)4U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_Torque_Request_Status_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_Torque_Request_Status_E_

typedef int32_T Dt_Enum_Torque_Request_Status_E;

/* enum Dt_Enum_Torque_Request_Status_E */
#define Disabled                       (0)                       /* Default value */
#define Standby                        (1)
#define Longi                          (2)
#define Dis_active                     (3)
#define Hold_Req                       (4)
#define Override                       (5)
#define Fault                          (6)
#endif

#ifndef DEFINED_TYPEDEF_FOR_Dt_Enum_Internal_Control_Mode_E_
#define DEFINED_TYPEDEF_FOR_Dt_Enum_Internal_Control_Mode_E_

typedef uint8_T Dt_Enum_Internal_Control_Mode_E;

/* enum Dt_Enum_Internal_Control_Mode_E */
#define Standstill                     ((Dt_Enum_Internal_Control_Mode_E)0U) /* Default value */
#define Monitoring                     ((Dt_Enum_Internal_Control_Mode_E)1U)
#define Speedctrl                      ((Dt_Enum_Internal_Control_Mode_E)2U)
#define Distctrl                       ((Dt_Enum_Internal_Control_Mode_E)3U)
#define Passive                        ((Dt_Enum_Internal_Control_Mode_E)4U)
#define Error                          ((Dt_Enum_Internal_Control_Mode_E)5U)
#endif

/* Parameters for system: '<S1>/Acc_req' */
typedef struct P_Acc_req_ACC_T_ P_Acc_req_ACC_T;

/* Parameters (default storage) */
typedef struct P_ACC_T_ P_ACC_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ACC_T RT_MODEL_ACC_T;

#endif                                 /* ACC_types_h_ */
