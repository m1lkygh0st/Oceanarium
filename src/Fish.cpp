#include "Fish.h"
#include <iostream>

Fish::Fish(std::string species, const int age, std::string gender,
           const int appetite, const int health)
    : species(std::move(species)), age(age), gender(std::move(gender)),
      appetite(appetite), health(health), alive(true) {}

const std::string &Fish::getSpecies() const { return species; }
int Fish::getAge() const { return age; }
const std::string &Fish::getGender() const { return gender; }
int Fish::getAppetite() const { return appetite; }
int Fish::getHealth() const { return health; }
bool Fish::isAlive() const { return alive; }

void Fish::feed(const int food) {
  if (!alive)
    return;
  appetite += food;
  if (appetite > 100)
    appetite = 100;
}

void Fish::tickDay() {
  if (!alive)
    return;

  appetite -= 1;
  if (appetite <= 0) {
    appetite = 0;
    health -= 5;
  }
  if (health <= 0) {
    health = 0;
    alive = false;
  }
}

void Fish::printInfo() const {
  std::cout << "Species: " << species << " | Age: " << age
            << " | Gender: " << gender << " | Appetite: " << appetite
            << " | Health: " << health
            << " | Status: " << (alive ? "ALIVE" : "DEAD") << "\n";
}