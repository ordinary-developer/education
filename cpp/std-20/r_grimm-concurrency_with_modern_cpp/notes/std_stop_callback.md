### thread safety for `std::stop_source`
The calls of
- `stop_possible()`
- `stop_requested()`
- `request_stop()`

of `std::stop_source` are thread-safe.


### `std::stop_callback`
The `std::stop_callback` constructor registers the callback function for the `std::stop_token` and its destructor unregisters it.

The callback function is invoked

- in the thread constructing the `std::stop_callback` (during registration)
  (if the request to stop happens before the registration of the `std::stop_callback`)

- in the thread invoking `request_stop`
  (if the request to stop happens ater the registration of the `std::stop_callback`)

- never
  (if the thread is executed before the stop request)

_Note 1:_ There is no execution in the thread after the stop request (and consequently after callback execution).

_Note 2:_ The `std::jthread` can be created with a function with the only `std::stop_token` as a formal parameter (and it must not be passed as an actual parameter to thread creation)

_Note 3:_ If there are more than one callback there is no guarantee in which order they are executed.


### a general mechanism to send signals
the execution entity must be in one of the following states when the request to stop is signaled

- not started:
  the call `stopToken.stop_requested` returns true when executed;

  the callback is executed in the thread registering the callback (construcing `std::stop_callback`)
  during registering (callback constructing) per se

- executing:
  `stopToken.stop_requested()` returns true if `stopSource.request_stop()` happen before it, otherwise false

  the callback is executed in the thread registering the callback (construcing `std::stop_callback`)
  during registering (callback constructing) per se
  if the `stopSource.request_stop()` happen before registration

  otherwise 
  the callback is executed in the thread invokin `request_stop` (after callback registration)

- finished:
  the call `stopSource.request_stop` has no effect, the callbabck is not executed



