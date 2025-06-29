#include "s21_math.h"
#include <math.h>


    #include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Засекаем начальное время

    // printf("%Lf\n", s21_fabs(0.0/0.0));
    // printf("%f\n", fabs(0.0/0.0));
    // printf("\n");
    // printf("%0.19Lf\n", s21_exp(0.000001));
    // printf("%0.19f\n", exp(0.000001));
    // printf("\n");
    printf("%0.6Lf\n", s21_log(MAX_VAL));
    printf("%0.6f\n", log(MAX_VAL));
    printf("%0.6Lf\n", s21_log(56556));
    printf("%0.6f\n", log(56556));
    // printf("%Lf\n", s21_ceil(5435345363456473123));
    // printf("%f\n", ceil(5435345363456473123));
    // printf("\n");
    // printf("%Lf\n", s21_floor(MAX_VAL));
    // printf("%f\n", floor(MAX_VAL));
    // printf("\n");
    // printf("%Lf\n", s21_fmod(54546.5456, 43.33));
    // printf("%f\n", fmod(54546.5456, 43.33));

    // printf("\n");
    // printf("%0.19f\n", pow(5, 5));
    // printf("%0.19Lf\n", s21_pow(5, 5));
    printf("%0.6f\n", sqrt(0.000001));
    printf("%0.6Lf\n", s21_sqrt(0.000001));

    end = clock(); // Засекаем конечное время

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Вычисляем время выполнения в секундах
    printf("Время выполнения: %f секунд\n", cpu_time_used);

    return 0;
}
