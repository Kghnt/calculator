#include <stdio.h>
#include <math.h>
#include "factorial.h"
#define RANK 1000
//接收弧度


// 计算sin(x)的泰勒展开
double cqu_sin(double x) {
    double result = 0;
    int i;
    for (i = 0; i < RANK; i++) {
        result += (pow(-1, i) / factorial(2 * i + 1)) * pow(x, 2 * i + 1);
    }
    return result;
}

// 计算cos(x)的泰勒展开
double cqu_cos(double x) {
    double result = 0;
    int i;
    for (i = 0; i < RANK; i++) {
        result += (pow(-1, i) / factorial(2 * i)) * pow(x, 2 * i);
    }
    return result;
}

double cqu_tan(double x)
{
    return cqu_sin(x) / cqu_cos(x);
}