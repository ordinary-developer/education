cmake_minimum_required(VERSION 3.2)

if(WIN32)
    message("WIN32 platform")
else()
    message("no WIN32 platform")
endif()

if(MSVC)
    message("MSVC platform")
else()
    message("no MSVC platform")
endif()

if(CMAKE_GENERATOR STREQUAL "Xcode")
    message("Xcode generator")
else()
    message("no Xcode generator")
endif()

option(BUILD_CUSTOM "enable custom build") 
if(BUILD_CUSTOM)
    message("build custom")
else()
    message("no build custom")
endif()

