# 🐠 Oceanarium — C++17 Simulation Project

Учебный проект, реализующий систему управления океанариумом с использованием **C++17, OOP, CMake и unit-тестирования (Doctest)**.



<a href="https://github.com/m1lkygh0st/Oceanarium">
  <img src="https://img.shields.io/badge/Oceanarium-C++17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"  alt=""/>
</a>

---

# 📌 Основной функционал

## 🐟 Животные (Fish system)

Базовый класс `Fish` и наследники:

* Salmon
* Shark
* Angelfish
* Butterflyfish
* Cardinalfish

### Характеристики:

* возраст
* пол
* аппетит
* здоровье
* статус (жив / мёртв)

### Поведение:

* `feed(int food)` — кормление
* `tickDay()` — симуляция дня

---

## 👨‍🔧 Сотрудники

### Worker

* имя
* возраст
* пол
* активность
* система отпусков (breakDays)
* `tickDay()` — обновление состояния

### Admin (наследник Worker)

* функция управления сотрудниками
* `giveBreak(Worker&, int days)`

---

## 🏢 Аквариумы

Функции:

* добавление рыб
* добавление сотрудников
* кормление рыб сотрудником
* вывод информации
* подсчёт состояния

Хранение реализовано через:

* `std::vector<std::unique_ptr<Fish>>`
* `std::vector<std::unique_ptr<Worker>>`

---

## 🌊 Океанариум

* хранит множество аквариумов
* управляет симуляцией времени
* многопоточная система (`std::thread`)
* обновление состояния всей системы

---

## ⌨️ Консольный интерфейс

Доступные действия:

* добавить аквариум
* добавить рыбу
* добавить сотрудника / администратора
* показать состояние системы
* кормление рыб
* назначение отпусков
* выход

---

# ⚙️ Технологический стек

* C++17
* STL (vector, memory, thread, atomic)
* CMake ≥ 3.16
* Doctest (unit testing)
* RAII (unique_ptr)
* Multithreading

---

# 🧪 Тестирование

Используется **Doctest**.

### Покрытие тестами:

* Fish::feed (границы + логика насыщения)
* Fish::tickDay (жизненный цикл + смерть)
* Worker::setBreak + tickDay (состояния)
* Aquarium::addFish (контейнерная логика)

---

## ▶ Запуск тестов

```bash id="test_run_10"
cmake -S . -B build
cmake --build build
cd build
ctest -V
```

---

# 🏗️ Сборка проекта

## Требования:

* CMake ≥ 3.16
* Компилятор с поддержкой C++17

## Сборка:

```bash id="build_10"
cmake -S . -B build
cmake --build build
```

## Запуск:

```bash id="run_10"
./build/Oceanarium
```

---

# 📁 Структура репозитория (GitHub-ready)

```text id="repo_10"
Oceanarium/
├── include/              # заголовочные файлы
├── src/                  # реализация логики
├── tests/                # Doctest unit tests
├── docs/                 # (Doxygen HTML документация)
├── CMakeLists.txt
├── README.md
└── .clang-format
```

---

# 🌿 Git workflow

Проект ведётся по модели веток:

```text id="git_10"
main
 └── dev
      ├── feature/fish-system
      ├── feature/aquarium
      ├── feature/workers
      ├── feature/tests
      └── feature/ui
```

### Правила работы:

* `main` — стабильная версия (релиз)
* `dev` — интеграционная ветка
* каждая новая фича → отдельная ветка
* merge → только через Pull Request

---

# 📚 Документация (Doxygen)

Генерация документации:

```bash id="doxy_10"
doxygen Doxyfile
```

Результат:

```
docs/html/index.html
```

---

# 🧠 Архитектура проекта

## Принципы:

* OOP (наследование, полиморфизм)
* RAII (unique_ptr)
* separation of concerns
* modular design

## Основные модули:

* Fish system
* Worker system
* Aquarium container
* Oceanarium manager
* Input system
* Simulation engine (thread-based)

---

# 🔒 Технические особенности

* ❌ нет new/delete
* ✔ smart pointers
* ✔ exception-safe input handling
* ✔ multithreaded simulation
* ✔ strict separation header/source
* ✔ UTF-8 encoding
* ✔ C++17 standard

---

# 🧪 Качество кода

* clang-format style applied
* no raw memory management
* unit tests via Doctest
* modular architecture
* no absolute paths

---

# 🚀 Как выглядит сценарий работы

1. пользователь создаёт аквариум
2. добавляет рыб
3. добавляет сотрудников
4. сотрудники кормят рыб
5. система симулирует дни
6. состояние обновляется автоматически

---
