cmake_minimum_required(VERSION 3.20)

include(GoogleTest)

add_executable(canvas_test
    canvas_test.cpp)

target_link_libraries(canvas_test
    rtc_core
    gtest
    gtest_main)

gtest_discover_tests(canvas_test)

add_executable(tuple_test
    tuple_test.cpp)

target_link_libraries(tuple_test
    rtc_core
    gtest
    gtest_main)
      
gtest_discover_tests(tuple_test)

add_executable(matrix_test
    matrix_test.cpp)

target_link_libraries(matrix_test
    rtc_core
    gtest
    gtest_main)
      
gtest_discover_tests(matrix_test)