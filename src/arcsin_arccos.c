#include <stdio.h>
#include <math.h>

#define RANK 1000
#define PI 3.14159265358979323846
#define EPSILON 1e-6 // �����������
// ����׳�
/*double factorial(int n) 
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}*/


// ����arcsin(x)��̩��չ��
/*double cqu_arcsin(double x) 
{
    double result = 0;
    int i;
    for (i = 0; i < RANK; i++) {
        result += (factorial(2 * i) / (pow(4, i) * pow(factorial(i), 2) * (2 * i + 1))) * pow(x, 2 * i + 1);
    }
    return result;
}*/



double cqu_arcsin(double x) 
{
    double guess = x; // ��ʼ�²�ֵ
    double delta; // ��������

    // ʹ��ţ�ٵ��������
    do 
    {
        double sine = sin(guess);
        delta = (sine - x) / cos(guess); 
        guess -= delta;
    } while (fabs(delta) > EPSILON);

    return guess;
}

// ����arccos(x)��̩��չ��
double cqu_arccos(double x) 
{
    return PI / 2 - cqu_arcsin(x);
}

