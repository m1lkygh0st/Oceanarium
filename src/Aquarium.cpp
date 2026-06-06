#include "Aquarium.h"
#include <iostream>

Aquarium::Aquarium(int number) : aquariumNumber(number) {}

void Aquarium::addFish(std::unique_ptr<Fish> fish) {
  fishes.push_back(std::move(fish));
}

void Aquarium::addWorker(std::unique_ptr<Worker> worker) {
  workers.push_back(std::move(worker));
}

int Aquarium::getFishCount() const { return static_cast<int>(fishes.size()); }
int Aquarium::getWorkerCount() const {
  return static_cast<int>(workers.size());
}
int Aquarium::getNumber() const { return aquariumNumber; }

Fish &Aquarium::getFish(const int index) const { return *fishes.at(index); }
Worker &Aquarium::getWorker(const int index) const {
  return *workers.at(index);
}

void Aquarium::feedFishByWorker(const Worker &worker) const {
  if (!worker.isActive())
    return;
  for (auto &fish : fishes) {
    fish->feed(15);
  }
}

void Aquarium::tickDay() const {
  for (auto &fish : fishes) {
    fish->tickDay();
  }
  for (auto &worker : workers) {
    worker->tickDay();
  }
}

void Aquarium::printInfo() const {
  std::cout << "\nAquarium #" << aquariumNumber << "\n";

  std::cout << "Fishes:\n";
  for (const auto &f : fishes) {
    f->printInfo();
  }

  std::cout << "Workers:\n";
  for (const auto &w : workers) {
    w->printInfo();
  }
}