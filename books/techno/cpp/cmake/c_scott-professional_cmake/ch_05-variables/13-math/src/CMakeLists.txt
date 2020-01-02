cmake_minimum_required(VERSION 3.2)

set(x 3)
set(y 7)
math(EXPR z "(${x} + ${y}) / 2")
message("result = ${z}")

