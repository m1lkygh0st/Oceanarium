#include "Aquarium.h"

void Aquarium::addFish(const Fish &fish) { fishes.push_back(fish); }

int Aquarium::getFishCount() const { return static_cast<int>(fishes.size()); }

const std::vector<Fish> &Aquarium::getFishes() const { return fishes; }
