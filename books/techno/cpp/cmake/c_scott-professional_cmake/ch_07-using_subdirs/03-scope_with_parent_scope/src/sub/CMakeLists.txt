cmake_minimum_required(VERSION 3.2)

message("child (before): myVar = ${myVar}")
set(localVar bar)
set(myVar ${localVar} PARENT_SCOPE)
message("child (after): myVar = ${myVar}")

