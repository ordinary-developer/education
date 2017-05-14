# RValue references

rvalue references
-----------------

There are two types of references in C++:
- lvalue references (references to lvalues)  
  the term lvalue refers to things that can be o the left side of an
  assignment expression - names objects, objects allocated on the
  statck or heap, or members of other objects (thinsg with a defined
  storage location)
- rvalue references (references to rvalues)  
  the term rvalue refers to things that can occur only on the right
  side of an assignment expression - literals and temporaries


Move semantics
--------------

Rather that copying the contents of an rvalue parameter, you can just
move the contents.

This can be beneficial when you wish to move the parameter value into 
a local or member variable without copying, because although an rvalue
reference parameter can bind to rvalues, within the function itself
it is treated as an lvalue


Rvalue references and function templates
----------------------------------------

When you use rvalue references for parameters to a function template
if the function parameter is an rvalue to a template parameter,
automatic template argument type deduction deduces the type to be an
lvalue reference if an lvalue is supplied or a plain unadorned type 
if an rvalue is supplied.

```cpp
template <typename T>
void foo(T&& t) 
{ }
```
If you call a function with an rvalue, then T is deduced to be the 
type of the value.
If you call foo with lvalue, T is deduced to be an lvalue reference.


This allows a single function template to accept both lvalue and 
rvalue parameters and is used by the std::thread constructor so that
the supplied callable object can be moved into internal storage rather
than copied if the parameter is an rvalue.