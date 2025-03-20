#include "vex.h"

using namespace vex;

/* 
  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  这是设备定义文件，这里的设备名称需要和声明文件里面的名称保持一致!
*/

//这两句为固定语句
brain Brain;
controller Controller = controller(primary);

/* 
  电机定义语句如下，参数从左往右代表：端口 ， 齿比 ， 默认转向。
  端口：电机与主控连接的端口。
  齿比：电机内部齿轮箱的齿比，此参数设置不影响电机功率输出，但影响电机内置编码器读数。
  默认转向：false代表电机默认转向与机盖上标注方向相同，true代表与标注方向相反。

  齿比设置虽然不影响功率输出，但是有时电机内置编码器会参与控制算法，因此为了方便调试，齿比一定要设置正确。
  默认转向需要分析电机实际运动情况，例如底盘电机会使用齿轮串联在一起，那么不同位置的电机默认转向可能不同。
 */
motor Motor = motor( PORT1 , ratio6_1 , false );

/* 
  气缸定义语句如下，参数代表：端口。
  端口：气缸与主控连接的端口。

  这里的端口是三线接口，不同于连接电机的四线接口，三线接口的序号由英文字母A-H表示，
  且需要调用主控对象里的ThreeWirePort，例如这里的三线端口是"Brain.ThreeWirePort.A"。
 */
digital_out Piston = digital_out(Brain.ThreeWirePort.A);

/* 
  惯导，距离传感器，光感，旧版编码器定义语句如下，参数代表：端口。
  端口：以上设备与主控连接的端口。
 */
inertial Inertial = inertial(PORT2);
vex::distance Distance = vex::distance(PORT3);
vex::optical Optical = vex::optical(PORT4);
encoder Encoder = encoder(Brain.ThreeWirePort.B);

/* 
  新版编码器定义语句如下，参数代表：端口 ， 默认转向。
  端口：新版编码器与主控连接的端口。
  默认转向：false代表编码器正方向与机盖上标注方向相同，true代表与标注方向相反。

  这里的默认转向与电机的类似，默认转向的设置会影响最终编码器的读数。
 */
rotation Rotation = rotation(PORT5 , false);