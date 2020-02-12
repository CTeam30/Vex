/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\CTeam30                                          */
/*    Created:      Tue Feb 11 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftMotorBack5       motor         5               
// RightMotorBack6      motor         6               
// RightMotorFront14    motor         13              
// LeftMotorFront20     motor         20              
// Inertial11           inertial      11              
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"

using namespace vex;

int Speed = 50;
int AutonDegrees = 45;

void AutonTurn () {
  while(true) {
    LeftMotorBack5.setVelocity(Speed, pct);
    LeftMotorFront20.setVelocity(Speed, pct);
    RightMotorBack6.setVelocity(Speed, pct);
    RightMotorFront14.setVelocity(Speed, pct);  

    Speed = (Inertial11.heading(degrees) - AutonDegrees) * -1;

    

    LeftMotorBack5.spin(reverse);
    LeftMotorFront20.spin(reverse);
    RightMotorBack6.spin(forward);
    RightMotorFront14.spin(forward);

    if (Speed <= 1){
      LeftMotorBack5.stop();
      LeftMotorFront20.stop();
      RightMotorBack6.stop();
      RightMotorFront14.stop();
      break;
    }

    if(Speed <= 20) {
      Speed = 20;
    }
  }

}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Inertial11.calibrate();

  task::sleep(2000);

  //Inertial11.heading(degrees);

  

  Brain.Screen.print(Inertial11.heading(degrees));

  LeftMotorBack5.setVelocity(50, percent);
  RightMotorBack6.setVelocity(50, percent);
  RightMotorFront14.setVelocity(50,percent);
  RightMotorBack6.setVelocity(50, percent);

  Brain.Screen.print("Calling 45");

  AutonTurn();

  Brain.Screen.print("Finished 45");

  /*//while(Inertial11.heading(degrees))
  while(Inertial11.heading(degrees) < 45) {
    LeftMotorBack5.spinFor(forward, 1, degrees, false);
    LeftMotorFront20.spinFor(forward, 1, degrees, false);
  }

  while(Inertial11.heading(degrees) > 47) {
    RightMotorBack6.spin(reverse);
    RightMotorFront14.spin(reverse);
  }*/

/*
  while(true) {
      //LeftMotorBack5.spin(forward);
      //RightMotorBack6.spin(reverse);

      if (Inertial11.heading(degrees) > 2 && Inertial11.heading(degrees) < 180 ) {
        //Brain.Screen.print(Inertial11.heading(degrees));
        LeftMotorBack5.setVelocity(50, percent);
        LeftMotorBack5.spin(forward);
     }

     else {
       LeftMotorBack5.stop();
     }

      if (Inertial11.heading(degrees) < 358 && Inertial11.heading(degrees) > 180) {
          //Brain.Screen.print(Inertial11.heading(degrees));
          RightMotorBack6.setVelocity(50, percent);
          RightMotorBack6.spin(reverse);
      }

      else {
       RightMotorBack6.stop();
     }

  }
*/
}
