#pragma once

#include <atomic>
#include <memory>
#include <thread>
#include <vector>

#include "Aquarium.h"

/**
 * @class Oceanarium
 * @brief Главный класс симуляции океанариума.
 *
 * Управляет аквариумами и глобальной симуляцией времени.
 */
class Oceanarium {
  std::vector<std::unique_ptr<Aquarium>> aquariums;

  std::thread timeThread;
  std::atomic<bool> running{false};

  /**
   * @brief Основной цикл симуляции времени
   */
  void timeLoop();

public:
  /**
   * @brief Добавить аквариум
   */
  void addAquarium(std::unique_ptr<Aquarium> aquarium);

  /**
   * @brief Количество аквариумов
   */
  [[nodiscard]] int getAquariumCount() const;

  /**
   * @brief Получить аквариум
   */
  [[nodiscard]] Aquarium &getAquarium(int index) const;

  /**
   * @brief Запуск симуляции
   */
  void startSimulation();

  /**
   * @brief Остановка симуляции
   */
  void stopSimulation();

  ~Oceanarium();
};