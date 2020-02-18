/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Shane Collins Team 1                                      */
/*    Created:      Wed Dec 04 2019                                           */
/*    Description:  This program will turn right 90 degrees using the         */
/*                  Inertial Sensor.                                          */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Arm1                 motor         18              
// Arm2                 motor         2               
// LeftMotorBack5       motor         5               
// RightMotorBack6      motor         17              
// LeftMotorFront20     motor         20              
// RightMotorFront14    motor         13              
// Controller1          controller                    
// Claw18               motor         15              
// ArmExtender19        motor         16              
// Inertial12           inertial      12              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int TurnSpeed = 20;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Inertial12.calibrate();
  // waits for the Inertial Sensor to calibrate
  while (Inertial12.isCalibrating()) {
    wait(100, msec);
  }
  

  while (true) {
    TurnSpeed = 90 - Inertial12.rotation(degrees);

    if (TurnSpeed <= 0) {
      TurnSpeed = TurnSpeed * -1;
    }

    Brain.Screen.clearScreen();

    Brain.Screen.print(TurnSpeed);

    LeftMotorBack5.setVelocity(TurnSpeed, percent);
    RightMotorFront14.setVelocity(TurnSpeed, percent);

    LeftMotorFront20.setVelocity(TurnSpeed, percent);
    RightMotorFront14.setVelocity(TurnSpeed, percent);


    if ((Inertial12.rotation(degrees) <= 89.0)){
      LeftMotorBack5.spin(forward);
      RightMotorBack6.spin(forward);

      LeftMotorFront20.spin(forward);
      RightMotorFront14.spin(forward);
      //wait(1, seconds);
    }

    else if ((Inertial12.rotation(degrees) >= 91.0)){
      LeftMotorBack5.spin(reverse);
      RightMotorBack6.spin(reverse);

      LeftMotorFront20.spin(reverse);
      RightMotorFront14.spin(reverse);
      //wait(1, seconds);
    }

    else {

    LeftMotorBack5.stop();
    RightMotorBack6.stop();

    LeftMotorFront20.stop();
    RightMotorFront14.stop();

    }
  }
  
  
  
  
  // Turns the robot to the right

  // Waits until the motor reaches a 90 degree turn and stops the Left and
  // Right Motors.

  
}
