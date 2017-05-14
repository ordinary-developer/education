Understand auto type deduction
==============================

Base material
-------------

```cpp
template <typename T> 
void f(ParamType parameter); 

f(expr); 
```

When a variable is declared using "auto", 
"auto" plays the role of "T" in the template,
and the type specifier for the variable acts as "ParamType".

So the next snippets are "equal":
```cpp
auto x = 27;

// and
template <typename T>
void f_for_x(T param);

f_for_x(27);
```

And the next snippets are also "equal":
```cpp
const auto cx = x;

// and
template <typename T>
void f_for_cx(const T param);

f_for_cx(x);
```

And the next snippets are also "equal":
```cpp
const auto& rx = x;

// and
template <typename T>
void f_for_rx(const T& param);

f_for_rx(x);
```

And rules for template type deducing can be applied.


Auxiliary
---------

- "auto" type deduction assumes that a braced initializer 
  represents a "std::initializer_list",
  and template type deduction doesn't;
- "auto" in a function return type or a lambda parameter
  implies template type deduction, not "auto" type deduction.
