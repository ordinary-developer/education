### `std::stop_callback`
The `std::stop_callback` constructor registers the callback function for the `std::stop_token` (given by the associated `std::stop_source`).

The callback function is invoked

- in the thread constructing the `std::stop_callback`
  (if the request to stop happens before the registration of the `std::stop_callback`)

- in the thread invoking `request_stop`
  (otherwise)

- never
  (if the thread is executed before the stop request)

_Note 1:_ There is no execution in the thread after the stop request (and consequently after callback execution).

_Note 2:_ The `std::jthread` can be created with a function with a `std::stop_token` as a formal parameter (and it must not be passed as an actual parameter to the thread creation)
