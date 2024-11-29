# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(Evidencia2 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files
set(SOURCES 
    src/main.cpp
    src/FordFulkenson.h
)

# Eexecutable target
add_executable(Evidencia2 ${SOURCES})

# Enable testing
enable_testing()

# Include FetchContent for Catch2
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0 # Replace with the latest version
)
FetchContent_MakeAvailable(Catch2)

# Test source files
set(TEST_FILES
    tests/test_main.cpp
    tests/test_fordFulkenson.cpp
)

# Test executable
# Create a separate executable for each test source
foreach(TEST_SRC ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_SRC} NAME_WE) 
    add_executable(${TEST_NAME} ${TEST_SRC})            
    target_link_libraries(${TEST_NAME} PRIVATE Catch2::Catch2WithMain)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})   
endforeach()

# Link libraries if needed
# target_link_libraries(test_main PRIVATE your_library_name)

