cmake_minimum_required(VERSION 3.2)

set(multiLine [[
First line
Second line
]])
message("multiLine: " ${multiLine})

# with brackets
set(shellScript [=[
#!/bin/bash

[[ -n "${USER}" ]] && echo "Have USER"
]=])
message("shellScript: " ${shellScript})

# without brackets
set(shellScript
"#!/bin/bash

[[ -n \"\${USER}\" ]] && echo \"Have USER\"")
message("shellScript: " ${shellScript})
