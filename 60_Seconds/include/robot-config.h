using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftMotorBack5;
extern motor RightMotorBack6;
extern motor LeftMotorFront20;
extern motor RightMotorFront14;
extern motor Arm1;
extern motor Arm2;
extern motor ArmExtender19;
extern motor Claw18;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );