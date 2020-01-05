cmake_minimum_required(VERSION 3.2)

message("child (before): myVar = ${myVar}")
message("child (before): childVar = ${childVar}")

set(myVar bar)
set(childVar fuzz)

message("child (after): myVar = ${myVar}")
message("child (after): childVar = ${childVar}")

