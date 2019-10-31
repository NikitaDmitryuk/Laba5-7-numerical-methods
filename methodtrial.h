#ifndef METHODTRIAL_H
#define METHODTRIAL_H
#include "methodintegral.h"

class MethodTrial : public MethodIntegral
{
public:
    MethodTrial(double _h);
    double calcInt(Func foo, double a, double b);

private:
    double h;
};

#endif // METHODTRIAL_H
