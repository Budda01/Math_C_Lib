#include "s21_math.h"

long double s21_ceil(double x) {
  long double fracPartX = 0.0;
  if (x < MAX_VAL){
    fracPartX = (x - (long long)x);
  }
  return (fracPartX > 0.0 ? x - fracPartX + 1 : x);
}

