#include "chassis.h"

/* 
    这是陀螺仪驱动函数，用于获取陀螺仪的数据，
    包括偏航角和角速度
*/
void chassis::ImuDrive(){
    imu_rotation = Inertial.rotation();

    angular_velocity = Inertial.gyroRate(zaxis, rpm);

    if(imu_rotation > 0){
        yaw = fmod(imu_rotation, 360.0);
    }else if(imu_rotation < 0){
        yaw = 360 - fmod(fabs(imu_rotation), 360.0);
    }else{
        yaw = 0;
    }
}

/* 
    这是编码器驱动函数，用于获取编码器的数据，
    包括左右电机的速度和位置
*/
void chassis::EncoderDrive(){
    liner_velocity = (left_velocity + right_velocity) / 2.0;

    left_velocity = (
        LF.velocity(velocityUnits::rpm)+
        LM.velocity(velocityUnits::rpm) +
        LB.velocity(velocityUnits::rpm)
    ) / 3;
    right_velocity = (
        RF.velocity(velocityUnits::rpm)+
        RM.velocity(velocityUnits::rpm) +
        RB.velocity(velocityUnits::rpm)
    ) / 3;

    left_position = (
        LF.position(rotationUnits::deg)+
        LM.position(rotationUnits::deg) +
        LB.position(rotationUnits::deg)
    ) / 3;
    right_position = (
        RF.position(rotationUnits::deg)+
        RM.position(rotationUnits::deg) +
        RB.position(rotationUnits::deg)
    ) / 3;
}

/* 
    这是底盘运动驱动函数，用于控制底盘的运动
*/
void chassis::MovementDrive(){
    LF.spin(fwd , left_voltage , voltageUnits::mV);
    LM.spin(fwd , left_voltage , voltageUnits::mV);
    LB.spin(fwd , left_voltage , voltageUnits::mV);

    RF.spin(fwd , right_voltage , voltageUnits::mV);
    RF.spin(fwd , right_voltage , voltageUnits::mV);
    RB.spin(fwd , right_voltage , voltageUnits::mV);
}

/* 
    这是底盘总驱动函数，不断刷新所有驱动
*/
void ChassisDrive(void* _Chassis){
    chassis* Chassis = (chassis*)_Chassis;
    while (true)
    {
        Chassis->ImuDrive();
        Chassis->EncoderDrive();
        Chassis->MovementDrive();
        wait(5,msec);
    }
}