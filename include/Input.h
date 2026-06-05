#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

class Input {
public:
  static int readInt(const std::string &prompt) {
    while (true) {
      try {
        int value;
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
          throw std::runtime_error("Invalid integer");

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
      }

      catch (const std::exception &e) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: " << e.what() << "\n";
      }
    }
  }
};

#endif
