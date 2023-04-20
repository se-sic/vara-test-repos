#include <stdio.h>

namespace my_namespace {
  int x = 42;
}

using namespace my_namespace; 

int main() {
  printf("%d", x);
}
