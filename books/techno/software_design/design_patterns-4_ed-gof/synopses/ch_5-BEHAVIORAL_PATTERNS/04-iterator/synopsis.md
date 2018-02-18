ITERATOR (CURSOR)
----------------- 

Intent
------

Provide a way to access the elements of an aggregate object 
sequentially without exposing its underlying representation.


Applicability
-------------

Use the Iterator pattern
- to access an aggregate object's contents without exposing its 
  internal representation;
- to support multiple traversals of aggregate objects;
- to provider a uniform interface for traversing different
  aggregate structures 
  (that is, to support polymorphic iteration).


Structure
---------

```
 --------------------    ----------    -----------------
 | Aggregate        |<---| Client |--->| Iterator      |
 --------------------    ----------    -----------------
 | CreateIterator() |                  | First()       |
 --------------------                  | Next()        |
          ^                            | IsDone()      |
         / \                           | CurrentItem() |
         ---                           -----------------
          |                                    ^
          |                                   / \
          |                                   ---
          |                                    |
 ----------------------               ---------------------
 | ConcreteAggregate  |<------------- | ConcreteIterator  |          
 ----------------------               ---------------------
 | CreateIterator() o |
 -------------------|--
                    |
 ------------------------------------
 | return new ConcreteIterator(this) \
 -------------------------------------
```


Participants
------------

- *Iterator*
  - defines an interface for accessing and traversing elements;
- *ConcreteIterator*
  - implements the *Iterator* interface;
  - keeps track of the current position in the traversal of 
    the aggregate;
- *Aggregate*
  - defines an interface for creating an *Iterator* object;
- *ConcreteAggregate*
  - implements the *Iterator* creation interface to return an
    instance of the proper ConcreteIterator.


Collaborations
--------------

A *ConcreteIterator* keeps track of the current object in the
aggregate and can compute the succeeding object in the 
traversal.


Consequences
------------

The *Iterator* pattern has three important consequences:
- it supports in the traversal of an aggregate;
- iterators simplify the Aggregate interface;
- more than one traversal can be pending on an aggregate.


Implementation
--------------

- Who controls the iteration?  
  (client or iterator)
- Who defines the traversal algorithm?  
  (the iterator is not the only place where the traversal algorithm
   canbe defined)
- How robust is the iterator?  
  (a robust iterator ensures that insertions and removals won't 
   interfere with traversal, and it does it without copying the
   aggregate)
