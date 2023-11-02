#include "s21_math.h"

long double s21_sqrt(double x){
    long double res = s21_exp(s21_log(x)/2);
    return res;
}