#include <stdio.h>

int add(int A, int B) {
  return A + B;
}

int sub(int A, int B) {
  return A - B;
}

int main() {
  printf("Answer: %d", add(sub(80, 40), 2));
}
