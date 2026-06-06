#ifndef FISH_H
#define FISH_H

#include <string>

/**
 * @class Fish
 * @brief Базовый класс рыбы в океанариуме.
 *
 * Содержит базовые характеристики всех рыб:
 * возраст, пол, аппетит, здоровье и статус жизни.
 */
class Fish {
protected:
  std::string species; /**< Вид рыбы */
  int age;             /**< Возраст */
  std::string gender;  /**< Пол */
  int appetite;        /**< Аппетит (0-100) */
  int health;          /**< Здоровье (0-100) */
  bool alive;          /**< Жива ли рыба */

public:
  /**
   * @brief Конструктор рыбы
   */
  Fish(std::string species, int age, std::string gender, int appetite, int health);

  virtual ~Fish() = default;

  [[nodiscard]] const std::string &getSpecies() const;
  [[nodiscard]] int getAge() const;
  [[nodiscard]] const std::string &getGender() const;
  [[nodiscard]] int getAppetite() const;
  [[nodiscard]] int getHealth() const;
  [[nodiscard]] bool isAlive() const;

  /**
   * @brief Кормление рыбы
   * @param food количество еды
   */
  void feed(int food);

  /**
   * @brief Симуляция одного дня жизни рыбы
   */
  void tickDay();

  /**
   * @brief Вывод информации о рыбе
   */
  virtual void printInfo() const;
};

#endif