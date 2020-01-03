cmake_minimum_required(VERSION 3.2)

set(who Fred)
if("Hi from ${who}" MATCHES "Hi from (Fred|Barney).*")
    message("${CMAKE_MATCH_1} says hello")
endif()

