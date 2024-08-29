cmake_minimum_required(VERSION 3.2)

function(func resultVar1 resultVar2)
    set(${resultVar1} "first result" PARENT_SCOPE)
    set(${resultVar2} "second result" PARENT_SCOPE)
endfunction()

func(myVar otherVar)
message("myVar: ${myVar}")
message("otherVar: ${otherVar}")

