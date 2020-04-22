int whileloop_normal() {
  int counter = 42;
  int normal_sum = 0;
  while (counter--) {
    normal_sum += counter;
  }
  return normal_sum;
}

int whileloop_linebreak() {
  int counter = 42;
  int lb_sum = 0;
  while
    (counter--) {
    lb_sum += counter;
  }
  return lb_sum;
}

int whileloop_innerlinebreak() {
  int counter = 42;
  int ilb_sum = 0;
  while (
    counter--) {
    ilb_sum += counter;
  }
  return ilb_sum;
}

int whileloop_bodylinebreak() {
  int counter = 42;
  int blb_sum = 0;
  while (counter--)
  {
    blb_sum += counter;
  }
  return blb_sum;
}

int whileloop_endnolinebreak() {
  int counter = 42;
  int enlb_sum = 0;
  while (counter--) {
    enlb_sum += counter;}
  return enlb_sum;
}

int main() {
}
