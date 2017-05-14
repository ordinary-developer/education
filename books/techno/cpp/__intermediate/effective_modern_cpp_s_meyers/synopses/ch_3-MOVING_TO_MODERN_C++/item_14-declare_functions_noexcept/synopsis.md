Declare functions noexcept if they won't emit exceptions
========================================================

Base material
-------------

#### Wide contract

A fuction with a wide contract has no preconditions;
such function may be called regardless of the state of the program,
and it imposes no constraints on the arguments that the caller
pass it   
(this doesn't legitimize programms whose behavior is already
 undefined; for example, "std::vector::size" has a wide contract,
 but it doesn't require that it behave reasonably if you invoke it
 on a random chunk of memory that you've cast to a "std::vector";
 the result of the cast is undefined, so there are no behavioral
 guarantees for the program containing the cast).

Functions with wide contracts never exhibit undefined behavior.


#### Narrow contract

Functions without wide contracts have narrow contracts; 
for such functions, if a precondition is violated, 
results are undefined.


Summary
-------

- *noexcept* is part of a function's interaface, and that means
  that callers may depend on it;
- *noexcept* functions are more optimizable than non-noexcept ones;
- *noexcept* is particularly valuable for the move operations, swap,
  memory deallocation functions, and destructors;
- most functions are exception-neutral rather than *noexcept*.
