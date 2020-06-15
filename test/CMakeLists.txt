cmake_minimum_required(VERSION 2.8)

SET(PROJECT_NAME_TEST ${PROJECT_NAME}-test)
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -Wall")
add_compile_options(-std=c++17)
enable_testing()
find_package(GTest REQUIRED)

include_directories(
  ${GTEST_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME_TEST}
  main.cpp
  address_test.cpp
)

target_link_libraries(${PROJECT_NAME_TEST}
  PRIVATE
  ${GTEST_BOTH_LIBRARIES}
  ${PROJECT_NAME}
)
