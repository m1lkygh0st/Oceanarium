#ifndef CARDINALFISH_H
#define CARDINALFISH_H

#include "Fish.h"

class Cardinalfish : public Fish {
public:
  Cardinalfish(const int age, const std::string &gender, const int appetite,
               const int health)
      : Fish("Cardinalfish", age, gender, appetite, health) {}
};

#endif
