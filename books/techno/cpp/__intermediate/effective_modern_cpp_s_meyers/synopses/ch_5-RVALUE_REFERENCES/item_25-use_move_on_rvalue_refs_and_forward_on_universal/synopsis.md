Use std::move on rvalue refs, std::foarward on universal
========================================================

Base material
-------------

Rvalue references bind only to objects that are candidates for 
moving; if you have an rvalue reference parameter, you *know* that
the object it's bound to may be moved.

A universal reference *might* be bound to an object that's eligible
for moving; universal references should be cast to rvalues only if
they were initialized with rvalues.

- rvalue references should be *uncoditionally cast* to rvalues
  (via std::move) when forwarding them to other functions,  
  because they're *always* bound to rvalues;
- universal references should be *conditionally cast* to rvalues
  (via std::forward) when forwarding them,  
  because they're only *sometimes* bound to rvalues.

You should avoid using *std::forward* with rvalue references  
you should avoid using *std::move* with universal references, 
because that can have the effect of unexpectedly modifying lvalues
(e.g., local variables).

You can overload function for const lvalues and for rvalues, but
- you must mantain two functions instead of a single template  
  (and if you have n parameters, you must mantina pow(2,n) functions,
   and if you have unlimited count of parameters the problem
   can't be resolved);
- this approach is less efficient than using universal references.

If you want to use the object bound to an rvalue reference or a
universal reference more that once in a single function, and you 
want to make sure that it's not moved from until you are otherwise
done with it, you must apply *std::move* (for rvalue references)
or *std::forward* (for universal references) to only the *final use*
of the reference.

If you're in a function that returns by value, and you're returning
an object bound to an rvalue reference or a universal reference,
you can apply std::move or std::forward when you return the reference.


Copy elision
------------

Compilers may elide the copying (or moving) of a local object in 
a function that returns by value if
- the type of the local object is the same as that returned by
  the function;
- the local objects is what's being returned.


Summary
-------

- apply std::move to rvalue references and std::forward to universal
  references the last time each is used;
- do the same thing for rvalue references and universal references
  being returned from functions that return by value;
- never apply std::move or std::forward to local objects if they would
  otherwise be eligible for the return value optimization.
