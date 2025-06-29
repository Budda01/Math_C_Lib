#include "s21_math.h"

long double s21_cos(double x) {
  long double res = 0;
  long double rad = radianConversion(x);
  for (int i = 0; i < 10; i++) {
    res += ((s21_pow(-1, i) * (s21_pow(rad, (2 * i)))) / s21_factorial(2 * i));
  }
  return res;
}