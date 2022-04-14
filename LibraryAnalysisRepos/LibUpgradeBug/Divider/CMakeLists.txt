cmake_minimum_required(VERSION 3.13)
project(divider CXX)

include_directories(
  external/libfraction/include/
)

add_subdirectory(external)
add_subdirectory(src)
