#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double res = 1.0;
  int check = 0;
  if (exp < 0.0) {
    check = 1;
    exp = s21_fabs(exp);
  }
  int intPartExp = (int)exp;
  long double fracPartExp = (exp - intPartExp);
  for (int i = 1; i <= intPartExp; i++) {
    res = res * base;
  }
  if (fracPartExp != 0) {
    res *= s21_exp(fracPartExp * (s21_log(base)));
  }
  if (res > MAX_VAL) res = INF_VAL;
  return (check == 0) ? res : 1.0 / res;
}