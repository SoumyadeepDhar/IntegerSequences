cmake_minimum_required(VERSION 3.16.3)
SET(PROJECT_NAME "IntegerSequence")
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project information
project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES CXX)

# Include directory for the project
include_directories(include)

# External library to do large int operations
find_library(LARGEINT NAMES largeint HINTS "${CMAKE_SOURCE_DIR}/library/")

# Add source files
set(SOURCES 
    source/processor.cpp
    source/A002110.cpp)

# Make ctest target
add_executable(A002110 ${SOURCES})

# Links the executable to the LargeInt C++ library.
target_link_libraries (A002110 PRIVATE ${LARGEINT})


