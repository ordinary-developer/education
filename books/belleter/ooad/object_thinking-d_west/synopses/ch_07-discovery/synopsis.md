Chapter 7 - Discovery
=====================

Domain understanding
--------------------
Select a couple of nouns and verb phrases, 
and write the first elements of a semantic net.
The circled nouns provid a rich set of potential objects,
and the relationships provide an equality rich set 
of potential responsibilities (expectations of those objects).

#### An XP approach:
It is necessary to define user stories. 
these user stories can be expanded into a sequence of interactions
and can be depicted with an interaction diagram.
User stories can have preconditions and postconditions.

Objects must me defined in terms of the services
they can provide others.


Object definition
-----------------
Object definition involves capturing three bits of information:
- a short prose description of the object 
  (in the words of a domain user);
- an enumeration of the services it is expected to provide
- a stereotype: another object or other objects that the one
  were are working with resembles in terms of similarity
  of provided services.
  (information holder, structurer, service provider,
   coordinator, controller, interfacer etc.).
   
It is often useful to use the "Rule" object.
A rule object is given responsibility to evaluate itself 
(true or false or maby something else)
 
Kent Beck says, 
> Keep things simple by not providing abstractions
> until the abstractions provide simplicity

Heuristics
----------
- Let objects assume repsonsibility for tasks
  that are wholly or completely delegatd to other objects
  (the Facade pattern).
- Delegate responsibilities to get a better distribution
  and increase reusability.
- Use anthropomorphization and foreshadowing (your programmer expierience)
  to determine whether an object should assume a given responsibility
- Responsibilities should be distributed among the community of objects
  in a balanced manner.
- Always state responsibilities in an active voice
  describing a service to be performed.
- Avoid responsibilities that are characteristic specific,
  that focus on providing a potential user with the value 
  of a single characteristic of the object
  (don't use "getAge" methods, but group demographic info 
   into simple objects (DTO))
- Create proxies for objects outside your domain 
  that are sources of information required by objects within your domain.
  (the Proxy pattern)
- Look for components.
