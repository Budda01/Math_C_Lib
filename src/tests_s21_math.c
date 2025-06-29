#include "tests_s21_math.h"

#include "s21_math.h"

START_TEST(test_s21_abs) {
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(100), abs(-100));
  ck_assert_int_eq(s21_abs(-100000000), abs(100000000));
  ck_assert_int_eq(s21_abs(999999999), abs(-999999999));
  ck_assert_int_eq(s21_abs(000003546), abs(-000003546));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(-0), abs(0));
}
END_TEST

START_TEST(test_s21_ceil) {
  ck_assert_ldouble_eq(s21_ceil(5.49), ceil(5.49));
  ck_assert_ldouble_eq(s21_ceil(-5.00001), ceil(-5.00001));
  ck_assert_ldouble_eq(s21_ceil(-999999999.000001), ceil(-999999999.000001));
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
  ck_assert_ldouble_eq(s21_ceil(-0), ceil(-0));
  ck_assert_ldouble_eq(s21_ceil(1), ceil(1));
  ck_assert_ldouble_eq(s21_ceil(000003546), ceil(000003546));
  ck_assert_ldouble_eq(s21_ceil(00000), ceil(00000));
  ck_assert_ldouble_eq(s21_ceil(.002), ceil(.002));
  ck_assert_ldouble_eq(s21_ceil(INF_VAL), ceil(INF_VAL));
  ck_assert_ldouble_eq(s21_ceil(-INF_VAL), ceil(-INF_VAL));
  ck_assert_ldouble_eq(s21_ceil(MAX_VAL), ceil(MAX_VAL));
  ck_assert_ldouble_eq(s21_ceil(EXP), ceil(EXP));
  ck_assert_ldouble_nan(s21_ceil(NAN_VAL));
  ck_assert_ldouble_eq(s21_ceil(MAX_LOG_VAL), ceil(MAX_LOG_VAL));
}
END_TEST

START_TEST(test_s21_exp) {
  ck_assert_ldouble_ne_tol(s21_exp(MAX_LOG_VAL), exp(MAX_LOG_VAL), 1e+16);
  ck_assert_ldouble_nan(s21_exp(NAN_VAL));
  ck_assert_ldouble_eq(s21_exp(MAX_VAL), exp(MAX_VAL));
  ck_assert_ldouble_eq_tol(s21_exp(EXP), exp(EXP), 1e-6);
  ck_assert_ldouble_eq(s21_exp(710), exp(710));
  ck_assert_ldouble_eq(s21_exp(INF_VAL), exp(INF_VAL));
  ck_assert_ldouble_eq_tol(s21_exp(-10), exp(-10), 1e-6);
  ck_assert_ldouble_ne_tol(s21_exp(56), exp(56), 1e+9);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-0), exp(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(00000), exp(00000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(6.4343e-29), exp(6.4343e-29), 1e-6);
}
END_TEST

START_TEST(test_s21_fabs) {
  ck_assert_ldouble_eq(s21_fabs(-1.0), fabs(-1.0));
  ck_assert_ldouble_eq(s21_fabs(100), fabs(-100.000000));
  ck_assert_ldouble_eq(s21_fabs(-100000000.456789), fabs(100000000.456789));
  ck_assert_ldouble_eq(s21_fabs(999999999.999999), fabs(-999999999.999999));
  ck_assert_ldouble_eq(s21_fabs(000003546.0), fabs(-000003546.0));
  ck_assert_ldouble_eq(s21_fabs(0.0), fabs(-0.0));
  ck_assert_ldouble_eq(s21_fabs(-0.000001), fabs(0.000001));
  ck_assert_ldouble_eq(s21_fabs(EXP), fabs(EXP));
  ck_assert_ldouble_eq(s21_fabs(MAX_VAL), fabs(MAX_VAL));
  ck_assert_ldouble_eq(s21_fabs(MAX_LOG_VAL), fabs(MAX_LOG_VAL));
  ck_assert_ldouble_nan(s21_fabs(NAN_VAL));
  ck_assert_ldouble_eq(s21_fabs(INF_VAL), fabs(INF_VAL));
}
END_TEST

START_TEST(test_s21_floor) {
  ck_assert_ldouble_eq(s21_floor(5.49), floor(5.49));
  ck_assert_ldouble_eq(s21_floor(-5.00001), floor(-5.00001));
  ck_assert_ldouble_eq(s21_floor(-999999999), floor(-999999999));
  ck_assert_ldouble_eq(s21_floor(0), floor(0));
  ck_assert_ldouble_eq(s21_floor(-0), floor(-0));
  ck_assert_ldouble_eq(s21_floor(1), floor(1));
  ck_assert_ldouble_eq(s21_floor(000003546), floor(000003546));
  ck_assert_ldouble_eq(s21_floor(00000), floor(00000));
  ck_assert_ldouble_eq(s21_floor(.002), floor(.002));
  ck_assert_ldouble_eq(s21_floor(INF_VAL), floor(INF_VAL));
  ck_assert_ldouble_eq(s21_floor(MAX_VAL), floor(MAX_VAL));
  ck_assert_ldouble_eq(s21_floor(MAX_LOG_VAL), floor(MAX_LOG_VAL));
  ck_assert_ldouble_eq(s21_floor(EXP), floor(EXP));
  ck_assert_ldouble_nan(s21_floor(NAN_VAL));
}
END_TEST

START_TEST(test_s21_fmod) {
  ck_assert_ldouble_eq(s21_fmod(6.5, 5), fmod(6.5, 5));
  ck_assert_ldouble_eq(s21_fmod(6.500000, 5.000000), fmod(6.500000, 5.000000));
  ck_assert_ldouble_eq_tol(s21_fmod(31.400001, 0.000001),
                           fmod(31.400001, 0.000001), 1e-6);
  ck_assert_ldouble_eq(s21_fmod(EXP, EXP), fmod(EXP, EXP));
  ck_assert_ldouble_eq_tol(s21_fmod(EXP, 0.7), fmod(EXP, 0.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(EXP, -0.7), fmod(EXP, -0.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(MAX_LOG_VAL, 0.764),
                           fmod(MAX_LOG_VAL, 0.764), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(1e10, 0.31), fmod(1e10, 0.31), 1e-6);
  ck_assert_ldouble_eq(s21_fmod(14, INF_VAL), fmod(14, INF_VAL));
  ck_assert_ldouble_eq(s21_fmod(14, -INF_VAL), fmod(14, -INF_VAL));
  ck_assert_ldouble_nan(s21_fmod(INF_VAL, INF_VAL));
  ck_assert_ldouble_nan(s21_fmod(-INF_VAL, INF_VAL));
  ck_assert_ldouble_nan(s21_fmod(INF_VAL, 2));
  ck_assert_ldouble_nan(s21_fmod(NAN_VAL, 0.764));
  ck_assert_ldouble_nan(s21_fmod(100423, NAN_VAL));
  ck_assert_ldouble_nan(s21_fmod(6.5, 0));
  ck_assert_ldouble_eq(s21_fmod(0, 5), fmod(0, 5));
}
END_TEST

START_TEST(test_s21_log) {
  ck_assert_ldouble_eq_tol(s21_log(6.5), log(6.5), 1e-6);
  ck_assert_ldouble_eq(s21_log(0.0), log(0.0));
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_eq_tol(s21_log(100.000000), log(100.000000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(000003546.0), log(000003546.0), 1e-6);
  ck_assert_ldouble_eq(s21_log(0.0), log(0.0));
  ck_assert_ldouble_eq_tol(s21_log(0.000001), log(0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(EXP), log(EXP), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(MAX_VAL), log(MAX_VAL), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(MAX_LOG_VAL), log(MAX_LOG_VAL), 1e-6);
  ck_assert_ldouble_eq(s21_log(INF_VAL), log(INF_VAL));
  ck_assert_ldouble_nan(s21_log(NAN_VAL));
}
END_TEST

START_TEST(test_s21_pow) {
  ck_assert_ldouble_eq(s21_pow(1, -1), pow(1, -1));
  ck_assert_ldouble_eq_tol(s21_pow(100, -13), pow(100, -13), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.000001, 22), pow(0.000001, 22), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(06.000001, -13), pow(06.000001, -13), 1e-6);
  ck_assert_ldouble_eq(s21_pow(06.000001, 0), pow(06.000001, 0));
  ck_assert_ldouble_eq(s21_pow(INF_VAL, 0), pow(INF_VAL, 0));
  ck_assert_ldouble_eq(s21_pow(INF_VAL, 10), pow(INF_VAL, 10));
  ck_assert_ldouble_eq(s21_pow(5, 0003), pow(5, 0003));
  ck_assert_ldouble_eq_tol(s21_pow(31.434535354, EXP), pow(31.434535354, EXP),
                           1e-6);
  ck_assert_ldouble_eq(s21_pow(0, 1), pow(0, 1));
  ck_assert_ldouble_eq(s21_pow(-0.0, 1), pow(-0.0, 1));
  ck_assert_ldouble_eq(s21_pow(MAX_VAL, 10), pow(MAX_VAL, 10));
  ck_assert_ldouble_ne_tol(s21_pow(MAX_LOG_VAL, 10), pow(MAX_LOG_VAL, 10),
                           1e+11);
  ck_assert_ldouble_eq_tol(s21_pow(EXP, 10), pow(EXP, 10), 1e-6);
  ck_assert_ldouble_nan(s21_pow(NAN_VAL, 10));
  ck_assert_ldouble_eq_tol(s21_pow(-81, -1), pow(-81, -1), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt) {
  ck_assert_ldouble_eq_tol(s21_sqrt(100), sqrt(100), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.000001), sqrt(0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(06.000001), sqrt(06.000001), 1e-6);
  ck_assert_ldouble_eq(s21_sqrt(INF_VAL), sqrt(INF_VAL));
  ck_assert_ldouble_eq_tol(s21_sqrt(0003), sqrt(0003), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(31.434535354), sqrt(31.434535354), 1e-6);
  ck_assert_ldouble_eq(s21_sqrt(0.0), sqrt(0.0));
  ck_assert_ldouble_eq_tol(s21_sqrt(EXP), sqrt(EXP), 1e-6);
  ck_assert_ldouble_ne_tol(s21_sqrt(MAX_VAL), sqrt(MAX_VAL), 1e+16);
  ck_assert_ldouble_eq_tol(s21_sqrt(MAX_LOG_VAL), sqrt(MAX_LOG_VAL), 1e-6);
  ck_assert_ldouble_nan(s21_sqrt(NAN_VAL));
  ck_assert_ldouble_nan(s21_sqrt(-387));
}
END_TEST

START_TEST(test_s21_cos) {
  ck_assert_ldouble_eq_tol(s21_cos(987565.9874641213656),
                           cos(987565.9874641213656), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-576.000007), cos(-576.000007), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(3), cos(3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(4), cos(4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(6), cos(6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-66), cos(-66), 1e-6);
  ck_assert_ldouble_nan(s21_cos(NAN_VAL));
  ck_assert_ldouble_nan(s21_cos(INF_VAL));
  ck_assert_ldouble_eq_tol(s21_cos(0.0000000456445), cos(0.0000000456445),
                           1e-6);
}
END_TEST

START_TEST(test_s21_sin) {
  ck_assert_ldouble_eq_tol(s21_sin(987565.9874641213656),
                           sin(987565.9874641213656), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-576.000007), sin(-576.000007), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(2), sin(2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(4), sin(4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-4), sin(-4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(6), sin(6), 1e-6);
  ck_assert_ldouble_nan(s21_sin(NAN_VAL));
  ck_assert_ldouble_nan(s21_sin(INF_VAL));
  ck_assert_ldouble_eq_tol(s21_sin(0.00000005465123161),
                           sin(0.00000005465123161), 1e-6);
}
END_TEST

START_TEST(test_s21_tan) {
  ck_assert_ldouble_eq_tol(s21_tan(-4), tan(-4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(534535), tan(534535), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-576.000007), tan(-576.000007), 1e-6);
  ck_assert_ldouble_nan(s21_tan(NAN_VAL));
  ck_assert_ldouble_nan(s21_tan(INF_VAL));
  ck_assert_ldouble_infinite(s21_tan(S21_PI / 2));
  ck_assert_ldouble_infinite(s21_tan(-S21_PI / 2));
  ck_assert_ldouble_eq_tol(s21_tan(-0.00000074645632171),
                           tan(-0.00000074645632171), 1e-6);
}
END_TEST

START_TEST(test_s21_atan) {
  ck_assert_ldouble_eq_tol(s21_atan(-4), atan(-4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(999999999999999), atan(999999999999999),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.799), atan(0.799), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.009), atan(0.009), 1e-6);
  ck_assert_ldouble_nan(s21_atan(NAN_VAL));
  ck_assert_ldouble_nan(s21_atan(INF_VAL));
  ck_assert_ldouble_nan(s21_atan(-INF_VAL));
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
}
END_TEST

START_TEST(test_s21_asin) {
  ck_assert_ldouble_nan(s21_asin(-4));
  ck_assert_ldouble_nan(s21_asin(4));
  ck_assert_ldouble_nan(s21_asin(99999.99));
  ck_assert_ldouble_nan(s21_asin(-9999.99));
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.5646), asin(0.5646), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.7766), asin(-0.7766), 1e-6);
  ck_assert_ldouble_nan(s21_asin(NAN_VAL));
  ck_assert_ldouble_nan(s21_asin(INF_VAL));
  ck_assert_ldouble_nan(s21_asin(-INF_VAL));
}
END_TEST

START_TEST(test_s21_acos) {
  ck_assert_ldouble_nan(s21_acos(9999999.9));
  ck_assert_ldouble_nan(s21_acos(2));
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.568), acos(0.568), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.568), acos(-0.568), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_ldouble_nan(s21_acos(-2));
  ck_assert_ldouble_nan(s21_acos(-9999999.9));
  ck_assert_ldouble_nan(s21_acos(NAN_VAL));
  ck_assert_ldouble_nan(s21_acos(INF_VAL));
  ck_assert_ldouble_nan(s21_acos(-INF_VAL));
}
END_TEST

Suite *suite_tests_s21_math(void) {
  Suite *suite;
  TCase *t_cases;

  suite = suite_create("TEST_MATH");
  t_cases = tcase_create("CASES");

  tcase_add_test(t_cases, test_s21_abs);
  tcase_add_test(t_cases, test_s21_ceil);
  tcase_add_test(t_cases, test_s21_exp);
  tcase_add_test(t_cases, test_s21_fabs);
  tcase_add_test(t_cases, test_s21_floor);
  tcase_add_test(t_cases, test_s21_fmod);
  tcase_add_test(t_cases, test_s21_log);
  tcase_add_test(t_cases, test_s21_pow);
  tcase_add_test(t_cases, test_s21_sqrt);
  tcase_add_test(t_cases, test_s21_cos);
  tcase_add_test(t_cases, test_s21_sin);
  tcase_add_test(t_cases, test_s21_tan);
  tcase_add_test(t_cases, test_s21_atan);
  tcase_add_test(t_cases, test_s21_asin);
  tcase_add_test(t_cases, test_s21_acos);

  suite_add_tcase(suite, t_cases);

  return suite;
}

int main() {
  int fails;
  Suite *suite;
  SRunner *srunner;

  suite = suite_tests_s21_math();
  srunner = srunner_create(suite);

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_NORMAL);
  fails = srunner_ntests_failed(srunner);
  srunner_free(srunner);
  if (fails > 0)
    return EXIT_FAILURE;
  else
    return EXIT_SUCCESS;
}
