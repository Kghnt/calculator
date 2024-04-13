#define _CRT_SECURE_NO_WARNINGS  // ���ĳЩ���������ܱ���Ĵ���
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "calculator.h" // ����ͷ�ļ�
#include "Tri_func.h"

#define PI 3.14159265358979323846
#define DEG_TO_RAD(x) ((x) * PI / 180.0) // �Ƕ�ת��Ϊ����

double expression() 
{
    double value = add_sub(); // ��ȡ��һ����

    int c = getchar();
    while (1) 
    {
        switch (c) 
        {
        case '+':
            value += add_sub(); // �ӷ�
            c = getchar();
            break;
        case '-':
            value -= add_sub(); // ����
            c = getchar();
            break;
        default:
            ungetc(c, stdin); // ����ȡ���ַ��Ż�������
            return value;
        }
    }
}

// ������
double add_sub()
{
    double value = factor(); // ��ȡ��һ������

    int c = getchar();
    while (1) 
    {
        switch (c) 
        {
        case '*':
            value *= factor(); // �˷�
            c = getchar();
            break;
        case '/':
            value /= factor(); // ����
            c = getchar();
            break;
        default:
            ungetc(c, stdin); // ����ȡ���ַ��Ż�������
            return value;
        }
    }
}

// ��������
double factor() 
{
    int c = getchar();

    if (c == '(') 
    {
        double value = expression(); // �ݹ鴦�������ڵı��ʽ
        getchar(); // ��ȡ������
        return value;
    }
    else if (isdigit(c) || c == '.') 
    {
        ungetc(c, stdin); // �����ַŻ�������
        double value;
        scanf("%lf", &value);
        return value;
    }
    else if (c == '-') 
    {
        return -factor(); // ������
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
       // double radian = DEG_TO_RAD(angle); // ���Ƕ�ת��Ϊ���ȣ�����̩��չ��
        if (func[0] == 's' && func[1] == 'i' && func[2] == 'n') 
        {
            getchar();    //��Ϊ�����Ǻ����ж��ĸ���ĸ���Ե�����һ����ĸ��cos��tanͬ��
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
        return 0; // ���� 0���Ա�����Ч����Ӱ�������
    }
}
