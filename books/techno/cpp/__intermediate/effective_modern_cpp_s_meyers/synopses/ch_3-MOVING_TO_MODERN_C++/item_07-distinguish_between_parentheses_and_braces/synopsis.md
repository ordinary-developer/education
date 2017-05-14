Distinguish between () and {}
=============================

Pluses
------

Braced initialization may be used in the widest variety of contexts.

A novel feature of braced initialization 
(an initialization with curly braces) is that it prohibits
implicit "narrowing conversions" amoung built-in types.

Braced initialization is immune to C++'s "most vexing parse"
(when you want do default-construct an object, 
 but inadvertently declare a function instread).


Minuses
-------

There is a tangled relashionship among braced initializers,
std::initializer_lists, and constructor overload resolution:
- when an auto-declared variable has a braced initializer,
  the type deduced is "std::initializer_list";
- in constructors calls, parentheses and braces 
  have the same meaning as long as "std::initializer_list" parameters
  are not involved;
- if one or more constructors declare a parameter 
  of type"std::initializer_list", calls 
  using the braced initialization syntax 
  STRONGLY prefer the overloads taking "std::initializer_list"s  
  (if there any way for compilers to construe a call using
  a braced initializer to be to a constructor taking a
  "std::initializer_list", compilers will employ 
  that interpretation);
- if there's no way to convert the types of the arguments 
  in a braced initializer to the type in a "std::initializer_list" do
  compilers fall back on normal overload resolution;
- "{}" mean "no arguments", 
  so you get default construction
  "{{}}" or "({})" mean "empty std::initializer_list", 
  so you get the construction from a "std::initializer_list"
  with no elements;
- std::vector has a non-std::initializer_list constructor  
  (which is called when the caller uses parenthesesd),
  std::vector has a std::initializer_list constructor
  (which is called when the caller uses braces).


Summary
-------

- design your constructors so that the overload called isn't affected
  by whether clients use parentheses or braces;
- choose carefully between parentheses 
   - consistency with C++98 syntactic tradition;
   - avoidance of the auto-deduced-a-std::initializer_list problem;
   - knowledge that their object creation calls won't be 
     inadvertently waylaid by std::initializer_list constructors
     and braces;
   - unrivaled breadth of applicability;
   - prohibition of narrowing conversions;
   - immunity to C++ most vexing parse.

  so pick one approach and apply it consistently.
