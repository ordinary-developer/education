MAKE std::threads UNJOINABLE ON ALL PATHS
=========================================

Base material
-------------

Every std::thread object is in one of two states:
- joinable;
- unjoinable.

A joinable std::thread corresponds to an underlying asynchronous
thread of execution that is or could be running (and also blocked
or waiting to be scheduled).

An unjoinable std::thread is std::thread that's not joinable.
Unjoinable std::thread objects include:
- default-constructed std::threads;
- std::thread objects that have been moved from;
- std::threads that have been joined;
- std::threads that have been detached.

One reason a std::thread's joinability is important is that 
if the destructor for a joinable thread is invoked, 
execution of the program is terminated.


Summary
-------

- make std::threads unjoinable on all paths;
- join-on-destruction can lead to difficult-to-debug performance
  anomalies;
- detach-on-destruction can lead to difficult-to-debug undefined
  behavior;
- declare std::thread objects last in lists of data members.
