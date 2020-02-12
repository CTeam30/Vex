using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LeftMotorBack5;
extern motor RightMotorBack6;
extern motor RightMotorFront14;
extern motor LeftMotorFront20;
extern inertial Inertial11;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );