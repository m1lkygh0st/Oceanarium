#ifndef BUTTERFLYFISH_H
#define BUTTERFLYFISH_H

#include "Fish.h"

class Butterflyfish : public Fish {
public:
  Butterflyfish(const int age, const std::string &gender, const int appetite,
                const int health)
      : Fish("Butterflyfish", age, gender, appetite, health) {}
};

#endif
