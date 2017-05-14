Use shared_ptr for shared-ownership resource management
=======================================================

Base material
-------------

An object accessed via std::shared_ptr has its lifetime managed 
by those pointers through shared ownership.

When the last std::shared_ptr pointing to an object stops pointing
there (e.g., because the shared_ptr is destroyed or mad to point to
a different object), that shared_ptr destroys the object
it points to.

A std::shared_ptr has the resource's reference count, a value
associated with the resource that keeps track of how many
std::shared_ptrs point to it.
std::shared_ptr constructors increment this count (usually).
std::shared_ptr destructors decrement it.
and copy assignment operators do both;

If a std::shared_ptr sees a reference count of zero
after performing a decrement, no more std::shared_ptrs point to 
the resource, so the std::shared_ptr destroys it.

The existense of the reference count has performance implications:
- std::shared_ptrs are tiwce the size of a raw pointer
  (they internally contain a raw pointer to the resource as well
   as a raw pointer to the resource's reference count);
- memory for the reference count must be dynamically allocated
  (the reference count is stored as dynamically allocated data);
- increments and decrements of the reference count must be atomic.


Destruction mechanism
---------------------

std::shared_ptr uses delete as its default resource-destruction 
mechanism, but it also supports custom deleters.

For std::unique_ptr, the type of the deleter is part of the type 
of the smart pointer, for std::shared_ptr , it's not.

Specifying a custom deleter doesn't change the size of a
std::shared_ptr object.


Control block
-------------

There's a control block for each object managed by std::shared_ptrs.

The control block contains:
- a reference count;
- a copy of the custom deleter (if one has been specified);
- a copy of a custom allocator (if on has been specified);
- additional data (e.g. a secondary reference count).
 
Rules for control block creation:
- std::make_shared always creates a control block;
- a control block is created when a std::shared_ptr is constructed
  from a unique-ownership pointer 
  (i.e., a std::unique_ptr or std::auto_ptr);
- when a std::shared_ptr constructor is called with a raw pointer,
  it creates a control block
  (if you wanted to create a shared ptr from an object,
   that already has a control block, you'd presumably pass
   a std::shared_ptr or a std::weak_ptr;
   std::shared_ptr constructors taking std::shared_ptrs 
   or std::weak_ptrs as constructor arguments don't create 
   new control blocks, because they can rely on the smart pointers
   passed to them to point to any necessary control blocks).


Using std::shared_ptr with raw pointers
---------------------------------------

- try to avoid passing raw pointers to a std::shared_ptr constructor
  (the usual alternative is to use std::make_shared,
   but you can't use std::make_shared when you use a custom deleter);
- if you must pass a raw pointer to a std::shared_ptr constructor,
  pass the result of new directly instead of going through 
  a raw pointer variable;
- [my] create a std::shared_ptr from another a std::shared_ptr 
  (not a raw pointer).
 

std::enable_shared_from_this
----------------------------

If class instances can be stored in a container using shared_ptrs
maybe it is useful to use the "std::enable_shared_from_this" class
("The Curiously Recurring Template" implementation for this case).


Arrays
------

std::shared_ptrs can't work with arrays.
 
