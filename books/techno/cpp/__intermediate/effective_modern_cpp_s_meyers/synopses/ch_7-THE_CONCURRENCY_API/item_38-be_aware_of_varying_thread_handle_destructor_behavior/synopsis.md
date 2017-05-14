Be aware of varying thread handle destructor behavior
=====================================================

Base material
-------------

Both std::thread objects and future objects can be thought of
as handles to system threads.

Destruction of a joinable std::thread terminates your program,
because the two obvious alternatives - an implicit join and
an implicit detach - were considered worse choices.

Yet the destructor for a future sometimes behaves 
as if it did an implicit join, 
sometimes as if it did an impilicit detach, and sometimes neither.
It never causes program termination.

Because when a callee transmits a result to a caller, 
neither objects associated with the callee
no objects associated with the caller 
are suitable places to store the calle's result, 
it stored in a location outside both.
This location is known as the shared state.

The behavior of a future's destructor is determined 
by the shared state associated with the future.

- The destructor for the last future referring to a shared state
  for a non-deferred task launched via std::async blocks
  until the task completes
  (In essence, the destructor for such a future does an implicit join
   on the thread on which the asynchronously executing task 
   is running).
- The destructor for all other futures simply destroys 
  the future object.
  (For asynchronously running tasks, this is akin 
   to an implicit detach on the underlying thread. 
   For deferred tasks for which this is the final future,
   it means that the deferred task will never run).


What we're really dealing with is a simple "normal" behavior.
The normal behavior is that a future's destructor destroys
the future object.

The exception to this normal behavior arises only for a future
for which all of the following apply:
- it refers to a shared state that was created 
  due to a call to std::async;
- the task's launch policy is std::launch::async;
- the future is the last future referring to the shared state.
  (for std::futures, this will always be the case.
   For std::shared_futures, if other std::shared_futures refer
   to the same shared state as the future being destroyed,
   the future being destroyed follows the normal behavior
   (i.e. it simply destroys its data members)).

Only when all of these conditions are fulfilled
does a future's destructor exhibit special behavior,
and that behavior it to block
until the asynchronously running task completes.

It's common to hear this exception
to normal future destructor behavior summarized as
"Futures from std::async block in their destructors".
  

Summary
-------

- Future destructors normally just destroy the future's data members.
- The final future referring to a shared state 
  for a non-deferred task launched via std::async blocks
  until the task completes.

