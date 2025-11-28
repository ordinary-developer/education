unicode text files
==================

base
----

to access files containing non-ASCII Unicode text, we simply
pass in an encoding name if the text in the field doesn't match
the default encoding for our platform

in this mode, Python text files automatically encode on writes
and decode on reads per the encoding scheme name you provide
