MEMENTO (Token)
=======

Intent
------

Without viloating encapsulation, capture and externalize an object's 
internal state so that the object can be restored to this state 
later.


Applicability
-------------

Use the Memento pattern when
- a snapshot of (some portion of) and object's state must be saved so
  that it can be restored to that state later;
- a direct interface to obtaining the state would expose 
  implementation details and break the object's encapsulation.


Structure
---------

```
 ---------------------------     --------------  memento -------------
 | Originator              |---->| Memento    |<-------<>| Caretaker |
 ---------------------------     --------------          -------------
 | SetMemento(Memento m) o |     | GetState() |
 | CreateMemento() o     | |     | SetState() |
 ------------------|-----|--     --------------
 | state           |     | |     | state      |
 ---------------------------     --------------
                   |     | 
 --------------------\  -----------------------\
 | return             \ | state = m->GetState() |
 |  new Memento(state)| -------------------------
 ----------------------
```


Participants
------------

- **Memento**
  - store internal state of the Originator object;  the memento
    may store as much or as little of the originator's internal state
    as necessary at its orginator's discretion;
  - protects against access by objects other than the originator;
    mementos have effectively two interfaces; caretaker sees
    a narrow interface to the Memento - it can only pass the 
    memento to other objects; Originator, in contrast, sees a 
    wide interface, one that lets it access all the data necessary
    to restore itself to its previous state;
    ideally, only the originator that produced the memento would 
    be permitted to access the *memento*'s internal state.
- **Originator**
  - creates a memento containing a snapshot of its current internal
    state;
  - uses the memento to restore its internal state.
- **Caretaker**
  - is repsonsible for the memento's safekeeping;
  - never operates on or examines the contents of a memento.


Collaborations
--------------

- A caretaker requests a memento from an originator,
  holds it fro a time, and passes it back to the originator;
- mementos are passive, only the originator that created a memento
  will assign or retrieve its state.


Consequences
------------

The Memento pattern has several consequences:
- preserving encapsulation boundaries;
- it simplifies originator;
- using mementos might be expensive;
- defining narrow and wide interfaces;
- hidden costs in caring for mementos.


Implementation
--------------

Here are two issues to consider when implementing the Memento 
pattern:
- language support;
- storing incremental changes.
