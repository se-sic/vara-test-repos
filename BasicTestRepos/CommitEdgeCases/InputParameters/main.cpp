void inputPtrParam(int *ip) {
    *ip = 42;
}
void inputRefParam(int &ir) {
    ir = 42;
}
void noInputParam(int i) {
    i = 42;
}
int main() {
  int VarI;
  noInputParam(VarI);

  int VarIR;
  inputRefParam(VarIR);

  int VarIP;
  inputPtrParam(&VarIP);
}
