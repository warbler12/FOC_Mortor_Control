/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_hall_f28379d.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_hall_f28379d'.
 *
 * Model version                  : 14
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Oct 11 18:36:36 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_mcb_pmsm_foc_hall_f28379d_h_
#define RTW_HEADER_mcb_pmsm_foc_hall_f28379d_h_
#ifndef mcb_pmsm_foc_hall_f28379d_COMMON_INCLUDES_
#define mcb_pmsm_foc_hall_f28379d_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "string.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "DSP28xx_SciUtil.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif                          /* mcb_pmsm_foc_hall_f28379d_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_pmsm_foc_hall_f28379d_types.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
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

/* Block signals for system '<S257>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S259>/Merge' */
  uint16_T Merge1;                     /* '<S259>/Merge1' */
  uint16_T Merge3;                     /* '<S259>/Merge3' */
  int16_T Merge2;                      /* '<S259>/Merge2' */
  boolean_T RelationalOperator;        /* '<S259>/Relational Operator' */
} rtB_ValidHalls_mcb_pmsm_foc_hal;

/* Block signals for system '<S328>/SPI Master Transfer2' */
typedef struct {
  uint16_T SPIMasterTransfer2;         /* '<S328>/SPI Master Transfer2' */
} rtB_SPIMasterTransfer2_mcb_pmsm;

/* Block states (default storage) for system '<S328>/SPI Master Transfer2' */
typedef struct {
  codertarget_tic2000_blocks_SPIM obj; /* '<S328>/SPI Master Transfer2' */
  boolean_T objisempty;                /* '<S328>/SPI Master Transfer2' */
} rtDW_SPIMasterTransfer2_mcb_pms;

/* Block signals for system '<Root>/Speed Control' */
typedef struct {
  real32_T Id_ref;                     /* '<S10>/Id_ref' */
  real32_T Switch;                     /* '<S339>/Switch' */
  real32_T Product;                    /* '<S394>/Product' */
  real32_T UnitDelay;                  /* '<S394>/Unit Delay' */
  real32_T Product1;                   /* '<S394>/Product1' */
  real32_T Add1;                       /* '<S394>/Add1' */
  real32_T Sum;                        /* '<S338>/Sum' */
  real32_T PProdOut;                   /* '<S380>/PProd Out' */
  real32_T Ki2;                        /* '<S338>/Ki2' */
  real32_T Integrator;                 /* '<S375>/Integrator' */
  real32_T Sum_i;                      /* '<S384>/Sum' */
  real32_T DeadZone;                   /* '<S368>/DeadZone' */
  real32_T IProdOut;                   /* '<S372>/IProd Out' */
  real32_T Switch_b;                   /* '<S366>/Switch' */
  real32_T Saturation;                 /* '<S382>/Saturation' */
  int16_T Switch1;                     /* '<S366>/Switch1' */
  int16_T Switch2;                     /* '<S366>/Switch2' */
  boolean_T DataStoreRead2;            /* '<S338>/Data Store Read2' */
  boolean_T DataStoreRead1;            /* '<S339>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S338>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S366>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S366>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S366>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S366>/Equal1' */
  boolean_T AND3;                      /* '<S366>/AND3' */
} rtB_SpeedControl_mcb_pmsm_foc_h;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S394>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S375>/Integrator' */
  int16_T Integrator_PrevResetState;   /* '<S375>/Integrator' */
} rtDW_SpeedControl_mcb_pmsm_foc_;

/* Block signals (default storage) */
typedef struct {
  uint32_T DataStoreRead;              /* '<S5>/Data Store Read' */
  uint32_T ReadGPIODATregister;        /* '<S315>/Read GPIO DAT register' */
  uint32_T Hall_C;                     /* '<S315>/Hall_C' */
  uint32_T ShiftArithmetic;            /* '<S315>/Shift Arithmetic' */
  uint32_T Hall_B;                     /* '<S315>/Hall_B' */
  uint32_T ShiftArithmetic1;           /* '<S315>/Shift Arithmetic1' */
  uint32_T Hall_A;                     /* '<S315>/Hall_A' */
  uint32_T ShiftArithmetic2;           /* '<S315>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2;           /* '<S315>/Bitwise Operator2' */
  uint32_T eCAP[2];                    /* '<S316>/eCAP' */
  uint32_T Switch;                     /* '<S5>/Switch' */
  uint32_T DataStoreRead_o;            /* '<S4>/Data Store Read' */
  uint32_T ReadGPIODATregister_n;      /* '<S293>/Read GPIO DAT register' */
  uint32_T Hall_C_f;                   /* '<S293>/Hall_C' */
  uint32_T ShiftArithmetic_b;          /* '<S293>/Shift Arithmetic' */
  uint32_T Hall_B_m;                   /* '<S293>/Hall_B' */
  uint32_T ShiftArithmetic1_j;         /* '<S293>/Shift Arithmetic1' */
  uint32_T Hall_A_e;                   /* '<S293>/Hall_A' */
  uint32_T ShiftArithmetic2_k;         /* '<S293>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2_m;         /* '<S293>/Bitwise Operator2' */
  uint32_T eCAP_c[2];                  /* '<S294>/eCAP' */
  uint32_T Switch_l;                   /* '<S4>/Switch' */
  uint32_T DataStoreRead_p;            /* '<S3>/Data Store Read' */
  uint32_T ReadGPIODATregister_g;      /* '<S271>/Read GPIO DAT register' */
  uint32_T Hall_C_n;                   /* '<S271>/Hall_C' */
  uint32_T ShiftArithmetic_e;          /* '<S271>/Shift Arithmetic' */
  uint32_T Hall_B_i;                   /* '<S271>/Hall_B' */
  uint32_T ShiftArithmetic1_jb;        /* '<S271>/Shift Arithmetic1' */
  uint32_T Hall_A_k;                   /* '<S271>/Hall_A' */
  uint32_T ShiftArithmetic2_i;         /* '<S271>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2_n;         /* '<S271>/Bitwise Operator2' */
  uint32_T eCAP_l[2];                  /* '<S272>/eCAP' */
  uint32_T Switch_e;                   /* '<S3>/Switch' */
  uint32_T speedCountDelay;            /* '<S177>/speedCountDelay' */
  uint32_T Sum[4];                     /* '<S22>/Sum' */
  uint32_T BytePack[2];                /* '<S227>/Byte Pack' */
  uint32_T SCI_Tx_Data[3];             /* '<S225>/Merge' */
  uint32_T SCI_Tx_Iteration;           /* '<S225>/Merge1' */
  uint32_T IndexVector;                /* '<S226>/Index Vector' */
  uint32_T Add;                        /* '<S226>/Add' */
  uint32_T Data[2];                    /* '<S229>/Data' */
  uint32_T Data_f[2];                  /* '<S230>/Data' */
  uint32_T Data_fw[2];                 /* '<S231>/Data' */
  uint32_T Input;                      /* '<S168>/Input' */
  uint32_T Max;                        /* '<S181>/Max' */
  uint32_T UnitDelay;                  /* '<S171>/Unit Delay' */
  uint32_T Merge;                      /* '<S171>/Merge' */
  uint32_T DataStoreRead2;             /* '<S164>/Data Store Read2' */
  uint32_T ReadGPIODATregister_p;      /* '<S176>/Read GPIO DAT register' */
  uint32_T Hall_C_e;                   /* '<S176>/Hall_C' */
  uint32_T ShiftArithmetic_l;          /* '<S176>/Shift Arithmetic' */
  uint32_T Hall_B_e;                   /* '<S176>/Hall_B' */
  uint32_T ShiftArithmetic1_c;         /* '<S176>/Shift Arithmetic1' */
  uint32_T Hall_A_d;                   /* '<S176>/Hall_A' */
  uint32_T ShiftArithmetic2_kn;        /* '<S176>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2_g;         /* '<S176>/Bitwise Operator2' */
  uint32_T MemoryCopy;                 /* '<S170>/Memory Copy' */
  uint32_T MemoryCopy1;                /* '<S170>/Memory Copy1' */
  uint32_T MemoryCopy2;                /* '<S170>/Memory Copy2' */
  uint32_T Min;                        /* '<S170>/Min' */
  uint32_T ReadGPIODATregister_nt;     /* '<S172>/Read GPIO DAT register' */
  uint32_T Hall_C_fc;                  /* '<S172>/Hall_C' */
  uint32_T ShiftArithmetic_p;          /* '<S172>/Shift Arithmetic' */
  uint32_T Hall_B_f;                   /* '<S172>/Hall_B' */
  uint32_T ShiftArithmetic1_h;         /* '<S172>/Shift Arithmetic1' */
  uint32_T Hall_A_c;                   /* '<S172>/Hall_A' */
  uint32_T ShiftArithmetic2_e;         /* '<S172>/Shift Arithmetic2' */
  uint32_T BitwiseOperator2_p;         /* '<S172>/Bitwise Operator2' */
  real32_T RT1;                        /* '<Root>/RT1' */
  real32_T RT6;                        /* '<Root>/RT6' */
  real32_T RT7;                        /* '<Root>/RT7' */
  real32_T RT2[2];                     /* '<Root>/RT2' */
  real32_T SCIReceive[2];              /* '<S337>/SCI Receive' */
  real32_T Merge_d;                    /* '<S166>/Merge' */
  real32_T Merge1;                     /* '<S166>/Merge1' */
  real32_T Switch_h;                   /* '<S213>/Switch' */
  real32_T Merge_m;                    /* '<S214>/Merge' */
  real32_T Floor;                      /* '<S215>/Floor' */
  real32_T Add_e;                      /* '<S215>/Add' */
  real32_T GetADCVoltage[2];           /* '<S221>/Get ADC Voltage' */
  real32_T GetCurrents[2];             /* '<S221>/Get Currents' */
  real32_T PU_Conversion[2];           /* '<S221>/PU_Conversion' */
  real32_T DataStoreRead1;             /* '<S12>/Data Store Read1' */
  real32_T Merge_j;                    /* '<S150>/Merge' */
  real32_T indexing;                   /* '<S22>/indexing' */
  real32_T Lookup[4];                  /* '<S22>/Lookup' */
  real32_T Sum3;                       /* '<S149>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S22>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S22>/Sum2' */
  real32_T Product;                    /* '<S149>/Product' */
  real32_T Sum4;                       /* '<S149>/Sum4' */
  real32_T Sum5;                       /* '<S149>/Sum5' */
  real32_T Product1;                   /* '<S149>/Product1' */
  real32_T Sum6;                       /* '<S149>/Sum6' */
  real32_T TmpSignalConversionAtSelectorIn[9];
  real32_T Selector[2];                /* '<S12>/Selector' */
  real32_T Sum_g;                      /* '<S28>/Sum' */
  real32_T PProdOut;                   /* '<S133>/PProd Out' */
  real32_T Kp1;                        /* '<S28>/Kp1' */
  real32_T Integrator;                 /* '<S128>/Integrator' */
  real32_T Sum_m;                      /* '<S137>/Sum' */
  real32_T Saturation;                 /* '<S135>/Saturation' */
  real32_T Sum_b;                      /* '<S27>/Sum' */
  real32_T PProdOut_b;                 /* '<S82>/PProd Out' */
  real32_T Ki1;                        /* '<S27>/Ki1' */
  real32_T Integrator_o;               /* '<S77>/Integrator' */
  real32_T Sum_h;                      /* '<S86>/Sum' */
  real32_T Saturation_j;               /* '<S84>/Saturation' */
  real32_T Switch_j;                   /* '<S31>/Switch' */
  real32_T Product_b;                  /* '<S31>/Product' */
  real32_T Product_e;                  /* '<S32>/Product' */
  real32_T Product1_b;                 /* '<S32>/Product1' */
  real32_T Sum1;                       /* '<S32>/Sum1' */
  real32_T Merge_do[2];                /* '<S26>/Merge' */
  real32_T DeadZone;                   /* '<S70>/DeadZone' */
  real32_T IProdOut;                   /* '<S74>/IProd Out' */
  real32_T Switch_b;                   /* '<S68>/Switch' */
  real32_T DeadZone_g;                 /* '<S121>/DeadZone' */
  real32_T IProdOut_h;                 /* '<S125>/IProd Out' */
  real32_T Switch_ls;                  /* '<S119>/Switch' */
  real32_T DataTypeConversion;         /* '<S15>/Data Type Conversion' */
  real32_T Switch_f;                   /* '<S222>/Switch' */
  real32_T Speed_PU;                   /* '<S1>/Input Scaling' */
  real32_T sqrt3_by_two;               /* '<S160>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S160>/one_by_two' */
  real32_T add_c;                      /* '<S160>/add_c' */
  real32_T add_b;                      /* '<S160>/add_b' */
  real32_T Min_a;                      /* '<S157>/Min' */
  real32_T Max_h;                      /* '<S157>/Max' */
  real32_T Add_i;                      /* '<S157>/Add' */
  real32_T one_by_two_b;               /* '<S157>/one_by_two' */
  real32_T Add3;                       /* '<S156>/Add3' */
  real32_T Add2;                       /* '<S156>/Add2' */
  real32_T Add1;                       /* '<S156>/Add1' */
  real32_T Gain[3];                    /* '<S156>/Gain' */
  real32_T Gain_m[3];                  /* '<S15>/Gain' */
  real32_T PWM_Duty_Cycles[3];         /* '<S15>/Sum' */
  real32_T currentSpeedData;           /* '<S180>/currentSpeedData' */
  real32_T Divide;                     /* '<S180>/Divide' */
  real32_T SpeedGain;                  /* '<S180>/SpeedGain' */
  real32_T Merge1_l;                   /* '<S193>/Merge1' */
  real32_T Saturation_k;               /* '<S193>/Saturation' */
  real32_T Merge_c;                    /* '<S193>/Merge' */
  real32_T countData;                  /* '<S196>/countData' */
  real32_T currentSpeedData_k;         /* '<S196>/currentSpeedData' */
  real32_T Divide_f;                   /* '<S196>/Divide' */
  real32_T countData_o;                /* '<S197>/countData' */
  real32_T previousSpeedData;          /* '<S197>/previousSpeedData' */
  real32_T Divide_i;                   /* '<S197>/Divide' */
  real32_T currentSpeedData_o;         /* '<S197>/currentSpeedData' */
  real32_T Divide1;                    /* '<S197>/Divide1' */
  real32_T Sum_n;                      /* '<S197>/Sum' */
  real32_T Gain1;                      /* '<S197>/Gain1' */
  real32_T Sum1_i;                     /* '<S197>/Sum1' */
  real32_T Product_i;                  /* '<S197>/Product' */
  real32_T Merge1_la;                  /* '<S194>/Merge1' */
  real32_T Merge1_d;                   /* '<S195>/Merge1' */
  real32_T Convert_back;               /* '<S153>/Convert_back' */
  real32_T Convert_back_h;             /* '<S152>/Convert_back' */
  real32_T acos_e;                     /* '<S147>/acos' */
  real32_T bsin;                       /* '<S147>/bsin' */
  real32_T sum_Ds;                     /* '<S147>/sum_Ds' */
  real32_T bcos;                       /* '<S147>/bcos' */
  real32_T asin_j;                     /* '<S147>/asin' */
  real32_T sum_Qs;                     /* '<S147>/sum_Qs' */
  real32_T Switch_fd[2];               /* '<S148>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T qcos;                       /* '<S145>/qcos' */
  real32_T dsin;                       /* '<S145>/dsin' */
  real32_T sum_beta;                   /* '<S145>/sum_beta' */
  real32_T dcos;                       /* '<S145>/dcos' */
  real32_T qsin;                       /* '<S145>/qsin' */
  real32_T sum_alpha;                  /* '<S145>/sum_alpha' */
  real32_T Switch_k[2];                /* '<S146>/Switch' */
  real32_T algDD_o1_c;
  real32_T algDD_o2_e;
  real32_T Product_ie[2];              /* '<S33>/Product' */
  real32_T SquareRoot;                 /* '<S33>/Square Root' */
  real32_T Switch_o;                   /* '<S33>/Switch' */
  real32_T Reciprocal;                 /* '<S33>/Reciprocal' */
  real32_T Switch_hp[2];               /* '<S30>/Switch' */
  real32_T Switch2;                    /* '<S40>/Switch2' */
  real32_T Product_a;                  /* '<S39>/Product' */
  real32_T Sum_nl;                     /* '<S39>/Sum' */
  real32_T Product2;                   /* '<S39>/Product2' */
  real32_T Merge_me;                   /* '<S39>/Merge' */
  real32_T Gain_e;                     /* '<S39>/Gain' */
  real32_T Switch_c;                   /* '<S40>/Switch' */
  real32_T Switch1;                    /* '<S41>/Switch1' */
  real32_T Sqrt;                       /* '<S41>/Sqrt' */
  real32_T Gain_c;                     /* '<S41>/Gain' */
  real32_T a_plus_2b;                  /* '<S25>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S25>/one_by_sqrt3' */
  real32_T algDD_o1_a;
  real32_T algDD_o2_n;
  int32_T DataTypeConversion_f[2];     /* '<S163>/Data Type Conversion' */
  int32_T Add_f[2];                    /* '<S163>/Add' */
  uint16_T Divide_ir;                  /* '<S319>/Divide' */
  uint16_T Divide1_e;                  /* '<S319>/Divide1' */
  uint16_T ForIterator;                /* '<S322>/For Iterator' */
  uint16_T ADC_A_IN0;                  /* '<S322>/ADC_A_IN0' */
  uint16_T ADC_B_IN0;                  /* '<S322>/ADC_B_IN0' */
  uint16_T Memory;                     /* '<S327>/Memory' */
  uint16_T Sum_i;                      /* '<S327>/Sum' */
  uint16_T Memory1;                    /* '<S327>/Memory1' */
  uint16_T Sum1_j;                     /* '<S327>/Sum1' */
  uint16_T DataTypeConversion2;        /* '<S335>/Data Type Conversion2' */
  uint16_T BitwiseOperator;            /* '<S334>/Bitwise Operator' */
  uint16_T BitwiseOperator1;           /* '<S334>/Bitwise Operator1' */
  uint16_T ShiftArithmetic1_d;         /* '<S334>/Shift Arithmetic1' */
  uint16_T DataTypeConversion1_o;      /* '<S296>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_p;      /* '<S296>/Data Type Conversion2' */
  uint16_T DataTypeConversion_n;       /* '<S301>/Data Type Conversion' */
  uint16_T Merge_p;                    /* '<S301>/Merge' */
  uint16_T DataTypeConversion1_n;      /* '<S274>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_g;      /* '<S274>/Data Type Conversion2' */
  uint16_T DataTypeConversion_j;       /* '<S279>/Data Type Conversion' */
  uint16_T Merge_ji;                   /* '<S279>/Merge' */
  uint16_T DataTypeConversion1_d;      /* '<S252>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_c;      /* '<S252>/Data Type Conversion2' */
  uint16_T DataTypeConversion_p;       /* '<S257>/Data Type Conversion' */
  uint16_T Merge_k;                    /* '<S257>/Merge' */
  uint16_T Switch_a;                   /* '<S166>/Switch' */
  uint16_T Switch_m;                   /* '<S177>/Switch' */
  uint16_T DelayOneStep;               /* '<S178>/Delay One Step' */
  uint16_T watchdogcheck;              /* '<S181>/watchdog check' */
  uint16_T Sum_m3;                     /* '<S178>/Sum' */
  uint16_T DataStoreRead_k;            /* '<S163>/Data Store Read' */
  uint16_T DataStoreRead1_h;           /* '<S163>/Data Store Read1' */
  uint16_T ADC_C_IN2;                  /* '<S234>/ADC_C_IN2' */
  uint16_T ADC_B_IN2;                  /* '<S234>/ADC_B_IN2' */
  uint16_T Output;                     /* '<S228>/Output' */
  uint16_T DataTypeConversion_l;       /* '<S150>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S22>/Get_Integer' */
  uint16_T DataStoreRead_g;            /* '<S12>/Data Store Read' */
  uint16_T MultiportSwitch[2];         /* '<S12>/Multiport Switch' */
  uint16_T FixPtSum1;                  /* '<S232>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S233>/FixPt Switch' */
  uint16_T Switch1_o;                  /* '<S31>/Switch1' */
  uint16_T Switch1_f[3];               /* '<S222>/Switch1' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S222>/Scale_to_PWM_Counter_PRD' */
  uint16_T speedcheck;                 /* '<S181>/speed check' */
  uint16_T DataStoreRead5;             /* '<S164>/Data Store Read5' */
  uint16_T DataStoreRead4;             /* '<S164>/Data Store Read4' */
  uint16_T DataTypeConversion_jg;      /* '<S29>/Data Type Conversion' */
  uint16_T DataTypeConversion_nl;      /* '<S39>/Data Type Conversion' */
  int16_T DataStoreRead1_k;            /* '<S5>/Data Store Read1' */
  int16_T Merge1_k;                    /* '<S301>/Merge1' */
  int16_T DataStoreRead1_kl;           /* '<S4>/Data Store Read1' */
  int16_T Merge1_a;                    /* '<S279>/Merge1' */
  int16_T DataStoreRead1_o;            /* '<S3>/Data Store Read1' */
  int16_T Merge1_kl;                   /* '<S257>/Merge1' */
  int16_T WhileIterator;               /* '<S226>/While Iterator' */
  int16_T DataStoreRead3;              /* '<S164>/Data Store Read3' */
  int16_T Convert_uint16;              /* '<S153>/Convert_uint16' */
  int16_T Convert_uint16_j;            /* '<S152>/Convert_uint16' */
  uint16_T Compare;                    /* '<S173>/Compare' */
  int16_T Switch1_i;                   /* '<S68>/Switch1' */
  int16_T Switch2_a;                   /* '<S68>/Switch2' */
  int16_T Switch1_j;                   /* '<S119>/Switch1' */
  int16_T Switch2_b;                   /* '<S119>/Switch2' */
  boolean_T Switch_bt;                 /* '<S320>/Switch' */
  boolean_T NOT;                       /* '<S318>/NOT' */
  boolean_T DataTypeConversion3;       /* '<S334>/Data Type Conversion3' */
  boolean_T Merge3;                    /* '<S301>/Merge3' */
  boolean_T Merge_pt;                  /* '<S295>/Merge' */
  boolean_T Merge3_o;                  /* '<S279>/Merge3' */
  boolean_T Merge_f;                   /* '<S273>/Merge' */
  boolean_T Merge3_m;                  /* '<S257>/Merge3' */
  boolean_T Merge_n;                   /* '<S251>/Merge' */
  boolean_T Compare_e;                 /* '<S165>/Compare' */
  boolean_T DataTypeConversion4;       /* '<S166>/Data Type Conversion4' */
  boolean_T DataTypeConversion_nh;     /* '<S177>/Data Type Conversion' */
  boolean_T validityDelay;             /* '<S177>/validityDelay' */
  boolean_T DelayOneStep1;             /* '<S178>/Delay One Step1' */
  boolean_T OR;                        /* '<S178>/OR' */
  boolean_T Compare_n;                 /* '<S182>/Compare' */
  boolean_T Compare_j;                 /* '<S151>/Compare' */
  boolean_T DataStoreRead1_b;          /* '<S28>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S28>/Logical Operator' */
  boolean_T DataStoreRead1_g;          /* '<S27>/Data Store Read1' */
  boolean_T LogicalOperator_j;         /* '<S27>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S68>/Relational Operator' */
  boolean_T fixforDTpropagationissue; /* '<S68>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                     /* '<S68>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S68>/Equal1' */
  boolean_T AND3;                      /* '<S68>/AND3' */
  boolean_T RelationalOperator_m;      /* '<S119>/Relational Operator' */
  boolean_T fixforDTpropagationissue_b;
                                     /* '<S119>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_h;
                                    /* '<S119>/fix for DT propagation issue1' */
  boolean_T Equal1_d;                  /* '<S119>/Equal1' */
  boolean_T AND3_f;                    /* '<S119>/AND3' */
  boolean_T Enable;                    /* '<S15>/Enable' */
  boolean_T LogicalOperator_a;         /* '<S177>/Logical Operator' */
  boolean_T RelationalOperator_k;      /* '<S171>/Relational Operator' */
  boolean_T NOT_b;                     /* '<S171>/NOT' */
  boolean_T RelationalOperator_h;      /* '<S29>/Relational Operator' */
  boolean_T Compare_h;                 /* '<S35>/Compare' */
  boolean_T Compare_nf;                /* '<S36>/Compare' */
  boolean_T LowerRelop1;               /* '<S40>/LowerRelop1' */
  boolean_T RelationalOperator_i;      /* '<S39>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S40>/UpperRelop' */
  rtB_SpeedControl_mcb_pmsm_foc_h SpeedControl;/* '<Root>/Speed Control' */
  rtB_SPIMasterTransfer2_mcb_pmsm SPIMasterTransfer3;/* '<S328>/SPI Master Transfer2' */
  rtB_SPIMasterTransfer2_mcb_pmsm SPIMasterTransfer2;/* '<S328>/SPI Master Transfer2' */
  rtB_ValidHalls_mcb_pmsm_foc_hal ValidHalls_hi;/* '<S301>/Valid Halls' */
  rtB_ValidHalls_mcb_pmsm_foc_hal ValidHalls_h;/* '<S279>/Valid Halls' */
  rtB_ValidHalls_mcb_pmsm_foc_hal ValidHalls;/* '<S257>/Valid Halls' */
} BlockIO_mcb_pmsm_foc_hall_f2837;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S128>/Integrator' */
  real32_T Integrator_DSTATE_j;        /* '<S77>/Integrator' */
  uint32_T UnitDelay_DSTATE;           /* '<S171>/Unit Delay' */
  volatile real32_T RT1_Buffer[2];     /* '<Root>/RT1' */
  volatile real32_T RT6_Buffer[2];     /* '<Root>/RT6' */
  volatile real32_T RT2_Buffer[4];     /* '<Root>/RT2' */
  real32_T Speed_ref;                  /* '<Root>/Data Store Memory8' */
  int32_T DigitalOutput2_FRAC_LEN;     /* '<S330>/Digital Output2' */
  int32_T DRV830xEnable_FRAC_LEN;      /* '<S320>/DRV830x Enable' */
  int32_T Add_DWORK1[2];               /* '<S163>/Add' */
  int32_T InverterEnable_FRAC_LEN;     /* '<S222>/Inverter Enable' */
  uint32_T GlobalSpeedCount;           /* '<Root>/Data Store Memory1' */
  uint32_T GlobalHallState;            /* '<Root>/Data Store Memory4' */
  uint32_T Sum_DWORK1[4];              /* '<S22>/Sum' */
  uint32_T Add_DWORK1_j;               /* '<S226>/Add' */
  uint16_T DelayOneStep_DSTATE;        /* '<S178>/Delay One Step' */
  uint16_T Output_DSTATE;              /* '<S228>/Output' */
  volatile int16_T RT1_ActiveBufIdx;   /* '<Root>/RT1' */
  volatile int16_T RT1_semaphoreTaken; /* '<Root>/RT1' */
  volatile int16_T RT6_ActiveBufIdx;   /* '<Root>/RT6' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory3' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory2' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory5' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory6' */
  uint16_T Debug_signals;              /* '<Root>/Data Store Memory7' */
  uint16_T Memory_PreviousInput;       /* '<S327>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S327>/Memory1' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S178>/Delay One Step1' */
  int16_T Integrator_PrevResetState;   /* '<S128>/Integrator' */
  int16_T Integrator_PrevResetState_m; /* '<S77>/Integrator' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  rtDW_SpeedControl_mcb_pmsm_foc_ SpeedControl;/* '<Root>/Speed Control' */
  rtDW_SPIMasterTransfer2_mcb_pms SPIMasterTransfer3;/* '<S328>/SPI Master Transfer2' */
  rtDW_SPIMasterTransfer2_mcb_pms SPIMasterTransfer2;/* '<S328>/SPI Master Transfer2' */
} D_Work_mcb_pmsm_foc_hall_f28379;

/* Invariant block signals (default storage) */
typedef struct {
  const uint32_T Width;                /* '<S225>/Width' */
  const real32_T SpeedConstData;       /* '<S180>/SpeedConstData' */
} ConstBlockIO_mcb_pmsm_foc_hall_;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S22>/sine_table_values'
   */
  real32_T sine_table_values_Value[1002];
} ConstParam_mcb_pmsm_foc_hall_f2;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_foc_hall_f2837 {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern BlockIO_mcb_pmsm_foc_hall_f2837 mcb_pmsm_foc_hall_f28379d_B;

/* Block states (default storage) */
extern D_Work_mcb_pmsm_foc_hall_f28379 mcb_pmsm_foc_hall_f28379d_DWork;
extern const ConstBlockIO_mcb_pmsm_foc_hall_ mcb_pmsm_foc_hall_f28379_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_mcb_pmsm_foc_hall_f2 mcb_pmsm_foc_hall_f28379_ConstP;

/* External function called from main */
extern void mcb_pmsm_foc_hall_f28379d_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void mcb_pmsm_foc_hall_f28379d_initialize(void);
extern void mcb_pmsm_foc_hall_f28379d_step0(void);
extern void mcb_pmsm_foc_hall_f28379d_step1(void);
extern void mcb_pmsm_foc_hall_f28379d_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_foc_hall_f283 *const mcb_pmsm_foc_hall_f28379d_M;
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
  void mcb_pmsm_foc_hall_f28379d_configure_interrupts (void);
  void mcb_pmsm_foc_hall_f28379d_unconfigure_interrupts (void);

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
 * '<Root>' : 'mcb_pmsm_foc_hall_f28379d'
 * '<S1>'   : 'mcb_pmsm_foc_hall_f28379d/Current Control'
 * '<S2>'   : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt'
 * '<S3>'   : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A'
 * '<S4>'   : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B'
 * '<S5>'   : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C'
 * '<S6>'   : 'mcb_pmsm_foc_hall_f28379d/Hardware Init'
 * '<S7>'   : 'mcb_pmsm_foc_hall_f28379d/Heartbeat LED'
 * '<S8>'   : 'mcb_pmsm_foc_hall_f28379d/Inverter and Motor - Plant Model'
 * '<S9>'   : 'mcb_pmsm_foc_hall_f28379d/Serial Receive'
 * '<S10>'  : 'mcb_pmsm_foc_hall_f28379d/Speed Control'
 * '<S11>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System'
 * '<S12>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Debug_signals'
 * '<S13>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling'
 * '<S14>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Inverter'
 * '<S15>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Output Scaling'
 * '<S16>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/SCI_Tx'
 * '<S17>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Sensor Driver Blocks'
 * '<S18>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Clarke Transform'
 * '<S19>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers'
 * '<S20>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Inverse Park Transform'
 * '<S21>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Park Transform'
 * '<S22>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Sine-Cosine Lookup'
 * '<S23>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Space Vector Generator'
 * '<S24>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Clarke Transform/Two phase input'
 * '<S25>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S26>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter'
 * '<S27>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id'
 * '<S28>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq'
 * '<S29>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S30>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S31>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S32>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S33>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S34>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S35>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S36>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S37>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S38>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S39>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S40>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S41>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S42>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S43>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S44>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S45>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S46>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S47>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S48>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S49>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S50>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S51>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S52>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S53>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S54>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S55>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S56>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S57>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S58>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S59>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S60>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S61>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S62>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S63>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S64>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S65>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S66>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S67>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S68>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S69>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S70>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S71>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S72>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S73>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S74>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S75>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S76>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S77>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S78>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S79>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S80>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S81>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S82>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S83>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S84>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S85>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S86>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S87>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S88>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S89>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S90>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S91>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S92>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S93>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S94>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S95>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S96>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S97>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S98>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S99>'  : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S100>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S101>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S102>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S103>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S104>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S105>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S106>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S107>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S108>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S109>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S110>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S111>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S112>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S113>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S114>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S115>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S116>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S117>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S118>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S119>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S120>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S121>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S122>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S123>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S124>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S125>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S126>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S127>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S128>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S129>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S130>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S131>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S132>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S133>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S134>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S135>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S136>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S137>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S138>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S139>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S140>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S141>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S142>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S143>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S144>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S145>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Inverse Park Transform/Two inputs CRL'
 * '<S146>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S147>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Park Transform/Two inputs CRL'
 * '<S148>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S149>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Sine-Cosine Lookup/Interpolation'
 * '<S150>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Sine-Cosine Lookup/WrapUp'
 * '<S151>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S152>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S153>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S154>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Space Vector Generator/Modulation method'
 * '<S155>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Space Vector Generator/Voltage Input'
 * '<S156>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Space Vector Generator/Modulation method/SVPWM'
 * '<S157>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S158>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S159>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S160>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S161>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)'
 * '<S162>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall'
 * '<S163>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Convert ADC value to PU'
 * '<S164>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading'
 * '<S165>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Glitch Filter'
 * '<S166>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position'
 * '<S167>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position1'
 * '<S168>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Subsystem'
 * '<S169>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Function-Call Subsystem'
 * '<S170>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Function-Call Subsystem1'
 * '<S171>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Integrity_Check'
 * '<S172>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Function-Call Subsystem/Read Halls'
 * '<S173>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Integrity_Check/Compare To Constant'
 * '<S174>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Integrity_Check/No_Integrity_issue'
 * '<S175>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Integrity_Check/Refresh_Halls'
 * '<S176>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Integrity_Check/Refresh_Halls/Read Halls'
 * '<S177>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/ExtrapolationOrder'
 * '<S178>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Software Watchdog Timer'
 * '<S179>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant'
 * '<S180>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position'
 * '<S181>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/VaidityCheck'
 * '<S182>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Software Watchdog Timer/Compare To Zero'
 * '<S183>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction'
 * '<S184>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 1'
 * '<S185>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 2'
 * '<S186>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 3'
 * '<S187>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 4'
 * '<S188>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 5'
 * '<S189>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 6'
 * '<S190>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 7'
 * '<S191>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem'
 * '<S192>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem1'
 * '<S193>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1'
 * '<S194>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction'
 * '<S195>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction'
 * '<S196>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/first_order'
 * '<S197>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/second_order'
 * '<S198>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 1'
 * '<S199>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 2'
 * '<S200>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 3'
 * '<S201>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 4'
 * '<S202>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 5'
 * '<S203>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 6'
 * '<S204>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 7'
 * '<S205>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 1'
 * '<S206>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 2'
 * '<S207>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 3'
 * '<S208>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 4'
 * '<S209>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 5'
 * '<S210>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 6'
 * '<S211>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 7'
 * '<S212>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position1/MechToElec'
 * '<S213>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position1/MechToElec/floating-point'
 * '<S214>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position1/MechToElec/floating-point/Compensate Offset'
 * '<S215>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position1/MechToElec/floating-point/Mech To Elec'
 * '<S216>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position1/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S217>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position1/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S218>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position1/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S219>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position1/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S220>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Convert ADC value to PU/Data_Type'
 * '<S221>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Input Scaling/Read_Sensor (codegen)/Convert ADC value to PU/Data_Type/Data_Type_Float'
 * '<S222>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Inverter/Code Generation'
 * '<S223>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/SCI_Tx/Code Generation'
 * '<S224>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/SCI_Tx/Code Generation/Data_Conditioning_Tx'
 * '<S225>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging'
 * '<S226>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/SCI_Tx/Code Generation/While Iterator Subsystem'
 * '<S227>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/SCI_Tx/Code Generation/Data_Conditioning_Tx/Data_Type_Float'
 * '<S228>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Counter Limited'
 * '<S229>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Data'
 * '<S230>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/End'
 * '<S231>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Start'
 * '<S232>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Counter Limited/Increment Real World'
 * '<S233>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/SCI_Tx/Code Generation/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S234>' : 'mcb_pmsm_foc_hall_f28379d/Current Control/Sensor Driver Blocks/Sensor Driver Blocks (codegen)'
 * '<S235>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation'
 * '<S236>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_ADCB1_INT'
 * '<S237>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_ECAP1_INT'
 * '<S238>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_ECAP2_INT'
 * '<S239>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_ECAP3_INT'
 * '<S240>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_SCIA_RX_INT'
 * '<S241>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_ADCB1_INT/ECSoC'
 * '<S242>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_ADCB1_INT/ECSoC/ECSimCodegen'
 * '<S243>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_ECAP1_INT/ECSoC'
 * '<S244>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_ECAP1_INT/ECSoC/ECSimCodegen'
 * '<S245>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_ECAP2_INT/ECSoC'
 * '<S246>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_ECAP2_INT/ECSoC/ECSimCodegen'
 * '<S247>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_ECAP3_INT/ECSoC'
 * '<S248>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_ECAP3_INT/ECSoC/ECSimCodegen'
 * '<S249>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_SCIA_RX_INT/ECSoC'
 * '<S250>' : 'mcb_pmsm_foc_hall_f28379d/HW Interrupt/Code Generation/HWI_SCIA_RX_INT/ECSoC/ECSimCodegen'
 * '<S251>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Capture Event Selection'
 * '<S252>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity'
 * '<S253>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/HallValidity'
 * '<S254>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/eCAP'
 * '<S255>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Capture Event Selection/Output 0'
 * '<S256>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Capture Event Selection/Output 1'
 * '<S257>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem'
 * '<S258>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S259>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls'
 * '<S260>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S261>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S262>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S263>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S264>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S265>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S266>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S267>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S268>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S269>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S270>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/HallValidity/CodeGen'
 * '<S271>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/HallValidity/CodeGen/Read Halls'
 * '<S272>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor A/eCAP/Code generation'
 * '<S273>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Capture Event Selection'
 * '<S274>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity'
 * '<S275>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/HallValidity'
 * '<S276>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/eCAP'
 * '<S277>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Capture Event Selection/Output 0'
 * '<S278>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Capture Event Selection/Output 1'
 * '<S279>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem'
 * '<S280>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S281>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls'
 * '<S282>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S283>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S284>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S285>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S286>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S287>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S288>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S289>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S290>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S291>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S292>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/HallValidity/CodeGen'
 * '<S293>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/HallValidity/CodeGen/Read Halls'
 * '<S294>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor B/eCAP/Code generation'
 * '<S295>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Capture Event Selection'
 * '<S296>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity'
 * '<S297>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/HallValidity'
 * '<S298>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/eCAP'
 * '<S299>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Capture Event Selection/Output 0'
 * '<S300>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Capture Event Selection/Output 1'
 * '<S301>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem'
 * '<S302>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S303>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls'
 * '<S304>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S305>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S306>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S307>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S308>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S309>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S310>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S311>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S312>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S313>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S314>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/HallValidity/CodeGen'
 * '<S315>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/HallValidity/CodeGen/Read Halls'
 * '<S316>' : 'mcb_pmsm_foc_hall_f28379d/Hall Sensor C/eCAP/Code generation'
 * '<S317>' : 'mcb_pmsm_foc_hall_f28379d/Hardware Init/Variant Subsystem'
 * '<S318>' : 'mcb_pmsm_foc_hall_f28379d/Hardware Init/Variant Subsystem/Code Generation'
 * '<S319>' : 'mcb_pmsm_foc_hall_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset '
 * '<S320>' : 'mcb_pmsm_foc_hall_f28379d/Hardware Init/Variant Subsystem/Code Generation/DRV Enable'
 * '<S321>' : 'mcb_pmsm_foc_hall_f28379d/Hardware Init/Variant Subsystem/Code Generation/Default ADC Offset'
 * '<S322>' : 'mcb_pmsm_foc_hall_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem'
 * '<S323>' : 'mcb_pmsm_foc_hall_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem'
 * '<S324>' : 'mcb_pmsm_foc_hall_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem1'
 * '<S325>' : 'mcb_pmsm_foc_hall_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem2'
 * '<S326>' : 'mcb_pmsm_foc_hall_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem3'
 * '<S327>' : 'mcb_pmsm_foc_hall_f28379d/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S328>' : 'mcb_pmsm_foc_hall_f28379d/Hardware Init/Variant Subsystem/Code Generation/DRV Enable/ADC Gain Setting'
 * '<S329>' : 'mcb_pmsm_foc_hall_f28379d/Heartbeat LED/Heartbeat LED'
 * '<S330>' : 'mcb_pmsm_foc_hall_f28379d/Heartbeat LED/Heartbeat LED/Code generation'
 * '<S331>' : 'mcb_pmsm_foc_hall_f28379d/Inverter and Motor - Plant Model/Codegeneration'
 * '<S332>' : 'mcb_pmsm_foc_hall_f28379d/Serial Receive/Data_Conditioning_Rx'
 * '<S333>' : 'mcb_pmsm_foc_hall_f28379d/Serial Receive/SCI_Rx'
 * '<S334>' : 'mcb_pmsm_foc_hall_f28379d/Serial Receive/unParse'
 * '<S335>' : 'mcb_pmsm_foc_hall_f28379d/Serial Receive/Data_Conditioning_Rx/Data_Type_Float'
 * '<S336>' : 'mcb_pmsm_foc_hall_f28379d/Serial Receive/SCI_Rx/Code Generation'
 * '<S337>' : 'mcb_pmsm_foc_hall_f28379d/Serial Receive/SCI_Rx/Code Generation/Data_Type_Float'
 * '<S338>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed'
 * '<S339>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/Speed_Ref_Selector'
 * '<S340>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S341>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S342>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S343>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S344>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S345>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S346>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S347>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S348>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S349>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S350>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S351>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S352>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S353>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S354>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S355>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S356>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S357>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S358>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S359>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S360>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S361>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S362>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S363>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S364>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S365>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S366>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S367>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S368>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S369>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S370>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S371>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S372>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S373>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S374>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S375>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S376>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S377>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S378>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S379>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S380>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S381>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S382>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S383>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S384>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S385>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S386>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S387>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S388>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S389>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S390>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S391>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S392>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S393>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S394>' : 'mcb_pmsm_foc_hall_f28379d/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                             /* RTW_HEADER_mcb_pmsm_foc_hall_f28379d_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
