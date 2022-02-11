#include <math.h>

#include "main.h"

global autonomous_selector AutonomousSelector;
global basic_chassis   RobotChassis;

#include "chassis.cpp"
#include "gui.cpp"
#include "opcontrol.cpp"
#include "autonomous.cpp"

//~ Initialization
void initialize(){ 
    InitGUI();
    
    motor_set_reversed( LeftDriveMotor, false);
    motor_set_reversed(RightDriveMotor,  true);
    motor_set_brake_mode(LiftMotor, E_MOTOR_BRAKE_HOLD);
    motor_set_brake_mode(WristMotor, E_MOTOR_BRAKE_HOLD);
    motor_set_brake_mode(ClawMotor, E_MOTOR_BRAKE_HOLD);
    motor_set_encoder_units(ClawMotor, E_MOTOR_ENCODER_DEGREES);
}

//~ Competition initialization
void competition_initialize(){
}

//~ Disabled
void disabled(){
}
