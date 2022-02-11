
//~ Driver control
void
opcontrol(){
    b8 SlowModeOn;
    b8 InvertModeOn;
    b8 OpenClawOn;
    
    u32 PreviousTime = millis();
    f64 dTime = (f64)MillisecondsPerTick / 1000;
    while(true)
    {
        //~ Movement
        s16 Forward = controller_get_analog(E_CONTROLLER_MASTER, ANALOG_LEFT_Y);
        s16 Turn = controller_get_analog(E_CONTROLLER_MASTER, ANALOG_RIGHT_X);
        
        if(controller_get_digital_new_press(E_CONTROLLER_MASTER, DIGITAL_X)){
            SlowModeOn = !SlowModeOn;
        }
        
        if(SlowModeOn){
            Forward /= 2;
            Turn   /= 2;
        }
        
        if(controller_get_digital_new_press(E_CONTROLLER_MASTER, DIGITAL_Y)){
            InvertModeOn = !InvertModeOn;
        }
        
        if(InvertModeOn){
            Forward = -Forward;
        }
        
        motor_move(LeftDriveMotor, Forward+Turn);
        motor_move(RightDriveMotor, Forward-Turn);
        
        //~ Lift
        if(controller_get_digital(E_CONTROLLER_MASTER, DIGITAL_R1) &&
           !adi_digital_read(LiftUpLimitSwitch)){
            motor_move_velocity(LiftMotor, 100);
        }else if(controller_get_digital(E_CONTROLLER_MASTER, DIGITAL_R2) &&
                 !adi_digital_read(LiftDownLimitSwitch)){
            motor_move_velocity(LiftMotor, -100);
        }else{
            motor_move_velocity(LiftMotor, 0);
        }
        
        //~ Wrist
        if(controller_get_digital(E_CONTROLLER_MASTER, DIGITAL_DOWN)){
            motor_move_velocity(WristMotor, 100);
        }else if(controller_get_digital(E_CONTROLLER_MASTER, DIGITAL_UP)){
            motor_move_velocity(WristMotor, -100);
        }else{
            motor_move_velocity(WristMotor, 0);
        }
        
        //~Claw
#if 0
        if(controller_get_digital(E_CONTROLLER_MASTER, DIGITAL_LEFT)){
            motor_move_velocity(ClawMotor, -100);
        }else if(controller_get_digital(E_CONTROLLER_MASTER, DIGITAL_RIGHT)){
            motor_move_velocity(ClawMotor, 100);
        }else{
            motor_move_velocity(ClawMotor, 0);
        }
#endif
        
        if(controller_get_digital_new_press(E_CONTROLLER_MASTER, DIGITAL_LEFT)){
            motor_move_absolute(9,-500, (s32)Gearset36MaxVelocity);
        }
        
        
        if(controller_get_digital_new_press(E_CONTROLLER_MASTER, DIGITAL_RIGHT)){
            motor_move_absolute(9,0, (s32)Gearset36MaxVelocity);
        }
        
        task_delay_until(&PreviousTime, MillisecondsPerTick);
    }
}