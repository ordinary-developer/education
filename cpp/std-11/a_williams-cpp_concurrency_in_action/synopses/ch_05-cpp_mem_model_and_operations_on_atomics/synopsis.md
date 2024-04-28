C++ MEMORY MODEL AND OPERATIONS ON ATOMIC TYPES
===============================================

Object and memory locations
---------------------------

The C++ Standard defines an object as a "region of storage",
although it goes on to assign properties to these objects, 
such as their type and lifetime.

Some of these objects are simple values of a fundamental type
such as int or float, 
whereas others are instances of user-defined classes.
Some objects (such as arrays, instances of derived classes,
and instances of classes with non-static data members)
have subobjects, but others don't.

An object is stored in one or more memory locations.
Each such memory locations is either an object (or subobject) 
of a scalar type such as unsigned short or my_class* 
or a sequence of adjacent bif fields.
Though adajcent bitfields are distinct objects, 
they are still counted as the same memory location.

There are four important things:
- every variable is an object, including those 
  that are members of other objects;
- every object occupies at least one memory location;
- variables of fundamental types such as int or char
  are exactly one memory location, whatever their size,
  even if they are adjacent or part of an array;
- adjacent bit fields are part of the same memory location.


Objects, memory locations, and concurrency
------------------------------------------

If two threads access *separate* memory locations, there's no problem.

If two threads access *the same* memory location, 
then you can have the next situations:
- if neither thread is updating the memory location, you're fine;
- if either thread is modifying the data,
  there is a potential for a race condition. 

In order to avoid the race condition, 
here has to be an enforced ordering 
between the accesses in the two threads.

If more than two threads access the same memory location, 
each pair of accesses must have a defined ordering.


Modification orders
-------------------

Every object in a C++ program has a defined modification order
composed of all the writes to that object
from all threads in the program, 
starting with the object's initialization.

In most cases this order will vary between runs, 
but in any execution of the program all threads in the system
must agree on the order.

If the object in question isn't one of the atomic types,
you're responsible for marking certain
that there is sufficient synchronization to ensure that
threads agree on the modification order of each variable.
If different threads see distinct sequences of values
for a single variable,
you have a data race and undefined behavior.

If you do use atomic operations, the compiler is responsible 
for ensuring that the necessary synchronization is in place.

Although all threads must agree on the modification orders
of each individual object in a program, 
they don't necessarily have to agree 
on the relative order of operations on separate objects.


Atomic operations and types in C++
----------------------------------

An *atomic operation* is an idivisible operation.

The standard atomic types can be found in the <atomic> header.

The std::atomic<> class template has the next operations:
- load();
- store();
- exchange();                |   assignment from and convertion to the
- compare_exchange_weak();   |-> user-defined type
- compare_exchange_strong(). |


Each of the operations on the atomic types has an optional 
memory-ordering argument that can be used to specify the required
memory-ordering semantics.

Operations are divided into three categories:
- *store* operations, which chan have the next types of ordering:
  - memory_order_relaxed;
  - memory_order_release;
  - memory_order_seq_cst;
- *load* operations, which can have the next types of ordering:
  - memory_order_relaxed;
  - memory_order_consume;
  - memory_order_acquire;
  - memory_order_seq_cst;
- *read-modify-write* operations, which can have the next types
  of ordering:
  - memory_order_relaxed;
  - memory_order_consume;
  - memory_order_acquire;
  - memory_order_release;
  - memory_order_acq_rel;
  - memory_order_seq_cst.
The default ordering for all operations is "memory_order_seq_cst".



Operations on std::atomic_flag
------------------------------

*std::atomic_flag* is the simplest standard atomic type, which 
represents a Boolean flag. Objects of this type can be in one of 
two states: set or clear.  
It is the only type guaranteed to be lock-free.

Objects of type std::atomic_flag must be initialized with
ATOMIC_FLAG_INIT. This initializes the flag to a clear state.

If the std::atomic_flag object has static storage duration, it will
always be initialized by the time of the first operation on the flag.

After your flag object initialization, you can
- destroy it  
  (calling desctructor);
- clear it (store operation)  
  (calling the "clear()" member function);
- set it and query the previous value (read-modify-write operation)   
  (calling the "test_and_set()" member function).

You can't copy-construct another std::atomic_flag object from the 
first, and you can't assign one std::atomic_flag to another.
All operations on a atomic type are defined as atomic, and 
assignment and copy-construction cannot be atomic because involve
two objects.


Operations on std::atomic<bool>
-------------------------------

std::atomic<bool> is still not copy-constructible or copy-assignable,
you can construct it from a nonatomic bool.

Assignment operators that atomic types support return values
(of the corresponding nonatomic type) rather than references.


Storing a new value (or not) depending on the current value
-----------------------------------------------------------

The compare/exchange operation (compare_exchange_weak/strong)
compares the value of the atomic variable 
with a suplied expected value and stores the supplied disired value
if they (atomic variable's value and a supplied expected value) 
are equal.
If the values aren't equal, 
he expected value is updated is updated with the actual value
of the atomic variable.
The return type of the compare/exchange function is a bool, 
which is true if the store was performed and false otherwise.

For compare_exchange_weak(), the store might be not successful 
even if the original value of the variable 
was equal to the expected value,
in which case the value of the variable is unchanged 
and the return value of compare_exchnage_weak is false. 
Because compare_exchange_weak() can fail spuriosly, 
it must typically be used in a loop:
```cpp
bool expected = false;
extern atomic<bool> b; // set somewhere else
while (!b.compare_exchange_weak(expected, true) && !expected);
```

compare_exchange_strong() is guaranteed to return false  
only if the actual value wasn't equal to the expected value.
this can eliminate the need for loops.


Operations on std::atomic<T*>: pointer arithmetic
-------------------------------------------------

The atomic form of a pointer to some type T is std::atomic<T*>.
It is neither copy-constructible nor copy-assignable, although it
can be both constructed and assigned from the suitable pointer values.

It has the next member functions:
- is_lock_free();
- load();
- store();
- exchange();
- compare_exchange_weak();
- compare_exchange_strong();
- fetch_add();     - |
- fetch_sub();       | 
- operator +=;       | pointer arithmetic
- operator -=;       | operations
- operator ++;       |
- operator --      - |

Operators "+=", "-=", "++" and "--" atomically change
the atomic variable's value and return a plain pointer (not a ref.)
that also points to the atomic variable's value.
Specifying the ordering semantics isn't possible 
for the operator forms. These forms therefore 
always have memory_order_seq_cst semantics.

fetch_and() and fetch_sub() do atomic addition and subtraction,
but they return the original value (before operation performing).
Because fetch_add() and fetch_sub() are read-modify-write operations,
they can have any of the memory-ordering tags 
and can participate in a release sequence.


The std::atomic<> primary class template
----------------------------------------

In order to use std::atomic<UDT> for some user-defined type UDT, 
- this must have a trivial copy-assignment operator
  (the type must not have any virtual functions or virtual base 
   classes and must use the compiler-generated copy-assignment
   operator);
- every base class and non-static data member of a 
  user-defined type must also have a trivial copy-assignment operator;
- the type must be bitwise equality comparable.


The synchronizes-with relationship
----------------------------------

The *synchronizes-with* relationship is something that you can get 
only between operations on atomic types 
(operations on a data structure might provide this relationship
 if the data structure contains atomic types and the operation
 on that data structure preform the appropriate atomic operations
 internally).

The basic idea is this: a suitably tagged atomic write operation *W*
on variable *x* synchronizes-with a suitably tagged atomic read 
operation on *x* that reads the value stored by either that write 
(*W*), or a subsequent atomic write operation on *x* by the same 
thread that performed the initial write *W*, or a sequence of atomic
read-modify-write operations on *x* (such as *fetch_add()* or
*compare_exchange_weak()*) by any thread, where value read by
the first thread in the sequence is the value written by *W*.


The happens-before relationship
-------------------------------

The happens-before relationship means: if one operation is 
sequenced before another, then it also happens-before it.


Memory ordering for atomic operations
-------------------------------------

There are six memory ordering options that can be applied to
operations on atomic types:
- memory_order_relaxed;
- memory_order_consume;
- memory_order_acquire;
- memory_order_release;
- memory_order_acq_rel;
- memory_order_seq_cst.

The default memory-ordering option for all operations on atomic types
is *memory_order_seq_cst*
(the most stringent of the available options).

Although there are siz ordering options, they represent three models:
- *sequentially consistent* ordering  
  (memory_order_seq_cst)
- *acquire-release* ordering  
  (memory_order_consume, memory_order_arcuire, memory_order_release,
   memory_order_acq_rel)
- *relaxed* ordering  
  (memory_order_relaxed)


Sequentially consistent ordering
--------------------------------

If all operations on instances of atomic types are sequentially 
consistent, teh behaviour of a multithread program is as if all these
operations were performed in some particular sequence by a single
thread.


Relaxed ordering
----------------

Operations on the same variable within a single thread still obey
happens-before relationships, but there's almost no requirement on
ordering relative to other threads.

The only requirement is that access to a single atomic variable 
from the same thread can't be reordered; once a given thread has 
seen a particular value of an atomic varable, a subsequent read by
that thread can't retrieve an earlier value of the variable.


Acquire-release ordering
------------------------

Acquire-release ordering still has no total order of operations,
but it does introduce some synchronization. 

Under this ordering model, atomic loads are *aqcuire* operations
(*memory_order_acquire*), atomic stores are *release* operations
(*memory_order_release*), and atomic read-modify-write operations
(such as *fetch_add()* or *exchange()*) are either *acquire*,
*release*, or both (*memory_order_acq_rel*).

Synchronization is pairwise, between the thread that does the release
and the thread that does the acquire.

*A release operation synchronizes-with an acquire operation 
that reads the value written*. This means that different threads
can still see different orderings, but these orderings are 
restricted.


Data dependency with acquire-release ordering and memory_order_consume
----------------------------------------------------------------------

There are tow new relations that deal with data dependencies:
- dependency-ordered-before;
- carries-a-dependency-to.


Release sequences and synchronizes-with
---------------------------------------

If the store is tagged with *memory_order_release*, 
*memory_order_acq_rel*, or *memory_order_seq_cst*, 
and the load is tagged with *memory_order_consume*,
*memory_order_acquire*, or *memory_order_seq_cst*, and each operation
in the chain loads the value written by the previous operation, then
the chain of operations constitutes a release sequence and the initial
store synchronizes-with (for *memory_order_acquire* or 
*memory_order_seq_cst*) or dependency-ordered-before
(for memory_order_consume) the final load.


Fences
------

Fences (memory barriers) are operations that enforce memory-ordering 
constraints without modifying any data and are typically combined 
with atomic operations that use the *memory_order_relaxed* ordering 
constraints.

If an acquire operation sees the result of a store that takes place
after a release fence, the fence synchronizes-with that acquire
operation; and if a load that takes place before an acquire fence
sees the result of a release operation, the release operation 
synchronizes-with the acquire fence.

For fences on both sides if a load that takes place before the 
acquire fence sees a value written by a store that takes place after
the release fence, the release fence synchronizes-with the aqcuire 
fence.
