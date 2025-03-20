#pragma once
#include "vex.h"

/* 
    下面是底盘类的具体结构
*/

class chassis{
private:

    //基础参数
    /* 
        这些是底盘的基础属性，包括控制量和被控制量
        控制量是线速度，角速度以及偏航角，被控制量是电压
    */
    double left_voltage , right_voltage; //左右电机电压
    double liner_velocity , angular_velocity; //线速度，角速度
    double yaw; //偏航角

    //传感器数据
    /* 
        这些是传感器数据，用于闭环控制
    */
    double imu_rotation; //陀螺仪角度
    double left_velocity , right_velocity; //左右电机速度
    double left_position , right_position; //左右电机位置

    //控制器
    /* 
        这些是控制器，用于控制底盘的运动
    */
    PID liner_pid;
    PID angular_pid;
public:

    //构造函数
    /* 
        控制器算法（例如pid）初始化在这里面执行
    */
    chassis();

    //路线导演函数
    /* 
        这个函数是用来导演自动路线的，
        所有自动阶段的动作都写在这个函数里面，
        因此这个函数就像一个导演一样，负责自动阶段的动作
    */
    void ChassisRoute();

    //驱动
    /* 
        下面这些函数是传感器和执行器的驱动，
        驱动是负责连接硬件和软件的桥梁，
        通过驱动，硬件可以递交正确的数据给软件，软件也可以控制硬件
    */
    void ImuDrive();
    void EncoderDrive();
    void MovementDrive();

    //控制
    /* 
        下面这些函数是用于控制底盘运动的函数
    */
    void SetVoltage(double L , double R);
    void SetBrake(brakeType btype);
    void Forward(double distance , double velocity);
    void Backward(double distance , double velocity);
    void TurnLeftTo(double angle , double velocity);
    void TurnRightTo(double angle , double velocity);

    //输出
    /* 
        下面这些是输出函数，
        用于获取底盘的数据，主要用于调试阶段的遥测数据，
        虽然有些函数没有实际的控制作用，但是可以帮助我们了解底盘的状态，
        因此这一部分是必要的
    */
    double GetYaw();
    double GetRotation();
    double GetLinerVelocity();
    double GetAngularVelocity();
    double GetMotorPosition();
};

/* 
    下面是底盘总驱动函数
*/
void ChassisDrive(void* Chassis);