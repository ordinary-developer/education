### Condition Variables

Troubles:
- lost wakeups
- spurious wakeups

Basic howtos:
- use the `wait` method with a predicate
  (to eliminate spurious wakeups)
- use a mutex to modify shared variables (even atomic)
  (for correct synchronization)
