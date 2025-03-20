#include "vex.h"

/* 
    路线导演函数
*/
void chassis::ChassisRoute(){
    Forward(1 , 50);
    TurnLeftTo(90 , 50);
    Forward(1 , 50);
}