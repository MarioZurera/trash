include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

cmake_minimum_required(VERSION 3.29)
project(trash C CXX)

enable_testing()

# Set C Standard
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS_DEBUG "-O0 -g3 -Wall -Wextra -Wpedantic -Werror")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

include_directories(include)
add_executable(trash
        src/main.c
        src/lexer.c
        src/readline.c
        include/trash.h
)

add_executable(tests
        src/readline.c
        include/trash.h
        tests/test.cpp
        tests/readline_test.cpp
)
target_link_libraries(tests gtest gtest_main)

# Add test to CTest
add_test(NAME tests COMMAND tests)