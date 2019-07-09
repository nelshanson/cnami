#include "utils.h"

void print_array(const double* arr, const size_t n) {
  for (size_t i = 0; i < n-1; ++i) {
    printf("%f ", arr[i]);
  }
  printf("%f\n", arr[n-1]);
}