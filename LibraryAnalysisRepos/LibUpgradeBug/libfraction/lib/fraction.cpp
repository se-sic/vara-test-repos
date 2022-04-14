#include "fraction.h"

namespace libfraction {
int global_n;
int global_d = 1;

void init(int n, int d) {
  global_n = n;
  global_d = d;
}

int get_n() { return global_n; }

int get_d() { return global_d; }
}  // namespace libfraction
