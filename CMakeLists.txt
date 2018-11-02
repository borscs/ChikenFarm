cmake_minimum_required(VERSION 3.12)
project(ChickenFarm)

set(CMAKE_CXX_STANDARD 17)

set(QT_DIR ~/Qt/5.11.0/gcc_64)

find_package(Qt5Core REQUIRED HINTS ${QT_DIR})

add_executable(ChickenFarm main.cpp Utils.h Farm.cpp Chicken.cpp )

target_link_libraries(ChickenFarm Qt5::Core)