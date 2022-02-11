
#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS


//~ Library includes
#include "api.h"
#include "pros/apix.h"
#include "assert.h"

#include "okapi/api.hpp"

using namespace pros;
using namespace pros::c;
using namespace pros::literals;
using namespace okapi::literals;

//~ includes
#include "tyler_basics.h"
#include "robot_basics.h"

#include "chassis.h"

//~ Constants
global_constant f64 MillisecondsPerTick = 10;

global_constant u8 LeftDriveMotor  =  1;
global_constant u8 RightDriveMotor = 11;

global_constant u8 LiftMotor = 12;
global_constant u8 WristMotor = 20;
global_constant u8 ClawMotor = 9;

global_constant u8 LiftDownLimitSwitch = 'A';
global_constant u8 LiftUpLimitSwitch = 'H';

//~ Autonomous selector

const char *MatchButtonsMap[] = {
 "None",
 "Auto A",
 "Auto B",
 "Auto C",
 "Auto D",
 "Auto E",
 "",
};

const char *SkillsButtonsMap[] = {
 "Auto A",
 "",
};

enum autonomous_mode {
 Autonomous_None    = 0,
 
 MatchAutonomous_A  = 1,
 MatchAutonomous_B  = 2,
 MatchAutonomous_C  = 3,
 MatchAutonomous_D  = 4,
 MatchAutonomous_E  = 5,
 
 SkillsAutonomous_A = 6,
 
 // NOTE(Tyler): Always keep at the end
 Autonomous_TOTAL
};

enum autonomous_selector_tab {
 AutonomousSelectorTab_None   = 0,
 AutonomousSelectorTab_Match  = 1,
 AutonomousSelectorTab_Skills = 2,
};

struct autonomous_selector {
 autonomous_mode Selected;
 
 lv_obj_t *Tabview;
 
 lv_obj_t *MatchPage;
 lv_obj_t *MatchMatrix;
 
 lv_obj_t *SkillsPage;
 lv_obj_t *SkillsMatrix;
};


//~ NOTE(Tyler): Declared here so the ones that aren't used are rememembered
void initialize(void);
void competition_initialize(void);
void disabled(void);
void autonomous(void);
void opcontrol(void);

#endif  // _PROS_MAIN_H_
