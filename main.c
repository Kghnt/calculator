#define _CRT_SECURE_NO_WARNINGS  // 解决某些编译器可能报告的错误
#include <stdio.h>
#include "calculator.h" // 包含头文件
#include "Tri_func.h"

void Instructions();
int global_flag;//用于判断error输入

int main() 
{
    char choice = 'y';
    Instructions();
    while (choice == 'y' || choice == 'Y') 
    { 
        global_flag = 0;
        printf("请输入表达式（支持四则运算，可包含括号）：\n");
        double result = expression();
        if (global_flag == 0) 
        {
            printf("结果为： %.8g\n\n", result);//输出8位有效数字
        }
        else if (global_flag == 1)
        {
            printf("错误：无效的输入\n\n");
            while (getchar() != '\n');
        }
        printf("是否继续计算？若继续请输入y，输入其余键退出: ");
        //getchar();//
        scanf(" %c", &choice);  //空格吸收上一次输入的换行符
        while (getchar() != '\n'); // 清空输入缓冲区
    }
    printf("谢谢使用！\n");
    return 0;
}

void Instructions()
{
    printf("*********************************************************************************\n");
    printf("*                               三角函数计算器                                  *\n");
    printf("*********************************************************************************\n");
    printf("使用说明：\n");
    printf("\t本计算器支持基本的计算器功能，此外支持三角函数的使用\n");
    printf("\t支持三角函数类型：sin,cos,tan,arcsin,arccos,arctan\n");
    printf("\t如想使用三角函数，sin(xx), cos(xx), tan(xx), asin(xx), acos(xx), atan(xx)\n\n");
}