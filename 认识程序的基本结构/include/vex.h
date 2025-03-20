#pragma once //建议加上这一行

/*
  2.  认识文件"vex.h"

  这是官方API的头文件，一般情况下不建议修改这里的代码，
  当然，如果你需要其他c++标准头文件，可以加在这里，但是绝对不要删除任何一行代码。
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//这两行代码建议加上，方便查看遥测数据
#include <iostream>
using namespace std;

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)