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
  Fish(std::string species, int age, std::string gender, int appetite,
       int health);
  virtual ~Fish() = default;

  [[nodiscard]] const std::string &getSpecies() const;
  [[nodiscard]] int getAge() const;
  [[nodiscard]] const std::string &getGender() const;
  [[nodiscard]] int getAppetite() const;
  [[nodiscard]] int getHealth() const;
  [[nodiscard]] bool isAlive() const;

  void feed(int food);
  void tickDay();
  virtual void printInfo() const;
};

#endif