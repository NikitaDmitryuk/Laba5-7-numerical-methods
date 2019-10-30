#include "methodsimps.h"

MethodSimps::MethodSimps(double _h)
{
    h = _h;
}

double MethodSimps::calcInt(double (*func)(double x), double a, double b){
      int n = int((b - a) /2.0/ h + 0.5);
      n = 2 * n;
      double k1 = 0, k2 = 0;
      for(int i = 1; i < n; i += 2) {
        k1 += func(a + i*h);
        k2 += func(a + (i+1)*h);
      }
      return h/3*(func(a) + 4 * k1 + 2 * k2);
}
