# lock-based concurrent data structures
a *thread-safe* data structure means
that multiple threads can access the data structure concurrenlty,
either performing the same or distinct operations,
and each thread will see a self-consistent view of the data structure;
no data will be lost or corrupted, all invariants will be upheld,
and there'll be no problematic race conditions.

the base guideline:
*the smaller the protected region,
the fewer operatins are serialized*

the design of lock-based concurrent data structures is all about ensuring
that the right mutex is locked when accessing the data
and the lock is held for the minimum amount of time

thread-safety checklist:
- ensure that no thread can see a state where the invariants of the data structure
  have been broket by the actions of another thread
- ensure that there are no no race conditions inherent in the interface to the data structure
  by providing functions for complete operations rather than for operations steps
- ensure that the invariants are not broken in the presence of exceptions
- minimize the opportunities for deadlock by restricting the scope of locsk
  and avoiding nested locks where possible
