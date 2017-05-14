strings
=======

strings
-------

strings are used to record both textual information as well
as arbitrary collections of bytes
 

sequence operations
-------------------

as sequences, strings suppport operations that ussume a positional
ordering amount items

- len(s)  -> gets the length of the string
- s[i]    -> indexing expression
  Positive indexes count from the left
  Negative indexes count back from the right
- s[i:j]  -> extracts an entire section (slice) in a single step
  s[1:]   - Everyting past the first (1:len(s))  
  s       - s itself hasn't changed  
  s[0:3]  - everyting but the last  
  s[:3]   - same as s[0:3]  
  s[:-1]  - Everything but the last again, but simpler (0:-1)  
  s[:]    - All of s as a top-level copy (0:len(s)   
            (first index inlusive, second not)
 - +     -> concatenation
 - *     -> repetion


immutability
------------- 

strings are immutable in Python - they cannot be changed in place
after they are created

numbers, strings and tuples are immutable;
lists, dictionaries, and sets are not.
  

type-specific methods
---------------------

- find(str)  
  returns the offset of the passed-in substring
  or (-1) if it is not present
 
- replace(replaceble_str, new_str)  
  performs global searches and replacments

- split(delimiter)  
  splits a string into substrings on a delimiter      

- upper()  
  converts to upper case

- isalpha()  
  tests whether a string is a letter
 
- isdigit()  
  tests whether the string is a digit

- rstrip()  
  strips whitespace characters off the end of the string


getting help
------------

- dir(s)  
  returns a list of all the attributes 
  available for any object passed to it

- help(s.replace)  
  returns the description of the method

both "dir" and "help" also accept as arguments either a real object,
or the name of a data type (like "str", "list", and "dict")
   

other ways to code strings
--------------------------

Python allows strings to be enclosed in single 
or double quote characters - they mean the same
but allow the other type of quote to be embedded with an escape

Python also allows multiline string literals 
enclosed in triple quotes (single or double)


unicode strings
---------------

in Python 3.X, the normal "str" string handles Unicode text
(including ASCII, which is just a simple kind of Unicode);
a distinct "bytes" string type represents raw byte values
(includeing media and encoded text);
and 2.X Unicode literals are supported in 3.3 and later
(they are treated the same as normal 3.X "str" strings)

in Python 2.X, the normal "str" string handles both 8-bit 
character strings (including ASCII text) and raw byte values;
a distinct "unicode" string type represents Unicode text;
and 3.X bytes literals are supported in 2.6 and later
(they are treated the same as normal 2.X "str" strings).

formally, in both 2.X and 3.X, non-Unicode strings 
are sequences of 8-bit bytes 
that print with ASCII characters when possible, 
and Unicode strings  are  seqencees of Unicode code points -
identyfing numbers for characters, which do not necessarily map 
to single bytes when encoded to files or stored in memory

both 3.X and 2.X also support the "bytearray" string type,
which is essentially a "bytes" string (a "str" in 2.X)
that supports most of the list objct's in-place 
mutalbe change operations

both 3.X and 2.X also support coding non-ASCII characters
with \x hexadecimal  short \u and long \U Unicode escapes

what these values mean and how they are used 
differs between text strings, 
which are the normal string in 3.X and Unicode in 2.X,
and byte strings, which are bytes in 3.X 
and the normal string in 2.X;
all these escapes can be used to embed actual Unicode
code-point ordinal-value integers in text strings;
by contrast, byte strings use only \x  hexadecimal escapes 
to embed the encoded form of text, not its decoded code point values

Python 2.X allows its normal and Unicode strings to be mixed
in expressions as long as the normal string is all ASCII;
Python 3.X never allows its normal and byte strings 
to mix without explicit conversion

apart from these string types, Unicode processing mostly reduces
to transferring text data to and from files text is encoded
to bytes when stored in a file, and decoded into characters
(a.k.a. code points) when read back into memory;
once it is loaded, we usually process text 
as strings in decoded form only

 
pattern matching
----------------
 
the "re" module supports pattern-based text processing
