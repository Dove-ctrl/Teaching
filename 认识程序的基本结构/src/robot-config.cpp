/* 
  4.  认识文件"robot-config.cpp" 

  这是机器人的配置定义文件，所有电气设备都在这里定义。
  这个文件相当于告诉控制器，我今天有这些设备要运行，至于设备配置细节在这里写清楚了。

  如果你看明白了robot-config.h的声明和定义的解释，那么这里你应该很容易理解。

  具体的定义方式，在API食用教程里，这里不多讲。

  唯一还要强调的点，这也是新人最容易出现的问题：.h文件里面声明了，那么.cpp文件里面也要有相应的定义，
  两个文件里面的电气设备是一一对应的，不能一个多一个少，
  如果你的程序怎么下载都有报错，那建议你检查检查这两个文件。
 */

#include "vex.h"

using namespace vex;

//这两行代码是固定的，每套程序都要有这两行。
brain Brain;
controller Controller;