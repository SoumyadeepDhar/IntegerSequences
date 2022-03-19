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

# List of manual sequences
file(STRINGS msequence.txt MANUAL_SEQUENCES)

# Create target for each sequence
foreach(seq ${MANUAL_SEQUENCES})

    # Add source files
    set(SOURCES 
        source/manual/${seq}.cpp
        source/processor.cpp)

    # Make ctest target 
    add_executable(${seq} ${SOURCES})

    # Create sequence number based class
    target_compile_definitions(${seq} PRIVATE "-DSEQUENCE=${seq}" "-DPARI")

    # Set build options
    target_compile_options(${seq} PRIVATE -O3 -Wall -Wextra)

    # Links the executable to the LargeInt C++ library.
    target_link_libraries (${seq} PRIVATE ${LARGEINT}) 

    # Add CTest to CI
    add_test(CTest${seq} ${seq})

endforeach()


# List of generated sequences
file(STRINGS gsequence.txt GENERATED_SEQUENCES)

# Create target for each sequence
foreach(seq ${GENERATED_SEQUENCES})

    # Add source files
    set(SOURCES 
        source/generated/${seq}.cpp
        source/processor.cpp)

    # Make ctest target 
    add_executable(${seq} ${SOURCES})

    # Create sequence number based class
    target_compile_definitions(${seq} PRIVATE "-DSEQUENCE=${seq}" "-DPARI")

    # Set build options
    target_compile_options(${seq} PRIVATE -O3 -Wall -Wextra)

    # Links the executable to the LargeInt C++ library.
    target_link_libraries (${seq} PRIVATE ${LARGEINT}) 

    # Add CTest to CI
    add_test(CTest${seq} ${seq})

endforeach()
