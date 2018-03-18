Bridge (Handle, Body)
=====================

Intent
------

Decouple an abstraction from its implementation so that the two can
vary independently.


Applicability
-------------

Use the Bridge pattern when
- you want to avoid a permanent binding between an abstraction and
  its implementation (for example, when the implementation must be
  selected or switched at run-time);
- both the abstraction and their implementation should be extensible
  by subclassing. In this case, the Bridge pattern lets you combine
  the different abstractions and implementaions and extend them
  independently;
- changes in the implementaion of an abstraction should have no impact
  on clients; that is, their code should not have to be recompiled;
- (C++) you want to hide the implemention of an abstraction completely
  from clients. In C++ the representation of a class is visible in 
  the class interface;
- you have a proliferation of classes (such a class hierarchy 
  indicates the need for splitting an object into two parts);
- you want to share an implementaion among multiple objects 
  (perhaps using reference counting).


Structure
---------

```
 ----------
 | Client |
 ----------
     |
     |    ---------------                          ------------------
     |--->| Abstraction |<>----------------------->|  Implementor   |
          ---------------                          ------------------
          | Operation() |                          | OperationImpl()|
          -----------|---                          ------------------
              ^   |  ----------------------\                ^
             / \  |--| imp->OperationImp();|               / \
             ---     -----------------------               ---
              |                                             |
              |                         ------------------------|
              |                         |                       |  
   ----------------------    ------------------------           |
   | RefinedAbstraction |    | ConcreteImplementorA |           |
   ----------------------    ------------------------           |
                             | OperationImp()       |           |
                             ------------------------           |
                                                                |
                                            ------------------------
                                            | ConcreteImplementorB |
                                            ------------------------
                                            | OperationImp()       |
                                            ------------------------
```     


Participants
------------

- *Abstraction*
  - defines the abstraction's interface;
  - maintains a reference to an object of type *Implementor*.
- *RefinedAbstraction*
  - extends the interface defined by *Abstraction*.
- *Implementor*
  - defines the iterface for implementation classes; this interface
    doesn't have to correspond exactly to *Abstraction*'s interface;
    in fact the two interfaces can be quite different; typically 
    the *Implementor* interface provides only primitive operations,
    and *Abstraction* defines higher-level operations based on these
    primitives.
- *ConcreteImplementor*
  - implements the *Implementor* interface and defines its concrete
    implementation.


Collaborations
--------------

- *Abstraction* forwards client requests it its *Implementor* object.


Consequences
------------
 
- *Decoupling interface and implementation.*  
  An implementation is not bound  permanently to an interface. The
  implementation of an abstraction can be configured at run-time.
- *Improved extensibility*.  
  You can extends the Abstraction and Implementator hierarchies
  independently.
- *Hiding implementaion details from clients*.  
  You can shield clients from implementation details.
