cmake_minimum_required(VERSION 3.2)

set(myList a b c)
list(LENGTH myList len)
message("length = ${len}")


list(GET myList 2 1 letters)
message("letters = ${letters}")


set(myList a b c)
list(APPEND myList d e f)
message("myList (first) = ${myList}")


list(INSERT myList 2 X Y Z)
message("myList (second) = ${myList}")

set(myList a b c d e)
list(FIND myList d index)
message("index = ${index}")


set(myList a b c d d e e)

list(REMOVE_ITEM myList e)
message("myList (first) = ${myList}")

list(REMOVE_AT myList 0)
message("myList (second) = ${myList}")

list(REMOVE_DUPLICATES myList)
message("myList (third) = ${myList}")


set(myList a b c d e f)

list(REVERSE myList)
message("myList (first) = ${myList}")

list(SORT myList)
message("myList (second) = ${myList}")

