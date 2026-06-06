#ifndef WORKER_H
#define WORKER_H

#include <string>

/**
 * @class Worker
 * @brief Базовый работник океанариума.
 *
 * Может кормить рыб и уходить в отпуск (break).
 */
class Worker {
protected:
  std::string name; /**< Имя */
  int age;          /**< Возраст */
  std::string gender; /**< Пол */

  bool active;      /**< Активен ли */
  int breakDays;    /**< Остаток дней отдыха */

public:
  /**
   * @brief Конструктор работника
   */
  Worker(std::string name, int age, std::string gender);

  virtual ~Worker() = default;

  [[nodiscard]] const std::string &getName() const;
  [[nodiscard]] int getAge() const;
  [[nodiscard]] const std::string &getGender() const;
  [[nodiscard]] bool isActive() const;

  /**
   * @brief Установить активность
   */
  void setActive(bool status);

  /**
   * @brief Назначить отпуск
   */
  void setBreak(int days);

  /**
   * @brief Симуляция дня
   */
  void tickDay();

  /**
   * @brief Вывод информации
   */
  virtual void printInfo() const;
};

#endif