#include <stdio.h>

int centralFunction(int i) {
  return i + i;
}

int usesCentralFunction1() {
  int i = 1;
  return centralFunction(i);
}

int usesCentralFunction2() {
  return centralFunction(2);
}

int usesCentralFunction3() {
  return centralFunction(3);
}

int usesCentralFunction4() {
  return centralFunction(4);
}

int usesCentralFunction5() {
  return centralFunction(5);
}

int usesCentralFunction6() {
  return centralFunction(6);
}

int main() {
  printf("%i\n", usesCentralFunction1());
  printf("%i\n", usesCentralFunction2());
  printf("%i\n", usesCentralFunction3());
  printf("%i\n", usesCentralFunction4());
  printf("%i\n", usesCentralFunction5());
  printf("%i\n", usesCentralFunction6());
  return 0;
}
          
