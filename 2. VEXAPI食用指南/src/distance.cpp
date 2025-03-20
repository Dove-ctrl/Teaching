#include "vex.h"

//这里只会介绍常用的函数，其他的可以自己探索

void distance_API(){
    /* 
        objectDistance()和objectVelocity()函数

        objectDistance()函数用于获取物体和传感器的距离，objectVelocity()用于获取物体移动速度。
     */
    Distance.objectDistance(distanceUnits::mm);
    Distance.objectVelocity();
}