#include <stdio.h>
#include <math.h>
#include "factorial.h"
#define RANK 1000
#define PI 3.14159265358979323846
//直接泰勒展开误差较大，舍弃采用sin/cos方法实现
/* 计算tan(x)的泰勒展开
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


// 计算arctan的函数，使用泰勒展开
double cqu_arctan(double x) {
    // 如果 x 的绝对值大于等于 1，则利用 arctan 的对称性质调整 x 到合法范围内
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