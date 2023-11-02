#include "s21_math.h"

long double s21_ceil(double x){
    long double fracPartX = (x - (int)x);
    return fracPartX > 0.0 ? (int)x+1 : x;
}