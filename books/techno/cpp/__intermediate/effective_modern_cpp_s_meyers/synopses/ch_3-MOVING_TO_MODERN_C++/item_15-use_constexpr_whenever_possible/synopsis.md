Use constexpr whenever possible
===============================

*constepxr* with objects
------------------------

*constexpr* objects have values have values that are known 
at compile time (translation time).

Integral values that are constant and known during compilation
can be used in contexts where C++ requires an
integral constant expression 
(specification of array sizes, integral template arguments
(including lengths of std::array objects), enumerator values,
alignment specifiers, and more). 

Note that *const* objects need not be initialized with values
known during compilation.

All *constexpr* are *const*, but not all *const* objects 
are *constexpr*.

If you want compilers to guarantee that a variable has a value
that can be used in contexts requiring compile-time constants,
use *constexpr*, not *const*.


*constexpr* with functions
--------------------------

- *constexpr* functions can be used in contexts that demand
  compile-time constants  
  (if the values of the arguments you pass to a *constexpr* function
   in such a context are known during compilation, the result will
   be computed during compilation
   if any of the arguments' values is not known during compilation,
   your code will be rejected);
- when a *constexpr* function is called with one or more values that
  are not known during compilation, it acts like a normal function,
  computing its result at runtime, 
  this means you don't need two functions to perform the same
  operation, one for compile-time constants and one for all other
  values.

 
Summary
-------

- *constexpr* objects are *const* and are initialized with values 
  known during compilation;
- *constexpr* functions can produce compile-time results 
  when called with arguments whose values are known 
  during compilation;
- use *constexpr* whenever possible:  
  *constexpr* objects and functions may be used in a wider range 
  of contexts than non-constexpr objects and functions;
- *constexpr* is part of an object's or function's interface.

