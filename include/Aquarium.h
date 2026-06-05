#ifndef AQUARIUM_H
#define AQUARIUM_H

#include <memory>
#include <vector>

#include "Fish.h"
#include "Worker.h"

class Aquarium {
    int aquariumNumber;
    std::vector<std::unique_ptr<Fish>> fishes;
    std::vector<Worker> workers;

public:
    explicit Aquarium(int number);

    int getNumber() const;
    void addFish(std::unique_ptr<Fish> fish);
    int getFishCount() const;

    Fish &getFish(int index) const;
    const std::vector<std::unique_ptr<Fish>> &getFishes() const;

    void addWorker(const Worker &worker);
    int getWorkerCount() const;
    Worker &getWorker(int index);
    const std::vector<Worker> &getWorkers() const;

    void feedFishByWorker(const Worker &worker) const;

    void printInfo() const;
};

#endif
