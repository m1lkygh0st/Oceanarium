cmake_minimum_required(VERSION 3.16)

project(Oceanarium)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Oceanarium
        src/main.cpp
        src/Aquarium.cpp
        src/Oceanarium.cpp
        src/Fish.cpp
        src/Worker.cpp
        src/Admin.cpp
        src/Input.cpp
)

target_include_directories(Oceanarium PRIVATE include)

enable_testing()

add_executable(tests
        tests/test_main.cpp
        src/Fish.cpp
        src/Worker.cpp
        src/Aquarium.cpp
        src/Oceanarium.cpp
        src/Admin.cpp
)

target_include_directories(tests PRIVATE include tests)

add_test(NAME OceanariumTests COMMAND tests)