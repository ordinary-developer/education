# Chapter 10 - Wrapping up
## Frameworks (aka patterns)

### Composable document
Composable document is a collection of elements 
(which means it has the behaviour of adding, deleting,
 and providing access to the collected elements)
that can identify itself, describe itself, and display itself.


### Object routing and tracking
On object has on "originLocation", a "destinationLocation", 
a description, and a unique ID.
It obtains a route from a network, 
here a root is an ordered set of nodes and links
that connect an "originLocation" to a "destinationLocation".
An object obtains a route, 
checks with both nodes and links to track its own progress,
and raises an alert if it detects a deviation from its assigned route.


### Resource Allocation and Scheduling
Three objects form the core of this framework:
- Resource
  can have other resources (calendar with time divisions)
  as part of its structure, description, and its identity;
- Request
  which can recursively be a collection of requests
  and which has a description (resource requirements),
  and identiry, and a "Requester";
- Reservation
  which associates a resource with a request
  and has an identity along with references to the objects 
  it is associating.

Remark:
Scheduling is a resource allocation, 
where the resource it time.
