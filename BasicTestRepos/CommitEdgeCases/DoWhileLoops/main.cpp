int dowhileloop_linebreakwhile() {
  int counter = 42;
  int lbw_sum = 0;
  do {
    lbw_sum += counter;
  }
  while (counter--);
  return lbw_sum;
}

int dowhileloop_linebreakbcond() {
  int counter = 42;
  int lbbc_sum = 0;
  {
    lbbc_sum += counter;
  } while
    (counter--);
  return lbbc_sum;
}

int dowhileloop_linebreakcond() {
  int counter = 42;
  int lbc_sum = 0;
  do  {
    lbc_sum += counter;
  } while (
    counter--);
  return lbc_sum;
}

int dowhileloop_normal() {
  int counter = 42;
  int normal_sum = 0;
  do {
    normal_sum += counter;
    } while (counter--);
  return normal_sum;
}

int dowhileloop_linebreaknobrack() {
  int counter = 42;
  int lbnb_sum = 0;
  {
    lbnb_sum += counter;}
  while (counter--) ;
  return lbnb_sum;
}

int main() {
}
