Use std::unique_ptr for exclusive-ownership resource management
===============================================================

std::unique_ptr
---------------

std::unique_ptr embodies exclusive ownership semantics.

A non-null std::unique_ptr always owns what it points to.

Moving a std::unique_ptr trasfers ownership from the source pointer
to the destination pointer (the source pointer is set to null).

Copying a std::unique_ptr isn't allowed.

std::unique_ptr is thus a move-only type.

Upon destruction, a non-null std::unique_ptr destroys its resource.

By default, resource destruction is accomplished by applying 
"delete" to the raw pointer inside the std::unique_ptr.
  

destruction of std::unique_ptr
------------------------------

The std::unique_ptr owning the managed resource would eventually
have its desctrutor called 
(except the next case: if an when an exception 
propagates out of a thread's primayr function (e.g., main,
for the program's initial thread) or if a "noexcept" specification
is vialated, local objects may not be destroyed, and if std::abort
or an exit function (i.e., std::_Exit, std::exit, or std::quic_exit)
is called, they definitely won't be.


Custom deleters for unique_ptr
------------------------------

When using the default deleter (i.e., "delete"), you can reasonably
assume that "std::unique_ptr" objects are the same size 
as raw pointers.

When custom deleters enter the picture, this may no be the case;
deleters that are function pointers generally cause the size of a
std::unique_ptr to grow from one word to two
for deleters that are function objects, the change in size depends
on how much state is stored in the function object.

Stateless function objects (e.g., from lambda expressions with no
captures) incur no size penalty, and this means that when a custom
deleter can be implemented as either a function or a captureless
lambda expression, the lambda is preferable.


std::unique_ptr for arrays
--------------------------

std::unique_ptr comes in two forms:
- one for individual objects (std::unique_ptr<T>);
- one for arrays (std::unique_ptr<T[]>).

You can use std::unique_ptr<T[]> when you're using a C-like API
that returns a raw pointer to heap array that you assume 
ownership of.


Convert std::unique_ptr to std::shared_ptr
------------------------------------------

std::unique_ptr can be easily and efficiently converted to a
std::shared_ptr.


Summary
-------

- std::unique_ptr is a small, fast, move-only smart pointer for
  managing resources with exclusive-ownership semantics;
- by default, resource destruction takes place via "delete",
  but custom deleters can be specified;
  stateful deleters and function pointers as deleters increase
  the size of std::unique_ptr objects;
- converting a std::unique_ptr to a std::shared_ptr is easy.
