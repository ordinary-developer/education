Use decltype on auto&& parameters to std::forward them
======================================================

Generic lambdas
---------------

Generic lambdas are lambdas that use auto in their parameter
specifications.

When an lvalue is passed to a lambda, decltype(x) yields the customary
type to pass to std::forward; for rvalues, decltype(x) yields a type 
to pass to std::forward that's not conventional, but that nevertheless
yields the same outcome as the conventional type. So for both lvalues
and rvalues, passing decltype(x) to std::forward gives us the result
we want.

A perfect-forwarding lambda can be written like this:
```cpp
auto f =
    [](auto&& param)
    {
        return 
            func(normalize(std::forward<decltype(param)>(param)));
    };
```

A perferct-forwarding variadic lambda can be written like this:
```cpp
auto f =
    [](auto&&... params)
    {
        return 
          func(normalize(std::forward<decltype>(params)>(params)...));
    };
```


Resume
------

Use decltype on auto&& parameters to std::forward them.
