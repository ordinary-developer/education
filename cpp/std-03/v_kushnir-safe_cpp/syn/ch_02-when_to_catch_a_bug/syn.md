# Chapter 2 - WHEN TO CATCH A BUG

Rules for the chapter
---------------------

- prohibit implicit type convertions: 
  declare constructors taking one parameter with the keyword *explicit*
  and avoid conversion operators;
- use different classes for different data types;
- do not use *enums* to create *int* constants,
  use them to create new types.

