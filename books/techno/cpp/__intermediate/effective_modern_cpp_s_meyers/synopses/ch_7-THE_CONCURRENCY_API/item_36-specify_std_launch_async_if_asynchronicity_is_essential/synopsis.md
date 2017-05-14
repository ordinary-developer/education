SPECIFY std::launch::async IF ASYNCHRONICITY IS ESSENTIAL
=========================================================

Base material
-------------

Assuming a function f is passed to "std::async" for execution,
- the "std::launch::async" launch policy means that f must be 
  run asynchronously (i.e., on a different thread);
- the "std::launch::deferred" launch policy means that f may run
  only when "get" or "wait" is called on the future returned
  by the "std::async";  
  when "get" or "wait" is invoked, f will execute synchronously
  (i.e., the caller will block until f finishes running);  
  if neither "get" nor "wait" is called, f will never run.


Summary
-------

- the default launch policy for "std::async" permits both 
  asynchronous and synchronous task execution;
- this flexibility leads to uncertainty when accessing 
  "thread_local"s, implies that the task may never execute,
  and affects program logic for timeout-based "wait" calls;
- specify std::launch::async if asynchronous task execution 
  is essential.

