cmake_minimum_required(VERSION 3.2)

set(myVar "goes here")
message("myVar: " ${myVar})

set(multiLine "First line ${myVar}
Second line with a \"quoted\" word")
message("multiLine: " ${multiLine})

