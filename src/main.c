#define _CRT_SECURE_NO_WARNINGS  // ���ĳЩ���������ܱ���Ĵ���
#include <stdio.h>
#include "calculator.h" // ����ͷ�ļ�
#include "Tri_func.h"
#include "test.h"
void instructions();
int global_flag;//�����ж�error����

int main() 
{
    char mode_choice;
    printf("��ѡ����Ի����\n");
    printf("A�����ԣ�B������\n");
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
            printf("��������ʽ��֧���������㣬�ɰ������ţ���\n");
            double result = expression();  //�ú���Ϊ�����庯���������������(�����������Ķ���)���ڴ˺����Լ���ݹ���õĺ�����ʵ��
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
        
    }
    else 
    {
        printf("������Ч������\n");
        return 1; // �����˳�������
    }

    return 0;

    
}

void instructions()
{
    printf("*********************************************************************************\n");
    printf("*                               ���Ǻ���������                                  *\n");
    printf("*********************************************************************************\n");
    printf("ʹ��˵����\n");
    printf("\t��������֧�ֻ����ļ��������ܣ�����֧�����Ǻ�����ʹ��\n");
    printf("\t֧�����Ǻ������ͣ�sin,cos,tan,arcsin,arccos,arctan\n");
    printf("\t����ʹ�����Ǻ�����sin(xx), cos(xx), tan(xx), asin(xx), acos(xx), atan(xx)\n\n");
}