cmake_minimum_required(VERSION 3.12)
project(stl_benchmark)

add_subdirectory(benchmark)

add_executable(stl_benchmark main.cpp)

set_property(TARGET stl_benchmark PROPERTY CXX_STANDARD 11)

target_link_libraries(stl_benchmark benchmark benchmark_main)

file(COPY nist.stl DESTINATION ${CMAKE_BINARY_DIR})
