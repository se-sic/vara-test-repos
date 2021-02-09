#include <stdio.h>

int add1(int i) {
  return i + 1;
}

int add2(int i) {
  return add1(i) + 1;
}

int add3(int i) {
  return add2(i) + 1;
}

int add4(int i) {
  return add3(i) + 1;
}

int add5(int i) {
  return add4(i) + 1;
}

int main() {
  printf("%d\n", add5(42));
  return 0;
}
