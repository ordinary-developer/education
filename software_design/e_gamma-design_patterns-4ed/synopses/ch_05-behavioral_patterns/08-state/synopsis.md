STATE (Objects for States)
=====

Intent
------

Allow an object to alter its behavior when its internal state 
changes. The object will apear to change its class.


Applicability
-------------

Use the State pattern in either of the following cases:
- an object's behavior depends on its state, and it must change its
  behavior at runtime depending on that state;
- operations have large, multipart conditional statements that depend
  on the object's state.


Structure
---------

```
 ---------------  state       ------------
 | Context     |<>----------->| State    |
 ---------------              ------------
 | Request() o |              | Handle() |
 ------------|--              ------------
             |                     ^
 -----------------\               / \
 | state->Handle() |              ---
 -------------------               |
                         -----------------------------------
                         |                    |
                 ------------------   ------------------
                 | ConcreteStateA |   | ConcreteStateB |
                 ------------------   ------------------
                 | Handle()       |   | Handle()       |
                 ------------------   ------------------
```


Participants
------------

- **Context**
  - defines the interface of interest to clients;
  - maintains and instance of a ConcreteState subclass that defines
    the current state.
- **State**
  - defines an interface for encapsulating the behavior associated
    with a particular state of the Context.
- **ConcreteState subclasses**
  - each subclass implements a behavior associated with a state of 
    the context.


Collaborations
--------------

- context delegates state-specific requests to the current
  ConcreteState object;
- a context may pass itself as an arugment to the State object
  handling the request
  (this lets the State object access the context if neccessary);
- context is the primary interface for clients; clients can configure
  a context with State objects; once a context is configures,
  its clients don't have to deal with the Sate objects directly;
- either Context or the ConcreteState subclasses can decide which
  state succeeds another and under what circumstances.


Consequences
------------

The state pattern has the following consequences:
- it localizes state-specific behavior and partitions behavior for
  different states;
- it makes state transitions explicit;
- state objects can be shared.


Implementation
--------------

The state pattern raises a variety of implementation issues:
- who defines the state transitions?;
- a table-based alternative;
- creating and destroying State objects;
- using dynamic inheritance;



           




