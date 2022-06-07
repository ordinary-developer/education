cmake_minimum_required(VERSION 3.2)

set(myVar foo)
message("parent (before): myVar = ${myVar}")
add_subdirectory(sub)
message("parent (after): myVar = ${myVar}")

