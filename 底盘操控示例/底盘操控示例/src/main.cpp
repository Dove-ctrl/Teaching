#include "vex.h"

using namespace vex;

competition Competition;

void pre_auton(void) {
  
}

void autonomous(void) {
  
}

void usercontrol(void) {
  //循环不断刷新电机的电压值
  //摇杆3前后推，机器前后走，摇杆1左右推，机器左右转
  while(true){
    LF.spin(fwd , (Controller.Axis3.position() + Controller.Axis1.position()) * 120 , voltageUnits::mV);
    LM.spin(fwd , (Controller.Axis3.position() + Controller.Axis1.position()) * 120 , voltageUnits::mV);
    LB.spin(fwd , (Controller.Axis3.position() + Controller.Axis1.position()) * 120 , voltageUnits::mV);
    RF.spin(fwd , (Controller.Axis3.position() - Controller.Axis1.position()) * 120 , voltageUnits::mV);
    RM.spin(fwd , (Controller.Axis3.position() - Controller.Axis1.position()) * 120 , voltageUnits::mV);
    RB.spin(fwd , (Controller.Axis3.position() - Controller.Axis1.position()) * 120 , voltageUnits::mV);
    wait(10,msec);//调整刷新的速率
  }
}

//main函数不做任何更改
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
