#include "fraction.h"

#include <iostream>


int divide() {
  int n = libfraction::get_n();
  int d = libfraction::get_d();
  return n / d;
}

int main() {
  int n = 42;
  libfraction::init(n);
  std::cout << divide();
  return 0;
}
