#ifndef INPUT_H
#define INPUT_H

#include <algorithm>
#include <cctype>
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

        if (std::cin.fail()) {
          throw std::runtime_error("Invalid integer");
        }

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

  static std::string readString(const std::string &prompt) {
    while (true) {
      std::string value;
      std::cout << prompt;
      std::getline(std::cin, value);

      if (!std::cin.fail()) {
        return value;
      }

      std::cin.clear();
    }
  }

  static std::string readNonEmptyString(const std::string &prompt) {
    while (true) {

      if (std::string value = readString(prompt); !value.empty()) {
        return value;
      }

      std::cout << "Value cannot be empty\n";
    }
  }

  static int readIntRange(const std::string &prompt, const int min,
                          const int max) {
    while (true) {

      if (const int value = readInt(prompt); value >= min && value <= max) {
        return value;
      }

      std::cout << "Value must be in range [" << min << ", " << max << "]\n";
    }
  }

  static std::string readLettersOnly(const std::string &prompt) {
    while (true) {
      std::string value = readNonEmptyString(prompt);
      bool valid = true;
      for (const char c : value) {
        if (!std::isalpha(static_cast<unsigned char>(c))) {
          valid = false;
          break;
        }
      }
      if (valid) {
        return value;
      }

      std::cout << "Value must contain only letters\n";
    }
  }

  static std::string readGender(const std::string &prompt) {
    while (true) {
      std::string value = readNonEmptyString(prompt);
      std::transform(value.begin(), value.end(), value.begin(),
                     [](const unsigned char c) { return std::tolower(c); });

      if (value == "male" || value == "female") {
        return value;
      }

      std::cout << "Gender must be 'male' or 'female'\n";
    }
  }
};

#endif
