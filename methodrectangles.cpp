#include "methodrectangles.h"

MethodRectangles::MethodRectangles(double _h, int _method)
{
    h = _h;
    method = _method;
}

double MethodRectangles::calcInt(Func foo, double a, double b){
    double i, I;
    I = 0;
    switch (method) {
    case LEFT:
        for(i = a; i < b; I += foo(1, i), i += h);
        I *= h;
        break;
    case CENTER:
        for(i = a + h / 2.0; i < b; I += foo(1, i), i += h);
        I *= h;
        break;
    case RIGHT:
        for(i = a + h; i <= b; I += foo(1, i), i += h);
        I *= h;
        break;
    }
    return I;
}
