#ifndef ADMIN_H
#define ADMIN_H

#include "Worker.h"

/**
 * @class Admin
 * @brief Администратор океанариума — расширенный тип работника.
 *
 * Администратор может управлять другими работниками, например
 * назначать им перерывы.
 */
class Admin : public Worker {
public:
  /**
   * @brief Конструктор администратора
   * @param name Имя
   * @param age Возраст
   * @param gender Пол
   */
  Admin(std::string name, int age, std::string gender);

  /**
   * @brief Назначить перерыв работнику
   * @param worker Работник, которому назначается перерыв
   * @param days Количество дней
   *
   * После вызова работник становится неактивным на указанное число дней.
   */
  void giveBreak(Worker &worker, int days) const;

  /**
   * @brief Вывод информации об администраторе
   */
  void printInfo() const override;
};

#endif