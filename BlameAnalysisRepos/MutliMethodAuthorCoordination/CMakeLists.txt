cmake_minimum_required(VERSION 3.1...3.24)
project(
  ComputationService
  VERSION 1.0
  LANGUAGES CXX
)

add_executable(computeService
  main.cpp
  loader.cpp
  computation.cpp
)
