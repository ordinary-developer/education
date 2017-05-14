Distinguish universal references from rvalue references
=======================================================

Base material
-------------

T&& has two different meanings:
- rvalue reference  
  (they bind only to rvalues, and their primary raison d'etre
   is to identify objects that may be moved from);
- either rvalue reference or lvalue reference  
  (they look like rvalue references in the source code (i.e. T&&),
   but they behave as if they were lvalue references (i.e. T&);
   their dual nature permits them to bind to rvalues (like rvalue
   references) as well as lvalues (like lvalue references),
   they can bind to *const* or non-*const*, to *volatile* or
   non-*volatile* objects, even to objects that are both *const*
   and *volatile*; they can bind to virtually anything - they are 
   *universal references*)

Universal references arise in two contexts:  
(both have the presence of *type deduction*)
- function template parameters;
- auto declarations.

Because universal references are references, they must be initialzied.
The initializer for a universal reference determines wheter it 
represents an rvalue reference or an lvalue reference. If the 
initializer is an rvalue, the universal reference corresponds to an 
rvalue reference. if the initializer is an lvalue, the universal
reference corresponds to an lvalue reference.  
For universal references that are function parameteres, the 
initializer is provided at the call site. 

For a reference to be universal, type deduction is necessary, but
it's not sufficient, the *form* of the reference declaration must
also be correct: it must be precisely *T&&*.

Even the simple presence of a *const* qualifer is enough to 
disqualify a reference from being universal.

If a template contains a function parameter of type T&& it is not
necessarily a universal reference, that is because being in the
template does'nt guarantee the presence of type deduction.

In the std::vector class the function *push_back* assumes an rvalue
reference, and the function *emplace_back* assumes an universal 
reference.


Summary
-------

- if a function template parameter has type T&& for a deduced type T,
  or if an object is declared using auto&&, the parameter or object
  is a universal reference;
- if the form if the type declaration isn't precisely *type&&*, 
  or if type deduction does not occur, *type&&* denotes an rvalue 
  references;
- universal references correspond to rvalue references if they're
  initialized with rvalues; they correspond to lvalue references 
  if they're initialized with lvalues.
