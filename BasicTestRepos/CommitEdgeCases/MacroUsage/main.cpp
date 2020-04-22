#define multi_line(a, b, c) (a) \
    + (b) \
    + (c)

#define doCalc(a, b) (a) + (b)

int single_macro(int a, int b) {
  return doCalc(a, b);
}

int multi_macro(int a, int b, int c) {
  return multi_line(a, b, c);
}

int main() {
}
