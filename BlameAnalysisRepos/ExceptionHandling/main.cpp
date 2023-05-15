struct MyInt {
  int value;

  explicit MyInt(int value) : value(value) {}

  MyInt& operator=(const MyInt &other) {
    this->value = other.value;
    return *this;
  }
};

MyInt funcA() throw() { return MyInt(42); }
MyInt funcB() throw() { return MyInt(21); }

int main() {
  MyInt i(7);

  try {
    if (i.value > 0) {
      i = funcA();
    } else {
      i = funcB();
    }
  } catch (...) {
    return i.value;
  }

  return i.value;
}
