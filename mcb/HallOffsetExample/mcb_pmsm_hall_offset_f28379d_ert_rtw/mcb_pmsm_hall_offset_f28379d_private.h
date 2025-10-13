/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_hall_offset_f28379d_private.h
 *
 * Code generated for Simulink model 'mcb_pmsm_hall_offset_f28379d'.
 *
 * Model version                  : 7.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Oct 13 11:13:13 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_mcb_pmsm_hall_offset_f28379d_private_h_
#define RTW_HEADER_mcb_pmsm_hall_offset_f28379d_private_h_
#include "rtwtypes.h"
#include "mcb_pmsm_hall_offset_f28379d.h"
#include "mcb_pmsm_hall_offset_f28379d_types.h"

void InitAdcB (void);
void config_ADCB_SOC0 (void);
void InitAdcC (void);
void config_ADCC_SOC0 (void);
extern uint16_T MW_adcBInitFlag;
extern uint16_T MW_adcCInitFlag;
extern void mcb_pmsm_hall_offs_HallValueof1(real32_T *rty_position);
extern void mcb_pmsm_hall_offs_HallValueof2(real32_T *rty_position);
extern void mcb_pmsm_hall_offs_HallValueof3(real32_T *rty_position);
extern void mcb_pmsm_hall_offs_HallValueof4(real32_T *rty_position);
extern void mcb_pmsm_hall_offs_HallValueof5(real32_T *rty_position);
extern void mcb_pmsm_hall_offs_HallValueof7(real32_T *rty_position);
extern void mcb_pmsm_hall_offset_f2_Output1(boolean_T *rty_Out1);
extern void mcb_pmsm_hall_offset_f2_Output0(boolean_T *rty_Out1);
extern void mcb_pmsm_hall_o_ValidHalls_Init(rtB_ValidHalls_mcb_pmsm_hall_of
  *localB);
extern void mcb_pmsm_hall_offset_ValidHalls(uint16_T rtu_hallReading, uint16_T
  rtu_previousState, int16_T rtu_previous_direction, boolean_T
  *rty_directional_speed_valid_fla, int16_T *rty_direction, uint16_T
  *rty_inValidHall, rtB_ValidHalls_mcb_pmsm_hall_of *localB);
extern void Badhallglitchorwrongconnection(int16_T rtu_previous_direction,
  uint16_T *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla);
extern void mcb_pmsm_hall_AtomicHallReading(void);

#endif                  /* RTW_HEADER_mcb_pmsm_hall_offset_f28379d_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
