int contextDependentFunction(int Val) {
  return Val + 42;
}
int contextOne() {
  int contextValue = 10;
  int returnValue = contextDependentFunction(contextValue);
  return returnValue;
}
int contextTwo() {
  int contextValue2 = 12;
  int returnValue = contextDependentFunction(contextValue2);
  return returnValue;
}
int main() {
  return contextOne() + contextTwo();
}
