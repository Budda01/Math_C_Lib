#include "s21_math.h"

long double s21_fmod(double x, double y) {
  int check_x = 0;
  int check_y = 0;
  int check_inf = 0;
  if (x < 0) {
    x = s21_fabs(x);
    check_x = 1;
  }
  long double res = x;
  if (y < 0) {
    y = s21_fabs(y);
    check_y = 1;
  }
  if (x == INF_VAL && y == INF_VAL) {
    res = NAN_VAL;
  } else if (y == INF_VAL) {
    res = x;
  } else if (x == INF_VAL) {
    res = NAN_VAL;
    check_inf = 1;
  } else if (y != y) {
    res = NAN_VAL;
  } else if (y != 0.0) {
    res = x - y * (long long int)(x / y);

  } else {
    res = (-1) * NAN_VAL;
  }
  return (check_x == 0 || check_inf == 1 || check_y == 1) ? res : (-1) * res;
}