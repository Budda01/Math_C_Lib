#ifndef S21_MATH
#define S21_MATH

#include <stdio.h>
#include <stdlib.h>

#define EXP 2.718281828459045
#define MAX_VAL 1.7976931348623157e+308
#define MAX_LOG_VAL 709.7827128933839730962
#define INF_VAL 1.0 / 0.0
#define NAN_VAL 0.0 / 0.0

int s21_factorial(int x);
long double s21_exp(double x);
int s21_abs(int x);
long double s21_fabs(double x);
long double expSeriesExpansion(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_pow(double base, double exp);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double logSeriesExpansion(double x);

#endif  // S21_MATH