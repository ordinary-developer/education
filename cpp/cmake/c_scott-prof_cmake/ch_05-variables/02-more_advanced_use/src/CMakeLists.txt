cmake_minimum_required(VERSION 3.2)

set(foo ab)
message("foo: " ${foo})

set(bar ${foo}cd)
message("bar: " ${bar})

set(baz ${foo} cd)
message("baz: " ${baz})

set(myVar ba)
message("myVar: " ${myVar})

set(big "${${myVar}r}ef") # big = "${bar}ef"
message("big: " ${big})

set(${foo} xyz) # ab = xyz
message("ab: " ${${foo}})

set(bar ${notSetVar})
message("bar: " ${bar})

