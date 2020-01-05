cmake_minimum_required(VERSION 3.2)

function(func arg)
    if(DEFINED arg)
        message("function arg is a defined variable")
    else()
        message("function arg is NOT a defined variable")
    endif()
endfunction()

macro(macr arg)
    if(DEFINED arg)
        message("macro arg is a defined variable")
    else()
        message("macor arg is NOT a defined variable")
    endif()
endmacro()

func(foobar)
macr(foobar)

