cmake_minimum_required (VERSION 2.6)
project (Tutorial)

# version number
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# option for lib using
option (USE_MYMATH
        "use tutorial provided math implementation" ON)

# check function existence
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

# pass CMake settings to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

include_directories("${PROJECT_BINARY_DIR}")

if (USE_MYMATH)
    include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory (MathFunctions)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)


add_executable(Tutorial tutorial.cpp)    
target_link_libraries(Tutorial ${EXTRA_LIBS})

# installation
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
         DESTINATION include)

# tests
include(CTest)
add_test(TutorialRuns Tutorial 25)

add_test (TutorialComp25 Tutorial 25)
set_tests_properties( 
  TutorialComp25 PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")

add_test (TutorialNegative Tutorial -25)
set_tests_properties (
  TutorialNegative PROPERTIES PASS_REGULAR_EXPRESSION "-25 is -nan")

add_test (TutorialSmall Tutorial 0.0001)
set_tests_properties (
  TutorialSmall PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")

add_test (TutorialUsage Tutorial)
set_tests_properties (
  TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")

# CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
     "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include (CPack)
