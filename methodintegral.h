#ifndef METHODINTEGRAL_H
#define METHODINTEGRAL_H
#include "iostream"

using namespace std;
typedef double (*Func)(int num, ...);

class MethodIntegral
{
public:
     MethodIntegral();
     virtual ~MethodIntegral()=0;
     virtual double calcInt(Func foo, double a, double b);
     virtual double calcInt(Func foo, double r);
};

#endif // METHODINTEGRAL_H
