#include "s21_math.h"


long double s21_log(double x){

    long double sum = 0.0;
    long double numin = 0.0;
    int count = 0;

    if(x < 1.0 && x > 0.0){
        numin = (x-1);
        count = 1;
    }
    else{
        numin = ((x-1)/(x+1)); 
        count = 2;
    }

    for (int n = 1; n <= 1000; n +=count){
        long double prod = 1.0;
        for (int i = 1; i <= n; i++){
            prod *= numin;
        }
        if (n % 2 == 1 && x < 1){
            prod = (-1)*prod;
        }
        sum += (prod/n);
    }
    return x < 1 ? (-1)*sum : 2*sum;
}

