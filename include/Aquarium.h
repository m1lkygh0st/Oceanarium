#ifndef AQUARIUM_H
#define AQUARIUM_H

class Aquarium {
  int fishCount;

public:
  Aquarium();

  void addFish(int count);
  int getFishCount() const;
};

#endif
