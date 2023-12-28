#include "s21_math.h"

long double s21_acos(double x) {
  long double res = 0.0;
  if (x > 0 && x < 1) {
    res = s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  } else if (x > -1 && x < 0) {
    res = S21_PI + s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  } else if (x == 1) {
    res = 0.0;
  } else if (x == -1) {
    res = S21_PI;
  } else if (x == 0) {
    res = 1.570796;
  } else if (x != x || x == INF_VAL || x == -INF_VAL || x > 1 || x < -1) {
    res = NAN_VAL;
  }
  return res;
}