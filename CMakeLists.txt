cmake_minimum_required(VERSION 3.17)
project(file_tracer)

set(CMAKE_CXX_STANDARD 17)

# --- add ftlib sources and compile them as a sub-CMake project ---
add_subdirectory(ftlib)

# --- Set the path to the root of wxWidgets
set(wxWidgets_ROOT_DIR wxWidgets)

# --- wxWidgets header files ---
# include(${wxWidgets_USE_FILE})
include_directories(wxWidgets/include)

# --- file tracer source files ---
add_executable(file_tracer src/hello_world_app.cpp src/hello_world_app.h)

# --- Link against wxWidgets libraries
target_link_libraries(file_tracer ft ${wxWidgets_LIBRARIES})
