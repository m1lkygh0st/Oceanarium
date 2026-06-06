#include "Oceanarium.h"
#include <stdexcept>

void Oceanarium::addAquarium(std::unique_ptr<Aquarium> aquarium) {
  aquariums.push_back(std::move(aquarium));
}

int Oceanarium::getAquariumCount() const {
  return static_cast<int>(aquariums.size());
}

Aquarium &Oceanarium::getAquarium(const int index) {
  if (index < 0 || index >= getAquariumCount())
    throw std::out_of_range("Invalid aquarium index");

  return *aquariums.at(index);
}

const Aquarium &Oceanarium::getAquarium(const int index) const {
  if (index < 0 || index >= getAquariumCount())
    throw std::out_of_range("Invalid aquarium index");

  return *aquariums.at(index);
}

const std::vector<std::unique_ptr<Aquarium>> &Oceanarium::getAquariums() const {
  return aquariums;
}