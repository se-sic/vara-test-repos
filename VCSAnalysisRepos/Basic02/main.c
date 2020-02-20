bool somePredicate();

int main(/* int argc, char *argv[] */) {
  int i;
  if (somePredicate()) {
    i = 200;
  } else {
    i = 500;
  }
  int j = i * 2;
  return j;
}
