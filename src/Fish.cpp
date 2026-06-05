#include <utility>

#include "Fish.h"

Fish::Fish(std::string species, const int age, std::string gender, const int appetite, const int health) :
    species(std::move(species)), age(age), gender(std::move(gender)), appetite(appetite), health(health) {}

std::string Fish::getSpecies() const { return species; }
int Fish::getAge() const { return age; }
std::string Fish::getGender() const { return gender; }
int Fish::getAppetite() const { return appetite; }
int Fish::getHealth() const { return health; }
