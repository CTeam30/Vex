/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Shane Collins Team 1 KCS                                  */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftMotorBack5       motor         5               
// RightMotorBack6      motor         17              
// LeftMotorFront20     motor         20              
// RightMotorFront14    motor         13              
// Arm1                 motor         18              
// Arm2                 motor         2               
// ArmExtender19        motor         16              
// Claw18               motor         15              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

  Arm1.setStopping(hold);
  Arm2.setStopping(hold);
  ArmExtender19.setStopping(hold);
  Claw18.setStopping(hold);
  LeftMotorBack5.setStopping(hold);
  RightMotorBack6.setStopping(hold);
  LeftMotorFront20.setStopping(hold);
  RightMotorFront14.setStopping(hold);
  
  Arm1.setMaxTorque(100, percent);
  Arm2.setMaxTorque(100, percent);
  ArmExtender19.setMaxTorque(100,percent);
  Claw18.setMaxTorque(100, percent);
  LeftMotorBack5.setMaxTorque(100, percent);
  RightMotorBack6.setMaxTorque(100, percent);
  LeftMotorFront20.setMaxTorque(100, percent);
  RightMotorFront14.setMaxTorque(100, percent);
  
  Arm1.setVelocity(100, percent);
  Arm2.setVelocity(100, percent);
  ArmExtender19.setVelocity(100,percent);
  Claw18.setVelocity(100, percent);
  LeftMotorBack5.setVelocity(100, percent);
  RightMotorBack6.setVelocity(100, percent);
  LeftMotorFront20.setVelocity(100, percent);
  RightMotorFront14.setVelocity(100, percent);
  
  Brain.Screen.print("Pre Auton Run");
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

/*
int ClawTmStp () {
  int tm = 0;
  while (tm <= 20) {
    tm = tm + 1;
    task::sleep(1000);
  }
  return (tm);
}
*/

int tm = 0;

void Clawtm() {
  int tm = 0;
  while (tm <= 20) {
    tm = tm + 1;
    task::sleep(1000);
    Brain.Screen.print(tm);
  }
}

int clawbool = true;

void ClawHold() {
  if (clawbool) {
    Claw18.setMaxTorque(100, percent);
    Claw18.setVelocity(100, percent);
    Claw18.spinFor(-350, degrees, clawbool);
  }
}

int Auton_Move = true;
int Speed = 50;
int Dist = 50;
int DistObj = 40;
int AutonDiv = 2;

int ArmMove = 0;

void Arm() {
  Arm1.spinFor(ArmMove, degrees, false);
  Arm2.spinFor(ArmMove, degrees, true);
}

int TurnMove = 0;

void Turn() {
  if (TurnMove >= 1) {
    LeftMotorBack5.spinFor(TurnMove, degrees, false);
    LeftMotorFront20.spinFor(TurnMove, degrees, true);
  }
  if (TurnMove <= -1) {
    RightMotorBack6.spinFor(TurnMove, degrees, false);
    RightMotorFront14.spinFor(TurnMove, degrees, true); 
  }
}

//int ClawMove = 0; 

/*void Claw() {
    Claw18.spinFor(ClawMove, degrees, true);
} */

int DriveMove = 0;
int DriveSpeed = 0;

void Drive() {
  LeftMotorBack5.setVelocity(DriveSpeed, percent);
  LeftMotorFront20.setVelocity(DriveSpeed, percent);
  RightMotorBack6.setVelocity(DriveSpeed, percent);
  RightMotorFront14.setVelocity(DriveSpeed, percent);

  LeftMotorBack5.spinFor(DriveMove, degrees, false);
  LeftMotorFront20.spinFor(DriveMove, degrees, false);
  RightMotorBack6.spinFor(DriveMove * -1, degrees, false);
  RightMotorFront14.spinFor(DriveMove * -1, degrees, true);
}


void autonomous(void) {

  //vex::task t3 (ClawTmStp);

  task::sleep(100);
  //LeftMotorBack5.spinFor(50, degrees, false);
 // RightMotorBack6.spinFor(-50, degrees, false);
  
  Claw18.setTimeout(1, sec);

  ClawHold();

  wait(0.5, seconds);

  Arm1.setVelocity(30, percent);
  Arm2.setVelocity(30, percent);

  ArmMove = 330;
  Arm();

  DriveSpeed = 40;
  DriveMove = 300;
  Drive();

  //ArmMove = 200;
  //Arm();

  TurnMove = 680;
  Turn();

  DriveSpeed = 40;
  DriveMove = 800;
  Drive(); 

  TurnMove = -50;
  Turn();

  DriveSpeed = 40;
  DriveMove = 250;
  Drive();

  //clawbool = false;

  //Brain.Screen.print(clawbool);

  //Claw18.spinFor(200, degrees, true);

  //ArmMove = -200;
 // Arm();

 // task::sleep(500);

  TurnMove = 130;
  Turn();

  DriveSpeed = 40;
  DriveMove = 100;
  Drive();

  DriveSpeed = 40;
  DriveMove = -100;
  Drive();

 // ArmMove = -130;
 // Arm();

  clawbool = false;

  Brain.Screen.print(clawbool);

  Claw18.spinFor(250, degrees, true);

  task::sleep(500);

 // TurnMove = -100;
  //Turn();

  DriveSpeed = 40;
  DriveMove = -400;
  Drive();

 // DriveSpeed = 40;
  //DriveMove = 400;
  //Drive();

  //DriveSpeed = 40;
 // DriveMove = -400;
 // Drive();

  ArmMove = -300;
  Arm();

  }


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
int AdjVel = 1;

int ContPrnt () {
  while (true) {
    //Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("Velocity: ");
    Controller1.Screen.print(AdjVel);
    //task::sleep(500);
    //Controller1.Screen.setCursor(3,1);
    //Controller1.Screen.print("Time: ");
    //Controller1.Screen.print(round(Brain.Timer.value()));
  // task::sleep(500); */
    Brain.Screen.setCursor(2,1);
    Brain.Screen.print("Claw temp: ");
    Brain.Screen.print(Claw18.temperature(percent));
    /*Controller1.Screen.setCursor(4,1);
    Controller1.Screen.print("Battery: ");
    Controller1.Screen.print(Brain.Battery.current()); */
    task::sleep(200);
    Brain.Screen.clearLine(2);
    Controller1.Screen.clearLine(3);
  }
  return(10);
}

/* int ContPrntTm () {
  while (true) {
    Controller1.Screen.setCursor(3,1);
    Controller1.Screen.print("Time: ");
    Controller1.Screen.print(round(Brain.Timer.value()));
    task::sleep(1000);
    Controller1.Screen.clearScreen();
  }
  return(10);
} */

void usercontrol(void) {
  // User control code here, inside the loop

  int WheelsFailSafe = 0;
  vex::task t1 (ContPrnt);
 // vex::task t2 (ContPrntTm);
  Controller1.rumble(rumbleShort);
  
  while (true) {
      
      if (WheelsFailSafe == 0) {
        LeftMotorBack5.spin(directionType::fwd, Controller1.Axis4.value() + Controller1.Axis3.value() / AdjVel, velocityUnits::pct); //(Axis3+Axis4)/2;
        RightMotorBack6.spin(directionType::fwd, Controller1.Axis4.value() - Controller1.Axis3.value() / AdjVel, velocityUnits::pct);//(Axis3-Axis4)/2;
      }

      LeftMotorFront20.spin(directionType::fwd, Controller1.Axis4.value() + Controller1.Axis3.value() / AdjVel, velocityUnits::pct); //(Axis3+Axis4)/2;
      RightMotorFront14.spin(directionType::fwd, Controller1.Axis4.value() - Controller1.Axis3.value() / AdjVel, velocityUnits::pct);//(Axis3-Axis4)/2;
      
      //Arm Motor
      if((Controller1.Axis2.value() == 0)) {
        
        Arm1.stop();
        Arm2.stop();
       // task::sleep(1);

      }
      
      if ((Controller1.Axis2.value() >= 10)) {

        Arm1.spin(directionType::fwd, Controller1.Axis2.value()/2, velocityUnits::pct);
        Arm2.spin(directionType::fwd, Controller1.Axis2.value()/2, velocityUnits::pct);
        //task::sleep(1);

      }

      if ((Controller1.Axis2.value() <= -10)) { 

        Arm1.spin(directionType::rev, Controller1.Axis2.value()/2 * -1, velocityUnits::pct);
        Arm2.spin(directionType::rev, Controller1.Axis2.value()/2 * -1, velocityUnits::pct);
        //task::sleep(1);
      
      }
      

      //Arm Extender
      if((Controller1.Axis1.value() == 0)) {
        
        ArmExtender19.stop();
       // task::sleep(1);

      }
      
      if ((Controller1.Axis1.value() >= 10)) {

        ArmExtender19.spin(directionType::fwd, Controller1.Axis1.value()/2, velocityUnits::pct);
       // task::sleep(1);

      }

      if ((Controller1.Axis1.value() <= -10)) { 

        ArmExtender19.spin(directionType::rev, Controller1.Axis1.value()/2 * -1, velocityUnits::pct);
       // task::sleep(1);

      }

      if (Controller1.ButtonUp.pressing()) {
        AdjVel = AdjVel - 1;
        task::sleep(100);
      }

      if (Controller1.ButtonDown.pressing()) {
        AdjVel = AdjVel + 1;
        task::sleep(100);
      }

      if (AdjVel <= 0 ) {
        AdjVel = 1;
       // task::sleep(100);
      }

      if (Controller1.ButtonB.pressing()) {
        LeftMotorBack5.setVelocity(50, percent);
        RightMotorBack6.setVelocity(50, percent);
        LeftMotorFront20.setVelocity(50, percent);
        RightMotorFront14.setVelocity(50, percent);

        LeftMotorBack5.spinFor(-300, degrees, false);
        RightMotorBack6.spinFor(300, degrees, false);
        LeftMotorFront20.spinFor(-300, degrees, false);
        RightMotorFront14.spinFor(300, degrees, true);

        LeftMotorBack5.setVelocity(100, percent);
        RightMotorBack6.setVelocity(100, percent);
        LeftMotorFront20.setVelocity(100, percent);
        RightMotorFront14.setVelocity(100, percent);

      }

      if (Controller1.ButtonX.pressing()) {
        WheelsFailSafe = WheelsFailSafe + 1;
        task::sleep(200);
      }

      if (WheelsFailSafe >= 2) {
        WheelsFailSafe = 0;
      }

      if (WheelsFailSafe == 1) {
        LeftMotorBack5.setStopping(coast);
        RightMotorBack6.setStopping(coast);
      }

      if (WheelsFailSafe != 1) {
        LeftMotorBack5.setStopping(hold);
        RightMotorBack6.setStopping(hold);
      }
     task::sleep(20);
    }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
