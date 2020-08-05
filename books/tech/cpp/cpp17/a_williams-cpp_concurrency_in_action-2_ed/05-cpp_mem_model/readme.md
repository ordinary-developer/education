# memory model

## memory locations
two aspects to the memory model:
- basic *structural* aspects
  (how things are laid out in memory)
- concurrency aspects

all data in C++ is made up of *objects* - regions of storage (with their type and lifetime)

an object is stored in one or more *memory locations* - 
entities (or sub-entities) of a scalar type (`int` or `my_class*`) or a sequence of adjacent bit fields

remarks:
- every variable is an object (members of other objects are also objects)
- every object occupies *at least one* memory location
- variables of fundamental types (int, char, etc.) 
  occupy *excatly one* memory locaion
  (whaterver their size, even if they're adjacent or part of an array)
- adjacent bit fields are part of the same memory location


## memory locations and concurrency
- two threads access *separate* memory locations - [ok]
- two threads access *the same* memory locations only for reading - [ok]
- one of two threads access *the same* memory location for writing - [race condition with UB - sync is needed]

*data race* - it is not specified which thread touches the memory location first (without UB is ok)

to avoid the race condition with UB it is necessary to enforce an ordering between the accesses in the two threads or make accesses atomic

if more than two threads access the same memory location, each pair of accesses must have a defined ordering

*data race with UB conditions*
- there is not enforced ordering between two accesses to a single memory location
  from separate threads
- one or both of thoses accesses is not atomic
- one or both is a write
    

## modification order (i.e. memory model)
a *modification order* is composed of all the writes to an object from all threads, starting with the object's initialization
(this order may vary between runs)


## atomics
an *atomic operation* is an indivisible operation

the standard atomic types ar note copyable or assignable
(they have no cpy constructors or copy assignment operations)
but they support assginment from and implicit convertion to
the corresponding built-in types

atomic types (allmost all) have member functions:
- `is_lock_free()`  
  'true' means that operations are done directory with atomic instructions (*lock-free*)  
  'false' means that operations are done by using a lock internal to the compiler
- `is_always_lock_free()` (*static constexpr*)  
  'true' - atomic type is lock-free for all supported hardware  
  'false' - otherwise
- `load()`, `store()`, `exchange()`, `compare_exchange_weak()`,
  `compare_exchange_strong()`
- `+=`, `-=`, `*=`, `|=` operators and so on (where appropriate)
- `fetch_add()`, `fetch_or()` and so on (where approapriate)
- `++' and `--` operators for atomic integrals and atomic pointers

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


## shared_ptr
accessing the same `std::shared_ptr<T>` object from multiple threads
without using the atomic access functions from all threads,
or using suitalbe external synchronization,
is a data race and UB


## memory orderings
there are three  models:
- *sequentially consistent* ordering
  (std::memory_order_seq_cst)
- *acquire-release* ordering
  (std::memory_order_consume, std::memory_order_acquire, std::memory_order_release, std::memory_order_acq_rel)
- *relaxed* ordering
  (std::memory_order_relaxed)


## sequentially consistent ordering
according to *sequentially consistent* ordering the behavior of a multithreaded program
is as if all operations were performed in some particular sequence by a single thread,
it means that operations can't be reordered (accross threads)

*sync issues*  
a sequentially consistent store synchronizes with a sequentially constistent load
of the same variable that reads the value stored

obeying "happen-before" relationships by atomic operations:
- within a thread - yes
- accross threads - yes


## realxed ordering
the only requirement is that all threads agree on the modification order of each individual variable

obeying "happen-before" relationships by atomic operations:
- within a thread - yes
- accross threads - NO (no "synchronizes-with" relationship)


## acquire-release ordering
under this ordering model
- atomic loads (`a.load()`) are *acquire* operations (std::memory_order_acquire)
- atomic stores (`a.store()`) are *release* operations (std::memory_order_release)
- atomic read-modify-write (`fetch_add()`, `exchange()`, etc.) are either *acquire*, *release* or both (std::memory_order_acq_rel)

*a release operation synchronizes-with an acquire operation that reads the value written*

in order to provide any synchronization, acquire and release operations must be paired up;

the value stored by a release operation must be seen by an acquire operation for either

*if A inter-thread happens before B* and *B inter-thread happens before C*,
then *A inter-thread happens before C*


## std::memory_order_consume
DON'T USE std::memory_order_consume
