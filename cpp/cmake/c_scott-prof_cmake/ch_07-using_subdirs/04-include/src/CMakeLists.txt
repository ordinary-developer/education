cmake_minimum_required(VERSION 3.2)

add_subdirectory(sub)
message("====")
include(sub/CMakeLists.txt)

