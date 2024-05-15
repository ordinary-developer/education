# Chapter 8 - All the World's a Stage

## Static relationships

### Is-a-Kind-of relationship
Your taxonomy must follow two rules:
- Exibit a single line of descent (single inheritance) base on nothing
  but the behaviors of the objects.
- Subclass only by extension - by adding behaviors.
  (A subclass should be able to do everything its superclass can do,
   plus at least one more thing.
   You can substitute an object from a subclass in any situtation
   calling for an object from its superclass and still get behavior
   you expected).

### Collaborates-with relationship
Collaborations should occur inside the encapsulation barrier,
with:
- objects occupying instance variables;
- objects being received along with messages,
- objects occupying temporary variables.

(Global variables should be avoided)

### MVC
An eventDispatcher is a simple two-dimensional table,
the first of which contains a list of events
that can be dispatched and the second column 
of which contains a collection (possibly and ordered collection)
of notificationRequest objects.

## Constraints
Implementing constrains in the affected method 
or a manager/controller object, makes objects brittle.
So implementing constraints can be done with a rule object
(by encapsulation).

A rule is an ordered collection of variables, constants, and operators.

Rules are recursive. Any element of a rule can be replaced with a rule.

## Unit-tests
For every message you listed (message protocol) first tests are:
- When the message is sent to the object, 
  is the expected object returned?
- Is it an instance of the right class?
- Is it in the correct state?
  (It has a reasonable value or 
   its instance variables have reasonble values).

