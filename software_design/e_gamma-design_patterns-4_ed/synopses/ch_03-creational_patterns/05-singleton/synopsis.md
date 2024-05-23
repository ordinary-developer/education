SINGLETON
=========

Intent
------

Ensure a class only has one instance, and provide a global point 
of access to it.


Applicability
-------------

Use the Singleton pattern when
- there must be exactly one instance of a class, and it must 
  be accessible to clients from a well-known access point;
- when the sole instance should be extensible by subclassing, and
  clients should be able to use an extended instance without 
  modifying there code.


Structure
---------

```
 -------------------------
 | Singleton             |
 -------------------------     --------------------------\
 | static Instance()    *------| return uniqueInstance    \
 | SingletonOperation()  |     |                          |
 | GetSingletonData()    |     ----------------------------
 -------------------------
 | static uniqueInstance |
 | singletonData         |
 -------------------------
```


Participants
------------

- Singleton
    * defines an Instance operation that lets clients access its
      unique instance. Instance is a class operation (that is, 
      a static member function in C++); 
    * may be responsible for creating its own unique instance.


Collaborations
--------------

- Clients access a Singleton instance solely through Singleton's
  Instance operation.


Consequences
------------

The Singleton pattern has several benefits:
- Controlled access to sole instance.
- Reduced namespace.
- Permits refeniment of operations and representation.
- Permits a variable number of instances.
- More flexible than class operations.


Implementation
--------------

Here are implementation issues to consider when using the Singleton
pattern:
- Ensuring a unique instance.
- Subclassing the Singleton class.
