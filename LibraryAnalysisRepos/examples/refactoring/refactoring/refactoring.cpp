#include <iostream>

int foo(int i) {
 return i - 1;
}

int main(int argc, char *argv[]) {
 std::cout << foo(argc);
}
