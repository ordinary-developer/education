# Short summary
- Prefer composition (mainly via ctor injection) to inheritance.
- Where possible use immutable objects.



# Class issues
Objects must ALWAYS  be in a complete state (also just after construction) (domain invariants must be held).

`private` should be your default scope (for member vars).

Don't use getters and setters.

If object A needs object B, B is a dependency of A.
For A to have access to B
- A can instantiate B itself;
- A can fetch a B instance from a known location (*service location*);
- A can get a B instance injected upon construction (*dependency injection*).

Three object types:
- *Service* objects (services -"er"s) - perfom a task or return a piece of information
  (can be created directly or fetched via a service locator);
- *Entity* (models) and *value* objects (domain objects)
  (are the materials that services use to perform their tasks).
- *DTO* (data transfer objects) (structs in C++)
  (carry date provided by the world outside or
   ommand objects (for providing data for operations)).

Most objects that are not entities should be implemented as immutable objects.


## Services
Services must be immutable.
Create wrapper (new service) classes for complicated and system methods.

Info about performed tasks itself (context, current context) should be provided as method arguments.
To to figure out arugment should be passed to ctor or method:
> "Could I run this service in a batch, without requiring it to be instantiated over and over again?"


## Entity objects
Represent important concepts from the buisiness domain. (Maybe use an internal id for an entity object).
Entities are mutable objects

Change methods should have a void return type and their names should be in the imperative form.


## Value objects
> "A value object is any immutable object that wraps primitive-type values."

Value objects wrap values inside an object.
To figure out if necessary to introduce a value object:
> "Would any string, int, etc., be acceptable here?" - if no, introduce a value object.

When to create value objects:
- extract new objects to prevent domain invariants
  from being verified in multiple places;
- extract new objects to represent composite values
  (when values belong together).
  
Value objects shouldn't get any dependencies injected, only values, value objects, or lists of them.
If a value object still need a service to perform some taks, inject it as a method argument
(or better pass a value object to a service).

We don't need value objects to be identifiable.
In fact, we shouldn't change a value object at all.

Create values instead of modifying them.

Compare values objects as whole objects (not via its properities).
When comparing immutable objects, assert equality, not sameness.

*Optional*:
For the equality method you can apply the rule for getters: only add this method if some other client than a test uses it.
(For tests it is better to use something like a standard assertEquals (that compare all internal members by default (if such assertEquals exists))).

  
## DTO
- all of its properties are exposed;
- its properties contain only primitive-type values, other DTOs, or simple arrays of DTOs;
- can be created using a regular ctor,
  or its properties can be set one by one,
  or they can be filled via a property filler (from raw data (as array or something else)) as a named ctor;
- dto can hava the "validate" method, that collects error lists or the whole status.

DTOs not necessarily need to be immutable, and its members (properties) can be public.



# Construction
- No ctor arguments should be optional (to grasp immediately all object config).
- No object creation outside ctor param building.
- Use *Factory* (*Builder*) objects to validate params for object ctor
  (may put this Factory(Builder) object as static methods of built objects).
- In ctor only assign properties (and maybe validate them).
- Consider throw an exception on params validation
  (use std InvalidException, don't use your own).
- Use assertions for class invariants.
- For sevices use a normal ctor,
  for value objects use a *named* ctor 
  (usually static method in the same object, normal ctor can (should?) be private)
  (for named ctors use domain terms (create, place, establish, etc...)).



# Lifecycle  
## Getters
Only add getters to expose internal data when this data is needed by some other client than the test itself.

## Don't use property fillers 
Don't copy data from a raw array to instance members (through reflection for example).

## Methods
A modifier method (both in mutable in immutable objects) must (like a ctor)
- check the client provides meaningful data;
- protect domain invariants.
(A modifier for a mutable object should verify that the requested state change is valid).

So a modifier can resuse the existing ctor (especially for immutable objects).






# Testing
Objects must be testable

*Test Doubles (stand-ins)*
- *Stub* - an object that provides predefined answers to method calls;
- *Mock* - an object on which you set expectations;
- *Fake* - an object with limited capabilities (for the purposes of testing), e.g. a fake web service.

When throw exception on param validattion test exceptions also on the messages
(with full or partial equalness).

Don't test the normal ctor flow, test a ctor for ways in which it should fail.
