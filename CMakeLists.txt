cmake_minimum_required(VERSION 3.21)

project(Stopwatch LANGUAGES CXX VERSION 1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Stopwatch STATIC stopwatch.cpp)
