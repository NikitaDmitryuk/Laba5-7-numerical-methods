#include "calcintegral.h"

CalcIntegral::CalcIntegral()
{

}

CalcIntegral::~CalcIntegral()
{
    method.~shared_ptr();
}

CalcIntegral::CalcIntegral(double (*_func)(double x), MethodIntegral *_method){
    func1 = _func;
    flag = 1;
    method.reset(_method);
}

CalcIntegral::CalcIntegral(double (*_func)(double x, double y), MethodIntegral *_method){
    func2 = _func;
    flag = 2;
    method.reset(_method);
}

void CalcIntegral::setMethod(MethodIntegral* _method){
    method.reset(_method);
}

void CalcIntegral::setFunc(double (*_func)(double x)){
    func1 = _func;
    flag = 1;
}

void CalcIntegral::setFunc(double (*_func)(double x, double y)){
    func2 = _func;
    flag = 2;
}

double CalcIntegral::getI(){
    return I;
}

double CalcIntegral::calc(double _a, double _b){
    double res = 0;
    if(flag == 1){
        res =  method.get()->calcInt(func1, _a, _b);
    } else {
        cout << "функция была изменена" << endl;
    }
    I = res;
    return res;
}

double CalcIntegral::calc(double x1, double x2, double y1, double y2){
    double res = 0;
    if(flag == 2){
        res = method.get()->calcInt(func2, x1, x2, y1, y2);
    } else {
        cout << "функция была изменена" << endl;
    }
    I = res;
    return res;
}

double CalcIntegral::calc(double r){
    double res = 0;
    if(flag == 6){
        res =  method.get()->calcInt(func6, r);
    } else {
        cout << "функция была изменена" << endl;
    }
    I = res;
    return res;
}

void CalcIntegral::setFunc(double (*_func)(double x1, double y1, double z1, double x2, double y2, double z2)){
    func6 = _func;
    flag = 6;
}
