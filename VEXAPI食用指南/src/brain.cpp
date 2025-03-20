#include "vex.h"

//这里只会介绍常用的函数，其他的可以自己探索

void brian_API(){
    /* 
        主控屏幕显示函数

        这些函数都是用于控制主控屏幕显示的函数，可以在屏幕上显示遥测数据，方便调试。

        还有很多实用函数这里没有列举出来，v5主控的功能很多，说它们不常用是因为整合成一个可用的系统很麻烦，
        但是不妨碍这些函数依然有探索价值，用它们做一些小功能还是很好玩的。
     */
    Brain.Screen.clearLine(1);
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(100,100,"abc");
}