#ifndef OCEANARIUM_H
#define OCEANARIUM_H

#include "Aquarium.h"
#include <memory>
#include <vector>

class Oceanarium {
  std::vector<std::unique_ptr<Aquarium>> aquariums;

public:
  void addAquarium(std::unique_ptr<Aquarium> aquarium);

  [[nodiscard]] int getAquariumCount() const;

  Aquarium &getAquarium(int index);
  [[nodiscard]] const Aquarium &getAquarium(int index) const;

  [[nodiscard]] const std::vector<std::unique_ptr<Aquarium>> &
  getAquariums() const;
};

#endif