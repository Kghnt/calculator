#define _CRT_SECURE_NO_WARNINGS  // ���ĳЩ���������ܱ���Ĵ���
#include <stdio.h>
#include "calculator.h" // ����ͷ�ļ�
#include "Tri_func.h"

void Instructions();
int global_flag;//�����ж�error����

int main() 
{
    char choice = 'y';
    Instructions();
    while (choice == 'y' || choice == 'Y') 
    { 
        global_flag = 0;
        printf("��������ʽ��֧���������㣬�ɰ������ţ���\n");
        double result = expression();
        if (global_flag == 0) 
        {
            printf("���Ϊ�� %.8g\n\n", result);//���8λ��Ч����
        }
        else if (global_flag == 1)
        {
            printf("������Ч������\n\n");
            while (getchar() != '\n');
        }
        printf("�Ƿ�������㣿������������y������������˳�: ");
        //getchar();//
        scanf(" %c", &choice);  //�ո�������һ������Ļ��з�
        while (getchar() != '\n'); // ������뻺����
    }
    printf("ллʹ�ã�\n");
    return 0;
}

void Instructions()
{
    printf("*********************************************************************************\n");
    printf("*                               ���Ǻ���������                                  *\n");
    printf("*********************************************************************************\n");
    printf("ʹ��˵����\n");
    printf("\t��������֧�ֻ����ļ��������ܣ�����֧�����Ǻ�����ʹ��\n");
    printf("\t֧�����Ǻ������ͣ�sin,cos,tan,arcsin,arccos,arctan\n");
    printf("\t����ʹ�����Ǻ�����sin(xx), cos(xx), tan(xx), asin(xx), acos(xx), atan(xx)\n\n");
}