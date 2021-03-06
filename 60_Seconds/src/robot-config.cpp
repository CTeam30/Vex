#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftMotorBack5 = motor(PORT5, ratio18_1, false);
motor RightMotorBack6 = motor(PORT6, ratio18_1, false);
motor LeftMotorFront20 = motor(PORT20, ratio18_1, false);
motor RightMotorFront14 = motor(PORT13, ratio18_1, false);
motor Arm1 = motor(PORT1, ratio18_1, true);
motor Arm2 = motor(PORT2, ratio18_1, false);
motor ArmExtender19 = motor(PORT19, ratio18_1, false);
motor Claw18 = motor(PORT10, ratio18_1, false);
controller Controller1 = controller(primary);
inertial Inertial11 = inertial(PORT11);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1RightShoulderControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_callback_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // check the ButtonR1/ButtonR2 status to control Claw18
      if (Controller1.ButtonR1.pressing()) {
        Claw18.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR2.pressing()) {
        Claw18.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (!Controller1RightShoulderControlMotorsStopped) {
        Claw18.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1RightShoulderControlMotorsStopped = true;
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_callback_Controller1);
}