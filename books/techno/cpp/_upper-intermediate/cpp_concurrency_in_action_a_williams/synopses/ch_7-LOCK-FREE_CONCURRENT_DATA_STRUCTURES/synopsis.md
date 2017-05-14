DESIGNING LOCK-FREE CONCURRENT DATA STRUCTURES
==============================================

Definitions
-----------

Algorithms and data structurs that use mutexes, conditions variables,
and futures to synchronize the data are called *blocking* data
structures and algorithms.

Data structures and algorithms that don't use blocking library
functions are said to be *nonblocking*. Not all such data structures
are lock-free, though.

For a data structure to qualify as *lock-free*, more than one thread
must be able to access the data structure concurrently.
They don't have to be able to do the same operations.
Also if one of threads accessing the data structure is suspended
by the scheduler midway through its operation, the other threads
must still be able to complete their operations without waiting
for the suspended thread.

A *wait-free* data structure is a lock-free data structure with
the additional property that every thread accessing the data 
structure can complete its operation within a bounded number of
steps, regardless of the behavior of other threads.

With a lock-free data structure, some thread make progress with
every step. 

With a wait-free data structure, every thread can make
forward progress, regardless of what the other threads are doing;
there's no need for waiting.
