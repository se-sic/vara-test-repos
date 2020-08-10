#include "fire.h"
#include "water.h"

#include <iostream>

void handleElementalistStuff() {
  std::cout << "Try to cast fire thingy" << std::endl;
  cast_fire_bolt();
  std::cout << "I'm not done yet." << std::endl;

  std::cout << "Try to cast water stuff." << std::endl;
  cast_water_beam();
  std::cout << "Now I'm done." << std::endl;
}

int main(/* int argc, char *argv[] */) {
  // do stuff
  handleElementalistStuff();
  return 0;
}
