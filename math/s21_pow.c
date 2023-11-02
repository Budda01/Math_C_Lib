#include "s21_math.h"

long double s21_pow(double base, double exp){
    long double res = 1.0;
    int intPartExp = (int)exp;
    long double fracPartExp = exp - intPartExp;
    for (int i = 1; i <= intPartExp; i++){
        res *= base;
    }
    if (fracPartExp != 0.0){
        res *= s21_exp(fracPartExp*(s21_log(base)));
    } 
    return res;
}