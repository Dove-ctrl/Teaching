/* 
    代码行为规范

    随意性的代码会导致代码混乱，甚至导致隐藏bug，对学习或提升编程能力有极大阻碍

    这里主要是强调以下几点：代码缩进，空格空行，整体风格。
 */

//下面这个例子是不规范缩进

void function_a(){
    bool    condition;
            int 
    number;
while(true){
    if(condition)
            {
                number = 10;
}
            else{
        number = 5;  
break;      
                }
    }
            if(     number > 7
            )   {       number = 9;

        }   else
    {  
                    condition = 
        false   ;
    }

}

//下面这个例子是规范缩进

void function_b(){
    bool condition;
    int number;
    while(true){
        if(condition){
            number = 10;
        }else{
            number = 5;
            break;     
        }
    }
    if(number > 7){
        number = 9;
    }else{  
        condition = false;
    }
}

/* 
    从这两个例子能看出，缩进规范化对代码美观或者阅读流畅度有很大影响，
    假设没有颜色标注提示，你不可能很快地读懂function_a在干什么，
    甚至有颜色标注时，你也不可能保证5秒内你能看清这个函数的大致结构，
    而反观function_b，阅读难度大大降低，明眼人一看就能知道在做什么，
    因此，我建议每个新人，敲代码不要着急，一定先把缩进格式写清楚，
    优秀程序的缩进一定是控制得很规范的。
 */

//下面是空格空行不规范的

float function_c(){
    int number=1;int value=0;
    while((number>value?number:value)){number+=value;value+10/20*30-40;number=number+1/2-3*4;}return (number+value)/number+1;
}

//下面是空格空行规范的

float function_d(){
    //定义
    int number = 1;
    int value = 0;

    //循环计算
    while( number > value ? number : value ){
        number += value;
        value + 10 / 20 * 30 - 40;
        number = number + 1 / 2 - 3 * 4;
    }

    //返回
    number = value + number / 4;
    return ( number + value ) / number + 1;
}

/* 
    相信你也能看出差别了，不空格空行，会让代码缩成一坨很长的东西，非常难阅读，很容易看错，
    正确的使用空格空行，配合上注释，会使代码结构非常清晰，看起来有种微风拂面的感觉，
    做这一件事情的代码不空行，贴在一起，表示它们是一块代码，共同完成这件事的，
    做另一件事的代码用空行隔开，表示是另一块代码，共同完成另一件事情。
    而变量和运算符号，括号之间用空格隔开，方便阅读。
 */

//下面是关于整体风格的示例

void function_e(){
    //while风格1
    while (true)
    {
        
    }

    //while风格2
    while(true){

    }

    //if风格1
    if (1)
    {

    }
    else
    {

    }

    //if风格2
    if(1){

    }else{

    }

    int DriveVoltage = 0; //命名风格1
    int driveVoltage = 0; //命名风格2
    int drive_voltage = 0; //命名风格3

    //类风格1
    class point{
    private:
        int x = 0;
    };

    //类风格2
    class point{
        public:
        int x = 0;
    };
}

/* 
    不管你使用哪种风格,都没问题,你也可以打造一套你自己的风格,
    但是需要保证你这套程序里面风格统一,不能又是风格1又是风格2,
    这当然不影响阅读,但是写代码也要考虑美观性,这是属于你自己的代码风格。
 */