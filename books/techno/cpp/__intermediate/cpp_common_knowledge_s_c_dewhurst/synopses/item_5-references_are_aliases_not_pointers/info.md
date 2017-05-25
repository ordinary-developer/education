References are aliases not pointers
====================================

common
------

A reference is another name for an existing object.

Differences between references and pointers:
- there are no null references;
- all references require initialization;
- reference always refers to the object 
  with which it is initialized.

A reference is bound to its initializer for its whole lifetime.

When a reference to const is initialized with a literal,
the reference is se to refer to a temporary location
that is initialized with the literal.
 
Odinarily, such temporaries are destroyed (that is, go out of scope
and have their destructors called) at the end of the expression
in which they're created;
however, when such a temporary is used to initialized a reference
to const, the temporary will exist as long as the reference that
refers to it.

