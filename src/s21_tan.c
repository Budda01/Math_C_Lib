#include "s21_math.h"

long double s21_tan(double x) {
  long double res = 0.0;
  if (x == S21_PI / 2) {
    res = INF_VAL;
  } else if (x == -S21_PI / 2) {
    res = -INF_VAL;
  } else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}