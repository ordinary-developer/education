cmake_minimum_required(VERSION 3.2)

set(myVar abc)
unset(myVar)

message("myVar: " ${myVar})

