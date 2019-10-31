#ifndef CALCINTEGRAL_H
#define CALCINTEGRAL_H
#include <memory>
#include "methodintegral.h"
#include <iostream>

using namespace std;
typedef double (*Func)(int num, ...);

class CalcIntegral
{
public:
    CalcIntegral();
    ~CalcIntegral();
    CalcIntegral(Func _foo, MethodIntegral *_method);
    void setMethod(MethodIntegral* _method);
    void setFunc(Func _foo);
    double calc(double _a, double _b);
    double calc(double r);
    double calc(double x1, double x2, double y1, double y2);
    double calcDeltaI(double _I0);
    double getI();
private:
    int flag;
    Func foo;
    double I;
    shared_ptr<MethodIntegral> method;
};

#endif // CALCINTEGRAL_H
