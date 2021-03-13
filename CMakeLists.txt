cmake_minimum_required(VERSION 3.17)
project(file_tracer)

set(CMAKE_CXX_STANDARD 17)

# Include wxWidgets lib sources (to build with the project)
add_subdirectory(libs/wxWidgets)
add_executable(file_tracer src/main.cpp)

target_link_libraries(file_tracer wx::net wx::core wx::base)
