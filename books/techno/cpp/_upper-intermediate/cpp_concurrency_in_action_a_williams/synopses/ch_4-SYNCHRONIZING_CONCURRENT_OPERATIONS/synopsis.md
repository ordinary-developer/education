SYNCHRONIZING CONCURRENT OPERATIONS
===================================

Common
------

The C++ Standard Library provides facilities to synchronize operations
between threads in the form of *condition variables* and *futures*


Waiting for an event or other condition
---------------------------------------

Conceptually, a condition variable is associated with some event or
other condition, and one or more threads can wait for that condition
to be satisfied. When some thread has determined that the condition
is satisfied, it can then notify one or more of the threads waiting
on the condition variable.

The Standard C++ Library provides two implementations of a condition
variable:
- std::condition_variable;
- std::condition_variable_any.
Both of these are declared in the <condition_variable> library header.
In both cases, they need to work with a mutex in order to provide
appropriate synchronization; the former is limited to working with
std::mutex, whereas the latter can work with anything that meets some
minimal criteria for being mutex-like.

Because std::condition_variable_any is more general, there is the 
potential for additional costs in terms of size, performance, or
operating system resources, so std::condition_variable should be 
preferred unless the additional flexibility is required.


Waiting for one-off events with futures
---------------------------------------

If a thread needs to wait for a specific one-off event, 
it somehow obtains a future representing this event. 
The thread can then periodically wait on the future for short periods
of time to see if the event has occurred. Once an event has happened
(and the future has become ready), the future can't be reset.

There are two sorts of futures in C++ Standard Library, implemented
as two class templates declared in the <future> library header:
- unique futures (std::future<>);
- shared futures (std::shared_future<>).

An instance of std::future is the one and only instance that
refers to its associated event, whereas multiple instances of
std::shared_future may refer to the same event. In the latter case,
all the instances will become ready at the same time, and they may 
all access any data associated with the event.


std::async
----------

You can use std::async to start an *asynchronous task* for which
you don't need the result rigth away. Rather than giving you back
a std::thread object to wait on, std::async returns a std::future
object, which will eventually hold the return value of the function.
When you need the value, you just call get() on the future, and 
the thread blocks until the future is ready and then returns the 
value.

std::async allows you to pass additional arguments to the function
by adding extra arguments to the call. 

If the first argument is a pointer to a member function, 
the second argument provides the object on which to apply the member
function (either directly, or via a pointer, or wrapped in std::ref),
and the remaining arguments are passed as arguments to the member
function.

Otherwise, the second and subsequent arguments are passed as arguments
to the function or callable object specified as the first argument.

Just as with std::thread, if the arguments are rvalues, the copies
are created by moving the originals. This allow the use of move-only
types as both the function object and the arguments.

By default, it's up to the implementation wheterh std::async starts 
a new thread, or whether the task runs synchronously when the future
is waited for.

You can specify which to use with an additional parameter to 
std::async before the function to call. This parameter is of the type
std::launch, and can either be
- std::launch::deferred  
  to indicate that the function call deferred until either wait()
  or get() is called on the future;
- std::launch::async  
  to indicate that the function must be run on its own thread;
- std::launch::deferred | std::launch::async
  to indicate that the implementation may choose
  (this option is default).


std::packaged_task
------------------

std::packaged_task<> ties a future to a function or callable object.
When std::packaged_task<> object is invoked, it calls the 
associated function or callable object and makes the future ready,
with the return value stored as the associated data.

The template parameter for thestd::packaged_task<> class template 
is a function signature. When you construct an instance of 
std::packaged_task, you must pass in a function or callable object
that can accept the specified parameters and that returns a type
convertible to the specified return type.

The retur type of the specified function signature identifies 
the type of the std::future<> returned from the get_future() 
member function, whereas the argument list of the function signature
is used to specify the signature of the packaged tasks' function
call operator.

The std::packaged_task object is thus a callable object, and it can
be wrapped in std::function object, passed to a std::thread as the
thread function, passed to another function that requires a callable
object, or even invoked directly.

When the std::packaged_task is invoked as a function object, 
the arguments supplied to the function call operator are passed on
to the contained function, and the return value is stored as the
asynchronous result in the std::future obtained from get_future().

You can thus wrap a task in a std::packaged_task and retrieve 
the future before passing the std::packaged_task object elsewhere
to be invoked in due course.


std::promise
------------

std::promise<T> provides a means of setting a value (of type T),
which can later be read through an associated std::future<T> object. 
A std::promise/std::future pair would provide one possible mechanism
for this facility; the waiting thread could block on the future,
while the tread providing the data could use the promise half of 
the pairing to set the associated value and make the futre ready.

You can obtain the std::future object associated with a given 
std::promise by calling the get_future() member function, just like
with std::package_task. When the value of the promise is set
(using the set_value() member function), the future becomes ready
and can be used to retrieve the stored value. If you destroy the
std::promise without setting a value, an exception is stored instead.


Exceptions for the future
-------------------------

If the function call invoked as part of std::async throws an 
exception, that exception is stored in the future in place of a 
stored value, the future becomes ready, and a call to get()
rethrows that stored exception.

The same happends if you wrap the function in a std::packaged_task -
when the task is invoked, if the wrapped function throws an exception,
that exception is stored in the future in place of the result,
ready to be thrown on a call to get().


Exceptions for promises
-----------------------

If you wish to store an exception rather than a value, you call
the "set_exception()" member function rather that "set_value()".
This would typically be used in a "catch" block for an exception
thrown as part of the algorithm, to populate the promise with
that exception


Waiting from multiple threads
-----------------------------

Calls to the member functions of a particular std::future instance
are not synchronized with each other. If you access a single
std::future object from multiple threads without additional 
synchronization, you have a data race and undefined behaviour. This
is by design: std::future models unique ownership of the asynchronous
result, and the one-shot nature of get() makes such concurrent access
pointless anyway - only one thread can retrieve the value, because
after the first call to get() there's no value left to retrieve.

Whereas std::future is only moveable, so ownership can be transferred
between instances, but only one instance refers to a particular
asynchronouse result at a time, std::shared_future instances are
copyable, so you can have multiple objects referring to the same
associated state.

Now, with std::shared_future, member functions on an individual object
are still unsynchronized, so to avoid data races accessing a single
object from multiple threads, you must protect access with a lock.
The preferred way to use it would be to take a copy of the object 
instead and have each thread access its own copy. Accesses to the
shared asynchronous state from multiple threads are safe if each 
thread accesses that state through its own std::shared_future object.

Instances of std::shared_future that reference some asynchronous state
are constructed from instances of std::future that reference that 
state. Since std::future objects don't share ownership of the
asynchronous sate with any other object, the owneship must be
transferred into the std::shared_future using std::move, leaving
the std::future in an empty state, as if it was default constructed.

Just as with other movable objects, the transfer of ownership is
implicit for rvalues.

std::future also has an additional feature to facilitate the use 
of std::shared_future with the new facility for automatically deducing
the type of a variable from its initializer. std::future has a share()
member function that creates a new std::shared_future and thransfers
ownership to it directly.


Waiting with a time limit
-------------------------

There are two sorts of timeouts you may wish to specify:
- a *duration-based* timeout  
  where you wait for a specific amount of time;
- an *absolute* timeout  
  where you wait until a specific point in time.

Most of the waiting functions provide variants that handle both forms
of timeouts. The variants that handle the duration-based timeouts
has a "_for" suffix, and those that handle the absolute timeouts 
have a "_until" suffix.

std::condition_variable has two overloads of the "wait_for()" member
function and two overloads of the "wait_until()" member function.

