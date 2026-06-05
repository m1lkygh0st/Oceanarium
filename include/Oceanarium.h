#ifndef OCEANARIUM_H
#define OCEANARIUM_H

#include <memory>
#include <vector>
#include "Aquarium.h"

class Oceanarium {
  std::vector<std::unique_ptr<Aquarium>> aquariums;

public:
  void addAquarium(std::unique_ptr<Aquarium> aquarium);
  int getAquariumCount() const;
  Aquarium &getAquarium(int index) const;
  const std::vector<std::unique_ptr<Aquarium>> &getAquariums() const;
};

#endif
