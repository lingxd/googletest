cmake_minimum_required(VERSION 3.0.0)
project(gtest01 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
add_test(Test gtest01)
enable_testing()

find_package(GTest REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(gtest01 main.cpp)
target_link_libraries(gtest01 GTest::GTest GTest::Main)
target_link_libraries(gtest01 ${GTEST_BOTH_LIBRARIES})
target_link_libraries(gtest01 ${CMAKE_THREAD_LIBS_INIT})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
