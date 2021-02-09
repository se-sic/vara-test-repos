cmake_minimum_required(VERSION 3.13)

project(calculator)

include_directories(
    include/
)

add_executable(calculator
               src/main.cpp
               src/expression.cpp
               src/visitor.cpp
               src/parser.cpp
               )
