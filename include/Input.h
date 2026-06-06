#ifndef INPUT_H
#define INPUT_H

#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

/**
 * @class Input
 * @brief Утилита для безопасного ввода данных с консоли.
 *
 * Содержит методы проверки корректности ввода пользователя.
 */
class Input {
public:
  /**
   * @brief Чтение целого числа
   */
  static int readInt(const std::string &prompt);

  /**
   * @brief Чтение строки
   */
  static std::string readString(const std::string &prompt);

  /**
   * @brief Чтение непустой строки
   */
  static std::string readNonEmptyString(const std::string &prompt);

  /**
   * @brief Чтение числа в диапазоне
   */
  static int readIntRange(const std::string &prompt, int min, int max);

  /**
   * @brief Только буквы
   */
  static std::string readLettersOnly(const std::string &prompt);

  /**
   * @brief Пол (male/female)
   */
  static std::string readGender(const std::string &prompt);
};

#endif