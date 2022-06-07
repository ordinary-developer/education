Deleted functions
=================

The standard idiom
------------------

The standard idiom for preventing copies of a class used to be 
declared the copy constructor and copy assignment operator private
and then not provide an implementation. 

This would cause a compile error if any code outside the class in
question tried to copy an instance and a link-time error (due to lack
of an implementation) if any of the class's member functions or 
friends tried to copy an instance


C++11 idiom
-----------

You can declare a function as *deleted* by addint *=delete* to the
function declaration.

You can apply the *=delete* specifier to any function, not just
copy constructors and assignment operators. This makes it clear that
the function isnt' available. 

It does a bit more that that too, though: a delete function 
participates in overload resolution in the normal way and only causes
a compilation error if it's selected. This can be used to reove
specifie overloads.
