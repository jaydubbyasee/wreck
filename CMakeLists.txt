cmake_minimum_required(VERSION 2.8)

project(wreck)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# Enables use of C++11 libraries and allows Eclipse CDT4 Generator 
# to enable indexing for C++11 syntax and api.
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

# The core library for Wreck
add_subdirectory(core)

# The engine library for Wreck
add_subdirectory(engine)

# Thee graphics library for Wreck
add_subdirectory(graphics)

# Demo directory
add_subdirectory(demo)

# Test directory
add_subdirectory(test)
