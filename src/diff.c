#include "rvect.h"
#include "diff.h"

void diffpc(rvect_t *del, const rvect_t *x) {
  del->data[0] = 0.5*(x->data[1] - x->data[x->len-1]);
  del->data[del->len-1] = 0.5*(x->data[0] - x->data[x->len-2]);

  for (size_t i = 1; i < x->len-1; ++i) {
    del->data[i] = 0.5*(x->data[i+1] - x->data[i-1]);
  }
}
