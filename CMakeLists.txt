# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(Evidencia2 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files
set(SOURCES src/main.cpp)

# Eexecutable target
add_executable(Evidencia2 ${SOURCES})

# Enable testing
enable_testing()

# Test executable
add_executable(test_main tests/test_main.cpp)

# Link libraries if needed
# target_link_libraries(test_main PRIVATE your_library_name)

# Register the test with CTest
add_test(NAME TestMain COMMAND test_main)
