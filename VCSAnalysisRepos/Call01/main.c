int id(int x) {
  return x;
}

int unaryOperation(int x) {
  return x * 3;
}

int main() {
  int i = 13;
  int j = id(i);
  int k = j * 2;
  k = unaryOperation(k);
  return k;
}
