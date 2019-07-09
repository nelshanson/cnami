#include <stdio.h>
#include <math.h>
#include "CnamiConfig.h"
#include "utils.h"


int main(int argc, char **argv) {
  
  const long im = 100;
  const long nm = 100;

  const double dt = 1.;
  const double dx = 1.;
  const double c = 1.;

  double du[im];
  double u[im];

  const long ipos = 25;
  const double decay = 0.02;

  for (size_t i = 0; i < im; ++i) {
    double x = (i - ipos + 1) * (i - ipos + 1);
    u[i] = exp(-decay * x);
  }

  print_array(u, im);

  for (size_t n = 0; n < nm; ++n) {
    du[0] = u[0] - u[im-1];

    for (size_t i = 1; i < im; ++i) {
      du[i] = u[i] - u[i-1];
    }

    for (size_t i = 0; i < im; ++i) {
      u[i] = u[i] - c * du[i] / dx * dt;
    }

    print_array(u, im);
  }

  return 0;
}
