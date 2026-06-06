#ifndef AQUARIUM_H
#define AQUARIUM_H

#include "Fish.h"
#include "Worker.h"
#include <memory>
#include <vector>

/**
 * @class Aquarium
 * @brief Аквариум, содержащий рыб и работников.
 *
 * Отвечает за хранение и управление объектами внутри себя.
 */
class Aquarium {
  int aquariumNumber; /**< Номер аквариума */
  std::vector<std::unique_ptr<Fish>> fishes; /**< Рыбы */
  std::vector<std::unique_ptr<Worker>> workers; /**< Работники */

public:
  /**
   * @brief Конструктор аквариума
   * @param number Номер аквариума
   */
  explicit Aquarium(int number);

  /**
   * @brief Добавить рыбу
   * @param fish Указатель на рыбу
   */
  void addFish(std::unique_ptr<Fish> fish);

  /**
   * @brief Добавить работника
   * @param worker Указатель на работника
   */
  void addWorker(std::unique_ptr<Worker> worker);

  /**
   * @brief Получить рыбу по индексу
   * @param index Индекс
   * @return Ссылка на рыбу
   */
  [[nodiscard]] Fish &getFish(int index) const;

  /**
   * @brief Количество рыб
   */
  [[nodiscard]] int getFishCount() const;

  /**
   * @brief Количество работников
   */
  [[nodiscard]] int getWorkerCount() const;

  /**
   * @brief Номер аквариума
   */
  [[nodiscard]] int getNumber() const;

  /**
   * @brief Получить работника по индексу
   */
  [[nodiscard]] Worker &getWorker(int index) const;

  /**
   * @brief Кормление рыб работником
   * @param worker Работник
   */
  void feedFishByWorker(const Worker &worker) const;

  /**
   * @brief Симуляция одного дня
   */
  void tickDay();

  /**
   * @brief Вывод информации об аквариуме
   */
  void printInfo() const;
};

#endif