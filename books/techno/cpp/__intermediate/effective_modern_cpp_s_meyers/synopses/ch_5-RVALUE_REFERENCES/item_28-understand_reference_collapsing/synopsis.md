Understand reference collapsing
===============================


Encoding mechanism
------------------

for the template
```cpp
template <typename T>
void func(T&& param);
```

The deduced template parameter T will encode whether the argument
passed to "param" was an lvalue or an rvalue.

- when an lvalue is passed as an argument, "T" is deduced to be an
  lvalue reference;
- when an rvalue is passed, "T" is deduced to be a non-reference.


Reference collapsing
--------------------

References to references are illegal in C++.

You are forbidden from declaring references to references, but 
compilers may produce them in particular contexts, template 
instantiations being among them.
When compilers generate references to references, reference collapsing
dictates what heppens next.

There are two kinds of references (lvalue and rvalue), so there are 
four possible reference-reference combinations (lvalue to lvalue,
lvalue to rvalue, rvalue to lvalue, and rvalue to rvalue).

If a reference to a reference arises in a context where this is
permitted (e.g., during tepmlate instantiation), the references 
collapse to a single reference according to this rule:
**if either reference is an lvalue reference, the result is an lvalue
reference; otherwise (i.e., if both are rvalue references) the result
is an rvalue reference**.

Teference collapsing occurs in four contexts:
- template instantiation;
- type generation for "auto" variables;
- generation and use of "typedef"s and alias declarations  
  (if, during creation or evaluation of a typedef, references to
   references arise, reference collapsing intervenes to eliminate 
   them);
- use of "decltype"  
  (if, during analysis of a type involving "decltype", a reference
   to a reference arises, reference collapsing will kick in 
   to eliminate it).


Univeral reference redefinition
-------------------------------

A universal reference isn't a new kind of reference, it's actually
an rvalue reference in a context where two conditions are satisfied:
- *type deduction distinguishes lvalues from rvalues*  
  lvalues of type T are deduced to have type T&, while rvalue of 
  type T yield T as their deduced type;
- *reference collapsing occurs*.


Summary
-------

- reference collapsing occurs in four contexts:
  template instantiation, "auto" type generation, creation and use of
  "typedef"s and alias declarations, and "decltype";
- when compilers generate a reference to a reference in a reference
  collapsing context, the result becomes a single reference; if either
  of the original references in an lvalue reference, the result is an
  lvalue reference, otherwise it's an rvalue reference;
- universal references are rvalue references in contexts where type
  deduction distinguishes lvalues from rvalues and where reference
  collapsing occurs.
