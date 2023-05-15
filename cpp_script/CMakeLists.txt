cmake_minimum_required(VERSION 3.23)
project(cpp_script)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp_script main.cpp vecteur_template.cpp point.cpp metropolis_hastings.cpp matrice.cpp)
