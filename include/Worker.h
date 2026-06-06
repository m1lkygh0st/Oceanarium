#ifndef WORKER_H
#define WORKER_H

#include <string>

class Worker {
protected:
  std::string name;
  int age;
  std::string gender;
  bool active;
  int unavailableDays;

public:
  Worker(std::string name, int age, std::string gender);

  virtual ~Worker() = default;

  [[nodiscard]] const std::string &getName() const;
  [[nodiscard]] int getAge() const;
  [[nodiscard]] const std::string &getGender() const;

  [[nodiscard]] bool isActive() const;

  void setActive(bool status);

  void setUnavailableDays(int days);
  [[nodiscard]] int getUnavailableDays() const;
  void tickDay();
  virtual void feed() const;
  virtual void printInfo() const;
};

#endif