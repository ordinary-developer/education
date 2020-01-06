cmake_minimum_required(VERSION 3.2)

macro(dangerous)
    foreach(arg in LISTS ARGN)
        message("argument: ${arg}")
    endforeach()
endmacro()

function(func1)
    dangerous(1 2)
endfunction()

func1(3)

function(func2)
    foreach(arg IN LISTS ARGN)
        message("argument: ${arg}")
    endforeach()
endfunction()

func2(1 2)

