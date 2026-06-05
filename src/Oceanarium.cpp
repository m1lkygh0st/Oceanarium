#include "Oceanarium.h"
#include <stdexcept>

void Oceanarium::addAquarium(std::unique_ptr<Aquarium> aquarium) { aquariums.push_back(std::move(aquarium)); }
int Oceanarium::getAquariumCount() const { return static_cast<int>(aquariums.size()); }

Aquarium &Oceanarium::getAquarium(const int index) const {
  if (index < 0 || index >= getAquariumCount())
    throw std::runtime_error("Invalid aquarium index");
  return *aquariums[index];
}

const std::vector<std::unique_ptr<Aquarium>> &Oceanarium::getAquariums() const { return aquariums; }
