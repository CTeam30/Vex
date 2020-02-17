/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\shane                                            */
/*    Created:      Fri Feb 14 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Vision3              vision        11              
// Arm1                 motor         18              
// Arm2                 motor         2               
// LeftMotorBack5       motor         5               
// RightMotorBack6      motor         17              
// LeftMotorFront20     motor         20              
// RightMotorFront14    motor         13              
// Controller1          controller                    
// Claw18               motor         15              
// ArmExtender19        motor         16              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int AdjVel = 1;
int WheelsFailSafe = 0;

//int ContPrnt () {
  //while (true) {
    //Controller1.Screen.setCursor(1,1);
  //  Controller1.Screen.print("Velocity: ");
 //   Controller1.Screen.print(AdjVel);
    //task::sleep(500);
    //Controller1.Screen.setCursor(3,1);
    //Controller1.Screen.print("Time: ");
    //Controller1.Screen.print(round(Brain.Timer.value()));
  // task::sleep(500); */
 //   Brain.Screen.setCursor(2,1);
//    Brain.Screen.print("Claw temp: ");
 //   Brain.Screen.print(Claw18.temperature(percent));
    /*Controller1.Screen.setCursor(4,1);
    Controller1.Screen.print("Battery: ");
    Controller1.Screen.print(Brain.Battery.current()); */
   // Brain.Screen.setCursor(4, 4);
 //   Brain.Screen.print(WheelsFailSafe);
    
  //  task::sleep(200);
 //   Brain.Screen.clearLine(2);
 //   Controller1.Screen.clearLine(3);
//  }
//  return(10);
//}


int MOEH = 0;
int MovingArm = false;

int MOEW = 0;
int MovingDrive = false;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Arm1.setVelocity(40, percent);
  Arm2.setVelocity(40,percent);

  Arm1.setStopping(hold);
  Arm2.setStopping(hold);

  while (true) {

  //Arm

    Vision3.takeSnapshot(Vision3__GREEN_CUBE);
    MOEH = Vision3.largestObject.height / 3;
    MovingArm = false;

    if (not Vision3.largestObject.exists) {
        task::sleep(300);
        Arm1.stop();
        Arm2.stop();
      }
    

    if (Vision3.largestObject.exists) {
      if (Vision3.largestObject.centerY > 106 + MOEH) {
        MovingArm = true;
        Arm1.spin(forward);
        Arm2.spin(forward);
      }

      else if (Vision3.largestObject.centerY < 106 - MOEH) {
        MovingArm = true;
        Arm1.spin(reverse);
        Arm2.spin(reverse);
      }

      else  {
        Arm1.stop();
        Arm2.stop();
      }

      
    }

    //Drive

    //Vision3.takeSnapshot(Vision3__GREEN_CUBE);
    MOEW = Vision3.largestObject.width / 2;
    MovingDrive = false;

    if (not Vision3.largestObject.exists) {
        task::sleep(50);
        LeftMotorBack5.stop();
        LeftMotorFront20.stop();
        RightMotorBack6.stop();
        RightMotorFront14.stop();
      }
    

    if (Vision3.largestObject.exists) {
      if (Vision3.largestObject.centerX > 158 + MOEW) {
        MovingDrive = true;
        LeftMotorBack5.spin(forward);
        LeftMotorFront20.spin(forward);
        RightMotorBack6.spin(forward);
        RightMotorFront14.spin(forward);
      }

      else if (Vision3.largestObject.centerX < 158 - MOEW) {
        MovingDrive = true;
        RightMotorBack6.spin(reverse);
        RightMotorFront14.spin(reverse);
        LeftMotorBack5.spin(reverse);
        LeftMotorFront20.spin(reverse);
      }

      else  {
        RightMotorBack6.stop();
        RightMotorFront14.stop();
        LeftMotorBack5.stop();
        LeftMotorFront20.stop();
      }

      
    }
  }
}
















/*

//Driver Control
       
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
   */