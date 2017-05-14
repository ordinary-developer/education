Prefer alias declarations to "typedef"s
=======================================

Base material
-------------

- "typedef"s don't support templatization, but alias 
  declaration do;
- alias templates avoid the "::type" suffix and, in templates",
  the "typename" prefix often required to refer to "typedef"s;
- C++14 offers alias templates for all the C++11 type traits
  transformations.
