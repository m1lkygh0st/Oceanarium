#ifndef WORKER_H
#define WORKER_H

#include <string>

class Worker {
protected:
  std::string name;
  int age;
  std::string gender;

  bool active;
  int breakDays;

public:
  Worker(std::string name, int age, std::string gender);
  virtual ~Worker() = default;

  [[nodiscard]] const std::string &getName() const;
  [[nodiscard]] int getAge() const;
  [[nodiscard]] const std::string &getGender() const;
  [[nodiscard]] bool isActive() const;

  void setActive(bool status);

  void setBreak(int days);
  void tickDay();

  virtual void printInfo() const;
};

#endif