#ifndef ANGELFISH_H
#define ANGELFISH_H

#include "Fish.h"

class Angelfish : public Fish {
public:
  Angelfish(const int age, const std::string &gender, const int appetite, const int health) :
      Fish("Angelfish", age, gender, appetite, health) {}
};

#endif
