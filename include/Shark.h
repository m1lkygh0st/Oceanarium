#ifndef SHARK_H
#define SHARK_H

#include "Fish.h"

/**
 * @class Shark
 * @brief Рыба — акула.
 */
class Shark : public Fish {
public:
  Shark(const int age, const std::string &gender, const int appetite,
        const int health)
      : Fish("Shark", age, gender, appetite, health) {}
};

#endif