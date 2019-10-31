#ifndef METHODRECTANGLES_H
#define METHODRECTANGLES_H
#include "methodintegral.h"
#include <math.h>
using namespace std;
class MethodRectangles : public MethodIntegral
{
public:
    MethodRectangles(double _h, int _method);
    double calcInt(Func foo, double a, double b);

private:
    double h;
    int method;
    enum Method{
        LEFT,
        CENTER,
        RIGHT
    };
};

#endif // METHODRECTANGLES_H
