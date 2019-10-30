#include "methodtrial.h"

MethodTrial::MethodTrial(double _h)
{
    h = _h;
}

double MethodTrial::calcInt(double (*func)(double x), double a, double b){
    double res = 0;
    for(double i = a; i < b; res += func(i) + func(i + h), i += h);
    res *= h / 2.0;
    return res;
}
