cmake_minimum_required(VERSION 2.8)

set(myVar a b c)
message("myVar: " ${myVar})

set(myVar a;b;c)
message("myVar: " ${myVar})

set(myVar "a b c")
message("myVar: " ${myVar})

set(myVar a b;c)
message("myVar: " ${myVar})

set(myVar a "b c")
message("myVar: " ${myVar})

