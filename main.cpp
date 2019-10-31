#include <QCoreApplication>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include "calcintegral.h"
#include "methodintegral.h"
#include "methodmk.h"
#include "methodrectangles.h"
#include "methodtrial.h"
#include "methodsimps.h"
#include "methodrichardson.h"
#include "stdarg.h"

using namespace std;

double f(int num, ...){
    va_list args;
    va_start(args, num);
    double x = va_arg(args, double);
    va_end(args);
    return x;
}

double f1(int num, ...){
    va_list args;
    va_start(args, num);
    double x = va_arg(args, double);
    va_end(args);
    return exp(x);
}

double f1Int(double a, double b){
    return exp(b) - exp(a);
}

double f2(int num, ...){
    va_list args;
    va_start(args, num);
    double x = va_arg(args, double);
    va_end(args);
    return sin(x);
}

double f2Int(double a, double b){
    return -cos(b) + cos(a);
}

double f3(int num, ...){
    va_list args;
    va_start(args, num);
    double x = va_arg(args, double);
    va_end(args);
    return x / sqrt(5.0 - 4 * x);
}

double f3Int(double a, double b){
    return pow(-4 * b + 5, 3.0 / 2.0) / 24.0 - 5 * sqrt(-4 * b + 5) / 8.0 - (pow(-4 * a + 5, 3.0 / 2.0) / 24.0 - 5 * sqrt(-4 * a + 5) / 8.0);
}

double f7(int num, ...){
    double x[6];
    va_list args;
    va_start(args, num);
    for(;num >= 0;num--){
        x[num] = va_arg(args, double);
    }
    double r = sqrt((x[0] - x[3]) * (x[0] - x[3]) + (x[1] - x[4]) * (x[1] - x[4]) + (x[2] - x[5]) * (x[2] - x[5]));
    return 1.0 / M_PI / pow(r, 1.0);
}


int main(int argc, char *argv[])
{
    QCoreApplication qt(argc, argv);

    double h = 0.00001;
    int n = 100000;

    enum MethRect{
        LEFT,
        CENTER,
        RIGHT
    };

    enum MethMK{
        METHOD_MEDIUM,
        METHOD_SPACE,
        METHOD_SAMPLE,
        METHOD_MAINPART,
        METHOD_I1,
        METHOD_I2
    };

    CalcIntegral integral = CalcIntegral();

    integral.setMethod(new MethodMK(n, METHOD_MEDIUM));

    integral.setFunc(f1);
    cout << "Интеграл от exp(x) на интервале [0, 1] методом МК (0): " << integral.calc(0, 1.0) << " + " << integral.getI() - f1Int(0, 1.0) << endl;
    integral.setFunc(f2);
    cout << "Интеграл от sin(x) на интервале [0, pi/2] методом МК (0): " << integral.calc(0, M_PI / 2.0) << " + " << integral.getI() - f2Int(0, M_PI / 2.0) << endl;
    integral.setFunc(f3);
    cout << "Интеграл от x / sqrt(5.0 - 4 * x) на интервале [-1, 1] методом МК (0): " << integral.calc(-1, 1) << " + " << integral.getI() - f3Int(-1, 1) << endl;

    cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
    integral.setMethod(new MethodMK(n, METHOD_SPACE));

    integral.setFunc(f1);
    cout << "Интеграл от exp(x) на интервале [0, 1] методом МК (1): " << integral.calc(0, 1.0) << " + " << integral.getI() - f1Int(0, 1.0) << endl;
    integral.setFunc(f2);
    cout << "Интеграл от sin(x) на интервале [0, pi/2] методом МК (1): " << integral.calc(0, M_PI / 2.0) << " + " << integral.getI() - f2Int(0, M_PI / 2.0) << endl;
    integral.setFunc(f3);
    cout << "Интеграл от x / sqrt(5.0 - 4 * x) на интервале [-1, 1] методом МК (1): " << integral.calc(-1, 1) << " + " << integral.getI() - f3Int(-1, 1) << endl;

    cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
    integral.setMethod(new MethodRectangles(h, CENTER));

    integral.setFunc(f1);
    cout << "Интеграл от exp(x) на интервале [0, 1] методом центральных прямоугольников с шагом " << h << ": " << integral.calc(0, 1.0) << " + " << integral.getI() - f1Int(0, 1.0) << endl;
    integral.setFunc(f2);
    cout << "Интеграл от sin(x) на интервале [0, pi/2] методом центральных прямоугольников с шагом " << h << ": " << integral.calc(0, M_PI / 2.0) << " + " << integral.getI() - f2Int(0, M_PI / 2.0) << endl;
    integral.setFunc(f3);
    cout << "Интеграл от x / sqrt(5.0 - 4 * x) на интервале [-1, 1] методом центральных прямоугольников с шагом " << h << ": " << integral.calc(-1, 1) << " + " << integral.getI() - f3Int(-1, 1) << endl;

    cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
    integral.setMethod(new MethodRectangles(h, LEFT));

    integral.setFunc(f1);
    cout << "Интеграл от exp(x) на интервале [0, 1] методом левых прямоугольников с шагом " << h << ": " << integral.calc(0, 1.0) << " + " << integral.getI() - f1Int(0, 1.0) << endl;
    integral.setFunc(f2);
    cout << "Интеграл от sin(x) на интервале [0, pi/2] методом левых прямоугольников с шагом " << h << ": " << integral.calc(0, M_PI / 2.0) << " + " << integral.getI() - f2Int(0, M_PI / 2.0) << endl;
    integral.setFunc(f3);
    cout << "Интеграл от x / sqrt(5.0 - 4 * x) на интервале [-1, 1] методом левых прямоугольников с шагом " << h << ": " << integral.calc(-1, 1) << " + " << integral.getI() - f3Int(-1, 1) << endl;

    cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
    integral.setMethod(new MethodRectangles(h, RIGHT));

    integral.setFunc(f1);
    cout << "Интеграл от exp(x) на интервале [0, 1] методом правых прямоугольников с шагом " << h << ": " << integral.calc(0, 1.0) << " + " << integral.getI() - f1Int(0, 1.0) << endl;
    integral.setFunc(f2);
    cout << "Интеграл от sin(x) на интервале [0, pi/2] методом правых прямоугольников с шагом " << h << ": " << integral.calc(0, M_PI / 2.0) << " + " << integral.getI() - f2Int(0, M_PI / 2.0) << endl;
    integral.setFunc(f3);
    cout << "Интеграл от x / sqrt(5.0 - 4 * x) на интервале [-1, 1] методом правых прямоугольников с шагом " << h << ": " << integral.calc(-1, 1) << " + " << integral.getI() - f3Int(-1, 1) << endl;

    cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
    integral.setMethod(new MethodTrial(h));

    integral.setFunc(f1);
    cout << "Интеграл от exp(x) на интервале [0, 1] методом трапеций с шагом " << h << ": " << integral.calc(0, 1.0) << " + " << integral.getI() - f1Int(0, 1.0) << endl;
    integral.setFunc(f2);
    cout << "Интеграл от sin(x) на интервале [0, pi/2] методом трапеций с шагом " << h << ": " << integral.calc(0, M_PI / 2.0) << " + " << integral.getI() - f2Int(0, M_PI / 2.0) << endl;
    integral.setFunc(f3);
    cout << "Интеграл от x / sqrt(5.0 - 4 * x) на интервале [-1, 1] методом трапеций с шагом " << h << ": " << integral.calc(-1, 1) << " + " << integral.getI() - f3Int(-1, 1) << endl;

    cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
    integral.setMethod(new MethodSimps(h));

    integral.setFunc(f1);
    cout << "Интеграл от exp(x) на интервале [0, 1] методом Симпсона с шагом " << h << ": " << integral.calc(0, 1.0) << " + " << integral.getI() - f1Int(0, 1.0) << endl;
    integral.setFunc(f2);
    cout << "Интеграл от sin(x) на интервале [0, pi/2] методом Симпсона с шагом " << h << ": " << integral.calc(0, M_PI / 2.0) << " + " << integral.getI() - f2Int(0, M_PI / 2.0) << endl;
    integral.setFunc(f3);
    cout << "Интеграл от x / sqrt(5.0 - 4 * x) на интервале [-1, 1] методом Симпсона с шагом " << h << ": " << integral.calc(-1, 1) << " + " << integral.getI() - f3Int(-1, 1) << endl;

    cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
    integral.setMethod(new MethodRichardson(h));

    integral.setFunc(f1);
    cout << "Интеграл от exp(x) на интервале [0, 1] методом Экстраполяции Ричардсона с шагом " << h << ": " << integral.calc(0, 1.0) << " + " << integral.getI() - f1Int(0, 1.0) << endl;
    integral.setFunc(f2);
    cout << "Интеграл от sin(x) на интервале [0, pi/2] методом Экстраполяции Ричардсона с шагом " << h << ": " << integral.calc(0, M_PI / 2.0) << " + " << integral.getI() - f2Int(0, M_PI / 2.0) << endl;
    integral.setFunc(f3);
    cout << "Интеграл от x / sqrt(5.0 - 4 * x) на интервале [-1, 1] методом Экстраполяции Ричардсона с шагом " << h << ": " << integral.calc(-1, 1) << " + " << integral.getI() - f3Int(-1, 1) << endl;


    return qt.exec();
}
