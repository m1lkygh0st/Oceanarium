#ifndef BUTTERFLYFISH_H
#define BUTTERFLYFISH_H

#include "Fish.h"

/**
 * @class Butterflyfish
 * @brief Рыба — рыба-бабочка.
 */
class Butterflyfish : public Fish {
public:
  /**
   * @brief Конструктор рыбы-бабочки
   * @param age Возраст рыбы
   * @param gender Пол рыбы ("male"/"female")
   * @param appetite Аппетит (0-100)
   * @param health Здоровье (0-100)
   *
   * Вызывает конструктор базового класса Fish с видом "Butterflyfish".
   */
  Butterflyfish(int age, const std::string &gender, int appetite, int health)
      : Fish("Butterflyfish", age, gender, appetite, health) {}
};

#endif