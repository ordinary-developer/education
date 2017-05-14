void futures for one-shot event communication
=============================================

Base material
-------------

You can *detect* an event and *react* to it by using 
a cond-var mechanism, but it has some drawbacks
(spurious wakeups, possible reacting task haning etc.)


A future-based approach
-----------------------

The detecting task has a std::promise object
(i.e the writing end of the communications channel):
```cpp
std::promise<void> promise;
```
and the reacting task has a corresponding future.
When the detecting task sees that the event it's looking for
has occurred, it sets the std::promise
(i.e., writes into the communications channel):
```cpp
promise.set_value();
```
Meanwhile, the reacting task "waits" on its future:
```cpp
promise.get_future().wait();
```
That "wait" blocks the reacting task until the std::promise
has been set.

#### Drawbacks

std::promise may be set only once. 
The communication channel between a std::promise and a future
is a one-shot mechanism: it can't be used repeatedly.


Employing many reactive tasks
-----------------------------

You can use std::shared_futures instead of std::future
to have many reactive tasks, 



Summary
-------

- for simple event communications, condvar-based designs
  require a superfluous mutex, impose constraints
  on the relative progress of detecting and reacting tasks,
  and require reacting tasks to verify
  that the event has taken place;
- designs employing a flag avoid those problems,
  but are based on polling, not blocking;
- a condvar and flag can be used together, 
  but the resulting communication mechanism is somewhat stilted;
- using std::promises and futures dodges these issues, 
  but the approach uses heap memory for shared states, 
  and it's limited to one-shot communication.
