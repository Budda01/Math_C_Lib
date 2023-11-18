#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res;
  if (x < 0.0 || x != x) {
    res = (-1) * NAN_VAL;
  } else if (x == 0.0)
    res = 0.0;
  else
    res = s21_exp(s21_log(x) / 2);
  return res;
}