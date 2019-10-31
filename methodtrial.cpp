#include "methodtrial.h"

MethodTrial::MethodTrial(double _h)
{
    h = _h;
}

double MethodTrial::calcInt(Func foo, double a, double b){
    double res = 0;
    for(double i = a; i < b; res += foo(1, i) + foo(1, i + h), i += h);
    res *= h / 2.0;
    return res;
}
