
//~ Helpers
void MotorMoveAbsoluteAndWait(u8 Motor, f64 Position, f64 Velocity){
 motor_move_absolute(Motor, 0, GEARSET_36_MAX_VELOCITY);
 
 const f64 Epsilon = 0.001;
 
 while(true){
  if(fabs(motor_get_position(Motor)-Position) <= Epsilon) break;
  delay(1);
 }
}

void MotorMoveRelativeAndWait(u8 Motor, f64 Position, f64 Velocity){
 f64 StartP = motor_get_position(Motor);
 motor_move_relative(Motor, 0, GEARSET_36_MAX_VELOCITY);
 
 const f64 Epsilon = 0.001;
 
 while(true){
  if(fabs(motor_get_position(Motor)-StartP-Position) <= Epsilon) break;
  delay(1);
 }
}

//~ Match autonomous routines

// Grab short yellow tower
void MatchAutonomousA(){
 ChassisMoveAndWait(&RobotChassis, Inch(48));
 ChassisMoveAndWait(&RobotChassis, -Inch(28));
 ChassisMoveAndWait(&RobotChassis, -Inch(20));
}

// Aalliance tower on AWP line
void MatchAutonomousB(){
 ChassisMoveAndWait(&RobotChassis, Inch(12));
 // Something here to drop the autonomous preload into the tower
 ChassisMoveAndWait(&RobotChassis, -Inch(12));
}

// Alliance tower on ramp
void MatchAutonomousC(){
 ChassisMoveAndWait(&RobotChassis, Inch(12));
 // Something here to drop the autonomous preload into the tower
 ChassisMoveAndWait(&RobotChassis, -Inch(12));
}


// Grab short yellow tower and alliance tower on AWP line
void MatchAutonomousD(){
 // Grab short yellow tower
 ChassisMoveAndWait(&RobotChassis, Inch(48));
 ChassisMoveAndWait(&RobotChassis, -Inch(28));
 ChassisMoveAndWait(&RobotChassis, -Inch(20));
 
 // Do alliance tower
 ChassisRotateAndWait(&RobotChassis, 45);
 ChassisMoveAndWait(&RobotChassis, Inch(12));
 // Something here to drop the autonomous preload into the tower
 ChassisMoveAndWait(&RobotChassis, -Inch(12));
}

void MatchAutonomousE(){
}


//~ Skills autonomous
void SkillsAutonomousA(){
 
}

//~ 
void autonomous(){
 if(lv_tabview_get_tab_act(AutonomousSelector.Tabview) == 0) return;
 
 switch(AutonomousSelector.Selected){
  case MatchAutonomous_A:  MatchAutonomousA();  break;
  case MatchAutonomous_B:  MatchAutonomousB();  break;
  case MatchAutonomous_C:  MatchAutonomousC();  break;
  case MatchAutonomous_D:  MatchAutonomousD();  break;
  case MatchAutonomous_E:  MatchAutonomousE();  break;
  case SkillsAutonomous_A: SkillsAutonomousA(); break;
 }
}
