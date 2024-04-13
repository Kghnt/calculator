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
                extern int global_flag;
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
