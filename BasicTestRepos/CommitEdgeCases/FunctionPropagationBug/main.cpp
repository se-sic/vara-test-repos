int g;
void funcWithoutInput() { g = 42; }
int funcOnlyReturn() { return 21; }
int main() {
  int localVar;
  funcWithoutInput();
  localVar = 1337;
  localVar = funcOnlyReturn();
  return localVar;
}
