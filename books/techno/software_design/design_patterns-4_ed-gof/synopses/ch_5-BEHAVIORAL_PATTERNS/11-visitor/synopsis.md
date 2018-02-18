VISTOR
======

Intent
------

Represent an operation to be performed on the elements of an object
structure. Visitor lets you define a new operation without changing
the classes of the elements on which it operates.


Applicability
-------------

Use the Visitor pattern when
- an object structure contains many classes of objects with differing
  interfaces, and you want to perform operations on these objects
  that depend on their concrete classes;
- many distinct and unrelated operations need to be performed 
  on objects in an object structure, and you want to avoi "polluting"
  their classes with these operations;
- the classes defining the object structure rarely change, but you
  often want to define new operations over the structure.


Structure
---------

```
 ----------             -------------------------------------------
 | Cleint |------------>| Visitor                                 |
 ---------              -------------------------------------------
  |                     | VisitConcreteElementA(ConcreteElementA) |
  |                     | VisitConcreteElementB(ConcreteElementB) |
  |                     -------------------------------------------
  |                                         ^
  |                                        / \
  |                                        ---
  |                                         |
  |                       ------------------------------
  |                       |                            |
  |  -------------------------------------------       | 
  |  | ConcreteVisitor1                        |       |
  |  -------------------------------------------       |
  |  | VisitConcreteElementA(ConcreteElementA) |       |
  |  | VisitConcreteElementB(ConcreteElementB) |       |
  |  -------------------------------------------       |
  |                                                    |
  |                        -------------------------------------------
  |                        |ConcreteVisitor2                         |
  |                        -------------------------------------------
  |                        | VisitConcreteElementA(ConcreteElementA) |
  |                        | VisitConcreteElementB(ConcreteElementB) |
  |                        -------------------------------------------
  |
  |   ------------------         -------------------
  --->| ObjectStruture |-------->| Element         |
      ------------------         -------------------
                                 | Accept(Visitor) |
                                 -------------------
                                          ^
                                         / \
                                         ---
                                          |
                        ---------------------------
                        |                         |
              ----------------------    ----------------------
              | ConcreteElementA   |    | ConcreteElementB   |
              ----------------------    ----------------------
              | Accept(Visitor v) o|    | Accept(Visitor v) o|
              | OperationA()      ||    | OperationB()      ||
               -------------------||    --------------------|-
                                  |                         |
 ------------------------------\ /  ------------------------------\  
 | v->VisitConcreteElement(this)|   |v->VisitConcreteElementB(this)| 
 -------------------------------    -------------------------------
```


Participants
------------

- **Visitor**
  - declares a Visit operations for each class of ConcreteElement
    in the object structure
    (the operation's name and signature identifies the class 
     that sends the Visit request to the visitor; 
     that lets the visitor determine the concrete class 
     of the element being visited;
     then the visitor can access the element directly through
     its particular interface).
- **ConcreteVisitor**
  - implements each operation declared by Visitor.
- **Element**
  - defines an Accept operation that takes a visitor as an argument.
- **ConcreteElement**
  - implements an Accept operation that takes a visitor 
    as an argument.
- **ObjectStructure**
   - can enumerate its elements;
   - may provide a high-level interface to allow the visitor to visit
     its elements;
   - may either be a composite or a collection such as a list
     or a set.


Collaborations
--------------

- a client that uses the Visitor pattern must create 
  a ConcreteVisitor object and then tarverse the object structure,
  visiting each element with the visitor;
- when an element is visited, it calls the Visitor operation 
  that corresponds to its class; the element supplies itself 
  as an argument to this operation 
  to let the visitor access its state, if necessary.


Consequences
------------

Some of the benefits and liabilities of the Visitor pattern 
are as follows:
- Visitor makes adding new operations easy;
- a visitor gathers related operations and separates unrelated ones;
- adding new ConreteElement classes is hard;
- visiting accross class hierarchies;
- accumulating state;
- breaking encapsulation;


Implementation
--------------

When you apply the visitor pattern 
the following implementation issues arise
- double dispatch;
- who is responsible for traversing the object structure?

