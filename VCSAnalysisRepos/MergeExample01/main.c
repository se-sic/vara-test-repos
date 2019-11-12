#include <stdio.h>

int sub(int a, int b) {
  return a - b;
}

int sum(int a, int b) { return a + b; }

int doStuff(int a, int b) { return a * b; }

int main() {
  printf("The answer is: %d\n", sum(22, sub(22, 2)));

  printf("Another option: %d", doStuff(21, 2));
}
