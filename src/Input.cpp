// src/Input.cpp
#include "Input.h"
#include <iostream>
#include <limits>

int Input::readInt(const std::string &prompt) {
  int value;
  std::cout << prompt;
  while (!(std::cin >> value)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Try again: ";
  }
  return value;
}

int Input::readIntRange(const std::string &prompt, int min, int max) {
  int value;
  do {
    value = readInt(prompt);
    if (value < min || value > max) {
      std::cout << "Out of range! Enter a value between " << min << " and "
                << max << ": ";
    }
  } while (value < min || value > max);
  return value;
}

std::string Input::readString(const std::string &prompt) {
  std::string value;
  std::cout << prompt;
  std::cin >> value;
  return value;
}

std::string Input::readGender(const std::string &prompt) {
  std::string value;
  do {
    std::cout << prompt;
    std::cin >> value;
  } while (value != "male" && value != "female");
  return value;
}