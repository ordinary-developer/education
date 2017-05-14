Alternatives to overloading on universal references
===================================================


Abandon overloading
-------------------

You can avoid overloading on universal references by simply using
different names for the would-be overloads (this approach won't work
for constructors, because constructor names are fixed by the language).


Pass by const T&
----------------

You can replace pass-by-universal-reference with 
pass-by-lvalue- reference-to-const.
The drawback is that the design isn't as efficient as we'd prefer.


Pass by value
-------------

You can consider passing objects by value when you know you'll copy
them.


Use tag dispatch
----------------

If the motivation for the use of a universal reference is perfect
forwarding, we have to use a universal reference.

A universal reference parameter generally provides an exact match
for whatever's passed in, but if the universal reference is part
of a parameter list containing other parameters that are not
universal references, sufficiently poor matches on the non-universal
reference parameters can knock an overload with a universal
reference out of the running  
that's the basis behind the tag dispatch approach.

A keystone of tag dispatch is the existence of a single (unoverloaded)
function as the client API. This single function dispatches the work
to be done to the implementation functions.


Constraining templates that take universal references
-----------------------------------------------------

If we have perferct-forwading overloaded constructors
the real problem is not that the compiler-generated functions
(i.e., copy and move constructors) sometimes bypass the tag dispatch
desigen, it's that they don't alwasy pass it by.

By default, all templates are *enabled*, but a template using 
*std::enabled_if* is enabled only if he condition specified by
*std::enabled_if* is satisfied.

We can enable *our class*'s perfect forwarding constructor only if the
being passed isn't *our class*; if the type being passed is 
*our class*, we want to disable the perfect forwarding constructor
(i.e., cause compilers to ignore it), becuase that will cause the
class's copy or move constructor to handle the call, which is what
we want when an *our class* object is initialized with another 
*out class* instance.


Summary
-------

- alternatives to the combination of universal references and
  overloading include the use of distinct function names, passing
  parameters by lvalue-reference-to-const, passing parameters by value,
  and using tag dispatch;
- constraining templates via std::enable_if permits the use of
  universal references and overloading together, but it controls
  the conditions under which compilers may use the universal
  reference overloads;
- universal reference parameters often have efficiency advantages,
  but they typically have usability disadvantages.

