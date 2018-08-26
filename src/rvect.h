#pragma once
#include <stdlib.h>

typedef struct {
  double *data;
  size_t len;
} rvect_t;

/**
 * Allocate a new rvect_t on the heap with a data array
 * initialized to zeros.
 * @param size_t n The length of the desired vector.
 * @return rvect_t* A pointer to the newly allocated rvect_t structure.
 *   Or NULL on failure.
 */
rvect_t *rvect_new(const size_t n);

/**
 *
 */
size_t rvect_free(rvect_t *vec);

void rvect_print(const rvect_t *vec);
void axpy(const double a, rvect_t *x, const rvect_t *y);
void vect_sum(rvect_t *x, const rvect_t *y);
void scal_add(const double a, rvect_t *x);
void scal_mult(const double a, rvect_t *x);
