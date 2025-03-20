using namespace vex;

/* 
  !!!!!!!!!!!!!!!
  这是设备声明文件
*/

//这两句为固定语句
extern brain Brain;
extern controller Controller;

//执行器
extern motor Motor; //电机
extern digital_out Piston; //气缸

//传感器
extern inertial Inertial; //惯导
extern encoder Encoder; //旧版编码器
extern rotation Rotation; //新版编码器
extern vex::distance Distance; //距离传感器，类型名前面必须要加vex::限定作用域，不然会奇妙报错。
extern vex::optical Optical; //光感，类型名前面必须要加vex::限定作用域，不然会奇妙报错。