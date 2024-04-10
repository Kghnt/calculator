#define _CRT_SECURE_NO_WARNINGS  // 解决某些编译器可能报告的错误
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "calculator.h" // 包含头文件
#include "Tri_func.h"

#define PI 3.14159265358979323846
#define DEG_TO_RAD(x) ((x) * PI / 180.0) // 角度转换为弧度

double expression() {
    double value = term(); // 读取第一个项

    int c = getchar();
    while (1) {
        switch (c) {
        case '+':
            value += term(); // 加法
            c = getchar();
            break;
        case '-':
            value -= term(); // 减法
            c = getchar();
            break;
        default:
            ungetc(c, stdin); // 将读取的字符放回输入流
            return value;
        }
    }
}

// 解析项
double term() {
    double value = factor(); // 读取第一个因子

    int c = getchar();
    while (1) {
        switch (c) {
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
double factor() {
    int c = getchar();

    if (c == '(') {
        double value = expression(); // 递归处理括号内的表达式
        getchar(); // 读取右括号
        return value;
    }
    else if (isdigit(c) || c == '.') {
        ungetc(c, stdin); // 将数字放回输入流
        double value;
        scanf("%lf", &value);
        return value;
    }
    else if (c == '-') {
        return -factor(); // 处理负号
    }
    else if (c == 's' || c == 'c' || c == 't' || c == 'a') {
        char func[5];
        func[0] = c;
        func[1] = getchar();
        func[2] = getchar();
        func[3] = getchar();
        func[4] = '\0';
        double angle = DEG_TO_RAD(factor()); // 将角度转换为弧度
        if (func[0] == 's' && func[1] == 'i' && func[2] == 'n') {
            getchar();    //因为反三角函数判断四个字母所以得吸收一个字母，cos和tan同理
            return cqu_sin(angle);
        }
        else if (func[0] == 'c' && func[1] == 'o' && func[2] == 's') {
            getchar();
            return cqu_cos(angle);
        }
        else if (func[0] == 't' && func[1] == 'a' && func[2] == 'n') {
            getchar();
            return cqu_tan(angle);
        }
        else if (func[0] == 'a' && func[1] == 's' && func[2] == 'i' && func[3] == 'n') {
            return cqu_arcsin(angle) ;
        }
        else if (func[0] == 'a' && func[1] == 'c' && func[2] == 'o' && func[3] == 's') {
            return cqu_arccos(angle) ;
        }
        else if (func[0] == 'a' && func[1] == 't' && func[2] == 'a' && func[3] == 'n') {
            return cqu_arctan(angle);
            //return atan(factor());

        }
    }
    else {
        printf("错误：无效的输入\n");
        exit(EXIT_FAILURE);
    }
}