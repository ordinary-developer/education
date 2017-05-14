Declare overriding functions override
=====================================

Base material
-------------

For overriding to occur, several requirements (in C++98) must be met:
- the base class function must be virtual;
- the base and derived function names must be identical
  (except the case of destructors);
- the parameter types of the base and derived functions 
  must be identical;
- the "const"ness of the base and derived functions 
  must be identical;
- the return type and exception specifications of the base 
  and derived functions must be compatible.

in C++11 one more requirement must be met:

- the function's reference qualifiers must be identical  
  (they make it possible to limit use of a member functions
   to lvalues only or rvalues only; member functions need not
   be virtual to use them).


Summary
-------

- declare overriding functions override;
- member function reference qualifiers make it possible 
  to treat lvalue and rvalue objects (*this) differently.
