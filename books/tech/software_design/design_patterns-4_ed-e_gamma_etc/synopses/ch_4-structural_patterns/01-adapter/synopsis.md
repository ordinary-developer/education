ADAPTER (Wrapper)
=================

Intent
------

Convert the interface of a class into another interface clients 
expect. Adapter lets classes work together that couldn't otherwise 
because of incompatible interfaces.


Applicability
-------------

Use the Adapter pattern when
- you want to use an existing class, and its interface does not 
  match the one you need.
- you want to create a reusable class that cooperates with unrelated
  or unforeseen classes, that is, classes that don't necessarily
  have compatible interfaces.
- *(object adapter only)* you need to use several existing subclasses,
  but it's impractical to adapt their interface by subclassing every
  one. An object adapter can adapt the interface of its parent class.


Structure
---------

A *class adapter* use multiple inheritance to adapt one interface to
another
```
   ----------        -------------      ---------------------
   | Client |------->| Target    |      | Adaptee           |
   ----------        -------------      ---------------------
                     | Request() |      | SpecificRequest() |
                     -------------      ---------------------
                           ^                      ^
                          / \                    / \
                          ---                    ---
                           |                      |
                           -------  ---------------
                                 |  |
                           ---------------
                           | Adapter     |
                           ---------------   ---------------------
                           | Request()  *----| SpecificRequest()  \
                           ---------------   ----------------------
```

An object adapter relies on object composition:
```
  ------------        --------------             ---------------------
  | Client   |------->| Target     |          |->| Adoptee           |
  ------------        --------------          |  ---------------------
                      | Request()  |          |  | SpecificRequest() |
                      --------------          |  ---------------------
                             ^                |
                            / \               |
                            ---               | 
                             |                |
                      -------------- adaptee  |
                      | Adapter    |-----------
                      --------------    ----------------------------\
                      | Request() *|----| adaptee->SpecificRequest() |
                      --------------    ------------------------------
```


Participants
------------

- *Target*
  * defines the domain-specific interface that Client uses.
- *Client*
  * collaborates with objects conforming to the Target interface.
- *Adaptee*
  * defines an existing interface that needs adapting.
- *Adapter*
  * adapts the interface of Adaptee to the Target interface.
  

Collaborations
--------------

- *Client*s call operations on an *Adapter* instance. In turn, 
  the *Adapter* calls *Adaptee* operations that carry out the request.


Consequences
------------

Class and object adapters have different trade-offs. 
A class adapter
- adapts *Adaptee* to *Target* by committing to a concrete *Adapter*
  class. As a consequence, a class adapter won't work when we want
  to adapt a class and all its subclasses.
- lets *Adapter* override some of *Adaptee*'s behavior, since 
  *Adapter* is a subclass of *Adaptee*.
- introduces only one object, and no additional pointer indirection
  is needed to get to the adaptee.

An object adapter
- lets a single *Adapter* work with many *Adaptees* - that is, 
  the *Adaptte* itself and all of its subclasses (if any). 
  The *Adapter* can also add functionality to all *Adaptees* at once.
- makes it harder to override *Adaptee* behavior. It will require 
  subclassing *Adaptee* and making *Adapter* refer to the subclass
  rather than the *Adaptee* itself.


Implementation
--------------

Some issues to keep in mind:
1. *Implementation class adapters in C++*  
   In a C++ implementation of a class adapter, *Adapter* would inherit
   publicly from *Target* and privately from *Adaptee*. Thus *Adapter*
   would be a subtype of *Target* but not of *Adaptee*.
2. *Pluggable Adapters*  
   - *using abstract operations*  
     Define corresponding abstract operations for the narrow *Adaptee*
     interface. Subclasses must implement the abstract operation and
     adapt the hierarchically structrued object.
   - *using delegate objects*
     The *Adapter* forwards requests for accessing the hierarchical
     structures to a delegate object.
