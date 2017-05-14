Use init capture to move objects into closures
==============================================

Init captures (C++14)
---------------------    

C++11 doesn't support moving objects into closures, but C++14 suport
moving objects into closures.

The new capability is called *init capture*. Another name for 
init capture is *generalized lambda capture*.

Using an initi capture makes it possible for you to specify
- *the name of a data member* in the closure class generated
  from lambda;
- *an expression* initializing that data member.

```cpp
auto pw = std::make_unique<Widget>();
auto func = [pw = std::move(pw)]
            {
                return pw->doSomething();
            };
```


Emulating init captures in C++11
--------------------------------

If you want to stick with lambdas, move capture ca be emulated 
in C++ by two ways
- moving theobject to be captured into a fuction object produced
  by std::bind;
- giving the lambda a reference to the "captured" object.


Summary
-------

- use C++14's init capture to move objects into closures;
- in C++11, emulate init capture via hand-written classes 
  or std::bind.
