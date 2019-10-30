#include "methodintegral.h"

MethodIntegral::MethodIntegral()
{

}

MethodIntegral::~MethodIntegral()
{

}

double MethodIntegral::calcInt(double (*func)(double x, double y), double x1, double x2, double y1, double y2){
    cout << "Нет реализации функции" << endl;
    return 0;
}

double MethodIntegral::calcInt(double (*func)(double x1, double y1, double z1, double x2, double y2, double z2), double r){
    cout << "Нет реализации функции" << endl;
    return 0;
}
