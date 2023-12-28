CFLAGS = gcc -Wall -Werror -Wextra -std=c11 
L = -L. -lcheck -lmath
UNI_F = -lsubunit -lm -lrt -lpthread
SYSTEM_NAME = $(shell uname -s)
GCOV = -fprofile-arcs -ftest-coverage
ifeq ($(SYSTEM_NAME), Darwin)
	OPEN_CMD = open
else 
	OPEN_CMD = xdg-open
endif

all: s21_math.a

test: s21_math.a
ifeq ($(SYSTEM_NAME), Darwin)
	$(CFLAGS) tests_s21_math.c -o test $(L)
else
	$(CFLAGS) tests_s21_math.c -o test $(L) $(UNI_F)
endif
	./test

gcov_report:
ifeq ($(SYSTEM_NAME), Darwin)
	$(CFLAGS) $(GCOV) tests_s21_math.c -o test $(L)
else
	$(CFLAGS) $(GCOV) tests_s21_math.c -o test $(L) $(UNI_F)
endif
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	$(OPEN_CMD) ./report/index.html

s21_math.a: clean
	$(CFLAGS) -c s21_*.c  extra.c
	ar rc libmath.a *.o
	ranlib libmath.a

style:
	clang-format -style=Google -n *.c *.h

clean:
	rm -rf *.a *.o test *.gcda *.gcno *.info report *.out


.PHONY: all clean test s21_math.a gcov_report style