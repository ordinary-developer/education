### thread safety for `std::stop_source`
The calls of
- `stop_possible()`
- `stop_requested()`
- `request_stop()`

of `std::stop_source` are thread-safe.


### `std::stop_callback` and `std::stop_callback`
The `std::stop_callback` constructor registers the callback function for the `std::stop_token` and its destructor unregisters it.

the execution entity may be in one of the following states when the request to stop is signaled

- not started:
  - stopToken:
    `stopToken.stop_requested` return true when executed

  - stop callback:
    the callback is executed  when `stopToken|jthread.request_stop` is signaled

    the callback is executed in the thread registering (constructing) the callback
    during registering (constructing) per se

- executing:
  - stopToken:
    if `stopSource.request_stop()` happens before `stop_requested`, `stop_requested` return true
    otherwise false

  - stop callback:
    if the `stopSource.request_stop()` happens before registration (constructing) the callback
    the callback is executed in the tread registering (constructing) the callback

    otherwise
    the callback executed in the thread invoking `request_stop` (after callback registration)

- finished:
  the call `stopSource.request_stop` has no effect, the callbabck is not executed

_Note 1:_ The `std::jthread` can be created with a function with the only `std::stop_token` as a formal parameter (and it must not be passed as an actual parameter to thread creation)

_Note 2:_ If there are more than one callback there is no guarantee in which order they are executed.

