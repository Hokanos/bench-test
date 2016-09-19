cmake_minimum_required(VERSION 2.8)

project(bench-test)

add_definitions(--std=c++11)

add_subdirectory(3rd/google-benchmark)

include_directories(src)
include_directories(3rd/google-benchmark/include SYSTEM)

set(FIB_SRC src/Fibonacci.cpp)
add_library(fib ${FIB_SRC})

add_executable(gbench-test src/gbench-test.cpp)
target_link_libraries(gbench-test benchmark pthread fib)

add_executable(mybench-test src/mybench-test.cpp)
target_link_libraries(mybench-test pthread fib)