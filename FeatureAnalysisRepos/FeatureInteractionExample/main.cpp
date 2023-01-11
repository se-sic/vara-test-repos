#include "feature_util.h"

int main(int argc, char** argv) {
  bool __attribute__((feature_variable("Foo"))) Foo = false;
  bool __attribute__((feature_variable("Bar"))) Bar = false;

  if (fpcsc::isFeatureEnabled(argc, argv, std::string("--foo"))) {
    Foo = true;
  }

  if (fpcsc::isFeatureEnabled(argc, argv, std::string("--bar"))) {
    Bar = true;
  }

  if (Foo) {
    fpcsc::sleep_for_secs(13);
  } else {
    fpcsc::sleep_for_secs(3);
  }

  fpcsc::sleep_for_secs(2); // General waiting time

  if (Bar) {
    fpcsc::sleep_for_secs(3);
  } else {
    fpcsc::sleep_for_secs(1);
  }

  fpcsc::sleep_for_secs(2); // General waiting time

  if (Foo && Bar) {
    fpcsc::sleep_for_secs(6);
  }

  return 0;
}
