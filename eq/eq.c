#include "eq.h"
#include <math.h>
#include <stdio.h>

double *calc_equation(double a, double b, double c) {
  double *roots = NULL;

  double d = b * b - 4 * a * c;
  if (d > 0) {
    roots = (double *)malloc(2 * sizeof(double));
    double x1 = (-b + sqrt(d)) / (2 * a);
    double x2 = (-b - sqrt(d)) / (2 * a);
    roots[0] = fmin(x1, x2);
    roots[1] = fmax(x1, x2);

  } else if (d == 0) {
    roots = (double *)malloc(sizeof(double));
    roots[0] = (-b) / (2 * a);
  }
  return roots;
}