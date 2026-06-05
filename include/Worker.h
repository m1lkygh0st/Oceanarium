#ifndef WORKER_H
#define WORKER_H


#include <string>

class Worker {
  std::string name;
  int age;
  std::string gender;

public:
  Worker(std::string name, int age, std::string gender);

  const std::string &getName() const;
  int getAge() const;
  const std::string &getGender() const;

  void feed() const;

  void printInfo() const;
};

#endif
