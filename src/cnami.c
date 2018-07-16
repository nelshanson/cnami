#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(const float *a, const size_t n) {
  for (size_t i = 0; i < n-1; ++i) {
    fprintf(stdout, "%f,", a[i]);
  }
  fprintf(stdout, "%f\n", a[n-1]);
}

int main(int argc, char **argv) {
  const size_t im = 100;

  const float dt = 1.;
  const float dx = 1.;
  const float c = 1.; // phase speed

  float *u = calloc(im, sizeof(float));
  float *du = calloc(im, sizeof(float));
  
  return 0;
}
