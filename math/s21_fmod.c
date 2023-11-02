#include "s21_math.h"

long double s21_fmod(double x, double y){
    if (x < 0){
        x = s21_fabs(x);
    }
    if (y < 0){
        y = s21_fabs(y);
    }
    long double res = x;
    if (y != 0.0){
        while(x > y){
            res = x - y;
            y += y;
        }
    }
    return res;
}