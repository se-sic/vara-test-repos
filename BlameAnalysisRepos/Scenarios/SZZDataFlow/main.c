#include <stdio.h>

int x = 42;
int y = 1337;

int min(int x, int y) {
  if (x <= y) {
    return x;
  }
  return y;
}

int max(int x, int y) {
  if (x >= y) {
    return x;
  }
  return y;
}

int main() {
  int a = max(x, y);
  if (a < 0) {
    printf("Both numbers are negative.");
  }
  return 0;
}
          
