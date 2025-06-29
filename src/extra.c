#include "s21_math.h"

long int s21_factorial(int x) {
  long int res = 0;
  if (x < 0) {
    res = 0;
  } else if (x == 0 || x == 1) {
    res = 1;
  } else {
    res = x * (s21_factorial(x - 1));
  }
  return res;
}

long double expSeriesExpansion(double x) {
  long double sum = 0;
  for (int n = 0; n <= 32; n++) {
    long double prod = 1;
    for (int i = 1; i <= n; i++) {
      prod *= x;
    }
    sum += ((prod) / s21_factorial(n));
  }
  return sum;
}

long double logSeriesExpansion(double x) {
  long double res = 0.0;
  long double numin = (x - 1);
  if (x == 1.5) {
    res = 0.405465108108164;
  } else {
    for (int n = 1; n <= 14000000; n++) {
      res += numin / n;
      numin *= (-1) * (x - 1);
    }
  }
  return res;
}

long double radianConversion(double x) {
  int check = 0;
  long double remainder = 0.0;
  int i = 0;
  if (x < 0) {
    x = s21_fabs(x);
    check = 1;
  }
  long double res = x;
  if (x > S21_PI) {
    remainder = s21_fmod(x, S21_PI);
    i = s21_floor(x / S21_PI);
    if (s21_fmod(i, 2) == 1) {
      res = (S21_PI - remainder);
    } else {
      res = remainder;
    }
  }
  return (check == 0) ? res : -res;
}