#include <stdbool.h>

bool somePredicate();

int main(/* int argc, char *argv[] */) {
  int i = 10;
  int j = 46;
  int *ptr;
  if (somePredicate()) {
    ptr = &i;
  } else {
    ptr = &j;
  }
  *ptr = 25;
  return i;
}
