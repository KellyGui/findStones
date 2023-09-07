cmake_minimum_required(VERSION 3.10.0)
project(mytest)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} test.cpp)
target_link_libraries(${PROJECT_NAME} gtest gtest_main findstonepairs)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})