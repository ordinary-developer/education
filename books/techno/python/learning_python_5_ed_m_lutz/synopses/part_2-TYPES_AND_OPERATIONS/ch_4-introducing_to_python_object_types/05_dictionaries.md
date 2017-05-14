dictionaries
============

base
----

dictionaries in Python are not sequences at all,
but are instead known as mappings
 
mappings store objects by key

dictionaries are mutable
 
assignments to new dictionary keys create those keys

we can make dictionaries by passing to the "dict" type name
either keyword arguments 
(a special name=value syntax in function calls),
or the result of zipping together sequences of keys and values 
obtained at runtime


missing keys: if tests
----------------------

the dictionary "in" membership expression allows us
to query the existence of a key
 
there are other ways to avoid accessing nonexistent keys
in a dictionary
- the "get" method, a conditional index with a default
- the "if/else" ternary expression


sorting keys: for loops
-----------------------

we can get the keys of a dictionary in a sorted order
by using the "sorted" function;  
the parameter must be your dictionary


iteration and optimization
--------------------------


an object is iterable if it is either 
a physically stored sequence in memory, or an object 
that generates one item at a time  in the context
of an iteration operation - a sort of "virtual" sequence

More formally, both types of objects are considered iterable 
because they support the iteration protocol -
they respond to the "iter" call with an object 
that advances in response to "next" calls 
and raises an exception when finished producing values
