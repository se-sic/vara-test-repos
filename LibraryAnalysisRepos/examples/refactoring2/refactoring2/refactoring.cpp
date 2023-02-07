#include <iostream>

int baz() {
 return 1;
}

int foo(int i) {
 return i - baz();
}

int main(int argc, char *argv[]) {
 std::cout << foo(argc);
}
