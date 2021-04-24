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

# Enable CTest
enable_testing()

# List of sequences
set(SEQUENCES A002110 A143293 A067175)

# Create target for each sequence
foreach(seq ${SEQUENCES})

    # Add source files
    set(SOURCES 
        source/processor.cpp
        source/${seq}.cpp)

    # Make ctest target 
    add_executable(${seq} ${SOURCES})

    # Links the executable to the LargeInt C++ library.
    target_link_libraries (${seq} PRIVATE ${LARGEINT}) 

    # Add CTest to CI
    add_test(CTest${seq} ${seq})

endforeach(seq)

