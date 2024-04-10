#define _CRT_SECURE_NO_WARNINGS  // ���ĳЩ���������ܱ���Ĵ���
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "calculator.h" // ����ͷ�ļ�
#include "Tri_func.h"

#define PI 3.14159265358979323846
#define DEG_TO_RAD(x) ((x) * PI / 180.0) // �Ƕ�ת��Ϊ����

double expression() {
    double value = term(); // ��ȡ��һ����

    int c = getchar();
    while (1) {
        switch (c) {
        case '+':
            value += term(); // �ӷ�
            c = getchar();
            break;
        case '-':
            value -= term(); // ����
            c = getchar();
            break;
        default:
            ungetc(c, stdin); // ����ȡ���ַ��Ż�������
            return value;
        }
    }
}

// ������
double term() {
    double value = factor(); // ��ȡ��һ������

    int c = getchar();
    while (1) {
        switch (c) {
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
double factor() {
    int c = getchar();

    if (c == '(') {
        double value = expression(); // �ݹ鴦�������ڵı��ʽ
        getchar(); // ��ȡ������
        return value;
    }
    else if (isdigit(c) || c == '.') {
        ungetc(c, stdin); // �����ַŻ�������
        double value;
        scanf("%lf", &value);
        return value;
    }
    else if (c == '-') {
        return -factor(); // ������
    }
    else if (c == 's' || c == 'c' || c == 't' || c == 'a') {
        char func[5];
        func[0] = c;
        func[1] = getchar();
        func[2] = getchar();
        func[3] = getchar();
        func[4] = '\0';
        double angle = DEG_TO_RAD(factor()); // ���Ƕ�ת��Ϊ����
        if (func[0] == 's' && func[1] == 'i' && func[2] == 'n') {
            getchar();    //��Ϊ�����Ǻ����ж��ĸ���ĸ���Ե�����һ����ĸ��cos��tanͬ��
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
        printf("������Ч������\n");
        exit(EXIT_FAILURE);
    }
}