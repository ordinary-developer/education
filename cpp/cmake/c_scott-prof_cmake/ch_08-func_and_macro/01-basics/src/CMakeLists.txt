cmake_minimum_required(VERSION 3.2)

function(print_me)
    message("hello from inside a function")
    message("all done")
endfunction()

print_me()

