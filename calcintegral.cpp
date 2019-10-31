#include "calcintegral.h"

CalcIntegral::CalcIntegral()
{

}

CalcIntegral::~CalcIntegral()
{
    method.~shared_ptr();
}

CalcIntegral::CalcIntegral(Func _foo, MethodIntegral *_method){
    foo = _foo;
    method.reset(_method);
}

void CalcIntegral::setMethod(MethodIntegral* _method){
    method.reset(_method);
}

void CalcIntegral::setFunc(Func _foo){
    foo = _foo;
}


double CalcIntegral::getI(){
    return I;
}

double CalcIntegral::calc(double _a, double _b){

    I =  method.get()->calcInt(foo, _a, _b);
    return I;
}


double CalcIntegral::calc(double r){

    I =  method.get()->calcInt(foo, r);
    return I;
}

