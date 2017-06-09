cmake_minimum_required(VERSION 3.7)
project(onp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Token.cpp Token.h)
add_executable(onp ${SOURCE_FILES})