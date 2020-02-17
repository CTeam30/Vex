#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Vision3__GREEN_CUBE = signature (1, -6983, -6333, -6658, -4443, -3931, -4186, 11, 0);
signature Vision3__SIG_2 = signature (2, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision3__SIG_3 = signature (3, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision3__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision3__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision3__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 3, 0);
signature Vision3__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 3, 0);
vision Vision3 = vision (PORT11, 50, Vision3__GREEN_CUBE, Vision3__SIG_2, Vision3__SIG_3, Vision3__SIG_4, Vision3__SIG_5, Vision3__SIG_6, Vision3__SIG_7);
/*vex-vision-config:end*/
motor Arm1 = motor(PORT18, ratio18_1, false);
motor Arm2 = motor(PORT2, ratio18_1, true);
motor LeftMotorBack5 = motor(PORT5, ratio18_1, false);
motor RightMotorBack6 = motor(PORT17, ratio18_1, false);
motor LeftMotorFront20 = motor(PORT20, ratio18_1, false);
motor RightMotorFront14 = motor(PORT13, ratio18_1, false);
controller Controller1 = controller(primary);
motor Claw18 = motor(PORT15, ratio18_1, false);
motor ArmExtender19 = motor(PORT16, ratio18_1, false);

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
        Claw18.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR2.pressing()) {
        Claw18.spin(reverse);
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