#include "Aquarium.h"
#include <iostream>

Aquarium::Aquarium(const int number) : aquariumNumber(number) {}
int Aquarium::getNumber() const { return aquariumNumber; }
void Aquarium::addFish(std::unique_ptr<Fish> fish) { fishes.push_back(std::move(fish)); }
size_t Aquarium::getFishCount() const { return fishes.size(); }
const std::vector<std::unique_ptr<Fish>> &Aquarium::getFishes() const { return fishes; }

void Aquarium::printInfo() const {
  std::cout << "Aquarium " << aquariumNumber << " - " << fishes.size() << " fish\n";
  for (const auto &fish: fishes) {
    fish->printInfo();
  }
}
