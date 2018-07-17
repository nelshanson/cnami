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

void init_blob(float *a, const size_t n, const size_t ipos, const float decay) {
  for (size_t i = 0; i < n; ++i) {
    int offset = (int) (i - ipos);
    a[i] = exp(-decay * offset * offset);
  }
}

void compute_differences(const float *u, float *du, const size_t n) {
  du[0] = u[0] - u[n-1];
  for (size_t i = 1; i < n; ++i) {
    du[i] = u[i] - u[i-1];
  }
}

void update_position(
  float *u,
  const float *du,
  const size_t n,
  const float c,
  const float dx,
  const float dt)
{
  for (size_t i = 0; i < n; ++i) {
    u[i] = u[i] - c * du[i] / dx * dt;
  }
}

int main(int argc, char **argv) {
  const size_t im = 100;

  const float dt = 1.;
  const float dx = 1.;
  const float c = 1.; // phase speed

  float *u = calloc(im, sizeof(float));
  float *du = calloc(im, sizeof(float));

  init_blob(u, im, 24, 0.02);
  print_array(u, im);

  // Time loop...
  const int nm = 100;
  for (int i = 0; i < nm; ++i) {
    compute_differences(u, du, im);
    update_position(u, du, im, c, dx, dt);
    print_array(u, im);
  }

  return 0;
}
