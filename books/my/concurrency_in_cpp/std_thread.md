# std::thread
if a thread is can't be started
then the `std::system_error`
with the error code `resource_unavailable_try_again` will be thrown

if an exception occurs that is not caught inside the thread,
the programm immediately aborts, calling `std::terminate()`;
to pass exceptions to a context outside the thread
`exception_ptr` must be used

if you don't call `join()` or `detach()`
before the lifetime of the thread object ends
or a move assignment to it happens,
the program aborts, calling `std::terminate()`

make sure that a detached thread does not access any objects
after their lifetime has ended