COMMAMND (Action, Transaction)
==============================

Intent
------

Encapsulate a request as an object, thereby letting you parameterize
with different requests, queue or log requests, and support undoable
operations.


Applicability
-------------

Use the Command pattern when you want to
- parameterize objects by an action to perform;
- specify, queue, and execute requests at different times;
- support undo  
  the Command's "Execute" operation can store state for reversing its 
  effects in the command itself; the command interface must have an 
  added "Unexecute" operation that reverses the effects of a previous
  call to "Execute"; executed commands are stored in a history list;
  unlimited-level undo and redo is achieved by traversing this list
  backwards and forwards calling "Unexecute" and "Execute", 
  respectively;
- support logging changes so that they can be reapplied in case of 
  a system crash  
  by augmenting the "Command" interface with load and store
  operations, you can keep a persistent log of changes; recovering 
  from a crash involves reloading logged commands from disk and
  reexecuting them with the "Execute" operation;
- structure a system around high-level operations built on primitives
  operations  
  such a structure is common in information systems that support 
  transactions.


Structure
---------

``` 
                                       -------------
                               ------->| Command   |
                               |       -------------
 ----------   -----------      |       | Execute() |
 | Client |   | Invoker |<>-----       -------------
 ----------   -----------                    ^
  |      |                                  / \
  |      |    ------------                  ---
  |      ---->| Receiver |                   |
  |           -----------   receiver -------------------
  |           | Action() |<----------| ConcreteCommand |
  |           ------------           -------------------  -------------
  |                                  | Execute() o-----|--| receiver-> \
  |                                  -------------------  |   execute() |
  |--------------------------------->| state           |  ---------------
                                     -------------------
```


Participants
------------

- *Command*
  - declares an interface for executing an operation.
- *ConcreteCommand*
  - defines a binding between a *Receiver* object and an action;
  - implements "Execute" by invoking the corresponding operation(s)
    on *Receiver*.
- *Client*
  - creates a *ConcreteCommand* object and sets its receiver.
- *Invoker*
  - asks the command to carry out the request.
- *Receiver*  
  - knows how to perform the operations associated with carrying out
    a request; any class may server as a *Receiver*.


Collaborations
--------------

- the *Client* creates a *ConcreteCommand* object and specifies its
  *Receiver*;
- an *Invoker* object stores the *ConcreteCommand* object;
- the *Invoker* issues a request by calling "Execute" on the command;
  when commands are undoable, "ConcreteCommand" stores state for
  undoing the command prior to invoking "Execute";
- the "ConcreteCommand" object invokes operations on its *Receiver* 
  to carry out the request.


Consequences
------------

The *Command* pattern has the following consequences:
- *command* decouples the object that invokes the operation from one
  that knows how to perform it;
- *command*s are first-class object; they can be manipulated and
  extended like any other object;
- you can assemble *command*s into a composite *command*;
- it's easy to add new *command*s, because you don't have to exchange
  exiting classes.


Implementation
--------------

Consider the following issues when implementing the *Command* pattern:
- how intelligent should a command be?  
  (merely defines a binding between a receiver and the actions that
   carry out the request or implements everything itself without
   delegating to a receiver at all);
- supporting undo and redo  
  to support undo and redo capabilities a *ConcreteCommand* class might need
  to store additional state, that include
  - the *Receiver* object, which actually carries out operations 
    in response to the request,
  - the arguments to the operation performed on the *Receiver*,
  - any original values in the *Receiver* that can change as a result
    of handling the request; the *Receiver* must provider operations
    that let the *Command* return the *Receiver* to its prior state
  to support one-level of undo, an application needs to store only
  the command that was executed last, for multiple-level undo and redo,
  the application needs a history list of commands that have been
  executed; 
  traversing backward through the list and reverse-executing
  commands cancels their effect, traversing forward and executing 
  commands reexecutes them;
  an undoable command might have to be copied before it can be placed
  on the history list;
- avoiding error accumulation in the undo process;
- using C++ templates  
  for commands that aren't undoable and don't require arguments, 
  we can use C++ templates to avoid creating a *Command* subclass 
  for every kind of action and receiver.
