#define _CRT_SECURE_NO_WARNINGS  // 解决某些编译器可能报告的错误
#include <stdio.h>
#include "calculator.h" // 包含头文件

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