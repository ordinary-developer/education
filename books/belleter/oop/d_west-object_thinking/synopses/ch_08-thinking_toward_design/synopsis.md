Chapter 8 - Thinking toward design
==================================

Getting required knowledge
--------------------------
An object has four ways to gain access to the knowledge:
- It can store that knowledge in an instance variable
  (V - variable).
- It can ask (in the specification of a message singature)
  for that knowledge to be provided along 
  with the request for service (the message)
  (A - argument).
- It can obtain the knowledge from a third party - another object.
  (C - collaboration).
- It can "manufacture" the knowledge at the point when it is required.
  (M - method)

Use argument (A) and method (M).

A tipical West-approach
-----------------------
#### Widget
A widget can be represented by a "dataEntryWidget" object 
that has appearace, behavior (responsibilities) and a set of rule objects
(for validating its content).

#### Forms
A form object is an ordered collection os elements.
An element might be a string or a dataEntryWidget.
A form has an appearance, behavoir (respsonsiblities)
(add elements, delete elements, 
 collaborate with internal and external objects)
and a set of rule objects for validating itself.

