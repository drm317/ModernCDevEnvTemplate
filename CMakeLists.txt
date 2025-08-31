cmake_minimum_required(VERSION 3.16)
project(c_template)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.c")
file(GLOB LIB_SOURCES "src/*.c")
list(REMOVE_ITEM LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c")

# Main executable
add_executable(main ${SOURCES})

# Test configuration
file(GLOB TEST_SOURCES "test/*.c")
file(GLOB TEST_UNITY_SOURCES "test/unity/*.c")

# Test executable
add_executable(test_runner ${LIB_SOURCES} ${TEST_SOURCES} ${TEST_UNITY_SOURCES})
target_include_directories(test_runner PRIVATE test)

# Custom targets for compatibility with original workflow
add_custom_target(run
    COMMAND main
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(test
    COMMAND test_runner
    DEPENDS test_runner
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(format
    COMMAND clang-format -i ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(tidy
    COMMAND clang-tidy ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c -- -I${CMAKE_CURRENT_SOURCE_DIR}/include
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)