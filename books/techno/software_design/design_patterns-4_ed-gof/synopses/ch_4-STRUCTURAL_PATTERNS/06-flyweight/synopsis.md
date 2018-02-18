Flyweight
=========

Intent
------

Use sharing to support large numbers of fine-grained objects 
efficiently.

(A flyweight is a shared object that can be used in multiple contexts
simultaneously. The flyweight acts as an independent object in 
each context - it's indistiguishable from an instance of the object
that's not shared. Flyweights cannot make assumptions about the
context in which they operate. The key concept here is the 
distinction between intrinsic and extrinsic state. Intrinsic state 
is stored in the flyweight; it consists of information that's
independent of the flyweight's context, thereby making it sharable.
Extrinsic state depends on and varies with the flyweight's context
and therefore can't be shared. Client objects are responsible
for passing extrinsic state to the flyweight when it needs it.)


Applicability
-------------

The *Flyweight* pattern's effectiveness depends heavily on how 
and where it's used. 

Apply the *Flyweight* pattern when *all* of the following are true:
- an application uses a large number of objects;
- storage costs are high because of the sheer quantity of objects;
- most object state can be made extrinsic;
- many groups of objets may be replaced by relatively few shared
  objects one extrinsic state is removed;
- the application doens't depend on object identity
  (since flyweight objects may be share, identity tests will return
   true for conceptually distinct objects).


Structure
---------

```
 ----------------------   flyweights     -----------------------------
 | FlyweightFactory   |<>--------------->| Flyweight                 |
 ----------------------                  -----------------------------
 | GetFlyweight(key) o|                  | Operation(extrinsicState) |
 --------------------|-                  -----------------------------
   ^                 |                           |
   |  --------------------------------\          |
   |  | if (flyweight[key] exists) {   \         |
   |  |   return existing flyweight;    |        |
   |  | }                               |        |
   |  | else {                          |        |
   |  |   create new flyweight;         |        |
   |  |   add it to pool of flyweights; |        |
   |  |   return the new flyweight;     |        |
   |  -----------------------------------        ^
   |                                            / \
   |                       --------------------------------
   |                       |                              |
   |        ---------------------------    ---------------------------
   |      ->| ConcreteFlyweight       |  ->|UnsharedConcreteFlyweight| 
   |      | ---------------------------  | ---------------------------
   |      | |Operation(extrinsicState)|  | |Operation(extrinsicState)|
   |      | ---------------------------  | ---------------------------
   |      | | IntrinsicState          |  | | allState                |
   |      | ---------------------------  | ---------------------------
 -------- |                              |
 |Client|---------------------------------
 --------
```


Participants
------------

- *Flyweight*
  - declares an interface through which flyweights can receive 
    and act on extrinsic state.
- *ConcreteFlyweight*
  - implements the Flyweight interface and adds storage for intrinsic
    state, if any; a *ConcreteFlyweight* object must be shareable;
    any state it stores must be intrinsic; that is, it must be 
    independent of the ConcreteFlyweight object's context.
- *UnsharedConcreteFlyweight*
  - not all Flyweight subclasses need to be shared; the Flyweight
    interface enables sharing; it doesn't enforce it; it's common for
    *UnsharedConcreteFlyweight* objects to have ConcreteFlyweight 
    objects as children at some level in the flyweight object 
    structure.
- *FlyweightFactory*
  - create and manages flyweight objects;
  - ensures that flyweights are shared properly; When a client
    requests a flyweight, the FlyweightFactory object supplies an
    existing instance or creates one, if none exits.
- *Client*
  - maintains a reference to flyweight(s);
  - computes or stores the extrinsic state of flyweight(s).


Collaborations
--------------

- State that a *flyweight* need to function must be characterized as
  either intrinsic or extrinsic. Intrinsic state is stored in the 
  *ConcreteFlyweight* object; extrinsic state is stored or computed
  by *Client* objects. *Client*s pass this state to the *flyweight*
  when they invoke its operations.
- *Client*s should not instantiate *ConcreteFlyweight*s directly.
  *Client*s must obtain *ConcreteFlyweight* objects exclusively from
  the *FlyweightFactory* object to ensure they are shared properly.


Implementation
--------------

Consider the following issues when implementing the Flyweight pattern:
- *Remoing extrinsic state.*  
  The pattern's applicability is determined largely by how easy 
  it is to identify extrinsic state and remove it from shared objects.
  Removing extrinsic state won't help reduce storage costs 
  if there are as many different kind of extrinsic state as 
  there are objects before sharing. Ideally, extrinsic state can
  be computed from a separate object structure, one with far smaller
  storage requirements.
- *Managing shared objects.*  
  Because objects are shared, clients shouldn't instantiate them
  directly. FlyweightFactory lets clients locate a particular
  flyweight. FlyweightFactory objects often use an associative 
  store to let clients look up flyweights of interest.
