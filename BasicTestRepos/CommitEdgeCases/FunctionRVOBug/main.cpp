#include <string>
int g;
void funcWithoutInput() { g = 42; }
std::string funcOnlyReturn() { return "21"; }
int main() {
  std::string localVar;
  funcWithoutInput();
  localVar = "1337";
  localVar = funcOnlyReturn();
  return localVar.size();
}
