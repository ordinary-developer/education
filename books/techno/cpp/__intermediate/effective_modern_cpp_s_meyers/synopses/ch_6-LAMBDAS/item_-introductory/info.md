LAMBDAS
=======

Lambda
------

A *lambda expression* is just an expression. 
It's part of the source code.

In the next example
```
std::find_if(container.begin(), container.end(),
             [](int value) { return 0 < value; });
```
the second string is the lambda


Closure
-------

A *closure* is the runtime object created by a lambda. Depending on 
the capture mode, closures hold copies of or references to the
captured data.


Closure class
-------------

A *closure class* is a class from which a closure is instantiated.
Each lambda causes compilers to generate a unique closure class.
The statements inside a lambda become executable instructions in
the member functions of its closure class.


Auxiliary information
---------------------

A lambda is often used to create a closure that's used only as an 
argument to a function. However, closures may generally be copied,
so it's usually possible to have multiple closures of a closure type
corresponding to a single lambda.

It is often important to distinguish what exists during compilation
(lambdas and closure classes) and  what exists at runtime (closures).

