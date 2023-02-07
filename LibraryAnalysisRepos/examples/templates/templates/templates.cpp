#include <iostream>

template<typename T>
T foo() {
 return 1;
}

template<>
int foo<int>() {
 return 0;
}

int main() {
 std::cout << foo<int>();
}
