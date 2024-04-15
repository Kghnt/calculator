#define _CRT_SECURE_NO_WARNINGS  // 解决某些编译器可能报告的错误
#include <stdio.h>
#include "calculator.h" // 包含头文件
#include "Tri_func.h"
#include "test.h"
void instructions();
int global_flag;//用于判断error输入

int main() 
{
    char mode_choice;
    printf("请选择测试或计算\n");
    printf("A：测试，B：计算\n");
    scanf("%c", &mode_choice);
    getchar();
    if (mode_choice == 'A' || mode_choice == 'a') 
    {
        testTrigFunctions();
    }
    else if (mode_choice == 'B' || mode_choice == 'b') 
    {
        char choice = 'y';
        instructions();
        while (choice == 'y' || choice == 'Y')
        {
            global_flag = 0;
            printf("请输入表达式（支持四则运算，可包含括号）：\n");
            double result = expression();  //该函数为计算体函数，整个计算过程(包括数据流的读入)都在此函数以及其递归调用的函数中实现
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
        
    }
    else 
    {
        printf("错误：无效的输入\n");
        return 1; // 报错并退出主函数
    }

    return 0;

    
}

void instructions()
{
    printf("*********************************************************************************\n");
    printf("*                               三角函数计算器                                  *\n");
    printf("*********************************************************************************\n");
    printf("使用说明：\n");
    printf("\t本计算器支持基本的计算器功能，此外支持三角函数的使用\n");
    printf("\t支持三角函数类型：sin,cos,tan,arcsin,arccos,arctan\n");
    printf("\t如想使用三角函数，sin(xx), cos(xx), tan(xx), asin(xx), acos(xx), atan(xx)\n\n");
}