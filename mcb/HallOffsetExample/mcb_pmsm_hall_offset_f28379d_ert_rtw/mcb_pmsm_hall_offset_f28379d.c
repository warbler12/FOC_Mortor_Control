/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_hall_offset_f28379d.c
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

#include "mcb_pmsm_hall_offset_f28379d.h"
#include "rtwtypes.h"
#include "mcb_pmsm_hall_offset_f28379d_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_mcb_pmsm_hall_offset_f2 mcb_pmsm_hall_offset_f28379d_B;

/* Block states (default storage) */
D_Work_mcb_pmsm_hall_offset_f28 mcb_pmsm_hall_offset_f283_DWork;

/* Real-time model */
static RT_MODEL_mcb_pmsm_hall_offset_f mcb_pmsm_hall_offset_f28379d_M_;
RT_MODEL_mcb_pmsm_hall_offset_f *const mcb_pmsm_hall_offset_f28379d_M =
  &mcb_pmsm_hall_offset_f28379d_M_;

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

/* Output and update for atomic system: '<S130>/Atomic Hall Reading' */
void mcb_pmsm_hall_AtomicHallReading(void)
{
  uint32_T u0;
  uint32_T u1;

  /* user code (Output function Body for TID1) */

  /* System '<S130>/Atomic Hall Reading' */
  DINT;

  /* DataStoreRead: '<S131>/Data Store Read5' */
  mcb_pmsm_hall_offset_f28379d_B.DataStoreRead5 =
    mcb_pmsm_hall_offset_f283_DWork.HallStateChangeFlag;

  /* S-Function (memorycopy): '<S133>/Read GPIO DAT register' */
  {
    uint32_T *memindsrc1 = (uint32_T *) (&GpioDataRegs.GPBDAT.all);
    uint32_T *meminddst1 = (uint32_T *)
      (&mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister_h);
    *(uint32_T *) (meminddst1) = *(uint32_T *) (memindsrc1);
  }

  /* S-Function (sfix_bitop): '<S133>/Hall_C' */
  mcb_pmsm_hall_offset_f28379d_B.Hall_C_a =
    mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister_h & 33554432UL;

  /* ArithShift: '<S133>/Shift Arithmetic' incorporates:
   *  S-Function (sfix_bitop): '<S133>/Hall_C'
   */
  mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic_a =
    mcb_pmsm_hall_offset_f28379d_B.Hall_C_a >> 23U;

  /* S-Function (sfix_bitop): '<S133>/Hall_B' */
  mcb_pmsm_hall_offset_f28379d_B.Hall_B_b =
    mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister_h & 8388608UL;

  /* ArithShift: '<S133>/Shift Arithmetic1' incorporates:
   *  S-Function (sfix_bitop): '<S133>/Hall_B'
   */
  mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic1_i =
    mcb_pmsm_hall_offset_f28379d_B.Hall_B_b >> 22U;

  /* S-Function (sfix_bitop): '<S133>/Hall_A' */
  mcb_pmsm_hall_offset_f28379d_B.Hall_A_a =
    mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister_h & 4194304UL;

  /* ArithShift: '<S133>/Shift Arithmetic2' incorporates:
   *  S-Function (sfix_bitop): '<S133>/Hall_A'
   */
  mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic2_e =
    mcb_pmsm_hall_offset_f28379d_B.Hall_A_a >> 22U;

  /* S-Function (sfix_bitop): '<S133>/Bitwise Operator2' */
  mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_o = (uint32_T)((int16_T)
    mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic_a | (int16_T)
    mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic1_i | (int16_T)
    mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic2_e);

  /* S-Function (memorycopy): '<S131>/Memory Copy' */
  {
    uint32_T *memindsrc2 = (uint32_T *) (&ECap1Regs.TSCTR);
    uint32_T *meminddst2 = (uint32_T *)
      (&mcb_pmsm_hall_offset_f28379d_B.MemoryCopy);
    *(uint32_T *) (meminddst2) = *(uint32_T *) (memindsrc2);
  }

  /* S-Function (memorycopy): '<S131>/Memory Copy1' */
  {
    uint32_T *memindsrc3 = (uint32_T *) (&ECap2Regs.TSCTR);
    uint32_T *meminddst3 = (uint32_T *)
      (&mcb_pmsm_hall_offset_f28379d_B.MemoryCopy1);
    *(uint32_T *) (meminddst3) = *(uint32_T *) (memindsrc3);
  }

  /* S-Function (memorycopy): '<S131>/Memory Copy2' */
  {
    uint32_T *memindsrc4 = (uint32_T *) (&ECap3Regs.TSCTR);
    uint32_T *meminddst4 = (uint32_T *)
      (&mcb_pmsm_hall_offset_f28379d_B.MemoryCopy2);
    *(uint32_T *) (meminddst4) = *(uint32_T *) (memindsrc4);
  }

  /* MinMax: '<S131>/Min' */
  u0 = mcb_pmsm_hall_offset_f28379d_B.MemoryCopy;
  u1 = mcb_pmsm_hall_offset_f28379d_B.MemoryCopy1;
  if (u0 <= u1) {
    u1 = u0;
  }

  u0 = mcb_pmsm_hall_offset_f28379d_B.MemoryCopy2;
  if (u1 > u0) {
    u1 = u0;
  }

  /* MinMax: '<S131>/Min' */
  mcb_pmsm_hall_offset_f28379d_B.Min = u1;

  /* DataStoreRead: '<S131>/Data Store Read2' */
  mcb_pmsm_hall_offset_f28379d_B.DataStoreRead2 =
    mcb_pmsm_hall_offset_f283_DWork.GlobalSpeedCount;

  /* DataStoreRead: '<S131>/Data Store Read3' */
  mcb_pmsm_hall_offset_f28379d_B.DataStoreRead3 =
    mcb_pmsm_hall_offset_f283_DWork.GlobalDirection;

  /* DataStoreRead: '<S131>/Data Store Read4' */
  mcb_pmsm_hall_offset_f28379d_B.DataStoreRead4 =
    mcb_pmsm_hall_offset_f283_DWork.GlobalSpeedValidity;

  /* user code (Output function Trailer for TID1) */

  /* System '<S130>/Atomic Hall Reading' */
  EINT;
}

/*
 * Output and update for action system:
 *    '<S152>/Hall Value of 1'
 *    '<S151>/Hall Value of 2'
 */
void mcb_pmsm_hall_offs_HallValueof1(real32_T *rty_position)
{
  /* SignalConversion generated from: '<S162>/position' incorporates:
   *  Constant: '<S162>/Constant'
   */
  *rty_position = 0.16667F;
}

/*
 * Output and update for action system:
 *    '<S152>/Hall Value of 2'
 *    '<S151>/Hall Value of 3'
 */
void mcb_pmsm_hall_offs_HallValueof2(real32_T *rty_position)
{
  /* SignalConversion generated from: '<S163>/position' incorporates:
   *  Constant: '<S163>/Constant'
   */
  *rty_position = 0.33333F;
}

/*
 * Output and update for action system:
 *    '<S152>/Hall Value of 3'
 *    '<S151>/Hall Value of 4'
 */
void mcb_pmsm_hall_offs_HallValueof3(real32_T *rty_position)
{
  /* SignalConversion generated from: '<S164>/position' incorporates:
   *  Constant: '<S164>/Constant'
   */
  *rty_position = 0.5F;
}

/*
 * Output and update for action system:
 *    '<S152>/Hall Value of 4'
 *    '<S151>/Hall Value of 5'
 */
void mcb_pmsm_hall_offs_HallValueof4(real32_T *rty_position)
{
  /* SignalConversion generated from: '<S165>/position' incorporates:
   *  Constant: '<S165>/Constant'
   */
  *rty_position = 0.66667F;
}

/*
 * Output and update for action system:
 *    '<S152>/Hall Value of 5'
 *    '<S151>/Hall Value of 6'
 */
void mcb_pmsm_hall_offs_HallValueof5(real32_T *rty_position)
{
  /* SignalConversion generated from: '<S166>/position' incorporates:
   *  Constant: '<S166>/Constant'
   */
  *rty_position = 0.83333F;
}

/*
 * Output and update for action system:
 *    '<S152>/Hall Value of 7'
 *    '<S151>/Hall Value of 1'
 *    '<S151>/Hall Value of 7'
 *    '<S140>/Hall Value of 7'
 */
void mcb_pmsm_hall_offs_HallValueof7(real32_T *rty_position)
{
  /* SignalConversion generated from: '<S168>/position' incorporates:
   *  Constant: '<S168>/Constant'
   */
  *rty_position = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S23>/Output 1'
 *    '<S41>/Output 1'
 *    '<S59>/Output 1'
 */
void mcb_pmsm_hall_offset_f2_Output1(boolean_T *rty_Out1)
{
  /* SignalConversion generated from: '<S27>/Out1' incorporates:
   *  Constant: '<S27>/Constant'
   */
  *rty_Out1 = true;
}

/*
 * Output and update for action system:
 *    '<S23>/Output 0'
 *    '<S41>/Output 0'
 *    '<S59>/Output 0'
 */
void mcb_pmsm_hall_offset_f2_Output0(boolean_T *rty_Out1)
{
  /* SignalConversion generated from: '<S26>/Out1' incorporates:
   *  Constant: '<S26>/Constant'
   */
  *rty_Out1 = false;
}

/*
 * System initialize for action system:
 *    '<S28>/Valid Halls'
 *    '<S46>/Valid Halls'
 *    '<S64>/Valid Halls'
 */
void mcb_pmsm_hall_o_ValidHalls_Init(rtB_ValidHalls_mcb_pmsm_hall_of *localB)
{
  /* SystemInitialize for Merge: '<S30>/Merge' */
  localB->Merge = 0U;

  /* SystemInitialize for Merge: '<S30>/Merge1' */
  localB->Merge1 = 0U;

  /* SystemInitialize for Merge: '<S30>/Merge2' */
  localB->Merge2 = 0;

  /* SystemInitialize for Merge: '<S30>/Merge3' */
  localB->Merge3 = 0U;
}

/*
 * Output and update for action system:
 *    '<S28>/Valid Halls'
 *    '<S46>/Valid Halls'
 *    '<S64>/Valid Halls'
 */
void mcb_pmsm_hall_offset_ValidHalls(uint16_T rtu_hallReading, uint16_T
  rtu_previousState, int16_T rtu_previous_direction, boolean_T
  *rty_directional_speed_valid_fla, int16_T *rty_direction, uint16_T
  *rty_inValidHall, rtB_ValidHalls_mcb_pmsm_hall_of *localB)
{
  /* SwitchCase: '<S30>/Switch Case' */
  switch ((int32_T)rtu_hallReading) {
   case 5L:
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* Merge: '<S30>/Merge' incorporates:
     *  Constant: '<S31>/previous'
     *  SignalConversion generated from: '<S31>/Out1'
     */
    localB->Merge = 1U;

    /* Merge: '<S30>/Merge1' incorporates:
     *  Constant: '<S31>/next'
     *  SignalConversion generated from: '<S31>/Out2'
     */
    localB->Merge1 = 4U;

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem' */
    break;

   case 4L:
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* Merge: '<S30>/Merge' incorporates:
     *  Constant: '<S32>/previous'
     *  SignalConversion generated from: '<S32>/Out1'
     */
    localB->Merge = 5U;

    /* Merge: '<S30>/Merge1' incorporates:
     *  Constant: '<S32>/next'
     *  SignalConversion generated from: '<S32>/Out2'
     */
    localB->Merge1 = 6U;

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem1' */
    break;

   case 6L:
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* Merge: '<S30>/Merge' incorporates:
     *  Constant: '<S33>/previous'
     *  SignalConversion generated from: '<S33>/Out1'
     */
    localB->Merge = 4U;

    /* Merge: '<S30>/Merge1' incorporates:
     *  Constant: '<S33>/next'
     *  SignalConversion generated from: '<S33>/Out2'
     */
    localB->Merge1 = 2U;

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem2' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* Merge: '<S30>/Merge' incorporates:
     *  Constant: '<S34>/previous'
     *  SignalConversion generated from: '<S34>/Out1'
     */
    localB->Merge = 6U;

    /* Merge: '<S30>/Merge1' incorporates:
     *  Constant: '<S34>/next'
     *  SignalConversion generated from: '<S34>/Out2'
     */
    localB->Merge1 = 3U;

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem3' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    /* Merge: '<S30>/Merge' incorporates:
     *  Constant: '<S35>/previous'
     *  SignalConversion generated from: '<S35>/Out1'
     */
    localB->Merge = 2U;

    /* Merge: '<S30>/Merge1' incorporates:
     *  Constant: '<S35>/next'
     *  SignalConversion generated from: '<S35>/Out2'
     */
    localB->Merge1 = 1U;

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem4' */
    break;

   case 1L:
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    /* Merge: '<S30>/Merge' incorporates:
     *  Constant: '<S36>/previous'
     *  SignalConversion generated from: '<S36>/Out1'
     */
    localB->Merge = 3U;

    /* Merge: '<S30>/Merge1' incorporates:
     *  Constant: '<S36>/next'
     *  SignalConversion generated from: '<S36>/Out2'
     */
    localB->Merge1 = 5U;

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem5' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S30>/Switch Case' */

  /* If: '<S30>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    /* Merge: '<S30>/Merge2' incorporates:
     *  Constant: '<S37>/Constant'
     *  SignalConversion generated from: '<S37>/direction'
     */
    localB->Merge2 = 1;

    /* Merge: '<S30>/Merge3' incorporates:
     *  Constant: '<S37>/Constant1'
     *  SignalConversion generated from: '<S37>/sequence_check'
     */
    localB->Merge3 = 0U;

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    /* Merge: '<S30>/Merge2' incorporates:
     *  Constant: '<S38>/Constant'
     *  SignalConversion generated from: '<S38>/direction'
     */
    localB->Merge2 = -1;

    /* Merge: '<S30>/Merge3' incorporates:
     *  Constant: '<S38>/Constant1'
     *  SignalConversion generated from: '<S38>/sequence_check'
     */
    localB->Merge3 = 0U;

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    /* Merge: '<S30>/Merge3' incorporates:
     *  Constant: '<S39>/Constant'
     *  SignalConversion generated from: '<S39>/sequence_check'
     */
    localB->Merge3 = 1U;

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem8' */
  }

  /* End of If: '<S30>/If' */

  /* SignalConversion: '<S30>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S30>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant'
   */
  if (localB->Merge3 != 0U) {
    *rty_directional_speed_valid_fla = false;
  } else {
    /* RelationalOperator: '<S30>/Relational Operator' */
    localB->RelationalOperator = (localB->Merge2 == rtu_previous_direction);
    *rty_directional_speed_valid_fla = localB->RelationalOperator;
  }

  /* End of Switch: '<S30>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S28>/Bad hall (glitch or wrong connection)'
 *    '<S46>/Bad hall (glitch or wrong connection)'
 *    '<S64>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnection(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla)
{
  /* SignalConversion generated from: '<S29>/inValidHall' incorporates:
   *  Constant: '<S29>/Constant'
   */
  *rty_inValidHall = 1U;

  /* SignalConversion: '<S29>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S29>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S29>/Constant1'
   */
  *rty_directional_speed_valid_fla = false;
}

/* Model step function */
void mcb_pmsm_hall_offset_f28379d_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S5>/Digital Output2' incorporates:
   *  Constant: '<S5>/LED'
   */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)((1U) != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_hall_offset_f28379d_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(mcb_pmsm_hall_offset_f28379d_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_hall_offset_f28379d_B), 0,
                sizeof(BlockIO_mcb_pmsm_hall_offset_f2));

  {
    mcb_pmsm_hall_offset_f28379d_B.SCIReceive = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Merge = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Merge1 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Switch_g = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.TmpSignalConversionAtBytePackIn[0] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.TmpSignalConversionAtBytePackIn[1] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Merge_j = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.indexing = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Lookup[0] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Lookup[1] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Lookup[2] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Lookup[3] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Sum3 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Sum2 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Product = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Sum4 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Sum5 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Product1 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Sum6 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.sqrt3_by_two = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.one_by_two = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.add_c = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.add_b = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Min_a = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Max_h = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Add_i = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.one_by_two_b = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Add2 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Add1_m = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Add3 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Gain[0] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Gain[1] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Gain[2] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Sum_d[0] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Sum_d[1] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Sum_d[2] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Gain_h[0] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Gain_h[1] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Gain_h[2] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.currentSpeedData = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Divide = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.SpeedGain = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Merge1_m = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Saturation = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Merge_f = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.countData = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.currentSpeedData_e = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Divide_n = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.countData_k = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.previousSpeedData = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Divide_b = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.currentSpeedData_k = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Divide1 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Sum_i = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Gain1 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Sum1 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Product_g = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Merge1_p = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Merge1_d = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Input = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Convert_back = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Convert_back_h = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Merge_fz = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.UnitDelay = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.scaleOut = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Add_j = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1_o = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Add1_g = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Input_h = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Delay_j = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Add1_o = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.SaturatetomotorcalibSpeedRPM = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.qcos = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.dsin = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.sum_beta = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.dcos = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.qsin = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.sum_alpha = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Switch_k[0] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Switch_k[1] = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.algDD_o1 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.algDD_o2 = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Delay_b = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.OutportBufferForOffset = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Product_j = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.UnitDelay_p = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Product1_h = 0.0F;
    mcb_pmsm_hall_offset_f28379d_B.Add1_ox = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_hall_offset_f283_DWork, 0,
                sizeof(D_Work_mcb_pmsm_hall_offset_f28));
  mcb_pmsm_hall_offset_f283_DWork.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE = 0.0F;
  mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE_i = 0.0F;
  mcb_pmsm_hall_offset_f283_DWork.UnitDelay_DSTATE_o = 0.0F;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Offset Calculation'
   */

  /* System initialize for function-call system: '<Root>/Offset Calculation' */

  /* Start for Delay: '<S134>/validityDelay' */
  mcb_pmsm_hall_offset_f28379d_B.validityDelay = false;

  /* Start for Delay: '<S134>/speedCountDelay' */
  mcb_pmsm_hall_offset_f28379d_B.speedCountDelay = 0UL;

  /* Start for Delay: '<S135>/Delay One Step' */
  mcb_pmsm_hall_offset_f28379d_B.DelayOneStep = 0U;

  /* Start for S-Function (c2802xpwm): '<S81>/ePWM1' */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 1U;          // Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x12U;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 6250U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm1Regs.CMPA.bit.CMPA = 3126U;   // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 3126U;   // Counter Compare B Register
    EPwm1Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm1Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7FU) | 0x1A01U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S81>/ePWM2' */

  /*** Initialize ePWM2 modules ***/
  {
    /*  // Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 0U;          // Sync Output Select

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm2Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 1U;          // Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 1U;          // Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm2Regs.TBCTL2.all = (EPwm2Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 6250U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm2Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm2Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm2Regs.CMPCTL2.all = (EPwm2Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm2Regs.CMPA.bit.CMPA = 3126U;   // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 3126U;   // Counter Compare B Register
    EPwm2Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm2Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       EPwm2Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
       EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
       EPwm2Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm2Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm2Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCASEL              = 2U;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM2SOC Period Select
       EPwm2Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM2INTn Period Select
       EPwm2Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm2Regs.ETSOCPS.all = (EPwm2Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm2Regs.ETINTPS.all = (EPwm2Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPALINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPBLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPCLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPDLINK = 1U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm2Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
       EPwm2Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
     */
    EPwm2Regs.HRPCTL.all = (EPwm2Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S81>/ePWM3' */

  /*** Initialize ePWM3 modules ***/
  {
    /*  // Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 0U;          // Sync Output Select

       EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm3Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

       EPwm3Regs.TBCTL.bit.PHSEN                = 1U;          // Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 1U;          // Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm3Regs.TBCTL2.all = (EPwm3Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 6250U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm3Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm3Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm3Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm3Regs.CMPCTL2.all = (EPwm3Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm3Regs.CMPA.bit.CMPA = 3126U;   // Counter Compare A Register
    EPwm3Regs.CMPB.bit.CMPB = 3126U;   // Counter Compare B Register
    EPwm3Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm3Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm3Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       EPwm3Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
       EPwm3Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
       EPwm3Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm3Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm3Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCASEL              = 2U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM3SOC Period Select
       EPwm3Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM3SOCB Period Select
       EPwm3Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.INTEN                = 0U;          // EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM3INTn Period Select
       EPwm3Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm3Regs.ETSOCPS.all = (EPwm3Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm3Regs.ETINTPS.all = (EPwm3Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3B
       EPwm3Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM3A action on DCAEVT1
       EPwm3Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM3A action on DCAEVT2
       EPwm3Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM3B action on DCBEVT1
       EPwm3Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM3B action on DCBEVT2
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
     */
    EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm3Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm3Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm3Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm3Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm3Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm3Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm3Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm3Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm3Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm3Regs.EPWMXLINK.bit.TBPRDLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPALINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPBLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPCLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPDLINK = 2U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm3Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
       EPwm3Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
     */
    EPwm3Regs.HRPCTL.all = (EPwm3Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c280xgpio_do): '<S81>/DRV830x Enable' */
  EALLOW;
  GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
  GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
  EDIS;

  /* Start for S-Function (c2802xadc): '<S6>/ADC_B_IN2' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S6>/ADC_C_IN2' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC0 ();

  /* InitializeConditions for Delay: '<S135>/Delay One Step1' */
  mcb_pmsm_hall_offset_f283_DWork.DelayOneStep1_DSTATE = true;

  /* InitializeConditions for Delay: '<S135>/Delay One Step' */
  mcb_pmsm_hall_offset_f283_DWork.DelayOneStep_DSTATE = 667U;

  /* SystemInitialize for IfAction SubSystem: '<S132>/Speed and direction are valid Use speed to extrapolate position' */
  /* SystemInitialize for Enabled SubSystem: '<S137>/Subsystem1' */
  /* SystemInitialize for Merge: '<S150>/Merge' */
  mcb_pmsm_hall_offset_f28379d_B.Merge_f = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S137>/Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<S132>/Speed and direction are valid Use speed to extrapolate position' */
  /* SystemInitialize for Enabled SubSystem: '<S77>/Find Offset' */
  /* InitializeConditions for Delay: '<S83>/Delay' */
  mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE_i = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S77>/Find Offset' */

  /* SystemInitialize for Enabled SubSystem: '<S77>/PosGen' */
  /* InitializeConditions for UnitDelay: '<S105>/Unit Delay' */
  mcb_pmsm_hall_offset_f283_DWork.UnitDelay_DSTATE = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S85>/Up Counter' */
  /* InitializeConditions for Delay: '<S102>/Delay' */
  mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE_ip = 0UL;

  /* End of SystemInitialize for SubSystem: '<S85>/Up Counter' */
  /* End of SystemInitialize for SubSystem: '<S77>/PosGen' */

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S16>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Hall Sensor A'
   */

  /* System initialize for function-call system: '<Root>/Hall Sensor A' */

  /* SystemInitialize for IfAction SubSystem: '<S28>/Valid Halls' */
  mcb_pmsm_hall_o_ValidHalls_Init(&mcb_pmsm_hall_offset_f28379d_B.ValidHalls);

  /* End of SystemInitialize for SubSystem: '<S28>/Valid Halls' */

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S16>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S18>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Hall Sensor B'
   */

  /* System initialize for function-call system: '<Root>/Hall Sensor B' */

  /* SystemInitialize for IfAction SubSystem: '<S46>/Valid Halls' */
  mcb_pmsm_hall_o_ValidHalls_Init(&mcb_pmsm_hall_offset_f28379d_B.ValidHalls_k);

  /* End of SystemInitialize for SubSystem: '<S46>/Valid Halls' */

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S18>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S20>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Hall Sensor C'
   */

  /* System initialize for function-call system: '<Root>/Hall Sensor C' */

  /* SystemInitialize for IfAction SubSystem: '<S64>/Valid Halls' */
  mcb_pmsm_hall_o_ValidHalls_Init(&mcb_pmsm_hall_offset_f28379d_B.ValidHalls_p);

  /* End of SystemInitialize for SubSystem: '<S64>/Valid Halls' */

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S20>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Serial Receive'
   */

  /* System initialize for function-call system: '<Root>/Serial Receive' */

  /* Start for S-Function (c28xsci_rx): '<S171>/SCI Receive' */

  /* Initialize out port */
  {
    mcb_pmsm_hall_offset_f28379d_B.SCIReceive = (real32_T)0.0;
  }

  /*Configure Timer2 when blocking mode is enabled and Timeout is not inf*/
  {
    /* InitCpuTimers() - CPU Timers are also initialized in
     * MW_c28xx_board.c in the generated code.
     */
    CpuTimer2Regs.PRD.all = 0xFFFFFFFFU;/* max Period*/
    CpuTimer2Regs.TIM.all = 0xFFFFFFFFU;/* set Ctr*/
    CpuTimer2Regs.TPR.all = 0x00U;     /* no prescaler    */
    StartCpuTimer2();
  }

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* Start for S-Function (c280xgpio_do): '<S5>/Digital Output2' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x4U;
  EDIS;

  /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model terminate function */
void mcb_pmsm_hall_offset_f28379d_terminate(void)
{
  /* (no terminate code required) */
}

void mcb_pmsm_hall_offset_f28379d_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(33,&ADCB1_INT,1);
  HWI_TIC28x_EnableIRQ(33);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(56,&ECAP1_INT,0);
  HWI_TIC28x_EnableIRQ(56);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(57,&ECAP2_INT,0);
  HWI_TIC28x_EnableIRQ(57);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(58,&ECAP3_INT,0);
  HWI_TIC28x_EnableIRQ(58);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(96,&SCIA_RX_INT,3);
  HWI_TIC28x_EnableIRQ(96);
}

/* Hardware Interrupt Block: '<S14>/Hardware Interrupt' */
interrupt void ADCB1_INT(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  volatile unsigned int PIEIER9_stack_save = PieCtrlRegs.PIEIER9.all;
  PieCtrlRegs.PIEIER1.all &= ~66;
                              /*disable group1 lower/equal priority interrupts*/
  PieCtrlRegs.PIEIER9.all &= ~1;
                              /*disable group9 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~257;    /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 257;
                   /*ACK to allow other interrupts from the same group to fire*/
  IER |= 1;
  EINT;

  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Offset Calculation' */
      {
        uint64_T tmp;
        real32_T Bias;
        real32_T u0_p;
        uint32_T u0;
        uint32_T u1;
        int16_T s122_iter;
        uint16_T Scale_to_PWM_Counter_PRD;
        boolean_T doReset;

        /* Outputs for Atomic SubSystem: '<S130>/Atomic Hall Reading' */
        mcb_pmsm_hall_AtomicHallReading();

        /* End of Outputs for SubSystem: '<S130>/Atomic Hall Reading' */

        /* Switch: '<S132>/Switch' incorporates:
         *  Constant: '<S132>/WatchDog'
         */
        mcb_pmsm_hall_offset_f28379d_B.Switch_a = 0U;

        /* DataStoreWrite: '<S130>/Data Store Write2' */
        mcb_pmsm_hall_offset_f283_DWork.HallStateChangeFlag = 0U;

        /* DataTypeConversion: '<S132>/Data Type Conversion4' */
        mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion4 =
          (mcb_pmsm_hall_offset_f28379d_B.DataStoreRead5 != 0U);

        /* DataTypeConversion: '<S134>/Data Type Conversion' */
        mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion_l3 =
          (mcb_pmsm_hall_offset_f28379d_B.DataStoreRead4 != 0U);

        /* Switch: '<S134>/Switch' incorporates:
         *  Constant: '<S134>/Order'
         */
        mcb_pmsm_hall_offset_f28379d_B.Switch_f = 0U;

        /* Delay: '<S135>/Delay One Step1' */
        mcb_pmsm_hall_offset_f28379d_B.DelayOneStep1 =
          mcb_pmsm_hall_offset_f283_DWork.DelayOneStep1_DSTATE;

        /* Logic: '<S135>/OR' */
        mcb_pmsm_hall_offset_f28379d_B.OR =
          (mcb_pmsm_hall_offset_f28379d_B.DelayOneStep1 ||
           mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion4);

        /* Delay: '<S135>/Delay One Step' */
        doReset = mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion4;
        if (mcb_pmsm_hall_offset_f28379d_B.OR) {
          if (doReset) {
            mcb_pmsm_hall_offset_f283_DWork.DelayOneStep_DSTATE = 667U;
          }

          /* Delay: '<S135>/Delay One Step' */
          mcb_pmsm_hall_offset_f28379d_B.DelayOneStep =
            mcb_pmsm_hall_offset_f283_DWork.DelayOneStep_DSTATE;
        }

        /* End of Delay: '<S135>/Delay One Step' */

        /* RelationalOperator: '<S139>/Compare' incorporates:
         *  Constant: '<S139>/Constant'
         */
        mcb_pmsm_hall_offset_f28379d_B.Compare =
          (mcb_pmsm_hall_offset_f28379d_B.DelayOneStep > 0U);

        /* Switch: '<S138>/watchdog check' */
        if (mcb_pmsm_hall_offset_f28379d_B.Compare) {
          /* MinMax: '<S138>/Max' */
          u0 = mcb_pmsm_hall_offset_f28379d_B.DataStoreRead2;
          u1 = mcb_pmsm_hall_offset_f28379d_B.Min;
          if (u0 >= u1) {
            u1 = u0;
          }

          /* MinMax: '<S138>/Max' */
          mcb_pmsm_hall_offset_f28379d_B.Max = u1;

          /* Switch: '<S138>/speed check' */
          if (mcb_pmsm_hall_offset_f28379d_B.Max >= 25000000UL) {
            /* Switch: '<S138>/speed check' incorporates:
             *  Constant: '<S138>/Constant'
             */
            mcb_pmsm_hall_offset_f28379d_B.speedcheck = 0U;
          } else {
            /* Logic: '<S134>/Logical Operator' */
            mcb_pmsm_hall_offset_f28379d_B.LogicalOperator =
              (mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion_l3 ||
               mcb_pmsm_hall_offset_f28379d_B.validityDelay);

            /* Switch: '<S138>/speed check' */
            mcb_pmsm_hall_offset_f28379d_B.speedcheck =
              mcb_pmsm_hall_offset_f28379d_B.LogicalOperator;
          }

          /* End of Switch: '<S138>/speed check' */

          /* Switch: '<S138>/watchdog check' */
          mcb_pmsm_hall_offset_f28379d_B.watchdogcheck =
            mcb_pmsm_hall_offset_f28379d_B.speedcheck;
        } else {
          /* Switch: '<S138>/watchdog check' incorporates:
           *  Constant: '<S138>/Constant'
           */
          mcb_pmsm_hall_offset_f28379d_B.watchdogcheck = 0U;
        }

        /* End of Switch: '<S138>/watchdog check' */

        /* If: '<S132>/If' */
        if (mcb_pmsm_hall_offset_f28379d_B.watchdogcheck != 0U) {
          /* Outputs for IfAction SubSystem: '<S132>/Speed and direction are valid Use speed to extrapolate position' incorporates:
           *  ActionPort: '<S137>/Action Port'
           */
          /* DataTypeConversion: '<S137>/currentSpeedData' */
          mcb_pmsm_hall_offset_f28379d_B.currentSpeedData = (real32_T)
            mcb_pmsm_hall_offset_f28379d_B.DataStoreRead2;

          /* Product: '<S137>/Divide' */
          mcb_pmsm_hall_offset_f28379d_B.Divide =
            mcb_pmsm_hall_offset_f28_ConstB.SpeedConstData /
            mcb_pmsm_hall_offset_f28379d_B.currentSpeedData;

          /* Gain: '<S137>/SpeedGain' */
          mcb_pmsm_hall_offset_f28379d_B.SpeedGain = 0.00333333341F *
            mcb_pmsm_hall_offset_f28379d_B.Divide;

          /* If: '<S137>/If' */
          if (mcb_pmsm_hall_offset_f28379d_B.DataStoreRead3 > 0) {
            /* Outputs for IfAction SubSystem: '<S137>/If Action Subsystem' incorporates:
             *  ActionPort: '<S148>/Action Port'
             */
            /* Merge: '<S132>/Merge' incorporates:
             *  SignalConversion generated from: '<S148>/In1'
             */
            mcb_pmsm_hall_offset_f28379d_B.Merge =
              mcb_pmsm_hall_offset_f28379d_B.SpeedGain;

            /* End of Outputs for SubSystem: '<S137>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S137>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S149>/Action Port'
             */
            /* Merge: '<S132>/Merge' incorporates:
             *  UnaryMinus: '<S149>/Unary Minus'
             */
            mcb_pmsm_hall_offset_f28379d_B.Merge =
              -mcb_pmsm_hall_offset_f28379d_B.SpeedGain;

            /* End of Outputs for SubSystem: '<S137>/If Action Subsystem1' */
          }

          /* End of If: '<S137>/If' */

          /* Outputs for Enabled SubSystem: '<S137>/Subsystem1' incorporates:
           *  EnablePort: '<S150>/Enable'
           */
          /* Outputs for IfAction SubSystem: '<S150>/first_order' incorporates:
           *  ActionPort: '<S153>/Action Port'
           */
          /* If: '<S150>/If1' incorporates:
           *  DataTypeConversion: '<S153>/countData'
           *  DataTypeConversion: '<S153>/currentSpeedData'
           *  Gain: '<S153>/Gain'
           *  Merge: '<S150>/Merge1'
           *  Product: '<S153>/Divide'
           */
          mcb_pmsm_hall_offset_f28379d_B.countData = (real32_T)
            mcb_pmsm_hall_offset_f28379d_B.Min;
          mcb_pmsm_hall_offset_f28379d_B.currentSpeedData_e = (real32_T)
            mcb_pmsm_hall_offset_f28379d_B.DataStoreRead2;
          mcb_pmsm_hall_offset_f28379d_B.Divide_n =
            mcb_pmsm_hall_offset_f28379d_B.countData /
            mcb_pmsm_hall_offset_f28379d_B.currentSpeedData_e;
          mcb_pmsm_hall_offset_f28379d_B.Merge1_m = 0.5F *
            mcb_pmsm_hall_offset_f28379d_B.Divide_n;

          /* End of Outputs for SubSystem: '<S150>/first_order' */

          /* Saturate: '<S150>/Saturation' */
          u0_p = mcb_pmsm_hall_offset_f28379d_B.Merge1_m;
          if (u0_p > 0.16667F) {
            /* Saturate: '<S150>/Saturation' */
            mcb_pmsm_hall_offset_f28379d_B.Saturation = 0.16667F;
          } else {
            /* Saturate: '<S150>/Saturation' */
            mcb_pmsm_hall_offset_f28379d_B.Saturation = u0_p;
          }

          /* End of Saturate: '<S150>/Saturation' */

          /* If: '<S150>/If' */
          if (mcb_pmsm_hall_offset_f28379d_B.DataStoreRead3 != 1) {
            /* Outputs for IfAction SubSystem: '<S150>/-ve Direction' incorporates:
             *  ActionPort: '<S152>/Action Port'
             */
            /* SwitchCase: '<S152>/Switch Case' */
            switch ((int32_T)mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_o)
        {
             case 5L:
              /* Outputs for IfAction SubSystem: '<S152>/Hall Value of 1' incorporates:
               *  ActionPort: '<S162>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof1
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_d);

              /* End of Outputs for SubSystem: '<S152>/Hall Value of 1' */
              break;

             case 4L:
              /* Outputs for IfAction SubSystem: '<S152>/Hall Value of 2' incorporates:
               *  ActionPort: '<S163>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof2
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_d);

              /* End of Outputs for SubSystem: '<S152>/Hall Value of 2' */
              break;

             case 6L:
              /* Outputs for IfAction SubSystem: '<S152>/Hall Value of 3' incorporates:
               *  ActionPort: '<S164>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof3
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_d);

              /* End of Outputs for SubSystem: '<S152>/Hall Value of 3' */
              break;

             case 2L:
              /* Outputs for IfAction SubSystem: '<S152>/Hall Value of 4' incorporates:
               *  ActionPort: '<S165>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof4
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_d);

              /* End of Outputs for SubSystem: '<S152>/Hall Value of 4' */
              break;

             case 3L:
              /* Outputs for IfAction SubSystem: '<S152>/Hall Value of 5' incorporates:
               *  ActionPort: '<S166>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof5
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_d);

              /* End of Outputs for SubSystem: '<S152>/Hall Value of 5' */
              break;

             case 1L:
              /* Outputs for IfAction SubSystem: '<S152>/Hall Value of 6' incorporates:
               *  ActionPort: '<S167>/Action Port'
               */
              /* Merge: '<S152>/Merge1' incorporates:
               *  Constant: '<S167>/Constant'
               *  SignalConversion generated from: '<S167>/position'
               */
              mcb_pmsm_hall_offset_f28379d_B.Merge1_d = 1.0F;

              /* End of Outputs for SubSystem: '<S152>/Hall Value of 6' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S152>/Hall Value of 7' incorporates:
               *  ActionPort: '<S168>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof7
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_d);

              /* End of Outputs for SubSystem: '<S152>/Hall Value of 7' */
              break;
            }

            /* End of SwitchCase: '<S152>/Switch Case' */

            /* Merge: '<S150>/Merge' incorporates:
             *  Sum: '<S152>/Sum'
             */
            mcb_pmsm_hall_offset_f28379d_B.Merge_f =
              mcb_pmsm_hall_offset_f28379d_B.Merge1_d -
              mcb_pmsm_hall_offset_f28379d_B.Saturation;

            /* End of Outputs for SubSystem: '<S150>/-ve Direction' */
          } else {
            /* Outputs for IfAction SubSystem: '<S150>/+ve Direction' incorporates:
             *  ActionPort: '<S151>/Action Port'
             */
            /* SwitchCase: '<S151>/Switch Case' */
            switch ((int32_T)mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_o)
        {
             case 5L:
              /* Outputs for IfAction SubSystem: '<S151>/Hall Value of 1' incorporates:
               *  ActionPort: '<S155>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof7
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_p);

              /* End of Outputs for SubSystem: '<S151>/Hall Value of 1' */
              break;

             case 4L:
              /* Outputs for IfAction SubSystem: '<S151>/Hall Value of 2' incorporates:
               *  ActionPort: '<S156>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof1
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_p);

              /* End of Outputs for SubSystem: '<S151>/Hall Value of 2' */
              break;

             case 6L:
              /* Outputs for IfAction SubSystem: '<S151>/Hall Value of 3' incorporates:
               *  ActionPort: '<S157>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof2
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_p);

              /* End of Outputs for SubSystem: '<S151>/Hall Value of 3' */
              break;

             case 2L:
              /* Outputs for IfAction SubSystem: '<S151>/Hall Value of 4' incorporates:
               *  ActionPort: '<S158>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof3
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_p);

              /* End of Outputs for SubSystem: '<S151>/Hall Value of 4' */
              break;

             case 3L:
              /* Outputs for IfAction SubSystem: '<S151>/Hall Value of 5' incorporates:
               *  ActionPort: '<S159>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof4
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_p);

              /* End of Outputs for SubSystem: '<S151>/Hall Value of 5' */
              break;

             case 1L:
              /* Outputs for IfAction SubSystem: '<S151>/Hall Value of 6' incorporates:
               *  ActionPort: '<S160>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof5
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_p);

              /* End of Outputs for SubSystem: '<S151>/Hall Value of 6' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S151>/Hall Value of 7' incorporates:
               *  ActionPort: '<S161>/Action Port'
               */
              mcb_pmsm_hall_offs_HallValueof7
                (&mcb_pmsm_hall_offset_f28379d_B.Merge1_p);

              /* End of Outputs for SubSystem: '<S151>/Hall Value of 7' */
              break;
            }

            /* End of SwitchCase: '<S151>/Switch Case' */

            /* Merge: '<S150>/Merge' incorporates:
             *  Sum: '<S151>/Sum'
             */
            mcb_pmsm_hall_offset_f28379d_B.Merge_f =
              mcb_pmsm_hall_offset_f28379d_B.Merge1_p +
              mcb_pmsm_hall_offset_f28379d_B.Saturation;

            /* End of Outputs for SubSystem: '<S150>/+ve Direction' */
          }

          /* End of If: '<S150>/If' */
          /* End of Outputs for SubSystem: '<S137>/Subsystem1' */

          /* Merge: '<S132>/Merge1' incorporates:
           *  SignalConversion generated from: '<S137>/rawPosition'
           */
          mcb_pmsm_hall_offset_f28379d_B.Merge1 =
            mcb_pmsm_hall_offset_f28379d_B.Merge_f;

          /* End of Outputs for SubSystem: '<S132>/Speed and direction are valid Use speed to extrapolate position' */
        } else {
          /* Outputs for IfAction SubSystem: '<S132>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
           *  ActionPort: '<S136>/Action Port'
           */
          /* SwitchCase: '<S140>/Switch Case' */
          switch ((int32_T)mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_o) {
           case 5L:
            /* Outputs for IfAction SubSystem: '<S140>/Hall Value of 1' incorporates:
             *  ActionPort: '<S141>/Action Port'
             */
            /* Merge: '<S132>/Merge1' incorporates:
             *  Constant: '<S141>/Constant'
             *  SignalConversion generated from: '<S141>/position'
             */
            mcb_pmsm_hall_offset_f28379d_B.Merge1 = 0.083333F;

            /* End of Outputs for SubSystem: '<S140>/Hall Value of 1' */
            break;

           case 4L:
            /* Outputs for IfAction SubSystem: '<S140>/Hall Value of 2' incorporates:
             *  ActionPort: '<S142>/Action Port'
             */
            /* Merge: '<S132>/Merge1' incorporates:
             *  Constant: '<S142>/Constant'
             *  SignalConversion generated from: '<S142>/position'
             */
            mcb_pmsm_hall_offset_f28379d_B.Merge1 = 0.25F;

            /* End of Outputs for SubSystem: '<S140>/Hall Value of 2' */
            break;

           case 6L:
            /* Outputs for IfAction SubSystem: '<S140>/Hall Value of 3' incorporates:
             *  ActionPort: '<S143>/Action Port'
             */
            /* Merge: '<S132>/Merge1' incorporates:
             *  Constant: '<S143>/Constant'
             *  SignalConversion generated from: '<S143>/position'
             */
            mcb_pmsm_hall_offset_f28379d_B.Merge1 = 0.41667F;

            /* End of Outputs for SubSystem: '<S140>/Hall Value of 3' */
            break;

           case 2L:
            /* Outputs for IfAction SubSystem: '<S140>/Hall Value of 4' incorporates:
             *  ActionPort: '<S144>/Action Port'
             */
            /* Merge: '<S132>/Merge1' incorporates:
             *  Constant: '<S144>/Constant'
             *  SignalConversion generated from: '<S144>/position'
             */
            mcb_pmsm_hall_offset_f28379d_B.Merge1 = 0.58333F;

            /* End of Outputs for SubSystem: '<S140>/Hall Value of 4' */
            break;

           case 3L:
            /* Outputs for IfAction SubSystem: '<S140>/Hall Value of 5' incorporates:
             *  ActionPort: '<S145>/Action Port'
             */
            /* Merge: '<S132>/Merge1' incorporates:
             *  Constant: '<S145>/Constant'
             *  SignalConversion generated from: '<S145>/position'
             */
            mcb_pmsm_hall_offset_f28379d_B.Merge1 = 0.75F;

            /* End of Outputs for SubSystem: '<S140>/Hall Value of 5' */
            break;

           case 1L:
            /* Outputs for IfAction SubSystem: '<S140>/Hall Value of 6' incorporates:
             *  ActionPort: '<S146>/Action Port'
             */
            /* Merge: '<S132>/Merge1' incorporates:
             *  Constant: '<S146>/Constant'
             *  SignalConversion generated from: '<S146>/position'
             */
            mcb_pmsm_hall_offset_f28379d_B.Merge1 = 0.91667F;

            /* End of Outputs for SubSystem: '<S140>/Hall Value of 6' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S140>/Hall Value of 7' incorporates:
             *  ActionPort: '<S147>/Action Port'
             */
            mcb_pmsm_hall_offs_HallValueof7
              (&mcb_pmsm_hall_offset_f28379d_B.Merge1);

            /* End of Outputs for SubSystem: '<S140>/Hall Value of 7' */
            break;
          }

          /* End of SwitchCase: '<S140>/Switch Case' */

          /* Merge: '<S132>/Merge' incorporates:
           *  Constant: '<S136>/Constant'
           *  SignalConversion generated from: '<S136>/Speed(r.p.m)'
           */
          mcb_pmsm_hall_offset_f28379d_B.Merge = 0.0F;

          /* End of Outputs for SubSystem: '<S132>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
        }

        /* End of If: '<S132>/If' */

        /* Sum: '<S135>/Sum' incorporates:
         *  Constant: '<S135>/Constant2'
         */
        mcb_pmsm_hall_offset_f28379d_B.Sum_dm =
          mcb_pmsm_hall_offset_f28379d_B.DelayOneStep - 1U;

        /* UnitDelay: '<S124>/Output' */
        mcb_pmsm_hall_offset_f28379d_B.Output =
          mcb_pmsm_hall_offset_f283_DWork.Output_DSTATE;

        /* DataStoreRead: '<S77>/Data Store Read' */
        mcb_pmsm_hall_offset_f28379d_B.DataStoreRead_l =
          mcb_pmsm_hall_offset_f283_DWork.Enable;

        /* Outputs for Enabled SubSystem: '<S77>/PosGen' incorporates:
         *  EnablePort: '<S85>/Enable'
         */
        if (mcb_pmsm_hall_offset_f28379d_B.DataStoreRead_l) {
          if (!mcb_pmsm_hall_offset_f283_DWork.PosGen_MODE) {
            /* InitializeConditions for UnitDelay: '<S105>/Unit Delay' */
            mcb_pmsm_hall_offset_f283_DWork.UnitDelay_DSTATE = 0.0F;
            mcb_pmsm_hall_offset_f283_DWork.PosGen_MODE = true;
          }

          /* Outputs for Enabled SubSystem: '<S85>/Up Counter' incorporates:
           *  EnablePort: '<S102>/Enable'
           */
          if (!mcb_pmsm_hall_offset_f283_DWork.UpCounter_MODE) {
            /* InitializeConditions for Delay: '<S102>/Delay' */
            mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE_ip = 0UL;
            mcb_pmsm_hall_offset_f283_DWork.UpCounter_MODE = true;
          }

          /* Delay: '<S102>/Delay' */
          mcb_pmsm_hall_offset_f28379d_B.Delay =
            mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE_ip;

          /* Sum: '<S102>/Add1' incorporates:
           *  Constant: '<S102>/Constant'
           */
          tmp = mcb_pmsm_hall_offset_f28379d_B.Delay + 1ULL;
          if (tmp > 4294967295ULL) {
            tmp = 4294967295ULL;
          }

          /* Sum: '<S102>/Add1' */
          mcb_pmsm_hall_offset_f28379d_B.Add1 = (uint32_T)tmp;

          /* Update for Delay: '<S102>/Delay' */
          mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE_ip =
            mcb_pmsm_hall_offset_f28379d_B.Add1;

          /* End of Outputs for SubSystem: '<S85>/Up Counter' */

          /* RelationalOperator: '<S98>/Compare' incorporates:
           *  Constant: '<S98>/Constant'
           */
          mcb_pmsm_hall_offset_f28379d_B.Compare_b =
            (mcb_pmsm_hall_offset_f28379d_B.Add1 <= 352000UL);

          /* Logic: '<S85>/NOT' */
          mcb_pmsm_hall_offset_f28379d_B.NOT_p =
            !mcb_pmsm_hall_offset_f28379d_B.Compare_b;

          /* Outputs for Enabled SubSystem: '<S85>/Subsystem' incorporates:
           *  EnablePort: '<S100>/Enable'
           */
          if (mcb_pmsm_hall_offset_f28379d_B.NOT_p) {
            /* DataStoreWrite: '<S100>/Data Store Write' incorporates:
             *  Constant: '<S100>/Constant'
             */
            mcb_pmsm_hall_offset_f283_DWork.Enable = false;
          }

          /* End of Outputs for SubSystem: '<S85>/Subsystem' */

          /* RelationalOperator: '<S99>/Compare' incorporates:
           *  Constant: '<S99>/Constant'
           */
          mcb_pmsm_hall_offset_f28379d_B.Compare_i =
            (mcb_pmsm_hall_offset_f28379d_B.Add1 <= 320000UL);

          /* If: '<S101>/If' incorporates:
           *  Constant: '<S101>/Count for 2 sec'
           */
          if (mcb_pmsm_hall_offset_f28379d_B.Add1 < 40000UL) {
            /* Outputs for IfAction SubSystem: '<S101>/If Action Subsystem' incorporates:
             *  ActionPort: '<S103>/Action Port'
             */
            /* Merge: '<S101>/Merge' incorporates:
             *  Constant: '<S103>/Constant'
             *  SignalConversion generated from: '<S103>/Out1'
             */
            mcb_pmsm_hall_offset_f28379d_B.Merge_fz = 0.0F;

            /* End of Outputs for SubSystem: '<S101>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S101>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S104>/Action Port'
             */
            /* Delay: '<S104>/Delay' */
            mcb_pmsm_hall_offset_f28379d_B.Delay_j =
              mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE;

            /* Sum: '<S104>/Add1' incorporates:
             *  Constant: '<S104>/Constant1'
             */
            mcb_pmsm_hall_offset_f28379d_B.Add1_o =
              mcb_pmsm_hall_offset_f28379d_B.Delay_j + 0.001F;

            /* Saturate: '<S104>/Saturate to 'motor.calibSpeed' RPM' */
            u0_p = mcb_pmsm_hall_offset_f28379d_B.Add1_o;
            if (u0_p > 12.0F) {
              /* Saturate: '<S104>/Saturate to 'motor.calibSpeed' RPM' */
              mcb_pmsm_hall_offset_f28379d_B.SaturatetomotorcalibSpeedRPM =
                12.0F;
            } else if (u0_p < 0.0F) {
              /* Saturate: '<S104>/Saturate to 'motor.calibSpeed' RPM' */
              mcb_pmsm_hall_offset_f28379d_B.SaturatetomotorcalibSpeedRPM = 0.0F;
            } else {
              /* Saturate: '<S104>/Saturate to 'motor.calibSpeed' RPM' */
              mcb_pmsm_hall_offset_f28379d_B.SaturatetomotorcalibSpeedRPM = u0_p;
            }

            /* End of Saturate: '<S104>/Saturate to 'motor.calibSpeed' RPM' */

            /* Merge: '<S101>/Merge' incorporates:
             *  Gain: '<S104>/Multiply'
             */
            mcb_pmsm_hall_offset_f28379d_B.Merge_fz = 6.25E-5F *
              mcb_pmsm_hall_offset_f28379d_B.SaturatetomotorcalibSpeedRPM;

            /* Update for Delay: '<S104>/Delay' */
            mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE =
              mcb_pmsm_hall_offset_f28379d_B.SaturatetomotorcalibSpeedRPM;

            /* End of Outputs for SubSystem: '<S101>/If Action Subsystem2' */
          }

          /* End of If: '<S101>/If' */

          /* UnitDelay: '<S105>/Unit Delay' */
          mcb_pmsm_hall_offset_f28379d_B.UnitDelay =
            mcb_pmsm_hall_offset_f283_DWork.UnitDelay_DSTATE;

          /* Logic: '<S105>/NOT' */
          mcb_pmsm_hall_offset_f28379d_B.NOT_h = true;

          /* Outputs for Enabled SubSystem: '<S105>/Accumulate' incorporates:
           *  EnablePort: '<S106>/Enable'
           */
          /* Delay: '<S106>/Delay' */
          mcb_pmsm_hall_offset_f28379d_B.Delay_c =
            mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE_a;

          /* Outputs for Enabled SubSystem: '<S106>/Subsystem' incorporates:
           *  EnablePort: '<S107>/Enable'
           */
          if (mcb_pmsm_hall_offset_f28379d_B.Delay_c) {
            /* SignalConversion generated from: '<S107>/Input' */
            mcb_pmsm_hall_offset_f28379d_B.Input_h =
              mcb_pmsm_hall_offset_f28379d_B.Merge_fz;
          }

          /* End of Outputs for SubSystem: '<S106>/Subsystem' */

          /* Sum: '<S106>/Add' */
          mcb_pmsm_hall_offset_f28379d_B.Add_j =
            mcb_pmsm_hall_offset_f28379d_B.Input_h +
            mcb_pmsm_hall_offset_f28379d_B.UnitDelay;

          /* DataTypeConversion: '<S106>/Data Type Conversion' */
          mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion_f = (int16_T)
            (real32_T)floor(mcb_pmsm_hall_offset_f28379d_B.Add_j);

          /* DataTypeConversion: '<S106>/Data Type Conversion1' */
          mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1_o =
            mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion_f;

          /* Sum: '<S106>/Add1' */
          mcb_pmsm_hall_offset_f28379d_B.Add1_g =
            mcb_pmsm_hall_offset_f28379d_B.Add_j -
            mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1_o;

          /* Update for Delay: '<S106>/Delay' incorporates:
           *  Constant: '<S106>/Constant'
           */
          mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE_a = true;

          /* End of Outputs for SubSystem: '<S105>/Accumulate' */

          /* Gain: '<S105>/scaleOut' */
          mcb_pmsm_hall_offset_f28379d_B.scaleOut =
            mcb_pmsm_hall_offset_f28379d_B.Add1_g;

          /* Update for UnitDelay: '<S105>/Unit Delay' */
          mcb_pmsm_hall_offset_f283_DWork.UnitDelay_DSTATE =
            mcb_pmsm_hall_offset_f28379d_B.Add1_g;
        } else if (mcb_pmsm_hall_offset_f283_DWork.PosGen_MODE) {
          /* Disable for Enabled SubSystem: '<S85>/Up Counter' */
          if (mcb_pmsm_hall_offset_f283_DWork.UpCounter_MODE) {
            /* Disable for Sum: '<S102>/Add1' incorporates:
             *  Outport: '<S102>/Count'
             */
            mcb_pmsm_hall_offset_f28379d_B.Add1 = 0UL;
            mcb_pmsm_hall_offset_f283_DWork.UpCounter_MODE = false;
          }

          /* End of Disable for SubSystem: '<S85>/Up Counter' */

          /* Disable for RelationalOperator: '<S99>/Compare' incorporates:
           *  Outport: '<S85>/EnPWM'
           */
          mcb_pmsm_hall_offset_f28379d_B.Compare_i = false;

          /* Disable for RelationalOperator: '<S98>/Compare' incorporates:
           *  Outport: '<S85>/EnableHost'
           */
          mcb_pmsm_hall_offset_f28379d_B.Compare_b = false;
          mcb_pmsm_hall_offset_f283_DWork.PosGen_MODE = false;
        }

        /* End of Outputs for SubSystem: '<S77>/PosGen' */

        /* Switch: '<S6>/Switch' */
        if (mcb_pmsm_hall_offset_f28379d_B.Compare_b) {
          /* Switch: '<S6>/Switch' */
          mcb_pmsm_hall_offset_f28379d_B.Switch_g =
            mcb_pmsm_hall_offset_f28379d_B.Merge1;
        } else {
          /* Switch: '<S6>/Switch' incorporates:
           *  Constant: '<S6>/Constant'
           */
          mcb_pmsm_hall_offset_f28379d_B.Switch_g = -1.0F;
        }

        /* End of Switch: '<S6>/Switch' */

        /* Outputs for Enabled SubSystem: '<S77>/Find Offset' incorporates:
         *  EnablePort: '<S83>/Enable'
         */
        if (mcb_pmsm_hall_offset_f28379d_B.Compare_i) {
          if (!mcb_pmsm_hall_offset_f283_DWork.FindOffset_MODE) {
            /* InitializeConditions for Delay: '<S83>/Delay' */
            mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE_i = 0.0F;
            mcb_pmsm_hall_offset_f283_DWork.FindOffset_MODE = true;
          }

          /* RelationalOperator: '<S89>/Compare' incorporates:
           *  Constant: '<S89>/Constant'
           */
          mcb_pmsm_hall_offset_f28379d_B.Compare_o =
            (mcb_pmsm_hall_offset_f28379d_B.scaleOut <= 0.01F);

          /* Delay: '<S83>/Delay' */
          mcb_pmsm_hall_offset_f28379d_B.Delay_b =
            mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE_i;

          /* RelationalOperator: '<S90>/Compare' incorporates:
           *  Constant: '<S90>/Constant'
           */
          mcb_pmsm_hall_offset_f28379d_B.Compare_jr =
            (mcb_pmsm_hall_offset_f28379d_B.Delay_b >= 0.99F);

          /* Logic: '<S83>/AND' */
          mcb_pmsm_hall_offset_f28379d_B.AND =
            (mcb_pmsm_hall_offset_f28379d_B.Compare_o &&
             mcb_pmsm_hall_offset_f28379d_B.Compare_jr);

          /* Outputs for Enabled SubSystem: '<S83>/Subsystem' incorporates:
           *  EnablePort: '<S91>/Enable'
           */
          if (mcb_pmsm_hall_offset_f28379d_B.AND) {
            /* Product: '<S95>/Product' incorporates:
             *  Constant: '<S95>/Filter_Constant'
             */
            mcb_pmsm_hall_offset_f28379d_B.Product_j =
              mcb_pmsm_hall_offset_f28379d_B.Merge1 * 0.5F;

            /* UnitDelay: '<S95>/Unit Delay' */
            mcb_pmsm_hall_offset_f28379d_B.UnitDelay_p =
              mcb_pmsm_hall_offset_f283_DWork.UnitDelay_DSTATE_o;

            /* Product: '<S95>/Product1' incorporates:
             *  Constant: '<S95>/One'
             */
            mcb_pmsm_hall_offset_f28379d_B.Product1_h = 0.5F *
              mcb_pmsm_hall_offset_f28379d_B.UnitDelay_p;

            /* Sum: '<S95>/Add1' */
            mcb_pmsm_hall_offset_f28379d_B.Add1_ox =
              mcb_pmsm_hall_offset_f28379d_B.Product_j +
              mcb_pmsm_hall_offset_f28379d_B.Product1_h;

            /* Update for UnitDelay: '<S95>/Unit Delay' */
            mcb_pmsm_hall_offset_f283_DWork.UnitDelay_DSTATE_o =
              mcb_pmsm_hall_offset_f28379d_B.Add1_ox;
          }

          /* End of Outputs for SubSystem: '<S83>/Subsystem' */

          /* SignalConversion generated from: '<S83>/Offset' */
          mcb_pmsm_hall_offset_f28379d_B.OutportBufferForOffset =
            mcb_pmsm_hall_offset_f28379d_B.Add1_ox;

          /* Update for Delay: '<S83>/Delay' */
          mcb_pmsm_hall_offset_f283_DWork.Delay_DSTATE_i =
            mcb_pmsm_hall_offset_f28379d_B.scaleOut;
        } else {
          mcb_pmsm_hall_offset_f283_DWork.FindOffset_MODE = false;
        }

        /* End of Outputs for SubSystem: '<S77>/Find Offset' */

        /* Logic: '<S77>/NOT' */
        mcb_pmsm_hall_offset_f28379d_B.NOT =
          !mcb_pmsm_hall_offset_f28379d_B.Compare_i;

        /* Outputs for Enabled SubSystem: '<S77>/Subsystem1' incorporates:
         *  EnablePort: '<S88>/Enable'
         */
        if (mcb_pmsm_hall_offset_f28379d_B.NOT) {
          mcb_pmsm_hall_offset_f283_DWork.Subsystem1_MODE = true;

          /* SignalConversion generated from: '<S88>/Input' */
          mcb_pmsm_hall_offset_f28379d_B.Input =
            mcb_pmsm_hall_offset_f28379d_B.OutportBufferForOffset;
        } else if (mcb_pmsm_hall_offset_f283_DWork.Subsystem1_MODE) {
          /* Disable for SignalConversion generated from: '<S88>/Input' incorporates:
           *  Outport: '<S88>/Offset'
           */
          mcb_pmsm_hall_offset_f28379d_B.Input = 0.0F;
          mcb_pmsm_hall_offset_f283_DWork.Subsystem1_MODE = false;
        }

        /* End of Outputs for SubSystem: '<S77>/Subsystem1' */

        /* SignalConversion generated from: '<S123>/Byte Pack' */
        mcb_pmsm_hall_offset_f28379d_B.TmpSignalConversionAtBytePackIn[0] =
          mcb_pmsm_hall_offset_f28379d_B.Switch_g;
        mcb_pmsm_hall_offset_f28379d_B.TmpSignalConversionAtBytePackIn[1] =
          mcb_pmsm_hall_offset_f28379d_B.Input;

        /* S-Function (any2byte_svd): '<S123>/Byte Pack' */

        /* Pack: <S123>/Byte Pack */
        {
          uint32_T MW_outputPortOffset = 0;
          uint32_T MW_inputPortWidth = 0;
          uint32_T MW_remainder1 = 0;

          /* Packed output data type - uint32_T */
          /* Packing the values of Input 1 */
          /* Input data type - real32_T, size - 2 */
          {
            MW_inputPortWidth = 2 * sizeof(real32_T);
            memcpy((uint16_T*)&mcb_pmsm_hall_offset_f28379d_B.BytePack[0] +
                   MW_outputPortOffset, (uint16_T*)
                   &mcb_pmsm_hall_offset_f28379d_B.TmpSignalConversionAtBytePackIn
                   [0], MW_inputPortWidth);
          }
        }

        /* If: '<S121>/If' */
        if (mcb_pmsm_hall_offset_f28379d_B.Output == 0U) {
          /* Outputs for IfAction SubSystem: '<S121>/Start' incorporates:
           *  ActionPort: '<S127>/Action Port'
           */
          /* Merge: '<S121>/Merge' incorporates:
           *  Constant: '<S127>/Start'
           *  SignalConversion generated from: '<S127>/Data_out'
           */
          mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Data[0] = 1397969747UL;

          /* SignalConversion generated from: '<S127>/Data' */
          u0 = mcb_pmsm_hall_offset_f28379d_B.BytePack[0];

          /* End of Outputs for SubSystem: '<S121>/Start' */
          mcb_pmsm_hall_offset_f28379d_B.Data_fw[0] = u0;

          /* Outputs for IfAction SubSystem: '<S121>/Start' incorporates:
           *  ActionPort: '<S127>/Action Port'
           */
          /* Merge: '<S121>/Merge' incorporates:
           *  SignalConversion generated from: '<S127>/Data_out'
           */
          mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Data[1] = u0;

          /* SignalConversion generated from: '<S127>/Data' */
          u0 = mcb_pmsm_hall_offset_f28379d_B.BytePack[1];

          /* End of Outputs for SubSystem: '<S121>/Start' */
          mcb_pmsm_hall_offset_f28379d_B.Data_fw[1] = u0;

          /* Outputs for IfAction SubSystem: '<S121>/Start' incorporates:
           *  ActionPort: '<S127>/Action Port'
           */
          /* Merge: '<S121>/Merge' incorporates:
           *  SignalConversion generated from: '<S127>/Data_out'
           */
          mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Data[2] = u0;

          /* Merge: '<S121>/Merge1' incorporates:
           *  Bias: '<S127>/Bias'
           */
          mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Iteration =
            mcb_pmsm_hall_offset_f28_ConstB.Width + 1UL;

          /* End of Outputs for SubSystem: '<S121>/Start' */
        } else if (mcb_pmsm_hall_offset_f28379d_B.Output == 599U) {
          /* Outputs for IfAction SubSystem: '<S121>/End' incorporates:
           *  ActionPort: '<S126>/Action Port'
           */
          /* SignalConversion generated from: '<S126>/Data' */
          u0 = mcb_pmsm_hall_offset_f28379d_B.BytePack[0];

          /* End of Outputs for SubSystem: '<S121>/End' */
          mcb_pmsm_hall_offset_f28379d_B.Data_f[0] = u0;

          /* Outputs for IfAction SubSystem: '<S121>/End' incorporates:
           *  ActionPort: '<S126>/Action Port'
           */
          /* Merge: '<S121>/Merge' incorporates:
           *  SignalConversion generated from: '<S126>/Data_out'
           */
          mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Data[0] = u0;

          /* SignalConversion generated from: '<S126>/Data' */
          u0 = mcb_pmsm_hall_offset_f28379d_B.BytePack[1];

          /* End of Outputs for SubSystem: '<S121>/End' */
          mcb_pmsm_hall_offset_f28379d_B.Data_f[1] = u0;

          /* Outputs for IfAction SubSystem: '<S121>/End' incorporates:
           *  ActionPort: '<S126>/Action Port'
           */
          /* Merge: '<S121>/Merge' incorporates:
           *  Constant: '<S126>/End'
           *  SignalConversion generated from: '<S126>/Data_out'
           */
          mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Data[1] = u0;
          mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Data[2] = 1162167621UL;

          /* Merge: '<S121>/Merge1' incorporates:
           *  Bias: '<S126>/Bias'
           */
          mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Iteration =
            mcb_pmsm_hall_offset_f28_ConstB.Width + 1UL;

          /* End of Outputs for SubSystem: '<S121>/End' */
        } else {
          /* Outputs for IfAction SubSystem: '<S121>/Data' incorporates:
           *  ActionPort: '<S125>/Action Port'
           */
          /* SignalConversion generated from: '<S125>/Data' */
          u0 = mcb_pmsm_hall_offset_f28379d_B.BytePack[0];

          /* End of Outputs for SubSystem: '<S121>/Data' */
          mcb_pmsm_hall_offset_f28379d_B.Data[0] = u0;

          /* Outputs for IfAction SubSystem: '<S121>/Data' incorporates:
           *  ActionPort: '<S125>/Action Port'
           */
          /* Merge: '<S121>/Merge' incorporates:
           *  SignalConversion generated from: '<S125>/Data_out'
           */
          mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Data[0] = u0;

          /* SignalConversion generated from: '<S125>/Data' */
          u0 = mcb_pmsm_hall_offset_f28379d_B.BytePack[1];

          /* End of Outputs for SubSystem: '<S121>/Data' */
          mcb_pmsm_hall_offset_f28379d_B.Data[1] = u0;

          /* Outputs for IfAction SubSystem: '<S121>/Data' incorporates:
           *  ActionPort: '<S125>/Action Port'
           */
          /* Merge: '<S121>/Merge' incorporates:
           *  Constant: '<S125>/Dummy'
           *  SignalConversion generated from: '<S125>/Data_out'
           */
          mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Data[1] = u0;
          mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Data[2] = 0UL;

          /* Merge: '<S121>/Merge1' incorporates:
           *  SignalConversion generated from: '<S125>/Data_width'
           */
          mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Iteration =
            mcb_pmsm_hall_offset_f28_ConstB.Width;

          /* End of Outputs for SubSystem: '<S121>/Data' */
        }

        /* End of If: '<S121>/If' */

        /* Outputs for Iterator SubSystem: '<S78>/While Iterator Subsystem' incorporates:
         *  WhileIterator: '<S122>/While Iterator'
         */
        s122_iter = 1;
        do {
          mcb_pmsm_hall_offset_f28379d_B.WhileIterator = s122_iter;
          mcb_pmsm_hall_offset_f28379d_B.IndexVector =
            mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Data[mcb_pmsm_hall_offset_f28379d_B.WhileIterator
            - 1];

          {
            if (checkSCITransmitInProgressA != 1U) {
              checkSCITransmitInProgressA = 1U;
              int16_T errFlgHeader = NOERROR;
              int16_T errFlgData = NOERROR;
              int16_T errFlgTail = NOERROR;
              errFlgData = scia_xmit((unsigned char*)
                &mcb_pmsm_hall_offset_f28379d_B.IndexVector, 4, 4);
              checkSCITransmitInProgressA = 0U;
            }
          }

          mcb_pmsm_hall_offset_f28379d_B.Add =
            mcb_pmsm_hall_offset_f28379d_B.SCI_Tx_Iteration - (uint32_T)
            mcb_pmsm_hall_offset_f28379d_B.WhileIterator;
          s122_iter++;
        } while (mcb_pmsm_hall_offset_f28379d_B.Add != 0UL);

        /* End of Outputs for SubSystem: '<S78>/While Iterator Subsystem' */

        /* Sum: '<S128>/FixPt Sum1' incorporates:
         *  Constant: '<S128>/FixPt Constant'
         */
        mcb_pmsm_hall_offset_f28379d_B.FixPtSum1 =
          mcb_pmsm_hall_offset_f28379d_B.Output + 1U;

        /* Switch: '<S129>/FixPt Switch' */
        if (mcb_pmsm_hall_offset_f28379d_B.FixPtSum1 > 599U) {
          /* Switch: '<S129>/FixPt Switch' incorporates:
           *  Constant: '<S129>/Constant'
           */
          mcb_pmsm_hall_offset_f28379d_B.FixPtSwitch = 0U;
        } else {
          /* Switch: '<S129>/FixPt Switch' */
          mcb_pmsm_hall_offset_f28379d_B.FixPtSwitch =
            mcb_pmsm_hall_offset_f28379d_B.FixPtSum1;
        }

        /* End of Switch: '<S129>/FixPt Switch' */

        /* RelationalOperator: '<S110>/Compare' incorporates:
         *  Constant: '<S110>/Constant'
         */
        mcb_pmsm_hall_offset_f28379d_B.Compare_j =
          (mcb_pmsm_hall_offset_f28379d_B.scaleOut < 0.0F);

        /* DataTypeConversion: '<S109>/Data Type Conversion' */
        mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion_l =
          mcb_pmsm_hall_offset_f28379d_B.Compare_j;

        /* If: '<S109>/If' */
        if (mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion_l > 0U) {
          /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem' incorporates:
           *  ActionPort: '<S111>/Action Port'
           */
          /* DataTypeConversion: '<S111>/Convert_uint16' */
          mcb_pmsm_hall_offset_f28379d_B.Convert_uint16_j = (int16_T)(real32_T)
            floor(mcb_pmsm_hall_offset_f28379d_B.scaleOut);

          /* DataTypeConversion: '<S111>/Convert_back' */
          mcb_pmsm_hall_offset_f28379d_B.Convert_back_h =
            mcb_pmsm_hall_offset_f28379d_B.Convert_uint16_j;

          /* Merge: '<S109>/Merge' incorporates:
           *  Sum: '<S111>/Sum'
           */
          mcb_pmsm_hall_offset_f28379d_B.Merge_j =
            mcb_pmsm_hall_offset_f28379d_B.scaleOut -
            mcb_pmsm_hall_offset_f28379d_B.Convert_back_h;

          /* End of Outputs for SubSystem: '<S109>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S112>/Action Port'
           */
          /* DataTypeConversion: '<S112>/Convert_uint16' */
          mcb_pmsm_hall_offset_f28379d_B.Convert_uint16 = (int16_T)
            mcb_pmsm_hall_offset_f28379d_B.scaleOut;

          /* DataTypeConversion: '<S112>/Convert_back' */
          mcb_pmsm_hall_offset_f28379d_B.Convert_back =
            mcb_pmsm_hall_offset_f28379d_B.Convert_uint16;

          /* Merge: '<S109>/Merge' incorporates:
           *  Sum: '<S112>/Sum'
           */
          mcb_pmsm_hall_offset_f28379d_B.Merge_j =
            mcb_pmsm_hall_offset_f28379d_B.scaleOut -
            mcb_pmsm_hall_offset_f28379d_B.Convert_back;

          /* End of Outputs for SubSystem: '<S109>/If Action Subsystem1' */
        }

        /* End of If: '<S109>/If' */

        /* Gain: '<S86>/indexing' */
        mcb_pmsm_hall_offset_f28379d_B.indexing = 800.0F *
          mcb_pmsm_hall_offset_f28379d_B.Merge_j;

        /* DataTypeConversion: '<S86>/Get_Integer' */
        mcb_pmsm_hall_offset_f28379d_B.Get_Integer = (uint16_T)
          mcb_pmsm_hall_offset_f28379d_B.indexing;

        /* Sum: '<S86>/Sum' incorporates:
         *  Constant: '<S86>/offset'
         */
        u0 = mcb_pmsm_hall_offset_f28379d_B.Get_Integer + 1UL;
        mcb_pmsm_hall_offset_f28379d_B.Sum[0] = u0;

        /* Selector: '<S86>/Lookup' incorporates:
         *  Constant: '<S86>/sine_table_values'
         */
        mcb_pmsm_hall_offset_f28379d_B.Lookup[0] =
          mcb_pmsm_hall_offset_f28_ConstP.sine_table_values_Value[(int16_T)u0];

        /* Sum: '<S86>/Sum' */
        u0 = mcb_pmsm_hall_offset_f28379d_B.Get_Integer;
        mcb_pmsm_hall_offset_f28379d_B.Sum[1] = u0;

        /* Selector: '<S86>/Lookup' incorporates:
         *  Constant: '<S86>/sine_table_values'
         */
        mcb_pmsm_hall_offset_f28379d_B.Lookup[1] =
          mcb_pmsm_hall_offset_f28_ConstP.sine_table_values_Value[(int16_T)u0];

        /* Sum: '<S86>/Sum' incorporates:
         *  Constant: '<S86>/offset'
         */
        u0 = mcb_pmsm_hall_offset_f28379d_B.Get_Integer + 201UL;
        mcb_pmsm_hall_offset_f28379d_B.Sum[2] = u0;

        /* Selector: '<S86>/Lookup' incorporates:
         *  Constant: '<S86>/sine_table_values'
         */
        mcb_pmsm_hall_offset_f28379d_B.Lookup[2] =
          mcb_pmsm_hall_offset_f28_ConstP.sine_table_values_Value[(int16_T)u0];

        /* Sum: '<S86>/Sum' incorporates:
         *  Constant: '<S86>/offset'
         */
        u0 = mcb_pmsm_hall_offset_f28379d_B.Get_Integer + 200UL;
        mcb_pmsm_hall_offset_f28379d_B.Sum[3] = u0;

        /* Selector: '<S86>/Lookup' incorporates:
         *  Constant: '<S86>/sine_table_values'
         */
        mcb_pmsm_hall_offset_f28379d_B.Lookup[3] =
          mcb_pmsm_hall_offset_f28_ConstP.sine_table_values_Value[(int16_T)u0];

        /* Sum: '<S108>/Sum3' */
        mcb_pmsm_hall_offset_f28379d_B.Sum3 =
          mcb_pmsm_hall_offset_f28379d_B.Lookup[0] -
          mcb_pmsm_hall_offset_f28379d_B.Lookup[1];

        /* DataTypeConversion: '<S86>/Data Type Conversion1' */
        mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1 =
          mcb_pmsm_hall_offset_f28379d_B.Get_Integer;

        /* Sum: '<S86>/Sum2' */
        mcb_pmsm_hall_offset_f28379d_B.Sum2 =
          mcb_pmsm_hall_offset_f28379d_B.indexing -
          mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1;

        /* Product: '<S108>/Product' */
        mcb_pmsm_hall_offset_f28379d_B.Product =
          mcb_pmsm_hall_offset_f28379d_B.Sum3 *
          mcb_pmsm_hall_offset_f28379d_B.Sum2;

        /* Sum: '<S108>/Sum4' */
        mcb_pmsm_hall_offset_f28379d_B.Sum4 =
          mcb_pmsm_hall_offset_f28379d_B.Product +
          mcb_pmsm_hall_offset_f28379d_B.Lookup[1];

        /* Sum: '<S108>/Sum5' */
        mcb_pmsm_hall_offset_f28379d_B.Sum5 =
          mcb_pmsm_hall_offset_f28379d_B.Lookup[2] -
          mcb_pmsm_hall_offset_f28379d_B.Lookup[3];

        /* Product: '<S108>/Product1' */
        mcb_pmsm_hall_offset_f28379d_B.Product1 =
          mcb_pmsm_hall_offset_f28379d_B.Sum5 *
          mcb_pmsm_hall_offset_f28379d_B.Sum2;

        /* Sum: '<S108>/Sum6' */
        mcb_pmsm_hall_offset_f28379d_B.Sum6 =
          mcb_pmsm_hall_offset_f28379d_B.Product1 +
          mcb_pmsm_hall_offset_f28379d_B.Lookup[3];

        /* Outputs for Atomic SubSystem: '<S84>/Two inputs CRL' */
        /* Product: '<S96>/qcos' incorporates:
         *  Constant: '<S77>/Constant1'
         */
        mcb_pmsm_hall_offset_f28379d_B.qcos = 0.0F *
          mcb_pmsm_hall_offset_f28379d_B.Sum6;

        /* Product: '<S96>/dsin' incorporates:
         *  Constant: '<S77>/Vd_Ref'
         */
        mcb_pmsm_hall_offset_f28379d_B.dsin = 0.15F *
          mcb_pmsm_hall_offset_f28379d_B.Sum4;

        /* Sum: '<S96>/sum_beta' */
        mcb_pmsm_hall_offset_f28379d_B.sum_beta =
          mcb_pmsm_hall_offset_f28379d_B.qcos +
          mcb_pmsm_hall_offset_f28379d_B.dsin;

        /* Product: '<S96>/dcos' incorporates:
         *  Constant: '<S77>/Vd_Ref'
         */
        mcb_pmsm_hall_offset_f28379d_B.dcos = 0.15F *
          mcb_pmsm_hall_offset_f28379d_B.Sum6;

        /* Product: '<S96>/qsin' incorporates:
         *  Constant: '<S77>/Constant1'
         */
        mcb_pmsm_hall_offset_f28379d_B.qsin = 0.0F *
          mcb_pmsm_hall_offset_f28379d_B.Sum4;

        /* Sum: '<S96>/sum_alpha' */
        mcb_pmsm_hall_offset_f28379d_B.sum_alpha =
          mcb_pmsm_hall_offset_f28379d_B.dcos -
          mcb_pmsm_hall_offset_f28379d_B.qsin;

        /* Switch: '<S97>/Switch' */
        mcb_pmsm_hall_offset_f28379d_B.Switch_k[0] =
          mcb_pmsm_hall_offset_f28379d_B.sum_alpha;
        mcb_pmsm_hall_offset_f28379d_B.Switch_k[1] =
          mcb_pmsm_hall_offset_f28379d_B.sum_beta;

        /* AlgorithmDescriptorDelegate generated from: '<S96>/a16' */
        mcb_pmsm_hall_offset_f28379d_B.algDD_o1 =
          mcb_pmsm_hall_offset_f28379d_B.Switch_k[0];

        /* AlgorithmDescriptorDelegate generated from: '<S96>/a16' */
        mcb_pmsm_hall_offset_f28379d_B.algDD_o2 =
          mcb_pmsm_hall_offset_f28379d_B.Switch_k[1];

        /* End of Outputs for SubSystem: '<S84>/Two inputs CRL' */

        /* Switch: '<S80>/Switch4' */
        if (mcb_pmsm_hall_offset_f28379d_B.Compare_i) {
          /* Gain: '<S119>/sqrt3_by_two' */
          mcb_pmsm_hall_offset_f28379d_B.sqrt3_by_two = 0.866025388F *
            mcb_pmsm_hall_offset_f28379d_B.algDD_o2;

          /* Gain: '<S119>/one_by_two' */
          mcb_pmsm_hall_offset_f28379d_B.one_by_two = 0.5F *
            mcb_pmsm_hall_offset_f28379d_B.algDD_o1;

          /* Sum: '<S119>/add_c' */
          mcb_pmsm_hall_offset_f28379d_B.add_c = (0.0F -
            mcb_pmsm_hall_offset_f28379d_B.one_by_two) -
            mcb_pmsm_hall_offset_f28379d_B.sqrt3_by_two;

          /* Sum: '<S119>/add_b' */
          mcb_pmsm_hall_offset_f28379d_B.add_b =
            mcb_pmsm_hall_offset_f28379d_B.sqrt3_by_two -
            mcb_pmsm_hall_offset_f28379d_B.one_by_two;

          /* MinMax: '<S116>/Min' */
          u0_p = mcb_pmsm_hall_offset_f28379d_B.algDD_o1;
          Bias = mcb_pmsm_hall_offset_f28379d_B.add_b;
          if ((u0_p <= Bias) || rtIsNaNF(Bias)) {
            Bias = u0_p;
          }

          u0_p = mcb_pmsm_hall_offset_f28379d_B.add_c;
          if ((!(Bias <= u0_p)) && (!rtIsNaNF(u0_p))) {
            Bias = u0_p;
          }

          /* MinMax: '<S116>/Min' */
          mcb_pmsm_hall_offset_f28379d_B.Min_a = Bias;

          /* MinMax: '<S116>/Max' */
          u0_p = mcb_pmsm_hall_offset_f28379d_B.algDD_o1;
          Bias = mcb_pmsm_hall_offset_f28379d_B.add_b;
          if ((u0_p >= Bias) || rtIsNaNF(Bias)) {
            Bias = u0_p;
          }

          u0_p = mcb_pmsm_hall_offset_f28379d_B.add_c;
          if ((!(Bias >= u0_p)) && (!rtIsNaNF(u0_p))) {
            Bias = u0_p;
          }

          /* MinMax: '<S116>/Max' */
          mcb_pmsm_hall_offset_f28379d_B.Max_h = Bias;

          /* Sum: '<S116>/Add' */
          mcb_pmsm_hall_offset_f28379d_B.Add_i =
            mcb_pmsm_hall_offset_f28379d_B.Max_h +
            mcb_pmsm_hall_offset_f28379d_B.Min_a;

          /* Gain: '<S116>/one_by_two' */
          mcb_pmsm_hall_offset_f28379d_B.one_by_two_b = -0.5F *
            mcb_pmsm_hall_offset_f28379d_B.Add_i;

          /* Sum: '<S115>/Add2' */
          mcb_pmsm_hall_offset_f28379d_B.Add2 =
            mcb_pmsm_hall_offset_f28379d_B.one_by_two_b +
            mcb_pmsm_hall_offset_f28379d_B.add_c;

          /* Sum: '<S115>/Add1' */
          mcb_pmsm_hall_offset_f28379d_B.Add1_m =
            mcb_pmsm_hall_offset_f28379d_B.add_b +
            mcb_pmsm_hall_offset_f28379d_B.one_by_two_b;

          /* Sum: '<S115>/Add3' */
          mcb_pmsm_hall_offset_f28379d_B.Add3 =
            mcb_pmsm_hall_offset_f28379d_B.algDD_o1 +
            mcb_pmsm_hall_offset_f28379d_B.one_by_two_b;

          /* Gain: '<S115>/Gain' */
          mcb_pmsm_hall_offset_f28379d_B.Gain[0] = 1.15470052F *
            mcb_pmsm_hall_offset_f28379d_B.Add3;
          mcb_pmsm_hall_offset_f28379d_B.Gain[1] = 1.15470052F *
            mcb_pmsm_hall_offset_f28379d_B.Add1_m;
          mcb_pmsm_hall_offset_f28379d_B.Gain[2] = 1.15470052F *
            mcb_pmsm_hall_offset_f28379d_B.Add2;

          /* Sum: '<S80>/Sum' incorporates:
           *  Constant: '<S80>/Constant'
           */
          Bias = mcb_pmsm_hall_offset_f28379d_B.Gain[0] + 1.0F;
          mcb_pmsm_hall_offset_f28379d_B.Sum_d[0] = Bias;

          /* Gain: '<S80>/Gain' */
          Bias *= 0.5F;
          mcb_pmsm_hall_offset_f28379d_B.Gain_h[0] = Bias;

          /* Gain: '<S80>/Scale_to_PWM_Counter_PRD' */
          Scale_to_PWM_Counter_PRD = (uint16_T)(6250.0F * Bias);
          mcb_pmsm_hall_offset_f28379d_B.Scale_to_PWM_Counter_PRD[0] =
            Scale_to_PWM_Counter_PRD;

          /* Switch: '<S80>/Switch4' */
          mcb_pmsm_hall_offset_f28379d_B.Switch4[0] = Scale_to_PWM_Counter_PRD;

          /* Sum: '<S80>/Sum' incorporates:
           *  Constant: '<S80>/Constant'
           */
          Bias = mcb_pmsm_hall_offset_f28379d_B.Gain[1] + 1.0F;
          mcb_pmsm_hall_offset_f28379d_B.Sum_d[1] = Bias;

          /* Gain: '<S80>/Gain' */
          Bias *= 0.5F;
          mcb_pmsm_hall_offset_f28379d_B.Gain_h[1] = Bias;

          /* Gain: '<S80>/Scale_to_PWM_Counter_PRD' */
          Scale_to_PWM_Counter_PRD = (uint16_T)(6250.0F * Bias);
          mcb_pmsm_hall_offset_f28379d_B.Scale_to_PWM_Counter_PRD[1] =
            Scale_to_PWM_Counter_PRD;

          /* Switch: '<S80>/Switch4' */
          mcb_pmsm_hall_offset_f28379d_B.Switch4[1] = Scale_to_PWM_Counter_PRD;

          /* Sum: '<S80>/Sum' incorporates:
           *  Constant: '<S80>/Constant'
           */
          Bias = mcb_pmsm_hall_offset_f28379d_B.Gain[2] + 1.0F;
          mcb_pmsm_hall_offset_f28379d_B.Sum_d[2] = Bias;

          /* Gain: '<S80>/Gain' */
          Bias *= 0.5F;
          mcb_pmsm_hall_offset_f28379d_B.Gain_h[2] = Bias;

          /* Gain: '<S80>/Scale_to_PWM_Counter_PRD' */
          Scale_to_PWM_Counter_PRD = (uint16_T)(6250.0F * Bias);
          mcb_pmsm_hall_offset_f28379d_B.Scale_to_PWM_Counter_PRD[2] =
            Scale_to_PWM_Counter_PRD;

          /* Switch: '<S80>/Switch4' */
          mcb_pmsm_hall_offset_f28379d_B.Switch4[2] = Scale_to_PWM_Counter_PRD;
        } else {
          /* Switch: '<S80>/Switch4' incorporates:
           *  Constant: '<S80>/stop'
           */
          mcb_pmsm_hall_offset_f28379d_B.Switch4[0] = 0U;
          mcb_pmsm_hall_offset_f28379d_B.Switch4[1] = 0U;
          mcb_pmsm_hall_offset_f28379d_B.Switch4[2] = 0U;
        }

        /* End of Switch: '<S80>/Switch4' */

        /* S-Function (c2802xpwm): '<S81>/ePWM1' */

        /*-- Update CMPA value for ePWM1 --*/
        {
          EPwm1Regs.CMPA.bit.CMPA = (uint16_T)
            (mcb_pmsm_hall_offset_f28379d_B.Switch4[0]);
        }

        /* S-Function (c2802xpwm): '<S81>/ePWM2' */

        /*-- Update CMPA value for ePWM2 --*/
        {
          EPwm2Regs.CMPA.bit.CMPA = (uint16_T)
            (mcb_pmsm_hall_offset_f28379d_B.Switch4[1]);
        }

        /* S-Function (c2802xpwm): '<S81>/ePWM3' */

        /*-- Update CMPA value for ePWM3 --*/
        {
          EPwm3Regs.CMPA.bit.CMPA = (uint16_T)
            (mcb_pmsm_hall_offset_f28379d_B.Switch4[2]);
        }

        /* Switch: '<S81>/Switch' */
        mcb_pmsm_hall_offset_f28379d_B.Switch_c =
          mcb_pmsm_hall_offset_f28379d_B.Compare_i;

        /* S-Function (c280xgpio_do): '<S81>/DRV830x Enable' */
        {
          if (mcb_pmsm_hall_offset_f28379d_B.Switch_c) {
            GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
          } else {
            GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
          }
        }

        /* S-Function (c2802xadc): '<S6>/ADC_B_IN2' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          mcb_pmsm_hall_offset_f28379d_B.ADC_B_IN2 = (AdcbResultRegs.ADCRESULT0);
        }

        /* S-Function (c2802xadc): '<S6>/ADC_C_IN2' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          mcb_pmsm_hall_offset_f28379d_B.ADC_C_IN2 = (AdccResultRegs.ADCRESULT0);
        }

        /* Update for Delay: '<S135>/Delay One Step1' */
        mcb_pmsm_hall_offset_f283_DWork.DelayOneStep1_DSTATE =
          mcb_pmsm_hall_offset_f28379d_B.Compare;

        /* Update for Delay: '<S135>/Delay One Step' */
        if (mcb_pmsm_hall_offset_f28379d_B.OR) {
          mcb_pmsm_hall_offset_f283_DWork.DelayOneStep_DSTATE =
            mcb_pmsm_hall_offset_f28379d_B.Sum_dm;
        }

        /* End of Update for Delay: '<S135>/Delay One Step' */

        /* Update for UnitDelay: '<S124>/Output' */
        mcb_pmsm_hall_offset_f283_DWork.Output_DSTATE =
          mcb_pmsm_hall_offset_f28379d_B.FixPtSwitch;
      }

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */
    }
  }

  /* Clear occurred EOC event event */
  AdcbRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdcbRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEIER9.all = PIEIER9_stack_save;
                                   /*restore PIEIER register that was modified*/
  HWI_TIC28x_AcknowledgeIrq(33);
}

/* Hardware Interrupt Block: '<S16>/Hardware Interrupt' */
interrupt void ECAP1_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S16>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Hall Sensor A' */

      /* S-Function (memorycopy): '<S25>/Read GPIO DAT register' */
      {
        uint32_T *memindsrc5 = (uint32_T *) (&GpioDataRegs.GPBDAT.all);
        uint32_T *meminddst5 = (uint32_T *)
          (&mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister_l);
        *(uint32_T *) (meminddst5) = *(uint32_T *) (memindsrc5);
      }

      /* S-Function (sfix_bitop): '<S25>/Hall_C' */
      mcb_pmsm_hall_offset_f28379d_B.Hall_C_o =
        mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister_l & 33554432UL;

      /* ArithShift: '<S25>/Shift Arithmetic' incorporates:
       *  S-Function (sfix_bitop): '<S25>/Hall_C'
       */
      mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic_j =
        mcb_pmsm_hall_offset_f28379d_B.Hall_C_o >> 23U;

      /* S-Function (sfix_bitop): '<S25>/Hall_B' */
      mcb_pmsm_hall_offset_f28379d_B.Hall_B_n =
        mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister_l & 8388608UL;

      /* ArithShift: '<S25>/Shift Arithmetic1' incorporates:
       *  S-Function (sfix_bitop): '<S25>/Hall_B'
       */
      mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic1_a =
        mcb_pmsm_hall_offset_f28379d_B.Hall_B_n >> 22U;

      /* S-Function (sfix_bitop): '<S25>/Hall_A' */
      mcb_pmsm_hall_offset_f28379d_B.Hall_A_e =
        mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister_l & 4194304UL;

      /* ArithShift: '<S25>/Shift Arithmetic2' incorporates:
       *  S-Function (sfix_bitop): '<S25>/Hall_A'
       */
      mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic2_h =
        mcb_pmsm_hall_offset_f28379d_B.Hall_A_e >> 22U;

      /* S-Function (sfix_bitop): '<S25>/Bitwise Operator2' */
      mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_kn = (uint32_T)((int16_T)
        mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic_j | (int16_T)
        mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic1_a | (int16_T)
        mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic2_h);

      /* DataTypeConversion: '<S24>/Data Type Conversion1' */
      mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1_h = (uint16_T)
        mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_kn;

      /* DataStoreRead: '<S2>/Data Store Read' */
      mcb_pmsm_hall_offset_f28379d_B.DataStoreRead_b3 =
        mcb_pmsm_hall_offset_f283_DWork.GlobalHallState;

      /* DataTypeConversion: '<S24>/Data Type Conversion2' */
      mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion2_d = (uint16_T)
        mcb_pmsm_hall_offset_f28379d_B.DataStoreRead_b3;

      /* DataStoreRead: '<S2>/Data Store Read1' */
      mcb_pmsm_hall_offset_f28379d_B.DataStoreRead1_d =
        mcb_pmsm_hall_offset_f283_DWork.GlobalDirection;

      /* SwitchCase: '<S24>/Detects if the halls reading is valid' */
      switch ((int32_T)mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1_h) {
       case 5L:
       case 4L:
       case 6L:
       case 2L:
       case 3L:
       case 1L:
        /* Outputs for IfAction SubSystem: '<S28>/Valid Halls' incorporates:
         *  ActionPort: '<S30>/Action Port'
         */
        mcb_pmsm_hall_offset_ValidHalls
          (mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1_h,
           mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion2_d,
           mcb_pmsm_hall_offset_f28379d_B.DataStoreRead1_d,
           &mcb_pmsm_hall_offset_f28379d_B.Merge3_k,
           &mcb_pmsm_hall_offset_f28379d_B.Merge1_g,
           &mcb_pmsm_hall_offset_f28379d_B.Merge_k,
           &mcb_pmsm_hall_offset_f28379d_B.ValidHalls);

        /* End of Outputs for SubSystem: '<S28>/Valid Halls' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S28>/Bad hall (glitch or wrong connection)' incorporates:
         *  ActionPort: '<S29>/Action Port'
         */
        Badhallglitchorwrongconnection
          (mcb_pmsm_hall_offset_f28379d_B.DataStoreRead1_d,
           &mcb_pmsm_hall_offset_f28379d_B.Merge_k,
           &mcb_pmsm_hall_offset_f28379d_B.Merge1_g,
           &mcb_pmsm_hall_offset_f28379d_B.Merge3_k);

        /* End of Outputs for SubSystem: '<S28>/Bad hall (glitch or wrong connection)' */
        break;
      }

      /* End of SwitchCase: '<S24>/Detects if the halls reading is valid' */

      /* DataTypeConversion: '<S28>/Data Type Conversion' */
      mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion_h =
        mcb_pmsm_hall_offset_f28379d_B.Merge3_k;

      /* DataStoreWrite: '<S2>/Data Store Write' */
      mcb_pmsm_hall_offset_f283_DWork.GlobalSpeedValidity =
        mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion_h;

      /* DataStoreWrite: '<S2>/Data Store Write1' */
      mcb_pmsm_hall_offset_f283_DWork.GlobalDirection =
        mcb_pmsm_hall_offset_f28379d_B.Merge1_g;

      /* DataStoreWrite: '<S2>/Data Store Write2' incorporates:
       *  Constant: '<S24>/Constant'
       */
      mcb_pmsm_hall_offset_f283_DWork.HallStateChangeFlag = 1U;

      /* S-Function (c280xcap): '<S2>/eCAP' */
      mcb_pmsm_hall_offset_f28379d_B.eCAP_i[0] = ECap1Regs.CAP1;
      mcb_pmsm_hall_offset_f28379d_B.eCAP_i[1] = ECap1Regs.CAP2;

      /* If: '<S23>/If' */
      if (((uint16_T)mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_kn == 5U) ||
          ((uint16_T)mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_kn == 3U))
      {
        /* Outputs for IfAction SubSystem: '<S23>/Output 1' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        mcb_pmsm_hall_offset_f2_Output1(&mcb_pmsm_hall_offset_f28379d_B.Merge_p);

        /* End of Outputs for SubSystem: '<S23>/Output 1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S23>/Output 0' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        mcb_pmsm_hall_offset_f2_Output0(&mcb_pmsm_hall_offset_f28379d_B.Merge_p);

        /* End of Outputs for SubSystem: '<S23>/Output 0' */
      }

      /* End of If: '<S23>/If' */

      /* Switch: '<S2>/Switch' */
      if (mcb_pmsm_hall_offset_f28379d_B.Merge_p) {
        /* Switch: '<S2>/Switch' */
        mcb_pmsm_hall_offset_f28379d_B.Switch_e =
          mcb_pmsm_hall_offset_f28379d_B.eCAP_i[0];
      } else {
        /* Switch: '<S2>/Switch' */
        mcb_pmsm_hall_offset_f28379d_B.Switch_e =
          mcb_pmsm_hall_offset_f28379d_B.eCAP_i[1];
      }

      /* End of Switch: '<S2>/Switch' */

      /* DataStoreWrite: '<S2>/Data Store Write3' */
      mcb_pmsm_hall_offset_f283_DWork.GlobalSpeedCount =
        mcb_pmsm_hall_offset_f28379d_B.Switch_e;

      /* DataStoreWrite: '<S2>/Data Store Write4' */
      mcb_pmsm_hall_offset_f283_DWork.GlobalHallState =
        mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_kn;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S16>/Hardware Interrupt' */
    }
  }

  /* Clear occurred CEVT1 event */
  ECap1Regs.ECCLR.bit.CEVT1= 1;

  /* Clear occurred CEVT2 event */
  ECap1Regs.ECCLR.bit.CEVT2= 1;

  /* Clear occurred CEVT3 event */
  ECap1Regs.ECCLR.bit.CEVT3= 1;

  /* Clear occurred CEVT4 event */
  ECap1Regs.ECCLR.bit.CEVT4= 1;

  /* Clear occurred CTROVF event */
  ECap1Regs.ECCLR.bit.CTROVF= 1;

  /* Clear occurred CTR_PRD event */
  ECap1Regs.ECCLR.bit.CTR_PRD= 1;

  /* Clear occurred CTR_CMP event */
  ECap1Regs.ECCLR.bit.CTR_CMP= 1;
  ECap1Regs.ECCLR.bit.INT= 1;
  HWI_TIC28x_AcknowledgeIrq(56);
}

/* Hardware Interrupt Block: '<S18>/Hardware Interrupt' */
interrupt void ECAP2_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S18>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Hall Sensor B' */

      /* S-Function (memorycopy): '<S43>/Read GPIO DAT register' */
      {
        uint32_T *memindsrc6 = (uint32_T *) (&GpioDataRegs.GPBDAT.all);
        uint32_T *meminddst6 = (uint32_T *)
          (&mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister_b);
        *(uint32_T *) (meminddst6) = *(uint32_T *) (memindsrc6);
      }

      /* S-Function (sfix_bitop): '<S43>/Hall_C' */
      mcb_pmsm_hall_offset_f28379d_B.Hall_C_e =
        mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister_b & 33554432UL;

      /* ArithShift: '<S43>/Shift Arithmetic' incorporates:
       *  S-Function (sfix_bitop): '<S43>/Hall_C'
       */
      mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic_o =
        mcb_pmsm_hall_offset_f28379d_B.Hall_C_e >> 23U;

      /* S-Function (sfix_bitop): '<S43>/Hall_B' */
      mcb_pmsm_hall_offset_f28379d_B.Hall_B_g =
        mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister_b & 8388608UL;

      /* ArithShift: '<S43>/Shift Arithmetic1' incorporates:
       *  S-Function (sfix_bitop): '<S43>/Hall_B'
       */
      mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic1_l =
        mcb_pmsm_hall_offset_f28379d_B.Hall_B_g >> 22U;

      /* S-Function (sfix_bitop): '<S43>/Hall_A' */
      mcb_pmsm_hall_offset_f28379d_B.Hall_A_f =
        mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister_b & 4194304UL;

      /* ArithShift: '<S43>/Shift Arithmetic2' incorporates:
       *  S-Function (sfix_bitop): '<S43>/Hall_A'
       */
      mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic2_c =
        mcb_pmsm_hall_offset_f28379d_B.Hall_A_f >> 22U;

      /* S-Function (sfix_bitop): '<S43>/Bitwise Operator2' */
      mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_k = (uint32_T)((int16_T)
        mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic_o | (int16_T)
        mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic1_l | (int16_T)
        mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic2_c);

      /* DataTypeConversion: '<S42>/Data Type Conversion1' */
      mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1_k = (uint16_T)
        mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_k;

      /* DataStoreRead: '<S3>/Data Store Read' */
      mcb_pmsm_hall_offset_f28379d_B.DataStoreRead_b =
        mcb_pmsm_hall_offset_f283_DWork.GlobalHallState;

      /* DataTypeConversion: '<S42>/Data Type Conversion2' */
      mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion2_j = (uint16_T)
        mcb_pmsm_hall_offset_f28379d_B.DataStoreRead_b;

      /* DataStoreRead: '<S3>/Data Store Read1' */
      mcb_pmsm_hall_offset_f28379d_B.DataStoreRead1_m =
        mcb_pmsm_hall_offset_f283_DWork.GlobalDirection;

      /* SwitchCase: '<S42>/Detects if the halls reading is valid' */
      switch ((int32_T)mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1_k) {
       case 5L:
       case 4L:
       case 6L:
       case 2L:
       case 3L:
       case 1L:
        /* Outputs for IfAction SubSystem: '<S46>/Valid Halls' incorporates:
         *  ActionPort: '<S48>/Action Port'
         */
        mcb_pmsm_hall_offset_ValidHalls
          (mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1_k,
           mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion2_j,
           mcb_pmsm_hall_offset_f28379d_B.DataStoreRead1_m,
           &mcb_pmsm_hall_offset_f28379d_B.Merge3_n,
           &mcb_pmsm_hall_offset_f28379d_B.Merge1_d2,
           &mcb_pmsm_hall_offset_f28379d_B.Merge_jr,
           &mcb_pmsm_hall_offset_f28379d_B.ValidHalls_k);

        /* End of Outputs for SubSystem: '<S46>/Valid Halls' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S46>/Bad hall (glitch or wrong connection)' incorporates:
         *  ActionPort: '<S47>/Action Port'
         */
        Badhallglitchorwrongconnection
          (mcb_pmsm_hall_offset_f28379d_B.DataStoreRead1_m,
           &mcb_pmsm_hall_offset_f28379d_B.Merge_jr,
           &mcb_pmsm_hall_offset_f28379d_B.Merge1_d2,
           &mcb_pmsm_hall_offset_f28379d_B.Merge3_n);

        /* End of Outputs for SubSystem: '<S46>/Bad hall (glitch or wrong connection)' */
        break;
      }

      /* End of SwitchCase: '<S42>/Detects if the halls reading is valid' */

      /* DataTypeConversion: '<S46>/Data Type Conversion' */
      mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion_d =
        mcb_pmsm_hall_offset_f28379d_B.Merge3_n;

      /* DataStoreWrite: '<S3>/Data Store Write' */
      mcb_pmsm_hall_offset_f283_DWork.GlobalSpeedValidity =
        mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion_d;

      /* DataStoreWrite: '<S3>/Data Store Write1' */
      mcb_pmsm_hall_offset_f283_DWork.GlobalDirection =
        mcb_pmsm_hall_offset_f28379d_B.Merge1_d2;

      /* DataStoreWrite: '<S3>/Data Store Write2' incorporates:
       *  Constant: '<S42>/Constant'
       */
      mcb_pmsm_hall_offset_f283_DWork.HallStateChangeFlag = 1U;

      /* S-Function (c280xcap): '<S3>/eCAP' */
      mcb_pmsm_hall_offset_f28379d_B.eCAP_n[0] = ECap2Regs.CAP1;
      mcb_pmsm_hall_offset_f28379d_B.eCAP_n[1] = ECap2Regs.CAP2;

      /* If: '<S41>/If' */
      if (((uint16_T)mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_k == 6U) ||
          ((uint16_T)mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_k == 3U)) {
        /* Outputs for IfAction SubSystem: '<S41>/Output 1' incorporates:
         *  ActionPort: '<S45>/Action Port'
         */
        mcb_pmsm_hall_offset_f2_Output1(&mcb_pmsm_hall_offset_f28379d_B.Merge_n);

        /* End of Outputs for SubSystem: '<S41>/Output 1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S41>/Output 0' incorporates:
         *  ActionPort: '<S44>/Action Port'
         */
        mcb_pmsm_hall_offset_f2_Output0(&mcb_pmsm_hall_offset_f28379d_B.Merge_n);

        /* End of Outputs for SubSystem: '<S41>/Output 0' */
      }

      /* End of If: '<S41>/If' */

      /* Switch: '<S3>/Switch' */
      if (mcb_pmsm_hall_offset_f28379d_B.Merge_n) {
        /* Switch: '<S3>/Switch' */
        mcb_pmsm_hall_offset_f28379d_B.Switch_n =
          mcb_pmsm_hall_offset_f28379d_B.eCAP_n[0];
      } else {
        /* Switch: '<S3>/Switch' */
        mcb_pmsm_hall_offset_f28379d_B.Switch_n =
          mcb_pmsm_hall_offset_f28379d_B.eCAP_n[1];
      }

      /* End of Switch: '<S3>/Switch' */

      /* DataStoreWrite: '<S3>/Data Store Write3' */
      mcb_pmsm_hall_offset_f283_DWork.GlobalSpeedCount =
        mcb_pmsm_hall_offset_f28379d_B.Switch_n;

      /* DataStoreWrite: '<S3>/Data Store Write4' */
      mcb_pmsm_hall_offset_f283_DWork.GlobalHallState =
        mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2_k;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S18>/Hardware Interrupt' */
    }
  }

  /* Clear occurred CEVT1 event */
  ECap2Regs.ECCLR.bit.CEVT1= 1;

  /* Clear occurred CEVT2 event */
  ECap2Regs.ECCLR.bit.CEVT2= 1;

  /* Clear occurred CEVT3 event */
  ECap2Regs.ECCLR.bit.CEVT3= 1;

  /* Clear occurred CEVT4 event */
  ECap2Regs.ECCLR.bit.CEVT4= 1;

  /* Clear occurred CTROVF event */
  ECap2Regs.ECCLR.bit.CTROVF= 1;

  /* Clear occurred CTR_PRD event */
  ECap2Regs.ECCLR.bit.CTR_PRD= 1;

  /* Clear occurred CTR_CMP event */
  ECap2Regs.ECCLR.bit.CTR_CMP= 1;
  ECap2Regs.ECCLR.bit.INT= 1;
  HWI_TIC28x_AcknowledgeIrq(57);
}

/* Hardware Interrupt Block: '<S20>/Hardware Interrupt' */
interrupt void ECAP3_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S20>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Hall Sensor C' */

      /* S-Function (memorycopy): '<S61>/Read GPIO DAT register' */
      {
        uint32_T *memindsrc7 = (uint32_T *) (&GpioDataRegs.GPBDAT.all);
        uint32_T *meminddst7 = (uint32_T *)
          (&mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister);
        *(uint32_T *) (meminddst7) = *(uint32_T *) (memindsrc7);
      }

      /* S-Function (sfix_bitop): '<S61>/Hall_C' */
      mcb_pmsm_hall_offset_f28379d_B.Hall_C =
        mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister & 33554432UL;

      /* ArithShift: '<S61>/Shift Arithmetic' incorporates:
       *  S-Function (sfix_bitop): '<S61>/Hall_C'
       */
      mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic =
        mcb_pmsm_hall_offset_f28379d_B.Hall_C >> 23U;

      /* S-Function (sfix_bitop): '<S61>/Hall_B' */
      mcb_pmsm_hall_offset_f28379d_B.Hall_B =
        mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister & 8388608UL;

      /* ArithShift: '<S61>/Shift Arithmetic1' incorporates:
       *  S-Function (sfix_bitop): '<S61>/Hall_B'
       */
      mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic1 =
        mcb_pmsm_hall_offset_f28379d_B.Hall_B >> 22U;

      /* S-Function (sfix_bitop): '<S61>/Hall_A' */
      mcb_pmsm_hall_offset_f28379d_B.Hall_A =
        mcb_pmsm_hall_offset_f28379d_B.ReadGPIODATregister & 4194304UL;

      /* ArithShift: '<S61>/Shift Arithmetic2' incorporates:
       *  S-Function (sfix_bitop): '<S61>/Hall_A'
       */
      mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic2 =
        mcb_pmsm_hall_offset_f28379d_B.Hall_A >> 22U;

      /* S-Function (sfix_bitop): '<S61>/Bitwise Operator2' */
      mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2 = (uint32_T)((int16_T)
        mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic | (int16_T)
        mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic1 | (int16_T)
        mcb_pmsm_hall_offset_f28379d_B.ShiftArithmetic2);

      /* DataTypeConversion: '<S60>/Data Type Conversion1' */
      mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1_b = (uint16_T)
        mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2;

      /* DataStoreRead: '<S4>/Data Store Read' */
      mcb_pmsm_hall_offset_f28379d_B.DataStoreRead =
        mcb_pmsm_hall_offset_f283_DWork.GlobalHallState;

      /* DataTypeConversion: '<S60>/Data Type Conversion2' */
      mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion2 = (uint16_T)
        mcb_pmsm_hall_offset_f28379d_B.DataStoreRead;

      /* DataStoreRead: '<S4>/Data Store Read1' */
      mcb_pmsm_hall_offset_f28379d_B.DataStoreRead1 =
        mcb_pmsm_hall_offset_f283_DWork.GlobalDirection;

      /* SwitchCase: '<S60>/Detects if the halls reading is valid' */
      switch ((int32_T)mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1_b) {
       case 5L:
       case 4L:
       case 6L:
       case 2L:
       case 3L:
       case 1L:
        /* Outputs for IfAction SubSystem: '<S64>/Valid Halls' incorporates:
         *  ActionPort: '<S66>/Action Port'
         */
        mcb_pmsm_hall_offset_ValidHalls
          (mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion1_b,
           mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion2,
           mcb_pmsm_hall_offset_f28379d_B.DataStoreRead1,
           &mcb_pmsm_hall_offset_f28379d_B.Merge3,
           &mcb_pmsm_hall_offset_f28379d_B.Merge1_dw,
           &mcb_pmsm_hall_offset_f28379d_B.Merge_b,
           &mcb_pmsm_hall_offset_f28379d_B.ValidHalls_p);

        /* End of Outputs for SubSystem: '<S64>/Valid Halls' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S64>/Bad hall (glitch or wrong connection)' incorporates:
         *  ActionPort: '<S65>/Action Port'
         */
        Badhallglitchorwrongconnection
          (mcb_pmsm_hall_offset_f28379d_B.DataStoreRead1,
           &mcb_pmsm_hall_offset_f28379d_B.Merge_b,
           &mcb_pmsm_hall_offset_f28379d_B.Merge1_dw,
           &mcb_pmsm_hall_offset_f28379d_B.Merge3);

        /* End of Outputs for SubSystem: '<S64>/Bad hall (glitch or wrong connection)' */
        break;
      }

      /* End of SwitchCase: '<S60>/Detects if the halls reading is valid' */

      /* DataTypeConversion: '<S64>/Data Type Conversion' */
      mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion =
        mcb_pmsm_hall_offset_f28379d_B.Merge3;

      /* DataStoreWrite: '<S4>/Data Store Write' */
      mcb_pmsm_hall_offset_f283_DWork.GlobalSpeedValidity =
        mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion;

      /* DataStoreWrite: '<S4>/Data Store Write1' */
      mcb_pmsm_hall_offset_f283_DWork.GlobalDirection =
        mcb_pmsm_hall_offset_f28379d_B.Merge1_dw;

      /* DataStoreWrite: '<S4>/Data Store Write2' incorporates:
       *  Constant: '<S60>/Constant'
       */
      mcb_pmsm_hall_offset_f283_DWork.HallStateChangeFlag = 1U;

      /* S-Function (c280xcap): '<S4>/eCAP' */
      mcb_pmsm_hall_offset_f28379d_B.eCAP[0] = ECap3Regs.CAP1;
      mcb_pmsm_hall_offset_f28379d_B.eCAP[1] = ECap3Regs.CAP2;

      /* If: '<S59>/If' */
      if (((uint16_T)mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2 == 6U) ||
          ((uint16_T)mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2 == 5U)) {
        /* Outputs for IfAction SubSystem: '<S59>/Output 1' incorporates:
         *  ActionPort: '<S63>/Action Port'
         */
        mcb_pmsm_hall_offset_f2_Output1(&mcb_pmsm_hall_offset_f28379d_B.Merge_f2);

        /* End of Outputs for SubSystem: '<S59>/Output 1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S59>/Output 0' incorporates:
         *  ActionPort: '<S62>/Action Port'
         */
        mcb_pmsm_hall_offset_f2_Output0(&mcb_pmsm_hall_offset_f28379d_B.Merge_f2);

        /* End of Outputs for SubSystem: '<S59>/Output 0' */
      }

      /* End of If: '<S59>/If' */

      /* Switch: '<S4>/Switch' */
      if (mcb_pmsm_hall_offset_f28379d_B.Merge_f2) {
        /* Switch: '<S4>/Switch' */
        mcb_pmsm_hall_offset_f28379d_B.Switch =
          mcb_pmsm_hall_offset_f28379d_B.eCAP[0];
      } else {
        /* Switch: '<S4>/Switch' */
        mcb_pmsm_hall_offset_f28379d_B.Switch =
          mcb_pmsm_hall_offset_f28379d_B.eCAP[1];
      }

      /* End of Switch: '<S4>/Switch' */

      /* DataStoreWrite: '<S4>/Data Store Write3' */
      mcb_pmsm_hall_offset_f283_DWork.GlobalSpeedCount =
        mcb_pmsm_hall_offset_f28379d_B.Switch;

      /* DataStoreWrite: '<S4>/Data Store Write4' */
      mcb_pmsm_hall_offset_f283_DWork.GlobalHallState =
        mcb_pmsm_hall_offset_f28379d_B.BitwiseOperator2;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S20>/Hardware Interrupt' */
    }
  }

  /* Clear occurred CEVT1 event */
  ECap3Regs.ECCLR.bit.CEVT1= 1;

  /* Clear occurred CEVT2 event */
  ECap3Regs.ECCLR.bit.CEVT2= 1;

  /* Clear occurred CEVT3 event */
  ECap3Regs.ECCLR.bit.CEVT3= 1;

  /* Clear occurred CEVT4 event */
  ECap3Regs.ECCLR.bit.CEVT4= 1;

  /* Clear occurred CTROVF event */
  ECap3Regs.ECCLR.bit.CTROVF= 1;

  /* Clear occurred CTR_PRD event */
  ECap3Regs.ECCLR.bit.CTR_PRD= 1;

  /* Clear occurred CTR_CMP event */
  ECap3Regs.ECCLR.bit.CTR_CMP= 1;
  ECap3Regs.ECCLR.bit.INT= 1;
  HWI_TIC28x_AcknowledgeIrq(58);
}

/* Hardware Interrupt Block: '<S22>/Hardware Interrupt' */
interrupt void SCIA_RX_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Serial Receive' */

      /* S-Function (c28xsci_rx): '<S171>/SCI Receive' */
      {
        int16_T i;
        int16_T errFlg = NOERROR;
        uint16_T isHeadReceived = 1U;

        //get data as uint16 in recBuff
        uint16_T recbuff[2];
        for (i = 0; i < 2; i++) {
          recbuff[i] = 0U;
        }

        errFlg = NOERROR;

        /* Receiving data: For uint32 and uint16, rcvBuff will contain uint16 data */
        if (isHeadReceived) {
          errFlg = scia_rcv(recbuff, 4, 4);
          if ((errFlg != NOERROR) && (errFlg != PARTIALDATA)) {
            mcb_pmsm_hall_offset_f28379d_B.SCIReceive = 0.0;
          }

          if ((errFlg == NOERROR) || (errFlg == PARTIALDATA)) {
            memcpy( &mcb_pmsm_hall_offset_f28379d_B.SCIReceive, recbuff,2);
          }
        }
      }

      /* DataTypeConversion: '<S7>/Data Type Conversion' */
      mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion_b =
        (mcb_pmsm_hall_offset_f28379d_B.SCIReceive != 0.0F);

      /* DataStoreWrite: '<S7>/Data Store Write' */
      mcb_pmsm_hall_offset_f283_DWork.Enable =
        mcb_pmsm_hall_offset_f28379d_B.DataTypeConversion_b;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */
    }
  }

  /* Clear occurred Rx FIFO complete event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFINTCLR= 1;
  EDIS;

  /* Clear occurred Rx FIFO overflow event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFOVRCLR= 1;
  EDIS;
  HWI_TIC28x_AcknowledgeIrq(96);
}

void mcb_pmsm_hall_offset_f28379d_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(33);
  HWI_TIC28x_DisableIRQ(56);
  HWI_TIC28x_DisableIRQ(57);
  HWI_TIC28x_DisableIRQ(58);
  HWI_TIC28x_DisableIRQ(96);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
