cmake_minimum_required(VERSION 3.2)

function(func)
    set(prefix ARG)
    set(noValues ENABLE_NET COOL_STUFF)
    set(singleValues TARGET)
    set(multiValues SOURCES IMAGES)

    include(CMakeParseArguments)
    cmake_parse_arguments(${prefix}
                          "${noValues}"
                          "${singleValues}"
                          "${multiValues}"
                          ${ARGN})

    message("option summary:")
    foreach(arg IN LISTS noValues)
        if(${${prefix}_${arg}})
            message(" ${arg} enabled")
        else()
            message(" ${arg} disabled")
        endif()
    endforeach()

    foreach(arg IN LISTS singleValues multiValues)
        message(" ${arg} = ${${prefix}_${arg}}")
    endforeach()
endfunction()


func(SOURCES foo.cpp bar.cpp TARGET myApp ENABLE_NET)
func(COOL_STUFF TARGET dummy IMAGES here.png there.png gone.png)

