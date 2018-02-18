Composite
=========

Intent
------

Compose objects into tree structures to represent part-whole
hierarchies. Composite lets clients treat individual objects 
and compositions of objects uniformly.


Applicability
-------------

Use the Composite pattern when
- you want to represent part-whole hierarchies of objects;
- you want clients to be able to ignore the difference between 
  compositions of objects and individual objects. Clients will treat 
  all objects in the composite structure iniformly.


Structure
---------

```
 ----------       ---------------------
 | Client | ----> | Component         |*<--------------
 ----------       ---------------------              |
                  | Operation()       |              |
                  | Add(Component)    |              |
                  | Remove(Component) |              |
                  | GetChild(int)     |              |
                  ---------------------              |
                            ^                        |
                           / \                       |
                           ---                       |
                            |                        |
        -------------------------                    |
        |                       |                    |
 ---------------    ---------------------   children |
 | Leaf        |    | Composite         | <>----------
 ---------------    ---------------------  -----------------------\
 | Operation() |    | Operation() o-----|--| forall g in childrent \       
 ---------------    | Add(Component)    |  |  g.Operation();        |
                    | Remove(Component) |  --------------------------
                    | GetChild(int)     |
                    ---------------------
```


Participants
------------

- *Component*
  - declares the interface for objects in the composition;
  - implements default behaviour for the interface
    common to all classes, as appropriate;
  - declares an interface for accessing and managing its child 
    components;
  - (optional) defines an interface for accessing 
    a component's parent in the recursive structure, 
    and implements it if that's appropriate.
- *Leaf*
  - represents leaf objects in the composition;
    a leaf has no children;
  - defines behaviour for primitive objects in the composition.
- *Composite*
  - defines behaviour for components having children;
  - store child components;
  - implements child-related operations in the *Component* interface.
- *Client*
  - manipulates objects in the composition through the *Component*
    interface


Collaborations
--------------

- *Client*s use the *Component* class interface to interact 
  with objects in the composite structure. If the recipient 
  is a *Leaf*, then the request is handled directly. If the recipient
  is a *Composite*, then it usually forwards requests to its child
  components, possibly performing additional operations before 
  and/or after forwarding.


Consequences
------------

The *Composite* pattern
- defines class hierarchies consisting of primitive objects and 
  composite objects; wherever client code expects a primitive object,
  it can also take a composite object;
- makes the *Client* siple; *Client*s can treat composite structures
  and individual objects uniformly;
- makes it easier to add new kinds of *Component*s. Newly defined
  *Composite* or *Leaf* subclasses work automatically with existing
  structures and client code. *Client*s dont't have to be changed
  for new *Component* classes;
- can make your design overly general; The disadvantage of making it 
  easy to add new components is that it makes it harder to restrict
  the components of a composite; sometimes you want a composite 
  to have only certain components; with *Composite*, you can't rely
  on the type system to enforce those constraints for you; you'll 
  have to use run-time checks instead.


    