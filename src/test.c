#include "stdio.h"
#include "math.h"
#include "Tri_func.h"
#define M_PI 3.14159265358979323846
void testTrigFunctions() 
{
    double test_number = 0.8;
    //range（-1,1）
    double Radians = test_number * M_PI / 180.0;
    double sin_value = sin(Radians);
    double cos_value = cos(Radians);
    double tan_value = tan(Radians);
    double arcsin_value = asin(test_number);
    double arccos_value = acos(test_number);
    double arctan_value = atan(test_number);
    //Calculated values from standard math libraries
    double my_sin_value = cqu_sin(Radians);
    double my_cos_value = cqu_cos(Radians);
    double my_tan_value = cqu_tan(Radians);
    double my_arcsin_value = cqu_arcsin(test_number);
    double my_arccos_value = cqu_arccos(test_number);
    double my_arctan_value = cqu_arctan(test_number);
    //Test value


    if (fabs(sin_value - my_sin_value) < 0.0001&& fabs(cos_value - my_cos_value) < 0.0001&& fabs(tan_value - my_tan_value) < 0.0001 && fabs(arcsin_value - my_arcsin_value) < 0.0001
        && fabs(arccos_value - my_arccos_value) < 0.0001)
    {
        printf("和标准的数学库差值在0.0001内，测试通过！\n");
    }
    else 
    {
        printf("测试不通过！\n");
    }
}
