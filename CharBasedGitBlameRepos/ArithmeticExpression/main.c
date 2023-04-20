#include <stdio.h>

int calculate_something(int x) {
  int result;
  result = x + 42 - 1;
  return result;
}

int main() {
  printf("%d", calculate_something(4));
}
