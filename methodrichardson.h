#ifndef METHODRICHARDSON_H
#define METHODRICHARDSON_H
#include "methodintegral.h"
#include "calcintegral.h"
#include "methodsimps.h"
#include <memory>

using namespace std;

class MethodRichardson : public MethodIntegral
{
public:
    MethodRichardson(double _h);
    double calcInt(double (*func)(double x), double a, double b);
private:
    double h;
};

#endif // METHODRICHARDSON_H
