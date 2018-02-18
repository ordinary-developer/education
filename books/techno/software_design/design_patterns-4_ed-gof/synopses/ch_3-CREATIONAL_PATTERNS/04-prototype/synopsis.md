PROTOTYPE
==============

Intent
------

Specify the kinds of objects to create using a prototypical instance,
and create new objects by copying this prototype.        


Applicability
-------------

Use the *Prototype* pattern when a system should be independent of
how its prducts arec created, composed, and represented; and
- when the classes to instantiate are specified at run-time, for
  example, by dynamic loading; or
- to avoid building a class hierarchy of factories that parallels
  the class heirarchy of products; or
- when instances of a class can have one of only a few different 
  combinations of state. It may be more convenient to install 
  a corresponding number of prototypes and clone them rather
  than instantiating the class manually, each time with the
  appropriate state


Structure
---------

```
     ---------------- prototype       -------------
     | Client       |---------------->| Prototype |
     ----------------                 -------------
     | Operation() o|                 | Clone()   |
     --------------|-                 -------------
                   |                        ^
                   |                       / \
------------------------\                  ---
| p = prototype->Clone() |                  |
-------------------------      --------------------------
                               |                        |
                     ----------------------   ----------------------
                     | ConcretePrototype1 |   | ConcretePrototype2 |
                     ----------------------   ----------------------
                     | Clone() o          |   | Clone() o          |
                     ----------|-----------   ----------|-----------
                               |                        |
                               |                        |
                    ---------------------\  ----------------------\
                    |return copy of self |  | return copy of self |
                    ---------------------   -----------------------
```

Participants
------------

- *Prototype*
    * declares an interface for cloning itself.
- *ConcretePrototype*
    * implements an operation for cloning itself.
- *Client*
    * creates a new object by asking a prototype to clone itself.


Collaborations
--------------

- A client asks a prototype to clone itself.


Consequences
------------

The Prototype pattern hides the concrete product classes from the 
client, thereby reducing the number of names clients know about.
Moreover, these pattern let a client work with application-specific
classes without modification.

Additional benefits of the Prototype pattern are listed below.
- *Adding and removing products at run-time*
- *Specifying new objects by varying values*
- *Specifying new objects by varying structure*
- *Reduced subclassing*
- *Configuring an application with classes dynamically*


Implementation
--------------

Consider the following issues when implementing prototypes:
- *Using a prototype manager.*  
  When the number of prototypes in a system isn't fiexed (this is,
  they can be created and destroyed dynamically), keep a registry of
  available prototypes. Clients won't manage prototypes themselves
  but will store and retrieve them from the registry. A client 
  will ask the registry for a prototype before cloning it. We call
  this registry a *prototype manager.*  
  A prototype manager is an associative store that returns the
  prototype matching a given key. It has operations for registering
  a prototype undera key and for unregistering it. Clients can
  change or even browse through the registry at run-time. This lets
  clients extend and take invetory on the system without writing code.
- *Implementing the Clone operation.*  
  The hardest part of the Prototype pattern is implementing the
  Clone operation correctly. It's particularly tricky when object
  structures contain circular references.
- *Initializing clones.*  
  While some clients are perfectly happy with the clone as is, others
  will want to initialize some or all of its internal state to values
  of their choosing. You generally can't pass these values in the
  Clone operation, because their number will vary between classes 
  of prototypes. Some prototypes might need multiple initialization
  parameters; others won't need any. Passing parameters in the Clone
  operation precludes a uniform cloning interface.  
  It might be the case that your prototype classes already define
  operations for (re)setting key pieces of state. If so, clients may
  use these operation immediately after cloning. If not, then you 
  may have to introduce an Initialize operation that takes 
  initialization parameters as arguments and sets the clone's 
  internal state accordingly. Beware of deep-copying Clone
  operation - the copes may have to be deleted (either explicitly
  or within Initialize) before you reinitialize them.



