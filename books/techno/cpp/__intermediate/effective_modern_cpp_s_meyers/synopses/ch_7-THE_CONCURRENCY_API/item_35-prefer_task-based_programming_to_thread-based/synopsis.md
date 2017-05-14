Prefer task-based programming to thread-based
=============================================

Base material
-------------

You can create a std::thread and run a function on it, thus employing
a *thread-based* approach. Or you can pass a function do std::async,
a strategy known as *task-based*.  

With the thread-based invocation, ther's no straightforward way
to get access to the function return value. With the task-based
approach, this way exists, because the future returned from std::async
offers the "get" function.

The "get" function is even more important if a function emits an
exception, because "get" provides access to that, too. With the
thread-based approach, if a function throws, the program dies
(via a call to std::terminate).

A more fundamental difference between thread-based and task-based
programming is the higher level of abstractin that task-based 
embodies.

Software threads are a limited resources. If you try to create more
than the system can provide, a "std::system_error" exception is 
thrown.

Even if you don't run out of threads, you can have trouble with
oversubscription.


Summary
-------

- the "std::thread" API offers no direct way to get return values
  from asynchronously run functions, and if those functions throw,
  the program is terminated;
- thread-based programming calls for manual management exhuastion,
  oversubscription, load balancing, and adaptation to new platforms;
- task-based programming via "std::async" with the default launch
  policy handles most of these issues for you.
