#ifndef METHODSIMPS_H
#define METHODSIMPS_H
#include "methodintegral.h"
#include <math.h>

using namespace std;

class MethodSimps : public MethodIntegral
{
public:
    MethodSimps(double _h);
    double calcInt(Func foo, double a, double b);

private:
    double h;
};

#endif // METHODSIMPS_H
