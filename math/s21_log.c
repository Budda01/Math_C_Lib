#include "s21_math.h"

long double s21_log(double x) {
  long double res = 0.0;
  int count = 1;
  double r = 1.5;
  if (x == INF_VAL)
    res = INF_VAL;
  else if (x == (-1) * INF_VAL || x < 0 || x != x)
    res = NAN_VAL;
  else if (x == 0.0)
    res = (-1) * INF_VAL;
  else if (x > r) {
    long double n = x;
    while (n > r) {
      n = n / r;
      count++;
    }
    for (int i = 1; i < count; i++) {
      res += logSeriesExpansion(r);
    }
    res += logSeriesExpansion(n);
  } else if (x > 0.0) {
    res = logSeriesExpansion(x);
  }
  return res;
}
