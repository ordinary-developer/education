Decorator (Wrapper)
===================

Intent
------

Attach additional responsibilities to an object dynamically. 
Decorators provide a flexible alternative to subclassing for
extending functionality.


Applicability
-------------

Use Decorator
- to add responsibilities to individual objects dynamically and
  transparently, that is, without affecting other objects;
- for responsibilities that can be withdrawn;
- when extension by subclassing is impractical  
  (sometimes a large number of independent extensions are possible
   and would produce an explosion of subclasses to support every
   combination; or a class definition may be hidden or otherwise
   unavailable for subclassing).


Structure
---------

```
          ---------------
          | Component    |<--------------------------
          ---------------                           |
          | Operation()  |                          |
          ----------------                          |
                  ^                                 |                   
                 / \                                |
           ---------------------                    |
           |                   |                    |
 ---------------------  ----------------  component |
 | ConcreteComponent |  | Decorator    |<>-----------
 ---------------------  ----------------    ------------------------\
 | Operation()       |  | Operation() o|----| component->Operation() |
 ---------------------  ----------------    --------------------------
                             ^
                            / \
         ------------------------
         |                      |
---------------------- ----------------------                          
| ConcreteDecoratorA | | ConcreteDecoratorB |                
---------------------- ---------------------- ----------------------\
| Operation()        | | Operation() o------|-|Decorator::Operation()|
---------------------- | AddedBehavior()    | |AddedBehavior();      | 
| addedState         | ---------------------- ------------------------
---------------------
```


Participants
------------

- *Component*
  - defines the interface for objects that can have repsonsibilities
    added to them dynmically.
- *ConcreteComponent*
  - defines an boject to which additional responsibilities can be
    attaced.
- *Decorator*
  - maintains a reference to a *Component* object and defines an
    inteface that conforms to *Component*'s interface.
- *ConcreteDecorator*
   - adds responsibilities to the *Component*.


Collaborations
--------------

- *Decorator* forwards requests to its *Component* object. It may
  optionally perform additional operations before and after 
  forwarding the request.


Consequences
------------
The *Decorator* pattern has at least two key benefits:
- more flexibility than static inheritance;
- avoids feature-laden classes high up in the hierarchy.

The *Decorator* pattern has at least two liabilities:
- a decorator and its component aren't identical;
- lots of little objects.


Implementation
--------------

Several issues should be considered when applying the *Decorator*
pattern:
- *interface conformance*  
  a decorator object's interface must conform to the interface
  of the component it decorates; ConcreteDecorator classes must
  therefore inherit from a common class (at least in C++);
- *omitting the abstract Decorator class*  
  there's no need to define an abstract Decorator class when you
  only need to add one responsibility;
- *keeping Component classes lightweight*;
- *changing the skin of an object versus changing its guts*  
  we chan think of a decorator as a skin over an object that changes
  its behaviour; an alternative is to change the object's guts;
  the Strategy pattern is a good example of a pattern
  for changing the guts.
