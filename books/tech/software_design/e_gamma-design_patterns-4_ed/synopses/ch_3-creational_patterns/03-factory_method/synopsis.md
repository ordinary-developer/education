FACTORY METHOD (Virtual Constructor)
====================================

Itent
-----

Define and interface for creating an object, but let subclasses 
decide which class to instantiate. Factory Method lets a class defer
instantiation to subclasses.


Applicability
-------------

Use the Factory Method pattern when
- a class can't anticipate the class of objects it must create;
- a class wan't its subclasses to specify the objects it creates;
- classes delegate responsibility to one of several 
  helper subclasses, and you want to localize the knowledge of which
  helper subclass is the delegate.


Structure
---------

```                       
                          --------------------
                          | Creatorr         |
                          --------------------  ------------------\
  -----------------       | FactoryMethod()  |  | product =        \
  |    Product    |       | AnOperation()   *|--|   FactoryMethod() |
  -----------------       --------------------  ---------------------
         ^                          ^
        / \                        / \
        ---                        ---
         |                          |
         |                          |
 -------------------      -------------------
 | ConcreteProduct | <--- | ConcreteCreator | 
 -------------------      -------------------   ------------------\
                          |FactoryMethod() *|---| return new       \
                          ------------------    |   ConcreteProduct |
                                                ---------------------  
```

Participants
------------

- Product
  * defines the interface of objects the factory method creates.
- ConcreteProduct 
  * implements the Product interface.
- Creator
  * declares the factory method, which returns an object  
    of type Product. Creator may also define a default implementation
    of the factory method that returns a default ConcreteProduct 
    object;
  * may call the factory method to create a Product object.
- ConcreteCreator
  * overrides the factory method to return an instance of a 
    ConcreteProduct.


Collaborations
--------------

- Creator relies on its subclasses to define the factory method so 
  that it returns an instance of the appropriate ConcreteProduct.


Consequences
------------

Factory methods eliminate the need to bind application-specific
classes into your code. The code only deals with the Product 
interface; therefore it can work with any user-defined
ConcreteProduct classes.


Implementation
--------------

- **Two major varieties**  
  The two main variations of the *Factory Method* pattern are
  - the case when the *Creator* class is an abstract class 
    and does not provide an implementation for the factory method
    it declares;
  - the case when the *Creator* is a concrete class and provides
    a default implementation for the factory method.
- **Parameterized factory methods**  
  Another variation on the pattern lets the factory method create 
  multiple kinds of products. The factory method takes a parameter
  that identifies the kind of object to create. All objects the 
  factory method creates will share the *Product* interface.  
  Overriding a parameterized factory method lets you easily and
  selectively extend or change the products 
  that a *Creator* produces. 
- **Language-specific variants and issues**  
  Factory methods in C++ are always virtual functions and are often
  pure virtual. Just be careful not to call factory methods in 
  the *Creator*'s constructor - the factory method in the 
  *ConcreteCreator* won't be available yet.  
  You can avoid this by being careful to access products solely 
  through accessor operations that create the product on demand.
  Instead of creating the concrete product in the constructor,
  the constructor merely initializes it to 0. The accessor returns
  the product. But first it checks to make sure the product exists,
  and if it doesn't, the accessor creates it. This technique is
  sometimes called lazy initialization.
- **Using templates to avoid subclassing**  
  To avoid subclassing in C++ is to provide a template subclass
  of *Creator* that's parameterized by the *Product* class.
- **Naming conventions**  
  It's good practice to use naming conventions that make it clear
  you're using factory methods. For example, you can declare the
  abstract operation that defines the factory method as 
  DoMakeClass(), where Class is the *Product* class.
    
