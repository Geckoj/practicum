#include "eq.h"
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double round_n(double input, int n) {
  double scale = pow(10, n);
  return round(input * scale) / scale;
}

double *calc_equation(double a, double b, double c, int *roots_size,
                      int tochnost) {

  double *roots = NULL;

  double EPSILON = pow(10, -tochnost);
  if (tochnost == 0) {
    EPSILON = 0;
  }

  if (b > 0) {
    a = -a;
    b = -b;
    c = -c;
  }

  *roots_size = 0;

  double d = (b * b) - (4 * a * c);
  double sd = sqrt(d);
  // printf("%.10f\t%.10f\n", d, sd);

  if (fabs(d) < EPSILON) {
    sd = 0;
  }

  // printf("%.10f\t%.10f\n", d, sd);

  if (d > EPSILON) {
    roots = (double *)malloc(2 * sizeof(double));
    *roots_size = 2;

    double x1 = round_n(((-b + sd) / (2 * a)), tochnost);
    double x2 = round_n((c / (a * x1)), tochnost);

    roots[0] = fmin(x1, x2);
    roots[1] = fmax(x1, x2);
    // printf("DVA %.11f\t%.11f\n", roots[0], roots[1]);

    return roots;
  } else if (fabs(d) <= EPSILON) {
    roots = (double *)malloc(1 * sizeof(double));
    *roots_size = 1;

    roots[0] = round_n(((-b + sd) / (2 * a)), tochnost);
    // printf("%f\n", roots[0]);

    return roots;
  } else {
    return NULL;
  }
}