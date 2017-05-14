Prefer make_unique and make_shared to direct use of new
=======================================================

Use *make* functions
--------------------

- code duplication should be avoided  
  (the versions using *new* repeat the type being created, but 
   the *make* functions don't - code duplication should be avoided);
- exception safety  
  (to see more in the book);
- improved efficiency  
  (one memory allocation instead of two).


Where to use *new* keyword instead of *make*
--------------------------------------------

- none of the *make* functions permit the specification of 
  custom deleters, but *unique_ptr* and *shared_ptr* have
  constructors that do  
  (for both std::shared_ptr and std::unique_ptr);
- within the *make* functons, the perfect forwarding code 
  uses parentheses, not braces  
  (if you want to construct your pointed-to object using a braced
   initializer, you must use *new* directly)  
  (for both std::shared_ptr and std::unique_ptr);
- some classes define their own versions of *operator new* and
  *operator delete*
  (usually they can allocate only *sizeof(ClassName)* bytes,
   but shared_ptr must allocate *sizeof(ClassName) + control block*)  
  (for only std::shared_ptr);
- when use shared_ptr and weak_ptr it can be lag between
  object destruction and memory deallocation.


Summary
-------

- compared to direct use of *new*, *make* functions eliminate source
  code duplication, improve exception safety, and, for
  std::shared_ptr and std::allocated_shared, generate code
  that's smaller and faster;
- situations where use of *make* functions is inappropriate include
  the need to specify custom deleters and a desirte to pass braced
  initializers;
- for *std::shared_ptr*s, additional situations where *make* 
  functions may be ill-advised (1) classes with custom memory
  management and (2) systems with memory concerns, very large objects,
  and *std::weak_ptr*s that outlive the corresponding *shared_ptr*s.
