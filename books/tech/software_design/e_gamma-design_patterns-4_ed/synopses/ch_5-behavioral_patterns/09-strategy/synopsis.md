Strategy (Policy)
========

Intent
------

Define a family of algorithms, encapsulate each one, and make them
interchangable. Strategy lets the algorithm vary independently from
clients that use it.


Applicability
-------------

Use the Strategy pattern when
- many related classes differ only in their behavior; 
- you need different variants of an algorithm;
- an algorithm uses data that clients shouldn't know about;
- a class defines many behaviors, and these appear am multiple 
  conditional statements in its operations
  (instread of many conditionals, move related conditional branches
   into their own Strategy class).


Structure
---------

```
 ----------------------  strategy        ------------------------ 
 | Context            |<>--------------->| Strategy             |
 ----------------------                  ------------------------
 | ContextInterface() |                  | AlgorithmInterface() |
 ----------------------                  ------------------------ 
                                              ^
                                             / \
                                             ---
                                              |
           ----------------------------------------------------
           |                         |                        |
 ------------------------ ------------------------ ------------------------
 | ConcreteStrategyA    | | ConcreteStrategyB    | | ConcreteStrategyC    |
 ------------------------ ------------------------ ------------------------
 | AlgorithmInterface() | | AlgorithmInterface() | | AlgorithmInterface() | 
 ------------------------ ------------------------ ------------------------
```
    

Participants
------------

- **Strategy**
  - declares an interface common to all supported algorithms
    (context uses this interface to call the algorithm defined by a
     ConcreteStrategy).
- **ConcreteStrategy**
  - implements the algorithm using the Strategy interface.
- **Context**
  - is configured with a ConcreteStrategy object;
  - maintains a reference to a Strategy object;
  - may define an interface that lets Strategy access its data.


Collaborations
--------------

- Strategy and Context interact to implement the chosen algorithm
  (a context may pass all data required by the algorithm to the 
   strategy when the algorithm is called and alternatively, the 
   context can pass itself as an argument to Strategy operations);
- a context forwards requests from its clients to its strategy
  (clients usually create and pass a ConcreteStrategy object 
   to the context; thereafter, clients interact with the context
   exclusively).


Consequences
------------

The Strategy pattern has the following benefits and drawbacks:
- families of related algorithms;
- an alternative to subclassing;
- strategies eliminate conditional statements;
- a choice of implementations;
- clients must be aware of different Strategies;
- communication overhead between Strategy and Context;
- increased number of objects.


Implementation
--------------

Consider the following implementation issues:
- defining the Strategy and Context interfaces;
- Strategies as template parameters; 
- making strategy objects optional;
