Familiarize yourself with perfect forwarding failure cases
==========================================================

Base material
-------------

"Forwarding" just means that one function passes - *forwards* -
its parameters to another function. The goal is for the second
function (the one being forwarded to) to receive the same objects
that the first function (the one doing forwarding) received.

That rules out by-value parameters, because they're copies of what
the original caller passed in. 

Pointer parameters are also ruled out, because we don't want to force
callers to pass pointers.

When it comes to general-purpose forwarding, we'll be dealing with
parameters that are references.

*Perfect forwarding* means we don't just forward objects, we also 
forward their salient characteristics: their types, whether they're
lvalues or rvalues, and whether they're const or volatile.
In conjunction with the observation that we'll be dealing with
reference parameters, this implies that we'll be using universal
references, because only universal reference parameters encode 
information about the lvalueness and rvalueness of the arguments
that are passed to them.


Kinds of arguments that can't be perfect-forwarded
--------------------------------------------------

- *braced initializers*  
  perfect forwarding fails when either of the following occurs:
  - compilers are unabled to deduce types;
  - compilers deduce the "wrong" type;
- *0 or NULL as null pointers*  
  when you try to pass 0 or NULL as a null pointer to a template,
  type deduction goes awry, deducing an integral type (typically int)
  instead of a pointer type for the argument you pass;
  the result is that neither 0 nor NULL can be perfect-forwarded as
  a null pointer. The fix is easy, however: pass "nullptr" instead
  of 0 or NULL;
- declaration-only integral static const data members;
- overloaded function names and template names;
- bitfilds.


Summary
-------

- perfect forwarding fails when template type deduction fails or when
  it deduces the wrong type;
- the kinds of arguments that lead to perfect forwardnig failure are
  braced initializers, null pointers expressed as 0 or NULL,
  declaration-only integral const static data members, template
  and overloaded function names, and bitfields.
