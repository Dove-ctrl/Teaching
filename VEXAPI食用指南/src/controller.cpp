#include "vex.h"

//这里只会介绍常用的函数，其他的可以自己探索

void controller_API(){
    /* 
        遥控器按键函数

        这些函数都是用来获取遥控器的电信号，从而可以控制机器人运动，
        其中，摇杆的返回值是-100到100的数字，按键的返回值是bool类型。
     */
    Controller.Axis1.position();
    Controller.Axis2.position();
    Controller.Axis3.position();
    Controller.Axis4.position();
    Controller.ButtonA.pressing();
    Controller.ButtonB.pressing();
    Controller.ButtonX.pressing();
    Controller.ButtonY.pressing();
    Controller.ButtonUp.pressing();
    Controller.ButtonDown.pressing();
    Controller.ButtonLeft.pressing();
    Controller.ButtonRight.pressing();
    Controller.ButtonL1.pressing();
    Controller.ButtonL2.pressing();
    Controller.ButtonR1.pressing();
    Controller.ButtonR2.pressing();

    /* 
        遥控器屏幕控制函数

        这些函数都是用于控制遥控器屏幕显示的函数，
        一般情况下不需要深究，主要是为了方便显示遥测数据，
        可以用主控显示代替。
     */
    Controller.Screen.clearLine(1);
    Controller.Screen.clearScreen();
    Controller.Screen.print("abc");
}