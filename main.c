#define _CRT_SECURE_NO_WARNINGS  // ���ĳЩ���������ܱ���Ĵ���
#include <stdio.h>
#include "calculator.h" // ����ͷ�ļ�

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