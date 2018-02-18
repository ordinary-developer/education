ITEPRETER
=========

Intent
------

Given a language, define a representation for its grammar along 
with an interpreter that uses the representation to intepret
sentences in the language.


Applicability
-------------

Use the Interpreter pattern when there is a language to interpret,
and you can represent statements in the language as abstract thress.
The interpreter pattern works best when
- the grammar is simple  
  (for complex grammars you can use parser generators) 
- efficiency is not a critical concern  
  (for efficient interpreters you can use state machines)


Structure
---------
```
                      -----------
               ------>| Context |
               |      -----------
 ----------    |
 | Client | ----
 ----------
      |           ----------------------
      ----------->| AbstractExpression |<-----------------------
                  ----------------------                       |
                  | Interpret(Context) |                       |
                  ----------------------                       |
                             ^                                 |
                            / \                                |
                            ---                                |
                             |                                 |
            -----------------------------------                |
            |                                 |                |
 -------------------------        -------------------------    |
 | TerminationExpression |        | NonterminalExpression |<>---
 -------------------------        -------------------------
 | Interpret(Context)    |        | Interpret(Context)    |
 ------------------------         -------------------------
 ```


Participants
------------

- *AbstractExpression*
  - declares an abstract "Interpret" operation that is common to all
    nodes in the abstract syntax tree;
- *TerminalExpression*
  - implements an "Interpret" operation associated with terminal 
    symbols in the grammar;
  - an instance is required for every terminal symbol in a sentence;
- *NonterminalExpression*
  - on such class is required for every rule *R::R1 R2 ... Rn* in the
    grammar;
  - maintains instance variables of type *AbstractExression* for
    each of the symbols R1 through Rn;
  - implements an "Interpret" operation for nonterminal symbols in 
    the grammar ("Interpret" typically calls itself recursively 
    on the variables representing R1 through Rn);
- *Context*
  - contains information that is global to the interpreter;
- *Client*
  - builds (or is given) an abstract syntax tree representing a
    particular sentence in the language that the grammar defines
    (the abstract syntax tree is assembled from instances of the
     NonterminalExpression and TerminalExpression classe);
  - invokes the "Interpret" operation.


Collaborations
--------------

- The *client* builds (or is given) the sentence as an abstract syntax
  tree of *NonterminalExpression* and *TerminalExpression* instances. 
  Then the *client* initializes the *context* and invokes the
  "Interpret" operation.
- Each *NonterminalExpression* node defines "Interpret" in terms
  of "Interpret" on each subexpression. The "Interpret" operation
  of each *TerminalExpression* defines the base case in the recursion.
- The "Interpret" operations at each node use the *context* to store
  and access the state of the interpreter.


Consequences
------------

The Interpreter pattern has the following benefits and liabilities:
- It's easy to change and extends the grammar. 
- Implementing the grammar is easy, too.
- Complex grammars are hard to maintain.
  (When the grammar is very complex, other techniques such as 
   parser or compiler generators are more appropriate).
- Adding new ways to interpret expressions.
  (If you keep creating new ways of interpreting an expression,
   then consider using the "Visitor" pattern to avoid changing
   the grammar classes).


Implementation
--------------

- Creating the abstract syntax tree  
  (The Interpreter pattern doesn't explain how to create an
   abstract syntax tree (it doesn't address parsing). The abstract
   syntax tree can be created by a table-driven parser, by a 
   hand-crafted (usually recursive descent) parser, or directly 
   by the client).
- Defining the Interpret operation  
  (You don't have to define the "Interpret" operation in the 
   expression classes, may be it is better to use the Visitor 
   pattern to put "Interpret" in a separate "visitor" object).
- Sharing terminal symbols with the Flyweight pattern.
   

