#include "Admin.h"
#include <iostream>

Admin::Admin(std::string name, const int age, std::string gender)
    : Worker(std::move(name), age, std::move(gender)) {}

void Admin::giveBreak(Worker &worker, const int days) const {
  worker.setBreak(days);
  std::cout << "Admin " << name << " gave break " << days << " days to "
            << worker.getName() << "\n";
}

void Admin::printInfo() const {
  std::cout << "[ADMIN] ";
  Worker::printInfo();
}