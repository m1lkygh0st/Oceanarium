#ifndef SALMON_H
#define SALMON_H

#include "Fish.h"

/**
 * @class Salmon
 * @brief Рыба — лосось.
 */
class Salmon : public Fish {
public:
  Salmon(const int age, const std::string &gender, const int appetite,
         const int health)
      : Fish("Salmon", age, gender, appetite, health) {}
};

#endif