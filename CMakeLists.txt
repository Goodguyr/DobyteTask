cmake_minimum_required(VERSION 3.21)
project(DoByteProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(main main.cpp Solution.cpp Solution.h)
add_executable(test SolutionTests.cpp Solution.cpp Solution.h)

target_link_libraries(test gtest::gtest)

target_compile_options(main PRIVATE -O3 -Wall -Wextra) 