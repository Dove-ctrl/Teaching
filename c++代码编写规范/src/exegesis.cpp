/* 
    注释的规范

    为什么要写注释？

    对于刚开始接触编程的人来说，勤写注释能帮助他更好的理解自己在做什么，
    不明白自己写出来代码的含义，是学习或提升编程能力的大忌。
    对于有一定编程基础的人来讲，注释就像火锅的九宫格，
    能更清晰地展现代码的结构，方便后续的维护和修改。

    因此，养成写注释的习惯一定不是坏事，
    同时，注释也需要有一定规范。
 */

void exegesis(){
    /* 
        对变量，函数或对象的注释

        一般两种方式：要么写在上面一行，要么写在这行的结尾

        需要注意的是，写在上面一行时需要和其他代码分开来，空一行才是规范的写法，
        同理，写在结尾需要打上空格再写注释。

        还有，注释需要已尽量简洁的话语表达含义，不可太长。
     */

    int number = 1; //变量

    //函数
    exegesis();
}

/* 
    对某个定义的注释

    这里建议用Doxygen注释，右键变量或函数名可以看到”生成Doxygen注释“的选项，
    我尤其建议新人每个变量或函数都这样写注释，会很直观明了，你也不会忘记它是干什么的,
    当你鼠标光标移到这个有Doxygen注释的函数上时，会显示这个函数的详细注释，非常方便。
 */

/// @brief 这是一个
float value = 1.234;

/// @brief 这是一个示例函数
/// @param i 形参i
void example(int i);