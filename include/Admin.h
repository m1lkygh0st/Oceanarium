#ifndef ADMIN_H
#define ADMIN_H

#include "Worker.h"

class Admin : public Worker {
public:
  Admin(const std::string &name, int age, const std::string &gender);

  void giveBreak(Worker &worker, int days) const;
  void printInfo() const override;
};

#endif