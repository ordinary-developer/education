# memory model

## memory locations
two aspects to the memory model:
- basic *structural* aspects
  (how thins are laid out in memory)
- concurrency aspects

all data in C++ is made up of *objects* - region of storage (with their type and lifetime)

an object is stored in one or more *memory locations* - 
an entity (or sub-entity) of a scalar type (`int` or `my_class*`) or a sequence of adjacent bit fields

remarks:
- every variable is an object (members of other objects are also objects)
- every object occupies *at least one* memory location
- variables of fundamental types (int, char, etc.) 
  occupy *excatly one* memory locaion
  (whaterver ther size, even if they're adjacent or part of an array)
- adjacent bit fields are part of the same memory location


## memory locations and concurrency
- two threads access *separate* memory locations - [ok]
- two threads access *the same* memory locations only for reading - [ok]
- one of two threads access *the same* memory location for writing - [race condition - sync is needed]

to avoid the race condition it is necessary to enforce an ordering between the accesses in the two threads

if more than two threads access the same memory location, each pair of access must have a defined ordering


## modification order (i.e. memory model)
a *modification order* is composed of all the writes to an object from all threads, starting with the object's initialization


## atomics
an *atomic operation* is an indivisible operation

atomic types (allmost all) have member functions:
- `is_lock_free()`
  `true` means that operations are done directory with atomic instructions (*lock-free*)
  `false` means that operations are done by using a lock internal to the compiler
- `is_always_lock_free()` (*static constexpr*)
  `true` - atomic type is lock-free for all supported hardware
  `false` - otherwise

the operations can have the next orderings:
*store* operations:
- *memory_order_relaxed* 
- *memory_order_release* 
- *memory_order_seq_cst*

*load* operations:
- *memory_order_relaxed*
- *memory_order_consume*
- *memory_order_acquire*
- *memory_order_seq_cst*

*read-modify-write* operations (all orderings):
- *memory_order_relaxed*
- *memory_order_consume*
- *memory_order_acquire*
- *memory_order_release*
- *memory_order_acq_rel*
- *memory_order_seq_cst*