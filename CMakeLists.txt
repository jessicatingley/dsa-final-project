cmake_minimum_required(VERSION 3.23)
project(dsa_final_project)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(dsa_final_project
        insertion_sort.cpp parallel_insertion_sort.cpp)

add_executable(tests
        unit_tests.cpp insertion_sort.cpp merge_sort.cpp quick_sort.cpp parallel_insertion_sort.cpp)

add_executable(benchmarking
        benchmark.cpp insertion_sort.cpp merge_sort.cpp quick_sort.cpp parallel_insertion_sort.cpp)
