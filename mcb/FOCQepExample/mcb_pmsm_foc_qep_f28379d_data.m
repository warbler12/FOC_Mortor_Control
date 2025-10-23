% Model         :   PMSM Field Oriented Control
% Description   :   Set Parameters for PMSM Field Oriented Control
% File name     :   mcb_pmsm_foc_qep_f28379d_data.m

% Copyright 2020-2022 The MathWorks, Inc.

%% Set PWM Switching frequency
PWM_frequency 	= 20e3;             %Hz     // converter s/w freq
T_pwm           = 1/PWM_frequency;  %s      // PWM switching time period

%% Set Sample Times
Ts          	= T_pwm;            %sec    // Sample time for control system
Ts_simulink     = T_pwm/2;          %sec    // Simulation time step for model simulation
Ts_motor        = T_pwm/2;          %Sec    // Simulation time step for pmsm
Ts_inverter     = T_pwm/2;          %sec    // Simulation time step for inverter
Ts_speed        = 10*Ts;            %Sec    // Sample time for speed controller

%% Set data type for controller & code-gen
% dataType = fixdt(1,32,17);        % Fixed point code-generation
dataType = 'single';                % Floating point code-generation

%% System Parameters 
% Motor parameters
pmsm = mcb_SetPMSMMotorParameters('42jsf630as');
pmsm.Rs = 1.02;          % 定子电阻 (Ohm)
pmsm.Ld = 0.00059;       % D轴电感 (H) 
pmsm.Lq = 0.00059;       % Q轴电感 (H) - 假设Ld = Lq
%pmsm.FluxPM = 0.0323;    % 永磁体磁链 (Wb) - 计算得出，见下方说明
pmsm.p = 4;             % 极对数
pmsm.I_rated = 4.0;      % 额定电流 (A) - 峰值
pmsm.N_rated = 3000;     % 额定转速 (RPM)
pmsm.N_max = 4000;     
pmsm.N_base = 3885;   
pmsm.Vdc = 24.0;         % 直流母线电压 (V)
pmsm.QEPSlits = 1000;

% 可选参数
pmsm.J = 1e-4;           % 转动惯量 (kg·m²) - 估计值，需要调整
pmsm.B = 1e-5;           % 摩擦系数 - 估计值
pmsm.PositionOffset = PositionOffset;         % 0.0638 Per-Unit position offset

%% Target & Inverter Parameters
target = mcb_SetProcessorDetails('F28379D',PWM_frequency);
target.comport = '<Select a port...>';
% target.comport = 'COM3';       % Uncomment and update the appropriate serial port

inverter = mcb_SetInverterParameters('BoostXL-DRV8305');

% Enable automatic calibration of ADC offset for current measurement
inverter.ADCOffsetCalibEnable = 1;  % Enable: 1, Disable:0 

% If automatic ADC offset calibration is disabled, uncomment and update the 
% offset values below manually
% inverter.CtSensAOffset = 2295;      % ADC Offset for phase current A 
% inverter.CtSensBOffset = 2286;      % ADC Offset for phase current B

% Update inverter.ISenseMax based for the chosen motor and target
inverter = mcb_updateInverterParameters(pmsm,inverter,target);

% Max and min ADC counts for current sense offsets
inverter.CtSensOffsetMax = 2500;    % Maximum permitted ADC counts for current sense offset
inverter.CtSensOffsetMin = 1500;    % Minimum permitted ADC counts for current sense offset

%% Derive Characteristics
pmsm.N_base = mcb_getBaseSpeed(pmsm,inverter); %rpm // Base speed of motor at given Vdc

% mcb_getCharacteristics(pmsm,inverter);

%% PU System details // Set base values for pu conversion

PU_System = mcb_SetPUSystem(pmsm,inverter);

%% Controller design // Get ballpark values!

PI_params = mcb_SetControllerParameters(pmsm,inverter,PU_System,T_pwm,Ts,Ts_speed);

% 手动覆盖为安全参数
PI_params.Kp_i = 3;
PI_params.Ki_i = 0.8;
PI_params.Kp_id = 3; 
PI_params.Ki_id = 0.5;
PI_params.Kp_speed = 0.8;
PI_params.Ki_speed = 0.2;

%Updating delays for simulation
PI_params.delay_Currents    = int32(Ts/Ts_simulink);
PI_params.delay_Position    = int32(Ts/Ts_simulink);
PI_params.delay_Speed       = int32(Ts_speed/Ts_simulink);
PI_params.delay_Speed1      = (PI_params.delay_IIR + 0.5*Ts)/Ts_speed;

% mcb_getControlAnalysis(pmsm,inverter,PU_System,PI_params,Ts,Ts_speed); 

%% Displaying model variables
disp(pmsm);
disp(inverter);
disp(target);
disp(PU_System);
