#include "vex.h"

//这里只会介绍常用的函数，其他的可以自己探索

void encoder_API(){
    /* 
        rotation()和resetRotation()函数

        rotation()用于获取编码器转动数值，单位可以指定为角度或圈数，
        resetRotation()用于重置编码器的值。
     */
    Encoder.rotation(rotationUnits::deg);
    Encoder.resetRotation();

    /* 
        angle()函数

        这个函数用于获取编码器的绝对角度，范围为0-360°。
     */
    Rotation.angle();

    /* 
        position()和resetPosition()函数

        position()用于获取编码器转动数值，单位可以指定为角度或圈数，
        resetPosition()用于重置编码器的值。
     */
    Rotation.position(rotationUnits::deg);
    Rotation.resetPosition();

    /* 
        velocity()函数

        这个函数用于获取编码器的转动速度，单位可以指定为rpm，dps或pct。
     */
    Encoder.velocity(velocityUnits::rpm);
    Rotation.velocity(velocityUnits::dps);
}