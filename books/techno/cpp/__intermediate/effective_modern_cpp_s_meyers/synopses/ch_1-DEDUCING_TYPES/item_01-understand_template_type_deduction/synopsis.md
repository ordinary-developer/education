# Undestand template type deduction

Base material
=============

The next code sample will be useful 
for our discussing of type deducing:

```cpp
template <typename T>
void f(ParamType parameter);

f(expr);
```


1 - *ParamType* is a reference or pointer, but not universal reference
----------------------------------------------------------------------
- if *expr*'s type is a reference, (but not universal reference) 
  ignore the reference part (in the *expr*);
- then pattern-match *expr*'s type against *ParamType*
  to determine *T*.


2 - *ParamType* is a universal Reference
----------------------------------------
- if *expr* is a lvalue, both *T* and *ParamType* are deduced
  to be lvalue references;
- if *expr* is a rvalue, the *normal* (case 1) rules apply.


3 - *ParamType* is neither a pointer nor a reference
----------------------------------------------------
- if *expr*'s type is a reference, ignore the reference part;
- if *expr* is "const", ignore that, too;
- if *expr* is "volatile", also ignore that.

