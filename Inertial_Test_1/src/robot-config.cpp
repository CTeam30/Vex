#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftMotorBack5 = motor(PORT5, ratio18_1, false);
motor RightMotorBack6 = motor(PORT6, ratio18_1, false);
motor RightMotorFront14 = motor(PORT13, ratio18_1, false);
motor LeftMotorFront20 = motor(PORT20, ratio18_1, false);
inertial Inertial11 = inertial(PORT11);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}