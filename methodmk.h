#ifndef METHODMK_H
#define METHODMK_H
#include "methodintegral.h"
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include "calcintegral.h"
#include "methodintegral.h"
#include "memory.h"

using namespace std;

class MethodMK : public MethodIntegral
{
public:
    MethodMK(int _n, int _method);
    double calcInt(Func foo, double a, double b);
    double calcInt(Func foo, double r);

private:
    int n, method;
    enum Method{
        METHOD_MEDIUM,
        METHOD_SPACE,
        METHOD_SAMPLE,
        METHOD_MAINPART,
        METHOD_I1,
        METHOD_I2
    };
};

#endif // METHODMK_H
