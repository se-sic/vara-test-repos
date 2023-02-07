#include <iostream>

struct A {
 int i;
 A(int i) : i(i) {};
};

int foo(A a) {
 return a.i;
}

int foo(int i) {
 return i - 1;
}

int main(int argc, char *argv[]) {
 std::cout << foo(argc);
}
