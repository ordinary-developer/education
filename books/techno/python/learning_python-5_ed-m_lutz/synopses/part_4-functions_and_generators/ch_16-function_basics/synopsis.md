Functions basics
================

Coding functions
----------------

Some useful notes about functions in Python:
- 'def' is executable code;
- 'def' creates an object and assigns it to a name  
  (the function name becomes a reference to the function object);
- 'lambda' creates an object but returns it as a result;
- 'return' sends a result object back to the caller;
- 'yield' sends a result object back to the caller,  
  but remembers where it left off;
- 'global' declares module-level variables that are to be assigned;
- 'nonlocal' declares enclosing function variables;
  that are to be assinged  
  (so enclosing functions can serve as a place to retain state -
   information between function calls - 
   without using shared global names);
- arguments are passed by assignment (object reference)  
  (in Python's model the caller and function
   share objects by references, but there is no name aliasing;
   changing an argument name within a function 
   does not also change the corresponding name in the caller,
   but changing passed-in mutable objects in place
   can change objects hared by the caller);
- arguments are passed by position, unless you say otherwise;
- arguments, return values and variables are not declared;

   
'def' statements
----------------

If the value for a 'return' statement is omitted, 
'return' sends back a *None*.
The function without a 'return' statement also returns the None.


