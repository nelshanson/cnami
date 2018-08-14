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
