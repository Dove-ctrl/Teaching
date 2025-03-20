#include "vex.h"
#include "PID.h"

using namespace vex;

competition Competition;

void pre_auton(void) {
  
}

void autonomous(void) {
  
}

/* 
  此程序为PID示例程序，旨在帮助你更好了解怎么在机器人中使用PID控制

  下面是一次完整的PID控制过程展示，在此之前，你需要明白为什么要用PID以及PID的基本原理，
  如果不清楚，请转至PID.h/.cpp和PID文件夹里的pdf文件
 */

void usercontrol(void) {
  /* 在开始控制前，你需要准备以下变量和对象 */

  PID pid; /* PID控制器 */
  timer T; /* 计时器，这是为了防止无法跳出循环 */
  float target_angle = 270; /* 目标值 */
  int timeout = 2000; /* 跳出时间 */

  /* 接下来需要对PID控制器初始化 */

  pid.set_coefficient(10 , 0 , 0.01); /* 设置PID的三个参数 */
  pid.set_error_tol(2); /* 设置误差容忍值 */

  /* 下面控制过程开始 */

  pid.set_target(target_angle); /* 指定本次控制的目标值 */
  pid.set_error_range(10 , target_angle); /* 指定本次控制的误差值范围 */

  T.clear(); /* 计时器置零 */

  while( !pid.target_arrived() || T.time(msec) <= timeout ){ /* 循环条件为：PID未达到目标值 或 计时器超时 */

    pid.update( Motor.position( rotationUnits::deg ) ); /* 获取传感器的值，计算新的输出 */
    Motor.spin(fwd , pid.get_output() , voltageUnits::mV); /* 输出交给电机执行 */
    wait(10,msec);

    /* 在这个循环里，电机的电压值被不断更新，从而达到期望的控制效果 */

  }

  /* 控制结束前需要更新一次电机的电压，防止一直空转，以及重置PID控制器 */
  Motor.stop();
  pid.reset(pid._all);

  /* 到此为止控制结束 */
}

/* 
  注意事项：
  1.  kp，ki，kd的调整是有说法的，不是任意给定一个值就可以，先调kp，这取决于你的控制量和误差究竟是何关系，
  误差量小而控制量需要大，kp应该是很大的值，而且kp决定了你这个控制过程的快慢，这也取决实际的需求，接着再调kd，
  kd是为了防止超调的，因为电机加减速过程并不是线性的，而kp这个线性的控制大概率没法准确控制，极有可能会超调，
  因此kd就是为了解决这个问题的，kd越大，曲线越平滑，kd越小，曲线越陡峭，最后调ki，如果你通过调整kp，kd就满足了实际需求，ki可以不调，设为0就行，但是大多数情况下，系统因为有负载，会出现稳态误差，需要调大ki消除稳态误差。

  2. 误差容忍值的设置是为了解决ki无论怎么调都无法达到目标值的问题，这个值不应该设置太大，否则系统不会达到需要的准确度

  3. 别忘了去重置电压和PID控制器，下次使用才不会出错
 */

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
