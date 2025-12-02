BUILDER
=======

Intent
------

Separate the construction of a complex object 
from its representation so that the same construction process
can create different representations


Applicability
-------------

Use the "BUILDER" pattern when
  
- the algorithm for creating a complex object should be independent
  of the parts that make up the object and how they're assembled;
- the construction process must allo different representations for
   the object that's constructed.


Structure
---------

```
 ------------------                  ---------------
 | Director       |<>--------------->| Builder     |
 ------------------                  ---------------
 | Construct()  o |                  | BuildPart() |
 ------------------                  ---------------
                |                           ^
                |                          / \
                |                          ---
 ----------------------------- \            |
 | for all objects in structure \  -------------------     -----------
 | {                            |  | ConcreteBuilder | --> | Product |
 |   builder->BuildPart()       |  -------------------     -----------
 | }                            |  | BuildPart()     | 
 --------------------------------  | GetResult()     |
                                   -------------------
```


Participants
------------

- Builder  
    * specifies an abstract interface for creating parts of 
      a "Product" object.
- ConcreteBuilder
    * constructs and assembles parts of the product 
      by implementing the "Builder" interface;
    * defines and keeps track of the representation it creates;
    * provides an interface for retreiving the product.
- Director
    * constructs an object using the "Builder" interface.
- Product
    * represents the complex object under construction;
      ("ConcreteBuilder" builds the product's internal representation
      and defines the process by which it's assembled);
    * includes classes that define the constituent parts,
      including interfaces for assembling the parts 
      into the final result.


Collaborations
--------------
 
- The client CREATES the "Director" object and CONFIGURES it 
  with the desired "Builder" object.
- "Director" NOTIFIES the "Builder" whenever a part of the "Product"
   should be build.
- "Builder" HANDLE REQUESTS from the director 
   and ADDS parts to the "Product".
- The client RETRIEVES the "Product" from the "Builder"


Consequences
------------

- It lets you vary a product's internal representation.
- It isolates code for construction and representation.
- It gives you finer control over the construction process
  (only when the product is finished does the director retrieve it
  from the builder).


Implementation
--------------

- Assembly and construction interface must be general enough to allow
  the construction of products for all kinds of concrete builders.
- No abstract class for products
  (in the commom case, the products produced by the concrete builders
  differ greatly in their representation).
- Empty methods as default in Builder
  (it lets clients ovveride only the operations 
  they're interested in).
