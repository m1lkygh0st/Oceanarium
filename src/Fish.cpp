#include "Fish.h"
#include <iostream>

Fish::Fish(std::string species, const int age, std::string gender,
           const int appetite, const int health)
    : species(std::move(species)), age(age), gender(std::move(gender)),
      appetite(appetite), health(health), alive(true) {}

std::string Fish::getSpecies() const { return species; }
int Fish::getAge() const { return age; }
std::string Fish::getGender() const { return gender; }
int Fish::getAppetite() const { return appetite; }
int Fish::getHealth() const { return health; }
bool Fish::isAlive() const { return alive; }

void Fish::increaseAppetite(const int value) {
  if (alive) {
    appetite += value;
  }
}

void Fish::decreaseHealth(const int value) {
  if (!alive) {
    return;
  }
  health -= value;
  if (health <= 0) {
    alive = false;
  }
}

void Fish::kill() { alive = false; }

void Fish::printInfo() const {
  std::cout << "  Species: " << species << " | Age: " << age
            << " | Gender: " << gender << " | Appetite: " << appetite
            << " | Health: " << health
            << " | Status: " << (alive ? "LIVE" : "DEAD") << "\n";
}