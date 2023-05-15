#include "feature_util.h"

int main(int argc, char** argv) {
  bool __attribute__((feature_variable("FeatureA"))) FeatureA = false;
  bool __attribute__((feature_variable("FeatureB"))) FeatureB = false;

  if (fpcsc::isFeatureEnabled(argc, argv, std::string("--A"))) {
    FeatureA = true;
  }

  if (fpcsc::isFeatureEnabled(argc, argv, std::string("--B"))) {
    FeatureB = true;
  }
  if (FeatureA) {
    fpcsc::sleep_for_secs(5);
  } else {
    fpcsc::sleep_for_secs(3);
  }
  if (FeatureB) {
    fpcsc::sleep_for_secs(7);
  } else {
    fpcsc::sleep_for_secs(4);
  }
  if (FeatureA && FeatureB) {
    fpcsc::sleep_for_secs(12);
  } else {
    fpcsc::sleep_for_secs(2);
  }
}
