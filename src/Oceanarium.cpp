#include "Oceanarium.h"
#include <chrono>

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

void Oceanarium::timeLoop() {
  using namespace std::chrono_literals;

  while (running) {
    std::this_thread::sleep_for(10s);

    for (auto &aquarium : aquariums) {
      aquarium->tickDay();
    }

    for (const auto &aquarium : aquariums) {
      for (int i = 0; i < aquarium->getWorkerCount(); ++i) {
        aquarium->getWorker(i).printInfo();
      }
    }
  }
}