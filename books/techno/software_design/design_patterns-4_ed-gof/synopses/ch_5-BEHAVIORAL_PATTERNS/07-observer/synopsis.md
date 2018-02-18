OBSERVER (Dependents, Publish-Subscribe)
======== 

Intent
------

Define a one-to-many dependency between objects so that
when one object changes state, all its dependents are notified and
update automatically.


Applicability
-------------

Use the Observer pattern in any of the following situations:
- when an abstraction has two aspects, one dependent on the other;
  encapsulating these aspects in separate objects lets you vary 
  and reuse them independently;
- when a change to one object requires changing others, 
  and you don't know how many objects need to be changed;
- when an object should be able to notif other objects 
  without making assumptions about who these objects are;
  (in other words, you don't want these objects tightly coupled).


Structure
---------

```
 -------------------- observers      ------------
 | Subject          |--------------->| Observer |
 --------------------                -----------
 | Attach(Observer) |                | Update() |
 | Detach(Observer) |                ------------
 | Notfy() o -------|----                  ^
  -------------------   |                 / \
          ^             |                 ---
         / \   -----------------------\    |
         ---   | for all o in observer \   | ----------------------\
          |    |   in observer         |   | | observerState =      \
          |    | {                     |   | |  subject->GetState() |
          |    |   o->Update();        |   | ------------------------
          |    | }                     |   |
          |     ------------------------   ------------
          |                                           |
 --------------------                subject --------------------
 | ConcreteSubject  |<-----------------------| ConcreteObserver |
 --------------------  ------------ ---\     --------------------
 | GetState() o-----|--| return         \    | Update() o-------|-
 | SetState()       |  |   subjectState |    --------------------
 --------------------  ------------------    | observerState    |
 | subjectState     |                        --------------------
 --------------------
```


Participants
------------

- **Subject**
  - knows its observers;
  - provides an interface for attaching and detaching Observer 
    objects.
- **Observer**
  - defines an updating interface for objects that sould be notified
    of changes in a subject.
- **ConcreteSubject**
  - stores state of interest to ConcreteObserver objects;
  - sends a notification to its observers when its state changes.
- **ConcreteObserver**
  - maintains a reference to a ConcreteSubject object;
  - stores state that should stay consistent with the subject's;
  - implements the Obserer updating interface to keep its state
    consistent with the subject's.


Collaborations
--------------

- concreteSubject notifies its observers whenever a change occurs
  that could make its observer's state inconsistent with its own;
- after being informed of a change in the concrete subject, 
  a ConcreteObserver object may query the subject for information;
  ConcreteObserver uses this information to reconcile its state
  with that of the subject.


Consequences
------------

Further benefits and liabilities of the Observer pattern 
include the following:
- abstract coupling between Subject and Observer;
- support fot broadcast communication;
- unexpected updates;


Implementation
--------------

Some issues are related to the implementation:
- mapping subjects to their observers;
- observing more than one subject;
- who triggers the update?;
- dangling references to deleted subjects;
- making sure Subject state is self-consistent before notification;
- avoiding observer-specific update protocols: 
  the push and pull models;
- specifying modification of interest explicitly;
- encapsulating complex update semantics;
- combining the Subject and Observer classes.
