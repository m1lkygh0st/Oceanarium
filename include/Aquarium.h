#ifndef AQUARIUM_H
#define AQUARIUM_H

#include <vector>
#include "Fish.h"

class Aquarium {
    std::vector<Fish> fishes;

public:
    void addFish(const Fish &fish);
    int getFishCount() const;
    const std::vector<Fish> &getFishes() const;
};

#endif
