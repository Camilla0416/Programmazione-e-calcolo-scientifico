cmake_minimum_required(VERSION 3.20)
project(es_3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE CXX FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SOURCES rational.hpp main.cpp)
add_executable(es_3 ${SOURCES})