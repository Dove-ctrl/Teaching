#pragma once
using namespace vex;

extern brain Brain;
extern controller Controller;

/* 
    底盘是一个控制系统，包含了执行器，传感器以及控制器
    其中，执行器为电机（Motor），传感器为陀螺仪（Inertial）。控制器为控制算法
    当然，传感器还有很多，比如编码器组成的里程计，激光测距仪等，这里只是简单的示例
*/

extern inertial Inertial;

extern motor LF;
extern motor LM;
extern motor LB;
extern motor RF;
extern motor RM;
extern motor RB;