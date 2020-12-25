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

Objects must ALWAYS not be in an inpcomplete state.

Don't use getters and setters.


Two object types:
- *Service* objects (services -"er"s) - perfom a task or return a piece of information
  (can be created directly or fetched via a service locator);
- *Entity* objects (domain objects).


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
- Consider throw an exception on params validation.


# Testing
*Test Doubles (stand-ins)*
- *Stub* - an object that provides predefined answers to method calls;
- *Mock* - an object on which you set expectations;
- *Fake* - an object with limited capabilities (for the purposes of testing), e.g. a fake web service.