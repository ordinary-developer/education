cmake_minimum_required(VERSION 3.2)

set(myVar foo)
message("parent (before): myVar = ${myVar}")
message("parent (before): childVar = ${childVar}")

add_subdirectory(sub)

message("parent (after): myVar = ${myVar}")
message("parent (after): childVar = ${childVar}")

