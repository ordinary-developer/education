# Short summary
- Objects must be testable
- Prefer composition (mainly via ctor injection) to inheritance
- Where possible use immutable objects


# Class issues
*Private* should be your default scope (for vars).

If object A needs object B, B is a dependency of A.
For A to have access to B
- A can instantiate B itself;
- A can fetch a B instance from a known location (*service location*);
- A can get a B instance injected upon construction (*dependency injection*).

Objects must ALWAYS  be in an complete state (domain invariants must be held).

Don't use getters and setters.


Two object types:
- *Service* objects (services -"er"s) - perfom a task or return a piece of information
  (can be created directly or fetched via a service locator);
- *Entity*(models) and *value* objects (domain objects)
  (are the materials that services use to perform their tasks).


### Services
Services must be immutable.
Create wrapper (new service) classes for complicated and system methods.

#### Methods of services
Info about performed tasks itself (context, current context) should be provided as method arguments.
To to figure out arugment should be passed to ctor or method:
> "Could I run this service is a batch, without requiring it to be instantiated over and over again?"


# Construction
- No ctor arguments should be optional (to graspe immediately all object config);
- No object creation outside ctor param building;
- Use Factory (Builder) objects to validate params for object ctor;
  (may put this Factory(Builder) object as static methods of built objects);
- In ctor only assign properties (and maybe validate them);
- Consider throw an exception on params validation
  (use std InvalidException, don't use your own)
  (when throw exception on param validattion test exceptions also on the messages).

### Value objects
Value objects wrap values inside an object.
To figure out if necessary to introduce a value object:
> "Would any string, int, etc., be acceptable here?" - if no, introduce a value object

When to create value objects:
- extract new objects to prevent domain invariants
  from being verified in multiple places;
- extract new objects to represent composite values;


# Testing
*Test Doubles (stand-ins)*
- *Stub* - an object that provides predefined answers to method calls;
- *Mock* - an object on which you set expectations;
- *Fake* - an object with limited capabilities (for the purposes of testing), e.g. a fake web service.
