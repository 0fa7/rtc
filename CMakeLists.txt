cmake_minimum_required(VERSION 3.20)

project(rtc)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(RTC_LIB_SOURCES
    canvas.cpp
    tuple.cpp)

add_library(rtc_core
    ${RTC_LIB_SOURCES})

set(RTC_MAIN_SOURCES
    rtc.cpp)

add_executable(rtc
    ${RTC_MAIN_SOURCES})

target_link_libraries(rtc
    rtc_core)

if(${RTC_ENABLE_TESTS})
    enable_testing()
    add_subdirectory(tests)
endif()