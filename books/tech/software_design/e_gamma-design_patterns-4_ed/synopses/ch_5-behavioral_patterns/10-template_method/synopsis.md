TEMPLATE METHOD
===============

Intent
------

Define a skeleton of an algorithm in an operation, deferring some 
steps to subclasses. Template Method lets subclasses redefine certain
steps of an algorithm without changing the algorithm's structure.


Applicability
-------------

The Template Method pattern should be used
- to implement the invariant parts of an algorithms once and leave it
  up to subclasses to implement the behavior that can vary;
- when common behavior among subclasses should be factored and 
  localized in a common class to avoid code duplication;
- to control subclasses extensions 
  (you can define a template method that calls "hook" operations at
   specific points, thereby permitting extensions only at those
   points).


Structure
---------

```
  -------------------------
  | AbstractClass         |
  -------------------------      ----------------------\
  | TemplateMethod() o-----------| ...                  \ 
  | PrimitiveOperation1() |      | PrimitiveOperation1() |
  | PrimitiveOperation2() |      | ...                   |
  -------------------------      | PrimitiveOperation2() |
              ^                  | ...                   |
             / \                 -------------------------
             ---
              |
  -------------------------
  | ConcreteClass         |
  -------------------------
  | PrimitiveOperation1() |
  | PrimitiveOperation2() |
  -------------------------
```


Participants
------------

- **AbstractClass**
  - defines abstract primitive operations that concrete subclasses
    define to implement steps of an algorithm;
  - implements a template method defining the skeleton of an 
    algorithm
    (the template method calls primitive operations as well as
    as operations defined in AbstractClass or those of other 
    objects).
- **ConcreteClass**
  - implements the primitive operations to carry out 
    subclass-specific steps of the algorithm.


Collaborations
--------------

- ConcreteClass relies on AbstractClass to implement the invariant
  steps of the algorithm.


Consequences
------------

It's important for template methods to specify which operations are 
hooks (may be overridden) and which are abstract operations
(must be overridden).


Implementation
--------------

Three implementation issues are worth noting:
- using C++ access control;
- minimizing primitive operations;
- naming conventions.
