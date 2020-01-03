cmake_minimum_required(VERSION 3.2)

if(1.2 VERSION_EQUAL 1.2.0)
    message("1.2 VERSION_EQUAL 1.2.0")
else()
    message("no 1.2 VERSION_EQUAL 1.2.0")
endif()

if(1.2 VERSION_LESS 1.2.3)
    message("1.2 VERSION_LESS 1.2.3")
else()
    message("no 1.2 VERSION_LESS 1.2.3")
endif()

if(1.2.3 VERSION_GREATER 1.2)
    message("1.2.3 VERSION_GREATER 1.2")
else()
    message("no 1.2.3 VERSION_GREATER 1.2")
endif()

if(2.0.1 VERSION_GREATER 1.9.7)
    message("2.0.1 VERSION_GREATER 1.9.7")
else()
    message("no 2.0.1 VERSION_GREATER 1.9.7")
endif()

if(1.8.2 VERSION_LESS 2)
    message("1.8.2 VERSION_LESS 2")
else()
    message("no 1.8.2 VERSION_LESS 2")
endif()

