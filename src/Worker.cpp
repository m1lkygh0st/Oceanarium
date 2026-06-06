#include "Worker.h"
#include <iostream>

Worker::Worker(std::string name, const int age, std::string gender)
    : name(std::move(name)), age(age), gender(std::move(gender)), active(true),
      unavailableDays(0) {}

const std::string &Worker::getName() const { return name; }
int Worker::getAge() const { return age; }
const std::string &Worker::getGender() const { return gender; }
bool Worker::isActive() const { return active; }

void Worker::setActive(const bool status) { active = status; }

void Worker::setUnavailableDays(const int days) {
  unavailableDays = days;
  active = (days == 0);
}

int Worker::getUnavailableDays() const { return unavailableDays; }

void Worker::tickDay() {
  if (unavailableDays > 0) {
    unavailableDays--;
    if (unavailableDays == 0)
      active = true;
  }
}

void Worker::feed() const {
  if (!active) {
    std::cout << "Worker " << name << " is inactive.\n";
    return;
  }
  std::cout << "Worker " << name << " is feeding fishes.\n";
}

void Worker::printInfo() const {
  std::cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender
            << ", Status: " << (active ? "Active" : "Inactive")
            << ", Break days left: " << unavailableDays << '\n';
}