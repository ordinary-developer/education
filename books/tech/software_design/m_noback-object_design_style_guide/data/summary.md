*Private* should be your default scope (for vars).

If object A needs object B, B is a dependency of A.
For A to have access to B
- A can instantiate B itself;
- A can fetch a B instance from a known location (*service location*);
- A can get a B instance injected upon construction (*dependency injection*).

Use inheritance carefully. Prefer composition to inheritance.

*Test Doubles (Fakes, Stubs, Mocks)*
- *Stub* - an object that provides predefined answers to method calls;
- *Mock* - an object on which you set expectations;
- *Fake* - an object with limited capabilities (for the purposes of testing), e.g. a fake web service.
