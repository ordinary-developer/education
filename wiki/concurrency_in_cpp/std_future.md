## std::future - normal execution
- call `async` without explicitly passing a launch policy
  ```
  std::future<T> f{ std::async(func) };
  ```
  if async() (without explicitly passing a launch policy)
  couldn't start the passed functionality immediately,
  it will **defer** the call so that it gets called 
  only when the outcome of the passed functionality explicitly is requested
  with **get()** or **wait()**;
  but without such a request,
  the termination of the scope will even terminate the program
  without ever calling the background task


- call async with `std::launch::async`
  ```
  std::future<T> f{ std::async(std::launch::async, func) };
  ```
  if the asynchronous call is not possible here,
  the program will throw a `std::system_error` exception
  with the error code `resource_unavailable_try_again`,
  which is equivalent to the POSIX `errno EAGAIN`

  If you don't assign the result of `std::async(std::launch::async, ...) anywhere,
  the caller will block untill the passed functionality has finished
  (synchronous call)


- call `async` with `std::launch::deferred`
  ```
  std::future<T> f{ std::async(std::launch::deferred, func) };
  ```
  it is guaranteed that func() never gets called without `get()` or `wait()`

All `async()` calls can throw `std::bad_alloc`
if memory for the internal data structures could not be allocated
(according to cppreference)

You can call `get()` only once. After `get()`, the futures is in an invalid state.
Only the destructor the the `valid()` method can be called.

If the task has been started and no `get()` calls was, 
leaving the scope of the future object
will wait for the background task to end.



## std::future - exceptions
When `get()` is called
and the background operation was or gets terminated by an exception,
which was/is not handled inside the thread,
this exception gets propagated again.
