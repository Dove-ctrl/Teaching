#include "chassis.h"

/* 
    这个函数用于设置左右电机电压
*/
void chassis::SetVoltage(double L , double R){
    left_voltage = L;
    right_voltage = R;
}

/* 
    这个函数用于制动底盘，可以选择制动类型
*/
void chassis::SetBrake(brakeType btype){
    left_voltage = right_voltage = 0;
    LF.stop(btype);
    LM.stop(btype);
    LB.stop(btype);
    RF.stop(btype);
    RM.stop(btype);
    RB.stop(btype);
}

/* 
    这个函数用于底盘前进，可以设置前进距离和速度，
    这里的距离是以地垫单位为准的，速度是百分比
    例如：Forward(1 , 50) 表示底盘前进1米，速度为50%
*/
void chassis::Forward(double distance , double velocity){

    /* 
        1281是一个测量值，用于将地垫单位转换为编码器旋转的度数，可以根据齿轮比，轮子直径计算
        经过这一步把地垫单位转换为编码器旋转的度数后，就可以用于控制电机的旋转了
    */
    distance = distance * 1281;
    velocity = (velocity >= 100 ? 100 : velocity) / 100;

    /* 
        设置pid的目标值，这里的目标值是当前位置加上需要前进的距离
    */
    liner_pid.set_target(GetMotorPosition() + distance);

    /* 
        持续更新pid的输出，然后计算需要的速度，最后控制电机旋转，直到达到指定位置
    */
    while(!liner_pid.is_arrived()){
        liner_pid.update(GetMotorPosition());
        liner_velocity = velocity * liner_pid.get_output();
        angular_velocity = 0;
        SetVoltage(liner_velocity , liner_velocity);
        wait(5,msec);
    }

    /* 
        到达指定位置后，制动底盘，然后重置pid
    */
    SetBrake(brake);
    liner_pid.reset();
}

/* 
    这个函数用于底盘后退，可以设置后退距离和速度，
    这里的距离是以地垫单位为准的，速度是百分比
    例如：Backward(1 , 50) 表示底盘后退1米，速度为50%
*/
void chassis::Backward(double distance , double velocity){

    distance = distance * 1281;
    velocity = (velocity >= 100 ? 100 : velocity) / 100;

    liner_pid.set_target(GetMotorPosition() - distance);

    while(!liner_pid.is_arrived()){
        liner_pid.update(GetMotorPosition());
        liner_velocity = velocity * liner_pid.get_output();
        angular_velocity = 0;
        SetVoltage(liner_velocity , liner_velocity);
        wait(5,msec);
    }

    SetBrake(brake);
    liner_pid.reset();
}

/* 
    这个函数用于底盘左转，可以设置左转到哪个角度和需要的速度，
    这里的角度是以度数为准的，速度是百分比
    例如：TurnLeftTo(90 , 50) 表示底盘左转到90度，速度为50%
    这里需要注意的是，转动的角度是相对于初始化时的偏航角的，也就是绝对角度，
    而不是相对于上一次偏航角的角度
*/
void chassis::TurnLeftTo(double angle , double velocity){

    /* 
        这里的angle是相对于初始化时的偏航角的，也就是绝对角度，
        而不是相对于上一次偏航角的角度，因此需要进行一些处理，把angle转换为imu_rotation
    */
    angle = imu_rotation + (angle - yaw > 0 ? angle - yaw : 360 + angle - yaw);
    velocity = (velocity >= 100 ? 100 : velocity) / 100;

    /* 
        设置pid的目标值，这里的目标值是angle
    */
    angular_pid.set_target(angle);

    /* 
        持续更新pid的输出，然后计算需要的速度，最后控制电机旋转，直到达到指定位置
    */
    while(!angular_pid.is_arrived()){
        angular_pid.update(GetRotation());
        angular_velocity = velocity * angular_pid.get_output();
        liner_velocity = 0;
        SetVoltage(angular_velocity , -angular_velocity);
        wait(5,msec);
    }

    /* 
        到达指定位置后，制动底盘，然后重置pid
    */
    SetBrake(brake);
    angular_pid.reset();
}

/* 
    这个函数用于底盘右转，可以设置右转到哪个角度和需要的速度，
    这里的角度是以度数为准的，速度是百分比
    例如：TurnRightTo(90 , 50) 表示底盘右转到90度，速度为50%
    这里需要注意的是，转动的角度是相对于初始化时的偏航角的，也就是绝对角度，
    而不是相对于上一次偏航角的角度
*/
void chassis::TurnRightTo(double angle , double velocity){

    angle = imu_rotation - (angle - yaw < 0 ? yaw - angle : yaw - angle + 360);
    velocity = (velocity >= 100 ? 100 : velocity) / 100;

    angular_pid.set_target(angle);

    while(!angular_pid.is_arrived()){
        angular_pid.update(GetRotation());
        angular_velocity = velocity * angular_pid.get_output();
        liner_velocity = 0;
        SetVoltage(angular_velocity , -angular_velocity);
        wait(5,msec);
    }

    SetBrake(brake);
    angular_pid.reset();
}