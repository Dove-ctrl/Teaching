#include "vex.h"

using namespace vex;

competition Competition;
chassis Chassis = chassis();

void pre_auton(void) {
  /* 
      初始化陀螺仪
  */
  Inertial.calibrate();
  waitUntil(!Inertial.isCalibrating());
}

void autonomous(void) {
  Chassis.ChassisRoute();
}

void usercontrol(void) {
  
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  /* 
      创建线程，用于底盘总驱动
  */
  thread chassis_thread = thread(ChassisDrive , &Chassis);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
