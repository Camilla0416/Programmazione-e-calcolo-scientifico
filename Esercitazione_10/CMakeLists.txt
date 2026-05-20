cmake_minimum_required(VERSION 3.20)
project(Esercitazione_10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE CXX FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

include_directories(/usr/include/eigen3)

set(SOURCES gradiente_coniugato.cpp)
add_executable(es_10 ${SOURCES})