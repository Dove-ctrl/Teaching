/* 
  3.  认识文件"main.cpp"

  这里是所有代码最终执行的地方，也就是main函数。
  
  在这里我不建议小白去修改这个文件的结构和代码，尤其是main函数，
  及其容易导致程序无法运行，后果自负。

  先说一下这个文件的结构：
    a.  pre_auto函数
        这个函数是最先执行的函数，程序一启动就开始执行，
        因此你可以在这里进行机器人系统的初始化，
        包括但不限于：惯导的校准，编码器的置零，算法的初始化。
    
    b.  autonomous函数
        这个函数是自动时段函数，比赛自动时段会执行这个函数，
        在这里面编写你的自动程序。

    c.  usercontrol函数
        这个函数是手动时段函数，比赛手动时段会执行这个函数，
        在这个里面编写你的手动程序。

  当非比赛时，遥控器没有接入场控就进入程序，默认是执行手动函数。

  我不建议你把所有代码都往这个文件里面塞，因为会显得很杂乱无章，后期修改起来异常困难，
  更好的做法是，这里只有一些基本的控制逻辑结构，
  具体怎么控制的，放到其他文件的函数里，main.cpp只需引用这些文件即可。
 */

#include "vex.h"

using namespace vex;

competition Competition;

void pre_auton(void) {
  
}

void autonomous(void) {
  
}

void usercontrol(void) {
  
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
