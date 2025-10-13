/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pmsm_f28379d_openloop.h
 *
 * Code generated for Simulink model 'pmsm_f28379d_openloop'.
 *
 * Model version                  : 16
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Oct 11 15:16:00 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pmsm_f28379d_openloop_h_
#define RTW_HEADER_pmsm_f28379d_openloop_h_
#ifndef pmsm_f28379d_openloop_COMMON_INCLUDES_
#define pmsm_f28379d_openloop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                              /* pmsm_f28379d_openloop_COMMON_INCLUDES_ */

#include "pmsm_f28379d_openloop_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals (default storage) */
typedef struct {
  real_T SineWaveFunction;             /* '<Root>/Sine Wave Function' */
  real_T SineWaveFunction1;            /* '<Root>/Sine Wave Function1' */
  real_T SineWaveFunction2;            /* '<Root>/Sine Wave Function2' */
  real_T Max;                          /* '<S5>/Max' */
  real_T Min;                          /* '<S5>/Min' */
  real_T Add;                          /* '<S5>/Add' */
  real_T one_by_two;                   /* '<S5>/one_by_two' */
  real_T Add3;                         /* '<S4>/Add3' */
  real_T Add1;                         /* '<S4>/Add1' */
  real_T Add2;                         /* '<S4>/Add2' */
  real_T Gain[3];                      /* '<S4>/Gain' */
} BlockIO_pmsm_f28379d_openloop;

/* Real-time Model Data Structure */
struct tag_RTM_pmsm_f28379d_openloop {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern BlockIO_pmsm_f28379d_openloop pmsm_f28379d_openloop_B;

/* Model entry point functions */
extern void pmsm_f28379d_openloop_initialize(void);
extern void pmsm_f28379d_openloop_step(void);
extern void pmsm_f28379d_openloop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pmsm_f28379d_openloop *const pmsm_f28379d_openloop_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'pmsm_f28379d_openloop'
 * '<S1>'   : 'pmsm_f28379d_openloop/PWM Reference Generator'
 * '<S2>'   : 'pmsm_f28379d_openloop/PWM Reference Generator/Modulation method'
 * '<S3>'   : 'pmsm_f28379d_openloop/PWM Reference Generator/Voltage Input'
 * '<S4>'   : 'pmsm_f28379d_openloop/PWM Reference Generator/Modulation method/SVPWM'
 * '<S5>'   : 'pmsm_f28379d_openloop/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S6>'   : 'pmsm_f28379d_openloop/PWM Reference Generator/Voltage Input/Vabc'
 */
#endif                                 /* RTW_HEADER_pmsm_f28379d_openloop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
