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

  [[nodiscard]] int getNumber() const;
  void addFish(std::unique_ptr<Fish> fish);
  [[nodiscard]] int getFishCount() const;
  [[nodiscard]] Fish &getFish(int index) const;
  [[nodiscard]] const std::vector<std::unique_ptr<Fish>> &getFishes() const;

  void addWorker(std::unique_ptr<Worker> worker);
  [[nodiscard]] int getWorkerCount() const;
  [[nodiscard]] Worker &getWorker(int index) const;
  [[nodiscard]] const std::vector<std::unique_ptr<Worker>> &getWorkers() const;

  void feedFishByWorker(const Worker &worker) const;

  void printInfo() const;
};

#endif