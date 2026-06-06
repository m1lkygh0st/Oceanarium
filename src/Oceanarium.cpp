#include "Oceanarium.h"
#include <chrono>
#include <iostream>

void Oceanarium::addAquarium(std::unique_ptr<Aquarium> aquarium) {
  aquariums.push_back(std::move(aquarium));
}

int Oceanarium::getAquariumCount() const {
  return static_cast<int>(aquariums.size());
}

Aquarium &Oceanarium::getAquarium(const int index) const {
  return *aquariums.at(index);
}

void Oceanarium::startSimulation() {
  if (running)
    return;

  running = true;
  timeThread = std::thread(&Oceanarium::timeLoop, this);
}

void Oceanarium::stopSimulation() {
  running = false;

  if (timeThread.joinable())
    timeThread.join();
}

Oceanarium::~Oceanarium() { stopSimulation(); }

void Oceanarium::timeLoop() const {
  using namespace std::chrono_literals;

  while (running) {
    std::this_thread::sleep_for(10s);

    for (auto &aq : aquariums) {
      aq->tickDay();
    }

    std::cout << "\n[SIMULATION] 10 seconds passed: fish appetite decreased!\n";
  }
}