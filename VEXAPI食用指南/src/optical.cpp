#include "vex.h"

//这里只会介绍常用的函数，其他的可以自己探索

void optical_API(){
    /* 
        hue()函数

        这个函数用于获取当前环境下的光线色调，
        如果你不理解这个函数，可以把光感连接到主控，
        在主控的设备界面点击你连接好的光感，上面会有详尽的参数显示，
        你可以通过改变环境光颜色，例如放一个有色物体在光感前，观察数值变化，理解函数的含义。
     */
    Optical.hue();

    /* 
        setLightPower()和setLight()函数

        这两个函数都是控制光感自带的led灯，
        setLightPower()控制发光强度，setLight()控制开闭，
        但是需要注意的是，setLight()里的参数不是bool类型，
        而是vex::ledState::on或vex::ledState::off （我也不知道为什么要这样搞，不懂）。
     */
    Optical.setLightPower(100);
    Optical.setLight(vex::ledState::on);
}