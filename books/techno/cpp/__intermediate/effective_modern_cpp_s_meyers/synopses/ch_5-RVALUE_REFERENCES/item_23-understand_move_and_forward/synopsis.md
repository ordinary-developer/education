Understand move and forward
===========================

Preamble
--------

A parameter is always an lvalue, even if its type is an rvalue
reference.

That is, given  
```c++
void f(Widget&& w);
```

The parameter w is an lvalue, even though its type is 
rvalue-reference-to-Widget.


Base material
-------------

*std::move* and *std::forward* are merely functions (actually 
function templates) that perform casts. *std::move* unconditionally
casts its argument to an rvalue, while *std::forward* performs this
cast only if a particulary condition is fulfilled.


std::move
---------

- don't declare objects *const* if you want to be able to move 
  from them; move request on *const* objects are silently transformed
  into copy operations;
- *std::move* not only doesn't actually move anything, it doesn't
  even guarantee that the object it's casting will be eligible to
  be moved; the only thing you know for sure about the result of
  applying *std::move* to an object is that it is an rvalue.


std::forward
------------

*std::forward* is a conditional task: it casts to an rvalue only
if its argument was initialized with an rvalue.


Summary
-------

- *std::move* performs an unconditional cast to an rvalue; in and of
  itself, it doesn't move anything;
- *std::forward* casts its argument to an rvalue only if that 
  argument is bound to an rvalue;
- neither *std::move* nor *std::forward* do anything at runtime.
