cmake_minimum_required(VERSION 3.20)

add_executable(tuple_test
    tuple_test.cpp)

target_link_libraries(tuple_test
    rtc_core
    gtest
    gtest_main)
      
include(GoogleTest)
gtest_discover_tests(tuple_test)