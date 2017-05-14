lists
=====

lists
-----

lists are positionally ordered collections 
of arbitrarily typed objects, and they have no fixed size;
they are also mutable.


sequene operations
------------------

len(), indexing, concatenation, repeating


type-specific operations
------------------------

the "list" class has the next methods:
- append(element)  
  expands the list's size and inserts an item at the end

- pop(offset)  
  removes an item at a given offset, causing the list to shrink
  (an equivalent is the "del" statement)
  removes the last element when called without parameters
 
- insert()  
  inserts an item at an arbitrary position

- remove(value)  
  removes a given item by value

- extend()  
  add multiple items at the end

- sort()  
  orders the list in ascending fashion by default

- reverse()  
  reverses the list

because lists are mutable, most lists methods also change 
the list object in place, instead of creating a new one

indexing off the end of a list is always a mistake, 
but so is assingning off the end

Python's core data types support arbitrary nesting;
we can a have a lists that contains a dictionary, 
which contains another list, and so on


comprehensions
--------------

list comprehensions are a way to build a new list
by running an expression on each item in a sequence, 
one at a time, from left to right;

lists comprehensions are coded in square brackets 
and are composed of an expression and a looping construct
that share a varialbe name (row, here)

- range(value)  
  a built-in that generates succesive integers.

enclosing a comprehension in parentheses can be used to 
create generators that produce results on demand

the "map" built-in can do similar work, by generating the results
of running items through a function, one at a time and on request

in Python 2.7 adn 3.X, comprehension syntax can also be used 
to create sets and dictionaries
