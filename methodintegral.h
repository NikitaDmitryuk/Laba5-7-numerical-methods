#ifndef METHODINTEGRAL_H
#define METHODINTEGRAL_H
#include "iostream"

using namespace std;

class MethodIntegral
{
public:
     MethodIntegral();
     virtual ~MethodIntegral()=0;
     virtual double calcInt(double (*func)(double x), double a, double b)=0;
     virtual double calcInt(double (*func)(double x, double y), double x1, double x2, double y1, double y2);
     virtual double calcInt(double (*func)(double x1, double y1, double z1, double x2, double y2, double z2), double r);
};

#endif // METHODINTEGRAL_H
