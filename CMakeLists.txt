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
        src/Worker.cpp
        include/Worker.h
        src/Admin.cpp
)

target_include_directories(Oceanarium PRIVATE include)