cmake_minimum_required(VERSION 3.5.0)
project(Receipt_generator VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_compile_options(-pedantic-errors -std=c++20 -Wall -Wextra -Weffc++ -Wconversion -Wsign-conversion)

add_executable(Receipt_generator main.cpp data.cpp output.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
