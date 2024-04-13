#include <stdio.h>
#include <math.h>
#include "factorial.h"
#define RANK 1000
#define PI 3.14159265358979323846
//ֱ��̩��չ�����ϴ���������sin/cos����ʵ��
/* ����tan(x)��̩��չ��
double cqu_tan(double x) 
{
    double result = 0.0;
    double term = x;

    for (int i = 1; i <= RANK; ++i) 
    {
        result += term;
        term = pow(x, 2 * i + 1) / (2 * i + 1);
    }

    return result;
}*/


// ����arctan�ĺ�����ʹ��̩��չ��
double cqu_arctan(double x) {
    // ��� x �ľ���ֵ���ڵ��� 1�������� arctan �ĶԳ����ʵ��� x ���Ϸ���Χ��
    if (fabs(x) >= 1) {
        x = 1 / x;
        double result = PI / 2 - cqu_arctan(x);
        return result;
    }

    double result = 0.0;
    for (int i = 0; i < RANK; i++) {
        int sign = (i % 2 == 0) ? 1 : -1;
        double term = sign * pow(x, 2 * i + 1) / (2 * i + 1);
        result += term;
    }
    return result;
}