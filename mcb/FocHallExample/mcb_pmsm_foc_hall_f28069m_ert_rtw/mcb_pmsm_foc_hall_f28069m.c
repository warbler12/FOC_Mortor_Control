/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_hall_f28069m.c
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_hall_f28069m'.
 *
 * Model version                  : 7.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Sep 29 18:18:53 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_pmsm_foc_hall_f28069m.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_hall_f28069m_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_mcb_pmsm_foc_hall_f2806 mcb_pmsm_foc_hall_f28069m_B;

/* Block states (default storage) */
D_Work_mcb_pmsm_foc_hall_f28069 mcb_pmsm_foc_hall_f28069m_DWork;

/* Real-time model */
static RT_MODEL_mcb_pmsm_foc_hall_f280 mcb_pmsm_foc_hall_f28069m_M_;
RT_MODEL_mcb_pmsm_foc_hall_f280 *const mcb_pmsm_foc_hall_f28069m_M =
  &mcb_pmsm_foc_hall_f28069m_M_;
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcAInitFlag = 0;

#endif

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void mcb_pmsm_foc_hall_f28069m_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_hall_f28069m_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (mcb_pmsm_foc_hall_f28069m_M->Timing.TaskCounters.TID[1])++;
  if ((mcb_pmsm_foc_hall_f28069m_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [0.5s, 0.0s] */
    mcb_pmsm_foc_hall_f28069m_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S200>/Hall Value of 1'
 *    '<S200>/Hall Value of 2'
 *    '<S200>/Hall Value of 3'
 *    '<S200>/Hall Value of 4'
 *    '<S200>/Hall Value of 5'
 *    '<S200>/Hall Value of 6'
 *    '<S200>/Hall Value of 7'
 *    '<S199>/Hall Value of 1'
 *    '<S199>/Hall Value of 2'
 *    '<S199>/Hall Value of 3'
 *    ...
 */
void mcb_pmsm_foc_h_HallValueof1(real32_T *rty_position,
  rtP_HallValueof1_mcb_pmsm_foc_h *localP)
{
  /* SignalConversion generated from: '<S210>/position' incorporates:
   *  Constant: '<S210>/Constant'
   */
  *rty_position = localP->Constant_Value;
}

/* System initialize for function-call system: '<Root>/Current Control' */
void mcb_pms_CurrentControl_Init(void)
{
  /* Start for Delay: '<S182>/validityDelay' */
  mcb_pmsm_foc_hall_f28069m_B.validityDelay = false;

  /* Start for Delay: '<S182>/speedCountDelay' */
  mcb_pmsm_foc_hall_f28069m_B.speedCountDelay = 0UL;

  /* Start for Delay: '<S183>/Delay One Step' */
  mcb_pmsm_foc_hall_f28069m_B.DelayOneStep = 0U;

  /* Start for S-Function (c2802xadc): '<S228>/ADC' */
  if (MW_adcAInitFlag == 0U) {
    InitAdcA();
    MW_adcAInitFlag = 1U;
  }

  config_ADCA_SOC2 ();

  /* Start for Constant: '<S28>/Kp1' */
  mcb_pmsm_foc_hall_f28069m_B.Kp1_c = mcb_pmsm_foc_hall_f28069m_P.Kp1_Value;

  /* Start for Constant: '<S27>/Ki1' */
  mcb_pmsm_foc_hall_f28069m_B.Ki1 = mcb_pmsm_foc_hall_f28069m_P.Ki1_Value;

  /* Start for S-Function (c280xgpio_do): '<S225>/Digital Output2' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFF333U;
  GpioCtrlRegs.GPADIR.all |= 0x2AU;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S225>/ePWM1' */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 1U;          // Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x12U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 2250U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm1Regs.CMPA.bit.CMPA = 1126U;   // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 1126U;   // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 264U;
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
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 0U;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x803FU) | 0x0U;
    EPwm1Regs.DBRED = 0U;// Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED = 0U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM1SOCA Period Select
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM1INTn Select
       EPwm1Regs.ETPS.bit.INTPRD                = 1U;          // EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0FU) | 0x1A01U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303U) | 0x1101U;

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
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 0U;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x0U;

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
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S225>/ePWM2' */

  /*** Initialize ePWM2 modules ***/
  {
    /*  // Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 0U;          // Sync Output Select

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 1U;          // Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 1U;          // Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 2250U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm2Regs.CMPA.bit.CMPA = 1126U;   // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 1126U;   // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 264U;
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
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 0U;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x803FU) | 0x0U;
    EPwm2Regs.DBRED = 0U;// Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED = 0U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASEL              = 0U;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM2SOCA Period Select
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
       EPwm2Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM2INTn Select
       EPwm2Regs.ETPS.bit.INTPRD                = 1U;          // EPWM2INTn Period Select
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0FU) | 0x1001U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303U) | 0x1101U;

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
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S225>/ePWM3' */

  /*** Initialize ePWM3 modules ***/
  {
    /*  // Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select

       EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm3Regs.TBCTL.bit.PHSEN                = 1U;          // Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 1U;          // Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x2036U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 2250U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm3Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm3Regs.CMPA.bit.CMPA = 1126U;   // Counter Compare A Register
    EPwm3Regs.CMPB.bit.CMPB = 1126U;   // Counter Compare B Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 264U;
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
       EPwm3Regs.DBCTL.bit.OUT_MODE             = 0U;          // Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x803FU) | 0x0U;
    EPwm3Regs.DBRED = 0U;// Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED = 0U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASEL              = 0U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM3SOCA Period Select
       EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
       EPwm3Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM3SOCB Period Select
       EPwm3Regs.ETSEL.bit.INTEN                = 0U;          // EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM3INTn Select
       EPwm3Regs.ETPS.bit.INTPRD                = 1U;          // EPWM3INTn Period Select
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF0FU) | 0x1001U;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x3303U) | 0x1101U;

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
    EDIS;
  }

  /* InitializeConditions for Delay: '<S182>/validityDelay' */
  mcb_pmsm_foc_hall_f28069m_DWork.validityDelay_DSTATE =
    mcb_pmsm_foc_hall_f28069m_P.validityDelay_InitialCondition;

  /* InitializeConditions for Delay: '<S182>/speedCountDelay' */
  mcb_pmsm_foc_hall_f28069m_DWork.speedCountDelay_DSTATE =
    mcb_pmsm_foc_hall_f28069m_P.speedCountDelay_InitialConditio;

  /* InitializeConditions for Delay: '<S183>/Delay One Step1' */
  mcb_pmsm_foc_hall_f28069m_DWork.DelayOneStep1_DSTATE =
    mcb_pmsm_foc_hall_f28069m_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Delay: '<S183>/Delay One Step' */
  mcb_pmsm_foc_hall_f28069m_DWork.DelayOneStep_DSTATE =
    mcb_pmsm_foc_hall_f28069m_P.SoftwareWatchdogTimer_maxCount;

  /* InitializeConditions for UnitDelay: '<S161>/Output' */
  mcb_pmsm_foc_hall_f28069m_DWork.Output_DSTATE =
    mcb_pmsm_foc_hall_f28069m_P.Output_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S128>/Integrator' */
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE_k =
    mcb_pmsm_foc_hall_f28069m_B.Kp1_c;
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_PrevResetState_o = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S77>/Integrator' */
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE_g =
    mcb_pmsm_foc_hall_f28069m_B.Ki1;
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_PrevResetState_j = 0;

  /* SystemInitialize for Atomic SubSystem: '<S169>/Atomic Hall Reading' */

  /* InitializeConditions for UnitDelay: '<S178>/Unit Delay' */
  mcb_pmsm_foc_hall_f28069m_DWork.UnitDelay_DSTATE_i =
    mcb_pmsm_foc_hall_f28069m_P.UnitDelay_InitialCondition_g;

  /* SystemInitialize for DataTypeConversion: '<S176>/Data Type Conversion' incorporates:
   *  Outport: '<S176>/HallSignal'
   */
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion =
    mcb_pmsm_foc_hall_f28069m_P.HallSignal_Y0;

  /* SystemInitialize for MinMax: '<S177>/Min' incorporates:
   *  Outport: '<S177>/u'
   */
  mcb_pmsm_foc_hall_f28069m_B.Min = mcb_pmsm_foc_hall_f28069m_P.u_Y0;

  /* End of SystemInitialize for S-Function (fcgen): '<S171>/Function-Call Generator' */

  /* End of SystemInitialize for SubSystem: '<S169>/Atomic Hall Reading' */

  /* SystemInitialize for Enabled SubSystem: '<S169>/Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S175>/Input' incorporates:
   *  Outport: '<S175>/Output'
   */
  mcb_pmsm_foc_hall_f28069m_B.Input = mcb_pmsm_foc_hall_f28069m_P.Output_Y0;

  /* End of SystemInitialize for SubSystem: '<S169>/Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S173>/Speed and direction are valid Use speed to extrapolate position' */
  /* SystemInitialize for Enabled SubSystem: '<S185>/Subsystem1' */
  /* SystemInitialize for Merge: '<S198>/Merge' */
  mcb_pmsm_foc_hall_f28069m_B.Merge_b =
    mcb_pmsm_foc_hall_f28069m_P.Merge_InitialOutput;

  /* End of SystemInitialize for SubSystem: '<S185>/Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<S173>/Speed and direction are valid Use speed to extrapolate position' */
  /* SystemInitialize for SignalConversion generated from: '<S1>/Speed_fb' incorporates:
   *  Outport: '<S1>/Speed_fb'
   */
  mcb_pmsm_foc_hall_f28069m_B.Speed_PU = mcb_pmsm_foc_hall_f28069m_P.Speed_fb_Y0;
}

/* System reset for function-call system: '<Root>/Current Control' */
void mcb_pm_CurrentControl_Reset(void)
{
  /* InitializeConditions for Delay: '<S182>/validityDelay' */
  mcb_pmsm_foc_hall_f28069m_DWork.validityDelay_DSTATE =
    mcb_pmsm_foc_hall_f28069m_P.validityDelay_InitialCondition;

  /* InitializeConditions for Delay: '<S182>/speedCountDelay' */
  mcb_pmsm_foc_hall_f28069m_DWork.speedCountDelay_DSTATE =
    mcb_pmsm_foc_hall_f28069m_P.speedCountDelay_InitialConditio;

  /* InitializeConditions for Delay: '<S183>/Delay One Step1' */
  mcb_pmsm_foc_hall_f28069m_DWork.DelayOneStep1_DSTATE =
    mcb_pmsm_foc_hall_f28069m_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Delay: '<S183>/Delay One Step' */
  mcb_pmsm_foc_hall_f28069m_DWork.DelayOneStep_DSTATE =
    mcb_pmsm_foc_hall_f28069m_P.SoftwareWatchdogTimer_maxCount;

  /* InitializeConditions for UnitDelay: '<S161>/Output' */
  mcb_pmsm_foc_hall_f28069m_DWork.Output_DSTATE =
    mcb_pmsm_foc_hall_f28069m_P.Output_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S128>/Integrator' */
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE_k =
    mcb_pmsm_foc_hall_f28069m_B.Kp1_c;
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_PrevResetState_o = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S77>/Integrator' */
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE_g =
    mcb_pmsm_foc_hall_f28069m_B.Ki1;
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_PrevResetState_j = 0;

  /* SystemReset for Atomic SubSystem: '<S169>/Atomic Hall Reading' */

  /* InitializeConditions for UnitDelay: '<S178>/Unit Delay' */
  mcb_pmsm_foc_hall_f28069m_DWork.UnitDelay_DSTATE_i =
    mcb_pmsm_foc_hall_f28069m_P.UnitDelay_InitialCondition_g;

  /* End of SystemReset for SubSystem: '<S169>/Atomic Hall Reading' */
}

/* Output and update for function-call system: '<Root>/Current Control' */
#pragma CODE_SECTION (mcb_pmsm_foc_CurrentControl, "ramfuncs")

void mcb_pmsm_foc_CurrentControl(void)
{
  int32_T Q17perunitconversion;
  real32_T Bias;
  real32_T u0_0;
  real32_T u1_0;
  uint32_T u0;
  uint32_T u1;
  int16_T s227_iter;
  uint16_T Data;
  boolean_T doReset;

  /* Outputs for Atomic SubSystem: '<S169>/Atomic Hall Reading' */

  /* user code (Output function Body for TID2) */

  /* System '<S169>/Atomic Hall Reading' */
  DINT;

  /* DataStoreRead: '<S171>/Data Store Read5' */
  mcb_pmsm_foc_hall_f28069m_B.DataStoreRead5 =
    mcb_pmsm_foc_hall_f28069m_DWork.HallStateChangeFlag;

  /* S-Function (fcgen): '<S171>/Function-Call Generator' incorporates:
   *  SubSystem: '<S171>/Function-Call Subsystem'
   */
  /* S-Function (memorycopy_svd): '<S176>/Memory Copy3' */
  {
    uint32_T *memindsrc1 = (uint32_T *) (&GpioDataRegs.GPADAT.all);
    uint32_T *meminddst1 = (uint32_T *)
      (&mcb_pmsm_foc_hall_f28069m_B.MemoryCopy3_o);
    *(uint32_T *) (meminddst1) = *(uint32_T *) (memindsrc1);
  }

  /* S-Function (sfix_bitop): '<S176>/Bitwise AND' */
  mcb_pmsm_foc_hall_f28069m_B.BitwiseAND_aq =
    mcb_pmsm_foc_hall_f28069m_B.MemoryCopy3_o &
    mcb_pmsm_foc_hall_f28069m_P.BitwiseAND_BitMask;

  /* ArithShift: '<S176>/Shift Arithmetic' incorporates:
   *  S-Function (sfix_bitop): '<S176>/Bitwise AND'
   */
  mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_e =
    mcb_pmsm_foc_hall_f28069m_B.BitwiseAND_aq >> 24U;

  /* DataTypeConversion: '<S176>/Data Type Conversion' */
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion =
    mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_e;

  /* S-Function (fcgen): '<S171>/Function-Call Generator' incorporates:
   *  SubSystem: '<S171>/Function-Call Subsystem1'
   */
  /* S-Function (memorycopy): '<S177>/Memory Copy' */
  {
    uint32_T *memindsrc2 = (uint32_T *) (&ECap1Regs.TSCTR);
    uint32_T *meminddst2 = (uint32_T *)
      (&mcb_pmsm_foc_hall_f28069m_B.MemoryCopy_l);
    *(uint32_T *) (meminddst2) = *(uint32_T *) (memindsrc2);
  }

  /* S-Function (memorycopy): '<S177>/Memory Copy1' */
  {
    uint32_T *memindsrc3 = (uint32_T *) (&ECap2Regs.TSCTR);
    uint32_T *meminddst3 = (uint32_T *)
      (&mcb_pmsm_foc_hall_f28069m_B.MemoryCopy1);
    *(uint32_T *) (meminddst3) = *(uint32_T *) (memindsrc3);
  }

  /* S-Function (memorycopy): '<S177>/Memory Copy2' */
  {
    uint32_T *memindsrc4 = (uint32_T *) (&ECap3Regs.TSCTR);
    uint32_T *meminddst4 = (uint32_T *)
      (&mcb_pmsm_foc_hall_f28069m_B.MemoryCopy2);
    *(uint32_T *) (meminddst4) = *(uint32_T *) (memindsrc4);
  }

  /* MinMax: '<S177>/Min' */
  u0 = mcb_pmsm_foc_hall_f28069m_B.MemoryCopy_l;
  u1 = mcb_pmsm_foc_hall_f28069m_B.MemoryCopy1;
  if (u0 <= u1) {
    u1 = u0;
  }

  u0 = mcb_pmsm_foc_hall_f28069m_B.MemoryCopy2;
  if (u1 > u0) {
    u1 = u0;
  }

  /* MinMax: '<S177>/Min' */
  mcb_pmsm_foc_hall_f28069m_B.Min = u1;

  /* End of Outputs for S-Function (fcgen): '<S171>/Function-Call Generator' */

  /* RelationalOperator: '<S179>/Compare' incorporates:
   *  Constant: '<S179>/Constant'
   */
  mcb_pmsm_foc_hall_f28069m_B.Compare = (uint16_T)
    (mcb_pmsm_foc_hall_f28069m_B.Min <
     mcb_pmsm_foc_hall_f28069m_P.CompareToConstant_const);

  /* UnitDelay: '<S178>/Unit Delay' */
  mcb_pmsm_foc_hall_f28069m_B.UnitDelay =
    mcb_pmsm_foc_hall_f28069m_DWork.UnitDelay_DSTATE_i;

  /* RelationalOperator: '<S178>/Relational Operator' */
  mcb_pmsm_foc_hall_f28069m_B.RelationalOperator_o =
    (mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion ==
     mcb_pmsm_foc_hall_f28069m_B.UnitDelay);

  /* Logic: '<S178>/NOT' incorporates:
   *  RelationalOperator: '<S179>/Compare'
   */
  mcb_pmsm_foc_hall_f28069m_B.NOT_m =
    (mcb_pmsm_foc_hall_f28069m_B.RelationalOperator_o &&
     (mcb_pmsm_foc_hall_f28069m_B.Compare != 0U));

  /* If: '<S178>/If' */
  if (!mcb_pmsm_foc_hall_f28069m_B.NOT_m) {
    /* Outputs for IfAction SubSystem: '<S178>/No_Integrity_issue' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    /* Merge: '<S178>/Merge' incorporates:
     *  SignalConversion generated from: '<S180>/Counter'
     */
    mcb_pmsm_foc_hall_f28069m_B.Merge =
      mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion;

    /* End of Outputs for SubSystem: '<S178>/No_Integrity_issue' */
  } else {
    /* Outputs for IfAction SubSystem: '<S178>/Refresh_Halls' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    /* S-Function (memorycopy_svd): '<S181>/Memory Copy3' */
    {
      uint32_T *memindsrc5 = (uint32_T *) (&GpioDataRegs.GPADAT.all);
      uint32_T *meminddst5 = (uint32_T *)
        (&mcb_pmsm_foc_hall_f28069m_B.MemoryCopy3);
      *(uint32_T *) (meminddst5) = *(uint32_T *) (memindsrc5);
    }

    /* S-Function (sfix_bitop): '<S181>/Bitwise AND' */
    mcb_pmsm_foc_hall_f28069m_B.BitwiseAND_e =
      mcb_pmsm_foc_hall_f28069m_B.MemoryCopy3 &
      mcb_pmsm_foc_hall_f28069m_P.BitwiseAND_BitMask_p;

    /* ArithShift: '<S181>/Shift Arithmetic' incorporates:
     *  S-Function (sfix_bitop): '<S181>/Bitwise AND'
     */
    mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_i =
      mcb_pmsm_foc_hall_f28069m_B.BitwiseAND_e >> 24U;

    /* Merge: '<S178>/Merge' incorporates:
     *  DataTypeConversion: '<S181>/Data Type Conversion'
     */
    mcb_pmsm_foc_hall_f28069m_B.Merge =
      mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_i;

    /* End of Outputs for SubSystem: '<S178>/Refresh_Halls' */
  }

  /* End of If: '<S178>/If' */

  /* DataStoreRead: '<S171>/Data Store Read2' */
  mcb_pmsm_foc_hall_f28069m_B.DataStoreRead2 =
    mcb_pmsm_foc_hall_f28069m_DWork.GlobalSpeedCount;

  /* DataStoreRead: '<S171>/Data Store Read3' */
  mcb_pmsm_foc_hall_f28069m_B.DataStoreRead3 =
    mcb_pmsm_foc_hall_f28069m_DWork.GlobalDirection;

  /* DataStoreRead: '<S171>/Data Store Read4' */
  mcb_pmsm_foc_hall_f28069m_B.DataStoreRead4 =
    mcb_pmsm_foc_hall_f28069m_DWork.GlobalSpeedValidity;

  /* user code (Output function Trailer for TID2) */

  /* System '<S169>/Atomic Hall Reading' */
  EINT;

  /* Update for UnitDelay: '<S178>/Unit Delay' */
  mcb_pmsm_foc_hall_f28069m_DWork.UnitDelay_DSTATE_i =
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion;

  /* End of Outputs for SubSystem: '<S169>/Atomic Hall Reading' */

  /* Switch: '<S173>/Switch' */
  if (mcb_pmsm_foc_hall_f28069m_B.DataStoreRead5 != 0U) {
    /* Switch: '<S173>/Switch' incorporates:
     *  Constant: '<S173>/WatchDog'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch_ad =
      mcb_pmsm_foc_hall_f28069m_P.WatchDog_Value;
  } else {
    /* Switch: '<S173>/Switch' */
    mcb_pmsm_foc_hall_f28069m_B.Switch_ad = 0U;
  }

  /* End of Switch: '<S173>/Switch' */

  /* DataStoreWrite: '<S169>/Data Store Write2' */
  mcb_pmsm_foc_hall_f28069m_DWork.HallStateChangeFlag =
    mcb_pmsm_foc_hall_f28069m_B.Switch_ad;

  /* RelationalOperator: '<S172>/Compare' incorporates:
   *  Constant: '<S172>/Constant'
   */
  mcb_pmsm_foc_hall_f28069m_B.Compare_f =
    (mcb_pmsm_foc_hall_f28069m_B.DataStoreRead2 >=
     mcb_pmsm_foc_hall_f28069m_P.GlitchFilter_const);

  /* DataTypeConversion: '<S173>/Data Type Conversion4' */
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion4 =
    (mcb_pmsm_foc_hall_f28069m_B.DataStoreRead5 != 0U);

  /* DataTypeConversion: '<S182>/Data Type Conversion' */
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_lx =
    (mcb_pmsm_foc_hall_f28069m_B.DataStoreRead4 != 0U);

  /* Switch: '<S182>/Switch' incorporates:
   *  Constant: '<S182>/Order'
   */
  if (mcb_pmsm_foc_hall_f28069m_P.Order_Value >
      mcb_pmsm_foc_hall_f28069m_P.Switch_Threshold_k) {
    /* Switch: '<S182>/Switch' */
    mcb_pmsm_foc_hall_f28069m_B.Switch_i =
      mcb_pmsm_foc_hall_f28069m_B.DataStoreRead5;
  } else {
    /* Switch: '<S182>/Switch' */
    mcb_pmsm_foc_hall_f28069m_B.Switch_i =
      mcb_pmsm_foc_hall_f28069m_P.Order_Value;
  }

  /* End of Switch: '<S182>/Switch' */

  /* Delay: '<S182>/validityDelay' incorporates:
   *  Delay: '<S182>/speedCountDelay'
   */
  if (mcb_pmsm_foc_hall_f28069m_B.Switch_i != 0U) {
    /* Delay: '<S182>/validityDelay' */
    mcb_pmsm_foc_hall_f28069m_B.validityDelay =
      mcb_pmsm_foc_hall_f28069m_DWork.validityDelay_DSTATE;

    /* Delay: '<S182>/speedCountDelay' */
    mcb_pmsm_foc_hall_f28069m_B.speedCountDelay =
      mcb_pmsm_foc_hall_f28069m_DWork.speedCountDelay_DSTATE;
  }

  /* End of Delay: '<S182>/validityDelay' */

  /* Outputs for Enabled SubSystem: '<S169>/Subsystem' incorporates:
   *  EnablePort: '<S175>/Enable'
   */
  if (mcb_pmsm_foc_hall_f28069m_B.Compare_f) {
    /* SignalConversion generated from: '<S175>/Input' */
    mcb_pmsm_foc_hall_f28069m_B.Input =
      mcb_pmsm_foc_hall_f28069m_B.DataStoreRead2;
  }

  /* End of Outputs for SubSystem: '<S169>/Subsystem' */

  /* Delay: '<S183>/Delay One Step1' */
  mcb_pmsm_foc_hall_f28069m_B.DelayOneStep1 =
    mcb_pmsm_foc_hall_f28069m_DWork.DelayOneStep1_DSTATE;

  /* Logic: '<S183>/OR' */
  mcb_pmsm_foc_hall_f28069m_B.OR = (mcb_pmsm_foc_hall_f28069m_B.DelayOneStep1 ||
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion4);

  /* Delay: '<S183>/Delay One Step' */
  doReset = mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion4;
  if (mcb_pmsm_foc_hall_f28069m_B.OR) {
    if (doReset) {
      mcb_pmsm_foc_hall_f28069m_DWork.DelayOneStep_DSTATE =
        mcb_pmsm_foc_hall_f28069m_P.SoftwareWatchdogTimer_maxCount;
    }

    /* Delay: '<S183>/Delay One Step' */
    mcb_pmsm_foc_hall_f28069m_B.DelayOneStep =
      mcb_pmsm_foc_hall_f28069m_DWork.DelayOneStep_DSTATE;
  }

  /* End of Delay: '<S183>/Delay One Step' */

  /* RelationalOperator: '<S187>/Compare' incorporates:
   *  Constant: '<S187>/Constant'
   */
  mcb_pmsm_foc_hall_f28069m_B.Compare_j =
    (mcb_pmsm_foc_hall_f28069m_B.DelayOneStep >
     mcb_pmsm_foc_hall_f28069m_P.Constant_Value_k);

  /* Switch: '<S186>/watchdog check' */
  if (mcb_pmsm_foc_hall_f28069m_B.Compare_j) {
    /* MinMax: '<S186>/Max' */
    u0 = mcb_pmsm_foc_hall_f28069m_B.Input;
    u1 = mcb_pmsm_foc_hall_f28069m_B.Min;
    if (u0 >= u1) {
      u1 = u0;
    }

    /* MinMax: '<S186>/Max' */
    mcb_pmsm_foc_hall_f28069m_B.Max = u1;

    /* Switch: '<S186>/speed check' */
    if (mcb_pmsm_foc_hall_f28069m_B.Max >=
        mcb_pmsm_foc_hall_f28069m_P.speedcheck_Threshold) {
      /* Switch: '<S186>/speed check' incorporates:
       *  Constant: '<S186>/Constant'
       */
      mcb_pmsm_foc_hall_f28069m_B.speedcheck =
        mcb_pmsm_foc_hall_f28069m_P.Constant_Value_fx;
    } else {
      /* Logic: '<S182>/Logical Operator' */
      mcb_pmsm_foc_hall_f28069m_B.LogicalOperator_a =
        (mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_lx ||
         mcb_pmsm_foc_hall_f28069m_B.validityDelay);

      /* Switch: '<S186>/speed check' */
      mcb_pmsm_foc_hall_f28069m_B.speedcheck =
        mcb_pmsm_foc_hall_f28069m_B.LogicalOperator_a;
    }

    /* End of Switch: '<S186>/speed check' */

    /* Switch: '<S186>/watchdog check' */
    mcb_pmsm_foc_hall_f28069m_B.watchdogcheck =
      mcb_pmsm_foc_hall_f28069m_B.speedcheck;
  } else {
    /* Switch: '<S186>/watchdog check' incorporates:
     *  Constant: '<S186>/Constant'
     */
    mcb_pmsm_foc_hall_f28069m_B.watchdogcheck =
      mcb_pmsm_foc_hall_f28069m_P.Constant_Value_fx;
  }

  /* End of Switch: '<S186>/watchdog check' */

  /* If: '<S173>/If' incorporates:
   *  Constant: '<S185>/PositionEnable'
   */
  if (mcb_pmsm_foc_hall_f28069m_B.watchdogcheck != 0U) {
    /* Outputs for IfAction SubSystem: '<S173>/Speed and direction are valid Use speed to extrapolate position' incorporates:
     *  ActionPort: '<S185>/Action Port'
     */
    /* DataTypeConversion: '<S185>/SpeedConstData' incorporates:
     *  Constant: '<S185>/SpeedConst'
     */
    mcb_pmsm_foc_hall_f28069m_B.SpeedConstData = (real32_T)
      mcb_pmsm_foc_hall_f28069m_P.SpeedConst_Value;

    /* DataTypeConversion: '<S185>/currentSpeedData' */
    mcb_pmsm_foc_hall_f28069m_B.currentSpeedData = (real32_T)
      mcb_pmsm_foc_hall_f28069m_B.Input;

    /* Product: '<S185>/Divide' */
    mcb_pmsm_foc_hall_f28069m_B.Divide =
      mcb_pmsm_foc_hall_f28069m_B.SpeedConstData /
      mcb_pmsm_foc_hall_f28069m_B.currentSpeedData;

    /* Gain: '<S185>/SpeedGain' */
    mcb_pmsm_foc_hall_f28069m_B.SpeedGain =
      mcb_pmsm_foc_hall_f28069m_P.SpeedGain_Gain *
      mcb_pmsm_foc_hall_f28069m_B.Divide;

    /* If: '<S185>/If' */
    if (mcb_pmsm_foc_hall_f28069m_B.DataStoreRead3 > 0) {
      /* Outputs for IfAction SubSystem: '<S185>/If Action Subsystem' incorporates:
       *  ActionPort: '<S196>/Action Port'
       */
      /* Merge: '<S173>/Merge' incorporates:
       *  SignalConversion generated from: '<S196>/In1'
       */
      mcb_pmsm_foc_hall_f28069m_B.Merge_m =
        mcb_pmsm_foc_hall_f28069m_B.SpeedGain;

      /* End of Outputs for SubSystem: '<S185>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S185>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S197>/Action Port'
       */
      /* Merge: '<S173>/Merge' incorporates:
       *  UnaryMinus: '<S197>/Unary Minus'
       */
      mcb_pmsm_foc_hall_f28069m_B.Merge_m =
        -mcb_pmsm_foc_hall_f28069m_B.SpeedGain;

      /* End of Outputs for SubSystem: '<S185>/If Action Subsystem1' */
    }

    /* End of If: '<S185>/If' */

    /* Outputs for Enabled SubSystem: '<S185>/Subsystem1' incorporates:
     *  EnablePort: '<S198>/Enable'
     */
    if (mcb_pmsm_foc_hall_f28069m_P.PositionEnable_Value > 0U) {
      /* If: '<S198>/If1' incorporates:
       *  Constant: '<S198>/Constant'
       */
      if (mcb_pmsm_foc_hall_f28069m_P.Constant_Value > 1.0) {
        /* Outputs for IfAction SubSystem: '<S198>/second_order' incorporates:
         *  ActionPort: '<S202>/Action Port'
         */
        /* DataTypeConversion: '<S202>/countData' */
        mcb_pmsm_foc_hall_f28069m_B.countData_h = (real32_T)
          mcb_pmsm_foc_hall_f28069m_B.Min;

        /* DataTypeConversion: '<S202>/previousSpeedData' */
        mcb_pmsm_foc_hall_f28069m_B.previousSpeedData = (real32_T)
          mcb_pmsm_foc_hall_f28069m_B.speedCountDelay;

        /* Product: '<S202>/Divide' */
        mcb_pmsm_foc_hall_f28069m_B.Divide_k =
          mcb_pmsm_foc_hall_f28069m_B.countData_h /
          mcb_pmsm_foc_hall_f28069m_B.previousSpeedData;

        /* DataTypeConversion: '<S202>/currentSpeedData' */
        mcb_pmsm_foc_hall_f28069m_B.currentSpeedData_a = (real32_T)
          mcb_pmsm_foc_hall_f28069m_B.Input;

        /* Product: '<S202>/Divide1' */
        mcb_pmsm_foc_hall_f28069m_B.Divide1 =
          mcb_pmsm_foc_hall_f28069m_B.countData_h /
          mcb_pmsm_foc_hall_f28069m_B.currentSpeedData_a;

        /* Sum: '<S202>/Sum' */
        mcb_pmsm_foc_hall_f28069m_B.Sum_ar = mcb_pmsm_foc_hall_f28069m_B.Divide1
          - mcb_pmsm_foc_hall_f28069m_B.Divide_k;

        /* Gain: '<S202>/Gain1' */
        mcb_pmsm_foc_hall_f28069m_B.Gain1 =
          mcb_pmsm_foc_hall_f28069m_P.Gain1_Gain *
          mcb_pmsm_foc_hall_f28069m_B.Sum_ar;

        /* Sum: '<S202>/Sum1' incorporates:
         *  Constant: '<S202>/Constant'
         */
        mcb_pmsm_foc_hall_f28069m_B.Sum1_m = mcb_pmsm_foc_hall_f28069m_B.Gain1 +
          mcb_pmsm_foc_hall_f28069m_P.Constant_Value_b;

        /* Product: '<S202>/Product' */
        mcb_pmsm_foc_hall_f28069m_B.Product_b =
          mcb_pmsm_foc_hall_f28069m_B.Divide1 *
          mcb_pmsm_foc_hall_f28069m_B.Sum1_m;

        /* Merge: '<S198>/Merge1' incorporates:
         *  Gain: '<S202>/Gain'
         */
        mcb_pmsm_foc_hall_f28069m_B.Merge1_m =
          mcb_pmsm_foc_hall_f28069m_P.Gain_Gain_p *
          mcb_pmsm_foc_hall_f28069m_B.Product_b;

        /* End of Outputs for SubSystem: '<S198>/second_order' */
      } else {
        /* Outputs for IfAction SubSystem: '<S198>/first_order' incorporates:
         *  ActionPort: '<S201>/Action Port'
         */
        /* DataTypeConversion: '<S201>/countData' */
        mcb_pmsm_foc_hall_f28069m_B.countData = (real32_T)
          mcb_pmsm_foc_hall_f28069m_B.Min;

        /* DataTypeConversion: '<S201>/currentSpeedData' */
        mcb_pmsm_foc_hall_f28069m_B.currentSpeedData_n = (real32_T)
          mcb_pmsm_foc_hall_f28069m_B.Input;

        /* Product: '<S201>/Divide' */
        mcb_pmsm_foc_hall_f28069m_B.Divide_e =
          mcb_pmsm_foc_hall_f28069m_B.countData /
          mcb_pmsm_foc_hall_f28069m_B.currentSpeedData_n;

        /* Merge: '<S198>/Merge1' incorporates:
         *  Gain: '<S201>/Gain'
         */
        mcb_pmsm_foc_hall_f28069m_B.Merge1_m =
          mcb_pmsm_foc_hall_f28069m_P.Gain_Gain_c *
          mcb_pmsm_foc_hall_f28069m_B.Divide_e;

        /* End of Outputs for SubSystem: '<S198>/first_order' */
      }

      /* End of If: '<S198>/If1' */

      /* Saturate: '<S198>/Saturation' */
      u0_0 = mcb_pmsm_foc_hall_f28069m_B.Merge1_m;
      u1_0 = mcb_pmsm_foc_hall_f28069m_P.Saturation_LowerSat;
      Bias = mcb_pmsm_foc_hall_f28069m_P.Saturation_UpperSat;
      if (u0_0 > Bias) {
        /* Saturate: '<S198>/Saturation' */
        mcb_pmsm_foc_hall_f28069m_B.Saturation_f = Bias;
      } else if (u0_0 < u1_0) {
        /* Saturate: '<S198>/Saturation' */
        mcb_pmsm_foc_hall_f28069m_B.Saturation_f = u1_0;
      } else {
        /* Saturate: '<S198>/Saturation' */
        mcb_pmsm_foc_hall_f28069m_B.Saturation_f = u0_0;
      }

      /* End of Saturate: '<S198>/Saturation' */

      /* If: '<S198>/If' */
      if (mcb_pmsm_foc_hall_f28069m_B.DataStoreRead3 != 1) {
        /* Outputs for IfAction SubSystem: '<S198>/-ve Direction' incorporates:
         *  ActionPort: '<S200>/Action Port'
         */
        /* SwitchCase: '<S200>/Switch Case' */
        switch ((int32_T)mcb_pmsm_foc_hall_f28069m_B.Merge) {
         case 5L:
          /* Outputs for IfAction SubSystem: '<S200>/Hall Value of 1' incorporates:
           *  ActionPort: '<S210>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_dn,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof1);

          /* End of Outputs for SubSystem: '<S200>/Hall Value of 1' */
          break;

         case 4L:
          /* Outputs for IfAction SubSystem: '<S200>/Hall Value of 2' incorporates:
           *  ActionPort: '<S211>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_dn,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof2);

          /* End of Outputs for SubSystem: '<S200>/Hall Value of 2' */
          break;

         case 6L:
          /* Outputs for IfAction SubSystem: '<S200>/Hall Value of 3' incorporates:
           *  ActionPort: '<S212>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_dn,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof3);

          /* End of Outputs for SubSystem: '<S200>/Hall Value of 3' */
          break;

         case 2L:
          /* Outputs for IfAction SubSystem: '<S200>/Hall Value of 4' incorporates:
           *  ActionPort: '<S213>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_dn,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof4);

          /* End of Outputs for SubSystem: '<S200>/Hall Value of 4' */
          break;

         case 3L:
          /* Outputs for IfAction SubSystem: '<S200>/Hall Value of 5' incorporates:
           *  ActionPort: '<S214>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_dn,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof5);

          /* End of Outputs for SubSystem: '<S200>/Hall Value of 5' */
          break;

         case 1L:
          /* Outputs for IfAction SubSystem: '<S200>/Hall Value of 6' incorporates:
           *  ActionPort: '<S215>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_dn,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof6);

          /* End of Outputs for SubSystem: '<S200>/Hall Value of 6' */
          break;

         default:
          /* Outputs for IfAction SubSystem: '<S200>/Hall Value of 7' incorporates:
           *  ActionPort: '<S216>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_dn,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof7);

          /* End of Outputs for SubSystem: '<S200>/Hall Value of 7' */
          break;
        }

        /* End of SwitchCase: '<S200>/Switch Case' */

        /* Merge: '<S198>/Merge' incorporates:
         *  Sum: '<S200>/Sum'
         */
        mcb_pmsm_foc_hall_f28069m_B.Merge_b =
          mcb_pmsm_foc_hall_f28069m_B.Merge1_dn -
          mcb_pmsm_foc_hall_f28069m_B.Saturation_f;

        /* End of Outputs for SubSystem: '<S198>/-ve Direction' */
      } else {
        /* Outputs for IfAction SubSystem: '<S198>/+ve Direction' incorporates:
         *  ActionPort: '<S199>/Action Port'
         */
        /* SwitchCase: '<S199>/Switch Case' */
        switch ((int32_T)mcb_pmsm_foc_hall_f28069m_B.Merge) {
         case 5L:
          /* Outputs for IfAction SubSystem: '<S199>/Hall Value of 1' incorporates:
           *  ActionPort: '<S203>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_d,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof1_n);

          /* End of Outputs for SubSystem: '<S199>/Hall Value of 1' */
          break;

         case 4L:
          /* Outputs for IfAction SubSystem: '<S199>/Hall Value of 2' incorporates:
           *  ActionPort: '<S204>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_d,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof2_n);

          /* End of Outputs for SubSystem: '<S199>/Hall Value of 2' */
          break;

         case 6L:
          /* Outputs for IfAction SubSystem: '<S199>/Hall Value of 3' incorporates:
           *  ActionPort: '<S205>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_d,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof3_k);

          /* End of Outputs for SubSystem: '<S199>/Hall Value of 3' */
          break;

         case 2L:
          /* Outputs for IfAction SubSystem: '<S199>/Hall Value of 4' incorporates:
           *  ActionPort: '<S206>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_d,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof4_l);

          /* End of Outputs for SubSystem: '<S199>/Hall Value of 4' */
          break;

         case 3L:
          /* Outputs for IfAction SubSystem: '<S199>/Hall Value of 5' incorporates:
           *  ActionPort: '<S207>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_d,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof5_e);

          /* End of Outputs for SubSystem: '<S199>/Hall Value of 5' */
          break;

         case 1L:
          /* Outputs for IfAction SubSystem: '<S199>/Hall Value of 6' incorporates:
           *  ActionPort: '<S208>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_d,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof6_d);

          /* End of Outputs for SubSystem: '<S199>/Hall Value of 6' */
          break;

         default:
          /* Outputs for IfAction SubSystem: '<S199>/Hall Value of 7' incorporates:
           *  ActionPort: '<S209>/Action Port'
           */
          mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1_d,
            &mcb_pmsm_foc_hall_f28069m_P.HallValueof7_a);

          /* End of Outputs for SubSystem: '<S199>/Hall Value of 7' */
          break;
        }

        /* End of SwitchCase: '<S199>/Switch Case' */

        /* Merge: '<S198>/Merge' incorporates:
         *  Sum: '<S199>/Sum'
         */
        mcb_pmsm_foc_hall_f28069m_B.Merge_b =
          mcb_pmsm_foc_hall_f28069m_B.Merge1_d +
          mcb_pmsm_foc_hall_f28069m_B.Saturation_f;

        /* End of Outputs for SubSystem: '<S198>/+ve Direction' */
      }

      /* End of If: '<S198>/If' */
    }

    /* End of Outputs for SubSystem: '<S185>/Subsystem1' */

    /* Merge: '<S173>/Merge1' incorporates:
     *  Constant: '<S185>/PositionEnable'
     *  SignalConversion generated from: '<S185>/rawPosition'
     */
    mcb_pmsm_foc_hall_f28069m_B.Merge1 = mcb_pmsm_foc_hall_f28069m_B.Merge_b;

    /* End of Outputs for SubSystem: '<S173>/Speed and direction are valid Use speed to extrapolate position' */
  } else {
    /* Outputs for IfAction SubSystem: '<S173>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
     *  ActionPort: '<S184>/Action Port'
     */
    /* SwitchCase: '<S188>/Switch Case' */
    switch ((int32_T)mcb_pmsm_foc_hall_f28069m_B.Merge) {
     case 5L:
      /* Outputs for IfAction SubSystem: '<S188>/Hall Value of 1' incorporates:
       *  ActionPort: '<S189>/Action Port'
       */
      mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1,
        &mcb_pmsm_foc_hall_f28069m_P.HallValueof1_m);

      /* End of Outputs for SubSystem: '<S188>/Hall Value of 1' */
      break;

     case 4L:
      /* Outputs for IfAction SubSystem: '<S188>/Hall Value of 2' incorporates:
       *  ActionPort: '<S190>/Action Port'
       */
      mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1,
        &mcb_pmsm_foc_hall_f28069m_P.HallValueof2_m);

      /* End of Outputs for SubSystem: '<S188>/Hall Value of 2' */
      break;

     case 6L:
      /* Outputs for IfAction SubSystem: '<S188>/Hall Value of 3' incorporates:
       *  ActionPort: '<S191>/Action Port'
       */
      mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1,
        &mcb_pmsm_foc_hall_f28069m_P.HallValueof3_kd);

      /* End of Outputs for SubSystem: '<S188>/Hall Value of 3' */
      break;

     case 2L:
      /* Outputs for IfAction SubSystem: '<S188>/Hall Value of 4' incorporates:
       *  ActionPort: '<S192>/Action Port'
       */
      mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1,
        &mcb_pmsm_foc_hall_f28069m_P.HallValueof4_p);

      /* End of Outputs for SubSystem: '<S188>/Hall Value of 4' */
      break;

     case 3L:
      /* Outputs for IfAction SubSystem: '<S188>/Hall Value of 5' incorporates:
       *  ActionPort: '<S193>/Action Port'
       */
      mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1,
        &mcb_pmsm_foc_hall_f28069m_P.HallValueof5_i);

      /* End of Outputs for SubSystem: '<S188>/Hall Value of 5' */
      break;

     case 1L:
      /* Outputs for IfAction SubSystem: '<S188>/Hall Value of 6' incorporates:
       *  ActionPort: '<S194>/Action Port'
       */
      mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1,
        &mcb_pmsm_foc_hall_f28069m_P.HallValueof6_p);

      /* End of Outputs for SubSystem: '<S188>/Hall Value of 6' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S188>/Hall Value of 7' incorporates:
       *  ActionPort: '<S195>/Action Port'
       */
      mcb_pmsm_foc_h_HallValueof1(&mcb_pmsm_foc_hall_f28069m_B.Merge1,
        &mcb_pmsm_foc_hall_f28069m_P.HallValueof7_p);

      /* End of Outputs for SubSystem: '<S188>/Hall Value of 7' */
      break;
    }

    /* End of SwitchCase: '<S188>/Switch Case' */

    /* Merge: '<S173>/Merge' incorporates:
     *  Constant: '<S184>/Constant'
     *  SignalConversion generated from: '<S184>/Speed(r.p.m)'
     */
    mcb_pmsm_foc_hall_f28069m_B.Merge_m =
      mcb_pmsm_foc_hall_f28069m_P.Constant_Value_m4;

    /* End of Outputs for SubSystem: '<S173>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
  }

  /* End of If: '<S173>/If' */

  /* Gain: '<S173>/PositionUnit' */
  mcb_pmsm_foc_hall_f28069m_B.PositionUnit =
    mcb_pmsm_foc_hall_f28069m_P.PositionUnit_Gain *
    mcb_pmsm_foc_hall_f28069m_B.Merge1;

  /* Sum: '<S183>/Sum' incorporates:
   *  Constant: '<S183>/Constant2'
   */
  mcb_pmsm_foc_hall_f28069m_B.Sum_at = mcb_pmsm_foc_hall_f28069m_B.DelayOneStep
    - mcb_pmsm_foc_hall_f28069m_P.Constant2_Value;

  /* Switch: '<S218>/Switch' incorporates:
   *  Constant: '<S218>/Constant'
   */
  if (mcb_pmsm_foc_hall_f28069m_P.Constant_Value_dp >
      mcb_pmsm_foc_hall_f28069m_P.Switch_Threshold_l) {
    /* Switch: '<S218>/Switch' incorporates:
     *  Constant: '<S218>/Constant1'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch_pz =
      mcb_pmsm_foc_hall_f28069m_P.Constant1_Value;
  } else {
    /* Switch: '<S218>/Switch' incorporates:
     *  Constant: '<S174>/ReplaceInport_Offset'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch_pz =
      mcb_pmsm_foc_hall_f28069m_P.ReplaceInport_Offset_Value;
  }

  /* End of Switch: '<S218>/Switch' */

  /* If: '<S219>/If' */
  if (mcb_pmsm_foc_hall_f28069m_B.PositionUnit <=
      mcb_pmsm_foc_hall_f28069m_B.Switch_pz) {
    /* Outputs for IfAction SubSystem: '<S219>/If Action Subsystem' incorporates:
     *  ActionPort: '<S221>/Action Port'
     */
    /* Merge: '<S219>/Merge' incorporates:
     *  Constant: '<S221>/Constant'
     *  Sum: '<S221>/Add'
     */
    mcb_pmsm_foc_hall_f28069m_B.Merge_p =
      (mcb_pmsm_foc_hall_f28069m_B.PositionUnit +
       mcb_pmsm_foc_hall_f28069m_P.Constant_Value_l) -
      mcb_pmsm_foc_hall_f28069m_B.Switch_pz;

    /* End of Outputs for SubSystem: '<S219>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S219>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S222>/Action Port'
     */
    /* Merge: '<S219>/Merge' incorporates:
     *  Sum: '<S222>/Add'
     */
    mcb_pmsm_foc_hall_f28069m_B.Merge_p =
      mcb_pmsm_foc_hall_f28069m_B.PositionUnit -
      mcb_pmsm_foc_hall_f28069m_B.Switch_pz;

    /* End of Outputs for SubSystem: '<S219>/If Action Subsystem1' */
  }

  /* End of If: '<S219>/If' */

  /* Gain: '<S224>/Number of pole pairs' */
  mcb_pmsm_foc_hall_f28069m_B.Numberofpolepairs =
    mcb_pmsm_foc_hall_f28069m_P.MechanicaltoElectricalPosition_ *
    mcb_pmsm_foc_hall_f28069m_B.Merge_p;

  /* Gain: '<S220>/Multiply' */
  mcb_pmsm_foc_hall_f28069m_B.Multiply =
    mcb_pmsm_foc_hall_f28069m_P.Multiply_Gain *
    mcb_pmsm_foc_hall_f28069m_B.Numberofpolepairs;

  /* Rounding: '<S220>/Floor' */
  mcb_pmsm_foc_hall_f28069m_B.Floor = (real32_T)floor
    (mcb_pmsm_foc_hall_f28069m_B.Multiply);

  /* Gain: '<S220>/Multiply1' */
  mcb_pmsm_foc_hall_f28069m_B.Multiply1 =
    mcb_pmsm_foc_hall_f28069m_P.Multiply1_Gain *
    mcb_pmsm_foc_hall_f28069m_B.Floor;

  /* Sum: '<S220>/Add' */
  mcb_pmsm_foc_hall_f28069m_B.Add =
    mcb_pmsm_foc_hall_f28069m_B.Numberofpolepairs -
    mcb_pmsm_foc_hall_f28069m_B.Multiply1;

  /* DataStoreRead: '<S170>/Data Store Read' */
  mcb_pmsm_foc_hall_f28069m_B.DataStoreRead_e =
    mcb_pmsm_foc_hall_f28069m_DWork.IaOffset;

  /* DataStoreRead: '<S170>/Data Store Read1' */
  mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1 =
    mcb_pmsm_foc_hall_f28069m_DWork.IbOffset;

  /* S-Function (c2802xadc): '<S228>/ADC' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcaRegs.ADCSOCFRC1.bit.SOC2 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #67|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    float wait_index;
    for (wait_index= 11; wait_index > 0; wait_index--)
      __mnop();

#endif

    mcb_pmsm_foc_hall_f28069m_B.ADC_n = (AdcaResultRegs.ADCRESULT2);
  }

  /* DataTypeConversion: '<S170>/Data Type Conversion' */
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_n =
    mcb_pmsm_foc_hall_f28069m_B.ADC_n;

  /* Sum: '<S170>/Add' */
  mcb_pmsm_foc_hall_f28069m_B.Add_m[0] =
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_n -
    mcb_pmsm_foc_hall_f28069m_B.DataStoreRead_e;
  mcb_pmsm_foc_hall_f28069m_B.Add_m[1] =
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_n -
    mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1;

  /* ArithShift: '<S170>/Q17 per unit conversion' incorporates:
   *  Sum: '<S170>/Add'
   */
  Q17perunitconversion = mcb_pmsm_foc_hall_f28069m_B.Add_m[0] << 6U;
  mcb_pmsm_foc_hall_f28069m_B.Q17perunitconversion[0] = Q17perunitconversion;

  /* UnaryMinus: '<S170>/DRV_8312 EVM is using an inverted amplifier circuit for current sensing' incorporates:
   *  ArithShift: '<S170>/Q17 per unit conversion'
   */
  Q17perunitconversion = -Q17perunitconversion;
  mcb_pmsm_foc_hall_f28069m_B.DRV_8312EVMisusinganinvertedamp[0] =
    Q17perunitconversion;

  /* DataTypeConversion: '<S170>/Data Type Conversion1' incorporates:
   *  UnaryMinus: '<S170>/DRV_8312 EVM is using an inverted amplifier circuit for current sensing'
   */
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_m[0] = (real32_T)
    Q17perunitconversion * 7.62939453E-6F;

  /* ArithShift: '<S170>/Q17 per unit conversion' incorporates:
   *  Sum: '<S170>/Add'
   */
  Q17perunitconversion = mcb_pmsm_foc_hall_f28069m_B.Add_m[1] << 6U;
  mcb_pmsm_foc_hall_f28069m_B.Q17perunitconversion[1] = Q17perunitconversion;

  /* UnaryMinus: '<S170>/DRV_8312 EVM is using an inverted amplifier circuit for current sensing' incorporates:
   *  ArithShift: '<S170>/Q17 per unit conversion'
   */
  Q17perunitconversion = -Q17perunitconversion;
  mcb_pmsm_foc_hall_f28069m_B.DRV_8312EVMisusinganinvertedamp[1] =
    Q17perunitconversion;

  /* DataTypeConversion: '<S170>/Data Type Conversion1' incorporates:
   *  UnaryMinus: '<S170>/DRV_8312 EVM is using an inverted amplifier circuit for current sensing'
   */
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_m[1] = (real32_T)
    Q17perunitconversion * 7.62939453E-6F;

  /* UnitDelay: '<S161>/Output' */
  mcb_pmsm_foc_hall_f28069m_B.Output =
    mcb_pmsm_foc_hall_f28069m_DWork.Output_DSTATE;

  /* DataTypeConversion: '<S163>/Data Type Conversion' */
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_m[0] = (int32_T)
    (mcb_pmsm_foc_hall_f28069m_B.Merge_m * 4096.0F);
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_m[1] = (int32_T)
    (mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_m[0] * 4096.0F);

  /* DataTypeConversion: '<S163>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S163>/Data Type Conversion'
   */
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion3[0] = (uint16_T)
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_m[0];
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion3[1] = (uint16_T)
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_m[1];

  /* If: '<S12>/If' */
  if (mcb_pmsm_foc_hall_f28069m_B.Output == 0U) {
    /* Outputs for IfAction SubSystem: '<S12>/Start' incorporates:
     *  ActionPort: '<S165>/Action Port'
     */
    /* Merge: '<S12>/Merge' incorporates:
     *  Constant: '<S165>/End'
     *  SignalConversion generated from: '<S165>/Data_out'
     */
    mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Data[0] =
      mcb_pmsm_foc_hall_f28069m_P.End_Value;

    /* SignalConversion generated from: '<S165>/Data' */
    Data = mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion3[0];

    /* End of Outputs for SubSystem: '<S12>/Start' */
    mcb_pmsm_foc_hall_f28069m_B.Data_fw[0] = Data;

    /* Outputs for IfAction SubSystem: '<S12>/Start' incorporates:
     *  ActionPort: '<S165>/Action Port'
     */
    /* Merge: '<S12>/Merge' incorporates:
     *  SignalConversion generated from: '<S165>/Data_out'
     */
    mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Data[1] = Data;

    /* SignalConversion generated from: '<S165>/Data' */
    Data = mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion3[1];

    /* End of Outputs for SubSystem: '<S12>/Start' */
    mcb_pmsm_foc_hall_f28069m_B.Data_fw[1] = Data;

    /* Outputs for IfAction SubSystem: '<S12>/Start' incorporates:
     *  ActionPort: '<S165>/Action Port'
     */
    /* Merge: '<S12>/Merge' incorporates:
     *  SignalConversion generated from: '<S165>/Data_out'
     */
    mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Data[2] = Data;

    /* Merge: '<S12>/Merge1' incorporates:
     *  Bias: '<S165>/Bias'
     */
    mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_hall_f28069_ConstB.Width +
      mcb_pmsm_foc_hall_f28069m_P.Bias_Bias;

    /* End of Outputs for SubSystem: '<S12>/Start' */
  } else if (mcb_pmsm_foc_hall_f28069m_B.Output == 599U) {
    /* Outputs for IfAction SubSystem: '<S12>/End' incorporates:
     *  ActionPort: '<S164>/Action Port'
     */
    /* SignalConversion generated from: '<S164>/Data' */
    Data = mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion3[0];

    /* End of Outputs for SubSystem: '<S12>/End' */
    mcb_pmsm_foc_hall_f28069m_B.Data_f[0] = Data;

    /* Outputs for IfAction SubSystem: '<S12>/End' incorporates:
     *  ActionPort: '<S164>/Action Port'
     */
    /* Merge: '<S12>/Merge' incorporates:
     *  SignalConversion generated from: '<S164>/Data_out'
     */
    mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Data[0] = Data;

    /* SignalConversion generated from: '<S164>/Data' */
    Data = mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion3[1];

    /* End of Outputs for SubSystem: '<S12>/End' */
    mcb_pmsm_foc_hall_f28069m_B.Data_f[1] = Data;

    /* Outputs for IfAction SubSystem: '<S12>/End' incorporates:
     *  ActionPort: '<S164>/Action Port'
     */
    /* Merge: '<S12>/Merge' incorporates:
     *  Constant: '<S164>/Start'
     *  SignalConversion generated from: '<S164>/Data_out'
     */
    mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Data[1] = Data;
    mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Data[2] =
      mcb_pmsm_foc_hall_f28069m_P.Start_Value;

    /* Merge: '<S12>/Merge1' incorporates:
     *  Bias: '<S164>/Bias'
     */
    mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_hall_f28069_ConstB.Width +
      mcb_pmsm_foc_hall_f28069m_P.Bias_Bias_l;

    /* End of Outputs for SubSystem: '<S12>/End' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/Data' incorporates:
     *  ActionPort: '<S162>/Action Port'
     */
    /* SignalConversion generated from: '<S162>/Data' */
    Data = mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion3[0];

    /* End of Outputs for SubSystem: '<S12>/Data' */
    mcb_pmsm_foc_hall_f28069m_B.Data[0] = Data;

    /* Outputs for IfAction SubSystem: '<S12>/Data' incorporates:
     *  ActionPort: '<S162>/Action Port'
     */
    /* Merge: '<S12>/Merge' incorporates:
     *  SignalConversion generated from: '<S162>/Data_out'
     */
    mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Data[0] = Data;

    /* SignalConversion generated from: '<S162>/Data' */
    Data = mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion3[1];

    /* End of Outputs for SubSystem: '<S12>/Data' */
    mcb_pmsm_foc_hall_f28069m_B.Data[1] = Data;

    /* Outputs for IfAction SubSystem: '<S12>/Data' incorporates:
     *  ActionPort: '<S162>/Action Port'
     */
    /* Merge: '<S12>/Merge' incorporates:
     *  Constant: '<S162>/Start'
     *  SignalConversion generated from: '<S162>/Data_out'
     */
    mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Data[1] = Data;
    mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Data[2] =
      mcb_pmsm_foc_hall_f28069m_P.Start_Value_c;

    /* Merge: '<S12>/Merge1' incorporates:
     *  SignalConversion generated from: '<S162>/Data_width'
     */
    mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_hall_f28069_ConstB.Width;

    /* End of Outputs for SubSystem: '<S12>/Data' */
  }

  /* End of If: '<S12>/If' */

  /* Outputs for Iterator SubSystem: '<S226>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S227>/While Iterator'
   */
  s227_iter = 1;
  do {
    mcb_pmsm_foc_hall_f28069m_B.WhileIterator = s227_iter;
    mcb_pmsm_foc_hall_f28069m_B.IndexVector =
      mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Data[mcb_pmsm_foc_hall_f28069m_B.WhileIterator
      - 1];

    {
      if (checkSCITransmitInProgressA != 1U) {
        checkSCITransmitInProgressA = 1U;
        int16_T errFlgHeader = NOERROR;
        int16_T errFlgData = NOERROR;
        int16_T errFlgTail = NOERROR;
        errFlgData = scia_xmit((unsigned char*)
          &mcb_pmsm_foc_hall_f28069m_B.IndexVector, 2, 2);
        checkSCITransmitInProgressA = 0U;
      }
    }

    mcb_pmsm_foc_hall_f28069m_B.Add_ml =
      mcb_pmsm_foc_hall_f28069m_B.SCI_Tx_Iteration - (uint16_T)
      mcb_pmsm_foc_hall_f28069m_B.WhileIterator;
    s227_iter++;
  } while (mcb_pmsm_foc_hall_f28069m_B.Add_ml != 0U);

  /* End of Outputs for SubSystem: '<S226>/While Iterator Subsystem' */

  /* Outputs for Atomic SubSystem: '<S24>/Two phase CRL wrap' */
  /* Sum: '<S25>/a_plus_2b' */
  mcb_pmsm_foc_hall_f28069m_B.a_plus_2b =
    (mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_m[0] +
     mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_m[1]) +
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_m[1];

  /* Gain: '<S25>/one_by_sqrt3' */
  mcb_pmsm_foc_hall_f28069m_B.one_by_sqrt3 =
    mcb_pmsm_foc_hall_f28069m_P.one_by_sqrt3_Gain *
    mcb_pmsm_foc_hall_f28069m_B.a_plus_2b;

  /* AlgorithmDescriptorDelegate generated from: '<S25>/a16' */
  mcb_pmsm_foc_hall_f28069m_B.algDD_o1_b =
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_m[0];

  /* AlgorithmDescriptorDelegate generated from: '<S25>/a16' */
  mcb_pmsm_foc_hall_f28069m_B.algDD_o2_a =
    mcb_pmsm_foc_hall_f28069m_B.one_by_sqrt3;

  /* End of Outputs for SubSystem: '<S24>/Two phase CRL wrap' */

  /* Gain: '<S24>/Kalpha' */
  mcb_pmsm_foc_hall_f28069m_B.Kalpha = mcb_pmsm_foc_hall_f28069m_P.Kalpha_Gain *
    mcb_pmsm_foc_hall_f28069m_B.algDD_o1_b;

  /* Gain: '<S24>/Kbeta' */
  mcb_pmsm_foc_hall_f28069m_B.Kbeta = mcb_pmsm_foc_hall_f28069m_P.Kbeta_Gain *
    mcb_pmsm_foc_hall_f28069m_B.algDD_o2_a;

  /* Switch: '<S31>/Switch1' incorporates:
   *  Constant: '<S31>/enableInportSatMethod'
   */
  if (mcb_pmsm_foc_hall_f28069m_P.enableInportSatMethod_Value != 0U) {
    /* Switch: '<S31>/Switch1' incorporates:
     *  Constant: '<S26>/ReplaceInport_satMethod'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch1_c =
      mcb_pmsm_foc_hall_f28069m_P.ReplaceInport_satMethod_Value;
  } else {
    /* Switch: '<S31>/Switch1' incorporates:
     *  Constant: '<S31>/ChosenMethod'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch1_c =
      mcb_pmsm_foc_hall_f28069m_P.ChosenMethod_Value;
  }

  /* End of Switch: '<S31>/Switch1' */

  /* Gain: '<S150>/convert_pu' */
  mcb_pmsm_foc_hall_f28069m_B.convert_pu =
    mcb_pmsm_foc_hall_f28069m_P.convert_pu_Gain *
    mcb_pmsm_foc_hall_f28069m_B.Add;

  /* RelationalOperator: '<S151>/Compare' incorporates:
   *  Constant: '<S151>/Constant'
   */
  mcb_pmsm_foc_hall_f28069m_B.Compare_p =
    (mcb_pmsm_foc_hall_f28069m_B.convert_pu <
     mcb_pmsm_foc_hall_f28069m_P.Constant_Value_h5);

  /* DataTypeConversion: '<S150>/Data Type Conversion' */
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_l =
    mcb_pmsm_foc_hall_f28069m_B.Compare_p;

  /* If: '<S150>/If' */
  if (mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_l > 0U) {
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    /* DataTypeConversion: '<S152>/Convert_uint16' */
    mcb_pmsm_foc_hall_f28069m_B.Convert_uint16_i = (int16_T)(real32_T)floor
      (mcb_pmsm_foc_hall_f28069m_B.convert_pu);

    /* DataTypeConversion: '<S152>/Convert_back' */
    mcb_pmsm_foc_hall_f28069m_B.Convert_back_e =
      mcb_pmsm_foc_hall_f28069m_B.Convert_uint16_i;

    /* Merge: '<S150>/Merge' incorporates:
     *  Sum: '<S152>/Sum'
     */
    mcb_pmsm_foc_hall_f28069m_B.Merge_n = mcb_pmsm_foc_hall_f28069m_B.convert_pu
      - mcb_pmsm_foc_hall_f28069m_B.Convert_back_e;

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    /* DataTypeConversion: '<S153>/Convert_uint16' */
    mcb_pmsm_foc_hall_f28069m_B.Convert_uint16 = (int16_T)
      mcb_pmsm_foc_hall_f28069m_B.convert_pu;

    /* DataTypeConversion: '<S153>/Convert_back' */
    mcb_pmsm_foc_hall_f28069m_B.Convert_back =
      mcb_pmsm_foc_hall_f28069m_B.Convert_uint16;

    /* Merge: '<S150>/Merge' incorporates:
     *  Sum: '<S153>/Sum'
     */
    mcb_pmsm_foc_hall_f28069m_B.Merge_n = mcb_pmsm_foc_hall_f28069m_B.convert_pu
      - mcb_pmsm_foc_hall_f28069m_B.Convert_back;

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem1' */
  }

  /* End of If: '<S150>/If' */

  /* Gain: '<S22>/indexing' */
  mcb_pmsm_foc_hall_f28069m_B.indexing =
    mcb_pmsm_foc_hall_f28069m_P.indexing_Gain *
    mcb_pmsm_foc_hall_f28069m_B.Merge_n;

  /* DataTypeConversion: '<S22>/Get_Integer' */
  mcb_pmsm_foc_hall_f28069m_B.Get_Integer = (uint16_T)
    mcb_pmsm_foc_hall_f28069m_B.indexing;

  /* Sum: '<S22>/Sum' incorporates:
   *  Constant: '<S22>/offset'
   */
  u1 = (uint32_T)mcb_pmsm_foc_hall_f28069m_P.offset_Value[0] +
    mcb_pmsm_foc_hall_f28069m_B.Get_Integer;
  mcb_pmsm_foc_hall_f28069m_B.Sum[0] = u1;

  /* Selector: '<S22>/Lookup' incorporates:
   *  Constant: '<S22>/sine_table_values'
   */
  mcb_pmsm_foc_hall_f28069m_B.Lookup[0] =
    mcb_pmsm_foc_hall_f28069m_P.sine_table_values_Value[(int16_T)u1];

  /* Sum: '<S22>/Sum' incorporates:
   *  Constant: '<S22>/offset'
   */
  u1 = (uint32_T)mcb_pmsm_foc_hall_f28069m_P.offset_Value[1] +
    mcb_pmsm_foc_hall_f28069m_B.Get_Integer;
  mcb_pmsm_foc_hall_f28069m_B.Sum[1] = u1;

  /* Selector: '<S22>/Lookup' incorporates:
   *  Constant: '<S22>/sine_table_values'
   */
  mcb_pmsm_foc_hall_f28069m_B.Lookup[1] =
    mcb_pmsm_foc_hall_f28069m_P.sine_table_values_Value[(int16_T)u1];

  /* Sum: '<S22>/Sum' incorporates:
   *  Constant: '<S22>/offset'
   */
  u1 = (uint32_T)mcb_pmsm_foc_hall_f28069m_P.offset_Value[2] +
    mcb_pmsm_foc_hall_f28069m_B.Get_Integer;
  mcb_pmsm_foc_hall_f28069m_B.Sum[2] = u1;

  /* Selector: '<S22>/Lookup' incorporates:
   *  Constant: '<S22>/sine_table_values'
   */
  mcb_pmsm_foc_hall_f28069m_B.Lookup[2] =
    mcb_pmsm_foc_hall_f28069m_P.sine_table_values_Value[(int16_T)u1];

  /* Sum: '<S22>/Sum' incorporates:
   *  Constant: '<S22>/offset'
   */
  u1 = (uint32_T)mcb_pmsm_foc_hall_f28069m_P.offset_Value[3] +
    mcb_pmsm_foc_hall_f28069m_B.Get_Integer;
  mcb_pmsm_foc_hall_f28069m_B.Sum[3] = u1;

  /* Selector: '<S22>/Lookup' incorporates:
   *  Constant: '<S22>/sine_table_values'
   */
  mcb_pmsm_foc_hall_f28069m_B.Lookup[3] =
    mcb_pmsm_foc_hall_f28069m_P.sine_table_values_Value[(int16_T)u1];

  /* Sum: '<S149>/Sum3' */
  mcb_pmsm_foc_hall_f28069m_B.Sum3 = mcb_pmsm_foc_hall_f28069m_B.Lookup[0] -
    mcb_pmsm_foc_hall_f28069m_B.Lookup[1];

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_b =
    mcb_pmsm_foc_hall_f28069m_B.Get_Integer;

  /* Sum: '<S22>/Sum2' */
  mcb_pmsm_foc_hall_f28069m_B.Sum2 = mcb_pmsm_foc_hall_f28069m_B.indexing -
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_b;

  /* Product: '<S149>/Product' */
  mcb_pmsm_foc_hall_f28069m_B.Product_l = mcb_pmsm_foc_hall_f28069m_B.Sum3 *
    mcb_pmsm_foc_hall_f28069m_B.Sum2;

  /* Sum: '<S149>/Sum4' */
  mcb_pmsm_foc_hall_f28069m_B.Sum4 = mcb_pmsm_foc_hall_f28069m_B.Product_l +
    mcb_pmsm_foc_hall_f28069m_B.Lookup[1];

  /* Sum: '<S149>/Sum5' */
  mcb_pmsm_foc_hall_f28069m_B.Sum5 = mcb_pmsm_foc_hall_f28069m_B.Lookup[2] -
    mcb_pmsm_foc_hall_f28069m_B.Lookup[3];

  /* Product: '<S149>/Product1' */
  mcb_pmsm_foc_hall_f28069m_B.Product1_a = mcb_pmsm_foc_hall_f28069m_B.Sum5 *
    mcb_pmsm_foc_hall_f28069m_B.Sum2;

  /* Sum: '<S149>/Sum6' */
  mcb_pmsm_foc_hall_f28069m_B.Sum6 = mcb_pmsm_foc_hall_f28069m_B.Product1_a +
    mcb_pmsm_foc_hall_f28069m_B.Lookup[3];

  /* Outputs for Atomic SubSystem: '<S21>/Two inputs CRL' */
  /* Product: '<S147>/bcos' */
  mcb_pmsm_foc_hall_f28069m_B.bcos = mcb_pmsm_foc_hall_f28069m_B.Kbeta *
    mcb_pmsm_foc_hall_f28069m_B.Sum6;

  /* Product: '<S147>/asin' */
  mcb_pmsm_foc_hall_f28069m_B.asin_h = mcb_pmsm_foc_hall_f28069m_B.Kalpha *
    mcb_pmsm_foc_hall_f28069m_B.Sum4;

  /* Sum: '<S147>/sum_Qs' */
  mcb_pmsm_foc_hall_f28069m_B.sum_Qs = mcb_pmsm_foc_hall_f28069m_B.bcos -
    mcb_pmsm_foc_hall_f28069m_B.asin_h;

  /* Product: '<S147>/acos' */
  mcb_pmsm_foc_hall_f28069m_B.acos_c = mcb_pmsm_foc_hall_f28069m_B.Kalpha *
    mcb_pmsm_foc_hall_f28069m_B.Sum6;

  /* Product: '<S147>/bsin' */
  mcb_pmsm_foc_hall_f28069m_B.bsin = mcb_pmsm_foc_hall_f28069m_B.Kbeta *
    mcb_pmsm_foc_hall_f28069m_B.Sum4;

  /* Sum: '<S147>/sum_Ds' */
  mcb_pmsm_foc_hall_f28069m_B.sum_Ds = mcb_pmsm_foc_hall_f28069m_B.acos_c +
    mcb_pmsm_foc_hall_f28069m_B.bsin;

  /* Switch: '<S148>/Switch' incorporates:
   *  Constant: '<S148>/Offset'
   */
  if (mcb_pmsm_foc_hall_f28069m_P.Offset_Value_m >
      mcb_pmsm_foc_hall_f28069m_P.Switch_Threshold_g) {
    /* UnaryMinus: '<S148>/Unary_Minus' */
    mcb_pmsm_foc_hall_f28069m_B.Unary_Minus =
      -mcb_pmsm_foc_hall_f28069m_B.sum_Qs;

    /* Switch: '<S148>/Switch' */
    mcb_pmsm_foc_hall_f28069m_B.Switch_kn[0] =
      mcb_pmsm_foc_hall_f28069m_B.Unary_Minus;
    mcb_pmsm_foc_hall_f28069m_B.Switch_kn[1] =
      mcb_pmsm_foc_hall_f28069m_B.sum_Ds;
  } else {
    /* Switch: '<S148>/Switch' */
    mcb_pmsm_foc_hall_f28069m_B.Switch_kn[0] =
      mcb_pmsm_foc_hall_f28069m_B.sum_Ds;
    mcb_pmsm_foc_hall_f28069m_B.Switch_kn[1] =
      mcb_pmsm_foc_hall_f28069m_B.sum_Qs;
  }

  /* End of Switch: '<S148>/Switch' */

  /* AlgorithmDescriptorDelegate generated from: '<S147>/a16' */
  mcb_pmsm_foc_hall_f28069m_B.algDD_o1 = mcb_pmsm_foc_hall_f28069m_B.Switch_kn[0];

  /* AlgorithmDescriptorDelegate generated from: '<S147>/a16' */
  mcb_pmsm_foc_hall_f28069m_B.algDD_o2 = mcb_pmsm_foc_hall_f28069m_B.Switch_kn[1];

  /* End of Outputs for SubSystem: '<S21>/Two inputs CRL' */

  /* Sum: '<S28>/Sum' */
  mcb_pmsm_foc_hall_f28069m_B.Sum_i = mcb_pmsm_foc_hall_f28069m_B.RT6[1] -
    mcb_pmsm_foc_hall_f28069m_B.algDD_o2;

  /* Constant: '<S28>/Kp' */
  mcb_pmsm_foc_hall_f28069m_B.Kp = mcb_pmsm_foc_hall_f28069m_P.Kp_Value;

  /* Product: '<S133>/PProd Out' */
  mcb_pmsm_foc_hall_f28069m_B.PProdOut_d = mcb_pmsm_foc_hall_f28069m_B.Sum_i *
    mcb_pmsm_foc_hall_f28069m_B.Kp;

  /* DataStoreRead: '<S28>/Data Store Read1' */
  mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_o =
    mcb_pmsm_foc_hall_f28069m_DWork.Enable;

  /* Logic: '<S28>/Logical Operator' */
  mcb_pmsm_foc_hall_f28069m_B.LogicalOperator_c =
    !mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_o;

  /* Constant: '<S28>/Kp1' */
  mcb_pmsm_foc_hall_f28069m_B.Kp1_c = mcb_pmsm_foc_hall_f28069m_P.Kp1_Value;

  /* DiscreteIntegrator: '<S128>/Integrator' */
  if (mcb_pmsm_foc_hall_f28069m_B.LogicalOperator_c ||
      (mcb_pmsm_foc_hall_f28069m_DWork.Integrator_PrevResetState_o != 0)) {
    mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE_k =
      mcb_pmsm_foc_hall_f28069m_B.Kp1_c;
  }

  /* DiscreteIntegrator: '<S128>/Integrator' */
  mcb_pmsm_foc_hall_f28069m_B.Integrator_h =
    mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE_k;

  /* Sum: '<S137>/Sum' */
  mcb_pmsm_foc_hall_f28069m_B.Sum_n = mcb_pmsm_foc_hall_f28069m_B.PProdOut_d +
    mcb_pmsm_foc_hall_f28069m_B.Integrator_h;

  /* Saturate: '<S135>/Saturation' */
  u0_0 = mcb_pmsm_foc_hall_f28069m_B.Sum_n;
  u1_0 = mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiwin;
  Bias = mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_f;
  if (u0_0 > Bias) {
    /* Saturate: '<S135>/Saturation' */
    mcb_pmsm_foc_hall_f28069m_B.Saturation_d = Bias;
  } else if (u0_0 < u1_0) {
    /* Saturate: '<S135>/Saturation' */
    mcb_pmsm_foc_hall_f28069m_B.Saturation_d = u1_0;
  } else {
    /* Saturate: '<S135>/Saturation' */
    mcb_pmsm_foc_hall_f28069m_B.Saturation_d = u0_0;
  }

  /* End of Saturate: '<S135>/Saturation' */

  /* Sum: '<S27>/Sum' */
  mcb_pmsm_foc_hall_f28069m_B.Sum_p = mcb_pmsm_foc_hall_f28069m_B.RT6[0] -
    mcb_pmsm_foc_hall_f28069m_B.algDD_o1;

  /* Constant: '<S27>/Kp' */
  mcb_pmsm_foc_hall_f28069m_B.Kp_i = mcb_pmsm_foc_hall_f28069m_P.Kp_Value_p;

  /* Product: '<S82>/PProd Out' */
  mcb_pmsm_foc_hall_f28069m_B.PProdOut_p = mcb_pmsm_foc_hall_f28069m_B.Sum_p *
    mcb_pmsm_foc_hall_f28069m_B.Kp_i;

  /* DataStoreRead: '<S27>/Data Store Read1' */
  mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_c =
    mcb_pmsm_foc_hall_f28069m_DWork.Enable;

  /* Logic: '<S27>/Logical Operator' */
  mcb_pmsm_foc_hall_f28069m_B.LogicalOperator_n =
    !mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_c;

  /* Constant: '<S27>/Ki1' */
  mcb_pmsm_foc_hall_f28069m_B.Ki1 = mcb_pmsm_foc_hall_f28069m_P.Ki1_Value;

  /* DiscreteIntegrator: '<S77>/Integrator' */
  if (mcb_pmsm_foc_hall_f28069m_B.LogicalOperator_n ||
      (mcb_pmsm_foc_hall_f28069m_DWork.Integrator_PrevResetState_j != 0)) {
    mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE_g =
      mcb_pmsm_foc_hall_f28069m_B.Ki1;
  }

  /* DiscreteIntegrator: '<S77>/Integrator' */
  mcb_pmsm_foc_hall_f28069m_B.Integrator_n =
    mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE_g;

  /* Sum: '<S86>/Sum' */
  mcb_pmsm_foc_hall_f28069m_B.Sum_ai = mcb_pmsm_foc_hall_f28069m_B.PProdOut_p +
    mcb_pmsm_foc_hall_f28069m_B.Integrator_n;

  /* Saturate: '<S84>/Saturation' */
  u0_0 = mcb_pmsm_foc_hall_f28069m_B.Sum_ai;
  u1_0 = mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_o;
  Bias = mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_e;
  if (u0_0 > Bias) {
    /* Saturate: '<S84>/Saturation' */
    mcb_pmsm_foc_hall_f28069m_B.Saturation_c = Bias;
  } else if (u0_0 < u1_0) {
    /* Saturate: '<S84>/Saturation' */
    mcb_pmsm_foc_hall_f28069m_B.Saturation_c = u1_0;
  } else {
    /* Saturate: '<S84>/Saturation' */
    mcb_pmsm_foc_hall_f28069m_B.Saturation_c = u0_0;
  }

  /* End of Saturate: '<S84>/Saturation' */

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S31>/enableInportSatLim'
   */
  if (mcb_pmsm_foc_hall_f28069m_P.enableInportSatLim_Value != 0U) {
    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S26>/ReplaceInport_satLim'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch_k =
      mcb_pmsm_foc_hall_f28069m_P.ReplaceInport_satLim_Value;
  } else {
    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S31>/Constant3'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch_k =
      mcb_pmsm_foc_hall_f28069m_P.Constant3_Value;
  }

  /* End of Switch: '<S31>/Switch' */

  /* Product: '<S31>/Product' */
  mcb_pmsm_foc_hall_f28069m_B.Product_o = mcb_pmsm_foc_hall_f28069m_B.Switch_k *
    mcb_pmsm_foc_hall_f28069m_B.Switch_k;

  /* Product: '<S32>/Product' */
  mcb_pmsm_foc_hall_f28069m_B.Product_g =
    mcb_pmsm_foc_hall_f28069m_B.Saturation_c *
    mcb_pmsm_foc_hall_f28069m_B.Saturation_c;

  /* Product: '<S32>/Product1' */
  mcb_pmsm_foc_hall_f28069m_B.Product1_m =
    mcb_pmsm_foc_hall_f28069m_B.Saturation_d *
    mcb_pmsm_foc_hall_f28069m_B.Saturation_d;

  /* Sum: '<S32>/Sum1' */
  mcb_pmsm_foc_hall_f28069m_B.Sum1 = mcb_pmsm_foc_hall_f28069m_B.Product_g +
    mcb_pmsm_foc_hall_f28069m_B.Product1_m;

  /* If: '<S26>/If' */
  if ((mcb_pmsm_foc_hall_f28069m_B.Switch1_c == 1U) ||
      (mcb_pmsm_foc_hall_f28069m_B.Switch1_c == 2U)) {
    /* Outputs for IfAction SubSystem: '<S26>/D//Q Axis Priority' incorporates:
     *  ActionPort: '<S30>/Action Port'
     */
    /* RelationalOperator: '<S35>/Compare' incorporates:
     *  Constant: '<S35>/Constant'
     */
    mcb_pmsm_foc_hall_f28069m_B.Compare_a =
      (mcb_pmsm_foc_hall_f28069m_B.Switch1_c ==
       mcb_pmsm_foc_hall_f28069m_P.CompareToConstant_const_p);

    /* RelationalOperator: '<S36>/Compare' incorporates:
     *  Constant: '<S36>/Constant'
     */
    mcb_pmsm_foc_hall_f28069m_B.Compare_k =
      (mcb_pmsm_foc_hall_f28069m_B.Switch1_c ==
       mcb_pmsm_foc_hall_f28069m_P.CompareToConstant1_const);

    /* Switch: '<S30>/Switch' */
    if (mcb_pmsm_foc_hall_f28069m_B.Compare_a) {
      /* Switch: '<S30>/Switch' */
      mcb_pmsm_foc_hall_f28069m_B.Switch_ei[0] =
        mcb_pmsm_foc_hall_f28069m_B.Saturation_c;
      mcb_pmsm_foc_hall_f28069m_B.Switch_ei[1] =
        mcb_pmsm_foc_hall_f28069m_B.Saturation_d;
    } else {
      /* Switch: '<S30>/Switch' */
      mcb_pmsm_foc_hall_f28069m_B.Switch_ei[0] =
        mcb_pmsm_foc_hall_f28069m_B.Saturation_d;
      mcb_pmsm_foc_hall_f28069m_B.Switch_ei[1] =
        mcb_pmsm_foc_hall_f28069m_B.Saturation_c;
    }

    /* End of Switch: '<S30>/Switch' */

    /* RelationalOperator: '<S40>/LowerRelop1' */
    mcb_pmsm_foc_hall_f28069m_B.LowerRelop1 =
      (mcb_pmsm_foc_hall_f28069m_B.Switch_ei[0] >
       mcb_pmsm_foc_hall_f28069m_B.Switch_k);

    /* Switch: '<S40>/Switch2' */
    if (mcb_pmsm_foc_hall_f28069m_B.LowerRelop1) {
      /* Switch: '<S40>/Switch2' */
      mcb_pmsm_foc_hall_f28069m_B.Switch2 = mcb_pmsm_foc_hall_f28069m_B.Switch_k;
    } else {
      /* Gain: '<S39>/Gain' */
      mcb_pmsm_foc_hall_f28069m_B.Gain_m =
        mcb_pmsm_foc_hall_f28069m_P.Gain_Gain_m *
        mcb_pmsm_foc_hall_f28069m_B.Switch_k;

      /* RelationalOperator: '<S40>/UpperRelop' */
      mcb_pmsm_foc_hall_f28069m_B.UpperRelop =
        (mcb_pmsm_foc_hall_f28069m_B.Switch_ei[0] <
         mcb_pmsm_foc_hall_f28069m_B.Gain_m);

      /* Switch: '<S40>/Switch' */
      if (mcb_pmsm_foc_hall_f28069m_B.UpperRelop) {
        /* Switch: '<S40>/Switch' */
        mcb_pmsm_foc_hall_f28069m_B.Switch_fb =
          mcb_pmsm_foc_hall_f28069m_B.Gain_m;
      } else {
        /* Switch: '<S40>/Switch' */
        mcb_pmsm_foc_hall_f28069m_B.Switch_fb =
          mcb_pmsm_foc_hall_f28069m_B.Switch_ei[0];
      }

      /* End of Switch: '<S40>/Switch' */

      /* Switch: '<S40>/Switch2' */
      mcb_pmsm_foc_hall_f28069m_B.Switch2 =
        mcb_pmsm_foc_hall_f28069m_B.Switch_fb;
    }

    /* End of Switch: '<S40>/Switch2' */

    /* Product: '<S39>/Product' */
    mcb_pmsm_foc_hall_f28069m_B.Product_n = mcb_pmsm_foc_hall_f28069m_B.Switch2 *
      mcb_pmsm_foc_hall_f28069m_B.Switch2;

    /* Sum: '<S39>/Sum' */
    mcb_pmsm_foc_hall_f28069m_B.Sum_e = mcb_pmsm_foc_hall_f28069m_B.Product_o -
      mcb_pmsm_foc_hall_f28069m_B.Product_n;

    /* Product: '<S39>/Product2' */
    mcb_pmsm_foc_hall_f28069m_B.Product2 =
      mcb_pmsm_foc_hall_f28069m_B.Switch_ei[1] *
      mcb_pmsm_foc_hall_f28069m_B.Switch_ei[1];

    /* RelationalOperator: '<S39>/Relational Operator' */
    mcb_pmsm_foc_hall_f28069m_B.RelationalOperator_ky =
      (mcb_pmsm_foc_hall_f28069m_B.Sum_e >= mcb_pmsm_foc_hall_f28069m_B.Product2);

    /* DataTypeConversion: '<S39>/Data Type Conversion' */
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_a =
      mcb_pmsm_foc_hall_f28069m_B.RelationalOperator_ky;

    /* If: '<S39>/If' incorporates:
     *  Switch: '<S41>/Switch1'
     */
    if (mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_a != 0U) {
      /* Outputs for IfAction SubSystem: '<S39>/passThrough' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      /* Merge: '<S39>/Merge' incorporates:
       *  SignalConversion generated from: '<S42>/ref2'
       */
      mcb_pmsm_foc_hall_f28069m_B.Merge_b4 =
        mcb_pmsm_foc_hall_f28069m_B.Switch_ei[1];

      /* End of Outputs for SubSystem: '<S39>/passThrough' */
    } else {
      /* Outputs for IfAction SubSystem: '<S39>/limitRef2' incorporates:
       *  ActionPort: '<S41>/Action Port'
       */
      if (mcb_pmsm_foc_hall_f28069m_B.Sum_e >
          mcb_pmsm_foc_hall_f28069m_P.Switch1_Threshold) {
        /* Switch: '<S41>/Switch1' */
        mcb_pmsm_foc_hall_f28069m_B.Switch1 = mcb_pmsm_foc_hall_f28069m_B.Sum_e;
      } else {
        /* Switch: '<S41>/Switch1' incorporates:
         *  Constant: '<S41>/Constant'
         */
        mcb_pmsm_foc_hall_f28069m_B.Switch1 =
          mcb_pmsm_foc_hall_f28069m_P.Constant_Value_h;
      }

      /* Sqrt: '<S41>/Sqrt' */
      mcb_pmsm_foc_hall_f28069m_B.Sqrt = (real32_T)sqrt
        (mcb_pmsm_foc_hall_f28069m_B.Switch1);

      /* Switch: '<S41>/Switch' */
      if (mcb_pmsm_foc_hall_f28069m_B.Switch_ei[1] >=
          mcb_pmsm_foc_hall_f28069m_P.Switch_Threshold) {
        /* Merge: '<S39>/Merge' */
        mcb_pmsm_foc_hall_f28069m_B.Merge_b4 = mcb_pmsm_foc_hall_f28069m_B.Sqrt;
      } else {
        /* Gain: '<S41>/Gain' */
        mcb_pmsm_foc_hall_f28069m_B.Gain_e =
          mcb_pmsm_foc_hall_f28069m_P.Gain_Gain *
          mcb_pmsm_foc_hall_f28069m_B.Sqrt;

        /* Merge: '<S39>/Merge' */
        mcb_pmsm_foc_hall_f28069m_B.Merge_b4 =
          mcb_pmsm_foc_hall_f28069m_B.Gain_e;
      }

      /* End of Switch: '<S41>/Switch' */
      /* End of Outputs for SubSystem: '<S39>/limitRef2' */
    }

    /* End of If: '<S39>/If' */

    /* Switch: '<S30>/Switch1' */
    if (mcb_pmsm_foc_hall_f28069m_B.Compare_k) {
      /* Merge: '<S26>/Merge' */
      mcb_pmsm_foc_hall_f28069m_B.Merge_o[0] =
        mcb_pmsm_foc_hall_f28069m_B.Switch2;
      mcb_pmsm_foc_hall_f28069m_B.Merge_o[1] =
        mcb_pmsm_foc_hall_f28069m_B.Merge_b4;
    } else {
      /* Merge: '<S26>/Merge' */
      mcb_pmsm_foc_hall_f28069m_B.Merge_o[0] =
        mcb_pmsm_foc_hall_f28069m_B.Merge_b4;
      mcb_pmsm_foc_hall_f28069m_B.Merge_o[1] =
        mcb_pmsm_foc_hall_f28069m_B.Switch2;
    }

    /* End of Switch: '<S30>/Switch1' */
    /* End of Outputs for SubSystem: '<S26>/D//Q Axis Priority' */
  } else {
    /* Outputs for IfAction SubSystem: '<S26>/D-Q Equivalence' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* RelationalOperator: '<S29>/Relational Operator' */
    mcb_pmsm_foc_hall_f28069m_B.RelationalOperator_n =
      (mcb_pmsm_foc_hall_f28069m_B.Sum1 > mcb_pmsm_foc_hall_f28069m_B.Product_o);

    /* DataTypeConversion: '<S29>/Data Type Conversion' */
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_lq =
      mcb_pmsm_foc_hall_f28069m_B.RelationalOperator_n;

    /* If: '<S29>/If' */
    if (mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_lq != 0U) {
      /* Outputs for IfAction SubSystem: '<S29>/Limiter' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      /* Product: '<S33>/Product' */
      mcb_pmsm_foc_hall_f28069m_B.Product_gn[0] =
        mcb_pmsm_foc_hall_f28069m_B.Saturation_c *
        mcb_pmsm_foc_hall_f28069m_B.Switch_k;
      mcb_pmsm_foc_hall_f28069m_B.Product_gn[1] =
        mcb_pmsm_foc_hall_f28069m_B.Saturation_d *
        mcb_pmsm_foc_hall_f28069m_B.Switch_k;

      /* Sqrt: '<S33>/Square Root' */
      mcb_pmsm_foc_hall_f28069m_B.SquareRoot = (real32_T)sqrt
        (mcb_pmsm_foc_hall_f28069m_B.Sum1);

      /* Switch: '<S33>/Switch' */
      if (mcb_pmsm_foc_hall_f28069m_B.SquareRoot != 0.0F) {
        /* Switch: '<S33>/Switch' */
        mcb_pmsm_foc_hall_f28069m_B.Switch_e =
          mcb_pmsm_foc_hall_f28069m_B.SquareRoot;
      } else {
        /* Switch: '<S33>/Switch' incorporates:
         *  Constant: '<S33>/Constant'
         */
        mcb_pmsm_foc_hall_f28069m_B.Switch_e =
          mcb_pmsm_foc_hall_f28069m_P.Constant_Value_d;
      }

      /* End of Switch: '<S33>/Switch' */

      /* Product: '<S33>/Reciprocal' */
      mcb_pmsm_foc_hall_f28069m_B.Reciprocal = 1.0F /
        mcb_pmsm_foc_hall_f28069m_B.Switch_e;

      /* Merge: '<S26>/Merge' incorporates:
       *  Product: '<S33>/Product1'
       */
      mcb_pmsm_foc_hall_f28069m_B.Merge_o[0] =
        mcb_pmsm_foc_hall_f28069m_B.Product_gn[0] *
        mcb_pmsm_foc_hall_f28069m_B.Reciprocal;
      mcb_pmsm_foc_hall_f28069m_B.Merge_o[1] =
        mcb_pmsm_foc_hall_f28069m_B.Product_gn[1] *
        mcb_pmsm_foc_hall_f28069m_B.Reciprocal;

      /* End of Outputs for SubSystem: '<S29>/Limiter' */
    } else {
      /* Outputs for IfAction SubSystem: '<S29>/Passthrough' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      /* Merge: '<S26>/Merge' incorporates:
       *  SignalConversion generated from: '<S34>/dqRef'
       */
      mcb_pmsm_foc_hall_f28069m_B.Merge_o[0] =
        mcb_pmsm_foc_hall_f28069m_B.Saturation_c;
      mcb_pmsm_foc_hall_f28069m_B.Merge_o[1] =
        mcb_pmsm_foc_hall_f28069m_B.Saturation_d;

      /* End of Outputs for SubSystem: '<S29>/Passthrough' */
    }

    /* End of If: '<S29>/If' */
    /* End of Outputs for SubSystem: '<S26>/D-Q Equivalence' */
  }

  /* End of If: '<S26>/If' */

  /* DeadZone: '<S70>/DeadZone' */
  if (mcb_pmsm_foc_hall_f28069m_B.Sum_ai >
      mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_e) {
    /* DeadZone: '<S70>/DeadZone' */
    mcb_pmsm_foc_hall_f28069m_B.DeadZone_k = mcb_pmsm_foc_hall_f28069m_B.Sum_ai
      - mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_e;
  } else if (mcb_pmsm_foc_hall_f28069m_B.Sum_ai >=
             mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_o) {
    /* DeadZone: '<S70>/DeadZone' */
    mcb_pmsm_foc_hall_f28069m_B.DeadZone_k = 0.0F;
  } else {
    /* DeadZone: '<S70>/DeadZone' */
    mcb_pmsm_foc_hall_f28069m_B.DeadZone_k = mcb_pmsm_foc_hall_f28069m_B.Sum_ai
      - mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_o;
  }

  /* End of DeadZone: '<S70>/DeadZone' */

  /* RelationalOperator: '<S68>/Relational Operator' incorporates:
   *  Constant: '<S68>/Clamping_zero'
   */
  mcb_pmsm_foc_hall_f28069m_B.RelationalOperator_l =
    (mcb_pmsm_foc_hall_f28069m_P.Clamping_zero_Value !=
     mcb_pmsm_foc_hall_f28069m_B.DeadZone_k);

  /* RelationalOperator: '<S68>/fix for DT propagation issue' incorporates:
   *  Constant: '<S68>/Clamping_zero'
   */
  mcb_pmsm_foc_hall_f28069m_B.fixforDTpropagationissue_i =
    (mcb_pmsm_foc_hall_f28069m_B.DeadZone_k >
     mcb_pmsm_foc_hall_f28069m_P.Clamping_zero_Value);

  /* Switch: '<S68>/Switch1' */
  if (mcb_pmsm_foc_hall_f28069m_B.fixforDTpropagationissue_i) {
    /* Switch: '<S68>/Switch1' incorporates:
     *  Constant: '<S68>/Constant'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch1_k =
      mcb_pmsm_foc_hall_f28069m_P.Constant_Value_mz;
  } else {
    /* Switch: '<S68>/Switch1' incorporates:
     *  Constant: '<S68>/Constant2'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch1_k =
      mcb_pmsm_foc_hall_f28069m_P.Constant2_Value_o;
  }

  /* End of Switch: '<S68>/Switch1' */

  /* Product: '<S74>/IProd Out' incorporates:
   *  Constant: '<S27>/Ki'
   */
  mcb_pmsm_foc_hall_f28069m_B.IProdOut_l = mcb_pmsm_foc_hall_f28069m_B.Sum_p *
    mcb_pmsm_foc_hall_f28069m_P.Ki_Value;

  /* RelationalOperator: '<S68>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S68>/Clamping_zero'
   */
  mcb_pmsm_foc_hall_f28069m_B.fixforDTpropagationissue1_n =
    (mcb_pmsm_foc_hall_f28069m_B.IProdOut_l >
     mcb_pmsm_foc_hall_f28069m_P.Clamping_zero_Value);

  /* Switch: '<S68>/Switch2' */
  if (mcb_pmsm_foc_hall_f28069m_B.fixforDTpropagationissue1_n) {
    /* Switch: '<S68>/Switch2' incorporates:
     *  Constant: '<S68>/Constant3'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch2_l =
      mcb_pmsm_foc_hall_f28069m_P.Constant3_Value_a;
  } else {
    /* Switch: '<S68>/Switch2' incorporates:
     *  Constant: '<S68>/Constant4'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch2_l =
      mcb_pmsm_foc_hall_f28069m_P.Constant4_Value;
  }

  /* End of Switch: '<S68>/Switch2' */

  /* RelationalOperator: '<S68>/Equal1' incorporates:
   *  Switch: '<S68>/Switch1'
   *  Switch: '<S68>/Switch2'
   */
  mcb_pmsm_foc_hall_f28069m_B.Equal1_g = (mcb_pmsm_foc_hall_f28069m_B.Switch1_k ==
    mcb_pmsm_foc_hall_f28069m_B.Switch2_l);

  /* Logic: '<S68>/AND3' */
  mcb_pmsm_foc_hall_f28069m_B.AND3_c =
    (mcb_pmsm_foc_hall_f28069m_B.RelationalOperator_l &&
     mcb_pmsm_foc_hall_f28069m_B.Equal1_g);

  /* Switch: '<S68>/Switch' */
  if (mcb_pmsm_foc_hall_f28069m_B.AND3_c) {
    /* Switch: '<S68>/Switch' incorporates:
     *  Constant: '<S68>/Constant1'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch_l =
      mcb_pmsm_foc_hall_f28069m_P.Constant1_Value_e;
  } else {
    /* Switch: '<S68>/Switch' */
    mcb_pmsm_foc_hall_f28069m_B.Switch_l =
      mcb_pmsm_foc_hall_f28069m_B.IProdOut_l;
  }

  /* End of Switch: '<S68>/Switch' */

  /* DeadZone: '<S121>/DeadZone' */
  if (mcb_pmsm_foc_hall_f28069m_B.Sum_n >
      mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_f) {
    /* DeadZone: '<S121>/DeadZone' */
    mcb_pmsm_foc_hall_f28069m_B.DeadZone_o = mcb_pmsm_foc_hall_f28069m_B.Sum_n -
      mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_f;
  } else if (mcb_pmsm_foc_hall_f28069m_B.Sum_n >=
             mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiwin) {
    /* DeadZone: '<S121>/DeadZone' */
    mcb_pmsm_foc_hall_f28069m_B.DeadZone_o = 0.0F;
  } else {
    /* DeadZone: '<S121>/DeadZone' */
    mcb_pmsm_foc_hall_f28069m_B.DeadZone_o = mcb_pmsm_foc_hall_f28069m_B.Sum_n -
      mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiwin;
  }

  /* End of DeadZone: '<S121>/DeadZone' */

  /* RelationalOperator: '<S119>/Relational Operator' incorporates:
   *  Constant: '<S119>/Clamping_zero'
   */
  mcb_pmsm_foc_hall_f28069m_B.RelationalOperator_k =
    (mcb_pmsm_foc_hall_f28069m_P.Clamping_zero_Value_j !=
     mcb_pmsm_foc_hall_f28069m_B.DeadZone_o);

  /* RelationalOperator: '<S119>/fix for DT propagation issue' incorporates:
   *  Constant: '<S119>/Clamping_zero'
   */
  mcb_pmsm_foc_hall_f28069m_B.fixforDTpropagationissue_p =
    (mcb_pmsm_foc_hall_f28069m_B.DeadZone_o >
     mcb_pmsm_foc_hall_f28069m_P.Clamping_zero_Value_j);

  /* Switch: '<S119>/Switch1' */
  if (mcb_pmsm_foc_hall_f28069m_B.fixforDTpropagationissue_p) {
    /* Switch: '<S119>/Switch1' incorporates:
     *  Constant: '<S119>/Constant'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch1_d =
      mcb_pmsm_foc_hall_f28069m_P.Constant_Value_ib;
  } else {
    /* Switch: '<S119>/Switch1' incorporates:
     *  Constant: '<S119>/Constant2'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch1_d =
      mcb_pmsm_foc_hall_f28069m_P.Constant2_Value_b5;
  }

  /* End of Switch: '<S119>/Switch1' */

  /* Product: '<S125>/IProd Out' incorporates:
   *  Constant: '<S28>/Ki'
   */
  mcb_pmsm_foc_hall_f28069m_B.IProdOut_b = mcb_pmsm_foc_hall_f28069m_B.Sum_i *
    mcb_pmsm_foc_hall_f28069m_P.Ki_Value_n;

  /* RelationalOperator: '<S119>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S119>/Clamping_zero'
   */
  mcb_pmsm_foc_hall_f28069m_B.fixforDTpropagationissue1_e =
    (mcb_pmsm_foc_hall_f28069m_B.IProdOut_b >
     mcb_pmsm_foc_hall_f28069m_P.Clamping_zero_Value_j);

  /* Switch: '<S119>/Switch2' */
  if (mcb_pmsm_foc_hall_f28069m_B.fixforDTpropagationissue1_e) {
    /* Switch: '<S119>/Switch2' incorporates:
     *  Constant: '<S119>/Constant3'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch2_ld =
      mcb_pmsm_foc_hall_f28069m_P.Constant3_Value_o;
  } else {
    /* Switch: '<S119>/Switch2' incorporates:
     *  Constant: '<S119>/Constant4'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch2_ld =
      mcb_pmsm_foc_hall_f28069m_P.Constant4_Value_a;
  }

  /* End of Switch: '<S119>/Switch2' */

  /* RelationalOperator: '<S119>/Equal1' incorporates:
   *  Switch: '<S119>/Switch1'
   *  Switch: '<S119>/Switch2'
   */
  mcb_pmsm_foc_hall_f28069m_B.Equal1_f = (mcb_pmsm_foc_hall_f28069m_B.Switch1_d ==
    mcb_pmsm_foc_hall_f28069m_B.Switch2_ld);

  /* Logic: '<S119>/AND3' */
  mcb_pmsm_foc_hall_f28069m_B.AND3_b =
    (mcb_pmsm_foc_hall_f28069m_B.RelationalOperator_k &&
     mcb_pmsm_foc_hall_f28069m_B.Equal1_f);

  /* Switch: '<S119>/Switch' */
  if (mcb_pmsm_foc_hall_f28069m_B.AND3_b) {
    /* Switch: '<S119>/Switch' incorporates:
     *  Constant: '<S119>/Constant1'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch_k5 =
      mcb_pmsm_foc_hall_f28069m_P.Constant1_Value_j;
  } else {
    /* Switch: '<S119>/Switch' */
    mcb_pmsm_foc_hall_f28069m_B.Switch_k5 =
      mcb_pmsm_foc_hall_f28069m_B.IProdOut_b;
  }

  /* End of Switch: '<S119>/Switch' */

  /* Outputs for Atomic SubSystem: '<S20>/Two inputs CRL' */
  /* Product: '<S145>/qcos' */
  mcb_pmsm_foc_hall_f28069m_B.qcos = mcb_pmsm_foc_hall_f28069m_B.Merge_o[1] *
    mcb_pmsm_foc_hall_f28069m_B.Sum6;

  /* Product: '<S145>/dsin' */
  mcb_pmsm_foc_hall_f28069m_B.dsin = mcb_pmsm_foc_hall_f28069m_B.Merge_o[0] *
    mcb_pmsm_foc_hall_f28069m_B.Sum4;

  /* Sum: '<S145>/sum_beta' */
  mcb_pmsm_foc_hall_f28069m_B.sum_beta = mcb_pmsm_foc_hall_f28069m_B.qcos +
    mcb_pmsm_foc_hall_f28069m_B.dsin;

  /* Product: '<S145>/dcos' */
  mcb_pmsm_foc_hall_f28069m_B.dcos = mcb_pmsm_foc_hall_f28069m_B.Merge_o[0] *
    mcb_pmsm_foc_hall_f28069m_B.Sum6;

  /* Product: '<S145>/qsin' */
  mcb_pmsm_foc_hall_f28069m_B.qsin = mcb_pmsm_foc_hall_f28069m_B.Merge_o[1] *
    mcb_pmsm_foc_hall_f28069m_B.Sum4;

  /* Sum: '<S145>/sum_alpha' */
  mcb_pmsm_foc_hall_f28069m_B.sum_alpha = mcb_pmsm_foc_hall_f28069m_B.dcos -
    mcb_pmsm_foc_hall_f28069m_B.qsin;

  /* Switch: '<S146>/Switch' incorporates:
   *  Constant: '<S146>/Offset'
   */
  if (mcb_pmsm_foc_hall_f28069m_P.Offset_Value >
      mcb_pmsm_foc_hall_f28069m_P.Switch_Threshold_f) {
    /* UnaryMinus: '<S146>/Unary_Minus' */
    mcb_pmsm_foc_hall_f28069m_B.Unary_Minus_b =
      -mcb_pmsm_foc_hall_f28069m_B.sum_alpha;

    /* Switch: '<S146>/Switch' */
    mcb_pmsm_foc_hall_f28069m_B.Switch_ka[0] =
      mcb_pmsm_foc_hall_f28069m_B.sum_beta;
    mcb_pmsm_foc_hall_f28069m_B.Switch_ka[1] =
      mcb_pmsm_foc_hall_f28069m_B.Unary_Minus_b;
  } else {
    /* Switch: '<S146>/Switch' */
    mcb_pmsm_foc_hall_f28069m_B.Switch_ka[0] =
      mcb_pmsm_foc_hall_f28069m_B.sum_alpha;
    mcb_pmsm_foc_hall_f28069m_B.Switch_ka[1] =
      mcb_pmsm_foc_hall_f28069m_B.sum_beta;
  }

  /* End of Switch: '<S146>/Switch' */

  /* AlgorithmDescriptorDelegate generated from: '<S145>/a16' */
  mcb_pmsm_foc_hall_f28069m_B.algDD_o1_m =
    mcb_pmsm_foc_hall_f28069m_B.Switch_ka[0];

  /* AlgorithmDescriptorDelegate generated from: '<S145>/a16' */
  mcb_pmsm_foc_hall_f28069m_B.algDD_o2_n =
    mcb_pmsm_foc_hall_f28069m_B.Switch_ka[1];

  /* End of Outputs for SubSystem: '<S20>/Two inputs CRL' */

  /* Sum: '<S166>/FixPt Sum1' incorporates:
   *  Constant: '<S166>/FixPt Constant'
   */
  mcb_pmsm_foc_hall_f28069m_B.FixPtSum1 = mcb_pmsm_foc_hall_f28069m_B.Output +
    mcb_pmsm_foc_hall_f28069m_P.FixPtConstant_Value;

  /* Switch: '<S167>/FixPt Switch' */
  if (mcb_pmsm_foc_hall_f28069m_B.FixPtSum1 >
      mcb_pmsm_foc_hall_f28069m_P.CounterLimited_uplimit) {
    /* Switch: '<S167>/FixPt Switch' incorporates:
     *  Constant: '<S167>/Constant'
     */
    mcb_pmsm_foc_hall_f28069m_B.FixPtSwitch =
      mcb_pmsm_foc_hall_f28069m_P.Constant_Value_f;
  } else {
    /* Switch: '<S167>/FixPt Switch' */
    mcb_pmsm_foc_hall_f28069m_B.FixPtSwitch =
      mcb_pmsm_foc_hall_f28069m_B.FixPtSum1;
  }

  /* End of Switch: '<S167>/FixPt Switch' */

  /* DataStoreRead: '<S15>/Enable' */
  mcb_pmsm_foc_hall_f28069m_B.PWM_En = mcb_pmsm_foc_hall_f28069m_DWork.Enable;

  /* DataTypeConversion: '<S15>/Data Type Conversion' */
  mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_p =
    mcb_pmsm_foc_hall_f28069m_B.PWM_En;

  /* SignalConversion generated from: '<S225>/Digital Output2' */
  mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalO_d[0] =
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_p;
  mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalO_d[1] =
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_p;
  mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalO_d[2] =
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_p;

  /* S-Function (c280xgpio_do): '<S225>/Digital Output2' */
  {
    if (mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalO_d[0]) {
      GpioDataRegs.GPASET.bit.GPIO1 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO1 = 1U;
    }

    if (mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalO_d[1]) {
      GpioDataRegs.GPASET.bit.GPIO3 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO3 = 1U;
    }

    if (mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalO_d[2]) {
      GpioDataRegs.GPASET.bit.GPIO5 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO5 = 1U;
    }
  }

  /* Switch: '<S225>/Switch1' */
  if (mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_p >=
      mcb_pmsm_foc_hall_f28069m_P.Switch1_Threshold_i) {
    /* Gain: '<S160>/sqrt3_by_two' */
    mcb_pmsm_foc_hall_f28069m_B.sqrt3_by_two =
      mcb_pmsm_foc_hall_f28069m_P.sqrt3_by_two_Gain *
      mcb_pmsm_foc_hall_f28069m_B.algDD_o2_n;

    /* Gain: '<S160>/one_by_two' */
    mcb_pmsm_foc_hall_f28069m_B.one_by_two =
      mcb_pmsm_foc_hall_f28069m_P.one_by_two_Gain *
      mcb_pmsm_foc_hall_f28069m_B.algDD_o1_m;

    /* Sum: '<S160>/add_c' */
    mcb_pmsm_foc_hall_f28069m_B.add_c = (0.0F -
      mcb_pmsm_foc_hall_f28069m_B.one_by_two) -
      mcb_pmsm_foc_hall_f28069m_B.sqrt3_by_two;

    /* Gain: '<S160>/Kc' */
    mcb_pmsm_foc_hall_f28069m_B.Kc = mcb_pmsm_foc_hall_f28069m_P.Kc_Gain *
      mcb_pmsm_foc_hall_f28069m_B.add_c;

    /* Gain: '<S160>/Ka' */
    mcb_pmsm_foc_hall_f28069m_B.Ka = mcb_pmsm_foc_hall_f28069m_P.Ka_Gain *
      mcb_pmsm_foc_hall_f28069m_B.algDD_o1_m;

    /* Sum: '<S160>/add_b' */
    mcb_pmsm_foc_hall_f28069m_B.add_b = mcb_pmsm_foc_hall_f28069m_B.sqrt3_by_two
      - mcb_pmsm_foc_hall_f28069m_B.one_by_two;

    /* Gain: '<S160>/Kb' */
    mcb_pmsm_foc_hall_f28069m_B.Kb = mcb_pmsm_foc_hall_f28069m_P.Kb_Gain *
      mcb_pmsm_foc_hall_f28069m_B.add_b;

    /* MinMax: '<S157>/Min' */
    u0_0 = mcb_pmsm_foc_hall_f28069m_B.Ka;
    Bias = mcb_pmsm_foc_hall_f28069m_B.Kb;
    if ((u0_0 <= Bias) || rtIsNaNF(Bias)) {
      Bias = u0_0;
    }

    u1_0 = mcb_pmsm_foc_hall_f28069m_B.Kc;
    if ((!(Bias <= u1_0)) && (!rtIsNaNF(u1_0))) {
      Bias = u1_0;
    }

    /* MinMax: '<S157>/Min' */
    mcb_pmsm_foc_hall_f28069m_B.Min_o = Bias;

    /* MinMax: '<S157>/Max' */
    u0_0 = mcb_pmsm_foc_hall_f28069m_B.Ka;
    Bias = mcb_pmsm_foc_hall_f28069m_B.Kb;
    if ((u0_0 >= Bias) || rtIsNaNF(Bias)) {
      Bias = u0_0;
    }

    u1_0 = mcb_pmsm_foc_hall_f28069m_B.Kc;
    if ((!(Bias >= u1_0)) && (!rtIsNaNF(u1_0))) {
      Bias = u1_0;
    }

    /* MinMax: '<S157>/Max' */
    mcb_pmsm_foc_hall_f28069m_B.Max_g = Bias;

    /* Sum: '<S157>/Add' */
    mcb_pmsm_foc_hall_f28069m_B.Add_h = mcb_pmsm_foc_hall_f28069m_B.Max_g +
      mcb_pmsm_foc_hall_f28069m_B.Min_o;

    /* Gain: '<S157>/one_by_two' */
    mcb_pmsm_foc_hall_f28069m_B.one_by_two_f =
      mcb_pmsm_foc_hall_f28069m_P.one_by_two_Gain_k *
      mcb_pmsm_foc_hall_f28069m_B.Add_h;

    /* Sum: '<S156>/Add3' */
    mcb_pmsm_foc_hall_f28069m_B.Add3 = mcb_pmsm_foc_hall_f28069m_B.Ka +
      mcb_pmsm_foc_hall_f28069m_B.one_by_two_f;

    /* Sum: '<S156>/Add2' */
    mcb_pmsm_foc_hall_f28069m_B.Add2 = mcb_pmsm_foc_hall_f28069m_B.one_by_two_f
      + mcb_pmsm_foc_hall_f28069m_B.Kc;

    /* Sum: '<S156>/Add1' */
    mcb_pmsm_foc_hall_f28069m_B.Add1_n = mcb_pmsm_foc_hall_f28069m_B.Kb +
      mcb_pmsm_foc_hall_f28069m_B.one_by_two_f;

    /* Gain: '<S156>/Gain' */
    mcb_pmsm_foc_hall_f28069m_B.Gain[0] =
      mcb_pmsm_foc_hall_f28069m_P.Gain_Gain_h * mcb_pmsm_foc_hall_f28069m_B.Add3;
    mcb_pmsm_foc_hall_f28069m_B.Gain[1] =
      mcb_pmsm_foc_hall_f28069m_P.Gain_Gain_h *
      mcb_pmsm_foc_hall_f28069m_B.Add1_n;
    mcb_pmsm_foc_hall_f28069m_B.Gain[2] =
      mcb_pmsm_foc_hall_f28069m_P.Gain_Gain_h * mcb_pmsm_foc_hall_f28069m_B.Add2;

    /* Gain: '<S15>/One_by_Two' */
    u0_0 = mcb_pmsm_foc_hall_f28069m_P.One_by_Two_Gain *
      mcb_pmsm_foc_hall_f28069m_B.Gain[0];
    mcb_pmsm_foc_hall_f28069m_B.One_by_Two[0] = u0_0;

    /* Sum: '<S15>/Sum' incorporates:
     *  Constant: '<S15>/Constant'
     */
    u0_0 += mcb_pmsm_foc_hall_f28069m_P.Constant_Value_gi;
    mcb_pmsm_foc_hall_f28069m_B.PWM_Duty_Cycles[0] = u0_0;

    /* Gain: '<S225>/Scale_to_PWM_Counter_PRD' */
    Data = (uint16_T)(mcb_pmsm_foc_hall_f28069m_P.Scale_to_PWM_Counter_PRD_Gain *
                      u0_0);
    mcb_pmsm_foc_hall_f28069m_B.Scale_to_PWM_Counter_PRD[0] = Data;

    /* Switch: '<S225>/Switch1' */
    mcb_pmsm_foc_hall_f28069m_B.Switch1_ce[0] = Data;

    /* Gain: '<S15>/One_by_Two' */
    u0_0 = mcb_pmsm_foc_hall_f28069m_P.One_by_Two_Gain *
      mcb_pmsm_foc_hall_f28069m_B.Gain[1];
    mcb_pmsm_foc_hall_f28069m_B.One_by_Two[1] = u0_0;

    /* Sum: '<S15>/Sum' incorporates:
     *  Constant: '<S15>/Constant'
     */
    u0_0 += mcb_pmsm_foc_hall_f28069m_P.Constant_Value_gi;
    mcb_pmsm_foc_hall_f28069m_B.PWM_Duty_Cycles[1] = u0_0;

    /* Gain: '<S225>/Scale_to_PWM_Counter_PRD' */
    Data = (uint16_T)(mcb_pmsm_foc_hall_f28069m_P.Scale_to_PWM_Counter_PRD_Gain *
                      u0_0);
    mcb_pmsm_foc_hall_f28069m_B.Scale_to_PWM_Counter_PRD[1] = Data;

    /* Switch: '<S225>/Switch1' */
    mcb_pmsm_foc_hall_f28069m_B.Switch1_ce[1] = Data;

    /* Gain: '<S15>/One_by_Two' */
    u0_0 = mcb_pmsm_foc_hall_f28069m_P.One_by_Two_Gain *
      mcb_pmsm_foc_hall_f28069m_B.Gain[2];
    mcb_pmsm_foc_hall_f28069m_B.One_by_Two[2] = u0_0;

    /* Sum: '<S15>/Sum' incorporates:
     *  Constant: '<S15>/Constant'
     */
    u0_0 += mcb_pmsm_foc_hall_f28069m_P.Constant_Value_gi;
    mcb_pmsm_foc_hall_f28069m_B.PWM_Duty_Cycles[2] = u0_0;

    /* Gain: '<S225>/Scale_to_PWM_Counter_PRD' */
    Data = (uint16_T)(mcb_pmsm_foc_hall_f28069m_P.Scale_to_PWM_Counter_PRD_Gain *
                      u0_0);
    mcb_pmsm_foc_hall_f28069m_B.Scale_to_PWM_Counter_PRD[2] = Data;

    /* Switch: '<S225>/Switch1' */
    mcb_pmsm_foc_hall_f28069m_B.Switch1_ce[2] = Data;
  } else {
    /* Switch: '<S225>/Switch1' incorporates:
     *  Constant: '<S225>/stop'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch1_ce[0] =
      mcb_pmsm_foc_hall_f28069m_P.stop_Value;
    mcb_pmsm_foc_hall_f28069m_B.Switch1_ce[1] =
      mcb_pmsm_foc_hall_f28069m_P.stop_Value;
    mcb_pmsm_foc_hall_f28069m_B.Switch1_ce[2] =
      mcb_pmsm_foc_hall_f28069m_P.stop_Value;
  }

  /* End of Switch: '<S225>/Switch1' */

  /* S-Function (c2802xpwm): '<S225>/ePWM1' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(mcb_pmsm_foc_hall_f28069m_B.Switch1_ce
      [0]);
  }

  /* S-Function (c2802xpwm): '<S225>/ePWM2' */

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)(mcb_pmsm_foc_hall_f28069m_B.Switch1_ce
      [1]);
  }

  /* S-Function (c2802xpwm): '<S225>/ePWM3' */

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.bit.CMPA = (uint16_T)(mcb_pmsm_foc_hall_f28069m_B.Switch1_ce
      [2]);
  }

  /* SignalConversion generated from: '<S1>/Speed_fb' */
  mcb_pmsm_foc_hall_f28069m_B.Speed_PU = mcb_pmsm_foc_hall_f28069m_B.Merge_m;

  /* Update for Delay: '<S182>/validityDelay' incorporates:
   *  Delay: '<S182>/speedCountDelay'
   */
  if (mcb_pmsm_foc_hall_f28069m_B.Switch_i != 0U) {
    mcb_pmsm_foc_hall_f28069m_DWork.validityDelay_DSTATE =
      mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_lx;
    mcb_pmsm_foc_hall_f28069m_DWork.speedCountDelay_DSTATE =
      mcb_pmsm_foc_hall_f28069m_B.Input;
  }

  /* End of Update for Delay: '<S182>/validityDelay' */

  /* Update for Delay: '<S183>/Delay One Step1' */
  mcb_pmsm_foc_hall_f28069m_DWork.DelayOneStep1_DSTATE =
    mcb_pmsm_foc_hall_f28069m_B.Compare_j;

  /* Update for Delay: '<S183>/Delay One Step' */
  if (mcb_pmsm_foc_hall_f28069m_B.OR) {
    mcb_pmsm_foc_hall_f28069m_DWork.DelayOneStep_DSTATE =
      mcb_pmsm_foc_hall_f28069m_B.Sum_at;
  }

  /* End of Update for Delay: '<S183>/Delay One Step' */

  /* Update for UnitDelay: '<S161>/Output' */
  mcb_pmsm_foc_hall_f28069m_DWork.Output_DSTATE =
    mcb_pmsm_foc_hall_f28069m_B.FixPtSwitch;

  /* Update for DiscreteIntegrator: '<S128>/Integrator' */
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE_k +=
    mcb_pmsm_foc_hall_f28069m_P.Integrator_gainval *
    mcb_pmsm_foc_hall_f28069m_B.Switch_k5;
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_PrevResetState_o = (int16_T)
    mcb_pmsm_foc_hall_f28069m_B.LogicalOperator_c;

  /* Update for DiscreteIntegrator: '<S77>/Integrator' */
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE_g +=
    mcb_pmsm_foc_hall_f28069m_P.Integrator_gainval_i *
    mcb_pmsm_foc_hall_f28069m_B.Switch_l;
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_PrevResetState_j = (int16_T)
    mcb_pmsm_foc_hall_f28069m_B.LogicalOperator_n;
}

/* Termination for function-call system: '<Root>/Current Control' */
void mcb_pms_CurrentControl_Term(void)
{
}

/*
 * Output and update for action system:
 *    '<S245>/Output 1'
 *    '<S245>/Output 0'
 *    '<S266>/Output 1'
 *    '<S266>/Output 0'
 *    '<S287>/Output 1'
 *    '<S287>/Output 0'
 */
void mcb_pmsm_foc_hall_f_Output1(boolean_T *rty_Out1,
  rtP_Output1_mcb_pmsm_foc_hall_f *localP)
{
  /* SignalConversion generated from: '<S250>/Out1' incorporates:
   *  Constant: '<S250>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S253>/If Action Subsystem6'
 *    '<S253>/If Action Subsystem7'
 *    '<S274>/If Action Subsystem6'
 *    '<S274>/If Action Subsystem7'
 *    '<S295>/If Action Subsystem6'
 *    '<S295>/If Action Subsystem7'
 */
void mcb_pmsm_IfActionSubsystem6(int16_T *rty_direction, uint16_T
  *rty_sequence_check, rtP_IfActionSubsystem6_mcb_pmsm *localP)
{
  /* SignalConversion generated from: '<S260>/direction' incorporates:
   *  Constant: '<S260>/Constant'
   */
  *rty_direction = localP->Constant_Value;

  /* SignalConversion generated from: '<S260>/sequence_check' incorporates:
   *  Constant: '<S260>/Constant1'
   */
  *rty_sequence_check = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S253>/If Action Subsystem'
 *    '<S253>/If Action Subsystem1'
 *    '<S253>/If Action Subsystem2'
 *    '<S253>/If Action Subsystem3'
 *    '<S253>/If Action Subsystem4'
 *    '<S253>/If Action Subsystem5'
 *    '<S274>/If Action Subsystem'
 *    '<S274>/If Action Subsystem1'
 *    '<S274>/If Action Subsystem2'
 *    '<S274>/If Action Subsystem3'
 *    ...
 */
void mcb_pmsm__IfActionSubsystem(uint16_T *rty_Out1, uint16_T *rty_Out2,
  rtP_IfActionSubsystem_mcb_pmsm_ *localP)
{
  /* SignalConversion generated from: '<S254>/Out1' incorporates:
   *  Constant: '<S254>/previous'
   */
  *rty_Out1 = localP->previous_Value;

  /* SignalConversion generated from: '<S254>/Out2' incorporates:
   *  Constant: '<S254>/next'
   */
  *rty_Out2 = localP->next_Value;
}

/*
 * System initialize for action system:
 *    '<S251>/Valid Halls'
 *    '<S272>/Valid Halls'
 *    '<S293>/Valid Halls'
 */
void mcb_pmsm_fo_ValidHalls_Init(rtB_ValidHalls_mcb_pmsm_foc_hal *localB,
  rtP_ValidHalls_mcb_pmsm_foc_hal *localP)
{
  /* SystemInitialize for Merge: '<S253>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S253>/Merge1' */
  localB->Merge1 = localP->Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S253>/Merge2' */
  localB->Merge2 = localP->Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S253>/Merge3' */
  localB->Merge3 = localP->Merge3_InitialOutput;
}

/*
 * Output and update for action system:
 *    '<S251>/Valid Halls'
 *    '<S272>/Valid Halls'
 *    '<S293>/Valid Halls'
 */
void mcb_pmsm_foc_hal_ValidHalls(uint16_T rtu_hallReading, uint16_T
  rtu_previousState, int16_T rtu_previous_direction, boolean_T
  *rty_directional_speed_valid_fla, int16_T *rty_direction, uint16_T
  *rty_inValidHall, rtB_ValidHalls_mcb_pmsm_foc_hal *localB,
  rtP_ValidHalls_mcb_pmsm_foc_hal *localP)
{
  /* SwitchCase: '<S253>/Switch Case' */
  switch ((int32_T)rtu_hallReading) {
   case 5L:
    /* Outputs for IfAction SubSystem: '<S253>/If Action Subsystem' incorporates:
     *  ActionPort: '<S254>/Action Port'
     */
    mcb_pmsm__IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S253>/If Action Subsystem' */
    break;

   case 4L:
    /* Outputs for IfAction SubSystem: '<S253>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S255>/Action Port'
     */
    mcb_pmsm__IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S253>/If Action Subsystem1' */
    break;

   case 6L:
    /* Outputs for IfAction SubSystem: '<S253>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S256>/Action Port'
     */
    mcb_pmsm__IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S253>/If Action Subsystem2' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<S253>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S257>/Action Port'
     */
    mcb_pmsm__IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S253>/If Action Subsystem3' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S253>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S258>/Action Port'
     */
    mcb_pmsm__IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S253>/If Action Subsystem4' */
    break;

   case 1L:
    /* Outputs for IfAction SubSystem: '<S253>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S259>/Action Port'
     */
    mcb_pmsm__IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S253>/If Action Subsystem5' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S253>/Switch Case' */

  /* If: '<S253>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S253>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S260>/Action Port'
     */
    mcb_pmsm_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S253>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S253>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S261>/Action Port'
     */
    mcb_pmsm_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S253>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S253>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S262>/Action Port'
     */
    /* Merge: '<S253>/Merge3' incorporates:
     *  Constant: '<S262>/Constant'
     *  SignalConversion generated from: '<S262>/sequence_check'
     */
    localB->Merge3 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S253>/If Action Subsystem8' */
  }

  /* End of If: '<S253>/If' */

  /* SignalConversion: '<S253>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S253>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S253>/Switch' incorporates:
   *  Constant: '<S253>/Constant'
   */
  if (localB->Merge3 != 0U) {
    *rty_directional_speed_valid_fla = localP->Constant_Value_h;
  } else {
    /* RelationalOperator: '<S253>/Relational Operator' */
    localB->RelationalOperator = (localB->Merge2 == rtu_previous_direction);
    *rty_directional_speed_valid_fla = localB->RelationalOperator;
  }

  /* End of Switch: '<S253>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S251>/Bad hall (glitch or wrong connection)'
 *    '<S272>/Bad hall (glitch or wrong connection)'
 *    '<S293>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnect(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla, rtP_Badhallglitchorwrongconnect *localP)
{
  /* SignalConversion generated from: '<S252>/inValidHall' incorporates:
   *  Constant: '<S252>/Constant'
   */
  *rty_inValidHall = localP->Constant_Value;

  /* SignalConversion: '<S252>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S252>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S252>/Constant1'
   */
  *rty_directional_speed_valid_fla = localP->Constant1_Value;
}

/* Model step function for TID0 */
void mcb_pmsm_foc_hall_f28069m_step0(void) /* Sample time: [0.0005s, 0.0s] */
{
  real32_T u0;
  real32_T u1;
  real32_T u2;

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/RT' */
  mcb_pmsm_foc_hall_f28069m_B.RT_c =
    mcb_pmsm_foc_hall_f28069m_DWork.RT_Buffer[mcb_pmsm_foc_hall_f28069m_DWork.RT_ActiveBufIdx];

  /* RateTransition: '<Root>/RT1' */
  mcb_pmsm_foc_hall_f28069m_DWork.RT1_semaphoreTaken =
    mcb_pmsm_foc_hall_f28069m_DWork.RT1_ActiveBufIdx;

  /* RateTransition: '<Root>/RT1' */
  mcb_pmsm_foc_hall_f28069m_B.RT1 =
    mcb_pmsm_foc_hall_f28069m_DWork.RT1_Buffer[mcb_pmsm_foc_hall_f28069m_DWork.RT1_semaphoreTaken];

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  /* DataStoreRead: '<S325>/Data Store Read1' */
  mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_ls =
    mcb_pmsm_foc_hall_f28069m_DWork.Enable;

  /* DataStoreRead: '<S326>/Data Store Read1' */
  mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_ll =
    mcb_pmsm_foc_hall_f28069m_DWork.Enable;

  /* Switch: '<S326>/Switch' */
  if (mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_ll) {
    /* Switch: '<S326>/Switch' */
    mcb_pmsm_foc_hall_f28069m_B.Switch_a = mcb_pmsm_foc_hall_f28069m_B.RT_c;
  } else {
    /* Switch: '<S326>/Switch' */
    mcb_pmsm_foc_hall_f28069m_B.Switch_a = mcb_pmsm_foc_hall_f28069m_B.RT1;
  }

  /* End of Switch: '<S326>/Switch' */

  /* Product: '<S381>/Product' incorporates:
   *  Constant: '<S381>/Filter_Constant'
   */
  mcb_pmsm_foc_hall_f28069m_B.Product = mcb_pmsm_foc_hall_f28069m_B.Switch_a *
    mcb_pmsm_foc_hall_f28069m_P.Filter_Constant_Value;

  /* UnitDelay: '<S381>/Unit Delay' */
  mcb_pmsm_foc_hall_f28069m_B.UnitDelay_k =
    mcb_pmsm_foc_hall_f28069m_DWork.UnitDelay_DSTATE;

  /* Product: '<S381>/Product1' incorporates:
   *  Constant: '<S381>/One'
   */
  mcb_pmsm_foc_hall_f28069m_B.Product1 = mcb_pmsm_foc_hall_f28069m_P.One_Value *
    mcb_pmsm_foc_hall_f28069m_B.UnitDelay_k;

  /* Sum: '<S381>/Add1' */
  mcb_pmsm_foc_hall_f28069m_B.Add1 = mcb_pmsm_foc_hall_f28069m_B.Product +
    mcb_pmsm_foc_hall_f28069m_B.Product1;

  /* Sum: '<S325>/Sum' */
  mcb_pmsm_foc_hall_f28069m_B.Sum_a = mcb_pmsm_foc_hall_f28069m_B.Add1 -
    mcb_pmsm_foc_hall_f28069m_B.RT1;

  /* Constant: '<S325>/Kp1' */
  mcb_pmsm_foc_hall_f28069m_B.Kp1 = mcb_pmsm_foc_hall_f28069m_P.Kp1_Value_e;

  /* Product: '<S366>/PProd Out' */
  mcb_pmsm_foc_hall_f28069m_B.PProdOut = mcb_pmsm_foc_hall_f28069m_B.Sum_a *
    mcb_pmsm_foc_hall_f28069m_B.Kp1;

  /* Logic: '<S325>/Logical Operator' */
  mcb_pmsm_foc_hall_f28069m_B.LogicalOperator =
    !mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_ls;

  /* Constant: '<S325>/Ki2' */
  mcb_pmsm_foc_hall_f28069m_B.Ki2 = mcb_pmsm_foc_hall_f28069m_P.Ki2_Value;

  /* DiscreteIntegrator: '<S361>/Integrator' */
  if (mcb_pmsm_foc_hall_f28069m_B.LogicalOperator ||
      (mcb_pmsm_foc_hall_f28069m_DWork.Integrator_PrevResetState != 0)) {
    mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE =
      mcb_pmsm_foc_hall_f28069m_B.Ki2;
  }

  /* DiscreteIntegrator: '<S361>/Integrator' */
  mcb_pmsm_foc_hall_f28069m_B.Integrator =
    mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE;

  /* Sum: '<S370>/Sum' */
  mcb_pmsm_foc_hall_f28069m_B.Sum_g = mcb_pmsm_foc_hall_f28069m_B.PProdOut +
    mcb_pmsm_foc_hall_f28069m_B.Integrator;

  /* DeadZone: '<S354>/DeadZone' */
  if (mcb_pmsm_foc_hall_f28069m_B.Sum_g >
      mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_h) {
    /* DeadZone: '<S354>/DeadZone' */
    mcb_pmsm_foc_hall_f28069m_B.DeadZone = mcb_pmsm_foc_hall_f28069m_B.Sum_g -
      mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_h;
  } else if (mcb_pmsm_foc_hall_f28069m_B.Sum_g >=
             mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_d) {
    /* DeadZone: '<S354>/DeadZone' */
    mcb_pmsm_foc_hall_f28069m_B.DeadZone = 0.0F;
  } else {
    /* DeadZone: '<S354>/DeadZone' */
    mcb_pmsm_foc_hall_f28069m_B.DeadZone = mcb_pmsm_foc_hall_f28069m_B.Sum_g -
      mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_d;
  }

  /* End of DeadZone: '<S354>/DeadZone' */

  /* RelationalOperator: '<S352>/Relational Operator' incorporates:
   *  Constant: '<S352>/Clamping_zero'
   */
  mcb_pmsm_foc_hall_f28069m_B.RelationalOperator =
    (mcb_pmsm_foc_hall_f28069m_P.Clamping_zero_Value_i !=
     mcb_pmsm_foc_hall_f28069m_B.DeadZone);

  /* RelationalOperator: '<S352>/fix for DT propagation issue' incorporates:
   *  Constant: '<S352>/Clamping_zero'
   */
  mcb_pmsm_foc_hall_f28069m_B.fixforDTpropagationissue =
    (mcb_pmsm_foc_hall_f28069m_B.DeadZone >
     mcb_pmsm_foc_hall_f28069m_P.Clamping_zero_Value_i);

  /* Switch: '<S352>/Switch1' */
  if (mcb_pmsm_foc_hall_f28069m_B.fixforDTpropagationissue) {
    /* Switch: '<S352>/Switch1' incorporates:
     *  Constant: '<S352>/Constant'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch1_b =
      mcb_pmsm_foc_hall_f28069m_P.Constant_Value_j1;
  } else {
    /* Switch: '<S352>/Switch1' incorporates:
     *  Constant: '<S352>/Constant2'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch1_b =
      mcb_pmsm_foc_hall_f28069m_P.Constant2_Value_n;
  }

  /* End of Switch: '<S352>/Switch1' */

  /* Product: '<S358>/IProd Out' incorporates:
   *  Constant: '<S325>/Ki1'
   */
  mcb_pmsm_foc_hall_f28069m_B.IProdOut = mcb_pmsm_foc_hall_f28069m_B.Sum_a *
    mcb_pmsm_foc_hall_f28069m_P.Ki1_Value_k;

  /* RelationalOperator: '<S352>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S352>/Clamping_zero'
   */
  mcb_pmsm_foc_hall_f28069m_B.fixforDTpropagationissue1 =
    (mcb_pmsm_foc_hall_f28069m_B.IProdOut >
     mcb_pmsm_foc_hall_f28069m_P.Clamping_zero_Value_i);

  /* Switch: '<S352>/Switch2' */
  if (mcb_pmsm_foc_hall_f28069m_B.fixforDTpropagationissue1) {
    /* Switch: '<S352>/Switch2' incorporates:
     *  Constant: '<S352>/Constant3'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch2_f =
      mcb_pmsm_foc_hall_f28069m_P.Constant3_Value_i;
  } else {
    /* Switch: '<S352>/Switch2' incorporates:
     *  Constant: '<S352>/Constant4'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch2_f =
      mcb_pmsm_foc_hall_f28069m_P.Constant4_Value_k;
  }

  /* End of Switch: '<S352>/Switch2' */

  /* RelationalOperator: '<S352>/Equal1' incorporates:
   *  Switch: '<S352>/Switch1'
   *  Switch: '<S352>/Switch2'
   */
  mcb_pmsm_foc_hall_f28069m_B.Equal1 = (mcb_pmsm_foc_hall_f28069m_B.Switch1_b ==
    mcb_pmsm_foc_hall_f28069m_B.Switch2_f);

  /* Logic: '<S352>/AND3' */
  mcb_pmsm_foc_hall_f28069m_B.AND3 =
    (mcb_pmsm_foc_hall_f28069m_B.RelationalOperator &&
     mcb_pmsm_foc_hall_f28069m_B.Equal1);

  /* Switch: '<S352>/Switch' */
  if (mcb_pmsm_foc_hall_f28069m_B.AND3) {
    /* Switch: '<S352>/Switch' incorporates:
     *  Constant: '<S352>/Constant1'
     */
    mcb_pmsm_foc_hall_f28069m_B.Switch_f =
      mcb_pmsm_foc_hall_f28069m_P.Constant1_Value_f;
  } else {
    /* Switch: '<S352>/Switch' */
    mcb_pmsm_foc_hall_f28069m_B.Switch_f = mcb_pmsm_foc_hall_f28069m_B.IProdOut;
  }

  /* End of Switch: '<S352>/Switch' */

  /* Saturate: '<S368>/Saturation' */
  u0 = mcb_pmsm_foc_hall_f28069m_B.Sum_g;
  u1 = mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_d;
  u2 = mcb_pmsm_foc_hall_f28069m_P.DiscretePIControllerwithantiw_h;
  if (u0 > u2) {
    /* Saturate: '<S368>/Saturation' */
    mcb_pmsm_foc_hall_f28069m_B.Saturation = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S368>/Saturation' */
    mcb_pmsm_foc_hall_f28069m_B.Saturation = u1;
  } else {
    /* Saturate: '<S368>/Saturation' */
    mcb_pmsm_foc_hall_f28069m_B.Saturation = u0;
  }

  /* End of Saturate: '<S368>/Saturation' */

  /* Update for UnitDelay: '<S381>/Unit Delay' */
  mcb_pmsm_foc_hall_f28069m_DWork.UnitDelay_DSTATE =
    mcb_pmsm_foc_hall_f28069m_B.Add1;

  /* Update for DiscreteIntegrator: '<S361>/Integrator' */
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE +=
    mcb_pmsm_foc_hall_f28069m_P.Integrator_gainval_p *
    mcb_pmsm_foc_hall_f28069m_B.Switch_f;
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_PrevResetState = (int16_T)
    mcb_pmsm_foc_hall_f28069m_B.LogicalOperator;

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */

  /* Update for RateTransition: '<Root>/RT6' incorporates:
   *  Constant: '<S10>/Id_ref'
   */
  mcb_pmsm_foc_hall_f28069m_DWork.RT6_Buffer
    [(mcb_pmsm_foc_hall_f28069m_DWork.RT6_ActiveBufIdx == 0) << 1U] =
    mcb_pmsm_foc_hall_f28069m_P.Id_ref_Value;
  mcb_pmsm_foc_hall_f28069m_DWork.RT6_Buffer[1 +
    ((mcb_pmsm_foc_hall_f28069m_DWork.RT6_ActiveBufIdx == 0) << 1U)] =
    mcb_pmsm_foc_hall_f28069m_B.Saturation;
  mcb_pmsm_foc_hall_f28069m_DWork.RT6_ActiveBufIdx =
    (mcb_pmsm_foc_hall_f28069m_DWork.RT6_ActiveBufIdx == 0);
}

/* Model step function for TID1 */
void mcb_pmsm_foc_hall_f28069m_step1(void) /* Sample time: [0.5s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S320>/Digital Output1' incorporates:
   *  Constant: '<S7>/RED_LED'
   */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = (uint16_T)
      (mcb_pmsm_foc_hall_f28069m_P.RED_LED_Value != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_foc_hall_f28069m_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mcb_pmsm_foc_hall_f28069m_M, 0,
                sizeof(RT_MODEL_mcb_pmsm_foc_hall_f280));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_foc_hall_f28069m_B), 0,
                sizeof(BlockIO_mcb_pmsm_foc_hall_f2806));

  {
    mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalOut[0] = 0.0;
    mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalOut[1] = 0.0;
    mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalOut[2] = 0.0;
    mcb_pmsm_foc_hall_f28069m_B.RT6[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.RT6[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.RT_c = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.RT1 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_a = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Product = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.UnitDelay_k = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Product1 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Add1 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum_a = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Kp1 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.PProdOut = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Ki2 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Integrator = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum_g = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.DeadZone = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.IProdOut = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_f = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Saturation = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_l = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Merge_m = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Merge1 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.PositionUnit = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_pz = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Merge_p = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Numberofpolepairs = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Multiply = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Floor = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Multiply1 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Add = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_m[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_m[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Kalpha = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Kbeta = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.convert_pu = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Merge_n = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.indexing = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Lookup[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Lookup[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Lookup[2] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Lookup[3] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum3 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_b = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum2 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Product_l = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum4 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum5 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Product1_a = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum6 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum_i = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Kp = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.PProdOut_d = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Kp1_c = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Integrator_h = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum_n = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Saturation_d = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum_p = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Kp_i = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.PProdOut_p = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Ki1 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Integrator_n = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum_ai = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Saturation_c = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_k = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Product_o = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Product_g = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Product1_m = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum1 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Merge_o[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Merge_o[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.DeadZone_k = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.IProdOut_l = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_l = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.DeadZone_o = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.IProdOut_b = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_k5 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_p = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalO_d[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalO_d[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalO_d[2] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Speed_PU = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.sqrt3_by_two = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.one_by_two = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.add_c = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Kc = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Ka = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.add_b = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Kb = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Min_o = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Max_g = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Add_h = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.one_by_two_f = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Add3 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Add2 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Add1_n = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Gain[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Gain[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Gain[2] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.One_by_Two[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.One_by_Two[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.One_by_Two[2] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.PWM_Duty_Cycles[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.PWM_Duty_Cycles[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.PWM_Duty_Cycles[2] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.SpeedConstData = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.currentSpeedData = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Divide = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.SpeedGain = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Merge1_m = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Saturation_f = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Merge_b = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.countData = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.currentSpeedData_n = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Divide_e = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.countData_h = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.previousSpeedData = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Divide_k = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.currentSpeedData_a = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Divide1 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum_ar = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Gain1 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum1_m = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Product_b = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Merge1_d = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Merge1_dn = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Convert_back = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Convert_back_e = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.bcos = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.asin_h = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.sum_Qs = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.acos_c = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.bsin = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.sum_Ds = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_kn[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_kn[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.algDD_o1 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.algDD_o2 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Unary_Minus = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.qcos = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.dsin = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.sum_beta = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.dcos = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.qsin = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.sum_alpha = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_ka[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_ka[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.algDD_o1_m = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.algDD_o2_n = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Unary_Minus_b = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Product_gn[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Product_gn[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.SquareRoot = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_e = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Reciprocal = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_ei[0] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_ei[1] = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch2 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Product_n = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sum_e = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Product2 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Merge_b4 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Gain_m = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch_fb = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Switch1 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Sqrt = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.Gain_e = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.a_plus_2b = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.one_by_sqrt3 = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.algDD_o1_b = 0.0F;
    mcb_pmsm_foc_hall_f28069m_B.algDD_o2_a = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_foc_hall_f28069m_DWork, 0,
                sizeof(D_Work_mcb_pmsm_foc_hall_f28069));
  mcb_pmsm_foc_hall_f28069m_DWork.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE = 0.0F;
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE_k = 0.0F;
  mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE_g = 0.0F;
  mcb_pmsm_foc_hall_f28069m_DWork.RT6_Buffer[0] = 0.0F;
  mcb_pmsm_foc_hall_f28069m_DWork.RT6_Buffer[1] = 0.0F;
  mcb_pmsm_foc_hall_f28069m_DWork.RT6_Buffer[2] = 0.0F;
  mcb_pmsm_foc_hall_f28069m_DWork.RT6_Buffer[3] = 0.0F;
  mcb_pmsm_foc_hall_f28069m_DWork.RT_Buffer[0] = 0.0F;
  mcb_pmsm_foc_hall_f28069m_DWork.RT_Buffer[1] = 0.0F;
  mcb_pmsm_foc_hall_f28069m_DWork.RT1_Buffer[0] = 0.0F;
  mcb_pmsm_foc_hall_f28069m_DWork.RT1_Buffer[1] = 0.0F;

  {
    uint16_T s313_iter;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    mcb_pmsm_foc_hall_f28069m_DWork.HallStateChangeFlag =
      mcb_pmsm_foc_hall_f28069m_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    mcb_pmsm_foc_hall_f28069m_DWork.GlobalSpeedCount =
      mcb_pmsm_foc_hall_f28069m_P.DataStoreMemory1_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    mcb_pmsm_foc_hall_f28069m_DWork.GlobalSpeedValidity =
      mcb_pmsm_foc_hall_f28069m_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory29' */
    mcb_pmsm_foc_hall_f28069m_DWork.Enable =
      mcb_pmsm_foc_hall_f28069m_P.DataStoreMemory29_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    mcb_pmsm_foc_hall_f28069m_DWork.GlobalDirection =
      mcb_pmsm_foc_hall_f28069m_P.DataStoreMemory3_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
    mcb_pmsm_foc_hall_f28069m_DWork.GlobalHallState =
      mcb_pmsm_foc_hall_f28069m_P.DataStoreMemory4_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
    mcb_pmsm_foc_hall_f28069m_DWork.IaOffset =
      mcb_pmsm_foc_hall_f28069m_P.DataStoreMemory5_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    mcb_pmsm_foc_hall_f28069m_DWork.IbOffset =
      mcb_pmsm_foc_hall_f28069m_P.DataStoreMemory6_InitialValue;

    /* InitializeConditions for RateTransition: '<Root>/RT6' */
    mcb_pmsm_foc_hall_f28069m_DWork.RT6_Buffer[0] =
      mcb_pmsm_foc_hall_f28069m_P.RT6_InitialCondition;
    mcb_pmsm_foc_hall_f28069m_DWork.RT6_Buffer[1] =
      mcb_pmsm_foc_hall_f28069m_P.RT6_InitialCondition;

    /* InitializeConditions for RateTransition: '<Root>/RT' */
    mcb_pmsm_foc_hall_f28069m_DWork.RT_Buffer[0] =
      mcb_pmsm_foc_hall_f28069m_P.RT_InitialCondition;

    /* InitializeConditions for RateTransition: '<Root>/RT1' */
    mcb_pmsm_foc_hall_f28069m_DWork.RT1_Buffer[0] =
      mcb_pmsm_foc_hall_f28069m_P.RT1_InitialCondition;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S238>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Hall Sensor A'
     */
    /* System initialize for function-call system: '<Root>/Hall Sensor A' */

    /* SystemInitialize for IfAction SubSystem: '<S251>/Valid Halls' */
    mcb_pmsm_fo_ValidHalls_Init(&mcb_pmsm_foc_hall_f28069m_B.ValidHalls,
      &mcb_pmsm_foc_hall_f28069m_P.ValidHalls);

    /* End of SystemInitialize for SubSystem: '<S251>/Valid Halls' */

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S240>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Hall Sensor B'
     */
    /* System initialize for function-call system: '<Root>/Hall Sensor B' */

    /* SystemInitialize for IfAction SubSystem: '<S272>/Valid Halls' */
    mcb_pmsm_fo_ValidHalls_Init(&mcb_pmsm_foc_hall_f28069m_B.ValidHalls_i,
      &mcb_pmsm_foc_hall_f28069m_P.ValidHalls_i);

    /* End of SystemInitialize for SubSystem: '<S272>/Valid Halls' */

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S242>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Hall Sensor C'
     */
    /* System initialize for function-call system: '<Root>/Hall Sensor C' */

    /* SystemInitialize for IfAction SubSystem: '<S293>/Valid Halls' */
    mcb_pmsm_fo_ValidHalls_Init(&mcb_pmsm_foc_hall_f28069m_B.ValidHalls_j,
      &mcb_pmsm_foc_hall_f28069m_P.ValidHalls_j);

    /* End of SystemInitialize for SubSystem: '<S293>/Valid Halls' */

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S236>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Current Control'
     */
    mcb_pms_CurrentControl_Init();

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S244>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Serial Receive'
     */
    /* System initialize for function-call system: '<Root>/Serial Receive' */

    /* Start for S-Function (c28xsci_rx): '<S324>/SCI Receive' */

    /* Initialize out port */
    {
      mcb_pmsm_foc_hall_f28069m_B.SCIReceive[0] = (uint16_T)0.0;
      mcb_pmsm_foc_hall_f28069m_B.SCIReceive[1] = (uint16_T)0.0;
    }

    /*Configure Timer2 when blocking mode is enabled and Timeout is not inf*/
    {
      /* InitCpuTimers() - CPU Timers are also initialized in
       * MW_c28xx_board.c in the generated code.
       */
      CpuTimer2Regs.PRD.all = 0xFFFFFFFFU;/* max Period*/
      CpuTimer2Regs.TIM.all = 0xFFFFFFFFU;/* set Ctr*/
      CpuTimer2Regs.TPR.all = 0x00U;   /* no prescaler    */
      StartCpuTimer2();
    }

    /* SystemInitialize for DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
     *  Outport: '<S9>/Desired Speed'
     */
    mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_l =
      mcb_pmsm_foc_hall_f28069m_P.DesiredSpeed_Y0;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Speed Control' */
    /* Start for Constant: '<S325>/Ki2' */
    mcb_pmsm_foc_hall_f28069m_B.Ki2 = mcb_pmsm_foc_hall_f28069m_P.Ki2_Value;

    /* InitializeConditions for UnitDelay: '<S381>/Unit Delay' */
    mcb_pmsm_foc_hall_f28069m_DWork.UnitDelay_DSTATE =
      mcb_pmsm_foc_hall_f28069m_P.UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S361>/Integrator' */
    mcb_pmsm_foc_hall_f28069m_DWork.Integrator_DSTATE =
      mcb_pmsm_foc_hall_f28069m_B.Ki2;
    mcb_pmsm_foc_hall_f28069m_DWork.Integrator_PrevResetState = 0;

    /* End of SystemInitialize for SubSystem: '<Root>/Speed Control' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
    /* Start for S-Function (c280xgpio_do): '<S320>/Digital Output1' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
    GpioCtrlRegs.GPADIR.all |= 0x80000000U;
    EDIS;

    /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Start for S-Function (c280xgpio_do): '<S311>/Digital Output2' */
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all &= 0xFFFFF333U;
    GpioCtrlRegs.GPADIR.all |= 0x2AU;
    EDIS;

    /* SystemInitialize for Enabled SubSystem: '<S309>/Calculate ADC Offset ' */
    /* SystemInitialize for Iterator SubSystem: '<S310>/For Iterator Subsystem' */
    /* Start for S-Function (c2802xadc): '<S313>/ADC' */
    if (MW_adcAInitFlag == 0U) {
      InitAdcA();
      MW_adcAInitFlag = 1U;
    }

    config_ADCA_SOC0 ();

    /* Start for S-Function (c2802xadc): '<S313>/ADC1' */
    if (MW_adcAInitFlag == 0U) {
      InitAdcA();
      MW_adcAInitFlag = 1U;
    }

    config_ADCA_SOC1 ();

    /* SystemInitialize for IfAction SubSystem: '<S313>/If Action Subsystem' */
    /* InitializeConditions for Memory: '<S318>/Memory' */
    mcb_pmsm_foc_hall_f28069m_DWork.Memory_PreviousInput =
      mcb_pmsm_foc_hall_f28069m_P.Memory_InitialCondition;

    /* InitializeConditions for Memory: '<S318>/Memory1' */
    mcb_pmsm_foc_hall_f28069m_DWork.Memory1_PreviousInput =
      mcb_pmsm_foc_hall_f28069m_P.Memory1_InitialCondition;

    /* SystemInitialize for Sum: '<S318>/Sum' incorporates:
     *  Outport: '<S318>/Out1'
     */
    mcb_pmsm_foc_hall_f28069m_B.Sum_m = mcb_pmsm_foc_hall_f28069m_P.Out1_Y0;

    /* SystemInitialize for Sum: '<S318>/Sum1' incorporates:
     *  Outport: '<S318>/Out2'
     */
    mcb_pmsm_foc_hall_f28069m_B.Sum1_i = mcb_pmsm_foc_hall_f28069m_P.Out2_Y0;

    /* End of SystemInitialize for SubSystem: '<S313>/If Action Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S310>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S309>/Calculate ADC Offset ' */
    /* End of SystemInitialize for SubSystem: '<Root>/Hardware Init' */

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* SignalConversion generated from: '<S311>/Digital Output2' incorporates:
     *  Constant: '<S6>/Constant'
     */
    mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalOut[0] =
      mcb_pmsm_foc_hall_f28069m_P.Constant_Value_m;
    mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalOut[1] =
      mcb_pmsm_foc_hall_f28069m_P.Constant_Value_m;
    mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalOut[2] =
      mcb_pmsm_foc_hall_f28069m_P.Constant_Value_m;

    /* S-Function (c280xgpio_do): '<S311>/Digital Output2' */
    {
      if (mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalOut[0]) {
        GpioDataRegs.GPASET.bit.GPIO1 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO1 = 1U;
      }

      if (mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalOut[1]) {
        GpioDataRegs.GPASET.bit.GPIO3 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO3 = 1U;
      }

      if (mcb_pmsm_foc_hall_f28069m_B.TmpSignalConversionAtDigitalOut[2]) {
        GpioDataRegs.GPASET.bit.GPIO5 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO5 = 1U;
      }
    }

    /* Outputs for Enabled SubSystem: '<S309>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S310>/Enable'
     */
    /* Constant: '<S309>/ADC Calib Enable' */
    if (mcb_pmsm_foc_hall_f28069m_P.ADCCalibEnable_Value > 0.0) {
      /* Outputs for Iterator SubSystem: '<S310>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S313>/For Iterator'
       */
      for (s313_iter = 1U; s313_iter <=
           mcb_pmsm_foc_hall_f28069m_P.ForIterator_IterationLimit; s313_iter++)
      {
        /* Outputs for Iterator SubSystem: '<S310>/For Iterator Subsystem' incorporates:
         *  ForIterator: '<S313>/For Iterator'
         */
        mcb_pmsm_foc_hall_f28069m_B.ForIterator = s313_iter;

        /* S-Function (c2802xadc): '<S313>/ADC' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          AdcaRegs.ADCSOCFRC1.bit.SOC0 = 1U;

          /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

          asm(" RPT #67|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

          float wait_index;
          for (wait_index= 11; wait_index > 0; wait_index--)
            __mnop();

#endif

          mcb_pmsm_foc_hall_f28069m_B.ADC = (AdcaResultRegs.ADCRESULT0);
        }

        /* S-Function (c2802xadc): '<S313>/ADC1' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          AdcaRegs.ADCSOCFRC1.bit.SOC1 = 1U;

          /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

          asm(" RPT #67|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

          float wait_index;
          for (wait_index= 11; wait_index > 0; wait_index--)
            __mnop();

#endif

          mcb_pmsm_foc_hall_f28069m_B.ADC1 = (AdcaResultRegs.ADCRESULT1);
        }

        /* If: '<S313>/If' */
        if (mcb_pmsm_foc_hall_f28069m_B.ForIterator > 8U) {
          /* Outputs for IfAction SubSystem: '<S313>/If Action Subsystem' incorporates:
           *  ActionPort: '<S318>/Action Port'
           */
          /* Memory: '<S318>/Memory' */
          mcb_pmsm_foc_hall_f28069m_B.Memory =
            mcb_pmsm_foc_hall_f28069m_DWork.Memory_PreviousInput;

          /* Sum: '<S318>/Sum' */
          mcb_pmsm_foc_hall_f28069m_B.Sum_m = mcb_pmsm_foc_hall_f28069m_B.ADC +
            mcb_pmsm_foc_hall_f28069m_B.Memory;

          /* Memory: '<S318>/Memory1' */
          mcb_pmsm_foc_hall_f28069m_B.Memory1 =
            mcb_pmsm_foc_hall_f28069m_DWork.Memory1_PreviousInput;

          /* Sum: '<S318>/Sum1' */
          mcb_pmsm_foc_hall_f28069m_B.Sum1_i = mcb_pmsm_foc_hall_f28069m_B.ADC1
            + mcb_pmsm_foc_hall_f28069m_B.Memory1;

          /* Update for Memory: '<S318>/Memory' */
          mcb_pmsm_foc_hall_f28069m_DWork.Memory_PreviousInput =
            mcb_pmsm_foc_hall_f28069m_B.Sum_m;

          /* Update for Memory: '<S318>/Memory1' */
          mcb_pmsm_foc_hall_f28069m_DWork.Memory1_PreviousInput =
            mcb_pmsm_foc_hall_f28069m_B.Sum1_i;

          /* End of Outputs for SubSystem: '<S313>/If Action Subsystem' */
        }

        /* End of If: '<S313>/If' */
      }

      /* End of Outputs for SubSystem: '<S310>/For Iterator Subsystem' */

      /* Product: '<S310>/Divide' incorporates:
       *  Constant: '<S310>/Constant'
       */
      mcb_pmsm_foc_hall_f28069m_B.Divide_d = (uint16_T)((real_T)
        mcb_pmsm_foc_hall_f28069m_B.Sum_m /
        mcb_pmsm_foc_hall_f28069m_P.Constant_Value_g);

      /* If: '<S310>/If' incorporates:
       *  Constant: '<S310>/Constant1'
       *  Constant: '<S310>/Constant2'
       */
      if ((mcb_pmsm_foc_hall_f28069m_B.Divide_d >
           mcb_pmsm_foc_hall_f28069m_P.Constant2_Value_b) &&
          (mcb_pmsm_foc_hall_f28069m_B.Divide_d <
           mcb_pmsm_foc_hall_f28069m_P.Constant1_Value_o)) {
        /* Outputs for IfAction SubSystem: '<S310>/If Action Subsystem' incorporates:
         *  ActionPort: '<S314>/Action Port'
         */
        /* DataStoreWrite: '<S314>/Data Store Write1' */
        mcb_pmsm_foc_hall_f28069m_DWork.IaOffset =
          mcb_pmsm_foc_hall_f28069m_B.Divide_d;

        /* End of Outputs for SubSystem: '<S310>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S310>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S315>/Action Port'
         */
        /* DataStoreWrite: '<S315>/Data Store Write1' incorporates:
         *  Constant: '<S315>/Constant'
         */
        mcb_pmsm_foc_hall_f28069m_DWork.IaOffset =
          mcb_pmsm_foc_hall_f28069m_P.Constant_Value_f2;

        /* End of Outputs for SubSystem: '<S310>/If Action Subsystem1' */
      }

      /* End of If: '<S310>/If' */

      /* Product: '<S310>/Divide1' incorporates:
       *  Constant: '<S310>/Constant'
       */
      mcb_pmsm_foc_hall_f28069m_B.Divide1_j = (uint16_T)((real_T)
        mcb_pmsm_foc_hall_f28069m_B.Sum1_i /
        mcb_pmsm_foc_hall_f28069m_P.Constant_Value_g);

      /* If: '<S310>/If1' incorporates:
       *  Constant: '<S310>/Constant1'
       *  Constant: '<S310>/Constant2'
       */
      if ((mcb_pmsm_foc_hall_f28069m_B.Divide1_j >
           mcb_pmsm_foc_hall_f28069m_P.Constant2_Value_b) &&
          (mcb_pmsm_foc_hall_f28069m_B.Divide1_j <
           mcb_pmsm_foc_hall_f28069m_P.Constant1_Value_o)) {
        /* Outputs for IfAction SubSystem: '<S310>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S316>/Action Port'
         */
        /* DataStoreWrite: '<S316>/Data Store Write2' */
        mcb_pmsm_foc_hall_f28069m_DWork.IbOffset =
          mcb_pmsm_foc_hall_f28069m_B.Divide1_j;

        /* End of Outputs for SubSystem: '<S310>/If Action Subsystem2' */
      } else {
        /* Outputs for IfAction SubSystem: '<S310>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S317>/Action Port'
         */
        /* DataStoreWrite: '<S317>/Data Store Write2' incorporates:
         *  Constant: '<S317>/Constant1'
         */
        mcb_pmsm_foc_hall_f28069m_DWork.IbOffset =
          mcb_pmsm_foc_hall_f28069m_P.Constant1_Value_h;

        /* End of Outputs for SubSystem: '<S310>/If Action Subsystem3' */
      }

      /* End of If: '<S310>/If1' */
    }

    /* End of Outputs for SubSystem: '<S309>/Calculate ADC Offset ' */

    /* Logic: '<S309>/NOT' incorporates:
     *  Constant: '<S309>/ADC Calib Enable'
     */
    mcb_pmsm_foc_hall_f28069m_B.NOT =
      !(mcb_pmsm_foc_hall_f28069m_P.ADCCalibEnable_Value != 0.0);

    /* Outputs for Enabled SubSystem: '<S309>/Default ADC Offset' incorporates:
     *  EnablePort: '<S312>/Enable'
     */
    if (mcb_pmsm_foc_hall_f28069m_B.NOT) {
      /* DataStoreWrite: '<S312>/Data Store Write1' incorporates:
       *  Constant: '<S312>/Constant'
       */
      mcb_pmsm_foc_hall_f28069m_DWork.IaOffset =
        mcb_pmsm_foc_hall_f28069m_P.Constant_Value_a;

      /* DataStoreWrite: '<S312>/Data Store Write2' incorporates:
       *  Constant: '<S312>/Constant1'
       */
      mcb_pmsm_foc_hall_f28069m_DWork.IbOffset =
        mcb_pmsm_foc_hall_f28069m_P.Constant1_Value_ei;
    }

    /* End of Outputs for SubSystem: '<S309>/Default ADC Offset' */
    /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
  }
}

/* Model terminate function */
void mcb_pmsm_foc_hall_f28069m_terminate(void)
{
  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S236>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Current Control'
   */
  mcb_pms_CurrentControl_Term();

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S236>/Hardware Interrupt' */
}

void mcb_pmsm_foc_hall_f28069m_configure_interrupts(void)
{
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
  HWI_TIC28x_ConfigureIRQ(32,&ADCA1_INT,1);
  HWI_TIC28x_EnableIRQ(32);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(96,&SCIA_RX_INT,3);
  HWI_TIC28x_EnableIRQ(96);
}

/* Hardware Interrupt Block: '<S236>/Hardware Interrupt' */
interrupt void ADCA1_INT(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  volatile unsigned int PIEIER9_stack_save = PieCtrlRegs.PIEIER9.all;
  PieCtrlRegs.PIEIER1.all &= ~65;
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
      int16_T tmp;

      /* RateTransition: '<Root>/RT6' */
      tmp = mcb_pmsm_foc_hall_f28069m_DWork.RT6_ActiveBufIdx << 1U;
      mcb_pmsm_foc_hall_f28069m_B.RT6[0] =
        mcb_pmsm_foc_hall_f28069m_DWork.RT6_Buffer[tmp];
      mcb_pmsm_foc_hall_f28069m_B.RT6[1] =
        mcb_pmsm_foc_hall_f28069m_DWork.RT6_Buffer[tmp + 1];

      /* S-Function (HardwareInterrupt_sfun): '<S236>/Hardware Interrupt' */
      mcb_pmsm_foc_CurrentControl();

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S236>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT1' */
      mcb_pmsm_foc_hall_f28069m_DWork.RT1_Buffer[mcb_pmsm_foc_hall_f28069m_DWork.RT1_semaphoreTaken
        == 0] = mcb_pmsm_foc_hall_f28069m_B.Speed_PU;
      mcb_pmsm_foc_hall_f28069m_DWork.RT1_ActiveBufIdx =
        (mcb_pmsm_foc_hall_f28069m_DWork.RT1_semaphoreTaken == 0);
    }
  }

  /* Clear occurred EOC event event */
  AdcaRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdcaRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEIER9.all = PIEIER9_stack_save;
                                   /*restore PIEIER register that was modified*/
  HWI_TIC28x_AcknowledgeIrq(32);
}

/* Hardware Interrupt Block: '<S238>/Hardware Interrupt' */
interrupt void ECAP1_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S238>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Hall Sensor A' */

      /* DataStoreRead: '<S3>/Data Store Read' */
      mcb_pmsm_foc_hall_f28069m_B.DataStoreRead_m =
        mcb_pmsm_foc_hall_f28069m_DWork.GlobalHallState;

      /* S-Function (memorycopy): '<S264>/Memory Copy' */
      {
        uint32_T *memindsrc6 = (uint32_T *) (&GpioDataRegs.GPADAT.all);
        uint32_T *meminddst6 = (uint32_T *)
          (&mcb_pmsm_foc_hall_f28069m_B.MemoryCopy_p);
        *(uint32_T *) (meminddst6) = *(uint32_T *) (memindsrc6);
      }

      /* S-Function (sfix_bitop): '<S264>/Bitwise AND' */
      mcb_pmsm_foc_hall_f28069m_B.BitwiseAND_a =
        mcb_pmsm_foc_hall_f28069m_B.MemoryCopy_p &
        mcb_pmsm_foc_hall_f28069m_P.BitwiseAND_BitMask_m;

      /* ArithShift: '<S264>/Shift Arithmetic' incorporates:
       *  S-Function (sfix_bitop): '<S264>/Bitwise AND'
       */
      mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_dt =
        mcb_pmsm_foc_hall_f28069m_B.BitwiseAND_a >> 24U;

      /* DataTypeConversion: '<S246>/Data Type Conversion1' */
      mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_e = (uint16_T)
        mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_dt;

      /* DataTypeConversion: '<S246>/Data Type Conversion2' */
      mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion2_a = (uint16_T)
        mcb_pmsm_foc_hall_f28069m_B.DataStoreRead_m;

      /* DataStoreRead: '<S3>/Data Store Read1' */
      mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_lq =
        mcb_pmsm_foc_hall_f28069m_DWork.GlobalDirection;

      /* SwitchCase: '<S246>/Detects if the halls reading is valid' */
      switch ((int32_T)mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_e) {
       case 5L:
       case 4L:
       case 6L:
       case 2L:
       case 3L:
       case 1L:
        /* Outputs for IfAction SubSystem: '<S251>/Valid Halls' incorporates:
         *  ActionPort: '<S253>/Action Port'
         */
        mcb_pmsm_foc_hal_ValidHalls
          (mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_e,
           mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion2_a,
           mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_lq,
           &mcb_pmsm_foc_hall_f28069m_B.Merge3_d,
           &mcb_pmsm_foc_hall_f28069m_B.Merge1_ml,
           &mcb_pmsm_foc_hall_f28069m_B.Merge_m4,
           &mcb_pmsm_foc_hall_f28069m_B.ValidHalls,
           &mcb_pmsm_foc_hall_f28069m_P.ValidHalls);

        /* End of Outputs for SubSystem: '<S251>/Valid Halls' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S251>/Bad hall (glitch or wrong connection)' incorporates:
         *  ActionPort: '<S252>/Action Port'
         */
        Badhallglitchorwrongconnect
          (mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_lq,
           &mcb_pmsm_foc_hall_f28069m_B.Merge_m4,
           &mcb_pmsm_foc_hall_f28069m_B.Merge1_ml,
           &mcb_pmsm_foc_hall_f28069m_B.Merge3_d,
           &mcb_pmsm_foc_hall_f28069m_P.Badhallglitchorwrongconnection);

        /* End of Outputs for SubSystem: '<S251>/Bad hall (glitch or wrong connection)' */
        break;
      }

      /* End of SwitchCase: '<S246>/Detects if the halls reading is valid' */

      /* DataTypeConversion: '<S251>/Data Type Conversion' */
      mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_nh =
        mcb_pmsm_foc_hall_f28069m_B.Merge3_d;

      /* DataStoreWrite: '<S3>/Data Store Write' */
      mcb_pmsm_foc_hall_f28069m_DWork.GlobalSpeedValidity =
        mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_nh;

      /* DataStoreWrite: '<S3>/Data Store Write1' */
      mcb_pmsm_foc_hall_f28069m_DWork.GlobalDirection =
        mcb_pmsm_foc_hall_f28069m_B.Merge1_ml;

      /* DataStoreWrite: '<S3>/Data Store Write2' incorporates:
       *  Constant: '<S246>/Constant'
       */
      mcb_pmsm_foc_hall_f28069m_DWork.HallStateChangeFlag =
        mcb_pmsm_foc_hall_f28069m_P.Constant_Value_me;

      /* S-Function (c280xcap): '<S265>/eCAP' */
      mcb_pmsm_foc_hall_f28069m_B.eCAP_l[0] = ECap1Regs.CAP1;
      mcb_pmsm_foc_hall_f28069m_B.eCAP_l[1] = ECap1Regs.CAP2;

      /* If: '<S245>/If' */
      if (((uint16_T)mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_dt == 5U) ||
          ((uint16_T)mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_dt == 3U)) {
        /* Outputs for IfAction SubSystem: '<S245>/Output 1' incorporates:
         *  ActionPort: '<S250>/Action Port'
         */
        mcb_pmsm_foc_hall_f_Output1(&mcb_pmsm_foc_hall_f28069m_B.Merge_i,
          &mcb_pmsm_foc_hall_f28069m_P.Output1);

        /* End of Outputs for SubSystem: '<S245>/Output 1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S245>/Output 0' incorporates:
         *  ActionPort: '<S249>/Action Port'
         */
        mcb_pmsm_foc_hall_f_Output1(&mcb_pmsm_foc_hall_f28069m_B.Merge_i,
          &mcb_pmsm_foc_hall_f28069m_P.Output0);

        /* End of Outputs for SubSystem: '<S245>/Output 0' */
      }

      /* End of If: '<S245>/If' */

      /* Switch: '<S3>/Switch' */
      if (mcb_pmsm_foc_hall_f28069m_B.Merge_i) {
        /* Switch: '<S3>/Switch' */
        mcb_pmsm_foc_hall_f28069m_B.Switch_m =
          mcb_pmsm_foc_hall_f28069m_B.eCAP_l[0];
      } else {
        /* Switch: '<S3>/Switch' */
        mcb_pmsm_foc_hall_f28069m_B.Switch_m =
          mcb_pmsm_foc_hall_f28069m_B.eCAP_l[1];
      }

      /* End of Switch: '<S3>/Switch' */

      /* DataStoreWrite: '<S3>/Data Store Write3' */
      mcb_pmsm_foc_hall_f28069m_DWork.GlobalSpeedCount =
        mcb_pmsm_foc_hall_f28069m_B.Switch_m;

      /* DataStoreWrite: '<S3>/Data Store Write4' */
      mcb_pmsm_foc_hall_f28069m_DWork.GlobalHallState =
        mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_dt;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S238>/Hardware Interrupt' */
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

/* Hardware Interrupt Block: '<S240>/Hardware Interrupt' */
interrupt void ECAP2_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S240>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Hall Sensor B' */

      /* DataStoreRead: '<S4>/Data Store Read' */
      mcb_pmsm_foc_hall_f28069m_B.DataStoreRead_g =
        mcb_pmsm_foc_hall_f28069m_DWork.GlobalHallState;

      /* S-Function (memorycopy): '<S285>/Memory Copy' */
      {
        uint32_T *memindsrc7 = (uint32_T *) (&GpioDataRegs.GPADAT.all);
        uint32_T *meminddst7 = (uint32_T *)
          (&mcb_pmsm_foc_hall_f28069m_B.MemoryCopy_m);
        *(uint32_T *) (meminddst7) = *(uint32_T *) (memindsrc7);
      }

      /* S-Function (sfix_bitop): '<S285>/Bitwise AND' */
      mcb_pmsm_foc_hall_f28069m_B.BitwiseAND_p =
        mcb_pmsm_foc_hall_f28069m_B.MemoryCopy_m &
        mcb_pmsm_foc_hall_f28069m_P.BitwiseAND_BitMask_d;

      /* ArithShift: '<S285>/Shift Arithmetic' incorporates:
       *  S-Function (sfix_bitop): '<S285>/Bitwise AND'
       */
      mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_d =
        mcb_pmsm_foc_hall_f28069m_B.BitwiseAND_p >> 24U;

      /* DataTypeConversion: '<S267>/Data Type Conversion1' */
      mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_c = (uint16_T)
        mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_d;

      /* DataTypeConversion: '<S267>/Data Type Conversion2' */
      mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion2_g = (uint16_T)
        mcb_pmsm_foc_hall_f28069m_B.DataStoreRead_g;

      /* DataStoreRead: '<S4>/Data Store Read1' */
      mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_l =
        mcb_pmsm_foc_hall_f28069m_DWork.GlobalDirection;

      /* SwitchCase: '<S267>/Detects if the halls reading is valid' */
      switch ((int32_T)mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_c) {
       case 5L:
       case 4L:
       case 6L:
       case 2L:
       case 3L:
       case 1L:
        /* Outputs for IfAction SubSystem: '<S272>/Valid Halls' incorporates:
         *  ActionPort: '<S274>/Action Port'
         */
        mcb_pmsm_foc_hal_ValidHalls
          (mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_c,
           mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion2_g,
           mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_l,
           &mcb_pmsm_foc_hall_f28069m_B.Merge3_k,
           &mcb_pmsm_foc_hall_f28069m_B.Merge1_d4,
           &mcb_pmsm_foc_hall_f28069m_B.Merge_a,
           &mcb_pmsm_foc_hall_f28069m_B.ValidHalls_i,
           &mcb_pmsm_foc_hall_f28069m_P.ValidHalls_i);

        /* End of Outputs for SubSystem: '<S272>/Valid Halls' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S272>/Bad hall (glitch or wrong connection)' incorporates:
         *  ActionPort: '<S273>/Action Port'
         */
        Badhallglitchorwrongconnect(mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_l,
          &mcb_pmsm_foc_hall_f28069m_B.Merge_a,
          &mcb_pmsm_foc_hall_f28069m_B.Merge1_d4,
          &mcb_pmsm_foc_hall_f28069m_B.Merge3_k,
          &mcb_pmsm_foc_hall_f28069m_P.Badhallglitchorwrongconnectio_k);

        /* End of Outputs for SubSystem: '<S272>/Bad hall (glitch or wrong connection)' */
        break;
      }

      /* End of SwitchCase: '<S267>/Detects if the halls reading is valid' */

      /* DataTypeConversion: '<S272>/Data Type Conversion' */
      mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_p1 =
        mcb_pmsm_foc_hall_f28069m_B.Merge3_k;

      /* DataStoreWrite: '<S4>/Data Store Write' */
      mcb_pmsm_foc_hall_f28069m_DWork.GlobalSpeedValidity =
        mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_p1;

      /* DataStoreWrite: '<S4>/Data Store Write1' */
      mcb_pmsm_foc_hall_f28069m_DWork.GlobalDirection =
        mcb_pmsm_foc_hall_f28069m_B.Merge1_d4;

      /* DataStoreWrite: '<S4>/Data Store Write2' incorporates:
       *  Constant: '<S267>/Constant'
       */
      mcb_pmsm_foc_hall_f28069m_DWork.HallStateChangeFlag =
        mcb_pmsm_foc_hall_f28069m_P.Constant_Value_j;

      /* S-Function (c280xcap): '<S286>/eCAP' */
      mcb_pmsm_foc_hall_f28069m_B.eCAP_j[0] = ECap2Regs.CAP1;
      mcb_pmsm_foc_hall_f28069m_B.eCAP_j[1] = ECap2Regs.CAP2;

      /* If: '<S266>/If' */
      if (((uint16_T)mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_d == 3U) ||
          ((uint16_T)mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_d == 6U)) {
        /* Outputs for IfAction SubSystem: '<S266>/Output 1' incorporates:
         *  ActionPort: '<S271>/Action Port'
         */
        mcb_pmsm_foc_hall_f_Output1(&mcb_pmsm_foc_hall_f28069m_B.Merge_d,
          &mcb_pmsm_foc_hall_f28069m_P.Output1_a);

        /* End of Outputs for SubSystem: '<S266>/Output 1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S266>/Output 0' incorporates:
         *  ActionPort: '<S270>/Action Port'
         */
        mcb_pmsm_foc_hall_f_Output1(&mcb_pmsm_foc_hall_f28069m_B.Merge_d,
          &mcb_pmsm_foc_hall_f28069m_P.Output0_f);

        /* End of Outputs for SubSystem: '<S266>/Output 0' */
      }

      /* End of If: '<S266>/If' */

      /* Switch: '<S4>/Switch' */
      if (mcb_pmsm_foc_hall_f28069m_B.Merge_d) {
        /* Switch: '<S4>/Switch' */
        mcb_pmsm_foc_hall_f28069m_B.Switch_p =
          mcb_pmsm_foc_hall_f28069m_B.eCAP_j[0];
      } else {
        /* Switch: '<S4>/Switch' */
        mcb_pmsm_foc_hall_f28069m_B.Switch_p =
          mcb_pmsm_foc_hall_f28069m_B.eCAP_j[1];
      }

      /* End of Switch: '<S4>/Switch' */

      /* DataStoreWrite: '<S4>/Data Store Write3' */
      mcb_pmsm_foc_hall_f28069m_DWork.GlobalSpeedCount =
        mcb_pmsm_foc_hall_f28069m_B.Switch_p;

      /* DataStoreWrite: '<S4>/Data Store Write4' */
      mcb_pmsm_foc_hall_f28069m_DWork.GlobalHallState =
        mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic_d;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S240>/Hardware Interrupt' */
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

/* Hardware Interrupt Block: '<S242>/Hardware Interrupt' */
interrupt void ECAP3_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S242>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Hall Sensor C' */

      /* DataStoreRead: '<S5>/Data Store Read' */
      mcb_pmsm_foc_hall_f28069m_B.DataStoreRead =
        mcb_pmsm_foc_hall_f28069m_DWork.GlobalHallState;

      /* S-Function (memorycopy): '<S306>/Memory Copy' */
      {
        uint32_T *memindsrc8 = (uint32_T *) (&GpioDataRegs.GPADAT.all);
        uint32_T *meminddst8 = (uint32_T *)
          (&mcb_pmsm_foc_hall_f28069m_B.MemoryCopy);
        *(uint32_T *) (meminddst8) = *(uint32_T *) (memindsrc8);
      }

      /* S-Function (sfix_bitop): '<S306>/Bitwise AND' */
      mcb_pmsm_foc_hall_f28069m_B.BitwiseAND =
        mcb_pmsm_foc_hall_f28069m_B.MemoryCopy &
        mcb_pmsm_foc_hall_f28069m_P.BitwiseAND_BitMask_pw;

      /* ArithShift: '<S306>/Shift Arithmetic' incorporates:
       *  S-Function (sfix_bitop): '<S306>/Bitwise AND'
       */
      mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic =
        mcb_pmsm_foc_hall_f28069m_B.BitwiseAND >> 24U;

      /* DataTypeConversion: '<S288>/Data Type Conversion1' */
      mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_n = (uint16_T)
        mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic;

      /* DataTypeConversion: '<S288>/Data Type Conversion2' */
      mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion2 = (uint16_T)
        mcb_pmsm_foc_hall_f28069m_B.DataStoreRead;

      /* DataStoreRead: '<S5>/Data Store Read1' */
      mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_i =
        mcb_pmsm_foc_hall_f28069m_DWork.GlobalDirection;

      /* SwitchCase: '<S288>/Detects if the halls reading is valid' */
      switch ((int32_T)mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_n) {
       case 5L:
       case 4L:
       case 6L:
       case 2L:
       case 3L:
       case 1L:
        /* Outputs for IfAction SubSystem: '<S293>/Valid Halls' incorporates:
         *  ActionPort: '<S295>/Action Port'
         */
        mcb_pmsm_foc_hal_ValidHalls
          (mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_n,
           mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion2,
           mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_i,
           &mcb_pmsm_foc_hall_f28069m_B.Merge3,
           &mcb_pmsm_foc_hall_f28069m_B.Merge1_i,
           &mcb_pmsm_foc_hall_f28069m_B.Merge_l,
           &mcb_pmsm_foc_hall_f28069m_B.ValidHalls_j,
           &mcb_pmsm_foc_hall_f28069m_P.ValidHalls_j);

        /* End of Outputs for SubSystem: '<S293>/Valid Halls' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S293>/Bad hall (glitch or wrong connection)' incorporates:
         *  ActionPort: '<S294>/Action Port'
         */
        Badhallglitchorwrongconnect(mcb_pmsm_foc_hall_f28069m_B.DataStoreRead1_i,
          &mcb_pmsm_foc_hall_f28069m_B.Merge_l,
          &mcb_pmsm_foc_hall_f28069m_B.Merge1_i,
          &mcb_pmsm_foc_hall_f28069m_B.Merge3,
          &mcb_pmsm_foc_hall_f28069m_P.Badhallglitchorwrongconnectio_l);

        /* End of Outputs for SubSystem: '<S293>/Bad hall (glitch or wrong connection)' */
        break;
      }

      /* End of SwitchCase: '<S288>/Detects if the halls reading is valid' */

      /* DataTypeConversion: '<S293>/Data Type Conversion' */
      mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_f =
        mcb_pmsm_foc_hall_f28069m_B.Merge3;

      /* DataStoreWrite: '<S5>/Data Store Write' */
      mcb_pmsm_foc_hall_f28069m_DWork.GlobalSpeedValidity =
        mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion_f;

      /* DataStoreWrite: '<S5>/Data Store Write1' */
      mcb_pmsm_foc_hall_f28069m_DWork.GlobalDirection =
        mcb_pmsm_foc_hall_f28069m_B.Merge1_i;

      /* DataStoreWrite: '<S5>/Data Store Write2' incorporates:
       *  Constant: '<S288>/Constant'
       */
      mcb_pmsm_foc_hall_f28069m_DWork.HallStateChangeFlag =
        mcb_pmsm_foc_hall_f28069m_P.Constant_Value_i;

      /* S-Function (c280xcap): '<S307>/eCAP' */
      mcb_pmsm_foc_hall_f28069m_B.eCAP[0] = ECap3Regs.CAP1;
      mcb_pmsm_foc_hall_f28069m_B.eCAP[1] = ECap3Regs.CAP2;

      /* If: '<S287>/If' */
      if (((uint16_T)mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic == 5U) ||
          ((uint16_T)mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic == 6U)) {
        /* Outputs for IfAction SubSystem: '<S287>/Output 1' incorporates:
         *  ActionPort: '<S292>/Action Port'
         */
        mcb_pmsm_foc_hall_f_Output1(&mcb_pmsm_foc_hall_f28069m_B.Merge_j,
          &mcb_pmsm_foc_hall_f28069m_P.Output1_o);

        /* End of Outputs for SubSystem: '<S287>/Output 1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S287>/Output 0' incorporates:
         *  ActionPort: '<S291>/Action Port'
         */
        mcb_pmsm_foc_hall_f_Output1(&mcb_pmsm_foc_hall_f28069m_B.Merge_j,
          &mcb_pmsm_foc_hall_f28069m_P.Output0_b);

        /* End of Outputs for SubSystem: '<S287>/Output 0' */
      }

      /* End of If: '<S287>/If' */

      /* Switch: '<S5>/Switch' */
      if (mcb_pmsm_foc_hall_f28069m_B.Merge_j) {
        /* Switch: '<S5>/Switch' */
        mcb_pmsm_foc_hall_f28069m_B.Switch = mcb_pmsm_foc_hall_f28069m_B.eCAP[0];
      } else {
        /* Switch: '<S5>/Switch' */
        mcb_pmsm_foc_hall_f28069m_B.Switch = mcb_pmsm_foc_hall_f28069m_B.eCAP[1];
      }

      /* End of Switch: '<S5>/Switch' */

      /* DataStoreWrite: '<S5>/Data Store Write3' */
      mcb_pmsm_foc_hall_f28069m_DWork.GlobalSpeedCount =
        mcb_pmsm_foc_hall_f28069m_B.Switch;

      /* DataStoreWrite: '<S5>/Data Store Write4' */
      mcb_pmsm_foc_hall_f28069m_DWork.GlobalHallState =
        mcb_pmsm_foc_hall_f28069m_B.ShiftArithmetic;

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S242>/Hardware Interrupt' */
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

/* Hardware Interrupt Block: '<S244>/Hardware Interrupt' */
interrupt void SCIA_RX_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S244>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Serial Receive' */
      {
        int16_T DataTypeConversion2_h;

        /* S-Function (c28xsci_rx): '<S324>/SCI Receive' */
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
            errFlg = scia_rcv(recbuff, 4, 2);
            asm(" NOP");
            if ((errFlg == NOERROR) || (errFlg == PARTIALDATA)) {
              memcpy( &mcb_pmsm_foc_hall_f28069m_B.SCIReceive[0], recbuff,2);
            }
          }
        }

        /* DataTypeConversion: '<S322>/Data Type Conversion2' */
        DataTypeConversion2_h = (int16_T)mcb_pmsm_foc_hall_f28069m_B.SCIReceive
          [0];
        mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion2_h[0] =
          DataTypeConversion2_h;

        /* DataTypeConversion: '<S322>/Data Type Conversion1' incorporates:
         *  DataTypeConversion: '<S322>/Data Type Conversion2'
         */
        mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1[0] = (real32_T)
          DataTypeConversion2_h * 0.000244140625F;

        /* DataTypeConversion: '<S322>/Data Type Conversion2' */
        DataTypeConversion2_h = (int16_T)mcb_pmsm_foc_hall_f28069m_B.SCIReceive
          [1];
        mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion2_h[1] =
          DataTypeConversion2_h;

        /* DataTypeConversion: '<S322>/Data Type Conversion1' incorporates:
         *  DataTypeConversion: '<S322>/Data Type Conversion2'
         */
        mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1[1] = (real32_T)
          DataTypeConversion2_h * 0.000244140625F;

        /* DataTypeConversion: '<S9>/Data Type Conversion3' */
        mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion3_o =
          (mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1[1] != 0.0F);

        /* DataStoreWrite: '<S9>/Data Store Write' */
        mcb_pmsm_foc_hall_f28069m_DWork.Enable =
          mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion3_o;

        /* DataTypeConversion: '<S9>/Data Type Conversion1' */
        mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_l =
          mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1[0];
      }

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S244>/Hardware Interrupt' */

      /* Update for RateTransition: '<Root>/RT' */
      mcb_pmsm_foc_hall_f28069m_DWork.RT_Buffer[mcb_pmsm_foc_hall_f28069m_DWork.RT_ActiveBufIdx
        == 0] = mcb_pmsm_foc_hall_f28069m_B.DataTypeConversion1_l;
      mcb_pmsm_foc_hall_f28069m_DWork.RT_ActiveBufIdx =
        (mcb_pmsm_foc_hall_f28069m_DWork.RT_ActiveBufIdx == 0);
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

void mcb_pmsm_foc_hall_f28069m_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(56);
  HWI_TIC28x_DisableIRQ(57);
  HWI_TIC28x_DisableIRQ(58);
  HWI_TIC28x_DisableIRQ(32);
  HWI_TIC28x_DisableIRQ(96);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
