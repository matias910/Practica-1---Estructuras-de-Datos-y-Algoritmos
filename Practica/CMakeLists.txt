cmake_minimum_required(VERSION 4.0)
project(Practica)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practica
        src/main.cpp
        src/dataset.cpp
        src/quicksort.cpp
        src/heapsort.cpp
        src/AVLtree.cpp
)

target_include_directories(Practica PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)