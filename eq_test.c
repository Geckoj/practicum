#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "eq.h"

int main() {
  test_1();
  test_2();
  test_3();
  test_4();
  test_5();
  test_6();
  return 0;
}

void test_1() {
  int roots_size = 0;
  double *roots = calc_equation(1, 0, -1, &roots_size, 0);
  assert(roots[0] == -1);
  assert(roots[1] == 1);
  assert(roots_size == 2);
  printf("test 1 passed\n");
}

void test_2() {
  int roots_size = 0;
  double *roots = calc_equation(1, 0, 0, &roots_size, 0);
  assert(roots[0] == 0);
  assert(roots_size == 1);
  printf("test 2 passed\n");
}

void test_3() {
  int roots_size = 0;
  double *roots = calc_equation(1, 0, 1, &roots_size, 0);
  assert(roots_size == 0);
  printf("test 3 passed\n");
}

void test_4() {
  int roots_size = 0;
  double *roots = calc_equation(1, 0, -1E-7, &roots_size, 10);
  assert(fabs(roots[0] - (-3E-4)) < 1E-4);
  assert(fabs(roots[1] - (3E-4)) < 1E-4);
  assert(roots_size == 2);
  printf("test 4 passed\n");
}

void test_5() {
  int roots_size = 0;
  double *roots = calc_equation(1, -1E+10, -1, &roots_size, 11);
  assert(fabs(roots[0] - (-1E-10)) < 1E-11);
  assert(fabs(roots[1] - (1E+10)) < 1E-11);
  assert(roots_size == 2);
  printf("test 5 passed\n");
}

void test_6() {
  int roots_size = 0;
  double *roots = calc_equation(1, 0, -1E-8, &roots_size, 7);
  assert(fabs(roots[0] - 0) < 1E-7);
  assert(roots_size == 1);
  printf("test 6 passed\n");
}