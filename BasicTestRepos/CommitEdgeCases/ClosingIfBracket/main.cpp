#include <cstdio>

int main() {
  bool Cond = false;
  bool Cond1 = false;
  bool Cond2 = false;
  bool Cond3 = false;
  bool Cond4 = false;
  if (Cond) {
    puts("42");
  }

  if (Cond1)
  { puts("42");
  }

  if (Cond2) {
    puts("42"); };

  if (Cond3) {
    puts("42");
  } else { // Cond3
    puts("42");
  }

  if (Cond4) {
  } else { // Cond4
    puts("42"); }
}
