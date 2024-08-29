cmake_minimum_required(VERSION 3.2)

macro(inner)
    message("from inner")
    return()
    message("never printed")
endmacro()

function(outer)
    message("from outer before calling inner")
    inner()
    message("also never printed")
endfunction()

outer()


function(outer2)
    message("from outer before calling inner")

    message("from inner")
    return()
    message("never printed")

    message("also never printed")
endfunction()

outer2()

