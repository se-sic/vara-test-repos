project(tester CXX)

include_directories(
  external/fire_lib/include/
  external/water_lib/include/
)

add_subdirectory(external)
add_subdirectory(test_prog)
