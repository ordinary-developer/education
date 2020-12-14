#include "Super.hpp"
#include "Sub.hpp"


int main() {
    Sub mySub;
    mySub.someMethod();
    mySub.someOtherMethod();

    Super mySuper;
    // the next line will not compile
    // mySuper.someOtherMethod();
    
    Super* superPointer = new Sub(); 
    superPointer->someMethod();
    // the next line will not compile
    // superPointer->someOtherMethod();
   
    Super mySuper2;
    mySuper2.someMethod();
    Sub mySub2;
    mySub2.someMethod();

    Sub mySub3;
    Super& ref = mySub3;
    ref.someMethod();

    Sub mySub4;
    Super& ref2 = mySub4;
    mySub4.someOtherMethod(); // This is fine
    // the next string will not compile
    // ref2.someOtherMethod();

    Sub mySub5;
    Super assignedObject = mySub5;
    assignedObject.someMethod(); // calls super's version of someMethod()
    
    return 0;
}
