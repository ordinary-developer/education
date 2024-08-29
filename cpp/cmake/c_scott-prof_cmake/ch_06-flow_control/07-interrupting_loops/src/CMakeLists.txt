cmake_minimum_required(VERSION 3.2)

foreach(outerVar IN ITEMS a b c)
    unset(s)
    foreach(innerVar IN ITEMS 1 2 3)
        list(APPEND s "${outerVar}${innerVar}")
        string(LENGTH s length)
        if (length GREATER 5)
            break()
        endif()

        if(outerVar STREQUAL "b")
            continue()
        endif()
        message("processing ${outerVar}-${innerVar}")
    endforeach()

    message("Accumulated list: ${s}")
endforeach()

