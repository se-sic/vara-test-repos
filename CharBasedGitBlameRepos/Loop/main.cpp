#include <stdio.h>

int enhanced_loop() {
  int numbers[] = {1, 2, 3, 4};
  int result = 0;
  for (int element : numbers) {
    result += element;
  }
  return result;
}

int loop_function() {
  int result = 0;
  for (int count = 0; count < 4; count++) {
    result += count;
  }
  return result;
}

int main() {
  return 0;
}
