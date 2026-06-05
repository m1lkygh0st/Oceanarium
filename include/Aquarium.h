#ifndef AQUARIUM_H
#define AQUARIUM_H

#include <memory>
#include <vector>
#include "Fish.h"

class Aquarium {
    std::vector<std::unique_ptr<Fish>> fishes;
    int aquariumNumber;

public:
    explicit Aquarium(int number);
    int getNumber() const;
    void addFish(std::unique_ptr<Fish> fish);
    size_t getFishCount() const;
    const std::vector<std::unique_ptr<Fish>> &getFishes() const;
    void printInfo() const;
};

#endif
