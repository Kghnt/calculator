/*这段C代码实现了一个简单的数学表达式计算器，具备以下功能：
支持基本的加减乘除运算。
支持使用括号改变运算优先级。
提供了expression()函数作为计算入口，递归调用add_sub()和factor()函数来逐步解析和计算整个表达式。

计算项（add_sub）：
在add_sub()函数中，先调用factor()获取一个因子的值。
接着，循环读取下一个字符，若为乘号（'*'）或除号（'/'），则继续调用factor()计算下一个因子，并根据当前字符执行乘法或除法操作。
循环持续到遇到非乘除符号时结束，将结果返回给上层调用。

计算因子（factor）：
在factor()函数中，首先读取一个字符以确定因子类型。
若为左括号，递归调用expression()计算括号内表达式，并在读取右括号后返回结果。
若为数字（包括整数和小数），通过scanf()读取一个浮点数作为因子值。
若为负号，则计算下一个因子的相反数。
若为特定的三角函数名，读取相应的函数名和参数，将角度转换为弧度后调用对应的三角函数计算结果。
若遇到非法输入，输出错误信息并退出程序。*/

#define _CRT_SECURE_NO_WARNINGS  // 解决某些编译器可能报告的错误
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "calculator.h" // 包含头文件
#include "Tri_func.h"

#define PI 3.14159265358979323846
#define DEG_TO_RAD(x) ((x) * PI / 180.0) // 角度转换为弧度

double expression() 
{
    double value = add_sub(); // 读取第一个项

    int c = getchar();
    while (1) 
    {
        switch (c) 
        {
        case '+':
            value += add_sub(); // 加法
            c = getchar();
            break;
        case '-':
            value -= add_sub(); // 减法
            c = getchar();
            break;
        default:
            ungetc(c, stdin); // 将读取的字符放回输入流
            return value;
        }
    }
}

// 解析项
double add_sub()
{
    double value = factor(); // 读取第一个因子

    int c = getchar();
    while (1) 
    {
        switch (c) 
        {
        case '*':
            value *= factor(); // 乘法
            c = getchar();
            break;
        case '/':
            value /= factor(); // 除法
            c = getchar();
            break;
        default:
            ungetc(c, stdin); // 将读取的字符放回输入流
            return value;
        }
    }
}

// 解析因子
double factor() 
{
    int c = getchar();

    if (c == '(') 
    {
        double value = expression(); // 递归处理括号内的表达式
        getchar(); // 读取右括号
        return value;
    }
    else if (isdigit(c) || c == '.') 
    {
        ungetc(c, stdin); // 将数字放回输入流
        double value;
        scanf("%lf", &value);
        return value;
    }
    else if (c == '-') 
    {
        return -factor(); // 处理负号
    }
    else if (c == 's' || c == 'c' || c == 't' || c == 'a') 
    {
        char func[5];
        func[0] = c;
        func[1] = getchar();
        func[2] = getchar();
        func[3] = getchar();
        func[4] = '\0';
        double angle=0;
        double radian=0;
        double number = factor();
       // double angle = factor();
       // double radian = DEG_TO_RAD(angle); // 将角度转换为弧度，用于泰勒展开
        if (func[0] == 's' && func[1] == 'i' && func[2] == 'n') 
        {
            getchar();    //因为反三角函数判断四个字母所以得吸收一个字母，cos和tan同理
            radian = DEG_TO_RAD(number);
            return cqu_sin(radian);
          //  return sin(radian);
        }
        else if (func[0] == 'c' && func[1] == 'o' && func[2] == 's') 
        {
            getchar();
            radian = DEG_TO_RAD(number);
            return cqu_cos(radian);
            // return cos(radian);
        }
        else if (func[0] == 't' && func[1] == 'a' && func[2] == 'n') 
        {
            getchar();
            angle = number;
            if (angle == 90)
            {
                extern int global_flag;  //非法输入,跳转，下同
                global_flag = 1;
                return 0;
            }
            radian = DEG_TO_RAD(number);
            return cqu_tan(radian);
           // return tan(radian);
        }
        else if (func[0] == 'a' && func[1] == 's' && func[2] == 'i' && func[3] == 'n') {
            if (number >= -1 && number <= 1)
            {
                angle = number;
                return cqu_arcsin(angle) ;
            }
            else 
            {
                extern int global_flag;
                global_flag = 1;
                return 0;
            }
            //return asin(angle);
        }
        else if (func[0] == 'a' && func[1] == 'c' && func[2] == 'o' && func[3] == 's') 
        {
            if (number >= -1 && number <= 1) 
            {
                angle = number;
                return cqu_arccos(angle) ;
                // return acos(angle);
            }
            else 
            {
            extern int global_flag;
                global_flag = 1;
                return 0;
            }
        }
        else if (func[0] == 'a' && func[1] == 't' && func[2] == 'a' && func[3] == 'n') 
        {
            angle = number;
            return cqu_arctan(angle);
            //return atan(angle);

        }
    }

    else 
    {
        extern int global_flag;
        global_flag = 1;
        //int d;
        //while ((d = getchar()) != '\n' && d != EOF);
        return 0; // 返回 0，以避免无效输入影响计算结果
    }
}
