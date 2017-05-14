Prefer lambdas to std::bind
===========================

lambdas versus std::bind
------------------------

in the next code
```cpp
auto setSoundB = std::bind(setAlarm, 
                           steady_clock::now() + 1h, 
                           _1,
                           30s);
```

The alarm will be set to go off an hour after the call to std::bind,
not an hour after the call to setAlarm.

The correct code may be written so
```cpp
auto setSoundB = std::bind(setAlarm,
                           std::bind(std::plus<>(), 
                                     steady_clock::now(), 
                                     1h),
                           _1,
                           30s);    
``


Compared to lambdas, then, code using std::bind is less readable, 
less expressive, and possibly less efficient. In C++14, there are no
resonable use cases for std::bind.

In C++14, however, std::bind can be justified in two constrained 
situations:
- *move capture*  
  c++11 lambdas don't offer move capture, but it can be emulated
  through a combination of a lambda and std::bind;
- *polymorphic function objects*  
  because the function call operator on a bind object uses perfect
  forwarding, it can accept arguments of any type; this can be useful
  when you want to bind an object with a templatized function call
  operator.


Summary
-------

- lambdas are more readable, more expressive, and may be more 
  efficient than using std::bind;
- in C++11 only, std::bind may be usefull for implementing move 
  capture or for binding objects with templatized function
  call operators.
