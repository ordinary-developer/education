MEDIATOR
========

Intent
------

Define an object that encapsulates how a set of objects interact.
Mediator promote loose coupling by keeping objects from referring
to each other exlicitly, and it lets you vary their interaction
independently.


Applicability
-------------

Use the Mediator pattern when
- a set of objects communicate in well-defined but complex ways;
  the resulting interdependencies are unstructured and difficult
  to understand;
- reusing an object is difficult because it refers to and 
  communicated with mayny other objects;
- a behaviour that's distributed between several classes should
  be customizable without a lot of subclassing.


Structure
---------

```
    ------------            mediator  -------------
    | Mediator |<---------------------| Colleague |
    ------------                      -------------
          ^                                  ^
         / \                                / \
         ---                                --- 
          |                                  |
          |                      ---------------------------
          |                      |                         |
 --------------------   ---------------------    ---------------------
 | ConcreteMediator |-->| ConcreteCollegue1 |  ->| ConcreteCollegue2 |
 --------------------   ---------------------  |  --------------------
              |                                |
              ----------------------------------
```


Participants
------------

- *Mediator*
  - defines an interface for communicating with *Colleague* objects.
- *ConcreteMediator*
  - implements cooperative behaviour by coordinating *Colleague*
    objects;
  - knows and maintains its colleagues.
- *Colleague classes*
  - each *Colleague* class knows its *Mediator* object;
  - each colleague communicates with its mediator whenever it would
    have otherwise comminicated with another colleague.


Collaborations
--------------

- Colleagues send and receive requests from a Mediator object. 
  The mediator implements the cooperative behaviour by routing
  request between the appropriate colleague(s).


Consequences
------------

The Mediator pattern has the following benefits and drawbacks:
1. It limits subclassing.
2. It decouples colleagues.
3. It simplifies object protocols.
4. It abstracts how objects cooperate.
5. It centralizes control  
   (But in this case the mediator can be more complex, more monolith).


Implementation
--------------

The following implementation issues are relevant to the Mediator
pattern:
1. Omitting the abstract Mediator class.  
   There's no need to define an abstract Mediator class when 
   colleague work with only one mediator. The abstract coupling
   that the Mediator class provides lets colleagues work with 
   different Mediator subclasses, and vice versa.
2. Colleague-Mediator communication.  
   Colleagues have to communicate with their mediator when an event
   of interest occurs.  
   One approach is to implement the Mediator as
   an Observer using the Observer pattern. Colleague classes act as
   Subjects, sending notifications to the mediator whenever they
   change state. The mediator responds by propagating the effects
   of the change to other colleagues.  
   Another approach defines a specialized notification interface 
   in Mediator that lets colleagues be more direct in their 
   communication.

