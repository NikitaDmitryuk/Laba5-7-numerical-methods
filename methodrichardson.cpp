#include "methodrichardson.h"

MethodRichardson::MethodRichardson(double _h)
{
    h = _h;
}

double MethodRichardson::calcInt(double (*func)(double x), double a, double b){

    CalcIntegral integral = CalcIntegral();
    integral.setFunc(func);
    integral.setMethod(new MethodSimps(h));
    double r1 = integral.calc(a, b); //Simpson(5);
    integral.setMethod(new MethodSimps(h / 2.0));
    double r2 = integral.calc(a, b);
    integral.setMethod(new MethodSimps(h / 4.0));
    double r3 = integral.calc(a, b);
    int p = int(log2((r3 - r2) / (r2 - r1)) + 0.5);
    double I = ((2 ^ p)*r1 - r2) / ((2 ^ p) - 1);
    return I;
}
