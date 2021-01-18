#include <stdio.h>

int sum(int a, int b) { return a + b; }

int doStuff(int a, int b) { return a * b; }

int main() {
  printf("The answer is: %d\n", sum(22, 20));

  printf("Another option: %d", doStuff(21, 2));
}
