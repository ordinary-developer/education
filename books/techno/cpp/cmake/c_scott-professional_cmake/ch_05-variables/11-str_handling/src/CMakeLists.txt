cmake_minimum_required(VERSION 3.2)

# FIND
set(longStr abcdefabcdef)
set(shortBit def)

string(FIND ${longStr} ${shortBit} fwdIndex)
string(FIND ${longStr} ${shortBit} revIndex REVERSE)

message("fwdIndex = ${fwdIndex}, revIndex = ${revIndex}")


# REPLACE
set(longStr abcdefabcdef)
set(replace def)
set(replaceWith fed)

string(REPLACE ${replace} ${replaceWith} result ${longStr})

message("replaceResult = ${result}")


# REGEX
set(longStr abcdefabcdef)

string(REGEX MATCHALL "[ace]" matchVar ${longStr})
string(REGEX REPLACE "([de])" "X\\1Y" replVar ${longStr})

message("matchVar = ${matchVar}")
message("replVar = ${replVar}")


# SUBSTRING
set(long Str abcdefabcdef)

string(SUBSTRING ${longStr} 3 3 substrVar)

message("substrVar = ${substrVar}")


# LENGTH TOLOWER TOUPPER STRIP
set(longStr abcdefabcdef)

string(LENGTH ${longStr} outVar)
message("length = ${outVar}")

string(TOLOWER ${longStr} outVar)
message("tolower = ${outVar}")

string(TOUPPER ${longStr} outVar)
message("toupper = ${outVar}")

string(STRIP ${longStr} outVar)
message("strip = ${outVar}")

