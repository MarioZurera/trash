include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

cmake_minimum_required(VERSION 3.29)
project(bash C CXX)

# Enable testing
enable_testing()

# Set C Standard
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add GoogleTest directory (Assuming it's in the external/googletest folder)
# add_subdirectory(googletest)

# Define source files and targets
add_executable(my_program main.c)

# Add Google Test test target
add_executable(tests test.cpp)
target_link_libraries(tests gtest gtest_main)

# Add test to CTest
add_test(NAME tests COMMAND tests)


#[[



add_executable(bash main.c)

add_subdirectory(googletest)

enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bash_tests test_sum.cpp)

target_link_libraries(bash_tests gtest gtest_main)

add_test(NAME mash_tests COMMAND mash_tests)]]
