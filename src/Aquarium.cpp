#include "Aquarium.h"
#include <iostream>

Aquarium::Aquarium(const int number) : aquariumNumber(number) {}

int Aquarium::getNumber() const { return aquariumNumber; }

void Aquarium::addFish(std::unique_ptr<Fish> fish) {
  fishes.push_back(std::move(fish));
}
int Aquarium::getFishCount() const { return static_cast<int>(fishes.size()); }
Fish &Aquarium::getFish(const int index) const { return *fishes.at(index); }
const std::vector<std::unique_ptr<Fish>> &Aquarium::getFishes() const {
  return fishes;
}

void Aquarium::addWorker(std::unique_ptr<Worker> worker) {
  workers.push_back(std::move(worker));
}
int Aquarium::getWorkerCount() const {
  return static_cast<int>(workers.size());
}
Worker &Aquarium::getWorker(const int index) const {
  return *workers.at(index);
}
const std::vector<std::unique_ptr<Worker>> &Aquarium::getWorkers() const {
  return workers;
}

void Aquarium::feedFishByWorker(const Worker &worker) const {
  std::cout << "Worker " << worker.getName() << " is feeding fish in Aquarium "
            << aquariumNumber << "\n";
  for (auto &fish : fishes) {
    fish->increaseAppetite(1);
  }
}

void Aquarium::printInfo() const {
  std::cout << "\nAquarium " << aquariumNumber << "\n";
  std::cout << " Fish count: " << fishes.size() << "\n";
  std::cout << " Worker count: " << workers.size() << "\n";

  std::cout << " Fish list:\n";
  if (fishes.empty())
    std::cout << "  empty\n";
  else
    for (const auto &f : fishes)
      f->printInfo();

  std::cout << " Workers list:\n";
  if (workers.empty())
    std::cout << "  empty\n";
  else {
    for (size_t i = 0; i < workers.size(); ++i) {
      std::cout << "  [" << (i + 1) << "] ";
      workers[i]->printInfo();
    }
  }
}