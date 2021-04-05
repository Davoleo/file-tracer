cmake_minimum_required(VERSION 3.17)
project(file_tracer)

set(CMAKE_CXX_STANDARD 17)

# --- add ftlib sources and compile them as a sub-CMake project ---
add_subdirectory(ftlib)

# --- Setup wxWidgets library files ---
find_package(wxWidgets 3.1 COMPONENTS core base REQUIRED)

# --- wxWidgets header files ---
include(${wxWidgets_USE_FILE})
# include_directories(wxWidgets/include)

# Extra things
if(WIN32)
    # Include a RC file for windows
    list(APPEND SRC_FILES ../sample.rc)
elseif(APPLE)
    # Add an icon for the apple .app file
    list(APPEND SRC_FILES ../../src/osx/carbon/wxmac.icns)
endif()

# --- file tracer source files ---
set(SRC_FILES src/FileTracer.cpp src/FileTracer.h src/UI/MainWindow.cpp src/UI/MainWindow.h)
add_executable(file_tracer ${SRC_FILES})

# --- Link against wxWidgets libraries
target_link_libraries(file_tracer ft ${wxWidgets_LIBRARIES})
