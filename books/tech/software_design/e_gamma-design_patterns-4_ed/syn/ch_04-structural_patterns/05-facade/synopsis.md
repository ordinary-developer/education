Facade
======

Intent
------

Provide a unified interface to a set of interfaces in a subsystem.
Facade defines a higher-level interface that makes the subsystem
easier to use.


Applicability
-------------

Use the *Facade* pattern when
- you want to provide a simple interface to a complex subsystem;
- there are many dependencies between clients and the implementation
  classes for an abstraction; introduce a facade to decouple the 
  subsystem from clients and other subsystems, thereby promoting
  subsystem independence and portability;
- you want to layer your subsystems; use a facade to define an entry
  point to each subsystem level.


Structure
---------

```                          ----------
 ----------------------------| Facade |---------------------------
 |                           ----------                          |
 |                           /    |    \                         |
 |                          /     |     \                        |
 |                         /      |      \                       |
 |                        /       |       \                      |
 |                       /        |        \                     |
 |                      \/       \ /       \/                    |
 |                    -------  -------   ------                  |
 |                    |     |  |     |   |    |                  |
 |                    -------  -------   ------                  |
 -----------------------------------------------------------------
```


Participants
------------

- *Facade*
  - knows which subsystem classes are responsible for a request;
  - delegates client requests to appropriate subsystem object.
- *subsystem classes*
  - implement subsystem functionality;
  - handle work assigned by the Facade object;
  - have no knowledge of the facade;  
    that is, they keep no references to it.


Collaborations
--------------

- clients communicate with the subsystem by sending requests 
  to *Facade*, which forwards them to the appropriate subsystem 
  object;
- clients that use the facade don't have to access its subsystem
  objects directly.


Consequences
------------

The *Facade* pattern offers the following benefits:
- it shields clients from subsystem components;
- it promotes weak coupling between the subsystem and its clients.


Implementation
--------------

Consider the following issues when implementing a facade:
- *reducing client-subsystem coupling*
  the coupling between clients and the subsystem can be reduced 
  even further by making Facade an abstract class with concrete
  subclasses for different implementations of a subsystem; then
  clients can communicate with the subsystem through the interface
  of the abstract Facade class;  
- *public versus private subsystem classes*  
  and just as it is useful to think of the public and private 
  interface of a class, we can think of the public and private
  interface of a subsystem.



