Avoid overloading on universal references
=========================================

Base material
-------------

Functions taking universal references are the greediest functions
in C++. They instantiate to create exact matches for almost any type
of argument.
This is why combining overloading and universal references is almost
always a bad idea: the universal reference overload vacuums up far
more argument types than the developer doing the overloading
generally expects.

One of the overload-resolution rules in C++ it that in situations
where a template instantiantiation and a non-template function
(i.e., a "normal" function) are equally good matches for a function
call, the normal function is preferred.

An easy way to topple into this pit is to write a perfect forwarding
constructor.


Summary
-------

- overloading on universal references almost always leads to the
  universal reference overload being called more frequently than
  expected;
- perfect-forwarding constructors are especially problematic,
  because they're tipically better matches than copy constructors
  for non-const lvalues, and they can hijack derived class calls
  to base class copy and move constructors.
