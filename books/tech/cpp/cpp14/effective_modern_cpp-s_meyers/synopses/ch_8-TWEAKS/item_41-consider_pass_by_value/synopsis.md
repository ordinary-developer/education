Consider pass by value for copyable parameters that are cheap to move and always copied
=========================================================================

Base material
------------

- you should only consider using pass by value;
- consider pass by value only for copyable parameters;
- pass by value is worth considering only for parameters
  that are cheap to move;
- you should consider pass by value only for parameters 
  that are always copied.


Summary
-------

- for copyable, cheap-to-move parameters that are always copied,
  pass by value may be nearly as efficient as pass by reference,
  it's easier to implement, and it can generate less object code;
- copying parameters via construction may be significantly 
  more expensive than copying them via assignment;
- pass by value is subject to the slicing problem,
  so it's typically inappropriate for base class parameter types.

