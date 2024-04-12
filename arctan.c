#include <stdio.h>
#include <math.h>
#include "factorial.h"
#define RANK 1000

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

// 计算arctan(x)的泰勒展开
double cqu_arctan(double x) 
{
    double result = 0;
    int i;
    for (i = 0; i < RANK; i++) 
    {
        double term = pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
        result += term;
    }
    return result;
}