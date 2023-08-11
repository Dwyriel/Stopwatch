cmake_minimum_required(VERSION 3.21)
project(Stopwatch)

set(CMAKE_CXX_STANDARD 11)

add_library(Stopwatch STATIC stopwatch.cpp)
