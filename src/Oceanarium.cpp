#include "Oceanarium.h"
#include <stdexcept>

void Oceanarium::addAquarium(const Aquarium &aquarium) { aquariums.push_back(aquarium); }

int Oceanarium::getAquariumCount() const { return static_cast<int>(aquariums.size()); }

Aquarium &Oceanarium::getAquarium(const int index) {
  if (index < 0 || index >= getAquariumCount()) {
    throw std::runtime_error("Invalid aquarium index");
  }
  return aquariums[index];
}

const std::vector<Aquarium> &Oceanarium::getAquariums() const { return aquariums; }
