#include <iostream>

struct A {
 virtual int foo() {
  return 1;
 }
};

struct B : public A {
 int foo() override {
  return 0;
 }
};

int bar(A *a) {
 return a->foo();
}

int main() {
 A *a = new B();
 std::cout << bar(a);
}
