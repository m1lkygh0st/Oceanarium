#include "Aquarium.h"
#include <stdexcept>

Aquarium::Aquarium() : fishCount(0) {}

void Aquarium::addFish(const int count) {
  if (count <= 0) {
    throw std::runtime_error("Fish count should be positive");
  }
  fishCount += count;
}

int Aquarium::getFishCount() const { return fishCount; }
