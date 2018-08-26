#include "rvect.h"
#include <stdio.h>
#include <stdlib.h>

rvect_t *rvect_new(const size_t n) {
  rvect_t *vec = malloc(sizeof(rvect_t));
  double *data = calloc(sizeof(double), n);

  *vec = (rvect_t) {.data=data, .len=n};
  return vec;
}

size_t rvect_free(rvect_t *vec) {
  size_t len = vec->len;
  free(vec->data);
  free(vec);
  return len;
}

void rvect_print(const rvect_t *vec) {
  fprintf(stdout, "[%f", vec->data[0]);
  for (size_t i = 1; i < vec->len; ++i) {
    fprintf(stdout, ", %f", vec->data[i]);
  }
  fprintf(stdout, "]\n");
}

void axpy(const double a, rvect_t *x, const rvect_t *y) {
  for (size_t i = 0; i < x->len; ++i) {
    x->data[i] = a*x->data[i] + y->data[i];
  }
}

void vect_sum(rvect_t *x, const rvect_t *y) {
  axpy(1, x, y);
}

void scal_add(const double a, rvect_t *x) {
  for (size_t i = 0; i < x->len; ++i) {
    x->data[i] += a;
  }
}

void scal_mult(const double a, rvect_t *x) {
  for (size_t i = 0; i < x->len; ++i) {
    x->data[i] *= a;
  }
}
