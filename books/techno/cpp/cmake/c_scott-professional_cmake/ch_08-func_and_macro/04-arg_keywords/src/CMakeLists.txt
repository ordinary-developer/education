cmake_minimum_required(VERSION 3.2)

macro(dangerous1)
    foreach(arg in LISTS ARGN)
        message("argument: ${arg}")
    endforeach()
endmacro()

function(func1)
    dangerous1(1 2)
endfunction()

func1(3)


macro(dangerous2)
    foreach(arg in LISTS ${ARGN})
        message("argument: ${arg}")
    endforeach()
endmacro()

function(func2)
    dangerous2(1 2)
endfunction()

func2(3)    


function(func3)
    foreach(arg IN LISTS ARGN)
        message("argument: ${arg}")
    endforeach()
endfunction()

func3(1 2)

