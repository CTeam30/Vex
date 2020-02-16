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
// RightMotorBack6      motor         6               
// LeftMotorFront20     motor         20              
// RightMotorFront14    motor         13              
// Arm1                 motor         1               
// Arm2                 motor         2               
// ArmExtender19        motor         19              
// Claw18               motor         10              
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

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
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
int WheelsFailSafe = 0;

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
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print(WheelsFailSafe);
    
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
