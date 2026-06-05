#ifndef FISH_H
#define FISH_H

#include <string>

class Fish {
protected:
  std::string species;
  int age;
  std::string gender;
  int appetite;
  int health;

  bool alive;

public:
  Fish(std::string species, int age, std::string gender, int appetite, int health);

  std::string getSpecies() const;
  int getAge() const;
  std::string getGender() const;
  int getAppetite() const;
  int getHealth() const;

  bool isAlive() const;

  virtual void printInfo() const;
  virtual ~Fish() = default;
};

#endif
