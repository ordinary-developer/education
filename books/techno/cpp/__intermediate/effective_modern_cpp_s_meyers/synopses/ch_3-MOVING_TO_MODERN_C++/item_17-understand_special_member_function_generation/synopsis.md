Understand special member function generation
=============================================

Base material
-------------

C++ has six special member functions:

- default constructor
  (generated only if the class contains no user-declared 
   constructors at all);
- destructor
  (desctructors are "noexcept" by default,
   they are virtual only if a base class destructor is virtual);
- copy constructor
  (behavior: memberwise copy construction of non-static data members;
   generated only if the class lacks 
   a user-declared copy constructor;
   is independent from copy assignment operator declaring;
   deleted if the class declares a move operation;
   generation of this function in a class with a user-declared
   copy assignment operator or destructor is deprecated);
- copy assignment operator
  (behavior: memberwise copy assignment of non-static data members;
   generated only if the class lacks a user-declared copy assignment
   operator;
   is independent from copy constructor declaring;
   deleted if the class declares a move operation;
   generation of this function is a class with a user-defined
   copy constructor or desctructor is deprecated);
- move constructor and move assignment operator (C++11)
  (each performs memberwise moving of non-static data members;
   generated of the class contains no user-declared copy operations
   and move operations, and destructor;
   these two operations are not independent;
   memberwise move consists of move operations on data members
   and base classes that support move operations, 
   but a copy operation for those that don't).

Generated special member functions are implicitly "public" 
and "inline".

Generated functions are nonvirtual unless the function in question
is a destructor in a derived class inheriting from a base class
with a virtual destructor.

Member function templates never suppress generation of special
member functions.

"Rule of three":
if you declare any of a copy constructor, copy assignmet operator,
or destructor, you should declare all three.
