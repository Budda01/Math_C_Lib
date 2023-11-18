#include "s21_math.h"

long double s21_floor(double x) {
  long double res = 0.0;
  long double fracPart = 0.0;

  if (x == INF_VAL)
    res = INF_VAL;
  else if (x == (-1) * INF_VAL)
    res = (-1) * INF_VAL;
  else if (x == MAX_VAL)
    res = MAX_VAL;
  else {
    fracPart = x - (long long)x;
    if (x >= 0) {
      res = x - fracPart;
    } else{
      if (fracPart == 0.0){
        res = x;
      }
      else
        res = x - fracPart - 1;
      }
  }
  return res;
}