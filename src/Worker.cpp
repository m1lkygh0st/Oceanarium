#include "Worker.h"
#include <iostream>
Worker::Worker(std::string name, const int age, std::string gender) :
    name(std::move(name)), age(age), gender(std::move(gender)) {}

const std::string &Worker::getName() const { return name; }
int Worker::getAge() const { return age; }
const std::string &Worker::getGender() const { return gender; }

void Worker::feed() const { std::cout << "Worker " << name << " is feeding fishes.\n"; }

void Worker::printInfo() const { std::cout << "Name: " << name << ", Age: " << age << ", Gender: " << gender << "\n"; }
