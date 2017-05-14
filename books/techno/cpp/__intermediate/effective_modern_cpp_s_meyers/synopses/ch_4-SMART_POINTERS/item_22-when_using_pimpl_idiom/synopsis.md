When using Pimpl Idiom, define special member functions in the 
implementation file
===============================================================

Base material
-------------

**Pimpl Idiom** is the technique whereby you replace the data members
of a class with a pointer to an implementation class (or struct),
put the data members that used to be in the primary class into the
implementation class, and access those data members indirectly 
through the pointer.

It can be used because pointers to an incomplete type may be declared
(and an implementation struct here is an incomplete type).


Summary
-------

- the *Pimpl Idiom* decreases build times by reducing compilation
  dependencies between class clients and class implementations;
- for std::unique_ptr pImpl pointers, declare special member functions
  in the class header, but implement them in the implementation file;
  do this even if the default function implementations are acceptible;
- the obove advice applies to unique_ptr, but not to shared_ptr.

