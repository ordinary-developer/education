# Chapter 6 - Method, Process and models

## Semantic net
A semantic net consists of little more than nodes, arc, and text labels,
whith nodes representing things and arcs representing relationships
among those things.

## Object Cubes
Object cubes offer single, consistent, metaphor-preserving model objects.
Each of the six sides of the cube captures one critical aspect of the conceptualization of an object:

 - Side 1  (class, responsibilities, collaborations, the classic CRC card) contains
   * the name of the class to which the object being modeled is an instance,
   * a list of its responsibilities, and identification of any required collaborators.

 - Side 2  includes
   * a text description of the nature of the objects represented by the class.
   * Stereotypes (as defined by Wirfs-Brock) should be included on this side and any notations helpful for implementation.

 - Side 3  provides
   * a list of named contracts, the most common of which will be public, private, and protected.
   * Contracts are intended to reveal the intent of the class creator as to who should be able to send particular messages.
   * Each contract lists the messages (entire signature or just the selector) that should be included in that contract.

 - Side 4 identifies
   * the discrete pieces of information that an object will require
     if it is to fulfill its assigned responsibilities.
   * Each piece of information is given a descriptive label,
     a code indicating the source of the knowledge,
     and the name of the class that will embody or contain that knowledge.

 - Side 5  lists
   * all of the messages that an object agrees it will respond to.
   * Each message listed here will identify the message selector, or message name;
     indicate whether any arguments are required (and if so, the class of each argument);
     and identify the class of the object returned in response to the sending of the message.

 - Side 6  names and describes any events (changes in the state of an object) that other objects might want to be made aware of.

## Interaction Diagram
They model the communication among a group of objects engaged in a particular task.
Each scenario is bounded by a precondition (what must be true and what message must be sent to initiate the scenario) and a postcondition (what is to be returned when the scenario completes normally).

## Static Relation Diagram
Static relation diagrams depict relationships, relatively static in nature, among a group of classes.

Here are three common examples and their uses:

- Class hierarchy
  A simple diagram showing a single relationship: is-a-kind-of.

- Gestalt map
  provides an overview, or gestalt, of a system or an application while minimizing the amount of detail.
  Some very common types of relationships captured on a gestalt map include
  is-a-part-of, is-a-collection-of, is-composed-of, uses, coordinates, associates, and is-a-kind-of.
  (these relationships can be depicted abote the line(arc) linking two entities)
  Notice the absence of labels such as Manages or Controls, relationships that should not exist from an object thinking point of view

## Collective memory map
A specialized static relation that shows how knowledge is distributed among a community of objects
and that provides structural and definitional metadata relevant to that knowledge.
Specifically, it notes the distribution of objects—stored in instance variables of other objects
—whose primary purpose is to represent some piece of data (strings, numbers, dates, or the like).
Any constraints and relationships that exist among this subset of objects are
noted on this diagram.

## Object State Chart
Captures state-dependent information about objects

