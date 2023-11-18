#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double comp = 0.0;
  int check = 0;
  int check_inf = 0;
  if (x < 0) {
    x = s21_fabs(x);
    check = 1;
  }
  long double res = x;
  if (y < 0) y = s21_fabs(y);

  if (x == INF_VAL) {
    res = NAN_VAL;
    check_inf = 1;
  } else if (y != y) {
    res = NAN_VAL;
  } else if (y != 0.0) {
    while (x >= comp) {
      res = x - comp;
      comp += y;
    }
  } else {
    res = (-1) * NAN_VAL;
  }
  return (check == 0 || check_inf == 1) ? res : (-1) * res;
}