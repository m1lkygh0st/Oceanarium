#include "Admin.h"

#include <iostream>

Admin::Admin(const std::string &name, const int age, const std::string &gender)
    : Worker(name, age, gender) {}

void Admin::giveBreak(Worker &worker, const int days) const {
  worker.setUnavailableDays(days);

  std::cout << "Admin " << getName() << " gave " << worker.getName()
            << " a break for " << days << " day(s).\n";
}

void Admin::printInfo() const {
  std::cout << "[ADMIN] "
            << "Name: " << getName() << ", Age: " << getAge()
            << ", Gender: " << getGender()
            << ", Status: " << (isActive() ? "Active" : "Inactive") << '\n';
}