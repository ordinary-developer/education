Assume that move operations are note prsent, not cheap, and not used
====================================================================

Base material   
-------------

Many types fail to support move semantics:
- for types in your applications where no modifications for C++11
  (only old C++98 code) have been made, the existence of move 
  support in your compilers is likely to do you little good;
  true, C++11 is willing to generate move operations for classes 
  that lack them, but that happens only for classes declaring
  no copy operations, move operations, or destructors;
- data members or base classes of types that have disabled moving
  (e.g., by deleting the move operations) will also suppres
  compiler-generated move operations;
- for types without explicit support for moving and that don't
  qualify for compiler-generated move operations, there is no reason
  to expect C++11 to deliver andy kind of performance improvement
  over C++98.

Data for a std::array's contents are stored directly in the 
std::array object. Thus moving from one std::array to another runs
in linear time because all elements must be moved.

There are thus several scenarios in which C++11's move semantics 
do you no good:
- *no move operations:*   
  the object to be moved from fails to offer move operations;
  the move request therefore becomes a copy request;
- *move not faster:*  
  the object to be moved from has move operations that are no faster
  than its copy operations;
- *move not usable:*
  the context in which the moving would take place requies a move
  operations that emits no exception, but that operation isn't 
  declared noexcept.

It's worth mentioning, too, another scenario where move semantics
offers no efficiency gain:
- *source object is lvalue:*  
  with very few exception only rvalues may be used as the source
  of a move operation.


Summary
-------

- assume that move operations are not present, not cheap, 
  and not used;
- in code with known types or support for move semantics, there is
  no need for assumptions.

