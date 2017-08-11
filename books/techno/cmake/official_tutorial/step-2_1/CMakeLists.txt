cmake_minimum_required (VERSION 2.6)
project (Tutorial)

# version number
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# pass CMake settings to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_BINARY_DIR}/MathFunctions")
add_subdirectory(MathFunctions)

add_executable(Tutorial tutorial.cpp)    
target_link_libraries(Tutorial MathFunctions)
