#include <stdio.h>

class Foo {
  int value;
public:
  Foo(int param) : value(param) {
    setVal();
  };

  int getVal() { return value; };
  void setVal() { value = 42; };
};

int main() {
  Foo* fooA = new Foo(21);
  Foo fooA2 = *fooA;
  Foo* fooB = new Foo(42);
  fooB->getVal();
  return 0;
}
