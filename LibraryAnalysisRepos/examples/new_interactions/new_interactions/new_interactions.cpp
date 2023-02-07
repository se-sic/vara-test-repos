#include <iostream>

struct A {
 virtual int foo() {
  return 1;
 }
};

int bar(int i) {
 return i + 1;
}

struct B : public A {
 int foo() override {
  int i = 0;
  return bar(i);
 }
};

int main() {
 A *a = new B();
 std::cout << a->foo();
}

