#include "Worker.h"
#include <iostream>
Worker::Worker(std::string name, const int age, std::string gender)
    : name(std::move(name)), age(age), gender(std::move(gender)), active(true),
      breakDays(0) {}

const std::string &Worker::getName() const { return name; }
int Worker::getAge() const { return age; }
const std::string &Worker::getGender() const { return gender; }
bool Worker::isActive() const { return active; }

void Worker::setActive(const bool status) { active = status; }

void Worker::setBreak(const int days) {
  breakDays = days;
  if (days > 0)
    active = false;
}

void Worker::tickDay() {
  if (breakDays > 0) {
    breakDays--;
    if (breakDays == 0) {
      active = true;
    }
  }
}

void Worker::printInfo() const {
  std::cout << "Name: " << name << " | Age: " << age << " | Gender: " << gender
            << " | Status: " << (active ? "ACTIVE" : "BREAK")
            << " | Break days: " << breakDays << "\n";
}