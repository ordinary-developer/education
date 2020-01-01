cmake_minimum_required(VERSION 3.2)

set(myVar foo)
set(result ${myVar})
set(myVar bar CACHE STRING "")

set(result ${myVar})
message("result: " ${result})

set(myVar fred)
set(result ${myVar})
message("result: " ${result})

