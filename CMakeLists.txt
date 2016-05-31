cmake_minimum_required(VERSION 3.5)

option(test "Build all tests." ON)

project(scratch CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${dir}/build")

include_directories("${PROJECT_SOURCE_DIR}/containers")
include_directories("${PROJECT_SOURCE_DIR}/algorithms")

add_executable(scratch main.cpp)

# Tests
add_subdirectory("${PROJECT_SOURCE_DIR}/ext/gtest")
enable_testing()

include_directories(${GTEST_INCLUDE_DIRS})

include_directories("${PROJECT_SOURCE_DIR}/test")

set (TEST_FILES test/test_linked_list.cpp test/test_queue.cpp test/test_stack.cpp test/test_double_linked_list.cpp test/test_sort.cpp)
add_executable(testBasic ${TEST_FILES})
add_dependencies(testBasic googletest)

target_link_libraries(testBasic ${GTEST_LIBS_DIR}/libgtest.a ${GTEST_LIBS_DIR}/libgtest_main.a)
target_link_libraries(testBasic ${CMAKE_THREAD_LIBS_INIT})

add_test(test1 testBasic)