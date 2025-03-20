/* 
    命名规范

    这是尤为重要的地方，命名规范与影响代码的上限，
    命名不规范，你有再逆天的逻辑和算法也没用，因为你一定看不懂你自己的代码，跟没有写是没区别的。

    我们会给：类（结构体）、函数、常量、全局变量、静态变量、成员变量、临时变量（参数）等进行命名，
    有两个基本原则：
    1.  含义清晰，不易混淆。
    2.  不和其它模块、系统API的命名空间相冲突。

    下面看示例。
 */

//下面三个是典型的错误命名，你的程序最不应该出现这种典型错误。

    //含义完全不清楚
    int a = 1; 
    int abc = 2;
    int aabbcc = 3;

    //拼音缩写，最可恶的一种，还要认认真真读一遍才知道写的啥。
    int woshinidie = 2; 

    //拼音首字母缩写，这个是最最最可恶的。
    //只要我不说，没人能知道下面的命名是什么意思。
    float wjsynkbd(int nybsldw); 

//下面这是另一类错误命名，一是名字太短，导致含义不明，二是名字太长，代码显得冗长，不方便快速浏览。

    //第三个是较为合适的写法，一般控制在2-3个英文单词即可。
    double vX = 0.123;
    double this_is_encoderX_value = 0.135;
    double X_value = 0.246;

//下面这也是另一类错误命名，使用非公认的缩写，导致含义不明。

    int MV = 12000; //本意是Motor Voltage，但是没有人用这个缩写，这是非公认的。
    int adj_value = 12345; //adj是adjust的简写，这是编程里常出现的一种写法。

//下面是属于和其他API冲突的错误。

    float forward();//forward是vexAPI里的东西，虽然编译可能不会报错，但是最好不要这样写。

//下面是正确的命名方式，常用的有下划线命名，驼峰式命名，帕斯卡命名（自己上网查）

    int object_num = 0; //代表物体的数目，使用单词object和常用缩写num（number）
    float driveVoltage = 1000; //代表驱动电压，使用单词drive和voltage
    void ControllerBtnCheck(); //代表遥控器按钮状态检查，使用单词controller，check和常用缩写btn（button）
    const int MAX_VELOCITY = 200; //代表最大速度，全部大写表示这是常量

//正确的命名习惯

    int right_motor_velocity = 100; //右电机速度
    int left_motor_velocity = 100; //左电机速度

    void MotorVelocitySet(int right, int left); //设置电机速度
    void MotorVelocityGet(int &right, int &left); //获取电机速度

    class chassis{ //底盘类
    public:
        chassis();
    };
    class odometry{ //里程计类
    public:
        odometry();
    };

    const int MAX_VELOCITY = 200; //最大速度
    const int MIN_VELOCITY = 0; //最小速度

    //从上面的命名你应该能看出，不同的变量、函数、类、常量都有不同的命名方式。
    //我的习惯是变量用下划线命名，函数用驼峰式命名，类用下划线命名，常量下划线加全大写。
    //这样可以通过不同的命名方式快速区分出变量、函数、类、常量。