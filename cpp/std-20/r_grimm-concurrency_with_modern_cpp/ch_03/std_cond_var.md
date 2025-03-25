### Condition Variables

Troubles:
- lost wakeups:
  the sender sends its notification before the receiver gets to its wait state

- spurious wakeups
  the receiver may wake up, although no notification happend
  (e.g. a stolen wakeup - before the awoken thread gets the chance to run,
  another thread kicks in and runs)

Basic howtos:
- use the `wait` method with a predicate
  (to eliminate spurious wakeups)
- use a mutex to modify shared variables (even atomic)
  (for correct publishing the modification to the waiting thread)
- a sender: use `std::lock_guard`
  a receiver: use `std::unique_lock`
