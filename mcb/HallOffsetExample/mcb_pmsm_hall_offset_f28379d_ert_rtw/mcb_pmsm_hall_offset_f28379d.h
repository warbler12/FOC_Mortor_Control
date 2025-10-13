/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_hall_offset_f28379d.h
 *
 * Code generated for Simulink model 'mcb_pmsm_hall_offset_f28379d'.
 *
 * Model version                  : 7.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Oct 13 11:25:57 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_mcb_pmsm_hall_offset_f28379d_h_
#define RTW_HEADER_mcb_pmsm_hall_offset_f28379d_h_
#ifndef mcb_pmsm_hall_offset_f28379d_COMMON_INCLUDES_
#define mcb_pmsm_hall_offset_f28379d_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "string.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "DSP28xx_SciUtil.h"
#include "IQmathLib.h"
#endif                       /* mcb_pmsm_hall_offset_f28379d_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_pmsm_hall_offset_f28379d_types.h"
#include <stddef.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void init_CAP_GPIO(void);
extern void init_CAP1(void);
extern void init_CAP2(void);
extern void init_CAP3(void);
extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);
extern void configureIXbar(void);

/* Block signals for system '<S28>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S30>/Merge' */
  uint16_T Merge1;                     /* '<S30>/Merge1' */
  uint16_T Merge3;                     /* '<S30>/Merge3' */
  int16_T Merge2;                      /* '<S30>/Merge2' */
  boolean_T RelationalOperator;        /* '<S30>/Relational Operator' */
} rtB_ValidHalls_mcb_pmsm_hall_of;

/* Block signals (default storage) */
typedef struct {
  uint32_T ReadGPIODATregister;        /* '<S61>/Read GPIO DAT register' */
  uint32_T Hall_C;                     /* '<S61>/Hall_C' */
  uint32_T ShiftArithmetic;            /* '<S61>/Shift Arithmetic' */
  uint32_T Hall_B;                     /* '<S61>/Hall_B' */
  uint32_T ShiftArithmetic1;           /* '<S61>/Shift Arithmetic1' */
  uint32_T Hall_A;                     /* '<S61>/Hall_A' */
  uint32_T ShiftArithmetic2;           /* '<S61>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2;           /* '<S61>/Bitwise Operator2' */
  uint32_T DataStoreRead;              /* '<S4>/Data Store Read' */
  uint32_T eCAP[2];                    /* '<S4>/eCAP' */
  uint32_T Switch;                     /* '<S4>/Switch' */
  uint32_T ReadGPIODATregister_b;      /* '<S43>/Read GPIO DAT register' */
  uint32_T Hall_C_e;                   /* '<S43>/Hall_C' */
  uint32_T ShiftArithmetic_o;          /* '<S43>/Shift Arithmetic' */
  uint32_T Hall_B_g;                   /* '<S43>/Hall_B' */
  uint32_T ShiftArithmetic1_l;         /* '<S43>/Shift Arithmetic1' */
  uint32_T Hall_A_f;                   /* '<S43>/Hall_A' */
  uint32_T ShiftArithmetic2_c;         /* '<S43>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2_k;         /* '<S43>/Bitwise Operator2' */
  uint32_T DataStoreRead_b;            /* '<S3>/Data Store Read' */
  uint32_T eCAP_n[2];                  /* '<S3>/eCAP' */
  uint32_T Switch_n;                   /* '<S3>/Switch' */
  uint32_T ReadGPIODATregister_l;      /* '<S25>/Read GPIO DAT register' */
  uint32_T Hall_C_o;                   /* '<S25>/Hall_C' */
  uint32_T ShiftArithmetic_j;          /* '<S25>/Shift Arithmetic' */
  uint32_T Hall_B_n;                   /* '<S25>/Hall_B' */
  uint32_T ShiftArithmetic1_a;         /* '<S25>/Shift Arithmetic1' */
  uint32_T Hall_A_e;                   /* '<S25>/Hall_A' */
  uint32_T ShiftArithmetic2_h;         /* '<S25>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2_kn;        /* '<S25>/Bitwise Operator2' */
  uint32_T DataStoreRead_b3;           /* '<S2>/Data Store Read' */
  uint32_T eCAP_i[2];                  /* '<S2>/eCAP' */
  uint32_T Switch_e;                   /* '<S2>/Switch' */
  uint32_T speedCountDelay;            /* '<S134>/speedCountDelay' */
  uint32_T BytePack[2];                /* '<S123>/Byte Pack' */
  uint32_T SCI_Tx_Data[3];             /* '<S121>/Merge' */
  uint32_T SCI_Tx_Iteration;           /* '<S121>/Merge1' */
  uint32_T Sum[4];                     /* '<S86>/Sum' */
  uint32_T Max;                        /* '<S138>/Max' */
  uint32_T ReadGPIODATregister_h;      /* '<S133>/Read GPIO DAT register' */
  uint32_T Hall_C_a;                   /* '<S133>/Hall_C' */
  uint32_T ShiftArithmetic_a;          /* '<S133>/Shift Arithmetic' */
  uint32_T Hall_B_b;                   /* '<S133>/Hall_B' */
  uint32_T ShiftArithmetic1_i;         /* '<S133>/Shift Arithmetic1' */
  uint32_T Hall_A_a;                   /* '<S133>/Hall_A' */
  uint32_T ShiftArithmetic2_e;         /* '<S133>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2_o;         /* '<S133>/Bitwise Operator2' */
  uint32_T MemoryCopy;                 /* '<S131>/Memory Copy' */
  uint32_T MemoryCopy1;                /* '<S131>/Memory Copy1' */
  uint32_T MemoryCopy2;                /* '<S131>/Memory Copy2' */
  uint32_T Min;                        /* '<S131>/Min' */
  uint32_T DataStoreRead2;             /* '<S131>/Data Store Read2' */
  uint32_T IndexVector;                /* '<S122>/Index Vector' */
  uint32_T Add;                        /* '<S122>/Add' */
  uint32_T Data[2];                    /* '<S125>/Data' */
  uint32_T Data_f[2];                  /* '<S126>/Data' */
  uint32_T Data_fw[2];                 /* '<S127>/Data' */
  uint32_T Delay;                      /* '<S102>/Delay' */
  uint32_T Add1;                       /* '<S102>/Add1' */
  real32_T SCIReceive;                 /* '<S171>/SCI Receive' */
  real32_T Merge;                      /* '<S132>/Merge' */
  real32_T Merge1;                     /* '<S132>/Merge1' */
  real32_T Switch_g;                   /* '<S6>/Switch' */
  real32_T TmpSignalConversionAtBytePackIn[2];
  real32_T Merge_j;                    /* '<S109>/Merge' */
  real32_T indexing;                   /* '<S86>/indexing' */
  real32_T Lookup[4];                  /* '<S86>/Lookup' */
  real32_T Sum3;                       /* '<S108>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S86>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S86>/Sum2' */
  real32_T Product;                    /* '<S108>/Product' */
  real32_T Sum4;                       /* '<S108>/Sum4' */
  real32_T Sum5;                       /* '<S108>/Sum5' */
  real32_T Product1;                   /* '<S108>/Product1' */
  real32_T Sum6;                       /* '<S108>/Sum6' */
  real32_T sqrt3_by_two;               /* '<S119>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S119>/one_by_two' */
  real32_T add_c;                      /* '<S119>/add_c' */
  real32_T add_b;                      /* '<S119>/add_b' */
  real32_T Min_a;                      /* '<S116>/Min' */
  real32_T Max_h;                      /* '<S116>/Max' */
  real32_T Add_i;                      /* '<S116>/Add' */
  real32_T one_by_two_b;               /* '<S116>/one_by_two' */
  real32_T Add2;                       /* '<S115>/Add2' */
  real32_T Add1_m;                     /* '<S115>/Add1' */
  real32_T Add3;                       /* '<S115>/Add3' */
  real32_T Gain[3];                    /* '<S115>/Gain' */
  real32_T Sum_d[3];                   /* '<S80>/Sum' */
  real32_T Gain_h[3];                  /* '<S80>/Gain' */
  real32_T currentSpeedData;           /* '<S137>/currentSpeedData' */
  real32_T Divide;                     /* '<S137>/Divide' */
  real32_T SpeedGain;                  /* '<S137>/SpeedGain' */
  real32_T Merge1_m;                   /* '<S150>/Merge1' */
  real32_T Saturation;                 /* '<S150>/Saturation' */
  real32_T Merge_f;                    /* '<S150>/Merge' */
  real32_T countData;                  /* '<S153>/countData' */
  real32_T currentSpeedData_e;         /* '<S153>/currentSpeedData' */
  real32_T Divide_n;                   /* '<S153>/Divide' */
  real32_T countData_k;                /* '<S154>/countData' */
  real32_T previousSpeedData;          /* '<S154>/previousSpeedData' */
  real32_T Divide_b;                   /* '<S154>/Divide' */
  real32_T currentSpeedData_k;         /* '<S154>/currentSpeedData' */
  real32_T Divide1;                    /* '<S154>/Divide1' */
  real32_T Sum_i;                      /* '<S154>/Sum' */
  real32_T Gain1;                      /* '<S154>/Gain1' */
  real32_T Sum1;                       /* '<S154>/Sum1' */
  real32_T Product_g;                  /* '<S154>/Product' */
  real32_T Merge1_p;                   /* '<S151>/Merge1' */
  real32_T Merge1_d;                   /* '<S152>/Merge1' */
  real32_T Input;                      /* '<S88>/Input' */
  real32_T Convert_back;               /* '<S112>/Convert_back' */
  real32_T Convert_back_h;             /* '<S111>/Convert_back' */
  real32_T Merge_fz;                   /* '<S101>/Merge' */
  real32_T UnitDelay;                  /* '<S105>/Unit Delay' */
  real32_T scaleOut;                   /* '<S105>/scaleOut' */
  real32_T Add_j;                      /* '<S106>/Add' */
  real32_T DataTypeConversion1_o;      /* '<S106>/Data Type Conversion1' */
  real32_T Add1_g;                     /* '<S106>/Add1' */
  real32_T Input_h;                    /* '<S107>/Input' */
  real32_T Delay_j;                    /* '<S104>/Delay' */
  real32_T Add1_o;                     /* '<S104>/Add1' */
  real32_T SaturatetomotorcalibSpeedRPM;
                               /* '<S104>/Saturate to 'motor.calibSpeed' RPM' */
  real32_T qcos;                       /* '<S96>/qcos' */
  real32_T dsin;                       /* '<S96>/dsin' */
  real32_T sum_beta;                   /* '<S96>/sum_beta' */
  real32_T dcos;                       /* '<S96>/dcos' */
  real32_T qsin;                       /* '<S96>/qsin' */
  real32_T sum_alpha;                  /* '<S96>/sum_alpha' */
  real32_T Switch_k[2];                /* '<S97>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T Delay_b;                    /* '<S83>/Delay' */
  real32_T OutportBufferForOffset;     /* '<S83>/Subsystem' */
  real32_T Product_j;                  /* '<S95>/Product' */
  real32_T UnitDelay_p;                /* '<S95>/Unit Delay' */
  real32_T Product1_h;                 /* '<S95>/Product1' */
  real32_T Add1_ox;                    /* '<S95>/Add1' */
  uint16_T DataTypeConversion1_b;      /* '<S60>/Data Type Conversion1' */
  uint16_T DataTypeConversion2;        /* '<S60>/Data Type Conversion2' */
  uint16_T DataTypeConversion;         /* '<S64>/Data Type Conversion' */
  uint16_T Merge_b;                    /* '<S64>/Merge' */
  uint16_T DataTypeConversion1_k;      /* '<S42>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_j;      /* '<S42>/Data Type Conversion2' */
  uint16_T DataTypeConversion_d;       /* '<S46>/Data Type Conversion' */
  uint16_T Merge_jr;                   /* '<S46>/Merge' */
  uint16_T DataTypeConversion1_h;      /* '<S24>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_d;      /* '<S24>/Data Type Conversion2' */
  uint16_T DataTypeConversion_h;       /* '<S28>/Data Type Conversion' */
  uint16_T Merge_k;                    /* '<S28>/Merge' */
  uint16_T Switch_a;                   /* '<S132>/Switch' */
  uint16_T Switch_f;                   /* '<S134>/Switch' */
  uint16_T DelayOneStep;               /* '<S135>/Delay One Step' */
  uint16_T watchdogcheck;              /* '<S138>/watchdog check' */
  uint16_T Sum_dm;                     /* '<S135>/Sum' */
  uint16_T Output;                     /* '<S124>/Output' */
  uint16_T FixPtSum1;                  /* '<S128>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S129>/FixPt Switch' */
  uint16_T DataTypeConversion_l;       /* '<S109>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S86>/Get_Integer' */
  uint16_T Switch4[3];                 /* '<S80>/Switch4' */
  uint16_T ADC_B_IN2;                  /* '<S6>/ADC_B_IN2' */
  uint16_T ADC_C_IN2;                  /* '<S6>/ADC_C_IN2' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S80>/Scale_to_PWM_Counter_PRD' */
  uint16_T speedcheck;                 /* '<S138>/speed check' */
  uint16_T DataStoreRead5;             /* '<S131>/Data Store Read5' */
  uint16_T DataStoreRead4;             /* '<S131>/Data Store Read4' */
  int16_T DataStoreRead1;              /* '<S4>/Data Store Read1' */
  int16_T Merge1_dw;                   /* '<S64>/Merge1' */
  int16_T DataStoreRead1_m;            /* '<S3>/Data Store Read1' */
  int16_T Merge1_d2;                   /* '<S46>/Merge1' */
  int16_T DataStoreRead1_d;            /* '<S2>/Data Store Read1' */
  int16_T Merge1_g;                    /* '<S28>/Merge1' */
  int16_T DataStoreRead3;              /* '<S131>/Data Store Read3' */
  int16_T WhileIterator;               /* '<S122>/While Iterator' */
  int16_T Convert_uint16;              /* '<S112>/Convert_uint16' */
  int16_T Convert_uint16_j;            /* '<S111>/Convert_uint16' */
  int16_T DataTypeConversion_f;        /* '<S106>/Data Type Conversion' */
  boolean_T DataTypeConversion_b;      /* '<S7>/Data Type Conversion' */
  boolean_T Merge3;                    /* '<S64>/Merge3' */
  boolean_T Merge_f2;                  /* '<S59>/Merge' */
  boolean_T Merge3_n;                  /* '<S46>/Merge3' */
  boolean_T Merge_n;                   /* '<S41>/Merge' */
  boolean_T Merge3_k;                  /* '<S28>/Merge3' */
  boolean_T Merge_p;                   /* '<S23>/Merge' */
  boolean_T DataTypeConversion4;       /* '<S132>/Data Type Conversion4' */
  boolean_T DataTypeConversion_l3;     /* '<S134>/Data Type Conversion' */
  boolean_T validityDelay;             /* '<S134>/validityDelay' */
  boolean_T DelayOneStep1;             /* '<S135>/Delay One Step1' */
  boolean_T OR;                        /* '<S135>/OR' */
  boolean_T Compare;                   /* '<S139>/Compare' */
  boolean_T DataStoreRead_l;           /* '<S77>/Data Store Read' */
  boolean_T NOT;                       /* '<S77>/NOT' */
  boolean_T Compare_j;                 /* '<S110>/Compare' */
  boolean_T Switch_c;                  /* '<S81>/Switch' */
  boolean_T NOT_o;                     /* '<S81>/NOT' */
  boolean_T LogicalOperator;           /* '<S134>/Logical Operator' */
  boolean_T Compare_b;                 /* '<S98>/Compare' */
  boolean_T NOT_p;                     /* '<S85>/NOT' */
  boolean_T Compare_i;                 /* '<S99>/Compare' */
  boolean_T NOT_h;                     /* '<S105>/NOT' */
  boolean_T Delay_c;                   /* '<S106>/Delay' */
  boolean_T Compare_o;                 /* '<S89>/Compare' */
  boolean_T Compare_jr;                /* '<S90>/Compare' */
  boolean_T AND;                       /* '<S83>/AND' */
  rtB_ValidHalls_mcb_pmsm_hall_of ValidHalls_p;/* '<S64>/Valid Halls' */
  rtB_ValidHalls_mcb_pmsm_hall_of ValidHalls_k;/* '<S46>/Valid Halls' */
  rtB_ValidHalls_mcb_pmsm_hall_of ValidHalls;/* '<S28>/Valid Halls' */
} BlockIO_mcb_pmsm_hall_offset_f2;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint64_T Add1_DWORK1;                /* '<S102>/Add1' */
  real32_T UnitDelay_DSTATE;           /* '<S105>/Unit Delay' */
  real32_T Delay_DSTATE;               /* '<S104>/Delay' */
  real32_T Delay_DSTATE_i;             /* '<S83>/Delay' */
  real32_T UnitDelay_DSTATE_o;         /* '<S95>/Unit Delay' */
  uint32_T Delay_DSTATE_ip;            /* '<S102>/Delay' */
  int32_T DigitalOutput2_FRAC_LEN;     /* '<S5>/Digital Output2' */
  int32_T DRV830xEnable_FRAC_LEN;      /* '<S81>/DRV830x Enable' */
  uint32_T GlobalSpeedCount;           /* '<Root>/Data Store Memory1' */
  uint32_T GlobalHallState;            /* '<Root>/Data Store Memory4' */
  uint32_T Sum_DWORK1[4];              /* '<S86>/Sum' */
  uint32_T Add_DWORK1;                 /* '<S122>/Add' */
  uint16_T DelayOneStep_DSTATE;        /* '<S135>/Delay One Step' */
  uint16_T Output_DSTATE;              /* '<S124>/Output' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory3' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory2' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S135>/Delay One Step1' */
  boolean_T Delay_DSTATE_a;            /* '<S106>/Delay' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T Subsystem1_MODE;           /* '<S77>/Subsystem1' */
  boolean_T PosGen_MODE;               /* '<S77>/PosGen' */
  boolean_T UpCounter_MODE;            /* '<S85>/Up Counter' */
  boolean_T FindOffset_MODE;           /* '<S77>/Find Offset' */
} D_Work_mcb_pmsm_hall_offset_f28;

/* Invariant block signals (default storage) */
typedef struct {
  const uint32_T Width;                /* '<S121>/Width' */
  const real32_T SpeedConstData;       /* '<S137>/SpeedConstData' */
} ConstBlockIO_mcb_pmsm_hall_offs;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S86>/sine_table_values'
   */
  real32_T sine_table_values_Value[1002];
} ConstParam_mcb_pmsm_hall_offset;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_hall_offset_f2 {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern BlockIO_mcb_pmsm_hall_offset_f2 mcb_pmsm_hall_offset_f28379d_B;

/* Block states (default storage) */
extern D_Work_mcb_pmsm_hall_offset_f28 mcb_pmsm_hall_offset_f283_DWork;
extern const ConstBlockIO_mcb_pmsm_hall_offs mcb_pmsm_hall_offset_f28_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_mcb_pmsm_hall_offset mcb_pmsm_hall_offset_f28_ConstP;

/* Model entry point functions */
extern void mcb_pmsm_hall_offset_f28379d_initialize(void);
extern void mcb_pmsm_hall_offset_f28379d_step(void);
extern void mcb_pmsm_hall_offset_f28379d_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_hall_offset_f *const mcb_pmsm_hall_offset_f28379d_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ADCB1_INT(void);
  interrupt void ECAP1_INT(void);
  interrupt void ECAP2_INT(void);
  interrupt void ECAP3_INT(void);
  interrupt void SCIA_RX_INT(void);
  void mcb_pmsm_hall_offset_f28379d_configure_interrupts (void);
  void mcb_pmsm_hall_offset_f28379d_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

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
 * '<Root>' : 'mcb_pmsm_hall_offset_f28379d'
 * '<S1>'   : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt'
 * '<S2>'   : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A'
 * '<S3>'   : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B'
 * '<S4>'   : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C'
 * '<S5>'   : 'mcb_pmsm_hall_offset_f28379d/Heartbeat LED'
 * '<S6>'   : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation'
 * '<S7>'   : 'mcb_pmsm_hall_offset_f28379d/Serial Receive'
 * '<S8>'   : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_ADCB1_INT'
 * '<S9>'   : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_ECAP1_INT'
 * '<S10>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_ECAP2_INT'
 * '<S11>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_ECAP3_INT'
 * '<S12>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_SCIA_RX_INT'
 * '<S13>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_ADCB1_INT/ECSoC'
 * '<S14>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_ADCB1_INT/ECSoC/ECSimCodegen'
 * '<S15>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_ECAP1_INT/ECSoC'
 * '<S16>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_ECAP1_INT/ECSoC/ECSimCodegen'
 * '<S17>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_ECAP2_INT/ECSoC'
 * '<S18>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_ECAP2_INT/ECSoC/ECSimCodegen'
 * '<S19>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_ECAP3_INT/ECSoC'
 * '<S20>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_ECAP3_INT/ECSoC/ECSimCodegen'
 * '<S21>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_SCIA_RX_INT/ECSoC'
 * '<S22>'  : 'mcb_pmsm_hall_offset_f28379d/HW Interrupt/HWI_SCIA_RX_INT/ECSoC/ECSimCodegen'
 * '<S23>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Capture Event Selection'
 * '<S24>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity'
 * '<S25>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Read Halls'
 * '<S26>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Capture Event Selection/Output 0'
 * '<S27>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Capture Event Selection/Output 1'
 * '<S28>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem'
 * '<S29>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S30>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls'
 * '<S31>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S32>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S33>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S34>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S35>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S36>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S37>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S38>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S39>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S40>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S41>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Capture Event Selection'
 * '<S42>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity'
 * '<S43>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Read Halls'
 * '<S44>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Capture Event Selection/Output 0'
 * '<S45>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Capture Event Selection/Output 1'
 * '<S46>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem'
 * '<S47>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S48>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls'
 * '<S49>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S50>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S51>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S52>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S53>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S54>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S55>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S56>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S57>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S58>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S59>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Capture Event Selection'
 * '<S60>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity'
 * '<S61>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Read Halls'
 * '<S62>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Capture Event Selection/Output 0'
 * '<S63>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Capture Event Selection/Output 1'
 * '<S64>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem'
 * '<S65>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S66>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls'
 * '<S67>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S68>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S69>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S70>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S71>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S72>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S73>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S74>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S75>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S76>'  : 'mcb_pmsm_hall_offset_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S77>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System'
 * '<S78>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Data Serial Output'
 * '<S79>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling'
 * '<S80>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Output Scaling'
 * '<S81>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/PWM_Output'
 * '<S82>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Parameters'
 * '<S83>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Find Offset'
 * '<S84>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Inverse Park Transform'
 * '<S85>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/PosGen'
 * '<S86>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup'
 * '<S87>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator'
 * '<S88>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Subsystem1'
 * '<S89>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Find Offset/Compare To Constant'
 * '<S90>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Find Offset/Compare To Constant1'
 * '<S91>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Find Offset/Subsystem'
 * '<S92>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Find Offset/Subsystem/IIR Filter'
 * '<S93>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Find Offset/Subsystem/IIR Filter/IIR Filter'
 * '<S94>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass'
 * '<S95>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S96>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Inverse Park Transform/Two inputs CRL'
 * '<S97>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S98>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/PosGen/Disable host after 22 seconds'
 * '<S99>'  : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/PosGen/Enable PWM for 20 seconds'
 * '<S100>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem'
 * '<S101>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1'
 * '<S102>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/PosGen/Up Counter'
 * '<S103>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1/If Action Subsystem'
 * '<S104>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1/If Action Subsystem2'
 * '<S105>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1/Position Generator'
 * '<S106>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1/Position Generator/Accumulate'
 * '<S107>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/PosGen/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S108>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/Interpolation'
 * '<S109>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/WrapUp'
 * '<S110>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S111>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S112>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S113>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Modulation method'
 * '<S114>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Voltage Input'
 * '<S115>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Modulation method/SVPWM'
 * '<S116>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S117>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S118>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S119>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S120>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Data Serial Output/Data_Conditioning_Tx'
 * '<S121>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging'
 * '<S122>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Data Serial Output/While Iterator Subsystem'
 * '<S123>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Data Serial Output/Data_Conditioning_Tx/Data_Type_Float'
 * '<S124>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging/Counter Limited'
 * '<S125>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging/Data'
 * '<S126>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging/End'
 * '<S127>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging/Start'
 * '<S128>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging/Counter Limited/Increment Real World'
 * '<S129>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Data Serial Output/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S130>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall'
 * '<S131>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Atomic Hall Reading'
 * '<S132>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position'
 * '<S133>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Atomic Hall Reading/Read Halls'
 * '<S134>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/ExtrapolationOrder'
 * '<S135>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Software Watchdog Timer'
 * '<S136>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant'
 * '<S137>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position'
 * '<S138>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/VaidityCheck'
 * '<S139>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Software Watchdog Timer/Compare To Zero'
 * '<S140>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction'
 * '<S141>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 1'
 * '<S142>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 2'
 * '<S143>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 3'
 * '<S144>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 4'
 * '<S145>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 5'
 * '<S146>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 6'
 * '<S147>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 7'
 * '<S148>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem'
 * '<S149>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem1'
 * '<S150>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1'
 * '<S151>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction'
 * '<S152>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction'
 * '<S153>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/first_order'
 * '<S154>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/second_order'
 * '<S155>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 1'
 * '<S156>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 2'
 * '<S157>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 3'
 * '<S158>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 4'
 * '<S159>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 5'
 * '<S160>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 6'
 * '<S161>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 7'
 * '<S162>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 1'
 * '<S163>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 2'
 * '<S164>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 3'
 * '<S165>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 4'
 * '<S166>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 5'
 * '<S167>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 6'
 * '<S168>' : 'mcb_pmsm_hall_offset_f28379d/Offset Calculation/Input Scaling/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 7'
 * '<S169>' : 'mcb_pmsm_hall_offset_f28379d/Serial Receive/Code Generation'
 * '<S170>' : 'mcb_pmsm_hall_offset_f28379d/Serial Receive/Data_Conditioning_Rx'
 * '<S171>' : 'mcb_pmsm_hall_offset_f28379d/Serial Receive/Code Generation/Data_Type_Float'
 * '<S172>' : 'mcb_pmsm_hall_offset_f28379d/Serial Receive/Data_Conditioning_Rx/Data_Type_Float'
 */
#endif                          /* RTW_HEADER_mcb_pmsm_hall_offset_f28379d_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
