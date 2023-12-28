#include "s21_math.h"

long double s21_asin(double x) {
  long double res = 0.0;
  if (x > -1 && x < 1) {
    res = s21_atan(x / s21_sqrt(1 - s21_pow(x, 2)));
  } else if (x > 1 || x < -1 || x == INF_VAL || x == -INF_VAL || x != x) {
    res = NAN_VAL;
  } else if (x == 1) {
    res = 1.570796;
  } else if (x == -1) {
    res = -1.570796;
  }
  return res;
}