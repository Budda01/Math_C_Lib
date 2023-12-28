#include "s21_math.h"

long double s21_atan(double x) {
  long double res_1 = 0.0;
  long double res_2 = 0.0;
  int check = 0;
  if (x > -1 && x < 1) {
    for (int i = 0; i < 5000; i++) {
      res_1 += (s21_pow(-1, i) * s21_pow(x, (1 + 2 * i))) / (1 + 2 * i);
    }
  } else if (x > 1 || x < -1) {
    check = 1;
    for (int i = 0; i < 500; i++) {
      res_1 += (s21_pow(-1, i) * s21_pow(x, (-1 - 2 * i))) / (1 + 2 * i);
    }
    res_2 = (S21_PI * s21_fabs(x)) / (2 * x) - res_1;
  } else if (x == 1) {
    res_1 = 0.785398;
  } else if (x == -1) {
    res_1 = -0.785398;
  } else if (x == INF_VAL) {
    res_1 = 1.570796;
  } else if (x == -INF_VAL) {
    res_1 = -1.570796;
  } else if (x != x) {
    res_1 = NAN_VAL;
  }
  return (check == 0) ? res_1 : res_2;
}