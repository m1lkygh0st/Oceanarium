#ifndef OCEANARIUM_H
#define OCEANARIUM_H

#include <vector>
#include "Aquarium.h"


class Oceanarium {
  std::vector<Aquarium> aquariums;

public:
  void addAquarium(const Aquarium &aquarium);
  int getAquariumCount() const;
  Aquarium &getAquarium(int index);
  const std::vector<Aquarium> &getAquariums() const;
};

#endif
