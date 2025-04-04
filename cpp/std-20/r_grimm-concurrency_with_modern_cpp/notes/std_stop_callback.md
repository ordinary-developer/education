### thread safety for `std::stop_source`
The calls of
- `stop_possible()`
- `stop_requested()`
- `request_stop()`

of `std::stop_source` are thread-safe.

### `std::stop_callback`
The `std::stop_callback` constructor registers the callback function for the `std::stop_token` (given by the associated `std::stop_source`) and its destructor unregisters it.

The callback function is invoked

- in the thread constructing the `std::stop_callback`
  (if the request to stop happens before the registration of the `std::stop_callback`)

- in the thread invoking `request_stop`
  (if the request to stop happens ater the registration of the `std::stop_callback`)

- never
  (if the thread is executed before the stop request)

_Note 1:_ There is no execution in the thread after the stop request (and consequently after callback execution).

_Note 2:_ The `std::jthread` can be created with a function with a `std::stop_token` as a formal parameter (and it must not be passed as an actual parameter to the thread creation)

_Note 3:_ It there are more than one callback there is no guarantee in which order they are executed.