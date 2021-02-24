#include "fire.h"
#include "water.h"
#include "earth.h"

#include <iostream>

std::string get_shout(std::string shout) { return shout; }

void handle_elementalist_stuff() {
  std::cout << get_shout("Casting fire thingy!") << std::endl;
  std::cout << get_fire_spell() << std::endl;
  std::cout << "I'm not done yet." << std::endl;

  std::cout << get_shout("Casting water stuff!") << std::endl;
  std::cout << get_water_spell() << std::endl;
  std::cout << "Now I'm done." << std::endl;

  std::cout << get_shout("Tricked ya! Still casting water stuff!") << std::endl;
  std::cout << get_water_spell() << std::endl;
  std::cout << get_shout("Guess what comes next...") << std::endl;

  std::cout << get_fire_spell() << std::endl;
  std::cout << "All mana consumed." << std::endl;

  std::cout << get_shout("Drinking mana potion!") << std::endl;
  std::cout << get_earth_spell() << std::endl;
  std::cout << get_shout("Fin") << std::endl;
}

int main(/* int argc, char *argv[] */) {
  // do stuff
  handle_elementalist_stuff();
  return 0;
}
