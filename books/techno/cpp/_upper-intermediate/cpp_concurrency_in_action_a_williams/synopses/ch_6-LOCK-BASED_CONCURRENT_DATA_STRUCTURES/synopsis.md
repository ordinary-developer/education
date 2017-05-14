DESIGNING LOCK-BASED DATA STRUCTURES
====================================

Avoiding serialization
----------------------

The main idea: 
*the smaller the protected region, 
the fewer operations are serialized, and the greater the potential
for concurrency*.


Guidelines for designing data structures for concurrency
--------------------------------------------------------

Basics of how to make data structures thread-safe
- ensure that no thread can see a state where the invariants 
  of the data structure have been broken 
  by the actions of another thread;
- take care to avoid race conditions inherent in the interface 
  to the data structure by providing functions for complete operations
  rather than for operation steps;
- pay attention to how the data structure behaves in the presence
  of exceptions to ensure that the invariants are not broken;
- minimize the opportunities for deadlock 
  when using the data structure by restricting the scope of locks
  and avoiding nested locks where possible.

Some aspects about genuine concurrent access:
- can the scope of locks be restricted to allow some parts 
  of an operations to be performed outside the lock?
- can different parts of the data structure be protected 
  with different mutexes?
- do all operations require the same level of protection?
- can a simple change to the data structure improve the opportunities
  for concurrency without affecting the operational semantics?

The design of lock based concurrent data structures 
is all about ensuring that the right mutex is locked when accessing
data and ensuring that the lock is held for a minimum amout of time.
