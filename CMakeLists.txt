# Root CMakeLists.txt remains the same as you provided last:
cmake_minimum_required(VERSION 3.24)
project(binc_cmake_example)

set(CMAKE_CXX_STANDARD 17)

add_executable(binc_cmake_example main.cpp)

# Add the external library
add_subdirectory(externals/binc)

# Link your executable with the external library
target_link_libraries(binc_cmake_example PRIVATE binc)
