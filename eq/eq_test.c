#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "eq.h"

int main() {
  //   printf("%f\t%f", calc_equation(1, 0, -1)[0], calc_equation(1, 0, -1)[1]);

  double *res = calc_equation(1, 0, -1);

  for (int i = 0; i <= (sizeof(res) / sizeof(res[0])); i++) {
    printf("%f\t", res[i]);
  }
  printf("\n");

  return 0;
}