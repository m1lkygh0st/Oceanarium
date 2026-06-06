#ifndef CARDINALFISH_H
#define CARDINALFISH_H

#include "Fish.h"

/**
 * @class Cardinalfish
 * @brief Рыба — кардинал.
 *
 * Наследуется от базового класса Fish.
 * Имеет стандартные характеристики: возраст, пол, аппетит, здоровье.
 */
class Cardinalfish : public Fish {
public:
  /**
   * @brief Конструктор рыбы кардинала
   * @param age Возраст рыбы
   * @param gender Пол рыбы ("male"/"female")
   * @param appetite Аппетит (0-100)
   * @param health Здоровье (0-100)
   *
   * Вызывает конструктор базового класса Fish с видом "Cardinalfish".
   */
  Cardinalfish(const int age, const std::string &gender, const int appetite,
               const int health)
      : Fish("Cardinalfish", age, gender, appetite, health) {}
};

#endif