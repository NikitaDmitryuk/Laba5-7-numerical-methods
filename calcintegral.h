#ifndef CALCINTEGRAL_H
#define CALCINTEGRAL_H
#include <memory>
#include "methodintegral.h"
#include <iostream>

using namespace std;

class CalcIntegral
{
public:
    CalcIntegral();
    ~CalcIntegral();
    CalcIntegral(double (*_func)(double x), MethodIntegral *_method);
    CalcIntegral(double (*_func)(double x, double y), MethodIntegral *_method);
    void setMethod(MethodIntegral* _method);
    void setFunc(double (*_func)(double x));
    void setFunc(double (*func)(double x1, double y1, double z1, double x2, double y2, double z2));
    void setFunc(double (*_func)(double x, double y));
    double calc(double _a, double _b);
    double calc(double r);
    double calc(double x1, double x2, double y1, double y2);
    double calcDeltaI(double _I0);
    double getI();
private:
    int flag;
    double (*func1)(double x);
    double (*func2)(double x, double y);
    double (*func6)(double x1, double y1, double z1, double x2, double y2, double z2);
    double I;
    shared_ptr<MethodIntegral> method;
};

#endif // CALCINTEGRAL_H
