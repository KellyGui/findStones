cmake_minimum_required(VERSION 3.10.0)
project(findstonepairs)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
link_directories(${PROJECT_SOURCE_DIR}/lib)

#build googletest
enable_testing()
add_subdirectory(3dparty/googletest)
include_directories(3dparty/googletest/googletest/include)

include_directories(src/)
add_library(${PROJECT_NAME} SHARED src/findStonepairs.cpp)

add_executable(main src/findStonepairs.cpp)
add_subdirectory(test)
