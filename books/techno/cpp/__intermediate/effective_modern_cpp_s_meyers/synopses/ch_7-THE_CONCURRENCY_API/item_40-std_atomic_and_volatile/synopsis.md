Use std::atomic for concurrency, volatile for special memory
============================================================

Base material
-------------

Instantiations of the *std::atomic* template offer operations
that are guaranteed to be seen as atomic by other threads.

*Volatile* instantiations do not garantee an atomic behaviour.

The use of std::atomics imposes restrictions 
on how code can be reordered, and one such restriction
is that no code that, in the source code, precedes a write 
of a std::atomic variable may take place afterwards
(or appear to other cores to take place afterwards).
(but this is true only for the memory_sequential_consistency model,
for the weak (relaxed) model it is not true).

Declaring a variable as volatile doesn't impose 
the same code reordering restrictions.

These two issues - no guarantee of operation atomicity 
and insufficient restrictions on code reordering - 
explain why *volatile* is not useful for concurrent programming.
In a nutshell, *volatile* is useful for telling compilers
that they're dealing with memory that doesn't behave normally.


Summary
-------

- *std::atomic* is for data accessed from multiple threads 
  without using mutexes
  (it's a tool for writing concurrent software);
- *volatile* is for memory where reads and writes 
  should not be optimized away
  (it's a tool for working with special memory).
