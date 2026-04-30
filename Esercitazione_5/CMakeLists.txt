cmake_minimum_required(VERSION 3.20)
project(Esercitazione_5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Creo il target per l'eseguibile 1 del mio progetto software
set(SRC_measure_sorts timecounter.cpp measure_sorts.cpp)
add_executable(measure_sorts ${SRC_measure_sorts})

# Creo il target per l'eseguibile 2 del mio progetto software
set(SRC_measure_sorts_new timecounter.cpp measure_sorts_new.cpp)
add_executable(measure_sorts_new ${SRC_measure_sorts_new})

## Creo i target per gli eseguibili che effettueranno i test unitari
add_executable(test_mergesort test_mergesort.cpp)
add_test(NAME mergesort COMMAND test_mergesort)

add_executable(test_quicksort test_quicksort.cpp)
add_test(NAME quicksort COMMAND test_quicksort)

enable_testing()