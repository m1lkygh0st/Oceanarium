#ifndef ANGELFISH_H
#define ANGELFISH_H

#include "Fish.h"

/**
 * @class Angelfish
 * @brief Вид рыбы — скалярия.
 */
class Angelfish : public Fish {
public:
  /**
   * @brief Конструктор скалярии
   * @param age Возраст
   * @param gender Пол
   * @param appetite Аппетит
   * @param health Здоровье
   */
  Angelfish(int age, const std::string &gender, int appetite, int health)
      : Fish("Angelfish", age, gender, appetite, health) {}
};

#endif