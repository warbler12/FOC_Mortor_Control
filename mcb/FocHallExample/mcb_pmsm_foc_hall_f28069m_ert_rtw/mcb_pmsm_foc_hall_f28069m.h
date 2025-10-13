/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_hall_f28069m.h
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

#ifndef RTW_HEADER_mcb_pmsm_foc_hall_f28069m_h_
#define RTW_HEADER_mcb_pmsm_foc_hall_f28069m_h_
#ifndef mcb_pmsm_foc_hall_f28069m_COMMON_INCLUDES_
#define mcb_pmsm_foc_hall_f28069m_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "DSP28xx_SciUtil.h"
#include "IQmathLib.h"
#endif                          /* mcb_pmsm_foc_hall_f28069m_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include <stddef.h>
#include "mcb_pmsm_foc_hall_f28069m_types.h"
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

/* Block signals for system '<S251>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S253>/Merge' */
  uint16_T Merge1;                     /* '<S253>/Merge1' */
  uint16_T Merge3;                     /* '<S253>/Merge3' */
  int16_T Merge2;                      /* '<S253>/Merge2' */
  boolean_T RelationalOperator;        /* '<S253>/Relational Operator' */
} rtB_ValidHalls_mcb_pmsm_foc_hal;

/* Block signals (default storage) */
typedef struct {
  real_T TmpSignalConversionAtDigitalOut[3];
  uint32_T DataStoreRead;              /* '<S5>/Data Store Read' */
  uint32_T MemoryCopy;                 /* '<S306>/Memory Copy' */
  uint32_T BitwiseAND;                 /* '<S306>/Bitwise AND' */
  uint32_T ShiftArithmetic;            /* '<S306>/Shift Arithmetic' */
  uint32_T eCAP[2];                    /* '<S307>/eCAP' */
  uint32_T Switch;                     /* '<S5>/Switch' */
  uint32_T DataStoreRead_g;            /* '<S4>/Data Store Read' */
  uint32_T MemoryCopy_m;               /* '<S285>/Memory Copy' */
  uint32_T BitwiseAND_p;               /* '<S285>/Bitwise AND' */
  uint32_T ShiftArithmetic_d;          /* '<S285>/Shift Arithmetic' */
  uint32_T eCAP_j[2];                  /* '<S286>/eCAP' */
  uint32_T Switch_p;                   /* '<S4>/Switch' */
  uint32_T DataStoreRead_m;            /* '<S3>/Data Store Read' */
  uint32_T MemoryCopy_p;               /* '<S264>/Memory Copy' */
  uint32_T BitwiseAND_a;               /* '<S264>/Bitwise AND' */
  uint32_T ShiftArithmetic_dt;         /* '<S264>/Shift Arithmetic' */
  uint32_T eCAP_l[2];                  /* '<S265>/eCAP' */
  uint32_T Switch_m;                   /* '<S3>/Switch' */
  uint32_T speedCountDelay;            /* '<S182>/speedCountDelay' */
  uint32_T Sum[4];                     /* '<S22>/Sum' */
  uint32_T Input;                      /* '<S175>/Input' */
  uint32_T Max;                        /* '<S186>/Max' */
  uint32_T UnitDelay;                  /* '<S178>/Unit Delay' */
  uint32_T Merge;                      /* '<S178>/Merge' */
  uint32_T DataStoreRead2;             /* '<S171>/Data Store Read2' */
  uint32_T MemoryCopy3;                /* '<S181>/Memory Copy3' */
  uint32_T BitwiseAND_e;               /* '<S181>/Bitwise AND' */
  uint32_T ShiftArithmetic_i;          /* '<S181>/Shift Arithmetic' */
  uint32_T MemoryCopy_l;               /* '<S177>/Memory Copy' */
  uint32_T MemoryCopy1;                /* '<S177>/Memory Copy1' */
  uint32_T MemoryCopy2;                /* '<S177>/Memory Copy2' */
  uint32_T Min;                        /* '<S177>/Min' */
  uint32_T MemoryCopy3_o;              /* '<S176>/Memory Copy3' */
  uint32_T BitwiseAND_aq;              /* '<S176>/Bitwise AND' */
  uint32_T ShiftArithmetic_e;          /* '<S176>/Shift Arithmetic' */
  uint32_T DataTypeConversion;         /* '<S176>/Data Type Conversion' */
  real32_T RT6[2];                     /* '<Root>/RT6' */
  real32_T RT_c;                       /* '<Root>/RT' */
  real32_T RT1;                        /* '<Root>/RT1' */
  real32_T Switch_a;                   /* '<S326>/Switch' */
  real32_T Product;                    /* '<S381>/Product' */
  real32_T UnitDelay_k;                /* '<S381>/Unit Delay' */
  real32_T Product1;                   /* '<S381>/Product1' */
  real32_T Add1;                       /* '<S381>/Add1' */
  real32_T Sum_a;                      /* '<S325>/Sum' */
  real32_T Kp1;                        /* '<S325>/Kp1' */
  real32_T PProdOut;                   /* '<S366>/PProd Out' */
  real32_T Ki2;                        /* '<S325>/Ki2' */
  real32_T Integrator;                 /* '<S361>/Integrator' */
  real32_T Sum_g;                      /* '<S370>/Sum' */
  real32_T DeadZone;                   /* '<S354>/DeadZone' */
  real32_T IProdOut;                   /* '<S358>/IProd Out' */
  real32_T Switch_f;                   /* '<S352>/Switch' */
  real32_T Saturation;                 /* '<S368>/Saturation' */
  real32_T DataTypeConversion1[2];     /* '<S322>/Data Type Conversion1' */
  real32_T DataTypeConversion1_l;      /* '<S9>/Data Type Conversion1' */
  real32_T Merge_m;                    /* '<S173>/Merge' */
  real32_T Merge1;                     /* '<S173>/Merge1' */
  real32_T PositionUnit;               /* '<S173>/PositionUnit' */
  real32_T Switch_pz;                  /* '<S218>/Switch' */
  real32_T Merge_p;                    /* '<S219>/Merge' */
  real32_T Numberofpolepairs;          /* '<S224>/Number of pole pairs' */
  real32_T Multiply;                   /* '<S220>/Multiply' */
  real32_T Floor;                      /* '<S220>/Floor' */
  real32_T Multiply1;                  /* '<S220>/Multiply1' */
  real32_T Add;                        /* '<S220>/Add' */
  real32_T DataTypeConversion1_m[2];   /* '<S170>/Data Type Conversion1' */
  real32_T Kalpha;                     /* '<S24>/Kalpha' */
  real32_T Kbeta;                      /* '<S24>/Kbeta' */
  real32_T convert_pu;                 /* '<S150>/convert_pu' */
  real32_T Merge_n;                    /* '<S150>/Merge' */
  real32_T indexing;                   /* '<S22>/indexing' */
  real32_T Lookup[4];                  /* '<S22>/Lookup' */
  real32_T Sum3;                       /* '<S149>/Sum3' */
  real32_T DataTypeConversion1_b;      /* '<S22>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S22>/Sum2' */
  real32_T Product_l;                  /* '<S149>/Product' */
  real32_T Sum4;                       /* '<S149>/Sum4' */
  real32_T Sum5;                       /* '<S149>/Sum5' */
  real32_T Product1_a;                 /* '<S149>/Product1' */
  real32_T Sum6;                       /* '<S149>/Sum6' */
  real32_T Sum_i;                      /* '<S28>/Sum' */
  real32_T Kp;                         /* '<S28>/Kp' */
  real32_T PProdOut_d;                 /* '<S133>/PProd Out' */
  real32_T Kp1_c;                      /* '<S28>/Kp1' */
  real32_T Integrator_h;               /* '<S128>/Integrator' */
  real32_T Sum_n;                      /* '<S137>/Sum' */
  real32_T Saturation_d;               /* '<S135>/Saturation' */
  real32_T Sum_p;                      /* '<S27>/Sum' */
  real32_T Kp_i;                       /* '<S27>/Kp' */
  real32_T PProdOut_p;                 /* '<S82>/PProd Out' */
  real32_T Ki1;                        /* '<S27>/Ki1' */
  real32_T Integrator_n;               /* '<S77>/Integrator' */
  real32_T Sum_ai;                     /* '<S86>/Sum' */
  real32_T Saturation_c;               /* '<S84>/Saturation' */
  real32_T Switch_k;                   /* '<S31>/Switch' */
  real32_T Product_o;                  /* '<S31>/Product' */
  real32_T Product_g;                  /* '<S32>/Product' */
  real32_T Product1_m;                 /* '<S32>/Product1' */
  real32_T Sum1;                       /* '<S32>/Sum1' */
  real32_T Merge_o[2];                 /* '<S26>/Merge' */
  real32_T DeadZone_k;                 /* '<S70>/DeadZone' */
  real32_T IProdOut_l;                 /* '<S74>/IProd Out' */
  real32_T Switch_l;                   /* '<S68>/Switch' */
  real32_T DeadZone_o;                 /* '<S121>/DeadZone' */
  real32_T IProdOut_b;                 /* '<S125>/IProd Out' */
  real32_T Switch_k5;                  /* '<S119>/Switch' */
  real32_T DataTypeConversion_p;       /* '<S15>/Data Type Conversion' */
  real32_T TmpSignalConversionAtDigitalO_d[3];
  real32_T Speed_PU;                   /* '<S1>/Input Scaling' */
  real32_T sqrt3_by_two;               /* '<S160>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S160>/one_by_two' */
  real32_T add_c;                      /* '<S160>/add_c' */
  real32_T Kc;                         /* '<S160>/Kc' */
  real32_T Ka;                         /* '<S160>/Ka' */
  real32_T add_b;                      /* '<S160>/add_b' */
  real32_T Kb;                         /* '<S160>/Kb' */
  real32_T Min_o;                      /* '<S157>/Min' */
  real32_T Max_g;                      /* '<S157>/Max' */
  real32_T Add_h;                      /* '<S157>/Add' */
  real32_T one_by_two_f;               /* '<S157>/one_by_two' */
  real32_T Add3;                       /* '<S156>/Add3' */
  real32_T Add2;                       /* '<S156>/Add2' */
  real32_T Add1_n;                     /* '<S156>/Add1' */
  real32_T Gain[3];                    /* '<S156>/Gain' */
  real32_T One_by_Two[3];              /* '<S15>/One_by_Two' */
  real32_T PWM_Duty_Cycles[3];         /* '<S15>/Sum' */
  real32_T SpeedConstData;             /* '<S185>/SpeedConstData' */
  real32_T currentSpeedData;           /* '<S185>/currentSpeedData' */
  real32_T Divide;                     /* '<S185>/Divide' */
  real32_T SpeedGain;                  /* '<S185>/SpeedGain' */
  real32_T Merge1_m;                   /* '<S198>/Merge1' */
  real32_T Saturation_f;               /* '<S198>/Saturation' */
  real32_T Merge_b;                    /* '<S198>/Merge' */
  real32_T countData;                  /* '<S201>/countData' */
  real32_T currentSpeedData_n;         /* '<S201>/currentSpeedData' */
  real32_T Divide_e;                   /* '<S201>/Divide' */
  real32_T countData_h;                /* '<S202>/countData' */
  real32_T previousSpeedData;          /* '<S202>/previousSpeedData' */
  real32_T Divide_k;                   /* '<S202>/Divide' */
  real32_T currentSpeedData_a;         /* '<S202>/currentSpeedData' */
  real32_T Divide1;                    /* '<S202>/Divide1' */
  real32_T Sum_ar;                     /* '<S202>/Sum' */
  real32_T Gain1;                      /* '<S202>/Gain1' */
  real32_T Sum1_m;                     /* '<S202>/Sum1' */
  real32_T Product_b;                  /* '<S202>/Product' */
  real32_T Merge1_d;                   /* '<S199>/Merge1' */
  real32_T Merge1_dn;                  /* '<S200>/Merge1' */
  real32_T Convert_back;               /* '<S153>/Convert_back' */
  real32_T Convert_back_e;             /* '<S152>/Convert_back' */
  real32_T bcos;                       /* '<S147>/bcos' */
  real32_T asin_h;                     /* '<S147>/asin' */
  real32_T sum_Qs;                     /* '<S147>/sum_Qs' */
  real32_T acos_c;                     /* '<S147>/acos' */
  real32_T bsin;                       /* '<S147>/bsin' */
  real32_T sum_Ds;                     /* '<S147>/sum_Ds' */
  real32_T Switch_kn[2];               /* '<S148>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T Unary_Minus;                /* '<S148>/Unary_Minus' */
  real32_T qcos;                       /* '<S145>/qcos' */
  real32_T dsin;                       /* '<S145>/dsin' */
  real32_T sum_beta;                   /* '<S145>/sum_beta' */
  real32_T dcos;                       /* '<S145>/dcos' */
  real32_T qsin;                       /* '<S145>/qsin' */
  real32_T sum_alpha;                  /* '<S145>/sum_alpha' */
  real32_T Switch_ka[2];               /* '<S146>/Switch' */
  real32_T algDD_o1_m;
  real32_T algDD_o2_n;
  real32_T Unary_Minus_b;              /* '<S146>/Unary_Minus' */
  real32_T Product_gn[2];              /* '<S33>/Product' */
  real32_T SquareRoot;                 /* '<S33>/Square Root' */
  real32_T Switch_e;                   /* '<S33>/Switch' */
  real32_T Reciprocal;                 /* '<S33>/Reciprocal' */
  real32_T Switch_ei[2];               /* '<S30>/Switch' */
  real32_T Switch2;                    /* '<S40>/Switch2' */
  real32_T Product_n;                  /* '<S39>/Product' */
  real32_T Sum_e;                      /* '<S39>/Sum' */
  real32_T Product2;                   /* '<S39>/Product2' */
  real32_T Merge_b4;                   /* '<S39>/Merge' */
  real32_T Gain_m;                     /* '<S39>/Gain' */
  real32_T Switch_fb;                  /* '<S40>/Switch' */
  real32_T Switch1;                    /* '<S41>/Switch1' */
  real32_T Sqrt;                       /* '<S41>/Sqrt' */
  real32_T Gain_e;                     /* '<S41>/Gain' */
  real32_T a_plus_2b;                  /* '<S25>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S25>/one_by_sqrt3' */
  real32_T algDD_o1_b;
  real32_T algDD_o2_a;
  int32_T DRV_8312EVMisusinganinvertedamp[2];
  /* '<S170>/DRV_8312 EVM is using an inverted amplifier circuit for current sensing' */
  int32_T DataTypeConversion_m[2];     /* '<S163>/Data Type Conversion' */
  int32_T DataTypeConversion_n;        /* '<S170>/Data Type Conversion' */
  int32_T Add_m[2];                    /* '<S170>/Add' */
  int32_T Q17perunitconversion[2];     /* '<S170>/Q17 per unit conversion' */
  uint16_T Divide_d;                   /* '<S310>/Divide' */
  uint16_T Divide1_j;                  /* '<S310>/Divide1' */
  uint16_T ForIterator;                /* '<S313>/For Iterator' */
  uint16_T ADC;                        /* '<S313>/ADC' */
  uint16_T ADC1;                       /* '<S313>/ADC1' */
  uint16_T Memory;                     /* '<S318>/Memory' */
  uint16_T Sum_m;                      /* '<S318>/Sum' */
  uint16_T Memory1;                    /* '<S318>/Memory1' */
  uint16_T Sum1_i;                     /* '<S318>/Sum1' */
  uint16_T SCIReceive[2];              /* '<S324>/SCI Receive' */
  uint16_T DataTypeConversion1_n;      /* '<S288>/Data Type Conversion1' */
  uint16_T DataTypeConversion2;        /* '<S288>/Data Type Conversion2' */
  uint16_T DataTypeConversion_f;       /* '<S293>/Data Type Conversion' */
  uint16_T Merge_l;                    /* '<S293>/Merge' */
  uint16_T DataTypeConversion1_c;      /* '<S267>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_g;      /* '<S267>/Data Type Conversion2' */
  uint16_T DataTypeConversion_p1;      /* '<S272>/Data Type Conversion' */
  uint16_T Merge_a;                    /* '<S272>/Merge' */
  uint16_T DataTypeConversion1_e;      /* '<S246>/Data Type Conversion1' */
  uint16_T DataTypeConversion2_a;      /* '<S246>/Data Type Conversion2' */
  uint16_T DataTypeConversion_nh;      /* '<S251>/Data Type Conversion' */
  uint16_T Merge_m4;                   /* '<S251>/Merge' */
  uint16_T Switch_ad;                  /* '<S173>/Switch' */
  uint16_T Switch_i;                   /* '<S182>/Switch' */
  uint16_T DelayOneStep;               /* '<S183>/Delay One Step' */
  uint16_T watchdogcheck;              /* '<S186>/watchdog check' */
  uint16_T Sum_at;                     /* '<S183>/Sum' */
  uint16_T DataStoreRead_e;            /* '<S170>/Data Store Read' */
  uint16_T DataStoreRead1;             /* '<S170>/Data Store Read1' */
  uint16_T ADC_n;                      /* '<S228>/ADC' */
  uint16_T Output;                     /* '<S161>/Output' */
  uint16_T DataTypeConversion3[2];     /* '<S163>/Data Type Conversion3' */
  uint16_T SCI_Tx_Data[3];             /* '<S12>/Merge' */
  uint16_T SCI_Tx_Iteration;           /* '<S12>/Merge1' */
  uint16_T Switch1_c;                  /* '<S31>/Switch1' */
  uint16_T DataTypeConversion_l;       /* '<S150>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S22>/Get_Integer' */
  uint16_T FixPtSum1;                  /* '<S166>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S167>/FixPt Switch' */
  uint16_T Switch1_ce[3];              /* '<S225>/Switch1' */
  uint16_T IndexVector;                /* '<S227>/Index Vector' */
  uint16_T Add_ml;                     /* '<S227>/Add' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S225>/Scale_to_PWM_Counter_PRD' */
  uint16_T speedcheck;                 /* '<S186>/speed check' */
  uint16_T DataStoreRead5;             /* '<S171>/Data Store Read5' */
  uint16_T DataStoreRead4;             /* '<S171>/Data Store Read4' */
  uint16_T Data[2];                    /* '<S162>/Data' */
  uint16_T Data_f[2];                  /* '<S164>/Data' */
  uint16_T Data_fw[2];                 /* '<S165>/Data' */
  uint16_T DataTypeConversion_lq;      /* '<S29>/Data Type Conversion' */
  uint16_T DataTypeConversion_a;       /* '<S39>/Data Type Conversion' */
  int16_T DataTypeConversion2_h[2];    /* '<S322>/Data Type Conversion2' */
  int16_T DataStoreRead1_i;            /* '<S5>/Data Store Read1' */
  int16_T Merge1_i;                    /* '<S293>/Merge1' */
  int16_T DataStoreRead1_l;            /* '<S4>/Data Store Read1' */
  int16_T Merge1_d4;                   /* '<S272>/Merge1' */
  int16_T DataStoreRead1_lq;           /* '<S3>/Data Store Read1' */
  int16_T Merge1_ml;                   /* '<S251>/Merge1' */
  int16_T WhileIterator;               /* '<S227>/While Iterator' */
  int16_T DataStoreRead3;              /* '<S171>/Data Store Read3' */
  int16_T Convert_uint16;              /* '<S153>/Convert_uint16' */
  int16_T Convert_uint16_i;            /* '<S152>/Convert_uint16' */
  uint16_T Compare;                    /* '<S179>/Compare' */
  int16_T Switch1_b;                   /* '<S352>/Switch1' */
  int16_T Switch2_f;                   /* '<S352>/Switch2' */
  int16_T Switch1_k;                   /* '<S68>/Switch1' */
  int16_T Switch2_l;                   /* '<S68>/Switch2' */
  int16_T Switch1_d;                   /* '<S119>/Switch1' */
  int16_T Switch2_ld;                  /* '<S119>/Switch2' */
  boolean_T DataStoreRead1_ls;         /* '<S325>/Data Store Read1' */
  boolean_T DataStoreRead1_ll;         /* '<S326>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S325>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S352>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S352>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S352>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S352>/Equal1' */
  boolean_T AND3;                      /* '<S352>/AND3' */
  boolean_T NOT;                       /* '<S309>/NOT' */
  boolean_T DataTypeConversion3_o;     /* '<S9>/Data Type Conversion3' */
  boolean_T Merge3;                    /* '<S293>/Merge3' */
  boolean_T Merge_j;                   /* '<S287>/Merge' */
  boolean_T Merge3_k;                  /* '<S272>/Merge3' */
  boolean_T Merge_d;                   /* '<S266>/Merge' */
  boolean_T Merge3_d;                  /* '<S251>/Merge3' */
  boolean_T Merge_i;                   /* '<S245>/Merge' */
  boolean_T Compare_f;                 /* '<S172>/Compare' */
  boolean_T DataTypeConversion4;       /* '<S173>/Data Type Conversion4' */
  boolean_T DataTypeConversion_lx;     /* '<S182>/Data Type Conversion' */
  boolean_T validityDelay;             /* '<S182>/validityDelay' */
  boolean_T DelayOneStep1;             /* '<S183>/Delay One Step1' */
  boolean_T OR;                        /* '<S183>/OR' */
  boolean_T Compare_j;                 /* '<S187>/Compare' */
  boolean_T Compare_p;                 /* '<S151>/Compare' */
  boolean_T DataStoreRead1_o;          /* '<S28>/Data Store Read1' */
  boolean_T LogicalOperator_c;         /* '<S28>/Logical Operator' */
  boolean_T DataStoreRead1_c;          /* '<S27>/Data Store Read1' */
  boolean_T LogicalOperator_n;         /* '<S27>/Logical Operator' */
  boolean_T RelationalOperator_l;      /* '<S68>/Relational Operator' */
  boolean_T fixforDTpropagationissue_i;
                                      /* '<S68>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_n;
                                     /* '<S68>/fix for DT propagation issue1' */
  boolean_T Equal1_g;                  /* '<S68>/Equal1' */
  boolean_T AND3_c;                    /* '<S68>/AND3' */
  boolean_T RelationalOperator_k;      /* '<S119>/Relational Operator' */
  boolean_T fixforDTpropagationissue_p;
                                     /* '<S119>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_e;
                                    /* '<S119>/fix for DT propagation issue1' */
  boolean_T Equal1_f;                  /* '<S119>/Equal1' */
  boolean_T AND3_b;                    /* '<S119>/AND3' */
  boolean_T PWM_En;                    /* '<S15>/Enable' */
  boolean_T LogicalOperator_a;         /* '<S182>/Logical Operator' */
  boolean_T RelationalOperator_o;      /* '<S178>/Relational Operator' */
  boolean_T NOT_m;                     /* '<S178>/NOT' */
  boolean_T RelationalOperator_n;      /* '<S29>/Relational Operator' */
  boolean_T Compare_a;                 /* '<S35>/Compare' */
  boolean_T Compare_k;                 /* '<S36>/Compare' */
  boolean_T LowerRelop1;               /* '<S40>/LowerRelop1' */
  boolean_T RelationalOperator_ky;     /* '<S39>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S40>/UpperRelop' */
  rtB_ValidHalls_mcb_pmsm_foc_hal ValidHalls_j;/* '<S293>/Valid Halls' */
  rtB_ValidHalls_mcb_pmsm_foc_hal ValidHalls_i;/* '<S272>/Valid Halls' */
  rtB_ValidHalls_mcb_pmsm_foc_hal ValidHalls;/* '<S251>/Valid Halls' */
} BlockIO_mcb_pmsm_foc_hall_f2806;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S381>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S361>/Integrator' */
  real32_T Integrator_DSTATE_k;        /* '<S128>/Integrator' */
  real32_T Integrator_DSTATE_g;        /* '<S77>/Integrator' */
  uint32_T speedCountDelay_DSTATE;     /* '<S182>/speedCountDelay' */
  uint32_T UnitDelay_DSTATE_i;         /* '<S178>/Unit Delay' */
  volatile real32_T RT6_Buffer[4];     /* '<Root>/RT6' */
  volatile real32_T RT_Buffer[2];      /* '<Root>/RT' */
  volatile real32_T RT1_Buffer[2];     /* '<Root>/RT1' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S320>/Digital Output1' */
  int32_T DigitalOutput2_FRAC_LEN;     /* '<S311>/Digital Output2' */
  int32_T Add_DWORK1[2];               /* '<S170>/Add' */
  int32_T DigitalOutput2_FRAC_LEN_m;   /* '<S225>/Digital Output2' */
  uint32_T GlobalSpeedCount;           /* '<Root>/Data Store Memory1' */
  uint32_T GlobalHallState;            /* '<Root>/Data Store Memory4' */
  uint32_T Sum_DWORK1[4];              /* '<S22>/Sum' */
  uint16_T DelayOneStep_DSTATE;        /* '<S183>/Delay One Step' */
  uint16_T Output_DSTATE;              /* '<S161>/Output' */
  volatile int16_T RT6_ActiveBufIdx;   /* '<Root>/RT6' */
  volatile int16_T RT_ActiveBufIdx;    /* '<Root>/RT' */
  volatile int16_T RT1_ActiveBufIdx;   /* '<Root>/RT1' */
  volatile int16_T RT1_semaphoreTaken; /* '<Root>/RT1' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory3' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory2' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory5' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory6' */
  uint16_T Memory_PreviousInput;       /* '<S318>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S318>/Memory1' */
  uint16_T Add_DWORK1_g;               /* '<S227>/Add' */
  boolean_T validityDelay_DSTATE;      /* '<S182>/validityDelay' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S183>/Delay One Step1' */
  int16_T Integrator_PrevResetState;   /* '<S361>/Integrator' */
  int16_T Integrator_PrevResetState_o; /* '<S128>/Integrator' */
  int16_T Integrator_PrevResetState_j; /* '<S77>/Integrator' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
} D_Work_mcb_pmsm_foc_hall_f28069;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T Width;                /* '<S12>/Width' */
} ConstBlockIO_mcb_pmsm_foc_hall_;

/* Parameters for system: '<S200>/Hall Value of 1' */
struct rtP_HallValueof1_mcb_pmsm_foc_h_ {
  real32_T Constant_Value;             /* Expression: single(0.16667)
                                        * Referenced by: '<S210>/Constant'
                                        */
};

/* Parameters for system: '<S245>/Output 1' */
struct rtP_Output1_mcb_pmsm_foc_hall_f_ {
  boolean_T Constant_Value;            /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S250>/Constant'
                                        */
};

/* Parameters for system: '<S253>/If Action Subsystem6' */
struct rtP_IfActionSubsystem6_mcb_pmsm_ {
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S260>/Constant'
                                        */
  uint16_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S260>/Constant1'
                                        */
};

/* Parameters for system: '<S253>/If Action Subsystem' */
struct rtP_IfActionSubsystem_mcb_pmsm__ {
  uint16_T previous_Value;             /* Computed Parameter: previous_Value
                                        * Referenced by: '<S254>/previous'
                                        */
  uint16_T next_Value;                 /* Computed Parameter: next_Value
                                        * Referenced by: '<S254>/next'
                                        */
};

/* Parameters for system: '<S251>/Valid Halls' */
struct rtP_ValidHalls_mcb_pmsm_foc_hal_ {
  int16_T Merge2_InitialOutput;      /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S253>/Merge2'
                                      */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S262>/Constant'
                                        */
  uint16_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S253>/Merge'
                                       */
  uint16_T Merge1_InitialOutput;     /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S253>/Merge1'
                                      */
  uint16_T Merge3_InitialOutput;     /* Computed Parameter: Merge3_InitialOutput
                                      * Referenced by: '<S253>/Merge3'
                                      */
  boolean_T Constant_Value_h;          /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S253>/Constant'
                                        */
  rtP_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem5;/* '<S253>/If Action Subsystem5' */
  rtP_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem4;/* '<S253>/If Action Subsystem4' */
  rtP_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem3;/* '<S253>/If Action Subsystem3' */
  rtP_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem2;/* '<S253>/If Action Subsystem2' */
  rtP_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem1;/* '<S253>/If Action Subsystem1' */
  rtP_IfActionSubsystem_mcb_pmsm_ IfActionSubsystem;/* '<S253>/If Action Subsystem' */
  rtP_IfActionSubsystem6_mcb_pmsm IfActionSubsystem7;/* '<S253>/If Action Subsystem7' */
  rtP_IfActionSubsystem6_mcb_pmsm IfActionSubsystem6;/* '<S253>/If Action Subsystem6' */
};

/* Parameters for system: '<S251>/Bad hall (glitch or wrong connection)' */
struct rtP_Badhallglitchorwrongconnect_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S252>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S252>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct Parameters_mcb_pmsm_foc_hall_f2_ {
  real32_T DiscretePIControllerwithantiwin;
                              /* Mask Parameter: DiscretePIControllerwithantiwin
                               * Referenced by:
                               *   '<S135>/Saturation'
                               *   '<S121>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_o;
                              /* Mask Parameter: DiscretePIControllerwithantiw_o
                               * Referenced by:
                               *   '<S84>/Saturation'
                               *   '<S70>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_d;
                              /* Mask Parameter: DiscretePIControllerwithantiw_d
                               * Referenced by:
                               *   '<S368>/Saturation'
                               *   '<S354>/DeadZone'
                               */
  real32_T MechanicaltoElectricalPosition_;
                              /* Mask Parameter: MechanicaltoElectricalPosition_
                               * Referenced by: '<S224>/Number of pole pairs'
                               */
  real32_T DiscretePIControllerwithantiw_f;
                              /* Mask Parameter: DiscretePIControllerwithantiw_f
                               * Referenced by:
                               *   '<S135>/Saturation'
                               *   '<S121>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_e;
                              /* Mask Parameter: DiscretePIControllerwithantiw_e
                               * Referenced by:
                               *   '<S84>/Saturation'
                               *   '<S70>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_h;
                              /* Mask Parameter: DiscretePIControllerwithantiw_h
                               * Referenced by:
                               *   '<S368>/Saturation'
                               *   '<S354>/DeadZone'
                               */
  uint32_T BitwiseAND_BitMask;         /* Mask Parameter: BitwiseAND_BitMask
                                        * Referenced by: '<S176>/Bitwise AND'
                                        */
  uint32_T BitwiseAND_BitMask_p;       /* Mask Parameter: BitwiseAND_BitMask_p
                                        * Referenced by: '<S181>/Bitwise AND'
                                        */
  uint32_T BitwiseAND_BitMask_m;       /* Mask Parameter: BitwiseAND_BitMask_m
                                        * Referenced by: '<S264>/Bitwise AND'
                                        */
  uint32_T BitwiseAND_BitMask_d;       /* Mask Parameter: BitwiseAND_BitMask_d
                                        * Referenced by: '<S285>/Bitwise AND'
                                        */
  uint32_T BitwiseAND_BitMask_pw;      /* Mask Parameter: BitwiseAND_BitMask_pw
                                        * Referenced by: '<S306>/Bitwise AND'
                                        */
  uint32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S179>/Constant'
                                       */
  uint32_T GlitchFilter_const;         /* Mask Parameter: GlitchFilter_const
                                        * Referenced by: '<S172>/Constant'
                                        */
  uint16_T CompareToConstant_const_p;
                                    /* Mask Parameter: CompareToConstant_const_p
                                     * Referenced by: '<S35>/Constant'
                                     */
  uint16_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S36>/Constant'
                                      */
  uint16_T SoftwareWatchdogTimer_maxCount;
                               /* Mask Parameter: SoftwareWatchdogTimer_maxCount
                                * Referenced by: '<S183>/Delay One Step'
                                */
  uint16_T CounterLimited_uplimit;     /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S167>/FixPt Switch'
                                        */
  real_T Constant_Value;               /* Expression: EnableSecondOrder
                                        * Referenced by: '<S198>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: 8
                                        * Referenced by: '<S310>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T ADCCalibEnable_Value;      /* Expression: inverter.ADCOffsetCalibEnable
                                     * Referenced by: '<S309>/ADC Calib Enable'
                                     */
  real32_T one_by_sqrt3_Gain;          /* Computed Parameter: one_by_sqrt3_Gain
                                        * Referenced by: '<S25>/one_by_sqrt3'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S41>/Constant'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S41>/Gain'
                                        */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S41>/Switch1'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S41>/Switch'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S39>/Gain'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S33>/Constant'
                                        */
  real32_T ReplaceInport_satLim_Value;
                               /* Computed Parameter: ReplaceInport_satLim_Value
                                * Referenced by: '<S26>/ReplaceInport_satLim'
                                */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S31>/Constant3'
                                        */
  real32_T Constant_Value_b;           /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S202>/Constant'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S202>/Gain1'
                                        */
  real32_T Gain_Gain_p;                /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S202>/Gain'
                                        */
  real32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S201>/Gain'
                                        */
  real32_T Saturation_UpperSat;        /* Expression: single(0.16667)
                                        * Referenced by: '<S198>/Saturation'
                                        */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S198>/Saturation'
                                       */
  real32_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S198>/Merge'
                                       */
  real32_T SpeedGain_Gain;             /* Expression: single(MinSpeed/5298)
                                        * Referenced by: '<S185>/SpeedGain'
                                        */
  real32_T Constant_Value_m4;          /* Computed Parameter: Constant_Value_m4
                                        * Referenced by: '<S184>/Constant'
                                        */
  real32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S221>/Constant'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S218>/Constant1'
                                        */
  real32_T ReplaceInport_Offset_Value;
                               /* Computed Parameter: ReplaceInport_Offset_Value
                                * Referenced by: '<S174>/ReplaceInport_Offset'
                                */
  real32_T Constant_Value_gi;          /* Computed Parameter: Constant_Value_gi
                                        * Referenced by: '<S15>/Constant'
                                        */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S160>/sqrt3_by_two'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S160>/one_by_two'
                                        */
  real32_T Kc_Gain;                    /* Computed Parameter: Kc_Gain
                                        * Referenced by: '<S160>/Kc'
                                        */
  real32_T Ka_Gain;                    /* Computed Parameter: Ka_Gain
                                        * Referenced by: '<S160>/Ka'
                                        */
  real32_T Kb_Gain;                    /* Computed Parameter: Kb_Gain
                                        * Referenced by: '<S160>/Kb'
                                        */
  real32_T one_by_two_Gain_k;          /* Computed Parameter: one_by_two_Gain_k
                                        * Referenced by: '<S157>/one_by_two'
                                        */
  real32_T Gain_Gain_h;                /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S156>/Gain'
                                        */
  real32_T One_by_Two_Gain;            /* Computed Parameter: One_by_Two_Gain
                                        * Referenced by: '<S15>/One_by_Two'
                                        */
  real32_T Scale_to_PWM_Counter_PRD_Gain;
                            /* Computed Parameter: Scale_to_PWM_Counter_PRD_Gain
                             * Referenced by: '<S225>/Scale_to_PWM_Counter_PRD'
                             */
  real32_T DutyCycles_Y0;              /* Computed Parameter: DutyCycles_Y0
                                        * Referenced by: '<S1>/Duty Cycles'
                                        */
  real32_T Speed_fb_Y0;                /* Computed Parameter: Speed_fb_Y0
                                        * Referenced by: '<S1>/Speed_fb'
                                        */
  real32_T PositionUnit_Gain;          /* Expression: single(1)
                                        * Referenced by: '<S173>/PositionUnit'
                                        */
  real32_T Multiply_Gain;              /* Computed Parameter: Multiply_Gain
                                        * Referenced by: '<S220>/Multiply'
                                        */
  real32_T Multiply1_Gain;             /* Computed Parameter: Multiply1_Gain
                                        * Referenced by: '<S220>/Multiply1'
                                        */
  real32_T Kalpha_Gain;                /* Computed Parameter: Kalpha_Gain
                                        * Referenced by: '<S24>/Kalpha'
                                        */
  real32_T Kbeta_Gain;                 /* Computed Parameter: Kbeta_Gain
                                        * Referenced by: '<S24>/Kbeta'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S22>/sine_table_values'
                                   */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S150>/convert_pu'
                                        */
  real32_T Constant_Value_h5;          /* Computed Parameter: Constant_Value_h5
                                        * Referenced by: '<S151>/Constant'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S22>/indexing'
                                        */
  real32_T Kp_Value;                   /* Expression: PI_params.Kp_i
                                        * Referenced by: '<S28>/Kp'
                                        */
  real32_T Kp1_Value;                  /* Computed Parameter: Kp1_Value
                                        * Referenced by: '<S28>/Kp1'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S128>/Integrator'
                                        */
  real32_T Kp_Value_p;                 /* Expression: PI_params.Kp_i
                                        * Referenced by: '<S27>/Kp'
                                        */
  real32_T Ki1_Value;                  /* Computed Parameter: Ki1_Value
                                        * Referenced by: '<S27>/Ki1'
                                        */
  real32_T Integrator_gainval_i;     /* Computed Parameter: Integrator_gainval_i
                                      * Referenced by: '<S77>/Integrator'
                                      */
  real32_T Clamping_zero_Value;       /* Computed Parameter: Clamping_zero_Value
                                       * Referenced by: '<S68>/Clamping_zero'
                                       */
  real32_T Ki_Value;                   /* Computed Parameter: Ki_Value
                                        * Referenced by: '<S27>/Ki'
                                        */
  real32_T Constant1_Value_e;          /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S68>/Constant1'
                                        */
  real32_T Clamping_zero_Value_j;   /* Computed Parameter: Clamping_zero_Value_j
                                     * Referenced by: '<S119>/Clamping_zero'
                                     */
  real32_T Ki_Value_n;                 /* Computed Parameter: Ki_Value_n
                                        * Referenced by: '<S28>/Ki'
                                        */
  real32_T Constant1_Value_j;          /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S119>/Constant1'
                                        */
  real32_T Switch1_Threshold_i;       /* Computed Parameter: Switch1_Threshold_i
                                       * Referenced by: '<S225>/Switch1'
                                       */
  real32_T DesiredSpeed_Y0;            /* Computed Parameter: DesiredSpeed_Y0
                                        * Referenced by: '<S9>/Desired Speed'
                                        */
  real32_T Constant1_Value_f;          /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S352>/Constant1'
                                        */
  real32_T Id_ref_Value;               /* Computed Parameter: Id_ref_Value
                                        * Referenced by: '<S10>/Id_ref'
                                        */
  real32_T Clamping_zero_Value_i;   /* Computed Parameter: Clamping_zero_Value_i
                                     * Referenced by: '<S352>/Clamping_zero'
                                     */
  real32_T Filter_Constant_Value;   /* Computed Parameter: Filter_Constant_Value
                                     * Referenced by: '<S381>/Filter_Constant'
                                     */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S381>/One'
                                        */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S381>/Unit Delay'
                                */
  real32_T Kp1_Value_e;                /* Expression: PI_params.Kp_speed
                                        * Referenced by: '<S325>/Kp1'
                                        */
  real32_T Ki2_Value;                  /* Computed Parameter: Ki2_Value
                                        * Referenced by: '<S325>/Ki2'
                                        */
  real32_T Integrator_gainval_p;     /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S361>/Integrator'
                                      */
  real32_T Ki1_Value_k;                /* Computed Parameter: Ki1_Value_k
                                        * Referenced by: '<S325>/Ki1'
                                        */
  real32_T RT6_InitialCondition;     /* Computed Parameter: RT6_InitialCondition
                                      * Referenced by: '<Root>/RT6'
                                      */
  real32_T RT_InitialCondition;       /* Computed Parameter: RT_InitialCondition
                                       * Referenced by: '<Root>/RT'
                                       */
  real32_T RT1_InitialCondition;     /* Computed Parameter: RT1_InitialCondition
                                      * Referenced by: '<Root>/RT1'
                                      */
  uint32_T HallSignal_Y0;              /* Computed Parameter: HallSignal_Y0
                                        * Referenced by: '<S176>/HallSignal'
                                        */
  uint32_T u_Y0;                       /* Computed Parameter: u_Y0
                                        * Referenced by: '<S177>/u'
                                        */
  uint32_T UnitDelay_InitialCondition_g;
                             /* Computed Parameter: UnitDelay_InitialCondition_g
                              * Referenced by: '<S178>/Unit Delay'
                              */
  uint32_T SpeedConst_Value;
                          /* Expression: uint32(30*ClkFreq/(PolePairs*MinSpeed))
                           * Referenced by: '<S185>/SpeedConst'
                           */
  uint32_T speedcheck_Threshold;     /* Computed Parameter: speedcheck_Threshold
                                      * Referenced by: '<S186>/speed check'
                                      */
  uint32_T Output_Y0;                  /* Computed Parameter: Output_Y0
                                        * Referenced by: '<S175>/Output'
                                        */
  uint32_T speedCountDelay_InitialConditio;
                          /* Computed Parameter: speedCountDelay_InitialConditio
                           * Referenced by: '<S182>/speedCountDelay'
                           */
  uint32_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  uint32_T DataStoreMemory4_InitialValue;
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<Root>/Data Store Memory4'
                             */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S22>/offset'
                                        */
  int16_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  uint16_T ReplaceInport_satMethod_Value;
                            /* Computed Parameter: ReplaceInport_satMethod_Value
                             * Referenced by: '<S26>/ReplaceInport_satMethod'
                             */
  uint16_T ChosenMethod_Value;         /* Computed Parameter: ChosenMethod_Value
                                        * Referenced by: '<S31>/ChosenMethod'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S146>/Offset'
                                        */
  uint16_T Switch_Threshold_f;         /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S146>/Switch'
                                        */
  uint16_T Offset_Value_m;             /* Computed Parameter: Offset_Value_m
                                        * Referenced by: '<S148>/Offset'
                                        */
  uint16_T Switch_Threshold_g;         /* Computed Parameter: Switch_Threshold_g
                                        * Referenced by: '<S148>/Switch'
                                        */
  uint16_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S167>/Constant'
                                        */
  uint16_T End_Value;                  /* Computed Parameter: End_Value
                                        * Referenced by: '<S165>/End'
                                        */
  uint16_T Bias_Bias;                  /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S165>/Bias'
                                        */
  uint16_T Start_Value;                /* Computed Parameter: Start_Value
                                        * Referenced by: '<S164>/Start'
                                        */
  uint16_T Bias_Bias_l;                /* Computed Parameter: Bias_Bias_l
                                        * Referenced by: '<S164>/Bias'
                                        */
  uint16_T Start_Value_c;              /* Computed Parameter: Start_Value_c
                                        * Referenced by: '<S162>/Start'
                                        */
  uint16_T PositionEnable_Value;     /* Computed Parameter: PositionEnable_Value
                                      * Referenced by: '<S185>/PositionEnable'
                                      */
  uint16_T WatchDog_Value;             /* Computed Parameter: WatchDog_Value
                                        * Referenced by: '<S173>/WatchDog'
                                        */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S225>/stop'
                                        */
  uint16_T Order_Value;                /* Computed Parameter: Order_Value
                                        * Referenced by: '<S182>/Order'
                                        */
  uint16_T Switch_Threshold_k;         /* Computed Parameter: Switch_Threshold_k
                                        * Referenced by: '<S182>/Switch'
                                        */
  uint16_T Constant_Value_fx;          /* Computed Parameter: Constant_Value_fx
                                        * Referenced by: '<S186>/Constant'
                                        */
  uint16_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S187>/Constant'
                                        */
  uint16_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S183>/Constant2'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S161>/Output'
                                   */
  uint16_T enableInportSatMethod_Value;
                              /* Computed Parameter: enableInportSatMethod_Value
                               * Referenced by: '<S31>/enableInportSatMethod'
                               */
  uint16_T enableInportSatLim_Value;
                                 /* Computed Parameter: enableInportSatLim_Value
                                  * Referenced by: '<S31>/enableInportSatLim'
                                  */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S166>/FixPt Constant'
                                       */
  uint16_T Constant_Value_me;          /* Computed Parameter: Constant_Value_me
                                        * Referenced by: '<S246>/Constant'
                                        */
  uint16_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S267>/Constant'
                                        */
  uint16_T Constant_Value_i;           /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S288>/Constant'
                                        */
  uint16_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S318>/Out1'
                                        */
  uint16_T Out2_Y0;                    /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S318>/Out2'
                                        */
  uint16_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S318>/Memory'
                                   */
  uint16_T Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<S318>/Memory1'
                                  */
  uint16_T ForIterator_IterationLimit;
                               /* Computed Parameter: ForIterator_IterationLimit
                                * Referenced by: '<S313>/For Iterator'
                                */
  uint16_T Constant_Value_f2;          /* Computed Parameter: Constant_Value_f2
                                        * Referenced by: '<S315>/Constant'
                                        */
  uint16_T Constant1_Value_h;          /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S317>/Constant1'
                                        */
  uint16_T Constant1_Value_o;          /* Computed Parameter: Constant1_Value_o
                                        * Referenced by: '<S310>/Constant1'
                                        */
  uint16_T Constant2_Value_b;          /* Computed Parameter: Constant2_Value_b
                                        * Referenced by: '<S310>/Constant2'
                                        */
  uint16_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S312>/Constant'
                                        */
  uint16_T Constant1_Value_ei;         /* Computed Parameter: Constant1_Value_ei
                                        * Referenced by: '<S312>/Constant1'
                                        */
  uint16_T RED_LED_Value;              /* Computed Parameter: RED_LED_Value
                                        * Referenced by: '<S7>/RED_LED'
                                        */
  uint16_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  uint16_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<Root>/Data Store Memory2'
                             */
  uint16_T DataStoreMemory5_InitialValue;
                            /* Computed Parameter: DataStoreMemory5_InitialValue
                             * Referenced by: '<Root>/Data Store Memory5'
                             */
  uint16_T DataStoreMemory6_InitialValue;
                            /* Computed Parameter: DataStoreMemory6_InitialValue
                             * Referenced by: '<Root>/Data Store Memory6'
                             */
  boolean_T validityDelay_InitialCondition;
                           /* Computed Parameter: validityDelay_InitialCondition
                            * Referenced by: '<S182>/validityDelay'
                            */
  boolean_T DelayOneStep1_InitialCondition;
                           /* Computed Parameter: DelayOneStep1_InitialCondition
                            * Referenced by: '<S183>/Delay One Step1'
                            */
  boolean_T DataStoreMemory29_InitialValue;
                           /* Computed Parameter: DataStoreMemory29_InitialValue
                            * Referenced by: '<Root>/Data Store Memory29'
                            */
  int16_T Constant_Value_mz;           /* Computed Parameter: Constant_Value_mz
                                        * Referenced by: '<S68>/Constant'
                                        */
  int16_T Constant2_Value_o;           /* Computed Parameter: Constant2_Value_o
                                        * Referenced by: '<S68>/Constant2'
                                        */
  int16_T Constant3_Value_a;           /* Computed Parameter: Constant3_Value_a
                                        * Referenced by: '<S68>/Constant3'
                                        */
  int16_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S68>/Constant4'
                                        */
  int16_T Constant_Value_ib;           /* Computed Parameter: Constant_Value_ib
                                        * Referenced by: '<S119>/Constant'
                                        */
  int16_T Constant2_Value_b5;          /* Computed Parameter: Constant2_Value_b5
                                        * Referenced by: '<S119>/Constant2'
                                        */
  int16_T Constant3_Value_o;           /* Computed Parameter: Constant3_Value_o
                                        * Referenced by: '<S119>/Constant3'
                                        */
  int16_T Constant4_Value_a;           /* Computed Parameter: Constant4_Value_a
                                        * Referenced by: '<S119>/Constant4'
                                        */
  int16_T Constant_Value_j1;           /* Computed Parameter: Constant_Value_j1
                                        * Referenced by: '<S352>/Constant'
                                        */
  int16_T Constant2_Value_n;           /* Computed Parameter: Constant2_Value_n
                                        * Referenced by: '<S352>/Constant2'
                                        */
  int16_T Constant3_Value_i;           /* Computed Parameter: Constant3_Value_i
                                        * Referenced by: '<S352>/Constant3'
                                        */
  int16_T Constant4_Value_k;           /* Computed Parameter: Constant4_Value_k
                                        * Referenced by: '<S352>/Constant4'
                                        */
  uint16_T Constant_Value_dp;          /* Computed Parameter: Constant_Value_dp
                                        * Referenced by: '<S218>/Constant'
                                        */
  uint16_T Switch_Threshold_l;         /* Computed Parameter: Switch_Threshold_l
                                        * Referenced by: '<S218>/Switch'
                                        */
  rtP_Badhallglitchorwrongconnect Badhallglitchorwrongconnectio_l;
                            /* '<S293>/Bad hall (glitch or wrong connection)' */
  rtP_ValidHalls_mcb_pmsm_foc_hal ValidHalls_j;/* '<S293>/Valid Halls' */
  rtP_Output1_mcb_pmsm_foc_hall_f Output0_b;/* '<S287>/Output 0' */
  rtP_Output1_mcb_pmsm_foc_hall_f Output1_o;/* '<S287>/Output 1' */
  rtP_Badhallglitchorwrongconnect Badhallglitchorwrongconnectio_k;
                            /* '<S272>/Bad hall (glitch or wrong connection)' */
  rtP_ValidHalls_mcb_pmsm_foc_hal ValidHalls_i;/* '<S272>/Valid Halls' */
  rtP_Output1_mcb_pmsm_foc_hall_f Output0_f;/* '<S266>/Output 0' */
  rtP_Output1_mcb_pmsm_foc_hall_f Output1_a;/* '<S266>/Output 1' */
  rtP_Badhallglitchorwrongconnect Badhallglitchorwrongconnection;
                            /* '<S251>/Bad hall (glitch or wrong connection)' */
  rtP_ValidHalls_mcb_pmsm_foc_hal ValidHalls;/* '<S251>/Valid Halls' */
  rtP_Output1_mcb_pmsm_foc_hall_f Output0;/* '<S245>/Output 0' */
  rtP_Output1_mcb_pmsm_foc_hall_f Output1;/* '<S245>/Output 1' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof7_p;/* '<S188>/Hall Value of 7' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof6_p;/* '<S188>/Hall Value of 6' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof5_i;/* '<S188>/Hall Value of 5' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof4_p;/* '<S188>/Hall Value of 4' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof3_kd;/* '<S188>/Hall Value of 3' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof2_m;/* '<S188>/Hall Value of 2' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof1_m;/* '<S188>/Hall Value of 1' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof7_a;/* '<S199>/Hall Value of 7' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof6_d;/* '<S199>/Hall Value of 6' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof5_e;/* '<S199>/Hall Value of 5' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof4_l;/* '<S199>/Hall Value of 4' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof3_k;/* '<S199>/Hall Value of 3' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof2_n;/* '<S199>/Hall Value of 2' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof1_n;/* '<S199>/Hall Value of 1' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof7;/* '<S200>/Hall Value of 7' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof6;/* '<S200>/Hall Value of 6' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof5;/* '<S200>/Hall Value of 5' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof4;/* '<S200>/Hall Value of 4' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof3;/* '<S200>/Hall Value of 3' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof2;/* '<S200>/Hall Value of 2' */
  rtP_HallValueof1_mcb_pmsm_foc_h HallValueof1;/* '<S200>/Hall Value of 1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_foc_hall_f2806 {
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

/* Block parameters (default storage) */
extern Parameters_mcb_pmsm_foc_hall_f2 mcb_pmsm_foc_hall_f28069m_P;

/* Block signals (default storage) */
extern BlockIO_mcb_pmsm_foc_hall_f2806 mcb_pmsm_foc_hall_f28069m_B;

/* Block states (default storage) */
extern D_Work_mcb_pmsm_foc_hall_f28069 mcb_pmsm_foc_hall_f28069m_DWork;
extern const ConstBlockIO_mcb_pmsm_foc_hall_ mcb_pmsm_foc_hall_f28069_ConstB;/* constant block i/o */

/* External function called from main */
extern void mcb_pmsm_foc_hall_f28069m_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void mcb_pmsm_foc_hall_f28069m_initialize(void);
extern void mcb_pmsm_foc_hall_f28069m_step0(void);
extern void mcb_pmsm_foc_hall_f28069m_step1(void);
extern void mcb_pmsm_foc_hall_f28069m_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_foc_hall_f280 *const mcb_pmsm_foc_hall_f28069m_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ECAP1_INT(void);
  interrupt void ECAP2_INT(void);
  interrupt void ECAP3_INT(void);
  interrupt void ADCA1_INT(void);
  interrupt void SCIA_RX_INT(void);
  void mcb_pmsm_foc_hall_f28069m_configure_interrupts (void);
  void mcb_pmsm_foc_hall_f28069m_unconfigure_interrupts (void);

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
 * '<Root>' : 'mcb_pmsm_foc_hall_f28069m'
 * '<S1>'   : 'mcb_pmsm_foc_hall_f28069m/Current Control'
 * '<S2>'   : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt'
 * '<S3>'   : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A'
 * '<S4>'   : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B'
 * '<S5>'   : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C'
 * '<S6>'   : 'mcb_pmsm_foc_hall_f28069m/Hardware Init'
 * '<S7>'   : 'mcb_pmsm_foc_hall_f28069m/Heartbeat LED'
 * '<S8>'   : 'mcb_pmsm_foc_hall_f28069m/Inverter and Motor - Plant Model'
 * '<S9>'   : 'mcb_pmsm_foc_hall_f28069m/Serial Receive'
 * '<S10>'  : 'mcb_pmsm_foc_hall_f28069m/Speed Control'
 * '<S11>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System'
 * '<S12>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Data_Logging'
 * '<S13>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling'
 * '<S14>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Inverter'
 * '<S15>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Output Scaling'
 * '<S16>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/SCI_Tx'
 * '<S17>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Sensor Driver Blocks'
 * '<S18>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Clarke Transform'
 * '<S19>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers'
 * '<S20>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Inverse Park Transform'
 * '<S21>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Park Transform'
 * '<S22>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Sine-Cosine Lookup'
 * '<S23>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Space Vector Generator'
 * '<S24>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Clarke Transform/Two phase input'
 * '<S25>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S26>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter'
 * '<S27>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id'
 * '<S28>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq'
 * '<S29>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S30>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S31>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S32>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S33>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S34>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S35>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S36>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S37>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S38>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S39>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S40>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S41>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S42>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S43>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S44>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S45>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S46>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S47>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S48>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S49>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S50>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S51>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S52>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S53>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S54>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S55>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S56>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S57>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S58>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S59>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S60>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S61>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S62>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S63>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S64>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S65>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S66>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S67>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S68>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S69>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S70>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S71>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S72>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S73>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S74>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S75>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S76>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S77>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S78>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S79>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S80>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S81>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S82>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S83>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S84>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S85>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S86>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S87>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S88>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S89>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S90>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S91>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S92>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S93>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S94>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S95>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S96>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S97>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S98>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S99>'  : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S100>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S101>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S102>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S103>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S104>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S105>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S106>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S107>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S108>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S109>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S110>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S111>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S112>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S113>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S114>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S115>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S116>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S117>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S118>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S119>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S120>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S121>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S122>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S123>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S124>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S125>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S126>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S127>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S128>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S129>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S130>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S131>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S132>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S133>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S134>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S135>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S136>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S137>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S138>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S139>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S140>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S141>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S142>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S143>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S144>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S145>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Inverse Park Transform/Two inputs CRL'
 * '<S146>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S147>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Park Transform/Two inputs CRL'
 * '<S148>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S149>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Sine-Cosine Lookup/Interpolation'
 * '<S150>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Sine-Cosine Lookup/WrapUp'
 * '<S151>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S152>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S153>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S154>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Space Vector Generator/Modulation method'
 * '<S155>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Space Vector Generator/Voltage Input'
 * '<S156>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Space Vector Generator/Modulation method/SVPWM'
 * '<S157>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S158>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S159>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S160>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S161>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Data_Logging/Counter Limited'
 * '<S162>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Data_Logging/Data'
 * '<S163>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Data_Logging/Data_Conditioning'
 * '<S164>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Data_Logging/End'
 * '<S165>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Data_Logging/Start'
 * '<S166>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Data_Logging/Counter Limited/Increment Real World'
 * '<S167>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S168>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)'
 * '<S169>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall'
 * '<S170>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Convert ADC value to PU'
 * '<S171>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading'
 * '<S172>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Glitch Filter'
 * '<S173>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position'
 * '<S174>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position'
 * '<S175>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Subsystem'
 * '<S176>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Function-Call Subsystem'
 * '<S177>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Function-Call Subsystem1'
 * '<S178>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Integrity_Check'
 * '<S179>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Integrity_Check/Compare To Constant'
 * '<S180>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Integrity_Check/No_Integrity_issue'
 * '<S181>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Atomic Hall Reading/Integrity_Check/Refresh_Halls'
 * '<S182>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/ExtrapolationOrder'
 * '<S183>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Software Watchdog Timer'
 * '<S184>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant'
 * '<S185>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position'
 * '<S186>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/VaidityCheck'
 * '<S187>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Software Watchdog Timer/Compare To Zero'
 * '<S188>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction'
 * '<S189>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 1'
 * '<S190>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 2'
 * '<S191>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 3'
 * '<S192>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 4'
 * '<S193>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 5'
 * '<S194>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 6'
 * '<S195>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 7'
 * '<S196>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem'
 * '<S197>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem1'
 * '<S198>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1'
 * '<S199>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction'
 * '<S200>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction'
 * '<S201>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/first_order'
 * '<S202>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/second_order'
 * '<S203>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 1'
 * '<S204>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 2'
 * '<S205>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 3'
 * '<S206>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 4'
 * '<S207>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 5'
 * '<S208>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 6'
 * '<S209>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 7'
 * '<S210>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 1'
 * '<S211>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 2'
 * '<S212>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 3'
 * '<S213>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 4'
 * '<S214>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 5'
 * '<S215>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 6'
 * '<S216>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 7'
 * '<S217>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position/MechToElec'
 * '<S218>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S219>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S220>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S221>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S222>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S223>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S224>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Input Scaling/Read_Sensor (codegen)/Calculate Position from Hall/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S225>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Inverter/Code Generation'
 * '<S226>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/SCI_Tx/Code Generation'
 * '<S227>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/SCI_Tx/Code Generation/While Iterator Subsystem'
 * '<S228>' : 'mcb_pmsm_foc_hall_f28069m/Current Control/Sensor Driver Blocks/Sensor Driver Blocks (codegen)'
 * '<S229>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation'
 * '<S230>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_ADCINT1'
 * '<S231>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_ECAP1_INT'
 * '<S232>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_ECAP2_INT'
 * '<S233>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_ECAP3_INT'
 * '<S234>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_SCIRXINTA'
 * '<S235>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_ADCINT1/ECSoC'
 * '<S236>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_ADCINT1/ECSoC/ECSimCodegen'
 * '<S237>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_ECAP1_INT/ECSoC'
 * '<S238>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_ECAP1_INT/ECSoC/ECSimCodegen'
 * '<S239>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_ECAP2_INT/ECSoC'
 * '<S240>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_ECAP2_INT/ECSoC/ECSimCodegen'
 * '<S241>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_ECAP3_INT/ECSoC'
 * '<S242>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_ECAP3_INT/ECSoC/ECSimCodegen'
 * '<S243>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_SCIRXINTA/ECSoC'
 * '<S244>' : 'mcb_pmsm_foc_hall_f28069m/HW Interrupt/Code Generation/HWI_SCIRXINTA/ECSoC/ECSimCodegen'
 * '<S245>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Capture Event Selection'
 * '<S246>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity'
 * '<S247>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/HallValidity'
 * '<S248>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/eCAP'
 * '<S249>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Capture Event Selection/Output 0'
 * '<S250>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Capture Event Selection/Output 1'
 * '<S251>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem'
 * '<S252>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S253>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls'
 * '<S254>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S255>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S256>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S257>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S258>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S259>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S260>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S261>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S262>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S263>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S264>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/HallValidity/CodeGen'
 * '<S265>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor A/eCAP/Code generation'
 * '<S266>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Capture Event Selection'
 * '<S267>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity'
 * '<S268>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/HallValidity'
 * '<S269>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/eCAP'
 * '<S270>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Capture Event Selection/Output 0'
 * '<S271>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Capture Event Selection/Output 1'
 * '<S272>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem'
 * '<S273>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S274>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls'
 * '<S275>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S276>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S277>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S278>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S279>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S280>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S281>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S282>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S283>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S284>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S285>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/HallValidity/CodeGen'
 * '<S286>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor B/eCAP/Code generation'
 * '<S287>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Capture Event Selection'
 * '<S288>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity'
 * '<S289>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/HallValidity'
 * '<S290>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/eCAP'
 * '<S291>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Capture Event Selection/Output 0'
 * '<S292>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Capture Event Selection/Output 1'
 * '<S293>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem'
 * '<S294>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S295>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls'
 * '<S296>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S297>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S298>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S299>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S300>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S301>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S302>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S303>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S304>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S305>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S306>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/HallValidity/CodeGen'
 * '<S307>' : 'mcb_pmsm_foc_hall_f28069m/Hall Sensor C/eCAP/Code generation'
 * '<S308>' : 'mcb_pmsm_foc_hall_f28069m/Hardware Init/Variant Subsystem'
 * '<S309>' : 'mcb_pmsm_foc_hall_f28069m/Hardware Init/Variant Subsystem/Code Generation'
 * '<S310>' : 'mcb_pmsm_foc_hall_f28069m/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset '
 * '<S311>' : 'mcb_pmsm_foc_hall_f28069m/Hardware Init/Variant Subsystem/Code Generation/DRV Enable'
 * '<S312>' : 'mcb_pmsm_foc_hall_f28069m/Hardware Init/Variant Subsystem/Code Generation/Default ADC Offset'
 * '<S313>' : 'mcb_pmsm_foc_hall_f28069m/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem'
 * '<S314>' : 'mcb_pmsm_foc_hall_f28069m/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem'
 * '<S315>' : 'mcb_pmsm_foc_hall_f28069m/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem1'
 * '<S316>' : 'mcb_pmsm_foc_hall_f28069m/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem2'
 * '<S317>' : 'mcb_pmsm_foc_hall_f28069m/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem3'
 * '<S318>' : 'mcb_pmsm_foc_hall_f28069m/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S319>' : 'mcb_pmsm_foc_hall_f28069m/Heartbeat LED/Heartbeat LED'
 * '<S320>' : 'mcb_pmsm_foc_hall_f28069m/Heartbeat LED/Heartbeat LED/Code generation'
 * '<S321>' : 'mcb_pmsm_foc_hall_f28069m/Inverter and Motor - Plant Model/Codegeneration'
 * '<S322>' : 'mcb_pmsm_foc_hall_f28069m/Serial Receive/Data_Conditioning'
 * '<S323>' : 'mcb_pmsm_foc_hall_f28069m/Serial Receive/SCI_Rx'
 * '<S324>' : 'mcb_pmsm_foc_hall_f28069m/Serial Receive/SCI_Rx/Code Generation'
 * '<S325>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed'
 * '<S326>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/Speed_Ref_Selector'
 * '<S327>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S328>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S329>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S330>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S331>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S332>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S333>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S334>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S335>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S336>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S337>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S338>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S339>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S340>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S341>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S342>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S343>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S344>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S345>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S346>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S347>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S348>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S349>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S350>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S351>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S352>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S353>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S354>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S355>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S356>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S357>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S358>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S359>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S360>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S361>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S362>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S363>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S364>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S365>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S366>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S367>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S368>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S369>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S370>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S371>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S372>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S373>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S374>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S375>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S376>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S377>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S378>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/Speed_Ref_Selector/IIR Filter'
 * '<S379>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/Speed_Ref_Selector/IIR Filter/IIR Filter'
 * '<S380>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/Speed_Ref_Selector/IIR Filter/IIR Filter/Low-pass'
 * '<S381>' : 'mcb_pmsm_foc_hall_f28069m/Speed Control/Speed_Ref_Selector/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                             /* RTW_HEADER_mcb_pmsm_foc_hall_f28069m_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
