cmake_minimum_required(VERSION 3.23)
project(cpp_script)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp_script main.cpp point.cpp metropolis_hastings.cpp matrice.cpp vector_double.h swendsen_wang.h swendsen_wang.cpp)
