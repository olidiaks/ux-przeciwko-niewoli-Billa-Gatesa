cmake_minimum_required(VERSION 3.25)
project(Projekt_podbijanie_kampusu_microsoftu)

set(CMAKE_CXX_STANDARD 11)

add_executable(Projekt_podbijanie_kampusu_microsoftu main.cpp Game.cpp Game.h Enemy.cpp Enemy.h Enemy.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(SFML/include)
target_link_libraries(Projekt_podbijanie_kampusu_microsoftu sfml-system sfml-network sfml-window sfml-graphics sfml-audio)