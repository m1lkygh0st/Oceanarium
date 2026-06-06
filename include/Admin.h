#ifndef ADMIN_H
#define ADMIN_H

#include "Worker.h"

class Admin : public Worker {
public:
  Admin(std::string name, int age, std::string gender);

  void giveBreak(Worker &worker, int days) const;
  void printInfo() const override;
};

#endif