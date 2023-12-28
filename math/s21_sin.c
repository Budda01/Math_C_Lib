#include "s21_math.h"

long double s21_sin(double x) {
  long double res = 0.0;
  long double rad = 0.0;
  if (x > 0 && x > S21_PI && s21_fmod(s21_floor(x / S21_PI), 2) == 1) {
    rad = -radianConversion(x);
  } else if (x < 0 && s21_fabs(x) > S21_PI &&
             s21_fmod(s21_floor(x / S21_PI), 2) == 0) {
    rad = -radianConversion(x);
  } else {
    rad = radianConversion(x);
  }
  for (int i = 0; i < 10; i++) {
    res += ((s21_pow(-1, i) * (s21_pow(rad, (1 + 2 * i)))) /
            s21_factorial(1 + 2 * i));
  }
  return res;
}