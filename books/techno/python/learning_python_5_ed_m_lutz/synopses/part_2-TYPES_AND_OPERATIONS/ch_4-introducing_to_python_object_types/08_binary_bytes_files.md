binary bytes files
==================

base
----

Python 3.X draws a sharp distinction between text and binary 
data in files: TEXT FILES represent content as normal "str" strings
and perform Unicode encoding and decoding automatically when 
writing and reading data, wile BINARY FILES represent content
as a special "bytes" string and allow you to access file content
unaltered

Python 2.X supports the same dichotomy, but doesn't impose 
it as rigidly, and its tools differ
