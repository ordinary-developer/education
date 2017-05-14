constexpr function
==================

constant expressions
--------------------
There are few things you can only do with constant expressions:
- specify the bounds of an array;
- specify the value of a nontype template parameter;
- provide an initializer for a "static const" class data member 
  of integral type in the class definition;
- provider an intializer for a built-in type or aggregate
  that can be used for static initialization.

Static initialization like in the last issue can be used
to avoid order-of-initialization problems and race conditions.


constexpr and user-defined types
--------------------------------
For a class type to be classified as a literal type, 
the following must all be true:
- it must have a trivial copy constructor;
- it must have a trivial destructor;
- all non-static data members and base classes must be trivial types;
- it must have either a trivial default constructor 
  or a constexpr constructor other than the copy constructor.

Objects of a literal type initialized with a constant expression
are statically initialized, and so their initialization if free
from race conditions and initialization order issues.

This covers constructors too. If the constructor is declared "constexpr"
and the constructor parameters are constant expressions, 
the initialization is constant initialization 
and happens as part of the static initialization phase.


constexpr function requirements
-------------------------------
The requirements for a constexpr function are as follows:
- all parameters must be of a literal type;
- the return type must be a literal type;
- the function body must consist of a single return statement;
- the expression in the return statement
  must qualify as a constant expression;
- any constructor or conversion operator
  used to construct the return value from the epxression
  must be constexpr

For constexpr class member functions there are additional requirements:
- constexpr member functions can’t be virtual;
- the class for which the function is a member must be a literal type.

The rules are different for constexpr constructors:
- the constructor body must be empty;
- every base class must be initialized;
- every non-static data member must be initialized;
- any expressions used in the member initialization list
  must qualify as constant expressions.
- the constructors chosen for the initialization 
  of the data members and base classes must be constexpr constructors;
- any constructor or conversion operator
  used to construct the data members and base classes
  from their corresponding initialization expression must be constexpr.

