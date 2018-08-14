#include "io_utils.h"
#include <stdio.h>
#include <stdlib.h>

void print_array(const float *a, const size_t n) {
  for (size_t i = 0; i < n-1; ++i) {
    fprintf(stdout, "%f,", a[i]);
  }
  fprintf(stdout, "%f\n", a[n-1]);
}
