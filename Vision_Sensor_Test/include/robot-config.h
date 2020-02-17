using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern signature Vision3__GREEN_CUBE;
extern signature Vision3__SIG_2;
extern signature Vision3__SIG_3;
extern signature Vision3__SIG_4;
extern signature Vision3__SIG_5;
extern signature Vision3__SIG_6;
extern signature Vision3__SIG_7;
extern vision Vision3;
extern motor Arm1;
extern motor Arm2;
extern motor LeftMotorBack5;
extern motor RightMotorBack6;
extern motor LeftMotorFront20;
extern motor RightMotorFront14;
extern controller Controller1;
extern motor Claw18;
extern motor ArmExtender19;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );