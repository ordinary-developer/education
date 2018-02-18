CHAIN OF RESPONSIBILITY
=======================

Intent
------

Avoid coupling the sender of a request to its receiver by giving
more than one object a chance to handle the request. Chain the 
receiving objects and pass the request along the chain until an
object handles it.


Applicability
-------------

Use Chain of Responsibility when
- more then one object may handle a request, and the handler isn't
  know a priori; the handler should be ascertained automatically;
- you want to issue a request to one of several objects without 
  specifying the receiver expliitly;
- the set of objects that can handle a request should be specified
  dynamically.


Structure
---------

```
                                    ---------------
                                    |             |
                                   \ /            |
                                    .             |
 ----------         ------------------- successor |
 | Client |-------->| Handler         |------------
 ----------         -------------------
                    | HandleRequest() |
                    -------------------
                             ^
                            / \
                            ---
                             |
             -------------------------------
             |                             |
    --------------------          -------------------
    | ConcreteHandler1 |          | ConcreteHander2 |
    --------------------          -------------------
    | HandleRequest()  |          | HandleRequest() |
    --------------------          -------------------
```


Participants
------------

- *Handler*
  - defines an interface for handling requests
  - (optional) implements the successor link.
- *ConcreteHandler*
  - handles requests it is responsible for;
  - can access its successor;
  - if the ConcreteHandler can handle the request, it does so,
    otherwise it forwards the request to its successor.
- *Client*
  - initiates the request to a ConcreteHandler object on the chain.


Collaborations
--------------

- When a *Client* issues a request, the request propagates along the
  chain until a *ConcreteHandler* object takes responsibility for 
  handling it.


Consequences
------------

Chain of Responsibility has the following benefits and liabilities:
- reduced coupling;
- added flexibility in assigning responsibilities to objects;
- receipt isn't guaranteed  
  since a request has no explicit receiver, there's no guarantee
  it'll be handled - the request can fall off the end of the chain
  without ever being handled; a request can also go unhandled when
  the chain is not configured properly.


Implementation
--------------

Here are implementation issues to consider in Chain of Responsibility:
- implementing the successor chain  
  there are two possible ways to implement the successor chain:
  - define new links (usually in the Handler, but ConcreteHandler
    could define them instead);
  - use existing links.
- connecting successors:  
- representing requests.  
