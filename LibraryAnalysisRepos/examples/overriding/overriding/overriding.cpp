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

int main() {
 A *a = new B();
 std::cout << a->foo();
}
