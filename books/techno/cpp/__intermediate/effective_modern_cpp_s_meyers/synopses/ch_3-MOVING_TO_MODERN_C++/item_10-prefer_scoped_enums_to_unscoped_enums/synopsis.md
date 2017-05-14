Prefer scoped enums to unscoped enums
=====================================

Base material
-------------

- C++98 style enums are now known as unscoped enums;
- enumerators of scoped enums are visible only within the enum  
  (they convert to other types only with a cast);
- both scoped and unscoped enums support specification 
  of the underlying type  
  (the default underlying type for scoped enums is "int",  
  unscoped enums have no default underlying type);
- scoped enums may always be forward-declared
  (unscoped enums may be forward-declared only if their declaration
  specifies an underlying type).
