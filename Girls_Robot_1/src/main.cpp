/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Arm1                 motor         10              
// Arm2                 motor         2               
// Claw18               motor         16              
// RightMotorFront14    motor         11              
// LeftMotorFront20     motor         20              
// RightMotorBack6      motor         12              
// LeftMotorBack5       motor         19              
// Controller1          controller                    
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

  Arm1.setStopping(hold);
  Arm2.setStopping(hold);
 // ArmExtender19.setStopping(hold);
  Claw18.setStopping(hold);
  LeftMotorBack5.setStopping(hold);
  RightMotorBack6.setStopping(hold);
  LeftMotorFront20.setStopping(hold);
  RightMotorFront14.setStopping(hold);
  
  Arm1.setMaxTorque(100, percent);
  Arm2.setMaxTorque(100, percent);
 // ArmExtender19.setMaxTorque(100,percent);
  Claw18.setMaxTorque(100, percent);
  LeftMotorBack5.setMaxTorque(100, percent);
  RightMotorBack6.setMaxTorque(100, percent);
  LeftMotorFront20.setMaxTorque(100, percent);
  RightMotorFront14.setMaxTorque(100, percent);
  
  Arm1.setVelocity(100, percent);
  Arm2.setVelocity(100, percent);
 // ArmExtender19.setVelocity(100,percent);
  Claw18.setVelocity(25, percent);
  LeftMotorBack5.setVelocity(100, percent);
  RightMotorBack6.setVelocity(100, percent);
  LeftMotorFront20.setVelocity(100, percent);
  RightMotorFront14.setVelocity(100, percent);
  
  Brain.Screen.print("Pre Auton Run");

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
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

int clawbool = true;

void ClawHold() {
  if (clawbool) {
    Claw18.setMaxTorque(100, percent);
    Claw18.setVelocity(20, percent);
    Claw18.spinFor(-50, degrees, clawbool);
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

  ArmMove = 250;
  Arm();

  DriveSpeed = 40;
  DriveMove = 300;
  Drive();

  //ArmMove = 200;
  //Arm();

  TurnMove = 650;
  Turn();

  DriveSpeed = 40;
  DriveMove = 1100;
  Drive(); 

  //TurnMove = 300;
  //Turn();

  DriveSpeed = 40;
  DriveMove = -200;
  Drive();

  clawbool = false;

  Brain.Screen.print(clawbool);

  Claw18.spinFor(25, degrees, true);

  task::sleep(500);

  //clawbool = false;

  //Brain.Screen.print(clawbool);

  //Claw18.spinFor(200, degrees, true);

  //ArmMove = -200;
 // Arm();

 // task::sleep(500);

  DriveSpeed = 40;
  DriveMove = 150;
  Drive();

  DriveSpeed = 40;
  DriveMove = -200;
  Drive();

  TurnMove = -550;
  Turn();

  DriveSpeed = 40;
  DriveMove = -400;
  Drive();

  ArmMove = -360;
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

void usercontrol(void) {
  // User control code here, inside the loop
  Controller1.rumble(rumbleShort);

  while (true) {
      

      LeftMotorBack5.spin(directionType::fwd, Controller1.Axis4.value() + Controller1.Axis3.value() / 1, velocityUnits::pct); //(Axis3+Axis4)/2;
      RightMotorBack6.spin(directionType::fwd, Controller1.Axis4.value() - Controller1.Axis3.value() / 1, velocityUnits::pct);//(Axis3-Axis4)/2;
      
      LeftMotorFront20.spin(directionType::fwd, Controller1.Axis4.value() + Controller1.Axis3.value() / 1, velocityUnits::pct); //(Axis3+Axis4)/2;
      RightMotorFront14.spin(directionType::fwd, Controller1.Axis4.value() - Controller1.Axis3.value() / 1, velocityUnits::pct);//(Axis3-Axis4)/2;
      
      //Arm Motor
      if((Controller1.Axis2.value() == 0)) {
        
        Arm1.stop();
        Arm2.stop();
       // task::sleep(1);

      }
      
      while ((Controller1.Axis2.value() >= 10)) {

        Arm1.spin(directionType::fwd, Controller1.Axis2.value()/1.4, velocityUnits::pct);
        Arm2.spin(directionType::fwd, Controller1.Axis2.value()/1.4, velocityUnits::pct);
        //task::sleep(1);

      }

      while ((Controller1.Axis2.value() <= -10)) { 

        Arm1.spin(directionType::rev, Controller1.Axis2.value()/1.4 * -1, velocityUnits::pct);
        Arm2.spin(directionType::rev, Controller1.Axis2.value()/1.4 * -1, velocityUnits::pct);
        //task::sleep(1);
      
      }
      
/*
      //Arm Extender
      if((Controller1.Axis1.value() == 0)) {
        
        ArmExtender19.stop();
       // task::sleep(1);

      }
      
      while ((Controller1.Axis1.value() >= 10)) {

        ArmExtender19.spin(directionType::fwd, Controller1.Axis1.value()/2, velocityUnits::pct);
       // task::sleep(1);

      }

      while ((Controller1.Axis1.value() <= -10)) { 

        ArmExtender19.spin(directionType::rev, Controller1.Axis1.value()/2 * -1, velocityUnits::pct);
       // task::sleep(1);

      }

      if (Controller1.ButtonUp.pressing()) {
        AdjVel = AdjVel - 1;
       // task::sleep(500);
      }

      if (Controller1.ButtonDown.pressing()) {
        AdjVel = AdjVel + 1;
        //task::sleep(500);
      }
*/
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
