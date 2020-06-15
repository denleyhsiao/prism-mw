cmake_minimum_required(VERSION 2.8)

SET(PROJECT_NAME "prism-mw")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -Wall")
add_compile_options(-std=c++17)

project(${PROJECT_NAME})

include_directories(
  include
)

add_library(${PROJECT_NAME}
  src/address.cpp
)

add_subdirectory(test)
