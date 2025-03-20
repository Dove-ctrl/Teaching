#include "chassis.h"

const double LINER_KP = 10;
const double LINER_KI = 0;
const double LINER_KD = 10;
const double LINER_ERROR_TOL = 60;
const double LINER_D_TOL = 1;
const double LINER_I_MAX = 2000;
const double LINER_ARRIVED_TIMES = 3;

const double ANGULAR_KP = 200;
const double ANGULAR_KI = 0;
const double ANGULAR_KD = 1750;
const double ANGULAR_ERROR_TOL = 1;
const double ANGULAR_D_TOL = 0.5;
const double ANGULAR_I_MAX = 2000;
const double ANGULAR_ARRIVED_TIMES = 10;

/* 
    构造函数，初始化PID算法
*/
chassis::chassis(){
    liner_pid.set_coefficient(LINER_KP , LINER_KI , LINER_KD);
    liner_pid.set_error_tol(LINER_ERROR_TOL);
    liner_pid.set_arrived_times(LINER_ARRIVED_TIMES);
    liner_pid.set_D_Tol(LINER_D_TOL);
    liner_pid.set_I_Max(LINER_I_MAX);

    angular_pid.set_coefficient(ANGULAR_KP , ANGULAR_KI , ANGULAR_KD);
    angular_pid.set_error_tol(ANGULAR_ERROR_TOL);
    angular_pid.set_arrived_times(ANGULAR_ARRIVED_TIMES);
    angular_pid.set_D_Tol(ANGULAR_D_TOL);
    angular_pid.set_I_Max(ANGULAR_I_MAX);

    liner_pid.set_feed_forward_gain_activate(false);
    angular_pid.set_feed_forward_gain_activate(false);
}

double chassis::GetYaw(){
    return yaw;
}

double chassis::GetLinerVelocity(){
    return liner_velocity;
}

double chassis::GetAngularVelocity(){
    return angular_velocity;
}

double chassis::GetMotorPosition(){
    return (left_position + right_position) / 2;
}

double chassis::GetRotation(){
    return imu_rotation;
}