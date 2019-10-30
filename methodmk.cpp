#include "methodmk.h"

MethodMK::MethodMK(int _n, int _method)
{
    n = _n;
    method = _method;
}

double MethodMK::calcInt(double (*func)(double x), double a, double b){
    double fi, nSup, nInf, sup, inf, x, y, f, result;
    int i;
    switch (method)
    {
    case METHOD_MEDIUM:
        fi = 0;
        for(i = 0; i < n ; i++, fi += func(rand() / double(RAND_MAX) * (b - a) + a));
        result = (b - a) * fi / n;
        break;
    case METHOD_SPACE:
        nSup = 0;
        nInf = 0;
        sup = func(b) * 1.1;
        inf = 0;

        for(i = 0; i < n; i++){
            x = rand() / double(RAND_MAX) * (b - a) + a;
            y = rand() / double(RAND_MAX) * (sup - inf) + inf;
            f = func(x);
            if(f >= 0){
                if(y < f)
                    nSup++;
                if(f > sup)
                    sup = f * 1.1;
            }else {
                if(y > f)
                    nInf++;
                if(f < inf)
                    inf = f * 1.1;
            }
        }
        result = (sup * nSup + inf * nInf) * (b - a) / n;
        break;
    case METHOD_SAMPLE:
        result = 0;
        break;
    default:
        result = 0;
        cout << "Нет такого метода" << endl;
        break;
    }
    return result;
}

double MethodMK::calcInt(double (*func)(double x, double y), double x1, double x2, double y1, double y2){
    double fi, result;
    switch (method) {
    case METHOD_MEDIUM:
        fi = 0;
        for(int i = 0; i < n ; i++, fi += func(rand() / double(RAND_MAX) * (x2 - x1) + x1, rand() / double(RAND_MAX) * (y2 - y1) + y1));
        result = (x2 - x1) * (y2 - y1) * fi / n;
        break;
    default:
        cout << "Нет такого метода" << endl;
        result = 0;
    }
    return  result;
}

double MethodMK::calcInt(double (*func)(double x1, double y1, double z1, double x2, double y2, double z2), double r){

    double fi, result, phi1, rad1, theta1, phi2, rad2, theta2, x1, y1, z1, x2, y2, z2;
    switch (method) {
    case METHOD_I1:
        fi = 0;

        for(int i = 0; i < n ; i++){
            phi1 = rand() / double(RAND_MAX) * 2 * M_PI;
            theta1 = rand() / double(RAND_MAX) * M_PI - M_PI / 2.0;
            rad1 = rand() / double(RAND_MAX) * r;
            phi2 = rand() / double(RAND_MAX) * 2 * M_PI;
            theta2 = rand() / double(RAND_MAX) * M_PI - M_PI / 2.0;
            rad2 = rand() / double(RAND_MAX) * r;
            x1 = rad1 * sin(theta1) * cos(phi1);
            y1 = rad1 * sin(theta1) * sin(phi1);
            z1 = rad1 * cos(theta1);
            x2 = rad2 * sin(theta2) * cos(phi2);
            y2 = rad2 * sin(theta2) * sin(phi2);
            z2 = rad2 * cos(theta2);
            fi += func(x1, y1, z1, x2, y2, z2);
        }
        result = (4.0 / 3.0) * (4.0 / 3.0) * fi / n;
        break;
    default:
        cout << "Нет такого метода" << endl;
        result = 0;
    }
    return  result;

}
