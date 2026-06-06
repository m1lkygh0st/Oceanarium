#pragma once
#include <atomic>
#include <memory>
#include <thread>
#include <vector>

#include "Aquarium.h"

class Oceanarium {
  std::vector<std::unique_ptr<Aquarium>> aquariums;

  std::thread timeThread;
  std::atomic<bool> running{false};

  void timeLoop() const;

public:
  void addAquarium(std::unique_ptr<Aquarium> aquarium);

  [[nodiscard]] int getAquariumCount() const;
  [[nodiscard]] Aquarium &getAquarium(int index) const;

  void startSimulation();
  void stopSimulation();

  ~Oceanarium();
};