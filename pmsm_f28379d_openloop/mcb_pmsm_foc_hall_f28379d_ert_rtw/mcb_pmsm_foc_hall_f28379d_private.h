/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_hall_f28379d_private.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_hall_f28379d'.
 *
 * Model version                  : 14
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Oct 11 15:17:47 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_mcb_pmsm_foc_hall_f28379d_private_h_
#define RTW_HEADER_mcb_pmsm_foc_hall_f28379d_private_h_
#include "rtwtypes.h"
#include "mcb_pmsm_foc_hall_f28379d.h"
#include "mcb_pmsm_foc_hall_f28379d_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFFFU) ) || ( SCHAR_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
void InitAdcC (void);
void config_ADCC_SOC0 (void);
void InitAdcB (void);
void config_ADCB_SOC0 (void);
void config_ADCC_SOC2 (void);
void config_ADCB_SOC2 (void);
extern uint16_T MW_adcCInitFlag;
extern uint16_T MW_adcBInitFlag;
extern void mcb_pmsm_foc_h_HallValueof1(real32_T *rty_position);
extern void mcb_pmsm_foc_h_HallValueof2(real32_T *rty_position);
extern void mcb_pmsm_foc_h_HallValueof3(real32_T *rty_position);
extern void mcb_pmsm_foc_h_HallValueof4(real32_T *rty_position);
extern void mcb_pmsm_foc_h_HallValueof5(real32_T *rty_position);
extern void mcb_pmsm_foc_h_HallValueof7(real32_T *rty_position);
extern void mcb_pmsm_foc_hall_f_Output1(boolean_T *rty_Out1);
extern void mcb_pmsm_foc_hall_f_Output0(boolean_T *rty_Out1);
extern void mcb_pmsm_fo_ValidHalls_Init(rtB_ValidHalls_mcb_pmsm_foc_hal *localB);
extern void mcb_pmsm_foc_hal_ValidHalls(uint16_T rtu_hallReading, uint16_T
  rtu_previousState, int16_T rtu_previous_direction, boolean_T
  *rty_directional_speed_valid_fla, int16_T *rty_direction, uint16_T
  *rty_inValidHall, rtB_ValidHalls_mcb_pmsm_foc_hal *localB);
extern void Badhallglitchorwrongconnect(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla);
extern void mcb_SPIMasterTransfer2_Init(rtDW_SPIMasterTransfer2_mcb_pms *localDW);
extern void mcb_pmsm_SPIMasterTransfer2(uint16_T rtu_0,
  rtB_SPIMasterTransfer2_mcb_pmsm *localB, rtDW_SPIMasterTransfer2_mcb_pms
  *localDW);
extern void mcb_pmsm__SpeedControl_Init(rtB_SpeedControl_mcb_pmsm_foc_h *localB,
  rtDW_SpeedControl_mcb_pmsm_foc_ *localDW);
extern void mcb_pmsm_foc_h_SpeedControl(real32_T rtu_Speed_Ref_PU, real32_T
  rtu_Speed_Meas_PU, const boolean_T *rtd_Enable,
  rtB_SpeedControl_mcb_pmsm_foc_h *localB, rtDW_SpeedControl_mcb_pmsm_foc_
  *localDW);
extern void mcb_pmsm__AtomicHallReading(void);
extern void mcb_pms_CurrentControl_Init(void);
extern void mcb_pm_CurrentControl_Reset(void);

#pragma CODE_SECTION (mcb_pmsm_foc_CurrentControl, "ramfuncs")

extern void mcb_pmsm_foc_CurrentControl(void);
extern void mcb_SPIMasterTransfer2_Term(rtDW_SPIMasterTransfer2_mcb_pms *localDW);

#endif                     /* RTW_HEADER_mcb_pmsm_foc_hall_f28379d_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
