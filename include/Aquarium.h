#ifndef AQUARIUM_H
#define AQUARIUM_H

#include "Fish.h"
#include "Worker.h"
#include <memory>
#include <vector>

class Aquarium {
  int aquariumNumber;
  std::vector<std::unique_ptr<Fish>> fishes;
  std::vector<std::unique_ptr<Worker>> workers;

public:
  explicit Aquarium(int number);

  void addFish(std::unique_ptr<Fish> fish);
  void addWorker(std::unique_ptr<Worker> worker);
  [[nodiscard]] Fish &getFish(int index) const;
  [[nodiscard]] int getFishCount() const;
  [[nodiscard]] int getWorkerCount() const;
  [[nodiscard]] int getNumber() const;

  [[nodiscard]] Worker &getWorker(int index) const;

  void feedFishByWorker(const Worker &worker) const;
  void tickDay() const;
  void printInfo() const;
};

#endif