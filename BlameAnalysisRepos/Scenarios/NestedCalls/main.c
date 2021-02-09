#include <stdio.h>

void print0(int a) {
  printf(a);
}

void print1(int a) {
  print0(a);
}

void print2(int a) {
  print1(a);
}

void print3(int a) {
  print2(a);
}

void print4(int a) {
  print3(a);
}

void print5(int a) {
  print4(a);
}

int main() {
  print5(42);
}
