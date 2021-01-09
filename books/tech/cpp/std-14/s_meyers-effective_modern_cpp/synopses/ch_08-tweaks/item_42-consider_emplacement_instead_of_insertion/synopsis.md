Consider emplacement instead of insertion
=========================================

Base material
-------------

Insertion functions take objects to be inserted, 
while emplacement functions take consturctor arguments for objects
to be inserted.

If all the following are true, emplacement will almost certainly 
outperform insertion:
- the value being added is constructed into the container, 
  not assigned;
- the argument type(s) being passed differ from the type 
  held by the container;
- the container is unlikely to reject the new value as a duplicate.


```cpp
std::regex r1 = nullptr;
std::regex r2(nullptr);
```

The syntax used to initialize r1 (employing the uquals sign)
corresponds to what is known as copy initialization.
The syntax used to initialize r2 (with the parentheses,
although braces may be used instead) 
yields what is called direct initialization.
Copy initialization is not permitted to use *explict* constructors.
Direct initialization is.


Summary
-------

- in principle, emplacement functions should sometimes
  be more efficient than their insertion counterparts,
  and they should never be less efficient;
- in practice, they're most likely to be faster when
  1. the value being added it constructed into the container,
      not assigned;
  2. the argument type(s) passed differ from the type
      held by the container;
  3. the container won't reject the value being added 
     due to it being a duplicate.
- emplacement functions may perform type convertions 
  that would be rejected by insertion functions.
