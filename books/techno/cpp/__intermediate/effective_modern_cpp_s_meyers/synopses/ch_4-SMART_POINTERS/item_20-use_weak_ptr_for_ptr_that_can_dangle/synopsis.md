Use weak_ptr for shared_ptr-like pointers that can dangle
=========================================================

Base material 
-------------

"weak_ptr" has to contend with a problem unknown to "shared_ptr"s:
the possibility that waht it point to has bee destroyed; a truly 
smart pointer would deal with this problem by tracking when it 
dangles, i.e., when the object it is supposed to int to no longer
exists.

"weak_ptr"s are typically created from "shared_ptr"s, they point to 
the same place as the "shared_ptr"s initializing them, but they 
dont' affect the reference count of the object they point to.

"weak_ptr"s can detect when they dangle only when an object's liftime
is managed by "shared_ptr"s.


Weak_ptr dereferencing
----------------------

"weak_ptr"s lack dereferencing operations.

You need an atomic operation that checks to see if the "weak_ptr"
has expired and, if not, gives you access to the object in ponts to;
this is done by creating a "shared_ptr" from the "weak_ptr".

The operation comes in two forms:
- weak_ptr::lock()
  returns a shared_ptr; the "shared_ptr" is null if "weak_ptr" has 
  expired;
- shared_ptr constructor takig a weak_ptr as an argument
  if weak_ptr has expired, an exception is thrown.

 
Efficiency perspective
----------------------

"weak_ptr" objects are the same size as "shared_ptr" objects, 
they make use of the same control blocks as "shared_ptr"s
("weak_ptr" don't participate in the shared ownership of objets
and hence don't affect the pointed-to-object's reference count;
there is actually a second reference count int the control block,
and it is this second reference count that "weak_ptr"s manipulate.


Summary
-------

- use "weak_ptr" for "shared_ptr"-liek pointers that can dangle;
- pontential use cases for "weak_ptr" include caching, 
  observer lists, and the prevention of "shared_ptr" cycles.
