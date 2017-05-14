Use the explicitly typed initializer idiom
==========================================

Base material
-------------

"Invisible" proxy types can cause "auto" to deduce
the "wrong" type for an initializing expresion
(for example: std::vector<bool>::reference).

The explicitly typed initializer idiom involves declaring
a variable with "auto", but casting the initialization expression
to the type you want "auto" to deduce.

You also can use the explicitly typed initializer idiom 
to emphasize that you are deliberately creating a variable
of a type that is different from that generated 
by the initializing expression.
