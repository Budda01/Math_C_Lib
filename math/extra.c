#include "s21_math.h"


int s21_factorial(int x){
    int res = 0;
    if (x == 0 || x == 1){
        res = 1;
    }
    else{
        res = x*(s21_factorial(x-1));
    }
    return res;
}

long double expSeriesExpansion(double x){
    long double sum = 0;
    for (int n = 0; n <= 32; n++){
        long double prod = 1;
        for (int i = 1; i <= n; i++){
            prod *= x;
        }
        sum += ((prod)/s21_factorial(n));
    }
    return sum;
}
