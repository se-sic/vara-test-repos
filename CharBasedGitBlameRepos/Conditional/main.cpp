#include <stdio.h>

float conditional_declaration(int x) {
  if (float result = x * 2) {
    return result;
  }
  return 0;
}

bool conditional_function(int x, int y) {
  if (x <= y) {
    return true;
  }
  return false;
}

int main() {
  return 0;
}
