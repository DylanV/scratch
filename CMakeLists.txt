cmake_minimum_required(VERSION 3.5)

option(test "Build all tests." ON)

set(PROJECT_NAME scratch)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(dir ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${dir}/build")

include_directories("${PROJECT_SOURCE_DIR}/src")

set (SOURCE_FILES src/basic.cpp src/basic.h)
add_library(src_lib ${SOURCE_FILES})

add_executable(scratch main.cpp)
target_link_libraries(scratch src_lib)

# Tests
add_subdirectory("${PROJECT_SOURCE_DIR}/ext/gtest")

enable_testing()

include_directories(${gtest_SOURCE_DIR})

include_directories("${PROJECT_SOURCE_DIR}/test")

add_executable(testBasic test/test_basic.cpp)
add_dependencies(testBasic googletest)

target_link_libraries(testBasic ${GTEST_LIBS_DIR}/libgtest.a ${GTEST_LIBS_DIR}/libgtest_main.a)
target_link_libraries(testBasic src_lib)
target_link_libraries(testBasic ${CMAKE_THREAD_LIBS_INIT})

add_test(test1 testBasic)