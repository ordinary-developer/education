AVOID DEFAULT CAPTURE MODES
===========================

Basic material
--------------

There are two default capture modes in C++11:
- by-reference; 
- by-value.

Default by-reference capture can lead to dangling references.  
Default by-value capture lures you into thinking you're immune
to that problem (you're not), and it lulls you into thinking your
closures are self-containd (they may not be).


By-reference capture
--------------------

A by-reference capture causes a closure to contain a reference to
a local variable or to a parameter that's available in the scope
where the lambda the lambda is defined.  
If the lifetime of a closure created from that lambda exceeds 
the lifetime of the local variable or parameter, the reference in
the closure will dangle.

Long-term, it's simply better software engineering to explicitly list
the local variables and parameters that a lambda depends on.


By-value capture
----------------

In general, default by-value capture ins't the antidangling elixir
you might imagine. The problem is that if you capture a pointer
by value, you copy the pointer into the closures arising from 
the lambda, but you don't prevent code outside the lambda 
from deleting the pointer and causing your copies to dangle.

Captures apply only to non-static local variables 
(including parameters) visible in the scope where the lambda 
is created.

An additional drawback to default by-value captures is that they can
suggest that the corresponding closures are self-contained and  
insulated from changes to data outside the closures.  
In general, that's not true, because lambdas may be dependent not
just on local variables and parameters (which may be captured), but
also on objects with *static storage duration*.  
Such objects are defined at global or namespace scope 
or are declared static inside classes, functioins, or files. 
These objects can be used inside lambdas, but they can't be captured.


Summary
-------

- default by-reference capture can lead to dangling references;
- default by-value capture is susceptible to dangling pointers
  (especially this), and it misleadingly suggests
  that lambdas are self-contained.
